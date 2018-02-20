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

// WindowsApplicationModelUserDataTasks.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
#define OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsConsolidatedNamespace.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WAUUserDataTaskManager, WAUUserDataTaskStore, WAUUserDataTaskList, WAUUserDataTaskListLimitedWriteOperations, WAUUserDataTaskListSyncManager, WAUUserDataTaskReader, WAUUserDataTaskQueryOptions, WAUUserDataTask, WAUUserDataTaskBatch, WAUUserDataTaskRecurrenceProperties, WAUUserDataTaskRegenerationProperties;
@protocol WAUIUserDataTaskManagerStatics, WAUIUserDataTaskManager, WAUIUserDataTaskStore, WAUIUserDataTaskQueryOptions, WAUIUserDataTaskList, WAUIUserDataTaskListLimitedWriteOperations, WAUIUserDataTaskBatch, WAUIUserDataTaskReader, WAUIUserDataTask, WAUIUserDataTaskRecurrenceProperties, WAUIUserDataTaskRegenerationProperties, WAUIUserDataTaskListSyncManager;

// Windows.ApplicationModel.UserDataTasks.UserDataTaskStoreAccessType
enum _WAUUserDataTaskStoreAccessType {
    WAUUserDataTaskStoreAccessTypeAppTasksReadWrite = 0,
    WAUUserDataTaskStoreAccessTypeAllTasksLimitedReadWrite = 1,
};
typedef unsigned WAUUserDataTaskStoreAccessType;

// Windows.ApplicationModel.UserDataTasks.UserDataTaskListOtherAppReadAccess
enum _WAUUserDataTaskListOtherAppReadAccess {
    WAUUserDataTaskListOtherAppReadAccessFull = 0,
    WAUUserDataTaskListOtherAppReadAccessSystemOnly = 1,
    WAUUserDataTaskListOtherAppReadAccessNone = 2,
};
typedef unsigned WAUUserDataTaskListOtherAppReadAccess;

// Windows.ApplicationModel.UserDataTasks.UserDataTaskListOtherAppWriteAccess
enum _WAUUserDataTaskListOtherAppWriteAccess {
    WAUUserDataTaskListOtherAppWriteAccessLimited = 0,
    WAUUserDataTaskListOtherAppWriteAccessNone = 1,
};
typedef unsigned WAUUserDataTaskListOtherAppWriteAccess;

// Windows.ApplicationModel.UserDataTasks.UserDataTaskKind
enum _WAUUserDataTaskKind {
    WAUUserDataTaskKindSingle = 0,
    WAUUserDataTaskKindRecurring = 1,
    WAUUserDataTaskKindRegenerating = 2,
};
typedef unsigned WAUUserDataTaskKind;

// Windows.ApplicationModel.UserDataTasks.UserDataTaskPriority
enum _WAUUserDataTaskPriority {
    WAUUserDataTaskPriorityNormal = 0,
    WAUUserDataTaskPriorityLow = -1,
    WAUUserDataTaskPriorityHigh = 1,
};
typedef unsigned WAUUserDataTaskPriority;

// Windows.ApplicationModel.UserDataTasks.UserDataTaskSensitivity
enum _WAUUserDataTaskSensitivity {
    WAUUserDataTaskSensitivityPublic = 0,
    WAUUserDataTaskSensitivityPrivate = 1,
};
typedef unsigned WAUUserDataTaskSensitivity;

// Windows.ApplicationModel.UserDataTasks.UserDataTaskDetailsKind
enum _WAUUserDataTaskDetailsKind {
    WAUUserDataTaskDetailsKindPlainText = 0,
    WAUUserDataTaskDetailsKindHtml = 1,
};
typedef unsigned WAUUserDataTaskDetailsKind;

