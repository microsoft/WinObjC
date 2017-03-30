// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Networking.Sockets.1.h"
#include "Windows.ApplicationModel.Background.1.h"
#include "Windows.Foundation.1.h"
#include "Windows.ApplicationModel.Background.2.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_98b9acc1_4b56_532e_ac73_03d5291cca90
#define WINRT_GENERIC_98b9acc1_4b56_532e_ac73_03d5291cca90
template <> struct __declspec(uuid("98b9acc1-4b56-532e-ac73-03d5291cca90")) __declspec(novtable) IVector<hstring> : impl_IVector<hstring> {};
#endif

#ifndef WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
#define WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
template <> struct __declspec(uuid("2f13c006-a03a-5f69-b090-75a43e33423e")) __declspec(novtable) IVectorView<hstring> : impl_IVectorView<hstring> {};
#endif

#ifndef WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
#define WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
template <> struct __declspec(uuid("e2fcc7c1-3bfc-5a0b-b2b0-72e769d1cb7e")) __declspec(novtable) IIterable<hstring> : impl_IIterable<hstring> {};
#endif

#ifndef WINRT_GENERIC_0c7d1423_e8fd_5a91_b55c_8bfbe7ac2d40
#define WINRT_GENERIC_0c7d1423_e8fd_5a91_b55c_8bfbe7ac2d40
template <> struct __declspec(uuid("0c7d1423-e8fd-5a91-b55c-8bfbe7ac2d40")) __declspec(novtable) IIterable<Windows::Security::Cryptography::Certificates::Certificate> : impl_IIterable<Windows::Security::Cryptography::Certificates::Certificate> {};
#endif

#ifndef WINRT_GENERIC_963f7013_77c2_51c5_8038_b5bcef633edb
#define WINRT_GENERIC_963f7013_77c2_51c5_8038_b5bcef633edb
template <> struct __declspec(uuid("963f7013-77c2-51c5-8038-b5bcef633edb")) __declspec(novtable) IVectorView<Windows::Security::Cryptography::Certificates::Certificate> : impl_IVectorView<Windows::Security::Cryptography::Certificates::Certificate> {};
#endif

#ifndef WINRT_GENERIC_cb383486_c2bc_5756_912d_6a708a07e5bd
#define WINRT_GENERIC_cb383486_c2bc_5756_912d_6a708a07e5bd
template <> struct __declspec(uuid("cb383486-c2bc-5756-912d-6a708a07e5bd")) __declspec(novtable) IVectorView<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> : impl_IVectorView<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> {};
#endif

#ifndef WINRT_GENERIC_8780a851_6d48_5006_9288_81f3d7045a96
#define WINRT_GENERIC_8780a851_6d48_5006_9288_81f3d7045a96
template <> struct __declspec(uuid("8780a851-6d48-5006-9288-81f3d7045a96")) __declspec(novtable) IVectorView<Windows::Networking::EndpointPair> : impl_IVectorView<Windows::Networking::EndpointPair> {};
#endif

#ifndef WINRT_GENERIC_e6ac8bee_a31c_5af2_9227_5be2f9e80763
#define WINRT_GENERIC_e6ac8bee_a31c_5af2_9227_5be2f9e80763
template <> struct __declspec(uuid("e6ac8bee-a31c-5af2-9227-5be2f9e80763")) __declspec(novtable) IMapView<hstring, Windows::Networking::Sockets::SocketActivityInformation> : impl_IMapView<hstring, Windows::Networking::Sockets::SocketActivityInformation> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_e8736833_d013_5361_977d_c5e99934680e
#define WINRT_GENERIC_e8736833_d013_5361_977d_c5e99934680e
template <> struct __declspec(uuid("e8736833-d013-5361-977d-c5e99934680e")) __declspec(novtable) IAsyncOperation<Windows::Storage::Streams::IOutputStream> : impl_IAsyncOperation<Windows::Storage::Streams::IOutputStream> {};
#endif

