// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::Background {

struct BackgroundTaskCanceledEventHandler;
struct BackgroundTaskCompletedEventHandler;
struct BackgroundTaskProgressEventHandler;
struct IActivitySensorTrigger;
struct IActivitySensorTriggerFactory;
struct IAlarmApplicationManagerStatics;
struct IApplicationTrigger;
struct IApplicationTriggerDetails;
struct IAppointmentStoreNotificationTrigger;
struct IBackgroundCondition;
struct IBackgroundExecutionManagerStatics;
struct IBackgroundTask;
struct IBackgroundTaskBuilder;
struct IBackgroundTaskBuilder2;
struct IBackgroundTaskBuilder3;
struct IBackgroundTaskCompletedEventArgs;
struct IBackgroundTaskDeferral;
struct IBackgroundTaskInstance;
struct IBackgroundTaskInstance2;
struct IBackgroundTaskInstance4;
struct IBackgroundTaskProgressEventArgs;
struct IBackgroundTaskRegistration;
struct IBackgroundTaskRegistration2;
struct IBackgroundTaskRegistrationStatics;
struct IBackgroundTrigger;
struct IBackgroundWorkCostStatics;
struct IBluetoothLEAdvertisementPublisherTrigger;
struct IBluetoothLEAdvertisementWatcherTrigger;
struct ICachedFileUpdaterTrigger;
struct ICachedFileUpdaterTriggerDetails;
struct IChatMessageNotificationTrigger;
struct IChatMessageReceivedNotificationTrigger;
struct ICommunicationBlockingAppSetAsActiveTrigger;
struct IContactStoreNotificationTrigger;
struct IContentPrefetchTrigger;
struct IContentPrefetchTriggerFactory;
struct IDeviceConnectionChangeTrigger;
struct IDeviceConnectionChangeTriggerStatics;
struct IDeviceManufacturerNotificationTrigger;
struct IDeviceManufacturerNotificationTriggerFactory;
struct IDeviceServicingTrigger;
struct IDeviceUseTrigger;
struct IDeviceWatcherTrigger;
struct IEmailStoreNotificationTrigger;
struct IGattCharacteristicNotificationTrigger;
struct IGattCharacteristicNotificationTriggerFactory;
struct ILocationTrigger;
struct ILocationTriggerFactory;
struct IMaintenanceTrigger;
struct IMaintenanceTriggerFactory;
struct IMediaProcessingTrigger;
struct INetworkOperatorHotspotAuthenticationTrigger;
struct INetworkOperatorNotificationTrigger;
struct INetworkOperatorNotificationTriggerFactory;
struct IPhoneTrigger;
struct IPhoneTriggerFactory;
struct IPushNotificationTriggerFactory;
struct IRcsEndUserMessageAvailableTrigger;
struct IRfcommConnectionTrigger;
struct ISecondaryAuthenticationFactorAuthenticationTrigger;
struct ISensorDataThresholdTrigger;
struct ISensorDataThresholdTriggerFactory;
struct ISmartCardTrigger;
struct ISmartCardTriggerFactory;
struct ISmsMessageReceivedTriggerFactory;
struct ISocketActivityTrigger;
struct IStorageLibraryContentChangedTrigger;
struct IStorageLibraryContentChangedTriggerStatics;
struct ISystemCondition;
struct ISystemConditionFactory;
struct ISystemTrigger;
struct ISystemTriggerFactory;
struct ITimeTrigger;
struct ITimeTriggerFactory;
struct IToastNotificationActionTriggerFactory;
struct IToastNotificationHistoryChangedTriggerFactory;
struct IUserNotificationChangedTriggerFactory;
struct ActivitySensorTrigger;
struct ApplicationTrigger;
struct ApplicationTriggerDetails;
struct AppointmentStoreNotificationTrigger;
struct BackgroundTaskBuilder;
struct BackgroundTaskCompletedEventArgs;
struct BackgroundTaskDeferral;
struct BackgroundTaskProgressEventArgs;
struct BackgroundTaskRegistration;
struct BluetoothLEAdvertisementPublisherTrigger;
struct BluetoothLEAdvertisementWatcherTrigger;
struct CachedFileUpdaterTrigger;
struct CachedFileUpdaterTriggerDetails;
struct ChatMessageNotificationTrigger;
struct ChatMessageReceivedNotificationTrigger;
struct CommunicationBlockingAppSetAsActiveTrigger;
struct ContactStoreNotificationTrigger;
struct ContentPrefetchTrigger;
struct DeviceConnectionChangeTrigger;
struct DeviceManufacturerNotificationTrigger;
struct DeviceServicingTrigger;
struct DeviceUseTrigger;
struct DeviceWatcherTrigger;
struct EmailStoreNotificationTrigger;
struct GattCharacteristicNotificationTrigger;
struct LocationTrigger;
struct MaintenanceTrigger;
struct MediaProcessingTrigger;
struct MobileBroadbandDeviceServiceNotificationTrigger;
struct MobileBroadbandPinLockStateChangeTrigger;
struct MobileBroadbandRadioStateChangeTrigger;
struct MobileBroadbandRegistrationStateChangeTrigger;
struct NetworkOperatorHotspotAuthenticationTrigger;
struct NetworkOperatorNotificationTrigger;
struct PhoneTrigger;
struct PushNotificationTrigger;
struct RcsEndUserMessageAvailableTrigger;
struct RfcommConnectionTrigger;
struct SecondaryAuthenticationFactorAuthenticationTrigger;
struct SensorDataThresholdTrigger;
struct SmartCardTrigger;
struct SmsMessageReceivedTrigger;
struct SocketActivityTrigger;
struct StorageLibraryContentChangedTrigger;
struct SystemCondition;
struct SystemTrigger;
struct TimeTrigger;
struct ToastNotificationActionTrigger;
struct ToastNotificationHistoryChangedTrigger;
struct UserNotificationChangedTrigger;

}

