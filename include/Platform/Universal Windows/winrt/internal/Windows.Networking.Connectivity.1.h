// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Networking.Connectivity.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Networking.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Networking.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Networking::Connectivity {

struct NetworkUsageStates
{
    winrt::Windows::Networking::Connectivity::TriStates Roaming;
    winrt::Windows::Networking::Connectivity::TriStates Shared;
};

}

namespace Windows::Networking::Connectivity {

using NetworkUsageStates = ABI::Windows::Networking::Connectivity::NetworkUsageStates;

}

namespace ABI::Windows::Networking::Connectivity {

struct __declspec(uuid("f769b039-eca2-45eb-ade1-b0368b756c49")) __declspec(novtable) IAttributedNetworkUsage : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_BytesSent(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_BytesReceived(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_AttributionId(hstring * value) = 0;
    virtual HRESULT __stdcall get_AttributionName(hstring * value) = 0;
    virtual HRESULT __stdcall get_AttributionThumbnail(Windows::Storage::Streams::IRandomAccessStreamReference ** value) = 0;
};

struct __declspec(uuid("6fa529f4-effd-4542-9ab2-705bbf94943a")) __declspec(novtable) ICellularApnContext : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ProviderId(hstring * value) = 0;
    virtual HRESULT __stdcall put_ProviderId(hstring value) = 0;
    virtual HRESULT __stdcall get_AccessPointName(hstring * value) = 0;
    virtual HRESULT __stdcall put_AccessPointName(hstring value) = 0;
    virtual HRESULT __stdcall get_UserName(hstring * value) = 0;
    virtual HRESULT __stdcall put_UserName(hstring value) = 0;
    virtual HRESULT __stdcall get_Password(hstring * value) = 0;
    virtual HRESULT __stdcall put_Password(hstring value) = 0;
    virtual HRESULT __stdcall get_IsCompressionEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsCompressionEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_AuthenticationType(winrt::Windows::Networking::Connectivity::CellularApnAuthenticationType * value) = 0;
    virtual HRESULT __stdcall put_AuthenticationType(winrt::Windows::Networking::Connectivity::CellularApnAuthenticationType value) = 0;
};

struct __declspec(uuid("bad7d829-3416-4b10-a202-bac0b075bdae")) __declspec(novtable) IConnectionCost : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_NetworkCostType(winrt::Windows::Networking::Connectivity::NetworkCostType * value) = 0;
    virtual HRESULT __stdcall get_Roaming(bool * value) = 0;
    virtual HRESULT __stdcall get_OverDataLimit(bool * value) = 0;
    virtual HRESULT __stdcall get_ApproachingDataLimit(bool * value) = 0;
};

struct __declspec(uuid("8e113a05-e209-4549-bb25-5e0db691cb05")) __declspec(novtable) IConnectionCost2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_BackgroundDataUsageRestricted(bool * value) = 0;
};

struct __declspec(uuid("71ba143c-598e-49d0-84eb-8febaedcc195")) __declspec(novtable) IConnectionProfile : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ProfileName(hstring * value) = 0;
    virtual HRESULT __stdcall abi_GetNetworkConnectivityLevel(winrt::Windows::Networking::Connectivity::NetworkConnectivityLevel * value) = 0;
    virtual HRESULT __stdcall abi_GetNetworkNames(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
    virtual HRESULT __stdcall abi_GetConnectionCost(Windows::Networking::Connectivity::IConnectionCost ** value) = 0;
    virtual HRESULT __stdcall abi_GetDataPlanStatus(Windows::Networking::Connectivity::IDataPlanStatus ** value) = 0;
    virtual HRESULT __stdcall get_NetworkAdapter(Windows::Networking::Connectivity::INetworkAdapter ** value) = 0;
    virtual HRESULT __stdcall abi_GetLocalUsage(Windows::Foundation::DateTime StartTime, Windows::Foundation::DateTime EndTime, Windows::Networking::Connectivity::IDataUsage ** value) = 0;
    virtual HRESULT __stdcall abi_GetLocalUsagePerRoamingStates(Windows::Foundation::DateTime StartTime, Windows::Foundation::DateTime EndTime, winrt::Windows::Networking::Connectivity::RoamingStates States, Windows::Networking::Connectivity::IDataUsage ** value) = 0;
    virtual HRESULT __stdcall get_NetworkSecuritySettings(Windows::Networking::Connectivity::INetworkSecuritySettings ** value) = 0;
};

struct __declspec(uuid("e2045145-4c9f-400c-9150-7ec7d6e2888a")) __declspec(novtable) IConnectionProfile2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsWwanConnectionProfile(bool * value) = 0;
    virtual HRESULT __stdcall get_IsWlanConnectionProfile(bool * value) = 0;
    virtual HRESULT __stdcall get_WwanConnectionProfileDetails(Windows::Networking::Connectivity::IWwanConnectionProfileDetails ** value) = 0;
    virtual HRESULT __stdcall get_WlanConnectionProfileDetails(Windows::Networking::Connectivity::IWlanConnectionProfileDetails ** value) = 0;
    virtual HRESULT __stdcall get_ServiceProviderGuid(Windows::Foundation::IReference<GUID> ** value) = 0;
    virtual HRESULT __stdcall abi_GetSignalBars(Windows::Foundation::IReference<uint8_t> ** value) = 0;
    virtual HRESULT __stdcall abi_GetDomainConnectivityLevel(winrt::Windows::Networking::Connectivity::DomainConnectivityLevel * value) = 0;
    virtual HRESULT __stdcall abi_GetNetworkUsageAsync(Windows::Foundation::DateTime startTime, Windows::Foundation::DateTime endTime, winrt::Windows::Networking::Connectivity::DataUsageGranularity granularity, Windows::Networking::Connectivity::NetworkUsageStates states, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::Connectivity::NetworkUsage>> ** value) = 0;
    virtual HRESULT __stdcall abi_GetConnectivityIntervalsAsync(Windows::Foundation::DateTime startTime, Windows::Foundation::DateTime endTime, Windows::Networking::Connectivity::NetworkUsageStates states, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::Connectivity::ConnectivityInterval>> ** value) = 0;
};

