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
@class WABAppointmentStoreNotificationTrigger, WABApplicationTrigger, WABApplicationTriggerDetails, WABBackgroundExecutionManager,
    WABMediaProcessingTrigger, WABBackgroundTaskRegistration, WABBackgroundTaskDeferral, WABBackgroundTaskProgressEventArgs,
    WABBackgroundTaskCompletedEventArgs, WABBackgroundTaskBuilder, WABBackgroundWorkCost, WABChatMessageNotificationTrigger,
    WABChatMessageReceivedNotificationTrigger, WABRcsEndUserMessageAvailableTrigger, WABContactStoreNotificationTrigger,
    WABContentPrefetchTrigger, WABEmailStoreNotificationTrigger, WABMobileBroadbandRegistrationStateChangeTrigger,
    WABMobileBroadbandRadioStateChangeTrigger, WABMobileBroadbandPinLockStateChangeTrigger,
    WABMobileBroadbandDeviceServiceNotificationTrigger, WABSmsMessageReceivedTrigger, WABStorageLibraryContentChangedTrigger,
    WABSystemTrigger, WABSystemCondition, WABNetworkOperatorNotificationTrigger, WABDeviceManufacturerNotificationTrigger,
    WABCachedFileUpdaterTriggerDetails, WABCachedFileUpdaterTrigger, WABTimeTrigger, WABMaintenanceTrigger, WABDeviceUseTrigger,
    WABDeviceServicingTrigger, WABRfcommConnectionTrigger, WABDeviceConnectionChangeTrigger, WABGattCharacteristicNotificationTrigger,
    WABBluetoothLEAdvertisementWatcherTrigger, WABBluetoothLEAdvertisementPublisherTrigger, WABDeviceWatcherTrigger, WABLocationTrigger,
    WABActivitySensorTrigger, WABNetworkOperatorHotspotAuthenticationTrigger, WABSocketActivityTrigger, WABPushNotificationTrigger,
    WABToastNotificationHistoryChangedTrigger, WABToastNotificationActionTrigger;
@protocol WABIApplicationTriggerDetails
, WABIBackgroundExecutionManagerStatics, WABIBackgroundTaskInstance, WABIBackgroundWorkCostStatics, WABIBackgroundTaskDeferral,
    WABIBackgroundTaskInstance2, WABIBackgroundTask, WABIBackgroundTaskRegistration, WABIBackgroundTaskRegistration2, WABIBackgroundTrigger,
    WABIAppointmentStoreNotificationTrigger, WABIApplicationTrigger, WABIMediaProcessingTrigger, WABIBackgroundTaskRegistrationStatics,
    WABIBackgroundTaskBuilder, WABIBackgroundCondition, WABIBackgroundTaskBuilder2, WABIBackgroundTaskBuilder3,
    WABIBackgroundTaskCompletedEventArgs, WABIBackgroundTaskProgressEventArgs, WABIChatMessageNotificationTrigger,
    WABIChatMessageReceivedNotificationTrigger, WABIRcsEndUserMessageAvailableTrigger, WABIContactStoreNotificationTrigger,
    WABIContentPrefetchTrigger, WABIContentPrefetchTriggerFactory, WABIEmailStoreNotificationTrigger, WABISmsMessageReceivedTriggerFactory,
    WABIStorageLibraryContentChangedTrigger, WABIStorageLibraryContentChangedTriggerStatics, WABISystemTrigger, WABISystemTriggerFactory,
    WABISystemCondition, WABISystemConditionFactory, WABINetworkOperatorNotificationTrigger, WABINetworkOperatorNotificationTriggerFactory,
    WABIDeviceManufacturerNotificationTrigger, WABIDeviceManufacturerNotificationTriggerFactory, WABICachedFileUpdaterTriggerDetails,
    WABICachedFileUpdaterTrigger, WABITimeTrigger, WABITimeTriggerFactory, WABIMaintenanceTrigger, WABIMaintenanceTriggerFactory,
    WABIDeviceUseTrigger, WABIDeviceServicingTrigger, WABIRfcommConnectionTrigger, WABIDeviceConnectionChangeTrigger,
    WABIDeviceConnectionChangeTriggerStatics, WABIGattCharacteristicNotificationTrigger, WABIGattCharacteristicNotificationTriggerFactory,
    WABIBluetoothLEAdvertisementWatcherTrigger, WABIBluetoothLEAdvertisementPublisherTrigger, WABIDeviceWatcherTrigger, WABILocationTrigger,
    WABILocationTriggerFactory, WABIActivitySensorTrigger, WABIActivitySensorTriggerFactory,
    WABINetworkOperatorHotspotAuthenticationTrigger, WABIPushNotificationTriggerFactory, WABIToastNotificationHistoryChangedTriggerFactory,
    WABIToastNotificationActionTriggerFactory;

