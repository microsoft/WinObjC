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

// WindowsNetworkingSockets.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WNSSocketActivityContext, WNSDatagramSocket, WNSStreamSocket, WNSStreamSocketListener, WNSSocketActivityInformation,
    WNSDatagramSocketControl, WNSDatagramSocketInformation, WNSDatagramSocketMessageReceivedEventArgs, WNSStreamSocketControl,
    WNSStreamSocketInformation, WNSStreamSocketListenerControl, WNSStreamSocketListenerInformation,
    WNSStreamSocketListenerConnectionReceivedEventArgs, WNSWebSocketClosedEventArgs, WNSMessageWebSocketControl,
    WNSMessageWebSocketInformation, WNSMessageWebSocket, WNSMessageWebSocketMessageReceivedEventArgs, WNSStreamWebSocketControl,
    WNSStreamWebSocketInformation, WNSStreamWebSocket, WNSWebSocketKeepAlive, WNSSocketError, WNSWebSocketError,
    WNSSocketActivityTriggerDetails;
@class WNSRoundTripTimeStatistics, WNSBandwidthStatistics;
@protocol WNSISocketActivityInformation
, WNSISocketActivityTriggerDetails, WNSISocketActivityInformationStatics, WNSISocketActivityContext, WNSISocketActivityContextFactory,
    WNSIDatagramSocketMessageReceivedEventArgs, WNSIMessageWebSocketMessageReceivedEventArgs, WNSIWebSocketClosedEventArgs,
    WNSIDatagramSocketInformation, WNSIDatagramSocketControl, WNSIDatagramSocketControl2, WNSIDatagramSocketControl3,
    WNSIDatagramSocketStatics, WNSIDatagramSocket, WNSIDatagramSocket2, WNSIDatagramSocket3, WNSIStreamSocketInformation,
    WNSIStreamSocketInformation2, WNSIStreamSocketControl, WNSIStreamSocketControl2, WNSIStreamSocketControl3, WNSIStreamSocket,
    WNSIStreamSocket2, WNSIStreamSocket3, WNSIStreamSocketListenerControl, WNSIStreamSocketListenerControl2,
    WNSIStreamSocketListenerInformation, WNSIStreamSocketListenerConnectionReceivedEventArgs, WNSIStreamSocketListener,
    WNSIStreamSocketListener2, WNSIStreamSocketListener3, WNSIWebSocketControl, WNSIWebSocketInformation, WNSIWebSocket,
    WNSIMessageWebSocketControl, WNSIMessageWebSocket, WNSIStreamWebSocketControl, WNSIStreamWebSocket, WNSISocketErrorStatics,
    WNSIWebSocketErrorStatics;

// Windows.Networking.Sockets.SocketMessageType
enum _WNSSocketMessageType {
    WNSSocketMessageTypeBinary = 0,
    WNSSocketMessageTypeUtf8 = 1,
};
typedef unsigned WNSSocketMessageType;

// Windows.Networking.Sockets.SocketProtectionLevel
enum _WNSSocketProtectionLevel {
    WNSSocketProtectionLevelPlainSocket = 0,
    WNSSocketProtectionLevelSsl = 1,
    WNSSocketProtectionLevelSslAllowNullEncryption = 2,
    WNSSocketProtectionLevelBluetoothEncryptionAllowNullAuthentication = 3,
    WNSSocketProtectionLevelBluetoothEncryptionWithAuthentication = 4,
    WNSSocketProtectionLevelSsl3AllowWeakEncryption = 5,
    WNSSocketProtectionLevelTls10 = 6,
    WNSSocketProtectionLevelTls11 = 7,
    WNSSocketProtectionLevelTls12 = 8,
};
typedef unsigned WNSSocketProtectionLevel;

// Windows.Networking.Sockets.SocketQualityOfService
enum _WNSSocketQualityOfService {
    WNSSocketQualityOfServiceNormal = 0,
    WNSSocketQualityOfServiceLowLatency = 1,
};
typedef unsigned WNSSocketQualityOfService;

