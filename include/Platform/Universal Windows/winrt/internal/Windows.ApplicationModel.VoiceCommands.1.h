// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.ApplicationModel.VoiceCommands.0.h"
#include "Windows.ApplicationModel.AppService.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Globalization.0.h"
#include "Windows.Media.SpeechRecognition.0.h"
#include "Windows.Storage.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::VoiceCommands {

struct __declspec(uuid("936f5273-ec82-42a6-a55c-d2d79ec6f920")) __declspec(novtable) IVoiceCommand : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CommandName(hstring * value) = 0;
    virtual HRESULT __stdcall get_Properties(Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::Collections::IVectorView<hstring>> ** value) = 0;
    virtual HRESULT __stdcall get_SpeechRecognitionResult(Windows::Media::SpeechRecognition::ISpeechRecognitionResult ** value) = 0;
};

struct __declspec(uuid("c85e675d-fe42-432c-9907-09df9fcf64e8")) __declspec(novtable) IVoiceCommandCompletedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Reason(winrt::Windows::ApplicationModel::VoiceCommands::VoiceCommandCompletionReason * value) = 0;
};

struct __declspec(uuid("a022593e-8221-4526-b083-840972262247")) __declspec(novtable) IVoiceCommandConfirmationResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Confirmed(bool * value) = 0;
};

struct __declspec(uuid("3eefe9f0-b8c7-4c76-a0de-1607895ee327")) __declspec(novtable) IVoiceCommandContentTile : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Title(hstring * value) = 0;
    virtual HRESULT __stdcall put_Title(hstring value) = 0;
    virtual HRESULT __stdcall get_TextLine1(hstring * value) = 0;
    virtual HRESULT __stdcall put_TextLine1(hstring value) = 0;
    virtual HRESULT __stdcall get_TextLine2(hstring * value) = 0;
    virtual HRESULT __stdcall put_TextLine2(hstring value) = 0;
    virtual HRESULT __stdcall get_TextLine3(hstring * value) = 0;
    virtual HRESULT __stdcall put_TextLine3(hstring value) = 0;
    virtual HRESULT __stdcall get_Image(Windows::Storage::IStorageFile ** value) = 0;
    virtual HRESULT __stdcall put_Image(Windows::Storage::IStorageFile * value) = 0;
    virtual HRESULT __stdcall get_AppContext(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_AppContext(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_AppLaunchArgument(hstring * value) = 0;
    virtual HRESULT __stdcall put_AppLaunchArgument(hstring value) = 0;
    virtual HRESULT __stdcall get_ContentTileType(winrt::Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTileType * value) = 0;
    virtual HRESULT __stdcall put_ContentTileType(winrt::Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTileType value) = 0;
};

struct __declspec(uuid("7972aad0-0974-4979-984b-cb8959cd61ae")) __declspec(novtable) IVoiceCommandDefinition : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Language(hstring * value) = 0;
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall abi_SetPhraseListAsync(hstring phraseListName, Windows::Foundation::Collections::IIterable<hstring> * phraseList, Windows::Foundation::IAsyncAction ** updateAction) = 0;
};

struct __declspec(uuid("8fe7a69e-067e-4f16-a18c-5b17e9499940")) __declspec(novtable) IVoiceCommandDefinitionManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_InstallCommandDefinitionsFromStorageFileAsync(Windows::Storage::IStorageFile * file, Windows::Foundation::IAsyncAction ** installAction) = 0;
    virtual HRESULT __stdcall get_InstalledCommandDefinitions(Windows::Foundation::Collections::IMapView<hstring, Windows::ApplicationModel::VoiceCommands::VoiceCommandDefinition> ** voiceCommandDefinitions) = 0;
};

struct __declspec(uuid("ecc68cfe-c9ac-45df-a8ea-feea08ef9c5e")) __declspec(novtable) IVoiceCommandDisambiguationResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SelectedItem(Windows::ApplicationModel::VoiceCommands::IVoiceCommandContentTile ** value) = 0;
};

