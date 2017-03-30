// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Foundation.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Foundation {

template <typename H> struct impl_DeferralCompletedHandler : implements<impl_DeferralCompletedHandler<H>, abi<DeferralCompletedHandler>>, H
{
    impl_DeferralCompletedHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke() noexcept override
    {
        try
        {
            (*this)();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Foundation {

struct WINRT_EBO Deferral :
    Windows::Foundation::IDeferral
{
    Deferral(std::nullptr_t) noexcept {}
    Deferral(const Windows::Foundation::DeferralCompletedHandler & handler);
};

struct WINRT_EBO MemoryBuffer :
    Windows::Foundation::IMemoryBuffer
{
    MemoryBuffer(std::nullptr_t) noexcept {}
    MemoryBuffer(uint32_t capacity);
};

struct WINRT_EBO Uri :
    Windows::Foundation::IUriRuntimeClass,
    impl::require<Uri, Windows::Foundation::IStringable, Windows::Foundation::IUriRuntimeClassWithAbsoluteCanonicalUri>
{
    Uri(std::nullptr_t) noexcept {}
    Uri(hstring_view uri);
    Uri(hstring_view baseUri, hstring_view relativeUri);
    static hstring UnescapeComponent(hstring_view toUnescape);
    static hstring EscapeComponent(hstring_view toEscape);
};

struct WINRT_EBO WwwFormUrlDecoder :
    Windows::Foundation::IWwwFormUrlDecoderRuntimeClass
{
    WwwFormUrlDecoder(std::nullptr_t) noexcept {}
    WwwFormUrlDecoder(hstring_view query);
};

struct WINRT_EBO WwwFormUrlDecoderEntry :
    Windows::Foundation::IWwwFormUrlDecoderEntry
{
    WwwFormUrlDecoderEntry(std::nullptr_t) noexcept {}
};

}

}