// Windows.Networking.Sockets.SocketErrorStatus
enum _WNSSocketErrorStatus {
    WNSSocketErrorStatusUnknown = 0,
    WNSSocketErrorStatusOperationAborted = 1,
    WNSSocketErrorStatusHttpInvalidServerResponse = 2,
    WNSSocketErrorStatusConnectionTimedOut = 3,
    WNSSocketErrorStatusAddressFamilyNotSupported = 4,
    WNSSocketErrorStatusSocketTypeNotSupported = 5,
    WNSSocketErrorStatusHostNotFound = 6,
    WNSSocketErrorStatusNoDataRecordOfRequestedType = 7,
    WNSSocketErrorStatusNonAuthoritativeHostNotFound = 8,
    WNSSocketErrorStatusClassTypeNotFound = 9,
    WNSSocketErrorStatusAddressAlreadyInUse = 10,
    WNSSocketErrorStatusCannotAssignRequestedAddress = 11,
    WNSSocketErrorStatusConnectionRefused = 12,
    WNSSocketErrorStatusNetworkIsUnreachable = 13,
    WNSSocketErrorStatusUnreachableHost = 14,
    WNSSocketErrorStatusNetworkIsDown = 15,
    WNSSocketErrorStatusNetworkDroppedConnectionOnReset = 16,
    WNSSocketErrorStatusSoftwareCausedConnectionAbort = 17,
    WNSSocketErrorStatusConnectionResetByPeer = 18,
    WNSSocketErrorStatusHostIsDown = 19,
    WNSSocketErrorStatusNoAddressesFound = 20,
    WNSSocketErrorStatusTooManyOpenFiles = 21,
    WNSSocketErrorStatusMessageTooLong = 22,
    WNSSocketErrorStatusCertificateExpired = 23,
    WNSSocketErrorStatusCertificateUntrustedRoot = 24,
    WNSSocketErrorStatusCertificateCommonNameIsIncorrect = 25,
    WNSSocketErrorStatusCertificateWrongUsage = 26,
    WNSSocketErrorStatusCertificateRevoked = 27,
    WNSSocketErrorStatusCertificateNoRevocationCheck = 28,
    WNSSocketErrorStatusCertificateRevocationServerOffline = 29,
    WNSSocketErrorStatusCertificateIsInvalid = 30,
};
typedef unsigned WNSSocketErrorStatus;

// Windows.Networking.Sockets.SocketSslErrorSeverity
enum _WNSSocketSslErrorSeverity {
    WNSSocketSslErrorSeverityNone = 0,
    WNSSocketSslErrorSeverityIgnorable = 1,
    WNSSocketSslErrorSeverityFatal = 2,
};
typedef unsigned WNSSocketSslErrorSeverity;

// Windows.Networking.Sockets.SocketActivityKind
enum _WNSSocketActivityKind {
    WNSSocketActivityKindNone = 0,
    WNSSocketActivityKindStreamSocketListener = 1,
    WNSSocketActivityKindDatagramSocket = 2,
    WNSSocketActivityKindStreamSocket = 3,
};
typedef unsigned WNSSocketActivityKind;

// Windows.Networking.Sockets.SocketActivityTriggerReason
enum _WNSSocketActivityTriggerReason {
    WNSSocketActivityTriggerReasonNone = 0,
    WNSSocketActivityTriggerReasonSocketActivity = 1,
    WNSSocketActivityTriggerReasonConnectionAccepted = 2,
    WNSSocketActivityTriggerReasonKeepAliveTimerExpired = 3,
    WNSSocketActivityTriggerReasonSocketClosed = 4,
};
typedef unsigned WNSSocketActivityTriggerReason;

// Windows.Networking.Sockets.SocketActivityConnectedStandbyAction
enum _WNSSocketActivityConnectedStandbyAction {
    WNSSocketActivityConnectedStandbyActionDoNotWake = 0,
    WNSSocketActivityConnectedStandbyActionWake = 1,
};
typedef unsigned WNSSocketActivityConnectedStandbyAction;

#include "WindowsSecurityCryptographyCertificates.h"
#include "WindowsNetworking.h"
#include "WindowsSecurityCredentials.h"
#include "WindowsWeb.h"
#include "WindowsStorageStreams.h"
#include "WindowsFoundationCollections.h"
#include "WindowsFoundation.h"
#include "WindowsNetworkingConnectivity.h"
#include "WindowsApplicationModelBackground.h"

#import <Foundation/Foundation.h>