struct __declspec(uuid("0284b30e-8a3b-4cc4-a6a1-cad5be2716b5")) __declspec(novtable) IVoiceCommandResponse : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Message(Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage ** value) = 0;
    virtual HRESULT __stdcall put_Message(Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage * value) = 0;
    virtual HRESULT __stdcall get_RepeatMessage(Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage ** value) = 0;
    virtual HRESULT __stdcall put_RepeatMessage(Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage * value) = 0;
    virtual HRESULT __stdcall get_AppLaunchArgument(hstring * value) = 0;
    virtual HRESULT __stdcall put_AppLaunchArgument(hstring value) = 0;
    virtual HRESULT __stdcall get_VoiceCommandContentTiles(Windows::Foundation::Collections::IVector<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile> ** value) = 0;
};

struct __declspec(uuid("2932f813-0d3b-49f2-96dd-625019bd3b5d")) __declspec(novtable) IVoiceCommandResponseStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MaxSupportedVoiceCommandContentTiles(uint32_t * value) = 0;
    virtual HRESULT __stdcall abi_CreateResponse(Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage * userMessage, Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse ** response) = 0;
    virtual HRESULT __stdcall abi_CreateResponseWithTiles(Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage * message, Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile> * contentTiles, Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse ** response) = 0;
    virtual HRESULT __stdcall abi_CreateResponseForPrompt(Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage * message, Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage * repeatMessage, Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse ** response) = 0;
    virtual HRESULT __stdcall abi_CreateResponseForPromptWithTiles(Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage * message, Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage * repeatMessage, Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile> * contentTiles, Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse ** response) = 0;
};

struct __declspec(uuid("d894bb9f-21da-44a4-98a2-fb131920a9cc")) __declspec(novtable) IVoiceCommandServiceConnection : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetVoiceCommandAsync(Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::VoiceCommands::VoiceCommand> ** operation) = 0;
    virtual HRESULT __stdcall abi_RequestConfirmationAsync(Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse * response, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::VoiceCommands::VoiceCommandConfirmationResult> ** operation) = 0;
    virtual HRESULT __stdcall abi_RequestDisambiguationAsync(Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse * response, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::VoiceCommands::VoiceCommandDisambiguationResult> ** operation) = 0;
    virtual HRESULT __stdcall abi_ReportProgressAsync(Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse * response, Windows::Foundation::IAsyncAction ** action) = 0;
    virtual HRESULT __stdcall abi_ReportSuccessAsync(Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse * response, Windows::Foundation::IAsyncAction ** action) = 0;
    virtual HRESULT __stdcall abi_ReportFailureAsync(Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse * response, Windows::Foundation::IAsyncAction ** action) = 0;
    virtual HRESULT __stdcall abi_RequestAppLaunchAsync(Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse * response, Windows::Foundation::IAsyncAction ** action) = 0;
    virtual HRESULT __stdcall get_Language(Windows::Globalization::ILanguage ** language) = 0;
    virtual HRESULT __stdcall add_VoiceCommandCompleted(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::VoiceCommands::VoiceCommandServiceConnection, Windows::ApplicationModel::VoiceCommands::VoiceCommandCompletedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_VoiceCommandCompleted(event_token token) = 0;
};

struct __declspec(uuid("370ebffb-2d34-42df-8770-074d0f334697")) __declspec(novtable) IVoiceCommandServiceConnectionStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FromAppServiceTriggerDetails(Windows::ApplicationModel::AppService::IAppServiceTriggerDetails * triggerDetails, Windows::ApplicationModel::VoiceCommands::IVoiceCommandServiceConnection ** value) = 0;
};

