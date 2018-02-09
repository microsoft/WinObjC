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

// WindowsSecurityAuthenticationWebCore.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
#define OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsConsolidatedNamespace.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WSAWCWebTokenRequest, WSAWCWebAccountEventArgs, WSAWCWebAccountMonitor, WSAWCWebAuthenticationCoreManager, WSAWCWebProviderError, WSAWCWebTokenResponse, WSAWCWebTokenRequestResult;
@protocol WSAWCIWebTokenRequest, WSAWCIWebTokenRequest2, WSAWCIWebTokenRequest3, WSAWCIWebTokenRequestFactory, WSAWCIWebAccountEventArgs, WSAWCIWebAuthenticationCoreManagerStatics, WSAWCIWebAuthenticationCoreManagerStatics2, WSAWCIWebAuthenticationCoreManagerStatics3, WSAWCIWebAccountMonitor, WSAWCIWebProviderError, WSAWCIWebProviderErrorFactory, WSAWCIWebTokenRequestResult, WSAWCIWebTokenResponse, WSAWCIWebTokenResponseFactory;

// Windows.Security.Authentication.Web.Core.WebTokenRequestPromptType
enum _WSAWCWebTokenRequestPromptType {
    WSAWCWebTokenRequestPromptTypeDefault = 0,
    WSAWCWebTokenRequestPromptTypeForceAuthentication = 1,
};
typedef unsigned WSAWCWebTokenRequestPromptType;

// Windows.Security.Authentication.Web.Core.WebTokenRequestStatus
enum _WSAWCWebTokenRequestStatus {
    WSAWCWebTokenRequestStatusSuccess = 0,
    WSAWCWebTokenRequestStatusUserCancel = 1,
    WSAWCWebTokenRequestStatusAccountSwitch = 2,
    WSAWCWebTokenRequestStatusUserInteractionRequired = 3,
    WSAWCWebTokenRequestStatusAccountProviderNotAvailable = 4,
    WSAWCWebTokenRequestStatusProviderError = 5,
};
typedef unsigned WSAWCWebTokenRequestStatus;

#include "WindowsFoundation.h"
#include "WindowsSecurityCredentials.h"
#include "WindowsSystem.h"

#import <Foundation/Foundation.h>

// Windows.Security.Authentication.Web.Core.WebTokenRequest
#ifndef __WSAWCWebTokenRequest_DEFINED__
#define __WSAWCWebTokenRequest_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSAWCWebTokenRequest : RTObject
+ (WSAWCWebTokenRequest*)make:(WSCWebAccountProvider*)provider scope:(NSString *)scope clientId:(NSString *)clientId ACTIVATOR;
+ (WSAWCWebTokenRequest*)makeWithPromptType:(WSCWebAccountProvider*)provider scope:(NSString *)scope clientId:(NSString *)clientId promptType:(WSAWCWebTokenRequestPromptType)promptType ACTIVATOR;
+ (WSAWCWebTokenRequest*)makeWithProvider:(WSCWebAccountProvider*)provider ACTIVATOR;
+ (WSAWCWebTokenRequest*)makeWithScope:(WSCWebAccountProvider*)provider scope:(NSString *)scope ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * clientId;
@property (readonly) WSAWCWebTokenRequestPromptType promptType;
@property (readonly) NSMutableDictionary* /* NSString *, NSString * */ properties;
@property (readonly) NSString * scope;
@property (readonly) WSCWebAccountProvider* webAccountProvider;
@property (readonly) NSMutableDictionary* /* NSString *, NSString * */ appProperties;
@property (retain) NSString * correlationId;
@end

#endif // __WSAWCWebTokenRequest_DEFINED__

// Windows.Security.Authentication.Web.Core.WebAccountEventArgs
#ifndef __WSAWCWebAccountEventArgs_DEFINED__
#define __WSAWCWebAccountEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSAWCWebAccountEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSCWebAccount* account;
@end

#endif // __WSAWCWebAccountEventArgs_DEFINED__

