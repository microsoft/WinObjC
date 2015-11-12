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

// WindowsDevicesBluetoothAdvertisement.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WDBABluetoothLEManufacturerData, WDBABluetoothLEAdvertisementDataSection, WDBABluetoothLEAdvertisement,
    WDBABluetoothLEAdvertisementBytePattern, WDBABluetoothLEAdvertisementFilter, WDBABluetoothLEAdvertisementWatcherStoppedEventArgs,
    WDBABluetoothLEAdvertisementWatcher, WDBABluetoothLEAdvertisementReceivedEventArgs, WDBABluetoothLEAdvertisementDataTypes,
    WDBABluetoothLEAdvertisementPublisherStatusChangedEventArgs, WDBABluetoothLEAdvertisementPublisher;
@protocol WDBAIBluetoothLEAdvertisement
, WDBAIBluetoothLEAdvertisementFilter, WDBAIBluetoothLEAdvertisementWatcherStoppedEventArgs, WDBAIBluetoothLEAdvertisementWatcherFactory,
    WDBAIBluetoothLEAdvertisementWatcher, WDBAIBluetoothLEAdvertisementReceivedEventArgs, WDBAIBluetoothLEAdvertisementDataSectionFactory,
    WDBAIBluetoothLEAdvertisementDataSection, WDBAIBluetoothLEManufacturerDataFactory, WDBAIBluetoothLEManufacturerData,
    WDBAIBluetoothLEAdvertisementBytePatternFactory, WDBAIBluetoothLEAdvertisementBytePattern,
    WDBAIBluetoothLEAdvertisementDataTypesStatics, WDBAIBluetoothLEAdvertisementPublisherStatusChangedEventArgs,
    WDBAIBluetoothLEAdvertisementPublisherFactory, WDBAIBluetoothLEAdvertisementPublisher;

// Windows.Devices.Bluetooth.Advertisement.BluetoothLEScanningMode
enum _WDBABluetoothLEScanningMode {
    WDBABluetoothLEScanningModePassive = 0,
    WDBABluetoothLEScanningModeActive = 1,
};
typedef unsigned WDBABluetoothLEScanningMode;

// Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementFlags
enum _WDBABluetoothLEAdvertisementFlags {
    WDBABluetoothLEAdvertisementFlagsNone = 0,
    WDBABluetoothLEAdvertisementFlagsLimitedDiscoverableMode = 1,
    WDBABluetoothLEAdvertisementFlagsGeneralDiscoverableMode = 2,
    WDBABluetoothLEAdvertisementFlagsClassicNotSupported = 4,
    WDBABluetoothLEAdvertisementFlagsDualModeControllerCapable = 8,
    WDBABluetoothLEAdvertisementFlagsDualModeHostCapable = 16,
};
typedef unsigned WDBABluetoothLEAdvertisementFlags;

// Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementType
enum _WDBABluetoothLEAdvertisementType {
    WDBABluetoothLEAdvertisementTypeConnectableUndirected = 0,
    WDBABluetoothLEAdvertisementTypeConnectableDirected = 1,
    WDBABluetoothLEAdvertisementTypeScannableUndirected = 2,
    WDBABluetoothLEAdvertisementTypeNonConnectableUndirected = 3,
    WDBABluetoothLEAdvertisementTypeScanResponse = 4,
};
typedef unsigned WDBABluetoothLEAdvertisementType;

// Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementWatcherStatus
enum _WDBABluetoothLEAdvertisementWatcherStatus {
    WDBABluetoothLEAdvertisementWatcherStatusCreated = 0,
    WDBABluetoothLEAdvertisementWatcherStatusStarted = 1,
    WDBABluetoothLEAdvertisementWatcherStatusStopping = 2,
    WDBABluetoothLEAdvertisementWatcherStatusStopped = 3,
    WDBABluetoothLEAdvertisementWatcherStatusAborted = 4,
};
typedef unsigned WDBABluetoothLEAdvertisementWatcherStatus;

// Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementPublisherStatus
enum _WDBABluetoothLEAdvertisementPublisherStatus {
    WDBABluetoothLEAdvertisementPublisherStatusCreated = 0,
    WDBABluetoothLEAdvertisementPublisherStatusWaiting = 1,
    WDBABluetoothLEAdvertisementPublisherStatusStarted = 2,
    WDBABluetoothLEAdvertisementPublisherStatusStopping = 3,
    WDBABluetoothLEAdvertisementPublisherStatusStopped = 4,
    WDBABluetoothLEAdvertisementPublisherStatusAborted = 5,
};
typedef unsigned WDBABluetoothLEAdvertisementPublisherStatus;

