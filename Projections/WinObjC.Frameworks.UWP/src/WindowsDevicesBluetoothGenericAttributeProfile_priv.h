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

// WindowsDevicesBluetoothGenericAttributeProfile_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsDevicesBluetooth_priv.h"
#include "WindowsStorageStreams_priv.h"
ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDeviceServiceStatics> WDBGIGattDeviceServiceStatics_inst();
ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristicStatics> WDBGIGattCharacteristicStatics_inst();
ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDescriptorStatics> WDBGIGattDescriptorStatics_inst();
ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattPresentationFormatStatics> WDBGIGattPresentationFormatStatics_inst();
ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattServiceUuidsStatics> WDBGIGattServiceUuidsStatics_inst();
ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattServiceUuidsStatics2> WDBGIGattServiceUuidsStatics2_inst();
ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristicUuidsStatics>
WDBGIGattCharacteristicUuidsStatics_inst();
ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristicUuidsStatics2>
WDBGIGattCharacteristicUuidsStatics2_inst();
ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDescriptorUuidsStatics> WDBGIGattDescriptorUuidsStatics_inst();
ComPtr<ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattPresentationFormatTypesStatics>
WDBGIGattPresentationFormatTypesStatics_inst();

id RTProxiedNSArray_WDBGGattCharacteristic_create(IInspectable* val);
id RTProxiedNSArray_WDBGGattDescriptor_create(IInspectable* val);
id RTProxiedNSArray_WDBGGattDeviceService_create(IInspectable* val);
id RTProxiedNSArray_WDBGGattPresentationFormat_create(IInspectable* val);

@class RTProxiedNSArray_WDBGGattCharacteristic, RTProxiedNSArray_WDBGGattDescriptor, RTProxiedNSArray_WDBGGattDeviceService,
    RTProxiedNSArray_WDBGGattPresentationFormat;

#ifndef __ITypedEventHandler_Windows_Devices_Bluetooth_GenericAttributeProfile_GattCharacteristic_Windows_Devices_Bluetooth_GenericAttributeProfile_GattValueChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Bluetooth_GenericAttributeProfile_GattCharacteristic_Windows_Devices_Bluetooth_GenericAttributeProfile_GattValueChangedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_Bluetooth_GenericAttributeProfile_GattCharacteristic_Windows_Devices_Bluetooth_GenericAttributeProfile_GattValueChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic*,
                              ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattValueChangedEventArgs*>> {
    void (^_delegate)(WDBGGattCharacteristic*, WDBGGattValueChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Bluetooth_GenericAttributeProfile_GattCharacteristic_Windows_Devices_Bluetooth_GenericAttributeProfile_GattValueChangedEventArgs(
        void (^del)(WDBGGattCharacteristic*, WDBGGattValueChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Bluetooth_GenericAttributeProfile_GattCharacteristic_Windows_Devices_Bluetooth_GenericAttributeProfile_GattValueChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic* arg0,
           ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattValueChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDBGGattCharacteristic>(arg0), _createRtProxy<WDBGGattValueChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
