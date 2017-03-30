// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Bluetooth.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::Bluetooth {

struct WINRT_EBO BluetoothClassOfDevice :
    Windows::Devices::Bluetooth::IBluetoothClassOfDevice
{
    BluetoothClassOfDevice(std::nullptr_t) noexcept {}
    static Windows::Devices::Bluetooth::BluetoothClassOfDevice FromRawValue(uint32_t rawValue);
    static Windows::Devices::Bluetooth::BluetoothClassOfDevice FromParts(Windows::Devices::Bluetooth::BluetoothMajorClass majorClass, Windows::Devices::Bluetooth::BluetoothMinorClass minorClass, Windows::Devices::Bluetooth::BluetoothServiceCapabilities serviceCapabilities);
};

struct WINRT_EBO BluetoothDevice :
    Windows::Devices::Bluetooth::IBluetoothDevice,
    impl::require<BluetoothDevice, Windows::Foundation::IClosable, Windows::Devices::Bluetooth::IBluetoothDevice2, Windows::Devices::Bluetooth::IBluetoothDevice3>
{
    BluetoothDevice(std::nullptr_t) noexcept {}
    static Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothDevice> FromIdAsync(hstring_view deviceId);
    static Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothDevice> FromHostNameAsync(const Windows::Networking::HostName & hostName);
    static Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothDevice> FromBluetoothAddressAsync(uint64_t address);
    static hstring GetDeviceSelector();
    static hstring GetDeviceSelectorFromPairingState(bool pairingState);
    static hstring GetDeviceSelectorFromConnectionStatus(Windows::Devices::Bluetooth::BluetoothConnectionStatus connectionStatus);
    static hstring GetDeviceSelectorFromDeviceName(hstring_view deviceName);
    static hstring GetDeviceSelectorFromBluetoothAddress(uint64_t bluetoothAddress);
    static hstring GetDeviceSelectorFromClassOfDevice(const Windows::Devices::Bluetooth::BluetoothClassOfDevice & classOfDevice);
};

struct WINRT_EBO BluetoothLEAppearance :
    Windows::Devices::Bluetooth::IBluetoothLEAppearance
{
    BluetoothLEAppearance(std::nullptr_t) noexcept {}
    static Windows::Devices::Bluetooth::BluetoothLEAppearance FromRawValue(uint16_t rawValue);
    static Windows::Devices::Bluetooth::BluetoothLEAppearance FromParts(uint16_t appearanceCategory, uint16_t appearanceSubCategory);
};

struct BluetoothLEAppearanceCategories
{
    BluetoothLEAppearanceCategories() = delete;
    static uint16_t Uncategorized();
    static uint16_t Phone();
    static uint16_t Computer();
    static uint16_t Watch();
    static uint16_t Clock();
    static uint16_t Display();
    static uint16_t RemoteControl();
    static uint16_t EyeGlasses();
    static uint16_t Tag();
    static uint16_t Keyring();
    static uint16_t MediaPlayer();
    static uint16_t BarcodeScanner();
    static uint16_t Thermometer();
    static uint16_t HeartRate();
    static uint16_t BloodPressure();
    static uint16_t HumanInterfaceDevice();
    static uint16_t GlucoseMeter();
    static uint16_t RunningWalking();
    static uint16_t Cycling();
    static uint16_t PulseOximeter();
    static uint16_t WeightScale();
    static uint16_t OutdoorSportActivity();
};

struct BluetoothLEAppearanceSubcategories
{
    BluetoothLEAppearanceSubcategories() = delete;
    static uint16_t Generic();
    static uint16_t SportsWatch();
    static uint16_t ThermometerEar();
    static uint16_t HeartRateBelt();
    static uint16_t BloodPressureArm();
    static uint16_t BloodPressureWrist();
    static uint16_t Keyboard();
    static uint16_t Mouse();
    static uint16_t Joystick();
    static uint16_t Gamepad();
    static uint16_t DigitizerTablet();
    static uint16_t CardReader();
    static uint16_t DigitalPen();
    static uint16_t BarcodeScanner();
    static uint16_t RunningWalkingInShoe();
    static uint16_t RunningWalkingOnShoe();
    static uint16_t RunningWalkingOnHip();
    static uint16_t CyclingComputer();
    static uint16_t CyclingSpeedSensor();
    static uint16_t CyclingCadenceSensor();
    static uint16_t CyclingPowerSensor();
    static uint16_t CyclingSpeedCadenceSensor();
    static uint16_t OximeterFingertip();
    static uint16_t OximeterWristWorn();
    static uint16_t LocationDisplay();
    static uint16_t LocationNavigationDisplay();
    static uint16_t LocationPod();
    static uint16_t LocationNavigationPod();
};

struct WINRT_EBO BluetoothLEDevice :
    Windows::Devices::Bluetooth::IBluetoothLEDevice,
    impl::require<BluetoothLEDevice, Windows::Foundation::IClosable, Windows::Devices::Bluetooth::IBluetoothLEDevice2>
{
    BluetoothLEDevice(std::nullptr_t) noexcept {}
    static Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothLEDevice> FromIdAsync(hstring_view deviceId);
    static Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothLEDevice> FromBluetoothAddressAsync(uint64_t bluetoothAddress);
    static hstring GetDeviceSelector();
    static hstring GetDeviceSelectorFromPairingState(bool pairingState);
    static hstring GetDeviceSelectorFromConnectionStatus(Windows::Devices::Bluetooth::BluetoothConnectionStatus connectionStatus);
    static hstring GetDeviceSelectorFromDeviceName(hstring_view deviceName);
    static hstring GetDeviceSelectorFromBluetoothAddress(uint64_t bluetoothAddress);
    static hstring GetDeviceSelectorFromBluetoothAddress(uint64_t bluetoothAddress, Windows::Devices::Bluetooth::BluetoothAddressType bluetoothAddressType);
    static hstring GetDeviceSelectorFromAppearance(const Windows::Devices::Bluetooth::BluetoothLEAppearance & appearance);
    static Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothLEDevice> FromBluetoothAddressAsync(uint64_t bluetoothAddress, Windows::Devices::Bluetooth::BluetoothAddressType bluetoothAddressType);
};

struct WINRT_EBO BluetoothSignalStrengthFilter :
    Windows::Devices::Bluetooth::IBluetoothSignalStrengthFilter
{
    BluetoothSignalStrengthFilter(std::nullptr_t) noexcept {}
    BluetoothSignalStrengthFilter();
};

}

}
