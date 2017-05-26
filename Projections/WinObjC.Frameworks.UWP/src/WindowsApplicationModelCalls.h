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

// WindowsApplicationModelCalls.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
#define OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsConsolidatedNamespace.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WACPhoneLine, WACPhoneVoicemail, WACPhoneLineCellularDetails, WACPhoneCallVideoCapabilities, WACPhoneLineConfiguration,
    WACPhoneDialOptions, WACPhoneLineWatcher, WACPhoneLineWatcherEventArgs, WACPhoneCallStore, WACPhoneCallManager,
    WACPhoneCallVideoCapabilitiesManager, WACPhoneCallBlocking, WACCallStateChangeEventArgs, WACCallAnswerEventArgs, WACCallRejectEventArgs,
    WACVoipPhoneCall, WACMuteChangeEventArgs, WACVoipCallCoordinator, WACLockScreenCallEndCallDeferral, WACLockScreenCallUI,
    WACLockScreenCallEndRequestedEventArgs, WACPhoneCallHistoryEntryAddress, WACPhoneCallHistoryEntry, WACPhoneCallHistoryEntryReader,
    WACPhoneCallHistoryEntryQueryOptions, WACPhoneCallHistoryStore, WACPhoneCallHistoryManagerForUser, WACPhoneCallHistoryManager;
@protocol WACIPhoneVoicemail
, WACIPhoneDialOptions, WACIPhoneLineCellularDetails, WACIPhoneLine, WACIPhoneCallStore, WACIPhoneLineConfiguration, WACIPhoneLineStatics,
    WACIPhoneLineWatcher, WACIPhoneLineWatcherEventArgs, WACIPhoneCallManagerStatics, WACIPhoneCallManagerStatics2,
    WACIPhoneCallVideoCapabilities, WACIPhoneCallVideoCapabilitiesManagerStatics, WACIPhoneCallBlockingStatics,
    WACICallStateChangeEventArgs, WACICallAnswerEventArgs, WACICallRejectEventArgs, WACIVoipPhoneCall, WACIMuteChangeEventArgs,
    WACIVoipCallCoordinator, WACIVoipCallCoordinatorStatics, WACILockScreenCallEndCallDeferral, WACILockScreenCallEndRequestedEventArgs,
    WACILockScreenCallUI, WACIPhoneCallHistoryEntry, WACIPhoneCallHistoryEntryAddress, WACIPhoneCallHistoryEntryAddressFactory,
    WACIPhoneCallHistoryEntryQueryOptions, WACIPhoneCallHistoryEntryReader, WACIPhoneCallHistoryStore, WACIPhoneCallHistoryManagerStatics,
    WACIPhoneCallHistoryManagerStatics2, WACIPhoneCallHistoryManagerForUser;

// Windows.ApplicationModel.Calls.PhoneNetworkState
enum _WACPhoneNetworkState {
    WACPhoneNetworkStateUnknown = 0,
    WACPhoneNetworkStateNoSignal = 1,
    WACPhoneNetworkStateDeregistered = 2,
    WACPhoneNetworkStateDenied = 3,
    WACPhoneNetworkStateSearching = 4,
    WACPhoneNetworkStateHome = 5,
    WACPhoneNetworkStateRoamingInternational = 6,
    WACPhoneNetworkStateRoamingDomestic = 7,
};
typedef unsigned WACPhoneNetworkState;

// Windows.ApplicationModel.Calls.PhoneVoicemailType
enum _WACPhoneVoicemailType {
    WACPhoneVoicemailTypeNone = 0,
    WACPhoneVoicemailTypeTraditional = 1,
    WACPhoneVoicemailTypeVisual = 2,
};
typedef unsigned WACPhoneVoicemailType;

// Windows.ApplicationModel.Calls.PhoneCallMedia
enum _WACPhoneCallMedia {
    WACPhoneCallMediaAudio = 0,
    WACPhoneCallMediaAudioAndVideo = 1,
};
typedef unsigned WACPhoneCallMedia;

