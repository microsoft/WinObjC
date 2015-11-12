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

// WindowsNetworkingNetworkOperators.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WNNMobileBroadbandAccount, WNNMobileBroadbandNetwork, WNNMobileBroadbandDeviceInformation, WNNMobileBroadbandPinManager,
    WNNMobileBroadbandUiccApp, WNNNetworkOperatorTetheringAccessPointConfiguration, WNNNetworkOperatorTetheringOperationResult,
    WNNNetworkOperatorTetheringManager, WNNNetworkOperatorTetheringClient, WNNMobileBroadbandAccountEventArgs,
    WNNMobileBroadbandAccountUpdatedEventArgs, WNNMobileBroadbandAccountWatcher, WNNMobileBroadbandModem, WNNMobileBroadbandUicc,
    WNNMobileBroadbandModemConfiguration, WNNMobileBroadbandDeviceServiceInformation, WNNMobileBroadbandDeviceService,
    WNNMobileBroadbandPin, WNNMobileBroadbandPinOperationResult, WNNMobileBroadbandDeviceServiceDataSession,
    WNNMobileBroadbandDeviceServiceCommandSession, WNNMobileBroadbandDeviceServiceDataReceivedEventArgs,
    WNNMobileBroadbandDeviceServiceCommandResult, WNNMobileBroadbandUiccAppsResult, WNNMobileBroadbandUiccAppRecordDetailsResult,
    WNNMobileBroadbandUiccAppReadRecordResult, WNNMobileBroadbandNetworkRegistrationStateChange,
    WNNMobileBroadbandNetworkRegistrationStateChangeTriggerDetails, WNNMobileBroadbandRadioStateChange,
    WNNMobileBroadbandRadioStateChangeTriggerDetails, WNNMobileBroadbandPinLockStateChange,
    WNNMobileBroadbandPinLockStateChangeTriggerDetails, WNNMobileBroadbandDeviceServiceTriggerDetails, WNNKnownCSimFilePaths,
    WNNKnownRuimFilePaths, WNNKnownSimFilePaths, WNNKnownUSimFilePaths, WNNHotspotAuthenticationEventDetails,
    WNNHotspotAuthenticationContext, WNNHotspotCredentialsAuthenticationResult, WNNProvisionFromXmlDocumentResults, WNNProvisionedProfile,
    WNNProvisioningAgent, WNNUssdMessage, WNNUssdReply, WNNUssdSession;
@class WNNProfileUsage;
@protocol WNNIMobileBroadbandAccountStatics
, WNNIMobileBroadbandAccount, WNNIMobileBroadbandAccount2, WNNIMobileBroadbandDeviceInformation, WNNIMobileBroadbandDeviceInformation2,
    WNNIMobileBroadbandNetwork, WNNIMobileBroadbandNetwork2, WNNINetworkOperatorTetheringAccessPointConfiguration,
    WNNINetworkOperatorTetheringOperationResult, WNNINetworkOperatorTetheringManagerStatics, WNNINetworkOperatorTetheringManagerStatics2,
    WNNINetworkOperatorTetheringManager, WNNINetworkOperatorTetheringClient, WNNINetworkOperatorTetheringClientManager,
    WNNIMobileBroadbandAccountEventArgs, WNNIMobileBroadbandAccountUpdatedEventArgs, WNNIMobileBroadbandAccountWatcher,
    WNNIMobileBroadbandModemStatics, WNNIMobileBroadbandModemConfiguration, WNNIMobileBroadbandModem, WNNIMobileBroadbandPinManager,
    WNNIMobileBroadbandPinOperationResult, WNNIMobileBroadbandPin, WNNIMobileBroadbandDeviceServiceInformation,
    WNNIMobileBroadbandDeviceService, WNNIMobileBroadbandDeviceServiceDataReceivedEventArgs, WNNIMobileBroadbandDeviceServiceDataSession,
    WNNIMobileBroadbandDeviceServiceCommandResult, WNNIMobileBroadbandDeviceServiceCommandSession, WNNIMobileBroadbandUiccAppsResult,
    WNNIMobileBroadbandUicc, WNNIMobileBroadbandUiccAppRecordDetailsResult, WNNIMobileBroadbandUiccAppReadRecordResult,
    WNNIMobileBroadbandUiccApp, WNNIMobileBroadbandNetworkRegistrationStateChange,
    WNNIMobileBroadbandNetworkRegistrationStateChangeTriggerDetails, WNNIMobileBroadbandRadioStateChange,
    WNNIMobileBroadbandRadioStateChangeTriggerDetails, WNNIMobileBroadbandPinLockStateChange,
    WNNIMobileBroadbandPinLockStateChangeTriggerDetails, WNNIMobileBroadbandDeviceServiceTriggerDetails, WNNIKnownCSimFilePathsStatics,
    WNNIKnownRuimFilePathsStatics, WNNIKnownSimFilePathsStatics, WNNIKnownUSimFilePathsStatics, WNNIHotspotAuthenticationEventDetails,
    WNNIHotspotAuthenticationContextStatics, WNNIHotspotAuthenticationContext, WNNIHotspotCredentialsAuthenticationResult,
    WNNIHotspotAuthenticationContext2, WNNIProvisionFromXmlDocumentResults, WNNIProvisionedProfile, WNNIProvisioningAgent,
    WNNIProvisioningAgentStaticMethods, WNNIUssdMessage, WNNIUssdMessageFactory, WNNIUssdReply, WNNIUssdSession, WNNIUssdSessionStatics;

// Windows.Networking.NetworkOperators.DataClasses
enum _WNNDataClasses {
    WNNDataClassesNone = 0,
    WNNDataClassesGprs = 1,
    WNNDataClassesEdge = 2,
    WNNDataClassesUmts = 4,
    WNNDataClassesHsdpa = 8,
    WNNDataClassesHsupa = 16,
    WNNDataClassesLteAdvanced = 32,
    WNNDataClassesCdma1xRtt = 65536,
    WNNDataClassesCdma1xEvdo = 131072,
    WNNDataClassesCdma1xEvdoRevA = 262144,
    WNNDataClassesCdma1xEvdv = 524288,
    WNNDataClassesCdma3xRtt = 1048576,
    WNNDataClassesCdma1xEvdoRevB = 2097152,
    WNNDataClassesCdmaUmb = 4194304,
    WNNDataClassesCustom = -2147483648,
};
typedef unsigned WNNDataClasses;

