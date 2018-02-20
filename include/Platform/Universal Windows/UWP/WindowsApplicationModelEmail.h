//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

// WindowsApplicationModelEmail.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
#define OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsConsolidatedNamespace.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WAEEmailMessage, WAEEmailStore, WAEEmailManagerForUser, WAEEmailMailbox, WAEEmailConversationReader, WAEEmailQueryOptions, WAEEmailMessageReader, WAEEmailConversation, WAEEmailFolder, WAEEmailRecipient, WAEEmailIrmTemplate, WAEEmailIrmInfo, WAEEmailAttachment, WAEEmailMeetingInfo, WAEEmailMailboxChangedDeferral, WAEEmailMailboxCapabilities, WAEEmailMailboxChangeTracker, WAEEmailMailboxPolicies, WAEEmailMailboxSyncManager, WAEEmailMailboxChangedEventArgs, WAEEmailMailboxAutoReplySettings, WAEEmailRecipientResolutionResult, WAEEmailMailboxCreateFolderResult, WAEEmailMailboxAutoReply, WAEEmailItemCounts, WAEEmailQueryTextSearch, WAEEmailConversationBatch, WAEEmailMessageBatch, WAEEmailMailboxAction, WAEEmailMailboxChange, WAEEmailMailboxChangeReader, WAEEmailManager, WAEEmailStoreNotificationTriggerDetails;
@protocol WAEIEmailManagerStatics, WAEIEmailManagerStatics2, WAEIEmailManagerStatics3, WAEIEmailManagerForUser, WAEIEmailStore, WAEIEmailRecipient, WAEIEmailRecipientFactory, WAEIEmailIrmTemplate, WAEIEmailIrmTemplateFactory, WAEIEmailIrmInfo, WAEIEmailIrmInfoFactory, WAEIEmailMessage, WAEIEmailMessage2, WAEIEmailMessage3, WAEIEmailMessage4, WAEIEmailAttachment, WAEIEmailAttachment2, WAEIEmailAttachmentFactory, WAEIEmailAttachmentFactory2, WAEIEmailMailboxChangedEventArgs, WAEIEmailMailboxChangedDeferral, WAEIEmailStoreNotificationTriggerDetails, WAEIEmailMailboxPolicies, WAEIEmailMailboxPolicies2, WAEIEmailMailboxPolicies3, WAEIEmailMailboxCapabilities, WAEIEmailMailboxCapabilities2, WAEIEmailMailboxCapabilities3, WAEIEmailMailbox, WAEIEmailMailbox2, WAEIEmailMailbox3, WAEIEmailMailbox4, WAEIEmailMailbox5, WAEIEmailRecipientResolutionResult, WAEIEmailRecipientResolutionResult2, WAEIEmailMailboxCreateFolderResult, WAEIEmailMailboxAutoReplySettings, WAEIEmailMailboxAutoReply, WAEIEmailMailboxSyncManager, WAEIEmailMailboxSyncManager2, WAEIEmailFolder, WAEIEmailConversation, WAEIEmailMailboxAction, WAEIEmailQueryTextSearch, WAEIEmailQueryOptionsFactory, WAEIEmailQueryOptions, WAEIEmailConversationBatch, WAEIEmailConversationReader, WAEIEmailMessageBatch, WAEIEmailMessageReader, WAEIEmailMailboxChange, WAEIEmailMailboxChangeReader, WAEIEmailMailboxChangeTracker, WAEIEmailMeetingInfo, WAEIEmailMeetingInfo2, WAEIEmailItemCounts;

// Windows.ApplicationModel.Email.EmailCertificateValidationStatus
enum _WAEEmailCertificateValidationStatus {
    WAEEmailCertificateValidationStatusSuccess = 0,
    WAEEmailCertificateValidationStatusNoMatch = 1,
    WAEEmailCertificateValidationStatusInvalidUsage = 2,
    WAEEmailCertificateValidationStatusInvalidCertificate = 3,
    WAEEmailCertificateValidationStatusRevoked = 4,
    WAEEmailCertificateValidationStatusChainRevoked = 5,
    WAEEmailCertificateValidationStatusRevocationServerFailure = 6,
    WAEEmailCertificateValidationStatusExpired = 7,
    WAEEmailCertificateValidationStatusUntrusted = 8,
    WAEEmailCertificateValidationStatusServerError = 9,
    WAEEmailCertificateValidationStatusUnknownFailure = 10,
};
typedef unsigned WAEEmailCertificateValidationStatus;

// Windows.ApplicationModel.Email.EmailStoreAccessType
enum _WAEEmailStoreAccessType {
    WAEEmailStoreAccessTypeAppMailboxesReadWrite = 0,
    WAEEmailStoreAccessTypeAllMailboxesLimitedReadWrite = 1,
};
typedef unsigned WAEEmailStoreAccessType;

// Windows.ApplicationModel.Email.EmailMessageBodyKind
enum _WAEEmailMessageBodyKind {
    WAEEmailMessageBodyKindHtml = 0,
    WAEEmailMessageBodyKindPlainText = 1,
};
typedef unsigned WAEEmailMessageBodyKind;

// Windows.ApplicationModel.Email.EmailAttachmentDownloadState
enum _WAEEmailAttachmentDownloadState {
    WAEEmailAttachmentDownloadStateNotDownloaded = 0,
    WAEEmailAttachmentDownloadStateDownloading = 1,
    WAEEmailAttachmentDownloadStateDownloaded = 2,
    WAEEmailAttachmentDownloadStateFailed = 3,
};
typedef unsigned WAEEmailAttachmentDownloadState;

// Windows.ApplicationModel.Email.EmailMessageDownloadState
enum _WAEEmailMessageDownloadState {
    WAEEmailMessageDownloadStatePartiallyDownloaded = 0,
    WAEEmailMessageDownloadStateDownloading = 1,
    WAEEmailMessageDownloadStateDownloaded = 2,
    WAEEmailMessageDownloadStateFailed = 3,
};
typedef unsigned WAEEmailMessageDownloadState;

