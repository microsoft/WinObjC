// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Networking::ServiceDiscovery::Dnssd {

struct IDnssdRegistrationResult;
struct IDnssdServiceInstance;
struct IDnssdServiceInstanceFactory;
struct IDnssdServiceWatcher;
struct DnssdRegistrationResult;
struct DnssdServiceInstance;
struct DnssdServiceInstanceCollection;
struct DnssdServiceWatcher;

}

namespace Windows::Networking::ServiceDiscovery::Dnssd {

struct IDnssdRegistrationResult;
struct IDnssdServiceInstance;
struct IDnssdServiceInstanceFactory;
struct IDnssdServiceWatcher;
struct DnssdRegistrationResult;
struct DnssdServiceInstance;
struct DnssdServiceInstanceCollection;
struct DnssdServiceWatcher;

}

namespace Windows::Networking::ServiceDiscovery::Dnssd {

template <typename T> struct impl_IDnssdRegistrationResult;
template <typename T> struct impl_IDnssdServiceInstance;
template <typename T> struct impl_IDnssdServiceInstanceFactory;
template <typename T> struct impl_IDnssdServiceWatcher;

}

namespace Windows::Networking::ServiceDiscovery::Dnssd {

enum class DnssdRegistrationStatus
{
    Success = 0,
    InvalidServiceName = 1,
    ServerError = 2,
    SecurityError = 3,
};

enum class DnssdServiceWatcherStatus
{
    Created = 0,
    Started = 1,
    EnumerationCompleted = 2,
    Stopping = 3,
    Stopped = 4,
    Aborted = 5,
};

}

}