// Windows.Security.Authentication.Web.Core.WebAccountMonitor
#ifndef __WSAWCWebAccountMonitor_DEFINED__
#define __WSAWCWebAccountMonitor_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSAWCWebAccountMonitor : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (EventRegistrationToken)addDefaultSignInAccountChangedEvent:(void(^)(WSAWCWebAccountMonitor*, RTObject*))del;
- (void)removeDefaultSignInAccountChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addRemovedEvent:(void(^)(WSAWCWebAccountMonitor*, WSAWCWebAccountEventArgs*))del;
- (void)removeRemovedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUpdatedEvent:(void(^)(WSAWCWebAccountMonitor*, WSAWCWebAccountEventArgs*))del;
- (void)removeUpdatedEvent:(EventRegistrationToken)tok;
@end

#endif // __WSAWCWebAccountMonitor_DEFINED__

// Windows.Security.Authentication.Web.Core.WebAuthenticationCoreManager
#ifndef __WSAWCWebAuthenticationCoreManager_DEFINED__
#define __WSAWCWebAuthenticationCoreManager_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSAWCWebAuthenticationCoreManager : RTObject
+ (void)getTokenSilentlyAsync:(WSAWCWebTokenRequest*)request success:(void (^)(WSAWCWebTokenRequestResult*))success failure:(void (^)(NSError*))failure;
+ (void)getTokenSilentlyWithWebAccountAsync:(WSAWCWebTokenRequest*)request webAccount:(WSCWebAccount*)webAccount success:(void (^)(WSAWCWebTokenRequestResult*))success failure:(void (^)(NSError*))failure;
+ (void)requestTokenAsync:(WSAWCWebTokenRequest*)request success:(void (^)(WSAWCWebTokenRequestResult*))success failure:(void (^)(NSError*))failure;
+ (void)requestTokenWithWebAccountAsync:(WSAWCWebTokenRequest*)request webAccount:(WSCWebAccount*)webAccount success:(void (^)(WSAWCWebTokenRequestResult*))success failure:(void (^)(NSError*))failure;
+ (void)findAccountAsync:(WSCWebAccountProvider*)provider webAccountId:(NSString *)webAccountId success:(void (^)(WSCWebAccount*))success failure:(void (^)(NSError*))failure;
+ (void)findAccountProviderAsync:(NSString *)webAccountProviderId success:(void (^)(WSCWebAccountProvider*))success failure:(void (^)(NSError*))failure;
+ (void)findAccountProviderWithAuthorityAsync:(NSString *)webAccountProviderId authority:(NSString *)authority success:(void (^)(WSCWebAccountProvider*))success failure:(void (^)(NSError*))failure;
+ (WSAWCWebAccountMonitor*)createWebAccountMonitor:(id<NSFastEnumeration> /* WSCWebAccount* */)webAccounts;
+ (void)getTokenSilentlyAsync:(WSAWCWebTokenRequest*)request success:(void (^)(WSAWCWebTokenRequestResult*))success failure:(void (^)(NSError*))failure;
+ (void)getTokenSilentlyWithWebAccountAsync:(WSAWCWebTokenRequest*)request webAccount:(WSCWebAccount*)webAccount success:(void (^)(WSAWCWebTokenRequestResult*))success failure:(void (^)(NSError*))failure;
+ (void)requestTokenAsync:(WSAWCWebTokenRequest*)request success:(void (^)(WSAWCWebTokenRequestResult*))success failure:(void (^)(NSError*))failure;
+ (void)requestTokenWithWebAccountAsync:(WSAWCWebTokenRequest*)request webAccount:(WSCWebAccount*)webAccount success:(void (^)(WSAWCWebTokenRequestResult*))success failure:(void (^)(NSError*))failure;
+ (void)findAccountAsync:(WSCWebAccountProvider*)provider webAccountId:(NSString *)webAccountId success:(void (^)(WSCWebAccount*))success failure:(void (^)(NSError*))failure;
+ (void)findAccountProviderAsync:(NSString *)webAccountProviderId success:(void (^)(WSCWebAccountProvider*))success failure:(void (^)(NSError*))failure;
+ (void)findAccountProviderWithAuthorityAsync:(NSString *)webAccountProviderId authority:(NSString *)authority success:(void (^)(WSCWebAccountProvider*))success failure:(void (^)(NSError*))failure;
+ (void)findAccountProviderWithAuthorityForUserAsync:(NSString *)webAccountProviderId authority:(NSString *)authority user:(WSUser*)user success:(void (^)(WSCWebAccountProvider*))success failure:(void (^)(NSError*))failure;
+ (void)getTokenSilentlyAsync:(WSAWCWebTokenRequest*)request success:(void (^)(WSAWCWebTokenRequestResult*))success failure:(void (^)(NSError*))failure;
+ (void)getTokenSilentlyWithWebAccountAsync:(WSAWCWebTokenRequest*)request webAccount:(WSCWebAccount*)webAccount success:(void (^)(WSAWCWebTokenRequestResult*))success failure:(void (^)(NSError*))failure;
+ (void)requestTokenAsync:(WSAWCWebTokenRequest*)request success:(void (^)(WSAWCWebTokenRequestResult*))success failure:(void (^)(NSError*))failure;
+ (void)requestTokenWithWebAccountAsync:(WSAWCWebTokenRequest*)request webAccount:(WSCWebAccount*)webAccount success:(void (^)(WSAWCWebTokenRequestResult*))success failure:(void (^)(NSError*))failure;
+ (void)findAccountAsync:(WSCWebAccountProvider*)provider webAccountId:(NSString *)webAccountId success:(void (^)(WSCWebAccount*))success failure:(void (^)(NSError*))failure;
+ (void)findAccountProviderAsync:(NSString *)webAccountProviderId success:(void (^)(WSCWebAccountProvider*))success failure:(void (^)(NSError*))failure;
+ (void)findAccountProviderWithAuthorityAsync:(NSString *)webAccountProviderId authority:(NSString *)authority success:(void (^)(WSCWebAccountProvider*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSAWCWebAuthenticationCoreManager_DEFINED__

// Windows.Security.Authentication.Web.Core.WebProviderError
#ifndef __WSAWCWebProviderError_DEFINED__
#define __WSAWCWebProviderError_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSAWCWebProviderError : RTObject
+ (WSAWCWebProviderError*)make:(unsigned int)errorCode errorMessage:(NSString *)errorMessage ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int errorCode;
@property (readonly) NSString * errorMessage;
@property (readonly) NSMutableDictionary* /* NSString *, NSString * */ properties;
@end

#endif // __WSAWCWebProviderError_DEFINED__

// Windows.Security.Authentication.Web.Core.WebTokenResponse
#ifndef __WSAWCWebTokenResponse_DEFINED__
#define __WSAWCWebTokenResponse_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSAWCWebTokenResponse : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
+ (WSAWCWebTokenResponse*)makeWithToken:(NSString *)token ACTIVATOR;
+ (WSAWCWebTokenResponse*)makeWithTokenAndAccount:(NSString *)token webAccount:(WSCWebAccount*)webAccount ACTIVATOR;
+ (WSAWCWebTokenResponse*)makeWithTokenAccountAndError:(NSString *)token webAccount:(WSCWebAccount*)webAccount error:(WSAWCWebProviderError*)error ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSMutableDictionary* /* NSString *, NSString * */ properties;
@property (readonly) WSAWCWebProviderError* providerError;
@property (readonly) NSString * token;
@property (readonly) WSCWebAccount* webAccount;
@end

#endif // __WSAWCWebTokenResponse_DEFINED__

// Windows.Security.Authentication.Web.Core.WebTokenRequestResult
#ifndef __WSAWCWebTokenRequestResult_DEFINED__
#define __WSAWCWebTokenRequestResult_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WSAWCWebTokenRequestResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WSAWCWebTokenResponse* */ responseData;
@property (readonly) WSAWCWebProviderError* responseError;
@property (readonly) WSAWCWebTokenRequestStatus responseStatus;
- (RTObject<WFIAsyncAction>*)invalidateCacheAsync;
@end

#endif // __WSAWCWebTokenRequestResult_DEFINED__

