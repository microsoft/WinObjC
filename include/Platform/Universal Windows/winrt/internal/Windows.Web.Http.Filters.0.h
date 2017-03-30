// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Web::Http::Filters {

struct IHttpBaseProtocolFilter;
struct IHttpBaseProtocolFilter2;
struct IHttpBaseProtocolFilter3;
struct IHttpBaseProtocolFilter4;
struct IHttpCacheControl;
struct IHttpFilter;
struct IHttpServerCustomValidationRequestedEventArgs;
struct HttpBaseProtocolFilter;
struct HttpCacheControl;
struct HttpServerCustomValidationRequestedEventArgs;

}

namespace Windows::Web::Http::Filters {

struct IHttpBaseProtocolFilter;
struct IHttpBaseProtocolFilter2;
struct IHttpBaseProtocolFilter3;
struct IHttpBaseProtocolFilter4;
struct IHttpCacheControl;
struct IHttpFilter;
struct IHttpServerCustomValidationRequestedEventArgs;
struct HttpBaseProtocolFilter;
struct HttpCacheControl;
struct HttpServerCustomValidationRequestedEventArgs;

}

namespace Windows::Web::Http::Filters {

template <typename T> struct impl_IHttpBaseProtocolFilter;
template <typename T> struct impl_IHttpBaseProtocolFilter2;
template <typename T> struct impl_IHttpBaseProtocolFilter3;
template <typename T> struct impl_IHttpBaseProtocolFilter4;
template <typename T> struct impl_IHttpCacheControl;
template <typename T> struct impl_IHttpFilter;
template <typename T> struct impl_IHttpServerCustomValidationRequestedEventArgs;

}

namespace Windows::Web::Http::Filters {

enum class HttpCacheReadBehavior
{
    Default = 0,
    MostRecent = 1,
    OnlyFromCache = 2,
    NoCache = 3,
};

enum class HttpCacheWriteBehavior
{
    Default = 0,
    NoCache = 1,
};

enum class HttpCookieUsageBehavior
{
    Default = 0,
    NoCookies = 1,
};

}

}
