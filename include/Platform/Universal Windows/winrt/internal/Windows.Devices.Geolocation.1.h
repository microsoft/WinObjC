// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Devices.Geolocation.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Geolocation {

struct BasicGeoposition
{
    double Latitude;
    double Longitude;
    double Altitude;
};

}

namespace Windows::Devices::Geolocation {

using BasicGeoposition = ABI::Windows::Devices::Geolocation::BasicGeoposition;

}

namespace ABI::Windows::Devices::Geolocation {

struct __declspec(uuid("a8567a1a-64f4-4d48-bcea-f6b008eca34c")) __declspec(novtable) ICivicAddress : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Country(hstring * value) = 0;
    virtual HRESULT __stdcall get_State(hstring * value) = 0;
    virtual HRESULT __stdcall get_City(hstring * value) = 0;
    virtual HRESULT __stdcall get_PostalCode(hstring * value) = 0;
    virtual HRESULT __stdcall get_Timestamp(Windows::Foundation::DateTime * value) = 0;
};

struct __declspec(uuid("0896c80b-274f-43da-9a06-cbfcdaeb4ec2")) __declspec(novtable) IGeoboundingBox : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_NorthwestCorner(Windows::Devices::Geolocation::BasicGeoposition * value) = 0;
    virtual HRESULT __stdcall get_SoutheastCorner(Windows::Devices::Geolocation::BasicGeoposition * value) = 0;
    virtual HRESULT __stdcall get_Center(Windows::Devices::Geolocation::BasicGeoposition * value) = 0;
    virtual HRESULT __stdcall get_MinAltitude(double * value) = 0;
    virtual HRESULT __stdcall get_MaxAltitude(double * value) = 0;
};

struct __declspec(uuid("4dfba589-0411-4abc-b3b5-5bbccb57d98c")) __declspec(novtable) IGeoboundingBoxFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Devices::Geolocation::BasicGeoposition northwestCorner, Windows::Devices::Geolocation::BasicGeoposition southeastCorner, Windows::Devices::Geolocation::IGeoboundingBox ** value) = 0;
    virtual HRESULT __stdcall abi_CreateWithAltitudeReference(Windows::Devices::Geolocation::BasicGeoposition northwestCorner, Windows::Devices::Geolocation::BasicGeoposition southeastCorner, winrt::Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem, Windows::Devices::Geolocation::IGeoboundingBox ** value) = 0;
    virtual HRESULT __stdcall abi_CreateWithAltitudeReferenceAndSpatialReference(Windows::Devices::Geolocation::BasicGeoposition northwestCorner, Windows::Devices::Geolocation::BasicGeoposition southeastCorner, winrt::Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem, uint32_t spatialReferenceId, Windows::Devices::Geolocation::IGeoboundingBox ** value) = 0;
};

struct __declspec(uuid("67b80708-e61a-4cd0-841b-93233792b5ca")) __declspec(novtable) IGeoboundingBoxStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_TryCompute(Windows::Foundation::Collections::IIterable<Windows::Devices::Geolocation::BasicGeoposition> * positions, Windows::Devices::Geolocation::IGeoboundingBox ** value) = 0;
    virtual HRESULT __stdcall abi_TryComputeWithAltitudeReference(Windows::Foundation::Collections::IIterable<Windows::Devices::Geolocation::BasicGeoposition> * positions, winrt::Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeRefSystem, Windows::Devices::Geolocation::IGeoboundingBox ** value) = 0;
    virtual HRESULT __stdcall abi_TryComputeWithAltitudeReferenceAndSpatialReference(Windows::Foundation::Collections::IIterable<Windows::Devices::Geolocation::BasicGeoposition> * positions, winrt::Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeRefSystem, uint32_t spatialReferenceId, Windows::Devices::Geolocation::IGeoboundingBox ** value) = 0;
};

struct __declspec(uuid("39e45843-a7f9-4e63-92a7-ba0c28d124b1")) __declspec(novtable) IGeocircle : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Center(Windows::Devices::Geolocation::BasicGeoposition * value) = 0;
    virtual HRESULT __stdcall get_Radius(double * value) = 0;
};

struct __declspec(uuid("afd6531f-72b1-4f7d-87cc-4ed4c9849c05")) __declspec(novtable) IGeocircleFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Devices::Geolocation::BasicGeoposition position, double radius, Windows::Devices::Geolocation::IGeocircle ** value) = 0;
    virtual HRESULT __stdcall abi_CreateWithAltitudeReferenceSystem(Windows::Devices::Geolocation::BasicGeoposition position, double radius, winrt::Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem, Windows::Devices::Geolocation::IGeocircle ** value) = 0;
    virtual HRESULT __stdcall abi_CreateWithAltitudeReferenceSystemAndSpatialReferenceId(Windows::Devices::Geolocation::BasicGeoposition position, double radius, winrt::Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem, uint32_t spatialReferenceId, Windows::Devices::Geolocation::IGeocircle ** value) = 0;
};