// Windows.ApplicationModel.Calls.PhoneLineTransport
enum _WACPhoneLineTransport {
    WACPhoneLineTransportCellular = 0,
    WACPhoneLineTransportVoipApp = 1,
};
typedef unsigned WACPhoneLineTransport;

// Windows.ApplicationModel.Calls.PhoneSimState
enum _WACPhoneSimState {
    WACPhoneSimStateUnknown = 0,
    WACPhoneSimStatePinNotRequired = 1,
    WACPhoneSimStatePinUnlocked = 2,
    WACPhoneSimStatePinLocked = 3,
    WACPhoneSimStatePukLocked = 4,
    WACPhoneSimStateNotInserted = 5,
    WACPhoneSimStateInvalid = 6,
    WACPhoneSimStateDisabled = 7,
};
typedef unsigned WACPhoneSimState;

// Windows.ApplicationModel.Calls.PhoneAudioRoutingEndpoint
enum _WACPhoneAudioRoutingEndpoint {
    WACPhoneAudioRoutingEndpointDefault = 0,
    WACPhoneAudioRoutingEndpointBluetooth = 1,
    WACPhoneAudioRoutingEndpointSpeakerphone = 2,
};
typedef unsigned WACPhoneAudioRoutingEndpoint;

// Windows.ApplicationModel.Calls.PhoneLineWatcherStatus
enum _WACPhoneLineWatcherStatus {
    WACPhoneLineWatcherStatusCreated = 0,
    WACPhoneLineWatcherStatusStarted = 1,
    WACPhoneLineWatcherStatusEnumerationCompleted = 2,
    WACPhoneLineWatcherStatusStopped = 3,
};
typedef unsigned WACPhoneLineWatcherStatus;

// Windows.ApplicationModel.Calls.PhoneLineNetworkOperatorDisplayTextLocation
enum _WACPhoneLineNetworkOperatorDisplayTextLocation {
    WACPhoneLineNetworkOperatorDisplayTextLocationDefault = 0,
    WACPhoneLineNetworkOperatorDisplayTextLocationTile = 1,
    WACPhoneLineNetworkOperatorDisplayTextLocationDialer = 2,
    WACPhoneLineNetworkOperatorDisplayTextLocationInCallUI = 3,
};
typedef unsigned WACPhoneLineNetworkOperatorDisplayTextLocation;

// Windows.ApplicationModel.Calls.CellularDtmfMode
enum _WACCellularDtmfMode {
    WACCellularDtmfModeContinuous = 0,
    WACCellularDtmfModeBurst = 1,
};
typedef unsigned WACCellularDtmfMode;

// Windows.ApplicationModel.Calls.VoipPhoneCallMedia
enum _WACVoipPhoneCallMedia {
    WACVoipPhoneCallMediaNone = 0,
    WACVoipPhoneCallMediaAudio = 1,
    WACVoipPhoneCallMediaVideo = 2,
};
typedef unsigned WACVoipPhoneCallMedia;

// Windows.ApplicationModel.Calls.VoipPhoneCallRejectReason
enum _WACVoipPhoneCallRejectReason {
    WACVoipPhoneCallRejectReasonUserIgnored = 0,
    WACVoipPhoneCallRejectReasonTimedOut = 1,
    WACVoipPhoneCallRejectReasonOtherIncomingCall = 2,
    WACVoipPhoneCallRejectReasonEmergencyCallExists = 3,
    WACVoipPhoneCallRejectReasonInvalidCallState = 4,
};
typedef unsigned WACVoipPhoneCallRejectReason;

// Windows.ApplicationModel.Calls.VoipPhoneCallState
enum _WACVoipPhoneCallState {
    WACVoipPhoneCallStateEnded = 0,
    WACVoipPhoneCallStateHeld = 1,
    WACVoipPhoneCallStateActive = 2,
    WACVoipPhoneCallStateIncoming = 3,
    WACVoipPhoneCallStateOutgoing = 4,
};
typedef unsigned WACVoipPhoneCallState;

