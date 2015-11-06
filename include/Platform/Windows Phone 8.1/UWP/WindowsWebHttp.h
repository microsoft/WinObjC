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

// WindowsWebHttp.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WWHHttpRequestMessage, WWHHttpResponseMessage, WWHHttpClient, WWHHttpCookie, WWHHttpCookieCollection, WWHHttpMethod,
    WWHHttpTransportInformation, WWHHttpStringContent, WWHHttpBufferContent, WWHHttpStreamContent, WWHHttpFormUrlEncodedContent,
    WWHHttpMultipartContent, WWHHttpMultipartFormDataContent, WWHHttpCookieManager;
@class WWHHttpProgress;
@protocol WWHIHttpClientFactory
, WWHIHttpClient, WWHIHttpContent, WWHIHttpCookieManager, WWHIHttpCookieFactory, WWHIHttpCookie, WWHIHttpMethodStatics,
    WWHIHttpMethodFactory, WWHIHttpMethod, WWHIHttpTransportInformation, WWHIHttpRequestMessageFactory, WWHIHttpRequestMessage,
    WWHIHttpResponseMessageFactory, WWHIHttpResponseMessage, WWHIHttpStringContentFactory, WWHIHttpBufferContentFactory,
    WWHIHttpStreamContentFactory, WWHIHttpFormUrlEncodedContentFactory, WWHIHttpMultipartContentFactory, WWHIHttpMultipartContent,
    WWHIHttpMultipartFormDataContentFactory, WWHIHttpMultipartFormDataContent;

// Windows.Web.Http.HttpVersion
enum _WWHHttpVersion {
    WWHHttpVersionNone = 0,
    WWHHttpVersionHttp10 = 1,
    WWHHttpVersionHttp11 = 2,
};
typedef unsigned WWHHttpVersion;

// Windows.Web.Http.HttpCompletionOption
enum _WWHHttpCompletionOption {
    WWHHttpCompletionOptionResponseContentRead = 0,
    WWHHttpCompletionOptionResponseHeadersRead = 1,
};
typedef unsigned WWHHttpCompletionOption;

// Windows.Web.Http.HttpStatusCode
enum _WWHHttpStatusCode {
    WWHHttpStatusCodeNone = 0,
    WWHHttpStatusCodeContinue = 100,
    WWHHttpStatusCodeSwitchingProtocols = 101,
    WWHHttpStatusCodeProcessing = 102,
    WWHHttpStatusCodeOk = 200,
    WWHHttpStatusCodeCreated = 201,
    WWHHttpStatusCodeAccepted = 202,
    WWHHttpStatusCodeNonAuthoritativeInformation = 203,
    WWHHttpStatusCodeNoContent = 204,
    WWHHttpStatusCodeResetContent = 205,
    WWHHttpStatusCodePartialContent = 206,
    WWHHttpStatusCodeMultiStatus = 207,
    WWHHttpStatusCodeAlreadyReported = 208,
    WWHHttpStatusCodeIMUsed = 226,
    WWHHttpStatusCodeMultipleChoices = 300,
    WWHHttpStatusCodeMovedPermanently = 301,
    WWHHttpStatusCodeFound = 302,
    WWHHttpStatusCodeSeeOther = 303,
    WWHHttpStatusCodeNotModified = 304,
    WWHHttpStatusCodeUseProxy = 305,
    WWHHttpStatusCodeTemporaryRedirect = 307,
    WWHHttpStatusCodePermanentRedirect = 308,
    WWHHttpStatusCodeBadRequest = 400,
    WWHHttpStatusCodeUnauthorized = 401,
    WWHHttpStatusCodePaymentRequired = 402,
    WWHHttpStatusCodeForbidden = 403,
    WWHHttpStatusCodeNotFound = 404,
    WWHHttpStatusCodeMethodNotAllowed = 405,
    WWHHttpStatusCodeNotAcceptable = 406,
    WWHHttpStatusCodeProxyAuthenticationRequired = 407,
    WWHHttpStatusCodeRequestTimeout = 408,
    WWHHttpStatusCodeConflict = 409,
    WWHHttpStatusCodeGone = 410,
    WWHHttpStatusCodeLengthRequired = 411,
    WWHHttpStatusCodePreconditionFailed = 412,
    WWHHttpStatusCodeRequestEntityTooLarge = 413,
    WWHHttpStatusCodeRequestUriTooLong = 414,
    WWHHttpStatusCodeUnsupportedMediaType = 415,
    WWHHttpStatusCodeRequestedRangeNotSatisfiable = 416,
    WWHHttpStatusCodeExpectationFailed = 417,
    WWHHttpStatusCodeUnprocessableEntity = 422,
    WWHHttpStatusCodeLocked = 423,
    WWHHttpStatusCodeFailedDependency = 424,
    WWHHttpStatusCodeUpgradeRequired = 426,
    WWHHttpStatusCodePreconditionRequired = 428,
    WWHHttpStatusCodeTooManyRequests = 429,
    WWHHttpStatusCodeRequestHeaderFieldsTooLarge = 431,
    WWHHttpStatusCodeInternalServerError = 500,
    WWHHttpStatusCodeNotImplemented = 501,
    WWHHttpStatusCodeBadGateway = 502,
    WWHHttpStatusCodeServiceUnavailable = 503,
    WWHHttpStatusCodeGatewayTimeout = 504,
    WWHHttpStatusCodeHttpVersionNotSupported = 505,
    WWHHttpStatusCodeVariantAlsoNegotiates = 506,
    WWHHttpStatusCodeInsufficientStorage = 507,
    WWHHttpStatusCodeLoopDetected = 508,
    WWHHttpStatusCodeNotExtended = 510,
    WWHHttpStatusCodeNetworkAuthenticationRequired = 511,
};
typedef unsigned WWHHttpStatusCode;