// Windows.Networking.NetworkOperators.MobileBroadbandDeviceType
enum _WNNMobileBroadbandDeviceType {
    WNNMobileBroadbandDeviceTypeUnknown = 0,
    WNNMobileBroadbandDeviceTypeEmbedded = 1,
    WNNMobileBroadbandDeviceTypeRemovable = 2,
    WNNMobileBroadbandDeviceTypeRemote = 3,
};
typedef unsigned WNNMobileBroadbandDeviceType;

// Windows.Networking.NetworkOperators.NetworkDeviceStatus
enum _WNNNetworkDeviceStatus {
    WNNNetworkDeviceStatusDeviceNotReady = 0,
    WNNNetworkDeviceStatusDeviceReady = 1,
    WNNNetworkDeviceStatusSimNotInserted = 2,
    WNNNetworkDeviceStatusBadSim = 3,
    WNNNetworkDeviceStatusDeviceHardwareFailure = 4,
    WNNNetworkDeviceStatusAccountNotActivated = 5,
    WNNNetworkDeviceStatusDeviceLocked = 6,
    WNNNetworkDeviceStatusDeviceBlocked = 7,
};
typedef unsigned WNNNetworkDeviceStatus;

// Windows.Networking.NetworkOperators.NetworkRegistrationState
enum _WNNNetworkRegistrationState {
    WNNNetworkRegistrationStateNone = 0,
    WNNNetworkRegistrationStateDeregistered = 1,
    WNNNetworkRegistrationStateSearching = 2,
    WNNNetworkRegistrationStateHome = 3,
    WNNNetworkRegistrationStateRoaming = 4,
    WNNNetworkRegistrationStatePartner = 5,
    WNNNetworkRegistrationStateDenied = 6,
};
typedef unsigned WNNNetworkRegistrationState;

// Windows.Networking.NetworkOperators.MobileBroadbandRadioState
enum _WNNMobileBroadbandRadioState {
    WNNMobileBroadbandRadioStateOff = 0,
    WNNMobileBroadbandRadioStateOn = 1,
};
typedef unsigned WNNMobileBroadbandRadioState;

// Windows.Networking.NetworkOperators.NetworkOperatorEventMessageType
enum _WNNNetworkOperatorEventMessageType {
    WNNNetworkOperatorEventMessageTypeGsm = 0,
    WNNNetworkOperatorEventMessageTypeCdma = 1,
    WNNNetworkOperatorEventMessageTypeUssd = 2,
    WNNNetworkOperatorEventMessageTypeDataPlanThresholdReached = 3,
    WNNNetworkOperatorEventMessageTypeDataPlanReset = 4,
    WNNNetworkOperatorEventMessageTypeDataPlanDeleted = 5,
    WNNNetworkOperatorEventMessageTypeProfileConnected = 6,
    WNNNetworkOperatorEventMessageTypeProfileDisconnected = 7,
    WNNNetworkOperatorEventMessageTypeRegisteredRoaming = 8,
    WNNNetworkOperatorEventMessageTypeRegisteredHome = 9,
    WNNNetworkOperatorEventMessageTypeTetheringEntitlementCheck = 10,
    WNNNetworkOperatorEventMessageTypeTetheringOperationalStateChanged = 11,
    WNNNetworkOperatorEventMessageTypeTetheringNumberOfClientsChanged = 12,
};
typedef unsigned WNNNetworkOperatorEventMessageType;

// Windows.Networking.NetworkOperators.MobileBroadbandAccountWatcherStatus
enum _WNNMobileBroadbandAccountWatcherStatus {
    WNNMobileBroadbandAccountWatcherStatusCreated = 0,
    WNNMobileBroadbandAccountWatcherStatusStarted = 1,
    WNNMobileBroadbandAccountWatcherStatusEnumerationCompleted = 2,
    WNNMobileBroadbandAccountWatcherStatusStopped = 3,
    WNNMobileBroadbandAccountWatcherStatusAborted = 4,
};
typedef unsigned WNNMobileBroadbandAccountWatcherStatus;

// Windows.Networking.NetworkOperators.TetheringOperationalState
enum _WNNTetheringOperationalState {
    WNNTetheringOperationalStateUnknown = 0,
    WNNTetheringOperationalStateOn = 1,
    WNNTetheringOperationalStateOff = 2,
    WNNTetheringOperationalStateInTransition = 3,
};
typedef unsigned WNNTetheringOperationalState;

// Windows.Networking.NetworkOperators.TetheringCapability
enum _WNNTetheringCapability {
    WNNTetheringCapabilityEnabled = 0,
    WNNTetheringCapabilityDisabledByGroupPolicy = 1,
    WNNTetheringCapabilityDisabledByHardwareLimitation = 2,
    WNNTetheringCapabilityDisabledByOperator = 3,
    WNNTetheringCapabilityDisabledBySku = 4,
    WNNTetheringCapabilityDisabledByRequiredAppNotInstalled = 5,
    WNNTetheringCapabilityDisabledDueToUnknownCause = 6,
    WNNTetheringCapabilityDisabledBySystemCapability = 7,
};
typedef unsigned WNNTetheringCapability;

// Windows.Networking.NetworkOperators.TetheringOperationStatus
enum _WNNTetheringOperationStatus {
    WNNTetheringOperationStatusSuccess = 0,
    WNNTetheringOperationStatusUnknown = 1,
    WNNTetheringOperationStatusMobileBroadbandDeviceOff = 2,
    WNNTetheringOperationStatusWiFiDeviceOff = 3,
    WNNTetheringOperationStatusEntitlementCheckTimeout = 4,
    WNNTetheringOperationStatusEntitlementCheckFailure = 5,
    WNNTetheringOperationStatusOperationInProgress = 6,
};
typedef unsigned WNNTetheringOperationStatus;

// Windows.Networking.NetworkOperators.MobileBroadbandPinLockState
enum _WNNMobileBroadbandPinLockState {
    WNNMobileBroadbandPinLockStateUnknown = 0,
    WNNMobileBroadbandPinLockStateUnlocked = 1,
    WNNMobileBroadbandPinLockStatePinRequired = 2,
    WNNMobileBroadbandPinLockStatePinUnblockKeyRequired = 3,
};
typedef unsigned WNNMobileBroadbandPinLockState;