// [struct] Windows.Networking.Sockets.RoundTripTimeStatistics
WINRT_EXPORT
@interface WNSRoundTripTimeStatistics : NSObject
+ (instancetype) new;
@property unsigned int variance;
@property unsigned int max;
@property unsigned int min;
@property unsigned int sum;
@end

// [struct] Windows.Networking.Sockets.BandwidthStatistics
WINRT_EXPORT
@interface WNSBandwidthStatistics : NSObject
+ (instancetype) new;
@property uint64_t outboundBitsPerSecond;
@property uint64_t inboundBitsPerSecond;
@property uint64_t outboundBitsPerSecondInstability;
@property uint64_t inboundBitsPerSecondInstability;
@property BOOL outboundBandwidthPeaked;
@property BOOL inboundBandwidthPeaked;
@end

// Windows.Networking.Sockets.IWebSocketControl
#ifndef __WNSIWebSocketControl_DEFINED__
#define __WNSIWebSocketControl_DEFINED__

@protocol WNSIWebSocketControl
@property unsigned int outboundBufferSizeInBytes;
@property (copy) WSCPasswordCredential* proxyCredential;
@property (copy) WSCPasswordCredential* serverCredential;
@property (readonly) NSMutableArray* supportedProtocols;
@end

#endif // __WNSIWebSocketControl_DEFINED__

// Windows.Networking.Sockets.IWebSocketInformation
#ifndef __WNSIWebSocketInformation_DEFINED__
#define __WNSIWebSocketInformation_DEFINED__

@protocol WNSIWebSocketInformation
@property (readonly) WNSBandwidthStatistics* bandwidthStatistics;
@property (readonly) WNHostName* localAddress;
@property (readonly) NSString* protocol;
@end

#endif // __WNSIWebSocketInformation_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

#endif // __WFIClosable_DEFINED__

// Windows.Networking.Sockets.IWebSocket
#ifndef __WNSIWebSocket_DEFINED__
#define __WNSIWebSocket_DEFINED__

@protocol WNSIWebSocket <WFIClosable>
@property (readonly) RTObject<WSSIOutputStream>* outputStream;
- (EventRegistrationToken)addClosedEvent:(void (^)(RTObject<WNSIWebSocket>*, WNSWebSocketClosedEventArgs*))del;
- (void)removeClosedEvent:(EventRegistrationToken)tok;
- (RTObject<WFIAsyncAction>*)connectAsync:(WFUri*)uri;
- (void)setRequestHeader:(NSString*)headerName headerValue:(NSString*)headerValue;
- (void)closeWithStatus:(unsigned short)code reason:(NSString*)reason;
- (void)close;
@end

#endif // __WNSIWebSocket_DEFINED__

// Windows.Networking.Sockets.SocketActivityContext
#ifndef __WNSSocketActivityContext_DEFINED__
#define __WNSSocketActivityContext_DEFINED__

WINRT_EXPORT
@interface WNSSocketActivityContext : RTObject
+ (WNSSocketActivityContext*)create:(RTObject<WSSIBuffer>*)data ACTIVATOR;
@property (readonly) RTObject<WSSIBuffer>* data;
@end

#endif // __WNSSocketActivityContext_DEFINED__

// Windows.Networking.Sockets.DatagramSocket
#ifndef __WNSDatagramSocket_DEFINED__
#define __WNSDatagramSocket_DEFINED__

WINRT_EXPORT
@interface WNSDatagramSocket : RTObject <WFIClosable>
+ (void)getEndpointPairsAsync:(WNHostName*)remoteHostName
            remoteServiceName:(NSString*)remoteServiceName
                      success:(void (^)(NSArray*))success
                      failure:(void (^)(NSError*))failure;
+ (void)getEndpointPairsWithSortOptionsAsync:(WNHostName*)remoteHostName
                           remoteServiceName:(NSString*)remoteServiceName
                                 sortOptions:(WNHostNameSortOptions)sortOptions
                                     success:(void (^)(NSArray*))success
                                     failure:(void (^)(NSError*))failure;