// Windows.Web.Http.HttpProgressStage
enum _WWHHttpProgressStage {
    WWHHttpProgressStageNone = 0,
    WWHHttpProgressStageDetectingProxy = 10,
    WWHHttpProgressStageResolvingName = 20,
    WWHHttpProgressStageConnectingToServer = 30,
    WWHHttpProgressStageNegotiatingSsl = 40,
    WWHHttpProgressStageSendingHeaders = 50,
    WWHHttpProgressStageSendingContent = 60,
    WWHHttpProgressStageWaitingForResponse = 70,
    WWHHttpProgressStageReceivingHeaders = 80,
    WWHHttpProgressStageReceivingContent = 90,
};
typedef unsigned WWHHttpProgressStage;

// Windows.Web.Http.HttpResponseMessageSource
enum _WWHHttpResponseMessageSource {
    WWHHttpResponseMessageSourceNone = 0,
    WWHHttpResponseMessageSourceCache = 1,
    WWHHttpResponseMessageSourceNetwork = 2,
};
typedef unsigned WWHHttpResponseMessageSource;

#include "WindowsNetworkingSockets.h"
#include "WindowsSecurityCryptographyCertificates.h"
#include "WindowsFoundation.h"
#include "WindowsWebHttpFilters.h"
#include "WindowsFoundationCollections.h"
#include "WindowsStorageStreams.h"
#include "WindowsWebHttpHeaders.h"

// [struct] Windows.Web.Http.HttpProgress
WINRT_EXPORT
@interface WWHHttpProgress : NSObject
+ (instancetype) new;
@property WWHHttpProgressStage stage;
@property uint64_t bytesSent;
@property (copy) NSNumber* totalBytesToSend;
@property uint64_t bytesReceived;
@property (copy) NSNumber* totalBytesToReceive;
@property unsigned retries;
@end

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

#endif // __WFIClosable_DEFINED__

// Windows.Web.Http.IHttpContent
#ifndef __WWHIHttpContent_DEFINED__
#define __WWHIHttpContent_DEFINED__

@protocol WWHIHttpContent <WFIClosable>
@property (readonly) WWHHHttpContentHeaderCollection* headers;
- (void)bufferAllAsyncWithSuccess:(void (^)(uint64_t))success progress:(void (^)(uint64_t))progress failure:(void (^)(NSError*))failure;
- (void)readAsBufferAsyncWithSuccess:(void (^)(RTObject<WSSIBuffer>*))success
                            progress:(void (^)(uint64_t))progress
                             failure:(void (^)(NSError*))failure;
