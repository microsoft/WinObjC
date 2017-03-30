// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.ApplicationModel.Background.0.h"
#include "Windows.ApplicationModel.Calls.Background.0.h"
#include "Windows.Devices.Bluetooth.0.h"
#include "Windows.Devices.Bluetooth.Advertisement.0.h"
#include "Windows.Devices.Bluetooth.Background.0.h"
#include "Windows.Devices.Bluetooth.GenericAttributeProfile.0.h"
#include "Windows.Devices.Sensors.0.h"
#include "Windows.Devices.SmartCards.0.h"
#include "Windows.Devices.Sms.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Foundation.Collections.0.h"
#include "Windows.Networking.0.h"
#include "Windows.Networking.Sockets.0.h"
#include "Windows.Storage.0.h"
#include "Windows.Storage.Provider.0.h"
#include "Windows.System.0.h"
#include "Windows.UI.Notifications.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Storage.1.h"
#include "Windows.Devices.Sensors.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::Background {

struct __declspec(uuid("a6c4bac0-51f8-4c57-ac3f-156dd1680c4f")) __declspec(novtable) BackgroundTaskCanceledEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::ApplicationModel::Background::IBackgroundTaskInstance * sender, winrt::Windows::ApplicationModel::Background::BackgroundTaskCancellationReason reason) = 0;
};

struct __declspec(uuid("5b38e929-a086-46a7-a678-439135822bcf")) __declspec(novtable) BackgroundTaskCompletedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::ApplicationModel::Background::IBackgroundTaskRegistration * sender, Windows::ApplicationModel::Background::IBackgroundTaskCompletedEventArgs * args) = 0;
};

struct __declspec(uuid("46e0683c-8a88-4c99-804c-76897f6277a6")) __declspec(novtable) BackgroundTaskProgressEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::ApplicationModel::Background::IBackgroundTaskRegistration * sender, Windows::ApplicationModel::Background::IBackgroundTaskProgressEventArgs * args) = 0;
};

struct __declspec(uuid("d0dd4342-e37b-4823-a5fe-6b31dfefdeb0")) __declspec(novtable) IActivitySensorTrigger : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SubscribedActivities(Windows::Foundation::Collections::IVector<winrt::Windows::Devices::Sensors::ActivityType> ** value) = 0;
    virtual HRESULT __stdcall get_ReportInterval(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_SupportedActivities(Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::Sensors::ActivityType> ** value) = 0;
    virtual HRESULT __stdcall get_MinimumReportInterval(uint32_t * value) = 0;
};

struct __declspec(uuid("a72691c3-3837-44f7-831b-0132cc872bc3")) __declspec(novtable) IActivitySensorTriggerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(uint32_t reportIntervalInMilliseconds, Windows::ApplicationModel::Background::IActivitySensorTrigger ** activityTrigger) = 0;
};

struct __declspec(uuid("ca03fa3b-cce6-4de2-b09b-9628bd33bbbe")) __declspec(novtable) IAlarmApplicationManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RequestAccessAsync(Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::AlarmAccessStatus> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetAccessStatus(winrt::Windows::ApplicationModel::Background::AlarmAccessStatus * status) = 0;
};

struct __declspec(uuid("0b468630-9574-492c-9e93-1a3ae6335fe9")) __declspec(novtable) IApplicationTrigger : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RequestAsync(Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::ApplicationTriggerResult> ** result) = 0;
    virtual HRESULT __stdcall abi_RequestAsyncWithArguments(Windows::Foundation::Collections::IPropertySet * arguments, Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::ApplicationTriggerResult> ** result) = 0;
};

struct __declspec(uuid("97dc6ab2-2219-4a9e-9c5e-41d047f76e82")) __declspec(novtable) IApplicationTriggerDetails : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Arguments(Windows::Foundation::Collections::IPropertySet ** value) = 0;
};

struct __declspec(uuid("64d4040c-c201-42ad-aa2a-e21ba3425b6d")) __declspec(novtable) IAppointmentStoreNotificationTrigger : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("ae48a1ee-8951-400a-8302-9c9c9a2a3a3b")) __declspec(novtable) IBackgroundCondition : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("e826ea58-66a9-4d41-83d4-b4c18c87b846")) __declspec(novtable) IBackgroundExecutionManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RequestAccessAsync(Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::BackgroundAccessStatus> ** operation) = 0;
    virtual HRESULT __stdcall abi_RequestAccessForApplicationAsync(hstring applicationId, Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::BackgroundAccessStatus> ** operation) = 0;
    virtual HRESULT __stdcall abi_RemoveAccess() = 0;
    virtual HRESULT __stdcall abi_RemoveAccessForApplication(hstring applicationId) = 0;
    virtual HRESULT __stdcall abi_GetAccessStatus(winrt::Windows::ApplicationModel::Background::BackgroundAccessStatus * status) = 0;
    virtual HRESULT __stdcall abi_GetAccessStatusForApplication(hstring applicationId, winrt::Windows::ApplicationModel::Background::BackgroundAccessStatus * status) = 0;
};

struct __declspec(uuid("7d13d534-fd12-43ce-8c22-ea1ff13c06df")) __declspec(novtable) IBackgroundTask : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Run(Windows::ApplicationModel::Background::IBackgroundTaskInstance * taskInstance) = 0;
};

struct __declspec(uuid("0351550e-3e64-4572-a93a-84075a37c917")) __declspec(novtable) IBackgroundTaskBuilder : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_TaskEntryPoint(hstring value) = 0;
    virtual HRESULT __stdcall get_TaskEntryPoint(hstring * value) = 0;
    virtual HRESULT __stdcall abi_SetTrigger(Windows::ApplicationModel::Background::IBackgroundTrigger * trigger) = 0;
    virtual HRESULT __stdcall abi_AddCondition(Windows::ApplicationModel::Background::IBackgroundCondition * condition) = 0;
    virtual HRESULT __stdcall put_Name(hstring value) = 0;
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall abi_Register(Windows::ApplicationModel::Background::IBackgroundTaskRegistration ** task) = 0;
};

struct __declspec(uuid("6ae7cfb1-104f-406d-8db6-844a570f42bb")) __declspec(novtable) IBackgroundTaskBuilder2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_CancelOnConditionLoss(bool value) = 0;
    virtual HRESULT __stdcall get_CancelOnConditionLoss(bool * value) = 0;
};

struct __declspec(uuid("28c74f4a-8ba9-4c09-a24f-19683e2c924c")) __declspec(novtable) IBackgroundTaskBuilder3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_IsNetworkRequested(bool value) = 0;
    virtual HRESULT __stdcall get_IsNetworkRequested(bool * value) = 0;
};

struct __declspec(uuid("565d25cf-f209-48f4-9967-2b184f7bfbf0")) __declspec(novtable) IBackgroundTaskCompletedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_InstanceId(GUID * value) = 0;
    virtual HRESULT __stdcall abi_CheckResult() = 0;
};

struct __declspec(uuid("93cc156d-af27-4dd3-846e-24ee40cadd25")) __declspec(novtable) IBackgroundTaskDeferral : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Complete() = 0;
};

struct __declspec(uuid("865bda7a-21d8-4573-8f32-928a1b0641f6")) __declspec(novtable) IBackgroundTaskInstance : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_InstanceId(GUID * value) = 0;
    virtual HRESULT __stdcall get_Task(Windows::ApplicationModel::Background::IBackgroundTaskRegistration ** task) = 0;
    virtual HRESULT __stdcall get_Progress(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_Progress(uint32_t value) = 0;
    virtual HRESULT __stdcall get_TriggerDetails(Windows::Foundation::IInspectable ** triggerDetails) = 0;
    virtual HRESULT __stdcall add_Canceled(Windows::ApplicationModel::Background::BackgroundTaskCanceledEventHandler * cancelHandler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_Canceled(event_token cookie) = 0;
    virtual HRESULT __stdcall get_SuspendedCount(uint32_t * value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::ApplicationModel::Background::IBackgroundTaskDeferral ** deferral) = 0;
};

struct __declspec(uuid("4f7d0176-0c76-4fb4-896d-5de1864122f6")) __declspec(novtable) IBackgroundTaskInstance2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetThrottleCount(winrt::Windows::ApplicationModel::Background::BackgroundTaskThrottleCounter counter, uint32_t * value) = 0;
};

struct __declspec(uuid("7f29f23c-aa04-4b08-97b0-06d874cdabf5")) __declspec(novtable) IBackgroundTaskInstance4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_User(Windows::System::IUser ** value) = 0;
};