// Windows.ApplicationModel.Email.EmailSpecialFolderKind
enum _WAEEmailSpecialFolderKind {
    WAEEmailSpecialFolderKindNone = 0,
    WAEEmailSpecialFolderKindRoot = 1,
    WAEEmailSpecialFolderKindInbox = 2,
    WAEEmailSpecialFolderKindOutbox = 3,
    WAEEmailSpecialFolderKindDrafts = 4,
    WAEEmailSpecialFolderKindDeletedItems = 5,
    WAEEmailSpecialFolderKindSent = 6,
};
typedef unsigned WAEEmailSpecialFolderKind;

// Windows.ApplicationModel.Email.EmailQueryKind
enum _WAEEmailQueryKind {
    WAEEmailQueryKindAll = 0,
    WAEEmailQueryKindImportant = 1,
    WAEEmailQueryKindFlagged = 2,
    WAEEmailQueryKindUnread = 3,
    WAEEmailQueryKindRead = 4,
    WAEEmailQueryKindUnseen = 5,
};
typedef unsigned WAEEmailQueryKind;

// Windows.ApplicationModel.Email.EmailMailboxChangeType
enum _WAEEmailMailboxChangeType {
    WAEEmailMailboxChangeTypeMessageCreated = 0,
    WAEEmailMailboxChangeTypeMessageModified = 1,
    WAEEmailMailboxChangeTypeMessageDeleted = 2,
    WAEEmailMailboxChangeTypeFolderCreated = 3,
    WAEEmailMailboxChangeTypeFolderModified = 4,
    WAEEmailMailboxChangeTypeFolderDeleted = 5,
    WAEEmailMailboxChangeTypeChangeTrackingLost = 6,
};
typedef unsigned WAEEmailMailboxChangeType;

// Windows.ApplicationModel.Email.EmailQuerySortDirection
enum _WAEEmailQuerySortDirection {
    WAEEmailQuerySortDirectionDescending = 0,
    WAEEmailQuerySortDirectionAscending = 1,
};
typedef unsigned WAEEmailQuerySortDirection;

// Windows.ApplicationModel.Email.EmailQuerySortProperty
enum _WAEEmailQuerySortProperty {
    WAEEmailQuerySortPropertyDate = 0,
};
typedef unsigned WAEEmailQuerySortProperty;

// Windows.ApplicationModel.Email.EmailQuerySearchFields
enum _WAEEmailQuerySearchFields {
    WAEEmailQuerySearchFieldsNone = 0,
    WAEEmailQuerySearchFieldsSubject = 1,
    WAEEmailQuerySearchFieldsSender = 2,
    WAEEmailQuerySearchFieldsPreview = 4,
    WAEEmailQuerySearchFieldsRecipients = 8,
    WAEEmailQuerySearchFieldsAll = -1,
};
typedef unsigned WAEEmailQuerySearchFields;

// Windows.ApplicationModel.Email.EmailBatchStatus
enum _WAEEmailBatchStatus {
    WAEEmailBatchStatusSuccess = 0,
    WAEEmailBatchStatusServerSearchSyncManagerError = 1,
    WAEEmailBatchStatusServerSearchUnknownError = 2,
};
typedef unsigned WAEEmailBatchStatus;

// Windows.ApplicationModel.Email.EmailMessageResponseKind
enum _WAEEmailMessageResponseKind {
    WAEEmailMessageResponseKindNone = 0,
    WAEEmailMessageResponseKindReply = 1,
    WAEEmailMessageResponseKindReplyAll = 2,
    WAEEmailMessageResponseKindForward = 3,
};
typedef unsigned WAEEmailMessageResponseKind;

// Windows.ApplicationModel.Email.EmailMeetingResponseType
enum _WAEEmailMeetingResponseType {
    WAEEmailMeetingResponseTypeAccept = 0,
    WAEEmailMeetingResponseTypeDecline = 1,
    WAEEmailMeetingResponseTypeTentative = 2,
};
typedef unsigned WAEEmailMeetingResponseType;

// Windows.ApplicationModel.Email.EmailMailboxActionKind
enum _WAEEmailMailboxActionKind {
    WAEEmailMailboxActionKindMarkMessageAsSeen = 0,
    WAEEmailMailboxActionKindMarkMessageRead = 1,
    WAEEmailMailboxActionKindChangeMessageFlagState = 2,
    WAEEmailMailboxActionKindMoveMessage = 3,
    WAEEmailMailboxActionKindSaveDraft = 4,
    WAEEmailMailboxActionKindSendMessage = 5,
    WAEEmailMailboxActionKindCreateResponseReplyMessage = 6,
    WAEEmailMailboxActionKindCreateResponseReplyAllMessage = 7,
    WAEEmailMailboxActionKindCreateResponseForwardMessage = 8,
    WAEEmailMailboxActionKindMoveFolder = 9,
    WAEEmailMailboxActionKindMarkFolderForSyncEnabled = 10,
};
typedef unsigned WAEEmailMailboxActionKind;

// Windows.ApplicationModel.Email.EmailImportance
enum _WAEEmailImportance {
    WAEEmailImportanceNormal = 0,
    WAEEmailImportanceHigh = 1,
    WAEEmailImportanceLow = 2,
};
typedef unsigned WAEEmailImportance;

// Windows.ApplicationModel.Email.EmailFlagState
enum _WAEEmailFlagState {
    WAEEmailFlagStateUnflagged = 0,
    WAEEmailFlagStateFlagged = 1,
    WAEEmailFlagStateCompleted = 2,
    WAEEmailFlagStateCleared = 3,
};
typedef unsigned WAEEmailFlagState;

// Windows.ApplicationModel.Email.EmailMailboxSyncStatus
enum _WAEEmailMailboxSyncStatus {
    WAEEmailMailboxSyncStatusIdle = 0,
    WAEEmailMailboxSyncStatusSyncing = 1,
    WAEEmailMailboxSyncStatusUpToDate = 2,
    WAEEmailMailboxSyncStatusAuthenticationError = 3,
    WAEEmailMailboxSyncStatusPolicyError = 4,
    WAEEmailMailboxSyncStatusUnknownError = 5,
    WAEEmailMailboxSyncStatusManualAccountRemovalRequired = 6,
};
typedef unsigned WAEEmailMailboxSyncStatus;

