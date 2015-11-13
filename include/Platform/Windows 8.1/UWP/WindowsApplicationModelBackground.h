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

// WindowsApplicationModelBackground.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WABAlarmApplicationManager, WABBackgroundExecutionManager, WABBackgroundTaskRegistration, WABBackgroundTaskDeferral,
    WABBackgroundTaskProgressEventArgs, WABBackgroundTaskCompletedEventArgs, WABBackgroundTaskBuilder, WABBackgroundWorkCost,
    WABSystemTrigger, WABSystemCondition, WABNetworkOperatorNotificationTrigger, WABTimeTrigger, WABMaintenanceTrigger, WABDeviceUseTrigger,
    WABDeviceServicingTrigger, WABLocationTrigger, WABNetworkOperatorHotspotAuthenticationTrigger, WABPushNotificationTrigger;
@protocol WABIAlarmApplicationManagerStatics
, WABIBackgroundExecutionManagerStatics, WABIBackgroundTaskInstance, WABIBackgroundWorkCostStatics, WABIBackgroundTaskDeferral,
    WABIBackgroundTaskInstance2, WABIBackgroundTask, WABIBackgroundTaskRegistration, WABIBackgroundTaskRegistrationStatics,
    WABIBackgroundTaskBuilder, WABIBackgroundTrigger, WABIBackgroundCondition, WABIBackgroundTaskBuilder2,
    WABIBackgroundTaskCompletedEventArgs, WABIBackgroundTaskProgressEventArgs, WABISystemTrigger, WABISystemTriggerFactory,
    WABISystemCondition, WABISystemConditionFactory, WABINetworkOperatorNotificationTrigger, WABINetworkOperatorNotificationTriggerFactory,
    WABITimeTrigger, WABITimeTriggerFactory, WABIMaintenanceTrigger, WABIMaintenanceTriggerFactory, WABIDeviceUseTrigger,
    WABIDeviceServicingTrigger, WABILocationTrigger, WABILocationTriggerFactory, WABINetworkOperatorHotspotAuthenticationTrigger,
    WABIPushNotificationTriggerFactory;

// Windows.ApplicationModel.Background.AlarmAccessStatus
enum _WABAlarmAccessStatus {
    WABAlarmAccessStatusUnspecified = 0,
    WABAlarmAccessStatusAllowedWithWakeupCapability = 1,
    WABAlarmAccessStatusAllowedWithoutWakeupCapability = 2,
    WABAlarmAccessStatusDenied = 3,
};
typedef unsigned WABAlarmAccessStatus;

// Windows.ApplicationModel.Background.BackgroundAccessStatus
enum _WABBackgroundAccessStatus {
    WABBackgroundAccessStatusUnspecified = 0,
    WABBackgroundAccessStatusAllowedWithAlwaysOnRealTimeConnectivity = 1,
    WABBackgroundAccessStatusAllowedMayUseActiveRealTimeConnectivity = 2,
    WABBackgroundAccessStatusDenied = 3,
};
typedef unsigned WABBackgroundAccessStatus;

// Windows.ApplicationModel.Background.BackgroundWorkCostValue
enum _WABBackgroundWorkCostValue {
    WABBackgroundWorkCostValueLow = 0,
    WABBackgroundWorkCostValueMedium = 1,
    WABBackgroundWorkCostValueHigh = 2,
};
typedef unsigned WABBackgroundWorkCostValue;

// Windows.ApplicationModel.Background.BackgroundTaskCancellationReason
enum _WABBackgroundTaskCancellationReason {
    WABBackgroundTaskCancellationReasonAbort = 0,
    WABBackgroundTaskCancellationReasonTerminating = 1,
    WABBackgroundTaskCancellationReasonLoggingOff = 2,
    WABBackgroundTaskCancellationReasonServicingUpdate = 3,
    WABBackgroundTaskCancellationReasonIdleTask = 4,
    WABBackgroundTaskCancellationReasonUninstall = 5,
    WABBackgroundTaskCancellationReasonConditionLoss = 6,
    WABBackgroundTaskCancellationReasonSystemPolicy = 7,
    WABBackgroundTaskCancellationReasonQuietHoursEntered = 8,
};
typedef unsigned WABBackgroundTaskCancellationReason;

