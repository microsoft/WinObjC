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

// WindowsApplicationModelEmailDataProvider.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSAPPLICATIONMODELEMAILDATAPROVIDEREXPORT
#define OBJCUWPWINDOWSAPPLICATIONMODELEMAILDATAPROVIDEREXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsApplicationModelEmailDataProvider.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WAEDEmailDataProviderConnection, WAEDEmailMailboxSyncManagerSyncRequestEventArgs, WAEDEmailMailboxDownloadMessageRequestEventArgs, WAEDEmailMailboxDownloadAttachmentRequestEventArgs, WAEDEmailMailboxCreateFolderRequestEventArgs, WAEDEmailMailboxDeleteFolderRequestEventArgs, WAEDEmailMailboxEmptyFolderRequestEventArgs, WAEDEmailMailboxMoveFolderRequestEventArgs, WAEDEmailMailboxUpdateMeetingResponseRequestEventArgs, WAEDEmailMailboxForwardMeetingRequestEventArgs, WAEDEmailMailboxProposeNewTimeForMeetingRequestEventArgs, WAEDEmailMailboxSetAutoReplySettingsRequestEventArgs, WAEDEmailMailboxGetAutoReplySettingsRequestEventArgs, WAEDEmailMailboxResolveRecipientsRequestEventArgs, WAEDEmailMailboxValidateCertificatesRequestEventArgs, WAEDEmailMailboxServerSearchReadBatchRequestEventArgs, WAEDEmailDataProviderTriggerDetails, WAEDEmailMailboxSyncManagerSyncRequest, WAEDEmailMailboxDownloadMessageRequest, WAEDEmailMailboxDownloadAttachmentRequest, WAEDEmailMailboxCreateFolderRequest, WAEDEmailMailboxDeleteFolderRequest, WAEDEmailMailboxEmptyFolderRequest, WAEDEmailMailboxMoveFolderRequest, WAEDEmailMailboxUpdateMeetingResponseRequest, WAEDEmailMailboxForwardMeetingRequest, WAEDEmailMailboxProposeNewTimeForMeetingRequest, WAEDEmailMailboxSetAutoReplySettingsRequest, WAEDEmailMailboxGetAutoReplySettingsRequest, WAEDEmailMailboxResolveRecipientsRequest, WAEDEmailMailboxValidateCertificatesRequest, WAEDEmailMailboxServerSearchReadBatchRequest;
@protocol WAEDIEmailDataProviderTriggerDetails, WAEDIEmailDataProviderConnection, WAEDIEmailMailboxSyncManagerSyncRequest, WAEDIEmailMailboxDownloadMessageRequest, WAEDIEmailMailboxDownloadAttachmentRequest, WAEDIEmailMailboxCreateFolderRequest, WAEDIEmailMailboxDeleteFolderRequest, WAEDIEmailMailboxEmptyFolderRequest, WAEDIEmailMailboxMoveFolderRequest, WAEDIEmailMailboxUpdateMeetingResponseRequest, WAEDIEmailMailboxForwardMeetingRequest, WAEDIEmailMailboxProposeNewTimeForMeetingRequest, WAEDIEmailMailboxSetAutoReplySettingsRequest, WAEDIEmailMailboxGetAutoReplySettingsRequest, WAEDIEmailMailboxResolveRecipientsRequest, WAEDIEmailMailboxValidateCertificatesRequest, WAEDIEmailMailboxServerSearchReadBatchRequest, WAEDIEmailMailboxSyncManagerSyncRequestEventArgs, WAEDIEmailMailboxDownloadMessageRequestEventArgs, WAEDIEmailMailboxDownloadAttachmentRequestEventArgs, WAEDIEmailMailboxCreateFolderRequestEventArgs, WAEDIEmailMailboxDeleteFolderRequestEventArgs, WAEDIEmailMailboxEmptyFolderRequestEventArgs, WAEDIEmailMailboxMoveFolderRequestEventArgs, WAEDIEmailMailboxUpdateMeetingResponseRequestEventArgs, WAEDIEmailMailboxForwardMeetingRequestEventArgs, WAEDIEmailMailboxProposeNewTimeForMeetingRequestEventArgs, WAEDIEmailMailboxSetAutoReplySettingsRequestEventArgs, WAEDIEmailMailboxGetAutoReplySettingsRequestEventArgs, WAEDIEmailMailboxResolveRecipientsRequestEventArgs, WAEDIEmailMailboxValidateCertificatesRequestEventArgs, WAEDIEmailMailboxServerSearchReadBatchRequestEventArgs;

