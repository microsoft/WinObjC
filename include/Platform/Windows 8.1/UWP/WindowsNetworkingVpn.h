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

// WindowsNetworkingVpn.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WNVVpnRoute, WNVVpnNamespaceInfo, WNVVpnInterfaceId, WNVVpnRouteAssignment, WNVVpnNamespaceAssignment, WNVVpnPickedCredential,
    WNVVpnPacketBuffer, WNVVpnChannelConfiguration, WNVVpnChannel, WNVVpnChannelActivityEventArgs, WNVVpnSystemHealth,
    WNVVpnPacketBufferList, WNVVpnCustomEditBox, WNVVpnCustomComboBox, WNVVpnCustomTextBox, WNVVpnCustomCheckBox, WNVVpnCustomErrorBox;
@protocol WNVIVpnPlugIn
, WNVIVpnCustomPrompt, WNVIVpnCustomEditBox, WNVIVpnCustomComboBox, WNVIVpnCustomTextBox, WNVIVpnCustomCheckBox, WNVIVpnCustomErrorBox,
    WNVIVpnRouteFactory, WNVIVpnRoute, WNVIVpnRouteAssignment, WNVIVpnNamespaceInfoFactory, WNVIVpnNamespaceInfo,
    WNVIVpnNamespaceAssignment, WNVIVpnInterfaceIdFactory, WNVIVpnInterfaceId, WNVIVpnPickedCredential, WNVIVpnSystemHealth,
    WNVIVpnChannelConfiguration, WNVIVpnChannelActivityEventArgs, WNVIVpnChannel, WNVIVpnChannelStatics, WNVIVpnPacketBufferFactory,
    WNVIVpnPacketBuffer, WNVIVpnPacketBufferList;

// Windows.Networking.Vpn.VpnDataPathType
enum _WNVVpnDataPathType {
    WNVVpnDataPathTypeSend = 0,
    WNVVpnDataPathTypeReceive = 1,
};
typedef unsigned WNVVpnDataPathType;

// Windows.Networking.Vpn.VpnChannelActivityEventType
enum _WNVVpnChannelActivityEventType {
    WNVVpnChannelActivityEventTypeIdle = 0,
    WNVVpnChannelActivityEventTypeActive = 1,
};
typedef unsigned WNVVpnChannelActivityEventType;

// Windows.Networking.Vpn.VpnCredentialType
enum _WNVVpnCredentialType {
    WNVVpnCredentialTypeUsernamePassword = 0,
    WNVVpnCredentialTypeUsernameOtpPin = 1,
    WNVVpnCredentialTypeUsernamePasswordAndPin = 2,
    WNVVpnCredentialTypeUsernamePasswordChange = 3,
    WNVVpnCredentialTypeSmartCard = 4,
    WNVVpnCredentialTypeProtectedCertificate = 5,
    WNVVpnCredentialTypeUnProtectedCertificate = 6,
};
typedef unsigned WNVVpnCredentialType;

// Windows.Networking.Vpn.VpnPacketBufferStatus
enum _WNVVpnPacketBufferStatus {
    WNVVpnPacketBufferStatusOk = 0,
    WNVVpnPacketBufferStatusInvalidBufferSize = 1,
};
typedef unsigned WNVVpnPacketBufferStatus;

#include "WindowsStorageStreams.h"
#include "WindowsSecurityCredentials.h"
#include "WindowsFoundationCollections.h"
#include "WindowsSecurityCryptographyCertificates.h"
#include "WindowsNetworking.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Networking.Vpn.IVpnPlugIn
#ifndef __WNVIVpnPlugIn_DEFINED__
#define __WNVIVpnPlugIn_DEFINED__

@protocol WNVIVpnPlugIn
- (void)connect:(WNVVpnChannel*)channel;
- (void)disconnect:(WNVVpnChannel*)channel;
- (void)getKeepAlivePayload:(WNVVpnChannel*)channel keepAlivePacket:(WNVVpnPacketBuffer**)keepAlivePacket;
- (void)encapsulate:(WNVVpnChannel*)channel
            packets:(WNVVpnPacketBufferList*)packets
 encapulatedPackets:(WNVVpnPacketBufferList*)encapulatedPackets;