struct __declspec(uuid("ee21a3aa-976a-4c70-803d-083ea55bcbc4")) __declspec(novtable) IGeocoordinate : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Latitude(double * value) = 0;
    virtual HRESULT __stdcall get_Longitude(double * value) = 0;
    virtual HRESULT __stdcall get_Altitude(Windows::Foundation::IReference<double> ** value) = 0;
    virtual HRESULT __stdcall get_Accuracy(double * value) = 0;
    virtual HRESULT __stdcall get_AltitudeAccuracy(Windows::Foundation::IReference<double> ** value) = 0;
    virtual HRESULT __stdcall get_Heading(Windows::Foundation::IReference<double> ** value) = 0;
    virtual HRESULT __stdcall get_Speed(Windows::Foundation::IReference<double> ** value) = 0;
    virtual HRESULT __stdcall get_Timestamp(Windows::Foundation::DateTime * value) = 0;
};

struct __declspec(uuid("c32a74d9-2608-474c-912c-06dd490f4af7")) __declspec(novtable) IGeocoordinateSatelliteData : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PositionDilutionOfPrecision(Windows::Foundation::IReference<double> ** ppValue) = 0;
    virtual HRESULT __stdcall get_HorizontalDilutionOfPrecision(Windows::Foundation::IReference<double> ** ppValue) = 0;
    virtual HRESULT __stdcall get_VerticalDilutionOfPrecision(Windows::Foundation::IReference<double> ** ppValue) = 0;
};

struct __declspec(uuid("feea0525-d22c-4d46-b527-0b96066fc7db")) __declspec(novtable) IGeocoordinateWithPoint : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Point(Windows::Devices::Geolocation::IGeopoint ** value) = 0;
};

struct __declspec(uuid("95e634be-dbd6-40ac-b8f2-a65c0340d9a6")) __declspec(novtable) IGeocoordinateWithPositionData : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PositionSource(winrt::Windows::Devices::Geolocation::PositionSource * pValue) = 0;
    virtual HRESULT __stdcall get_SatelliteData(Windows::Devices::Geolocation::IGeocoordinateSatelliteData ** ppValue) = 0;
};

struct __declspec(uuid("8543fc02-c9f1-4610-afe0-8bc3a6a87036")) __declspec(novtable) IGeocoordinateWithPositionSourceTimestamp : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PositionSourceTimestamp(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
};

struct __declspec(uuid("a9c3bf62-4524-4989-8aa9-de019d2e551f")) __declspec(novtable) IGeolocator : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DesiredAccuracy(winrt::Windows::Devices::Geolocation::PositionAccuracy * value) = 0;
    virtual HRESULT __stdcall put_DesiredAccuracy(winrt::Windows::Devices::Geolocation::PositionAccuracy value) = 0;
    virtual HRESULT __stdcall get_MovementThreshold(double * value) = 0;
    virtual HRESULT __stdcall put_MovementThreshold(double value) = 0;
    virtual HRESULT __stdcall get_ReportInterval(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_ReportInterval(uint32_t value) = 0;
    virtual HRESULT __stdcall get_LocationStatus(winrt::Windows::Devices::Geolocation::PositionStatus * value) = 0;
    virtual HRESULT __stdcall abi_GetGeopositionAsync(Windows::Foundation::IAsyncOperation<Windows::Devices::Geolocation::Geoposition> ** value) = 0;
    virtual HRESULT __stdcall abi_GetGeopositionAsyncWithAgeAndTimeout(Windows::Foundation::TimeSpan maximumAge, Windows::Foundation::TimeSpan timeout, Windows::Foundation::IAsyncOperation<Windows::Devices::Geolocation::Geoposition> ** value) = 0;
    virtual HRESULT __stdcall add_PositionChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Geolocation::Geolocator, Windows::Devices::Geolocation::PositionChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PositionChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_StatusChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Geolocation::Geolocator, Windows::Devices::Geolocation::StatusChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_StatusChanged(event_token token) = 0;
};

struct __declspec(uuid("d1b42e6d-8891-43b4-ad36-27c6fe9a97b1")) __declspec(novtable) IGeolocator2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_AllowFallbackToConsentlessPositions() = 0;
};

