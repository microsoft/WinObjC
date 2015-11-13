//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

// WindowsDevicesBluetoothGenericAttributeProfile.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WDBGGattDeviceService, WDBGGattCharacteristic, WDBGGattDescriptor, WDBGGattPresentationFormat, WDBGGattReadResult,
    WDBGGattReadClientCharacteristicConfigurationDescriptorResult, WDBGGattValueChangedEventArgs, WDBGGattServiceUuids,
    WDBGGattCharacteristicUuids, WDBGGattDescriptorUuids, WDBGGattReliableWriteTransaction, WDBGGattPresentationFormatTypes;
@protocol WDBGIGattDeviceServiceStatics
, WDBGIGattCharacteristicStatics, WDBGIGattCharacteristic, WDBGIGattDescriptorStatics, WDBGIGattDescriptor,
    WDBGIGattPresentationFormatStatics, WDBGIGattPresentationFormatTypesStatics, WDBGIGattPresentationFormat,
    WDBGIGattValueChangedEventArgs, WDBGIGattServiceUuidsStatics, WDBGIGattCharacteristicUuidsStatics, WDBGIGattDescriptorUuidsStatics,
    WDBGIGattReliableWriteTransaction, WDBGIGattReadResult, WDBGIGattReadClientCharacteristicConfigurationDescriptorResult,
    WDBGIGattDeviceService;

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattCharacteristicProperties
enum _WDBGGattCharacteristicProperties {
    WDBGGattCharacteristicPropertiesNone = 0,
    WDBGGattCharacteristicPropertiesBroadcast = 1,
    WDBGGattCharacteristicPropertiesRead = 2,
    WDBGGattCharacteristicPropertiesWriteWithoutResponse = 4,
    WDBGGattCharacteristicPropertiesWrite = 8,
    WDBGGattCharacteristicPropertiesNotify = 16,
    WDBGGattCharacteristicPropertiesIndicate = 32,
    WDBGGattCharacteristicPropertiesAuthenticatedSignedWrites = 64,
    WDBGGattCharacteristicPropertiesExtendedProperties = 128,
    WDBGGattCharacteristicPropertiesReliableWrites = 256,
    WDBGGattCharacteristicPropertiesWritableAuxiliaries = 512,
};
typedef unsigned WDBGGattCharacteristicProperties;

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattClientCharacteristicConfigurationDescriptorValue
enum _WDBGGattClientCharacteristicConfigurationDescriptorValue {
    WDBGGattClientCharacteristicConfigurationDescriptorValueNone = 0,
    WDBGGattClientCharacteristicConfigurationDescriptorValueNotify = 1,
    WDBGGattClientCharacteristicConfigurationDescriptorValueIndicate = 2,
};
typedef unsigned WDBGGattClientCharacteristicConfigurationDescriptorValue;

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattProtectionLevel
enum _WDBGGattProtectionLevel {
    WDBGGattProtectionLevelPlain = 0,
    WDBGGattProtectionLevelAuthenticationRequired = 1,
    WDBGGattProtectionLevelEncryptionRequired = 2,
    WDBGGattProtectionLevelEncryptionAndAuthenticationRequired = 3,
};
typedef unsigned WDBGGattProtectionLevel;

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattWriteOption
enum _WDBGGattWriteOption {
    WDBGGattWriteOptionWriteWithResponse = 0,
    WDBGGattWriteOptionWriteWithoutResponse = 1,
};
typedef unsigned WDBGGattWriteOption;

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattCommunicationStatus
enum _WDBGGattCommunicationStatus {
    WDBGGattCommunicationStatusSuccess = 0,
    WDBGGattCommunicationStatusUnreachable = 1,
};
typedef unsigned WDBGGattCommunicationStatus;

#include "WindowsDevicesBluetooth.h"
#include "WindowsFoundation.h"
#include "WindowsStorageStreams.h"
#include "WindowsFoundationCollections.h"

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

#endif // __WFIClosable_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattDeviceService
#ifndef __WDBGGattDeviceService_DEFINED__
#define __WDBGGattDeviceService_DEFINED__

WINRT_EXPORT
@interface WDBGGattDeviceService : RTObject <WFIClosable>
+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDBGGattDeviceService*))success failure:(void (^)(NSError*))failure;
+ (NSString*)getDeviceSelectorFromUuid:(WFGUID*)serviceUuid;
+ (NSString*)getDeviceSelectorFromShortId:(unsigned short)serviceShortId;
+ (WFGUID*)convertShortIdToUuid:(unsigned short)shortId;
@property (readonly) unsigned short attributeHandle;
@property (readonly) NSString* deviceId;
@property (readonly) WFGUID* uuid;
- (id<NSFastEnumeration> /*WDBGGattCharacteristic*/)getCharacteristics:(WFGUID*)characteristicUuid;
- (id<NSFastEnumeration> /*WDBGGattDeviceService*/)getIncludedServices:(WFGUID*)serviceUuid;
- (void)close;
@end

