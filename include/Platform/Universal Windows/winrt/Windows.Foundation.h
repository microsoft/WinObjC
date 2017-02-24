// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "Windows.Foundation.Collections.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Foundation {

template <typename L> DeferralCompletedHandler::DeferralCompletedHandler(L lambda) :
    DeferralCompletedHandler(impl::make_delegate<impl_DeferralCompletedHandler<L>, DeferralCompletedHandler>(std::forward<L>(lambda)))
{}

template <typename F> DeferralCompletedHandler::DeferralCompletedHandler(F * function) :
    DeferralCompletedHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> DeferralCompletedHandler::DeferralCompletedHandler(O * object, M method) :
    DeferralCompletedHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void DeferralCompletedHandler::operator()() const
{
    check_hresult((*(abi<DeferralCompletedHandler> **)this)->abi_Invoke());
}

}

namespace impl {

template <typename D>
struct produce<D, Windows::Foundation::IClosable> : produce_base<D, Windows::Foundation::IClosable>
{
    HRESULT __stdcall abi_Close() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Close();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::IDeferral> : produce_base<D, Windows::Foundation::IDeferral>
{
    HRESULT __stdcall abi_Complete() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Complete();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::IDeferralFactory> : produce_base<D, Windows::Foundation::IDeferralFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Foundation::DeferralCompletedHandler> handler, impl::abi_arg_out<Windows::Foundation::IDeferral> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Foundation::DeferralCompletedHandler *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::IGetActivationFactory> : produce_base<D, Windows::Foundation::IGetActivationFactory>
{
    HRESULT __stdcall abi_GetActivationFactory(impl::abi_arg_in<hstring> activatableClassId, impl::abi_arg_out<Windows::Foundation::IInspectable> factory) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *factory = detach_abi(this->shim().GetActivationFactory(*reinterpret_cast<const hstring *>(&activatableClassId)));
            return S_OK;
        }
        catch (...)
        {
            *factory = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::IMemoryBuffer> : produce_base<D, Windows::Foundation::IMemoryBuffer>
{
    HRESULT __stdcall abi_CreateReference(impl::abi_arg_out<Windows::Foundation::IMemoryBufferReference> reference) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *reference = detach_abi(this->shim().CreateReference());
            return S_OK;
        }
        catch (...)
        {
            *reference = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::IMemoryBufferFactory> : produce_base<D, Windows::Foundation::IMemoryBufferFactory>
{
    HRESULT __stdcall abi_Create(uint32_t capacity, impl::abi_arg_out<Windows::Foundation::IMemoryBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Create(capacity));
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
struct produce<D, Windows::Foundation::IMemoryBufferReference> : produce_base<D, Windows::Foundation::IMemoryBufferReference>
{
    HRESULT __stdcall get_Capacity(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Capacity());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Closed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Foundation::IMemoryBufferReference, Windows::Foundation::IInspectable>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().Closed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Foundation::IMemoryBufferReference, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Closed(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Closed(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::IStringable> : produce_base<D, Windows::Foundation::IStringable>
{
    HRESULT __stdcall abi_ToString(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ToString());
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
struct produce<D, Windows::Foundation::IUriEscapeStatics> : produce_base<D, Windows::Foundation::IUriEscapeStatics>
{
    HRESULT __stdcall abi_UnescapeComponent(impl::abi_arg_in<hstring> toUnescape, impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UnescapeComponent(*reinterpret_cast<const hstring *>(&toUnescape)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_EscapeComponent(impl::abi_arg_in<hstring> toEscape, impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EscapeComponent(*reinterpret_cast<const hstring *>(&toEscape)));
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
struct produce<D, Windows::Foundation::IUriRuntimeClass> : produce_base<D, Windows::Foundation::IUriRuntimeClass>
{
    HRESULT __stdcall get_AbsoluteUri(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AbsoluteUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayUri(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayUri());
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

    HRESULT __stdcall get_Extension(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Extension());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Fragment(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Fragment());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Host(impl::abi_arg_out<hstring> value) noexcept override
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

    HRESULT __stdcall get_Password(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Password());
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

    HRESULT __stdcall get_Query(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Query());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_QueryParsed(impl::abi_arg_out<Windows::Foundation::IWwwFormUrlDecoderRuntimeClass> ppWwwFormUrlDecoder) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *ppWwwFormUrlDecoder = detach_abi(this->shim().QueryParsed());
            return S_OK;
        }
        catch (...)
        {
            *ppWwwFormUrlDecoder = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RawUri(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RawUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SchemeName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SchemeName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UserName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UserName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Port(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Port());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Suspicious(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Suspicious());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Equals(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> pUri, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Equals(*reinterpret_cast<const Windows::Foundation::Uri *>(&pUri)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CombineUri(impl::abi_arg_in<hstring> relativeUri, impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CombineUri(*reinterpret_cast<const hstring *>(&relativeUri)));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::IUriRuntimeClassFactory> : produce_base<D, Windows::Foundation::IUriRuntimeClassFactory>
{
    HRESULT __stdcall abi_CreateUri(impl::abi_arg_in<hstring> uri, impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateUri(*reinterpret_cast<const hstring *>(&uri)));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithRelativeUri(impl::abi_arg_in<hstring> baseUri, impl::abi_arg_in<hstring> relativeUri, impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateWithRelativeUri(*reinterpret_cast<const hstring *>(&baseUri), *reinterpret_cast<const hstring *>(&relativeUri)));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::IUriRuntimeClassWithAbsoluteCanonicalUri> : produce_base<D, Windows::Foundation::IUriRuntimeClassWithAbsoluteCanonicalUri>
{
    HRESULT __stdcall get_AbsoluteCanonicalUri(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AbsoluteCanonicalUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayIri(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayIri());
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
struct produce<D, Windows::Foundation::IWwwFormUrlDecoderEntry> : produce_base<D, Windows::Foundation::IWwwFormUrlDecoderEntry>
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
};

template <typename D>
struct produce<D, Windows::Foundation::IWwwFormUrlDecoderRuntimeClass> : produce_base<D, Windows::Foundation::IWwwFormUrlDecoderRuntimeClass>
{
    HRESULT __stdcall abi_GetFirstValueByName(impl::abi_arg_in<hstring> name, impl::abi_arg_out<hstring> phstrValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *phstrValue = detach_abi(this->shim().GetFirstValueByName(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *phstrValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Foundation::IWwwFormUrlDecoderRuntimeClassFactory> : produce_base<D, Windows::Foundation::IWwwFormUrlDecoderRuntimeClassFactory>
{
    HRESULT __stdcall abi_CreateWwwFormUrlDecoder(impl::abi_arg_in<hstring> query, impl::abi_arg_out<Windows::Foundation::IWwwFormUrlDecoderRuntimeClass> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateWwwFormUrlDecoder(*reinterpret_cast<const hstring *>(&query)));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Foundation {

template <typename D> void impl_IClosable<D>::Close() const
{
    check_hresult(WINRT_SHIM(IClosable)->abi_Close());
}

template <typename D> hstring impl_IStringable<D>::ToString() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStringable)->abi_ToString(put_abi(value)));
    return value;
}

template <typename D> void impl_IDeferral<D>::Complete() const
{
    check_hresult(WINRT_SHIM(IDeferral)->abi_Complete());
}

template <typename D> Windows::Foundation::Deferral impl_IDeferralFactory<D>::Create(const Windows::Foundation::DeferralCompletedHandler & handler) const
{
    Windows::Foundation::Deferral result { nullptr };
    check_hresult(WINRT_SHIM(IDeferralFactory)->abi_Create(get_abi(handler), put_abi(result)));
    return result;
}

template <typename D> hstring impl_IUriRuntimeClass<D>::AbsoluteUri() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUriRuntimeClass)->get_AbsoluteUri(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IUriRuntimeClass<D>::DisplayUri() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUriRuntimeClass)->get_DisplayUri(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IUriRuntimeClass<D>::Domain() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUriRuntimeClass)->get_Domain(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IUriRuntimeClass<D>::Extension() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUriRuntimeClass)->get_Extension(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IUriRuntimeClass<D>::Fragment() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUriRuntimeClass)->get_Fragment(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IUriRuntimeClass<D>::Host() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUriRuntimeClass)->get_Host(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IUriRuntimeClass<D>::Password() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUriRuntimeClass)->get_Password(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IUriRuntimeClass<D>::Path() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUriRuntimeClass)->get_Path(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IUriRuntimeClass<D>::Query() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUriRuntimeClass)->get_Query(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::WwwFormUrlDecoder impl_IUriRuntimeClass<D>::QueryParsed() const
{
    Windows::Foundation::WwwFormUrlDecoder ppWwwFormUrlDecoder { nullptr };
    check_hresult(WINRT_SHIM(IUriRuntimeClass)->get_QueryParsed(put_abi(ppWwwFormUrlDecoder)));
    return ppWwwFormUrlDecoder;
}

template <typename D> hstring impl_IUriRuntimeClass<D>::RawUri() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUriRuntimeClass)->get_RawUri(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IUriRuntimeClass<D>::SchemeName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUriRuntimeClass)->get_SchemeName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IUriRuntimeClass<D>::UserName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUriRuntimeClass)->get_UserName(put_abi(value)));
    return value;
}

template <typename D> int32_t impl_IUriRuntimeClass<D>::Port() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IUriRuntimeClass)->get_Port(&value));
    return value;
}

template <typename D> bool impl_IUriRuntimeClass<D>::Suspicious() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IUriRuntimeClass)->get_Suspicious(&value));
    return value;
}

template <typename D> bool impl_IUriRuntimeClass<D>::Equals(const Windows::Foundation::Uri & pUri) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IUriRuntimeClass)->abi_Equals(get_abi(pUri), &value));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_IUriRuntimeClass<D>::CombineUri(hstring_view relativeUri) const
{
    Windows::Foundation::Uri instance { nullptr };
    check_hresult(WINRT_SHIM(IUriRuntimeClass)->abi_CombineUri(get_abi(relativeUri), put_abi(instance)));
    return instance;
}

template <typename D> hstring impl_IUriRuntimeClassWithAbsoluteCanonicalUri<D>::AbsoluteCanonicalUri() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUriRuntimeClassWithAbsoluteCanonicalUri)->get_AbsoluteCanonicalUri(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IUriRuntimeClassWithAbsoluteCanonicalUri<D>::DisplayIri() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUriRuntimeClassWithAbsoluteCanonicalUri)->get_DisplayIri(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IUriEscapeStatics<D>::UnescapeComponent(hstring_view toUnescape) const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUriEscapeStatics)->abi_UnescapeComponent(get_abi(toUnescape), put_abi(value)));
    return value;
}

template <typename D> hstring impl_IUriEscapeStatics<D>::EscapeComponent(hstring_view toEscape) const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUriEscapeStatics)->abi_EscapeComponent(get_abi(toEscape), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_IUriRuntimeClassFactory<D>::CreateUri(hstring_view uri) const
{
    Windows::Foundation::Uri instance { nullptr };
    check_hresult(WINRT_SHIM(IUriRuntimeClassFactory)->abi_CreateUri(get_abi(uri), put_abi(instance)));
    return instance;
}

template <typename D> Windows::Foundation::Uri impl_IUriRuntimeClassFactory<D>::CreateWithRelativeUri(hstring_view baseUri, hstring_view relativeUri) const
{
    Windows::Foundation::Uri instance { nullptr };
    check_hresult(WINRT_SHIM(IUriRuntimeClassFactory)->abi_CreateWithRelativeUri(get_abi(baseUri), get_abi(relativeUri), put_abi(instance)));
    return instance;
}

template <typename D> hstring impl_IWwwFormUrlDecoderEntry<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWwwFormUrlDecoderEntry)->get_Name(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IWwwFormUrlDecoderEntry<D>::Value() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWwwFormUrlDecoderEntry)->get_Value(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IWwwFormUrlDecoderRuntimeClass<D>::GetFirstValueByName(hstring_view name) const
{
    hstring phstrValue;
    check_hresult(WINRT_SHIM(IWwwFormUrlDecoderRuntimeClass)->abi_GetFirstValueByName(get_abi(name), put_abi(phstrValue)));
    return phstrValue;
}

template <typename D> Windows::Foundation::WwwFormUrlDecoder impl_IWwwFormUrlDecoderRuntimeClassFactory<D>::CreateWwwFormUrlDecoder(hstring_view query) const
{
    Windows::Foundation::WwwFormUrlDecoder instance { nullptr };
    check_hresult(WINRT_SHIM(IWwwFormUrlDecoderRuntimeClassFactory)->abi_CreateWwwFormUrlDecoder(get_abi(query), put_abi(instance)));
    return instance;
}

template <typename D> Windows::Foundation::IInspectable impl_IGetActivationFactory<D>::GetActivationFactory(hstring_view activatableClassId) const
{
    Windows::Foundation::IInspectable factory;
    check_hresult(WINRT_SHIM(IGetActivationFactory)->abi_GetActivationFactory(get_abi(activatableClassId), put_abi(factory)));
    return factory;
}

template <typename D> uint32_t impl_IMemoryBufferReference<D>::Capacity() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMemoryBufferReference)->get_Capacity(&value));
    return value;
}

template <typename D> event_token impl_IMemoryBufferReference<D>::Closed(const Windows::Foundation::TypedEventHandler<Windows::Foundation::IMemoryBufferReference, Windows::Foundation::IInspectable> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IMemoryBufferReference)->add_Closed(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IMemoryBufferReference> impl_IMemoryBufferReference<D>::Closed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Foundation::IMemoryBufferReference, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMemoryBufferReference>(this, &ABI::Windows::Foundation::IMemoryBufferReference::remove_Closed, Closed(handler));
}

template <typename D> void impl_IMemoryBufferReference<D>::Closed(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IMemoryBufferReference)->remove_Closed(cookie));
}

template <typename D> Windows::Foundation::IMemoryBufferReference impl_IMemoryBuffer<D>::CreateReference() const
{
    Windows::Foundation::IMemoryBufferReference reference;
    check_hresult(WINRT_SHIM(IMemoryBuffer)->abi_CreateReference(put_abi(reference)));
    return reference;
}

template <typename D> Windows::Foundation::MemoryBuffer impl_IMemoryBufferFactory<D>::Create(uint32_t capacity) const
{
    Windows::Foundation::MemoryBuffer value { nullptr };
    check_hresult(WINRT_SHIM(IMemoryBufferFactory)->abi_Create(capacity, put_abi(value)));
    return value;
}

inline Deferral::Deferral(const Windows::Foundation::DeferralCompletedHandler & handler) :
    Deferral(get_activation_factory<Deferral, IDeferralFactory>().Create(handler))
{}

inline MemoryBuffer::MemoryBuffer(uint32_t capacity) :
    MemoryBuffer(get_activation_factory<MemoryBuffer, IMemoryBufferFactory>().Create(capacity))
{}

inline Uri::Uri(hstring_view uri) :
    Uri(get_activation_factory<Uri, IUriRuntimeClassFactory>().CreateUri(uri))
{}

inline Uri::Uri(hstring_view baseUri, hstring_view relativeUri) :
    Uri(get_activation_factory<Uri, IUriRuntimeClassFactory>().CreateWithRelativeUri(baseUri, relativeUri))
{}

inline hstring Uri::UnescapeComponent(hstring_view toUnescape)
{
    return get_activation_factory<Uri, IUriEscapeStatics>().UnescapeComponent(toUnescape);
}

inline hstring Uri::EscapeComponent(hstring_view toEscape)
{
    return get_activation_factory<Uri, IUriEscapeStatics>().EscapeComponent(toEscape);
}

inline WwwFormUrlDecoder::WwwFormUrlDecoder(hstring_view query) :
    WwwFormUrlDecoder(get_activation_factory<WwwFormUrlDecoder, IWwwFormUrlDecoderRuntimeClassFactory>().CreateWwwFormUrlDecoder(query))
{}

}

}
#pragma warning(pop)