struct __declspec(uuid("9a8e7571-2df5-4591-9f87-eb5fd894e9b7")) __declspec(novtable) IGeolocatorStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RequestAccessAsync(Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Geolocation::GeolocationAccessStatus> ** result) = 0;
    virtual HRESULT __stdcall abi_GetGeopositionHistoryAsync(Windows::Foundation::DateTime startTime, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Geolocation::Geoposition>> ** result) = 0;
    virtual HRESULT __stdcall abi_GetGeopositionHistoryWithDurationAsync(Windows::Foundation::DateTime startTime, Windows::Foundation::TimeSpan duration, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Geolocation::Geoposition>> ** result) = 0;
};

struct __declspec(uuid("993011a2-fa1c-4631-a71d-0dbeb1250d9c")) __declspec(novtable) IGeolocatorStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsDefaultGeopositionRecommended(bool * value) = 0;
    virtual HRESULT __stdcall put_DefaultGeoposition(Windows::Foundation::IReference<Windows::Devices::Geolocation::BasicGeoposition> * value) = 0;
    virtual HRESULT __stdcall get_DefaultGeoposition(Windows::Foundation::IReference<Windows::Devices::Geolocation::BasicGeoposition> ** value) = 0;
};

struct __declspec(uuid("96f5d3c1-b80f-460a-994d-a96c47a51aa4")) __declspec(novtable) IGeolocatorWithScalarAccuracy : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DesiredAccuracyInMeters(Windows::Foundation::IReference<uint32_t> ** value) = 0;
    virtual HRESULT __stdcall put_DesiredAccuracyInMeters(Windows::Foundation::IReference<uint32_t> * value) = 0;
};

struct __declspec(uuid("e53fd7b9-2da4-4714-a652-de8593289898")) __declspec(novtable) IGeopath : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Positions(Windows::Foundation::Collections::IVectorView<Windows::Devices::Geolocation::BasicGeoposition> ** value) = 0;
};

struct __declspec(uuid("27bea9c8-c7e7-4359-9b9b-fca3e05ef593")) __declspec(novtable) IGeopathFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Foundation::Collections::IIterable<Windows::Devices::Geolocation::BasicGeoposition> * positions, Windows::Devices::Geolocation::IGeopath ** value) = 0;
    virtual HRESULT __stdcall abi_CreateWithAltitudeReference(Windows::Foundation::Collections::IIterable<Windows::Devices::Geolocation::BasicGeoposition> * positions, winrt::Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem, Windows::Devices::Geolocation::IGeopath ** value) = 0;
    virtual HRESULT __stdcall abi_CreateWithAltitudeReferenceAndSpatialReference(Windows::Foundation::Collections::IIterable<Windows::Devices::Geolocation::BasicGeoposition> * positions, winrt::Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem, uint32_t spatialReferenceId, Windows::Devices::Geolocation::IGeopath ** value) = 0;
};

struct __declspec(uuid("6bfa00eb-e56e-49bb-9caf-cbaa78a8bcef")) __declspec(novtable) IGeopoint : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Position(Windows::Devices::Geolocation::BasicGeoposition * value) = 0;
};

struct __declspec(uuid("db6b8d33-76bd-4e30-8af7-a844dc37b7a0")) __declspec(novtable) IGeopointFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Devices::Geolocation::BasicGeoposition position, Windows::Devices::Geolocation::IGeopoint ** value) = 0;
    virtual HRESULT __stdcall abi_CreateWithAltitudeReferenceSystem(Windows::Devices::Geolocation::BasicGeoposition position, winrt::Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem, Windows::Devices::Geolocation::IGeopoint ** value) = 0;
    virtual HRESULT __stdcall abi_CreateWithAltitudeReferenceSystemAndSpatialReferenceId(Windows::Devices::Geolocation::BasicGeoposition position, winrt::Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem, uint32_t spatialReferenceId, Windows::Devices::Geolocation::IGeopoint ** value) = 0;
};

struct __declspec(uuid("c18d0454-7d41-4ff7-a957-9dffb4ef7f5b")) __declspec(novtable) IGeoposition : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Coordinate(Windows::Devices::Geolocation::IGeocoordinate ** value) = 0;
    virtual HRESULT __stdcall get_CivicAddress(Windows::Devices::Geolocation::ICivicAddress ** value) = 0;
};

struct __declspec(uuid("7f62f697-8671-4b0d-86f8-474a8496187c")) __declspec(novtable) IGeoposition2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_VenueData(Windows::Devices::Geolocation::IVenueData ** value) = 0;
};

