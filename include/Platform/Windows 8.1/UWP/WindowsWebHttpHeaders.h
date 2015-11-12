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

// WindowsWebHttpHeaders.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WWHHHttpContentHeaderCollection, WWHHHttpRequestHeaderCollection, WWHHHttpResponseHeaderCollection,
    WWHHHttpContentDispositionHeaderValue, WWHHHttpContentCodingHeaderValueCollection, WWHHHttpLanguageHeaderValueCollection,
    WWHHHttpContentRangeHeaderValue, WWHHHttpMediaTypeHeaderValue, WWHHHttpMediaTypeWithQualityHeaderValueCollection,
    WWHHHttpContentCodingWithQualityHeaderValueCollection, WWHHHttpLanguageRangeWithQualityHeaderValueCollection,
    WWHHHttpCredentialsHeaderValue, WWHHHttpCacheDirectiveHeaderValueCollection, WWHHHttpConnectionOptionHeaderValueCollection,
    WWHHHttpCookiePairHeaderValueCollection, WWHHHttpExpectationHeaderValueCollection, WWHHHttpTransferCodingHeaderValueCollection,
    WWHHHttpProductInfoHeaderValueCollection, WWHHHttpMethodHeaderValueCollection, WWHHHttpChallengeHeaderValueCollection,
    WWHHHttpDateOrDeltaHeaderValue, WWHHHttpNameValueHeaderValue, WWHHHttpChallengeHeaderValue, WWHHHttpConnectionOptionHeaderValue,
    WWHHHttpContentCodingHeaderValue, WWHHHttpCookiePairHeaderValue, WWHHHttpExpectationHeaderValue,
    WWHHHttpLanguageRangeWithQualityHeaderValue, WWHHHttpMediaTypeWithQualityHeaderValue, WWHHHttpProductHeaderValue,
    WWHHHttpProductInfoHeaderValue, WWHHHttpContentCodingWithQualityHeaderValue, WWHHHttpTransferCodingHeaderValue;
@protocol WWHHIHttpContentHeaderCollection
, WWHHIHttpRequestHeaderCollection, WWHHIHttpResponseHeaderCollection, WWHHIHttpCacheDirectiveHeaderValueCollection,
    WWHHIHttpChallengeHeaderValueStatics, WWHHIHttpChallengeHeaderValueFactory, WWHHIHttpChallengeHeaderValue,
    WWHHIHttpChallengeHeaderValueCollection, WWHHIHttpCredentialsHeaderValueStatics, WWHHIHttpCredentialsHeaderValueFactory,
    WWHHIHttpCredentialsHeaderValue, WWHHIHttpConnectionOptionHeaderValueStatics, WWHHIHttpConnectionOptionHeaderValueFactory,
    WWHHIHttpConnectionOptionHeaderValue, WWHHIHttpConnectionOptionHeaderValueCollection, WWHHIHttpContentCodingHeaderValueStatics,
    WWHHIHttpContentCodingHeaderValueFactory, WWHHIHttpContentCodingHeaderValue, WWHHIHttpContentCodingHeaderValueCollection,
    WWHHIHttpContentDispositionHeaderValueStatics, WWHHIHttpContentDispositionHeaderValueFactory, WWHHIHttpContentDispositionHeaderValue,
    WWHHIHttpContentRangeHeaderValueStatics, WWHHIHttpContentRangeHeaderValueFactory, WWHHIHttpContentRangeHeaderValue,
    WWHHIHttpCookiePairHeaderValueStatics, WWHHIHttpCookiePairHeaderValueFactory, WWHHIHttpCookiePairHeaderValue,
    WWHHIHttpCookiePairHeaderValueCollection, WWHHIHttpDateOrDeltaHeaderValueStatics, WWHHIHttpDateOrDeltaHeaderValue,
    WWHHIHttpExpectationHeaderValueStatics, WWHHIHttpExpectationHeaderValueFactory, WWHHIHttpExpectationHeaderValue,
    WWHHIHttpExpectationHeaderValueCollection, WWHHIHttpLanguageHeaderValueCollection, WWHHIHttpLanguageRangeWithQualityHeaderValueStatics,
    WWHHIHttpLanguageRangeWithQualityHeaderValueFactory, WWHHIHttpLanguageRangeWithQualityHeaderValue,
    WWHHIHttpLanguageRangeWithQualityHeaderValueCollection, WWHHIHttpMediaTypeHeaderValueStatics, WWHHIHttpMediaTypeHeaderValueFactory,
    WWHHIHttpMediaTypeHeaderValue, WWHHIHttpMediaTypeWithQualityHeaderValueStatics, WWHHIHttpMediaTypeWithQualityHeaderValueFactory,
    WWHHIHttpMediaTypeWithQualityHeaderValue, WWHHIHttpMediaTypeWithQualityHeaderValueCollection, WWHHIHttpMethodHeaderValueCollection,
    WWHHIHttpNameValueHeaderValueStatics, WWHHIHttpNameValueHeaderValueFactory, WWHHIHttpNameValueHeaderValue,
    WWHHIHttpProductHeaderValueStatics, WWHHIHttpProductHeaderValueFactory, WWHHIHttpProductHeaderValue,
    WWHHIHttpProductInfoHeaderValueStatics, WWHHIHttpProductInfoHeaderValueFactory, WWHHIHttpProductInfoHeaderValue,
    WWHHIHttpProductInfoHeaderValueCollection, WWHHIHttpContentCodingWithQualityHeaderValueStatics,
    WWHHIHttpContentCodingWithQualityHeaderValueFactory, WWHHIHttpContentCodingWithQualityHeaderValue,
    WWHHIHttpContentCodingWithQualityHeaderValueCollection, WWHHIHttpTransferCodingHeaderValueStatics,
    WWHHIHttpTransferCodingHeaderValueFactory, WWHHIHttpTransferCodingHeaderValue, WWHHIHttpTransferCodingHeaderValueCollection;

