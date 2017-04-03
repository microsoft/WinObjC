//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

// WindowsApplicationModelContactsDataProvider.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSAPPLICATIONMODELCONTACTSDATAPROVIDEREXPORT
#define OBJCUWPWINDOWSAPPLICATIONMODELCONTACTSDATAPROVIDEREXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsApplicationModelContactsDataProvider.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WACDContactDataProviderConnection, WACDContactListSyncManagerSyncRequestEventArgs, WACDContactListServerSearchReadBatchRequestEventArgs, WACDContactDataProviderTriggerDetails, WACDContactListSyncManagerSyncRequest, WACDContactListServerSearchReadBatchRequest;
@protocol WACDIContactDataProviderTriggerDetails, WACDIContactDataProviderConnection, WACDIContactListSyncManagerSyncRequest, WACDIContactListServerSearchReadBatchRequest, WACDIContactListSyncManagerSyncRequestEventArgs, WACDIContactListServerSearchReadBatchRequestEventArgs;

#include "WindowsFoundation.h"
#include "WindowsApplicationModelContacts.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.Contacts.DataProvider.ContactDataProviderConnection
#ifndef __WACDContactDataProviderConnection_DEFINED__
#define __WACDContactDataProviderConnection_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELCONTACTSDATAPROVIDEREXPORT
@interface WACDContactDataProviderConnection : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (EventRegistrationToken)addServerSearchReadBatchRequestedEvent:(void(^)(WACDContactDataProviderConnection*, WACDContactListServerSearchReadBatchRequestEventArgs*))del;
- (void)removeServerSearchReadBatchRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSyncRequestedEvent:(void(^)(WACDContactDataProviderConnection*, WACDContactListSyncManagerSyncRequestEventArgs*))del;
- (void)removeSyncRequestedEvent:(EventRegistrationToken)tok;
- (void)start;
@end

#endif // __WACDContactDataProviderConnection_DEFINED__

// Windows.ApplicationModel.Contacts.DataProvider.ContactListSyncManagerSyncRequestEventArgs
#ifndef __WACDContactListSyncManagerSyncRequestEventArgs_DEFINED__
#define __WACDContactListSyncManagerSyncRequestEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELCONTACTSDATAPROVIDEREXPORT
@interface WACDContactListSyncManagerSyncRequestEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WACDContactListSyncManagerSyncRequest* request;
- (WFDeferral*)getDeferral;
@end

#endif // __WACDContactListSyncManagerSyncRequestEventArgs_DEFINED__

// Windows.ApplicationModel.Contacts.DataProvider.ContactListServerSearchReadBatchRequestEventArgs
#ifndef __WACDContactListServerSearchReadBatchRequestEventArgs_DEFINED__
#define __WACDContactListServerSearchReadBatchRequestEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELCONTACTSDATAPROVIDEREXPORT
@interface WACDContactListServerSearchReadBatchRequestEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WACDContactListServerSearchReadBatchRequest* request;
- (WFDeferral*)getDeferral;
@end

#endif // __WACDContactListServerSearchReadBatchRequestEventArgs_DEFINED__

// Windows.ApplicationModel.Contacts.DataProvider.ContactDataProviderTriggerDetails
#ifndef __WACDContactDataProviderTriggerDetails_DEFINED__
#define __WACDContactDataProviderTriggerDetails_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELCONTACTSDATAPROVIDEREXPORT
@interface WACDContactDataProviderTriggerDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WACDContactDataProviderConnection* connection;
@end

#endif // __WACDContactDataProviderTriggerDetails_DEFINED__

// Windows.ApplicationModel.Contacts.DataProvider.ContactListSyncManagerSyncRequest
#ifndef __WACDContactListSyncManagerSyncRequest_DEFINED__
#define __WACDContactListSyncManagerSyncRequest_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELCONTACTSDATAPROVIDEREXPORT
@interface WACDContactListSyncManagerSyncRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * contactListId;
- (RTObject<WFIAsyncAction>*)reportCompletedAsync;
- (RTObject<WFIAsyncAction>*)reportFailedAsync;
@end

#endif // __WACDContactListSyncManagerSyncRequest_DEFINED__

// Windows.ApplicationModel.Contacts.DataProvider.ContactListServerSearchReadBatchRequest
#ifndef __WACDContactListServerSearchReadBatchRequest_DEFINED__
#define __WACDContactListServerSearchReadBatchRequest_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELCONTACTSDATAPROVIDEREXPORT
@interface WACDContactListServerSearchReadBatchRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * contactListId;
@property (readonly) WACContactQueryOptions* options;
@property (readonly) NSString * sessionId;
@property (readonly) unsigned int suggestedBatchSize;
- (RTObject<WFIAsyncAction>*)saveContactAsync:(WACContact*)contact;
- (RTObject<WFIAsyncAction>*)reportCompletedAsync;
- (RTObject<WFIAsyncAction>*)reportFailedAsync:(WACContactBatchStatus)batchStatus;
@end

#endif // __WACDContactListServerSearchReadBatchRequest_DEFINED__