+ (instancetype)create ACTIVATOR;
@property (readonly) WNSDatagramSocketControl* control;
@property (readonly) WNSDatagramSocketInformation* information;
@property (readonly) RTObject<WSSIOutputStream>* outputStream;
- (EventRegistrationToken)addMessageReceivedEvent:(void (^)(WNSDatagramSocket*, WNSDatagramSocketMessageReceivedEventArgs*))del;
- (void)removeMessageReceivedEvent:(EventRegistrationToken)tok;
- (RTObject<WFIAsyncAction>*)connectAsync:(WNHostName*)remoteHostName remoteServiceName:(NSString*)remoteServiceName;
- (RTObject<WFIAsyncAction>*)connectWithEndpointPairAsync:(WNEndpointPair*)endpointPair;
- (RTObject<WFIAsyncAction>*)bindServiceNameAsync:(NSString*)localServiceName;
- (RTObject<WFIAsyncAction>*)bindEndpointAsync:(WNHostName*)localHostName localServiceName:(NSString*)localServiceName;
- (void)joinMulticastGroup:(WNHostName*)host;
- (void)getOutputStreamAsync:(WNHostName*)remoteHostName
           remoteServiceName:(NSString*)remoteServiceName
                     success:(void (^)(RTObject<WSSIOutputStream>*))success
                     failure:(void (^)(NSError*))failure;
- (void)getOutputStreamWithEndpointPairAsync:(WNEndpointPair*)endpointPair
                                     success:(void (^)(RTObject<WSSIOutputStream>*))success
                                     failure:(void (^)(NSError*))failure;
- (void)close;
- (RTObject<WFIAsyncAction>*)bindServiceNameAndAdapterAsync:(NSString*)localServiceName adapter:(WNCNetworkAdapter*)adapter;
- (RTObject<WFIAsyncAction>*)cancelIOAsync;
- (void)enableTransferOwnership:(WFGUID*)taskId;
- (void)enableTransferOwnershipWithConnectedStandbyAction:(WFGUID*)taskId
                                   connectedStandbyAction:(WNSSocketActivityConnectedStandbyAction)connectedStandbyAction;
- (void)transferOwnership:(NSString*)socketId;
- (void)transferOwnershipWithContext:(NSString*)socketId data:(WNSSocketActivityContext*)data;
- (void)transferOwnershipWithContextAndKeepAliveTime:(NSString*)socketId
                                                data:(WNSSocketActivityContext*)data
                                       keepAliveTime:(WFTimeSpan*)keepAliveTime;
@end

#endif // __WNSDatagramSocket_DEFINED__

// Windows.Networking.Sockets.StreamSocket
#ifndef __WNSStreamSocket_DEFINED__
#define __WNSStreamSocket_DEFINED__

WINRT_EXPORT
@interface WNSStreamSocket : RTObject <WFIClosable>
+ (instancetype)create ACTIVATOR;
@property (readonly) WNSStreamSocketControl* control;
@property (readonly) WNSStreamSocketInformation* information;
@property (readonly) RTObject<WSSIInputStream>* inputStream;
@property (readonly) RTObject<WSSIOutputStream>* outputStream;
- (RTObject<WFIAsyncAction>*)connectWithEndpointPairAsync:(WNEndpointPair*)endpointPair;
- (RTObject<WFIAsyncAction>*)connectAsync:(WNHostName*)remoteHostName remoteServiceName:(NSString*)remoteServiceName;
- (RTObject<WFIAsyncAction>*)connectWithEndpointPairAndProtectionLevelAsync:(WNEndpointPair*)endpointPair
                                                            protectionLevel:(WNSSocketProtectionLevel)protectionLevel;
- (RTObject<WFIAsyncAction>*)connectWithProtectionLevelAsync:(WNHostName*)remoteHostName
                                           remoteServiceName:(NSString*)remoteServiceName
                                             protectionLevel:(WNSSocketProtectionLevel)protectionLevel;
- (RTObject<WFIAsyncAction>*)upgradeToSslAsync:(WNSSocketProtectionLevel)protectionLevel validationHostName:(WNHostName*)validationHostName;
- (void)close;
- (RTObject<WFIAsyncAction>*)connectWithProtectionLevelAndAdapterAsync:(WNHostName*)remoteHostName
                                                     remoteServiceName:(NSString*)remoteServiceName
                                                       protectionLevel:(WNSSocketProtectionLevel)protectionLevel
                                                               adapter:(WNCNetworkAdapter*)adapter;