#endif // __WDBGGattDeviceService_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattCharacteristic
#ifndef __WDBGGattCharacteristic_DEFINED__
#define __WDBGGattCharacteristic_DEFINED__

WINRT_EXPORT
@interface WDBGGattCharacteristic : RTObject
+ (WFGUID*)convertShortIdToUuid:(unsigned short)shortId;
@property WDBGGattProtectionLevel protectionLevel;
@property (readonly) unsigned short attributeHandle;
@property (readonly) WDBGGattCharacteristicProperties characteristicProperties;
@property (readonly) id<NSFastEnumeration> /*WDBGGattPresentationFormat*/ presentationFormats;
@property (readonly) NSString* userDescription;
@property (readonly) WFGUID* uuid;
- (EventRegistrationToken)addValueChangedEvent:(void (^)(WDBGGattCharacteristic*, WDBGGattValueChangedEventArgs*))del;
- (void)removeValueChangedEvent:(EventRegistrationToken)tok;
- (id<NSFastEnumeration> /*WDBGGattDescriptor*/)getDescriptors:(WFGUID*)descriptorUuid;
- (void)readValueAsyncWithSuccess:(void (^)(WDBGGattReadResult*))success failure:(void (^)(NSError*))failure;
- (void)readValueWithCacheModeAsync:(WDBBluetoothCacheMode)cacheMode
                            success:(void (^)(WDBGGattReadResult*))success
                            failure:(void (^)(NSError*))failure;
- (void)writeValueAsync:(RTObject<WSSIBuffer>*)value
                success:(void (^)(WDBGGattCommunicationStatus))success
                failure:(void (^)(NSError*))failure;
- (void)writeValueWithOptionAsync:(RTObject<WSSIBuffer>*)value
                      writeOption:(WDBGGattWriteOption)writeOption
                          success:(void (^)(WDBGGattCommunicationStatus))success
                          failure:(void (^)(NSError*))failure;
- (void)readClientCharacteristicConfigurationDescriptorAsyncWithSuccess:
            (void (^)(WDBGGattReadClientCharacteristicConfigurationDescriptorResult*))success
                                                                failure:(void (^)(NSError*))failure;
- (void)writeClientCharacteristicConfigurationDescriptorAsync:
            (WDBGGattClientCharacteristicConfigurationDescriptorValue)clientCharacteristicConfigurationDescriptorValue
                                                      success:(void (^)(WDBGGattCommunicationStatus))success
                                                      failure:(void (^)(NSError*))failure;
@end

#endif // __WDBGGattCharacteristic_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattDescriptor
#ifndef __WDBGGattDescriptor_DEFINED__
#define __WDBGGattDescriptor_DEFINED__

WINRT_EXPORT
@interface WDBGGattDescriptor : RTObject
+ (WFGUID*)convertShortIdToUuid:(unsigned short)shortId;
@property WDBGGattProtectionLevel protectionLevel;
@property (readonly) unsigned short attributeHandle;
@property (readonly) WFGUID* uuid;
- (void)readValueAsyncWithSuccess:(void (^)(WDBGGattReadResult*))success failure:(void (^)(NSError*))failure;
- (void)readValueWithCacheModeAsync:(WDBBluetoothCacheMode)cacheMode
                            success:(void (^)(WDBGGattReadResult*))success
                            failure:(void (^)(NSError*))failure;
- (void)writeValueAsync:(RTObject<WSSIBuffer>*)value
                success:(void (^)(WDBGGattCommunicationStatus))success
                failure:(void (^)(NSError*))failure;
@end

#endif // __WDBGGattDescriptor_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattPresentationFormat
#ifndef __WDBGGattPresentationFormat_DEFINED__
#define __WDBGGattPresentationFormat_DEFINED__

WINRT_EXPORT
@interface WDBGGattPresentationFormat : RTObject
@property (readonly) unsigned short description;
@property (readonly) int exponent;
@property (readonly) uint8_t formatType;
@property (readonly) uint8_t Namespace;
@property (readonly) unsigned short unit;
+ (uint8_t)bluetoothSigAssignedNumbers;
@end

#endif // __WDBGGattPresentationFormat_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattReadResult
#ifndef __WDBGGattReadResult_DEFINED__
#define __WDBGGattReadResult_DEFINED__

WINRT_EXPORT
@interface WDBGGattReadResult : RTObject
@property (readonly) WDBGGattCommunicationStatus status;
@property (readonly) RTObject<WSSIBuffer>* value;
@end

#endif // __WDBGGattReadResult_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattReadClientCharacteristicConfigurationDescriptorResult
#ifndef __WDBGGattReadClientCharacteristicConfigurationDescriptorResult_DEFINED__
#define __WDBGGattReadClientCharacteristicConfigurationDescriptorResult_DEFINED__

WINRT_EXPORT
@interface WDBGGattReadClientCharacteristicConfigurationDescriptorResult : RTObject
@property (readonly) WDBGGattClientCharacteristicConfigurationDescriptorValue clientCharacteristicConfigurationDescriptor;
@property (readonly) WDBGGattCommunicationStatus status;
@end