- (void)readAsInputStreamAsyncWithSuccess:(void (^)(RTObject<WSSIInputStream>*))success
                                 progress:(void (^)(uint64_t))progress
                                  failure:(void (^)(NSError*))failure;
- (void)readAsStringAsyncWithSuccess:(void (^)(NSString*))success progress:(void (^)(uint64_t))progress failure:(void (^)(NSError*))failure;
- (BOOL)tryComputeLength:(uint64_t*)length;
- (void)writeToStreamAsync:(RTObject<WSSIOutputStream>*)outputStream
                   success:(void (^)(uint64_t))success
                  progress:(void (^)(uint64_t))progress
                   failure:(void (^)(NSError*))failure;
- (void)close;
@end

#endif // __WWHIHttpContent_DEFINED__

// Windows.Foundation.IStringable
#ifndef __WFIStringable_DEFINED__
#define __WFIStringable_DEFINED__

@protocol WFIStringable
- (NSString*)toString;
@end

#endif // __WFIStringable_DEFINED__

// Windows.Web.Http.HttpRequestMessage
#ifndef __WWHHttpRequestMessage_DEFINED__
#define __WWHHttpRequestMessage_DEFINED__

WINRT_EXPORT
@interface WWHHttpRequestMessage : RTObject <WFIClosable, WFIStringable>
+ (WWHHttpRequestMessage*)create:(WWHHttpMethod*)method uri:(WFUri*)uri ACTIVATOR;
+ (instancetype)create ACTIVATOR;
@property (copy) WFUri* requestUri;
@property (copy) WWHHttpMethod* method;
@property (copy) RTObject<WWHIHttpContent>* content;
@property (readonly) WWHHHttpRequestHeaderCollection* headers;
// Failed to generate property Properties (Can't marshal Windows.Foundation.Collections.IMap`2<String,System.Object>)
@property (readonly) WWHHttpTransportInformation* transportInformation;
// Failed to generate member get_Properties (Can't marshal Windows.Foundation.Collections.IMap`2<String,System.Object>)
- (void)close;
- (NSString*)toString;
@end

#endif // __WWHHttpRequestMessage_DEFINED__

// Windows.Web.Http.HttpResponseMessage
#ifndef __WWHHttpResponseMessage_DEFINED__
#define __WWHHttpResponseMessage_DEFINED__

WINRT_EXPORT
@interface WWHHttpResponseMessage : RTObject <WFIClosable, WFIStringable>
+ (instancetype)create ACTIVATOR;
+ (WWHHttpResponseMessage*)create:(WWHHttpStatusCode)statusCode ACTIVATOR;
@property WWHHttpVersion version;
@property WWHHttpStatusCode statusCode;
@property WWHHttpResponseMessageSource source;
@property (copy) WWHHttpRequestMessage* requestMessage;
@property (copy) NSString* reasonPhrase;
@property (copy) RTObject<WWHIHttpContent>* content;
@property (readonly) WWHHHttpResponseHeaderCollection* headers;
@property (readonly) BOOL isSuccessStatusCode;
- (WWHHttpResponseMessage*)ensureSuccessStatusCode;
- (void)close;
- (NSString*)toString;
@end

#endif // __WWHHttpResponseMessage_DEFINED__

// Windows.Web.Http.HttpClient
#ifndef __WWHHttpClient_DEFINED__
#define __WWHHttpClient_DEFINED__

WINRT_EXPORT
@interface WWHHttpClient : RTObject <WFIClosable, WFIStringable>
+ (instancetype)create ACTIVATOR;
+ (WWHHttpClient*)create:(RTObject<WWHFIHttpFilter>*)filter ACTIVATOR;
@property (readonly) WWHHHttpRequestHeaderCollection* defaultRequestHeaders;
- (void)deleteAsync:(WFUri*)uri
            success:(void (^)(WWHHttpResponseMessage*))success
           progress:(void (^)(WWHHttpProgress*))progress
            failure:(void (^)(NSError*))failure;
- (void)getAsync:(WFUri*)uri
         success:(void (^)(WWHHttpResponseMessage*))success
        progress:(void (^)(WWHHttpProgress*))progress
         failure:(void (^)(NSError*))failure;