// Windows.Networking.NetworkOperators.MobileBroadbandPinType
enum _WNNMobileBroadbandPinType {
    WNNMobileBroadbandPinTypeNone = 0,
    WNNMobileBroadbandPinTypeCustom = 1,
    WNNMobileBroadbandPinTypePin1 = 2,
    WNNMobileBroadbandPinTypePin2 = 3,
    WNNMobileBroadbandPinTypeSimPin = 4,
    WNNMobileBroadbandPinTypeFirstSimPin = 5,
    WNNMobileBroadbandPinTypeNetworkPin = 6,
    WNNMobileBroadbandPinTypeNetworkSubsetPin = 7,
    WNNMobileBroadbandPinTypeServiceProviderPin = 8,
    WNNMobileBroadbandPinTypeCorporatePin = 9,
    WNNMobileBroadbandPinTypeSubsidyLock = 10,
};
typedef unsigned WNNMobileBroadbandPinType;

// Windows.Networking.NetworkOperators.MobileBroadbandPinFormat
enum _WNNMobileBroadbandPinFormat {
    WNNMobileBroadbandPinFormatUnknown = 0,
    WNNMobileBroadbandPinFormatNumeric = 1,
    WNNMobileBroadbandPinFormatAlphanumeric = 2,
};
typedef unsigned WNNMobileBroadbandPinFormat;

// Windows.Networking.NetworkOperators.MobileBroadbandUiccAppOperationStatus
enum _WNNMobileBroadbandUiccAppOperationStatus {
    WNNMobileBroadbandUiccAppOperationStatusSuccess = 0,
    WNNMobileBroadbandUiccAppOperationStatusInvalidUiccFilePath = 1,
    WNNMobileBroadbandUiccAppOperationStatusAccessConditionNotHeld = 2,
    WNNMobileBroadbandUiccAppOperationStatusUiccBusy = 3,
};
typedef unsigned WNNMobileBroadbandUiccAppOperationStatus;

// Windows.Networking.NetworkOperators.UiccAppKind
enum _WNNUiccAppKind {
    WNNUiccAppKindUnknown = 0,
    WNNUiccAppKindMF = 1,
    WNNUiccAppKindMFSim = 2,
    WNNUiccAppKindMFRuim = 3,
    WNNUiccAppKindUSim = 4,
    WNNUiccAppKindCSim = 5,
    WNNUiccAppKindISim = 6,
};
typedef unsigned WNNUiccAppKind;

// Windows.Networking.NetworkOperators.UiccAppRecordKind
enum _WNNUiccAppRecordKind {
    WNNUiccAppRecordKindUnknown = 0,
    WNNUiccAppRecordKindTransparent = 1,
    WNNUiccAppRecordKindRecordOriented = 2,
};
typedef unsigned WNNUiccAppRecordKind;

// Windows.Networking.NetworkOperators.UiccAccessCondition
enum _WNNUiccAccessCondition {
    WNNUiccAccessConditionAlwaysAllowed = 0,
    WNNUiccAccessConditionPin1 = 1,
    WNNUiccAccessConditionPin2 = 2,
    WNNUiccAccessConditionPin3 = 3,
    WNNUiccAccessConditionPin4 = 4,
    WNNUiccAccessConditionAdministrative5 = 5,
    WNNUiccAccessConditionAdministrative6 = 6,
    WNNUiccAccessConditionNeverAllowed = 7,
};
typedef unsigned WNNUiccAccessCondition;

// Windows.Networking.NetworkOperators.HotspotAuthenticationResponseCode
enum _WNNHotspotAuthenticationResponseCode {
    WNNHotspotAuthenticationResponseCodeNoError = 0,
    WNNHotspotAuthenticationResponseCodeLoginSucceeded = 50,
    WNNHotspotAuthenticationResponseCodeLoginFailed = 100,
    WNNHotspotAuthenticationResponseCodeRadiusServerError = 102,
    WNNHotspotAuthenticationResponseCodeNetworkAdministratorError = 105,
    WNNHotspotAuthenticationResponseCodeLoginAborted = 151,
    WNNHotspotAuthenticationResponseCodeAccessGatewayInternalError = 255,
};
typedef unsigned WNNHotspotAuthenticationResponseCode;

// Windows.Networking.NetworkOperators.ProfileMediaType
enum _WNNProfileMediaType {
    WNNProfileMediaTypeWlan = 0,
    WNNProfileMediaTypeWwan = 1,
};
typedef unsigned WNNProfileMediaType;

// Windows.Networking.NetworkOperators.UssdResultCode
enum _WNNUssdResultCode {
    WNNUssdResultCodeNoActionRequired = 0,
    WNNUssdResultCodeActionRequired = 1,
    WNNUssdResultCodeTerminated = 2,
    WNNUssdResultCodeOtherLocalClient = 3,
    WNNUssdResultCodeOperationNotSupported = 4,
    WNNUssdResultCodeNetworkTimeout = 5,
};
typedef unsigned WNNUssdResultCode;

#include "WindowsNetworkingConnectivity.h"
#include "WindowsStorageStreams.h"
#include "WindowsDevicesSms.h"
#include "WindowsFoundationCollections.h"
#include "WindowsFoundation.h"
#include "WindowsNetworking.h"
#include "WindowsDataXmlDom.h"

#import <Foundation/Foundation.h>

// [struct] Windows.Networking.NetworkOperators.ProfileUsage
WINRT_EXPORT
@interface WNNProfileUsage : NSObject
+ (instancetype) new;
@property unsigned int usageInMegabytes;
@property (copy) WFDateTime* lastSyncTime;
@end

// Windows.Networking.NetworkOperators.MobileBroadbandAccount
#ifndef __WNNMobileBroadbandAccount_DEFINED__
#define __WNNMobileBroadbandAccount_DEFINED__

WINRT_EXPORT
@interface WNNMobileBroadbandAccount : RTObject
+ (WNNMobileBroadbandAccount*)createFromNetworkAccountId:(NSString*)networkAccountId;
@property (readonly) WNNMobileBroadbandDeviceInformation* currentDeviceInformation;
@property (readonly) WNNMobileBroadbandNetwork* currentNetwork;
@property (readonly) NSString* networkAccountId;
@property (readonly) WFGUID* serviceProviderGuid;
@property (readonly) NSString* serviceProviderName;
+ (NSArray*)availableNetworkAccountIds;
- (NSArray*)getConnectionProfiles;
@end

#endif // __WNNMobileBroadbandAccount_DEFINED__

// Windows.Networking.NetworkOperators.MobileBroadbandNetwork
#ifndef __WNNMobileBroadbandNetwork_DEFINED__
#define __WNNMobileBroadbandNetwork_DEFINED__