// Windows.ApplicationModel.Email.EmailMailboxOtherAppReadAccess
enum _WAEEmailMailboxOtherAppReadAccess {
    WAEEmailMailboxOtherAppReadAccessSystemOnly = 0,
    WAEEmailMailboxOtherAppReadAccessFull = 1,
    WAEEmailMailboxOtherAppReadAccessNone = 2,
};
typedef unsigned WAEEmailMailboxOtherAppReadAccess;

// Windows.ApplicationModel.Email.EmailMailboxOtherAppWriteAccess
enum _WAEEmailMailboxOtherAppWriteAccess {
    WAEEmailMailboxOtherAppWriteAccessNone = 0,
    WAEEmailMailboxOtherAppWriteAccessLimited = 1,
};
typedef unsigned WAEEmailMailboxOtherAppWriteAccess;

// Windows.ApplicationModel.Email.EmailMailboxAllowedSmimeEncryptionAlgorithmNegotiation
enum _WAEEmailMailboxAllowedSmimeEncryptionAlgorithmNegotiation {
    WAEEmailMailboxAllowedSmimeEncryptionAlgorithmNegotiationNone = 0,
    WAEEmailMailboxAllowedSmimeEncryptionAlgorithmNegotiationStrongAlgorithm = 1,
    WAEEmailMailboxAllowedSmimeEncryptionAlgorithmNegotiationAnyAlgorithm = 2,
};
typedef unsigned WAEEmailMailboxAllowedSmimeEncryptionAlgorithmNegotiation;

// Windows.ApplicationModel.Email.EmailMailboxSmimeEncryptionAlgorithm
enum _WAEEmailMailboxSmimeEncryptionAlgorithm {
    WAEEmailMailboxSmimeEncryptionAlgorithmAny = 0,
    WAEEmailMailboxSmimeEncryptionAlgorithmTripleDes = 1,
    WAEEmailMailboxSmimeEncryptionAlgorithmDes = 2,
    WAEEmailMailboxSmimeEncryptionAlgorithmRC2128Bit = 3,
    WAEEmailMailboxSmimeEncryptionAlgorithmRC264Bit = 4,
    WAEEmailMailboxSmimeEncryptionAlgorithmRC240Bit = 5,
};
typedef unsigned WAEEmailMailboxSmimeEncryptionAlgorithm;

// Windows.ApplicationModel.Email.EmailMailboxSmimeSigningAlgorithm
enum _WAEEmailMailboxSmimeSigningAlgorithm {
    WAEEmailMailboxSmimeSigningAlgorithmAny = 0,
    WAEEmailMailboxSmimeSigningAlgorithmSha1 = 1,
    WAEEmailMailboxSmimeSigningAlgorithmMD5 = 2,
};
typedef unsigned WAEEmailMailboxSmimeSigningAlgorithm;

// Windows.ApplicationModel.Email.EmailMailboxAutoReplyMessageResponseKind
enum _WAEEmailMailboxAutoReplyMessageResponseKind {
    WAEEmailMailboxAutoReplyMessageResponseKindHtml = 0,
    WAEEmailMailboxAutoReplyMessageResponseKindPlainText = 1,
};
typedef unsigned WAEEmailMailboxAutoReplyMessageResponseKind;

// Windows.ApplicationModel.Email.EmailQuerySearchScope
enum _WAEEmailQuerySearchScope {
    WAEEmailQuerySearchScopeLocal = 0,
    WAEEmailQuerySearchScopeServer = 1,
};
typedef unsigned WAEEmailQuerySearchScope;

// Windows.ApplicationModel.Email.EmailRecipientResolutionStatus
enum _WAEEmailRecipientResolutionStatus {
    WAEEmailRecipientResolutionStatusSuccess = 0,
    WAEEmailRecipientResolutionStatusRecipientNotFound = 1,
    WAEEmailRecipientResolutionStatusAmbiguousRecipient = 2,
    WAEEmailRecipientResolutionStatusNoCertificate = 3,
    WAEEmailRecipientResolutionStatusCertificateRequestLimitReached = 4,
    WAEEmailRecipientResolutionStatusCannotResolveDistributionList = 5,
    WAEEmailRecipientResolutionStatusServerError = 6,
    WAEEmailRecipientResolutionStatusUnknownFailure = 7,
};
typedef unsigned WAEEmailRecipientResolutionStatus;

// Windows.ApplicationModel.Email.EmailMessageSmimeKind
enum _WAEEmailMessageSmimeKind {
    WAEEmailMessageSmimeKindNone = 0,
    WAEEmailMessageSmimeKindClearSigned = 1,
    WAEEmailMessageSmimeKindOpaqueSigned = 2,
    WAEEmailMessageSmimeKindEncrypted = 3,
};
typedef unsigned WAEEmailMessageSmimeKind;

// Windows.ApplicationModel.Email.EmailMailboxEmptyFolderStatus
enum _WAEEmailMailboxEmptyFolderStatus {
    WAEEmailMailboxEmptyFolderStatusSuccess = 0,
    WAEEmailMailboxEmptyFolderStatusNetworkError = 1,
    WAEEmailMailboxEmptyFolderStatusPermissionsError = 2,
    WAEEmailMailboxEmptyFolderStatusServerError = 3,
    WAEEmailMailboxEmptyFolderStatusUnknownFailure = 4,
    WAEEmailMailboxEmptyFolderStatusCouldNotDeleteEverything = 5,
};
typedef unsigned WAEEmailMailboxEmptyFolderStatus;

// Windows.ApplicationModel.Email.EmailMailboxCreateFolderStatus
enum _WAEEmailMailboxCreateFolderStatus {
    WAEEmailMailboxCreateFolderStatusSuccess = 0,
    WAEEmailMailboxCreateFolderStatusNetworkError = 1,
    WAEEmailMailboxCreateFolderStatusPermissionsError = 2,
    WAEEmailMailboxCreateFolderStatusServerError = 3,
    WAEEmailMailboxCreateFolderStatusUnknownFailure = 4,
    WAEEmailMailboxCreateFolderStatusNameCollision = 5,
    WAEEmailMailboxCreateFolderStatusServerRejected = 6,
};
typedef unsigned WAEEmailMailboxCreateFolderStatus;