// Windows.ApplicationModel.Background.BackgroundTaskThrottleCounter
enum _WABBackgroundTaskThrottleCounter {
    WABBackgroundTaskThrottleCounterAll = 0,
    WABBackgroundTaskThrottleCounterCpu = 1,
    WABBackgroundTaskThrottleCounterNetwork = 2,
};
typedef unsigned WABBackgroundTaskThrottleCounter;

// Windows.ApplicationModel.Background.SystemTriggerType
enum _WABSystemTriggerType {
    WABSystemTriggerTypeInvalid = 0,
    WABSystemTriggerTypeSmsReceived = 1,
    WABSystemTriggerTypeUserPresent = 2,
    WABSystemTriggerTypeUserAway = 3,
    WABSystemTriggerTypeNetworkStateChange = 4,
    WABSystemTriggerTypeControlChannelReset = 5,
    WABSystemTriggerTypeInternetAvailable = 6,
    WABSystemTriggerTypeSessionConnected = 7,
    WABSystemTriggerTypeServicingComplete = 8,
    WABSystemTriggerTypeLockScreenApplicationAdded = 9,
    WABSystemTriggerTypeLockScreenApplicationRemoved = 10,
    WABSystemTriggerTypeTimeZoneChange = 11,
    WABSystemTriggerTypeOnlineIdConnectedStateChange = 12,
    WABSystemTriggerTypeBackgroundWorkCostChange = 13,
};
typedef unsigned WABSystemTriggerType;

// Windows.ApplicationModel.Background.SystemConditionType
enum _WABSystemConditionType {
    WABSystemConditionTypeInvalid = 0,
    WABSystemConditionTypeUserPresent = 1,
    WABSystemConditionTypeUserNotPresent = 2,
    WABSystemConditionTypeInternetAvailable = 3,
    WABSystemConditionTypeInternetNotAvailable = 4,
    WABSystemConditionTypeSessionConnected = 5,
    WABSystemConditionTypeSessionDisconnected = 6,
    WABSystemConditionTypeFreeNetworkAvailable = 7,
    WABSystemConditionTypeBackgroundWorkCostNotHigh = 8,
};
typedef unsigned WABSystemConditionType;

// Windows.ApplicationModel.Background.DeviceTriggerResult
enum _WABDeviceTriggerResult {
    WABDeviceTriggerResultAllowed = 0,
    WABDeviceTriggerResultDeniedByUser = 1,
    WABDeviceTriggerResultDeniedBySystem = 2,
    WABDeviceTriggerResultLowBattery = 3,
};
typedef unsigned WABDeviceTriggerResult;

// Windows.ApplicationModel.Background.LocationTriggerType
enum _WABLocationTriggerType {
    WABLocationTriggerTypeGeofence = 0,
};
typedef unsigned WABLocationTriggerType;

#include "WindowsFoundation.h"
#include "WindowsFoundationCollections.h"
// Windows.ApplicationModel.Background.BackgroundTaskCanceledEventHandler
#ifndef __WABBackgroundTaskCanceledEventHandler__DEFINED
#define __WABBackgroundTaskCanceledEventHandler__DEFINED
typedef void (^WABBackgroundTaskCanceledEventHandler)(RTObject<WABIBackgroundTaskInstance>* sender,
                                                      WABBackgroundTaskCancellationReason reason);
#endif // __WABBackgroundTaskCanceledEventHandler__DEFINED

// Windows.ApplicationModel.Background.BackgroundTaskCompletedEventHandler
#ifndef __WABBackgroundTaskCompletedEventHandler__DEFINED
#define __WABBackgroundTaskCompletedEventHandler__DEFINED
typedef void (^WABBackgroundTaskCompletedEventHandler)(WABBackgroundTaskRegistration* sender, WABBackgroundTaskCompletedEventArgs* args);
#endif // __WABBackgroundTaskCompletedEventHandler__DEFINED