struct __declspec(uuid("c99ca2af-c729-43c1-8fab-d6dec914df7e")) __declspec(novtable) IGeoshape : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_GeoshapeType(winrt::Windows::Devices::Geolocation::GeoshapeType * value) = 0;
    virtual HRESULT __stdcall get_SpatialReferenceId(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_AltitudeReferenceSystem(winrt::Windows::Devices::Geolocation::AltitudeReferenceSystem * value) = 0;
};

struct __declspec(uuid("37859ce5-9d1e-46c5-bf3b-6ad8cac1a093")) __declspec(novtable) IPositionChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Position(Windows::Devices::Geolocation::IGeoposition ** value) = 0;
};

struct __declspec(uuid("3453d2da-8c93-4111-a205-9aecfc9be5c0")) __declspec(novtable) IStatusChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Status(winrt::Windows::Devices::Geolocation::PositionStatus * value) = 0;
};

struct __declspec(uuid("66f39187-60e3-4b2f-b527-4f53f1c3c677")) __declspec(novtable) IVenueData : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall get_Level(hstring * value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Devices::Geolocation::CivicAddress> { using default_interface = Windows::Devices::Geolocation::ICivicAddress; };
template <> struct traits<Windows::Devices::Geolocation::GeoboundingBox> { using default_interface = Windows::Devices::Geolocation::IGeoboundingBox; };
template <> struct traits<Windows::Devices::Geolocation::Geocircle> { using default_interface = Windows::Devices::Geolocation::IGeocircle; };
template <> struct traits<Windows::Devices::Geolocation::Geocoordinate> { using default_interface = Windows::Devices::Geolocation::IGeocoordinate; };
template <> struct traits<Windows::Devices::Geolocation::GeocoordinateSatelliteData> { using default_interface = Windows::Devices::Geolocation::IGeocoordinateSatelliteData; };
template <> struct traits<Windows::Devices::Geolocation::Geolocator> { using default_interface = Windows::Devices::Geolocation::IGeolocator; };
template <> struct traits<Windows::Devices::Geolocation::Geopath> { using default_interface = Windows::Devices::Geolocation::IGeopath; };
template <> struct traits<Windows::Devices::Geolocation::Geopoint> { using default_interface = Windows::Devices::Geolocation::IGeopoint; };
template <> struct traits<Windows::Devices::Geolocation::Geoposition> { using default_interface = Windows::Devices::Geolocation::IGeoposition; };
template <> struct traits<Windows::Devices::Geolocation::PositionChangedEventArgs> { using default_interface = Windows::Devices::Geolocation::IPositionChangedEventArgs; };
template <> struct traits<Windows::Devices::Geolocation::StatusChangedEventArgs> { using default_interface = Windows::Devices::Geolocation::IStatusChangedEventArgs; };
template <> struct traits<Windows::Devices::Geolocation::VenueData> { using default_interface = Windows::Devices::Geolocation::IVenueData; };

}