#include "WindowsFoundation.h"
#include "WindowsApplicationModelEmail.h"
#include "WindowsSecurityCryptographyCertificates.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.Email.DataProvider.EmailDataProviderConnection
#ifndef __WAEDEmailDataProviderConnection_DEFINED__
#define __WAEDEmailDataProviderConnection_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELEMAILDATAPROVIDEREXPORT
@interface WAEDEmailDataProviderConnection : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (EventRegistrationToken)addCreateFolderRequestedEvent:(void(^)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxCreateFolderRequestEventArgs*))del;
- (void)removeCreateFolderRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDeleteFolderRequestedEvent:(void(^)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxDeleteFolderRequestEventArgs*))del;
- (void)removeDeleteFolderRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDownloadAttachmentRequestedEvent:(void(^)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxDownloadAttachmentRequestEventArgs*))del;
- (void)removeDownloadAttachmentRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDownloadMessageRequestedEvent:(void(^)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxDownloadMessageRequestEventArgs*))del;
- (void)removeDownloadMessageRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addEmptyFolderRequestedEvent:(void(^)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxEmptyFolderRequestEventArgs*))del;
- (void)removeEmptyFolderRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addForwardMeetingRequestedEvent:(void(^)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxForwardMeetingRequestEventArgs*))del;
- (void)removeForwardMeetingRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addGetAutoReplySettingsRequestedEvent:(void(^)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxGetAutoReplySettingsRequestEventArgs*))del;
- (void)removeGetAutoReplySettingsRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addMailboxSyncRequestedEvent:(void(^)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxSyncManagerSyncRequestEventArgs*))del;
- (void)removeMailboxSyncRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addMoveFolderRequestedEvent:(void(^)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxMoveFolderRequestEventArgs*))del;
- (void)removeMoveFolderRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addProposeNewTimeForMeetingRequestedEvent:(void(^)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxProposeNewTimeForMeetingRequestEventArgs*))del;
- (void)removeProposeNewTimeForMeetingRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addResolveRecipientsRequestedEvent:(void(^)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxResolveRecipientsRequestEventArgs*))del;
- (void)removeResolveRecipientsRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addServerSearchReadBatchRequestedEvent:(void(^)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxServerSearchReadBatchRequestEventArgs*))del;
- (void)removeServerSearchReadBatchRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSetAutoReplySettingsRequestedEvent:(void(^)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxSetAutoReplySettingsRequestEventArgs*))del;
- (void)removeSetAutoReplySettingsRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUpdateMeetingResponseRequestedEvent:(void(^)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxUpdateMeetingResponseRequestEventArgs*))del;
- (void)removeUpdateMeetingResponseRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addValidateCertificatesRequestedEvent:(void(^)(WAEDEmailDataProviderConnection*, WAEDEmailMailboxValidateCertificatesRequestEventArgs*))del;
- (void)removeValidateCertificatesRequestedEvent:(EventRegistrationToken)tok;
- (void)start;
@end

#endif // __WAEDEmailDataProviderConnection_DEFINED__

// Windows.ApplicationModel.Email.DataProvider.EmailMailboxSyncManagerSyncRequestEventArgs
#ifndef __WAEDEmailMailboxSyncManagerSyncRequestEventArgs_DEFINED__
#define __WAEDEmailMailboxSyncManagerSyncRequestEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELEMAILDATAPROVIDEREXPORT
@interface WAEDEmailMailboxSyncManagerSyncRequestEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAEDEmailMailboxSyncManagerSyncRequest* request;
- (WFDeferral*)getDeferral;
@end

#endif // __WAEDEmailMailboxSyncManagerSyncRequestEventArgs_DEFINED__

// Windows.ApplicationModel.Email.DataProvider.EmailMailboxDownloadMessageRequestEventArgs
#ifndef __WAEDEmailMailboxDownloadMessageRequestEventArgs_DEFINED__
#define __WAEDEmailMailboxDownloadMessageRequestEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELEMAILDATAPROVIDEREXPORT
@interface WAEDEmailMailboxDownloadMessageRequestEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAEDEmailMailboxDownloadMessageRequest* request;
- (WFDeferral*)getDeferral;
@end