#include "WindowsStorageStreams.h"
#include "WindowsFoundationCollections.h"
#include "WindowsDevicesBluetooth.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Devices.Bluetooth.Advertisement.BluetoothLEManufacturerData
#ifndef __WDBABluetoothLEManufacturerData_DEFINED__
#define __WDBABluetoothLEManufacturerData_DEFINED__

WINRT_EXPORT
@interface WDBABluetoothLEManufacturerData : RTObject
+ (WDBABluetoothLEManufacturerData*)create:(unsigned short)companyId data:(RTObject<WSSIBuffer>*)data ACTIVATOR;
+ (instancetype)create ACTIVATOR;
@property (copy) RTObject<WSSIBuffer>* data;
@property unsigned short companyId;
@end

#endif // __WDBABluetoothLEManufacturerData_DEFINED__

// Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementDataSection
#ifndef __WDBABluetoothLEAdvertisementDataSection_DEFINED__
#define __WDBABluetoothLEAdvertisementDataSection_DEFINED__

WINRT_EXPORT
@interface WDBABluetoothLEAdvertisementDataSection : RTObject
+ (WDBABluetoothLEAdvertisementDataSection*)create:(uint8_t)dataType data:(RTObject<WSSIBuffer>*)data ACTIVATOR;
+ (instancetype)create ACTIVATOR;
@property uint8_t dataType;
@property (copy) RTObject<WSSIBuffer>* data;
@end

#endif // __WDBABluetoothLEAdvertisementDataSection_DEFINED__

// Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisement
#ifndef __WDBABluetoothLEAdvertisement_DEFINED__
#define __WDBABluetoothLEAdvertisement_DEFINED__

WINRT_EXPORT
@interface WDBABluetoothLEAdvertisement : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* localName;
@property (copy) id flags;
@property (readonly) NSMutableArray* dataSections;
@property (readonly) NSMutableArray* manufacturerData;
@property (readonly) NSMutableArray* serviceUuids;
- (NSArray*)getManufacturerDataByCompanyId:(unsigned short)companyId;
- (NSArray*)getSectionsByType:(uint8_t)type;
@end

#endif // __WDBABluetoothLEAdvertisement_DEFINED__

// Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementBytePattern
#ifndef __WDBABluetoothLEAdvertisementBytePattern_DEFINED__
#define __WDBABluetoothLEAdvertisementBytePattern_DEFINED__

WINRT_EXPORT
@interface WDBABluetoothLEAdvertisementBytePattern : RTObject
+ (WDBABluetoothLEAdvertisementBytePattern*)create:(uint8_t)dataType offset:(int16_t)offset data:(RTObject<WSSIBuffer>*)data ACTIVATOR;
+ (instancetype)create ACTIVATOR;
@property int16_t offset;
@property uint8_t dataType;
@property (copy) RTObject<WSSIBuffer>* data;
@end

#endif // __WDBABluetoothLEAdvertisementBytePattern_DEFINED__

// Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementFilter
#ifndef __WDBABluetoothLEAdvertisementFilter_DEFINED__
#define __WDBABluetoothLEAdvertisementFilter_DEFINED__

WINRT_EXPORT
@interface WDBABluetoothLEAdvertisementFilter : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) WDBABluetoothLEAdvertisement* advertisement;
@property (readonly) NSMutableArray* bytePatterns;
@end

#endif // __WDBABluetoothLEAdvertisementFilter_DEFINED__

// Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementWatcherStoppedEventArgs
#ifndef __WDBABluetoothLEAdvertisementWatcherStoppedEventArgs_DEFINED__
#define __WDBABluetoothLEAdvertisementWatcherStoppedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDBABluetoothLEAdvertisementWatcherStoppedEventArgs : RTObject
@property (readonly) WDBBluetoothError error;
@end

#endif // __WDBABluetoothLEAdvertisementWatcherStoppedEventArgs_DEFINED__

// Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementWatcher
#ifndef __WDBABluetoothLEAdvertisementWatcher_DEFINED__
#define __WDBABluetoothLEAdvertisementWatcher_DEFINED__

WINRT_EXPORT
@interface WDBABluetoothLEAdvertisementWatcher : RTObject
+ (instancetype)create ACTIVATOR;
+ (WDBABluetoothLEAdvertisementWatcher*)create:(WDBABluetoothLEAdvertisementFilter*)advertisementFilter ACTIVATOR;
@property (copy) WDBBluetoothSignalStrengthFilter* signalStrengthFilter;
@property WDBABluetoothLEScanningMode scanningMode;
@property (copy) WDBABluetoothLEAdvertisementFilter* advertisementFilter;
@property (readonly) WFTimeSpan* maxOutOfRangeTimeout;
@property (readonly) WFTimeSpan* maxSamplingInterval;
@property (readonly) WFTimeSpan* minOutOfRangeTimeout;
@property (readonly) WFTimeSpan* minSamplingInterval;
@property (readonly) WDBABluetoothLEAdvertisementWatcherStatus status;
- (EventRegistrationToken)addReceivedEvent:(void (^)(WDBABluetoothLEAdvertisementWatcher*,
                                                     WDBABluetoothLEAdvertisementReceivedEventArgs*))del;