namespace Windows::Devices::Geolocation {

template <typename D>
struct WINRT_EBO impl_ICivicAddress
{
    hstring Country() const;
    hstring State() const;
    hstring City() const;
    hstring PostalCode() const;
    Windows::Foundation::DateTime Timestamp() const;
};

template <typename D>
struct WINRT_EBO impl_IGeoboundingBox
{
    Windows::Devices::Geolocation::BasicGeoposition NorthwestCorner() const;
    Windows::Devices::Geolocation::BasicGeoposition SoutheastCorner() const;
    Windows::Devices::Geolocation::BasicGeoposition Center() const;
    double MinAltitude() const;
    double MaxAltitude() const;
};

template <typename D>
struct WINRT_EBO impl_IGeoboundingBoxFactory
{
    Windows::Devices::Geolocation::GeoboundingBox Create(const Windows::Devices::Geolocation::BasicGeoposition & northwestCorner, const Windows::Devices::Geolocation::BasicGeoposition & southeastCorner) const;
    Windows::Devices::Geolocation::GeoboundingBox CreateWithAltitudeReference(const Windows::Devices::Geolocation::BasicGeoposition & northwestCorner, const Windows::Devices::Geolocation::BasicGeoposition & southeastCorner, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem) const;
    Windows::Devices::Geolocation::GeoboundingBox CreateWithAltitudeReferenceAndSpatialReference(const Windows::Devices::Geolocation::BasicGeoposition & northwestCorner, const Windows::Devices::Geolocation::BasicGeoposition & southeastCorner, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem, uint32_t spatialReferenceId) const;
};

template <typename D>
struct WINRT_EBO impl_IGeoboundingBoxStatics
{
    Windows::Devices::Geolocation::GeoboundingBox TryCompute(iterable<Windows::Devices::Geolocation::BasicGeoposition> positions) const;
    Windows::Devices::Geolocation::GeoboundingBox TryCompute(iterable<Windows::Devices::Geolocation::BasicGeoposition> positions, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeRefSystem) const;
    Windows::Devices::Geolocation::GeoboundingBox TryCompute(iterable<Windows::Devices::Geolocation::BasicGeoposition> positions, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeRefSystem, uint32_t spatialReferenceId) const;
};

template <typename D>
struct WINRT_EBO impl_IGeocircle
{
    Windows::Devices::Geolocation::BasicGeoposition Center() const;
    double Radius() const;
};

template <typename D>
struct WINRT_EBO impl_IGeocircleFactory
{
    Windows::Devices::Geolocation::Geocircle Create(const Windows::Devices::Geolocation::BasicGeoposition & position, double radius) const;
    Windows::Devices::Geolocation::Geocircle CreateWithAltitudeReferenceSystem(const Windows::Devices::Geolocation::BasicGeoposition & position, double radius, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem) const;
    Windows::Devices::Geolocation::Geocircle CreateWithAltitudeReferenceSystemAndSpatialReferenceId(const Windows::Devices::Geolocation::BasicGeoposition & position, double radius, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem, uint32_t spatialReferenceId) const;
};

template <typename D>
struct WINRT_EBO impl_IGeocoordinate
{
    [[deprecated("Latitude may be altered or unavailable after Windows 8.1. Instead, use Point.Position.Latitude")]] double Latitude() const;
    [[deprecated("Longitude may be altered or unavailable after Windows 8.1. Instead, use Point.Position.Longitude")]] double Longitude() const;
    [[deprecated("Altitude may be altered or unavailable after Windows 8.1. Instead, use Point.Position.Altitude")]] Windows::Foundation::IReference<double> Altitude() const;
    double Accuracy() const;
    Windows::Foundation::IReference<double> AltitudeAccuracy() const;
    Windows::Foundation::IReference<double> Heading() const;
    Windows::Foundation::IReference<double> Speed() const;
    Windows::Foundation::DateTime Timestamp() const;
};

template <typename D>
struct WINRT_EBO impl_IGeocoordinateSatelliteData
{
    Windows::Foundation::IReference<double> PositionDilutionOfPrecision() const;
    Windows::Foundation::IReference<double> HorizontalDilutionOfPrecision() const;
    Windows::Foundation::IReference<double> VerticalDilutionOfPrecision() const;
};

template <typename D>
struct WINRT_EBO impl_IGeocoordinateWithPoint
{
    Windows::Devices::Geolocation::Geopoint Point() const;
};

template <typename D>
struct WINRT_EBO impl_IGeocoordinateWithPositionData
{
    Windows::Devices::Geolocation::PositionSource PositionSource() const;
    Windows::Devices::Geolocation::GeocoordinateSatelliteData SatelliteData() const;
};

template <typename D>
struct WINRT_EBO impl_IGeocoordinateWithPositionSourceTimestamp
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> PositionSourceTimestamp() const;
};

template <typename D>
struct WINRT_EBO impl_IGeolocator
{
    Windows::Devices::Geolocation::PositionAccuracy DesiredAccuracy() const;
    void DesiredAccuracy(Windows::Devices::Geolocation::PositionAccuracy value) const;
    double MovementThreshold() const;
    void MovementThreshold(double value) const;
    uint32_t ReportInterval() const;
    void ReportInterval(uint32_t value) const;
    Windows::Devices::Geolocation::PositionStatus LocationStatus() const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::Geolocation::Geoposition> GetGeopositionAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::Geolocation::Geoposition> GetGeopositionAsync(const Windows::Foundation::TimeSpan & maximumAge, const Windows::Foundation::TimeSpan & timeout) const;
    event_token PositionChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Geolocation::Geolocator, Windows::Devices::Geolocation::PositionChangedEventArgs> & handler) const;
    using PositionChanged_revoker = event_revoker<IGeolocator>;
    PositionChanged_revoker PositionChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Geolocation::Geolocator, Windows::Devices::Geolocation::PositionChangedEventArgs> & handler) const;
    void PositionChanged(event_token token) const;
    event_token StatusChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Geolocation::Geolocator, Windows::Devices::Geolocation::StatusChangedEventArgs> & handler) const;
    using StatusChanged_revoker = event_revoker<IGeolocator>;
    StatusChanged_revoker StatusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Geolocation::Geolocator, Windows::Devices::Geolocation::StatusChangedEventArgs> & handler) const;
    void StatusChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IGeolocator2
{
    void AllowFallbackToConsentlessPositions() const;
};

