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

// WindowsDevicesAllJoyn.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WDAAllJoynStatus, WDAAllJoynAboutData, WDAAllJoynBusAttachment, WDAAllJoynBusAttachmentStateChangedEventArgs,
    WDAAllJoynCredentialsRequestedEventArgs, WDAAllJoynCredentialsVerificationRequestedEventArgs, WDAAllJoynAuthenticationCompleteEventArgs,
    WDAAllJoynCredentials, WDAAllJoynServiceInfo, WDAAllJoynAboutDataView, WDAAllJoynAcceptSessionJoinerEventArgs,
    WDAAllJoynSessionMemberAddedEventArgs, WDAAllJoynSessionMemberRemovedEventArgs, WDAAllJoynSessionLostEventArgs,
    WDAAllJoynProducerStoppedEventArgs, WDAAllJoynWatcherStoppedEventArgs, WDAAllJoynServiceInfoRemovedEventArgs, WDAAllJoynMessageInfo;
@protocol WDAIAllJoynStatusStatics
, WDAIAllJoynBusAttachment, WDAIAllJoynBusAttachmentStateChangedEventArgs, WDAIAllJoynCredentials, WDAIAllJoynCredentialsRequestedEventArgs,
    WDAIAllJoynCredentialsVerificationRequestedEventArgs, WDAIAllJoynAuthenticationCompleteEventArgs, WDAIAllJoynBusAttachmentFactory,
    WDAIAllJoynServiceInfo, WDAIAllJoynServiceInfoFactory, WDAIAllJoynAboutDataViewStatics, WDAIAllJoynAboutDataView, WDAIAllJoynAboutData,
    WDAIAllJoynAcceptSessionJoinerEventArgs, WDAIAllJoynAcceptSessionJoiner, WDAIAllJoynAcceptSessionJoinerEventArgsFactory,
    WDAIAllJoynSessionMemberAddedEventArgs, WDAIAllJoynSessionMemberAddedEventArgsFactory, WDAIAllJoynSessionMemberRemovedEventArgs,
    WDAIAllJoynSessionMemberRemovedEventArgsFactory, WDAIAllJoynSessionLostEventArgs, WDAIAllJoynSessionLostEventArgsFactory,
    WDAIAllJoynProducerStoppedEventArgs, WDAIAllJoynProducerStoppedEventArgsFactory, WDAIAllJoynWatcherStoppedEventArgs,
    WDAIAllJoynWatcherStoppedEventArgsFactory, WDAIAllJoynServiceInfoRemovedEventArgs, WDAIAllJoynServiceInfoRemovedEventArgsFactory,
    WDAIAllJoynMessageInfo, WDAIAllJoynMessageInfoFactory;

// Windows.Devices.AllJoyn.AllJoynAuthenticationMechanism
enum _WDAAllJoynAuthenticationMechanism {
    WDAAllJoynAuthenticationMechanismNone = 0,
    WDAAllJoynAuthenticationMechanismSrpAnonymous = 1,
    WDAAllJoynAuthenticationMechanismSrpLogon = 2,
    WDAAllJoynAuthenticationMechanismEcdheNull = 3,
    WDAAllJoynAuthenticationMechanismEcdhePsk = 4,
    WDAAllJoynAuthenticationMechanismEcdheEcdsa = 5,
};
typedef unsigned WDAAllJoynAuthenticationMechanism;

// Windows.Devices.AllJoyn.AllJoynBusAttachmentState
enum _WDAAllJoynBusAttachmentState {
    WDAAllJoynBusAttachmentStateDisconnected = 0,
    WDAAllJoynBusAttachmentStateConnecting = 1,
    WDAAllJoynBusAttachmentStateConnected = 2,
    WDAAllJoynBusAttachmentStateDisconnecting = 3,
};
typedef unsigned WDAAllJoynBusAttachmentState;

// Windows.Devices.AllJoyn.AllJoynTrafficType
enum _WDAAllJoynTrafficType {
    WDAAllJoynTrafficTypeUnknown = 0,
    WDAAllJoynTrafficTypeMessages = 1,
    WDAAllJoynTrafficTypeRawUnreliable = 2,
    WDAAllJoynTrafficTypeRawReliable = 4,
};
typedef unsigned WDAAllJoynTrafficType;

