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

// WindowsDevicesBluetoothBackground.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_DEVICES_BLUETOOTH_BACKGROUND_EXPORT
#define OBJCUWP_WINDOWS_DEVICES_BLUETOOTH_BACKGROUND_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_Devices_Bluetooth_Background.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WDBBRfcommInboundConnectionInformation, WDBBRfcommOutboundConnectionInformation, WDBBRfcommConnectionTriggerDetails,
    WDBBGattCharacteristicNotificationTriggerDetails, WDBBBluetoothLEAdvertisementWatcherTriggerDetails,
    WDBBBluetoothLEAdvertisementPublisherTriggerDetails;
@protocol WDBBIRfcommInboundConnectionInformation
, WDBBIRfcommOutboundConnectionInformation, WDBBIRfcommConnectionTriggerDetails, WDBBIGattCharacteristicNotificationTriggerDetails,
    WDBBIBluetoothLEAdvertisementWatcherTriggerDetails, WDBBIBluetoothLEAdvertisementPublisherTriggerDetails;

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

OBJCUWP_WINDOWS_DEVICES_BLUETOOTH_BACKGROUND_EXPORT
@interface WDBBRfcommInboundConnectionInformation : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property WDBBluetoothServiceCapabilities serviceCapabilities;
@property (retain) RTObject<WSSIBuffer>* sdpRecord;
@property (retain) WDBRRfcommServiceId* localServiceId;
@end

#endif // __WDBBRfcommInboundConnectionInformation_DEFINED__

// Windows.Devices.Bluetooth.Background.RfcommOutboundConnectionInformation
#ifndef __WDBBRfcommOutboundConnectionInformation_DEFINED__
#define __WDBBRfcommOutboundConnectionInformation_DEFINED__

OBJCUWP_WINDOWS_DEVICES_BLUETOOTH_BACKGROUND_EXPORT
@interface WDBBRfcommOutboundConnectionInformation : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (retain) WDBRRfcommServiceId* remoteServiceId;
@end

#endif // __WDBBRfcommOutboundConnectionInformation_DEFINED__

// Windows.Devices.Bluetooth.Background.RfcommConnectionTriggerDetails
#ifndef __WDBBRfcommConnectionTriggerDetails_DEFINED__
#define __WDBBRfcommConnectionTriggerDetails_DEFINED__

OBJCUWP_WINDOWS_DEVICES_BLUETOOTH_BACKGROUND_EXPORT
@interface WDBBRfcommConnectionTriggerDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) BOOL incoming;
@property (readonly) WDBBluetoothDevice* remoteDevice;
@property (readonly) WNSStreamSocket* socket;
@end

#endif // __WDBBRfcommConnectionTriggerDetails_DEFINED__

// Windows.Devices.Bluetooth.Background.GattCharacteristicNotificationTriggerDetails
#ifndef __WDBBGattCharacteristicNotificationTriggerDetails_DEFINED__
#define __WDBBGattCharacteristicNotificationTriggerDetails_DEFINED__

OBJCUWP_WINDOWS_DEVICES_BLUETOOTH_BACKGROUND_EXPORT
@interface WDBBGattCharacteristicNotificationTriggerDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WDBGGattCharacteristic* characteristic;
@property (readonly) RTObject<WSSIBuffer>* value;
@end

#endif // __WDBBGattCharacteristicNotificationTriggerDetails_DEFINED__

// Windows.Devices.Bluetooth.Background.BluetoothLEAdvertisementWatcherTriggerDetails
#ifndef __WDBBBluetoothLEAdvertisementWatcherTriggerDetails_DEFINED__
#define __WDBBBluetoothLEAdvertisementWatcherTriggerDetails_DEFINED__

OBJCUWP_WINDOWS_DEVICES_BLUETOOTH_BACKGROUND_EXPORT
@interface WDBBBluetoothLEAdvertisementWatcherTriggerDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) NSArray* /* WDBABluetoothLEAdvertisementReceivedEventArgs* */ advertisements;
@property (readonly) WDBBluetoothError error;
@property (readonly) WDBBluetoothSignalStrengthFilter* signalStrengthFilter;
@end

#endif // __WDBBBluetoothLEAdvertisementWatcherTriggerDetails_DEFINED__

// Windows.Devices.Bluetooth.Background.BluetoothLEAdvertisementPublisherTriggerDetails
#ifndef __WDBBBluetoothLEAdvertisementPublisherTriggerDetails_DEFINED__
#define __WDBBBluetoothLEAdvertisementPublisherTriggerDetails_DEFINED__

OBJCUWP_WINDOWS_DEVICES_BLUETOOTH_BACKGROUND_EXPORT
@interface WDBBBluetoothLEAdvertisementPublisherTriggerDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WDBBluetoothError error;
@property (readonly) WDBABluetoothLEAdvertisementPublisherStatus status;
@end

#endif // __WDBBBluetoothLEAdvertisementPublisherTriggerDetails_DEFINED__
