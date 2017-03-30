// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Web.Http.Filters.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Web::Http::Filters {

struct WINRT_EBO HttpBaseProtocolFilter :
    Windows::Web::Http::Filters::IHttpBaseProtocolFilter,
    impl::require<HttpBaseProtocolFilter, Windows::Web::Http::Filters::IHttpBaseProtocolFilter2, Windows::Web::Http::Filters::IHttpBaseProtocolFilter3, Windows::Web::Http::Filters::IHttpBaseProtocolFilter4>
{
    HttpBaseProtocolFilter(std::nullptr_t) noexcept {}
    HttpBaseProtocolFilter();
};

struct WINRT_EBO HttpCacheControl :
    Windows::Web::Http::Filters::IHttpCacheControl
{
    HttpCacheControl(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HttpServerCustomValidationRequestedEventArgs :
    Windows::Web::Http::Filters::IHttpServerCustomValidationRequestedEventArgs
{
    HttpServerCustomValidationRequestedEventArgs(std::nullptr_t) noexcept {}
};

}

}
