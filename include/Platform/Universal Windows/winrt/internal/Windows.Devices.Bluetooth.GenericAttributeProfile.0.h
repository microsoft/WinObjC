// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Bluetooth::GenericAttributeProfile {

struct IGattCharacteristic;
struct IGattCharacteristic2;
struct IGattCharacteristicStatics;
struct IGattCharacteristicUuidsStatics;
struct IGattCharacteristicUuidsStatics2;
struct IGattDescriptor;
struct IGattDescriptorStatics;
struct IGattDescriptorUuidsStatics;
struct IGattDeviceService;
struct IGattDeviceService2;
struct IGattDeviceServiceStatics;
struct IGattPresentationFormat;
struct IGattPresentationFormatStatics;
struct IGattPresentationFormatTypesStatics;
struct IGattReadClientCharacteristicConfigurationDescriptorResult;
struct IGattReadResult;
struct IGattReliableWriteTransaction;
struct IGattServiceUuidsStatics;
struct IGattServiceUuidsStatics2;
struct IGattValueChangedEventArgs;
struct GattCharacteristic;
struct GattDescriptor;
struct GattDeviceService;
struct GattPresentationFormat;
struct GattReadClientCharacteristicConfigurationDescriptorResult;
struct GattReadResult;
struct GattReliableWriteTransaction;
struct GattValueChangedEventArgs;

}

namespace Windows::Devices::Bluetooth::GenericAttributeProfile {

struct IGattCharacteristic;
struct IGattCharacteristic2;
struct IGattCharacteristicStatics;
struct IGattCharacteristicUuidsStatics;
struct IGattCharacteristicUuidsStatics2;
struct IGattDescriptor;
struct IGattDescriptorStatics;
struct IGattDescriptorUuidsStatics;
struct IGattDeviceService;
struct IGattDeviceService2;
struct IGattDeviceServiceStatics;
struct IGattPresentationFormat;
struct IGattPresentationFormatStatics;
struct IGattPresentationFormatTypesStatics;
struct IGattReadClientCharacteristicConfigurationDescriptorResult;
struct IGattReadResult;
struct IGattReliableWriteTransaction;
struct IGattServiceUuidsStatics;
struct IGattServiceUuidsStatics2;
struct IGattValueChangedEventArgs;
struct GattCharacteristic;
struct GattCharacteristicUuids;
struct GattDescriptor;
struct GattDescriptorUuids;
struct GattDeviceService;
struct GattPresentationFormat;
struct GattPresentationFormatTypes;
struct GattReadClientCharacteristicConfigurationDescriptorResult;
struct GattReadResult;
struct GattReliableWriteTransaction;
struct GattServiceUuids;
struct GattValueChangedEventArgs;

}

namespace Windows::Devices::Bluetooth::GenericAttributeProfile {

template <typename T> struct impl_IGattCharacteristic;
template <typename T> struct impl_IGattCharacteristic2;
template <typename T> struct impl_IGattCharacteristicStatics;
template <typename T> struct impl_IGattCharacteristicUuidsStatics;
template <typename T> struct impl_IGattCharacteristicUuidsStatics2;
template <typename T> struct impl_IGattDescriptor;
template <typename T> struct impl_IGattDescriptorStatics;
template <typename T> struct impl_IGattDescriptorUuidsStatics;
template <typename T> struct impl_IGattDeviceService;
template <typename T> struct impl_IGattDeviceService2;
template <typename T> struct impl_IGattDeviceServiceStatics;
template <typename T> struct impl_IGattPresentationFormat;
template <typename T> struct impl_IGattPresentationFormatStatics;
template <typename T> struct impl_IGattPresentationFormatTypesStatics;
template <typename T> struct impl_IGattReadClientCharacteristicConfigurationDescriptorResult;
template <typename T> struct impl_IGattReadResult;
template <typename T> struct impl_IGattReliableWriteTransaction;
template <typename T> struct impl_IGattServiceUuidsStatics;
template <typename T> struct impl_IGattServiceUuidsStatics2;
template <typename T> struct impl_IGattValueChangedEventArgs;

}

namespace Windows::Devices::Bluetooth::GenericAttributeProfile {

enum class GattCharacteristicProperties : unsigned
{
    None = 0x0,
    Broadcast = 0x1,
    Read = 0x2,
    WriteWithoutResponse = 0x4,
    Write = 0x8,
    Notify = 0x10,
    Indicate = 0x20,
    AuthenticatedSignedWrites = 0x40,
    ExtendedProperties = 0x80,
    ReliableWrites = 0x100,
    WritableAuxiliaries = 0x200,
};

DEFINE_ENUM_FLAG_OPERATORS(GattCharacteristicProperties)

enum class GattClientCharacteristicConfigurationDescriptorValue
{
    None = 0,
    Notify = 1,
    Indicate = 2,
};

enum class GattCommunicationStatus
{
    Success = 0,
    Unreachable = 1,
};

enum class GattProtectionLevel
{
    Plain = 0,
    AuthenticationRequired = 1,
    EncryptionRequired = 2,
    EncryptionAndAuthenticationRequired = 3,
};

enum class GattWriteOption
{
    WriteWithResponse = 0,
    WriteWithoutResponse = 1,
};

}

}
