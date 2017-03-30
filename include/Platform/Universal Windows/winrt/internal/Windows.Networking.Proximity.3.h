// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Networking.Proximity.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Networking::Proximity {

template <typename H> struct impl_DeviceArrivedEventHandler : implements<impl_DeviceArrivedEventHandler<H>, abi<DeviceArrivedEventHandler>>, H
{
    impl_DeviceArrivedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Networking::Proximity::IProximityDevice> sender) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Networking::Proximity::ProximityDevice *>(&sender));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_DeviceDepartedEventHandler : implements<impl_DeviceDepartedEventHandler<H>, abi<DeviceDepartedEventHandler>>, H
{
    impl_DeviceDepartedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Networking::Proximity::IProximityDevice> sender) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Networking::Proximity::ProximityDevice *>(&sender));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_MessageReceivedHandler : implements<impl_MessageReceivedHandler<H>, abi<MessageReceivedHandler>>, H
{
    impl_MessageReceivedHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Networking::Proximity::IProximityDevice> sender, impl::abi_arg_in<Windows::Networking::Proximity::IProximityMessage> message) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Networking::Proximity::ProximityDevice *>(&sender), *reinterpret_cast<const Windows::Networking::Proximity::ProximityMessage *>(&message));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_MessageTransmittedHandler : implements<impl_MessageTransmittedHandler<H>, abi<MessageTransmittedHandler>>, H
{
    impl_MessageTransmittedHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Networking::Proximity::IProximityDevice> sender, int64_t messageId) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Networking::Proximity::ProximityDevice *>(&sender), messageId);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Networking::Proximity {

struct WINRT_EBO ConnectionRequestedEventArgs :
    Windows::Networking::Proximity::IConnectionRequestedEventArgs
{
    ConnectionRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct PeerFinder
{
    PeerFinder() = delete;
    static bool AllowBluetooth();
    static void AllowBluetooth(bool value);
    static bool AllowInfrastructure();
    static void AllowInfrastructure(bool value);
    static bool AllowWiFiDirect();
    static void AllowWiFiDirect(bool value);
    static hstring DisplayName();
    static void DisplayName(hstring_view value);
    static Windows::Networking::Proximity::PeerDiscoveryTypes SupportedDiscoveryTypes();
    static Windows::Foundation::Collections::IMap<hstring, hstring> AlternateIdentities();
    static void Start();
    static void Start(hstring_view peerMessage);
    static void Stop();
    static event_token TriggeredConnectionStateChanged(const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::Networking::Proximity::TriggeredConnectionStateChangedEventArgs> & handler);
    using TriggeredConnectionStateChanged_revoker = factory_event_revoker<IPeerFinderStatics>;
    static TriggeredConnectionStateChanged_revoker TriggeredConnectionStateChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::Networking::Proximity::TriggeredConnectionStateChangedEventArgs> & handler);
    static void TriggeredConnectionStateChanged(event_token cookie);
    static event_token ConnectionRequested(const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::Networking::Proximity::ConnectionRequestedEventArgs> & handler);
    using ConnectionRequested_revoker = factory_event_revoker<IPeerFinderStatics>;
    static ConnectionRequested_revoker ConnectionRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::Networking::Proximity::ConnectionRequestedEventArgs> & handler);
    static void ConnectionRequested(event_token cookie);
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::Proximity::PeerInformation>> FindAllPeersAsync();
    static Windows::Foundation::IAsyncOperation<Windows::Networking::Sockets::StreamSocket> ConnectAsync(const Windows::Networking::Proximity::PeerInformation & peerInformation);
    static Windows::Networking::Proximity::PeerRole Role();
    static void Role(Windows::Networking::Proximity::PeerRole value);
    static Windows::Storage::Streams::IBuffer DiscoveryData();
    static void DiscoveryData(const Windows::Storage::Streams::IBuffer & value);
    static Windows::Networking::Proximity::PeerWatcher CreateWatcher();
};

struct WINRT_EBO PeerInformation :
    Windows::Networking::Proximity::IPeerInformation,
    impl::require<PeerInformation, Windows::Networking::Proximity::IPeerInformationWithHostAndService, Windows::Networking::Proximity::IPeerInformation3>
{
    PeerInformation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PeerWatcher :
    Windows::Networking::Proximity::IPeerWatcher
{
    PeerWatcher(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ProximityDevice :
    Windows::Networking::Proximity::IProximityDevice
{
    ProximityDevice(std::nullptr_t) noexcept {}
    static hstring GetDeviceSelector();
    static Windows::Networking::Proximity::ProximityDevice GetDefault();
    static Windows::Networking::Proximity::ProximityDevice FromId(hstring_view deviceId);
};

struct WINRT_EBO ProximityMessage :
    Windows::Networking::Proximity::IProximityMessage
{
    ProximityMessage(std::nullptr_t) noexcept {}
};

struct WINRT_EBO TriggeredConnectionStateChangedEventArgs :
    Windows::Networking::Proximity::ITriggeredConnectionStateChangedEventArgs
{
    TriggeredConnectionStateChangedEventArgs(std::nullptr_t) noexcept {}
};

}

}