#endif // __WAEDEmailMailboxDownloadMessageRequestEventArgs_DEFINED__

// Windows.ApplicationModel.Email.DataProvider.EmailMailboxDownloadAttachmentRequestEventArgs
#ifndef __WAEDEmailMailboxDownloadAttachmentRequestEventArgs_DEFINED__
#define __WAEDEmailMailboxDownloadAttachmentRequestEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELEMAILDATAPROVIDEREXPORT
@interface WAEDEmailMailboxDownloadAttachmentRequestEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAEDEmailMailboxDownloadAttachmentRequest* request;
- (WFDeferral*)getDeferral;
@end

#endif // __WAEDEmailMailboxDownloadAttachmentRequestEventArgs_DEFINED__

// Windows.ApplicationModel.Email.DataProvider.EmailMailboxCreateFolderRequestEventArgs
#ifndef __WAEDEmailMailboxCreateFolderRequestEventArgs_DEFINED__
#define __WAEDEmailMailboxCreateFolderRequestEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELEMAILDATAPROVIDEREXPORT
@interface WAEDEmailMailboxCreateFolderRequestEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAEDEmailMailboxCreateFolderRequest* request;
- (WFDeferral*)getDeferral;
@end

#endif // __WAEDEmailMailboxCreateFolderRequestEventArgs_DEFINED__

// Windows.ApplicationModel.Email.DataProvider.EmailMailboxDeleteFolderRequestEventArgs
#ifndef __WAEDEmailMailboxDeleteFolderRequestEventArgs_DEFINED__
#define __WAEDEmailMailboxDeleteFolderRequestEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELEMAILDATAPROVIDEREXPORT
@interface WAEDEmailMailboxDeleteFolderRequestEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAEDEmailMailboxDeleteFolderRequest* request;
- (WFDeferral*)getDeferral;
@end

#endif // __WAEDEmailMailboxDeleteFolderRequestEventArgs_DEFINED__

// Windows.ApplicationModel.Email.DataProvider.EmailMailboxEmptyFolderRequestEventArgs
#ifndef __WAEDEmailMailboxEmptyFolderRequestEventArgs_DEFINED__
#define __WAEDEmailMailboxEmptyFolderRequestEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELEMAILDATAPROVIDEREXPORT
@interface WAEDEmailMailboxEmptyFolderRequestEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAEDEmailMailboxEmptyFolderRequest* request;
- (WFDeferral*)getDeferral;
@end

#endif // __WAEDEmailMailboxEmptyFolderRequestEventArgs_DEFINED__

// Windows.ApplicationModel.Email.DataProvider.EmailMailboxMoveFolderRequestEventArgs
#ifndef __WAEDEmailMailboxMoveFolderRequestEventArgs_DEFINED__
#define __WAEDEmailMailboxMoveFolderRequestEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELEMAILDATAPROVIDEREXPORT
@interface WAEDEmailMailboxMoveFolderRequestEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAEDEmailMailboxMoveFolderRequest* request;
- (WFDeferral*)getDeferral;
@end

#endif // __WAEDEmailMailboxMoveFolderRequestEventArgs_DEFINED__

// Windows.ApplicationModel.Email.DataProvider.EmailMailboxUpdateMeetingResponseRequestEventArgs
#ifndef __WAEDEmailMailboxUpdateMeetingResponseRequestEventArgs_DEFINED__
#define __WAEDEmailMailboxUpdateMeetingResponseRequestEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELEMAILDATAPROVIDEREXPORT
@interface WAEDEmailMailboxUpdateMeetingResponseRequestEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAEDEmailMailboxUpdateMeetingResponseRequest* request;
- (WFDeferral*)getDeferral;
@end

#endif // __WAEDEmailMailboxUpdateMeetingResponseRequestEventArgs_DEFINED__

// Windows.ApplicationModel.Email.DataProvider.EmailMailboxForwardMeetingRequestEventArgs
#ifndef __WAEDEmailMailboxForwardMeetingRequestEventArgs_DEFINED__
#define __WAEDEmailMailboxForwardMeetingRequestEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELEMAILDATAPROVIDEREXPORT
@interface WAEDEmailMailboxForwardMeetingRequestEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAEDEmailMailboxForwardMeetingRequest* request;
- (WFDeferral*)getDeferral;
@end