// Windows.ApplicationModel.Background.BackgroundTaskProgressEventHandler
#ifndef __WABBackgroundTaskProgressEventHandler__DEFINED
#define __WABBackgroundTaskProgressEventHandler__DEFINED
typedef void (^WABBackgroundTaskProgressEventHandler)(WABBackgroundTaskRegistration* sender, WABBackgroundTaskProgressEventArgs* args);
#endif // __WABBackgroundTaskProgressEventHandler__DEFINED

// Windows.ApplicationModel.Background.BackgroundTaskCanceledEventHandler
#ifndef __WABBackgroundTaskCanceledEventHandler__DEFINED
#define __WABBackgroundTaskCanceledEventHandler__DEFINED
typedef void (^WABBackgroundTaskCanceledEventHandler)(RTObject<WABIBackgroundTaskInstance>* sender,
                                                      WABBackgroundTaskCancellationReason reason);
#endif // __WABBackgroundTaskCanceledEventHandler__DEFINED

// Windows.ApplicationModel.Background.BackgroundTaskProgressEventHandler
#ifndef __WABBackgroundTaskProgressEventHandler__DEFINED
#define __WABBackgroundTaskProgressEventHandler__DEFINED
typedef void (^WABBackgroundTaskProgressEventHandler)(WABBackgroundTaskRegistration* sender, WABBackgroundTaskProgressEventArgs* args);
#endif // __WABBackgroundTaskProgressEventHandler__DEFINED

// Windows.ApplicationModel.Background.BackgroundTaskCompletedEventHandler
#ifndef __WABBackgroundTaskCompletedEventHandler__DEFINED
#define __WABBackgroundTaskCompletedEventHandler__DEFINED
typedef void (^WABBackgroundTaskCompletedEventHandler)(WABBackgroundTaskRegistration* sender, WABBackgroundTaskCompletedEventArgs* args);
#endif // __WABBackgroundTaskCompletedEventHandler__DEFINED

// Windows.ApplicationModel.Background.IBackgroundTaskInstance
#ifndef __WABIBackgroundTaskInstance_DEFINED__
#define __WABIBackgroundTaskInstance_DEFINED__

@protocol WABIBackgroundTaskInstance
@property (readonly) WFGUID* instanceId;
@property unsigned progress;
@property (readonly) unsigned suspendedCount;
@property (readonly) WABBackgroundTaskRegistration* task;
@property (readonly) RTObject* triggerDetails;
- (EventRegistrationToken)addCanceledEvent:(WABBackgroundTaskCanceledEventHandler)del;
- (void)removeCanceledEvent:(EventRegistrationToken)tok;
- (WABBackgroundTaskDeferral*)getDeferral;
@end

#endif // __WABIBackgroundTaskInstance_DEFINED__

// Windows.ApplicationModel.Background.IBackgroundTaskInstance2
#ifndef __WABIBackgroundTaskInstance2_DEFINED__
#define __WABIBackgroundTaskInstance2_DEFINED__

@protocol WABIBackgroundTaskInstance2 <WABIBackgroundTaskInstance>
- (unsigned)getThrottleCount:(WABBackgroundTaskThrottleCounter)counter;
- (WABBackgroundTaskDeferral*)getDeferral;
@end

#endif // __WABIBackgroundTaskInstance2_DEFINED__

// Windows.ApplicationModel.Background.IBackgroundTask
#ifndef __WABIBackgroundTask_DEFINED__
#define __WABIBackgroundTask_DEFINED__

@protocol WABIBackgroundTask
- (void)run:(RTObject<WABIBackgroundTaskInstance>*)taskInstance;
@end

#endif // __WABIBackgroundTask_DEFINED__

// Windows.ApplicationModel.Background.IBackgroundTaskRegistration
#ifndef __WABIBackgroundTaskRegistration_DEFINED__
#define __WABIBackgroundTaskRegistration_DEFINED__