#ifndef WINRT_GENERIC_4482e19b_2389_5767_9b0b_8d7a8ef55743
#define WINRT_GENERIC_4482e19b_2389_5767_9b0b_8d7a8ef55743
template <> struct __declspec(uuid("4482e19b-2389-5767-9b0b-8d7a8ef55743")) __declspec(novtable) TypedEventHandler<Windows::Networking::Sockets::DatagramSocket, Windows::Networking::Sockets::DatagramSocketMessageReceivedEventArgs> : impl_TypedEventHandler<Windows::Networking::Sockets::DatagramSocket, Windows::Networking::Sockets::DatagramSocketMessageReceivedEventArgs> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_d7828cf7_4301_58d3_aab5_06e5eefcf79f
#define WINRT_GENERIC_d7828cf7_4301_58d3_aab5_06e5eefcf79f
template <> struct __declspec(uuid("d7828cf7-4301-58d3-aab5-06e5eefcf79f")) __declspec(novtable) IVector<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> : impl_IVector<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_33d00d41_c94f_5a61_9ab7_280dcefa0b08
#define WINRT_GENERIC_33d00d41_c94f_5a61_9ab7_280dcefa0b08
template <> struct __declspec(uuid("33d00d41-c94f-5a61-9ab7-280dcefa0b08")) __declspec(novtable) TypedEventHandler<Windows::Networking::Sockets::StreamSocketListener, Windows::Networking::Sockets::StreamSocketListenerConnectionReceivedEventArgs> : impl_TypedEventHandler<Windows::Networking::Sockets::StreamSocketListener, Windows::Networking::Sockets::StreamSocketListenerConnectionReceivedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_03cf8f90_1669_5f4d_9404_2b784678e6dd
#define WINRT_GENERIC_03cf8f90_1669_5f4d_9404_2b784678e6dd
template <> struct __declspec(uuid("03cf8f90-1669-5f4d-9404-2b784678e6dd")) __declspec(novtable) TypedEventHandler<Windows::Networking::Sockets::IWebSocket, Windows::Networking::Sockets::WebSocketClosedEventArgs> : impl_TypedEventHandler<Windows::Networking::Sockets::IWebSocket, Windows::Networking::Sockets::WebSocketClosedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_de980538_6dcd_52b0_802f_4b6cf59a01ab
#define WINRT_GENERIC_de980538_6dcd_52b0_802f_4b6cf59a01ab
template <> struct __declspec(uuid("de980538-6dcd-52b0-802f-4b6cf59a01ab")) __declspec(novtable) TypedEventHandler<Windows::Networking::Sockets::MessageWebSocket, Windows::Networking::Sockets::MessageWebSocketMessageReceivedEventArgs> : impl_TypedEventHandler<Windows::Networking::Sockets::MessageWebSocket, Windows::Networking::Sockets::MessageWebSocketMessageReceivedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_2c34c585_9cf6_56c7_8dd1_5da26e322078
#define WINRT_GENERIC_2c34c585_9cf6_56c7_8dd1_5da26e322078
template <> struct __declspec(uuid("2c34c585-9cf6-56c7-8dd1-5da26e322078")) __declspec(novtable) TypedEventHandler<Windows::Networking::Sockets::MessageWebSocket, Windows::Networking::Sockets::WebSocketServerCustomValidationRequestedEventArgs> : impl_TypedEventHandler<Windows::Networking::Sockets::MessageWebSocket, Windows::Networking::Sockets::WebSocketServerCustomValidationRequestedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_18b143d3_897e_595e_acc1_ef35614b4cec
#define WINRT_GENERIC_18b143d3_897e_595e_acc1_ef35614b4cec
template <> struct __declspec(uuid("18b143d3-897e-595e-acc1-ef35614b4cec")) __declspec(novtable) TypedEventHandler<Windows::Networking::Sockets::StreamWebSocket, Windows::Networking::Sockets::WebSocketServerCustomValidationRequestedEventArgs> : impl_TypedEventHandler<Windows::Networking::Sockets::StreamWebSocket, Windows::Networking::Sockets::WebSocketServerCustomValidationRequestedEventArgs> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_d7ec83c4_a17b_51bf_8997_aa33b9102dc9
#define WINRT_GENERIC_d7ec83c4_a17b_51bf_8997_aa33b9102dc9
template <> struct __declspec(uuid("d7ec83c4-a17b-51bf-8997-aa33b9102dc9")) __declspec(novtable) IIterable<Windows::Networking::EndpointPair> : impl_IIterable<Windows::Networking::EndpointPair> {};
#endif

