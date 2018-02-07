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

// WindowsSecurityAuthenticationIdentityProvider.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSSECURITYAUTHENTICATIONIDENTITYPROVIDEREXPORT
#define OBJCUWPWINDOWSSECURITYAUTHENTICATIONIDENTITYPROVIDEREXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsSecurityAuthenticationIdentityProvider.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WSAIPSecondaryAuthenticationFactorRegistration, WSAIPSecondaryAuthenticationFactorRegistrationResult, WSAIPSecondaryAuthenticationFactorAuthentication, WSAIPSecondaryAuthenticationFactorAuthenticationResult, WSAIPSecondaryAuthenticationFactorInfo, WSAIPSecondaryAuthenticationFactorAuthenticationStageChangedEventArgs, WSAIPSecondaryAuthenticationFactorAuthenticationStageInfo;
@protocol WSAIPISecondaryAuthenticationFactorRegistrationResult, WSAIPISecondaryAuthenticationFactorAuthenticationResult, WSAIPISecondaryAuthenticationFactorRegistrationStatics, WSAIPISecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatics, WSAIPISecondaryAuthenticationFactorRegistration, WSAIPISecondaryAuthenticationFactorAuthenticationStatics, WSAIPISecondaryAuthenticationFactorAuthentication, WSAIPISecondaryAuthenticationFactorInfo, WSAIPISecondaryAuthenticationFactorInfo2, WSAIPISecondaryAuthenticationFactorAuthenticationStageInfo, WSAIPISecondaryAuthenticationFactorAuthenticationStageChangedEventArgs;

// Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorDeviceCapabilities
enum _WSAIPSecondaryAuthenticationFactorDeviceCapabilities {
    WSAIPSecondaryAuthenticationFactorDeviceCapabilitiesNone = 0,
    WSAIPSecondaryAuthenticationFactorDeviceCapabilitiesSecureStorage = 1,
    WSAIPSecondaryAuthenticationFactorDeviceCapabilitiesStoreKeys = 2,
    WSAIPSecondaryAuthenticationFactorDeviceCapabilitiesConfirmUserIntentToAuthenticate = 4,
    WSAIPSecondaryAuthenticationFactorDeviceCapabilitiesSupportSecureUserPresenceCheck = 8,
    WSAIPSecondaryAuthenticationFactorDeviceCapabilitiesTransmittedDataIsEncrypted = 16,
    WSAIPSecondaryAuthenticationFactorDeviceCapabilitiesHMacSha256 = 32,
    WSAIPSecondaryAuthenticationFactorDeviceCapabilitiesCloseRangeDataTransmission = 64,
};
typedef unsigned WSAIPSecondaryAuthenticationFactorDeviceCapabilities;

// Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorDeviceFindScope
enum _WSAIPSecondaryAuthenticationFactorDeviceFindScope {
    WSAIPSecondaryAuthenticationFactorDeviceFindScopeUser = 0,
    WSAIPSecondaryAuthenticationFactorDeviceFindScopeAllUsers = 1,
};
typedef unsigned WSAIPSecondaryAuthenticationFactorDeviceFindScope;

// Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorAuthenticationStage
enum _WSAIPSecondaryAuthenticationFactorAuthenticationStage {
    WSAIPSecondaryAuthenticationFactorAuthenticationStageNotStarted = 0,
    WSAIPSecondaryAuthenticationFactorAuthenticationStageWaitingForUserConfirmation = 1,
    WSAIPSecondaryAuthenticationFactorAuthenticationStageCollectingCredential = 2,
    WSAIPSecondaryAuthenticationFactorAuthenticationStageSuspendingAuthentication = 3,
    WSAIPSecondaryAuthenticationFactorAuthenticationStageCredentialCollected = 4,
    WSAIPSecondaryAuthenticationFactorAuthenticationStageCredentialAuthenticated = 5,
    WSAIPSecondaryAuthenticationFactorAuthenticationStageStoppingAuthentication = 6,
    WSAIPSecondaryAuthenticationFactorAuthenticationStageReadyForLock = 7,
    WSAIPSecondaryAuthenticationFactorAuthenticationStageCheckingDevicePresence = 8,
};
typedef unsigned WSAIPSecondaryAuthenticationFactorAuthenticationStage;

// Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorRegistrationStatus
enum _WSAIPSecondaryAuthenticationFactorRegistrationStatus {
    WSAIPSecondaryAuthenticationFactorRegistrationStatusFailed = 0,
    WSAIPSecondaryAuthenticationFactorRegistrationStatusStarted = 1,
    WSAIPSecondaryAuthenticationFactorRegistrationStatusCanceledByUser = 2,
    WSAIPSecondaryAuthenticationFactorRegistrationStatusPinSetupRequired = 3,
    WSAIPSecondaryAuthenticationFactorRegistrationStatusDisabledByPolicy = 4,
};
typedef unsigned WSAIPSecondaryAuthenticationFactorRegistrationStatus;

// Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatus
enum _WSAIPSecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatus {
    WSAIPSecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatusUnsupported = 0,
    WSAIPSecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatusSucceeded = 1,
    WSAIPSecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatusDisabledByPolicy = 2,
};
typedef unsigned WSAIPSecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatus;

// Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorAuthenticationStatus
enum _WSAIPSecondaryAuthenticationFactorAuthenticationStatus {
    WSAIPSecondaryAuthenticationFactorAuthenticationStatusFailed = 0,
    WSAIPSecondaryAuthenticationFactorAuthenticationStatusStarted = 1,
    WSAIPSecondaryAuthenticationFactorAuthenticationStatusUnknownDevice = 2,
    WSAIPSecondaryAuthenticationFactorAuthenticationStatusDisabledByPolicy = 3,
    WSAIPSecondaryAuthenticationFactorAuthenticationStatusInvalidAuthenticationStage = 4,
};
typedef unsigned WSAIPSecondaryAuthenticationFactorAuthenticationStatus;

// Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorFinishAuthenticationStatus
enum _WSAIPSecondaryAuthenticationFactorFinishAuthenticationStatus {
    WSAIPSecondaryAuthenticationFactorFinishAuthenticationStatusFailed = 0,
    WSAIPSecondaryAuthenticationFactorFinishAuthenticationStatusCompleted = 1,
    WSAIPSecondaryAuthenticationFactorFinishAuthenticationStatusNonceExpired = 2,
};
typedef unsigned WSAIPSecondaryAuthenticationFactorFinishAuthenticationStatus;

// Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorAuthenticationScenario
enum _WSAIPSecondaryAuthenticationFactorAuthenticationScenario {
    WSAIPSecondaryAuthenticationFactorAuthenticationScenarioSignIn = 0,
    WSAIPSecondaryAuthenticationFactorAuthenticationScenarioCredentialPrompt = 1,
};
typedef unsigned WSAIPSecondaryAuthenticationFactorAuthenticationScenario;

// Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorAuthenticationMessage
enum _WSAIPSecondaryAuthenticationFactorAuthenticationMessage {
    WSAIPSecondaryAuthenticationFactorAuthenticationMessageInvalid = 0,
    WSAIPSecondaryAuthenticationFactorAuthenticationMessageSwipeUpWelcome = 1,
    WSAIPSecondaryAuthenticationFactorAuthenticationMessageTapWelcome = 2,
    WSAIPSecondaryAuthenticationFactorAuthenticationMessageDeviceNeedsAttention = 3,
    WSAIPSecondaryAuthenticationFactorAuthenticationMessageLookingForDevice = 4,
    WSAIPSecondaryAuthenticationFactorAuthenticationMessageLookingForDevicePluggedin = 5,
    WSAIPSecondaryAuthenticationFactorAuthenticationMessageBluetoothIsDisabled = 6,
    WSAIPSecondaryAuthenticationFactorAuthenticationMessageNfcIsDisabled = 7,
    WSAIPSecondaryAuthenticationFactorAuthenticationMessageWiFiIsDisabled = 8,
    WSAIPSecondaryAuthenticationFactorAuthenticationMessageExtraTapIsRequired = 9,
    WSAIPSecondaryAuthenticationFactorAuthenticationMessageDisabledByPolicy = 10,
    WSAIPSecondaryAuthenticationFactorAuthenticationMessageTapOnDeviceRequired = 11,
    WSAIPSecondaryAuthenticationFactorAuthenticationMessageHoldFinger = 12,
    WSAIPSecondaryAuthenticationFactorAuthenticationMessageScanFinger = 13,
    WSAIPSecondaryAuthenticationFactorAuthenticationMessageUnauthorizedUser = 14,
    WSAIPSecondaryAuthenticationFactorAuthenticationMessageReregisterRequired = 15,
    WSAIPSecondaryAuthenticationFactorAuthenticationMessageTryAgain = 16,
    WSAIPSecondaryAuthenticationFactorAuthenticationMessageSayPassphrase = 17,
    WSAIPSecondaryAuthenticationFactorAuthenticationMessageReadyToSignIn = 18,
    WSAIPSecondaryAuthenticationFactorAuthenticationMessageUseAnotherSignInOption = 19,
};
typedef unsigned WSAIPSecondaryAuthenticationFactorAuthenticationMessage;

// Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorDevicePresence
enum _WSAIPSecondaryAuthenticationFactorDevicePresence {
    WSAIPSecondaryAuthenticationFactorDevicePresenceAbsent = 0,
    WSAIPSecondaryAuthenticationFactorDevicePresencePresent = 1,
};
typedef unsigned WSAIPSecondaryAuthenticationFactorDevicePresence;

// Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorDevicePresenceMonitoringMode
enum _WSAIPSecondaryAuthenticationFactorDevicePresenceMonitoringMode {
    WSAIPSecondaryAuthenticationFactorDevicePresenceMonitoringModeUnsupported = 0,
    WSAIPSecondaryAuthenticationFactorDevicePresenceMonitoringModeAppManaged = 1,
    WSAIPSecondaryAuthenticationFactorDevicePresenceMonitoringModeSystemManaged = 2,
};
typedef unsigned WSAIPSecondaryAuthenticationFactorDevicePresenceMonitoringMode;

#include "WindowsStorageStreams.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorRegistration
#ifndef __WSAIPSecondaryAuthenticationFactorRegistration_DEFINED__
#define __WSAIPSecondaryAuthenticationFactorRegistration_DEFINED__

