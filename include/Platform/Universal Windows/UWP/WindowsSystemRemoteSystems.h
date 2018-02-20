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

// WindowsSystemRemoteSystems.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
#define OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsSystemRemoteSystems.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WSRRemoteSystem, WSRRemoteSystemWatcher, WSRKnownRemoteSystemCapabilities, WSRRemoteSystemAuthorizationKindFilter, WSRRemoteSystemAddedEventArgs, WSRRemoteSystemUpdatedEventArgs, WSRRemoteSystemRemovedEventArgs, WSRRemoteSystemConnectionRequest, WSRRemoteSystemKinds, WSRRemoteSystemKindFilter, WSRRemoteSystemDiscoveryTypeFilter, WSRRemoteSystemStatusTypeFilter, WSRRemoteSystemSession, WSRRemoteSystemSessionJoinResult, WSRRemoteSystemSessionInfo, WSRRemoteSystemSessionAddedEventArgs, WSRRemoteSystemSessionUpdatedEventArgs, WSRRemoteSystemSessionRemovedEventArgs, WSRRemoteSystemSessionWatcher, WSRRemoteSystemSessionInvitation, WSRRemoteSystemSessionInvitationReceivedEventArgs, WSRRemoteSystemSessionInvitationListener, WSRRemoteSystemSessionParticipant, WSRRemoteSystemSessionParticipantAddedEventArgs, WSRRemoteSystemSessionParticipantRemovedEventArgs, WSRRemoteSystemSessionParticipantWatcher, WSRRemoteSystemSessionJoinRequest, WSRRemoteSystemSessionJoinRequestedEventArgs, WSRRemoteSystemSessionCreationResult, WSRRemoteSystemSessionOptions, WSRRemoteSystemSessionController, WSRRemoteSystemSessionDisconnectedEventArgs, WSRRemoteSystemSessionValueSetReceivedEventArgs, WSRRemoteSystemSessionMessageChannel;
@protocol WSRIRemoteSystemFilter, WSRIRemoteSystemStatics, WSRIRemoteSystemStatics2, WSRIRemoteSystem, WSRIRemoteSystem2, WSRIRemoteSystem3, WSRIKnownRemoteSystemCapabilitiesStatics, WSRIRemoteSystemAuthorizationKindFilterFactory, WSRIRemoteSystemAuthorizationKindFilter, WSRIRemoteSystemWatcher, WSRIRemoteSystemAddedEventArgs, WSRIRemoteSystemUpdatedEventArgs, WSRIRemoteSystemRemovedEventArgs, WSRIRemoteSystemConnectionRequestFactory, WSRIRemoteSystemConnectionRequest, WSRIRemoteSystemKindStatics, WSRIRemoteSystemKindStatics2, WSRIRemoteSystemKindFilterFactory, WSRIRemoteSystemKindFilter, WSRIRemoteSystemDiscoveryTypeFilterFactory, WSRIRemoteSystemDiscoveryTypeFilter, WSRIRemoteSystemStatusTypeFilterFactory, WSRIRemoteSystemStatusTypeFilter, WSRIRemoteSystemSessionJoinResult, WSRIRemoteSystemSessionInfo, WSRIRemoteSystemSessionAddedEventArgs, WSRIRemoteSystemSessionUpdatedEventArgs, WSRIRemoteSystemSessionRemovedEventArgs, WSRIRemoteSystemSessionWatcher, WSRIRemoteSystemSessionInvitation, WSRIRemoteSystemSessionInvitationReceivedEventArgs, WSRIRemoteSystemSessionInvitationListener, WSRIRemoteSystemSessionParticipant, WSRIRemoteSystemSessionParticipantAddedEventArgs, WSRIRemoteSystemSessionParticipantRemovedEventArgs, WSRIRemoteSystemSessionParticipantWatcher, WSRIRemoteSystemSessionJoinRequest, WSRIRemoteSystemSessionJoinRequestedEventArgs, WSRIRemoteSystemSessionCreationResult, WSRIRemoteSystemSessionOptions, WSRIRemoteSystemSessionController, WSRIRemoteSystemSessionControllerFactory, WSRIRemoteSystemSessionDisconnectedEventArgs, WSRIRemoteSystemSession, WSRIRemoteSystemSessionStatics, WSRIRemoteSystemSessionValueSetReceivedEventArgs, WSRIRemoteSystemSessionMessageChannel, WSRIRemoteSystemSessionMessageChannelFactory;

