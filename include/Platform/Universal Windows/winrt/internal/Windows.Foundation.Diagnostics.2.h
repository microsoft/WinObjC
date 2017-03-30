// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Foundation.Diagnostics.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_2bf27008_2eb4_5675_b1cd_e9906cc5ce64
#define WINRT_GENERIC_2bf27008_2eb4_5675_b1cd_e9906cc5ce64
template <> struct __declspec(uuid("2bf27008-2eb4-5675-b1cd-e9906cc5ce64")) __declspec(novtable) EventHandler<Windows::Foundation::Diagnostics::TracingStatusChangedEventArgs> : impl_EventHandler<Windows::Foundation::Diagnostics::TracingStatusChangedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_5e52f8ce_aced_5a42_95b4_f674dd84885e
#define WINRT_GENERIC_5e52f8ce_aced_5a42_95b4_f674dd84885e
template <> struct __declspec(uuid("5e52f8ce-aced-5a42-95b4-f674dd84885e")) __declspec(novtable) IAsyncOperation<Windows::Storage::StorageFile> : impl_IAsyncOperation<Windows::Storage::StorageFile> {};
#endif

#ifndef WINRT_GENERIC_9b05106d_77e0_5c24_82b0_9b2dc8f79671
#define WINRT_GENERIC_9b05106d_77e0_5c24_82b0_9b2dc8f79671
template <> struct __declspec(uuid("9b05106d-77e0-5c24-82b0-9b2dc8f79671")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Diagnostics::ErrorDetails> : impl_IAsyncOperation<Windows::Foundation::Diagnostics::ErrorDetails> {};
#endif

#ifndef WINRT_GENERIC_52c9c2a1_54a3_5ef9_9aff_014e7c454655
#define WINRT_GENERIC_52c9c2a1_54a3_5ef9_9aff_014e7c454655
template <> struct __declspec(uuid("52c9c2a1-54a3-5ef9-9aff-014e7c454655")) __declspec(novtable) TypedEventHandler<Windows::Foundation::Diagnostics::ILoggingChannel, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::Foundation::Diagnostics::ILoggingChannel, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_0c6563b0_9d8b_5b60_994b_dee1174d1efb
#define WINRT_GENERIC_0c6563b0_9d8b_5b60_994b_dee1174d1efb
template <> struct __declspec(uuid("0c6563b0-9d8b-5b60-994b-dee1174d1efb")) __declspec(novtable) TypedEventHandler<Windows::Foundation::Diagnostics::IFileLoggingSession, Windows::Foundation::Diagnostics::LogFileGeneratedEventArgs> : impl_TypedEventHandler<Windows::Foundation::Diagnostics::IFileLoggingSession, Windows::Foundation::Diagnostics::LogFileGeneratedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_e521c894_2c26_5946_9e61_2b5e188d01ed
#define WINRT_GENERIC_e521c894_2c26_5946_9e61_2b5e188d01ed
template <> struct __declspec(uuid("e521c894-2c26-5946-9e61-2b5e188d01ed")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Storage::StorageFile> : impl_AsyncOperationCompletedHandler<Windows::Storage::StorageFile> {};
#endif

#ifndef WINRT_GENERIC_a6997f9d_7195_5972_8ecd_1c73aa5cb312
#define WINRT_GENERIC_a6997f9d_7195_5972_8ecd_1c73aa5cb312
template <> struct __declspec(uuid("a6997f9d-7195-5972-8ecd-1c73aa5cb312")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Diagnostics::ErrorDetails> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Diagnostics::ErrorDetails> {};
#endif


}

namespace Windows::Foundation::Diagnostics {

struct IAsyncCausalityTracerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IAsyncCausalityTracerStatics>
{
    IAsyncCausalityTracerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IErrorDetails :
    Windows::Foundation::IInspectable,
    impl::consume<IErrorDetails>
{
    IErrorDetails(std::nullptr_t = nullptr) noexcept {}
};

struct IErrorDetailsStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IErrorDetailsStatics>
{
    IErrorDetailsStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IErrorReportingSettings :
    Windows::Foundation::IInspectable,
    impl::consume<IErrorReportingSettings>
{
    IErrorReportingSettings(std::nullptr_t = nullptr) noexcept {}
};

struct IFileLoggingSession :
    Windows::Foundation::IInspectable,
    impl::consume<IFileLoggingSession>,
    impl::require<IFileLoggingSession, Windows::Foundation::IClosable>
{
    IFileLoggingSession(std::nullptr_t = nullptr) noexcept {}
};

struct IFileLoggingSessionFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IFileLoggingSessionFactory>
{
    IFileLoggingSessionFactory(std::nullptr_t = nullptr) noexcept {}
};

struct ILogFileGeneratedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<ILogFileGeneratedEventArgs>
{
    ILogFileGeneratedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct ILoggingActivity :
    Windows::Foundation::IInspectable,
    impl::consume<ILoggingActivity>,
    impl::require<ILoggingActivity, Windows::Foundation::IClosable>
{
    ILoggingActivity(std::nullptr_t = nullptr) noexcept {}
};

struct ILoggingActivity2 :
    Windows::Foundation::IInspectable,
    impl::consume<ILoggingActivity2>,
    impl::require<ILoggingActivity2, Windows::Foundation::Diagnostics::ILoggingActivity, Windows::Foundation::Diagnostics::ILoggingTarget, Windows::Foundation::IClosable>
{
    ILoggingActivity2(std::nullptr_t = nullptr) noexcept {}
};

struct ILoggingActivityFactory :
    Windows::Foundation::IInspectable,
    impl::consume<ILoggingActivityFactory>
{
    ILoggingActivityFactory(std::nullptr_t = nullptr) noexcept {}
};

struct ILoggingChannel :
    Windows::Foundation::IInspectable,
    impl::consume<ILoggingChannel>,
    impl::require<ILoggingChannel, Windows::Foundation::IClosable>
{
    ILoggingChannel(std::nullptr_t = nullptr) noexcept {}
};

struct ILoggingChannel2 :
    Windows::Foundation::IInspectable,
    impl::consume<ILoggingChannel2>,
    impl::require<ILoggingChannel2, Windows::Foundation::Diagnostics::ILoggingChannel, Windows::Foundation::Diagnostics::ILoggingTarget, Windows::Foundation::IClosable>
{
    ILoggingChannel2(std::nullptr_t = nullptr) noexcept {}
};

struct ILoggingChannelFactory :
    Windows::Foundation::IInspectable,
    impl::consume<ILoggingChannelFactory>
{
    ILoggingChannelFactory(std::nullptr_t = nullptr) noexcept {}
};

struct ILoggingChannelFactory2 :
    Windows::Foundation::IInspectable,
    impl::consume<ILoggingChannelFactory2>
{
    ILoggingChannelFactory2(std::nullptr_t = nullptr) noexcept {}
};

struct ILoggingChannelOptions :
    Windows::Foundation::IInspectable,
    impl::consume<ILoggingChannelOptions>
{
    ILoggingChannelOptions(std::nullptr_t = nullptr) noexcept {}
};

struct ILoggingChannelOptionsFactory :
    Windows::Foundation::IInspectable,
    impl::consume<ILoggingChannelOptionsFactory>
{
    ILoggingChannelOptionsFactory(std::nullptr_t = nullptr) noexcept {}
};

struct ILoggingFields :
    Windows::Foundation::IInspectable,
    impl::consume<ILoggingFields>
{
    ILoggingFields(std::nullptr_t = nullptr) noexcept {}
};

struct ILoggingOptions :
    Windows::Foundation::IInspectable,
    impl::consume<ILoggingOptions>
{
    ILoggingOptions(std::nullptr_t = nullptr) noexcept {}
};

struct ILoggingOptionsFactory :
    Windows::Foundation::IInspectable,
    impl::consume<ILoggingOptionsFactory>
{
    ILoggingOptionsFactory(std::nullptr_t = nullptr) noexcept {}
};

struct ILoggingSession :
    Windows::Foundation::IInspectable,
    impl::consume<ILoggingSession>,
    impl::require<ILoggingSession, Windows::Foundation::IClosable>
{
    ILoggingSession(std::nullptr_t = nullptr) noexcept {}
};

struct ILoggingSessionFactory :
    Windows::Foundation::IInspectable,
    impl::consume<ILoggingSessionFactory>
{
    ILoggingSessionFactory(std::nullptr_t = nullptr) noexcept {}
};

struct ILoggingTarget :
    Windows::Foundation::IInspectable,
    impl::consume<ILoggingTarget>
{
    ILoggingTarget(std::nullptr_t = nullptr) noexcept {}
};

struct ITracingStatusChangedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<ITracingStatusChangedEventArgs>
{
    ITracingStatusChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

}

}
