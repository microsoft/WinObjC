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

// WindowsDevicesBluetoothGenericAttributeProfile.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
#define OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsConsolidatedNamespace.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WDBGGattDeviceService, WDBGGattDeviceServicesResult, WDBGGattProtocolError, WDBGGattSession, WDBGGattSessionStatusChangedEventArgs, WDBGGattCharacteristic, WDBGGattCharacteristicsResult, WDBGGattDescriptor, WDBGGattPresentationFormat, WDBGGattReadResult, WDBGGattReadClientCharacteristicConfigurationDescriptorResult, WDBGGattValueChangedEventArgs, WDBGGattDescriptorsResult, WDBGGattWriteResult, WDBGGattPresentationFormatTypes, WDBGGattServiceUuids, WDBGGattCharacteristicUuids, WDBGGattDescriptorUuids, WDBGGattReliableWriteTransaction, WDBGGattServiceProviderAdvertisingParameters, WDBGGattLocalCharacteristicParameters, WDBGGattLocalDescriptorParameters, WDBGGattServiceProviderResult, WDBGGattLocalService, WDBGGattServiceProvider, WDBGGattServiceProviderAdvertisementStatusChangedEventArgs, WDBGGattLocalCharacteristicResult, WDBGGattLocalCharacteristic, WDBGGattLocalDescriptorResult, WDBGGattLocalDescriptor, WDBGGattSubscribedClient, WDBGGattReadRequestedEventArgs, WDBGGattWriteRequestedEventArgs, WDBGGattClientNotificationResult, WDBGGattReadRequest, WDBGGattRequestStateChangedEventArgs, WDBGGattWriteRequest;
@protocol WDBGIGattProtocolErrorStatics, WDBGIGattSessionStatics, WDBGIGattSession, WDBGIGattSessionStatusChangedEventArgs, WDBGIGattDeviceServiceStatics, WDBGIGattDeviceServiceStatics2, WDBGIGattDeviceService, WDBGIGattDeviceService2, WDBGIGattDeviceService3, WDBGIGattDeviceServicesResult, WDBGIGattCharacteristicStatics, WDBGIGattCharacteristic, WDBGIGattCharacteristic2, WDBGIGattCharacteristic3, WDBGIGattCharacteristicsResult, WDBGIGattDescriptorStatics, WDBGIGattDescriptor, WDBGIGattDescriptor2, WDBGIGattDescriptorsResult, WDBGIGattPresentationFormatTypesStatics, WDBGIGattPresentationFormatStatics, WDBGIGattPresentationFormatStatics2, WDBGIGattPresentationFormat, WDBGIGattValueChangedEventArgs, WDBGIGattServiceUuidsStatics, WDBGIGattServiceUuidsStatics2, WDBGIGattCharacteristicUuidsStatics, WDBGIGattCharacteristicUuidsStatics2, WDBGIGattDescriptorUuidsStatics, WDBGIGattReliableWriteTransaction, WDBGIGattReliableWriteTransaction2, WDBGIGattReadResult, WDBGIGattReadResult2, WDBGIGattWriteResult, WDBGIGattReadClientCharacteristicConfigurationDescriptorResult, WDBGIGattReadClientCharacteristicConfigurationDescriptorResult2, WDBGIGattServiceProviderAdvertisingParameters, WDBGIGattLocalCharacteristicParameters, WDBGIGattLocalDescriptorParameters, WDBGIGattServiceProviderStatics, WDBGIGattServiceProvider, WDBGIGattServiceProviderAdvertisementStatusChangedEventArgs, WDBGIGattServiceProviderResult, WDBGIGattLocalService, WDBGIGattLocalCharacteristic, WDBGIGattLocalCharacteristicResult, WDBGIGattSubscribedClient, WDBGIGattClientNotificationResult, WDBGIGattClientNotificationResult2, WDBGIGattLocalDescriptor, WDBGIGattLocalDescriptorResult, WDBGIGattReadRequest, WDBGIGattWriteRequest, WDBGIGattReadRequestedEventArgs, WDBGIGattWriteRequestedEventArgs, WDBGIGattRequestStateChangedEventArgs;

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattSessionStatus
enum _WDBGGattSessionStatus {
    WDBGGattSessionStatusClosed = 0,
    WDBGGattSessionStatusActive = 1,
};
typedef unsigned WDBGGattSessionStatus;

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
    WDBGGattCommunicationStatusProtocolError = 2,
    WDBGGattCommunicationStatusAccessDenied = 3,
};
typedef unsigned WDBGGattCommunicationStatus;

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattSharingMode
enum _WDBGGattSharingMode {
    WDBGGattSharingModeUnspecified = 0,
    WDBGGattSharingModeExclusive = 1,
    WDBGGattSharingModeSharedReadOnly = 2,
    WDBGGattSharingModeSharedReadAndWrite = 3,
};
typedef unsigned WDBGGattSharingMode;

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattOpenStatus
enum _WDBGGattOpenStatus {
    WDBGGattOpenStatusUnspecified = 0,
    WDBGGattOpenStatusSuccess = 1,
    WDBGGattOpenStatusAlreadyOpened = 2,
    WDBGGattOpenStatusNotFound = 3,
    WDBGGattOpenStatusSharingViolation = 4,
    WDBGGattOpenStatusAccessDenied = 5,
};
typedef unsigned WDBGGattOpenStatus;

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattRequestState
enum _WDBGGattRequestState {
    WDBGGattRequestStatePending = 0,
    WDBGGattRequestStateCompleted = 1,
    WDBGGattRequestStateCanceled = 2,
};
typedef unsigned WDBGGattRequestState;

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattServiceProviderAdvertisementStatus
enum _WDBGGattServiceProviderAdvertisementStatus {
    WDBGGattServiceProviderAdvertisementStatusCreated = 0,
    WDBGGattServiceProviderAdvertisementStatusStopped = 1,
    WDBGGattServiceProviderAdvertisementStatusStarted = 2,
    WDBGGattServiceProviderAdvertisementStatusAborted = 3,
};
typedef unsigned WDBGGattServiceProviderAdvertisementStatus;