struct __declspec(uuid("fb1468ac-8332-4d0a-9532-03eae684da31")) __declspec(novtable) IBackgroundTaskProgressEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_InstanceId(GUID * value) = 0;
    virtual HRESULT __stdcall get_Progress(uint32_t * value) = 0;
};

struct __declspec(uuid("10654cc2-a26e-43bf-8c12-1fb40dbfbfa0")) __declspec(novtable) IBackgroundTaskRegistration : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TaskId(GUID * value) = 0;
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall add_Progress(Windows::ApplicationModel::Background::BackgroundTaskProgressEventHandler * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_Progress(event_token cookie) = 0;
    virtual HRESULT __stdcall add_Completed(Windows::ApplicationModel::Background::BackgroundTaskCompletedEventHandler * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_Completed(event_token cookie) = 0;
    virtual HRESULT __stdcall abi_Unregister(bool cancelTask) = 0;
};

struct __declspec(uuid("6138c703-bb86-4112-afc3-7f939b166e3b")) __declspec(novtable) IBackgroundTaskRegistration2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Trigger(Windows::ApplicationModel::Background::IBackgroundTrigger ** value) = 0;
};

struct __declspec(uuid("4c542f69-b000-42ba-a093-6a563c65e3f8")) __declspec(novtable) IBackgroundTaskRegistrationStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AllTasks(Windows::Foundation::Collections::IMapView<GUID, Windows::ApplicationModel::Background::IBackgroundTaskRegistration> ** tasks) = 0;
};

struct __declspec(uuid("84b3a058-6027-4b87-9790-bdf3f757dbd7")) __declspec(novtable) IBackgroundTrigger : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("c740a662-c310-4b82-b3e3-3bcfb9e4c77d")) __declspec(novtable) IBackgroundWorkCostStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CurrentBackgroundWorkCost(winrt::Windows::ApplicationModel::Background::BackgroundWorkCostValue * value) = 0;
};

struct __declspec(uuid("ab3e2612-25d3-48ae-8724-d81877ae6129")) __declspec(novtable) IBluetoothLEAdvertisementPublisherTrigger : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Advertisement(Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisement ** value) = 0;
};

struct __declspec(uuid("1aab1819-bce1-48eb-a827-59fb7cee52a6")) __declspec(novtable) IBluetoothLEAdvertisementWatcherTrigger : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MinSamplingInterval(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_MaxSamplingInterval(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_MinOutOfRangeTimeout(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_MaxOutOfRangeTimeout(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_SignalStrengthFilter(Windows::Devices::Bluetooth::IBluetoothSignalStrengthFilter ** value) = 0;
    virtual HRESULT __stdcall put_SignalStrengthFilter(Windows::Devices::Bluetooth::IBluetoothSignalStrengthFilter * value) = 0;
    virtual HRESULT __stdcall get_AdvertisementFilter(Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementFilter ** value) = 0;
    virtual HRESULT __stdcall put_AdvertisementFilter(Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementFilter * value) = 0;
};

struct __declspec(uuid("e21caeeb-32f2-4d31-b553-b9e01bde37e0")) __declspec(novtable) ICachedFileUpdaterTrigger : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("71838c13-1314-47b4-9597-dc7e248c17cc")) __declspec(novtable) ICachedFileUpdaterTriggerDetails : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_UpdateTarget(winrt::Windows::Storage::Provider::CachedFileTarget * value) = 0;
    virtual HRESULT __stdcall get_UpdateRequest(Windows::Storage::Provider::IFileUpdateRequest ** value) = 0;
    virtual HRESULT __stdcall get_CanRequestUserInput(bool * value) = 0;
};

struct __declspec(uuid("513b43bf-1d40-5c5d-78f5-c923fee3739e")) __declspec(novtable) IChatMessageNotificationTrigger : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("3ea3760e-baf5-4077-88e9-060cf6f0c6d5")) __declspec(novtable) IChatMessageReceivedNotificationTrigger : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("fb91f28a-16a5-486d-974c-7835a8477be2")) __declspec(novtable) ICommunicationBlockingAppSetAsActiveTrigger : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("c833419b-4705-4571-9a16-06b997bf9c96")) __declspec(novtable) IContactStoreNotificationTrigger : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("710627ee-04fa-440b-80c0-173202199e5d")) __declspec(novtable) IContentPrefetchTrigger : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_WaitInterval(Windows::Foundation::TimeSpan * waitInterval) = 0;
};

struct __declspec(uuid("c2643eda-8a03-409e-b8c4-88814c28ccb6")) __declspec(novtable) IContentPrefetchTriggerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Foundation::TimeSpan waitInterval, Windows::ApplicationModel::Background::IContentPrefetchTrigger ** trigger) = 0;
};

struct __declspec(uuid("90875e64-3cdd-4efb-ab1c-5b3b6a60ce34")) __declspec(novtable) IDeviceConnectionChangeTrigger : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
    virtual HRESULT __stdcall get_CanMaintainConnection(bool * value) = 0;
    virtual HRESULT __stdcall get_MaintainConnection(bool * value) = 0;
    virtual HRESULT __stdcall put_MaintainConnection(bool value) = 0;
};

struct __declspec(uuid("c3ea246a-4efd-4498-aa60-a4e4e3b17ab9")) __declspec(novtable) IDeviceConnectionChangeTriggerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FromIdAsync(hstring deviceId, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Background::DeviceConnectionChangeTrigger> ** deviceChangeTrigger) = 0;
};

struct __declspec(uuid("81278ab5-41ab-16da-86c2-7f7bf0912f5b")) __declspec(novtable) IDeviceManufacturerNotificationTrigger : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TriggerQualifier(hstring * value) = 0;
    virtual HRESULT __stdcall get_OneShot(bool * oneShot) = 0;
};

struct __declspec(uuid("7955de75-25bb-4153-a1a2-3029fcabb652")) __declspec(novtable) IDeviceManufacturerNotificationTriggerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(hstring triggerQualifier, bool oneShot, Windows::ApplicationModel::Background::IDeviceManufacturerNotificationTrigger ** trigger) = 0;
};

struct __declspec(uuid("1ab217ad-6e34-49d3-9e6f-17f1b6dfa881")) __declspec(novtable) IDeviceServicingTrigger : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RequestAsyncSimple(hstring deviceId, Windows::Foundation::TimeSpan expectedDuration, Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::DeviceTriggerResult> ** result) = 0;
    virtual HRESULT __stdcall abi_RequestAsyncWithArguments(hstring deviceId, Windows::Foundation::TimeSpan expectedDuration, hstring arguments, Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::DeviceTriggerResult> ** result) = 0;
};

struct __declspec(uuid("0da68011-334f-4d57-b6ec-6dca64b412e4")) __declspec(novtable) IDeviceUseTrigger : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RequestAsyncSimple(hstring deviceId, Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::DeviceTriggerResult> ** result) = 0;
    virtual HRESULT __stdcall abi_RequestAsyncWithArguments(hstring deviceId, hstring arguments, Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::DeviceTriggerResult> ** result) = 0;
};

struct __declspec(uuid("a4617fdd-8573-4260-befc-5bec89cb693d")) __declspec(novtable) IDeviceWatcherTrigger : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("986d06da-47eb-4268-a4f2-f3f77188388a")) __declspec(novtable) IEmailStoreNotificationTrigger : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("e25f8fc8-0696-474f-a732-f292b0cebc5d")) __declspec(novtable) IGattCharacteristicNotificationTrigger : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Characteristic(Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic ** value) = 0;
};

struct __declspec(uuid("57ba1995-b143-4575-9f6b-fd59d93ace1a")) __declspec(novtable) IGattCharacteristicNotificationTriggerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic * characteristic, Windows::ApplicationModel::Background::IGattCharacteristicNotificationTrigger ** gattCharacteristicNotificationTrigger) = 0;
};

struct __declspec(uuid("47666a1c-6877-481e-8026-ff7e14a811a0")) __declspec(novtable) ILocationTrigger : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TriggerType(winrt::Windows::ApplicationModel::Background::LocationTriggerType * triggerType) = 0;
};

struct __declspec(uuid("1106bb07-ff69-4e09-aa8b-1384ea475e98")) __declspec(novtable) ILocationTriggerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(winrt::Windows::ApplicationModel::Background::LocationTriggerType triggerType, Windows::ApplicationModel::Background::ILocationTrigger ** locationTrigger) = 0;
};

