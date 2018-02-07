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

// WindowsSecurityAuthenticationIdentityCore.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSSECURITYAUTHENTICATIONIDENTITYCOREEXPORT
#define OBJCUWPWINDOWSSECURITYAUTHENTICATIONIDENTITYCOREEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsSecurityAuthenticationIdentityCore.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WSAICMicrosoftAccountMultiFactorSessionInfo, WSAICMicrosoftAccountMultiFactorOneTimeCodedInfo, WSAICMicrosoftAccountMultiFactorGetSessionsResult, WSAICMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo, WSAICMicrosoftAccountMultiFactorAuthenticationManager;
@protocol WSAICIMicrosoftAccountMultiFactorSessionInfo, WSAICIMicrosoftAccountMultiFactorGetSessionsResult, WSAICIMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo, WSAICIMicrosoftAccountMultiFactorOneTimeCodedInfo, WSAICIMicrosoftAccountMultiFactorAuthenticationManager, WSAICIMicrosoftAccountMultiFactorAuthenticatorStatics;

// Windows.Security.Authentication.Identity.Core.MicrosoftAccountMultiFactorServiceResponse
enum _WSAICMicrosoftAccountMultiFactorServiceResponse {
    WSAICMicrosoftAccountMultiFactorServiceResponseSuccess = 0,
    WSAICMicrosoftAccountMultiFactorServiceResponseError = 1,
    WSAICMicrosoftAccountMultiFactorServiceResponseNoNetworkConnection = 2,
    WSAICMicrosoftAccountMultiFactorServiceResponseServiceUnavailable = 3,
    WSAICMicrosoftAccountMultiFactorServiceResponseTotpSetupDenied = 4,
    WSAICMicrosoftAccountMultiFactorServiceResponseNgcNotSetup = 5,
    WSAICMicrosoftAccountMultiFactorServiceResponseSessionAlreadyDenied = 6,
    WSAICMicrosoftAccountMultiFactorServiceResponseSessionAlreadyApproved = 7,
    WSAICMicrosoftAccountMultiFactorServiceResponseSessionExpired = 8,
    WSAICMicrosoftAccountMultiFactorServiceResponseNgcNonceExpired = 9,
    WSAICMicrosoftAccountMultiFactorServiceResponseInvalidSessionId = 10,
    WSAICMicrosoftAccountMultiFactorServiceResponseInvalidSessionType = 11,
    WSAICMicrosoftAccountMultiFactorServiceResponseInvalidOperation = 12,
    WSAICMicrosoftAccountMultiFactorServiceResponseInvalidStateTransition = 13,
    WSAICMicrosoftAccountMultiFactorServiceResponseDeviceNotFound = 14,
    WSAICMicrosoftAccountMultiFactorServiceResponseFlowDisabled = 15,
    WSAICMicrosoftAccountMultiFactorServiceResponseSessionNotApproved = 16,
    WSAICMicrosoftAccountMultiFactorServiceResponseOperationCanceledByUser = 17,
    WSAICMicrosoftAccountMultiFactorServiceResponseNgcDisabledByServer = 18,
    WSAICMicrosoftAccountMultiFactorServiceResponseNgcKeyNotFoundOnServer = 19,
    WSAICMicrosoftAccountMultiFactorServiceResponseUIRequired = 20,
    WSAICMicrosoftAccountMultiFactorServiceResponseDeviceIdChanged = 21,
};
typedef unsigned WSAICMicrosoftAccountMultiFactorServiceResponse;

// Windows.Security.Authentication.Identity.Core.MicrosoftAccountMultiFactorSessionAuthenticationStatus
enum _WSAICMicrosoftAccountMultiFactorSessionAuthenticationStatus {
    WSAICMicrosoftAccountMultiFactorSessionAuthenticationStatusAuthenticated = 0,
    WSAICMicrosoftAccountMultiFactorSessionAuthenticationStatusUnauthenticated = 1,
};
typedef unsigned WSAICMicrosoftAccountMultiFactorSessionAuthenticationStatus;

