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

// WindowsApplicationModelBackground_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsSystem_priv.h"
#include "WindowsApplicationModelCallsBackground_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsDevicesSmartCards_priv.h"
#include "WindowsDevicesSms_priv.h"
#include "WindowsFoundationCollections_priv.h"
#include "WindowsStorage_priv.h"
#include "WindowsStorageProvider_priv.h"
#include "WindowsDevicesBluetooth_priv.h"
#include "WindowsDevicesBluetoothBackground_priv.h"
#include "WindowsNetworkingSockets_priv.h"
#include "WindowsNetworking_priv.h"
#include "WindowsDevicesBluetoothGenericAttributeProfile_priv.h"
#include "WindowsDevicesBluetoothAdvertisement_priv.h"
#include "WindowsDevicesSensors_priv.h"
#include "WindowsUINotifications_priv.h"
ComPtr<ABI::Windows::ApplicationModel::Background::IAlarmApplicationManagerStatics> WABIAlarmApplicationManagerStatics_inst();
static ComPtr<ABI::Windows::ApplicationModel::Background::IPhoneTriggerFactory> WABIPhoneTriggerFactory_inst();
static ComPtr<ABI::Windows::ApplicationModel::Background::ISmartCardTriggerFactory> WABISmartCardTriggerFactory_inst();
ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundExecutionManagerStatics> WABIBackgroundExecutionManagerStatics_inst();
ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistrationStatics> WABIBackgroundTaskRegistrationStatics_inst();
ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundWorkCostStatics> WABIBackgroundWorkCostStatics_inst();
static ComPtr<ABI::Windows::ApplicationModel::Background::IContentPrefetchTriggerFactory> WABIContentPrefetchTriggerFactory_inst();
static ComPtr<ABI::Windows::ApplicationModel::Background::ISmsMessageReceivedTriggerFactory> WABISmsMessageReceivedTriggerFactory_inst();
ComPtr<ABI::Windows::ApplicationModel::Background::IStorageLibraryContentChangedTriggerStatics>
WABIStorageLibraryContentChangedTriggerStatics_inst();
static ComPtr<ABI::Windows::ApplicationModel::Background::ISystemTriggerFactory> WABISystemTriggerFactory_inst();
static ComPtr<ABI::Windows::ApplicationModel::Background::ISystemConditionFactory> WABISystemConditionFactory_inst();
static ComPtr<ABI::Windows::ApplicationModel::Background::INetworkOperatorNotificationTriggerFactory>
WABINetworkOperatorNotificationTriggerFactory_inst();
static ComPtr<ABI::Windows::ApplicationModel::Background::IDeviceManufacturerNotificationTriggerFactory>
WABIDeviceManufacturerNotificationTriggerFactory_inst();
static ComPtr<ABI::Windows::ApplicationModel::Background::ITimeTriggerFactory> WABITimeTriggerFactory_inst();
static ComPtr<ABI::Windows::ApplicationModel::Background::IMaintenanceTriggerFactory> WABIMaintenanceTriggerFactory_inst();
ComPtr<ABI::Windows::ApplicationModel::Background::IDeviceConnectionChangeTriggerStatics> WABIDeviceConnectionChangeTriggerStatics_inst();
static ComPtr<ABI::Windows::ApplicationModel::Background::IGattCharacteristicNotificationTriggerFactory>
WABIGattCharacteristicNotificationTriggerFactory_inst();
static ComPtr<ABI::Windows::ApplicationModel::Background::ILocationTriggerFactory> WABILocationTriggerFactory_inst();
static ComPtr<ABI::Windows::ApplicationModel::Background::IActivitySensorTriggerFactory> WABIActivitySensorTriggerFactory_inst();
static ComPtr<ABI::Windows::ApplicationModel::Background::ISensorDataThresholdTriggerFactory> WABISensorDataThresholdTriggerFactory_inst();
static ComPtr<ABI::Windows::ApplicationModel::Background::IPushNotificationTriggerFactory> WABIPushNotificationTriggerFactory_inst();
static ComPtr<ABI::Windows::ApplicationModel::Background::IToastNotificationHistoryChangedTriggerFactory>
WABIToastNotificationHistoryChangedTriggerFactory_inst();
static ComPtr<ABI::Windows::ApplicationModel::Background::IToastNotificationActionTriggerFactory>
WABIToastNotificationActionTriggerFactory_inst();
static ComPtr<ABI::Windows::ApplicationModel::Background::IUserNotificationChangedTriggerFactory>
WABIUserNotificationChangedTriggerFactory_inst();

