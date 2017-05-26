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

// WindowsDevicesBluetooth_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsDevicesBluetoothGenericAttributeProfile_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsNetworking_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsDevicesBluetoothRfcomm_priv.h"
#include "WindowsDevicesEnumeration_priv.h"
ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothDeviceStatics> WDBIBluetoothDeviceStatics_inst();
ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothDeviceStatics2> WDBIBluetoothDeviceStatics2_inst();
ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothClassOfDeviceStatics> WDBIBluetoothClassOfDeviceStatics_inst();
ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothLEAppearanceCategoriesStatics> WDBIBluetoothLEAppearanceCategoriesStatics_inst();
ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothLEAppearanceSubcategoriesStatics> WDBIBluetoothLEAppearanceSubcategoriesStatics_inst();
ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothLEAppearanceStatics> WDBIBluetoothLEAppearanceStatics_inst();
ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothLEDeviceStatics> WDBIBluetoothLEDeviceStatics_inst();
ComPtr<ABI::Windows::Devices::Bluetooth::IBluetoothLEDeviceStatics2> WDBIBluetoothLEDeviceStatics2_inst();

id RTProxiedNSArray_RTObject_WSSIBuffer_create(IInspectable* val);
id RTProxiedNSArray_WDBGGattDeviceService_create(IInspectable* val);
id RTProxiedNSArray_WDBRRfcommDeviceService_create(IInspectable* val);

@class Nullable_Int16, Nullable_WFTimeSpan, RTProxiedNSArray_RTObject_WSSIBuffer, RTProxiedNSArray_WDBGGattDeviceService,
    RTProxiedNSArray_WDBRRfcommDeviceService;

#ifndef __ITypedEventHandler_Windows_Devices_Bluetooth_BluetoothDevice_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Devices_Bluetooth_BluetoothDevice_System_Object__DEFINED
class ITypedEventHandler_Windows_Devices_Bluetooth_BluetoothDevice_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Bluetooth::BluetoothDevice*, IInspectable*>> {
    void (^_delegate)(WDBBluetoothDevice*, RTObject*);

public:
    ITypedEventHandler_Windows_Devices_Bluetooth_BluetoothDevice_System_Object(void (^del)(WDBBluetoothDevice*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Bluetooth_BluetoothDevice_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Bluetooth::IBluetoothDevice* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDBBluetoothDevice>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Bluetooth_BluetoothLEDevice_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Devices_Bluetooth_BluetoothLEDevice_System_Object__DEFINED
class ITypedEventHandler_Windows_Devices_Bluetooth_BluetoothLEDevice_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Bluetooth::BluetoothLEDevice*, IInspectable*>> {
    void (^_delegate)(WDBBluetoothLEDevice*, RTObject*);

public:
    ITypedEventHandler_Windows_Devices_Bluetooth_BluetoothLEDevice_System_Object(void (^del)(WDBBluetoothLEDevice*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Bluetooth_BluetoothLEDevice_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Bluetooth::IBluetoothLEDevice* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDBBluetoothLEDevice>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif
