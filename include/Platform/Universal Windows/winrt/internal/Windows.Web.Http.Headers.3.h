// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Web.Http.Headers.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Web::Http::Headers {

struct WINRT_EBO HttpCacheDirectiveHeaderValueCollection :
    Windows::Web::Http::Headers::IHttpCacheDirectiveHeaderValueCollection,
    impl::require<HttpCacheDirectiveHeaderValueCollection, Windows::Foundation::IStringable>
{
    HttpCacheDirectiveHeaderValueCollection(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HttpChallengeHeaderValue :
    Windows::Web::Http::Headers::IHttpChallengeHeaderValue,
    impl::require<HttpChallengeHeaderValue, Windows::Foundation::IStringable>
{
    HttpChallengeHeaderValue(std::nullptr_t) noexcept {}
    HttpChallengeHeaderValue(hstring_view scheme);
    HttpChallengeHeaderValue(hstring_view scheme, hstring_view token);
    static Windows::Web::Http::Headers::HttpChallengeHeaderValue Parse(hstring_view input);
    static bool TryParse(hstring_view input, Windows::Web::Http::Headers::HttpChallengeHeaderValue & challengeHeaderValue);
};

struct WINRT_EBO HttpChallengeHeaderValueCollection :
    Windows::Web::Http::Headers::IHttpChallengeHeaderValueCollection,
    impl::require<HttpChallengeHeaderValueCollection, Windows::Foundation::IStringable>
{
    HttpChallengeHeaderValueCollection(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HttpConnectionOptionHeaderValue :
    Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValue,
    impl::require<HttpConnectionOptionHeaderValue, Windows::Foundation::IStringable>
{
    HttpConnectionOptionHeaderValue(std::nullptr_t) noexcept {}
    HttpConnectionOptionHeaderValue(hstring_view token);
    static Windows::Web::Http::Headers::HttpConnectionOptionHeaderValue Parse(hstring_view input);
    static bool TryParse(hstring_view input, Windows::Web::Http::Headers::HttpConnectionOptionHeaderValue & connectionOptionHeaderValue);
};

struct WINRT_EBO HttpConnectionOptionHeaderValueCollection :
    Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValueCollection,
    impl::require<HttpConnectionOptionHeaderValueCollection, Windows::Foundation::IStringable>
{
    HttpConnectionOptionHeaderValueCollection(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HttpContentCodingHeaderValue :
    Windows::Web::Http::Headers::IHttpContentCodingHeaderValue,
    impl::require<HttpContentCodingHeaderValue, Windows::Foundation::IStringable>
{
    HttpContentCodingHeaderValue(std::nullptr_t) noexcept {}
    HttpContentCodingHeaderValue(hstring_view contentCoding);
    static Windows::Web::Http::Headers::HttpContentCodingHeaderValue Parse(hstring_view input);
    static bool TryParse(hstring_view input, Windows::Web::Http::Headers::HttpContentCodingHeaderValue & contentCodingHeaderValue);
};

struct WINRT_EBO HttpContentCodingHeaderValueCollection :
    Windows::Web::Http::Headers::IHttpContentCodingHeaderValueCollection,
    impl::require<HttpContentCodingHeaderValueCollection, Windows::Foundation::IStringable>
{
    HttpContentCodingHeaderValueCollection(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HttpContentCodingWithQualityHeaderValue :
    Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValue,
    impl::require<HttpContentCodingWithQualityHeaderValue, Windows::Foundation::IStringable>
{
    HttpContentCodingWithQualityHeaderValue(std::nullptr_t) noexcept {}
    HttpContentCodingWithQualityHeaderValue(hstring_view contentCoding);
    HttpContentCodingWithQualityHeaderValue(hstring_view contentCoding, double quality);
    static Windows::Web::Http::Headers::HttpContentCodingWithQualityHeaderValue Parse(hstring_view input);
    static bool TryParse(hstring_view input, Windows::Web::Http::Headers::HttpContentCodingWithQualityHeaderValue & contentCodingWithQualityHeaderValue);
};

struct WINRT_EBO HttpContentCodingWithQualityHeaderValueCollection :
    Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValueCollection,
    impl::require<HttpContentCodingWithQualityHeaderValueCollection, Windows::Foundation::IStringable>
{
    HttpContentCodingWithQualityHeaderValueCollection(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HttpContentDispositionHeaderValue :
    Windows::Web::Http::Headers::IHttpContentDispositionHeaderValue,
    impl::require<HttpContentDispositionHeaderValue, Windows::Foundation::IStringable>
{
    HttpContentDispositionHeaderValue(std::nullptr_t) noexcept {}
    HttpContentDispositionHeaderValue(hstring_view dispositionType);
    static Windows::Web::Http::Headers::HttpContentDispositionHeaderValue Parse(hstring_view input);
    static bool TryParse(hstring_view input, Windows::Web::Http::Headers::HttpContentDispositionHeaderValue & contentDispositionHeaderValue);
};

struct WINRT_EBO HttpContentHeaderCollection :
    Windows::Web::Http::Headers::IHttpContentHeaderCollection,
    impl::require<HttpContentHeaderCollection, Windows::Foundation::IStringable>
{
    HttpContentHeaderCollection(std::nullptr_t) noexcept {}
    HttpContentHeaderCollection();
};

struct WINRT_EBO HttpContentRangeHeaderValue :
    Windows::Web::Http::Headers::IHttpContentRangeHeaderValue,
    impl::require<HttpContentRangeHeaderValue, Windows::Foundation::IStringable>
{
    HttpContentRangeHeaderValue(std::nullptr_t) noexcept {}
    HttpContentRangeHeaderValue(uint64_t length);
    HttpContentRangeHeaderValue(uint64_t from, uint64_t to);
    HttpContentRangeHeaderValue(uint64_t from, uint64_t to, uint64_t length);
    static Windows::Web::Http::Headers::HttpContentRangeHeaderValue Parse(hstring_view input);
    static bool TryParse(hstring_view input, Windows::Web::Http::Headers::HttpContentRangeHeaderValue & contentRangeHeaderValue);
};

struct WINRT_EBO HttpCookiePairHeaderValue :
    Windows::Web::Http::Headers::IHttpCookiePairHeaderValue,
    impl::require<HttpCookiePairHeaderValue, Windows::Foundation::IStringable>
{
    HttpCookiePairHeaderValue(std::nullptr_t) noexcept {}
    HttpCookiePairHeaderValue(hstring_view name);
    HttpCookiePairHeaderValue(hstring_view name, hstring_view value);
    static Windows::Web::Http::Headers::HttpCookiePairHeaderValue Parse(hstring_view input);
    static bool TryParse(hstring_view input, Windows::Web::Http::Headers::HttpCookiePairHeaderValue & cookiePairHeaderValue);
};

struct WINRT_EBO HttpCookiePairHeaderValueCollection :
    Windows::Web::Http::Headers::IHttpCookiePairHeaderValueCollection,
    impl::require<HttpCookiePairHeaderValueCollection, Windows::Foundation::IStringable>
{
    HttpCookiePairHeaderValueCollection(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HttpCredentialsHeaderValue :
    Windows::Web::Http::Headers::IHttpCredentialsHeaderValue,
    impl::require<HttpCredentialsHeaderValue, Windows::Foundation::IStringable>
{
    HttpCredentialsHeaderValue(std::nullptr_t) noexcept {}
    HttpCredentialsHeaderValue(hstring_view scheme);
    HttpCredentialsHeaderValue(hstring_view scheme, hstring_view token);
    static Windows::Web::Http::Headers::HttpCredentialsHeaderValue Parse(hstring_view input);
    static bool TryParse(hstring_view input, Windows::Web::Http::Headers::HttpCredentialsHeaderValue & credentialsHeaderValue);
};

struct WINRT_EBO HttpDateOrDeltaHeaderValue :
    Windows::Web::Http::Headers::IHttpDateOrDeltaHeaderValue,
    impl::require<HttpDateOrDeltaHeaderValue, Windows::Foundation::IStringable>
{
    HttpDateOrDeltaHeaderValue(std::nullptr_t) noexcept {}
    static Windows::Web::Http::Headers::HttpDateOrDeltaHeaderValue Parse(hstring_view input);
    static bool TryParse(hstring_view input, Windows::Web::Http::Headers::HttpDateOrDeltaHeaderValue & dateOrDeltaHeaderValue);
};

struct WINRT_EBO HttpExpectationHeaderValue :
    Windows::Web::Http::Headers::IHttpExpectationHeaderValue,
    impl::require<HttpExpectationHeaderValue, Windows::Foundation::IStringable>
{
    HttpExpectationHeaderValue(std::nullptr_t) noexcept {}
    HttpExpectationHeaderValue(hstring_view name);
    HttpExpectationHeaderValue(hstring_view name, hstring_view value);
    static Windows::Web::Http::Headers::HttpExpectationHeaderValue Parse(hstring_view input);
    static bool TryParse(hstring_view input, Windows::Web::Http::Headers::HttpExpectationHeaderValue & expectationHeaderValue);
};

struct WINRT_EBO HttpExpectationHeaderValueCollection :
    Windows::Web::Http::Headers::IHttpExpectationHeaderValueCollection,
    impl::require<HttpExpectationHeaderValueCollection, Windows::Foundation::IStringable>
{
    HttpExpectationHeaderValueCollection(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HttpLanguageHeaderValueCollection :
    Windows::Web::Http::Headers::IHttpLanguageHeaderValueCollection,
    impl::require<HttpLanguageHeaderValueCollection, Windows::Foundation::IStringable>
{
    HttpLanguageHeaderValueCollection(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HttpLanguageRangeWithQualityHeaderValue :
    Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValue,
    impl::require<HttpLanguageRangeWithQualityHeaderValue, Windows::Foundation::IStringable>
{
    HttpLanguageRangeWithQualityHeaderValue(std::nullptr_t) noexcept {}
    HttpLanguageRangeWithQualityHeaderValue(hstring_view languageRange);
    HttpLanguageRangeWithQualityHeaderValue(hstring_view languageRange, double quality);
    static Windows::Web::Http::Headers::HttpLanguageRangeWithQualityHeaderValue Parse(hstring_view input);
    static bool TryParse(hstring_view input, Windows::Web::Http::Headers::HttpLanguageRangeWithQualityHeaderValue & languageRangeWithQualityHeaderValue);
};

struct WINRT_EBO HttpLanguageRangeWithQualityHeaderValueCollection :
    Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValueCollection,
    impl::require<HttpLanguageRangeWithQualityHeaderValueCollection, Windows::Foundation::IStringable>
{
    HttpLanguageRangeWithQualityHeaderValueCollection(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HttpMediaTypeHeaderValue :
    Windows::Web::Http::Headers::IHttpMediaTypeHeaderValue,
    impl::require<HttpMediaTypeHeaderValue, Windows::Foundation::IStringable>
{
    HttpMediaTypeHeaderValue(std::nullptr_t) noexcept {}
    HttpMediaTypeHeaderValue(hstring_view mediaType);
    static Windows::Web::Http::Headers::HttpMediaTypeHeaderValue Parse(hstring_view input);
    static bool TryParse(hstring_view input, Windows::Web::Http::Headers::HttpMediaTypeHeaderValue & mediaTypeHeaderValue);
};

struct WINRT_EBO HttpMediaTypeWithQualityHeaderValue :
    Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValue,
    impl::require<HttpMediaTypeWithQualityHeaderValue, Windows::Foundation::IStringable>
{
    HttpMediaTypeWithQualityHeaderValue(std::nullptr_t) noexcept {}
    HttpMediaTypeWithQualityHeaderValue(hstring_view mediaType);
    HttpMediaTypeWithQualityHeaderValue(hstring_view mediaType, double quality);
    static Windows::Web::Http::Headers::HttpMediaTypeWithQualityHeaderValue Parse(hstring_view input);
    static bool TryParse(hstring_view input, Windows::Web::Http::Headers::HttpMediaTypeWithQualityHeaderValue & mediaTypeWithQualityHeaderValue);
};

struct WINRT_EBO HttpMediaTypeWithQualityHeaderValueCollection :
    Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValueCollection,
    impl::require<HttpMediaTypeWithQualityHeaderValueCollection, Windows::Foundation::IStringable>
{
    HttpMediaTypeWithQualityHeaderValueCollection(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HttpMethodHeaderValueCollection :
    Windows::Web::Http::Headers::IHttpMethodHeaderValueCollection,
    impl::require<HttpMethodHeaderValueCollection, Windows::Foundation::IStringable>
{
    HttpMethodHeaderValueCollection(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HttpNameValueHeaderValue :
    Windows::Web::Http::Headers::IHttpNameValueHeaderValue,
    impl::require<HttpNameValueHeaderValue, Windows::Foundation::IStringable>
{
    HttpNameValueHeaderValue(std::nullptr_t) noexcept {}
    HttpNameValueHeaderValue(hstring_view name);
    HttpNameValueHeaderValue(hstring_view name, hstring_view value);
    static Windows::Web::Http::Headers::HttpNameValueHeaderValue Parse(hstring_view input);
    static bool TryParse(hstring_view input, Windows::Web::Http::Headers::HttpNameValueHeaderValue & nameValueHeaderValue);
};

struct WINRT_EBO HttpProductHeaderValue :
    Windows::Web::Http::Headers::IHttpProductHeaderValue,
    impl::require<HttpProductHeaderValue, Windows::Foundation::IStringable>
{
    HttpProductHeaderValue(std::nullptr_t) noexcept {}
    HttpProductHeaderValue(hstring_view productName);
    HttpProductHeaderValue(hstring_view productName, hstring_view productVersion);
    static Windows::Web::Http::Headers::HttpProductHeaderValue Parse(hstring_view input);
    static bool TryParse(hstring_view input, Windows::Web::Http::Headers::HttpProductHeaderValue & productHeaderValue);
};

struct WINRT_EBO HttpProductInfoHeaderValue :
    Windows::Web::Http::Headers::IHttpProductInfoHeaderValue,
    impl::require<HttpProductInfoHeaderValue, Windows::Foundation::IStringable>
{
    HttpProductInfoHeaderValue(std::nullptr_t) noexcept {}
    HttpProductInfoHeaderValue(hstring_view productComment);
    HttpProductInfoHeaderValue(hstring_view productName, hstring_view productVersion);
    static Windows::Web::Http::Headers::HttpProductInfoHeaderValue Parse(hstring_view input);
    static bool TryParse(hstring_view input, Windows::Web::Http::Headers::HttpProductInfoHeaderValue & productInfoHeaderValue);
};

struct WINRT_EBO HttpProductInfoHeaderValueCollection :
    Windows::Web::Http::Headers::IHttpProductInfoHeaderValueCollection,
    impl::require<HttpProductInfoHeaderValueCollection, Windows::Foundation::IStringable>
{
    HttpProductInfoHeaderValueCollection(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HttpRequestHeaderCollection :
    Windows::Web::Http::Headers::IHttpRequestHeaderCollection,
    impl::require<HttpRequestHeaderCollection, Windows::Foundation::IStringable>
{
    HttpRequestHeaderCollection(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HttpResponseHeaderCollection :
    Windows::Web::Http::Headers::IHttpResponseHeaderCollection,
    impl::require<HttpResponseHeaderCollection, Windows::Foundation::IStringable>
{
    HttpResponseHeaderCollection(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HttpTransferCodingHeaderValue :
    Windows::Web::Http::Headers::IHttpTransferCodingHeaderValue,
    impl::require<HttpTransferCodingHeaderValue, Windows::Foundation::IStringable>
{
    HttpTransferCodingHeaderValue(std::nullptr_t) noexcept {}
    HttpTransferCodingHeaderValue(hstring_view input);
    static Windows::Web::Http::Headers::HttpTransferCodingHeaderValue Parse(hstring_view input);
    static bool TryParse(hstring_view input, Windows::Web::Http::Headers::HttpTransferCodingHeaderValue & transferCodingHeaderValue);
};

struct WINRT_EBO HttpTransferCodingHeaderValueCollection :
    Windows::Web::Http::Headers::IHttpTransferCodingHeaderValueCollection,
    impl::require<HttpTransferCodingHeaderValueCollection, Windows::Foundation::IStringable>
{
    HttpTransferCodingHeaderValueCollection(std::nullptr_t) noexcept {}
};

}

}