- (RTObject<WFIAsyncAction>*)cancelIOAsync;
- (void)enableTransferOwnership:(WFGUID*)taskId;
- (void)enableTransferOwnershipWithConnectedStandbyAction:(WFGUID*)taskId
                                   connectedStandbyAction:(WNSSocketActivityConnectedStandbyAction)connectedStandbyAction;
- (void)transferOwnership:(NSString*)socketId;
- (void)transferOwnershipWithContext:(NSString*)socketId data:(WNSSocketActivityContext*)data;
- (void)transferOwnershipWithContextAndKeepAliveTime:(NSString*)socketId
                                                data:(WNSSocketActivityContext*)data
                                       keepAliveTime:(WFTimeSpan*)keepAliveTime;
@end

#endif // __WNSStreamSocket_DEFINED__

// Windows.Networking.Sockets.StreamSocketListener
#ifndef __WNSStreamSocketListener_DEFINED__
#define __WNSStreamSocketListener_DEFINED__

WINRT_EXPORT
@interface WNSStreamSocketListener : RTObject <WFIClosable>
+ (instancetype)create ACTIVATOR;
@property (readonly) WNSStreamSocketListenerControl* control;
@property (readonly) WNSStreamSocketListenerInformation* information;
- (EventRegistrationToken)addConnectionReceivedEvent:(void (^)(WNSStreamSocketListener*,
                                                               WNSStreamSocketListenerConnectionReceivedEventArgs*))del;
- (void)removeConnectionReceivedEvent:(EventRegistrationToken)tok;
- (RTObject<WFIAsyncAction>*)bindServiceNameAsync:(NSString*)localServiceName;
- (RTObject<WFIAsyncAction>*)bindEndpointAsync:(WNHostName*)localHostName localServiceName:(NSString*)localServiceName;
- (void)close;
- (RTObject<WFIAsyncAction>*)bindServiceNameWithProtectionLevelAsync:(NSString*)localServiceName
                                                     protectionLevel:(WNSSocketProtectionLevel)protectionLevel;
- (RTObject<WFIAsyncAction>*)bindServiceNameWithProtectionLevelAndAdapterAsync:(NSString*)localServiceName
                                                               protectionLevel:(WNSSocketProtectionLevel)protectionLevel
                                                                       adapter:(WNCNetworkAdapter*)adapter;
- (RTObject<WFIAsyncAction>*)cancelIOAsync;
- (void)enableTransferOwnership:(WFGUID*)taskId;
- (void)enableTransferOwnershipWithConnectedStandbyAction:(WFGUID*)taskId
                                   connectedStandbyAction:(WNSSocketActivityConnectedStandbyAction)connectedStandbyAction;
- (void)transferOwnership:(NSString*)socketId;
- (void)transferOwnershipWithContext:(NSString*)socketId data:(WNSSocketActivityContext*)data;
@end

#endif // __WNSStreamSocketListener_DEFINED__

// Windows.Networking.Sockets.SocketActivityInformation
#ifndef __WNSSocketActivityInformation_DEFINED__
#define __WNSSocketActivityInformation_DEFINED__

WINRT_EXPORT
@interface WNSSocketActivityInformation : RTObject
@property (readonly) WNSSocketActivityContext* context;
@property (readonly) WNSDatagramSocket* datagramSocket;
@property (readonly) NSString* id;
@property (readonly) WNSSocketActivityKind socketKind;
@property (readonly) WNSStreamSocket* streamSocket;
@property (readonly) WNSStreamSocketListener* streamSocketListener;
@property (readonly) WFGUID* taskId;
+ (NSDictionary*)allSockets;
@end

#endif // __WNSSocketActivityInformation_DEFINED__

// Windows.Networking.Sockets.DatagramSocketControl
#ifndef __WNSDatagramSocketControl_DEFINED__
#define __WNSDatagramSocketControl_DEFINED__

WINRT_EXPORT
@interface WNSDatagramSocketControl : RTObject
@property WNSSocketQualityOfService qualityOfService;
@property uint8_t outboundUnicastHopLimit;
@property unsigned int inboundBufferSizeInBytes;
@property BOOL dontFragment;
@property BOOL multicastOnly;
@end

#endif // __WNSDatagramSocketControl_DEFINED__

// Windows.Networking.Sockets.DatagramSocketInformation
#ifndef __WNSDatagramSocketInformation_DEFINED__
#define __WNSDatagramSocketInformation_DEFINED__

