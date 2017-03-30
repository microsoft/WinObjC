// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Foundation.0.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

struct __declspec(uuid("ed32a372-f3c8-4faa-9cfb-470148da3888")) __declspec(novtable) DeferralCompletedHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke() = 0;
};

struct __declspec(uuid("30d5a829-7fa4-4026-83bb-d75bae4ea99e")) __declspec(novtable) IClosable : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Close() = 0;
};

struct __declspec(uuid("d6269732-3b7f-46a7-b40b-4fdca2a2c693")) __declspec(novtable) IDeferral : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Complete() = 0;
};

struct __declspec(uuid("65a1ecc5-3fb5-4832-8ca9-f061b281d13a")) __declspec(novtable) IDeferralFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Foundation::DeferralCompletedHandler * handler, Windows::Foundation::IDeferral ** result) = 0;
};

struct __declspec(uuid("4edb8ee2-96dd-49a7-94f7-4607ddab8e3c")) __declspec(novtable) IGetActivationFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetActivationFactory(hstring activatableClassId, Windows::Foundation::IInspectable ** factory) = 0;
};

struct __declspec(uuid("fbc4dd2a-245b-11e4-af98-689423260cf8")) __declspec(novtable) IMemoryBuffer : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateReference(Windows::Foundation::IMemoryBufferReference ** reference) = 0;
};

struct __declspec(uuid("fbc4dd2b-245b-11e4-af98-689423260cf8")) __declspec(novtable) IMemoryBufferFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(uint32_t capacity, Windows::Foundation::IMemoryBuffer ** value) = 0;
};

struct __declspec(uuid("fbc4dd29-245b-11e4-af98-689423260cf8")) __declspec(novtable) IMemoryBufferReference : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Capacity(uint32_t * value) = 0;
    virtual HRESULT __stdcall add_Closed(Windows::Foundation::TypedEventHandler<Windows::Foundation::IMemoryBufferReference, Windows::Foundation::IInspectable> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_Closed(event_token cookie) = 0;
};

struct __declspec(uuid("96369f54-8eb6-48f0-abce-c1b211e627c3")) __declspec(novtable) IStringable : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ToString(hstring * value) = 0;
};

struct __declspec(uuid("c1d432ba-c824-4452-a7fd-512bc3bbe9a1")) __declspec(novtable) IUriEscapeStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_UnescapeComponent(hstring toUnescape, hstring * value) = 0;
    virtual HRESULT __stdcall abi_EscapeComponent(hstring toEscape, hstring * value) = 0;
};

struct __declspec(uuid("9e365e57-48b2-4160-956f-c7385120bbfc")) __declspec(novtable) IUriRuntimeClass : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AbsoluteUri(hstring * value) = 0;
    virtual HRESULT __stdcall get_DisplayUri(hstring * value) = 0;
    virtual HRESULT __stdcall get_Domain(hstring * value) = 0;
    virtual HRESULT __stdcall get_Extension(hstring * value) = 0;
    virtual HRESULT __stdcall get_Fragment(hstring * value) = 0;
    virtual HRESULT __stdcall get_Host(hstring * value) = 0;
    virtual HRESULT __stdcall get_Password(hstring * value) = 0;
    virtual HRESULT __stdcall get_Path(hstring * value) = 0;
    virtual HRESULT __stdcall get_Query(hstring * value) = 0;
    virtual HRESULT __stdcall get_QueryParsed(Windows::Foundation::IWwwFormUrlDecoderRuntimeClass ** ppWwwFormUrlDecoder) = 0;
    virtual HRESULT __stdcall get_RawUri(hstring * value) = 0;
    virtual HRESULT __stdcall get_SchemeName(hstring * value) = 0;
    virtual HRESULT __stdcall get_UserName(hstring * value) = 0;
    virtual HRESULT __stdcall get_Port(int32_t * value) = 0;
    virtual HRESULT __stdcall get_Suspicious(bool * value) = 0;
    virtual HRESULT __stdcall abi_Equals(Windows::Foundation::IUriRuntimeClass * pUri, bool * value) = 0;
    virtual HRESULT __stdcall abi_CombineUri(hstring relativeUri, Windows::Foundation::IUriRuntimeClass ** instance) = 0;
};

struct __declspec(uuid("44a9796f-723e-4fdf-a218-033e75b0c084")) __declspec(novtable) IUriRuntimeClassFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateUri(hstring uri, Windows::Foundation::IUriRuntimeClass ** instance) = 0;
    virtual HRESULT __stdcall abi_CreateWithRelativeUri(hstring baseUri, hstring relativeUri, Windows::Foundation::IUriRuntimeClass ** instance) = 0;
};

struct __declspec(uuid("758d9661-221c-480f-a339-50656673f46f")) __declspec(novtable) IUriRuntimeClassWithAbsoluteCanonicalUri : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AbsoluteCanonicalUri(hstring * value) = 0;
    virtual HRESULT __stdcall get_DisplayIri(hstring * value) = 0;
};

