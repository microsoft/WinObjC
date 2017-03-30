// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.ApplicationModel.Email.0.h"
#include "Windows.ApplicationModel.Appointments.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.System.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Security.Cryptography.Certificates.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::Email {

struct __declspec(uuid("f353caf9-57c8-4adb-b992-60fceb584f54")) __declspec(novtable) IEmailAttachment : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FileName(hstring * value) = 0;
    virtual HRESULT __stdcall put_FileName(hstring value) = 0;
    virtual HRESULT __stdcall get_Data(Windows::Storage::Streams::IRandomAccessStreamReference ** value) = 0;
    virtual HRESULT __stdcall put_Data(Windows::Storage::Streams::IRandomAccessStreamReference * value) = 0;
};

struct __declspec(uuid("225f1070-b0ff-4571-9d54-a706c48d55c6")) __declspec(novtable) IEmailAttachment2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall get_ContentId(hstring * value) = 0;
    virtual HRESULT __stdcall put_ContentId(hstring value) = 0;
    virtual HRESULT __stdcall get_ContentLocation(hstring * value) = 0;
    virtual HRESULT __stdcall put_ContentLocation(hstring value) = 0;
    virtual HRESULT __stdcall get_DownloadState(winrt::Windows::ApplicationModel::Email::EmailAttachmentDownloadState * value) = 0;
    virtual HRESULT __stdcall put_DownloadState(winrt::Windows::ApplicationModel::Email::EmailAttachmentDownloadState value) = 0;
    virtual HRESULT __stdcall get_EstimatedDownloadSizeInBytes(uint64_t * value) = 0;
    virtual HRESULT __stdcall put_EstimatedDownloadSizeInBytes(uint64_t value) = 0;
    virtual HRESULT __stdcall get_IsFromBaseMessage(bool * value) = 0;
    virtual HRESULT __stdcall get_IsInline(bool * value) = 0;
    virtual HRESULT __stdcall put_IsInline(bool value) = 0;
    virtual HRESULT __stdcall get_MimeType(hstring * value) = 0;
    virtual HRESULT __stdcall put_MimeType(hstring value) = 0;
};

struct __declspec(uuid("796eac46-ed56-4979-8708-abb8bc854b7d")) __declspec(novtable) IEmailAttachmentFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(hstring fileName, Windows::Storage::Streams::IRandomAccessStreamReference * data, Windows::ApplicationModel::Email::IEmailAttachment ** result) = 0;
};

struct __declspec(uuid("23259435-51f9-427d-adcd-241023c8cfb7")) __declspec(novtable) IEmailAttachmentFactory2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(hstring fileName, Windows::Storage::Streams::IRandomAccessStreamReference * data, hstring mimeType, Windows::ApplicationModel::Email::IEmailAttachment ** result) = 0;
};

struct __declspec(uuid("da18c248-a0bc-4349-902d-90f66389f51b")) __declspec(novtable) IEmailConversation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall get_MailboxId(hstring * value) = 0;
    virtual HRESULT __stdcall get_FlagState(winrt::Windows::ApplicationModel::Email::EmailFlagState * value) = 0;
    virtual HRESULT __stdcall get_HasAttachment(bool * value) = 0;
    virtual HRESULT __stdcall get_Importance(winrt::Windows::ApplicationModel::Email::EmailImportance * value) = 0;
    virtual HRESULT __stdcall get_LastEmailResponseKind(winrt::Windows::ApplicationModel::Email::EmailMessageResponseKind * value) = 0;
    virtual HRESULT __stdcall get_MessageCount(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_MostRecentMessageId(hstring * value) = 0;
    virtual HRESULT __stdcall get_MostRecentMessageTime(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_Preview(hstring * value) = 0;
    virtual HRESULT __stdcall get_LatestSender(Windows::ApplicationModel::Email::IEmailRecipient ** value) = 0;
    virtual HRESULT __stdcall get_Subject(hstring * value) = 0;
    virtual HRESULT __stdcall get_UnreadMessageCount(uint32_t * value) = 0;
    virtual HRESULT __stdcall abi_FindMessagesAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMessage>> ** result) = 0;
    virtual HRESULT __stdcall abi_FindMessagesWithCountAsync(uint32_t count, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMessage>> ** result) = 0;
};

struct __declspec(uuid("b8c1ab81-01c5-432a-9df1-fe85d98a279a")) __declspec(novtable) IEmailConversationBatch : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Conversations(Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailConversation> ** value) = 0;
    virtual HRESULT __stdcall get_Status(winrt::Windows::ApplicationModel::Email::EmailBatchStatus * value) = 0;
};

struct __declspec(uuid("b4630f82-2875-44c8-9b8c-85beb3a3c653")) __declspec(novtable) IEmailConversationReader : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ReadBatchAsync(Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailConversationBatch> ** result) = 0;
};

struct __declspec(uuid("a24f7771-996c-4864-b1ba-ed1240e57d11")) __declspec(novtable) IEmailFolder : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall get_RemoteId(hstring * value) = 0;
    virtual HRESULT __stdcall put_RemoteId(hstring value) = 0;
    virtual HRESULT __stdcall get_MailboxId(hstring * value) = 0;
    virtual HRESULT __stdcall get_ParentFolderId(hstring * value) = 0;
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall put_DisplayName(hstring value) = 0;
    virtual HRESULT __stdcall get_IsSyncEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsSyncEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_LastSuccessfulSyncTime(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall put_LastSuccessfulSyncTime(Windows::Foundation::DateTime value) = 0;
    virtual HRESULT __stdcall get_Kind(winrt::Windows::ApplicationModel::Email::EmailSpecialFolderKind * value) = 0;
    virtual HRESULT __stdcall abi_CreateFolderAsync(hstring name, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailFolder> ** result) = 0;
    virtual HRESULT __stdcall abi_DeleteAsync(Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_FindChildFoldersAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailFolder>> ** result) = 0;
    virtual HRESULT __stdcall abi_GetConversationReader(Windows::ApplicationModel::Email::IEmailConversationReader ** result) = 0;
    virtual HRESULT __stdcall abi_GetConversationReaderWithOptions(Windows::ApplicationModel::Email::IEmailQueryOptions * options, Windows::ApplicationModel::Email::IEmailConversationReader ** result) = 0;
    virtual HRESULT __stdcall abi_GetMessageAsync(hstring id, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMessage> ** result) = 0;
    virtual HRESULT __stdcall abi_GetMessageReader(Windows::ApplicationModel::Email::IEmailMessageReader ** result) = 0;
    virtual HRESULT __stdcall abi_GetMessageReaderWithOptions(Windows::ApplicationModel::Email::IEmailQueryOptions * options, Windows::ApplicationModel::Email::IEmailMessageReader ** result) = 0;
    virtual HRESULT __stdcall abi_GetMessageCountsAsync(Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailItemCounts> ** result) = 0;
    virtual HRESULT __stdcall abi_TryMoveAsync(Windows::ApplicationModel::Email::IEmailFolder * newParentFolder, Windows::Foundation::IAsyncOperation<bool> ** result) = 0;
    virtual HRESULT __stdcall abi_TryMoveWithNewNameAsync(Windows::ApplicationModel::Email::IEmailFolder * newParentFolder, hstring newFolderName, Windows::Foundation::IAsyncOperation<bool> ** result) = 0;
    virtual HRESULT __stdcall abi_TrySaveAsync(Windows::Foundation::IAsyncOperation<bool> ** result) = 0;
    virtual HRESULT __stdcall abi_SaveMessageAsync(Windows::ApplicationModel::Email::IEmailMessage * message, Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("90f52193-b1a0-4ebd-a6b6-ddca55606e0e")) __declspec(novtable) IEmailIrmInfo : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CanEdit(bool * value) = 0;
    virtual HRESULT __stdcall put_CanEdit(bool value) = 0;
    virtual HRESULT __stdcall get_CanExtractData(bool * value) = 0;
    virtual HRESULT __stdcall put_CanExtractData(bool value) = 0;
    virtual HRESULT __stdcall get_CanForward(bool * value) = 0;
    virtual HRESULT __stdcall put_CanForward(bool value) = 0;
    virtual HRESULT __stdcall get_CanModifyRecipientsOnResponse(bool * value) = 0;
    virtual HRESULT __stdcall put_CanModifyRecipientsOnResponse(bool value) = 0;
    virtual HRESULT __stdcall get_CanPrintData(bool * value) = 0;
    virtual HRESULT __stdcall put_CanPrintData(bool value) = 0;
    virtual HRESULT __stdcall get_CanRemoveIrmOnResponse(bool * value) = 0;
    virtual HRESULT __stdcall put_CanRemoveIrmOnResponse(bool value) = 0;
    virtual HRESULT __stdcall get_CanReply(bool * value) = 0;
    virtual HRESULT __stdcall put_CanReply(bool value) = 0;
    virtual HRESULT __stdcall get_CanReplyAll(bool * value) = 0;
    virtual HRESULT __stdcall put_CanReplyAll(bool value) = 0;
    virtual HRESULT __stdcall get_ExpirationDate(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall put_ExpirationDate(Windows::Foundation::DateTime value) = 0;
    virtual HRESULT __stdcall get_IsIrmOriginator(bool * value) = 0;
    virtual HRESULT __stdcall put_IsIrmOriginator(bool value) = 0;
    virtual HRESULT __stdcall get_IsProgramaticAccessAllowed(bool * value) = 0;
    virtual HRESULT __stdcall put_IsProgramaticAccessAllowed(bool value) = 0;
    virtual HRESULT __stdcall get_Template(Windows::ApplicationModel::Email::IEmailIrmTemplate ** value) = 0;
    virtual HRESULT __stdcall put_Template(Windows::ApplicationModel::Email::IEmailIrmTemplate * value) = 0;
};

struct __declspec(uuid("314bb18c-e3e6-4d7b-be8d-91a96311b01b")) __declspec(novtable) IEmailIrmInfoFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Foundation::DateTime expiration, Windows::ApplicationModel::Email::IEmailIrmTemplate * irmTemplate, Windows::ApplicationModel::Email::IEmailIrmInfo ** result) = 0;
};

struct __declspec(uuid("f327758d-546d-4bea-a963-54a38b2cc016")) __declspec(novtable) IEmailIrmTemplate : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall put_Id(hstring value) = 0;
    virtual HRESULT __stdcall get_Description(hstring * value) = 0;
    virtual HRESULT __stdcall put_Description(hstring value) = 0;
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall put_Name(hstring value) = 0;
};

struct __declspec(uuid("3da31876-8738-4418-b9cb-471b936fe71e")) __declspec(novtable) IEmailIrmTemplateFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(hstring id, hstring name, hstring description, Windows::ApplicationModel::Email::IEmailIrmTemplate ** result) = 0;
};

