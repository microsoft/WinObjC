// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.VoiceCommands.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::VoiceCommands {

struct WINRT_EBO VoiceCommand :
    Windows::ApplicationModel::VoiceCommands::IVoiceCommand
{
    VoiceCommand(std::nullptr_t) noexcept {}
};

struct WINRT_EBO VoiceCommandCompletedEventArgs :
    Windows::ApplicationModel::VoiceCommands::IVoiceCommandCompletedEventArgs
{
    VoiceCommandCompletedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO VoiceCommandConfirmationResult :
    Windows::ApplicationModel::VoiceCommands::IVoiceCommandConfirmationResult
{
    VoiceCommandConfirmationResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO VoiceCommandContentTile :
    Windows::ApplicationModel::VoiceCommands::IVoiceCommandContentTile
{
    VoiceCommandContentTile(std::nullptr_t) noexcept {}
    VoiceCommandContentTile();
};

struct WINRT_EBO VoiceCommandDefinition :
    Windows::ApplicationModel::VoiceCommands::IVoiceCommandDefinition
{
    VoiceCommandDefinition(std::nullptr_t) noexcept {}
};

struct VoiceCommandDefinitionManager
{
    VoiceCommandDefinitionManager() = delete;
    static Windows::Foundation::IAsyncAction InstallCommandDefinitionsFromStorageFileAsync(const Windows::Storage::StorageFile & file);
    static Windows::Foundation::Collections::IMapView<hstring, Windows::ApplicationModel::VoiceCommands::VoiceCommandDefinition> InstalledCommandDefinitions();
};

struct WINRT_EBO VoiceCommandDisambiguationResult :
    Windows::ApplicationModel::VoiceCommands::IVoiceCommandDisambiguationResult
{
    VoiceCommandDisambiguationResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO VoiceCommandResponse :
    Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse
{
    VoiceCommandResponse(std::nullptr_t) noexcept {}
    static uint32_t MaxSupportedVoiceCommandContentTiles();
    static Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse CreateResponse(const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & userMessage);
    static Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse CreateResponse(const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & message, iterable<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile> contentTiles);
    static Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse CreateResponseForPrompt(const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & message, const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & repeatMessage);
    static Windows::ApplicationModel::VoiceCommands::VoiceCommandResponse CreateResponseForPrompt(const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & message, const Windows::ApplicationModel::VoiceCommands::VoiceCommandUserMessage & repeatMessage, iterable<Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile> contentTiles);
};

struct WINRT_EBO VoiceCommandServiceConnection :
    Windows::ApplicationModel::VoiceCommands::IVoiceCommandServiceConnection
{
    VoiceCommandServiceConnection(std::nullptr_t) noexcept {}
    static Windows::ApplicationModel::VoiceCommands::VoiceCommandServiceConnection FromAppServiceTriggerDetails(const Windows::ApplicationModel::AppService::AppServiceTriggerDetails & triggerDetails);
};

struct WINRT_EBO VoiceCommandUserMessage :
    Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage
{
    VoiceCommandUserMessage(std::nullptr_t) noexcept {}
    VoiceCommandUserMessage();
};

}

}