WINRT_EXPORT
@interface WNSDatagramSocketInformation : RTObject
@property (readonly) WNHostName* localAddress;
@property (readonly) NSString* localPort;
@property (readonly) WNHostName* remoteAddress;
@property (readonly) NSString* remotePort;
@end

#endif // __WNSDatagramSocketInformation_DEFINED__

// Windows.Networking.Sockets.DatagramSocketMessageReceivedEventArgs
#ifndef __WNSDatagramSocketMessageReceivedEventArgs_DEFINED__
#define __WNSDatagramSocketMessageReceivedEventArgs_DEFINED__

WINRT_EXPORT
@interface WNSDatagramSocketMessageReceivedEventArgs : RTObject
@property (readonly) WNHostName* localAddress;
@property (readonly) WNHostName* remoteAddress;
@property (readonly) NSString* remotePort;
- (WSSDataReader*)getDataReader;
- (RTObject<WSSIInputStream>*)getDataStream;
@end

#endif // __WNSDatagramSocketMessageReceivedEventArgs_DEFINED__

// Windows.Networking.Sockets.StreamSocketControl
#ifndef __WNSStreamSocketControl_DEFINED__
#define __WNSStreamSocketControl_DEFINED__

WINRT_EXPORT
@interface WNSStreamSocketControl : RTObject
@property WNSSocketQualityOfService qualityOfService;
@property uint8_t outboundUnicastHopLimit;
@property unsigned int outboundBufferSizeInBytes;
@property BOOL noDelay;
@property BOOL keepAlive;
@property (readonly) NSMutableArray* ignorableServerCertificateErrors;
@property BOOL serializeConnectionAttempts;
@property (copy) WSCCCertificate* clientCertificate;
@end

#endif // __WNSStreamSocketControl_DEFINED__

// Windows.Networking.Sockets.StreamSocketInformation
#ifndef __WNSStreamSocketInformation_DEFINED__
#define __WNSStreamSocketInformation_DEFINED__

WINRT_EXPORT
@interface WNSStreamSocketInformation : RTObject
@property (readonly) WNSBandwidthStatistics* bandwidthStatistics;
@property (readonly) WNHostName* localAddress;
@property (readonly) NSString* localPort;
@property (readonly) WNSSocketProtectionLevel protectionLevel;
@property (readonly) WNHostName* remoteAddress;
@property (readonly) WNHostName* remoteHostName;
@property (readonly) NSString* remotePort;
@property (readonly) NSString* remoteServiceName;
@property (readonly) WNSRoundTripTimeStatistics* roundTripTimeStatistics;
@property (readonly) RTObject<WSSIBuffer>* sessionKey;
@property (readonly) WSCCCertificate* serverCertificate;
@property (readonly) WNSSocketSslErrorSeverity serverCertificateErrorSeverity;
@property (readonly) NSArray* serverCertificateErrors;
@property (readonly) NSArray* serverIntermediateCertificates;
@end

#endif // __WNSStreamSocketInformation_DEFINED__

// Windows.Networking.Sockets.StreamSocketListenerControl
#ifndef __WNSStreamSocketListenerControl_DEFINED__
#define __WNSStreamSocketListenerControl_DEFINED__

WINRT_EXPORT
@interface WNSStreamSocketListenerControl : RTObject
@property WNSSocketQualityOfService qualityOfService;
@property uint8_t outboundUnicastHopLimit;
@property unsigned int outboundBufferSizeInBytes;
@property BOOL noDelay;
@property BOOL keepAlive;
@end

#endif // __WNSStreamSocketListenerControl_DEFINED__

// Windows.Networking.Sockets.StreamSocketListenerInformation
#ifndef __WNSStreamSocketListenerInformation_DEFINED__
#define __WNSStreamSocketListenerInformation_DEFINED__

WINRT_EXPORT
@interface WNSStreamSocketListenerInformation : RTObject
@property (readonly) NSString* localPort;
@end

#endif // __WNSStreamSocketListenerInformation_DEFINED__

// Windows.Networking.Sockets.StreamSocketListenerConnectionReceivedEventArgs
#ifndef __WNSStreamSocketListenerConnectionReceivedEventArgs_DEFINED__
#define __WNSStreamSocketListenerConnectionReceivedEventArgs_DEFINED__