#include "WindowsStorageStreams.h"
#include "WindowsFoundationCollections.h"
#include "WindowsFoundation.h"
#include "WindowsWebHttp.h"
#include "WindowsNetworking.h"
#include "WindowsGlobalization.h"

// Windows.Foundation.IStringable
#ifndef __WFIStringable_DEFINED__
#define __WFIStringable_DEFINED__

@protocol WFIStringable
- (NSString*)toString;
@end

#endif // __WFIStringable_DEFINED__

// Windows.Web.Http.Headers.HttpContentHeaderCollection
#ifndef __WWHHHttpContentHeaderCollection_DEFINED__
#define __WWHHHttpContentHeaderCollection_DEFINED__

WINRT_EXPORT
@interface WWHHHttpContentHeaderCollection : RTObject <WFIStringable>
+ (instancetype)create ACTIVATOR;
@property (readonly) unsigned size;
@property (copy) WFDateTime* lastModified;
@property (copy) WFDateTime* expires;
@property (copy) WWHHHttpMediaTypeHeaderValue* contentType;
@property (copy) WWHHHttpContentRangeHeaderValue* contentRange;
@property (copy) RTObject<WSSIBuffer>* contentMD5;
@property (copy) WFUri* contentLocation;
@property (copy) NSNumber* contentLength;
@property (copy) WWHHHttpContentDispositionHeaderValue* contentDisposition;
@property (readonly) WWHHHttpContentCodingHeaderValueCollection* contentEncoding;
@property (readonly) WWHHHttpLanguageHeaderValueCollection* contentLanguage;
- (void)append:(NSString*)name value:(NSString*)value;
- (BOOL)tryAppendWithoutValidation:(NSString*)name value:(NSString*)value;
// Could not find base class Windows.Foundation.Collections.IMap`2<String,String> type information
// Could not find base class Windows.Foundation.Collections.IMap`2<String,String> type information
- (NSString*)toString;
@end

#endif // __WWHHHttpContentHeaderCollection_DEFINED__

// Windows.Web.Http.Headers.HttpRequestHeaderCollection
#ifndef __WWHHHttpRequestHeaderCollection_DEFINED__
#define __WWHHHttpRequestHeaderCollection_DEFINED__

WINRT_EXPORT
@interface WWHHHttpRequestHeaderCollection : RTObject <WFIStringable>
@property (readonly) unsigned size;
@property (copy) WFDateTime* date;
@property (copy) WWHHHttpCredentialsHeaderValue* authorization;
@property (copy) NSString* from;
@property (copy) WFUri* referer;
@property (copy) WWHHHttpCredentialsHeaderValue* proxyAuthorization;
@property (copy) NSNumber* maxForwards;
@property (copy) WFDateTime* ifUnmodifiedSince;
@property (copy) WFDateTime* ifModifiedSince;
@property (copy) WNHostName* host;
@property (readonly) WWHHHttpMediaTypeWithQualityHeaderValueCollection* accept;
@property (readonly) WWHHHttpContentCodingWithQualityHeaderValueCollection* acceptEncoding;
@property (readonly) WWHHHttpLanguageRangeWithQualityHeaderValueCollection* acceptLanguage;
@property (readonly) WWHHHttpCacheDirectiveHeaderValueCollection* cacheControl;
@property (readonly) WWHHHttpConnectionOptionHeaderValueCollection* connection;
@property (readonly) WWHHHttpCookiePairHeaderValueCollection* cookie;
@property (readonly) WWHHHttpTransferCodingHeaderValueCollection* transferEncoding;
@property (readonly) WWHHHttpProductInfoHeaderValueCollection* userAgent;
@property (readonly) WWHHHttpExpectationHeaderValueCollection* expect;
- (void)append:(NSString*)name value:(NSString*)value;
- (BOOL)tryAppendWithoutValidation:(NSString*)name value:(NSString*)value;
// Could not find base class Windows.Foundation.Collections.IMap`2<String,String> type information
// Could not find base class Windows.Foundation.Collections.IMap`2<String,String> type information
- (NSString*)toString;
@end

