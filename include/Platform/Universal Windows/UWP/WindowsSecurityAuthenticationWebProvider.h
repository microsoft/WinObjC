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

// WindowsSecurityAuthenticationWebProvider.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WSAWPWebProviderTokenRequest, WSAWPWebProviderTokenResponse, WSAWPWebAccountClientView, WSAWPWebAccountManager,
    WSAWPWebAccountProviderRequestTokenOperation, WSAWPWebAccountProviderGetTokenSilentOperation,
    WSAWPWebAccountProviderAddAccountOperation, WSAWPWebAccountProviderManageAccountOperation,
    WSAWPWebAccountProviderDeleteAccountOperation, WSAWPWebAccountProviderSignOutAccountOperation,
    WSAWPWebAccountProviderRetrieveCookiesOperation, WSAWPWebAccountProviderTriggerDetails;
@protocol WSAWPIWebAccountProviderOperation
, WSAWPIWebProviderTokenRequest, WSAWPIWebProviderTokenResponse, WSAWPIWebProviderTokenResponseFactory, WSAWPIWebAccountClientView,
    WSAWPIWebAccountClientViewFactory, WSAWPIWebAccountManagerStatics, WSAWPIWebAccountScopeManagerStatics,
    WSAWPIWebAccountProviderBaseReportOperation, WSAWPIWebAccountProviderUIReportOperation, WSAWPIWebAccountProviderSilentReportOperation,
    WSAWPIWebAccountProviderTokenOperation, WSAWPIWebAccountProviderAddAccountOperation, WSAWPIWebAccountProviderManageAccountOperation,
    WSAWPIWebAccountProviderDeleteAccountOperation, WSAWPIWebAccountProviderSignOutAccountOperation,
    WSAWPIWebAccountProviderRetrieveCookiesOperation, WSAWPIWebAccountProviderTokenObjects;

// Windows.Security.Authentication.Web.Provider.WebAccountProviderOperationKind
enum _WSAWPWebAccountProviderOperationKind {
    WSAWPWebAccountProviderOperationKindRequestToken = 0,
    WSAWPWebAccountProviderOperationKindGetTokenSilently = 1,
    WSAWPWebAccountProviderOperationKindAddAccount = 2,
    WSAWPWebAccountProviderOperationKindManageAccount = 3,
    WSAWPWebAccountProviderOperationKindDeleteAccount = 4,
    WSAWPWebAccountProviderOperationKindRetrieveCookies = 5,
    WSAWPWebAccountProviderOperationKindSignOutAccount = 6,
};
typedef unsigned WSAWPWebAccountProviderOperationKind;

// Windows.Security.Authentication.Web.Provider.WebAccountSelectionOptions
enum _WSAWPWebAccountSelectionOptions {
    WSAWPWebAccountSelectionOptionsDefault = 0,
    WSAWPWebAccountSelectionOptionsNew = 1,
};
typedef unsigned WSAWPWebAccountSelectionOptions;

// Windows.Security.Authentication.Web.Provider.WebAccountClientViewType
enum _WSAWPWebAccountClientViewType {
    WSAWPWebAccountClientViewTypeIdOnly = 0,
    WSAWPWebAccountClientViewTypeIdAndProperties = 1,
};
typedef unsigned WSAWPWebAccountClientViewType;

// Windows.Security.Authentication.Web.Provider.WebAccountScope
enum _WSAWPWebAccountScope {
    WSAWPWebAccountScopePerUser = 0,
    WSAWPWebAccountScopePerApplication = 1,
};
typedef unsigned WSAWPWebAccountScope;

#include "WindowsSecurityAuthenticationWebCore.h"
#include "WindowsSecurityCryptographyCore.h"
#include "WindowsFoundation.h"
#include "WindowsStorageStreams.h"
#include "WindowsSecurityCredentials.h"
#include "WindowsFoundationCollections.h"
#include "WindowsWebHttp.h"
#include "WindowsSecurityAuthenticationWeb.h"

