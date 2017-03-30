// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::Chat {

struct IChatCapabilities;
struct IChatCapabilitiesManagerStatics;
struct IChatConversation;
struct IChatConversation2;
struct IChatConversationReader;
struct IChatConversationThreadingInfo;
struct IChatItem;
struct IChatMessage;
struct IChatMessage2;
struct IChatMessage3;
struct IChatMessage4;
struct IChatMessageAttachment;
struct IChatMessageAttachment2;
struct IChatMessageAttachmentFactory;
struct IChatMessageBlockingStatic;
struct IChatMessageChange;
struct IChatMessageChangeReader;
struct IChatMessageChangeTracker;
struct IChatMessageChangedDeferral;
struct IChatMessageChangedEventArgs;
struct IChatMessageManager2Statics;
struct IChatMessageManagerStatic;
struct IChatMessageManagerStatics3;
struct IChatMessageNotificationTriggerDetails;
struct IChatMessageNotificationTriggerDetails2;
struct IChatMessageReader;
struct IChatMessageReader2;
struct IChatMessageStore;
struct IChatMessageStore2;
struct IChatMessageStore3;
struct IChatMessageStoreChangedEventArgs;
struct IChatMessageTransport;
struct IChatMessageTransport2;
struct IChatMessageTransportConfiguration;
struct IChatMessageValidationResult;
struct IChatQueryOptions;
struct IChatRecipientDeliveryInfo;
struct IChatSearchReader;
struct IChatSyncConfiguration;
struct IChatSyncManager;
struct IRcsEndUserMessage;
struct IRcsEndUserMessageAction;
struct IRcsEndUserMessageAvailableEventArgs;
struct IRcsEndUserMessageAvailableTriggerDetails;
struct IRcsEndUserMessageManager;
struct IRcsManagerStatics;
struct IRcsServiceKindSupportedChangedEventArgs;
struct IRcsTransport;
struct IRcsTransportConfiguration;
struct IRemoteParticipantComposingChangedEventArgs;
struct ChatCapabilities;
struct ChatConversation;
struct ChatConversationReader;
struct ChatConversationThreadingInfo;
struct ChatMessage;
struct ChatMessageAttachment;
struct ChatMessageChange;
struct ChatMessageChangeReader;
struct ChatMessageChangeTracker;
struct ChatMessageChangedDeferral;
struct ChatMessageChangedEventArgs;
struct ChatMessageNotificationTriggerDetails;
struct ChatMessageReader;
struct ChatMessageStore;
struct ChatMessageStoreChangedEventArgs;
struct ChatMessageTransport;
struct ChatMessageTransportConfiguration;
struct ChatMessageValidationResult;
struct ChatQueryOptions;
struct ChatRecipientDeliveryInfo;
struct ChatSearchReader;
struct ChatSyncConfiguration;
struct ChatSyncManager;
struct RcsEndUserMessage;
struct RcsEndUserMessageAction;
struct RcsEndUserMessageAvailableEventArgs;
struct RcsEndUserMessageAvailableTriggerDetails;
struct RcsEndUserMessageManager;
struct RcsServiceKindSupportedChangedEventArgs;
struct RcsTransport;
struct RcsTransportConfiguration;
struct RemoteParticipantComposingChangedEventArgs;

}