#endif // __WWHHHttpRequestHeaderCollection_DEFINED__

// Windows.Web.Http.Headers.HttpResponseHeaderCollection
#ifndef __WWHHHttpResponseHeaderCollection_DEFINED__
#define __WWHHHttpResponseHeaderCollection_DEFINED__

WINRT_EXPORT
@interface WWHHHttpResponseHeaderCollection : RTObject <WFIStringable>
@property (readonly) unsigned size;
@property (copy) WWHHHttpDateOrDeltaHeaderValue* retryAfter;
@property (copy) WFUri* location;
@property (copy) WFDateTime* date;
@property (copy) WFTimeSpan* age;
@property (readonly) WWHHHttpMethodHeaderValueCollection* allow;
@property (readonly) WWHHHttpCacheDirectiveHeaderValueCollection* cacheControl;
@property (readonly) WWHHHttpConnectionOptionHeaderValueCollection* connection;
@property (readonly) WWHHHttpChallengeHeaderValueCollection* proxyAuthenticate;
@property (readonly) WWHHHttpTransferCodingHeaderValueCollection* transferEncoding;
@property (readonly) WWHHHttpChallengeHeaderValueCollection* wwwAuthenticate;
- (void)append:(NSString*)name value:(NSString*)value;
- (BOOL)tryAppendWithoutValidation:(NSString*)name value:(NSString*)value;
// Could not find base class Windows.Foundation.Collections.IMap`2<String,String> type information
// Could not find base class Windows.Foundation.Collections.IMap`2<String,String> type information
- (NSString*)toString;
@end

#endif // __WWHHHttpResponseHeaderCollection_DEFINED__

// Windows.Web.Http.Headers.HttpContentDispositionHeaderValue
#ifndef __WWHHHttpContentDispositionHeaderValue_DEFINED__
#define __WWHHHttpContentDispositionHeaderValue_DEFINED__

WINRT_EXPORT
@interface WWHHHttpContentDispositionHeaderValue : RTObject <WFIStringable>
+ (WWHHHttpContentDispositionHeaderValue*)parse:(NSString*)input;
+ (BOOL)tryParse:(NSString*)input contentDispositionHeaderValue:(WWHHHttpContentDispositionHeaderValue**)contentDispositionHeaderValue;
+ (WWHHHttpContentDispositionHeaderValue*)create:(NSString*)dispositionType ACTIVATOR;
@property (copy) NSNumber* size;
@property (copy) NSString* name;
@property (copy) NSString* fileNameStar;
@property (copy) NSString* fileName;
@property (copy) NSString* dispositionType;
@property (readonly) id<NSFastEnumeration> /*WWHHHttpNameValueHeaderValue*/ parameters;
- (NSString*)toString;
@end

#endif // __WWHHHttpContentDispositionHeaderValue_DEFINED__

// Windows.Web.Http.Headers.HttpContentCodingHeaderValueCollection
#ifndef __WWHHHttpContentCodingHeaderValueCollection_DEFINED__
#define __WWHHHttpContentCodingHeaderValueCollection_DEFINED__

WINRT_EXPORT
@interface WWHHHttpContentCodingHeaderValueCollection : RTObject <WFIStringable>
@property (readonly) unsigned size;
- (void)parseAdd:(NSString*)input;
- (BOOL)tryParseAdd:(NSString*)input;
- (NSString*)toString;
@end

#endif // __WWHHHttpContentCodingHeaderValueCollection_DEFINED__

// Windows.Web.Http.Headers.HttpLanguageHeaderValueCollection
#ifndef __WWHHHttpLanguageHeaderValueCollection_DEFINED__
#define __WWHHHttpLanguageHeaderValueCollection_DEFINED__

WINRT_EXPORT
@interface WWHHHttpLanguageHeaderValueCollection : RTObject <WFIStringable>
@property (readonly) unsigned size;
- (void)parseAdd:(NSString*)input;
- (BOOL)tryParseAdd:(NSString*)input;
- (NSString*)toString;
@end

#endif // __WWHHHttpLanguageHeaderValueCollection_DEFINED__

// Windows.Web.Http.Headers.HttpContentRangeHeaderValue
#ifndef __WWHHHttpContentRangeHeaderValue_DEFINED__
#define __WWHHHttpContentRangeHeaderValue_DEFINED__