@protocol WABIBackgroundTaskRegistration
@property (readonly) NSString* name;
@property (readonly) WFGUID* taskId;
- (EventRegistrationToken)addCompletedEvent:(WABBackgroundTaskCompletedEventHandler)del;
- (void)removeCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addProgressEvent:(WABBackgroundTaskProgressEventHandler)del;
- (void)removeProgressEvent:(EventRegistrationToken)tok;
- (void)unregister:(BOOL)cancelTask;
@end

#endif // __WABIBackgroundTaskRegistration_DEFINED__

// Windows.ApplicationModel.Background.IBackgroundTrigger
#ifndef __WABIBackgroundTrigger_DEFINED__
#define __WABIBackgroundTrigger_DEFINED__

@protocol WABIBackgroundTrigger
@end

#endif // __WABIBackgroundTrigger_DEFINED__

// Windows.ApplicationModel.Background.IBackgroundCondition
#ifndef __WABIBackgroundCondition_DEFINED__
#define __WABIBackgroundCondition_DEFINED__

@protocol WABIBackgroundCondition
@end

#endif // __WABIBackgroundCondition_DEFINED__

// Windows.ApplicationModel.Background.AlarmApplicationManager
#ifndef __WABAlarmApplicationManager_DEFINED__
#define __WABAlarmApplicationManager_DEFINED__

WINRT_EXPORT
@interface WABAlarmApplicationManager : RTObject
+ (void)requestAccessAsyncWithSuccess:(void (^)(WABAlarmAccessStatus))success failure:(void (^)(NSError*))failure;
+ (WABAlarmAccessStatus)getAccessStatus;
@end

#endif // __WABAlarmApplicationManager_DEFINED__

// Windows.ApplicationModel.Background.BackgroundExecutionManager
#ifndef __WABBackgroundExecutionManager_DEFINED__
#define __WABBackgroundExecutionManager_DEFINED__

WINRT_EXPORT
@interface WABBackgroundExecutionManager : RTObject
+ (void)requestAccessAsyncWithSuccess:(void (^)(WABBackgroundAccessStatus))success failure:(void (^)(NSError*))failure;
+ (void)requestAccessForApplicationAsync:(NSString*)applicationId
                                 success:(void (^)(WABBackgroundAccessStatus))success
                                 failure:(void (^)(NSError*))failure;
+ (void)removeAccess;
+ (void)removeAccessForApplication:(NSString*)applicationId;
+ (WABBackgroundAccessStatus)getAccessStatus;
+ (WABBackgroundAccessStatus)getAccessStatusForApplication:(NSString*)applicationId;
@end

#endif // __WABBackgroundExecutionManager_DEFINED__

// Windows.ApplicationModel.Background.BackgroundTaskRegistration
#ifndef __WABBackgroundTaskRegistration_DEFINED__
#define __WABBackgroundTaskRegistration_DEFINED__

WINRT_EXPORT
@interface WABBackgroundTaskRegistration : RTObject <WABIBackgroundTaskRegistration>
@property (readonly) NSString* name;
@property (readonly) WFGUID* taskId;
+ (NSDictionary* /*GUID, WABIBackgroundTaskRegistration*/)allTasks;
- (EventRegistrationToken)addCompletedEvent:(WABBackgroundTaskCompletedEventHandler)del;
- (void)removeCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addProgressEvent:(WABBackgroundTaskProgressEventHandler)del;
- (void)removeProgressEvent:(EventRegistrationToken)tok;
- (void)unregister:(BOOL)cancelTask;
@end

#endif // __WABBackgroundTaskRegistration_DEFINED__

// Windows.ApplicationModel.Background.BackgroundTaskDeferral
#ifndef __WABBackgroundTaskDeferral_DEFINED__
#define __WABBackgroundTaskDeferral_DEFINED__

WINRT_EXPORT
@interface WABBackgroundTaskDeferral : RTObject
- (void)complete;
@end

#endif // __WABBackgroundTaskDeferral_DEFINED__

// Windows.ApplicationModel.Background.BackgroundTaskProgressEventArgs
#ifndef __WABBackgroundTaskProgressEventArgs_DEFINED__
#define __WABBackgroundTaskProgressEventArgs_DEFINED__

