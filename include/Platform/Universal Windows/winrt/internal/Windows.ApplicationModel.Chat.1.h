// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.ApplicationModel.Chat.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Media.MediaProperties.0.h"
#include "Windows.Security.Credentials.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::Chat {

struct __declspec(uuid("3aff77bc-39c9-4dd1-ad2d-3964dd9d403f")) __declspec(novtable) IChatCapabilities : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsOnline(bool * result) = 0;
    virtual HRESULT __stdcall get_IsChatCapable(bool * result) = 0;
    virtual HRESULT __stdcall get_IsFileTransferCapable(bool * result) = 0;
    virtual HRESULT __stdcall get_IsGeoLocationPushCapable(bool * result) = 0;
    virtual HRESULT __stdcall get_IsIntegratedMessagingCapable(bool * result) = 0;
};

struct __declspec(uuid("b57a2f30-7041-458e-b0cf-7c0d9fea333a")) __declspec(novtable) IChatCapabilitiesManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetCachedCapabilitiesAsync(hstring address, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatCapabilities> ** result) = 0;
    virtual HRESULT __stdcall abi_GetCapabilitiesFromNetworkAsync(hstring address, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatCapabilities> ** result) = 0;
};

struct __declspec(uuid("a58c080d-1a6f-46dc-8f3d-f5028660b6ee")) __declspec(novtable) IChatConversation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_HasUnreadMessages(bool * result) = 0;
    virtual HRESULT __stdcall get_Id(hstring * result) = 0;
    virtual HRESULT __stdcall get_Subject(hstring * result) = 0;
    virtual HRESULT __stdcall put_Subject(hstring value) = 0;
    virtual HRESULT __stdcall get_IsConversationMuted(bool * result) = 0;
    virtual HRESULT __stdcall put_IsConversationMuted(bool value) = 0;
    virtual HRESULT __stdcall get_MostRecentMessageId(hstring * result) = 0;
    virtual HRESULT __stdcall get_Participants(Windows::Foundation::Collections::IVector<hstring> ** result) = 0;
    virtual HRESULT __stdcall get_ThreadingInfo(Windows::ApplicationModel::Chat::IChatConversationThreadingInfo ** result) = 0;
    virtual HRESULT __stdcall abi_DeleteAsync(Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_GetMessageReader(Windows::ApplicationModel::Chat::IChatMessageReader ** result) = 0;
    virtual HRESULT __stdcall abi_MarkAllMessagesAsReadAsync(Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_MarkMessagesAsReadAsync(Windows::Foundation::DateTime value, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_SaveAsync(Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_NotifyLocalParticipantComposing(hstring transportId, hstring participantAddress, bool isComposing) = 0;
    virtual HRESULT __stdcall abi_NotifyRemoteParticipantComposing(hstring transportId, hstring participantAddress, bool isComposing) = 0;
    virtual HRESULT __stdcall add_RemoteParticipantComposingChanged(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Chat::ChatConversation, Windows::ApplicationModel::Chat::RemoteParticipantComposingChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_RemoteParticipantComposingChanged(event_token token) = 0;
};

struct __declspec(uuid("0a030cd1-983a-47aa-9a90-ee48ee997b59")) __declspec(novtable) IChatConversation2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CanModifyParticipants(bool * result) = 0;
    virtual HRESULT __stdcall put_CanModifyParticipants(bool value) = 0;
};

struct __declspec(uuid("055136d2-de32-4a47-a93a-b3dc0833852b")) __declspec(novtable) IChatConversationReader : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ReadBatchAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::ChatConversation>> ** result) = 0;
    virtual HRESULT __stdcall abi_ReadBatchWithCountAsync(int32_t count, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::ChatConversation>> ** result) = 0;
};

struct __declspec(uuid("331c21dc-7a07-4422-a32c-24be7c6dab24")) __declspec(novtable) IChatConversationThreadingInfo : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ContactId(hstring * result) = 0;
    virtual HRESULT __stdcall put_ContactId(hstring value) = 0;
    virtual HRESULT __stdcall get_Custom(hstring * result) = 0;
    virtual HRESULT __stdcall put_Custom(hstring value) = 0;
    virtual HRESULT __stdcall get_ConversationId(hstring * result) = 0;
    virtual HRESULT __stdcall put_ConversationId(hstring value) = 0;
    virtual HRESULT __stdcall get_Participants(Windows::Foundation::Collections::IVector<hstring> ** result) = 0;
    virtual HRESULT __stdcall get_Kind(winrt::Windows::ApplicationModel::Chat::ChatConversationThreadingKind * result) = 0;
    virtual HRESULT __stdcall put_Kind(winrt::Windows::ApplicationModel::Chat::ChatConversationThreadingKind value) = 0;
};

struct __declspec(uuid("8751d000-ceb1-4243-b803-15d45a1dd428")) __declspec(novtable) IChatItem : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ItemKind(winrt::Windows::ApplicationModel::Chat::ChatItemKind * result) = 0;
};

struct __declspec(uuid("4b39052a-1142-5089-76da-f2db3d17cd05")) __declspec(novtable) IChatMessage : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Attachments(Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Chat::ChatMessageAttachment> ** value) = 0;
    virtual HRESULT __stdcall get_Body(hstring * value) = 0;
    virtual HRESULT __stdcall put_Body(hstring value) = 0;
    virtual HRESULT __stdcall get_From(hstring * value) = 0;
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall get_IsForwardingDisabled(bool * value) = 0;
    virtual HRESULT __stdcall get_IsIncoming(bool * value) = 0;
    virtual HRESULT __stdcall get_IsRead(bool * value) = 0;
    virtual HRESULT __stdcall get_LocalTimestamp(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_NetworkTimestamp(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_Recipients(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_RecipientSendStatuses(Windows::Foundation::Collections::IMapView<hstring, winrt::Windows::ApplicationModel::Chat::ChatMessageStatus> ** value) = 0;
    virtual HRESULT __stdcall get_Status(winrt::Windows::ApplicationModel::Chat::ChatMessageStatus * value) = 0;
    virtual HRESULT __stdcall get_Subject(hstring * value) = 0;
    virtual HRESULT __stdcall get_TransportFriendlyName(hstring * value) = 0;
    virtual HRESULT __stdcall get_TransportId(hstring * value) = 0;
    virtual HRESULT __stdcall put_TransportId(hstring value) = 0;
};

struct __declspec(uuid("86668332-543f-49f5-ac71-6c2afc6565fd")) __declspec(novtable) IChatMessage2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EstimatedDownloadSize(uint64_t * result) = 0;
    virtual HRESULT __stdcall put_EstimatedDownloadSize(uint64_t value) = 0;
    virtual HRESULT __stdcall put_From(hstring value) = 0;
    virtual HRESULT __stdcall get_IsAutoReply(bool * result) = 0;
    virtual HRESULT __stdcall put_IsAutoReply(bool value) = 0;
    virtual HRESULT __stdcall put_IsForwardingDisabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsReplyDisabled(bool * result) = 0;
    virtual HRESULT __stdcall put_IsIncoming(bool value) = 0;
    virtual HRESULT __stdcall put_IsRead(bool value) = 0;
    virtual HRESULT __stdcall get_IsSeen(bool * result) = 0;
    virtual HRESULT __stdcall put_IsSeen(bool value) = 0;
    virtual HRESULT __stdcall get_IsSimMessage(bool * result) = 0;
    virtual HRESULT __stdcall put_LocalTimestamp(Windows::Foundation::DateTime value) = 0;
    virtual HRESULT __stdcall get_MessageKind(winrt::Windows::ApplicationModel::Chat::ChatMessageKind * result) = 0;
    virtual HRESULT __stdcall put_MessageKind(winrt::Windows::ApplicationModel::Chat::ChatMessageKind value) = 0;
    virtual HRESULT __stdcall get_MessageOperatorKind(winrt::Windows::ApplicationModel::Chat::ChatMessageOperatorKind * result) = 0;
    virtual HRESULT __stdcall put_MessageOperatorKind(winrt::Windows::ApplicationModel::Chat::ChatMessageOperatorKind value) = 0;
    virtual HRESULT __stdcall put_NetworkTimestamp(Windows::Foundation::DateTime value) = 0;
    virtual HRESULT __stdcall get_IsReceivedDuringQuietHours(bool * result) = 0;
    virtual HRESULT __stdcall put_IsReceivedDuringQuietHours(bool value) = 0;
    virtual HRESULT __stdcall put_RemoteId(hstring value) = 0;
    virtual HRESULT __stdcall put_Status(winrt::Windows::ApplicationModel::Chat::ChatMessageStatus value) = 0;
    virtual HRESULT __stdcall put_Subject(hstring value) = 0;
    virtual HRESULT __stdcall get_ShouldSuppressNotification(bool * result) = 0;
    virtual HRESULT __stdcall put_ShouldSuppressNotification(bool value) = 0;
    virtual HRESULT __stdcall get_ThreadingInfo(Windows::ApplicationModel::Chat::IChatConversationThreadingInfo ** result) = 0;
    virtual HRESULT __stdcall put_ThreadingInfo(Windows::ApplicationModel::Chat::IChatConversationThreadingInfo * value) = 0;
    virtual HRESULT __stdcall get_RecipientsDeliveryInfos(Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Chat::ChatRecipientDeliveryInfo> ** result) = 0;
};

struct __declspec(uuid("74eb2fb0-3ba7-459f-8e0b-e8af0febd9ad")) __declspec(novtable) IChatMessage3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RemoteId(hstring * value) = 0;
};