template <typename D>
struct WINRT_EBO impl_IGeolocatorStatics
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Geolocation::GeolocationAccessStatus> RequestAccessAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Geolocation::Geoposition>> GetGeopositionHistoryAsync(const Windows::Foundation::DateTime & startTime) const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Geolocation::Geoposition>> GetGeopositionHistoryAsync(const Windows::Foundation::DateTime & startTime, const Windows::Foundation::TimeSpan & duration) const;
};

template <typename D>
struct WINRT_EBO impl_IGeolocatorStatics2
{
    bool IsDefaultGeopositionRecommended() const;
    void DefaultGeoposition(const optional<Windows::Devices::Geolocation::BasicGeoposition> & value) const;
    Windows::Foundation::IReference<Windows::Devices::Geolocation::BasicGeoposition> DefaultGeoposition() const;
};

template <typename D>
struct WINRT_EBO impl_IGeolocatorWithScalarAccuracy
{
    Windows::Foundation::IReference<uint32_t> DesiredAccuracyInMeters() const;
    void DesiredAccuracyInMeters(const optional<uint32_t> & value) const;
};

template <typename D>
struct WINRT_EBO impl_IGeopath
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Geolocation::BasicGeoposition> Positions() const;
};

template <typename D>
struct WINRT_EBO impl_IGeopathFactory
{
    Windows::Devices::Geolocation::Geopath Create(iterable<Windows::Devices::Geolocation::BasicGeoposition> positions) const;
    Windows::Devices::Geolocation::Geopath CreateWithAltitudeReference(iterable<Windows::Devices::Geolocation::BasicGeoposition> positions, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem) const;
    Windows::Devices::Geolocation::Geopath CreateWithAltitudeReferenceAndSpatialReference(iterable<Windows::Devices::Geolocation::BasicGeoposition> positions, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem, uint32_t spatialReferenceId) const;
};

template <typename D>
struct WINRT_EBO impl_IGeopoint
{
    Windows::Devices::Geolocation::BasicGeoposition Position() const;
};

template <typename D>
struct WINRT_EBO impl_IGeopointFactory
{
    Windows::Devices::Geolocation::Geopoint Create(const Windows::Devices::Geolocation::BasicGeoposition & position) const;
    Windows::Devices::Geolocation::Geopoint CreateWithAltitudeReferenceSystem(const Windows::Devices::Geolocation::BasicGeoposition & position, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem) const;
    Windows::Devices::Geolocation::Geopoint CreateWithAltitudeReferenceSystemAndSpatialReferenceId(const Windows::Devices::Geolocation::BasicGeoposition & position, Windows::Devices::Geolocation::AltitudeReferenceSystem altitudeReferenceSystem, uint32_t spatialReferenceId) const;
};

template <typename D>
struct WINRT_EBO impl_IGeoposition
{
    Windows::Devices::Geolocation::Geocoordinate Coordinate() const;
    Windows::Devices::Geolocation::CivicAddress CivicAddress() const;
};

template <typename D>
struct WINRT_EBO impl_IGeoposition2
{
    Windows::Devices::Geolocation::VenueData VenueData() const;
};

template <typename D>
struct WINRT_EBO impl_IGeoshape
{
    Windows::Devices::Geolocation::GeoshapeType GeoshapeType() const;
    uint32_t SpatialReferenceId() const;
    Windows::Devices::Geolocation::AltitudeReferenceSystem AltitudeReferenceSystem() const;
};

template <typename D>
struct WINRT_EBO impl_IPositionChangedEventArgs
{
    Windows::Devices::Geolocation::Geoposition Position() const;
};

template <typename D>
struct WINRT_EBO impl_IStatusChangedEventArgs
{
    Windows::Devices::Geolocation::PositionStatus Status() const;
};

template <typename D>
struct WINRT_EBO impl_IVenueData
{
    hstring Id() const;
    hstring Level() const;
};

}