// Windows.ApplicationModel.Calls.VoipPhoneCallResourceReservationStatus
enum _WACVoipPhoneCallResourceReservationStatus {
    WACVoipPhoneCallResourceReservationStatusSuccess = 0,
    WACVoipPhoneCallResourceReservationStatusResourcesNotAvailable = 1,
};
typedef unsigned WACVoipPhoneCallResourceReservationStatus;

// Windows.ApplicationModel.Calls.PhoneCallHistoryEntryOtherAppReadAccess
enum _WACPhoneCallHistoryEntryOtherAppReadAccess {
    WACPhoneCallHistoryEntryOtherAppReadAccessFull = 0,
    WACPhoneCallHistoryEntryOtherAppReadAccessSystemOnly = 1,
};
typedef unsigned WACPhoneCallHistoryEntryOtherAppReadAccess;

// Windows.ApplicationModel.Calls.PhoneCallHistoryEntryMedia
enum _WACPhoneCallHistoryEntryMedia {
    WACPhoneCallHistoryEntryMediaAudio = 0,
    WACPhoneCallHistoryEntryMediaVideo = 1,
};
typedef unsigned WACPhoneCallHistoryEntryMedia;

// Windows.ApplicationModel.Calls.PhoneCallHistoryEntryRawAddressKind
enum _WACPhoneCallHistoryEntryRawAddressKind {
    WACPhoneCallHistoryEntryRawAddressKindPhoneNumber = 0,
    WACPhoneCallHistoryEntryRawAddressKindCustom = 1,
};
typedef unsigned WACPhoneCallHistoryEntryRawAddressKind;

// Windows.ApplicationModel.Calls.PhoneCallHistoryEntryQueryDesiredMedia
enum _WACPhoneCallHistoryEntryQueryDesiredMedia {
    WACPhoneCallHistoryEntryQueryDesiredMediaNone = 0,
    WACPhoneCallHistoryEntryQueryDesiredMediaAudio = 1,
    WACPhoneCallHistoryEntryQueryDesiredMediaVideo = 2,
    WACPhoneCallHistoryEntryQueryDesiredMediaAll = -1,
};
typedef unsigned WACPhoneCallHistoryEntryQueryDesiredMedia;

// Windows.ApplicationModel.Calls.PhoneCallHistoryStoreAccessType
enum _WACPhoneCallHistoryStoreAccessType {
    WACPhoneCallHistoryStoreAccessTypeAppEntriesReadWrite = 0,
    WACPhoneCallHistoryStoreAccessTypeAllEntriesLimitedReadWrite = 1,
    WACPhoneCallHistoryStoreAccessTypeAllEntriesReadWrite = 2,
};
typedef unsigned WACPhoneCallHistoryStoreAccessType;

// Windows.ApplicationModel.Calls.PhoneCallHistorySourceIdKind
enum _WACPhoneCallHistorySourceIdKind {
    WACPhoneCallHistorySourceIdKindCellularPhoneLineId = 0,
    WACPhoneCallHistorySourceIdKindPackageFamilyName = 1,
};
typedef unsigned WACPhoneCallHistorySourceIdKind;

#include "WindowsFoundation.h"
#include "WindowsApplicationModelContacts.h"
#include "WindowsUI.h"
#include "WindowsSystem.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.Calls.PhoneLine
#ifndef __WACPhoneLine_DEFINED__
#define __WACPhoneLine_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACPhoneLine : RTObject
+ (void)fromIdAsync:(WFGUID*)lineId success:(void (^)(WACPhoneLine*))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) BOOL canDial;
@property (readonly) WACPhoneLineCellularDetails* cellularDetails;
@property (readonly) WUColor* displayColor;
@property (readonly) NSString* displayName;
@property (readonly) WFGUID* id;
@property (readonly) WACPhoneLineConfiguration* lineConfiguration;
@property (readonly) NSString* networkName;
@property (readonly) WACPhoneNetworkState networkState;
@property (readonly) BOOL supportsTile;
@property (readonly) WACPhoneLineTransport transport;
@property (readonly) WACPhoneCallVideoCapabilities* videoCallingCapabilities;
@property (readonly) WACPhoneVoicemail* voicemail;
- (EventRegistrationToken)addLineChangedEvent:(void (^)(WACPhoneLine*, RTObject*))del;
- (void)removeLineChangedEvent:(EventRegistrationToken)tok;
- (void)isImmediateDialNumberAsync:(NSString*)number success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)dial:(NSString*)number displayName:(NSString*)displayName;
- (void)dialWithOptions:(WACPhoneDialOptions*)options;
@end