// Windows.ApplicationModel.UserDataTasks.UserDataTaskRecurrenceUnit
enum _WAUUserDataTaskRecurrenceUnit {
    WAUUserDataTaskRecurrenceUnitDaily = 0,
    WAUUserDataTaskRecurrenceUnitWeekly = 1,
    WAUUserDataTaskRecurrenceUnitMonthly = 2,
    WAUUserDataTaskRecurrenceUnitMonthlyOnDay = 3,
    WAUUserDataTaskRecurrenceUnitYearly = 4,
    WAUUserDataTaskRecurrenceUnitYearlyOnDay = 5,
};
typedef unsigned WAUUserDataTaskRecurrenceUnit;

// Windows.ApplicationModel.UserDataTasks.UserDataTaskRegenerationUnit
enum _WAUUserDataTaskRegenerationUnit {
    WAUUserDataTaskRegenerationUnitDaily = 0,
    WAUUserDataTaskRegenerationUnitWeekly = 1,
    WAUUserDataTaskRegenerationUnitMonthly = 2,
    WAUUserDataTaskRegenerationUnitYearly = 4,
};
typedef unsigned WAUUserDataTaskRegenerationUnit;

// Windows.ApplicationModel.UserDataTasks.UserDataTaskDaysOfWeek
enum _WAUUserDataTaskDaysOfWeek {
    WAUUserDataTaskDaysOfWeekNone = 0,
    WAUUserDataTaskDaysOfWeekSunday = 1,
    WAUUserDataTaskDaysOfWeekMonday = 2,
    WAUUserDataTaskDaysOfWeekTuesday = 4,
    WAUUserDataTaskDaysOfWeekWednesday = 8,
    WAUUserDataTaskDaysOfWeekThursday = 16,
    WAUUserDataTaskDaysOfWeekFriday = 32,
    WAUUserDataTaskDaysOfWeekSaturday = 64,
};
typedef unsigned WAUUserDataTaskDaysOfWeek;

// Windows.ApplicationModel.UserDataTasks.UserDataTaskQuerySortProperty
enum _WAUUserDataTaskQuerySortProperty {
    WAUUserDataTaskQuerySortPropertyDueDate = 0,
};
typedef unsigned WAUUserDataTaskQuerySortProperty;

// Windows.ApplicationModel.UserDataTasks.UserDataTaskQueryKind
enum _WAUUserDataTaskQueryKind {
    WAUUserDataTaskQueryKindAll = 0,
    WAUUserDataTaskQueryKindIncomplete = 1,
    WAUUserDataTaskQueryKindComplete = 2,
};
typedef unsigned WAUUserDataTaskQueryKind;

// Windows.ApplicationModel.UserDataTasks.UserDataTaskWeekOfMonth
enum _WAUUserDataTaskWeekOfMonth {
    WAUUserDataTaskWeekOfMonthFirst = 0,
    WAUUserDataTaskWeekOfMonthSecond = 1,
    WAUUserDataTaskWeekOfMonthThird = 2,
    WAUUserDataTaskWeekOfMonthFourth = 3,
    WAUUserDataTaskWeekOfMonthLast = 4,
};
typedef unsigned WAUUserDataTaskWeekOfMonth;

// Windows.ApplicationModel.UserDataTasks.UserDataTaskListSyncStatus
enum _WAUUserDataTaskListSyncStatus {
    WAUUserDataTaskListSyncStatusIdle = 0,
    WAUUserDataTaskListSyncStatusSyncing = 1,
    WAUUserDataTaskListSyncStatusUpToDate = 2,
    WAUUserDataTaskListSyncStatusAuthenticationError = 3,
    WAUUserDataTaskListSyncStatusPolicyError = 4,
    WAUUserDataTaskListSyncStatusUnknownError = 5,
};
typedef unsigned WAUUserDataTaskListSyncStatus;

