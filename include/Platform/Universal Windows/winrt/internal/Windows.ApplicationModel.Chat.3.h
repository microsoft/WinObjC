// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.Chat.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::Chat {

struct WINRT_EBO ChatCapabilities :
    Windows::ApplicationModel::Chat::IChatCapabilities
{
    ChatCapabilities(std::nullptr_t) noexcept {}
};

struct ChatCapabilitiesManager
{
    ChatCapabilitiesManager() = delete;
    static Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatCapabilities> GetCachedCapabilitiesAsync(hstring_view address);
    static Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatCapabilities> GetCapabilitiesFromNetworkAsync(hstring_view address);
};

struct WINRT_EBO ChatConversation :
    Windows::ApplicationModel::Chat::IChatConversation,
    impl::require<ChatConversation, Windows::ApplicationModel::Chat::IChatItem, Windows::ApplicationModel::Chat::IChatConversation2>
{
    ChatConversation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ChatConversationReader :
    Windows::ApplicationModel::Chat::IChatConversationReader
{
    ChatConversationReader(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ChatConversationThreadingInfo :
    Windows::ApplicationModel::Chat::IChatConversationThreadingInfo
{
    ChatConversationThreadingInfo(std::nullptr_t) noexcept {}
    ChatConversationThreadingInfo();
};

struct WINRT_EBO ChatMessage :
    Windows::ApplicationModel::Chat::IChatMessage,
    impl::require<ChatMessage, Windows::ApplicationModel::Chat::IChatMessage3, Windows::ApplicationModel::Chat::IChatMessage2, Windows::ApplicationModel::Chat::IChatMessage4, Windows::ApplicationModel::Chat::IChatItem>
{
    ChatMessage(std::nullptr_t) noexcept {}
    ChatMessage();
    using impl_IChatMessage::From;
    using impl_IChatMessage::IsForwardingDisabled;
    using impl_IChatMessage::IsIncoming;
    using impl_IChatMessage::IsRead;
    using impl_IChatMessage::LocalTimestamp;
    using impl_IChatMessage::NetworkTimestamp;
    using impl_IChatMessage::Status;
    using impl_IChatMessage::Subject;
    using impl_IChatMessage2::From;
    using impl_IChatMessage2::IsForwardingDisabled;
    using impl_IChatMessage2::IsIncoming;
    using impl_IChatMessage2::IsRead;
    using impl_IChatMessage2::LocalTimestamp;
    using impl_IChatMessage2::NetworkTimestamp;
    using impl_IChatMessage2::RemoteId;
    using impl_IChatMessage2::Status;
    using impl_IChatMessage2::Subject;
    using impl_IChatMessage3::RemoteId;
};

struct WINRT_EBO ChatMessageAttachment :
    Windows::ApplicationModel::Chat::IChatMessageAttachment,
    impl::require<ChatMessageAttachment, Windows::ApplicationModel::Chat::IChatMessageAttachment2>
{
    ChatMessageAttachment(std::nullptr_t) noexcept {}
    ChatMessageAttachment(hstring_view mimeType, const Windows::Storage::Streams::IRandomAccessStreamReference & dataStreamReference);
};

struct ChatMessageBlocking
{
    ChatMessageBlocking() = delete;
    static Windows::Foundation::IAsyncAction MarkMessageAsBlockedAsync(hstring_view localChatMessageId, bool blocked);
};

struct WINRT_EBO ChatMessageChange :
    Windows::ApplicationModel::Chat::IChatMessageChange
{
    ChatMessageChange(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ChatMessageChangeReader :
    Windows::ApplicationModel::Chat::IChatMessageChangeReader
{
    ChatMessageChangeReader(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ChatMessageChangeTracker :
    Windows::ApplicationModel::Chat::IChatMessageChangeTracker
{
    ChatMessageChangeTracker(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ChatMessageChangedDeferral :
    Windows::ApplicationModel::Chat::IChatMessageChangedDeferral
{
    ChatMessageChangedDeferral(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ChatMessageChangedEventArgs :
    Windows::ApplicationModel::Chat::IChatMessageChangedEventArgs
{
    ChatMessageChangedEventArgs(std::nullptr_t) noexcept {}
};

struct ChatMessageManager
{
    ChatMessageManager() = delete;
    static Windows::Foundation::IAsyncOperation<hstring> RegisterTransportAsync();
    static Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatMessageTransport> GetTransportAsync(hstring_view transportId);
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::ChatMessageTransport>> GetTransportsAsync();
    static Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatMessageStore> RequestStoreAsync();
    static Windows::Foundation::IAsyncAction ShowComposeSmsMessageAsync(const Windows::ApplicationModel::Chat::ChatMessage & message);
    static void ShowSmsSettings();
    static Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatSyncManager> RequestSyncManagerAsync();
};

struct WINRT_EBO ChatMessageNotificationTriggerDetails :
    Windows::ApplicationModel::Chat::IChatMessageNotificationTriggerDetails,
    impl::require<ChatMessageNotificationTriggerDetails, Windows::ApplicationModel::Chat::IChatMessageNotificationTriggerDetails2>
{
    ChatMessageNotificationTriggerDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ChatMessageReader :
    Windows::ApplicationModel::Chat::IChatMessageReader,
    impl::require<ChatMessageReader, Windows::ApplicationModel::Chat::IChatMessageReader2>
{
    ChatMessageReader(std::nullptr_t) noexcept {}
    using impl_IChatMessageReader::ReadBatchAsync;
    using impl_IChatMessageReader2::ReadBatchAsync;
};

struct WINRT_EBO ChatMessageStore :
    Windows::ApplicationModel::Chat::IChatMessageStore,
    impl::require<ChatMessageStore, Windows::ApplicationModel::Chat::IChatMessageStore2, Windows::ApplicationModel::Chat::IChatMessageStore3>
{
    ChatMessageStore(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ChatMessageStoreChangedEventArgs :
    Windows::ApplicationModel::Chat::IChatMessageStoreChangedEventArgs
{
    ChatMessageStoreChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ChatMessageTransport :
    Windows::ApplicationModel::Chat::IChatMessageTransport,
    impl::require<ChatMessageTransport, Windows::ApplicationModel::Chat::IChatMessageTransport2>
{
    ChatMessageTransport(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ChatMessageTransportConfiguration :
    Windows::ApplicationModel::Chat::IChatMessageTransportConfiguration
{
    ChatMessageTransportConfiguration(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ChatMessageValidationResult :
    Windows::ApplicationModel::Chat::IChatMessageValidationResult
{
    ChatMessageValidationResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ChatQueryOptions :
    Windows::ApplicationModel::Chat::IChatQueryOptions
{
    ChatQueryOptions(std::nullptr_t) noexcept {}
    ChatQueryOptions();
};

struct WINRT_EBO ChatRecipientDeliveryInfo :
    Windows::ApplicationModel::Chat::IChatRecipientDeliveryInfo
{
    ChatRecipientDeliveryInfo(std::nullptr_t) noexcept {}
    ChatRecipientDeliveryInfo();
};

struct WINRT_EBO ChatSearchReader :
    Windows::ApplicationModel::Chat::IChatSearchReader
{
    ChatSearchReader(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ChatSyncConfiguration :
    Windows::ApplicationModel::Chat::IChatSyncConfiguration
{
    ChatSyncConfiguration(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ChatSyncManager :
    Windows::ApplicationModel::Chat::IChatSyncManager
{
    ChatSyncManager(std::nullptr_t) noexcept {}
};

struct WINRT_EBO RcsEndUserMessage :
    Windows::ApplicationModel::Chat::IRcsEndUserMessage
{
    RcsEndUserMessage(std::nullptr_t) noexcept {}
};

struct WINRT_EBO RcsEndUserMessageAction :
    Windows::ApplicationModel::Chat::IRcsEndUserMessageAction
{
    RcsEndUserMessageAction(std::nullptr_t) noexcept {}
};

struct WINRT_EBO RcsEndUserMessageAvailableEventArgs :
    Windows::ApplicationModel::Chat::IRcsEndUserMessageAvailableEventArgs
{
    RcsEndUserMessageAvailableEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO RcsEndUserMessageAvailableTriggerDetails :
    Windows::ApplicationModel::Chat::IRcsEndUserMessageAvailableTriggerDetails
{
    RcsEndUserMessageAvailableTriggerDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO RcsEndUserMessageManager :
    Windows::ApplicationModel::Chat::IRcsEndUserMessageManager
{
    RcsEndUserMessageManager(std::nullptr_t) noexcept {}
};

struct RcsManager
{
    RcsManager() = delete;
    static Windows::ApplicationModel::Chat::RcsEndUserMessageManager GetEndUserMessageManager();
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::RcsTransport>> GetTransportsAsync();
    static Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::RcsTransport> GetTransportAsync(hstring_view transportId);
    static Windows::Foundation::IAsyncAction LeaveConversationAsync(const Windows::ApplicationModel::Chat::ChatConversation & conversation);
};

struct WINRT_EBO RcsServiceKindSupportedChangedEventArgs :
    Windows::ApplicationModel::Chat::IRcsServiceKindSupportedChangedEventArgs
{
    RcsServiceKindSupportedChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO RcsTransport :
    Windows::ApplicationModel::Chat::IRcsTransport
{
    RcsTransport(std::nullptr_t) noexcept {}
};

struct WINRT_EBO RcsTransportConfiguration :
    Windows::ApplicationModel::Chat::IRcsTransportConfiguration
{
    RcsTransportConfiguration(std::nullptr_t) noexcept {}
};

struct WINRT_EBO RemoteParticipantComposingChangedEventArgs :
    Windows::ApplicationModel::Chat::IRemoteParticipantComposingChangedEventArgs
{
    RemoteParticipantComposingChangedEventArgs(std::nullptr_t) noexcept {}
};

}

}
