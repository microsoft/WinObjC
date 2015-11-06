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

// WindowsDevicesWiFiDirect.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WDWWiFiDirectDevice, WDWWiFiDirectConnectionParameters, WDWWiFiDirectInformationElement, WDWWiFiDirectLegacySettings,
    WDWWiFiDirectAdvertisement, WDWWiFiDirectAdvertisementPublisherStatusChangedEventArgs, WDWWiFiDirectAdvertisementPublisher,
    WDWWiFiDirectConnectionRequest, WDWWiFiDirectConnectionRequestedEventArgs, WDWWiFiDirectConnectionListener;
@protocol WDWIWiFiDirectDeviceStatics
, WDWIWiFiDirectDeviceStatics2, WDWIWiFiDirectInformationElementStatics, WDWIWiFiDirectInformationElement, WDWIWiFiDirectLegacySettings,
    WDWIWiFiDirectAdvertisement, WDWIWiFiDirectAdvertisementPublisherStatusChangedEventArgs, WDWIWiFiDirectAdvertisementPublisher,
    WDWIWiFiDirectConnectionParameters, WDWIWiFiDirectConnectionRequestedEventArgs, WDWIWiFiDirectConnectionListener, WDWIWiFiDirectDevice,
    WDWIWiFiDirectConnectionRequest;

// Windows.Devices.WiFiDirect.WiFiDirectConnectionStatus
enum _WDWWiFiDirectConnectionStatus {
    WDWWiFiDirectConnectionStatusDisconnected = 0,
    WDWWiFiDirectConnectionStatusConnected = 1,
};
typedef unsigned WDWWiFiDirectConnectionStatus;

// Windows.Devices.WiFiDirect.WiFiDirectError
enum _WDWWiFiDirectError {
    WDWWiFiDirectErrorSuccess = 0,
    WDWWiFiDirectErrorRadioNotAvailable = 1,
    WDWWiFiDirectErrorResourceInUse = 2,
};
typedef unsigned WDWWiFiDirectError;

// Windows.Devices.WiFiDirect.WiFiDirectDeviceSelectorType
enum _WDWWiFiDirectDeviceSelectorType {
    WDWWiFiDirectDeviceSelectorTypeDeviceInterface = 0,
    WDWWiFiDirectDeviceSelectorTypeAssociationEndpoint = 1,
};
typedef unsigned WDWWiFiDirectDeviceSelectorType;

// Windows.Devices.WiFiDirect.WiFiDirectAdvertisementListenStateDiscoverability
enum _WDWWiFiDirectAdvertisementListenStateDiscoverability {
    WDWWiFiDirectAdvertisementListenStateDiscoverabilityNone = 0,
    WDWWiFiDirectAdvertisementListenStateDiscoverabilityNormal = 1,
    WDWWiFiDirectAdvertisementListenStateDiscoverabilityIntensive = 2,
};
typedef unsigned WDWWiFiDirectAdvertisementListenStateDiscoverability;

// Windows.Devices.WiFiDirect.WiFiDirectAdvertisementPublisherStatus
enum _WDWWiFiDirectAdvertisementPublisherStatus {
    WDWWiFiDirectAdvertisementPublisherStatusCreated = 0,
    WDWWiFiDirectAdvertisementPublisherStatusStarted = 1,
    WDWWiFiDirectAdvertisementPublisherStatusStopped = 2,
    WDWWiFiDirectAdvertisementPublisherStatusAborted = 3,
};
typedef unsigned WDWWiFiDirectAdvertisementPublisherStatus;

#include "WindowsFoundation.h"
#include "WindowsSecurityCredentials.h"
#include "WindowsFoundationCollections.h"
#include "WindowsStorageStreams.h"
#include "WindowsDevicesEnumeration.h"
#include "WindowsNetworking.h"

#import <Foundation/Foundation.h>

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

#endif // __WFIClosable_DEFINED__

// Windows.Devices.WiFiDirect.WiFiDirectDevice
#ifndef __WDWWiFiDirectDevice_DEFINED__
#define __WDWWiFiDirectDevice_DEFINED__

WINRT_EXPORT
@interface WDWWiFiDirectDevice : RTObject <WFIClosable>
+ (NSString*)getDeviceSelector:(WDWWiFiDirectDeviceSelectorType)type;
+ (void)fromIdAsync:(NSString*)deviceId
    connectionParameters:(WDWWiFiDirectConnectionParameters*)connectionParameters
                 success:(void (^)(WDWWiFiDirectDevice*))success
                 failure:(void (^)(NSError*))failure;
+ (NSString*)getDeviceSelector;
+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDWWiFiDirectDevice*))success failure:(void (^)(NSError*))failure;
@property (readonly) WDWWiFiDirectConnectionStatus connectionStatus;
@property (readonly) NSString* deviceId;
- (EventRegistrationToken)addConnectionStatusChangedEvent:(void (^)(WDWWiFiDirectDevice*, RTObject*))del;
- (void)removeConnectionStatusChangedEvent:(EventRegistrationToken)tok;
- (NSArray*)getConnectionEndpointPairs;
- (void)close;
@end

#endif // __WDWWiFiDirectDevice_DEFINED__

// Windows.Devices.WiFiDirect.WiFiDirectConnectionParameters
#ifndef __WDWWiFiDirectConnectionParameters_DEFINED__
#define __WDWWiFiDirectConnectionParameters_DEFINED__

