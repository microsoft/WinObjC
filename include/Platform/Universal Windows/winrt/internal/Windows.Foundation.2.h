// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_b1f00d3b_1f06_5117_93ea_2a0d79116701
#define WINRT_GENERIC_b1f00d3b_1f06_5117_93ea_2a0d79116701
template <> struct __declspec(uuid("b1f00d3b-1f06-5117-93ea-2a0d79116701")) __declspec(novtable) IVectorView<Windows::Foundation::IWwwFormUrlDecoderEntry> : impl_IVectorView<Windows::Foundation::IWwwFormUrlDecoderEntry> {};
#endif

#ifndef WINRT_GENERIC_876be83b_7218_5bfb_a169_83152ef7e146
#define WINRT_GENERIC_876be83b_7218_5bfb_a169_83152ef7e146
template <> struct __declspec(uuid("876be83b-7218-5bfb-a169-83152ef7e146")) __declspec(novtable) IIterable<Windows::Foundation::IWwwFormUrlDecoderEntry> : impl_IIterable<Windows::Foundation::IWwwFormUrlDecoderEntry> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_f4637d4a_0760_5431_bfc0_24eb1d4f6c4f
#define WINRT_GENERIC_f4637d4a_0760_5431_bfc0_24eb1d4f6c4f
template <> struct __declspec(uuid("f4637d4a-0760-5431-bfc0-24eb1d4f6c4f")) __declspec(novtable) TypedEventHandler<Windows::Foundation::IMemoryBufferReference, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::Foundation::IMemoryBufferReference, Windows::Foundation::IInspectable> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_32e54295_373c_50cb_80a1_468a990ca780
#define WINRT_GENERIC_32e54295_373c_50cb_80a1_468a990ca780
template <> struct __declspec(uuid("32e54295-373c-50cb-80a1-468a990ca780")) __declspec(novtable) IIterator<Windows::Foundation::IWwwFormUrlDecoderEntry> : impl_IIterator<Windows::Foundation::IWwwFormUrlDecoderEntry> {};
#endif


}

namespace Windows::Foundation {

struct DeferralCompletedHandler : Windows::Foundation::IUnknown
{
    DeferralCompletedHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> DeferralCompletedHandler(L lambda);
    template <typename F> DeferralCompletedHandler (F * function);
    template <typename O, typename M> DeferralCompletedHandler(O * object, M method);
    void operator()() const;
};

struct IClosable :
    Windows::Foundation::IInspectable,
    impl::consume<IClosable>
{
    IClosable(std::nullptr_t = nullptr) noexcept {}
};

struct IDeferral :
    Windows::Foundation::IInspectable,
    impl::consume<IDeferral>,
    impl::require<IDeferral, Windows::Foundation::IClosable>
{
    IDeferral(std::nullptr_t = nullptr) noexcept {}
};

struct IDeferralFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IDeferralFactory>
{
    IDeferralFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IGetActivationFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IGetActivationFactory>
{
    IGetActivationFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IMemoryBuffer :
    Windows::Foundation::IInspectable,
    impl::consume<IMemoryBuffer>,
    impl::require<IMemoryBuffer, Windows::Foundation::IClosable>
{
    IMemoryBuffer(std::nullptr_t = nullptr) noexcept {}
};

struct IMemoryBufferFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IMemoryBufferFactory>
{
    IMemoryBufferFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IMemoryBufferReference :
    Windows::Foundation::IInspectable,
    impl::consume<IMemoryBufferReference>,
    impl::require<IMemoryBufferReference, Windows::Foundation::IClosable>
{
    IMemoryBufferReference(std::nullptr_t = nullptr) noexcept {}
};

struct IStringable :
    Windows::Foundation::IInspectable,
    impl::consume<IStringable>
{
    IStringable(std::nullptr_t = nullptr) noexcept {}
};

struct IUriEscapeStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IUriEscapeStatics>
{
    IUriEscapeStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IUriRuntimeClass :
    Windows::Foundation::IInspectable,
    impl::consume<IUriRuntimeClass>
{
    IUriRuntimeClass(std::nullptr_t = nullptr) noexcept {}
};

struct IUriRuntimeClassFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IUriRuntimeClassFactory>
{
    IUriRuntimeClassFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IUriRuntimeClassWithAbsoluteCanonicalUri :
    Windows::Foundation::IInspectable,
    impl::consume<IUriRuntimeClassWithAbsoluteCanonicalUri>
{
    IUriRuntimeClassWithAbsoluteCanonicalUri(std::nullptr_t = nullptr) noexcept {}
};

struct IWwwFormUrlDecoderEntry :
    Windows::Foundation::IInspectable,
    impl::consume<IWwwFormUrlDecoderEntry>
{
    IWwwFormUrlDecoderEntry(std::nullptr_t = nullptr) noexcept {}
};

struct IWwwFormUrlDecoderRuntimeClass :
    Windows::Foundation::IInspectable,
    impl::consume<IWwwFormUrlDecoderRuntimeClass>,
    impl::require<IWwwFormUrlDecoderRuntimeClass, Windows::Foundation::Collections::IIterable<Windows::Foundation::IWwwFormUrlDecoderEntry>, Windows::Foundation::Collections::IVectorView<Windows::Foundation::IWwwFormUrlDecoderEntry>>
{
    IWwwFormUrlDecoderRuntimeClass(std::nullptr_t = nullptr) noexcept {}
};

struct IWwwFormUrlDecoderRuntimeClassFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IWwwFormUrlDecoderRuntimeClassFactory>
{
    IWwwFormUrlDecoderRuntimeClassFactory(std::nullptr_t = nullptr) noexcept {}
};

}

}