struct __declspec(uuid("674eb3c0-44f6-4f07-b979-4c723fc08597")) __declspec(novtable) IVoiceCommandUserMessage : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DisplayMessage(hstring * value) = 0;
    virtual HRESULT __stdcall put_DisplayMessage(hstring value) = 0;
    virtual HRESULT __stdcall get_SpokenMessage(hstring * value) = 0;
    virtual HRESULT __stdcall put_SpokenMessage(hstring value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::ApplicationModel::VoiceCommands::VoiceCommand> { using default_interface = Windows::ApplicationModel::VoiceCommands::IVoiceCommand; };
template <> struct traits<Windows::ApplicationModel::VoiceCommands::VoiceCommandCompletedEventArgs> { using default_interface = Windows::ApplicationModel::VoiceCommands::IVoiceCommandCompletedEventArgs; };
template <> struct traits<Windows::ApplicationModel::VoiceCommands::VoiceCommandConfirmationResult> { using default_interface = Windows::ApplicationModel::VoiceCommands::IVoiceCommandConfirmationResult; };
template <> struct traits<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile> { using default_interface = Windows::ApplicationModel::VoiceCommands::IVoiceCommandContentTile; };
template <> struct traits<Windows::ApplicationModel::VoiceCommands::VoiceCommandDefinition> { using default_interface = Windows::ApplicationModel::VoiceCommands::IVoiceCommandDefinition; };
template <> struct traits<Windows::ApplicationModel::VoiceCommands::VoiceCommandDisambiguationResult> { using default_interface = Windows::ApplicationModel::VoiceCommands::IVoiceCommandDisambiguationResult; };
template <> struct traits<Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse> { using default_interface = Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse; };
template <> struct traits<Windows::ApplicationModel::VoiceCommands::VoiceCommandServiceConnection> { using default_interface = Windows::ApplicationModel::VoiceCommands::IVoiceCommandServiceConnection; };
template <> struct traits<Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage> { using default_interface = Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage; };

}