// Windows.ApplicationModel.Email.EmailMailboxDeleteFolderStatus
enum _WAEEmailMailboxDeleteFolderStatus {
    WAEEmailMailboxDeleteFolderStatusSuccess = 0,
    WAEEmailMailboxDeleteFolderStatusNetworkError = 1,
    WAEEmailMailboxDeleteFolderStatusPermissionsError = 2,
    WAEEmailMailboxDeleteFolderStatusServerError = 3,
    WAEEmailMailboxDeleteFolderStatusUnknownFailure = 4,
    WAEEmailMailboxDeleteFolderStatusCouldNotDeleteEverything = 5,
};
typedef unsigned WAEEmailMailboxDeleteFolderStatus;

#include "WindowsApplicationModelAppointments.h"
#include "WindowsFoundation.h"
#include "WindowsSystem.h"
#include "WindowsStorageStreams.h"
#include "WindowsSecurityCryptographyCertificates.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.Email.EmailMessage
#ifndef __WAEEmailMessage_DEFINED__
#define __WAEEmailMessage_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAEEmailMessage : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * subject;
@property (retain) NSString * body;
@property (readonly) NSMutableArray* /* WAEEmailRecipient* */ bcc;
@property (readonly) NSMutableArray* /* WAEEmailRecipient* */ cC;
@property (readonly) NSMutableArray* /* WAEEmailAttachment* */ attachments;
@property (readonly) NSMutableArray* /* WAEEmailRecipient* */ to;
@property BOOL allowInternetImages;
@property WAEEmailFlagState flagState;
@property unsigned int estimatedDownloadSizeInBytes;
@property WAEEmailMessageDownloadState downloadState;
@property WAEEmailImportance importance;
@property (retain) WAEEmailIrmInfo* irmInfo;
@property int originalCodePage;
@property (retain) id /* WFDateTime* */ sentTime;
@property (retain) WAEEmailRecipient* sender;
@property (retain) NSString * remoteId;
@property (retain) NSString * preview;
@property (retain) NSString * messageClass;
@property (retain) WAEEmailMeetingInfo* meetingInfo;
@property WAEEmailMessageResponseKind lastResponseKind;
@property BOOL isSeen;
@property BOOL isRead;
@property (readonly) BOOL isServerSearchMessage;
@property (readonly) BOOL isSmartSendable;
@property (readonly) NSString * mailboxId;
@property (readonly) uint64_t changeNumber;
@property (readonly) NSString * conversationId;
@property (readonly) NSString * normalizedSubject;
@property (readonly) NSString * folderId;
@property (readonly) BOOL hasPartialBodies;
@property (readonly) NSString * id;
@property (readonly) NSString * inResponseToMessageId;
@property (readonly) BOOL isDraftMessage;
@property WAEEmailMessageSmimeKind smimeKind;
@property (retain) RTObject<WSSIRandomAccessStreamReference>* smimeData;
@property (retain) WAEEmailRecipient* sentRepresenting;
@property (readonly) NSMutableArray* /* WAEEmailRecipient* */ replyTo;
- (RTObject<WSSIRandomAccessStreamReference>*)getBodyStream:(WAEEmailMessageBodyKind)type;
- (void)setBodyStream:(WAEEmailMessageBodyKind)type stream:(RTObject<WSSIRandomAccessStreamReference>*)stream;
@end

#endif // __WAEEmailMessage_DEFINED__

