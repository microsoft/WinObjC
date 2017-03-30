// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Networking.Sockets.0.h"
#include "Windows.ApplicationModel.Background.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Networking.0.h"
#include "Windows.Networking.Connectivity.0.h"
#include "Windows.Security.Credentials.0.h"
#include "Windows.Security.Cryptography.Certificates.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Web.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Networking.1.h"
#include "Windows.Foundation.1.h"
#include "Windows.Storage.Streams.1.h"
#include "Windows.Security.Cryptography.Certificates.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Networking::Sockets {

struct RoundTripTimeStatistics
{
    uint32_t Variance;
    uint32_t Max;
    uint32_t Min;
    uint32_t Sum;
};

struct BandwidthStatistics
{
    uint64_t OutboundBitsPerSecond;
    uint64_t InboundBitsPerSecond;
    uint64_t OutboundBitsPerSecondInstability;
    uint64_t InboundBitsPerSecondInstability;
    bool OutboundBandwidthPeaked;
    bool InboundBandwidthPeaked;
};

}

namespace Windows::Networking::Sockets {

using RoundTripTimeStatistics = ABI::Windows::Networking::Sockets::RoundTripTimeStatistics;
using BandwidthStatistics = ABI::Windows::Networking::Sockets::BandwidthStatistics;

}

namespace ABI::Windows::Networking::Sockets {

struct __declspec(uuid("7d1431a7-ee96-40e8-a199-8703cd969ec3")) __declspec(novtable) IControlChannelTrigger : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ControlChannelTriggerId(hstring * value) = 0;
    virtual HRESULT __stdcall get_ServerKeepAliveIntervalInMinutes(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_ServerKeepAliveIntervalInMinutes(uint32_t value) = 0;
    virtual HRESULT __stdcall get_CurrentKeepAliveIntervalInMinutes(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_TransportObject(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall get_KeepAliveTrigger(Windows::ApplicationModel::Background::IBackgroundTrigger ** trigger) = 0;
    virtual HRESULT __stdcall get_PushNotificationTrigger(Windows::ApplicationModel::Background::IBackgroundTrigger ** trigger) = 0;
    virtual HRESULT __stdcall abi_UsingTransport(Windows::Foundation::IInspectable * transport) = 0;
    virtual HRESULT __stdcall abi_WaitForPushEnabled(winrt::Windows::Networking::Sockets::ControlChannelTriggerStatus * channelTriggerStatus) = 0;
    virtual HRESULT __stdcall abi_DecreaseNetworkKeepAliveInterval() = 0;
    virtual HRESULT __stdcall abi_FlushTransport() = 0;
};

struct __declspec(uuid("af00d237-51be-4514-9725-3556e1879580")) __declspec(novtable) IControlChannelTrigger2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsWakeFromLowPowerSupported(bool * value) = 0;
};

struct __declspec(uuid("1b36e047-89bb-4236-96ac-71d012bb4869")) __declspec(novtable) IControlChannelTriggerEventDetails : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ControlChannelTrigger(Windows::Networking::Sockets::IControlChannelTrigger ** value) = 0;
};

struct __declspec(uuid("da4b7cf0-8d71-446f-88c3-b95184a2d6cd")) __declspec(novtable) IControlChannelTriggerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateControlChannelTrigger(hstring channelId, uint32_t serverKeepAliveIntervalInMinutes, Windows::Networking::Sockets::IControlChannelTrigger ** notificationChannel) = 0;
    virtual HRESULT __stdcall abi_CreateControlChannelTriggerEx(hstring channelId, uint32_t serverKeepAliveIntervalInMinutes, winrt::Windows::Networking::Sockets::ControlChannelTriggerResourceType resourceRequestType, Windows::Networking::Sockets::IControlChannelTrigger ** notificationChannel) = 0;
};

struct __declspec(uuid("6851038e-8ec4-42fe-9bb2-21e91b7bfcb1")) __declspec(novtable) IControlChannelTriggerResetEventDetails : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ResetReason(winrt::Windows::Networking::Sockets::ControlChannelTriggerResetReason * value) = 0;
    virtual HRESULT __stdcall get_HardwareSlotReset(bool * value) = 0;
    virtual HRESULT __stdcall get_SoftwareSlotReset(bool * value) = 0;
};

struct __declspec(uuid("7fe25bbb-c3bc-4677-8446-ca28a465a3af")) __declspec(novtable) IDatagramSocket : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Control(Windows::Networking::Sockets::IDatagramSocketControl ** value) = 0;
    virtual HRESULT __stdcall get_Information(Windows::Networking::Sockets::IDatagramSocketInformation ** value) = 0;
    virtual HRESULT __stdcall get_OutputStream(Windows::Storage::Streams::IOutputStream ** value) = 0;
    virtual HRESULT __stdcall abi_ConnectAsync(Windows::Networking::IHostName * remoteHostName, hstring remoteServiceName, Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_ConnectWithEndpointPairAsync(Windows::Networking::IEndpointPair * endpointPair, Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_BindServiceNameAsync(hstring localServiceName, Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_BindEndpointAsync(Windows::Networking::IHostName * localHostName, hstring localServiceName, Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_JoinMulticastGroup(Windows::Networking::IHostName * host) = 0;
    virtual HRESULT __stdcall abi_GetOutputStreamAsync(Windows::Networking::IHostName * remoteHostName, hstring remoteServiceName, Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IOutputStream> ** value) = 0;
    virtual HRESULT __stdcall abi_GetOutputStreamWithEndpointPairAsync(Windows::Networking::IEndpointPair * endpointPair, Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IOutputStream> ** value) = 0;
    virtual HRESULT __stdcall add_MessageReceived(Windows::Foundation::TypedEventHandler<Windows::Networking::Sockets::DatagramSocket, Windows::Networking::Sockets::DatagramSocketMessageReceivedEventArgs> * eventHandler, event_token * eventCookie) = 0;
    virtual HRESULT __stdcall remove_MessageReceived(event_token eventCookie) = 0;
};

struct __declspec(uuid("d83ba354-9a9d-4185-a20a-1424c9c2a7cd")) __declspec(novtable) IDatagramSocket2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_BindServiceNameAndAdapterAsync(hstring localServiceName, Windows::Networking::Connectivity::INetworkAdapter * adapter, Windows::Foundation::IAsyncAction ** operation) = 0;
};

struct __declspec(uuid("37544f09-ab92-4306-9ac1-0c381283d9c6")) __declspec(novtable) IDatagramSocket3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CancelIOAsync(Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_EnableTransferOwnership(GUID taskId) = 0;
    virtual HRESULT __stdcall abi_EnableTransferOwnershipWithConnectedStandbyAction(GUID taskId, winrt::Windows::Networking::Sockets::SocketActivityConnectedStandbyAction connectedStandbyAction) = 0;
    virtual HRESULT __stdcall abi_TransferOwnership(hstring socketId) = 0;
    virtual HRESULT __stdcall abi_TransferOwnershipWithContext(hstring socketId, Windows::Networking::Sockets::ISocketActivityContext * data) = 0;
    virtual HRESULT __stdcall abi_TransferOwnershipWithContextAndKeepAliveTime(hstring socketId, Windows::Networking::Sockets::ISocketActivityContext * data, Windows::Foundation::TimeSpan keepAliveTime) = 0;
};

struct __declspec(uuid("52ac3f2e-349a-4135-bb58-b79b2647d390")) __declspec(novtable) IDatagramSocketControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_QualityOfService(winrt::Windows::Networking::Sockets::SocketQualityOfService * value) = 0;
    virtual HRESULT __stdcall put_QualityOfService(winrt::Windows::Networking::Sockets::SocketQualityOfService value) = 0;
    virtual HRESULT __stdcall get_OutboundUnicastHopLimit(uint8_t * value) = 0;
    virtual HRESULT __stdcall put_OutboundUnicastHopLimit(uint8_t value) = 0;
};

struct __declspec(uuid("33ead5c2-979c-4415-82a1-3cfaf646c192")) __declspec(novtable) IDatagramSocketControl2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_InboundBufferSizeInBytes(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_InboundBufferSizeInBytes(uint32_t value) = 0;
    virtual HRESULT __stdcall get_DontFragment(bool * value) = 0;
    virtual HRESULT __stdcall put_DontFragment(bool value) = 0;
};

struct __declspec(uuid("d4eb8256-1f6d-4598-9b57-d42a001df349")) __declspec(novtable) IDatagramSocketControl3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MulticastOnly(bool * value) = 0;
    virtual HRESULT __stdcall put_MulticastOnly(bool value) = 0;
};

struct __declspec(uuid("5f1a569a-55fb-48cd-9706-7a974f7b1585")) __declspec(novtable) IDatagramSocketInformation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LocalAddress(Windows::Networking::IHostName ** value) = 0;
    virtual HRESULT __stdcall get_LocalPort(hstring * value) = 0;
    virtual HRESULT __stdcall get_RemoteAddress(Windows::Networking::IHostName ** value) = 0;
    virtual HRESULT __stdcall get_RemotePort(hstring * value) = 0;
};

struct __declspec(uuid("9e2ddca2-1712-4ce4-b179-8c652c6d107e")) __declspec(novtable) IDatagramSocketMessageReceivedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RemoteAddress(Windows::Networking::IHostName ** value) = 0;
    virtual HRESULT __stdcall get_RemotePort(hstring * value) = 0;
    virtual HRESULT __stdcall get_LocalAddress(Windows::Networking::IHostName ** value) = 0;
    virtual HRESULT __stdcall abi_GetDataReader(Windows::Storage::Streams::IDataReader ** dataReader) = 0;
    virtual HRESULT __stdcall abi_GetDataStream(Windows::Storage::Streams::IInputStream ** inputStream) = 0;
};