OBJCUWPWINDOWSSECURITYAUTHENTICATIONIDENTITYPROVIDEREXPORT
@interface WSAIPSecondaryAuthenticationFactorRegistration : RTObject
+ (void)requestStartRegisteringDeviceAsync:(NSString *)deviceId capabilities:(WSAIPSecondaryAuthenticationFactorDeviceCapabilities)capabilities deviceFriendlyName:(NSString *)deviceFriendlyName deviceModelNumber:(NSString *)deviceModelNumber deviceKey:(RTObject<WSSIBuffer>*)deviceKey mutualAuthenticationKey:(RTObject<WSSIBuffer>*)mutualAuthenticationKey success:(void (^)(WSAIPSecondaryAuthenticationFactorRegistrationResult*))success failure:(void (^)(NSError*))failure;
+ (void)findAllRegisteredDeviceInfoAsync:(WSAIPSecondaryAuthenticationFactorDeviceFindScope)queryType success:(void (^)(NSArray* /* WSAIPSecondaryAuthenticationFactorInfo* */))success failure:(void (^)(NSError*))failure;
+ (RTObject<WFIAsyncAction>*)unregisterDeviceAsync:(NSString *)deviceId;
+ (RTObject<WFIAsyncAction>*)updateDeviceConfigurationDataAsync:(NSString *)deviceId deviceConfigurationData:(RTObject<WSSIBuffer>*)deviceConfigurationData;
+ (void)registerDevicePresenceMonitoringAsync:(NSString *)deviceId deviceInstancePath:(NSString *)deviceInstancePath monitoringMode:(WSAIPSecondaryAuthenticationFactorDevicePresenceMonitoringMode)monitoringMode success:(void (^)(WSAIPSecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatus))success failure:(void (^)(NSError*))failure;
+ (void)registerDevicePresenceMonitoringWithNewDeviceAsync:(NSString *)deviceId deviceInstancePath:(NSString *)deviceInstancePath monitoringMode:(WSAIPSecondaryAuthenticationFactorDevicePresenceMonitoringMode)monitoringMode deviceFriendlyName:(NSString *)deviceFriendlyName deviceModelNumber:(NSString *)deviceModelNumber deviceConfigurationData:(RTObject<WSSIBuffer>*)deviceConfigurationData success:(void (^)(WSAIPSecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatus))success failure:(void (^)(NSError*))failure;
+ (RTObject<WFIAsyncAction>*)unregisterDevicePresenceMonitoringAsync:(NSString *)deviceId;
+ (BOOL)isDevicePresenceMonitoringSupported;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (RTObject<WFIAsyncAction>*)finishRegisteringDeviceAsync:(RTObject<WSSIBuffer>*)deviceConfigurationData;
- (RTObject<WFIAsyncAction>*)abortRegisteringDeviceAsync:(NSString *)errorLogMessage;
@end

#endif // __WSAIPSecondaryAuthenticationFactorRegistration_DEFINED__

// Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorRegistrationResult
#ifndef __WSAIPSecondaryAuthenticationFactorRegistrationResult_DEFINED__
#define __WSAIPSecondaryAuthenticationFactorRegistrationResult_DEFINED__

OBJCUWPWINDOWSSECURITYAUTHENTICATIONIDENTITYPROVIDEREXPORT
@interface WSAIPSecondaryAuthenticationFactorRegistrationResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSAIPSecondaryAuthenticationFactorRegistration* registration;
@property (readonly) WSAIPSecondaryAuthenticationFactorRegistrationStatus status;
@end

#endif // __WSAIPSecondaryAuthenticationFactorRegistrationResult_DEFINED__

// Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorAuthentication
#ifndef __WSAIPSecondaryAuthenticationFactorAuthentication_DEFINED__
#define __WSAIPSecondaryAuthenticationFactorAuthentication_DEFINED__

OBJCUWPWINDOWSSECURITYAUTHENTICATIONIDENTITYPROVIDEREXPORT
@interface WSAIPSecondaryAuthenticationFactorAuthentication : RTObject
+ (RTObject<WFIAsyncAction>*)showNotificationMessageAsync:(NSString *)deviceName message:(WSAIPSecondaryAuthenticationFactorAuthenticationMessage)message;
+ (void)startAuthenticationAsync:(NSString *)deviceId serviceAuthenticationNonce:(RTObject<WSSIBuffer>*)serviceAuthenticationNonce success:(void (^)(WSAIPSecondaryAuthenticationFactorAuthenticationResult*))success failure:(void (^)(NSError*))failure;
+ (void)getAuthenticationStageInfoAsyncWithSuccess:(void (^)(WSAIPSecondaryAuthenticationFactorAuthenticationStageInfo*))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) RTObject<WSSIBuffer>* deviceConfigurationData;
@property (readonly) RTObject<WSSIBuffer>* deviceNonce;
@property (readonly) RTObject<WSSIBuffer>* serviceAuthenticationHmac;
@property (readonly) RTObject<WSSIBuffer>* sessionNonce;
+ (EventRegistrationToken)addAuthenticationStageChangedEvent:(void(^)(RTObject*, WSAIPSecondaryAuthenticationFactorAuthenticationStageChangedEventArgs*))del;
+ (void)removeAuthenticationStageChangedEvent:(EventRegistrationToken)tok;
- (void)finishAuthenticationAsync:(RTObject<WSSIBuffer>*)deviceHmac sessionHmac:(RTObject<WSSIBuffer>*)sessionHmac success:(void (^)(WSAIPSecondaryAuthenticationFactorFinishAuthenticationStatus))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)abortAuthenticationAsync:(NSString *)errorLogMessage;
@end

