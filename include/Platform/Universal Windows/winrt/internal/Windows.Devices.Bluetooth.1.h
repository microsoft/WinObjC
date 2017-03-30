// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Devices.Bluetooth.0.h"
#include "Windows.Devices.Bluetooth.GenericAttributeProfile.0.h"
#include "Windows.Devices.Bluetooth.Rfcomm.0.h"
#include "Windows.Devices.Enumeration.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Networking.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Storage.Streams.1.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Devices.Bluetooth.Rfcomm.1.h"
#include "Windows.Devices.Enumeration.1.h"
#include "Windows.Devices.Bluetooth.GenericAttributeProfile.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Bluetooth {

struct __declspec(uuid("d640227e-d7d7-4661-9454-65039ca17a2b")) __declspec(novtable) IBluetoothClassOfDevice : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RawValue(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_MajorClass(winrt::Windows::Devices::Bluetooth::BluetoothMajorClass * value) = 0;
    virtual HRESULT __stdcall get_MinorClass(winrt::Windows::Devices::Bluetooth::BluetoothMinorClass * value) = 0;
    virtual HRESULT __stdcall get_ServiceCapabilities(winrt::Windows::Devices::Bluetooth::BluetoothServiceCapabilities * value) = 0;
};

struct __declspec(uuid("e46135bd-0fa2-416c-91b4-c1e48ca061c1")) __declspec(novtable) IBluetoothClassOfDeviceStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FromRawValue(uint32_t rawValue, Windows::Devices::Bluetooth::IBluetoothClassOfDevice ** classOfDevice) = 0;
    virtual HRESULT __stdcall abi_FromParts(winrt::Windows::Devices::Bluetooth::BluetoothMajorClass majorClass, winrt::Windows::Devices::Bluetooth::BluetoothMinorClass minorClass, winrt::Windows::Devices::Bluetooth::BluetoothServiceCapabilities serviceCapabilities, Windows::Devices::Bluetooth::IBluetoothClassOfDevice ** classOfDevice) = 0;
};

struct __declspec(uuid("2335b156-90d2-4a04-aef5-0e20b9e6b707")) __declspec(novtable) IBluetoothDevice : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
    virtual HRESULT __stdcall get_HostName(Windows::Networking::IHostName ** value) = 0;
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall get_ClassOfDevice(Windows::Devices::Bluetooth::IBluetoothClassOfDevice ** value) = 0;
    virtual HRESULT __stdcall get_SdpRecords(Windows::Foundation::Collections::IVectorView<Windows::Storage::Streams::IBuffer> ** value) = 0;
    virtual HRESULT __stdcall get_RfcommServices(Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceService> ** value) = 0;
    virtual HRESULT __stdcall get_ConnectionStatus(winrt::Windows::Devices::Bluetooth::BluetoothConnectionStatus * value) = 0;
    virtual HRESULT __stdcall get_BluetoothAddress(uint64_t * value) = 0;
    virtual HRESULT __stdcall add_NameChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothDevice, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_NameChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_SdpRecordsChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothDevice, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SdpRecordsChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_ConnectionStatusChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothDevice, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ConnectionStatusChanged(event_token token) = 0;
};

struct __declspec(uuid("0133f954-b156-4dd0-b1f5-c11bc31a5163")) __declspec(novtable) IBluetoothDevice2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceInformation(Windows::Devices::Enumeration::IDeviceInformation ** value) = 0;
};

