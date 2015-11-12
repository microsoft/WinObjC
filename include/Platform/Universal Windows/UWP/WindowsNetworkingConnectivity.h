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

// WindowsNetworkingConnectivity.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WNCIPInformation, WNCDataPlanUsage, WNCConnectionCost, WNCDataPlanStatus, WNCNetworkAdapter, WNCDataUsage,
    WNCNetworkSecuritySettings, WNCWlanConnectionProfileDetails, WNCNetworkUsage, WNCConnectivityInterval, WNCAttributedNetworkUsage,
    WNCLanIdentifierData, WNCConnectionProfile, WNCLanIdentifier, WNCProxyConfiguration, WNCConnectionProfileFilter, WNCNetworkItem,
    WNCRoutePolicy, WNCCellularApnContext, WNCConnectionSession, WNCNetworkInformation, WNCConnectivityManager,
    WNCNetworkStateChangeEventDetails, WNCWwanConnectionProfileDetails;
@class WNCNetworkUsageStates;
@protocol WNCIDataUsage
, WNCIDataPlanUsage, WNCIDataPlanStatus, WNCIConnectionCost, WNCIConnectionCost2, WNCINetworkSecuritySettings, WNCIConnectionProfile,
    WNCIWlanConnectionProfileDetails, WNCIConnectivityInterval, WNCINetworkUsage, WNCIAttributedNetworkUsage, WNCIConnectionProfile2,
    WNCIConnectionProfile3, WNCILanIdentifierData, WNCILanIdentifier, WNCINetworkInformationStatics, WNCIConnectionProfileFilter,
    WNCIConnectionProfileFilter2, WNCINetworkInformationStatics2, WNCINetworkItem, WNCINetworkAdapter, WNCIIPInformation,
    WNCIProxyConfiguration, WNCIConnectionSession, WNCIRoutePolicy, WNCIRoutePolicyFactory, WNCICellularApnContext,
    WNCIConnectivityManagerStatics, WNCINetworkStateChangeEventDetails, WNCINetworkStateChangeEventDetails2,
    WNCIWwanConnectionProfileDetails;

// Windows.Networking.Connectivity.NetworkCostType
enum _WNCNetworkCostType {
    WNCNetworkCostTypeUnknown = 0,
    WNCNetworkCostTypeUnrestricted = 1,
    WNCNetworkCostTypeFixed = 2,
    WNCNetworkCostTypeVariable = 3,
};
typedef unsigned WNCNetworkCostType;

// Windows.Networking.Connectivity.NetworkConnectivityLevel
enum _WNCNetworkConnectivityLevel {
    WNCNetworkConnectivityLevelNone = 0,
    WNCNetworkConnectivityLevelLocalAccess = 1,
    WNCNetworkConnectivityLevelConstrainedInternetAccess = 2,
    WNCNetworkConnectivityLevelInternetAccess = 3,
};
typedef unsigned WNCNetworkConnectivityLevel;

// Windows.Networking.Connectivity.NetworkTypes
enum _WNCNetworkTypes {
    WNCNetworkTypesNone = 0,
    WNCNetworkTypesInternet = 1,
    WNCNetworkTypesPrivateNetwork = 2,
};
typedef unsigned WNCNetworkTypes;

// Windows.Networking.Connectivity.RoamingStates
enum _WNCRoamingStates {
    WNCRoamingStatesNone = 0,
    WNCRoamingStatesNotRoaming = 1,
    WNCRoamingStatesRoaming = 2,
};
typedef unsigned WNCRoamingStates;

// Windows.Networking.Connectivity.NetworkAuthenticationType
enum _WNCNetworkAuthenticationType {
    WNCNetworkAuthenticationTypeNone = 0,
    WNCNetworkAuthenticationTypeUnknown = 1,
    WNCNetworkAuthenticationTypeOpen80211 = 2,
    WNCNetworkAuthenticationTypeSharedKey80211 = 3,
    WNCNetworkAuthenticationTypeWpa = 4,
    WNCNetworkAuthenticationTypeWpaPsk = 5,
    WNCNetworkAuthenticationTypeWpaNone = 6,
    WNCNetworkAuthenticationTypeRsna = 7,
    WNCNetworkAuthenticationTypeRsnaPsk = 8,
    WNCNetworkAuthenticationTypeIhv = 9,
};
typedef unsigned WNCNetworkAuthenticationType;

