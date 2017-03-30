// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Networking.ServiceDiscovery.Dnssd.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Networking::ServiceDiscovery::Dnssd {

struct WINRT_EBO DnssdRegistrationResult :
    Windows::Networking::ServiceDiscovery::Dnssd::IDnssdRegistrationResult,
    impl::require<DnssdRegistrationResult, Windows::Foundation::IStringable>
{
    DnssdRegistrationResult(std::nullptr_t) noexcept {}
    DnssdRegistrationResult();
};

struct WINRT_EBO DnssdServiceInstance :
    Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstance,
    impl::require<DnssdServiceInstance, Windows::Foundation::IStringable>
{
    DnssdServiceInstance(std::nullptr_t) noexcept {}
    DnssdServiceInstance(hstring_view dnssdServiceInstanceName, const Windows::Networking::HostName & hostName, uint16_t port);
};

struct WINRT_EBO DnssdServiceInstanceCollection :
    Windows::Foundation::Collections::IVectorView<Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceInstance>
{
    DnssdServiceInstanceCollection(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DnssdServiceWatcher :
    Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceWatcher
{
    DnssdServiceWatcher(std::nullptr_t) noexcept {}
};

}

}