WINRT_EXPORT
@interface WNSStreamSocketListenerConnectionReceivedEventArgs : RTObject
@property (readonly) WNSStreamSocket* socket;
@end

#endif // __WNSStreamSocketListenerConnectionReceivedEventArgs_DEFINED__

// Windows.Networking.Sockets.WebSocketClosedEventArgs
#ifndef __WNSWebSocketClosedEventArgs_DEFINED__
#define __WNSWebSocketClosedEventArgs_DEFINED__

WINRT_EXPORT
@interface WNSWebSocketClosedEventArgs : RTObject
@property (readonly) unsigned short code;
@property (readonly) NSString* reason;
@end

#endif // __WNSWebSocketClosedEventArgs_DEFINED__

// Windows.Networking.Sockets.MessageWebSocketControl
#ifndef __WNSMessageWebSocketControl_DEFINED__
#define __WNSMessageWebSocketControl_DEFINED__

WINRT_EXPORT
@interface WNSMessageWebSocketControl : RTObject <WNSIWebSocketControl>
@property WNSSocketMessageType messageType;
@property unsigned int maxMessageSize;
@property (copy) WSCPasswordCredential* serverCredential;
@property (copy) WSCPasswordCredential* proxyCredential;
@property unsigned int outboundBufferSizeInBytes;
@property (readonly) NSMutableArray* supportedProtocols;
@end

#endif // __WNSMessageWebSocketControl_DEFINED__

// Windows.Networking.Sockets.MessageWebSocketInformation
#ifndef __WNSMessageWebSocketInformation_DEFINED__
#define __WNSMessageWebSocketInformation_DEFINED__

WINRT_EXPORT
@interface WNSMessageWebSocketInformation : RTObject <WNSIWebSocketInformation>
@property (readonly) WNSBandwidthStatistics* bandwidthStatistics;
@property (readonly) WNHostName* localAddress;
@property (readonly) NSString* protocol;
@end

#endif // __WNSMessageWebSocketInformation_DEFINED__

// Windows.Networking.Sockets.MessageWebSocket
#ifndef __WNSMessageWebSocket_DEFINED__
#define __WNSMessageWebSocket_DEFINED__

WINRT_EXPORT
@interface WNSMessageWebSocket : RTObject <WNSIWebSocket, WFIClosable>
+ (instancetype)create ACTIVATOR;
@property (readonly) WNSMessageWebSocketControl* control;
@property (readonly) WNSMessageWebSocketInformation* information;
@property (readonly) RTObject<WSSIOutputStream>* outputStream;
- (EventRegistrationToken)addMessageReceivedEvent:(void (^)(WNSMessageWebSocket*, WNSMessageWebSocketMessageReceivedEventArgs*))del;
- (void)removeMessageReceivedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addClosedEvent:(void (^)(RTObject<WNSIWebSocket>*, WNSWebSocketClosedEventArgs*))del;
- (void)removeClosedEvent:(EventRegistrationToken)tok;
- (RTObject<WFIAsyncAction>*)connectAsync:(WFUri*)uri;
- (void)setRequestHeader:(NSString*)headerName headerValue:(NSString*)headerValue;
- (void)closeWithStatus:(unsigned short)code reason:(NSString*)reason;
- (void)close;
@end

#endif // __WNSMessageWebSocket_DEFINED__

// Windows.Networking.Sockets.MessageWebSocketMessageReceivedEventArgs
#ifndef __WNSMessageWebSocketMessageReceivedEventArgs_DEFINED__
#define __WNSMessageWebSocketMessageReceivedEventArgs_DEFINED__

WINRT_EXPORT
@interface WNSMessageWebSocketMessageReceivedEventArgs : RTObject
@property (readonly) WNSSocketMessageType messageType;
- (WSSDataReader*)getDataReader;
- (RTObject<WSSIInputStream>*)getDataStream;
@end

#endif // __WNSMessageWebSocketMessageReceivedEventArgs_DEFINED__

// Windows.Networking.Sockets.StreamWebSocketControl
#ifndef __WNSStreamWebSocketControl_DEFINED__
#define __WNSStreamWebSocketControl_DEFINED__