// Windows.Networking.Connectivity.NetworkEncryptionType
enum _WNCNetworkEncryptionType {
    WNCNetworkEncryptionTypeNone = 0,
    WNCNetworkEncryptionTypeUnknown = 1,
    WNCNetworkEncryptionTypeWep = 2,
    WNCNetworkEncryptionTypeWep40 = 3,
    WNCNetworkEncryptionTypeWep104 = 4,
    WNCNetworkEncryptionTypeTkip = 5,
    WNCNetworkEncryptionTypeCcmp = 6,
    WNCNetworkEncryptionTypeWpaUseGroup = 7,
    WNCNetworkEncryptionTypeRsnUseGroup = 8,
    WNCNetworkEncryptionTypeIhv = 9,
};
typedef unsigned WNCNetworkEncryptionType;

// Windows.Networking.Connectivity.DomainConnectivityLevel
enum _WNCDomainConnectivityLevel {
    WNCDomainConnectivityLevelNone = 0,
    WNCDomainConnectivityLevelUnauthenticated = 1,
    WNCDomainConnectivityLevelAuthenticated = 2,
};
typedef unsigned WNCDomainConnectivityLevel;

// Windows.Networking.Connectivity.DataUsageGranularity
enum _WNCDataUsageGranularity {
    WNCDataUsageGranularityPerMinute = 0,
    WNCDataUsageGranularityPerHour = 1,
    WNCDataUsageGranularityPerDay = 2,
    WNCDataUsageGranularityTotal = 3,
};
typedef unsigned WNCDataUsageGranularity;

// Windows.Networking.Connectivity.CellularApnAuthenticationType
enum _WNCCellularApnAuthenticationType {
    WNCCellularApnAuthenticationTypeNone = 0,
    WNCCellularApnAuthenticationTypePap = 1,
    WNCCellularApnAuthenticationTypeChap = 2,
    WNCCellularApnAuthenticationTypeMschapv2 = 3,
};
typedef unsigned WNCCellularApnAuthenticationType;

// Windows.Networking.Connectivity.TriStates
enum _WNCTriStates {
    WNCTriStatesDoNotCare = 0,
    WNCTriStatesNo = 1,
    WNCTriStatesYes = 2,
};
typedef unsigned WNCTriStates;

// Windows.Networking.Connectivity.WwanNetworkRegistrationState
enum _WNCWwanNetworkRegistrationState {
    WNCWwanNetworkRegistrationStateNone = 0,
    WNCWwanNetworkRegistrationStateDeregistered = 1,
    WNCWwanNetworkRegistrationStateSearching = 2,
    WNCWwanNetworkRegistrationStateHome = 3,
    WNCWwanNetworkRegistrationStateRoaming = 4,
    WNCWwanNetworkRegistrationStatePartner = 5,
    WNCWwanNetworkRegistrationStateDenied = 6,
};
typedef unsigned WNCWwanNetworkRegistrationState;

// Windows.Networking.Connectivity.WwanDataClass
enum _WNCWwanDataClass {
    WNCWwanDataClassNone = 0,
    WNCWwanDataClassGprs = 1,
    WNCWwanDataClassEdge = 2,
    WNCWwanDataClassUmts = 4,
    WNCWwanDataClassHsdpa = 8,
    WNCWwanDataClassHsupa = 16,
    WNCWwanDataClassLteAdvanced = 32,
    WNCWwanDataClassCdma1xRtt = 65536,
    WNCWwanDataClassCdma1xEvdo = 131072,
    WNCWwanDataClassCdma1xEvdoRevA = 262144,
    WNCWwanDataClassCdma1xEvdv = 524288,
    WNCWwanDataClassCdma3xRtt = 1048576,
    WNCWwanDataClassCdma1xEvdoRevB = 2097152,
    WNCWwanDataClassCdmaUmb = 4194304,
    WNCWwanDataClassCustom = -2147483648,
};
typedef unsigned WNCWwanDataClass;

