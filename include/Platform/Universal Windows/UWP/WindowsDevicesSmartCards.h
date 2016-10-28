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

// WindowsDevicesSmartCards.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_DEVICES_SMARTCARDS_EXPORT
#define OBJCUWP_WINDOWS_DEVICES_SMARTCARDS_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_Devices_SmartCards.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WDSSmartCardReader, WDSSmartCard, WDSCardAddedEventArgs, WDSCardRemovedEventArgs, WDSSmartCardProvisioning, WDSSmartCardPinPolicy,
    WDSSmartCardChallengeContext, WDSSmartCardPinResetRequest, WDSSmartCardPinResetDeferral, WDSSmartCardConnection;
@protocol WDSISmartCardReaderStatics
, WDSISmartCardReader, WDSICardAddedEventArgs, WDSICardRemovedEventArgs, WDSISmartCard, WDSISmartCardProvisioningStatics,
    WDSISmartCardProvisioningStatics2, WDSISmartCardProvisioning, WDSISmartCardProvisioning2, WDSISmartCardPinResetRequest,
    WDSISmartCardPinResetDeferral, WDSISmartCardPinPolicy, WDSISmartCardConnect, WDSISmartCardChallengeContext, WDSISmartCardConnection;

// Windows.Devices.SmartCards.SmartCardReaderKind
enum _WDSSmartCardReaderKind {
    WDSSmartCardReaderKindAny = 0,
    WDSSmartCardReaderKindGeneric = 1,
    WDSSmartCardReaderKindTpm = 2,
    WDSSmartCardReaderKindNfc = 3,
    WDSSmartCardReaderKindUicc = 4,
};
typedef unsigned WDSSmartCardReaderKind;

// Windows.Devices.SmartCards.SmartCardReaderStatus
enum _WDSSmartCardReaderStatus {
    WDSSmartCardReaderStatusDisconnected = 0,
    WDSSmartCardReaderStatusReady = 1,
    WDSSmartCardReaderStatusExclusive = 2,
};
typedef unsigned WDSSmartCardReaderStatus;

// Windows.Devices.SmartCards.SmartCardStatus
enum _WDSSmartCardStatus {
    WDSSmartCardStatusDisconnected = 0,
    WDSSmartCardStatusReady = 1,
    WDSSmartCardStatusShared = 2,
    WDSSmartCardStatusExclusive = 3,
    WDSSmartCardStatusUnresponsive = 4,
};
typedef unsigned WDSSmartCardStatus;

// Windows.Devices.SmartCards.SmartCardPinCharacterPolicyOption
enum _WDSSmartCardPinCharacterPolicyOption {
    WDSSmartCardPinCharacterPolicyOptionAllow = 0,
    WDSSmartCardPinCharacterPolicyOptionRequireAtLeastOne = 1,
    WDSSmartCardPinCharacterPolicyOptionDisallow = 2,
};
typedef unsigned WDSSmartCardPinCharacterPolicyOption;

#include "WindowsFoundation.h"
#include "WindowsStorageStreams.h"
// Windows.Devices.SmartCards.SmartCardPinResetHandler
#ifndef __WDSSmartCardPinResetHandler__DEFINED
#define __WDSSmartCardPinResetHandler__DEFINED
typedef void (^WDSSmartCardPinResetHandler)(WDSSmartCardProvisioning* sender, WDSSmartCardPinResetRequest* request);
#endif // __WDSSmartCardPinResetHandler__DEFINED

#import <Foundation/Foundation.h>

// Windows.Devices.SmartCards.SmartCardPinResetHandler
#ifndef __WDSSmartCardPinResetHandler__DEFINED
#define __WDSSmartCardPinResetHandler__DEFINED
typedef void (^WDSSmartCardPinResetHandler)(WDSSmartCardProvisioning* sender, WDSSmartCardPinResetRequest* request);
#endif // __WDSSmartCardPinResetHandler__DEFINED

// Windows.Devices.SmartCards.SmartCardReader
#ifndef __WDSSmartCardReader_DEFINED__
#define __WDSSmartCardReader_DEFINED__