// Windows.ApplicationModel.Background.ApplicationTriggerResult
enum _WABApplicationTriggerResult {
    WABApplicationTriggerResultAllowed = 0,
    WABApplicationTriggerResultCurrentlyRunning = 1,
    WABApplicationTriggerResultDisabledByPolicy = 2,
    WABApplicationTriggerResultUnknownError = 3,
};
typedef unsigned WABApplicationTriggerResult;

// Windows.ApplicationModel.Background.BackgroundAccessStatus
enum _WABBackgroundAccessStatus {
    WABBackgroundAccessStatusUnspecified = 0,
    WABBackgroundAccessStatusAllowedWithAlwaysOnRealTimeConnectivity = 1,
    WABBackgroundAccessStatusAllowedMayUseActiveRealTimeConnectivity = 2,
    WABBackgroundAccessStatusDenied = 3,
};
typedef unsigned WABBackgroundAccessStatus;

// Windows.ApplicationModel.Background.MediaProcessingTriggerResult
enum _WABMediaProcessingTriggerResult {
    WABMediaProcessingTriggerResultAllowed = 0,
    WABMediaProcessingTriggerResultCurrentlyRunning = 1,
    WABMediaProcessingTriggerResultDisabledByPolicy = 2,
    WABMediaProcessingTriggerResultUnknownError = 3,
};
typedef unsigned WABMediaProcessingTriggerResult;

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
    WABBackgroundTaskCancellationReasonExecutionTimeExceeded = 9,
    WABBackgroundTaskCancellationReasonResourceRevocation = 10,
    WABBackgroundTaskCancellationReasonEnergySaver = 11,
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
    WABSystemTriggerTypePowerStateChange = 14,
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

#include "WindowsDevicesSms.h"
#include "WindowsFoundationCollections.h"
#include "WindowsDevicesBluetooth.h"
#include "WindowsDevicesBluetoothBackground.h"
#include "WindowsFoundation.h"
#include "WindowsStorage.h"
#include "WindowsNetworking.h"
#include "WindowsNetworkingSockets.h"
#include "WindowsStorageProvider.h"
#include "WindowsDevicesBluetoothGenericAttributeProfile.h"
#include "WindowsDevicesBluetoothAdvertisement.h"
#include "WindowsDevicesSensors.h"
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

#import <Foundation/Foundation.h>

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
@property unsigned int progress;
@property (readonly) unsigned int suspendedCount;
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
- (unsigned int)getThrottleCount:(WABBackgroundTaskThrottleCounter)counter;
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

// Windows.ApplicationModel.Background.IBackgroundTaskRegistration2
#ifndef __WABIBackgroundTaskRegistration2_DEFINED__
#define __WABIBackgroundTaskRegistration2_DEFINED__

@protocol WABIBackgroundTaskRegistration2 <WABIBackgroundTaskRegistration>
@property (readonly) RTObject<WABIBackgroundTrigger>* trigger;
- (void)unregister:(BOOL)cancelTask;
@end

#endif // __WABIBackgroundTaskRegistration2_DEFINED__

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

// Windows.ApplicationModel.Background.AppointmentStoreNotificationTrigger
#ifndef __WABAppointmentStoreNotificationTrigger_DEFINED__
#define __WABAppointmentStoreNotificationTrigger_DEFINED__