WINRT_EXPORT
@interface WABBackgroundTaskProgressEventArgs : RTObject
@property (readonly) WFGUID* instanceId;
@property (readonly) unsigned progress;
@end

#endif // __WABBackgroundTaskProgressEventArgs_DEFINED__

// Windows.ApplicationModel.Background.BackgroundTaskCompletedEventArgs
#ifndef __WABBackgroundTaskCompletedEventArgs_DEFINED__
#define __WABBackgroundTaskCompletedEventArgs_DEFINED__

WINRT_EXPORT
@interface WABBackgroundTaskCompletedEventArgs : RTObject
@property (readonly) WFGUID* instanceId;
- (void)checkResult;
@end

#endif // __WABBackgroundTaskCompletedEventArgs_DEFINED__

// Windows.ApplicationModel.Background.BackgroundTaskBuilder
#ifndef __WABBackgroundTaskBuilder_DEFINED__
#define __WABBackgroundTaskBuilder_DEFINED__

WINRT_EXPORT
@interface WABBackgroundTaskBuilder : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* taskEntryPoint;
@property (copy) NSString* name;
@property BOOL cancelOnConditionLoss;
- (void)setTrigger:(RTObject<WABIBackgroundTrigger>*)trigger;
- (void)addCondition:(RTObject<WABIBackgroundCondition>*)condition;
- (WABBackgroundTaskRegistration*)Register;
@end

#endif // __WABBackgroundTaskBuilder_DEFINED__

// Windows.ApplicationModel.Background.BackgroundWorkCost
#ifndef __WABBackgroundWorkCost_DEFINED__
#define __WABBackgroundWorkCost_DEFINED__

WINRT_EXPORT
@interface WABBackgroundWorkCost : RTObject
+ (WABBackgroundWorkCostValue)currentBackgroundWorkCost;
@end

#endif // __WABBackgroundWorkCost_DEFINED__

// Windows.ApplicationModel.Background.SystemTrigger
#ifndef __WABSystemTrigger_DEFINED__
#define __WABSystemTrigger_DEFINED__

WINRT_EXPORT
@interface WABSystemTrigger : RTObject <WABIBackgroundTrigger>
+ (WABSystemTrigger*)create:(WABSystemTriggerType)triggerType oneShot:(BOOL)oneShot ACTIVATOR;
@property (readonly) BOOL oneShot;
@property (readonly) WABSystemTriggerType triggerType;
@end

#endif // __WABSystemTrigger_DEFINED__

// Windows.ApplicationModel.Background.SystemCondition
#ifndef __WABSystemCondition_DEFINED__
#define __WABSystemCondition_DEFINED__

WINRT_EXPORT
@interface WABSystemCondition : RTObject <WABIBackgroundCondition>
+ (WABSystemCondition*)create:(WABSystemConditionType)conditionType ACTIVATOR;
@property (readonly) WABSystemConditionType conditionType;
@end

#endif // __WABSystemCondition_DEFINED__

// Windows.ApplicationModel.Background.NetworkOperatorNotificationTrigger
#ifndef __WABNetworkOperatorNotificationTrigger_DEFINED__
#define __WABNetworkOperatorNotificationTrigger_DEFINED__

WINRT_EXPORT
@interface WABNetworkOperatorNotificationTrigger : RTObject <WABIBackgroundTrigger>
+ (WABNetworkOperatorNotificationTrigger*)create:(NSString*)networkAccountId ACTIVATOR;
@property (readonly) NSString* networkAccountId;
@end

#endif // __WABNetworkOperatorNotificationTrigger_DEFINED__

// Windows.ApplicationModel.Background.TimeTrigger
#ifndef __WABTimeTrigger_DEFINED__
#define __WABTimeTrigger_DEFINED__

WINRT_EXPORT
@interface WABTimeTrigger : RTObject <WABIBackgroundTrigger>
+ (WABTimeTrigger*)create:(unsigned)freshnessTime oneShot:(BOOL)oneShot ACTIVATOR;
@property (readonly) unsigned freshnessTime;
@property (readonly) BOOL oneShot;
@end