#endif // __WACPhoneLine_DEFINED__

// Windows.ApplicationModel.Calls.PhoneVoicemail
#ifndef __WACPhoneVoicemail_DEFINED__
#define __WACPhoneVoicemail_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACPhoneVoicemail : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) int messageCount;
@property (readonly) NSString* number;
@property (readonly) WACPhoneVoicemailType type;
- (RTObject<WFIAsyncAction>*)dialVoicemailAsync;
@end

#endif // __WACPhoneVoicemail_DEFINED__

// Windows.ApplicationModel.Calls.PhoneLineCellularDetails
#ifndef __WACPhoneLineCellularDetails_DEFINED__
#define __WACPhoneLineCellularDetails_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACPhoneLineCellularDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isModemOn;
@property (readonly) int registrationRejectCode;
@property (readonly) int simSlotIndex;
@property (readonly) WACPhoneSimState simState;
- (NSString*)getNetworkOperatorDisplayText:(WACPhoneLineNetworkOperatorDisplayTextLocation)location;
@end

#endif // __WACPhoneLineCellularDetails_DEFINED__

// Windows.ApplicationModel.Calls.PhoneCallVideoCapabilities
#ifndef __WACPhoneCallVideoCapabilities_DEFINED__
#define __WACPhoneCallVideoCapabilities_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACPhoneCallVideoCapabilities : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isVideoCallingCapable;
@end

#endif // __WACPhoneCallVideoCapabilities_DEFINED__

// Windows.ApplicationModel.Calls.PhoneLineConfiguration
#ifndef __WACPhoneLineConfiguration_DEFINED__
#define __WACPhoneLineConfiguration_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACPhoneLineConfiguration : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) NSDictionary* /* NSString *, RTObject* */ extendedProperties;
@property (readonly) BOOL isVideoCallingEnabled;
@end

#endif // __WACPhoneLineConfiguration_DEFINED__

