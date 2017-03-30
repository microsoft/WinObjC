// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::WiFi {

struct IWiFiAdapter;
struct IWiFiAdapterStatics;
struct IWiFiAvailableNetwork;
struct IWiFiConnectionResult;
struct IWiFiNetworkReport;
struct WiFiAdapter;
struct WiFiAvailableNetwork;
struct WiFiConnectionResult;
struct WiFiNetworkReport;

}

namespace Windows::Devices::WiFi {

struct IWiFiAdapter;
struct IWiFiAdapterStatics;
struct IWiFiAvailableNetwork;
struct IWiFiConnectionResult;
struct IWiFiNetworkReport;
struct WiFiAdapter;
struct WiFiAvailableNetwork;
struct WiFiConnectionResult;
struct WiFiNetworkReport;

}

namespace Windows::Devices::WiFi {

template <typename T> struct impl_IWiFiAdapter;
template <typename T> struct impl_IWiFiAdapterStatics;
template <typename T> struct impl_IWiFiAvailableNetwork;
template <typename T> struct impl_IWiFiConnectionResult;
template <typename T> struct impl_IWiFiNetworkReport;

}

namespace Windows::Devices::WiFi {

enum class WiFiAccessStatus
{
    Unspecified = 0,
    Allowed = 1,
    DeniedByUser = 2,
    DeniedBySystem = 3,
};

enum class WiFiConnectionStatus
{
    UnspecifiedFailure = 0,
    Success = 1,
    AccessRevoked = 2,
    InvalidCredential = 3,
    NetworkNotAvailable = 4,
    Timeout = 5,
    UnsupportedAuthenticationProtocol = 6,
};

enum class WiFiNetworkKind
{
    Any = 0,
    Infrastructure = 1,
    Adhoc = 2,
};

enum class WiFiPhyKind
{
    Unknown = 0,
    Fhss = 1,
    Dsss = 2,
    IRBaseband = 3,
    Ofdm = 4,
    Hrdsss = 5,
    Erp = 6,
    HT = 7,
    Vht = 8,
    Dmg = 9,
};

enum class WiFiReconnectionKind
{
    Automatic = 0,
    Manual = 1,
};

}

}