- (void)decapsulate:(WNVVpnChannel*)channel
             encapBuffer:(WNVVpnPacketBuffer*)encapBuffer
     decapsulatedPackets:(WNVVpnPacketBufferList*)decapsulatedPackets
    controlPacketsToSend:(WNVVpnPacketBufferList*)controlPacketsToSend;
@end

#endif // __WNVIVpnPlugIn_DEFINED__

// Windows.Networking.Vpn.IVpnCustomPrompt
#ifndef __WNVIVpnCustomPrompt_DEFINED__
#define __WNVIVpnCustomPrompt_DEFINED__

@protocol WNVIVpnCustomPrompt
@property BOOL bordered;
@property BOOL compulsory;
@property (copy) NSString* label;
@end

#endif // __WNVIVpnCustomPrompt_DEFINED__

// Windows.Networking.Vpn.IVpnRouteFactory
#ifndef __WNVIVpnRouteFactory_DEFINED__
#define __WNVIVpnRouteFactory_DEFINED__

@protocol WNVIVpnRouteFactory
- (WNVVpnRoute*)createVpnRoute:(WNHostName*)address prefixSize:(uint8_t)prefixSize;
@end

#endif // __WNVIVpnRouteFactory_DEFINED__

// Windows.Networking.Vpn.IVpnNamespaceInfoFactory
#ifndef __WNVIVpnNamespaceInfoFactory_DEFINED__
#define __WNVIVpnNamespaceInfoFactory_DEFINED__

@protocol WNVIVpnNamespaceInfoFactory
- (WNVVpnNamespaceInfo*)createVpnNamespaceInfo:(NSString*)name
                                 dnsServerList:(id<NSFastEnumeration> /*WNHostName*/)dnsServerList
                               proxyServerList:(id<NSFastEnumeration> /*WNHostName*/)proxyServerList;
@end

#endif // __WNVIVpnNamespaceInfoFactory_DEFINED__

// Windows.Networking.Vpn.IVpnInterfaceIdFactory
#ifndef __WNVIVpnInterfaceIdFactory_DEFINED__
#define __WNVIVpnInterfaceIdFactory_DEFINED__

@protocol WNVIVpnInterfaceIdFactory
- (WNVVpnInterfaceId*)createVpnInterfaceId:(id<NSFastEnumeration> /*UInt8*/)address;
@end

#endif // __WNVIVpnInterfaceIdFactory_DEFINED__

// Windows.Networking.Vpn.IVpnChannelStatics
#ifndef __WNVIVpnChannelStatics_DEFINED__
#define __WNVIVpnChannelStatics_DEFINED__

@protocol WNVIVpnChannelStatics
- (void)processEventAsync:(RTObject*)thirdPartyPlugIn event:(RTObject*)event;
@end

#endif // __WNVIVpnChannelStatics_DEFINED__

// Windows.Networking.Vpn.IVpnPacketBufferFactory
#ifndef __WNVIVpnPacketBufferFactory_DEFINED__
#define __WNVIVpnPacketBufferFactory_DEFINED__

@protocol WNVIVpnPacketBufferFactory
- (WNVVpnPacketBuffer*)createVpnPacketBuffer:(WNVVpnPacketBuffer*)parentBuffer offset:(unsigned)offset length:(unsigned)length;
@end

#endif // __WNVIVpnPacketBufferFactory_DEFINED__

// Windows.Networking.Vpn.VpnRoute
#ifndef __WNVVpnRoute_DEFINED__
#define __WNVVpnRoute_DEFINED__

WINRT_EXPORT
@interface WNVVpnRoute : RTObject
+ (WNVVpnRoute*)createVpnRoute:(WNHostName*)address prefixSize:(uint8_t)prefixSize ACTIVATOR;
@property uint8_t prefixSize;
@property (copy) WNHostName* address;
@end