#endif // __WAEDEmailMailboxForwardMeetingRequestEventArgs_DEFINED__

// Windows.ApplicationModel.Email.DataProvider.EmailMailboxProposeNewTimeForMeetingRequestEventArgs
#ifndef __WAEDEmailMailboxProposeNewTimeForMeetingRequestEventArgs_DEFINED__
#define __WAEDEmailMailboxProposeNewTimeForMeetingRequestEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELEMAILDATAPROVIDEREXPORT
@interface WAEDEmailMailboxProposeNewTimeForMeetingRequestEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAEDEmailMailboxProposeNewTimeForMeetingRequest* request;
- (WFDeferral*)getDeferral;
@end

#endif // __WAEDEmailMailboxProposeNewTimeForMeetingRequestEventArgs_DEFINED__

// Windows.ApplicationModel.Email.DataProvider.EmailMailboxSetAutoReplySettingsRequestEventArgs
#ifndef __WAEDEmailMailboxSetAutoReplySettingsRequestEventArgs_DEFINED__
#define __WAEDEmailMailboxSetAutoReplySettingsRequestEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELEMAILDATAPROVIDEREXPORT
@interface WAEDEmailMailboxSetAutoReplySettingsRequestEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAEDEmailMailboxSetAutoReplySettingsRequest* request;
- (WFDeferral*)getDeferral;
@end

#endif // __WAEDEmailMailboxSetAutoReplySettingsRequestEventArgs_DEFINED__

// Windows.ApplicationModel.Email.DataProvider.EmailMailboxGetAutoReplySettingsRequestEventArgs
#ifndef __WAEDEmailMailboxGetAutoReplySettingsRequestEventArgs_DEFINED__
#define __WAEDEmailMailboxGetAutoReplySettingsRequestEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELEMAILDATAPROVIDEREXPORT
@interface WAEDEmailMailboxGetAutoReplySettingsRequestEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAEDEmailMailboxGetAutoReplySettingsRequest* request;
- (WFDeferral*)getDeferral;
@end

#endif // __WAEDEmailMailboxGetAutoReplySettingsRequestEventArgs_DEFINED__

// Windows.ApplicationModel.Email.DataProvider.EmailMailboxResolveRecipientsRequestEventArgs
#ifndef __WAEDEmailMailboxResolveRecipientsRequestEventArgs_DEFINED__
#define __WAEDEmailMailboxResolveRecipientsRequestEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELEMAILDATAPROVIDEREXPORT
@interface WAEDEmailMailboxResolveRecipientsRequestEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAEDEmailMailboxResolveRecipientsRequest* request;
- (WFDeferral*)getDeferral;
@end

#endif // __WAEDEmailMailboxResolveRecipientsRequestEventArgs_DEFINED__

// Windows.ApplicationModel.Email.DataProvider.EmailMailboxValidateCertificatesRequestEventArgs
#ifndef __WAEDEmailMailboxValidateCertificatesRequestEventArgs_DEFINED__
#define __WAEDEmailMailboxValidateCertificatesRequestEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELEMAILDATAPROVIDEREXPORT
@interface WAEDEmailMailboxValidateCertificatesRequestEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAEDEmailMailboxValidateCertificatesRequest* request;
- (WFDeferral*)getDeferral;
@end

#endif // __WAEDEmailMailboxValidateCertificatesRequestEventArgs_DEFINED__

// Windows.ApplicationModel.Email.DataProvider.EmailMailboxServerSearchReadBatchRequestEventArgs
#ifndef __WAEDEmailMailboxServerSearchReadBatchRequestEventArgs_DEFINED__
#define __WAEDEmailMailboxServerSearchReadBatchRequestEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELEMAILDATAPROVIDEREXPORT
@interface WAEDEmailMailboxServerSearchReadBatchRequestEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAEDEmailMailboxServerSearchReadBatchRequest* request;
- (WFDeferral*)getDeferral;
@end

#endif // __WAEDEmailMailboxServerSearchReadBatchRequestEventArgs_DEFINED__

