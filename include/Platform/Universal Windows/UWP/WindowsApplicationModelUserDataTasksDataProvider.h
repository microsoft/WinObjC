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

// WindowsApplicationModelUserDataTasksDataProvider.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSAPPLICATIONMODELUSERDATATASKSDATAPROVIDEREXPORT
#define OBJCUWPWINDOWSAPPLICATIONMODELUSERDATATASKSDATAPROVIDEREXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsApplicationModelUserDataTasksDataProvider.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WAUDUserDataTaskDataProviderConnection, WAUDUserDataTaskListCreateOrUpdateTaskRequestEventArgs, WAUDUserDataTaskListSyncManagerSyncRequestEventArgs, WAUDUserDataTaskListSkipOccurrenceRequestEventArgs, WAUDUserDataTaskListCompleteTaskRequestEventArgs, WAUDUserDataTaskListDeleteTaskRequestEventArgs, WAUDUserDataTaskDataProviderTriggerDetails, WAUDUserDataTaskListCreateOrUpdateTaskRequest, WAUDUserDataTaskListSyncManagerSyncRequest, WAUDUserDataTaskListSkipOccurrenceRequest, WAUDUserDataTaskListCompleteTaskRequest, WAUDUserDataTaskListDeleteTaskRequest;
@protocol WAUDIUserDataTaskDataProviderTriggerDetails, WAUDIUserDataTaskDataProviderConnection, WAUDIUserDataTaskListCreateOrUpdateTaskRequest, WAUDIUserDataTaskListSyncManagerSyncRequest, WAUDIUserDataTaskListSkipOccurrenceRequest, WAUDIUserDataTaskListCompleteTaskRequest, WAUDIUserDataTaskListDeleteTaskRequest, WAUDIUserDataTaskListCreateOrUpdateTaskRequestEventArgs, WAUDIUserDataTaskListSyncManagerSyncRequestEventArgs, WAUDIUserDataTaskListSkipOccurrenceRequestEventArgs, WAUDIUserDataTaskListCompleteTaskRequestEventArgs, WAUDIUserDataTaskListDeleteTaskRequestEventArgs;

#include "WindowsFoundation.h"
#include "WindowsApplicationModelUserDataTasks.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.UserDataTasks.DataProvider.UserDataTaskDataProviderConnection
#ifndef __WAUDUserDataTaskDataProviderConnection_DEFINED__
#define __WAUDUserDataTaskDataProviderConnection_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELUSERDATATASKSDATAPROVIDEREXPORT
@interface WAUDUserDataTaskDataProviderConnection : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (EventRegistrationToken)addCompleteTaskRequestedEvent:(void(^)(WAUDUserDataTaskDataProviderConnection*, WAUDUserDataTaskListCompleteTaskRequestEventArgs*))del;
- (void)removeCompleteTaskRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCreateOrUpdateTaskRequestedEvent:(void(^)(WAUDUserDataTaskDataProviderConnection*, WAUDUserDataTaskListCreateOrUpdateTaskRequestEventArgs*))del;
- (void)removeCreateOrUpdateTaskRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDeleteTaskRequestedEvent:(void(^)(WAUDUserDataTaskDataProviderConnection*, WAUDUserDataTaskListDeleteTaskRequestEventArgs*))del;
- (void)removeDeleteTaskRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSkipOccurrenceRequestedEvent:(void(^)(WAUDUserDataTaskDataProviderConnection*, WAUDUserDataTaskListSkipOccurrenceRequestEventArgs*))del;
- (void)removeSkipOccurrenceRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSyncRequestedEvent:(void(^)(WAUDUserDataTaskDataProviderConnection*, WAUDUserDataTaskListSyncManagerSyncRequestEventArgs*))del;
- (void)removeSyncRequestedEvent:(EventRegistrationToken)tok;
- (void)start;
@end

#endif // __WAUDUserDataTaskDataProviderConnection_DEFINED__

// Windows.ApplicationModel.UserDataTasks.DataProvider.UserDataTaskListCreateOrUpdateTaskRequestEventArgs
#ifndef __WAUDUserDataTaskListCreateOrUpdateTaskRequestEventArgs_DEFINED__
#define __WAUDUserDataTaskListCreateOrUpdateTaskRequestEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELUSERDATATASKSDATAPROVIDEREXPORT
@interface WAUDUserDataTaskListCreateOrUpdateTaskRequestEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAUDUserDataTaskListCreateOrUpdateTaskRequest* request;
- (WFDeferral*)getDeferral;
@end

#endif // __WAUDUserDataTaskListCreateOrUpdateTaskRequestEventArgs_DEFINED__

// Windows.ApplicationModel.UserDataTasks.DataProvider.UserDataTaskListSyncManagerSyncRequestEventArgs
#ifndef __WAUDUserDataTaskListSyncManagerSyncRequestEventArgs_DEFINED__
#define __WAUDUserDataTaskListSyncManagerSyncRequestEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELUSERDATATASKSDATAPROVIDEREXPORT
@interface WAUDUserDataTaskListSyncManagerSyncRequestEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAUDUserDataTaskListSyncManagerSyncRequest* request;
- (WFDeferral*)getDeferral;
@end

#endif // __WAUDUserDataTaskListSyncManagerSyncRequestEventArgs_DEFINED__

// Windows.ApplicationModel.UserDataTasks.DataProvider.UserDataTaskListSkipOccurrenceRequestEventArgs
#ifndef __WAUDUserDataTaskListSkipOccurrenceRequestEventArgs_DEFINED__
#define __WAUDUserDataTaskListSkipOccurrenceRequestEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELUSERDATATASKSDATAPROVIDEREXPORT
@interface WAUDUserDataTaskListSkipOccurrenceRequestEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAUDUserDataTaskListSkipOccurrenceRequest* request;
- (WFDeferral*)getDeferral;
@end

