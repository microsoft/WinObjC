// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Bluetooth.GenericAttributeProfile.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::Bluetooth::GenericAttributeProfile {

struct WINRT_EBO GattCharacteristic :
    Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic,
    impl::require<GattCharacteristic, Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic2>
{
    GattCharacteristic(std::nullptr_t) noexcept {}
    static GUID ConvertShortIdToUuid(uint16_t shortId);
};

struct GattCharacteristicUuids
{
    GattCharacteristicUuids() = delete;
    static GUID BatteryLevel();
    static GUID BloodPressureFeature();
    static GUID BloodPressureMeasurement();
    static GUID BodySensorLocation();
    static GUID CscFeature();
    static GUID CscMeasurement();
    static GUID GlucoseFeature();
    static GUID GlucoseMeasurement();
    static GUID GlucoseMeasurementContext();
    static GUID HeartRateControlPoint();
    static GUID HeartRateMeasurement();
    static GUID IntermediateCuffPressure();
    static GUID IntermediateTemperature();
    static GUID MeasurementInterval();
    static GUID RecordAccessControlPoint();
    static GUID RscFeature();
    static GUID RscMeasurement();
    static GUID SCControlPoint();
    static GUID SensorLocation();
    static GUID TemperatureMeasurement();
    static GUID TemperatureType();
    static GUID AlertCategoryId();
    static GUID AlertCategoryIdBitMask();
    static GUID AlertLevel();
    static GUID AlertNotificationControlPoint();
    static GUID AlertStatus();
    static GUID GapAppearance();
    static GUID BootKeyboardInputReport();
    static GUID BootKeyboardOutputReport();
    static GUID BootMouseInputReport();
    static GUID CurrentTime();
    static GUID CyclingPowerControlPoint();
    static GUID CyclingPowerFeature();
    static GUID CyclingPowerMeasurement();
    static GUID CyclingPowerVector();
    static GUID DateTime();
    static GUID DayDateTime();
    static GUID DayOfWeek();
    static GUID GapDeviceName();
    static GUID DstOffset();
    static GUID ExactTime256();
    static GUID FirmwareRevisionString();
    static GUID HardwareRevisionString();
    static GUID HidControlPoint();
    static GUID HidInformation();
    static GUID Ieee1107320601RegulatoryCertificationDataList();
    static GUID LnControlPoint();
    static GUID LnFeature();
    static GUID LocalTimeInformation();
    static GUID LocationAndSpeed();
    static GUID ManufacturerNameString();
    static GUID ModelNumberString();
    static GUID Navigation();
    static GUID NewAlert();
    static GUID GapPeripheralPreferredConnectionParameters();
    static GUID GapPeripheralPrivacyFlag();
    static GUID PnpId();
    static GUID PositionQuality();
    static GUID ProtocolMode();
    static GUID GapReconnectionAddress();
    static GUID ReferenceTimeInformation();
    static GUID Report();
    static GUID ReportMap();
    static GUID RingerControlPoint();
    static GUID RingerSetting();
    static GUID ScanIntervalWindow();
    static GUID ScanRefresh();
    static GUID SerialNumberString();
    static GUID GattServiceChanged();
    static GUID SoftwareRevisionString();
    static GUID SupportedNewAlertCategory();
    static GUID SupportUnreadAlertCategory();
    static GUID SystemId();
    static GUID TimeAccuracy();
    static GUID TimeSource();
    static GUID TimeUpdateControlPoint();
    static GUID TimeUpdateState();
    static GUID TimeWithDst();
    static GUID TimeZone();
    static GUID TxPowerLevel();
    static GUID UnreadAlertStatus();
};

struct WINRT_EBO GattDescriptor :
    Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDescriptor
{
    GattDescriptor(std::nullptr_t) noexcept {}
    static GUID ConvertShortIdToUuid(uint16_t shortId);
};

