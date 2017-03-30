// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Devices.Bluetooth.GenericAttributeProfile.0.h"
#include "Windows.Devices.Bluetooth.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Bluetooth::GenericAttributeProfile {

struct __declspec(uuid("59cb50c1-5934-4f68-a198-eb864fa44e6b")) __declspec(novtable) IGattCharacteristic : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDescriptors(GUID descriptorUuid, Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::GenericAttributeProfile::GattDescriptor> ** value) = 0;
    virtual HRESULT __stdcall get_CharacteristicProperties(winrt::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristicProperties * value) = 0;
    virtual HRESULT __stdcall get_ProtectionLevel(winrt::Windows::Devices::Bluetooth::GenericAttributeProfile::GattProtectionLevel * value) = 0;
    virtual HRESULT __stdcall put_ProtectionLevel(winrt::Windows::Devices::Bluetooth::GenericAttributeProfile::GattProtectionLevel value) = 0;
    virtual HRESULT __stdcall get_UserDescription(hstring * value) = 0;
    virtual HRESULT __stdcall get_Uuid(GUID * value) = 0;
    virtual HRESULT __stdcall get_AttributeHandle(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_PresentationFormats(Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::GenericAttributeProfile::GattPresentationFormat> ** value) = 0;
    virtual HRESULT __stdcall abi_ReadValueAsync(Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::GenericAttributeProfile::GattReadResult> ** value) = 0;
    virtual HRESULT __stdcall abi_ReadValueWithCacheModeAsync(winrt::Windows::Devices::Bluetooth::BluetoothCacheMode cacheMode, Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::GenericAttributeProfile::GattReadResult> ** value) = 0;
    virtual HRESULT __stdcall abi_WriteValueAsync(Windows::Storage::Streams::IBuffer * value, Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCommunicationStatus> ** asyncOp) = 0;
    virtual HRESULT __stdcall abi_WriteValueWithOptionAsync(Windows::Storage::Streams::IBuffer * value, winrt::Windows::Devices::Bluetooth::GenericAttributeProfile::GattWriteOption writeOption, Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCommunicationStatus> ** asyncOp) = 0;
    virtual HRESULT __stdcall abi_ReadClientCharacteristicConfigurationDescriptorAsync(Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::GenericAttributeProfile::GattReadClientCharacteristicConfigurationDescriptorResult> ** asyncOp) = 0;
    virtual HRESULT __stdcall abi_WriteClientCharacteristicConfigurationDescriptorAsync(winrt::Windows::Devices::Bluetooth::GenericAttributeProfile::GattClientCharacteristicConfigurationDescriptorValue clientCharacteristicConfigurationDescriptorValue, Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCommunicationStatus> ** asyncOp) = 0;
    virtual HRESULT __stdcall add_ValueChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic, Windows::Devices::Bluetooth::GenericAttributeProfile::GattValueChangedEventArgs> * valueChangedHandler, event_token * valueChangedEventCookie) = 0;
    virtual HRESULT __stdcall remove_ValueChanged(event_token valueChangedEventCookie) = 0;
};

struct __declspec(uuid("ae1ab578-ec06-4764-b780-9835a1d35d6e")) __declspec(novtable) IGattCharacteristic2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Service(Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDeviceService ** value) = 0;
    virtual HRESULT __stdcall abi_GetAllDescriptors(Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::GenericAttributeProfile::GattDescriptor> ** descriptors) = 0;
};

struct __declspec(uuid("59cb50c3-5934-4f68-a198-eb864fa44e6b")) __declspec(novtable) IGattCharacteristicStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ConvertShortIdToUuid(uint16_t shortId, GUID * characteristicUuid) = 0;
};

struct __declspec(uuid("58fa4586-b1de-470c-b7de-0d11ff44f4b7")) __declspec(novtable) IGattCharacteristicUuidsStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_BatteryLevel(GUID * value) = 0;
    virtual HRESULT __stdcall get_BloodPressureFeature(GUID * value) = 0;
    virtual HRESULT __stdcall get_BloodPressureMeasurement(GUID * value) = 0;
    virtual HRESULT __stdcall get_BodySensorLocation(GUID * value) = 0;
    virtual HRESULT __stdcall get_CscFeature(GUID * value) = 0;
    virtual HRESULT __stdcall get_CscMeasurement(GUID * value) = 0;
    virtual HRESULT __stdcall get_GlucoseFeature(GUID * value) = 0;
    virtual HRESULT __stdcall get_GlucoseMeasurement(GUID * value) = 0;
    virtual HRESULT __stdcall get_GlucoseMeasurementContext(GUID * value) = 0;
    virtual HRESULT __stdcall get_HeartRateControlPoint(GUID * value) = 0;
    virtual HRESULT __stdcall get_HeartRateMeasurement(GUID * value) = 0;
    virtual HRESULT __stdcall get_IntermediateCuffPressure(GUID * value) = 0;
    virtual HRESULT __stdcall get_IntermediateTemperature(GUID * value) = 0;
    virtual HRESULT __stdcall get_MeasurementInterval(GUID * value) = 0;
    virtual HRESULT __stdcall get_RecordAccessControlPoint(GUID * value) = 0;
    virtual HRESULT __stdcall get_RscFeature(GUID * value) = 0;
    virtual HRESULT __stdcall get_RscMeasurement(GUID * value) = 0;
    virtual HRESULT __stdcall get_SCControlPoint(GUID * value) = 0;
    virtual HRESULT __stdcall get_SensorLocation(GUID * value) = 0;
    virtual HRESULT __stdcall get_TemperatureMeasurement(GUID * value) = 0;
    virtual HRESULT __stdcall get_TemperatureType(GUID * value) = 0;
};