namespace Windows::ApplicationModel::Background {

struct BackgroundTaskCanceledEventHandler;
struct BackgroundTaskCompletedEventHandler;
struct BackgroundTaskProgressEventHandler;
struct IActivitySensorTrigger;
struct IActivitySensorTriggerFactory;
struct IAlarmApplicationManagerStatics;
struct IApplicationTrigger;
struct IApplicationTriggerDetails;
struct IAppointmentStoreNotificationTrigger;
struct IBackgroundCondition;
struct IBackgroundExecutionManagerStatics;
struct IBackgroundTask;
struct IBackgroundTaskBuilder;
struct IBackgroundTaskBuilder2;
struct IBackgroundTaskBuilder3;
struct IBackgroundTaskCompletedEventArgs;
struct IBackgroundTaskDeferral;
struct IBackgroundTaskInstance;
struct IBackgroundTaskInstance2;
struct IBackgroundTaskInstance4;
struct IBackgroundTaskProgressEventArgs;
struct IBackgroundTaskRegistration;
struct IBackgroundTaskRegistration2;
struct IBackgroundTaskRegistrationStatics;
struct IBackgroundTrigger;
struct IBackgroundWorkCostStatics;
struct IBluetoothLEAdvertisementPublisherTrigger;
struct IBluetoothLEAdvertisementWatcherTrigger;
struct ICachedFileUpdaterTrigger;
struct ICachedFileUpdaterTriggerDetails;
struct IChatMessageNotificationTrigger;
struct IChatMessageReceivedNotificationTrigger;
struct ICommunicationBlockingAppSetAsActiveTrigger;
struct IContactStoreNotificationTrigger;
struct IContentPrefetchTrigger;
struct IContentPrefetchTriggerFactory;
struct IDeviceConnectionChangeTrigger;
struct IDeviceConnectionChangeTriggerStatics;
struct IDeviceManufacturerNotificationTrigger;
struct IDeviceManufacturerNotificationTriggerFactory;
struct IDeviceServicingTrigger;
struct IDeviceUseTrigger;
struct IDeviceWatcherTrigger;
struct IEmailStoreNotificationTrigger;
struct IGattCharacteristicNotificationTrigger;
struct IGattCharacteristicNotificationTriggerFactory;
struct ILocationTrigger;
struct ILocationTriggerFactory;
struct IMaintenanceTrigger;
struct IMaintenanceTriggerFactory;
struct IMediaProcessingTrigger;
struct INetworkOperatorHotspotAuthenticationTrigger;
struct INetworkOperatorNotificationTrigger;
struct INetworkOperatorNotificationTriggerFactory;
struct IPhoneTrigger;
struct IPhoneTriggerFactory;
struct IPushNotificationTriggerFactory;
struct IRcsEndUserMessageAvailableTrigger;
struct IRfcommConnectionTrigger;
struct ISecondaryAuthenticationFactorAuthenticationTrigger;
struct ISensorDataThresholdTrigger;
struct ISensorDataThresholdTriggerFactory;
struct ISmartCardTrigger;
struct ISmartCardTriggerFactory;
struct ISmsMessageReceivedTriggerFactory;
struct ISocketActivityTrigger;
struct IStorageLibraryContentChangedTrigger;
struct IStorageLibraryContentChangedTriggerStatics;
struct ISystemCondition;
struct ISystemConditionFactory;
struct ISystemTrigger;
struct ISystemTriggerFactory;
struct ITimeTrigger;
struct ITimeTriggerFactory;
struct IToastNotificationActionTriggerFactory;
struct IToastNotificationHistoryChangedTriggerFactory;
struct IUserNotificationChangedTriggerFactory;
struct ActivitySensorTrigger;
struct AlarmApplicationManager;
struct ApplicationTrigger;
struct ApplicationTriggerDetails;
struct AppointmentStoreNotificationTrigger;
struct BackgroundExecutionManager;
struct BackgroundTaskBuilder;
struct BackgroundTaskCompletedEventArgs;
struct BackgroundTaskDeferral;
struct BackgroundTaskProgressEventArgs;
struct BackgroundTaskRegistration;
struct BackgroundWorkCost;
struct BluetoothLEAdvertisementPublisherTrigger;
struct BluetoothLEAdvertisementWatcherTrigger;
struct CachedFileUpdaterTrigger;
struct CachedFileUpdaterTriggerDetails;
struct ChatMessageNotificationTrigger;
struct ChatMessageReceivedNotificationTrigger;
struct CommunicationBlockingAppSetAsActiveTrigger;
struct ContactStoreNotificationTrigger;
struct ContentPrefetchTrigger;
struct DeviceConnectionChangeTrigger;
struct DeviceManufacturerNotificationTrigger;
struct DeviceServicingTrigger;
struct DeviceUseTrigger;
struct DeviceWatcherTrigger;
struct EmailStoreNotificationTrigger;
struct GattCharacteristicNotificationTrigger;
struct LocationTrigger;
struct MaintenanceTrigger;
struct MediaProcessingTrigger;
struct MobileBroadbandDeviceServiceNotificationTrigger;
struct MobileBroadbandPinLockStateChangeTrigger;
struct MobileBroadbandRadioStateChangeTrigger;
struct MobileBroadbandRegistrationStateChangeTrigger;
struct NetworkOperatorHotspotAuthenticationTrigger;
struct NetworkOperatorNotificationTrigger;
struct PhoneTrigger;
struct PushNotificationTrigger;
struct RcsEndUserMessageAvailableTrigger;
struct RfcommConnectionTrigger;
struct SecondaryAuthenticationFactorAuthenticationTrigger;
struct SensorDataThresholdTrigger;
struct SmartCardTrigger;
struct SmsMessageReceivedTrigger;
struct SocketActivityTrigger;
struct StorageLibraryContentChangedTrigger;
struct SystemCondition;
struct SystemTrigger;
struct TimeTrigger;
struct ToastNotificationActionTrigger;
struct ToastNotificationHistoryChangedTrigger;
struct UserNotificationChangedTrigger;

}

