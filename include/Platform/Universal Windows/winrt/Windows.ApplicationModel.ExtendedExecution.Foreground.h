// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.ApplicationModel.ExtendedExecution.Foreground.3.h"
#include "Windows.ApplicationModel.ExtendedExecution.h"
#include "Windows.Foundation.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundRevokedEventArgs> : produce_base<D, Windows::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundRevokedEventArgs>
{
    HRESULT __stdcall get_Reason(Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundRevokedReason * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Reason());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundSession> : produce_base<D, Windows::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundSession>
{
    HRESULT __stdcall get_Description(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Description());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Description(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Description(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Revoked(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundRevokedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Revoked(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundRevokedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Revoked(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Revoked(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestExtensionAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestExtensionAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Reason(Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundReason * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Reason());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Reason(Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundReason value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Reason(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::ApplicationModel::ExtendedExecution::Foreground {

template <typename D> Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundRevokedReason impl_IExtendedExecutionForegroundRevokedEventArgs<D>::Reason() const
{
    Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundRevokedReason value {};
    check_hresult(WINRT_SHIM(IExtendedExecutionForegroundRevokedEventArgs)->get_Reason(&value));
    return value;
}

template <typename D> hstring impl_IExtendedExecutionForegroundSession<D>::Description() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IExtendedExecutionForegroundSession)->get_Description(put_abi(value)));
    return value;
}

template <typename D> void impl_IExtendedExecutionForegroundSession<D>::Description(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IExtendedExecutionForegroundSession)->put_Description(get_abi(value)));
}

template <typename D> event_token impl_IExtendedExecutionForegroundSession<D>::Revoked(const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundRevokedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IExtendedExecutionForegroundSession)->add_Revoked(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IExtendedExecutionForegroundSession> impl_IExtendedExecutionForegroundSession<D>::Revoked(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundRevokedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IExtendedExecutionForegroundSession>(this, &ABI::Windows::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundSession::remove_Revoked, Revoked(handler));
}

template <typename D> void impl_IExtendedExecutionForegroundSession<D>::Revoked(event_token token) const
{
    check_hresult(WINRT_SHIM(IExtendedExecutionForegroundSession)->remove_Revoked(token));
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundResult> impl_IExtendedExecutionForegroundSession<D>::RequestExtensionAsync() const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundResult> operation;
    check_hresult(WINRT_SHIM(IExtendedExecutionForegroundSession)->abi_RequestExtensionAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundReason impl_IExtendedExecutionForegroundSession<D>::Reason() const
{
    Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundReason value {};
    check_hresult(WINRT_SHIM(IExtendedExecutionForegroundSession)->get_Reason(&value));
    return value;
}

template <typename D> void impl_IExtendedExecutionForegroundSession<D>::Reason(Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundReason value) const
{
    check_hresult(WINRT_SHIM(IExtendedExecutionForegroundSession)->put_Reason(value));
}

inline ExtendedExecutionForegroundSession::ExtendedExecutionForegroundSession() :
    ExtendedExecutionForegroundSession(activate_instance<ExtendedExecutionForegroundSession>())
{}

}

}
#pragma warning(pop)
