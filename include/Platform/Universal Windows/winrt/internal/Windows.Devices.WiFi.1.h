// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Devices.WiFi.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Networking.Connectivity.0.h"
#include "Windows.Security.Credentials.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::WiFi {

struct __declspec(uuid("a6c4e423-3d75-43a4-b9de-11e26b72d9b0")) __declspec(novtable) IWiFiAdapter : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_NetworkAdapter(Windows::Networking::Connectivity::INetworkAdapter ** value) = 0;
    virtual HRESULT __stdcall abi_ScanAsync(Windows::Foundation::IAsyncAction ** value) = 0;
    virtual HRESULT __stdcall get_NetworkReport(Windows::Devices::WiFi::IWiFiNetworkReport ** value) = 0;
    virtual HRESULT __stdcall add_AvailableNetworksChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::WiFi::WiFiAdapter, Windows::Foundation::IInspectable> * args, event_token * eventCookie) = 0;
    virtual HRESULT __stdcall remove_AvailableNetworksChanged(event_token eventCookie) = 0;
    virtual HRESULT __stdcall abi_ConnectAsync(Windows::Devices::WiFi::IWiFiAvailableNetwork * availableNetwork, winrt::Windows::Devices::WiFi::WiFiReconnectionKind reconnectionKind, Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiConnectionResult> ** value) = 0;
    virtual HRESULT __stdcall abi_ConnectWithPasswordCredentialAsync(Windows::Devices::WiFi::IWiFiAvailableNetwork * availableNetwork, winrt::Windows::Devices::WiFi::WiFiReconnectionKind reconnectionKind, Windows::Security::Credentials::IPasswordCredential * passwordCredential, Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiConnectionResult> ** value) = 0;
    virtual HRESULT __stdcall abi_ConnectWithPasswordCredentialAndSsidAsync(Windows::Devices::WiFi::IWiFiAvailableNetwork * availableNetwork, winrt::Windows::Devices::WiFi::WiFiReconnectionKind reconnectionKind, Windows::Security::Credentials::IPasswordCredential * passwordCredential, hstring ssid, Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiConnectionResult> ** value) = 0;
    virtual HRESULT __stdcall abi_Disconnect() = 0;
};

struct __declspec(uuid("da25fddd-d24c-43e3-aabd-c4659f730f99")) __declspec(novtable) IWiFiAdapterStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FindAllAdaptersAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::WiFi::WiFiAdapter>> ** value) = 0;
    virtual HRESULT __stdcall abi_GetDeviceSelector(hstring * deviceSelector) = 0;
    virtual HRESULT __stdcall abi_FromIdAsync(hstring deviceId, Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiAdapter> ** asyncOp) = 0;
    virtual HRESULT __stdcall abi_RequestAccessAsync(Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::WiFi::WiFiAccessStatus> ** value) = 0;
};

