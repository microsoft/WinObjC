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

// WindowsNetworkingXboxLive.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSNETWORKINGXBOXLIVEEXPORT
#define OBJCUWPWINDOWSNETWORKINGXBOXLIVEEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsNetworkingXboxLive.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WNXXboxLiveDeviceAddress, WNXXboxLiveEndpointPair, WNXXboxLiveEndpointPairTemplate, WNXXboxLiveInboundEndpointPairCreatedEventArgs, WNXXboxLiveEndpointPairCreationResult, WNXXboxLiveEndpointPairStateChangedEventArgs, WNXXboxLiveQualityOfServiceMetricResult, WNXXboxLiveQualityOfServicePrivatePayloadResult, WNXXboxLiveQualityOfServiceMeasurement;
@protocol WNXIXboxLiveDeviceAddressStatics, WNXIXboxLiveDeviceAddress, WNXIXboxLiveInboundEndpointPairCreatedEventArgs, WNXIXboxLiveEndpointPairCreationResult, WNXIXboxLiveEndpointPairTemplateStatics, WNXIXboxLiveEndpointPairTemplate, WNXIXboxLiveEndpointPairStateChangedEventArgs, WNXIXboxLiveEndpointPairStatics, WNXIXboxLiveEndpointPair, WNXIXboxLiveQualityOfServiceMetricResult, WNXIXboxLiveQualityOfServicePrivatePayloadResult, WNXIXboxLiveQualityOfServiceMeasurementStatics, WNXIXboxLiveQualityOfServiceMeasurement;

// Windows.Networking.XboxLive.XboxLiveNetworkAccessKind
enum _WNXXboxLiveNetworkAccessKind {
    WNXXboxLiveNetworkAccessKindOpen = 0,
    WNXXboxLiveNetworkAccessKindModerate = 1,
    WNXXboxLiveNetworkAccessKindStrict = 2,
};
typedef unsigned WNXXboxLiveNetworkAccessKind;

// Windows.Networking.XboxLive.XboxLiveSocketKind
enum _WNXXboxLiveSocketKind {
    WNXXboxLiveSocketKindNone = 0,
    WNXXboxLiveSocketKindDatagram = 1,
    WNXXboxLiveSocketKindStream = 2,
};
typedef unsigned WNXXboxLiveSocketKind;

// Windows.Networking.XboxLive.XboxLiveEndpointPairCreationBehaviors
enum _WNXXboxLiveEndpointPairCreationBehaviors {
    WNXXboxLiveEndpointPairCreationBehaviorsNone = 0,
    WNXXboxLiveEndpointPairCreationBehaviorsReevaluatePath = 1,
};
typedef unsigned WNXXboxLiveEndpointPairCreationBehaviors;

// Windows.Networking.XboxLive.XboxLiveEndpointPairCreationStatus
enum _WNXXboxLiveEndpointPairCreationStatus {
    WNXXboxLiveEndpointPairCreationStatusSucceeded = 0,
    WNXXboxLiveEndpointPairCreationStatusNoLocalNetworks = 1,
    WNXXboxLiveEndpointPairCreationStatusNoCompatibleNetworkPaths = 2,
    WNXXboxLiveEndpointPairCreationStatusLocalSystemNotAuthorized = 3,
    WNXXboxLiveEndpointPairCreationStatusCanceled = 4,
    WNXXboxLiveEndpointPairCreationStatusTimedOut = 5,
    WNXXboxLiveEndpointPairCreationStatusRemoteSystemNotAuthorized = 6,
    WNXXboxLiveEndpointPairCreationStatusRefusedDueToConfiguration = 7,
    WNXXboxLiveEndpointPairCreationStatusUnexpectedInternalError = 8,
};
typedef unsigned WNXXboxLiveEndpointPairCreationStatus;

