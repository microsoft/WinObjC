// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.VoiceCommands.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
#define WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
template <> struct __declspec(uuid("2f13c006-a03a-5f69-b090-75a43e33423e")) __declspec(novtable) IVectorView<hstring> : impl_IVectorView<hstring> {};
#endif

#ifndef WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
#define WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
template <> struct __declspec(uuid("e2fcc7c1-3bfc-5a0b-b2b0-72e769d1cb7e")) __declspec(novtable) IIterable<hstring> : impl_IIterable<hstring> {};
#endif

#ifndef WINRT_GENERIC_4c1168f0_a0b2_5312_b99a_471abd334e85
#define WINRT_GENERIC_4c1168f0_a0b2_5312_b99a_471abd334e85
template <> struct __declspec(uuid("4c1168f0-a0b2-5312-b99a-471abd334e85")) __declspec(novtable) IMapView<hstring, Windows::ApplicationModel::VoiceCommands::VoiceCommandDefinition> : impl_IMapView<hstring, Windows::ApplicationModel::VoiceCommands::VoiceCommandDefinition> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_815f1854_4d79_570d_9b57_5b47e282cd66
#define WINRT_GENERIC_815f1854_4d79_570d_9b57_5b47e282cd66
template <> struct __declspec(uuid("815f1854-4d79-570d-9b57-5b47e282cd66")) __declspec(novtable) IAsyncOperation<Windows::ApplicationModel::VoiceCommands::VoiceCommand> : impl_IAsyncOperation<Windows::ApplicationModel::VoiceCommands::VoiceCommand> {};
#endif

#ifndef WINRT_GENERIC_3b39db5f_d2a4_5d88_851f_e9a0ea0d947e
#define WINRT_GENERIC_3b39db5f_d2a4_5d88_851f_e9a0ea0d947e
template <> struct __declspec(uuid("3b39db5f-d2a4-5d88-851f-e9a0ea0d947e")) __declspec(novtable) IAsyncOperation<Windows::ApplicationModel::VoiceCommands::VoiceCommandConfirmationResult> : impl_IAsyncOperation<Windows::ApplicationModel::VoiceCommands::VoiceCommandConfirmationResult> {};
#endif

#ifndef WINRT_GENERIC_b03d44c8_060f_5b98_953a_fd1eb1d46abc
#define WINRT_GENERIC_b03d44c8_060f_5b98_953a_fd1eb1d46abc
template <> struct __declspec(uuid("b03d44c8-060f-5b98-953a-fd1eb1d46abc")) __declspec(novtable) IAsyncOperation<Windows::ApplicationModel::VoiceCommands::VoiceCommandDisambiguationResult> : impl_IAsyncOperation<Windows::ApplicationModel::VoiceCommands::VoiceCommandDisambiguationResult> {};
#endif