// Windows.ApplicationModel.Email.EmailStore
#ifndef __WAEEmailStore_DEFINED__
#define __WAEEmailStore_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAEEmailStore : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)findMailboxesAsyncWithSuccess:(void (^)(NSArray* /* WAEEmailMailbox* */))success failure:(void (^)(NSError*))failure;
- (WAEEmailConversationReader*)getConversationReader;
- (WAEEmailConversationReader*)getConversationReaderWithOptions:(WAEEmailQueryOptions*)options;
- (WAEEmailMessageReader*)getMessageReader;
- (WAEEmailMessageReader*)getMessageReaderWithOptions:(WAEEmailQueryOptions*)options;
- (void)getMailboxAsync:(NSString *)id success:(void (^)(WAEEmailMailbox*))success failure:(void (^)(NSError*))failure;
- (void)getConversationAsync:(NSString *)id success:(void (^)(WAEEmailConversation*))success failure:(void (^)(NSError*))failure;
- (void)getFolderAsync:(NSString *)id success:(void (^)(WAEEmailFolder*))success failure:(void (^)(NSError*))failure;
- (void)getMessageAsync:(NSString *)id success:(void (^)(WAEEmailMessage*))success failure:(void (^)(NSError*))failure;
- (void)createMailboxAsync:(NSString *)accountName accountAddress:(NSString *)accountAddress success:(void (^)(WAEEmailMailbox*))success failure:(void (^)(NSError*))failure;
- (void)createMailboxInAccountAsync:(NSString *)accountName accountAddress:(NSString *)accountAddress userDataAccountId:(NSString *)userDataAccountId success:(void (^)(WAEEmailMailbox*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WAEEmailStore_DEFINED__

// Windows.ApplicationModel.Email.EmailManagerForUser
#ifndef __WAEEmailManagerForUser_DEFINED__
#define __WAEEmailManagerForUser_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAEEmailManagerForUser : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSUser* user;
- (RTObject<WFIAsyncAction>*)showComposeNewEmailAsync:(WAEEmailMessage*)message;
- (void)requestStoreAsync:(WAEEmailStoreAccessType)accessType success:(void (^)(WAEEmailStore*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WAEEmailManagerForUser_DEFINED__

// Windows.ApplicationModel.Email.EmailMailbox
#ifndef __WAEEmailMailbox_DEFINED__
#define __WAEEmailMailbox_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAEEmailMailbox : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WAEEmailMailboxOtherAppWriteAccess otherAppWriteAccess;
@property (retain) NSString * mailAddress;
@property WAEEmailMailboxOtherAppReadAccess otherAppReadAccess;
@property (retain) NSString * displayName;
@property (readonly) NSString * id;
@property (readonly) BOOL isDataEncryptedUnderLock;
@property (readonly) BOOL isOwnedByCurrentApp;
@property (readonly) NSMutableArray* /* NSString * */ mailAddressAliases;
@property (readonly) WAEEmailMailboxCapabilities* capabilities;
@property (readonly) WAEEmailMailboxChangeTracker* changeTracker;
@property (readonly) WAEEmailMailboxPolicies* policies;
@property (readonly) NSString * sourceDisplayName;
@property (readonly) WAEEmailMailboxSyncManager* syncManager;
@property (readonly) NSString * userDataAccountId;
@property (readonly) NSString * linkedMailboxId;
@property (readonly) NSString * networkAccountId;
@property (readonly) NSString * networkId;
- (EventRegistrationToken)addMailboxChangedEvent:(void(^)(WAEEmailMailbox*, WAEEmailMailboxChangedEventArgs*))del;
- (void)removeMailboxChangedEvent:(EventRegistrationToken)tok;
- (WAEEmailConversationReader*)getConversationReader;
- (WAEEmailConversationReader*)getConversationReaderWithOptions:(WAEEmailQueryOptions*)options;
- (WAEEmailMessageReader*)getMessageReader;
- (WAEEmailMessageReader*)getMessageReaderWithOptions:(WAEEmailQueryOptions*)options;
- (RTObject<WFIAsyncAction>*)deleteAsync;
- (void)getConversationAsync:(NSString *)id success:(void (^)(WAEEmailConversation*))success failure:(void (^)(NSError*))failure;
- (void)getFolderAsync:(NSString *)id success:(void (^)(WAEEmailFolder*))success failure:(void (^)(NSError*))failure;
- (void)getMessageAsync:(NSString *)id success:(void (^)(WAEEmailMessage*))success failure:(void (^)(NSError*))failure;
- (void)getSpecialFolderAsync:(WAEEmailSpecialFolderKind)folderType success:(void (^)(WAEEmailFolder*))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)saveAsync;
- (RTObject<WFIAsyncAction>*)markMessageAsSeenAsync:(NSString *)messageId;
- (RTObject<WFIAsyncAction>*)markFolderAsSeenAsync:(NSString *)folderId;
- (RTObject<WFIAsyncAction>*)markMessageReadAsync:(NSString *)messageId isRead:(BOOL)isRead;
- (RTObject<WFIAsyncAction>*)changeMessageFlagStateAsync:(NSString *)messageId flagState:(WAEEmailFlagState)flagState;
- (void)tryMoveMessageAsync:(NSString *)messageId newParentFolderId:(NSString *)newParentFolderId success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)tryMoveFolderAsync:(NSString *)folderId newParentFolderId:(NSString *)newParentFolderId success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)tryMoveFolderWithNewNameAsync:(NSString *)folderId newParentFolderId:(NSString *)newParentFolderId newFolderName:(NSString *)newFolderName success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)deleteMessageAsync:(NSString *)messageId;
- (RTObject<WFIAsyncAction>*)markFolderSyncEnabledAsync:(NSString *)folderId isSyncEnabled:(BOOL)isSyncEnabled;
- (RTObject<WFIAsyncAction>*)sendMessageAsync:(WAEEmailMessage*)message;
- (RTObject<WFIAsyncAction>*)saveDraftAsync:(WAEEmailMessage*)message;
- (RTObject<WFIAsyncAction>*)downloadMessageAsync:(NSString *)messageId;
- (RTObject<WFIAsyncAction>*)downloadAttachmentAsync:(NSString *)attachmentId;
- (void)createResponseMessageAsync:(NSString *)messageId responseType:(WAEEmailMessageResponseKind)responseType subject:(NSString *)subject responseHeaderType:(WAEEmailMessageBodyKind)responseHeaderType responseHeader:(NSString *)responseHeader success:(void (^)(WAEEmailMessage*))success failure:(void (^)(NSError*))failure;
- (void)tryUpdateMeetingResponseAsync:(WAEEmailMessage*)meeting response:(WAEEmailMeetingResponseType)response subject:(NSString *)subject comment:(NSString *)comment sendUpdate:(BOOL)sendUpdate success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)tryForwardMeetingAsync:(WAEEmailMessage*)meeting recipients:(id<NSFastEnumeration> /* WAEEmailRecipient* */)recipients subject:(NSString *)subject forwardHeaderType:(WAEEmailMessageBodyKind)forwardHeaderType forwardHeader:(NSString *)forwardHeader comment:(NSString *)comment success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)tryProposeNewTimeForMeetingAsync:(WAEEmailMessage*)meeting newStartTime:(WFDateTime*)newStartTime newDuration:(WFTimeSpan*)newDuration subject:(NSString *)subject comment:(NSString *)comment success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)smartSendMessageAsync:(WAEEmailMessage*)message smartSend:(BOOL)smartSend;
- (void)trySetAutoReplySettingsAsync:(WAEEmailMailboxAutoReplySettings*)autoReplySettings success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)tryGetAutoReplySettingsAsync:(WAEEmailMailboxAutoReplyMessageResponseKind)requestedFormat success:(void (^)(WAEEmailMailboxAutoReplySettings*))success failure:(void (^)(NSError*))failure;
- (void)resolveRecipientsAsync:(id<NSFastEnumeration> /* NSString * */)recipients success:(void (^)(NSArray* /* WAEEmailRecipientResolutionResult* */))success failure:(void (^)(NSError*))failure;
- (void)validateCertificatesAsync:(id<NSFastEnumeration> /* WSCCCertificate* */)certificates success:(void (^)(NSArray* /* WAEEmailCertificateValidationStatus */))success failure:(void (^)(NSError*))failure;
- (void)tryEmptyFolderAsync:(NSString *)folderId success:(void (^)(WAEEmailMailboxEmptyFolderStatus))success failure:(void (^)(NSError*))failure;
- (void)tryCreateFolderAsync:(NSString *)parentFolderId name:(NSString *)name success:(void (^)(WAEEmailMailboxCreateFolderResult*))success failure:(void (^)(NSError*))failure;
- (void)tryDeleteFolderAsync:(NSString *)folderId success:(void (^)(WAEEmailMailboxDeleteFolderStatus))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)registerSyncManagerAsync;
- (WAEEmailMailboxChangeTracker*)getChangeTracker:(NSString *)identity;
@end

