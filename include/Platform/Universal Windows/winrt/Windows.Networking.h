// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Networking.Connectivity.3.h"
#include "internal/Windows.Networking.3.h"
#include "Windows.Foundation.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Networking::IEndpointPair> : produce_base<D, Windows::Networking::IEndpointPair>
{
    HRESULT __stdcall get_LocalHostName(impl::abi_arg_out<Windows::Networking::IHostName> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LocalHostName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LocalHostName(impl::abi_arg_in<Windows::Networking::IHostName> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LocalHostName(*reinterpret_cast<const Windows::Networking::HostName *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LocalServiceName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LocalServiceName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LocalServiceName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LocalServiceName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RemoteHostName(impl::abi_arg_out<Windows::Networking::IHostName> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemoteHostName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RemoteHostName(impl::abi_arg_in<Windows::Networking::IHostName> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoteHostName(*reinterpret_cast<const Windows::Networking::HostName *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RemoteServiceName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemoteServiceName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RemoteServiceName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoteServiceName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::IEndpointPairFactory> : produce_base<D, Windows::Networking::IEndpointPairFactory>
{
    HRESULT __stdcall abi_CreateEndpointPair(impl::abi_arg_in<Windows::Networking::IHostName> localHostName, impl::abi_arg_in<hstring> localServiceName, impl::abi_arg_in<Windows::Networking::IHostName> remoteHostName, impl::abi_arg_in<hstring> remoteServiceName, impl::abi_arg_out<Windows::Networking::IEndpointPair> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateEndpointPair(*reinterpret_cast<const Windows::Networking::HostName *>(&localHostName), *reinterpret_cast<const hstring *>(&localServiceName), *reinterpret_cast<const Windows::Networking::HostName *>(&remoteHostName), *reinterpret_cast<const hstring *>(&remoteServiceName)));
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
struct produce<D, Windows::Networking::IHostName> : produce_base<D, Windows::Networking::IHostName>
{
    HRESULT __stdcall get_IPInformation(impl::abi_arg_out<Windows::Networking::Connectivity::IIPInformation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IPInformation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RawName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RawName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanonicalName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanonicalName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Type(Windows::Networking::HostNameType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Type());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsEqual(impl::abi_arg_in<Windows::Networking::IHostName> hostName, bool * isEqual) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *isEqual = detach_abi(this->shim().IsEqual(*reinterpret_cast<const Windows::Networking::HostName *>(&hostName)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::IHostNameFactory> : produce_base<D, Windows::Networking::IHostNameFactory>
{
    HRESULT __stdcall abi_CreateHostName(impl::abi_arg_in<hstring> hostName, impl::abi_arg_out<Windows::Networking::IHostName> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateHostName(*reinterpret_cast<const hstring *>(&hostName)));
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
struct produce<D, Windows::Networking::IHostNameStatics> : produce_base<D, Windows::Networking::IHostNameStatics>
{
    HRESULT __stdcall abi_Compare(impl::abi_arg_in<hstring> value1, impl::abi_arg_in<hstring> value2, int32_t * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Compare(*reinterpret_cast<const hstring *>(&value1), *reinterpret_cast<const hstring *>(&value2)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Networking {

template <typename D> int32_t impl_IHostNameStatics<D>::Compare(hstring_view value1, hstring_view value2) const
{
    int32_t result {};
    check_hresult(WINRT_SHIM(IHostNameStatics)->abi_Compare(get_abi(value1), get_abi(value2), &result));
    return result;
}

template <typename D> Windows::Networking::Connectivity::IPInformation impl_IHostName<D>::IPInformation() const
{
    Windows::Networking::Connectivity::IPInformation value { nullptr };
    check_hresult(WINRT_SHIM(IHostName)->get_IPInformation(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IHostName<D>::RawName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHostName)->get_RawName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IHostName<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHostName)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IHostName<D>::CanonicalName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHostName)->get_CanonicalName(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::HostNameType impl_IHostName<D>::Type() const
{
    Windows::Networking::HostNameType value {};
    check_hresult(WINRT_SHIM(IHostName)->get_Type(&value));
    return value;
}

template <typename D> bool impl_IHostName<D>::IsEqual(const Windows::Networking::HostName & hostName) const
{
    bool isEqual {};
    check_hresult(WINRT_SHIM(IHostName)->abi_IsEqual(get_abi(hostName), &isEqual));
    return isEqual;
}

template <typename D> Windows::Networking::HostName impl_IHostNameFactory<D>::CreateHostName(hstring_view hostName) const
{
    Windows::Networking::HostName value { nullptr };
    check_hresult(WINRT_SHIM(IHostNameFactory)->abi_CreateHostName(get_abi(hostName), put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::HostName impl_IEndpointPair<D>::LocalHostName() const
{
    Windows::Networking::HostName value { nullptr };
    check_hresult(WINRT_SHIM(IEndpointPair)->get_LocalHostName(put_abi(value)));
    return value;
}

template <typename D> void impl_IEndpointPair<D>::LocalHostName(const Windows::Networking::HostName & value) const
{
    check_hresult(WINRT_SHIM(IEndpointPair)->put_LocalHostName(get_abi(value)));
}

template <typename D> hstring impl_IEndpointPair<D>::LocalServiceName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEndpointPair)->get_LocalServiceName(put_abi(value)));
    return value;
}

template <typename D> void impl_IEndpointPair<D>::LocalServiceName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IEndpointPair)->put_LocalServiceName(get_abi(value)));
}

template <typename D> Windows::Networking::HostName impl_IEndpointPair<D>::RemoteHostName() const
{
    Windows::Networking::HostName value { nullptr };
    check_hresult(WINRT_SHIM(IEndpointPair)->get_RemoteHostName(put_abi(value)));
    return value;
}

template <typename D> void impl_IEndpointPair<D>::RemoteHostName(const Windows::Networking::HostName & value) const
{
    check_hresult(WINRT_SHIM(IEndpointPair)->put_RemoteHostName(get_abi(value)));
}

template <typename D> hstring impl_IEndpointPair<D>::RemoteServiceName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEndpointPair)->get_RemoteServiceName(put_abi(value)));
    return value;
}

template <typename D> void impl_IEndpointPair<D>::RemoteServiceName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IEndpointPair)->put_RemoteServiceName(get_abi(value)));
}

template <typename D> Windows::Networking::EndpointPair impl_IEndpointPairFactory<D>::CreateEndpointPair(const Windows::Networking::HostName & localHostName, hstring_view localServiceName, const Windows::Networking::HostName & remoteHostName, hstring_view remoteServiceName) const
{
    Windows::Networking::EndpointPair value { nullptr };
    check_hresult(WINRT_SHIM(IEndpointPairFactory)->abi_CreateEndpointPair(get_abi(localHostName), get_abi(localServiceName), get_abi(remoteHostName), get_abi(remoteServiceName), put_abi(value)));
    return value;
}

inline EndpointPair::EndpointPair(const Windows::Networking::HostName & localHostName, hstring_view localServiceName, const Windows::Networking::HostName & remoteHostName, hstring_view remoteServiceName) :
    EndpointPair(get_activation_factory<EndpointPair, IEndpointPairFactory>().CreateEndpointPair(localHostName, localServiceName, remoteHostName, remoteServiceName))
{}

inline HostName::HostName(hstring_view hostName) :
    HostName(get_activation_factory<HostName, IHostNameFactory>().CreateHostName(hostName))
{}

inline int32_t HostName::Compare(hstring_view value1, hstring_view value2)
{
    return get_activation_factory<HostName, IHostNameStatics>().Compare(value1, value2);
}

}

}
#pragma warning(pop)