// Windows.ApplicationModel.Email.DataProvider.EmailDataProviderTriggerDetails
#ifndef __WAEDEmailDataProviderTriggerDetails_DEFINED__
#define __WAEDEmailDataProviderTriggerDetails_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELEMAILDATAPROVIDEREXPORT
@interface WAEDEmailDataProviderTriggerDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAEDEmailDataProviderConnection* connection;
@end

#endif // __WAEDEmailDataProviderTriggerDetails_DEFINED__

// Windows.ApplicationModel.Email.DataProvider.EmailMailboxSyncManagerSyncRequest
#ifndef __WAEDEmailMailboxSyncManagerSyncRequest_DEFINED__
#define __WAEDEmailMailboxSyncManagerSyncRequest_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELEMAILDATAPROVIDEREXPORT
@interface WAEDEmailMailboxSyncManagerSyncRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * emailMailboxId;
- (RTObject<WFIAsyncAction>*)reportCompletedAsync;
- (RTObject<WFIAsyncAction>*)reportFailedAsync;
@end

#endif // __WAEDEmailMailboxSyncManagerSyncRequest_DEFINED__

// Windows.ApplicationModel.Email.DataProvider.EmailMailboxDownloadMessageRequest
#ifndef __WAEDEmailMailboxDownloadMessageRequest_DEFINED__
#define __WAEDEmailMailboxDownloadMessageRequest_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELEMAILDATAPROVIDEREXPORT
@interface WAEDEmailMailboxDownloadMessageRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * emailMailboxId;
@property (readonly) NSString * emailMessageId;
- (RTObject<WFIAsyncAction>*)reportCompletedAsync;
- (RTObject<WFIAsyncAction>*)reportFailedAsync;
@end

#endif // __WAEDEmailMailboxDownloadMessageRequest_DEFINED__

// Windows.ApplicationModel.Email.DataProvider.EmailMailboxDownloadAttachmentRequest
#ifndef __WAEDEmailMailboxDownloadAttachmentRequest_DEFINED__
#define __WAEDEmailMailboxDownloadAttachmentRequest_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELEMAILDATAPROVIDEREXPORT
@interface WAEDEmailMailboxDownloadAttachmentRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * emailAttachmentId;
@property (readonly) NSString * emailMailboxId;
@property (readonly) NSString * emailMessageId;
- (RTObject<WFIAsyncAction>*)reportCompletedAsync;
- (RTObject<WFIAsyncAction>*)reportFailedAsync;
@end

#endif // __WAEDEmailMailboxDownloadAttachmentRequest_DEFINED__

// Windows.ApplicationModel.Email.DataProvider.EmailMailboxCreateFolderRequest
#ifndef __WAEDEmailMailboxCreateFolderRequest_DEFINED__
#define __WAEDEmailMailboxCreateFolderRequest_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELEMAILDATAPROVIDEREXPORT
@interface WAEDEmailMailboxCreateFolderRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * emailMailboxId;
@property (readonly) NSString * name;
@property (readonly) NSString * parentFolderId;
- (RTObject<WFIAsyncAction>*)reportCompletedAsync:(WAEEmailFolder*)folder;
- (RTObject<WFIAsyncAction>*)reportFailedAsync:(WAEEmailMailboxCreateFolderStatus)status;
@end

#endif // __WAEDEmailMailboxCreateFolderRequest_DEFINED__

// Windows.ApplicationModel.Email.DataProvider.EmailMailboxDeleteFolderRequest
#ifndef __WAEDEmailMailboxDeleteFolderRequest_DEFINED__
#define __WAEDEmailMailboxDeleteFolderRequest_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELEMAILDATAPROVIDEREXPORT
@interface WAEDEmailMailboxDeleteFolderRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * emailFolderId;
@property (readonly) NSString * emailMailboxId;
- (RTObject<WFIAsyncAction>*)reportCompletedAsync;
- (RTObject<WFIAsyncAction>*)reportFailedAsync:(WAEEmailMailboxDeleteFolderStatus)status;
@end

#endif // __WAEDEmailMailboxDeleteFolderRequest_DEFINED__