WINRT_EXPORT
@interface WWHHHttpContentRangeHeaderValue : RTObject <WFIStringable>
+ (WWHHHttpContentRangeHeaderValue*)parse:(NSString*)input;
+ (BOOL)tryParse:(NSString*)input contentRangeHeaderValue:(WWHHHttpContentRangeHeaderValue**)contentRangeHeaderValue;
+ (WWHHHttpContentRangeHeaderValue*)createFromLength:(uint64_t)length ACTIVATOR;
+ (WWHHHttpContentRangeHeaderValue*)createFromRange:(uint64_t)from to:(uint64_t)to ACTIVATOR;
+ (WWHHHttpContentRangeHeaderValue*)createFromRangeWithLength:(uint64_t)from to:(uint64_t)to length:(uint64_t)length ACTIVATOR;
@property (copy) NSString* unit;
@property (readonly) NSNumber* firstBytePosition;
@property (readonly) NSNumber* lastBytePosition;
@property (readonly) NSNumber* length;
- (NSString*)toString;
@end

#endif // __WWHHHttpContentRangeHeaderValue_DEFINED__

// Windows.Web.Http.Headers.HttpMediaTypeHeaderValue
#ifndef __WWHHHttpMediaTypeHeaderValue_DEFINED__
#define __WWHHHttpMediaTypeHeaderValue_DEFINED__

WINRT_EXPORT
@interface WWHHHttpMediaTypeHeaderValue : RTObject <WFIStringable>
+ (WWHHHttpMediaTypeHeaderValue*)parse:(NSString*)input;
+ (BOOL)tryParse:(NSString*)input mediaTypeHeaderValue:(WWHHHttpMediaTypeHeaderValue**)mediaTypeHeaderValue;
+ (WWHHHttpMediaTypeHeaderValue*)create:(NSString*)mediaType ACTIVATOR;
@property (copy) NSString* mediaType;
@property (copy) NSString* charSet;
@property (readonly) id<NSFastEnumeration> /*WWHHHttpNameValueHeaderValue*/ parameters;
- (NSString*)toString;
@end

#endif // __WWHHHttpMediaTypeHeaderValue_DEFINED__

// Windows.Web.Http.Headers.HttpMediaTypeWithQualityHeaderValueCollection
#ifndef __WWHHHttpMediaTypeWithQualityHeaderValueCollection_DEFINED__
#define __WWHHHttpMediaTypeWithQualityHeaderValueCollection_DEFINED__

WINRT_EXPORT
@interface WWHHHttpMediaTypeWithQualityHeaderValueCollection : RTObject <WFIStringable>
@property (readonly) unsigned size;
- (void)parseAdd:(NSString*)input;
- (BOOL)tryParseAdd:(NSString*)input;
- (NSString*)toString;
@end

#endif // __WWHHHttpMediaTypeWithQualityHeaderValueCollection_DEFINED__

// Windows.Web.Http.Headers.HttpContentCodingWithQualityHeaderValueCollection
#ifndef __WWHHHttpContentCodingWithQualityHeaderValueCollection_DEFINED__
#define __WWHHHttpContentCodingWithQualityHeaderValueCollection_DEFINED__

WINRT_EXPORT
@interface WWHHHttpContentCodingWithQualityHeaderValueCollection : RTObject <WFIStringable>
@property (readonly) unsigned size;
- (void)parseAdd:(NSString*)input;
- (BOOL)tryParseAdd:(NSString*)input;
- (NSString*)toString;
@end

#endif // __WWHHHttpContentCodingWithQualityHeaderValueCollection_DEFINED__

// Windows.Web.Http.Headers.HttpLanguageRangeWithQualityHeaderValueCollection
#ifndef __WWHHHttpLanguageRangeWithQualityHeaderValueCollection_DEFINED__
#define __WWHHHttpLanguageRangeWithQualityHeaderValueCollection_DEFINED__

WINRT_EXPORT
@interface WWHHHttpLanguageRangeWithQualityHeaderValueCollection : RTObject <WFIStringable>
@property (readonly) unsigned size;
- (void)parseAdd:(NSString*)input;
- (BOOL)tryParseAdd:(NSString*)input;
- (NSString*)toString;
@end

#endif // __WWHHHttpLanguageRangeWithQualityHeaderValueCollection_DEFINED__

// Windows.Web.Http.Headers.HttpCredentialsHeaderValue
#ifndef __WWHHHttpCredentialsHeaderValue_DEFINED__
#define __WWHHHttpCredentialsHeaderValue_DEFINED__

WINRT_EXPORT
@interface WWHHHttpCredentialsHeaderValue : RTObject <WFIStringable>
+ (WWHHHttpCredentialsHeaderValue*)parse:(NSString*)input;
+ (BOOL)tryParse:(NSString*)input credentialsHeaderValue:(WWHHHttpCredentialsHeaderValue**)credentialsHeaderValue;
+ (WWHHHttpCredentialsHeaderValue*)createFromScheme:(NSString*)scheme ACTIVATOR;
+ (WWHHHttpCredentialsHeaderValue*)createFromSchemeWithToken:(NSString*)scheme token:(NSString*)token ACTIVATOR;
@property (readonly) id<NSFastEnumeration> /*WWHHHttpNameValueHeaderValue*/ parameters;
@property (readonly) NSString* scheme;
@property (readonly) NSString* token;
- (NSString*)toString;
@end