#endif // __WAEEmailMailbox_DEFINED__

// Windows.ApplicationModel.Email.EmailConversationReader
#ifndef __WAEEmailConversationReader_DEFINED__
#define __WAEEmailConversationReader_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAEEmailConversationReader : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)readBatchAsyncWithSuccess:(void (^)(WAEEmailConversationBatch*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WAEEmailConversationReader_DEFINED__

// Windows.ApplicationModel.Email.EmailQueryOptions
#ifndef __WAEEmailQueryOptions_DEFINED__
#define __WAEEmailQueryOptions_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAEEmailQueryOptions : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
+ (WAEEmailQueryOptions*)makeWithText:(NSString *)text ACTIVATOR;
+ (WAEEmailQueryOptions*)makeWithTextAndFields:(NSString *)text fields:(WAEEmailQuerySearchFields)fields ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WAEEmailQuerySortProperty sortProperty;
@property WAEEmailQuerySortDirection sortDirection;
@property WAEEmailQueryKind kind;
@property (readonly) NSMutableArray* /* NSString * */ folderIds;
@property (readonly) WAEEmailQueryTextSearch* textSearch;
@end

#endif // __WAEEmailQueryOptions_DEFINED__

// Windows.ApplicationModel.Email.EmailMessageReader
#ifndef __WAEEmailMessageReader_DEFINED__
#define __WAEEmailMessageReader_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAEEmailMessageReader : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)readBatchAsyncWithSuccess:(void (^)(WAEEmailMessageBatch*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WAEEmailMessageReader_DEFINED__

// Windows.ApplicationModel.Email.EmailConversation
#ifndef __WAEEmailConversation_DEFINED__
#define __WAEEmailConversation_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAEEmailConversation : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAEEmailFlagState flagState;
@property (readonly) BOOL hasAttachment;
@property (readonly) NSString * id;
@property (readonly) WAEEmailImportance importance;
@property (readonly) WAEEmailMessageResponseKind lastEmailResponseKind;
@property (readonly) WAEEmailRecipient* latestSender;
@property (readonly) NSString * mailboxId;
@property (readonly) unsigned int messageCount;
@property (readonly) NSString * mostRecentMessageId;
@property (readonly) WFDateTime* mostRecentMessageTime;
@property (readonly) NSString * preview;
@property (readonly) NSString * subject;
@property (readonly) unsigned int unreadMessageCount;
- (void)findMessagesAsyncWithSuccess:(void (^)(NSArray* /* WAEEmailMessage* */))success failure:(void (^)(NSError*))failure;
- (void)findMessagesWithCountAsync:(unsigned int)count success:(void (^)(NSArray* /* WAEEmailMessage* */))success failure:(void (^)(NSError*))failure;
@end

#endif // __WAEEmailConversation_DEFINED__

// Windows.ApplicationModel.Email.EmailFolder
#ifndef __WAEEmailFolder_DEFINED__
#define __WAEEmailFolder_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAEEmailFolder : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * remoteId;
@property (retain) WFDateTime* lastSuccessfulSyncTime;
@property BOOL isSyncEnabled;
@property (retain) NSString * displayName;
@property (readonly) NSString * id;
@property (readonly) WAEEmailSpecialFolderKind kind;
@property (readonly) NSString * mailboxId;
@property (readonly) NSString * parentFolderId;
- (void)createFolderAsync:(NSString *)name success:(void (^)(WAEEmailFolder*))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)deleteAsync;
- (void)findChildFoldersAsyncWithSuccess:(void (^)(NSArray* /* WAEEmailFolder* */))success failure:(void (^)(NSError*))failure;
- (WAEEmailConversationReader*)getConversationReader;
- (WAEEmailConversationReader*)getConversationReaderWithOptions:(WAEEmailQueryOptions*)options;
- (void)getMessageAsync:(NSString *)id success:(void (^)(WAEEmailMessage*))success failure:(void (^)(NSError*))failure;
- (WAEEmailMessageReader*)getMessageReader;
- (WAEEmailMessageReader*)getMessageReaderWithOptions:(WAEEmailQueryOptions*)options;
- (void)getMessageCountsAsyncWithSuccess:(void (^)(WAEEmailItemCounts*))success failure:(void (^)(NSError*))failure;
- (void)tryMoveAsync:(WAEEmailFolder*)newParentFolder success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)tryMoveWithNewNameAsync:(WAEEmailFolder*)newParentFolder newFolderName:(NSString *)newFolderName success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)trySaveAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)saveMessageAsync:(WAEEmailMessage*)message;
@end

#endif // __WAEEmailFolder_DEFINED__

// Windows.ApplicationModel.Email.EmailRecipient
#ifndef __WAEEmailRecipient_DEFINED__
#define __WAEEmailRecipient_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAEEmailRecipient : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
+ (WAEEmailRecipient*)make:(NSString *)address ACTIVATOR;
+ (WAEEmailRecipient*)makeWithName:(NSString *)address name:(NSString *)name ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * name;
@property (retain) NSString * address;
@end

#endif // __WAEEmailRecipient_DEFINED__

// Windows.ApplicationModel.Email.EmailIrmTemplate
#ifndef __WAEEmailIrmTemplate_DEFINED__
#define __WAEEmailIrmTemplate_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAEEmailIrmTemplate : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
+ (WAEEmailIrmTemplate*)make:(NSString *)id name:(NSString *)name description:(NSString *)description ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * name;
@property (retain) NSString * id;
@property (retain) NSString * Description;
@end

#endif // __WAEEmailIrmTemplate_DEFINED__

// Windows.ApplicationModel.Email.EmailIrmInfo
#ifndef __WAEEmailIrmInfo_DEFINED__
#define __WAEEmailIrmInfo_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAEEmailIrmInfo : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
+ (WAEEmailIrmInfo*)make:(WFDateTime*)expiration irmTemplate:(WAEEmailIrmTemplate*)irmTemplate ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL canRemoveIrmOnResponse;
@property BOOL canPrintData;
@property BOOL canModifyRecipientsOnResponse;
@property BOOL canForward;
@property BOOL canExtractData;
@property BOOL canReply;
@property BOOL canEdit;
@property (retain) WAEEmailIrmTemplate* Template;
@property BOOL isProgramaticAccessAllowed;
@property BOOL isIrmOriginator;
@property (retain) WFDateTime* expirationDate;
@property BOOL canReplyAll;
@end