// Windows.ApplicationModel.Email.DataProvider.EmailMailboxEmptyFolderRequest
#ifndef __WAEDEmailMailboxEmptyFolderRequest_DEFINED__
#define __WAEDEmailMailboxEmptyFolderRequest_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELEMAILDATAPROVIDEREXPORT
@interface WAEDEmailMailboxEmptyFolderRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * emailFolderId;
@property (readonly) NSString * emailMailboxId;
- (RTObject<WFIAsyncAction>*)reportCompletedAsync;
- (RTObject<WFIAsyncAction>*)reportFailedAsync:(WAEEmailMailboxEmptyFolderStatus)status;
@end

#endif // __WAEDEmailMailboxEmptyFolderRequest_DEFINED__

// Windows.ApplicationModel.Email.DataProvider.EmailMailboxMoveFolderRequest
#ifndef __WAEDEmailMailboxMoveFolderRequest_DEFINED__
#define __WAEDEmailMailboxMoveFolderRequest_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELEMAILDATAPROVIDEREXPORT
@interface WAEDEmailMailboxMoveFolderRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * emailFolderId;
@property (readonly) NSString * emailMailboxId;
@property (readonly) NSString * newFolderName __attribute__ ((ns_returns_not_retained));
@property (readonly) NSString * newParentFolderId __attribute__ ((ns_returns_not_retained));
- (RTObject<WFIAsyncAction>*)reportCompletedAsync;
- (RTObject<WFIAsyncAction>*)reportFailedAsync;
@end

#endif // __WAEDEmailMailboxMoveFolderRequest_DEFINED__

// Windows.ApplicationModel.Email.DataProvider.EmailMailboxUpdateMeetingResponseRequest
#ifndef __WAEDEmailMailboxUpdateMeetingResponseRequest_DEFINED__
#define __WAEDEmailMailboxUpdateMeetingResponseRequest_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELEMAILDATAPROVIDEREXPORT
@interface WAEDEmailMailboxUpdateMeetingResponseRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * comment;
@property (readonly) NSString * emailMailboxId;
@property (readonly) NSString * emailMessageId;
@property (readonly) WAEEmailMeetingResponseType response;
@property (readonly) BOOL sendUpdate;
@property (readonly) NSString * subject;
- (RTObject<WFIAsyncAction>*)reportCompletedAsync;
- (RTObject<WFIAsyncAction>*)reportFailedAsync;
@end

#endif // __WAEDEmailMailboxUpdateMeetingResponseRequest_DEFINED__

// Windows.ApplicationModel.Email.DataProvider.EmailMailboxForwardMeetingRequest
#ifndef __WAEDEmailMailboxForwardMeetingRequest_DEFINED__
#define __WAEDEmailMailboxForwardMeetingRequest_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELEMAILDATAPROVIDEREXPORT
@interface WAEDEmailMailboxForwardMeetingRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * comment;
@property (readonly) NSString * emailMailboxId;
@property (readonly) NSString * emailMessageId;
@property (readonly) NSString * forwardHeader;
@property (readonly) WAEEmailMessageBodyKind forwardHeaderType;
@property (readonly) NSArray* /* WAEEmailRecipient* */ recipients;
@property (readonly) NSString * subject;
- (RTObject<WFIAsyncAction>*)reportCompletedAsync;
- (RTObject<WFIAsyncAction>*)reportFailedAsync;
@end

#endif // __WAEDEmailMailboxForwardMeetingRequest_DEFINED__

// Windows.ApplicationModel.Email.DataProvider.EmailMailboxProposeNewTimeForMeetingRequest
#ifndef __WAEDEmailMailboxProposeNewTimeForMeetingRequest_DEFINED__
#define __WAEDEmailMailboxProposeNewTimeForMeetingRequest_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELEMAILDATAPROVIDEREXPORT
@interface WAEDEmailMailboxProposeNewTimeForMeetingRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * comment;
@property (readonly) NSString * emailMailboxId;
@property (readonly) NSString * emailMessageId;
@property (readonly) WFTimeSpan* newDuration __attribute__ ((ns_returns_not_retained));
@property (readonly) WFDateTime* newStartTime __attribute__ ((ns_returns_not_retained));
@property (readonly) NSString * subject;
- (RTObject<WFIAsyncAction>*)reportCompletedAsync;
- (RTObject<WFIAsyncAction>*)reportFailedAsync;
@end

#endif // __WAEDEmailMailboxProposeNewTimeForMeetingRequest_DEFINED__

