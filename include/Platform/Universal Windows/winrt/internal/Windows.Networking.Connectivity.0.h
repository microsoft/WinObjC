// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Networking::Connectivity {

struct NetworkUsageStates;

}

namespace Windows::Networking::Connectivity {

using NetworkUsageStates = ABI::Windows::Networking::Connectivity::NetworkUsageStates;

}

namespace ABI::Windows::Networking::Connectivity {

struct IAttributedNetworkUsage;
struct ICellularApnContext;
struct IConnectionCost;
struct IConnectionCost2;
struct IConnectionProfile;
struct IConnectionProfile2;
struct IConnectionProfile3;
struct IConnectionProfileFilter;
struct IConnectionProfileFilter2;
struct IConnectionSession;
struct IConnectivityInterval;
struct IConnectivityManagerStatics;
struct IDataPlanStatus;
struct IDataPlanUsage;
struct IDataUsage;
struct IIPInformation;
struct ILanIdentifier;
struct ILanIdentifierData;
struct INetworkAdapter;
struct INetworkInformationStatics;
struct INetworkInformationStatics2;
struct INetworkItem;
struct INetworkSecuritySettings;
struct INetworkStateChangeEventDetails;
struct INetworkStateChangeEventDetails2;
struct INetworkUsage;
struct IProxyConfiguration;
struct IRoutePolicy;
struct IRoutePolicyFactory;
struct IWlanConnectionProfileDetails;
struct IWwanConnectionProfileDetails;
struct NetworkStatusChangedEventHandler;
struct AttributedNetworkUsage;
struct CellularApnContext;
struct ConnectionCost;
struct ConnectionProfile;
struct ConnectionProfileFilter;
struct ConnectionSession;
struct ConnectivityInterval;
struct DataPlanStatus;
struct DataPlanUsage;
struct DataUsage;
struct IPInformation;
struct LanIdentifier;
struct LanIdentifierData;
struct NetworkAdapter;
struct NetworkItem;
struct NetworkSecuritySettings;
struct NetworkStateChangeEventDetails;
struct NetworkUsage;
struct ProxyConfiguration;
struct RoutePolicy;
struct WlanConnectionProfileDetails;
struct WwanConnectionProfileDetails;

}

namespace Windows::Networking::Connectivity {

struct NetworkStatusChangedEventHandler;
struct IAttributedNetworkUsage;
struct ICellularApnContext;
struct IConnectionCost;
struct IConnectionCost2;
struct IConnectionProfile;
struct IConnectionProfile2;
struct IConnectionProfile3;
struct IConnectionProfileFilter;
struct IConnectionProfileFilter2;
struct IConnectionSession;
struct IConnectivityInterval;
struct IConnectivityManagerStatics;
struct IDataPlanStatus;
struct IDataPlanUsage;
struct IDataUsage;
struct IIPInformation;
struct ILanIdentifier;
struct ILanIdentifierData;
struct INetworkAdapter;
struct INetworkInformationStatics;
struct INetworkInformationStatics2;
struct INetworkItem;
struct INetworkSecuritySettings;
struct INetworkStateChangeEventDetails;
struct INetworkStateChangeEventDetails2;
struct INetworkUsage;
struct IProxyConfiguration;
struct IRoutePolicy;
struct IRoutePolicyFactory;
struct IWlanConnectionProfileDetails;
struct IWwanConnectionProfileDetails;
struct AttributedNetworkUsage;
struct CellularApnContext;
struct ConnectionCost;
struct ConnectionProfile;
struct ConnectionProfileFilter;
struct ConnectionSession;
struct ConnectivityInterval;
struct ConnectivityManager;
struct DataPlanStatus;
struct DataPlanUsage;
struct DataUsage;
struct IPInformation;
struct LanIdentifier;
struct LanIdentifierData;
struct NetworkAdapter;
struct NetworkInformation;
struct NetworkItem;
struct NetworkSecuritySettings;
struct NetworkStateChangeEventDetails;
struct NetworkUsage;
struct ProxyConfiguration;
struct RoutePolicy;
struct WlanConnectionProfileDetails;
struct WwanConnectionProfileDetails;

}