#endif // __WDBGGattReadClientCharacteristicConfigurationDescriptorResult_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattValueChangedEventArgs
#ifndef __WDBGGattValueChangedEventArgs_DEFINED__
#define __WDBGGattValueChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDBGGattValueChangedEventArgs : RTObject
@property (readonly) RTObject<WSSIBuffer>* characteristicValue;
@property (readonly) WFDateTime* timestamp;
@end

#endif // __WDBGGattValueChangedEventArgs_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattServiceUuids
#ifndef __WDBGGattServiceUuids_DEFINED__
#define __WDBGGattServiceUuids_DEFINED__

WINRT_EXPORT
@interface WDBGGattServiceUuids : RTObject
+ (WFGUID*)battery;
+ (WFGUID*)bloodPressure;
+ (WFGUID*)cyclingSpeedAndCadence;
+ (WFGUID*)genericAccess;
+ (WFGUID*)genericAttribute;
+ (WFGUID*)glucose;
+ (WFGUID*)healthThermometer;
+ (WFGUID*)heartRate;
+ (WFGUID*)runningSpeedAndCadence;
@end

#endif // __WDBGGattServiceUuids_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattCharacteristicUuids
#ifndef __WDBGGattCharacteristicUuids_DEFINED__
#define __WDBGGattCharacteristicUuids_DEFINED__

WINRT_EXPORT
@interface WDBGGattCharacteristicUuids : RTObject
+ (WFGUID*)batteryLevel;
+ (WFGUID*)bloodPressureFeature;
+ (WFGUID*)bloodPressureMeasurement;
+ (WFGUID*)bodySensorLocation;
+ (WFGUID*)cscFeature;
+ (WFGUID*)cscMeasurement;
+ (WFGUID*)glucoseFeature;
+ (WFGUID*)glucoseMeasurement;
+ (WFGUID*)glucoseMeasurementContext;
+ (WFGUID*)heartRateControlPoint;
+ (WFGUID*)heartRateMeasurement;
+ (WFGUID*)intermediateCuffPressure;
+ (WFGUID*)intermediateTemperature;
+ (WFGUID*)measurementInterval;
+ (WFGUID*)recordAccessControlPoint;
+ (WFGUID*)rscFeature;
+ (WFGUID*)rscMeasurement;
+ (WFGUID*)sCControlPoint;
+ (WFGUID*)sensorLocation;
+ (WFGUID*)temperatureMeasurement;
+ (WFGUID*)temperatureType;
@end

#endif // __WDBGGattCharacteristicUuids_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattDescriptorUuids
#ifndef __WDBGGattDescriptorUuids_DEFINED__
#define __WDBGGattDescriptorUuids_DEFINED__

WINRT_EXPORT
@interface WDBGGattDescriptorUuids : RTObject
+ (WFGUID*)characteristicAggregateFormat;
+ (WFGUID*)characteristicExtendedProperties;
+ (WFGUID*)characteristicPresentationFormat;
+ (WFGUID*)characteristicUserDescription;
+ (WFGUID*)clientCharacteristicConfiguration;
+ (WFGUID*)serverCharacteristicConfiguration;
@end

#endif // __WDBGGattDescriptorUuids_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattReliableWriteTransaction
#ifndef __WDBGGattReliableWriteTransaction_DEFINED__
#define __WDBGGattReliableWriteTransaction_DEFINED__

WINRT_EXPORT
@interface WDBGGattReliableWriteTransaction : RTObject
+ (instancetype)create ACTIVATOR;
- (void)writeValue:(WDBGGattCharacteristic*)characteristic value:(RTObject<WSSIBuffer>*)value;
- (void)commitAsyncWithSuccess:(void (^)(WDBGGattCommunicationStatus))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDBGGattReliableWriteTransaction_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattPresentationFormatTypes
#ifndef __WDBGGattPresentationFormatTypes_DEFINED__
#define __WDBGGattPresentationFormatTypes_DEFINED__

WINRT_EXPORT
@interface WDBGGattPresentationFormatTypes : RTObject
+ (uint8_t)bit2;
+ (uint8_t)boolean;
+ (uint8_t)dUInt16;
+ (uint8_t)Float;
+ (uint8_t)float32;
+ (uint8_t)float64;
+ (uint8_t)nibble;
+ (uint8_t)sFloat;
+ (uint8_t)sInt12;
+ (uint8_t)sInt128;
+ (uint8_t)sInt16;
+ (uint8_t)sInt24;
+ (uint8_t)sInt32;
+ (uint8_t)sInt48;
+ (uint8_t)sInt64;
+ (uint8_t)sInt8;
+ (uint8_t)Struct;
+ (uint8_t)uInt12;
+ (uint8_t)uInt128;
+ (uint8_t)uInt16;
+ (uint8_t)uInt24;
+ (uint8_t)uInt32;
+ (uint8_t)uInt48;
+ (uint8_t)uInt64;
+ (uint8_t)uInt8;
+ (uint8_t)utf16;
+ (uint8_t)utf8;
@end

#endif // __WDBGGattPresentationFormatTypes_DEFINED__
