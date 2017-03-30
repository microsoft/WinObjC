// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::WiFiDirect::Services {

struct IWiFiDirectService;
struct IWiFiDirectServiceAdvertiser;
struct IWiFiDirectServiceAdvertiserFactory;
struct IWiFiDirectServiceAutoAcceptSessionConnectedEventArgs;
struct IWiFiDirectServiceProvisioningInfo;
struct IWiFiDirectServiceRemotePortAddedEventArgs;
struct IWiFiDirectServiceSession;
struct IWiFiDirectServiceSessionDeferredEventArgs;
struct IWiFiDirectServiceSessionRequest;
struct IWiFiDirectServiceSessionRequestedEventArgs;
struct IWiFiDirectServiceStatics;
struct WiFiDirectService;
struct WiFiDirectServiceAdvertiser;
struct WiFiDirectServiceAutoAcceptSessionConnectedEventArgs;
struct WiFiDirectServiceProvisioningInfo;
struct WiFiDirectServiceRemotePortAddedEventArgs;
struct WiFiDirectServiceSession;
struct WiFiDirectServiceSessionDeferredEventArgs;
struct WiFiDirectServiceSessionRequest;
struct WiFiDirectServiceSessionRequestedEventArgs;

}

namespace Windows::Devices::WiFiDirect::Services {

struct IWiFiDirectService;
struct IWiFiDirectServiceAdvertiser;
struct IWiFiDirectServiceAdvertiserFactory;
struct IWiFiDirectServiceAutoAcceptSessionConnectedEventArgs;
struct IWiFiDirectServiceProvisioningInfo;
struct IWiFiDirectServiceRemotePortAddedEventArgs;
struct IWiFiDirectServiceSession;
struct IWiFiDirectServiceSessionDeferredEventArgs;
struct IWiFiDirectServiceSessionRequest;
struct IWiFiDirectServiceSessionRequestedEventArgs;
struct IWiFiDirectServiceStatics;
struct WiFiDirectService;
struct WiFiDirectServiceAdvertiser;
struct WiFiDirectServiceAutoAcceptSessionConnectedEventArgs;
struct WiFiDirectServiceProvisioningInfo;
struct WiFiDirectServiceRemotePortAddedEventArgs;
struct WiFiDirectServiceSession;
struct WiFiDirectServiceSessionDeferredEventArgs;
struct WiFiDirectServiceSessionRequest;
struct WiFiDirectServiceSessionRequestedEventArgs;

}

namespace Windows::Devices::WiFiDirect::Services {

template <typename T> struct impl_IWiFiDirectService;
template <typename T> struct impl_IWiFiDirectServiceAdvertiser;
template <typename T> struct impl_IWiFiDirectServiceAdvertiserFactory;
template <typename T> struct impl_IWiFiDirectServiceAutoAcceptSessionConnectedEventArgs;
template <typename T> struct impl_IWiFiDirectServiceProvisioningInfo;
template <typename T> struct impl_IWiFiDirectServiceRemotePortAddedEventArgs;
template <typename T> struct impl_IWiFiDirectServiceSession;
template <typename T> struct impl_IWiFiDirectServiceSessionDeferredEventArgs;
template <typename T> struct impl_IWiFiDirectServiceSessionRequest;
template <typename T> struct impl_IWiFiDirectServiceSessionRequestedEventArgs;
template <typename T> struct impl_IWiFiDirectServiceStatics;

}

namespace Windows::Devices::WiFiDirect::Services {

enum class WiFiDirectServiceAdvertisementStatus
{
    Created = 0,
    Started = 1,
    Stopped = 2,
    Aborted = 3,
};

enum class WiFiDirectServiceConfigurationMethod
{
    Default = 0,
    PinDisplay = 1,
    PinEntry = 2,
};

enum class WiFiDirectServiceError
{
    Success = 0,
    RadioNotAvailable = 1,
    ResourceInUse = 2,
    UnsupportedHardware = 3,
    NoHardware = 4,
};

enum class WiFiDirectServiceIPProtocol
{
    Tcp = 6,
    Udp = 17,
};

enum class WiFiDirectServiceSessionErrorStatus
{
    Ok = 0,
    Disassociated = 1,
    LocalClose = 2,
    RemoteClose = 3,
    SystemFailure = 4,
    NoResponseFromRemote = 5,
};

enum class WiFiDirectServiceSessionStatus
{
    Closed = 0,
    Initiated = 1,
    Requested = 2,
    Open = 3,
};

enum class WiFiDirectServiceStatus
{
    Available = 0,
    Busy = 1,
    Custom = 2,
};

}

}
