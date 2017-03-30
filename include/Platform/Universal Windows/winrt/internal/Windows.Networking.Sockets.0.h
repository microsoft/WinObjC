// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Networking::Sockets {

struct RoundTripTimeStatistics;
struct BandwidthStatistics;

}

namespace Windows::Networking::Sockets {

using RoundTripTimeStatistics = ABI::Windows::Networking::Sockets::RoundTripTimeStatistics;
using BandwidthStatistics = ABI::Windows::Networking::Sockets::BandwidthStatistics;

}

namespace ABI::Windows::Networking::Sockets {

struct IControlChannelTrigger;
struct IControlChannelTrigger2;
struct IControlChannelTriggerEventDetails;
struct IControlChannelTriggerFactory;
struct IControlChannelTriggerResetEventDetails;
struct IDatagramSocket;
struct IDatagramSocket2;
struct IDatagramSocket3;
struct IDatagramSocketControl;
struct IDatagramSocketControl2;
struct IDatagramSocketControl3;
struct IDatagramSocketInformation;
struct IDatagramSocketMessageReceivedEventArgs;
struct IDatagramSocketStatics;
struct IMessageWebSocket;
struct IMessageWebSocket2;
struct IMessageWebSocketControl;
struct IMessageWebSocketMessageReceivedEventArgs;
struct ISocketActivityContext;
struct ISocketActivityContextFactory;
struct ISocketActivityInformation;
struct ISocketActivityInformationStatics;
struct ISocketActivityTriggerDetails;
struct ISocketErrorStatics;
struct IStreamSocket;
struct IStreamSocket2;
struct IStreamSocket3;
struct IStreamSocketControl;
struct IStreamSocketControl2;
struct IStreamSocketControl3;
struct IStreamSocketInformation;
struct IStreamSocketInformation2;
struct IStreamSocketListener;
struct IStreamSocketListener2;
struct IStreamSocketListener3;
struct IStreamSocketListenerConnectionReceivedEventArgs;
struct IStreamSocketListenerControl;
struct IStreamSocketListenerControl2;
struct IStreamSocketListenerInformation;
struct IStreamSocketStatics;
struct IStreamWebSocket;
struct IStreamWebSocket2;
struct IStreamWebSocketControl;
struct IWebSocket;
struct IWebSocketClosedEventArgs;
struct IWebSocketControl;
struct IWebSocketControl2;
struct IWebSocketErrorStatics;
struct IWebSocketInformation;
struct IWebSocketInformation2;
struct IWebSocketServerCustomValidationRequestedEventArgs;
struct ControlChannelTrigger;
struct DatagramSocket;
struct DatagramSocketControl;
struct DatagramSocketInformation;
struct DatagramSocketMessageReceivedEventArgs;
struct MessageWebSocket;
struct MessageWebSocketControl;
struct MessageWebSocketInformation;
struct MessageWebSocketMessageReceivedEventArgs;
struct SocketActivityContext;
struct SocketActivityInformation;
struct SocketActivityTriggerDetails;
struct StreamSocket;
struct StreamSocketControl;
struct StreamSocketInformation;
struct StreamSocketListener;
struct StreamSocketListenerConnectionReceivedEventArgs;
struct StreamSocketListenerControl;
struct StreamSocketListenerInformation;
struct StreamWebSocket;
struct StreamWebSocketControl;
struct StreamWebSocketInformation;
struct WebSocketClosedEventArgs;
struct WebSocketKeepAlive;
struct WebSocketServerCustomValidationRequestedEventArgs;

}

