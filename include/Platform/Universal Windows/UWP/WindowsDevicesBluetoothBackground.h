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

// WindowsDevicesBluetoothBackground.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
#define OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsConsolidatedNamespace.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WDBBRfcommInboundConnectionInformation, WDBBRfcommOutboundConnectionInformation, WDBBRfcommConnectionTriggerDetails, WDBBGattCharacteristicNotificationTriggerDetails, WDBBGattServiceProviderConnection, WDBBGattServiceProviderTriggerDetails, WDBBBluetoothLEAdvertisementWatcherTriggerDetails, WDBBBluetoothLEAdvertisementPublisherTriggerDetails;
@protocol WDBBIRfcommInboundConnectionInformation, WDBBIRfcommOutboundConnectionInformation, WDBBIRfcommConnectionTriggerDetails, WDBBIGattCharacteristicNotificationTriggerDetails, WDBBIGattCharacteristicNotificationTriggerDetails2, WDBBIGattServiceProviderConnectionStatics, WDBBIGattServiceProviderConnection, WDBBIGattServiceProviderTriggerDetails, WDBBIBluetoothLEAdvertisementWatcherTriggerDetails, WDBBIBluetoothLEAdvertisementPublisherTriggerDetails;

// Windows.Devices.Bluetooth.Background.BluetoothEventTriggeringMode
enum _WDBBBluetoothEventTriggeringMode {
    WDBBBluetoothEventTriggeringModeSerial = 0,
    WDBBBluetoothEventTriggeringModeBatch = 1,
    WDBBBluetoothEventTriggeringModeKeepLatest = 2,
};
typedef unsigned WDBBBluetoothEventTriggeringMode;

#include "WindowsDevicesBluetoothGenericAttributeProfile.h"
#include "WindowsDevicesBluetooth.h"
#include "WindowsDevicesBluetoothAdvertisement.h"
#include "WindowsStorageStreams.h"
#include "WindowsDevicesBluetoothRfcomm.h"
#include "WindowsNetworkingSockets.h"

#import <Foundation/Foundation.h>

// Windows.Devices.Bluetooth.Background.RfcommInboundConnectionInformation
#ifndef __WDBBRfcommInboundConnectionInformation_DEFINED__
#define __WDBBRfcommInboundConnectionInformation_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBBRfcommInboundConnectionInformation : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WDBBluetoothServiceCapabilities serviceCapabilities;
@property (retain) RTObject<WSSIBuffer>* sdpRecord;
@property (retain) WDBRRfcommServiceId* localServiceId;
@end

#endif // __WDBBRfcommInboundConnectionInformation_DEFINED__

// Windows.Devices.Bluetooth.Background.RfcommOutboundConnectionInformation
#ifndef __WDBBRfcommOutboundConnectionInformation_DEFINED__
#define __WDBBRfcommOutboundConnectionInformation_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBBRfcommOutboundConnectionInformation : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WDBRRfcommServiceId* remoteServiceId;
@end

#endif // __WDBBRfcommOutboundConnectionInformation_DEFINED__

// Windows.Devices.Bluetooth.Background.RfcommConnectionTriggerDetails
#ifndef __WDBBRfcommConnectionTriggerDetails_DEFINED__
#define __WDBBRfcommConnectionTriggerDetails_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBBRfcommConnectionTriggerDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL incoming;
@property (readonly) WDBBluetoothDevice* remoteDevice;
@property (readonly) WNSStreamSocket* socket;
@end

#endif // __WDBBRfcommConnectionTriggerDetails_DEFINED__

// Windows.Devices.Bluetooth.Background.GattCharacteristicNotificationTriggerDetails
#ifndef __WDBBGattCharacteristicNotificationTriggerDetails_DEFINED__
#define __WDBBGattCharacteristicNotificationTriggerDetails_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBBGattCharacteristicNotificationTriggerDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDBGGattCharacteristic* characteristic;
@property (readonly) RTObject<WSSIBuffer>* value;
@property (readonly) WDBBluetoothError error;
@property (readonly) WDBBBluetoothEventTriggeringMode eventTriggeringMode;
@property (readonly) NSArray* /* WDBGGattValueChangedEventArgs* */ valueChangedEvents;
@end

#endif // __WDBBGattCharacteristicNotificationTriggerDetails_DEFINED__

// Windows.Devices.Bluetooth.Background.GattServiceProviderConnection
#ifndef __WDBBGattServiceProviderConnection_DEFINED__
#define __WDBBGattServiceProviderConnection_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBBGattServiceProviderConnection : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDBGGattLocalService* service;
@property (readonly) NSString * triggerId;
+ (NSDictionary* /* NSString *, WDBBGattServiceProviderConnection* */)allServices;
- (void)start;
@end

#endif // __WDBBGattServiceProviderConnection_DEFINED__

// Windows.Devices.Bluetooth.Background.GattServiceProviderTriggerDetails
#ifndef __WDBBGattServiceProviderTriggerDetails_DEFINED__
#define __WDBBGattServiceProviderTriggerDetails_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBBGattServiceProviderTriggerDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDBBGattServiceProviderConnection* connection;
@end

#endif // __WDBBGattServiceProviderTriggerDetails_DEFINED__

// Windows.Devices.Bluetooth.Background.BluetoothLEAdvertisementWatcherTriggerDetails
#ifndef __WDBBBluetoothLEAdvertisementWatcherTriggerDetails_DEFINED__
#define __WDBBBluetoothLEAdvertisementWatcherTriggerDetails_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBBBluetoothLEAdvertisementWatcherTriggerDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WDBABluetoothLEAdvertisementReceivedEventArgs* */ advertisements;
@property (readonly) WDBBluetoothError error;
@property (readonly) WDBBluetoothSignalStrengthFilter* signalStrengthFilter;
@end

#endif // __WDBBBluetoothLEAdvertisementWatcherTriggerDetails_DEFINED__

// Windows.Devices.Bluetooth.Background.BluetoothLEAdvertisementPublisherTriggerDetails
#ifndef __WDBBBluetoothLEAdvertisementPublisherTriggerDetails_DEFINED__
#define __WDBBBluetoothLEAdvertisementPublisherTriggerDetails_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBBBluetoothLEAdvertisementPublisherTriggerDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDBBluetoothError error;
@property (readonly) WDBABluetoothLEAdvertisementPublisherStatus status;
@end

#endif // __WDBBBluetoothLEAdvertisementPublisherTriggerDetails_DEFINED__