#endif // __WAEEmailIrmInfo_DEFINED__

// Windows.ApplicationModel.Email.EmailAttachment
#ifndef __WAEEmailAttachment_DEFINED__
#define __WAEEmailAttachment_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAEEmailAttachment : RTObject
+ (WAEEmailAttachment*)make:(NSString *)fileName data:(RTObject<WSSIRandomAccessStreamReference>*)data ACTIVATOR;
+ (WAEEmailAttachment*)make:(NSString *)fileName data:(RTObject<WSSIRandomAccessStreamReference>*)data mimeType:(NSString *)mimeType ACTIVATOR;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * fileName;
@property (retain) RTObject<WSSIRandomAccessStreamReference>* data;
@property (retain) NSString * mimeType;
@property BOOL isInline;
@property uint64_t estimatedDownloadSizeInBytes;
@property WAEEmailAttachmentDownloadState downloadState;
@property (retain) NSString * contentLocation;
@property (retain) NSString * contentId;
@property (readonly) NSString * id;
@property (readonly) BOOL isFromBaseMessage;
@end

#endif // __WAEEmailAttachment_DEFINED__

// Windows.ApplicationModel.Email.EmailMeetingInfo
#ifndef __WAEEmailMeetingInfo_DEFINED__
#define __WAEEmailMeetingInfo_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAEEmailMeetingInfo : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * location;
@property BOOL isResponseRequested;
@property BOOL isAllDay;
@property BOOL allowNewTimeProposal;
@property (retain) WFTimeSpan* duration;
@property (retain) NSString * appointmentRoamingId;
@property (retain) id /* WFDateTime* */ appointmentOriginalStartTime;
@property (retain) id /* WFTimeSpan* */ proposedDuration;
@property uint64_t remoteChangeNumber;
@property (retain) WFDateTime* startTime;
@property (retain) id /* WFDateTime* */ recurrenceStartTime;
@property (retain) WAAAppointmentRecurrence* recurrence;
@property (retain) id /* WFDateTime* */ proposedStartTime;
@property (readonly) BOOL isReportedOutOfDateByServer;
@end

#endif // __WAEEmailMeetingInfo_DEFINED__

// Windows.ApplicationModel.Email.EmailMailboxChangedDeferral
#ifndef __WAEEmailMailboxChangedDeferral_DEFINED__
#define __WAEEmailMailboxChangedDeferral_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAEEmailMailboxChangedDeferral : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)complete;
@end

#endif // __WAEEmailMailboxChangedDeferral_DEFINED__

// Windows.ApplicationModel.Email.EmailMailboxCapabilities
#ifndef __WAEEmailMailboxCapabilities_DEFINED__
#define __WAEEmailMailboxCapabilities_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAEEmailMailboxCapabilities : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL canSmartSend;
@property BOOL canUpdateMeetingResponses;
@property BOOL canServerSearchMailbox;
@property BOOL canServerSearchFolders;
@property BOOL canForwardMeetings;
@property BOOL canProposeNewTimeForMeetings;
@property BOOL canGetAndSetInternalAutoReplies;
@property BOOL canGetAndSetExternalAutoReplies;
@property BOOL canValidateCertificates;
@property BOOL canResolveRecipients;
@property BOOL canMoveFolder;
@property BOOL canEmptyFolder;
@property BOOL canDeleteFolder;
@property BOOL canCreateFolder;
@end

#endif // __WAEEmailMailboxCapabilities_DEFINED__

// Windows.ApplicationModel.Email.EmailMailboxChangeTracker
#ifndef __WAEEmailMailboxChangeTracker_DEFINED__
#define __WAEEmailMailboxChangeTracker_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAEEmailMailboxChangeTracker : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isTracking;
- (void)enable;
- (WAEEmailMailboxChangeReader*)getChangeReader;
- (void)reset;
@end

#endif // __WAEEmailMailboxChangeTracker_DEFINED__

// Windows.ApplicationModel.Email.EmailMailboxPolicies
#ifndef __WAEEmailMailboxPolicies_DEFINED__
#define __WAEEmailMailboxPolicies_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAEEmailMailboxPolicies : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) id /* WAEEmailMailboxSmimeSigningAlgorithm */ requiredSmimeSigningAlgorithm;
@property (retain) id /* WAEEmailMailboxSmimeEncryptionAlgorithm */ requiredSmimeEncryptionAlgorithm;
@property WAEEmailMailboxAllowedSmimeEncryptionAlgorithmNegotiation allowedSmimeEncryptionAlgorithmNegotiation;
@property BOOL allowSmimeSoftCertificates;
@property BOOL mustSignSmimeMessages;
@property BOOL mustEncryptSmimeMessages;
@end

#endif // __WAEEmailMailboxPolicies_DEFINED__

// Windows.ApplicationModel.Email.EmailMailboxSyncManager
#ifndef __WAEEmailMailboxSyncManager_DEFINED__
#define __WAEEmailMailboxSyncManager_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAEEmailMailboxSyncManager : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WAEEmailMailboxSyncStatus status;
@property (retain) WFDateTime* lastSuccessfulSyncTime;
@property (retain) WFDateTime* lastAttemptedSyncTime;
- (EventRegistrationToken)addSyncStatusChangedEvent:(void(^)(WAEEmailMailboxSyncManager*, RTObject*))del;
- (void)removeSyncStatusChangedEvent:(EventRegistrationToken)tok;
- (void)syncAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WAEEmailMailboxSyncManager_DEFINED__

// Windows.ApplicationModel.Email.EmailMailboxChangedEventArgs
#ifndef __WAEEmailMailboxChangedEventArgs_DEFINED__
#define __WAEEmailMailboxChangedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAEEmailMailboxChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (WAEEmailMailboxChangedDeferral*)getDeferral;
@end

#endif // __WAEEmailMailboxChangedEventArgs_DEFINED__

