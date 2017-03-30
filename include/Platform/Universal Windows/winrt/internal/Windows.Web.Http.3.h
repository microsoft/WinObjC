// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Web.Http.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Web::Http {

struct WINRT_EBO HttpBufferContent :
    Windows::Web::Http::IHttpContent,
    impl::require<HttpBufferContent, Windows::Foundation::IStringable>
{
    HttpBufferContent(std::nullptr_t) noexcept {}
    HttpBufferContent(const Windows::Storage::Streams::IBuffer & content);
    HttpBufferContent(const Windows::Storage::Streams::IBuffer & content, uint32_t offset, uint32_t count);
};

struct WINRT_EBO HttpClient :
    Windows::Web::Http::IHttpClient,
    impl::require<HttpClient, Windows::Foundation::IStringable>
{
    HttpClient(std::nullptr_t) noexcept {}
    HttpClient();
    HttpClient(const Windows::Web::Http::Filters::IHttpFilter & filter);
};

struct WINRT_EBO HttpCookie :
    Windows::Web::Http::IHttpCookie,
    impl::require<HttpCookie, Windows::Foundation::IStringable>
{
    HttpCookie(std::nullptr_t) noexcept {}
    HttpCookie(hstring_view name, hstring_view domain, hstring_view path);
};

struct WINRT_EBO HttpCookieCollection :
    Windows::Foundation::Collections::IVectorView<Windows::Web::Http::HttpCookie>
{
    HttpCookieCollection(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HttpCookieManager :
    Windows::Web::Http::IHttpCookieManager
{
    HttpCookieManager(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HttpFormUrlEncodedContent :
    Windows::Web::Http::IHttpContent,
    impl::require<HttpFormUrlEncodedContent, Windows::Foundation::IStringable>
{
    HttpFormUrlEncodedContent(std::nullptr_t) noexcept {}
    HttpFormUrlEncodedContent(iterable<Windows::Foundation::Collections::IKeyValuePair<hstring, hstring>> content);
};

struct WINRT_EBO HttpMethod :
    Windows::Web::Http::IHttpMethod,
    impl::require<HttpMethod, Windows::Foundation::IStringable>
{
    HttpMethod(std::nullptr_t) noexcept {}
    HttpMethod(hstring_view method);
    static Windows::Web::Http::HttpMethod Delete();
    static Windows::Web::Http::HttpMethod Get();
    static Windows::Web::Http::HttpMethod Head();
    static Windows::Web::Http::HttpMethod Options();
    static Windows::Web::Http::HttpMethod Patch();
    static Windows::Web::Http::HttpMethod Post();
    static Windows::Web::Http::HttpMethod Put();
};

struct WINRT_EBO HttpMultipartContent :
    Windows::Web::Http::IHttpContent,
    impl::require<HttpMultipartContent, Windows::Foundation::IStringable, Windows::Web::Http::IHttpMultipartContent, Windows::Foundation::Collections::IIterable<Windows::Web::Http::IHttpContent>>
{
    HttpMultipartContent(std::nullptr_t) noexcept {}
    HttpMultipartContent();
    HttpMultipartContent(hstring_view subtype);
    HttpMultipartContent(hstring_view subtype, hstring_view boundary);
};

struct WINRT_EBO HttpMultipartFormDataContent :
    Windows::Web::Http::IHttpContent,
    impl::require<HttpMultipartFormDataContent, Windows::Foundation::IStringable, Windows::Web::Http::IHttpMultipartFormDataContent, Windows::Foundation::Collections::IIterable<Windows::Web::Http::IHttpContent>>
{
    HttpMultipartFormDataContent(std::nullptr_t) noexcept {}
    HttpMultipartFormDataContent();
    HttpMultipartFormDataContent(hstring_view boundary);
};

struct WINRT_EBO HttpRequestMessage :
    Windows::Web::Http::IHttpRequestMessage,
    impl::require<HttpRequestMessage, Windows::Foundation::IStringable>
{
    HttpRequestMessage(std::nullptr_t) noexcept {}
    HttpRequestMessage();
    HttpRequestMessage(const Windows::Web::Http::HttpMethod & method, const Windows::Foundation::Uri & uri);
};

struct WINRT_EBO HttpResponseMessage :
    Windows::Web::Http::IHttpResponseMessage,
    impl::require<HttpResponseMessage, Windows::Foundation::IStringable>
{
    HttpResponseMessage(std::nullptr_t) noexcept {}
    HttpResponseMessage();
    HttpResponseMessage(Windows::Web::Http::HttpStatusCode statusCode);
};

struct WINRT_EBO HttpStreamContent :
    Windows::Web::Http::IHttpContent,
    impl::require<HttpStreamContent, Windows::Foundation::IStringable>
{
    HttpStreamContent(std::nullptr_t) noexcept {}
    HttpStreamContent(const Windows::Storage::Streams::IInputStream & content);
};

struct WINRT_EBO HttpStringContent :
    Windows::Web::Http::IHttpContent,
    impl::require<HttpStringContent, Windows::Foundation::IStringable>
{
    HttpStringContent(std::nullptr_t) noexcept {}
    HttpStringContent(hstring_view content);
    HttpStringContent(hstring_view content, Windows::Storage::Streams::UnicodeEncoding encoding);
    HttpStringContent(hstring_view content, Windows::Storage::Streams::UnicodeEncoding encoding, hstring_view mediaType);
};

struct WINRT_EBO HttpTransportInformation :
    Windows::Web::Http::IHttpTransportInformation,
    impl::require<HttpTransportInformation, Windows::Foundation::IStringable>
{
    HttpTransportInformation(std::nullptr_t) noexcept {}
};

}

}
