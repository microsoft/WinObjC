// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Devices.Geolocation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.UI.Xaml.3.h"
#include "internal/Windows.UI.3.h"
#include "internal/Windows.Services.Maps.3.h"
#include "internal/Windows.UI.Xaml.Controls.Maps.3.h"
#include "Windows.UI.Xaml.Controls.h"
#include "internal/Windows.UI.Xaml.Controls.Maps.5.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::ICustomMapTileDataSource> : produce_base<D, Windows::UI::Xaml::Controls::Maps::ICustomMapTileDataSource>
{
    HRESULT __stdcall add_BitmapRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::CustomMapTileDataSource, Windows::UI::Xaml::Controls::Maps::MapTileBitmapRequestedEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().BitmapRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::CustomMapTileDataSource, Windows::UI::Xaml::Controls::Maps::MapTileBitmapRequestedEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_BitmapRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BitmapRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::ICustomMapTileDataSourceFactory> : produce_base<D, Windows::UI::Xaml::Controls::Maps::ICustomMapTileDataSourceFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::ICustomMapTileDataSource> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstance(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
            return S_OK;
        }
        catch (...)
        {
            *inner = nullptr;
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IHttpMapTileDataSource> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IHttpMapTileDataSource>
{
    HRESULT __stdcall get_UriFormatString(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UriFormatString());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_UriFormatString(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UriFormatString(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AdditionalRequestHeaders(impl::abi_arg_out<Windows::Foundation::Collections::IMap<hstring, hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AdditionalRequestHeaders());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AllowCaching(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllowCaching());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AllowCaching(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowCaching(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_UriRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::HttpMapTileDataSource, Windows::UI::Xaml::Controls::Maps::MapTileUriRequestedEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().UriRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::HttpMapTileDataSource, Windows::UI::Xaml::Controls::Maps::MapTileUriRequestedEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_UriRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UriRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IHttpMapTileDataSourceFactory> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IHttpMapTileDataSourceFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IHttpMapTileDataSource> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstance(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
            return S_OK;
        }
        catch (...)
        {
            *inner = nullptr;
            *instance = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateInstanceWithUriFormatString(impl::abi_arg_in<hstring> uriFormatString, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IHttpMapTileDataSource> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithUriFormatString(*reinterpret_cast<const hstring *>(&uriFormatString), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
            return S_OK;
        }
        catch (...)
        {
            *inner = nullptr;
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::ILocalMapTileDataSource> : produce_base<D, Windows::UI::Xaml::Controls::Maps::ILocalMapTileDataSource>
{
    HRESULT __stdcall get_UriFormatString(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UriFormatString());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_UriFormatString(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UriFormatString(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_UriRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::LocalMapTileDataSource, Windows::UI::Xaml::Controls::Maps::MapTileUriRequestedEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().UriRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::LocalMapTileDataSource, Windows::UI::Xaml::Controls::Maps::MapTileUriRequestedEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_UriRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UriRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::ILocalMapTileDataSourceFactory> : produce_base<D, Windows::UI::Xaml::Controls::Maps::ILocalMapTileDataSourceFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::ILocalMapTileDataSource> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstance(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
            return S_OK;
        }
        catch (...)
        {
            *inner = nullptr;
            *instance = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateInstanceWithUriFormatString(impl::abi_arg_in<hstring> uriFormatString, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::ILocalMapTileDataSource> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithUriFormatString(*reinterpret_cast<const hstring *>(&uriFormatString), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
            return S_OK;
        }
        catch (...)
        {
            *inner = nullptr;
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapActualCameraChangedEventArgs> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapActualCameraChangedEventArgs>
{
    HRESULT __stdcall get_Camera(impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapCamera> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Camera());
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
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapActualCameraChangedEventArgs2> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapActualCameraChangedEventArgs2>
{
    HRESULT __stdcall get_ChangeReason(Windows::UI::Xaml::Controls::Maps::MapCameraChangeReason * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ChangeReason());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapActualCameraChangingEventArgs> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapActualCameraChangingEventArgs>
{
    HRESULT __stdcall get_Camera(impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapCamera> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Camera());
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
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapActualCameraChangingEventArgs2> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapActualCameraChangingEventArgs2>
{
    HRESULT __stdcall get_ChangeReason(Windows::UI::Xaml::Controls::Maps::MapCameraChangeReason * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ChangeReason());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapCamera> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapCamera>
{
    HRESULT __stdcall get_Location(impl::abi_arg_out<Windows::Devices::Geolocation::IGeopoint> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Location());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Location(impl::abi_arg_in<Windows::Devices::Geolocation::IGeopoint> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Location(*reinterpret_cast<const Windows::Devices::Geolocation::Geopoint *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Heading(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Heading());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Heading(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Heading(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Pitch(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Pitch());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Pitch(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Pitch(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Roll(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Roll());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Roll(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Roll(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FieldOfView(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FieldOfView());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FieldOfView(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FieldOfView(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapCameraFactory> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapCameraFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithLocation(impl::abi_arg_in<Windows::Devices::Geolocation::IGeopoint> location, impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapCamera> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithLocation(*reinterpret_cast<const Windows::Devices::Geolocation::Geopoint *>(&location)));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateInstanceWithLocationAndHeading(impl::abi_arg_in<Windows::Devices::Geolocation::IGeopoint> location, double headingInDegrees, impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapCamera> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithLocationAndHeading(*reinterpret_cast<const Windows::Devices::Geolocation::Geopoint *>(&location), headingInDegrees));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateInstanceWithLocationHeadingAndPitch(impl::abi_arg_in<Windows::Devices::Geolocation::IGeopoint> location, double headingInDegrees, double pitchInDegrees, impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapCamera> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithLocationHeadingAndPitch(*reinterpret_cast<const Windows::Devices::Geolocation::Geopoint *>(&location), headingInDegrees, pitchInDegrees));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateInstanceWithLocationHeadingPitchRollAndFieldOfView(impl::abi_arg_in<Windows::Devices::Geolocation::IGeopoint> location, double headingInDegrees, double pitchInDegrees, double rollInDegrees, double fieldOfViewInDegrees, impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapCamera> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithLocationHeadingPitchRollAndFieldOfView(*reinterpret_cast<const Windows::Devices::Geolocation::Geopoint *>(&location), headingInDegrees, pitchInDegrees, rollInDegrees, fieldOfViewInDegrees));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapControl> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapControl>
{
    HRESULT __stdcall get_Center(impl::abi_arg_out<Windows::Devices::Geolocation::IGeopoint> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Center());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Center(impl::abi_arg_in<Windows::Devices::Geolocation::IGeopoint> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Center(*reinterpret_cast<const Windows::Devices::Geolocation::Geopoint *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Children(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::DependencyObject>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Children());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ColorScheme(Windows::UI::Xaml::Controls::Maps::MapColorScheme * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ColorScheme());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ColorScheme(Windows::UI::Xaml::Controls::Maps::MapColorScheme value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ColorScheme(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DesiredPitch(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DesiredPitch());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DesiredPitch(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DesiredPitch(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Heading(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Heading());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Heading(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Heading(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LandmarksVisible(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LandmarksVisible());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LandmarksVisible(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LandmarksVisible(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LoadingStatus(Windows::UI::Xaml::Controls::Maps::MapLoadingStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LoadingStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MapServiceToken(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MapServiceToken());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MapServiceToken(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MapServiceToken(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxZoomLevel(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxZoomLevel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinZoomLevel(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinZoomLevel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PedestrianFeaturesVisible(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PedestrianFeaturesVisible());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PedestrianFeaturesVisible(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PedestrianFeaturesVisible(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Pitch(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Pitch());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Style(Windows::UI::Xaml::Controls::Maps::MapStyle * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Style());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Style(Windows::UI::Xaml::Controls::Maps::MapStyle value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Style(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TrafficFlowVisible(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TrafficFlowVisible());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TrafficFlowVisible(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TrafficFlowVisible(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TransformOrigin(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TransformOrigin());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TransformOrigin(impl::abi_arg_in<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TransformOrigin(*reinterpret_cast<const Windows::Foundation::Point *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WatermarkMode(Windows::UI::Xaml::Controls::Maps::MapWatermarkMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WatermarkMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_WatermarkMode(Windows::UI::Xaml::Controls::Maps::MapWatermarkMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WatermarkMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ZoomLevel(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ZoomLevel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ZoomLevel(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ZoomLevel(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MapElements(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::Maps::MapElement>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MapElements());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Routes(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::Maps::MapRouteView>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Routes());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TileSources(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::Maps::MapTileSource>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TileSources());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_CenterChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().CenterChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CenterChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CenterChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_HeadingChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().HeadingChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_HeadingChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HeadingChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_LoadingStatusChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().LoadingStatusChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_LoadingStatusChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LoadingStatusChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_MapDoubleTapped(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapInputEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().MapDoubleTapped(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapInputEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_MapDoubleTapped(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MapDoubleTapped(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_MapHolding(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapInputEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().MapHolding(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapInputEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_MapHolding(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MapHolding(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_MapTapped(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapInputEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().MapTapped(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapInputEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_MapTapped(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MapTapped(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PitchChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().PitchChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PitchChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PitchChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_TransformOriginChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().TransformOriginChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_TransformOriginChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TransformOriginChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ZoomLevelChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ZoomLevelChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ZoomLevelChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ZoomLevelChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindMapElementsAtOffset(impl::abi_arg_in<Windows::Foundation::Point> offset, impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Controls::Maps::MapElement>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().FindMapElementsAtOffset(*reinterpret_cast<const Windows::Foundation::Point *>(&offset)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetLocationFromOffset(impl::abi_arg_in<Windows::Foundation::Point> offset, impl::abi_arg_out<Windows::Devices::Geolocation::IGeopoint> location) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GetLocationFromOffset(*reinterpret_cast<const Windows::Foundation::Point *>(&offset), *location);
            return S_OK;
        }
        catch (...)
        {
            *location = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetOffsetFromLocation(impl::abi_arg_in<Windows::Devices::Geolocation::IGeopoint> location, impl::abi_arg_out<Windows::Foundation::Point> offset) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GetOffsetFromLocation(*reinterpret_cast<const Windows::Devices::Geolocation::Geopoint *>(&location), *offset);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsLocationInView(impl::abi_arg_in<Windows::Devices::Geolocation::IGeopoint> location, bool * isInView) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsLocationInView(*reinterpret_cast<const Windows::Devices::Geolocation::Geopoint *>(&location), *isInView);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TrySetViewBoundsAsync(impl::abi_arg_in<Windows::Devices::Geolocation::IGeoboundingBox> bounds, impl::abi_arg_in<Windows::Foundation::IReference<Windows::UI::Xaml::Thickness>> margin, Windows::UI::Xaml::Controls::Maps::MapAnimationKind animation, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().TrySetViewBoundsAsync(*reinterpret_cast<const Windows::Devices::Geolocation::GeoboundingBox *>(&bounds), *reinterpret_cast<const Windows::Foundation::IReference<Windows::UI::Xaml::Thickness> *>(&margin), animation));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TrySetViewWithCenterAsync(impl::abi_arg_in<Windows::Devices::Geolocation::IGeopoint> center, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().TrySetViewAsync(*reinterpret_cast<const Windows::Devices::Geolocation::Geopoint *>(&center)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TrySetViewWithCenterAndZoomAsync(impl::abi_arg_in<Windows::Devices::Geolocation::IGeopoint> center, impl::abi_arg_in<Windows::Foundation::IReference<double>> zoomLevel, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().TrySetViewAsync(*reinterpret_cast<const Windows::Devices::Geolocation::Geopoint *>(&center), *reinterpret_cast<const Windows::Foundation::IReference<double> *>(&zoomLevel)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TrySetViewWithCenterZoomHeadingAndPitchAsync(impl::abi_arg_in<Windows::Devices::Geolocation::IGeopoint> center, impl::abi_arg_in<Windows::Foundation::IReference<double>> zoomLevel, impl::abi_arg_in<Windows::Foundation::IReference<double>> heading, impl::abi_arg_in<Windows::Foundation::IReference<double>> desiredPitch, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().TrySetViewAsync(*reinterpret_cast<const Windows::Devices::Geolocation::Geopoint *>(&center), *reinterpret_cast<const Windows::Foundation::IReference<double> *>(&zoomLevel), *reinterpret_cast<const Windows::Foundation::IReference<double> *>(&heading), *reinterpret_cast<const Windows::Foundation::IReference<double> *>(&desiredPitch)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TrySetViewWithCenterZoomHeadingPitchAndAnimationAsync(impl::abi_arg_in<Windows::Devices::Geolocation::IGeopoint> center, impl::abi_arg_in<Windows::Foundation::IReference<double>> zoomLevel, impl::abi_arg_in<Windows::Foundation::IReference<double>> heading, impl::abi_arg_in<Windows::Foundation::IReference<double>> desiredPitch, Windows::UI::Xaml::Controls::Maps::MapAnimationKind animation, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().TrySetViewAsync(*reinterpret_cast<const Windows::Devices::Geolocation::Geopoint *>(&center), *reinterpret_cast<const Windows::Foundation::IReference<double> *>(&zoomLevel), *reinterpret_cast<const Windows::Foundation::IReference<double> *>(&heading), *reinterpret_cast<const Windows::Foundation::IReference<double> *>(&desiredPitch), animation));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapControl2> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapControl2>
{
    HRESULT __stdcall get_BusinessLandmarksVisible(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BusinessLandmarksVisible());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BusinessLandmarksVisible(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BusinessLandmarksVisible(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TransitFeaturesVisible(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TransitFeaturesVisible());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TransitFeaturesVisible(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TransitFeaturesVisible(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PanInteractionMode(Windows::UI::Xaml::Controls::Maps::MapPanInteractionMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PanInteractionMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PanInteractionMode(Windows::UI::Xaml::Controls::Maps::MapPanInteractionMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PanInteractionMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RotateInteractionMode(Windows::UI::Xaml::Controls::Maps::MapInteractionMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RotateInteractionMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RotateInteractionMode(Windows::UI::Xaml::Controls::Maps::MapInteractionMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RotateInteractionMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TiltInteractionMode(Windows::UI::Xaml::Controls::Maps::MapInteractionMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TiltInteractionMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TiltInteractionMode(Windows::UI::Xaml::Controls::Maps::MapInteractionMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TiltInteractionMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ZoomInteractionMode(Windows::UI::Xaml::Controls::Maps::MapInteractionMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ZoomInteractionMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ZoomInteractionMode(Windows::UI::Xaml::Controls::Maps::MapInteractionMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ZoomInteractionMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Is3DSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Is3DSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsStreetsideSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsStreetsideSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Scene(impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapScene> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Scene());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Scene(impl::abi_arg_in<Windows::UI::Xaml::Controls::Maps::IMapScene> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Scene(*reinterpret_cast<const Windows::UI::Xaml::Controls::Maps::MapScene *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ActualCamera(impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapCamera> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ActualCamera());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TargetCamera(impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapCamera> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetCamera());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CustomExperience(impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapCustomExperience> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CustomExperience());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CustomExperience(impl::abi_arg_in<Windows::UI::Xaml::Controls::Maps::IMapCustomExperience> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CustomExperience(*reinterpret_cast<const Windows::UI::Xaml::Controls::Maps::MapCustomExperience *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_MapElementClick(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapElementClickEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().MapElementClick(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapElementClickEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_MapElementClick(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MapElementClick(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_MapElementPointerEntered(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapElementPointerEnteredEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().MapElementPointerEntered(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapElementPointerEnteredEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_MapElementPointerEntered(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MapElementPointerEntered(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_MapElementPointerExited(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapElementPointerExitedEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().MapElementPointerExited(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapElementPointerExitedEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_MapElementPointerExited(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MapElementPointerExited(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ActualCameraChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapActualCameraChangedEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ActualCameraChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapActualCameraChangedEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ActualCameraChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ActualCameraChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ActualCameraChanging(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapActualCameraChangingEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ActualCameraChanging(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapActualCameraChangingEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ActualCameraChanging(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ActualCameraChanging(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_TargetCameraChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapTargetCameraChangedEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().TargetCameraChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapTargetCameraChangedEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_TargetCameraChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TargetCameraChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_CustomExperienceChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapCustomExperienceChangedEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().CustomExperienceChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapCustomExperienceChangedEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CustomExperienceChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CustomExperienceChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartContinuousRotate(double rateInDegreesPerSecond) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartContinuousRotate(rateInDegreesPerSecond);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StopContinuousRotate() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StopContinuousRotate();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartContinuousTilt(double rateInDegreesPerSecond) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartContinuousTilt(rateInDegreesPerSecond);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StopContinuousTilt() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StopContinuousTilt();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartContinuousZoom(double rateOfChangePerSecond) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartContinuousZoom(rateOfChangePerSecond);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StopContinuousZoom() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StopContinuousZoom();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryRotateAsync(double degrees, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().TryRotateAsync(degrees));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryRotateToAsync(double angleInDegrees, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().TryRotateToAsync(angleInDegrees));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryTiltAsync(double degrees, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().TryTiltAsync(degrees));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryTiltToAsync(double angleInDegrees, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().TryTiltToAsync(angleInDegrees));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryZoomInAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().TryZoomInAsync());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryZoomOutAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().TryZoomOutAsync());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryZoomToAsync(double zoomLevel, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().TryZoomToAsync(zoomLevel));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TrySetSceneAsync(impl::abi_arg_in<Windows::UI::Xaml::Controls::Maps::IMapScene> scene, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().TrySetSceneAsync(*reinterpret_cast<const Windows::UI::Xaml::Controls::Maps::MapScene *>(&scene)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TrySetSceneWithAnimationAsync(impl::abi_arg_in<Windows::UI::Xaml::Controls::Maps::IMapScene> scene, Windows::UI::Xaml::Controls::Maps::MapAnimationKind animationKind, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().TrySetSceneAsync(*reinterpret_cast<const Windows::UI::Xaml::Controls::Maps::MapScene *>(&scene), animationKind));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapControl3> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapControl3>
{
    HRESULT __stdcall add_MapRightTapped(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapRightTappedEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().MapRightTapped(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapRightTappedEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_MapRightTapped(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MapRightTapped(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapControl4> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapControl4>
{
    HRESULT __stdcall get_BusinessLandmarksEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BusinessLandmarksEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BusinessLandmarksEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BusinessLandmarksEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TransitFeaturesEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TransitFeaturesEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TransitFeaturesEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TransitFeaturesEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetVisibleRegion(Windows::UI::Xaml::Controls::Maps::MapVisibleRegionKind region, impl::abi_arg_out<Windows::Devices::Geolocation::IGeopath> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetVisibleRegion(region));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkClickEventArgs> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkClickEventArgs>
{
    HRESULT __stdcall get_LocalLocations(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::LocalSearch::LocalLocation>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LocalLocations());
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
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkPointerEnteredEventArgs> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkPointerEnteredEventArgs>
{
    HRESULT __stdcall get_LocalLocations(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::LocalSearch::LocalLocation>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LocalLocations());
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
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkPointerExitedEventArgs> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkPointerExitedEventArgs>
{
    HRESULT __stdcall get_LocalLocations(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::LocalSearch::LocalLocation>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LocalLocations());
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
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkRightTappedEventArgs> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapControlBusinessLandmarkRightTappedEventArgs>
{
    HRESULT __stdcall get_LocalLocations(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::LocalSearch::LocalLocation>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LocalLocations());
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
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper>
{
    HRESULT __stdcall add_BusinessLandmarkClick(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkClickEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().BusinessLandmarkClick(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkClickEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_BusinessLandmarkClick(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BusinessLandmarkClick(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_TransitFeatureClick(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlTransitFeatureClickEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().TransitFeatureClick(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlTransitFeatureClickEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_TransitFeatureClick(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TransitFeatureClick(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_BusinessLandmarkRightTapped(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkRightTappedEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().BusinessLandmarkRightTapped(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkRightTappedEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_BusinessLandmarkRightTapped(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BusinessLandmarkRightTapped(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_TransitFeatureRightTapped(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlTransitFeatureRightTappedEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().TransitFeatureRightTapped(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlTransitFeatureRightTappedEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_TransitFeatureRightTapped(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TransitFeatureRightTapped(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper2> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper2>
{
    HRESULT __stdcall add_BusinessLandmarkPointerEntered(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkPointerEnteredEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().BusinessLandmarkPointerEntered(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkPointerEnteredEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_BusinessLandmarkPointerEntered(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BusinessLandmarkPointerEntered(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_TransitFeaturePointerEntered(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlTransitFeaturePointerEnteredEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().TransitFeaturePointerEntered(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlTransitFeaturePointerEnteredEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_TransitFeaturePointerEntered(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TransitFeaturePointerEntered(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_BusinessLandmarkPointerExited(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkPointerExitedEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().BusinessLandmarkPointerExited(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkPointerExitedEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_BusinessLandmarkPointerExited(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BusinessLandmarkPointerExited(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_TransitFeaturePointerExited(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlTransitFeaturePointerExitedEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().TransitFeaturePointerExited(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlTransitFeaturePointerExitedEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_TransitFeaturePointerExited(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TransitFeaturePointerExited(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapControlDataHelperFactory> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapControlDataHelperFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::UI::Xaml::Controls::Maps::IMapControl> map, impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstance(*reinterpret_cast<const Windows::UI::Xaml::Controls::Maps::MapControl *>(&map)));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapControlStatics> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapControlStatics>
{
    HRESULT __stdcall get_CenterProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CenterProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ChildrenProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ChildrenProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ColorSchemeProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ColorSchemeProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DesiredPitchProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DesiredPitchProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HeadingProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HeadingProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LandmarksVisibleProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LandmarksVisibleProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LoadingStatusProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LoadingStatusProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MapServiceTokenProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MapServiceTokenProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PedestrianFeaturesVisibleProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PedestrianFeaturesVisibleProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PitchProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PitchProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StyleProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StyleProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TrafficFlowVisibleProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TrafficFlowVisibleProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TransformOriginProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TransformOriginProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WatermarkModeProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WatermarkModeProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ZoomLevelProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ZoomLevelProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MapElementsProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MapElementsProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RoutesProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RoutesProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TileSourcesProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TileSourcesProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LocationProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LocationProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetLocation(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, impl::abi_arg_out<Windows::Devices::Geolocation::IGeopoint> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetLocation(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetLocation(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, impl::abi_arg_in<Windows::Devices::Geolocation::IGeopoint> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetLocation(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), *reinterpret_cast<const Windows::Devices::Geolocation::Geopoint *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NormalizedAnchorPointProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NormalizedAnchorPointProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetNormalizedAnchorPoint(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetNormalizedAnchorPoint(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetNormalizedAnchorPoint(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, impl::abi_arg_in<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetNormalizedAnchorPoint(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), *reinterpret_cast<const Windows::Foundation::Point *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapControlStatics2> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapControlStatics2>
{
    HRESULT __stdcall get_BusinessLandmarksVisibleProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BusinessLandmarksVisibleProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TransitFeaturesVisibleProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TransitFeaturesVisibleProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PanInteractionModeProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PanInteractionModeProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RotateInteractionModeProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RotateInteractionModeProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TiltInteractionModeProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TiltInteractionModeProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ZoomInteractionModeProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ZoomInteractionModeProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Is3DSupportedProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Is3DSupportedProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsStreetsideSupportedProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsStreetsideSupportedProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SceneProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SceneProperty());
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
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapControlStatics4> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapControlStatics4>
{
    HRESULT __stdcall get_BusinessLandmarksEnabledProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BusinessLandmarksEnabledProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TransitFeaturesEnabledProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TransitFeaturesEnabledProperty());
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
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeatureClickEventArgs> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeatureClickEventArgs>
{
    HRESULT __stdcall get_DisplayName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Location(impl::abi_arg_out<Windows::Devices::Geolocation::IGeopoint> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Location());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TransitProperties(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TransitProperties());
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
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeaturePointerEnteredEventArgs> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeaturePointerEnteredEventArgs>
{
    HRESULT __stdcall get_DisplayName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Location(impl::abi_arg_out<Windows::Devices::Geolocation::IGeopoint> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Location());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TransitProperties(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TransitProperties());
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
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeaturePointerExitedEventArgs> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeaturePointerExitedEventArgs>
{
    HRESULT __stdcall get_DisplayName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Location(impl::abi_arg_out<Windows::Devices::Geolocation::IGeopoint> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Location());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TransitProperties(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TransitProperties());
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
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeatureRightTappedEventArgs> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapControlTransitFeatureRightTappedEventArgs>
{
    HRESULT __stdcall get_DisplayName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Location(impl::abi_arg_out<Windows::Devices::Geolocation::IGeopoint> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Location());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TransitProperties(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TransitProperties());
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
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapCustomExperience> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapCustomExperience>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapCustomExperienceChangedEventArgs> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapCustomExperienceChangedEventArgs>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapCustomExperienceFactory> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapCustomExperienceFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapCustomExperience> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstance(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
            return S_OK;
        }
        catch (...)
        {
            *inner = nullptr;
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapElement> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapElement>
{
    HRESULT __stdcall get_ZIndex(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ZIndex());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ZIndex(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ZIndex(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Visible(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Visible());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Visible(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Visible(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapElement2> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapElement2>
{
    HRESULT __stdcall get_MapTabIndex(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MapTabIndex());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MapTabIndex(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MapTabIndex(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapElementClickEventArgs> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapElementClickEventArgs>
{
    HRESULT __stdcall get_Position(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Position());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Location(impl::abi_arg_out<Windows::Devices::Geolocation::IGeopoint> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Location());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MapElements(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::Maps::MapElement>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MapElements());
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
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapElementFactory> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapElementFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapElement> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstance(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
            return S_OK;
        }
        catch (...)
        {
            *inner = nullptr;
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapElementPointerEnteredEventArgs> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapElementPointerEnteredEventArgs>
{
    HRESULT __stdcall get_Position(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Position());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Location(impl::abi_arg_out<Windows::Devices::Geolocation::IGeopoint> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Location());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MapElement(impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapElement> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MapElement());
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
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapElementPointerExitedEventArgs> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapElementPointerExitedEventArgs>
{
    HRESULT __stdcall get_Position(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Position());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Location(impl::abi_arg_out<Windows::Devices::Geolocation::IGeopoint> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Location());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MapElement(impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapElement> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MapElement());
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
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapElementStatics> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapElementStatics>
{
    HRESULT __stdcall get_ZIndexProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ZIndexProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VisibleProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VisibleProperty());
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
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapElementStatics2> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapElementStatics2>
{
    HRESULT __stdcall get_MapTabIndexProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MapTabIndexProperty());
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
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapIcon> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapIcon>
{
    HRESULT __stdcall get_Location(impl::abi_arg_out<Windows::Devices::Geolocation::IGeopoint> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Location());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Location(impl::abi_arg_in<Windows::Devices::Geolocation::IGeopoint> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Location(*reinterpret_cast<const Windows::Devices::Geolocation::Geopoint *>(&value));
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

    HRESULT __stdcall get_NormalizedAnchorPoint(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NormalizedAnchorPoint());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_NormalizedAnchorPoint(impl::abi_arg_in<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NormalizedAnchorPoint(*reinterpret_cast<const Windows::Foundation::Point *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Image(impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Image());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Image(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Image(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapIcon2> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapIcon2>
{
    HRESULT __stdcall get_CollisionBehaviorDesired(Windows::UI::Xaml::Controls::Maps::MapElementCollisionBehavior * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CollisionBehaviorDesired());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CollisionBehaviorDesired(Windows::UI::Xaml::Controls::Maps::MapElementCollisionBehavior value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CollisionBehaviorDesired(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapIconStatics> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapIconStatics>
{
    HRESULT __stdcall get_LocationProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LocationProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TitleProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TitleProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NormalizedAnchorPointProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NormalizedAnchorPointProperty());
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
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapIconStatics2> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapIconStatics2>
{
    HRESULT __stdcall get_CollisionBehaviorDesiredProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CollisionBehaviorDesiredProperty());
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
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapInputEventArgs> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapInputEventArgs>
{
    HRESULT __stdcall get_Position(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Position());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Location(impl::abi_arg_out<Windows::Devices::Geolocation::IGeopoint> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Location());
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
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapItemsControl> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapItemsControl>
{
    HRESULT __stdcall get_ItemsSource(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ItemsSource());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ItemsSource(impl::abi_arg_in<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ItemsSource(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Items(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::DependencyObject>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Items());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ItemTemplate(impl::abi_arg_out<Windows::UI::Xaml::IDataTemplate> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ItemTemplate());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ItemTemplate(impl::abi_arg_in<Windows::UI::Xaml::IDataTemplate> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ItemTemplate(*reinterpret_cast<const Windows::UI::Xaml::DataTemplate *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapItemsControlStatics> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapItemsControlStatics>
{
    HRESULT __stdcall get_ItemsSourceProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ItemsSourceProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ItemsProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ItemsProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ItemTemplateProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ItemTemplateProperty());
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
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapPolygon> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapPolygon>
{
    HRESULT __stdcall get_Path(impl::abi_arg_out<Windows::Devices::Geolocation::IGeopath> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Path());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Path(impl::abi_arg_in<Windows::Devices::Geolocation::IGeopath> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Path(*reinterpret_cast<const Windows::Devices::Geolocation::Geopath *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StrokeColor(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StrokeColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StrokeColor(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StrokeColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StrokeThickness(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StrokeThickness());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StrokeThickness(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StrokeThickness(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StrokeDashed(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StrokeDashed());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StrokeDashed(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StrokeDashed(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FillColor(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FillColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FillColor(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FillColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapPolygon2> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapPolygon2>
{
    HRESULT __stdcall get_Paths(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Devices::Geolocation::Geopath>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Paths());
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
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapPolygonStatics> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapPolygonStatics>
{
    HRESULT __stdcall get_PathProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PathProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StrokeThicknessProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StrokeThicknessProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StrokeDashedProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StrokeDashedProperty());
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
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapPolyline> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapPolyline>
{
    HRESULT __stdcall get_Path(impl::abi_arg_out<Windows::Devices::Geolocation::IGeopath> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Path());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Path(impl::abi_arg_in<Windows::Devices::Geolocation::IGeopath> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Path(*reinterpret_cast<const Windows::Devices::Geolocation::Geopath *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StrokeColor(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StrokeColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StrokeColor(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StrokeColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StrokeThickness(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StrokeThickness());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StrokeThickness(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StrokeThickness(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StrokeDashed(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StrokeDashed());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StrokeDashed(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StrokeDashed(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapPolylineStatics> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapPolylineStatics>
{
    HRESULT __stdcall get_PathProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PathProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StrokeDashedProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StrokeDashedProperty());
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
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapRightTappedEventArgs> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapRightTappedEventArgs>
{
    HRESULT __stdcall get_Position(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Position());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Location(impl::abi_arg_out<Windows::Devices::Geolocation::IGeopoint> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Location());
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
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapRouteView> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapRouteView>
{
    HRESULT __stdcall get_RouteColor(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RouteColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RouteColor(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RouteColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OutlineColor(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OutlineColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OutlineColor(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OutlineColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Route(impl::abi_arg_out<Windows::Services::Maps::IMapRoute> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Route());
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
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapRouteViewFactory> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapRouteViewFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithMapRoute(impl::abi_arg_in<Windows::Services::Maps::IMapRoute> route, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapRouteView> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithMapRoute(*reinterpret_cast<const Windows::Services::Maps::MapRoute *>(&route), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
            return S_OK;
        }
        catch (...)
        {
            *inner = nullptr;
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapScene> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapScene>
{
    HRESULT __stdcall get_TargetCamera(impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapCamera> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetCamera());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_TargetCameraChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapScene, Windows::UI::Xaml::Controls::Maps::MapTargetCameraChangedEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().TargetCameraChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapScene, Windows::UI::Xaml::Controls::Maps::MapTargetCameraChangedEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_TargetCameraChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TargetCameraChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapSceneStatics> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapSceneStatics>
{
    HRESULT __stdcall abi_CreateFromBoundingBox(impl::abi_arg_in<Windows::Devices::Geolocation::IGeoboundingBox> bounds, impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapScene> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().CreateFromBoundingBox(*reinterpret_cast<const Windows::Devices::Geolocation::GeoboundingBox *>(&bounds)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromBoundingBoxWithHeadingAndPitch(impl::abi_arg_in<Windows::Devices::Geolocation::IGeoboundingBox> bounds, double headingInDegrees, double pitchInDegrees, impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapScene> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().CreateFromBoundingBox(*reinterpret_cast<const Windows::Devices::Geolocation::GeoboundingBox *>(&bounds), headingInDegrees, pitchInDegrees));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromCamera(impl::abi_arg_in<Windows::UI::Xaml::Controls::Maps::IMapCamera> camera, impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapScene> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().CreateFromCamera(*reinterpret_cast<const Windows::UI::Xaml::Controls::Maps::MapCamera *>(&camera)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromLocation(impl::abi_arg_in<Windows::Devices::Geolocation::IGeopoint> location, impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapScene> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().CreateFromLocation(*reinterpret_cast<const Windows::Devices::Geolocation::Geopoint *>(&location)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromLocationWithHeadingAndPitch(impl::abi_arg_in<Windows::Devices::Geolocation::IGeopoint> location, double headingInDegrees, double pitchInDegrees, impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapScene> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().CreateFromLocation(*reinterpret_cast<const Windows::Devices::Geolocation::Geopoint *>(&location), headingInDegrees, pitchInDegrees));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromLocationAndRadius(impl::abi_arg_in<Windows::Devices::Geolocation::IGeopoint> location, double radiusInMeters, impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapScene> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().CreateFromLocationAndRadius(*reinterpret_cast<const Windows::Devices::Geolocation::Geopoint *>(&location), radiusInMeters));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromLocationAndRadiusWithHeadingAndPitch(impl::abi_arg_in<Windows::Devices::Geolocation::IGeopoint> location, double radiusInMeters, double headingInDegrees, double pitchInDegrees, impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapScene> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().CreateFromLocationAndRadius(*reinterpret_cast<const Windows::Devices::Geolocation::Geopoint *>(&location), radiusInMeters, headingInDegrees, pitchInDegrees));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromLocations(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Devices::Geolocation::Geopoint>> locations, impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapScene> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().CreateFromLocations(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Devices::Geolocation::Geopoint> *>(&locations)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromLocationsWithHeadingAndPitch(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Devices::Geolocation::Geopoint>> locations, double headingInDegrees, double pitchInDegrees, impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapScene> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().CreateFromLocations(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Devices::Geolocation::Geopoint> *>(&locations), headingInDegrees, pitchInDegrees));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapTargetCameraChangedEventArgs> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapTargetCameraChangedEventArgs>
{
    HRESULT __stdcall get_Camera(impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapCamera> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Camera());
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
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapTargetCameraChangedEventArgs2> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapTargetCameraChangedEventArgs2>
{
    HRESULT __stdcall get_ChangeReason(Windows::UI::Xaml::Controls::Maps::MapCameraChangeReason * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ChangeReason());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapTileBitmapRequest> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapTileBitmapRequest>
{
    HRESULT __stdcall get_PixelData(impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PixelData());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PixelData(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PixelData(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamReference *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapTileBitmapRequestDeferral> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetDeferral());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapTileBitmapRequestDeferral> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapTileBitmapRequestDeferral>
{
    HRESULT __stdcall abi_Complete() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Complete();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapTileBitmapRequestedEventArgs> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapTileBitmapRequestedEventArgs>
{
    HRESULT __stdcall get_X(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().X());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Y(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Y());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ZoomLevel(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ZoomLevel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Request(impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapTileBitmapRequest> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Request());
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
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapTileDataSource> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapTileDataSource>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapTileDataSourceFactory> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapTileDataSourceFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapTileDataSource> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstance(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
            return S_OK;
        }
        catch (...)
        {
            *inner = nullptr;
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapTileSource> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapTileSource>
{
    HRESULT __stdcall get_DataSource(impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapTileDataSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DataSource());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DataSource(impl::abi_arg_in<Windows::UI::Xaml::Controls::Maps::IMapTileDataSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DataSource(*reinterpret_cast<const Windows::UI::Xaml::Controls::Maps::MapTileDataSource *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Layer(Windows::UI::Xaml::Controls::Maps::MapTileLayer * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Layer());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Layer(Windows::UI::Xaml::Controls::Maps::MapTileLayer value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Layer(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ZoomLevelRange(impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ZoomLevelRange());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ZoomLevelRange(impl::abi_arg_in<Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ZoomLevelRange(*reinterpret_cast<const Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Bounds(impl::abi_arg_out<Windows::Devices::Geolocation::IGeoboundingBox> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Bounds());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Bounds(impl::abi_arg_in<Windows::Devices::Geolocation::IGeoboundingBox> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Bounds(*reinterpret_cast<const Windows::Devices::Geolocation::GeoboundingBox *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AllowOverstretch(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllowOverstretch());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AllowOverstretch(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowOverstretch(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsFadingEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsFadingEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsFadingEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsFadingEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsTransparencyEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsTransparencyEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsTransparencyEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsTransparencyEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsRetryEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsRetryEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsRetryEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsRetryEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ZIndex(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ZIndex());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ZIndex(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ZIndex(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TilePixelSize(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TilePixelSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TilePixelSize(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TilePixelSize(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Visible(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Visible());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Visible(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Visible(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapTileSourceFactory> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapTileSourceFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapTileSource> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstance(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
            return S_OK;
        }
        catch (...)
        {
            *inner = nullptr;
            *instance = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateInstanceWithDataSource(impl::abi_arg_in<Windows::UI::Xaml::Controls::Maps::IMapTileDataSource> dataSource, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapTileSource> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithDataSource(*reinterpret_cast<const Windows::UI::Xaml::Controls::Maps::MapTileDataSource *>(&dataSource), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
            return S_OK;
        }
        catch (...)
        {
            *inner = nullptr;
            *instance = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateInstanceWithDataSourceAndZoomRange(impl::abi_arg_in<Windows::UI::Xaml::Controls::Maps::IMapTileDataSource> dataSource, impl::abi_arg_in<Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange> zoomLevelRange, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapTileSource> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithDataSourceAndZoomRange(*reinterpret_cast<const Windows::UI::Xaml::Controls::Maps::MapTileDataSource *>(&dataSource), *reinterpret_cast<const Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange *>(&zoomLevelRange), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
            return S_OK;
        }
        catch (...)
        {
            *inner = nullptr;
            *instance = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateInstanceWithDataSourceZoomRangeAndBounds(impl::abi_arg_in<Windows::UI::Xaml::Controls::Maps::IMapTileDataSource> dataSource, impl::abi_arg_in<Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange> zoomLevelRange, impl::abi_arg_in<Windows::Devices::Geolocation::IGeoboundingBox> bounds, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapTileSource> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithDataSourceZoomRangeAndBounds(*reinterpret_cast<const Windows::UI::Xaml::Controls::Maps::MapTileDataSource *>(&dataSource), *reinterpret_cast<const Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange *>(&zoomLevelRange), *reinterpret_cast<const Windows::Devices::Geolocation::GeoboundingBox *>(&bounds), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
            return S_OK;
        }
        catch (...)
        {
            *inner = nullptr;
            *instance = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateInstanceWithDataSourceZoomRangeBoundsAndTileSize(impl::abi_arg_in<Windows::UI::Xaml::Controls::Maps::IMapTileDataSource> dataSource, impl::abi_arg_in<Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange> zoomLevelRange, impl::abi_arg_in<Windows::Devices::Geolocation::IGeoboundingBox> bounds, int32_t tileSizeInPixels, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapTileSource> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithDataSourceZoomRangeBoundsAndTileSize(*reinterpret_cast<const Windows::UI::Xaml::Controls::Maps::MapTileDataSource *>(&dataSource), *reinterpret_cast<const Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange *>(&zoomLevelRange), *reinterpret_cast<const Windows::Devices::Geolocation::GeoboundingBox *>(&bounds), tileSizeInPixels, *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
            return S_OK;
        }
        catch (...)
        {
            *inner = nullptr;
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapTileSourceStatics> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapTileSourceStatics>
{
    HRESULT __stdcall get_DataSourceProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DataSourceProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LayerProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LayerProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ZoomLevelRangeProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ZoomLevelRangeProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BoundsProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BoundsProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AllowOverstretchProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllowOverstretchProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsFadingEnabledProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsFadingEnabledProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsTransparencyEnabledProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsTransparencyEnabledProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsRetryEnabledProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsRetryEnabledProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ZIndexProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ZIndexProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TilePixelSizeProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TilePixelSizeProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VisibleProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VisibleProperty());
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
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapTileUriRequest> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapTileUriRequest>
{
    HRESULT __stdcall get_Uri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Uri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Uri(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Uri(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapTileUriRequestDeferral> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetDeferral());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapTileUriRequestDeferral> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapTileUriRequestDeferral>
{
    HRESULT __stdcall abi_Complete() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Complete();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IMapTileUriRequestedEventArgs> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IMapTileUriRequestedEventArgs>
{
    HRESULT __stdcall get_X(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().X());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Y(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Y());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ZoomLevel(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ZoomLevel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Request(impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IMapTileUriRequest> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Request());
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
struct produce<D, Windows::UI::Xaml::Controls::Maps::IStreetsideExperience> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IStreetsideExperience>
{
    HRESULT __stdcall get_AddressTextVisible(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AddressTextVisible());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AddressTextVisible(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddressTextVisible(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CursorVisible(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CursorVisible());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CursorVisible(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CursorVisible(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OverviewMapVisible(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OverviewMapVisible());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OverviewMapVisible(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OverviewMapVisible(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StreetLabelsVisible(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StreetLabelsVisible());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StreetLabelsVisible(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StreetLabelsVisible(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExitButtonVisible(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExitButtonVisible());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ExitButtonVisible(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ExitButtonVisible(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ZoomButtonsVisible(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ZoomButtonsVisible());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ZoomButtonsVisible(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ZoomButtonsVisible(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IStreetsideExperienceFactory> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IStreetsideExperienceFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithPanorama(impl::abi_arg_in<Windows::UI::Xaml::Controls::Maps::IStreetsidePanorama> panorama, impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IStreetsideExperience> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithPanorama(*reinterpret_cast<const Windows::UI::Xaml::Controls::Maps::StreetsidePanorama *>(&panorama)));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateInstanceWithPanoramaHeadingPitchAndFieldOfView(impl::abi_arg_in<Windows::UI::Xaml::Controls::Maps::IStreetsidePanorama> panorama, double headingInDegrees, double pitchInDegrees, double fieldOfViewInDegrees, impl::abi_arg_out<Windows::UI::Xaml::Controls::Maps::IStreetsideExperience> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithPanoramaHeadingPitchAndFieldOfView(*reinterpret_cast<const Windows::UI::Xaml::Controls::Maps::StreetsidePanorama *>(&panorama), headingInDegrees, pitchInDegrees, fieldOfViewInDegrees));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Controls::Maps::IStreetsidePanorama> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IStreetsidePanorama>
{
    HRESULT __stdcall get_Location(impl::abi_arg_out<Windows::Devices::Geolocation::IGeopoint> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Location());
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
struct produce<D, Windows::UI::Xaml::Controls::Maps::IStreetsidePanoramaStatics> : produce_base<D, Windows::UI::Xaml::Controls::Maps::IStreetsidePanoramaStatics>
{
    HRESULT __stdcall abi_FindNearbyWithLocationAsync(impl::abi_arg_in<Windows::Devices::Geolocation::IGeopoint> location, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::UI::Xaml::Controls::Maps::StreetsidePanorama>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().FindNearbyAsync(*reinterpret_cast<const Windows::Devices::Geolocation::Geopoint *>(&location)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindNearbyWithLocationAndRadiusAsync(impl::abi_arg_in<Windows::Devices::Geolocation::IGeopoint> location, double radiusInMeters, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::UI::Xaml::Controls::Maps::StreetsidePanorama>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().FindNearbyAsync(*reinterpret_cast<const Windows::Devices::Geolocation::Geopoint *>(&location), radiusInMeters));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::UI::Xaml::Controls::Maps {

template <typename D> Windows::UI::Xaml::Controls::Maps::MapCamera impl_IMapActualCameraChangedEventArgs<D>::Camera() const
{
    Windows::UI::Xaml::Controls::Maps::MapCamera value { nullptr };
    check_hresult(WINRT_SHIM(IMapActualCameraChangedEventArgs)->get_Camera(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapCameraChangeReason impl_IMapActualCameraChangedEventArgs2<D>::ChangeReason() const
{
    Windows::UI::Xaml::Controls::Maps::MapCameraChangeReason value {};
    check_hresult(WINRT_SHIM(IMapActualCameraChangedEventArgs2)->get_ChangeReason(&value));
    return value;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapCamera impl_IMapActualCameraChangingEventArgs<D>::Camera() const
{
    Windows::UI::Xaml::Controls::Maps::MapCamera value { nullptr };
    check_hresult(WINRT_SHIM(IMapActualCameraChangingEventArgs)->get_Camera(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapCameraChangeReason impl_IMapActualCameraChangingEventArgs2<D>::ChangeReason() const
{
    Windows::UI::Xaml::Controls::Maps::MapCameraChangeReason value {};
    check_hresult(WINRT_SHIM(IMapActualCameraChangingEventArgs2)->get_ChangeReason(&value));
    return value;
}

template <typename D> Windows::Foundation::Point impl_IMapElementClickEventArgs<D>::Position() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(IMapElementClickEventArgs)->get_Position(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geopoint impl_IMapElementClickEventArgs<D>::Location() const
{
    Windows::Devices::Geolocation::Geopoint value { nullptr };
    check_hresult(WINRT_SHIM(IMapElementClickEventArgs)->get_Location(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::Maps::MapElement> impl_IMapElementClickEventArgs<D>::MapElements() const
{
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::Maps::MapElement> value;
    check_hresult(WINRT_SHIM(IMapElementClickEventArgs)->get_MapElements(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Point impl_IMapElementPointerEnteredEventArgs<D>::Position() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(IMapElementPointerEnteredEventArgs)->get_Position(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geopoint impl_IMapElementPointerEnteredEventArgs<D>::Location() const
{
    Windows::Devices::Geolocation::Geopoint value { nullptr };
    check_hresult(WINRT_SHIM(IMapElementPointerEnteredEventArgs)->get_Location(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapElement impl_IMapElementPointerEnteredEventArgs<D>::MapElement() const
{
    Windows::UI::Xaml::Controls::Maps::MapElement value { nullptr };
    check_hresult(WINRT_SHIM(IMapElementPointerEnteredEventArgs)->get_MapElement(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Point impl_IMapElementPointerExitedEventArgs<D>::Position() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(IMapElementPointerExitedEventArgs)->get_Position(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geopoint impl_IMapElementPointerExitedEventArgs<D>::Location() const
{
    Windows::Devices::Geolocation::Geopoint value { nullptr };
    check_hresult(WINRT_SHIM(IMapElementPointerExitedEventArgs)->get_Location(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapElement impl_IMapElementPointerExitedEventArgs<D>::MapElement() const
{
    Windows::UI::Xaml::Controls::Maps::MapElement value { nullptr };
    check_hresult(WINRT_SHIM(IMapElementPointerExitedEventArgs)->get_MapElement(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Point impl_IMapRightTappedEventArgs<D>::Position() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(IMapRightTappedEventArgs)->get_Position(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geopoint impl_IMapRightTappedEventArgs<D>::Location() const
{
    Windows::Devices::Geolocation::Geopoint value { nullptr };
    check_hresult(WINRT_SHIM(IMapRightTappedEventArgs)->get_Location(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapCamera impl_IMapTargetCameraChangedEventArgs<D>::Camera() const
{
    Windows::UI::Xaml::Controls::Maps::MapCamera value { nullptr };
    check_hresult(WINRT_SHIM(IMapTargetCameraChangedEventArgs)->get_Camera(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapCameraChangeReason impl_IMapTargetCameraChangedEventArgs2<D>::ChangeReason() const
{
    Windows::UI::Xaml::Controls::Maps::MapCameraChangeReason value {};
    check_hresult(WINRT_SHIM(IMapTargetCameraChangedEventArgs2)->get_ChangeReason(&value));
    return value;
}

template <typename D> Windows::Storage::Streams::IRandomAccessStreamReference impl_IMapTileBitmapRequest<D>::PixelData() const
{
    Windows::Storage::Streams::IRandomAccessStreamReference value;
    check_hresult(WINRT_SHIM(IMapTileBitmapRequest)->get_PixelData(put_abi(value)));
    return value;
}

template <typename D> void impl_IMapTileBitmapRequest<D>::PixelData(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const
{
    check_hresult(WINRT_SHIM(IMapTileBitmapRequest)->put_PixelData(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapTileBitmapRequestDeferral impl_IMapTileBitmapRequest<D>::GetDeferral() const
{
    Windows::UI::Xaml::Controls::Maps::MapTileBitmapRequestDeferral returnValue { nullptr };
    check_hresult(WINRT_SHIM(IMapTileBitmapRequest)->abi_GetDeferral(put_abi(returnValue)));
    return returnValue;
}

template <typename D> void impl_IMapTileBitmapRequestDeferral<D>::Complete() const
{
    check_hresult(WINRT_SHIM(IMapTileBitmapRequestDeferral)->abi_Complete());
}

template <typename D> int32_t impl_IMapTileBitmapRequestedEventArgs<D>::X() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IMapTileBitmapRequestedEventArgs)->get_X(&value));
    return value;
}

template <typename D> int32_t impl_IMapTileBitmapRequestedEventArgs<D>::Y() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IMapTileBitmapRequestedEventArgs)->get_Y(&value));
    return value;
}

template <typename D> int32_t impl_IMapTileBitmapRequestedEventArgs<D>::ZoomLevel() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IMapTileBitmapRequestedEventArgs)->get_ZoomLevel(&value));
    return value;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapTileBitmapRequest impl_IMapTileBitmapRequestedEventArgs<D>::Request() const
{
    Windows::UI::Xaml::Controls::Maps::MapTileBitmapRequest value { nullptr };
    check_hresult(WINRT_SHIM(IMapTileBitmapRequestedEventArgs)->get_Request(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_IMapTileUriRequest<D>::Uri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IMapTileUriRequest)->get_Uri(put_abi(value)));
    return value;
}

template <typename D> void impl_IMapTileUriRequest<D>::Uri(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(IMapTileUriRequest)->put_Uri(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapTileUriRequestDeferral impl_IMapTileUriRequest<D>::GetDeferral() const
{
    Windows::UI::Xaml::Controls::Maps::MapTileUriRequestDeferral returnValue { nullptr };
    check_hresult(WINRT_SHIM(IMapTileUriRequest)->abi_GetDeferral(put_abi(returnValue)));
    return returnValue;
}

template <typename D> void impl_IMapTileUriRequestDeferral<D>::Complete() const
{
    check_hresult(WINRT_SHIM(IMapTileUriRequestDeferral)->abi_Complete());
}

template <typename D> int32_t impl_IMapTileUriRequestedEventArgs<D>::X() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IMapTileUriRequestedEventArgs)->get_X(&value));
    return value;
}

template <typename D> int32_t impl_IMapTileUriRequestedEventArgs<D>::Y() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IMapTileUriRequestedEventArgs)->get_Y(&value));
    return value;
}

template <typename D> int32_t impl_IMapTileUriRequestedEventArgs<D>::ZoomLevel() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IMapTileUriRequestedEventArgs)->get_ZoomLevel(&value));
    return value;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapTileUriRequest impl_IMapTileUriRequestedEventArgs<D>::Request() const
{
    Windows::UI::Xaml::Controls::Maps::MapTileUriRequest value { nullptr };
    check_hresult(WINRT_SHIM(IMapTileUriRequestedEventArgs)->get_Request(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geopoint impl_IMapCamera<D>::Location() const
{
    Windows::Devices::Geolocation::Geopoint value { nullptr };
    check_hresult(WINRT_SHIM(IMapCamera)->get_Location(put_abi(value)));
    return value;
}

template <typename D> void impl_IMapCamera<D>::Location(const Windows::Devices::Geolocation::Geopoint & value) const
{
    check_hresult(WINRT_SHIM(IMapCamera)->put_Location(get_abi(value)));
}

template <typename D> double impl_IMapCamera<D>::Heading() const
{
    double value {};
    check_hresult(WINRT_SHIM(IMapCamera)->get_Heading(&value));
    return value;
}

template <typename D> void impl_IMapCamera<D>::Heading(double value) const
{
    check_hresult(WINRT_SHIM(IMapCamera)->put_Heading(value));
}

template <typename D> double impl_IMapCamera<D>::Pitch() const
{
    double value {};
    check_hresult(WINRT_SHIM(IMapCamera)->get_Pitch(&value));
    return value;
}

template <typename D> void impl_IMapCamera<D>::Pitch(double value) const
{
    check_hresult(WINRT_SHIM(IMapCamera)->put_Pitch(value));
}

template <typename D> double impl_IMapCamera<D>::Roll() const
{
    double value {};
    check_hresult(WINRT_SHIM(IMapCamera)->get_Roll(&value));
    return value;
}

template <typename D> void impl_IMapCamera<D>::Roll(double value) const
{
    check_hresult(WINRT_SHIM(IMapCamera)->put_Roll(value));
}

template <typename D> double impl_IMapCamera<D>::FieldOfView() const
{
    double value {};
    check_hresult(WINRT_SHIM(IMapCamera)->get_FieldOfView(&value));
    return value;
}

template <typename D> void impl_IMapCamera<D>::FieldOfView(double value) const
{
    check_hresult(WINRT_SHIM(IMapCamera)->put_FieldOfView(value));
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapCamera impl_IMapCameraFactory<D>::CreateInstanceWithLocation(const Windows::Devices::Geolocation::Geopoint & location) const
{
    Windows::UI::Xaml::Controls::Maps::MapCamera instance { nullptr };
    check_hresult(WINRT_SHIM(IMapCameraFactory)->abi_CreateInstanceWithLocation(get_abi(location), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapCamera impl_IMapCameraFactory<D>::CreateInstanceWithLocationAndHeading(const Windows::Devices::Geolocation::Geopoint & location, double headingInDegrees) const
{
    Windows::UI::Xaml::Controls::Maps::MapCamera instance { nullptr };
    check_hresult(WINRT_SHIM(IMapCameraFactory)->abi_CreateInstanceWithLocationAndHeading(get_abi(location), headingInDegrees, put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapCamera impl_IMapCameraFactory<D>::CreateInstanceWithLocationHeadingAndPitch(const Windows::Devices::Geolocation::Geopoint & location, double headingInDegrees, double pitchInDegrees) const
{
    Windows::UI::Xaml::Controls::Maps::MapCamera instance { nullptr };
    check_hresult(WINRT_SHIM(IMapCameraFactory)->abi_CreateInstanceWithLocationHeadingAndPitch(get_abi(location), headingInDegrees, pitchInDegrees, put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapCamera impl_IMapCameraFactory<D>::CreateInstanceWithLocationHeadingPitchRollAndFieldOfView(const Windows::Devices::Geolocation::Geopoint & location, double headingInDegrees, double pitchInDegrees, double rollInDegrees, double fieldOfViewInDegrees) const
{
    Windows::UI::Xaml::Controls::Maps::MapCamera instance { nullptr };
    check_hresult(WINRT_SHIM(IMapCameraFactory)->abi_CreateInstanceWithLocationHeadingPitchRollAndFieldOfView(get_abi(location), headingInDegrees, pitchInDegrees, rollInDegrees, fieldOfViewInDegrees, put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapCustomExperience impl_IMapCustomExperienceFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Controls::Maps::MapCustomExperience instance { nullptr };
    check_hresult(WINRT_SHIM(IMapCustomExperienceFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> int32_t impl_IMapElement<D>::ZIndex() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IMapElement)->get_ZIndex(&value));
    return value;
}

template <typename D> void impl_IMapElement<D>::ZIndex(int32_t value) const
{
    check_hresult(WINRT_SHIM(IMapElement)->put_ZIndex(value));
}

template <typename D> bool impl_IMapElement<D>::Visible() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMapElement)->get_Visible(&value));
    return value;
}

template <typename D> void impl_IMapElement<D>::Visible(bool value) const
{
    check_hresult(WINRT_SHIM(IMapElement)->put_Visible(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapElementStatics<D>::ZIndexProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapElementStatics)->get_ZIndexProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapElementStatics<D>::VisibleProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapElementStatics)->get_VisibleProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapElement impl_IMapElementFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Controls::Maps::MapElement instance { nullptr };
    check_hresult(WINRT_SHIM(IMapElementFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> int32_t impl_IMapElement2<D>::MapTabIndex() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IMapElement2)->get_MapTabIndex(&value));
    return value;
}

template <typename D> void impl_IMapElement2<D>::MapTabIndex(int32_t value) const
{
    check_hresult(WINRT_SHIM(IMapElement2)->put_MapTabIndex(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapElementStatics2<D>::MapTabIndexProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapElementStatics2)->get_MapTabIndexProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Point impl_IMapInputEventArgs<D>::Position() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(IMapInputEventArgs)->get_Position(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geopoint impl_IMapInputEventArgs<D>::Location() const
{
    Windows::Devices::Geolocation::Geopoint value { nullptr };
    check_hresult(WINRT_SHIM(IMapInputEventArgs)->get_Location(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IInspectable impl_IMapItemsControl<D>::ItemsSource() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IMapItemsControl)->get_ItemsSource(put_abi(value)));
    return value;
}

template <typename D> void impl_IMapItemsControl<D>::ItemsSource(const Windows::Foundation::IInspectable & value) const
{
    check_hresult(WINRT_SHIM(IMapItemsControl)->put_ItemsSource(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::UI::Xaml::DependencyObject> impl_IMapItemsControl<D>::Items() const
{
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::DependencyObject> value;
    check_hresult(WINRT_SHIM(IMapItemsControl)->get_Items(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DataTemplate impl_IMapItemsControl<D>::ItemTemplate() const
{
    Windows::UI::Xaml::DataTemplate value { nullptr };
    check_hresult(WINRT_SHIM(IMapItemsControl)->get_ItemTemplate(put_abi(value)));
    return value;
}

template <typename D> void impl_IMapItemsControl<D>::ItemTemplate(const Windows::UI::Xaml::DataTemplate & value) const
{
    check_hresult(WINRT_SHIM(IMapItemsControl)->put_ItemTemplate(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapItemsControlStatics<D>::ItemsSourceProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapItemsControlStatics)->get_ItemsSourceProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapItemsControlStatics<D>::ItemsProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapItemsControlStatics)->get_ItemsProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapItemsControlStatics<D>::ItemTemplateProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapItemsControlStatics)->get_ItemTemplateProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Color impl_IMapRouteView<D>::RouteColor() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IMapRouteView)->get_RouteColor(put_abi(value)));
    return value;
}

template <typename D> void impl_IMapRouteView<D>::RouteColor(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(IMapRouteView)->put_RouteColor(get_abi(value)));
}

template <typename D> Windows::UI::Color impl_IMapRouteView<D>::OutlineColor() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IMapRouteView)->get_OutlineColor(put_abi(value)));
    return value;
}

template <typename D> void impl_IMapRouteView<D>::OutlineColor(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(IMapRouteView)->put_OutlineColor(get_abi(value)));
}

template <typename D> Windows::Services::Maps::MapRoute impl_IMapRouteView<D>::Route() const
{
    Windows::Services::Maps::MapRoute value { nullptr };
    check_hresult(WINRT_SHIM(IMapRouteView)->get_Route(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapRouteView impl_IMapRouteViewFactory<D>::CreateInstanceWithMapRoute(const Windows::Services::Maps::MapRoute & route, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Controls::Maps::MapRouteView instance { nullptr };
    check_hresult(WINRT_SHIM(IMapRouteViewFactory)->abi_CreateInstanceWithMapRoute(get_abi(route), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapCamera impl_IMapScene<D>::TargetCamera() const
{
    Windows::UI::Xaml::Controls::Maps::MapCamera value { nullptr };
    check_hresult(WINRT_SHIM(IMapScene)->get_TargetCamera(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IMapScene<D>::TargetCameraChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapScene, Windows::UI::Xaml::Controls::Maps::MapTargetCameraChangedEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMapScene)->add_TargetCameraChanged(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMapScene> impl_IMapScene<D>::TargetCameraChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapScene, Windows::UI::Xaml::Controls::Maps::MapTargetCameraChangedEventArgs> & value) const
{
    return impl::make_event_revoker<D, IMapScene>(this, &ABI::Windows::UI::Xaml::Controls::Maps::IMapScene::remove_TargetCameraChanged, TargetCameraChanged(value));
}

template <typename D> void impl_IMapScene<D>::TargetCameraChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IMapScene)->remove_TargetCameraChanged(token));
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapScene impl_IMapSceneStatics<D>::CreateFromBoundingBox(const Windows::Devices::Geolocation::GeoboundingBox & bounds) const
{
    Windows::UI::Xaml::Controls::Maps::MapScene returnValue { nullptr };
    check_hresult(WINRT_SHIM(IMapSceneStatics)->abi_CreateFromBoundingBox(get_abi(bounds), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapScene impl_IMapSceneStatics<D>::CreateFromBoundingBox(const Windows::Devices::Geolocation::GeoboundingBox & bounds, double headingInDegrees, double pitchInDegrees) const
{
    Windows::UI::Xaml::Controls::Maps::MapScene returnValue { nullptr };
    check_hresult(WINRT_SHIM(IMapSceneStatics)->abi_CreateFromBoundingBoxWithHeadingAndPitch(get_abi(bounds), headingInDegrees, pitchInDegrees, put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapScene impl_IMapSceneStatics<D>::CreateFromCamera(const Windows::UI::Xaml::Controls::Maps::MapCamera & camera) const
{
    Windows::UI::Xaml::Controls::Maps::MapScene returnValue { nullptr };
    check_hresult(WINRT_SHIM(IMapSceneStatics)->abi_CreateFromCamera(get_abi(camera), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapScene impl_IMapSceneStatics<D>::CreateFromLocation(const Windows::Devices::Geolocation::Geopoint & location) const
{
    Windows::UI::Xaml::Controls::Maps::MapScene returnValue { nullptr };
    check_hresult(WINRT_SHIM(IMapSceneStatics)->abi_CreateFromLocation(get_abi(location), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapScene impl_IMapSceneStatics<D>::CreateFromLocation(const Windows::Devices::Geolocation::Geopoint & location, double headingInDegrees, double pitchInDegrees) const
{
    Windows::UI::Xaml::Controls::Maps::MapScene returnValue { nullptr };
    check_hresult(WINRT_SHIM(IMapSceneStatics)->abi_CreateFromLocationWithHeadingAndPitch(get_abi(location), headingInDegrees, pitchInDegrees, put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapScene impl_IMapSceneStatics<D>::CreateFromLocationAndRadius(const Windows::Devices::Geolocation::Geopoint & location, double radiusInMeters) const
{
    Windows::UI::Xaml::Controls::Maps::MapScene returnValue { nullptr };
    check_hresult(WINRT_SHIM(IMapSceneStatics)->abi_CreateFromLocationAndRadius(get_abi(location), radiusInMeters, put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapScene impl_IMapSceneStatics<D>::CreateFromLocationAndRadius(const Windows::Devices::Geolocation::Geopoint & location, double radiusInMeters, double headingInDegrees, double pitchInDegrees) const
{
    Windows::UI::Xaml::Controls::Maps::MapScene returnValue { nullptr };
    check_hresult(WINRT_SHIM(IMapSceneStatics)->abi_CreateFromLocationAndRadiusWithHeadingAndPitch(get_abi(location), radiusInMeters, headingInDegrees, pitchInDegrees, put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapScene impl_IMapSceneStatics<D>::CreateFromLocations(iterable<Windows::Devices::Geolocation::Geopoint> locations) const
{
    Windows::UI::Xaml::Controls::Maps::MapScene returnValue { nullptr };
    check_hresult(WINRT_SHIM(IMapSceneStatics)->abi_CreateFromLocations(get_abi(locations), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapScene impl_IMapSceneStatics<D>::CreateFromLocations(iterable<Windows::Devices::Geolocation::Geopoint> locations, double headingInDegrees, double pitchInDegrees) const
{
    Windows::UI::Xaml::Controls::Maps::MapScene returnValue { nullptr };
    check_hresult(WINRT_SHIM(IMapSceneStatics)->abi_CreateFromLocationsWithHeadingAndPitch(get_abi(locations), headingInDegrees, pitchInDegrees, put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapTileDataSource impl_IMapTileDataSourceFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Controls::Maps::MapTileDataSource instance { nullptr };
    check_hresult(WINRT_SHIM(IMapTileDataSourceFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapTileDataSource impl_IMapTileSource<D>::DataSource() const
{
    Windows::UI::Xaml::Controls::Maps::MapTileDataSource value { nullptr };
    check_hresult(WINRT_SHIM(IMapTileSource)->get_DataSource(put_abi(value)));
    return value;
}

template <typename D> void impl_IMapTileSource<D>::DataSource(const Windows::UI::Xaml::Controls::Maps::MapTileDataSource & value) const
{
    check_hresult(WINRT_SHIM(IMapTileSource)->put_DataSource(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapTileLayer impl_IMapTileSource<D>::Layer() const
{
    Windows::UI::Xaml::Controls::Maps::MapTileLayer value {};
    check_hresult(WINRT_SHIM(IMapTileSource)->get_Layer(&value));
    return value;
}

template <typename D> void impl_IMapTileSource<D>::Layer(Windows::UI::Xaml::Controls::Maps::MapTileLayer value) const
{
    check_hresult(WINRT_SHIM(IMapTileSource)->put_Layer(value));
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange impl_IMapTileSource<D>::ZoomLevelRange() const
{
    Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange value {};
    check_hresult(WINRT_SHIM(IMapTileSource)->get_ZoomLevelRange(put_abi(value)));
    return value;
}

template <typename D> void impl_IMapTileSource<D>::ZoomLevelRange(const Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange & value) const
{
    check_hresult(WINRT_SHIM(IMapTileSource)->put_ZoomLevelRange(get_abi(value)));
}

template <typename D> Windows::Devices::Geolocation::GeoboundingBox impl_IMapTileSource<D>::Bounds() const
{
    Windows::Devices::Geolocation::GeoboundingBox value { nullptr };
    check_hresult(WINRT_SHIM(IMapTileSource)->get_Bounds(put_abi(value)));
    return value;
}

template <typename D> void impl_IMapTileSource<D>::Bounds(const Windows::Devices::Geolocation::GeoboundingBox & value) const
{
    check_hresult(WINRT_SHIM(IMapTileSource)->put_Bounds(get_abi(value)));
}

template <typename D> bool impl_IMapTileSource<D>::AllowOverstretch() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMapTileSource)->get_AllowOverstretch(&value));
    return value;
}

template <typename D> void impl_IMapTileSource<D>::AllowOverstretch(bool value) const
{
    check_hresult(WINRT_SHIM(IMapTileSource)->put_AllowOverstretch(value));
}

template <typename D> bool impl_IMapTileSource<D>::IsFadingEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMapTileSource)->get_IsFadingEnabled(&value));
    return value;
}

template <typename D> void impl_IMapTileSource<D>::IsFadingEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IMapTileSource)->put_IsFadingEnabled(value));
}

template <typename D> bool impl_IMapTileSource<D>::IsTransparencyEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMapTileSource)->get_IsTransparencyEnabled(&value));
    return value;
}

template <typename D> void impl_IMapTileSource<D>::IsTransparencyEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IMapTileSource)->put_IsTransparencyEnabled(value));
}

template <typename D> bool impl_IMapTileSource<D>::IsRetryEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMapTileSource)->get_IsRetryEnabled(&value));
    return value;
}

template <typename D> void impl_IMapTileSource<D>::IsRetryEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IMapTileSource)->put_IsRetryEnabled(value));
}

template <typename D> int32_t impl_IMapTileSource<D>::ZIndex() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IMapTileSource)->get_ZIndex(&value));
    return value;
}

template <typename D> void impl_IMapTileSource<D>::ZIndex(int32_t value) const
{
    check_hresult(WINRT_SHIM(IMapTileSource)->put_ZIndex(value));
}

template <typename D> int32_t impl_IMapTileSource<D>::TilePixelSize() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IMapTileSource)->get_TilePixelSize(&value));
    return value;
}

template <typename D> void impl_IMapTileSource<D>::TilePixelSize(int32_t value) const
{
    check_hresult(WINRT_SHIM(IMapTileSource)->put_TilePixelSize(value));
}

template <typename D> bool impl_IMapTileSource<D>::Visible() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMapTileSource)->get_Visible(&value));
    return value;
}

template <typename D> void impl_IMapTileSource<D>::Visible(bool value) const
{
    check_hresult(WINRT_SHIM(IMapTileSource)->put_Visible(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapTileSourceStatics<D>::DataSourceProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapTileSourceStatics)->get_DataSourceProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapTileSourceStatics<D>::LayerProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapTileSourceStatics)->get_LayerProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapTileSourceStatics<D>::ZoomLevelRangeProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapTileSourceStatics)->get_ZoomLevelRangeProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapTileSourceStatics<D>::BoundsProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapTileSourceStatics)->get_BoundsProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapTileSourceStatics<D>::AllowOverstretchProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapTileSourceStatics)->get_AllowOverstretchProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapTileSourceStatics<D>::IsFadingEnabledProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapTileSourceStatics)->get_IsFadingEnabledProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapTileSourceStatics<D>::IsTransparencyEnabledProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapTileSourceStatics)->get_IsTransparencyEnabledProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapTileSourceStatics<D>::IsRetryEnabledProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapTileSourceStatics)->get_IsRetryEnabledProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapTileSourceStatics<D>::ZIndexProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapTileSourceStatics)->get_ZIndexProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapTileSourceStatics<D>::TilePixelSizeProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapTileSourceStatics)->get_TilePixelSizeProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapTileSourceStatics<D>::VisibleProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapTileSourceStatics)->get_VisibleProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapTileSource impl_IMapTileSourceFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Controls::Maps::MapTileSource instance { nullptr };
    check_hresult(WINRT_SHIM(IMapTileSourceFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapTileSource impl_IMapTileSourceFactory<D>::CreateInstanceWithDataSource(const Windows::UI::Xaml::Controls::Maps::MapTileDataSource & dataSource, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Controls::Maps::MapTileSource instance { nullptr };
    check_hresult(WINRT_SHIM(IMapTileSourceFactory)->abi_CreateInstanceWithDataSource(get_abi(dataSource), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapTileSource impl_IMapTileSourceFactory<D>::CreateInstanceWithDataSourceAndZoomRange(const Windows::UI::Xaml::Controls::Maps::MapTileDataSource & dataSource, const Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange & zoomLevelRange, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Controls::Maps::MapTileSource instance { nullptr };
    check_hresult(WINRT_SHIM(IMapTileSourceFactory)->abi_CreateInstanceWithDataSourceAndZoomRange(get_abi(dataSource), get_abi(zoomLevelRange), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapTileSource impl_IMapTileSourceFactory<D>::CreateInstanceWithDataSourceZoomRangeAndBounds(const Windows::UI::Xaml::Controls::Maps::MapTileDataSource & dataSource, const Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange & zoomLevelRange, const Windows::Devices::Geolocation::GeoboundingBox & bounds, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Controls::Maps::MapTileSource instance { nullptr };
    check_hresult(WINRT_SHIM(IMapTileSourceFactory)->abi_CreateInstanceWithDataSourceZoomRangeAndBounds(get_abi(dataSource), get_abi(zoomLevelRange), get_abi(bounds), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapTileSource impl_IMapTileSourceFactory<D>::CreateInstanceWithDataSourceZoomRangeBoundsAndTileSize(const Windows::UI::Xaml::Controls::Maps::MapTileDataSource & dataSource, const Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange & zoomLevelRange, const Windows::Devices::Geolocation::GeoboundingBox & bounds, int32_t tileSizeInPixels, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Controls::Maps::MapTileSource instance { nullptr };
    check_hresult(WINRT_SHIM(IMapTileSourceFactory)->abi_CreateInstanceWithDataSourceZoomRangeBoundsAndTileSize(get_abi(dataSource), get_abi(zoomLevelRange), get_abi(bounds), tileSizeInPixels, get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::Devices::Geolocation::Geopoint impl_IStreetsidePanorama<D>::Location() const
{
    Windows::Devices::Geolocation::Geopoint value { nullptr };
    check_hresult(WINRT_SHIM(IStreetsidePanorama)->get_Location(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::UI::Xaml::Controls::Maps::StreetsidePanorama> impl_IStreetsidePanoramaStatics<D>::FindNearbyAsync(const Windows::Devices::Geolocation::Geopoint & location) const
{
    Windows::Foundation::IAsyncOperation<Windows::UI::Xaml::Controls::Maps::StreetsidePanorama> returnValue;
    check_hresult(WINRT_SHIM(IStreetsidePanoramaStatics)->abi_FindNearbyWithLocationAsync(get_abi(location), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::UI::Xaml::Controls::Maps::StreetsidePanorama> impl_IStreetsidePanoramaStatics<D>::FindNearbyAsync(const Windows::Devices::Geolocation::Geopoint & location, double radiusInMeters) const
{
    Windows::Foundation::IAsyncOperation<Windows::UI::Xaml::Controls::Maps::StreetsidePanorama> returnValue;
    check_hresult(WINRT_SHIM(IStreetsidePanoramaStatics)->abi_FindNearbyWithLocationAndRadiusAsync(get_abi(location), radiusInMeters, put_abi(returnValue)));
    return returnValue;
}

template <typename D> event_token impl_ICustomMapTileDataSource<D>::BitmapRequested(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::CustomMapTileDataSource, Windows::UI::Xaml::Controls::Maps::MapTileBitmapRequestedEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ICustomMapTileDataSource)->add_BitmapRequested(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<ICustomMapTileDataSource> impl_ICustomMapTileDataSource<D>::BitmapRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::CustomMapTileDataSource, Windows::UI::Xaml::Controls::Maps::MapTileBitmapRequestedEventArgs> & value) const
{
    return impl::make_event_revoker<D, ICustomMapTileDataSource>(this, &ABI::Windows::UI::Xaml::Controls::Maps::ICustomMapTileDataSource::remove_BitmapRequested, BitmapRequested(value));
}

template <typename D> void impl_ICustomMapTileDataSource<D>::BitmapRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(ICustomMapTileDataSource)->remove_BitmapRequested(token));
}

template <typename D> Windows::UI::Xaml::Controls::Maps::CustomMapTileDataSource impl_ICustomMapTileDataSourceFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Controls::Maps::CustomMapTileDataSource instance { nullptr };
    check_hresult(WINRT_SHIM(ICustomMapTileDataSourceFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> hstring impl_IHttpMapTileDataSource<D>::UriFormatString() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHttpMapTileDataSource)->get_UriFormatString(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpMapTileDataSource<D>::UriFormatString(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IHttpMapTileDataSource)->put_UriFormatString(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IMap<hstring, hstring> impl_IHttpMapTileDataSource<D>::AdditionalRequestHeaders() const
{
    Windows::Foundation::Collections::IMap<hstring, hstring> value;
    check_hresult(WINRT_SHIM(IHttpMapTileDataSource)->get_AdditionalRequestHeaders(put_abi(value)));
    return value;
}

template <typename D> bool impl_IHttpMapTileDataSource<D>::AllowCaching() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IHttpMapTileDataSource)->get_AllowCaching(&value));
    return value;
}

template <typename D> void impl_IHttpMapTileDataSource<D>::AllowCaching(bool value) const
{
    check_hresult(WINRT_SHIM(IHttpMapTileDataSource)->put_AllowCaching(value));
}

template <typename D> event_token impl_IHttpMapTileDataSource<D>::UriRequested(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::HttpMapTileDataSource, Windows::UI::Xaml::Controls::Maps::MapTileUriRequestedEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IHttpMapTileDataSource)->add_UriRequested(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IHttpMapTileDataSource> impl_IHttpMapTileDataSource<D>::UriRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::HttpMapTileDataSource, Windows::UI::Xaml::Controls::Maps::MapTileUriRequestedEventArgs> & value) const
{
    return impl::make_event_revoker<D, IHttpMapTileDataSource>(this, &ABI::Windows::UI::Xaml::Controls::Maps::IHttpMapTileDataSource::remove_UriRequested, UriRequested(value));
}

template <typename D> void impl_IHttpMapTileDataSource<D>::UriRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IHttpMapTileDataSource)->remove_UriRequested(token));
}

template <typename D> Windows::UI::Xaml::Controls::Maps::HttpMapTileDataSource impl_IHttpMapTileDataSourceFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Controls::Maps::HttpMapTileDataSource instance { nullptr };
    check_hresult(WINRT_SHIM(IHttpMapTileDataSourceFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::HttpMapTileDataSource impl_IHttpMapTileDataSourceFactory<D>::CreateInstanceWithUriFormatString(hstring_view uriFormatString, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Controls::Maps::HttpMapTileDataSource instance { nullptr };
    check_hresult(WINRT_SHIM(IHttpMapTileDataSourceFactory)->abi_CreateInstanceWithUriFormatString(get_abi(uriFormatString), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> hstring impl_ILocalMapTileDataSource<D>::UriFormatString() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ILocalMapTileDataSource)->get_UriFormatString(put_abi(value)));
    return value;
}

template <typename D> void impl_ILocalMapTileDataSource<D>::UriFormatString(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ILocalMapTileDataSource)->put_UriFormatString(get_abi(value)));
}

template <typename D> event_token impl_ILocalMapTileDataSource<D>::UriRequested(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::LocalMapTileDataSource, Windows::UI::Xaml::Controls::Maps::MapTileUriRequestedEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ILocalMapTileDataSource)->add_UriRequested(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<ILocalMapTileDataSource> impl_ILocalMapTileDataSource<D>::UriRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::LocalMapTileDataSource, Windows::UI::Xaml::Controls::Maps::MapTileUriRequestedEventArgs> & value) const
{
    return impl::make_event_revoker<D, ILocalMapTileDataSource>(this, &ABI::Windows::UI::Xaml::Controls::Maps::ILocalMapTileDataSource::remove_UriRequested, UriRequested(value));
}

template <typename D> void impl_ILocalMapTileDataSource<D>::UriRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(ILocalMapTileDataSource)->remove_UriRequested(token));
}

template <typename D> Windows::UI::Xaml::Controls::Maps::LocalMapTileDataSource impl_ILocalMapTileDataSourceFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Controls::Maps::LocalMapTileDataSource instance { nullptr };
    check_hresult(WINRT_SHIM(ILocalMapTileDataSourceFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::LocalMapTileDataSource impl_ILocalMapTileDataSourceFactory<D>::CreateInstanceWithUriFormatString(hstring_view uriFormatString, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Controls::Maps::LocalMapTileDataSource instance { nullptr };
    check_hresult(WINRT_SHIM(ILocalMapTileDataSourceFactory)->abi_CreateInstanceWithUriFormatString(get_abi(uriFormatString), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::Devices::Geolocation::Geopoint impl_IMapIcon<D>::Location() const
{
    Windows::Devices::Geolocation::Geopoint value { nullptr };
    check_hresult(WINRT_SHIM(IMapIcon)->get_Location(put_abi(value)));
    return value;
}

template <typename D> void impl_IMapIcon<D>::Location(const Windows::Devices::Geolocation::Geopoint & value) const
{
    check_hresult(WINRT_SHIM(IMapIcon)->put_Location(get_abi(value)));
}

template <typename D> hstring impl_IMapIcon<D>::Title() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMapIcon)->get_Title(put_abi(value)));
    return value;
}

template <typename D> void impl_IMapIcon<D>::Title(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IMapIcon)->put_Title(get_abi(value)));
}

template <typename D> Windows::Foundation::Point impl_IMapIcon<D>::NormalizedAnchorPoint() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(IMapIcon)->get_NormalizedAnchorPoint(put_abi(value)));
    return value;
}

template <typename D> void impl_IMapIcon<D>::NormalizedAnchorPoint(const Windows::Foundation::Point & value) const
{
    check_hresult(WINRT_SHIM(IMapIcon)->put_NormalizedAnchorPoint(get_abi(value)));
}

template <typename D> Windows::Storage::Streams::IRandomAccessStreamReference impl_IMapIcon<D>::Image() const
{
    Windows::Storage::Streams::IRandomAccessStreamReference value;
    check_hresult(WINRT_SHIM(IMapIcon)->get_Image(put_abi(value)));
    return value;
}

template <typename D> void impl_IMapIcon<D>::Image(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const
{
    check_hresult(WINRT_SHIM(IMapIcon)->put_Image(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapIconStatics<D>::LocationProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapIconStatics)->get_LocationProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapIconStatics<D>::TitleProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapIconStatics)->get_TitleProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapIconStatics<D>::NormalizedAnchorPointProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapIconStatics)->get_NormalizedAnchorPointProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapElementCollisionBehavior impl_IMapIcon2<D>::CollisionBehaviorDesired() const
{
    Windows::UI::Xaml::Controls::Maps::MapElementCollisionBehavior value {};
    check_hresult(WINRT_SHIM(IMapIcon2)->get_CollisionBehaviorDesired(&value));
    return value;
}

template <typename D> void impl_IMapIcon2<D>::CollisionBehaviorDesired(Windows::UI::Xaml::Controls::Maps::MapElementCollisionBehavior value) const
{
    check_hresult(WINRT_SHIM(IMapIcon2)->put_CollisionBehaviorDesired(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapIconStatics2<D>::CollisionBehaviorDesiredProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapIconStatics2)->get_CollisionBehaviorDesiredProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geopath impl_IMapPolygon<D>::Path() const
{
    Windows::Devices::Geolocation::Geopath value { nullptr };
    check_hresult(WINRT_SHIM(IMapPolygon)->get_Path(put_abi(value)));
    return value;
}

template <typename D> void impl_IMapPolygon<D>::Path(const Windows::Devices::Geolocation::Geopath & value) const
{
    check_hresult(WINRT_SHIM(IMapPolygon)->put_Path(get_abi(value)));
}

template <typename D> Windows::UI::Color impl_IMapPolygon<D>::StrokeColor() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IMapPolygon)->get_StrokeColor(put_abi(value)));
    return value;
}

template <typename D> void impl_IMapPolygon<D>::StrokeColor(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(IMapPolygon)->put_StrokeColor(get_abi(value)));
}

template <typename D> double impl_IMapPolygon<D>::StrokeThickness() const
{
    double value {};
    check_hresult(WINRT_SHIM(IMapPolygon)->get_StrokeThickness(&value));
    return value;
}

template <typename D> void impl_IMapPolygon<D>::StrokeThickness(double value) const
{
    check_hresult(WINRT_SHIM(IMapPolygon)->put_StrokeThickness(value));
}

template <typename D> bool impl_IMapPolygon<D>::StrokeDashed() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMapPolygon)->get_StrokeDashed(&value));
    return value;
}

template <typename D> void impl_IMapPolygon<D>::StrokeDashed(bool value) const
{
    check_hresult(WINRT_SHIM(IMapPolygon)->put_StrokeDashed(value));
}

template <typename D> Windows::UI::Color impl_IMapPolygon<D>::FillColor() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IMapPolygon)->get_FillColor(put_abi(value)));
    return value;
}

template <typename D> void impl_IMapPolygon<D>::FillColor(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(IMapPolygon)->put_FillColor(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapPolygonStatics<D>::PathProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapPolygonStatics)->get_PathProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapPolygonStatics<D>::StrokeThicknessProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapPolygonStatics)->get_StrokeThicknessProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapPolygonStatics<D>::StrokeDashedProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapPolygonStatics)->get_StrokeDashedProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Devices::Geolocation::Geopath> impl_IMapPolygon2<D>::Paths() const
{
    Windows::Foundation::Collections::IVector<Windows::Devices::Geolocation::Geopath> value;
    check_hresult(WINRT_SHIM(IMapPolygon2)->get_Paths(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geopath impl_IMapPolyline<D>::Path() const
{
    Windows::Devices::Geolocation::Geopath value { nullptr };
    check_hresult(WINRT_SHIM(IMapPolyline)->get_Path(put_abi(value)));
    return value;
}

template <typename D> void impl_IMapPolyline<D>::Path(const Windows::Devices::Geolocation::Geopath & value) const
{
    check_hresult(WINRT_SHIM(IMapPolyline)->put_Path(get_abi(value)));
}

template <typename D> Windows::UI::Color impl_IMapPolyline<D>::StrokeColor() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IMapPolyline)->get_StrokeColor(put_abi(value)));
    return value;
}

template <typename D> void impl_IMapPolyline<D>::StrokeColor(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(IMapPolyline)->put_StrokeColor(get_abi(value)));
}

template <typename D> double impl_IMapPolyline<D>::StrokeThickness() const
{
    double value {};
    check_hresult(WINRT_SHIM(IMapPolyline)->get_StrokeThickness(&value));
    return value;
}

template <typename D> void impl_IMapPolyline<D>::StrokeThickness(double value) const
{
    check_hresult(WINRT_SHIM(IMapPolyline)->put_StrokeThickness(value));
}

template <typename D> bool impl_IMapPolyline<D>::StrokeDashed() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMapPolyline)->get_StrokeDashed(&value));
    return value;
}

template <typename D> void impl_IMapPolyline<D>::StrokeDashed(bool value) const
{
    check_hresult(WINRT_SHIM(IMapPolyline)->put_StrokeDashed(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapPolylineStatics<D>::PathProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapPolylineStatics)->get_PathProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapPolylineStatics<D>::StrokeDashedProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapPolylineStatics)->get_StrokeDashedProperty(put_abi(value)));
    return value;
}

template <typename D> bool impl_IStreetsideExperience<D>::AddressTextVisible() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStreetsideExperience)->get_AddressTextVisible(&value));
    return value;
}

template <typename D> void impl_IStreetsideExperience<D>::AddressTextVisible(bool value) const
{
    check_hresult(WINRT_SHIM(IStreetsideExperience)->put_AddressTextVisible(value));
}

template <typename D> bool impl_IStreetsideExperience<D>::CursorVisible() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStreetsideExperience)->get_CursorVisible(&value));
    return value;
}

template <typename D> void impl_IStreetsideExperience<D>::CursorVisible(bool value) const
{
    check_hresult(WINRT_SHIM(IStreetsideExperience)->put_CursorVisible(value));
}

template <typename D> bool impl_IStreetsideExperience<D>::OverviewMapVisible() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStreetsideExperience)->get_OverviewMapVisible(&value));
    return value;
}

template <typename D> void impl_IStreetsideExperience<D>::OverviewMapVisible(bool value) const
{
    check_hresult(WINRT_SHIM(IStreetsideExperience)->put_OverviewMapVisible(value));
}

template <typename D> bool impl_IStreetsideExperience<D>::StreetLabelsVisible() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStreetsideExperience)->get_StreetLabelsVisible(&value));
    return value;
}

template <typename D> void impl_IStreetsideExperience<D>::StreetLabelsVisible(bool value) const
{
    check_hresult(WINRT_SHIM(IStreetsideExperience)->put_StreetLabelsVisible(value));
}

template <typename D> bool impl_IStreetsideExperience<D>::ExitButtonVisible() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStreetsideExperience)->get_ExitButtonVisible(&value));
    return value;
}

template <typename D> void impl_IStreetsideExperience<D>::ExitButtonVisible(bool value) const
{
    check_hresult(WINRT_SHIM(IStreetsideExperience)->put_ExitButtonVisible(value));
}

template <typename D> bool impl_IStreetsideExperience<D>::ZoomButtonsVisible() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStreetsideExperience)->get_ZoomButtonsVisible(&value));
    return value;
}

template <typename D> void impl_IStreetsideExperience<D>::ZoomButtonsVisible(bool value) const
{
    check_hresult(WINRT_SHIM(IStreetsideExperience)->put_ZoomButtonsVisible(value));
}

template <typename D> Windows::UI::Xaml::Controls::Maps::StreetsideExperience impl_IStreetsideExperienceFactory<D>::CreateInstanceWithPanorama(const Windows::UI::Xaml::Controls::Maps::StreetsidePanorama & panorama) const
{
    Windows::UI::Xaml::Controls::Maps::StreetsideExperience instance { nullptr };
    check_hresult(WINRT_SHIM(IStreetsideExperienceFactory)->abi_CreateInstanceWithPanorama(get_abi(panorama), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::StreetsideExperience impl_IStreetsideExperienceFactory<D>::CreateInstanceWithPanoramaHeadingPitchAndFieldOfView(const Windows::UI::Xaml::Controls::Maps::StreetsidePanorama & panorama, double headingInDegrees, double pitchInDegrees, double fieldOfViewInDegrees) const
{
    Windows::UI::Xaml::Controls::Maps::StreetsideExperience instance { nullptr };
    check_hresult(WINRT_SHIM(IStreetsideExperienceFactory)->abi_CreateInstanceWithPanoramaHeadingPitchAndFieldOfView(get_abi(panorama), headingInDegrees, pitchInDegrees, fieldOfViewInDegrees, put_abi(instance)));
    return instance;
}

template <typename D> Windows::Devices::Geolocation::Geopoint impl_IMapControl<D>::Center() const
{
    Windows::Devices::Geolocation::Geopoint value { nullptr };
    check_hresult(WINRT_SHIM(IMapControl)->get_Center(put_abi(value)));
    return value;
}

template <typename D> void impl_IMapControl<D>::Center(const Windows::Devices::Geolocation::Geopoint & value) const
{
    check_hresult(WINRT_SHIM(IMapControl)->put_Center(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::UI::Xaml::DependencyObject> impl_IMapControl<D>::Children() const
{
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::DependencyObject> value;
    check_hresult(WINRT_SHIM(IMapControl)->get_Children(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapColorScheme impl_IMapControl<D>::ColorScheme() const
{
    Windows::UI::Xaml::Controls::Maps::MapColorScheme value {};
    check_hresult(WINRT_SHIM(IMapControl)->get_ColorScheme(&value));
    return value;
}

template <typename D> void impl_IMapControl<D>::ColorScheme(Windows::UI::Xaml::Controls::Maps::MapColorScheme value) const
{
    check_hresult(WINRT_SHIM(IMapControl)->put_ColorScheme(value));
}

template <typename D> double impl_IMapControl<D>::DesiredPitch() const
{
    double value {};
    check_hresult(WINRT_SHIM(IMapControl)->get_DesiredPitch(&value));
    return value;
}

template <typename D> void impl_IMapControl<D>::DesiredPitch(double value) const
{
    check_hresult(WINRT_SHIM(IMapControl)->put_DesiredPitch(value));
}

template <typename D> double impl_IMapControl<D>::Heading() const
{
    double value {};
    check_hresult(WINRT_SHIM(IMapControl)->get_Heading(&value));
    return value;
}

template <typename D> void impl_IMapControl<D>::Heading(double value) const
{
    check_hresult(WINRT_SHIM(IMapControl)->put_Heading(value));
}

template <typename D> bool impl_IMapControl<D>::LandmarksVisible() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMapControl)->get_LandmarksVisible(&value));
    return value;
}

template <typename D> void impl_IMapControl<D>::LandmarksVisible(bool value) const
{
    check_hresult(WINRT_SHIM(IMapControl)->put_LandmarksVisible(value));
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapLoadingStatus impl_IMapControl<D>::LoadingStatus() const
{
    Windows::UI::Xaml::Controls::Maps::MapLoadingStatus value {};
    check_hresult(WINRT_SHIM(IMapControl)->get_LoadingStatus(&value));
    return value;
}

template <typename D> hstring impl_IMapControl<D>::MapServiceToken() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMapControl)->get_MapServiceToken(put_abi(value)));
    return value;
}

template <typename D> void impl_IMapControl<D>::MapServiceToken(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IMapControl)->put_MapServiceToken(get_abi(value)));
}

template <typename D> double impl_IMapControl<D>::MaxZoomLevel() const
{
    double value {};
    check_hresult(WINRT_SHIM(IMapControl)->get_MaxZoomLevel(&value));
    return value;
}

template <typename D> double impl_IMapControl<D>::MinZoomLevel() const
{
    double value {};
    check_hresult(WINRT_SHIM(IMapControl)->get_MinZoomLevel(&value));
    return value;
}

template <typename D> bool impl_IMapControl<D>::PedestrianFeaturesVisible() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMapControl)->get_PedestrianFeaturesVisible(&value));
    return value;
}

template <typename D> void impl_IMapControl<D>::PedestrianFeaturesVisible(bool value) const
{
    check_hresult(WINRT_SHIM(IMapControl)->put_PedestrianFeaturesVisible(value));
}

template <typename D> double impl_IMapControl<D>::Pitch() const
{
    double value {};
    check_hresult(WINRT_SHIM(IMapControl)->get_Pitch(&value));
    return value;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapStyle impl_IMapControl<D>::Style() const
{
    Windows::UI::Xaml::Controls::Maps::MapStyle value {};
    check_hresult(WINRT_SHIM(IMapControl)->get_Style(&value));
    return value;
}

template <typename D> void impl_IMapControl<D>::Style(Windows::UI::Xaml::Controls::Maps::MapStyle value) const
{
    check_hresult(WINRT_SHIM(IMapControl)->put_Style(value));
}

template <typename D> bool impl_IMapControl<D>::TrafficFlowVisible() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMapControl)->get_TrafficFlowVisible(&value));
    return value;
}

template <typename D> void impl_IMapControl<D>::TrafficFlowVisible(bool value) const
{
    check_hresult(WINRT_SHIM(IMapControl)->put_TrafficFlowVisible(value));
}

template <typename D> Windows::Foundation::Point impl_IMapControl<D>::TransformOrigin() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(IMapControl)->get_TransformOrigin(put_abi(value)));
    return value;
}

template <typename D> void impl_IMapControl<D>::TransformOrigin(const Windows::Foundation::Point & value) const
{
    check_hresult(WINRT_SHIM(IMapControl)->put_TransformOrigin(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapWatermarkMode impl_IMapControl<D>::WatermarkMode() const
{
    Windows::UI::Xaml::Controls::Maps::MapWatermarkMode value {};
    check_hresult(WINRT_SHIM(IMapControl)->get_WatermarkMode(&value));
    return value;
}

template <typename D> void impl_IMapControl<D>::WatermarkMode(Windows::UI::Xaml::Controls::Maps::MapWatermarkMode value) const
{
    check_hresult(WINRT_SHIM(IMapControl)->put_WatermarkMode(value));
}

template <typename D> double impl_IMapControl<D>::ZoomLevel() const
{
    double value {};
    check_hresult(WINRT_SHIM(IMapControl)->get_ZoomLevel(&value));
    return value;
}

template <typename D> void impl_IMapControl<D>::ZoomLevel(double value) const
{
    check_hresult(WINRT_SHIM(IMapControl)->put_ZoomLevel(value));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::Maps::MapElement> impl_IMapControl<D>::MapElements() const
{
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::Maps::MapElement> value;
    check_hresult(WINRT_SHIM(IMapControl)->get_MapElements(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::Maps::MapRouteView> impl_IMapControl<D>::Routes() const
{
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::Maps::MapRouteView> value;
    check_hresult(WINRT_SHIM(IMapControl)->get_Routes(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::Maps::MapTileSource> impl_IMapControl<D>::TileSources() const
{
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::Maps::MapTileSource> value;
    check_hresult(WINRT_SHIM(IMapControl)->get_TileSources(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IMapControl<D>::CenterChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMapControl)->add_CenterChanged(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMapControl> impl_IMapControl<D>::CenterChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable> & value) const
{
    return impl::make_event_revoker<D, IMapControl>(this, &ABI::Windows::UI::Xaml::Controls::Maps::IMapControl::remove_CenterChanged, CenterChanged(value));
}

template <typename D> void impl_IMapControl<D>::CenterChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IMapControl)->remove_CenterChanged(token));
}

template <typename D> event_token impl_IMapControl<D>::HeadingChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMapControl)->add_HeadingChanged(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMapControl> impl_IMapControl<D>::HeadingChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable> & value) const
{
    return impl::make_event_revoker<D, IMapControl>(this, &ABI::Windows::UI::Xaml::Controls::Maps::IMapControl::remove_HeadingChanged, HeadingChanged(value));
}

template <typename D> void impl_IMapControl<D>::HeadingChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IMapControl)->remove_HeadingChanged(token));
}

template <typename D> event_token impl_IMapControl<D>::LoadingStatusChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMapControl)->add_LoadingStatusChanged(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMapControl> impl_IMapControl<D>::LoadingStatusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable> & value) const
{
    return impl::make_event_revoker<D, IMapControl>(this, &ABI::Windows::UI::Xaml::Controls::Maps::IMapControl::remove_LoadingStatusChanged, LoadingStatusChanged(value));
}

template <typename D> void impl_IMapControl<D>::LoadingStatusChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IMapControl)->remove_LoadingStatusChanged(token));
}

template <typename D> event_token impl_IMapControl<D>::MapDoubleTapped(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapInputEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMapControl)->add_MapDoubleTapped(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMapControl> impl_IMapControl<D>::MapDoubleTapped(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapInputEventArgs> & value) const
{
    return impl::make_event_revoker<D, IMapControl>(this, &ABI::Windows::UI::Xaml::Controls::Maps::IMapControl::remove_MapDoubleTapped, MapDoubleTapped(value));
}

template <typename D> void impl_IMapControl<D>::MapDoubleTapped(event_token token) const
{
    check_hresult(WINRT_SHIM(IMapControl)->remove_MapDoubleTapped(token));
}

template <typename D> event_token impl_IMapControl<D>::MapHolding(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapInputEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMapControl)->add_MapHolding(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMapControl> impl_IMapControl<D>::MapHolding(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapInputEventArgs> & value) const
{
    return impl::make_event_revoker<D, IMapControl>(this, &ABI::Windows::UI::Xaml::Controls::Maps::IMapControl::remove_MapHolding, MapHolding(value));
}

template <typename D> void impl_IMapControl<D>::MapHolding(event_token token) const
{
    check_hresult(WINRT_SHIM(IMapControl)->remove_MapHolding(token));
}

template <typename D> event_token impl_IMapControl<D>::MapTapped(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapInputEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMapControl)->add_MapTapped(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMapControl> impl_IMapControl<D>::MapTapped(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapInputEventArgs> & value) const
{
    return impl::make_event_revoker<D, IMapControl>(this, &ABI::Windows::UI::Xaml::Controls::Maps::IMapControl::remove_MapTapped, MapTapped(value));
}

template <typename D> void impl_IMapControl<D>::MapTapped(event_token token) const
{
    check_hresult(WINRT_SHIM(IMapControl)->remove_MapTapped(token));
}

template <typename D> event_token impl_IMapControl<D>::PitchChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMapControl)->add_PitchChanged(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMapControl> impl_IMapControl<D>::PitchChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable> & value) const
{
    return impl::make_event_revoker<D, IMapControl>(this, &ABI::Windows::UI::Xaml::Controls::Maps::IMapControl::remove_PitchChanged, PitchChanged(value));
}

template <typename D> void impl_IMapControl<D>::PitchChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IMapControl)->remove_PitchChanged(token));
}

template <typename D> event_token impl_IMapControl<D>::TransformOriginChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMapControl)->add_TransformOriginChanged(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMapControl> impl_IMapControl<D>::TransformOriginChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable> & value) const
{
    return impl::make_event_revoker<D, IMapControl>(this, &ABI::Windows::UI::Xaml::Controls::Maps::IMapControl::remove_TransformOriginChanged, TransformOriginChanged(value));
}

template <typename D> void impl_IMapControl<D>::TransformOriginChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IMapControl)->remove_TransformOriginChanged(token));
}

template <typename D> event_token impl_IMapControl<D>::ZoomLevelChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMapControl)->add_ZoomLevelChanged(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMapControl> impl_IMapControl<D>::ZoomLevelChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::Foundation::IInspectable> & value) const
{
    return impl::make_event_revoker<D, IMapControl>(this, &ABI::Windows::UI::Xaml::Controls::Maps::IMapControl::remove_ZoomLevelChanged, ZoomLevelChanged(value));
}

template <typename D> void impl_IMapControl<D>::ZoomLevelChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IMapControl)->remove_ZoomLevelChanged(token));
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Controls::Maps::MapElement> impl_IMapControl<D>::FindMapElementsAtOffset(const Windows::Foundation::Point & offset) const
{
    Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Controls::Maps::MapElement> returnValue;
    check_hresult(WINRT_SHIM(IMapControl)->abi_FindMapElementsAtOffset(get_abi(offset), put_abi(returnValue)));
    return returnValue;
}

template <typename D> void impl_IMapControl<D>::GetLocationFromOffset(const Windows::Foundation::Point & offset, Windows::Devices::Geolocation::Geopoint & location) const
{
    check_hresult(WINRT_SHIM(IMapControl)->abi_GetLocationFromOffset(get_abi(offset), put_abi(location)));
}

template <typename D> void impl_IMapControl<D>::GetOffsetFromLocation(const Windows::Devices::Geolocation::Geopoint & location, Windows::Foundation::Point & offset) const
{
    check_hresult(WINRT_SHIM(IMapControl)->abi_GetOffsetFromLocation(get_abi(location), put_abi(offset)));
}

template <typename D> void impl_IMapControl<D>::IsLocationInView(const Windows::Devices::Geolocation::Geopoint & location, bool & isInView) const
{
    check_hresult(WINRT_SHIM(IMapControl)->abi_IsLocationInView(get_abi(location), &isInView));
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IMapControl<D>::TrySetViewBoundsAsync(const Windows::Devices::Geolocation::GeoboundingBox & bounds, const optional<Windows::UI::Xaml::Thickness> & margin, Windows::UI::Xaml::Controls::Maps::MapAnimationKind animation) const
{
    Windows::Foundation::IAsyncOperation<bool> returnValue;
    check_hresult(WINRT_SHIM(IMapControl)->abi_TrySetViewBoundsAsync(get_abi(bounds), get_abi(margin), animation, put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IMapControl<D>::TrySetViewAsync(const Windows::Devices::Geolocation::Geopoint & center) const
{
    Windows::Foundation::IAsyncOperation<bool> returnValue;
    check_hresult(WINRT_SHIM(IMapControl)->abi_TrySetViewWithCenterAsync(get_abi(center), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IMapControl<D>::TrySetViewAsync(const Windows::Devices::Geolocation::Geopoint & center, const optional<double> & zoomLevel) const
{
    Windows::Foundation::IAsyncOperation<bool> returnValue;
    check_hresult(WINRT_SHIM(IMapControl)->abi_TrySetViewWithCenterAndZoomAsync(get_abi(center), get_abi(zoomLevel), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IMapControl<D>::TrySetViewAsync(const Windows::Devices::Geolocation::Geopoint & center, const optional<double> & zoomLevel, const optional<double> & heading, const optional<double> & desiredPitch) const
{
    Windows::Foundation::IAsyncOperation<bool> returnValue;
    check_hresult(WINRT_SHIM(IMapControl)->abi_TrySetViewWithCenterZoomHeadingAndPitchAsync(get_abi(center), get_abi(zoomLevel), get_abi(heading), get_abi(desiredPitch), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IMapControl<D>::TrySetViewAsync(const Windows::Devices::Geolocation::Geopoint & center, const optional<double> & zoomLevel, const optional<double> & heading, const optional<double> & desiredPitch, Windows::UI::Xaml::Controls::Maps::MapAnimationKind animation) const
{
    Windows::Foundation::IAsyncOperation<bool> returnValue;
    check_hresult(WINRT_SHIM(IMapControl)->abi_TrySetViewWithCenterZoomHeadingPitchAndAnimationAsync(get_abi(center), get_abi(zoomLevel), get_abi(heading), get_abi(desiredPitch), animation, put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapControlStatics<D>::CenterProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapControlStatics)->get_CenterProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapControlStatics<D>::ChildrenProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapControlStatics)->get_ChildrenProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapControlStatics<D>::ColorSchemeProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapControlStatics)->get_ColorSchemeProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapControlStatics<D>::DesiredPitchProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapControlStatics)->get_DesiredPitchProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapControlStatics<D>::HeadingProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapControlStatics)->get_HeadingProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapControlStatics<D>::LandmarksVisibleProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapControlStatics)->get_LandmarksVisibleProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapControlStatics<D>::LoadingStatusProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapControlStatics)->get_LoadingStatusProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapControlStatics<D>::MapServiceTokenProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapControlStatics)->get_MapServiceTokenProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapControlStatics<D>::PedestrianFeaturesVisibleProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapControlStatics)->get_PedestrianFeaturesVisibleProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapControlStatics<D>::PitchProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapControlStatics)->get_PitchProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapControlStatics<D>::StyleProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapControlStatics)->get_StyleProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapControlStatics<D>::TrafficFlowVisibleProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapControlStatics)->get_TrafficFlowVisibleProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapControlStatics<D>::TransformOriginProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapControlStatics)->get_TransformOriginProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapControlStatics<D>::WatermarkModeProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapControlStatics)->get_WatermarkModeProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapControlStatics<D>::ZoomLevelProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapControlStatics)->get_ZoomLevelProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapControlStatics<D>::MapElementsProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapControlStatics)->get_MapElementsProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapControlStatics<D>::RoutesProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapControlStatics)->get_RoutesProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapControlStatics<D>::TileSourcesProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapControlStatics)->get_TileSourcesProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapControlStatics<D>::LocationProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapControlStatics)->get_LocationProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geopoint impl_IMapControlStatics<D>::GetLocation(const Windows::UI::Xaml::DependencyObject & element) const
{
    Windows::Devices::Geolocation::Geopoint value { nullptr };
    check_hresult(WINRT_SHIM(IMapControlStatics)->abi_GetLocation(get_abi(element), put_abi(value)));
    return value;
}

template <typename D> void impl_IMapControlStatics<D>::SetLocation(const Windows::UI::Xaml::DependencyObject & element, const Windows::Devices::Geolocation::Geopoint & value) const
{
    check_hresult(WINRT_SHIM(IMapControlStatics)->abi_SetLocation(get_abi(element), get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapControlStatics<D>::NormalizedAnchorPointProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapControlStatics)->get_NormalizedAnchorPointProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Point impl_IMapControlStatics<D>::GetNormalizedAnchorPoint(const Windows::UI::Xaml::DependencyObject & element) const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(IMapControlStatics)->abi_GetNormalizedAnchorPoint(get_abi(element), put_abi(value)));
    return value;
}

template <typename D> void impl_IMapControlStatics<D>::SetNormalizedAnchorPoint(const Windows::UI::Xaml::DependencyObject & element, const Windows::Foundation::Point & value) const
{
    check_hresult(WINRT_SHIM(IMapControlStatics)->abi_SetNormalizedAnchorPoint(get_abi(element), get_abi(value)));
}

template <typename D> bool impl_IMapControl2<D>::BusinessLandmarksVisible() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMapControl2)->get_BusinessLandmarksVisible(&value));
    return value;
}

template <typename D> void impl_IMapControl2<D>::BusinessLandmarksVisible(bool value) const
{
    check_hresult(WINRT_SHIM(IMapControl2)->put_BusinessLandmarksVisible(value));
}

template <typename D> bool impl_IMapControl2<D>::TransitFeaturesVisible() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMapControl2)->get_TransitFeaturesVisible(&value));
    return value;
}

template <typename D> void impl_IMapControl2<D>::TransitFeaturesVisible(bool value) const
{
    check_hresult(WINRT_SHIM(IMapControl2)->put_TransitFeaturesVisible(value));
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapPanInteractionMode impl_IMapControl2<D>::PanInteractionMode() const
{
    Windows::UI::Xaml::Controls::Maps::MapPanInteractionMode value {};
    check_hresult(WINRT_SHIM(IMapControl2)->get_PanInteractionMode(&value));
    return value;
}

template <typename D> void impl_IMapControl2<D>::PanInteractionMode(Windows::UI::Xaml::Controls::Maps::MapPanInteractionMode value) const
{
    check_hresult(WINRT_SHIM(IMapControl2)->put_PanInteractionMode(value));
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapInteractionMode impl_IMapControl2<D>::RotateInteractionMode() const
{
    Windows::UI::Xaml::Controls::Maps::MapInteractionMode value {};
    check_hresult(WINRT_SHIM(IMapControl2)->get_RotateInteractionMode(&value));
    return value;
}

template <typename D> void impl_IMapControl2<D>::RotateInteractionMode(Windows::UI::Xaml::Controls::Maps::MapInteractionMode value) const
{
    check_hresult(WINRT_SHIM(IMapControl2)->put_RotateInteractionMode(value));
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapInteractionMode impl_IMapControl2<D>::TiltInteractionMode() const
{
    Windows::UI::Xaml::Controls::Maps::MapInteractionMode value {};
    check_hresult(WINRT_SHIM(IMapControl2)->get_TiltInteractionMode(&value));
    return value;
}

template <typename D> void impl_IMapControl2<D>::TiltInteractionMode(Windows::UI::Xaml::Controls::Maps::MapInteractionMode value) const
{
    check_hresult(WINRT_SHIM(IMapControl2)->put_TiltInteractionMode(value));
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapInteractionMode impl_IMapControl2<D>::ZoomInteractionMode() const
{
    Windows::UI::Xaml::Controls::Maps::MapInteractionMode value {};
    check_hresult(WINRT_SHIM(IMapControl2)->get_ZoomInteractionMode(&value));
    return value;
}

template <typename D> void impl_IMapControl2<D>::ZoomInteractionMode(Windows::UI::Xaml::Controls::Maps::MapInteractionMode value) const
{
    check_hresult(WINRT_SHIM(IMapControl2)->put_ZoomInteractionMode(value));
}

template <typename D> bool impl_IMapControl2<D>::Is3DSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMapControl2)->get_Is3DSupported(&value));
    return value;
}

template <typename D> bool impl_IMapControl2<D>::IsStreetsideSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMapControl2)->get_IsStreetsideSupported(&value));
    return value;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapScene impl_IMapControl2<D>::Scene() const
{
    Windows::UI::Xaml::Controls::Maps::MapScene value { nullptr };
    check_hresult(WINRT_SHIM(IMapControl2)->get_Scene(put_abi(value)));
    return value;
}

template <typename D> void impl_IMapControl2<D>::Scene(const Windows::UI::Xaml::Controls::Maps::MapScene & value) const
{
    check_hresult(WINRT_SHIM(IMapControl2)->put_Scene(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapCamera impl_IMapControl2<D>::ActualCamera() const
{
    Windows::UI::Xaml::Controls::Maps::MapCamera value { nullptr };
    check_hresult(WINRT_SHIM(IMapControl2)->get_ActualCamera(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapCamera impl_IMapControl2<D>::TargetCamera() const
{
    Windows::UI::Xaml::Controls::Maps::MapCamera value { nullptr };
    check_hresult(WINRT_SHIM(IMapControl2)->get_TargetCamera(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapCustomExperience impl_IMapControl2<D>::CustomExperience() const
{
    Windows::UI::Xaml::Controls::Maps::MapCustomExperience value { nullptr };
    check_hresult(WINRT_SHIM(IMapControl2)->get_CustomExperience(put_abi(value)));
    return value;
}

template <typename D> void impl_IMapControl2<D>::CustomExperience(const Windows::UI::Xaml::Controls::Maps::MapCustomExperience & value) const
{
    check_hresult(WINRT_SHIM(IMapControl2)->put_CustomExperience(get_abi(value)));
}

template <typename D> event_token impl_IMapControl2<D>::MapElementClick(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapElementClickEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMapControl2)->add_MapElementClick(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMapControl2> impl_IMapControl2<D>::MapElementClick(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapElementClickEventArgs> & value) const
{
    return impl::make_event_revoker<D, IMapControl2>(this, &ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2::remove_MapElementClick, MapElementClick(value));
}

template <typename D> void impl_IMapControl2<D>::MapElementClick(event_token token) const
{
    check_hresult(WINRT_SHIM(IMapControl2)->remove_MapElementClick(token));
}

template <typename D> event_token impl_IMapControl2<D>::MapElementPointerEntered(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapElementPointerEnteredEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMapControl2)->add_MapElementPointerEntered(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMapControl2> impl_IMapControl2<D>::MapElementPointerEntered(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapElementPointerEnteredEventArgs> & value) const
{
    return impl::make_event_revoker<D, IMapControl2>(this, &ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2::remove_MapElementPointerEntered, MapElementPointerEntered(value));
}

template <typename D> void impl_IMapControl2<D>::MapElementPointerEntered(event_token token) const
{
    check_hresult(WINRT_SHIM(IMapControl2)->remove_MapElementPointerEntered(token));
}

template <typename D> event_token impl_IMapControl2<D>::MapElementPointerExited(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapElementPointerExitedEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMapControl2)->add_MapElementPointerExited(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMapControl2> impl_IMapControl2<D>::MapElementPointerExited(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapElementPointerExitedEventArgs> & value) const
{
    return impl::make_event_revoker<D, IMapControl2>(this, &ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2::remove_MapElementPointerExited, MapElementPointerExited(value));
}

template <typename D> void impl_IMapControl2<D>::MapElementPointerExited(event_token token) const
{
    check_hresult(WINRT_SHIM(IMapControl2)->remove_MapElementPointerExited(token));
}

template <typename D> event_token impl_IMapControl2<D>::ActualCameraChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapActualCameraChangedEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMapControl2)->add_ActualCameraChanged(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMapControl2> impl_IMapControl2<D>::ActualCameraChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapActualCameraChangedEventArgs> & value) const
{
    return impl::make_event_revoker<D, IMapControl2>(this, &ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2::remove_ActualCameraChanged, ActualCameraChanged(value));
}

template <typename D> void impl_IMapControl2<D>::ActualCameraChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IMapControl2)->remove_ActualCameraChanged(token));
}

template <typename D> event_token impl_IMapControl2<D>::ActualCameraChanging(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapActualCameraChangingEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMapControl2)->add_ActualCameraChanging(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMapControl2> impl_IMapControl2<D>::ActualCameraChanging(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapActualCameraChangingEventArgs> & value) const
{
    return impl::make_event_revoker<D, IMapControl2>(this, &ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2::remove_ActualCameraChanging, ActualCameraChanging(value));
}

template <typename D> void impl_IMapControl2<D>::ActualCameraChanging(event_token token) const
{
    check_hresult(WINRT_SHIM(IMapControl2)->remove_ActualCameraChanging(token));
}

template <typename D> event_token impl_IMapControl2<D>::TargetCameraChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapTargetCameraChangedEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMapControl2)->add_TargetCameraChanged(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMapControl2> impl_IMapControl2<D>::TargetCameraChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapTargetCameraChangedEventArgs> & value) const
{
    return impl::make_event_revoker<D, IMapControl2>(this, &ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2::remove_TargetCameraChanged, TargetCameraChanged(value));
}

template <typename D> void impl_IMapControl2<D>::TargetCameraChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IMapControl2)->remove_TargetCameraChanged(token));
}

template <typename D> event_token impl_IMapControl2<D>::CustomExperienceChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapCustomExperienceChangedEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMapControl2)->add_CustomExperienceChanged(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMapControl2> impl_IMapControl2<D>::CustomExperienceChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapCustomExperienceChangedEventArgs> & value) const
{
    return impl::make_event_revoker<D, IMapControl2>(this, &ABI::Windows::UI::Xaml::Controls::Maps::IMapControl2::remove_CustomExperienceChanged, CustomExperienceChanged(value));
}

template <typename D> void impl_IMapControl2<D>::CustomExperienceChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IMapControl2)->remove_CustomExperienceChanged(token));
}

template <typename D> void impl_IMapControl2<D>::StartContinuousRotate(double rateInDegreesPerSecond) const
{
    check_hresult(WINRT_SHIM(IMapControl2)->abi_StartContinuousRotate(rateInDegreesPerSecond));
}

template <typename D> void impl_IMapControl2<D>::StopContinuousRotate() const
{
    check_hresult(WINRT_SHIM(IMapControl2)->abi_StopContinuousRotate());
}

template <typename D> void impl_IMapControl2<D>::StartContinuousTilt(double rateInDegreesPerSecond) const
{
    check_hresult(WINRT_SHIM(IMapControl2)->abi_StartContinuousTilt(rateInDegreesPerSecond));
}

template <typename D> void impl_IMapControl2<D>::StopContinuousTilt() const
{
    check_hresult(WINRT_SHIM(IMapControl2)->abi_StopContinuousTilt());
}

template <typename D> void impl_IMapControl2<D>::StartContinuousZoom(double rateOfChangePerSecond) const
{
    check_hresult(WINRT_SHIM(IMapControl2)->abi_StartContinuousZoom(rateOfChangePerSecond));
}

template <typename D> void impl_IMapControl2<D>::StopContinuousZoom() const
{
    check_hresult(WINRT_SHIM(IMapControl2)->abi_StopContinuousZoom());
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IMapControl2<D>::TryRotateAsync(double degrees) const
{
    Windows::Foundation::IAsyncOperation<bool> returnValue;
    check_hresult(WINRT_SHIM(IMapControl2)->abi_TryRotateAsync(degrees, put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IMapControl2<D>::TryRotateToAsync(double angleInDegrees) const
{
    Windows::Foundation::IAsyncOperation<bool> returnValue;
    check_hresult(WINRT_SHIM(IMapControl2)->abi_TryRotateToAsync(angleInDegrees, put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IMapControl2<D>::TryTiltAsync(double degrees) const
{
    Windows::Foundation::IAsyncOperation<bool> returnValue;
    check_hresult(WINRT_SHIM(IMapControl2)->abi_TryTiltAsync(degrees, put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IMapControl2<D>::TryTiltToAsync(double angleInDegrees) const
{
    Windows::Foundation::IAsyncOperation<bool> returnValue;
    check_hresult(WINRT_SHIM(IMapControl2)->abi_TryTiltToAsync(angleInDegrees, put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IMapControl2<D>::TryZoomInAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> returnValue;
    check_hresult(WINRT_SHIM(IMapControl2)->abi_TryZoomInAsync(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IMapControl2<D>::TryZoomOutAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> returnValue;
    check_hresult(WINRT_SHIM(IMapControl2)->abi_TryZoomOutAsync(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IMapControl2<D>::TryZoomToAsync(double zoomLevel) const
{
    Windows::Foundation::IAsyncOperation<bool> returnValue;
    check_hresult(WINRT_SHIM(IMapControl2)->abi_TryZoomToAsync(zoomLevel, put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IMapControl2<D>::TrySetSceneAsync(const Windows::UI::Xaml::Controls::Maps::MapScene & scene) const
{
    Windows::Foundation::IAsyncOperation<bool> returnValue;
    check_hresult(WINRT_SHIM(IMapControl2)->abi_TrySetSceneAsync(get_abi(scene), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IMapControl2<D>::TrySetSceneAsync(const Windows::UI::Xaml::Controls::Maps::MapScene & scene, Windows::UI::Xaml::Controls::Maps::MapAnimationKind animationKind) const
{
    Windows::Foundation::IAsyncOperation<bool> returnValue;
    check_hresult(WINRT_SHIM(IMapControl2)->abi_TrySetSceneWithAnimationAsync(get_abi(scene), animationKind, put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapControlStatics2<D>::BusinessLandmarksVisibleProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapControlStatics2)->get_BusinessLandmarksVisibleProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapControlStatics2<D>::TransitFeaturesVisibleProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapControlStatics2)->get_TransitFeaturesVisibleProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapControlStatics2<D>::PanInteractionModeProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapControlStatics2)->get_PanInteractionModeProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapControlStatics2<D>::RotateInteractionModeProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapControlStatics2)->get_RotateInteractionModeProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapControlStatics2<D>::TiltInteractionModeProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapControlStatics2)->get_TiltInteractionModeProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapControlStatics2<D>::ZoomInteractionModeProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapControlStatics2)->get_ZoomInteractionModeProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapControlStatics2<D>::Is3DSupportedProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapControlStatics2)->get_Is3DSupportedProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapControlStatics2<D>::IsStreetsideSupportedProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapControlStatics2)->get_IsStreetsideSupportedProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapControlStatics2<D>::SceneProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapControlStatics2)->get_SceneProperty(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IMapControl3<D>::MapRightTapped(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapRightTappedEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMapControl3)->add_MapRightTapped(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMapControl3> impl_IMapControl3<D>::MapRightTapped(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapRightTappedEventArgs> & value) const
{
    return impl::make_event_revoker<D, IMapControl3>(this, &ABI::Windows::UI::Xaml::Controls::Maps::IMapControl3::remove_MapRightTapped, MapRightTapped(value));
}

template <typename D> void impl_IMapControl3<D>::MapRightTapped(event_token token) const
{
    check_hresult(WINRT_SHIM(IMapControl3)->remove_MapRightTapped(token));
}

template <typename D> bool impl_IMapControl4<D>::BusinessLandmarksEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMapControl4)->get_BusinessLandmarksEnabled(&value));
    return value;
}

template <typename D> void impl_IMapControl4<D>::BusinessLandmarksEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IMapControl4)->put_BusinessLandmarksEnabled(value));
}

template <typename D> bool impl_IMapControl4<D>::TransitFeaturesEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMapControl4)->get_TransitFeaturesEnabled(&value));
    return value;
}

template <typename D> void impl_IMapControl4<D>::TransitFeaturesEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IMapControl4)->put_TransitFeaturesEnabled(value));
}

template <typename D> Windows::Devices::Geolocation::Geopath impl_IMapControl4<D>::GetVisibleRegion(Windows::UI::Xaml::Controls::Maps::MapVisibleRegionKind region) const
{
    Windows::Devices::Geolocation::Geopath returnValue { nullptr };
    check_hresult(WINRT_SHIM(IMapControl4)->abi_GetVisibleRegion(region, put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapControlStatics4<D>::BusinessLandmarksEnabledProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapControlStatics4)->get_BusinessLandmarksEnabledProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IMapControlStatics4<D>::TransitFeaturesEnabledProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IMapControlStatics4)->get_TransitFeaturesEnabledProperty(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IMapControlDataHelper<D>::BusinessLandmarkClick(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkClickEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMapControlDataHelper)->add_BusinessLandmarkClick(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMapControlDataHelper> impl_IMapControlDataHelper<D>::BusinessLandmarkClick(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkClickEventArgs> & value) const
{
    return impl::make_event_revoker<D, IMapControlDataHelper>(this, &ABI::Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper::remove_BusinessLandmarkClick, BusinessLandmarkClick(value));
}

template <typename D> void impl_IMapControlDataHelper<D>::BusinessLandmarkClick(event_token token) const
{
    check_hresult(WINRT_SHIM(IMapControlDataHelper)->remove_BusinessLandmarkClick(token));
}

template <typename D> event_token impl_IMapControlDataHelper<D>::TransitFeatureClick(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlTransitFeatureClickEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMapControlDataHelper)->add_TransitFeatureClick(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMapControlDataHelper> impl_IMapControlDataHelper<D>::TransitFeatureClick(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlTransitFeatureClickEventArgs> & value) const
{
    return impl::make_event_revoker<D, IMapControlDataHelper>(this, &ABI::Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper::remove_TransitFeatureClick, TransitFeatureClick(value));
}

template <typename D> void impl_IMapControlDataHelper<D>::TransitFeatureClick(event_token token) const
{
    check_hresult(WINRT_SHIM(IMapControlDataHelper)->remove_TransitFeatureClick(token));
}

template <typename D> event_token impl_IMapControlDataHelper<D>::BusinessLandmarkRightTapped(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkRightTappedEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMapControlDataHelper)->add_BusinessLandmarkRightTapped(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMapControlDataHelper> impl_IMapControlDataHelper<D>::BusinessLandmarkRightTapped(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkRightTappedEventArgs> & value) const
{
    return impl::make_event_revoker<D, IMapControlDataHelper>(this, &ABI::Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper::remove_BusinessLandmarkRightTapped, BusinessLandmarkRightTapped(value));
}

template <typename D> void impl_IMapControlDataHelper<D>::BusinessLandmarkRightTapped(event_token token) const
{
    check_hresult(WINRT_SHIM(IMapControlDataHelper)->remove_BusinessLandmarkRightTapped(token));
}

template <typename D> event_token impl_IMapControlDataHelper<D>::TransitFeatureRightTapped(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlTransitFeatureRightTappedEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMapControlDataHelper)->add_TransitFeatureRightTapped(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMapControlDataHelper> impl_IMapControlDataHelper<D>::TransitFeatureRightTapped(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlTransitFeatureRightTappedEventArgs> & value) const
{
    return impl::make_event_revoker<D, IMapControlDataHelper>(this, &ABI::Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper::remove_TransitFeatureRightTapped, TransitFeatureRightTapped(value));
}

template <typename D> void impl_IMapControlDataHelper<D>::TransitFeatureRightTapped(event_token token) const
{
    check_hresult(WINRT_SHIM(IMapControlDataHelper)->remove_TransitFeatureRightTapped(token));
}

template <typename D> event_token impl_IMapControlDataHelper2<D>::BusinessLandmarkPointerEntered(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkPointerEnteredEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMapControlDataHelper2)->add_BusinessLandmarkPointerEntered(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMapControlDataHelper2> impl_IMapControlDataHelper2<D>::BusinessLandmarkPointerEntered(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkPointerEnteredEventArgs> & value) const
{
    return impl::make_event_revoker<D, IMapControlDataHelper2>(this, &ABI::Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper2::remove_BusinessLandmarkPointerEntered, BusinessLandmarkPointerEntered(value));
}

template <typename D> void impl_IMapControlDataHelper2<D>::BusinessLandmarkPointerEntered(event_token token) const
{
    check_hresult(WINRT_SHIM(IMapControlDataHelper2)->remove_BusinessLandmarkPointerEntered(token));
}

template <typename D> event_token impl_IMapControlDataHelper2<D>::TransitFeaturePointerEntered(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlTransitFeaturePointerEnteredEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMapControlDataHelper2)->add_TransitFeaturePointerEntered(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMapControlDataHelper2> impl_IMapControlDataHelper2<D>::TransitFeaturePointerEntered(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlTransitFeaturePointerEnteredEventArgs> & value) const
{
    return impl::make_event_revoker<D, IMapControlDataHelper2>(this, &ABI::Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper2::remove_TransitFeaturePointerEntered, TransitFeaturePointerEntered(value));
}

template <typename D> void impl_IMapControlDataHelper2<D>::TransitFeaturePointerEntered(event_token token) const
{
    check_hresult(WINRT_SHIM(IMapControlDataHelper2)->remove_TransitFeaturePointerEntered(token));
}

template <typename D> event_token impl_IMapControlDataHelper2<D>::BusinessLandmarkPointerExited(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkPointerExitedEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMapControlDataHelper2)->add_BusinessLandmarkPointerExited(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMapControlDataHelper2> impl_IMapControlDataHelper2<D>::BusinessLandmarkPointerExited(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlBusinessLandmarkPointerExitedEventArgs> & value) const
{
    return impl::make_event_revoker<D, IMapControlDataHelper2>(this, &ABI::Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper2::remove_BusinessLandmarkPointerExited, BusinessLandmarkPointerExited(value));
}

template <typename D> void impl_IMapControlDataHelper2<D>::BusinessLandmarkPointerExited(event_token token) const
{
    check_hresult(WINRT_SHIM(IMapControlDataHelper2)->remove_BusinessLandmarkPointerExited(token));
}

template <typename D> event_token impl_IMapControlDataHelper2<D>::TransitFeaturePointerExited(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlTransitFeaturePointerExitedEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IMapControlDataHelper2)->add_TransitFeaturePointerExited(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IMapControlDataHelper2> impl_IMapControlDataHelper2<D>::TransitFeaturePointerExited(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Maps::MapControl, Windows::UI::Xaml::Controls::Maps::MapControlTransitFeaturePointerExitedEventArgs> & value) const
{
    return impl::make_event_revoker<D, IMapControlDataHelper2>(this, &ABI::Windows::UI::Xaml::Controls::Maps::IMapControlDataHelper2::remove_TransitFeaturePointerExited, TransitFeaturePointerExited(value));
}

template <typename D> void impl_IMapControlDataHelper2<D>::TransitFeaturePointerExited(event_token token) const
{
    check_hresult(WINRT_SHIM(IMapControlDataHelper2)->remove_TransitFeaturePointerExited(token));
}

template <typename D> Windows::UI::Xaml::Controls::Maps::MapControlDataHelper impl_IMapControlDataHelperFactory<D>::CreateInstance(const Windows::UI::Xaml::Controls::Maps::MapControl & map) const
{
    Windows::UI::Xaml::Controls::Maps::MapControlDataHelper instance { nullptr };
    check_hresult(WINRT_SHIM(IMapControlDataHelperFactory)->abi_CreateInstance(get_abi(map), put_abi(instance)));
    return instance;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::LocalSearch::LocalLocation> impl_IMapControlBusinessLandmarkClickEventArgs<D>::LocalLocations() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::LocalSearch::LocalLocation> value;
    check_hresult(WINRT_SHIM(IMapControlBusinessLandmarkClickEventArgs)->get_LocalLocations(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMapControlTransitFeatureClickEventArgs<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMapControlTransitFeatureClickEventArgs)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geopoint impl_IMapControlTransitFeatureClickEventArgs<D>::Location() const
{
    Windows::Devices::Geolocation::Geopoint value { nullptr };
    check_hresult(WINRT_SHIM(IMapControlTransitFeatureClickEventArgs)->get_Location(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> impl_IMapControlTransitFeatureClickEventArgs<D>::TransitProperties() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> value;
    check_hresult(WINRT_SHIM(IMapControlTransitFeatureClickEventArgs)->get_TransitProperties(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::LocalSearch::LocalLocation> impl_IMapControlBusinessLandmarkRightTappedEventArgs<D>::LocalLocations() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::LocalSearch::LocalLocation> value;
    check_hresult(WINRT_SHIM(IMapControlBusinessLandmarkRightTappedEventArgs)->get_LocalLocations(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMapControlTransitFeatureRightTappedEventArgs<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMapControlTransitFeatureRightTappedEventArgs)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geopoint impl_IMapControlTransitFeatureRightTappedEventArgs<D>::Location() const
{
    Windows::Devices::Geolocation::Geopoint value { nullptr };
    check_hresult(WINRT_SHIM(IMapControlTransitFeatureRightTappedEventArgs)->get_Location(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> impl_IMapControlTransitFeatureRightTappedEventArgs<D>::TransitProperties() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> value;
    check_hresult(WINRT_SHIM(IMapControlTransitFeatureRightTappedEventArgs)->get_TransitProperties(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::LocalSearch::LocalLocation> impl_IMapControlBusinessLandmarkPointerEnteredEventArgs<D>::LocalLocations() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::LocalSearch::LocalLocation> value;
    check_hresult(WINRT_SHIM(IMapControlBusinessLandmarkPointerEnteredEventArgs)->get_LocalLocations(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMapControlTransitFeaturePointerEnteredEventArgs<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMapControlTransitFeaturePointerEnteredEventArgs)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geopoint impl_IMapControlTransitFeaturePointerEnteredEventArgs<D>::Location() const
{
    Windows::Devices::Geolocation::Geopoint value { nullptr };
    check_hresult(WINRT_SHIM(IMapControlTransitFeaturePointerEnteredEventArgs)->get_Location(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> impl_IMapControlTransitFeaturePointerEnteredEventArgs<D>::TransitProperties() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> value;
    check_hresult(WINRT_SHIM(IMapControlTransitFeaturePointerEnteredEventArgs)->get_TransitProperties(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::LocalSearch::LocalLocation> impl_IMapControlBusinessLandmarkPointerExitedEventArgs<D>::LocalLocations() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::LocalSearch::LocalLocation> value;
    check_hresult(WINRT_SHIM(IMapControlBusinessLandmarkPointerExitedEventArgs)->get_LocalLocations(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMapControlTransitFeaturePointerExitedEventArgs<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMapControlTransitFeaturePointerExitedEventArgs)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geopoint impl_IMapControlTransitFeaturePointerExitedEventArgs<D>::Location() const
{
    Windows::Devices::Geolocation::Geopoint value { nullptr };
    check_hresult(WINRT_SHIM(IMapControlTransitFeaturePointerExitedEventArgs)->get_Location(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> impl_IMapControlTransitFeaturePointerExitedEventArgs<D>::TransitProperties() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> value;
    check_hresult(WINRT_SHIM(IMapControlTransitFeaturePointerExitedEventArgs)->get_TransitProperties(put_abi(value)));
    return value;
}

inline CustomMapTileDataSource::CustomMapTileDataSource()
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<CustomMapTileDataSource, ICustomMapTileDataSourceFactory>().CreateInstance(outer, inner));
}

inline HttpMapTileDataSource::HttpMapTileDataSource()
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<HttpMapTileDataSource, IHttpMapTileDataSourceFactory>().CreateInstance(outer, inner));
}

inline HttpMapTileDataSource::HttpMapTileDataSource(hstring_view uriFormatString)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<HttpMapTileDataSource, IHttpMapTileDataSourceFactory>().CreateInstanceWithUriFormatString(uriFormatString, outer, inner));
}

inline LocalMapTileDataSource::LocalMapTileDataSource()
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<LocalMapTileDataSource, ILocalMapTileDataSourceFactory>().CreateInstance(outer, inner));
}

inline LocalMapTileDataSource::LocalMapTileDataSource(hstring_view uriFormatString)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<LocalMapTileDataSource, ILocalMapTileDataSourceFactory>().CreateInstanceWithUriFormatString(uriFormatString, outer, inner));
}

inline MapActualCameraChangedEventArgs::MapActualCameraChangedEventArgs() :
    MapActualCameraChangedEventArgs(activate_instance<MapActualCameraChangedEventArgs>())
{}

inline MapActualCameraChangingEventArgs::MapActualCameraChangingEventArgs() :
    MapActualCameraChangingEventArgs(activate_instance<MapActualCameraChangingEventArgs>())
{}

inline MapCamera::MapCamera(const Windows::Devices::Geolocation::Geopoint & location) :
    MapCamera(get_activation_factory<MapCamera, IMapCameraFactory>().CreateInstanceWithLocation(location))
{}

inline MapCamera::MapCamera(const Windows::Devices::Geolocation::Geopoint & location, double headingInDegrees) :
    MapCamera(get_activation_factory<MapCamera, IMapCameraFactory>().CreateInstanceWithLocationAndHeading(location, headingInDegrees))
{}

inline MapCamera::MapCamera(const Windows::Devices::Geolocation::Geopoint & location, double headingInDegrees, double pitchInDegrees) :
    MapCamera(get_activation_factory<MapCamera, IMapCameraFactory>().CreateInstanceWithLocationHeadingAndPitch(location, headingInDegrees, pitchInDegrees))
{}

inline MapCamera::MapCamera(const Windows::Devices::Geolocation::Geopoint & location, double headingInDegrees, double pitchInDegrees, double rollInDegrees, double fieldOfViewInDegrees) :
    MapCamera(get_activation_factory<MapCamera, IMapCameraFactory>().CreateInstanceWithLocationHeadingPitchRollAndFieldOfView(location, headingInDegrees, pitchInDegrees, rollInDegrees, fieldOfViewInDegrees))
{}

inline MapControl::MapControl() :
    MapControl(activate_instance<MapControl>())
{}

inline Windows::UI::Xaml::DependencyProperty MapControl::CenterProperty()
{
    return get_activation_factory<MapControl, IMapControlStatics>().CenterProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapControl::ChildrenProperty()
{
    return get_activation_factory<MapControl, IMapControlStatics>().ChildrenProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapControl::ColorSchemeProperty()
{
    return get_activation_factory<MapControl, IMapControlStatics>().ColorSchemeProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapControl::DesiredPitchProperty()
{
    return get_activation_factory<MapControl, IMapControlStatics>().DesiredPitchProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapControl::HeadingProperty()
{
    return get_activation_factory<MapControl, IMapControlStatics>().HeadingProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapControl::LandmarksVisibleProperty()
{
    return get_activation_factory<MapControl, IMapControlStatics>().LandmarksVisibleProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapControl::LoadingStatusProperty()
{
    return get_activation_factory<MapControl, IMapControlStatics>().LoadingStatusProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapControl::MapServiceTokenProperty()
{
    return get_activation_factory<MapControl, IMapControlStatics>().MapServiceTokenProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapControl::PedestrianFeaturesVisibleProperty()
{
    return get_activation_factory<MapControl, IMapControlStatics>().PedestrianFeaturesVisibleProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapControl::PitchProperty()
{
    return get_activation_factory<MapControl, IMapControlStatics>().PitchProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapControl::StyleProperty()
{
    return get_activation_factory<MapControl, IMapControlStatics>().StyleProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapControl::TrafficFlowVisibleProperty()
{
    return get_activation_factory<MapControl, IMapControlStatics>().TrafficFlowVisibleProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapControl::TransformOriginProperty()
{
    return get_activation_factory<MapControl, IMapControlStatics>().TransformOriginProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapControl::WatermarkModeProperty()
{
    return get_activation_factory<MapControl, IMapControlStatics>().WatermarkModeProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapControl::ZoomLevelProperty()
{
    return get_activation_factory<MapControl, IMapControlStatics>().ZoomLevelProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapControl::MapElementsProperty()
{
    return get_activation_factory<MapControl, IMapControlStatics>().MapElementsProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapControl::RoutesProperty()
{
    return get_activation_factory<MapControl, IMapControlStatics>().RoutesProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapControl::TileSourcesProperty()
{
    return get_activation_factory<MapControl, IMapControlStatics>().TileSourcesProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapControl::LocationProperty()
{
    return get_activation_factory<MapControl, IMapControlStatics>().LocationProperty();
}

inline Windows::Devices::Geolocation::Geopoint MapControl::GetLocation(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<MapControl, IMapControlStatics>().GetLocation(element);
}

inline void MapControl::SetLocation(const Windows::UI::Xaml::DependencyObject & element, const Windows::Devices::Geolocation::Geopoint & value)
{
    get_activation_factory<MapControl, IMapControlStatics>().SetLocation(element, value);
}

inline Windows::UI::Xaml::DependencyProperty MapControl::NormalizedAnchorPointProperty()
{
    return get_activation_factory<MapControl, IMapControlStatics>().NormalizedAnchorPointProperty();
}

inline Windows::Foundation::Point MapControl::GetNormalizedAnchorPoint(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<MapControl, IMapControlStatics>().GetNormalizedAnchorPoint(element);
}

inline void MapControl::SetNormalizedAnchorPoint(const Windows::UI::Xaml::DependencyObject & element, const Windows::Foundation::Point & value)
{
    get_activation_factory<MapControl, IMapControlStatics>().SetNormalizedAnchorPoint(element, value);
}

inline Windows::UI::Xaml::DependencyProperty MapControl::BusinessLandmarksVisibleProperty()
{
    return get_activation_factory<MapControl, IMapControlStatics2>().BusinessLandmarksVisibleProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapControl::TransitFeaturesVisibleProperty()
{
    return get_activation_factory<MapControl, IMapControlStatics2>().TransitFeaturesVisibleProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapControl::PanInteractionModeProperty()
{
    return get_activation_factory<MapControl, IMapControlStatics2>().PanInteractionModeProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapControl::RotateInteractionModeProperty()
{
    return get_activation_factory<MapControl, IMapControlStatics2>().RotateInteractionModeProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapControl::TiltInteractionModeProperty()
{
    return get_activation_factory<MapControl, IMapControlStatics2>().TiltInteractionModeProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapControl::ZoomInteractionModeProperty()
{
    return get_activation_factory<MapControl, IMapControlStatics2>().ZoomInteractionModeProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapControl::Is3DSupportedProperty()
{
    return get_activation_factory<MapControl, IMapControlStatics2>().Is3DSupportedProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapControl::IsStreetsideSupportedProperty()
{
    return get_activation_factory<MapControl, IMapControlStatics2>().IsStreetsideSupportedProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapControl::SceneProperty()
{
    return get_activation_factory<MapControl, IMapControlStatics2>().SceneProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapControl::BusinessLandmarksEnabledProperty()
{
    return get_activation_factory<MapControl, IMapControlStatics4>().BusinessLandmarksEnabledProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapControl::TransitFeaturesEnabledProperty()
{
    return get_activation_factory<MapControl, IMapControlStatics4>().TransitFeaturesEnabledProperty();
}

inline MapControlBusinessLandmarkClickEventArgs::MapControlBusinessLandmarkClickEventArgs() :
    MapControlBusinessLandmarkClickEventArgs(activate_instance<MapControlBusinessLandmarkClickEventArgs>())
{}

inline MapControlBusinessLandmarkPointerEnteredEventArgs::MapControlBusinessLandmarkPointerEnteredEventArgs() :
    MapControlBusinessLandmarkPointerEnteredEventArgs(activate_instance<MapControlBusinessLandmarkPointerEnteredEventArgs>())
{}

inline MapControlBusinessLandmarkPointerExitedEventArgs::MapControlBusinessLandmarkPointerExitedEventArgs() :
    MapControlBusinessLandmarkPointerExitedEventArgs(activate_instance<MapControlBusinessLandmarkPointerExitedEventArgs>())
{}

inline MapControlBusinessLandmarkRightTappedEventArgs::MapControlBusinessLandmarkRightTappedEventArgs() :
    MapControlBusinessLandmarkRightTappedEventArgs(activate_instance<MapControlBusinessLandmarkRightTappedEventArgs>())
{}

inline MapControlDataHelper::MapControlDataHelper(const Windows::UI::Xaml::Controls::Maps::MapControl & map) :
    MapControlDataHelper(get_activation_factory<MapControlDataHelper, IMapControlDataHelperFactory>().CreateInstance(map))
{}

inline MapControlTransitFeatureClickEventArgs::MapControlTransitFeatureClickEventArgs() :
    MapControlTransitFeatureClickEventArgs(activate_instance<MapControlTransitFeatureClickEventArgs>())
{}

inline MapControlTransitFeaturePointerEnteredEventArgs::MapControlTransitFeaturePointerEnteredEventArgs() :
    MapControlTransitFeaturePointerEnteredEventArgs(activate_instance<MapControlTransitFeaturePointerEnteredEventArgs>())
{}

inline MapControlTransitFeaturePointerExitedEventArgs::MapControlTransitFeaturePointerExitedEventArgs() :
    MapControlTransitFeaturePointerExitedEventArgs(activate_instance<MapControlTransitFeaturePointerExitedEventArgs>())
{}

inline MapControlTransitFeatureRightTappedEventArgs::MapControlTransitFeatureRightTappedEventArgs() :
    MapControlTransitFeatureRightTappedEventArgs(activate_instance<MapControlTransitFeatureRightTappedEventArgs>())
{}

inline MapCustomExperience::MapCustomExperience()
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<MapCustomExperience, IMapCustomExperienceFactory>().CreateInstance(outer, inner));
}

inline MapCustomExperienceChangedEventArgs::MapCustomExperienceChangedEventArgs() :
    MapCustomExperienceChangedEventArgs(activate_instance<MapCustomExperienceChangedEventArgs>())
{}

inline MapElement::MapElement()
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<MapElement, IMapElementFactory>().CreateInstance(outer, inner));
}

inline Windows::UI::Xaml::DependencyProperty MapElement::ZIndexProperty()
{
    return get_activation_factory<MapElement, IMapElementStatics>().ZIndexProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapElement::VisibleProperty()
{
    return get_activation_factory<MapElement, IMapElementStatics>().VisibleProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapElement::MapTabIndexProperty()
{
    return get_activation_factory<MapElement, IMapElementStatics2>().MapTabIndexProperty();
}

inline MapElementClickEventArgs::MapElementClickEventArgs() :
    MapElementClickEventArgs(activate_instance<MapElementClickEventArgs>())
{}

inline MapElementPointerEnteredEventArgs::MapElementPointerEnteredEventArgs() :
    MapElementPointerEnteredEventArgs(activate_instance<MapElementPointerEnteredEventArgs>())
{}

inline MapElementPointerExitedEventArgs::MapElementPointerExitedEventArgs() :
    MapElementPointerExitedEventArgs(activate_instance<MapElementPointerExitedEventArgs>())
{}

inline MapIcon::MapIcon() :
    MapIcon(activate_instance<MapIcon>())
{}

inline Windows::UI::Xaml::DependencyProperty MapIcon::LocationProperty()
{
    return get_activation_factory<MapIcon, IMapIconStatics>().LocationProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapIcon::TitleProperty()
{
    return get_activation_factory<MapIcon, IMapIconStatics>().TitleProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapIcon::NormalizedAnchorPointProperty()
{
    return get_activation_factory<MapIcon, IMapIconStatics>().NormalizedAnchorPointProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapIcon::CollisionBehaviorDesiredProperty()
{
    return get_activation_factory<MapIcon, IMapIconStatics2>().CollisionBehaviorDesiredProperty();
}

inline MapInputEventArgs::MapInputEventArgs() :
    MapInputEventArgs(activate_instance<MapInputEventArgs>())
{}

inline MapItemsControl::MapItemsControl() :
    MapItemsControl(activate_instance<MapItemsControl>())
{}

inline Windows::UI::Xaml::DependencyProperty MapItemsControl::ItemsSourceProperty()
{
    return get_activation_factory<MapItemsControl, IMapItemsControlStatics>().ItemsSourceProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapItemsControl::ItemsProperty()
{
    return get_activation_factory<MapItemsControl, IMapItemsControlStatics>().ItemsProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapItemsControl::ItemTemplateProperty()
{
    return get_activation_factory<MapItemsControl, IMapItemsControlStatics>().ItemTemplateProperty();
}

inline MapPolygon::MapPolygon() :
    MapPolygon(activate_instance<MapPolygon>())
{}

inline Windows::UI::Xaml::DependencyProperty MapPolygon::PathProperty()
{
    return get_activation_factory<MapPolygon, IMapPolygonStatics>().PathProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapPolygon::StrokeThicknessProperty()
{
    return get_activation_factory<MapPolygon, IMapPolygonStatics>().StrokeThicknessProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapPolygon::StrokeDashedProperty()
{
    return get_activation_factory<MapPolygon, IMapPolygonStatics>().StrokeDashedProperty();
}

inline MapPolyline::MapPolyline() :
    MapPolyline(activate_instance<MapPolyline>())
{}

inline Windows::UI::Xaml::DependencyProperty MapPolyline::PathProperty()
{
    return get_activation_factory<MapPolyline, IMapPolylineStatics>().PathProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapPolyline::StrokeDashedProperty()
{
    return get_activation_factory<MapPolyline, IMapPolylineStatics>().StrokeDashedProperty();
}

inline MapRightTappedEventArgs::MapRightTappedEventArgs() :
    MapRightTappedEventArgs(activate_instance<MapRightTappedEventArgs>())
{}

inline MapRouteView::MapRouteView(const Windows::Services::Maps::MapRoute & route)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<MapRouteView, IMapRouteViewFactory>().CreateInstanceWithMapRoute(route, outer, inner));
}

inline Windows::UI::Xaml::Controls::Maps::MapScene MapScene::CreateFromBoundingBox(const Windows::Devices::Geolocation::GeoboundingBox & bounds)
{
    return get_activation_factory<MapScene, IMapSceneStatics>().CreateFromBoundingBox(bounds);
}

inline Windows::UI::Xaml::Controls::Maps::MapScene MapScene::CreateFromBoundingBox(const Windows::Devices::Geolocation::GeoboundingBox & bounds, double headingInDegrees, double pitchInDegrees)
{
    return get_activation_factory<MapScene, IMapSceneStatics>().CreateFromBoundingBox(bounds, headingInDegrees, pitchInDegrees);
}

inline Windows::UI::Xaml::Controls::Maps::MapScene MapScene::CreateFromCamera(const Windows::UI::Xaml::Controls::Maps::MapCamera & camera)
{
    return get_activation_factory<MapScene, IMapSceneStatics>().CreateFromCamera(camera);
}

inline Windows::UI::Xaml::Controls::Maps::MapScene MapScene::CreateFromLocation(const Windows::Devices::Geolocation::Geopoint & location)
{
    return get_activation_factory<MapScene, IMapSceneStatics>().CreateFromLocation(location);
}

inline Windows::UI::Xaml::Controls::Maps::MapScene MapScene::CreateFromLocation(const Windows::Devices::Geolocation::Geopoint & location, double headingInDegrees, double pitchInDegrees)
{
    return get_activation_factory<MapScene, IMapSceneStatics>().CreateFromLocation(location, headingInDegrees, pitchInDegrees);
}

inline Windows::UI::Xaml::Controls::Maps::MapScene MapScene::CreateFromLocationAndRadius(const Windows::Devices::Geolocation::Geopoint & location, double radiusInMeters)
{
    return get_activation_factory<MapScene, IMapSceneStatics>().CreateFromLocationAndRadius(location, radiusInMeters);
}

inline Windows::UI::Xaml::Controls::Maps::MapScene MapScene::CreateFromLocationAndRadius(const Windows::Devices::Geolocation::Geopoint & location, double radiusInMeters, double headingInDegrees, double pitchInDegrees)
{
    return get_activation_factory<MapScene, IMapSceneStatics>().CreateFromLocationAndRadius(location, radiusInMeters, headingInDegrees, pitchInDegrees);
}

inline Windows::UI::Xaml::Controls::Maps::MapScene MapScene::CreateFromLocations(iterable<Windows::Devices::Geolocation::Geopoint> locations)
{
    return get_activation_factory<MapScene, IMapSceneStatics>().CreateFromLocations(locations);
}

inline Windows::UI::Xaml::Controls::Maps::MapScene MapScene::CreateFromLocations(iterable<Windows::Devices::Geolocation::Geopoint> locations, double headingInDegrees, double pitchInDegrees)
{
    return get_activation_factory<MapScene, IMapSceneStatics>().CreateFromLocations(locations, headingInDegrees, pitchInDegrees);
}

inline MapTargetCameraChangedEventArgs::MapTargetCameraChangedEventArgs() :
    MapTargetCameraChangedEventArgs(activate_instance<MapTargetCameraChangedEventArgs>())
{}

inline MapTileBitmapRequest::MapTileBitmapRequest() :
    MapTileBitmapRequest(activate_instance<MapTileBitmapRequest>())
{}

inline MapTileBitmapRequestDeferral::MapTileBitmapRequestDeferral() :
    MapTileBitmapRequestDeferral(activate_instance<MapTileBitmapRequestDeferral>())
{}

inline MapTileBitmapRequestedEventArgs::MapTileBitmapRequestedEventArgs() :
    MapTileBitmapRequestedEventArgs(activate_instance<MapTileBitmapRequestedEventArgs>())
{}

inline MapTileDataSource::MapTileDataSource()
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<MapTileDataSource, IMapTileDataSourceFactory>().CreateInstance(outer, inner));
}

inline MapTileSource::MapTileSource()
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<MapTileSource, IMapTileSourceFactory>().CreateInstance(outer, inner));
}

inline MapTileSource::MapTileSource(const Windows::UI::Xaml::Controls::Maps::MapTileDataSource & dataSource)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<MapTileSource, IMapTileSourceFactory>().CreateInstanceWithDataSource(dataSource, outer, inner));
}

inline MapTileSource::MapTileSource(const Windows::UI::Xaml::Controls::Maps::MapTileDataSource & dataSource, const Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange & zoomLevelRange)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<MapTileSource, IMapTileSourceFactory>().CreateInstanceWithDataSourceAndZoomRange(dataSource, zoomLevelRange, outer, inner));
}

inline MapTileSource::MapTileSource(const Windows::UI::Xaml::Controls::Maps::MapTileDataSource & dataSource, const Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange & zoomLevelRange, const Windows::Devices::Geolocation::GeoboundingBox & bounds)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<MapTileSource, IMapTileSourceFactory>().CreateInstanceWithDataSourceZoomRangeAndBounds(dataSource, zoomLevelRange, bounds, outer, inner));
}

inline MapTileSource::MapTileSource(const Windows::UI::Xaml::Controls::Maps::MapTileDataSource & dataSource, const Windows::UI::Xaml::Controls::Maps::MapZoomLevelRange & zoomLevelRange, const Windows::Devices::Geolocation::GeoboundingBox & bounds, int32_t tileSizeInPixels)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<MapTileSource, IMapTileSourceFactory>().CreateInstanceWithDataSourceZoomRangeBoundsAndTileSize(dataSource, zoomLevelRange, bounds, tileSizeInPixels, outer, inner));
}

inline Windows::UI::Xaml::DependencyProperty MapTileSource::DataSourceProperty()
{
    return get_activation_factory<MapTileSource, IMapTileSourceStatics>().DataSourceProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapTileSource::LayerProperty()
{
    return get_activation_factory<MapTileSource, IMapTileSourceStatics>().LayerProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapTileSource::ZoomLevelRangeProperty()
{
    return get_activation_factory<MapTileSource, IMapTileSourceStatics>().ZoomLevelRangeProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapTileSource::BoundsProperty()
{
    return get_activation_factory<MapTileSource, IMapTileSourceStatics>().BoundsProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapTileSource::AllowOverstretchProperty()
{
    return get_activation_factory<MapTileSource, IMapTileSourceStatics>().AllowOverstretchProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapTileSource::IsFadingEnabledProperty()
{
    return get_activation_factory<MapTileSource, IMapTileSourceStatics>().IsFadingEnabledProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapTileSource::IsTransparencyEnabledProperty()
{
    return get_activation_factory<MapTileSource, IMapTileSourceStatics>().IsTransparencyEnabledProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapTileSource::IsRetryEnabledProperty()
{
    return get_activation_factory<MapTileSource, IMapTileSourceStatics>().IsRetryEnabledProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapTileSource::ZIndexProperty()
{
    return get_activation_factory<MapTileSource, IMapTileSourceStatics>().ZIndexProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapTileSource::TilePixelSizeProperty()
{
    return get_activation_factory<MapTileSource, IMapTileSourceStatics>().TilePixelSizeProperty();
}

inline Windows::UI::Xaml::DependencyProperty MapTileSource::VisibleProperty()
{
    return get_activation_factory<MapTileSource, IMapTileSourceStatics>().VisibleProperty();
}

inline MapTileUriRequest::MapTileUriRequest() :
    MapTileUriRequest(activate_instance<MapTileUriRequest>())
{}

inline MapTileUriRequestDeferral::MapTileUriRequestDeferral() :
    MapTileUriRequestDeferral(activate_instance<MapTileUriRequestDeferral>())
{}

inline MapTileUriRequestedEventArgs::MapTileUriRequestedEventArgs() :
    MapTileUriRequestedEventArgs(activate_instance<MapTileUriRequestedEventArgs>())
{}

inline StreetsideExperience::StreetsideExperience(const Windows::UI::Xaml::Controls::Maps::StreetsidePanorama & panorama) :
    StreetsideExperience(get_activation_factory<StreetsideExperience, IStreetsideExperienceFactory>().CreateInstanceWithPanorama(panorama))
{}

inline StreetsideExperience::StreetsideExperience(const Windows::UI::Xaml::Controls::Maps::StreetsidePanorama & panorama, double headingInDegrees, double pitchInDegrees, double fieldOfViewInDegrees) :
    StreetsideExperience(get_activation_factory<StreetsideExperience, IStreetsideExperienceFactory>().CreateInstanceWithPanoramaHeadingPitchAndFieldOfView(panorama, headingInDegrees, pitchInDegrees, fieldOfViewInDegrees))
{}

inline Windows::Foundation::IAsyncOperation<Windows::UI::Xaml::Controls::Maps::StreetsidePanorama> StreetsidePanorama::FindNearbyAsync(const Windows::Devices::Geolocation::Geopoint & location)
{
    return get_activation_factory<StreetsidePanorama, IStreetsidePanoramaStatics>().FindNearbyAsync(location);
}

inline Windows::Foundation::IAsyncOperation<Windows::UI::Xaml::Controls::Maps::StreetsidePanorama> StreetsidePanorama::FindNearbyAsync(const Windows::Devices::Geolocation::Geopoint & location, double radiusInMeters)
{
    return get_activation_factory<StreetsidePanorama, IStreetsidePanoramaStatics>().FindNearbyAsync(location, radiusInMeters);
}

}

}
#pragma warning(pop)