// Windows.ApplicationModel.Calls.PhoneDialOptions
#ifndef __WACPhoneDialOptions_DEFINED__
#define __WACPhoneDialOptions_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACPhoneDialOptions : RTObject
+ (instancetype)make __attribute__((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (retain) NSString* number;
@property WACPhoneCallMedia media;
@property (retain) NSString* displayName;
@property (retain) WACContactPhone* contactPhone;
@property (retain) WACContact* contact;
@property WACPhoneAudioRoutingEndpoint audioEndpoint;
@end

#endif // __WACPhoneDialOptions_DEFINED__

// Windows.ApplicationModel.Calls.PhoneLineWatcher
#ifndef __WACPhoneLineWatcher_DEFINED__
#define __WACPhoneLineWatcher_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACPhoneLineWatcher : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WACPhoneLineWatcherStatus status;
- (EventRegistrationToken)addEnumerationCompletedEvent:(void (^)(WACPhoneLineWatcher*, RTObject*))del;
- (void)removeEnumerationCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addLineAddedEvent:(void (^)(WACPhoneLineWatcher*, WACPhoneLineWatcherEventArgs*))del;
- (void)removeLineAddedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addLineRemovedEvent:(void (^)(WACPhoneLineWatcher*, WACPhoneLineWatcherEventArgs*))del;
- (void)removeLineRemovedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addLineUpdatedEvent:(void (^)(WACPhoneLineWatcher*, WACPhoneLineWatcherEventArgs*))del;
- (void)removeLineUpdatedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStoppedEvent:(void (^)(WACPhoneLineWatcher*, RTObject*))del;
- (void)removeStoppedEvent:(EventRegistrationToken)tok;
- (void)start;
- (void)stop;
@end

#endif // __WACPhoneLineWatcher_DEFINED__

// Windows.ApplicationModel.Calls.PhoneLineWatcherEventArgs
#ifndef __WACPhoneLineWatcherEventArgs_DEFINED__
#define __WACPhoneLineWatcherEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACPhoneLineWatcherEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WFGUID* lineId;
@end

#endif // __WACPhoneLineWatcherEventArgs_DEFINED__

// Windows.ApplicationModel.Calls.PhoneCallStore
#ifndef __WACPhoneCallStore_DEFINED__
#define __WACPhoneCallStore_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACPhoneCallStore : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
- (void)isEmergencyPhoneNumberAsync:(NSString*)number success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)getDefaultLineAsyncWithSuccess:(void (^)(WFGUID*))success failure:(void (^)(NSError*))failure;
- (WACPhoneLineWatcher*)requestLineWatcher;
@end

#endif // __WACPhoneCallStore_DEFINED__

// Windows.ApplicationModel.Calls.PhoneCallManager
#ifndef __WACPhoneCallManager_DEFINED__
#define __WACPhoneCallManager_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACPhoneCallManager : RTObject
+ (void)showPhoneCallSettingsUI;
+ (void)requestStoreAsyncWithSuccess:(void (^)(WACPhoneCallStore*))success failure:(void (^)(NSError*))failure;
+ (void)showPhoneCallUI:(NSString*)phoneNumber displayName:(NSString*)displayName;
+ (BOOL)isCallActive;
+ (BOOL)isCallIncoming;
+ (EventRegistrationToken)addCallStateChangedEvent:(void (^)(RTObject*, RTObject*))del;
+ (void)removeCallStateChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WACPhoneCallManager_DEFINED__

// Windows.ApplicationModel.Calls.PhoneCallVideoCapabilitiesManager
#ifndef __WACPhoneCallVideoCapabilitiesManager_DEFINED__
#define __WACPhoneCallVideoCapabilitiesManager_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACPhoneCallVideoCapabilitiesManager : RTObject
+ (void)getCapabilitiesAsync:(NSString*)phoneNumber
                     success:(void (^)(WACPhoneCallVideoCapabilities*))success
                     failure:(void (^)(NSError*))failure;
@end

#endif // __WACPhoneCallVideoCapabilitiesManager_DEFINED__

// Windows.ApplicationModel.Calls.PhoneCallBlocking
#ifndef __WACPhoneCallBlocking_DEFINED__
#define __WACPhoneCallBlocking_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACPhoneCallBlocking : RTObject
+ (void)setCallBlockingListAsync:(id<NSFastEnumeration> /* NSString * */)phoneNumberList
                         success:(void (^)(BOOL))success
                         failure:(void (^)(NSError*))failure;
+ (BOOL)blockUnknownNumbers;
+ (void)setBlockUnknownNumbers:(BOOL)value;
+ (BOOL)blockPrivateNumbers;
+ (void)setBlockPrivateNumbers:(BOOL)value;
@end

#endif // __WACPhoneCallBlocking_DEFINED__

// Windows.ApplicationModel.Calls.CallStateChangeEventArgs
#ifndef __WACCallStateChangeEventArgs_DEFINED__
#define __WACCallStateChangeEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACCallStateChangeEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WACVoipPhoneCallState state;
@end

#endif // __WACCallStateChangeEventArgs_DEFINED__

// Windows.ApplicationModel.Calls.CallAnswerEventArgs
#ifndef __WACCallAnswerEventArgs_DEFINED__
#define __WACCallAnswerEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACCallAnswerEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WACVoipPhoneCallMedia acceptedMedia;
@end

#endif // __WACCallAnswerEventArgs_DEFINED__

// Windows.ApplicationModel.Calls.CallRejectEventArgs
#ifndef __WACCallRejectEventArgs_DEFINED__
#define __WACCallRejectEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACCallRejectEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WACVoipPhoneCallRejectReason rejectReason;
@end

#endif // __WACCallRejectEventArgs_DEFINED__

// Windows.ApplicationModel.Calls.VoipPhoneCall
#ifndef __WACVoipPhoneCall_DEFINED__
#define __WACVoipPhoneCall_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACVoipPhoneCall : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (retain) WFDateTime* startTime;
@property (retain) NSString* contactName;
@property WACVoipPhoneCallMedia callMedia;
- (EventRegistrationToken)addAnswerRequestedEvent:(void (^)(WACVoipPhoneCall*, WACCallAnswerEventArgs*))del;
- (void)removeAnswerRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addEndRequestedEvent:(void (^)(WACVoipPhoneCall*, WACCallStateChangeEventArgs*))del;
- (void)removeEndRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addHoldRequestedEvent:(void (^)(WACVoipPhoneCall*, WACCallStateChangeEventArgs*))del;
- (void)removeHoldRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addRejectRequestedEvent:(void (^)(WACVoipPhoneCall*, WACCallRejectEventArgs*))del;
- (void)removeRejectRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addResumeRequestedEvent:(void (^)(WACVoipPhoneCall*, WACCallStateChangeEventArgs*))del;
- (void)removeResumeRequestedEvent:(EventRegistrationToken)tok;
- (void)notifyCallHeld;
- (void)notifyCallActive;
- (void)notifyCallEnded;
- (void)notifyCallReady;
@end

#endif // __WACVoipPhoneCall_DEFINED__

// Windows.ApplicationModel.Calls.MuteChangeEventArgs
#ifndef __WACMuteChangeEventArgs_DEFINED__
#define __WACMuteChangeEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACMuteChangeEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) BOOL muted;
@end

#endif // __WACMuteChangeEventArgs_DEFINED__

// Windows.ApplicationModel.Calls.VoipCallCoordinator
#ifndef __WACVoipCallCoordinator_DEFINED__
#define __WACVoipCallCoordinator_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACVoipCallCoordinator : RTObject
+ (WACVoipCallCoordinator*)getDefault;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
- (EventRegistrationToken)addMuteStateChangedEvent:(void (^)(WACVoipCallCoordinator*, WACMuteChangeEventArgs*))del;
- (void)removeMuteStateChangedEvent:(EventRegistrationToken)tok;
- (void)reserveCallResourcesAsync:(NSString*)taskEntryPoint
                          success:(void (^)(WACVoipPhoneCallResourceReservationStatus))success
                          failure:(void (^)(NSError*))failure;
- (WACVoipPhoneCall*)requestNewIncomingCall:(NSString*)context
                                contactName:(NSString*)contactName
                              contactNumber:(NSString*)contactNumber
                               contactImage:(WFUri*)contactImage
                                serviceName:(NSString*)serviceName
                              brandingImage:(WFUri*)brandingImage
                                callDetails:(NSString*)callDetails
                                   ringtone:(WFUri*)ringtone
                                      media:(WACVoipPhoneCallMedia)media
                                ringTimeout:(WFTimeSpan*)ringTimeout;
- (WACVoipPhoneCall*)requestNewOutgoingCall:(NSString*)context
                                contactName:(NSString*)contactName
                                serviceName:(NSString*)serviceName
                                      media:(WACVoipPhoneCallMedia)media;
- (void)notifyMuted;
- (void)notifyUnmuted;
- (WACVoipPhoneCall*)requestOutgoingUpgradeToVideoCall:(WFGUID*)callUpgradeGuid
                                               context:(NSString*)context
                                           contactName:(NSString*)contactName
                                           serviceName:(NSString*)serviceName;
- (WACVoipPhoneCall*)requestIncomingUpgradeToVideoCall:(NSString*)context
                                           contactName:(NSString*)contactName
                                         contactNumber:(NSString*)contactNumber
                                          contactImage:(WFUri*)contactImage
                                           serviceName:(NSString*)serviceName
                                         brandingImage:(WFUri*)brandingImage
                                           callDetails:(NSString*)callDetails
                                              ringtone:(WFUri*)ringtone
                                           ringTimeout:(WFTimeSpan*)ringTimeout;
- (void)terminateCellularCall:(WFGUID*)callUpgradeGuid;
- (void)cancelUpgrade:(WFGUID*)callUpgradeGuid;
@end

#endif // __WACVoipCallCoordinator_DEFINED__

// Windows.ApplicationModel.Calls.LockScreenCallEndCallDeferral
#ifndef __WACLockScreenCallEndCallDeferral_DEFINED__
#define __WACLockScreenCallEndCallDeferral_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACLockScreenCallEndCallDeferral : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
- (void)complete;
@end

#endif // __WACLockScreenCallEndCallDeferral_DEFINED__

// Windows.ApplicationModel.Calls.LockScreenCallUI
#ifndef __WACLockScreenCallUI_DEFINED__
#define __WACLockScreenCallUI_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACLockScreenCallUI : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (retain) NSString* callTitle;
- (EventRegistrationToken)addClosedEvent:(void (^)(WACLockScreenCallUI*, RTObject*))del;
- (void)removeClosedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addEndRequestedEvent:(void (^)(WACLockScreenCallUI*, WACLockScreenCallEndRequestedEventArgs*))del;
- (void)removeEndRequestedEvent:(EventRegistrationToken)tok;
- (void)dismiss;
@end

#endif // __WACLockScreenCallUI_DEFINED__

// Windows.ApplicationModel.Calls.LockScreenCallEndRequestedEventArgs
#ifndef __WACLockScreenCallEndRequestedEventArgs_DEFINED__
#define __WACLockScreenCallEndRequestedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACLockScreenCallEndRequestedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WFDateTime* deadline;
- (WACLockScreenCallEndCallDeferral*)getDeferral;
@end

#endif // __WACLockScreenCallEndRequestedEventArgs_DEFINED__

// Windows.ApplicationModel.Calls.PhoneCallHistoryEntryAddress
#ifndef __WACPhoneCallHistoryEntryAddress_DEFINED__
#define __WACPhoneCallHistoryEntryAddress_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACPhoneCallHistoryEntryAddress : RTObject
+ (WACPhoneCallHistoryEntryAddress*)make:(NSString*)rawAddress
                          rawAddressKind:(WACPhoneCallHistoryEntryRawAddressKind)rawAddressKind ACTIVATOR;
+ (instancetype)make __attribute__((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property WACPhoneCallHistoryEntryRawAddressKind rawAddressKind;
@property (retain) NSString* rawAddress;
@property (retain) NSString* displayName;
@property (retain) NSString* contactId;
@end

#endif // __WACPhoneCallHistoryEntryAddress_DEFINED__

// Windows.ApplicationModel.Calls.PhoneCallHistoryEntry
#ifndef __WACPhoneCallHistoryEntry_DEFINED__
#define __WACPhoneCallHistoryEntry_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACPhoneCallHistoryEntry : RTObject
+ (instancetype)make __attribute__((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property WACPhoneCallHistoryEntryMedia media;
@property BOOL isMissed;
@property BOOL isIncoming;
@property BOOL isCallerIdBlocked;
@property BOOL isSeen;
@property (retain) id /* WFTimeSpan* */ duration;
@property BOOL isEmergency;
@property BOOL isSuppressed;
@property (retain) WFDateTime* startTime;
@property WACPhoneCallHistorySourceIdKind sourceIdKind;
@property (retain) WACPhoneCallHistoryEntryAddress* address;
@property (retain) NSString* sourceId;
@property (retain) NSString* remoteId;
@property WACPhoneCallHistoryEntryOtherAppReadAccess otherAppReadAccess;
@property BOOL isRinging;
@property BOOL isVoicemail;
@property (readonly) NSString* id;
@property (readonly) NSString* sourceDisplayName;
@end

#endif // __WACPhoneCallHistoryEntry_DEFINED__

// Windows.ApplicationModel.Calls.PhoneCallHistoryEntryReader
#ifndef __WACPhoneCallHistoryEntryReader_DEFINED__
#define __WACPhoneCallHistoryEntryReader_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACPhoneCallHistoryEntryReader : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
- (void)readBatchAsyncWithSuccess:(void (^)(NSArray* /* WACPhoneCallHistoryEntry* */))success failure:(void (^)(NSError*))failure;
@end

#endif // __WACPhoneCallHistoryEntryReader_DEFINED__

// Windows.ApplicationModel.Calls.PhoneCallHistoryEntryQueryOptions
#ifndef __WACPhoneCallHistoryEntryQueryOptions_DEFINED__
#define __WACPhoneCallHistoryEntryQueryOptions_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACPhoneCallHistoryEntryQueryOptions : RTObject
+ (instancetype)make __attribute__((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property WACPhoneCallHistoryEntryQueryDesiredMedia desiredMedia;
@property (readonly) NSMutableArray* /* NSString * */ sourceIds;
@end

#endif // __WACPhoneCallHistoryEntryQueryOptions_DEFINED__

// Windows.ApplicationModel.Calls.PhoneCallHistoryStore
#ifndef __WACPhoneCallHistoryStore_DEFINED__
#define __WACPhoneCallHistoryStore_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACPhoneCallHistoryStore : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
- (void)getEntryAsync:(NSString*)callHistoryEntryId
              success:(void (^)(WACPhoneCallHistoryEntry*))success
              failure:(void (^)(NSError*))failure;
- (WACPhoneCallHistoryEntryReader*)getEntryReader;
- (WACPhoneCallHistoryEntryReader*)getEntryReaderWithOptions:(WACPhoneCallHistoryEntryQueryOptions*)queryOptions;
- (RTObject<WFIAsyncAction>*)saveEntryAsync:(WACPhoneCallHistoryEntry*)callHistoryEntry;
- (RTObject<WFIAsyncAction>*)deleteEntryAsync:(WACPhoneCallHistoryEntry*)callHistoryEntry;
- (RTObject<WFIAsyncAction>*)deleteEntriesAsync:(id<NSFastEnumeration> /* WACPhoneCallHistoryEntry* */)callHistoryEntries;
- (RTObject<WFIAsyncAction>*)markEntryAsSeenAsync:(WACPhoneCallHistoryEntry*)callHistoryEntry;
- (RTObject<WFIAsyncAction>*)markEntriesAsSeenAsync:(id<NSFastEnumeration> /* WACPhoneCallHistoryEntry* */)callHistoryEntries;
- (void)getUnseenCountAsyncWithSuccess:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)markAllAsSeenAsync;
- (void)getSourcesUnseenCountAsync:(id<NSFastEnumeration> /* NSString * */)sourceIds
                           success:(void (^)(unsigned int))success
                           failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)markSourcesAsSeenAsync:(id<NSFastEnumeration> /* NSString * */)sourceIds;
@end

#endif // __WACPhoneCallHistoryStore_DEFINED__

// Windows.ApplicationModel.Calls.PhoneCallHistoryManagerForUser
#ifndef __WACPhoneCallHistoryManagerForUser_DEFINED__
#define __WACPhoneCallHistoryManagerForUser_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACPhoneCallHistoryManagerForUser : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WSUser* user;
- (void)requestStoreAsync:(WACPhoneCallHistoryStoreAccessType)accessType
                  success:(void (^)(WACPhoneCallHistoryStore*))success
                  failure:(void (^)(NSError*))failure;
@end

#endif // __WACPhoneCallHistoryManagerForUser_DEFINED__

// Windows.ApplicationModel.Calls.PhoneCallHistoryManager
#ifndef __WACPhoneCallHistoryManager_DEFINED__
#define __WACPhoneCallHistoryManager_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACPhoneCallHistoryManager : RTObject
+ (void)requestStoreAsync:(WACPhoneCallHistoryStoreAccessType)accessType
                  success:(void (^)(WACPhoneCallHistoryStore*))success
                  failure:(void (^)(NSError*))failure;
+ (WACPhoneCallHistoryManagerForUser*)getForUser:(WSUser*)user;
@end

#endif // __WACPhoneCallHistoryManager_DEFINED__