#include "WindowsSystem.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.UserDataTasks.UserDataTaskManager
#ifndef __WAUUserDataTaskManager_DEFINED__
#define __WAUUserDataTaskManager_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAUUserDataTaskManager : RTObject
+ (WAUUserDataTaskManager*)getDefault;
+ (WAUUserDataTaskManager*)getForUser:(WSUser*)user;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSUser* user;
- (void)requestStoreAsync:(WAUUserDataTaskStoreAccessType)accessType success:(void (^)(WAUUserDataTaskStore*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WAUUserDataTaskManager_DEFINED__

// Windows.ApplicationModel.UserDataTasks.UserDataTaskStore
#ifndef __WAUUserDataTaskStore_DEFINED__
#define __WAUUserDataTaskStore_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAUUserDataTaskStore : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)createListAsync:(NSString *)name success:(void (^)(WAUUserDataTaskList*))success failure:(void (^)(NSError*))failure;
- (void)createListInAccountAsync:(NSString *)name userDataAccountId:(NSString *)userDataAccountId success:(void (^)(WAUUserDataTaskList*))success failure:(void (^)(NSError*))failure;
- (void)findListsAsyncWithSuccess:(void (^)(NSArray* /* WAUUserDataTaskList* */))success failure:(void (^)(NSError*))failure;
- (void)getListAsync:(NSString *)taskListId success:(void (^)(WAUUserDataTaskList*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WAUUserDataTaskStore_DEFINED__

// Windows.ApplicationModel.UserDataTasks.UserDataTaskList
#ifndef __WAUUserDataTaskList_DEFINED__
#define __WAUUserDataTaskList_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAUUserDataTaskList : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WAUUserDataTaskListOtherAppWriteAccess otherAppWriteAccess;
@property WAUUserDataTaskListOtherAppReadAccess otherAppReadAccess;
@property (retain) NSString * displayName;
@property (readonly) NSString * id;
@property (readonly) WAUUserDataTaskListLimitedWriteOperations* limitedWriteOperations;
@property (readonly) NSString * sourceDisplayName;
@property (readonly) WAUUserDataTaskListSyncManager* syncManager;
@property (readonly) NSString * userDataAccountId;
- (RTObject<WFIAsyncAction>*)registerSyncManagerAsync;
- (WAUUserDataTaskReader*)getTaskReader;
- (WAUUserDataTaskReader*)getTaskReaderWithOptions:(WAUUserDataTaskQueryOptions*)options;
- (void)getTaskAsync:(NSString *)userDataTask success:(void (^)(WAUUserDataTask*))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)saveTaskAsync:(WAUUserDataTask*)userDataTask;
- (RTObject<WFIAsyncAction>*)deleteTaskAsync:(NSString *)userDataTaskId;
- (RTObject<WFIAsyncAction>*)deleteAsync;
- (RTObject<WFIAsyncAction>*)saveAsync;
@end

#endif // __WAUUserDataTaskList_DEFINED__

// Windows.ApplicationModel.UserDataTasks.UserDataTaskListLimitedWriteOperations
#ifndef __WAUUserDataTaskListLimitedWriteOperations_DEFINED__
#define __WAUUserDataTaskListLimitedWriteOperations_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAUUserDataTaskListLimitedWriteOperations : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)tryCompleteTaskAsync:(NSString *)userDataTaskId success:(void (^)(NSString *))success failure:(void (^)(NSError*))failure;
- (void)tryCreateOrUpdateTaskAsync:(WAUUserDataTask*)userDataTask success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)tryDeleteTaskAsync:(NSString *)userDataTaskId success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)trySkipOccurrenceAsync:(NSString *)userDataTaskId success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WAUUserDataTaskListLimitedWriteOperations_DEFINED__

// Windows.ApplicationModel.UserDataTasks.UserDataTaskListSyncManager
#ifndef __WAUUserDataTaskListSyncManager_DEFINED__
#define __WAUUserDataTaskListSyncManager_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAUUserDataTaskListSyncManager : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WAUUserDataTaskListSyncStatus status;
@property (retain) WFDateTime* lastSuccessfulSyncTime;
@property (retain) WFDateTime* lastAttemptedSyncTime;
- (EventRegistrationToken)addSyncStatusChangedEvent:(void(^)(WAUUserDataTaskListSyncManager*, RTObject*))del;
- (void)removeSyncStatusChangedEvent:(EventRegistrationToken)tok;
- (void)syncAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WAUUserDataTaskListSyncManager_DEFINED__

// Windows.ApplicationModel.UserDataTasks.UserDataTaskReader
#ifndef __WAUUserDataTaskReader_DEFINED__
#define __WAUUserDataTaskReader_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAUUserDataTaskReader : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)readBatchAsyncWithSuccess:(void (^)(WAUUserDataTaskBatch*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WAUUserDataTaskReader_DEFINED__

// Windows.ApplicationModel.UserDataTasks.UserDataTaskQueryOptions
#ifndef __WAUUserDataTaskQueryOptions_DEFINED__
#define __WAUUserDataTaskQueryOptions_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAUUserDataTaskQueryOptions : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WAUUserDataTaskQuerySortProperty sortProperty;
@property WAUUserDataTaskQueryKind kind;
@end

#endif // __WAUUserDataTaskQueryOptions_DEFINED__

// Windows.ApplicationModel.UserDataTasks.UserDataTask
#ifndef __WAUUserDataTask_DEFINED__
#define __WAUUserDataTask_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAUUserDataTask : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WAUUserDataTaskRegenerationProperties* regenerationProperties;
@property WAUUserDataTaskPriority priority;
@property (retain) id /* WFDateTime* */ completedDate;
@property (retain) id /* WFDateTime* */ dueDate;
@property WAUUserDataTaskDetailsKind detailsKind;
@property (retain) id /* WFDateTime* */ startDate;
@property (retain) NSString * details;
@property (retain) NSString * subject;
@property WAUUserDataTaskSensitivity sensitivity;
@property (retain) NSString * remoteId;
@property (retain) id /* WFDateTime* */ reminder;
@property (retain) WAUUserDataTaskRecurrenceProperties* recurrenceProperties;
@property (readonly) NSString * id;
@property (readonly) WAUUserDataTaskKind kind;
@property (readonly) NSString * listId;
@end

#endif // __WAUUserDataTask_DEFINED__

// Windows.ApplicationModel.UserDataTasks.UserDataTaskBatch
#ifndef __WAUUserDataTaskBatch_DEFINED__
#define __WAUUserDataTaskBatch_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAUUserDataTaskBatch : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WAUUserDataTask* */ tasks;
@end

#endif // __WAUUserDataTaskBatch_DEFINED__

// Windows.ApplicationModel.UserDataTasks.UserDataTaskRecurrenceProperties
#ifndef __WAUUserDataTaskRecurrenceProperties_DEFINED__
#define __WAUUserDataTaskRecurrenceProperties_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAUUserDataTaskRecurrenceProperties : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) id /* WAUUserDataTaskWeekOfMonth */ weekOfMonth;
@property (retain) id /* WFDateTime* */ until;
@property WAUUserDataTaskRecurrenceUnit unit;
@property (retain) id /* int */ occurrences;
@property (retain) id /* int */ month;
@property int interval;
@property (retain) id /* WAUUserDataTaskDaysOfWeek */ daysOfWeek;
@property (retain) id /* int */ day;
@end

#endif // __WAUUserDataTaskRecurrenceProperties_DEFINED__

// Windows.ApplicationModel.UserDataTasks.UserDataTaskRegenerationProperties
#ifndef __WAUUserDataTaskRegenerationProperties_DEFINED__
#define __WAUUserDataTaskRegenerationProperties_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WAUUserDataTaskRegenerationProperties : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) id /* WFDateTime* */ until;
@property WAUUserDataTaskRegenerationUnit unit;
@property (retain) id /* int */ occurrences;
@property int interval;
@end

#endif // __WAUUserDataTaskRegenerationProperties_DEFINED__