struct __declspec(uuid("e9c62aee-1494-4a21-bb7e-8589fc751d9d")) __declspec(novtable) IDatagramSocketStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetEndpointPairsAsync(Windows::Networking::IHostName * remoteHostName, hstring remoteServiceName, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::EndpointPair>> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetEndpointPairsWithSortOptionsAsync(Windows::Networking::IHostName * remoteHostName, hstring remoteServiceName, winrt::Windows::Networking::HostNameSortOptions sortOptions, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::EndpointPair>> ** operation) = 0;
};

struct __declspec(uuid("33727d08-34d5-4746-ad7b-8dde5bc2ef88")) __declspec(novtable) IMessageWebSocket : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Control(Windows::Networking::Sockets::IMessageWebSocketControl ** value) = 0;
    virtual HRESULT __stdcall get_Information(Windows::Networking::Sockets::IWebSocketInformation ** value) = 0;
    virtual HRESULT __stdcall add_MessageReceived(Windows::Foundation::TypedEventHandler<Windows::Networking::Sockets::MessageWebSocket, Windows::Networking::Sockets::MessageWebSocketMessageReceivedEventArgs> * eventHandler, event_token * eventCookie) = 0;
    virtual HRESULT __stdcall remove_MessageReceived(event_token eventCookie) = 0;
};

struct __declspec(uuid("bed0cee7-f9c8-440a-9ad5-737281d9742e")) __declspec(novtable) IMessageWebSocket2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_ServerCustomValidationRequested(Windows::Foundation::TypedEventHandler<Windows::Networking::Sockets::MessageWebSocket, Windows::Networking::Sockets::WebSocketServerCustomValidationRequestedEventArgs> * eventHandler, event_token * eventCookie) = 0;
    virtual HRESULT __stdcall remove_ServerCustomValidationRequested(event_token eventCookie) = 0;
};

struct __declspec(uuid("8118388a-c629-4f0a-80fb-81fc05538862")) __declspec(novtable) IMessageWebSocketControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MaxMessageSize(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_MaxMessageSize(uint32_t value) = 0;
    virtual HRESULT __stdcall get_MessageType(winrt::Windows::Networking::Sockets::SocketMessageType * value) = 0;
    virtual HRESULT __stdcall put_MessageType(winrt::Windows::Networking::Sockets::SocketMessageType value) = 0;
};

struct __declspec(uuid("478c22ac-4c4b-42ed-9ed7-1ef9f94fa3d5")) __declspec(novtable) IMessageWebSocketMessageReceivedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MessageType(winrt::Windows::Networking::Sockets::SocketMessageType * value) = 0;
    virtual HRESULT __stdcall abi_GetDataReader(Windows::Storage::Streams::IDataReader ** dataReader) = 0;
    virtual HRESULT __stdcall abi_GetDataStream(Windows::Storage::Streams::IInputStream ** inputStream) = 0;
};

struct __declspec(uuid("43b04d64-4c85-4396-a637-1d973f6ebd49")) __declspec(novtable) ISocketActivityContext : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Data(Windows::Storage::Streams::IBuffer ** value) = 0;
};

struct __declspec(uuid("b99fc3c3-088c-4388-83ae-2525138e049a")) __declspec(novtable) ISocketActivityContextFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Storage::Streams::IBuffer * data, Windows::Networking::Sockets::ISocketActivityContext ** context) = 0;
};

struct __declspec(uuid("8d8a42e4-a87e-4b74-9968-185b2511defe")) __declspec(novtable) ISocketActivityInformation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TaskId(GUID * value) = 0;
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall get_SocketKind(winrt::Windows::Networking::Sockets::SocketActivityKind * value) = 0;
    virtual HRESULT __stdcall get_Context(Windows::Networking::Sockets::ISocketActivityContext ** value) = 0;
    virtual HRESULT __stdcall get_DatagramSocket(Windows::Networking::Sockets::IDatagramSocket ** value) = 0;
    virtual HRESULT __stdcall get_StreamSocket(Windows::Networking::Sockets::IStreamSocket ** value) = 0;
    virtual HRESULT __stdcall get_StreamSocketListener(Windows::Networking::Sockets::IStreamSocketListener ** value) = 0;
};

struct __declspec(uuid("8570b47a-7e7d-4736-8041-1327a6543c56")) __declspec(novtable) ISocketActivityInformationStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AllSockets(Windows::Foundation::Collections::IMapView<hstring, Windows::Networking::Sockets::SocketActivityInformation> ** sockets) = 0;
};

struct __declspec(uuid("45f406a7-fc9f-4f81-acad-355fef51e67b")) __declspec(novtable) ISocketActivityTriggerDetails : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Reason(winrt::Windows::Networking::Sockets::SocketActivityTriggerReason * value) = 0;
    virtual HRESULT __stdcall get_SocketInformation(Windows::Networking::Sockets::ISocketActivityInformation ** value) = 0;
};

struct __declspec(uuid("828337f4-7d56-4d8e-b7b4-a07dd7c1bca9")) __declspec(novtable) ISocketErrorStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetStatus(int32_t hresult, winrt::Windows::Networking::Sockets::SocketErrorStatus * status) = 0;
};

struct __declspec(uuid("69a22cf3-fc7b-4857-af38-f6e7de6a5b49")) __declspec(novtable) IStreamSocket : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Control(Windows::Networking::Sockets::IStreamSocketControl ** value) = 0;
    virtual HRESULT __stdcall get_Information(Windows::Networking::Sockets::IStreamSocketInformation ** value) = 0;
    virtual HRESULT __stdcall get_InputStream(Windows::Storage::Streams::IInputStream ** value) = 0;
    virtual HRESULT __stdcall get_OutputStream(Windows::Storage::Streams::IOutputStream ** value) = 0;
    virtual HRESULT __stdcall abi_ConnectWithEndpointPairAsync(Windows::Networking::IEndpointPair * endpointPair, Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_ConnectAsync(Windows::Networking::IHostName * remoteHostName, hstring remoteServiceName, Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_ConnectWithEndpointPairAndProtectionLevelAsync(Windows::Networking::IEndpointPair * endpointPair, winrt::Windows::Networking::Sockets::SocketProtectionLevel protectionLevel, Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_ConnectWithProtectionLevelAsync(Windows::Networking::IHostName * remoteHostName, hstring remoteServiceName, winrt::Windows::Networking::Sockets::SocketProtectionLevel protectionLevel, Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_UpgradeToSslAsync(winrt::Windows::Networking::Sockets::SocketProtectionLevel protectionLevel, Windows::Networking::IHostName * validationHostName, Windows::Foundation::IAsyncAction ** operation) = 0;
};

struct __declspec(uuid("29d0e575-f314-4d09-adf0-0fbd967fbd9f")) __declspec(novtable) IStreamSocket2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ConnectWithProtectionLevelAndAdapterAsync(Windows::Networking::IHostName * remoteHostName, hstring remoteServiceName, winrt::Windows::Networking::Sockets::SocketProtectionLevel protectionLevel, Windows::Networking::Connectivity::INetworkAdapter * adapter, Windows::Foundation::IAsyncAction ** operation) = 0;
};

struct __declspec(uuid("3f430b00-9d28-4854-bac3-2301941ec223")) __declspec(novtable) IStreamSocket3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CancelIOAsync(Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_EnableTransferOwnership(GUID taskId) = 0;
    virtual HRESULT __stdcall abi_EnableTransferOwnershipWithConnectedStandbyAction(GUID taskId, winrt::Windows::Networking::Sockets::SocketActivityConnectedStandbyAction connectedStandbyAction) = 0;
    virtual HRESULT __stdcall abi_TransferOwnership(hstring socketId) = 0;
    virtual HRESULT __stdcall abi_TransferOwnershipWithContext(hstring socketId, Windows::Networking::Sockets::ISocketActivityContext * data) = 0;
    virtual HRESULT __stdcall abi_TransferOwnershipWithContextAndKeepAliveTime(hstring socketId, Windows::Networking::Sockets::ISocketActivityContext * data, Windows::Foundation::TimeSpan keepAliveTime) = 0;
};

struct __declspec(uuid("fe25adf1-92ab-4af3-9992-0f4c85e36cc4")) __declspec(novtable) IStreamSocketControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_NoDelay(bool * value) = 0;
    virtual HRESULT __stdcall put_NoDelay(bool value) = 0;
    virtual HRESULT __stdcall get_KeepAlive(bool * value) = 0;
    virtual HRESULT __stdcall put_KeepAlive(bool value) = 0;
    virtual HRESULT __stdcall get_OutboundBufferSizeInBytes(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_OutboundBufferSizeInBytes(uint32_t value) = 0;
    virtual HRESULT __stdcall get_QualityOfService(winrt::Windows::Networking::Sockets::SocketQualityOfService * value) = 0;
    virtual HRESULT __stdcall put_QualityOfService(winrt::Windows::Networking::Sockets::SocketQualityOfService value) = 0;
    virtual HRESULT __stdcall get_OutboundUnicastHopLimit(uint8_t * value) = 0;
    virtual HRESULT __stdcall put_OutboundUnicastHopLimit(uint8_t value) = 0;
};

struct __declspec(uuid("c2d09a56-060f-44c1-b8e2-1fbf60bd62c5")) __declspec(novtable) IStreamSocketControl2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IgnorableServerCertificateErrors(Windows::Foundation::Collections::IVector<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> ** value) = 0;
};

struct __declspec(uuid("c56a444c-4e74-403e-894c-b31cae5c7342")) __declspec(novtable) IStreamSocketControl3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SerializeConnectionAttempts(bool * value) = 0;
    virtual HRESULT __stdcall put_SerializeConnectionAttempts(bool value) = 0;
    virtual HRESULT __stdcall get_ClientCertificate(Windows::Security::Cryptography::Certificates::ICertificate ** value) = 0;
    virtual HRESULT __stdcall put_ClientCertificate(Windows::Security::Cryptography::Certificates::ICertificate * value) = 0;
};

