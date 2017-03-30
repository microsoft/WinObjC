// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Geolocation.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::Geolocation {

struct WINRT_EBO CivicAddress :
    Windows::Devices::Geolocation::ICivicAddress
{
    CivicAddress(std::nullptr_t) noexcept {}
};

struct WINRT_EBO GeoboundingBox :
    Windows::Devices::Geolocation::IGeoboundingBox
{
    GeoboundingBox(std::nullptr_t) noexcept {}
    GeoboundingBox(const Windows::Devices::Geolocation::BasicGeoposition & northwestCorner, const Windows::Devices::Geolocation::BasicGeoposition & southeastCorner);
    GeoboundingBox(const Windows::Devices::Geolocation::BasicGeoposition & northwestCorner, const Windows::Devices::Geolocation::BasicGeoposition & southeastCorner, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem);
    GeoboundingBox(const Windows::Devices::Geolocation::BasicGeoposition & northwestCorner, const Windows::Devices::Geolocation::BasicGeoposition & southeastCorner, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem, uint32_t spatialReferenceId);
    static Windows::Devices::Geolocation::GeoboundingBox TryCompute(iterable<Windows::Devices::Geolocation::BasicGeoposition> positions);
    static Windows::Devices::Geolocation::GeoboundingBox TryCompute(iterable<Windows::Devices::Geolocation::BasicGeoposition> positions, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeRefSystem);
    static Windows::Devices::Geolocation::GeoboundingBox TryCompute(iterable<Windows::Devices::Geolocation::BasicGeoposition> positions, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeRefSystem, uint32_t spatialReferenceId);
};

struct WINRT_EBO Geocircle :
    Windows::Devices::Geolocation::IGeocircle
{
    Geocircle(std::nullptr_t) noexcept {}
    Geocircle(const Windows::Devices::Geolocation::BasicGeoposition & position, double radius);
    Geocircle(const Windows::Devices::Geolocation::BasicGeoposition & position, double radius, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem);
    Geocircle(const Windows::Devices::Geolocation::BasicGeoposition & position, double radius, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem, uint32_t spatialReferenceId);
};

struct WINRT_EBO Geocoordinate :
    Windows::Devices::Geolocation::IGeocoordinate,
    impl::require<Geocoordinate, Windows::Devices::Geolocation::IGeocoordinateWithPositionData, Windows::Devices::Geolocation::IGeocoordinateWithPoint, Windows::Devices::Geolocation::IGeocoordinateWithPositionSourceTimestamp>
{
    Geocoordinate(std::nullptr_t) noexcept {}
};

struct WINRT_EBO GeocoordinateSatelliteData :
    Windows::Devices::Geolocation::IGeocoordinateSatelliteData
{
    GeocoordinateSatelliteData(std::nullptr_t) noexcept {}
};

struct WINRT_EBO Geolocator :
    Windows::Devices::Geolocation::IGeolocator,
    impl::require<Geolocator, Windows::Devices::Geolocation::IGeolocatorWithScalarAccuracy, Windows::Devices::Geolocation::IGeolocator2>
{
    Geolocator(std::nullptr_t) noexcept {}
    Geolocator();
    static Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Geolocation::GeolocationAccessStatus> RequestAccessAsync();
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Geolocation::Geoposition>> GetGeopositionHistoryAsync(const Windows::Foundation::DateTime & startTime);
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Geolocation::Geoposition>> GetGeopositionHistoryAsync(const Windows::Foundation::DateTime & startTime, const Windows::Foundation::TimeSpan & duration);
    static bool IsDefaultGeopositionRecommended();
    static void DefaultGeoposition(const optional<Windows::Devices::Geolocation::BasicGeoposition> & value);
    static Windows::Foundation::IReference<Windows::Devices::Geolocation::BasicGeoposition> DefaultGeoposition();
};

struct WINRT_EBO Geopath :
    Windows::Devices::Geolocation::IGeopath
{
    Geopath(std::nullptr_t) noexcept {}
    Geopath(iterable<Windows::Devices::Geolocation::BasicGeoposition> positions);
    Geopath(iterable<Windows::Devices::Geolocation::BasicGeoposition> positions, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem);
    Geopath(iterable<Windows::Devices::Geolocation::BasicGeoposition> positions, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem, uint32_t spatialReferenceId);
};

struct WINRT_EBO Geopoint :
    Windows::Devices::Geolocation::IGeopoint
{
    Geopoint(std::nullptr_t) noexcept {}
    Geopoint(const Windows::Devices::Geolocation::BasicGeoposition & position);
    Geopoint(const Windows::Devices::Geolocation::BasicGeoposition & position, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem);
    Geopoint(const Windows::Devices::Geolocation::BasicGeoposition & position, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem, uint32_t spatialReferenceId);
};

struct WINRT_EBO Geoposition :
    Windows::Devices::Geolocation::IGeoposition,
    impl::require<Geoposition, Windows::Devices::Geolocation::IGeoposition2>
{
    Geoposition(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PositionChangedEventArgs :
    Windows::Devices::Geolocation::IPositionChangedEventArgs
{
    PositionChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO StatusChangedEventArgs :
    Windows::Devices::Geolocation::IStatusChangedEventArgs
{
    StatusChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO VenueData :
    Windows::Devices::Geolocation::IVenueData
{
    VenueData(std::nullptr_t) noexcept {}
};

}

}
