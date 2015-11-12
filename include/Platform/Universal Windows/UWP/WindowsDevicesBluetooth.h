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

// WindowsDevicesBluetooth.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WDBBluetoothClassOfDevice, WDBBluetoothDevice, WDBBluetoothLEDevice, WDBBluetoothSignalStrengthFilter;
@protocol WDBIBluetoothDevice
, WDBIBluetoothDeviceStatics, WDBIBluetoothLEDevice, WDBIBluetoothLEDeviceStatics, WDBIBluetoothClassOfDevice,
    WDBIBluetoothClassOfDeviceStatics, WDBIBluetoothSignalStrengthFilter;

// Windows.Devices.Bluetooth.BluetoothCacheMode
enum _WDBBluetoothCacheMode {
    WDBBluetoothCacheModeCached = 0,
    WDBBluetoothCacheModeUncached = 1,
};
typedef unsigned WDBBluetoothCacheMode;

// Windows.Devices.Bluetooth.BluetoothMajorClass
enum _WDBBluetoothMajorClass {
    WDBBluetoothMajorClassMiscellaneous = 0,
    WDBBluetoothMajorClassComputer = 1,
    WDBBluetoothMajorClassPhone = 2,
    WDBBluetoothMajorClassNetworkAccessPoint = 3,
    WDBBluetoothMajorClassAudioVideo = 4,
    WDBBluetoothMajorClassPeripheral = 5,
    WDBBluetoothMajorClassImaging = 6,
    WDBBluetoothMajorClassWearable = 7,
    WDBBluetoothMajorClassToy = 8,
    WDBBluetoothMajorClassHealth = 9,
};
typedef unsigned WDBBluetoothMajorClass;

// Windows.Devices.Bluetooth.BluetoothMinorClass
enum _WDBBluetoothMinorClass {
    WDBBluetoothMinorClassUncategorized = 0,
    WDBBluetoothMinorClassComputerDesktop = 1,
    WDBBluetoothMinorClassComputerServer = 2,
    WDBBluetoothMinorClassComputerLaptop = 3,
    WDBBluetoothMinorClassComputerHandheld = 4,
    WDBBluetoothMinorClassComputerPalmSize = 5,
    WDBBluetoothMinorClassComputerWearable = 6,
    WDBBluetoothMinorClassComputerTablet = 7,
    WDBBluetoothMinorClassPhoneCellular = 1,
    WDBBluetoothMinorClassPhoneCordless = 2,
    WDBBluetoothMinorClassPhoneSmartPhone = 3,
    WDBBluetoothMinorClassPhoneWired = 4,
    WDBBluetoothMinorClassPhoneIsdn = 5,
    WDBBluetoothMinorClassNetworkFullyAvailable = 0,
    WDBBluetoothMinorClassNetworkUsed01To17Percent = 8,
    WDBBluetoothMinorClassNetworkUsed17To33Percent = 16,
    WDBBluetoothMinorClassNetworkUsed33To50Percent = 24,
    WDBBluetoothMinorClassNetworkUsed50To67Percent = 32,
    WDBBluetoothMinorClassNetworkUsed67To83Percent = 40,
    WDBBluetoothMinorClassNetworkUsed83To99Percent = 48,
    WDBBluetoothMinorClassNetworkNoServiceAvailable = 56,
    WDBBluetoothMinorClassAudioVideoWearableHeadset = 1,
    WDBBluetoothMinorClassAudioVideoHandsFree = 2,
    WDBBluetoothMinorClassAudioVideoMicrophone = 4,
    WDBBluetoothMinorClassAudioVideoLoudspeaker = 5,
    WDBBluetoothMinorClassAudioVideoHeadphones = 6,
    WDBBluetoothMinorClassAudioVideoPortableAudio = 7,
    WDBBluetoothMinorClassAudioVideoCarAudio = 8,
    WDBBluetoothMinorClassAudioVideoSetTopBox = 9,
    WDBBluetoothMinorClassAudioVideoHifiAudioDevice = 10,
    WDBBluetoothMinorClassAudioVideoVcr = 11,
    WDBBluetoothMinorClassAudioVideoVideoCamera = 12,
    WDBBluetoothMinorClassAudioVideoCamcorder = 13,
    WDBBluetoothMinorClassAudioVideoVideoMonitor = 14,
    WDBBluetoothMinorClassAudioVideoVideoDisplayAndLoudspeaker = 15,
    WDBBluetoothMinorClassAudioVideoVideoConferencing = 16,
    WDBBluetoothMinorClassAudioVideoGamingOrToy = 18,
    WDBBluetoothMinorClassPeripheralJoystick = 1,
    WDBBluetoothMinorClassPeripheralGamepad = 2,
    WDBBluetoothMinorClassPeripheralRemoteControl = 3,
    WDBBluetoothMinorClassPeripheralSensing = 4,
    WDBBluetoothMinorClassPeripheralDigitizerTablet = 5,
    WDBBluetoothMinorClassPeripheralCardReader = 6,
    WDBBluetoothMinorClassPeripheralDigitalPen = 7,
    WDBBluetoothMinorClassPeripheralHandheldScanner = 8,
    WDBBluetoothMinorClassPeripheralHandheldGesture = 9,
    WDBBluetoothMinorClassWearableWristwatch = 1,
    WDBBluetoothMinorClassWearablePager = 2,
    WDBBluetoothMinorClassWearableJacket = 3,
    WDBBluetoothMinorClassWearableHelmet = 4,
    WDBBluetoothMinorClassWearableGlasses = 5,
    WDBBluetoothMinorClassToyRobot = 1,
    WDBBluetoothMinorClassToyVehicle = 2,
    WDBBluetoothMinorClassToyDoll = 3,
    WDBBluetoothMinorClassToyController = 4,
    WDBBluetoothMinorClassToyGame = 5,
    WDBBluetoothMinorClassHealthBloodPressureMonitor = 1,
    WDBBluetoothMinorClassHealthThermometer = 2,
    WDBBluetoothMinorClassHealthWeighingScale = 3,
    WDBBluetoothMinorClassHealthGlucoseMeter = 4,
    WDBBluetoothMinorClassHealthPulseOximeter = 5,
    WDBBluetoothMinorClassHealthHeartRateMonitor = 6,
    WDBBluetoothMinorClassHealthHealthDataDisplay = 7,
    WDBBluetoothMinorClassHealthStepCounter = 8,
    WDBBluetoothMinorClassHealthBodyCompositionAnalyzer = 9,
    WDBBluetoothMinorClassHealthPeakFlowMonitor = 10,
    WDBBluetoothMinorClassHealthMedicationMonitor = 11,
    WDBBluetoothMinorClassHealthKneeProsthesis = 12,
    WDBBluetoothMinorClassHealthAnkleProsthesis = 13,
    WDBBluetoothMinorClassHealthGenericHealthManager = 14,
    WDBBluetoothMinorClassHealthPersonalMobilityDevice = 15,
};
typedef unsigned WDBBluetoothMinorClass;

