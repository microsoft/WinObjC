// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Web.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Storage.Streams.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Web {

struct __declspec(uuid("b0aba86a-9aeb-4d3a-9590-003e3ca7e290")) __declspec(novtable) IUriToStreamResolver : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_UriToStreamAsync(Windows::Foundation::IUriRuntimeClass * uri, Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IInputStream> ** operation) = 0;
};

struct __declspec(uuid("fe616766-bf27-4064-87b7-6563bb11ce2e")) __declspec(novtable) IWebErrorStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetStatus(int32_t hresult, winrt::Windows::Web::WebErrorStatus * status) = 0;
};

}

namespace ABI {


}

namespace Windows::Web {

template <typename D>
struct WINRT_EBO impl_IUriToStreamResolver
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IInputStream> UriToStreamAsync(const Windows::Foundation::Uri & uri) const;
};

template <typename D>
struct WINRT_EBO impl_IWebErrorStatics
{
    Windows::Web::WebErrorStatus GetStatus(int32_t hresult) const;
};

}

namespace impl {

template <> struct traits<Windows::Web::IUriToStreamResolver>
{
    using abi = ABI::Windows::Web::IUriToStreamResolver;
    template <typename D> using consume = Windows::Web::impl_IUriToStreamResolver<D>;
};

template <> struct traits<Windows::Web::IWebErrorStatics>
{
    using abi = ABI::Windows::Web::IWebErrorStatics;
    template <typename D> using consume = Windows::Web::impl_IWebErrorStatics<D>;
};

template <> struct traits<Windows::Web::WebError>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.WebError"; }
};

}

}