namespace Windows::ApplicationModel::Chat {

struct IChatCapabilities;
struct IChatCapabilitiesManagerStatics;
struct IChatConversation;
struct IChatConversation2;
struct IChatConversationReader;
struct IChatConversationThreadingInfo;
struct IChatItem;
struct IChatMessage;
struct IChatMessage2;
struct IChatMessage3;
struct IChatMessage4;
struct IChatMessageAttachment;
struct IChatMessageAttachment2;
struct IChatMessageAttachmentFactory;
struct IChatMessageBlockingStatic;
struct IChatMessageChange;
struct IChatMessageChangeReader;
struct IChatMessageChangeTracker;
struct IChatMessageChangedDeferral;
struct IChatMessageChangedEventArgs;
struct IChatMessageManager2Statics;
struct IChatMessageManagerStatic;
struct IChatMessageManagerStatics3;
struct IChatMessageNotificationTriggerDetails;
struct IChatMessageNotificationTriggerDetails2;
struct IChatMessageReader;
struct IChatMessageReader2;
struct IChatMessageStore;
struct IChatMessageStore2;
struct IChatMessageStore3;
struct IChatMessageStoreChangedEventArgs;
struct IChatMessageTransport;
struct IChatMessageTransport2;
struct IChatMessageTransportConfiguration;
struct IChatMessageValidationResult;
struct IChatQueryOptions;
struct IChatRecipientDeliveryInfo;
struct IChatSearchReader;
struct IChatSyncConfiguration;
struct IChatSyncManager;
struct IRcsEndUserMessage;
struct IRcsEndUserMessageAction;
struct IRcsEndUserMessageAvailableEventArgs;
struct IRcsEndUserMessageAvailableTriggerDetails;
struct IRcsEndUserMessageManager;
struct IRcsManagerStatics;
struct IRcsServiceKindSupportedChangedEventArgs;
struct IRcsTransport;
struct IRcsTransportConfiguration;
struct IRemoteParticipantComposingChangedEventArgs;
struct ChatCapabilities;
struct ChatCapabilitiesManager;
struct ChatConversation;
struct ChatConversationReader;
struct ChatConversationThreadingInfo;
struct ChatMessage;
struct ChatMessageAttachment;
struct ChatMessageBlocking;
struct ChatMessageChange;
struct ChatMessageChangeReader;
struct ChatMessageChangeTracker;
struct ChatMessageChangedDeferral;
struct ChatMessageChangedEventArgs;
struct ChatMessageManager;
struct ChatMessageNotificationTriggerDetails;
struct ChatMessageReader;
struct ChatMessageStore;
struct ChatMessageStoreChangedEventArgs;
struct ChatMessageTransport;
struct ChatMessageTransportConfiguration;
struct ChatMessageValidationResult;
struct ChatQueryOptions;
struct ChatRecipientDeliveryInfo;
struct ChatSearchReader;
struct ChatSyncConfiguration;
struct ChatSyncManager;
struct RcsEndUserMessage;
struct RcsEndUserMessageAction;
struct RcsEndUserMessageAvailableEventArgs;
struct RcsEndUserMessageAvailableTriggerDetails;
struct RcsEndUserMessageManager;
struct RcsManager;
struct RcsServiceKindSupportedChangedEventArgs;
struct RcsTransport;
struct RcsTransportConfiguration;
struct RemoteParticipantComposingChangedEventArgs;

}

namespace Windows::ApplicationModel::Chat {

template <typename T> struct impl_IChatCapabilities;
template <typename T> struct impl_IChatCapabilitiesManagerStatics;
template <typename T> struct impl_IChatConversation;
template <typename T> struct impl_IChatConversation2;
template <typename T> struct impl_IChatConversationReader;
template <typename T> struct impl_IChatConversationThreadingInfo;
template <typename T> struct impl_IChatItem;
template <typename T> struct impl_IChatMessage;
template <typename T> struct impl_IChatMessage2;
template <typename T> struct impl_IChatMessage3;
template <typename T> struct impl_IChatMessage4;
template <typename T> struct impl_IChatMessageAttachment;
template <typename T> struct impl_IChatMessageAttachment2;
template <typename T> struct impl_IChatMessageAttachmentFactory;
template <typename T> struct impl_IChatMessageBlockingStatic;
template <typename T> struct impl_IChatMessageChange;
template <typename T> struct impl_IChatMessageChangeReader;
template <typename T> struct impl_IChatMessageChangeTracker;
template <typename T> struct impl_IChatMessageChangedDeferral;
template <typename T> struct impl_IChatMessageChangedEventArgs;
template <typename T> struct impl_IChatMessageManager2Statics;
template <typename T> struct impl_IChatMessageManagerStatic;
template <typename T> struct impl_IChatMessageManagerStatics3;
template <typename T> struct impl_IChatMessageNotificationTriggerDetails;
template <typename T> struct impl_IChatMessageNotificationTriggerDetails2;
template <typename T> struct impl_IChatMessageReader;
template <typename T> struct impl_IChatMessageReader2;
template <typename T> struct impl_IChatMessageStore;
template <typename T> struct impl_IChatMessageStore2;
template <typename T> struct impl_IChatMessageStore3;
template <typename T> struct impl_IChatMessageStoreChangedEventArgs;
template <typename T> struct impl_IChatMessageTransport;
template <typename T> struct impl_IChatMessageTransport2;
template <typename T> struct impl_IChatMessageTransportConfiguration;
template <typename T> struct impl_IChatMessageValidationResult;
template <typename T> struct impl_IChatQueryOptions;
template <typename T> struct impl_IChatRecipientDeliveryInfo;
template <typename T> struct impl_IChatSearchReader;
template <typename T> struct impl_IChatSyncConfiguration;
template <typename T> struct impl_IChatSyncManager;
template <typename T> struct impl_IRcsEndUserMessage;
template <typename T> struct impl_IRcsEndUserMessageAction;
template <typename T> struct impl_IRcsEndUserMessageAvailableEventArgs;
template <typename T> struct impl_IRcsEndUserMessageAvailableTriggerDetails;
template <typename T> struct impl_IRcsEndUserMessageManager;
template <typename T> struct impl_IRcsManagerStatics;
template <typename T> struct impl_IRcsServiceKindSupportedChangedEventArgs;
template <typename T> struct impl_IRcsTransport;
template <typename T> struct impl_IRcsTransportConfiguration;
template <typename T> struct impl_IRemoteParticipantComposingChangedEventArgs;

}

