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

// WindowsDevicesBluetooth.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
#define OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsConsolidatedNamespace.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WDBBluetoothAdapter, WDBBluetoothDeviceId, WDBBluetoothUuidHelper, WDBBluetoothDevice, WDBBluetoothClassOfDevice, WDBBluetoothLEAppearanceCategories, WDBBluetoothLEAppearanceSubcategories, WDBBluetoothLEAppearance, WDBBluetoothLEDevice, WDBBluetoothSignalStrengthFilter;
@protocol WDBIBluetoothAdapterStatics, WDBIBluetoothAdapter, WDBIBluetoothDeviceIdStatics, WDBIBluetoothDeviceId, WDBIBluetoothUuidHelperStatics, WDBIBluetoothDeviceStatics, WDBIBluetoothDeviceStatics2, WDBIBluetoothDevice, WDBIBluetoothDevice2, WDBIBluetoothDevice3, WDBIBluetoothDevice4, WDBIBluetoothLEAppearanceCategoriesStatics, WDBIBluetoothLEAppearanceSubcategoriesStatics, WDBIBluetoothLEAppearance, WDBIBluetoothLEAppearanceStatics, WDBIBluetoothLEDeviceStatics, WDBIBluetoothLEDeviceStatics2, WDBIBluetoothLEDevice, WDBIBluetoothLEDevice2, WDBIBluetoothLEDevice3, WDBIBluetoothLEDevice4, WDBIBluetoothClassOfDevice, WDBIBluetoothClassOfDeviceStatics, WDBIBluetoothSignalStrengthFilter;

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
    WDBBluetoothErrorDisabledByUser = 7,
    WDBBluetoothErrorConsentRequired = 8,
    WDBBluetoothErrorTransportNotSupported = 9,
};
typedef unsigned WDBBluetoothError;

// Windows.Devices.Bluetooth.BluetoothAddressType
enum _WDBBluetoothAddressType {
    WDBBluetoothAddressTypePublic = 0,
    WDBBluetoothAddressTypeRandom = 1,
    WDBBluetoothAddressTypeUnspecified = 2,
};
typedef unsigned WDBBluetoothAddressType;

#include "WindowsDevicesBluetoothGenericAttributeProfile.h"
#include "WindowsFoundation.h"
#include "WindowsDevicesRadios.h"
#include "WindowsNetworking.h"
#include "WindowsStorageStreams.h"
#include "WindowsDevicesBluetoothRfcomm.h"
#include "WindowsDevicesEnumeration.h"

#import <Foundation/Foundation.h>