WINRT_EXPORT
@interface WABAppointmentStoreNotificationTrigger : RTObject <WABIBackgroundTrigger>
+ (instancetype)create ACTIVATOR;
@end

#endif // __WABAppointmentStoreNotificationTrigger_DEFINED__

// Windows.ApplicationModel.Background.ApplicationTrigger
#ifndef __WABApplicationTrigger_DEFINED__
#define __WABApplicationTrigger_DEFINED__

WINRT_EXPORT
@interface WABApplicationTrigger : RTObject <WABIBackgroundTrigger>
+ (instancetype)create ACTIVATOR;
- (void)requestAsyncWithSuccess:(void (^)(WABApplicationTriggerResult))success failure:(void (^)(NSError*))failure;
- (void)requestAsyncWithArguments:(WFCValueSet*)arguments
                          success:(void (^)(WABApplicationTriggerResult))success
                          failure:(void (^)(NSError*))failure;
@end

#endif // __WABApplicationTrigger_DEFINED__

// Windows.ApplicationModel.Background.ApplicationTriggerDetails
#ifndef __WABApplicationTriggerDetails_DEFINED__
#define __WABApplicationTriggerDetails_DEFINED__

WINRT_EXPORT
@interface WABApplicationTriggerDetails : RTObject
@property (readonly) WFCValueSet* arguments;
@end

#endif // __WABApplicationTriggerDetails_DEFINED__

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

// Windows.ApplicationModel.Background.MediaProcessingTrigger
#ifndef __WABMediaProcessingTrigger_DEFINED__
#define __WABMediaProcessingTrigger_DEFINED__

WINRT_EXPORT
@interface WABMediaProcessingTrigger : RTObject <WABIBackgroundTrigger>
+ (instancetype)create ACTIVATOR;
- (void)requestAsyncWithSuccess:(void (^)(WABMediaProcessingTriggerResult))success failure:(void (^)(NSError*))failure;
- (void)requestAsyncWithArguments:(WFCValueSet*)arguments
                          success:(void (^)(WABMediaProcessingTriggerResult))success
                          failure:(void (^)(NSError*))failure;
@end

#endif // __WABMediaProcessingTrigger_DEFINED__

// Windows.ApplicationModel.Background.BackgroundTaskRegistration
#ifndef __WABBackgroundTaskRegistration_DEFINED__
#define __WABBackgroundTaskRegistration_DEFINED__

WINRT_EXPORT
@interface WABBackgroundTaskRegistration : RTObject <WABIBackgroundTaskRegistration, WABIBackgroundTaskRegistration2>
@property (readonly) NSString* name;
@property (readonly) WFGUID* taskId;
@property (readonly) RTObject<WABIBackgroundTrigger>* trigger;
+ (NSDictionary*)allTasks;
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
@property (readonly) unsigned int progress;
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
@property BOOL isNetworkRequested;
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

// Windows.ApplicationModel.Background.ChatMessageNotificationTrigger
#ifndef __WABChatMessageNotificationTrigger_DEFINED__
#define __WABChatMessageNotificationTrigger_DEFINED__

WINRT_EXPORT
@interface WABChatMessageNotificationTrigger : RTObject <WABIBackgroundTrigger>
+ (instancetype)create ACTIVATOR;
@end

#endif // __WABChatMessageNotificationTrigger_DEFINED__

// Windows.ApplicationModel.Background.ChatMessageReceivedNotificationTrigger
#ifndef __WABChatMessageReceivedNotificationTrigger_DEFINED__
#define __WABChatMessageReceivedNotificationTrigger_DEFINED__

WINRT_EXPORT
@interface WABChatMessageReceivedNotificationTrigger : RTObject <WABIBackgroundTrigger>
+ (instancetype)create ACTIVATOR;
@end

#endif // __WABChatMessageReceivedNotificationTrigger_DEFINED__

// Windows.ApplicationModel.Background.RcsEndUserMessageAvailableTrigger
#ifndef __WABRcsEndUserMessageAvailableTrigger_DEFINED__
#define __WABRcsEndUserMessageAvailableTrigger_DEFINED__