namespace Windows::ApplicationModel::Chat {

enum class ChatConversationThreadingKind
{
    Participants = 0,
    ContactId = 1,
    ConversationId = 2,
    Custom = 3,
};

enum class ChatItemKind
{
    Message = 0,
    Conversation = 1,
};

enum class ChatMessageChangeType
{
    MessageCreated = 0,
    MessageModified = 1,
    MessageDeleted = 2,
    ChangeTrackingLost = 3,
};

enum class ChatMessageKind
{
    Standard = 0,
    FileTransferRequest = 1,
    TransportCustom = 2,
    JoinedConversation = 3,
    LeftConversation = 4,
    OtherParticipantJoinedConversation = 5,
    OtherParticipantLeftConversation = 6,
};

enum class ChatMessageOperatorKind
{
    Unspecified = 0,
    Sms = 1,
    Mms = 2,
    Rcs = 3,
};

enum class ChatMessageStatus
{
    Draft = 0,
    Sending = 1,
    Sent = 2,
    SendRetryNeeded = 3,
    SendFailed = 4,
    Received = 5,
    ReceiveDownloadNeeded = 6,
    ReceiveDownloadFailed = 7,
    ReceiveDownloading = 8,
    Deleted = 9,
    Declined = 10,
    Cancelled = 11,
    Recalled = 12,
    ReceiveRetryNeeded = 13,
};

enum class ChatMessageTransportKind
{
    Text = 0,
    Untriaged = 1,
    Blocked = 2,
    Custom = 3,
};

enum class ChatMessageValidationStatus
{
    Valid = 0,
    NoRecipients = 1,
    InvalidData = 2,
    MessageTooLarge = 3,
    TooManyRecipients = 4,
    TransportInactive = 5,
    TransportNotFound = 6,
    TooManyAttachments = 7,
    InvalidRecipients = 8,
    InvalidBody = 9,
    InvalidOther = 10,
    ValidWithLargeMessage = 11,
    VoiceRoamingRestriction = 12,
    DataRoamingRestriction = 13,
};

enum class ChatRestoreHistorySpan
{
    LastMonth = 0,
    LastYear = 1,
    AnyTime = 2,
};

enum class ChatStoreChangedEventKind
{
    NotificationsMissed = 0,
    StoreModified = 1,
    MessageCreated = 2,
    MessageModified = 3,
    MessageDeleted = 4,
    ConversationModified = 5,
    ConversationDeleted = 6,
    ConversationTransportDeleted = 7,
};

enum class ChatTransportErrorCodeCategory
{
    None = 0,
    Http = 1,
    Network = 2,
    MmsServer = 3,
};

enum class ChatTransportInterpretedErrorCode
{
    None = 0,
    Unknown = 1,
    InvalidRecipientAddress = 2,
    NetworkConnectivity = 3,
    ServiceDenied = 4,
    Timeout = 5,
};

enum class RcsServiceKind
{
    Chat = 0,
    GroupChat = 1,
    FileTransfer = 2,
    Capability = 3,
};

}

}
