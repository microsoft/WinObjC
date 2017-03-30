// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Web.Http.Diagnostics.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.System.Diagnostics.0.h"
#include "Windows.Web.Http.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Web::Http::Diagnostics {

struct __declspec(uuid("bd811501-a056-4d39-b174-833b7b03b02c")) __declspec(novtable) IHttpDiagnosticProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Start() = 0;
    virtual HRESULT __stdcall abi_Stop() = 0;
    virtual HRESULT __stdcall add_RequestSent(Windows::Foundation::TypedEventHandler<Windows::Web::Http::Diagnostics::HttpDiagnosticProvider, Windows::Web::Http::Diagnostics::HttpDiagnosticProviderRequestSentEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_RequestSent(event_token token) = 0;
    virtual HRESULT __stdcall add_ResponseReceived(Windows::Foundation::TypedEventHandler<Windows::Web::Http::Diagnostics::HttpDiagnosticProvider, Windows::Web::Http::Diagnostics::HttpDiagnosticProviderResponseReceivedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ResponseReceived(event_token token) = 0;
    virtual HRESULT __stdcall add_RequestResponseCompleted(Windows::Foundation::TypedEventHandler<Windows::Web::Http::Diagnostics::HttpDiagnosticProvider, Windows::Web::Http::Diagnostics::HttpDiagnosticProviderRequestResponseCompletedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_RequestResponseCompleted(event_token token) = 0;
};

struct __declspec(uuid("735f98ee-94f6-4532-b26e-61e1b1e4efd4")) __declspec(novtable) IHttpDiagnosticProviderRequestResponseCompletedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ActivityId(GUID * value) = 0;
    virtual HRESULT __stdcall get_Timestamps(Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseTimestamps ** value) = 0;
    virtual HRESULT __stdcall get_RequestedUri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall get_ProcessId(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_ThreadId(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_Initiator(winrt::Windows::Web::Http::Diagnostics::HttpDiagnosticRequestInitiator * value) = 0;
    virtual HRESULT __stdcall get_SourceLocations(Windows::Foundation::Collections::IVectorView<Windows::Web::Http::Diagnostics::HttpDiagnosticSourceLocation> ** value) = 0;
};

struct __declspec(uuid("e0afde10-55cf-4c01-91d4-a20557d849f0")) __declspec(novtable) IHttpDiagnosticProviderRequestResponseTimestamps : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CacheCheckedTimestamp(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall get_ConnectionInitiatedTimestamp(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall get_NameResolvedTimestamp(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall get_SslNegotiatedTimestamp(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall get_ConnectionCompletedTimestamp(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall get_RequestSentTimestamp(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall get_RequestCompletedTimestamp(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall get_ResponseReceivedTimestamp(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall get_ResponseCompletedTimestamp(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
};

struct __declspec(uuid("3f5196d0-4c1f-4ebe-a57a-06930771c50d")) __declspec(novtable) IHttpDiagnosticProviderRequestSentEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Timestamp(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_ActivityId(GUID * value) = 0;
    virtual HRESULT __stdcall get_Message(Windows::Web::Http::IHttpRequestMessage ** value) = 0;
    virtual HRESULT __stdcall get_ProcessId(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_ThreadId(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_Initiator(winrt::Windows::Web::Http::Diagnostics::HttpDiagnosticRequestInitiator * value) = 0;
    virtual HRESULT __stdcall get_SourceLocations(Windows::Foundation::Collections::IVectorView<Windows::Web::Http::Diagnostics::HttpDiagnosticSourceLocation> ** value) = 0;
};

struct __declspec(uuid("a0a2566c-ab5f-4d66-bb2d-084cf41635d0")) __declspec(novtable) IHttpDiagnosticProviderResponseReceivedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Timestamp(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_ActivityId(GUID * value) = 0;
    virtual HRESULT __stdcall get_Message(Windows::Web::Http::IHttpResponseMessage ** value) = 0;
};

struct __declspec(uuid("5b824ec1-6a6c-47cc-afec-1e86bc26053b")) __declspec(novtable) IHttpDiagnosticProviderStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateFromProcessDiagnosticInfo(Windows::System::Diagnostics::IProcessDiagnosticInfo * processDiagnosticInfo, Windows::Web::Http::Diagnostics::IHttpDiagnosticProvider ** value) = 0;
};

struct __declspec(uuid("54a9d260-8860-423f-b6fa-d77716f647a7")) __declspec(novtable) IHttpDiagnosticSourceLocation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SourceUri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall get_LineNumber(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_ColumnNumber(uint64_t * value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Web::Http::Diagnostics::HttpDiagnosticProvider> { using default_interface = Windows::Web::Http::Diagnostics::IHttpDiagnosticProvider; };
template <> struct traits<Windows::Web::Http::Diagnostics::HttpDiagnosticProviderRequestResponseCompletedEventArgs> { using default_interface = Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseCompletedEventArgs; };
template <> struct traits<Windows::Web::Http::Diagnostics::HttpDiagnosticProviderRequestResponseTimestamps> { using default_interface = Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseTimestamps; };
template <> struct traits<Windows::Web::Http::Diagnostics::HttpDiagnosticProviderRequestSentEventArgs> { using default_interface = Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestSentEventArgs; };
template <> struct traits<Windows::Web::Http::Diagnostics::HttpDiagnosticProviderResponseReceivedEventArgs> { using default_interface = Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderResponseReceivedEventArgs; };
template <> struct traits<Windows::Web::Http::Diagnostics::HttpDiagnosticSourceLocation> { using default_interface = Windows::Web::Http::Diagnostics::IHttpDiagnosticSourceLocation; };

}

namespace Windows::Web::Http::Diagnostics {

template <typename D>
struct WINRT_EBO impl_IHttpDiagnosticProvider
{
    void Start() const;
    void Stop() const;
    event_token RequestSent(const Windows::Foundation::TypedEventHandler<Windows::Web::Http::Diagnostics::HttpDiagnosticProvider, Windows::Web::Http::Diagnostics::HttpDiagnosticProviderRequestSentEventArgs> & handler) const;
    using RequestSent_revoker = event_revoker<IHttpDiagnosticProvider>;
    RequestSent_revoker RequestSent(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Web::Http::Diagnostics::HttpDiagnosticProvider, Windows::Web::Http::Diagnostics::HttpDiagnosticProviderRequestSentEventArgs> & handler) const;
    void RequestSent(event_token token) const;
    event_token ResponseReceived(const Windows::Foundation::TypedEventHandler<Windows::Web::Http::Diagnostics::HttpDiagnosticProvider, Windows::Web::Http::Diagnostics::HttpDiagnosticProviderResponseReceivedEventArgs> & handler) const;
    using ResponseReceived_revoker = event_revoker<IHttpDiagnosticProvider>;
    ResponseReceived_revoker ResponseReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Web::Http::Diagnostics::HttpDiagnosticProvider, Windows::Web::Http::Diagnostics::HttpDiagnosticProviderResponseReceivedEventArgs> & handler) const;
    void ResponseReceived(event_token token) const;
    event_token RequestResponseCompleted(const Windows::Foundation::TypedEventHandler<Windows::Web::Http::Diagnostics::HttpDiagnosticProvider, Windows::Web::Http::Diagnostics::HttpDiagnosticProviderRequestResponseCompletedEventArgs> & handler) const;
    using RequestResponseCompleted_revoker = event_revoker<IHttpDiagnosticProvider>;
    RequestResponseCompleted_revoker RequestResponseCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Web::Http::Diagnostics::HttpDiagnosticProvider, Windows::Web::Http::Diagnostics::HttpDiagnosticProviderRequestResponseCompletedEventArgs> & handler) const;
    void RequestResponseCompleted(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpDiagnosticProviderRequestResponseCompletedEventArgs
{
    GUID ActivityId() const;
    Windows::Web::Http::Diagnostics::HttpDiagnosticProviderRequestResponseTimestamps Timestamps() const;
    Windows::Foundation::Uri RequestedUri() const;
    uint32_t ProcessId() const;
    uint32_t ThreadId() const;
    Windows::Web::Http::Diagnostics::HttpDiagnosticRequestInitiator Initiator() const;
    Windows::Foundation::Collections::IVectorView<Windows::Web::Http::Diagnostics::HttpDiagnosticSourceLocation> SourceLocations() const;
};

template <typename D>
struct WINRT_EBO impl_IHttpDiagnosticProviderRequestResponseTimestamps
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> CacheCheckedTimestamp() const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> ConnectionInitiatedTimestamp() const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> NameResolvedTimestamp() const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> SslNegotiatedTimestamp() const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> ConnectionCompletedTimestamp() const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> RequestSentTimestamp() const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> RequestCompletedTimestamp() const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> ResponseReceivedTimestamp() const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> ResponseCompletedTimestamp() const;
};

template <typename D>
struct WINRT_EBO impl_IHttpDiagnosticProviderRequestSentEventArgs
{
    Windows::Foundation::DateTime Timestamp() const;
    GUID ActivityId() const;
    Windows::Web::Http::HttpRequestMessage Message() const;
    uint32_t ProcessId() const;
    uint32_t ThreadId() const;
    Windows::Web::Http::Diagnostics::HttpDiagnosticRequestInitiator Initiator() const;
    Windows::Foundation::Collections::IVectorView<Windows::Web::Http::Diagnostics::HttpDiagnosticSourceLocation> SourceLocations() const;
};

template <typename D>
struct WINRT_EBO impl_IHttpDiagnosticProviderResponseReceivedEventArgs
{
    Windows::Foundation::DateTime Timestamp() const;
    GUID ActivityId() const;
    Windows::Web::Http::HttpResponseMessage Message() const;
};

template <typename D>
struct WINRT_EBO impl_IHttpDiagnosticProviderStatics
{
    Windows::Web::Http::Diagnostics::HttpDiagnosticProvider CreateFromProcessDiagnosticInfo(const Windows::System::Diagnostics::ProcessDiagnosticInfo & processDiagnosticInfo) const;
};

template <typename D>
struct WINRT_EBO impl_IHttpDiagnosticSourceLocation
{
    Windows::Foundation::Uri SourceUri() const;
    uint64_t LineNumber() const;
    uint64_t ColumnNumber() const;
};

}

namespace impl {

template <> struct traits<Windows::Web::Http::Diagnostics::IHttpDiagnosticProvider>
{
    using abi = ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProvider;
    template <typename D> using consume = Windows::Web::Http::Diagnostics::impl_IHttpDiagnosticProvider<D>;
};

template <> struct traits<Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseCompletedEventArgs>
{
    using abi = ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseCompletedEventArgs;
    template <typename D> using consume = Windows::Web::Http::Diagnostics::impl_IHttpDiagnosticProviderRequestResponseCompletedEventArgs<D>;
};

template <> struct traits<Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseTimestamps>
{
    using abi = ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseTimestamps;
    template <typename D> using consume = Windows::Web::Http::Diagnostics::impl_IHttpDiagnosticProviderRequestResponseTimestamps<D>;
};

template <> struct traits<Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestSentEventArgs>
{
    using abi = ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestSentEventArgs;
    template <typename D> using consume = Windows::Web::Http::Diagnostics::impl_IHttpDiagnosticProviderRequestSentEventArgs<D>;
};

template <> struct traits<Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderResponseReceivedEventArgs>
{
    using abi = ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderResponseReceivedEventArgs;
    template <typename D> using consume = Windows::Web::Http::Diagnostics::impl_IHttpDiagnosticProviderResponseReceivedEventArgs<D>;
};

template <> struct traits<Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderStatics>
{
    using abi = ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderStatics;
    template <typename D> using consume = Windows::Web::Http::Diagnostics::impl_IHttpDiagnosticProviderStatics<D>;
};

template <> struct traits<Windows::Web::Http::Diagnostics::IHttpDiagnosticSourceLocation>
{
    using abi = ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticSourceLocation;
    template <typename D> using consume = Windows::Web::Http::Diagnostics::impl_IHttpDiagnosticSourceLocation<D>;
};

template <> struct traits<Windows::Web::Http::Diagnostics::HttpDiagnosticProvider>
{
    using abi = ABI::Windows::Web::Http::Diagnostics::HttpDiagnosticProvider;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Diagnostics.HttpDiagnosticProvider"; }
};

template <> struct traits<Windows::Web::Http::Diagnostics::HttpDiagnosticProviderRequestResponseCompletedEventArgs>
{
    using abi = ABI::Windows::Web::Http::Diagnostics::HttpDiagnosticProviderRequestResponseCompletedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Diagnostics.HttpDiagnosticProviderRequestResponseCompletedEventArgs"; }
};

template <> struct traits<Windows::Web::Http::Diagnostics::HttpDiagnosticProviderRequestResponseTimestamps>
{
    using abi = ABI::Windows::Web::Http::Diagnostics::HttpDiagnosticProviderRequestResponseTimestamps;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Diagnostics.HttpDiagnosticProviderRequestResponseTimestamps"; }
};

template <> struct traits<Windows::Web::Http::Diagnostics::HttpDiagnosticProviderRequestSentEventArgs>
{
    using abi = ABI::Windows::Web::Http::Diagnostics::HttpDiagnosticProviderRequestSentEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Diagnostics.HttpDiagnosticProviderRequestSentEventArgs"; }
};

template <> struct traits<Windows::Web::Http::Diagnostics::HttpDiagnosticProviderResponseReceivedEventArgs>
{
    using abi = ABI::Windows::Web::Http::Diagnostics::HttpDiagnosticProviderResponseReceivedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Diagnostics.HttpDiagnosticProviderResponseReceivedEventArgs"; }
};

template <> struct traits<Windows::Web::Http::Diagnostics::HttpDiagnosticSourceLocation>
{
    using abi = ABI::Windows::Web::Http::Diagnostics::HttpDiagnosticSourceLocation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Http.Diagnostics.HttpDiagnosticSourceLocation"; }
};

}

}