namespace Windows::ApplicationModel::VoiceCommands {

template <typename D>
struct WINRT_EBO impl_IVoiceCommand
{
    hstring CommandName() const;
    Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::Collections::IVectorView<hstring>> Properties() const;
    Windows::Media::SpeechRecognition::SpeechRecognitionResult SpeechRecognitionResult() const;
};

template <typename D>
struct WINRT_EBO impl_IVoiceCommandCompletedEventArgs
{
    Windows::ApplicationModel::VoiceCommands::VoiceCommandCompletionReason Reason() const;
};

template <typename D>
struct WINRT_EBO impl_IVoiceCommandConfirmationResult
{
    bool Confirmed() const;
};

template <typename D>
struct WINRT_EBO impl_IVoiceCommandContentTile
{
    hstring Title() const;
    void Title(hstring_view value) const;
    hstring TextLine1() const;
    void TextLine1(hstring_view value) const;
    hstring TextLine2() const;
    void TextLine2(hstring_view value) const;
    hstring TextLine3() const;
    void TextLine3(hstring_view value) const;
    Windows::Storage::IStorageFile Image() const;
    void Image(const Windows::Storage::IStorageFile & value) const;
    Windows::Foundation::IInspectable AppContext() const;
    void AppContext(const Windows::Foundation::IInspectable & value) const;
    hstring AppLaunchArgument() const;
    void AppLaunchArgument(hstring_view value) const;
    Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTileType ContentTileType() const;
    void ContentTileType(Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTileType value) const;
};

template <typename D>
struct WINRT_EBO impl_IVoiceCommandDefinition
{
    hstring Language() const;
    hstring Name() const;
    Windows::Foundation::IAsyncAction SetPhraseListAsync(hstring_view phraseListName, iterable<hstring> phraseList) const;
};

template <typename D>
struct WINRT_EBO impl_IVoiceCommandDefinitionManagerStatics
{
    Windows::Foundation::IAsyncAction InstallCommandDefinitionsFromStorageFileAsync(const Windows::Storage::StorageFile & file) const;
    Windows::Foundation::Collections::IMapView<hstring, Windows::ApplicationModel::VoiceCommands::VoiceCommandDefinition> InstalledCommandDefinitions() const;
};

template <typename D>
struct WINRT_EBO impl_IVoiceCommandDisambiguationResult
{
    Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile SelectedItem() const;
};

template <typename D>
struct WINRT_EBO impl_IVoiceCommandResponse
{
    Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage Message() const;
    void Message(const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & value) const;
    Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage RepeatMessage() const;
    void RepeatMessage(const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & value) const;
    hstring AppLaunchArgument() const;
    void AppLaunchArgument(hstring_view value) const;
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile> VoiceCommandContentTiles() const;
};

template <typename D>
struct WINRT_EBO impl_IVoiceCommandResponseStatics
{
    uint32_t MaxSupportedVoiceCommandContentTiles() const;
    Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse CreateResponse(const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & userMessage) const;
    Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse CreateResponse(const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & message, iterable<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile> contentTiles) const;
    Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse CreateResponseForPrompt(const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & message, const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & repeatMessage) const;
    Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse CreateResponseForPrompt(const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & message, const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & repeatMessage, iterable<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile> contentTiles) const;
};

template <typename D>
struct WINRT_EBO impl_IVoiceCommandServiceConnection
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::VoiceCommands::VoiceCommand> GetVoiceCommandAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::VoiceCommands::VoiceCommandConfirmationResult> RequestConfirmationAsync(const Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse & response) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::VoiceCommands::VoiceCommandDisambiguationResult> RequestDisambiguationAsync(const Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse & response) const;
    Windows::Foundation::IAsyncAction ReportProgressAsync(const Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse & response) const;
    Windows::Foundation::IAsyncAction ReportSuccessAsync(const Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse & response) const;
    Windows::Foundation::IAsyncAction ReportFailureAsync(const Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse & response) const;
    Windows::Foundation::IAsyncAction RequestAppLaunchAsync(const Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse & response) const;
    Windows::Globalization::Language Language() const;
    event_token VoiceCommandCompleted(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::VoiceCommands::VoiceCommandServiceConnection, Windows::ApplicationModel::VoiceCommands::VoiceCommandCompletedEventArgs> & handler) const;
    using VoiceCommandCompleted_revoker = event_revoker<IVoiceCommandServiceConnection>;
    VoiceCommandCompleted_revoker VoiceCommandCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::VoiceCommands::VoiceCommandServiceConnection, Windows::ApplicationModel::VoiceCommands::VoiceCommandCompletedEventArgs> & handler) const;
    void VoiceCommandCompleted(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IVoiceCommandServiceConnectionStatics
{
    Windows::ApplicationModel::VoiceCommands::VoiceCommandServiceConnection FromAppServiceTriggerDetails(const Windows::ApplicationModel::AppService::AppServiceTriggerDetails & triggerDetails) const;
};

template <typename D>
struct WINRT_EBO impl_IVoiceCommandUserMessage
{
    hstring DisplayMessage() const;
    void DisplayMessage(hstring_view value) const;
    hstring SpokenMessage() const;
    void SpokenMessage(hstring_view value) const;
};

}