// Windows.Security.Authentication.Identity.Core.MicrosoftAccountMultiFactorAuthenticationType
enum _WSAICMicrosoftAccountMultiFactorAuthenticationType {
    WSAICMicrosoftAccountMultiFactorAuthenticationTypeUser = 0,
    WSAICMicrosoftAccountMultiFactorAuthenticationTypeDevice = 1,
};
typedef unsigned WSAICMicrosoftAccountMultiFactorAuthenticationType;

// Windows.Security.Authentication.Identity.Core.MicrosoftAccountMultiFactorSessionApprovalStatus
enum _WSAICMicrosoftAccountMultiFactorSessionApprovalStatus {
    WSAICMicrosoftAccountMultiFactorSessionApprovalStatusPending = 0,
    WSAICMicrosoftAccountMultiFactorSessionApprovalStatusApproved = 1,
    WSAICMicrosoftAccountMultiFactorSessionApprovalStatusDenied = 2,
};
typedef unsigned WSAICMicrosoftAccountMultiFactorSessionApprovalStatus;

#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Security.Authentication.Identity.Core.MicrosoftAccountMultiFactorSessionInfo
#ifndef __WSAICMicrosoftAccountMultiFactorSessionInfo_DEFINED__
#define __WSAICMicrosoftAccountMultiFactorSessionInfo_DEFINED__

OBJCUWPWINDOWSSECURITYAUTHENTICATIONIDENTITYCOREEXPORT
@interface WSAICMicrosoftAccountMultiFactorSessionInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSAICMicrosoftAccountMultiFactorSessionApprovalStatus approvalStatus;
@property (readonly) WSAICMicrosoftAccountMultiFactorAuthenticationType authenticationType;
@property (readonly) NSString * displaySessionId;
@property (readonly) WFDateTime* expirationTime;
@property (readonly) WFDateTime* requestTime;
@property (readonly) NSString * sessionId;
@property (readonly) NSString * userAccountId;
@end

#endif // __WSAICMicrosoftAccountMultiFactorSessionInfo_DEFINED__

// Windows.Security.Authentication.Identity.Core.MicrosoftAccountMultiFactorOneTimeCodedInfo
#ifndef __WSAICMicrosoftAccountMultiFactorOneTimeCodedInfo_DEFINED__
#define __WSAICMicrosoftAccountMultiFactorOneTimeCodedInfo_DEFINED__

OBJCUWPWINDOWSSECURITYAUTHENTICATIONIDENTITYCOREEXPORT
@interface WSAICMicrosoftAccountMultiFactorOneTimeCodedInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * code;
@property (readonly) WSAICMicrosoftAccountMultiFactorServiceResponse serviceResponse;
@property (readonly) WFTimeSpan* timeInterval;
@property (readonly) WFTimeSpan* timeToLive;
@end

#endif // __WSAICMicrosoftAccountMultiFactorOneTimeCodedInfo_DEFINED__

// Windows.Security.Authentication.Identity.Core.MicrosoftAccountMultiFactorGetSessionsResult
#ifndef __WSAICMicrosoftAccountMultiFactorGetSessionsResult_DEFINED__
#define __WSAICMicrosoftAccountMultiFactorGetSessionsResult_DEFINED__

OBJCUWPWINDOWSSECURITYAUTHENTICATIONIDENTITYCOREEXPORT
@interface WSAICMicrosoftAccountMultiFactorGetSessionsResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSAICMicrosoftAccountMultiFactorServiceResponse serviceResponse;
@property (readonly) NSArray* /* WSAICMicrosoftAccountMultiFactorSessionInfo* */ sessions;
@end

#endif // __WSAICMicrosoftAccountMultiFactorGetSessionsResult_DEFINED__

// Windows.Security.Authentication.Identity.Core.MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo
#ifndef __WSAICMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo_DEFINED__
#define __WSAICMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo_DEFINED__

