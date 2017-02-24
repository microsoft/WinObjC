// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.ApplicationModel.Contacts.3.h"
#include "internal/Windows.ApplicationModel.Contacts.DataProvider.3.h"
#include "Windows.ApplicationModel.Contacts.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::Contacts::DataProvider::IContactDataProviderConnection> : produce_base<D, Windows::ApplicationModel::Contacts::DataProvider::IContactDataProviderConnection>
{
    HRESULT __stdcall add_SyncRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Contacts::DataProvider::ContactDataProviderConnection, Windows::ApplicationModel::Contacts::DataProvider::ContactListSyncManagerSyncRequestEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().SyncRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Contacts::DataProvider::ContactDataProviderConnection, Windows::ApplicationModel::Contacts::DataProvider::ContactListSyncManagerSyncRequestEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SyncRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SyncRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ServerSearchReadBatchRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Contacts::DataProvider::ContactDataProviderConnection, Windows::ApplicationModel::Contacts::DataProvider::ContactListServerSearchReadBatchRequestEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ServerSearchReadBatchRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Contacts::DataProvider::ContactDataProviderConnection, Windows::ApplicationModel::Contacts::DataProvider::ContactListServerSearchReadBatchRequestEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ServerSearchReadBatchRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ServerSearchReadBatchRequested(token);
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
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Contacts::DataProvider::IContactDataProviderTriggerDetails> : produce_base<D, Windows::ApplicationModel::Contacts::DataProvider::IContactDataProviderTriggerDetails>
{
    HRESULT __stdcall get_Connection(impl::abi_arg_out<Windows::ApplicationModel::Contacts::DataProvider::IContactDataProviderConnection> value) noexcept override
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
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequest> : produce_base<D, Windows::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequest>
{
    HRESULT __stdcall get_SessionId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SessionId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContactListId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContactListId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Options(impl::abi_arg_out<Windows::ApplicationModel::Contacts::IContactQueryOptions> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Options());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SuggestedBatchSize(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SuggestedBatchSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SaveContactAsync(impl::abi_arg_in<Windows::ApplicationModel::Contacts::IContact> contact, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().SaveContactAsync(*reinterpret_cast<const Windows::ApplicationModel::Contacts::Contact *>(&contact)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportCompletedAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReportCompletedAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportFailedAsync(Windows::ApplicationModel::Contacts::ContactBatchStatus batchStatus, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReportFailedAsync(batchStatus));
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
struct produce<D, Windows::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequestEventArgs> : produce_base<D, Windows::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequestEventArgs>
{
    HRESULT __stdcall get_Request(impl::abi_arg_out<Windows::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequest> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Request());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDeferral());
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
struct produce<D, Windows::ApplicationModel::Contacts::DataProvider::IContactListSyncManagerSyncRequest> : produce_base<D, Windows::ApplicationModel::Contacts::DataProvider::IContactListSyncManagerSyncRequest>
{
    HRESULT __stdcall get_ContactListId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContactListId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportCompletedAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReportCompletedAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportFailedAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReportFailedAsync());
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
struct produce<D, Windows::ApplicationModel::Contacts::DataProvider::IContactListSyncManagerSyncRequestEventArgs> : produce_base<D, Windows::ApplicationModel::Contacts::DataProvider::IContactListSyncManagerSyncRequestEventArgs>
{
    HRESULT __stdcall get_Request(impl::abi_arg_out<Windows::ApplicationModel::Contacts::DataProvider::IContactListSyncManagerSyncRequest> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Request());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDeferral());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::ApplicationModel::Contacts::DataProvider {

template <typename D> Windows::ApplicationModel::Contacts::DataProvider::ContactDataProviderConnection impl_IContactDataProviderTriggerDetails<D>::Connection() const
{
    Windows::ApplicationModel::Contacts::DataProvider::ContactDataProviderConnection value { nullptr };
    check_hresult(WINRT_SHIM(IContactDataProviderTriggerDetails)->get_Connection(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IContactDataProviderConnection<D>::SyncRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Contacts::DataProvider::ContactDataProviderConnection, Windows::ApplicationModel::Contacts::DataProvider::ContactListSyncManagerSyncRequestEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IContactDataProviderConnection)->add_SyncRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IContactDataProviderConnection> impl_IContactDataProviderConnection<D>::SyncRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Contacts::DataProvider::ContactDataProviderConnection, Windows::ApplicationModel::Contacts::DataProvider::ContactListSyncManagerSyncRequestEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IContactDataProviderConnection>(this, &ABI::Windows::ApplicationModel::Contacts::DataProvider::IContactDataProviderConnection::remove_SyncRequested, SyncRequested(handler));
}

template <typename D> void impl_IContactDataProviderConnection<D>::SyncRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IContactDataProviderConnection)->remove_SyncRequested(token));
}

template <typename D> event_token impl_IContactDataProviderConnection<D>::ServerSearchReadBatchRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Contacts::DataProvider::ContactDataProviderConnection, Windows::ApplicationModel::Contacts::DataProvider::ContactListServerSearchReadBatchRequestEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IContactDataProviderConnection)->add_ServerSearchReadBatchRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IContactDataProviderConnection> impl_IContactDataProviderConnection<D>::ServerSearchReadBatchRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Contacts::DataProvider::ContactDataProviderConnection, Windows::ApplicationModel::Contacts::DataProvider::ContactListServerSearchReadBatchRequestEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IContactDataProviderConnection>(this, &ABI::Windows::ApplicationModel::Contacts::DataProvider::IContactDataProviderConnection::remove_ServerSearchReadBatchRequested, ServerSearchReadBatchRequested(handler));
}

template <typename D> void impl_IContactDataProviderConnection<D>::ServerSearchReadBatchRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IContactDataProviderConnection)->remove_ServerSearchReadBatchRequested(token));
}

