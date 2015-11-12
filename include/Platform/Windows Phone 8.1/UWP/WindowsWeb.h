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

// WindowsWeb.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WWWebError;
@protocol WWIUriToStreamResolver
, WWIWebErrorStatics;

// Windows.Web.WebErrorStatus
enum _WWWebErrorStatus {
    WWWebErrorStatusUnknown = 0,
    WWWebErrorStatusCertificateCommonNameIsIncorrect = 1,
    WWWebErrorStatusCertificateExpired = 2,
    WWWebErrorStatusCertificateContainsErrors = 3,
    WWWebErrorStatusCertificateRevoked = 4,
    WWWebErrorStatusCertificateIsInvalid = 5,
    WWWebErrorStatusServerUnreachable = 6,
    WWWebErrorStatusTimeout = 7,
    WWWebErrorStatusErrorHttpInvalidServerResponse = 8,
    WWWebErrorStatusConnectionAborted = 9,
    WWWebErrorStatusConnectionReset = 10,
    WWWebErrorStatusDisconnected = 11,
    WWWebErrorStatusHttpToHttpsOnRedirection = 12,
    WWWebErrorStatusHttpsToHttpOnRedirection = 13,
    WWWebErrorStatusCannotConnect = 14,
    WWWebErrorStatusHostNameNotResolved = 15,
    WWWebErrorStatusOperationCanceled = 16,
    WWWebErrorStatusRedirectFailed = 17,
    WWWebErrorStatusUnexpectedStatusCode = 18,
    WWWebErrorStatusUnexpectedRedirection = 19,
    WWWebErrorStatusUnexpectedClientError = 20,
    WWWebErrorStatusUnexpectedServerError = 21,
    WWWebErrorStatusMultipleChoices = 300,
    WWWebErrorStatusMovedPermanently = 301,
    WWWebErrorStatusFound = 302,
    WWWebErrorStatusSeeOther = 303,
    WWWebErrorStatusNotModified = 304,
    WWWebErrorStatusUseProxy = 305,
    WWWebErrorStatusTemporaryRedirect = 307,
    WWWebErrorStatusBadRequest = 400,
    WWWebErrorStatusUnauthorized = 401,
    WWWebErrorStatusPaymentRequired = 402,
    WWWebErrorStatusForbidden = 403,
    WWWebErrorStatusNotFound = 404,
    WWWebErrorStatusMethodNotAllowed = 405,
    WWWebErrorStatusNotAcceptable = 406,
    WWWebErrorStatusProxyAuthenticationRequired = 407,
    WWWebErrorStatusRequestTimeout = 408,
    WWWebErrorStatusConflict = 409,
    WWWebErrorStatusGone = 410,
    WWWebErrorStatusLengthRequired = 411,
    WWWebErrorStatusPreconditionFailed = 412,
    WWWebErrorStatusRequestEntityTooLarge = 413,
    WWWebErrorStatusRequestUriTooLong = 414,
    WWWebErrorStatusUnsupportedMediaType = 415,
    WWWebErrorStatusRequestedRangeNotSatisfiable = 416,
    WWWebErrorStatusExpectationFailed = 417,
    WWWebErrorStatusInternalServerError = 500,
    WWWebErrorStatusNotImplemented = 501,
    WWWebErrorStatusBadGateway = 502,
    WWWebErrorStatusServiceUnavailable = 503,
    WWWebErrorStatusGatewayTimeout = 504,
    WWWebErrorStatusHttpVersionNotSupported = 505,
};
typedef unsigned WWWebErrorStatus;

#include "WindowsStorageStreams.h"
#include "WindowsFoundation.h"

// Windows.Web.IUriToStreamResolver
#ifndef __WWIUriToStreamResolver_DEFINED__
#define __WWIUriToStreamResolver_DEFINED__

@protocol WWIUriToStreamResolver
- (void)uriToStreamAsync:(WFUri*)uri success:(void (^)(RTObject<WSSIInputStream>*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WWIUriToStreamResolver_DEFINED__

// Windows.Web.WebError
#ifndef __WWWebError_DEFINED__
#define __WWWebError_DEFINED__

WINRT_EXPORT
@interface WWWebError : RTObject
+ (WWWebErrorStatus)getStatus:(int)hresult;
@end

#endif // __WWWebError_DEFINED__