struct __declspec(uuid("5bd13321-fec8-4bab-83ba-0baf3c1f6cbd")) __declspec(novtable) IEmailItemCounts : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Flagged(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_Important(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_Total(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_Unread(uint32_t * value) = 0;
};

struct __declspec(uuid("a8790649-cf5b-411b-80b1-4a6a1484ce25")) __declspec(novtable) IEmailMailbox : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Capabilities(Windows::ApplicationModel::Email::IEmailMailboxCapabilities ** value) = 0;
    virtual HRESULT __stdcall get_ChangeTracker(Windows::ApplicationModel::Email::IEmailMailboxChangeTracker ** value) = 0;
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall put_DisplayName(hstring value) = 0;
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall get_IsOwnedByCurrentApp(bool * value) = 0;
    virtual HRESULT __stdcall get_IsDataEncryptedUnderLock(bool * value) = 0;
    virtual HRESULT __stdcall get_MailAddress(hstring * value) = 0;
    virtual HRESULT __stdcall put_MailAddress(hstring value) = 0;
    virtual HRESULT __stdcall get_MailAddressAliases(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_OtherAppReadAccess(winrt::Windows::ApplicationModel::Email::EmailMailboxOtherAppReadAccess * value) = 0;
    virtual HRESULT __stdcall put_OtherAppReadAccess(winrt::Windows::ApplicationModel::Email::EmailMailboxOtherAppReadAccess value) = 0;
    virtual HRESULT __stdcall get_OtherAppWriteAccess(winrt::Windows::ApplicationModel::Email::EmailMailboxOtherAppWriteAccess * value) = 0;
    virtual HRESULT __stdcall put_OtherAppWriteAccess(winrt::Windows::ApplicationModel::Email::EmailMailboxOtherAppWriteAccess value) = 0;
    virtual HRESULT __stdcall get_Policies(Windows::ApplicationModel::Email::IEmailMailboxPolicies ** value) = 0;
    virtual HRESULT __stdcall get_SourceDisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall get_SyncManager(Windows::ApplicationModel::Email::IEmailMailboxSyncManager ** value) = 0;
    virtual HRESULT __stdcall get_UserDataAccountId(hstring * value) = 0;
    virtual HRESULT __stdcall abi_GetConversationReader(Windows::ApplicationModel::Email::IEmailConversationReader ** result) = 0;
    virtual HRESULT __stdcall abi_GetConversationReaderWithOptions(Windows::ApplicationModel::Email::IEmailQueryOptions * options, Windows::ApplicationModel::Email::IEmailConversationReader ** result) = 0;
    virtual HRESULT __stdcall abi_GetMessageReader(Windows::ApplicationModel::Email::IEmailMessageReader ** result) = 0;
    virtual HRESULT __stdcall abi_GetMessageReaderWithOptions(Windows::ApplicationModel::Email::IEmailQueryOptions * options, Windows::ApplicationModel::Email::IEmailMessageReader ** result) = 0;
    virtual HRESULT __stdcall abi_DeleteAsync(Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_GetConversationAsync(hstring id, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailConversation> ** result) = 0;
    virtual HRESULT __stdcall abi_GetFolderAsync(hstring id, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailFolder> ** result) = 0;
    virtual HRESULT __stdcall abi_GetMessageAsync(hstring id, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMessage> ** result) = 0;
    virtual HRESULT __stdcall abi_GetSpecialFolderAsync(winrt::Windows::ApplicationModel::Email::EmailSpecialFolderKind folderType, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailFolder> ** result) = 0;
    virtual HRESULT __stdcall abi_SaveAsync(Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_MarkMessageAsSeenAsync(hstring messageId, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_MarkFolderAsSeenAsync(hstring folderId, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_MarkMessageReadAsync(hstring messageId, bool isRead, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_ChangeMessageFlagStateAsync(hstring messageId, winrt::Windows::ApplicationModel::Email::EmailFlagState flagState, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_TryMoveMessageAsync(hstring messageId, hstring newParentFolderId, Windows::Foundation::IAsyncOperation<bool> ** result) = 0;
    virtual HRESULT __stdcall abi_TryMoveFolderAsync(hstring folderId, hstring newParentFolderId, Windows::Foundation::IAsyncOperation<bool> ** result) = 0;
    virtual HRESULT __stdcall abi_TryMoveFolderWithNewNameAsync(hstring folderId, hstring newParentFolderId, hstring newFolderName, Windows::Foundation::IAsyncOperation<bool> ** result) = 0;
    virtual HRESULT __stdcall abi_DeleteMessageAsync(hstring messageId, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_MarkFolderSyncEnabledAsync(hstring folderId, bool isSyncEnabled, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_SendMessageAsync(Windows::ApplicationModel::Email::IEmailMessage * message, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_SaveDraftAsync(Windows::ApplicationModel::Email::IEmailMessage * message, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_DownloadMessageAsync(hstring messageId, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_DownloadAttachmentAsync(hstring attachmentId, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_CreateResponseMessageAsync(hstring messageId, winrt::Windows::ApplicationModel::Email::EmailMessageResponseKind responseType, hstring subject, winrt::Windows::ApplicationModel::Email::EmailMessageBodyKind responseHeaderType, hstring responseHeader, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMessage> ** result) = 0;
    virtual HRESULT __stdcall abi_TryUpdateMeetingResponseAsync(Windows::ApplicationModel::Email::IEmailMessage * meeting, winrt::Windows::ApplicationModel::Email::EmailMeetingResponseType response, hstring subject, hstring comment, bool sendUpdate, Windows::Foundation::IAsyncOperation<bool> ** result) = 0;
    virtual HRESULT __stdcall abi_TryForwardMeetingAsync(Windows::ApplicationModel::Email::IEmailMessage * meeting, Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Email::EmailRecipient> * recipients, hstring subject, winrt::Windows::ApplicationModel::Email::EmailMessageBodyKind forwardHeaderType, hstring forwardHeader, hstring comment, Windows::Foundation::IAsyncOperation<bool> ** result) = 0;
    virtual HRESULT __stdcall abi_TryProposeNewTimeForMeetingAsync(Windows::ApplicationModel::Email::IEmailMessage * meeting, Windows::Foundation::DateTime newStartTime, Windows::Foundation::TimeSpan newDuration, hstring subject, hstring comment, Windows::Foundation::IAsyncOperation<bool> ** result) = 0;
    virtual HRESULT __stdcall add_MailboxChanged(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::EmailMailbox, Windows::ApplicationModel::Email::EmailMailboxChangedEventArgs> * pHandler, event_token * pToken) = 0;
    virtual HRESULT __stdcall remove_MailboxChanged(event_token token) = 0;
    virtual HRESULT __stdcall abi_SmartSendMessageAsync(Windows::ApplicationModel::Email::IEmailMessage * message, bool smartSend, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_TrySetAutoReplySettingsAsync(Windows::ApplicationModel::Email::IEmailMailboxAutoReplySettings * autoReplySettings, Windows::Foundation::IAsyncOperation<bool> ** result) = 0;
    virtual HRESULT __stdcall abi_TryGetAutoReplySettingsAsync(winrt::Windows::ApplicationModel::Email::EmailMailboxAutoReplyMessageResponseKind requestedFormat, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMailboxAutoReplySettings> ** autoReplySettings) = 0;
};

struct __declspec(uuid("14f8e404-6ca2-4ab2-9241-79cd7bf46346")) __declspec(novtable) IEmailMailbox2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LinkedMailboxId(hstring * value) = 0;
    virtual HRESULT __stdcall get_NetworkAccountId(hstring * value) = 0;
    virtual HRESULT __stdcall get_NetworkId(hstring * value) = 0;
};

struct __declspec(uuid("3da5897b-458b-408a-8e37-ac8b05d8af56")) __declspec(novtable) IEmailMailbox3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ResolveRecipientsAsync(Windows::Foundation::Collections::IIterable<hstring> * recipients, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailRecipientResolutionResult>> ** result) = 0;
    virtual HRESULT __stdcall abi_ValidateCertificatesAsync(Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate> * certificates, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<winrt::Windows::ApplicationModel::Email::EmailCertificateValidationStatus>> ** result) = 0;
    virtual HRESULT __stdcall abi_TryEmptyFolderAsync(hstring folderId, Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Email::EmailMailboxEmptyFolderStatus> ** result) = 0;
    virtual HRESULT __stdcall abi_TryCreateFolderAsync(hstring parentFolderId, hstring name, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMailboxCreateFolderResult> ** result) = 0;
    virtual HRESULT __stdcall abi_TryDeleteFolderAsync(hstring folderId, Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Email::EmailMailboxDeleteFolderStatus> ** result) = 0;
};

struct __declspec(uuid("5d1f301b-f222-48a7-b7b6-716356cd26a1")) __declspec(novtable) IEmailMailbox4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RegisterSyncManagerAsync(Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("ac9889fa-21fa-4927-9210-d410582fdf3e")) __declspec(novtable) IEmailMailboxAction : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Kind(winrt::Windows::ApplicationModel::Email::EmailMailboxActionKind * value) = 0;
    virtual HRESULT __stdcall get_ChangeNumber(uint64_t * value) = 0;
};

struct __declspec(uuid("e223254c-8ab4-485b-b31f-04d15476bd59")) __declspec(novtable) IEmailMailboxAutoReply : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_Response(hstring * value) = 0;
    virtual HRESULT __stdcall put_Response(hstring value) = 0;
};

struct __declspec(uuid("a87a9fa8-0ac6-4b77-ba77-a6b99e9a27b8")) __declspec(novtable) IEmailMailboxAutoReplySettings : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_ResponseKind(winrt::Windows::ApplicationModel::Email::EmailMailboxAutoReplyMessageResponseKind * value) = 0;
    virtual HRESULT __stdcall put_ResponseKind(winrt::Windows::ApplicationModel::Email::EmailMailboxAutoReplyMessageResponseKind value) = 0;
    virtual HRESULT __stdcall get_StartTime(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall put_StartTime(Windows::Foundation::IReference<Windows::Foundation::DateTime> * value) = 0;
    virtual HRESULT __stdcall get_EndTime(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall put_EndTime(Windows::Foundation::IReference<Windows::Foundation::DateTime> * value) = 0;
    virtual HRESULT __stdcall get_InternalReply(Windows::ApplicationModel::Email::IEmailMailboxAutoReply ** value) = 0;
    virtual HRESULT __stdcall get_KnownExternalReply(Windows::ApplicationModel::Email::IEmailMailboxAutoReply ** value) = 0;
    virtual HRESULT __stdcall get_UnknownExternalReply(Windows::ApplicationModel::Email::IEmailMailboxAutoReply ** value) = 0;
};

struct __declspec(uuid("eedec3a6-89db-4305-82c4-439e0a33da11")) __declspec(novtable) IEmailMailboxCapabilities : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CanForwardMeetings(bool * value) = 0;
    virtual HRESULT __stdcall get_CanGetAndSetExternalAutoReplies(bool * value) = 0;
    virtual HRESULT __stdcall get_CanGetAndSetInternalAutoReplies(bool * value) = 0;
    virtual HRESULT __stdcall get_CanUpdateMeetingResponses(bool * value) = 0;
    virtual HRESULT __stdcall get_CanServerSearchFolders(bool * value) = 0;
    virtual HRESULT __stdcall get_CanServerSearchMailbox(bool * value) = 0;
    virtual HRESULT __stdcall get_CanProposeNewTimeForMeetings(bool * value) = 0;
    virtual HRESULT __stdcall get_CanSmartSend(bool * value) = 0;
};

struct __declspec(uuid("69723ee4-2f21-4cbc-88ab-2e7602a4806b")) __declspec(novtable) IEmailMailboxCapabilities2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CanResolveRecipients(bool * value) = 0;
    virtual HRESULT __stdcall get_CanValidateCertificates(bool * value) = 0;
    virtual HRESULT __stdcall get_CanEmptyFolder(bool * value) = 0;
    virtual HRESULT __stdcall get_CanCreateFolder(bool * value) = 0;
    virtual HRESULT __stdcall get_CanDeleteFolder(bool * value) = 0;
    virtual HRESULT __stdcall get_CanMoveFolder(bool * value) = 0;
};

struct __declspec(uuid("f690e944-56f2-45aa-872c-0ce9f3db0b5c")) __declspec(novtable) IEmailMailboxCapabilities3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_CanForwardMeetings(bool value) = 0;
    virtual HRESULT __stdcall put_CanGetAndSetExternalAutoReplies(bool value) = 0;
    virtual HRESULT __stdcall put_CanGetAndSetInternalAutoReplies(bool value) = 0;
    virtual HRESULT __stdcall put_CanUpdateMeetingResponses(bool value) = 0;
    virtual HRESULT __stdcall put_CanServerSearchFolders(bool value) = 0;
    virtual HRESULT __stdcall put_CanServerSearchMailbox(bool value) = 0;
    virtual HRESULT __stdcall put_CanProposeNewTimeForMeetings(bool value) = 0;
    virtual HRESULT __stdcall put_CanSmartSend(bool value) = 0;
    virtual HRESULT __stdcall put_CanResolveRecipients(bool value) = 0;
    virtual HRESULT __stdcall put_CanValidateCertificates(bool value) = 0;
    virtual HRESULT __stdcall put_CanEmptyFolder(bool value) = 0;
    virtual HRESULT __stdcall put_CanCreateFolder(bool value) = 0;
    virtual HRESULT __stdcall put_CanDeleteFolder(bool value) = 0;
    virtual HRESULT __stdcall put_CanMoveFolder(bool value) = 0;
};

struct __declspec(uuid("61edf54b-11ef-400c-adde-8cde65c85e66")) __declspec(novtable) IEmailMailboxChange : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ChangeType(winrt::Windows::ApplicationModel::Email::EmailMailboxChangeType * value) = 0;
    virtual HRESULT __stdcall get_MailboxActions(Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Email::EmailMailboxAction> ** value) = 0;
    virtual HRESULT __stdcall get_Message(Windows::ApplicationModel::Email::IEmailMessage ** value) = 0;
    virtual HRESULT __stdcall get_Folder(Windows::ApplicationModel::Email::IEmailFolder ** value) = 0;
};

struct __declspec(uuid("bdbd0ebb-c53d-4331-97be-be75a2146a75")) __declspec(novtable) IEmailMailboxChangeReader : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_AcceptChanges() = 0;
    virtual HRESULT __stdcall abi_AcceptChangesThrough(Windows::ApplicationModel::Email::IEmailMailboxChange * lastChangeToAcknowledge) = 0;
    virtual HRESULT __stdcall abi_ReadBatchAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMailboxChange>> ** value) = 0;
};

struct __declspec(uuid("7ae48638-5166-42b7-8882-fd21c92bdd4b")) __declspec(novtable) IEmailMailboxChangeTracker : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsTracking(bool * value) = 0;
    virtual HRESULT __stdcall abi_Enable() = 0;
    virtual HRESULT __stdcall abi_GetChangeReader(Windows::ApplicationModel::Email::IEmailMailboxChangeReader ** value) = 0;
    virtual HRESULT __stdcall abi_Reset() = 0;
};

struct __declspec(uuid("779a74c1-97c5-4b54-b30d-306232623e6d")) __declspec(novtable) IEmailMailboxChangedDeferral : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Complete() = 0;
};

struct __declspec(uuid("3cfd5f6e-01d4-4e4a-a44c-b22dd42ec207")) __declspec(novtable) IEmailMailboxChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDeferral(Windows::ApplicationModel::Email::IEmailMailboxChangedDeferral ** result) = 0;
};

struct __declspec(uuid("b228557f-2885-4998-b595-8a2d374ce950")) __declspec(novtable) IEmailMailboxCreateFolderResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Status(winrt::Windows::ApplicationModel::Email::EmailMailboxCreateFolderStatus * value) = 0;
    virtual HRESULT __stdcall get_Folder(Windows::ApplicationModel::Email::IEmailFolder ** value) = 0;
};

struct __declspec(uuid("1f3345c5-1c3b-4dc7-b410-6373783e545d")) __declspec(novtable) IEmailMailboxPolicies : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AllowedSmimeEncryptionAlgorithmNegotiation(winrt::Windows::ApplicationModel::Email::EmailMailboxAllowedSmimeEncryptionAlgorithmNegotiation * value) = 0;
    virtual HRESULT __stdcall get_AllowSmimeSoftCertificates(bool * value) = 0;
    virtual HRESULT __stdcall get_RequiredSmimeEncryptionAlgorithm(Windows::Foundation::IReference<winrt::Windows::ApplicationModel::Email::EmailMailboxSmimeEncryptionAlgorithm> ** value) = 0;
    virtual HRESULT __stdcall get_RequiredSmimeSigningAlgorithm(Windows::Foundation::IReference<winrt::Windows::ApplicationModel::Email::EmailMailboxSmimeSigningAlgorithm> ** value) = 0;
};

struct __declspec(uuid("bab58afb-a14b-497c-a8e2-55eac29cc4b5")) __declspec(novtable) IEmailMailboxPolicies2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MustEncryptSmimeMessages(bool * value) = 0;
    virtual HRESULT __stdcall get_MustSignSmimeMessages(bool * value) = 0;
};