namespace Windows::Networking::Connectivity {

template <typename T> struct impl_IAttributedNetworkUsage;
template <typename T> struct impl_ICellularApnContext;
template <typename T> struct impl_IConnectionCost;
template <typename T> struct impl_IConnectionCost2;
template <typename T> struct impl_IConnectionProfile;
template <typename T> struct impl_IConnectionProfile2;
template <typename T> struct impl_IConnectionProfile3;
template <typename T> struct impl_IConnectionProfileFilter;
template <typename T> struct impl_IConnectionProfileFilter2;
template <typename T> struct impl_IConnectionSession;
template <typename T> struct impl_IConnectivityInterval;
template <typename T> struct impl_IConnectivityManagerStatics;
template <typename T> struct impl_IDataPlanStatus;
template <typename T> struct impl_IDataPlanUsage;
template <typename T> struct impl_IDataUsage;
template <typename T> struct impl_IIPInformation;
template <typename T> struct impl_ILanIdentifier;
template <typename T> struct impl_ILanIdentifierData;
template <typename T> struct impl_INetworkAdapter;
template <typename T> struct impl_INetworkInformationStatics;
template <typename T> struct impl_INetworkInformationStatics2;
template <typename T> struct impl_INetworkItem;
template <typename T> struct impl_INetworkSecuritySettings;
template <typename T> struct impl_INetworkStateChangeEventDetails;
template <typename T> struct impl_INetworkStateChangeEventDetails2;
template <typename T> struct impl_INetworkUsage;
template <typename T> struct impl_IProxyConfiguration;
template <typename T> struct impl_IRoutePolicy;
template <typename T> struct impl_IRoutePolicyFactory;
template <typename T> struct impl_IWlanConnectionProfileDetails;
template <typename T> struct impl_IWwanConnectionProfileDetails;
template <typename T> struct impl_NetworkStatusChangedEventHandler;

}

namespace Windows::Networking::Connectivity {

enum class CellularApnAuthenticationType
{
    None = 0,
    Pap = 1,
    Chap = 2,
    Mschapv2 = 3,
};

enum class DataUsageGranularity
{
    PerMinute = 0,
    PerHour = 1,
    PerDay = 2,
    Total = 3,
};

enum class DomainConnectivityLevel
{
    None = 0,
    Unauthenticated = 1,
    Authenticated = 2,
};

enum class NetworkAuthenticationType
{
    None = 0,
    Unknown = 1,
    Open80211 = 2,
    SharedKey80211 = 3,
    Wpa = 4,
    WpaPsk = 5,
    WpaNone = 6,
    Rsna = 7,
    RsnaPsk = 8,
    Ihv = 9,
};

enum class NetworkConnectivityLevel
{
    None = 0,
    LocalAccess = 1,
    ConstrainedInternetAccess = 2,
    InternetAccess = 3,
};

enum class NetworkCostType
{
    Unknown = 0,
    Unrestricted = 1,
    Fixed = 2,
    Variable = 3,
};

enum class NetworkEncryptionType
{
    None = 0,
    Unknown = 1,
    Wep = 2,
    Wep40 = 3,
    Wep104 = 4,
    Tkip = 5,
    Ccmp = 6,
    WpaUseGroup = 7,
    RsnUseGroup = 8,
    Ihv = 9,
};

enum class NetworkTypes : unsigned
{
    None = 0x0,
    Internet = 0x1,
    PrivateNetwork = 0x2,
};

DEFINE_ENUM_FLAG_OPERATORS(NetworkTypes)

enum class RoamingStates : unsigned
{
    None = 0x0,
    NotRoaming = 0x1,
    Roaming = 0x2,
};

DEFINE_ENUM_FLAG_OPERATORS(RoamingStates)

enum class TriStates
{
    DoNotCare = 0,
    No = 1,
    Yes = 2,
};

enum class WwanDataClass : unsigned
{
    None = 0x0,
    Gprs = 0x1,
    Edge = 0x2,
    Umts = 0x4,
    Hsdpa = 0x8,
    Hsupa = 0x10,
    LteAdvanced = 0x20,
    Cdma1xRtt = 0x10000,
    Cdma1xEvdo = 0x20000,
    Cdma1xEvdoRevA = 0x40000,
    Cdma1xEvdv = 0x80000,
    Cdma3xRtt = 0x100000,
    Cdma1xEvdoRevB = 0x200000,
    CdmaUmb = 0x400000,
    Custom = 0x80000000,
};

DEFINE_ENUM_FLAG_OPERATORS(WwanDataClass)

enum class WwanNetworkRegistrationState
{
    None = 0,
    Deregistered = 1,
    Searching = 2,
    Home = 3,
    Roaming = 4,
    Partner = 5,
    Denied = 6,
};

}

}
