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

@class WSRRemoteSystem, WSRRemoteSystemWatcher, WSRRemoteSystemAddedEventArgs, WSRRemoteSystemUpdatedEventArgs,
    WSRRemoteSystemRemovedEventArgs, WSRRemoteSystemConnectionRequest, WSRRemoteSystemKinds, WSRRemoteSystemKindFilter,
    WSRRemoteSystemDiscoveryTypeFilter, WSRRemoteSystemStatusTypeFilter;
@protocol WSRIRemoteSystemFilter
, WSRIRemoteSystemStatics, WSRIRemoteSystem, WSRIRemoteSystemWatcher, WSRIRemoteSystemAddedEventArgs, WSRIRemoteSystemUpdatedEventArgs,
    WSRIRemoteSystemRemovedEventArgs, WSRIRemoteSystemConnectionRequestFactory, WSRIRemoteSystemConnectionRequest,
    WSRIRemoteSystemKindStatics, WSRIRemoteSystemKindFilterFactory, WSRIRemoteSystemKindFilter, WSRIRemoteSystemDiscoveryTypeFilterFactory,
    WSRIRemoteSystemDiscoveryTypeFilter, WSRIRemoteSystemStatusTypeFilterFactory, WSRIRemoteSystemStatusTypeFilter;

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

#include "WindowsNetworking.h"
#include "WindowsFoundation.h"

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
+ (void)findByHostNameAsync:(WNHostName*)hostName success:(void (^)(WSRRemoteSystem*))success failure:(void (^)(NSError*))failure;
+ (WSRRemoteSystemWatcher*)createWatcher;
+ (WSRRemoteSystemWatcher*)createWatcherWithFilters:(id<NSFastEnumeration> /* RTObject<WSRIRemoteSystemFilter>* */)filters;
+ (void)requestAccessAsyncWithSuccess:(void (^)(WSRRemoteSystemAccessStatus))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) NSString* displayName;
@property (readonly) NSString* id;
@property (readonly) BOOL isAvailableByProximity;
@property (readonly) NSString* kind;
@property (readonly) WSRRemoteSystemStatus status;
@end

#endif // __WSRRemoteSystem_DEFINED__

// Windows.System.RemoteSystems.RemoteSystemWatcher
#ifndef __WSRRemoteSystemWatcher_DEFINED__
#define __WSRRemoteSystemWatcher_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystemWatcher : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
- (EventRegistrationToken)addRemoteSystemAddedEvent:(void (^)(WSRRemoteSystemWatcher*, WSRRemoteSystemAddedEventArgs*))del;
- (void)removeRemoteSystemAddedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addRemoteSystemRemovedEvent:(void (^)(WSRRemoteSystemWatcher*, WSRRemoteSystemRemovedEventArgs*))del;
- (void)removeRemoteSystemRemovedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addRemoteSystemUpdatedEvent:(void (^)(WSRRemoteSystemWatcher*, WSRRemoteSystemUpdatedEventArgs*))del;
- (void)removeRemoteSystemUpdatedEvent:(EventRegistrationToken)tok;
- (void)start;
- (void)stop;
@end

#endif // __WSRRemoteSystemWatcher_DEFINED__

// Windows.System.RemoteSystems.RemoteSystemAddedEventArgs
#ifndef __WSRRemoteSystemAddedEventArgs_DEFINED__
#define __WSRRemoteSystemAddedEventArgs_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystemAddedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
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
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
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
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) NSString* remoteSystemId;
@end

#endif // __WSRRemoteSystemRemovedEventArgs_DEFINED__

// Windows.System.RemoteSystems.RemoteSystemConnectionRequest
#ifndef __WSRRemoteSystemConnectionRequest_DEFINED__
#define __WSRRemoteSystemConnectionRequest_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystemConnectionRequest : RTObject
+ (WSRRemoteSystemConnectionRequest*)make:(WSRRemoteSystem*)remoteSystem ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WSRRemoteSystem* remoteSystem;
@end

#endif // __WSRRemoteSystemConnectionRequest_DEFINED__

// Windows.System.RemoteSystems.RemoteSystemKinds
#ifndef __WSRRemoteSystemKinds_DEFINED__
#define __WSRRemoteSystemKinds_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystemKinds : RTObject
+ (NSString*)desktop;
+ (NSString*)holographic;
+ (NSString*)hub;
+ (NSString*)phone;
+ (NSString*)xbox;
@end

#endif // __WSRRemoteSystemKinds_DEFINED__

// Windows.System.RemoteSystems.RemoteSystemKindFilter
#ifndef __WSRRemoteSystemKindFilter_DEFINED__
#define __WSRRemoteSystemKindFilter_DEFINED__

OBJCUWPWINDOWSSYSTEMREMOTESYSTEMSEXPORT
@interface WSRRemoteSystemKindFilter : RTObject <WSRIRemoteSystemFilter>
+ (WSRRemoteSystemKindFilter*)make:(id<NSFastEnumeration> /* NSString * */)remoteSystemKinds ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
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
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
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
+ (instancetype)createWith:(IInspectable*)obj __attribute__((ns_returns_autoreleased));
#endif
@property (readonly) WSRRemoteSystemStatusType remoteSystemStatusType;
@end

#endif // __WSRRemoteSystemStatusTypeFilter_DEFINED__