struct __declspec(uuid("bdd4a01f-4867-414a-81a2-803919c44191")) __declspec(novtable) IEmailMailboxPolicies3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_AllowedSmimeEncryptionAlgorithmNegotiation(winrt::Windows::ApplicationModel::Email::EmailMailboxAllowedSmimeEncryptionAlgorithmNegotiation value) = 0;
    virtual HRESULT __stdcall put_AllowSmimeSoftCertificates(bool value) = 0;
    virtual HRESULT __stdcall put_RequiredSmimeEncryptionAlgorithm(Windows::Foundation::IReference<winrt::Windows::ApplicationModel::Email::EmailMailboxSmimeEncryptionAlgorithm> * value) = 0;
    virtual HRESULT __stdcall put_RequiredSmimeSigningAlgorithm(Windows::Foundation::IReference<winrt::Windows::ApplicationModel::Email::EmailMailboxSmimeSigningAlgorithm> * value) = 0;
    virtual HRESULT __stdcall put_MustEncryptSmimeMessages(bool value) = 0;
    virtual HRESULT __stdcall put_MustSignSmimeMessages(bool value) = 0;
};

struct __declspec(uuid("517ac55a-3591-4b5d-85bc-c71dde862263")) __declspec(novtable) IEmailMailboxSyncManager : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Status(winrt::Windows::ApplicationModel::Email::EmailMailboxSyncStatus * value) = 0;
    virtual HRESULT __stdcall get_LastSuccessfulSyncTime(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_LastAttemptedSyncTime(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall abi_SyncAsync(Windows::Foundation::IAsyncOperation<bool> ** result) = 0;
    virtual HRESULT __stdcall add_SyncStatusChanged(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::EmailMailboxSyncManager, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SyncStatusChanged(event_token token) = 0;
};

struct __declspec(uuid("cd8dc97e-95c1-4f89-81b7-e6aecb6695fc")) __declspec(novtable) IEmailMailboxSyncManager2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_Status(winrt::Windows::ApplicationModel::Email::EmailMailboxSyncStatus value) = 0;
    virtual HRESULT __stdcall put_LastSuccessfulSyncTime(Windows::Foundation::DateTime value) = 0;
    virtual HRESULT __stdcall put_LastAttemptedSyncTime(Windows::Foundation::DateTime value) = 0;
};

struct __declspec(uuid("f773de9f-3ca5-4b0f-90c1-156e40174ce5")) __declspec(novtable) IEmailManagerForUser : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ShowComposeNewEmailAsync(Windows::ApplicationModel::Email::IEmailMessage * message, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_RequestStoreAsync(winrt::Windows::ApplicationModel::Email::EmailStoreAccessType accessType, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailStore> ** result) = 0;
    virtual HRESULT __stdcall get_User(Windows::System::IUser ** value) = 0;
};

struct __declspec(uuid("f5128654-55c5-4890-a824-216c2618ce7f")) __declspec(novtable) IEmailManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ShowComposeNewEmailAsync(Windows::ApplicationModel::Email::IEmailMessage * message, Windows::Foundation::IAsyncAction ** asyncAction) = 0;
};

struct __declspec(uuid("ac052da3-b194-425d-b6d9-d0f04135eda2")) __declspec(novtable) IEmailManagerStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RequestStoreAsync(winrt::Windows::ApplicationModel::Email::EmailStoreAccessType accessType, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailStore> ** result) = 0;
};

struct __declspec(uuid("4a722395-843e-4945-b3aa-349e07a362c5")) __declspec(novtable) IEmailManagerStatics3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetForUser(Windows::System::IUser * user, Windows::ApplicationModel::Email::IEmailManagerForUser ** result) = 0;
};