// Windows.ApplicationModel.Email.DataProvider.EmailMailboxSetAutoReplySettingsRequest
#ifndef __WAEDEmailMailboxSetAutoReplySettingsRequest_DEFINED__
#define __WAEDEmailMailboxSetAutoReplySettingsRequest_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELEMAILDATAPROVIDEREXPORT
@interface WAEDEmailMailboxSetAutoReplySettingsRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAEEmailMailboxAutoReplySettings* autoReplySettings;
@property (readonly) NSString * emailMailboxId;
- (RTObject<WFIAsyncAction>*)reportCompletedAsync;
- (RTObject<WFIAsyncAction>*)reportFailedAsync;
@end

#endif // __WAEDEmailMailboxSetAutoReplySettingsRequest_DEFINED__

// Windows.ApplicationModel.Email.DataProvider.EmailMailboxGetAutoReplySettingsRequest
#ifndef __WAEDEmailMailboxGetAutoReplySettingsRequest_DEFINED__
#define __WAEDEmailMailboxGetAutoReplySettingsRequest_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELEMAILDATAPROVIDEREXPORT
@interface WAEDEmailMailboxGetAutoReplySettingsRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * emailMailboxId;
@property (readonly) WAEEmailMailboxAutoReplyMessageResponseKind requestedFormat;
- (RTObject<WFIAsyncAction>*)reportCompletedAsync:(WAEEmailMailboxAutoReplySettings*)autoReplySettings;
- (RTObject<WFIAsyncAction>*)reportFailedAsync;
@end

#endif // __WAEDEmailMailboxGetAutoReplySettingsRequest_DEFINED__

// Windows.ApplicationModel.Email.DataProvider.EmailMailboxResolveRecipientsRequest
#ifndef __WAEDEmailMailboxResolveRecipientsRequest_DEFINED__
#define __WAEDEmailMailboxResolveRecipientsRequest_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELEMAILDATAPROVIDEREXPORT
@interface WAEDEmailMailboxResolveRecipientsRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * emailMailboxId;
@property (readonly) NSArray* /* NSString * */ recipients;
- (RTObject<WFIAsyncAction>*)reportCompletedAsync:(id<NSFastEnumeration> /* WAEEmailRecipientResolutionResult* */)resolutionResults;
- (RTObject<WFIAsyncAction>*)reportFailedAsync;
@end

#endif // __WAEDEmailMailboxResolveRecipientsRequest_DEFINED__

// Windows.ApplicationModel.Email.DataProvider.EmailMailboxValidateCertificatesRequest
#ifndef __WAEDEmailMailboxValidateCertificatesRequest_DEFINED__
#define __WAEDEmailMailboxValidateCertificatesRequest_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELEMAILDATAPROVIDEREXPORT
@interface WAEDEmailMailboxValidateCertificatesRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WSCCCertificate* */ certificates;
@property (readonly) NSString * emailMailboxId;
- (RTObject<WFIAsyncAction>*)reportCompletedAsync:(id<NSFastEnumeration> /* WAEEmailCertificateValidationStatus */)validationStatuses;
- (RTObject<WFIAsyncAction>*)reportFailedAsync;
@end

#endif // __WAEDEmailMailboxValidateCertificatesRequest_DEFINED__

// Windows.ApplicationModel.Email.DataProvider.EmailMailboxServerSearchReadBatchRequest
#ifndef __WAEDEmailMailboxServerSearchReadBatchRequest_DEFINED__
#define __WAEDEmailMailboxServerSearchReadBatchRequest_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELEMAILDATAPROVIDEREXPORT
@interface WAEDEmailMailboxServerSearchReadBatchRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * emailFolderId;
@property (readonly) NSString * emailMailboxId;
@property (readonly) WAEEmailQueryOptions* options;
@property (readonly) NSString * sessionId;
@property (readonly) unsigned int suggestedBatchSize;
- (RTObject<WFIAsyncAction>*)saveMessageAsync:(WAEEmailMessage*)message;
- (RTObject<WFIAsyncAction>*)reportCompletedAsync;
- (RTObject<WFIAsyncAction>*)reportFailedAsync:(WAEEmailBatchStatus)batchStatus;
@end

#endif // __WAEDEmailMailboxServerSearchReadBatchRequest_DEFINED__