struct __declspec(uuid("26e96246-183e-4704-9826-71b4a2f0f668")) __declspec(novtable) IWiFiAvailableNetwork : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Uptime(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_Ssid(hstring * value) = 0;
    virtual HRESULT __stdcall get_Bssid(hstring * value) = 0;
    virtual HRESULT __stdcall get_ChannelCenterFrequencyInKilohertz(int32_t * value) = 0;
    virtual HRESULT __stdcall get_NetworkRssiInDecibelMilliwatts(double * value) = 0;
    virtual HRESULT __stdcall get_SignalBars(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_NetworkKind(winrt::Windows::Devices::WiFi::WiFiNetworkKind * value) = 0;
    virtual HRESULT __stdcall get_PhyKind(winrt::Windows::Devices::WiFi::WiFiPhyKind * value) = 0;
    virtual HRESULT __stdcall get_SecuritySettings(Windows::Networking::Connectivity::INetworkSecuritySettings ** value) = 0;
    virtual HRESULT __stdcall get_BeaconInterval(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_IsWiFiDirect(bool * value) = 0;
};

struct __declspec(uuid("143bdfd9-c37d-40be-a5c8-857bce85a931")) __declspec(novtable) IWiFiConnectionResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ConnectionStatus(winrt::Windows::Devices::WiFi::WiFiConnectionStatus * value) = 0;
};

struct __declspec(uuid("9524ded2-5911-445e-8194-be4f1a704895")) __declspec(novtable) IWiFiNetworkReport : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Timestamp(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_AvailableNetworks(Windows::Foundation::Collections::IVectorView<Windows::Devices::WiFi::WiFiAvailableNetwork> ** value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Devices::WiFi::WiFiAdapter> { using default_interface = Windows::Devices::WiFi::IWiFiAdapter; };
template <> struct traits<Windows::Devices::WiFi::WiFiAvailableNetwork> { using default_interface = Windows::Devices::WiFi::IWiFiAvailableNetwork; };
template <> struct traits<Windows::Devices::WiFi::WiFiConnectionResult> { using default_interface = Windows::Devices::WiFi::IWiFiConnectionResult; };
template <> struct traits<Windows::Devices::WiFi::WiFiNetworkReport> { using default_interface = Windows::Devices::WiFi::IWiFiNetworkReport; };

}

namespace Windows::Devices::WiFi {

template <typename D>
struct WINRT_EBO impl_IWiFiAdapter
{
    Windows::Networking::Connectivity::NetworkAdapter NetworkAdapter() const;
    Windows::Foundation::IAsyncAction ScanAsync() const;
    Windows::Devices::WiFi::WiFiNetworkReport NetworkReport() const;
    event_token AvailableNetworksChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFi::WiFiAdapter, Windows::Foundation::IInspectable> & args) const;
    using AvailableNetworksChanged_revoker = event_revoker<IWiFiAdapter>;
    AvailableNetworksChanged_revoker AvailableNetworksChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFi::WiFiAdapter, Windows::Foundation::IInspectable> & args) const;
    void AvailableNetworksChanged(event_token eventCookie) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiConnectionResult> ConnectAsync(const Windows::Devices::WiFi::WiFiAvailableNetwork & availableNetwork, Windows::Devices::WiFi::WiFiReconnectionKind reconnectionKind) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiConnectionResult> ConnectAsync(const Windows::Devices::WiFi::WiFiAvailableNetwork & availableNetwork, Windows::Devices::WiFi::WiFiReconnectionKind reconnectionKind, const Windows::Security::Credentials::PasswordCredential & passwordCredential) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiConnectionResult> ConnectAsync(const Windows::Devices::WiFi::WiFiAvailableNetwork & availableNetwork, Windows::Devices::WiFi::WiFiReconnectionKind reconnectionKind, const Windows::Security::Credentials::PasswordCredential & passwordCredential, hstring_view ssid) const;
    void Disconnect() const;
};

template <typename D>
struct WINRT_EBO impl_IWiFiAdapterStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::WiFi::WiFiAdapter>> FindAllAdaptersAsync() const;
    hstring GetDeviceSelector() const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiAdapter> FromIdAsync(hstring_view deviceId) const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::WiFi::WiFiAccessStatus> RequestAccessAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IWiFiAvailableNetwork
{
    Windows::Foundation::TimeSpan Uptime() const;
    hstring Ssid() const;
    hstring Bssid() const;
    int32_t ChannelCenterFrequencyInKilohertz() const;
    double NetworkRssiInDecibelMilliwatts() const;
    uint8_t SignalBars() const;
    Windows::Devices::WiFi::WiFiNetworkKind NetworkKind() const;
    Windows::Devices::WiFi::WiFiPhyKind PhyKind() const;
    Windows::Networking::Connectivity::NetworkSecuritySettings SecuritySettings() const;
    Windows::Foundation::TimeSpan BeaconInterval() const;
    bool IsWiFiDirect() const;
};

template <typename D>
struct WINRT_EBO impl_IWiFiConnectionResult
{
    Windows::Devices::WiFi::WiFiConnectionStatus ConnectionStatus() const;
};

template <typename D>
struct WINRT_EBO impl_IWiFiNetworkReport
{
    Windows::Foundation::DateTime Timestamp() const;
    Windows::Foundation::Collections::IVectorView<Windows::Devices::WiFi::WiFiAvailableNetwork> AvailableNetworks() const;
};

}

namespace impl {

template <> struct traits<Windows::Devices::WiFi::IWiFiAdapter>
{
    using abi = ABI::Windows::Devices::WiFi::IWiFiAdapter;
    template <typename D> using consume = Windows::Devices::WiFi::impl_IWiFiAdapter<D>;
};

template <> struct traits<Windows::Devices::WiFi::IWiFiAdapterStatics>
{
    using abi = ABI::Windows::Devices::WiFi::IWiFiAdapterStatics;
    template <typename D> using consume = Windows::Devices::WiFi::impl_IWiFiAdapterStatics<D>;
};

template <> struct traits<Windows::Devices::WiFi::IWiFiAvailableNetwork>
{
    using abi = ABI::Windows::Devices::WiFi::IWiFiAvailableNetwork;
    template <typename D> using consume = Windows::Devices::WiFi::impl_IWiFiAvailableNetwork<D>;
};

template <> struct traits<Windows::Devices::WiFi::IWiFiConnectionResult>
{
    using abi = ABI::Windows::Devices::WiFi::IWiFiConnectionResult;
    template <typename D> using consume = Windows::Devices::WiFi::impl_IWiFiConnectionResult<D>;
};

template <> struct traits<Windows::Devices::WiFi::IWiFiNetworkReport>
{
    using abi = ABI::Windows::Devices::WiFi::IWiFiNetworkReport;
    template <typename D> using consume = Windows::Devices::WiFi::impl_IWiFiNetworkReport<D>;
};

template <> struct traits<Windows::Devices::WiFi::WiFiAdapter>
{
    using abi = ABI::Windows::Devices::WiFi::WiFiAdapter;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.WiFi.WiFiAdapter"; }
};

template <> struct traits<Windows::Devices::WiFi::WiFiAvailableNetwork>
{
    using abi = ABI::Windows::Devices::WiFi::WiFiAvailableNetwork;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.WiFi.WiFiAvailableNetwork"; }
};

template <> struct traits<Windows::Devices::WiFi::WiFiConnectionResult>
{
    using abi = ABI::Windows::Devices::WiFi::WiFiConnectionResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.WiFi.WiFiConnectionResult"; }
};

template <> struct traits<Windows::Devices::WiFi::WiFiNetworkReport>
{
    using abi = ABI::Windows::Devices::WiFi::WiFiNetworkReport;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.WiFi.WiFiNetworkReport"; }
};

}

}
