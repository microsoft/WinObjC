// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.ApplicationModel.Email.DataProvider.0.h"
#include "Windows.ApplicationModel.Email.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.ApplicationModel.Email.1.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Security.Cryptography.Certificates.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::Email::DataProvider {

struct __declspec(uuid("3b9c9dc7-37b2-4bf0-ae30-7b644a1c96e1")) __declspec(novtable) IEmailDataProviderConnection : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_MailboxSyncRequested(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxSyncManagerSyncRequestEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_MailboxSyncRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_DownloadMessageRequested(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadMessageRequestEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DownloadMessageRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_DownloadAttachmentRequested(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadAttachmentRequestEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DownloadAttachmentRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_CreateFolderRequested(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxCreateFolderRequestEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_CreateFolderRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_DeleteFolderRequested(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxDeleteFolderRequestEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DeleteFolderRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_EmptyFolderRequested(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxEmptyFolderRequestEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_EmptyFolderRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_MoveFolderRequested(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxMoveFolderRequestEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_MoveFolderRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_UpdateMeetingResponseRequested(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxUpdateMeetingResponseRequestEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_UpdateMeetingResponseRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_ForwardMeetingRequested(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxForwardMeetingRequestEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ForwardMeetingRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_ProposeNewTimeForMeetingRequested(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxProposeNewTimeForMeetingRequestEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ProposeNewTimeForMeetingRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_SetAutoReplySettingsRequested(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxSetAutoReplySettingsRequestEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SetAutoReplySettingsRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_GetAutoReplySettingsRequested(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxGetAutoReplySettingsRequestEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_GetAutoReplySettingsRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_ResolveRecipientsRequested(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxResolveRecipientsRequestEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ResolveRecipientsRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_ValidateCertificatesRequested(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxValidateCertificatesRequestEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ValidateCertificatesRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_ServerSearchReadBatchRequested(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxServerSearchReadBatchRequestEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ServerSearchReadBatchRequested(event_token token) = 0;
    virtual HRESULT __stdcall abi_Start() = 0;
};

struct __declspec(uuid("8f3e4e50-341e-45f3-bba0-84a005e1319a")) __declspec(novtable) IEmailDataProviderTriggerDetails : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Connection(Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection ** value) = 0;
};

struct __declspec(uuid("184d3775-c921-4c39-a309-e16c9f22b04b")) __declspec(novtable) IEmailMailboxCreateFolderRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EmailMailboxId(hstring * value) = 0;
    virtual HRESULT __stdcall get_ParentFolderId(hstring * value) = 0;
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall abi_ReportCompletedAsync(Windows::ApplicationModel::Email::IEmailFolder * folder, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_ReportFailedAsync(winrt::Windows::ApplicationModel::Email::EmailMailboxCreateFolderStatus status, Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("03e4c02c-241c-4ea9-a68f-ff20bc5afc85")) __declspec(novtable) IEmailMailboxCreateFolderRequestEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Request(Windows::ApplicationModel::Email::DataProvider::IEmailMailboxCreateFolderRequest ** value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("9469e88a-a931-4779-923d-09a3ea292e29")) __declspec(novtable) IEmailMailboxDeleteFolderRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EmailMailboxId(hstring * value) = 0;
    virtual HRESULT __stdcall get_EmailFolderId(hstring * value) = 0;
    virtual HRESULT __stdcall abi_ReportCompletedAsync(Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_ReportFailedAsync(winrt::Windows::ApplicationModel::Email::EmailMailboxDeleteFolderStatus status, Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("b4d32d06-2332-4678-8378-28b579336846")) __declspec(novtable) IEmailMailboxDeleteFolderRequestEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Request(Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDeleteFolderRequest ** value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("0b1dbbb4-750c-48e1-bce4-8d589684ffbc")) __declspec(novtable) IEmailMailboxDownloadAttachmentRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EmailMailboxId(hstring * value) = 0;
    virtual HRESULT __stdcall get_EmailMessageId(hstring * value) = 0;
    virtual HRESULT __stdcall get_EmailAttachmentId(hstring * value) = 0;
    virtual HRESULT __stdcall abi_ReportCompletedAsync(Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_ReportFailedAsync(Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("ccddc46d-ffa8-4877-9f9d-fed7bcaf4104")) __declspec(novtable) IEmailMailboxDownloadAttachmentRequestEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Request(Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadAttachmentRequest ** value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("497b4187-5b4d-4b23-816c-f3842beb753e")) __declspec(novtable) IEmailMailboxDownloadMessageRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EmailMailboxId(hstring * value) = 0;
    virtual HRESULT __stdcall get_EmailMessageId(hstring * value) = 0;
    virtual HRESULT __stdcall abi_ReportCompletedAsync(Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_ReportFailedAsync(Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("470409ad-d0a0-4a5b-bb2a-37621039c53e")) __declspec(novtable) IEmailMailboxDownloadMessageRequestEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Request(Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadMessageRequest ** value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("fe4b03ab-f86d-46d9-b4ce-bc8a6d9e9268")) __declspec(novtable) IEmailMailboxEmptyFolderRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EmailMailboxId(hstring * value) = 0;
    virtual HRESULT __stdcall get_EmailFolderId(hstring * value) = 0;
    virtual HRESULT __stdcall abi_ReportCompletedAsync(Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_ReportFailedAsync(winrt::Windows::ApplicationModel::Email::EmailMailboxEmptyFolderStatus status, Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("7183f484-985a-4ac0-b33f-ee0e2627a3c0")) __declspec(novtable) IEmailMailboxEmptyFolderRequestEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Request(Windows::ApplicationModel::Email::DataProvider::IEmailMailboxEmptyFolderRequest ** value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("616d6af1-70d4-4832-b869-b80542ae9be8")) __declspec(novtable) IEmailMailboxForwardMeetingRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EmailMailboxId(hstring * value) = 0;
    virtual HRESULT __stdcall get_EmailMessageId(hstring * value) = 0;
    virtual HRESULT __stdcall get_Recipients(Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailRecipient> ** value) = 0;
    virtual HRESULT __stdcall get_Subject(hstring * value) = 0;
    virtual HRESULT __stdcall get_ForwardHeaderType(winrt::Windows::ApplicationModel::Email::EmailMessageBodyKind * value) = 0;
    virtual HRESULT __stdcall get_ForwardHeader(hstring * value) = 0;
    virtual HRESULT __stdcall get_Comment(hstring * value) = 0;
    virtual HRESULT __stdcall abi_ReportCompletedAsync(Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_ReportFailedAsync(Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("2bd8f33a-2974-4759-a5a5-58f44d3c0275")) __declspec(novtable) IEmailMailboxForwardMeetingRequestEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Request(Windows::ApplicationModel::Email::DataProvider::IEmailMailboxForwardMeetingRequest ** value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("9b380789-1e88-4e01-84cc-1386ad9a2c2f")) __declspec(novtable) IEmailMailboxGetAutoReplySettingsRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EmailMailboxId(hstring * value) = 0;
    virtual HRESULT __stdcall get_RequestedFormat(winrt::Windows::ApplicationModel::Email::EmailMailboxAutoReplyMessageResponseKind * value) = 0;
    virtual HRESULT __stdcall abi_ReportCompletedAsync(Windows::ApplicationModel::Email::IEmailMailboxAutoReplySettings * autoReplySettings, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_ReportFailedAsync(Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("d79f55c2-fd45-4004-8a91-9bacf38b7022")) __declspec(novtable) IEmailMailboxGetAutoReplySettingsRequestEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Request(Windows::ApplicationModel::Email::DataProvider::IEmailMailboxGetAutoReplySettingsRequest ** value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("10ba2856-4a95-4068-91cc-67cc7acf454f")) __declspec(novtable) IEmailMailboxMoveFolderRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EmailMailboxId(hstring * value) = 0;
    virtual HRESULT __stdcall get_EmailFolderId(hstring * value) = 0;
    virtual HRESULT __stdcall get_NewParentFolderId(hstring * value) = 0;
    virtual HRESULT __stdcall get_NewFolderName(hstring * value) = 0;
    virtual HRESULT __stdcall abi_ReportCompletedAsync(Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_ReportFailedAsync(Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("38623020-14ba-4c88-8698-7239e3c8aaa7")) __declspec(novtable) IEmailMailboxMoveFolderRequestEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Request(Windows::ApplicationModel::Email::DataProvider::IEmailMailboxMoveFolderRequest ** value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("5aeff152-9799-4f9f-a399-ff07f3eef04e")) __declspec(novtable) IEmailMailboxProposeNewTimeForMeetingRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EmailMailboxId(hstring * value) = 0;
    virtual HRESULT __stdcall get_EmailMessageId(hstring * value) = 0;
    virtual HRESULT __stdcall get_NewStartTime(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_NewDuration(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_Subject(hstring * value) = 0;
    virtual HRESULT __stdcall get_Comment(hstring * value) = 0;
    virtual HRESULT __stdcall abi_ReportCompletedAsync(Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_ReportFailedAsync(Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("fb480b98-33ad-4a67-8251-0f9c249b6a20")) __declspec(novtable) IEmailMailboxProposeNewTimeForMeetingRequestEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Request(Windows::ApplicationModel::Email::DataProvider::IEmailMailboxProposeNewTimeForMeetingRequest ** value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("efa4cf70-7b39-4c9b-811e-41eaf43a332d")) __declspec(novtable) IEmailMailboxResolveRecipientsRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EmailMailboxId(hstring * value) = 0;
    virtual HRESULT __stdcall get_Recipients(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
    virtual HRESULT __stdcall abi_ReportCompletedAsync(Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Email::EmailRecipientResolutionResult> * resolutionResults, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_ReportFailedAsync(Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("260f9e02-b2cf-40f8-8c28-e3ed43b1e89a")) __declspec(novtable) IEmailMailboxResolveRecipientsRequestEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Request(Windows::ApplicationModel::Email::DataProvider::IEmailMailboxResolveRecipientsRequest ** value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("090eebdf-5a96-41d3-8ad8-34912f9aa60e")) __declspec(novtable) IEmailMailboxServerSearchReadBatchRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SessionId(hstring * value) = 0;
    virtual HRESULT __stdcall get_EmailMailboxId(hstring * value) = 0;
    virtual HRESULT __stdcall get_EmailFolderId(hstring * value) = 0;
    virtual HRESULT __stdcall get_Options(Windows::ApplicationModel::Email::IEmailQueryOptions ** value) = 0;
    virtual HRESULT __stdcall get_SuggestedBatchSize(uint32_t * value) = 0;
    virtual HRESULT __stdcall abi_SaveMessageAsync(Windows::ApplicationModel::Email::IEmailMessage * message, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_ReportCompletedAsync(Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_ReportFailedAsync(winrt::Windows::ApplicationModel::Email::EmailBatchStatus batchStatus, Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("14101b4e-ed9e-45d1-ad7a-cc9b7f643ae2")) __declspec(novtable) IEmailMailboxServerSearchReadBatchRequestEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Request(Windows::ApplicationModel::Email::DataProvider::IEmailMailboxServerSearchReadBatchRequest ** value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("75a422d0-a88e-4e54-8dc7-c243186b774e")) __declspec(novtable) IEmailMailboxSetAutoReplySettingsRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EmailMailboxId(hstring * value) = 0;
    virtual HRESULT __stdcall get_AutoReplySettings(Windows::ApplicationModel::Email::IEmailMailboxAutoReplySettings ** value) = 0;
    virtual HRESULT __stdcall abi_ReportCompletedAsync(Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_ReportFailedAsync(Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("09da11ad-d7ca-4087-ac86-53fa67f76246")) __declspec(novtable) IEmailMailboxSetAutoReplySettingsRequestEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Request(Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSetAutoReplySettingsRequest ** value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("4e10e8e4-7e67-405a-b673-dc60c91090fc")) __declspec(novtable) IEmailMailboxSyncManagerSyncRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EmailMailboxId(hstring * value) = 0;
    virtual HRESULT __stdcall abi_ReportCompletedAsync(Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_ReportFailedAsync(Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("439a031a-8fcc-4ae5-b9b5-d434e0a65aa8")) __declspec(novtable) IEmailMailboxSyncManagerSyncRequestEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Request(Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSyncManagerSyncRequest ** value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("5b99ac93-b2cf-4888-ba4f-306b6b66df30")) __declspec(novtable) IEmailMailboxUpdateMeetingResponseRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EmailMailboxId(hstring * value) = 0;
    virtual HRESULT __stdcall get_EmailMessageId(hstring * value) = 0;
    virtual HRESULT __stdcall get_Response(winrt::Windows::ApplicationModel::Email::EmailMeetingResponseType * response) = 0;
    virtual HRESULT __stdcall get_Subject(hstring * value) = 0;
    virtual HRESULT __stdcall get_Comment(hstring * value) = 0;
    virtual HRESULT __stdcall get_SendUpdate(bool * value) = 0;
    virtual HRESULT __stdcall abi_ReportCompletedAsync(Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_ReportFailedAsync(Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("6898d761-56c9-4f17-be31-66fda94ba159")) __declspec(novtable) IEmailMailboxUpdateMeetingResponseRequestEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Request(Windows::ApplicationModel::Email::DataProvider::IEmailMailboxUpdateMeetingResponseRequest ** value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

struct __declspec(uuid("a94d3931-e11a-4f97-b81a-187a70a8f41a")) __declspec(novtable) IEmailMailboxValidateCertificatesRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EmailMailboxId(hstring * value) = 0;
    virtual HRESULT __stdcall get_Certificates(Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> ** value) = 0;
    virtual HRESULT __stdcall abi_ReportCompletedAsync(Windows::Foundation::Collections::IIterable<winrt::Windows::ApplicationModel::Email::EmailCertificateValidationStatus> * validationStatuses, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_ReportFailedAsync(Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("2583bf17-02ff-49fe-a73c-03f37566c691")) __declspec(novtable) IEmailMailboxValidateCertificatesRequestEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Request(Windows::ApplicationModel::Email::DataProvider::IEmailMailboxValidateCertificatesRequest ** value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection> { using default_interface = Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection; };
template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderTriggerDetails> { using default_interface = Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderTriggerDetails; };
template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxCreateFolderRequest> { using default_interface = Windows::ApplicationModel::Email::DataProvider::IEmailMailboxCreateFolderRequest; };
template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxCreateFolderRequestEventArgs> { using default_interface = Windows::ApplicationModel::Email::DataProvider::IEmailMailboxCreateFolderRequestEventArgs; };
template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxDeleteFolderRequest> { using default_interface = Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDeleteFolderRequest; };
template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxDeleteFolderRequestEventArgs> { using default_interface = Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDeleteFolderRequestEventArgs; };
template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadAttachmentRequest> { using default_interface = Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadAttachmentRequest; };
template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadAttachmentRequestEventArgs> { using default_interface = Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadAttachmentRequestEventArgs; };
template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadMessageRequest> { using default_interface = Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadMessageRequest; };
template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadMessageRequestEventArgs> { using default_interface = Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadMessageRequestEventArgs; };
template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxEmptyFolderRequest> { using default_interface = Windows::ApplicationModel::Email::DataProvider::IEmailMailboxEmptyFolderRequest; };
template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxEmptyFolderRequestEventArgs> { using default_interface = Windows::ApplicationModel::Email::DataProvider::IEmailMailboxEmptyFolderRequestEventArgs; };
template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxForwardMeetingRequest> { using default_interface = Windows::ApplicationModel::Email::DataProvider::IEmailMailboxForwardMeetingRequest; };
template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxForwardMeetingRequestEventArgs> { using default_interface = Windows::ApplicationModel::Email::DataProvider::IEmailMailboxForwardMeetingRequestEventArgs; };
template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxGetAutoReplySettingsRequest> { using default_interface = Windows::ApplicationModel::Email::DataProvider::IEmailMailboxGetAutoReplySettingsRequest; };
template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxGetAutoReplySettingsRequestEventArgs> { using default_interface = Windows::ApplicationModel::Email::DataProvider::IEmailMailboxGetAutoReplySettingsRequestEventArgs; };
template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxMoveFolderRequest> { using default_interface = Windows::ApplicationModel::Email::DataProvider::IEmailMailboxMoveFolderRequest; };
template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxMoveFolderRequestEventArgs> { using default_interface = Windows::ApplicationModel::Email::DataProvider::IEmailMailboxMoveFolderRequestEventArgs; };
template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxProposeNewTimeForMeetingRequest> { using default_interface = Windows::ApplicationModel::Email::DataProvider::IEmailMailboxProposeNewTimeForMeetingRequest; };
template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxProposeNewTimeForMeetingRequestEventArgs> { using default_interface = Windows::ApplicationModel::Email::DataProvider::IEmailMailboxProposeNewTimeForMeetingRequestEventArgs; };
template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxResolveRecipientsRequest> { using default_interface = Windows::ApplicationModel::Email::DataProvider::IEmailMailboxResolveRecipientsRequest; };
template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxResolveRecipientsRequestEventArgs> { using default_interface = Windows::ApplicationModel::Email::DataProvider::IEmailMailboxResolveRecipientsRequestEventArgs; };
template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxServerSearchReadBatchRequest> { using default_interface = Windows::ApplicationModel::Email::DataProvider::IEmailMailboxServerSearchReadBatchRequest; };
template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxServerSearchReadBatchRequestEventArgs> { using default_interface = Windows::ApplicationModel::Email::DataProvider::IEmailMailboxServerSearchReadBatchRequestEventArgs; };
template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxSetAutoReplySettingsRequest> { using default_interface = Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSetAutoReplySettingsRequest; };
template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxSetAutoReplySettingsRequestEventArgs> { using default_interface = Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSetAutoReplySettingsRequestEventArgs; };
template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxSyncManagerSyncRequest> { using default_interface = Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSyncManagerSyncRequest; };
template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxSyncManagerSyncRequestEventArgs> { using default_interface = Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSyncManagerSyncRequestEventArgs; };
template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxUpdateMeetingResponseRequest> { using default_interface = Windows::ApplicationModel::Email::DataProvider::IEmailMailboxUpdateMeetingResponseRequest; };
template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxUpdateMeetingResponseRequestEventArgs> { using default_interface = Windows::ApplicationModel::Email::DataProvider::IEmailMailboxUpdateMeetingResponseRequestEventArgs; };
template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxValidateCertificatesRequest> { using default_interface = Windows::ApplicationModel::Email::DataProvider::IEmailMailboxValidateCertificatesRequest; };
template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxValidateCertificatesRequestEventArgs> { using default_interface = Windows::ApplicationModel::Email::DataProvider::IEmailMailboxValidateCertificatesRequestEventArgs; };

}

namespace Windows::ApplicationModel::Email::DataProvider {

template <typename D>
struct WINRT_EBO impl_IEmailDataProviderConnection
{
    event_token MailboxSyncRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxSyncManagerSyncRequestEventArgs> & handler) const;
    using MailboxSyncRequested_revoker = event_revoker<IEmailDataProviderConnection>;
    MailboxSyncRequested_revoker MailboxSyncRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxSyncManagerSyncRequestEventArgs> & handler) const;
    void MailboxSyncRequested(event_token token) const;
    event_token DownloadMessageRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadMessageRequestEventArgs> & handler) const;
    using DownloadMessageRequested_revoker = event_revoker<IEmailDataProviderConnection>;
    DownloadMessageRequested_revoker DownloadMessageRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadMessageRequestEventArgs> & handler) const;
    void DownloadMessageRequested(event_token token) const;
    event_token DownloadAttachmentRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadAttachmentRequestEventArgs> & handler) const;
    using DownloadAttachmentRequested_revoker = event_revoker<IEmailDataProviderConnection>;
    DownloadAttachmentRequested_revoker DownloadAttachmentRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadAttachmentRequestEventArgs> & handler) const;
    void DownloadAttachmentRequested(event_token token) const;
    event_token CreateFolderRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxCreateFolderRequestEventArgs> & handler) const;
    using CreateFolderRequested_revoker = event_revoker<IEmailDataProviderConnection>;
    CreateFolderRequested_revoker CreateFolderRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxCreateFolderRequestEventArgs> & handler) const;
    void CreateFolderRequested(event_token token) const;
    event_token DeleteFolderRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxDeleteFolderRequestEventArgs> & handler) const;
    using DeleteFolderRequested_revoker = event_revoker<IEmailDataProviderConnection>;
    DeleteFolderRequested_revoker DeleteFolderRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxDeleteFolderRequestEventArgs> & handler) const;
    void DeleteFolderRequested(event_token token) const;
    event_token EmptyFolderRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxEmptyFolderRequestEventArgs> & handler) const;
    using EmptyFolderRequested_revoker = event_revoker<IEmailDataProviderConnection>;
    EmptyFolderRequested_revoker EmptyFolderRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxEmptyFolderRequestEventArgs> & handler) const;
    void EmptyFolderRequested(event_token token) const;
    event_token MoveFolderRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxMoveFolderRequestEventArgs> & handler) const;
    using MoveFolderRequested_revoker = event_revoker<IEmailDataProviderConnection>;
    MoveFolderRequested_revoker MoveFolderRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxMoveFolderRequestEventArgs> & handler) const;
    void MoveFolderRequested(event_token token) const;
    event_token UpdateMeetingResponseRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxUpdateMeetingResponseRequestEventArgs> & handler) const;
    using UpdateMeetingResponseRequested_revoker = event_revoker<IEmailDataProviderConnection>;
    UpdateMeetingResponseRequested_revoker UpdateMeetingResponseRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxUpdateMeetingResponseRequestEventArgs> & handler) const;
    void UpdateMeetingResponseRequested(event_token token) const;
    event_token ForwardMeetingRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxForwardMeetingRequestEventArgs> & handler) const;
    using ForwardMeetingRequested_revoker = event_revoker<IEmailDataProviderConnection>;
    ForwardMeetingRequested_revoker ForwardMeetingRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxForwardMeetingRequestEventArgs> & handler) const;
    void ForwardMeetingRequested(event_token token) const;
    event_token ProposeNewTimeForMeetingRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxProposeNewTimeForMeetingRequestEventArgs> & handler) const;
    using ProposeNewTimeForMeetingRequested_revoker = event_revoker<IEmailDataProviderConnection>;
    ProposeNewTimeForMeetingRequested_revoker ProposeNewTimeForMeetingRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxProposeNewTimeForMeetingRequestEventArgs> & handler) const;
    void ProposeNewTimeForMeetingRequested(event_token token) const;
    event_token SetAutoReplySettingsRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxSetAutoReplySettingsRequestEventArgs> & handler) const;
    using SetAutoReplySettingsRequested_revoker = event_revoker<IEmailDataProviderConnection>;
    SetAutoReplySettingsRequested_revoker SetAutoReplySettingsRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxSetAutoReplySettingsRequestEventArgs> & handler) const;
    void SetAutoReplySettingsRequested(event_token token) const;
    event_token GetAutoReplySettingsRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxGetAutoReplySettingsRequestEventArgs> & handler) const;
    using GetAutoReplySettingsRequested_revoker = event_revoker<IEmailDataProviderConnection>;
    GetAutoReplySettingsRequested_revoker GetAutoReplySettingsRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxGetAutoReplySettingsRequestEventArgs> & handler) const;
    void GetAutoReplySettingsRequested(event_token token) const;
    event_token ResolveRecipientsRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxResolveRecipientsRequestEventArgs> & handler) const;
    using ResolveRecipientsRequested_revoker = event_revoker<IEmailDataProviderConnection>;
    ResolveRecipientsRequested_revoker ResolveRecipientsRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxResolveRecipientsRequestEventArgs> & handler) const;
    void ResolveRecipientsRequested(event_token token) const;
    event_token ValidateCertificatesRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxValidateCertificatesRequestEventArgs> & handler) const;
    using ValidateCertificatesRequested_revoker = event_revoker<IEmailDataProviderConnection>;
    ValidateCertificatesRequested_revoker ValidateCertificatesRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxValidateCertificatesRequestEventArgs> & handler) const;
    void ValidateCertificatesRequested(event_token token) const;
    event_token ServerSearchReadBatchRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxServerSearchReadBatchRequestEventArgs> & handler) const;
    using ServerSearchReadBatchRequested_revoker = event_revoker<IEmailDataProviderConnection>;
    ServerSearchReadBatchRequested_revoker ServerSearchReadBatchRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxServerSearchReadBatchRequestEventArgs> & handler) const;
    void ServerSearchReadBatchRequested(event_token token) const;
    void Start() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailDataProviderTriggerDetails
{
    Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection Connection() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxCreateFolderRequest
{
    hstring EmailMailboxId() const;
    hstring ParentFolderId() const;
    hstring Name() const;
    Windows::Foundation::IAsyncAction ReportCompletedAsync(const Windows::ApplicationModel::Email::EmailFolder & folder) const;
    Windows::Foundation::IAsyncAction ReportFailedAsync(Windows::ApplicationModel::Email::EmailMailboxCreateFolderStatus status) const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxCreateFolderRequestEventArgs
{
    Windows::ApplicationModel::Email::DataProvider::EmailMailboxCreateFolderRequest Request() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxDeleteFolderRequest
{
    hstring EmailMailboxId() const;
    hstring EmailFolderId() const;
    Windows::Foundation::IAsyncAction ReportCompletedAsync() const;
    Windows::Foundation::IAsyncAction ReportFailedAsync(Windows::ApplicationModel::Email::EmailMailboxDeleteFolderStatus status) const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxDeleteFolderRequestEventArgs
{
    Windows::ApplicationModel::Email::DataProvider::EmailMailboxDeleteFolderRequest Request() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxDownloadAttachmentRequest
{
    hstring EmailMailboxId() const;
    hstring EmailMessageId() const;
    hstring EmailAttachmentId() const;
    Windows::Foundation::IAsyncAction ReportCompletedAsync() const;
    Windows::Foundation::IAsyncAction ReportFailedAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxDownloadAttachmentRequestEventArgs
{
    Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadAttachmentRequest Request() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxDownloadMessageRequest
{
    hstring EmailMailboxId() const;
    hstring EmailMessageId() const;
    Windows::Foundation::IAsyncAction ReportCompletedAsync() const;
    Windows::Foundation::IAsyncAction ReportFailedAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxDownloadMessageRequestEventArgs
{
    Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadMessageRequest Request() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxEmptyFolderRequest
{
    hstring EmailMailboxId() const;
    hstring EmailFolderId() const;
    Windows::Foundation::IAsyncAction ReportCompletedAsync() const;
    Windows::Foundation::IAsyncAction ReportFailedAsync(Windows::ApplicationModel::Email::EmailMailboxEmptyFolderStatus status) const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxEmptyFolderRequestEventArgs
{
    Windows::ApplicationModel::Email::DataProvider::EmailMailboxEmptyFolderRequest Request() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxForwardMeetingRequest
{
    hstring EmailMailboxId() const;
    hstring EmailMessageId() const;
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailRecipient> Recipients() const;
    hstring Subject() const;
    Windows::ApplicationModel::Email::EmailMessageBodyKind ForwardHeaderType() const;
    hstring ForwardHeader() const;
    hstring Comment() const;
    Windows::Foundation::IAsyncAction ReportCompletedAsync() const;
    Windows::Foundation::IAsyncAction ReportFailedAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxForwardMeetingRequestEventArgs
{
    Windows::ApplicationModel::Email::DataProvider::EmailMailboxForwardMeetingRequest Request() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxGetAutoReplySettingsRequest
{
    hstring EmailMailboxId() const;
    Windows::ApplicationModel::Email::EmailMailboxAutoReplyMessageResponseKind RequestedFormat() const;
    Windows::Foundation::IAsyncAction ReportCompletedAsync(const Windows::ApplicationModel::Email::EmailMailboxAutoReplySettings & autoReplySettings) const;
    Windows::Foundation::IAsyncAction ReportFailedAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxGetAutoReplySettingsRequestEventArgs
{
    Windows::ApplicationModel::Email::DataProvider::EmailMailboxGetAutoReplySettingsRequest Request() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxMoveFolderRequest
{
    hstring EmailMailboxId() const;
    hstring EmailFolderId() const;
    hstring NewParentFolderId() const;
    hstring NewFolderName() const;
    Windows::Foundation::IAsyncAction ReportCompletedAsync() const;
    Windows::Foundation::IAsyncAction ReportFailedAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxMoveFolderRequestEventArgs
{
    Windows::ApplicationModel::Email::DataProvider::EmailMailboxMoveFolderRequest Request() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxProposeNewTimeForMeetingRequest
{
    hstring EmailMailboxId() const;
    hstring EmailMessageId() const;
    Windows::Foundation::DateTime NewStartTime() const;
    Windows::Foundation::TimeSpan NewDuration() const;
    hstring Subject() const;
    hstring Comment() const;
    Windows::Foundation::IAsyncAction ReportCompletedAsync() const;
    Windows::Foundation::IAsyncAction ReportFailedAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxProposeNewTimeForMeetingRequestEventArgs
{
    Windows::ApplicationModel::Email::DataProvider::EmailMailboxProposeNewTimeForMeetingRequest Request() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxResolveRecipientsRequest
{
    hstring EmailMailboxId() const;
    Windows::Foundation::Collections::IVectorView<hstring> Recipients() const;
    Windows::Foundation::IAsyncAction ReportCompletedAsync(iterable<Windows::ApplicationModel::Email::EmailRecipientResolutionResult> resolutionResults) const;
    Windows::Foundation::IAsyncAction ReportFailedAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxResolveRecipientsRequestEventArgs
{
    Windows::ApplicationModel::Email::DataProvider::EmailMailboxResolveRecipientsRequest Request() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxServerSearchReadBatchRequest
{
    hstring SessionId() const;
    hstring EmailMailboxId() const;
    hstring EmailFolderId() const;
    Windows::ApplicationModel::Email::EmailQueryOptions Options() const;
    uint32_t SuggestedBatchSize() const;
    Windows::Foundation::IAsyncAction SaveMessageAsync(const Windows::ApplicationModel::Email::EmailMessage & message) const;
    Windows::Foundation::IAsyncAction ReportCompletedAsync() const;
    Windows::Foundation::IAsyncAction ReportFailedAsync(Windows::ApplicationModel::Email::EmailBatchStatus batchStatus) const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxServerSearchReadBatchRequestEventArgs
{
    Windows::ApplicationModel::Email::DataProvider::EmailMailboxServerSearchReadBatchRequest Request() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxSetAutoReplySettingsRequest
{
    hstring EmailMailboxId() const;
    Windows::ApplicationModel::Email::EmailMailboxAutoReplySettings AutoReplySettings() const;
    Windows::Foundation::IAsyncAction ReportCompletedAsync() const;
    Windows::Foundation::IAsyncAction ReportFailedAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxSetAutoReplySettingsRequestEventArgs
{
    Windows::ApplicationModel::Email::DataProvider::EmailMailboxSetAutoReplySettingsRequest Request() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxSyncManagerSyncRequest
{
    hstring EmailMailboxId() const;
    Windows::Foundation::IAsyncAction ReportCompletedAsync() const;
    Windows::Foundation::IAsyncAction ReportFailedAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxSyncManagerSyncRequestEventArgs
{
    Windows::ApplicationModel::Email::DataProvider::EmailMailboxSyncManagerSyncRequest Request() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxUpdateMeetingResponseRequest
{
    hstring EmailMailboxId() const;
    hstring EmailMessageId() const;
    Windows::ApplicationModel::Email::EmailMeetingResponseType Response() const;
    hstring Subject() const;
    hstring Comment() const;
    bool SendUpdate() const;
    Windows::Foundation::IAsyncAction ReportCompletedAsync() const;
    Windows::Foundation::IAsyncAction ReportFailedAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxUpdateMeetingResponseRequestEventArgs
{
    Windows::ApplicationModel::Email::DataProvider::EmailMailboxUpdateMeetingResponseRequest Request() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxValidateCertificatesRequest
{
    hstring EmailMailboxId() const;
    Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> Certificates() const;
    Windows::Foundation::IAsyncAction ReportCompletedAsync(iterable<winrt::Windows::ApplicationModel::Email::EmailCertificateValidationStatus> validationStatuses) const;
    Windows::Foundation::IAsyncAction ReportFailedAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IEmailMailboxValidateCertificatesRequestEventArgs
{
    Windows::ApplicationModel::Email::DataProvider::EmailMailboxValidateCertificatesRequest Request() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

}

namespace impl {

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection;
    template <typename D> using consume = Windows::ApplicationModel::Email::DataProvider::impl_IEmailDataProviderConnection<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderTriggerDetails>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderTriggerDetails;
    template <typename D> using consume = Windows::ApplicationModel::Email::DataProvider::impl_IEmailDataProviderTriggerDetails<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxCreateFolderRequest>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxCreateFolderRequest;
    template <typename D> using consume = Windows::ApplicationModel::Email::DataProvider::impl_IEmailMailboxCreateFolderRequest<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxCreateFolderRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxCreateFolderRequestEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Email::DataProvider::impl_IEmailMailboxCreateFolderRequestEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDeleteFolderRequest>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDeleteFolderRequest;
    template <typename D> using consume = Windows::ApplicationModel::Email::DataProvider::impl_IEmailMailboxDeleteFolderRequest<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDeleteFolderRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDeleteFolderRequestEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Email::DataProvider::impl_IEmailMailboxDeleteFolderRequestEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadAttachmentRequest>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadAttachmentRequest;
    template <typename D> using consume = Windows::ApplicationModel::Email::DataProvider::impl_IEmailMailboxDownloadAttachmentRequest<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadAttachmentRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadAttachmentRequestEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Email::DataProvider::impl_IEmailMailboxDownloadAttachmentRequestEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadMessageRequest>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadMessageRequest;
    template <typename D> using consume = Windows::ApplicationModel::Email::DataProvider::impl_IEmailMailboxDownloadMessageRequest<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadMessageRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadMessageRequestEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Email::DataProvider::impl_IEmailMailboxDownloadMessageRequestEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxEmptyFolderRequest>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxEmptyFolderRequest;
    template <typename D> using consume = Windows::ApplicationModel::Email::DataProvider::impl_IEmailMailboxEmptyFolderRequest<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxEmptyFolderRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxEmptyFolderRequestEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Email::DataProvider::impl_IEmailMailboxEmptyFolderRequestEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxForwardMeetingRequest>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxForwardMeetingRequest;
    template <typename D> using consume = Windows::ApplicationModel::Email::DataProvider::impl_IEmailMailboxForwardMeetingRequest<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxForwardMeetingRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxForwardMeetingRequestEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Email::DataProvider::impl_IEmailMailboxForwardMeetingRequestEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxGetAutoReplySettingsRequest>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxGetAutoReplySettingsRequest;
    template <typename D> using consume = Windows::ApplicationModel::Email::DataProvider::impl_IEmailMailboxGetAutoReplySettingsRequest<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxGetAutoReplySettingsRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxGetAutoReplySettingsRequestEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Email::DataProvider::impl_IEmailMailboxGetAutoReplySettingsRequestEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxMoveFolderRequest>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxMoveFolderRequest;
    template <typename D> using consume = Windows::ApplicationModel::Email::DataProvider::impl_IEmailMailboxMoveFolderRequest<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxMoveFolderRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxMoveFolderRequestEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Email::DataProvider::impl_IEmailMailboxMoveFolderRequestEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxProposeNewTimeForMeetingRequest>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxProposeNewTimeForMeetingRequest;
    template <typename D> using consume = Windows::ApplicationModel::Email::DataProvider::impl_IEmailMailboxProposeNewTimeForMeetingRequest<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxProposeNewTimeForMeetingRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxProposeNewTimeForMeetingRequestEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Email::DataProvider::impl_IEmailMailboxProposeNewTimeForMeetingRequestEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxResolveRecipientsRequest>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxResolveRecipientsRequest;
    template <typename D> using consume = Windows::ApplicationModel::Email::DataProvider::impl_IEmailMailboxResolveRecipientsRequest<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxResolveRecipientsRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxResolveRecipientsRequestEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Email::DataProvider::impl_IEmailMailboxResolveRecipientsRequestEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxServerSearchReadBatchRequest>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxServerSearchReadBatchRequest;
    template <typename D> using consume = Windows::ApplicationModel::Email::DataProvider::impl_IEmailMailboxServerSearchReadBatchRequest<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxServerSearchReadBatchRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxServerSearchReadBatchRequestEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Email::DataProvider::impl_IEmailMailboxServerSearchReadBatchRequestEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSetAutoReplySettingsRequest>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSetAutoReplySettingsRequest;
    template <typename D> using consume = Windows::ApplicationModel::Email::DataProvider::impl_IEmailMailboxSetAutoReplySettingsRequest<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSetAutoReplySettingsRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSetAutoReplySettingsRequestEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Email::DataProvider::impl_IEmailMailboxSetAutoReplySettingsRequestEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSyncManagerSyncRequest>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSyncManagerSyncRequest;
    template <typename D> using consume = Windows::ApplicationModel::Email::DataProvider::impl_IEmailMailboxSyncManagerSyncRequest<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSyncManagerSyncRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSyncManagerSyncRequestEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Email::DataProvider::impl_IEmailMailboxSyncManagerSyncRequestEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxUpdateMeetingResponseRequest>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxUpdateMeetingResponseRequest;
    template <typename D> using consume = Windows::ApplicationModel::Email::DataProvider::impl_IEmailMailboxUpdateMeetingResponseRequest<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxUpdateMeetingResponseRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxUpdateMeetingResponseRequestEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Email::DataProvider::impl_IEmailMailboxUpdateMeetingResponseRequestEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxValidateCertificatesRequest>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxValidateCertificatesRequest;
    template <typename D> using consume = Windows::ApplicationModel::Email::DataProvider::impl_IEmailMailboxValidateCertificatesRequest<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::IEmailMailboxValidateCertificatesRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::IEmailMailboxValidateCertificatesRequestEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Email::DataProvider::impl_IEmailMailboxValidateCertificatesRequestEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.DataProvider.EmailDataProviderConnection"; }
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderTriggerDetails>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::EmailDataProviderTriggerDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.DataProvider.EmailDataProviderTriggerDetails"; }
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxCreateFolderRequest>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxCreateFolderRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.DataProvider.EmailMailboxCreateFolderRequest"; }
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxCreateFolderRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxCreateFolderRequestEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.DataProvider.EmailMailboxCreateFolderRequestEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxDeleteFolderRequest>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxDeleteFolderRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.DataProvider.EmailMailboxDeleteFolderRequest"; }
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxDeleteFolderRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxDeleteFolderRequestEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.DataProvider.EmailMailboxDeleteFolderRequestEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadAttachmentRequest>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadAttachmentRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.DataProvider.EmailMailboxDownloadAttachmentRequest"; }
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadAttachmentRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadAttachmentRequestEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.DataProvider.EmailMailboxDownloadAttachmentRequestEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadMessageRequest>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadMessageRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.DataProvider.EmailMailboxDownloadMessageRequest"; }
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadMessageRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadMessageRequestEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.DataProvider.EmailMailboxDownloadMessageRequestEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxEmptyFolderRequest>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxEmptyFolderRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.DataProvider.EmailMailboxEmptyFolderRequest"; }
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxEmptyFolderRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxEmptyFolderRequestEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.DataProvider.EmailMailboxEmptyFolderRequestEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxForwardMeetingRequest>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxForwardMeetingRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.DataProvider.EmailMailboxForwardMeetingRequest"; }
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxForwardMeetingRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxForwardMeetingRequestEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.DataProvider.EmailMailboxForwardMeetingRequestEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxGetAutoReplySettingsRequest>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxGetAutoReplySettingsRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.DataProvider.EmailMailboxGetAutoReplySettingsRequest"; }
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxGetAutoReplySettingsRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxGetAutoReplySettingsRequestEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.DataProvider.EmailMailboxGetAutoReplySettingsRequestEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxMoveFolderRequest>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxMoveFolderRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.DataProvider.EmailMailboxMoveFolderRequest"; }
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxMoveFolderRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxMoveFolderRequestEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.DataProvider.EmailMailboxMoveFolderRequestEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxProposeNewTimeForMeetingRequest>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxProposeNewTimeForMeetingRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.DataProvider.EmailMailboxProposeNewTimeForMeetingRequest"; }
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxProposeNewTimeForMeetingRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxProposeNewTimeForMeetingRequestEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.DataProvider.EmailMailboxProposeNewTimeForMeetingRequestEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxResolveRecipientsRequest>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxResolveRecipientsRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.DataProvider.EmailMailboxResolveRecipientsRequest"; }
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxResolveRecipientsRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxResolveRecipientsRequestEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.DataProvider.EmailMailboxResolveRecipientsRequestEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxServerSearchReadBatchRequest>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxServerSearchReadBatchRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.DataProvider.EmailMailboxServerSearchReadBatchRequest"; }
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxServerSearchReadBatchRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxServerSearchReadBatchRequestEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.DataProvider.EmailMailboxServerSearchReadBatchRequestEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxSetAutoReplySettingsRequest>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxSetAutoReplySettingsRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.DataProvider.EmailMailboxSetAutoReplySettingsRequest"; }
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxSetAutoReplySettingsRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxSetAutoReplySettingsRequestEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.DataProvider.EmailMailboxSetAutoReplySettingsRequestEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxSyncManagerSyncRequest>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxSyncManagerSyncRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.DataProvider.EmailMailboxSyncManagerSyncRequest"; }
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxSyncManagerSyncRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxSyncManagerSyncRequestEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.DataProvider.EmailMailboxSyncManagerSyncRequestEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxUpdateMeetingResponseRequest>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxUpdateMeetingResponseRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.DataProvider.EmailMailboxUpdateMeetingResponseRequest"; }
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxUpdateMeetingResponseRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxUpdateMeetingResponseRequestEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.DataProvider.EmailMailboxUpdateMeetingResponseRequestEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxValidateCertificatesRequest>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxValidateCertificatesRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.DataProvider.EmailMailboxValidateCertificatesRequest"; }
};

template <> struct traits<Windows::ApplicationModel::Email::DataProvider::EmailMailboxValidateCertificatesRequestEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Email::DataProvider::EmailMailboxValidateCertificatesRequestEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Email.DataProvider.EmailMailboxValidateCertificatesRequestEventArgs"; }
};

}

}
