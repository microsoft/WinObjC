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

// WindowsSecurityAuthenticationOnlineId.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSSECURITYAUTHENTICATIONONLINEIDEXPORT
#define OBJCUWPWINDOWSSECURITYAUTHENTICATIONONLINEIDEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsSecurityAuthenticationOnlineId.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WSAOOnlineIdServiceTicketRequest, WSAOOnlineIdServiceTicket, WSAOUserAuthenticationOperation, WSAOSignOutUserOperation, WSAOUserIdentity, WSAOOnlineIdAuthenticator, WSAOOnlineIdSystemIdentity, WSAOOnlineIdSystemTicketResult, WSAOOnlineIdSystemAuthenticatorForUser, WSAOOnlineIdSystemAuthenticator;
@protocol WSAOIOnlineIdServiceTicketRequest, WSAOIOnlineIdServiceTicketRequestFactory, WSAOIOnlineIdServiceTicket, WSAOIUserIdentity, WSAOIOnlineIdAuthenticator, WSAOIOnlineIdSystemIdentity, WSAOIOnlineIdSystemTicketResult, WSAOIOnlineIdSystemAuthenticatorForUser, WSAOIOnlineIdSystemAuthenticatorStatics;

// Windows.Security.Authentication.OnlineId.CredentialPromptType
enum _WSAOCredentialPromptType {
    WSAOCredentialPromptTypePromptIfNeeded = 0,
    WSAOCredentialPromptTypeRetypeCredentials = 1,
    WSAOCredentialPromptTypeDoNotPrompt = 2,
};
typedef unsigned WSAOCredentialPromptType;

// Windows.Security.Authentication.OnlineId.OnlineIdSystemTicketStatus
enum _WSAOOnlineIdSystemTicketStatus {
    WSAOOnlineIdSystemTicketStatusSuccess = 0,
    WSAOOnlineIdSystemTicketStatusError = 1,
    WSAOOnlineIdSystemTicketStatusServiceConnectionError = 2,
};
typedef unsigned WSAOOnlineIdSystemTicketStatus;

#include "WindowsFoundation.h"
#include "WindowsSystem.h"
// Windows.Foundation.AsyncActionCompletedHandler
#ifndef __WFAsyncActionCompletedHandler__DEFINED
#define __WFAsyncActionCompletedHandler__DEFINED
typedef void(^WFAsyncActionCompletedHandler)(RTObject<WFIAsyncAction>* asyncInfo, WFAsyncStatus asyncStatus);
#endif // __WFAsyncActionCompletedHandler__DEFINED


#import <Foundation/Foundation.h>

// Windows.Security.Authentication.OnlineId.OnlineIdServiceTicketRequest
#ifndef __WSAOOnlineIdServiceTicketRequest_DEFINED__
#define __WSAOOnlineIdServiceTicketRequest_DEFINED__

OBJCUWPWINDOWSSECURITYAUTHENTICATIONONLINEIDEXPORT
@interface WSAOOnlineIdServiceTicketRequest : RTObject
+ (WSAOOnlineIdServiceTicketRequest*)makeOnlineIdServiceTicketRequest:(NSString *)service policy:(NSString *)policy ACTIVATOR;
+ (WSAOOnlineIdServiceTicketRequest*)makeOnlineIdServiceTicketRequestAdvanced:(NSString *)service ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * policy;
@property (readonly) NSString * service;
@end

#endif // __WSAOOnlineIdServiceTicketRequest_DEFINED__

// Windows.Security.Authentication.OnlineId.OnlineIdServiceTicket
#ifndef __WSAOOnlineIdServiceTicket_DEFINED__
#define __WSAOOnlineIdServiceTicket_DEFINED__

OBJCUWPWINDOWSSECURITYAUTHENTICATIONONLINEIDEXPORT
@interface WSAOOnlineIdServiceTicket : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) int errorCode;
@property (readonly) WSAOOnlineIdServiceTicketRequest* request;
@property (readonly) NSString * value;
@end

#endif // __WSAOOnlineIdServiceTicket_DEFINED__

// Windows.Foundation.IAsyncInfo
#ifndef __WFIAsyncInfo_DEFINED__
#define __WFIAsyncInfo_DEFINED__

@protocol WFIAsyncInfo
@property (readonly) HRESULT errorCode;
@property (readonly) unsigned int id;
@property (readonly) WFAsyncStatus status;
- (void)cancel;
- (void)close;
@end

OBJCUWPWINDOWSSECURITYAUTHENTICATIONONLINEIDEXPORT
@interface WFIAsyncInfo : RTObject <WFIAsyncInfo>
@end

#endif // __WFIAsyncInfo_DEFINED__

// Windows.Security.Authentication.OnlineId.UserAuthenticationOperation
#ifndef __WSAOUserAuthenticationOperation_DEFINED__
#define __WSAOUserAuthenticationOperation_DEFINED__

OBJCUWPWINDOWSSECURITYAUTHENTICATIONONLINEIDEXPORT
@interface WSAOUserAuthenticationOperation : RTObject <WFIAsyncInfo>
 // Failed to get type for default interface: Can't marshal Windows.Foundation.IAsyncOperation`1<Windows.Security.Authentication.OnlineId.UserIdentity>
@property (readonly) HRESULT errorCode;
@property (readonly) unsigned int id;
@property (readonly) WFAsyncStatus status;
// Failed to generate property Completed (Can't marshal Windows.Foundation.AsyncOperationCompletedHandler`1<Windows.Security.Authentication.OnlineId.UserIdentity>)
// Could not find base class Windows.Foundation.IAsyncOperation`1<Windows.Security.Authentication.OnlineId.UserIdentity> type information
- (void)cancel;
- (void)close;
@end

#endif // __WSAOUserAuthenticationOperation_DEFINED__