WINRT_EXPORT
@interface WNNMobileBroadbandNetwork : RTObject
@property (readonly) NSString* accessPointName;
@property (readonly) unsigned int activationNetworkError;
@property (readonly) WNCNetworkAdapter* networkAdapter;
@property (readonly) WNNNetworkRegistrationState networkRegistrationState;
@property (readonly) unsigned int packetAttachNetworkError;
@property (readonly) WNNDataClasses registeredDataClass;
@property (readonly) NSString* registeredProviderId;
@property (readonly) NSString* registeredProviderName;
@property (readonly) unsigned int registrationNetworkError;
@property (readonly) NSArray* registrationUiccApps;
- (void)showConnectionUI;
- (void)getVoiceCallSupportAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WNNMobileBroadbandNetwork_DEFINED__

// Windows.Networking.NetworkOperators.MobileBroadbandDeviceInformation
#ifndef __WNNMobileBroadbandDeviceInformation_DEFINED__
#define __WNNMobileBroadbandDeviceInformation_DEFINED__

WINRT_EXPORT
@interface WNNMobileBroadbandDeviceInformation : RTObject
@property (readonly) WDSCellularClass cellularClass;
@property (readonly) WNNMobileBroadbandRadioState currentRadioState;
@property (readonly) NSString* customDataClass;
@property (readonly) WNNDataClasses dataClasses;
@property (readonly) NSString* deviceId;
@property (readonly) WNNMobileBroadbandDeviceType deviceType;
@property (readonly) NSString* firmwareInformation;
@property (readonly) NSString* manufacturer;
@property (readonly) NSString* mobileEquipmentId;
@property (readonly) NSString* model;
@property (readonly) WNNNetworkDeviceStatus networkDeviceStatus;
@property (readonly) NSString* simIccId;
@property (readonly) NSString* subscriberId;
@property (readonly) NSArray* telephoneNumbers;
@property (readonly) WNNMobileBroadbandPinManager* pinManager;
@property (readonly) NSString* revision;
@property (readonly) NSString* serialNumber;
@end

#endif // __WNNMobileBroadbandDeviceInformation_DEFINED__

// Windows.Networking.NetworkOperators.MobileBroadbandPinManager
#ifndef __WNNMobileBroadbandPinManager_DEFINED__
#define __WNNMobileBroadbandPinManager_DEFINED__

WINRT_EXPORT
@interface WNNMobileBroadbandPinManager : RTObject
@property (readonly) NSArray* supportedPins;
- (WNNMobileBroadbandPin*)getPin:(WNNMobileBroadbandPinType)pinType;
@end

#endif // __WNNMobileBroadbandPinManager_DEFINED__

// Windows.Networking.NetworkOperators.MobileBroadbandUiccApp
#ifndef __WNNMobileBroadbandUiccApp_DEFINED__
#define __WNNMobileBroadbandUiccApp_DEFINED__

WINRT_EXPORT
@interface WNNMobileBroadbandUiccApp : RTObject
@property (readonly) RTObject<WSSIBuffer>* id;
@property (readonly) WNNUiccAppKind kind;
- (void)getRecordDetailsAsync:(id<NSFastEnumeration> /* unsigned int */)uiccFilePath
                      success:(void (^)(WNNMobileBroadbandUiccAppRecordDetailsResult*))success
                      failure:(void (^)(NSError*))failure;
- (void)readRecordAsync:(id<NSFastEnumeration> /* unsigned int */)uiccFilePath
            recordIndex:(int)recordIndex
                success:(void (^)(WNNMobileBroadbandUiccAppReadRecordResult*))success
                failure:(void (^)(NSError*))failure;
@end

#endif // __WNNMobileBroadbandUiccApp_DEFINED__

// Windows.Networking.NetworkOperators.NetworkOperatorTetheringAccessPointConfiguration
#ifndef __WNNNetworkOperatorTetheringAccessPointConfiguration_DEFINED__
#define __WNNNetworkOperatorTetheringAccessPointConfiguration_DEFINED__

WINRT_EXPORT
@interface WNNNetworkOperatorTetheringAccessPointConfiguration : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* ssid;
@property (copy) NSString* passphrase;
@end

#endif // __WNNNetworkOperatorTetheringAccessPointConfiguration_DEFINED__

// Windows.Networking.NetworkOperators.NetworkOperatorTetheringOperationResult
#ifndef __WNNNetworkOperatorTetheringOperationResult_DEFINED__
#define __WNNNetworkOperatorTetheringOperationResult_DEFINED__

WINRT_EXPORT
@interface WNNNetworkOperatorTetheringOperationResult : RTObject
@property (readonly) NSString* additionalErrorMessage;
@property (readonly) WNNTetheringOperationStatus status;
@end

#endif // __WNNNetworkOperatorTetheringOperationResult_DEFINED__

// Windows.Networking.NetworkOperators.NetworkOperatorTetheringManager
#ifndef __WNNNetworkOperatorTetheringManager_DEFINED__
#define __WNNNetworkOperatorTetheringManager_DEFINED__

WINRT_EXPORT
@interface WNNNetworkOperatorTetheringManager : RTObject
+ (WNNTetheringCapability)getTetheringCapability:(NSString*)networkAccountId;
+ (WNNNetworkOperatorTetheringManager*)createFromNetworkAccountId:(NSString*)networkAccountId;
+ (WNNTetheringCapability)getTetheringCapabilityFromConnectionProfile:(WNCConnectionProfile*)profile;
+ (WNNNetworkOperatorTetheringManager*)createFromConnectionProfile:(WNCConnectionProfile*)profile;
@property (readonly) unsigned int clientCount;
@property (readonly) unsigned int maxClientCount;
@property (readonly) WNNTetheringOperationalState tetheringOperationalState;
- (WNNNetworkOperatorTetheringAccessPointConfiguration*)getCurrentAccessPointConfiguration;
- (RTObject<WFIAsyncAction>*)configureAccessPointAsync:(WNNNetworkOperatorTetheringAccessPointConfiguration*)configuration;
- (void)startTetheringAsyncWithSuccess:(void (^)(WNNNetworkOperatorTetheringOperationResult*))success failure:(void (^)(NSError*))failure;
- (void)stopTetheringAsyncWithSuccess:(void (^)(WNNNetworkOperatorTetheringOperationResult*))success failure:(void (^)(NSError*))failure;
- (NSArray*)getTetheringClients;
@end

#endif // __WNNNetworkOperatorTetheringManager_DEFINED__

// Windows.Networking.NetworkOperators.NetworkOperatorTetheringClient
#ifndef __WNNNetworkOperatorTetheringClient_DEFINED__
#define __WNNNetworkOperatorTetheringClient_DEFINED__

WINRT_EXPORT
@interface WNNNetworkOperatorTetheringClient : RTObject
@property (readonly) NSArray* hostNames;
@property (readonly) NSString* macAddress;
@end