namespace Windows::Networking::Sockets {

struct IControlChannelTrigger;
struct IControlChannelTrigger2;
struct IControlChannelTriggerEventDetails;
struct IControlChannelTriggerFactory;
struct IControlChannelTriggerResetEventDetails;
struct IDatagramSocket;
struct IDatagramSocket2;
struct IDatagramSocket3;
struct IDatagramSocketControl;
struct IDatagramSocketControl2;
struct IDatagramSocketControl3;
struct IDatagramSocketInformation;
struct IDatagramSocketMessageReceivedEventArgs;
struct IDatagramSocketStatics;
struct IMessageWebSocket;
struct IMessageWebSocket2;
struct IMessageWebSocketControl;
struct IMessageWebSocketMessageReceivedEventArgs;
struct ISocketActivityContext;
struct ISocketActivityContextFactory;
struct ISocketActivityInformation;
struct ISocketActivityInformationStatics;
struct ISocketActivityTriggerDetails;
struct ISocketErrorStatics;
struct IStreamSocket;
struct IStreamSocket2;
struct IStreamSocket3;
struct IStreamSocketControl;
struct IStreamSocketControl2;
struct IStreamSocketControl3;
struct IStreamSocketInformation;
struct IStreamSocketInformation2;
struct IStreamSocketListener;
struct IStreamSocketListener2;
struct IStreamSocketListener3;
struct IStreamSocketListenerConnectionReceivedEventArgs;
struct IStreamSocketListenerControl;
struct IStreamSocketListenerControl2;
struct IStreamSocketListenerInformation;
struct IStreamSocketStatics;
struct IStreamWebSocket;
struct IStreamWebSocket2;
struct IStreamWebSocketControl;
struct IWebSocket;
struct IWebSocketClosedEventArgs;
struct IWebSocketControl;
struct IWebSocketControl2;
struct IWebSocketErrorStatics;
struct IWebSocketInformation;
struct IWebSocketInformation2;
struct IWebSocketServerCustomValidationRequestedEventArgs;
struct ControlChannelTrigger;
struct DatagramSocket;
struct DatagramSocketControl;
struct DatagramSocketInformation;
struct DatagramSocketMessageReceivedEventArgs;
struct MessageWebSocket;
struct MessageWebSocketControl;
struct MessageWebSocketInformation;
struct MessageWebSocketMessageReceivedEventArgs;
struct SocketActivityContext;
struct SocketActivityInformation;
struct SocketActivityTriggerDetails;
struct SocketError;
struct StreamSocket;
struct StreamSocketControl;
struct StreamSocketInformation;
struct StreamSocketListener;
struct StreamSocketListenerConnectionReceivedEventArgs;
struct StreamSocketListenerControl;
struct StreamSocketListenerInformation;
struct StreamWebSocket;
struct StreamWebSocketControl;
struct StreamWebSocketInformation;
struct WebSocketClosedEventArgs;
struct WebSocketError;
struct WebSocketKeepAlive;
struct WebSocketServerCustomValidationRequestedEventArgs;

}

namespace Windows::Networking::Sockets {

template <typename T> struct impl_IControlChannelTrigger;
template <typename T> struct impl_IControlChannelTrigger2;
template <typename T> struct impl_IControlChannelTriggerEventDetails;
template <typename T> struct impl_IControlChannelTriggerFactory;
template <typename T> struct impl_IControlChannelTriggerResetEventDetails;
template <typename T> struct impl_IDatagramSocket;
template <typename T> struct impl_IDatagramSocket2;
template <typename T> struct impl_IDatagramSocket3;
template <typename T> struct impl_IDatagramSocketControl;
template <typename T> struct impl_IDatagramSocketControl2;
template <typename T> struct impl_IDatagramSocketControl3;
template <typename T> struct impl_IDatagramSocketInformation;
template <typename T> struct impl_IDatagramSocketMessageReceivedEventArgs;
template <typename T> struct impl_IDatagramSocketStatics;
template <typename T> struct impl_IMessageWebSocket;
template <typename T> struct impl_IMessageWebSocket2;
template <typename T> struct impl_IMessageWebSocketControl;
template <typename T> struct impl_IMessageWebSocketMessageReceivedEventArgs;
template <typename T> struct impl_ISocketActivityContext;
template <typename T> struct impl_ISocketActivityContextFactory;
template <typename T> struct impl_ISocketActivityInformation;
template <typename T> struct impl_ISocketActivityInformationStatics;
template <typename T> struct impl_ISocketActivityTriggerDetails;
template <typename T> struct impl_ISocketErrorStatics;
template <typename T> struct impl_IStreamSocket;
template <typename T> struct impl_IStreamSocket2;
template <typename T> struct impl_IStreamSocket3;
template <typename T> struct impl_IStreamSocketControl;
template <typename T> struct impl_IStreamSocketControl2;
template <typename T> struct impl_IStreamSocketControl3;
template <typename T> struct impl_IStreamSocketInformation;
template <typename T> struct impl_IStreamSocketInformation2;
template <typename T> struct impl_IStreamSocketListener;
template <typename T> struct impl_IStreamSocketListener2;
template <typename T> struct impl_IStreamSocketListener3;
template <typename T> struct impl_IStreamSocketListenerConnectionReceivedEventArgs;
template <typename T> struct impl_IStreamSocketListenerControl;
template <typename T> struct impl_IStreamSocketListenerControl2;
template <typename T> struct impl_IStreamSocketListenerInformation;
template <typename T> struct impl_IStreamSocketStatics;
template <typename T> struct impl_IStreamWebSocket;
template <typename T> struct impl_IStreamWebSocket2;
template <typename T> struct impl_IStreamWebSocketControl;
template <typename T> struct impl_IWebSocket;
template <typename T> struct impl_IWebSocketClosedEventArgs;
template <typename T> struct impl_IWebSocketControl;
template <typename T> struct impl_IWebSocketControl2;
template <typename T> struct impl_IWebSocketErrorStatics;
template <typename T> struct impl_IWebSocketInformation;
template <typename T> struct impl_IWebSocketInformation2;
template <typename T> struct impl_IWebSocketServerCustomValidationRequestedEventArgs;

}