- (void)getWithOptionAsync:(WFUri*)uri
          completionOption:(WWHHttpCompletionOption)completionOption
                   success:(void (^)(WWHHttpResponseMessage*))success
                  progress:(void (^)(WWHHttpProgress*))progress
                   failure:(void (^)(NSError*))failure;
- (void)getBufferAsync:(WFUri*)uri
               success:(void (^)(RTObject<WSSIBuffer>*))success
              progress:(void (^)(WWHHttpProgress*))progress
               failure:(void (^)(NSError*))failure;
- (void)getInputStreamAsync:(WFUri*)uri
                    success:(void (^)(RTObject<WSSIInputStream>*))success
                   progress:(void (^)(WWHHttpProgress*))progress
                    failure:(void (^)(NSError*))failure;
- (void)getStringAsync:(WFUri*)uri
               success:(void (^)(NSString*))success
              progress:(void (^)(WWHHttpProgress*))progress
               failure:(void (^)(NSError*))failure;
- (void)postAsync:(WFUri*)uri
          content:(RTObject<WWHIHttpContent>*)content
          success:(void (^)(WWHHttpResponseMessage*))success
         progress:(void (^)(WWHHttpProgress*))progress
          failure:(void (^)(NSError*))failure;
- (void)putAsync:(WFUri*)uri
         content:(RTObject<WWHIHttpContent>*)content
         success:(void (^)(WWHHttpResponseMessage*))success
        progress:(void (^)(WWHHttpProgress*))progress
         failure:(void (^)(NSError*))failure;
- (void)sendRequestAsync:(WWHHttpRequestMessage*)request
                 success:(void (^)(WWHHttpResponseMessage*))success
                progress:(void (^)(WWHHttpProgress*))progress
                 failure:(void (^)(NSError*))failure;
- (void)sendRequestWithOptionAsync:(WWHHttpRequestMessage*)request
                  completionOption:(WWHHttpCompletionOption)completionOption
                           success:(void (^)(WWHHttpResponseMessage*))success
                          progress:(void (^)(WWHHttpProgress*))progress
                           failure:(void (^)(NSError*))failure;
- (void)close;
- (NSString*)toString;
@end

#endif // __WWHHttpClient_DEFINED__

// Windows.Web.Http.HttpCookie
#ifndef __WWHHttpCookie_DEFINED__
#define __WWHHttpCookie_DEFINED__

WINRT_EXPORT
@interface WWHHttpCookie : RTObject <WFIStringable>
+ (WWHHttpCookie*)create:(NSString*)name domain:(NSString*)domain path:(NSString*)path ACTIVATOR;
@property (copy) NSString* value;
@property BOOL secure;
@property BOOL httpOnly;
@property (copy) WFDateTime* expires;
@property (readonly) NSString* domain;
@property (readonly) NSString* name;
@property (readonly) NSString* path;
- (NSString*)toString;
@end

#endif // __WWHHttpCookie_DEFINED__

// Windows.Web.Http.HttpCookieCollection
#ifndef __WWHHttpCookieCollection_DEFINED__
#define __WWHHttpCookieCollection_DEFINED__

WINRT_EXPORT
@interface WWHHttpCookieCollection : RTObject
@property (readonly) unsigned size;
@end

#endif // __WWHHttpCookieCollection_DEFINED__

// Windows.Web.Http.HttpMethod
#ifndef __WWHHttpMethod_DEFINED__
#define __WWHHttpMethod_DEFINED__

WINRT_EXPORT
@interface WWHHttpMethod : RTObject <WFIStringable>
+ (WWHHttpMethod*)create:(NSString*)method ACTIVATOR;
@property (readonly) NSString* method;
+ (WWHHttpMethod*)Delete;
+ (WWHHttpMethod*)get;
+ (WWHHttpMethod*)head;
+ (WWHHttpMethod*)options;
+ (WWHHttpMethod*)patch;
+ (WWHHttpMethod*)post;
+ (WWHHttpMethod*)put;
- (NSString*)toString;
@end

#endif // __WWHHttpMethod_DEFINED__

// Windows.Web.Http.HttpTransportInformation
#ifndef __WWHHttpTransportInformation_DEFINED__
#define __WWHHttpTransportInformation_DEFINED__

