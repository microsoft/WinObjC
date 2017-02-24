// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Devices.Enumeration.3.h"
#include "internal/Windows.Devices.Enumeration.Pnp.3.h"
#include "Windows.Devices.Enumeration.h"
#include "Windows.Foundation.Collections.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::Enumeration::Pnp::IPnpObject> : produce_base<D, Windows::Devices::Enumeration::Pnp::IPnpObject>
{
    HRESULT __stdcall get_Type(Windows::Devices::Enumeration::Pnp::PnpObjectType * value) noexcept override
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

    HRESULT __stdcall get_Properties(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> value) noexcept override
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

    HRESULT __stdcall abi_Update(impl::abi_arg_in<Windows::Devices::Enumeration::Pnp::IPnpObjectUpdate> updateInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Update(*reinterpret_cast<const Windows::Devices::Enumeration::Pnp::PnpObjectUpdate *>(&updateInfo));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::Pnp::IPnpObjectStatics> : produce_base<D, Windows::Devices::Enumeration::Pnp::IPnpObjectStatics>
{
    HRESULT __stdcall abi_CreateFromIdAsync(Windows::Devices::Enumeration::Pnp::PnpObjectType type, impl::abi_arg_in<hstring> id, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> requestedProperties, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::Pnp::PnpObject>> asyncOp) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_abi(this->shim().CreateFromIdAsync(type, *reinterpret_cast<const hstring *>(&id), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&requestedProperties)));
            return S_OK;
        }
        catch (...)
        {
            *asyncOp = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAllAsync(Windows::Devices::Enumeration::Pnp::PnpObjectType type, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> requestedProperties, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::Pnp::PnpObjectCollection>> asyncOp) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_abi(this->shim().FindAllAsync(type, *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&requestedProperties)));
            return S_OK;
        }
        catch (...)
        {
            *asyncOp = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAllAsyncAqsFilter(Windows::Devices::Enumeration::Pnp::PnpObjectType type, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> requestedProperties, impl::abi_arg_in<hstring> aqsFilter, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::Pnp::PnpObjectCollection>> asyncOp) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_abi(this->shim().FindAllAsync(type, *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&requestedProperties), *reinterpret_cast<const hstring *>(&aqsFilter)));
            return S_OK;
        }
        catch (...)
        {
            *asyncOp = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWatcher(Windows::Devices::Enumeration::Pnp::PnpObjectType type, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> requestedProperties, impl::abi_arg_out<Windows::Devices::Enumeration::Pnp::IPnpObjectWatcher> watcher) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *watcher = detach_abi(this->shim().CreateWatcher(type, *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&requestedProperties)));
            return S_OK;
        }
        catch (...)
        {
            *watcher = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWatcherAqsFilter(Windows::Devices::Enumeration::Pnp::PnpObjectType type, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> requestedProperties, impl::abi_arg_in<hstring> aqsFilter, impl::abi_arg_out<Windows::Devices::Enumeration::Pnp::IPnpObjectWatcher> watcher) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *watcher = detach_abi(this->shim().CreateWatcher(type, *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&requestedProperties), *reinterpret_cast<const hstring *>(&aqsFilter)));
            return S_OK;
        }
        catch (...)
        {
            *watcher = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::Pnp::IPnpObjectUpdate> : produce_base<D, Windows::Devices::Enumeration::Pnp::IPnpObjectUpdate>
{
    HRESULT __stdcall get_Type(Windows::Devices::Enumeration::Pnp::PnpObjectType * value) noexcept override
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

    HRESULT __stdcall get_Properties(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> value) noexcept override
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
};

template <typename D>
struct produce<D, Windows::Devices::Enumeration::Pnp::IPnpObjectWatcher> : produce_base<D, Windows::Devices::Enumeration::Pnp::IPnpObjectWatcher>
{
    HRESULT __stdcall add_Added(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::Pnp::PnpObjectWatcher, Windows::Devices::Enumeration::Pnp::PnpObject>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Added(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::Pnp::PnpObjectWatcher, Windows::Devices::Enumeration::Pnp::PnpObject> *>(&handler)));
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

    HRESULT __stdcall add_Updated(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::Pnp::PnpObjectWatcher, Windows::Devices::Enumeration::Pnp::PnpObjectUpdate>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Updated(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::Pnp::PnpObjectWatcher, Windows::Devices::Enumeration::Pnp::PnpObjectUpdate> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Updated(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Updated(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Removed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::Pnp::PnpObjectWatcher, Windows::Devices::Enumeration::Pnp::PnpObjectUpdate>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Removed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::Pnp::PnpObjectWatcher, Windows::Devices::Enumeration::Pnp::PnpObjectUpdate> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Removed(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Removed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_EnumerationCompleted(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::Pnp::PnpObjectWatcher, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().EnumerationCompleted(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::Pnp::PnpObjectWatcher, Windows::Foundation::IInspectable> *>(&handler)));
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

    HRESULT __stdcall add_Stopped(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::Pnp::PnpObjectWatcher, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Stopped(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::Pnp::PnpObjectWatcher, Windows::Foundation::IInspectable> *>(&handler)));
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

    HRESULT __stdcall get_Status(Windows::Devices::Enumeration::DeviceWatcherStatus * status) noexcept override
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

namespace Windows::Devices::Enumeration::Pnp {

template <typename D> Windows::Devices::Enumeration::Pnp::PnpObjectType impl_IPnpObjectUpdate<D>::Type() const
{
    Windows::Devices::Enumeration::Pnp::PnpObjectType value {};
    check_hresult(WINRT_SHIM(IPnpObjectUpdate)->get_Type(&value));
    return value;
}

template <typename D> hstring impl_IPnpObjectUpdate<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPnpObjectUpdate)->get_Id(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> impl_IPnpObjectUpdate<D>::Properties() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> value;
    check_hresult(WINRT_SHIM(IPnpObjectUpdate)->get_Properties(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IPnpObjectWatcher<D>::Added(const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::Pnp::PnpObjectWatcher, Windows::Devices::Enumeration::Pnp::PnpObject> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPnpObjectWatcher)->add_Added(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPnpObjectWatcher> impl_IPnpObjectWatcher<D>::Added(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::Pnp::PnpObjectWatcher, Windows::Devices::Enumeration::Pnp::PnpObject> & handler) const
{
    return impl::make_event_revoker<D, IPnpObjectWatcher>(this, &ABI::Windows::Devices::Enumeration::Pnp::IPnpObjectWatcher::remove_Added, Added(handler));
}

template <typename D> void impl_IPnpObjectWatcher<D>::Added(event_token token) const
{
    check_hresult(WINRT_SHIM(IPnpObjectWatcher)->remove_Added(token));
}

template <typename D> event_token impl_IPnpObjectWatcher<D>::Updated(const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::Pnp::PnpObjectWatcher, Windows::Devices::Enumeration::Pnp::PnpObjectUpdate> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPnpObjectWatcher)->add_Updated(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPnpObjectWatcher> impl_IPnpObjectWatcher<D>::Updated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::Pnp::PnpObjectWatcher, Windows::Devices::Enumeration::Pnp::PnpObjectUpdate> & handler) const
{
    return impl::make_event_revoker<D, IPnpObjectWatcher>(this, &ABI::Windows::Devices::Enumeration::Pnp::IPnpObjectWatcher::remove_Updated, Updated(handler));
}

template <typename D> void impl_IPnpObjectWatcher<D>::Updated(event_token token) const
{
    check_hresult(WINRT_SHIM(IPnpObjectWatcher)->remove_Updated(token));
}

template <typename D> event_token impl_IPnpObjectWatcher<D>::Removed(const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::Pnp::PnpObjectWatcher, Windows::Devices::Enumeration::Pnp::PnpObjectUpdate> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPnpObjectWatcher)->add_Removed(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPnpObjectWatcher> impl_IPnpObjectWatcher<D>::Removed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::Pnp::PnpObjectWatcher, Windows::Devices::Enumeration::Pnp::PnpObjectUpdate> & handler) const
{
    return impl::make_event_revoker<D, IPnpObjectWatcher>(this, &ABI::Windows::Devices::Enumeration::Pnp::IPnpObjectWatcher::remove_Removed, Removed(handler));
}

template <typename D> void impl_IPnpObjectWatcher<D>::Removed(event_token token) const
{
    check_hresult(WINRT_SHIM(IPnpObjectWatcher)->remove_Removed(token));
}

template <typename D> event_token impl_IPnpObjectWatcher<D>::EnumerationCompleted(const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::Pnp::PnpObjectWatcher, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPnpObjectWatcher)->add_EnumerationCompleted(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPnpObjectWatcher> impl_IPnpObjectWatcher<D>::EnumerationCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::Pnp::PnpObjectWatcher, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IPnpObjectWatcher>(this, &ABI::Windows::Devices::Enumeration::Pnp::IPnpObjectWatcher::remove_EnumerationCompleted, EnumerationCompleted(handler));
}

template <typename D> void impl_IPnpObjectWatcher<D>::EnumerationCompleted(event_token token) const
{
    check_hresult(WINRT_SHIM(IPnpObjectWatcher)->remove_EnumerationCompleted(token));
}

template <typename D> event_token impl_IPnpObjectWatcher<D>::Stopped(const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::Pnp::PnpObjectWatcher, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPnpObjectWatcher)->add_Stopped(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IPnpObjectWatcher> impl_IPnpObjectWatcher<D>::Stopped(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Enumeration::Pnp::PnpObjectWatcher, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IPnpObjectWatcher>(this, &ABI::Windows::Devices::Enumeration::Pnp::IPnpObjectWatcher::remove_Stopped, Stopped(handler));
}

template <typename D> void impl_IPnpObjectWatcher<D>::Stopped(event_token token) const
{
    check_hresult(WINRT_SHIM(IPnpObjectWatcher)->remove_Stopped(token));
}

template <typename D> Windows::Devices::Enumeration::DeviceWatcherStatus impl_IPnpObjectWatcher<D>::Status() const
{
    Windows::Devices::Enumeration::DeviceWatcherStatus status {};
    check_hresult(WINRT_SHIM(IPnpObjectWatcher)->get_Status(&status));
    return status;
}

template <typename D> void impl_IPnpObjectWatcher<D>::Start() const
{
    check_hresult(WINRT_SHIM(IPnpObjectWatcher)->abi_Start());
}

template <typename D> void impl_IPnpObjectWatcher<D>::Stop() const
{
    check_hresult(WINRT_SHIM(IPnpObjectWatcher)->abi_Stop());
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::Pnp::PnpObject> impl_IPnpObjectStatics<D>::CreateFromIdAsync(Windows::Devices::Enumeration::Pnp::PnpObjectType type, hstring_view id, iterable<hstring> requestedProperties) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::Pnp::PnpObject> asyncOp;
    check_hresult(WINRT_SHIM(IPnpObjectStatics)->abi_CreateFromIdAsync(type, get_abi(id), get_abi(requestedProperties), put_abi(asyncOp)));
    return asyncOp;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::Pnp::PnpObjectCollection> impl_IPnpObjectStatics<D>::FindAllAsync(Windows::Devices::Enumeration::Pnp::PnpObjectType type, iterable<hstring> requestedProperties) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::Pnp::PnpObjectCollection> asyncOp;
    check_hresult(WINRT_SHIM(IPnpObjectStatics)->abi_FindAllAsync(type, get_abi(requestedProperties), put_abi(asyncOp)));
    return asyncOp;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::Pnp::PnpObjectCollection> impl_IPnpObjectStatics<D>::FindAllAsync(Windows::Devices::Enumeration::Pnp::PnpObjectType type, iterable<hstring> requestedProperties, hstring_view aqsFilter) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::Pnp::PnpObjectCollection> asyncOp;
    check_hresult(WINRT_SHIM(IPnpObjectStatics)->abi_FindAllAsyncAqsFilter(type, get_abi(requestedProperties), get_abi(aqsFilter), put_abi(asyncOp)));
    return asyncOp;
}

template <typename D> Windows::Devices::Enumeration::Pnp::PnpObjectWatcher impl_IPnpObjectStatics<D>::CreateWatcher(Windows::Devices::Enumeration::Pnp::PnpObjectType type, iterable<hstring> requestedProperties) const
{
    Windows::Devices::Enumeration::Pnp::PnpObjectWatcher watcher { nullptr };
    check_hresult(WINRT_SHIM(IPnpObjectStatics)->abi_CreateWatcher(type, get_abi(requestedProperties), put_abi(watcher)));
    return watcher;
}

template <typename D> Windows::Devices::Enumeration::Pnp::PnpObjectWatcher impl_IPnpObjectStatics<D>::CreateWatcher(Windows::Devices::Enumeration::Pnp::PnpObjectType type, iterable<hstring> requestedProperties, hstring_view aqsFilter) const
{
    Windows::Devices::Enumeration::Pnp::PnpObjectWatcher watcher { nullptr };
    check_hresult(WINRT_SHIM(IPnpObjectStatics)->abi_CreateWatcherAqsFilter(type, get_abi(requestedProperties), get_abi(aqsFilter), put_abi(watcher)));
    return watcher;
}

template <typename D> Windows::Devices::Enumeration::Pnp::PnpObjectType impl_IPnpObject<D>::Type() const
{
    Windows::Devices::Enumeration::Pnp::PnpObjectType value {};
    check_hresult(WINRT_SHIM(IPnpObject)->get_Type(&value));
    return value;
}

template <typename D> hstring impl_IPnpObject<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPnpObject)->get_Id(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> impl_IPnpObject<D>::Properties() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> value;
    check_hresult(WINRT_SHIM(IPnpObject)->get_Properties(put_abi(value)));
    return value;
}

template <typename D> void impl_IPnpObject<D>::Update(const Windows::Devices::Enumeration::Pnp::PnpObjectUpdate & updateInfo) const
{
    check_hresult(WINRT_SHIM(IPnpObject)->abi_Update(get_abi(updateInfo)));
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::Pnp::PnpObject> PnpObject::CreateFromIdAsync(Windows::Devices::Enumeration::Pnp::PnpObjectType type, hstring_view id, iterable<hstring> requestedProperties)
{
    return get_activation_factory<PnpObject, IPnpObjectStatics>().CreateFromIdAsync(type, id, requestedProperties);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::Pnp::PnpObjectCollection> PnpObject::FindAllAsync(Windows::Devices::Enumeration::Pnp::PnpObjectType type, iterable<hstring> requestedProperties)
{
    return get_activation_factory<PnpObject, IPnpObjectStatics>().FindAllAsync(type, requestedProperties);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Enumeration::Pnp::PnpObjectCollection> PnpObject::FindAllAsync(Windows::Devices::Enumeration::Pnp::PnpObjectType type, iterable<hstring> requestedProperties, hstring_view aqsFilter)
{
    return get_activation_factory<PnpObject, IPnpObjectStatics>().FindAllAsync(type, requestedProperties, aqsFilter);
}

inline Windows::Devices::Enumeration::Pnp::PnpObjectWatcher PnpObject::CreateWatcher(Windows::Devices::Enumeration::Pnp::PnpObjectType type, iterable<hstring> requestedProperties)
{
    return get_activation_factory<PnpObject, IPnpObjectStatics>().CreateWatcher(type, requestedProperties);
}

inline Windows::Devices::Enumeration::Pnp::PnpObjectWatcher PnpObject::CreateWatcher(Windows::Devices::Enumeration::Pnp::PnpObjectType type, iterable<hstring> requestedProperties, hstring_view aqsFilter)
{
    return get_activation_factory<PnpObject, IPnpObjectStatics>().CreateWatcher(type, requestedProperties, aqsFilter);
}

}

}
#pragma warning(pop)