struct __declspec(uuid("578c2528-4cd9-4161-8045-201cfd5b115c")) __declspec(novtable) IConnectionProfile3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetAttributedNetworkUsageAsync(Windows::Foundation::DateTime startTime, Windows::Foundation::DateTime endTime, Windows::Networking::Connectivity::NetworkUsageStates states, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::Connectivity::AttributedNetworkUsage>> ** value) = 0;
};

struct __declspec(uuid("204c7cc8-bd2d-4e8d-a4b3-455ec337388a")) __declspec(novtable) IConnectionProfileFilter : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_IsConnected(bool value) = 0;
    virtual HRESULT __stdcall get_IsConnected(bool * value) = 0;
    virtual HRESULT __stdcall put_IsWwanConnectionProfile(bool value) = 0;
    virtual HRESULT __stdcall get_IsWwanConnectionProfile(bool * value) = 0;
    virtual HRESULT __stdcall put_IsWlanConnectionProfile(bool value) = 0;
    virtual HRESULT __stdcall get_IsWlanConnectionProfile(bool * value) = 0;
    virtual HRESULT __stdcall put_NetworkCostType(winrt::Windows::Networking::Connectivity::NetworkCostType value) = 0;
    virtual HRESULT __stdcall get_NetworkCostType(winrt::Windows::Networking::Connectivity::NetworkCostType * value) = 0;
    virtual HRESULT __stdcall put_ServiceProviderGuid(Windows::Foundation::IReference<GUID> * value) = 0;
    virtual HRESULT __stdcall get_ServiceProviderGuid(Windows::Foundation::IReference<GUID> ** value) = 0;
};

struct __declspec(uuid("cd068ee1-c3fc-4fad-9ddc-593faa4b7885")) __declspec(novtable) IConnectionProfileFilter2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_IsRoaming(Windows::Foundation::IReference<bool> * value) = 0;
    virtual HRESULT __stdcall get_IsRoaming(Windows::Foundation::IReference<bool> ** value) = 0;
    virtual HRESULT __stdcall put_IsOverDataLimit(Windows::Foundation::IReference<bool> * value) = 0;
    virtual HRESULT __stdcall get_IsOverDataLimit(Windows::Foundation::IReference<bool> ** value) = 0;
    virtual HRESULT __stdcall put_IsBackgroundDataUsageRestricted(Windows::Foundation::IReference<bool> * value) = 0;
    virtual HRESULT __stdcall get_IsBackgroundDataUsageRestricted(Windows::Foundation::IReference<bool> ** value) = 0;
    virtual HRESULT __stdcall get_RawData(Windows::Storage::Streams::IBuffer ** value) = 0;
};

struct __declspec(uuid("ff905d4c-f83b-41b0-8a0c-1462d9c56b73")) __declspec(novtable) IConnectionSession : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ConnectionProfile(Windows::Networking::Connectivity::IConnectionProfile ** value) = 0;
};

struct __declspec(uuid("4faa3fff-6746-4824-a964-eed8e87f8709")) __declspec(novtable) IConnectivityInterval : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_StartTime(Windows::Foundation::DateTime * startTime) = 0;
    virtual HRESULT __stdcall get_ConnectionDuration(Windows::Foundation::TimeSpan * duration) = 0;
};

struct __declspec(uuid("5120d4b1-4fb1-48b0-afc9-42e0092a8164")) __declspec(novtable) IConnectivityManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_AcquireConnectionAsync(Windows::Networking::Connectivity::ICellularApnContext * cellularApnContext, Windows::Foundation::IAsyncOperation<Windows::Networking::Connectivity::ConnectionSession> ** operation) = 0;
    virtual HRESULT __stdcall abi_AddHttpRoutePolicy(Windows::Networking::Connectivity::IRoutePolicy * routePolicy) = 0;
    virtual HRESULT __stdcall abi_RemoveHttpRoutePolicy(Windows::Networking::Connectivity::IRoutePolicy * routePolicy) = 0;
};

struct __declspec(uuid("977a8b8c-3885-40f3-8851-42cd2bd568bb")) __declspec(novtable) IDataPlanStatus : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DataPlanUsage(Windows::Networking::Connectivity::IDataPlanUsage ** value) = 0;
    virtual HRESULT __stdcall get_DataLimitInMegabytes(Windows::Foundation::IReference<uint32_t> ** value) = 0;
    virtual HRESULT __stdcall get_InboundBitsPerSecond(Windows::Foundation::IReference<uint64_t> ** value) = 0;
    virtual HRESULT __stdcall get_OutboundBitsPerSecond(Windows::Foundation::IReference<uint64_t> ** value) = 0;
    virtual HRESULT __stdcall get_NextBillingCycle(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall get_MaxTransferSizeInMegabytes(Windows::Foundation::IReference<uint32_t> ** value) = 0;
};

struct __declspec(uuid("b921492d-3b44-47ff-b361-be59e69ed1b0")) __declspec(novtable) IDataPlanUsage : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MegabytesUsed(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_LastSyncTime(Windows::Foundation::DateTime * value) = 0;
};

struct __declspec(uuid("c1431dd3-b146-4d39-b959-0c69b096c512")) __declspec(novtable) IDataUsage : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_BytesSent(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_BytesReceived(uint64_t * value) = 0;
};

struct __declspec(uuid("d85145e0-138f-47d7-9b3a-36bb488cef33")) __declspec(novtable) IIPInformation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_NetworkAdapter(Windows::Networking::Connectivity::INetworkAdapter ** value) = 0;
    virtual HRESULT __stdcall get_PrefixLength(Windows::Foundation::IReference<uint8_t> ** value) = 0;
};

struct __declspec(uuid("48aa53aa-1108-4546-a6cb-9a74da4b7ba0")) __declspec(novtable) ILanIdentifier : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_InfrastructureId(Windows::Networking::Connectivity::ILanIdentifierData ** value) = 0;
    virtual HRESULT __stdcall get_PortId(Windows::Networking::Connectivity::ILanIdentifierData ** value) = 0;
    virtual HRESULT __stdcall get_NetworkAdapterId(GUID * value) = 0;
};

struct __declspec(uuid("a74e83c3-d639-45be-a36a-c4e4aeaf6d9b")) __declspec(novtable) ILanIdentifierData : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Type(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_Value(Windows::Foundation::Collections::IVectorView<uint8_t> ** value) = 0;
};