struct __declspec(uuid("2d144b0f-d2bf-460c-aa68-6d3f8483c9bf")) __declspec(novtable) IChatMessage4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SyncId(hstring * result) = 0;
    virtual HRESULT __stdcall put_SyncId(hstring value) = 0;
};

struct __declspec(uuid("c7c4fd74-bf63-58eb-508c-8b863ff16b67")) __declspec(novtable) IChatMessageAttachment : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DataStreamReference(Windows::Storage::Streams::IRandomAccessStreamReference ** value) = 0;
    virtual HRESULT __stdcall put_DataStreamReference(Windows::Storage::Streams::IRandomAccessStreamReference * value) = 0;
    virtual HRESULT __stdcall get_GroupId(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_GroupId(uint32_t value) = 0;
    virtual HRESULT __stdcall get_MimeType(hstring * value) = 0;
    virtual HRESULT __stdcall put_MimeType(hstring value) = 0;
    virtual HRESULT __stdcall get_Text(hstring * value) = 0;
    virtual HRESULT __stdcall put_Text(hstring value) = 0;
};

struct __declspec(uuid("5ed99270-7dd1-4a87-a8ce-acdd87d80dc8")) __declspec(novtable) IChatMessageAttachment2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Thumbnail(Windows::Storage::Streams::IRandomAccessStreamReference ** result) = 0;
    virtual HRESULT __stdcall put_Thumbnail(Windows::Storage::Streams::IRandomAccessStreamReference * value) = 0;
    virtual HRESULT __stdcall get_TransferProgress(double * result) = 0;
    virtual HRESULT __stdcall put_TransferProgress(double value) = 0;
    virtual HRESULT __stdcall get_OriginalFileName(hstring * result) = 0;
    virtual HRESULT __stdcall put_OriginalFileName(hstring value) = 0;
};

struct __declspec(uuid("205852a2-a356-5b71-6ca9-66c985b7d0d5")) __declspec(novtable) IChatMessageAttachmentFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateChatMessageAttachment(hstring mimeType, Windows::Storage::Streams::IRandomAccessStreamReference * dataStreamReference, Windows::ApplicationModel::Chat::IChatMessageAttachment ** value) = 0;
};

struct __declspec(uuid("f6b9a380-cdea-11e4-8830-0800200c9a66")) __declspec(novtable) IChatMessageBlockingStatic : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_MarkMessageAsBlockedAsync(hstring localChatMessageId, bool blocked, Windows::Foundation::IAsyncAction ** value) = 0;
};

struct __declspec(uuid("1c18c355-421e-54b8-6d38-6b3a6c82fccc")) __declspec(novtable) IChatMessageChange : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ChangeType(winrt::Windows::ApplicationModel::Chat::ChatMessageChangeType * value) = 0;
    virtual HRESULT __stdcall get_Message(Windows::ApplicationModel::Chat::IChatMessage ** value) = 0;
};

struct __declspec(uuid("14267020-28ce-5f26-7b05-9a5c7cce87ca")) __declspec(novtable) IChatMessageChangeReader : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_AcceptChanges() = 0;
    virtual HRESULT __stdcall abi_AcceptChangesThrough(Windows::ApplicationModel::Chat::IChatMessageChange * lastChangeToAcknowledge) = 0;
    virtual HRESULT __stdcall abi_ReadBatchAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::ChatMessageChange>> ** value) = 0;
};

struct __declspec(uuid("60b7f066-70a0-5224-508c-242ef7c1d06f")) __declspec(novtable) IChatMessageChangeTracker : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Enable() = 0;
    virtual HRESULT __stdcall abi_GetChangeReader(Windows::ApplicationModel::Chat::IChatMessageChangeReader ** value) = 0;
    virtual HRESULT __stdcall abi_Reset() = 0;
};

struct __declspec(uuid("fbc6b30c-788c-4dcc-ace7-6282382968cf")) __declspec(novtable) IChatMessageChangedDeferral : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Complete() = 0;
};

struct __declspec(uuid("b6b73e2d-691c-4edf-8660-6eb9896892e3")) __declspec(novtable) IChatMessageChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDeferral(Windows::ApplicationModel::Chat::IChatMessageChangedDeferral ** result) = 0;
};

struct __declspec(uuid("1d45390f-9f4f-4e35-964e-1b9ca61ac044")) __declspec(novtable) IChatMessageManager2Statics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RegisterTransportAsync(Windows::Foundation::IAsyncOperation<hstring> ** result) = 0;
    virtual HRESULT __stdcall abi_GetTransportAsync(hstring transportId, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatMessageTransport> ** result) = 0;
};

struct __declspec(uuid("f15c60f7-d5e8-5e92-556d-e03b60253104")) __declspec(novtable) IChatMessageManagerStatic : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetTransportsAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::ChatMessageTransport>> ** value) = 0;
    virtual HRESULT __stdcall abi_RequestStoreAsync(Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatMessageStore> ** value) = 0;
    virtual HRESULT __stdcall abi_ShowComposeSmsMessageAsync(Windows::ApplicationModel::Chat::IChatMessage * message, Windows::Foundation::IAsyncAction ** value) = 0;
    virtual HRESULT __stdcall abi_ShowSmsSettings() = 0;
};

struct __declspec(uuid("208b830d-6755-48cc-9ab3-fd03c463fc92")) __declspec(novtable) IChatMessageManagerStatics3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RequestSyncManagerAsync(Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatSyncManager> ** result) = 0;
};

struct __declspec(uuid("fd344dfb-3063-4e17-8586-c6c08262e6c0")) __declspec(novtable) IChatMessageNotificationTriggerDetails : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ChatMessage(Windows::ApplicationModel::Chat::IChatMessage ** value) = 0;
};

struct __declspec(uuid("6bb522e0-aa07-4fd1-9471-77934fb75ee6")) __declspec(novtable) IChatMessageNotificationTriggerDetails2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ShouldDisplayToast(bool * result) = 0;
    virtual HRESULT __stdcall get_ShouldUpdateDetailText(bool * result) = 0;
    virtual HRESULT __stdcall get_ShouldUpdateBadge(bool * result) = 0;
    virtual HRESULT __stdcall get_ShouldUpdateActionCenter(bool * result) = 0;
};

struct __declspec(uuid("b6ea78ce-4489-56f9-76aa-e204682514cf")) __declspec(novtable) IChatMessageReader : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ReadBatchAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::ChatMessage>> ** value) = 0;
};

struct __declspec(uuid("89643683-64bb-470d-9df4-0de8be1a05bf")) __declspec(novtable) IChatMessageReader2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ReadBatchWithCountAsync(int32_t count, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::ChatMessage>> ** result) = 0;
};

struct __declspec(uuid("31f2fd01-ccf6-580b-4976-0a07dd5d3b47")) __declspec(novtable) IChatMessageStore : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ChangeTracker(Windows::ApplicationModel::Chat::IChatMessageChangeTracker ** value) = 0;
    virtual HRESULT __stdcall abi_DeleteMessageAsync(hstring localMessageId, Windows::Foundation::IAsyncAction ** value) = 0;
    virtual HRESULT __stdcall abi_DownloadMessageAsync(hstring localChatMessageId, Windows::Foundation::IAsyncAction ** value) = 0;
    virtual HRESULT __stdcall abi_GetMessageAsync(hstring localChatMessageId, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatMessage> ** value) = 0;
    virtual HRESULT __stdcall abi_GetMessageReader1(Windows::ApplicationModel::Chat::IChatMessageReader ** value) = 0;
    virtual HRESULT __stdcall abi_GetMessageReader2(Windows::Foundation::TimeSpan recentTimeLimit, Windows::ApplicationModel::Chat::IChatMessageReader ** value) = 0;
    virtual HRESULT __stdcall abi_MarkMessageReadAsync(hstring localChatMessageId, Windows::Foundation::IAsyncAction ** value) = 0;
    virtual HRESULT __stdcall abi_RetrySendMessageAsync(hstring localChatMessageId, Windows::Foundation::IAsyncAction ** value) = 0;
    virtual HRESULT __stdcall abi_SendMessageAsync(Windows::ApplicationModel::Chat::IChatMessage * chatMessage, Windows::Foundation::IAsyncAction ** value) = 0;
    virtual HRESULT __stdcall abi_ValidateMessage(Windows::ApplicationModel::Chat::IChatMessage * chatMessage, Windows::ApplicationModel::Chat::IChatMessageValidationResult ** value) = 0;
    virtual HRESULT __stdcall add_MessageChanged(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Chat::ChatMessageStore, Windows::ApplicationModel::Chat::ChatMessageChangedEventArgs> * value, event_token * returnValue) = 0;
    virtual HRESULT __stdcall remove_MessageChanged(event_token value) = 0;
};

