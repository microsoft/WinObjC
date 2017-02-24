// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Devices.Geolocation.3.h"
#include "Windows.Devices.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::Geolocation::ICivicAddress> : produce_base<D, Windows::Devices::Geolocation::ICivicAddress>
{
    HRESULT __stdcall get_Country(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Country());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_State(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().State());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_City(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().City());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PostalCode(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PostalCode());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Timestamp(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Timestamp());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Geolocation::IGeoboundingBox> : produce_base<D, Windows::Devices::Geolocation::IGeoboundingBox>
{
    HRESULT __stdcall get_NorthwestCorner(impl::abi_arg_out<Windows::Devices::Geolocation::BasicGeoposition> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NorthwestCorner());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SoutheastCorner(impl::abi_arg_out<Windows::Devices::Geolocation::BasicGeoposition> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SoutheastCorner());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Center(impl::abi_arg_out<Windows::Devices::Geolocation::BasicGeoposition> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Center());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinAltitude(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinAltitude());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxAltitude(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxAltitude());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Geolocation::IGeoboundingBoxFactory> : produce_base<D, Windows::Devices::Geolocation::IGeoboundingBoxFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Devices::Geolocation::BasicGeoposition> northwestCorner, impl::abi_arg_in<Windows::Devices::Geolocation::BasicGeoposition> southeastCorner, impl::abi_arg_out<Windows::Devices::Geolocation::IGeoboundingBox> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Devices::Geolocation::BasicGeoposition *>(&northwestCorner), *reinterpret_cast<const Windows::Devices::Geolocation::BasicGeoposition *>(&southeastCorner)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithAltitudeReference(impl::abi_arg_in<Windows::Devices::Geolocation::BasicGeoposition> northwestCorner, impl::abi_arg_in<Windows::Devices::Geolocation::BasicGeoposition> southeastCorner, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem, impl::abi_arg_out<Windows::Devices::Geolocation::IGeoboundingBox> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateWithAltitudeReference(*reinterpret_cast<const Windows::Devices::Geolocation::BasicGeoposition *>(&northwestCorner), *reinterpret_cast<const Windows::Devices::Geolocation::BasicGeoposition *>(&southeastCorner), altitudeReferenceSystem));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithAltitudeReferenceAndSpatialReference(impl::abi_arg_in<Windows::Devices::Geolocation::BasicGeoposition> northwestCorner, impl::abi_arg_in<Windows::Devices::Geolocation::BasicGeoposition> southeastCorner, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem, uint32_t spatialReferenceId, impl::abi_arg_out<Windows::Devices::Geolocation::IGeoboundingBox> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateWithAltitudeReferenceAndSpatialReference(*reinterpret_cast<const Windows::Devices::Geolocation::BasicGeoposition *>(&northwestCorner), *reinterpret_cast<const Windows::Devices::Geolocation::BasicGeoposition *>(&southeastCorner), altitudeReferenceSystem, spatialReferenceId));
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
struct produce<D, Windows::Devices::Geolocation::IGeoboundingBoxStatics> : produce_base<D, Windows::Devices::Geolocation::IGeoboundingBoxStatics>
{
    HRESULT __stdcall abi_TryCompute(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Devices::Geolocation::BasicGeoposition>> positions, impl::abi_arg_out<Windows::Devices::Geolocation::IGeoboundingBox> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TryCompute(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Devices::Geolocation::BasicGeoposition> *>(&positions)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryComputeWithAltitudeReference(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Devices::Geolocation::BasicGeoposition>> positions, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeRefSystem, impl::abi_arg_out<Windows::Devices::Geolocation::IGeoboundingBox> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TryCompute(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Devices::Geolocation::BasicGeoposition> *>(&positions), altitudeRefSystem));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryComputeWithAltitudeReferenceAndSpatialReference(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Devices::Geolocation::BasicGeoposition>> positions, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeRefSystem, uint32_t spatialReferenceId, impl::abi_arg_out<Windows::Devices::Geolocation::IGeoboundingBox> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TryCompute(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Devices::Geolocation::BasicGeoposition> *>(&positions), altitudeRefSystem, spatialReferenceId));
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
struct produce<D, Windows::Devices::Geolocation::IGeocircle> : produce_base<D, Windows::Devices::Geolocation::IGeocircle>
{
    HRESULT __stdcall get_Center(impl::abi_arg_out<Windows::Devices::Geolocation::BasicGeoposition> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Center());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Radius(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Radius());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Geolocation::IGeocircleFactory> : produce_base<D, Windows::Devices::Geolocation::IGeocircleFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Devices::Geolocation::BasicGeoposition> position, double radius, impl::abi_arg_out<Windows::Devices::Geolocation::IGeocircle> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Devices::Geolocation::BasicGeoposition *>(&position), radius));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithAltitudeReferenceSystem(impl::abi_arg_in<Windows::Devices::Geolocation::BasicGeoposition> position, double radius, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem, impl::abi_arg_out<Windows::Devices::Geolocation::IGeocircle> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateWithAltitudeReferenceSystem(*reinterpret_cast<const Windows::Devices::Geolocation::BasicGeoposition *>(&position), radius, altitudeReferenceSystem));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithAltitudeReferenceSystemAndSpatialReferenceId(impl::abi_arg_in<Windows::Devices::Geolocation::BasicGeoposition> position, double radius, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem, uint32_t spatialReferenceId, impl::abi_arg_out<Windows::Devices::Geolocation::IGeocircle> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateWithAltitudeReferenceSystemAndSpatialReferenceId(*reinterpret_cast<const Windows::Devices::Geolocation::BasicGeoposition *>(&position), radius, altitudeReferenceSystem, spatialReferenceId));
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
struct produce<D, Windows::Devices::Geolocation::IGeocoordinate> : produce_base<D, Windows::Devices::Geolocation::IGeocoordinate>
{
    HRESULT __stdcall get_Latitude(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Latitude());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Longitude(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Longitude());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Altitude(impl::abi_arg_out<Windows::Foundation::IReference<double>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Altitude());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Accuracy(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Accuracy());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AltitudeAccuracy(impl::abi_arg_out<Windows::Foundation::IReference<double>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AltitudeAccuracy());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Heading(impl::abi_arg_out<Windows::Foundation::IReference<double>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Heading());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Speed(impl::abi_arg_out<Windows::Foundation::IReference<double>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Speed());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Timestamp(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Timestamp());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Geolocation::IGeocoordinateSatelliteData> : produce_base<D, Windows::Devices::Geolocation::IGeocoordinateSatelliteData>
{
    HRESULT __stdcall get_PositionDilutionOfPrecision(impl::abi_arg_out<Windows::Foundation::IReference<double>> ppValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *ppValue = detach_abi(this->shim().PositionDilutionOfPrecision());
            return S_OK;
        }
        catch (...)
        {
            *ppValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HorizontalDilutionOfPrecision(impl::abi_arg_out<Windows::Foundation::IReference<double>> ppValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *ppValue = detach_abi(this->shim().HorizontalDilutionOfPrecision());
            return S_OK;
        }
        catch (...)
        {
            *ppValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VerticalDilutionOfPrecision(impl::abi_arg_out<Windows::Foundation::IReference<double>> ppValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *ppValue = detach_abi(this->shim().VerticalDilutionOfPrecision());
            return S_OK;
        }
        catch (...)
        {
            *ppValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Geolocation::IGeocoordinateWithPoint> : produce_base<D, Windows::Devices::Geolocation::IGeocoordinateWithPoint>
{
    HRESULT __stdcall get_Point(impl::abi_arg_out<Windows::Devices::Geolocation::IGeopoint> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Point());
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
struct produce<D, Windows::Devices::Geolocation::IGeocoordinateWithPositionData> : produce_base<D, Windows::Devices::Geolocation::IGeocoordinateWithPositionData>
{
    HRESULT __stdcall get_PositionSource(Windows::Devices::Geolocation::PositionSource * pValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *pValue = detach_abi(this->shim().PositionSource());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SatelliteData(impl::abi_arg_out<Windows::Devices::Geolocation::IGeocoordinateSatelliteData> ppValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *ppValue = detach_abi(this->shim().SatelliteData());
            return S_OK;
        }
        catch (...)
        {
            *ppValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Geolocation::IGeocoordinateWithPositionSourceTimestamp> : produce_base<D, Windows::Devices::Geolocation::IGeocoordinateWithPositionSourceTimestamp>
{
    HRESULT __stdcall get_PositionSourceTimestamp(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PositionSourceTimestamp());
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
struct produce<D, Windows::Devices::Geolocation::IGeolocator> : produce_base<D, Windows::Devices::Geolocation::IGeolocator>
{
    HRESULT __stdcall get_DesiredAccuracy(Windows::Devices::Geolocation::PositionAccuracy * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DesiredAccuracy());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DesiredAccuracy(Windows::Devices::Geolocation::PositionAccuracy value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DesiredAccuracy(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MovementThreshold(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MovementThreshold());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MovementThreshold(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MovementThreshold(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ReportInterval(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReportInterval());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ReportInterval(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportInterval(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LocationStatus(Windows::Devices::Geolocation::PositionStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LocationStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetGeopositionAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Geolocation::Geoposition>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetGeopositionAsync());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetGeopositionAsyncWithAgeAndTimeout(impl::abi_arg_in<Windows::Foundation::TimeSpan> maximumAge, impl::abi_arg_in<Windows::Foundation::TimeSpan> timeout, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Geolocation::Geoposition>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetGeopositionAsync(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&maximumAge), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&timeout)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PositionChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Geolocation::Geolocator, Windows::Devices::Geolocation::PositionChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().PositionChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Geolocation::Geolocator, Windows::Devices::Geolocation::PositionChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PositionChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PositionChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_StatusChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Geolocation::Geolocator, Windows::Devices::Geolocation::StatusChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().StatusChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Geolocation::Geolocator, Windows::Devices::Geolocation::StatusChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_StatusChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StatusChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Geolocation::IGeolocator2> : produce_base<D, Windows::Devices::Geolocation::IGeolocator2>
{
    HRESULT __stdcall abi_AllowFallbackToConsentlessPositions() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowFallbackToConsentlessPositions();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Geolocation::IGeolocatorStatics> : produce_base<D, Windows::Devices::Geolocation::IGeolocatorStatics>
{
    HRESULT __stdcall abi_RequestAccessAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Geolocation::GeolocationAccessStatus>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestAccessAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetGeopositionHistoryAsync(impl::abi_arg_in<Windows::Foundation::DateTime> startTime, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Geolocation::Geoposition>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetGeopositionHistoryAsync(*reinterpret_cast<const Windows::Foundation::DateTime *>(&startTime)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetGeopositionHistoryWithDurationAsync(impl::abi_arg_in<Windows::Foundation::DateTime> startTime, impl::abi_arg_in<Windows::Foundation::TimeSpan> duration, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Geolocation::Geoposition>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetGeopositionHistoryAsync(*reinterpret_cast<const Windows::Foundation::DateTime *>(&startTime), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&duration)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Geolocation::IGeolocatorStatics2> : produce_base<D, Windows::Devices::Geolocation::IGeolocatorStatics2>
{
    HRESULT __stdcall get_IsDefaultGeopositionRecommended(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDefaultGeopositionRecommended());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DefaultGeoposition(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Devices::Geolocation::BasicGeoposition>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DefaultGeoposition(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Devices::Geolocation::BasicGeoposition> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DefaultGeoposition(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Devices::Geolocation::BasicGeoposition>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DefaultGeoposition());
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
struct produce<D, Windows::Devices::Geolocation::IGeolocatorWithScalarAccuracy> : produce_base<D, Windows::Devices::Geolocation::IGeolocatorWithScalarAccuracy>
{
    HRESULT __stdcall get_DesiredAccuracyInMeters(impl::abi_arg_out<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DesiredAccuracyInMeters());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DesiredAccuracyInMeters(impl::abi_arg_in<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DesiredAccuracyInMeters(*reinterpret_cast<const Windows::Foundation::IReference<uint32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Geolocation::IGeopath> : produce_base<D, Windows::Devices::Geolocation::IGeopath>
{
    HRESULT __stdcall get_Positions(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Geolocation::BasicGeoposition>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Positions());
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
struct produce<D, Windows::Devices::Geolocation::IGeopathFactory> : produce_base<D, Windows::Devices::Geolocation::IGeopathFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Devices::Geolocation::BasicGeoposition>> positions, impl::abi_arg_out<Windows::Devices::Geolocation::IGeopath> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Devices::Geolocation::BasicGeoposition> *>(&positions)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithAltitudeReference(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Devices::Geolocation::BasicGeoposition>> positions, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem, impl::abi_arg_out<Windows::Devices::Geolocation::IGeopath> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateWithAltitudeReference(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Devices::Geolocation::BasicGeoposition> *>(&positions), altitudeReferenceSystem));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithAltitudeReferenceAndSpatialReference(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Devices::Geolocation::BasicGeoposition>> positions, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem, uint32_t spatialReferenceId, impl::abi_arg_out<Windows::Devices::Geolocation::IGeopath> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateWithAltitudeReferenceAndSpatialReference(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Devices::Geolocation::BasicGeoposition> *>(&positions), altitudeReferenceSystem, spatialReferenceId));
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
struct produce<D, Windows::Devices::Geolocation::IGeopoint> : produce_base<D, Windows::Devices::Geolocation::IGeopoint>
{
    HRESULT __stdcall get_Position(impl::abi_arg_out<Windows::Devices::Geolocation::BasicGeoposition> value) noexcept override
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
};

template <typename D>
struct produce<D, Windows::Devices::Geolocation::IGeopointFactory> : produce_base<D, Windows::Devices::Geolocation::IGeopointFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Devices::Geolocation::BasicGeoposition> position, impl::abi_arg_out<Windows::Devices::Geolocation::IGeopoint> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Devices::Geolocation::BasicGeoposition *>(&position)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithAltitudeReferenceSystem(impl::abi_arg_in<Windows::Devices::Geolocation::BasicGeoposition> position, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem, impl::abi_arg_out<Windows::Devices::Geolocation::IGeopoint> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateWithAltitudeReferenceSystem(*reinterpret_cast<const Windows::Devices::Geolocation::BasicGeoposition *>(&position), altitudeReferenceSystem));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithAltitudeReferenceSystemAndSpatialReferenceId(impl::abi_arg_in<Windows::Devices::Geolocation::BasicGeoposition> position, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem, uint32_t spatialReferenceId, impl::abi_arg_out<Windows::Devices::Geolocation::IGeopoint> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateWithAltitudeReferenceSystemAndSpatialReferenceId(*reinterpret_cast<const Windows::Devices::Geolocation::BasicGeoposition *>(&position), altitudeReferenceSystem, spatialReferenceId));
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
struct produce<D, Windows::Devices::Geolocation::IGeoposition> : produce_base<D, Windows::Devices::Geolocation::IGeoposition>
{
    HRESULT __stdcall get_Coordinate(impl::abi_arg_out<Windows::Devices::Geolocation::IGeocoordinate> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Coordinate());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CivicAddress(impl::abi_arg_out<Windows::Devices::Geolocation::ICivicAddress> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CivicAddress());
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
struct produce<D, Windows::Devices::Geolocation::IGeoposition2> : produce_base<D, Windows::Devices::Geolocation::IGeoposition2>
{
    HRESULT __stdcall get_VenueData(impl::abi_arg_out<Windows::Devices::Geolocation::IVenueData> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VenueData());
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
struct produce<D, Windows::Devices::Geolocation::IGeoshape> : produce_base<D, Windows::Devices::Geolocation::IGeoshape>
{
    HRESULT __stdcall get_GeoshapeType(Windows::Devices::Geolocation::GeoshapeType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GeoshapeType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SpatialReferenceId(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SpatialReferenceId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AltitudeReferenceSystem(Windows::Devices::Geolocation::AltitudeReferenceSystem * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AltitudeReferenceSystem());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Geolocation::IPositionChangedEventArgs> : produce_base<D, Windows::Devices::Geolocation::IPositionChangedEventArgs>
{
    HRESULT __stdcall get_Position(impl::abi_arg_out<Windows::Devices::Geolocation::IGeoposition> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Position());
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
struct produce<D, Windows::Devices::Geolocation::IStatusChangedEventArgs> : produce_base<D, Windows::Devices::Geolocation::IStatusChangedEventArgs>
{
    HRESULT __stdcall get_Status(Windows::Devices::Geolocation::PositionStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Geolocation::IVenueData> : produce_base<D, Windows::Devices::Geolocation::IVenueData>
{
    HRESULT __stdcall get_Id(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Level(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Level());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Devices::Geolocation {

template <typename D> Windows::Devices::Geolocation::GeoshapeType impl_IGeoshape<D>::GeoshapeType() const
{
    Windows::Devices::Geolocation::GeoshapeType value {};
    check_hresult(WINRT_SHIM(IGeoshape)->get_GeoshapeType(&value));
    return value;
}

template <typename D> uint32_t impl_IGeoshape<D>::SpatialReferenceId() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IGeoshape)->get_SpatialReferenceId(&value));
    return value;
}

template <typename D> Windows::Devices::Geolocation::AltitudeReferenceSystem impl_IGeoshape<D>::AltitudeReferenceSystem() const
{
    Windows::Devices::Geolocation::AltitudeReferenceSystem value {};
    check_hresult(WINRT_SHIM(IGeoshape)->get_AltitudeReferenceSystem(&value));
    return value;
}

template <typename D> Windows::Devices::Geolocation::BasicGeoposition impl_IGeopoint<D>::Position() const
{
    Windows::Devices::Geolocation::BasicGeoposition value {};
    check_hresult(WINRT_SHIM(IGeopoint)->get_Position(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geopoint impl_IGeopointFactory<D>::Create(const Windows::Devices::Geolocation::BasicGeoposition & position) const
{
    Windows::Devices::Geolocation::Geopoint value { nullptr };
    check_hresult(WINRT_SHIM(IGeopointFactory)->abi_Create(get_abi(position), put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geopoint impl_IGeopointFactory<D>::CreateWithAltitudeReferenceSystem(const Windows::Devices::Geolocation::BasicGeoposition & position, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem) const
{
    Windows::Devices::Geolocation::Geopoint value { nullptr };
    check_hresult(WINRT_SHIM(IGeopointFactory)->abi_CreateWithAltitudeReferenceSystem(get_abi(position), altitudeReferenceSystem, put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geopoint impl_IGeopointFactory<D>::CreateWithAltitudeReferenceSystemAndSpatialReferenceId(const Windows::Devices::Geolocation::BasicGeoposition & position, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem, uint32_t spatialReferenceId) const
{
    Windows::Devices::Geolocation::Geopoint value { nullptr };
    check_hresult(WINRT_SHIM(IGeopointFactory)->abi_CreateWithAltitudeReferenceSystemAndSpatialReferenceId(get_abi(position), altitudeReferenceSystem, spatialReferenceId, put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Geolocation::BasicGeoposition> impl_IGeopath<D>::Positions() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Geolocation::BasicGeoposition> value;
    check_hresult(WINRT_SHIM(IGeopath)->get_Positions(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geopath impl_IGeopathFactory<D>::Create(iterable<Windows::Devices::Geolocation::BasicGeoposition> positions) const
{
    Windows::Devices::Geolocation::Geopath value { nullptr };
    check_hresult(WINRT_SHIM(IGeopathFactory)->abi_Create(get_abi(positions), put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geopath impl_IGeopathFactory<D>::CreateWithAltitudeReference(iterable<Windows::Devices::Geolocation::BasicGeoposition> positions, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem) const
{
    Windows::Devices::Geolocation::Geopath value { nullptr };
    check_hresult(WINRT_SHIM(IGeopathFactory)->abi_CreateWithAltitudeReference(get_abi(positions), altitudeReferenceSystem, put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geopath impl_IGeopathFactory<D>::CreateWithAltitudeReferenceAndSpatialReference(iterable<Windows::Devices::Geolocation::BasicGeoposition> positions, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem, uint32_t spatialReferenceId) const
{
    Windows::Devices::Geolocation::Geopath value { nullptr };
    check_hresult(WINRT_SHIM(IGeopathFactory)->abi_CreateWithAltitudeReferenceAndSpatialReference(get_abi(positions), altitudeReferenceSystem, spatialReferenceId, put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::BasicGeoposition impl_IGeoboundingBox<D>::NorthwestCorner() const
{
    Windows::Devices::Geolocation::BasicGeoposition value {};
    check_hresult(WINRT_SHIM(IGeoboundingBox)->get_NorthwestCorner(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::BasicGeoposition impl_IGeoboundingBox<D>::SoutheastCorner() const
{
    Windows::Devices::Geolocation::BasicGeoposition value {};
    check_hresult(WINRT_SHIM(IGeoboundingBox)->get_SoutheastCorner(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::BasicGeoposition impl_IGeoboundingBox<D>::Center() const
{
    Windows::Devices::Geolocation::BasicGeoposition value {};
    check_hresult(WINRT_SHIM(IGeoboundingBox)->get_Center(put_abi(value)));
    return value;
}

template <typename D> double impl_IGeoboundingBox<D>::MinAltitude() const
{
    double value {};
    check_hresult(WINRT_SHIM(IGeoboundingBox)->get_MinAltitude(&value));
    return value;
}

template <typename D> double impl_IGeoboundingBox<D>::MaxAltitude() const
{
    double value {};
    check_hresult(WINRT_SHIM(IGeoboundingBox)->get_MaxAltitude(&value));
    return value;
}

template <typename D> Windows::Devices::Geolocation::GeoboundingBox impl_IGeoboundingBoxFactory<D>::Create(const Windows::Devices::Geolocation::BasicGeoposition & northwestCorner, const Windows::Devices::Geolocation::BasicGeoposition & southeastCorner) const
{
    Windows::Devices::Geolocation::GeoboundingBox value { nullptr };
    check_hresult(WINRT_SHIM(IGeoboundingBoxFactory)->abi_Create(get_abi(northwestCorner), get_abi(southeastCorner), put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::GeoboundingBox impl_IGeoboundingBoxFactory<D>::CreateWithAltitudeReference(const Windows::Devices::Geolocation::BasicGeoposition & northwestCorner, const Windows::Devices::Geolocation::BasicGeoposition & southeastCorner, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem) const
{
    Windows::Devices::Geolocation::GeoboundingBox value { nullptr };
    check_hresult(WINRT_SHIM(IGeoboundingBoxFactory)->abi_CreateWithAltitudeReference(get_abi(northwestCorner), get_abi(southeastCorner), altitudeReferenceSystem, put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::GeoboundingBox impl_IGeoboundingBoxFactory<D>::CreateWithAltitudeReferenceAndSpatialReference(const Windows::Devices::Geolocation::BasicGeoposition & northwestCorner, const Windows::Devices::Geolocation::BasicGeoposition & southeastCorner, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem, uint32_t spatialReferenceId) const
{
    Windows::Devices::Geolocation::GeoboundingBox value { nullptr };
    check_hresult(WINRT_SHIM(IGeoboundingBoxFactory)->abi_CreateWithAltitudeReferenceAndSpatialReference(get_abi(northwestCorner), get_abi(southeastCorner), altitudeReferenceSystem, spatialReferenceId, put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::GeoboundingBox impl_IGeoboundingBoxStatics<D>::TryCompute(iterable<Windows::Devices::Geolocation::BasicGeoposition> positions) const
{
    Windows::Devices::Geolocation::GeoboundingBox value { nullptr };
    check_hresult(WINRT_SHIM(IGeoboundingBoxStatics)->abi_TryCompute(get_abi(positions), put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::GeoboundingBox impl_IGeoboundingBoxStatics<D>::TryCompute(iterable<Windows::Devices::Geolocation::BasicGeoposition> positions, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeRefSystem) const
{
    Windows::Devices::Geolocation::GeoboundingBox value { nullptr };
    check_hresult(WINRT_SHIM(IGeoboundingBoxStatics)->abi_TryComputeWithAltitudeReference(get_abi(positions), altitudeRefSystem, put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::GeoboundingBox impl_IGeoboundingBoxStatics<D>::TryCompute(iterable<Windows::Devices::Geolocation::BasicGeoposition> positions, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeRefSystem, uint32_t spatialReferenceId) const
{
    Windows::Devices::Geolocation::GeoboundingBox value { nullptr };
    check_hresult(WINRT_SHIM(IGeoboundingBoxStatics)->abi_TryComputeWithAltitudeReferenceAndSpatialReference(get_abi(positions), altitudeRefSystem, spatialReferenceId, put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<double> impl_IGeocoordinateSatelliteData<D>::PositionDilutionOfPrecision() const
{
    Windows::Foundation::IReference<double> ppValue;
    check_hresult(WINRT_SHIM(IGeocoordinateSatelliteData)->get_PositionDilutionOfPrecision(put_abi(ppValue)));
    return ppValue;
}

template <typename D> Windows::Foundation::IReference<double> impl_IGeocoordinateSatelliteData<D>::HorizontalDilutionOfPrecision() const
{
    Windows::Foundation::IReference<double> ppValue;
    check_hresult(WINRT_SHIM(IGeocoordinateSatelliteData)->get_HorizontalDilutionOfPrecision(put_abi(ppValue)));
    return ppValue;
}

template <typename D> Windows::Foundation::IReference<double> impl_IGeocoordinateSatelliteData<D>::VerticalDilutionOfPrecision() const
{
    Windows::Foundation::IReference<double> ppValue;
    check_hresult(WINRT_SHIM(IGeocoordinateSatelliteData)->get_VerticalDilutionOfPrecision(put_abi(ppValue)));
    return ppValue;
}

template <typename D> hstring impl_IVenueData<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVenueData)->get_Id(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IVenueData<D>::Level() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVenueData)->get_Level(put_abi(value)));
    return value;
}

template <typename D> double impl_IGeocoordinate<D>::Latitude() const
{
    double value {};
    check_hresult(WINRT_SHIM(IGeocoordinate)->get_Latitude(&value));
    return value;
}

template <typename D> double impl_IGeocoordinate<D>::Longitude() const
{
    double value {};
    check_hresult(WINRT_SHIM(IGeocoordinate)->get_Longitude(&value));
    return value;
}

template <typename D> Windows::Foundation::IReference<double> impl_IGeocoordinate<D>::Altitude() const
{
    Windows::Foundation::IReference<double> value;
    check_hresult(WINRT_SHIM(IGeocoordinate)->get_Altitude(put_abi(value)));
    return value;
}

template <typename D> double impl_IGeocoordinate<D>::Accuracy() const
{
    double value {};
    check_hresult(WINRT_SHIM(IGeocoordinate)->get_Accuracy(&value));
    return value;
}

template <typename D> Windows::Foundation::IReference<double> impl_IGeocoordinate<D>::AltitudeAccuracy() const
{
    Windows::Foundation::IReference<double> value;
    check_hresult(WINRT_SHIM(IGeocoordinate)->get_AltitudeAccuracy(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<double> impl_IGeocoordinate<D>::Heading() const
{
    Windows::Foundation::IReference<double> value;
    check_hresult(WINRT_SHIM(IGeocoordinate)->get_Heading(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<double> impl_IGeocoordinate<D>::Speed() const
{
    Windows::Foundation::IReference<double> value;
    check_hresult(WINRT_SHIM(IGeocoordinate)->get_Speed(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IGeocoordinate<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IGeocoordinate)->get_Timestamp(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::PositionSource impl_IGeocoordinateWithPositionData<D>::PositionSource() const
{
    Windows::Devices::Geolocation::PositionSource pValue {};
    check_hresult(WINRT_SHIM(IGeocoordinateWithPositionData)->get_PositionSource(&pValue));
    return pValue;
}

template <typename D> Windows::Devices::Geolocation::GeocoordinateSatelliteData impl_IGeocoordinateWithPositionData<D>::SatelliteData() const
{
    Windows::Devices::Geolocation::GeocoordinateSatelliteData ppValue { nullptr };
    check_hresult(WINRT_SHIM(IGeocoordinateWithPositionData)->get_SatelliteData(put_abi(ppValue)));
    return ppValue;
}

template <typename D> Windows::Devices::Geolocation::Geopoint impl_IGeocoordinateWithPoint<D>::Point() const
{
    Windows::Devices::Geolocation::Geopoint value { nullptr };
    check_hresult(WINRT_SHIM(IGeocoordinateWithPoint)->get_Point(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IGeocoordinateWithPositionSourceTimestamp<D>::PositionSourceTimestamp() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(IGeocoordinateWithPositionSourceTimestamp)->get_PositionSourceTimestamp(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geocoordinate impl_IGeoposition<D>::Coordinate() const
{
    Windows::Devices::Geolocation::Geocoordinate value { nullptr };
    check_hresult(WINRT_SHIM(IGeoposition)->get_Coordinate(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::CivicAddress impl_IGeoposition<D>::CivicAddress() const
{
    Windows::Devices::Geolocation::CivicAddress value { nullptr };
    check_hresult(WINRT_SHIM(IGeoposition)->get_CivicAddress(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::VenueData impl_IGeoposition2<D>::VenueData() const
{
    Windows::Devices::Geolocation::VenueData value { nullptr };
    check_hresult(WINRT_SHIM(IGeoposition2)->get_VenueData(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICivicAddress<D>::Country() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICivicAddress)->get_Country(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICivicAddress<D>::State() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICivicAddress)->get_State(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICivicAddress<D>::City() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICivicAddress)->get_City(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICivicAddress<D>::PostalCode() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICivicAddress)->get_PostalCode(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_ICivicAddress<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(ICivicAddress)->get_Timestamp(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geoposition impl_IPositionChangedEventArgs<D>::Position() const
{
    Windows::Devices::Geolocation::Geoposition value { nullptr };
    check_hresult(WINRT_SHIM(IPositionChangedEventArgs)->get_Position(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::PositionStatus impl_IStatusChangedEventArgs<D>::Status() const
{
    Windows::Devices::Geolocation::PositionStatus value {};
    check_hresult(WINRT_SHIM(IStatusChangedEventArgs)->get_Status(&value));
    return value;
}

template <typename D> Windows::Devices::Geolocation::PositionAccuracy impl_IGeolocator<D>::DesiredAccuracy() const
{
    Windows::Devices::Geolocation::PositionAccuracy value {};
    check_hresult(WINRT_SHIM(IGeolocator)->get_DesiredAccuracy(&value));
    return value;
}

template <typename D> void impl_IGeolocator<D>::DesiredAccuracy(Windows::Devices::Geolocation::PositionAccuracy value) const
{
    check_hresult(WINRT_SHIM(IGeolocator)->put_DesiredAccuracy(value));
}

template <typename D> double impl_IGeolocator<D>::MovementThreshold() const
{
    double value {};
    check_hresult(WINRT_SHIM(IGeolocator)->get_MovementThreshold(&value));
    return value;
}

template <typename D> void impl_IGeolocator<D>::MovementThreshold(double value) const
{
    check_hresult(WINRT_SHIM(IGeolocator)->put_MovementThreshold(value));
}

template <typename D> uint32_t impl_IGeolocator<D>::ReportInterval() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IGeolocator)->get_ReportInterval(&value));
    return value;
}

template <typename D> void impl_IGeolocator<D>::ReportInterval(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IGeolocator)->put_ReportInterval(value));
}

template <typename D> Windows::Devices::Geolocation::PositionStatus impl_IGeolocator<D>::LocationStatus() const
{
    Windows::Devices::Geolocation::PositionStatus value {};
    check_hresult(WINRT_SHIM(IGeolocator)->get_LocationStatus(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Geolocation::Geoposition> impl_IGeolocator<D>::GetGeopositionAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Geolocation::Geoposition> value;
    check_hresult(WINRT_SHIM(IGeolocator)->abi_GetGeopositionAsync(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Geolocation::Geoposition> impl_IGeolocator<D>::GetGeopositionAsync(const Windows::Foundation::TimeSpan & maximumAge, const Windows::Foundation::TimeSpan & timeout) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Geolocation::Geoposition> value;
    check_hresult(WINRT_SHIM(IGeolocator)->abi_GetGeopositionAsyncWithAgeAndTimeout(get_abi(maximumAge), get_abi(timeout), put_abi(value)));
    return value;
}

template <typename D> event_token impl_IGeolocator<D>::PositionChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Geolocation::Geolocator, Windows::Devices::Geolocation::PositionChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IGeolocator)->add_PositionChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IGeolocator> impl_IGeolocator<D>::PositionChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Geolocation::Geolocator, Windows::Devices::Geolocation::PositionChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IGeolocator>(this, &ABI::Windows::Devices::Geolocation::IGeolocator::remove_PositionChanged, PositionChanged(handler));
}

template <typename D> void impl_IGeolocator<D>::PositionChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IGeolocator)->remove_PositionChanged(token));
}

template <typename D> event_token impl_IGeolocator<D>::StatusChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Geolocation::Geolocator, Windows::Devices::Geolocation::StatusChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IGeolocator)->add_StatusChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IGeolocator> impl_IGeolocator<D>::StatusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Geolocation::Geolocator, Windows::Devices::Geolocation::StatusChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IGeolocator>(this, &ABI::Windows::Devices::Geolocation::IGeolocator::remove_StatusChanged, StatusChanged(handler));
}

template <typename D> void impl_IGeolocator<D>::StatusChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IGeolocator)->remove_StatusChanged(token));
}

template <typename D> Windows::Foundation::IReference<uint32_t> impl_IGeolocatorWithScalarAccuracy<D>::DesiredAccuracyInMeters() const
{
    Windows::Foundation::IReference<uint32_t> value;
    check_hresult(WINRT_SHIM(IGeolocatorWithScalarAccuracy)->get_DesiredAccuracyInMeters(put_abi(value)));
    return value;
}

template <typename D> void impl_IGeolocatorWithScalarAccuracy<D>::DesiredAccuracyInMeters(const optional<uint32_t> & value) const
{
    check_hresult(WINRT_SHIM(IGeolocatorWithScalarAccuracy)->put_DesiredAccuracyInMeters(get_abi(value)));
}

template <typename D> void impl_IGeolocator2<D>::AllowFallbackToConsentlessPositions() const
{
    check_hresult(WINRT_SHIM(IGeolocator2)->abi_AllowFallbackToConsentlessPositions());
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Geolocation::GeolocationAccessStatus> impl_IGeolocatorStatics<D>::RequestAccessAsync() const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Geolocation::GeolocationAccessStatus> result;
    check_hresult(WINRT_SHIM(IGeolocatorStatics)->abi_RequestAccessAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Geolocation::Geoposition>> impl_IGeolocatorStatics<D>::GetGeopositionHistoryAsync(const Windows::Foundation::DateTime & startTime) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Geolocation::Geoposition>> result;
    check_hresult(WINRT_SHIM(IGeolocatorStatics)->abi_GetGeopositionHistoryAsync(get_abi(startTime), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Geolocation::Geoposition>> impl_IGeolocatorStatics<D>::GetGeopositionHistoryAsync(const Windows::Foundation::DateTime & startTime, const Windows::Foundation::TimeSpan & duration) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Geolocation::Geoposition>> result;
    check_hresult(WINRT_SHIM(IGeolocatorStatics)->abi_GetGeopositionHistoryWithDurationAsync(get_abi(startTime), get_abi(duration), put_abi(result)));
    return result;
}

template <typename D> bool impl_IGeolocatorStatics2<D>::IsDefaultGeopositionRecommended() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IGeolocatorStatics2)->get_IsDefaultGeopositionRecommended(&value));
    return value;
}

template <typename D> void impl_IGeolocatorStatics2<D>::DefaultGeoposition(const optional<Windows::Devices::Geolocation::BasicGeoposition> & value) const
{
    check_hresult(WINRT_SHIM(IGeolocatorStatics2)->put_DefaultGeoposition(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Devices::Geolocation::BasicGeoposition> impl_IGeolocatorStatics2<D>::DefaultGeoposition() const
{
    Windows::Foundation::IReference<Windows::Devices::Geolocation::BasicGeoposition> value;
    check_hresult(WINRT_SHIM(IGeolocatorStatics2)->get_DefaultGeoposition(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::BasicGeoposition impl_IGeocircle<D>::Center() const
{
    Windows::Devices::Geolocation::BasicGeoposition value {};
    check_hresult(WINRT_SHIM(IGeocircle)->get_Center(put_abi(value)));
    return value;
}

template <typename D> double impl_IGeocircle<D>::Radius() const
{
    double value {};
    check_hresult(WINRT_SHIM(IGeocircle)->get_Radius(&value));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geocircle impl_IGeocircleFactory<D>::Create(const Windows::Devices::Geolocation::BasicGeoposition & position, double radius) const
{
    Windows::Devices::Geolocation::Geocircle value { nullptr };
    check_hresult(WINRT_SHIM(IGeocircleFactory)->abi_Create(get_abi(position), radius, put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geocircle impl_IGeocircleFactory<D>::CreateWithAltitudeReferenceSystem(const Windows::Devices::Geolocation::BasicGeoposition & position, double radius, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem) const
{
    Windows::Devices::Geolocation::Geocircle value { nullptr };
    check_hresult(WINRT_SHIM(IGeocircleFactory)->abi_CreateWithAltitudeReferenceSystem(get_abi(position), radius, altitudeReferenceSystem, put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geocircle impl_IGeocircleFactory<D>::CreateWithAltitudeReferenceSystemAndSpatialReferenceId(const Windows::Devices::Geolocation::BasicGeoposition & position, double radius, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem, uint32_t spatialReferenceId) const
{
    Windows::Devices::Geolocation::Geocircle value { nullptr };
    check_hresult(WINRT_SHIM(IGeocircleFactory)->abi_CreateWithAltitudeReferenceSystemAndSpatialReferenceId(get_abi(position), radius, altitudeReferenceSystem, spatialReferenceId, put_abi(value)));
    return value;
}

inline GeoboundingBox::GeoboundingBox(const Windows::Devices::Geolocation::BasicGeoposition & northwestCorner, const Windows::Devices::Geolocation::BasicGeoposition & southeastCorner) :
    GeoboundingBox(get_activation_factory<GeoboundingBox, IGeoboundingBoxFactory>().Create(northwestCorner, southeastCorner))
{}

inline GeoboundingBox::GeoboundingBox(const Windows::Devices::Geolocation::BasicGeoposition & northwestCorner, const Windows::Devices::Geolocation::BasicGeoposition & southeastCorner, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem) :
    GeoboundingBox(get_activation_factory<GeoboundingBox, IGeoboundingBoxFactory>().CreateWithAltitudeReference(northwestCorner, southeastCorner, altitudeReferenceSystem))
{}

inline GeoboundingBox::GeoboundingBox(const Windows::Devices::Geolocation::BasicGeoposition & northwestCorner, const Windows::Devices::Geolocation::BasicGeoposition & southeastCorner, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem, uint32_t spatialReferenceId) :
    GeoboundingBox(get_activation_factory<GeoboundingBox, IGeoboundingBoxFactory>().CreateWithAltitudeReferenceAndSpatialReference(northwestCorner, southeastCorner, altitudeReferenceSystem, spatialReferenceId))
{}

inline Windows::Devices::Geolocation::GeoboundingBox GeoboundingBox::TryCompute(iterable<Windows::Devices::Geolocation::BasicGeoposition> positions)
{
    return get_activation_factory<GeoboundingBox, IGeoboundingBoxStatics>().TryCompute(positions);
}

inline Windows::Devices::Geolocation::GeoboundingBox GeoboundingBox::TryCompute(iterable<Windows::Devices::Geolocation::BasicGeoposition> positions, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeRefSystem)
{
    return get_activation_factory<GeoboundingBox, IGeoboundingBoxStatics>().TryCompute(positions, altitudeRefSystem);
}

inline Windows::Devices::Geolocation::GeoboundingBox GeoboundingBox::TryCompute(iterable<Windows::Devices::Geolocation::BasicGeoposition> positions, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeRefSystem, uint32_t spatialReferenceId)
{
    return get_activation_factory<GeoboundingBox, IGeoboundingBoxStatics>().TryCompute(positions, altitudeRefSystem, spatialReferenceId);
}

inline Geocircle::Geocircle(const Windows::Devices::Geolocation::BasicGeoposition & position, double radius) :
    Geocircle(get_activation_factory<Geocircle, IGeocircleFactory>().Create(position, radius))
{}

inline Geocircle::Geocircle(const Windows::Devices::Geolocation::BasicGeoposition & position, double radius, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem) :
    Geocircle(get_activation_factory<Geocircle, IGeocircleFactory>().CreateWithAltitudeReferenceSystem(position, radius, altitudeReferenceSystem))
{}

inline Geocircle::Geocircle(const Windows::Devices::Geolocation::BasicGeoposition & position, double radius, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem, uint32_t spatialReferenceId) :
    Geocircle(get_activation_factory<Geocircle, IGeocircleFactory>().CreateWithAltitudeReferenceSystemAndSpatialReferenceId(position, radius, altitudeReferenceSystem, spatialReferenceId))
{}

inline Geolocator::Geolocator() :
    Geolocator(activate_instance<Geolocator>())
{}

inline Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Geolocation::GeolocationAccessStatus> Geolocator::RequestAccessAsync()
{
    return get_activation_factory<Geolocator, IGeolocatorStatics>().RequestAccessAsync();
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Geolocation::Geoposition>> Geolocator::GetGeopositionHistoryAsync(const Windows::Foundation::DateTime & startTime)
{
    return get_activation_factory<Geolocator, IGeolocatorStatics>().GetGeopositionHistoryAsync(startTime);
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Geolocation::Geoposition>> Geolocator::GetGeopositionHistoryAsync(const Windows::Foundation::DateTime & startTime, const Windows::Foundation::TimeSpan & duration)
{
    return get_activation_factory<Geolocator, IGeolocatorStatics>().GetGeopositionHistoryAsync(startTime, duration);
}

inline bool Geolocator::IsDefaultGeopositionRecommended()
{
    return get_activation_factory<Geolocator, IGeolocatorStatics2>().IsDefaultGeopositionRecommended();
}

inline void Geolocator::DefaultGeoposition(const optional<Windows::Devices::Geolocation::BasicGeoposition> & value)
{
    get_activation_factory<Geolocator, IGeolocatorStatics2>().DefaultGeoposition(value);
}

inline Windows::Foundation::IReference<Windows::Devices::Geolocation::BasicGeoposition> Geolocator::DefaultGeoposition()
{
    return get_activation_factory<Geolocator, IGeolocatorStatics2>().DefaultGeoposition();
}

inline Geopath::Geopath(iterable<Windows::Devices::Geolocation::BasicGeoposition> positions) :
    Geopath(get_activation_factory<Geopath, IGeopathFactory>().Create(positions))
{}

inline Geopath::Geopath(iterable<Windows::Devices::Geolocation::BasicGeoposition> positions, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem) :
    Geopath(get_activation_factory<Geopath, IGeopathFactory>().CreateWithAltitudeReference(positions, altitudeReferenceSystem))
{}

inline Geopath::Geopath(iterable<Windows::Devices::Geolocation::BasicGeoposition> positions, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem, uint32_t spatialReferenceId) :
    Geopath(get_activation_factory<Geopath, IGeopathFactory>().CreateWithAltitudeReferenceAndSpatialReference(positions, altitudeReferenceSystem, spatialReferenceId))
{}

inline Geopoint::Geopoint(const Windows::Devices::Geolocation::BasicGeoposition & position) :
    Geopoint(get_activation_factory<Geopoint, IGeopointFactory>().Create(position))
{}

inline Geopoint::Geopoint(const Windows::Devices::Geolocation::BasicGeoposition & position, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem) :
    Geopoint(get_activation_factory<Geopoint, IGeopointFactory>().CreateWithAltitudeReferenceSystem(position, altitudeReferenceSystem))
{}

inline Geopoint::Geopoint(const Windows::Devices::Geolocation::BasicGeoposition & position, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem, uint32_t spatialReferenceId) :
    Geopoint(get_activation_factory<Geopoint, IGeopointFactory>().CreateWithAltitudeReferenceSystemAndSpatialReferenceId(position, altitudeReferenceSystem, spatialReferenceId))
{}

}

}
#pragma warning(pop)
