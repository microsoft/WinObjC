// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Networking.Connectivity.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Networking::Connectivity {

template <typename H> struct impl_NetworkStatusChangedEventHandler : implements<impl_NetworkStatusChangedEventHandler<H>, abi<NetworkStatusChangedEventHandler>>, H
{
    impl_NetworkStatusChangedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Networking::Connectivity {

struct WINRT_EBO AttributedNetworkUsage :
    Windows::Networking::Connectivity::IAttributedNetworkUsage
{
    AttributedNetworkUsage(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CellularApnContext :
    Windows::Networking::Connectivity::ICellularApnContext
{
    CellularApnContext(std::nullptr_t) noexcept {}
    CellularApnContext();
};

struct WINRT_EBO ConnectionCost :
    Windows::Networking::Connectivity::IConnectionCost,
    impl::require<ConnectionCost, Windows::Networking::Connectivity::IConnectionCost2>
{
    ConnectionCost(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ConnectionProfile :
    Windows::Networking::Connectivity::IConnectionProfile,
    impl::require<ConnectionProfile, Windows::Networking::Connectivity::IConnectionProfile2, Windows::Networking::Connectivity::IConnectionProfile3>
{
    ConnectionProfile(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ConnectionProfileFilter :
    Windows::Networking::Connectivity::IConnectionProfileFilter,
    impl::require<ConnectionProfileFilter, Windows::Networking::Connectivity::IConnectionProfileFilter2>
{
    ConnectionProfileFilter(std::nullptr_t) noexcept {}
    ConnectionProfileFilter();
};

struct WINRT_EBO ConnectionSession :
    Windows::Networking::Connectivity::IConnectionSession
{
    ConnectionSession(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ConnectivityInterval :
    Windows::Networking::Connectivity::IConnectivityInterval
{
    ConnectivityInterval(std::nullptr_t) noexcept {}
};

struct ConnectivityManager
{
    ConnectivityManager() = delete;
    static Windows::Foundation::IAsyncOperation<Windows::Networking::Connectivity::ConnectionSession> AcquireConnectionAsync(const Windows::Networking::Connectivity::CellularApnContext & cellularApnContext);
    static void AddHttpRoutePolicy(const Windows::Networking::Connectivity::RoutePolicy & routePolicy);
    static void RemoveHttpRoutePolicy(const Windows::Networking::Connectivity::RoutePolicy & routePolicy);
};

struct WINRT_EBO DataPlanStatus :
    Windows::Networking::Connectivity::IDataPlanStatus
{
    DataPlanStatus(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DataPlanUsage :
    Windows::Networking::Connectivity::IDataPlanUsage
{
    DataPlanUsage(std::nullptr_t) noexcept {}
};

struct [[deprecated("DataUsage may be altered or unavailable for releases after Windows 8.1. Instead, use NetworkUsage.")]] WINRT_EBO DataUsage :
    Windows::Networking::Connectivity::IDataUsage
{
    DataUsage(std::nullptr_t) noexcept {}
};

struct WINRT_EBO IPInformation :
    Windows::Networking::Connectivity::IIPInformation
{
    IPInformation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO LanIdentifier :
    Windows::Networking::Connectivity::ILanIdentifier
{
    LanIdentifier(std::nullptr_t) noexcept {}
};

struct WINRT_EBO LanIdentifierData :
    Windows::Networking::Connectivity::ILanIdentifierData
{
    LanIdentifierData(std::nullptr_t) noexcept {}
};

struct WINRT_EBO NetworkAdapter :
    Windows::Networking::Connectivity::INetworkAdapter
{
    NetworkAdapter(std::nullptr_t) noexcept {}
};

struct NetworkInformation
{
    NetworkInformation() = delete;
    static Windows::Foundation::Collections::IVectorView<Windows::Networking::Connectivity::ConnectionProfile> GetConnectionProfiles();
    static Windows::Networking::Connectivity::ConnectionProfile GetInternetConnectionProfile();
    static Windows::Foundation::Collections::IVectorView<Windows::Networking::Connectivity::LanIdentifier> GetLanIdentifiers();
    static Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName> GetHostNames();
    static Windows::Foundation::IAsyncOperation<Windows::Networking::Connectivity::ProxyConfiguration> GetProxyConfigurationAsync(const Windows::Foundation::Uri & uri);
    static Windows::Foundation::Collections::IVectorView<Windows::Networking::EndpointPair> GetSortedEndpointPairs(iterable<Windows::Networking::EndpointPair> destinationList, Windows::Networking::HostNameSortOptions sortOptions);
    static event_token NetworkStatusChanged(const Windows::Networking::Connectivity::NetworkStatusChangedEventHandler & networkStatusHandler);
    using NetworkStatusChanged_revoker = factory_event_revoker<INetworkInformationStatics>;
    static NetworkStatusChanged_revoker NetworkStatusChanged(auto_revoke_t, const Windows::Networking::Connectivity::NetworkStatusChangedEventHandler & networkStatusHandler);
    static void NetworkStatusChanged(event_token eventCookie);
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::Connectivity::ConnectionProfile>> FindConnectionProfilesAsync(const Windows::Networking::Connectivity::ConnectionProfileFilter & pProfileFilter);
};

struct WINRT_EBO NetworkItem :
    Windows::Networking::Connectivity::INetworkItem
{
    NetworkItem(std::nullptr_t) noexcept {}
};

struct WINRT_EBO NetworkSecuritySettings :
    Windows::Networking::Connectivity::INetworkSecuritySettings
{
    NetworkSecuritySettings(std::nullptr_t) noexcept {}
};

struct WINRT_EBO NetworkStateChangeEventDetails :
    Windows::Networking::Connectivity::INetworkStateChangeEventDetails,
    impl::require<NetworkStateChangeEventDetails, Windows::Networking::Connectivity::INetworkStateChangeEventDetails2>
{
    NetworkStateChangeEventDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO NetworkUsage :
    Windows::Networking::Connectivity::INetworkUsage
{
    NetworkUsage(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ProxyConfiguration :
    Windows::Networking::Connectivity::IProxyConfiguration
{
    ProxyConfiguration(std::nullptr_t) noexcept {}
};

struct WINRT_EBO RoutePolicy :
    Windows::Networking::Connectivity::IRoutePolicy
{
    RoutePolicy(std::nullptr_t) noexcept {}
    RoutePolicy(const Windows::Networking::Connectivity::ConnectionProfile & connectionProfile, const Windows::Networking::HostName & hostName, Windows::Networking::DomainNameType type);
};

struct WINRT_EBO WlanConnectionProfileDetails :
    Windows::Networking::Connectivity::IWlanConnectionProfileDetails
{
    WlanConnectionProfileDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WwanConnectionProfileDetails :
    Windows::Networking::Connectivity::IWwanConnectionProfileDetails
{
    WwanConnectionProfileDetails(std::nullptr_t) noexcept {}
};

}

}