#endif // __WNNNetworkOperatorTetheringClient_DEFINED__

// Windows.Networking.NetworkOperators.MobileBroadbandAccountEventArgs
#ifndef __WNNMobileBroadbandAccountEventArgs_DEFINED__
#define __WNNMobileBroadbandAccountEventArgs_DEFINED__

WINRT_EXPORT
@interface WNNMobileBroadbandAccountEventArgs : RTObject
@property (readonly) NSString* networkAccountId;
@end

#endif // __WNNMobileBroadbandAccountEventArgs_DEFINED__

// Windows.Networking.NetworkOperators.MobileBroadbandAccountUpdatedEventArgs
#ifndef __WNNMobileBroadbandAccountUpdatedEventArgs_DEFINED__
#define __WNNMobileBroadbandAccountUpdatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WNNMobileBroadbandAccountUpdatedEventArgs : RTObject
@property (readonly) BOOL hasDeviceInformationChanged;
@property (readonly) BOOL hasNetworkChanged;
@property (readonly) NSString* networkAccountId;
@end

#endif // __WNNMobileBroadbandAccountUpdatedEventArgs_DEFINED__

// Windows.Networking.NetworkOperators.MobileBroadbandAccountWatcher
#ifndef __WNNMobileBroadbandAccountWatcher_DEFINED__
#define __WNNMobileBroadbandAccountWatcher_DEFINED__

WINRT_EXPORT
@interface WNNMobileBroadbandAccountWatcher : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) WNNMobileBroadbandAccountWatcherStatus status;
- (EventRegistrationToken)addAccountAddedEvent:(void (^)(WNNMobileBroadbandAccountWatcher*, WNNMobileBroadbandAccountEventArgs*))del;
- (void)removeAccountAddedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addAccountRemovedEvent:(void (^)(WNNMobileBroadbandAccountWatcher*, WNNMobileBroadbandAccountEventArgs*))del;
- (void)removeAccountRemovedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addAccountUpdatedEvent:(void (^)(WNNMobileBroadbandAccountWatcher*,
                                                           WNNMobileBroadbandAccountUpdatedEventArgs*))del;
- (void)removeAccountUpdatedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addEnumerationCompletedEvent:(void (^)(WNNMobileBroadbandAccountWatcher*, RTObject*))del;
- (void)removeEnumerationCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStoppedEvent:(void (^)(WNNMobileBroadbandAccountWatcher*, RTObject*))del;
- (void)removeStoppedEvent:(EventRegistrationToken)tok;
- (void)start;
- (void)stop;
@end

#endif // __WNNMobileBroadbandAccountWatcher_DEFINED__

// Windows.Networking.NetworkOperators.MobileBroadbandModem
#ifndef __WNNMobileBroadbandModem_DEFINED__
#define __WNNMobileBroadbandModem_DEFINED__

WINRT_EXPORT
@interface WNNMobileBroadbandModem : RTObject
+ (NSString*)getDeviceSelector;
+ (WNNMobileBroadbandModem*)fromId:(NSString*)deviceId;
+ (WNNMobileBroadbandModem*)getDefault;
@property (readonly) WNNMobileBroadbandAccount* currentAccount;
@property (readonly) WNNMobileBroadbandNetwork* currentNetwork;
@property (readonly) WNNMobileBroadbandDeviceInformation* deviceInformation;
@property (readonly) NSArray* deviceServices;
@property (readonly) BOOL isResetSupported;
@property (readonly) unsigned int maxDeviceServiceCommandSizeInBytes;
@property (readonly) unsigned int maxDeviceServiceDataSizeInBytes;
- (WNNMobileBroadbandDeviceService*)getDeviceService:(WFGUID*)deviceServiceId;
- (RTObject<WFIAsyncAction>*)resetAsync;
- (void)getCurrentConfigurationAsyncWithSuccess:(void (^)(WNNMobileBroadbandModemConfiguration*))success
                                        failure:(void (^)(NSError*))failure;
@end

#endif // __WNNMobileBroadbandModem_DEFINED__

// Windows.Networking.NetworkOperators.MobileBroadbandUicc
#ifndef __WNNMobileBroadbandUicc_DEFINED__
#define __WNNMobileBroadbandUicc_DEFINED__