struct __declspec(uuid("ad4dc4ee-3ad4-491b-b311-abdf9bb22768")) __declspec(novtable) IChatMessageStore2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ForwardMessageAsync(hstring localChatMessageId, Windows::Foundation::Collections::IIterable<hstring> * addresses, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatMessage> ** result) = 0;
    virtual HRESULT __stdcall abi_GetConversationAsync(hstring conversationId, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatConversation> ** result) = 0;
    virtual HRESULT __stdcall abi_GetConversationForTransportsAsync(hstring conversationId, Windows::Foundation::Collections::IIterable<hstring> * transportIds, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatConversation> ** result) = 0;
    virtual HRESULT __stdcall abi_GetConversationFromThreadingInfoAsync(Windows::ApplicationModel::Chat::IChatConversationThreadingInfo * threadingInfo, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatConversation> ** result) = 0;
    virtual HRESULT __stdcall abi_GetConversationReader(Windows::ApplicationModel::Chat::IChatConversationReader ** result) = 0;
    virtual HRESULT __stdcall abi_GetConversationForTransportsReader(Windows::Foundation::Collections::IIterable<hstring> * transportIds, Windows::ApplicationModel::Chat::IChatConversationReader ** result) = 0;
    virtual HRESULT __stdcall abi_GetMessageByRemoteIdAsync(hstring transportId, hstring remoteId, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatMessage> ** result) = 0;
    virtual HRESULT __stdcall abi_GetUnseenCountAsync(Windows::Foundation::IAsyncOperation<int32_t> ** result) = 0;
    virtual HRESULT __stdcall abi_GetUnseenCountForTransportsReaderAsync(Windows::Foundation::Collections::IIterable<hstring> * transportIds, Windows::Foundation::IAsyncOperation<int32_t> ** result) = 0;
    virtual HRESULT __stdcall abi_MarkAsSeenAsync(Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_MarkAsSeenForTransportsAsync(Windows::Foundation::Collections::IIterable<hstring> * transportIds, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_GetSearchReader(Windows::ApplicationModel::Chat::IChatQueryOptions * value, Windows::ApplicationModel::Chat::IChatSearchReader ** result) = 0;
    virtual HRESULT __stdcall abi_SaveMessageAsync(Windows::ApplicationModel::Chat::IChatMessage * chatMessage, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_TryCancelDownloadMessageAsync(hstring localChatMessageId, Windows::Foundation::IAsyncOperation<bool> ** result) = 0;
    virtual HRESULT __stdcall abi_TryCancelSendMessageAsync(hstring localChatMessageId, Windows::Foundation::IAsyncOperation<bool> ** result) = 0;
    virtual HRESULT __stdcall add_StoreChanged(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Chat::ChatMessageStore, Windows::ApplicationModel::Chat::ChatMessageStoreChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_StoreChanged(event_token token) = 0;
};

struct __declspec(uuid("9adbbb09-4345-4ec1-8b74-b7338243719c")) __declspec(novtable) IChatMessageStore3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetMessageBySyncIdAsync(hstring syncId, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatMessage> ** result) = 0;
};

struct __declspec(uuid("65c66fac-fe8c-46d4-9119-57b8410311d5")) __declspec(novtable) IChatMessageStoreChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(hstring * result) = 0;
    virtual HRESULT __stdcall get_Kind(winrt::Windows::ApplicationModel::Chat::ChatStoreChangedEventKind * result) = 0;
};

struct __declspec(uuid("63a9dbf8-e6b3-5c9a-5f85-d47925b9bd18")) __declspec(novtable) IChatMessageTransport : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsAppSetAsNotificationProvider(bool * value) = 0;
    virtual HRESULT __stdcall get_IsActive(bool * value) = 0;
    virtual HRESULT __stdcall get_TransportFriendlyName(hstring * value) = 0;
    virtual HRESULT __stdcall get_TransportId(hstring * value) = 0;
    virtual HRESULT __stdcall abi_RequestSetAsNotificationProviderAsync(Windows::Foundation::IAsyncAction ** value) = 0;
};

struct __declspec(uuid("90a75622-d84a-4c22-a94d-544444edc8a1")) __declspec(novtable) IChatMessageTransport2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Configuration(Windows::ApplicationModel::Chat::IChatMessageTransportConfiguration ** result) = 0;
    virtual HRESULT __stdcall get_TransportKind(winrt::Windows::ApplicationModel::Chat::ChatMessageTransportKind * result) = 0;
};

struct __declspec(uuid("879ff725-1a08-4aca-a075-3355126312e6")) __declspec(novtable) IChatMessageTransportConfiguration : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MaxAttachmentCount(int32_t * result) = 0;
    virtual HRESULT __stdcall get_MaxMessageSizeInKilobytes(int32_t * result) = 0;
    virtual HRESULT __stdcall get_MaxRecipientCount(int32_t * result) = 0;
    virtual HRESULT __stdcall get_SupportedVideoFormat(Windows::Media::MediaProperties::IMediaEncodingProfile ** result) = 0;
    virtual HRESULT __stdcall get_ExtendedProperties(Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> ** result) = 0;
};

struct __declspec(uuid("25e93a03-28ec-5889-569b-7e486b126f18")) __declspec(novtable) IChatMessageValidationResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MaxPartCount(Windows::Foundation::IReference<uint32_t> ** value) = 0;
    virtual HRESULT __stdcall get_PartCount(Windows::Foundation::IReference<uint32_t> ** value) = 0;
    virtual HRESULT __stdcall get_RemainingCharacterCountInPart(Windows::Foundation::IReference<uint32_t> ** value) = 0;
    virtual HRESULT __stdcall get_Status(winrt::Windows::ApplicationModel::Chat::ChatMessageValidationStatus * value) = 0;
};

struct __declspec(uuid("2fd364a6-bf36-42f7-b7e7-923c0aabfe16")) __declspec(novtable) IChatQueryOptions : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SearchString(hstring * result) = 0;
    virtual HRESULT __stdcall put_SearchString(hstring value) = 0;
};

struct __declspec(uuid("ffc7b2a2-283c-4c0a-8a0e-8c33bdbf0545")) __declspec(novtable) IChatRecipientDeliveryInfo : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TransportAddress(hstring * result) = 0;
    virtual HRESULT __stdcall put_TransportAddress(hstring value) = 0;
    virtual HRESULT __stdcall get_DeliveryTime(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** result) = 0;
    virtual HRESULT __stdcall put_DeliveryTime(Windows::Foundation::IReference<Windows::Foundation::DateTime> * value) = 0;
    virtual HRESULT __stdcall get_ReadTime(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** result) = 0;
    virtual HRESULT __stdcall put_ReadTime(Windows::Foundation::IReference<Windows::Foundation::DateTime> * value) = 0;
    virtual HRESULT __stdcall get_TransportErrorCodeCategory(winrt::Windows::ApplicationModel::Chat::ChatTransportErrorCodeCategory * result) = 0;
    virtual HRESULT __stdcall get_TransportInterpretedErrorCode(winrt::Windows::ApplicationModel::Chat::ChatTransportInterpretedErrorCode * result) = 0;
    virtual HRESULT __stdcall get_TransportErrorCode(int32_t * result) = 0;
    virtual HRESULT __stdcall get_IsErrorPermanent(bool * result) = 0;
    virtual HRESULT __stdcall get_Status(winrt::Windows::ApplicationModel::Chat::ChatMessageStatus * result) = 0;
};

struct __declspec(uuid("4665fe49-9020-4752-980d-39612325f589")) __declspec(novtable) IChatSearchReader : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ReadBatchAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::IChatItem>> ** result) = 0;
    virtual HRESULT __stdcall abi_ReadBatchWithCountAsync(int32_t count, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::IChatItem>> ** result) = 0;
};

struct __declspec(uuid("09f869b2-69f4-4aff-82b6-06992ff402d2")) __declspec(novtable) IChatSyncConfiguration : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsSyncEnabled(bool * result) = 0;
    virtual HRESULT __stdcall put_IsSyncEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_RestoreHistorySpan(winrt::Windows::ApplicationModel::Chat::ChatRestoreHistorySpan * result) = 0;
    virtual HRESULT __stdcall put_RestoreHistorySpan(winrt::Windows::ApplicationModel::Chat::ChatRestoreHistorySpan value) = 0;
};

