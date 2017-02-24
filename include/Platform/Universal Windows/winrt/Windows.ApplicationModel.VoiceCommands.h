// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Storage.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Media.SpeechRecognition.3.h"
#include "internal/Windows.Globalization.3.h"
#include "internal/Windows.ApplicationModel.AppService.3.h"
#include "internal/Windows.ApplicationModel.VoiceCommands.3.h"
#include "Windows.ApplicationModel.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommand> : produce_base<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommand>
{
    HRESULT __stdcall get_CommandName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CommandName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Properties(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::Collections::IVectorView<hstring>>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Properties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SpeechRecognitionResult(impl::abi_arg_out<Windows::Media::SpeechRecognition::ISpeechRecognitionResult> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SpeechRecognitionResult());
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
struct produce<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandCompletedEventArgs> : produce_base<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandCompletedEventArgs>
{
    HRESULT __stdcall get_Reason(Windows::ApplicationModel::VoiceCommands::VoiceCommandCompletionReason * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Reason());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandConfirmationResult> : produce_base<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandConfirmationResult>
{
    HRESULT __stdcall get_Confirmed(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Confirmed());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandContentTile> : produce_base<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandContentTile>
{
    HRESULT __stdcall get_Title(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Title());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Title(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Title(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TextLine1(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TextLine1());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TextLine1(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TextLine1(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TextLine2(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TextLine2());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TextLine2(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TextLine2(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TextLine3(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TextLine3());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TextLine3(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TextLine3(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Image(impl::abi_arg_out<Windows::Storage::IStorageFile> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Image());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Image(impl::abi_arg_in<Windows::Storage::IStorageFile> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Image(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AppContext(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AppContext());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AppContext(impl::abi_arg_in<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AppContext(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AppLaunchArgument(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AppLaunchArgument());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AppLaunchArgument(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AppLaunchArgument(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContentTileType(Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTileType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentTileType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ContentTileType(Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTileType value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContentTileType(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandDefinition> : produce_base<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandDefinition>
{
    HRESULT __stdcall get_Language(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Language());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Name(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPhraseListAsync(impl::abi_arg_in<hstring> phraseListName, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> phraseList, impl::abi_arg_out<Windows::Foundation::IAsyncAction> updateAction) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *updateAction = detach_abi(this->shim().SetPhraseListAsync(*reinterpret_cast<const hstring *>(&phraseListName), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&phraseList)));
            return S_OK;
        }
        catch (...)
        {
            *updateAction = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandDefinitionManagerStatics> : produce_base<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandDefinitionManagerStatics>
{
    HRESULT __stdcall abi_InstallCommandDefinitionsFromStorageFileAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_out<Windows::Foundation::IAsyncAction> installAction) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *installAction = detach_abi(this->shim().InstallCommandDefinitionsFromStorageFileAsync(*reinterpret_cast<const Windows::Storage::StorageFile *>(&file)));
            return S_OK;
        }
        catch (...)
        {
            *installAction = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InstalledCommandDefinitions(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, Windows::ApplicationModel::VoiceCommands::VoiceCommandDefinition>> voiceCommandDefinitions) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *voiceCommandDefinitions = detach_abi(this->shim().InstalledCommandDefinitions());
            return S_OK;
        }
        catch (...)
        {
            *voiceCommandDefinitions = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandDisambiguationResult> : produce_base<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandDisambiguationResult>
{
    HRESULT __stdcall get_SelectedItem(impl::abi_arg_out<Windows::ApplicationModel::VoiceCommands::IVoiceCommandContentTile> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SelectedItem());
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
struct produce<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse> : produce_base<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse>
{
    HRESULT __stdcall get_Message(impl::abi_arg_out<Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Message());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Message(impl::abi_arg_in<Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Message(*reinterpret_cast<const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RepeatMessage(impl::abi_arg_out<Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RepeatMessage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RepeatMessage(impl::abi_arg_in<Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RepeatMessage(*reinterpret_cast<const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AppLaunchArgument(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AppLaunchArgument());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AppLaunchArgument(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AppLaunchArgument(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VoiceCommandContentTiles(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VoiceCommandContentTiles());
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
struct produce<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponseStatics> : produce_base<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponseStatics>
{
    HRESULT __stdcall get_MaxSupportedVoiceCommandContentTiles(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxSupportedVoiceCommandContentTiles());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateResponse(impl::abi_arg_in<Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage> userMessage, impl::abi_arg_out<Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse> response) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *response = detach_abi(this->shim().CreateResponse(*reinterpret_cast<const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage *>(&userMessage)));
            return S_OK;
        }
        catch (...)
        {
            *response = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateResponseWithTiles(impl::abi_arg_in<Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage> message, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile>> contentTiles, impl::abi_arg_out<Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse> response) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *response = detach_abi(this->shim().CreateResponse(*reinterpret_cast<const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage *>(&message), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile> *>(&contentTiles)));
            return S_OK;
        }
        catch (...)
        {
            *response = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateResponseForPrompt(impl::abi_arg_in<Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage> message, impl::abi_arg_in<Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage> repeatMessage, impl::abi_arg_out<Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse> response) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *response = detach_abi(this->shim().CreateResponseForPrompt(*reinterpret_cast<const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage *>(&message), *reinterpret_cast<const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage *>(&repeatMessage)));
            return S_OK;
        }
        catch (...)
        {
            *response = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateResponseForPromptWithTiles(impl::abi_arg_in<Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage> message, impl::abi_arg_in<Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage> repeatMessage, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile>> contentTiles, impl::abi_arg_out<Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse> response) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *response = detach_abi(this->shim().CreateResponseForPrompt(*reinterpret_cast<const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage *>(&message), *reinterpret_cast<const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage *>(&repeatMessage), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile> *>(&contentTiles)));
            return S_OK;
        }
        catch (...)
        {
            *response = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandServiceConnection> : produce_base<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandServiceConnection>
{
    HRESULT __stdcall abi_GetVoiceCommandAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::VoiceCommands::VoiceCommand>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetVoiceCommandAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestConfirmationAsync(impl::abi_arg_in<Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse> response, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::VoiceCommands::VoiceCommandConfirmationResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestConfirmationAsync(*reinterpret_cast<const Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse *>(&response)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestDisambiguationAsync(impl::abi_arg_in<Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse> response, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::VoiceCommands::VoiceCommandDisambiguationResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestDisambiguationAsync(*reinterpret_cast<const Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse *>(&response)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportProgressAsync(impl::abi_arg_in<Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse> response, impl::abi_arg_out<Windows::Foundation::IAsyncAction> action) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *action = detach_abi(this->shim().ReportProgressAsync(*reinterpret_cast<const Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse *>(&response)));
            return S_OK;
        }
        catch (...)
        {
            *action = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportSuccessAsync(impl::abi_arg_in<Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse> response, impl::abi_arg_out<Windows::Foundation::IAsyncAction> action) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *action = detach_abi(this->shim().ReportSuccessAsync(*reinterpret_cast<const Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse *>(&response)));
            return S_OK;
        }
        catch (...)
        {
            *action = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportFailureAsync(impl::abi_arg_in<Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse> response, impl::abi_arg_out<Windows::Foundation::IAsyncAction> action) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *action = detach_abi(this->shim().ReportFailureAsync(*reinterpret_cast<const Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse *>(&response)));
            return S_OK;
        }
        catch (...)
        {
            *action = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestAppLaunchAsync(impl::abi_arg_in<Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse> response, impl::abi_arg_out<Windows::Foundation::IAsyncAction> action) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *action = detach_abi(this->shim().RequestAppLaunchAsync(*reinterpret_cast<const Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse *>(&response)));
            return S_OK;
        }
        catch (...)
        {
            *action = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Language(impl::abi_arg_out<Windows::Globalization::ILanguage> language) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *language = detach_abi(this->shim().Language());
            return S_OK;
        }
        catch (...)
        {
            *language = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_VoiceCommandCompleted(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::VoiceCommands::VoiceCommandServiceConnection, Windows::ApplicationModel::VoiceCommands::VoiceCommandCompletedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().VoiceCommandCompleted(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::VoiceCommands::VoiceCommandServiceConnection, Windows::ApplicationModel::VoiceCommands::VoiceCommandCompletedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_VoiceCommandCompleted(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VoiceCommandCompleted(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandServiceConnectionStatics> : produce_base<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandServiceConnectionStatics>
{
    HRESULT __stdcall abi_FromAppServiceTriggerDetails(impl::abi_arg_in<Windows::ApplicationModel::AppService::IAppServiceTriggerDetails> triggerDetails, impl::abi_arg_out<Windows::ApplicationModel::VoiceCommands::IVoiceCommandServiceConnection> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FromAppServiceTriggerDetails(*reinterpret_cast<const Windows::ApplicationModel::AppService::AppServiceTriggerDetails *>(&triggerDetails)));
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
struct produce<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage> : produce_base<D, Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage>
{
    HRESULT __stdcall get_DisplayMessage(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayMessage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DisplayMessage(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayMessage(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SpokenMessage(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SpokenMessage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SpokenMessage(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SpokenMessage(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::ApplicationModel::VoiceCommands {

template <typename D> Windows::Foundation::IAsyncAction impl_IVoiceCommandDefinitionManagerStatics<D>::InstallCommandDefinitionsFromStorageFileAsync(const Windows::Storage::StorageFile & file) const
{
    Windows::Foundation::IAsyncAction installAction;
    check_hresult(WINRT_SHIM(IVoiceCommandDefinitionManagerStatics)->abi_InstallCommandDefinitionsFromStorageFileAsync(get_abi(file), put_abi(installAction)));
    return installAction;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::ApplicationModel::VoiceCommands::VoiceCommandDefinition> impl_IVoiceCommandDefinitionManagerStatics<D>::InstalledCommandDefinitions() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::ApplicationModel::VoiceCommands::VoiceCommandDefinition> voiceCommandDefinitions;
    check_hresult(WINRT_SHIM(IVoiceCommandDefinitionManagerStatics)->get_InstalledCommandDefinitions(put_abi(voiceCommandDefinitions)));
    return voiceCommandDefinitions;
}

template <typename D> hstring impl_IVoiceCommandDefinition<D>::Language() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVoiceCommandDefinition)->get_Language(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IVoiceCommandDefinition<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVoiceCommandDefinition)->get_Name(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IVoiceCommandDefinition<D>::SetPhraseListAsync(hstring_view phraseListName, iterable<hstring> phraseList) const
{
    Windows::Foundation::IAsyncAction updateAction;
    check_hresult(WINRT_SHIM(IVoiceCommandDefinition)->abi_SetPhraseListAsync(get_abi(phraseListName), get_abi(phraseList), put_abi(updateAction)));
    return updateAction;
}

template <typename D> hstring impl_IVoiceCommandContentTile<D>::Title() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVoiceCommandContentTile)->get_Title(put_abi(value)));
    return value;
}

template <typename D> void impl_IVoiceCommandContentTile<D>::Title(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IVoiceCommandContentTile)->put_Title(get_abi(value)));
}

template <typename D> hstring impl_IVoiceCommandContentTile<D>::TextLine1() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVoiceCommandContentTile)->get_TextLine1(put_abi(value)));
    return value;
}

template <typename D> void impl_IVoiceCommandContentTile<D>::TextLine1(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IVoiceCommandContentTile)->put_TextLine1(get_abi(value)));
}

template <typename D> hstring impl_IVoiceCommandContentTile<D>::TextLine2() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVoiceCommandContentTile)->get_TextLine2(put_abi(value)));
    return value;
}

template <typename D> void impl_IVoiceCommandContentTile<D>::TextLine2(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IVoiceCommandContentTile)->put_TextLine2(get_abi(value)));
}

template <typename D> hstring impl_IVoiceCommandContentTile<D>::TextLine3() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVoiceCommandContentTile)->get_TextLine3(put_abi(value)));
    return value;
}

template <typename D> void impl_IVoiceCommandContentTile<D>::TextLine3(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IVoiceCommandContentTile)->put_TextLine3(get_abi(value)));
}

template <typename D> Windows::Storage::IStorageFile impl_IVoiceCommandContentTile<D>::Image() const
{
    Windows::Storage::IStorageFile value;
    check_hresult(WINRT_SHIM(IVoiceCommandContentTile)->get_Image(put_abi(value)));
    return value;
}

template <typename D> void impl_IVoiceCommandContentTile<D>::Image(const Windows::Storage::IStorageFile & value) const
{
    check_hresult(WINRT_SHIM(IVoiceCommandContentTile)->put_Image(get_abi(value)));
}

template <typename D> Windows::Foundation::IInspectable impl_IVoiceCommandContentTile<D>::AppContext() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IVoiceCommandContentTile)->get_AppContext(put_abi(value)));
    return value;
}

template <typename D> void impl_IVoiceCommandContentTile<D>::AppContext(const Windows::Foundation::IInspectable & value) const
{
    check_hresult(WINRT_SHIM(IVoiceCommandContentTile)->put_AppContext(get_abi(value)));
}

template <typename D> hstring impl_IVoiceCommandContentTile<D>::AppLaunchArgument() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVoiceCommandContentTile)->get_AppLaunchArgument(put_abi(value)));
    return value;
}

template <typename D> void impl_IVoiceCommandContentTile<D>::AppLaunchArgument(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IVoiceCommandContentTile)->put_AppLaunchArgument(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTileType impl_IVoiceCommandContentTile<D>::ContentTileType() const
{
    Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTileType value {};
    check_hresult(WINRT_SHIM(IVoiceCommandContentTile)->get_ContentTileType(&value));
    return value;
}

template <typename D> void impl_IVoiceCommandContentTile<D>::ContentTileType(Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTileType value) const
{
    check_hresult(WINRT_SHIM(IVoiceCommandContentTile)->put_ContentTileType(value));
}

template <typename D> hstring impl_IVoiceCommandUserMessage<D>::DisplayMessage() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVoiceCommandUserMessage)->get_DisplayMessage(put_abi(value)));
    return value;
}

template <typename D> void impl_IVoiceCommandUserMessage<D>::DisplayMessage(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IVoiceCommandUserMessage)->put_DisplayMessage(get_abi(value)));
}

template <typename D> hstring impl_IVoiceCommandUserMessage<D>::SpokenMessage() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVoiceCommandUserMessage)->get_SpokenMessage(put_abi(value)));
    return value;
}

template <typename D> void impl_IVoiceCommandUserMessage<D>::SpokenMessage(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IVoiceCommandUserMessage)->put_SpokenMessage(get_abi(value)));
}

template <typename D> hstring impl_IVoiceCommand<D>::CommandName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVoiceCommand)->get_CommandName(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::Collections::IVectorView<hstring>> impl_IVoiceCommand<D>::Properties() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::Collections::IVectorView<hstring>> value;
    check_hresult(WINRT_SHIM(IVoiceCommand)->get_Properties(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::SpeechRecognition::SpeechRecognitionResult impl_IVoiceCommand<D>::SpeechRecognitionResult() const
{
    Windows::Media::SpeechRecognition::SpeechRecognitionResult value { nullptr };
    check_hresult(WINRT_SHIM(IVoiceCommand)->get_SpeechRecognitionResult(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::VoiceCommands::VoiceCommandCompletionReason impl_IVoiceCommandCompletedEventArgs<D>::Reason() const
{
    Windows::ApplicationModel::VoiceCommands::VoiceCommandCompletionReason value {};
    check_hresult(WINRT_SHIM(IVoiceCommandCompletedEventArgs)->get_Reason(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile impl_IVoiceCommandDisambiguationResult<D>::SelectedItem() const
{
    Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile value { nullptr };
    check_hresult(WINRT_SHIM(IVoiceCommandDisambiguationResult)->get_SelectedItem(put_abi(value)));
    return value;
}

template <typename D> bool impl_IVoiceCommandConfirmationResult<D>::Confirmed() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IVoiceCommandConfirmationResult)->get_Confirmed(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::VoiceCommands::VoiceCommand> impl_IVoiceCommandServiceConnection<D>::GetVoiceCommandAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::VoiceCommands::VoiceCommand> operation;
    check_hresult(WINRT_SHIM(IVoiceCommandServiceConnection)->abi_GetVoiceCommandAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::VoiceCommands::VoiceCommandConfirmationResult> impl_IVoiceCommandServiceConnection<D>::RequestConfirmationAsync(const Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse & response) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::VoiceCommands::VoiceCommandConfirmationResult> operation;
    check_hresult(WINRT_SHIM(IVoiceCommandServiceConnection)->abi_RequestConfirmationAsync(get_abi(response), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::VoiceCommands::VoiceCommandDisambiguationResult> impl_IVoiceCommandServiceConnection<D>::RequestDisambiguationAsync(const Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse & response) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::VoiceCommands::VoiceCommandDisambiguationResult> operation;
    check_hresult(WINRT_SHIM(IVoiceCommandServiceConnection)->abi_RequestDisambiguationAsync(get_abi(response), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IVoiceCommandServiceConnection<D>::ReportProgressAsync(const Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse & response) const
{
    Windows::Foundation::IAsyncAction action;
    check_hresult(WINRT_SHIM(IVoiceCommandServiceConnection)->abi_ReportProgressAsync(get_abi(response), put_abi(action)));
    return action;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IVoiceCommandServiceConnection<D>::ReportSuccessAsync(const Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse & response) const
{
    Windows::Foundation::IAsyncAction action;
    check_hresult(WINRT_SHIM(IVoiceCommandServiceConnection)->abi_ReportSuccessAsync(get_abi(response), put_abi(action)));
    return action;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IVoiceCommandServiceConnection<D>::ReportFailureAsync(const Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse & response) const
{
    Windows::Foundation::IAsyncAction action;
    check_hresult(WINRT_SHIM(IVoiceCommandServiceConnection)->abi_ReportFailureAsync(get_abi(response), put_abi(action)));
    return action;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IVoiceCommandServiceConnection<D>::RequestAppLaunchAsync(const Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse & response) const
{
    Windows::Foundation::IAsyncAction action;
    check_hresult(WINRT_SHIM(IVoiceCommandServiceConnection)->abi_RequestAppLaunchAsync(get_abi(response), put_abi(action)));
    return action;
}

template <typename D> Windows::Globalization::Language impl_IVoiceCommandServiceConnection<D>::Language() const
{
    Windows::Globalization::Language language { nullptr };
    check_hresult(WINRT_SHIM(IVoiceCommandServiceConnection)->get_Language(put_abi(language)));
    return language;
}

template <typename D> event_token impl_IVoiceCommandServiceConnection<D>::VoiceCommandCompleted(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::VoiceCommands::VoiceCommandServiceConnection, Windows::ApplicationModel::VoiceCommands::VoiceCommandCompletedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IVoiceCommandServiceConnection)->add_VoiceCommandCompleted(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IVoiceCommandServiceConnection> impl_IVoiceCommandServiceConnection<D>::VoiceCommandCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::VoiceCommands::VoiceCommandServiceConnection, Windows::ApplicationModel::VoiceCommands::VoiceCommandCompletedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IVoiceCommandServiceConnection>(this, &ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandServiceConnection::remove_VoiceCommandCompleted, VoiceCommandCompleted(handler));
}

template <typename D> void impl_IVoiceCommandServiceConnection<D>::VoiceCommandCompleted(event_token token) const
{
    check_hresult(WINRT_SHIM(IVoiceCommandServiceConnection)->remove_VoiceCommandCompleted(token));
}

template <typename D> Windows::ApplicationModel::VoiceCommands::VoiceCommandServiceConnection impl_IVoiceCommandServiceConnectionStatics<D>::FromAppServiceTriggerDetails(const Windows::ApplicationModel::AppService::AppServiceTriggerDetails & triggerDetails) const
{
    Windows::ApplicationModel::VoiceCommands::VoiceCommandServiceConnection value { nullptr };
    check_hresult(WINRT_SHIM(IVoiceCommandServiceConnectionStatics)->abi_FromAppServiceTriggerDetails(get_abi(triggerDetails), put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IVoiceCommandResponseStatics<D>::MaxSupportedVoiceCommandContentTiles() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IVoiceCommandResponseStatics)->get_MaxSupportedVoiceCommandContentTiles(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse impl_IVoiceCommandResponseStatics<D>::CreateResponse(const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & userMessage) const
{
    Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse response { nullptr };
    check_hresult(WINRT_SHIM(IVoiceCommandResponseStatics)->abi_CreateResponse(get_abi(userMessage), put_abi(response)));
    return response;
}

template <typename D> Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse impl_IVoiceCommandResponseStatics<D>::CreateResponse(const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & message, iterable<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile> contentTiles) const
{
    Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse response { nullptr };
    check_hresult(WINRT_SHIM(IVoiceCommandResponseStatics)->abi_CreateResponseWithTiles(get_abi(message), get_abi(contentTiles), put_abi(response)));
    return response;
}

template <typename D> Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse impl_IVoiceCommandResponseStatics<D>::CreateResponseForPrompt(const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & message, const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & repeatMessage) const
{
    Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse response { nullptr };
    check_hresult(WINRT_SHIM(IVoiceCommandResponseStatics)->abi_CreateResponseForPrompt(get_abi(message), get_abi(repeatMessage), put_abi(response)));
    return response;
}

template <typename D> Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse impl_IVoiceCommandResponseStatics<D>::CreateResponseForPrompt(const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & message, const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & repeatMessage, iterable<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile> contentTiles) const
{
    Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse response { nullptr };
    check_hresult(WINRT_SHIM(IVoiceCommandResponseStatics)->abi_CreateResponseForPromptWithTiles(get_abi(message), get_abi(repeatMessage), get_abi(contentTiles), put_abi(response)));
    return response;
}

template <typename D> Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage impl_IVoiceCommandResponse<D>::Message() const
{
    Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage value { nullptr };
    check_hresult(WINRT_SHIM(IVoiceCommandResponse)->get_Message(put_abi(value)));
    return value;
}

template <typename D> void impl_IVoiceCommandResponse<D>::Message(const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & value) const
{
    check_hresult(WINRT_SHIM(IVoiceCommandResponse)->put_Message(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage impl_IVoiceCommandResponse<D>::RepeatMessage() const
{
    Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage value { nullptr };
    check_hresult(WINRT_SHIM(IVoiceCommandResponse)->get_RepeatMessage(put_abi(value)));
    return value;
}

template <typename D> void impl_IVoiceCommandResponse<D>::RepeatMessage(const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & value) const
{
    check_hresult(WINRT_SHIM(IVoiceCommandResponse)->put_RepeatMessage(get_abi(value)));
}

template <typename D> hstring impl_IVoiceCommandResponse<D>::AppLaunchArgument() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVoiceCommandResponse)->get_AppLaunchArgument(put_abi(value)));
    return value;
}

template <typename D> void impl_IVoiceCommandResponse<D>::AppLaunchArgument(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IVoiceCommandResponse)->put_AppLaunchArgument(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile> impl_IVoiceCommandResponse<D>::VoiceCommandContentTiles() const
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile> value;
    check_hresult(WINRT_SHIM(IVoiceCommandResponse)->get_VoiceCommandContentTiles(put_abi(value)));
    return value;
}

inline VoiceCommandContentTile::VoiceCommandContentTile() :
    VoiceCommandContentTile(activate_instance<VoiceCommandContentTile>())
{}

inline Windows::Foundation::IAsyncAction VoiceCommandDefinitionManager::InstallCommandDefinitionsFromStorageFileAsync(const Windows::Storage::StorageFile & file)
{
    return get_activation_factory<VoiceCommandDefinitionManager, IVoiceCommandDefinitionManagerStatics>().InstallCommandDefinitionsFromStorageFileAsync(file);
}

inline Windows::Foundation::Collections::IMapView<hstring, Windows::ApplicationModel::VoiceCommands::VoiceCommandDefinition> VoiceCommandDefinitionManager::InstalledCommandDefinitions()
{
    return get_activation_factory<VoiceCommandDefinitionManager, IVoiceCommandDefinitionManagerStatics>().InstalledCommandDefinitions();
}

inline uint32_t VoiceCommandResponse::MaxSupportedVoiceCommandContentTiles()
{
    return get_activation_factory<VoiceCommandResponse, IVoiceCommandResponseStatics>().MaxSupportedVoiceCommandContentTiles();
}

inline Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse VoiceCommandResponse::CreateResponse(const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & userMessage)
{
    return get_activation_factory<VoiceCommandResponse, IVoiceCommandResponseStatics>().CreateResponse(userMessage);
}

inline Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse VoiceCommandResponse::CreateResponse(const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & message, iterable<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile> contentTiles)
{
    return get_activation_factory<VoiceCommandResponse, IVoiceCommandResponseStatics>().CreateResponse(message, contentTiles);
}

inline Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse VoiceCommandResponse::CreateResponseForPrompt(const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & message, const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & repeatMessage)
{
    return get_activation_factory<VoiceCommandResponse, IVoiceCommandResponseStatics>().CreateResponseForPrompt(message, repeatMessage);
}

inline Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse VoiceCommandResponse::CreateResponseForPrompt(const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & message, const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & repeatMessage, iterable<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile> contentTiles)
{
    return get_activation_factory<VoiceCommandResponse, IVoiceCommandResponseStatics>().CreateResponseForPrompt(message, repeatMessage, contentTiles);
}

inline Windows::ApplicationModel::VoiceCommands::VoiceCommandServiceConnection VoiceCommandServiceConnection::FromAppServiceTriggerDetails(const Windows::ApplicationModel::AppService::AppServiceTriggerDetails & triggerDetails)
{
    return get_activation_factory<VoiceCommandServiceConnection, IVoiceCommandServiceConnectionStatics>().FromAppServiceTriggerDetails(triggerDetails);
}

inline VoiceCommandUserMessage::VoiceCommandUserMessage() :
    VoiceCommandUserMessage(activate_instance<VoiceCommandUserMessage>())
{}

}

}
#pragma warning(pop)