// Windows.System.RemoteSystems.RemoteSystemStatus
enum _WSRRemoteSystemStatus {
    WSRRemoteSystemStatusUnavailable = 0,
    WSRRemoteSystemStatusDiscoveringAvailability = 1,
    WSRRemoteSystemStatusAvailable = 2,
    WSRRemoteSystemStatusUnknown = 3,
};
typedef unsigned WSRRemoteSystemStatus;

// Windows.System.RemoteSystems.RemoteSystemDiscoveryType
enum _WSRRemoteSystemDiscoveryType {
    WSRRemoteSystemDiscoveryTypeAny = 0,
    WSRRemoteSystemDiscoveryTypeProximal = 1,
    WSRRemoteSystemDiscoveryTypeCloud = 2,
    WSRRemoteSystemDiscoveryTypeSpatiallyProximal = 3,
};
typedef unsigned WSRRemoteSystemDiscoveryType;

// Windows.System.RemoteSystems.RemoteSystemStatusType
enum _WSRRemoteSystemStatusType {
    WSRRemoteSystemStatusTypeAny = 0,
    WSRRemoteSystemStatusTypeAvailable = 1,
};
typedef unsigned WSRRemoteSystemStatusType;

// Windows.System.RemoteSystems.RemoteSystemAccessStatus
enum _WSRRemoteSystemAccessStatus {
    WSRRemoteSystemAccessStatusUnspecified = 0,
    WSRRemoteSystemAccessStatusAllowed = 1,
    WSRRemoteSystemAccessStatusDeniedByUser = 2,
    WSRRemoteSystemAccessStatusDeniedBySystem = 3,
};
typedef unsigned WSRRemoteSystemAccessStatus;

// Windows.System.RemoteSystems.RemoteSystemAuthorizationKind
enum _WSRRemoteSystemAuthorizationKind {
    WSRRemoteSystemAuthorizationKindSameUser = 0,
    WSRRemoteSystemAuthorizationKindAnonymous = 1,
};
typedef unsigned WSRRemoteSystemAuthorizationKind;

// Windows.System.RemoteSystems.RemoteSystemSessionJoinStatus
enum _WSRRemoteSystemSessionJoinStatus {
    WSRRemoteSystemSessionJoinStatusSuccess = 0,
    WSRRemoteSystemSessionJoinStatusSessionLimitsExceeded = 1,
    WSRRemoteSystemSessionJoinStatusOperationAborted = 2,
    WSRRemoteSystemSessionJoinStatusSessionUnavailable = 3,
    WSRRemoteSystemSessionJoinStatusRejectedByController = 4,
};
typedef unsigned WSRRemoteSystemSessionJoinStatus;

// Windows.System.RemoteSystems.RemoteSystemSessionWatcherStatus
enum _WSRRemoteSystemSessionWatcherStatus {
    WSRRemoteSystemSessionWatcherStatusCreated = 0,
    WSRRemoteSystemSessionWatcherStatusStarted = 1,
    WSRRemoteSystemSessionWatcherStatusEnumerationCompleted = 2,
    WSRRemoteSystemSessionWatcherStatusStopping = 3,
    WSRRemoteSystemSessionWatcherStatusStopped = 4,
    WSRRemoteSystemSessionWatcherStatusAborted = 5,
};
typedef unsigned WSRRemoteSystemSessionWatcherStatus;