namespace Windows::ApplicationModel::Background {

template <typename T> struct impl_IActivitySensorTrigger;
template <typename T> struct impl_IActivitySensorTriggerFactory;
template <typename T> struct impl_IAlarmApplicationManagerStatics;
template <typename T> struct impl_IApplicationTrigger;
template <typename T> struct impl_IApplicationTriggerDetails;
template <typename T> struct impl_IAppointmentStoreNotificationTrigger;
template <typename T> struct impl_IBackgroundCondition;
template <typename T> struct impl_IBackgroundExecutionManagerStatics;
template <typename T> struct impl_IBackgroundTask;
template <typename T> struct impl_IBackgroundTaskBuilder;
template <typename T> struct impl_IBackgroundTaskBuilder2;
template <typename T> struct impl_IBackgroundTaskBuilder3;
template <typename T> struct impl_IBackgroundTaskCompletedEventArgs;
template <typename T> struct impl_IBackgroundTaskDeferral;
template <typename T> struct impl_IBackgroundTaskInstance;
template <typename T> struct impl_IBackgroundTaskInstance2;
template <typename T> struct impl_IBackgroundTaskInstance4;
template <typename T> struct impl_IBackgroundTaskProgressEventArgs;
template <typename T> struct impl_IBackgroundTaskRegistration;
template <typename T> struct impl_IBackgroundTaskRegistration2;
template <typename T> struct impl_IBackgroundTaskRegistrationStatics;
template <typename T> struct impl_IBackgroundTrigger;
template <typename T> struct impl_IBackgroundWorkCostStatics;
template <typename T> struct impl_IBluetoothLEAdvertisementPublisherTrigger;
template <typename T> struct impl_IBluetoothLEAdvertisementWatcherTrigger;
template <typename T> struct impl_ICachedFileUpdaterTrigger;
template <typename T> struct impl_ICachedFileUpdaterTriggerDetails;
template <typename T> struct impl_IChatMessageNotificationTrigger;
template <typename T> struct impl_IChatMessageReceivedNotificationTrigger;
template <typename T> struct impl_ICommunicationBlockingAppSetAsActiveTrigger;
template <typename T> struct impl_IContactStoreNotificationTrigger;
template <typename T> struct impl_IContentPrefetchTrigger;
template <typename T> struct impl_IContentPrefetchTriggerFactory;
template <typename T> struct impl_IDeviceConnectionChangeTrigger;
template <typename T> struct impl_IDeviceConnectionChangeTriggerStatics;
template <typename T> struct impl_IDeviceManufacturerNotificationTrigger;
template <typename T> struct impl_IDeviceManufacturerNotificationTriggerFactory;
template <typename T> struct impl_IDeviceServicingTrigger;
template <typename T> struct impl_IDeviceUseTrigger;
template <typename T> struct impl_IDeviceWatcherTrigger;
template <typename T> struct impl_IEmailStoreNotificationTrigger;
template <typename T> struct impl_IGattCharacteristicNotificationTrigger;
template <typename T> struct impl_IGattCharacteristicNotificationTriggerFactory;
template <typename T> struct impl_ILocationTrigger;
template <typename T> struct impl_ILocationTriggerFactory;
template <typename T> struct impl_IMaintenanceTrigger;
template <typename T> struct impl_IMaintenanceTriggerFactory;
template <typename T> struct impl_IMediaProcessingTrigger;
template <typename T> struct impl_INetworkOperatorHotspotAuthenticationTrigger;
template <typename T> struct impl_INetworkOperatorNotificationTrigger;
template <typename T> struct impl_INetworkOperatorNotificationTriggerFactory;
template <typename T> struct impl_IPhoneTrigger;
template <typename T> struct impl_IPhoneTriggerFactory;
template <typename T> struct impl_IPushNotificationTriggerFactory;
template <typename T> struct impl_IRcsEndUserMessageAvailableTrigger;
template <typename T> struct impl_IRfcommConnectionTrigger;
template <typename T> struct impl_ISecondaryAuthenticationFactorAuthenticationTrigger;
template <typename T> struct impl_ISensorDataThresholdTrigger;
template <typename T> struct impl_ISensorDataThresholdTriggerFactory;
template <typename T> struct impl_ISmartCardTrigger;
template <typename T> struct impl_ISmartCardTriggerFactory;
template <typename T> struct impl_ISmsMessageReceivedTriggerFactory;
template <typename T> struct impl_ISocketActivityTrigger;
template <typename T> struct impl_IStorageLibraryContentChangedTrigger;
template <typename T> struct impl_IStorageLibraryContentChangedTriggerStatics;
template <typename T> struct impl_ISystemCondition;
template <typename T> struct impl_ISystemConditionFactory;
template <typename T> struct impl_ISystemTrigger;
template <typename T> struct impl_ISystemTriggerFactory;
template <typename T> struct impl_ITimeTrigger;
template <typename T> struct impl_ITimeTriggerFactory;
template <typename T> struct impl_IToastNotificationActionTriggerFactory;
template <typename T> struct impl_IToastNotificationHistoryChangedTriggerFactory;
template <typename T> struct impl_IUserNotificationChangedTriggerFactory;
template <typename T> struct impl_BackgroundTaskCanceledEventHandler;
template <typename T> struct impl_BackgroundTaskCompletedEventHandler;
template <typename T> struct impl_BackgroundTaskProgressEventHandler;

}

