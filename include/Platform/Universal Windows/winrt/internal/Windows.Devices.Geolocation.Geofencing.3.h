// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Geolocation.Geofencing.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::Geolocation::Geofencing {

struct WINRT_EBO Geofence :
    Windows::Devices::Geolocation::Geofencing::IGeofence
{
    Geofence(std::nullptr_t) noexcept {}
    Geofence(hstring_view id, const Windows::Devices::Geolocation::IGeoshape & geoshape);
    Geofence(hstring_view id, const Windows::Devices::Geolocation::IGeoshape & geoshape, Windows::Devices::Geolocation::Geofencing::MonitoredGeofenceStates monitoredStates, bool singleUse);
    Geofence(hstring_view id, const Windows::Devices::Geolocation::IGeoshape & geoshape, Windows::Devices::Geolocation::Geofencing::MonitoredGeofenceStates monitoredStates, bool singleUse, const Windows::Foundation::TimeSpan & dwellTime);
    Geofence(hstring_view id, const Windows::Devices::Geolocation::IGeoshape & geoshape, Windows::Devices::Geolocation::Geofencing::MonitoredGeofenceStates monitoredStates, bool singleUse, const Windows::Foundation::TimeSpan & dwellTime, const Windows::Foundation::DateTime & startTime, const Windows::Foundation::TimeSpan & duration);
};

struct WINRT_EBO GeofenceMonitor :
    Windows::Devices::Geolocation::Geofencing::IGeofenceMonitor
{
    GeofenceMonitor(std::nullptr_t) noexcept {}
    static Windows::Devices::Geolocation::Geofencing::GeofenceMonitor Current();
};

struct WINRT_EBO GeofenceStateChangeReport :
    Windows::Devices::Geolocation::Geofencing::IGeofenceStateChangeReport
{
    GeofenceStateChangeReport(std::nullptr_t) noexcept {}
};

}

}