#endif // __WWHHHttpCredentialsHeaderValue_DEFINED__

// Windows.Web.Http.Headers.HttpCacheDirectiveHeaderValueCollection
#ifndef __WWHHHttpCacheDirectiveHeaderValueCollection_DEFINED__
#define __WWHHHttpCacheDirectiveHeaderValueCollection_DEFINED__

WINRT_EXPORT
@interface WWHHHttpCacheDirectiveHeaderValueCollection : RTObject <WFIStringable>
@property (readonly) unsigned size;
@property (copy) WFTimeSpan* sharedMaxAge;
@property (copy) WFTimeSpan* minFresh;
@property (copy) WFTimeSpan* maxStale;
@property (copy) WFTimeSpan* maxAge;
- (void)parseAdd:(NSString*)input;
- (BOOL)tryParseAdd:(NSString*)input;
- (NSString*)toString;
@end

#endif // __WWHHHttpCacheDirectiveHeaderValueCollection_DEFINED__

// Windows.Web.Http.Headers.HttpConnectionOptionHeaderValueCollection
#ifndef __WWHHHttpConnectionOptionHeaderValueCollection_DEFINED__
#define __WWHHHttpConnectionOptionHeaderValueCollection_DEFINED__

WINRT_EXPORT
@interface WWHHHttpConnectionOptionHeaderValueCollection : RTObject <WFIStringable>
@property (readonly) unsigned size;
- (void)parseAdd:(NSString*)input;
- (BOOL)tryParseAdd:(NSString*)input;
- (NSString*)toString;
@end

#endif // __WWHHHttpConnectionOptionHeaderValueCollection_DEFINED__

// Windows.Web.Http.Headers.HttpCookiePairHeaderValueCollection
#ifndef __WWHHHttpCookiePairHeaderValueCollection_DEFINED__
#define __WWHHHttpCookiePairHeaderValueCollection_DEFINED__

WINRT_EXPORT
@interface WWHHHttpCookiePairHeaderValueCollection : RTObject <WFIStringable>
@property (readonly) unsigned size;
- (void)parseAdd:(NSString*)input;
- (BOOL)tryParseAdd:(NSString*)input;
- (NSString*)toString;
@end

#endif // __WWHHHttpCookiePairHeaderValueCollection_DEFINED__

// Windows.Web.Http.Headers.HttpExpectationHeaderValueCollection
#ifndef __WWHHHttpExpectationHeaderValueCollection_DEFINED__
#define __WWHHHttpExpectationHeaderValueCollection_DEFINED__

WINRT_EXPORT
@interface WWHHHttpExpectationHeaderValueCollection : RTObject <WFIStringable>
@property (readonly) unsigned size;
- (void)parseAdd:(NSString*)input;
- (BOOL)tryParseAdd:(NSString*)input;
- (NSString*)toString;
@end

#endif // __WWHHHttpExpectationHeaderValueCollection_DEFINED__

// Windows.Web.Http.Headers.HttpTransferCodingHeaderValueCollection
#ifndef __WWHHHttpTransferCodingHeaderValueCollection_DEFINED__
#define __WWHHHttpTransferCodingHeaderValueCollection_DEFINED__

WINRT_EXPORT
@interface WWHHHttpTransferCodingHeaderValueCollection : RTObject <WFIStringable>
@property (readonly) unsigned size;
- (void)parseAdd:(NSString*)input;
- (BOOL)tryParseAdd:(NSString*)input;
- (NSString*)toString;
@end

#endif // __WWHHHttpTransferCodingHeaderValueCollection_DEFINED__

// Windows.Web.Http.Headers.HttpProductInfoHeaderValueCollection
#ifndef __WWHHHttpProductInfoHeaderValueCollection_DEFINED__
#define __WWHHHttpProductInfoHeaderValueCollection_DEFINED__

WINRT_EXPORT
@interface WWHHHttpProductInfoHeaderValueCollection : RTObject <WFIStringable>
@property (readonly) unsigned size;
- (void)parseAdd:(NSString*)input;
- (BOOL)tryParseAdd:(NSString*)input;
- (NSString*)toString;
@end

#endif // __WWHHHttpProductInfoHeaderValueCollection_DEFINED__

// Windows.Web.Http.Headers.HttpMethodHeaderValueCollection
#ifndef __WWHHHttpMethodHeaderValueCollection_DEFINED__
#define __WWHHHttpMethodHeaderValueCollection_DEFINED__

WINRT_EXPORT
@interface WWHHHttpMethodHeaderValueCollection : RTObject <WFIStringable>
@property (readonly) unsigned size;
- (void)parseAdd:(NSString*)input;
- (BOOL)tryParseAdd:(NSString*)input;
- (NSString*)toString;
@end