#include "WindowsFoundation.h"
#include "WindowsStorageStreams.h"
#include "WindowsFoundationCollections.h"
#include "WindowsNetworking.h"
// Windows.Networking.Connectivity.NetworkStatusChangedEventHandler
#ifndef __WNCNetworkStatusChangedEventHandler__DEFINED
#define __WNCNetworkStatusChangedEventHandler__DEFINED
typedef void (^WNCNetworkStatusChangedEventHandler)(RTObject* sender);
#endif // __WNCNetworkStatusChangedEventHandler__DEFINED

#import <Foundation/Foundation.h>

// [struct] Windows.Networking.Connectivity.NetworkUsageStates
WINRT_EXPORT
@interface WNCNetworkUsageStates : NSObject
+ (instancetype) new;
@property WNCTriStates roaming;
@property WNCTriStates shared;
@end

// Windows.Networking.Connectivity.NetworkStatusChangedEventHandler
#ifndef __WNCNetworkStatusChangedEventHandler__DEFINED
#define __WNCNetworkStatusChangedEventHandler__DEFINED
typedef void (^WNCNetworkStatusChangedEventHandler)(RTObject* sender);
#endif // __WNCNetworkStatusChangedEventHandler__DEFINED

// Windows.Networking.Connectivity.IPInformation
#ifndef __WNCIPInformation_DEFINED__
#define __WNCIPInformation_DEFINED__

WINRT_EXPORT
@interface WNCIPInformation : RTObject
@property (readonly) WNCNetworkAdapter* networkAdapter;
@property (readonly) id prefixLength;
@end

#endif // __WNCIPInformation_DEFINED__

// Windows.Networking.Connectivity.DataPlanUsage
#ifndef __WNCDataPlanUsage_DEFINED__
#define __WNCDataPlanUsage_DEFINED__

WINRT_EXPORT
@interface WNCDataPlanUsage : RTObject
@property (readonly) WFDateTime* lastSyncTime;
@property (readonly) unsigned int megabytesUsed;
@end

#endif // __WNCDataPlanUsage_DEFINED__

// Windows.Networking.Connectivity.ConnectionCost
#ifndef __WNCConnectionCost_DEFINED__
#define __WNCConnectionCost_DEFINED__

WINRT_EXPORT
@interface WNCConnectionCost : RTObject
@property (readonly) BOOL approachingDataLimit;
@property (readonly) WNCNetworkCostType networkCostType;
@property (readonly) BOOL overDataLimit;
@property (readonly) BOOL roaming;
@property (readonly) BOOL backgroundDataUsageRestricted;
@end

#endif // __WNCConnectionCost_DEFINED__

// Windows.Networking.Connectivity.DataPlanStatus
#ifndef __WNCDataPlanStatus_DEFINED__
#define __WNCDataPlanStatus_DEFINED__

WINRT_EXPORT
@interface WNCDataPlanStatus : RTObject
@property (readonly) id dataLimitInMegabytes;
@property (readonly) WNCDataPlanUsage* dataPlanUsage;
@property (readonly) id inboundBitsPerSecond;
@property (readonly) id maxTransferSizeInMegabytes;
@property (readonly) id nextBillingCycle;
@property (readonly) id outboundBitsPerSecond;
@end

#endif // __WNCDataPlanStatus_DEFINED__

// Windows.Networking.Connectivity.NetworkAdapter
#ifndef __WNCNetworkAdapter_DEFINED__
#define __WNCNetworkAdapter_DEFINED__