struct __declspec(uuid("7ba52c63-2650-486f-b4b4-6bd9d3d63c84")) __declspec(novtable) IChatSyncManager : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Configuration(Windows::ApplicationModel::Chat::IChatSyncConfiguration ** result) = 0;
    virtual HRESULT __stdcall abi_AssociateAccountAsync(Windows::Security::Credentials::IWebAccount * webAccount, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_UnassociateAccountAsync(Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_IsAccountAssociated(Windows::Security::Credentials::IWebAccount * webAccount, bool * result) = 0;
    virtual HRESULT __stdcall abi_StartSync() = 0;
    virtual HRESULT __stdcall abi_SetConfigurationAsync(Windows::ApplicationModel::Chat::IChatSyncConfiguration * configuration, Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("d7cda5eb-cbd7-4f3b-8526-b506dec35c53")) __declspec(novtable) IRcsEndUserMessage : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TransportId(hstring * result) = 0;
    virtual HRESULT __stdcall get_Title(hstring * result) = 0;
    virtual HRESULT __stdcall get_Text(hstring * result) = 0;
    virtual HRESULT __stdcall get_IsPinRequired(bool * result) = 0;
    virtual HRESULT __stdcall get_Actions(Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::RcsEndUserMessageAction> ** result) = 0;
    virtual HRESULT __stdcall abi_SendResponseAsync(Windows::ApplicationModel::Chat::IRcsEndUserMessageAction * action, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_SendResponseWithPinAsync(Windows::ApplicationModel::Chat::IRcsEndUserMessageAction * action, hstring pin, Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("92378737-9b42-46d3-9d5e-3c1b2dae7cb8")) __declspec(novtable) IRcsEndUserMessageAction : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Label(hstring * result) = 0;
};

struct __declspec(uuid("2d45ae01-3f89-41ea-9702-9e9ed411aa98")) __declspec(novtable) IRcsEndUserMessageAvailableEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsMessageAvailable(bool * result) = 0;
    virtual HRESULT __stdcall get_Message(Windows::ApplicationModel::Chat::IRcsEndUserMessage ** result) = 0;
};

struct __declspec(uuid("5b97742d-351f-4692-b41e-1b035dc18986")) __declspec(novtable) IRcsEndUserMessageAvailableTriggerDetails : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Title(hstring * value) = 0;
    virtual HRESULT __stdcall get_Text(hstring * value) = 0;
};

struct __declspec(uuid("3054ae5a-4d1f-4b59-9433-126c734e86a6")) __declspec(novtable) IRcsEndUserMessageManager : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_MessageAvailableChanged(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Chat::RcsEndUserMessageManager, Windows::ApplicationModel::Chat::RcsEndUserMessageAvailableEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_MessageAvailableChanged(event_token token) = 0;
};

struct __declspec(uuid("7d270ac5-0abd-4f31-9b99-a59e71a7b731")) __declspec(novtable) IRcsManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetEndUserMessageManager(Windows::ApplicationModel::Chat::IRcsEndUserMessageManager ** result) = 0;
    virtual HRESULT __stdcall abi_GetTransportsAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::RcsTransport>> ** value) = 0;
    virtual HRESULT __stdcall abi_GetTransportAsync(hstring transportId, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::RcsTransport> ** result) = 0;
    virtual HRESULT __stdcall abi_LeaveConversationAsync(Windows::ApplicationModel::Chat::IChatConversation * conversation, Windows::Foundation::IAsyncAction ** value) = 0;
};

struct __declspec(uuid("f47ea244-e783-4866-b3a7-4e5ccf023070")) __declspec(novtable) IRcsServiceKindSupportedChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ServiceKind(winrt::Windows::ApplicationModel::Chat::RcsServiceKind * result) = 0;
};

struct __declspec(uuid("fea34759-f37c-4319-8546-ec84d21d30ff")) __declspec(novtable) IRcsTransport : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ExtendedProperties(Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> ** value) = 0;
    virtual HRESULT __stdcall get_IsActive(bool * value) = 0;
    virtual HRESULT __stdcall get_TransportFriendlyName(hstring * value) = 0;
    virtual HRESULT __stdcall get_TransportId(hstring * value) = 0;
    virtual HRESULT __stdcall get_Configuration(Windows::ApplicationModel::Chat::IRcsTransportConfiguration ** result) = 0;
    virtual HRESULT __stdcall abi_IsStoreAndForwardEnabled(winrt::Windows::ApplicationModel::Chat::RcsServiceKind serviceKind, bool * result) = 0;
    virtual HRESULT __stdcall abi_IsServiceKindSupported(winrt::Windows::ApplicationModel::Chat::RcsServiceKind serviceKind, bool * result) = 0;
    virtual HRESULT __stdcall add_ServiceKindSupportedChanged(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Chat::RcsTransport, Windows::ApplicationModel::Chat::RcsServiceKindSupportedChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ServiceKindSupportedChanged(event_token token) = 0;
};

struct __declspec(uuid("1fccb102-2472-4bb9-9988-c1211c83e8a9")) __declspec(novtable) IRcsTransportConfiguration : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MaxAttachmentCount(int32_t * result) = 0;
    virtual HRESULT __stdcall get_MaxMessageSizeInKilobytes(int32_t * result) = 0;
    virtual HRESULT __stdcall get_MaxGroupMessageSizeInKilobytes(int32_t * result) = 0;
    virtual HRESULT __stdcall get_MaxRecipientCount(int32_t * result) = 0;
    virtual HRESULT __stdcall get_MaxFileSizeInKilobytes(int32_t * result) = 0;
    virtual HRESULT __stdcall get_WarningFileSizeInKilobytes(int32_t * result) = 0;
};

struct __declspec(uuid("1ec045a7-cfc9-45c9-9876-449f2bc180f5")) __declspec(novtable) IRemoteParticipantComposingChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TransportId(hstring * result) = 0;
    virtual HRESULT __stdcall get_ParticipantAddress(hstring * result) = 0;
    virtual HRESULT __stdcall get_IsComposing(bool * result) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::ApplicationModel::Chat::ChatCapabilities> { using default_interface = Windows::ApplicationModel::Chat::IChatCapabilities; };