struct GattDescriptorUuids
{
    GattDescriptorUuids() = delete;
    static GUID CharacteristicAggregateFormat();
    static GUID CharacteristicExtendedProperties();
    static GUID CharacteristicPresentationFormat();
    static GUID CharacteristicUserDescription();
    static GUID ClientCharacteristicConfiguration();
    static GUID ServerCharacteristicConfiguration();
};

struct WINRT_EBO GattDeviceService :
    Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDeviceService,
    impl::require<GattDeviceService, Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDeviceService2>
{
    GattDeviceService(std::nullptr_t) noexcept {}
    static Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceService> FromIdAsync(hstring_view deviceId);
    static hstring GetDeviceSelectorFromUuid(GUID serviceUuid);
    static hstring GetDeviceSelectorFromShortId(uint16_t serviceShortId);
    static GUID ConvertShortIdToUuid(uint16_t shortId);
};

struct WINRT_EBO GattPresentationFormat :
    Windows::Devices::Bluetooth::GenericAttributeProfile::IGattPresentationFormat
{
    GattPresentationFormat(std::nullptr_t) noexcept {}
    static uint8_t BluetoothSigAssignedNumbers();
};

struct GattPresentationFormatTypes
{
    GattPresentationFormatTypes() = delete;
    static uint8_t Boolean();
    static uint8_t Bit2();
    static uint8_t Nibble();
    static uint8_t UInt8();
    static uint8_t UInt12();
    static uint8_t UInt16();
    static uint8_t UInt24();
    static uint8_t UInt32();
    static uint8_t UInt48();
    static uint8_t UInt64();
    static uint8_t UInt128();
    static uint8_t SInt8();
    static uint8_t SInt12();
    static uint8_t SInt16();
    static uint8_t SInt24();
    static uint8_t SInt32();
    static uint8_t SInt48();
    static uint8_t SInt64();
    static uint8_t SInt128();
    static uint8_t Float32();
    static uint8_t Float64();
    static uint8_t SFloat();
    static uint8_t Float();
    static uint8_t DUInt16();
    static uint8_t Utf8();
    static uint8_t Utf16();
    static uint8_t Struct();
};

struct WINRT_EBO GattReadClientCharacteristicConfigurationDescriptorResult :
    Windows::Devices::Bluetooth::GenericAttributeProfile::IGattReadClientCharacteristicConfigurationDescriptorResult
{
    GattReadClientCharacteristicConfigurationDescriptorResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO GattReadResult :
    Windows::Devices::Bluetooth::GenericAttributeProfile::IGattReadResult
{
    GattReadResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO GattReliableWriteTransaction :
    Windows::Devices::Bluetooth::GenericAttributeProfile::IGattReliableWriteTransaction
{
    GattReliableWriteTransaction(std::nullptr_t) noexcept {}
    GattReliableWriteTransaction();
};

struct GattServiceUuids
{
    GattServiceUuids() = delete;
    static GUID Battery();
    static GUID BloodPressure();
    static GUID CyclingSpeedAndCadence();
    static GUID GenericAccess();
    static GUID GenericAttribute();
    static GUID Glucose();
    static GUID HealthThermometer();
    static GUID HeartRate();
    static GUID RunningSpeedAndCadence();
    static GUID AlertNotification();
    static GUID CurrentTime();
    static GUID CyclingPower();
    static GUID DeviceInformation();
    static GUID HumanInterfaceDevice();
    static GUID ImmediateAlert();
    static GUID LinkLoss();
    static GUID LocationAndNavigation();
    static GUID NextDstChange();
    static GUID PhoneAlertStatus();
    static GUID ReferenceTimeUpdate();
    static GUID ScanParameters();
    static GUID TxPower();
};

struct WINRT_EBO GattValueChangedEventArgs :
    Windows::Devices::Bluetooth::GenericAttributeProfile::IGattValueChangedEventArgs
{
    GattValueChangedEventArgs(std::nullptr_t) noexcept {}
};

}

}