// Windows.System.RemoteSystems.RemoteSystemSessionParticipantWatcherStatus
enum _WSRRemoteSystemSessionParticipantWatcherStatus {
    WSRRemoteSystemSessionParticipantWatcherStatusCreated = 0,
    WSRRemoteSystemSessionParticipantWatcherStatusStarted = 1,
    WSRRemoteSystemSessionParticipantWatcherStatusEnumerationCompleted = 2,
    WSRRemoteSystemSessionParticipantWatcherStatusStopping = 3,
    WSRRemoteSystemSessionParticipantWatcherStatusStopped = 4,
    WSRRemoteSystemSessionParticipantWatcherStatusAborted = 5,
};
typedef unsigned WSRRemoteSystemSessionParticipantWatcherStatus;

// Windows.System.RemoteSystems.RemoteSystemSessionCreationStatus
enum _WSRRemoteSystemSessionCreationStatus {
    WSRRemoteSystemSessionCreationStatusSuccess = 0,
    WSRRemoteSystemSessionCreationStatusSessionLimitsExceeded = 1,
    WSRRemoteSystemSessionCreationStatusOperationAborted = 2,
};
typedef unsigned WSRRemoteSystemSessionCreationStatus;

// Windows.System.RemoteSystems.RemoteSystemSessionDisconnectedReason
enum _WSRRemoteSystemSessionDisconnectedReason {
    WSRRemoteSystemSessionDisconnectedReasonSessionUnavailable = 0,
    WSRRemoteSystemSessionDisconnectedReasonRemovedByController = 1,
    WSRRemoteSystemSessionDisconnectedReasonSessionClosed = 2,
};
typedef unsigned WSRRemoteSystemSessionDisconnectedReason;

// Windows.System.RemoteSystems.RemoteSystemSessionMessageChannelReliability
enum _WSRRemoteSystemSessionMessageChannelReliability {
    WSRRemoteSystemSessionMessageChannelReliabilityReliable = 0,
    WSRRemoteSystemSessionMessageChannelReliabilityUnreliable = 1,
};
typedef unsigned WSRRemoteSystemSessionMessageChannelReliability;

#include "WindowsNetworking.h"
#include "WindowsFoundation.h"
#include "WindowsFoundationCollections.h"

#import <Foundation/Foundation.h>

// Windows.System.RemoteSystems.IRemoteSystemFilter
#ifndef __WSRIRemoteSystemFilter_DEFINED__
#define __WSRIRemoteSystemFilter_DEFINED__

@protocol WSRIRemoteSystemFilter
@end

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRIRemoteSystemFilter : RTObject <WSRIRemoteSystemFilter>
@end

#endif // __WSRIRemoteSystemFilter_DEFINED__

// Windows.System.RemoteSystems.RemoteSystem
#ifndef __WSRRemoteSystem_DEFINED__
#define __WSRRemoteSystem_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystem : RTObject
+ (BOOL)isAuthorizationKindEnabled:(WSRRemoteSystemAuthorizationKind)kind;
+ (void)findByHostNameAsync:(WNHostName*)hostName success:(void (^)(WSRRemoteSystem*))success failure:(void (^)(NSError*))failure;
+ (WSRRemoteSystemWatcher*)createWatcher;
+ (WSRRemoteSystemWatcher*)createWatcherWithFilters:(id<NSFastEnumeration> /* RTObject<WSRIRemoteSystemFilter>* */)filters;
+ (void)requestAccessAsyncWithSuccess:(void (^)(WSRRemoteSystemAccessStatus))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * displayName;
@property (readonly) NSString * id;
@property (readonly) BOOL isAvailableByProximity;
@property (readonly) NSString * kind;
@property (readonly) WSRRemoteSystemStatus status;
@property (readonly) BOOL isAvailableBySpatialProximity;
@property (readonly) NSString * manufacturerDisplayName;
@property (readonly) NSString * modelDisplayName;
- (void)getCapabilitySupportedAsync:(NSString *)capabilityName success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSRRemoteSystem_DEFINED__