// Windows.Networking.XboxLive.XboxLiveEndpointPairState
enum _WNXXboxLiveEndpointPairState {
    WNXXboxLiveEndpointPairStateInvalid = 0,
    WNXXboxLiveEndpointPairStateCreatingOutbound = 1,
    WNXXboxLiveEndpointPairStateCreatingInbound = 2,
    WNXXboxLiveEndpointPairStateReady = 3,
    WNXXboxLiveEndpointPairStateDeletingLocally = 4,
    WNXXboxLiveEndpointPairStateRemoteEndpointTerminating = 5,
    WNXXboxLiveEndpointPairStateDeleted = 6,
};
typedef unsigned WNXXboxLiveEndpointPairState;

// Windows.Networking.XboxLive.XboxLiveQualityOfServiceMetric
enum _WNXXboxLiveQualityOfServiceMetric {
    WNXXboxLiveQualityOfServiceMetricAverageLatencyInMilliseconds = 0,
    WNXXboxLiveQualityOfServiceMetricMinLatencyInMilliseconds = 1,
    WNXXboxLiveQualityOfServiceMetricMaxLatencyInMilliseconds = 2,
    WNXXboxLiveQualityOfServiceMetricAverageOutboundBitsPerSecond = 3,
    WNXXboxLiveQualityOfServiceMetricMinOutboundBitsPerSecond = 4,
    WNXXboxLiveQualityOfServiceMetricMaxOutboundBitsPerSecond = 5,
    WNXXboxLiveQualityOfServiceMetricAverageInboundBitsPerSecond = 6,
    WNXXboxLiveQualityOfServiceMetricMinInboundBitsPerSecond = 7,
    WNXXboxLiveQualityOfServiceMetricMaxInboundBitsPerSecond = 8,
};
typedef unsigned WNXXboxLiveQualityOfServiceMetric;

// Windows.Networking.XboxLive.XboxLiveQualityOfServiceMeasurementStatus
enum _WNXXboxLiveQualityOfServiceMeasurementStatus {
    WNXXboxLiveQualityOfServiceMeasurementStatusNotStarted = 0,
    WNXXboxLiveQualityOfServiceMeasurementStatusInProgress = 1,
    WNXXboxLiveQualityOfServiceMeasurementStatusInProgressWithProvisionalResults = 2,
    WNXXboxLiveQualityOfServiceMeasurementStatusSucceeded = 3,
    WNXXboxLiveQualityOfServiceMeasurementStatusNoLocalNetworks = 4,
    WNXXboxLiveQualityOfServiceMeasurementStatusNoCompatibleNetworkPaths = 5,
    WNXXboxLiveQualityOfServiceMeasurementStatusLocalSystemNotAuthorized = 6,
    WNXXboxLiveQualityOfServiceMeasurementStatusCanceled = 7,
    WNXXboxLiveQualityOfServiceMeasurementStatusTimedOut = 8,
    WNXXboxLiveQualityOfServiceMeasurementStatusRemoteSystemNotAuthorized = 9,
    WNXXboxLiveQualityOfServiceMeasurementStatusRefusedDueToConfiguration = 10,
    WNXXboxLiveQualityOfServiceMeasurementStatusUnexpectedInternalError = 11,
};
typedef unsigned WNXXboxLiveQualityOfServiceMeasurementStatus;

#include "WindowsFoundation.h"
#include "WindowsStorageStreams.h"
#include "WindowsNetworking.h"

#import <Foundation/Foundation.h>

// Windows.Networking.XboxLive.XboxLiveDeviceAddress
#ifndef __WNXXboxLiveDeviceAddress_DEFINED__
#define __WNXXboxLiveDeviceAddress_DEFINED__