// Windows.Devices.AllJoyn.AllJoynSessionLostReason
enum _WDAAllJoynSessionLostReason {
    WDAAllJoynSessionLostReasonNone = 0,
    WDAAllJoynSessionLostReasonProducerLeftSession = 1,
    WDAAllJoynSessionLostReasonProducerClosedAbruptly = 2,
    WDAAllJoynSessionLostReasonRemovedByProducer = 3,
    WDAAllJoynSessionLostReasonLinkTimeout = 4,
    WDAAllJoynSessionLostReasonOther = 5,
};
typedef unsigned WDAAllJoynSessionLostReason;

#include "WindowsNetworkingSockets.h"
#include "WindowsSecurityCryptographyCertificates.h"
#include "WindowsFoundation.h"
#include "WindowsSecurityCredentials.h"
#include "WindowsFoundationCollections.h"
#include "WindowsGlobalization.h"

#import <Foundation/Foundation.h>

// Windows.Devices.AllJoyn.IAllJoynAcceptSessionJoiner
#ifndef __WDAIAllJoynAcceptSessionJoiner_DEFINED__
#define __WDAIAllJoynAcceptSessionJoiner_DEFINED__

@protocol WDAIAllJoynAcceptSessionJoiner
- (void)accept;
@end

#endif // __WDAIAllJoynAcceptSessionJoiner_DEFINED__

// Windows.Devices.AllJoyn.AllJoynStatus
#ifndef __WDAAllJoynStatus_DEFINED__
#define __WDAAllJoynStatus_DEFINED__

WINRT_EXPORT
@interface WDAAllJoynStatus : RTObject
+ (int)authenticationFailed;
+ (int)authenticationRejectedByUser;
+ (int)connectionRefused;
+ (int)fail;
+ (int)insufficientSecurity;
+ (int)invalidArgument1;
+ (int)invalidArgument2;
+ (int)invalidArgument3;
+ (int)invalidArgument4;
+ (int)invalidArgument5;
+ (int)invalidArgument6;
+ (int)invalidArgument7;
+ (int)invalidArgument8;
+ (int)ok;
+ (int)operationTimedOut;
+ (int)otherEndClosed;
+ (int)sslConnectFailed;
+ (int)sslIdentityVerificationFailed;
@end

#endif // __WDAAllJoynStatus_DEFINED__

// Windows.Devices.AllJoyn.AllJoynAboutData
#ifndef __WDAAllJoynAboutData_DEFINED__
#define __WDAAllJoynAboutData_DEFINED__

WINRT_EXPORT
@interface WDAAllJoynAboutData : RTObject
@property (copy) NSString* defaultDescription;
@property (copy) NSString* defaultAppName;
@property (copy) id dateOfManufacture;
@property (copy) NSString* defaultManufacturer;
@property WFGUID* appId;
@property (copy) WFUri* supportUrl;
@property (copy) NSString* softwareVersion;
@property (copy) NSString* modelNumber;
@property BOOL isEnabled;
@property (readonly) NSMutableDictionary* appNames;
@property (readonly) NSMutableDictionary* manufacturers;
@property (readonly) NSMutableDictionary* descriptions;
@end

#endif // __WDAAllJoynAboutData_DEFINED__

// Windows.Devices.AllJoyn.AllJoynBusAttachment
#ifndef __WDAAllJoynBusAttachment_DEFINED__
#define __WDAAllJoynBusAttachment_DEFINED__

WINRT_EXPORT
@interface WDAAllJoynBusAttachment : RTObject
+ (WDAAllJoynBusAttachment*)create:(NSString*)connectionSpecification ACTIVATOR;
+ (instancetype)create ACTIVATOR;
@property (readonly) WDAAllJoynAboutData* aboutData;
@property (readonly) NSMutableArray* authenticationMechanisms;
@property (readonly) NSString* connectionSpecification;
@property (readonly) WDAAllJoynBusAttachmentState state;
@property (readonly) NSString* uniqueName;
- (EventRegistrationToken)addAuthenticationCompleteEvent:(void (^)(WDAAllJoynBusAttachment*,
                                                                   WDAAllJoynAuthenticationCompleteEventArgs*))del;
- (void)removeAuthenticationCompleteEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCredentialsRequestedEvent:(void (^)(WDAAllJoynBusAttachment*, WDAAllJoynCredentialsRequestedEventArgs*))del;
- (void)removeCredentialsRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCredentialsVerificationRequestedEvent:(void (^)(WDAAllJoynBusAttachment*,
                                                                             WDAAllJoynCredentialsVerificationRequestedEventArgs*))del;
- (void)removeCredentialsVerificationRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStateChangedEvent:(void (^)(WDAAllJoynBusAttachment*, WDAAllJoynBusAttachmentStateChangedEventArgs*))del;
- (void)removeStateChangedEvent:(EventRegistrationToken)tok;
- (void)pingAsync:(NSString*)uniqueName success:(void (^)(int))success failure:(void (^)(NSError*))failure;
- (void)connect;
- (void)disconnect;
@end

#endif // __WDAAllJoynBusAttachment_DEFINED__

// Windows.Devices.AllJoyn.AllJoynBusAttachmentStateChangedEventArgs
#ifndef __WDAAllJoynBusAttachmentStateChangedEventArgs_DEFINED__
#define __WDAAllJoynBusAttachmentStateChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDAAllJoynBusAttachmentStateChangedEventArgs : RTObject
@property (readonly) WDAAllJoynBusAttachmentState state;
@property (readonly) int status;
@end

#endif // __WDAAllJoynBusAttachmentStateChangedEventArgs_DEFINED__

// Windows.Devices.AllJoyn.AllJoynCredentialsRequestedEventArgs
#ifndef __WDAAllJoynCredentialsRequestedEventArgs_DEFINED__
#define __WDAAllJoynCredentialsRequestedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDAAllJoynCredentialsRequestedEventArgs : RTObject
@property (readonly) unsigned short attemptCount;
@property (readonly) WDAAllJoynCredentials* credentials;
@property (readonly) NSString* peerUniqueName;
@property (readonly) NSString* requestedUserName;
- (WFDeferral*)getDeferral;
@end

#endif // __WDAAllJoynCredentialsRequestedEventArgs_DEFINED__

// Windows.Devices.AllJoyn.AllJoynCredentialsVerificationRequestedEventArgs
#ifndef __WDAAllJoynCredentialsVerificationRequestedEventArgs_DEFINED__
#define __WDAAllJoynCredentialsVerificationRequestedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDAAllJoynCredentialsVerificationRequestedEventArgs : RTObject
@property (readonly) WDAAllJoynAuthenticationMechanism authenticationMechanism;
@property (readonly) WSCCCertificate* peerCertificate;
@property (readonly) WNSSocketSslErrorSeverity peerCertificateErrorSeverity;
@property (readonly) NSArray* peerCertificateErrors;
@property (readonly) NSArray* peerIntermediateCertificates;
@property (readonly) NSString* peerUniqueName;
- (void)accept;
- (WFDeferral*)getDeferral;
@end

#endif // __WDAAllJoynCredentialsVerificationRequestedEventArgs_DEFINED__

// Windows.Devices.AllJoyn.AllJoynAuthenticationCompleteEventArgs
#ifndef __WDAAllJoynAuthenticationCompleteEventArgs_DEFINED__
#define __WDAAllJoynAuthenticationCompleteEventArgs_DEFINED__

WINRT_EXPORT
@interface WDAAllJoynAuthenticationCompleteEventArgs : RTObject
@property (readonly) WDAAllJoynAuthenticationMechanism authenticationMechanism;
@property (readonly) NSString* peerUniqueName;
@property (readonly) BOOL succeeded;
@end

#endif // __WDAAllJoynAuthenticationCompleteEventArgs_DEFINED__