WINRT_EXPORT
@interface WABRcsEndUserMessageAvailableTrigger : RTObject <WABIBackgroundTrigger>
+ (instancetype)create ACTIVATOR;
@end

#endif // __WABRcsEndUserMessageAvailableTrigger_DEFINED__

// Windows.ApplicationModel.Background.ContactStoreNotificationTrigger
#ifndef __WABContactStoreNotificationTrigger_DEFINED__
#define __WABContactStoreNotificationTrigger_DEFINED__

WINRT_EXPORT
@interface WABContactStoreNotificationTrigger : RTObject <WABIBackgroundTrigger>
+ (instancetype)create ACTIVATOR;
@end

#endif // __WABContactStoreNotificationTrigger_DEFINED__

// Windows.ApplicationModel.Background.ContentPrefetchTrigger
#ifndef __WABContentPrefetchTrigger_DEFINED__
#define __WABContentPrefetchTrigger_DEFINED__

WINRT_EXPORT
@interface WABContentPrefetchTrigger : RTObject <WABIBackgroundTrigger>
+ (instancetype)create ACTIVATOR;
+ (WABContentPrefetchTrigger*)create:(WFTimeSpan*)waitInterval ACTIVATOR;
@property (readonly) WFTimeSpan* waitInterval;
@end

#endif // __WABContentPrefetchTrigger_DEFINED__

// Windows.ApplicationModel.Background.EmailStoreNotificationTrigger
#ifndef __WABEmailStoreNotificationTrigger_DEFINED__
#define __WABEmailStoreNotificationTrigger_DEFINED__

WINRT_EXPORT
@interface WABEmailStoreNotificationTrigger : RTObject <WABIBackgroundTrigger>
+ (instancetype)create ACTIVATOR;
@end

#endif // __WABEmailStoreNotificationTrigger_DEFINED__

// Windows.ApplicationModel.Background.MobileBroadbandRegistrationStateChangeTrigger
#ifndef __WABMobileBroadbandRegistrationStateChangeTrigger_DEFINED__
#define __WABMobileBroadbandRegistrationStateChangeTrigger_DEFINED__

WINRT_EXPORT
@interface WABMobileBroadbandRegistrationStateChangeTrigger : RTObject <WABIBackgroundTrigger>
+ (instancetype)create ACTIVATOR;
@end

#endif // __WABMobileBroadbandRegistrationStateChangeTrigger_DEFINED__

// Windows.ApplicationModel.Background.MobileBroadbandRadioStateChangeTrigger
#ifndef __WABMobileBroadbandRadioStateChangeTrigger_DEFINED__
#define __WABMobileBroadbandRadioStateChangeTrigger_DEFINED__

WINRT_EXPORT
@interface WABMobileBroadbandRadioStateChangeTrigger : RTObject <WABIBackgroundTrigger>
+ (instancetype)create ACTIVATOR;
@end

#endif // __WABMobileBroadbandRadioStateChangeTrigger_DEFINED__

// Windows.ApplicationModel.Background.MobileBroadbandPinLockStateChangeTrigger
#ifndef __WABMobileBroadbandPinLockStateChangeTrigger_DEFINED__
#define __WABMobileBroadbandPinLockStateChangeTrigger_DEFINED__

WINRT_EXPORT
@interface WABMobileBroadbandPinLockStateChangeTrigger : RTObject <WABIBackgroundTrigger>
+ (instancetype)create ACTIVATOR;
@end

#endif // __WABMobileBroadbandPinLockStateChangeTrigger_DEFINED__

// Windows.ApplicationModel.Background.MobileBroadbandDeviceServiceNotificationTrigger
#ifndef __WABMobileBroadbandDeviceServiceNotificationTrigger_DEFINED__
#define __WABMobileBroadbandDeviceServiceNotificationTrigger_DEFINED__

WINRT_EXPORT
@interface WABMobileBroadbandDeviceServiceNotificationTrigger : RTObject <WABIBackgroundTrigger>
+ (instancetype)create ACTIVATOR;
@end

#endif // __WABMobileBroadbandDeviceServiceNotificationTrigger_DEFINED__

