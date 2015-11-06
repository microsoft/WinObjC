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

// WindowsSecurityAuthenticationWebCore.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WSAWCWebTokenRequest, WSAWCWebAuthenticationCoreManager, WSAWCWebProviderError, WSAWCWebTokenResponse, WSAWCWebTokenRequestResult;
@protocol WSAWCIWebTokenRequest
, WSAWCIWebTokenRequestFactory, WSAWCIWebAuthenticationCoreManagerStatics, WSAWCIWebAuthenticationCoreManagerStatics2,
    WSAWCIWebProviderError, WSAWCIWebProviderErrorFactory, WSAWCIWebTokenRequestResult, WSAWCIWebTokenResponse,
    WSAWCIWebTokenResponseFactory;

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
#include "WindowsFoundationCollections.h"
#include "WindowsSecurityCredentials.h"
#include "WindowsSystem.h"

#import <Foundation/Foundation.h>

// Windows.Security.Authentication.Web.Core.WebTokenRequest
#ifndef __WSAWCWebTokenRequest_DEFINED__
#define __WSAWCWebTokenRequest_DEFINED__

WINRT_EXPORT
@interface WSAWCWebTokenRequest : RTObject
+ (WSAWCWebTokenRequest*)create:(WSCWebAccountProvider*)provider scope:(NSString*)scope clientId:(NSString*)clientId ACTIVATOR;
+ (WSAWCWebTokenRequest*)createWithPromptType:(WSCWebAccountProvider*)provider
                                        scope:(NSString*)scope
                                     clientId:(NSString*)clientId
                                   promptType:(WSAWCWebTokenRequestPromptType)promptType ACTIVATOR;
+ (WSAWCWebTokenRequest*)createWithProvider:(WSCWebAccountProvider*)provider ACTIVATOR;
+ (WSAWCWebTokenRequest*)createWithScope:(WSCWebAccountProvider*)provider scope:(NSString*)scope ACTIVATOR;
@property (readonly) NSString* clientId;
@property (readonly) WSAWCWebTokenRequestPromptType promptType;
@property (readonly) NSMutableDictionary* properties;
@property (readonly) NSString* scope;
@property (readonly) WSCWebAccountProvider* webAccountProvider;
@end

#endif // __WSAWCWebTokenRequest_DEFINED__

// Windows.Security.Authentication.Web.Core.WebAuthenticationCoreManager
#ifndef __WSAWCWebAuthenticationCoreManager_DEFINED__
#define __WSAWCWebAuthenticationCoreManager_DEFINED__

WINRT_EXPORT
@interface WSAWCWebAuthenticationCoreManager : RTObject
+ (void)getTokenSilentlyAsync:(WSAWCWebTokenRequest*)request
                      success:(void (^)(WSAWCWebTokenRequestResult*))success
                      failure:(void (^)(NSError*))failure;
+ (void)getTokenSilentlyWithWebAccountAsync:(WSAWCWebTokenRequest*)request
                                 webAccount:(WSCWebAccount*)webAccount
                                    success:(void (^)(WSAWCWebTokenRequestResult*))success
                                    failure:(void (^)(NSError*))failure;
+ (void)requestTokenAsync:(WSAWCWebTokenRequest*)request
                  success:(void (^)(WSAWCWebTokenRequestResult*))success
                  failure:(void (^)(NSError*))failure;
+ (void)requestTokenWithWebAccountAsync:(WSAWCWebTokenRequest*)request
                             webAccount:(WSCWebAccount*)webAccount
                                success:(void (^)(WSAWCWebTokenRequestResult*))success
                                failure:(void (^)(NSError*))failure;
+ (void)findAccountAsync:(WSCWebAccountProvider*)provider
            webAccountId:(NSString*)webAccountId
                 success:(void (^)(WSCWebAccount*))success
                 failure:(void (^)(NSError*))failure;
+ (void)findAccountProviderAsync:(NSString*)webAccountProviderId
                         success:(void (^)(WSCWebAccountProvider*))success
                         failure:(void (^)(NSError*))failure;
+ (void)findAccountProviderWithAuthorityAsync:(NSString*)webAccountProviderId
                                    authority:(NSString*)authority
                                      success:(void (^)(WSCWebAccountProvider*))success
                                      failure:(void (^)(NSError*))failure;