struct __declspec(uuid("3b542e03-5388-496c-a8a3-affd39aec2e6")) __declspec(novtable) INetworkAdapter : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_OutboundMaxBitsPerSecond(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_InboundMaxBitsPerSecond(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_IanaInterfaceType(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_NetworkItem(Windows::Networking::Connectivity::INetworkItem ** value) = 0;
    virtual HRESULT __stdcall get_NetworkAdapterId(GUID * value) = 0;
    virtual HRESULT __stdcall abi_GetConnectedProfileAsync(Windows::Foundation::IAsyncOperation<Windows::Networking::Connectivity::ConnectionProfile> ** value) = 0;
};

struct __declspec(uuid("5074f851-950d-4165-9c15-365619481eea")) __declspec(novtable) INetworkInformationStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetConnectionProfiles(Windows::Foundation::Collections::IVectorView<Windows::Networking::Connectivity::ConnectionProfile> ** value) = 0;
    virtual HRESULT __stdcall abi_GetInternetConnectionProfile(Windows::Networking::Connectivity::IConnectionProfile ** value) = 0;
    virtual HRESULT __stdcall abi_GetLanIdentifiers(Windows::Foundation::Collections::IVectorView<Windows::Networking::Connectivity::LanIdentifier> ** value) = 0;
    virtual HRESULT __stdcall abi_GetHostNames(Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName> ** value) = 0;
    virtual HRESULT __stdcall abi_GetProxyConfigurationAsync(Windows::Foundation::IUriRuntimeClass * uri, Windows::Foundation::IAsyncOperation<Windows::Networking::Connectivity::ProxyConfiguration> ** value) = 0;
    virtual HRESULT __stdcall abi_GetSortedEndpointPairs(Windows::Foundation::Collections::IIterable<Windows::Networking::EndpointPair> * destinationList, winrt::Windows::Networking::HostNameSortOptions sortOptions, Windows::Foundation::Collections::IVectorView<Windows::Networking::EndpointPair> ** value) = 0;
    virtual HRESULT __stdcall add_NetworkStatusChanged(Windows::Networking::Connectivity::NetworkStatusChangedEventHandler * networkStatusHandler, event_token * eventCookie) = 0;
    virtual HRESULT __stdcall remove_NetworkStatusChanged(event_token eventCookie) = 0;
};

struct __declspec(uuid("459ced14-2832-49b6-ba6e-e265f04786a8")) __declspec(novtable) INetworkInformationStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FindConnectionProfilesAsync(Windows::Networking::Connectivity::IConnectionProfileFilter * pProfileFilter, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::Connectivity::ConnectionProfile>> ** value) = 0;
};

struct __declspec(uuid("01bc4d39-f5e0-4567-a28c-42080c831b2b")) __declspec(novtable) INetworkItem : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_NetworkId(GUID * value) = 0;
    virtual HRESULT __stdcall abi_GetNetworkTypes(winrt::Windows::Networking::Connectivity::NetworkTypes * value) = 0;
};

struct __declspec(uuid("7ca07e8d-917b-4b5f-b84d-28f7a5ac5402")) __declspec(novtable) INetworkSecuritySettings : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_NetworkAuthenticationType(winrt::Windows::Networking::Connectivity::NetworkAuthenticationType * value) = 0;
    virtual HRESULT __stdcall get_NetworkEncryptionType(winrt::Windows::Networking::Connectivity::NetworkEncryptionType * value) = 0;
};

struct __declspec(uuid("1f0cf333-d7a6-44dd-a4e9-687c476b903d")) __declspec(novtable) INetworkStateChangeEventDetails : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_HasNewInternetConnectionProfile(bool * value) = 0;
    virtual HRESULT __stdcall get_HasNewConnectionCost(bool * value) = 0;
    virtual HRESULT __stdcall get_HasNewNetworkConnectivityLevel(bool * value) = 0;
    virtual HRESULT __stdcall get_HasNewDomainConnectivityLevel(bool * value) = 0;
    virtual HRESULT __stdcall get_HasNewHostNameList(bool * value) = 0;
    virtual HRESULT __stdcall get_HasNewWwanRegistrationState(bool * value) = 0;
};

struct __declspec(uuid("d643c0e8-30d3-4f6a-ad47-6a1873ceb3c1")) __declspec(novtable) INetworkStateChangeEventDetails2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_HasNewTetheringOperationalState(bool * value) = 0;
    virtual HRESULT __stdcall get_HasNewTetheringClientCount(bool * value) = 0;
};

struct __declspec(uuid("49da8fce-9985-4927-bf5b-072b5c65f8d9")) __declspec(novtable) INetworkUsage : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_BytesSent(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_BytesReceived(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_ConnectionDuration(Windows::Foundation::TimeSpan * duration) = 0;
};

struct __declspec(uuid("ef3a60b4-9004-4dd6-b7d8-b3e502f4aad0")) __declspec(novtable) IProxyConfiguration : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ProxyUris(Windows::Foundation::Collections::IVectorView<Windows::Foundation::Uri> ** value) = 0;
    virtual HRESULT __stdcall get_CanConnectDirectly(bool * value) = 0;
};

struct __declspec(uuid("11abc4ac-0fc7-42e4-8742-569923b1ca11")) __declspec(novtable) IRoutePolicy : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ConnectionProfile(Windows::Networking::Connectivity::IConnectionProfile ** value) = 0;
    virtual HRESULT __stdcall get_HostName(Windows::Networking::IHostName ** value) = 0;
    virtual HRESULT __stdcall get_HostNameType(winrt::Windows::Networking::DomainNameType * value) = 0;
};

struct __declspec(uuid("36027933-a18e-4db5-a697-f58fa7364e44")) __declspec(novtable) IRoutePolicyFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateRoutePolicy(Windows::Networking::Connectivity::IConnectionProfile * connectionProfile, Windows::Networking::IHostName * hostName, winrt::Windows::Networking::DomainNameType type, Windows::Networking::Connectivity::IRoutePolicy ** routePolicy) = 0;
};

struct __declspec(uuid("562098cb-b35a-4bf1-a884-b7557e88ff86")) __declspec(novtable) IWlanConnectionProfileDetails : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetConnectedSsid(hstring * value) = 0;
};