id RTProxiedIterableNSArray_WSStorageLibrary_create(IInspectable* val);
id RTProxiedNSArray_WDSActivityType_create(IInspectable* val);
id RTProxiedNSDictionary_WFGUID_RTObject_WABIBackgroundTaskRegistration_create(IInspectable* val);
id RTProxiedNSMutableArray_WDSActivityType_create(IInspectable* val);

@class RTProxiedIterableNSArray_WSStorageLibrary, RTProxiedNSArray_WDSActivityType,
    RTProxiedNSDictionary_WFGUID_RTObject_WABIBackgroundTaskRegistration;
@class RTProxiedNSMutableArray_WDSActivityType;

#ifndef __WABBackgroundTaskCanceledEventHandler_shim__DEFINED
#define __WABBackgroundTaskCanceledEventHandler_shim__DEFINED
class WABBackgroundTaskCanceledEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::ApplicationModel::Background::IBackgroundTaskCanceledEventHandler> {
    void (^_delegate)(RTObject<WABIBackgroundTaskInstance>*, WABBackgroundTaskCancellationReason);

public:
    WABBackgroundTaskCanceledEventHandler_shim(void (^del)(RTObject<WABIBackgroundTaskInstance>*, WABBackgroundTaskCancellationReason))
        : _delegate([del copy]) {
    }
    ~WABBackgroundTaskCanceledEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::Background::IBackgroundTaskInstance* arg0,
                                             ABI::Windows::ApplicationModel::Background::BackgroundTaskCancellationReason arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WABIBackgroundTaskInstance>(arg0), (WABBackgroundTaskCancellationReason)arg1);
            return 0;
        };
    }
};
#endif

#ifndef __WABBackgroundTaskCompletedEventHandler_shim__DEFINED
#define __WABBackgroundTaskCompletedEventHandler_shim__DEFINED
class WABBackgroundTaskCompletedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::ApplicationModel::Background::IBackgroundTaskCompletedEventHandler> {
    void (^_delegate)(WABBackgroundTaskRegistration*, WABBackgroundTaskCompletedEventArgs*);

public:
    WABBackgroundTaskCompletedEventHandler_shim(void (^del)(WABBackgroundTaskRegistration*, WABBackgroundTaskCompletedEventArgs*))
        : _delegate([del copy]) {
    }
    ~WABBackgroundTaskCompletedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration* arg0,
                                             ABI::Windows::ApplicationModel::Background::IBackgroundTaskCompletedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WABBackgroundTaskRegistration>(arg0), _createRtProxy<WABBackgroundTaskCompletedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WABBackgroundTaskProgressEventHandler_shim__DEFINED
#define __WABBackgroundTaskProgressEventHandler_shim__DEFINED
class WABBackgroundTaskProgressEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::ApplicationModel::Background::IBackgroundTaskProgressEventHandler> {
    void (^_delegate)(WABBackgroundTaskRegistration*, WABBackgroundTaskProgressEventArgs*);

public:
    WABBackgroundTaskProgressEventHandler_shim(void (^del)(WABBackgroundTaskRegistration*, WABBackgroundTaskProgressEventArgs*))
        : _delegate([del copy]) {
    }
    ~WABBackgroundTaskProgressEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::Background::IBackgroundTaskRegistration* arg0,
                                             ABI::Windows::ApplicationModel::Background::IBackgroundTaskProgressEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WABBackgroundTaskRegistration>(arg0), _createRtProxy<WABBackgroundTaskProgressEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