struct __declspec(uuid("3b80ae30-5e68-4205-88f0-dc85d2e25ded")) __declspec(novtable) IStreamSocketInformation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LocalAddress(Windows::Networking::IHostName ** value) = 0;
    virtual HRESULT __stdcall get_LocalPort(hstring * value) = 0;
    virtual HRESULT __stdcall get_RemoteHostName(Windows::Networking::IHostName ** value) = 0;
    virtual HRESULT __stdcall get_RemoteAddress(Windows::Networking::IHostName ** value) = 0;
    virtual HRESULT __stdcall get_RemoteServiceName(hstring * value) = 0;
    virtual HRESULT __stdcall get_RemotePort(hstring * value) = 0;
    virtual HRESULT __stdcall get_RoundTripTimeStatistics(Windows::Networking::Sockets::RoundTripTimeStatistics * value) = 0;
    virtual HRESULT __stdcall get_BandwidthStatistics(Windows::Networking::Sockets::BandwidthStatistics * value) = 0;
    virtual HRESULT __stdcall get_ProtectionLevel(winrt::Windows::Networking::Sockets::SocketProtectionLevel * value) = 0;
    virtual HRESULT __stdcall get_SessionKey(Windows::Storage::Streams::IBuffer ** value) = 0;
};

struct __declspec(uuid("12c28452-4bdc-4ee4-976a-cf130e9d92e3")) __declspec(novtable) IStreamSocketInformation2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ServerCertificateErrorSeverity(winrt::Windows::Networking::Sockets::SocketSslErrorSeverity * value) = 0;
    virtual HRESULT __stdcall get_ServerCertificateErrors(Windows::Foundation::Collections::IVectorView<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> ** value) = 0;
    virtual HRESULT __stdcall get_ServerCertificate(Windows::Security::Cryptography::Certificates::ICertificate ** value) = 0;
    virtual HRESULT __stdcall get_ServerIntermediateCertificates(Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> ** value) = 0;
};

struct __declspec(uuid("ff513437-df9f-4df0-bf82-0ec5d7b35aae")) __declspec(novtable) IStreamSocketListener : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Control(Windows::Networking::Sockets::IStreamSocketListenerControl ** value) = 0;
    virtual HRESULT __stdcall get_Information(Windows::Networking::Sockets::IStreamSocketListenerInformation ** value) = 0;
    virtual HRESULT __stdcall abi_BindServiceNameAsync(hstring localServiceName, Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_BindEndpointAsync(Windows::Networking::IHostName * localHostName, hstring localServiceName, Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall add_ConnectionReceived(Windows::Foundation::TypedEventHandler<Windows::Networking::Sockets::StreamSocketListener, Windows::Networking::Sockets::StreamSocketListenerConnectionReceivedEventArgs> * eventHandler, event_token * eventCookie) = 0;
    virtual HRESULT __stdcall remove_ConnectionReceived(event_token eventCookie) = 0;
};

struct __declspec(uuid("658dc13e-bb3e-4458-b232-ed1088694b98")) __declspec(novtable) IStreamSocketListener2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_BindServiceNameWithProtectionLevelAsync(hstring localServiceName, winrt::Windows::Networking::Sockets::SocketProtectionLevel protectionLevel, Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_BindServiceNameWithProtectionLevelAndAdapterAsync(hstring localServiceName, winrt::Windows::Networking::Sockets::SocketProtectionLevel protectionLevel, Windows::Networking::Connectivity::INetworkAdapter * adapter, Windows::Foundation::IAsyncAction ** operation) = 0;
};

struct __declspec(uuid("4798201c-bdf8-4919-8542-28d450e74507")) __declspec(novtable) IStreamSocketListener3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CancelIOAsync(Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_EnableTransferOwnership(GUID taskId) = 0;
    virtual HRESULT __stdcall abi_EnableTransferOwnershipWithConnectedStandbyAction(GUID taskId, winrt::Windows::Networking::Sockets::SocketActivityConnectedStandbyAction connectedStandbyAction) = 0;
    virtual HRESULT __stdcall abi_TransferOwnership(hstring socketId) = 0;
    virtual HRESULT __stdcall abi_TransferOwnershipWithContext(hstring socketId, Windows::Networking::Sockets::ISocketActivityContext * data) = 0;
};

struct __declspec(uuid("0c472ea9-373f-447b-85b1-ddd4548803ba")) __declspec(novtable) IStreamSocketListenerConnectionReceivedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Socket(Windows::Networking::Sockets::IStreamSocket ** value) = 0;
};

struct __declspec(uuid("20d8c576-8d8a-4dba-9722-a16c4d984980")) __declspec(novtable) IStreamSocketListenerControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_QualityOfService(winrt::Windows::Networking::Sockets::SocketQualityOfService * value) = 0;
    virtual HRESULT __stdcall put_QualityOfService(winrt::Windows::Networking::Sockets::SocketQualityOfService value) = 0;
};

struct __declspec(uuid("948bb665-2c3e-404b-b8b0-8eb249a2b0a1")) __declspec(novtable) IStreamSocketListenerControl2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_NoDelay(bool * value) = 0;
    virtual HRESULT __stdcall put_NoDelay(bool value) = 0;
    virtual HRESULT __stdcall get_KeepAlive(bool * value) = 0;
    virtual HRESULT __stdcall put_KeepAlive(bool value) = 0;
    virtual HRESULT __stdcall get_OutboundBufferSizeInBytes(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_OutboundBufferSizeInBytes(uint32_t value) = 0;
    virtual HRESULT __stdcall get_OutboundUnicastHopLimit(uint8_t * value) = 0;
    virtual HRESULT __stdcall put_OutboundUnicastHopLimit(uint8_t value) = 0;
};

struct __declspec(uuid("e62ba82f-a63a-430b-bf62-29e93e5633b4")) __declspec(novtable) IStreamSocketListenerInformation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LocalPort(hstring * value) = 0;
};

struct __declspec(uuid("a420bc4a-6e2e-4af5-b556-355ae0cd4f29")) __declspec(novtable) IStreamSocketStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetEndpointPairsAsync(Windows::Networking::IHostName * remoteHostName, hstring remoteServiceName, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::EndpointPair>> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetEndpointPairsWithSortOptionsAsync(Windows::Networking::IHostName * remoteHostName, hstring remoteServiceName, winrt::Windows::Networking::HostNameSortOptions sortOptions, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::EndpointPair>> ** operation) = 0;
};

struct __declspec(uuid("bd4a49d8-b289-45bb-97eb-c7525205a843")) __declspec(novtable) IStreamWebSocket : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Control(Windows::Networking::Sockets::IStreamWebSocketControl ** value) = 0;
    virtual HRESULT __stdcall get_Information(Windows::Networking::Sockets::IWebSocketInformation ** value) = 0;
    virtual HRESULT __stdcall get_InputStream(Windows::Storage::Streams::IInputStream ** value) = 0;
};

struct __declspec(uuid("aa4d08cb-93f5-4678-8236-57cce5417ed5")) __declspec(novtable) IStreamWebSocket2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_ServerCustomValidationRequested(Windows::Foundation::TypedEventHandler<Windows::Networking::Sockets::StreamWebSocket, Windows::Networking::Sockets::WebSocketServerCustomValidationRequestedEventArgs> * eventHandler, event_token * eventCookie) = 0;
    virtual HRESULT __stdcall remove_ServerCustomValidationRequested(event_token eventCookie) = 0;
};

struct __declspec(uuid("b4f478b1-a45a-48db-953a-645b7d964c07")) __declspec(novtable) IStreamWebSocketControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_NoDelay(bool * value) = 0;
    virtual HRESULT __stdcall put_NoDelay(bool value) = 0;
};

struct __declspec(uuid("f877396f-99b1-4e18-bc08-850c9adf156e")) __declspec(novtable) IWebSocket : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_OutputStream(Windows::Storage::Streams::IOutputStream ** value) = 0;
    virtual HRESULT __stdcall abi_ConnectAsync(Windows::Foundation::IUriRuntimeClass * uri, Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_SetRequestHeader(hstring headerName, hstring headerValue) = 0;
    virtual HRESULT __stdcall add_Closed(Windows::Foundation::TypedEventHandler<Windows::Networking::Sockets::IWebSocket, Windows::Networking::Sockets::WebSocketClosedEventArgs> * eventHandler, event_token * eventCookie) = 0;
    virtual HRESULT __stdcall remove_Closed(event_token eventCookie) = 0;
    virtual HRESULT __stdcall abi_CloseWithStatus(uint16_t code, hstring reason) = 0;
};

struct __declspec(uuid("ceb78d07-d0a8-4703-a091-c8c2c0915bc3")) __declspec(novtable) IWebSocketClosedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Code(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_Reason(hstring * value) = 0;
};