#endif // __WNVVpnRoute_DEFINED__

// Windows.Networking.Vpn.VpnNamespaceInfo
#ifndef __WNVVpnNamespaceInfo_DEFINED__
#define __WNVVpnNamespaceInfo_DEFINED__

WINRT_EXPORT
@interface WNVVpnNamespaceInfo : RTObject
+ (WNVVpnNamespaceInfo*)createVpnNamespaceInfo:(NSString*)name
                                 dnsServerList:(id<NSFastEnumeration> /*WNHostName*/)dnsServerList
                               proxyServerList:(id<NSFastEnumeration> /*WNHostName*/)proxyServerList ACTIVATOR;
@property (copy) id<NSFastEnumeration> /*WNHostName*/ webProxyServers;
@property (copy) NSString* Namespace;
@property (copy) id<NSFastEnumeration> /*WNHostName*/ dnsServers;
@end

#endif // __WNVVpnNamespaceInfo_DEFINED__

// Windows.Networking.Vpn.VpnInterfaceId
#ifndef __WNVVpnInterfaceId_DEFINED__
#define __WNVVpnInterfaceId_DEFINED__

WINRT_EXPORT
@interface WNVVpnInterfaceId : RTObject
+ (WNVVpnInterfaceId*)createVpnInterfaceId:(id<NSFastEnumeration> /*UInt8*/)address ACTIVATOR;
- (void)getAddressInfo:(id<NSFastEnumeration> /*UInt8*/*)id;
@end

#endif // __WNVVpnInterfaceId_DEFINED__

// Windows.Networking.Vpn.VpnRouteAssignment
#ifndef __WNVVpnRouteAssignment_DEFINED__
#define __WNVVpnRouteAssignment_DEFINED__

WINRT_EXPORT
@interface WNVVpnRouteAssignment : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) id<NSFastEnumeration> /*WNVVpnRoute*/ ipv6InclusionRoutes;
@property (copy) id<NSFastEnumeration> /*WNVVpnRoute*/ ipv6ExclusionRoutes;
@property (copy) id<NSFastEnumeration> /*WNVVpnRoute*/ ipv4InclusionRoutes;
@property (copy) id<NSFastEnumeration> /*WNVVpnRoute*/ ipv4ExclusionRoutes;
@property BOOL excludeLocalSubnets;
@end

#endif // __WNVVpnRouteAssignment_DEFINED__

// Windows.Networking.Vpn.VpnNamespaceAssignment
#ifndef __WNVVpnNamespaceAssignment_DEFINED__
#define __WNVVpnNamespaceAssignment_DEFINED__

WINRT_EXPORT
@interface WNVVpnNamespaceAssignment : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) WFUri* proxyAutoConfigUri;
@property (copy) id<NSFastEnumeration> /*WNVVpnNamespaceInfo*/ namespaceList;
@end

#endif // __WNVVpnNamespaceAssignment_DEFINED__

// Windows.Networking.Vpn.VpnPickedCredential
#ifndef __WNVVpnPickedCredential_DEFINED__
#define __WNVVpnPickedCredential_DEFINED__

WINRT_EXPORT
@interface WNVVpnPickedCredential : RTObject
@property (readonly) NSString* additionalPin;
@property (readonly) WSCPasswordCredential* oldPasswordCredential;
@property (readonly) WSCPasswordCredential* passkeyCredential;
@end

#endif // __WNVVpnPickedCredential_DEFINED__

// Windows.Networking.Vpn.VpnPacketBuffer
#ifndef __WNVVpnPacketBuffer_DEFINED__
#define __WNVVpnPacketBuffer_DEFINED__

