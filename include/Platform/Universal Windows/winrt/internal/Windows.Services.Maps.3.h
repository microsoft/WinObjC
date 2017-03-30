// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Services.Maps.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Services::Maps {

struct WINRT_EBO MapAddress :
    Windows::Services::Maps::IMapAddress,
    impl::require<MapAddress, Windows::Services::Maps::IMapAddress2>
{
    MapAddress(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MapLocation :
    Windows::Services::Maps::IMapLocation
{
    MapLocation(std::nullptr_t) noexcept {}
};

struct MapLocationFinder
{
    MapLocationFinder() = delete;
    static Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapLocationFinderResult> FindLocationsAtAsync(const Windows::Devices::Geolocation::Geopoint & queryPoint);
    static Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapLocationFinderResult> FindLocationsAsync(hstring_view searchText, const Windows::Devices::Geolocation::Geopoint & referencePoint);
    static Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapLocationFinderResult> FindLocationsAsync(hstring_view searchText, const Windows::Devices::Geolocation::Geopoint & referencePoint, uint32_t maxCount);
    static Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapLocationFinderResult> FindLocationsAtAsync(const Windows::Devices::Geolocation::Geopoint & queryPoint, Windows::Services::Maps::MapLocationDesiredAccuracy accuracy);
};

struct WINRT_EBO MapLocationFinderResult :
    Windows::Services::Maps::IMapLocationFinderResult
{
    MapLocationFinderResult(std::nullptr_t) noexcept {}
};

struct MapManager
{
    MapManager() = delete;
    static void ShowDownloadedMapsUI();
    static void ShowMapsUpdateUI();
};

struct WINRT_EBO MapRoute :
    Windows::Services::Maps::IMapRoute,
    impl::require<MapRoute, Windows::Services::Maps::IMapRoute2>
{
    MapRoute(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MapRouteDrivingOptions :
    Windows::Services::Maps::IMapRouteDrivingOptions
{
    MapRouteDrivingOptions(std::nullptr_t) noexcept {}
    MapRouteDrivingOptions();
};

struct MapRouteFinder
{
    MapRouteFinder() = delete;
    static Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> GetDrivingRouteAsync(const Windows::Devices::Geolocation::Geopoint & startPoint, const Windows::Devices::Geolocation::Geopoint & endPoint);
    static Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> GetDrivingRouteAsync(const Windows::Devices::Geolocation::Geopoint & startPoint, const Windows::Devices::Geolocation::Geopoint & endPoint, Windows::Services::Maps::MapRouteOptimization optimization);
    static Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> GetDrivingRouteAsync(const Windows::Devices::Geolocation::Geopoint & startPoint, const Windows::Devices::Geolocation::Geopoint & endPoint, Windows::Services::Maps::MapRouteOptimization optimization, Windows::Services::Maps::MapRouteRestrictions restrictions);
    static Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> GetDrivingRouteAsync(const Windows::Devices::Geolocation::Geopoint & startPoint, const Windows::Devices::Geolocation::Geopoint & endPoint, Windows::Services::Maps::MapRouteOptimization optimization, Windows::Services::Maps::MapRouteRestrictions restrictions, double headingInDegrees);
    static Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> GetDrivingRouteFromWaypointsAsync(iterable<Windows::Devices::Geolocation::Geopoint> wayPoints);
    static Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> GetDrivingRouteFromWaypointsAsync(iterable<Windows::Devices::Geolocation::Geopoint> wayPoints, Windows::Services::Maps::MapRouteOptimization optimization);
    static Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> GetDrivingRouteFromWaypointsAsync(iterable<Windows::Devices::Geolocation::Geopoint> wayPoints, Windows::Services::Maps::MapRouteOptimization optimization, Windows::Services::Maps::MapRouteRestrictions restrictions);
    static Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> GetDrivingRouteFromWaypointsAsync(iterable<Windows::Devices::Geolocation::Geopoint> wayPoints, Windows::Services::Maps::MapRouteOptimization optimization, Windows::Services::Maps::MapRouteRestrictions restrictions, double headingInDegrees);
    static Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> GetWalkingRouteAsync(const Windows::Devices::Geolocation::Geopoint & startPoint, const Windows::Devices::Geolocation::Geopoint & endPoint);
    static Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> GetWalkingRouteFromWaypointsAsync(iterable<Windows::Devices::Geolocation::Geopoint> wayPoints);
    static Windows::Foundation::IAsyncOperation<Windows::Services::Maps::MapRouteFinderResult> GetDrivingRouteAsync(const Windows::Devices::Geolocation::Geopoint & startPoint, const Windows::Devices::Geolocation::Geopoint & endPoint, const Windows::Services::Maps::MapRouteDrivingOptions & options);
};

struct WINRT_EBO MapRouteFinderResult :
    Windows::Services::Maps::IMapRouteFinderResult,
    impl::require<MapRouteFinderResult, Windows::Services::Maps::IMapRouteFinderResult2>
{
    MapRouteFinderResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MapRouteLeg :
    Windows::Services::Maps::IMapRouteLeg
{
    MapRouteLeg(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MapRouteManeuver :
    Windows::Services::Maps::IMapRouteManeuver,
    impl::require<MapRouteManeuver, Windows::Services::Maps::IMapRouteManeuver2>
{
    MapRouteManeuver(std::nullptr_t) noexcept {}
};

struct MapService
{
    MapService() = delete;
    static void ServiceToken(hstring_view value);
    static hstring ServiceToken();
    static hstring WorldViewRegionCode();
    static hstring DataAttributions();
};

}

}