#endif // __WAUDUserDataTaskListSkipOccurrenceRequestEventArgs_DEFINED__

// Windows.ApplicationModel.UserDataTasks.DataProvider.UserDataTaskListCompleteTaskRequestEventArgs
#ifndef __WAUDUserDataTaskListCompleteTaskRequestEventArgs_DEFINED__
#define __WAUDUserDataTaskListCompleteTaskRequestEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELUSERDATATASKSDATAPROVIDEREXPORT
@interface WAUDUserDataTaskListCompleteTaskRequestEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAUDUserDataTaskListCompleteTaskRequest* request;
- (WFDeferral*)getDeferral;
@end

#endif // __WAUDUserDataTaskListCompleteTaskRequestEventArgs_DEFINED__

// Windows.ApplicationModel.UserDataTasks.DataProvider.UserDataTaskListDeleteTaskRequestEventArgs
#ifndef __WAUDUserDataTaskListDeleteTaskRequestEventArgs_DEFINED__
#define __WAUDUserDataTaskListDeleteTaskRequestEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELUSERDATATASKSDATAPROVIDEREXPORT
@interface WAUDUserDataTaskListDeleteTaskRequestEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAUDUserDataTaskListDeleteTaskRequest* request;
- (WFDeferral*)getDeferral;
@end

#endif // __WAUDUserDataTaskListDeleteTaskRequestEventArgs_DEFINED__

// Windows.ApplicationModel.UserDataTasks.DataProvider.UserDataTaskDataProviderTriggerDetails
#ifndef __WAUDUserDataTaskDataProviderTriggerDetails_DEFINED__
#define __WAUDUserDataTaskDataProviderTriggerDetails_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELUSERDATATASKSDATAPROVIDEREXPORT
@interface WAUDUserDataTaskDataProviderTriggerDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAUDUserDataTaskDataProviderConnection* connection;
@end

#endif // __WAUDUserDataTaskDataProviderTriggerDetails_DEFINED__

// Windows.ApplicationModel.UserDataTasks.DataProvider.UserDataTaskListCreateOrUpdateTaskRequest
#ifndef __WAUDUserDataTaskListCreateOrUpdateTaskRequest_DEFINED__
#define __WAUDUserDataTaskListCreateOrUpdateTaskRequest_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELUSERDATATASKSDATAPROVIDEREXPORT
@interface WAUDUserDataTaskListCreateOrUpdateTaskRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WAUUserDataTask* task;
@property (readonly) NSString * taskListId;
- (RTObject<WFIAsyncAction>*)reportCompletedAsync:(WAUUserDataTask*)createdOrUpdatedUserDataTask;
- (RTObject<WFIAsyncAction>*)reportFailedAsync;
@end

#endif // __WAUDUserDataTaskListCreateOrUpdateTaskRequest_DEFINED__

// Windows.ApplicationModel.UserDataTasks.DataProvider.UserDataTaskListSyncManagerSyncRequest
#ifndef __WAUDUserDataTaskListSyncManagerSyncRequest_DEFINED__
#define __WAUDUserDataTaskListSyncManagerSyncRequest_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELUSERDATATASKSDATAPROVIDEREXPORT
@interface WAUDUserDataTaskListSyncManagerSyncRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * taskListId;
- (RTObject<WFIAsyncAction>*)reportCompletedAsync;
- (RTObject<WFIAsyncAction>*)reportFailedAsync;
@end

#endif // __WAUDUserDataTaskListSyncManagerSyncRequest_DEFINED__

// Windows.ApplicationModel.UserDataTasks.DataProvider.UserDataTaskListSkipOccurrenceRequest
#ifndef __WAUDUserDataTaskListSkipOccurrenceRequest_DEFINED__
#define __WAUDUserDataTaskListSkipOccurrenceRequest_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELUSERDATATASKSDATAPROVIDEREXPORT
@interface WAUDUserDataTaskListSkipOccurrenceRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * taskId;
@property (readonly) NSString * taskListId;
- (RTObject<WFIAsyncAction>*)reportCompletedAsync;
- (RTObject<WFIAsyncAction>*)reportFailedAsync;
@end

#endif // __WAUDUserDataTaskListSkipOccurrenceRequest_DEFINED__

// Windows.ApplicationModel.UserDataTasks.DataProvider.UserDataTaskListCompleteTaskRequest
#ifndef __WAUDUserDataTaskListCompleteTaskRequest_DEFINED__
#define __WAUDUserDataTaskListCompleteTaskRequest_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELUSERDATATASKSDATAPROVIDEREXPORT
@interface WAUDUserDataTaskListCompleteTaskRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * taskId;
@property (readonly) NSString * taskListId;
- (RTObject<WFIAsyncAction>*)reportCompletedAsync:(NSString *)completedTaskId;
- (RTObject<WFIAsyncAction>*)reportFailedAsync;
@end

#endif // __WAUDUserDataTaskListCompleteTaskRequest_DEFINED__

// Windows.ApplicationModel.UserDataTasks.DataProvider.UserDataTaskListDeleteTaskRequest
#ifndef __WAUDUserDataTaskListDeleteTaskRequest_DEFINED__
#define __WAUDUserDataTaskListDeleteTaskRequest_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELUSERDATATASKSDATAPROVIDEREXPORT
@interface WAUDUserDataTaskListDeleteTaskRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * taskId;
@property (readonly) NSString * taskListId;
- (RTObject<WFIAsyncAction>*)reportCompletedAsync;
- (RTObject<WFIAsyncAction>*)reportFailedAsync;
@end

#endif // __WAUDUserDataTaskListDeleteTaskRequest_DEFINED__