struct __declspec(uuid("0e4da8fe-835f-4df3-82fd-df556ebc09ef")) __declspec(novtable) IWwanConnectionProfileDetails : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_HomeProviderId(hstring * value) = 0;
    virtual HRESULT __stdcall get_AccessPointName(hstring * value) = 0;
    virtual HRESULT __stdcall abi_GetNetworkRegistrationState(winrt::Windows::Networking::Connectivity::WwanNetworkRegistrationState * value) = 0;
    virtual HRESULT __stdcall abi_GetCurrentDataClass(winrt::Windows::Networking::Connectivity::WwanDataClass * value) = 0;
};

struct __declspec(uuid("71ba143f-598e-49d0-84eb-8febaedcc195")) __declspec(novtable) NetworkStatusChangedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Networking::Connectivity::AttributedNetworkUsage> { using default_interface = Windows::Networking::Connectivity::IAttributedNetworkUsage; };
template <> struct traits<Windows::Networking::Connectivity::CellularApnContext> { using default_interface = Windows::Networking::Connectivity::ICellularApnContext; };
template <> struct traits<Windows::Networking::Connectivity::ConnectionCost> { using default_interface = Windows::Networking::Connectivity::IConnectionCost; };
template <> struct traits<Windows::Networking::Connectivity::ConnectionProfile> { using default_interface = Windows::Networking::Connectivity::IConnectionProfile; };
template <> struct traits<Windows::Networking::Connectivity::ConnectionProfileFilter> { using default_interface = Windows::Networking::Connectivity::IConnectionProfileFilter; };
template <> struct traits<Windows::Networking::Connectivity::ConnectionSession> { using default_interface = Windows::Networking::Connectivity::IConnectionSession; };
template <> struct traits<Windows::Networking::Connectivity::ConnectivityInterval> { using default_interface = Windows::Networking::Connectivity::IConnectivityInterval; };
template <> struct traits<Windows::Networking::Connectivity::DataPlanStatus> { using default_interface = Windows::Networking::Connectivity::IDataPlanStatus; };
template <> struct traits<Windows::Networking::Connectivity::DataPlanUsage> { using default_interface = Windows::Networking::Connectivity::IDataPlanUsage; };
template <> struct traits<Windows::Networking::Connectivity::DataUsage> { using default_interface = Windows::Networking::Connectivity::IDataUsage; };
template <> struct traits<Windows::Networking::Connectivity::IPInformation> { using default_interface = Windows::Networking::Connectivity::IIPInformation; };
template <> struct traits<Windows::Networking::Connectivity::LanIdentifier> { using default_interface = Windows::Networking::Connectivity::ILanIdentifier; };
template <> struct traits<Windows::Networking::Connectivity::LanIdentifierData> { using default_interface = Windows::Networking::Connectivity::ILanIdentifierData; };
template <> struct traits<Windows::Networking::Connectivity::NetworkAdapter> { using default_interface = Windows::Networking::Connectivity::INetworkAdapter; };
template <> struct traits<Windows::Networking::Connectivity::NetworkItem> { using default_interface = Windows::Networking::Connectivity::INetworkItem; };
template <> struct traits<Windows::Networking::Connectivity::NetworkSecuritySettings> { using default_interface = Windows::Networking::Connectivity::INetworkSecuritySettings; };
template <> struct traits<Windows::Networking::Connectivity::NetworkStateChangeEventDetails> { using default_interface = Windows::Networking::Connectivity::INetworkStateChangeEventDetails; };
template <> struct traits<Windows::Networking::Connectivity::NetworkUsage> { using default_interface = Windows::Networking::Connectivity::INetworkUsage; };
template <> struct traits<Windows::Networking::Connectivity::ProxyConfiguration> { using default_interface = Windows::Networking::Connectivity::IProxyConfiguration; };
template <> struct traits<Windows::Networking::Connectivity::RoutePolicy> { using default_interface = Windows::Networking::Connectivity::IRoutePolicy; };
template <> struct traits<Windows::Networking::Connectivity::WlanConnectionProfileDetails> { using default_interface = Windows::Networking::Connectivity::IWlanConnectionProfileDetails; };
template <> struct traits<Windows::Networking::Connectivity::WwanConnectionProfileDetails> { using default_interface = Windows::Networking::Connectivity::IWwanConnectionProfileDetails; };

}

namespace Windows::Networking::Connectivity {

template <typename D>
struct WINRT_EBO impl_IAttributedNetworkUsage
{
    uint64_t BytesSent() const;
    uint64_t BytesReceived() const;
    hstring AttributionId() const;
    hstring AttributionName() const;
    Windows::Storage::Streams::IRandomAccessStreamReference AttributionThumbnail() const;
};

template <typename D>
struct WINRT_EBO impl_ICellularApnContext
{
    hstring ProviderId() const;
    void ProviderId(hstring_view value) const;
    hstring AccessPointName() const;
    void AccessPointName(hstring_view value) const;
    hstring UserName() const;
    void UserName(hstring_view value) const;
    hstring Password() const;
    void Password(hstring_view value) const;
    bool IsCompressionEnabled() const;
    void IsCompressionEnabled(bool value) const;
    Windows::Networking::Connectivity::CellularApnAuthenticationType AuthenticationType() const;
    void AuthenticationType(Windows::Networking::Connectivity::CellularApnAuthenticationType value) const;
};

template <typename D>
struct WINRT_EBO impl_IConnectionCost
{
    Windows::Networking::Connectivity::NetworkCostType NetworkCostType() const;
    bool Roaming() const;
    bool OverDataLimit() const;
    bool ApproachingDataLimit() const;
};

template <typename D>
struct WINRT_EBO impl_IConnectionCost2
{
    bool BackgroundDataUsageRestricted() const;
};

template <typename D>
struct WINRT_EBO impl_IConnectionProfile
{
    hstring ProfileName() const;
    Windows::Networking::Connectivity::NetworkConnectivityLevel GetNetworkConnectivityLevel() const;
    Windows::Foundation::Collections::IVectorView<hstring> GetNetworkNames() const;
    Windows::Networking::Connectivity::ConnectionCost GetConnectionCost() const;
    Windows::Networking::Connectivity::DataPlanStatus GetDataPlanStatus() const;
    Windows::Networking::Connectivity::NetworkAdapter NetworkAdapter() const;
    [[deprecated("GetLocalUsage may be altered or unavailable for releases after Windows 8.1. Instead, use GetNetworkUsageAsync.")]] Windows::Networking::Connectivity::DataUsage GetLocalUsage(const Windows::Foundation::DateTime & StartTime, const Windows::Foundation::DateTime & EndTime) const;
    [[deprecated("GetLocalUsage may be altered or unavailable for releases after Windows 8.1. Instead, use GetNetworkUsageAsync.")]] Windows::Networking::Connectivity::DataUsage GetLocalUsage(const Windows::Foundation::DateTime & StartTime, const Windows::Foundation::DateTime & EndTime, Windows::Networking::Connectivity::RoamingStates States) const;
    Windows::Networking::Connectivity::NetworkSecuritySettings NetworkSecuritySettings() const;
};

template <typename D>
struct WINRT_EBO impl_IConnectionProfile2
{
    bool IsWwanConnectionProfile() const;
    bool IsWlanConnectionProfile() const;
    Windows::Networking::Connectivity::WwanConnectionProfileDetails WwanConnectionProfileDetails() const;
    Windows::Networking::Connectivity::WlanConnectionProfileDetails WlanConnectionProfileDetails() const;
    Windows::Foundation::IReference<GUID> ServiceProviderGuid() const;
    Windows::Foundation::IReference<uint8_t> GetSignalBars() const;
    Windows::Networking::Connectivity::DomainConnectivityLevel GetDomainConnectivityLevel() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::Connectivity::NetworkUsage>> GetNetworkUsageAsync(const Windows::Foundation::DateTime & startTime, const Windows::Foundation::DateTime & endTime, Windows::Networking::Connectivity::DataUsageGranularity granularity, const Windows::Networking::Connectivity::NetworkUsageStates & states) const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::Connectivity::ConnectivityInterval>> GetConnectivityIntervalsAsync(const Windows::Foundation::DateTime & startTime, const Windows::Foundation::DateTime & endTime, const Windows::Networking::Connectivity::NetworkUsageStates & states) const;
};

template <typename D>
struct WINRT_EBO impl_IConnectionProfile3
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::Connectivity::AttributedNetworkUsage>> GetAttributedNetworkUsageAsync(const Windows::Foundation::DateTime & startTime, const Windows::Foundation::DateTime & endTime, const Windows::Networking::Connectivity::NetworkUsageStates & states) const;
};