OBJCUWP_WINDOWS_DEVICES_SMARTCARDS_EXPORT
@interface WDSSmartCardReader : RTObject
+ (NSString*)getDeviceSelector;
+ (NSString*)getDeviceSelectorWithKind:(WDSSmartCardReaderKind)kind;
+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDSSmartCardReader*))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) NSString* deviceId;
@property (readonly) WDSSmartCardReaderKind kind;
@property (readonly) NSString* name;
- (EventRegistrationToken)addCardAddedEvent:(void (^)(WDSSmartCardReader*, WDSCardAddedEventArgs*))del;
- (void)removeCardAddedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCardRemovedEvent:(void (^)(WDSSmartCardReader*, WDSCardRemovedEventArgs*))del;
- (void)removeCardRemovedEvent:(EventRegistrationToken)tok;
- (void)getStatusAsyncWithSuccess:(void (^)(WDSSmartCardReaderStatus))success failure:(void (^)(NSError*))failure;
- (void)findAllCardsAsyncWithSuccess:(void (^)(NSArray* /* WDSSmartCard* */))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDSSmartCardReader_DEFINED__

// Windows.Devices.SmartCards.SmartCard
#ifndef __WDSSmartCard_DEFINED__
#define __WDSSmartCard_DEFINED__

OBJCUWP_WINDOWS_DEVICES_SMARTCARDS_EXPORT
@interface WDSSmartCard : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WDSSmartCardReader* reader;
- (void)getStatusAsyncWithSuccess:(void (^)(WDSSmartCardStatus))success failure:(void (^)(NSError*))failure;
- (void)getAnswerToResetAsyncWithSuccess:(void (^)(RTObject<WSSIBuffer>*))success failure:(void (^)(NSError*))failure;
- (void)connectAsyncWithSuccess:(void (^)(WDSSmartCardConnection*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDSSmartCard_DEFINED__

// Windows.Devices.SmartCards.CardAddedEventArgs
#ifndef __WDSCardAddedEventArgs_DEFINED__
#define __WDSCardAddedEventArgs_DEFINED__

OBJCUWP_WINDOWS_DEVICES_SMARTCARDS_EXPORT
@interface WDSCardAddedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WDSSmartCard* smartCard;
@end

#endif // __WDSCardAddedEventArgs_DEFINED__

// Windows.Devices.SmartCards.CardRemovedEventArgs
#ifndef __WDSCardRemovedEventArgs_DEFINED__
#define __WDSCardRemovedEventArgs_DEFINED__

OBJCUWP_WINDOWS_DEVICES_SMARTCARDS_EXPORT
@interface WDSCardRemovedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WDSSmartCard* smartCard;
@end

#endif // __WDSCardRemovedEventArgs_DEFINED__

// Windows.Devices.SmartCards.SmartCardProvisioning
#ifndef __WDSSmartCardProvisioning_DEFINED__
#define __WDSSmartCardProvisioning_DEFINED__

OBJCUWP_WINDOWS_DEVICES_SMARTCARDS_EXPORT
@interface WDSSmartCardProvisioning : RTObject
+ (void)fromSmartCardAsync:(WDSSmartCard*)card success:(void (^)(WDSSmartCardProvisioning*))success failure:(void (^)(NSError*))failure;
+ (void)requestVirtualSmartCardCreationAsync:(NSString*)friendlyName
                           administrativeKey:(RTObject<WSSIBuffer>*)administrativeKey
                                   pinPolicy:(WDSSmartCardPinPolicy*)pinPolicy
                                     success:(void (^)(WDSSmartCardProvisioning*))success
                                     failure:(void (^)(NSError*))failure;
+ (void)requestVirtualSmartCardCreationAsyncWithCardId:(NSString*)friendlyName
                                     administrativeKey:(RTObject<WSSIBuffer>*)administrativeKey
                                             pinPolicy:(WDSSmartCardPinPolicy*)pinPolicy
                                                cardId:(WFGUID*)cardId
                                               success:(void (^)(WDSSmartCardProvisioning*))success
                                               failure:(void (^)(NSError*))failure;
+ (void)requestVirtualSmartCardDeletionAsync:(WDSSmartCard*)card success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
+ (void)requestAttestedVirtualSmartCardCreationAsync:(NSString*)friendlyName
                                   administrativeKey:(RTObject<WSSIBuffer>*)administrativeKey
                                           pinPolicy:(WDSSmartCardPinPolicy*)pinPolicy
                                             success:(void (^)(WDSSmartCardProvisioning*))success
                                             failure:(void (^)(NSError*))failure;
+ (void)requestAttestedVirtualSmartCardCreationAsyncWithCardId:(NSString*)friendlyName
                                             administrativeKey:(RTObject<WSSIBuffer>*)administrativeKey
                                                     pinPolicy:(WDSSmartCardPinPolicy*)pinPolicy
                                                        cardId:(WFGUID*)cardId
                                                       success:(void (^)(WDSSmartCardProvisioning*))success
                                                       failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WDSSmartCard* smartCard;
- (void)getIdAsyncWithSuccess:(void (^)(WFGUID*))success failure:(void (^)(NSError*))failure;
- (void)getNameAsyncWithSuccess:(void (^)(NSString*))success failure:(void (^)(NSError*))failure;
- (void)getChallengeContextAsyncWithSuccess:(void (^)(WDSSmartCardChallengeContext*))success failure:(void (^)(NSError*))failure;
- (void)requestPinChangeAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)requestPinResetAsync:(WDSSmartCardPinResetHandler)handler success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)getAuthorityKeyContainerNameAsyncWithSuccess:(void (^)(NSString*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDSSmartCardProvisioning_DEFINED__

// Windows.Devices.SmartCards.SmartCardPinPolicy
#ifndef __WDSSmartCardPinPolicy_DEFINED__
#define __WDSSmartCardPinPolicy_DEFINED__

OBJCUWP_WINDOWS_DEVICES_SMARTCARDS_EXPORT
@interface WDSSmartCardPinPolicy : RTObject
+ (instancetype)make ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property WDSSmartCardPinCharacterPolicyOption uppercaseLetters;
@property WDSSmartCardPinCharacterPolicyOption specialCharacters;
@property unsigned int minLength;
@property unsigned int maxLength;
@property WDSSmartCardPinCharacterPolicyOption lowercaseLetters;
@property WDSSmartCardPinCharacterPolicyOption digits;
@end

#endif // __WDSSmartCardPinPolicy_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWP_WINDOWS_DEVICES_SMARTCARDS_EXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.Devices.SmartCards.SmartCardChallengeContext
#ifndef __WDSSmartCardChallengeContext_DEFINED__
#define __WDSSmartCardChallengeContext_DEFINED__

OBJCUWP_WINDOWS_DEVICES_SMARTCARDS_EXPORT
@interface WDSSmartCardChallengeContext : RTObject <WFIClosable>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) RTObject<WSSIBuffer>* challenge;
- (void)verifyResponseAsync:(RTObject<WSSIBuffer>*)response success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)provisionAsync:(RTObject<WSSIBuffer>*)response formatCard:(BOOL)formatCard;
- (RTObject<WFIAsyncAction>*)provisionAsyncWithNewCardId:(RTObject<WSSIBuffer>*)response
                                              formatCard:(BOOL)formatCard
                                               newCardId:(WFGUID*)newCardId;