WINRT_EXPORT
@interface WWHHttpTransportInformation : RTObject <WFIStringable>
@property (readonly) WSCCCertificate* serverCertificate;
@property (readonly) WNSSocketSslErrorSeverity serverCertificateErrorSeverity;
@property (readonly) id<NSFastEnumeration> /*WSCCChainValidationResult*/ serverCertificateErrors;
@property (readonly) id<NSFastEnumeration> /*WSCCCertificate*/ serverIntermediateCertificates;
- (NSString*)toString;
@end

#endif // __WWHHttpTransportInformation_DEFINED__

// Windows.Web.Http.HttpStringContent
#ifndef __WWHHttpStringContent_DEFINED__
#define __WWHHttpStringContent_DEFINED__

WINRT_EXPORT
@interface WWHHttpStringContent : RTObject <WWHIHttpContent, WFIClosable, WFIStringable>
+ (WWHHttpStringContent*)createFromString:(NSString*)content ACTIVATOR;
+ (WWHHttpStringContent*)createFromStringWithEncoding:(NSString*)content encoding:(WSSUnicodeEncoding)encoding ACTIVATOR;
+ (WWHHttpStringContent*)createFromStringWithEncodingAndMediaType:(NSString*)content
                                                         encoding:(WSSUnicodeEncoding)encoding
                                                        mediaType:(NSString*)mediaType ACTIVATOR;
@property (readonly) WWHHHttpContentHeaderCollection* headers;
- (void)bufferAllAsyncWithSuccess:(void (^)(uint64_t))success progress:(void (^)(uint64_t))progress failure:(void (^)(NSError*))failure;
- (void)readAsBufferAsyncWithSuccess:(void (^)(RTObject<WSSIBuffer>*))success
                            progress:(void (^)(uint64_t))progress
                             failure:(void (^)(NSError*))failure;
- (void)readAsInputStreamAsyncWithSuccess:(void (^)(RTObject<WSSIInputStream>*))success
                                 progress:(void (^)(uint64_t))progress
                                  failure:(void (^)(NSError*))failure;
- (void)readAsStringAsyncWithSuccess:(void (^)(NSString*))success progress:(void (^)(uint64_t))progress failure:(void (^)(NSError*))failure;
- (BOOL)tryComputeLength:(uint64_t*)length;
- (void)writeToStreamAsync:(RTObject<WSSIOutputStream>*)outputStream
                   success:(void (^)(uint64_t))success
                  progress:(void (^)(uint64_t))progress
                   failure:(void (^)(NSError*))failure;
- (void)close;
- (NSString*)toString;
@end

#endif // __WWHHttpStringContent_DEFINED__

// Windows.Web.Http.HttpBufferContent
#ifndef __WWHHttpBufferContent_DEFINED__
#define __WWHHttpBufferContent_DEFINED__

WINRT_EXPORT
@interface WWHHttpBufferContent : RTObject <WWHIHttpContent, WFIClosable, WFIStringable>
+ (WWHHttpBufferContent*)createFromBuffer:(RTObject<WSSIBuffer>*)content ACTIVATOR;
+ (WWHHttpBufferContent*)createFromBufferWithOffset:(RTObject<WSSIBuffer>*)content offset:(unsigned)offset count:(unsigned)count ACTIVATOR;
@property (readonly) WWHHHttpContentHeaderCollection* headers;
- (void)bufferAllAsyncWithSuccess:(void (^)(uint64_t))success progress:(void (^)(uint64_t))progress failure:(void (^)(NSError*))failure;
- (void)readAsBufferAsyncWithSuccess:(void (^)(RTObject<WSSIBuffer>*))success
                            progress:(void (^)(uint64_t))progress
                             failure:(void (^)(NSError*))failure;
- (void)readAsInputStreamAsyncWithSuccess:(void (^)(RTObject<WSSIInputStream>*))success
                                 progress:(void (^)(uint64_t))progress
                                  failure:(void (^)(NSError*))failure;
- (void)readAsStringAsyncWithSuccess:(void (^)(NSString*))success progress:(void (^)(uint64_t))progress failure:(void (^)(NSError*))failure;
- (BOOL)tryComputeLength:(uint64_t*)length;
- (void)writeToStreamAsync:(RTObject<WSSIOutputStream>*)outputStream
                   success:(void (^)(uint64_t))success
                  progress:(void (^)(uint64_t))progress
                   failure:(void (^)(NSError*))failure;
