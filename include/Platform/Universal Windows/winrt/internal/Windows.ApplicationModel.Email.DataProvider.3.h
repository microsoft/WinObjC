// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.Email.DataProvider.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::Email::DataProvider {

struct WINRT_EBO EmailDataProviderConnection :
    Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection
{
    EmailDataProviderConnection(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailDataProviderTriggerDetails :
    Windows::ApplicationModel::Email::DataProvider::IEmailDataProviderTriggerDetails
{
    EmailDataProviderTriggerDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxCreateFolderRequest :
    Windows::ApplicationModel::Email::DataProvider::IEmailMailboxCreateFolderRequest
{
    EmailMailboxCreateFolderRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxCreateFolderRequestEventArgs :
    Windows::ApplicationModel::Email::DataProvider::IEmailMailboxCreateFolderRequestEventArgs
{
    EmailMailboxCreateFolderRequestEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxDeleteFolderRequest :
    Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDeleteFolderRequest
{
    EmailMailboxDeleteFolderRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxDeleteFolderRequestEventArgs :
    Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDeleteFolderRequestEventArgs
{
    EmailMailboxDeleteFolderRequestEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxDownloadAttachmentRequest :
    Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadAttachmentRequest
{
    EmailMailboxDownloadAttachmentRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxDownloadAttachmentRequestEventArgs :
    Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadAttachmentRequestEventArgs
{
    EmailMailboxDownloadAttachmentRequestEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxDownloadMessageRequest :
    Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadMessageRequest
{
    EmailMailboxDownloadMessageRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxDownloadMessageRequestEventArgs :
    Windows::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadMessageRequestEventArgs
{
    EmailMailboxDownloadMessageRequestEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxEmptyFolderRequest :
    Windows::ApplicationModel::Email::DataProvider::IEmailMailboxEmptyFolderRequest
{
    EmailMailboxEmptyFolderRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxEmptyFolderRequestEventArgs :
    Windows::ApplicationModel::Email::DataProvider::IEmailMailboxEmptyFolderRequestEventArgs
{
    EmailMailboxEmptyFolderRequestEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxForwardMeetingRequest :
    Windows::ApplicationModel::Email::DataProvider::IEmailMailboxForwardMeetingRequest
{
    EmailMailboxForwardMeetingRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxForwardMeetingRequestEventArgs :
    Windows::ApplicationModel::Email::DataProvider::IEmailMailboxForwardMeetingRequestEventArgs
{
    EmailMailboxForwardMeetingRequestEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxGetAutoReplySettingsRequest :
    Windows::ApplicationModel::Email::DataProvider::IEmailMailboxGetAutoReplySettingsRequest
{
    EmailMailboxGetAutoReplySettingsRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxGetAutoReplySettingsRequestEventArgs :
    Windows::ApplicationModel::Email::DataProvider::IEmailMailboxGetAutoReplySettingsRequestEventArgs
{
    EmailMailboxGetAutoReplySettingsRequestEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxMoveFolderRequest :
    Windows::ApplicationModel::Email::DataProvider::IEmailMailboxMoveFolderRequest
{
    EmailMailboxMoveFolderRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxMoveFolderRequestEventArgs :
    Windows::ApplicationModel::Email::DataProvider::IEmailMailboxMoveFolderRequestEventArgs
{
    EmailMailboxMoveFolderRequestEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxProposeNewTimeForMeetingRequest :
    Windows::ApplicationModel::Email::DataProvider::IEmailMailboxProposeNewTimeForMeetingRequest
{
    EmailMailboxProposeNewTimeForMeetingRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxProposeNewTimeForMeetingRequestEventArgs :
    Windows::ApplicationModel::Email::DataProvider::IEmailMailboxProposeNewTimeForMeetingRequestEventArgs
{
    EmailMailboxProposeNewTimeForMeetingRequestEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxResolveRecipientsRequest :
    Windows::ApplicationModel::Email::DataProvider::IEmailMailboxResolveRecipientsRequest
{
    EmailMailboxResolveRecipientsRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxResolveRecipientsRequestEventArgs :
    Windows::ApplicationModel::Email::DataProvider::IEmailMailboxResolveRecipientsRequestEventArgs
{
    EmailMailboxResolveRecipientsRequestEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxServerSearchReadBatchRequest :
    Windows::ApplicationModel::Email::DataProvider::IEmailMailboxServerSearchReadBatchRequest
{
    EmailMailboxServerSearchReadBatchRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxServerSearchReadBatchRequestEventArgs :
    Windows::ApplicationModel::Email::DataProvider::IEmailMailboxServerSearchReadBatchRequestEventArgs
{
    EmailMailboxServerSearchReadBatchRequestEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxSetAutoReplySettingsRequest :
    Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSetAutoReplySettingsRequest
{
    EmailMailboxSetAutoReplySettingsRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxSetAutoReplySettingsRequestEventArgs :
    Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSetAutoReplySettingsRequestEventArgs
{
    EmailMailboxSetAutoReplySettingsRequestEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxSyncManagerSyncRequest :
    Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSyncManagerSyncRequest
{
    EmailMailboxSyncManagerSyncRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxSyncManagerSyncRequestEventArgs :
    Windows::ApplicationModel::Email::DataProvider::IEmailMailboxSyncManagerSyncRequestEventArgs
{
    EmailMailboxSyncManagerSyncRequestEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxUpdateMeetingResponseRequest :
    Windows::ApplicationModel::Email::DataProvider::IEmailMailboxUpdateMeetingResponseRequest
{
    EmailMailboxUpdateMeetingResponseRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxUpdateMeetingResponseRequestEventArgs :
    Windows::ApplicationModel::Email::DataProvider::IEmailMailboxUpdateMeetingResponseRequestEventArgs
{
    EmailMailboxUpdateMeetingResponseRequestEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxValidateCertificatesRequest :
    Windows::ApplicationModel::Email::DataProvider::IEmailMailboxValidateCertificatesRequest
{
    EmailMailboxValidateCertificatesRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxValidateCertificatesRequestEventArgs :
    Windows::ApplicationModel::Email::DataProvider::IEmailMailboxValidateCertificatesRequestEventArgs
{
    EmailMailboxValidateCertificatesRequestEventArgs(std::nullptr_t) noexcept {}
};

}

}
