// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Networking.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.System.RemoteSystems.3.h"
#include "Windows.System.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::System::RemoteSystems::IRemoteSystem> : produce_base<D, Windows::System::RemoteSystems::IRemoteSystem>
{
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

    HRESULT __stdcall get_Id(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Kind(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Kind());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Status(Windows::System::RemoteSystems::RemoteSystemStatus * value) noexcept override
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

    HRESULT __stdcall get_IsAvailableByProximity(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsAvailableByProximity());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::RemoteSystems::IRemoteSystemAddedEventArgs> : produce_base<D, Windows::System::RemoteSystems::IRemoteSystemAddedEventArgs>
{
    HRESULT __stdcall get_RemoteSystem(impl::abi_arg_out<Windows::System::RemoteSystems::IRemoteSystem> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemoteSystem());
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
struct produce<D, Windows::System::RemoteSystems::IRemoteSystemConnectionRequest> : produce_base<D, Windows::System::RemoteSystems::IRemoteSystemConnectionRequest>
{
    HRESULT __stdcall get_RemoteSystem(impl::abi_arg_out<Windows::System::RemoteSystems::IRemoteSystem> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemoteSystem());
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
struct produce<D, Windows::System::RemoteSystems::IRemoteSystemConnectionRequestFactory> : produce_base<D, Windows::System::RemoteSystems::IRemoteSystemConnectionRequestFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::System::RemoteSystems::IRemoteSystem> remoteSystem, impl::abi_arg_out<Windows::System::RemoteSystems::IRemoteSystemConnectionRequest> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::System::RemoteSystems::RemoteSystem *>(&remoteSystem)));
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
struct produce<D, Windows::System::RemoteSystems::IRemoteSystemDiscoveryTypeFilter> : produce_base<D, Windows::System::RemoteSystems::IRemoteSystemDiscoveryTypeFilter>
{
    HRESULT __stdcall get_RemoteSystemDiscoveryType(Windows::System::RemoteSystems::RemoteSystemDiscoveryType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemoteSystemDiscoveryType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::RemoteSystems::IRemoteSystemDiscoveryTypeFilterFactory> : produce_base<D, Windows::System::RemoteSystems::IRemoteSystemDiscoveryTypeFilterFactory>
{
    HRESULT __stdcall abi_Create(Windows::System::RemoteSystems::RemoteSystemDiscoveryType discoveryType, impl::abi_arg_out<Windows::System::RemoteSystems::IRemoteSystemDiscoveryTypeFilter> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(discoveryType));
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
struct produce<D, Windows::System::RemoteSystems::IRemoteSystemFilter> : produce_base<D, Windows::System::RemoteSystems::IRemoteSystemFilter>
{};

template <typename D>
struct produce<D, Windows::System::RemoteSystems::IRemoteSystemKindFilter> : produce_base<D, Windows::System::RemoteSystems::IRemoteSystemKindFilter>
{
    HRESULT __stdcall get_RemoteSystemKinds(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemoteSystemKinds());
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
struct produce<D, Windows::System::RemoteSystems::IRemoteSystemKindFilterFactory> : produce_base<D, Windows::System::RemoteSystems::IRemoteSystemKindFilterFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> remoteSystemKinds, impl::abi_arg_out<Windows::System::RemoteSystems::IRemoteSystemKindFilter> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&remoteSystemKinds)));
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
struct produce<D, Windows::System::RemoteSystems::IRemoteSystemKindStatics> : produce_base<D, Windows::System::RemoteSystems::IRemoteSystemKindStatics>
{
    HRESULT __stdcall get_Phone(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Phone());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Hub(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Hub());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Holographic(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Holographic());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Desktop(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Desktop());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Xbox(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Xbox());
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
struct produce<D, Windows::System::RemoteSystems::IRemoteSystemRemovedEventArgs> : produce_base<D, Windows::System::RemoteSystems::IRemoteSystemRemovedEventArgs>
{
    HRESULT __stdcall get_RemoteSystemId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemoteSystemId());
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
struct produce<D, Windows::System::RemoteSystems::IRemoteSystemStatics> : produce_base<D, Windows::System::RemoteSystems::IRemoteSystemStatics>
{
    HRESULT __stdcall abi_FindByHostNameAsync(impl::abi_arg_in<Windows::Networking::IHostName> hostName, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::System::RemoteSystems::RemoteSystem>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FindByHostNameAsync(*reinterpret_cast<const Windows::Networking::HostName *>(&hostName)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWatcher(impl::abi_arg_out<Windows::System::RemoteSystems::IRemoteSystemWatcher> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateWatcher());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWatcherWithFilters(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::System::RemoteSystems::IRemoteSystemFilter>> filters, impl::abi_arg_out<Windows::System::RemoteSystems::IRemoteSystemWatcher> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateWatcher(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::System::RemoteSystems::IRemoteSystemFilter> *>(&filters)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestAccessAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::System::RemoteSystems::RemoteSystemAccessStatus>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestAccessAsync());
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
struct produce<D, Windows::System::RemoteSystems::IRemoteSystemStatusTypeFilter> : produce_base<D, Windows::System::RemoteSystems::IRemoteSystemStatusTypeFilter>
{
    HRESULT __stdcall get_RemoteSystemStatusType(Windows::System::RemoteSystems::RemoteSystemStatusType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemoteSystemStatusType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::System::RemoteSystems::IRemoteSystemStatusTypeFilterFactory> : produce_base<D, Windows::System::RemoteSystems::IRemoteSystemStatusTypeFilterFactory>
{
    HRESULT __stdcall abi_Create(Windows::System::RemoteSystems::RemoteSystemStatusType remoteSystemStatusType, impl::abi_arg_out<Windows::System::RemoteSystems::IRemoteSystemStatusTypeFilter> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(remoteSystemStatusType));
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
struct produce<D, Windows::System::RemoteSystems::IRemoteSystemUpdatedEventArgs> : produce_base<D, Windows::System::RemoteSystems::IRemoteSystemUpdatedEventArgs>
{
    HRESULT __stdcall get_RemoteSystem(impl::abi_arg_out<Windows::System::RemoteSystems::IRemoteSystem> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemoteSystem());
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
struct produce<D, Windows::System::RemoteSystems::IRemoteSystemWatcher> : produce_base<D, Windows::System::RemoteSystems::IRemoteSystemWatcher>
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

    HRESULT __stdcall add_RemoteSystemAdded(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::System::RemoteSystems::RemoteSystemWatcher, Windows::System::RemoteSystems::RemoteSystemAddedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().RemoteSystemAdded(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::System::RemoteSystems::RemoteSystemWatcher, Windows::System::RemoteSystems::RemoteSystemAddedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_RemoteSystemAdded(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoteSystemAdded(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_RemoteSystemUpdated(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::System::RemoteSystems::RemoteSystemWatcher, Windows::System::RemoteSystems::RemoteSystemUpdatedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().RemoteSystemUpdated(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::System::RemoteSystems::RemoteSystemWatcher, Windows::System::RemoteSystems::RemoteSystemUpdatedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_RemoteSystemUpdated(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoteSystemUpdated(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_RemoteSystemRemoved(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::System::RemoteSystems::RemoteSystemWatcher, Windows::System::RemoteSystems::RemoteSystemRemovedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().RemoteSystemRemoved(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::System::RemoteSystems::RemoteSystemWatcher, Windows::System::RemoteSystems::RemoteSystemRemovedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_RemoteSystemRemoved(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoteSystemRemoved(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::System::RemoteSystems {

template <typename D> Windows::Foundation::IAsyncOperation<Windows::System::RemoteSystems::RemoteSystem> impl_IRemoteSystemStatics<D>::FindByHostNameAsync(const Windows::Networking::HostName & hostName) const
{
    Windows::Foundation::IAsyncOperation<Windows::System::RemoteSystems::RemoteSystem> operation;
    check_hresult(WINRT_SHIM(IRemoteSystemStatics)->abi_FindByHostNameAsync(get_abi(hostName), put_abi(operation)));
    return operation;
}

template <typename D> Windows::System::RemoteSystems::RemoteSystemWatcher impl_IRemoteSystemStatics<D>::CreateWatcher() const
{
    Windows::System::RemoteSystems::RemoteSystemWatcher result { nullptr };
    check_hresult(WINRT_SHIM(IRemoteSystemStatics)->abi_CreateWatcher(put_abi(result)));
    return result;
}

template <typename D> Windows::System::RemoteSystems::RemoteSystemWatcher impl_IRemoteSystemStatics<D>::CreateWatcher(iterable<Windows::System::RemoteSystems::IRemoteSystemFilter> filters) const
{
    Windows::System::RemoteSystems::RemoteSystemWatcher result { nullptr };
    check_hresult(WINRT_SHIM(IRemoteSystemStatics)->abi_CreateWatcherWithFilters(get_abi(filters), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::System::RemoteSystems::RemoteSystemAccessStatus> impl_IRemoteSystemStatics<D>::RequestAccessAsync() const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::System::RemoteSystems::RemoteSystemAccessStatus> operation;
    check_hresult(WINRT_SHIM(IRemoteSystemStatics)->abi_RequestAccessAsync(put_abi(operation)));
    return operation;
}

template <typename D> hstring impl_IRemoteSystem<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IRemoteSystem)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IRemoteSystem<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IRemoteSystem)->get_Id(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IRemoteSystem<D>::Kind() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IRemoteSystem)->get_Kind(put_abi(value)));
    return value;
}

template <typename D> Windows::System::RemoteSystems::RemoteSystemStatus impl_IRemoteSystem<D>::Status() const
{
    Windows::System::RemoteSystems::RemoteSystemStatus value {};
    check_hresult(WINRT_SHIM(IRemoteSystem)->get_Status(&value));
    return value;
}

template <typename D> bool impl_IRemoteSystem<D>::IsAvailableByProximity() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IRemoteSystem)->get_IsAvailableByProximity(&value));
    return value;
}

template <typename D> void impl_IRemoteSystemWatcher<D>::Start() const
{
    check_hresult(WINRT_SHIM(IRemoteSystemWatcher)->abi_Start());
}

template <typename D> void impl_IRemoteSystemWatcher<D>::Stop() const
{
    check_hresult(WINRT_SHIM(IRemoteSystemWatcher)->abi_Stop());
}

template <typename D> event_token impl_IRemoteSystemWatcher<D>::RemoteSystemAdded(const Windows::Foundation::TypedEventHandler<Windows::System::RemoteSystems::RemoteSystemWatcher, Windows::System::RemoteSystems::RemoteSystemAddedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IRemoteSystemWatcher)->add_RemoteSystemAdded(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IRemoteSystemWatcher> impl_IRemoteSystemWatcher<D>::RemoteSystemAdded(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::System::RemoteSystems::RemoteSystemWatcher, Windows::System::RemoteSystems::RemoteSystemAddedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IRemoteSystemWatcher>(this, &ABI::Windows::System::RemoteSystems::IRemoteSystemWatcher::remove_RemoteSystemAdded, RemoteSystemAdded(handler));
}

template <typename D> void impl_IRemoteSystemWatcher<D>::RemoteSystemAdded(event_token token) const
{
    check_hresult(WINRT_SHIM(IRemoteSystemWatcher)->remove_RemoteSystemAdded(token));
}

template <typename D> event_token impl_IRemoteSystemWatcher<D>::RemoteSystemUpdated(const Windows::Foundation::TypedEventHandler<Windows::System::RemoteSystems::RemoteSystemWatcher, Windows::System::RemoteSystems::RemoteSystemUpdatedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IRemoteSystemWatcher)->add_RemoteSystemUpdated(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IRemoteSystemWatcher> impl_IRemoteSystemWatcher<D>::RemoteSystemUpdated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::System::RemoteSystems::RemoteSystemWatcher, Windows::System::RemoteSystems::RemoteSystemUpdatedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IRemoteSystemWatcher>(this, &ABI::Windows::System::RemoteSystems::IRemoteSystemWatcher::remove_RemoteSystemUpdated, RemoteSystemUpdated(handler));
}

template <typename D> void impl_IRemoteSystemWatcher<D>::RemoteSystemUpdated(event_token token) const
{
    check_hresult(WINRT_SHIM(IRemoteSystemWatcher)->remove_RemoteSystemUpdated(token));
}

template <typename D> event_token impl_IRemoteSystemWatcher<D>::RemoteSystemRemoved(const Windows::Foundation::TypedEventHandler<Windows::System::RemoteSystems::RemoteSystemWatcher, Windows::System::RemoteSystems::RemoteSystemRemovedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IRemoteSystemWatcher)->add_RemoteSystemRemoved(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IRemoteSystemWatcher> impl_IRemoteSystemWatcher<D>::RemoteSystemRemoved(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::System::RemoteSystems::RemoteSystemWatcher, Windows::System::RemoteSystems::RemoteSystemRemovedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IRemoteSystemWatcher>(this, &ABI::Windows::System::RemoteSystems::IRemoteSystemWatcher::remove_RemoteSystemRemoved, RemoteSystemRemoved(handler));
}

template <typename D> void impl_IRemoteSystemWatcher<D>::RemoteSystemRemoved(event_token token) const
{
    check_hresult(WINRT_SHIM(IRemoteSystemWatcher)->remove_RemoteSystemRemoved(token));
}

template <typename D> Windows::System::RemoteSystems::RemoteSystem impl_IRemoteSystemAddedEventArgs<D>::RemoteSystem() const
{
    Windows::System::RemoteSystems::RemoteSystem value { nullptr };
    check_hresult(WINRT_SHIM(IRemoteSystemAddedEventArgs)->get_RemoteSystem(put_abi(value)));
    return value;
}

template <typename D> Windows::System::RemoteSystems::RemoteSystem impl_IRemoteSystemUpdatedEventArgs<D>::RemoteSystem() const
{
    Windows::System::RemoteSystems::RemoteSystem value { nullptr };
    check_hresult(WINRT_SHIM(IRemoteSystemUpdatedEventArgs)->get_RemoteSystem(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IRemoteSystemRemovedEventArgs<D>::RemoteSystemId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IRemoteSystemRemovedEventArgs)->get_RemoteSystemId(put_abi(value)));
    return value;
}

template <typename D> Windows::System::RemoteSystems::RemoteSystemConnectionRequest impl_IRemoteSystemConnectionRequestFactory<D>::Create(const Windows::System::RemoteSystems::RemoteSystem & remoteSystem) const
{
    Windows::System::RemoteSystems::RemoteSystemConnectionRequest result { nullptr };
    check_hresult(WINRT_SHIM(IRemoteSystemConnectionRequestFactory)->abi_Create(get_abi(remoteSystem), put_abi(result)));
    return result;
}

template <typename D> Windows::System::RemoteSystems::RemoteSystem impl_IRemoteSystemConnectionRequest<D>::RemoteSystem() const
{
    Windows::System::RemoteSystems::RemoteSystem value { nullptr };
    check_hresult(WINRT_SHIM(IRemoteSystemConnectionRequest)->get_RemoteSystem(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IRemoteSystemKindStatics<D>::Phone() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IRemoteSystemKindStatics)->get_Phone(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IRemoteSystemKindStatics<D>::Hub() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IRemoteSystemKindStatics)->get_Hub(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IRemoteSystemKindStatics<D>::Holographic() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IRemoteSystemKindStatics)->get_Holographic(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IRemoteSystemKindStatics<D>::Desktop() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IRemoteSystemKindStatics)->get_Desktop(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IRemoteSystemKindStatics<D>::Xbox() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IRemoteSystemKindStatics)->get_Xbox(put_abi(value)));
    return value;
}

template <typename D> Windows::System::RemoteSystems::RemoteSystemKindFilter impl_IRemoteSystemKindFilterFactory<D>::Create(iterable<hstring> remoteSystemKinds) const
{
    Windows::System::RemoteSystems::RemoteSystemKindFilter result { nullptr };
    check_hresult(WINRT_SHIM(IRemoteSystemKindFilterFactory)->abi_Create(get_abi(remoteSystemKinds), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IRemoteSystemKindFilter<D>::RemoteSystemKinds() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(IRemoteSystemKindFilter)->get_RemoteSystemKinds(put_abi(value)));
    return value;
}

template <typename D> Windows::System::RemoteSystems::RemoteSystemDiscoveryTypeFilter impl_IRemoteSystemDiscoveryTypeFilterFactory<D>::Create(Windows::System::RemoteSystems::RemoteSystemDiscoveryType discoveryType) const
{
    Windows::System::RemoteSystems::RemoteSystemDiscoveryTypeFilter result { nullptr };
    check_hresult(WINRT_SHIM(IRemoteSystemDiscoveryTypeFilterFactory)->abi_Create(discoveryType, put_abi(result)));
    return result;
}

template <typename D> Windows::System::RemoteSystems::RemoteSystemDiscoveryType impl_IRemoteSystemDiscoveryTypeFilter<D>::RemoteSystemDiscoveryType() const
{
    Windows::System::RemoteSystems::RemoteSystemDiscoveryType value {};
    check_hresult(WINRT_SHIM(IRemoteSystemDiscoveryTypeFilter)->get_RemoteSystemDiscoveryType(&value));
    return value;
}

template <typename D> Windows::System::RemoteSystems::RemoteSystemStatusTypeFilter impl_IRemoteSystemStatusTypeFilterFactory<D>::Create(Windows::System::RemoteSystems::RemoteSystemStatusType remoteSystemStatusType) const
{
    Windows::System::RemoteSystems::RemoteSystemStatusTypeFilter result { nullptr };
    check_hresult(WINRT_SHIM(IRemoteSystemStatusTypeFilterFactory)->abi_Create(remoteSystemStatusType, put_abi(result)));
    return result;
}

template <typename D> Windows::System::RemoteSystems::RemoteSystemStatusType impl_IRemoteSystemStatusTypeFilter<D>::RemoteSystemStatusType() const
{
    Windows::System::RemoteSystems::RemoteSystemStatusType value {};
    check_hresult(WINRT_SHIM(IRemoteSystemStatusTypeFilter)->get_RemoteSystemStatusType(&value));
    return value;
}

inline Windows::Foundation::IAsyncOperation<Windows::System::RemoteSystems::RemoteSystem> RemoteSystem::FindByHostNameAsync(const Windows::Networking::HostName & hostName)
{
    return get_activation_factory<RemoteSystem, IRemoteSystemStatics>().FindByHostNameAsync(hostName);
}

inline Windows::System::RemoteSystems::RemoteSystemWatcher RemoteSystem::CreateWatcher()
{
    return get_activation_factory<RemoteSystem, IRemoteSystemStatics>().CreateWatcher();
}

inline Windows::System::RemoteSystems::RemoteSystemWatcher RemoteSystem::CreateWatcher(iterable<Windows::System::RemoteSystems::IRemoteSystemFilter> filters)
{
    return get_activation_factory<RemoteSystem, IRemoteSystemStatics>().CreateWatcher(filters);
}

inline Windows::Foundation::IAsyncOperation<winrt::Windows::System::RemoteSystems::RemoteSystemAccessStatus> RemoteSystem::RequestAccessAsync()
{
    return get_activation_factory<RemoteSystem, IRemoteSystemStatics>().RequestAccessAsync();
}

inline RemoteSystemConnectionRequest::RemoteSystemConnectionRequest(const Windows::System::RemoteSystems::RemoteSystem & remoteSystem) :
    RemoteSystemConnectionRequest(get_activation_factory<RemoteSystemConnectionRequest, IRemoteSystemConnectionRequestFactory>().Create(remoteSystem))
{}

inline RemoteSystemDiscoveryTypeFilter::RemoteSystemDiscoveryTypeFilter(Windows::System::RemoteSystems::RemoteSystemDiscoveryType discoveryType) :
    RemoteSystemDiscoveryTypeFilter(get_activation_factory<RemoteSystemDiscoveryTypeFilter, IRemoteSystemDiscoveryTypeFilterFactory>().Create(discoveryType))
{}

inline RemoteSystemKindFilter::RemoteSystemKindFilter(iterable<hstring> remoteSystemKinds) :
    RemoteSystemKindFilter(get_activation_factory<RemoteSystemKindFilter, IRemoteSystemKindFilterFactory>().Create(remoteSystemKinds))
{}

inline hstring RemoteSystemKinds::Phone()
{
    return get_activation_factory<RemoteSystemKinds, IRemoteSystemKindStatics>().Phone();
}

inline hstring RemoteSystemKinds::Hub()
{
    return get_activation_factory<RemoteSystemKinds, IRemoteSystemKindStatics>().Hub();
}

inline hstring RemoteSystemKinds::Holographic()
{
    return get_activation_factory<RemoteSystemKinds, IRemoteSystemKindStatics>().Holographic();
}

inline hstring RemoteSystemKinds::Desktop()
{
    return get_activation_factory<RemoteSystemKinds, IRemoteSystemKindStatics>().Desktop();
}

inline hstring RemoteSystemKinds::Xbox()
{
    return get_activation_factory<RemoteSystemKinds, IRemoteSystemKindStatics>().Xbox();
}

inline RemoteSystemStatusTypeFilter::RemoteSystemStatusTypeFilter(Windows::System::RemoteSystems::RemoteSystemStatusType remoteSystemStatusType) :
    RemoteSystemStatusTypeFilter(get_activation_factory<RemoteSystemStatusTypeFilter, IRemoteSystemStatusTypeFilterFactory>().Create(remoteSystemStatusType))
{}

}

}
#pragma warning(pop)