#endif // __WSAIPSecondaryAuthenticationFactorAuthentication_DEFINED__

// Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorAuthenticationResult
#ifndef __WSAIPSecondaryAuthenticationFactorAuthenticationResult_DEFINED__
#define __WSAIPSecondaryAuthenticationFactorAuthenticationResult_DEFINED__

OBJCUWPWINDOWSSECURITYAUTHENTICATIONIDENTITYPROVIDEREXPORT
@interface WSAIPSecondaryAuthenticationFactorAuthenticationResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSAIPSecondaryAuthenticationFactorAuthentication* authentication;
@property (readonly) WSAIPSecondaryAuthenticationFactorAuthenticationStatus status;
@end

#endif // __WSAIPSecondaryAuthenticationFactorAuthenticationResult_DEFINED__

// Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorInfo
#ifndef __WSAIPSecondaryAuthenticationFactorInfo_DEFINED__
#define __WSAIPSecondaryAuthenticationFactorInfo_DEFINED__

OBJCUWPWINDOWSSECURITYAUTHENTICATIONIDENTITYPROVIDEREXPORT
@interface WSAIPSecondaryAuthenticationFactorInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) RTObject<WSSIBuffer>* deviceConfigurationData;
@property (readonly) NSString * deviceFriendlyName;
@property (readonly) NSString * deviceId;
@property (readonly) NSString * deviceModelNumber;
@property (readonly) BOOL isAuthenticationSupported;
@property (readonly) WSAIPSecondaryAuthenticationFactorDevicePresenceMonitoringMode presenceMonitoringMode;
- (RTObject<WFIAsyncAction>*)updateDevicePresenceAsync:(WSAIPSecondaryAuthenticationFactorDevicePresence)presenceState;
@end

#endif // __WSAIPSecondaryAuthenticationFactorInfo_DEFINED__

// Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs
#ifndef __WSAIPSecondaryAuthenticationFactorAuthenticationStageChangedEventArgs_DEFINED__
#define __WSAIPSecondaryAuthenticationFactorAuthenticationStageChangedEventArgs_DEFINED__

OBJCUWPWINDOWSSECURITYAUTHENTICATIONIDENTITYPROVIDEREXPORT
@interface WSAIPSecondaryAuthenticationFactorAuthenticationStageChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSAIPSecondaryAuthenticationFactorAuthenticationStageInfo* stageInfo;
@end

#endif // __WSAIPSecondaryAuthenticationFactorAuthenticationStageChangedEventArgs_DEFINED__

// Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorAuthenticationStageInfo
#ifndef __WSAIPSecondaryAuthenticationFactorAuthenticationStageInfo_DEFINED__
#define __WSAIPSecondaryAuthenticationFactorAuthenticationStageInfo_DEFINED__

OBJCUWPWINDOWSSECURITYAUTHENTICATIONIDENTITYPROVIDEREXPORT
@interface WSAIPSecondaryAuthenticationFactorAuthenticationStageInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * deviceId;
@property (readonly) WSAIPSecondaryAuthenticationFactorAuthenticationScenario scenario;
@property (readonly) WSAIPSecondaryAuthenticationFactorAuthenticationStage stage;
@end

#endif // __WSAIPSecondaryAuthenticationFactorAuthenticationStageInfo_DEFINED__