// Windows.Devices.AllJoyn.AllJoynCredentials
#ifndef __WDAAllJoynCredentials_DEFINED__
#define __WDAAllJoynCredentials_DEFINED__

WINRT_EXPORT
@interface WDAAllJoynCredentials : RTObject
@property (copy) WFTimeSpan* timeout;
@property (copy) WSCPasswordCredential* passwordCredential;
@property (copy) WSCCCertificate* certificate;
@property (readonly) WDAAllJoynAuthenticationMechanism authenticationMechanism;
@end

#endif // __WDAAllJoynCredentials_DEFINED__

// Windows.Devices.AllJoyn.AllJoynServiceInfo
#ifndef __WDAAllJoynServiceInfo_DEFINED__
#define __WDAAllJoynServiceInfo_DEFINED__

WINRT_EXPORT
@interface WDAAllJoynServiceInfo : RTObject
+ (WDAAllJoynServiceInfo*)create:(NSString*)uniqueName objectPath:(NSString*)objectPath sessionPort:(unsigned short)sessionPort ACTIVATOR;
@property (readonly) NSString* objectPath;
@property (readonly) unsigned short sessionPort;
@property (readonly) NSString* uniqueName;
@end

#endif // __WDAAllJoynServiceInfo_DEFINED__

// Windows.Devices.AllJoyn.AllJoynAboutDataView
#ifndef __WDAAllJoynAboutDataView_DEFINED__
#define __WDAAllJoynAboutDataView_DEFINED__

WINRT_EXPORT
@interface WDAAllJoynAboutDataView : RTObject
+ (void)getDataBySessionPortAsync:(NSString*)uniqueName
                    busAttachment:(WDAAllJoynBusAttachment*)busAttachment
                      sessionPort:(unsigned short)sessionPort
                          success:(void (^)(WDAAllJoynAboutDataView*))success
                          failure:(void (^)(NSError*))failure;
+ (void)getDataBySessionPortWithLanguageAsync:(NSString*)uniqueName
                                busAttachment:(WDAAllJoynBusAttachment*)busAttachment
                                  sessionPort:(unsigned short)sessionPort
                                     language:(WGLanguage*)language
                                      success:(void (^)(WDAAllJoynAboutDataView*))success
                                      failure:(void (^)(NSError*))failure;
@property (readonly) NSString* aJSoftwareVersion;
@property (readonly) WFGUID* appId;
@property (readonly) NSString* appName;
@property (readonly) id dateOfManufacture;
@property (readonly) WGLanguage* defaultLanguage;
@property (readonly) NSString* description;
@property (readonly) NSString* deviceId;
@property (readonly) NSString* deviceName;
@property (readonly) NSString* hardwareVersion;
@property (readonly) NSString* manufacturer;
@property (readonly) NSString* modelNumber;
@property (readonly) NSDictionary* properties;
@property (readonly) NSString* softwareVersion;
@property (readonly) int status;
@property (readonly) WFUri* supportUrl;
@property (readonly) NSArray* supportedLanguages;
@end

#endif // __WDAAllJoynAboutDataView_DEFINED__

// Windows.Devices.AllJoyn.AllJoynAcceptSessionJoinerEventArgs
#ifndef __WDAAllJoynAcceptSessionJoinerEventArgs_DEFINED__
#define __WDAAllJoynAcceptSessionJoinerEventArgs_DEFINED__

WINRT_EXPORT
@interface WDAAllJoynAcceptSessionJoinerEventArgs : RTObject
+ (WDAAllJoynAcceptSessionJoinerEventArgs*)create:(NSString*)uniqueName
                                      sessionPort:(unsigned short)sessionPort
                                      trafficType:(WDAAllJoynTrafficType)trafficType
                                        proximity:(uint8_t)proximity
                              acceptSessionJoiner:(RTObject<WDAIAllJoynAcceptSessionJoiner>*)acceptSessionJoiner ACTIVATOR;
@property (readonly) BOOL sameNetwork;
@property (readonly) BOOL samePhysicalNode;
@property (readonly) unsigned short sessionPort;
@property (readonly) WDAAllJoynTrafficType trafficType;
@property (readonly) NSString* uniqueName;
- (void)accept;
@end