+ (void)findAccountProviderWithAuthorityForUserAsync:(NSString*)webAccountProviderId
                                           authority:(NSString*)authority
                                                user:(WSUser*)user
                                             success:(void (^)(WSCWebAccountProvider*))success
                                             failure:(void (^)(NSError*))failure;
+ (void)getTokenSilentlyAsync:(WSAWCWebTokenRequest*)request
                      success:(void (^)(WSAWCWebTokenRequestResult*))success
                      failure:(void (^)(NSError*))failure;
+ (void)getTokenSilentlyWithWebAccountAsync:(WSAWCWebTokenRequest*)request
                                 webAccount:(WSCWebAccount*)webAccount
                                    success:(void (^)(WSAWCWebTokenRequestResult*))success
                                    failure:(void (^)(NSError*))failure;
+ (void)requestTokenAsync:(WSAWCWebTokenRequest*)request
                  success:(void (^)(WSAWCWebTokenRequestResult*))success
                  failure:(void (^)(NSError*))failure;
+ (void)requestTokenWithWebAccountAsync:(WSAWCWebTokenRequest*)request
                             webAccount:(WSCWebAccount*)webAccount
                                success:(void (^)(WSAWCWebTokenRequestResult*))success
                                failure:(void (^)(NSError*))failure;
+ (void)findAccountAsync:(WSCWebAccountProvider*)provider
            webAccountId:(NSString*)webAccountId
                 success:(void (^)(WSCWebAccount*))success
                 failure:(void (^)(NSError*))failure;
+ (void)findAccountProviderAsync:(NSString*)webAccountProviderId
                         success:(void (^)(WSCWebAccountProvider*))success
                         failure:(void (^)(NSError*))failure;
+ (void)findAccountProviderWithAuthorityAsync:(NSString*)webAccountProviderId
                                    authority:(NSString*)authority
                                      success:(void (^)(WSCWebAccountProvider*))success
                                      failure:(void (^)(NSError*))failure;
@end

#endif // __WSAWCWebAuthenticationCoreManager_DEFINED__

// Windows.Security.Authentication.Web.Core.WebProviderError
#ifndef __WSAWCWebProviderError_DEFINED__
#define __WSAWCWebProviderError_DEFINED__

WINRT_EXPORT
@interface WSAWCWebProviderError : RTObject
+ (WSAWCWebProviderError*)create:(unsigned int)errorCode errorMessage:(NSString*)errorMessage ACTIVATOR;
@property (readonly) unsigned int errorCode;
@property (readonly) NSString* errorMessage;
@property (readonly) NSMutableDictionary* properties;
@end

#endif // __WSAWCWebProviderError_DEFINED__

// Windows.Security.Authentication.Web.Core.WebTokenResponse
#ifndef __WSAWCWebTokenResponse_DEFINED__
#define __WSAWCWebTokenResponse_DEFINED__

WINRT_EXPORT
@interface WSAWCWebTokenResponse : RTObject
+ (WSAWCWebTokenResponse*)createWithToken:(NSString*)token ACTIVATOR;
+ (WSAWCWebTokenResponse*)createWithTokenAndAccount:(NSString*)token webAccount:(WSCWebAccount*)webAccount ACTIVATOR;
+ (WSAWCWebTokenResponse*)createWithTokenAccountAndError:(NSString*)token
                                              webAccount:(WSCWebAccount*)webAccount
                                                   error:(WSAWCWebProviderError*)error ACTIVATOR;
+ (instancetype)create ACTIVATOR;
@property (readonly) NSMutableDictionary* properties;
@property (readonly) WSAWCWebProviderError* providerError;
@property (readonly) NSString* token;
@property (readonly) WSCWebAccount* webAccount;
@end

#endif // __WSAWCWebTokenResponse_DEFINED__

// Windows.Security.Authentication.Web.Core.WebTokenRequestResult
#ifndef __WSAWCWebTokenRequestResult_DEFINED__
#define __WSAWCWebTokenRequestResult_DEFINED__

WINRT_EXPORT
@interface WSAWCWebTokenRequestResult : RTObject
@property (readonly) NSArray* responseData;
@property (readonly) WSAWCWebProviderError* responseError;
@property (readonly) WSAWCWebTokenRequestStatus responseStatus;
- (RTObject<WFIAsyncAction>*)invalidateCacheAsync;
@end

#endif // __WSAWCWebTokenRequestResult_DEFINED__
