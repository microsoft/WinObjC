// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Web.Http.Diagnostics.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_5541d8a7_497c_5aa4_86fc_7713adbf2a2c
#define WINRT_GENERIC_5541d8a7_497c_5aa4_86fc_7713adbf2a2c
template <> struct __declspec(uuid("5541d8a7-497c-5aa4-86fc-7713adbf2a2c")) __declspec(novtable) IReference<Windows::Foundation::DateTime> : impl_IReference<Windows::Foundation::DateTime> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_e9af27d3_80e8_5aff_a7e5_1b221787f096
#define WINRT_GENERIC_e9af27d3_80e8_5aff_a7e5_1b221787f096
template <> struct __declspec(uuid("e9af27d3-80e8-5aff-a7e5-1b221787f096")) __declspec(novtable) IVectorView<Windows::Web::Http::Diagnostics::HttpDiagnosticSourceLocation> : impl_IVectorView<Windows::Web::Http::Diagnostics::HttpDiagnosticSourceLocation> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_f8e10321_47bd_526a_a9b2_3bf12f725f8b
#define WINRT_GENERIC_f8e10321_47bd_526a_a9b2_3bf12f725f8b
template <> struct __declspec(uuid("f8e10321-47bd-526a-a9b2-3bf12f725f8b")) __declspec(novtable) TypedEventHandler<Windows::Web::Http::Diagnostics::HttpDiagnosticProvider, Windows::Web::Http::Diagnostics::HttpDiagnosticProviderRequestSentEventArgs> : impl_TypedEventHandler<Windows::Web::Http::Diagnostics::HttpDiagnosticProvider, Windows::Web::Http::Diagnostics::HttpDiagnosticProviderRequestSentEventArgs> {};
#endif

#ifndef WINRT_GENERIC_2eef1846_8176_52af_8d2b_e0c932512e9f
#define WINRT_GENERIC_2eef1846_8176_52af_8d2b_e0c932512e9f
template <> struct __declspec(uuid("2eef1846-8176-52af-8d2b-e0c932512e9f")) __declspec(novtable) TypedEventHandler<Windows::Web::Http::Diagnostics::HttpDiagnosticProvider, Windows::Web::Http::Diagnostics::HttpDiagnosticProviderResponseReceivedEventArgs> : impl_TypedEventHandler<Windows::Web::Http::Diagnostics::HttpDiagnosticProvider, Windows::Web::Http::Diagnostics::HttpDiagnosticProviderResponseReceivedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_2281ad23_9c8d_5d82_9b20_bcf157b04fd9
#define WINRT_GENERIC_2281ad23_9c8d_5d82_9b20_bcf157b04fd9
template <> struct __declspec(uuid("2281ad23-9c8d-5d82-9b20-bcf157b04fd9")) __declspec(novtable) TypedEventHandler<Windows::Web::Http::Diagnostics::HttpDiagnosticProvider, Windows::Web::Http::Diagnostics::HttpDiagnosticProviderRequestResponseCompletedEventArgs> : impl_TypedEventHandler<Windows::Web::Http::Diagnostics::HttpDiagnosticProvider, Windows::Web::Http::Diagnostics::HttpDiagnosticProviderRequestResponseCompletedEventArgs> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_807b6ed4_5f42_5199_b231_60cce2c76940
#define WINRT_GENERIC_807b6ed4_5f42_5199_b231_60cce2c76940
template <> struct __declspec(uuid("807b6ed4-5f42-5199-b231-60cce2c76940")) __declspec(novtable) IIterator<Windows::Web::Http::Diagnostics::HttpDiagnosticSourceLocation> : impl_IIterator<Windows::Web::Http::Diagnostics::HttpDiagnosticSourceLocation> {};
#endif

#ifndef WINRT_GENERIC_4286ca1a_a4c5_5ae8_9da9_5bfa24768e22
#define WINRT_GENERIC_4286ca1a_a4c5_5ae8_9da9_5bfa24768e22
template <> struct __declspec(uuid("4286ca1a-a4c5-5ae8-9da9-5bfa24768e22")) __declspec(novtable) IIterable<Windows::Web::Http::Diagnostics::HttpDiagnosticSourceLocation> : impl_IIterable<Windows::Web::Http::Diagnostics::HttpDiagnosticSourceLocation> {};
#endif


}

namespace Windows::Web::Http::Diagnostics {

struct IHttpDiagnosticProvider :
    Windows::Foundation::IInspectable,
    impl::consume<IHttpDiagnosticProvider>
{
    IHttpDiagnosticProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IHttpDiagnosticProviderRequestResponseCompletedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IHttpDiagnosticProviderRequestResponseCompletedEventArgs>
{
    IHttpDiagnosticProviderRequestResponseCompletedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IHttpDiagnosticProviderRequestResponseTimestamps :
    Windows::Foundation::IInspectable,
    impl::consume<IHttpDiagnosticProviderRequestResponseTimestamps>
{
    IHttpDiagnosticProviderRequestResponseTimestamps(std::nullptr_t = nullptr) noexcept {}
};

struct IHttpDiagnosticProviderRequestSentEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IHttpDiagnosticProviderRequestSentEventArgs>
{
    IHttpDiagnosticProviderRequestSentEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IHttpDiagnosticProviderResponseReceivedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IHttpDiagnosticProviderResponseReceivedEventArgs>
{
    IHttpDiagnosticProviderResponseReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IHttpDiagnosticProviderStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IHttpDiagnosticProviderStatics>
{
    IHttpDiagnosticProviderStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IHttpDiagnosticSourceLocation :
    Windows::Foundation::IInspectable,
    impl::consume<IHttpDiagnosticSourceLocation>
{
    IHttpDiagnosticSourceLocation(std::nullptr_t = nullptr) noexcept {}
};

}

}