// Windows.ApplicationModel.Background.SmsMessageReceivedTrigger
#ifndef __WABSmsMessageReceivedTrigger_DEFINED__
#define __WABSmsMessageReceivedTrigger_DEFINED__

WINRT_EXPORT
@interface WABSmsMessageReceivedTrigger : RTObject <WABIBackgroundTrigger>
+ (WABSmsMessageReceivedTrigger*)create:(WDSSmsFilterRules*)filterRules ACTIVATOR;
@end

#endif // __WABSmsMessageReceivedTrigger_DEFINED__

// Windows.ApplicationModel.Background.StorageLibraryContentChangedTrigger
#ifndef __WABStorageLibraryContentChangedTrigger_DEFINED__
#define __WABStorageLibraryContentChangedTrigger_DEFINED__

WINRT_EXPORT
@interface WABStorageLibraryContentChangedTrigger : RTObject <WABIBackgroundTrigger>
+ (WABStorageLibraryContentChangedTrigger*)create:(WSStorageLibrary*)storageLibrary;
+ (WABStorageLibraryContentChangedTrigger*)createFromLibraries:(id<NSFastEnumeration> /* WSStorageLibrary* */)storageLibraries;
@end

#endif // __WABStorageLibraryContentChangedTrigger_DEFINED__

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

// Windows.ApplicationModel.Background.DeviceManufacturerNotificationTrigger
#ifndef __WABDeviceManufacturerNotificationTrigger_DEFINED__
#define __WABDeviceManufacturerNotificationTrigger_DEFINED__

WINRT_EXPORT
@interface WABDeviceManufacturerNotificationTrigger : RTObject <WABIBackgroundTrigger>
+ (WABDeviceManufacturerNotificationTrigger*)create:(NSString*)triggerQualifier oneShot:(BOOL)oneShot ACTIVATOR;
@property (readonly) BOOL oneShot;
@property (readonly) NSString* triggerQualifier;
@end

#endif // __WABDeviceManufacturerNotificationTrigger_DEFINED__

// Windows.ApplicationModel.Background.CachedFileUpdaterTriggerDetails
#ifndef __WABCachedFileUpdaterTriggerDetails_DEFINED__
#define __WABCachedFileUpdaterTriggerDetails_DEFINED__

WINRT_EXPORT
@interface WABCachedFileUpdaterTriggerDetails : RTObject
@property (readonly) BOOL canRequestUserInput;
@property (readonly) WSPFileUpdateRequest* updateRequest;
@property (readonly) WSPCachedFileTarget updateTarget;
@end

#endif // __WABCachedFileUpdaterTriggerDetails_DEFINED__

// Windows.ApplicationModel.Background.CachedFileUpdaterTrigger
#ifndef __WABCachedFileUpdaterTrigger_DEFINED__
#define __WABCachedFileUpdaterTrigger_DEFINED__

WINRT_EXPORT
@interface WABCachedFileUpdaterTrigger : RTObject <WABIBackgroundTrigger>
+ (instancetype)create ACTIVATOR;
@end

#endif // __WABCachedFileUpdaterTrigger_DEFINED__

// Windows.ApplicationModel.Background.TimeTrigger
#ifndef __WABTimeTrigger_DEFINED__
#define __WABTimeTrigger_DEFINED__

WINRT_EXPORT
@interface WABTimeTrigger : RTObject <WABIBackgroundTrigger>
+ (WABTimeTrigger*)create:(unsigned int)freshnessTime oneShot:(BOOL)oneShot ACTIVATOR;
@property (readonly) unsigned int freshnessTime;
@property (readonly) BOOL oneShot;
@end

#endif // __WABTimeTrigger_DEFINED__

// Windows.ApplicationModel.Background.MaintenanceTrigger
#ifndef __WABMaintenanceTrigger_DEFINED__
#define __WABMaintenanceTrigger_DEFINED__

WINRT_EXPORT
@interface WABMaintenanceTrigger : RTObject <WABIBackgroundTrigger>
+ (WABMaintenanceTrigger*)create:(unsigned int)freshnessTime oneShot:(BOOL)oneShot ACTIVATOR;
@property (readonly) unsigned int freshnessTime;
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

