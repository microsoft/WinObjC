// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Networking.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Networking.Sockets.3.h"
#include "internal/Windows.Networking.Connectivity.3.h"
#include "internal/Windows.Networking.ServiceDiscovery.Dnssd.3.h"
#include "Windows.Networking.h"
#include "Windows.Foundation.h"
#include "Windows.Foundation.Collections.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Networking::ServiceDiscovery::Dnssd::IDnssdRegistrationResult> : produce_base<D, Windows::Networking::ServiceDiscovery::Dnssd::IDnssdRegistrationResult>
{
    HRESULT __stdcall get_Status(Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IPAddress(impl::abi_arg_out<Windows::Networking::IHostName> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IPAddress());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HasInstanceNameChanged(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HasInstanceNameChanged());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstance> : produce_base<D, Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstance>
{
    HRESULT __stdcall get_DnssdServiceInstanceName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DnssdServiceInstanceName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DnssdServiceInstanceName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DnssdServiceInstanceName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HostName(impl::abi_arg_out<Windows::Networking::IHostName> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HostName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_HostName(impl::abi_arg_in<Windows::Networking::IHostName> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HostName(*reinterpret_cast<const Windows::Networking::HostName *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Port(uint16_t * value) noexcept override
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

    HRESULT __stdcall put_Port(uint16_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Port(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Priority(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Priority());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Priority(uint16_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Priority(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Weight(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Weight());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Weight(uint16_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Weight(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TextAttributes(impl::abi_arg_out<Windows::Foundation::Collections::IMap<hstring, hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TextAttributes());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RegisterStreamSocketListenerAsync1(impl::abi_arg_in<Windows::Networking::Sockets::IStreamSocketListener> socket, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RegisterStreamSocketListenerAsync(*reinterpret_cast<const Windows::Networking::Sockets::StreamSocketListener *>(&socket)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RegisterStreamSocketListenerAsync2(impl::abi_arg_in<Windows::Networking::Sockets::IStreamSocketListener> socket, impl::abi_arg_in<Windows::Networking::Connectivity::INetworkAdapter> adapter, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RegisterStreamSocketListenerAsync(*reinterpret_cast<const Windows::Networking::Sockets::StreamSocketListener *>(&socket), *reinterpret_cast<const Windows::Networking::Connectivity::NetworkAdapter *>(&adapter)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RegisterDatagramSocketAsync1(impl::abi_arg_in<Windows::Networking::Sockets::IDatagramSocket> socket, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RegisterDatagramSocketAsync(*reinterpret_cast<const Windows::Networking::Sockets::DatagramSocket *>(&socket)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RegisterDatagramSocketAsync2(impl::abi_arg_in<Windows::Networking::Sockets::IDatagramSocket> socket, impl::abi_arg_in<Windows::Networking::Connectivity::INetworkAdapter> adapter, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RegisterDatagramSocketAsync(*reinterpret_cast<const Windows::Networking::Sockets::DatagramSocket *>(&socket), *reinterpret_cast<const Windows::Networking::Connectivity::NetworkAdapter *>(&adapter)));
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
struct produce<D, Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstanceFactory> : produce_base<D, Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstanceFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> dnssdServiceInstanceName, impl::abi_arg_in<Windows::Networking::IHostName> hostName, uint16_t port, impl::abi_arg_out<Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstance> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&dnssdServiceInstanceName), *reinterpret_cast<const Windows::Networking::HostName *>(&hostName), port));
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
struct produce<D, Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceWatcher> : produce_base<D, Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceWatcher>
{
    HRESULT __stdcall add_Added(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcher, Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceInstance>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Added(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcher, Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceInstance> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Added(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Added(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_EnumerationCompleted(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcher, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().EnumerationCompleted(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcher, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_EnumerationCompleted(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnumerationCompleted(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Stopped(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcher, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Stopped(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcher, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Stopped(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stopped(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Status(Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcherStatus * status) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *status = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

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
};

}

namespace Windows::Networking::ServiceDiscovery::Dnssd {

template <typename D> event_token impl_IDnssdServiceWatcher<D>::Added(const Windows::Foundation::TypedEventHandler<Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcher, Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceInstance> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IDnssdServiceWatcher)->add_Added(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IDnssdServiceWatcher> impl_IDnssdServiceWatcher<D>::Added(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcher, Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceInstance> & handler) const
{
    return impl::make_event_revoker<D, IDnssdServiceWatcher>(this, &ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceWatcher::remove_Added, Added(handler));
}

template <typename D> void impl_IDnssdServiceWatcher<D>::Added(event_token token) const
{
    check_hresult(WINRT_SHIM(IDnssdServiceWatcher)->remove_Added(token));
}

template <typename D> event_token impl_IDnssdServiceWatcher<D>::EnumerationCompleted(const Windows::Foundation::TypedEventHandler<Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcher, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IDnssdServiceWatcher)->add_EnumerationCompleted(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IDnssdServiceWatcher> impl_IDnssdServiceWatcher<D>::EnumerationCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcher, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IDnssdServiceWatcher>(this, &ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceWatcher::remove_EnumerationCompleted, EnumerationCompleted(handler));
}

template <typename D> void impl_IDnssdServiceWatcher<D>::EnumerationCompleted(event_token token) const
{
    check_hresult(WINRT_SHIM(IDnssdServiceWatcher)->remove_EnumerationCompleted(token));
}

template <typename D> event_token impl_IDnssdServiceWatcher<D>::Stopped(const Windows::Foundation::TypedEventHandler<Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcher, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IDnssdServiceWatcher)->add_Stopped(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IDnssdServiceWatcher> impl_IDnssdServiceWatcher<D>::Stopped(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcher, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IDnssdServiceWatcher>(this, &ABI::Windows::Networking::ServiceDiscovery::Dnssd::IDnssdServiceWatcher::remove_Stopped, Stopped(handler));
}

template <typename D> void impl_IDnssdServiceWatcher<D>::Stopped(event_token token) const
{
    check_hresult(WINRT_SHIM(IDnssdServiceWatcher)->remove_Stopped(token));
}

template <typename D> Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcherStatus impl_IDnssdServiceWatcher<D>::Status() const
{
    Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceWatcherStatus status {};
    check_hresult(WINRT_SHIM(IDnssdServiceWatcher)->get_Status(&status));
    return status;
}

template <typename D> void impl_IDnssdServiceWatcher<D>::Start() const
{
    check_hresult(WINRT_SHIM(IDnssdServiceWatcher)->abi_Start());
}

template <typename D> void impl_IDnssdServiceWatcher<D>::Stop() const
{
    check_hresult(WINRT_SHIM(IDnssdServiceWatcher)->abi_Stop());
}

template <typename D> Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationStatus impl_IDnssdRegistrationResult<D>::Status() const
{
    Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationStatus value {};
    check_hresult(WINRT_SHIM(IDnssdRegistrationResult)->get_Status(&value));
    return value;
}

template <typename D> Windows::Networking::HostName impl_IDnssdRegistrationResult<D>::IPAddress() const
{
    Windows::Networking::HostName value { nullptr };
    check_hresult(WINRT_SHIM(IDnssdRegistrationResult)->get_IPAddress(put_abi(value)));
    return value;
}

template <typename D> bool impl_IDnssdRegistrationResult<D>::HasInstanceNameChanged() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDnssdRegistrationResult)->get_HasInstanceNameChanged(&value));
    return value;
}

template <typename D> Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceInstance impl_IDnssdServiceInstanceFactory<D>::Create(hstring_view dnssdServiceInstanceName, const Windows::Networking::HostName & hostName, uint16_t port) const
{
    Windows::Networking::ServiceDiscovery::Dnssd::DnssdServiceInstance result { nullptr };
    check_hresult(WINRT_SHIM(IDnssdServiceInstanceFactory)->abi_Create(get_abi(dnssdServiceInstanceName), get_abi(hostName), port, put_abi(result)));
    return result;
}

template <typename D> hstring impl_IDnssdServiceInstance<D>::DnssdServiceInstanceName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDnssdServiceInstance)->get_DnssdServiceInstanceName(put_abi(value)));
    return value;
}

template <typename D> void impl_IDnssdServiceInstance<D>::DnssdServiceInstanceName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IDnssdServiceInstance)->put_DnssdServiceInstanceName(get_abi(value)));
}

template <typename D> Windows::Networking::HostName impl_IDnssdServiceInstance<D>::HostName() const
{
    Windows::Networking::HostName value { nullptr };
    check_hresult(WINRT_SHIM(IDnssdServiceInstance)->get_HostName(put_abi(value)));
    return value;
}

template <typename D> void impl_IDnssdServiceInstance<D>::HostName(const Windows::Networking::HostName & value) const
{
    check_hresult(WINRT_SHIM(IDnssdServiceInstance)->put_HostName(get_abi(value)));
}

template <typename D> uint16_t impl_IDnssdServiceInstance<D>::Port() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IDnssdServiceInstance)->get_Port(&value));
    return value;
}

template <typename D> void impl_IDnssdServiceInstance<D>::Port(uint16_t value) const
{
    check_hresult(WINRT_SHIM(IDnssdServiceInstance)->put_Port(value));
}

template <typename D> uint16_t impl_IDnssdServiceInstance<D>::Priority() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IDnssdServiceInstance)->get_Priority(&value));
    return value;
}

template <typename D> void impl_IDnssdServiceInstance<D>::Priority(uint16_t value) const
{
    check_hresult(WINRT_SHIM(IDnssdServiceInstance)->put_Priority(value));
}

template <typename D> uint16_t impl_IDnssdServiceInstance<D>::Weight() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IDnssdServiceInstance)->get_Weight(&value));
    return value;
}

template <typename D> void impl_IDnssdServiceInstance<D>::Weight(uint16_t value) const
{
    check_hresult(WINRT_SHIM(IDnssdServiceInstance)->put_Weight(value));
}

template <typename D> Windows::Foundation::Collections::IMap<hstring, hstring> impl_IDnssdServiceInstance<D>::TextAttributes() const
{
    Windows::Foundation::Collections::IMap<hstring, hstring> value;
    check_hresult(WINRT_SHIM(IDnssdServiceInstance)->get_TextAttributes(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult> impl_IDnssdServiceInstance<D>::RegisterStreamSocketListenerAsync(const Windows::Networking::Sockets::StreamSocketListener & socket) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult> result;
    check_hresult(WINRT_SHIM(IDnssdServiceInstance)->abi_RegisterStreamSocketListenerAsync1(get_abi(socket), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult> impl_IDnssdServiceInstance<D>::RegisterStreamSocketListenerAsync(const Windows::Networking::Sockets::StreamSocketListener & socket, const Windows::Networking::Connectivity::NetworkAdapter & adapter) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult> result;
    check_hresult(WINRT_SHIM(IDnssdServiceInstance)->abi_RegisterStreamSocketListenerAsync2(get_abi(socket), get_abi(adapter), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult> impl_IDnssdServiceInstance<D>::RegisterDatagramSocketAsync(const Windows::Networking::Sockets::DatagramSocket & socket) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult> result;
    check_hresult(WINRT_SHIM(IDnssdServiceInstance)->abi_RegisterDatagramSocketAsync1(get_abi(socket), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult> impl_IDnssdServiceInstance<D>::RegisterDatagramSocketAsync(const Windows::Networking::Sockets::DatagramSocket & socket, const Windows::Networking::Connectivity::NetworkAdapter & adapter) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::ServiceDiscovery::Dnssd::DnssdRegistrationResult> result;
    check_hresult(WINRT_SHIM(IDnssdServiceInstance)->abi_RegisterDatagramSocketAsync2(get_abi(socket), get_abi(adapter), put_abi(result)));
    return result;
}

inline DnssdRegistrationResult::DnssdRegistrationResult() :
    DnssdRegistrationResult(activate_instance<DnssdRegistrationResult>())
{}

inline DnssdServiceInstance::DnssdServiceInstance(hstring_view dnssdServiceInstanceName, const Windows::Networking::HostName & hostName, uint16_t port) :
    DnssdServiceInstance(get_activation_factory<DnssdServiceInstance, IDnssdServiceInstanceFactory>().Create(dnssdServiceInstanceName, hostName, port))
{}

}

}
#pragma warning(pop)