#import <Foundation/Foundation.h>

// Windows.Security.Authentication.Web.Provider.IWebAccountProviderOperation
#ifndef __WSAWPIWebAccountProviderOperation_DEFINED__
#define __WSAWPIWebAccountProviderOperation_DEFINED__

@protocol WSAWPIWebAccountProviderOperation
@property (readonly) WSAWPWebAccountProviderOperationKind kind;
@end

#endif // __WSAWPIWebAccountProviderOperation_DEFINED__

// Windows.Security.Authentication.Web.Provider.IWebAccountProviderBaseReportOperation
#ifndef __WSAWPIWebAccountProviderBaseReportOperation_DEFINED__
#define __WSAWPIWebAccountProviderBaseReportOperation_DEFINED__

@protocol WSAWPIWebAccountProviderBaseReportOperation
- (void)reportCompleted;
- (void)reportError:(WSAWCWebProviderError*)value;
@end

#endif // __WSAWPIWebAccountProviderBaseReportOperation_DEFINED__

// Windows.Security.Authentication.Web.Provider.IWebAccountProviderUIReportOperation
#ifndef __WSAWPIWebAccountProviderUIReportOperation_DEFINED__
#define __WSAWPIWebAccountProviderUIReportOperation_DEFINED__

@protocol WSAWPIWebAccountProviderUIReportOperation <WSAWPIWebAccountProviderBaseReportOperation>
- (void)reportUserCanceled;
- (void)reportCompleted;
- (void)reportError:(WSAWCWebProviderError*)value;
@end

#endif // __WSAWPIWebAccountProviderUIReportOperation_DEFINED__

// Windows.Security.Authentication.Web.Provider.IWebAccountProviderSilentReportOperation
#ifndef __WSAWPIWebAccountProviderSilentReportOperation_DEFINED__
#define __WSAWPIWebAccountProviderSilentReportOperation_DEFINED__

@protocol WSAWPIWebAccountProviderSilentReportOperation <WSAWPIWebAccountProviderBaseReportOperation>
- (void)reportUserInteractionRequired;
- (void)reportUserInteractionRequiredWithError:(WSAWCWebProviderError*)value;
- (void)reportCompleted;
- (void)reportError:(WSAWCWebProviderError*)value;
@end

#endif // __WSAWPIWebAccountProviderSilentReportOperation_DEFINED__

// Windows.Security.Authentication.Web.Provider.IWebAccountProviderTokenOperation
#ifndef __WSAWPIWebAccountProviderTokenOperation_DEFINED__
#define __WSAWPIWebAccountProviderTokenOperation_DEFINED__

@protocol WSAWPIWebAccountProviderTokenOperation <WSAWPIWebAccountProviderOperation>
@property (copy) WFDateTime* cacheExpirationTime;
@property (readonly) WSAWPWebProviderTokenRequest* providerRequest;
@property (readonly) NSMutableArray* providerResponses;
@end

#endif // __WSAWPIWebAccountProviderTokenOperation_DEFINED__

// Windows.Security.Authentication.Web.Provider.IWebAccountProviderTokenObjects
#ifndef __WSAWPIWebAccountProviderTokenObjects_DEFINED__
#define __WSAWPIWebAccountProviderTokenObjects_DEFINED__

@protocol WSAWPIWebAccountProviderTokenObjects
@property (readonly) RTObject<WSAWPIWebAccountProviderOperation>* operation;
@end

#endif // __WSAWPIWebAccountProviderTokenObjects_DEFINED__

// Windows.Security.Authentication.Web.Provider.WebProviderTokenRequest
#ifndef __WSAWPWebProviderTokenRequest_DEFINED__
#define __WSAWPWebProviderTokenRequest_DEFINED__

