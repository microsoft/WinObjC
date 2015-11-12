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

// WindowsWebHttpFilters.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WWHFHttpCacheControl, WWHFHttpBaseProtocolFilter;
@protocol WWHFIHttpFilter
, WWHFIHttpCacheControl, WWHFIHttpBaseProtocolFilter, WWHFIHttpBaseProtocolFilter2;

// Windows.Web.Http.Filters.HttpCacheReadBehavior
enum _WWHFHttpCacheReadBehavior {
    WWHFHttpCacheReadBehaviorDefault = 0,
    WWHFHttpCacheReadBehaviorMostRecent = 1,
    WWHFHttpCacheReadBehaviorOnlyFromCache = 2,
};
typedef unsigned WWHFHttpCacheReadBehavior;

// Windows.Web.Http.Filters.HttpCacheWriteBehavior
enum _WWHFHttpCacheWriteBehavior {
    WWHFHttpCacheWriteBehaviorDefault = 0,
    WWHFHttpCacheWriteBehaviorNoCache = 1,
};
typedef unsigned WWHFHttpCacheWriteBehavior;

#include "WindowsFoundation.h"
#include "WindowsSecurityCryptographyCertificates.h"
#include "WindowsWebHttp.h"
#include "WindowsSecurityCredentials.h"
#include "WindowsFoundationCollections.h"

#import <Foundation/Foundation.h>

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

#endif // __WFIClosable_DEFINED__

// Windows.Web.Http.Filters.IHttpFilter
#ifndef __WWHFIHttpFilter_DEFINED__
#define __WWHFIHttpFilter_DEFINED__

@protocol WWHFIHttpFilter <WFIClosable>
- (void)sendRequestAsync:(WWHHttpRequestMessage*)request
                 success:(void (^)(WWHHttpResponseMessage*))success
                progress:(void (^)(WWHHttpProgress*))progress
                 failure:(void (^)(NSError*))failure;
- (void)close;
@end

#endif // __WWHFIHttpFilter_DEFINED__

// Windows.Web.Http.Filters.HttpCacheControl
#ifndef __WWHFHttpCacheControl_DEFINED__
#define __WWHFHttpCacheControl_DEFINED__

WINRT_EXPORT
@interface WWHFHttpCacheControl : RTObject
@property WWHFHttpCacheWriteBehavior writeBehavior;
@property WWHFHttpCacheReadBehavior readBehavior;
@end

#endif // __WWHFHttpCacheControl_DEFINED__

// Windows.Web.Http.Filters.HttpBaseProtocolFilter
#ifndef __WWHFHttpBaseProtocolFilter_DEFINED__
#define __WWHFHttpBaseProtocolFilter_DEFINED__

WINRT_EXPORT
@interface WWHFHttpBaseProtocolFilter : RTObject <WWHFIHttpFilter, WFIClosable>
+ (instancetype)create ACTIVATOR;
@property BOOL useProxy;
@property (copy) WSCPasswordCredential* serverCredential;
@property (copy) WSCPasswordCredential* proxyCredential;
@property unsigned int maxConnectionsPerServer;
@property (copy) WSCCCertificate* clientCertificate;
@property BOOL automaticDecompression;
@property BOOL allowUI;
@property BOOL allowAutoRedirect;
@property (readonly) WWHHttpCookieManager* cookieManager;
@property (readonly) NSMutableArray* ignorableServerCertificateErrors;
@property (readonly) WWHFHttpCacheControl* cacheControl;
@property WWHHttpVersion maxVersion;
- (void)sendRequestAsync:(WWHHttpRequestMessage*)request
                 success:(void (^)(WWHHttpResponseMessage*))success
                progress:(void (^)(WWHHttpProgress*))progress
                 failure:(void (^)(NSError*))failure;
- (void)close;
@end

#endif // __WWHFHttpBaseProtocolFilter_DEFINED__