OBJCUWPWINDOWSNETWORKINGXBOXLIVEEXPORT
@interface WNXXboxLiveDeviceAddress : RTObject
+ (WNXXboxLiveDeviceAddress*)createFromSnapshotBase64:(NSString *)base64;
+ (WNXXboxLiveDeviceAddress*)createFromSnapshotBuffer:(RTObject<WSSIBuffer>*)buffer;
+ (WNXXboxLiveDeviceAddress*)createFromSnapshotBytes:(NSArray* /* uint8_t */)buffer;
+ (WNXXboxLiveDeviceAddress*)getLocal;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isLocal;
@property (readonly) BOOL isValid;
@property (readonly) WNXXboxLiveNetworkAccessKind networkAccessKind;
+ (unsigned int)maxSnapshotBytesSize;
- (EventRegistrationToken)addSnapshotChangedEvent:(void(^)(WNXXboxLiveDeviceAddress*, RTObject*))del;
- (void)removeSnapshotChangedEvent:(EventRegistrationToken)tok;
- (NSString *)getSnapshotAsBase64;
- (RTObject<WSSIBuffer>*)getSnapshotAsBuffer;
- (void)getSnapshotAsBytes:(NSArray* /* uint8_t */*)buffer bytesWritten:(unsigned int*)bytesWritten;
- (int)compare:(WNXXboxLiveDeviceAddress*)otherDeviceAddress;
@end

#endif // __WNXXboxLiveDeviceAddress_DEFINED__

// Windows.Networking.XboxLive.XboxLiveEndpointPair
#ifndef __WNXXboxLiveEndpointPair_DEFINED__
#define __WNXXboxLiveEndpointPair_DEFINED__

OBJCUWPWINDOWSNETWORKINGXBOXLIVEEXPORT
@interface WNXXboxLiveEndpointPair : RTObject
+ (WNXXboxLiveEndpointPair*)findEndpointPairBySocketAddressBytes:(NSArray* /* uint8_t */)localSocketAddress remoteSocketAddress:(NSArray* /* uint8_t */)remoteSocketAddress;
+ (WNXXboxLiveEndpointPair*)findEndpointPairByHostNamesAndPorts:(WNHostName*)localHostName localPort:(NSString *)localPort remoteHostName:(WNHostName*)remoteHostName remotePort:(NSString *)remotePort;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WNHostName* localHostName;
@property (readonly) NSString * localPort;
@property (readonly) WNXXboxLiveDeviceAddress* remoteDeviceAddress;
@property (readonly) WNHostName* remoteHostName;
@property (readonly) NSString * remotePort;
@property (readonly) WNXXboxLiveEndpointPairState state;
@property (readonly) WNXXboxLiveEndpointPairTemplate* Template;
- (EventRegistrationToken)addStateChangedEvent:(void(^)(WNXXboxLiveEndpointPair*, WNXXboxLiveEndpointPairStateChangedEventArgs*))del;
- (void)removeStateChangedEvent:(EventRegistrationToken)tok;
- (RTObject<WFIAsyncAction>*)deleteAsync;
- (void)getRemoteSocketAddressBytes:(NSArray* /* uint8_t */*)socketAddress;
- (void)getLocalSocketAddressBytes:(NSArray* /* uint8_t */*)socketAddress;
@end

#endif // __WNXXboxLiveEndpointPair_DEFINED__

// Windows.Networking.XboxLive.XboxLiveEndpointPairTemplate
#ifndef __WNXXboxLiveEndpointPairTemplate_DEFINED__
#define __WNXXboxLiveEndpointPairTemplate_DEFINED__