struct __declspec(uuid("125e7431-f678-4e8e-b670-20a9b06c512d")) __declspec(novtable) IWwwFormUrlDecoderEntry : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall get_Value(hstring * value) = 0;
};

struct __declspec(uuid("d45a0451-f225-4542-9296-0e1df5d254df")) __declspec(novtable) IWwwFormUrlDecoderRuntimeClass : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetFirstValueByName(hstring name, hstring * phstrValue) = 0;
};

struct __declspec(uuid("5b8c6b3d-24ae-41b5-a1bf-f0c3d544845b")) __declspec(novtable) IWwwFormUrlDecoderRuntimeClassFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateWwwFormUrlDecoder(hstring query, Windows::Foundation::IWwwFormUrlDecoderRuntimeClass ** instance) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Foundation::Deferral> { using default_interface = Windows::Foundation::IDeferral; };
template <> struct traits<Windows::Foundation::MemoryBuffer> { using default_interface = Windows::Foundation::IMemoryBuffer; };
template <> struct traits<Windows::Foundation::Uri> { using default_interface = Windows::Foundation::IUriRuntimeClass; };
template <> struct traits<Windows::Foundation::WwwFormUrlDecoder> { using default_interface = Windows::Foundation::IWwwFormUrlDecoderRuntimeClass; };
template <> struct traits<Windows::Foundation::WwwFormUrlDecoderEntry> { using default_interface = Windows::Foundation::IWwwFormUrlDecoderEntry; };

}

namespace Windows::Foundation {

template <typename D>
struct WINRT_EBO impl_IClosable
{
    void Close() const;
};

template <typename D>
struct WINRT_EBO impl_IDeferral
{
    void Complete() const;
};

template <typename D>
struct WINRT_EBO impl_IDeferralFactory
{
    Windows::Foundation::Deferral Create(const Windows::Foundation::DeferralCompletedHandler & handler) const;
};

template <typename D>
struct WINRT_EBO impl_IGetActivationFactory
{
    Windows::Foundation::IInspectable GetActivationFactory(hstring_view activatableClassId) const;
};

template <typename D>
struct WINRT_EBO impl_IMemoryBuffer
{
    Windows::Foundation::IMemoryBufferReference CreateReference() const;
};

template <typename D>
struct WINRT_EBO impl_IMemoryBufferFactory
{
    Windows::Foundation::MemoryBuffer Create(uint32_t capacity) const;
};

template <typename D>
struct WINRT_EBO impl_IMemoryBufferReference
{
    uint32_t Capacity() const;
    event_token Closed(const Windows::Foundation::TypedEventHandler<Windows::Foundation::IMemoryBufferReference, Windows::Foundation::IInspectable> & handler) const;
    using Closed_revoker = event_revoker<IMemoryBufferReference>;
    Closed_revoker Closed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Foundation::IMemoryBufferReference, Windows::Foundation::IInspectable> & handler) const;
    void Closed(event_token cookie) const;
};

template <typename D>
struct WINRT_EBO impl_IStringable
{
    hstring ToString() const;
};

template <typename D>
struct WINRT_EBO impl_IUriEscapeStatics
{
    hstring UnescapeComponent(hstring_view toUnescape) const;
    hstring EscapeComponent(hstring_view toEscape) const;
};

template <typename D>
struct WINRT_EBO impl_IUriRuntimeClass
{
    hstring AbsoluteUri() const;
    hstring DisplayUri() const;
    hstring Domain() const;
    hstring Extension() const;
    hstring Fragment() const;
    hstring Host() const;
    hstring Password() const;
    hstring Path() const;
    hstring Query() const;
    Windows::Foundation::WwwFormUrlDecoder QueryParsed() const;
    hstring RawUri() const;
    hstring SchemeName() const;
    hstring UserName() const;
    int32_t Port() const;
    bool Suspicious() const;
    bool Equals(const Windows::Foundation::Uri & pUri) const;
    Windows::Foundation::Uri CombineUri(hstring_view relativeUri) const;
};

template <typename D>
struct WINRT_EBO impl_IUriRuntimeClassFactory
{
    Windows::Foundation::Uri CreateUri(hstring_view uri) const;
    Windows::Foundation::Uri CreateWithRelativeUri(hstring_view baseUri, hstring_view relativeUri) const;
};

template <typename D>
struct WINRT_EBO impl_IUriRuntimeClassWithAbsoluteCanonicalUri
{
    hstring AbsoluteCanonicalUri() const;
    hstring DisplayIri() const;
};

template <typename D>
struct WINRT_EBO impl_IWwwFormUrlDecoderEntry
{
    hstring Name() const;
    hstring Value() const;
};

template <typename D>
struct WINRT_EBO impl_IWwwFormUrlDecoderRuntimeClass
{
    hstring GetFirstValueByName(hstring_view name) const;
};

template <typename D>
struct WINRT_EBO impl_IWwwFormUrlDecoderRuntimeClassFactory
{
    Windows::Foundation::WwwFormUrlDecoder CreateWwwFormUrlDecoder(hstring_view query) const;
};

}

