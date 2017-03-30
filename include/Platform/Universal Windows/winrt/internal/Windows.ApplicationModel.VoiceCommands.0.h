// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::VoiceCommands {

struct IVoiceCommand;
struct IVoiceCommandCompletedEventArgs;
struct IVoiceCommandConfirmationResult;
struct IVoiceCommandContentTile;
struct IVoiceCommandDefinition;
struct IVoiceCommandDefinitionManagerStatics;
struct IVoiceCommandDisambiguationResult;
struct IVoiceCommandResponse;
struct IVoiceCommandResponseStatics;
struct IVoiceCommandServiceConnection;
struct IVoiceCommandServiceConnectionStatics;
struct IVoiceCommandUserMessage;
struct VoiceCommand;
struct VoiceCommandCompletedEventArgs;
struct VoiceCommandConfirmationResult;
struct VoiceCommandContentTile;
struct VoiceCommandDefinition;
struct VoiceCommandDisambiguationResult;
struct VoiceCommandResponse;
struct VoiceCommandServiceConnection;
struct VoiceCommandUserMessage;

}

namespace Windows::ApplicationModel::VoiceCommands {

struct IVoiceCommand;
struct IVoiceCommandCompletedEventArgs;
struct IVoiceCommandConfirmationResult;
struct IVoiceCommandContentTile;
struct IVoiceCommandDefinition;
struct IVoiceCommandDefinitionManagerStatics;
struct IVoiceCommandDisambiguationResult;
struct IVoiceCommandResponse;
struct IVoiceCommandResponseStatics;
struct IVoiceCommandServiceConnection;
struct IVoiceCommandServiceConnectionStatics;
struct IVoiceCommandUserMessage;
struct VoiceCommand;
struct VoiceCommandCompletedEventArgs;
struct VoiceCommandConfirmationResult;
struct VoiceCommandContentTile;
struct VoiceCommandDefinition;
struct VoiceCommandDefinitionManager;
struct VoiceCommandDisambiguationResult;
struct VoiceCommandResponse;
struct VoiceCommandServiceConnection;
struct VoiceCommandUserMessage;

}

namespace Windows::ApplicationModel::VoiceCommands {

template <typename T> struct impl_IVoiceCommand;
template <typename T> struct impl_IVoiceCommandCompletedEventArgs;
template <typename T> struct impl_IVoiceCommandConfirmationResult;
template <typename T> struct impl_IVoiceCommandContentTile;
template <typename T> struct impl_IVoiceCommandDefinition;
template <typename T> struct impl_IVoiceCommandDefinitionManagerStatics;
template <typename T> struct impl_IVoiceCommandDisambiguationResult;
template <typename T> struct impl_IVoiceCommandResponse;
template <typename T> struct impl_IVoiceCommandResponseStatics;
template <typename T> struct impl_IVoiceCommandServiceConnection;
template <typename T> struct impl_IVoiceCommandServiceConnectionStatics;
template <typename T> struct impl_IVoiceCommandUserMessage;

}

namespace Windows::ApplicationModel::VoiceCommands {

enum class VoiceCommandCompletionReason
{
    Unknown = 0,
    CommunicationFailed = 1,
    ResourceLimitsExceeded = 2,
    Canceled = 3,
    TimeoutExceeded = 4,
    AppLaunched = 5,
    Completed = 6,
};

enum class VoiceCommandContentTileType
{
    TitleOnly = 0,
    TitleWithText = 1,
    TitleWith68x68Icon = 2,
    TitleWith68x68IconAndText = 3,
    TitleWith68x92Icon = 4,
    TitleWith68x92IconAndText = 5,
    TitleWith280x140Icon = 6,
    TitleWith280x140IconAndText = 7,
};

}

}