// Windows.System.RemoteSystems.RemoteSystemWatcher
#ifndef __WSRRemoteSystemWatcher_DEFINED__
#define __WSRRemoteSystemWatcher_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystemWatcher : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (EventRegistrationToken)addRemoteSystemAddedEvent:(void(^)(WSRRemoteSystemWatcher*, WSRRemoteSystemAddedEventArgs*))del;
- (void)removeRemoteSystemAddedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addRemoteSystemRemovedEvent:(void(^)(WSRRemoteSystemWatcher*, WSRRemoteSystemRemovedEventArgs*))del;
- (void)removeRemoteSystemRemovedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addRemoteSystemUpdatedEvent:(void(^)(WSRRemoteSystemWatcher*, WSRRemoteSystemUpdatedEventArgs*))del;
- (void)removeRemoteSystemUpdatedEvent:(EventRegistrationToken)tok;
- (void)start;
- (void)stop;
@end

#endif // __WSRRemoteSystemWatcher_DEFINED__

// Windows.System.RemoteSystems.KnownRemoteSystemCapabilities
#ifndef __WSRKnownRemoteSystemCapabilities_DEFINED__
#define __WSRKnownRemoteSystemCapabilities_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRKnownRemoteSystemCapabilities : RTObject
+ (NSString *)appService;
+ (NSString *)launchUri;
+ (NSString *)remoteSession;
+ (NSString *)spatialEntity;
@end

#endif // __WSRKnownRemoteSystemCapabilities_DEFINED__

// Windows.System.RemoteSystems.RemoteSystemAuthorizationKindFilter
#ifndef __WSRRemoteSystemAuthorizationKindFilter_DEFINED__
#define __WSRRemoteSystemAuthorizationKindFilter_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystemAuthorizationKindFilter : RTObject <WSRIRemoteSystemFilter>
+ (WSRRemoteSystemAuthorizationKindFilter*)make:(WSRRemoteSystemAuthorizationKind)remoteSystemAuthorizationKind ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSRRemoteSystemAuthorizationKind remoteSystemAuthorizationKind;
@end

#endif // __WSRRemoteSystemAuthorizationKindFilter_DEFINED__

// Windows.System.RemoteSystems.RemoteSystemAddedEventArgs
#ifndef __WSRRemoteSystemAddedEventArgs_DEFINED__
#define __WSRRemoteSystemAddedEventArgs_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystemAddedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSRRemoteSystem* remoteSystem;
@end

#endif // __WSRRemoteSystemAddedEventArgs_DEFINED__

// Windows.System.RemoteSystems.RemoteSystemUpdatedEventArgs
#ifndef __WSRRemoteSystemUpdatedEventArgs_DEFINED__
#define __WSRRemoteSystemUpdatedEventArgs_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystemUpdatedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSRRemoteSystem* remoteSystem;
@end

#endif // __WSRRemoteSystemUpdatedEventArgs_DEFINED__

// Windows.System.RemoteSystems.RemoteSystemRemovedEventArgs
#ifndef __WSRRemoteSystemRemovedEventArgs_DEFINED__
#define __WSRRemoteSystemRemovedEventArgs_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystemRemovedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * remoteSystemId;
@end

#endif // __WSRRemoteSystemRemovedEventArgs_DEFINED__

// Windows.System.RemoteSystems.RemoteSystemConnectionRequest
#ifndef __WSRRemoteSystemConnectionRequest_DEFINED__
#define __WSRRemoteSystemConnectionRequest_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystemConnectionRequest : RTObject
+ (WSRRemoteSystemConnectionRequest*)make:(WSRRemoteSystem*)remoteSystem ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSRRemoteSystem* remoteSystem;
@end

#endif // __WSRRemoteSystemConnectionRequest_DEFINED__