template <typename D>
struct WINRT_EBO impl_IConnectionProfileFilter
{
    void IsConnected(bool value) const;
    bool IsConnected() const;
    void IsWwanConnectionProfile(bool value) const;
    bool IsWwanConnectionProfile() const;
    void IsWlanConnectionProfile(bool value) const;
    bool IsWlanConnectionProfile() const;
    void NetworkCostType(Windows::Networking::Connectivity::NetworkCostType value) const;
    Windows::Networking::Connectivity::NetworkCostType NetworkCostType() const;
    void ServiceProviderGuid(const optional<GUID> & value) const;
    Windows::Foundation::IReference<GUID> ServiceProviderGuid() const;
};

template <typename D>
struct WINRT_EBO impl_IConnectionProfileFilter2
{
    void IsRoaming(const optional<bool> & value) const;
    Windows::Foundation::IReference<bool> IsRoaming() const;
    void IsOverDataLimit(const optional<bool> & value) const;
    Windows::Foundation::IReference<bool> IsOverDataLimit() const;
    void IsBackgroundDataUsageRestricted(const optional<bool> & value) const;
    Windows::Foundation::IReference<bool> IsBackgroundDataUsageRestricted() const;
    Windows::Storage::Streams::IBuffer RawData() const;
};

template <typename D>
struct WINRT_EBO impl_IConnectionSession
{
    Windows::Networking::Connectivity::ConnectionProfile ConnectionProfile() const;
};

template <typename D>
struct WINRT_EBO impl_IConnectivityInterval
{
    Windows::Foundation::DateTime StartTime() const;
    Windows::Foundation::TimeSpan ConnectionDuration() const;
};

template <typename D>
struct WINRT_EBO impl_IConnectivityManagerStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::Connectivity::ConnectionSession> AcquireConnectionAsync(const Windows::Networking::Connectivity::CellularApnContext & cellularApnContext) const;
    void AddHttpRoutePolicy(const Windows::Networking::Connectivity::RoutePolicy & routePolicy) const;
    void RemoveHttpRoutePolicy(const Windows::Networking::Connectivity::RoutePolicy & routePolicy) const;
};

template <typename D>
struct WINRT_EBO impl_IDataPlanStatus
{
    Windows::Networking::Connectivity::DataPlanUsage DataPlanUsage() const;
    Windows::Foundation::IReference<uint32_t> DataLimitInMegabytes() const;
    Windows::Foundation::IReference<uint64_t> InboundBitsPerSecond() const;
    Windows::Foundation::IReference<uint64_t> OutboundBitsPerSecond() const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> NextBillingCycle() const;
    Windows::Foundation::IReference<uint32_t> MaxTransferSizeInMegabytes() const;
};

template <typename D>
struct WINRT_EBO impl_IDataPlanUsage
{
    uint32_t MegabytesUsed() const;
    Windows::Foundation::DateTime LastSyncTime() const;
};

template <typename D>
struct WINRT_EBO impl_IDataUsage
{
    [[deprecated("IDataUsage may be altered or unavailable for releases after Windows 8.1. Instead, use INetworkUsage.")]] uint64_t BytesSent() const;
    [[deprecated("IDataUsage may be altered or unavailable for releases after Windows 8.1. Instead, use INetworkUsage.")]] uint64_t BytesReceived() const;
};

template <typename D>
struct WINRT_EBO impl_IIPInformation
{
    Windows::Networking::Connectivity::NetworkAdapter NetworkAdapter() const;
    Windows::Foundation::IReference<uint8_t> PrefixLength() const;
};

template <typename D>
struct WINRT_EBO impl_ILanIdentifier
{
    Windows::Networking::Connectivity::LanIdentifierData InfrastructureId() const;
    Windows::Networking::Connectivity::LanIdentifierData PortId() const;
    GUID NetworkAdapterId() const;
};

template <typename D>
struct WINRT_EBO impl_ILanIdentifierData
{
    uint32_t Type() const;
    Windows::Foundation::Collections::IVectorView<uint8_t> Value() const;
};

