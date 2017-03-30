// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Geolocation.Geofencing.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_096dc936_5f66_5c6e_95ce_ef5541fbf4c4
#define WINRT_GENERIC_096dc936_5f66_5c6e_95ce_ef5541fbf4c4
template <> struct __declspec(uuid("096dc936-5f66-5c6e-95ce-ef5541fbf4c4")) __declspec(novtable) IVector<Windows::Devices::Geolocation::Geofencing::Geofence> : impl_IVector<Windows::Devices::Geolocation::Geofencing::Geofence> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_ecc5af2c_e47a_59ce_86be_9c3066fe26f7
#define WINRT_GENERIC_ecc5af2c_e47a_59ce_86be_9c3066fe26f7
template <> struct __declspec(uuid("ecc5af2c-e47a-59ce-86be-9c3066fe26f7")) __declspec(novtable) TypedEventHandler<Windows::Devices::Geolocation::Geofencing::GeofenceMonitor, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::Devices::Geolocation::Geofencing::GeofenceMonitor, Windows::Foundation::IInspectable> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_ea91593d_ecf4_5041_86f2_837a282c4d94
#define WINRT_GENERIC_ea91593d_ecf4_5041_86f2_837a282c4d94
template <> struct __declspec(uuid("ea91593d-ecf4-5041-86f2-837a282c4d94")) __declspec(novtable) IVectorView<Windows::Devices::Geolocation::Geofencing::GeofenceStateChangeReport> : impl_IVectorView<Windows::Devices::Geolocation::Geofencing::GeofenceStateChangeReport> {};
#endif

#ifndef WINRT_GENERIC_e7a9e144_202d_5708_a9bd_e3dc0e14df46
#define WINRT_GENERIC_e7a9e144_202d_5708_a9bd_e3dc0e14df46
template <> struct __declspec(uuid("e7a9e144-202d-5708-a9bd-e3dc0e14df46")) __declspec(novtable) IIterator<Windows::Devices::Geolocation::Geofencing::Geofence> : impl_IIterator<Windows::Devices::Geolocation::Geofencing::Geofence> {};
#endif

#ifndef WINRT_GENERIC_ce697733_595c_51c0_ad5f_324af5cdf2dd
#define WINRT_GENERIC_ce697733_595c_51c0_ad5f_324af5cdf2dd
template <> struct __declspec(uuid("ce697733-595c-51c0-ad5f-324af5cdf2dd")) __declspec(novtable) IIterable<Windows::Devices::Geolocation::Geofencing::Geofence> : impl_IIterable<Windows::Devices::Geolocation::Geofencing::Geofence> {};
#endif

#ifndef WINRT_GENERIC_d8039aca_1a45_5d13_8cfd_4900c22b8ef1
#define WINRT_GENERIC_d8039aca_1a45_5d13_8cfd_4900c22b8ef1
template <> struct __declspec(uuid("d8039aca-1a45-5d13-8cfd-4900c22b8ef1")) __declspec(novtable) IVectorView<Windows::Devices::Geolocation::Geofencing::Geofence> : impl_IVectorView<Windows::Devices::Geolocation::Geofencing::Geofence> {};
#endif

#ifndef WINRT_GENERIC_eaff2de4_6650_544a_b7ac_6d5b819d4698
#define WINRT_GENERIC_eaff2de4_6650_544a_b7ac_6d5b819d4698
template <> struct __declspec(uuid("eaff2de4-6650-544a-b7ac-6d5b819d4698")) __declspec(novtable) IIterator<Windows::Devices::Geolocation::Geofencing::GeofenceStateChangeReport> : impl_IIterator<Windows::Devices::Geolocation::Geofencing::GeofenceStateChangeReport> {};
#endif

#ifndef WINRT_GENERIC_76f50b4e_7aa7_565b_aada_b0c1cc144ed0
#define WINRT_GENERIC_76f50b4e_7aa7_565b_aada_b0c1cc144ed0
template <> struct __declspec(uuid("76f50b4e-7aa7-565b-aada-b0c1cc144ed0")) __declspec(novtable) IIterable<Windows::Devices::Geolocation::Geofencing::GeofenceStateChangeReport> : impl_IIterable<Windows::Devices::Geolocation::Geofencing::GeofenceStateChangeReport> {};
#endif


}

namespace Windows::Devices::Geolocation::Geofencing {

struct IGeofence :
    Windows::Foundation::IInspectable,
    impl::consume<IGeofence>
{
    IGeofence(std::nullptr_t = nullptr) noexcept {}
};

struct IGeofenceFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IGeofenceFactory>
{
    IGeofenceFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IGeofenceMonitor :
    Windows::Foundation::IInspectable,
    impl::consume<IGeofenceMonitor>
{
    IGeofenceMonitor(std::nullptr_t = nullptr) noexcept {}
};

struct IGeofenceMonitorStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IGeofenceMonitorStatics>
{
    IGeofenceMonitorStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IGeofenceStateChangeReport :
    Windows::Foundation::IInspectable,
    impl::consume<IGeofenceStateChangeReport>
{
    IGeofenceStateChangeReport(std::nullptr_t = nullptr) noexcept {}
};

}

}