// Windows.ApplicationModel.Background.RfcommConnectionTrigger
#ifndef __WABRfcommConnectionTrigger_DEFINED__
#define __WABRfcommConnectionTrigger_DEFINED__

WINRT_EXPORT
@interface WABRfcommConnectionTrigger : RTObject <WABIBackgroundTrigger>
+ (instancetype)create ACTIVATOR;
@property (copy) WNHostName* remoteHostName;
@property WNSSocketProtectionLevel protectionLevel;
@property BOOL allowMultipleConnections;
@property (readonly) WDBBRfcommInboundConnectionInformation* inboundConnection;
@property (readonly) WDBBRfcommOutboundConnectionInformation* outboundConnection;
@end

#endif // __WABRfcommConnectionTrigger_DEFINED__

// Windows.ApplicationModel.Background.DeviceConnectionChangeTrigger
#ifndef __WABDeviceConnectionChangeTrigger_DEFINED__
#define __WABDeviceConnectionChangeTrigger_DEFINED__

WINRT_EXPORT
@interface WABDeviceConnectionChangeTrigger : RTObject <WABIBackgroundTrigger>
+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WABDeviceConnectionChangeTrigger*))success failure:(void (^)(NSError*))failure;
@property BOOL maintainConnection;
@property (readonly) BOOL canMaintainConnection;
@property (readonly) NSString* deviceId;
@end

#endif // __WABDeviceConnectionChangeTrigger_DEFINED__

// Windows.ApplicationModel.Background.GattCharacteristicNotificationTrigger
#ifndef __WABGattCharacteristicNotificationTrigger_DEFINED__
#define __WABGattCharacteristicNotificationTrigger_DEFINED__

WINRT_EXPORT
@interface WABGattCharacteristicNotificationTrigger : RTObject <WABIBackgroundTrigger>
+ (WABGattCharacteristicNotificationTrigger*)create:(WDBGGattCharacteristic*)characteristic ACTIVATOR;
@property (readonly) WDBGGattCharacteristic* characteristic;
@end

#endif // __WABGattCharacteristicNotificationTrigger_DEFINED__

// Windows.ApplicationModel.Background.BluetoothLEAdvertisementWatcherTrigger
#ifndef __WABBluetoothLEAdvertisementWatcherTrigger_DEFINED__
#define __WABBluetoothLEAdvertisementWatcherTrigger_DEFINED__

WINRT_EXPORT
@interface WABBluetoothLEAdvertisementWatcherTrigger : RTObject <WABIBackgroundTrigger>
+ (instancetype)create ACTIVATOR;
@property (copy) WDBBluetoothSignalStrengthFilter* signalStrengthFilter;
@property (copy) WDBABluetoothLEAdvertisementFilter* advertisementFilter;
@property (readonly) WFTimeSpan* maxOutOfRangeTimeout;
@property (readonly) WFTimeSpan* maxSamplingInterval;
@property (readonly) WFTimeSpan* minOutOfRangeTimeout;
@property (readonly) WFTimeSpan* minSamplingInterval;
@end

#endif // __WABBluetoothLEAdvertisementWatcherTrigger_DEFINED__

// Windows.ApplicationModel.Background.BluetoothLEAdvertisementPublisherTrigger
#ifndef __WABBluetoothLEAdvertisementPublisherTrigger_DEFINED__
#define __WABBluetoothLEAdvertisementPublisherTrigger_DEFINED__

WINRT_EXPORT
@interface WABBluetoothLEAdvertisementPublisherTrigger : RTObject <WABIBackgroundTrigger>
+ (instancetype)create ACTIVATOR;
@property (readonly) WDBABluetoothLEAdvertisement* advertisement;
@end

#endif // __WABBluetoothLEAdvertisementPublisherTrigger_DEFINED__

// Windows.ApplicationModel.Background.DeviceWatcherTrigger
#ifndef __WABDeviceWatcherTrigger_DEFINED__
#define __WABDeviceWatcherTrigger_DEFINED__