struct __declspec(uuid("57fff78b-651a-4454-b90f-eb21ef0b0d71")) __declspec(novtable) IBluetoothDevice3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceAccessInformation(Windows::Devices::Enumeration::IDeviceAccessInformation ** value) = 0;
    virtual HRESULT __stdcall abi_RequestAccessAsync(Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Enumeration::DeviceAccessStatus> ** value) = 0;
    virtual HRESULT __stdcall abi_GetRfcommServicesAsync(Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetRfcommServicesWithCacheModeAsync(winrt::Windows::Devices::Bluetooth::BluetoothCacheMode cacheMode, Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetRfcommServicesForIdAsync(Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId * serviceId, Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetRfcommServicesForIdWithCacheModeAsync(Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId * serviceId, winrt::Windows::Devices::Bluetooth::BluetoothCacheMode cacheMode, Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult> ** operation) = 0;
};

struct __declspec(uuid("0991df51-57db-4725-bbd7-84f64327ec2c")) __declspec(novtable) IBluetoothDeviceStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FromIdAsync(hstring deviceId, Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothDevice> ** operation) = 0;
    virtual HRESULT __stdcall abi_FromHostNameAsync(Windows::Networking::IHostName * hostName, Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothDevice> ** operation) = 0;
    virtual HRESULT __stdcall abi_FromBluetoothAddressAsync(uint64_t address, Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothDevice> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetDeviceSelector(hstring * deviceSelector) = 0;
};

struct __declspec(uuid("c29e8e2f-4e14-4477-aa1b-b8b47e5b7ece")) __declspec(novtable) IBluetoothDeviceStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDeviceSelectorFromPairingState(bool pairingState, hstring * deviceSelector) = 0;
    virtual HRESULT __stdcall abi_GetDeviceSelectorFromConnectionStatus(winrt::Windows::Devices::Bluetooth::BluetoothConnectionStatus connectionStatus, hstring * deviceSelector) = 0;
    virtual HRESULT __stdcall abi_GetDeviceSelectorFromDeviceName(hstring deviceName, hstring * deviceSelector) = 0;
    virtual HRESULT __stdcall abi_GetDeviceSelectorFromBluetoothAddress(uint64_t bluetoothAddress, hstring * deviceSelector) = 0;
    virtual HRESULT __stdcall abi_GetDeviceSelectorFromClassOfDevice(Windows::Devices::Bluetooth::IBluetoothClassOfDevice * classOfDevice, hstring * deviceSelector) = 0;
};

struct __declspec(uuid("5d2079f2-66a8-4258-985e-02b4d9509f18")) __declspec(novtable) IBluetoothLEAppearance : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RawValue(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_Category(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_SubCategory(uint16_t * value) = 0;
};

struct __declspec(uuid("6d4d54fe-046a-4185-aab6-824cf0610861")) __declspec(novtable) IBluetoothLEAppearanceCategoriesStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Uncategorized(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_Phone(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_Computer(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_Watch(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_Clock(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_Display(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_RemoteControl(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_EyeGlasses(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_Tag(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_Keyring(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_MediaPlayer(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_BarcodeScanner(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_Thermometer(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_HeartRate(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_BloodPressure(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_HumanInterfaceDevice(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_GlucoseMeter(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_RunningWalking(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_Cycling(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_PulseOximeter(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_WeightScale(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_OutdoorSportActivity(uint16_t * value) = 0;
};

struct __declspec(uuid("a193c0c7-4504-4f4a-9ba5-cd1054e5e065")) __declspec(novtable) IBluetoothLEAppearanceStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FromRawValue(uint16_t rawValue, Windows::Devices::Bluetooth::IBluetoothLEAppearance ** appearance) = 0;
    virtual HRESULT __stdcall abi_FromParts(uint16_t appearanceCategory, uint16_t appearanceSubCategory, Windows::Devices::Bluetooth::IBluetoothLEAppearance ** appearance) = 0;
};

struct __declspec(uuid("e57ba606-2144-415a-8312-71ccf291f8d1")) __declspec(novtable) IBluetoothLEAppearanceSubcategoriesStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Generic(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_SportsWatch(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_ThermometerEar(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_HeartRateBelt(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_BloodPressureArm(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_BloodPressureWrist(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_Keyboard(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_Mouse(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_Joystick(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_Gamepad(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_DigitizerTablet(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_CardReader(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_DigitalPen(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_BarcodeScanner(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_RunningWalkingInShoe(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_RunningWalkingOnShoe(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_RunningWalkingOnHip(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_CyclingComputer(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_CyclingSpeedSensor(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_CyclingCadenceSensor(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_CyclingPowerSensor(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_CyclingSpeedCadenceSensor(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_OximeterFingertip(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_OximeterWristWorn(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_LocationDisplay(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_LocationNavigationDisplay(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_LocationPod(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_LocationNavigationPod(uint16_t * value) = 0;
};

struct __declspec(uuid("b5ee2f7b-4ad8-4642-ac48-80a0b500e887")) __declspec(novtable) IBluetoothLEDevice : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall get_GattServices(Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceService> ** value) = 0;
    virtual HRESULT __stdcall get_ConnectionStatus(winrt::Windows::Devices::Bluetooth::BluetoothConnectionStatus * value) = 0;
    virtual HRESULT __stdcall get_BluetoothAddress(uint64_t * value) = 0;
    virtual HRESULT __stdcall abi_GetGattService(GUID serviceUuid, Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDeviceService ** service) = 0;
    virtual HRESULT __stdcall add_NameChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothLEDevice, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_NameChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_GattServicesChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothLEDevice, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_GattServicesChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_ConnectionStatusChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothLEDevice, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ConnectionStatusChanged(event_token token) = 0;
};

struct __declspec(uuid("26f062b3-7aee-4d31-baba-b1b9775f5916")) __declspec(novtable) IBluetoothLEDevice2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceInformation(Windows::Devices::Enumeration::IDeviceInformation ** value) = 0;
    virtual HRESULT __stdcall get_Appearance(Windows::Devices::Bluetooth::IBluetoothLEAppearance ** value) = 0;
    virtual HRESULT __stdcall get_BluetoothAddressType(winrt::Windows::Devices::Bluetooth::BluetoothAddressType * value) = 0;
};

struct __declspec(uuid("c8cf1a19-f0b6-4bf0-8689-41303de2d9f4")) __declspec(novtable) IBluetoothLEDeviceStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FromIdAsync(hstring deviceId, Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothLEDevice> ** operation) = 0;
    virtual HRESULT __stdcall abi_FromBluetoothAddressAsync(uint64_t bluetoothAddress, Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothLEDevice> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetDeviceSelector(hstring * deviceSelector) = 0;
};

struct __declspec(uuid("5f12c06b-3bac-43e8-ad16-563271bd41c2")) __declspec(novtable) IBluetoothLEDeviceStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDeviceSelectorFromPairingState(bool pairingState, hstring * deviceSelector) = 0;
    virtual HRESULT __stdcall abi_GetDeviceSelectorFromConnectionStatus(winrt::Windows::Devices::Bluetooth::BluetoothConnectionStatus connectionStatus, hstring * deviceSelector) = 0;
    virtual HRESULT __stdcall abi_GetDeviceSelectorFromDeviceName(hstring deviceName, hstring * deviceSelector) = 0;
    virtual HRESULT __stdcall abi_GetDeviceSelectorFromBluetoothAddress(uint64_t bluetoothAddress, hstring * deviceSelector) = 0;
    virtual HRESULT __stdcall abi_GetDeviceSelectorFromBluetoothAddressWithBluetoothAddressType(uint64_t bluetoothAddress, winrt::Windows::Devices::Bluetooth::BluetoothAddressType bluetoothAddressType, hstring * deviceSelector) = 0;
    virtual HRESULT __stdcall abi_GetDeviceSelectorFromAppearance(Windows::Devices::Bluetooth::IBluetoothLEAppearance * appearance, hstring * deviceSelector) = 0;
    virtual HRESULT __stdcall abi_FromBluetoothAddressWithBluetoothAddressTypeAsync(uint64_t bluetoothAddress, winrt::Windows::Devices::Bluetooth::BluetoothAddressType bluetoothAddressType, Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothLEDevice> ** operation) = 0;
};

struct __declspec(uuid("df7b7391-6bb5-4cfe-90b1-5d7324edcf7f")) __declspec(novtable) IBluetoothSignalStrengthFilter : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_InRangeThresholdInDBm(Windows::Foundation::IReference<int16_t> ** value) = 0;
    virtual HRESULT __stdcall put_InRangeThresholdInDBm(Windows::Foundation::IReference<int16_t> * value) = 0;
    virtual HRESULT __stdcall get_OutOfRangeThresholdInDBm(Windows::Foundation::IReference<int16_t> ** value) = 0;
    virtual HRESULT __stdcall put_OutOfRangeThresholdInDBm(Windows::Foundation::IReference<int16_t> * value) = 0;
    virtual HRESULT __stdcall get_OutOfRangeTimeout(Windows::Foundation::IReference<Windows::Foundation::TimeSpan> ** value) = 0;
    virtual HRESULT __stdcall put_OutOfRangeTimeout(Windows::Foundation::IReference<Windows::Foundation::TimeSpan> * value) = 0;
    virtual HRESULT __stdcall get_SamplingInterval(Windows::Foundation::IReference<Windows::Foundation::TimeSpan> ** value) = 0;
    virtual HRESULT __stdcall put_SamplingInterval(Windows::Foundation::IReference<Windows::Foundation::TimeSpan> * value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Devices::Bluetooth::BluetoothClassOfDevice> { using default_interface = Windows::Devices::Bluetooth::IBluetoothClassOfDevice; };
template <> struct traits<Windows::Devices::Bluetooth::BluetoothDevice> { using default_interface = Windows::Devices::Bluetooth::IBluetoothDevice; };
template <> struct traits<Windows::Devices::Bluetooth::BluetoothLEAppearance> { using default_interface = Windows::Devices::Bluetooth::IBluetoothLEAppearance; };
template <> struct traits<Windows::Devices::Bluetooth::BluetoothLEDevice> { using default_interface = Windows::Devices::Bluetooth::IBluetoothLEDevice; };
template <> struct traits<Windows::Devices::Bluetooth::BluetoothSignalStrengthFilter> { using default_interface = Windows::Devices::Bluetooth::IBluetoothSignalStrengthFilter; };

}

namespace Windows::Devices::Bluetooth {

template <typename D>
struct WINRT_EBO impl_IBluetoothClassOfDevice
{
    uint32_t RawValue() const;
    Windows::Devices::Bluetooth::BluetoothMajorClass MajorClass() const;
    Windows::Devices::Bluetooth::BluetoothMinorClass MinorClass() const;
    Windows::Devices::Bluetooth::BluetoothServiceCapabilities ServiceCapabilities() const;
};

template <typename D>
struct WINRT_EBO impl_IBluetoothClassOfDeviceStatics
{
    Windows::Devices::Bluetooth::BluetoothClassOfDevice FromRawValue(uint32_t rawValue) const;
    Windows::Devices::Bluetooth::BluetoothClassOfDevice FromParts(Windows::Devices::Bluetooth::BluetoothMajorClass majorClass, Windows::Devices::Bluetooth::BluetoothMinorClass minorClass, Windows::Devices::Bluetooth::BluetoothServiceCapabilities serviceCapabilities) const;
};

template <typename D>
struct WINRT_EBO impl_IBluetoothDevice
{
    hstring DeviceId() const;
    Windows::Networking::HostName HostName() const;
    hstring Name() const;
    Windows::Devices::Bluetooth::BluetoothClassOfDevice ClassOfDevice() const;
    Windows::Foundation::Collections::IVectorView<Windows::Storage::Streams::IBuffer> SdpRecords() const;
    [[deprecated("Use GetRfcommServicesAsync instead of RfcommServices.  For more info, see MSDN.")]] Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceService> RfcommServices() const;
    Windows::Devices::Bluetooth::BluetoothConnectionStatus ConnectionStatus() const;
    uint64_t BluetoothAddress() const;
    event_token NameChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothDevice, Windows::Foundation::IInspectable> & handler) const;
    using NameChanged_revoker = event_revoker<IBluetoothDevice>;
    NameChanged_revoker NameChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothDevice, Windows::Foundation::IInspectable> & handler) const;
    void NameChanged(event_token token) const;
    event_token SdpRecordsChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothDevice, Windows::Foundation::IInspectable> & handler) const;
    using SdpRecordsChanged_revoker = event_revoker<IBluetoothDevice>;
    SdpRecordsChanged_revoker SdpRecordsChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothDevice, Windows::Foundation::IInspectable> & handler) const;
    void SdpRecordsChanged(event_token token) const;
    event_token ConnectionStatusChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothDevice, Windows::Foundation::IInspectable> & handler) const;
    using ConnectionStatusChanged_revoker = event_revoker<IBluetoothDevice>;
    ConnectionStatusChanged_revoker ConnectionStatusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothDevice, Windows::Foundation::IInspectable> & handler) const;
    void ConnectionStatusChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IBluetoothDevice2
{
    Windows::Devices::Enumeration::DeviceInformation DeviceInformation() const;
};

template <typename D>
struct WINRT_EBO impl_IBluetoothDevice3
{
    Windows::Devices::Enumeration::DeviceAccessInformation DeviceAccessInformation() const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Enumeration::DeviceAccessStatus> RequestAccessAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult> GetRfcommServicesAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult> GetRfcommServicesAsync(Windows::Devices::Bluetooth::BluetoothCacheMode cacheMode) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult> GetRfcommServicesForIdAsync(const Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId & serviceId) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult> GetRfcommServicesForIdAsync(const Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId & serviceId, Windows::Devices::Bluetooth::BluetoothCacheMode cacheMode) const;
};

template <typename D>
struct WINRT_EBO impl_IBluetoothDeviceStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothDevice> FromIdAsync(hstring_view deviceId) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothDevice> FromHostNameAsync(const Windows::Networking::HostName & hostName) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothDevice> FromBluetoothAddressAsync(uint64_t address) const;
    hstring GetDeviceSelector() const;
};

template <typename D>
struct WINRT_EBO impl_IBluetoothDeviceStatics2
{
    hstring GetDeviceSelectorFromPairingState(bool pairingState) const;
    hstring GetDeviceSelectorFromConnectionStatus(Windows::Devices::Bluetooth::BluetoothConnectionStatus connectionStatus) const;
    hstring GetDeviceSelectorFromDeviceName(hstring_view deviceName) const;
    hstring GetDeviceSelectorFromBluetoothAddress(uint64_t bluetoothAddress) const;
    hstring GetDeviceSelectorFromClassOfDevice(const Windows::Devices::Bluetooth::BluetoothClassOfDevice & classOfDevice) const;
};

template <typename D>
struct WINRT_EBO impl_IBluetoothLEAppearance
{
    uint16_t RawValue() const;
    uint16_t Category() const;
    uint16_t SubCategory() const;
};

template <typename D>
struct WINRT_EBO impl_IBluetoothLEAppearanceCategoriesStatics
{
    uint16_t Uncategorized() const;
    uint16_t Phone() const;
    uint16_t Computer() const;
    uint16_t Watch() const;
    uint16_t Clock() const;
    uint16_t Display() const;
    uint16_t RemoteControl() const;
    uint16_t EyeGlasses() const;
    uint16_t Tag() const;
    uint16_t Keyring() const;
    uint16_t MediaPlayer() const;
    uint16_t BarcodeScanner() const;
    uint16_t Thermometer() const;
    uint16_t HeartRate() const;
    uint16_t BloodPressure() const;
    uint16_t HumanInterfaceDevice() const;
    uint16_t GlucoseMeter() const;
    uint16_t RunningWalking() const;
    uint16_t Cycling() const;
    uint16_t PulseOximeter() const;
    uint16_t WeightScale() const;
    uint16_t OutdoorSportActivity() const;
};

template <typename D>
struct WINRT_EBO impl_IBluetoothLEAppearanceStatics
{
    Windows::Devices::Bluetooth::BluetoothLEAppearance FromRawValue(uint16_t rawValue) const;
    Windows::Devices::Bluetooth::BluetoothLEAppearance FromParts(uint16_t appearanceCategory, uint16_t appearanceSubCategory) const;
};

template <typename D>
struct WINRT_EBO impl_IBluetoothLEAppearanceSubcategoriesStatics
{
    uint16_t Generic() const;
    uint16_t SportsWatch() const;
    uint16_t ThermometerEar() const;
    uint16_t HeartRateBelt() const;
    uint16_t BloodPressureArm() const;
    uint16_t BloodPressureWrist() const;
    uint16_t Keyboard() const;
    uint16_t Mouse() const;
    uint16_t Joystick() const;
    uint16_t Gamepad() const;
    uint16_t DigitizerTablet() const;
    uint16_t CardReader() const;
    uint16_t DigitalPen() const;
    uint16_t BarcodeScanner() const;
    uint16_t RunningWalkingInShoe() const;
    uint16_t RunningWalkingOnShoe() const;
    uint16_t RunningWalkingOnHip() const;
    uint16_t CyclingComputer() const;
    uint16_t CyclingSpeedSensor() const;
    uint16_t CyclingCadenceSensor() const;
    uint16_t CyclingPowerSensor() const;
    uint16_t CyclingSpeedCadenceSensor() const;
    uint16_t OximeterFingertip() const;
    uint16_t OximeterWristWorn() const;
    uint16_t LocationDisplay() const;
    uint16_t LocationNavigationDisplay() const;
    uint16_t LocationPod() const;
    uint16_t LocationNavigationPod() const;
};

template <typename D>
struct WINRT_EBO impl_IBluetoothLEDevice
{
    hstring DeviceId() const;
    hstring Name() const;
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceService> GattServices() const;
    Windows::Devices::Bluetooth::BluetoothConnectionStatus ConnectionStatus() const;
    uint64_t BluetoothAddress() const;
    Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceService GetGattService(GUID serviceUuid) const;
    event_token NameChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothLEDevice, Windows::Foundation::IInspectable> & handler) const;
    using NameChanged_revoker = event_revoker<IBluetoothLEDevice>;
    NameChanged_revoker NameChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothLEDevice, Windows::Foundation::IInspectable> & handler) const;
    void NameChanged(event_token token) const;
    event_token GattServicesChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothLEDevice, Windows::Foundation::IInspectable> & handler) const;
    using GattServicesChanged_revoker = event_revoker<IBluetoothLEDevice>;
    GattServicesChanged_revoker GattServicesChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothLEDevice, Windows::Foundation::IInspectable> & handler) const;
    void GattServicesChanged(event_token token) const;
    event_token ConnectionStatusChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothLEDevice, Windows::Foundation::IInspectable> & handler) const;
    using ConnectionStatusChanged_revoker = event_revoker<IBluetoothLEDevice>;
    ConnectionStatusChanged_revoker ConnectionStatusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothLEDevice, Windows::Foundation::IInspectable> & handler) const;
    void ConnectionStatusChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IBluetoothLEDevice2
{
    Windows::Devices::Enumeration::DeviceInformation DeviceInformation() const;
    Windows::Devices::Bluetooth::BluetoothLEAppearance Appearance() const;
    Windows::Devices::Bluetooth::BluetoothAddressType BluetoothAddressType() const;
};

template <typename D>
struct WINRT_EBO impl_IBluetoothLEDeviceStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothLEDevice> FromIdAsync(hstring_view deviceId) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothLEDevice> FromBluetoothAddressAsync(uint64_t bluetoothAddress) const;
    hstring GetDeviceSelector() const;
};

template <typename D>
struct WINRT_EBO impl_IBluetoothLEDeviceStatics2
{
    hstring GetDeviceSelectorFromPairingState(bool pairingState) const;
    hstring GetDeviceSelectorFromConnectionStatus(Windows::Devices::Bluetooth::BluetoothConnectionStatus connectionStatus) const;
    hstring GetDeviceSelectorFromDeviceName(hstring_view deviceName) const;
    hstring GetDeviceSelectorFromBluetoothAddress(uint64_t bluetoothAddress) const;
    hstring GetDeviceSelectorFromBluetoothAddress(uint64_t bluetoothAddress, Windows::Devices::Bluetooth::BluetoothAddressType bluetoothAddressType) const;
    hstring GetDeviceSelectorFromAppearance(const Windows::Devices::Bluetooth::BluetoothLEAppearance & appearance) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothLEDevice> FromBluetoothAddressAsync(uint64_t bluetoothAddress, Windows::Devices::Bluetooth::BluetoothAddressType bluetoothAddressType) const;
};

template <typename D>
struct WINRT_EBO impl_IBluetoothSignalStrengthFilter
{
    Windows::Foundation::IReference<int16_t> InRangeThresholdInDBm() const;
    void InRangeThresholdInDBm(const optional<int16_t> & value) const;
    Windows::Foundation::IReference<int16_t> OutOfRangeThresholdInDBm() const;
    void OutOfRangeThresholdInDBm(const optional<int16_t> & value) const;
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> OutOfRangeTimeout() const;
    void OutOfRangeTimeout(const optional<Windows::Foundation::TimeSpan> & value) const;
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> SamplingInterval() const;
    void SamplingInterval(const optional<Windows::Foundation::TimeSpan> & value) const;
};

}

namespace impl {

template <> struct traits<Windows::Devices::Bluetooth::IBluetoothClassOfDevice>
{
    using abi = ABI::Windows::Devices::Bluetooth::IBluetoothClassOfDevice;
    template <typename D> using consume = Windows::Devices::Bluetooth::impl_IBluetoothClassOfDevice<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::IBluetoothClassOfDeviceStatics>
{
    using abi = ABI::Windows::Devices::Bluetooth::IBluetoothClassOfDeviceStatics;
    template <typename D> using consume = Windows::Devices::Bluetooth::impl_IBluetoothClassOfDeviceStatics<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::IBluetoothDevice>
{
    using abi = ABI::Windows::Devices::Bluetooth::IBluetoothDevice;
    template <typename D> using consume = Windows::Devices::Bluetooth::impl_IBluetoothDevice<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::IBluetoothDevice2>
{
    using abi = ABI::Windows::Devices::Bluetooth::IBluetoothDevice2;
    template <typename D> using consume = Windows::Devices::Bluetooth::impl_IBluetoothDevice2<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::IBluetoothDevice3>
{
    using abi = ABI::Windows::Devices::Bluetooth::IBluetoothDevice3;
    template <typename D> using consume = Windows::Devices::Bluetooth::impl_IBluetoothDevice3<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::IBluetoothDeviceStatics>
{
    using abi = ABI::Windows::Devices::Bluetooth::IBluetoothDeviceStatics;
    template <typename D> using consume = Windows::Devices::Bluetooth::impl_IBluetoothDeviceStatics<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::IBluetoothDeviceStatics2>
{
    using abi = ABI::Windows::Devices::Bluetooth::IBluetoothDeviceStatics2;
    template <typename D> using consume = Windows::Devices::Bluetooth::impl_IBluetoothDeviceStatics2<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::IBluetoothLEAppearance>
{
    using abi = ABI::Windows::Devices::Bluetooth::IBluetoothLEAppearance;
    template <typename D> using consume = Windows::Devices::Bluetooth::impl_IBluetoothLEAppearance<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::IBluetoothLEAppearanceCategoriesStatics>
{
    using abi = ABI::Windows::Devices::Bluetooth::IBluetoothLEAppearanceCategoriesStatics;
    template <typename D> using consume = Windows::Devices::Bluetooth::impl_IBluetoothLEAppearanceCategoriesStatics<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::IBluetoothLEAppearanceStatics>
{
    using abi = ABI::Windows::Devices::Bluetooth::IBluetoothLEAppearanceStatics;
    template <typename D> using consume = Windows::Devices::Bluetooth::impl_IBluetoothLEAppearanceStatics<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::IBluetoothLEAppearanceSubcategoriesStatics>
{
    using abi = ABI::Windows::Devices::Bluetooth::IBluetoothLEAppearanceSubcategoriesStatics;
    template <typename D> using consume = Windows::Devices::Bluetooth::impl_IBluetoothLEAppearanceSubcategoriesStatics<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::IBluetoothLEDevice>
{
    using abi = ABI::Windows::Devices::Bluetooth::IBluetoothLEDevice;
    template <typename D> using consume = Windows::Devices::Bluetooth::impl_IBluetoothLEDevice<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::IBluetoothLEDevice2>
{
    using abi = ABI::Windows::Devices::Bluetooth::IBluetoothLEDevice2;
    template <typename D> using consume = Windows::Devices::Bluetooth::impl_IBluetoothLEDevice2<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::IBluetoothLEDeviceStatics>
{
    using abi = ABI::Windows::Devices::Bluetooth::IBluetoothLEDeviceStatics;
    template <typename D> using consume = Windows::Devices::Bluetooth::impl_IBluetoothLEDeviceStatics<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::IBluetoothLEDeviceStatics2>
{
    using abi = ABI::Windows::Devices::Bluetooth::IBluetoothLEDeviceStatics2;
    template <typename D> using consume = Windows::Devices::Bluetooth::impl_IBluetoothLEDeviceStatics2<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::IBluetoothSignalStrengthFilter>
{
    using abi = ABI::Windows::Devices::Bluetooth::IBluetoothSignalStrengthFilter;
    template <typename D> using consume = Windows::Devices::Bluetooth::impl_IBluetoothSignalStrengthFilter<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::BluetoothClassOfDevice>
{
    using abi = ABI::Windows::Devices::Bluetooth::BluetoothClassOfDevice;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.BluetoothClassOfDevice"; }
};

template <> struct traits<Windows::Devices::Bluetooth::BluetoothDevice>
{
    using abi = ABI::Windows::Devices::Bluetooth::BluetoothDevice;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.BluetoothDevice"; }
};

template <> struct traits<Windows::Devices::Bluetooth::BluetoothLEAppearance>
{
    using abi = ABI::Windows::Devices::Bluetooth::BluetoothLEAppearance;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.BluetoothLEAppearance"; }
};

template <> struct traits<Windows::Devices::Bluetooth::BluetoothLEAppearanceCategories>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.BluetoothLEAppearanceCategories"; }
};

template <> struct traits<Windows::Devices::Bluetooth::BluetoothLEAppearanceSubcategories>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.BluetoothLEAppearanceSubcategories"; }
};

template <> struct traits<Windows::Devices::Bluetooth::BluetoothLEDevice>
{
    using abi = ABI::Windows::Devices::Bluetooth::BluetoothLEDevice;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.BluetoothLEDevice"; }
};

template <> struct traits<Windows::Devices::Bluetooth::BluetoothSignalStrengthFilter>
{
    using abi = ABI::Windows::Devices::Bluetooth::BluetoothSignalStrengthFilter;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.BluetoothSignalStrengthFilter"; }
};

}

}
