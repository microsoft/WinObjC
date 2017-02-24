// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Web.Http.Filters.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Web.Http.Headers.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Security.Cryptography.Certificates.3.h"
#include "internal/Windows.Networking.Sockets.3.h"
#include "internal/Windows.Web.Http.3.h"
#include "Windows.Web.h"
#include "Windows.Foundation.h"
#include "Windows.Foundation.Collections.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Web::Http::IHttpBufferContentFactory> : produce_base<D, Windows::Web::Http::IHttpBufferContentFactory>
{
    HRESULT __stdcall abi_CreateFromBuffer(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> content, impl::abi_arg_out<Windows::Web::Http::IHttpContent> bufferContent) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *bufferContent = detach_abi(this->shim().CreateFromBuffer(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&content)));
            return S_OK;
        }
        catch (...)
        {
            *bufferContent = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromBufferWithOffset(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> content, uint32_t offset, uint32_t count, impl::abi_arg_out<Windows::Web::Http::IHttpContent> bufferContent) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *bufferContent = detach_abi(this->shim().CreateFromBufferWithOffset(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&content), offset, count));
            return S_OK;
        }
        catch (...)
        {
            *bufferContent = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::IHttpClient> : produce_base<D, Windows::Web::Http::IHttpClient>
{
    HRESULT __stdcall abi_DeleteAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().DeleteAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetWithOptionAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, Windows::Web::Http::HttpCompletionOption completionOption, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri), completionOption));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetBufferAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Storage::Streams::IBuffer, Windows::Web::Http::HttpProgress>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetBufferAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetInputStreamAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Storage::Streams::IInputStream, Windows::Web::Http::HttpProgress>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetInputStreamAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStringAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<hstring, Windows::Web::Http::HttpProgress>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetStringAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PostAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_in<Windows::Web::Http::IHttpContent> content, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().PostAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const Windows::Web::Http::IHttpContent *>(&content)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PutAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_in<Windows::Web::Http::IHttpContent> content, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().PutAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const Windows::Web::Http::IHttpContent *>(&content)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SendRequestAsync(impl::abi_arg_in<Windows::Web::Http::IHttpRequestMessage> request, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().SendRequestAsync(*reinterpret_cast<const Windows::Web::Http::HttpRequestMessage *>(&request)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SendRequestWithOptionAsync(impl::abi_arg_in<Windows::Web::Http::IHttpRequestMessage> request, Windows::Web::Http::HttpCompletionOption completionOption, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().SendRequestAsync(*reinterpret_cast<const Windows::Web::Http::HttpRequestMessage *>(&request), completionOption));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DefaultRequestHeaders(impl::abi_arg_out<Windows::Web::Http::Headers::IHttpRequestHeaderCollection> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DefaultRequestHeaders());
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
struct produce<D, Windows::Web::Http::IHttpClientFactory> : produce_base<D, Windows::Web::Http::IHttpClientFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Web::Http::Filters::IHttpFilter> filter, impl::abi_arg_out<Windows::Web::Http::IHttpClient> client) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *client = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Web::Http::Filters::IHttpFilter *>(&filter)));
            return S_OK;
        }
        catch (...)
        {
            *client = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::IHttpContent> : produce_base<D, Windows::Web::Http::IHttpContent>
{
    HRESULT __stdcall get_Headers(impl::abi_arg_out<Windows::Web::Http::Headers::IHttpContentHeaderCollection> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Headers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_BufferAllAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().BufferAllAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReadAsBufferAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Storage::Streams::IBuffer, uint64_t>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ReadAsBufferAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReadAsInputStreamAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Storage::Streams::IInputStream, uint64_t>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ReadAsInputStreamAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReadAsStringAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<hstring, uint64_t>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ReadAsStringAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryComputeLength(uint64_t * length, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryComputeLength(*length));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_WriteToStreamAsync(impl::abi_arg_in<Windows::Storage::Streams::IOutputStream> outputStream, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().WriteToStreamAsync(*reinterpret_cast<const Windows::Storage::Streams::IOutputStream *>(&outputStream)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::IHttpCookie> : produce_base<D, Windows::Web::Http::IHttpCookie>
{
    HRESULT __stdcall get_Name(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Domain(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Domain());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Path(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Path());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Expires(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Expires());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Expires(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Expires(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::DateTime> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HttpOnly(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HttpOnly());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_HttpOnly(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HttpOnly(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Secure(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Secure());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Secure(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Secure(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Value(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Value());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Value(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Value(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::IHttpCookieFactory> : produce_base<D, Windows::Web::Http::IHttpCookieFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> name, impl::abi_arg_in<hstring> domain, impl::abi_arg_in<hstring> path, impl::abi_arg_out<Windows::Web::Http::IHttpCookie> cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const hstring *>(&domain), *reinterpret_cast<const hstring *>(&path)));
            return S_OK;
        }
        catch (...)
        {
            *cookie = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::IHttpCookieManager> : produce_base<D, Windows::Web::Http::IHttpCookieManager>
{
    HRESULT __stdcall abi_SetCookie(impl::abi_arg_in<Windows::Web::Http::IHttpCookie> cookie, bool * replaced) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *replaced = detach_abi(this->shim().SetCookie(*reinterpret_cast<const Windows::Web::Http::HttpCookie *>(&cookie)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetCookieWithThirdParty(impl::abi_arg_in<Windows::Web::Http::IHttpCookie> cookie, bool thirdParty, bool * replaced) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *replaced = detach_abi(this->shim().SetCookie(*reinterpret_cast<const Windows::Web::Http::HttpCookie *>(&cookie), thirdParty));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteCookie(impl::abi_arg_in<Windows::Web::Http::IHttpCookie> cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DeleteCookie(*reinterpret_cast<const Windows::Web::Http::HttpCookie *>(&cookie));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCookies(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Web::Http::HttpCookie>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetCookies(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri)));
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
struct produce<D, Windows::Web::Http::IHttpFormUrlEncodedContentFactory> : produce_base<D, Windows::Web::Http::IHttpFormUrlEncodedContentFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, hstring>>> content, impl::abi_arg_out<Windows::Web::Http::IHttpContent> formUrlEncodedContent) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *formUrlEncodedContent = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, hstring>> *>(&content)));
            return S_OK;
        }
        catch (...)
        {
            *formUrlEncodedContent = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::IHttpMethod> : produce_base<D, Windows::Web::Http::IHttpMethod>
{
    HRESULT __stdcall get_Method(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Method());
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
struct produce<D, Windows::Web::Http::IHttpMethodFactory> : produce_base<D, Windows::Web::Http::IHttpMethodFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> method, impl::abi_arg_out<Windows::Web::Http::IHttpMethod> httpMethod) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *httpMethod = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&method)));
            return S_OK;
        }
        catch (...)
        {
            *httpMethod = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::IHttpMethodStatics> : produce_base<D, Windows::Web::Http::IHttpMethodStatics>
{
    HRESULT __stdcall get_Delete(impl::abi_arg_out<Windows::Web::Http::IHttpMethod> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Delete());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Get(impl::abi_arg_out<Windows::Web::Http::IHttpMethod> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Get());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Head(impl::abi_arg_out<Windows::Web::Http::IHttpMethod> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Head());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Options(impl::abi_arg_out<Windows::Web::Http::IHttpMethod> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Options());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Patch(impl::abi_arg_out<Windows::Web::Http::IHttpMethod> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Patch());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Post(impl::abi_arg_out<Windows::Web::Http::IHttpMethod> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Post());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Put(impl::abi_arg_out<Windows::Web::Http::IHttpMethod> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Put());
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
struct produce<D, Windows::Web::Http::IHttpMultipartContent> : produce_base<D, Windows::Web::Http::IHttpMultipartContent>
{
    HRESULT __stdcall abi_Add(impl::abi_arg_in<Windows::Web::Http::IHttpContent> content) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Add(*reinterpret_cast<const Windows::Web::Http::IHttpContent *>(&content));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::IHttpMultipartContentFactory> : produce_base<D, Windows::Web::Http::IHttpMultipartContentFactory>
{
    HRESULT __stdcall abi_CreateWithSubtype(impl::abi_arg_in<hstring> subtype, impl::abi_arg_out<Windows::Web::Http::IHttpContent> multipartContent) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *multipartContent = detach_abi(this->shim().CreateWithSubtype(*reinterpret_cast<const hstring *>(&subtype)));
            return S_OK;
        }
        catch (...)
        {
            *multipartContent = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithSubtypeAndBoundary(impl::abi_arg_in<hstring> subtype, impl::abi_arg_in<hstring> boundary, impl::abi_arg_out<Windows::Web::Http::IHttpContent> multipartContent) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *multipartContent = detach_abi(this->shim().CreateWithSubtypeAndBoundary(*reinterpret_cast<const hstring *>(&subtype), *reinterpret_cast<const hstring *>(&boundary)));
            return S_OK;
        }
        catch (...)
        {
            *multipartContent = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::IHttpMultipartFormDataContent> : produce_base<D, Windows::Web::Http::IHttpMultipartFormDataContent>
{
    HRESULT __stdcall abi_Add(impl::abi_arg_in<Windows::Web::Http::IHttpContent> content) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Add(*reinterpret_cast<const Windows::Web::Http::IHttpContent *>(&content));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddWithName(impl::abi_arg_in<Windows::Web::Http::IHttpContent> content, impl::abi_arg_in<hstring> name) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Add(*reinterpret_cast<const Windows::Web::Http::IHttpContent *>(&content), *reinterpret_cast<const hstring *>(&name));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddWithNameAndFileName(impl::abi_arg_in<Windows::Web::Http::IHttpContent> content, impl::abi_arg_in<hstring> name, impl::abi_arg_in<hstring> fileName) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Add(*reinterpret_cast<const Windows::Web::Http::IHttpContent *>(&content), *reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const hstring *>(&fileName));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::IHttpMultipartFormDataContentFactory> : produce_base<D, Windows::Web::Http::IHttpMultipartFormDataContentFactory>
{
    HRESULT __stdcall abi_CreateWithBoundary(impl::abi_arg_in<hstring> boundary, impl::abi_arg_out<Windows::Web::Http::IHttpContent> multipartFormDataContent) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *multipartFormDataContent = detach_abi(this->shim().CreateWithBoundary(*reinterpret_cast<const hstring *>(&boundary)));
            return S_OK;
        }
        catch (...)
        {
            *multipartFormDataContent = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::IHttpRequestMessage> : produce_base<D, Windows::Web::Http::IHttpRequestMessage>
{
    HRESULT __stdcall get_Content(impl::abi_arg_out<Windows::Web::Http::IHttpContent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Content());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Content(impl::abi_arg_in<Windows::Web::Http::IHttpContent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Content(*reinterpret_cast<const Windows::Web::Http::IHttpContent *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Headers(impl::abi_arg_out<Windows::Web::Http::Headers::IHttpRequestHeaderCollection> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Headers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Method(impl::abi_arg_out<Windows::Web::Http::IHttpMethod> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Method());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Method(impl::abi_arg_in<Windows::Web::Http::IHttpMethod> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Method(*reinterpret_cast<const Windows::Web::Http::HttpMethod *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Properties(impl::abi_arg_out<Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::IInspectable>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Properties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RequestUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequestUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RequestUri(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequestUri(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TransportInformation(impl::abi_arg_out<Windows::Web::Http::IHttpTransportInformation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TransportInformation());
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
struct produce<D, Windows::Web::Http::IHttpRequestMessageFactory> : produce_base<D, Windows::Web::Http::IHttpRequestMessageFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Web::Http::IHttpMethod> method, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_out<Windows::Web::Http::IHttpRequestMessage> httpRequestMessage) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *httpRequestMessage = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Web::Http::HttpMethod *>(&method), *reinterpret_cast<const Windows::Foundation::Uri *>(&uri)));
            return S_OK;
        }
        catch (...)
        {
            *httpRequestMessage = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::IHttpResponseMessage> : produce_base<D, Windows::Web::Http::IHttpResponseMessage>
{
    HRESULT __stdcall get_Content(impl::abi_arg_out<Windows::Web::Http::IHttpContent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Content());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Content(impl::abi_arg_in<Windows::Web::Http::IHttpContent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Content(*reinterpret_cast<const Windows::Web::Http::IHttpContent *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Headers(impl::abi_arg_out<Windows::Web::Http::Headers::IHttpResponseHeaderCollection> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Headers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsSuccessStatusCode(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsSuccessStatusCode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ReasonPhrase(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReasonPhrase());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ReasonPhrase(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReasonPhrase(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RequestMessage(impl::abi_arg_out<Windows::Web::Http::IHttpRequestMessage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequestMessage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RequestMessage(impl::abi_arg_in<Windows::Web::Http::IHttpRequestMessage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequestMessage(*reinterpret_cast<const Windows::Web::Http::HttpRequestMessage *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Source(Windows::Web::Http::HttpResponseMessageSource * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Source());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Source(Windows::Web::Http::HttpResponseMessageSource value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Source(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StatusCode(Windows::Web::Http::HttpStatusCode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StatusCode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StatusCode(Windows::Web::Http::HttpStatusCode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StatusCode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Version(Windows::Web::Http::HttpVersion * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Version());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Version(Windows::Web::Http::HttpVersion value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Version(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_EnsureSuccessStatusCode(impl::abi_arg_out<Windows::Web::Http::IHttpResponseMessage> httpResponseMessage) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *httpResponseMessage = detach_abi(this->shim().EnsureSuccessStatusCode());
            return S_OK;
        }
        catch (...)
        {
            *httpResponseMessage = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::IHttpResponseMessageFactory> : produce_base<D, Windows::Web::Http::IHttpResponseMessageFactory>
{
    HRESULT __stdcall abi_Create(Windows::Web::Http::HttpStatusCode statusCode, impl::abi_arg_out<Windows::Web::Http::IHttpResponseMessage> httpResponseMessage) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *httpResponseMessage = detach_abi(this->shim().Create(statusCode));
            return S_OK;
        }
        catch (...)
        {
            *httpResponseMessage = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::IHttpStreamContentFactory> : produce_base<D, Windows::Web::Http::IHttpStreamContentFactory>
{
    HRESULT __stdcall abi_CreateFromInputStream(impl::abi_arg_in<Windows::Storage::Streams::IInputStream> content, impl::abi_arg_out<Windows::Web::Http::IHttpContent> streamContent) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *streamContent = detach_abi(this->shim().CreateFromInputStream(*reinterpret_cast<const Windows::Storage::Streams::IInputStream *>(&content)));
            return S_OK;
        }
        catch (...)
        {
            *streamContent = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::IHttpStringContentFactory> : produce_base<D, Windows::Web::Http::IHttpStringContentFactory>
{
    HRESULT __stdcall abi_CreateFromString(impl::abi_arg_in<hstring> content, impl::abi_arg_out<Windows::Web::Http::IHttpContent> stringContent) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *stringContent = detach_abi(this->shim().CreateFromString(*reinterpret_cast<const hstring *>(&content)));
            return S_OK;
        }
        catch (...)
        {
            *stringContent = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromStringWithEncoding(impl::abi_arg_in<hstring> content, Windows::Storage::Streams::UnicodeEncoding encoding, impl::abi_arg_out<Windows::Web::Http::IHttpContent> stringContent) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *stringContent = detach_abi(this->shim().CreateFromStringWithEncoding(*reinterpret_cast<const hstring *>(&content), encoding));
            return S_OK;
        }
        catch (...)
        {
            *stringContent = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromStringWithEncodingAndMediaType(impl::abi_arg_in<hstring> content, Windows::Storage::Streams::UnicodeEncoding encoding, impl::abi_arg_in<hstring> mediaType, impl::abi_arg_out<Windows::Web::Http::IHttpContent> stringContent) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *stringContent = detach_abi(this->shim().CreateFromStringWithEncodingAndMediaType(*reinterpret_cast<const hstring *>(&content), encoding, *reinterpret_cast<const hstring *>(&mediaType)));
            return S_OK;
        }
        catch (...)
        {
            *stringContent = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::IHttpTransportInformation> : produce_base<D, Windows::Web::Http::IHttpTransportInformation>
{
    HRESULT __stdcall get_ServerCertificate(impl::abi_arg_out<Windows::Security::Cryptography::Certificates::ICertificate> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServerCertificate());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServerCertificateErrorSeverity(Windows::Networking::Sockets::SocketSslErrorSeverity * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServerCertificateErrorSeverity());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServerCertificateErrors(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServerCertificateErrors());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServerIntermediateCertificates(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServerIntermediateCertificates());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Web::Http {

template <typename D> Windows::Web::Http::HttpClient impl_IHttpClientFactory<D>::Create(const Windows::Web::Http::Filters::IHttpFilter & filter) const
{
    Windows::Web::Http::HttpClient client { nullptr };
    check_hresult(WINRT_SHIM(IHttpClientFactory)->abi_Create(get_abi(filter), put_abi(client)));
    return client;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> impl_IHttpClient<D>::DeleteAsync(const Windows::Foundation::Uri & uri) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> operation;
    check_hresult(WINRT_SHIM(IHttpClient)->abi_DeleteAsync(get_abi(uri), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> impl_IHttpClient<D>::GetAsync(const Windows::Foundation::Uri & uri) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> operation;
    check_hresult(WINRT_SHIM(IHttpClient)->abi_GetAsync(get_abi(uri), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> impl_IHttpClient<D>::GetAsync(const Windows::Foundation::Uri & uri, Windows::Web::Http::HttpCompletionOption completionOption) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> operation;
    check_hresult(WINRT_SHIM(IHttpClient)->abi_GetWithOptionAsync(get_abi(uri), completionOption, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Storage::Streams::IBuffer, Windows::Web::Http::HttpProgress> impl_IHttpClient<D>::GetBufferAsync(const Windows::Foundation::Uri & uri) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Storage::Streams::IBuffer, Windows::Web::Http::HttpProgress> operation;
    check_hresult(WINRT_SHIM(IHttpClient)->abi_GetBufferAsync(get_abi(uri), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Storage::Streams::IInputStream, Windows::Web::Http::HttpProgress> impl_IHttpClient<D>::GetInputStreamAsync(const Windows::Foundation::Uri & uri) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Storage::Streams::IInputStream, Windows::Web::Http::HttpProgress> operation;
    check_hresult(WINRT_SHIM(IHttpClient)->abi_GetInputStreamAsync(get_abi(uri), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<hstring, Windows::Web::Http::HttpProgress> impl_IHttpClient<D>::GetStringAsync(const Windows::Foundation::Uri & uri) const
{
    Windows::Foundation::IAsyncOperationWithProgress<hstring, Windows::Web::Http::HttpProgress> operation;
    check_hresult(WINRT_SHIM(IHttpClient)->abi_GetStringAsync(get_abi(uri), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> impl_IHttpClient<D>::PostAsync(const Windows::Foundation::Uri & uri, const Windows::Web::Http::IHttpContent & content) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> operation;
    check_hresult(WINRT_SHIM(IHttpClient)->abi_PostAsync(get_abi(uri), get_abi(content), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> impl_IHttpClient<D>::PutAsync(const Windows::Foundation::Uri & uri, const Windows::Web::Http::IHttpContent & content) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> operation;
    check_hresult(WINRT_SHIM(IHttpClient)->abi_PutAsync(get_abi(uri), get_abi(content), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> impl_IHttpClient<D>::SendRequestAsync(const Windows::Web::Http::HttpRequestMessage & request) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> operation;
    check_hresult(WINRT_SHIM(IHttpClient)->abi_SendRequestAsync(get_abi(request), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> impl_IHttpClient<D>::SendRequestAsync(const Windows::Web::Http::HttpRequestMessage & request, Windows::Web::Http::HttpCompletionOption completionOption) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Http::HttpResponseMessage, Windows::Web::Http::HttpProgress> operation;
    check_hresult(WINRT_SHIM(IHttpClient)->abi_SendRequestWithOptionAsync(get_abi(request), completionOption, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Web::Http::Headers::HttpRequestHeaderCollection impl_IHttpClient<D>::DefaultRequestHeaders() const
{
    Windows::Web::Http::Headers::HttpRequestHeaderCollection value { nullptr };
    check_hresult(WINRT_SHIM(IHttpClient)->get_DefaultRequestHeaders(put_abi(value)));
    return value;
}

template <typename D> Windows::Web::Http::Headers::HttpContentHeaderCollection impl_IHttpContent<D>::Headers() const
{
    Windows::Web::Http::Headers::HttpContentHeaderCollection value { nullptr };
    check_hresult(WINRT_SHIM(IHttpContent)->get_Headers(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t> impl_IHttpContent<D>::BufferAllAsync() const
{
    Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t> operation;
    check_hresult(WINRT_SHIM(IHttpContent)->abi_BufferAllAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Storage::Streams::IBuffer, uint64_t> impl_IHttpContent<D>::ReadAsBufferAsync() const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Storage::Streams::IBuffer, uint64_t> operation;
    check_hresult(WINRT_SHIM(IHttpContent)->abi_ReadAsBufferAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Storage::Streams::IInputStream, uint64_t> impl_IHttpContent<D>::ReadAsInputStreamAsync() const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Storage::Streams::IInputStream, uint64_t> operation;
    check_hresult(WINRT_SHIM(IHttpContent)->abi_ReadAsInputStreamAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<hstring, uint64_t> impl_IHttpContent<D>::ReadAsStringAsync() const
{
    Windows::Foundation::IAsyncOperationWithProgress<hstring, uint64_t> operation;
    check_hresult(WINRT_SHIM(IHttpContent)->abi_ReadAsStringAsync(put_abi(operation)));
    return operation;
}

template <typename D> bool impl_IHttpContent<D>::TryComputeLength(uint64_t & length) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IHttpContent)->abi_TryComputeLength(&length, &succeeded));
    return succeeded;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t> impl_IHttpContent<D>::WriteToStreamAsync(const Windows::Storage::Streams::IOutputStream & outputStream) const
{
    Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t> operation;
    check_hresult(WINRT_SHIM(IHttpContent)->abi_WriteToStreamAsync(get_abi(outputStream), put_abi(operation)));
    return operation;
}

template <typename D> bool impl_IHttpCookieManager<D>::SetCookie(const Windows::Web::Http::HttpCookie & cookie) const
{
    bool replaced {};
    check_hresult(WINRT_SHIM(IHttpCookieManager)->abi_SetCookie(get_abi(cookie), &replaced));
    return replaced;
}

template <typename D> bool impl_IHttpCookieManager<D>::SetCookie(const Windows::Web::Http::HttpCookie & cookie, bool thirdParty) const
{
    bool replaced {};
    check_hresult(WINRT_SHIM(IHttpCookieManager)->abi_SetCookieWithThirdParty(get_abi(cookie), thirdParty, &replaced));
    return replaced;
}

template <typename D> void impl_IHttpCookieManager<D>::DeleteCookie(const Windows::Web::Http::HttpCookie & cookie) const
{
    check_hresult(WINRT_SHIM(IHttpCookieManager)->abi_DeleteCookie(get_abi(cookie)));
}

template <typename D> Windows::Web::Http::HttpCookieCollection impl_IHttpCookieManager<D>::GetCookies(const Windows::Foundation::Uri & uri) const
{
    Windows::Web::Http::HttpCookieCollection value { nullptr };
    check_hresult(WINRT_SHIM(IHttpCookieManager)->abi_GetCookies(get_abi(uri), put_abi(value)));
    return value;
}

template <typename D> Windows::Web::Http::HttpCookie impl_IHttpCookieFactory<D>::Create(hstring_view name, hstring_view domain, hstring_view path) const
{
    Windows::Web::Http::HttpCookie cookie { nullptr };
    check_hresult(WINRT_SHIM(IHttpCookieFactory)->abi_Create(get_abi(name), get_abi(domain), get_abi(path), put_abi(cookie)));
    return cookie;
}

template <typename D> hstring impl_IHttpCookie<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHttpCookie)->get_Name(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IHttpCookie<D>::Domain() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHttpCookie)->get_Domain(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IHttpCookie<D>::Path() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHttpCookie)->get_Path(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IHttpCookie<D>::Expires() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(IHttpCookie)->get_Expires(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpCookie<D>::Expires(const optional<Windows::Foundation::DateTime> & value) const
{
    check_hresult(WINRT_SHIM(IHttpCookie)->put_Expires(get_abi(value)));
}

template <typename D> bool impl_IHttpCookie<D>::HttpOnly() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IHttpCookie)->get_HttpOnly(&value));
    return value;
}

template <typename D> void impl_IHttpCookie<D>::HttpOnly(bool value) const
{
    check_hresult(WINRT_SHIM(IHttpCookie)->put_HttpOnly(value));
}

template <typename D> bool impl_IHttpCookie<D>::Secure() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IHttpCookie)->get_Secure(&value));
    return value;
}

template <typename D> void impl_IHttpCookie<D>::Secure(bool value) const
{
    check_hresult(WINRT_SHIM(IHttpCookie)->put_Secure(value));
}

template <typename D> hstring impl_IHttpCookie<D>::Value() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHttpCookie)->get_Value(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpCookie<D>::Value(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IHttpCookie)->put_Value(get_abi(value)));
}

template <typename D> Windows::Web::Http::HttpMethod impl_IHttpMethodStatics<D>::Delete() const
{
    Windows::Web::Http::HttpMethod value { nullptr };
    check_hresult(WINRT_SHIM(IHttpMethodStatics)->get_Delete(put_abi(value)));
    return value;
}

template <typename D> Windows::Web::Http::HttpMethod impl_IHttpMethodStatics<D>::Get() const
{
    Windows::Web::Http::HttpMethod value { nullptr };
    check_hresult(WINRT_SHIM(IHttpMethodStatics)->get_Get(put_abi(value)));
    return value;
}

template <typename D> Windows::Web::Http::HttpMethod impl_IHttpMethodStatics<D>::Head() const
{
    Windows::Web::Http::HttpMethod value { nullptr };
    check_hresult(WINRT_SHIM(IHttpMethodStatics)->get_Head(put_abi(value)));
    return value;
}

template <typename D> Windows::Web::Http::HttpMethod impl_IHttpMethodStatics<D>::Options() const
{
    Windows::Web::Http::HttpMethod value { nullptr };
    check_hresult(WINRT_SHIM(IHttpMethodStatics)->get_Options(put_abi(value)));
    return value;
}

template <typename D> Windows::Web::Http::HttpMethod impl_IHttpMethodStatics<D>::Patch() const
{
    Windows::Web::Http::HttpMethod value { nullptr };
    check_hresult(WINRT_SHIM(IHttpMethodStatics)->get_Patch(put_abi(value)));
    return value;
}

template <typename D> Windows::Web::Http::HttpMethod impl_IHttpMethodStatics<D>::Post() const
{
    Windows::Web::Http::HttpMethod value { nullptr };
    check_hresult(WINRT_SHIM(IHttpMethodStatics)->get_Post(put_abi(value)));
    return value;
}

template <typename D> Windows::Web::Http::HttpMethod impl_IHttpMethodStatics<D>::Put() const
{
    Windows::Web::Http::HttpMethod value { nullptr };
    check_hresult(WINRT_SHIM(IHttpMethodStatics)->get_Put(put_abi(value)));
    return value;
}

template <typename D> Windows::Web::Http::HttpMethod impl_IHttpMethodFactory<D>::Create(hstring_view method) const
{
    Windows::Web::Http::HttpMethod httpMethod { nullptr };
    check_hresult(WINRT_SHIM(IHttpMethodFactory)->abi_Create(get_abi(method), put_abi(httpMethod)));
    return httpMethod;
}

template <typename D> hstring impl_IHttpMethod<D>::Method() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHttpMethod)->get_Method(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Cryptography::Certificates::Certificate impl_IHttpTransportInformation<D>::ServerCertificate() const
{
    Windows::Security::Cryptography::Certificates::Certificate value { nullptr };
    check_hresult(WINRT_SHIM(IHttpTransportInformation)->get_ServerCertificate(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::Sockets::SocketSslErrorSeverity impl_IHttpTransportInformation<D>::ServerCertificateErrorSeverity() const
{
    Windows::Networking::Sockets::SocketSslErrorSeverity value {};
    check_hresult(WINRT_SHIM(IHttpTransportInformation)->get_ServerCertificateErrorSeverity(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> impl_IHttpTransportInformation<D>::ServerCertificateErrors() const
{
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> value;
    check_hresult(WINRT_SHIM(IHttpTransportInformation)->get_ServerCertificateErrors(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> impl_IHttpTransportInformation<D>::ServerIntermediateCertificates() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> value;
    check_hresult(WINRT_SHIM(IHttpTransportInformation)->get_ServerIntermediateCertificates(put_abi(value)));
    return value;
}

template <typename D> Windows::Web::Http::HttpRequestMessage impl_IHttpRequestMessageFactory<D>::Create(const Windows::Web::Http::HttpMethod & method, const Windows::Foundation::Uri & uri) const
{
    Windows::Web::Http::HttpRequestMessage httpRequestMessage { nullptr };
    check_hresult(WINRT_SHIM(IHttpRequestMessageFactory)->abi_Create(get_abi(method), get_abi(uri), put_abi(httpRequestMessage)));
    return httpRequestMessage;
}

template <typename D> Windows::Web::Http::IHttpContent impl_IHttpRequestMessage<D>::Content() const
{
    Windows::Web::Http::IHttpContent value;
    check_hresult(WINRT_SHIM(IHttpRequestMessage)->get_Content(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpRequestMessage<D>::Content(const Windows::Web::Http::IHttpContent & value) const
{
    check_hresult(WINRT_SHIM(IHttpRequestMessage)->put_Content(get_abi(value)));
}

template <typename D> Windows::Web::Http::Headers::HttpRequestHeaderCollection impl_IHttpRequestMessage<D>::Headers() const
{
    Windows::Web::Http::Headers::HttpRequestHeaderCollection value { nullptr };
    check_hresult(WINRT_SHIM(IHttpRequestMessage)->get_Headers(put_abi(value)));
    return value;
}

template <typename D> Windows::Web::Http::HttpMethod impl_IHttpRequestMessage<D>::Method() const
{
    Windows::Web::Http::HttpMethod value { nullptr };
    check_hresult(WINRT_SHIM(IHttpRequestMessage)->get_Method(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpRequestMessage<D>::Method(const Windows::Web::Http::HttpMethod & value) const
{
    check_hresult(WINRT_SHIM(IHttpRequestMessage)->put_Method(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::IInspectable> impl_IHttpRequestMessage<D>::Properties() const
{
    Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::IInspectable> value;
    check_hresult(WINRT_SHIM(IHttpRequestMessage)->get_Properties(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_IHttpRequestMessage<D>::RequestUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IHttpRequestMessage)->get_RequestUri(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpRequestMessage<D>::RequestUri(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(IHttpRequestMessage)->put_RequestUri(get_abi(value)));
}

template <typename D> Windows::Web::Http::HttpTransportInformation impl_IHttpRequestMessage<D>::TransportInformation() const
{
    Windows::Web::Http::HttpTransportInformation value { nullptr };
    check_hresult(WINRT_SHIM(IHttpRequestMessage)->get_TransportInformation(put_abi(value)));
    return value;
}

template <typename D> Windows::Web::Http::HttpResponseMessage impl_IHttpResponseMessageFactory<D>::Create(Windows::Web::Http::HttpStatusCode statusCode) const
{
    Windows::Web::Http::HttpResponseMessage httpResponseMessage { nullptr };
    check_hresult(WINRT_SHIM(IHttpResponseMessageFactory)->abi_Create(statusCode, put_abi(httpResponseMessage)));
    return httpResponseMessage;
}

template <typename D> Windows::Web::Http::IHttpContent impl_IHttpResponseMessage<D>::Content() const
{
    Windows::Web::Http::IHttpContent value;
    check_hresult(WINRT_SHIM(IHttpResponseMessage)->get_Content(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpResponseMessage<D>::Content(const Windows::Web::Http::IHttpContent & value) const
{
    check_hresult(WINRT_SHIM(IHttpResponseMessage)->put_Content(get_abi(value)));
}

template <typename D> Windows::Web::Http::Headers::HttpResponseHeaderCollection impl_IHttpResponseMessage<D>::Headers() const
{
    Windows::Web::Http::Headers::HttpResponseHeaderCollection value { nullptr };
    check_hresult(WINRT_SHIM(IHttpResponseMessage)->get_Headers(put_abi(value)));
    return value;
}

template <typename D> bool impl_IHttpResponseMessage<D>::IsSuccessStatusCode() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IHttpResponseMessage)->get_IsSuccessStatusCode(&value));
    return value;
}

template <typename D> hstring impl_IHttpResponseMessage<D>::ReasonPhrase() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHttpResponseMessage)->get_ReasonPhrase(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpResponseMessage<D>::ReasonPhrase(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IHttpResponseMessage)->put_ReasonPhrase(get_abi(value)));
}

template <typename D> Windows::Web::Http::HttpRequestMessage impl_IHttpResponseMessage<D>::RequestMessage() const
{
    Windows::Web::Http::HttpRequestMessage value { nullptr };
    check_hresult(WINRT_SHIM(IHttpResponseMessage)->get_RequestMessage(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpResponseMessage<D>::RequestMessage(const Windows::Web::Http::HttpRequestMessage & value) const
{
    check_hresult(WINRT_SHIM(IHttpResponseMessage)->put_RequestMessage(get_abi(value)));
}

template <typename D> Windows::Web::Http::HttpResponseMessageSource impl_IHttpResponseMessage<D>::Source() const
{
    Windows::Web::Http::HttpResponseMessageSource value {};
    check_hresult(WINRT_SHIM(IHttpResponseMessage)->get_Source(&value));
    return value;
}

template <typename D> void impl_IHttpResponseMessage<D>::Source(Windows::Web::Http::HttpResponseMessageSource value) const
{
    check_hresult(WINRT_SHIM(IHttpResponseMessage)->put_Source(value));
}

template <typename D> Windows::Web::Http::HttpStatusCode impl_IHttpResponseMessage<D>::StatusCode() const
{
    Windows::Web::Http::HttpStatusCode value {};
    check_hresult(WINRT_SHIM(IHttpResponseMessage)->get_StatusCode(&value));
    return value;
}

template <typename D> void impl_IHttpResponseMessage<D>::StatusCode(Windows::Web::Http::HttpStatusCode value) const
{
    check_hresult(WINRT_SHIM(IHttpResponseMessage)->put_StatusCode(value));
}

template <typename D> Windows::Web::Http::HttpVersion impl_IHttpResponseMessage<D>::Version() const
{
    Windows::Web::Http::HttpVersion value {};
    check_hresult(WINRT_SHIM(IHttpResponseMessage)->get_Version(&value));
    return value;
}

template <typename D> void impl_IHttpResponseMessage<D>::Version(Windows::Web::Http::HttpVersion value) const
{
    check_hresult(WINRT_SHIM(IHttpResponseMessage)->put_Version(value));
}

template <typename D> Windows::Web::Http::HttpResponseMessage impl_IHttpResponseMessage<D>::EnsureSuccessStatusCode() const
{
    Windows::Web::Http::HttpResponseMessage httpResponseMessage { nullptr };
    check_hresult(WINRT_SHIM(IHttpResponseMessage)->abi_EnsureSuccessStatusCode(put_abi(httpResponseMessage)));
    return httpResponseMessage;
}

template <typename D> Windows::Web::Http::HttpStringContent impl_IHttpStringContentFactory<D>::CreateFromString(hstring_view content) const
{
    Windows::Web::Http::HttpStringContent stringContent { nullptr };
    check_hresult(WINRT_SHIM(IHttpStringContentFactory)->abi_CreateFromString(get_abi(content), put_abi(stringContent)));
    return stringContent;
}

template <typename D> Windows::Web::Http::HttpStringContent impl_IHttpStringContentFactory<D>::CreateFromStringWithEncoding(hstring_view content, Windows::Storage::Streams::UnicodeEncoding encoding) const
{
    Windows::Web::Http::HttpStringContent stringContent { nullptr };
    check_hresult(WINRT_SHIM(IHttpStringContentFactory)->abi_CreateFromStringWithEncoding(get_abi(content), encoding, put_abi(stringContent)));
    return stringContent;
}

template <typename D> Windows::Web::Http::HttpStringContent impl_IHttpStringContentFactory<D>::CreateFromStringWithEncodingAndMediaType(hstring_view content, Windows::Storage::Streams::UnicodeEncoding encoding, hstring_view mediaType) const
{
    Windows::Web::Http::HttpStringContent stringContent { nullptr };
    check_hresult(WINRT_SHIM(IHttpStringContentFactory)->abi_CreateFromStringWithEncodingAndMediaType(get_abi(content), encoding, get_abi(mediaType), put_abi(stringContent)));
    return stringContent;
}

template <typename D> Windows::Web::Http::HttpBufferContent impl_IHttpBufferContentFactory<D>::CreateFromBuffer(const Windows::Storage::Streams::IBuffer & content) const
{
    Windows::Web::Http::HttpBufferContent bufferContent { nullptr };
    check_hresult(WINRT_SHIM(IHttpBufferContentFactory)->abi_CreateFromBuffer(get_abi(content), put_abi(bufferContent)));
    return bufferContent;
}

template <typename D> Windows::Web::Http::HttpBufferContent impl_IHttpBufferContentFactory<D>::CreateFromBufferWithOffset(const Windows::Storage::Streams::IBuffer & content, uint32_t offset, uint32_t count) const
{
    Windows::Web::Http::HttpBufferContent bufferContent { nullptr };
    check_hresult(WINRT_SHIM(IHttpBufferContentFactory)->abi_CreateFromBufferWithOffset(get_abi(content), offset, count, put_abi(bufferContent)));
    return bufferContent;
}

template <typename D> Windows::Web::Http::HttpStreamContent impl_IHttpStreamContentFactory<D>::CreateFromInputStream(const Windows::Storage::Streams::IInputStream & content) const
{
    Windows::Web::Http::HttpStreamContent streamContent { nullptr };
    check_hresult(WINRT_SHIM(IHttpStreamContentFactory)->abi_CreateFromInputStream(get_abi(content), put_abi(streamContent)));
    return streamContent;
}

template <typename D> Windows::Web::Http::HttpFormUrlEncodedContent impl_IHttpFormUrlEncodedContentFactory<D>::Create(iterable<Windows::Foundation::Collections::IKeyValuePair<hstring, hstring>> content) const
{
    Windows::Web::Http::HttpFormUrlEncodedContent formUrlEncodedContent { nullptr };
    check_hresult(WINRT_SHIM(IHttpFormUrlEncodedContentFactory)->abi_Create(get_abi(content), put_abi(formUrlEncodedContent)));
    return formUrlEncodedContent;
}

template <typename D> Windows::Web::Http::HttpMultipartContent impl_IHttpMultipartContentFactory<D>::CreateWithSubtype(hstring_view subtype) const
{
    Windows::Web::Http::HttpMultipartContent multipartContent { nullptr };
    check_hresult(WINRT_SHIM(IHttpMultipartContentFactory)->abi_CreateWithSubtype(get_abi(subtype), put_abi(multipartContent)));
    return multipartContent;
}

template <typename D> Windows::Web::Http::HttpMultipartContent impl_IHttpMultipartContentFactory<D>::CreateWithSubtypeAndBoundary(hstring_view subtype, hstring_view boundary) const
{
    Windows::Web::Http::HttpMultipartContent multipartContent { nullptr };
    check_hresult(WINRT_SHIM(IHttpMultipartContentFactory)->abi_CreateWithSubtypeAndBoundary(get_abi(subtype), get_abi(boundary), put_abi(multipartContent)));
    return multipartContent;
}

template <typename D> void impl_IHttpMultipartContent<D>::Add(const Windows::Web::Http::IHttpContent & content) const
{
    check_hresult(WINRT_SHIM(IHttpMultipartContent)->abi_Add(get_abi(content)));
}

template <typename D> Windows::Web::Http::HttpMultipartFormDataContent impl_IHttpMultipartFormDataContentFactory<D>::CreateWithBoundary(hstring_view boundary) const
{
    Windows::Web::Http::HttpMultipartFormDataContent multipartFormDataContent { nullptr };
    check_hresult(WINRT_SHIM(IHttpMultipartFormDataContentFactory)->abi_CreateWithBoundary(get_abi(boundary), put_abi(multipartFormDataContent)));
    return multipartFormDataContent;
}

template <typename D> void impl_IHttpMultipartFormDataContent<D>::Add(const Windows::Web::Http::IHttpContent & content) const
{
    check_hresult(WINRT_SHIM(IHttpMultipartFormDataContent)->abi_Add(get_abi(content)));
}

template <typename D> void impl_IHttpMultipartFormDataContent<D>::Add(const Windows::Web::Http::IHttpContent & content, hstring_view name) const
{
    check_hresult(WINRT_SHIM(IHttpMultipartFormDataContent)->abi_AddWithName(get_abi(content), get_abi(name)));
}

template <typename D> void impl_IHttpMultipartFormDataContent<D>::Add(const Windows::Web::Http::IHttpContent & content, hstring_view name, hstring_view fileName) const
{
    check_hresult(WINRT_SHIM(IHttpMultipartFormDataContent)->abi_AddWithNameAndFileName(get_abi(content), get_abi(name), get_abi(fileName)));
}

inline HttpBufferContent::HttpBufferContent(const Windows::Storage::Streams::IBuffer & content) :
    HttpBufferContent(get_activation_factory<HttpBufferContent, IHttpBufferContentFactory>().CreateFromBuffer(content))
{}

inline HttpBufferContent::HttpBufferContent(const Windows::Storage::Streams::IBuffer & content, uint32_t offset, uint32_t count) :
    HttpBufferContent(get_activation_factory<HttpBufferContent, IHttpBufferContentFactory>().CreateFromBufferWithOffset(content, offset, count))
{}

inline HttpClient::HttpClient() :
    HttpClient(activate_instance<HttpClient>())
{}

inline HttpClient::HttpClient(const Windows::Web::Http::Filters::IHttpFilter & filter) :
    HttpClient(get_activation_factory<HttpClient, IHttpClientFactory>().Create(filter))
{}

inline HttpCookie::HttpCookie(hstring_view name, hstring_view domain, hstring_view path) :
    HttpCookie(get_activation_factory<HttpCookie, IHttpCookieFactory>().Create(name, domain, path))
{}

inline HttpFormUrlEncodedContent::HttpFormUrlEncodedContent(iterable<Windows::Foundation::Collections::IKeyValuePair<hstring, hstring>> content) :
    HttpFormUrlEncodedContent(get_activation_factory<HttpFormUrlEncodedContent, IHttpFormUrlEncodedContentFactory>().Create(content))
{}

inline HttpMethod::HttpMethod(hstring_view method) :
    HttpMethod(get_activation_factory<HttpMethod, IHttpMethodFactory>().Create(method))
{}

inline Windows::Web::Http::HttpMethod HttpMethod::Delete()
{
    return get_activation_factory<HttpMethod, IHttpMethodStatics>().Delete();
}

inline Windows::Web::Http::HttpMethod HttpMethod::Get()
{
    return get_activation_factory<HttpMethod, IHttpMethodStatics>().Get();
}

inline Windows::Web::Http::HttpMethod HttpMethod::Head()
{
    return get_activation_factory<HttpMethod, IHttpMethodStatics>().Head();
}

inline Windows::Web::Http::HttpMethod HttpMethod::Options()
{
    return get_activation_factory<HttpMethod, IHttpMethodStatics>().Options();
}

inline Windows::Web::Http::HttpMethod HttpMethod::Patch()
{
    return get_activation_factory<HttpMethod, IHttpMethodStatics>().Patch();
}

inline Windows::Web::Http::HttpMethod HttpMethod::Post()
{
    return get_activation_factory<HttpMethod, IHttpMethodStatics>().Post();
}

inline Windows::Web::Http::HttpMethod HttpMethod::Put()
{
    return get_activation_factory<HttpMethod, IHttpMethodStatics>().Put();
}

inline HttpMultipartContent::HttpMultipartContent() :
    HttpMultipartContent(activate_instance<HttpMultipartContent>())
{}

inline HttpMultipartContent::HttpMultipartContent(hstring_view subtype) :
    HttpMultipartContent(get_activation_factory<HttpMultipartContent, IHttpMultipartContentFactory>().CreateWithSubtype(subtype))
{}

inline HttpMultipartContent::HttpMultipartContent(hstring_view subtype, hstring_view boundary) :
    HttpMultipartContent(get_activation_factory<HttpMultipartContent, IHttpMultipartContentFactory>().CreateWithSubtypeAndBoundary(subtype, boundary))
{}

inline HttpMultipartFormDataContent::HttpMultipartFormDataContent() :
    HttpMultipartFormDataContent(activate_instance<HttpMultipartFormDataContent>())
{}

inline HttpMultipartFormDataContent::HttpMultipartFormDataContent(hstring_view boundary) :
    HttpMultipartFormDataContent(get_activation_factory<HttpMultipartFormDataContent, IHttpMultipartFormDataContentFactory>().CreateWithBoundary(boundary))
{}

inline HttpRequestMessage::HttpRequestMessage() :
    HttpRequestMessage(activate_instance<HttpRequestMessage>())
{}

inline HttpRequestMessage::HttpRequestMessage(const Windows::Web::Http::HttpMethod & method, const Windows::Foundation::Uri & uri) :
    HttpRequestMessage(get_activation_factory<HttpRequestMessage, IHttpRequestMessageFactory>().Create(method, uri))
{}

inline HttpResponseMessage::HttpResponseMessage() :
    HttpResponseMessage(activate_instance<HttpResponseMessage>())
{}

inline HttpResponseMessage::HttpResponseMessage(Windows::Web::Http::HttpStatusCode statusCode) :
    HttpResponseMessage(get_activation_factory<HttpResponseMessage, IHttpResponseMessageFactory>().Create(statusCode))
{}

inline HttpStreamContent::HttpStreamContent(const Windows::Storage::Streams::IInputStream & content) :
    HttpStreamContent(get_activation_factory<HttpStreamContent, IHttpStreamContentFactory>().CreateFromInputStream(content))
{}

inline HttpStringContent::HttpStringContent(hstring_view content) :
    HttpStringContent(get_activation_factory<HttpStringContent, IHttpStringContentFactory>().CreateFromString(content))
{}

inline HttpStringContent::HttpStringContent(hstring_view content, Windows::Storage::Streams::UnicodeEncoding encoding) :
    HttpStringContent(get_activation_factory<HttpStringContent, IHttpStringContentFactory>().CreateFromStringWithEncoding(content, encoding))
{}

inline HttpStringContent::HttpStringContent(hstring_view content, Windows::Storage::Streams::UnicodeEncoding encoding, hstring_view mediaType) :
    HttpStringContent(get_activation_factory<HttpStringContent, IHttpStringContentFactory>().CreateFromStringWithEncodingAndMediaType(content, encoding, mediaType))
{}

}

}
#pragma warning(pop)