template <typename D> void impl_IContactDataProviderConnection<D>::Start() const
{
    check_hresult(WINRT_SHIM(IContactDataProviderConnection)->abi_Start());
}

template <typename D> hstring impl_IContactListSyncManagerSyncRequest<D>::ContactListId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactListSyncManagerSyncRequest)->get_ContactListId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IContactListSyncManagerSyncRequest<D>::ReportCompletedAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IContactListSyncManagerSyncRequest)->abi_ReportCompletedAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IContactListSyncManagerSyncRequest<D>::ReportFailedAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IContactListSyncManagerSyncRequest)->abi_ReportFailedAsync(put_abi(result)));
    return result;
}

template <typename D> hstring impl_IContactListServerSearchReadBatchRequest<D>::SessionId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactListServerSearchReadBatchRequest)->get_SessionId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContactListServerSearchReadBatchRequest<D>::ContactListId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactListServerSearchReadBatchRequest)->get_ContactListId(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Contacts::ContactQueryOptions impl_IContactListServerSearchReadBatchRequest<D>::Options() const
{
    Windows::ApplicationModel::Contacts::ContactQueryOptions value { nullptr };
    check_hresult(WINRT_SHIM(IContactListServerSearchReadBatchRequest)->get_Options(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IContactListServerSearchReadBatchRequest<D>::SuggestedBatchSize() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IContactListServerSearchReadBatchRequest)->get_SuggestedBatchSize(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IContactListServerSearchReadBatchRequest<D>::SaveContactAsync(const Windows::ApplicationModel::Contacts::Contact & contact) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IContactListServerSearchReadBatchRequest)->abi_SaveContactAsync(get_abi(contact), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IContactListServerSearchReadBatchRequest<D>::ReportCompletedAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IContactListServerSearchReadBatchRequest)->abi_ReportCompletedAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IContactListServerSearchReadBatchRequest<D>::ReportFailedAsync(Windows::ApplicationModel::Contacts::ContactBatchStatus batchStatus) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IContactListServerSearchReadBatchRequest)->abi_ReportFailedAsync(batchStatus, put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Contacts::DataProvider::ContactListSyncManagerSyncRequest impl_IContactListSyncManagerSyncRequestEventArgs<D>::Request() const
{
    Windows::ApplicationModel::Contacts::DataProvider::ContactListSyncManagerSyncRequest value { nullptr };
    check_hresult(WINRT_SHIM(IContactListSyncManagerSyncRequestEventArgs)->get_Request(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Deferral impl_IContactListSyncManagerSyncRequestEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(WINRT_SHIM(IContactListSyncManagerSyncRequestEventArgs)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Contacts::DataProvider::ContactListServerSearchReadBatchRequest impl_IContactListServerSearchReadBatchRequestEventArgs<D>::Request() const
{
    Windows::ApplicationModel::Contacts::DataProvider::ContactListServerSearchReadBatchRequest value { nullptr };
    check_hresult(WINRT_SHIM(IContactListServerSearchReadBatchRequestEventArgs)->get_Request(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Deferral impl_IContactListServerSearchReadBatchRequestEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral value { nullptr };
    check_hresult(WINRT_SHIM(IContactListServerSearchReadBatchRequestEventArgs)->abi_GetDeferral(put_abi(value)));
    return value;
}

}

}
#pragma warning(pop)