WINRT_EXPORT
@interface WNCNetworkAdapter : RTObject
@property (readonly) unsigned int ianaInterfaceType;
@property (readonly) uint64_t inboundMaxBitsPerSecond;
@property (readonly) WFGUID* networkAdapterId;
@property (readonly) WNCNetworkItem* networkItem;
@property (readonly) uint64_t outboundMaxBitsPerSecond;
- (void)getConnectedProfileAsyncWithSuccess:(void (^)(WNCConnectionProfile*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WNCNetworkAdapter_DEFINED__

// Windows.Networking.Connectivity.DataUsage
#ifndef __WNCDataUsage_DEFINED__
#define __WNCDataUsage_DEFINED__

WINRT_EXPORT
@interface WNCDataUsage : RTObject
@property (readonly) uint64_t bytesReceived;
@property (readonly) uint64_t bytesSent;
@end

#endif // __WNCDataUsage_DEFINED__

// Windows.Networking.Connectivity.NetworkSecuritySettings
#ifndef __WNCNetworkSecuritySettings_DEFINED__
#define __WNCNetworkSecuritySettings_DEFINED__

WINRT_EXPORT
@interface WNCNetworkSecuritySettings : RTObject
@property (readonly) WNCNetworkAuthenticationType networkAuthenticationType;
@property (readonly) WNCNetworkEncryptionType networkEncryptionType;
@end

#endif // __WNCNetworkSecuritySettings_DEFINED__

// Windows.Networking.Connectivity.WlanConnectionProfileDetails
#ifndef __WNCWlanConnectionProfileDetails_DEFINED__
#define __WNCWlanConnectionProfileDetails_DEFINED__

WINRT_EXPORT
@interface WNCWlanConnectionProfileDetails : RTObject
- (NSString*)getConnectedSsid;
@end

#endif // __WNCWlanConnectionProfileDetails_DEFINED__

// Windows.Networking.Connectivity.NetworkUsage
#ifndef __WNCNetworkUsage_DEFINED__
#define __WNCNetworkUsage_DEFINED__

WINRT_EXPORT
@interface WNCNetworkUsage : RTObject
@property (readonly) uint64_t bytesReceived;
@property (readonly) uint64_t bytesSent;
@property (readonly) WFTimeSpan* connectionDuration;
@end

#endif // __WNCNetworkUsage_DEFINED__

// Windows.Networking.Connectivity.ConnectivityInterval
#ifndef __WNCConnectivityInterval_DEFINED__
#define __WNCConnectivityInterval_DEFINED__

WINRT_EXPORT
@interface WNCConnectivityInterval : RTObject
@property (readonly) WFTimeSpan* connectionDuration;
@property (readonly) WFDateTime* startTime;
@end

#endif // __WNCConnectivityInterval_DEFINED__

// Windows.Networking.Connectivity.AttributedNetworkUsage
#ifndef __WNCAttributedNetworkUsage_DEFINED__
#define __WNCAttributedNetworkUsage_DEFINED__

WINRT_EXPORT
@interface WNCAttributedNetworkUsage : RTObject
@property (readonly) NSString* attributionId;
@property (readonly) NSString* attributionName;
@property (readonly) RTObject<WSSIRandomAccessStreamReference>* attributionThumbnail;
@property (readonly) uint64_t bytesReceived;
@property (readonly) uint64_t bytesSent;
@end

#endif // __WNCAttributedNetworkUsage_DEFINED__

// Windows.Networking.Connectivity.LanIdentifierData
#ifndef __WNCLanIdentifierData_DEFINED__
#define __WNCLanIdentifierData_DEFINED__

WINRT_EXPORT
@interface WNCLanIdentifierData : RTObject
@property (readonly) unsigned int type;
@property (readonly) NSArray* value;
@end

#endif // __WNCLanIdentifierData_DEFINED__

// Windows.Networking.Connectivity.ConnectionProfile
#ifndef __WNCConnectionProfile_DEFINED__
#define __WNCConnectionProfile_DEFINED__

WINRT_EXPORT
@interface WNCConnectionProfile : RTObject
@property (readonly) WNCNetworkAdapter* networkAdapter;
@property (readonly) WNCNetworkSecuritySettings* networkSecuritySettings;
@property (readonly) NSString* profileName;
@property (readonly) BOOL isWlanConnectionProfile;
@property (readonly) BOOL isWwanConnectionProfile;
@property (readonly) id serviceProviderGuid;
@property (readonly) WNCWlanConnectionProfileDetails* wlanConnectionProfileDetails;
@property (readonly) WNCWwanConnectionProfileDetails* wwanConnectionProfileDetails;
- (WNCNetworkConnectivityLevel)getNetworkConnectivityLevel;
- (NSArray*)getNetworkNames;
- (WNCConnectionCost*)getConnectionCost;
- (WNCDataPlanStatus*)getDataPlanStatus;
- (WNCDataUsage*)getLocalUsage:(WFDateTime*)StartTime EndTime:(WFDateTime*)EndTime;
- (WNCDataUsage*)getLocalUsagePerRoamingStates:(WFDateTime*)StartTime EndTime:(WFDateTime*)EndTime States:(WNCRoamingStates)States;
- (id)getSignalBars;
- (WNCDomainConnectivityLevel)getDomainConnectivityLevel;
- (void)getNetworkUsageAsync:(WFDateTime*)startTime
                     endTime:(WFDateTime*)endTime
                 granularity:(WNCDataUsageGranularity)granularity
                      states:(WNCNetworkUsageStates*)states
                     success:(void (^)(NSArray*))success
                     failure:(void (^)(NSError*))failure;
- (void)getConnectivityIntervalsAsync:(WFDateTime*)startTime
                              endTime:(WFDateTime*)endTime
                               states:(WNCNetworkUsageStates*)states
                              success:(void (^)(NSArray*))success
                              failure:(void (^)(NSError*))failure;
- (void)getAttributedNetworkUsageAsync:(WFDateTime*)startTime
                               endTime:(WFDateTime*)endTime
                                states:(WNCNetworkUsageStates*)states
                               success:(void (^)(NSArray*))success
                               failure:(void (^)(NSError*))failure;
@end

#endif // __WNCConnectionProfile_DEFINED__

// Windows.Networking.Connectivity.LanIdentifier
#ifndef __WNCLanIdentifier_DEFINED__
#define __WNCLanIdentifier_DEFINED__

WINRT_EXPORT
@interface WNCLanIdentifier : RTObject
@property (readonly) WNCLanIdentifierData* infrastructureId;
@property (readonly) WFGUID* networkAdapterId;
@property (readonly) WNCLanIdentifierData* portId;
@end

#endif // __WNCLanIdentifier_DEFINED__

// Windows.Networking.Connectivity.ProxyConfiguration
#ifndef __WNCProxyConfiguration_DEFINED__
#define __WNCProxyConfiguration_DEFINED__

WINRT_EXPORT
@interface WNCProxyConfiguration : RTObject
@property (readonly) BOOL canConnectDirectly;
@property (readonly) NSArray* proxyUris;
@end

#endif // __WNCProxyConfiguration_DEFINED__

// Windows.Networking.Connectivity.ConnectionProfileFilter
#ifndef __WNCConnectionProfileFilter_DEFINED__
#define __WNCConnectionProfileFilter_DEFINED__

WINRT_EXPORT
@interface WNCConnectionProfileFilter : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) id serviceProviderGuid;
@property WNCNetworkCostType networkCostType;
@property BOOL isWwanConnectionProfile;
@property BOOL isWlanConnectionProfile;
@property BOOL isConnected;
@property (copy) id isRoaming;
@property (copy) id isOverDataLimit;
@property (copy) id isBackgroundDataUsageRestricted;
@property (readonly) RTObject<WSSIBuffer>* rawData;
@end

#endif // __WNCConnectionProfileFilter_DEFINED__

// Windows.Networking.Connectivity.NetworkItem
#ifndef __WNCNetworkItem_DEFINED__
#define __WNCNetworkItem_DEFINED__

WINRT_EXPORT
@interface WNCNetworkItem : RTObject
@property (readonly) WFGUID* networkId;
- (WNCNetworkTypes)getNetworkTypes;
@end

#endif // __WNCNetworkItem_DEFINED__

// Windows.Networking.Connectivity.RoutePolicy
#ifndef __WNCRoutePolicy_DEFINED__
#define __WNCRoutePolicy_DEFINED__

WINRT_EXPORT
@interface WNCRoutePolicy : RTObject
+ (WNCRoutePolicy*)createRoutePolicy:(WNCConnectionProfile*)connectionProfile
                            hostName:(WNHostName*)hostName
                                type:(WNDomainNameType)type ACTIVATOR;
@property (readonly) WNCConnectionProfile* connectionProfile;
@property (readonly) WNHostName* hostName;
@property (readonly) WNDomainNameType hostNameType;
@end

#endif // __WNCRoutePolicy_DEFINED__

// Windows.Networking.Connectivity.CellularApnContext
#ifndef __WNCCellularApnContext_DEFINED__
#define __WNCCellularApnContext_DEFINED__

WINRT_EXPORT
@interface WNCCellularApnContext : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* userName;
@property (copy) NSString* providerId;
@property (copy) NSString* password;
@property BOOL isCompressionEnabled;
@property WNCCellularApnAuthenticationType authenticationType;
@property (copy) NSString* accessPointName;
@end

#endif // __WNCCellularApnContext_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

#endif // __WFIClosable_DEFINED__

// Windows.Networking.Connectivity.ConnectionSession
#ifndef __WNCConnectionSession_DEFINED__
#define __WNCConnectionSession_DEFINED__

WINRT_EXPORT
@interface WNCConnectionSession : RTObject <WFIClosable>
@property (readonly) WNCConnectionProfile* connectionProfile;
- (void)close;
@end

#endif // __WNCConnectionSession_DEFINED__

// Windows.Networking.Connectivity.NetworkInformation
#ifndef __WNCNetworkInformation_DEFINED__
#define __WNCNetworkInformation_DEFINED__

WINRT_EXPORT
@interface WNCNetworkInformation : RTObject
+ (void)findConnectionProfilesAsync:(WNCConnectionProfileFilter*)pProfileFilter
                            success:(void (^)(NSArray*))success
                            failure:(void (^)(NSError*))failure;
+ (NSArray*)getConnectionProfiles;
+ (WNCConnectionProfile*)getInternetConnectionProfile;
+ (NSArray*)getLanIdentifiers;
+ (NSArray*)getHostNames;
+ (void)getProxyConfigurationAsync:(WFUri*)uri success:(void (^)(WNCProxyConfiguration*))success failure:(void (^)(NSError*))failure;
+ (NSArray*)getSortedEndpointPairs:(id<NSFastEnumeration> /* WNEndpointPair* */)destinationList
                       sortOptions:(WNHostNameSortOptions)sortOptions;
+ (EventRegistrationToken)addNetworkStatusChangedEvent:(WNCNetworkStatusChangedEventHandler)del;
+ (void)removeNetworkStatusChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WNCNetworkInformation_DEFINED__

// Windows.Networking.Connectivity.ConnectivityManager
#ifndef __WNCConnectivityManager_DEFINED__
#define __WNCConnectivityManager_DEFINED__

WINRT_EXPORT
@interface WNCConnectivityManager : RTObject
+ (void)acquireConnectionAsync:(WNCCellularApnContext*)cellularApnContext
                       success:(void (^)(WNCConnectionSession*))success
                       failure:(void (^)(NSError*))failure;
+ (void)addHttpRoutePolicy:(WNCRoutePolicy*)routePolicy;
+ (void)removeHttpRoutePolicy:(WNCRoutePolicy*)routePolicy;
@end

#endif // __WNCConnectivityManager_DEFINED__

// Windows.Networking.Connectivity.NetworkStateChangeEventDetails
#ifndef __WNCNetworkStateChangeEventDetails_DEFINED__
#define __WNCNetworkStateChangeEventDetails_DEFINED__

WINRT_EXPORT
@interface WNCNetworkStateChangeEventDetails : RTObject
@property (readonly) BOOL hasNewConnectionCost;
@property (readonly) BOOL hasNewDomainConnectivityLevel;
@property (readonly) BOOL hasNewHostNameList;
@property (readonly) BOOL hasNewInternetConnectionProfile;
@property (readonly) BOOL hasNewNetworkConnectivityLevel;
@property (readonly) BOOL hasNewWwanRegistrationState;
@property (readonly) BOOL hasNewTetheringClientCount;
@property (readonly) BOOL hasNewTetheringOperationalState;
@end

#endif // __WNCNetworkStateChangeEventDetails_DEFINED__

// Windows.Networking.Connectivity.WwanConnectionProfileDetails
#ifndef __WNCWwanConnectionProfileDetails_DEFINED__
#define __WNCWwanConnectionProfileDetails_DEFINED__

WINRT_EXPORT
@interface WNCWwanConnectionProfileDetails : RTObject
@property (readonly) NSString* accessPointName;
@property (readonly) NSString* homeProviderId;
- (WNCWwanNetworkRegistrationState)getNetworkRegistrationState;
- (WNCWwanDataClass)getCurrentDataClass;
@end

#endif // __WNCWwanConnectionProfileDetails_DEFINED__