struct __declspec(uuid("1855b425-d46e-4a2c-9c3f-ed6dea29e7be")) __declspec(novtable) IGattCharacteristicUuidsStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AlertCategoryId(GUID * value) = 0;
    virtual HRESULT __stdcall get_AlertCategoryIdBitMask(GUID * value) = 0;
    virtual HRESULT __stdcall get_AlertLevel(GUID * value) = 0;
    virtual HRESULT __stdcall get_AlertNotificationControlPoint(GUID * value) = 0;
    virtual HRESULT __stdcall get_AlertStatus(GUID * value) = 0;
    virtual HRESULT __stdcall get_GapAppearance(GUID * value) = 0;
    virtual HRESULT __stdcall get_BootKeyboardInputReport(GUID * value) = 0;
    virtual HRESULT __stdcall get_BootKeyboardOutputReport(GUID * value) = 0;
    virtual HRESULT __stdcall get_BootMouseInputReport(GUID * value) = 0;
    virtual HRESULT __stdcall get_CurrentTime(GUID * value) = 0;
    virtual HRESULT __stdcall get_CyclingPowerControlPoint(GUID * value) = 0;
    virtual HRESULT __stdcall get_CyclingPowerFeature(GUID * value) = 0;
    virtual HRESULT __stdcall get_CyclingPowerMeasurement(GUID * value) = 0;
    virtual HRESULT __stdcall get_CyclingPowerVector(GUID * value) = 0;
    virtual HRESULT __stdcall get_DateTime(GUID * value) = 0;
    virtual HRESULT __stdcall get_DayDateTime(GUID * value) = 0;
    virtual HRESULT __stdcall get_DayOfWeek(GUID * value) = 0;
    virtual HRESULT __stdcall get_GapDeviceName(GUID * value) = 0;
    virtual HRESULT __stdcall get_DstOffset(GUID * value) = 0;
    virtual HRESULT __stdcall get_ExactTime256(GUID * value) = 0;
    virtual HRESULT __stdcall get_FirmwareRevisionString(GUID * value) = 0;
    virtual HRESULT __stdcall get_HardwareRevisionString(GUID * value) = 0;
    virtual HRESULT __stdcall get_HidControlPoint(GUID * value) = 0;
    virtual HRESULT __stdcall get_HidInformation(GUID * value) = 0;
    virtual HRESULT __stdcall get_Ieee1107320601RegulatoryCertificationDataList(GUID * value) = 0;
    virtual HRESULT __stdcall get_LnControlPoint(GUID * value) = 0;
    virtual HRESULT __stdcall get_LnFeature(GUID * value) = 0;
    virtual HRESULT __stdcall get_LocalTimeInformation(GUID * value) = 0;
    virtual HRESULT __stdcall get_LocationAndSpeed(GUID * value) = 0;
    virtual HRESULT __stdcall get_ManufacturerNameString(GUID * value) = 0;
    virtual HRESULT __stdcall get_ModelNumberString(GUID * value) = 0;
    virtual HRESULT __stdcall get_Navigation(GUID * value) = 0;
    virtual HRESULT __stdcall get_NewAlert(GUID * value) = 0;
    virtual HRESULT __stdcall get_GapPeripheralPreferredConnectionParameters(GUID * value) = 0;
    virtual HRESULT __stdcall get_GapPeripheralPrivacyFlag(GUID * value) = 0;
    virtual HRESULT __stdcall get_PnpId(GUID * value) = 0;
    virtual HRESULT __stdcall get_PositionQuality(GUID * value) = 0;
    virtual HRESULT __stdcall get_ProtocolMode(GUID * value) = 0;
    virtual HRESULT __stdcall get_GapReconnectionAddress(GUID * value) = 0;
    virtual HRESULT __stdcall get_ReferenceTimeInformation(GUID * value) = 0;
    virtual HRESULT __stdcall get_Report(GUID * value) = 0;
    virtual HRESULT __stdcall get_ReportMap(GUID * value) = 0;
    virtual HRESULT __stdcall get_RingerControlPoint(GUID * value) = 0;
    virtual HRESULT __stdcall get_RingerSetting(GUID * value) = 0;
    virtual HRESULT __stdcall get_ScanIntervalWindow(GUID * value) = 0;
    virtual HRESULT __stdcall get_ScanRefresh(GUID * value) = 0;
    virtual HRESULT __stdcall get_SerialNumberString(GUID * value) = 0;
    virtual HRESULT __stdcall get_GattServiceChanged(GUID * value) = 0;
    virtual HRESULT __stdcall get_SoftwareRevisionString(GUID * value) = 0;
    virtual HRESULT __stdcall get_SupportedNewAlertCategory(GUID * value) = 0;
    virtual HRESULT __stdcall get_SupportUnreadAlertCategory(GUID * value) = 0;
    virtual HRESULT __stdcall get_SystemId(GUID * value) = 0;
    virtual HRESULT __stdcall get_TimeAccuracy(GUID * value) = 0;
    virtual HRESULT __stdcall get_TimeSource(GUID * value) = 0;
    virtual HRESULT __stdcall get_TimeUpdateControlPoint(GUID * value) = 0;
    virtual HRESULT __stdcall get_TimeUpdateState(GUID * value) = 0;
    virtual HRESULT __stdcall get_TimeWithDst(GUID * value) = 0;
    virtual HRESULT __stdcall get_TimeZone(GUID * value) = 0;
    virtual HRESULT __stdcall get_TxPowerLevel(GUID * value) = 0;
    virtual HRESULT __stdcall get_UnreadAlertStatus(GUID * value) = 0;
};