struct __declspec(uuid("31c03fa9-7933-415f-a275-d165ba07026b")) __declspec(novtable) IEmailMeetingInfo : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AllowNewTimeProposal(bool * value) = 0;
    virtual HRESULT __stdcall put_AllowNewTimeProposal(bool value) = 0;
    virtual HRESULT __stdcall get_AppointmentRoamingId(hstring * value) = 0;
    virtual HRESULT __stdcall put_AppointmentRoamingId(hstring value) = 0;
    virtual HRESULT __stdcall get_AppointmentOriginalStartTime(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall put_AppointmentOriginalStartTime(Windows::Foundation::IReference<Windows::Foundation::DateTime> * value) = 0;
    virtual HRESULT __stdcall get_Duration(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall put_Duration(Windows::Foundation::TimeSpan value) = 0;
    virtual HRESULT __stdcall get_IsAllDay(bool * value) = 0;
    virtual HRESULT __stdcall put_IsAllDay(bool value) = 0;
    virtual HRESULT __stdcall get_IsResponseRequested(bool * value) = 0;
    virtual HRESULT __stdcall put_IsResponseRequested(bool value) = 0;
    virtual HRESULT __stdcall get_Location(hstring * value) = 0;
    virtual HRESULT __stdcall put_Location(hstring value) = 0;
    virtual HRESULT __stdcall get_ProposedStartTime(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** proposedStartTime) = 0;
    virtual HRESULT __stdcall put_ProposedStartTime(Windows::Foundation::IReference<Windows::Foundation::DateTime> * proposedStartTime) = 0;
    virtual HRESULT __stdcall get_ProposedDuration(Windows::Foundation::IReference<Windows::Foundation::TimeSpan> ** duration) = 0;
    virtual HRESULT __stdcall put_ProposedDuration(Windows::Foundation::IReference<Windows::Foundation::TimeSpan> * duration) = 0;
    virtual HRESULT __stdcall get_RecurrenceStartTime(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall put_RecurrenceStartTime(Windows::Foundation::IReference<Windows::Foundation::DateTime> * value) = 0;
    virtual HRESULT __stdcall get_Recurrence(Windows::ApplicationModel::Appointments::IAppointmentRecurrence ** value) = 0;
    virtual HRESULT __stdcall put_Recurrence(Windows::ApplicationModel::Appointments::IAppointmentRecurrence * value) = 0;
    virtual HRESULT __stdcall get_RemoteChangeNumber(uint64_t * value) = 0;
    virtual HRESULT __stdcall put_RemoteChangeNumber(uint64_t value) = 0;
    virtual HRESULT __stdcall get_StartTime(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall put_StartTime(Windows::Foundation::DateTime value) = 0;
};

struct __declspec(uuid("7e59386d-b0d9-4fe5-867c-e31ed2b588b8")) __declspec(novtable) IEmailMeetingInfo2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsReportedOutOfDateByServer(bool * value) = 0;
};

struct __declspec(uuid("6c6d948d-80b5-48f8-b0b1-e04e430f44e5")) __declspec(novtable) IEmailMessage : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Subject(hstring * value) = 0;
    virtual HRESULT __stdcall put_Subject(hstring value) = 0;
    virtual HRESULT __stdcall get_Body(hstring * value) = 0;
    virtual HRESULT __stdcall put_Body(hstring value) = 0;
    virtual HRESULT __stdcall get_To(Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Email::EmailRecipient> ** value) = 0;
    virtual HRESULT __stdcall get_CC(Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Email::EmailRecipient> ** value) = 0;
    virtual HRESULT __stdcall get_Bcc(Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Email::EmailRecipient> ** value) = 0;
    virtual HRESULT __stdcall get_Attachments(Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Email::EmailAttachment> ** value) = 0;
};

struct __declspec(uuid("fdc8248b-9f1a-44db-bd3c-65c384770f86")) __declspec(novtable) IEmailMessage2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall get_RemoteId(hstring * value) = 0;
    virtual HRESULT __stdcall put_RemoteId(hstring value) = 0;
    virtual HRESULT __stdcall get_MailboxId(hstring * value) = 0;
    virtual HRESULT __stdcall get_ConversationId(hstring * value) = 0;
    virtual HRESULT __stdcall get_FolderId(hstring * value) = 0;
    virtual HRESULT __stdcall get_AllowInternetImages(bool * value) = 0;
    virtual HRESULT __stdcall put_AllowInternetImages(bool value) = 0;
    virtual HRESULT __stdcall get_ChangeNumber(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_DownloadState(winrt::Windows::ApplicationModel::Email::EmailMessageDownloadState * value) = 0;
    virtual HRESULT __stdcall put_DownloadState(winrt::Windows::ApplicationModel::Email::EmailMessageDownloadState value) = 0;
    virtual HRESULT __stdcall get_EstimatedDownloadSizeInBytes(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_EstimatedDownloadSizeInBytes(uint32_t value) = 0;
    virtual HRESULT __stdcall get_FlagState(winrt::Windows::ApplicationModel::Email::EmailFlagState * value) = 0;
    virtual HRESULT __stdcall put_FlagState(winrt::Windows::ApplicationModel::Email::EmailFlagState value) = 0;
    virtual HRESULT __stdcall get_HasPartialBodies(bool * value) = 0;
    virtual HRESULT __stdcall get_Importance(winrt::Windows::ApplicationModel::Email::EmailImportance * value) = 0;
    virtual HRESULT __stdcall put_Importance(winrt::Windows::ApplicationModel::Email::EmailImportance value) = 0;
    virtual HRESULT __stdcall get_InResponseToMessageId(hstring * value) = 0;
    virtual HRESULT __stdcall get_IrmInfo(Windows::ApplicationModel::Email::IEmailIrmInfo ** value) = 0;
    virtual HRESULT __stdcall put_IrmInfo(Windows::ApplicationModel::Email::IEmailIrmInfo * value) = 0;
    virtual HRESULT __stdcall get_IsDraftMessage(bool * value) = 0;
    virtual HRESULT __stdcall get_IsRead(bool * value) = 0;
    virtual HRESULT __stdcall put_IsRead(bool value) = 0;
    virtual HRESULT __stdcall get_IsSeen(bool * value) = 0;
    virtual HRESULT __stdcall put_IsSeen(bool value) = 0;
    virtual HRESULT __stdcall get_IsServerSearchMessage(bool * value) = 0;
    virtual HRESULT __stdcall get_IsSmartSendable(bool * value) = 0;
    virtual HRESULT __stdcall get_MessageClass(hstring * value) = 0;
    virtual HRESULT __stdcall put_MessageClass(hstring value) = 0;
    virtual HRESULT __stdcall get_NormalizedSubject(hstring * value) = 0;
    virtual HRESULT __stdcall get_OriginalCodePage(int32_t * value) = 0;
    virtual HRESULT __stdcall put_OriginalCodePage(int32_t value) = 0;
    virtual HRESULT __stdcall get_Preview(hstring * value) = 0;
    virtual HRESULT __stdcall put_Preview(hstring value) = 0;
    virtual HRESULT __stdcall get_LastResponseKind(winrt::Windows::ApplicationModel::Email::EmailMessageResponseKind * value) = 0;
    virtual HRESULT __stdcall put_LastResponseKind(winrt::Windows::ApplicationModel::Email::EmailMessageResponseKind value) = 0;
    virtual HRESULT __stdcall get_Sender(Windows::ApplicationModel::Email::IEmailRecipient ** value) = 0;
    virtual HRESULT __stdcall put_Sender(Windows::ApplicationModel::Email::IEmailRecipient * value) = 0;
    virtual HRESULT __stdcall get_SentTime(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall put_SentTime(Windows::Foundation::IReference<Windows::Foundation::DateTime> * value) = 0;
    virtual HRESULT __stdcall get_MeetingInfo(Windows::ApplicationModel::Email::IEmailMeetingInfo ** value) = 0;
    virtual HRESULT __stdcall put_MeetingInfo(Windows::ApplicationModel::Email::IEmailMeetingInfo * value) = 0;
    virtual HRESULT __stdcall abi_GetBodyStream(winrt::Windows::ApplicationModel::Email::EmailMessageBodyKind type, Windows::Storage::Streams::IRandomAccessStreamReference ** result) = 0;
    virtual HRESULT __stdcall abi_SetBodyStream(winrt::Windows::ApplicationModel::Email::EmailMessageBodyKind type, Windows::Storage::Streams::IRandomAccessStreamReference * stream) = 0;
};

struct __declspec(uuid("a1ea675c-e598-4d29-a018-fc7b7eece0a1")) __declspec(novtable) IEmailMessage3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SmimeData(Windows::Storage::Streams::IRandomAccessStreamReference ** value) = 0;
    virtual HRESULT __stdcall put_SmimeData(Windows::Storage::Streams::IRandomAccessStreamReference * value) = 0;
    virtual HRESULT __stdcall get_SmimeKind(winrt::Windows::ApplicationModel::Email::EmailMessageSmimeKind * value) = 0;
    virtual HRESULT __stdcall put_SmimeKind(winrt::Windows::ApplicationModel::Email::EmailMessageSmimeKind value) = 0;
};

struct __declspec(uuid("605cd08f-25d9-4f1b-9e51-0514c0149653")) __declspec(novtable) IEmailMessageBatch : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Messages(Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMessage> ** value) = 0;
    virtual HRESULT __stdcall get_Status(winrt::Windows::ApplicationModel::Email::EmailBatchStatus * value) = 0;
};

struct __declspec(uuid("2f4abe9f-6213-4a85-a3b0-f92d1a839d19")) __declspec(novtable) IEmailMessageReader : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ReadBatchAsync(Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMessageBatch> ** result) = 0;
};

struct __declspec(uuid("45504b9b-3e7f-4d52-b6dd-d6fd4e1fbd9a")) __declspec(novtable) IEmailQueryOptions : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TextSearch(Windows::ApplicationModel::Email::IEmailQueryTextSearch ** value) = 0;
    virtual HRESULT __stdcall get_SortDirection(winrt::Windows::ApplicationModel::Email::EmailQuerySortDirection * value) = 0;
    virtual HRESULT __stdcall put_SortDirection(winrt::Windows::ApplicationModel::Email::EmailQuerySortDirection value) = 0;
    virtual HRESULT __stdcall get_SortProperty(winrt::Windows::ApplicationModel::Email::EmailQuerySortProperty * value) = 0;
    virtual HRESULT __stdcall put_SortProperty(winrt::Windows::ApplicationModel::Email::EmailQuerySortProperty value) = 0;
    virtual HRESULT __stdcall get_Kind(winrt::Windows::ApplicationModel::Email::EmailQueryKind * value) = 0;
    virtual HRESULT __stdcall put_Kind(winrt::Windows::ApplicationModel::Email::EmailQueryKind value) = 0;
    virtual HRESULT __stdcall get_FolderIds(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
};

struct __declspec(uuid("88f1a1b8-78ab-4ee8-b4e3-046d6e2fe5e2")) __declspec(novtable) IEmailQueryOptionsFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateWithText(hstring text, Windows::ApplicationModel::Email::IEmailQueryOptions ** result) = 0;
    virtual HRESULT __stdcall abi_CreateWithTextAndFields(hstring text, winrt::Windows::ApplicationModel::Email::EmailQuerySearchFields fields, Windows::ApplicationModel::Email::IEmailQueryOptions ** result) = 0;
};

struct __declspec(uuid("9fa0a288-3c5d-46a5-a6e2-31d6fd17e540")) __declspec(novtable) IEmailQueryTextSearch : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Fields(winrt::Windows::ApplicationModel::Email::EmailQuerySearchFields * value) = 0;
    virtual HRESULT __stdcall put_Fields(winrt::Windows::ApplicationModel::Email::EmailQuerySearchFields value) = 0;
    virtual HRESULT __stdcall get_SearchScope(winrt::Windows::ApplicationModel::Email::EmailQuerySearchScope * value) = 0;
    virtual HRESULT __stdcall put_SearchScope(winrt::Windows::ApplicationModel::Email::EmailQuerySearchScope value) = 0;
    virtual HRESULT __stdcall get_Text(hstring * value) = 0;
    virtual HRESULT __stdcall put_Text(hstring value) = 0;
};

struct __declspec(uuid("cae825b3-4478-4814-b900-c902b5e19b53")) __declspec(novtable) IEmailRecipient : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall put_Name(hstring value) = 0;
    virtual HRESULT __stdcall get_Address(hstring * value) = 0;
    virtual HRESULT __stdcall put_Address(hstring value) = 0;
};

struct __declspec(uuid("5500b84d-c79a-4ef8-b909-722e18e3935d")) __declspec(novtable) IEmailRecipientFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(hstring address, Windows::ApplicationModel::Email::IEmailRecipient ** result) = 0;
    virtual HRESULT __stdcall abi_CreateWithName(hstring address, hstring name, Windows::ApplicationModel::Email::IEmailRecipient ** result) = 0;
};

struct __declspec(uuid("918338fa-8d8d-4573-80d1-07172a34b98d")) __declspec(novtable) IEmailRecipientResolutionResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Status(winrt::Windows::ApplicationModel::Email::EmailRecipientResolutionStatus * value) = 0;
    virtual HRESULT __stdcall get_PublicKeys(Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> ** value) = 0;
};

struct __declspec(uuid("5e420bb6-ce5b-4bde-b9d4-e16da0b09fca")) __declspec(novtable) IEmailRecipientResolutionResult2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_Status(winrt::Windows::ApplicationModel::Email::EmailRecipientResolutionStatus value) = 0;
    virtual HRESULT __stdcall abi_SetPublicKeys(Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate> * value) = 0;
};

struct __declspec(uuid("f803226e-9137-4f8b-a470-279ac3058eb6")) __declspec(novtable) IEmailStore : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FindMailboxesAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMailbox>> ** result) = 0;
    virtual HRESULT __stdcall abi_GetConversationReader(Windows::ApplicationModel::Email::IEmailConversationReader ** result) = 0;
    virtual HRESULT __stdcall abi_GetConversationReaderWithOptions(Windows::ApplicationModel::Email::IEmailQueryOptions * options, Windows::ApplicationModel::Email::IEmailConversationReader ** result) = 0;
    virtual HRESULT __stdcall abi_GetMessageReader(Windows::ApplicationModel::Email::IEmailMessageReader ** result) = 0;
    virtual HRESULT __stdcall abi_GetMessageReaderWithOptions(Windows::ApplicationModel::Email::IEmailQueryOptions * options, Windows::ApplicationModel::Email::IEmailMessageReader ** result) = 0;
    virtual HRESULT __stdcall abi_GetMailboxAsync(hstring id, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMailbox> ** result) = 0;
    virtual HRESULT __stdcall abi_GetConversationAsync(hstring id, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailConversation> ** result) = 0;
    virtual HRESULT __stdcall abi_GetFolderAsync(hstring id, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailFolder> ** result) = 0;
    virtual HRESULT __stdcall abi_GetMessageAsync(hstring id, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMessage> ** result) = 0;
    virtual HRESULT __stdcall abi_CreateMailboxAsync(hstring accountName, hstring accountAddress, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMailbox> ** result) = 0;
    virtual HRESULT __stdcall abi_CreateMailboxInAccountAsync(hstring accountName, hstring accountAddress, hstring userDataAccountId, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMailbox> ** result) = 0;
};