OBJCUWPWINDOWSNETWORKINGXBOXLIVEEXPORT
@interface WNXXboxLiveEndpointPairTemplate : RTObject
+ (WNXXboxLiveEndpointPairTemplate*)getTemplateByName:(NSString *)name;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned short acceptorBoundPortRangeLower;
@property (readonly) unsigned short acceptorBoundPortRangeUpper;
@property (readonly) NSArray* /* WNXXboxLiveEndpointPair* */ endpointPairs;
@property (readonly) unsigned short initiatorBoundPortRangeLower;
@property (readonly) unsigned short initiatorBoundPortRangeUpper;
@property (readonly) NSString * name;
@property (readonly) WNXXboxLiveSocketKind socketKind;
+ (NSArray* /* WNXXboxLiveEndpointPairTemplate* */)templates;
- (EventRegistrationToken)addInboundEndpointPairCreatedEvent:(void(^)(WNXXboxLiveEndpointPairTemplate*, WNXXboxLiveInboundEndpointPairCreatedEventArgs*))del;
- (void)removeInboundEndpointPairCreatedEvent:(EventRegistrationToken)tok;
- (void)createEndpointPairDefaultAsync:(WNXXboxLiveDeviceAddress*)deviceAddress success:(void (^)(WNXXboxLiveEndpointPairCreationResult*))success failure:(void (^)(NSError*))failure;
- (void)createEndpointPairWithBehaviorsAsync:(WNXXboxLiveDeviceAddress*)deviceAddress behaviors:(WNXXboxLiveEndpointPairCreationBehaviors)behaviors success:(void (^)(WNXXboxLiveEndpointPairCreationResult*))success failure:(void (^)(NSError*))failure;
- (void)createEndpointPairForPortsDefaultAsync:(WNXXboxLiveDeviceAddress*)deviceAddress initiatorPort:(NSString *)initiatorPort acceptorPort:(NSString *)acceptorPort success:(void (^)(WNXXboxLiveEndpointPairCreationResult*))success failure:(void (^)(NSError*))failure;
- (void)createEndpointPairForPortsWithBehaviorsAsync:(WNXXboxLiveDeviceAddress*)deviceAddress initiatorPort:(NSString *)initiatorPort acceptorPort:(NSString *)acceptorPort behaviors:(WNXXboxLiveEndpointPairCreationBehaviors)behaviors success:(void (^)(WNXXboxLiveEndpointPairCreationResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WNXXboxLiveEndpointPairTemplate_DEFINED__

// Windows.Networking.XboxLive.XboxLiveInboundEndpointPairCreatedEventArgs
#ifndef __WNXXboxLiveInboundEndpointPairCreatedEventArgs_DEFINED__
#define __WNXXboxLiveInboundEndpointPairCreatedEventArgs_DEFINED__

OBJCUWPWINDOWSNETWORKINGXBOXLIVEEXPORT
@interface WNXXboxLiveInboundEndpointPairCreatedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WNXXboxLiveEndpointPair* endpointPair;
@end

#endif // __WNXXboxLiveInboundEndpointPairCreatedEventArgs_DEFINED__

// Windows.Networking.XboxLive.XboxLiveEndpointPairCreationResult
#ifndef __WNXXboxLiveEndpointPairCreationResult_DEFINED__
#define __WNXXboxLiveEndpointPairCreationResult_DEFINED__

OBJCUWPWINDOWSNETWORKINGXBOXLIVEEXPORT
@interface WNXXboxLiveEndpointPairCreationResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WNXXboxLiveDeviceAddress* deviceAddress;
@property (readonly) WNXXboxLiveEndpointPair* endpointPair;
@property (readonly) BOOL isExistingPathEvaluation;
@property (readonly) WNXXboxLiveEndpointPairCreationStatus status;
@end

#endif // __WNXXboxLiveEndpointPairCreationResult_DEFINED__

// Windows.Networking.XboxLive.XboxLiveEndpointPairStateChangedEventArgs
#ifndef __WNXXboxLiveEndpointPairStateChangedEventArgs_DEFINED__
#define __WNXXboxLiveEndpointPairStateChangedEventArgs_DEFINED__

OBJCUWPWINDOWSNETWORKINGXBOXLIVEEXPORT
@interface WNXXboxLiveEndpointPairStateChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WNXXboxLiveEndpointPairState newState;
@property (readonly) WNXXboxLiveEndpointPairState oldState;
@end

#endif // __WNXXboxLiveEndpointPairStateChangedEventArgs_DEFINED__

// Windows.Networking.XboxLive.XboxLiveQualityOfServiceMetricResult
#ifndef __WNXXboxLiveQualityOfServiceMetricResult_DEFINED__
#define __WNXXboxLiveQualityOfServiceMetricResult_DEFINED__

OBJCUWPWINDOWSNETWORKINGXBOXLIVEEXPORT
@interface WNXXboxLiveQualityOfServiceMetricResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WNXXboxLiveDeviceAddress* deviceAddress;
@property (readonly) WNXXboxLiveQualityOfServiceMetric metric;
@property (readonly) WNXXboxLiveQualityOfServiceMeasurementStatus status;
@property (readonly) uint64_t value;
@end

#endif // __WNXXboxLiveQualityOfServiceMetricResult_DEFINED__

// Windows.Networking.XboxLive.XboxLiveQualityOfServicePrivatePayloadResult
#ifndef __WNXXboxLiveQualityOfServicePrivatePayloadResult_DEFINED__
#define __WNXXboxLiveQualityOfServicePrivatePayloadResult_DEFINED__

OBJCUWPWINDOWSNETWORKINGXBOXLIVEEXPORT
@interface WNXXboxLiveQualityOfServicePrivatePayloadResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WNXXboxLiveDeviceAddress* deviceAddress;
@property (readonly) WNXXboxLiveQualityOfServiceMeasurementStatus status;
@property (readonly) RTObject<WSSIBuffer>* value;
@end

#endif // __WNXXboxLiveQualityOfServicePrivatePayloadResult_DEFINED__

// Windows.Networking.XboxLive.XboxLiveQualityOfServiceMeasurement
#ifndef __WNXXboxLiveQualityOfServiceMeasurement_DEFINED__
#define __WNXXboxLiveQualityOfServiceMeasurement_DEFINED__

OBJCUWPWINDOWSNETWORKINGXBOXLIVEEXPORT
@interface WNXXboxLiveQualityOfServiceMeasurement : RTObject
+ (void)publishPrivatePayloadBytes:(NSArray* /* uint8_t */)payload;
+ (void)clearPrivatePayload;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property unsigned int timeoutInMilliseconds;
@property BOOL shouldRequestPrivatePayloads;
@property unsigned int numberOfProbesToAttempt;
@property (readonly) NSMutableArray* /* WNXXboxLiveDeviceAddress* */ deviceAddresses;
@property (readonly) NSArray* /* WNXXboxLiveQualityOfServiceMetricResult* */ metricResults;
@property (readonly) NSMutableArray* /* WNXXboxLiveQualityOfServiceMetric */ metrics;
@property (readonly) unsigned int numberOfResultsPending;
@property (readonly) NSArray* /* WNXXboxLiveQualityOfServicePrivatePayloadResult* */ privatePayloadResults;
+ (RTObject<WSSIBuffer>*)publishedPrivatePayload;
+ (void)setPublishedPrivatePayload:(RTObject<WSSIBuffer>*)value;
+ (unsigned int)maxSimultaneousProbeConnections;
+ (void)setMaxSimultaneousProbeConnections:(unsigned int)value;
+ (BOOL)isSystemOutboundBandwidthConstrained;
+ (void)setIsSystemOutboundBandwidthConstrained:(BOOL)value;
+ (BOOL)isSystemInboundBandwidthConstrained;
+ (void)setIsSystemInboundBandwidthConstrained:(BOOL)value;
+ (unsigned int)maxPrivatePayloadSize;
- (RTObject<WFIAsyncAction>*)measureAsync;
- (NSArray* /* WNXXboxLiveQualityOfServiceMetricResult* */)getMetricResultsForDevice:(WNXXboxLiveDeviceAddress*)deviceAddress;
- (NSArray* /* WNXXboxLiveQualityOfServiceMetricResult* */)getMetricResultsForMetric:(WNXXboxLiveQualityOfServiceMetric)metric;
- (WNXXboxLiveQualityOfServiceMetricResult*)getMetricResult:(WNXXboxLiveDeviceAddress*)deviceAddress metric:(WNXXboxLiveQualityOfServiceMetric)metric;
- (WNXXboxLiveQualityOfServicePrivatePayloadResult*)getPrivatePayloadResult:(WNXXboxLiveDeviceAddress*)deviceAddress;
@end

#endif // __WNXXboxLiveQualityOfServiceMeasurement_DEFINED__

