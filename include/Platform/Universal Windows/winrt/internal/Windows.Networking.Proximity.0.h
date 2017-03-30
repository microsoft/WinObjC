// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Networking::Proximity {

struct DeviceArrivedEventHandler;
struct DeviceDepartedEventHandler;
struct IConnectionRequestedEventArgs;
struct IPeerFinderStatics;
struct IPeerFinderStatics2;
struct IPeerInformation;
struct IPeerInformation3;
struct IPeerInformationWithHostAndService;
struct IPeerWatcher;
struct IProximityDevice;
struct IProximityDeviceStatics;
struct IProximityMessage;
struct ITriggeredConnectionStateChangedEventArgs;
struct MessageReceivedHandler;
struct MessageTransmittedHandler;
struct ConnectionRequestedEventArgs;
struct PeerInformation;
struct PeerWatcher;
struct ProximityDevice;
struct ProximityMessage;
struct TriggeredConnectionStateChangedEventArgs;

}

namespace Windows::Networking::Proximity {

struct DeviceArrivedEventHandler;
struct DeviceDepartedEventHandler;
struct MessageReceivedHandler;
struct MessageTransmittedHandler;
struct IConnectionRequestedEventArgs;
struct IPeerFinderStatics;
struct IPeerFinderStatics2;
struct IPeerInformation;
struct IPeerInformation3;
struct IPeerInformationWithHostAndService;
struct IPeerWatcher;
struct IProximityDevice;
struct IProximityDeviceStatics;
struct IProximityMessage;
struct ITriggeredConnectionStateChangedEventArgs;
struct ConnectionRequestedEventArgs;
struct PeerFinder;
struct PeerInformation;
struct PeerWatcher;
struct ProximityDevice;
struct ProximityMessage;
struct TriggeredConnectionStateChangedEventArgs;

}

namespace Windows::Networking::Proximity {

template <typename T> struct impl_IConnectionRequestedEventArgs;
template <typename T> struct impl_IPeerFinderStatics;
template <typename T> struct impl_IPeerFinderStatics2;
template <typename T> struct impl_IPeerInformation;
template <typename T> struct impl_IPeerInformation3;
template <typename T> struct impl_IPeerInformationWithHostAndService;
template <typename T> struct impl_IPeerWatcher;
template <typename T> struct impl_IProximityDevice;
template <typename T> struct impl_IProximityDeviceStatics;
template <typename T> struct impl_IProximityMessage;
template <typename T> struct impl_ITriggeredConnectionStateChangedEventArgs;
template <typename T> struct impl_DeviceArrivedEventHandler;
template <typename T> struct impl_DeviceDepartedEventHandler;
template <typename T> struct impl_MessageReceivedHandler;
template <typename T> struct impl_MessageTransmittedHandler;

}

namespace Windows::Networking::Proximity {

enum class PeerDiscoveryTypes : unsigned
{
    None = 0x0,
    Browse = 0x1,
    Triggered = 0x2,
};

DEFINE_ENUM_FLAG_OPERATORS(PeerDiscoveryTypes)

enum class PeerRole
{
    Peer = 0,
    Host = 1,
    Client = 2,
};

enum class PeerWatcherStatus
{
    Created = 0,
    Started = 1,
    EnumerationCompleted = 2,
    Stopping = 3,
    Stopped = 4,
    Aborted = 5,
};

enum class TriggeredConnectState
{
    PeerFound = 0,
    Listening = 1,
    Connecting = 2,
    Completed = 3,
    Canceled = 4,
    Failed = 5,
};

}

}