- (void)close;
- (NSString*)toString;
@end

#endif // __WWHHttpBufferContent_DEFINED__

// Windows.Web.Http.HttpStreamContent
#ifndef __WWHHttpStreamContent_DEFINED__
#define __WWHHttpStreamContent_DEFINED__

WINRT_EXPORT
@interface WWHHttpStreamContent : RTObject <WWHIHttpContent, WFIClosable, WFIStringable>
+ (WWHHttpStreamContent*)createFromInputStream:(RTObject<WSSIInputStream>*)content ACTIVATOR;
@property (readonly) WWHHHttpContentHeaderCollection* headers;
- (void)bufferAllAsyncWithSuccess:(void (^)(uint64_t))success progress:(void (^)(uint64_t))progress failure:(void (^)(NSError*))failure;
- (void)readAsBufferAsyncWithSuccess:(void (^)(RTObject<WSSIBuffer>*))success
                            progress:(void (^)(uint64_t))progress
                             failure:(void (^)(NSError*))failure;
- (void)readAsInputStreamAsyncWithSuccess:(void (^)(RTObject<WSSIInputStream>*))success
                                 progress:(void (^)(uint64_t))progress
                                  failure:(void (^)(NSError*))failure;
- (void)readAsStringAsyncWithSuccess:(void (^)(NSString*))success progress:(void (^)(uint64_t))progress failure:(void (^)(NSError*))failure;
- (BOOL)tryComputeLength:(uint64_t*)length;
- (void)writeToStreamAsync:(RTObject<WSSIOutputStream>*)outputStream
                   success:(void (^)(uint64_t))success
                  progress:(void (^)(uint64_t))progress
                   failure:(void (^)(NSError*))failure;
- (void)close;
- (NSString*)toString;
@end

#endif // __WWHHttpStreamContent_DEFINED__

// Windows.Web.Http.HttpFormUrlEncodedContent
#ifndef __WWHHttpFormUrlEncodedContent_DEFINED__
#define __WWHHttpFormUrlEncodedContent_DEFINED__

WINRT_EXPORT
@interface WWHHttpFormUrlEncodedContent : RTObject <WWHIHttpContent, WFIClosable, WFIStringable>
// Could not generate Create (Can't marshal Windows.Foundation.Collections.IKeyValuePair`2<String,String>)
@property (readonly) WWHHHttpContentHeaderCollection* headers;
- (void)bufferAllAsyncWithSuccess:(void (^)(uint64_t))success progress:(void (^)(uint64_t))progress failure:(void (^)(NSError*))failure;
- (void)readAsBufferAsyncWithSuccess:(void (^)(RTObject<WSSIBuffer>*))success
                            progress:(void (^)(uint64_t))progress
                             failure:(void (^)(NSError*))failure;
- (void)readAsInputStreamAsyncWithSuccess:(void (^)(RTObject<WSSIInputStream>*))success
                                 progress:(void (^)(uint64_t))progress
                                  failure:(void (^)(NSError*))failure;
- (void)readAsStringAsyncWithSuccess:(void (^)(NSString*))success progress:(void (^)(uint64_t))progress failure:(void (^)(NSError*))failure;
- (BOOL)tryComputeLength:(uint64_t*)length;
- (void)writeToStreamAsync:(RTObject<WSSIOutputStream>*)outputStream
                   success:(void (^)(uint64_t))success
                  progress:(void (^)(uint64_t))progress
                   failure:(void (^)(NSError*))failure;
- (void)close;
- (NSString*)toString;
@end

#endif // __WWHHttpFormUrlEncodedContent_DEFINED__

// Windows.Web.Http.HttpMultipartContent
#ifndef __WWHHttpMultipartContent_DEFINED__
#define __WWHHttpMultipartContent_DEFINED__

