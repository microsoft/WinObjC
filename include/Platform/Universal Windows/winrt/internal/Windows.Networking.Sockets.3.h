// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Networking.Sockets.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Networking::Sockets {

struct WINRT_EBO ControlChannelTrigger :
    Windows::Networking::Sockets::IControlChannelTrigger,
    impl::require<ControlChannelTrigger, Windows::Networking::Sockets::IControlChannelTrigger2>
{
    ControlChannelTrigger(std::nullptr_t) noexcept {}
    ControlChannelTrigger(hstring_view channelId, uint32_t serverKeepAliveIntervalInMinutes);
    ControlChannelTrigger(hstring_view channelId, uint32_t serverKeepAliveIntervalInMinutes, Windows::Networking::Sockets::ControlChannelTriggerResourceType resourceRequestType);
};

struct WINRT_EBO DatagramSocket :
    Windows::Networking::Sockets::IDatagramSocket,
    impl::require<DatagramSocket, Windows::Networking::Sockets::IDatagramSocket2, Windows::Networking::Sockets::IDatagramSocket3>
{
    DatagramSocket(std::nullptr_t) noexcept {}
    DatagramSocket();
    using impl_IDatagramSocket::BindServiceNameAsync;
    using impl_IDatagramSocket2::BindServiceNameAsync;
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::EndpointPair>> GetEndpointPairsAsync(const Windows::Networking::HostName & remoteHostName, hstring_view remoteServiceName);
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::EndpointPair>> GetEndpointPairsAsync(const Windows::Networking::HostName & remoteHostName, hstring_view remoteServiceName, Windows::Networking::HostNameSortOptions sortOptions);
};

