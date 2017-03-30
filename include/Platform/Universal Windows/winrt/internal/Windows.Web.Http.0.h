// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Web::Http {

struct HttpProgress;

}

namespace Windows::Web::Http {

struct HttpProgress;

}

namespace ABI::Windows::Web::Http {

struct IHttpBufferContentFactory;
struct IHttpClient;
struct IHttpClientFactory;
struct IHttpContent;
struct IHttpCookie;
struct IHttpCookieFactory;
struct IHttpCookieManager;
struct IHttpFormUrlEncodedContentFactory;
struct IHttpMethod;
struct IHttpMethodFactory;
struct IHttpMethodStatics;
struct IHttpMultipartContent;
struct IHttpMultipartContentFactory;
struct IHttpMultipartFormDataContent;
struct IHttpMultipartFormDataContentFactory;
struct IHttpRequestMessage;
struct IHttpRequestMessageFactory;
struct IHttpResponseMessage;
struct IHttpResponseMessageFactory;
struct IHttpStreamContentFactory;
struct IHttpStringContentFactory;
struct IHttpTransportInformation;
struct HttpBufferContent;
struct HttpClient;
struct HttpCookie;
struct HttpCookieCollection;
struct HttpCookieManager;
struct HttpFormUrlEncodedContent;
struct HttpMethod;
struct HttpMultipartContent;
struct HttpMultipartFormDataContent;
struct HttpRequestMessage;
struct HttpResponseMessage;
struct HttpStreamContent;
struct HttpStringContent;
struct HttpTransportInformation;

}

namespace Windows::Web::Http {

struct IHttpBufferContentFactory;
struct IHttpClient;
struct IHttpClientFactory;
struct IHttpContent;
struct IHttpCookie;
struct IHttpCookieFactory;
struct IHttpCookieManager;
struct IHttpFormUrlEncodedContentFactory;
struct IHttpMethod;
struct IHttpMethodFactory;
struct IHttpMethodStatics;
struct IHttpMultipartContent;
struct IHttpMultipartContentFactory;
struct IHttpMultipartFormDataContent;
struct IHttpMultipartFormDataContentFactory;
struct IHttpRequestMessage;
struct IHttpRequestMessageFactory;
struct IHttpResponseMessage;
struct IHttpResponseMessageFactory;
struct IHttpStreamContentFactory;
struct IHttpStringContentFactory;
struct IHttpTransportInformation;
struct HttpBufferContent;
struct HttpClient;
struct HttpCookie;
struct HttpCookieCollection;
struct HttpCookieManager;
struct HttpFormUrlEncodedContent;
struct HttpMethod;
struct HttpMultipartContent;
struct HttpMultipartFormDataContent;
struct HttpRequestMessage;
struct HttpResponseMessage;
struct HttpStreamContent;
struct HttpStringContent;
struct HttpTransportInformation;

}

namespace Windows::Web::Http {

template <typename T> struct impl_IHttpBufferContentFactory;
template <typename T> struct impl_IHttpClient;
template <typename T> struct impl_IHttpClientFactory;
template <typename T> struct impl_IHttpContent;
template <typename T> struct impl_IHttpCookie;
template <typename T> struct impl_IHttpCookieFactory;
template <typename T> struct impl_IHttpCookieManager;
template <typename T> struct impl_IHttpFormUrlEncodedContentFactory;
template <typename T> struct impl_IHttpMethod;
template <typename T> struct impl_IHttpMethodFactory;
template <typename T> struct impl_IHttpMethodStatics;
template <typename T> struct impl_IHttpMultipartContent;
template <typename T> struct impl_IHttpMultipartContentFactory;
template <typename T> struct impl_IHttpMultipartFormDataContent;
template <typename T> struct impl_IHttpMultipartFormDataContentFactory;
template <typename T> struct impl_IHttpRequestMessage;
template <typename T> struct impl_IHttpRequestMessageFactory;
template <typename T> struct impl_IHttpResponseMessage;
template <typename T> struct impl_IHttpResponseMessageFactory;
template <typename T> struct impl_IHttpStreamContentFactory;
template <typename T> struct impl_IHttpStringContentFactory;
template <typename T> struct impl_IHttpTransportInformation;

}

namespace Windows::Web::Http {

enum class HttpCompletionOption
{
    ResponseContentRead = 0,
    ResponseHeadersRead = 1,
};

enum class HttpProgressStage
{
    None = 0,
    DetectingProxy = 10,
    ResolvingName = 20,
    ConnectingToServer = 30,
    NegotiatingSsl = 40,
    SendingHeaders = 50,
    SendingContent = 60,
    WaitingForResponse = 70,
    ReceivingHeaders = 80,
    ReceivingContent = 90,
};

enum class HttpResponseMessageSource
{
    None = 0,
    Cache = 1,
    Network = 2,
};

enum class HttpStatusCode
{
    None = 0,
    Continue = 100,
    SwitchingProtocols = 101,
    Processing = 102,
    Ok = 200,
    Created = 201,
    Accepted = 202,
    NonAuthoritativeInformation = 203,
    NoContent = 204,
    ResetContent = 205,
    PartialContent = 206,
    MultiStatus = 207,
    AlreadyReported = 208,
    IMUsed = 226,
    MultipleChoices = 300,
    MovedPermanently = 301,
    Found = 302,
    SeeOther = 303,
    NotModified = 304,
    UseProxy = 305,
    TemporaryRedirect = 307,
    PermanentRedirect = 308,
    BadRequest = 400,
    Unauthorized = 401,
    PaymentRequired = 402,
    Forbidden = 403,
    NotFound = 404,
    MethodNotAllowed = 405,
    NotAcceptable = 406,
    ProxyAuthenticationRequired = 407,
    RequestTimeout = 408,
    Conflict = 409,
    Gone = 410,
    LengthRequired = 411,
    PreconditionFailed = 412,
    RequestEntityTooLarge = 413,
    RequestUriTooLong = 414,
    UnsupportedMediaType = 415,
    RequestedRangeNotSatisfiable = 416,
    ExpectationFailed = 417,
    UnprocessableEntity = 422,
    Locked = 423,
    FailedDependency = 424,
    UpgradeRequired = 426,
    PreconditionRequired = 428,
    TooManyRequests = 429,
    RequestHeaderFieldsTooLarge = 431,
    InternalServerError = 500,
    NotImplemented = 501,
    BadGateway = 502,
    ServiceUnavailable = 503,
    GatewayTimeout = 504,
    HttpVersionNotSupported = 505,
    VariantAlsoNegotiates = 506,
    InsufficientStorage = 507,
    LoopDetected = 508,
    NotExtended = 510,
    NetworkAuthenticationRequired = 511,
};

enum class HttpVersion
{
    None = 0,
    Http10 = 1,
    Http11 = 2,
    Http20 = 3,
};

}

}