template <typename D>
struct WINRT_EBO impl_INetworkAdapter
{
    uint64_t OutboundMaxBitsPerSecond() const;
    uint64_t InboundMaxBitsPerSecond() const;
    uint32_t IanaInterfaceType() const;
    Windows::Networking::Connectivity::NetworkItem NetworkItem() const;
    GUID NetworkAdapterId() const;
    Windows::Foundation::IAsyncOperation<Windows::Networking::Connectivity::ConnectionProfile> GetConnectedProfileAsync() const;
};

template <typename D>
struct WINRT_EBO impl_INetworkInformationStatics
{
    Windows::Foundation::Collections::IVectorView<Windows::Networking::Connectivity::ConnectionProfile> GetConnectionProfiles() const;
    Windows::Networking::Connectivity::ConnectionProfile GetInternetConnectionProfile() const;
    Windows::Foundation::Collections::IVectorView<Windows::Networking::Connectivity::LanIdentifier> GetLanIdentifiers() const;
    Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName> GetHostNames() const;
    Windows::Foundation::IAsyncOperation<Windows::Networking::Connectivity::ProxyConfiguration> GetProxyConfigurationAsync(const Windows::Foundation::Uri & uri) const;
    Windows::Foundation::Collections::IVectorView<Windows::Networking::EndpointPair> GetSortedEndpointPairs(iterable<Windows::Networking::EndpointPair> destinationList, Windows::Networking::HostNameSortOptions sortOptions) const;
    event_token NetworkStatusChanged(const Windows::Networking::Connectivity::NetworkStatusChangedEventHandler & networkStatusHandler) const;
    using NetworkStatusChanged_revoker = event_revoker<INetworkInformationStatics>;
    NetworkStatusChanged_revoker NetworkStatusChanged(auto_revoke_t, const Windows::Networking::Connectivity::NetworkStatusChangedEventHandler & networkStatusHandler) const;
    void NetworkStatusChanged(event_token eventCookie) const;
};

template <typename D>
struct WINRT_EBO impl_INetworkInformationStatics2
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::Connectivity::ConnectionProfile>> FindConnectionProfilesAsync(const Windows::Networking::Connectivity::ConnectionProfileFilter & pProfileFilter) const;
};

template <typename D>
struct WINRT_EBO impl_INetworkItem
{
    GUID NetworkId() const;
    Windows::Networking::Connectivity::NetworkTypes GetNetworkTypes() const;
};

template <typename D>
struct WINRT_EBO impl_INetworkSecuritySettings
{
    Windows::Networking::Connectivity::NetworkAuthenticationType NetworkAuthenticationType() const;
    Windows::Networking::Connectivity::NetworkEncryptionType NetworkEncryptionType() const;
};

template <typename D>
struct WINRT_EBO impl_INetworkStateChangeEventDetails
{
    bool HasNewInternetConnectionProfile() const;
    bool HasNewConnectionCost() const;
    bool HasNewNetworkConnectivityLevel() const;
    bool HasNewDomainConnectivityLevel() const;
    bool HasNewHostNameList() const;
    bool HasNewWwanRegistrationState() const;
};

template <typename D>
struct WINRT_EBO impl_INetworkStateChangeEventDetails2
{
    bool HasNewTetheringOperationalState() const;
    bool HasNewTetheringClientCount() const;
};

template <typename D>
struct WINRT_EBO impl_INetworkUsage
{
    uint64_t BytesSent() const;
    uint64_t BytesReceived() const;
    Windows::Foundation::TimeSpan ConnectionDuration() const;
};

template <typename D>
struct WINRT_EBO impl_IProxyConfiguration
{
    Windows::Foundation::Collections::IVectorView<Windows::Foundation::Uri> ProxyUris() const;
    bool CanConnectDirectly() const;
};

template <typename D>
struct WINRT_EBO impl_IRoutePolicy
{
    Windows::Networking::Connectivity::ConnectionProfile ConnectionProfile() const;
    Windows::Networking::HostName HostName() const;
    Windows::Networking::DomainNameType HostNameType() const;
};

template <typename D>
struct WINRT_EBO impl_IRoutePolicyFactory
{
    Windows::Networking::Connectivity::RoutePolicy CreateRoutePolicy(const Windows::Networking::Connectivity::ConnectionProfile & connectionProfile, const Windows::Networking::HostName & hostName, Windows::Networking::DomainNameType type) const;
};

template <typename D>
struct WINRT_EBO impl_IWlanConnectionProfileDetails
{
    hstring GetConnectedSsid() const;
};

template <typename D>
struct WINRT_EBO impl_IWwanConnectionProfileDetails
{
    hstring HomeProviderId() const;
    hstring AccessPointName() const;
    Windows::Networking::Connectivity::WwanNetworkRegistrationState GetNetworkRegistrationState() const;
    Windows::Networking::Connectivity::WwanDataClass GetCurrentDataClass() const;
};

}