#ifndef WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
#define WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
template <> struct __declspec(uuid("8c304ebb-6615-50a4-8829-879ecd443236")) __declspec(novtable) IIterator<hstring> : impl_IIterator<hstring> {};
#endif

#ifndef WINRT_GENERIC_676fc159_f15c_58bd_91a7_28f7e795c756
#define WINRT_GENERIC_676fc159_f15c_58bd_91a7_28f7e795c756
template <> struct __declspec(uuid("676fc159-f15c-58bd-91a7-28f7e795c756")) __declspec(novtable) IIterator<Windows::Security::Cryptography::Certificates::Certificate> : impl_IIterator<Windows::Security::Cryptography::Certificates::Certificate> {};
#endif

#ifndef WINRT_GENERIC_8bcad2b7_0e3b_5eae_bf69_e1f6d9c888f8
#define WINRT_GENERIC_8bcad2b7_0e3b_5eae_bf69_e1f6d9c888f8
template <> struct __declspec(uuid("8bcad2b7-0e3b-5eae-bf69-e1f6d9c888f8")) __declspec(novtable) IIterator<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> : impl_IIterator<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> {};
#endif

#ifndef WINRT_GENERIC_2628f58f_3f02_54f2_808f_e1117709d6d0
#define WINRT_GENERIC_2628f58f_3f02_54f2_808f_e1117709d6d0
template <> struct __declspec(uuid("2628f58f-3f02-54f2-808f-e1117709d6d0")) __declspec(novtable) IIterable<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> : impl_IIterable<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> {};
#endif

#ifndef WINRT_GENERIC_c899ff9f_e6f5_5673_810c_04e2ff98704f
#define WINRT_GENERIC_c899ff9f_e6f5_5673_810c_04e2ff98704f
template <> struct __declspec(uuid("c899ff9f-e6f5-5673-810c-04e2ff98704f")) __declspec(novtable) IIterator<Windows::Networking::EndpointPair> : impl_IIterator<Windows::Networking::EndpointPair> {};
#endif