// Windows.System.RemoteSystems.RemoteSystemKinds
#ifndef __WSRRemoteSystemKinds_DEFINED__
#define __WSRRemoteSystemKinds_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystemKinds : RTObject
+ (NSString *)desktop;
+ (NSString *)holographic;
+ (NSString *)hub;
+ (NSString *)phone;
+ (NSString *)xbox;
+ (NSString *)iot;
+ (NSString *)laptop;
+ (NSString *)tablet;
@end

#endif // __WSRRemoteSystemKinds_DEFINED__

// Windows.System.RemoteSystems.RemoteSystemKindFilter
#ifndef __WSRRemoteSystemKindFilter_DEFINED__
#define __WSRRemoteSystemKindFilter_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystemKindFilter : RTObject <WSRIRemoteSystemFilter>
+ (WSRRemoteSystemKindFilter*)make:(id<NSFastEnumeration> /* NSString * */)remoteSystemKinds ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* NSString * */ remoteSystemKinds;
@end

#endif // __WSRRemoteSystemKindFilter_DEFINED__

// Windows.System.RemoteSystems.RemoteSystemDiscoveryTypeFilter
#ifndef __WSRRemoteSystemDiscoveryTypeFilter_DEFINED__
#define __WSRRemoteSystemDiscoveryTypeFilter_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystemDiscoveryTypeFilter : RTObject <WSRIRemoteSystemFilter>
+ (WSRRemoteSystemDiscoveryTypeFilter*)make:(WSRRemoteSystemDiscoveryType)discoveryType ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSRRemoteSystemDiscoveryType remoteSystemDiscoveryType;
@end

#endif // __WSRRemoteSystemDiscoveryTypeFilter_DEFINED__

// Windows.System.RemoteSystems.RemoteSystemStatusTypeFilter
#ifndef __WSRRemoteSystemStatusTypeFilter_DEFINED__
#define __WSRRemoteSystemStatusTypeFilter_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystemStatusTypeFilter : RTObject <WSRIRemoteSystemFilter>
+ (WSRRemoteSystemStatusTypeFilter*)make:(WSRRemoteSystemStatusType)remoteSystemStatusType ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSRRemoteSystemStatusType remoteSystemStatusType;
@end

#endif // __WSRRemoteSystemStatusTypeFilter_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.System.RemoteSystems.RemoteSystemSession
#ifndef __WSRRemoteSystemSession_DEFINED__
#define __WSRRemoteSystemSession_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystemSession : RTObject <WFIClosable>
+ (WSRRemoteSystemSessionWatcher*)createWatcher;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * controllerDisplayName;
@property (readonly) NSString * displayName;
@property (readonly) NSString * id;
- (EventRegistrationToken)addDisconnectedEvent:(void(^)(WSRRemoteSystemSession*, WSRRemoteSystemSessionDisconnectedEventArgs*))del;
- (void)removeDisconnectedEvent:(EventRegistrationToken)tok;
- (WSRRemoteSystemSessionParticipantWatcher*)createParticipantWatcher;
- (void)sendInvitationAsync:(WSRRemoteSystem*)invitee success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)close;
@end

#endif // __WSRRemoteSystemSession_DEFINED__

// Windows.System.RemoteSystems.RemoteSystemSessionJoinResult
#ifndef __WSRRemoteSystemSessionJoinResult_DEFINED__
#define __WSRRemoteSystemSessionJoinResult_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystemSessionJoinResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSRRemoteSystemSession* session;
@property (readonly) WSRRemoteSystemSessionJoinStatus status;
@end

#endif // __WSRRemoteSystemSessionJoinResult_DEFINED__