- (void)removeReceivedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStoppedEvent:(void (^)(WDBABluetoothLEAdvertisementWatcher*,
                                                    WDBABluetoothLEAdvertisementWatcherStoppedEventArgs*))del;
- (void)removeStoppedEvent:(EventRegistrationToken)tok;
- (void)start;
- (void)stop;
@end

#endif // __WDBABluetoothLEAdvertisementWatcher_DEFINED__

// Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementReceivedEventArgs
#ifndef __WDBABluetoothLEAdvertisementReceivedEventArgs_DEFINED__
#define __WDBABluetoothLEAdvertisementReceivedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDBABluetoothLEAdvertisementReceivedEventArgs : RTObject
@property (readonly) WDBABluetoothLEAdvertisement* advertisement;
@property (readonly) WDBABluetoothLEAdvertisementType advertisementType;
@property (readonly) uint64_t bluetoothAddress;
@property (readonly) int16_t rawSignalStrengthInDBm;
@property (readonly) WFDateTime* timestamp;
@end

#endif // __WDBABluetoothLEAdvertisementReceivedEventArgs_DEFINED__

// Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementDataTypes
#ifndef __WDBABluetoothLEAdvertisementDataTypes_DEFINED__
#define __WDBABluetoothLEAdvertisementDataTypes_DEFINED__

WINRT_EXPORT
@interface WDBABluetoothLEAdvertisementDataTypes : RTObject
+ (uint8_t)advertisingInterval;
+ (uint8_t)appearance;
+ (uint8_t)completeLocalName;
+ (uint8_t)completeService128BitUuids;
+ (uint8_t)completeService16BitUuids;
+ (uint8_t)completeService32BitUuids;
+ (uint8_t)flags;
+ (uint8_t)incompleteService128BitUuids;
+ (uint8_t)incompleteService16BitUuids;
+ (uint8_t)incompleteService32BitUuids;
+ (uint8_t)manufacturerSpecificData;
+ (uint8_t)publicTargetAddress;
+ (uint8_t)randomTargetAddress;
+ (uint8_t)serviceData128BitUuids;
+ (uint8_t)serviceData16BitUuids;
+ (uint8_t)serviceData32BitUuids;
+ (uint8_t)serviceSolicitation128BitUuids;
+ (uint8_t)serviceSolicitation16BitUuids;
+ (uint8_t)serviceSolicitation32BitUuids;
+ (uint8_t)shortenedLocalName;
+ (uint8_t)slaveConnectionIntervalRange;
+ (uint8_t)txPowerLevel;
@end

#endif // __WDBABluetoothLEAdvertisementDataTypes_DEFINED__

// Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementPublisherStatusChangedEventArgs
#ifndef __WDBABluetoothLEAdvertisementPublisherStatusChangedEventArgs_DEFINED__
#define __WDBABluetoothLEAdvertisementPublisherStatusChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDBABluetoothLEAdvertisementPublisherStatusChangedEventArgs : RTObject
@property (readonly) WDBBluetoothError error;
@property (readonly) WDBABluetoothLEAdvertisementPublisherStatus status;
@end

#endif // __WDBABluetoothLEAdvertisementPublisherStatusChangedEventArgs_DEFINED__

// Windows.Devices.Bluetooth.Advertisement.BluetoothLEAdvertisementPublisher
#ifndef __WDBABluetoothLEAdvertisementPublisher_DEFINED__
#define __WDBABluetoothLEAdvertisementPublisher_DEFINED__

WINRT_EXPORT
@interface WDBABluetoothLEAdvertisementPublisher : RTObject
+ (WDBABluetoothLEAdvertisementPublisher*)create:(WDBABluetoothLEAdvertisement*)advertisement ACTIVATOR;
+ (instancetype)create ACTIVATOR;
@property (readonly) WDBABluetoothLEAdvertisement* advertisement;
@property (readonly) WDBABluetoothLEAdvertisementPublisherStatus status;
- (EventRegistrationToken)addStatusChangedEvent:(void (^)(WDBABluetoothLEAdvertisementPublisher*,
                                                          WDBABluetoothLEAdvertisementPublisherStatusChangedEventArgs*))del;
- (void)removeStatusChangedEvent:(EventRegistrationToken)tok;
- (void)start;
- (void)stop;
@end

#endif // __WDBABluetoothLEAdvertisementPublisher_DEFINED__