namespace impl {

template <> struct traits<Windows::Networking::Connectivity::IAttributedNetworkUsage>
{
    using abi = ABI::Windows::Networking::Connectivity::IAttributedNetworkUsage;
    template <typename D> using consume = Windows::Networking::Connectivity::impl_IAttributedNetworkUsage<D>;
};

template <> struct traits<Windows::Networking::Connectivity::ICellularApnContext>
{
    using abi = ABI::Windows::Networking::Connectivity::ICellularApnContext;
    template <typename D> using consume = Windows::Networking::Connectivity::impl_ICellularApnContext<D>;
};

template <> struct traits<Windows::Networking::Connectivity::IConnectionCost>
{
    using abi = ABI::Windows::Networking::Connectivity::IConnectionCost;
    template <typename D> using consume = Windows::Networking::Connectivity::impl_IConnectionCost<D>;
};

template <> struct traits<Windows::Networking::Connectivity::IConnectionCost2>
{
    using abi = ABI::Windows::Networking::Connectivity::IConnectionCost2;
    template <typename D> using consume = Windows::Networking::Connectivity::impl_IConnectionCost2<D>;
};

template <> struct traits<Windows::Networking::Connectivity::IConnectionProfile>
{
    using abi = ABI::Windows::Networking::Connectivity::IConnectionProfile;
    template <typename D> using consume = Windows::Networking::Connectivity::impl_IConnectionProfile<D>;
};

template <> struct traits<Windows::Networking::Connectivity::IConnectionProfile2>
{
    using abi = ABI::Windows::Networking::Connectivity::IConnectionProfile2;
    template <typename D> using consume = Windows::Networking::Connectivity::impl_IConnectionProfile2<D>;
};

template <> struct traits<Windows::Networking::Connectivity::IConnectionProfile3>
{
    using abi = ABI::Windows::Networking::Connectivity::IConnectionProfile3;
    template <typename D> using consume = Windows::Networking::Connectivity::impl_IConnectionProfile3<D>;
};

template <> struct traits<Windows::Networking::Connectivity::IConnectionProfileFilter>
{
    using abi = ABI::Windows::Networking::Connectivity::IConnectionProfileFilter;
    template <typename D> using consume = Windows::Networking::Connectivity::impl_IConnectionProfileFilter<D>;
};

template <> struct traits<Windows::Networking::Connectivity::IConnectionProfileFilter2>
{
    using abi = ABI::Windows::Networking::Connectivity::IConnectionProfileFilter2;
    template <typename D> using consume = Windows::Networking::Connectivity::impl_IConnectionProfileFilter2<D>;
};

template <> struct traits<Windows::Networking::Connectivity::IConnectionSession>
{
    using abi = ABI::Windows::Networking::Connectivity::IConnectionSession;
    template <typename D> using consume = Windows::Networking::Connectivity::impl_IConnectionSession<D>;
};

template <> struct traits<Windows::Networking::Connectivity::IConnectivityInterval>
{
    using abi = ABI::Windows::Networking::Connectivity::IConnectivityInterval;
    template <typename D> using consume = Windows::Networking::Connectivity::impl_IConnectivityInterval<D>;
};

template <> struct traits<Windows::Networking::Connectivity::IConnectivityManagerStatics>
{
    using abi = ABI::Windows::Networking::Connectivity::IConnectivityManagerStatics;
    template <typename D> using consume = Windows::Networking::Connectivity::impl_IConnectivityManagerStatics<D>;
};

template <> struct traits<Windows::Networking::Connectivity::IDataPlanStatus>
{
    using abi = ABI::Windows::Networking::Connectivity::IDataPlanStatus;
    template <typename D> using consume = Windows::Networking::Connectivity::impl_IDataPlanStatus<D>;
};

template <> struct traits<Windows::Networking::Connectivity::IDataPlanUsage>
{
    using abi = ABI::Windows::Networking::Connectivity::IDataPlanUsage;
    template <typename D> using consume = Windows::Networking::Connectivity::impl_IDataPlanUsage<D>;
};

template <> struct traits<Windows::Networking::Connectivity::IDataUsage>
{
    using abi = ABI::Windows::Networking::Connectivity::IDataUsage;
    template <typename D> using consume = Windows::Networking::Connectivity::impl_IDataUsage<D>;
};

template <> struct traits<Windows::Networking::Connectivity::IIPInformation>
{
    using abi = ABI::Windows::Networking::Connectivity::IIPInformation;
    template <typename D> using consume = Windows::Networking::Connectivity::impl_IIPInformation<D>;
};

template <> struct traits<Windows::Networking::Connectivity::ILanIdentifier>
{
    using abi = ABI::Windows::Networking::Connectivity::ILanIdentifier;
    template <typename D> using consume = Windows::Networking::Connectivity::impl_ILanIdentifier<D>;
};

template <> struct traits<Windows::Networking::Connectivity::ILanIdentifierData>
{
    using abi = ABI::Windows::Networking::Connectivity::ILanIdentifierData;
    template <typename D> using consume = Windows::Networking::Connectivity::impl_ILanIdentifierData<D>;
};

template <> struct traits<Windows::Networking::Connectivity::INetworkAdapter>
{
    using abi = ABI::Windows::Networking::Connectivity::INetworkAdapter;
    template <typename D> using consume = Windows::Networking::Connectivity::impl_INetworkAdapter<D>;
};

template <> struct traits<Windows::Networking::Connectivity::INetworkInformationStatics>
{
    using abi = ABI::Windows::Networking::Connectivity::INetworkInformationStatics;
    template <typename D> using consume = Windows::Networking::Connectivity::impl_INetworkInformationStatics<D>;
};

template <> struct traits<Windows::Networking::Connectivity::INetworkInformationStatics2>
{
    using abi = ABI::Windows::Networking::Connectivity::INetworkInformationStatics2;
    template <typename D> using consume = Windows::Networking::Connectivity::impl_INetworkInformationStatics2<D>;
};

template <> struct traits<Windows::Networking::Connectivity::INetworkItem>
{
    using abi = ABI::Windows::Networking::Connectivity::INetworkItem;
    template <typename D> using consume = Windows::Networking::Connectivity::impl_INetworkItem<D>;
};

template <> struct traits<Windows::Networking::Connectivity::INetworkSecuritySettings>
{
    using abi = ABI::Windows::Networking::Connectivity::INetworkSecuritySettings;
    template <typename D> using consume = Windows::Networking::Connectivity::impl_INetworkSecuritySettings<D>;
};

template <> struct traits<Windows::Networking::Connectivity::INetworkStateChangeEventDetails>
{
    using abi = ABI::Windows::Networking::Connectivity::INetworkStateChangeEventDetails;
    template <typename D> using consume = Windows::Networking::Connectivity::impl_INetworkStateChangeEventDetails<D>;
};

template <> struct traits<Windows::Networking::Connectivity::INetworkStateChangeEventDetails2>
{
    using abi = ABI::Windows::Networking::Connectivity::INetworkStateChangeEventDetails2;
    template <typename D> using consume = Windows::Networking::Connectivity::impl_INetworkStateChangeEventDetails2<D>;
};

template <> struct traits<Windows::Networking::Connectivity::INetworkUsage>
{
    using abi = ABI::Windows::Networking::Connectivity::INetworkUsage;
    template <typename D> using consume = Windows::Networking::Connectivity::impl_INetworkUsage<D>;
};

template <> struct traits<Windows::Networking::Connectivity::IProxyConfiguration>
{
    using abi = ABI::Windows::Networking::Connectivity::IProxyConfiguration;
    template <typename D> using consume = Windows::Networking::Connectivity::impl_IProxyConfiguration<D>;
};

template <> struct traits<Windows::Networking::Connectivity::IRoutePolicy>
{
    using abi = ABI::Windows::Networking::Connectivity::IRoutePolicy;
    template <typename D> using consume = Windows::Networking::Connectivity::impl_IRoutePolicy<D>;
};

template <> struct traits<Windows::Networking::Connectivity::IRoutePolicyFactory>
{
    using abi = ABI::Windows::Networking::Connectivity::IRoutePolicyFactory;
    template <typename D> using consume = Windows::Networking::Connectivity::impl_IRoutePolicyFactory<D>;
};

template <> struct traits<Windows::Networking::Connectivity::IWlanConnectionProfileDetails>
{
    using abi = ABI::Windows::Networking::Connectivity::IWlanConnectionProfileDetails;
    template <typename D> using consume = Windows::Networking::Connectivity::impl_IWlanConnectionProfileDetails<D>;
};

template <> struct traits<Windows::Networking::Connectivity::IWwanConnectionProfileDetails>
{
    using abi = ABI::Windows::Networking::Connectivity::IWwanConnectionProfileDetails;
    template <typename D> using consume = Windows::Networking::Connectivity::impl_IWwanConnectionProfileDetails<D>;
};

template <> struct traits<Windows::Networking::Connectivity::NetworkStatusChangedEventHandler>
{
    using abi = ABI::Windows::Networking::Connectivity::NetworkStatusChangedEventHandler;
};

template <> struct traits<Windows::Networking::Connectivity::AttributedNetworkUsage>
{
    using abi = ABI::Windows::Networking::Connectivity::AttributedNetworkUsage;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Connectivity.AttributedNetworkUsage"; }
};

template <> struct traits<Windows::Networking::Connectivity::CellularApnContext>
{
    using abi = ABI::Windows::Networking::Connectivity::CellularApnContext;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Connectivity.CellularApnContext"; }
};

template <> struct traits<Windows::Networking::Connectivity::ConnectionCost>
{
    using abi = ABI::Windows::Networking::Connectivity::ConnectionCost;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Connectivity.ConnectionCost"; }
};

template <> struct traits<Windows::Networking::Connectivity::ConnectionProfile>
{
    using abi = ABI::Windows::Networking::Connectivity::ConnectionProfile;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Connectivity.ConnectionProfile"; }
};

template <> struct traits<Windows::Networking::Connectivity::ConnectionProfileFilter>
{
    using abi = ABI::Windows::Networking::Connectivity::ConnectionProfileFilter;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Connectivity.ConnectionProfileFilter"; }
};

template <> struct traits<Windows::Networking::Connectivity::ConnectionSession>
{
    using abi = ABI::Windows::Networking::Connectivity::ConnectionSession;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Connectivity.ConnectionSession"; }
};

template <> struct traits<Windows::Networking::Connectivity::ConnectivityInterval>
{
    using abi = ABI::Windows::Networking::Connectivity::ConnectivityInterval;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Connectivity.ConnectivityInterval"; }
};

template <> struct traits<Windows::Networking::Connectivity::ConnectivityManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Connectivity.ConnectivityManager"; }
};