struct __declspec(uuid("68184c83-fc22-4ce5-841a-7239a9810047")) __declspec(novtable) IMaintenanceTrigger : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FreshnessTime(uint32_t * freshnessTime) = 0;
    virtual HRESULT __stdcall get_OneShot(bool * oneShot) = 0;
};

struct __declspec(uuid("4b3ddb2e-97dd-4629-88b0-b06cf9482ae5")) __declspec(novtable) IMaintenanceTriggerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(uint32_t freshnessTime, bool oneShot, Windows::ApplicationModel::Background::IMaintenanceTrigger ** trigger) = 0;
};

struct __declspec(uuid("9a95be65-8a52-4b30-9011-cf38040ea8b0")) __declspec(novtable) IMediaProcessingTrigger : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RequestAsync(Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::MediaProcessingTriggerResult> ** result) = 0;
    virtual HRESULT __stdcall abi_RequestAsyncWithArguments(Windows::Foundation::Collections::IPropertySet * arguments, Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::MediaProcessingTriggerResult> ** result) = 0;
};

struct __declspec(uuid("e756c791-3001-4de5-83c7-de61d88831d0")) __declspec(novtable) INetworkOperatorHotspotAuthenticationTrigger : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("90089cc6-63cd-480c-95d1-6e6aef801e4a")) __declspec(novtable) INetworkOperatorNotificationTrigger : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_NetworkAccountId(hstring * value) = 0;
};

struct __declspec(uuid("0a223e00-27d7-4353-adb9-9265aaea579d")) __declspec(novtable) INetworkOperatorNotificationTriggerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(hstring networkAccountId, Windows::ApplicationModel::Background::INetworkOperatorNotificationTrigger ** trigger) = 0;
};

struct __declspec(uuid("8dcfe99b-d4c5-49f1-b7d3-82e87a0e9dde")) __declspec(novtable) IPhoneTrigger : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_OneShot(bool * value) = 0;
    virtual HRESULT __stdcall get_TriggerType(winrt::Windows::ApplicationModel::Calls::Background::PhoneTriggerType * result) = 0;
};

struct __declspec(uuid("a0d93cda-5fc1-48fb-a546-32262040157b")) __declspec(novtable) IPhoneTriggerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(winrt::Windows::ApplicationModel::Calls::Background::PhoneTriggerType type, bool oneShot, Windows::ApplicationModel::Background::IPhoneTrigger ** result) = 0;
};

struct __declspec(uuid("6dd8ed1b-458e-4fc2-bc2e-d5664f77ed19")) __declspec(novtable) IPushNotificationTriggerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(hstring applicationId, Windows::ApplicationModel::Background::IBackgroundTrigger ** trigger) = 0;
};

struct __declspec(uuid("986d0d6a-b2f6-467f-a978-a44091c11a66")) __declspec(novtable) IRcsEndUserMessageAvailableTrigger : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("e8c4cae2-0b53-4464-9394-fd875654de64")) __declspec(novtable) IRfcommConnectionTrigger : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_InboundConnection(Windows::Devices::Bluetooth::Background::IRfcommInboundConnectionInformation ** value) = 0;
    virtual HRESULT __stdcall get_OutboundConnection(Windows::Devices::Bluetooth::Background::IRfcommOutboundConnectionInformation ** value) = 0;
    virtual HRESULT __stdcall get_AllowMultipleConnections(bool * value) = 0;
    virtual HRESULT __stdcall put_AllowMultipleConnections(bool value) = 0;
    virtual HRESULT __stdcall get_ProtectionLevel(winrt::Windows::Networking::Sockets::SocketProtectionLevel * value) = 0;
    virtual HRESULT __stdcall put_ProtectionLevel(winrt::Windows::Networking::Sockets::SocketProtectionLevel value) = 0;
    virtual HRESULT __stdcall get_RemoteHostName(Windows::Networking::IHostName ** value) = 0;
    virtual HRESULT __stdcall put_RemoteHostName(Windows::Networking::IHostName * value) = 0;
};

struct __declspec(uuid("f237f327-5181-4f24-96a7-700a4e5fac62")) __declspec(novtable) ISecondaryAuthenticationFactorAuthenticationTrigger : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("5bc0f372-d48b-4b7f-abec-15f9bacc12e2")) __declspec(novtable) ISensorDataThresholdTrigger : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("921fe675-7df0-4da3-97b3-e544ee857fe6")) __declspec(novtable) ISensorDataThresholdTriggerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Devices::Sensors::ISensorDataThreshold * threshold, Windows::ApplicationModel::Background::ISensorDataThresholdTrigger ** trigger) = 0;
};

struct __declspec(uuid("f53bc5ac-84ca-4972-8ce9-e58f97b37a50")) __declspec(novtable) ISmartCardTrigger : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TriggerType(winrt::Windows::Devices::SmartCards::SmartCardTriggerType * triggerType) = 0;
};

struct __declspec(uuid("63bf54c3-89c1-4e00-a9d3-97c629269dad")) __declspec(novtable) ISmartCardTriggerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(winrt::Windows::Devices::SmartCards::SmartCardTriggerType triggerType, Windows::ApplicationModel::Background::ISmartCardTrigger ** trigger) = 0;
};

struct __declspec(uuid("ea3ad8c8-6ba4-4ab2-8d21-bc6b09c77564")) __declspec(novtable) ISmsMessageReceivedTriggerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Devices::Sms::ISmsFilterRules * filterRules, Windows::ApplicationModel::Background::IBackgroundTrigger ** value) = 0;
};

struct __declspec(uuid("a9bbf810-9dde-4f8a-83e3-b0e0e7a50d70")) __declspec(novtable) ISocketActivityTrigger : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsWakeFromLowPowerSupported(bool * value) = 0;
};

struct __declspec(uuid("1637e0a7-829c-45bc-929b-a1e7ea78d89b")) __declspec(novtable) IStorageLibraryContentChangedTrigger : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("7f9f1b39-5f90-4e12-914e-a7d8e0bbfb18")) __declspec(novtable) IStorageLibraryContentChangedTriggerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Storage::IStorageLibrary * storageLibrary, Windows::ApplicationModel::Background::IStorageLibraryContentChangedTrigger ** result) = 0;
    virtual HRESULT __stdcall abi_CreateFromLibraries(Windows::Foundation::Collections::IIterable<Windows::Storage::StorageLibrary> * storageLibraries, Windows::ApplicationModel::Background::IStorageLibraryContentChangedTrigger ** result) = 0;
};

struct __declspec(uuid("c15fb476-89c5-420b-abd3-fb3030472128")) __declspec(novtable) ISystemCondition : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ConditionType(winrt::Windows::ApplicationModel::Background::SystemConditionType * conditionType) = 0;
};

struct __declspec(uuid("d269d1f1-05a7-49ae-87d7-16b2b8b9a553")) __declspec(novtable) ISystemConditionFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(winrt::Windows::ApplicationModel::Background::SystemConditionType conditionType, Windows::ApplicationModel::Background::ISystemCondition ** condition) = 0;
};

struct __declspec(uuid("1d80c776-3748-4463-8d7e-276dc139ac1c")) __declspec(novtable) ISystemTrigger : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_OneShot(bool * oneShot) = 0;
    virtual HRESULT __stdcall get_TriggerType(winrt::Windows::ApplicationModel::Background::SystemTriggerType * triggerType) = 0;
};

struct __declspec(uuid("e80423d4-8791-4579-8126-87ec8aaa407a")) __declspec(novtable) ISystemTriggerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(winrt::Windows::ApplicationModel::Background::SystemTriggerType triggerType, bool oneShot, Windows::ApplicationModel::Background::ISystemTrigger ** trigger) = 0;
};

struct __declspec(uuid("656e5556-0b2a-4377-ba70-3b45a935547f")) __declspec(novtable) ITimeTrigger : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FreshnessTime(uint32_t * freshnessTime) = 0;
    virtual HRESULT __stdcall get_OneShot(bool * oneShot) = 0;
};

struct __declspec(uuid("38c682fe-9b54-45e6-b2f3-269b87a6f734")) __declspec(novtable) ITimeTriggerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(uint32_t freshnessTime, bool oneShot, Windows::ApplicationModel::Background::ITimeTrigger ** trigger) = 0;
};

struct __declspec(uuid("b09dfc27-6480-4349-8125-97b3efaa0a3a")) __declspec(novtable) IToastNotificationActionTriggerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(hstring applicationId, Windows::ApplicationModel::Background::IBackgroundTrigger ** trigger) = 0;
};