struct __declspec(uuid("92055f2b-8084-4344-b4c2-284de19a8506")) __declspec(novtable) IGattDescriptor : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ProtectionLevel(winrt::Windows::Devices::Bluetooth::GenericAttributeProfile::GattProtectionLevel * value) = 0;
    virtual HRESULT __stdcall put_ProtectionLevel(winrt::Windows::Devices::Bluetooth::GenericAttributeProfile::GattProtectionLevel value) = 0;
    virtual HRESULT __stdcall get_Uuid(GUID * value) = 0;
    virtual HRESULT __stdcall get_AttributeHandle(uint16_t * value) = 0;
    virtual HRESULT __stdcall abi_ReadValueAsync(Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::GenericAttributeProfile::GattReadResult> ** value) = 0;
    virtual HRESULT __stdcall abi_ReadValueWithCacheModeAsync(winrt::Windows::Devices::Bluetooth::BluetoothCacheMode cacheMode, Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::GenericAttributeProfile::GattReadResult> ** value) = 0;
    virtual HRESULT __stdcall abi_WriteValueAsync(Windows::Storage::Streams::IBuffer * value, Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCommunicationStatus> ** action) = 0;
};

struct __declspec(uuid("92055f2d-8084-4344-b4c2-284de19a8506")) __declspec(novtable) IGattDescriptorStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ConvertShortIdToUuid(uint16_t shortId, GUID * descriptorUuid) = 0;
};

struct __declspec(uuid("a6f862ce-9cfc-42f1-9185-ff37b75181d3")) __declspec(novtable) IGattDescriptorUuidsStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CharacteristicAggregateFormat(GUID * value) = 0;
    virtual HRESULT __stdcall get_CharacteristicExtendedProperties(GUID * value) = 0;
    virtual HRESULT __stdcall get_CharacteristicPresentationFormat(GUID * value) = 0;
    virtual HRESULT __stdcall get_CharacteristicUserDescription(GUID * value) = 0;
    virtual HRESULT __stdcall get_ClientCharacteristicConfiguration(GUID * value) = 0;
    virtual HRESULT __stdcall get_ServerCharacteristicConfiguration(GUID * value) = 0;
};

struct __declspec(uuid("ac7b7c05-b33c-47cf-990f-6b8f5577df71")) __declspec(novtable) IGattDeviceService : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetCharacteristics(GUID characteristicUuid, Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic> ** value) = 0;
    virtual HRESULT __stdcall abi_GetIncludedServices(GUID serviceUuid, Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceService> ** value) = 0;
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
    virtual HRESULT __stdcall get_Uuid(GUID * value) = 0;
    virtual HRESULT __stdcall get_AttributeHandle(uint16_t * value) = 0;
};

struct __declspec(uuid("fc54520b-0b0d-4708-bae0-9ffd9489bc59")) __declspec(novtable) IGattDeviceService2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Device(Windows::Devices::Bluetooth::IBluetoothLEDevice ** value) = 0;
    virtual HRESULT __stdcall get_ParentServices(Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceService> ** value) = 0;
    virtual HRESULT __stdcall abi_GetAllCharacteristics(Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic> ** characteristics) = 0;
    virtual HRESULT __stdcall abi_GetAllIncludedServices(Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceService> ** includedServices) = 0;
};