#endif // __WWHHHttpMethodHeaderValueCollection_DEFINED__

// Windows.Web.Http.Headers.HttpChallengeHeaderValueCollection
#ifndef __WWHHHttpChallengeHeaderValueCollection_DEFINED__
#define __WWHHHttpChallengeHeaderValueCollection_DEFINED__

WINRT_EXPORT
@interface WWHHHttpChallengeHeaderValueCollection : RTObject <WFIStringable>
@property (readonly) unsigned size;
- (void)parseAdd:(NSString*)input;
- (BOOL)tryParseAdd:(NSString*)input;
- (NSString*)toString;
@end

#endif // __WWHHHttpChallengeHeaderValueCollection_DEFINED__

// Windows.Web.Http.Headers.HttpDateOrDeltaHeaderValue
#ifndef __WWHHHttpDateOrDeltaHeaderValue_DEFINED__
#define __WWHHHttpDateOrDeltaHeaderValue_DEFINED__

WINRT_EXPORT
@interface WWHHHttpDateOrDeltaHeaderValue : RTObject <WFIStringable>
+ (WWHHHttpDateOrDeltaHeaderValue*)parse:(NSString*)input;
+ (BOOL)tryParse:(NSString*)input dateOrDeltaHeaderValue:(WWHHHttpDateOrDeltaHeaderValue**)dateOrDeltaHeaderValue;
@property (readonly) WFDateTime* date;
@property (readonly) WFTimeSpan* delta;
- (NSString*)toString;
@end

#endif // __WWHHHttpDateOrDeltaHeaderValue_DEFINED__

// Windows.Web.Http.Headers.HttpNameValueHeaderValue
#ifndef __WWHHHttpNameValueHeaderValue_DEFINED__
#define __WWHHHttpNameValueHeaderValue_DEFINED__

WINRT_EXPORT
@interface WWHHHttpNameValueHeaderValue : RTObject <WFIStringable>
+ (WWHHHttpNameValueHeaderValue*)parse:(NSString*)input;
+ (BOOL)tryParse:(NSString*)input nameValueHeaderValue:(WWHHHttpNameValueHeaderValue**)nameValueHeaderValue;
+ (WWHHHttpNameValueHeaderValue*)createFromName:(NSString*)name ACTIVATOR;
+ (WWHHHttpNameValueHeaderValue*)createFromNameWithValue:(NSString*)name value:(NSString*)value ACTIVATOR;
@property (copy) NSString* value;
@property (readonly) NSString* name;
- (NSString*)toString;
@end

#endif // __WWHHHttpNameValueHeaderValue_DEFINED__

// Windows.Web.Http.Headers.HttpChallengeHeaderValue
#ifndef __WWHHHttpChallengeHeaderValue_DEFINED__
#define __WWHHHttpChallengeHeaderValue_DEFINED__

WINRT_EXPORT
@interface WWHHHttpChallengeHeaderValue : RTObject <WFIStringable>
+ (WWHHHttpChallengeHeaderValue*)parse:(NSString*)input;
+ (BOOL)tryParse:(NSString*)input challengeHeaderValue:(WWHHHttpChallengeHeaderValue**)challengeHeaderValue;
+ (WWHHHttpChallengeHeaderValue*)createFromScheme:(NSString*)scheme ACTIVATOR;
+ (WWHHHttpChallengeHeaderValue*)createFromSchemeWithToken:(NSString*)scheme token:(NSString*)token ACTIVATOR;
@property (readonly) id<NSFastEnumeration> /*WWHHHttpNameValueHeaderValue*/ parameters;
@property (readonly) NSString* scheme;
@property (readonly) NSString* token;
- (NSString*)toString;
@end

#endif // __WWHHHttpChallengeHeaderValue_DEFINED__

// Windows.Web.Http.Headers.HttpConnectionOptionHeaderValue
#ifndef __WWHHHttpConnectionOptionHeaderValue_DEFINED__
#define __WWHHHttpConnectionOptionHeaderValue_DEFINED__

WINRT_EXPORT
@interface WWHHHttpConnectionOptionHeaderValue : RTObject <WFIStringable>
+ (WWHHHttpConnectionOptionHeaderValue*)parse:(NSString*)input;
+ (BOOL)tryParse:(NSString*)input connectionOptionHeaderValue:(WWHHHttpConnectionOptionHeaderValue**)connectionOptionHeaderValue;
+ (WWHHHttpConnectionOptionHeaderValue*)create:(NSString*)token ACTIVATOR;
@property (readonly) NSString* token;
- (NSString*)toString;
@end

#endif // __WWHHHttpConnectionOptionHeaderValue_DEFINED__

// Windows.Web.Http.Headers.HttpContentCodingHeaderValue
#ifndef __WWHHHttpContentCodingHeaderValue_DEFINED__
#define __WWHHHttpContentCodingHeaderValue_DEFINED__