struct __declspec(uuid("81c6faad-8797-4785-81b4-b0cccb73d1d9")) __declspec(novtable) IToastNotificationHistoryChangedTriggerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(hstring applicationId, Windows::ApplicationModel::Background::IBackgroundTrigger ** trigger) = 0;
};

struct __declspec(uuid("cad4436c-69ab-4e18-a48a-5ed2ac435957")) __declspec(novtable) IUserNotificationChangedTriggerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(winrt::Windows::UI::Notifications::NotificationKinds notificationKinds, Windows::ApplicationModel::Background::IBackgroundTrigger ** trigger) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::ApplicationModel::Background::ActivitySensorTrigger> { using default_interface = Windows::ApplicationModel::Background::IActivitySensorTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::ApplicationTrigger> { using default_interface = Windows::ApplicationModel::Background::IApplicationTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::ApplicationTriggerDetails> { using default_interface = Windows::ApplicationModel::Background::IApplicationTriggerDetails; };
template <> struct traits<Windows::ApplicationModel::Background::AppointmentStoreNotificationTrigger> { using default_interface = Windows::ApplicationModel::Background::IAppointmentStoreNotificationTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::BackgroundTaskBuilder> { using default_interface = Windows::ApplicationModel::Background::IBackgroundTaskBuilder; };
template <> struct traits<Windows::ApplicationModel::Background::BackgroundTaskCompletedEventArgs> { using default_interface = Windows::ApplicationModel::Background::IBackgroundTaskCompletedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Background::BackgroundTaskDeferral> { using default_interface = Windows::ApplicationModel::Background::IBackgroundTaskDeferral; };
template <> struct traits<Windows::ApplicationModel::Background::BackgroundTaskProgressEventArgs> { using default_interface = Windows::ApplicationModel::Background::IBackgroundTaskProgressEventArgs; };
template <> struct traits<Windows::ApplicationModel::Background::BackgroundTaskRegistration> { using default_interface = Windows::ApplicationModel::Background::IBackgroundTaskRegistration; };
template <> struct traits<Windows::ApplicationModel::Background::BluetoothLEAdvertisementPublisherTrigger> { using default_interface = Windows::ApplicationModel::Background::IBluetoothLEAdvertisementPublisherTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::BluetoothLEAdvertisementWatcherTrigger> { using default_interface = Windows::ApplicationModel::Background::IBluetoothLEAdvertisementWatcherTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::CachedFileUpdaterTrigger> { using default_interface = Windows::ApplicationModel::Background::ICachedFileUpdaterTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::CachedFileUpdaterTriggerDetails> { using default_interface = Windows::ApplicationModel::Background::ICachedFileUpdaterTriggerDetails; };
template <> struct traits<Windows::ApplicationModel::Background::ChatMessageNotificationTrigger> { using default_interface = Windows::ApplicationModel::Background::IChatMessageNotificationTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::ChatMessageReceivedNotificationTrigger> { using default_interface = Windows::ApplicationModel::Background::IChatMessageReceivedNotificationTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::CommunicationBlockingAppSetAsActiveTrigger> { using default_interface = Windows::ApplicationModel::Background::ICommunicationBlockingAppSetAsActiveTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::ContactStoreNotificationTrigger> { using default_interface = Windows::ApplicationModel::Background::IContactStoreNotificationTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::ContentPrefetchTrigger> { using default_interface = Windows::ApplicationModel::Background::IContentPrefetchTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::DeviceConnectionChangeTrigger> { using default_interface = Windows::ApplicationModel::Background::IDeviceConnectionChangeTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::DeviceManufacturerNotificationTrigger> { using default_interface = Windows::ApplicationModel::Background::IDeviceManufacturerNotificationTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::DeviceServicingTrigger> { using default_interface = Windows::ApplicationModel::Background::IDeviceServicingTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::DeviceUseTrigger> { using default_interface = Windows::ApplicationModel::Background::IDeviceUseTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::DeviceWatcherTrigger> { using default_interface = Windows::ApplicationModel::Background::IDeviceWatcherTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::EmailStoreNotificationTrigger> { using default_interface = Windows::ApplicationModel::Background::IEmailStoreNotificationTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::GattCharacteristicNotificationTrigger> { using default_interface = Windows::ApplicationModel::Background::IGattCharacteristicNotificationTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::LocationTrigger> { using default_interface = Windows::ApplicationModel::Background::ILocationTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::MaintenanceTrigger> { using default_interface = Windows::ApplicationModel::Background::IMaintenanceTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::MediaProcessingTrigger> { using default_interface = Windows::ApplicationModel::Background::IMediaProcessingTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::MobileBroadbandDeviceServiceNotificationTrigger> { using default_interface = Windows::ApplicationModel::Background::IBackgroundTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::MobileBroadbandPinLockStateChangeTrigger> { using default_interface = Windows::ApplicationModel::Background::IBackgroundTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::MobileBroadbandRadioStateChangeTrigger> { using default_interface = Windows::ApplicationModel::Background::IBackgroundTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::MobileBroadbandRegistrationStateChangeTrigger> { using default_interface = Windows::ApplicationModel::Background::IBackgroundTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::NetworkOperatorHotspotAuthenticationTrigger> { using default_interface = Windows::ApplicationModel::Background::INetworkOperatorHotspotAuthenticationTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::NetworkOperatorNotificationTrigger> { using default_interface = Windows::ApplicationModel::Background::INetworkOperatorNotificationTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::PhoneTrigger> { using default_interface = Windows::ApplicationModel::Background::IPhoneTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::PushNotificationTrigger> { using default_interface = Windows::ApplicationModel::Background::IBackgroundTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::RcsEndUserMessageAvailableTrigger> { using default_interface = Windows::ApplicationModel::Background::IRcsEndUserMessageAvailableTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::RfcommConnectionTrigger> { using default_interface = Windows::ApplicationModel::Background::IRfcommConnectionTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::SecondaryAuthenticationFactorAuthenticationTrigger> { using default_interface = Windows::ApplicationModel::Background::ISecondaryAuthenticationFactorAuthenticationTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::SensorDataThresholdTrigger> { using default_interface = Windows::ApplicationModel::Background::ISensorDataThresholdTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::SmartCardTrigger> { using default_interface = Windows::ApplicationModel::Background::ISmartCardTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::SmsMessageReceivedTrigger> { using default_interface = Windows::ApplicationModel::Background::IBackgroundTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::SocketActivityTrigger> { using default_interface = Windows::ApplicationModel::Background::IBackgroundTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::StorageLibraryContentChangedTrigger> { using default_interface = Windows::ApplicationModel::Background::IStorageLibraryContentChangedTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::SystemCondition> { using default_interface = Windows::ApplicationModel::Background::ISystemCondition; };
template <> struct traits<Windows::ApplicationModel::Background::SystemTrigger> { using default_interface = Windows::ApplicationModel::Background::ISystemTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::TimeTrigger> { using default_interface = Windows::ApplicationModel::Background::ITimeTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::ToastNotificationActionTrigger> { using default_interface = Windows::ApplicationModel::Background::IBackgroundTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::ToastNotificationHistoryChangedTrigger> { using default_interface = Windows::ApplicationModel::Background::IBackgroundTrigger; };
template <> struct traits<Windows::ApplicationModel::Background::UserNotificationChangedTrigger> { using default_interface = Windows::ApplicationModel::Background::IBackgroundTrigger; };

}

namespace Windows::ApplicationModel::Background {

template <typename D>
struct WINRT_EBO impl_IActivitySensorTrigger
{
    Windows::Foundation::Collections::IVector<winrt::Windows::Devices::Sensors::ActivityType> SubscribedActivities() const;
    uint32_t ReportInterval() const;
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::Sensors::ActivityType> SupportedActivities() const;
    uint32_t MinimumReportInterval() const;
};

template <typename D>
struct WINRT_EBO impl_IActivitySensorTriggerFactory
{
    Windows::ApplicationModel::Background::ActivitySensorTrigger Create(uint32_t reportIntervalInMilliseconds) const;
};

template <typename D>
struct WINRT_EBO impl_IAlarmApplicationManagerStatics
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::AlarmAccessStatus> RequestAccessAsync() const;
    Windows::ApplicationModel::Background::AlarmAccessStatus GetAccessStatus() const;
};

template <typename D>
struct WINRT_EBO impl_IApplicationTrigger
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::ApplicationTriggerResult> RequestAsync() const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::ApplicationTriggerResult> RequestAsync(const Windows::Foundation::Collections::ValueSet & arguments) const;
};

template <typename D>
struct WINRT_EBO impl_IApplicationTriggerDetails
{
    Windows::Foundation::Collections::ValueSet Arguments() const;
};

template <typename D>
struct WINRT_EBO impl_IAppointmentStoreNotificationTrigger
{
};

template <typename D>
struct WINRT_EBO impl_IBackgroundCondition
{
};

template <typename D>
struct WINRT_EBO impl_IBackgroundExecutionManagerStatics
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::BackgroundAccessStatus> RequestAccessAsync() const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::BackgroundAccessStatus> RequestAccessAsync(hstring_view applicationId) const;
    void RemoveAccess() const;
    void RemoveAccess(hstring_view applicationId) const;
    Windows::ApplicationModel::Background::BackgroundAccessStatus GetAccessStatus() const;
    Windows::ApplicationModel::Background::BackgroundAccessStatus GetAccessStatus(hstring_view applicationId) const;
};

template <typename D>
struct WINRT_EBO impl_IBackgroundTask
{
    void Run(const Windows::ApplicationModel::Background::IBackgroundTaskInstance & taskInstance) const;
};

template <typename D>
struct WINRT_EBO impl_IBackgroundTaskBuilder
{
    void TaskEntryPoint(hstring_view value) const;
    hstring TaskEntryPoint() const;
    void SetTrigger(const Windows::ApplicationModel::Background::IBackgroundTrigger & trigger) const;
    void AddCondition(const Windows::ApplicationModel::Background::IBackgroundCondition & condition) const;
    void Name(hstring_view value) const;
    hstring Name() const;
    Windows::ApplicationModel::Background::BackgroundTaskRegistration Register() const;
};

template <typename D>
struct WINRT_EBO impl_IBackgroundTaskBuilder2
{
    void CancelOnConditionLoss(bool value) const;
    bool CancelOnConditionLoss() const;
};

template <typename D>
struct WINRT_EBO impl_IBackgroundTaskBuilder3
{
    void IsNetworkRequested(bool value) const;
    bool IsNetworkRequested() const;
};

template <typename D>
struct WINRT_EBO impl_IBackgroundTaskCompletedEventArgs
{
    GUID InstanceId() const;
    void CheckResult() const;
};

template <typename D>
struct WINRT_EBO impl_IBackgroundTaskDeferral
{
    void Complete() const;
};

template <typename D>
struct WINRT_EBO impl_IBackgroundTaskInstance
{
    GUID InstanceId() const;
    Windows::ApplicationModel::Background::BackgroundTaskRegistration Task() const;
    uint32_t Progress() const;
    void Progress(uint32_t value) const;
    Windows::Foundation::IInspectable TriggerDetails() const;
    event_token Canceled(const Windows::ApplicationModel::Background::BackgroundTaskCanceledEventHandler & cancelHandler) const;
    using Canceled_revoker = event_revoker<IBackgroundTaskInstance>;
    Canceled_revoker Canceled(auto_revoke_t, const Windows::ApplicationModel::Background::BackgroundTaskCanceledEventHandler & cancelHandler) const;
    void Canceled(event_token cookie) const;
    uint32_t SuspendedCount() const;
    Windows::ApplicationModel::Background::BackgroundTaskDeferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IBackgroundTaskInstance2
{
    uint32_t GetThrottleCount(Windows::ApplicationModel::Background::BackgroundTaskThrottleCounter counter) const;
};

template <typename D>
struct WINRT_EBO impl_IBackgroundTaskInstance4
{
    Windows::System::User User() const;
};

template <typename D>
struct WINRT_EBO impl_IBackgroundTaskProgressEventArgs
{
    GUID InstanceId() const;
    uint32_t Progress() const;
};

template <typename D>
struct WINRT_EBO impl_IBackgroundTaskRegistration
{
    GUID TaskId() const;
    hstring Name() const;
    event_token Progress(const Windows::ApplicationModel::Background::BackgroundTaskProgressEventHandler & handler) const;
    using Progress_revoker = event_revoker<IBackgroundTaskRegistration>;
    Progress_revoker Progress(auto_revoke_t, const Windows::ApplicationModel::Background::BackgroundTaskProgressEventHandler & handler) const;
    void Progress(event_token cookie) const;
    event_token Completed(const Windows::ApplicationModel::Background::BackgroundTaskCompletedEventHandler & handler) const;
    using Completed_revoker = event_revoker<IBackgroundTaskRegistration>;
    Completed_revoker Completed(auto_revoke_t, const Windows::ApplicationModel::Background::BackgroundTaskCompletedEventHandler & handler) const;
    void Completed(event_token cookie) const;
    void Unregister(bool cancelTask) const;
};

template <typename D>
struct WINRT_EBO impl_IBackgroundTaskRegistration2
{
    Windows::ApplicationModel::Background::IBackgroundTrigger Trigger() const;
};

template <typename D>
struct WINRT_EBO impl_IBackgroundTaskRegistrationStatics
{
    Windows::Foundation::Collections::IMapView<GUID, Windows::ApplicationModel::Background::IBackgroundTaskRegistration> AllTasks() const;
};

template <typename D>
struct WINRT_EBO impl_IBackgroundTrigger
{
};

template <typename D>
struct WINRT_EBO impl_IBackgroundWorkCostStatics
{
    Windows::ApplicationModel::Background::BackgroundWorkCostValue CurrentBackgroundWorkCost() const;
};

template <typename D>
struct WINRT_EBO impl_IBluetoothLEAdvertisementPublisherTrigger
{
    Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisement Advertisement() const;
};

template <typename D>
struct WINRT_EBO impl_IBluetoothLEAdvertisementWatcherTrigger
{
    Windows::Foundation::TimeSpan MinSamplingInterval() const;
    Windows::Foundation::TimeSpan MaxSamplingInterval() const;
    Windows::Foundation::TimeSpan MinOutOfRangeTimeout() const;
    Windows::Foundation::TimeSpan MaxOutOfRangeTimeout() const;
    Windows::Devices::Bluetooth::BluetoothSignalStrengthFilter SignalStrengthFilter() const;
    void SignalStrengthFilter(const Windows::Devices::Bluetooth::BluetoothSignalStrengthFilter & value) const;
    Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFilter AdvertisementFilter() const;
    void AdvertisementFilter(const Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementFilter & value) const;
};

template <typename D>
struct WINRT_EBO impl_ICachedFileUpdaterTrigger
{
};

template <typename D>
struct WINRT_EBO impl_ICachedFileUpdaterTriggerDetails
{
    Windows::Storage::Provider::CachedFileTarget UpdateTarget() const;
    Windows::Storage::Provider::FileUpdateRequest UpdateRequest() const;
    bool CanRequestUserInput() const;
};

template <typename D>
struct WINRT_EBO impl_IChatMessageNotificationTrigger
{
};

template <typename D>
struct WINRT_EBO impl_IChatMessageReceivedNotificationTrigger
{
};

template <typename D>
struct WINRT_EBO impl_ICommunicationBlockingAppSetAsActiveTrigger
{
};

template <typename D>
struct WINRT_EBO impl_IContactStoreNotificationTrigger
{
};

template <typename D>
struct WINRT_EBO impl_IContentPrefetchTrigger
{
    Windows::Foundation::TimeSpan WaitInterval() const;
};

template <typename D>
struct WINRT_EBO impl_IContentPrefetchTriggerFactory
{
    Windows::ApplicationModel::Background::ContentPrefetchTrigger Create(const Windows::Foundation::TimeSpan & waitInterval) const;
};

template <typename D>
struct WINRT_EBO impl_IDeviceConnectionChangeTrigger
{
    hstring DeviceId() const;
    bool CanMaintainConnection() const;
    bool MaintainConnection() const;
    void MaintainConnection(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IDeviceConnectionChangeTriggerStatics
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Background::DeviceConnectionChangeTrigger> FromIdAsync(hstring_view deviceId) const;
};

template <typename D>
struct WINRT_EBO impl_IDeviceManufacturerNotificationTrigger
{
    hstring TriggerQualifier() const;
    bool OneShot() const;
};

template <typename D>
struct WINRT_EBO impl_IDeviceManufacturerNotificationTriggerFactory
{
    Windows::ApplicationModel::Background::DeviceManufacturerNotificationTrigger Create(hstring_view triggerQualifier, bool oneShot) const;
};

template <typename D>
struct WINRT_EBO impl_IDeviceServicingTrigger
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::DeviceTriggerResult> RequestAsync(hstring_view deviceId, const Windows::Foundation::TimeSpan & expectedDuration) const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::DeviceTriggerResult> RequestAsync(hstring_view deviceId, const Windows::Foundation::TimeSpan & expectedDuration, hstring_view arguments) const;
};

template <typename D>
struct WINRT_EBO impl_IDeviceUseTrigger
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::DeviceTriggerResult> RequestAsync(hstring_view deviceId) const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::DeviceTriggerResult> RequestAsync(hstring_view deviceId, hstring_view arguments) const;
};

template <typename D>
struct WINRT_EBO impl_IDeviceWatcherTrigger
{
};

template <typename D>
struct WINRT_EBO impl_IEmailStoreNotificationTrigger
{
};

template <typename D>
struct WINRT_EBO impl_IGattCharacteristicNotificationTrigger
{
    Windows::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic Characteristic() const;
};

template <typename D>
struct WINRT_EBO impl_IGattCharacteristicNotificationTriggerFactory
{
    Windows::ApplicationModel::Background::GattCharacteristicNotificationTrigger Create(const Windows::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic & characteristic) const;
};

template <typename D>
struct WINRT_EBO impl_ILocationTrigger
{
    Windows::ApplicationModel::Background::LocationTriggerType TriggerType() const;
};

template <typename D>
struct WINRT_EBO impl_ILocationTriggerFactory
{
    Windows::ApplicationModel::Background::LocationTrigger Create(Windows::ApplicationModel::Background::LocationTriggerType triggerType) const;
};

template <typename D>
struct WINRT_EBO impl_IMaintenanceTrigger
{
    uint32_t FreshnessTime() const;
    bool OneShot() const;
};

template <typename D>
struct WINRT_EBO impl_IMaintenanceTriggerFactory
{
    Windows::ApplicationModel::Background::MaintenanceTrigger Create(uint32_t freshnessTime, bool oneShot) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaProcessingTrigger
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::MediaProcessingTriggerResult> RequestAsync() const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::Background::MediaProcessingTriggerResult> RequestAsync(const Windows::Foundation::Collections::ValueSet & arguments) const;
};

template <typename D>
struct WINRT_EBO impl_INetworkOperatorHotspotAuthenticationTrigger
{
};

template <typename D>
struct WINRT_EBO impl_INetworkOperatorNotificationTrigger
{
    hstring NetworkAccountId() const;
};

template <typename D>
struct WINRT_EBO impl_INetworkOperatorNotificationTriggerFactory
{
    Windows::ApplicationModel::Background::NetworkOperatorNotificationTrigger Create(hstring_view networkAccountId) const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneTrigger
{
    bool OneShot() const;
    Windows::ApplicationModel::Calls::Background::PhoneTriggerType TriggerType() const;
};

template <typename D>
struct WINRT_EBO impl_IPhoneTriggerFactory
{
    Windows::ApplicationModel::Background::PhoneTrigger Create(Windows::ApplicationModel::Calls::Background::PhoneTriggerType type, bool oneShot) const;
};

template <typename D>
struct WINRT_EBO impl_IPushNotificationTriggerFactory
{
    Windows::ApplicationModel::Background::PushNotificationTrigger Create(hstring_view applicationId) const;
};

template <typename D>
struct WINRT_EBO impl_IRcsEndUserMessageAvailableTrigger
{
};

template <typename D>
struct WINRT_EBO impl_IRfcommConnectionTrigger
{
    Windows::Devices::Bluetooth::Background::RfcommInboundConnectionInformation InboundConnection() const;
    Windows::Devices::Bluetooth::Background::RfcommOutboundConnectionInformation OutboundConnection() const;
    bool AllowMultipleConnections() const;
    void AllowMultipleConnections(bool value) const;
    Windows::Networking::Sockets::SocketProtectionLevel ProtectionLevel() const;
    void ProtectionLevel(Windows::Networking::Sockets::SocketProtectionLevel value) const;
    Windows::Networking::HostName RemoteHostName() const;
    void RemoteHostName(const Windows::Networking::HostName & value) const;
};

template <typename D>
struct WINRT_EBO impl_ISecondaryAuthenticationFactorAuthenticationTrigger
{
};

template <typename D>
struct WINRT_EBO impl_ISensorDataThresholdTrigger
{
};

template <typename D>
struct WINRT_EBO impl_ISensorDataThresholdTriggerFactory
{
    Windows::ApplicationModel::Background::SensorDataThresholdTrigger Create(const Windows::Devices::Sensors::ISensorDataThreshold & threshold) const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardTrigger
{
    Windows::Devices::SmartCards::SmartCardTriggerType TriggerType() const;
};

template <typename D>
struct WINRT_EBO impl_ISmartCardTriggerFactory
{
    Windows::ApplicationModel::Background::SmartCardTrigger Create(Windows::Devices::SmartCards::SmartCardTriggerType triggerType) const;
};

template <typename D>
struct WINRT_EBO impl_ISmsMessageReceivedTriggerFactory
{
    Windows::ApplicationModel::Background::SmsMessageReceivedTrigger Create(const Windows::Devices::Sms::SmsFilterRules & filterRules) const;
};

template <typename D>
struct WINRT_EBO impl_ISocketActivityTrigger
{
    bool IsWakeFromLowPowerSupported() const;
};

template <typename D>
struct WINRT_EBO impl_IStorageLibraryContentChangedTrigger
{
};

template <typename D>
struct WINRT_EBO impl_IStorageLibraryContentChangedTriggerStatics
{
    Windows::ApplicationModel::Background::StorageLibraryContentChangedTrigger Create(const Windows::Storage::StorageLibrary & storageLibrary) const;
    Windows::ApplicationModel::Background::StorageLibraryContentChangedTrigger CreateFromLibraries(iterable<Windows::Storage::StorageLibrary> storageLibraries) const;
};

template <typename D>
struct WINRT_EBO impl_ISystemCondition
{
    Windows::ApplicationModel::Background::SystemConditionType ConditionType() const;
};

template <typename D>
struct WINRT_EBO impl_ISystemConditionFactory
{
    Windows::ApplicationModel::Background::SystemCondition Create(Windows::ApplicationModel::Background::SystemConditionType conditionType) const;
};

template <typename D>
struct WINRT_EBO impl_ISystemTrigger
{
    bool OneShot() const;
    Windows::ApplicationModel::Background::SystemTriggerType TriggerType() const;
};

template <typename D>
struct WINRT_EBO impl_ISystemTriggerFactory
{
    Windows::ApplicationModel::Background::SystemTrigger Create(Windows::ApplicationModel::Background::SystemTriggerType triggerType, bool oneShot) const;
};

template <typename D>
struct WINRT_EBO impl_ITimeTrigger
{
    uint32_t FreshnessTime() const;
    bool OneShot() const;
};

template <typename D>
struct WINRT_EBO impl_ITimeTriggerFactory
{
    Windows::ApplicationModel::Background::TimeTrigger Create(uint32_t freshnessTime, bool oneShot) const;
};

template <typename D>
struct WINRT_EBO impl_IToastNotificationActionTriggerFactory
{
    Windows::ApplicationModel::Background::ToastNotificationActionTrigger Create(hstring_view applicationId) const;
};

template <typename D>
struct WINRT_EBO impl_IToastNotificationHistoryChangedTriggerFactory
{
    Windows::ApplicationModel::Background::ToastNotificationHistoryChangedTrigger Create(hstring_view applicationId) const;
};

template <typename D>
struct WINRT_EBO impl_IUserNotificationChangedTriggerFactory
{
    Windows::ApplicationModel::Background::UserNotificationChangedTrigger Create(Windows::UI::Notifications::NotificationKinds notificationKinds) const;
};

}

namespace impl {

template <> struct traits<Windows::ApplicationModel::Background::BackgroundTaskCanceledEventHandler>
{
    using abi = ABI::Windows::ApplicationModel::Background::BackgroundTaskCanceledEventHandler;
};

template <> struct traits<Windows::ApplicationModel::Background::BackgroundTaskCompletedEventHandler>
{
    using abi = ABI::Windows::ApplicationModel::Background::BackgroundTaskCompletedEventHandler;
};

template <> struct traits<Windows::ApplicationModel::Background::BackgroundTaskProgressEventHandler>
{
    using abi = ABI::Windows::ApplicationModel::Background::BackgroundTaskProgressEventHandler;
};

template <> struct traits<Windows::ApplicationModel::Background::IActivitySensorTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::IActivitySensorTrigger;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IActivitySensorTrigger<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IActivitySensorTriggerFactory>
{
    using abi = ABI::Windows::ApplicationModel::Background::IActivitySensorTriggerFactory;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IActivitySensorTriggerFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IAlarmApplicationManagerStatics>
{
    using abi = ABI::Windows::ApplicationModel::Background::IAlarmApplicationManagerStatics;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IAlarmApplicationManagerStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IApplicationTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::IApplicationTrigger;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IApplicationTrigger<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IApplicationTriggerDetails>
{
    using abi = ABI::Windows::ApplicationModel::Background::IApplicationTriggerDetails;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IApplicationTriggerDetails<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IAppointmentStoreNotificationTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::IAppointmentStoreNotificationTrigger;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IAppointmentStoreNotificationTrigger<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IBackgroundCondition>
{
    using abi = ABI::Windows::ApplicationModel::Background::IBackgroundCondition;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IBackgroundCondition<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IBackgroundExecutionManagerStatics>
{
    using abi = ABI::Windows::ApplicationModel::Background::IBackgroundExecutionManagerStatics;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IBackgroundExecutionManagerStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IBackgroundTask>
{
    using abi = ABI::Windows::ApplicationModel::Background::IBackgroundTask;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IBackgroundTask<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IBackgroundTaskBuilder>
{
    using abi = ABI::Windows::ApplicationModel::Background::IBackgroundTaskBuilder;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IBackgroundTaskBuilder<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IBackgroundTaskBuilder2>
{
    using abi = ABI::Windows::ApplicationModel::Background::IBackgroundTaskBuilder2;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IBackgroundTaskBuilder2<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IBackgroundTaskBuilder3>
{
    using abi = ABI::Windows::ApplicationModel::Background::IBackgroundTaskBuilder3;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IBackgroundTaskBuilder3<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IBackgroundTaskCompletedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Background::IBackgroundTaskCompletedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IBackgroundTaskCompletedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IBackgroundTaskDeferral>
{
    using abi = ABI::Windows::ApplicationModel::Background::IBackgroundTaskDeferral;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IBackgroundTaskDeferral<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IBackgroundTaskInstance>
{
    using abi = ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IBackgroundTaskInstance<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IBackgroundTaskInstance2>
{
    using abi = ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance2;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IBackgroundTaskInstance2<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IBackgroundTaskInstance4>
{
    using abi = ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance4;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IBackgroundTaskInstance4<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IBackgroundTaskProgressEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Background::IBackgroundTaskProgressEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IBackgroundTaskProgressEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IBackgroundTaskRegistration>
{
    using abi = ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IBackgroundTaskRegistration<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IBackgroundTaskRegistration2>
{
    using abi = ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration2;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IBackgroundTaskRegistration2<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IBackgroundTaskRegistrationStatics>
{
    using abi = ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistrationStatics;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IBackgroundTaskRegistrationStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IBackgroundTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::IBackgroundTrigger;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IBackgroundTrigger<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IBackgroundWorkCostStatics>
{
    using abi = ABI::Windows::ApplicationModel::Background::IBackgroundWorkCostStatics;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IBackgroundWorkCostStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IBluetoothLEAdvertisementPublisherTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::IBluetoothLEAdvertisementPublisherTrigger;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IBluetoothLEAdvertisementPublisherTrigger<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IBluetoothLEAdvertisementWatcherTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::IBluetoothLEAdvertisementWatcherTrigger;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IBluetoothLEAdvertisementWatcherTrigger<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::ICachedFileUpdaterTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::ICachedFileUpdaterTrigger;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_ICachedFileUpdaterTrigger<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::ICachedFileUpdaterTriggerDetails>
{
    using abi = ABI::Windows::ApplicationModel::Background::ICachedFileUpdaterTriggerDetails;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_ICachedFileUpdaterTriggerDetails<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IChatMessageNotificationTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::IChatMessageNotificationTrigger;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IChatMessageNotificationTrigger<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IChatMessageReceivedNotificationTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::IChatMessageReceivedNotificationTrigger;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IChatMessageReceivedNotificationTrigger<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::ICommunicationBlockingAppSetAsActiveTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::ICommunicationBlockingAppSetAsActiveTrigger;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_ICommunicationBlockingAppSetAsActiveTrigger<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IContactStoreNotificationTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::IContactStoreNotificationTrigger;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IContactStoreNotificationTrigger<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IContentPrefetchTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::IContentPrefetchTrigger;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IContentPrefetchTrigger<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IContentPrefetchTriggerFactory>
{
    using abi = ABI::Windows::ApplicationModel::Background::IContentPrefetchTriggerFactory;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IContentPrefetchTriggerFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IDeviceConnectionChangeTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::IDeviceConnectionChangeTrigger;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IDeviceConnectionChangeTrigger<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IDeviceConnectionChangeTriggerStatics>
{
    using abi = ABI::Windows::ApplicationModel::Background::IDeviceConnectionChangeTriggerStatics;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IDeviceConnectionChangeTriggerStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IDeviceManufacturerNotificationTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::IDeviceManufacturerNotificationTrigger;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IDeviceManufacturerNotificationTrigger<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IDeviceManufacturerNotificationTriggerFactory>
{
    using abi = ABI::Windows::ApplicationModel::Background::IDeviceManufacturerNotificationTriggerFactory;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IDeviceManufacturerNotificationTriggerFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IDeviceServicingTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::IDeviceServicingTrigger;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IDeviceServicingTrigger<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IDeviceUseTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::IDeviceUseTrigger;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IDeviceUseTrigger<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IDeviceWatcherTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::IDeviceWatcherTrigger;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IDeviceWatcherTrigger<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IEmailStoreNotificationTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::IEmailStoreNotificationTrigger;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IEmailStoreNotificationTrigger<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IGattCharacteristicNotificationTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::IGattCharacteristicNotificationTrigger;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IGattCharacteristicNotificationTrigger<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IGattCharacteristicNotificationTriggerFactory>
{
    using abi = ABI::Windows::ApplicationModel::Background::IGattCharacteristicNotificationTriggerFactory;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IGattCharacteristicNotificationTriggerFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::ILocationTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::ILocationTrigger;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_ILocationTrigger<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::ILocationTriggerFactory>
{
    using abi = ABI::Windows::ApplicationModel::Background::ILocationTriggerFactory;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_ILocationTriggerFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IMaintenanceTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::IMaintenanceTrigger;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IMaintenanceTrigger<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IMaintenanceTriggerFactory>
{
    using abi = ABI::Windows::ApplicationModel::Background::IMaintenanceTriggerFactory;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IMaintenanceTriggerFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IMediaProcessingTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::IMediaProcessingTrigger;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IMediaProcessingTrigger<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::INetworkOperatorHotspotAuthenticationTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::INetworkOperatorHotspotAuthenticationTrigger;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_INetworkOperatorHotspotAuthenticationTrigger<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::INetworkOperatorNotificationTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::INetworkOperatorNotificationTrigger;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_INetworkOperatorNotificationTrigger<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::INetworkOperatorNotificationTriggerFactory>
{
    using abi = ABI::Windows::ApplicationModel::Background::INetworkOperatorNotificationTriggerFactory;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_INetworkOperatorNotificationTriggerFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IPhoneTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::IPhoneTrigger;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IPhoneTrigger<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IPhoneTriggerFactory>
{
    using abi = ABI::Windows::ApplicationModel::Background::IPhoneTriggerFactory;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IPhoneTriggerFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IPushNotificationTriggerFactory>
{
    using abi = ABI::Windows::ApplicationModel::Background::IPushNotificationTriggerFactory;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IPushNotificationTriggerFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IRcsEndUserMessageAvailableTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::IRcsEndUserMessageAvailableTrigger;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IRcsEndUserMessageAvailableTrigger<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IRfcommConnectionTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::IRfcommConnectionTrigger;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IRfcommConnectionTrigger<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::ISecondaryAuthenticationFactorAuthenticationTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::ISecondaryAuthenticationFactorAuthenticationTrigger;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_ISecondaryAuthenticationFactorAuthenticationTrigger<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::ISensorDataThresholdTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::ISensorDataThresholdTrigger;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_ISensorDataThresholdTrigger<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::ISensorDataThresholdTriggerFactory>
{
    using abi = ABI::Windows::ApplicationModel::Background::ISensorDataThresholdTriggerFactory;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_ISensorDataThresholdTriggerFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::ISmartCardTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::ISmartCardTrigger;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_ISmartCardTrigger<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::ISmartCardTriggerFactory>
{
    using abi = ABI::Windows::ApplicationModel::Background::ISmartCardTriggerFactory;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_ISmartCardTriggerFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::ISmsMessageReceivedTriggerFactory>
{
    using abi = ABI::Windows::ApplicationModel::Background::ISmsMessageReceivedTriggerFactory;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_ISmsMessageReceivedTriggerFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::ISocketActivityTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::ISocketActivityTrigger;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_ISocketActivityTrigger<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IStorageLibraryContentChangedTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::IStorageLibraryContentChangedTrigger;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IStorageLibraryContentChangedTrigger<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IStorageLibraryContentChangedTriggerStatics>
{
    using abi = ABI::Windows::ApplicationModel::Background::IStorageLibraryContentChangedTriggerStatics;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IStorageLibraryContentChangedTriggerStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::ISystemCondition>
{
    using abi = ABI::Windows::ApplicationModel::Background::ISystemCondition;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_ISystemCondition<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::ISystemConditionFactory>
{
    using abi = ABI::Windows::ApplicationModel::Background::ISystemConditionFactory;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_ISystemConditionFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::ISystemTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::ISystemTrigger;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_ISystemTrigger<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::ISystemTriggerFactory>
{
    using abi = ABI::Windows::ApplicationModel::Background::ISystemTriggerFactory;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_ISystemTriggerFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::ITimeTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::ITimeTrigger;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_ITimeTrigger<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::ITimeTriggerFactory>
{
    using abi = ABI::Windows::ApplicationModel::Background::ITimeTriggerFactory;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_ITimeTriggerFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IToastNotificationActionTriggerFactory>
{
    using abi = ABI::Windows::ApplicationModel::Background::IToastNotificationActionTriggerFactory;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IToastNotificationActionTriggerFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IToastNotificationHistoryChangedTriggerFactory>
{
    using abi = ABI::Windows::ApplicationModel::Background::IToastNotificationHistoryChangedTriggerFactory;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IToastNotificationHistoryChangedTriggerFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::IUserNotificationChangedTriggerFactory>
{
    using abi = ABI::Windows::ApplicationModel::Background::IUserNotificationChangedTriggerFactory;
    template <typename D> using consume = Windows::ApplicationModel::Background::impl_IUserNotificationChangedTriggerFactory<D>;
};

template <> struct traits<Windows::ApplicationModel::Background::ActivitySensorTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::ActivitySensorTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.ActivitySensorTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::AlarmApplicationManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.AlarmApplicationManager"; }
};

template <> struct traits<Windows::ApplicationModel::Background::ApplicationTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::ApplicationTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.ApplicationTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::ApplicationTriggerDetails>
{
    using abi = ABI::Windows::ApplicationModel::Background::ApplicationTriggerDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.ApplicationTriggerDetails"; }
};

template <> struct traits<Windows::ApplicationModel::Background::AppointmentStoreNotificationTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::AppointmentStoreNotificationTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.AppointmentStoreNotificationTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::BackgroundExecutionManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.BackgroundExecutionManager"; }
};

template <> struct traits<Windows::ApplicationModel::Background::BackgroundTaskBuilder>
{
    using abi = ABI::Windows::ApplicationModel::Background::BackgroundTaskBuilder;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.BackgroundTaskBuilder"; }
};

template <> struct traits<Windows::ApplicationModel::Background::BackgroundTaskCompletedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Background::BackgroundTaskCompletedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.BackgroundTaskCompletedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Background::BackgroundTaskDeferral>
{
    using abi = ABI::Windows::ApplicationModel::Background::BackgroundTaskDeferral;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.BackgroundTaskDeferral"; }
};

template <> struct traits<Windows::ApplicationModel::Background::BackgroundTaskProgressEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Background::BackgroundTaskProgressEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.BackgroundTaskProgressEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Background::BackgroundTaskRegistration>
{
    using abi = ABI::Windows::ApplicationModel::Background::BackgroundTaskRegistration;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.BackgroundTaskRegistration"; }
};

template <> struct traits<Windows::ApplicationModel::Background::BackgroundWorkCost>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.BackgroundWorkCost"; }
};

template <> struct traits<Windows::ApplicationModel::Background::BluetoothLEAdvertisementPublisherTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::BluetoothLEAdvertisementPublisherTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.BluetoothLEAdvertisementPublisherTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::BluetoothLEAdvertisementWatcherTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::BluetoothLEAdvertisementWatcherTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.BluetoothLEAdvertisementWatcherTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::CachedFileUpdaterTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::CachedFileUpdaterTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.CachedFileUpdaterTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::CachedFileUpdaterTriggerDetails>
{
    using abi = ABI::Windows::ApplicationModel::Background::CachedFileUpdaterTriggerDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.CachedFileUpdaterTriggerDetails"; }
};

template <> struct traits<Windows::ApplicationModel::Background::ChatMessageNotificationTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::ChatMessageNotificationTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.ChatMessageNotificationTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::ChatMessageReceivedNotificationTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::ChatMessageReceivedNotificationTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.ChatMessageReceivedNotificationTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::CommunicationBlockingAppSetAsActiveTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::CommunicationBlockingAppSetAsActiveTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.CommunicationBlockingAppSetAsActiveTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::ContactStoreNotificationTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::ContactStoreNotificationTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.ContactStoreNotificationTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::ContentPrefetchTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::ContentPrefetchTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.ContentPrefetchTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::DeviceConnectionChangeTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::DeviceConnectionChangeTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.DeviceConnectionChangeTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::DeviceManufacturerNotificationTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::DeviceManufacturerNotificationTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.DeviceManufacturerNotificationTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::DeviceServicingTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::DeviceServicingTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.DeviceServicingTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::DeviceUseTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::DeviceUseTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.DeviceUseTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::DeviceWatcherTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::DeviceWatcherTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.DeviceWatcherTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::EmailStoreNotificationTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::EmailStoreNotificationTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.EmailStoreNotificationTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::GattCharacteristicNotificationTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::GattCharacteristicNotificationTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.GattCharacteristicNotificationTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::LocationTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::LocationTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.LocationTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::MaintenanceTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::MaintenanceTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.MaintenanceTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::MediaProcessingTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::MediaProcessingTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.MediaProcessingTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::MobileBroadbandDeviceServiceNotificationTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::MobileBroadbandDeviceServiceNotificationTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.MobileBroadbandDeviceServiceNotificationTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::MobileBroadbandPinLockStateChangeTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::MobileBroadbandPinLockStateChangeTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.MobileBroadbandPinLockStateChangeTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::MobileBroadbandRadioStateChangeTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::MobileBroadbandRadioStateChangeTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.MobileBroadbandRadioStateChangeTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::MobileBroadbandRegistrationStateChangeTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::MobileBroadbandRegistrationStateChangeTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.MobileBroadbandRegistrationStateChangeTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::NetworkOperatorHotspotAuthenticationTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::NetworkOperatorHotspotAuthenticationTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.NetworkOperatorHotspotAuthenticationTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::NetworkOperatorNotificationTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::NetworkOperatorNotificationTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.NetworkOperatorNotificationTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::PhoneTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::PhoneTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.PhoneTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::PushNotificationTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::PushNotificationTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.PushNotificationTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::RcsEndUserMessageAvailableTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::RcsEndUserMessageAvailableTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.RcsEndUserMessageAvailableTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::RfcommConnectionTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::RfcommConnectionTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.RfcommConnectionTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::SecondaryAuthenticationFactorAuthenticationTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::SecondaryAuthenticationFactorAuthenticationTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.SecondaryAuthenticationFactorAuthenticationTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::SensorDataThresholdTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::SensorDataThresholdTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.SensorDataThresholdTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::SmartCardTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::SmartCardTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.SmartCardTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::SmsMessageReceivedTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::SmsMessageReceivedTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.SmsMessageReceivedTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::SocketActivityTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::SocketActivityTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.SocketActivityTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::StorageLibraryContentChangedTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::StorageLibraryContentChangedTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.StorageLibraryContentChangedTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::SystemCondition>
{
    using abi = ABI::Windows::ApplicationModel::Background::SystemCondition;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.SystemCondition"; }
};

template <> struct traits<Windows::ApplicationModel::Background::SystemTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::SystemTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.SystemTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::TimeTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::TimeTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.TimeTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::ToastNotificationActionTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::ToastNotificationActionTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.ToastNotificationActionTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::ToastNotificationHistoryChangedTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::ToastNotificationHistoryChangedTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.ToastNotificationHistoryChangedTrigger"; }
};

template <> struct traits<Windows::ApplicationModel::Background::UserNotificationChangedTrigger>
{
    using abi = ABI::Windows::ApplicationModel::Background::UserNotificationChangedTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Background.UserNotificationChangedTrigger"; }
};

}

}