struct WINRT_EBO DatagramSocketControl :
    Windows::Networking::Sockets::IDatagramSocketControl,
    impl::require<DatagramSocketControl, Windows::Networking::Sockets::IDatagramSocketControl2, Windows::Networking::Sockets::IDatagramSocketControl3>
{
    DatagramSocketControl(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DatagramSocketInformation :
    Windows::Networking::Sockets::IDatagramSocketInformation
{
    DatagramSocketInformation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DatagramSocketMessageReceivedEventArgs :
    Windows::Networking::Sockets::IDatagramSocketMessageReceivedEventArgs
{
    DatagramSocketMessageReceivedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MessageWebSocket :
    Windows::Networking::Sockets::IMessageWebSocket,
    impl::require<MessageWebSocket, Windows::Networking::Sockets::IMessageWebSocket2>
{
    MessageWebSocket(std::nullptr_t) noexcept {}
    MessageWebSocket();
    using impl_IClosable::Close;
    using impl_IWebSocket::Close;
};

struct WINRT_EBO MessageWebSocketControl :
    Windows::Networking::Sockets::IMessageWebSocketControl,
    impl::require<MessageWebSocketControl, Windows::Networking::Sockets::IWebSocketControl2>
{
    MessageWebSocketControl(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MessageWebSocketInformation :
    Windows::Networking::Sockets::IWebSocketInformation,
    impl::require<MessageWebSocketInformation, Windows::Networking::Sockets::IWebSocketInformation2>
{
    MessageWebSocketInformation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MessageWebSocketMessageReceivedEventArgs :
    Windows::Networking::Sockets::IMessageWebSocketMessageReceivedEventArgs
{
    MessageWebSocketMessageReceivedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SocketActivityContext :
    Windows::Networking::Sockets::ISocketActivityContext
{
    SocketActivityContext(std::nullptr_t) noexcept {}
    SocketActivityContext(const Windows::Storage::Streams::IBuffer & data);
};

struct WINRT_EBO SocketActivityInformation :
    Windows::Networking::Sockets::ISocketActivityInformation
{
    SocketActivityInformation(std::nullptr_t) noexcept {}
    static Windows::Foundation::Collections::IMapView<hstring, Windows::Networking::Sockets::SocketActivityInformation> AllSockets();
};

struct WINRT_EBO SocketActivityTriggerDetails :
    Windows::Networking::Sockets::ISocketActivityTriggerDetails
{
    SocketActivityTriggerDetails(std::nullptr_t) noexcept {}
};

struct SocketError
{
    SocketError() = delete;
    static Windows::Networking::Sockets::SocketErrorStatus GetStatus(int32_t hresult);
};

struct WINRT_EBO StreamSocket :
    Windows::Networking::Sockets::IStreamSocket,
    impl::require<StreamSocket, Windows::Networking::Sockets::IStreamSocket2, Windows::Networking::Sockets::IStreamSocket3>
{
    StreamSocket(std::nullptr_t) noexcept {}
    StreamSocket();
    using impl_IStreamSocket::ConnectAsync;
    using impl_IStreamSocket2::ConnectAsync;
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::EndpointPair>> GetEndpointPairsAsync(const Windows::Networking::HostName & remoteHostName, hstring_view remoteServiceName);
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::EndpointPair>> GetEndpointPairsAsync(const Windows::Networking::HostName & remoteHostName, hstring_view remoteServiceName, Windows::Networking::HostNameSortOptions sortOptions);
};

struct WINRT_EBO StreamSocketControl :
    Windows::Networking::Sockets::IStreamSocketControl,
    impl::require<StreamSocketControl, Windows::Networking::Sockets::IStreamSocketControl2, Windows::Networking::Sockets::IStreamSocketControl3>
{
    StreamSocketControl(std::nullptr_t) noexcept {}
};

struct WINRT_EBO StreamSocketInformation :
    Windows::Networking::Sockets::IStreamSocketInformation,
    impl::require<StreamSocketInformation, Windows::Networking::Sockets::IStreamSocketInformation2>
{
    StreamSocketInformation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO StreamSocketListener :
    Windows::Networking::Sockets::IStreamSocketListener,
    impl::require<StreamSocketListener, Windows::Networking::Sockets::IStreamSocketListener2, Windows::Networking::Sockets::IStreamSocketListener3>
{
    StreamSocketListener(std::nullptr_t) noexcept {}
    StreamSocketListener();
    using impl_IStreamSocketListener::BindServiceNameAsync;
    using impl_IStreamSocketListener2::BindServiceNameAsync;
};

struct WINRT_EBO StreamSocketListenerConnectionReceivedEventArgs :
    Windows::Networking::Sockets::IStreamSocketListenerConnectionReceivedEventArgs
{
    StreamSocketListenerConnectionReceivedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO StreamSocketListenerControl :
    Windows::Networking::Sockets::IStreamSocketListenerControl,
    impl::require<StreamSocketListenerControl, Windows::Networking::Sockets::IStreamSocketListenerControl2>
{
    StreamSocketListenerControl(std::nullptr_t) noexcept {}
};

struct WINRT_EBO StreamSocketListenerInformation :
    Windows::Networking::Sockets::IStreamSocketListenerInformation
{
    StreamSocketListenerInformation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO StreamWebSocket :
    Windows::Networking::Sockets::IStreamWebSocket,
    impl::require<StreamWebSocket, Windows::Networking::Sockets::IStreamWebSocket2>
{
    StreamWebSocket(std::nullptr_t) noexcept {}
    StreamWebSocket();
    using impl_IClosable::Close;
    using impl_IWebSocket::Close;
};

struct WINRT_EBO StreamWebSocketControl :
    Windows::Networking::Sockets::IStreamWebSocketControl,
    impl::require<StreamWebSocketControl, Windows::Networking::Sockets::IWebSocketControl2>
{
    StreamWebSocketControl(std::nullptr_t) noexcept {}
};

struct WINRT_EBO StreamWebSocketInformation :
    Windows::Networking::Sockets::IWebSocketInformation,
    impl::require<StreamWebSocketInformation, Windows::Networking::Sockets::IWebSocketInformation2>
{
    StreamWebSocketInformation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WebSocketClosedEventArgs :
    Windows::Networking::Sockets::IWebSocketClosedEventArgs
{
    WebSocketClosedEventArgs(std::nullptr_t) noexcept {}
};

struct WebSocketError
{
    WebSocketError() = delete;
    static Windows::Web::WebErrorStatus GetStatus(int32_t hresult);
};

struct WINRT_EBO WebSocketKeepAlive :
    Windows::ApplicationModel::Background::IBackgroundTask
{
    WebSocketKeepAlive(std::nullptr_t) noexcept {}
    WebSocketKeepAlive();
};

struct WINRT_EBO WebSocketServerCustomValidationRequestedEventArgs :
    Windows::Networking::Sockets::IWebSocketServerCustomValidationRequestedEventArgs
{
    WebSocketServerCustomValidationRequestedEventArgs(std::nullptr_t) noexcept {}
};

}

}