// Windows.Foundation.IAsyncAction
#ifndef __WFIAsyncAction_DEFINED__
#define __WFIAsyncAction_DEFINED__

@protocol WFIAsyncAction <WFIAsyncInfo>
@property (copy) WFAsyncActionCompletedHandler completed;
- (void)getResults;
- (void)cancel;
- (void)close;
@end

OBJCUWPWINDOWSSECURITYAUTHENTICATIONONLINEIDEXPORT
@interface WFIAsyncAction : RTObject <WFIAsyncAction>
@end

#endif // __WFIAsyncAction_DEFINED__

// Windows.Security.Authentication.OnlineId.SignOutUserOperation
#ifndef __WSAOSignOutUserOperation_DEFINED__
#define __WSAOSignOutUserOperation_DEFINED__

OBJCUWPWINDOWSSECURITYAUTHENTICATIONONLINEIDEXPORT
@interface WSAOSignOutUserOperation : RTObject <WFIAsyncAction, WFIAsyncInfo>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) HRESULT errorCode;
@property (readonly) unsigned int id;
@property (readonly) WFAsyncStatus status;
@property (copy) WFAsyncActionCompletedHandler completed;
- (void)getResults;
- (void)cancel;
- (void)close;
@end

#endif // __WSAOSignOutUserOperation_DEFINED__

// Windows.Security.Authentication.OnlineId.UserIdentity
#ifndef __WSAOUserIdentity_DEFINED__
#define __WSAOUserIdentity_DEFINED__

OBJCUWPWINDOWSSECURITYAUTHENTICATIONONLINEIDEXPORT
@interface WSAOUserIdentity : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * firstName;
@property (readonly) NSString * id;
@property (readonly) BOOL isBetaAccount;
@property (readonly) BOOL isConfirmedPC;
@property (readonly) NSString * lastName;
@property (readonly) NSString * safeCustomerId;
@property (readonly) NSString * signInName;
@property (readonly) NSArray* /* WSAOOnlineIdServiceTicket* */ tickets;
@end

#endif // __WSAOUserIdentity_DEFINED__

// Windows.Security.Authentication.OnlineId.OnlineIdAuthenticator
#ifndef __WSAOOnlineIdAuthenticator_DEFINED__
#define __WSAOOnlineIdAuthenticator_DEFINED__

OBJCUWPWINDOWSSECURITYAUTHENTICATIONONLINEIDEXPORT
@interface WSAOOnlineIdAuthenticator : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WFGUID* applicationId;
@property (readonly) NSString * authenticatedSafeCustomerId;
@property (readonly) BOOL canSignOut;
// Failed to generate member AuthenticateUserAsync (Can't marshal Windows.Foundation.IAsyncOperation`1<Windows.Security.Authentication.OnlineId.UserIdentity>)
// Failed to generate member AuthenticateUserAsync (Can't marshal Windows.Foundation.IAsyncOperation`1<Windows.Security.Authentication.OnlineId.UserIdentity>)
- (WSAOSignOutUserOperation*)signOutUserAsync;
@end

#endif // __WSAOOnlineIdAuthenticator_DEFINED__

// Windows.Security.Authentication.OnlineId.OnlineIdSystemIdentity
#ifndef __WSAOOnlineIdSystemIdentity_DEFINED__
#define __WSAOOnlineIdSystemIdentity_DEFINED__

OBJCUWPWINDOWSSECURITYAUTHENTICATIONONLINEIDEXPORT
@interface WSAOOnlineIdSystemIdentity : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * id;
@property (readonly) WSAOOnlineIdServiceTicket* ticket;
@end

#endif // __WSAOOnlineIdSystemIdentity_DEFINED__

// Windows.Security.Authentication.OnlineId.OnlineIdSystemTicketResult
#ifndef __WSAOOnlineIdSystemTicketResult_DEFINED__
#define __WSAOOnlineIdSystemTicketResult_DEFINED__

OBJCUWPWINDOWSSECURITYAUTHENTICATIONONLINEIDEXPORT
@interface WSAOOnlineIdSystemTicketResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) HRESULT extendedError;
@property (readonly) WSAOOnlineIdSystemIdentity* identity;
@property (readonly) WSAOOnlineIdSystemTicketStatus status;
@end

#endif // __WSAOOnlineIdSystemTicketResult_DEFINED__

// Windows.Security.Authentication.OnlineId.OnlineIdSystemAuthenticatorForUser
#ifndef __WSAOOnlineIdSystemAuthenticatorForUser_DEFINED__
#define __WSAOOnlineIdSystemAuthenticatorForUser_DEFINED__

OBJCUWPWINDOWSSECURITYAUTHENTICATIONONLINEIDEXPORT
@interface WSAOOnlineIdSystemAuthenticatorForUser : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WFGUID* applicationId;
@property (readonly) WSUser* user;
- (void)getTicketAsync:(WSAOOnlineIdServiceTicketRequest*)request success:(void (^)(WSAOOnlineIdSystemTicketResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSAOOnlineIdSystemAuthenticatorForUser_DEFINED__

// Windows.Security.Authentication.OnlineId.OnlineIdSystemAuthenticator
#ifndef __WSAOOnlineIdSystemAuthenticator_DEFINED__
#define __WSAOOnlineIdSystemAuthenticator_DEFINED__

OBJCUWPWINDOWSSECURITYAUTHENTICATIONONLINEIDEXPORT
@interface WSAOOnlineIdSystemAuthenticator : RTObject
+ (WSAOOnlineIdSystemAuthenticatorForUser*)getForUser:(WSUser*)user;
+ (WSAOOnlineIdSystemAuthenticatorForUser*)Default;
@end

#endif // __WSAOOnlineIdSystemAuthenticator_DEFINED__