struct __declspec(uuid("2ec4bdc3-d9a5-455a-9811-de24d45337e9")) __declspec(novtable) IWebSocketControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_OutboundBufferSizeInBytes(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_OutboundBufferSizeInBytes(uint32_t value) = 0;
    virtual HRESULT __stdcall get_ServerCredential(Windows::Security::Credentials::IPasswordCredential ** value) = 0;
    virtual HRESULT __stdcall put_ServerCredential(Windows::Security::Credentials::IPasswordCredential * value) = 0;
    virtual HRESULT __stdcall get_ProxyCredential(Windows::Security::Credentials::IPasswordCredential ** value) = 0;
    virtual HRESULT __stdcall put_ProxyCredential(Windows::Security::Credentials::IPasswordCredential * value) = 0;
    virtual HRESULT __stdcall get_SupportedProtocols(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
};

struct __declspec(uuid("79c3be03-f2ca-461e-af4e-9665bc2d0620")) __declspec(novtable) IWebSocketControl2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IgnorableServerCertificateErrors(Windows::Foundation::Collections::IVector<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> ** value) = 0;
};

struct __declspec(uuid("27cdf35b-1f61-4709-8e02-61283ada4e9d")) __declspec(novtable) IWebSocketErrorStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetStatus(int32_t hresult, winrt::Windows::Web::WebErrorStatus * status) = 0;
};

struct __declspec(uuid("5e01e316-c92a-47a5-b25f-07847639d181")) __declspec(novtable) IWebSocketInformation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LocalAddress(Windows::Networking::IHostName ** value) = 0;
    virtual HRESULT __stdcall get_BandwidthStatistics(Windows::Networking::Sockets::BandwidthStatistics * value) = 0;
    virtual HRESULT __stdcall get_Protocol(hstring * value) = 0;
};

struct __declspec(uuid("ce1d39ce-a1b7-4d43-8269-8d5b981bd47a")) __declspec(novtable) IWebSocketInformation2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ServerCertificate(Windows::Security::Cryptography::Certificates::ICertificate ** value) = 0;
    virtual HRESULT __stdcall get_ServerCertificateErrorSeverity(winrt::Windows::Networking::Sockets::SocketSslErrorSeverity * value) = 0;
    virtual HRESULT __stdcall get_ServerCertificateErrors(Windows::Foundation::Collections::IVectorView<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> ** value) = 0;
    virtual HRESULT __stdcall get_ServerIntermediateCertificates(Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> ** value) = 0;
};

struct __declspec(uuid("ffeffe48-022a-4ab7-8b36-e10af4640e6b")) __declspec(novtable) IWebSocketServerCustomValidationRequestedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ServerCertificate(Windows::Security::Cryptography::Certificates::ICertificate ** value) = 0;
    virtual HRESULT __stdcall get_ServerCertificateErrorSeverity(winrt::Windows::Networking::Sockets::SocketSslErrorSeverity * value) = 0;
    virtual HRESULT __stdcall get_ServerCertificateErrors(Windows::Foundation::Collections::IVectorView<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> ** value) = 0;
    virtual HRESULT __stdcall get_ServerIntermediateCertificates(Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> ** value) = 0;
    virtual HRESULT __stdcall abi_Reject() = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** result) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Networking::Sockets::ControlChannelTrigger> { using default_interface = Windows::Networking::Sockets::IControlChannelTrigger; };
template <> struct traits<Windows::Networking::Sockets::DatagramSocket> { using default_interface = Windows::Networking::Sockets::IDatagramSocket; };
template <> struct traits<Windows::Networking::Sockets::DatagramSocketControl> { using default_interface = Windows::Networking::Sockets::IDatagramSocketControl; };
template <> struct traits<Windows::Networking::Sockets::DatagramSocketInformation> { using default_interface = Windows::Networking::Sockets::IDatagramSocketInformation; };
template <> struct traits<Windows::Networking::Sockets::DatagramSocketMessageReceivedEventArgs> { using default_interface = Windows::Networking::Sockets::IDatagramSocketMessageReceivedEventArgs; };
template <> struct traits<Windows::Networking::Sockets::MessageWebSocket> { using default_interface = Windows::Networking::Sockets::IMessageWebSocket; };
template <> struct traits<Windows::Networking::Sockets::MessageWebSocketControl> { using default_interface = Windows::Networking::Sockets::IMessageWebSocketControl; };
template <> struct traits<Windows::Networking::Sockets::MessageWebSocketInformation> { using default_interface = Windows::Networking::Sockets::IWebSocketInformation; };
template <> struct traits<Windows::Networking::Sockets::MessageWebSocketMessageReceivedEventArgs> { using default_interface = Windows::Networking::Sockets::IMessageWebSocketMessageReceivedEventArgs; };
template <> struct traits<Windows::Networking::Sockets::SocketActivityContext> { using default_interface = Windows::Networking::Sockets::ISocketActivityContext; };
template <> struct traits<Windows::Networking::Sockets::SocketActivityInformation> { using default_interface = Windows::Networking::Sockets::ISocketActivityInformation; };
template <> struct traits<Windows::Networking::Sockets::SocketActivityTriggerDetails> { using default_interface = Windows::Networking::Sockets::ISocketActivityTriggerDetails; };
template <> struct traits<Windows::Networking::Sockets::StreamSocket> { using default_interface = Windows::Networking::Sockets::IStreamSocket; };
template <> struct traits<Windows::Networking::Sockets::StreamSocketControl> { using default_interface = Windows::Networking::Sockets::IStreamSocketControl; };
template <> struct traits<Windows::Networking::Sockets::StreamSocketInformation> { using default_interface = Windows::Networking::Sockets::IStreamSocketInformation; };
template <> struct traits<Windows::Networking::Sockets::StreamSocketListener> { using default_interface = Windows::Networking::Sockets::IStreamSocketListener; };
template <> struct traits<Windows::Networking::Sockets::StreamSocketListenerConnectionReceivedEventArgs> { using default_interface = Windows::Networking::Sockets::IStreamSocketListenerConnectionReceivedEventArgs; };
template <> struct traits<Windows::Networking::Sockets::StreamSocketListenerControl> { using default_interface = Windows::Networking::Sockets::IStreamSocketListenerControl; };
template <> struct traits<Windows::Networking::Sockets::StreamSocketListenerInformation> { using default_interface = Windows::Networking::Sockets::IStreamSocketListenerInformation; };
template <> struct traits<Windows::Networking::Sockets::StreamWebSocket> { using default_interface = Windows::Networking::Sockets::IStreamWebSocket; };
template <> struct traits<Windows::Networking::Sockets::StreamWebSocketControl> { using default_interface = Windows::Networking::Sockets::IStreamWebSocketControl; };
template <> struct traits<Windows::Networking::Sockets::StreamWebSocketInformation> { using default_interface = Windows::Networking::Sockets::IWebSocketInformation; };
template <> struct traits<Windows::Networking::Sockets::WebSocketClosedEventArgs> { using default_interface = Windows::Networking::Sockets::IWebSocketClosedEventArgs; };
template <> struct traits<Windows::Networking::Sockets::WebSocketKeepAlive> { using default_interface = Windows::ApplicationModel::Background::IBackgroundTask; };
template <> struct traits<Windows::Networking::Sockets::WebSocketServerCustomValidationRequestedEventArgs> { using default_interface = Windows::Networking::Sockets::IWebSocketServerCustomValidationRequestedEventArgs; };

}

namespace Windows::Networking::Sockets {

template <typename D>
struct WINRT_EBO impl_IControlChannelTrigger
{
    hstring ControlChannelTriggerId() const;
    uint32_t ServerKeepAliveIntervalInMinutes() const;
    void ServerKeepAliveIntervalInMinutes(uint32_t value) const;
    uint32_t CurrentKeepAliveIntervalInMinutes() const;
    Windows::Foundation::IInspectable TransportObject() const;
    Windows::ApplicationModel::Background::IBackgroundTrigger KeepAliveTrigger() const;
    Windows::ApplicationModel::Background::IBackgroundTrigger PushNotificationTrigger() const;
    void UsingTransport(const Windows::Foundation::IInspectable & transport) const;
    Windows::Networking::Sockets::ControlChannelTriggerStatus WaitForPushEnabled() const;
    void DecreaseNetworkKeepAliveInterval() const;
    void FlushTransport() const;
};

template <typename D>
struct WINRT_EBO impl_IControlChannelTrigger2
{
    bool IsWakeFromLowPowerSupported() const;
};

template <typename D>
struct WINRT_EBO impl_IControlChannelTriggerEventDetails
{
    Windows::Networking::Sockets::ControlChannelTrigger ControlChannelTrigger() const;
};

template <typename D>
struct WINRT_EBO impl_IControlChannelTriggerFactory
{
    Windows::Networking::Sockets::ControlChannelTrigger CreateControlChannelTrigger(hstring_view channelId, uint32_t serverKeepAliveIntervalInMinutes) const;
    Windows::Networking::Sockets::ControlChannelTrigger CreateControlChannelTriggerEx(hstring_view channelId, uint32_t serverKeepAliveIntervalInMinutes, Windows::Networking::Sockets::ControlChannelTriggerResourceType resourceRequestType) const;
};

template <typename D>
struct WINRT_EBO impl_IControlChannelTriggerResetEventDetails
{
    Windows::Networking::Sockets::ControlChannelTriggerResetReason ResetReason() const;
    bool HardwareSlotReset() const;
    bool SoftwareSlotReset() const;
};

template <typename D>
struct WINRT_EBO impl_IDatagramSocket
{
    Windows::Networking::Sockets::DatagramSocketControl Control() const;
    Windows::Networking::Sockets::DatagramSocketInformation Information() const;
    Windows::Storage::Streams::IOutputStream OutputStream() const;
    Windows::Foundation::IAsyncAction ConnectAsync(const Windows::Networking::HostName & remoteHostName, hstring_view remoteServiceName) const;
    Windows::Foundation::IAsyncAction ConnectAsync(const Windows::Networking::EndpointPair & endpointPair) const;
    Windows::Foundation::IAsyncAction BindServiceNameAsync(hstring_view localServiceName) const;
    Windows::Foundation::IAsyncAction BindEndpointAsync(const Windows::Networking::HostName & localHostName, hstring_view localServiceName) const;
    void JoinMulticastGroup(const Windows::Networking::HostName & host) const;
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IOutputStream> GetOutputStreamAsync(const Windows::Networking::HostName & remoteHostName, hstring_view remoteServiceName) const;
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IOutputStream> GetOutputStreamAsync(const Windows::Networking::EndpointPair & endpointPair) const;
    event_token MessageReceived(const Windows::Foundation::TypedEventHandler<Windows::Networking::Sockets::DatagramSocket, Windows::Networking::Sockets::DatagramSocketMessageReceivedEventArgs> & eventHandler) const;
    using MessageReceived_revoker = event_revoker<IDatagramSocket>;
    MessageReceived_revoker MessageReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Networking::Sockets::DatagramSocket, Windows::Networking::Sockets::DatagramSocketMessageReceivedEventArgs> & eventHandler) const;
    void MessageReceived(event_token eventCookie) const;
};

