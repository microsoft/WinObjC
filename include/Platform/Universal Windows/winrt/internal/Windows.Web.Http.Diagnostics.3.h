// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Web.Http.Diagnostics.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Web::Http::Diagnostics {

struct WINRT_EBO HttpDiagnosticProvider :
    Windows::Web::Http::Diagnostics::IHttpDiagnosticProvider
{
    HttpDiagnosticProvider(std::nullptr_t) noexcept {}
    static Windows::Web::Http::Diagnostics::HttpDiagnosticProvider CreateFromProcessDiagnosticInfo(const Windows::System::Diagnostics::ProcessDiagnosticInfo & processDiagnosticInfo);
};

struct WINRT_EBO HttpDiagnosticProviderRequestResponseCompletedEventArgs :
    Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseCompletedEventArgs
{
    HttpDiagnosticProviderRequestResponseCompletedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HttpDiagnosticProviderRequestResponseTimestamps :
    Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseTimestamps
{
    HttpDiagnosticProviderRequestResponseTimestamps(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HttpDiagnosticProviderRequestSentEventArgs :
    Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestSentEventArgs
{
    HttpDiagnosticProviderRequestSentEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HttpDiagnosticProviderResponseReceivedEventArgs :
    Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderResponseReceivedEventArgs
{
    HttpDiagnosticProviderResponseReceivedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HttpDiagnosticSourceLocation :
    Windows::Web::Http::Diagnostics::IHttpDiagnosticSourceLocation
{
    HttpDiagnosticSourceLocation(std::nullptr_t) noexcept {}
};

}

}
