// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Networking.Sockets.3.h"
#include "internal/Windows.Networking.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Networking.Proximity.3.h"
#include "Windows.Networking.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Networking::Proximity {

template <typename L> DeviceArrivedEventHandler::DeviceArrivedEventHandler(L lambda) :
    DeviceArrivedEventHandler(impl::make_delegate<impl_DeviceArrivedEventHandler<L>, DeviceArrivedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> DeviceArrivedEventHandler::DeviceArrivedEventHandler(F * function) :
    DeviceArrivedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> DeviceArrivedEventHandler::DeviceArrivedEventHandler(O * object, M method) :
    DeviceArrivedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void DeviceArrivedEventHandler::operator()(const Windows::Networking::Proximity::ProximityDevice & sender) const
{
    check_hresult((*(abi<DeviceArrivedEventHandler> **)this)->abi_Invoke(get_abi(sender)));
}

template <typename L> DeviceDepartedEventHandler::DeviceDepartedEventHandler(L lambda) :
    DeviceDepartedEventHandler(impl::make_delegate<impl_DeviceDepartedEventHandler<L>, DeviceDepartedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> DeviceDepartedEventHandler::DeviceDepartedEventHandler(F * function) :
    DeviceDepartedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> DeviceDepartedEventHandler::DeviceDepartedEventHandler(O * object, M method) :
    DeviceDepartedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void DeviceDepartedEventHandler::operator()(const Windows::Networking::Proximity::ProximityDevice & sender) const
{
    check_hresult((*(abi<DeviceDepartedEventHandler> **)this)->abi_Invoke(get_abi(sender)));
}

template <typename L> MessageReceivedHandler::MessageReceivedHandler(L lambda) :
    MessageReceivedHandler(impl::make_delegate<impl_MessageReceivedHandler<L>, MessageReceivedHandler>(std::forward<L>(lambda)))
{}

template <typename F> MessageReceivedHandler::MessageReceivedHandler(F * function) :
    MessageReceivedHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> MessageReceivedHandler::MessageReceivedHandler(O * object, M method) :
    MessageReceivedHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void MessageReceivedHandler::operator()(const Windows::Networking::Proximity::ProximityDevice & sender, const Windows::Networking::Proximity::ProximityMessage & message) const
{
    check_hresult((*(abi<MessageReceivedHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(message)));
}

template <typename L> MessageTransmittedHandler::MessageTransmittedHandler(L lambda) :
    MessageTransmittedHandler(impl::make_delegate<impl_MessageTransmittedHandler<L>, MessageTransmittedHandler>(std::forward<L>(lambda)))
{}

template <typename F> MessageTransmittedHandler::MessageTransmittedHandler(F * function) :
    MessageTransmittedHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> MessageTransmittedHandler::MessageTransmittedHandler(O * object, M method) :
    MessageTransmittedHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void MessageTransmittedHandler::operator()(const Windows::Networking::Proximity::ProximityDevice & sender, int64_t messageId) const
{
    check_hresult((*(abi<MessageTransmittedHandler> **)this)->abi_Invoke(get_abi(sender), messageId));
}

}

namespace impl {

template <typename D>
struct produce<D, Windows::Networking::Proximity::IConnectionRequestedEventArgs> : produce_base<D, Windows::Networking::Proximity::IConnectionRequestedEventArgs>
{
    HRESULT __stdcall get_PeerInformation(impl::abi_arg_out<Windows::Networking::Proximity::IPeerInformation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PeerInformation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Proximity::IPeerFinderStatics> : produce_base<D, Windows::Networking::Proximity::IPeerFinderStatics>
{
    HRESULT __stdcall get_AllowBluetooth(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllowBluetooth());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AllowBluetooth(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowBluetooth(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AllowInfrastructure(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllowInfrastructure());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AllowInfrastructure(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowInfrastructure(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AllowWiFiDirect(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllowWiFiDirect());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AllowWiFiDirect(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowWiFiDirect(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DisplayName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedDiscoveryTypes(Windows::Networking::Proximity::PeerDiscoveryTypes * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportedDiscoveryTypes());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AlternateIdentities(impl::abi_arg_out<Windows::Foundation::Collections::IMap<hstring, hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AlternateIdentities());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Start() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartWithMessage(impl::abi_arg_in<hstring> peerMessage) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start(*reinterpret_cast<const hstring *>(&peerMessage));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Stop() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stop();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_TriggeredConnectionStateChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::Networking::Proximity::TriggeredConnectionStateChangedEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().TriggeredConnectionStateChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::Networking::Proximity::TriggeredConnectionStateChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_TriggeredConnectionStateChanged(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TriggeredConnectionStateChanged(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ConnectionRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::Networking::Proximity::ConnectionRequestedEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().ConnectionRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::Networking::Proximity::ConnectionRequestedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ConnectionRequested(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ConnectionRequested(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAllPeersAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::Proximity::PeerInformation>>> asyncOp) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_abi(this->shim().FindAllPeersAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncOp = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ConnectAsync(impl::abi_arg_in<Windows::Networking::Proximity::IPeerInformation> peerInformation, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::Sockets::StreamSocket>> asyncOp) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_abi(this->shim().ConnectAsync(*reinterpret_cast<const Windows::Networking::Proximity::PeerInformation *>(&peerInformation)));
            return S_OK;
        }
        catch (...)
        {
            *asyncOp = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Proximity::IPeerFinderStatics2> : produce_base<D, Windows::Networking::Proximity::IPeerFinderStatics2>
{
    HRESULT __stdcall get_Role(Windows::Networking::Proximity::PeerRole * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Role());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Role(Windows::Networking::Proximity::PeerRole value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Role(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DiscoveryData(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DiscoveryData());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DiscoveryData(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DiscoveryData(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWatcher(impl::abi_arg_out<Windows::Networking::Proximity::IPeerWatcher> watcher) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *watcher = detach_abi(this->shim().CreateWatcher());
            return S_OK;
        }
        catch (...)
        {
            *watcher = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Proximity::IPeerInformation> : produce_base<D, Windows::Networking::Proximity::IPeerInformation>
{
    HRESULT __stdcall get_DisplayName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Proximity::IPeerInformation3> : produce_base<D, Windows::Networking::Proximity::IPeerInformation3>
{
    HRESULT __stdcall get_Id(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DiscoveryData(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DiscoveryData());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Proximity::IPeerInformationWithHostAndService> : produce_base<D, Windows::Networking::Proximity::IPeerInformationWithHostAndService>
{
    HRESULT __stdcall get_HostName(impl::abi_arg_out<Windows::Networking::IHostName> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HostName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServiceName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServiceName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Proximity::IPeerWatcher> : produce_base<D, Windows::Networking::Proximity::IPeerWatcher>
{
    HRESULT __stdcall add_Added(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Networking::Proximity::PeerWatcher, Windows::Networking::Proximity::PeerInformation>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Added(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Networking::Proximity::PeerWatcher, Windows::Networking::Proximity::PeerInformation> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Added(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Added(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Removed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Networking::Proximity::PeerWatcher, Windows::Networking::Proximity::PeerInformation>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Removed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Networking::Proximity::PeerWatcher, Windows::Networking::Proximity::PeerInformation> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Removed(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Removed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Updated(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Networking::Proximity::PeerWatcher, Windows::Networking::Proximity::PeerInformation>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Updated(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Networking::Proximity::PeerWatcher, Windows::Networking::Proximity::PeerInformation> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Updated(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Updated(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_EnumerationCompleted(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Networking::Proximity::PeerWatcher, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().EnumerationCompleted(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Networking::Proximity::PeerWatcher, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_EnumerationCompleted(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnumerationCompleted(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Stopped(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Networking::Proximity::PeerWatcher, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Stopped(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Networking::Proximity::PeerWatcher, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Stopped(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stopped(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Status(Windows::Networking::Proximity::PeerWatcherStatus * status) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *status = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Start() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Stop() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stop();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Proximity::IProximityDevice> : produce_base<D, Windows::Networking::Proximity::IProximityDevice>
{
    HRESULT __stdcall abi_SubscribeForMessage(impl::abi_arg_in<hstring> messageType, impl::abi_arg_in<Windows::Networking::Proximity::MessageReceivedHandler> messageReceivedHandler, int64_t * subscriptionId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *subscriptionId = detach_abi(this->shim().SubscribeForMessage(*reinterpret_cast<const hstring *>(&messageType), *reinterpret_cast<const Windows::Networking::Proximity::MessageReceivedHandler *>(&messageReceivedHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PublishMessage(impl::abi_arg_in<hstring> messageType, impl::abi_arg_in<hstring> message, int64_t * messageId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *messageId = detach_abi(this->shim().PublishMessage(*reinterpret_cast<const hstring *>(&messageType), *reinterpret_cast<const hstring *>(&message)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PublishMessageWithCallback(impl::abi_arg_in<hstring> messageType, impl::abi_arg_in<hstring> message, impl::abi_arg_in<Windows::Networking::Proximity::MessageTransmittedHandler> messageTransmittedHandler, int64_t * messageId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *messageId = detach_abi(this->shim().PublishMessage(*reinterpret_cast<const hstring *>(&messageType), *reinterpret_cast<const hstring *>(&message), *reinterpret_cast<const Windows::Networking::Proximity::MessageTransmittedHandler *>(&messageTransmittedHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PublishBinaryMessage(impl::abi_arg_in<hstring> messageType, impl::abi_arg_in<Windows::Storage::Streams::IBuffer> message, int64_t * messageId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *messageId = detach_abi(this->shim().PublishBinaryMessage(*reinterpret_cast<const hstring *>(&messageType), *reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&message)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PublishBinaryMessageWithCallback(impl::abi_arg_in<hstring> messageType, impl::abi_arg_in<Windows::Storage::Streams::IBuffer> message, impl::abi_arg_in<Windows::Networking::Proximity::MessageTransmittedHandler> messageTransmittedHandler, int64_t * messageId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *messageId = detach_abi(this->shim().PublishBinaryMessage(*reinterpret_cast<const hstring *>(&messageType), *reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&message), *reinterpret_cast<const Windows::Networking::Proximity::MessageTransmittedHandler *>(&messageTransmittedHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PublishUriMessage(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> message, int64_t * messageId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *messageId = detach_abi(this->shim().PublishUriMessage(*reinterpret_cast<const Windows::Foundation::Uri *>(&message)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PublishUriMessageWithCallback(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> message, impl::abi_arg_in<Windows::Networking::Proximity::MessageTransmittedHandler> messageTransmittedHandler, int64_t * messageId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *messageId = detach_abi(this->shim().PublishUriMessage(*reinterpret_cast<const Windows::Foundation::Uri *>(&message), *reinterpret_cast<const Windows::Networking::Proximity::MessageTransmittedHandler *>(&messageTransmittedHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StopSubscribingForMessage(int64_t subscriptionId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StopSubscribingForMessage(subscriptionId);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StopPublishingMessage(int64_t messageId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StopPublishingMessage(messageId);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_DeviceArrived(impl::abi_arg_in<Windows::Networking::Proximity::DeviceArrivedEventHandler> arrivedHandler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().DeviceArrived(*reinterpret_cast<const Windows::Networking::Proximity::DeviceArrivedEventHandler *>(&arrivedHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DeviceArrived(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DeviceArrived(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_DeviceDeparted(impl::abi_arg_in<Windows::Networking::Proximity::DeviceDepartedEventHandler> departedHandler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().DeviceDeparted(*reinterpret_cast<const Windows::Networking::Proximity::DeviceDepartedEventHandler *>(&departedHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DeviceDeparted(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DeviceDeparted(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxMessageBytes(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxMessageBytes());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BitsPerSecond(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BitsPerSecond());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Proximity::IProximityDeviceStatics> : produce_base<D, Windows::Networking::Proximity::IProximityDeviceStatics>
{
    HRESULT __stdcall abi_GetDeviceSelector(impl::abi_arg_out<hstring> selector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *selector = detach_abi(this->shim().GetDeviceSelector());
            return S_OK;
        }
        catch (...)
        {
            *selector = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDefault(impl::abi_arg_out<Windows::Networking::Proximity::IProximityDevice> proximityDevice) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *proximityDevice = detach_abi(this->shim().GetDefault());
            return S_OK;
        }
        catch (...)
        {
            *proximityDevice = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromId(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_out<Windows::Networking::Proximity::IProximityDevice> proximityDevice) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *proximityDevice = detach_abi(this->shim().FromId(*reinterpret_cast<const hstring *>(&deviceId)));
            return S_OK;
        }
        catch (...)
        {
            *proximityDevice = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Proximity::IProximityMessage> : produce_base<D, Windows::Networking::Proximity::IProximityMessage>
{
    HRESULT __stdcall get_MessageType(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MessageType());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SubscriptionId(int64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SubscriptionId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Data(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Data());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DataAsString(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DataAsString());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Proximity::ITriggeredConnectionStateChangedEventArgs> : produce_base<D, Windows::Networking::Proximity::ITriggeredConnectionStateChangedEventArgs>
{
    HRESULT __stdcall get_State(Windows::Networking::Proximity::TriggeredConnectState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().State());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Id(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Socket(impl::abi_arg_out<Windows::Networking::Sockets::IStreamSocket> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Socket());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Networking::Proximity {

template <typename D> hstring impl_IProximityMessage<D>::MessageType() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IProximityMessage)->get_MessageType(put_abi(value)));
    return value;
}

template <typename D> int64_t impl_IProximityMessage<D>::SubscriptionId() const
{
    int64_t value {};
    check_hresult(WINRT_SHIM(IProximityMessage)->get_SubscriptionId(&value));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IProximityMessage<D>::Data() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IProximityMessage)->get_Data(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IProximityMessage<D>::DataAsString() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IProximityMessage)->get_DataAsString(put_abi(value)));
    return value;
}

template <typename D> int64_t impl_IProximityDevice<D>::SubscribeForMessage(hstring_view messageType, const Windows::Networking::Proximity::MessageReceivedHandler & messageReceivedHandler) const
{
    int64_t subscriptionId {};
    check_hresult(WINRT_SHIM(IProximityDevice)->abi_SubscribeForMessage(get_abi(messageType), get_abi(messageReceivedHandler), &subscriptionId));
    return subscriptionId;
}

template <typename D> int64_t impl_IProximityDevice<D>::PublishMessage(hstring_view messageType, hstring_view message) const
{
    int64_t messageId {};
    check_hresult(WINRT_SHIM(IProximityDevice)->abi_PublishMessage(get_abi(messageType), get_abi(message), &messageId));
    return messageId;
}

template <typename D> int64_t impl_IProximityDevice<D>::PublishMessage(hstring_view messageType, hstring_view message, const Windows::Networking::Proximity::MessageTransmittedHandler & messageTransmittedHandler) const
{
    int64_t messageId {};
    check_hresult(WINRT_SHIM(IProximityDevice)->abi_PublishMessageWithCallback(get_abi(messageType), get_abi(message), get_abi(messageTransmittedHandler), &messageId));
    return messageId;
}

template <typename D> int64_t impl_IProximityDevice<D>::PublishBinaryMessage(hstring_view messageType, const Windows::Storage::Streams::IBuffer & message) const
{
    int64_t messageId {};
    check_hresult(WINRT_SHIM(IProximityDevice)->abi_PublishBinaryMessage(get_abi(messageType), get_abi(message), &messageId));
    return messageId;
}

template <typename D> int64_t impl_IProximityDevice<D>::PublishBinaryMessage(hstring_view messageType, const Windows::Storage::Streams::IBuffer & message, const Windows::Networking::Proximity::MessageTransmittedHandler & messageTransmittedHandler) const
{
    int64_t messageId {};
    check_hresult(WINRT_SHIM(IProximityDevice)->abi_PublishBinaryMessageWithCallback(get_abi(messageType), get_abi(message), get_abi(messageTransmittedHandler), &messageId));
    return messageId;
}

template <typename D> int64_t impl_IProximityDevice<D>::PublishUriMessage(const Windows::Foundation::Uri & message) const
{
    int64_t messageId {};
    check_hresult(WINRT_SHIM(IProximityDevice)->abi_PublishUriMessage(get_abi(message), &messageId));
    return messageId;
}

template <typename D> int64_t impl_IProximityDevice<D>::PublishUriMessage(const Windows::Foundation::Uri & message, const Windows::Networking::Proximity::MessageTransmittedHandler & messageTransmittedHandler) const
{
    int64_t messageId {};
    check_hresult(WINRT_SHIM(IProximityDevice)->abi_PublishUriMessageWithCallback(get_abi(message), get_abi(messageTransmittedHandler), &messageId));
    return messageId;
}

template <typename D> void impl_IProximityDevice<D>::StopSubscribingForMessage(int64_t subscriptionId) const
{
    check_hresult(WINRT_SHIM(IProximityDevice)->abi_StopSubscribingForMessage(subscriptionId));
}

template <typename D> void impl_IProximityDevice<D>::StopPublishingMessage(int64_t messageId) const
{
    check_hresult(WINRT_SHIM(IProximityDevice)->abi_StopPublishingMessage(messageId));
}

template <typename D> event_token impl_IProximityDevice<D>::DeviceArrived(const Windows::Networking::Proximity::DeviceArrivedEventHandler & arrivedHandler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IProximityDevice)->add_DeviceArrived(get_abi(arrivedHandler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IProximityDevice> impl_IProximityDevice<D>::DeviceArrived(auto_revoke_t, const Windows::Networking::Proximity::DeviceArrivedEventHandler & arrivedHandler) const
{
    return impl::make_event_revoker<D, IProximityDevice>(this, &ABI::Windows::Networking::Proximity::IProximityDevice::remove_DeviceArrived, DeviceArrived(arrivedHandler));
}

template <typename D> void impl_IProximityDevice<D>::DeviceArrived(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IProximityDevice)->remove_DeviceArrived(cookie));
}

template <typename D> event_token impl_IProximityDevice<D>::DeviceDeparted(const Windows::Networking::Proximity::DeviceDepartedEventHandler & departedHandler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IProximityDevice)->add_DeviceDeparted(get_abi(departedHandler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IProximityDevice> impl_IProximityDevice<D>::DeviceDeparted(auto_revoke_t, const Windows::Networking::Proximity::DeviceDepartedEventHandler & departedHandler) const
{
    return impl::make_event_revoker<D, IProximityDevice>(this, &ABI::Windows::Networking::Proximity::IProximityDevice::remove_DeviceDeparted, DeviceDeparted(departedHandler));
}

template <typename D> void impl_IProximityDevice<D>::DeviceDeparted(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IProximityDevice)->remove_DeviceDeparted(cookie));
}

template <typename D> uint32_t impl_IProximityDevice<D>::MaxMessageBytes() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IProximityDevice)->get_MaxMessageBytes(&value));
    return value;
}

template <typename D> uint64_t impl_IProximityDevice<D>::BitsPerSecond() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IProximityDevice)->get_BitsPerSecond(&value));
    return value;
}

template <typename D> hstring impl_IProximityDevice<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IProximityDevice)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IProximityDeviceStatics<D>::GetDeviceSelector() const
{
    hstring selector;
    check_hresult(WINRT_SHIM(IProximityDeviceStatics)->abi_GetDeviceSelector(put_abi(selector)));
    return selector;
}

template <typename D> Windows::Networking::Proximity::ProximityDevice impl_IProximityDeviceStatics<D>::GetDefault() const
{
    Windows::Networking::Proximity::ProximityDevice proximityDevice { nullptr };
    check_hresult(WINRT_SHIM(IProximityDeviceStatics)->abi_GetDefault(put_abi(proximityDevice)));
    return proximityDevice;
}

template <typename D> Windows::Networking::Proximity::ProximityDevice impl_IProximityDeviceStatics<D>::FromId(hstring_view deviceId) const
{
    Windows::Networking::Proximity::ProximityDevice proximityDevice { nullptr };
    check_hresult(WINRT_SHIM(IProximityDeviceStatics)->abi_FromId(get_abi(deviceId), put_abi(proximityDevice)));
    return proximityDevice;
}

template <typename D> Windows::Networking::Proximity::TriggeredConnectState impl_ITriggeredConnectionStateChangedEventArgs<D>::State() const
{
    Windows::Networking::Proximity::TriggeredConnectState value {};
    check_hresult(WINRT_SHIM(ITriggeredConnectionStateChangedEventArgs)->get_State(&value));
    return value;
}

template <typename D> uint32_t impl_ITriggeredConnectionStateChangedEventArgs<D>::Id() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ITriggeredConnectionStateChangedEventArgs)->get_Id(&value));
    return value;
}

template <typename D> Windows::Networking::Sockets::StreamSocket impl_ITriggeredConnectionStateChangedEventArgs<D>::Socket() const
{
    Windows::Networking::Sockets::StreamSocket value { nullptr };
    check_hresult(WINRT_SHIM(ITriggeredConnectionStateChangedEventArgs)->get_Socket(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IPeerInformation<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPeerInformation)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::HostName impl_IPeerInformationWithHostAndService<D>::HostName() const
{
    Windows::Networking::HostName value { nullptr };
    check_hresult(WINRT_SHIM(IPeerInformationWithHostAndService)->get_HostName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IPeerInformationWithHostAndService<D>::ServiceName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPeerInformationWithHostAndService)->get_ServiceName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IPeerInformation3<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPeerInformation3)->get_Id(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IPeerInformation3<D>::DiscoveryData() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IPeerInformation3)->get_DiscoveryData(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::Proximity::PeerInformation impl_IConnectionRequestedEventArgs<D>::PeerInformation() const
{
    Windows::Networking::Proximity::PeerInformation value { nullptr };
    check_hresult(WINRT_SHIM(IConnectionRequestedEventArgs)->get_PeerInformation(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IPeerWatcher<D>::Added(const Windows::Foundation::TypedEventHandler<Windows::Networking::Proximity::PeerWatcher, Windows::Networking::Proximity::PeerInformation> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPeerWatcher)->add_Added(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPeerWatcher> impl_IPeerWatcher<D>::Added(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Networking::Proximity::PeerWatcher, Windows::Networking::Proximity::PeerInformation> & handler) const
{
    return impl::make_event_revoker<D, IPeerWatcher>(this, &ABI::Windows::Networking::Proximity::IPeerWatcher::remove_Added, Added(handler));
}

template <typename D> void impl_IPeerWatcher<D>::Added(event_token token) const
{
    check_hresult(WINRT_SHIM(IPeerWatcher)->remove_Added(token));
}

template <typename D> event_token impl_IPeerWatcher<D>::Removed(const Windows::Foundation::TypedEventHandler<Windows::Networking::Proximity::PeerWatcher, Windows::Networking::Proximity::PeerInformation> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPeerWatcher)->add_Removed(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPeerWatcher> impl_IPeerWatcher<D>::Removed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Networking::Proximity::PeerWatcher, Windows::Networking::Proximity::PeerInformation> & handler) const
{
    return impl::make_event_revoker<D, IPeerWatcher>(this, &ABI::Windows::Networking::Proximity::IPeerWatcher::remove_Removed, Removed(handler));
}

template <typename D> void impl_IPeerWatcher<D>::Removed(event_token token) const
{
    check_hresult(WINRT_SHIM(IPeerWatcher)->remove_Removed(token));
}

template <typename D> event_token impl_IPeerWatcher<D>::Updated(const Windows::Foundation::TypedEventHandler<Windows::Networking::Proximity::PeerWatcher, Windows::Networking::Proximity::PeerInformation> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPeerWatcher)->add_Updated(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPeerWatcher> impl_IPeerWatcher<D>::Updated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Networking::Proximity::PeerWatcher, Windows::Networking::Proximity::PeerInformation> & handler) const
{
    return impl::make_event_revoker<D, IPeerWatcher>(this, &ABI::Windows::Networking::Proximity::IPeerWatcher::remove_Updated, Updated(handler));
}

template <typename D> void impl_IPeerWatcher<D>::Updated(event_token token) const
{
    check_hresult(WINRT_SHIM(IPeerWatcher)->remove_Updated(token));
}

template <typename D> event_token impl_IPeerWatcher<D>::EnumerationCompleted(const Windows::Foundation::TypedEventHandler<Windows::Networking::Proximity::PeerWatcher, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPeerWatcher)->add_EnumerationCompleted(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPeerWatcher> impl_IPeerWatcher<D>::EnumerationCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Networking::Proximity::PeerWatcher, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IPeerWatcher>(this, &ABI::Windows::Networking::Proximity::IPeerWatcher::remove_EnumerationCompleted, EnumerationCompleted(handler));
}

template <typename D> void impl_IPeerWatcher<D>::EnumerationCompleted(event_token token) const
{
    check_hresult(WINRT_SHIM(IPeerWatcher)->remove_EnumerationCompleted(token));
}

template <typename D> event_token impl_IPeerWatcher<D>::Stopped(const Windows::Foundation::TypedEventHandler<Windows::Networking::Proximity::PeerWatcher, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPeerWatcher)->add_Stopped(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPeerWatcher> impl_IPeerWatcher<D>::Stopped(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Networking::Proximity::PeerWatcher, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IPeerWatcher>(this, &ABI::Windows::Networking::Proximity::IPeerWatcher::remove_Stopped, Stopped(handler));
}

template <typename D> void impl_IPeerWatcher<D>::Stopped(event_token token) const
{
    check_hresult(WINRT_SHIM(IPeerWatcher)->remove_Stopped(token));
}

template <typename D> Windows::Networking::Proximity::PeerWatcherStatus impl_IPeerWatcher<D>::Status() const
{
    Windows::Networking::Proximity::PeerWatcherStatus status {};
    check_hresult(WINRT_SHIM(IPeerWatcher)->get_Status(&status));
    return status;
}

template <typename D> void impl_IPeerWatcher<D>::Start() const
{
    check_hresult(WINRT_SHIM(IPeerWatcher)->abi_Start());
}

template <typename D> void impl_IPeerWatcher<D>::Stop() const
{
    check_hresult(WINRT_SHIM(IPeerWatcher)->abi_Stop());
}

template <typename D> bool impl_IPeerFinderStatics<D>::AllowBluetooth() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPeerFinderStatics)->get_AllowBluetooth(&value));
    return value;
}

template <typename D> void impl_IPeerFinderStatics<D>::AllowBluetooth(bool value) const
{
    check_hresult(WINRT_SHIM(IPeerFinderStatics)->put_AllowBluetooth(value));
}

template <typename D> bool impl_IPeerFinderStatics<D>::AllowInfrastructure() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPeerFinderStatics)->get_AllowInfrastructure(&value));
    return value;
}

template <typename D> void impl_IPeerFinderStatics<D>::AllowInfrastructure(bool value) const
{
    check_hresult(WINRT_SHIM(IPeerFinderStatics)->put_AllowInfrastructure(value));
}

template <typename D> bool impl_IPeerFinderStatics<D>::AllowWiFiDirect() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPeerFinderStatics)->get_AllowWiFiDirect(&value));
    return value;
}

template <typename D> void impl_IPeerFinderStatics<D>::AllowWiFiDirect(bool value) const
{
    check_hresult(WINRT_SHIM(IPeerFinderStatics)->put_AllowWiFiDirect(value));
}

template <typename D> hstring impl_IPeerFinderStatics<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPeerFinderStatics)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> void impl_IPeerFinderStatics<D>::DisplayName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPeerFinderStatics)->put_DisplayName(get_abi(value)));
}

template <typename D> Windows::Networking::Proximity::PeerDiscoveryTypes impl_IPeerFinderStatics<D>::SupportedDiscoveryTypes() const
{
    Windows::Networking::Proximity::PeerDiscoveryTypes value {};
    check_hresult(WINRT_SHIM(IPeerFinderStatics)->get_SupportedDiscoveryTypes(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMap<hstring, hstring> impl_IPeerFinderStatics<D>::AlternateIdentities() const
{
    Windows::Foundation::Collections::IMap<hstring, hstring> value;
    check_hresult(WINRT_SHIM(IPeerFinderStatics)->get_AlternateIdentities(put_abi(value)));
    return value;
}

template <typename D> void impl_IPeerFinderStatics<D>::Start() const
{
    check_hresult(WINRT_SHIM(IPeerFinderStatics)->abi_Start());
}

template <typename D> void impl_IPeerFinderStatics<D>::Start(hstring_view peerMessage) const
{
    check_hresult(WINRT_SHIM(IPeerFinderStatics)->abi_StartWithMessage(get_abi(peerMessage)));
}

template <typename D> void impl_IPeerFinderStatics<D>::Stop() const
{
    check_hresult(WINRT_SHIM(IPeerFinderStatics)->abi_Stop());
}

template <typename D> event_token impl_IPeerFinderStatics<D>::TriggeredConnectionStateChanged(const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::Networking::Proximity::TriggeredConnectionStateChangedEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IPeerFinderStatics)->add_TriggeredConnectionStateChanged(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IPeerFinderStatics> impl_IPeerFinderStatics<D>::TriggeredConnectionStateChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::Networking::Proximity::TriggeredConnectionStateChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IPeerFinderStatics>(this, &ABI::Windows::Networking::Proximity::IPeerFinderStatics::remove_TriggeredConnectionStateChanged, TriggeredConnectionStateChanged(handler));
}

template <typename D> void impl_IPeerFinderStatics<D>::TriggeredConnectionStateChanged(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IPeerFinderStatics)->remove_TriggeredConnectionStateChanged(cookie));
}

template <typename D> event_token impl_IPeerFinderStatics<D>::ConnectionRequested(const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::Networking::Proximity::ConnectionRequestedEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IPeerFinderStatics)->add_ConnectionRequested(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IPeerFinderStatics> impl_IPeerFinderStatics<D>::ConnectionRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::Networking::Proximity::ConnectionRequestedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IPeerFinderStatics>(this, &ABI::Windows::Networking::Proximity::IPeerFinderStatics::remove_ConnectionRequested, ConnectionRequested(handler));
}

template <typename D> void impl_IPeerFinderStatics<D>::ConnectionRequested(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IPeerFinderStatics)->remove_ConnectionRequested(cookie));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::Proximity::PeerInformation>> impl_IPeerFinderStatics<D>::FindAllPeersAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::Proximity::PeerInformation>> asyncOp;
    check_hresult(WINRT_SHIM(IPeerFinderStatics)->abi_FindAllPeersAsync(put_abi(asyncOp)));
    return asyncOp;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::Sockets::StreamSocket> impl_IPeerFinderStatics<D>::ConnectAsync(const Windows::Networking::Proximity::PeerInformation & peerInformation) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::Sockets::StreamSocket> asyncOp;
    check_hresult(WINRT_SHIM(IPeerFinderStatics)->abi_ConnectAsync(get_abi(peerInformation), put_abi(asyncOp)));
    return asyncOp;
}

template <typename D> Windows::Networking::Proximity::PeerRole impl_IPeerFinderStatics2<D>::Role() const
{
    Windows::Networking::Proximity::PeerRole value {};
    check_hresult(WINRT_SHIM(IPeerFinderStatics2)->get_Role(&value));
    return value;
}

template <typename D> void impl_IPeerFinderStatics2<D>::Role(Windows::Networking::Proximity::PeerRole value) const
{
    check_hresult(WINRT_SHIM(IPeerFinderStatics2)->put_Role(value));
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IPeerFinderStatics2<D>::DiscoveryData() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IPeerFinderStatics2)->get_DiscoveryData(put_abi(value)));
    return value;
}

template <typename D> void impl_IPeerFinderStatics2<D>::DiscoveryData(const Windows::Storage::Streams::IBuffer & value) const
{
    check_hresult(WINRT_SHIM(IPeerFinderStatics2)->put_DiscoveryData(get_abi(value)));
}

template <typename D> Windows::Networking::Proximity::PeerWatcher impl_IPeerFinderStatics2<D>::CreateWatcher() const
{
    Windows::Networking::Proximity::PeerWatcher watcher { nullptr };
    check_hresult(WINRT_SHIM(IPeerFinderStatics2)->abi_CreateWatcher(put_abi(watcher)));
    return watcher;
}

inline bool PeerFinder::AllowBluetooth()
{
    return get_activation_factory<PeerFinder, IPeerFinderStatics>().AllowBluetooth();
}

inline void PeerFinder::AllowBluetooth(bool value)
{
    get_activation_factory<PeerFinder, IPeerFinderStatics>().AllowBluetooth(value);
}

inline bool PeerFinder::AllowInfrastructure()
{
    return get_activation_factory<PeerFinder, IPeerFinderStatics>().AllowInfrastructure();
}

inline void PeerFinder::AllowInfrastructure(bool value)
{
    get_activation_factory<PeerFinder, IPeerFinderStatics>().AllowInfrastructure(value);
}

inline bool PeerFinder::AllowWiFiDirect()
{
    return get_activation_factory<PeerFinder, IPeerFinderStatics>().AllowWiFiDirect();
}

inline void PeerFinder::AllowWiFiDirect(bool value)
{
    get_activation_factory<PeerFinder, IPeerFinderStatics>().AllowWiFiDirect(value);
}

inline hstring PeerFinder::DisplayName()
{
    return get_activation_factory<PeerFinder, IPeerFinderStatics>().DisplayName();
}

inline void PeerFinder::DisplayName(hstring_view value)
{
    get_activation_factory<PeerFinder, IPeerFinderStatics>().DisplayName(value);
}

inline Windows::Networking::Proximity::PeerDiscoveryTypes PeerFinder::SupportedDiscoveryTypes()
{
    return get_activation_factory<PeerFinder, IPeerFinderStatics>().SupportedDiscoveryTypes();
}

inline Windows::Foundation::Collections::IMap<hstring, hstring> PeerFinder::AlternateIdentities()
{
    return get_activation_factory<PeerFinder, IPeerFinderStatics>().AlternateIdentities();
}

inline void PeerFinder::Start()
{
    get_activation_factory<PeerFinder, IPeerFinderStatics>().Start();
}

inline void PeerFinder::Start(hstring_view peerMessage)
{
    get_activation_factory<PeerFinder, IPeerFinderStatics>().Start(peerMessage);
}

inline void PeerFinder::Stop()
{
    get_activation_factory<PeerFinder, IPeerFinderStatics>().Stop();
}

inline event_token PeerFinder::TriggeredConnectionStateChanged(const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::Networking::Proximity::TriggeredConnectionStateChangedEventArgs> & handler)
{
    return get_activation_factory<PeerFinder, IPeerFinderStatics>().TriggeredConnectionStateChanged(handler);
}

inline factory_event_revoker<IPeerFinderStatics> PeerFinder::TriggeredConnectionStateChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::Networking::Proximity::TriggeredConnectionStateChangedEventArgs> & handler)
{
    auto factory = get_activation_factory<PeerFinder, IPeerFinderStatics>();
    return { factory, &ABI::Windows::Networking::Proximity::IPeerFinderStatics::remove_TriggeredConnectionStateChanged, factory.TriggeredConnectionStateChanged(handler) };
}

inline void PeerFinder::TriggeredConnectionStateChanged(event_token cookie)
{
    get_activation_factory<PeerFinder, IPeerFinderStatics>().TriggeredConnectionStateChanged(cookie);
}

inline event_token PeerFinder::ConnectionRequested(const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::Networking::Proximity::ConnectionRequestedEventArgs> & handler)
{
    return get_activation_factory<PeerFinder, IPeerFinderStatics>().ConnectionRequested(handler);
}

inline factory_event_revoker<IPeerFinderStatics> PeerFinder::ConnectionRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::Networking::Proximity::ConnectionRequestedEventArgs> & handler)
{
    auto factory = get_activation_factory<PeerFinder, IPeerFinderStatics>();
    return { factory, &ABI::Windows::Networking::Proximity::IPeerFinderStatics::remove_ConnectionRequested, factory.ConnectionRequested(handler) };
}

inline void PeerFinder::ConnectionRequested(event_token cookie)
{
    get_activation_factory<PeerFinder, IPeerFinderStatics>().ConnectionRequested(cookie);
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::Proximity::PeerInformation>> PeerFinder::FindAllPeersAsync()
{
    return get_activation_factory<PeerFinder, IPeerFinderStatics>().FindAllPeersAsync();
}

inline Windows::Foundation::IAsyncOperation<Windows::Networking::Sockets::StreamSocket> PeerFinder::ConnectAsync(const Windows::Networking::Proximity::PeerInformation & peerInformation)
{
    return get_activation_factory<PeerFinder, IPeerFinderStatics>().ConnectAsync(peerInformation);
}

inline Windows::Networking::Proximity::PeerRole PeerFinder::Role()
{
    return get_activation_factory<PeerFinder, IPeerFinderStatics2>().Role();
}

inline void PeerFinder::Role(Windows::Networking::Proximity::PeerRole value)
{
    get_activation_factory<PeerFinder, IPeerFinderStatics2>().Role(value);
}

inline Windows::Storage::Streams::IBuffer PeerFinder::DiscoveryData()
{
    return get_activation_factory<PeerFinder, IPeerFinderStatics2>().DiscoveryData();
}

inline void PeerFinder::DiscoveryData(const Windows::Storage::Streams::IBuffer & value)
{
    get_activation_factory<PeerFinder, IPeerFinderStatics2>().DiscoveryData(value);
}

inline Windows::Networking::Proximity::PeerWatcher PeerFinder::CreateWatcher()
{
    return get_activation_factory<PeerFinder, IPeerFinderStatics2>().CreateWatcher();
}

inline hstring ProximityDevice::GetDeviceSelector()
{
    return get_activation_factory<ProximityDevice, IProximityDeviceStatics>().GetDeviceSelector();
}

inline Windows::Networking::Proximity::ProximityDevice ProximityDevice::GetDefault()
{
    return get_activation_factory<ProximityDevice, IProximityDeviceStatics>().GetDefault();
}

inline Windows::Networking::Proximity::ProximityDevice ProximityDevice::FromId(hstring_view deviceId)
{
    return get_activation_factory<ProximityDevice, IProximityDeviceStatics>().FromId(deviceId);
}

}

}
#pragma warning(pop)