namespace Windows::ApplicationModel::Background {

enum class AlarmAccessStatus
{
    Unspecified = 0,
    AllowedWithWakeupCapability = 1,
    AllowedWithoutWakeupCapability = 2,
    Denied = 3,
};

enum class ApplicationTriggerResult
{
    Allowed = 0,
    CurrentlyRunning = 1,
    DisabledByPolicy = 2,
    UnknownError = 3,
};

enum class BackgroundAccessStatus
{
    Unspecified = 0,
    AllowedWithAlwaysOnRealTimeConnectivity [[deprecated("Use AlwaysAllowed or AllowedSubjectToSystemPolicy instead of AllowedWithAlwaysOnRealTimeConnectivity. For more info, see MSDN.")]] = 1,
    AllowedMayUseActiveRealTimeConnectivity [[deprecated("Use AlwaysAllowed or AllowedSubjectToSystemPolicy instead of AllowedMayUseActiveRealTimeConnectivity. For more info, see MSDN.")]] = 2,
    Denied [[deprecated("Use DeniedByUser or DeniedBySystemPolicy instead of Denied. For more info, see MSDN.")]] = 3,
    AlwaysAllowed = 4,
    AllowedSubjectToSystemPolicy = 5,
    DeniedBySystemPolicy = 6,
    DeniedByUser = 7,
};

enum class BackgroundTaskCancellationReason
{
    Abort = 0,
    Terminating = 1,
    LoggingOff = 2,
    ServicingUpdate = 3,
    IdleTask = 4,
    Uninstall = 5,
    ConditionLoss = 6,
    SystemPolicy = 7,
    QuietHoursEntered [[deprecated("QuietHoursEntered is deprecated after Windows 8.1")]] = 8,
    ExecutionTimeExceeded = 9,
    ResourceRevocation = 10,
    EnergySaver = 11,
};

enum class BackgroundTaskThrottleCounter
{
    All = 0,
    Cpu = 1,
    Network = 2,
};

enum class BackgroundWorkCostValue
{
    Low = 0,
    Medium = 1,
    High = 2,
};

enum class DeviceTriggerResult
{
    Allowed = 0,
    DeniedByUser = 1,
    DeniedBySystem = 2,
    LowBattery = 3,
};

enum class LocationTriggerType
{
    Geofence = 0,
};

enum class MediaProcessingTriggerResult
{
    Allowed = 0,
    CurrentlyRunning = 1,
    DisabledByPolicy = 2,
    UnknownError = 3,
};

enum class SystemConditionType
{
    Invalid = 0,
    UserPresent = 1,
    UserNotPresent = 2,
    InternetAvailable = 3,
    InternetNotAvailable = 4,
    SessionConnected = 5,
    SessionDisconnected = 6,
    FreeNetworkAvailable = 7,
    BackgroundWorkCostNotHigh = 8,
};

enum class SystemTriggerType
{
    Invalid = 0,
    SmsReceived = 1,
    UserPresent = 2,
    UserAway = 3,
    NetworkStateChange = 4,
    ControlChannelReset = 5,
    InternetAvailable = 6,
    SessionConnected = 7,
    ServicingComplete = 8,
    LockScreenApplicationAdded = 9,
    LockScreenApplicationRemoved = 10,
    TimeZoneChange = 11,
    OnlineIdConnectedStateChange = 12,
    BackgroundWorkCostChange = 13,
    PowerStateChange = 14,
    DefaultSignInAccountChange = 15,
};

}

}