OBJCUWPWINDOWSSECURITYAUTHENTICATIONIDENTITYCOREEXPORT
@interface WSAICMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSAICMicrosoftAccountMultiFactorServiceResponse serviceResponse;
@property (readonly) NSArray* /* WSAICMicrosoftAccountMultiFactorSessionInfo* */ sessions;
@property (readonly) NSArray* /* NSString * */ unregisteredAccounts;
@end

#endif // __WSAICMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo_DEFINED__

// Windows.Security.Authentication.Identity.Core.MicrosoftAccountMultiFactorAuthenticationManager
#ifndef __WSAICMicrosoftAccountMultiFactorAuthenticationManager_DEFINED__
#define __WSAICMicrosoftAccountMultiFactorAuthenticationManager_DEFINED__

OBJCUWPWINDOWSSECURITYAUTHENTICATIONIDENTITYCOREEXPORT
@interface WSAICMicrosoftAccountMultiFactorAuthenticationManager : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
+ (WSAICMicrosoftAccountMultiFactorAuthenticationManager*)current;
- (void)getOneTimePassCodeAsync:(NSString *)userAccountId codeLength:(unsigned int)codeLength success:(void (^)(WSAICMicrosoftAccountMultiFactorOneTimeCodedInfo*))success failure:(void (^)(NSError*))failure;
- (void)addDeviceAsync:(NSString *)userAccountId authenticationToken:(NSString *)authenticationToken wnsChannelId:(NSString *)wnsChannelId success:(void (^)(WSAICMicrosoftAccountMultiFactorServiceResponse))success failure:(void (^)(NSError*))failure;
- (void)removeDeviceAsync:(NSString *)userAccountId success:(void (^)(WSAICMicrosoftAccountMultiFactorServiceResponse))success failure:(void (^)(NSError*))failure;
- (void)updateWnsChannelAsync:(NSString *)userAccountId channelUri:(NSString *)channelUri success:(void (^)(WSAICMicrosoftAccountMultiFactorServiceResponse))success failure:(void (^)(NSError*))failure;
- (void)getSessionsAsync:(id<NSFastEnumeration> /* NSString * */)userAccountIdList success:(void (^)(WSAICMicrosoftAccountMultiFactorGetSessionsResult*))success failure:(void (^)(NSError*))failure;
- (void)getSessionsAndUnregisteredAccountsAsync:(id<NSFastEnumeration> /* NSString * */)userAccountIdList success:(void (^)(WSAICMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo*))success failure:(void (^)(NSError*))failure;
- (void)approveSessionUsingAuthSessionInfoAsync:(WSAICMicrosoftAccountMultiFactorSessionAuthenticationStatus)sessionAuthentictionStatus authenticationSessionInfo:(WSAICMicrosoftAccountMultiFactorSessionInfo*)authenticationSessionInfo success:(void (^)(WSAICMicrosoftAccountMultiFactorServiceResponse))success failure:(void (^)(NSError*))failure;
- (void)approveSessionAsync:(WSAICMicrosoftAccountMultiFactorSessionAuthenticationStatus)sessionAuthentictionStatus userAccountId:(NSString *)userAccountId sessionId:(NSString *)sessionId sessionAuthenticationType:(WSAICMicrosoftAccountMultiFactorAuthenticationType)sessionAuthenticationType success:(void (^)(WSAICMicrosoftAccountMultiFactorServiceResponse))success failure:(void (^)(NSError*))failure;
- (void)denySessionUsingAuthSessionInfoAsync:(WSAICMicrosoftAccountMultiFactorSessionInfo*)authenticationSessionInfo success:(void (^)(WSAICMicrosoftAccountMultiFactorServiceResponse))success failure:(void (^)(NSError*))failure;
- (void)denySessionAsync:(NSString *)userAccountId sessionId:(NSString *)sessionId sessionAuthenticationType:(WSAICMicrosoftAccountMultiFactorAuthenticationType)sessionAuthenticationType success:(void (^)(WSAICMicrosoftAccountMultiFactorServiceResponse))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSAICMicrosoftAccountMultiFactorAuthenticationManager_DEFINED__

