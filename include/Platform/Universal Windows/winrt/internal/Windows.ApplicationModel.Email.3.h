// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.Email.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::Email {

struct WINRT_EBO EmailAttachment :
    Windows::ApplicationModel::Email::IEmailAttachment,
    impl::require<EmailAttachment, Windows::ApplicationModel::Email::IEmailAttachment2>
{
    EmailAttachment(std::nullptr_t) noexcept {}
    EmailAttachment();
    EmailAttachment(hstring_view fileName, const Windows::Storage::Streams::IRandomAccessStreamReference & data);
    EmailAttachment(hstring_view fileName, const Windows::Storage::Streams::IRandomAccessStreamReference & data, hstring_view mimeType);
};

struct WINRT_EBO EmailConversation :
    Windows::ApplicationModel::Email::IEmailConversation
{
    EmailConversation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailConversationBatch :
    Windows::ApplicationModel::Email::IEmailConversationBatch
{
    EmailConversationBatch(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailConversationReader :
    Windows::ApplicationModel::Email::IEmailConversationReader
{
    EmailConversationReader(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailFolder :
    Windows::ApplicationModel::Email::IEmailFolder
{
    EmailFolder(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailIrmInfo :
    Windows::ApplicationModel::Email::IEmailIrmInfo
{
    EmailIrmInfo(std::nullptr_t) noexcept {}
    EmailIrmInfo();
    EmailIrmInfo(const Windows::Foundation::DateTime & expiration, const Windows::ApplicationModel::Email::EmailIrmTemplate & irmTemplate);
};

struct WINRT_EBO EmailIrmTemplate :
    Windows::ApplicationModel::Email::IEmailIrmTemplate
{
    EmailIrmTemplate(std::nullptr_t) noexcept {}
    EmailIrmTemplate();
    EmailIrmTemplate(hstring_view id, hstring_view name, hstring_view description);
};

struct WINRT_EBO EmailItemCounts :
    Windows::ApplicationModel::Email::IEmailItemCounts
{
    EmailItemCounts(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailbox :
    Windows::ApplicationModel::Email::IEmailMailbox,
    impl::require<EmailMailbox, Windows::ApplicationModel::Email::IEmailMailbox2, Windows::ApplicationModel::Email::IEmailMailbox3, Windows::ApplicationModel::Email::IEmailMailbox4>
{
    EmailMailbox(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxAction :
    Windows::ApplicationModel::Email::IEmailMailboxAction
{
    EmailMailboxAction(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxAutoReply :
    Windows::ApplicationModel::Email::IEmailMailboxAutoReply
{
    EmailMailboxAutoReply(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxAutoReplySettings :
    Windows::ApplicationModel::Email::IEmailMailboxAutoReplySettings
{
    EmailMailboxAutoReplySettings(std::nullptr_t) noexcept {}
    EmailMailboxAutoReplySettings();
};

struct WINRT_EBO EmailMailboxCapabilities :
    Windows::ApplicationModel::Email::IEmailMailboxCapabilities,
    impl::require<EmailMailboxCapabilities, Windows::ApplicationModel::Email::IEmailMailboxCapabilities2, Windows::ApplicationModel::Email::IEmailMailboxCapabilities3>
{
    EmailMailboxCapabilities(std::nullptr_t) noexcept {}
    using impl_IEmailMailboxCapabilities::CanForwardMeetings;
    using impl_IEmailMailboxCapabilities::CanGetAndSetExternalAutoReplies;
    using impl_IEmailMailboxCapabilities::CanGetAndSetInternalAutoReplies;
    using impl_IEmailMailboxCapabilities::CanProposeNewTimeForMeetings;
    using impl_IEmailMailboxCapabilities::CanServerSearchFolders;
    using impl_IEmailMailboxCapabilities::CanServerSearchMailbox;
    using impl_IEmailMailboxCapabilities::CanSmartSend;
    using impl_IEmailMailboxCapabilities::CanUpdateMeetingResponses;
    using impl_IEmailMailboxCapabilities2::CanCreateFolder;
    using impl_IEmailMailboxCapabilities2::CanDeleteFolder;
    using impl_IEmailMailboxCapabilities2::CanEmptyFolder;
    using impl_IEmailMailboxCapabilities2::CanMoveFolder;
    using impl_IEmailMailboxCapabilities2::CanResolveRecipients;
    using impl_IEmailMailboxCapabilities2::CanValidateCertificates;
    using impl_IEmailMailboxCapabilities3::CanCreateFolder;
    using impl_IEmailMailboxCapabilities3::CanDeleteFolder;
    using impl_IEmailMailboxCapabilities3::CanEmptyFolder;
    using impl_IEmailMailboxCapabilities3::CanForwardMeetings;
    using impl_IEmailMailboxCapabilities3::CanGetAndSetExternalAutoReplies;
    using impl_IEmailMailboxCapabilities3::CanGetAndSetInternalAutoReplies;
    using impl_IEmailMailboxCapabilities3::CanMoveFolder;
    using impl_IEmailMailboxCapabilities3::CanProposeNewTimeForMeetings;
    using impl_IEmailMailboxCapabilities3::CanResolveRecipients;
    using impl_IEmailMailboxCapabilities3::CanServerSearchFolders;
    using impl_IEmailMailboxCapabilities3::CanServerSearchMailbox;
    using impl_IEmailMailboxCapabilities3::CanSmartSend;
    using impl_IEmailMailboxCapabilities3::CanUpdateMeetingResponses;
    using impl_IEmailMailboxCapabilities3::CanValidateCertificates;
};

struct WINRT_EBO EmailMailboxChange :
    Windows::ApplicationModel::Email::IEmailMailboxChange
{
    EmailMailboxChange(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxChangeReader :
    Windows::ApplicationModel::Email::IEmailMailboxChangeReader
{
    EmailMailboxChangeReader(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxChangeTracker :
    Windows::ApplicationModel::Email::IEmailMailboxChangeTracker
{
    EmailMailboxChangeTracker(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxChangedDeferral :
    Windows::ApplicationModel::Email::IEmailMailboxChangedDeferral
{
    EmailMailboxChangedDeferral(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxChangedEventArgs :
    Windows::ApplicationModel::Email::IEmailMailboxChangedEventArgs
{
    EmailMailboxChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxCreateFolderResult :
    Windows::ApplicationModel::Email::IEmailMailboxCreateFolderResult
{
    EmailMailboxCreateFolderResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMailboxPolicies :
    Windows::ApplicationModel::Email::IEmailMailboxPolicies,
    impl::require<EmailMailboxPolicies, Windows::ApplicationModel::Email::IEmailMailboxPolicies2, Windows::ApplicationModel::Email::IEmailMailboxPolicies3>
{
    EmailMailboxPolicies(std::nullptr_t) noexcept {}
    using impl_IEmailMailboxPolicies::AllowSmimeSoftCertificates;
    using impl_IEmailMailboxPolicies::AllowedSmimeEncryptionAlgorithmNegotiation;
    using impl_IEmailMailboxPolicies::RequiredSmimeEncryptionAlgorithm;
    using impl_IEmailMailboxPolicies::RequiredSmimeSigningAlgorithm;
    using impl_IEmailMailboxPolicies2::MustEncryptSmimeMessages;
    using impl_IEmailMailboxPolicies2::MustSignSmimeMessages;
    using impl_IEmailMailboxPolicies3::AllowSmimeSoftCertificates;
    using impl_IEmailMailboxPolicies3::AllowedSmimeEncryptionAlgorithmNegotiation;
    using impl_IEmailMailboxPolicies3::MustEncryptSmimeMessages;
    using impl_IEmailMailboxPolicies3::MustSignSmimeMessages;
    using impl_IEmailMailboxPolicies3::RequiredSmimeEncryptionAlgorithm;
    using impl_IEmailMailboxPolicies3::RequiredSmimeSigningAlgorithm;
};

struct WINRT_EBO EmailMailboxSyncManager :
    Windows::ApplicationModel::Email::IEmailMailboxSyncManager,
    impl::require<EmailMailboxSyncManager, Windows::ApplicationModel::Email::IEmailMailboxSyncManager2>
{
    EmailMailboxSyncManager(std::nullptr_t) noexcept {}
    using impl_IEmailMailboxSyncManager::LastAttemptedSyncTime;
    using impl_IEmailMailboxSyncManager::LastSuccessfulSyncTime;
    using impl_IEmailMailboxSyncManager::Status;
    using impl_IEmailMailboxSyncManager2::LastAttemptedSyncTime;
    using impl_IEmailMailboxSyncManager2::LastSuccessfulSyncTime;
    using impl_IEmailMailboxSyncManager2::Status;
};

struct EmailManager
{
    EmailManager() = delete;
    static Windows::Foundation::IAsyncAction ShowComposeNewEmailAsync(const Windows::ApplicationModel::Email::EmailMessage & message);
    static Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Email::EmailStore> RequestStoreAsync(Windows::ApplicationModel::Email::EmailStoreAccessType accessType);
    static Windows::ApplicationModel::Email::EmailManagerForUser GetForUser(const Windows::System::User & user);
};

struct WINRT_EBO EmailManagerForUser :
    Windows::ApplicationModel::Email::IEmailManagerForUser
{
    EmailManagerForUser(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMeetingInfo :
    Windows::ApplicationModel::Email::IEmailMeetingInfo,
    impl::require<EmailMeetingInfo, Windows::ApplicationModel::Email::IEmailMeetingInfo2>
{
    EmailMeetingInfo(std::nullptr_t) noexcept {}
    EmailMeetingInfo();
};

struct WINRT_EBO EmailMessage :
    Windows::ApplicationModel::Email::IEmailMessage,
    impl::require<EmailMessage, Windows::ApplicationModel::Email::IEmailMessage2, Windows::ApplicationModel::Email::IEmailMessage3>
{
    EmailMessage(std::nullptr_t) noexcept {}
    EmailMessage();
};

struct WINRT_EBO EmailMessageBatch :
    Windows::ApplicationModel::Email::IEmailMessageBatch
{
    EmailMessageBatch(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailMessageReader :
    Windows::ApplicationModel::Email::IEmailMessageReader
{
    EmailMessageReader(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailQueryOptions :
    Windows::ApplicationModel::Email::IEmailQueryOptions
{
    EmailQueryOptions(std::nullptr_t) noexcept {}
    EmailQueryOptions();
    EmailQueryOptions(hstring_view text);
    EmailQueryOptions(hstring_view text, Windows::ApplicationModel::Email::EmailQuerySearchFields fields);
};

struct WINRT_EBO EmailQueryTextSearch :
    Windows::ApplicationModel::Email::IEmailQueryTextSearch
{
    EmailQueryTextSearch(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailRecipient :
    Windows::ApplicationModel::Email::IEmailRecipient
{
    EmailRecipient(std::nullptr_t) noexcept {}
    EmailRecipient();
    EmailRecipient(hstring_view address);
    EmailRecipient(hstring_view address, hstring_view name);
};

struct WINRT_EBO EmailRecipientResolutionResult :
    Windows::ApplicationModel::Email::IEmailRecipientResolutionResult,
    impl::require<EmailRecipientResolutionResult, Windows::ApplicationModel::Email::IEmailRecipientResolutionResult2>
{
    EmailRecipientResolutionResult(std::nullptr_t) noexcept {}
    EmailRecipientResolutionResult();
    using impl_IEmailRecipientResolutionResult::Status;
    using impl_IEmailRecipientResolutionResult2::Status;
};

struct WINRT_EBO EmailStore :
    Windows::ApplicationModel::Email::IEmailStore
{
    EmailStore(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailStoreNotificationTriggerDetails :
    Windows::ApplicationModel::Email::IEmailStoreNotificationTriggerDetails
{
    EmailStoreNotificationTriggerDetails(std::nullptr_t) noexcept {}
};

}

}