WINRT_EXPORT
@interface WNSStreamWebSocketControl : RTObject <WNSIWebSocketControl>
@property BOOL noDelay;
@property (copy) WSCPasswordCredential* serverCredential;
@property (copy) WSCPasswordCredential* proxyCredential;
@property unsigned int outboundBufferSizeInBytes;
@property (readonly) NSMutableArray* supportedProtocols;
@end

#endif // __WNSStreamWebSocketControl_DEFINED__

// Windows.Networking.Sockets.StreamWebSocketInformation
#ifndef __WNSStreamWebSocketInformation_DEFINED__
#define __WNSStreamWebSocketInformation_DEFINED__

WINRT_EXPORT
@interface WNSStreamWebSocketInformation : RTObject <WNSIWebSocketInformation>
@property (readonly) WNSBandwidthStatistics* bandwidthStatistics;
@property (readonly) WNHostName* localAddress;
@property (readonly) NSString* protocol;
@end

#endif // __WNSStreamWebSocketInformation_DEFINED__

// Windows.Networking.Sockets.StreamWebSocket
#ifndef __WNSStreamWebSocket_DEFINED__
#define __WNSStreamWebSocket_DEFINED__

WINRT_EXPORT
@interface WNSStreamWebSocket : RTObject <WNSIWebSocket, WFIClosable>
+ (instancetype)create ACTIVATOR;
@property (readonly) WNSStreamWebSocketControl* control;
@property (readonly) WNSStreamWebSocketInformation* information;
@property (readonly) RTObject<WSSIInputStream>* inputStream;
@property (readonly) RTObject<WSSIOutputStream>* outputStream;
- (EventRegistrationToken)addClosedEvent:(void (^)(RTObject<WNSIWebSocket>*, WNSWebSocketClosedEventArgs*))del;
- (void)removeClosedEvent:(EventRegistrationToken)tok;
- (RTObject<WFIAsyncAction>*)connectAsync:(WFUri*)uri;
- (void)setRequestHeader:(NSString*)headerName headerValue:(NSString*)headerValue;
- (void)closeWithStatus:(unsigned short)code reason:(NSString*)reason;
- (void)close;
@end

#endif // __WNSStreamWebSocket_DEFINED__

// Windows.ApplicationModel.Background.IBackgroundTask
#ifndef __WABIBackgroundTask_DEFINED__
#define __WABIBackgroundTask_DEFINED__

@protocol WABIBackgroundTask
- (void)run:(RTObject<WABIBackgroundTaskInstance>*)taskInstance;
@end

#endif // __WABIBackgroundTask_DEFINED__

// Windows.Networking.Sockets.WebSocketKeepAlive
#ifndef __WNSWebSocketKeepAlive_DEFINED__
#define __WNSWebSocketKeepAlive_DEFINED__

WINRT_EXPORT
@interface WNSWebSocketKeepAlive : RTObject <WABIBackgroundTask>
+ (instancetype)create ACTIVATOR;
- (void)run:(RTObject<WABIBackgroundTaskInstance>*)taskInstance;
@end

#endif // __WNSWebSocketKeepAlive_DEFINED__

// Windows.Networking.Sockets.SocketError
#ifndef __WNSSocketError_DEFINED__
#define __WNSSocketError_DEFINED__

WINRT_EXPORT
@interface WNSSocketError : RTObject
+ (WNSSocketErrorStatus)getStatus:(int)hresult;
@end

#endif // __WNSSocketError_DEFINED__

// Windows.Networking.Sockets.WebSocketError
#ifndef __WNSWebSocketError_DEFINED__
#define __WNSWebSocketError_DEFINED__

WINRT_EXPORT
@interface WNSWebSocketError : RTObject
+ (WWWebErrorStatus)getStatus:(int)hresult;
@end

#endif // __WNSWebSocketError_DEFINED__

// Windows.Networking.Sockets.SocketActivityTriggerDetails
#ifndef __WNSSocketActivityTriggerDetails_DEFINED__
#define __WNSSocketActivityTriggerDetails_DEFINED__

WINRT_EXPORT
@interface WNSSocketActivityTriggerDetails : RTObject
@property (readonly) WNSSocketActivityTriggerReason reason;
@property (readonly) WNSSocketActivityInformation* socketInformation;
@end

#endif // __WNSSocketActivityTriggerDetails_DEFINED__
