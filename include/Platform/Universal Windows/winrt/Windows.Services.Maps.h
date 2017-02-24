// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Devices.Geolocation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Services.Maps.3.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Services::Maps::IMapAddress> : produce_base<D, Windows::Services::Maps::IMapAddress>
{
    HRESULT __stdcall get_BuildingName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BuildingName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BuildingFloor(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BuildingFloor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BuildingRoom(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BuildingRoom());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BuildingWing(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BuildingWing());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StreetNumber(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StreetNumber());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Street(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Street());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Neighborhood(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Neighborhood());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_District(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().District());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Town(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Town());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Region(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Region());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RegionCode(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RegionCode());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall get_CountryCode(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CountryCode());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PostCode(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PostCode());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Continent(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Continent());
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
struct produce<D, Windows::Services::Maps::IMapAddress2> : produce_base<D, Windows::Services::Maps::IMapAddress2>
{
    HRESULT __stdcall get_FormattedAddress(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FormattedAddress());
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
struct produce<D, Windows::Services::Maps::IMapLocation> : produce_base<D, Windows::Services::Maps::IMapLocation>
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

    HRESULT __stdcall get_Description(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Description());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Address(impl::abi_arg_out<Windows::Services::Maps::IMapAddress> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Address());
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
struct produce<D, Windows::Services::Maps::IMapLocationFinderResult> : produce_base<D, Windows::Services::Maps::IMapLocationFinderResult>
{
    HRESULT __stdcall get_Locations(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::MapLocation>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Locations());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Status(Windows::Services::Maps::MapLocationFinderStatus * value) noexcept override
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
struct produce<D, Windows::Services::Maps::IMapLocationFinderStatics> : produce_base<D, Windows::Services::Maps::IMapLocationFinderStatics>
{
    HRESULT __stdcall abi_FindLocationsAtAsync(impl::abi_arg_in<Windows::Devices::Geolocation::IGeopoint> queryPoint, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapLocationFinderResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FindLocationsAtAsync(*reinterpret_cast<const Windows::Devices::Geolocation::Geopoint *>(&queryPoint)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindLocationsAsync(impl::abi_arg_in<hstring> searchText, impl::abi_arg_in<Windows::Devices::Geolocation::IGeopoint> referencePoint, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapLocationFinderResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FindLocationsAsync(*reinterpret_cast<const hstring *>(&searchText), *reinterpret_cast<const Windows::Devices::Geolocation::Geopoint *>(&referencePoint)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindLocationsWithMaxCountAsync(impl::abi_arg_in<hstring> searchText, impl::abi_arg_in<Windows::Devices::Geolocation::IGeopoint> referencePoint, uint32_t maxCount, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapLocationFinderResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FindLocationsAsync(*reinterpret_cast<const hstring *>(&searchText), *reinterpret_cast<const Windows::Devices::Geolocation::Geopoint *>(&referencePoint), maxCount));
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
struct produce<D, Windows::Services::Maps::IMapLocationFinderStatics2> : produce_base<D, Windows::Services::Maps::IMapLocationFinderStatics2>
{
    HRESULT __stdcall abi_FindLocationsAtWithAccuracyAsync(impl::abi_arg_in<Windows::Devices::Geolocation::IGeopoint> queryPoint, Windows::Services::Maps::MapLocationDesiredAccuracy accuracy, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapLocationFinderResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FindLocationsAtAsync(*reinterpret_cast<const Windows::Devices::Geolocation::Geopoint *>(&queryPoint), accuracy));
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
struct produce<D, Windows::Services::Maps::IMapManagerStatics> : produce_base<D, Windows::Services::Maps::IMapManagerStatics>
{
    HRESULT __stdcall abi_ShowDownloadedMapsUI() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowDownloadedMapsUI();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowMapsUpdateUI() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowMapsUpdateUI();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Services::Maps::IMapRoute> : produce_base<D, Windows::Services::Maps::IMapRoute>
{
    HRESULT __stdcall get_BoundingBox(impl::abi_arg_out<Windows::Devices::Geolocation::IGeoboundingBox> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BoundingBox());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LengthInMeters(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LengthInMeters());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EstimatedDuration(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EstimatedDuration());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall get_Legs(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::MapRouteLeg>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Legs());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsTrafficBased(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsTrafficBased());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Services::Maps::IMapRoute2> : produce_base<D, Windows::Services::Maps::IMapRoute2>
{
    HRESULT __stdcall get_ViolatedRestrictions(Windows::Services::Maps::MapRouteRestrictions * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ViolatedRestrictions());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HasBlockedRoads(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HasBlockedRoads());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Services::Maps::IMapRouteDrivingOptions> : produce_base<D, Windows::Services::Maps::IMapRouteDrivingOptions>
{
    HRESULT __stdcall get_MaxAlternateRouteCount(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxAlternateRouteCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxAlternateRouteCount(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxAlternateRouteCount(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InitialHeading(impl::abi_arg_out<Windows::Foundation::IReference<double>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InitialHeading());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_InitialHeading(impl::abi_arg_in<Windows::Foundation::IReference<double>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InitialHeading(*reinterpret_cast<const Windows::Foundation::IReference<double> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RouteOptimization(Windows::Services::Maps::MapRouteOptimization * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RouteOptimization());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RouteOptimization(Windows::Services::Maps::MapRouteOptimization value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RouteOptimization(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RouteRestrictions(Windows::Services::Maps::MapRouteRestrictions * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RouteRestrictions());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RouteRestrictions(Windows::Services::Maps::MapRouteRestrictions value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RouteRestrictions(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Services::Maps::IMapRouteFinderResult> : produce_base<D, Windows::Services::Maps::IMapRouteFinderResult>
{
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

    HRESULT __stdcall get_Status(Windows::Services::Maps::MapRouteFinderStatus * value) noexcept override
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
struct produce<D, Windows::Services::Maps::IMapRouteFinderResult2> : produce_base<D, Windows::Services::Maps::IMapRouteFinderResult2>
{
    HRESULT __stdcall get_AlternateRoutes(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::MapRoute>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AlternateRoutes());
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
struct produce<D, Windows::Services::Maps::IMapRouteFinderStatics> : produce_base<D, Windows::Services::Maps::IMapRouteFinderStatics>
{
    HRESULT __stdcall abi_GetDrivingRouteAsync(impl::abi_arg_in<Windows::Devices::Geolocation::IGeopoint> startPoint, impl::abi_arg_in<Windows::Devices::Geolocation::IGeopoint> endPoint, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDrivingRouteAsync(*reinterpret_cast<const Windows::Devices::Geolocation::Geopoint *>(&startPoint), *reinterpret_cast<const Windows::Devices::Geolocation::Geopoint *>(&endPoint)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDrivingRouteWithOptimizationAsync(impl::abi_arg_in<Windows::Devices::Geolocation::IGeopoint> startPoint, impl::abi_arg_in<Windows::Devices::Geolocation::IGeopoint> endPoint, Windows::Services::Maps::MapRouteOptimization optimization, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDrivingRouteAsync(*reinterpret_cast<const Windows::Devices::Geolocation::Geopoint *>(&startPoint), *reinterpret_cast<const Windows::Devices::Geolocation::Geopoint *>(&endPoint), optimization));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDrivingRouteWithOptimizationAndRestrictionsAsync(impl::abi_arg_in<Windows::Devices::Geolocation::IGeopoint> startPoint, impl::abi_arg_in<Windows::Devices::Geolocation::IGeopoint> endPoint, Windows::Services::Maps::MapRouteOptimization optimization, Windows::Services::Maps::MapRouteRestrictions restrictions, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDrivingRouteAsync(*reinterpret_cast<const Windows::Devices::Geolocation::Geopoint *>(&startPoint), *reinterpret_cast<const Windows::Devices::Geolocation::Geopoint *>(&endPoint), optimization, restrictions));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDrivingRouteWithOptimizationRestrictionsAndHeadingAsync(impl::abi_arg_in<Windows::Devices::Geolocation::IGeopoint> startPoint, impl::abi_arg_in<Windows::Devices::Geolocation::IGeopoint> endPoint, Windows::Services::Maps::MapRouteOptimization optimization, Windows::Services::Maps::MapRouteRestrictions restrictions, double headingInDegrees, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDrivingRouteAsync(*reinterpret_cast<const Windows::Devices::Geolocation::Geopoint *>(&startPoint), *reinterpret_cast<const Windows::Devices::Geolocation::Geopoint *>(&endPoint), optimization, restrictions, headingInDegrees));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDrivingRouteFromWaypointsAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Devices::Geolocation::Geopoint>> wayPoints, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDrivingRouteFromWaypointsAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Devices::Geolocation::Geopoint> *>(&wayPoints)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDrivingRouteFromWaypointsAndOptimizationAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Devices::Geolocation::Geopoint>> wayPoints, Windows::Services::Maps::MapRouteOptimization optimization, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDrivingRouteFromWaypointsAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Devices::Geolocation::Geopoint> *>(&wayPoints), optimization));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDrivingRouteFromWaypointsOptimizationAndRestrictionsAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Devices::Geolocation::Geopoint>> wayPoints, Windows::Services::Maps::MapRouteOptimization optimization, Windows::Services::Maps::MapRouteRestrictions restrictions, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDrivingRouteFromWaypointsAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Devices::Geolocation::Geopoint> *>(&wayPoints), optimization, restrictions));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDrivingRouteFromWaypointsOptimizationRestrictionsAndHeadingAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Devices::Geolocation::Geopoint>> wayPoints, Windows::Services::Maps::MapRouteOptimization optimization, Windows::Services::Maps::MapRouteRestrictions restrictions, double headingInDegrees, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDrivingRouteFromWaypointsAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Devices::Geolocation::Geopoint> *>(&wayPoints), optimization, restrictions, headingInDegrees));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetWalkingRouteAsync(impl::abi_arg_in<Windows::Devices::Geolocation::IGeopoint> startPoint, impl::abi_arg_in<Windows::Devices::Geolocation::IGeopoint> endPoint, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetWalkingRouteAsync(*reinterpret_cast<const Windows::Devices::Geolocation::Geopoint *>(&startPoint), *reinterpret_cast<const Windows::Devices::Geolocation::Geopoint *>(&endPoint)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetWalkingRouteFromWaypointsAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Devices::Geolocation::Geopoint>> wayPoints, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetWalkingRouteFromWaypointsAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Devices::Geolocation::Geopoint> *>(&wayPoints)));
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
struct produce<D, Windows::Services::Maps::IMapRouteFinderStatics2> : produce_base<D, Windows::Services::Maps::IMapRouteFinderStatics2>
{
    HRESULT __stdcall abi_GetDrivingRouteWithOptionsAsync(impl::abi_arg_in<Windows::Devices::Geolocation::IGeopoint> startPoint, impl::abi_arg_in<Windows::Devices::Geolocation::IGeopoint> endPoint, impl::abi_arg_in<Windows::Services::Maps::IMapRouteDrivingOptions> options, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDrivingRouteAsync(*reinterpret_cast<const Windows::Devices::Geolocation::Geopoint *>(&startPoint), *reinterpret_cast<const Windows::Devices::Geolocation::Geopoint *>(&endPoint), *reinterpret_cast<const Windows::Services::Maps::MapRouteDrivingOptions *>(&options)));
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
struct produce<D, Windows::Services::Maps::IMapRouteLeg> : produce_base<D, Windows::Services::Maps::IMapRouteLeg>
{
    HRESULT __stdcall get_BoundingBox(impl::abi_arg_out<Windows::Devices::Geolocation::IGeoboundingBox> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BoundingBox());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall get_LengthInMeters(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LengthInMeters());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EstimatedDuration(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EstimatedDuration());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Maneuvers(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::MapRouteManeuver>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Maneuvers());
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
struct produce<D, Windows::Services::Maps::IMapRouteManeuver> : produce_base<D, Windows::Services::Maps::IMapRouteManeuver>
{
    HRESULT __stdcall get_StartingPoint(impl::abi_arg_out<Windows::Devices::Geolocation::IGeopoint> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StartingPoint());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LengthInMeters(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LengthInMeters());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InstructionText(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InstructionText());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Kind(Windows::Services::Maps::MapRouteManeuverKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Kind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExitNumber(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExitNumber());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ManeuverNotices(Windows::Services::Maps::MapManeuverNotices * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ManeuverNotices());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Services::Maps::IMapRouteManeuver2> : produce_base<D, Windows::Services::Maps::IMapRouteManeuver2>
{
    HRESULT __stdcall get_StartHeading(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StartHeading());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EndHeading(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EndHeading());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StreetName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StreetName());
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
struct produce<D, Windows::Services::Maps::IMapServiceStatics> : produce_base<D, Windows::Services::Maps::IMapServiceStatics>
{
    HRESULT __stdcall put_ServiceToken(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ServiceToken(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServiceToken(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServiceToken());
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
struct produce<D, Windows::Services::Maps::IMapServiceStatics2> : produce_base<D, Windows::Services::Maps::IMapServiceStatics2>
{
    HRESULT __stdcall get_WorldViewRegionCode(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WorldViewRegionCode());
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
struct produce<D, Windows::Services::Maps::IMapServiceStatics3> : produce_base<D, Windows::Services::Maps::IMapServiceStatics3>
{
    HRESULT __stdcall get_DataAttributions(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DataAttributions());
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

namespace Windows::Services::Maps {

template <typename D> uint32_t impl_IMapRouteDrivingOptions<D>::MaxAlternateRouteCount() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMapRouteDrivingOptions)->get_MaxAlternateRouteCount(&value));
    return value;
}

template <typename D> void impl_IMapRouteDrivingOptions<D>::MaxAlternateRouteCount(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IMapRouteDrivingOptions)->put_MaxAlternateRouteCount(value));
}

template <typename D> Windows::Foundation::IReference<double> impl_IMapRouteDrivingOptions<D>::InitialHeading() const
{
    Windows::Foundation::IReference<double> value;
    check_hresult(WINRT_SHIM(IMapRouteDrivingOptions)->get_InitialHeading(put_abi(value)));
    return value;
}

template <typename D> void impl_IMapRouteDrivingOptions<D>::InitialHeading(const optional<double> & value) const
{
    check_hresult(WINRT_SHIM(IMapRouteDrivingOptions)->put_InitialHeading(get_abi(value)));
}

template <typename D> Windows::Services::Maps::MapRouteOptimization impl_IMapRouteDrivingOptions<D>::RouteOptimization() const
{
    Windows::Services::Maps::MapRouteOptimization value {};
    check_hresult(WINRT_SHIM(IMapRouteDrivingOptions)->get_RouteOptimization(&value));
    return value;
}

template <typename D> void impl_IMapRouteDrivingOptions<D>::RouteOptimization(Windows::Services::Maps::MapRouteOptimization value) const
{
    check_hresult(WINRT_SHIM(IMapRouteDrivingOptions)->put_RouteOptimization(value));
}

template <typename D> Windows::Services::Maps::MapRouteRestrictions impl_IMapRouteDrivingOptions<D>::RouteRestrictions() const
{
    Windows::Services::Maps::MapRouteRestrictions value {};
    check_hresult(WINRT_SHIM(IMapRouteDrivingOptions)->get_RouteRestrictions(&value));
    return value;
}

template <typename D> void impl_IMapRouteDrivingOptions<D>::RouteRestrictions(Windows::Services::Maps::MapRouteRestrictions value) const
{
    check_hresult(WINRT_SHIM(IMapRouteDrivingOptions)->put_RouteRestrictions(value));
}

template <typename D> hstring impl_IMapAddress<D>::BuildingName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMapAddress)->get_BuildingName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMapAddress<D>::BuildingFloor() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMapAddress)->get_BuildingFloor(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMapAddress<D>::BuildingRoom() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMapAddress)->get_BuildingRoom(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMapAddress<D>::BuildingWing() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMapAddress)->get_BuildingWing(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMapAddress<D>::StreetNumber() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMapAddress)->get_StreetNumber(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMapAddress<D>::Street() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMapAddress)->get_Street(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMapAddress<D>::Neighborhood() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMapAddress)->get_Neighborhood(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMapAddress<D>::District() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMapAddress)->get_District(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMapAddress<D>::Town() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMapAddress)->get_Town(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMapAddress<D>::Region() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMapAddress)->get_Region(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMapAddress<D>::RegionCode() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMapAddress)->get_RegionCode(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMapAddress<D>::Country() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMapAddress)->get_Country(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMapAddress<D>::CountryCode() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMapAddress)->get_CountryCode(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMapAddress<D>::PostCode() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMapAddress)->get_PostCode(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMapAddress<D>::Continent() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMapAddress)->get_Continent(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMapAddress2<D>::FormattedAddress() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMapAddress2)->get_FormattedAddress(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geopoint impl_IMapLocation<D>::Point() const
{
    Windows::Devices::Geolocation::Geopoint value { nullptr };
    check_hresult(WINRT_SHIM(IMapLocation)->get_Point(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMapLocation<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMapLocation)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMapLocation<D>::Description() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMapLocation)->get_Description(put_abi(value)));
    return value;
}

template <typename D> Windows::Services::Maps::MapAddress impl_IMapLocation<D>::Address() const
{
    Windows::Services::Maps::MapAddress value { nullptr };
    check_hresult(WINRT_SHIM(IMapLocation)->get_Address(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::MapLocation> impl_IMapLocationFinderResult<D>::Locations() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::MapLocation> value;
    check_hresult(WINRT_SHIM(IMapLocationFinderResult)->get_Locations(put_abi(value)));
    return value;
}

template <typename D> Windows::Services::Maps::MapLocationFinderStatus impl_IMapLocationFinderResult<D>::Status() const
{
    Windows::Services::Maps::MapLocationFinderStatus value {};
    check_hresult(WINRT_SHIM(IMapLocationFinderResult)->get_Status(&value));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geopoint impl_IMapRouteManeuver<D>::StartingPoint() const
{
    Windows::Devices::Geolocation::Geopoint value { nullptr };
    check_hresult(WINRT_SHIM(IMapRouteManeuver)->get_StartingPoint(put_abi(value)));
    return value;
}

template <typename D> double impl_IMapRouteManeuver<D>::LengthInMeters() const
{
    double value {};
    check_hresult(WINRT_SHIM(IMapRouteManeuver)->get_LengthInMeters(&value));
    return value;
}

template <typename D> hstring impl_IMapRouteManeuver<D>::InstructionText() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMapRouteManeuver)->get_InstructionText(put_abi(value)));
    return value;
}

template <typename D> Windows::Services::Maps::MapRouteManeuverKind impl_IMapRouteManeuver<D>::Kind() const
{
    Windows::Services::Maps::MapRouteManeuverKind value {};
    check_hresult(WINRT_SHIM(IMapRouteManeuver)->get_Kind(&value));
    return value;
}

template <typename D> hstring impl_IMapRouteManeuver<D>::ExitNumber() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMapRouteManeuver)->get_ExitNumber(put_abi(value)));
    return value;
}

template <typename D> Windows::Services::Maps::MapManeuverNotices impl_IMapRouteManeuver<D>::ManeuverNotices() const
{
    Windows::Services::Maps::MapManeuverNotices value {};
    check_hresult(WINRT_SHIM(IMapRouteManeuver)->get_ManeuverNotices(&value));
    return value;
}

template <typename D> double impl_IMapRouteManeuver2<D>::StartHeading() const
{
    double value {};
    check_hresult(WINRT_SHIM(IMapRouteManeuver2)->get_StartHeading(&value));
    return value;
}

template <typename D> double impl_IMapRouteManeuver2<D>::EndHeading() const
{
    double value {};
    check_hresult(WINRT_SHIM(IMapRouteManeuver2)->get_EndHeading(&value));
    return value;
}

template <typename D> hstring impl_IMapRouteManeuver2<D>::StreetName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMapRouteManeuver2)->get_StreetName(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::GeoboundingBox impl_IMapRouteLeg<D>::BoundingBox() const
{
    Windows::Devices::Geolocation::GeoboundingBox value { nullptr };
    check_hresult(WINRT_SHIM(IMapRouteLeg)->get_BoundingBox(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geopath impl_IMapRouteLeg<D>::Path() const
{
    Windows::Devices::Geolocation::Geopath value { nullptr };
    check_hresult(WINRT_SHIM(IMapRouteLeg)->get_Path(put_abi(value)));
    return value;
}

template <typename D> double impl_IMapRouteLeg<D>::LengthInMeters() const
{
    double value {};
    check_hresult(WINRT_SHIM(IMapRouteLeg)->get_LengthInMeters(&value));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IMapRouteLeg<D>::EstimatedDuration() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMapRouteLeg)->get_EstimatedDuration(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::MapRouteManeuver> impl_IMapRouteLeg<D>::Maneuvers() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::MapRouteManeuver> value;
    check_hresult(WINRT_SHIM(IMapRouteLeg)->get_Maneuvers(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::GeoboundingBox impl_IMapRoute<D>::BoundingBox() const
{
    Windows::Devices::Geolocation::GeoboundingBox value { nullptr };
    check_hresult(WINRT_SHIM(IMapRoute)->get_BoundingBox(put_abi(value)));
    return value;
}

template <typename D> double impl_IMapRoute<D>::LengthInMeters() const
{
    double value {};
    check_hresult(WINRT_SHIM(IMapRoute)->get_LengthInMeters(&value));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IMapRoute<D>::EstimatedDuration() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMapRoute)->get_EstimatedDuration(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geopath impl_IMapRoute<D>::Path() const
{
    Windows::Devices::Geolocation::Geopath value { nullptr };
    check_hresult(WINRT_SHIM(IMapRoute)->get_Path(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::MapRouteLeg> impl_IMapRoute<D>::Legs() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::MapRouteLeg> value;
    check_hresult(WINRT_SHIM(IMapRoute)->get_Legs(put_abi(value)));
    return value;
}

template <typename D> bool impl_IMapRoute<D>::IsTrafficBased() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMapRoute)->get_IsTrafficBased(&value));
    return value;
}

template <typename D> Windows::Services::Maps::MapRouteRestrictions impl_IMapRoute2<D>::ViolatedRestrictions() const
{
    Windows::Services::Maps::MapRouteRestrictions value {};
    check_hresult(WINRT_SHIM(IMapRoute2)->get_ViolatedRestrictions(&value));
    return value;
}

template <typename D> bool impl_IMapRoute2<D>::HasBlockedRoads() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMapRoute2)->get_HasBlockedRoads(&value));
    return value;
}

template <typename D> Windows::Services::Maps::MapRoute impl_IMapRouteFinderResult<D>::Route() const
{
    Windows::Services::Maps::MapRoute value { nullptr };
    check_hresult(WINRT_SHIM(IMapRouteFinderResult)->get_Route(put_abi(value)));
    return value;
}

template <typename D> Windows::Services::Maps::MapRouteFinderStatus impl_IMapRouteFinderResult<D>::Status() const
{
    Windows::Services::Maps::MapRouteFinderStatus value {};
    check_hresult(WINRT_SHIM(IMapRouteFinderResult)->get_Status(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::MapRoute> impl_IMapRouteFinderResult2<D>::AlternateRoutes() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::MapRoute> value;
    check_hresult(WINRT_SHIM(IMapRouteFinderResult2)->get_AlternateRoutes(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapLocationFinderResult> impl_IMapLocationFinderStatics<D>::FindLocationsAtAsync(const Windows::Devices::Geolocation::Geopoint & queryPoint) const
{
    Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapLocationFinderResult> result;
    check_hresult(WINRT_SHIM(IMapLocationFinderStatics)->abi_FindLocationsAtAsync(get_abi(queryPoint), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapLocationFinderResult> impl_IMapLocationFinderStatics<D>::FindLocationsAsync(hstring_view searchText, const Windows::Devices::Geolocation::Geopoint & referencePoint) const
{
    Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapLocationFinderResult> result;
    check_hresult(WINRT_SHIM(IMapLocationFinderStatics)->abi_FindLocationsAsync(get_abi(searchText), get_abi(referencePoint), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapLocationFinderResult> impl_IMapLocationFinderStatics<D>::FindLocationsAsync(hstring_view searchText, const Windows::Devices::Geolocation::Geopoint & referencePoint, uint32_t maxCount) const
{
    Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapLocationFinderResult> result;
    check_hresult(WINRT_SHIM(IMapLocationFinderStatics)->abi_FindLocationsWithMaxCountAsync(get_abi(searchText), get_abi(referencePoint), maxCount, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapLocationFinderResult> impl_IMapLocationFinderStatics2<D>::FindLocationsAtAsync(const Windows::Devices::Geolocation::Geopoint & queryPoint, Windows::Services::Maps::MapLocationDesiredAccuracy accuracy) const
{
    Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapLocationFinderResult> result;
    check_hresult(WINRT_SHIM(IMapLocationFinderStatics2)->abi_FindLocationsAtWithAccuracyAsync(get_abi(queryPoint), accuracy, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> impl_IMapRouteFinderStatics<D>::GetDrivingRouteAsync(const Windows::Devices::Geolocation::Geopoint & startPoint, const Windows::Devices::Geolocation::Geopoint & endPoint) const
{
    Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> result;
    check_hresult(WINRT_SHIM(IMapRouteFinderStatics)->abi_GetDrivingRouteAsync(get_abi(startPoint), get_abi(endPoint), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> impl_IMapRouteFinderStatics<D>::GetDrivingRouteAsync(const Windows::Devices::Geolocation::Geopoint & startPoint, const Windows::Devices::Geolocation::Geopoint & endPoint, Windows::Services::Maps::MapRouteOptimization optimization) const
{
    Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> result;
    check_hresult(WINRT_SHIM(IMapRouteFinderStatics)->abi_GetDrivingRouteWithOptimizationAsync(get_abi(startPoint), get_abi(endPoint), optimization, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> impl_IMapRouteFinderStatics<D>::GetDrivingRouteAsync(const Windows::Devices::Geolocation::Geopoint & startPoint, const Windows::Devices::Geolocation::Geopoint & endPoint, Windows::Services::Maps::MapRouteOptimization optimization, Windows::Services::Maps::MapRouteRestrictions restrictions) const
{
    Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> result;
    check_hresult(WINRT_SHIM(IMapRouteFinderStatics)->abi_GetDrivingRouteWithOptimizationAndRestrictionsAsync(get_abi(startPoint), get_abi(endPoint), optimization, restrictions, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> impl_IMapRouteFinderStatics<D>::GetDrivingRouteAsync(const Windows::Devices::Geolocation::Geopoint & startPoint, const Windows::Devices::Geolocation::Geopoint & endPoint, Windows::Services::Maps::MapRouteOptimization optimization, Windows::Services::Maps::MapRouteRestrictions restrictions, double headingInDegrees) const
{
    Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> result;
    check_hresult(WINRT_SHIM(IMapRouteFinderStatics)->abi_GetDrivingRouteWithOptimizationRestrictionsAndHeadingAsync(get_abi(startPoint), get_abi(endPoint), optimization, restrictions, headingInDegrees, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> impl_IMapRouteFinderStatics<D>::GetDrivingRouteFromWaypointsAsync(iterable<Windows::Devices::Geolocation::Geopoint> wayPoints) const
{
    Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> result;
    check_hresult(WINRT_SHIM(IMapRouteFinderStatics)->abi_GetDrivingRouteFromWaypointsAsync(get_abi(wayPoints), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> impl_IMapRouteFinderStatics<D>::GetDrivingRouteFromWaypointsAsync(iterable<Windows::Devices::Geolocation::Geopoint> wayPoints, Windows::Services::Maps::MapRouteOptimization optimization) const
{
    Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> result;
    check_hresult(WINRT_SHIM(IMapRouteFinderStatics)->abi_GetDrivingRouteFromWaypointsAndOptimizationAsync(get_abi(wayPoints), optimization, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> impl_IMapRouteFinderStatics<D>::GetDrivingRouteFromWaypointsAsync(iterable<Windows::Devices::Geolocation::Geopoint> wayPoints, Windows::Services::Maps::MapRouteOptimization optimization, Windows::Services::Maps::MapRouteRestrictions restrictions) const
{
    Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> result;
    check_hresult(WINRT_SHIM(IMapRouteFinderStatics)->abi_GetDrivingRouteFromWaypointsOptimizationAndRestrictionsAsync(get_abi(wayPoints), optimization, restrictions, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> impl_IMapRouteFinderStatics<D>::GetDrivingRouteFromWaypointsAsync(iterable<Windows::Devices::Geolocation::Geopoint> wayPoints, Windows::Services::Maps::MapRouteOptimization optimization, Windows::Services::Maps::MapRouteRestrictions restrictions, double headingInDegrees) const
{
    Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> result;
    check_hresult(WINRT_SHIM(IMapRouteFinderStatics)->abi_GetDrivingRouteFromWaypointsOptimizationRestrictionsAndHeadingAsync(get_abi(wayPoints), optimization, restrictions, headingInDegrees, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> impl_IMapRouteFinderStatics<D>::GetWalkingRouteAsync(const Windows::Devices::Geolocation::Geopoint & startPoint, const Windows::Devices::Geolocation::Geopoint & endPoint) const
{
    Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> result;
    check_hresult(WINRT_SHIM(IMapRouteFinderStatics)->abi_GetWalkingRouteAsync(get_abi(startPoint), get_abi(endPoint), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> impl_IMapRouteFinderStatics<D>::GetWalkingRouteFromWaypointsAsync(iterable<Windows::Devices::Geolocation::Geopoint> wayPoints) const
{
    Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> result;
    check_hresult(WINRT_SHIM(IMapRouteFinderStatics)->abi_GetWalkingRouteFromWaypointsAsync(get_abi(wayPoints), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> impl_IMapRouteFinderStatics2<D>::GetDrivingRouteAsync(const Windows::Devices::Geolocation::Geopoint & startPoint, const Windows::Devices::Geolocation::Geopoint & endPoint, const Windows::Services::Maps::MapRouteDrivingOptions & options) const
{
    Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> result;
    check_hresult(WINRT_SHIM(IMapRouteFinderStatics2)->abi_GetDrivingRouteWithOptionsAsync(get_abi(startPoint), get_abi(endPoint), get_abi(options), put_abi(result)));
    return result;
}

template <typename D> void impl_IMapServiceStatics<D>::ServiceToken(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IMapServiceStatics)->put_ServiceToken(get_abi(value)));
}

template <typename D> hstring impl_IMapServiceStatics<D>::ServiceToken() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMapServiceStatics)->get_ServiceToken(put_abi(value)));
    return value;
}

template <typename D> void impl_IMapManagerStatics<D>::ShowDownloadedMapsUI() const
{
    check_hresult(WINRT_SHIM(IMapManagerStatics)->abi_ShowDownloadedMapsUI());
}

template <typename D> void impl_IMapManagerStatics<D>::ShowMapsUpdateUI() const
{
    check_hresult(WINRT_SHIM(IMapManagerStatics)->abi_ShowMapsUpdateUI());
}

template <typename D> hstring impl_IMapServiceStatics2<D>::WorldViewRegionCode() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMapServiceStatics2)->get_WorldViewRegionCode(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMapServiceStatics3<D>::DataAttributions() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMapServiceStatics3)->get_DataAttributions(put_abi(value)));
    return value;
}

inline Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapLocationFinderResult> MapLocationFinder::FindLocationsAtAsync(const Windows::Devices::Geolocation::Geopoint & queryPoint)
{
    return get_activation_factory<MapLocationFinder, IMapLocationFinderStatics>().FindLocationsAtAsync(queryPoint);
}

inline Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapLocationFinderResult> MapLocationFinder::FindLocationsAsync(hstring_view searchText, const Windows::Devices::Geolocation::Geopoint & referencePoint)
{
    return get_activation_factory<MapLocationFinder, IMapLocationFinderStatics>().FindLocationsAsync(searchText, referencePoint);
}

inline Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapLocationFinderResult> MapLocationFinder::FindLocationsAsync(hstring_view searchText, const Windows::Devices::Geolocation::Geopoint & referencePoint, uint32_t maxCount)
{
    return get_activation_factory<MapLocationFinder, IMapLocationFinderStatics>().FindLocationsAsync(searchText, referencePoint, maxCount);
}

inline Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapLocationFinderResult> MapLocationFinder::FindLocationsAtAsync(const Windows::Devices::Geolocation::Geopoint & queryPoint, Windows::Services::Maps::MapLocationDesiredAccuracy accuracy)
{
    return get_activation_factory<MapLocationFinder, IMapLocationFinderStatics2>().FindLocationsAtAsync(queryPoint, accuracy);
}

inline void MapManager::ShowDownloadedMapsUI()
{
    get_activation_factory<MapManager, IMapManagerStatics>().ShowDownloadedMapsUI();
}

inline void MapManager::ShowMapsUpdateUI()
{
    get_activation_factory<MapManager, IMapManagerStatics>().ShowMapsUpdateUI();
}

inline MapRouteDrivingOptions::MapRouteDrivingOptions() :
    MapRouteDrivingOptions(activate_instance<MapRouteDrivingOptions>())
{}

inline Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> MapRouteFinder::GetDrivingRouteAsync(const Windows::Devices::Geolocation::Geopoint & startPoint, const Windows::Devices::Geolocation::Geopoint & endPoint)
{
    return get_activation_factory<MapRouteFinder, IMapRouteFinderStatics>().GetDrivingRouteAsync(startPoint, endPoint);
}

inline Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> MapRouteFinder::GetDrivingRouteAsync(const Windows::Devices::Geolocation::Geopoint & startPoint, const Windows::Devices::Geolocation::Geopoint & endPoint, Windows::Services::Maps::MapRouteOptimization optimization)
{
    return get_activation_factory<MapRouteFinder, IMapRouteFinderStatics>().GetDrivingRouteAsync(startPoint, endPoint, optimization);
}

inline Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> MapRouteFinder::GetDrivingRouteAsync(const Windows::Devices::Geolocation::Geopoint & startPoint, const Windows::Devices::Geolocation::Geopoint & endPoint, Windows::Services::Maps::MapRouteOptimization optimization, Windows::Services::Maps::MapRouteRestrictions restrictions)
{
    return get_activation_factory<MapRouteFinder, IMapRouteFinderStatics>().GetDrivingRouteAsync(startPoint, endPoint, optimization, restrictions);
}

inline Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> MapRouteFinder::GetDrivingRouteAsync(const Windows::Devices::Geolocation::Geopoint & startPoint, const Windows::Devices::Geolocation::Geopoint & endPoint, Windows::Services::Maps::MapRouteOptimization optimization, Windows::Services::Maps::MapRouteRestrictions restrictions, double headingInDegrees)
{
    return get_activation_factory<MapRouteFinder, IMapRouteFinderStatics>().GetDrivingRouteAsync(startPoint, endPoint, optimization, restrictions, headingInDegrees);
}

inline Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> MapRouteFinder::GetDrivingRouteFromWaypointsAsync(iterable<Windows::Devices::Geolocation::Geopoint> wayPoints)
{
    return get_activation_factory<MapRouteFinder, IMapRouteFinderStatics>().GetDrivingRouteFromWaypointsAsync(wayPoints);
}

inline Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> MapRouteFinder::GetDrivingRouteFromWaypointsAsync(iterable<Windows::Devices::Geolocation::Geopoint> wayPoints, Windows::Services::Maps::MapRouteOptimization optimization)
{
    return get_activation_factory<MapRouteFinder, IMapRouteFinderStatics>().GetDrivingRouteFromWaypointsAsync(wayPoints, optimization);
}

inline Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> MapRouteFinder::GetDrivingRouteFromWaypointsAsync(iterable<Windows::Devices::Geolocation::Geopoint> wayPoints, Windows::Services::Maps::MapRouteOptimization optimization, Windows::Services::Maps::MapRouteRestrictions restrictions)
{
    return get_activation_factory<MapRouteFinder, IMapRouteFinderStatics>().GetDrivingRouteFromWaypointsAsync(wayPoints, optimization, restrictions);
}

inline Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> MapRouteFinder::GetDrivingRouteFromWaypointsAsync(iterable<Windows::Devices::Geolocation::Geopoint> wayPoints, Windows::Services::Maps::MapRouteOptimization optimization, Windows::Services::Maps::MapRouteRestrictions restrictions, double headingInDegrees)
{
    return get_activation_factory<MapRouteFinder, IMapRouteFinderStatics>().GetDrivingRouteFromWaypointsAsync(wayPoints, optimization, restrictions, headingInDegrees);
}

inline Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> MapRouteFinder::GetWalkingRouteAsync(const Windows::Devices::Geolocation::Geopoint & startPoint, const Windows::Devices::Geolocation::Geopoint & endPoint)
{
    return get_activation_factory<MapRouteFinder, IMapRouteFinderStatics>().GetWalkingRouteAsync(startPoint, endPoint);
}

inline Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> MapRouteFinder::GetWalkingRouteFromWaypointsAsync(iterable<Windows::Devices::Geolocation::Geopoint> wayPoints)
{
    return get_activation_factory<MapRouteFinder, IMapRouteFinderStatics>().GetWalkingRouteFromWaypointsAsync(wayPoints);
}

inline Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> MapRouteFinder::GetDrivingRouteAsync(const Windows::Devices::Geolocation::Geopoint & startPoint, const Windows::Devices::Geolocation::Geopoint & endPoint, const Windows::Services::Maps::MapRouteDrivingOptions & options)
{
    return get_activation_factory<MapRouteFinder, IMapRouteFinderStatics2>().GetDrivingRouteAsync(startPoint, endPoint, options);
}

inline void MapService::ServiceToken(hstring_view value)
{
    get_activation_factory<MapService, IMapServiceStatics>().ServiceToken(value);
}

inline hstring MapService::ServiceToken()
{
    return get_activation_factory<MapService, IMapServiceStatics>().ServiceToken();
}

inline hstring MapService::WorldViewRegionCode()
{
    return get_activation_factory<MapService, IMapServiceStatics2>().WorldViewRegionCode();
}

inline hstring MapService::DataAttributions()
{
    return get_activation_factory<MapService, IMapServiceStatics3>().DataAttributions();
}

}

}
#pragma warning(pop)