// Windows.ApplicationModel.Email.EmailMailboxAutoReplySettings
#ifndef __WAEEmailMailboxAutoReplySettings_DEFINED__
#define __WAEEmailMailboxAutoReplySettings_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAEEmailMailboxAutoReplySettings : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) id /* WFDateTime* */ startTime;
@property WAEEmailMailboxAutoReplyMessageResponseKind responseKind;
@property BOOL isEnabled;
@property (retain) id /* WFDateTime* */ endTime;
@property (readonly) WAEEmailMailboxAutoReply* internalReply;
@property (readonly) WAEEmailMailboxAutoReply* knownExternalReply;
@property (readonly) WAEEmailMailboxAutoReply* unknownExternalReply;
@end

#endif // __WAEEmailMailboxAutoReplySettings_DEFINED__

// Windows.ApplicationModel.Email.EmailRecipientResolutionResult
#ifndef __WAEEmailRecipientResolutionResult_DEFINED__
#define __WAEEmailRecipientResolutionResult_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAEEmailRecipientResolutionResult : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WAEEmailRecipientResolutionStatus status;
@property (readonly) NSArray* /* WSCCCertificate* */ publicKeys;
- (void)setPublicKeys:(id<NSFastEnumeration> /* WSCCCertificate* */)value;
@end

#endif // __WAEEmailRecipientResolutionResult_DEFINED__

// Windows.ApplicationModel.Email.EmailMailboxCreateFolderResult
#ifndef __WAEEmailMailboxCreateFolderResult_DEFINED__
#define __WAEEmailMailboxCreateFolderResult_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAEEmailMailboxCreateFolderResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAEEmailFolder* folder;
@property (readonly) WAEEmailMailboxCreateFolderStatus status;
@end

#endif // __WAEEmailMailboxCreateFolderResult_DEFINED__

// Windows.ApplicationModel.Email.EmailMailboxAutoReply
#ifndef __WAEEmailMailboxAutoReply_DEFINED__
#define __WAEEmailMailboxAutoReply_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAEEmailMailboxAutoReply : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * response;
@property BOOL isEnabled;
@end

#endif // __WAEEmailMailboxAutoReply_DEFINED__

// Windows.ApplicationModel.Email.EmailItemCounts
#ifndef __WAEEmailItemCounts_DEFINED__
#define __WAEEmailItemCounts_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAEEmailItemCounts : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int flagged;
@property (readonly) unsigned int important;
@property (readonly) unsigned int total;
@property (readonly) unsigned int unread;
@end

#endif // __WAEEmailItemCounts_DEFINED__

// Windows.ApplicationModel.Email.EmailQueryTextSearch
#ifndef __WAEEmailQueryTextSearch_DEFINED__
#define __WAEEmailQueryTextSearch_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAEEmailQueryTextSearch : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * text;
@property WAEEmailQuerySearchScope searchScope;
@property WAEEmailQuerySearchFields fields;
@end

#endif // __WAEEmailQueryTextSearch_DEFINED__

// Windows.ApplicationModel.Email.EmailConversationBatch
#ifndef __WAEEmailConversationBatch_DEFINED__
#define __WAEEmailConversationBatch_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAEEmailConversationBatch : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WAEEmailConversation* */ conversations;
@property (readonly) WAEEmailBatchStatus status;
@end

#endif // __WAEEmailConversationBatch_DEFINED__

// Windows.ApplicationModel.Email.EmailMessageBatch
#ifndef __WAEEmailMessageBatch_DEFINED__
#define __WAEEmailMessageBatch_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAEEmailMessageBatch : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WAEEmailMessage* */ messages;
@property (readonly) WAEEmailBatchStatus status;
@end

#endif // __WAEEmailMessageBatch_DEFINED__

// Windows.ApplicationModel.Email.EmailMailboxAction
#ifndef __WAEEmailMailboxAction_DEFINED__
#define __WAEEmailMailboxAction_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAEEmailMailboxAction : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) uint64_t changeNumber;
@property (readonly) WAEEmailMailboxActionKind kind;
@end

#endif // __WAEEmailMailboxAction_DEFINED__

// Windows.ApplicationModel.Email.EmailMailboxChange
#ifndef __WAEEmailMailboxChange_DEFINED__
#define __WAEEmailMailboxChange_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAEEmailMailboxChange : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAEEmailMailboxChangeType changeType;
@property (readonly) WAEEmailFolder* folder;
@property (readonly) NSMutableArray* /* WAEEmailMailboxAction* */ mailboxActions;
@property (readonly) WAEEmailMessage* message;
@end

#endif // __WAEEmailMailboxChange_DEFINED__

// Windows.ApplicationModel.Email.EmailMailboxChangeReader
#ifndef __WAEEmailMailboxChangeReader_DEFINED__
#define __WAEEmailMailboxChangeReader_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAEEmailMailboxChangeReader : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)acceptChanges;
- (void)acceptChangesThrough:(WAEEmailMailboxChange*)lastChangeToAcknowledge;
- (void)readBatchAsyncWithSuccess:(void (^)(NSArray* /* WAEEmailMailboxChange* */))success failure:(void (^)(NSError*))failure;
@end

#endif // __WAEEmailMailboxChangeReader_DEFINED__

// Windows.ApplicationModel.Email.EmailManager
#ifndef __WAEEmailManager_DEFINED__
#define __WAEEmailManager_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAEEmailManager : RTObject
+ (WAEEmailManagerForUser*)getForUser:(WSUser*)user;
+ (void)requestStoreAsync:(WAEEmailStoreAccessType)accessType success:(void (^)(WAEEmailStore*))success failure:(void (^)(NSError*))failure;
+ (RTObject<WFIAsyncAction>*)showComposeNewEmailAsync:(WAEEmailMessage*)message;
@end

#endif // __WAEEmailManager_DEFINED__

// Windows.ApplicationModel.Email.EmailStoreNotificationTriggerDetails
#ifndef __WAEEmailStoreNotificationTriggerDetails_DEFINED__
#define __WAEEmailStoreNotificationTriggerDetails_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAEEmailStoreNotificationTriggerDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WAEEmailStoreNotificationTriggerDetails_DEFINED__