- (RTObject<WFIAsyncAction>*)changeAdministrativeKeyAsync:(RTObject<WSSIBuffer>*)response
                                     newAdministrativeKey:(RTObject<WSSIBuffer>*)newAdministrativeKey;
- (void)close;
@end

#endif // __WDSSmartCardChallengeContext_DEFINED__

// Windows.Devices.SmartCards.SmartCardPinResetRequest
#ifndef __WDSSmartCardPinResetRequest_DEFINED__
#define __WDSSmartCardPinResetRequest_DEFINED__

OBJCUWP_WINDOWS_DEVICES_SMARTCARDS_EXPORT
@interface WDSSmartCardPinResetRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) RTObject<WSSIBuffer>* challenge;
@property (readonly) WFDateTime* deadline;
- (WDSSmartCardPinResetDeferral*)getDeferral;
- (void)setResponse:(RTObject<WSSIBuffer>*)response;
@end

#endif // __WDSSmartCardPinResetRequest_DEFINED__

// Windows.Devices.SmartCards.SmartCardPinResetDeferral
#ifndef __WDSSmartCardPinResetDeferral_DEFINED__
#define __WDSSmartCardPinResetDeferral_DEFINED__

OBJCUWP_WINDOWS_DEVICES_SMARTCARDS_EXPORT
@interface WDSSmartCardPinResetDeferral : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
- (void)complete;
@end

#endif // __WDSSmartCardPinResetDeferral_DEFINED__

// Windows.Devices.SmartCards.SmartCardConnection
#ifndef __WDSSmartCardConnection_DEFINED__
#define __WDSSmartCardConnection_DEFINED__

OBJCUWP_WINDOWS_DEVICES_SMARTCARDS_EXPORT
@interface WDSSmartCardConnection : RTObject <WFIClosable>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
- (void)transmitAsync:(RTObject<WSSIBuffer>*)command success:(void (^)(RTObject<WSSIBuffer>*))success failure:(void (^)(NSError*))failure;
- (void)close;
@end

#endif // __WDSSmartCardConnection_DEFINED__