WINRT_EXPORT
@interface WSAWPWebProviderTokenRequest : RTObject
@property (readonly) WFUri* applicationCallbackUri;
@property (readonly) WSAWCWebTokenRequest* clientRequest;
@property (readonly) WSAWPWebAccountSelectionOptions webAccountSelectionOptions;
@property (readonly) NSArray* webAccounts;
- (void)getApplicationTokenBindingKeyAsync:(WSAWTokenBindingKeyType)keyType
                                    target:(WFUri*)target
                                   success:(void (^)(WSCCCryptographicKey*))success
                                   failure:(void (^)(NSError*))failure;
@end

#endif // __WSAWPWebProviderTokenRequest_DEFINED__

// Windows.Security.Authentication.Web.Provider.WebProviderTokenResponse
#ifndef __WSAWPWebProviderTokenResponse_DEFINED__
#define __WSAWPWebProviderTokenResponse_DEFINED__

WINRT_EXPORT
@interface WSAWPWebProviderTokenResponse : RTObject
+ (WSAWPWebProviderTokenResponse*)create:(WSAWCWebTokenResponse*)webTokenResponse ACTIVATOR;
@property (readonly) WSAWCWebTokenResponse* clientResponse;
@end

#endif // __WSAWPWebProviderTokenResponse_DEFINED__

// Windows.Security.Authentication.Web.Provider.WebAccountClientView
#ifndef __WSAWPWebAccountClientView_DEFINED__
#define __WSAWPWebAccountClientView_DEFINED__

WINRT_EXPORT
@interface WSAWPWebAccountClientView : RTObject
+ (WSAWPWebAccountClientView*)create:(WSAWPWebAccountClientViewType)viewType
              applicationCallbackUri:(WFUri*)applicationCallbackUri ACTIVATOR;
+ (WSAWPWebAccountClientView*)createWithPairwiseId:(WSAWPWebAccountClientViewType)viewType
                            applicationCallbackUri:(WFUri*)applicationCallbackUri
                                 accountPairwiseId:(NSString*)accountPairwiseId ACTIVATOR;
@property (readonly) NSString* accountPairwiseId;
@property (readonly) WFUri* applicationCallbackUri;
@property (readonly) WSAWPWebAccountClientViewType type;
@end

#endif // __WSAWPWebAccountClientView_DEFINED__

// Windows.Security.Authentication.Web.Provider.WebAccountManager
#ifndef __WSAWPWebAccountManager_DEFINED__
#define __WSAWPWebAccountManager_DEFINED__

WINRT_EXPORT
@interface WSAWPWebAccountManager : RTObject
+ (RTObject<WFIAsyncAction>*)updateWebAccountPropertiesAsync:(WSCWebAccount*)webAccount
                                          webAccountUserName:(NSString*)webAccountUserName
                                        additionalProperties:(NSDictionary* /* NSString *, NSString * */)additionalProperties;
+ (void)addWebAccountAsync:(NSString*)webAccountId
        webAccountUserName:(NSString*)webAccountUserName
                     props:(NSDictionary* /* NSString *, NSString * */)props
                   success:(void (^)(WSCWebAccount*))success
                   failure:(void (^)(NSError*))failure;
+ (RTObject<WFIAsyncAction>*)deleteWebAccountAsync:(WSCWebAccount*)webAccount;
+ (void)findAllProviderWebAccountsAsyncWithSuccess:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
+ (RTObject<WFIAsyncAction>*)pushCookiesAsync:(WFUri*)uri cookies:(id<NSFastEnumeration> /* WWHHttpCookie* */)cookies;
+ (RTObject<WFIAsyncAction>*)setViewAsync:(WSCWebAccount*)webAccount view:(WSAWPWebAccountClientView*)view;
+ (RTObject<WFIAsyncAction>*)clearViewAsync:(WSCWebAccount*)webAccount applicationCallbackUri:(WFUri*)applicationCallbackUri;
+ (void)getViewsAsync:(WSCWebAccount*)webAccount success:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
+ (RTObject<WFIAsyncAction>*)setWebAccountPictureAsync:(WSCWebAccount*)webAccount
                                     webAccountPicture:(RTObject<WSSIRandomAccessStream>*)webAccountPicture;