WINRT_EXPORT
@interface WWHHttpMultipartContent : RTObject <WWHIHttpContent, WFIClosable, WFIStringable>
+ (WWHHttpMultipartContent*)createWithSubtype:(NSString*)subtype ACTIVATOR;
+ (WWHHttpMultipartContent*)createWithSubtypeAndBoundary:(NSString*)subtype boundary:(NSString*)boundary ACTIVATOR;
+ (instancetype)create ACTIVATOR;
@property (readonly) WWHHHttpContentHeaderCollection* headers;
- (void)bufferAllAsyncWithSuccess:(void (^)(uint64_t))success progress:(void (^)(uint64_t))progress failure:(void (^)(NSError*))failure;
- (void)readAsBufferAsyncWithSuccess:(void (^)(RTObject<WSSIBuffer>*))success
                            progress:(void (^)(uint64_t))progress
                             failure:(void (^)(NSError*))failure;
- (void)readAsInputStreamAsyncWithSuccess:(void (^)(RTObject<WSSIInputStream>*))success
                                 progress:(void (^)(uint64_t))progress
                                  failure:(void (^)(NSError*))failure;
- (void)readAsStringAsyncWithSuccess:(void (^)(NSString*))success progress:(void (^)(uint64_t))progress failure:(void (^)(NSError*))failure;
- (BOOL)tryComputeLength:(uint64_t*)length;
- (void)writeToStreamAsync:(RTObject<WSSIOutputStream>*)outputStream
                   success:(void (^)(uint64_t))success
                  progress:(void (^)(uint64_t))progress
                   failure:(void (^)(NSError*))failure;
- (void)close;
- (void)add:(RTObject<WWHIHttpContent>*)content;
- (NSString*)toString;
@end

#endif // __WWHHttpMultipartContent_DEFINED__

// Windows.Web.Http.HttpMultipartFormDataContent
#ifndef __WWHHttpMultipartFormDataContent_DEFINED__
#define __WWHHttpMultipartFormDataContent_DEFINED__

WINRT_EXPORT
@interface WWHHttpMultipartFormDataContent : RTObject <WWHIHttpContent, WFIClosable, WFIStringable>
+ (WWHHttpMultipartFormDataContent*)createWithBoundary:(NSString*)boundary ACTIVATOR;
+ (instancetype)create ACTIVATOR;
@property (readonly) WWHHHttpContentHeaderCollection* headers;
- (void)bufferAllAsyncWithSuccess:(void (^)(uint64_t))success progress:(void (^)(uint64_t))progress failure:(void (^)(NSError*))failure;
- (void)readAsBufferAsyncWithSuccess:(void (^)(RTObject<WSSIBuffer>*))success
                            progress:(void (^)(uint64_t))progress
                             failure:(void (^)(NSError*))failure;
- (void)readAsInputStreamAsyncWithSuccess:(void (^)(RTObject<WSSIInputStream>*))success
                                 progress:(void (^)(uint64_t))progress
                                  failure:(void (^)(NSError*))failure;
- (void)readAsStringAsyncWithSuccess:(void (^)(NSString*))success progress:(void (^)(uint64_t))progress failure:(void (^)(NSError*))failure;
- (BOOL)tryComputeLength:(uint64_t*)length;
- (void)writeToStreamAsync:(RTObject<WSSIOutputStream>*)outputStream
                   success:(void (^)(uint64_t))success
                  progress:(void (^)(uint64_t))progress
                   failure:(void (^)(NSError*))failure;
- (void)close;
- (void)add:(RTObject<WWHIHttpContent>*)content;
- (void)addWithName:(RTObject<WWHIHttpContent>*)content name:(NSString*)name;
- (void)addWithNameAndFileName:(RTObject<WWHIHttpContent>*)content name:(NSString*)name fileName:(NSString*)fileName;
- (NSString*)toString;
@end

#endif // __WWHHttpMultipartFormDataContent_DEFINED__

// Windows.Web.Http.HttpCookieManager
#ifndef __WWHHttpCookieManager_DEFINED__
#define __WWHHttpCookieManager_DEFINED__

WINRT_EXPORT
@interface WWHHttpCookieManager : RTObject
- (BOOL)setCookie:(WWHHttpCookie*)cookie;
- (BOOL)setCookieWithThirdParty:(WWHHttpCookie*)cookie thirdParty:(BOOL)thirdParty;
- (void)deleteCookie:(WWHHttpCookie*)cookie;
- (WWHHttpCookieCollection*)getCookies:(WFUri*)uri;
@end

#endif // __WWHHttpCookieManager_DEFINED__