#endif // __WABTimeTrigger_DEFINED__

// Windows.ApplicationModel.Background.MaintenanceTrigger
#ifndef __WABMaintenanceTrigger_DEFINED__
#define __WABMaintenanceTrigger_DEFINED__

WINRT_EXPORT
@interface WABMaintenanceTrigger : RTObject <WABIBackgroundTrigger>
+ (WABMaintenanceTrigger*)create:(unsigned)freshnessTime oneShot:(BOOL)oneShot ACTIVATOR;
@property (readonly) unsigned freshnessTime;
@property (readonly) BOOL oneShot;
@end

#endif // __WABMaintenanceTrigger_DEFINED__

// Windows.ApplicationModel.Background.DeviceUseTrigger
#ifndef __WABDeviceUseTrigger_DEFINED__
#define __WABDeviceUseTrigger_DEFINED__

WINRT_EXPORT
@interface WABDeviceUseTrigger : RTObject <WABIBackgroundTrigger>
+ (instancetype)create ACTIVATOR;
- (void)requestAsyncSimple:(NSString*)deviceId success:(void (^)(WABDeviceTriggerResult))success failure:(void (^)(NSError*))failure;
- (void)requestAsyncWithArguments:(NSString*)deviceId
                        arguments:(NSString*)arguments
                          success:(void (^)(WABDeviceTriggerResult))success
                          failure:(void (^)(NSError*))failure;
@end

#endif // __WABDeviceUseTrigger_DEFINED__

// Windows.ApplicationModel.Background.DeviceServicingTrigger
#ifndef __WABDeviceServicingTrigger_DEFINED__
#define __WABDeviceServicingTrigger_DEFINED__

WINRT_EXPORT
@interface WABDeviceServicingTrigger : RTObject <WABIBackgroundTrigger>
+ (instancetype)create ACTIVATOR;
- (void)requestAsyncSimple:(NSString*)deviceId
          expectedDuration:(WFTimeSpan*)expectedDuration
                   success:(void (^)(WABDeviceTriggerResult))success
                   failure:(void (^)(NSError*))failure;
- (void)requestAsyncWithArguments:(NSString*)deviceId
                 expectedDuration:(WFTimeSpan*)expectedDuration
                        arguments:(NSString*)arguments
                          success:(void (^)(WABDeviceTriggerResult))success
                          failure:(void (^)(NSError*))failure;
@end

#endif // __WABDeviceServicingTrigger_DEFINED__

// Windows.ApplicationModel.Background.LocationTrigger
#ifndef __WABLocationTrigger_DEFINED__
#define __WABLocationTrigger_DEFINED__

WINRT_EXPORT
@interface WABLocationTrigger : RTObject <WABIBackgroundTrigger>
+ (WABLocationTrigger*)create:(WABLocationTriggerType)triggerType ACTIVATOR;
@property (readonly) WABLocationTriggerType triggerType;
@end

#endif // __WABLocationTrigger_DEFINED__

// Windows.ApplicationModel.Background.NetworkOperatorHotspotAuthenticationTrigger
#ifndef __WABNetworkOperatorHotspotAuthenticationTrigger_DEFINED__
#define __WABNetworkOperatorHotspotAuthenticationTrigger_DEFINED__

WINRT_EXPORT
@interface WABNetworkOperatorHotspotAuthenticationTrigger : RTObject <WABIBackgroundTrigger>
+ (instancetype)create ACTIVATOR;
@end

#endif // __WABNetworkOperatorHotspotAuthenticationTrigger_DEFINED__

// Windows.ApplicationModel.Background.PushNotificationTrigger
#ifndef __WABPushNotificationTrigger_DEFINED__
#define __WABPushNotificationTrigger_DEFINED__

WINRT_EXPORT
@interface WABPushNotificationTrigger : RTObject <WABIBackgroundTrigger>
+ (WABPushNotificationTrigger*)create:(NSString*)applicationId ACTIVATOR;
+ (instancetype)create ACTIVATOR;
@end

#endif // __WABPushNotificationTrigger_DEFINED__