namespace Windows::Networking::Sockets {

enum class ControlChannelTriggerResetReason
{
    FastUserSwitched = 0,
    LowPowerExit = 1,
    QuietHoursExit = 2,
    ApplicationRestart = 3,
};

enum class ControlChannelTriggerResourceType
{
    RequestSoftwareSlot = 0,
    RequestHardwareSlot = 1,
};

enum class ControlChannelTriggerStatus
{
    HardwareSlotRequested = 0,
    SoftwareSlotAllocated = 1,
    HardwareSlotAllocated = 2,
    PolicyError = 3,
    SystemError = 4,
    TransportDisconnected = 5,
    ServiceUnavailable = 6,
};

enum class SocketActivityConnectedStandbyAction
{
    DoNotWake = 0,
    Wake = 1,
};

enum class SocketActivityKind
{
    None = 0,
    StreamSocketListener = 1,
    DatagramSocket = 2,
    StreamSocket = 3,
};

enum class SocketActivityTriggerReason
{
    None = 0,
    SocketActivity = 1,
    ConnectionAccepted = 2,
    KeepAliveTimerExpired = 3,
    SocketClosed = 4,
};

enum class SocketErrorStatus
{
    Unknown = 0,
    OperationAborted = 1,
    HttpInvalidServerResponse = 2,
    ConnectionTimedOut = 3,
    AddressFamilyNotSupported = 4,
    SocketTypeNotSupported = 5,
    HostNotFound = 6,
    NoDataRecordOfRequestedType = 7,
    NonAuthoritativeHostNotFound = 8,
    ClassTypeNotFound = 9,
    AddressAlreadyInUse = 10,
    CannotAssignRequestedAddress = 11,
    ConnectionRefused = 12,
    NetworkIsUnreachable = 13,
    UnreachableHost = 14,
    NetworkIsDown = 15,
    NetworkDroppedConnectionOnReset = 16,
    SoftwareCausedConnectionAbort = 17,
    ConnectionResetByPeer = 18,
    HostIsDown = 19,
    NoAddressesFound = 20,
    TooManyOpenFiles = 21,
    MessageTooLong = 22,
    CertificateExpired = 23,
    CertificateUntrustedRoot = 24,
    CertificateCommonNameIsIncorrect = 25,
    CertificateWrongUsage = 26,
    CertificateRevoked = 27,
    CertificateNoRevocationCheck = 28,
    CertificateRevocationServerOffline = 29,
    CertificateIsInvalid = 30,
};

enum class SocketMessageType
{
    Binary = 0,
    Utf8 = 1,
};

enum class SocketProtectionLevel
{
    PlainSocket = 0,
    Ssl [[deprecated("Ssl may result in insecure connections and may be altered or unavailable for releases after Windows 8.1. Instead, use one of the TLS SocketProtectionLevel values.")]] = 1,
    SslAllowNullEncryption = 2,
    BluetoothEncryptionAllowNullAuthentication = 3,
    BluetoothEncryptionWithAuthentication = 4,
    Ssl3AllowWeakEncryption [[deprecated("Ssl3AllowWeakEncryption may result in insecure connections and may be altered or unavailable for releases after Windows 8.1. Instead, use one of the TLS SocketProtectionLevel values.")]] = 5,
    Tls10 = 6,
    Tls11 = 7,
    Tls12 = 8,
};

enum class SocketQualityOfService
{
    Normal = 0,
    LowLatency = 1,
};

enum class SocketSslErrorSeverity
{
    None = 0,
    Ignorable = 1,
    Fatal = 2,
};

}

}
