// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Security.Authentication.Identity.Core.3.h"
#include "Windows.Security.Authentication.Identity.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager> : produce_base<D, Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager>
{
    HRESULT __stdcall abi_GetOneTimePassCodeAsync(impl::abi_arg_in<hstring> userAccountId, uint32_t codeLength, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorOneTimeCodedInfo>> asyncOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOperation = detach_abi(this->shim().GetOneTimePassCodeAsync(*reinterpret_cast<const hstring *>(&userAccountId), codeLength));
            return S_OK;
        }
        catch (...)
        {
            *asyncOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddDeviceAsync(impl::abi_arg_in<hstring> userAccountId, impl::abi_arg_in<hstring> authenticationToken, impl::abi_arg_in<hstring> wnsChannelId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>> asyncOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOperation = detach_abi(this->shim().AddDeviceAsync(*reinterpret_cast<const hstring *>(&userAccountId), *reinterpret_cast<const hstring *>(&authenticationToken), *reinterpret_cast<const hstring *>(&wnsChannelId)));
            return S_OK;
        }
        catch (...)
        {
            *asyncOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveDeviceAsync(impl::abi_arg_in<hstring> userAccountId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>> asyncOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOperation = detach_abi(this->shim().RemoveDeviceAsync(*reinterpret_cast<const hstring *>(&userAccountId)));
            return S_OK;
        }
        catch (...)
        {
            *asyncOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UpdateWnsChannelAsync(impl::abi_arg_in<hstring> userAccountId, impl::abi_arg_in<hstring> channelUri, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>> asyncOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOperation = detach_abi(this->shim().UpdateWnsChannelAsync(*reinterpret_cast<const hstring *>(&userAccountId), *reinterpret_cast<const hstring *>(&channelUri)));
            return S_OK;
        }
        catch (...)
        {
            *asyncOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSessionsAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> userAccountIdList, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorGetSessionsResult>> asyncOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOperation = detach_abi(this->shim().GetSessionsAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&userAccountIdList)));
            return S_OK;
        }
        catch (...)
        {
            *asyncOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSessionsAndUnregisteredAccountsAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> userAccountIdList, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo>> asyncOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOperation = detach_abi(this->shim().GetSessionsAndUnregisteredAccountsAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&userAccountIdList)));
            return S_OK;
        }
        catch (...)
        {
            *asyncOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ApproveSessionUsingAuthSessionInfoAsync(Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionAuthenticationStatus sessionAuthentictionStatus, impl::abi_arg_in<Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo> authenticationSessionInfo, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>> asyncOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOperation = detach_abi(this->shim().ApproveSessionAsync(sessionAuthentictionStatus, *reinterpret_cast<const Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo *>(&authenticationSessionInfo)));
            return S_OK;
        }
        catch (...)
        {
            *asyncOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ApproveSessionAsync(Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionAuthenticationStatus sessionAuthentictionStatus, impl::abi_arg_in<hstring> userAccountId, impl::abi_arg_in<hstring> sessionId, Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationType sessionAuthenticationType, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>> asyncOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOperation = detach_abi(this->shim().ApproveSessionAsync(sessionAuthentictionStatus, *reinterpret_cast<const hstring *>(&userAccountId), *reinterpret_cast<const hstring *>(&sessionId), sessionAuthenticationType));
            return S_OK;
        }
        catch (...)
        {
            *asyncOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DenySessionUsingAuthSessionInfoAsync(impl::abi_arg_in<Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo> authenticationSessionInfo, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>> asyncOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOperation = detach_abi(this->shim().DenySessionAsync(*reinterpret_cast<const Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo *>(&authenticationSessionInfo)));
            return S_OK;
        }
        catch (...)
        {
            *asyncOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DenySessionAsync(impl::abi_arg_in<hstring> userAccountId, impl::abi_arg_in<hstring> sessionId, Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationType sessionAuthenticationType, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>> asyncOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOperation = detach_abi(this->shim().DenySessionAsync(*reinterpret_cast<const hstring *>(&userAccountId), *reinterpret_cast<const hstring *>(&sessionId), sessionAuthenticationType));
            return S_OK;
        }
        catch (...)
        {
            *asyncOperation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticatorStatics> : produce_base<D, Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticatorStatics>
{
    HRESULT __stdcall get_Current(impl::abi_arg_out<Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Current());
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
struct produce<D, Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorGetSessionsResult> : produce_base<D, Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorGetSessionsResult>
{
    HRESULT __stdcall get_Sessions(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Sessions());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServiceResponse(Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServiceResponse());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorOneTimeCodedInfo> : produce_base<D, Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorOneTimeCodedInfo>
{
    HRESULT __stdcall get_Code(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Code());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TimeInterval(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TimeInterval());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TimeToLive(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TimeToLive());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServiceResponse(Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServiceResponse());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo> : produce_base<D, Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo>
{
    HRESULT __stdcall get_UserAccountId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UserAccountId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall get_DisplaySessionId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplaySessionId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ApprovalStatus(Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionApprovalStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ApprovalStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AuthenticationType(Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AuthenticationType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RequestTime(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequestTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExpirationTime(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExpirationTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo> : produce_base<D, Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo>
{
    HRESULT __stdcall get_Sessions(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Sessions());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UnregisteredAccounts(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UnregisteredAccounts());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServiceResponse(Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServiceResponse());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Security::Authentication::Identity::Core {

template <typename D> hstring impl_IMicrosoftAccountMultiFactorSessionInfo<D>::UserAccountId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMicrosoftAccountMultiFactorSessionInfo)->get_UserAccountId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMicrosoftAccountMultiFactorSessionInfo<D>::SessionId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMicrosoftAccountMultiFactorSessionInfo)->get_SessionId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMicrosoftAccountMultiFactorSessionInfo<D>::DisplaySessionId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMicrosoftAccountMultiFactorSessionInfo)->get_DisplaySessionId(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionApprovalStatus impl_IMicrosoftAccountMultiFactorSessionInfo<D>::ApprovalStatus() const
{
    Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionApprovalStatus value {};
    check_hresult(WINRT_SHIM(IMicrosoftAccountMultiFactorSessionInfo)->get_ApprovalStatus(&value));
    return value;
}

template <typename D> Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationType impl_IMicrosoftAccountMultiFactorSessionInfo<D>::AuthenticationType() const
{
    Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationType value {};
    check_hresult(WINRT_SHIM(IMicrosoftAccountMultiFactorSessionInfo)->get_AuthenticationType(&value));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IMicrosoftAccountMultiFactorSessionInfo<D>::RequestTime() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IMicrosoftAccountMultiFactorSessionInfo)->get_RequestTime(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IMicrosoftAccountMultiFactorSessionInfo<D>::ExpirationTime() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IMicrosoftAccountMultiFactorSessionInfo)->get_ExpirationTime(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo> impl_IMicrosoftAccountMultiFactorGetSessionsResult<D>::Sessions() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo> value;
    check_hresult(WINRT_SHIM(IMicrosoftAccountMultiFactorGetSessionsResult)->get_Sessions(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse impl_IMicrosoftAccountMultiFactorGetSessionsResult<D>::ServiceResponse() const
{
    Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse value {};
    check_hresult(WINRT_SHIM(IMicrosoftAccountMultiFactorGetSessionsResult)->get_ServiceResponse(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo> impl_IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo<D>::Sessions() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo> value;
    check_hresult(WINRT_SHIM(IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo)->get_Sessions(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo<D>::UnregisteredAccounts() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo)->get_UnregisteredAccounts(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse impl_IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo<D>::ServiceResponse() const
{
    Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse value {};
    check_hresult(WINRT_SHIM(IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo)->get_ServiceResponse(&value));
    return value;
}

template <typename D> hstring impl_IMicrosoftAccountMultiFactorOneTimeCodedInfo<D>::Code() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMicrosoftAccountMultiFactorOneTimeCodedInfo)->get_Code(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IMicrosoftAccountMultiFactorOneTimeCodedInfo<D>::TimeInterval() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMicrosoftAccountMultiFactorOneTimeCodedInfo)->get_TimeInterval(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IMicrosoftAccountMultiFactorOneTimeCodedInfo<D>::TimeToLive() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IMicrosoftAccountMultiFactorOneTimeCodedInfo)->get_TimeToLive(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse impl_IMicrosoftAccountMultiFactorOneTimeCodedInfo<D>::ServiceResponse() const
{
    Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse value {};
    check_hresult(WINRT_SHIM(IMicrosoftAccountMultiFactorOneTimeCodedInfo)->get_ServiceResponse(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorOneTimeCodedInfo> impl_IMicrosoftAccountMultiFactorAuthenticationManager<D>::GetOneTimePassCodeAsync(hstring_view userAccountId, uint32_t codeLength) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorOneTimeCodedInfo> asyncOperation;
    check_hresult(WINRT_SHIM(IMicrosoftAccountMultiFactorAuthenticationManager)->abi_GetOneTimePassCodeAsync(get_abi(userAccountId), codeLength, put_abi(asyncOperation)));
    return asyncOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse> impl_IMicrosoftAccountMultiFactorAuthenticationManager<D>::AddDeviceAsync(hstring_view userAccountId, hstring_view authenticationToken, hstring_view wnsChannelId) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse> asyncOperation;
    check_hresult(WINRT_SHIM(IMicrosoftAccountMultiFactorAuthenticationManager)->abi_AddDeviceAsync(get_abi(userAccountId), get_abi(authenticationToken), get_abi(wnsChannelId), put_abi(asyncOperation)));
    return asyncOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse> impl_IMicrosoftAccountMultiFactorAuthenticationManager<D>::RemoveDeviceAsync(hstring_view userAccountId) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse> asyncOperation;
    check_hresult(WINRT_SHIM(IMicrosoftAccountMultiFactorAuthenticationManager)->abi_RemoveDeviceAsync(get_abi(userAccountId), put_abi(asyncOperation)));
    return asyncOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse> impl_IMicrosoftAccountMultiFactorAuthenticationManager<D>::UpdateWnsChannelAsync(hstring_view userAccountId, hstring_view channelUri) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse> asyncOperation;
    check_hresult(WINRT_SHIM(IMicrosoftAccountMultiFactorAuthenticationManager)->abi_UpdateWnsChannelAsync(get_abi(userAccountId), get_abi(channelUri), put_abi(asyncOperation)));
    return asyncOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorGetSessionsResult> impl_IMicrosoftAccountMultiFactorAuthenticationManager<D>::GetSessionsAsync(iterable<hstring> userAccountIdList) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorGetSessionsResult> asyncOperation;
    check_hresult(WINRT_SHIM(IMicrosoftAccountMultiFactorAuthenticationManager)->abi_GetSessionsAsync(get_abi(userAccountIdList), put_abi(asyncOperation)));
    return asyncOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo> impl_IMicrosoftAccountMultiFactorAuthenticationManager<D>::GetSessionsAndUnregisteredAccountsAsync(iterable<hstring> userAccountIdList) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo> asyncOperation;
    check_hresult(WINRT_SHIM(IMicrosoftAccountMultiFactorAuthenticationManager)->abi_GetSessionsAndUnregisteredAccountsAsync(get_abi(userAccountIdList), put_abi(asyncOperation)));
    return asyncOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse> impl_IMicrosoftAccountMultiFactorAuthenticationManager<D>::ApproveSessionAsync(Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionAuthenticationStatus sessionAuthentictionStatus, const Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo & authenticationSessionInfo) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse> asyncOperation;
    check_hresult(WINRT_SHIM(IMicrosoftAccountMultiFactorAuthenticationManager)->abi_ApproveSessionUsingAuthSessionInfoAsync(sessionAuthentictionStatus, get_abi(authenticationSessionInfo), put_abi(asyncOperation)));
    return asyncOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse> impl_IMicrosoftAccountMultiFactorAuthenticationManager<D>::ApproveSessionAsync(Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionAuthenticationStatus sessionAuthentictionStatus, hstring_view userAccountId, hstring_view sessionId, Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationType sessionAuthenticationType) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse> asyncOperation;
    check_hresult(WINRT_SHIM(IMicrosoftAccountMultiFactorAuthenticationManager)->abi_ApproveSessionAsync(sessionAuthentictionStatus, get_abi(userAccountId), get_abi(sessionId), sessionAuthenticationType, put_abi(asyncOperation)));
    return asyncOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse> impl_IMicrosoftAccountMultiFactorAuthenticationManager<D>::DenySessionAsync(const Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo & authenticationSessionInfo) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse> asyncOperation;
    check_hresult(WINRT_SHIM(IMicrosoftAccountMultiFactorAuthenticationManager)->abi_DenySessionUsingAuthSessionInfoAsync(get_abi(authenticationSessionInfo), put_abi(asyncOperation)));
    return asyncOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse> impl_IMicrosoftAccountMultiFactorAuthenticationManager<D>::DenySessionAsync(hstring_view userAccountId, hstring_view sessionId, Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationType sessionAuthenticationType) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse> asyncOperation;
    check_hresult(WINRT_SHIM(IMicrosoftAccountMultiFactorAuthenticationManager)->abi_DenySessionAsync(get_abi(userAccountId), get_abi(sessionId), sessionAuthenticationType, put_abi(asyncOperation)));
    return asyncOperation;
}

template <typename D> Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationManager impl_IMicrosoftAccountMultiFactorAuthenticatorStatics<D>::Current() const
{
    Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationManager value { nullptr };
    check_hresult(WINRT_SHIM(IMicrosoftAccountMultiFactorAuthenticatorStatics)->get_Current(put_abi(value)));
    return value;
}

inline Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationManager MicrosoftAccountMultiFactorAuthenticationManager::Current()
{
    return get_activation_factory<MicrosoftAccountMultiFactorAuthenticationManager, IMicrosoftAccountMultiFactorAuthenticatorStatics>().Current();
}

}

}
#pragma warning(pop)
