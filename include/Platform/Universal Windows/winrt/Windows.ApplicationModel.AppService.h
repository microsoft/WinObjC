// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.System.RemoteSystems.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.System.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.ApplicationModel.AppService.3.h"
#include "Windows.ApplicationModel.h"
#include "Windows.Foundation.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::AppService::IAppServiceCatalogStatics> : produce_base<D, Windows::ApplicationModel::AppService::IAppServiceCatalogStatics>
{
    HRESULT __stdcall abi_FindAppServiceProvidersAsync(impl::abi_arg_in<hstring> appServiceName, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::AppInfo>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FindAppServiceProvidersAsync(*reinterpret_cast<const hstring *>(&appServiceName)));
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
struct produce<D, Windows::ApplicationModel::AppService::IAppServiceClosedEventArgs> : produce_base<D, Windows::ApplicationModel::AppService::IAppServiceClosedEventArgs>
{
    HRESULT __stdcall get_Status(Windows::ApplicationModel::AppService::AppServiceClosedStatus * value) noexcept override
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
};

template <typename D>
struct produce<D, Windows::ApplicationModel::AppService::IAppServiceConnection> : produce_base<D, Windows::ApplicationModel::AppService::IAppServiceConnection>
{
    HRESULT __stdcall get_AppServiceName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AppServiceName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AppServiceName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AppServiceName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PackageFamilyName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PackageFamilyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PackageFamilyName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PackageFamilyName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OpenAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::AppService::AppServiceConnectionStatus>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().OpenAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SendMessageAsync(impl::abi_arg_in<Windows::Foundation::Collections::IPropertySet> message, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::AppService::AppServiceResponse>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().SendMessageAsync(*reinterpret_cast<const Windows::Foundation::Collections::ValueSet *>(&message)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_RequestReceived(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::AppService::AppServiceConnection, Windows::ApplicationModel::AppService::AppServiceRequestReceivedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().RequestReceived(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::AppService::AppServiceConnection, Windows::ApplicationModel::AppService::AppServiceRequestReceivedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_RequestReceived(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequestReceived(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ServiceClosed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::AppService::AppServiceConnection, Windows::ApplicationModel::AppService::AppServiceClosedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ServiceClosed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::AppService::AppServiceConnection, Windows::ApplicationModel::AppService::AppServiceClosedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ServiceClosed(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ServiceClosed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::AppService::IAppServiceConnection2> : produce_base<D, Windows::ApplicationModel::AppService::IAppServiceConnection2>
{
    HRESULT __stdcall abi_OpenRemoteAsync(impl::abi_arg_in<Windows::System::RemoteSystems::IRemoteSystemConnectionRequest> remoteSystemConnectionRequest, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::AppService::AppServiceConnectionStatus>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().OpenRemoteAsync(*reinterpret_cast<const Windows::System::RemoteSystems::RemoteSystemConnectionRequest *>(&remoteSystemConnectionRequest)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_User(impl::abi_arg_out<Windows::System::IUser> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().User());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_User(impl::abi_arg_in<Windows::System::IUser> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().User(*reinterpret_cast<const Windows::System::User *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::AppService::IAppServiceDeferral> : produce_base<D, Windows::ApplicationModel::AppService::IAppServiceDeferral>
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
struct produce<D, Windows::ApplicationModel::AppService::IAppServiceRequest> : produce_base<D, Windows::ApplicationModel::AppService::IAppServiceRequest>
{
    HRESULT __stdcall get_Message(impl::abi_arg_out<Windows::Foundation::Collections::IPropertySet> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Message());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SendResponseAsync(impl::abi_arg_in<Windows::Foundation::Collections::IPropertySet> message, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::AppService::AppServiceResponseStatus>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().SendResponseAsync(*reinterpret_cast<const Windows::Foundation::Collections::ValueSet *>(&message)));
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
struct produce<D, Windows::ApplicationModel::AppService::IAppServiceRequestReceivedEventArgs> : produce_base<D, Windows::ApplicationModel::AppService::IAppServiceRequestReceivedEventArgs>
{
    HRESULT __stdcall get_Request(impl::abi_arg_out<Windows::ApplicationModel::AppService::IAppServiceRequest> value) noexcept override
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

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::ApplicationModel::AppService::IAppServiceDeferral> value) noexcept override
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
struct produce<D, Windows::ApplicationModel::AppService::IAppServiceResponse> : produce_base<D, Windows::ApplicationModel::AppService::IAppServiceResponse>
{
    HRESULT __stdcall get_Message(impl::abi_arg_out<Windows::Foundation::Collections::IPropertySet> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Message());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Status(Windows::ApplicationModel::AppService::AppServiceResponseStatus * value) noexcept override
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
};

template <typename D>
struct produce<D, Windows::ApplicationModel::AppService::IAppServiceTriggerDetails> : produce_base<D, Windows::ApplicationModel::AppService::IAppServiceTriggerDetails>
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

    HRESULT __stdcall get_CallerPackageFamilyName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CallerPackageFamilyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AppServiceConnection(impl::abi_arg_out<Windows::ApplicationModel::AppService::IAppServiceConnection> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AppServiceConnection());
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
struct produce<D, Windows::ApplicationModel::AppService::IAppServiceTriggerDetails2> : produce_base<D, Windows::ApplicationModel::AppService::IAppServiceTriggerDetails2>
{
    HRESULT __stdcall get_IsRemoteSystemConnection(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsRemoteSystemConnection());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::ApplicationModel::AppService {

template <typename D> void impl_IAppServiceDeferral<D>::Complete() const
{
    check_hresult(WINRT_SHIM(IAppServiceDeferral)->abi_Complete());
}

template <typename D> Windows::ApplicationModel::AppService::AppServiceClosedStatus impl_IAppServiceClosedEventArgs<D>::Status() const
{
    Windows::ApplicationModel::AppService::AppServiceClosedStatus value {};
    check_hresult(WINRT_SHIM(IAppServiceClosedEventArgs)->get_Status(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::AppService::AppServiceRequest impl_IAppServiceRequestReceivedEventArgs<D>::Request() const
{
    Windows::ApplicationModel::AppService::AppServiceRequest value { nullptr };
    check_hresult(WINRT_SHIM(IAppServiceRequestReceivedEventArgs)->get_Request(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::AppService::AppServiceDeferral impl_IAppServiceRequestReceivedEventArgs<D>::GetDeferral() const
{
    Windows::ApplicationModel::AppService::AppServiceDeferral value { nullptr };
    check_hresult(WINRT_SHIM(IAppServiceRequestReceivedEventArgs)->abi_GetDeferral(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::AppService::AppServiceConnectionStatus> impl_IAppServiceConnection2<D>::OpenRemoteAsync(const Windows::System::RemoteSystems::RemoteSystemConnectionRequest & remoteSystemConnectionRequest) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::AppService::AppServiceConnectionStatus> operation;
    check_hresult(WINRT_SHIM(IAppServiceConnection2)->abi_OpenRemoteAsync(get_abi(remoteSystemConnectionRequest), put_abi(operation)));
    return operation;
}

template <typename D> Windows::System::User impl_IAppServiceConnection2<D>::User() const
{
    Windows::System::User value { nullptr };
    check_hresult(WINRT_SHIM(IAppServiceConnection2)->get_User(put_abi(value)));
    return value;
}

template <typename D> void impl_IAppServiceConnection2<D>::User(const Windows::System::User & value) const
{
    check_hresult(WINRT_SHIM(IAppServiceConnection2)->put_User(get_abi(value)));
}

template <typename D> hstring impl_IAppServiceTriggerDetails<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppServiceTriggerDetails)->get_Name(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppServiceTriggerDetails<D>::CallerPackageFamilyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppServiceTriggerDetails)->get_CallerPackageFamilyName(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::AppService::AppServiceConnection impl_IAppServiceTriggerDetails<D>::AppServiceConnection() const
{
    Windows::ApplicationModel::AppService::AppServiceConnection value { nullptr };
    check_hresult(WINRT_SHIM(IAppServiceTriggerDetails)->get_AppServiceConnection(put_abi(value)));
    return value;
}

template <typename D> bool impl_IAppServiceTriggerDetails2<D>::IsRemoteSystemConnection() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IAppServiceTriggerDetails2)->get_IsRemoteSystemConnection(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::ValueSet impl_IAppServiceRequest<D>::Message() const
{
    Windows::Foundation::Collections::ValueSet value { nullptr };
    check_hresult(WINRT_SHIM(IAppServiceRequest)->get_Message(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::AppService::AppServiceResponseStatus> impl_IAppServiceRequest<D>::SendResponseAsync(const Windows::Foundation::Collections::ValueSet & message) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::AppService::AppServiceResponseStatus> operation;
    check_hresult(WINRT_SHIM(IAppServiceRequest)->abi_SendResponseAsync(get_abi(message), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::Collections::ValueSet impl_IAppServiceResponse<D>::Message() const
{
    Windows::Foundation::Collections::ValueSet value { nullptr };
    check_hresult(WINRT_SHIM(IAppServiceResponse)->get_Message(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::AppService::AppServiceResponseStatus impl_IAppServiceResponse<D>::Status() const
{
    Windows::ApplicationModel::AppService::AppServiceResponseStatus value {};
    check_hresult(WINRT_SHIM(IAppServiceResponse)->get_Status(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::AppInfo>> impl_IAppServiceCatalogStatics<D>::FindAppServiceProvidersAsync(hstring_view appServiceName) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::AppInfo>> operation;
    check_hresult(WINRT_SHIM(IAppServiceCatalogStatics)->abi_FindAppServiceProvidersAsync(get_abi(appServiceName), put_abi(operation)));
    return operation;
}

template <typename D> hstring impl_IAppServiceConnection<D>::AppServiceName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppServiceConnection)->get_AppServiceName(put_abi(value)));
    return value;
}

template <typename D> void impl_IAppServiceConnection<D>::AppServiceName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IAppServiceConnection)->put_AppServiceName(get_abi(value)));
}

template <typename D> hstring impl_IAppServiceConnection<D>::PackageFamilyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppServiceConnection)->get_PackageFamilyName(put_abi(value)));
    return value;
}

template <typename D> void impl_IAppServiceConnection<D>::PackageFamilyName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IAppServiceConnection)->put_PackageFamilyName(get_abi(value)));
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::AppService::AppServiceConnectionStatus> impl_IAppServiceConnection<D>::OpenAsync() const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::AppService::AppServiceConnectionStatus> operation;
    check_hresult(WINRT_SHIM(IAppServiceConnection)->abi_OpenAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::AppService::AppServiceResponse> impl_IAppServiceConnection<D>::SendMessageAsync(const Windows::Foundation::Collections::ValueSet & message) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::AppService::AppServiceResponse> operation;
    check_hresult(WINRT_SHIM(IAppServiceConnection)->abi_SendMessageAsync(get_abi(message), put_abi(operation)));
    return operation;
}

template <typename D> event_token impl_IAppServiceConnection<D>::RequestReceived(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::AppService::AppServiceConnection, Windows::ApplicationModel::AppService::AppServiceRequestReceivedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IAppServiceConnection)->add_RequestReceived(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IAppServiceConnection> impl_IAppServiceConnection<D>::RequestReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::AppService::AppServiceConnection, Windows::ApplicationModel::AppService::AppServiceRequestReceivedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IAppServiceConnection>(this, &ABI::Windows::ApplicationModel::AppService::IAppServiceConnection::remove_RequestReceived, RequestReceived(handler));
}

template <typename D> void impl_IAppServiceConnection<D>::RequestReceived(event_token token) const
{
    check_hresult(WINRT_SHIM(IAppServiceConnection)->remove_RequestReceived(token));
}

template <typename D> event_token impl_IAppServiceConnection<D>::ServiceClosed(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::AppService::AppServiceConnection, Windows::ApplicationModel::AppService::AppServiceClosedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IAppServiceConnection)->add_ServiceClosed(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IAppServiceConnection> impl_IAppServiceConnection<D>::ServiceClosed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::AppService::AppServiceConnection, Windows::ApplicationModel::AppService::AppServiceClosedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IAppServiceConnection>(this, &ABI::Windows::ApplicationModel::AppService::IAppServiceConnection::remove_ServiceClosed, ServiceClosed(handler));
}

template <typename D> void impl_IAppServiceConnection<D>::ServiceClosed(event_token token) const
{
    check_hresult(WINRT_SHIM(IAppServiceConnection)->remove_ServiceClosed(token));
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::AppInfo>> AppServiceCatalog::FindAppServiceProvidersAsync(hstring_view appServiceName)
{
    return get_activation_factory<AppServiceCatalog, IAppServiceCatalogStatics>().FindAppServiceProvidersAsync(appServiceName);
}

inline AppServiceConnection::AppServiceConnection() :
    AppServiceConnection(activate_instance<AppServiceConnection>())
{}

}

}
#pragma warning(pop)
