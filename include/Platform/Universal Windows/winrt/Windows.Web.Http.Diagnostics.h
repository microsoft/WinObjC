// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Web.Http.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.System.Diagnostics.3.h"
#include "internal/Windows.Web.Http.Diagnostics.3.h"
#include "Windows.Web.Http.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Web::Http::Diagnostics::IHttpDiagnosticProvider> : produce_base<D, Windows::Web::Http::Diagnostics::IHttpDiagnosticProvider>
{
    HRESULT __stdcall abi_Start() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Stop() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stop();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_RequestSent(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Web::Http::Diagnostics::HttpDiagnosticProvider, Windows::Web::Http::Diagnostics::HttpDiagnosticProviderRequestSentEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().RequestSent(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Web::Http::Diagnostics::HttpDiagnosticProvider, Windows::Web::Http::Diagnostics::HttpDiagnosticProviderRequestSentEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_RequestSent(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequestSent(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ResponseReceived(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Web::Http::Diagnostics::HttpDiagnosticProvider, Windows::Web::Http::Diagnostics::HttpDiagnosticProviderResponseReceivedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ResponseReceived(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Web::Http::Diagnostics::HttpDiagnosticProvider, Windows::Web::Http::Diagnostics::HttpDiagnosticProviderResponseReceivedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ResponseReceived(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ResponseReceived(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_RequestResponseCompleted(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Web::Http::Diagnostics::HttpDiagnosticProvider, Windows::Web::Http::Diagnostics::HttpDiagnosticProviderRequestResponseCompletedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().RequestResponseCompleted(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Web::Http::Diagnostics::HttpDiagnosticProvider, Windows::Web::Http::Diagnostics::HttpDiagnosticProviderRequestResponseCompletedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_RequestResponseCompleted(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequestResponseCompleted(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseCompletedEventArgs> : produce_base<D, Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseCompletedEventArgs>
{
    HRESULT __stdcall get_ActivityId(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ActivityId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Timestamps(impl::abi_arg_out<Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseTimestamps> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Timestamps());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RequestedUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequestedUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProcessId(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProcessId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ThreadId(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ThreadId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Initiator(Windows::Web::Http::Diagnostics::HttpDiagnosticRequestInitiator * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Initiator());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SourceLocations(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Web::Http::Diagnostics::HttpDiagnosticSourceLocation>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourceLocations());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseTimestamps> : produce_base<D, Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseTimestamps>
{
    HRESULT __stdcall get_CacheCheckedTimestamp(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CacheCheckedTimestamp());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ConnectionInitiatedTimestamp(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ConnectionInitiatedTimestamp());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NameResolvedTimestamp(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NameResolvedTimestamp());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SslNegotiatedTimestamp(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SslNegotiatedTimestamp());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ConnectionCompletedTimestamp(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ConnectionCompletedTimestamp());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RequestSentTimestamp(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequestSentTimestamp());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RequestCompletedTimestamp(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequestCompletedTimestamp());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ResponseReceivedTimestamp(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ResponseReceivedTimestamp());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ResponseCompletedTimestamp(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ResponseCompletedTimestamp());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestSentEventArgs> : produce_base<D, Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestSentEventArgs>
{
    HRESULT __stdcall get_Timestamp(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Timestamp());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ActivityId(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ActivityId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Message(impl::abi_arg_out<Windows::Web::Http::IHttpRequestMessage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Message());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProcessId(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProcessId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ThreadId(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ThreadId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Initiator(Windows::Web::Http::Diagnostics::HttpDiagnosticRequestInitiator * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Initiator());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SourceLocations(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Web::Http::Diagnostics::HttpDiagnosticSourceLocation>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourceLocations());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderResponseReceivedEventArgs> : produce_base<D, Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderResponseReceivedEventArgs>
{
    HRESULT __stdcall get_Timestamp(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Timestamp());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ActivityId(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ActivityId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Message(impl::abi_arg_out<Windows::Web::Http::IHttpResponseMessage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Message());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderStatics> : produce_base<D, Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderStatics>
{
    HRESULT __stdcall abi_CreateFromProcessDiagnosticInfo(impl::abi_arg_in<Windows::System::Diagnostics::IProcessDiagnosticInfo> processDiagnosticInfo, impl::abi_arg_out<Windows::Web::Http::Diagnostics::IHttpDiagnosticProvider> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateFromProcessDiagnosticInfo(*reinterpret_cast<const Windows::System::Diagnostics::ProcessDiagnosticInfo *>(&processDiagnosticInfo)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Diagnostics::IHttpDiagnosticSourceLocation> : produce_base<D, Windows::Web::Http::Diagnostics::IHttpDiagnosticSourceLocation>
{
    HRESULT __stdcall get_SourceUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourceUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LineNumber(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LineNumber());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ColumnNumber(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ColumnNumber());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Web::Http::Diagnostics {

template <typename D> Windows::Foundation::Uri impl_IHttpDiagnosticSourceLocation<D>::SourceUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IHttpDiagnosticSourceLocation)->get_SourceUri(put_abi(value)));
    return value;
}

template <typename D> uint64_t impl_IHttpDiagnosticSourceLocation<D>::LineNumber() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IHttpDiagnosticSourceLocation)->get_LineNumber(&value));
    return value;
}

template <typename D> uint64_t impl_IHttpDiagnosticSourceLocation<D>::ColumnNumber() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IHttpDiagnosticSourceLocation)->get_ColumnNumber(&value));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IHttpDiagnosticProviderRequestSentEventArgs<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IHttpDiagnosticProviderRequestSentEventArgs)->get_Timestamp(put_abi(value)));
    return value;
}

template <typename D> GUID impl_IHttpDiagnosticProviderRequestSentEventArgs<D>::ActivityId() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(IHttpDiagnosticProviderRequestSentEventArgs)->get_ActivityId(&value));
    return value;
}

template <typename D> Windows::Web::Http::HttpRequestMessage impl_IHttpDiagnosticProviderRequestSentEventArgs<D>::Message() const
{
    Windows::Web::Http::HttpRequestMessage value { nullptr };
    check_hresult(WINRT_SHIM(IHttpDiagnosticProviderRequestSentEventArgs)->get_Message(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IHttpDiagnosticProviderRequestSentEventArgs<D>::ProcessId() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IHttpDiagnosticProviderRequestSentEventArgs)->get_ProcessId(&value));
    return value;
}

template <typename D> uint32_t impl_IHttpDiagnosticProviderRequestSentEventArgs<D>::ThreadId() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IHttpDiagnosticProviderRequestSentEventArgs)->get_ThreadId(&value));
    return value;
}

template <typename D> Windows::Web::Http::Diagnostics::HttpDiagnosticRequestInitiator impl_IHttpDiagnosticProviderRequestSentEventArgs<D>::Initiator() const
{
    Windows::Web::Http::Diagnostics::HttpDiagnosticRequestInitiator value {};
    check_hresult(WINRT_SHIM(IHttpDiagnosticProviderRequestSentEventArgs)->get_Initiator(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Web::Http::Diagnostics::HttpDiagnosticSourceLocation> impl_IHttpDiagnosticProviderRequestSentEventArgs<D>::SourceLocations() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Web::Http::Diagnostics::HttpDiagnosticSourceLocation> value;
    check_hresult(WINRT_SHIM(IHttpDiagnosticProviderRequestSentEventArgs)->get_SourceLocations(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IHttpDiagnosticProviderResponseReceivedEventArgs<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IHttpDiagnosticProviderResponseReceivedEventArgs)->get_Timestamp(put_abi(value)));
    return value;
}

template <typename D> GUID impl_IHttpDiagnosticProviderResponseReceivedEventArgs<D>::ActivityId() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(IHttpDiagnosticProviderResponseReceivedEventArgs)->get_ActivityId(&value));
    return value;
}

template <typename D> Windows::Web::Http::HttpResponseMessage impl_IHttpDiagnosticProviderResponseReceivedEventArgs<D>::Message() const
{
    Windows::Web::Http::HttpResponseMessage value { nullptr };
    check_hresult(WINRT_SHIM(IHttpDiagnosticProviderResponseReceivedEventArgs)->get_Message(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IHttpDiagnosticProviderRequestResponseTimestamps<D>::CacheCheckedTimestamp() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(IHttpDiagnosticProviderRequestResponseTimestamps)->get_CacheCheckedTimestamp(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IHttpDiagnosticProviderRequestResponseTimestamps<D>::ConnectionInitiatedTimestamp() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(IHttpDiagnosticProviderRequestResponseTimestamps)->get_ConnectionInitiatedTimestamp(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IHttpDiagnosticProviderRequestResponseTimestamps<D>::NameResolvedTimestamp() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(IHttpDiagnosticProviderRequestResponseTimestamps)->get_NameResolvedTimestamp(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IHttpDiagnosticProviderRequestResponseTimestamps<D>::SslNegotiatedTimestamp() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(IHttpDiagnosticProviderRequestResponseTimestamps)->get_SslNegotiatedTimestamp(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IHttpDiagnosticProviderRequestResponseTimestamps<D>::ConnectionCompletedTimestamp() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(IHttpDiagnosticProviderRequestResponseTimestamps)->get_ConnectionCompletedTimestamp(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IHttpDiagnosticProviderRequestResponseTimestamps<D>::RequestSentTimestamp() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(IHttpDiagnosticProviderRequestResponseTimestamps)->get_RequestSentTimestamp(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IHttpDiagnosticProviderRequestResponseTimestamps<D>::RequestCompletedTimestamp() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(IHttpDiagnosticProviderRequestResponseTimestamps)->get_RequestCompletedTimestamp(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IHttpDiagnosticProviderRequestResponseTimestamps<D>::ResponseReceivedTimestamp() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(IHttpDiagnosticProviderRequestResponseTimestamps)->get_ResponseReceivedTimestamp(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IHttpDiagnosticProviderRequestResponseTimestamps<D>::ResponseCompletedTimestamp() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(IHttpDiagnosticProviderRequestResponseTimestamps)->get_ResponseCompletedTimestamp(put_abi(value)));
    return value;
}

template <typename D> GUID impl_IHttpDiagnosticProviderRequestResponseCompletedEventArgs<D>::ActivityId() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(IHttpDiagnosticProviderRequestResponseCompletedEventArgs)->get_ActivityId(&value));
    return value;
}

template <typename D> Windows::Web::Http::Diagnostics::HttpDiagnosticProviderRequestResponseTimestamps impl_IHttpDiagnosticProviderRequestResponseCompletedEventArgs<D>::Timestamps() const
{
    Windows::Web::Http::Diagnostics::HttpDiagnosticProviderRequestResponseTimestamps value { nullptr };
    check_hresult(WINRT_SHIM(IHttpDiagnosticProviderRequestResponseCompletedEventArgs)->get_Timestamps(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_IHttpDiagnosticProviderRequestResponseCompletedEventArgs<D>::RequestedUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IHttpDiagnosticProviderRequestResponseCompletedEventArgs)->get_RequestedUri(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IHttpDiagnosticProviderRequestResponseCompletedEventArgs<D>::ProcessId() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IHttpDiagnosticProviderRequestResponseCompletedEventArgs)->get_ProcessId(&value));
    return value;
}

template <typename D> uint32_t impl_IHttpDiagnosticProviderRequestResponseCompletedEventArgs<D>::ThreadId() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IHttpDiagnosticProviderRequestResponseCompletedEventArgs)->get_ThreadId(&value));
    return value;
}

template <typename D> Windows::Web::Http::Diagnostics::HttpDiagnosticRequestInitiator impl_IHttpDiagnosticProviderRequestResponseCompletedEventArgs<D>::Initiator() const
{
    Windows::Web::Http::Diagnostics::HttpDiagnosticRequestInitiator value {};
    check_hresult(WINRT_SHIM(IHttpDiagnosticProviderRequestResponseCompletedEventArgs)->get_Initiator(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Web::Http::Diagnostics::HttpDiagnosticSourceLocation> impl_IHttpDiagnosticProviderRequestResponseCompletedEventArgs<D>::SourceLocations() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Web::Http::Diagnostics::HttpDiagnosticSourceLocation> value;
    check_hresult(WINRT_SHIM(IHttpDiagnosticProviderRequestResponseCompletedEventArgs)->get_SourceLocations(put_abi(value)));
    return value;
}

template <typename D> Windows::Web::Http::Diagnostics::HttpDiagnosticProvider impl_IHttpDiagnosticProviderStatics<D>::CreateFromProcessDiagnosticInfo(const Windows::System::Diagnostics::ProcessDiagnosticInfo & processDiagnosticInfo) const
{
    Windows::Web::Http::Diagnostics::HttpDiagnosticProvider value { nullptr };
    check_hresult(WINRT_SHIM(IHttpDiagnosticProviderStatics)->abi_CreateFromProcessDiagnosticInfo(get_abi(processDiagnosticInfo), put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpDiagnosticProvider<D>::Start() const
{
    check_hresult(WINRT_SHIM(IHttpDiagnosticProvider)->abi_Start());
}

template <typename D> void impl_IHttpDiagnosticProvider<D>::Stop() const
{
    check_hresult(WINRT_SHIM(IHttpDiagnosticProvider)->abi_Stop());
}

template <typename D> event_token impl_IHttpDiagnosticProvider<D>::RequestSent(const Windows::Foundation::TypedEventHandler<Windows::Web::Http::Diagnostics::HttpDiagnosticProvider, Windows::Web::Http::Diagnostics::HttpDiagnosticProviderRequestSentEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IHttpDiagnosticProvider)->add_RequestSent(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IHttpDiagnosticProvider> impl_IHttpDiagnosticProvider<D>::RequestSent(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Web::Http::Diagnostics::HttpDiagnosticProvider, Windows::Web::Http::Diagnostics::HttpDiagnosticProviderRequestSentEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IHttpDiagnosticProvider>(this, &ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProvider::remove_RequestSent, RequestSent(handler));
}

template <typename D> void impl_IHttpDiagnosticProvider<D>::RequestSent(event_token token) const
{
    check_hresult(WINRT_SHIM(IHttpDiagnosticProvider)->remove_RequestSent(token));
}

template <typename D> event_token impl_IHttpDiagnosticProvider<D>::ResponseReceived(const Windows::Foundation::TypedEventHandler<Windows::Web::Http::Diagnostics::HttpDiagnosticProvider, Windows::Web::Http::Diagnostics::HttpDiagnosticProviderResponseReceivedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IHttpDiagnosticProvider)->add_ResponseReceived(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IHttpDiagnosticProvider> impl_IHttpDiagnosticProvider<D>::ResponseReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Web::Http::Diagnostics::HttpDiagnosticProvider, Windows::Web::Http::Diagnostics::HttpDiagnosticProviderResponseReceivedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IHttpDiagnosticProvider>(this, &ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProvider::remove_ResponseReceived, ResponseReceived(handler));
}

template <typename D> void impl_IHttpDiagnosticProvider<D>::ResponseReceived(event_token token) const
{
    check_hresult(WINRT_SHIM(IHttpDiagnosticProvider)->remove_ResponseReceived(token));
}

template <typename D> event_token impl_IHttpDiagnosticProvider<D>::RequestResponseCompleted(const Windows::Foundation::TypedEventHandler<Windows::Web::Http::Diagnostics::HttpDiagnosticProvider, Windows::Web::Http::Diagnostics::HttpDiagnosticProviderRequestResponseCompletedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IHttpDiagnosticProvider)->add_RequestResponseCompleted(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IHttpDiagnosticProvider> impl_IHttpDiagnosticProvider<D>::RequestResponseCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Web::Http::Diagnostics::HttpDiagnosticProvider, Windows::Web::Http::Diagnostics::HttpDiagnosticProviderRequestResponseCompletedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IHttpDiagnosticProvider>(this, &ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProvider::remove_RequestResponseCompleted, RequestResponseCompleted(handler));
}

template <typename D> void impl_IHttpDiagnosticProvider<D>::RequestResponseCompleted(event_token token) const
{
    check_hresult(WINRT_SHIM(IHttpDiagnosticProvider)->remove_RequestResponseCompleted(token));
}

inline Windows::Web::Http::Diagnostics::HttpDiagnosticProvider HttpDiagnosticProvider::CreateFromProcessDiagnosticInfo(const Windows::System::Diagnostics::ProcessDiagnosticInfo & processDiagnosticInfo)
{
    return get_activation_factory<HttpDiagnosticProvider, IHttpDiagnosticProviderStatics>().CreateFromProcessDiagnosticInfo(processDiagnosticInfo);
}

}

}
#pragma warning(pop)