#include "WindowsFoundation.h"
#include "WindowsDevicesBluetooth.h"
#include "WindowsDevicesEnumeration.h"
#include "WindowsStorageStreams.h"

#import <Foundation/Foundation.h>

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattDeviceService
#ifndef __WDBGGattDeviceService_DEFINED__
#define __WDBGGattDeviceService_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBGGattDeviceService : RTObject <WFIClosable>
+ (void)fromIdWithSharingModeAsync:(NSString *)deviceId sharingMode:(WDBGGattSharingMode)sharingMode success:(void (^)(WDBGGattDeviceService*))success failure:(void (^)(NSError*))failure;
+ (NSString *)getDeviceSelectorForBluetoothDeviceId:(WDBBluetoothDeviceId*)bluetoothDeviceId;
+ (NSString *)getDeviceSelectorForBluetoothDeviceIdWithCacheMode:(WDBBluetoothDeviceId*)bluetoothDeviceId cacheMode:(WDBBluetoothCacheMode)cacheMode;
+ (NSString *)getDeviceSelectorForBluetoothDeviceIdAndUuid:(WDBBluetoothDeviceId*)bluetoothDeviceId serviceUuid:(WFGUID*)serviceUuid;
+ (NSString *)getDeviceSelectorForBluetoothDeviceIdAndUuidWithCacheMode:(WDBBluetoothDeviceId*)bluetoothDeviceId serviceUuid:(WFGUID*)serviceUuid cacheMode:(WDBBluetoothCacheMode)cacheMode;
+ (void)fromIdAsync:(NSString *)deviceId success:(void (^)(WDBGGattDeviceService*))success failure:(void (^)(NSError*))failure;
+ (NSString *)getDeviceSelectorFromUuid:(WFGUID*)serviceUuid;
+ (NSString *)getDeviceSelectorFromShortId:(unsigned short)serviceShortId;
+ (WFGUID*)convertShortIdToUuid:(unsigned short)shortId;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned short attributeHandle;
@property (readonly) NSString * deviceId;
@property (readonly) WFGUID* uuid;
@property (readonly) WDBBluetoothLEDevice* device;
@property (readonly) NSArray* /* WDBGGattDeviceService* */ parentServices;
@property (readonly) WDEDeviceAccessInformation* deviceAccessInformation;
@property (readonly) WDBGGattSession* session;
@property (readonly) WDBGGattSharingMode sharingMode;
- (NSArray* /* WDBGGattCharacteristic* */)getCharacteristics:(WFGUID*)characteristicUuid;
- (NSArray* /* WDBGGattDeviceService* */)getIncludedServices:(WFGUID*)serviceUuid;
- (void)close;
- (NSArray* /* WDBGGattCharacteristic* */)getAllCharacteristics;
- (NSArray* /* WDBGGattDeviceService* */)getAllIncludedServices;
- (void)requestAccessAsyncWithSuccess:(void (^)(WDEDeviceAccessStatus))success failure:(void (^)(NSError*))failure;
- (void)openAsync:(WDBGGattSharingMode)sharingMode success:(void (^)(WDBGGattOpenStatus))success failure:(void (^)(NSError*))failure;
- (void)getCharacteristicsAsyncWithSuccess:(void (^)(WDBGGattCharacteristicsResult*))success failure:(void (^)(NSError*))failure;
- (void)getCharacteristicsWithCacheModeAsync:(WDBBluetoothCacheMode)cacheMode success:(void (^)(WDBGGattCharacteristicsResult*))success failure:(void (^)(NSError*))failure;
- (void)getCharacteristicsForUuidAsync:(WFGUID*)characteristicUuid success:(void (^)(WDBGGattCharacteristicsResult*))success failure:(void (^)(NSError*))failure;
- (void)getCharacteristicsForUuidWithCacheModeAsync:(WFGUID*)characteristicUuid cacheMode:(WDBBluetoothCacheMode)cacheMode success:(void (^)(WDBGGattCharacteristicsResult*))success failure:(void (^)(NSError*))failure;
- (void)getIncludedServicesAsyncWithSuccess:(void (^)(WDBGGattDeviceServicesResult*))success failure:(void (^)(NSError*))failure;
- (void)getIncludedServicesWithCacheModeAsync:(WDBBluetoothCacheMode)cacheMode success:(void (^)(WDBGGattDeviceServicesResult*))success failure:(void (^)(NSError*))failure;
- (void)getIncludedServicesForUuidAsync:(WFGUID*)serviceUuid success:(void (^)(WDBGGattDeviceServicesResult*))success failure:(void (^)(NSError*))failure;
- (void)getIncludedServicesForUuidWithCacheModeAsync:(WFGUID*)serviceUuid cacheMode:(WDBBluetoothCacheMode)cacheMode success:(void (^)(WDBGGattDeviceServicesResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDBGGattDeviceService_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattDeviceServicesResult
#ifndef __WDBGGattDeviceServicesResult_DEFINED__
#define __WDBGGattDeviceServicesResult_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBGGattDeviceServicesResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) id /* uint8_t */ protocolError;
@property (readonly) NSArray* /* WDBGGattDeviceService* */ services;
@property (readonly) WDBGGattCommunicationStatus status;
@end

#endif // __WDBGGattDeviceServicesResult_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattProtocolError
#ifndef __WDBGGattProtocolError_DEFINED__
#define __WDBGGattProtocolError_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBGGattProtocolError : RTObject
+ (uint8_t)attributeNotFound;
+ (uint8_t)attributeNotLong;
+ (uint8_t)insufficientAuthentication;
+ (uint8_t)insufficientAuthorization;
+ (uint8_t)insufficientEncryption;
+ (uint8_t)insufficientEncryptionKeySize;
+ (uint8_t)insufficientResources;
+ (uint8_t)invalidAttributeValueLength;
+ (uint8_t)invalidHandle;
+ (uint8_t)invalidOffset;
+ (uint8_t)invalidPdu;
+ (uint8_t)prepareQueueFull;
+ (uint8_t)readNotPermitted;
+ (uint8_t)requestNotSupported;
+ (uint8_t)unlikelyError;
+ (uint8_t)unsupportedGroupType;
+ (uint8_t)writeNotPermitted;
@end

#endif // __WDBGGattProtocolError_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattSession
#ifndef __WDBGGattSession_DEFINED__
#define __WDBGGattSession_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBGGattSession : RTObject <WFIClosable>
+ (void)fromDeviceIdAsync:(WDBBluetoothDeviceId*)deviceId success:(void (^)(WDBGGattSession*))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL maintainConnection;
@property (readonly) BOOL canMaintainConnection;
@property (readonly) WDBBluetoothDeviceId* deviceId;
@property (readonly) unsigned short maxPduSize;
@property (readonly) WDBGGattSessionStatus sessionStatus;
- (EventRegistrationToken)addMaxPduSizeChangedEvent:(void(^)(WDBGGattSession*, RTObject*))del;
- (void)removeMaxPduSizeChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSessionStatusChangedEvent:(void(^)(WDBGGattSession*, WDBGGattSessionStatusChangedEventArgs*))del;
- (void)removeSessionStatusChangedEvent:(EventRegistrationToken)tok;
- (void)close;
@end

#endif // __WDBGGattSession_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattSessionStatusChangedEventArgs
#ifndef __WDBGGattSessionStatusChangedEventArgs_DEFINED__
#define __WDBGGattSessionStatusChangedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBGGattSessionStatusChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDBBluetoothError error;
@property (readonly) WDBGGattSessionStatus status;
@end

#endif // __WDBGGattSessionStatusChangedEventArgs_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattCharacteristic
#ifndef __WDBGGattCharacteristic_DEFINED__
#define __WDBGGattCharacteristic_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBGGattCharacteristic : RTObject
+ (WFGUID*)convertShortIdToUuid:(unsigned short)shortId;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WDBGGattProtectionLevel protectionLevel;
@property (readonly) unsigned short attributeHandle;
@property (readonly) WDBGGattCharacteristicProperties characteristicProperties;
@property (readonly) NSArray* /* WDBGGattPresentationFormat* */ presentationFormats;
@property (readonly) NSString * userDescription;
@property (readonly) WFGUID* uuid;
@property (readonly) WDBGGattDeviceService* service;
- (EventRegistrationToken)addValueChangedEvent:(void(^)(WDBGGattCharacteristic*, WDBGGattValueChangedEventArgs*))del;
- (void)removeValueChangedEvent:(EventRegistrationToken)tok;
- (NSArray* /* WDBGGattDescriptor* */)getDescriptors:(WFGUID*)descriptorUuid;
- (void)readValueAsyncWithSuccess:(void (^)(WDBGGattReadResult*))success failure:(void (^)(NSError*))failure;
- (void)readValueWithCacheModeAsync:(WDBBluetoothCacheMode)cacheMode success:(void (^)(WDBGGattReadResult*))success failure:(void (^)(NSError*))failure;
- (void)writeValueAsync:(RTObject<WSSIBuffer>*)value success:(void (^)(WDBGGattCommunicationStatus))success failure:(void (^)(NSError*))failure;
- (void)writeValueWithOptionAsync:(RTObject<WSSIBuffer>*)value writeOption:(WDBGGattWriteOption)writeOption success:(void (^)(WDBGGattCommunicationStatus))success failure:(void (^)(NSError*))failure;
- (void)readClientCharacteristicConfigurationDescriptorAsyncWithSuccess:(void (^)(WDBGGattReadClientCharacteristicConfigurationDescriptorResult*))success failure:(void (^)(NSError*))failure;
- (void)writeClientCharacteristicConfigurationDescriptorAsync:(WDBGGattClientCharacteristicConfigurationDescriptorValue)clientCharacteristicConfigurationDescriptorValue success:(void (^)(WDBGGattCommunicationStatus))success failure:(void (^)(NSError*))failure;
- (NSArray* /* WDBGGattDescriptor* */)getAllDescriptors;
- (void)getDescriptorsAsyncWithSuccess:(void (^)(WDBGGattDescriptorsResult*))success failure:(void (^)(NSError*))failure;
- (void)getDescriptorsWithCacheModeAsync:(WDBBluetoothCacheMode)cacheMode success:(void (^)(WDBGGattDescriptorsResult*))success failure:(void (^)(NSError*))failure;
- (void)getDescriptorsForUuidAsync:(WFGUID*)descriptorUuid success:(void (^)(WDBGGattDescriptorsResult*))success failure:(void (^)(NSError*))failure;
- (void)getDescriptorsForUuidWithCacheModeAsync:(WFGUID*)descriptorUuid cacheMode:(WDBBluetoothCacheMode)cacheMode success:(void (^)(WDBGGattDescriptorsResult*))success failure:(void (^)(NSError*))failure;
- (void)writeValueWithResultAsync:(RTObject<WSSIBuffer>*)value success:(void (^)(WDBGGattWriteResult*))success failure:(void (^)(NSError*))failure;
- (void)writeValueWithResultAndOptionAsync:(RTObject<WSSIBuffer>*)value writeOption:(WDBGGattWriteOption)writeOption success:(void (^)(WDBGGattWriteResult*))success failure:(void (^)(NSError*))failure;
- (void)writeClientCharacteristicConfigurationDescriptorWithResultAsync:(WDBGGattClientCharacteristicConfigurationDescriptorValue)clientCharacteristicConfigurationDescriptorValue success:(void (^)(WDBGGattWriteResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDBGGattCharacteristic_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattCharacteristicsResult
#ifndef __WDBGGattCharacteristicsResult_DEFINED__
#define __WDBGGattCharacteristicsResult_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBGGattCharacteristicsResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WDBGGattCharacteristic* */ characteristics;
@property (readonly) id /* uint8_t */ protocolError;
@property (readonly) WDBGGattCommunicationStatus status;
@end

#endif // __WDBGGattCharacteristicsResult_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattDescriptor
#ifndef __WDBGGattDescriptor_DEFINED__
#define __WDBGGattDescriptor_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBGGattDescriptor : RTObject
+ (WFGUID*)convertShortIdToUuid:(unsigned short)shortId;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WDBGGattProtectionLevel protectionLevel;
@property (readonly) unsigned short attributeHandle;
@property (readonly) WFGUID* uuid;
- (void)readValueAsyncWithSuccess:(void (^)(WDBGGattReadResult*))success failure:(void (^)(NSError*))failure;
- (void)readValueWithCacheModeAsync:(WDBBluetoothCacheMode)cacheMode success:(void (^)(WDBGGattReadResult*))success failure:(void (^)(NSError*))failure;
- (void)writeValueAsync:(RTObject<WSSIBuffer>*)value success:(void (^)(WDBGGattCommunicationStatus))success failure:(void (^)(NSError*))failure;
- (void)writeValueWithResultAsync:(RTObject<WSSIBuffer>*)value success:(void (^)(WDBGGattWriteResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDBGGattDescriptor_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattPresentationFormat
#ifndef __WDBGGattPresentationFormat_DEFINED__
#define __WDBGGattPresentationFormat_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBGGattPresentationFormat : RTObject
+ (WDBGGattPresentationFormat*)fromParts:(uint8_t)formatType exponent:(int)exponent unit:(unsigned short)unit namespaceId:(uint8_t)namespaceId description:(unsigned short)description;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned short Description;
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

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBGGattReadResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDBGGattCommunicationStatus status;
@property (readonly) RTObject<WSSIBuffer>* value;
@property (readonly) id /* uint8_t */ protocolError;
@end

#endif // __WDBGGattReadResult_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattReadClientCharacteristicConfigurationDescriptorResult
#ifndef __WDBGGattReadClientCharacteristicConfigurationDescriptorResult_DEFINED__
#define __WDBGGattReadClientCharacteristicConfigurationDescriptorResult_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBGGattReadClientCharacteristicConfigurationDescriptorResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDBGGattClientCharacteristicConfigurationDescriptorValue clientCharacteristicConfigurationDescriptor;
@property (readonly) WDBGGattCommunicationStatus status;
@property (readonly) id /* uint8_t */ protocolError;
@end

#endif // __WDBGGattReadClientCharacteristicConfigurationDescriptorResult_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattValueChangedEventArgs
#ifndef __WDBGGattValueChangedEventArgs_DEFINED__
#define __WDBGGattValueChangedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBGGattValueChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) RTObject<WSSIBuffer>* characteristicValue;
@property (readonly) WFDateTime* timestamp;
@end

#endif // __WDBGGattValueChangedEventArgs_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattDescriptorsResult
#ifndef __WDBGGattDescriptorsResult_DEFINED__
#define __WDBGGattDescriptorsResult_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBGGattDescriptorsResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WDBGGattDescriptor* */ descriptors;
@property (readonly) id /* uint8_t */ protocolError;
@property (readonly) WDBGGattCommunicationStatus status;
@end

#endif // __WDBGGattDescriptorsResult_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattWriteResult
#ifndef __WDBGGattWriteResult_DEFINED__
#define __WDBGGattWriteResult_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBGGattWriteResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) id /* uint8_t */ protocolError;
@property (readonly) WDBGGattCommunicationStatus status;
@end

#endif // __WDBGGattWriteResult_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattPresentationFormatTypes
#ifndef __WDBGGattPresentationFormatTypes_DEFINED__
#define __WDBGGattPresentationFormatTypes_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
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

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattServiceUuids
#ifndef __WDBGGattServiceUuids_DEFINED__
#define __WDBGGattServiceUuids_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBGGattServiceUuids : RTObject
+ (WFGUID*)cyclingSpeedAndCadence;
+ (WFGUID*)battery;
+ (WFGUID*)bloodPressure;
+ (WFGUID*)genericAccess;
+ (WFGUID*)genericAttribute;
+ (WFGUID*)glucose;
+ (WFGUID*)healthThermometer;
+ (WFGUID*)heartRate;
+ (WFGUID*)runningSpeedAndCadence;
+ (WFGUID*)nextDstChange;
+ (WFGUID*)alertNotification;
+ (WFGUID*)currentTime;
+ (WFGUID*)cyclingPower;
+ (WFGUID*)deviceInformation;
+ (WFGUID*)humanInterfaceDevice;
+ (WFGUID*)immediateAlert;
+ (WFGUID*)linkLoss;
+ (WFGUID*)locationAndNavigation;
+ (WFGUID*)phoneAlertStatus;
+ (WFGUID*)referenceTimeUpdate;
+ (WFGUID*)scanParameters;
+ (WFGUID*)txPower;
@end

#endif // __WDBGGattServiceUuids_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattCharacteristicUuids
#ifndef __WDBGGattCharacteristicUuids_DEFINED__
#define __WDBGGattCharacteristicUuids_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
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
+ (WFGUID*)lnFeature;
+ (WFGUID*)alertCategoryId;
+ (WFGUID*)alertCategoryIdBitMask;
+ (WFGUID*)alertLevel;
+ (WFGUID*)alertNotificationControlPoint;
+ (WFGUID*)alertStatus;
+ (WFGUID*)bootKeyboardInputReport;
+ (WFGUID*)bootKeyboardOutputReport;
+ (WFGUID*)bootMouseInputReport;
+ (WFGUID*)currentTime;
+ (WFGUID*)cyclingPowerControlPoint;
+ (WFGUID*)cyclingPowerFeature;
+ (WFGUID*)cyclingPowerMeasurement;
+ (WFGUID*)cyclingPowerVector;
+ (WFGUID*)dateTime;
+ (WFGUID*)dayDateTime;
+ (WFGUID*)dayOfWeek;
+ (WFGUID*)dstOffset;
+ (WFGUID*)exactTime256;
+ (WFGUID*)firmwareRevisionString;
+ (WFGUID*)gapAppearance;
+ (WFGUID*)gapDeviceName;
+ (WFGUID*)gapPeripheralPreferredConnectionParameters;
+ (WFGUID*)gapPeripheralPrivacyFlag;
+ (WFGUID*)gapReconnectionAddress;
+ (WFGUID*)gattServiceChanged;
+ (WFGUID*)hardwareRevisionString;
+ (WFGUID*)hidControlPoint;
+ (WFGUID*)hidInformation;
+ (WFGUID*)ieee1107320601RegulatoryCertificationDataList;
+ (WFGUID*)lnControlPoint;
+ (WFGUID*)localTimeInformation;
+ (WFGUID*)locationAndSpeed;
+ (WFGUID*)manufacturerNameString;
+ (WFGUID*)modelNumberString;
+ (WFGUID*)navigation;
+ (WFGUID*)newAlert __attribute__ ((ns_returns_not_retained));
+ (WFGUID*)pnpId;
+ (WFGUID*)positionQuality;
+ (WFGUID*)protocolMode;
+ (WFGUID*)referenceTimeInformation;
+ (WFGUID*)report;
+ (WFGUID*)reportMap;
+ (WFGUID*)ringerControlPoint;
+ (WFGUID*)ringerSetting;
+ (WFGUID*)scanIntervalWindow;
+ (WFGUID*)scanRefresh;
+ (WFGUID*)serialNumberString;
+ (WFGUID*)softwareRevisionString;
+ (WFGUID*)supportUnreadAlertCategory;
+ (WFGUID*)supportedNewAlertCategory;
+ (WFGUID*)systemId;
+ (WFGUID*)timeAccuracy;
+ (WFGUID*)timeSource;
+ (WFGUID*)timeUpdateControlPoint;
+ (WFGUID*)timeUpdateState;
+ (WFGUID*)timeWithDst;
+ (WFGUID*)timeZone;
+ (WFGUID*)txPowerLevel;
+ (WFGUID*)unreadAlertStatus;
@end

#endif // __WDBGGattCharacteristicUuids_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattDescriptorUuids
#ifndef __WDBGGattDescriptorUuids_DEFINED__
#define __WDBGGattDescriptorUuids_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
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

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBGGattReliableWriteTransaction : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)writeValue:(WDBGGattCharacteristic*)characteristic value:(RTObject<WSSIBuffer>*)value;
- (void)commitAsyncWithSuccess:(void (^)(WDBGGattCommunicationStatus))success failure:(void (^)(NSError*))failure;
- (void)commitWithResultAsyncWithSuccess:(void (^)(WDBGGattWriteResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDBGGattReliableWriteTransaction_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattServiceProviderAdvertisingParameters
#ifndef __WDBGGattServiceProviderAdvertisingParameters_DEFINED__
#define __WDBGGattServiceProviderAdvertisingParameters_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBGGattServiceProviderAdvertisingParameters : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isDiscoverable;
@property BOOL isConnectable;
@end

#endif // __WDBGGattServiceProviderAdvertisingParameters_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattLocalCharacteristicParameters
#ifndef __WDBGGattLocalCharacteristicParameters_DEFINED__
#define __WDBGGattLocalCharacteristicParameters_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBGGattLocalCharacteristicParameters : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WDBGGattProtectionLevel writeProtectionLevel;
@property (retain) NSString * userDescription;
@property (retain) RTObject<WSSIBuffer>* staticValue;
@property WDBGGattProtectionLevel readProtectionLevel;
@property WDBGGattCharacteristicProperties characteristicProperties;
@property (readonly) NSMutableArray* /* WDBGGattPresentationFormat* */ presentationFormats;
@end

#endif // __WDBGGattLocalCharacteristicParameters_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattLocalDescriptorParameters
#ifndef __WDBGGattLocalDescriptorParameters_DEFINED__
#define __WDBGGattLocalDescriptorParameters_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBGGattLocalDescriptorParameters : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WDBGGattProtectionLevel writeProtectionLevel;
@property (retain) RTObject<WSSIBuffer>* staticValue;
@property WDBGGattProtectionLevel readProtectionLevel;
@end

#endif // __WDBGGattLocalDescriptorParameters_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattServiceProviderResult
#ifndef __WDBGGattServiceProviderResult_DEFINED__
#define __WDBGGattServiceProviderResult_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBGGattServiceProviderResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDBBluetoothError error;
@property (readonly) WDBGGattServiceProvider* serviceProvider;
@end

#endif // __WDBGGattServiceProviderResult_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattLocalService
#ifndef __WDBGGattLocalService_DEFINED__
#define __WDBGGattLocalService_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBGGattLocalService : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WDBGGattLocalCharacteristic* */ characteristics;
@property (readonly) WFGUID* uuid;
- (void)createCharacteristicAsync:(WFGUID*)characteristicUuid parameters:(WDBGGattLocalCharacteristicParameters*)parameters success:(void (^)(WDBGGattLocalCharacteristicResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDBGGattLocalService_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattServiceProvider
#ifndef __WDBGGattServiceProvider_DEFINED__
#define __WDBGGattServiceProvider_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBGGattServiceProvider : RTObject
+ (void)createAsync:(WFGUID*)serviceUuid success:(void (^)(WDBGGattServiceProviderResult*))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDBGGattServiceProviderAdvertisementStatus advertisementStatus;
@property (readonly) WDBGGattLocalService* service;
- (EventRegistrationToken)addAdvertisementStatusChangedEvent:(void(^)(WDBGGattServiceProvider*, WDBGGattServiceProviderAdvertisementStatusChangedEventArgs*))del;
- (void)removeAdvertisementStatusChangedEvent:(EventRegistrationToken)tok;
- (void)startAdvertising;
- (void)startAdvertisingWithParameters:(WDBGGattServiceProviderAdvertisingParameters*)parameters;
- (void)stopAdvertising;
@end

#endif // __WDBGGattServiceProvider_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattServiceProviderAdvertisementStatusChangedEventArgs
#ifndef __WDBGGattServiceProviderAdvertisementStatusChangedEventArgs_DEFINED__
#define __WDBGGattServiceProviderAdvertisementStatusChangedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBGGattServiceProviderAdvertisementStatusChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDBBluetoothError error;
@property (readonly) WDBGGattServiceProviderAdvertisementStatus status;
@end

#endif // __WDBGGattServiceProviderAdvertisementStatusChangedEventArgs_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattLocalCharacteristicResult
#ifndef __WDBGGattLocalCharacteristicResult_DEFINED__
#define __WDBGGattLocalCharacteristicResult_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBGGattLocalCharacteristicResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDBGGattLocalCharacteristic* characteristic;
@property (readonly) WDBBluetoothError error;
@end

#endif // __WDBGGattLocalCharacteristicResult_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattLocalCharacteristic
#ifndef __WDBGGattLocalCharacteristic_DEFINED__
#define __WDBGGattLocalCharacteristic_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBGGattLocalCharacteristic : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDBGGattCharacteristicProperties characteristicProperties;
@property (readonly) NSArray* /* WDBGGattLocalDescriptor* */ descriptors;
@property (readonly) NSArray* /* WDBGGattPresentationFormat* */ presentationFormats;
@property (readonly) WDBGGattProtectionLevel readProtectionLevel;
@property (readonly) RTObject<WSSIBuffer>* staticValue;
@property (readonly) NSArray* /* WDBGGattSubscribedClient* */ subscribedClients;
@property (readonly) NSString * userDescription;
@property (readonly) WFGUID* uuid;
@property (readonly) WDBGGattProtectionLevel writeProtectionLevel;
- (EventRegistrationToken)addReadRequestedEvent:(void(^)(WDBGGattLocalCharacteristic*, WDBGGattReadRequestedEventArgs*))del;
- (void)removeReadRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSubscribedClientsChangedEvent:(void(^)(WDBGGattLocalCharacteristic*, RTObject*))del;
- (void)removeSubscribedClientsChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addWriteRequestedEvent:(void(^)(WDBGGattLocalCharacteristic*, WDBGGattWriteRequestedEventArgs*))del;
- (void)removeWriteRequestedEvent:(EventRegistrationToken)tok;
- (void)createDescriptorAsync:(WFGUID*)descriptorUuid parameters:(WDBGGattLocalDescriptorParameters*)parameters success:(void (^)(WDBGGattLocalDescriptorResult*))success failure:(void (^)(NSError*))failure;
- (void)notifyValueAsync:(RTObject<WSSIBuffer>*)value success:(void (^)(NSArray* /* WDBGGattClientNotificationResult* */))success failure:(void (^)(NSError*))failure;
- (void)notifyValueForSubscribedClientAsync:(RTObject<WSSIBuffer>*)value subscribedClient:(WDBGGattSubscribedClient*)subscribedClient success:(void (^)(WDBGGattClientNotificationResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDBGGattLocalCharacteristic_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattLocalDescriptorResult
#ifndef __WDBGGattLocalDescriptorResult_DEFINED__
#define __WDBGGattLocalDescriptorResult_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBGGattLocalDescriptorResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDBGGattLocalDescriptor* descriptor;
@property (readonly) WDBBluetoothError error;
@end

#endif // __WDBGGattLocalDescriptorResult_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattLocalDescriptor
#ifndef __WDBGGattLocalDescriptor_DEFINED__
#define __WDBGGattLocalDescriptor_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBGGattLocalDescriptor : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDBGGattProtectionLevel readProtectionLevel;
@property (readonly) RTObject<WSSIBuffer>* staticValue;
@property (readonly) WFGUID* uuid;
@property (readonly) WDBGGattProtectionLevel writeProtectionLevel;
- (EventRegistrationToken)addReadRequestedEvent:(void(^)(WDBGGattLocalDescriptor*, WDBGGattReadRequestedEventArgs*))del;
- (void)removeReadRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addWriteRequestedEvent:(void(^)(WDBGGattLocalDescriptor*, WDBGGattWriteRequestedEventArgs*))del;
- (void)removeWriteRequestedEvent:(EventRegistrationToken)tok;
@end

#endif // __WDBGGattLocalDescriptor_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattSubscribedClient
#ifndef __WDBGGattSubscribedClient_DEFINED__
#define __WDBGGattSubscribedClient_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBGGattSubscribedClient : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned short maxNotificationSize;
@property (readonly) WDBGGattSession* session;
- (EventRegistrationToken)addMaxNotificationSizeChangedEvent:(void(^)(WDBGGattSubscribedClient*, RTObject*))del;
- (void)removeMaxNotificationSizeChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WDBGGattSubscribedClient_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattReadRequestedEventArgs
#ifndef __WDBGGattReadRequestedEventArgs_DEFINED__
#define __WDBGGattReadRequestedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBGGattReadRequestedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDBGGattSession* session;
- (WFDeferral*)getDeferral;
- (void)getRequestAsyncWithSuccess:(void (^)(WDBGGattReadRequest*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDBGGattReadRequestedEventArgs_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattWriteRequestedEventArgs
#ifndef __WDBGGattWriteRequestedEventArgs_DEFINED__
#define __WDBGGattWriteRequestedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBGGattWriteRequestedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDBGGattSession* session;
- (WFDeferral*)getDeferral;
- (void)getRequestAsyncWithSuccess:(void (^)(WDBGGattWriteRequest*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDBGGattWriteRequestedEventArgs_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattClientNotificationResult
#ifndef __WDBGGattClientNotificationResult_DEFINED__
#define __WDBGGattClientNotificationResult_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBGGattClientNotificationResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) id /* uint8_t */ protocolError;
@property (readonly) WDBGGattCommunicationStatus status;
@property (readonly) WDBGGattSubscribedClient* subscribedClient;
@property (readonly) unsigned short bytesSent;
@end

#endif // __WDBGGattClientNotificationResult_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattReadRequest
#ifndef __WDBGGattReadRequest_DEFINED__
#define __WDBGGattReadRequest_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBGGattReadRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int length;
@property (readonly) unsigned int offset;
@property (readonly) WDBGGattRequestState state;
- (EventRegistrationToken)addStateChangedEvent:(void(^)(WDBGGattReadRequest*, WDBGGattRequestStateChangedEventArgs*))del;
- (void)removeStateChangedEvent:(EventRegistrationToken)tok;
- (void)respondWithValue:(RTObject<WSSIBuffer>*)value;
- (void)respondWithProtocolError:(uint8_t)protocolError;
@end

#endif // __WDBGGattReadRequest_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattRequestStateChangedEventArgs
#ifndef __WDBGGattRequestStateChangedEventArgs_DEFINED__
#define __WDBGGattRequestStateChangedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBGGattRequestStateChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDBBluetoothError error;
@property (readonly) WDBGGattRequestState state;
@end

#endif // __WDBGGattRequestStateChangedEventArgs_DEFINED__

// Windows.Devices.Bluetooth.GenericAttributeProfile.GattWriteRequest
#ifndef __WDBGGattWriteRequest_DEFINED__
#define __WDBGGattWriteRequest_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBGGattWriteRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int offset;
@property (readonly) WDBGGattWriteOption option;
@property (readonly) WDBGGattRequestState state;
@property (readonly) RTObject<WSSIBuffer>* value;
- (EventRegistrationToken)addStateChangedEvent:(void(^)(WDBGGattWriteRequest*, WDBGGattRequestStateChangedEventArgs*))del;
- (void)removeStateChangedEvent:(EventRegistrationToken)tok;
- (void)respond;
- (void)respondWithProtocolError:(uint8_t)protocolError;
@end

#endif // __WDBGGattWriteRequest_DEFINED__