#endif // __WDAAllJoynAcceptSessionJoinerEventArgs_DEFINED__

// Windows.Devices.AllJoyn.AllJoynSessionMemberAddedEventArgs
#ifndef __WDAAllJoynSessionMemberAddedEventArgs_DEFINED__
#define __WDAAllJoynSessionMemberAddedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDAAllJoynSessionMemberAddedEventArgs : RTObject
+ (WDAAllJoynSessionMemberAddedEventArgs*)create:(NSString*)uniqueName ACTIVATOR;
@property (readonly) NSString* uniqueName;
@end

#endif // __WDAAllJoynSessionMemberAddedEventArgs_DEFINED__

// Windows.Devices.AllJoyn.AllJoynSessionMemberRemovedEventArgs
#ifndef __WDAAllJoynSessionMemberRemovedEventArgs_DEFINED__
#define __WDAAllJoynSessionMemberRemovedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDAAllJoynSessionMemberRemovedEventArgs : RTObject
+ (WDAAllJoynSessionMemberRemovedEventArgs*)create:(NSString*)uniqueName ACTIVATOR;
@property (readonly) NSString* uniqueName;
@end

#endif // __WDAAllJoynSessionMemberRemovedEventArgs_DEFINED__

// Windows.Devices.AllJoyn.AllJoynSessionLostEventArgs
#ifndef __WDAAllJoynSessionLostEventArgs_DEFINED__
#define __WDAAllJoynSessionLostEventArgs_DEFINED__

WINRT_EXPORT
@interface WDAAllJoynSessionLostEventArgs : RTObject
+ (WDAAllJoynSessionLostEventArgs*)create:(WDAAllJoynSessionLostReason)reason ACTIVATOR;
@property (readonly) WDAAllJoynSessionLostReason reason;
@end

#endif // __WDAAllJoynSessionLostEventArgs_DEFINED__

// Windows.Devices.AllJoyn.AllJoynProducerStoppedEventArgs
#ifndef __WDAAllJoynProducerStoppedEventArgs_DEFINED__
#define __WDAAllJoynProducerStoppedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDAAllJoynProducerStoppedEventArgs : RTObject
+ (WDAAllJoynProducerStoppedEventArgs*)create:(int)status ACTIVATOR;
@property (readonly) int status;
@end

#endif // __WDAAllJoynProducerStoppedEventArgs_DEFINED__

// Windows.Devices.AllJoyn.AllJoynWatcherStoppedEventArgs
#ifndef __WDAAllJoynWatcherStoppedEventArgs_DEFINED__
#define __WDAAllJoynWatcherStoppedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDAAllJoynWatcherStoppedEventArgs : RTObject
+ (WDAAllJoynWatcherStoppedEventArgs*)create:(int)status ACTIVATOR;
@property (readonly) int status;
@end

#endif // __WDAAllJoynWatcherStoppedEventArgs_DEFINED__

// Windows.Devices.AllJoyn.AllJoynServiceInfoRemovedEventArgs
#ifndef __WDAAllJoynServiceInfoRemovedEventArgs_DEFINED__
#define __WDAAllJoynServiceInfoRemovedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDAAllJoynServiceInfoRemovedEventArgs : RTObject
+ (WDAAllJoynServiceInfoRemovedEventArgs*)create:(NSString*)uniqueName ACTIVATOR;
@property (readonly) NSString* uniqueName;
@end

#endif // __WDAAllJoynServiceInfoRemovedEventArgs_DEFINED__

// Windows.Devices.AllJoyn.AllJoynMessageInfo
#ifndef __WDAAllJoynMessageInfo_DEFINED__
#define __WDAAllJoynMessageInfo_DEFINED__

WINRT_EXPORT
@interface WDAAllJoynMessageInfo : RTObject
+ (WDAAllJoynMessageInfo*)create:(NSString*)senderUniqueName ACTIVATOR;
@property (readonly) NSString* senderUniqueName;
@end

#endif // __WDAAllJoynMessageInfo_DEFINED__
