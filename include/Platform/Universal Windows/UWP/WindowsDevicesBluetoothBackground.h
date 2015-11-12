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

#include "interopBase.h"
@class WDBBRfcommInboundConnectionInformation, WDBBRfcommOutboundConnectionInformation, WDBBRfcommConnectionTriggerDetails,
    WDBBGattCharacteristicNotificationTriggerDetails, WDBBBluetoothLEAdvertisementWatcherTriggerDetails,
    WDBBBluetoothLEAdvertisementPublisherTriggerDetails;
@protocol WDBBIRfcommInboundConnectionInformation
, WDBBIRfcommOutboundConnectionInformation, WDBBIRfcommConnectionTriggerDetails, WDBBIGattCharacteristicNotificationTriggerDetails,
    WDBBIBluetoothLEAdvertisementWatcherTriggerDetails, WDBBIBluetoothLEAdvertisementPublisherTriggerDetails;

#include "WindowsDevicesBluetoothGenericAttributeProfile.h"
#include "WindowsDevicesBluetooth.h"
#include "WindowsDevicesBluetoothAdvertisement.h"
#include "WindowsFoundationCollections.h"
#include "WindowsStorageStreams.h"
#include "WindowsDevicesBluetoothRfcomm.h"
#include "WindowsNetworkingSockets.h"

#import <Foundation/Foundation.h>

// Windows.Devices.Bluetooth.Background.RfcommInboundConnectionInformation
#ifndef __WDBBRfcommInboundConnectionInformation_DEFINED__
#define __WDBBRfcommInboundConnectionInformation_DEFINED__

WINRT_EXPORT
@interface WDBBRfcommInboundConnectionInformation : RTObject
@property WDBBluetoothServiceCapabilities serviceCapabilities;
@property (copy) RTObject<WSSIBuffer>* sdpRecord;
@property (copy) WDBRRfcommServiceId* localServiceId;
@end

#endif // __WDBBRfcommInboundConnectionInformation_DEFINED__

// Windows.Devices.Bluetooth.Background.RfcommOutboundConnectionInformation
#ifndef __WDBBRfcommOutboundConnectionInformation_DEFINED__
#define __WDBBRfcommOutboundConnectionInformation_DEFINED__

WINRT_EXPORT
@interface WDBBRfcommOutboundConnectionInformation : RTObject
@property (copy) WDBRRfcommServiceId* remoteServiceId;
@end

#endif // __WDBBRfcommOutboundConnectionInformation_DEFINED__

// Windows.Devices.Bluetooth.Background.RfcommConnectionTriggerDetails
#ifndef __WDBBRfcommConnectionTriggerDetails_DEFINED__
#define __WDBBRfcommConnectionTriggerDetails_DEFINED__

WINRT_EXPORT
@interface WDBBRfcommConnectionTriggerDetails : RTObject
@property (readonly) BOOL incoming;
@property (readonly) WDBBluetoothDevice* remoteDevice;
@property (readonly) WNSStreamSocket* socket;
@end

#endif // __WDBBRfcommConnectionTriggerDetails_DEFINED__

// Windows.Devices.Bluetooth.Background.GattCharacteristicNotificationTriggerDetails
#ifndef __WDBBGattCharacteristicNotificationTriggerDetails_DEFINED__
#define __WDBBGattCharacteristicNotificationTriggerDetails_DEFINED__

WINRT_EXPORT
@interface WDBBGattCharacteristicNotificationTriggerDetails : RTObject
@property (readonly) WDBGGattCharacteristic* characteristic;
@property (readonly) RTObject<WSSIBuffer>* value;
@end

#endif // __WDBBGattCharacteristicNotificationTriggerDetails_DEFINED__

// Windows.Devices.Bluetooth.Background.BluetoothLEAdvertisementWatcherTriggerDetails
#ifndef __WDBBBluetoothLEAdvertisementWatcherTriggerDetails_DEFINED__
#define __WDBBBluetoothLEAdvertisementWatcherTriggerDetails_DEFINED__

WINRT_EXPORT
@interface WDBBBluetoothLEAdvertisementWatcherTriggerDetails : RTObject
@property (readonly) NSArray* advertisements;
@property (readonly) WDBBluetoothError error;
@property (readonly) WDBBluetoothSignalStrengthFilter* signalStrengthFilter;
@end

#endif // __WDBBBluetoothLEAdvertisementWatcherTriggerDetails_DEFINED__

// Windows.Devices.Bluetooth.Background.BluetoothLEAdvertisementPublisherTriggerDetails
#ifndef __WDBBBluetoothLEAdvertisementPublisherTriggerDetails_DEFINED__
#define __WDBBBluetoothLEAdvertisementPublisherTriggerDetails_DEFINED__

WINRT_EXPORT
@interface WDBBBluetoothLEAdvertisementPublisherTriggerDetails : RTObject
@property (readonly) WDBBluetoothError error;
@property (readonly) WDBABluetoothLEAdvertisementPublisherStatus status;
@end

#endif // __WDBBBluetoothLEAdvertisementPublisherTriggerDetails_DEFINED__