template <typename D>
struct WINRT_EBO impl_IDatagramSocket2
{
    Windows::Foundation::IAsyncAction BindServiceNameAsync(hstring_view localServiceName, const Windows::Networking::Connectivity::NetworkAdapter & adapter) const;
};

template <typename D>
struct WINRT_EBO impl_IDatagramSocket3
{
    Windows::Foundation::IAsyncAction CancelIOAsync() const;
    void EnableTransferOwnership(GUID taskId) const;
    void EnableTransferOwnership(GUID taskId, Windows::Networking::Sockets::SocketActivityConnectedStandbyAction connectedStandbyAction) const;
    void TransferOwnership(hstring_view socketId) const;
    void TransferOwnership(hstring_view socketId, const Windows::Networking::Sockets::SocketActivityContext & data) const;
    void TransferOwnership(hstring_view socketId, const Windows::Networking::Sockets::SocketActivityContext & data, const Windows::Foundation::TimeSpan & keepAliveTime) const;
};

template <typename D>
struct WINRT_EBO impl_IDatagramSocketControl
{
    Windows::Networking::Sockets::SocketQualityOfService QualityOfService() const;
    void QualityOfService(Windows::Networking::Sockets::SocketQualityOfService value) const;
    uint8_t OutboundUnicastHopLimit() const;
    void OutboundUnicastHopLimit(uint8_t value) const;
};

template <typename D>
struct WINRT_EBO impl_IDatagramSocketControl2
{
    uint32_t InboundBufferSizeInBytes() const;
    void InboundBufferSizeInBytes(uint32_t value) const;
    bool DontFragment() const;
    void DontFragment(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IDatagramSocketControl3
{
    bool MulticastOnly() const;
    void MulticastOnly(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IDatagramSocketInformation
{
    Windows::Networking::HostName LocalAddress() const;
    hstring LocalPort() const;
    Windows::Networking::HostName RemoteAddress() const;
    hstring RemotePort() const;
};

template <typename D>
struct WINRT_EBO impl_IDatagramSocketMessageReceivedEventArgs
{
    Windows::Networking::HostName RemoteAddress() const;
    hstring RemotePort() const;
    Windows::Networking::HostName LocalAddress() const;
    Windows::Storage::Streams::DataReader GetDataReader() const;
    Windows::Storage::Streams::IInputStream GetDataStream() const;
};

template <typename D>
struct WINRT_EBO impl_IDatagramSocketStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::EndpointPair>> GetEndpointPairsAsync(const Windows::Networking::HostName & remoteHostName, hstring_view remoteServiceName) const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::EndpointPair>> GetEndpointPairsAsync(const Windows::Networking::HostName & remoteHostName, hstring_view remoteServiceName, Windows::Networking::HostNameSortOptions sortOptions) const;
};

template <typename D>
struct WINRT_EBO impl_IMessageWebSocket
{
    Windows::Networking::Sockets::MessageWebSocketControl Control() const;
    Windows::Networking::Sockets::MessageWebSocketInformation Information() const;
    event_token MessageReceived(const Windows::Foundation::TypedEventHandler<Windows::Networking::Sockets::MessageWebSocket, Windows::Networking::Sockets::MessageWebSocketMessageReceivedEventArgs> & eventHandler) const;
    using MessageReceived_revoker = event_revoker<IMessageWebSocket>;
    MessageReceived_revoker MessageReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Networking::Sockets::MessageWebSocket, Windows::Networking::Sockets::MessageWebSocketMessageReceivedEventArgs> & eventHandler) const;
    void MessageReceived(event_token eventCookie) const;
};

template <typename D>
struct WINRT_EBO impl_IMessageWebSocket2
{
    event_token ServerCustomValidationRequested(const Windows::Foundation::TypedEventHandler<Windows::Networking::Sockets::MessageWebSocket, Windows::Networking::Sockets::WebSocketServerCustomValidationRequestedEventArgs> & eventHandler) const;
    using ServerCustomValidationRequested_revoker = event_revoker<IMessageWebSocket2>;
    ServerCustomValidationRequested_revoker ServerCustomValidationRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Networking::Sockets::MessageWebSocket, Windows::Networking::Sockets::WebSocketServerCustomValidationRequestedEventArgs> & eventHandler) const;
    void ServerCustomValidationRequested(event_token eventCookie) const;
};

template <typename D>
struct WINRT_EBO impl_IMessageWebSocketControl
{
    uint32_t MaxMessageSize() const;
    void MaxMessageSize(uint32_t value) const;
    Windows::Networking::Sockets::SocketMessageType MessageType() const;
    void MessageType(Windows::Networking::Sockets::SocketMessageType value) const;
};

template <typename D>
struct WINRT_EBO impl_IMessageWebSocketMessageReceivedEventArgs
{
    Windows::Networking::Sockets::SocketMessageType MessageType() const;
    Windows::Storage::Streams::DataReader GetDataReader() const;
    Windows::Storage::Streams::IInputStream GetDataStream() const;
};

template <typename D>
struct WINRT_EBO impl_ISocketActivityContext
{
    Windows::Storage::Streams::IBuffer Data() const;
};

template <typename D>
struct WINRT_EBO impl_ISocketActivityContextFactory
{
    Windows::Networking::Sockets::SocketActivityContext Create(const Windows::Storage::Streams::IBuffer & data) const;
};

template <typename D>
struct WINRT_EBO impl_ISocketActivityInformation
{
    GUID TaskId() const;
    hstring Id() const;
    Windows::Networking::Sockets::SocketActivityKind SocketKind() const;
    Windows::Networking::Sockets::SocketActivityContext Context() const;
    Windows::Networking::Sockets::DatagramSocket DatagramSocket() const;
    Windows::Networking::Sockets::StreamSocket StreamSocket() const;
    Windows::Networking::Sockets::StreamSocketListener StreamSocketListener() const;
};

template <typename D>
struct WINRT_EBO impl_ISocketActivityInformationStatics
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::Networking::Sockets::SocketActivityInformation> AllSockets() const;
};

template <typename D>
struct WINRT_EBO impl_ISocketActivityTriggerDetails
{
    Windows::Networking::Sockets::SocketActivityTriggerReason Reason() const;
    Windows::Networking::Sockets::SocketActivityInformation SocketInformation() const;
};

template <typename D>
struct WINRT_EBO impl_ISocketErrorStatics
{
    Windows::Networking::Sockets::SocketErrorStatus GetStatus(int32_t hresult) const;
};

template <typename D>
struct WINRT_EBO impl_IStreamSocket
{
    Windows::Networking::Sockets::StreamSocketControl Control() const;
    Windows::Networking::Sockets::StreamSocketInformation Information() const;
    Windows::Storage::Streams::IInputStream InputStream() const;
    Windows::Storage::Streams::IOutputStream OutputStream() const;
    Windows::Foundation::IAsyncAction ConnectAsync(const Windows::Networking::EndpointPair & endpointPair) const;
    Windows::Foundation::IAsyncAction ConnectAsync(const Windows::Networking::HostName & remoteHostName, hstring_view remoteServiceName) const;
    Windows::Foundation::IAsyncAction ConnectAsync(const Windows::Networking::EndpointPair & endpointPair, Windows::Networking::Sockets::SocketProtectionLevel protectionLevel) const;
    Windows::Foundation::IAsyncAction ConnectAsync(const Windows::Networking::HostName & remoteHostName, hstring_view remoteServiceName, Windows::Networking::Sockets::SocketProtectionLevel protectionLevel) const;
    Windows::Foundation::IAsyncAction UpgradeToSslAsync(Windows::Networking::Sockets::SocketProtectionLevel protectionLevel, const Windows::Networking::HostName & validationHostName) const;
};

template <typename D>
struct WINRT_EBO impl_IStreamSocket2
{
    Windows::Foundation::IAsyncAction ConnectAsync(const Windows::Networking::HostName & remoteHostName, hstring_view remoteServiceName, Windows::Networking::Sockets::SocketProtectionLevel protectionLevel, const Windows::Networking::Connectivity::NetworkAdapter & adapter) const;
};

