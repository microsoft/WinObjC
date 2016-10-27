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

// WindowsDevicesWiFi.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_DEVICES_WIFI_EXPORT
#define OBJCUWP_WINDOWS_DEVICES_WIFI_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_Devices_WiFi.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WDWWiFiAdapter, WDWWiFiNetworkReport, WDWWiFiAvailableNetwork, WDWWiFiConnectionResult;
@protocol WDWIWiFiAdapterStatics
, WDWIWiFiAdapter, WDWIWiFiNetworkReport, WDWIWiFiAvailableNetwork, WDWIWiFiConnectionResult;

// Windows.Devices.WiFi.WiFiNetworkKind
enum _WDWWiFiNetworkKind {
    WDWWiFiNetworkKindAny = 0,
    WDWWiFiNetworkKindInfrastructure = 1,
    WDWWiFiNetworkKindAdhoc = 2,
};
typedef unsigned WDWWiFiNetworkKind;

// Windows.Devices.WiFi.WiFiPhyKind
enum _WDWWiFiPhyKind {
    WDWWiFiPhyKindUnknown = 0,
    WDWWiFiPhyKindFhss = 1,
    WDWWiFiPhyKindDsss = 2,
    WDWWiFiPhyKindIRBaseband = 3,
    WDWWiFiPhyKindOfdm = 4,
    WDWWiFiPhyKindHrdsss = 5,
    WDWWiFiPhyKindErp = 6,
    WDWWiFiPhyKindHT = 7,
    WDWWiFiPhyKindVht = 8,
};
typedef unsigned WDWWiFiPhyKind;

// Windows.Devices.WiFi.WiFiAccessStatus
enum _WDWWiFiAccessStatus {
    WDWWiFiAccessStatusUnspecified = 0,
    WDWWiFiAccessStatusAllowed = 1,
    WDWWiFiAccessStatusDeniedByUser = 2,
    WDWWiFiAccessStatusDeniedBySystem = 3,
};
typedef unsigned WDWWiFiAccessStatus;

// Windows.Devices.WiFi.WiFiReconnectionKind
enum _WDWWiFiReconnectionKind {
    WDWWiFiReconnectionKindAutomatic = 0,
    WDWWiFiReconnectionKindManual = 1,
};
typedef unsigned WDWWiFiReconnectionKind;

// Windows.Devices.WiFi.WiFiConnectionStatus
enum _WDWWiFiConnectionStatus {
    WDWWiFiConnectionStatusUnspecifiedFailure = 0,
    WDWWiFiConnectionStatusSuccess = 1,
    WDWWiFiConnectionStatusAccessRevoked = 2,
    WDWWiFiConnectionStatusInvalidCredential = 3,
    WDWWiFiConnectionStatusNetworkNotAvailable = 4,
    WDWWiFiConnectionStatusTimeout = 5,
    WDWWiFiConnectionStatusUnsupportedAuthenticationProtocol = 6,
};
typedef unsigned WDWWiFiConnectionStatus;

#include "WindowsNetworkingConnectivity.h"
#include "WindowsFoundation.h"
#include "WindowsSecurityCredentials.h"

#import <Foundation/Foundation.h>

// Windows.Devices.WiFi.WiFiAdapter
#ifndef __WDWWiFiAdapter_DEFINED__
#define __WDWWiFiAdapter_DEFINED__

OBJCUWP_WINDOWS_DEVICES_WIFI_EXPORT
@interface WDWWiFiAdapter : RTObject
+ (void)findAllAdaptersAsyncWithSuccess:(void (^)(NSArray* /* WDWWiFiAdapter* */))success failure:(void (^)(NSError*))failure;
+ (NSString*)getDeviceSelector;
+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDWWiFiAdapter*))success failure:(void (^)(NSError*))failure;
+ (void)requestAccessAsyncWithSuccess:(void (^)(WDWWiFiAccessStatus))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WNCNetworkAdapter* networkAdapter;
@property (readonly) WDWWiFiNetworkReport* networkReport;
- (EventRegistrationToken)addAvailableNetworksChangedEvent:(void (^)(WDWWiFiAdapter*, RTObject*))del;
- (void)removeAvailableNetworksChangedEvent:(EventRegistrationToken)tok;
- (RTObject<WFIAsyncAction>*)scanAsync;
- (void)connectAsync:(WDWWiFiAvailableNetwork*)availableNetwork
    reconnectionKind:(WDWWiFiReconnectionKind)reconnectionKind
             success:(void (^)(WDWWiFiConnectionResult*))success
             failure:(void (^)(NSError*))failure;
- (void)connectWithPasswordCredentialAsync:(WDWWiFiAvailableNetwork*)availableNetwork
                          reconnectionKind:(WDWWiFiReconnectionKind)reconnectionKind
                        passwordCredential:(WSCPasswordCredential*)passwordCredential
                                   success:(void (^)(WDWWiFiConnectionResult*))success
                                   failure:(void (^)(NSError*))failure;
- (void)connectWithPasswordCredentialAndSsidAsync:(WDWWiFiAvailableNetwork*)availableNetwork
                                 reconnectionKind:(WDWWiFiReconnectionKind)reconnectionKind
                               passwordCredential:(WSCPasswordCredential*)passwordCredential
                                             ssid:(NSString*)ssid
                                          success:(void (^)(WDWWiFiConnectionResult*))success
                                          failure:(void (^)(NSError*))failure;
- (void)disconnect;
@end

#endif // __WDWWiFiAdapter_DEFINED__

// Windows.Devices.WiFi.WiFiNetworkReport
#ifndef __WDWWiFiNetworkReport_DEFINED__
#define __WDWWiFiNetworkReport_DEFINED__

OBJCUWP_WINDOWS_DEVICES_WIFI_EXPORT
@interface WDWWiFiNetworkReport : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) NSArray* /* WDWWiFiAvailableNetwork* */ availableNetworks;
@property (readonly) WFDateTime* timestamp;
@end

#endif // __WDWWiFiNetworkReport_DEFINED__

// Windows.Devices.WiFi.WiFiAvailableNetwork
#ifndef __WDWWiFiAvailableNetwork_DEFINED__
#define __WDWWiFiAvailableNetwork_DEFINED__

OBJCUWP_WINDOWS_DEVICES_WIFI_EXPORT
@interface WDWWiFiAvailableNetwork : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WFTimeSpan* beaconInterval;
@property (readonly) NSString* bssid;
@property (readonly) int channelCenterFrequencyInKilohertz;
@property (readonly) BOOL isWiFiDirect;
@property (readonly) WDWWiFiNetworkKind networkKind;
@property (readonly) double networkRssiInDecibelMilliwatts;
@property (readonly) WDWWiFiPhyKind phyKind;
@property (readonly) WNCNetworkSecuritySettings* securitySettings;
@property (readonly) uint8_t signalBars;
@property (readonly) NSString* ssid;
@property (readonly) WFTimeSpan* uptime;
@end

#endif // __WDWWiFiAvailableNetwork_DEFINED__

// Windows.Devices.WiFi.WiFiConnectionResult
#ifndef __WDWWiFiConnectionResult_DEFINED__
#define __WDWWiFiConnectionResult_DEFINED__

OBJCUWP_WINDOWS_DEVICES_WIFI_EXPORT
@interface WDWWiFiConnectionResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WDWWiFiConnectionStatus connectionStatus;
@end

#endif // __WDWWiFiConnectionResult_DEFINED__