WINRT_EXPORT
@interface WWHHHttpContentCodingHeaderValue : RTObject <WFIStringable>
+ (WWHHHttpContentCodingHeaderValue*)parse:(NSString*)input;
+ (BOOL)tryParse:(NSString*)input contentCodingHeaderValue:(WWHHHttpContentCodingHeaderValue**)contentCodingHeaderValue;
+ (WWHHHttpContentCodingHeaderValue*)create:(NSString*)contentCoding ACTIVATOR;
@property (readonly) NSString* contentCoding;
- (NSString*)toString;
@end

#endif // __WWHHHttpContentCodingHeaderValue_DEFINED__

// Windows.Web.Http.Headers.HttpCookiePairHeaderValue
#ifndef __WWHHHttpCookiePairHeaderValue_DEFINED__
#define __WWHHHttpCookiePairHeaderValue_DEFINED__

WINRT_EXPORT
@interface WWHHHttpCookiePairHeaderValue : RTObject <WFIStringable>
+ (WWHHHttpCookiePairHeaderValue*)parse:(NSString*)input;
+ (BOOL)tryParse:(NSString*)input cookiePairHeaderValue:(WWHHHttpCookiePairHeaderValue**)cookiePairHeaderValue;
+ (WWHHHttpCookiePairHeaderValue*)createFromName:(NSString*)name ACTIVATOR;
+ (WWHHHttpCookiePairHeaderValue*)createFromNameWithValue:(NSString*)name value:(NSString*)value ACTIVATOR;
@property (copy) NSString* value;
@property (readonly) NSString* name;
- (NSString*)toString;
@end

#endif // __WWHHHttpCookiePairHeaderValue_DEFINED__

// Windows.Web.Http.Headers.HttpExpectationHeaderValue
#ifndef __WWHHHttpExpectationHeaderValue_DEFINED__
#define __WWHHHttpExpectationHeaderValue_DEFINED__

WINRT_EXPORT
@interface WWHHHttpExpectationHeaderValue : RTObject <WFIStringable>
+ (WWHHHttpExpectationHeaderValue*)parse:(NSString*)input;
+ (BOOL)tryParse:(NSString*)input expectationHeaderValue:(WWHHHttpExpectationHeaderValue**)expectationHeaderValue;
+ (WWHHHttpExpectationHeaderValue*)createFromName:(NSString*)name ACTIVATOR;
+ (WWHHHttpExpectationHeaderValue*)createFromNameWithValue:(NSString*)name value:(NSString*)value ACTIVATOR;
@property (copy) NSString* value;
@property (readonly) NSString* name;
@property (readonly) id<NSFastEnumeration> /*WWHHHttpNameValueHeaderValue*/ parameters;
- (NSString*)toString;
@end

#endif // __WWHHHttpExpectationHeaderValue_DEFINED__

// Windows.Web.Http.Headers.HttpLanguageRangeWithQualityHeaderValue
#ifndef __WWHHHttpLanguageRangeWithQualityHeaderValue_DEFINED__
#define __WWHHHttpLanguageRangeWithQualityHeaderValue_DEFINED__

WINRT_EXPORT
@interface WWHHHttpLanguageRangeWithQualityHeaderValue : RTObject <WFIStringable>
+ (WWHHHttpLanguageRangeWithQualityHeaderValue*)parse:(NSString*)input;
+ (BOOL)tryParse:(NSString*)input
    languageRangeWithQualityHeaderValue:(WWHHHttpLanguageRangeWithQualityHeaderValue**)languageRangeWithQualityHeaderValue;
+ (WWHHHttpLanguageRangeWithQualityHeaderValue*)createFromLanguageRange:(NSString*)languageRange ACTIVATOR;
+ (WWHHHttpLanguageRangeWithQualityHeaderValue*)createFromLanguageRangeWithQuality:(NSString*)languageRange
                                                                           quality:(double)quality ACTIVATOR;
@property (readonly) NSString* languageRange;
@property (readonly) NSNumber* quality;
- (NSString*)toString;
@end

#endif // __WWHHHttpLanguageRangeWithQualityHeaderValue_DEFINED__

// Windows.Web.Http.Headers.HttpMediaTypeWithQualityHeaderValue
#ifndef __WWHHHttpMediaTypeWithQualityHeaderValue_DEFINED__
#define __WWHHHttpMediaTypeWithQualityHeaderValue_DEFINED__

WINRT_EXPORT
@interface WWHHHttpMediaTypeWithQualityHeaderValue : RTObject <WFIStringable>
+ (WWHHHttpMediaTypeWithQualityHeaderValue*)parse:(NSString*)input;
+ (BOOL)tryParse:(NSString*)input
    mediaTypeWithQualityHeaderValue:(WWHHHttpMediaTypeWithQualityHeaderValue**)mediaTypeWithQualityHeaderValue;