template <> struct traits<Windows::Networking::Connectivity::DataPlanStatus>
{
    using abi = ABI::Windows::Networking::Connectivity::DataPlanStatus;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Connectivity.DataPlanStatus"; }
};

template <> struct traits<Windows::Networking::Connectivity::DataPlanUsage>
{
    using abi = ABI::Windows::Networking::Connectivity::DataPlanUsage;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Connectivity.DataPlanUsage"; }
};

template <> struct traits<Windows::Networking::Connectivity::DataUsage>
{
    using abi = ABI::Windows::Networking::Connectivity::DataUsage;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Connectivity.DataUsage"; }
};

template <> struct traits<Windows::Networking::Connectivity::IPInformation>
{
    using abi = ABI::Windows::Networking::Connectivity::IPInformation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Connectivity.IPInformation"; }
};

template <> struct traits<Windows::Networking::Connectivity::LanIdentifier>
{
    using abi = ABI::Windows::Networking::Connectivity::LanIdentifier;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Connectivity.LanIdentifier"; }
};

template <> struct traits<Windows::Networking::Connectivity::LanIdentifierData>
{
    using abi = ABI::Windows::Networking::Connectivity::LanIdentifierData;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Connectivity.LanIdentifierData"; }
};

template <> struct traits<Windows::Networking::Connectivity::NetworkAdapter>
{
    using abi = ABI::Windows::Networking::Connectivity::NetworkAdapter;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Connectivity.NetworkAdapter"; }
};

template <> struct traits<Windows::Networking::Connectivity::NetworkInformation>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Connectivity.NetworkInformation"; }
};

template <> struct traits<Windows::Networking::Connectivity::NetworkItem>
{
    using abi = ABI::Windows::Networking::Connectivity::NetworkItem;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Connectivity.NetworkItem"; }
};

template <> struct traits<Windows::Networking::Connectivity::NetworkSecuritySettings>
{
    using abi = ABI::Windows::Networking::Connectivity::NetworkSecuritySettings;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Connectivity.NetworkSecuritySettings"; }
};

template <> struct traits<Windows::Networking::Connectivity::NetworkStateChangeEventDetails>
{
    using abi = ABI::Windows::Networking::Connectivity::NetworkStateChangeEventDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Connectivity.NetworkStateChangeEventDetails"; }
};

template <> struct traits<Windows::Networking::Connectivity::NetworkUsage>
{
    using abi = ABI::Windows::Networking::Connectivity::NetworkUsage;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Connectivity.NetworkUsage"; }
};

template <> struct traits<Windows::Networking::Connectivity::ProxyConfiguration>
{
    using abi = ABI::Windows::Networking::Connectivity::ProxyConfiguration;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Connectivity.ProxyConfiguration"; }
};

template <> struct traits<Windows::Networking::Connectivity::RoutePolicy>
{
    using abi = ABI::Windows::Networking::Connectivity::RoutePolicy;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Connectivity.RoutePolicy"; }
};

template <> struct traits<Windows::Networking::Connectivity::WlanConnectionProfileDetails>
{
    using abi = ABI::Windows::Networking::Connectivity::WlanConnectionProfileDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Connectivity.WlanConnectionProfileDetails"; }
};

template <> struct traits<Windows::Networking::Connectivity::WwanConnectionProfileDetails>
{
    using abi = ABI::Windows::Networking::Connectivity::WwanConnectionProfileDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Connectivity.WwanConnectionProfileDetails"; }
};

}

}