template <typename D>
struct WINRT_EBO impl_IStreamSocket3
{
    Windows::Foundation::IAsyncAction CancelIOAsync() const;
    void EnableTransferOwnership(GUID taskId) const;
    void EnableTransferOwnership(GUID taskId, Windows::Networking::Sockets::SocketActivityConnectedStandbyAction connectedStandbyAction) const;
    void TransferOwnership(hstring_view socketId) const;
    void TransferOwnership(hstring_view socketId, const Windows::Networking::Sockets::SocketActivityContext & data) const;
    void TransferOwnership(hstring_view socketId, const Windows::Networking::Sockets::SocketActivityContext & data, const Windows::Foundation::TimeSpan & keepAliveTime) const;
};

template <typename D>
struct WINRT_EBO impl_IStreamSocketControl
{
    bool NoDelay() const;
    void NoDelay(bool value) const;
    bool KeepAlive() const;
    void KeepAlive(bool value) const;
    uint32_t OutboundBufferSizeInBytes() const;
    void OutboundBufferSizeInBytes(uint32_t value) const;
    Windows::Networking::Sockets::SocketQualityOfService QualityOfService() const;
    void QualityOfService(Windows::Networking::Sockets::SocketQualityOfService value) const;
    uint8_t OutboundUnicastHopLimit() const;
    void OutboundUnicastHopLimit(uint8_t value) const;
};

template <typename D>
struct WINRT_EBO impl_IStreamSocketControl2
{
    Windows::Foundation::Collections::IVector<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> IgnorableServerCertificateErrors() const;
};

template <typename D>
struct WINRT_EBO impl_IStreamSocketControl3
{
    bool SerializeConnectionAttempts() const;
    void SerializeConnectionAttempts(bool value) const;
    Windows::Security::Cryptography::Certificates::Certificate ClientCertificate() const;
    void ClientCertificate(const Windows::Security::Cryptography::Certificates::Certificate & value) const;
};

template <typename D>
struct WINRT_EBO impl_IStreamSocketInformation
{
    Windows::Networking::HostName LocalAddress() const;
    hstring LocalPort() const;
    Windows::Networking::HostName RemoteHostName() const;
    Windows::Networking::HostName RemoteAddress() const;
    hstring RemoteServiceName() const;
    hstring RemotePort() const;
    Windows::Networking::Sockets::RoundTripTimeStatistics RoundTripTimeStatistics() const;
    Windows::Networking::Sockets::BandwidthStatistics BandwidthStatistics() const;
    Windows::Networking::Sockets::SocketProtectionLevel ProtectionLevel() const;
    Windows::Storage::Streams::IBuffer SessionKey() const;
};

template <typename D>
struct WINRT_EBO impl_IStreamSocketInformation2
{
    Windows::Networking::Sockets::SocketSslErrorSeverity ServerCertificateErrorSeverity() const;
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> ServerCertificateErrors() const;
    Windows::Security::Cryptography::Certificates::Certificate ServerCertificate() const;
    Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> ServerIntermediateCertificates() const;
};

template <typename D>
struct WINRT_EBO impl_IStreamSocketListener
{
    Windows::Networking::Sockets::StreamSocketListenerControl Control() const;
    Windows::Networking::Sockets::StreamSocketListenerInformation Information() const;
    Windows::Foundation::IAsyncAction BindServiceNameAsync(hstring_view localServiceName) const;
    Windows::Foundation::IAsyncAction BindEndpointAsync(const Windows::Networking::HostName & localHostName, hstring_view localServiceName) const;
    event_token ConnectionReceived(const Windows::Foundation::TypedEventHandler<Windows::Networking::Sockets::StreamSocketListener, Windows::Networking::Sockets::StreamSocketListenerConnectionReceivedEventArgs> & eventHandler) const;
    using ConnectionReceived_revoker = event_revoker<IStreamSocketListener>;
    ConnectionReceived_revoker ConnectionReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Networking::Sockets::StreamSocketListener, Windows::Networking::Sockets::StreamSocketListenerConnectionReceivedEventArgs> & eventHandler) const;
    void ConnectionReceived(event_token eventCookie) const;
};

template <typename D>
struct WINRT_EBO impl_IStreamSocketListener2
{
    Windows::Foundation::IAsyncAction BindServiceNameAsync(hstring_view localServiceName, Windows::Networking::Sockets::SocketProtectionLevel protectionLevel) const;
    Windows::Foundation::IAsyncAction BindServiceNameAsync(hstring_view localServiceName, Windows::Networking::Sockets::SocketProtectionLevel protectionLevel, const Windows::Networking::Connectivity::NetworkAdapter & adapter) const;
};

template <typename D>
struct WINRT_EBO impl_IStreamSocketListener3
{
    Windows::Foundation::IAsyncAction CancelIOAsync() const;
    void EnableTransferOwnership(GUID taskId) const;
    void EnableTransferOwnership(GUID taskId, Windows::Networking::Sockets::SocketActivityConnectedStandbyAction connectedStandbyAction) const;
    void TransferOwnership(hstring_view socketId) const;
    void TransferOwnership(hstring_view socketId, const Windows::Networking::Sockets::SocketActivityContext & data) const;
};

template <typename D>
struct WINRT_EBO impl_IStreamSocketListenerConnectionReceivedEventArgs
{
    Windows::Networking::Sockets::StreamSocket Socket() const;
};

template <typename D>
struct WINRT_EBO impl_IStreamSocketListenerControl
{
    Windows::Networking::Sockets::SocketQualityOfService QualityOfService() const;
    void QualityOfService(Windows::Networking::Sockets::SocketQualityOfService value) const;
};

template <typename D>
struct WINRT_EBO impl_IStreamSocketListenerControl2
{
    bool NoDelay() const;
    void NoDelay(bool value) const;
    bool KeepAlive() const;
    void KeepAlive(bool value) const;
    uint32_t OutboundBufferSizeInBytes() const;
    void OutboundBufferSizeInBytes(uint32_t value) const;
    uint8_t OutboundUnicastHopLimit() const;
    void OutboundUnicastHopLimit(uint8_t value) const;
};

template <typename D>
struct WINRT_EBO impl_IStreamSocketListenerInformation
{
    hstring LocalPort() const;
};

template <typename D>
struct WINRT_EBO impl_IStreamSocketStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::EndpointPair>> GetEndpointPairsAsync(const Windows::Networking::HostName & remoteHostName, hstring_view remoteServiceName) const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::EndpointPair>> GetEndpointPairsAsync(const Windows::Networking::HostName & remoteHostName, hstring_view remoteServiceName, Windows::Networking::HostNameSortOptions sortOptions) const;
};

template <typename D>
struct WINRT_EBO impl_IStreamWebSocket
{
    Windows::Networking::Sockets::StreamWebSocketControl Control() const;
    Windows::Networking::Sockets::StreamWebSocketInformation Information() const;
    Windows::Storage::Streams::IInputStream InputStream() const;
};

template <typename D>
struct WINRT_EBO impl_IStreamWebSocket2
{
    event_token ServerCustomValidationRequested(const Windows::Foundation::TypedEventHandler<Windows::Networking::Sockets::StreamWebSocket, Windows::Networking::Sockets::WebSocketServerCustomValidationRequestedEventArgs> & eventHandler) const;
    using ServerCustomValidationRequested_revoker = event_revoker<IStreamWebSocket2>;
    ServerCustomValidationRequested_revoker ServerCustomValidationRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Networking::Sockets::StreamWebSocket, Windows::Networking::Sockets::WebSocketServerCustomValidationRequestedEventArgs> & eventHandler) const;
    void ServerCustomValidationRequested(event_token eventCookie) const;
};