// Windows.Devices.Bluetooth.BluetoothServiceCapabilities
enum _WDBBluetoothServiceCapabilities {
    WDBBluetoothServiceCapabilitiesNone = 0,
    WDBBluetoothServiceCapabilitiesLimitedDiscoverableMode = 1,
    WDBBluetoothServiceCapabilitiesPositioningService = 8,
    WDBBluetoothServiceCapabilitiesNetworkingService = 16,
    WDBBluetoothServiceCapabilitiesRenderingService = 32,
    WDBBluetoothServiceCapabilitiesCapturingService = 64,
    WDBBluetoothServiceCapabilitiesObjectTransferService = 128,
    WDBBluetoothServiceCapabilitiesAudioService = 256,
    WDBBluetoothServiceCapabilitiesTelephoneService = 512,
    WDBBluetoothServiceCapabilitiesInformationService = 1024,
};
typedef unsigned WDBBluetoothServiceCapabilities;

// Windows.Devices.Bluetooth.BluetoothConnectionStatus
enum _WDBBluetoothConnectionStatus {
    WDBBluetoothConnectionStatusDisconnected = 0,
    WDBBluetoothConnectionStatusConnected = 1,
};
typedef unsigned WDBBluetoothConnectionStatus;

// Windows.Devices.Bluetooth.BluetoothError
enum _WDBBluetoothError {
    WDBBluetoothErrorSuccess = 0,
    WDBBluetoothErrorRadioNotAvailable = 1,
    WDBBluetoothErrorResourceInUse = 2,
    WDBBluetoothErrorDeviceNotConnected = 3,
    WDBBluetoothErrorOtherError = 4,
    WDBBluetoothErrorDisabledByPolicy = 5,
    WDBBluetoothErrorNotSupported = 6,
};
typedef unsigned WDBBluetoothError;

#include "WindowsDevicesBluetoothGenericAttributeProfile.h"
#include "WindowsFoundation.h"
#include "WindowsNetworking.h"
#include "WindowsStorageStreams.h"
#include "WindowsFoundationCollections.h"
#include "WindowsDevicesBluetoothRfcomm.h"

#import <Foundation/Foundation.h>

// Windows.Devices.Bluetooth.BluetoothClassOfDevice
#ifndef __WDBBluetoothClassOfDevice_DEFINED__
#define __WDBBluetoothClassOfDevice_DEFINED__