+ (WWHHHttpMediaTypeWithQualityHeaderValue*)createFromMediaType:(NSString*)mediaType ACTIVATOR;
+ (WWHHHttpMediaTypeWithQualityHeaderValue*)createFromMediaTypeWithQuality:(NSString*)mediaType quality:(double)quality ACTIVATOR;
@property (copy) NSNumber* quality;
@property (copy) NSString* mediaType;
@property (copy) NSString* charSet;
@property (readonly) id<NSFastEnumeration> /*WWHHHttpNameValueHeaderValue*/ parameters;
- (NSString*)toString;
@end

#endif // __WWHHHttpMediaTypeWithQualityHeaderValue_DEFINED__

// Windows.Web.Http.Headers.HttpProductHeaderValue
#ifndef __WWHHHttpProductHeaderValue_DEFINED__
#define __WWHHHttpProductHeaderValue_DEFINED__

WINRT_EXPORT
@interface WWHHHttpProductHeaderValue : RTObject <WFIStringable>
+ (WWHHHttpProductHeaderValue*)parse:(NSString*)input;
+ (BOOL)tryParse:(NSString*)input productHeaderValue:(WWHHHttpProductHeaderValue**)productHeaderValue;
+ (WWHHHttpProductHeaderValue*)createFromName:(NSString*)productName ACTIVATOR;
+ (WWHHHttpProductHeaderValue*)createFromNameWithVersion:(NSString*)productName productVersion:(NSString*)productVersion ACTIVATOR;
@property (readonly) NSString* name;
@property (readonly) NSString* version;
- (NSString*)toString;
@end

#endif // __WWHHHttpProductHeaderValue_DEFINED__

// Windows.Web.Http.Headers.HttpProductInfoHeaderValue
#ifndef __WWHHHttpProductInfoHeaderValue_DEFINED__
#define __WWHHHttpProductInfoHeaderValue_DEFINED__

WINRT_EXPORT
@interface WWHHHttpProductInfoHeaderValue : RTObject <WFIStringable>
+ (WWHHHttpProductInfoHeaderValue*)parse:(NSString*)input;
+ (BOOL)tryParse:(NSString*)input productInfoHeaderValue:(WWHHHttpProductInfoHeaderValue**)productInfoHeaderValue;
+ (WWHHHttpProductInfoHeaderValue*)createFromComment:(NSString*)productComment ACTIVATOR;
+ (WWHHHttpProductInfoHeaderValue*)createFromNameWithVersion:(NSString*)productName productVersion:(NSString*)productVersion ACTIVATOR;
@property (readonly) NSString* comment;
@property (readonly) WWHHHttpProductHeaderValue* product;
- (NSString*)toString;
@end

#endif // __WWHHHttpProductInfoHeaderValue_DEFINED__

// Windows.Web.Http.Headers.HttpContentCodingWithQualityHeaderValue
#ifndef __WWHHHttpContentCodingWithQualityHeaderValue_DEFINED__
#define __WWHHHttpContentCodingWithQualityHeaderValue_DEFINED__

WINRT_EXPORT
@interface WWHHHttpContentCodingWithQualityHeaderValue : RTObject <WFIStringable>
+ (WWHHHttpContentCodingWithQualityHeaderValue*)parse:(NSString*)input;
+ (BOOL)tryParse:(NSString*)input
    contentCodingWithQualityHeaderValue:(WWHHHttpContentCodingWithQualityHeaderValue**)contentCodingWithQualityHeaderValue;
+ (WWHHHttpContentCodingWithQualityHeaderValue*)createFromValue:(NSString*)contentCoding ACTIVATOR;
+ (WWHHHttpContentCodingWithQualityHeaderValue*)createFromValueWithQuality:(NSString*)contentCoding quality:(double)quality ACTIVATOR;
@property (readonly) NSString* contentCoding;
@property (readonly) NSNumber* quality;
- (NSString*)toString;
@end

#endif // __WWHHHttpContentCodingWithQualityHeaderValue_DEFINED__

// Windows.Web.Http.Headers.HttpTransferCodingHeaderValue
#ifndef __WWHHHttpTransferCodingHeaderValue_DEFINED__
#define __WWHHHttpTransferCodingHeaderValue_DEFINED__

WINRT_EXPORT
@interface WWHHHttpTransferCodingHeaderValue : RTObject <WFIStringable>
+ (WWHHHttpTransferCodingHeaderValue*)parse:(NSString*)input;
+ (BOOL)tryParse:(NSString*)input transferCodingHeaderValue:(WWHHHttpTransferCodingHeaderValue**)transferCodingHeaderValue;
+ (WWHHHttpTransferCodingHeaderValue*)create:(NSString*)input ACTIVATOR;
@property (readonly) id<NSFastEnumeration> /*WWHHHttpNameValueHeaderValue*/ parameters;
@property (readonly) NSString* value;
- (NSString*)toString;
@end

#endif // __WWHHHttpTransferCodingHeaderValue_DEFINED__