struct __declspec(uuid("196d0022-faad-45dc-ae5b-2ac3184e84db")) __declspec(novtable) IGattDeviceServiceStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FromIdAsync(hstring deviceId, Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceService> ** gattDeviceService) = 0;
    virtual HRESULT __stdcall abi_GetDeviceSelectorFromUuid(GUID serviceUuid, hstring * selector) = 0;
    virtual HRESULT __stdcall abi_GetDeviceSelectorFromShortId(uint16_t serviceShortId, hstring * selector) = 0;
    virtual HRESULT __stdcall abi_ConvertShortIdToUuid(uint16_t shortId, GUID * serviceUuid) = 0;
};

struct __declspec(uuid("196d0021-faad-45dc-ae5b-2ac3184e84db")) __declspec(novtable) IGattPresentationFormat : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FormatType(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_Exponent(int32_t * value) = 0;
    virtual HRESULT __stdcall get_Unit(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_Namespace(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_Description(uint16_t * value) = 0;
};

struct __declspec(uuid("196d0020-faad-45dc-ae5b-2ac3184e84db")) __declspec(novtable) IGattPresentationFormatStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_BluetoothSigAssignedNumbers(uint8_t * value) = 0;
};

struct __declspec(uuid("faf1ba0a-30ba-409c-bef7-cffb6d03b8fb")) __declspec(novtable) IGattPresentationFormatTypesStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Boolean(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_Bit2(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_Nibble(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_UInt8(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_UInt12(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_UInt16(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_UInt24(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_UInt32(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_UInt48(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_UInt64(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_UInt128(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_SInt8(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_SInt12(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_SInt16(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_SInt24(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_SInt32(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_SInt48(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_SInt64(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_SInt128(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_Float32(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_Float64(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_SFloat(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_Float(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_DUInt16(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_Utf8(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_Utf16(uint8_t * value) = 0;
    virtual HRESULT __stdcall get_Struct(uint8_t * value) = 0;
};

struct __declspec(uuid("63a66f09-1aea-4c4c-a50f-97bae474b348")) __declspec(novtable) IGattReadClientCharacteristicConfigurationDescriptorResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Status(winrt::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCommunicationStatus * value) = 0;
    virtual HRESULT __stdcall get_ClientCharacteristicConfigurationDescriptor(winrt::Windows::Devices::Bluetooth::GenericAttributeProfile::GattClientCharacteristicConfigurationDescriptorValue * value) = 0;
};

struct __declspec(uuid("63a66f08-1aea-4c4c-a50f-97bae474b348")) __declspec(novtable) IGattReadResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Status(winrt::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCommunicationStatus * value) = 0;
    virtual HRESULT __stdcall get_Value(Windows::Storage::Streams::IBuffer ** value) = 0;
};

struct __declspec(uuid("63a66f07-1aea-4c4c-a50f-97bae474b348")) __declspec(novtable) IGattReliableWriteTransaction : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_WriteValue(Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic * characteristic, Windows::Storage::Streams::IBuffer * value) = 0;
    virtual HRESULT __stdcall abi_CommitAsync(Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCommunicationStatus> ** asyncOp) = 0;
};

struct __declspec(uuid("6dc57058-9aba-4417-b8f2-dce016d34ee2")) __declspec(novtable) IGattServiceUuidsStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Battery(GUID * value) = 0;
    virtual HRESULT __stdcall get_BloodPressure(GUID * value) = 0;
    virtual HRESULT __stdcall get_CyclingSpeedAndCadence(GUID * value) = 0;
    virtual HRESULT __stdcall get_GenericAccess(GUID * value) = 0;
    virtual HRESULT __stdcall get_GenericAttribute(GUID * value) = 0;
    virtual HRESULT __stdcall get_Glucose(GUID * value) = 0;
    virtual HRESULT __stdcall get_HealthThermometer(GUID * value) = 0;
    virtual HRESULT __stdcall get_HeartRate(GUID * value) = 0;
    virtual HRESULT __stdcall get_RunningSpeedAndCadence(GUID * value) = 0;
};

struct __declspec(uuid("d2ae94f5-3d15-4f79-9c0c-eaafa675155c")) __declspec(novtable) IGattServiceUuidsStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AlertNotification(GUID * value) = 0;
    virtual HRESULT __stdcall get_CurrentTime(GUID * value) = 0;
    virtual HRESULT __stdcall get_CyclingPower(GUID * value) = 0;
    virtual HRESULT __stdcall get_DeviceInformation(GUID * value) = 0;
    virtual HRESULT __stdcall get_HumanInterfaceDevice(GUID * value) = 0;
    virtual HRESULT __stdcall get_ImmediateAlert(GUID * value) = 0;
    virtual HRESULT __stdcall get_LinkLoss(GUID * value) = 0;
    virtual HRESULT __stdcall get_LocationAndNavigation(GUID * value) = 0;
    virtual HRESULT __stdcall get_NextDstChange(GUID * value) = 0;
    virtual HRESULT __stdcall get_PhoneAlertStatus(GUID * value) = 0;
    virtual HRESULT __stdcall get_ReferenceTimeUpdate(GUID * value) = 0;
    virtual HRESULT __stdcall get_ScanParameters(GUID * value) = 0;
    virtual HRESULT __stdcall get_TxPower(GUID * value) = 0;
};

struct __declspec(uuid("d21bdb54-06e3-4ed8-a263-acfac8ba7313")) __declspec(novtable) IGattValueChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CharacteristicValue(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall get_Timestamp(Windows::Foundation::DateTime * timestamp) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic> { using default_interface = Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic; };
template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::GattDescriptor> { using default_interface = Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDescriptor; };
template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceService> { using default_interface = Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDeviceService; };
template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::GattPresentationFormat> { using default_interface = Windows::Devices::Bluetooth::GenericAttributeProfile::IGattPresentationFormat; };
template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::GattReadClientCharacteristicConfigurationDescriptorResult> { using default_interface = Windows::Devices::Bluetooth::GenericAttributeProfile::IGattReadClientCharacteristicConfigurationDescriptorResult; };
template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::GattReadResult> { using default_interface = Windows::Devices::Bluetooth::GenericAttributeProfile::IGattReadResult; };
template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::GattReliableWriteTransaction> { using default_interface = Windows::Devices::Bluetooth::GenericAttributeProfile::IGattReliableWriteTransaction; };
template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::GattValueChangedEventArgs> { using default_interface = Windows::Devices::Bluetooth::GenericAttributeProfile::IGattValueChangedEventArgs; };

}

namespace Windows::Devices::Bluetooth::GenericAttributeProfile {

template <typename D>
struct WINRT_EBO impl_IGattCharacteristic
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::GenericAttributeProfile::GattDescriptor> GetDescriptors(GUID descriptorUuid) const;
    Windows::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristicProperties CharacteristicProperties() const;
    Windows::Devices::Bluetooth::GenericAttributeProfile::GattProtectionLevel ProtectionLevel() const;
    void ProtectionLevel(Windows::Devices::Bluetooth::GenericAttributeProfile::GattProtectionLevel value) const;
    hstring UserDescription() const;
    GUID Uuid() const;
    uint16_t AttributeHandle() const;
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::GenericAttributeProfile::GattPresentationFormat> PresentationFormats() const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::GenericAttributeProfile::GattReadResult> ReadValueAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::GenericAttributeProfile::GattReadResult> ReadValueAsync(Windows::Devices::Bluetooth::BluetoothCacheMode cacheMode) const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCommunicationStatus> WriteValueAsync(const Windows::Storage::Streams::IBuffer & value) const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCommunicationStatus> WriteValueAsync(const Windows::Storage::Streams::IBuffer & value, Windows::Devices::Bluetooth::GenericAttributeProfile::GattWriteOption writeOption) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::GenericAttributeProfile::GattReadClientCharacteristicConfigurationDescriptorResult> ReadClientCharacteristicConfigurationDescriptorAsync() const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCommunicationStatus> WriteClientCharacteristicConfigurationDescriptorAsync(Windows::Devices::Bluetooth::GenericAttributeProfile::GattClientCharacteristicConfigurationDescriptorValue clientCharacteristicConfigurationDescriptorValue) const;
    event_token ValueChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic, Windows::Devices::Bluetooth::GenericAttributeProfile::GattValueChangedEventArgs> & valueChangedHandler) const;
    using ValueChanged_revoker = event_revoker<IGattCharacteristic>;
    ValueChanged_revoker ValueChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic, Windows::Devices::Bluetooth::GenericAttributeProfile::GattValueChangedEventArgs> & valueChangedHandler) const;
    void ValueChanged(event_token valueChangedEventCookie) const;
};

template <typename D>
struct WINRT_EBO impl_IGattCharacteristic2
{
    Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceService Service() const;
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::GenericAttributeProfile::GattDescriptor> GetAllDescriptors() const;
};

template <typename D>
struct WINRT_EBO impl_IGattCharacteristicStatics
{
    GUID ConvertShortIdToUuid(uint16_t shortId) const;
};

template <typename D>
struct WINRT_EBO impl_IGattCharacteristicUuidsStatics
{
    GUID BatteryLevel() const;
    GUID BloodPressureFeature() const;
    GUID BloodPressureMeasurement() const;
    GUID BodySensorLocation() const;
    GUID CscFeature() const;
    GUID CscMeasurement() const;
    GUID GlucoseFeature() const;
    GUID GlucoseMeasurement() const;
    GUID GlucoseMeasurementContext() const;
    GUID HeartRateControlPoint() const;
    GUID HeartRateMeasurement() const;
    GUID IntermediateCuffPressure() const;
    GUID IntermediateTemperature() const;
    GUID MeasurementInterval() const;
    GUID RecordAccessControlPoint() const;
    GUID RscFeature() const;
    GUID RscMeasurement() const;
    GUID SCControlPoint() const;
    GUID SensorLocation() const;
    GUID TemperatureMeasurement() const;
    GUID TemperatureType() const;
};

template <typename D>
struct WINRT_EBO impl_IGattCharacteristicUuidsStatics2
{
    GUID AlertCategoryId() const;
    GUID AlertCategoryIdBitMask() const;
    GUID AlertLevel() const;
    GUID AlertNotificationControlPoint() const;
    GUID AlertStatus() const;
    GUID GapAppearance() const;
    GUID BootKeyboardInputReport() const;
    GUID BootKeyboardOutputReport() const;
    GUID BootMouseInputReport() const;
    GUID CurrentTime() const;
    GUID CyclingPowerControlPoint() const;
    GUID CyclingPowerFeature() const;
    GUID CyclingPowerMeasurement() const;
    GUID CyclingPowerVector() const;
    GUID DateTime() const;
    GUID DayDateTime() const;
    GUID DayOfWeek() const;
    GUID GapDeviceName() const;
    GUID DstOffset() const;
    GUID ExactTime256() const;
    GUID FirmwareRevisionString() const;
    GUID HardwareRevisionString() const;
    GUID HidControlPoint() const;
    GUID HidInformation() const;
    GUID Ieee1107320601RegulatoryCertificationDataList() const;
    GUID LnControlPoint() const;
    GUID LnFeature() const;
    GUID LocalTimeInformation() const;
    GUID LocationAndSpeed() const;
    GUID ManufacturerNameString() const;
    GUID ModelNumberString() const;
    GUID Navigation() const;
    GUID NewAlert() const;
    GUID GapPeripheralPreferredConnectionParameters() const;
    GUID GapPeripheralPrivacyFlag() const;
    GUID PnpId() const;
    GUID PositionQuality() const;
    GUID ProtocolMode() const;
    GUID GapReconnectionAddress() const;
    GUID ReferenceTimeInformation() const;
    GUID Report() const;
    GUID ReportMap() const;
    GUID RingerControlPoint() const;
    GUID RingerSetting() const;
    GUID ScanIntervalWindow() const;
    GUID ScanRefresh() const;
    GUID SerialNumberString() const;
    GUID GattServiceChanged() const;
    GUID SoftwareRevisionString() const;
    GUID SupportedNewAlertCategory() const;
    GUID SupportUnreadAlertCategory() const;
    GUID SystemId() const;
    GUID TimeAccuracy() const;
    GUID TimeSource() const;
    GUID TimeUpdateControlPoint() const;
    GUID TimeUpdateState() const;
    GUID TimeWithDst() const;
    GUID TimeZone() const;
    GUID TxPowerLevel() const;
    GUID UnreadAlertStatus() const;
};

template <typename D>
struct WINRT_EBO impl_IGattDescriptor
{
    Windows::Devices::Bluetooth::GenericAttributeProfile::GattProtectionLevel ProtectionLevel() const;
    void ProtectionLevel(Windows::Devices::Bluetooth::GenericAttributeProfile::GattProtectionLevel value) const;
    GUID Uuid() const;
    uint16_t AttributeHandle() const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::GenericAttributeProfile::GattReadResult> ReadValueAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::GenericAttributeProfile::GattReadResult> ReadValueAsync(Windows::Devices::Bluetooth::BluetoothCacheMode cacheMode) const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCommunicationStatus> WriteValueAsync(const Windows::Storage::Streams::IBuffer & value) const;
};

template <typename D>
struct WINRT_EBO impl_IGattDescriptorStatics
{
    GUID ConvertShortIdToUuid(uint16_t shortId) const;
};

template <typename D>
struct WINRT_EBO impl_IGattDescriptorUuidsStatics
{
    GUID CharacteristicAggregateFormat() const;
    GUID CharacteristicExtendedProperties() const;
    GUID CharacteristicPresentationFormat() const;
    GUID CharacteristicUserDescription() const;
    GUID ClientCharacteristicConfiguration() const;
    GUID ServerCharacteristicConfiguration() const;
};

template <typename D>
struct WINRT_EBO impl_IGattDeviceService
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic> GetCharacteristics(GUID characteristicUuid) const;
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceService> GetIncludedServices(GUID serviceUuid) const;
    hstring DeviceId() const;
    GUID Uuid() const;
    uint16_t AttributeHandle() const;
};

template <typename D>
struct WINRT_EBO impl_IGattDeviceService2
{
    Windows::Devices::Bluetooth::BluetoothLEDevice Device() const;
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceService> ParentServices() const;
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic> GetAllCharacteristics() const;
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceService> GetAllIncludedServices() const;
};

template <typename D>
struct WINRT_EBO impl_IGattDeviceServiceStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceService> FromIdAsync(hstring_view deviceId) const;
    hstring GetDeviceSelectorFromUuid(GUID serviceUuid) const;
    hstring GetDeviceSelectorFromShortId(uint16_t serviceShortId) const;
    GUID ConvertShortIdToUuid(uint16_t shortId) const;
};

template <typename D>
struct WINRT_EBO impl_IGattPresentationFormat
{
    uint8_t FormatType() const;
    int32_t Exponent() const;
    uint16_t Unit() const;
    uint8_t Namespace() const;
    uint16_t Description() const;
};

template <typename D>
struct WINRT_EBO impl_IGattPresentationFormatStatics
{
    uint8_t BluetoothSigAssignedNumbers() const;
};

template <typename D>
struct WINRT_EBO impl_IGattPresentationFormatTypesStatics
{
    uint8_t Boolean() const;
    uint8_t Bit2() const;
    uint8_t Nibble() const;
    uint8_t UInt8() const;
    uint8_t UInt12() const;
    uint8_t UInt16() const;
    uint8_t UInt24() const;
    uint8_t UInt32() const;
    uint8_t UInt48() const;
    uint8_t UInt64() const;
    uint8_t UInt128() const;
    uint8_t SInt8() const;
    uint8_t SInt12() const;
    uint8_t SInt16() const;
    uint8_t SInt24() const;
    uint8_t SInt32() const;
    uint8_t SInt48() const;
    uint8_t SInt64() const;
    uint8_t SInt128() const;
    uint8_t Float32() const;
    uint8_t Float64() const;
    uint8_t SFloat() const;
    uint8_t Float() const;
    uint8_t DUInt16() const;
    uint8_t Utf8() const;
    uint8_t Utf16() const;
    uint8_t Struct() const;
};

template <typename D>
struct WINRT_EBO impl_IGattReadClientCharacteristicConfigurationDescriptorResult
{
    Windows::Devices::Bluetooth::GenericAttributeProfile::GattCommunicationStatus Status() const;
    Windows::Devices::Bluetooth::GenericAttributeProfile::GattClientCharacteristicConfigurationDescriptorValue ClientCharacteristicConfigurationDescriptor() const;
};

template <typename D>
struct WINRT_EBO impl_IGattReadResult
{
    Windows::Devices::Bluetooth::GenericAttributeProfile::GattCommunicationStatus Status() const;
    Windows::Storage::Streams::IBuffer Value() const;
};

template <typename D>
struct WINRT_EBO impl_IGattReliableWriteTransaction
{
    void WriteValue(const Windows::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic & characteristic, const Windows::Storage::Streams::IBuffer & value) const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCommunicationStatus> CommitAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IGattServiceUuidsStatics
{
    GUID Battery() const;
    GUID BloodPressure() const;
    GUID CyclingSpeedAndCadence() const;
    GUID GenericAccess() const;
    GUID GenericAttribute() const;
    GUID Glucose() const;
    GUID HealthThermometer() const;
    GUID HeartRate() const;
    GUID RunningSpeedAndCadence() const;
};

template <typename D>
struct WINRT_EBO impl_IGattServiceUuidsStatics2
{
    GUID AlertNotification() const;
    GUID CurrentTime() const;
    GUID CyclingPower() const;
    GUID DeviceInformation() const;
    GUID HumanInterfaceDevice() const;
    GUID ImmediateAlert() const;
    GUID LinkLoss() const;
    GUID LocationAndNavigation() const;
    GUID NextDstChange() const;
    GUID PhoneAlertStatus() const;
    GUID ReferenceTimeUpdate() const;
    GUID ScanParameters() const;
    GUID TxPower() const;
};

template <typename D>
struct WINRT_EBO impl_IGattValueChangedEventArgs
{
    Windows::Storage::Streams::IBuffer CharacteristicValue() const;
    Windows::Foundation::DateTime Timestamp() const;
};

}

namespace impl {

template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic>
{
    using abi = ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic;
    template <typename D> using consume = Windows::Devices::Bluetooth::GenericAttributeProfile::impl_IGattCharacteristic<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic2>
{
    using abi = ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristic2;
    template <typename D> using consume = Windows::Devices::Bluetooth::GenericAttributeProfile::impl_IGattCharacteristic2<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristicStatics>
{
    using abi = ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristicStatics;
    template <typename D> using consume = Windows::Devices::Bluetooth::GenericAttributeProfile::impl_IGattCharacteristicStatics<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristicUuidsStatics>
{
    using abi = ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristicUuidsStatics;
    template <typename D> using consume = Windows::Devices::Bluetooth::GenericAttributeProfile::impl_IGattCharacteristicUuidsStatics<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristicUuidsStatics2>
{
    using abi = ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattCharacteristicUuidsStatics2;
    template <typename D> using consume = Windows::Devices::Bluetooth::GenericAttributeProfile::impl_IGattCharacteristicUuidsStatics2<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDescriptor>
{
    using abi = ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDescriptor;
    template <typename D> using consume = Windows::Devices::Bluetooth::GenericAttributeProfile::impl_IGattDescriptor<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDescriptorStatics>
{
    using abi = ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDescriptorStatics;
    template <typename D> using consume = Windows::Devices::Bluetooth::GenericAttributeProfile::impl_IGattDescriptorStatics<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDescriptorUuidsStatics>
{
    using abi = ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDescriptorUuidsStatics;
    template <typename D> using consume = Windows::Devices::Bluetooth::GenericAttributeProfile::impl_IGattDescriptorUuidsStatics<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDeviceService>
{
    using abi = ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDeviceService;
    template <typename D> using consume = Windows::Devices::Bluetooth::GenericAttributeProfile::impl_IGattDeviceService<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDeviceService2>
{
    using abi = ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDeviceService2;
    template <typename D> using consume = Windows::Devices::Bluetooth::GenericAttributeProfile::impl_IGattDeviceService2<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDeviceServiceStatics>
{
    using abi = ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDeviceServiceStatics;
    template <typename D> using consume = Windows::Devices::Bluetooth::GenericAttributeProfile::impl_IGattDeviceServiceStatics<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::IGattPresentationFormat>
{
    using abi = ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattPresentationFormat;
    template <typename D> using consume = Windows::Devices::Bluetooth::GenericAttributeProfile::impl_IGattPresentationFormat<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::IGattPresentationFormatStatics>
{
    using abi = ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattPresentationFormatStatics;
    template <typename D> using consume = Windows::Devices::Bluetooth::GenericAttributeProfile::impl_IGattPresentationFormatStatics<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::IGattPresentationFormatTypesStatics>
{
    using abi = ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattPresentationFormatTypesStatics;
    template <typename D> using consume = Windows::Devices::Bluetooth::GenericAttributeProfile::impl_IGattPresentationFormatTypesStatics<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::IGattReadClientCharacteristicConfigurationDescriptorResult>
{
    using abi = ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattReadClientCharacteristicConfigurationDescriptorResult;
    template <typename D> using consume = Windows::Devices::Bluetooth::GenericAttributeProfile::impl_IGattReadClientCharacteristicConfigurationDescriptorResult<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::IGattReadResult>
{
    using abi = ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattReadResult;
    template <typename D> using consume = Windows::Devices::Bluetooth::GenericAttributeProfile::impl_IGattReadResult<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::IGattReliableWriteTransaction>
{
    using abi = ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattReliableWriteTransaction;
    template <typename D> using consume = Windows::Devices::Bluetooth::GenericAttributeProfile::impl_IGattReliableWriteTransaction<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::IGattServiceUuidsStatics>
{
    using abi = ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattServiceUuidsStatics;
    template <typename D> using consume = Windows::Devices::Bluetooth::GenericAttributeProfile::impl_IGattServiceUuidsStatics<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::IGattServiceUuidsStatics2>
{
    using abi = ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattServiceUuidsStatics2;
    template <typename D> using consume = Windows::Devices::Bluetooth::GenericAttributeProfile::impl_IGattServiceUuidsStatics2<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::IGattValueChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::IGattValueChangedEventArgs;
    template <typename D> using consume = Windows::Devices::Bluetooth::GenericAttributeProfile::impl_IGattValueChangedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic>
{
    using abi = ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristic;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.GenericAttributeProfile.GattCharacteristic"; }
};

template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::GattCharacteristicUuids>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.GenericAttributeProfile.GattCharacteristicUuids"; }
};

template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::GattDescriptor>
{
    using abi = ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattDescriptor;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.GenericAttributeProfile.GattDescriptor"; }
};

template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::GattDescriptorUuids>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.GenericAttributeProfile.GattDescriptorUuids"; }
};

template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceService>
{
    using abi = ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceService;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.GenericAttributeProfile.GattDeviceService"; }
};

template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::GattPresentationFormat>
{
    using abi = ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattPresentationFormat;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.GenericAttributeProfile.GattPresentationFormat"; }
};

template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::GattPresentationFormatTypes>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.GenericAttributeProfile.GattPresentationFormatTypes"; }
};

template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::GattReadClientCharacteristicConfigurationDescriptorResult>
{
    using abi = ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattReadClientCharacteristicConfigurationDescriptorResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.GenericAttributeProfile.GattReadClientCharacteristicConfigurationDescriptorResult"; }
};

template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::GattReadResult>
{
    using abi = ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattReadResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.GenericAttributeProfile.GattReadResult"; }
};

template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::GattReliableWriteTransaction>
{
    using abi = ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattReliableWriteTransaction;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.GenericAttributeProfile.GattReliableWriteTransaction"; }
};

template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::GattServiceUuids>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.GenericAttributeProfile.GattServiceUuids"; }
};

template <> struct traits<Windows::Devices::Bluetooth::GenericAttributeProfile::GattValueChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Bluetooth::GenericAttributeProfile::GattValueChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.GenericAttributeProfile.GattValueChangedEventArgs"; }
};

}

}