namespace impl {

template <> struct traits<Windows::Devices::Geolocation::ICivicAddress>
{
    using abi = ABI::Windows::Devices::Geolocation::ICivicAddress;
    template <typename D> using consume = Windows::Devices::Geolocation::impl_ICivicAddress<D>;
};

template <> struct traits<Windows::Devices::Geolocation::IGeoboundingBox>
{
    using abi = ABI::Windows::Devices::Geolocation::IGeoboundingBox;
    template <typename D> using consume = Windows::Devices::Geolocation::impl_IGeoboundingBox<D>;
};

template <> struct traits<Windows::Devices::Geolocation::IGeoboundingBoxFactory>
{
    using abi = ABI::Windows::Devices::Geolocation::IGeoboundingBoxFactory;
    template <typename D> using consume = Windows::Devices::Geolocation::impl_IGeoboundingBoxFactory<D>;
};

template <> struct traits<Windows::Devices::Geolocation::IGeoboundingBoxStatics>
{
    using abi = ABI::Windows::Devices::Geolocation::IGeoboundingBoxStatics;
    template <typename D> using consume = Windows::Devices::Geolocation::impl_IGeoboundingBoxStatics<D>;
};

template <> struct traits<Windows::Devices::Geolocation::IGeocircle>
{
    using abi = ABI::Windows::Devices::Geolocation::IGeocircle;
    template <typename D> using consume = Windows::Devices::Geolocation::impl_IGeocircle<D>;
};

template <> struct traits<Windows::Devices::Geolocation::IGeocircleFactory>
{
    using abi = ABI::Windows::Devices::Geolocation::IGeocircleFactory;
    template <typename D> using consume = Windows::Devices::Geolocation::impl_IGeocircleFactory<D>;
};

template <> struct traits<Windows::Devices::Geolocation::IGeocoordinate>
{
    using abi = ABI::Windows::Devices::Geolocation::IGeocoordinate;
    template <typename D> using consume = Windows::Devices::Geolocation::impl_IGeocoordinate<D>;
};

template <> struct traits<Windows::Devices::Geolocation::IGeocoordinateSatelliteData>
{
    using abi = ABI::Windows::Devices::Geolocation::IGeocoordinateSatelliteData;
    template <typename D> using consume = Windows::Devices::Geolocation::impl_IGeocoordinateSatelliteData<D>;
};

template <> struct traits<Windows::Devices::Geolocation::IGeocoordinateWithPoint>
{
    using abi = ABI::Windows::Devices::Geolocation::IGeocoordinateWithPoint;
    template <typename D> using consume = Windows::Devices::Geolocation::impl_IGeocoordinateWithPoint<D>;
};

template <> struct traits<Windows::Devices::Geolocation::IGeocoordinateWithPositionData>
{
    using abi = ABI::Windows::Devices::Geolocation::IGeocoordinateWithPositionData;
    template <typename D> using consume = Windows::Devices::Geolocation::impl_IGeocoordinateWithPositionData<D>;
};

template <> struct traits<Windows::Devices::Geolocation::IGeocoordinateWithPositionSourceTimestamp>
{
    using abi = ABI::Windows::Devices::Geolocation::IGeocoordinateWithPositionSourceTimestamp;
    template <typename D> using consume = Windows::Devices::Geolocation::impl_IGeocoordinateWithPositionSourceTimestamp<D>;
};

template <> struct traits<Windows::Devices::Geolocation::IGeolocator>
{
    using abi = ABI::Windows::Devices::Geolocation::IGeolocator;
    template <typename D> using consume = Windows::Devices::Geolocation::impl_IGeolocator<D>;
};

template <> struct traits<Windows::Devices::Geolocation::IGeolocator2>
{
    using abi = ABI::Windows::Devices::Geolocation::IGeolocator2;
    template <typename D> using consume = Windows::Devices::Geolocation::impl_IGeolocator2<D>;
};

template <> struct traits<Windows::Devices::Geolocation::IGeolocatorStatics>
{
    using abi = ABI::Windows::Devices::Geolocation::IGeolocatorStatics;
    template <typename D> using consume = Windows::Devices::Geolocation::impl_IGeolocatorStatics<D>;
};

template <> struct traits<Windows::Devices::Geolocation::IGeolocatorStatics2>
{
    using abi = ABI::Windows::Devices::Geolocation::IGeolocatorStatics2;
    template <typename D> using consume = Windows::Devices::Geolocation::impl_IGeolocatorStatics2<D>;
};

template <> struct traits<Windows::Devices::Geolocation::IGeolocatorWithScalarAccuracy>
{
    using abi = ABI::Windows::Devices::Geolocation::IGeolocatorWithScalarAccuracy;
    template <typename D> using consume = Windows::Devices::Geolocation::impl_IGeolocatorWithScalarAccuracy<D>;
};

template <> struct traits<Windows::Devices::Geolocation::IGeopath>
{
    using abi = ABI::Windows::Devices::Geolocation::IGeopath;
    template <typename D> using consume = Windows::Devices::Geolocation::impl_IGeopath<D>;
};

template <> struct traits<Windows::Devices::Geolocation::IGeopathFactory>
{
    using abi = ABI::Windows::Devices::Geolocation::IGeopathFactory;
    template <typename D> using consume = Windows::Devices::Geolocation::impl_IGeopathFactory<D>;
};

template <> struct traits<Windows::Devices::Geolocation::IGeopoint>
{
    using abi = ABI::Windows::Devices::Geolocation::IGeopoint;
    template <typename D> using consume = Windows::Devices::Geolocation::impl_IGeopoint<D>;
};

template <> struct traits<Windows::Devices::Geolocation::IGeopointFactory>
{
    using abi = ABI::Windows::Devices::Geolocation::IGeopointFactory;
    template <typename D> using consume = Windows::Devices::Geolocation::impl_IGeopointFactory<D>;
};

template <> struct traits<Windows::Devices::Geolocation::IGeoposition>
{
    using abi = ABI::Windows::Devices::Geolocation::IGeoposition;
    template <typename D> using consume = Windows::Devices::Geolocation::impl_IGeoposition<D>;
};

template <> struct traits<Windows::Devices::Geolocation::IGeoposition2>
{
    using abi = ABI::Windows::Devices::Geolocation::IGeoposition2;
    template <typename D> using consume = Windows::Devices::Geolocation::impl_IGeoposition2<D>;
};

template <> struct traits<Windows::Devices::Geolocation::IGeoshape>
{
    using abi = ABI::Windows::Devices::Geolocation::IGeoshape;
    template <typename D> using consume = Windows::Devices::Geolocation::impl_IGeoshape<D>;
};

template <> struct traits<Windows::Devices::Geolocation::IPositionChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Geolocation::IPositionChangedEventArgs;
    template <typename D> using consume = Windows::Devices::Geolocation::impl_IPositionChangedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Geolocation::IStatusChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Geolocation::IStatusChangedEventArgs;
    template <typename D> using consume = Windows::Devices::Geolocation::impl_IStatusChangedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Geolocation::IVenueData>
{
    using abi = ABI::Windows::Devices::Geolocation::IVenueData;
    template <typename D> using consume = Windows::Devices::Geolocation::impl_IVenueData<D>;
};

template <> struct traits<Windows::Devices::Geolocation::CivicAddress>
{
    using abi = ABI::Windows::Devices::Geolocation::CivicAddress;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Geolocation.CivicAddress"; }
};

template <> struct traits<Windows::Devices::Geolocation::GeoboundingBox>
{
    using abi = ABI::Windows::Devices::Geolocation::GeoboundingBox;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Geolocation.GeoboundingBox"; }
};

template <> struct traits<Windows::Devices::Geolocation::Geocircle>
{
    using abi = ABI::Windows::Devices::Geolocation::Geocircle;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Geolocation.Geocircle"; }
};

template <> struct traits<Windows::Devices::Geolocation::Geocoordinate>
{
    using abi = ABI::Windows::Devices::Geolocation::Geocoordinate;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Geolocation.Geocoordinate"; }
};

template <> struct traits<Windows::Devices::Geolocation::GeocoordinateSatelliteData>
{
    using abi = ABI::Windows::Devices::Geolocation::GeocoordinateSatelliteData;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Geolocation.GeocoordinateSatelliteData"; }
};

template <> struct traits<Windows::Devices::Geolocation::Geolocator>
{
    using abi = ABI::Windows::Devices::Geolocation::Geolocator;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Geolocation.Geolocator"; }
};

template <> struct traits<Windows::Devices::Geolocation::Geopath>
{
    using abi = ABI::Windows::Devices::Geolocation::Geopath;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Geolocation.Geopath"; }
};

template <> struct traits<Windows::Devices::Geolocation::Geopoint>
{
    using abi = ABI::Windows::Devices::Geolocation::Geopoint;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Geolocation.Geopoint"; }
};

template <> struct traits<Windows::Devices::Geolocation::Geoposition>
{
    using abi = ABI::Windows::Devices::Geolocation::Geoposition;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Geolocation.Geoposition"; }
};

template <> struct traits<Windows::Devices::Geolocation::PositionChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Geolocation::PositionChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Geolocation.PositionChangedEventArgs"; }
};

template <> struct traits<Windows::Devices::Geolocation::StatusChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Geolocation::StatusChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Geolocation.StatusChangedEventArgs"; }
};

template <> struct traits<Windows::Devices::Geolocation::VenueData>
{
    using abi = ABI::Windows::Devices::Geolocation::VenueData;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Geolocation.VenueData"; }
};

}

}
