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

// WindowsNetworkingServiceDiscoveryDnssd.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSNETWORKINGSERVICEDISCOVERYDNSSDEXPORT
#define OBJCUWPWINDOWSNETWORKINGSERVICEDISCOVERYDNSSDEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsNetworkingServiceDiscoveryDnssd.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WNSDDnssdServiceWatcher, WNSDDnssdServiceInstance, WNSDDnssdRegistrationResult, WNSDDnssdServiceInstanceCollection;
@protocol WNSDIDnssdServiceWatcher, WNSDIDnssdRegistrationResult, WNSDIDnssdServiceInstanceFactory, WNSDIDnssdServiceInstance;

// Windows.Networking.ServiceDiscovery.Dnssd.DnssdRegistrationStatus
enum _WNSDDnssdRegistrationStatus {
    WNSDDnssdRegistrationStatusSuccess = 0,
    WNSDDnssdRegistrationStatusInvalidServiceName = 1,
    WNSDDnssdRegistrationStatusServerError = 2,
    WNSDDnssdRegistrationStatusSecurityError = 3,
};
typedef unsigned WNSDDnssdRegistrationStatus;

// Windows.Networking.ServiceDiscovery.Dnssd.DnssdServiceWatcherStatus
enum _WNSDDnssdServiceWatcherStatus {
    WNSDDnssdServiceWatcherStatusCreated = 0,
    WNSDDnssdServiceWatcherStatusStarted = 1,
    WNSDDnssdServiceWatcherStatusEnumerationCompleted = 2,
    WNSDDnssdServiceWatcherStatusStopping = 3,
    WNSDDnssdServiceWatcherStatusStopped = 4,
    WNSDDnssdServiceWatcherStatusAborted = 5,
};
typedef unsigned WNSDDnssdServiceWatcherStatus;

#include "WindowsFoundation.h"
#include "WindowsNetworkingSockets.h"
#include "WindowsNetworking.h"
#include "WindowsNetworkingConnectivity.h"

#import <Foundation/Foundation.h>

// Windows.Networking.ServiceDiscovery.Dnssd.DnssdServiceWatcher
#ifndef __WNSDDnssdServiceWatcher_DEFINED__
#define __WNSDDnssdServiceWatcher_DEFINED__

OBJCUWPWINDOWSNETWORKINGSERVICEDISCOVERYDNSSDEXPORT
@interface WNSDDnssdServiceWatcher : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WNSDDnssdServiceWatcherStatus status;
- (EventRegistrationToken)addAddedEvent:(void(^)(WNSDDnssdServiceWatcher*, WNSDDnssdServiceInstance*))del;
- (void)removeAddedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addEnumerationCompletedEvent:(void(^)(WNSDDnssdServiceWatcher*, RTObject*))del;
- (void)removeEnumerationCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStoppedEvent:(void(^)(WNSDDnssdServiceWatcher*, RTObject*))del;
- (void)removeStoppedEvent:(EventRegistrationToken)tok;
- (void)start;
- (void)stop;
@end

#endif // __WNSDDnssdServiceWatcher_DEFINED__

// Windows.Foundation.IStringable
#ifndef __WFIStringable_DEFINED__
#define __WFIStringable_DEFINED__

@protocol WFIStringable
- (NSString *)toString;
@end

OBJCUWPWINDOWSNETWORKINGSERVICEDISCOVERYDNSSDEXPORT
@interface WFIStringable : RTObject <WFIStringable>
@end

#endif // __WFIStringable_DEFINED__

// Windows.Networking.ServiceDiscovery.Dnssd.DnssdServiceInstance
#ifndef __WNSDDnssdServiceInstance_DEFINED__
#define __WNSDDnssdServiceInstance_DEFINED__

OBJCUWPWINDOWSNETWORKINGSERVICEDISCOVERYDNSSDEXPORT
@interface WNSDDnssdServiceInstance : RTObject <WFIStringable>
+ (WNSDDnssdServiceInstance*)make:(NSString *)dnssdServiceInstanceName hostName:(WNHostName*)hostName port:(unsigned short)port ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property unsigned short weight;
@property unsigned short priority;
@property unsigned short port;
@property (retain) WNHostName* hostName;
@property (retain) NSString * dnssdServiceInstanceName;
@property (readonly) NSMutableDictionary* /* NSString *, NSString * */ textAttributes;
- (void)registerStreamSocketListenerAsync1:(WNSStreamSocketListener*)socket success:(void (^)(WNSDDnssdRegistrationResult*))success failure:(void (^)(NSError*))failure;
- (void)registerStreamSocketListenerAsync2:(WNSStreamSocketListener*)socket adapter:(WNCNetworkAdapter*)adapter success:(void (^)(WNSDDnssdRegistrationResult*))success failure:(void (^)(NSError*))failure;
- (void)registerDatagramSocketAsync1:(WNSDatagramSocket*)socket success:(void (^)(WNSDDnssdRegistrationResult*))success failure:(void (^)(NSError*))failure;
- (void)registerDatagramSocketAsync2:(WNSDatagramSocket*)socket adapter:(WNCNetworkAdapter*)adapter success:(void (^)(WNSDDnssdRegistrationResult*))success failure:(void (^)(NSError*))failure;
- (NSString *)toString;
@end

#endif // __WNSDDnssdServiceInstance_DEFINED__

// Windows.Networking.ServiceDiscovery.Dnssd.DnssdRegistrationResult
#ifndef __WNSDDnssdRegistrationResult_DEFINED__
#define __WNSDDnssdRegistrationResult_DEFINED__

OBJCUWPWINDOWSNETWORKINGSERVICEDISCOVERYDNSSDEXPORT
@interface WNSDDnssdRegistrationResult : RTObject <WFIStringable>
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL hasInstanceNameChanged;
@property (readonly) WNHostName* iPAddress;
@property (readonly) WNSDDnssdRegistrationStatus status;
- (NSString *)toString;
@end

#endif // __WNSDDnssdRegistrationResult_DEFINED__

// Windows.Networking.ServiceDiscovery.Dnssd.DnssdServiceInstanceCollection
#ifndef __WNSDDnssdServiceInstanceCollection_DEFINED__
#define __WNSDDnssdServiceInstanceCollection_DEFINED__

OBJCUWPWINDOWSNETWORKINGSERVICEDISCOVERYDNSSDEXPORT
@interface WNSDDnssdServiceInstanceCollection : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int size;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(id __unsafe_unretained [])buffer
                                    count:(NSUInteger)len;

@end

#endif // __WNSDDnssdServiceInstanceCollection_DEFINED__