template <typename D>
struct WINRT_EBO impl_IStreamWebSocketControl
{
    bool NoDelay() const;
    void NoDelay(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IWebSocket
{
    Windows::Storage::Streams::IOutputStream OutputStream() const;
    Windows::Foundation::IAsyncAction ConnectAsync(const Windows::Foundation::Uri & uri) const;
    void SetRequestHeader(hstring_view headerName, hstring_view headerValue) const;
    event_token Closed(const Windows::Foundation::TypedEventHandler<Windows::Networking::Sockets::IWebSocket, Windows::Networking::Sockets::WebSocketClosedEventArgs> & eventHandler) const;
    using Closed_revoker = event_revoker<IWebSocket>;
    Closed_revoker Closed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Networking::Sockets::IWebSocket, Windows::Networking::Sockets::WebSocketClosedEventArgs> & eventHandler) const;
    void Closed(event_token eventCookie) const;
    void Close(uint16_t code, hstring_view reason) const;
};

template <typename D>
struct WINRT_EBO impl_IWebSocketClosedEventArgs
{
    uint16_t Code() const;
    hstring Reason() const;
};

template <typename D>
struct WINRT_EBO impl_IWebSocketControl
{
    uint32_t OutboundBufferSizeInBytes() const;
    void OutboundBufferSizeInBytes(uint32_t value) const;
    Windows::Security::Credentials::PasswordCredential ServerCredential() const;
    void ServerCredential(const Windows::Security::Credentials::PasswordCredential & value) const;
    Windows::Security::Credentials::PasswordCredential ProxyCredential() const;
    void ProxyCredential(const Windows::Security::Credentials::PasswordCredential & value) const;
    Windows::Foundation::Collections::IVector<hstring> SupportedProtocols() const;
};

template <typename D>
struct WINRT_EBO impl_IWebSocketControl2
{
    Windows::Foundation::Collections::IVector<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> IgnorableServerCertificateErrors() const;
};

template <typename D>
struct WINRT_EBO impl_IWebSocketErrorStatics
{
    Windows::Web::WebErrorStatus GetStatus(int32_t hresult) const;
};

template <typename D>
struct WINRT_EBO impl_IWebSocketInformation
{
    Windows::Networking::HostName LocalAddress() const;
    Windows::Networking::Sockets::BandwidthStatistics BandwidthStatistics() const;
    hstring Protocol() const;
};

template <typename D>
struct WINRT_EBO impl_IWebSocketInformation2
{
    Windows::Security::Cryptography::Certificates::Certificate ServerCertificate() const;
    Windows::Networking::Sockets::SocketSslErrorSeverity ServerCertificateErrorSeverity() const;
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> ServerCertificateErrors() const;
    Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> ServerIntermediateCertificates() const;
};

template <typename D>
struct WINRT_EBO impl_IWebSocketServerCustomValidationRequestedEventArgs
{
    Windows::Security::Cryptography::Certificates::Certificate ServerCertificate() const;
    Windows::Networking::Sockets::SocketSslErrorSeverity ServerCertificateErrorSeverity() const;
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> ServerCertificateErrors() const;
    Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> ServerIntermediateCertificates() const;
    void Reject() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

}

namespace impl {

template <> struct traits<Windows::Networking::Sockets::IControlChannelTrigger>
{
    using abi = ABI::Windows::Networking::Sockets::IControlChannelTrigger;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IControlChannelTrigger<D>;
};

template <> struct traits<Windows::Networking::Sockets::IControlChannelTrigger2>
{
    using abi = ABI::Windows::Networking::Sockets::IControlChannelTrigger2;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IControlChannelTrigger2<D>;
};

template <> struct traits<Windows::Networking::Sockets::IControlChannelTriggerEventDetails>
{
    using abi = ABI::Windows::Networking::Sockets::IControlChannelTriggerEventDetails;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IControlChannelTriggerEventDetails<D>;
};

template <> struct traits<Windows::Networking::Sockets::IControlChannelTriggerFactory>
{
    using abi = ABI::Windows::Networking::Sockets::IControlChannelTriggerFactory;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IControlChannelTriggerFactory<D>;
};

template <> struct traits<Windows::Networking::Sockets::IControlChannelTriggerResetEventDetails>
{
    using abi = ABI::Windows::Networking::Sockets::IControlChannelTriggerResetEventDetails;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IControlChannelTriggerResetEventDetails<D>;
};

template <> struct traits<Windows::Networking::Sockets::IDatagramSocket>
{
    using abi = ABI::Windows::Networking::Sockets::IDatagramSocket;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IDatagramSocket<D>;
};

template <> struct traits<Windows::Networking::Sockets::IDatagramSocket2>
{
    using abi = ABI::Windows::Networking::Sockets::IDatagramSocket2;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IDatagramSocket2<D>;
};

template <> struct traits<Windows::Networking::Sockets::IDatagramSocket3>
{
    using abi = ABI::Windows::Networking::Sockets::IDatagramSocket3;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IDatagramSocket3<D>;
};

template <> struct traits<Windows::Networking::Sockets::IDatagramSocketControl>
{
    using abi = ABI::Windows::Networking::Sockets::IDatagramSocketControl;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IDatagramSocketControl<D>;
};

template <> struct traits<Windows::Networking::Sockets::IDatagramSocketControl2>
{
    using abi = ABI::Windows::Networking::Sockets::IDatagramSocketControl2;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IDatagramSocketControl2<D>;
};

template <> struct traits<Windows::Networking::Sockets::IDatagramSocketControl3>
{
    using abi = ABI::Windows::Networking::Sockets::IDatagramSocketControl3;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IDatagramSocketControl3<D>;
};

template <> struct traits<Windows::Networking::Sockets::IDatagramSocketInformation>
{
    using abi = ABI::Windows::Networking::Sockets::IDatagramSocketInformation;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IDatagramSocketInformation<D>;
};

template <> struct traits<Windows::Networking::Sockets::IDatagramSocketMessageReceivedEventArgs>
{
    using abi = ABI::Windows::Networking::Sockets::IDatagramSocketMessageReceivedEventArgs;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IDatagramSocketMessageReceivedEventArgs<D>;
};

template <> struct traits<Windows::Networking::Sockets::IDatagramSocketStatics>
{
    using abi = ABI::Windows::Networking::Sockets::IDatagramSocketStatics;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IDatagramSocketStatics<D>;
};

template <> struct traits<Windows::Networking::Sockets::IMessageWebSocket>
{
    using abi = ABI::Windows::Networking::Sockets::IMessageWebSocket;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IMessageWebSocket<D>;
};

template <> struct traits<Windows::Networking::Sockets::IMessageWebSocket2>
{
    using abi = ABI::Windows::Networking::Sockets::IMessageWebSocket2;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IMessageWebSocket2<D>;
};

template <> struct traits<Windows::Networking::Sockets::IMessageWebSocketControl>
{
    using abi = ABI::Windows::Networking::Sockets::IMessageWebSocketControl;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IMessageWebSocketControl<D>;
};

template <> struct traits<Windows::Networking::Sockets::IMessageWebSocketMessageReceivedEventArgs>
{
    using abi = ABI::Windows::Networking::Sockets::IMessageWebSocketMessageReceivedEventArgs;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IMessageWebSocketMessageReceivedEventArgs<D>;
};

template <> struct traits<Windows::Networking::Sockets::ISocketActivityContext>
{
    using abi = ABI::Windows::Networking::Sockets::ISocketActivityContext;
    template <typename D> using consume = Windows::Networking::Sockets::impl_ISocketActivityContext<D>;
};

template <> struct traits<Windows::Networking::Sockets::ISocketActivityContextFactory>
{
    using abi = ABI::Windows::Networking::Sockets::ISocketActivityContextFactory;
    template <typename D> using consume = Windows::Networking::Sockets::impl_ISocketActivityContextFactory<D>;
};

template <> struct traits<Windows::Networking::Sockets::ISocketActivityInformation>
{
    using abi = ABI::Windows::Networking::Sockets::ISocketActivityInformation;
    template <typename D> using consume = Windows::Networking::Sockets::impl_ISocketActivityInformation<D>;
};

template <> struct traits<Windows::Networking::Sockets::ISocketActivityInformationStatics>
{
    using abi = ABI::Windows::Networking::Sockets::ISocketActivityInformationStatics;
    template <typename D> using consume = Windows::Networking::Sockets::impl_ISocketActivityInformationStatics<D>;
};

template <> struct traits<Windows::Networking::Sockets::ISocketActivityTriggerDetails>
{
    using abi = ABI::Windows::Networking::Sockets::ISocketActivityTriggerDetails;
    template <typename D> using consume = Windows::Networking::Sockets::impl_ISocketActivityTriggerDetails<D>;
};

template <> struct traits<Windows::Networking::Sockets::ISocketErrorStatics>
{
    using abi = ABI::Windows::Networking::Sockets::ISocketErrorStatics;
    template <typename D> using consume = Windows::Networking::Sockets::impl_ISocketErrorStatics<D>;
};

template <> struct traits<Windows::Networking::Sockets::IStreamSocket>
{
    using abi = ABI::Windows::Networking::Sockets::IStreamSocket;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IStreamSocket<D>;
};

template <> struct traits<Windows::Networking::Sockets::IStreamSocket2>
{
    using abi = ABI::Windows::Networking::Sockets::IStreamSocket2;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IStreamSocket2<D>;
};

template <> struct traits<Windows::Networking::Sockets::IStreamSocket3>
{
    using abi = ABI::Windows::Networking::Sockets::IStreamSocket3;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IStreamSocket3<D>;
};

template <> struct traits<Windows::Networking::Sockets::IStreamSocketControl>
{
    using abi = ABI::Windows::Networking::Sockets::IStreamSocketControl;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IStreamSocketControl<D>;
};

template <> struct traits<Windows::Networking::Sockets::IStreamSocketControl2>
{
    using abi = ABI::Windows::Networking::Sockets::IStreamSocketControl2;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IStreamSocketControl2<D>;
};

template <> struct traits<Windows::Networking::Sockets::IStreamSocketControl3>
{
    using abi = ABI::Windows::Networking::Sockets::IStreamSocketControl3;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IStreamSocketControl3<D>;
};

template <> struct traits<Windows::Networking::Sockets::IStreamSocketInformation>
{
    using abi = ABI::Windows::Networking::Sockets::IStreamSocketInformation;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IStreamSocketInformation<D>;
};

template <> struct traits<Windows::Networking::Sockets::IStreamSocketInformation2>
{
    using abi = ABI::Windows::Networking::Sockets::IStreamSocketInformation2;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IStreamSocketInformation2<D>;
};

template <> struct traits<Windows::Networking::Sockets::IStreamSocketListener>
{
    using abi = ABI::Windows::Networking::Sockets::IStreamSocketListener;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IStreamSocketListener<D>;
};

template <> struct traits<Windows::Networking::Sockets::IStreamSocketListener2>
{
    using abi = ABI::Windows::Networking::Sockets::IStreamSocketListener2;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IStreamSocketListener2<D>;
};

template <> struct traits<Windows::Networking::Sockets::IStreamSocketListener3>
{
    using abi = ABI::Windows::Networking::Sockets::IStreamSocketListener3;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IStreamSocketListener3<D>;
};

template <> struct traits<Windows::Networking::Sockets::IStreamSocketListenerConnectionReceivedEventArgs>
{
    using abi = ABI::Windows::Networking::Sockets::IStreamSocketListenerConnectionReceivedEventArgs;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IStreamSocketListenerConnectionReceivedEventArgs<D>;
};

template <> struct traits<Windows::Networking::Sockets::IStreamSocketListenerControl>
{
    using abi = ABI::Windows::Networking::Sockets::IStreamSocketListenerControl;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IStreamSocketListenerControl<D>;
};

template <> struct traits<Windows::Networking::Sockets::IStreamSocketListenerControl2>
{
    using abi = ABI::Windows::Networking::Sockets::IStreamSocketListenerControl2;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IStreamSocketListenerControl2<D>;
};

template <> struct traits<Windows::Networking::Sockets::IStreamSocketListenerInformation>
{
    using abi = ABI::Windows::Networking::Sockets::IStreamSocketListenerInformation;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IStreamSocketListenerInformation<D>;
};

template <> struct traits<Windows::Networking::Sockets::IStreamSocketStatics>
{
    using abi = ABI::Windows::Networking::Sockets::IStreamSocketStatics;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IStreamSocketStatics<D>;
};

template <> struct traits<Windows::Networking::Sockets::IStreamWebSocket>
{
    using abi = ABI::Windows::Networking::Sockets::IStreamWebSocket;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IStreamWebSocket<D>;
};

template <> struct traits<Windows::Networking::Sockets::IStreamWebSocket2>
{
    using abi = ABI::Windows::Networking::Sockets::IStreamWebSocket2;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IStreamWebSocket2<D>;
};

template <> struct traits<Windows::Networking::Sockets::IStreamWebSocketControl>
{
    using abi = ABI::Windows::Networking::Sockets::IStreamWebSocketControl;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IStreamWebSocketControl<D>;
};

template <> struct traits<Windows::Networking::Sockets::IWebSocket>
{
    using abi = ABI::Windows::Networking::Sockets::IWebSocket;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IWebSocket<D>;
};

template <> struct traits<Windows::Networking::Sockets::IWebSocketClosedEventArgs>
{
    using abi = ABI::Windows::Networking::Sockets::IWebSocketClosedEventArgs;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IWebSocketClosedEventArgs<D>;
};

template <> struct traits<Windows::Networking::Sockets::IWebSocketControl>
{
    using abi = ABI::Windows::Networking::Sockets::IWebSocketControl;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IWebSocketControl<D>;
};

template <> struct traits<Windows::Networking::Sockets::IWebSocketControl2>
{
    using abi = ABI::Windows::Networking::Sockets::IWebSocketControl2;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IWebSocketControl2<D>;
};

template <> struct traits<Windows::Networking::Sockets::IWebSocketErrorStatics>
{
    using abi = ABI::Windows::Networking::Sockets::IWebSocketErrorStatics;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IWebSocketErrorStatics<D>;
};

template <> struct traits<Windows::Networking::Sockets::IWebSocketInformation>
{
    using abi = ABI::Windows::Networking::Sockets::IWebSocketInformation;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IWebSocketInformation<D>;
};

template <> struct traits<Windows::Networking::Sockets::IWebSocketInformation2>
{
    using abi = ABI::Windows::Networking::Sockets::IWebSocketInformation2;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IWebSocketInformation2<D>;
};

template <> struct traits<Windows::Networking::Sockets::IWebSocketServerCustomValidationRequestedEventArgs>
{
    using abi = ABI::Windows::Networking::Sockets::IWebSocketServerCustomValidationRequestedEventArgs;
    template <typename D> using consume = Windows::Networking::Sockets::impl_IWebSocketServerCustomValidationRequestedEventArgs<D>;
};

template <> struct traits<Windows::Networking::Sockets::ControlChannelTrigger>
{
    using abi = ABI::Windows::Networking::Sockets::ControlChannelTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Sockets.ControlChannelTrigger"; }
};

template <> struct traits<Windows::Networking::Sockets::DatagramSocket>
{
    using abi = ABI::Windows::Networking::Sockets::DatagramSocket;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Sockets.DatagramSocket"; }
};

template <> struct traits<Windows::Networking::Sockets::DatagramSocketControl>
{
    using abi = ABI::Windows::Networking::Sockets::DatagramSocketControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Sockets.DatagramSocketControl"; }
};

template <> struct traits<Windows::Networking::Sockets::DatagramSocketInformation>
{
    using abi = ABI::Windows::Networking::Sockets::DatagramSocketInformation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Sockets.DatagramSocketInformation"; }
};

template <> struct traits<Windows::Networking::Sockets::DatagramSocketMessageReceivedEventArgs>
{
    using abi = ABI::Windows::Networking::Sockets::DatagramSocketMessageReceivedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Sockets.DatagramSocketMessageReceivedEventArgs"; }
};

template <> struct traits<Windows::Networking::Sockets::MessageWebSocket>
{
    using abi = ABI::Windows::Networking::Sockets::MessageWebSocket;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Sockets.MessageWebSocket"; }
};

template <> struct traits<Windows::Networking::Sockets::MessageWebSocketControl>
{
    using abi = ABI::Windows::Networking::Sockets::MessageWebSocketControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Sockets.MessageWebSocketControl"; }
};

template <> struct traits<Windows::Networking::Sockets::MessageWebSocketInformation>
{
    using abi = ABI::Windows::Networking::Sockets::MessageWebSocketInformation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Sockets.MessageWebSocketInformation"; }
};

template <> struct traits<Windows::Networking::Sockets::MessageWebSocketMessageReceivedEventArgs>
{
    using abi = ABI::Windows::Networking::Sockets::MessageWebSocketMessageReceivedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Sockets.MessageWebSocketMessageReceivedEventArgs"; }
};

template <> struct traits<Windows::Networking::Sockets::SocketActivityContext>
{
    using abi = ABI::Windows::Networking::Sockets::SocketActivityContext;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Sockets.SocketActivityContext"; }
};

template <> struct traits<Windows::Networking::Sockets::SocketActivityInformation>
{
    using abi = ABI::Windows::Networking::Sockets::SocketActivityInformation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Sockets.SocketActivityInformation"; }
};

template <> struct traits<Windows::Networking::Sockets::SocketActivityTriggerDetails>
{
    using abi = ABI::Windows::Networking::Sockets::SocketActivityTriggerDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Sockets.SocketActivityTriggerDetails"; }
};

template <> struct traits<Windows::Networking::Sockets::SocketError>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Sockets.SocketError"; }
};

template <> struct traits<Windows::Networking::Sockets::StreamSocket>
{
    using abi = ABI::Windows::Networking::Sockets::StreamSocket;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Sockets.StreamSocket"; }
};

template <> struct traits<Windows::Networking::Sockets::StreamSocketControl>
{
    using abi = ABI::Windows::Networking::Sockets::StreamSocketControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Sockets.StreamSocketControl"; }
};

template <> struct traits<Windows::Networking::Sockets::StreamSocketInformation>
{
    using abi = ABI::Windows::Networking::Sockets::StreamSocketInformation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Sockets.StreamSocketInformation"; }
};

template <> struct traits<Windows::Networking::Sockets::StreamSocketListener>
{
    using abi = ABI::Windows::Networking::Sockets::StreamSocketListener;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Sockets.StreamSocketListener"; }
};

template <> struct traits<Windows::Networking::Sockets::StreamSocketListenerConnectionReceivedEventArgs>
{
    using abi = ABI::Windows::Networking::Sockets::StreamSocketListenerConnectionReceivedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Sockets.StreamSocketListenerConnectionReceivedEventArgs"; }
};

template <> struct traits<Windows::Networking::Sockets::StreamSocketListenerControl>
{
    using abi = ABI::Windows::Networking::Sockets::StreamSocketListenerControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Sockets.StreamSocketListenerControl"; }
};

template <> struct traits<Windows::Networking::Sockets::StreamSocketListenerInformation>
{
    using abi = ABI::Windows::Networking::Sockets::StreamSocketListenerInformation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Sockets.StreamSocketListenerInformation"; }
};

template <> struct traits<Windows::Networking::Sockets::StreamWebSocket>
{
    using abi = ABI::Windows::Networking::Sockets::StreamWebSocket;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Sockets.StreamWebSocket"; }
};

template <> struct traits<Windows::Networking::Sockets::StreamWebSocketControl>
{
    using abi = ABI::Windows::Networking::Sockets::StreamWebSocketControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Sockets.StreamWebSocketControl"; }
};

template <> struct traits<Windows::Networking::Sockets::StreamWebSocketInformation>
{
    using abi = ABI::Windows::Networking::Sockets::StreamWebSocketInformation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Sockets.StreamWebSocketInformation"; }
};

template <> struct traits<Windows::Networking::Sockets::WebSocketClosedEventArgs>
{
    using abi = ABI::Windows::Networking::Sockets::WebSocketClosedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Sockets.WebSocketClosedEventArgs"; }
};

template <> struct traits<Windows::Networking::Sockets::WebSocketError>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Sockets.WebSocketError"; }
};

template <> struct traits<Windows::Networking::Sockets::WebSocketKeepAlive>
{
    using abi = ABI::Windows::Networking::Sockets::WebSocketKeepAlive;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Sockets.WebSocketKeepAlive"; }
};

template <> struct traits<Windows::Networking::Sockets::WebSocketServerCustomValidationRequestedEventArgs>
{
    using abi = ABI::Windows::Networking::Sockets::WebSocketServerCustomValidationRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Sockets.WebSocketServerCustomValidationRequestedEventArgs"; }
};

}

}