+ (RTObject<WFIAsyncAction>*)clearWebAccountPictureAsync:(WSCWebAccount*)webAccount;
+ (void)addWebAccountWithScopeAsync:(NSString*)webAccountId
                 webAccountUserName:(NSString*)webAccountUserName
                              props:(NSDictionary* /* NSString *, NSString * */)props
                              scope:(WSAWPWebAccountScope)scope
                            success:(void (^)(WSCWebAccount*))success
                            failure:(void (^)(NSError*))failure;
+ (RTObject<WFIAsyncAction>*)setScopeAsync:(WSCWebAccount*)webAccount scope:(WSAWPWebAccountScope)scope;
+ (WSAWPWebAccountScope)getScope:(WSCWebAccount*)webAccount;
@end

#endif // __WSAWPWebAccountManager_DEFINED__

// Windows.Security.Authentication.Web.Provider.WebAccountProviderRequestTokenOperation
#ifndef __WSAWPWebAccountProviderRequestTokenOperation_DEFINED__
#define __WSAWPWebAccountProviderRequestTokenOperation_DEFINED__

WINRT_EXPORT
@interface WSAWPWebAccountProviderRequestTokenOperation : RTObject <WSAWPIWebAccountProviderTokenOperation,
                                                                    WSAWPIWebAccountProviderOperation,
                                                                    WSAWPIWebAccountProviderUIReportOperation,
                                                                    WSAWPIWebAccountProviderBaseReportOperation>
@property (readonly) WSAWPWebAccountProviderOperationKind kind;
@property (copy) WFDateTime* cacheExpirationTime;
@property (readonly) WSAWPWebProviderTokenRequest* providerRequest;
@property (readonly) NSMutableArray* providerResponses;
- (void)reportUserCanceled;
- (void)reportCompleted;
- (void)reportError:(WSAWCWebProviderError*)value;
@end

#endif // __WSAWPWebAccountProviderRequestTokenOperation_DEFINED__

// Windows.Security.Authentication.Web.Provider.WebAccountProviderGetTokenSilentOperation
#ifndef __WSAWPWebAccountProviderGetTokenSilentOperation_DEFINED__
#define __WSAWPWebAccountProviderGetTokenSilentOperation_DEFINED__

WINRT_EXPORT
@interface WSAWPWebAccountProviderGetTokenSilentOperation : RTObject <WSAWPIWebAccountProviderTokenOperation,
                                                                      WSAWPIWebAccountProviderOperation,
                                                                      WSAWPIWebAccountProviderSilentReportOperation,
                                                                      WSAWPIWebAccountProviderBaseReportOperation>
@property (readonly) WSAWPWebAccountProviderOperationKind kind;
@property (copy) WFDateTime* cacheExpirationTime;
@property (readonly) WSAWPWebProviderTokenRequest* providerRequest;
@property (readonly) NSMutableArray* providerResponses;
- (void)reportUserInteractionRequired;
- (void)reportUserInteractionRequiredWithError:(WSAWCWebProviderError*)value;
- (void)reportCompleted;
- (void)reportError:(WSAWCWebProviderError*)value;
@end

#endif // __WSAWPWebAccountProviderGetTokenSilentOperation_DEFINED__

// Windows.Security.Authentication.Web.Provider.WebAccountProviderAddAccountOperation
#ifndef __WSAWPWebAccountProviderAddAccountOperation_DEFINED__
#define __WSAWPWebAccountProviderAddAccountOperation_DEFINED__

WINRT_EXPORT
@interface WSAWPWebAccountProviderAddAccountOperation : RTObject <WSAWPIWebAccountProviderOperation>
@property (readonly) WSAWPWebAccountProviderOperationKind kind;
- (void)reportCompleted;
@end

#endif // __WSAWPWebAccountProviderAddAccountOperation_DEFINED__

