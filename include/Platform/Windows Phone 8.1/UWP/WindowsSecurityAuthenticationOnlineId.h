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

// WindowsSecurityAuthenticationOnlineId.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WSAOOnlineIdServiceTicketRequest, WSAOOnlineIdServiceTicket, WSAOUserAuthenticationOperation, WSAOSignOutUserOperation,
    WSAOUserIdentity, WSAOOnlineIdAuthenticator;
@protocol WSAOIOnlineIdServiceTicketRequest
, WSAOIOnlineIdServiceTicketRequestFactory, WSAOIOnlineIdServiceTicket, WSAOIUserIdentity, WSAOIOnlineIdAuthenticator;

// Windows.Security.Authentication.OnlineId.CredentialPromptType
enum _WSAOCredentialPromptType {
    WSAOCredentialPromptTypePromptIfNeeded = 0,
    WSAOCredentialPromptTypeRetypeCredentials = 1,
    WSAOCredentialPromptTypeDoNotPrompt = 2,
};
typedef unsigned WSAOCredentialPromptType;

#include "WindowsFoundationCollections.h"
#include "WindowsFoundation.h"
// Windows.Foundation.AsyncActionCompletedHandler
#ifndef __WFAsyncActionCompletedHandler__DEFINED
#define __WFAsyncActionCompletedHandler__DEFINED
typedef void (^WFAsyncActionCompletedHandler)(RTObject<WFIAsyncAction>* asyncInfo, WFAsyncStatus asyncStatus);
#endif // __WFAsyncActionCompletedHandler__DEFINED

// Windows.Security.Authentication.OnlineId.OnlineIdServiceTicketRequest
#ifndef __WSAOOnlineIdServiceTicketRequest_DEFINED__
#define __WSAOOnlineIdServiceTicketRequest_DEFINED__

WINRT_EXPORT
@interface WSAOOnlineIdServiceTicketRequest : RTObject
+ (WSAOOnlineIdServiceTicketRequest*)createOnlineIdServiceTicketRequest:(NSString*)service policy:(NSString*)policy ACTIVATOR;
+ (WSAOOnlineIdServiceTicketRequest*)createOnlineIdServiceTicketRequestAdvanced:(NSString*)service ACTIVATOR;
@property (readonly) NSString* policy;
@property (readonly) NSString* service;
@end

#endif // __WSAOOnlineIdServiceTicketRequest_DEFINED__

// Windows.Security.Authentication.OnlineId.OnlineIdServiceTicket
#ifndef __WSAOOnlineIdServiceTicket_DEFINED__
#define __WSAOOnlineIdServiceTicket_DEFINED__

WINRT_EXPORT
@interface WSAOOnlineIdServiceTicket : RTObject
@property (readonly) int errorCode;
@property (readonly) WSAOOnlineIdServiceTicketRequest* request;
@property (readonly) NSString* value;
@end

#endif // __WSAOOnlineIdServiceTicket_DEFINED__

// Windows.Foundation.IAsyncInfo
#ifndef __WFIAsyncInfo_DEFINED__
#define __WFIAsyncInfo_DEFINED__

@protocol WFIAsyncInfo
@property (readonly) HRESULT errorCode;
@property (readonly) unsigned id;
@property (readonly) WFAsyncStatus status;
- (void)cancel;
- (void)close;
@end

#endif // __WFIAsyncInfo_DEFINED__

// Windows.Security.Authentication.OnlineId.UserAuthenticationOperation
#ifndef __WSAOUserAuthenticationOperation_DEFINED__
#define __WSAOUserAuthenticationOperation_DEFINED__

WINRT_EXPORT
@interface WSAOUserAuthenticationOperation : RTObject <WFIAsyncInfo>
@property (readonly) HRESULT errorCode;
@property (readonly) unsigned id;
@property (readonly) WFAsyncStatus status;
// Failed to generate property Completed (Can't marshal
// Windows.Foundation.AsyncOperationCompletedHandler`1<Windows.Security.Authentication.OnlineId.UserIdentity>)
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

#endif // __WFIAsyncAction_DEFINED__

// Windows.Security.Authentication.OnlineId.SignOutUserOperation
#ifndef __WSAOSignOutUserOperation_DEFINED__
#define __WSAOSignOutUserOperation_DEFINED__

WINRT_EXPORT
@interface WSAOSignOutUserOperation : RTObject <WFIAsyncAction, WFIAsyncInfo>
@property (copy) WFAsyncActionCompletedHandler completed;
@property (readonly) HRESULT errorCode;
@property (readonly) unsigned id;
@property (readonly) WFAsyncStatus status;
- (void)getResults;
- (void)cancel;
- (void)close;
@end

#endif // __WSAOSignOutUserOperation_DEFINED__

// Windows.Security.Authentication.OnlineId.UserIdentity
#ifndef __WSAOUserIdentity_DEFINED__
#define __WSAOUserIdentity_DEFINED__

WINRT_EXPORT
@interface WSAOUserIdentity : RTObject
@property (readonly) NSString* firstName;
@property (readonly) NSString* id;
@property (readonly) BOOL isBetaAccount;
@property (readonly) BOOL isConfirmedPC;
@property (readonly) NSString* lastName;
@property (readonly) NSString* safeCustomerId;
@property (readonly) NSString* signInName;
@property (readonly) id<NSFastEnumeration> /*WSAOOnlineIdServiceTicket*/ tickets;
@end

#endif // __WSAOUserIdentity_DEFINED__

// Windows.Security.Authentication.OnlineId.OnlineIdAuthenticator
#ifndef __WSAOOnlineIdAuthenticator_DEFINED__
#define __WSAOOnlineIdAuthenticator_DEFINED__

WINRT_EXPORT
@interface WSAOOnlineIdAuthenticator : RTObject
+ (instancetype)create ACTIVATOR;
@property WFGUID* applicationId;
@property (readonly) NSString* authenticatedSafeCustomerId;
@property (readonly) BOOL canSignOut;
- (WSAOUserAuthenticationOperation*)authenticateUserAsync:(WSAOOnlineIdServiceTicketRequest*)request;
- (WSAOUserAuthenticationOperation*)authenticateUserAsyncAdvanced:(id<NSFastEnumeration> /*WSAOOnlineIdServiceTicketRequest*/)requests
                                             credentialPromptType:(WSAOCredentialPromptType)credentialPromptType;
- (WSAOSignOutUserOperation*)signOutUserAsync;
@end

#endif // __WSAOOnlineIdAuthenticator_DEFINED__
