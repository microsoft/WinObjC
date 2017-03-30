// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Diagnostics {

struct IAsyncCausalityTracerStatics;
struct IErrorDetails;
struct IErrorDetailsStatics;
struct IErrorReportingSettings;
struct IFileLoggingSession;
struct IFileLoggingSessionFactory;
struct ILogFileGeneratedEventArgs;
struct ILoggingActivity;
struct ILoggingActivity2;
struct ILoggingActivityFactory;
struct ILoggingChannel;
struct ILoggingChannel2;
struct ILoggingChannelFactory;
struct ILoggingChannelFactory2;
struct ILoggingChannelOptions;
struct ILoggingChannelOptionsFactory;
struct ILoggingFields;
struct ILoggingOptions;
struct ILoggingOptionsFactory;
struct ILoggingSession;
struct ILoggingSessionFactory;
struct ILoggingTarget;
struct ITracingStatusChangedEventArgs;
struct ErrorDetails;
struct FileLoggingSession;
struct LogFileGeneratedEventArgs;
struct LoggingActivity;
struct LoggingChannel;
struct LoggingChannelOptions;
struct LoggingFields;
struct LoggingOptions;
struct LoggingSession;
struct RuntimeBrokerErrorSettings;
struct TracingStatusChangedEventArgs;

}

namespace Windows::Foundation::Diagnostics {

struct IAsyncCausalityTracerStatics;
struct IErrorDetails;
struct IErrorDetailsStatics;
struct IErrorReportingSettings;
struct IFileLoggingSession;
struct IFileLoggingSessionFactory;
struct ILogFileGeneratedEventArgs;
struct ILoggingActivity;
struct ILoggingActivity2;
struct ILoggingActivityFactory;
struct ILoggingChannel;
struct ILoggingChannel2;
struct ILoggingChannelFactory;
struct ILoggingChannelFactory2;
struct ILoggingChannelOptions;
struct ILoggingChannelOptionsFactory;
struct ILoggingFields;
struct ILoggingOptions;
struct ILoggingOptionsFactory;
struct ILoggingSession;
struct ILoggingSessionFactory;
struct ILoggingTarget;
struct ITracingStatusChangedEventArgs;
struct AsyncCausalityTracer;
struct ErrorDetails;
struct FileLoggingSession;
struct LogFileGeneratedEventArgs;
struct LoggingActivity;
struct LoggingChannel;
struct LoggingChannelOptions;
struct LoggingFields;
struct LoggingOptions;
struct LoggingSession;
struct RuntimeBrokerErrorSettings;
struct TracingStatusChangedEventArgs;

}

namespace Windows::Foundation::Diagnostics {

template <typename T> struct impl_IAsyncCausalityTracerStatics;
template <typename T> struct impl_IErrorDetails;
template <typename T> struct impl_IErrorDetailsStatics;
template <typename T> struct impl_IErrorReportingSettings;
template <typename T> struct impl_IFileLoggingSession;
template <typename T> struct impl_IFileLoggingSessionFactory;
template <typename T> struct impl_ILogFileGeneratedEventArgs;
template <typename T> struct impl_ILoggingActivity;
template <typename T> struct impl_ILoggingActivity2;
template <typename T> struct impl_ILoggingActivityFactory;
template <typename T> struct impl_ILoggingChannel;
template <typename T> struct impl_ILoggingChannel2;
template <typename T> struct impl_ILoggingChannelFactory;
template <typename T> struct impl_ILoggingChannelFactory2;
template <typename T> struct impl_ILoggingChannelOptions;
template <typename T> struct impl_ILoggingChannelOptionsFactory;
template <typename T> struct impl_ILoggingFields;
template <typename T> struct impl_ILoggingOptions;
template <typename T> struct impl_ILoggingOptionsFactory;
template <typename T> struct impl_ILoggingSession;
template <typename T> struct impl_ILoggingSessionFactory;
template <typename T> struct impl_ILoggingTarget;
template <typename T> struct impl_ITracingStatusChangedEventArgs;

}

namespace Windows::Foundation::Diagnostics {

enum class CausalityRelation
{
    AssignDelegate = 0,
    Join = 1,
    Choice = 2,
    Cancel = 3,
    Error = 4,
};

enum class CausalitySource
{
    Application = 0,
    Library = 1,
    System = 2,
};

enum class CausalitySynchronousWork
{
    CompletionNotification = 0,
    ProgressNotification = 1,
    Execution = 2,
};

enum class CausalityTraceLevel
{
    Required = 0,
    Important = 1,
    Verbose = 2,
};

enum class ErrorOptions : unsigned
{
    None = 0x0,
    SuppressExceptions = 0x1,
    ForceExceptions = 0x2,
    UseSetErrorInfo = 0x4,
    SuppressSetErrorInfo = 0x8,
};

DEFINE_ENUM_FLAG_OPERATORS(ErrorOptions)

enum class LoggingFieldFormat
{
    Default = 0,
    Hidden = 1,
    String = 2,
    Boolean = 3,
    Hexadecimal = 4,
    ProcessId = 5,
    ThreadId = 6,
    Port = 7,
    Ipv4Address = 8,
    Ipv6Address = 9,
    SocketAddress = 10,
    Xml = 11,
    Json = 12,
    Win32Error = 13,
    NTStatus = 14,
    HResult = 15,
    FileTime = 16,
    Signed = 17,
    Unsigned = 18,
};

enum class LoggingLevel
{
    Verbose = 0,
    Information = 1,
    Warning = 2,
    Error = 3,
    Critical = 4,
};

enum class LoggingOpcode
{
    Info = 0,
    Start = 1,
    Stop = 2,
    Reply = 6,
    Resume = 7,
    Suspend = 8,
    Send = 9,
};

}

}