namespace impl {

template <> struct traits<Windows::ApplicationModel::VoiceCommands::IVoiceCommand>
{
    using abi = ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommand;
    template <typename D> using consume = Windows::ApplicationModel::VoiceCommands::impl_IVoiceCommand<D>;
};

template <> struct traits<Windows::ApplicationModel::VoiceCommands::IVoiceCommandCompletedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandCompletedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::VoiceCommands::impl_IVoiceCommandCompletedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::VoiceCommands::IVoiceCommandConfirmationResult>
{
    using abi = ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandConfirmationResult;
    template <typename D> using consume = Windows::ApplicationModel::VoiceCommands::impl_IVoiceCommandConfirmationResult<D>;
};

template <> struct traits<Windows::ApplicationModel::VoiceCommands::IVoiceCommandContentTile>
{
    using abi = ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandContentTile;
    template <typename D> using consume = Windows::ApplicationModel::VoiceCommands::impl_IVoiceCommandContentTile<D>;
};

template <> struct traits<Windows::ApplicationModel::VoiceCommands::IVoiceCommandDefinition>
{
    using abi = ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandDefinition;
    template <typename D> using consume = Windows::ApplicationModel::VoiceCommands::impl_IVoiceCommandDefinition<D>;
};

template <> struct traits<Windows::ApplicationModel::VoiceCommands::IVoiceCommandDefinitionManagerStatics>
{
    using abi = ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandDefinitionManagerStatics;
    template <typename D> using consume = Windows::ApplicationModel::VoiceCommands::impl_IVoiceCommandDefinitionManagerStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::VoiceCommands::IVoiceCommandDisambiguationResult>
{
    using abi = ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandDisambiguationResult;
    template <typename D> using consume = Windows::ApplicationModel::VoiceCommands::impl_IVoiceCommandDisambiguationResult<D>;
};

template <> struct traits<Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse>
{
    using abi = ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse;
    template <typename D> using consume = Windows::ApplicationModel::VoiceCommands::impl_IVoiceCommandResponse<D>;
};

template <> struct traits<Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponseStatics>
{
    using abi = ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponseStatics;
    template <typename D> using consume = Windows::ApplicationModel::VoiceCommands::impl_IVoiceCommandResponseStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::VoiceCommands::IVoiceCommandServiceConnection>
{
    using abi = ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandServiceConnection;
    template <typename D> using consume = Windows::ApplicationModel::VoiceCommands::impl_IVoiceCommandServiceConnection<D>;
};

template <> struct traits<Windows::ApplicationModel::VoiceCommands::IVoiceCommandServiceConnectionStatics>
{
    using abi = ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandServiceConnectionStatics;
    template <typename D> using consume = Windows::ApplicationModel::VoiceCommands::impl_IVoiceCommandServiceConnectionStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage>
{
    using abi = ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage;
    template <typename D> using consume = Windows::ApplicationModel::VoiceCommands::impl_IVoiceCommandUserMessage<D>;
};

template <> struct traits<Windows::ApplicationModel::VoiceCommands::VoiceCommand>
{
    using abi = ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommand;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.VoiceCommands.VoiceCommand"; }
};

template <> struct traits<Windows::ApplicationModel::VoiceCommands::VoiceCommandCompletedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommandCompletedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.VoiceCommands.VoiceCommandCompletedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::VoiceCommands::VoiceCommandConfirmationResult>
{
    using abi = ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommandConfirmationResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.VoiceCommands.VoiceCommandConfirmationResult"; }
};

template <> struct traits<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile>
{
    using abi = ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.VoiceCommands.VoiceCommandContentTile"; }
};

template <> struct traits<Windows::ApplicationModel::VoiceCommands::VoiceCommandDefinition>
{
    using abi = ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommandDefinition;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.VoiceCommands.VoiceCommandDefinition"; }
};

template <> struct traits<Windows::ApplicationModel::VoiceCommands::VoiceCommandDefinitionManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.VoiceCommands.VoiceCommandDefinitionManager"; }
};

template <> struct traits<Windows::ApplicationModel::VoiceCommands::VoiceCommandDisambiguationResult>
{
    using abi = ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommandDisambiguationResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.VoiceCommands.VoiceCommandDisambiguationResult"; }
};

template <> struct traits<Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse>
{
    using abi = ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.VoiceCommands.VoiceCommandResponse"; }
};

template <> struct traits<Windows::ApplicationModel::VoiceCommands::VoiceCommandServiceConnection>
{
    using abi = ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommandServiceConnection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.VoiceCommands.VoiceCommandServiceConnection"; }
};

template <> struct traits<Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage>
{
    using abi = ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.VoiceCommands.VoiceCommandUserMessage"; }
};

}

}
