// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Foundation.Diagnostics.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Foundation::Diagnostics {

struct AsyncCausalityTracer
{
    AsyncCausalityTracer() = delete;
    static void TraceOperationCreation(Windows::Foundation::Diagnostics::CausalityTraceLevel traceLevel, Windows::Foundation::Diagnostics::CausalitySource source, GUID platformId, uint64_t operationId, hstring_view operationName, uint64_t relatedContext);
    static void TraceOperationCompletion(Windows::Foundation::Diagnostics::CausalityTraceLevel traceLevel, Windows::Foundation::Diagnostics::CausalitySource source, GUID platformId, uint64_t operationId, Windows::Foundation::AsyncStatus status);
    static void TraceOperationRelation(Windows::Foundation::Diagnostics::CausalityTraceLevel traceLevel, Windows::Foundation::Diagnostics::CausalitySource source, GUID platformId, uint64_t operationId, Windows::Foundation::Diagnostics::CausalityRelation relation);
    static void TraceSynchronousWorkStart(Windows::Foundation::Diagnostics::CausalityTraceLevel traceLevel, Windows::Foundation::Diagnostics::CausalitySource source, GUID platformId, uint64_t operationId, Windows::Foundation::Diagnostics::CausalitySynchronousWork work);
    static void TraceSynchronousWorkCompletion(Windows::Foundation::Diagnostics::CausalityTraceLevel traceLevel, Windows::Foundation::Diagnostics::CausalitySource source, Windows::Foundation::Diagnostics::CausalitySynchronousWork work);
    static event_token TracingStatusChanged(const Windows::Foundation::EventHandler<Windows::Foundation::Diagnostics::TracingStatusChangedEventArgs> & handler);
    using TracingStatusChanged_revoker = factory_event_revoker<IAsyncCausalityTracerStatics>;
    static TracingStatusChanged_revoker TracingStatusChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::Diagnostics::TracingStatusChangedEventArgs> & handler);
    static void TracingStatusChanged(event_token cookie);
};

struct WINRT_EBO ErrorDetails :
    Windows::Foundation::Diagnostics::IErrorDetails
{
    ErrorDetails(std::nullptr_t) noexcept {}
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Diagnostics::ErrorDetails> CreateFromHResultAsync(int32_t errorCode);
};

struct WINRT_EBO FileLoggingSession :
    Windows::Foundation::Diagnostics::IFileLoggingSession
{
    FileLoggingSession(std::nullptr_t) noexcept {}
    FileLoggingSession(hstring_view name);
};

struct WINRT_EBO LogFileGeneratedEventArgs :
    Windows::Foundation::Diagnostics::ILogFileGeneratedEventArgs
{
    LogFileGeneratedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO LoggingActivity :
    Windows::Foundation::Diagnostics::ILoggingActivity,
    impl::require<LoggingActivity, Windows::Foundation::Diagnostics::ILoggingTarget, Windows::Foundation::Diagnostics::ILoggingActivity2>
{
    LoggingActivity(std::nullptr_t) noexcept {}
    LoggingActivity(hstring_view activityName, const Windows::Foundation::Diagnostics::ILoggingChannel & loggingChannel);
    LoggingActivity(hstring_view activityName, const Windows::Foundation::Diagnostics::ILoggingChannel & loggingChannel, Windows::Foundation::Diagnostics::LoggingLevel level);
};

struct WINRT_EBO LoggingChannel :
    Windows::Foundation::Diagnostics::ILoggingChannel,
    impl::require<LoggingChannel, Windows::Foundation::Diagnostics::ILoggingTarget, Windows::Foundation::Diagnostics::ILoggingChannel2>
{
    LoggingChannel(std::nullptr_t) noexcept {}
    LoggingChannel(hstring_view name, const Windows::Foundation::Diagnostics::LoggingChannelOptions & options);
    LoggingChannel(hstring_view name, const Windows::Foundation::Diagnostics::LoggingChannelOptions & options, GUID id);
    LoggingChannel(hstring_view name);
};

struct WINRT_EBO LoggingChannelOptions :
    Windows::Foundation::Diagnostics::ILoggingChannelOptions
{
    LoggingChannelOptions(std::nullptr_t) noexcept {}
    LoggingChannelOptions();
    LoggingChannelOptions(GUID group);
};

struct WINRT_EBO LoggingFields :
    Windows::Foundation::Diagnostics::ILoggingFields
{
    LoggingFields(std::nullptr_t) noexcept {}
    LoggingFields();
};

struct WINRT_EBO LoggingOptions :
    Windows::Foundation::Diagnostics::ILoggingOptions
{
    LoggingOptions(std::nullptr_t) noexcept {}
    LoggingOptions();
    LoggingOptions(int64_t keywords);
};

struct WINRT_EBO LoggingSession :
    Windows::Foundation::Diagnostics::ILoggingSession
{
    LoggingSession(std::nullptr_t) noexcept {}
    LoggingSession(hstring_view name);
};

struct WINRT_EBO RuntimeBrokerErrorSettings :
    Windows::Foundation::Diagnostics::IErrorReportingSettings
{
    RuntimeBrokerErrorSettings(std::nullptr_t) noexcept {}
    RuntimeBrokerErrorSettings();
};

struct WINRT_EBO TracingStatusChangedEventArgs :
    Windows::Foundation::Diagnostics::ITracingStatusChangedEventArgs
{
    TracingStatusChangedEventArgs(std::nullptr_t) noexcept {}
};

}

}