namespace impl {

template <> struct traits<Windows::Foundation::DeferralCompletedHandler>
{
    using abi = ABI::Windows::Foundation::DeferralCompletedHandler;
};

template <> struct traits<Windows::Foundation::IClosable>
{
    using abi = ABI::Windows::Foundation::IClosable;
    template <typename D> using consume = Windows::Foundation::impl_IClosable<D>;
};

template <> struct traits<Windows::Foundation::IDeferral>
{
    using abi = ABI::Windows::Foundation::IDeferral;
    template <typename D> using consume = Windows::Foundation::impl_IDeferral<D>;
};

template <> struct traits<Windows::Foundation::IDeferralFactory>
{
    using abi = ABI::Windows::Foundation::IDeferralFactory;
    template <typename D> using consume = Windows::Foundation::impl_IDeferralFactory<D>;
};

template <> struct traits<Windows::Foundation::IGetActivationFactory>
{
    using abi = ABI::Windows::Foundation::IGetActivationFactory;
    template <typename D> using consume = Windows::Foundation::impl_IGetActivationFactory<D>;
};

template <> struct traits<Windows::Foundation::IMemoryBuffer>
{
    using abi = ABI::Windows::Foundation::IMemoryBuffer;
    template <typename D> using consume = Windows::Foundation::impl_IMemoryBuffer<D>;
};

template <> struct traits<Windows::Foundation::IMemoryBufferFactory>
{
    using abi = ABI::Windows::Foundation::IMemoryBufferFactory;
    template <typename D> using consume = Windows::Foundation::impl_IMemoryBufferFactory<D>;
};

template <> struct traits<Windows::Foundation::IMemoryBufferReference>
{
    using abi = ABI::Windows::Foundation::IMemoryBufferReference;
    template <typename D> using consume = Windows::Foundation::impl_IMemoryBufferReference<D>;
};

template <> struct traits<Windows::Foundation::IStringable>
{
    using abi = ABI::Windows::Foundation::IStringable;
    template <typename D> using consume = Windows::Foundation::impl_IStringable<D>;
};

template <> struct traits<Windows::Foundation::IUriEscapeStatics>
{
    using abi = ABI::Windows::Foundation::IUriEscapeStatics;
    template <typename D> using consume = Windows::Foundation::impl_IUriEscapeStatics<D>;
};

template <> struct traits<Windows::Foundation::IUriRuntimeClass>
{
    using abi = ABI::Windows::Foundation::IUriRuntimeClass;
    template <typename D> using consume = Windows::Foundation::impl_IUriRuntimeClass<D>;
};

template <> struct traits<Windows::Foundation::IUriRuntimeClassFactory>
{
    using abi = ABI::Windows::Foundation::IUriRuntimeClassFactory;
    template <typename D> using consume = Windows::Foundation::impl_IUriRuntimeClassFactory<D>;
};

template <> struct traits<Windows::Foundation::IUriRuntimeClassWithAbsoluteCanonicalUri>
{
    using abi = ABI::Windows::Foundation::IUriRuntimeClassWithAbsoluteCanonicalUri;
    template <typename D> using consume = Windows::Foundation::impl_IUriRuntimeClassWithAbsoluteCanonicalUri<D>;
};

template <> struct traits<Windows::Foundation::IWwwFormUrlDecoderEntry>
{
    using abi = ABI::Windows::Foundation::IWwwFormUrlDecoderEntry;
    template <typename D> using consume = Windows::Foundation::impl_IWwwFormUrlDecoderEntry<D>;
};

template <> struct traits<Windows::Foundation::IWwwFormUrlDecoderRuntimeClass>
{
    using abi = ABI::Windows::Foundation::IWwwFormUrlDecoderRuntimeClass;
    template <typename D> using consume = Windows::Foundation::impl_IWwwFormUrlDecoderRuntimeClass<D>;
};

template <> struct traits<Windows::Foundation::IWwwFormUrlDecoderRuntimeClassFactory>
{
    using abi = ABI::Windows::Foundation::IWwwFormUrlDecoderRuntimeClassFactory;
    template <typename D> using consume = Windows::Foundation::impl_IWwwFormUrlDecoderRuntimeClassFactory<D>;
};

template <> struct traits<Windows::Foundation::Deferral>
{
    using abi = ABI::Windows::Foundation::Deferral;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Foundation.Deferral"; }
};

template <> struct traits<Windows::Foundation::MemoryBuffer>
{
    using abi = ABI::Windows::Foundation::MemoryBuffer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Foundation.MemoryBuffer"; }
};

template <> struct traits<Windows::Foundation::Uri>
{
    using abi = ABI::Windows::Foundation::Uri;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Foundation.Uri"; }
};

template <> struct traits<Windows::Foundation::WwwFormUrlDecoder>
{
    using abi = ABI::Windows::Foundation::WwwFormUrlDecoder;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Foundation.WwwFormUrlDecoder"; }
};

template <> struct traits<Windows::Foundation::WwwFormUrlDecoderEntry>
{
    using abi = ABI::Windows::Foundation::WwwFormUrlDecoderEntry;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Foundation.WwwFormUrlDecoderEntry"; }
};

}

}