#ifndef WINRT_GENERIC_780a6352_b400_5767_993b_90875710d937
#define WINRT_GENERIC_780a6352_b400_5767_993b_90875710d937
template <> struct __declspec(uuid("780a6352-b400-5767-993b-90875710d937")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::VoiceCommands::VoiceCommandServiceConnection, Windows::ApplicationModel::VoiceCommands::VoiceCommandCompletedEventArgs> : impl_TypedEventHandler<Windows::ApplicationModel::VoiceCommands::VoiceCommandServiceConnection, Windows::ApplicationModel::VoiceCommands::VoiceCommandCompletedEventArgs> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_bd13249b_8099_5573_bf74_7457796e92e5
#define WINRT_GENERIC_bd13249b_8099_5573_bf74_7457796e92e5
template <> struct __declspec(uuid("bd13249b-8099-5573-bf74-7457796e92e5")) __declspec(novtable) IIterable<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile> : impl_IIterable<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile> {};
#endif

#ifndef WINRT_GENERIC_e45fe700_ea08_5172_b88c_c4b3e048c3e8
#define WINRT_GENERIC_e45fe700_ea08_5172_b88c_c4b3e048c3e8
template <> struct __declspec(uuid("e45fe700-ea08-5172-b88c-c4b3e048c3e8")) __declspec(novtable) IVector<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile> : impl_IVector<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile> {};
#endif

#ifndef WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
#define WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
template <> struct __declspec(uuid("8c304ebb-6615-50a4-8829-879ecd443236")) __declspec(novtable) IIterator<hstring> : impl_IIterator<hstring> {};
#endif

#ifndef WINRT_GENERIC_a932bfda_2ce5_5012_ae83_f397976e4a86
#define WINRT_GENERIC_a932bfda_2ce5_5012_ae83_f397976e4a86
template <> struct __declspec(uuid("a932bfda-2ce5-5012-ae83-f397976e4a86")) __declspec(novtable) IKeyValuePair<hstring, Windows::ApplicationModel::VoiceCommands::VoiceCommandDefinition> : impl_IKeyValuePair<hstring, Windows::ApplicationModel::VoiceCommands::VoiceCommandDefinition> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_1024f849_b4a1_52e6_b771_6d2f08c30e63
#define WINRT_GENERIC_1024f849_b4a1_52e6_b771_6d2f08c30e63
template <> struct __declspec(uuid("1024f849-b4a1-52e6-b771-6d2f08c30e63")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::ApplicationModel::VoiceCommands::VoiceCommand> : impl_AsyncOperationCompletedHandler<Windows::ApplicationModel::VoiceCommands::VoiceCommand> {};
#endif

#ifndef WINRT_GENERIC_f5244cb8_f912_50c9_b218_d7a0403971aa
#define WINRT_GENERIC_f5244cb8_f912_50c9_b218_d7a0403971aa
template <> struct __declspec(uuid("f5244cb8-f912-50c9-b218-d7a0403971aa")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::ApplicationModel::VoiceCommands::VoiceCommandConfirmationResult> : impl_AsyncOperationCompletedHandler<Windows::ApplicationModel::VoiceCommands::VoiceCommandConfirmationResult> {};
#endif

#ifndef WINRT_GENERIC_46b96890_2942_5564_82d8_31a4851bd7b8
#define WINRT_GENERIC_46b96890_2942_5564_82d8_31a4851bd7b8
template <> struct __declspec(uuid("46b96890-2942-5564-82d8-31a4851bd7b8")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::ApplicationModel::VoiceCommands::VoiceCommandDisambiguationResult> : impl_AsyncOperationCompletedHandler<Windows::ApplicationModel::VoiceCommands::VoiceCommandDisambiguationResult> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_968d589c_0710_52f0_85ed_112fac4cff35
#define WINRT_GENERIC_968d589c_0710_52f0_85ed_112fac4cff35
template <> struct __declspec(uuid("968d589c-0710-52f0-85ed-112fac4cff35")) __declspec(novtable) IIterator<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile> : impl_IIterator<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile> {};
#endif

#ifndef WINRT_GENERIC_cb2c6693_1fc9_5b95_99b5_7239679619b9
#define WINRT_GENERIC_cb2c6693_1fc9_5b95_99b5_7239679619b9
template <> struct __declspec(uuid("cb2c6693-1fc9-5b95-99b5-7239679619b9")) __declspec(novtable) IVectorView<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile> : impl_IVectorView<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile> {};
#endif

#ifndef WINRT_GENERIC_2843d34f_d3e5_5fca_9fdc_b568dd5c1e64
#define WINRT_GENERIC_2843d34f_d3e5_5fca_9fdc_b568dd5c1e64
template <> struct __declspec(uuid("2843d34f-d3e5-5fca-9fdc-b568dd5c1e64")) __declspec(novtable) IMapView<hstring, Windows::Foundation::Collections::IVectorView<hstring>> : impl_IMapView<hstring, Windows::Foundation::Collections::IVectorView<hstring>> {};
#endif

#ifndef WINRT_GENERIC_91fbb58b_fb9c_5165_a1bf_815d2767300d
#define WINRT_GENERIC_91fbb58b_fb9c_5165_a1bf_815d2767300d
template <> struct __declspec(uuid("91fbb58b-fb9c-5165-a1bf-815d2767300d")) __declspec(novtable) IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::ApplicationModel::VoiceCommands::VoiceCommandDefinition>> : impl_IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::ApplicationModel::VoiceCommands::VoiceCommandDefinition>> {};
#endif

#ifndef WINRT_GENERIC_67693dd1_ac45_5ef3_9ba6_4d78709d9ee0
#define WINRT_GENERIC_67693dd1_ac45_5ef3_9ba6_4d78709d9ee0
template <> struct __declspec(uuid("67693dd1-ac45-5ef3-9ba6-4d78709d9ee0")) __declspec(novtable) IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::ApplicationModel::VoiceCommands::VoiceCommandDefinition>> : impl_IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::ApplicationModel::VoiceCommands::VoiceCommandDefinition>> {};
#endif

#ifndef WINRT_GENERIC_bcde03ad_ea71_5077_a961_1c0ecff57202
#define WINRT_GENERIC_bcde03ad_ea71_5077_a961_1c0ecff57202
template <> struct __declspec(uuid("bcde03ad-ea71-5077-a961-1c0ecff57202")) __declspec(novtable) IKeyValuePair<hstring, Windows::Foundation::Collections::IVectorView<hstring>> : impl_IKeyValuePair<hstring, Windows::Foundation::Collections::IVectorView<hstring>> {};
#endif

#ifndef WINRT_GENERIC_643b6d83_457e_5a43_800f_b0449f91d96b
#define WINRT_GENERIC_643b6d83_457e_5a43_800f_b0449f91d96b
template <> struct __declspec(uuid("643b6d83-457e-5a43-800f-b0449f91d96b")) __declspec(novtable) IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::Collections::IVectorView<hstring>>> : impl_IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::Collections::IVectorView<hstring>>> {};
#endif

#ifndef WINRT_GENERIC_a4cd6151_2cc1_56f1_9014_df6ba3410beb
#define WINRT_GENERIC_a4cd6151_2cc1_56f1_9014_df6ba3410beb
template <> struct __declspec(uuid("a4cd6151-2cc1-56f1-9014-df6ba3410beb")) __declspec(novtable) IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::Collections::IVectorView<hstring>>> : impl_IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::Collections::IVectorView<hstring>>> {};
#endif


}

namespace Windows::ApplicationModel::VoiceCommands {

struct IVoiceCommand :
    Windows::Foundation::IInspectable,
    impl::consume<IVoiceCommand>
{
    IVoiceCommand(std::nullptr_t = nullptr) noexcept {}
};

struct IVoiceCommandCompletedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IVoiceCommandCompletedEventArgs>
{
    IVoiceCommandCompletedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IVoiceCommandConfirmationResult :
    Windows::Foundation::IInspectable,
    impl::consume<IVoiceCommandConfirmationResult>
{
    IVoiceCommandConfirmationResult(std::nullptr_t = nullptr) noexcept {}
};

struct IVoiceCommandContentTile :
    Windows::Foundation::IInspectable,
    impl::consume<IVoiceCommandContentTile>
{
    IVoiceCommandContentTile(std::nullptr_t = nullptr) noexcept {}
};

struct IVoiceCommandDefinition :
    Windows::Foundation::IInspectable,
    impl::consume<IVoiceCommandDefinition>
{
    IVoiceCommandDefinition(std::nullptr_t = nullptr) noexcept {}
};

struct IVoiceCommandDefinitionManagerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IVoiceCommandDefinitionManagerStatics>
{
    IVoiceCommandDefinitionManagerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IVoiceCommandDisambiguationResult :
    Windows::Foundation::IInspectable,
    impl::consume<IVoiceCommandDisambiguationResult>
{
    IVoiceCommandDisambiguationResult(std::nullptr_t = nullptr) noexcept {}
};

struct IVoiceCommandResponse :
    Windows::Foundation::IInspectable,
    impl::consume<IVoiceCommandResponse>
{
    IVoiceCommandResponse(std::nullptr_t = nullptr) noexcept {}
};

struct IVoiceCommandResponseStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IVoiceCommandResponseStatics>
{
    IVoiceCommandResponseStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IVoiceCommandServiceConnection :
    Windows::Foundation::IInspectable,
    impl::consume<IVoiceCommandServiceConnection>
{
    IVoiceCommandServiceConnection(std::nullptr_t = nullptr) noexcept {}
};

struct IVoiceCommandServiceConnectionStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IVoiceCommandServiceConnectionStatics>
{
    IVoiceCommandServiceConnectionStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IVoiceCommandUserMessage :
    Windows::Foundation::IInspectable,
    impl::consume<IVoiceCommandUserMessage>
{
    IVoiceCommandUserMessage(std::nullptr_t = nullptr) noexcept {}
};

}

}