WINRT_EXPORT
@interface WNVVpnPacketBuffer : RTObject
+ (WNVVpnPacketBuffer*)createVpnPacketBuffer:(WNVVpnPacketBuffer*)parentBuffer offset:(unsigned)offset length:(unsigned)length ACTIVATOR;
@property unsigned transportAffinity;
@property WNVVpnPacketBufferStatus status;
@property (readonly) WSSBuffer* buffer;
@end

#endif // __WNVVpnPacketBuffer_DEFINED__

// Windows.Networking.Vpn.VpnChannelConfiguration
#ifndef __WNVVpnChannelConfiguration_DEFINED__
#define __WNVVpnChannelConfiguration_DEFINED__

WINRT_EXPORT
@interface WNVVpnChannelConfiguration : RTObject
@property (readonly) NSString* customField;
@property (readonly) id<NSFastEnumeration> /*WNHostName*/ serverHostNameList;
@property (readonly) NSString* serverServiceName;
@end

#endif // __WNVVpnChannelConfiguration_DEFINED__

// Windows.Networking.Vpn.VpnChannel
#ifndef __WNVVpnChannel_DEFINED__
#define __WNVVpnChannel_DEFINED__

WINRT_EXPORT
@interface WNVVpnChannel : RTObject
+ (void)processEventAsync:(RTObject*)thirdPartyPlugIn event:(RTObject*)event;
@property (copy) RTObject* plugInContext;
@property (readonly) WNVVpnChannelConfiguration* configuration;
@property (readonly) unsigned id;
@property (readonly) WNVVpnSystemHealth* systemHealth;
- (EventRegistrationToken)addActivityChangeEvent:(void (^)(WNVVpnChannel*, WNVVpnChannelActivityEventArgs*))del;
- (void)removeActivityChangeEvent:(EventRegistrationToken)tok;
- (void)associateTransport:(RTObject*)mainOuterTunnelTransport optionalOuterTunnelTransport:(RTObject*)optionalOuterTunnelTransport;
- (void)start:(id<NSFastEnumeration> /*WNHostName*/)assignedClientIPv4list
          assignedClientIPv6list:(id<NSFastEnumeration> /*WNHostName*/)assignedClientIPv6list
                  vpnInterfaceId:(WNVVpnInterfaceId*)vpnInterfaceId
                      routeScope:(WNVVpnRouteAssignment*)routeScope
                  namespaceScope:(WNVVpnNamespaceAssignment*)namespaceScope
                         mtuSize:(unsigned)mtuSize
                    maxFrameSize:(unsigned)maxFrameSize
       optimizeForLowCostNetwork:(BOOL)optimizeForLowCostNetwork
        mainOuterTunnelTransport:(RTObject*)mainOuterTunnelTransport
    optionalOuterTunnelTransport:(RTObject*)optionalOuterTunnelTransport;
- (void)stop;
- (WNVVpnPickedCredential*)requestCredentials:(WNVVpnCredentialType)credType
                                      isRetry:(BOOL)isRetry
                     isSingleSignOnCredential:(BOOL)isSingleSignOnCredential
                                  certificate:(WSCCCertificate*)certificate;
- (void)requestVpnPacketBuffer:(WNVVpnDataPathType)type vpnPacketBuffer:(WNVVpnPacketBuffer**)vpnPacketBuffer;
- (void)logDiagnosticMessage:(NSString*)message;
- (void)requestCustomPrompt:(id<NSFastEnumeration> /*WNVIVpnCustomPrompt*/)customPrompt;
- (void)setErrorMessage:(NSString*)message;
- (void)setAllowedSslTlsVersions:(RTObject*)tunnelTransport useTls12:(BOOL)useTls12;
@end

#endif // __WNVVpnChannel_DEFINED__

// Windows.Networking.Vpn.VpnChannelActivityEventArgs
#ifndef __WNVVpnChannelActivityEventArgs_DEFINED__
#define __WNVVpnChannelActivityEventArgs_DEFINED__

WINRT_EXPORT
@interface WNVVpnChannelActivityEventArgs : RTObject
@property (readonly) WNVVpnChannelActivityEventType type;
@end

