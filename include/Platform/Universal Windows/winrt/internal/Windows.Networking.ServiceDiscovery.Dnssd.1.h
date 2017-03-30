// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Networking.ServiceDiscovery.Dnssd.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Networking.0.h"
#include "Windows.Networking.Connectivity.0.h"
#include "Windows.Networking.Sockets.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Networking::ServiceDiscovery::Dnssd {

struct __declspec(uuid("3d786ad2-e606-5350-73ea-7e97f066162f")) __declspec(novtable) IDnssdRegistrationResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Status(winrt::Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationStatus * value) = 0;
    virtual HRESULT __stdcall get_IPAddress(Windows::Networking::IHostName ** value) = 0;
    virtual HRESULT __stdcall get_HasInstanceNameChanged(bool * value) = 0;
};

struct __declspec(uuid("e246db7e-98a5-4ca1-b9e4-c253d33c35ff")) __declspec(novtable) IDnssdServiceInstance : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DnssdServiceInstanceName(hstring * value) = 0;
    virtual HRESULT __stdcall put_DnssdServiceInstanceName(hstring value) = 0;
    virtual HRESULT __stdcall get_HostName(Windows::Networking::IHostName ** value) = 0;
    virtual HRESULT __stdcall put_HostName(Windows::Networking::IHostName * value) = 0;
    virtual HRESULT __stdcall get_Port(uint16_t * value) = 0;
    virtual HRESULT __stdcall put_Port(uint16_t value) = 0;
    virtual HRESULT __stdcall get_Priority(uint16_t * value) = 0;
    virtual HRESULT __stdcall put_Priority(uint16_t value) = 0;
    virtual HRESULT __stdcall get_Weight(uint16_t * value) = 0;
    virtual HRESULT __stdcall put_Weight(uint16_t value) = 0;
    virtual HRESULT __stdcall get_TextAttributes(Windows::Foundation::Collections::IMap<hstring, hstring> ** value) = 0;
    virtual HRESULT __stdcall abi_RegisterStreamSocketListenerAsync1(Windows::Networking::Sockets::IStreamSocketListener * socket, Windows::Foundation::IAsyncOperation<Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult> ** result) = 0;
    virtual HRESULT __stdcall abi_RegisterStreamSocketListenerAsync2(Windows::Networking::Sockets::IStreamSocketListener * socket, Windows::Networking::Connectivity::INetworkAdapter * adapter, Windows::Foundation::IAsyncOperation<Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult> ** result) = 0;
    virtual HRESULT __stdcall abi_RegisterDatagramSocketAsync1(Windows::Networking::Sockets::IDatagramSocket * socket, Windows::Foundation::IAsyncOperation<Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult> ** result) = 0;
    virtual HRESULT __stdcall abi_RegisterDatagramSocketAsync2(Windows::Networking::Sockets::IDatagramSocket * socket, Windows::Networking::Connectivity::INetworkAdapter * adapter, Windows::Foundation::IAsyncOperation<Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult> ** result) = 0;
};

struct __declspec(uuid("6cb061a1-c478-4331-9684-4af2186c0a2b")) __declspec(novtable) IDnssdServiceInstanceFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(hstring dnssdServiceInstanceName, Windows::Networking::IHostName * hostName, uint16_t port, Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstance ** result) = 0;
};