#ifndef WINRT_GENERIC_7e4bda2c_0125_587d_8806_1285060f3b2d
#define WINRT_GENERIC_7e4bda2c_0125_587d_8806_1285060f3b2d
template <> struct __declspec(uuid("7e4bda2c-0125-587d-8806-1285060f3b2d")) __declspec(novtable) IKeyValuePair<hstring, Windows::Networking::Sockets::SocketActivityInformation> : impl_IKeyValuePair<hstring, Windows::Networking::Sockets::SocketActivityInformation> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_bcb37f4f_3af4_561c_a9e3_eef1738494d7
#define WINRT_GENERIC_bcb37f4f_3af4_561c_a9e3_eef1738494d7
template <> struct __declspec(uuid("bcb37f4f-3af4-561c-a9e3-eef1738494d7")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Storage::Streams::IOutputStream> : impl_AsyncOperationCompletedHandler<Windows::Storage::Streams::IOutputStream> {};
#endif

#ifndef WINRT_GENERIC_afc2ff8e_e393_566a_89c4_d043e940050d
#define WINRT_GENERIC_afc2ff8e_e393_566a_89c4_d043e940050d
template <> struct __declspec(uuid("afc2ff8e-e393-566a-89c4-d043e940050d")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::EndpointPair>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::EndpointPair>> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_f656f7a2_264b_5cfd_8288_64eb89455157
#define WINRT_GENERIC_f656f7a2_264b_5cfd_8288_64eb89455157
template <> struct __declspec(uuid("f656f7a2-264b-5cfd-8288-64eb89455157")) __declspec(novtable) IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Networking::Sockets::SocketActivityInformation>> : impl_IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Networking::Sockets::SocketActivityInformation>> {};
#endif

#ifndef WINRT_GENERIC_3e43fa16_7af1_51df_a0d3_da81b321639d
#define WINRT_GENERIC_3e43fa16_7af1_51df_a0d3_da81b321639d
template <> struct __declspec(uuid("3e43fa16-7af1-51df-a0d3-da81b321639d")) __declspec(novtable) IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Networking::Sockets::SocketActivityInformation>> : impl_IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Networking::Sockets::SocketActivityInformation>> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_20d6faab_3b8e_5a1f_8397_b01cb219a18d
#define WINRT_GENERIC_20d6faab_3b8e_5a1f_8397_b01cb219a18d
template <> struct __declspec(uuid("20d6faab-3b8e-5a1f-8397-b01cb219a18d")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Networking::EndpointPair>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Networking::EndpointPair>> {};
#endif


}

namespace Windows::Networking::Sockets {

struct IControlChannelTrigger :
    Windows::Foundation::IInspectable,
    impl::consume<IControlChannelTrigger>,
    impl::require<IControlChannelTrigger, Windows::Foundation::IClosable>
{
    IControlChannelTrigger(std::nullptr_t = nullptr) noexcept {}
};

struct IControlChannelTrigger2 :
    Windows::Foundation::IInspectable,
    impl::consume<IControlChannelTrigger2>
{
    IControlChannelTrigger2(std::nullptr_t = nullptr) noexcept {}
};

struct IControlChannelTriggerEventDetails :
    Windows::Foundation::IInspectable,
    impl::consume<IControlChannelTriggerEventDetails>
{
    IControlChannelTriggerEventDetails(std::nullptr_t = nullptr) noexcept {}
};

struct IControlChannelTriggerFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IControlChannelTriggerFactory>
{
    IControlChannelTriggerFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IControlChannelTriggerResetEventDetails :
    Windows::Foundation::IInspectable,
    impl::consume<IControlChannelTriggerResetEventDetails>
{
    IControlChannelTriggerResetEventDetails(std::nullptr_t = nullptr) noexcept {}
};

struct IDatagramSocket :
    Windows::Foundation::IInspectable,
    impl::consume<IDatagramSocket>,
    impl::require<IDatagramSocket, Windows::Foundation::IClosable>
{
    IDatagramSocket(std::nullptr_t = nullptr) noexcept {}
};

struct IDatagramSocket2 :
    Windows::Foundation::IInspectable,
    impl::consume<IDatagramSocket2>,
    impl::require<IDatagramSocket2, Windows::Foundation::IClosable>
{
    IDatagramSocket2(std::nullptr_t = nullptr) noexcept {}
};

struct IDatagramSocket3 :
    Windows::Foundation::IInspectable,
    impl::consume<IDatagramSocket3>
{
    IDatagramSocket3(std::nullptr_t = nullptr) noexcept {}
};

struct IDatagramSocketControl :
    Windows::Foundation::IInspectable,
    impl::consume<IDatagramSocketControl>
{
    IDatagramSocketControl(std::nullptr_t = nullptr) noexcept {}
};

struct IDatagramSocketControl2 :
    Windows::Foundation::IInspectable,
    impl::consume<IDatagramSocketControl2>
{
    IDatagramSocketControl2(std::nullptr_t = nullptr) noexcept {}
};

struct IDatagramSocketControl3 :
    Windows::Foundation::IInspectable,
    impl::consume<IDatagramSocketControl3>
{
    IDatagramSocketControl3(std::nullptr_t = nullptr) noexcept {}
};

struct IDatagramSocketInformation :
    Windows::Foundation::IInspectable,
    impl::consume<IDatagramSocketInformation>
{
    IDatagramSocketInformation(std::nullptr_t = nullptr) noexcept {}
};

struct IDatagramSocketMessageReceivedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IDatagramSocketMessageReceivedEventArgs>
{
    IDatagramSocketMessageReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IDatagramSocketStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IDatagramSocketStatics>
{
    IDatagramSocketStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IMessageWebSocket :
    Windows::Foundation::IInspectable,
    impl::consume<IMessageWebSocket>,
    impl::require<IMessageWebSocket, Windows::Foundation::IClosable, Windows::Networking::Sockets::IWebSocket>
{
    IMessageWebSocket(std::nullptr_t = nullptr) noexcept {}
    using impl_IClosable::Close;
    using impl_IWebSocket::Close;
};

struct IMessageWebSocket2 :
    Windows::Foundation::IInspectable,
    impl::consume<IMessageWebSocket2>,
    impl::require<IMessageWebSocket2, Windows::Foundation::IClosable, Windows::Networking::Sockets::IMessageWebSocket, Windows::Networking::Sockets::IWebSocket>
{
    IMessageWebSocket2(std::nullptr_t = nullptr) noexcept {}
    using impl_IClosable::Close;
    using impl_IWebSocket::Close;
};

struct IMessageWebSocketControl :
    Windows::Foundation::IInspectable,
    impl::consume<IMessageWebSocketControl>,
    impl::require<IMessageWebSocketControl, Windows::Networking::Sockets::IWebSocketControl>
{
    IMessageWebSocketControl(std::nullptr_t = nullptr) noexcept {}
};

struct IMessageWebSocketMessageReceivedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IMessageWebSocketMessageReceivedEventArgs>
{
    IMessageWebSocketMessageReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct ISocketActivityContext :
    Windows::Foundation::IInspectable,
    impl::consume<ISocketActivityContext>
{
    ISocketActivityContext(std::nullptr_t = nullptr) noexcept {}
};

struct ISocketActivityContextFactory :
    Windows::Foundation::IInspectable,
    impl::consume<ISocketActivityContextFactory>
{
    ISocketActivityContextFactory(std::nullptr_t = nullptr) noexcept {}
};

struct ISocketActivityInformation :
    Windows::Foundation::IInspectable,
    impl::consume<ISocketActivityInformation>
{
    ISocketActivityInformation(std::nullptr_t = nullptr) noexcept {}
};

struct ISocketActivityInformationStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ISocketActivityInformationStatics>
{
    ISocketActivityInformationStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ISocketActivityTriggerDetails :
    Windows::Foundation::IInspectable,
    impl::consume<ISocketActivityTriggerDetails>
{
    ISocketActivityTriggerDetails(std::nullptr_t = nullptr) noexcept {}
};

struct ISocketErrorStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ISocketErrorStatics>
{
    ISocketErrorStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IStreamSocket :
    Windows::Foundation::IInspectable,
    impl::consume<IStreamSocket>,
    impl::require<IStreamSocket, Windows::Foundation::IClosable>
{
    IStreamSocket(std::nullptr_t = nullptr) noexcept {}
};

struct IStreamSocket2 :
    Windows::Foundation::IInspectable,
    impl::consume<IStreamSocket2>,
    impl::require<IStreamSocket2, Windows::Foundation::IClosable>
{
    IStreamSocket2(std::nullptr_t = nullptr) noexcept {}
};

struct IStreamSocket3 :
    Windows::Foundation::IInspectable,
    impl::consume<IStreamSocket3>
{
    IStreamSocket3(std::nullptr_t = nullptr) noexcept {}
};

struct IStreamSocketControl :
    Windows::Foundation::IInspectable,
    impl::consume<IStreamSocketControl>
{
    IStreamSocketControl(std::nullptr_t = nullptr) noexcept {}
};

struct IStreamSocketControl2 :
    Windows::Foundation::IInspectable,
    impl::consume<IStreamSocketControl2>
{
    IStreamSocketControl2(std::nullptr_t = nullptr) noexcept {}
};

struct IStreamSocketControl3 :
    Windows::Foundation::IInspectable,
    impl::consume<IStreamSocketControl3>
{
    IStreamSocketControl3(std::nullptr_t = nullptr) noexcept {}
};

struct IStreamSocketInformation :
    Windows::Foundation::IInspectable,
    impl::consume<IStreamSocketInformation>
{
    IStreamSocketInformation(std::nullptr_t = nullptr) noexcept {}
};

struct IStreamSocketInformation2 :
    Windows::Foundation::IInspectable,
    impl::consume<IStreamSocketInformation2>
{
    IStreamSocketInformation2(std::nullptr_t = nullptr) noexcept {}
};

struct IStreamSocketListener :
    Windows::Foundation::IInspectable,
    impl::consume<IStreamSocketListener>,
    impl::require<IStreamSocketListener, Windows::Foundation::IClosable>
{
    IStreamSocketListener(std::nullptr_t = nullptr) noexcept {}
};

struct IStreamSocketListener2 :
    Windows::Foundation::IInspectable,
    impl::consume<IStreamSocketListener2>,
    impl::require<IStreamSocketListener2, Windows::Foundation::IClosable>
{
    IStreamSocketListener2(std::nullptr_t = nullptr) noexcept {}
};

struct IStreamSocketListener3 :
    Windows::Foundation::IInspectable,
    impl::consume<IStreamSocketListener3>
{
    IStreamSocketListener3(std::nullptr_t = nullptr) noexcept {}
};

struct IStreamSocketListenerConnectionReceivedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IStreamSocketListenerConnectionReceivedEventArgs>
{
    IStreamSocketListenerConnectionReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IStreamSocketListenerControl :
    Windows::Foundation::IInspectable,
    impl::consume<IStreamSocketListenerControl>
{
    IStreamSocketListenerControl(std::nullptr_t = nullptr) noexcept {}
};

struct IStreamSocketListenerControl2 :
    Windows::Foundation::IInspectable,
    impl::consume<IStreamSocketListenerControl2>
{
    IStreamSocketListenerControl2(std::nullptr_t = nullptr) noexcept {}
};

struct IStreamSocketListenerInformation :
    Windows::Foundation::IInspectable,
    impl::consume<IStreamSocketListenerInformation>
{
    IStreamSocketListenerInformation(std::nullptr_t = nullptr) noexcept {}
};

struct IStreamSocketStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IStreamSocketStatics>
{
    IStreamSocketStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IStreamWebSocket :
    Windows::Foundation::IInspectable,
    impl::consume<IStreamWebSocket>,
    impl::require<IStreamWebSocket, Windows::Foundation::IClosable, Windows::Networking::Sockets::IWebSocket>
{
    IStreamWebSocket(std::nullptr_t = nullptr) noexcept {}
    using impl_IClosable::Close;
    using impl_IWebSocket::Close;
};

struct IStreamWebSocket2 :
    Windows::Foundation::IInspectable,
    impl::consume<IStreamWebSocket2>,
    impl::require<IStreamWebSocket2, Windows::Foundation::IClosable, Windows::Networking::Sockets::IStreamWebSocket, Windows::Networking::Sockets::IWebSocket>
{
    IStreamWebSocket2(std::nullptr_t = nullptr) noexcept {}
    using impl_IClosable::Close;
    using impl_IWebSocket::Close;
};

struct IStreamWebSocketControl :
    Windows::Foundation::IInspectable,
    impl::consume<IStreamWebSocketControl>,
    impl::require<IStreamWebSocketControl, Windows::Networking::Sockets::IWebSocketControl>
{
    IStreamWebSocketControl(std::nullptr_t = nullptr) noexcept {}
};

struct IWebSocket :
    Windows::Foundation::IInspectable,
    impl::consume<IWebSocket>,
    impl::require<IWebSocket, Windows::Foundation::IClosable>
{
    IWebSocket(std::nullptr_t = nullptr) noexcept {}
    using impl_IClosable::Close;
    using impl_IWebSocket::Close;
};

struct IWebSocketClosedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IWebSocketClosedEventArgs>
{
    IWebSocketClosedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IWebSocketControl :
    Windows::Foundation::IInspectable,
    impl::consume<IWebSocketControl>
{
    IWebSocketControl(std::nullptr_t = nullptr) noexcept {}
};

struct IWebSocketControl2 :
    Windows::Foundation::IInspectable,
    impl::consume<IWebSocketControl2>,
    impl::require<IWebSocketControl2, Windows::Networking::Sockets::IWebSocketControl>
{
    IWebSocketControl2(std::nullptr_t = nullptr) noexcept {}
};

struct IWebSocketErrorStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IWebSocketErrorStatics>
{
    IWebSocketErrorStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IWebSocketInformation :
    Windows::Foundation::IInspectable,
    impl::consume<IWebSocketInformation>
{
    IWebSocketInformation(std::nullptr_t = nullptr) noexcept {}
};

struct IWebSocketInformation2 :
    Windows::Foundation::IInspectable,
    impl::consume<IWebSocketInformation2>,
    impl::require<IWebSocketInformation2, Windows::Networking::Sockets::IWebSocketInformation>
{
    IWebSocketInformation2(std::nullptr_t = nullptr) noexcept {}
};

struct IWebSocketServerCustomValidationRequestedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IWebSocketServerCustomValidationRequestedEventArgs>
{
    IWebSocketServerCustomValidationRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

}

}