#endif // __WNVVpnChannelActivityEventArgs_DEFINED__

// Windows.Networking.Vpn.VpnSystemHealth
#ifndef __WNVVpnSystemHealth_DEFINED__
#define __WNVVpnSystemHealth_DEFINED__

WINRT_EXPORT
@interface WNVVpnSystemHealth : RTObject
@property (readonly) WSSBuffer* statementOfHealth;
@end

#endif // __WNVVpnSystemHealth_DEFINED__

// Windows.Networking.Vpn.VpnPacketBufferList
#ifndef __WNVVpnPacketBufferList_DEFINED__
#define __WNVVpnPacketBufferList_DEFINED__

WINRT_EXPORT
@interface WNVVpnPacketBufferList : RTObject
@property WNVVpnPacketBufferStatus status;
@property (readonly) unsigned size;
- (void)append:(WNVVpnPacketBuffer*)nextVpnPacketBuffer;
- (void)addAtBegin:(WNVVpnPacketBuffer*)nextVpnPacketBuffer;
- (WNVVpnPacketBuffer*)removeAtEnd;
- (WNVVpnPacketBuffer*)removeAtBegin;
- (void)clear;
@end

#endif // __WNVVpnPacketBufferList_DEFINED__

// Windows.Networking.Vpn.VpnCustomEditBox
#ifndef __WNVVpnCustomEditBox_DEFINED__
#define __WNVVpnCustomEditBox_DEFINED__

WINRT_EXPORT
@interface WNVVpnCustomEditBox : RTObject <WNVIVpnCustomPrompt>
+ (instancetype)create ACTIVATOR;
@property BOOL noEcho;
@property (copy) NSString* defaultText;
@property (readonly) NSString* text;
@property (copy) NSString* label;
@property BOOL compulsory;
@property BOOL bordered;
@end

#endif // __WNVVpnCustomEditBox_DEFINED__

// Windows.Networking.Vpn.VpnCustomComboBox
#ifndef __WNVVpnCustomComboBox_DEFINED__
#define __WNVVpnCustomComboBox_DEFINED__

WINRT_EXPORT
@interface WNVVpnCustomComboBox : RTObject <WNVIVpnCustomPrompt>
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* label;
@property BOOL compulsory;
@property BOOL bordered;
@property (copy) id<NSFastEnumeration> /*String*/ optionsText;
@property (readonly) unsigned selected;
@end

#endif // __WNVVpnCustomComboBox_DEFINED__

// Windows.Networking.Vpn.VpnCustomTextBox
#ifndef __WNVVpnCustomTextBox_DEFINED__
#define __WNVVpnCustomTextBox_DEFINED__

WINRT_EXPORT
@interface WNVVpnCustomTextBox : RTObject <WNVIVpnCustomPrompt>
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* label;
@property BOOL compulsory;
@property BOOL bordered;
@property (copy) NSString* displayText;
@end

#endif // __WNVVpnCustomTextBox_DEFINED__

// Windows.Networking.Vpn.VpnCustomCheckBox
#ifndef __WNVVpnCustomCheckBox_DEFINED__
#define __WNVVpnCustomCheckBox_DEFINED__

WINRT_EXPORT
@interface WNVVpnCustomCheckBox : RTObject <WNVIVpnCustomPrompt>
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* label;
@property BOOL compulsory;
@property BOOL bordered;
@property BOOL initialCheckState;
@property (readonly) BOOL checked;
@end

#endif // __WNVVpnCustomCheckBox_DEFINED__

// Windows.Networking.Vpn.VpnCustomErrorBox
#ifndef __WNVVpnCustomErrorBox_DEFINED__
#define __WNVVpnCustomErrorBox_DEFINED__

WINRT_EXPORT
@interface WNVVpnCustomErrorBox : RTObject <WNVIVpnCustomPrompt>
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* label;
@property BOOL compulsory;
@property BOOL bordered;
@end

#endif // __WNVVpnCustomErrorBox_DEFINED__