// Windows.System.RemoteSystems.RemoteSystemSessionInfo
#ifndef __WSRRemoteSystemSessionInfo_DEFINED__
#define __WSRRemoteSystemSessionInfo_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystemSessionInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * controllerDisplayName;
@property (readonly) NSString * displayName;
- (void)joinAsyncWithSuccess:(void (^)(WSRRemoteSystemSessionJoinResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSRRemoteSystemSessionInfo_DEFINED__

// Windows.System.RemoteSystems.RemoteSystemSessionAddedEventArgs
#ifndef __WSRRemoteSystemSessionAddedEventArgs_DEFINED__
#define __WSRRemoteSystemSessionAddedEventArgs_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystemSessionAddedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSRRemoteSystemSessionInfo* sessionInfo;
@end

#endif // __WSRRemoteSystemSessionAddedEventArgs_DEFINED__

// Windows.System.RemoteSystems.RemoteSystemSessionUpdatedEventArgs
#ifndef __WSRRemoteSystemSessionUpdatedEventArgs_DEFINED__
#define __WSRRemoteSystemSessionUpdatedEventArgs_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystemSessionUpdatedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSRRemoteSystemSessionInfo* sessionInfo;
@end

#endif // __WSRRemoteSystemSessionUpdatedEventArgs_DEFINED__

// Windows.System.RemoteSystems.RemoteSystemSessionRemovedEventArgs
#ifndef __WSRRemoteSystemSessionRemovedEventArgs_DEFINED__
#define __WSRRemoteSystemSessionRemovedEventArgs_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystemSessionRemovedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSRRemoteSystemSessionInfo* sessionInfo;
@end

#endif // __WSRRemoteSystemSessionRemovedEventArgs_DEFINED__

// Windows.System.RemoteSystems.RemoteSystemSessionWatcher
#ifndef __WSRRemoteSystemSessionWatcher_DEFINED__
#define __WSRRemoteSystemSessionWatcher_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystemSessionWatcher : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSRRemoteSystemSessionWatcherStatus status;
- (EventRegistrationToken)addAddedEvent:(void(^)(WSRRemoteSystemSessionWatcher*, WSRRemoteSystemSessionAddedEventArgs*))del;
- (void)removeAddedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addRemovedEvent:(void(^)(WSRRemoteSystemSessionWatcher*, WSRRemoteSystemSessionRemovedEventArgs*))del;
- (void)removeRemovedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUpdatedEvent:(void(^)(WSRRemoteSystemSessionWatcher*, WSRRemoteSystemSessionUpdatedEventArgs*))del;
- (void)removeUpdatedEvent:(EventRegistrationToken)tok;
- (void)start;
- (void)stop;
@end

#endif // __WSRRemoteSystemSessionWatcher_DEFINED__

// Windows.System.RemoteSystems.RemoteSystemSessionInvitation
#ifndef __WSRRemoteSystemSessionInvitation_DEFINED__
#define __WSRRemoteSystemSessionInvitation_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystemSessionInvitation : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSRRemoteSystem* sender;
@property (readonly) WSRRemoteSystemSessionInfo* sessionInfo;
@end

#endif // __WSRRemoteSystemSessionInvitation_DEFINED__

// Windows.System.RemoteSystems.RemoteSystemSessionInvitationReceivedEventArgs
#ifndef __WSRRemoteSystemSessionInvitationReceivedEventArgs_DEFINED__
#define __WSRRemoteSystemSessionInvitationReceivedEventArgs_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystemSessionInvitationReceivedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSRRemoteSystemSessionInvitation* invitation;
@end

#endif // __WSRRemoteSystemSessionInvitationReceivedEventArgs_DEFINED__

// Windows.System.RemoteSystems.RemoteSystemSessionInvitationListener
#ifndef __WSRRemoteSystemSessionInvitationListener_DEFINED__
#define __WSRRemoteSystemSessionInvitationListener_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystemSessionInvitationListener : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (EventRegistrationToken)addInvitationReceivedEvent:(void(^)(WSRRemoteSystemSessionInvitationListener*, WSRRemoteSystemSessionInvitationReceivedEventArgs*))del;
- (void)removeInvitationReceivedEvent:(EventRegistrationToken)tok;
@end

#endif // __WSRRemoteSystemSessionInvitationListener_DEFINED__

// Windows.System.RemoteSystems.RemoteSystemSessionParticipant
#ifndef __WSRRemoteSystemSessionParticipant_DEFINED__
#define __WSRRemoteSystemSessionParticipant_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystemSessionParticipant : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSRRemoteSystem* remoteSystem;
- (NSArray* /* WNHostName* */)getHostNames;
@end

#endif // __WSRRemoteSystemSessionParticipant_DEFINED__

// Windows.System.RemoteSystems.RemoteSystemSessionParticipantAddedEventArgs
#ifndef __WSRRemoteSystemSessionParticipantAddedEventArgs_DEFINED__
#define __WSRRemoteSystemSessionParticipantAddedEventArgs_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystemSessionParticipantAddedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSRRemoteSystemSessionParticipant* participant;
@end

#endif // __WSRRemoteSystemSessionParticipantAddedEventArgs_DEFINED__

// Windows.System.RemoteSystems.RemoteSystemSessionParticipantRemovedEventArgs
#ifndef __WSRRemoteSystemSessionParticipantRemovedEventArgs_DEFINED__
#define __WSRRemoteSystemSessionParticipantRemovedEventArgs_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystemSessionParticipantRemovedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSRRemoteSystemSessionParticipant* participant;
@end

#endif // __WSRRemoteSystemSessionParticipantRemovedEventArgs_DEFINED__

// Windows.System.RemoteSystems.RemoteSystemSessionParticipantWatcher
#ifndef __WSRRemoteSystemSessionParticipantWatcher_DEFINED__
#define __WSRRemoteSystemSessionParticipantWatcher_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystemSessionParticipantWatcher : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSRRemoteSystemSessionParticipantWatcherStatus status;
- (EventRegistrationToken)addAddedEvent:(void(^)(WSRRemoteSystemSessionParticipantWatcher*, WSRRemoteSystemSessionParticipantAddedEventArgs*))del;
- (void)removeAddedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addEnumerationCompletedEvent:(void(^)(WSRRemoteSystemSessionParticipantWatcher*, RTObject*))del;
- (void)removeEnumerationCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addRemovedEvent:(void(^)(WSRRemoteSystemSessionParticipantWatcher*, WSRRemoteSystemSessionParticipantRemovedEventArgs*))del;
- (void)removeRemovedEvent:(EventRegistrationToken)tok;
- (void)start;
- (void)stop;
@end

#endif // __WSRRemoteSystemSessionParticipantWatcher_DEFINED__

// Windows.System.RemoteSystems.RemoteSystemSessionJoinRequest
#ifndef __WSRRemoteSystemSessionJoinRequest_DEFINED__
#define __WSRRemoteSystemSessionJoinRequest_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystemSessionJoinRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSRRemoteSystemSessionParticipant* participant;
- (void)accept;
@end

#endif // __WSRRemoteSystemSessionJoinRequest_DEFINED__

// Windows.System.RemoteSystems.RemoteSystemSessionJoinRequestedEventArgs
#ifndef __WSRRemoteSystemSessionJoinRequestedEventArgs_DEFINED__
#define __WSRRemoteSystemSessionJoinRequestedEventArgs_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystemSessionJoinRequestedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSRRemoteSystemSessionJoinRequest* joinRequest;
- (WFDeferral*)getDeferral;
@end

#endif // __WSRRemoteSystemSessionJoinRequestedEventArgs_DEFINED__

// Windows.System.RemoteSystems.RemoteSystemSessionCreationResult
#ifndef __WSRRemoteSystemSessionCreationResult_DEFINED__
#define __WSRRemoteSystemSessionCreationResult_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystemSessionCreationResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSRRemoteSystemSession* session;
@property (readonly) WSRRemoteSystemSessionCreationStatus status;
@end

#endif // __WSRRemoteSystemSessionCreationResult_DEFINED__

// Windows.System.RemoteSystems.RemoteSystemSessionOptions
#ifndef __WSRRemoteSystemSessionOptions_DEFINED__
#define __WSRRemoteSystemSessionOptions_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystemSessionOptions : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isInviteOnly;
@end

#endif // __WSRRemoteSystemSessionOptions_DEFINED__

// Windows.System.RemoteSystems.RemoteSystemSessionController
#ifndef __WSRRemoteSystemSessionController_DEFINED__
#define __WSRRemoteSystemSessionController_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystemSessionController : RTObject
+ (WSRRemoteSystemSessionController*)makeController:(NSString *)displayName ACTIVATOR;
+ (WSRRemoteSystemSessionController*)makeControllerWithSessionOptions:(NSString *)displayName options:(WSRRemoteSystemSessionOptions*)options ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (EventRegistrationToken)addJoinRequestedEvent:(void(^)(WSRRemoteSystemSessionController*, WSRRemoteSystemSessionJoinRequestedEventArgs*))del;
- (void)removeJoinRequestedEvent:(EventRegistrationToken)tok;
- (void)removeParticipantAsync:(WSRRemoteSystemSessionParticipant*)pParticipant success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)createSessionAsyncWithSuccess:(void (^)(WSRRemoteSystemSessionCreationResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSRRemoteSystemSessionController_DEFINED__

// Windows.System.RemoteSystems.RemoteSystemSessionDisconnectedEventArgs
#ifndef __WSRRemoteSystemSessionDisconnectedEventArgs_DEFINED__
#define __WSRRemoteSystemSessionDisconnectedEventArgs_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystemSessionDisconnectedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSRRemoteSystemSessionDisconnectedReason reason;
@end

#endif // __WSRRemoteSystemSessionDisconnectedEventArgs_DEFINED__

// Windows.System.RemoteSystems.RemoteSystemSessionValueSetReceivedEventArgs
#ifndef __WSRRemoteSystemSessionValueSetReceivedEventArgs_DEFINED__
#define __WSRRemoteSystemSessionValueSetReceivedEventArgs_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystemSessionValueSetReceivedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFCValueSet* message;
@property (readonly) WSRRemoteSystemSessionParticipant* sender;
@end

#endif // __WSRRemoteSystemSessionValueSetReceivedEventArgs_DEFINED__

// Windows.System.RemoteSystems.RemoteSystemSessionMessageChannel
#ifndef __WSRRemoteSystemSessionMessageChannel_DEFINED__
#define __WSRRemoteSystemSessionMessageChannel_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystemSessionMessageChannel : RTObject
+ (WSRRemoteSystemSessionMessageChannel*)make:(WSRRemoteSystemSession*)session channelName:(NSString *)channelName ACTIVATOR;
+ (WSRRemoteSystemSessionMessageChannel*)makeWithReliability:(WSRRemoteSystemSession*)session channelName:(NSString *)channelName reliability:(WSRRemoteSystemSessionMessageChannelReliability)reliability ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSRRemoteSystemSession* session;
- (EventRegistrationToken)addValueSetReceivedEvent:(void(^)(WSRRemoteSystemSessionMessageChannel*, WSRRemoteSystemSessionValueSetReceivedEventArgs*))del;
- (void)removeValueSetReceivedEvent:(EventRegistrationToken)tok;
- (void)broadcastValueSetAsync:(WFCValueSet*)messageData success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)sendValueSetAsync:(WFCValueSet*)messageData participant:(WSRRemoteSystemSessionParticipant*)participant success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)sendValueSetToParticipantsAsync:(WFCValueSet*)messageData participants:(id<NSFastEnumeration> /* WSRRemoteSystemSessionParticipant* */)participants success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSRRemoteSystemSessionMessageChannel_DEFINED__