struct __declspec(uuid("ce17563c-46e6-43c9-96f7-facf7dd710cb")) __declspec(novtable) IEmailStoreNotificationTriggerDetails : Windows::Foundation::IInspectable
{
};

}

namespace ABI {

template <> struct traits<Windows::ApplicationModel::Email::EmailAttachment> { using default_interface = Windows::ApplicationModel::Email::IEmailAttachment; };
template <> struct traits<Windows::ApplicationModel::Email::EmailConversation> { using default_interface = Windows::ApplicationModel::Email::IEmailConversation; };
template <> struct traits<Windows::ApplicationModel::Email::EmailConversationBatch> { using default_interface = Windows::ApplicationModel::Email::IEmailConversationBatch; };
template <> struct traits<Windows::ApplicationModel::Email::EmailConversationReader> { using default_interface = Windows::ApplicationModel::Email::IEmailConversationReader; };
template <> struct traits<Windows::ApplicationModel::Email::EmailFolder> { using default_interface = Windows::ApplicationModel::Email::IEmailFolder; };
template <> struct traits<Windows::ApplicationModel::Email::EmailIrmInfo> { using default_interface = Windows::ApplicationModel::Email::IEmailIrmInfo; };
template <> struct traits<Windows::ApplicationModel::Email::EmailIrmTemplate> { using default_interface = Windows::ApplicationModel::Email::IEmailIrmTemplate; };
template <> struct traits<Windows::ApplicationModel::Email::EmailItemCounts> { using default_interface = Windows::ApplicationModel::Email::IEmailItemCounts; };
template <> struct traits<Windows::ApplicationModel::Email::EmailMailbox> { using default_interface = Windows::ApplicationModel::Email::IEmailMailbox; };
template <> struct traits<Windows::ApplicationModel::Email::EmailMailboxAction> { using default_interface = Windows::ApplicationModel::Email::IEmailMailboxAction; };
template <> struct traits<Windows::ApplicationModel::Email::EmailMailboxAutoReply> { using default_interface = Windows::ApplicationModel::Email::IEmailMailboxAutoReply; };
template <> struct traits<Windows::ApplicationModel::Email::EmailMailboxAutoReplySettings> { using default_interface = Windows::ApplicationModel::Email::IEmailMailboxAutoReplySettings; };
template <> struct traits<Windows::ApplicationModel::Email::EmailMailboxCapabilities> { using default_interface = Windows::ApplicationModel::Email::IEmailMailboxCapabilities; };
template <> struct traits<Windows::ApplicationModel::Email::EmailMailboxChange> { using default_interface = Windows::ApplicationModel::Email::IEmailMailboxChange; };
template <> struct traits<Windows::ApplicationModel::Email::EmailMailboxChangeReader> { using default_interface = Windows::ApplicationModel::Email::IEmailMailboxChangeReader; };
template <> struct traits<Windows::ApplicationModel::Email::EmailMailboxChangeTracker> { using default_interface = Windows::ApplicationModel::Email::IEmailMailboxChangeTracker; };
template <> struct traits<Windows::ApplicationModel::Email::EmailMailboxChangedDeferral> { using default_interface = Windows::ApplicationModel::Email::IEmailMailboxChangedDeferral; };
template <> struct traits<Windows::ApplicationModel::Email::EmailMailboxChangedEventArgs> { using default_interface = Windows::ApplicationModel::Email::IEmailMailboxChangedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Email::EmailMailboxCreateFolderResult> { using default_interface = Windows::ApplicationModel::Email::IEmailMailboxCreateFolderResult; };
template <> struct traits<Windows::ApplicationModel::Email::EmailMailboxPolicies> { using default_interface = Windows::ApplicationModel::Email::IEmailMailboxPolicies; };
template <> struct traits<Windows::ApplicationModel::Email::EmailMailboxSyncManager> { using default_interface = Windows::ApplicationModel::Email::IEmailMailboxSyncManager; };
template <> struct traits<Windows::ApplicationModel::Email::EmailManagerForUser> { using default_interface = Windows::ApplicationModel::Email::IEmailManagerForUser; };
template <> struct traits<Windows::ApplicationModel::Email::EmailMeetingInfo> { using default_interface = Windows::ApplicationModel::Email::IEmailMeetingInfo; };
template <> struct traits<Windows::ApplicationModel::Email::EmailMessage> { using default_interface = Windows::ApplicationModel::Email::IEmailMessage; };
template <> struct traits<Windows::ApplicationModel::Email::EmailMessageBatch> { using default_interface = Windows::ApplicationModel::Email::IEmailMessageBatch; };
template <> struct traits<Windows::ApplicationModel::Email::EmailMessageReader> { using default_interface = Windows::ApplicationModel::Email::IEmailMessageReader; };
template <> struct traits<Windows::ApplicationModel::Email::EmailQueryOptions> { using default_interface = Windows::ApplicationModel::Email::IEmailQueryOptions; };
template <> struct traits<Windows::ApplicationModel::Email::EmailQueryTextSearch> { using default_interface = Windows::ApplicationModel::Email::IEmailQueryTextSearch; };
template <> struct traits<Windows::ApplicationModel::Email::EmailRecipient> { using default_interface = Windows::ApplicationModel::Email::IEmailRecipient; };
template <> struct traits<Windows::ApplicationModel::Email::EmailRecipientResolutionResult> { using default_interface = Windows::ApplicationModel::Email::IEmailRecipientResolutionResult; };
template <> struct traits<Windows::ApplicationModel::Email::EmailStore> { using default_interface = Windows::ApplicationModel::Email::IEmailStore; };
template <> struct traits<Windows::ApplicationModel::Email::EmailStoreNotificationTriggerDetails> { using default_interface = Windows::ApplicationModel::Email::IEmailStoreNotificationTriggerDetails; };

}

namespace Windows::ApplicationModel::Email {

template <typename D>
struct WINRT_EBO impl_IEmailAttachment
{
    hstring FileName() const;
    void FileName(hstring_view value) const;
    Windows::Storage::Streams::IRandomAccessStreamReference Data() const;
    void Data(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const;
};

template <typename D>
struct WINRT_EBO impl_IEmailAttachment2
{
    hstring Id() const;
    hstring ContentId() const;
    void ContentId(hstring_view value) const;
    hstring ContentLocation() const;
    void ContentLocation(hstring_view value) const;
    Windows::ApplicationModel::Email::EmailAttachmentDownloadState DownloadState() const;
    void DownloadState(Windows::ApplicationModel::Email::EmailAttachmentDownloadState value) const;
    uint64_t EstimatedDownloadSizeInBytes() const;
    void EstimatedDownloadSizeInBytes(uint64_t value) const;
    bool IsFromBaseMessage() const;
    bool IsInline() const;
    void IsInline(bool value) const;
    hstring MimeType() const;
    void MimeType(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IEmailAttachmentFactory
{
    Windows::ApplicationModel::Email::EmailAttachment Create(hstring_view fileName, const Windows::Storage::Streams::IRandomAccessStreamReference & data) const;
};

template <typename D>
struct WINRT_EBO impl_IEmailAttachmentFactory2
{
    Windows::ApplicationModel::Email::EmailAttachment Create(hstring_view fileName, const Windows::Storage::Streams::IRandomAccessStreamReference & data, hstring_view mimeType) const;
};

template <typename D>
struct WINRT_EBO impl_IEmailConversation
{
    hstring Id() const;
    hstring MailboxId() const;
    Windows::ApplicationModel::Email::EmailFlagState FlagState() const;
    bool HasAttachment() const;
    Windows::ApplicationModel::Email::EmailImportance Importance() const;
    Windows::ApplicationModel::Email::EmailMessageResponseKind LastEmailResponseKind() const;
    uint32_t MessageCount() const;
    hstring MostRecentMessageId() const;
    Windows::Foundation::DateTime MostRecentMessageTime() const;
    hstring Preview() const;
    Windows::ApplicationModel::Email::EmailRecipient LatestSender() const;
    hstring Subject() const;
    uint32_t UnreadMessageCount() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMessage>> FindMessagesAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMessage>> FindMessagesAsync(uint32_t count) const;
};

template <typename D>
struct WINRT_EBO impl_IEmailConversationBatch
{
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailConversation> Conversations() const;
    Windows::ApplicationModel::Email::EmailBatchStatus Status() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailConversationReader
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailConversationBatch> ReadBatchAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailFolder
{
    hstring Id() const;
    hstring RemoteId() const;
    void RemoteId(hstring_view value) const;
    hstring MailboxId() const;
    hstring ParentFolderId() const;
    hstring DisplayName() const;
    void DisplayName(hstring_view value) const;
    bool IsSyncEnabled() const;
    void IsSyncEnabled(bool value) const;
    Windows::Foundation::DateTime LastSuccessfulSyncTime() const;
    void LastSuccessfulSyncTime(const Windows::Foundation::DateTime & value) const;
    Windows::ApplicationModel::Email::EmailSpecialFolderKind Kind() const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailFolder> CreateFolderAsync(hstring_view name) const;
    Windows::Foundation::IAsyncAction DeleteAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailFolder>> FindChildFoldersAsync() const;
    Windows::ApplicationModel::Email::EmailConversationReader GetConversationReader() const;
    Windows::ApplicationModel::Email::EmailConversationReader GetConversationReader(const Windows::ApplicationModel::Email::EmailQueryOptions & options) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMessage> GetMessageAsync(hstring_view id) const;
    Windows::ApplicationModel::Email::EmailMessageReader GetMessageReader() const;
    Windows::ApplicationModel::Email::EmailMessageReader GetMessageReader(const Windows::ApplicationModel::Email::EmailQueryOptions & options) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailItemCounts> GetMessageCountsAsync() const;
    Windows::Foundation::IAsyncOperation<bool> TryMoveAsync(const Windows::ApplicationModel::Email::EmailFolder & newParentFolder) const;
    Windows::Foundation::IAsyncOperation<bool> TryMoveAsync(const Windows::ApplicationModel::Email::EmailFolder & newParentFolder, hstring_view newFolderName) const;
    Windows::Foundation::IAsyncOperation<bool> TrySaveAsync() const;
    Windows::Foundation::IAsyncAction SaveMessageAsync(const Windows::ApplicationModel::Email::EmailMessage & message) const;
};

template <typename D>
struct WINRT_EBO impl_IEmailIrmInfo
{
    bool CanEdit() const;
    void CanEdit(bool value) const;
    bool CanExtractData() const;
    void CanExtractData(bool value) const;
    bool CanForward() const;
    void CanForward(bool value) const;
    bool CanModifyRecipientsOnResponse() const;
    void CanModifyRecipientsOnResponse(bool value) const;
    bool CanPrintData() const;
    void CanPrintData(bool value) const;
    bool CanRemoveIrmOnResponse() const;
    void CanRemoveIrmOnResponse(bool value) const;
    bool CanReply() const;
    void CanReply(bool value) const;
    bool CanReplyAll() const;
    void CanReplyAll(bool value) const;
    Windows::Foundation::DateTime ExpirationDate() const;
    void ExpirationDate(const Windows::Foundation::DateTime & value) const;
    bool IsIrmOriginator() const;
    void IsIrmOriginator(bool value) const;
    bool IsProgramaticAccessAllowed() const;
    void IsProgramaticAccessAllowed(bool value) const;
    Windows::ApplicationModel::Email::EmailIrmTemplate Template() const;
    void Template(const Windows::ApplicationModel::Email::EmailIrmTemplate & value) const;
};

template <typename D>
struct WINRT_EBO impl_IEmailIrmInfoFactory
{
    Windows::ApplicationModel::Email::EmailIrmInfo Create(const Windows::Foundation::DateTime & expiration, const Windows::ApplicationModel::Email::EmailIrmTemplate & irmTemplate) const;
};

template <typename D>
struct WINRT_EBO impl_IEmailIrmTemplate
{
    hstring Id() const;
    void Id(hstring_view value) const;
    hstring Description() const;
    void Description(hstring_view value) const;
    hstring Name() const;
    void Name(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IEmailIrmTemplateFactory
{
    Windows::ApplicationModel::Email::EmailIrmTemplate Create(hstring_view id, hstring_view name, hstring_view description) const;
};

template <typename D>
struct WINRT_EBO impl_IEmailItemCounts
{
    uint32_t Flagged() const;
    uint32_t Important() const;
    uint32_t Total() const;
    uint32_t Unread() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailbox
{
    Windows::ApplicationModel::Email::EmailMailboxCapabilities Capabilities() const;
    Windows::ApplicationModel::Email::EmailMailboxChangeTracker ChangeTracker() const;
    hstring DisplayName() const;
    void DisplayName(hstring_view value) const;
    hstring Id() const;
    bool IsOwnedByCurrentApp() const;
    bool IsDataEncryptedUnderLock() const;
    hstring MailAddress() const;
    void MailAddress(hstring_view value) const;
    Windows::Foundation::Collections::IVector<hstring> MailAddressAliases() const;
    Windows::ApplicationModel::Email::EmailMailboxOtherAppReadAccess OtherAppReadAccess() const;
    void OtherAppReadAccess(Windows::ApplicationModel::Email::EmailMailboxOtherAppReadAccess value) const;
    Windows::ApplicationModel::Email::EmailMailboxOtherAppWriteAccess OtherAppWriteAccess() const;
    void OtherAppWriteAccess(Windows::ApplicationModel::Email::EmailMailboxOtherAppWriteAccess value) const;
    Windows::ApplicationModel::Email::EmailMailboxPolicies Policies() const;
    hstring SourceDisplayName() const;
    Windows::ApplicationModel::Email::EmailMailboxSyncManager SyncManager() const;
    hstring UserDataAccountId() const;
    Windows::ApplicationModel::Email::EmailConversationReader GetConversationReader() const;
    Windows::ApplicationModel::Email::EmailConversationReader GetConversationReader(const Windows::ApplicationModel::Email::EmailQueryOptions & options) const;
    Windows::ApplicationModel::Email::EmailMessageReader GetMessageReader() const;
    Windows::ApplicationModel::Email::EmailMessageReader GetMessageReader(const Windows::ApplicationModel::Email::EmailQueryOptions & options) const;
    Windows::Foundation::IAsyncAction DeleteAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailConversation> GetConversationAsync(hstring_view id) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailFolder> GetFolderAsync(hstring_view id) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMessage> GetMessageAsync(hstring_view id) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailFolder> GetSpecialFolderAsync(Windows::ApplicationModel::Email::EmailSpecialFolderKind folderType) const;
    Windows::Foundation::IAsyncAction SaveAsync() const;
    Windows::Foundation::IAsyncAction MarkMessageAsSeenAsync(hstring_view messageId) const;
    Windows::Foundation::IAsyncAction MarkFolderAsSeenAsync(hstring_view folderId) const;
    Windows::Foundation::IAsyncAction MarkMessageReadAsync(hstring_view messageId, bool isRead) const;
    Windows::Foundation::IAsyncAction ChangeMessageFlagStateAsync(hstring_view messageId, Windows::ApplicationModel::Email::EmailFlagState flagState) const;
    Windows::Foundation::IAsyncOperation<bool> TryMoveMessageAsync(hstring_view messageId, hstring_view newParentFolderId) const;
    Windows::Foundation::IAsyncOperation<bool> TryMoveFolderAsync(hstring_view folderId, hstring_view newParentFolderId) const;
    Windows::Foundation::IAsyncOperation<bool> TryMoveFolderAsync(hstring_view folderId, hstring_view newParentFolderId, hstring_view newFolderName) const;
    Windows::Foundation::IAsyncAction DeleteMessageAsync(hstring_view messageId) const;
    Windows::Foundation::IAsyncAction MarkFolderSyncEnabledAsync(hstring_view folderId, bool isSyncEnabled) const;
    Windows::Foundation::IAsyncAction SendMessageAsync(const Windows::ApplicationModel::Email::EmailMessage & message) const;
    Windows::Foundation::IAsyncAction SaveDraftAsync(const Windows::ApplicationModel::Email::EmailMessage & message) const;
    Windows::Foundation::IAsyncAction DownloadMessageAsync(hstring_view messageId) const;
    Windows::Foundation::IAsyncAction DownloadAttachmentAsync(hstring_view attachmentId) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMessage> CreateResponseMessageAsync(hstring_view messageId, Windows::ApplicationModel::Email::EmailMessageResponseKind responseType, hstring_view subject, Windows::ApplicationModel::Email::EmailMessageBodyKind responseHeaderType, hstring_view responseHeader) const;
    Windows::Foundation::IAsyncOperation<bool> TryUpdateMeetingResponseAsync(const Windows::ApplicationModel::Email::EmailMessage & meeting, Windows::ApplicationModel::Email::EmailMeetingResponseType response, hstring_view subject, hstring_view comment, bool sendUpdate) const;
    Windows::Foundation::IAsyncOperation<bool> TryForwardMeetingAsync(const Windows::ApplicationModel::Email::EmailMessage & meeting, iterable<Windows::ApplicationModel::Email::EmailRecipient> recipients, hstring_view subject, Windows::ApplicationModel::Email::EmailMessageBodyKind forwardHeaderType, hstring_view forwardHeader, hstring_view comment) const;
    Windows::Foundation::IAsyncOperation<bool> TryProposeNewTimeForMeetingAsync(const Windows::ApplicationModel::Email::EmailMessage & meeting, const Windows::Foundation::DateTime & newStartTime, const Windows::Foundation::TimeSpan & newDuration, hstring_view subject, hstring_view comment) const;
    event_token MailboxChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::EmailMailbox, Windows::ApplicationModel::Email::EmailMailboxChangedEventArgs> & pHandler) const;
    using MailboxChanged_revoker = event_revoker<IEmailMailbox>;
    MailboxChanged_revoker MailboxChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::EmailMailbox, Windows::ApplicationModel::Email::EmailMailboxChangedEventArgs> & pHandler) const;
    void MailboxChanged(event_token token) const;
    Windows::Foundation::IAsyncAction SendMessageAsync(const Windows::ApplicationModel::Email::EmailMessage & message, bool smartSend) const;
    Windows::Foundation::IAsyncOperation<bool> TrySetAutoReplySettingsAsync(const Windows::ApplicationModel::Email::EmailMailboxAutoReplySettings & autoReplySettings) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMailboxAutoReplySettings> TryGetAutoReplySettingsAsync(Windows::ApplicationModel::Email::EmailMailboxAutoReplyMessageResponseKind requestedFormat) const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailbox2
{
    hstring LinkedMailboxId() const;
    hstring NetworkAccountId() const;
    hstring NetworkId() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailbox3
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailRecipientResolutionResult>> ResolveRecipientsAsync(iterable<hstring> recipients) const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<winrt::Windows::ApplicationModel::Email::EmailCertificateValidationStatus>> ValidateCertificatesAsync(iterable<Windows::Security::Cryptography::Certificates::Certificate> certificates) const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Email::EmailMailboxEmptyFolderStatus> TryEmptyFolderAsync(hstring_view folderId) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMailboxCreateFolderResult> TryCreateFolderAsync(hstring_view parentFolderId, hstring_view name) const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Email::EmailMailboxDeleteFolderStatus> TryDeleteFolderAsync(hstring_view folderId) const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailbox4
{
    Windows::Foundation::IAsyncAction RegisterSyncManagerAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxAction
{
    Windows::ApplicationModel::Email::EmailMailboxActionKind Kind() const;
    uint64_t ChangeNumber() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxAutoReply
{
    bool IsEnabled() const;
    void IsEnabled(bool value) const;
    hstring Response() const;
    void Response(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxAutoReplySettings
{
    bool IsEnabled() const;
    void IsEnabled(bool value) const;
    Windows::ApplicationModel::Email::EmailMailboxAutoReplyMessageResponseKind ResponseKind() const;
    void ResponseKind(Windows::ApplicationModel::Email::EmailMailboxAutoReplyMessageResponseKind value) const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> StartTime() const;
    void StartTime(const optional<Windows::Foundation::DateTime> & value) const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> EndTime() const;
    void EndTime(const optional<Windows::Foundation::DateTime> & value) const;
    Windows::ApplicationModel::Email::EmailMailboxAutoReply InternalReply() const;
    Windows::ApplicationModel::Email::EmailMailboxAutoReply KnownExternalReply() const;
    Windows::ApplicationModel::Email::EmailMailboxAutoReply UnknownExternalReply() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxCapabilities
{
    bool CanForwardMeetings() const;
    bool CanGetAndSetExternalAutoReplies() const;
    bool CanGetAndSetInternalAutoReplies() const;
    bool CanUpdateMeetingResponses() const;
    bool CanServerSearchFolders() const;
    bool CanServerSearchMailbox() const;
    bool CanProposeNewTimeForMeetings() const;
    bool CanSmartSend() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxCapabilities2
{
    bool CanResolveRecipients() const;
    bool CanValidateCertificates() const;
    bool CanEmptyFolder() const;
    bool CanCreateFolder() const;
    bool CanDeleteFolder() const;
    bool CanMoveFolder() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxCapabilities3
{
    void CanForwardMeetings(bool value) const;
    void CanGetAndSetExternalAutoReplies(bool value) const;
    void CanGetAndSetInternalAutoReplies(bool value) const;
    void CanUpdateMeetingResponses(bool value) const;
    void CanServerSearchFolders(bool value) const;
    void CanServerSearchMailbox(bool value) const;
    void CanProposeNewTimeForMeetings(bool value) const;
    void CanSmartSend(bool value) const;
    void CanResolveRecipients(bool value) const;
    void CanValidateCertificates(bool value) const;
    void CanEmptyFolder(bool value) const;
    void CanCreateFolder(bool value) const;
    void CanDeleteFolder(bool value) const;
    void CanMoveFolder(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxChange
{
    Windows::ApplicationModel::Email::EmailMailboxChangeType ChangeType() const;
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Email::EmailMailboxAction> MailboxActions() const;
    Windows::ApplicationModel::Email::EmailMessage Message() const;
    Windows::ApplicationModel::Email::EmailFolder Folder() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxChangeReader
{
    void AcceptChanges() const;
    void AcceptChangesThrough(const Windows::ApplicationModel::Email::EmailMailboxChange & lastChangeToAcknowledge) const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMailboxChange>> ReadBatchAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxChangeTracker
{
    bool IsTracking() const;
    void Enable() const;
    Windows::ApplicationModel::Email::EmailMailboxChangeReader GetChangeReader() const;
    void Reset() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxChangedDeferral
{
    void Complete() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxChangedEventArgs
{
    Windows::ApplicationModel::Email::EmailMailboxChangedDeferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxCreateFolderResult
{
    Windows::ApplicationModel::Email::EmailMailboxCreateFolderStatus Status() const;
    Windows::ApplicationModel::Email::EmailFolder Folder() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxPolicies
{
    Windows::ApplicationModel::Email::EmailMailboxAllowedSmimeEncryptionAlgorithmNegotiation AllowedSmimeEncryptionAlgorithmNegotiation() const;
    bool AllowSmimeSoftCertificates() const;
    Windows::Foundation::IReference<winrt::Windows::ApplicationModel::Email::EmailMailboxSmimeEncryptionAlgorithm> RequiredSmimeEncryptionAlgorithm() const;
    Windows::Foundation::IReference<winrt::Windows::ApplicationModel::Email::EmailMailboxSmimeSigningAlgorithm> RequiredSmimeSigningAlgorithm() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxPolicies2
{
    bool MustEncryptSmimeMessages() const;
    bool MustSignSmimeMessages() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxPolicies3
{
    void AllowedSmimeEncryptionAlgorithmNegotiation(Windows::ApplicationModel::Email::EmailMailboxAllowedSmimeEncryptionAlgorithmNegotiation value) const;
    void AllowSmimeSoftCertificates(bool value) const;
    void RequiredSmimeEncryptionAlgorithm(const optional<winrt::Windows::ApplicationModel::Email::EmailMailboxSmimeEncryptionAlgorithm> & value) const;
    void RequiredSmimeSigningAlgorithm(const optional<winrt::Windows::ApplicationModel::Email::EmailMailboxSmimeSigningAlgorithm> & value) const;
    void MustEncryptSmimeMessages(bool value) const;
    void MustSignSmimeMessages(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxSyncManager
{
    Windows::ApplicationModel::Email::EmailMailboxSyncStatus Status() const;
    Windows::Foundation::DateTime LastSuccessfulSyncTime() const;
    Windows::Foundation::DateTime LastAttemptedSyncTime() const;
    Windows::Foundation::IAsyncOperation<bool> SyncAsync() const;
    event_token SyncStatusChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::EmailMailboxSyncManager, Windows::Foundation::IInspectable> & handler) const;
    using SyncStatusChanged_revoker = event_revoker<IEmailMailboxSyncManager>;
    SyncStatusChanged_revoker SyncStatusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::EmailMailboxSyncManager, Windows::Foundation::IInspectable> & handler) const;
    void SyncStatusChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxSyncManager2
{
    void Status(Windows::ApplicationModel::Email::EmailMailboxSyncStatus value) const;
    void LastSuccessfulSyncTime(const Windows::Foundation::DateTime & value) const;
    void LastAttemptedSyncTime(const Windows::Foundation::DateTime & value) const;
};

template <typename D>
struct WINRT_EBO impl_IEmailManagerForUser
{
    Windows::Foundation::IAsyncAction ShowComposeNewEmailAsync(const Windows::ApplicationModel::Email::EmailMessage & message) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailStore> RequestStoreAsync(Windows::ApplicationModel::Email::EmailStoreAccessType accessType) const;
    Windows::System::User User() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailManagerStatics
{
    Windows::Foundation::IAsyncAction ShowComposeNewEmailAsync(const Windows::ApplicationModel::Email::EmailMessage & message) const;
};

template <typename D>
struct WINRT_EBO impl_IEmailManagerStatics2
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailStore> RequestStoreAsync(Windows::ApplicationModel::Email::EmailStoreAccessType accessType) const;
};

template <typename D>
struct WINRT_EBO impl_IEmailManagerStatics3
{
    Windows::ApplicationModel::Email::EmailManagerForUser GetForUser(const Windows::System::User & user) const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMeetingInfo
{
    bool AllowNewTimeProposal() const;
    void AllowNewTimeProposal(bool value) const;
    hstring AppointmentRoamingId() const;
    void AppointmentRoamingId(hstring_view value) const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> AppointmentOriginalStartTime() const;
    void AppointmentOriginalStartTime(const optional<Windows::Foundation::DateTime> & value) const;
    Windows::Foundation::TimeSpan Duration() const;
    void Duration(const Windows::Foundation::TimeSpan & value) const;
    bool IsAllDay() const;
    void IsAllDay(bool value) const;
    bool IsResponseRequested() const;
    void IsResponseRequested(bool value) const;
    hstring Location() const;
    void Location(hstring_view value) const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> ProposedStartTime() const;
    void ProposedStartTime(const optional<Windows::Foundation::DateTime> & proposedStartTime) const;
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> ProposedDuration() const;
    void ProposedDuration(const optional<Windows::Foundation::TimeSpan> & duration) const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> RecurrenceStartTime() const;
    void RecurrenceStartTime(const optional<Windows::Foundation::DateTime> & value) const;
    Windows::ApplicationModel::Appointments::AppointmentRecurrence Recurrence() const;
    void Recurrence(const Windows::ApplicationModel::Appointments::AppointmentRecurrence & value) const;
    uint64_t RemoteChangeNumber() const;
    void RemoteChangeNumber(uint64_t value) const;
    Windows::Foundation::DateTime StartTime() const;
    void StartTime(const Windows::Foundation::DateTime & value) const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMeetingInfo2
{
    bool IsReportedOutOfDateByServer() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMessage
{
    hstring Subject() const;
    void Subject(hstring_view value) const;
    hstring Body() const;
    void Body(hstring_view value) const;
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Email::EmailRecipient> To() const;
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Email::EmailRecipient> CC() const;
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Email::EmailRecipient> Bcc() const;
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Email::EmailAttachment> Attachments() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMessage2
{
    hstring Id() const;
    hstring RemoteId() const;
    void RemoteId(hstring_view value) const;
    hstring MailboxId() const;
    hstring ConversationId() const;
    hstring FolderId() const;
    bool AllowInternetImages() const;
    void AllowInternetImages(bool value) const;
    uint64_t ChangeNumber() const;
    Windows::ApplicationModel::Email::EmailMessageDownloadState DownloadState() const;
    void DownloadState(Windows::ApplicationModel::Email::EmailMessageDownloadState value) const;
    uint32_t EstimatedDownloadSizeInBytes() const;
    void EstimatedDownloadSizeInBytes(uint32_t value) const;
    Windows::ApplicationModel::Email::EmailFlagState FlagState() const;
    void FlagState(Windows::ApplicationModel::Email::EmailFlagState value) const;
    bool HasPartialBodies() const;
    Windows::ApplicationModel::Email::EmailImportance Importance() const;
    void Importance(Windows::ApplicationModel::Email::EmailImportance value) const;
    hstring InResponseToMessageId() const;
    Windows::ApplicationModel::Email::EmailIrmInfo IrmInfo() const;
    void IrmInfo(const Windows::ApplicationModel::Email::EmailIrmInfo & value) const;
    bool IsDraftMessage() const;
    bool IsRead() const;
    void IsRead(bool value) const;
    bool IsSeen() const;
    void IsSeen(bool value) const;
    bool IsServerSearchMessage() const;
    bool IsSmartSendable() const;
    hstring MessageClass() const;
    void MessageClass(hstring_view value) const;
    hstring NormalizedSubject() const;
    int32_t OriginalCodePage() const;
    void OriginalCodePage(int32_t value) const;
    hstring Preview() const;
    void Preview(hstring_view value) const;
    Windows::ApplicationModel::Email::EmailMessageResponseKind LastResponseKind() const;
    void LastResponseKind(Windows::ApplicationModel::Email::EmailMessageResponseKind value) const;
    Windows::ApplicationModel::Email::EmailRecipient Sender() const;
    void Sender(const Windows::ApplicationModel::Email::EmailRecipient & value) const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> SentTime() const;
    void SentTime(const optional<Windows::Foundation::DateTime> & value) const;
    Windows::ApplicationModel::Email::EmailMeetingInfo MeetingInfo() const;
    void MeetingInfo(const Windows::ApplicationModel::Email::EmailMeetingInfo & value) const;
    Windows::Storage::Streams::IRandomAccessStreamReference GetBodyStream(Windows::ApplicationModel::Email::EmailMessageBodyKind type) const;
    void SetBodyStream(Windows::ApplicationModel::Email::EmailMessageBodyKind type, const Windows::Storage::Streams::IRandomAccessStreamReference & stream) const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMessage3
{
    Windows::Storage::Streams::IRandomAccessStreamReference SmimeData() const;
    void SmimeData(const Windows::Storage::Streams::IRandomAccessStreamReference & value) const;
    Windows::ApplicationModel::Email::EmailMessageSmimeKind SmimeKind() const;
    void SmimeKind(Windows::ApplicationModel::Email::EmailMessageSmimeKind value) const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMessageBatch
{
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMessage> Messages() const;
    Windows::ApplicationModel::Email::EmailBatchStatus Status() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMessageReader
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMessageBatch> ReadBatchAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailQueryOptions
{
    Windows::ApplicationModel::Email::EmailQueryTextSearch TextSearch() const;
    Windows::ApplicationModel::Email::EmailQuerySortDirection SortDirection() const;
    void SortDirection(Windows::ApplicationModel::Email::EmailQuerySortDirection value) const;
    Windows::ApplicationModel::Email::EmailQuerySortProperty SortProperty() const;
    void SortProperty(Windows::ApplicationModel::Email::EmailQuerySortProperty value) const;
    Windows::ApplicationModel::Email::EmailQueryKind Kind() const;
    void Kind(Windows::ApplicationModel::Email::EmailQueryKind value) const;
    Windows::Foundation::Collections::IVector<hstring> FolderIds() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailQueryOptionsFactory
{
    Windows::ApplicationModel::Email::EmailQueryOptions CreateWithText(hstring_view text) const;
    Windows::ApplicationModel::Email::EmailQueryOptions CreateWithTextAndFields(hstring_view text, Windows::ApplicationModel::Email::EmailQuerySearchFields fields) const;
};

template <typename D>
struct WINRT_EBO impl_IEmailQueryTextSearch
{
    Windows::ApplicationModel::Email::EmailQuerySearchFields Fields() const;
    void Fields(Windows::ApplicationModel::Email::EmailQuerySearchFields value) const;
    Windows::ApplicationModel::Email::EmailQuerySearchScope SearchScope() const;
    void SearchScope(Windows::ApplicationModel::Email::EmailQuerySearchScope value) const;
    hstring Text() const;
    void Text(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IEmailRecipient
{
    hstring Name() const;
    void Name(hstring_view value) const;
    hstring Address() const;
    void Address(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IEmailRecipientFactory
{
    Windows::ApplicationModel::Email::EmailRecipient Create(hstring_view address) const;
    Windows::ApplicationModel::Email::EmailRecipient CreateWithName(hstring_view address, hstring_view name) const;
};

template <typename D>
struct WINRT_EBO impl_IEmailRecipientResolutionResult
{
    Windows::ApplicationModel::Email::EmailRecipientResolutionStatus Status() const;
    Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> PublicKeys() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailRecipientResolutionResult2
{
    void Status(Windows::ApplicationModel::Email::EmailRecipientResolutionStatus value) const;
    void SetPublicKeys(iterable<Windows::Security::Cryptography::Certificates::Certificate> value) const;
};

template <typename D>
struct WINRT_EBO impl_IEmailStore
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMailbox>> FindMailboxesAsync() const;
    Windows::ApplicationModel::Email::EmailConversationReader GetConversationReader() const;
    Windows::ApplicationModel::Email::EmailConversationReader GetConversationReader(const Windows::ApplicationModel::Email::EmailQueryOptions & options) const;
    Windows::ApplicationModel::Email::EmailMessageReader GetMessageReader() const;
    Windows::ApplicationModel::Email::EmailMessageReader GetMessageReader(const Windows::ApplicationModel::Email::EmailQueryOptions & options) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMailbox> GetMailboxAsync(hstring_view id) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailConversation> GetConversationAsync(hstring_view id) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailFolder> GetFolderAsync(hstring_view id) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMessage> GetMessageAsync(hstring_view id) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMailbox> CreateMailboxAsync(hstring_view accountName, hstring_view accountAddress) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailMailbox> CreateMailboxAsync(hstring_view accountName, hstring_view accountAddress, hstring_view userDataAccountId) const;
};

template <typename D>
struct WINRT_EBO impl_IEmailStoreNotificationTriggerDetails
{
};

}

namespace impl {

template <> struct traits<Windows::ApplicationModel::Email::IEmailAttachment>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailAttachment;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailAttachment<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailAttachment2>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailAttachment2;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailAttachment2<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailAttachmentFactory>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailAttachmentFactory;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailAttachmentFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailAttachmentFactory2>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailAttachmentFactory2;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailAttachmentFactory2<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailConversation>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailConversation;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailConversation<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailConversationBatch>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailConversationBatch;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailConversationBatch<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailConversationReader>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailConversationReader;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailConversationReader<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailFolder>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailFolder;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailFolder<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailIrmInfo>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailIrmInfo;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailIrmInfo<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailIrmInfoFactory>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailIrmInfoFactory;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailIrmInfoFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailIrmTemplate>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailIrmTemplate;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailIrmTemplate<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailIrmTemplateFactory>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailIrmTemplateFactory;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailIrmTemplateFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailItemCounts>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailItemCounts;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailItemCounts<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailMailbox>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailMailbox;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailMailbox<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailMailbox2>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailMailbox2;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailMailbox2<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailMailbox3>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailMailbox3;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailMailbox3<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailMailbox4>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailMailbox4;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailMailbox4<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailMailboxAction>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailMailboxAction;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailMailboxAction<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailMailboxAutoReply>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailMailboxAutoReply;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailMailboxAutoReply<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailMailboxAutoReplySettings>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailMailboxAutoReplySettings;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailMailboxAutoReplySettings<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailMailboxCapabilities>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailMailboxCapabilities;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailMailboxCapabilities<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailMailboxCapabilities2>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailMailboxCapabilities2;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailMailboxCapabilities2<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailMailboxCapabilities3>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailMailboxCapabilities3;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailMailboxCapabilities3<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailMailboxChange>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailMailboxChange;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailMailboxChange<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailMailboxChangeReader>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailMailboxChangeReader;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailMailboxChangeReader<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailMailboxChangeTracker>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailMailboxChangeTracker;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailMailboxChangeTracker<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailMailboxChangedDeferral>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailMailboxChangedDeferral;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailMailboxChangedDeferral<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailMailboxChangedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailMailboxChangedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailMailboxChangedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailMailboxCreateFolderResult>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailMailboxCreateFolderResult;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailMailboxCreateFolderResult<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailMailboxPolicies>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailMailboxPolicies;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailMailboxPolicies<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailMailboxPolicies2>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailMailboxPolicies2;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailMailboxPolicies2<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailMailboxPolicies3>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailMailboxPolicies3;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailMailboxPolicies3<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailMailboxSyncManager>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailMailboxSyncManager;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailMailboxSyncManager<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailMailboxSyncManager2>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailMailboxSyncManager2;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailMailboxSyncManager2<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailManagerForUser>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailManagerForUser;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailManagerForUser<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailManagerStatics>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailManagerStatics;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailManagerStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailManagerStatics2>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailManagerStatics2;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailManagerStatics2<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailManagerStatics3>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailManagerStatics3;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailManagerStatics3<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailMeetingInfo>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailMeetingInfo;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailMeetingInfo<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailMeetingInfo2>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailMeetingInfo2;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailMeetingInfo2<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailMessage>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailMessage;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailMessage<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailMessage2>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailMessage2;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailMessage2<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailMessage3>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailMessage3;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailMessage3<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailMessageBatch>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailMessageBatch;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailMessageBatch<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailMessageReader>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailMessageReader;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailMessageReader<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailQueryOptions>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailQueryOptions;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailQueryOptions<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailQueryOptionsFactory>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailQueryOptionsFactory;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailQueryOptionsFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailQueryTextSearch>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailQueryTextSearch;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailQueryTextSearch<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailRecipient>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailRecipient;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailRecipient<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailRecipientFactory>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailRecipientFactory;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailRecipientFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailRecipientResolutionResult>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailRecipientResolutionResult;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailRecipientResolutionResult<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailRecipientResolutionResult2>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailRecipientResolutionResult2;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailRecipientResolutionResult2<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailStore>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailStore;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailStore<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::IEmailStoreNotificationTriggerDetails>
{
    using abi = ABI::Windows::ApplicationModel::Email::IEmailStoreNotificationTriggerDetails;
    template <typename D> using consume = Windows::ApplicationModel::Email::impl_IEmailStoreNotificationTriggerDetails<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::EmailAttachment>
{
    using abi = ABI::Windows::ApplicationModel::Email::EmailAttachment;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.EmailAttachment"; }
};

template <> struct traits<Windows::ApplicationModel::Email::EmailConversation>
{
    using abi = ABI::Windows::ApplicationModel::Email::EmailConversation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.EmailConversation"; }
};

template <> struct traits<Windows::ApplicationModel::Email::EmailConversationBatch>
{
    using abi = ABI::Windows::ApplicationModel::Email::EmailConversationBatch;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.EmailConversationBatch"; }
};

template <> struct traits<Windows::ApplicationModel::Email::EmailConversationReader>
{
    using abi = ABI::Windows::ApplicationModel::Email::EmailConversationReader;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.EmailConversationReader"; }
};

template <> struct traits<Windows::ApplicationModel::Email::EmailFolder>
{
    using abi = ABI::Windows::ApplicationModel::Email::EmailFolder;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.EmailFolder"; }
};

template <> struct traits<Windows::ApplicationModel::Email::EmailIrmInfo>
{
    using abi = ABI::Windows::ApplicationModel::Email::EmailIrmInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.EmailIrmInfo"; }
};

template <> struct traits<Windows::ApplicationModel::Email::EmailIrmTemplate>
{
    using abi = ABI::Windows::ApplicationModel::Email::EmailIrmTemplate;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.EmailIrmTemplate"; }
};

template <> struct traits<Windows::ApplicationModel::Email::EmailItemCounts>
{
    using abi = ABI::Windows::ApplicationModel::Email::EmailItemCounts;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.EmailItemCounts"; }
};

template <> struct traits<Windows::ApplicationModel::Email::EmailMailbox>
{
    using abi = ABI::Windows::ApplicationModel::Email::EmailMailbox;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.EmailMailbox"; }
};

template <> struct traits<Windows::ApplicationModel::Email::EmailMailboxAction>
{
    using abi = ABI::Windows::ApplicationModel::Email::EmailMailboxAction;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.EmailMailboxAction"; }
};

template <> struct traits<Windows::ApplicationModel::Email::EmailMailboxAutoReply>
{
    using abi = ABI::Windows::ApplicationModel::Email::EmailMailboxAutoReply;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.EmailMailboxAutoReply"; }
};

template <> struct traits<Windows::ApplicationModel::Email::EmailMailboxAutoReplySettings>
{
    using abi = ABI::Windows::ApplicationModel::Email::EmailMailboxAutoReplySettings;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.EmailMailboxAutoReplySettings"; }
};

template <> struct traits<Windows::ApplicationModel::Email::EmailMailboxCapabilities>
{
    using abi = ABI::Windows::ApplicationModel::Email::EmailMailboxCapabilities;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.EmailMailboxCapabilities"; }
};

template <> struct traits<Windows::ApplicationModel::Email::EmailMailboxChange>
{
    using abi = ABI::Windows::ApplicationModel::Email::EmailMailboxChange;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.EmailMailboxChange"; }
};

template <> struct traits<Windows::ApplicationModel::Email::EmailMailboxChangeReader>
{
    using abi = ABI::Windows::ApplicationModel::Email::EmailMailboxChangeReader;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.EmailMailboxChangeReader"; }
};

template <> struct traits<Windows::ApplicationModel::Email::EmailMailboxChangeTracker>
{
    using abi = ABI::Windows::ApplicationModel::Email::EmailMailboxChangeTracker;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.EmailMailboxChangeTracker"; }
};

template <> struct traits<Windows::ApplicationModel::Email::EmailMailboxChangedDeferral>
{
    using abi = ABI::Windows::ApplicationModel::Email::EmailMailboxChangedDeferral;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.EmailMailboxChangedDeferral"; }
};

template <> struct traits<Windows::ApplicationModel::Email::EmailMailboxChangedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Email::EmailMailboxChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.EmailMailboxChangedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Email::EmailMailboxCreateFolderResult>
{
    using abi = ABI::Windows::ApplicationModel::Email::EmailMailboxCreateFolderResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.EmailMailboxCreateFolderResult"; }
};

template <> struct traits<Windows::ApplicationModel::Email::EmailMailboxPolicies>
{
    using abi = ABI::Windows::ApplicationModel::Email::EmailMailboxPolicies;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.EmailMailboxPolicies"; }
};

template <> struct traits<Windows::ApplicationModel::Email::EmailMailboxSyncManager>
{
    using abi = ABI::Windows::ApplicationModel::Email::EmailMailboxSyncManager;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.EmailMailboxSyncManager"; }
};

template <> struct traits<Windows::ApplicationModel::Email::EmailManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.EmailManager"; }
};

template <> struct traits<Windows::ApplicationModel::Email::EmailManagerForUser>
{
    using abi = ABI::Windows::ApplicationModel::Email::EmailManagerForUser;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.EmailManagerForUser"; }
};

template <> struct traits<Windows::ApplicationModel::Email::EmailMeetingInfo>
{
    using abi = ABI::Windows::ApplicationModel::Email::EmailMeetingInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.EmailMeetingInfo"; }
};

template <> struct traits<Windows::ApplicationModel::Email::EmailMessage>
{
    using abi = ABI::Windows::ApplicationModel::Email::EmailMessage;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.EmailMessage"; }
};

template <> struct traits<Windows::ApplicationModel::Email::EmailMessageBatch>
{
    using abi = ABI::Windows::ApplicationModel::Email::EmailMessageBatch;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.EmailMessageBatch"; }
};

template <> struct traits<Windows::ApplicationModel::Email::EmailMessageReader>
{
    using abi = ABI::Windows::ApplicationModel::Email::EmailMessageReader;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.EmailMessageReader"; }
};

template <> struct traits<Windows::ApplicationModel::Email::EmailQueryOptions>
{
    using abi = ABI::Windows::ApplicationModel::Email::EmailQueryOptions;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.EmailQueryOptions"; }
};

template <> struct traits<Windows::ApplicationModel::Email::EmailQueryTextSearch>
{
    using abi = ABI::Windows::ApplicationModel::Email::EmailQueryTextSearch;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.EmailQueryTextSearch"; }
};

template <> struct traits<Windows::ApplicationModel::Email::EmailRecipient>
{
    using abi = ABI::Windows::ApplicationModel::Email::EmailRecipient;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.EmailRecipient"; }
};

template <> struct traits<Windows::ApplicationModel::Email::EmailRecipientResolutionResult>
{
    using abi = ABI::Windows::ApplicationModel::Email::EmailRecipientResolutionResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.EmailRecipientResolutionResult"; }
};

template <> struct traits<Windows::ApplicationModel::Email::EmailStore>
{
    using abi = ABI::Windows::ApplicationModel::Email::EmailStore;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.EmailStore"; }
};

template <> struct traits<Windows::ApplicationModel::Email::EmailStoreNotificationTriggerDetails>
{
    using abi = ABI::Windows::ApplicationModel::Email::EmailStoreNotificationTriggerDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.EmailStoreNotificationTriggerDetails"; }
};

}

}
