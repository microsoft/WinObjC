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
@class WNNMobileBroadbandAccount, WNNMobileBroadbandNetwork, WNNMobileBroadbandDeviceInformation,
    WNNNetworkOperatorNotificationEventDetails, WNNNetworkOperatorTetheringAccessPointConfiguration,
    WNNNetworkOperatorTetheringOperationResult, WNNNetworkOperatorTetheringManager, WNNMobileBroadbandAccountEventArgs,
    WNNMobileBroadbandAccountUpdatedEventArgs, WNNMobileBroadbandAccountWatcher, WNNHotspotAuthenticationEventDetails,
    WNNHotspotAuthenticationContext, WNNHotspotCredentialsAuthenticationResult, WNNProvisionFromXmlDocumentResults, WNNProvisionedProfile,
    WNNProvisioningAgent, WNNUssdMessage, WNNUssdReply, WNNUssdSession;
@class WNNProfileUsage;
@protocol WNNIMobileBroadbandAccountStatics
, WNNIMobileBroadbandAccount, WNNIMobileBroadbandAccount2, WNNIMobileBroadbandDeviceInformation, WNNIMobileBroadbandNetwork,
    WNNINetworkOperatorNotificationEventDetails, WNNINetworkOperatorTetheringEntitlementCheck,
    WNNINetworkOperatorTetheringAccessPointConfiguration, WNNINetworkOperatorTetheringOperationResult,
    WNNINetworkOperatorTetheringManagerStatics, WNNINetworkOperatorTetheringManager, WNNIMobileBroadbandAccountEventArgs,
    WNNIMobileBroadbandAccountUpdatedEventArgs, WNNIMobileBroadbandAccountWatcher, WNNIHotspotAuthenticationEventDetails,
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
#include "WindowsDevicesSms.h"
#include "WindowsFoundationCollections.h"
#include "WindowsFoundation.h"
#include "WindowsDataXmlDom.h"

// [struct] Windows.Networking.NetworkOperators.ProfileUsage
WINRT_EXPORT
@interface WNNProfileUsage : NSObject
+ (instancetype) new;
@property unsigned usageInMegabytes;
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
+ (id<NSFastEnumeration> /*String*/)availableNetworkAccountIds;
- (id<NSFastEnumeration> /*WNCConnectionProfile*/)getConnectionProfiles;
@end

#endif // __WNNMobileBroadbandAccount_DEFINED__

// Windows.Networking.NetworkOperators.MobileBroadbandNetwork
#ifndef __WNNMobileBroadbandNetwork_DEFINED__
#define __WNNMobileBroadbandNetwork_DEFINED__

WINRT_EXPORT
@interface WNNMobileBroadbandNetwork : RTObject
@property (readonly) NSString* accessPointName;
@property (readonly) unsigned activationNetworkError;
@property (readonly) WNCNetworkAdapter* networkAdapter;
@property (readonly) WNNNetworkRegistrationState networkRegistrationState;
@property (readonly) unsigned packetAttachNetworkError;
@property (readonly) WNNDataClasses registeredDataClass;
@property (readonly) NSString* registeredProviderId;
@property (readonly) NSString* registeredProviderName;
@property (readonly) unsigned registrationNetworkError;
- (void)showConnectionUI;
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
@property (readonly) id<NSFastEnumeration> /*String*/ telephoneNumbers;
@end

#endif // __WNNMobileBroadbandDeviceInformation_DEFINED__

// Windows.Networking.NetworkOperators.NetworkOperatorNotificationEventDetails
#ifndef __WNNNetworkOperatorNotificationEventDetails_DEFINED__
#define __WNNNetworkOperatorNotificationEventDetails_DEFINED__

WINRT_EXPORT
@interface WNNNetworkOperatorNotificationEventDetails : RTObject
@property (readonly) uint8_t encodingType;
@property (readonly) NSString* message;
@property (readonly) NSString* networkAccountId;
@property (readonly) WNNNetworkOperatorEventMessageType notificationType;
@property (readonly) NSString* ruleId;
@property (readonly) RTObject<WDSISmsMessage>* smsMessage;
- (void)authorizeTethering:(BOOL)allow entitlementFailureReason:(NSString*)entitlementFailureReason;
@end

#endif // __WNNNetworkOperatorNotificationEventDetails_DEFINED__

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
@property (readonly) unsigned clientCount;
@property (readonly) unsigned maxClientCount;
@property (readonly) WNNTetheringOperationalState tetheringOperationalState;
- (WNNNetworkOperatorTetheringAccessPointConfiguration*)getCurrentAccessPointConfiguration;
- (RTObject<WFIAsyncAction>*)configureAccessPointAsync:(WNNNetworkOperatorTetheringAccessPointConfiguration*)configuration;
- (void)startTetheringAsyncWithSuccess:(void (^)(WNNNetworkOperatorTetheringOperationResult*))success failure:(void (^)(NSError*))failure;
- (void)stopTetheringAsyncWithSuccess:(void (^)(WNNNetworkOperatorTetheringOperationResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WNNNetworkOperatorTetheringManager_DEFINED__

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
@property (readonly) id<NSFastEnumeration> /*UInt8*/ wirelessNetworkId;
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
- (id<NSFastEnumeration> /*UInt8*/)getPayload;
- (void)setPayload:(id<NSFastEnumeration> /*UInt8*/)value;
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