template <> struct traits<Windows::ApplicationModel::Chat::ChatConversation> { using default_interface = Windows::ApplicationModel::Chat::IChatConversation; };
template <> struct traits<Windows::ApplicationModel::Chat::ChatConversationReader> { using default_interface = Windows::ApplicationModel::Chat::IChatConversationReader; };
template <> struct traits<Windows::ApplicationModel::Chat::ChatConversationThreadingInfo> { using default_interface = Windows::ApplicationModel::Chat::IChatConversationThreadingInfo; };
template <> struct traits<Windows::ApplicationModel::Chat::ChatMessage> { using default_interface = Windows::ApplicationModel::Chat::IChatMessage; };
template <> struct traits<Windows::ApplicationModel::Chat::ChatMessageAttachment> { using default_interface = Windows::ApplicationModel::Chat::IChatMessageAttachment; };
template <> struct traits<Windows::ApplicationModel::Chat::ChatMessageChange> { using default_interface = Windows::ApplicationModel::Chat::IChatMessageChange; };
template <> struct traits<Windows::ApplicationModel::Chat::ChatMessageChangeReader> { using default_interface = Windows::ApplicationModel::Chat::IChatMessageChangeReader; };
template <> struct traits<Windows::ApplicationModel::Chat::ChatMessageChangeTracker> { using default_interface = Windows::ApplicationModel::Chat::IChatMessageChangeTracker; };
template <> struct traits<Windows::ApplicationModel::Chat::ChatMessageChangedDeferral> { using default_interface = Windows::ApplicationModel::Chat::IChatMessageChangedDeferral; };
template <> struct traits<Windows::ApplicationModel::Chat::ChatMessageChangedEventArgs> { using default_interface = Windows::ApplicationModel::Chat::IChatMessageChangedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Chat::ChatMessageNotificationTriggerDetails> { using default_interface = Windows::ApplicationModel::Chat::IChatMessageNotificationTriggerDetails; };
template <> struct traits<Windows::ApplicationModel::Chat::ChatMessageReader> { using default_interface = Windows::ApplicationModel::Chat::IChatMessageReader; };
template <> struct traits<Windows::ApplicationModel::Chat::ChatMessageStore> { using default_interface = Windows::ApplicationModel::Chat::IChatMessageStore; };
template <> struct traits<Windows::ApplicationModel::Chat::ChatMessageStoreChangedEventArgs> { using default_interface = Windows::ApplicationModel::Chat::IChatMessageStoreChangedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Chat::ChatMessageTransport> { using default_interface = Windows::ApplicationModel::Chat::IChatMessageTransport; };
template <> struct traits<Windows::ApplicationModel::Chat::ChatMessageTransportConfiguration> { using default_interface = Windows::ApplicationModel::Chat::IChatMessageTransportConfiguration; };
template <> struct traits<Windows::ApplicationModel::Chat::ChatMessageValidationResult> { using default_interface = Windows::ApplicationModel::Chat::IChatMessageValidationResult; };
template <> struct traits<Windows::ApplicationModel::Chat::ChatQueryOptions> { using default_interface = Windows::ApplicationModel::Chat::IChatQueryOptions; };
template <> struct traits<Windows::ApplicationModel::Chat::ChatRecipientDeliveryInfo> { using default_interface = Windows::ApplicationModel::Chat::IChatRecipientDeliveryInfo; };
template <> struct traits<Windows::ApplicationModel::Chat::ChatSearchReader> { using default_interface = Windows::ApplicationModel::Chat::IChatSearchReader; };
template <> struct traits<Windows::ApplicationModel::Chat::ChatSyncConfiguration> { using default_interface = Windows::ApplicationModel::Chat::IChatSyncConfiguration; };
template <> struct traits<Windows::ApplicationModel::Chat::ChatSyncManager> { using default_interface = Windows::ApplicationModel::Chat::IChatSyncManager; };
template <> struct traits<Windows::ApplicationModel::Chat::RcsEndUserMessage> { using default_interface = Windows::ApplicationModel::Chat::IRcsEndUserMessage; };
template <> struct traits<Windows::ApplicationModel::Chat::RcsEndUserMessageAction> { using default_interface = Windows::ApplicationModel::Chat::IRcsEndUserMessageAction; };
template <> struct traits<Windows::ApplicationModel::Chat::RcsEndUserMessageAvailableEventArgs> { using default_interface = Windows::ApplicationModel::Chat::IRcsEndUserMessageAvailableEventArgs; };
template <> struct traits<Windows::ApplicationModel::Chat::RcsEndUserMessageAvailableTriggerDetails> { using default_interface = Windows::ApplicationModel::Chat::IRcsEndUserMessageAvailableTriggerDetails; };
template <> struct traits<Windows::ApplicationModel::Chat::RcsEndUserMessageManager> { using default_interface = Windows::ApplicationModel::Chat::IRcsEndUserMessageManager; };
template <> struct traits<Windows::ApplicationModel::Chat::RcsServiceKindSupportedChangedEventArgs> { using default_interface = Windows::ApplicationModel::Chat::IRcsServiceKindSupportedChangedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Chat::RcsTransport> { using default_interface = Windows::ApplicationModel::Chat::IRcsTransport; };
template <> struct traits<Windows::ApplicationModel::Chat::RcsTransportConfiguration> { using default_interface = Windows::ApplicationModel::Chat::IRcsTransportConfiguration; };
template <> struct traits<Windows::ApplicationModel::Chat::RemoteParticipantComposingChangedEventArgs> { using default_interface = Windows::ApplicationModel::Chat::IRemoteParticipantComposingChangedEventArgs; };

}

namespace Windows::ApplicationModel::Chat {

template <typename D>
struct WINRT_EBO impl_IChatCapabilities
{
    bool IsOnline() const;
    bool IsChatCapable() const;
    bool IsFileTransferCapable() const;
    bool IsGeoLocationPushCapable() const;
    bool IsIntegratedMessagingCapable() const;
};

template <typename D>
struct WINRT_EBO impl_IChatCapabilitiesManagerStatics
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatCapabilities> GetCachedCapabilitiesAsync(hstring_view address) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatCapabilities> GetCapabilitiesFromNetworkAsync(hstring_view address) const;
};

template <typename D>
struct WINRT_EBO impl_IChatConversation
{
    bool HasUnreadMessages() const;
    hstring Id() const;
    hstring Subject() const;
    void Subject(hstring_view value) const;
    bool IsConversationMuted() const;
    void IsConversationMuted(bool value) const;
    hstring MostRecentMessageId() const;
    Windows::Foundation::Collections::IVector<hstring> Participants() const;
    Windows::ApplicationModel::Chat::ChatConversationThreadingInfo ThreadingInfo() const;
    Windows::Foundation::IAsyncAction DeleteAsync() const;
    Windows::ApplicationModel::Chat::ChatMessageReader GetMessageReader() const;
    Windows::Foundation::IAsyncAction MarkMessagesAsReadAsync() const;
    Windows::Foundation::IAsyncAction MarkMessagesAsReadAsync(const Windows::Foundation::DateTime & value) const;
    Windows::Foundation::IAsyncAction SaveAsync() const;
    void NotifyLocalParticipantComposing(hstring_view transportId, hstring_view participantAddress, bool isComposing) const;
    void NotifyRemoteParticipantComposing(hstring_view transportId, hstring_view participantAddress, bool isComposing) const;
    event_token RemoteParticipantComposingChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Chat::ChatConversation, Windows::ApplicationModel::Chat::RemoteParticipantComposingChangedEventArgs> & handler) const;
    using RemoteParticipantComposingChanged_revoker = event_revoker<IChatConversation>;
    RemoteParticipantComposingChanged_revoker RemoteParticipantComposingChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Chat::ChatConversation, Windows::ApplicationModel::Chat::RemoteParticipantComposingChangedEventArgs> & handler) const;
    void RemoteParticipantComposingChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IChatConversation2
{
    bool CanModifyParticipants() const;
    void CanModifyParticipants(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IChatConversationReader
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::ChatConversation>> ReadBatchAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::ChatConversation>> ReadBatchAsync(int32_t count) const;
};

template <typename D>
struct WINRT_EBO impl_IChatConversationThreadingInfo
{
    hstring ContactId() const;
    void ContactId(hstring_view value) const;
    hstring Custom() const;
    void Custom(hstring_view value) const;
    hstring ConversationId() const;
    void ConversationId(hstring_view value) const;
    Windows::Foundation::Collections::IVector<hstring> Participants() const;
    Windows::ApplicationModel::Chat::ChatConversationThreadingKind Kind() const;
    void Kind(Windows::ApplicationModel::Chat::ChatConversationThreadingKind value) const;
};

template <typename D>
struct WINRT_EBO impl_IChatItem
{
    Windows::ApplicationModel::Chat::ChatItemKind ItemKind() const;
};

template <typename D>
struct WINRT_EBO impl_IChatMessage
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Chat::ChatMessageAttachment> Attachments() const;
    hstring Body() const;
    void Body(hstring_view value) const;
    hstring From() const;
    hstring Id() const;
    bool IsForwardingDisabled() const;
    bool IsIncoming() const;
    bool IsRead() const;
    Windows::Foundation::DateTime LocalTimestamp() const;
    Windows::Foundation::DateTime NetworkTimestamp() const;
    Windows::Foundation::Collections::IVector<hstring> Recipients() const;
    Windows::Foundation::Collections::IMapView<hstring, winrt::Windows::ApplicationModel::Chat::ChatMessageStatus> RecipientSendStatuses() const;
    Windows::ApplicationModel::Chat::ChatMessageStatus Status() const;
    hstring Subject() const;
    hstring TransportFriendlyName() const;
    hstring TransportId() const;
    void TransportId(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IChatMessage2
{
    uint64_t EstimatedDownloadSize() const;
    void EstimatedDownloadSize(uint64_t value) const;
    void From(hstring_view value) const;
    bool IsAutoReply() const;
    void IsAutoReply(bool value) const;
    void IsForwardingDisabled(bool value) const;
    bool IsReplyDisabled() const;
    void IsIncoming(bool value) const;
    void IsRead(bool value) const;
    bool IsSeen() const;
    void IsSeen(bool value) const;
    bool IsSimMessage() const;
    void LocalTimestamp(const Windows::Foundation::DateTime & value) const;
    Windows::ApplicationModel::Chat::ChatMessageKind MessageKind() const;
    void MessageKind(Windows::ApplicationModel::Chat::ChatMessageKind value) const;
    Windows::ApplicationModel::Chat::ChatMessageOperatorKind MessageOperatorKind() const;
    void MessageOperatorKind(Windows::ApplicationModel::Chat::ChatMessageOperatorKind value) const;
    void NetworkTimestamp(const Windows::Foundation::DateTime & value) const;
    bool IsReceivedDuringQuietHours() const;
    void IsReceivedDuringQuietHours(bool value) const;
    void RemoteId(hstring_view value) const;
    void Status(Windows::ApplicationModel::Chat::ChatMessageStatus value) const;
    void Subject(hstring_view value) const;
    bool ShouldSuppressNotification() const;
    void ShouldSuppressNotification(bool value) const;
    Windows::ApplicationModel::Chat::ChatConversationThreadingInfo ThreadingInfo() const;
    void ThreadingInfo(const Windows::ApplicationModel::Chat::ChatConversationThreadingInfo & value) const;
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Chat::ChatRecipientDeliveryInfo> RecipientsDeliveryInfos() const;
};

template <typename D>
struct WINRT_EBO impl_IChatMessage3
{
    hstring RemoteId() const;
};

template <typename D>
struct WINRT_EBO impl_IChatMessage4
{
    hstring SyncId() const;
    void SyncId(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IChatMessageAttachment
{
    Windows::Storage::Streams::IRandomAccessStreamReference DataStreamReference() const;
    void DataStreamReference(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const;
    uint32_t GroupId() const;
    void GroupId(uint32_t value) const;
    hstring MimeType() const;
    void MimeType(hstring_view value) const;
    hstring Text() const;
    void Text(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IChatMessageAttachment2
{
    Windows::Storage::Streams::IRandomAccessStreamReference Thumbnail() const;
    void Thumbnail(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const;
    double TransferProgress() const;
    void TransferProgress(double value) const;
    hstring OriginalFileName() const;
    void OriginalFileName(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IChatMessageAttachmentFactory
{
    Windows::ApplicationModel::Chat::ChatMessageAttachment CreateChatMessageAttachment(hstring_view mimeType, const Windows::Storage::Streams::IRandomAccessStreamReference & dataStreamReference) const;
};

template <typename D>
struct WINRT_EBO impl_IChatMessageBlockingStatic
{
    Windows::Foundation::IAsyncAction MarkMessageAsBlockedAsync(hstring_view localChatMessageId, bool blocked) const;
};

template <typename D>
struct WINRT_EBO impl_IChatMessageChange
{
    Windows::ApplicationModel::Chat::ChatMessageChangeType ChangeType() const;
    Windows::ApplicationModel::Chat::ChatMessage Message() const;
};

template <typename D>
struct WINRT_EBO impl_IChatMessageChangeReader
{
    void AcceptChanges() const;
    void AcceptChangesThrough(const Windows::ApplicationModel::Chat::ChatMessageChange & lastChangeToAcknowledge) const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::ChatMessageChange>> ReadBatchAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IChatMessageChangeTracker
{
    void Enable() const;
    Windows::ApplicationModel::Chat::ChatMessageChangeReader GetChangeReader() const;
    void Reset() const;
};

template <typename D>
struct WINRT_EBO impl_IChatMessageChangedDeferral
{
    void Complete() const;
};

template <typename D>
struct WINRT_EBO impl_IChatMessageChangedEventArgs
{
    Windows::ApplicationModel::Chat::ChatMessageChangedDeferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IChatMessageManager2Statics
{
    Windows::Foundation::IAsyncOperation<hstring> RegisterTransportAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatMessageTransport> GetTransportAsync(hstring_view transportId) const;
};

template <typename D>
struct WINRT_EBO impl_IChatMessageManagerStatic
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::ChatMessageTransport>> GetTransportsAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatMessageStore> RequestStoreAsync() const;
    Windows::Foundation::IAsyncAction ShowComposeSmsMessageAsync(const Windows::ApplicationModel::Chat::ChatMessage & message) const;
    void ShowSmsSettings() const;
};

template <typename D>
struct WINRT_EBO impl_IChatMessageManagerStatics3
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatSyncManager> RequestSyncManagerAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IChatMessageNotificationTriggerDetails
{
    Windows::ApplicationModel::Chat::ChatMessage ChatMessage() const;
};

template <typename D>
struct WINRT_EBO impl_IChatMessageNotificationTriggerDetails2
{
    bool ShouldDisplayToast() const;
    bool ShouldUpdateDetailText() const;
    bool ShouldUpdateBadge() const;
    bool ShouldUpdateActionCenter() const;
};

template <typename D>
struct WINRT_EBO impl_IChatMessageReader
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::ChatMessage>> ReadBatchAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IChatMessageReader2
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::ChatMessage>> ReadBatchAsync(int32_t count) const;
};

template <typename D>
struct WINRT_EBO impl_IChatMessageStore
{
    Windows::ApplicationModel::Chat::ChatMessageChangeTracker ChangeTracker() const;
    Windows::Foundation::IAsyncAction DeleteMessageAsync(hstring_view localMessageId) const;
    Windows::Foundation::IAsyncAction DownloadMessageAsync(hstring_view localChatMessageId) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatMessage> GetMessageAsync(hstring_view localChatMessageId) const;
    Windows::ApplicationModel::Chat::ChatMessageReader GetMessageReader() const;
    Windows::ApplicationModel::Chat::ChatMessageReader GetMessageReader(const Windows::Foundation::TimeSpan & recentTimeLimit) const;
    Windows::Foundation::IAsyncAction MarkMessageReadAsync(hstring_view localChatMessageId) const;
    Windows::Foundation::IAsyncAction RetrySendMessageAsync(hstring_view localChatMessageId) const;
    Windows::Foundation::IAsyncAction SendMessageAsync(const Windows::ApplicationModel::Chat::ChatMessage & chatMessage) const;
    Windows::ApplicationModel::Chat::ChatMessageValidationResult ValidateMessage(const Windows::ApplicationModel::Chat::ChatMessage & chatMessage) const;
    event_token MessageChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Chat::ChatMessageStore, Windows::ApplicationModel::Chat::ChatMessageChangedEventArgs> & value) const;
    using MessageChanged_revoker = event_revoker<IChatMessageStore>;
    MessageChanged_revoker MessageChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Chat::ChatMessageStore, Windows::ApplicationModel::Chat::ChatMessageChangedEventArgs> & value) const;
    void MessageChanged(event_token value) const;
};

template <typename D>
struct WINRT_EBO impl_IChatMessageStore2
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatMessage> ForwardMessageAsync(hstring_view localChatMessageId, iterable<hstring> addresses) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatConversation> GetConversationAsync(hstring_view conversationId) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatConversation> GetConversationAsync(hstring_view conversationId, iterable<hstring> transportIds) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatConversation> GetConversationFromThreadingInfoAsync(const Windows::ApplicationModel::Chat::ChatConversationThreadingInfo & threadingInfo) const;
    Windows::ApplicationModel::Chat::ChatConversationReader GetConversationReader() const;
    Windows::ApplicationModel::Chat::ChatConversationReader GetConversationReader(iterable<hstring> transportIds) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatMessage> GetMessageByRemoteIdAsync(hstring_view transportId, hstring_view remoteId) const;
    Windows::Foundation::IAsyncOperation<int32_t> GetUnseenCountAsync() const;
    Windows::Foundation::IAsyncOperation<int32_t> GetUnseenCountAsync(iterable<hstring> transportIds) const;
    Windows::Foundation::IAsyncAction MarkAsSeenAsync() const;
    Windows::Foundation::IAsyncAction MarkAsSeenAsync(iterable<hstring> transportIds) const;
    Windows::ApplicationModel::Chat::ChatSearchReader GetSearchReader(const Windows::ApplicationModel::Chat::ChatQueryOptions & value) const;
    Windows::Foundation::IAsyncAction SaveMessageAsync(const Windows::ApplicationModel::Chat::ChatMessage & chatMessage) const;
    Windows::Foundation::IAsyncOperation<bool> TryCancelDownloadMessageAsync(hstring_view localChatMessageId) const;
    Windows::Foundation::IAsyncOperation<bool> TryCancelSendMessageAsync(hstring_view localChatMessageId) const;
    event_token StoreChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Chat::ChatMessageStore, Windows::ApplicationModel::Chat::ChatMessageStoreChangedEventArgs> & handler) const;
    using StoreChanged_revoker = event_revoker<IChatMessageStore2>;
    StoreChanged_revoker StoreChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Chat::ChatMessageStore, Windows::ApplicationModel::Chat::ChatMessageStoreChangedEventArgs> & handler) const;
    void StoreChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IChatMessageStore3
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::ChatMessage> GetMessageBySyncIdAsync(hstring_view syncId) const;
};

template <typename D>
struct WINRT_EBO impl_IChatMessageStoreChangedEventArgs
{
    hstring Id() const;
    Windows::ApplicationModel::Chat::ChatStoreChangedEventKind Kind() const;
};

template <typename D>
struct WINRT_EBO impl_IChatMessageTransport
{
    bool IsAppSetAsNotificationProvider() const;
    bool IsActive() const;
    hstring TransportFriendlyName() const;
    hstring TransportId() const;
    Windows::Foundation::IAsyncAction RequestSetAsNotificationProviderAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IChatMessageTransport2
{
    Windows::ApplicationModel::Chat::ChatMessageTransportConfiguration Configuration() const;
    Windows::ApplicationModel::Chat::ChatMessageTransportKind TransportKind() const;
};

template <typename D>
struct WINRT_EBO impl_IChatMessageTransportConfiguration
{
    int32_t MaxAttachmentCount() const;
    int32_t MaxMessageSizeInKilobytes() const;
    int32_t MaxRecipientCount() const;
    Windows::Media::MediaProperties::MediaEncodingProfile SupportedVideoFormat() const;
    Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> ExtendedProperties() const;
};

template <typename D>
struct WINRT_EBO impl_IChatMessageValidationResult
{
    Windows::Foundation::IReference<uint32_t> MaxPartCount() const;
    Windows::Foundation::IReference<uint32_t> PartCount() const;
    Windows::Foundation::IReference<uint32_t> RemainingCharacterCountInPart() const;
    Windows::ApplicationModel::Chat::ChatMessageValidationStatus Status() const;
};

template <typename D>
struct WINRT_EBO impl_IChatQueryOptions
{
    hstring SearchString() const;
    void SearchString(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IChatRecipientDeliveryInfo
{
    hstring TransportAddress() const;
    void TransportAddress(hstring_view value) const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> DeliveryTime() const;
    void DeliveryTime(const optional<Windows::Foundation::DateTime> & value) const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> ReadTime() const;
    void ReadTime(const optional<Windows::Foundation::DateTime> & value) const;
    Windows::ApplicationModel::Chat::ChatTransportErrorCodeCategory TransportErrorCodeCategory() const;
    Windows::ApplicationModel::Chat::ChatTransportInterpretedErrorCode TransportInterpretedErrorCode() const;
    int32_t TransportErrorCode() const;
    bool IsErrorPermanent() const;
    Windows::ApplicationModel::Chat::ChatMessageStatus Status() const;
};

template <typename D>
struct WINRT_EBO impl_IChatSearchReader
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::IChatItem>> ReadBatchAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::IChatItem>> ReadBatchAsync(int32_t count) const;
};

template <typename D>
struct WINRT_EBO impl_IChatSyncConfiguration
{
    bool IsSyncEnabled() const;
    void IsSyncEnabled(bool value) const;
    Windows::ApplicationModel::Chat::ChatRestoreHistorySpan RestoreHistorySpan() const;
    void RestoreHistorySpan(Windows::ApplicationModel::Chat::ChatRestoreHistorySpan value) const;
};

template <typename D>
struct WINRT_EBO impl_IChatSyncManager
{
    Windows::ApplicationModel::Chat::ChatSyncConfiguration Configuration() const;
    Windows::Foundation::IAsyncAction AssociateAccountAsync(const Windows::Security::Credentials::WebAccount & webAccount) const;
    Windows::Foundation::IAsyncAction UnassociateAccountAsync() const;
    bool IsAccountAssociated(const Windows::Security::Credentials::WebAccount & webAccount) const;
    void StartSync() const;
    Windows::Foundation::IAsyncAction SetConfigurationAsync(const Windows::ApplicationModel::Chat::ChatSyncConfiguration & configuration) const;
};

template <typename D>
struct WINRT_EBO impl_IRcsEndUserMessage
{
    hstring TransportId() const;
    hstring Title() const;
    hstring Text() const;
    bool IsPinRequired() const;
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::RcsEndUserMessageAction> Actions() const;
    Windows::Foundation::IAsyncAction SendResponseAsync(const Windows::ApplicationModel::Chat::RcsEndUserMessageAction & action) const;
    Windows::Foundation::IAsyncAction SendResponseWithPinAsync(const Windows::ApplicationModel::Chat::RcsEndUserMessageAction & action, hstring_view pin) const;
};

template <typename D>
struct WINRT_EBO impl_IRcsEndUserMessageAction
{
    hstring Label() const;
};

template <typename D>
struct WINRT_EBO impl_IRcsEndUserMessageAvailableEventArgs
{
    bool IsMessageAvailable() const;
    Windows::ApplicationModel::Chat::RcsEndUserMessage Message() const;
};

template <typename D>
struct WINRT_EBO impl_IRcsEndUserMessageAvailableTriggerDetails
{
    hstring Title() const;
    hstring Text() const;
};

template <typename D>
struct WINRT_EBO impl_IRcsEndUserMessageManager
{
    event_token MessageAvailableChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Chat::RcsEndUserMessageManager, Windows::ApplicationModel::Chat::RcsEndUserMessageAvailableEventArgs> & handler) const;
    using MessageAvailableChanged_revoker = event_revoker<IRcsEndUserMessageManager>;
    MessageAvailableChanged_revoker MessageAvailableChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Chat::RcsEndUserMessageManager, Windows::ApplicationModel::Chat::RcsEndUserMessageAvailableEventArgs> & handler) const;
    void MessageAvailableChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IRcsManagerStatics
{
    Windows::ApplicationModel::Chat::RcsEndUserMessageManager GetEndUserMessageManager() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Chat::RcsTransport>> GetTransportsAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Chat::RcsTransport> GetTransportAsync(hstring_view transportId) const;
    Windows::Foundation::IAsyncAction LeaveConversationAsync(const Windows::ApplicationModel::Chat::ChatConversation & conversation) const;
};

template <typename D>
struct WINRT_EBO impl_IRcsServiceKindSupportedChangedEventArgs
{
    Windows::ApplicationModel::Chat::RcsServiceKind ServiceKind() const;
};

template <typename D>
struct WINRT_EBO impl_IRcsTransport
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> ExtendedProperties() const;
    bool IsActive() const;
    hstring TransportFriendlyName() const;
    hstring TransportId() const;
    Windows::ApplicationModel::Chat::RcsTransportConfiguration Configuration() const;
    bool IsStoreAndForwardEnabled(Windows::ApplicationModel::Chat::RcsServiceKind serviceKind) const;
    bool IsServiceKindSupported(Windows::ApplicationModel::Chat::RcsServiceKind serviceKind) const;
    event_token ServiceKindSupportedChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Chat::RcsTransport, Windows::ApplicationModel::Chat::RcsServiceKindSupportedChangedEventArgs> & handler) const;
    using ServiceKindSupportedChanged_revoker = event_revoker<IRcsTransport>;
    ServiceKindSupportedChanged_revoker ServiceKindSupportedChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Chat::RcsTransport, Windows::ApplicationModel::Chat::RcsServiceKindSupportedChangedEventArgs> & handler) const;
    void ServiceKindSupportedChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IRcsTransportConfiguration
{
    int32_t MaxAttachmentCount() const;
    int32_t MaxMessageSizeInKilobytes() const;
    int32_t MaxGroupMessageSizeInKilobytes() const;
    int32_t MaxRecipientCount() const;
    int32_t MaxFileSizeInKilobytes() const;
    int32_t WarningFileSizeInKilobytes() const;
};

template <typename D>
struct WINRT_EBO impl_IRemoteParticipantComposingChangedEventArgs
{
    hstring TransportId() const;
    hstring ParticipantAddress() const;
    bool IsComposing() const;
};

}

namespace impl {

template <> struct traits<Windows::ApplicationModel::Chat::IChatCapabilities>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatCapabilities;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatCapabilities<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatCapabilitiesManagerStatics>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatCapabilitiesManagerStatics;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatCapabilitiesManagerStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatConversation>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatConversation;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatConversation<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatConversation2>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatConversation2;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatConversation2<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatConversationReader>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatConversationReader;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatConversationReader<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatConversationThreadingInfo>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatConversationThreadingInfo;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatConversationThreadingInfo<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatItem>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatItem;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatItem<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatMessage>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatMessage;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatMessage<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatMessage2>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatMessage2;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatMessage2<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatMessage3>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatMessage3;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatMessage3<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatMessage4>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatMessage4;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatMessage4<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatMessageAttachment>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatMessageAttachment;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatMessageAttachment<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatMessageAttachment2>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatMessageAttachment2;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatMessageAttachment2<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatMessageAttachmentFactory>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatMessageAttachmentFactory;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatMessageAttachmentFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatMessageBlockingStatic>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatMessageBlockingStatic;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatMessageBlockingStatic<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatMessageChange>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatMessageChange;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatMessageChange<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatMessageChangeReader>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatMessageChangeReader;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatMessageChangeReader<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatMessageChangeTracker>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatMessageChangeTracker;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatMessageChangeTracker<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatMessageChangedDeferral>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatMessageChangedDeferral;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatMessageChangedDeferral<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatMessageChangedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatMessageChangedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatMessageChangedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatMessageManager2Statics>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatMessageManager2Statics;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatMessageManager2Statics<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatMessageManagerStatic>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatMessageManagerStatic;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatMessageManagerStatic<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatMessageManagerStatics3>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatMessageManagerStatics3;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatMessageManagerStatics3<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatMessageNotificationTriggerDetails>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatMessageNotificationTriggerDetails;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatMessageNotificationTriggerDetails<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatMessageNotificationTriggerDetails2>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatMessageNotificationTriggerDetails2;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatMessageNotificationTriggerDetails2<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatMessageReader>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatMessageReader;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatMessageReader<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatMessageReader2>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatMessageReader2;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatMessageReader2<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatMessageStore>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatMessageStore;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatMessageStore<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatMessageStore2>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatMessageStore2;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatMessageStore2<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatMessageStore3>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatMessageStore3;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatMessageStore3<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatMessageStoreChangedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatMessageStoreChangedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatMessageStoreChangedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatMessageTransport>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatMessageTransport;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatMessageTransport<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatMessageTransport2>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatMessageTransport2;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatMessageTransport2<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatMessageTransportConfiguration>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatMessageTransportConfiguration;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatMessageTransportConfiguration<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatMessageValidationResult>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatMessageValidationResult;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatMessageValidationResult<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatQueryOptions>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatQueryOptions;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatQueryOptions<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatRecipientDeliveryInfo>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatRecipientDeliveryInfo;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatRecipientDeliveryInfo<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatSearchReader>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatSearchReader;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatSearchReader<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatSyncConfiguration>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatSyncConfiguration;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatSyncConfiguration<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IChatSyncManager>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IChatSyncManager;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IChatSyncManager<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IRcsEndUserMessage>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IRcsEndUserMessage;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IRcsEndUserMessage<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IRcsEndUserMessageAction>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IRcsEndUserMessageAction;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IRcsEndUserMessageAction<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IRcsEndUserMessageAvailableEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IRcsEndUserMessageAvailableEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IRcsEndUserMessageAvailableEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IRcsEndUserMessageAvailableTriggerDetails>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IRcsEndUserMessageAvailableTriggerDetails;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IRcsEndUserMessageAvailableTriggerDetails<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IRcsEndUserMessageManager>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IRcsEndUserMessageManager;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IRcsEndUserMessageManager<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IRcsManagerStatics>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IRcsManagerStatics;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IRcsManagerStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IRcsServiceKindSupportedChangedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IRcsServiceKindSupportedChangedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IRcsServiceKindSupportedChangedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IRcsTransport>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IRcsTransport;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IRcsTransport<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IRcsTransportConfiguration>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IRcsTransportConfiguration;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IRcsTransportConfiguration<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::IRemoteParticipantComposingChangedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Chat::IRemoteParticipantComposingChangedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Chat::impl_IRemoteParticipantComposingChangedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Chat::ChatCapabilities>
{
    using abi = ABI::Windows::ApplicationModel::Chat::ChatCapabilities;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Chat.ChatCapabilities"; }
};

template <> struct traits<Windows::ApplicationModel::Chat::ChatCapabilitiesManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Chat.ChatCapabilitiesManager"; }
};

template <> struct traits<Windows::ApplicationModel::Chat::ChatConversation>
{
    using abi = ABI::Windows::ApplicationModel::Chat::ChatConversation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Chat.ChatConversation"; }
};

template <> struct traits<Windows::ApplicationModel::Chat::ChatConversationReader>
{
    using abi = ABI::Windows::ApplicationModel::Chat::ChatConversationReader;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Chat.ChatConversationReader"; }
};

template <> struct traits<Windows::ApplicationModel::Chat::ChatConversationThreadingInfo>
{
    using abi = ABI::Windows::ApplicationModel::Chat::ChatConversationThreadingInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Chat.ChatConversationThreadingInfo"; }
};

template <> struct traits<Windows::ApplicationModel::Chat::ChatMessage>
{
    using abi = ABI::Windows::ApplicationModel::Chat::ChatMessage;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Chat.ChatMessage"; }
};

template <> struct traits<Windows::ApplicationModel::Chat::ChatMessageAttachment>
{
    using abi = ABI::Windows::ApplicationModel::Chat::ChatMessageAttachment;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Chat.ChatMessageAttachment"; }
};

template <> struct traits<Windows::ApplicationModel::Chat::ChatMessageBlocking>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Chat.ChatMessageBlocking"; }
};

template <> struct traits<Windows::ApplicationModel::Chat::ChatMessageChange>
{
    using abi = ABI::Windows::ApplicationModel::Chat::ChatMessageChange;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Chat.ChatMessageChange"; }
};

template <> struct traits<Windows::ApplicationModel::Chat::ChatMessageChangeReader>
{
    using abi = ABI::Windows::ApplicationModel::Chat::ChatMessageChangeReader;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Chat.ChatMessageChangeReader"; }
};

template <> struct traits<Windows::ApplicationModel::Chat::ChatMessageChangeTracker>
{
    using abi = ABI::Windows::ApplicationModel::Chat::ChatMessageChangeTracker;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Chat.ChatMessageChangeTracker"; }
};

template <> struct traits<Windows::ApplicationModel::Chat::ChatMessageChangedDeferral>
{
    using abi = ABI::Windows::ApplicationModel::Chat::ChatMessageChangedDeferral;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Chat.ChatMessageChangedDeferral"; }
};

template <> struct traits<Windows::ApplicationModel::Chat::ChatMessageChangedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Chat::ChatMessageChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Chat.ChatMessageChangedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Chat::ChatMessageManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Chat.ChatMessageManager"; }
};

template <> struct traits<Windows::ApplicationModel::Chat::ChatMessageNotificationTriggerDetails>
{
    using abi = ABI::Windows::ApplicationModel::Chat::ChatMessageNotificationTriggerDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Chat.ChatMessageNotificationTriggerDetails"; }
};

template <> struct traits<Windows::ApplicationModel::Chat::ChatMessageReader>
{
    using abi = ABI::Windows::ApplicationModel::Chat::ChatMessageReader;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Chat.ChatMessageReader"; }
};

template <> struct traits<Windows::ApplicationModel::Chat::ChatMessageStore>
{
    using abi = ABI::Windows::ApplicationModel::Chat::ChatMessageStore;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Chat.ChatMessageStore"; }
};

template <> struct traits<Windows::ApplicationModel::Chat::ChatMessageStoreChangedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Chat::ChatMessageStoreChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Chat.ChatMessageStoreChangedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Chat::ChatMessageTransport>
{
    using abi = ABI::Windows::ApplicationModel::Chat::ChatMessageTransport;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Chat.ChatMessageTransport"; }
};

template <> struct traits<Windows::ApplicationModel::Chat::ChatMessageTransportConfiguration>
{
    using abi = ABI::Windows::ApplicationModel::Chat::ChatMessageTransportConfiguration;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Chat.ChatMessageTransportConfiguration"; }
};

template <> struct traits<Windows::ApplicationModel::Chat::ChatMessageValidationResult>
{
    using abi = ABI::Windows::ApplicationModel::Chat::ChatMessageValidationResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Chat.ChatMessageValidationResult"; }
};

template <> struct traits<Windows::ApplicationModel::Chat::ChatQueryOptions>
{
    using abi = ABI::Windows::ApplicationModel::Chat::ChatQueryOptions;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Chat.ChatQueryOptions"; }
};

template <> struct traits<Windows::ApplicationModel::Chat::ChatRecipientDeliveryInfo>
{
    using abi = ABI::Windows::ApplicationModel::Chat::ChatRecipientDeliveryInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Chat.ChatRecipientDeliveryInfo"; }
};

template <> struct traits<Windows::ApplicationModel::Chat::ChatSearchReader>
{
    using abi = ABI::Windows::ApplicationModel::Chat::ChatSearchReader;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Chat.ChatSearchReader"; }
};

template <> struct traits<Windows::ApplicationModel::Chat::ChatSyncConfiguration>
{
    using abi = ABI::Windows::ApplicationModel::Chat::ChatSyncConfiguration;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Chat.ChatSyncConfiguration"; }
};

template <> struct traits<Windows::ApplicationModel::Chat::ChatSyncManager>
{
    using abi = ABI::Windows::ApplicationModel::Chat::ChatSyncManager;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Chat.ChatSyncManager"; }
};

template <> struct traits<Windows::ApplicationModel::Chat::RcsEndUserMessage>
{
    using abi = ABI::Windows::ApplicationModel::Chat::RcsEndUserMessage;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Chat.RcsEndUserMessage"; }
};

template <> struct traits<Windows::ApplicationModel::Chat::RcsEndUserMessageAction>
{
    using abi = ABI::Windows::ApplicationModel::Chat::RcsEndUserMessageAction;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Chat.RcsEndUserMessageAction"; }
};

template <> struct traits<Windows::ApplicationModel::Chat::RcsEndUserMessageAvailableEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Chat::RcsEndUserMessageAvailableEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Chat.RcsEndUserMessageAvailableEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Chat::RcsEndUserMessageAvailableTriggerDetails>
{
    using abi = ABI::Windows::ApplicationModel::Chat::RcsEndUserMessageAvailableTriggerDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Chat.RcsEndUserMessageAvailableTriggerDetails"; }
};

template <> struct traits<Windows::ApplicationModel::Chat::RcsEndUserMessageManager>
{
    using abi = ABI::Windows::ApplicationModel::Chat::RcsEndUserMessageManager;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Chat.RcsEndUserMessageManager"; }
};

template <> struct traits<Windows::ApplicationModel::Chat::RcsManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Chat.RcsManager"; }
};

template <> struct traits<Windows::ApplicationModel::Chat::RcsServiceKindSupportedChangedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Chat::RcsServiceKindSupportedChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Chat.RcsServiceKindSupportedChangedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Chat::RcsTransport>
{
    using abi = ABI::Windows::ApplicationModel::Chat::RcsTransport;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Chat.RcsTransport"; }
};

template <> struct traits<Windows::ApplicationModel::Chat::RcsTransportConfiguration>
{
    using abi = ABI::Windows::ApplicationModel::Chat::RcsTransportConfiguration;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Chat.RcsTransportConfiguration"; }
};

template <> struct traits<Windows::ApplicationModel::Chat::RemoteParticipantComposingChangedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Chat::RemoteParticipantComposingChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Chat.RemoteParticipantComposingChangedEventArgs"; }
};

}

}