WINRT_EXPORT
@interface WNNMobileBroadbandUicc : RTObject
@property (readonly) NSString* simIccId;
- (void)getUiccAppsAsyncWithSuccess:(void (^)(WNNMobileBroadbandUiccAppsResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WNNMobileBroadbandUicc_DEFINED__

// Windows.Networking.NetworkOperators.MobileBroadbandModemConfiguration
#ifndef __WNNMobileBroadbandModemConfiguration_DEFINED__
#define __WNNMobileBroadbandModemConfiguration_DEFINED__

WINRT_EXPORT
@interface WNNMobileBroadbandModemConfiguration : RTObject
@property (readonly) NSString* homeProviderId;
@property (readonly) NSString* homeProviderName;
@property (readonly) WNNMobileBroadbandUicc* uicc;
@end

#endif // __WNNMobileBroadbandModemConfiguration_DEFINED__

// Windows.Networking.NetworkOperators.MobileBroadbandDeviceServiceInformation
#ifndef __WNNMobileBroadbandDeviceServiceInformation_DEFINED__
#define __WNNMobileBroadbandDeviceServiceInformation_DEFINED__

WINRT_EXPORT
@interface WNNMobileBroadbandDeviceServiceInformation : RTObject
@property (readonly) WFGUID* deviceServiceId;
@property (readonly) BOOL isDataReadSupported;
@property (readonly) BOOL isDataWriteSupported;
@end

#endif // __WNNMobileBroadbandDeviceServiceInformation_DEFINED__

// Windows.Networking.NetworkOperators.MobileBroadbandDeviceService
#ifndef __WNNMobileBroadbandDeviceService_DEFINED__
#define __WNNMobileBroadbandDeviceService_DEFINED__

WINRT_EXPORT
@interface WNNMobileBroadbandDeviceService : RTObject
@property (readonly) WFGUID* deviceServiceId;
@property (readonly) NSArray* supportedCommands;
- (WNNMobileBroadbandDeviceServiceDataSession*)openDataSession;
- (WNNMobileBroadbandDeviceServiceCommandSession*)openCommandSession;
@end

#endif // __WNNMobileBroadbandDeviceService_DEFINED__

// Windows.Networking.NetworkOperators.MobileBroadbandPin
#ifndef __WNNMobileBroadbandPin_DEFINED__
#define __WNNMobileBroadbandPin_DEFINED__

WINRT_EXPORT
@interface WNNMobileBroadbandPin : RTObject
@property (readonly) unsigned int attemptsRemaining;
@property (readonly) BOOL enabled;
@property (readonly) WNNMobileBroadbandPinFormat format;
@property (readonly) WNNMobileBroadbandPinLockState lockState;
@property (readonly) unsigned int maxLength;
@property (readonly) unsigned int minLength;
@property (readonly) WNNMobileBroadbandPinType type;
- (void)enableAsync:(NSString*)currentPin
            success:(void (^)(WNNMobileBroadbandPinOperationResult*))success
            failure:(void (^)(NSError*))failure;
- (void)disableAsync:(NSString*)currentPin
             success:(void (^)(WNNMobileBroadbandPinOperationResult*))success
             failure:(void (^)(NSError*))failure;
- (void)enterAsync:(NSString*)currentPin
           success:(void (^)(WNNMobileBroadbandPinOperationResult*))success
           failure:(void (^)(NSError*))failure;
- (void)changeAsync:(NSString*)currentPin
             newPin:(NSString*)newPin
            success:(void (^)(WNNMobileBroadbandPinOperationResult*))success
            failure:(void (^)(NSError*))failure;
- (void)unblockAsync:(NSString*)pinUnblockKey
              newPin:(NSString*)newPin
             success:(void (^)(WNNMobileBroadbandPinOperationResult*))success
             failure:(void (^)(NSError*))failure;
@end

#endif // __WNNMobileBroadbandPin_DEFINED__

// Windows.Networking.NetworkOperators.MobileBroadbandPinOperationResult
#ifndef __WNNMobileBroadbandPinOperationResult_DEFINED__
#define __WNNMobileBroadbandPinOperationResult_DEFINED__

WINRT_EXPORT
@interface WNNMobileBroadbandPinOperationResult : RTObject
@property (readonly) unsigned int attemptsRemaining;
@property (readonly) BOOL isSuccessful;
@end

#endif // __WNNMobileBroadbandPinOperationResult_DEFINED__

// Windows.Networking.NetworkOperators.MobileBroadbandDeviceServiceDataSession
#ifndef __WNNMobileBroadbandDeviceServiceDataSession_DEFINED__
#define __WNNMobileBroadbandDeviceServiceDataSession_DEFINED__

WINRT_EXPORT
@interface WNNMobileBroadbandDeviceServiceDataSession : RTObject
- (EventRegistrationToken)addDataReceivedEvent:(void (^)(WNNMobileBroadbandDeviceServiceDataSession*,
                                                         WNNMobileBroadbandDeviceServiceDataReceivedEventArgs*))del;
- (void)removeDataReceivedEvent:(EventRegistrationToken)tok;
- (RTObject<WFIAsyncAction>*)writeDataAsync:(RTObject<WSSIBuffer>*)value;
- (void)closeSession;
@end

#endif // __WNNMobileBroadbandDeviceServiceDataSession_DEFINED__

// Windows.Networking.NetworkOperators.MobileBroadbandDeviceServiceCommandSession
#ifndef __WNNMobileBroadbandDeviceServiceCommandSession_DEFINED__
#define __WNNMobileBroadbandDeviceServiceCommandSession_DEFINED__

WINRT_EXPORT
@interface WNNMobileBroadbandDeviceServiceCommandSession : RTObject
- (void)sendQueryCommandAsync:(unsigned int)commandId
                         data:(RTObject<WSSIBuffer>*)data
                      success:(void (^)(WNNMobileBroadbandDeviceServiceCommandResult*))success
                      failure:(void (^)(NSError*))failure;
- (void)sendSetCommandAsync:(unsigned int)commandId
                       data:(RTObject<WSSIBuffer>*)data
                    success:(void (^)(WNNMobileBroadbandDeviceServiceCommandResult*))success
                    failure:(void (^)(NSError*))failure;
- (void)closeSession;
@end

#endif // __WNNMobileBroadbandDeviceServiceCommandSession_DEFINED__

// Windows.Networking.NetworkOperators.MobileBroadbandDeviceServiceDataReceivedEventArgs
#ifndef __WNNMobileBroadbandDeviceServiceDataReceivedEventArgs_DEFINED__
#define __WNNMobileBroadbandDeviceServiceDataReceivedEventArgs_DEFINED__

WINRT_EXPORT
@interface WNNMobileBroadbandDeviceServiceDataReceivedEventArgs : RTObject
@property (readonly) RTObject<WSSIBuffer>* receivedData;
@end

#endif // __WNNMobileBroadbandDeviceServiceDataReceivedEventArgs_DEFINED__

// Windows.Networking.NetworkOperators.MobileBroadbandDeviceServiceCommandResult
#ifndef __WNNMobileBroadbandDeviceServiceCommandResult_DEFINED__
#define __WNNMobileBroadbandDeviceServiceCommandResult_DEFINED__

WINRT_EXPORT
@interface WNNMobileBroadbandDeviceServiceCommandResult : RTObject
@property (readonly) RTObject<WSSIBuffer>* responseData;
@property (readonly) unsigned int statusCode;
@end

#endif // __WNNMobileBroadbandDeviceServiceCommandResult_DEFINED__

// Windows.Networking.NetworkOperators.MobileBroadbandUiccAppsResult
#ifndef __WNNMobileBroadbandUiccAppsResult_DEFINED__
#define __WNNMobileBroadbandUiccAppsResult_DEFINED__

WINRT_EXPORT
@interface WNNMobileBroadbandUiccAppsResult : RTObject
@property (readonly) WNNMobileBroadbandUiccAppOperationStatus status;
@property (readonly) NSArray* uiccApps;
@end

#endif // __WNNMobileBroadbandUiccAppsResult_DEFINED__

// Windows.Networking.NetworkOperators.MobileBroadbandUiccAppRecordDetailsResult
#ifndef __WNNMobileBroadbandUiccAppRecordDetailsResult_DEFINED__
#define __WNNMobileBroadbandUiccAppRecordDetailsResult_DEFINED__

WINRT_EXPORT
@interface WNNMobileBroadbandUiccAppRecordDetailsResult : RTObject
@property (readonly) WNNUiccAppRecordKind kind;
@property (readonly) WNNUiccAccessCondition readAccessCondition;
@property (readonly) int recordCount;
@property (readonly) int recordSize;
@property (readonly) WNNMobileBroadbandUiccAppOperationStatus status;
@property (readonly) WNNUiccAccessCondition writeAccessCondition;
@end

#endif // __WNNMobileBroadbandUiccAppRecordDetailsResult_DEFINED__

// Windows.Networking.NetworkOperators.MobileBroadbandUiccAppReadRecordResult
#ifndef __WNNMobileBroadbandUiccAppReadRecordResult_DEFINED__
#define __WNNMobileBroadbandUiccAppReadRecordResult_DEFINED__

WINRT_EXPORT
@interface WNNMobileBroadbandUiccAppReadRecordResult : RTObject
@property (readonly) RTObject<WSSIBuffer>* data;
@property (readonly) WNNMobileBroadbandUiccAppOperationStatus status;
@end

#endif // __WNNMobileBroadbandUiccAppReadRecordResult_DEFINED__

// Windows.Networking.NetworkOperators.MobileBroadbandNetworkRegistrationStateChange
#ifndef __WNNMobileBroadbandNetworkRegistrationStateChange_DEFINED__
#define __WNNMobileBroadbandNetworkRegistrationStateChange_DEFINED__

WINRT_EXPORT
@interface WNNMobileBroadbandNetworkRegistrationStateChange : RTObject
@property (readonly) NSString* deviceId;
@property (readonly) WNNMobileBroadbandNetwork* network;
@end

#endif // __WNNMobileBroadbandNetworkRegistrationStateChange_DEFINED__

// Windows.Networking.NetworkOperators.MobileBroadbandNetworkRegistrationStateChangeTriggerDetails
#ifndef __WNNMobileBroadbandNetworkRegistrationStateChangeTriggerDetails_DEFINED__
#define __WNNMobileBroadbandNetworkRegistrationStateChangeTriggerDetails_DEFINED__

WINRT_EXPORT
@interface WNNMobileBroadbandNetworkRegistrationStateChangeTriggerDetails : RTObject
@property (readonly) NSArray* networkRegistrationStateChanges;
@end

#endif // __WNNMobileBroadbandNetworkRegistrationStateChangeTriggerDetails_DEFINED__

// Windows.Networking.NetworkOperators.MobileBroadbandRadioStateChange
#ifndef __WNNMobileBroadbandRadioStateChange_DEFINED__
#define __WNNMobileBroadbandRadioStateChange_DEFINED__

WINRT_EXPORT
@interface WNNMobileBroadbandRadioStateChange : RTObject
@property (readonly) NSString* deviceId;
@property (readonly) WNNMobileBroadbandRadioState radioState;
@end

#endif // __WNNMobileBroadbandRadioStateChange_DEFINED__

// Windows.Networking.NetworkOperators.MobileBroadbandRadioStateChangeTriggerDetails
#ifndef __WNNMobileBroadbandRadioStateChangeTriggerDetails_DEFINED__
#define __WNNMobileBroadbandRadioStateChangeTriggerDetails_DEFINED__

WINRT_EXPORT
@interface WNNMobileBroadbandRadioStateChangeTriggerDetails : RTObject
@property (readonly) NSArray* radioStateChanges;
@end

#endif // __WNNMobileBroadbandRadioStateChangeTriggerDetails_DEFINED__

// Windows.Networking.NetworkOperators.MobileBroadbandPinLockStateChange
#ifndef __WNNMobileBroadbandPinLockStateChange_DEFINED__
#define __WNNMobileBroadbandPinLockStateChange_DEFINED__

WINRT_EXPORT
@interface WNNMobileBroadbandPinLockStateChange : RTObject
@property (readonly) NSString* deviceId;
@property (readonly) WNNMobileBroadbandPinLockState pinLockState;
@property (readonly) WNNMobileBroadbandPinType pinType;
@end

#endif // __WNNMobileBroadbandPinLockStateChange_DEFINED__

// Windows.Networking.NetworkOperators.MobileBroadbandPinLockStateChangeTriggerDetails
#ifndef __WNNMobileBroadbandPinLockStateChangeTriggerDetails_DEFINED__
#define __WNNMobileBroadbandPinLockStateChangeTriggerDetails_DEFINED__

WINRT_EXPORT
@interface WNNMobileBroadbandPinLockStateChangeTriggerDetails : RTObject
@property (readonly) NSArray* pinLockStateChanges;
@end

#endif // __WNNMobileBroadbandPinLockStateChangeTriggerDetails_DEFINED__

// Windows.Networking.NetworkOperators.MobileBroadbandDeviceServiceTriggerDetails
#ifndef __WNNMobileBroadbandDeviceServiceTriggerDetails_DEFINED__
#define __WNNMobileBroadbandDeviceServiceTriggerDetails_DEFINED__

WINRT_EXPORT
@interface WNNMobileBroadbandDeviceServiceTriggerDetails : RTObject
@property (readonly) NSString* deviceId;
@property (readonly) WFGUID* deviceServiceId;
@property (readonly) RTObject<WSSIBuffer>* receivedData;
@end

#endif // __WNNMobileBroadbandDeviceServiceTriggerDetails_DEFINED__

// Windows.Networking.NetworkOperators.KnownCSimFilePaths
#ifndef __WNNKnownCSimFilePaths_DEFINED__
#define __WNNKnownCSimFilePaths_DEFINED__

WINRT_EXPORT
@interface WNNKnownCSimFilePaths : RTObject
+ (NSArray*)eFSpn;
+ (NSArray*)gid1;
+ (NSArray*)gid2;
@end

#endif // __WNNKnownCSimFilePaths_DEFINED__

// Windows.Networking.NetworkOperators.KnownRuimFilePaths
#ifndef __WNNKnownRuimFilePaths_DEFINED__
#define __WNNKnownRuimFilePaths_DEFINED__

WINRT_EXPORT
@interface WNNKnownRuimFilePaths : RTObject
+ (NSArray*)eFSpn;
+ (NSArray*)gid1;
+ (NSArray*)gid2;
@end

#endif // __WNNKnownRuimFilePaths_DEFINED__

// Windows.Networking.NetworkOperators.KnownSimFilePaths
#ifndef __WNNKnownSimFilePaths_DEFINED__
#define __WNNKnownSimFilePaths_DEFINED__

WINRT_EXPORT
@interface WNNKnownSimFilePaths : RTObject
+ (NSArray*)eFOns;
+ (NSArray*)eFSpn;
+ (NSArray*)gid1;
+ (NSArray*)gid2;
@end

#endif // __WNNKnownSimFilePaths_DEFINED__

// Windows.Networking.NetworkOperators.KnownUSimFilePaths
#ifndef __WNNKnownUSimFilePaths_DEFINED__
#define __WNNKnownUSimFilePaths_DEFINED__

WINRT_EXPORT
@interface WNNKnownUSimFilePaths : RTObject
+ (NSArray*)eFOpl;
+ (NSArray*)eFPnn;
+ (NSArray*)eFSpn;
+ (NSArray*)gid1;
+ (NSArray*)gid2;
@end

#endif // __WNNKnownUSimFilePaths_DEFINED__

// Windows.Networking.NetworkOperators.HotspotAuthenticationEventDetails
#ifndef __WNNHotspotAuthenticationEventDetails_DEFINED__
#define __WNNHotspotAuthenticationEventDetails_DEFINED__

WINRT_EXPORT
@interface WNNHotspotAuthenticationEventDetails : RTObject
@property (readonly) NSString* eventToken;
@end

#endif // __WNNHotspotAuthenticationEventDetails_DEFINED__

// Windows.Networking.NetworkOperators.HotspotAuthenticationContext
#ifndef __WNNHotspotAuthenticationContext_DEFINED__
#define __WNNHotspotAuthenticationContext_DEFINED__

WINRT_EXPORT
@interface WNNHotspotAuthenticationContext : RTObject
+ (BOOL)tryGetAuthenticationContext:(NSString*)evenToken context:(WNNHotspotAuthenticationContext**)context;
@property (readonly) WFUri* authenticationUrl;
@property (readonly) WNCNetworkAdapter* networkAdapter;
@property (readonly) WFUri* redirectMessageUrl;
@property (readonly) WDXDXmlDocument* redirectMessageXml;
@property (readonly) NSArray* wirelessNetworkId;
- (void)issueCredentials:(NSString*)userName
                        password:(NSString*)password
                 extraParameters:(NSString*)extraParameters
    markAsManualConnectOnFailure:(BOOL)markAsManualConnectOnFailure;
- (void)abortAuthentication:(BOOL)markAsManual;
- (void)skipAuthentication;
- (void)triggerAttentionRequired:(NSString*)packageRelativeApplicationId applicationParameters:(NSString*)applicationParameters;
- (void)issueCredentialsAsync:(NSString*)userName
                     password:(NSString*)password
              extraParameters:(NSString*)extraParameters
 markAsManualConnectOnFailure:(BOOL)markAsManualConnectOnFailure
                      success:(void (^)(WNNHotspotCredentialsAuthenticationResult*))success
                      failure:(void (^)(NSError*))failure;
@end

#endif // __WNNHotspotAuthenticationContext_DEFINED__

// Windows.Networking.NetworkOperators.HotspotCredentialsAuthenticationResult
#ifndef __WNNHotspotCredentialsAuthenticationResult_DEFINED__
#define __WNNHotspotCredentialsAuthenticationResult_DEFINED__

WINRT_EXPORT
@interface WNNHotspotCredentialsAuthenticationResult : RTObject
@property (readonly) WDXDXmlDocument* authenticationReplyXml;
@property (readonly) BOOL hasNetworkErrorOccurred;
@property (readonly) WFUri* logoffUrl;
@property (readonly) WNNHotspotAuthenticationResponseCode responseCode;
@end

#endif // __WNNHotspotCredentialsAuthenticationResult_DEFINED__

// Windows.Networking.NetworkOperators.ProvisionFromXmlDocumentResults
#ifndef __WNNProvisionFromXmlDocumentResults_DEFINED__
#define __WNNProvisionFromXmlDocumentResults_DEFINED__

WINRT_EXPORT
@interface WNNProvisionFromXmlDocumentResults : RTObject
@property (readonly) BOOL allElementsProvisioned;
@property (readonly) NSString* provisionResultsXml;
@end

#endif // __WNNProvisionFromXmlDocumentResults_DEFINED__

// Windows.Networking.NetworkOperators.ProvisionedProfile
#ifndef __WNNProvisionedProfile_DEFINED__
#define __WNNProvisionedProfile_DEFINED__

WINRT_EXPORT
@interface WNNProvisionedProfile : RTObject
- (void)updateCost:(WNCNetworkCostType)value;
- (void)updateUsage:(WNNProfileUsage*)value;
@end

#endif // __WNNProvisionedProfile_DEFINED__

// Windows.Networking.NetworkOperators.ProvisioningAgent
#ifndef __WNNProvisioningAgent_DEFINED__
#define __WNNProvisioningAgent_DEFINED__

WINRT_EXPORT
@interface WNNProvisioningAgent : RTObject
+ (WNNProvisioningAgent*)createFromNetworkAccountId:(NSString*)networkAccountId;
+ (instancetype)create ACTIVATOR;
- (void)provisionFromXmlDocumentAsync:(NSString*)provisioningXmlDocument
                              success:(void (^)(WNNProvisionFromXmlDocumentResults*))success
                              failure:(void (^)(NSError*))failure;
- (WNNProvisionedProfile*)getProvisionedProfile:(WNNProfileMediaType)mediaType profileName:(NSString*)profileName;
@end

#endif // __WNNProvisioningAgent_DEFINED__

// Windows.Networking.NetworkOperators.UssdMessage
#ifndef __WNNUssdMessage_DEFINED__
#define __WNNUssdMessage_DEFINED__

WINRT_EXPORT
@interface WNNUssdMessage : RTObject
+ (WNNUssdMessage*)createMessage:(NSString*)messageText ACTIVATOR;
@property (copy) NSString* payloadAsText;
@property uint8_t dataCodingScheme;
- (NSArray*)getPayload;
- (void)setPayload:(id<NSFastEnumeration> /* uint8_t */)value;
@end

#endif // __WNNUssdMessage_DEFINED__

// Windows.Networking.NetworkOperators.UssdReply
#ifndef __WNNUssdReply_DEFINED__
#define __WNNUssdReply_DEFINED__

WINRT_EXPORT
@interface WNNUssdReply : RTObject
@property (readonly) WNNUssdMessage* message;
@property (readonly) WNNUssdResultCode resultCode;
@end

#endif // __WNNUssdReply_DEFINED__

// Windows.Networking.NetworkOperators.UssdSession
#ifndef __WNNUssdSession_DEFINED__
#define __WNNUssdSession_DEFINED__

WINRT_EXPORT
@interface WNNUssdSession : RTObject
+ (WNNUssdSession*)createFromNetworkAccountId:(NSString*)networkAccountId;
+ (WNNUssdSession*)createFromNetworkInterfaceId:(NSString*)networkInterfaceId;
- (void)sendMessageAndGetReplyAsync:(WNNUssdMessage*)message success:(void (^)(WNNUssdReply*))success failure:(void (^)(NSError*))failure;
- (void)close;
@end

#endif // __WNNUssdSession_DEFINED__