WINRT_EXPORT
@interface WDWWiFiDirectConnectionParameters : RTObject
+ (instancetype)create ACTIVATOR;
@property int16_t groupOwnerIntent;
@end

#endif // __WDWWiFiDirectConnectionParameters_DEFINED__

// Windows.Devices.WiFiDirect.WiFiDirectInformationElement
#ifndef __WDWWiFiDirectInformationElement_DEFINED__
#define __WDWWiFiDirectInformationElement_DEFINED__

WINRT_EXPORT
@interface WDWWiFiDirectInformationElement : RTObject
+ (NSMutableArray*)createFromBuffer:(RTObject<WSSIBuffer>*)buffer;
+ (NSMutableArray*)createFromDeviceInformation:(WDEDeviceInformation*)deviceInformation;
+ (instancetype)create ACTIVATOR;
@property (copy) RTObject<WSSIBuffer>* value;
@property uint8_t ouiType;
@property (copy) RTObject<WSSIBuffer>* oui;
@end

#endif // __WDWWiFiDirectInformationElement_DEFINED__

// Windows.Devices.WiFiDirect.WiFiDirectLegacySettings
#ifndef __WDWWiFiDirectLegacySettings_DEFINED__
#define __WDWWiFiDirectLegacySettings_DEFINED__

WINRT_EXPORT
@interface WDWWiFiDirectLegacySettings : RTObject
@property (copy) NSString* ssid;
@property (copy) WSCPasswordCredential* passphrase;
@property BOOL isEnabled;
@end

#endif // __WDWWiFiDirectLegacySettings_DEFINED__

// Windows.Devices.WiFiDirect.WiFiDirectAdvertisement
#ifndef __WDWWiFiDirectAdvertisement_DEFINED__
#define __WDWWiFiDirectAdvertisement_DEFINED__

WINRT_EXPORT
@interface WDWWiFiDirectAdvertisement : RTObject
@property WDWWiFiDirectAdvertisementListenStateDiscoverability listenStateDiscoverability;
@property BOOL isAutonomousGroupOwnerEnabled;
@property (copy) NSMutableArray* informationElements;
@property (readonly) WDWWiFiDirectLegacySettings* legacySettings;
@end

#endif // __WDWWiFiDirectAdvertisement_DEFINED__

// Windows.Devices.WiFiDirect.WiFiDirectAdvertisementPublisherStatusChangedEventArgs
#ifndef __WDWWiFiDirectAdvertisementPublisherStatusChangedEventArgs_DEFINED__
#define __WDWWiFiDirectAdvertisementPublisherStatusChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDWWiFiDirectAdvertisementPublisherStatusChangedEventArgs : RTObject
@property (readonly) WDWWiFiDirectError error;
@property (readonly) WDWWiFiDirectAdvertisementPublisherStatus status;
@end

#endif // __WDWWiFiDirectAdvertisementPublisherStatusChangedEventArgs_DEFINED__

// Windows.Devices.WiFiDirect.WiFiDirectAdvertisementPublisher
#ifndef __WDWWiFiDirectAdvertisementPublisher_DEFINED__
#define __WDWWiFiDirectAdvertisementPublisher_DEFINED__

WINRT_EXPORT
@interface WDWWiFiDirectAdvertisementPublisher : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) WDWWiFiDirectAdvertisement* advertisement;
@property (readonly) WDWWiFiDirectAdvertisementPublisherStatus status;
- (EventRegistrationToken)addStatusChangedEvent:(void (^)(WDWWiFiDirectAdvertisementPublisher*,
                                                          WDWWiFiDirectAdvertisementPublisherStatusChangedEventArgs*))del;
- (void)removeStatusChangedEvent:(EventRegistrationToken)tok;
- (void)start;
- (void)stop;
@end

#endif // __WDWWiFiDirectAdvertisementPublisher_DEFINED__

// Windows.Devices.WiFiDirect.WiFiDirectConnectionRequest
#ifndef __WDWWiFiDirectConnectionRequest_DEFINED__
#define __WDWWiFiDirectConnectionRequest_DEFINED__

WINRT_EXPORT
@interface WDWWiFiDirectConnectionRequest : RTObject <WFIClosable>
@property (readonly) WDEDeviceInformation* deviceInformation;
- (void)close;
@end

#endif // __WDWWiFiDirectConnectionRequest_DEFINED__

// Windows.Devices.WiFiDirect.WiFiDirectConnectionRequestedEventArgs
#ifndef __WDWWiFiDirectConnectionRequestedEventArgs_DEFINED__
#define __WDWWiFiDirectConnectionRequestedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDWWiFiDirectConnectionRequestedEventArgs : RTObject
- (WDWWiFiDirectConnectionRequest*)getConnectionRequest;
@end

#endif // __WDWWiFiDirectConnectionRequestedEventArgs_DEFINED__

// Windows.Devices.WiFiDirect.WiFiDirectConnectionListener
#ifndef __WDWWiFiDirectConnectionListener_DEFINED__
#define __WDWWiFiDirectConnectionListener_DEFINED__

WINRT_EXPORT
@interface WDWWiFiDirectConnectionListener : RTObject
+ (instancetype)create ACTIVATOR;
- (EventRegistrationToken)addConnectionRequestedEvent:(void (^)(WDWWiFiDirectConnectionListener*,
                                                                WDWWiFiDirectConnectionRequestedEventArgs*))del;
- (void)removeConnectionRequestedEvent:(EventRegistrationToken)tok;
@end

#endif // __WDWWiFiDirectConnectionListener_DEFINED__
