// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.Background.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::Background {

template <typename H> struct impl_BackgroundTaskCanceledEventHandler : implements<impl_BackgroundTaskCanceledEventHandler<H>, abi<BackgroundTaskCanceledEventHandler>>, H
{
    impl_BackgroundTaskCanceledEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::ApplicationModel::Background::IBackgroundTaskInstance> sender, Windows::ApplicationModel::Background::BackgroundTaskCancellationReason reason) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::ApplicationModel::Background::IBackgroundTaskInstance *>(&sender), reason);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_BackgroundTaskCompletedEventHandler : implements<impl_BackgroundTaskCompletedEventHandler<H>, abi<BackgroundTaskCompletedEventHandler>>, H
{
    impl_BackgroundTaskCompletedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::ApplicationModel::Background::IBackgroundTaskRegistration> sender, impl::abi_arg_in<Windows::ApplicationModel::Background::IBackgroundTaskCompletedEventArgs> args) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::ApplicationModel::Background::BackgroundTaskRegistration *>(&sender), *reinterpret_cast<const Windows::ApplicationModel::Background::BackgroundTaskCompletedEventArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_BackgroundTaskProgressEventHandler : implements<impl_BackgroundTaskProgressEventHandler<H>, abi<BackgroundTaskProgressEventHandler>>, H
{
    impl_BackgroundTaskProgressEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::ApplicationModel::Background::IBackgroundTaskRegistration> sender, impl::abi_arg_in<Windows::ApplicationModel::Background::IBackgroundTaskProgressEventArgs> args) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::ApplicationModel::Background::BackgroundTaskRegistration *>(&sender), *reinterpret_cast<const Windows::ApplicationModel::Background::BackgroundTaskProgressEventArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::ApplicationModel::Background {

struct WINRT_EBO ActivitySensorTrigger :
    Windows::ApplicationModel::Background::IActivitySensorTrigger
{
    ActivitySensorTrigger(std::nullptr_t) noexcept {}
    ActivitySensorTrigger(uint32_t reportIntervalInMilliseconds);
};

struct AlarmApplicationManager
{
    AlarmApplicationManager() = delete;
    static Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::AlarmAccessStatus> RequestAccessAsync();
    static Windows::ApplicationModel::Background::AlarmAccessStatus GetAccessStatus();
};

struct WINRT_EBO ApplicationTrigger :
    Windows::ApplicationModel::Background::IApplicationTrigger
{
    ApplicationTrigger(std::nullptr_t) noexcept {}
    ApplicationTrigger();
};

struct WINRT_EBO ApplicationTriggerDetails :
    Windows::ApplicationModel::Background::IApplicationTriggerDetails
{
    ApplicationTriggerDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AppointmentStoreNotificationTrigger :
    Windows::ApplicationModel::Background::IAppointmentStoreNotificationTrigger
{
    AppointmentStoreNotificationTrigger(std::nullptr_t) noexcept {}
    AppointmentStoreNotificationTrigger();
};

struct BackgroundExecutionManager
{
    BackgroundExecutionManager() = delete;
    static Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::BackgroundAccessStatus> RequestAccessAsync();
    static Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::BackgroundAccessStatus> RequestAccessAsync(hstring_view applicationId);
    static void RemoveAccess();
    static void RemoveAccess(hstring_view applicationId);
    static Windows::ApplicationModel::Background::BackgroundAccessStatus GetAccessStatus();
    static Windows::ApplicationModel::Background::BackgroundAccessStatus GetAccessStatus(hstring_view applicationId);
};

struct WINRT_EBO BackgroundTaskBuilder :
    Windows::ApplicationModel::Background::IBackgroundTaskBuilder,
    impl::require<BackgroundTaskBuilder, Windows::ApplicationModel::Background::IBackgroundTaskBuilder2, Windows::ApplicationModel::Background::IBackgroundTaskBuilder3>
{
    BackgroundTaskBuilder(std::nullptr_t) noexcept {}
    BackgroundTaskBuilder();
};

struct WINRT_EBO BackgroundTaskCompletedEventArgs :
    Windows::ApplicationModel::Background::IBackgroundTaskCompletedEventArgs
{
    BackgroundTaskCompletedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO BackgroundTaskDeferral :
    Windows::ApplicationModel::Background::IBackgroundTaskDeferral
{
    BackgroundTaskDeferral(std::nullptr_t) noexcept {}
};

struct WINRT_EBO BackgroundTaskProgressEventArgs :
    Windows::ApplicationModel::Background::IBackgroundTaskProgressEventArgs
{
    BackgroundTaskProgressEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO BackgroundTaskRegistration :
    Windows::ApplicationModel::Background::IBackgroundTaskRegistration,
    impl::require<BackgroundTaskRegistration, Windows::ApplicationModel::Background::IBackgroundTaskRegistration2>
{
    BackgroundTaskRegistration(std::nullptr_t) noexcept {}
    static Windows::Foundation::Collections::IMapView<GUID, Windows::ApplicationModel::Background::IBackgroundTaskRegistration> AllTasks();
};

struct BackgroundWorkCost
{
    BackgroundWorkCost() = delete;
    static Windows::ApplicationModel::Background::BackgroundWorkCostValue CurrentBackgroundWorkCost();
};

struct WINRT_EBO BluetoothLEAdvertisementPublisherTrigger :
    Windows::ApplicationModel::Background::IBluetoothLEAdvertisementPublisherTrigger
{
    BluetoothLEAdvertisementPublisherTrigger(std::nullptr_t) noexcept {}
    BluetoothLEAdvertisementPublisherTrigger();
};

struct WINRT_EBO BluetoothLEAdvertisementWatcherTrigger :
    Windows::ApplicationModel::Background::IBluetoothLEAdvertisementWatcherTrigger
{
    BluetoothLEAdvertisementWatcherTrigger(std::nullptr_t) noexcept {}
    BluetoothLEAdvertisementWatcherTrigger();
};

struct WINRT_EBO CachedFileUpdaterTrigger :
    Windows::ApplicationModel::Background::ICachedFileUpdaterTrigger
{
    CachedFileUpdaterTrigger(std::nullptr_t) noexcept {}
    CachedFileUpdaterTrigger();
};

struct WINRT_EBO CachedFileUpdaterTriggerDetails :
    Windows::ApplicationModel::Background::ICachedFileUpdaterTriggerDetails
{
    CachedFileUpdaterTriggerDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ChatMessageNotificationTrigger :
    Windows::ApplicationModel::Background::IChatMessageNotificationTrigger
{
    ChatMessageNotificationTrigger(std::nullptr_t) noexcept {}
    ChatMessageNotificationTrigger();
};

struct WINRT_EBO ChatMessageReceivedNotificationTrigger :
    Windows::ApplicationModel::Background::IChatMessageReceivedNotificationTrigger
{
    ChatMessageReceivedNotificationTrigger(std::nullptr_t) noexcept {}
    ChatMessageReceivedNotificationTrigger();
};

struct WINRT_EBO CommunicationBlockingAppSetAsActiveTrigger :
    Windows::ApplicationModel::Background::ICommunicationBlockingAppSetAsActiveTrigger
{
    CommunicationBlockingAppSetAsActiveTrigger(std::nullptr_t) noexcept {}
    CommunicationBlockingAppSetAsActiveTrigger();
};

struct WINRT_EBO ContactStoreNotificationTrigger :
    Windows::ApplicationModel::Background::IContactStoreNotificationTrigger
{
    ContactStoreNotificationTrigger(std::nullptr_t) noexcept {}
    ContactStoreNotificationTrigger();
};

struct WINRT_EBO ContentPrefetchTrigger :
    Windows::ApplicationModel::Background::IContentPrefetchTrigger
{
    ContentPrefetchTrigger(std::nullptr_t) noexcept {}
    ContentPrefetchTrigger();
    ContentPrefetchTrigger(const Windows::Foundation::TimeSpan & waitInterval);
};

struct WINRT_EBO DeviceConnectionChangeTrigger :
    Windows::ApplicationModel::Background::IDeviceConnectionChangeTrigger
{
    DeviceConnectionChangeTrigger(std::nullptr_t) noexcept {}
    static Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Background::DeviceConnectionChangeTrigger> FromIdAsync(hstring_view deviceId);
};

struct WINRT_EBO DeviceManufacturerNotificationTrigger :
    Windows::ApplicationModel::Background::IDeviceManufacturerNotificationTrigger
{
    DeviceManufacturerNotificationTrigger(std::nullptr_t) noexcept {}
    DeviceManufacturerNotificationTrigger(hstring_view triggerQualifier, bool oneShot);
};

struct WINRT_EBO DeviceServicingTrigger :
    Windows::ApplicationModel::Background::IDeviceServicingTrigger
{
    DeviceServicingTrigger(std::nullptr_t) noexcept {}
    DeviceServicingTrigger();
};

struct WINRT_EBO DeviceUseTrigger :
    Windows::ApplicationModel::Background::IDeviceUseTrigger
{
    DeviceUseTrigger(std::nullptr_t) noexcept {}
    DeviceUseTrigger();
};

struct WINRT_EBO DeviceWatcherTrigger :
    Windows::ApplicationModel::Background::IDeviceWatcherTrigger
{
    DeviceWatcherTrigger(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EmailStoreNotificationTrigger :
    Windows::ApplicationModel::Background::IEmailStoreNotificationTrigger
{
    EmailStoreNotificationTrigger(std::nullptr_t) noexcept {}
    EmailStoreNotificationTrigger();
};

struct WINRT_EBO GattCharacteristicNotificationTrigger :
    Windows::ApplicationModel::Background::IGattCharacteristicNotificationTrigger
{
    GattCharacteristicNotificationTrigger(std::nullptr_t) noexcept {}
    GattCharacteristicNotificationTrigger(const Windows::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic & characteristic);
};

struct WINRT_EBO LocationTrigger :
    Windows::ApplicationModel::Background::ILocationTrigger
{
    LocationTrigger(std::nullptr_t) noexcept {}
    LocationTrigger(Windows::ApplicationModel::Background::LocationTriggerType triggerType);
};

struct WINRT_EBO MaintenanceTrigger :
    Windows::ApplicationModel::Background::IMaintenanceTrigger
{
    MaintenanceTrigger(std::nullptr_t) noexcept {}
    MaintenanceTrigger(uint32_t freshnessTime, bool oneShot);
};

struct WINRT_EBO MediaProcessingTrigger :
    Windows::ApplicationModel::Background::IMediaProcessingTrigger
{
    MediaProcessingTrigger(std::nullptr_t) noexcept {}
    MediaProcessingTrigger();
};

struct WINRT_EBO MobileBroadbandDeviceServiceNotificationTrigger :
    Windows::ApplicationModel::Background::IBackgroundTrigger
{
    MobileBroadbandDeviceServiceNotificationTrigger(std::nullptr_t) noexcept {}
    MobileBroadbandDeviceServiceNotificationTrigger();
};

struct WINRT_EBO MobileBroadbandPinLockStateChangeTrigger :
    Windows::ApplicationModel::Background::IBackgroundTrigger
{
    MobileBroadbandPinLockStateChangeTrigger(std::nullptr_t) noexcept {}
    MobileBroadbandPinLockStateChangeTrigger();
};

struct WINRT_EBO MobileBroadbandRadioStateChangeTrigger :
    Windows::ApplicationModel::Background::IBackgroundTrigger
{
    MobileBroadbandRadioStateChangeTrigger(std::nullptr_t) noexcept {}
    MobileBroadbandRadioStateChangeTrigger();
};

struct WINRT_EBO MobileBroadbandRegistrationStateChangeTrigger :
    Windows::ApplicationModel::Background::IBackgroundTrigger
{
    MobileBroadbandRegistrationStateChangeTrigger(std::nullptr_t) noexcept {}
    MobileBroadbandRegistrationStateChangeTrigger();
};

struct WINRT_EBO NetworkOperatorHotspotAuthenticationTrigger :
    Windows::ApplicationModel::Background::INetworkOperatorHotspotAuthenticationTrigger
{
    NetworkOperatorHotspotAuthenticationTrigger(std::nullptr_t) noexcept {}
    NetworkOperatorHotspotAuthenticationTrigger();
};

struct WINRT_EBO NetworkOperatorNotificationTrigger :
    Windows::ApplicationModel::Background::INetworkOperatorNotificationTrigger
{
    NetworkOperatorNotificationTrigger(std::nullptr_t) noexcept {}
    NetworkOperatorNotificationTrigger(hstring_view networkAccountId);
};

struct WINRT_EBO PhoneTrigger :
    Windows::ApplicationModel::Background::IPhoneTrigger
{
    PhoneTrigger(std::nullptr_t) noexcept {}
    PhoneTrigger(Windows::ApplicationModel::Calls::Background::PhoneTriggerType type, bool oneShot);
};

struct WINRT_EBO PushNotificationTrigger :
    Windows::ApplicationModel::Background::IBackgroundTrigger
{
    PushNotificationTrigger(std::nullptr_t) noexcept {}
    PushNotificationTrigger();
    PushNotificationTrigger(hstring_view applicationId);
};

struct WINRT_EBO RcsEndUserMessageAvailableTrigger :
    Windows::ApplicationModel::Background::IRcsEndUserMessageAvailableTrigger
{
    RcsEndUserMessageAvailableTrigger(std::nullptr_t) noexcept {}
    RcsEndUserMessageAvailableTrigger();
};

struct WINRT_EBO RfcommConnectionTrigger :
    Windows::ApplicationModel::Background::IRfcommConnectionTrigger
{
    RfcommConnectionTrigger(std::nullptr_t) noexcept {}
    RfcommConnectionTrigger();
};

struct WINRT_EBO SecondaryAuthenticationFactorAuthenticationTrigger :
    Windows::ApplicationModel::Background::ISecondaryAuthenticationFactorAuthenticationTrigger
{
    SecondaryAuthenticationFactorAuthenticationTrigger(std::nullptr_t) noexcept {}
    SecondaryAuthenticationFactorAuthenticationTrigger();
};

struct WINRT_EBO SensorDataThresholdTrigger :
    Windows::ApplicationModel::Background::ISensorDataThresholdTrigger
{
    SensorDataThresholdTrigger(std::nullptr_t) noexcept {}
    SensorDataThresholdTrigger(const Windows::Devices::Sensors::ISensorDataThreshold & threshold);
};

struct WINRT_EBO SmartCardTrigger :
    Windows::ApplicationModel::Background::ISmartCardTrigger
{
    SmartCardTrigger(std::nullptr_t) noexcept {}
    SmartCardTrigger(Windows::Devices::SmartCards::SmartCardTriggerType triggerType);
};

struct WINRT_EBO SmsMessageReceivedTrigger :
    Windows::ApplicationModel::Background::IBackgroundTrigger
{
    SmsMessageReceivedTrigger(std::nullptr_t) noexcept {}
    SmsMessageReceivedTrigger(const Windows::Devices::Sms::SmsFilterRules & filterRules);
};

struct WINRT_EBO SocketActivityTrigger :
    Windows::ApplicationModel::Background::IBackgroundTrigger,
    impl::require<SocketActivityTrigger, Windows::ApplicationModel::Background::ISocketActivityTrigger>
{
    SocketActivityTrigger(std::nullptr_t) noexcept {}
    SocketActivityTrigger();
};

struct WINRT_EBO StorageLibraryContentChangedTrigger :
    Windows::ApplicationModel::Background::IStorageLibraryContentChangedTrigger
{
    StorageLibraryContentChangedTrigger(std::nullptr_t) noexcept {}
    static Windows::ApplicationModel::Background::StorageLibraryContentChangedTrigger Create(const Windows::Storage::StorageLibrary & storageLibrary);
    static Windows::ApplicationModel::Background::StorageLibraryContentChangedTrigger CreateFromLibraries(iterable<Windows::Storage::StorageLibrary> storageLibraries);
};

struct WINRT_EBO SystemCondition :
    Windows::ApplicationModel::Background::ISystemCondition
{
    SystemCondition(std::nullptr_t) noexcept {}
    SystemCondition(Windows::ApplicationModel::Background::SystemConditionType conditionType);
};

struct WINRT_EBO SystemTrigger :
    Windows::ApplicationModel::Background::ISystemTrigger
{
    SystemTrigger(std::nullptr_t) noexcept {}
    SystemTrigger(Windows::ApplicationModel::Background::SystemTriggerType triggerType, bool oneShot);
};

struct WINRT_EBO TimeTrigger :
    Windows::ApplicationModel::Background::ITimeTrigger
{
    TimeTrigger(std::nullptr_t) noexcept {}
    TimeTrigger(uint32_t freshnessTime, bool oneShot);
};

struct WINRT_EBO ToastNotificationActionTrigger :
    Windows::ApplicationModel::Background::IBackgroundTrigger
{
    ToastNotificationActionTrigger(std::nullptr_t) noexcept {}
    ToastNotificationActionTrigger();
    ToastNotificationActionTrigger(hstring_view applicationId);
};

struct WINRT_EBO ToastNotificationHistoryChangedTrigger :
    Windows::ApplicationModel::Background::IBackgroundTrigger
{
    ToastNotificationHistoryChangedTrigger(std::nullptr_t) noexcept {}
    ToastNotificationHistoryChangedTrigger();
    ToastNotificationHistoryChangedTrigger(hstring_view applicationId);
};

struct WINRT_EBO UserNotificationChangedTrigger :
    Windows::ApplicationModel::Background::IBackgroundTrigger
{
    UserNotificationChangedTrigger(std::nullptr_t) noexcept {}
    UserNotificationChangedTrigger(Windows::UI::Notifications::NotificationKinds notificationKinds);
};

}

}