// Windows.Security.Authentication.Web.Provider.WebAccountProviderManageAccountOperation
#ifndef __WSAWPWebAccountProviderManageAccountOperation_DEFINED__
#define __WSAWPWebAccountProviderManageAccountOperation_DEFINED__

WINRT_EXPORT
@interface WSAWPWebAccountProviderManageAccountOperation : RTObject <WSAWPIWebAccountProviderOperation>
@property (readonly) WSCWebAccount* webAccount;
@property (readonly) WSAWPWebAccountProviderOperationKind kind;
- (void)reportCompleted;
@end

#endif // __WSAWPWebAccountProviderManageAccountOperation_DEFINED__

// Windows.Security.Authentication.Web.Provider.WebAccountProviderDeleteAccountOperation
#ifndef __WSAWPWebAccountProviderDeleteAccountOperation_DEFINED__
#define __WSAWPWebAccountProviderDeleteAccountOperation_DEFINED__

WINRT_EXPORT
@interface WSAWPWebAccountProviderDeleteAccountOperation
    : RTObject <WSAWPIWebAccountProviderOperation, WSAWPIWebAccountProviderBaseReportOperation>
@property (readonly) WSCWebAccount* webAccount;
@property (readonly) WSAWPWebAccountProviderOperationKind kind;
- (void)reportCompleted;
- (void)reportError:(WSAWCWebProviderError*)value;
@end

#endif // __WSAWPWebAccountProviderDeleteAccountOperation_DEFINED__

// Windows.Security.Authentication.Web.Provider.WebAccountProviderSignOutAccountOperation
#ifndef __WSAWPWebAccountProviderSignOutAccountOperation_DEFINED__
#define __WSAWPWebAccountProviderSignOutAccountOperation_DEFINED__

WINRT_EXPORT
@interface WSAWPWebAccountProviderSignOutAccountOperation
    : RTObject <WSAWPIWebAccountProviderOperation, WSAWPIWebAccountProviderBaseReportOperation>
@property (readonly) WSAWPWebAccountProviderOperationKind kind;
@property (readonly) WFUri* applicationCallbackUri;
@property (readonly) NSString* clientId;
@property (readonly) WSCWebAccount* webAccount;
- (void)reportCompleted;
- (void)reportError:(WSAWCWebProviderError*)value;
@end

#endif // __WSAWPWebAccountProviderSignOutAccountOperation_DEFINED__

// Windows.Security.Authentication.Web.Provider.WebAccountProviderRetrieveCookiesOperation
#ifndef __WSAWPWebAccountProviderRetrieveCookiesOperation_DEFINED__
#define __WSAWPWebAccountProviderRetrieveCookiesOperation_DEFINED__

WINRT_EXPORT
@interface WSAWPWebAccountProviderRetrieveCookiesOperation
    : RTObject <WSAWPIWebAccountProviderOperation, WSAWPIWebAccountProviderBaseReportOperation>
@property (readonly) WSAWPWebAccountProviderOperationKind kind;
@property (copy) WFUri* uri;
@property (readonly) WFUri* applicationCallbackUri;
@property (readonly) WFUri* context;
@property (readonly) NSMutableArray* cookies;
- (void)reportCompleted;
- (void)reportError:(WSAWCWebProviderError*)value;
@end

#endif // __WSAWPWebAccountProviderRetrieveCookiesOperation_DEFINED__

// Windows.Security.Authentication.Web.Provider.WebAccountProviderTriggerDetails
#ifndef __WSAWPWebAccountProviderTriggerDetails_DEFINED__
#define __WSAWPWebAccountProviderTriggerDetails_DEFINED__

WINRT_EXPORT
@interface WSAWPWebAccountProviderTriggerDetails : RTObject <WSAWPIWebAccountProviderTokenObjects>
@property (readonly) RTObject<WSAWPIWebAccountProviderOperation>* operation;
@end

#endif // __WSAWPWebAccountProviderTriggerDetails_DEFINED__
