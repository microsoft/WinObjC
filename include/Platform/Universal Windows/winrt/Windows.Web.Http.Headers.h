// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Networking.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Web.Http.Headers.3.h"
#include "Windows.Web.Http.h"
#include "Windows.Foundation.h"
#include "Windows.Foundation.Collections.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpCacheDirectiveHeaderValueCollection> : produce_base<D, Windows::Web::Http::Headers::IHttpCacheDirectiveHeaderValueCollection>
{
    HRESULT __stdcall get_MaxAge(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxAge());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxAge(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxAge(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::TimeSpan> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxStale(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxStale());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxStale(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxStale(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::TimeSpan> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinFresh(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinFresh());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MinFresh(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MinFresh(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::TimeSpan> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SharedMaxAge(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SharedMaxAge());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SharedMaxAge(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SharedMaxAge(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::TimeSpan> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ParseAdd(impl::abi_arg_in<hstring> input) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ParseAdd(*reinterpret_cast<const hstring *>(&input));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryParseAdd(impl::abi_arg_in<hstring> input, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryParseAdd(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpChallengeHeaderValue> : produce_base<D, Windows::Web::Http::Headers::IHttpChallengeHeaderValue>
{
    HRESULT __stdcall get_Parameters(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Web::Http::Headers::HttpNameValueHeaderValue>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Parameters());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Scheme(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Scheme());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Token(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Token());
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
struct produce<D, Windows::Web::Http::Headers::IHttpChallengeHeaderValueCollection> : produce_base<D, Windows::Web::Http::Headers::IHttpChallengeHeaderValueCollection>
{
    HRESULT __stdcall abi_ParseAdd(impl::abi_arg_in<hstring> input) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ParseAdd(*reinterpret_cast<const hstring *>(&input));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryParseAdd(impl::abi_arg_in<hstring> input, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryParseAdd(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpChallengeHeaderValueFactory> : produce_base<D, Windows::Web::Http::Headers::IHttpChallengeHeaderValueFactory>
{
    HRESULT __stdcall abi_CreateFromScheme(impl::abi_arg_in<hstring> scheme, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpChallengeHeaderValue> challengeHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *challengeHeaderValue = detach_abi(this->shim().CreateFromScheme(*reinterpret_cast<const hstring *>(&scheme)));
            return S_OK;
        }
        catch (...)
        {
            *challengeHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromSchemeWithToken(impl::abi_arg_in<hstring> scheme, impl::abi_arg_in<hstring> token, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpChallengeHeaderValue> challengeHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *challengeHeaderValue = detach_abi(this->shim().CreateFromSchemeWithToken(*reinterpret_cast<const hstring *>(&scheme), *reinterpret_cast<const hstring *>(&token)));
            return S_OK;
        }
        catch (...)
        {
            *challengeHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpChallengeHeaderValueStatics> : produce_base<D, Windows::Web::Http::Headers::IHttpChallengeHeaderValueStatics>
{
    HRESULT __stdcall abi_Parse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpChallengeHeaderValue> challengeHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *challengeHeaderValue = detach_abi(this->shim().Parse(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            *challengeHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryParse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpChallengeHeaderValue> challengeHeaderValue, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryParse(*reinterpret_cast<const hstring *>(&input), *challengeHeaderValue));
            return S_OK;
        }
        catch (...)
        {
            *challengeHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValue> : produce_base<D, Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValue>
{
    HRESULT __stdcall get_Token(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Token());
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
struct produce<D, Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValueCollection> : produce_base<D, Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValueCollection>
{
    HRESULT __stdcall abi_ParseAdd(impl::abi_arg_in<hstring> input) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ParseAdd(*reinterpret_cast<const hstring *>(&input));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryParseAdd(impl::abi_arg_in<hstring> input, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryParseAdd(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValueFactory> : produce_base<D, Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValueFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> token, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValue> connectionOptionHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *connectionOptionHeaderValue = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&token)));
            return S_OK;
        }
        catch (...)
        {
            *connectionOptionHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValueStatics> : produce_base<D, Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValueStatics>
{
    HRESULT __stdcall abi_Parse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValue> connectionOptionHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *connectionOptionHeaderValue = detach_abi(this->shim().Parse(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            *connectionOptionHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryParse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValue> connectionOptionHeaderValue, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryParse(*reinterpret_cast<const hstring *>(&input), *connectionOptionHeaderValue));
            return S_OK;
        }
        catch (...)
        {
            *connectionOptionHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpContentCodingHeaderValue> : produce_base<D, Windows::Web::Http::Headers::IHttpContentCodingHeaderValue>
{
    HRESULT __stdcall get_ContentCoding(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentCoding());
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
struct produce<D, Windows::Web::Http::Headers::IHttpContentCodingHeaderValueCollection> : produce_base<D, Windows::Web::Http::Headers::IHttpContentCodingHeaderValueCollection>
{
    HRESULT __stdcall abi_ParseAdd(impl::abi_arg_in<hstring> input) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ParseAdd(*reinterpret_cast<const hstring *>(&input));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryParseAdd(impl::abi_arg_in<hstring> input, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryParseAdd(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpContentCodingHeaderValueFactory> : produce_base<D, Windows::Web::Http::Headers::IHttpContentCodingHeaderValueFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> contentCoding, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpContentCodingHeaderValue> contentCodingHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *contentCodingHeaderValue = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&contentCoding)));
            return S_OK;
        }
        catch (...)
        {
            *contentCodingHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpContentCodingHeaderValueStatics> : produce_base<D, Windows::Web::Http::Headers::IHttpContentCodingHeaderValueStatics>
{
    HRESULT __stdcall abi_Parse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpContentCodingHeaderValue> contentCodingHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *contentCodingHeaderValue = detach_abi(this->shim().Parse(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            *contentCodingHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryParse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpContentCodingHeaderValue> contentCodingHeaderValue, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryParse(*reinterpret_cast<const hstring *>(&input), *contentCodingHeaderValue));
            return S_OK;
        }
        catch (...)
        {
            *contentCodingHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValue> : produce_base<D, Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValue>
{
    HRESULT __stdcall get_ContentCoding(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentCoding());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Quality(impl::abi_arg_out<Windows::Foundation::IReference<double>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Quality());
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
struct produce<D, Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValueCollection> : produce_base<D, Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValueCollection>
{
    HRESULT __stdcall abi_ParseAdd(impl::abi_arg_in<hstring> input) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ParseAdd(*reinterpret_cast<const hstring *>(&input));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryParseAdd(impl::abi_arg_in<hstring> input, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryParseAdd(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValueFactory> : produce_base<D, Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValueFactory>
{
    HRESULT __stdcall abi_CreateFromValue(impl::abi_arg_in<hstring> contentCoding, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValue> contentCodingWithQualityHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *contentCodingWithQualityHeaderValue = detach_abi(this->shim().CreateFromValue(*reinterpret_cast<const hstring *>(&contentCoding)));
            return S_OK;
        }
        catch (...)
        {
            *contentCodingWithQualityHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromValueWithQuality(impl::abi_arg_in<hstring> contentCoding, double quality, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValue> contentCodingWithQualityHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *contentCodingWithQualityHeaderValue = detach_abi(this->shim().CreateFromValueWithQuality(*reinterpret_cast<const hstring *>(&contentCoding), quality));
            return S_OK;
        }
        catch (...)
        {
            *contentCodingWithQualityHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValueStatics> : produce_base<D, Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValueStatics>
{
    HRESULT __stdcall abi_Parse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValue> contentCodingWithQualityHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *contentCodingWithQualityHeaderValue = detach_abi(this->shim().Parse(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            *contentCodingWithQualityHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryParse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValue> contentCodingWithQualityHeaderValue, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryParse(*reinterpret_cast<const hstring *>(&input), *contentCodingWithQualityHeaderValue));
            return S_OK;
        }
        catch (...)
        {
            *contentCodingWithQualityHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpContentDispositionHeaderValue> : produce_base<D, Windows::Web::Http::Headers::IHttpContentDispositionHeaderValue>
{
    HRESULT __stdcall get_DispositionType(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DispositionType());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DispositionType(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DispositionType(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FileName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FileName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FileName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FileName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FileNameStar(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FileNameStar());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FileNameStar(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FileNameStar(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall put_Name(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Name(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Parameters(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Web::Http::Headers::HttpNameValueHeaderValue>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Parameters());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Size(impl::abi_arg_out<Windows::Foundation::IReference<uint64_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Size());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Size(impl::abi_arg_in<Windows::Foundation::IReference<uint64_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Size(*reinterpret_cast<const Windows::Foundation::IReference<uint64_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpContentDispositionHeaderValueFactory> : produce_base<D, Windows::Web::Http::Headers::IHttpContentDispositionHeaderValueFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> dispositionType, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpContentDispositionHeaderValue> contentDispositionHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *contentDispositionHeaderValue = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&dispositionType)));
            return S_OK;
        }
        catch (...)
        {
            *contentDispositionHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpContentDispositionHeaderValueStatics> : produce_base<D, Windows::Web::Http::Headers::IHttpContentDispositionHeaderValueStatics>
{
    HRESULT __stdcall abi_Parse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpContentDispositionHeaderValue> contentDispositionHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *contentDispositionHeaderValue = detach_abi(this->shim().Parse(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            *contentDispositionHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryParse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpContentDispositionHeaderValue> contentDispositionHeaderValue, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryParse(*reinterpret_cast<const hstring *>(&input), *contentDispositionHeaderValue));
            return S_OK;
        }
        catch (...)
        {
            *contentDispositionHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpContentHeaderCollection> : produce_base<D, Windows::Web::Http::Headers::IHttpContentHeaderCollection>
{
    HRESULT __stdcall get_ContentDisposition(impl::abi_arg_out<Windows::Web::Http::Headers::IHttpContentDispositionHeaderValue> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentDisposition());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ContentDisposition(impl::abi_arg_in<Windows::Web::Http::Headers::IHttpContentDispositionHeaderValue> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContentDisposition(*reinterpret_cast<const Windows::Web::Http::Headers::HttpContentDispositionHeaderValue *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContentEncoding(impl::abi_arg_out<Windows::Web::Http::Headers::IHttpContentCodingHeaderValueCollection> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentEncoding());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContentLanguage(impl::abi_arg_out<Windows::Web::Http::Headers::IHttpLanguageHeaderValueCollection> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentLanguage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContentLength(impl::abi_arg_out<Windows::Foundation::IReference<uint64_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentLength());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ContentLength(impl::abi_arg_in<Windows::Foundation::IReference<uint64_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContentLength(*reinterpret_cast<const Windows::Foundation::IReference<uint64_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContentLocation(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentLocation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ContentLocation(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContentLocation(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContentMD5(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentMD5());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ContentMD5(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContentMD5(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContentRange(impl::abi_arg_out<Windows::Web::Http::Headers::IHttpContentRangeHeaderValue> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentRange());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ContentRange(impl::abi_arg_in<Windows::Web::Http::Headers::IHttpContentRangeHeaderValue> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContentRange(*reinterpret_cast<const Windows::Web::Http::Headers::HttpContentRangeHeaderValue *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContentType(impl::abi_arg_out<Windows::Web::Http::Headers::IHttpMediaTypeHeaderValue> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentType());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ContentType(impl::abi_arg_in<Windows::Web::Http::Headers::IHttpMediaTypeHeaderValue> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContentType(*reinterpret_cast<const Windows::Web::Http::Headers::HttpMediaTypeHeaderValue *>(&value));
            return S_OK;
        }
        catch (...)
        {
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

    HRESULT __stdcall get_LastModified(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LastModified());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LastModified(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LastModified(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::DateTime> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Append(impl::abi_arg_in<hstring> name, impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Append(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryAppendWithoutValidation(impl::abi_arg_in<hstring> name, impl::abi_arg_in<hstring> value, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryAppendWithoutValidation(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const hstring *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpContentRangeHeaderValue> : produce_base<D, Windows::Web::Http::Headers::IHttpContentRangeHeaderValue>
{
    HRESULT __stdcall get_FirstBytePosition(impl::abi_arg_out<Windows::Foundation::IReference<uint64_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FirstBytePosition());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LastBytePosition(impl::abi_arg_out<Windows::Foundation::IReference<uint64_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LastBytePosition());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Length(impl::abi_arg_out<Windows::Foundation::IReference<uint64_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Length());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Unit(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Unit());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Unit(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Unit(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpContentRangeHeaderValueFactory> : produce_base<D, Windows::Web::Http::Headers::IHttpContentRangeHeaderValueFactory>
{
    HRESULT __stdcall abi_CreateFromLength(uint64_t length, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpContentRangeHeaderValue> contentRangeHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *contentRangeHeaderValue = detach_abi(this->shim().CreateFromLength(length));
            return S_OK;
        }
        catch (...)
        {
            *contentRangeHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromRange(uint64_t from, uint64_t to, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpContentRangeHeaderValue> contentRangeHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *contentRangeHeaderValue = detach_abi(this->shim().CreateFromRange(from, to));
            return S_OK;
        }
        catch (...)
        {
            *contentRangeHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromRangeWithLength(uint64_t from, uint64_t to, uint64_t length, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpContentRangeHeaderValue> contentRangeHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *contentRangeHeaderValue = detach_abi(this->shim().CreateFromRangeWithLength(from, to, length));
            return S_OK;
        }
        catch (...)
        {
            *contentRangeHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpContentRangeHeaderValueStatics> : produce_base<D, Windows::Web::Http::Headers::IHttpContentRangeHeaderValueStatics>
{
    HRESULT __stdcall abi_Parse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpContentRangeHeaderValue> contentRangeHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *contentRangeHeaderValue = detach_abi(this->shim().Parse(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            *contentRangeHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryParse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpContentRangeHeaderValue> contentRangeHeaderValue, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryParse(*reinterpret_cast<const hstring *>(&input), *contentRangeHeaderValue));
            return S_OK;
        }
        catch (...)
        {
            *contentRangeHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpCookiePairHeaderValue> : produce_base<D, Windows::Web::Http::Headers::IHttpCookiePairHeaderValue>
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
struct produce<D, Windows::Web::Http::Headers::IHttpCookiePairHeaderValueCollection> : produce_base<D, Windows::Web::Http::Headers::IHttpCookiePairHeaderValueCollection>
{
    HRESULT __stdcall abi_ParseAdd(impl::abi_arg_in<hstring> input) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ParseAdd(*reinterpret_cast<const hstring *>(&input));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryParseAdd(impl::abi_arg_in<hstring> input, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryParseAdd(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpCookiePairHeaderValueFactory> : produce_base<D, Windows::Web::Http::Headers::IHttpCookiePairHeaderValueFactory>
{
    HRESULT __stdcall abi_CreateFromName(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpCookiePairHeaderValue> cookiePairHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookiePairHeaderValue = detach_abi(this->shim().CreateFromName(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *cookiePairHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromNameWithValue(impl::abi_arg_in<hstring> name, impl::abi_arg_in<hstring> value, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpCookiePairHeaderValue> cookiePairHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookiePairHeaderValue = detach_abi(this->shim().CreateFromNameWithValue(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const hstring *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            *cookiePairHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpCookiePairHeaderValueStatics> : produce_base<D, Windows::Web::Http::Headers::IHttpCookiePairHeaderValueStatics>
{
    HRESULT __stdcall abi_Parse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpCookiePairHeaderValue> cookiePairHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookiePairHeaderValue = detach_abi(this->shim().Parse(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            *cookiePairHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryParse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpCookiePairHeaderValue> cookiePairHeaderValue, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryParse(*reinterpret_cast<const hstring *>(&input), *cookiePairHeaderValue));
            return S_OK;
        }
        catch (...)
        {
            *cookiePairHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpCredentialsHeaderValue> : produce_base<D, Windows::Web::Http::Headers::IHttpCredentialsHeaderValue>
{
    HRESULT __stdcall get_Parameters(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Web::Http::Headers::HttpNameValueHeaderValue>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Parameters());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Scheme(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Scheme());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Token(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Token());
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
struct produce<D, Windows::Web::Http::Headers::IHttpCredentialsHeaderValueFactory> : produce_base<D, Windows::Web::Http::Headers::IHttpCredentialsHeaderValueFactory>
{
    HRESULT __stdcall abi_CreateFromScheme(impl::abi_arg_in<hstring> scheme, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpCredentialsHeaderValue> credentialsHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *credentialsHeaderValue = detach_abi(this->shim().CreateFromScheme(*reinterpret_cast<const hstring *>(&scheme)));
            return S_OK;
        }
        catch (...)
        {
            *credentialsHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromSchemeWithToken(impl::abi_arg_in<hstring> scheme, impl::abi_arg_in<hstring> token, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpCredentialsHeaderValue> credentialsHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *credentialsHeaderValue = detach_abi(this->shim().CreateFromSchemeWithToken(*reinterpret_cast<const hstring *>(&scheme), *reinterpret_cast<const hstring *>(&token)));
            return S_OK;
        }
        catch (...)
        {
            *credentialsHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpCredentialsHeaderValueStatics> : produce_base<D, Windows::Web::Http::Headers::IHttpCredentialsHeaderValueStatics>
{
    HRESULT __stdcall abi_Parse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpCredentialsHeaderValue> credentialsHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *credentialsHeaderValue = detach_abi(this->shim().Parse(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            *credentialsHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryParse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpCredentialsHeaderValue> credentialsHeaderValue, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryParse(*reinterpret_cast<const hstring *>(&input), *credentialsHeaderValue));
            return S_OK;
        }
        catch (...)
        {
            *credentialsHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpDateOrDeltaHeaderValue> : produce_base<D, Windows::Web::Http::Headers::IHttpDateOrDeltaHeaderValue>
{
    HRESULT __stdcall get_Date(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Date());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Delta(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Delta());
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
struct produce<D, Windows::Web::Http::Headers::IHttpDateOrDeltaHeaderValueStatics> : produce_base<D, Windows::Web::Http::Headers::IHttpDateOrDeltaHeaderValueStatics>
{
    HRESULT __stdcall abi_Parse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpDateOrDeltaHeaderValue> dateOrDeltaHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *dateOrDeltaHeaderValue = detach_abi(this->shim().Parse(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            *dateOrDeltaHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryParse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpDateOrDeltaHeaderValue> dateOrDeltaHeaderValue, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryParse(*reinterpret_cast<const hstring *>(&input), *dateOrDeltaHeaderValue));
            return S_OK;
        }
        catch (...)
        {
            *dateOrDeltaHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpExpectationHeaderValue> : produce_base<D, Windows::Web::Http::Headers::IHttpExpectationHeaderValue>
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

    HRESULT __stdcall get_Parameters(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Web::Http::Headers::HttpNameValueHeaderValue>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Parameters());
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
struct produce<D, Windows::Web::Http::Headers::IHttpExpectationHeaderValueCollection> : produce_base<D, Windows::Web::Http::Headers::IHttpExpectationHeaderValueCollection>
{
    HRESULT __stdcall abi_ParseAdd(impl::abi_arg_in<hstring> input) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ParseAdd(*reinterpret_cast<const hstring *>(&input));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryParseAdd(impl::abi_arg_in<hstring> input, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryParseAdd(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpExpectationHeaderValueFactory> : produce_base<D, Windows::Web::Http::Headers::IHttpExpectationHeaderValueFactory>
{
    HRESULT __stdcall abi_CreateFromName(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpExpectationHeaderValue> expectationHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *expectationHeaderValue = detach_abi(this->shim().CreateFromName(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *expectationHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromNameWithValue(impl::abi_arg_in<hstring> name, impl::abi_arg_in<hstring> value, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpExpectationHeaderValue> expectationHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *expectationHeaderValue = detach_abi(this->shim().CreateFromNameWithValue(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const hstring *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            *expectationHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpExpectationHeaderValueStatics> : produce_base<D, Windows::Web::Http::Headers::IHttpExpectationHeaderValueStatics>
{
    HRESULT __stdcall abi_Parse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpExpectationHeaderValue> expectationHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *expectationHeaderValue = detach_abi(this->shim().Parse(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            *expectationHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryParse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpExpectationHeaderValue> expectationHeaderValue, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryParse(*reinterpret_cast<const hstring *>(&input), *expectationHeaderValue));
            return S_OK;
        }
        catch (...)
        {
            *expectationHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpLanguageHeaderValueCollection> : produce_base<D, Windows::Web::Http::Headers::IHttpLanguageHeaderValueCollection>
{
    HRESULT __stdcall abi_ParseAdd(impl::abi_arg_in<hstring> input) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ParseAdd(*reinterpret_cast<const hstring *>(&input));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryParseAdd(impl::abi_arg_in<hstring> input, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryParseAdd(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValue> : produce_base<D, Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValue>
{
    HRESULT __stdcall get_LanguageRange(impl::abi_arg_out<hstring> languageRange) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *languageRange = detach_abi(this->shim().LanguageRange());
            return S_OK;
        }
        catch (...)
        {
            *languageRange = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Quality(impl::abi_arg_out<Windows::Foundation::IReference<double>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Quality());
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
struct produce<D, Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValueCollection> : produce_base<D, Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValueCollection>
{
    HRESULT __stdcall abi_ParseAdd(impl::abi_arg_in<hstring> input) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ParseAdd(*reinterpret_cast<const hstring *>(&input));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryParseAdd(impl::abi_arg_in<hstring> input, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryParseAdd(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValueFactory> : produce_base<D, Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValueFactory>
{
    HRESULT __stdcall abi_CreateFromLanguageRange(impl::abi_arg_in<hstring> languageRange, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValue> languageRangeWithQualityHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *languageRangeWithQualityHeaderValue = detach_abi(this->shim().CreateFromLanguageRange(*reinterpret_cast<const hstring *>(&languageRange)));
            return S_OK;
        }
        catch (...)
        {
            *languageRangeWithQualityHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromLanguageRangeWithQuality(impl::abi_arg_in<hstring> languageRange, double quality, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValue> languageRangeWithQualityHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *languageRangeWithQualityHeaderValue = detach_abi(this->shim().CreateFromLanguageRangeWithQuality(*reinterpret_cast<const hstring *>(&languageRange), quality));
            return S_OK;
        }
        catch (...)
        {
            *languageRangeWithQualityHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValueStatics> : produce_base<D, Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValueStatics>
{
    HRESULT __stdcall abi_Parse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValue> languageRangeWithQualityHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *languageRangeWithQualityHeaderValue = detach_abi(this->shim().Parse(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            *languageRangeWithQualityHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryParse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValue> languageRangeWithQualityHeaderValue, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryParse(*reinterpret_cast<const hstring *>(&input), *languageRangeWithQualityHeaderValue));
            return S_OK;
        }
        catch (...)
        {
            *languageRangeWithQualityHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpMediaTypeHeaderValue> : produce_base<D, Windows::Web::Http::Headers::IHttpMediaTypeHeaderValue>
{
    HRESULT __stdcall get_CharSet(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CharSet());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CharSet(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CharSet(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MediaType(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MediaType());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MediaType(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MediaType(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Parameters(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Web::Http::Headers::HttpNameValueHeaderValue>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Parameters());
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
struct produce<D, Windows::Web::Http::Headers::IHttpMediaTypeHeaderValueFactory> : produce_base<D, Windows::Web::Http::Headers::IHttpMediaTypeHeaderValueFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> mediaType, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpMediaTypeHeaderValue> mediaTypeHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *mediaTypeHeaderValue = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&mediaType)));
            return S_OK;
        }
        catch (...)
        {
            *mediaTypeHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpMediaTypeHeaderValueStatics> : produce_base<D, Windows::Web::Http::Headers::IHttpMediaTypeHeaderValueStatics>
{
    HRESULT __stdcall abi_Parse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpMediaTypeHeaderValue> mediaTypeHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *mediaTypeHeaderValue = detach_abi(this->shim().Parse(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            *mediaTypeHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryParse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpMediaTypeHeaderValue> mediaTypeHeaderValue, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryParse(*reinterpret_cast<const hstring *>(&input), *mediaTypeHeaderValue));
            return S_OK;
        }
        catch (...)
        {
            *mediaTypeHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValue> : produce_base<D, Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValue>
{
    HRESULT __stdcall get_CharSet(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CharSet());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CharSet(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CharSet(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MediaType(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MediaType());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MediaType(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MediaType(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Parameters(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Web::Http::Headers::HttpNameValueHeaderValue>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Parameters());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Quality(impl::abi_arg_out<Windows::Foundation::IReference<double>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Quality());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Quality(impl::abi_arg_in<Windows::Foundation::IReference<double>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Quality(*reinterpret_cast<const Windows::Foundation::IReference<double> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValueCollection> : produce_base<D, Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValueCollection>
{
    HRESULT __stdcall abi_ParseAdd(impl::abi_arg_in<hstring> input) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ParseAdd(*reinterpret_cast<const hstring *>(&input));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryParseAdd(impl::abi_arg_in<hstring> input, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryParseAdd(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValueFactory> : produce_base<D, Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValueFactory>
{
    HRESULT __stdcall abi_CreateFromMediaType(impl::abi_arg_in<hstring> mediaType, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValue> mediaTypeWithQualityHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *mediaTypeWithQualityHeaderValue = detach_abi(this->shim().CreateFromMediaType(*reinterpret_cast<const hstring *>(&mediaType)));
            return S_OK;
        }
        catch (...)
        {
            *mediaTypeWithQualityHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromMediaTypeWithQuality(impl::abi_arg_in<hstring> mediaType, double quality, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValue> mediaTypeWithQualityHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *mediaTypeWithQualityHeaderValue = detach_abi(this->shim().CreateFromMediaTypeWithQuality(*reinterpret_cast<const hstring *>(&mediaType), quality));
            return S_OK;
        }
        catch (...)
        {
            *mediaTypeWithQualityHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValueStatics> : produce_base<D, Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValueStatics>
{
    HRESULT __stdcall abi_Parse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValue> mediaTypeWithQualityHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *mediaTypeWithQualityHeaderValue = detach_abi(this->shim().Parse(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            *mediaTypeWithQualityHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryParse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValue> mediaTypeWithQualityHeaderValue, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryParse(*reinterpret_cast<const hstring *>(&input), *mediaTypeWithQualityHeaderValue));
            return S_OK;
        }
        catch (...)
        {
            *mediaTypeWithQualityHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpMethodHeaderValueCollection> : produce_base<D, Windows::Web::Http::Headers::IHttpMethodHeaderValueCollection>
{
    HRESULT __stdcall abi_ParseAdd(impl::abi_arg_in<hstring> input) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ParseAdd(*reinterpret_cast<const hstring *>(&input));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryParseAdd(impl::abi_arg_in<hstring> input, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryParseAdd(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpNameValueHeaderValue> : produce_base<D, Windows::Web::Http::Headers::IHttpNameValueHeaderValue>
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
struct produce<D, Windows::Web::Http::Headers::IHttpNameValueHeaderValueFactory> : produce_base<D, Windows::Web::Http::Headers::IHttpNameValueHeaderValueFactory>
{
    HRESULT __stdcall abi_CreateFromName(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpNameValueHeaderValue> nameValueHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *nameValueHeaderValue = detach_abi(this->shim().CreateFromName(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *nameValueHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromNameWithValue(impl::abi_arg_in<hstring> name, impl::abi_arg_in<hstring> value, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpNameValueHeaderValue> nameValueHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *nameValueHeaderValue = detach_abi(this->shim().CreateFromNameWithValue(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const hstring *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            *nameValueHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpNameValueHeaderValueStatics> : produce_base<D, Windows::Web::Http::Headers::IHttpNameValueHeaderValueStatics>
{
    HRESULT __stdcall abi_Parse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpNameValueHeaderValue> nameValueHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *nameValueHeaderValue = detach_abi(this->shim().Parse(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            *nameValueHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryParse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpNameValueHeaderValue> nameValueHeaderValue, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryParse(*reinterpret_cast<const hstring *>(&input), *nameValueHeaderValue));
            return S_OK;
        }
        catch (...)
        {
            *nameValueHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpProductHeaderValue> : produce_base<D, Windows::Web::Http::Headers::IHttpProductHeaderValue>
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

    HRESULT __stdcall get_Version(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Version());
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
struct produce<D, Windows::Web::Http::Headers::IHttpProductHeaderValueFactory> : produce_base<D, Windows::Web::Http::Headers::IHttpProductHeaderValueFactory>
{
    HRESULT __stdcall abi_CreateFromName(impl::abi_arg_in<hstring> productName, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpProductHeaderValue> productHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *productHeaderValue = detach_abi(this->shim().CreateFromName(*reinterpret_cast<const hstring *>(&productName)));
            return S_OK;
        }
        catch (...)
        {
            *productHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromNameWithVersion(impl::abi_arg_in<hstring> productName, impl::abi_arg_in<hstring> productVersion, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpProductHeaderValue> productHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *productHeaderValue = detach_abi(this->shim().CreateFromNameWithVersion(*reinterpret_cast<const hstring *>(&productName), *reinterpret_cast<const hstring *>(&productVersion)));
            return S_OK;
        }
        catch (...)
        {
            *productHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpProductHeaderValueStatics> : produce_base<D, Windows::Web::Http::Headers::IHttpProductHeaderValueStatics>
{
    HRESULT __stdcall abi_Parse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpProductHeaderValue> productHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *productHeaderValue = detach_abi(this->shim().Parse(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            *productHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryParse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpProductHeaderValue> productHeaderValue, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryParse(*reinterpret_cast<const hstring *>(&input), *productHeaderValue));
            return S_OK;
        }
        catch (...)
        {
            *productHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpProductInfoHeaderValue> : produce_base<D, Windows::Web::Http::Headers::IHttpProductInfoHeaderValue>
{
    HRESULT __stdcall get_Product(impl::abi_arg_out<Windows::Web::Http::Headers::IHttpProductHeaderValue> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Product());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Comment(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Comment());
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
struct produce<D, Windows::Web::Http::Headers::IHttpProductInfoHeaderValueCollection> : produce_base<D, Windows::Web::Http::Headers::IHttpProductInfoHeaderValueCollection>
{
    HRESULT __stdcall abi_ParseAdd(impl::abi_arg_in<hstring> input) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ParseAdd(*reinterpret_cast<const hstring *>(&input));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryParseAdd(impl::abi_arg_in<hstring> input, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryParseAdd(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpProductInfoHeaderValueFactory> : produce_base<D, Windows::Web::Http::Headers::IHttpProductInfoHeaderValueFactory>
{
    HRESULT __stdcall abi_CreateFromComment(impl::abi_arg_in<hstring> productComment, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpProductInfoHeaderValue> productInfoHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *productInfoHeaderValue = detach_abi(this->shim().CreateFromComment(*reinterpret_cast<const hstring *>(&productComment)));
            return S_OK;
        }
        catch (...)
        {
            *productInfoHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromNameWithVersion(impl::abi_arg_in<hstring> productName, impl::abi_arg_in<hstring> productVersion, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpProductInfoHeaderValue> productInfoHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *productInfoHeaderValue = detach_abi(this->shim().CreateFromNameWithVersion(*reinterpret_cast<const hstring *>(&productName), *reinterpret_cast<const hstring *>(&productVersion)));
            return S_OK;
        }
        catch (...)
        {
            *productInfoHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpProductInfoHeaderValueStatics> : produce_base<D, Windows::Web::Http::Headers::IHttpProductInfoHeaderValueStatics>
{
    HRESULT __stdcall abi_Parse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpProductInfoHeaderValue> productInfoHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *productInfoHeaderValue = detach_abi(this->shim().Parse(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            *productInfoHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryParse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpProductInfoHeaderValue> productInfoHeaderValue, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryParse(*reinterpret_cast<const hstring *>(&input), *productInfoHeaderValue));
            return S_OK;
        }
        catch (...)
        {
            *productInfoHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpRequestHeaderCollection> : produce_base<D, Windows::Web::Http::Headers::IHttpRequestHeaderCollection>
{
    HRESULT __stdcall get_Accept(impl::abi_arg_out<Windows::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValueCollection> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Accept());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AcceptEncoding(impl::abi_arg_out<Windows::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValueCollection> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AcceptEncoding());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AcceptLanguage(impl::abi_arg_out<Windows::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValueCollection> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AcceptLanguage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Authorization(impl::abi_arg_out<Windows::Web::Http::Headers::IHttpCredentialsHeaderValue> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Authorization());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Authorization(impl::abi_arg_in<Windows::Web::Http::Headers::IHttpCredentialsHeaderValue> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Authorization(*reinterpret_cast<const Windows::Web::Http::Headers::HttpCredentialsHeaderValue *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CacheControl(impl::abi_arg_out<Windows::Web::Http::Headers::IHttpCacheDirectiveHeaderValueCollection> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CacheControl());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Connection(impl::abi_arg_out<Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValueCollection> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Connection());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Cookie(impl::abi_arg_out<Windows::Web::Http::Headers::IHttpCookiePairHeaderValueCollection> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Cookie());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Date(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Date());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Date(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Date(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::DateTime> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Expect(impl::abi_arg_out<Windows::Web::Http::Headers::IHttpExpectationHeaderValueCollection> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Expect());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_From(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().From());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_From(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().From(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Host(impl::abi_arg_out<Windows::Networking::IHostName> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Host());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Host(impl::abi_arg_in<Windows::Networking::IHostName> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Host(*reinterpret_cast<const Windows::Networking::HostName *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IfModifiedSince(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IfModifiedSince());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IfModifiedSince(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IfModifiedSince(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::DateTime> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IfUnmodifiedSince(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IfUnmodifiedSince());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IfUnmodifiedSince(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IfUnmodifiedSince(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::DateTime> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxForwards(impl::abi_arg_out<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxForwards());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxForwards(impl::abi_arg_in<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxForwards(*reinterpret_cast<const Windows::Foundation::IReference<uint32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProxyAuthorization(impl::abi_arg_out<Windows::Web::Http::Headers::IHttpCredentialsHeaderValue> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProxyAuthorization());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ProxyAuthorization(impl::abi_arg_in<Windows::Web::Http::Headers::IHttpCredentialsHeaderValue> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProxyAuthorization(*reinterpret_cast<const Windows::Web::Http::Headers::HttpCredentialsHeaderValue *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Referer(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Referer());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Referer(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Referer(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TransferEncoding(impl::abi_arg_out<Windows::Web::Http::Headers::IHttpTransferCodingHeaderValueCollection> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TransferEncoding());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UserAgent(impl::abi_arg_out<Windows::Web::Http::Headers::IHttpProductInfoHeaderValueCollection> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UserAgent());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Append(impl::abi_arg_in<hstring> name, impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Append(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryAppendWithoutValidation(impl::abi_arg_in<hstring> name, impl::abi_arg_in<hstring> value, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryAppendWithoutValidation(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const hstring *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpResponseHeaderCollection> : produce_base<D, Windows::Web::Http::Headers::IHttpResponseHeaderCollection>
{
    HRESULT __stdcall get_Age(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Age());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Age(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Age(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::TimeSpan> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Allow(impl::abi_arg_out<Windows::Web::Http::Headers::IHttpMethodHeaderValueCollection> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Allow());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CacheControl(impl::abi_arg_out<Windows::Web::Http::Headers::IHttpCacheDirectiveHeaderValueCollection> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CacheControl());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Connection(impl::abi_arg_out<Windows::Web::Http::Headers::IHttpConnectionOptionHeaderValueCollection> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Connection());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Date(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Date());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Date(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Date(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::DateTime> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Location(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Location());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Location(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Location(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProxyAuthenticate(impl::abi_arg_out<Windows::Web::Http::Headers::IHttpChallengeHeaderValueCollection> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProxyAuthenticate());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RetryAfter(impl::abi_arg_out<Windows::Web::Http::Headers::IHttpDateOrDeltaHeaderValue> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RetryAfter());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RetryAfter(impl::abi_arg_in<Windows::Web::Http::Headers::IHttpDateOrDeltaHeaderValue> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RetryAfter(*reinterpret_cast<const Windows::Web::Http::Headers::HttpDateOrDeltaHeaderValue *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TransferEncoding(impl::abi_arg_out<Windows::Web::Http::Headers::IHttpTransferCodingHeaderValueCollection> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TransferEncoding());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WwwAuthenticate(impl::abi_arg_out<Windows::Web::Http::Headers::IHttpChallengeHeaderValueCollection> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WwwAuthenticate());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Append(impl::abi_arg_in<hstring> name, impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Append(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryAppendWithoutValidation(impl::abi_arg_in<hstring> name, impl::abi_arg_in<hstring> value, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryAppendWithoutValidation(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const hstring *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpTransferCodingHeaderValue> : produce_base<D, Windows::Web::Http::Headers::IHttpTransferCodingHeaderValue>
{
    HRESULT __stdcall get_Parameters(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Web::Http::Headers::HttpNameValueHeaderValue>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Parameters());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
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
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpTransferCodingHeaderValueCollection> : produce_base<D, Windows::Web::Http::Headers::IHttpTransferCodingHeaderValueCollection>
{
    HRESULT __stdcall abi_ParseAdd(impl::abi_arg_in<hstring> input) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ParseAdd(*reinterpret_cast<const hstring *>(&input));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryParseAdd(impl::abi_arg_in<hstring> input, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryParseAdd(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpTransferCodingHeaderValueFactory> : produce_base<D, Windows::Web::Http::Headers::IHttpTransferCodingHeaderValueFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpTransferCodingHeaderValue> transferCodingHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *transferCodingHeaderValue = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            *transferCodingHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Http::Headers::IHttpTransferCodingHeaderValueStatics> : produce_base<D, Windows::Web::Http::Headers::IHttpTransferCodingHeaderValueStatics>
{
    HRESULT __stdcall abi_Parse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpTransferCodingHeaderValue> transferCodingHeaderValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *transferCodingHeaderValue = detach_abi(this->shim().Parse(*reinterpret_cast<const hstring *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            *transferCodingHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryParse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Web::Http::Headers::IHttpTransferCodingHeaderValue> transferCodingHeaderValue, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryParse(*reinterpret_cast<const hstring *>(&input), *transferCodingHeaderValue));
            return S_OK;
        }
        catch (...)
        {
            *transferCodingHeaderValue = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Web::Http::Headers {

template <typename D> Windows::Web::Http::Headers::HttpContentDispositionHeaderValue impl_IHttpContentHeaderCollection<D>::ContentDisposition() const
{
    Windows::Web::Http::Headers::HttpContentDispositionHeaderValue value { nullptr };
    check_hresult(WINRT_SHIM(IHttpContentHeaderCollection)->get_ContentDisposition(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpContentHeaderCollection<D>::ContentDisposition(const Windows::Web::Http::Headers::HttpContentDispositionHeaderValue & value) const
{
    check_hresult(WINRT_SHIM(IHttpContentHeaderCollection)->put_ContentDisposition(get_abi(value)));
}

template <typename D> Windows::Web::Http::Headers::HttpContentCodingHeaderValueCollection impl_IHttpContentHeaderCollection<D>::ContentEncoding() const
{
    Windows::Web::Http::Headers::HttpContentCodingHeaderValueCollection value { nullptr };
    check_hresult(WINRT_SHIM(IHttpContentHeaderCollection)->get_ContentEncoding(put_abi(value)));
    return value;
}

template <typename D> Windows::Web::Http::Headers::HttpLanguageHeaderValueCollection impl_IHttpContentHeaderCollection<D>::ContentLanguage() const
{
    Windows::Web::Http::Headers::HttpLanguageHeaderValueCollection value { nullptr };
    check_hresult(WINRT_SHIM(IHttpContentHeaderCollection)->get_ContentLanguage(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<uint64_t> impl_IHttpContentHeaderCollection<D>::ContentLength() const
{
    Windows::Foundation::IReference<uint64_t> value;
    check_hresult(WINRT_SHIM(IHttpContentHeaderCollection)->get_ContentLength(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpContentHeaderCollection<D>::ContentLength(const optional<uint64_t> & value) const
{
    check_hresult(WINRT_SHIM(IHttpContentHeaderCollection)->put_ContentLength(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_IHttpContentHeaderCollection<D>::ContentLocation() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IHttpContentHeaderCollection)->get_ContentLocation(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpContentHeaderCollection<D>::ContentLocation(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(IHttpContentHeaderCollection)->put_ContentLocation(get_abi(value)));
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IHttpContentHeaderCollection<D>::ContentMD5() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IHttpContentHeaderCollection)->get_ContentMD5(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpContentHeaderCollection<D>::ContentMD5(const Windows::Storage::Streams::IBuffer & value) const
{
    check_hresult(WINRT_SHIM(IHttpContentHeaderCollection)->put_ContentMD5(get_abi(value)));
}

template <typename D> Windows::Web::Http::Headers::HttpContentRangeHeaderValue impl_IHttpContentHeaderCollection<D>::ContentRange() const
{
    Windows::Web::Http::Headers::HttpContentRangeHeaderValue value { nullptr };
    check_hresult(WINRT_SHIM(IHttpContentHeaderCollection)->get_ContentRange(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpContentHeaderCollection<D>::ContentRange(const Windows::Web::Http::Headers::HttpContentRangeHeaderValue & value) const
{
    check_hresult(WINRT_SHIM(IHttpContentHeaderCollection)->put_ContentRange(get_abi(value)));
}

template <typename D> Windows::Web::Http::Headers::HttpMediaTypeHeaderValue impl_IHttpContentHeaderCollection<D>::ContentType() const
{
    Windows::Web::Http::Headers::HttpMediaTypeHeaderValue value { nullptr };
    check_hresult(WINRT_SHIM(IHttpContentHeaderCollection)->get_ContentType(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpContentHeaderCollection<D>::ContentType(const Windows::Web::Http::Headers::HttpMediaTypeHeaderValue & value) const
{
    check_hresult(WINRT_SHIM(IHttpContentHeaderCollection)->put_ContentType(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IHttpContentHeaderCollection<D>::Expires() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(IHttpContentHeaderCollection)->get_Expires(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpContentHeaderCollection<D>::Expires(const optional<Windows::Foundation::DateTime> & value) const
{
    check_hresult(WINRT_SHIM(IHttpContentHeaderCollection)->put_Expires(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IHttpContentHeaderCollection<D>::LastModified() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(IHttpContentHeaderCollection)->get_LastModified(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpContentHeaderCollection<D>::LastModified(const optional<Windows::Foundation::DateTime> & value) const
{
    check_hresult(WINRT_SHIM(IHttpContentHeaderCollection)->put_LastModified(get_abi(value)));
}

template <typename D> void impl_IHttpContentHeaderCollection<D>::Append(hstring_view name, hstring_view value) const
{
    check_hresult(WINRT_SHIM(IHttpContentHeaderCollection)->abi_Append(get_abi(name), get_abi(value)));
}

template <typename D> bool impl_IHttpContentHeaderCollection<D>::TryAppendWithoutValidation(hstring_view name, hstring_view value) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IHttpContentHeaderCollection)->abi_TryAppendWithoutValidation(get_abi(name), get_abi(value), &succeeded));
    return succeeded;
}

template <typename D> Windows::Web::Http::Headers::HttpMediaTypeWithQualityHeaderValueCollection impl_IHttpRequestHeaderCollection<D>::Accept() const
{
    Windows::Web::Http::Headers::HttpMediaTypeWithQualityHeaderValueCollection value { nullptr };
    check_hresult(WINRT_SHIM(IHttpRequestHeaderCollection)->get_Accept(put_abi(value)));
    return value;
}

template <typename D> Windows::Web::Http::Headers::HttpContentCodingWithQualityHeaderValueCollection impl_IHttpRequestHeaderCollection<D>::AcceptEncoding() const
{
    Windows::Web::Http::Headers::HttpContentCodingWithQualityHeaderValueCollection value { nullptr };
    check_hresult(WINRT_SHIM(IHttpRequestHeaderCollection)->get_AcceptEncoding(put_abi(value)));
    return value;
}

template <typename D> Windows::Web::Http::Headers::HttpLanguageRangeWithQualityHeaderValueCollection impl_IHttpRequestHeaderCollection<D>::AcceptLanguage() const
{
    Windows::Web::Http::Headers::HttpLanguageRangeWithQualityHeaderValueCollection value { nullptr };
    check_hresult(WINRT_SHIM(IHttpRequestHeaderCollection)->get_AcceptLanguage(put_abi(value)));
    return value;
}

template <typename D> Windows::Web::Http::Headers::HttpCredentialsHeaderValue impl_IHttpRequestHeaderCollection<D>::Authorization() const
{
    Windows::Web::Http::Headers::HttpCredentialsHeaderValue value { nullptr };
    check_hresult(WINRT_SHIM(IHttpRequestHeaderCollection)->get_Authorization(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpRequestHeaderCollection<D>::Authorization(const Windows::Web::Http::Headers::HttpCredentialsHeaderValue & value) const
{
    check_hresult(WINRT_SHIM(IHttpRequestHeaderCollection)->put_Authorization(get_abi(value)));
}

template <typename D> Windows::Web::Http::Headers::HttpCacheDirectiveHeaderValueCollection impl_IHttpRequestHeaderCollection<D>::CacheControl() const
{
    Windows::Web::Http::Headers::HttpCacheDirectiveHeaderValueCollection value { nullptr };
    check_hresult(WINRT_SHIM(IHttpRequestHeaderCollection)->get_CacheControl(put_abi(value)));
    return value;
}

template <typename D> Windows::Web::Http::Headers::HttpConnectionOptionHeaderValueCollection impl_IHttpRequestHeaderCollection<D>::Connection() const
{
    Windows::Web::Http::Headers::HttpConnectionOptionHeaderValueCollection value { nullptr };
    check_hresult(WINRT_SHIM(IHttpRequestHeaderCollection)->get_Connection(put_abi(value)));
    return value;
}

template <typename D> Windows::Web::Http::Headers::HttpCookiePairHeaderValueCollection impl_IHttpRequestHeaderCollection<D>::Cookie() const
{
    Windows::Web::Http::Headers::HttpCookiePairHeaderValueCollection value { nullptr };
    check_hresult(WINRT_SHIM(IHttpRequestHeaderCollection)->get_Cookie(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IHttpRequestHeaderCollection<D>::Date() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(IHttpRequestHeaderCollection)->get_Date(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpRequestHeaderCollection<D>::Date(const optional<Windows::Foundation::DateTime> & value) const
{
    check_hresult(WINRT_SHIM(IHttpRequestHeaderCollection)->put_Date(get_abi(value)));
}

template <typename D> Windows::Web::Http::Headers::HttpExpectationHeaderValueCollection impl_IHttpRequestHeaderCollection<D>::Expect() const
{
    Windows::Web::Http::Headers::HttpExpectationHeaderValueCollection value { nullptr };
    check_hresult(WINRT_SHIM(IHttpRequestHeaderCollection)->get_Expect(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IHttpRequestHeaderCollection<D>::From() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHttpRequestHeaderCollection)->get_From(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpRequestHeaderCollection<D>::From(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IHttpRequestHeaderCollection)->put_From(get_abi(value)));
}

template <typename D> Windows::Networking::HostName impl_IHttpRequestHeaderCollection<D>::Host() const
{
    Windows::Networking::HostName value { nullptr };
    check_hresult(WINRT_SHIM(IHttpRequestHeaderCollection)->get_Host(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpRequestHeaderCollection<D>::Host(const Windows::Networking::HostName & value) const
{
    check_hresult(WINRT_SHIM(IHttpRequestHeaderCollection)->put_Host(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IHttpRequestHeaderCollection<D>::IfModifiedSince() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(IHttpRequestHeaderCollection)->get_IfModifiedSince(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpRequestHeaderCollection<D>::IfModifiedSince(const optional<Windows::Foundation::DateTime> & value) const
{
    check_hresult(WINRT_SHIM(IHttpRequestHeaderCollection)->put_IfModifiedSince(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IHttpRequestHeaderCollection<D>::IfUnmodifiedSince() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(IHttpRequestHeaderCollection)->get_IfUnmodifiedSince(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpRequestHeaderCollection<D>::IfUnmodifiedSince(const optional<Windows::Foundation::DateTime> & value) const
{
    check_hresult(WINRT_SHIM(IHttpRequestHeaderCollection)->put_IfUnmodifiedSince(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<uint32_t> impl_IHttpRequestHeaderCollection<D>::MaxForwards() const
{
    Windows::Foundation::IReference<uint32_t> value;
    check_hresult(WINRT_SHIM(IHttpRequestHeaderCollection)->get_MaxForwards(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpRequestHeaderCollection<D>::MaxForwards(const optional<uint32_t> & value) const
{
    check_hresult(WINRT_SHIM(IHttpRequestHeaderCollection)->put_MaxForwards(get_abi(value)));
}

template <typename D> Windows::Web::Http::Headers::HttpCredentialsHeaderValue impl_IHttpRequestHeaderCollection<D>::ProxyAuthorization() const
{
    Windows::Web::Http::Headers::HttpCredentialsHeaderValue value { nullptr };
    check_hresult(WINRT_SHIM(IHttpRequestHeaderCollection)->get_ProxyAuthorization(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpRequestHeaderCollection<D>::ProxyAuthorization(const Windows::Web::Http::Headers::HttpCredentialsHeaderValue & value) const
{
    check_hresult(WINRT_SHIM(IHttpRequestHeaderCollection)->put_ProxyAuthorization(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_IHttpRequestHeaderCollection<D>::Referer() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IHttpRequestHeaderCollection)->get_Referer(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpRequestHeaderCollection<D>::Referer(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(IHttpRequestHeaderCollection)->put_Referer(get_abi(value)));
}

template <typename D> Windows::Web::Http::Headers::HttpTransferCodingHeaderValueCollection impl_IHttpRequestHeaderCollection<D>::TransferEncoding() const
{
    Windows::Web::Http::Headers::HttpTransferCodingHeaderValueCollection value { nullptr };
    check_hresult(WINRT_SHIM(IHttpRequestHeaderCollection)->get_TransferEncoding(put_abi(value)));
    return value;
}

template <typename D> Windows::Web::Http::Headers::HttpProductInfoHeaderValueCollection impl_IHttpRequestHeaderCollection<D>::UserAgent() const
{
    Windows::Web::Http::Headers::HttpProductInfoHeaderValueCollection value { nullptr };
    check_hresult(WINRT_SHIM(IHttpRequestHeaderCollection)->get_UserAgent(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpRequestHeaderCollection<D>::Append(hstring_view name, hstring_view value) const
{
    check_hresult(WINRT_SHIM(IHttpRequestHeaderCollection)->abi_Append(get_abi(name), get_abi(value)));
}

template <typename D> bool impl_IHttpRequestHeaderCollection<D>::TryAppendWithoutValidation(hstring_view name, hstring_view value) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IHttpRequestHeaderCollection)->abi_TryAppendWithoutValidation(get_abi(name), get_abi(value), &succeeded));
    return succeeded;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::TimeSpan> impl_IHttpResponseHeaderCollection<D>::Age() const
{
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> value;
    check_hresult(WINRT_SHIM(IHttpResponseHeaderCollection)->get_Age(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpResponseHeaderCollection<D>::Age(const optional<Windows::Foundation::TimeSpan> & value) const
{
    check_hresult(WINRT_SHIM(IHttpResponseHeaderCollection)->put_Age(get_abi(value)));
}

template <typename D> Windows::Web::Http::Headers::HttpMethodHeaderValueCollection impl_IHttpResponseHeaderCollection<D>::Allow() const
{
    Windows::Web::Http::Headers::HttpMethodHeaderValueCollection value { nullptr };
    check_hresult(WINRT_SHIM(IHttpResponseHeaderCollection)->get_Allow(put_abi(value)));
    return value;
}

template <typename D> Windows::Web::Http::Headers::HttpCacheDirectiveHeaderValueCollection impl_IHttpResponseHeaderCollection<D>::CacheControl() const
{
    Windows::Web::Http::Headers::HttpCacheDirectiveHeaderValueCollection value { nullptr };
    check_hresult(WINRT_SHIM(IHttpResponseHeaderCollection)->get_CacheControl(put_abi(value)));
    return value;
}

template <typename D> Windows::Web::Http::Headers::HttpConnectionOptionHeaderValueCollection impl_IHttpResponseHeaderCollection<D>::Connection() const
{
    Windows::Web::Http::Headers::HttpConnectionOptionHeaderValueCollection value { nullptr };
    check_hresult(WINRT_SHIM(IHttpResponseHeaderCollection)->get_Connection(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IHttpResponseHeaderCollection<D>::Date() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(IHttpResponseHeaderCollection)->get_Date(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpResponseHeaderCollection<D>::Date(const optional<Windows::Foundation::DateTime> & value) const
{
    check_hresult(WINRT_SHIM(IHttpResponseHeaderCollection)->put_Date(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_IHttpResponseHeaderCollection<D>::Location() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IHttpResponseHeaderCollection)->get_Location(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpResponseHeaderCollection<D>::Location(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(IHttpResponseHeaderCollection)->put_Location(get_abi(value)));
}

template <typename D> Windows::Web::Http::Headers::HttpChallengeHeaderValueCollection impl_IHttpResponseHeaderCollection<D>::ProxyAuthenticate() const
{
    Windows::Web::Http::Headers::HttpChallengeHeaderValueCollection value { nullptr };
    check_hresult(WINRT_SHIM(IHttpResponseHeaderCollection)->get_ProxyAuthenticate(put_abi(value)));
    return value;
}

template <typename D> Windows::Web::Http::Headers::HttpDateOrDeltaHeaderValue impl_IHttpResponseHeaderCollection<D>::RetryAfter() const
{
    Windows::Web::Http::Headers::HttpDateOrDeltaHeaderValue value { nullptr };
    check_hresult(WINRT_SHIM(IHttpResponseHeaderCollection)->get_RetryAfter(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpResponseHeaderCollection<D>::RetryAfter(const Windows::Web::Http::Headers::HttpDateOrDeltaHeaderValue & value) const
{
    check_hresult(WINRT_SHIM(IHttpResponseHeaderCollection)->put_RetryAfter(get_abi(value)));
}

template <typename D> Windows::Web::Http::Headers::HttpTransferCodingHeaderValueCollection impl_IHttpResponseHeaderCollection<D>::TransferEncoding() const
{
    Windows::Web::Http::Headers::HttpTransferCodingHeaderValueCollection value { nullptr };
    check_hresult(WINRT_SHIM(IHttpResponseHeaderCollection)->get_TransferEncoding(put_abi(value)));
    return value;
}

template <typename D> Windows::Web::Http::Headers::HttpChallengeHeaderValueCollection impl_IHttpResponseHeaderCollection<D>::WwwAuthenticate() const
{
    Windows::Web::Http::Headers::HttpChallengeHeaderValueCollection value { nullptr };
    check_hresult(WINRT_SHIM(IHttpResponseHeaderCollection)->get_WwwAuthenticate(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpResponseHeaderCollection<D>::Append(hstring_view name, hstring_view value) const
{
    check_hresult(WINRT_SHIM(IHttpResponseHeaderCollection)->abi_Append(get_abi(name), get_abi(value)));
}

template <typename D> bool impl_IHttpResponseHeaderCollection<D>::TryAppendWithoutValidation(hstring_view name, hstring_view value) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IHttpResponseHeaderCollection)->abi_TryAppendWithoutValidation(get_abi(name), get_abi(value), &succeeded));
    return succeeded;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::TimeSpan> impl_IHttpCacheDirectiveHeaderValueCollection<D>::MaxAge() const
{
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> value;
    check_hresult(WINRT_SHIM(IHttpCacheDirectiveHeaderValueCollection)->get_MaxAge(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpCacheDirectiveHeaderValueCollection<D>::MaxAge(const optional<Windows::Foundation::TimeSpan> & value) const
{
    check_hresult(WINRT_SHIM(IHttpCacheDirectiveHeaderValueCollection)->put_MaxAge(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::TimeSpan> impl_IHttpCacheDirectiveHeaderValueCollection<D>::MaxStale() const
{
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> value;
    check_hresult(WINRT_SHIM(IHttpCacheDirectiveHeaderValueCollection)->get_MaxStale(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpCacheDirectiveHeaderValueCollection<D>::MaxStale(const optional<Windows::Foundation::TimeSpan> & value) const
{
    check_hresult(WINRT_SHIM(IHttpCacheDirectiveHeaderValueCollection)->put_MaxStale(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::TimeSpan> impl_IHttpCacheDirectiveHeaderValueCollection<D>::MinFresh() const
{
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> value;
    check_hresult(WINRT_SHIM(IHttpCacheDirectiveHeaderValueCollection)->get_MinFresh(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpCacheDirectiveHeaderValueCollection<D>::MinFresh(const optional<Windows::Foundation::TimeSpan> & value) const
{
    check_hresult(WINRT_SHIM(IHttpCacheDirectiveHeaderValueCollection)->put_MinFresh(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::TimeSpan> impl_IHttpCacheDirectiveHeaderValueCollection<D>::SharedMaxAge() const
{
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> value;
    check_hresult(WINRT_SHIM(IHttpCacheDirectiveHeaderValueCollection)->get_SharedMaxAge(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpCacheDirectiveHeaderValueCollection<D>::SharedMaxAge(const optional<Windows::Foundation::TimeSpan> & value) const
{
    check_hresult(WINRT_SHIM(IHttpCacheDirectiveHeaderValueCollection)->put_SharedMaxAge(get_abi(value)));
}

template <typename D> void impl_IHttpCacheDirectiveHeaderValueCollection<D>::ParseAdd(hstring_view input) const
{
    check_hresult(WINRT_SHIM(IHttpCacheDirectiveHeaderValueCollection)->abi_ParseAdd(get_abi(input)));
}

template <typename D> bool impl_IHttpCacheDirectiveHeaderValueCollection<D>::TryParseAdd(hstring_view input) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IHttpCacheDirectiveHeaderValueCollection)->abi_TryParseAdd(get_abi(input), &succeeded));
    return succeeded;
}

template <typename D> Windows::Web::Http::Headers::HttpChallengeHeaderValue impl_IHttpChallengeHeaderValueStatics<D>::Parse(hstring_view input) const
{
    Windows::Web::Http::Headers::HttpChallengeHeaderValue challengeHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpChallengeHeaderValueStatics)->abi_Parse(get_abi(input), put_abi(challengeHeaderValue)));
    return challengeHeaderValue;
}

template <typename D> bool impl_IHttpChallengeHeaderValueStatics<D>::TryParse(hstring_view input, Windows::Web::Http::Headers::HttpChallengeHeaderValue & challengeHeaderValue) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IHttpChallengeHeaderValueStatics)->abi_TryParse(get_abi(input), put_abi(challengeHeaderValue), &succeeded));
    return succeeded;
}

template <typename D> Windows::Web::Http::Headers::HttpChallengeHeaderValue impl_IHttpChallengeHeaderValueFactory<D>::CreateFromScheme(hstring_view scheme) const
{
    Windows::Web::Http::Headers::HttpChallengeHeaderValue challengeHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpChallengeHeaderValueFactory)->abi_CreateFromScheme(get_abi(scheme), put_abi(challengeHeaderValue)));
    return challengeHeaderValue;
}

template <typename D> Windows::Web::Http::Headers::HttpChallengeHeaderValue impl_IHttpChallengeHeaderValueFactory<D>::CreateFromSchemeWithToken(hstring_view scheme, hstring_view token) const
{
    Windows::Web::Http::Headers::HttpChallengeHeaderValue challengeHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpChallengeHeaderValueFactory)->abi_CreateFromSchemeWithToken(get_abi(scheme), get_abi(token), put_abi(challengeHeaderValue)));
    return challengeHeaderValue;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Web::Http::Headers::HttpNameValueHeaderValue> impl_IHttpChallengeHeaderValue<D>::Parameters() const
{
    Windows::Foundation::Collections::IVector<Windows::Web::Http::Headers::HttpNameValueHeaderValue> value;
    check_hresult(WINRT_SHIM(IHttpChallengeHeaderValue)->get_Parameters(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IHttpChallengeHeaderValue<D>::Scheme() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHttpChallengeHeaderValue)->get_Scheme(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IHttpChallengeHeaderValue<D>::Token() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHttpChallengeHeaderValue)->get_Token(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpChallengeHeaderValueCollection<D>::ParseAdd(hstring_view input) const
{
    check_hresult(WINRT_SHIM(IHttpChallengeHeaderValueCollection)->abi_ParseAdd(get_abi(input)));
}

template <typename D> bool impl_IHttpChallengeHeaderValueCollection<D>::TryParseAdd(hstring_view input) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IHttpChallengeHeaderValueCollection)->abi_TryParseAdd(get_abi(input), &succeeded));
    return succeeded;
}

template <typename D> Windows::Web::Http::Headers::HttpCredentialsHeaderValue impl_IHttpCredentialsHeaderValueStatics<D>::Parse(hstring_view input) const
{
    Windows::Web::Http::Headers::HttpCredentialsHeaderValue credentialsHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpCredentialsHeaderValueStatics)->abi_Parse(get_abi(input), put_abi(credentialsHeaderValue)));
    return credentialsHeaderValue;
}

template <typename D> bool impl_IHttpCredentialsHeaderValueStatics<D>::TryParse(hstring_view input, Windows::Web::Http::Headers::HttpCredentialsHeaderValue & credentialsHeaderValue) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IHttpCredentialsHeaderValueStatics)->abi_TryParse(get_abi(input), put_abi(credentialsHeaderValue), &succeeded));
    return succeeded;
}

template <typename D> Windows::Web::Http::Headers::HttpCredentialsHeaderValue impl_IHttpCredentialsHeaderValueFactory<D>::CreateFromScheme(hstring_view scheme) const
{
    Windows::Web::Http::Headers::HttpCredentialsHeaderValue credentialsHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpCredentialsHeaderValueFactory)->abi_CreateFromScheme(get_abi(scheme), put_abi(credentialsHeaderValue)));
    return credentialsHeaderValue;
}

template <typename D> Windows::Web::Http::Headers::HttpCredentialsHeaderValue impl_IHttpCredentialsHeaderValueFactory<D>::CreateFromSchemeWithToken(hstring_view scheme, hstring_view token) const
{
    Windows::Web::Http::Headers::HttpCredentialsHeaderValue credentialsHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpCredentialsHeaderValueFactory)->abi_CreateFromSchemeWithToken(get_abi(scheme), get_abi(token), put_abi(credentialsHeaderValue)));
    return credentialsHeaderValue;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Web::Http::Headers::HttpNameValueHeaderValue> impl_IHttpCredentialsHeaderValue<D>::Parameters() const
{
    Windows::Foundation::Collections::IVector<Windows::Web::Http::Headers::HttpNameValueHeaderValue> value;
    check_hresult(WINRT_SHIM(IHttpCredentialsHeaderValue)->get_Parameters(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IHttpCredentialsHeaderValue<D>::Scheme() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHttpCredentialsHeaderValue)->get_Scheme(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IHttpCredentialsHeaderValue<D>::Token() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHttpCredentialsHeaderValue)->get_Token(put_abi(value)));
    return value;
}

template <typename D> Windows::Web::Http::Headers::HttpConnectionOptionHeaderValue impl_IHttpConnectionOptionHeaderValueStatics<D>::Parse(hstring_view input) const
{
    Windows::Web::Http::Headers::HttpConnectionOptionHeaderValue connectionOptionHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpConnectionOptionHeaderValueStatics)->abi_Parse(get_abi(input), put_abi(connectionOptionHeaderValue)));
    return connectionOptionHeaderValue;
}

template <typename D> bool impl_IHttpConnectionOptionHeaderValueStatics<D>::TryParse(hstring_view input, Windows::Web::Http::Headers::HttpConnectionOptionHeaderValue & connectionOptionHeaderValue) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IHttpConnectionOptionHeaderValueStatics)->abi_TryParse(get_abi(input), put_abi(connectionOptionHeaderValue), &succeeded));
    return succeeded;
}

template <typename D> Windows::Web::Http::Headers::HttpConnectionOptionHeaderValue impl_IHttpConnectionOptionHeaderValueFactory<D>::Create(hstring_view token) const
{
    Windows::Web::Http::Headers::HttpConnectionOptionHeaderValue connectionOptionHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpConnectionOptionHeaderValueFactory)->abi_Create(get_abi(token), put_abi(connectionOptionHeaderValue)));
    return connectionOptionHeaderValue;
}

template <typename D> hstring impl_IHttpConnectionOptionHeaderValue<D>::Token() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHttpConnectionOptionHeaderValue)->get_Token(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpConnectionOptionHeaderValueCollection<D>::ParseAdd(hstring_view input) const
{
    check_hresult(WINRT_SHIM(IHttpConnectionOptionHeaderValueCollection)->abi_ParseAdd(get_abi(input)));
}

template <typename D> bool impl_IHttpConnectionOptionHeaderValueCollection<D>::TryParseAdd(hstring_view input) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IHttpConnectionOptionHeaderValueCollection)->abi_TryParseAdd(get_abi(input), &succeeded));
    return succeeded;
}

template <typename D> Windows::Web::Http::Headers::HttpContentCodingHeaderValue impl_IHttpContentCodingHeaderValueStatics<D>::Parse(hstring_view input) const
{
    Windows::Web::Http::Headers::HttpContentCodingHeaderValue contentCodingHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpContentCodingHeaderValueStatics)->abi_Parse(get_abi(input), put_abi(contentCodingHeaderValue)));
    return contentCodingHeaderValue;
}

template <typename D> bool impl_IHttpContentCodingHeaderValueStatics<D>::TryParse(hstring_view input, Windows::Web::Http::Headers::HttpContentCodingHeaderValue & contentCodingHeaderValue) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IHttpContentCodingHeaderValueStatics)->abi_TryParse(get_abi(input), put_abi(contentCodingHeaderValue), &succeeded));
    return succeeded;
}

template <typename D> Windows::Web::Http::Headers::HttpContentCodingHeaderValue impl_IHttpContentCodingHeaderValueFactory<D>::Create(hstring_view contentCoding) const
{
    Windows::Web::Http::Headers::HttpContentCodingHeaderValue contentCodingHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpContentCodingHeaderValueFactory)->abi_Create(get_abi(contentCoding), put_abi(contentCodingHeaderValue)));
    return contentCodingHeaderValue;
}

template <typename D> hstring impl_IHttpContentCodingHeaderValue<D>::ContentCoding() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHttpContentCodingHeaderValue)->get_ContentCoding(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpContentCodingHeaderValueCollection<D>::ParseAdd(hstring_view input) const
{
    check_hresult(WINRT_SHIM(IHttpContentCodingHeaderValueCollection)->abi_ParseAdd(get_abi(input)));
}

template <typename D> bool impl_IHttpContentCodingHeaderValueCollection<D>::TryParseAdd(hstring_view input) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IHttpContentCodingHeaderValueCollection)->abi_TryParseAdd(get_abi(input), &succeeded));
    return succeeded;
}

template <typename D> Windows::Web::Http::Headers::HttpContentDispositionHeaderValue impl_IHttpContentDispositionHeaderValueStatics<D>::Parse(hstring_view input) const
{
    Windows::Web::Http::Headers::HttpContentDispositionHeaderValue contentDispositionHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpContentDispositionHeaderValueStatics)->abi_Parse(get_abi(input), put_abi(contentDispositionHeaderValue)));
    return contentDispositionHeaderValue;
}

template <typename D> bool impl_IHttpContentDispositionHeaderValueStatics<D>::TryParse(hstring_view input, Windows::Web::Http::Headers::HttpContentDispositionHeaderValue & contentDispositionHeaderValue) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IHttpContentDispositionHeaderValueStatics)->abi_TryParse(get_abi(input), put_abi(contentDispositionHeaderValue), &succeeded));
    return succeeded;
}

template <typename D> Windows::Web::Http::Headers::HttpContentDispositionHeaderValue impl_IHttpContentDispositionHeaderValueFactory<D>::Create(hstring_view dispositionType) const
{
    Windows::Web::Http::Headers::HttpContentDispositionHeaderValue contentDispositionHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpContentDispositionHeaderValueFactory)->abi_Create(get_abi(dispositionType), put_abi(contentDispositionHeaderValue)));
    return contentDispositionHeaderValue;
}

template <typename D> hstring impl_IHttpContentDispositionHeaderValue<D>::DispositionType() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHttpContentDispositionHeaderValue)->get_DispositionType(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpContentDispositionHeaderValue<D>::DispositionType(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IHttpContentDispositionHeaderValue)->put_DispositionType(get_abi(value)));
}

template <typename D> hstring impl_IHttpContentDispositionHeaderValue<D>::FileName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHttpContentDispositionHeaderValue)->get_FileName(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpContentDispositionHeaderValue<D>::FileName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IHttpContentDispositionHeaderValue)->put_FileName(get_abi(value)));
}

template <typename D> hstring impl_IHttpContentDispositionHeaderValue<D>::FileNameStar() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHttpContentDispositionHeaderValue)->get_FileNameStar(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpContentDispositionHeaderValue<D>::FileNameStar(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IHttpContentDispositionHeaderValue)->put_FileNameStar(get_abi(value)));
}

template <typename D> hstring impl_IHttpContentDispositionHeaderValue<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHttpContentDispositionHeaderValue)->get_Name(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpContentDispositionHeaderValue<D>::Name(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IHttpContentDispositionHeaderValue)->put_Name(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Web::Http::Headers::HttpNameValueHeaderValue> impl_IHttpContentDispositionHeaderValue<D>::Parameters() const
{
    Windows::Foundation::Collections::IVector<Windows::Web::Http::Headers::HttpNameValueHeaderValue> value;
    check_hresult(WINRT_SHIM(IHttpContentDispositionHeaderValue)->get_Parameters(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<uint64_t> impl_IHttpContentDispositionHeaderValue<D>::Size() const
{
    Windows::Foundation::IReference<uint64_t> value;
    check_hresult(WINRT_SHIM(IHttpContentDispositionHeaderValue)->get_Size(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpContentDispositionHeaderValue<D>::Size(const optional<uint64_t> & value) const
{
    check_hresult(WINRT_SHIM(IHttpContentDispositionHeaderValue)->put_Size(get_abi(value)));
}

template <typename D> Windows::Web::Http::Headers::HttpContentRangeHeaderValue impl_IHttpContentRangeHeaderValueStatics<D>::Parse(hstring_view input) const
{
    Windows::Web::Http::Headers::HttpContentRangeHeaderValue contentRangeHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpContentRangeHeaderValueStatics)->abi_Parse(get_abi(input), put_abi(contentRangeHeaderValue)));
    return contentRangeHeaderValue;
}

template <typename D> bool impl_IHttpContentRangeHeaderValueStatics<D>::TryParse(hstring_view input, Windows::Web::Http::Headers::HttpContentRangeHeaderValue & contentRangeHeaderValue) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IHttpContentRangeHeaderValueStatics)->abi_TryParse(get_abi(input), put_abi(contentRangeHeaderValue), &succeeded));
    return succeeded;
}

template <typename D> Windows::Web::Http::Headers::HttpContentRangeHeaderValue impl_IHttpContentRangeHeaderValueFactory<D>::CreateFromLength(uint64_t length) const
{
    Windows::Web::Http::Headers::HttpContentRangeHeaderValue contentRangeHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpContentRangeHeaderValueFactory)->abi_CreateFromLength(length, put_abi(contentRangeHeaderValue)));
    return contentRangeHeaderValue;
}

template <typename D> Windows::Web::Http::Headers::HttpContentRangeHeaderValue impl_IHttpContentRangeHeaderValueFactory<D>::CreateFromRange(uint64_t from, uint64_t to) const
{
    Windows::Web::Http::Headers::HttpContentRangeHeaderValue contentRangeHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpContentRangeHeaderValueFactory)->abi_CreateFromRange(from, to, put_abi(contentRangeHeaderValue)));
    return contentRangeHeaderValue;
}

template <typename D> Windows::Web::Http::Headers::HttpContentRangeHeaderValue impl_IHttpContentRangeHeaderValueFactory<D>::CreateFromRangeWithLength(uint64_t from, uint64_t to, uint64_t length) const
{
    Windows::Web::Http::Headers::HttpContentRangeHeaderValue contentRangeHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpContentRangeHeaderValueFactory)->abi_CreateFromRangeWithLength(from, to, length, put_abi(contentRangeHeaderValue)));
    return contentRangeHeaderValue;
}

template <typename D> Windows::Foundation::IReference<uint64_t> impl_IHttpContentRangeHeaderValue<D>::FirstBytePosition() const
{
    Windows::Foundation::IReference<uint64_t> value;
    check_hresult(WINRT_SHIM(IHttpContentRangeHeaderValue)->get_FirstBytePosition(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<uint64_t> impl_IHttpContentRangeHeaderValue<D>::LastBytePosition() const
{
    Windows::Foundation::IReference<uint64_t> value;
    check_hresult(WINRT_SHIM(IHttpContentRangeHeaderValue)->get_LastBytePosition(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<uint64_t> impl_IHttpContentRangeHeaderValue<D>::Length() const
{
    Windows::Foundation::IReference<uint64_t> value;
    check_hresult(WINRT_SHIM(IHttpContentRangeHeaderValue)->get_Length(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IHttpContentRangeHeaderValue<D>::Unit() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHttpContentRangeHeaderValue)->get_Unit(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpContentRangeHeaderValue<D>::Unit(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IHttpContentRangeHeaderValue)->put_Unit(get_abi(value)));
}

template <typename D> Windows::Web::Http::Headers::HttpCookiePairHeaderValue impl_IHttpCookiePairHeaderValueStatics<D>::Parse(hstring_view input) const
{
    Windows::Web::Http::Headers::HttpCookiePairHeaderValue cookiePairHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpCookiePairHeaderValueStatics)->abi_Parse(get_abi(input), put_abi(cookiePairHeaderValue)));
    return cookiePairHeaderValue;
}

template <typename D> bool impl_IHttpCookiePairHeaderValueStatics<D>::TryParse(hstring_view input, Windows::Web::Http::Headers::HttpCookiePairHeaderValue & cookiePairHeaderValue) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IHttpCookiePairHeaderValueStatics)->abi_TryParse(get_abi(input), put_abi(cookiePairHeaderValue), &succeeded));
    return succeeded;
}

template <typename D> Windows::Web::Http::Headers::HttpCookiePairHeaderValue impl_IHttpCookiePairHeaderValueFactory<D>::CreateFromName(hstring_view name) const
{
    Windows::Web::Http::Headers::HttpCookiePairHeaderValue cookiePairHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpCookiePairHeaderValueFactory)->abi_CreateFromName(get_abi(name), put_abi(cookiePairHeaderValue)));
    return cookiePairHeaderValue;
}

template <typename D> Windows::Web::Http::Headers::HttpCookiePairHeaderValue impl_IHttpCookiePairHeaderValueFactory<D>::CreateFromNameWithValue(hstring_view name, hstring_view value) const
{
    Windows::Web::Http::Headers::HttpCookiePairHeaderValue cookiePairHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpCookiePairHeaderValueFactory)->abi_CreateFromNameWithValue(get_abi(name), get_abi(value), put_abi(cookiePairHeaderValue)));
    return cookiePairHeaderValue;
}

template <typename D> hstring impl_IHttpCookiePairHeaderValue<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHttpCookiePairHeaderValue)->get_Name(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IHttpCookiePairHeaderValue<D>::Value() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHttpCookiePairHeaderValue)->get_Value(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpCookiePairHeaderValue<D>::Value(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IHttpCookiePairHeaderValue)->put_Value(get_abi(value)));
}

template <typename D> void impl_IHttpCookiePairHeaderValueCollection<D>::ParseAdd(hstring_view input) const
{
    check_hresult(WINRT_SHIM(IHttpCookiePairHeaderValueCollection)->abi_ParseAdd(get_abi(input)));
}

template <typename D> bool impl_IHttpCookiePairHeaderValueCollection<D>::TryParseAdd(hstring_view input) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IHttpCookiePairHeaderValueCollection)->abi_TryParseAdd(get_abi(input), &succeeded));
    return succeeded;
}

template <typename D> Windows::Web::Http::Headers::HttpDateOrDeltaHeaderValue impl_IHttpDateOrDeltaHeaderValueStatics<D>::Parse(hstring_view input) const
{
    Windows::Web::Http::Headers::HttpDateOrDeltaHeaderValue dateOrDeltaHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpDateOrDeltaHeaderValueStatics)->abi_Parse(get_abi(input), put_abi(dateOrDeltaHeaderValue)));
    return dateOrDeltaHeaderValue;
}

template <typename D> bool impl_IHttpDateOrDeltaHeaderValueStatics<D>::TryParse(hstring_view input, Windows::Web::Http::Headers::HttpDateOrDeltaHeaderValue & dateOrDeltaHeaderValue) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IHttpDateOrDeltaHeaderValueStatics)->abi_TryParse(get_abi(input), put_abi(dateOrDeltaHeaderValue), &succeeded));
    return succeeded;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IHttpDateOrDeltaHeaderValue<D>::Date() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(IHttpDateOrDeltaHeaderValue)->get_Date(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::TimeSpan> impl_IHttpDateOrDeltaHeaderValue<D>::Delta() const
{
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> value;
    check_hresult(WINRT_SHIM(IHttpDateOrDeltaHeaderValue)->get_Delta(put_abi(value)));
    return value;
}

template <typename D> Windows::Web::Http::Headers::HttpExpectationHeaderValue impl_IHttpExpectationHeaderValueStatics<D>::Parse(hstring_view input) const
{
    Windows::Web::Http::Headers::HttpExpectationHeaderValue expectationHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpExpectationHeaderValueStatics)->abi_Parse(get_abi(input), put_abi(expectationHeaderValue)));
    return expectationHeaderValue;
}

template <typename D> bool impl_IHttpExpectationHeaderValueStatics<D>::TryParse(hstring_view input, Windows::Web::Http::Headers::HttpExpectationHeaderValue & expectationHeaderValue) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IHttpExpectationHeaderValueStatics)->abi_TryParse(get_abi(input), put_abi(expectationHeaderValue), &succeeded));
    return succeeded;
}

template <typename D> Windows::Web::Http::Headers::HttpExpectationHeaderValue impl_IHttpExpectationHeaderValueFactory<D>::CreateFromName(hstring_view name) const
{
    Windows::Web::Http::Headers::HttpExpectationHeaderValue expectationHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpExpectationHeaderValueFactory)->abi_CreateFromName(get_abi(name), put_abi(expectationHeaderValue)));
    return expectationHeaderValue;
}

template <typename D> Windows::Web::Http::Headers::HttpExpectationHeaderValue impl_IHttpExpectationHeaderValueFactory<D>::CreateFromNameWithValue(hstring_view name, hstring_view value) const
{
    Windows::Web::Http::Headers::HttpExpectationHeaderValue expectationHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpExpectationHeaderValueFactory)->abi_CreateFromNameWithValue(get_abi(name), get_abi(value), put_abi(expectationHeaderValue)));
    return expectationHeaderValue;
}

template <typename D> hstring impl_IHttpExpectationHeaderValue<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHttpExpectationHeaderValue)->get_Name(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IHttpExpectationHeaderValue<D>::Value() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHttpExpectationHeaderValue)->get_Value(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpExpectationHeaderValue<D>::Value(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IHttpExpectationHeaderValue)->put_Value(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Web::Http::Headers::HttpNameValueHeaderValue> impl_IHttpExpectationHeaderValue<D>::Parameters() const
{
    Windows::Foundation::Collections::IVector<Windows::Web::Http::Headers::HttpNameValueHeaderValue> value;
    check_hresult(WINRT_SHIM(IHttpExpectationHeaderValue)->get_Parameters(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpExpectationHeaderValueCollection<D>::ParseAdd(hstring_view input) const
{
    check_hresult(WINRT_SHIM(IHttpExpectationHeaderValueCollection)->abi_ParseAdd(get_abi(input)));
}

template <typename D> bool impl_IHttpExpectationHeaderValueCollection<D>::TryParseAdd(hstring_view input) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IHttpExpectationHeaderValueCollection)->abi_TryParseAdd(get_abi(input), &succeeded));
    return succeeded;
}

template <typename D> void impl_IHttpLanguageHeaderValueCollection<D>::ParseAdd(hstring_view input) const
{
    check_hresult(WINRT_SHIM(IHttpLanguageHeaderValueCollection)->abi_ParseAdd(get_abi(input)));
}

template <typename D> bool impl_IHttpLanguageHeaderValueCollection<D>::TryParseAdd(hstring_view input) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IHttpLanguageHeaderValueCollection)->abi_TryParseAdd(get_abi(input), &succeeded));
    return succeeded;
}

template <typename D> Windows::Web::Http::Headers::HttpLanguageRangeWithQualityHeaderValue impl_IHttpLanguageRangeWithQualityHeaderValueStatics<D>::Parse(hstring_view input) const
{
    Windows::Web::Http::Headers::HttpLanguageRangeWithQualityHeaderValue languageRangeWithQualityHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpLanguageRangeWithQualityHeaderValueStatics)->abi_Parse(get_abi(input), put_abi(languageRangeWithQualityHeaderValue)));
    return languageRangeWithQualityHeaderValue;
}

template <typename D> bool impl_IHttpLanguageRangeWithQualityHeaderValueStatics<D>::TryParse(hstring_view input, Windows::Web::Http::Headers::HttpLanguageRangeWithQualityHeaderValue & languageRangeWithQualityHeaderValue) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IHttpLanguageRangeWithQualityHeaderValueStatics)->abi_TryParse(get_abi(input), put_abi(languageRangeWithQualityHeaderValue), &succeeded));
    return succeeded;
}

template <typename D> Windows::Web::Http::Headers::HttpLanguageRangeWithQualityHeaderValue impl_IHttpLanguageRangeWithQualityHeaderValueFactory<D>::CreateFromLanguageRange(hstring_view languageRange) const
{
    Windows::Web::Http::Headers::HttpLanguageRangeWithQualityHeaderValue languageRangeWithQualityHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpLanguageRangeWithQualityHeaderValueFactory)->abi_CreateFromLanguageRange(get_abi(languageRange), put_abi(languageRangeWithQualityHeaderValue)));
    return languageRangeWithQualityHeaderValue;
}

template <typename D> Windows::Web::Http::Headers::HttpLanguageRangeWithQualityHeaderValue impl_IHttpLanguageRangeWithQualityHeaderValueFactory<D>::CreateFromLanguageRangeWithQuality(hstring_view languageRange, double quality) const
{
    Windows::Web::Http::Headers::HttpLanguageRangeWithQualityHeaderValue languageRangeWithQualityHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpLanguageRangeWithQualityHeaderValueFactory)->abi_CreateFromLanguageRangeWithQuality(get_abi(languageRange), quality, put_abi(languageRangeWithQualityHeaderValue)));
    return languageRangeWithQualityHeaderValue;
}

template <typename D> hstring impl_IHttpLanguageRangeWithQualityHeaderValue<D>::LanguageRange() const
{
    hstring languageRange;
    check_hresult(WINRT_SHIM(IHttpLanguageRangeWithQualityHeaderValue)->get_LanguageRange(put_abi(languageRange)));
    return languageRange;
}

template <typename D> Windows::Foundation::IReference<double> impl_IHttpLanguageRangeWithQualityHeaderValue<D>::Quality() const
{
    Windows::Foundation::IReference<double> value;
    check_hresult(WINRT_SHIM(IHttpLanguageRangeWithQualityHeaderValue)->get_Quality(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpLanguageRangeWithQualityHeaderValueCollection<D>::ParseAdd(hstring_view input) const
{
    check_hresult(WINRT_SHIM(IHttpLanguageRangeWithQualityHeaderValueCollection)->abi_ParseAdd(get_abi(input)));
}

template <typename D> bool impl_IHttpLanguageRangeWithQualityHeaderValueCollection<D>::TryParseAdd(hstring_view input) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IHttpLanguageRangeWithQualityHeaderValueCollection)->abi_TryParseAdd(get_abi(input), &succeeded));
    return succeeded;
}

template <typename D> Windows::Web::Http::Headers::HttpMediaTypeHeaderValue impl_IHttpMediaTypeHeaderValueStatics<D>::Parse(hstring_view input) const
{
    Windows::Web::Http::Headers::HttpMediaTypeHeaderValue mediaTypeHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpMediaTypeHeaderValueStatics)->abi_Parse(get_abi(input), put_abi(mediaTypeHeaderValue)));
    return mediaTypeHeaderValue;
}

template <typename D> bool impl_IHttpMediaTypeHeaderValueStatics<D>::TryParse(hstring_view input, Windows::Web::Http::Headers::HttpMediaTypeHeaderValue & mediaTypeHeaderValue) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IHttpMediaTypeHeaderValueStatics)->abi_TryParse(get_abi(input), put_abi(mediaTypeHeaderValue), &succeeded));
    return succeeded;
}

template <typename D> Windows::Web::Http::Headers::HttpMediaTypeHeaderValue impl_IHttpMediaTypeHeaderValueFactory<D>::Create(hstring_view mediaType) const
{
    Windows::Web::Http::Headers::HttpMediaTypeHeaderValue mediaTypeHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpMediaTypeHeaderValueFactory)->abi_Create(get_abi(mediaType), put_abi(mediaTypeHeaderValue)));
    return mediaTypeHeaderValue;
}

template <typename D> hstring impl_IHttpMediaTypeHeaderValue<D>::CharSet() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHttpMediaTypeHeaderValue)->get_CharSet(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpMediaTypeHeaderValue<D>::CharSet(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IHttpMediaTypeHeaderValue)->put_CharSet(get_abi(value)));
}

template <typename D> hstring impl_IHttpMediaTypeHeaderValue<D>::MediaType() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHttpMediaTypeHeaderValue)->get_MediaType(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpMediaTypeHeaderValue<D>::MediaType(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IHttpMediaTypeHeaderValue)->put_MediaType(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Web::Http::Headers::HttpNameValueHeaderValue> impl_IHttpMediaTypeHeaderValue<D>::Parameters() const
{
    Windows::Foundation::Collections::IVector<Windows::Web::Http::Headers::HttpNameValueHeaderValue> value;
    check_hresult(WINRT_SHIM(IHttpMediaTypeHeaderValue)->get_Parameters(put_abi(value)));
    return value;
}

template <typename D> Windows::Web::Http::Headers::HttpMediaTypeWithQualityHeaderValue impl_IHttpMediaTypeWithQualityHeaderValueStatics<D>::Parse(hstring_view input) const
{
    Windows::Web::Http::Headers::HttpMediaTypeWithQualityHeaderValue mediaTypeWithQualityHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpMediaTypeWithQualityHeaderValueStatics)->abi_Parse(get_abi(input), put_abi(mediaTypeWithQualityHeaderValue)));
    return mediaTypeWithQualityHeaderValue;
}

template <typename D> bool impl_IHttpMediaTypeWithQualityHeaderValueStatics<D>::TryParse(hstring_view input, Windows::Web::Http::Headers::HttpMediaTypeWithQualityHeaderValue & mediaTypeWithQualityHeaderValue) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IHttpMediaTypeWithQualityHeaderValueStatics)->abi_TryParse(get_abi(input), put_abi(mediaTypeWithQualityHeaderValue), &succeeded));
    return succeeded;
}

template <typename D> Windows::Web::Http::Headers::HttpMediaTypeWithQualityHeaderValue impl_IHttpMediaTypeWithQualityHeaderValueFactory<D>::CreateFromMediaType(hstring_view mediaType) const
{
    Windows::Web::Http::Headers::HttpMediaTypeWithQualityHeaderValue mediaTypeWithQualityHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpMediaTypeWithQualityHeaderValueFactory)->abi_CreateFromMediaType(get_abi(mediaType), put_abi(mediaTypeWithQualityHeaderValue)));
    return mediaTypeWithQualityHeaderValue;
}

template <typename D> Windows::Web::Http::Headers::HttpMediaTypeWithQualityHeaderValue impl_IHttpMediaTypeWithQualityHeaderValueFactory<D>::CreateFromMediaTypeWithQuality(hstring_view mediaType, double quality) const
{
    Windows::Web::Http::Headers::HttpMediaTypeWithQualityHeaderValue mediaTypeWithQualityHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpMediaTypeWithQualityHeaderValueFactory)->abi_CreateFromMediaTypeWithQuality(get_abi(mediaType), quality, put_abi(mediaTypeWithQualityHeaderValue)));
    return mediaTypeWithQualityHeaderValue;
}

template <typename D> hstring impl_IHttpMediaTypeWithQualityHeaderValue<D>::CharSet() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHttpMediaTypeWithQualityHeaderValue)->get_CharSet(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpMediaTypeWithQualityHeaderValue<D>::CharSet(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IHttpMediaTypeWithQualityHeaderValue)->put_CharSet(get_abi(value)));
}

template <typename D> hstring impl_IHttpMediaTypeWithQualityHeaderValue<D>::MediaType() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHttpMediaTypeWithQualityHeaderValue)->get_MediaType(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpMediaTypeWithQualityHeaderValue<D>::MediaType(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IHttpMediaTypeWithQualityHeaderValue)->put_MediaType(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Web::Http::Headers::HttpNameValueHeaderValue> impl_IHttpMediaTypeWithQualityHeaderValue<D>::Parameters() const
{
    Windows::Foundation::Collections::IVector<Windows::Web::Http::Headers::HttpNameValueHeaderValue> value;
    check_hresult(WINRT_SHIM(IHttpMediaTypeWithQualityHeaderValue)->get_Parameters(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<double> impl_IHttpMediaTypeWithQualityHeaderValue<D>::Quality() const
{
    Windows::Foundation::IReference<double> value;
    check_hresult(WINRT_SHIM(IHttpMediaTypeWithQualityHeaderValue)->get_Quality(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpMediaTypeWithQualityHeaderValue<D>::Quality(const optional<double> & value) const
{
    check_hresult(WINRT_SHIM(IHttpMediaTypeWithQualityHeaderValue)->put_Quality(get_abi(value)));
}

template <typename D> void impl_IHttpMediaTypeWithQualityHeaderValueCollection<D>::ParseAdd(hstring_view input) const
{
    check_hresult(WINRT_SHIM(IHttpMediaTypeWithQualityHeaderValueCollection)->abi_ParseAdd(get_abi(input)));
}

template <typename D> bool impl_IHttpMediaTypeWithQualityHeaderValueCollection<D>::TryParseAdd(hstring_view input) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IHttpMediaTypeWithQualityHeaderValueCollection)->abi_TryParseAdd(get_abi(input), &succeeded));
    return succeeded;
}

template <typename D> void impl_IHttpMethodHeaderValueCollection<D>::ParseAdd(hstring_view input) const
{
    check_hresult(WINRT_SHIM(IHttpMethodHeaderValueCollection)->abi_ParseAdd(get_abi(input)));
}

template <typename D> bool impl_IHttpMethodHeaderValueCollection<D>::TryParseAdd(hstring_view input) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IHttpMethodHeaderValueCollection)->abi_TryParseAdd(get_abi(input), &succeeded));
    return succeeded;
}

template <typename D> Windows::Web::Http::Headers::HttpNameValueHeaderValue impl_IHttpNameValueHeaderValueStatics<D>::Parse(hstring_view input) const
{
    Windows::Web::Http::Headers::HttpNameValueHeaderValue nameValueHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpNameValueHeaderValueStatics)->abi_Parse(get_abi(input), put_abi(nameValueHeaderValue)));
    return nameValueHeaderValue;
}

template <typename D> bool impl_IHttpNameValueHeaderValueStatics<D>::TryParse(hstring_view input, Windows::Web::Http::Headers::HttpNameValueHeaderValue & nameValueHeaderValue) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IHttpNameValueHeaderValueStatics)->abi_TryParse(get_abi(input), put_abi(nameValueHeaderValue), &succeeded));
    return succeeded;
}

template <typename D> Windows::Web::Http::Headers::HttpNameValueHeaderValue impl_IHttpNameValueHeaderValueFactory<D>::CreateFromName(hstring_view name) const
{
    Windows::Web::Http::Headers::HttpNameValueHeaderValue nameValueHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpNameValueHeaderValueFactory)->abi_CreateFromName(get_abi(name), put_abi(nameValueHeaderValue)));
    return nameValueHeaderValue;
}

template <typename D> Windows::Web::Http::Headers::HttpNameValueHeaderValue impl_IHttpNameValueHeaderValueFactory<D>::CreateFromNameWithValue(hstring_view name, hstring_view value) const
{
    Windows::Web::Http::Headers::HttpNameValueHeaderValue nameValueHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpNameValueHeaderValueFactory)->abi_CreateFromNameWithValue(get_abi(name), get_abi(value), put_abi(nameValueHeaderValue)));
    return nameValueHeaderValue;
}

template <typename D> hstring impl_IHttpNameValueHeaderValue<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHttpNameValueHeaderValue)->get_Name(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IHttpNameValueHeaderValue<D>::Value() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHttpNameValueHeaderValue)->get_Value(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpNameValueHeaderValue<D>::Value(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IHttpNameValueHeaderValue)->put_Value(get_abi(value)));
}

template <typename D> Windows::Web::Http::Headers::HttpProductHeaderValue impl_IHttpProductHeaderValueStatics<D>::Parse(hstring_view input) const
{
    Windows::Web::Http::Headers::HttpProductHeaderValue productHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpProductHeaderValueStatics)->abi_Parse(get_abi(input), put_abi(productHeaderValue)));
    return productHeaderValue;
}

template <typename D> bool impl_IHttpProductHeaderValueStatics<D>::TryParse(hstring_view input, Windows::Web::Http::Headers::HttpProductHeaderValue & productHeaderValue) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IHttpProductHeaderValueStatics)->abi_TryParse(get_abi(input), put_abi(productHeaderValue), &succeeded));
    return succeeded;
}

template <typename D> Windows::Web::Http::Headers::HttpProductHeaderValue impl_IHttpProductHeaderValueFactory<D>::CreateFromName(hstring_view productName) const
{
    Windows::Web::Http::Headers::HttpProductHeaderValue productHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpProductHeaderValueFactory)->abi_CreateFromName(get_abi(productName), put_abi(productHeaderValue)));
    return productHeaderValue;
}

template <typename D> Windows::Web::Http::Headers::HttpProductHeaderValue impl_IHttpProductHeaderValueFactory<D>::CreateFromNameWithVersion(hstring_view productName, hstring_view productVersion) const
{
    Windows::Web::Http::Headers::HttpProductHeaderValue productHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpProductHeaderValueFactory)->abi_CreateFromNameWithVersion(get_abi(productName), get_abi(productVersion), put_abi(productHeaderValue)));
    return productHeaderValue;
}

template <typename D> hstring impl_IHttpProductHeaderValue<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHttpProductHeaderValue)->get_Name(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IHttpProductHeaderValue<D>::Version() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHttpProductHeaderValue)->get_Version(put_abi(value)));
    return value;
}

template <typename D> Windows::Web::Http::Headers::HttpProductInfoHeaderValue impl_IHttpProductInfoHeaderValueStatics<D>::Parse(hstring_view input) const
{
    Windows::Web::Http::Headers::HttpProductInfoHeaderValue productInfoHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpProductInfoHeaderValueStatics)->abi_Parse(get_abi(input), put_abi(productInfoHeaderValue)));
    return productInfoHeaderValue;
}

template <typename D> bool impl_IHttpProductInfoHeaderValueStatics<D>::TryParse(hstring_view input, Windows::Web::Http::Headers::HttpProductInfoHeaderValue & productInfoHeaderValue) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IHttpProductInfoHeaderValueStatics)->abi_TryParse(get_abi(input), put_abi(productInfoHeaderValue), &succeeded));
    return succeeded;
}

template <typename D> Windows::Web::Http::Headers::HttpProductInfoHeaderValue impl_IHttpProductInfoHeaderValueFactory<D>::CreateFromComment(hstring_view productComment) const
{
    Windows::Web::Http::Headers::HttpProductInfoHeaderValue productInfoHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpProductInfoHeaderValueFactory)->abi_CreateFromComment(get_abi(productComment), put_abi(productInfoHeaderValue)));
    return productInfoHeaderValue;
}

template <typename D> Windows::Web::Http::Headers::HttpProductInfoHeaderValue impl_IHttpProductInfoHeaderValueFactory<D>::CreateFromNameWithVersion(hstring_view productName, hstring_view productVersion) const
{
    Windows::Web::Http::Headers::HttpProductInfoHeaderValue productInfoHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpProductInfoHeaderValueFactory)->abi_CreateFromNameWithVersion(get_abi(productName), get_abi(productVersion), put_abi(productInfoHeaderValue)));
    return productInfoHeaderValue;
}

template <typename D> Windows::Web::Http::Headers::HttpProductHeaderValue impl_IHttpProductInfoHeaderValue<D>::Product() const
{
    Windows::Web::Http::Headers::HttpProductHeaderValue value { nullptr };
    check_hresult(WINRT_SHIM(IHttpProductInfoHeaderValue)->get_Product(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IHttpProductInfoHeaderValue<D>::Comment() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHttpProductInfoHeaderValue)->get_Comment(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpProductInfoHeaderValueCollection<D>::ParseAdd(hstring_view input) const
{
    check_hresult(WINRT_SHIM(IHttpProductInfoHeaderValueCollection)->abi_ParseAdd(get_abi(input)));
}

template <typename D> bool impl_IHttpProductInfoHeaderValueCollection<D>::TryParseAdd(hstring_view input) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IHttpProductInfoHeaderValueCollection)->abi_TryParseAdd(get_abi(input), &succeeded));
    return succeeded;
}

template <typename D> Windows::Web::Http::Headers::HttpContentCodingWithQualityHeaderValue impl_IHttpContentCodingWithQualityHeaderValueStatics<D>::Parse(hstring_view input) const
{
    Windows::Web::Http::Headers::HttpContentCodingWithQualityHeaderValue contentCodingWithQualityHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpContentCodingWithQualityHeaderValueStatics)->abi_Parse(get_abi(input), put_abi(contentCodingWithQualityHeaderValue)));
    return contentCodingWithQualityHeaderValue;
}

template <typename D> bool impl_IHttpContentCodingWithQualityHeaderValueStatics<D>::TryParse(hstring_view input, Windows::Web::Http::Headers::HttpContentCodingWithQualityHeaderValue & contentCodingWithQualityHeaderValue) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IHttpContentCodingWithQualityHeaderValueStatics)->abi_TryParse(get_abi(input), put_abi(contentCodingWithQualityHeaderValue), &succeeded));
    return succeeded;
}

template <typename D> Windows::Web::Http::Headers::HttpContentCodingWithQualityHeaderValue impl_IHttpContentCodingWithQualityHeaderValueFactory<D>::CreateFromValue(hstring_view contentCoding) const
{
    Windows::Web::Http::Headers::HttpContentCodingWithQualityHeaderValue contentCodingWithQualityHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpContentCodingWithQualityHeaderValueFactory)->abi_CreateFromValue(get_abi(contentCoding), put_abi(contentCodingWithQualityHeaderValue)));
    return contentCodingWithQualityHeaderValue;
}

template <typename D> Windows::Web::Http::Headers::HttpContentCodingWithQualityHeaderValue impl_IHttpContentCodingWithQualityHeaderValueFactory<D>::CreateFromValueWithQuality(hstring_view contentCoding, double quality) const
{
    Windows::Web::Http::Headers::HttpContentCodingWithQualityHeaderValue contentCodingWithQualityHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpContentCodingWithQualityHeaderValueFactory)->abi_CreateFromValueWithQuality(get_abi(contentCoding), quality, put_abi(contentCodingWithQualityHeaderValue)));
    return contentCodingWithQualityHeaderValue;
}

template <typename D> hstring impl_IHttpContentCodingWithQualityHeaderValue<D>::ContentCoding() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHttpContentCodingWithQualityHeaderValue)->get_ContentCoding(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<double> impl_IHttpContentCodingWithQualityHeaderValue<D>::Quality() const
{
    Windows::Foundation::IReference<double> value;
    check_hresult(WINRT_SHIM(IHttpContentCodingWithQualityHeaderValue)->get_Quality(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpContentCodingWithQualityHeaderValueCollection<D>::ParseAdd(hstring_view input) const
{
    check_hresult(WINRT_SHIM(IHttpContentCodingWithQualityHeaderValueCollection)->abi_ParseAdd(get_abi(input)));
}

template <typename D> bool impl_IHttpContentCodingWithQualityHeaderValueCollection<D>::TryParseAdd(hstring_view input) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IHttpContentCodingWithQualityHeaderValueCollection)->abi_TryParseAdd(get_abi(input), &succeeded));
    return succeeded;
}

template <typename D> Windows::Web::Http::Headers::HttpTransferCodingHeaderValue impl_IHttpTransferCodingHeaderValueStatics<D>::Parse(hstring_view input) const
{
    Windows::Web::Http::Headers::HttpTransferCodingHeaderValue transferCodingHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpTransferCodingHeaderValueStatics)->abi_Parse(get_abi(input), put_abi(transferCodingHeaderValue)));
    return transferCodingHeaderValue;
}

template <typename D> bool impl_IHttpTransferCodingHeaderValueStatics<D>::TryParse(hstring_view input, Windows::Web::Http::Headers::HttpTransferCodingHeaderValue & transferCodingHeaderValue) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IHttpTransferCodingHeaderValueStatics)->abi_TryParse(get_abi(input), put_abi(transferCodingHeaderValue), &succeeded));
    return succeeded;
}

template <typename D> Windows::Web::Http::Headers::HttpTransferCodingHeaderValue impl_IHttpTransferCodingHeaderValueFactory<D>::Create(hstring_view input) const
{
    Windows::Web::Http::Headers::HttpTransferCodingHeaderValue transferCodingHeaderValue { nullptr };
    check_hresult(WINRT_SHIM(IHttpTransferCodingHeaderValueFactory)->abi_Create(get_abi(input), put_abi(transferCodingHeaderValue)));
    return transferCodingHeaderValue;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Web::Http::Headers::HttpNameValueHeaderValue> impl_IHttpTransferCodingHeaderValue<D>::Parameters() const
{
    Windows::Foundation::Collections::IVector<Windows::Web::Http::Headers::HttpNameValueHeaderValue> value;
    check_hresult(WINRT_SHIM(IHttpTransferCodingHeaderValue)->get_Parameters(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IHttpTransferCodingHeaderValue<D>::Value() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHttpTransferCodingHeaderValue)->get_Value(put_abi(value)));
    return value;
}

template <typename D> void impl_IHttpTransferCodingHeaderValueCollection<D>::ParseAdd(hstring_view input) const
{
    check_hresult(WINRT_SHIM(IHttpTransferCodingHeaderValueCollection)->abi_ParseAdd(get_abi(input)));
}

template <typename D> bool impl_IHttpTransferCodingHeaderValueCollection<D>::TryParseAdd(hstring_view input) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IHttpTransferCodingHeaderValueCollection)->abi_TryParseAdd(get_abi(input), &succeeded));
    return succeeded;
}

inline HttpChallengeHeaderValue::HttpChallengeHeaderValue(hstring_view scheme) :
    HttpChallengeHeaderValue(get_activation_factory<HttpChallengeHeaderValue, IHttpChallengeHeaderValueFactory>().CreateFromScheme(scheme))
{}

inline HttpChallengeHeaderValue::HttpChallengeHeaderValue(hstring_view scheme, hstring_view token) :
    HttpChallengeHeaderValue(get_activation_factory<HttpChallengeHeaderValue, IHttpChallengeHeaderValueFactory>().CreateFromSchemeWithToken(scheme, token))
{}

inline Windows::Web::Http::Headers::HttpChallengeHeaderValue HttpChallengeHeaderValue::Parse(hstring_view input)
{
    return get_activation_factory<HttpChallengeHeaderValue, IHttpChallengeHeaderValueStatics>().Parse(input);
}

inline bool HttpChallengeHeaderValue::TryParse(hstring_view input, Windows::Web::Http::Headers::HttpChallengeHeaderValue & challengeHeaderValue)
{
    return get_activation_factory<HttpChallengeHeaderValue, IHttpChallengeHeaderValueStatics>().TryParse(input, challengeHeaderValue);
}

inline HttpConnectionOptionHeaderValue::HttpConnectionOptionHeaderValue(hstring_view token) :
    HttpConnectionOptionHeaderValue(get_activation_factory<HttpConnectionOptionHeaderValue, IHttpConnectionOptionHeaderValueFactory>().Create(token))
{}

inline Windows::Web::Http::Headers::HttpConnectionOptionHeaderValue HttpConnectionOptionHeaderValue::Parse(hstring_view input)
{
    return get_activation_factory<HttpConnectionOptionHeaderValue, IHttpConnectionOptionHeaderValueStatics>().Parse(input);
}

inline bool HttpConnectionOptionHeaderValue::TryParse(hstring_view input, Windows::Web::Http::Headers::HttpConnectionOptionHeaderValue & connectionOptionHeaderValue)
{
    return get_activation_factory<HttpConnectionOptionHeaderValue, IHttpConnectionOptionHeaderValueStatics>().TryParse(input, connectionOptionHeaderValue);
}

inline HttpContentCodingHeaderValue::HttpContentCodingHeaderValue(hstring_view contentCoding) :
    HttpContentCodingHeaderValue(get_activation_factory<HttpContentCodingHeaderValue, IHttpContentCodingHeaderValueFactory>().Create(contentCoding))
{}

inline Windows::Web::Http::Headers::HttpContentCodingHeaderValue HttpContentCodingHeaderValue::Parse(hstring_view input)
{
    return get_activation_factory<HttpContentCodingHeaderValue, IHttpContentCodingHeaderValueStatics>().Parse(input);
}

inline bool HttpContentCodingHeaderValue::TryParse(hstring_view input, Windows::Web::Http::Headers::HttpContentCodingHeaderValue & contentCodingHeaderValue)
{
    return get_activation_factory<HttpContentCodingHeaderValue, IHttpContentCodingHeaderValueStatics>().TryParse(input, contentCodingHeaderValue);
}

inline HttpContentCodingWithQualityHeaderValue::HttpContentCodingWithQualityHeaderValue(hstring_view contentCoding) :
    HttpContentCodingWithQualityHeaderValue(get_activation_factory<HttpContentCodingWithQualityHeaderValue, IHttpContentCodingWithQualityHeaderValueFactory>().CreateFromValue(contentCoding))
{}

inline HttpContentCodingWithQualityHeaderValue::HttpContentCodingWithQualityHeaderValue(hstring_view contentCoding, double quality) :
    HttpContentCodingWithQualityHeaderValue(get_activation_factory<HttpContentCodingWithQualityHeaderValue, IHttpContentCodingWithQualityHeaderValueFactory>().CreateFromValueWithQuality(contentCoding, quality))
{}

inline Windows::Web::Http::Headers::HttpContentCodingWithQualityHeaderValue HttpContentCodingWithQualityHeaderValue::Parse(hstring_view input)
{
    return get_activation_factory<HttpContentCodingWithQualityHeaderValue, IHttpContentCodingWithQualityHeaderValueStatics>().Parse(input);
}

inline bool HttpContentCodingWithQualityHeaderValue::TryParse(hstring_view input, Windows::Web::Http::Headers::HttpContentCodingWithQualityHeaderValue & contentCodingWithQualityHeaderValue)
{
    return get_activation_factory<HttpContentCodingWithQualityHeaderValue, IHttpContentCodingWithQualityHeaderValueStatics>().TryParse(input, contentCodingWithQualityHeaderValue);
}

inline HttpContentDispositionHeaderValue::HttpContentDispositionHeaderValue(hstring_view dispositionType) :
    HttpContentDispositionHeaderValue(get_activation_factory<HttpContentDispositionHeaderValue, IHttpContentDispositionHeaderValueFactory>().Create(dispositionType))
{}

inline Windows::Web::Http::Headers::HttpContentDispositionHeaderValue HttpContentDispositionHeaderValue::Parse(hstring_view input)
{
    return get_activation_factory<HttpContentDispositionHeaderValue, IHttpContentDispositionHeaderValueStatics>().Parse(input);
}

inline bool HttpContentDispositionHeaderValue::TryParse(hstring_view input, Windows::Web::Http::Headers::HttpContentDispositionHeaderValue & contentDispositionHeaderValue)
{
    return get_activation_factory<HttpContentDispositionHeaderValue, IHttpContentDispositionHeaderValueStatics>().TryParse(input, contentDispositionHeaderValue);
}

inline HttpContentHeaderCollection::HttpContentHeaderCollection() :
    HttpContentHeaderCollection(activate_instance<HttpContentHeaderCollection>())
{}

inline HttpContentRangeHeaderValue::HttpContentRangeHeaderValue(uint64_t length) :
    HttpContentRangeHeaderValue(get_activation_factory<HttpContentRangeHeaderValue, IHttpContentRangeHeaderValueFactory>().CreateFromLength(length))
{}

inline HttpContentRangeHeaderValue::HttpContentRangeHeaderValue(uint64_t from, uint64_t to) :
    HttpContentRangeHeaderValue(get_activation_factory<HttpContentRangeHeaderValue, IHttpContentRangeHeaderValueFactory>().CreateFromRange(from, to))
{}

inline HttpContentRangeHeaderValue::HttpContentRangeHeaderValue(uint64_t from, uint64_t to, uint64_t length) :
    HttpContentRangeHeaderValue(get_activation_factory<HttpContentRangeHeaderValue, IHttpContentRangeHeaderValueFactory>().CreateFromRangeWithLength(from, to, length))
{}

inline Windows::Web::Http::Headers::HttpContentRangeHeaderValue HttpContentRangeHeaderValue::Parse(hstring_view input)
{
    return get_activation_factory<HttpContentRangeHeaderValue, IHttpContentRangeHeaderValueStatics>().Parse(input);
}

inline bool HttpContentRangeHeaderValue::TryParse(hstring_view input, Windows::Web::Http::Headers::HttpContentRangeHeaderValue & contentRangeHeaderValue)
{
    return get_activation_factory<HttpContentRangeHeaderValue, IHttpContentRangeHeaderValueStatics>().TryParse(input, contentRangeHeaderValue);
}

inline HttpCookiePairHeaderValue::HttpCookiePairHeaderValue(hstring_view name) :
    HttpCookiePairHeaderValue(get_activation_factory<HttpCookiePairHeaderValue, IHttpCookiePairHeaderValueFactory>().CreateFromName(name))
{}

inline HttpCookiePairHeaderValue::HttpCookiePairHeaderValue(hstring_view name, hstring_view value) :
    HttpCookiePairHeaderValue(get_activation_factory<HttpCookiePairHeaderValue, IHttpCookiePairHeaderValueFactory>().CreateFromNameWithValue(name, value))
{}

inline Windows::Web::Http::Headers::HttpCookiePairHeaderValue HttpCookiePairHeaderValue::Parse(hstring_view input)
{
    return get_activation_factory<HttpCookiePairHeaderValue, IHttpCookiePairHeaderValueStatics>().Parse(input);
}

inline bool HttpCookiePairHeaderValue::TryParse(hstring_view input, Windows::Web::Http::Headers::HttpCookiePairHeaderValue & cookiePairHeaderValue)
{
    return get_activation_factory<HttpCookiePairHeaderValue, IHttpCookiePairHeaderValueStatics>().TryParse(input, cookiePairHeaderValue);
}

inline HttpCredentialsHeaderValue::HttpCredentialsHeaderValue(hstring_view scheme) :
    HttpCredentialsHeaderValue(get_activation_factory<HttpCredentialsHeaderValue, IHttpCredentialsHeaderValueFactory>().CreateFromScheme(scheme))
{}

inline HttpCredentialsHeaderValue::HttpCredentialsHeaderValue(hstring_view scheme, hstring_view token) :
    HttpCredentialsHeaderValue(get_activation_factory<HttpCredentialsHeaderValue, IHttpCredentialsHeaderValueFactory>().CreateFromSchemeWithToken(scheme, token))
{}

inline Windows::Web::Http::Headers::HttpCredentialsHeaderValue HttpCredentialsHeaderValue::Parse(hstring_view input)
{
    return get_activation_factory<HttpCredentialsHeaderValue, IHttpCredentialsHeaderValueStatics>().Parse(input);
}

inline bool HttpCredentialsHeaderValue::TryParse(hstring_view input, Windows::Web::Http::Headers::HttpCredentialsHeaderValue & credentialsHeaderValue)
{
    return get_activation_factory<HttpCredentialsHeaderValue, IHttpCredentialsHeaderValueStatics>().TryParse(input, credentialsHeaderValue);
}

inline Windows::Web::Http::Headers::HttpDateOrDeltaHeaderValue HttpDateOrDeltaHeaderValue::Parse(hstring_view input)
{
    return get_activation_factory<HttpDateOrDeltaHeaderValue, IHttpDateOrDeltaHeaderValueStatics>().Parse(input);
}

inline bool HttpDateOrDeltaHeaderValue::TryParse(hstring_view input, Windows::Web::Http::Headers::HttpDateOrDeltaHeaderValue & dateOrDeltaHeaderValue)
{
    return get_activation_factory<HttpDateOrDeltaHeaderValue, IHttpDateOrDeltaHeaderValueStatics>().TryParse(input, dateOrDeltaHeaderValue);
}

inline HttpExpectationHeaderValue::HttpExpectationHeaderValue(hstring_view name) :
    HttpExpectationHeaderValue(get_activation_factory<HttpExpectationHeaderValue, IHttpExpectationHeaderValueFactory>().CreateFromName(name))
{}

inline HttpExpectationHeaderValue::HttpExpectationHeaderValue(hstring_view name, hstring_view value) :
    HttpExpectationHeaderValue(get_activation_factory<HttpExpectationHeaderValue, IHttpExpectationHeaderValueFactory>().CreateFromNameWithValue(name, value))
{}

inline Windows::Web::Http::Headers::HttpExpectationHeaderValue HttpExpectationHeaderValue::Parse(hstring_view input)
{
    return get_activation_factory<HttpExpectationHeaderValue, IHttpExpectationHeaderValueStatics>().Parse(input);
}

inline bool HttpExpectationHeaderValue::TryParse(hstring_view input, Windows::Web::Http::Headers::HttpExpectationHeaderValue & expectationHeaderValue)
{
    return get_activation_factory<HttpExpectationHeaderValue, IHttpExpectationHeaderValueStatics>().TryParse(input, expectationHeaderValue);
}

inline HttpLanguageRangeWithQualityHeaderValue::HttpLanguageRangeWithQualityHeaderValue(hstring_view languageRange) :
    HttpLanguageRangeWithQualityHeaderValue(get_activation_factory<HttpLanguageRangeWithQualityHeaderValue, IHttpLanguageRangeWithQualityHeaderValueFactory>().CreateFromLanguageRange(languageRange))
{}

inline HttpLanguageRangeWithQualityHeaderValue::HttpLanguageRangeWithQualityHeaderValue(hstring_view languageRange, double quality) :
    HttpLanguageRangeWithQualityHeaderValue(get_activation_factory<HttpLanguageRangeWithQualityHeaderValue, IHttpLanguageRangeWithQualityHeaderValueFactory>().CreateFromLanguageRangeWithQuality(languageRange, quality))
{}

inline Windows::Web::Http::Headers::HttpLanguageRangeWithQualityHeaderValue HttpLanguageRangeWithQualityHeaderValue::Parse(hstring_view input)
{
    return get_activation_factory<HttpLanguageRangeWithQualityHeaderValue, IHttpLanguageRangeWithQualityHeaderValueStatics>().Parse(input);
}

inline bool HttpLanguageRangeWithQualityHeaderValue::TryParse(hstring_view input, Windows::Web::Http::Headers::HttpLanguageRangeWithQualityHeaderValue & languageRangeWithQualityHeaderValue)
{
    return get_activation_factory<HttpLanguageRangeWithQualityHeaderValue, IHttpLanguageRangeWithQualityHeaderValueStatics>().TryParse(input, languageRangeWithQualityHeaderValue);
}

inline HttpMediaTypeHeaderValue::HttpMediaTypeHeaderValue(hstring_view mediaType) :
    HttpMediaTypeHeaderValue(get_activation_factory<HttpMediaTypeHeaderValue, IHttpMediaTypeHeaderValueFactory>().Create(mediaType))
{}

inline Windows::Web::Http::Headers::HttpMediaTypeHeaderValue HttpMediaTypeHeaderValue::Parse(hstring_view input)
{
    return get_activation_factory<HttpMediaTypeHeaderValue, IHttpMediaTypeHeaderValueStatics>().Parse(input);
}

inline bool HttpMediaTypeHeaderValue::TryParse(hstring_view input, Windows::Web::Http::Headers::HttpMediaTypeHeaderValue & mediaTypeHeaderValue)
{
    return get_activation_factory<HttpMediaTypeHeaderValue, IHttpMediaTypeHeaderValueStatics>().TryParse(input, mediaTypeHeaderValue);
}

inline HttpMediaTypeWithQualityHeaderValue::HttpMediaTypeWithQualityHeaderValue(hstring_view mediaType) :
    HttpMediaTypeWithQualityHeaderValue(get_activation_factory<HttpMediaTypeWithQualityHeaderValue, IHttpMediaTypeWithQualityHeaderValueFactory>().CreateFromMediaType(mediaType))
{}

inline HttpMediaTypeWithQualityHeaderValue::HttpMediaTypeWithQualityHeaderValue(hstring_view mediaType, double quality) :
    HttpMediaTypeWithQualityHeaderValue(get_activation_factory<HttpMediaTypeWithQualityHeaderValue, IHttpMediaTypeWithQualityHeaderValueFactory>().CreateFromMediaTypeWithQuality(mediaType, quality))
{}

inline Windows::Web::Http::Headers::HttpMediaTypeWithQualityHeaderValue HttpMediaTypeWithQualityHeaderValue::Parse(hstring_view input)
{
    return get_activation_factory<HttpMediaTypeWithQualityHeaderValue, IHttpMediaTypeWithQualityHeaderValueStatics>().Parse(input);
}

inline bool HttpMediaTypeWithQualityHeaderValue::TryParse(hstring_view input, Windows::Web::Http::Headers::HttpMediaTypeWithQualityHeaderValue & mediaTypeWithQualityHeaderValue)
{
    return get_activation_factory<HttpMediaTypeWithQualityHeaderValue, IHttpMediaTypeWithQualityHeaderValueStatics>().TryParse(input, mediaTypeWithQualityHeaderValue);
}

inline HttpNameValueHeaderValue::HttpNameValueHeaderValue(hstring_view name) :
    HttpNameValueHeaderValue(get_activation_factory<HttpNameValueHeaderValue, IHttpNameValueHeaderValueFactory>().CreateFromName(name))
{}

inline HttpNameValueHeaderValue::HttpNameValueHeaderValue(hstring_view name, hstring_view value) :
    HttpNameValueHeaderValue(get_activation_factory<HttpNameValueHeaderValue, IHttpNameValueHeaderValueFactory>().CreateFromNameWithValue(name, value))
{}

inline Windows::Web::Http::Headers::HttpNameValueHeaderValue HttpNameValueHeaderValue::Parse(hstring_view input)
{
    return get_activation_factory<HttpNameValueHeaderValue, IHttpNameValueHeaderValueStatics>().Parse(input);
}

inline bool HttpNameValueHeaderValue::TryParse(hstring_view input, Windows::Web::Http::Headers::HttpNameValueHeaderValue & nameValueHeaderValue)
{
    return get_activation_factory<HttpNameValueHeaderValue, IHttpNameValueHeaderValueStatics>().TryParse(input, nameValueHeaderValue);
}

inline HttpProductHeaderValue::HttpProductHeaderValue(hstring_view productName) :
    HttpProductHeaderValue(get_activation_factory<HttpProductHeaderValue, IHttpProductHeaderValueFactory>().CreateFromName(productName))
{}

inline HttpProductHeaderValue::HttpProductHeaderValue(hstring_view productName, hstring_view productVersion) :
    HttpProductHeaderValue(get_activation_factory<HttpProductHeaderValue, IHttpProductHeaderValueFactory>().CreateFromNameWithVersion(productName, productVersion))
{}

inline Windows::Web::Http::Headers::HttpProductHeaderValue HttpProductHeaderValue::Parse(hstring_view input)
{
    return get_activation_factory<HttpProductHeaderValue, IHttpProductHeaderValueStatics>().Parse(input);
}

inline bool HttpProductHeaderValue::TryParse(hstring_view input, Windows::Web::Http::Headers::HttpProductHeaderValue & productHeaderValue)
{
    return get_activation_factory<HttpProductHeaderValue, IHttpProductHeaderValueStatics>().TryParse(input, productHeaderValue);
}

inline HttpProductInfoHeaderValue::HttpProductInfoHeaderValue(hstring_view productComment) :
    HttpProductInfoHeaderValue(get_activation_factory<HttpProductInfoHeaderValue, IHttpProductInfoHeaderValueFactory>().CreateFromComment(productComment))
{}

inline HttpProductInfoHeaderValue::HttpProductInfoHeaderValue(hstring_view productName, hstring_view productVersion) :
    HttpProductInfoHeaderValue(get_activation_factory<HttpProductInfoHeaderValue, IHttpProductInfoHeaderValueFactory>().CreateFromNameWithVersion(productName, productVersion))
{}

inline Windows::Web::Http::Headers::HttpProductInfoHeaderValue HttpProductInfoHeaderValue::Parse(hstring_view input)
{
    return get_activation_factory<HttpProductInfoHeaderValue, IHttpProductInfoHeaderValueStatics>().Parse(input);
}

inline bool HttpProductInfoHeaderValue::TryParse(hstring_view input, Windows::Web::Http::Headers::HttpProductInfoHeaderValue & productInfoHeaderValue)
{
    return get_activation_factory<HttpProductInfoHeaderValue, IHttpProductInfoHeaderValueStatics>().TryParse(input, productInfoHeaderValue);
}

inline HttpTransferCodingHeaderValue::HttpTransferCodingHeaderValue(hstring_view input) :
    HttpTransferCodingHeaderValue(get_activation_factory<HttpTransferCodingHeaderValue, IHttpTransferCodingHeaderValueFactory>().Create(input))
{}

inline Windows::Web::Http::Headers::HttpTransferCodingHeaderValue HttpTransferCodingHeaderValue::Parse(hstring_view input)
{
    return get_activation_factory<HttpTransferCodingHeaderValue, IHttpTransferCodingHeaderValueStatics>().Parse(input);
}

inline bool HttpTransferCodingHeaderValue::TryParse(hstring_view input, Windows::Web::Http::Headers::HttpTransferCodingHeaderValue & transferCodingHeaderValue)
{
    return get_activation_factory<HttpTransferCodingHeaderValue, IHttpTransferCodingHeaderValueStatics>().TryParse(input, transferCodingHeaderValue);
}

}

}
#pragma warning(pop)