WINRT_EXPORT
@interface WABDeviceWatcherTrigger : RTObject <WABIBackgroundTrigger>
@end

#endif // __WABDeviceWatcherTrigger_DEFINED__

// Windows.ApplicationModel.Background.LocationTrigger
#ifndef __WABLocationTrigger_DEFINED__
#define __WABLocationTrigger_DEFINED__

WINRT_EXPORT
@interface WABLocationTrigger : RTObject <WABIBackgroundTrigger>
+ (WABLocationTrigger*)create:(WABLocationTriggerType)triggerType ACTIVATOR;
@property (readonly) WABLocationTriggerType triggerType;
@end

#endif // __WABLocationTrigger_DEFINED__

// Windows.ApplicationModel.Background.ActivitySensorTrigger
#ifndef __WABActivitySensorTrigger_DEFINED__
#define __WABActivitySensorTrigger_DEFINED__

WINRT_EXPORT
@interface WABActivitySensorTrigger : RTObject <WABIBackgroundTrigger>
+ (WABActivitySensorTrigger*)create:(unsigned int)reportIntervalInMilliseconds ACTIVATOR;
@property (readonly) unsigned int minimumReportInterval;
@property (readonly) unsigned int reportInterval;
@property (readonly) NSMutableArray* subscribedActivities;
@property (readonly) NSArray* supportedActivities;
@end

#endif // __WABActivitySensorTrigger_DEFINED__

// Windows.ApplicationModel.Background.NetworkOperatorHotspotAuthenticationTrigger
#ifndef __WABNetworkOperatorHotspotAuthenticationTrigger_DEFINED__
#define __WABNetworkOperatorHotspotAuthenticationTrigger_DEFINED__

WINRT_EXPORT
@interface WABNetworkOperatorHotspotAuthenticationTrigger : RTObject <WABIBackgroundTrigger>
+ (instancetype)create ACTIVATOR;
@end

#endif // __WABNetworkOperatorHotspotAuthenticationTrigger_DEFINED__

// Windows.ApplicationModel.Background.SocketActivityTrigger
#ifndef __WABSocketActivityTrigger_DEFINED__
#define __WABSocketActivityTrigger_DEFINED__

WINRT_EXPORT
@interface WABSocketActivityTrigger : RTObject <WABIBackgroundTrigger>
+ (instancetype)create ACTIVATOR;
@end

#endif // __WABSocketActivityTrigger_DEFINED__

// Windows.ApplicationModel.Background.PushNotificationTrigger
#ifndef __WABPushNotificationTrigger_DEFINED__
#define __WABPushNotificationTrigger_DEFINED__

WINRT_EXPORT
@interface WABPushNotificationTrigger : RTObject <WABIBackgroundTrigger>
+ (instancetype)create ACTIVATOR;
+ (WABPushNotificationTrigger*)create:(NSString*)applicationId ACTIVATOR;
@end

#endif // __WABPushNotificationTrigger_DEFINED__

// Windows.ApplicationModel.Background.ToastNotificationHistoryChangedTrigger
#ifndef __WABToastNotificationHistoryChangedTrigger_DEFINED__
#define __WABToastNotificationHistoryChangedTrigger_DEFINED__

WINRT_EXPORT
@interface WABToastNotificationHistoryChangedTrigger : RTObject <WABIBackgroundTrigger>
+ (instancetype)create ACTIVATOR;
+ (WABToastNotificationHistoryChangedTrigger*)create:(NSString*)applicationId ACTIVATOR;
@end

#endif // __WABToastNotificationHistoryChangedTrigger_DEFINED__

// Windows.ApplicationModel.Background.ToastNotificationActionTrigger
#ifndef __WABToastNotificationActionTrigger_DEFINED__
#define __WABToastNotificationActionTrigger_DEFINED__

WINRT_EXPORT
@interface WABToastNotificationActionTrigger : RTObject <WABIBackgroundTrigger>
+ (instancetype)create ACTIVATOR;
+ (WABToastNotificationActionTrigger*)create:(NSString*)applicationId ACTIVATOR;
@end

#endif // __WABToastNotificationActionTrigger_DEFINED__