struct __declspec(uuid("cc34d9c1-db7d-4b69-983d-c6f83f205682")) __declspec(novtable) IDnssdServiceWatcher : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_Added(Windows::Foundation::TypedEventHandler<Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcher, Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceInstance> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Added(event_token token) = 0;
    virtual HRESULT __stdcall add_EnumerationCompleted(Windows::Foundation::TypedEventHandler<Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcher, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_EnumerationCompleted(event_token token) = 0;
    virtual HRESULT __stdcall add_Stopped(Windows::Foundation::TypedEventHandler<Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcher, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Stopped(event_token token) = 0;
    virtual HRESULT __stdcall get_Status(winrt::Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcherStatus * status) = 0;
    virtual HRESULT __stdcall abi_Start() = 0;
    virtual HRESULT __stdcall abi_Stop() = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult> { using default_interface = Windows::Networking::ServiceDiscovery::Dnssd::IDnssdRegistrationResult; };
template <> struct traits<Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceInstance> { using default_interface = Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstance; };
template <> struct traits<Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceInstanceCollection> { using default_interface = Windows::Foundation::Collections::IVectorView<Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceInstance>; };
template <> struct traits<Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcher> { using default_interface = Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceWatcher; };

}

namespace Windows::Networking::ServiceDiscovery::Dnssd {

template <typename D>
struct WINRT_EBO impl_IDnssdRegistrationResult
{
    Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationStatus Status() const;
    Windows::Networking::HostName IPAddress() const;
    bool HasInstanceNameChanged() const;
};

template <typename D>
struct WINRT_EBO impl_IDnssdServiceInstance
{
    hstring DnssdServiceInstanceName() const;
    void DnssdServiceInstanceName(hstring_view value) const;
    Windows::Networking::HostName HostName() const;
    void HostName(const Windows::Networking::HostName & value) const;
    uint16_t Port() const;
    void Port(uint16_t value) const;
    uint16_t Priority() const;
    void Priority(uint16_t value) const;
    uint16_t Weight() const;
    void Weight(uint16_t value) const;
    Windows::Foundation::Collections::IMap<hstring, hstring> TextAttributes() const;
    Windows::Foundation::IAsyncOperation<Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult> RegisterStreamSocketListenerAsync(const Windows::Networking::Sockets::StreamSocketListener & socket) const;
    Windows::Foundation::IAsyncOperation<Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult> RegisterStreamSocketListenerAsync(const Windows::Networking::Sockets::StreamSocketListener & socket, const Windows::Networking::Connectivity::NetworkAdapter & adapter) const;
    Windows::Foundation::IAsyncOperation<Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult> RegisterDatagramSocketAsync(const Windows::Networking::Sockets::DatagramSocket & socket) const;
    Windows::Foundation::IAsyncOperation<Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult> RegisterDatagramSocketAsync(const Windows::Networking::Sockets::DatagramSocket & socket, const Windows::Networking::Connectivity::NetworkAdapter & adapter) const;
};

template <typename D>
struct WINRT_EBO impl_IDnssdServiceInstanceFactory
{
    Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceInstance Create(hstring_view dnssdServiceInstanceName, const Windows::Networking::HostName & hostName, uint16_t port) const;
};

template <typename D>
struct WINRT_EBO impl_IDnssdServiceWatcher
{
    event_token Added(const Windows::Foundation::TypedEventHandler<Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcher, Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceInstance> & handler) const;
    using Added_revoker = event_revoker<IDnssdServiceWatcher>;
    Added_revoker Added(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcher, Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceInstance> & handler) const;
    void Added(event_token token) const;
    event_token EnumerationCompleted(const Windows::Foundation::TypedEventHandler<Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcher, Windows::Foundation::IInspectable> & handler) const;
    using EnumerationCompleted_revoker = event_revoker<IDnssdServiceWatcher>;
    EnumerationCompleted_revoker EnumerationCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcher, Windows::Foundation::IInspectable> & handler) const;
    void EnumerationCompleted(event_token token) const;
    event_token Stopped(const Windows::Foundation::TypedEventHandler<Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcher, Windows::Foundation::IInspectable> & handler) const;
    using Stopped_revoker = event_revoker<IDnssdServiceWatcher>;
    Stopped_revoker Stopped(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcher, Windows::Foundation::IInspectable> & handler) const;
    void Stopped(event_token token) const;
    Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcherStatus Status() const;
    void Start() const;
    void Stop() const;
};

}

namespace impl {

template <> struct traits<Windows::Networking::ServiceDiscovery::Dnssd::IDnssdRegistrationResult>
{
    using abi = ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdRegistrationResult;
    template <typename D> using consume = Windows::Networking::ServiceDiscovery::Dnssd::impl_IDnssdRegistrationResult<D>;
};

template <> struct traits<Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstance>
{
    using abi = ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstance;
    template <typename D> using consume = Windows::Networking::ServiceDiscovery::Dnssd::impl_IDnssdServiceInstance<D>;
};

template <> struct traits<Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstanceFactory>
{
    using abi = ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstanceFactory;
    template <typename D> using consume = Windows::Networking::ServiceDiscovery::Dnssd::impl_IDnssdServiceInstanceFactory<D>;
};

template <> struct traits<Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceWatcher>
{
    using abi = ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceWatcher;
    template <typename D> using consume = Windows::Networking::ServiceDiscovery::Dnssd::impl_IDnssdServiceWatcher<D>;
};

template <> struct traits<Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult>
{
    using abi = ABI::Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.ServiceDiscovery.Dnssd.DnssdRegistrationResult"; }
};

template <> struct traits<Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceInstance>
{
    using abi = ABI::Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceInstance;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.ServiceDiscovery.Dnssd.DnssdServiceInstance"; }
};

template <> struct traits<Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceInstanceCollection>
{
    using abi = ABI::Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceInstanceCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.ServiceDiscovery.Dnssd.DnssdServiceInstanceCollection"; }
};

template <> struct traits<Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcher>
{
    using abi = ABI::Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcher;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.ServiceDiscovery.Dnssd.DnssdServiceWatcher"; }
};

}

}
