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

// WindowsWebHttpFilters.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSWEBHTTPFILTERSEXPORT
#define OBJCUWPWINDOWSWEBHTTPFILTERSEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsWebHttpFilters.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WWHFHttpCacheControl, WWHFHttpBaseProtocolFilter, WWHFHttpServerCustomValidationRequestedEventArgs;
@protocol WWHFIHttpFilter, WWHFIHttpCacheControl, WWHFIHttpServerCustomValidationRequestedEventArgs, WWHFIHttpBaseProtocolFilter, WWHFIHttpBaseProtocolFilter2, WWHFIHttpBaseProtocolFilter3, WWHFIHttpBaseProtocolFilter4;

// Windows.Web.Http.Filters.HttpCacheReadBehavior
enum _WWHFHttpCacheReadBehavior {
    WWHFHttpCacheReadBehaviorDefault = 0,
    WWHFHttpCacheReadBehaviorMostRecent = 1,
    WWHFHttpCacheReadBehaviorOnlyFromCache = 2,
    WWHFHttpCacheReadBehaviorNoCache = 3,
};
typedef unsigned WWHFHttpCacheReadBehavior;

// Windows.Web.Http.Filters.HttpCacheWriteBehavior
enum _WWHFHttpCacheWriteBehavior {
    WWHFHttpCacheWriteBehaviorDefault = 0,
    WWHFHttpCacheWriteBehaviorNoCache = 1,
};
typedef unsigned WWHFHttpCacheWriteBehavior;

// Windows.Web.Http.Filters.HttpCookieUsageBehavior
enum _WWHFHttpCookieUsageBehavior {
    WWHFHttpCookieUsageBehaviorDefault = 0,
    WWHFHttpCookieUsageBehaviorNoCookies = 1,
};
typedef unsigned WWHFHttpCookieUsageBehavior;

#include "WindowsFoundation.h"
#include "WindowsNetworkingSockets.h"
#include "WindowsSecurityCryptographyCertificates.h"
#include "WindowsWebHttp.h"
#include "WindowsSecurityCredentials.h"

#import <Foundation/Foundation.h>

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWPWINDOWSWEBHTTPFILTERSEXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.Web.Http.Filters.IHttpFilter
#ifndef __WWHFIHttpFilter_DEFINED__
#define __WWHFIHttpFilter_DEFINED__

@protocol WWHFIHttpFilter <WFIClosable>
- (void)sendRequestAsync:(WWHHttpRequestMessage*)request success:(void (^)(WWHHttpResponseMessage*))success progress:(void (^)(WWHHttpProgress*))progress failure:(void (^)(NSError*))failure;
- (void)close;
@end

OBJCUWPWINDOWSWEBHTTPFILTERSEXPORT
@interface WWHFIHttpFilter : RTObject <WWHFIHttpFilter>
@end

#endif // __WWHFIHttpFilter_DEFINED__

// Windows.Web.Http.Filters.HttpCacheControl
#ifndef __WWHFHttpCacheControl_DEFINED__
#define __WWHFHttpCacheControl_DEFINED__

OBJCUWPWINDOWSWEBHTTPFILTERSEXPORT
@interface WWHFHttpCacheControl : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WWHFHttpCacheWriteBehavior writeBehavior;
@property WWHFHttpCacheReadBehavior readBehavior;
@end

#endif // __WWHFHttpCacheControl_DEFINED__

// Windows.Web.Http.Filters.HttpBaseProtocolFilter
#ifndef __WWHFHttpBaseProtocolFilter_DEFINED__
#define __WWHFHttpBaseProtocolFilter_DEFINED__

OBJCUWPWINDOWSWEBHTTPFILTERSEXPORT
@interface WWHFHttpBaseProtocolFilter : RTObject <WWHFIHttpFilter, WFIClosable>
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL useProxy;
@property (retain) WSCPasswordCredential* serverCredential;
@property (retain) WSCPasswordCredential* proxyCredential;
@property unsigned int maxConnectionsPerServer;
@property (retain) WSCCCertificate* clientCertificate;
@property BOOL automaticDecompression;
@property BOOL allowUI;
@property BOOL allowAutoRedirect;
@property (readonly) WWHHttpCookieManager* cookieManager;
@property (readonly) NSMutableArray* /* WSCCChainValidationResult */ ignorableServerCertificateErrors;
@property (readonly) WWHFHttpCacheControl* cacheControl;
@property WWHHttpVersion maxVersion;
@property WWHFHttpCookieUsageBehavior cookieUsageBehavior;
- (EventRegistrationToken)addServerCustomValidationRequestedEvent:(void(^)(WWHFHttpBaseProtocolFilter*, WWHFHttpServerCustomValidationRequestedEventArgs*))del;
- (void)removeServerCustomValidationRequestedEvent:(EventRegistrationToken)tok;
- (void)sendRequestAsync:(WWHHttpRequestMessage*)request success:(void (^)(WWHHttpResponseMessage*))success progress:(void (^)(WWHHttpProgress*))progress failure:(void (^)(NSError*))failure;
- (void)close;
- (void)clearAuthenticationCache;
@end

#endif // __WWHFHttpBaseProtocolFilter_DEFINED__

// Windows.Web.Http.Filters.HttpServerCustomValidationRequestedEventArgs
#ifndef __WWHFHttpServerCustomValidationRequestedEventArgs_DEFINED__
#define __WWHFHttpServerCustomValidationRequestedEventArgs_DEFINED__

OBJCUWPWINDOWSWEBHTTPFILTERSEXPORT
@interface WWHFHttpServerCustomValidationRequestedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WWHHttpRequestMessage* requestMessage;
@property (readonly) WSCCCertificate* serverCertificate;
@property (readonly) WNSSocketSslErrorSeverity serverCertificateErrorSeverity;
@property (readonly) NSArray* /* WSCCChainValidationResult */ serverCertificateErrors;
@property (readonly) NSArray* /* WSCCCertificate* */ serverIntermediateCertificates;
- (void)reject;
- (WFDeferral*)getDeferral;
@end

#endif // __WWHFHttpServerCustomValidationRequestedEventArgs_DEFINED__