// Windows.Devices.Bluetooth.BluetoothAdapter
#ifndef __WDBBluetoothAdapter_DEFINED__
#define __WDBBluetoothAdapter_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBBluetoothAdapter : RTObject
+ (NSString *)getDeviceSelector;
+ (void)fromIdAsync:(NSString *)deviceId success:(void (^)(WDBBluetoothAdapter*))success failure:(void (^)(NSError*))failure;
+ (void)getDefaultAsyncWithSuccess:(void (^)(WDBBluetoothAdapter*))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) uint64_t bluetoothAddress;
@property (readonly) NSString * deviceId;
@property (readonly) BOOL isAdvertisementOffloadSupported;
@property (readonly) BOOL isCentralRoleSupported;
@property (readonly) BOOL isClassicSupported;
@property (readonly) BOOL isLowEnergySupported;
@property (readonly) BOOL isPeripheralRoleSupported;
- (void)getRadioAsyncWithSuccess:(void (^)(WDRRadio*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDBBluetoothAdapter_DEFINED__

// Windows.Devices.Bluetooth.BluetoothDeviceId
#ifndef __WDBBluetoothDeviceId_DEFINED__
#define __WDBBluetoothDeviceId_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBBluetoothDeviceId : RTObject
+ (WDBBluetoothDeviceId*)fromId:(NSString *)deviceId;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * id;
@property (readonly) BOOL isClassicDevice;
@property (readonly) BOOL isLowEnergyDevice;
@end

#endif // __WDBBluetoothDeviceId_DEFINED__

// Windows.Devices.Bluetooth.BluetoothUuidHelper
#ifndef __WDBBluetoothUuidHelper_DEFINED__
#define __WDBBluetoothUuidHelper_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBBluetoothUuidHelper : RTObject
+ (WFGUID*)fromShortId:(unsigned int)shortId;
+ (id /* unsigned int */)tryGetShortId:(WFGUID*)uuid;
@end

#endif // __WDBBluetoothUuidHelper_DEFINED__

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

// Windows.Devices.Bluetooth.BluetoothDevice
#ifndef __WDBBluetoothDevice_DEFINED__
#define __WDBBluetoothDevice_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBBluetoothDevice : RTObject <WFIClosable>
+ (void)fromIdAsync:(NSString *)deviceId success:(void (^)(WDBBluetoothDevice*))success failure:(void (^)(NSError*))failure;
+ (void)fromHostNameAsync:(WNHostName*)hostName success:(void (^)(WDBBluetoothDevice*))success failure:(void (^)(NSError*))failure;
+ (void)fromBluetoothAddressAsync:(uint64_t)address success:(void (^)(WDBBluetoothDevice*))success failure:(void (^)(NSError*))failure;
+ (NSString *)getDeviceSelector;
+ (NSString *)getDeviceSelectorFromPairingState:(BOOL)pairingState;
+ (NSString *)getDeviceSelectorFromConnectionStatus:(WDBBluetoothConnectionStatus)connectionStatus;
+ (NSString *)getDeviceSelectorFromDeviceName:(NSString *)deviceName;
+ (NSString *)getDeviceSelectorFromBluetoothAddress:(uint64_t)bluetoothAddress;
+ (NSString *)getDeviceSelectorFromClassOfDevice:(WDBBluetoothClassOfDevice*)classOfDevice;
+ (void)fromIdAsync:(NSString *)deviceId success:(void (^)(WDBBluetoothDevice*))success failure:(void (^)(NSError*))failure;
+ (void)fromHostNameAsync:(WNHostName*)hostName success:(void (^)(WDBBluetoothDevice*))success failure:(void (^)(NSError*))failure;
+ (void)fromBluetoothAddressAsync:(uint64_t)address success:(void (^)(WDBBluetoothDevice*))success failure:(void (^)(NSError*))failure;
+ (NSString *)getDeviceSelector;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) uint64_t bluetoothAddress;
@property (readonly) WDBBluetoothClassOfDevice* classOfDevice;
@property (readonly) WDBBluetoothConnectionStatus connectionStatus;
@property (readonly) NSString * deviceId;
@property (readonly) WNHostName* hostName;
@property (readonly) NSString * name;
@property (readonly) NSArray* /* WDBRRfcommDeviceService* */ rfcommServices;
@property (readonly) NSArray* /* RTObject<WSSIBuffer>* */ sdpRecords;
@property (readonly) WDEDeviceInformation* deviceInformation;
@property (readonly) WDEDeviceAccessInformation* deviceAccessInformation;
@property (readonly) WDBBluetoothDeviceId* bluetoothDeviceId;
- (EventRegistrationToken)addConnectionStatusChangedEvent:(void(^)(WDBBluetoothDevice*, RTObject*))del;
- (void)removeConnectionStatusChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addNameChangedEvent:(void(^)(WDBBluetoothDevice*, RTObject*))del;
- (void)removeNameChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSdpRecordsChangedEvent:(void(^)(WDBBluetoothDevice*, RTObject*))del;
- (void)removeSdpRecordsChangedEvent:(EventRegistrationToken)tok;
- (void)close;
- (void)requestAccessAsyncWithSuccess:(void (^)(WDEDeviceAccessStatus))success failure:(void (^)(NSError*))failure;
- (void)getRfcommServicesAsyncWithSuccess:(void (^)(WDBRRfcommDeviceServicesResult*))success failure:(void (^)(NSError*))failure;
- (void)getRfcommServicesWithCacheModeAsync:(WDBBluetoothCacheMode)cacheMode success:(void (^)(WDBRRfcommDeviceServicesResult*))success failure:(void (^)(NSError*))failure;
- (void)getRfcommServicesForIdAsync:(WDBRRfcommServiceId*)serviceId success:(void (^)(WDBRRfcommDeviceServicesResult*))success failure:(void (^)(NSError*))failure;
- (void)getRfcommServicesForIdWithCacheModeAsync:(WDBRRfcommServiceId*)serviceId cacheMode:(WDBBluetoothCacheMode)cacheMode success:(void (^)(WDBRRfcommDeviceServicesResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDBBluetoothDevice_DEFINED__

// Windows.Devices.Bluetooth.BluetoothClassOfDevice
#ifndef __WDBBluetoothClassOfDevice_DEFINED__
#define __WDBBluetoothClassOfDevice_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBBluetoothClassOfDevice : RTObject
+ (WDBBluetoothClassOfDevice*)fromRawValue:(unsigned int)rawValue;
+ (WDBBluetoothClassOfDevice*)fromParts:(WDBBluetoothMajorClass)majorClass minorClass:(WDBBluetoothMinorClass)minorClass serviceCapabilities:(WDBBluetoothServiceCapabilities)serviceCapabilities;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDBBluetoothMajorClass majorClass;
@property (readonly) WDBBluetoothMinorClass minorClass;
@property (readonly) unsigned int rawValue;
@property (readonly) WDBBluetoothServiceCapabilities serviceCapabilities;
@end

#endif // __WDBBluetoothClassOfDevice_DEFINED__

// Windows.Devices.Bluetooth.BluetoothLEAppearanceCategories
#ifndef __WDBBluetoothLEAppearanceCategories_DEFINED__
#define __WDBBluetoothLEAppearanceCategories_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBBluetoothLEAppearanceCategories : RTObject
+ (unsigned short)barcodeScanner;
+ (unsigned short)bloodPressure;
+ (unsigned short)clock;
+ (unsigned short)computer;
+ (unsigned short)cycling;
+ (unsigned short)display;
+ (unsigned short)eyeGlasses;
+ (unsigned short)glucoseMeter;
+ (unsigned short)heartRate;
+ (unsigned short)humanInterfaceDevice;
+ (unsigned short)keyring;
+ (unsigned short)mediaPlayer;
+ (unsigned short)outdoorSportActivity;
+ (unsigned short)phone;
+ (unsigned short)pulseOximeter;
+ (unsigned short)remoteControl;
+ (unsigned short)runningWalking;
+ (unsigned short)tag;
+ (unsigned short)thermometer;
+ (unsigned short)uncategorized;
+ (unsigned short)watch;
+ (unsigned short)weightScale;
@end

#endif // __WDBBluetoothLEAppearanceCategories_DEFINED__

// Windows.Devices.Bluetooth.BluetoothLEAppearanceSubcategories
#ifndef __WDBBluetoothLEAppearanceSubcategories_DEFINED__
#define __WDBBluetoothLEAppearanceSubcategories_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBBluetoothLEAppearanceSubcategories : RTObject
+ (unsigned short)barcodeScanner;
+ (unsigned short)bloodPressureArm;
+ (unsigned short)bloodPressureWrist;
+ (unsigned short)cardReader;
+ (unsigned short)cyclingCadenceSensor;
+ (unsigned short)cyclingComputer;
+ (unsigned short)cyclingPowerSensor;
+ (unsigned short)cyclingSpeedCadenceSensor;
+ (unsigned short)cyclingSpeedSensor;
+ (unsigned short)digitalPen;
+ (unsigned short)digitizerTablet;
+ (unsigned short)gamepad;
+ (unsigned short)generic;
+ (unsigned short)heartRateBelt;
+ (unsigned short)joystick;
+ (unsigned short)keyboard;
+ (unsigned short)locationDisplay;
+ (unsigned short)locationNavigationDisplay;
+ (unsigned short)locationNavigationPod;
+ (unsigned short)locationPod;
+ (unsigned short)mouse;
+ (unsigned short)oximeterFingertip;
+ (unsigned short)oximeterWristWorn;
+ (unsigned short)runningWalkingInShoe;
+ (unsigned short)runningWalkingOnHip;
+ (unsigned short)runningWalkingOnShoe;
+ (unsigned short)sportsWatch;
+ (unsigned short)thermometerEar;
@end

#endif // __WDBBluetoothLEAppearanceSubcategories_DEFINED__

// Windows.Devices.Bluetooth.BluetoothLEAppearance
#ifndef __WDBBluetoothLEAppearance_DEFINED__
#define __WDBBluetoothLEAppearance_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBBluetoothLEAppearance : RTObject
+ (WDBBluetoothLEAppearance*)fromRawValue:(unsigned short)rawValue;
+ (WDBBluetoothLEAppearance*)fromParts:(unsigned short)appearanceCategory appearanceSubCategory:(unsigned short)appearanceSubCategory;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned short category;
@property (readonly) unsigned short rawValue;
@property (readonly) unsigned short subCategory;
@end

#endif // __WDBBluetoothLEAppearance_DEFINED__

// Windows.Devices.Bluetooth.BluetoothLEDevice
#ifndef __WDBBluetoothLEDevice_DEFINED__
#define __WDBBluetoothLEDevice_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBBluetoothLEDevice : RTObject <WFIClosable>
+ (void)fromIdAsync:(NSString *)deviceId success:(void (^)(WDBBluetoothLEDevice*))success failure:(void (^)(NSError*))failure;
+ (void)fromBluetoothAddressAsync:(uint64_t)bluetoothAddress success:(void (^)(WDBBluetoothLEDevice*))success failure:(void (^)(NSError*))failure;
+ (NSString *)getDeviceSelector;
+ (NSString *)getDeviceSelectorFromPairingState:(BOOL)pairingState;
+ (NSString *)getDeviceSelectorFromConnectionStatus:(WDBBluetoothConnectionStatus)connectionStatus;
+ (NSString *)getDeviceSelectorFromDeviceName:(NSString *)deviceName;
+ (NSString *)getDeviceSelectorFromBluetoothAddress:(uint64_t)bluetoothAddress;
+ (NSString *)getDeviceSelectorFromBluetoothAddressWithBluetoothAddressType:(uint64_t)bluetoothAddress bluetoothAddressType:(WDBBluetoothAddressType)bluetoothAddressType;
+ (NSString *)getDeviceSelectorFromAppearance:(WDBBluetoothLEAppearance*)appearance;
+ (void)fromBluetoothAddressWithBluetoothAddressTypeAsync:(uint64_t)bluetoothAddress bluetoothAddressType:(WDBBluetoothAddressType)bluetoothAddressType success:(void (^)(WDBBluetoothLEDevice*))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) uint64_t bluetoothAddress;
@property (readonly) WDBBluetoothConnectionStatus connectionStatus;
@property (readonly) NSString * deviceId;
@property (readonly) NSArray* /* WDBGGattDeviceService* */ gattServices;
@property (readonly) NSString * name;
@property (readonly) WDBBluetoothLEAppearance* appearance;
@property (readonly) WDBBluetoothAddressType bluetoothAddressType;
@property (readonly) WDEDeviceInformation* deviceInformation;
@property (readonly) WDEDeviceAccessInformation* deviceAccessInformation;
@property (readonly) WDBBluetoothDeviceId* bluetoothDeviceId;
- (EventRegistrationToken)addConnectionStatusChangedEvent:(void(^)(WDBBluetoothLEDevice*, RTObject*))del;
- (void)removeConnectionStatusChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addGattServicesChangedEvent:(void(^)(WDBBluetoothLEDevice*, RTObject*))del;
- (void)removeGattServicesChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addNameChangedEvent:(void(^)(WDBBluetoothLEDevice*, RTObject*))del;
- (void)removeNameChangedEvent:(EventRegistrationToken)tok;
- (WDBGGattDeviceService*)getGattService:(WFGUID*)serviceUuid;
- (void)close;
- (void)requestAccessAsyncWithSuccess:(void (^)(WDEDeviceAccessStatus))success failure:(void (^)(NSError*))failure;
- (void)getGattServicesAsyncWithSuccess:(void (^)(WDBGGattDeviceServicesResult*))success failure:(void (^)(NSError*))failure;
- (void)getGattServicesWithCacheModeAsync:(WDBBluetoothCacheMode)cacheMode success:(void (^)(WDBGGattDeviceServicesResult*))success failure:(void (^)(NSError*))failure;
- (void)getGattServicesForUuidAsync:(WFGUID*)serviceUuid success:(void (^)(WDBGGattDeviceServicesResult*))success failure:(void (^)(NSError*))failure;
- (void)getGattServicesForUuidWithCacheModeAsync:(WFGUID*)serviceUuid cacheMode:(WDBBluetoothCacheMode)cacheMode success:(void (^)(WDBGGattDeviceServicesResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDBBluetoothLEDevice_DEFINED__

// Windows.Devices.Bluetooth.BluetoothSignalStrengthFilter
#ifndef __WDBBluetoothSignalStrengthFilter_DEFINED__
#define __WDBBluetoothSignalStrengthFilter_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WDBBluetoothSignalStrengthFilter : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) id /* WFTimeSpan* */ samplingInterval;
@property (retain) id /* WFTimeSpan* */ outOfRangeTimeout;
@property (retain) id /* int16_t */ outOfRangeThresholdInDBm;
@property (retain) id /* int16_t */ inRangeThresholdInDBm;
@end

#endif // __WDBBluetoothSignalStrengthFilter_DEFINED__