WINRT_EXPORT
@interface WDBBluetoothClassOfDevice : RTObject
+ (WDBBluetoothClassOfDevice*)fromRawValue:(unsigned int)rawValue;
+ (WDBBluetoothClassOfDevice*)fromParts:(WDBBluetoothMajorClass)majorClass
                             minorClass:(WDBBluetoothMinorClass)minorClass
                    serviceCapabilities:(WDBBluetoothServiceCapabilities)serviceCapabilities;
@property (readonly) WDBBluetoothMajorClass majorClass;
@property (readonly) WDBBluetoothMinorClass minorClass;
@property (readonly) unsigned int rawValue;
@property (readonly) WDBBluetoothServiceCapabilities serviceCapabilities;
@end

#endif // __WDBBluetoothClassOfDevice_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

#endif // __WFIClosable_DEFINED__

// Windows.Devices.Bluetooth.BluetoothDevice
#ifndef __WDBBluetoothDevice_DEFINED__
#define __WDBBluetoothDevice_DEFINED__

WINRT_EXPORT
@interface WDBBluetoothDevice : RTObject <WFIClosable>
+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDBBluetoothDevice*))success failure:(void (^)(NSError*))failure;
+ (void)fromHostNameAsync:(WNHostName*)hostName success:(void (^)(WDBBluetoothDevice*))success failure:(void (^)(NSError*))failure;
+ (void)fromBluetoothAddressAsync:(uint64_t)address success:(void (^)(WDBBluetoothDevice*))success failure:(void (^)(NSError*))failure;
+ (NSString*)getDeviceSelector;
@property (readonly) uint64_t bluetoothAddress;
@property (readonly) WDBBluetoothClassOfDevice* classOfDevice;
@property (readonly) WDBBluetoothConnectionStatus connectionStatus;
@property (readonly) NSString* deviceId;
@property (readonly) WNHostName* hostName;
@property (readonly) NSString* name;
@property (readonly) NSArray* rfcommServices;
@property (readonly) NSArray* sdpRecords;
- (EventRegistrationToken)addConnectionStatusChangedEvent:(void (^)(WDBBluetoothDevice*, RTObject*))del;
- (void)removeConnectionStatusChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addNameChangedEvent:(void (^)(WDBBluetoothDevice*, RTObject*))del;
- (void)removeNameChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSdpRecordsChangedEvent:(void (^)(WDBBluetoothDevice*, RTObject*))del;
- (void)removeSdpRecordsChangedEvent:(EventRegistrationToken)tok;
- (void)close;
@end

#endif // __WDBBluetoothDevice_DEFINED__

// Windows.Devices.Bluetooth.BluetoothLEDevice
#ifndef __WDBBluetoothLEDevice_DEFINED__
#define __WDBBluetoothLEDevice_DEFINED__

WINRT_EXPORT
@interface WDBBluetoothLEDevice : RTObject <WFIClosable>
+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDBBluetoothLEDevice*))success failure:(void (^)(NSError*))failure;
+ (void)fromBluetoothAddressAsync:(uint64_t)bluetoothAddress
                          success:(void (^)(WDBBluetoothLEDevice*))success
                          failure:(void (^)(NSError*))failure;
+ (NSString*)getDeviceSelector;
@property (readonly) uint64_t bluetoothAddress;
@property (readonly) WDBBluetoothConnectionStatus connectionStatus;
@property (readonly) NSString* deviceId;
@property (readonly) NSArray* gattServices;
@property (readonly) NSString* name;
- (EventRegistrationToken)addConnectionStatusChangedEvent:(void (^)(WDBBluetoothLEDevice*, RTObject*))del;
- (void)removeConnectionStatusChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addGattServicesChangedEvent:(void (^)(WDBBluetoothLEDevice*, RTObject*))del;
- (void)removeGattServicesChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addNameChangedEvent:(void (^)(WDBBluetoothLEDevice*, RTObject*))del;
- (void)removeNameChangedEvent:(EventRegistrationToken)tok;
- (WDBGGattDeviceService*)getGattService:(WFGUID*)serviceUuid;
- (void)close;
@end

#endif // __WDBBluetoothLEDevice_DEFINED__

// Windows.Devices.Bluetooth.BluetoothSignalStrengthFilter
#ifndef __WDBBluetoothSignalStrengthFilter_DEFINED__
#define __WDBBluetoothSignalStrengthFilter_DEFINED__

WINRT_EXPORT
@interface WDBBluetoothSignalStrengthFilter : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) id samplingInterval;
@property (copy) id outOfRangeTimeout;
@property (copy) id outOfRangeThresholdInDBm;
@property (copy) id inRangeThresholdInDBm;
@end

#endif // __WDBBluetoothSignalStrengthFilter_DEFINED__
