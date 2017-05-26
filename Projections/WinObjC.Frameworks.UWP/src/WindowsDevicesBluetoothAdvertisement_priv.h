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

// WindowsDevicesBluetoothAdvertisement_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsStorageStreams_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsDevicesBluetooth_priv.h"
static ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEManufacturerDataFactory>
WDBAIBluetoothLEManufacturerDataFactory_inst();
static ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataSectionFactory>
WDBAIBluetoothLEAdvertisementDataSectionFactory_inst();
static ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementBytePatternFactory>
WDBAIBluetoothLEAdvertisementBytePatternFactory_inst();
static ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcherFactory>
WDBAIBluetoothLEAdvertisementWatcherFactory_inst();
ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementDataTypesStatics>
WDBAIBluetoothLEAdvertisementDataTypesStatics_inst();
static ComPtr<ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisherFactory>
WDBAIBluetoothLEAdvertisementPublisherFactory_inst();

id RTProxiedNSArray_WDBABluetoothLEAdvertisementDataSection_create(IInspectable* val);
id RTProxiedNSArray_WDBABluetoothLEManufacturerData_create(IInspectable* val);
id RTProxiedNSMutableArray_WDBABluetoothLEAdvertisementBytePattern_create(IInspectable* val);
id RTProxiedNSMutableArray_WDBABluetoothLEAdvertisementDataSection_create(IInspectable* val);
id RTProxiedNSMutableArray_WDBABluetoothLEManufacturerData_create(IInspectable* val);
id RTProxiedNSMutableArray_WFGUID_create(IInspectable* val);

@class Nullable_WDBABluetoothLEAdvertisementFlags, RTProxiedNSArray_WDBABluetoothLEAdvertisementDataSection,
    RTProxiedNSArray_WDBABluetoothLEManufacturerData;
@class RTProxiedNSMutableArray_WDBABluetoothLEAdvertisementBytePattern, RTProxiedNSMutableArray_WDBABluetoothLEAdvertisementDataSection;
@class RTProxiedNSMutableArray_WDBABluetoothLEManufacturerData, RTProxiedNSMutableArray_WFGUID;

#ifndef __ITypedEventHandler_Windows_Devices_Bluetooth_Advertisement_BluetoothLEAdvertisementPublisher_Windows_Devices_Bluetooth_Advertisement_BluetoothLEAdvertisementPublisherStatusChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Bluetooth_Advertisement_BluetoothLEAdvertisementPublisher_Windows_Devices_Bluetooth_Advertisement_BluetoothLEAdvertisementPublisherStatusChangedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_Bluetooth_Advertisement_BluetoothLEAdvertisementPublisher_Windows_Devices_Bluetooth_Advertisement_BluetoothLEAdvertisementPublisherStatusChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisher*,
                              ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementPublisherStatusChangedEventArgs*>> {
    void (^_delegate)(WDBABluetoothLEAdvertisementPublisher*, WDBABluetoothLEAdvertisementPublisherStatusChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Bluetooth_Advertisement_BluetoothLEAdvertisementPublisher_Windows_Devices_Bluetooth_Advertisement_BluetoothLEAdvertisementPublisherStatusChangedEventArgs(
        void (^del)(WDBABluetoothLEAdvertisementPublisher*, WDBABluetoothLEAdvertisementPublisherStatusChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Bluetooth_Advertisement_BluetoothLEAdvertisementPublisher_Windows_Devices_Bluetooth_Advertisement_BluetoothLEAdvertisementPublisherStatusChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisher* arg0,
           ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementPublisherStatusChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDBABluetoothLEAdvertisementPublisher>(arg0),
                      _createRtProxy<WDBABluetoothLEAdvertisementPublisherStatusChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Bluetooth_Advertisement_BluetoothLEAdvertisementWatcher_Windows_Devices_Bluetooth_Advertisement_BluetoothLEAdvertisementReceivedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Bluetooth_Advertisement_BluetoothLEAdvertisementWatcher_Windows_Devices_Bluetooth_Advertisement_BluetoothLEAdvertisementReceivedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_Bluetooth_Advertisement_BluetoothLEAdvertisementWatcher_Windows_Devices_Bluetooth_Advertisement_BluetoothLEAdvertisementReceivedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcher*,
                              ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementReceivedEventArgs*>> {
    void (^_delegate)(WDBABluetoothLEAdvertisementWatcher*, WDBABluetoothLEAdvertisementReceivedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Bluetooth_Advertisement_BluetoothLEAdvertisementWatcher_Windows_Devices_Bluetooth_Advertisement_BluetoothLEAdvertisementReceivedEventArgs(
        void (^del)(WDBABluetoothLEAdvertisementWatcher*, WDBABluetoothLEAdvertisementReceivedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Bluetooth_Advertisement_BluetoothLEAdvertisementWatcher_Windows_Devices_Bluetooth_Advertisement_BluetoothLEAdvertisementReceivedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher* arg0,
           ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementReceivedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDBABluetoothLEAdvertisementWatcher>(arg0),
                      _createRtProxy<WDBABluetoothLEAdvertisementReceivedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Bluetooth_Advertisement_BluetoothLEAdvertisementWatcher_Windows_Devices_Bluetooth_Advertisement_BluetoothLEAdvertisementWatcherStoppedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Bluetooth_Advertisement_BluetoothLEAdvertisementWatcher_Windows_Devices_Bluetooth_Advertisement_BluetoothLEAdvertisementWatcherStoppedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_Bluetooth_Advertisement_BluetoothLEAdvertisementWatcher_Windows_Devices_Bluetooth_Advertisement_BluetoothLEAdvertisementWatcherStoppedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcher*,
                              ABI::Windows::Devices::Bluetooth::Advertisement::BluetoothLEAdvertisementWatcherStoppedEventArgs*>> {
    void (^_delegate)(WDBABluetoothLEAdvertisementWatcher*, WDBABluetoothLEAdvertisementWatcherStoppedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Bluetooth_Advertisement_BluetoothLEAdvertisementWatcher_Windows_Devices_Bluetooth_Advertisement_BluetoothLEAdvertisementWatcherStoppedEventArgs(
        void (^del)(WDBABluetoothLEAdvertisementWatcher*, WDBABluetoothLEAdvertisementWatcherStoppedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Bluetooth_Advertisement_BluetoothLEAdvertisementWatcher_Windows_Devices_Bluetooth_Advertisement_BluetoothLEAdvertisementWatcherStoppedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcher* arg0,
           ABI::Windows::Devices::Bluetooth::Advertisement::IBluetoothLEAdvertisementWatcherStoppedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDBABluetoothLEAdvertisementWatcher>(arg0),
                      _createRtProxy<WDBABluetoothLEAdvertisementWatcherStoppedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
