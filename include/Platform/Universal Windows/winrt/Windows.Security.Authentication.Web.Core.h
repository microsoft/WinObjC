// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Security.Credentials.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.System.3.h"
#include "internal/Windows.Security.Authentication.Web.Core.3.h"
#include "Windows.Security.Authentication.Web.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Security::Authentication::Web::Core::IWebAccountEventArgs> : produce_base<D, Windows::Security::Authentication::Web::Core::IWebAccountEventArgs>
{
    HRESULT __stdcall get_Account(impl::abi_arg_out<Windows::Security::Credentials::IWebAccount> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Account());
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
struct produce<D, Windows::Security::Authentication::Web::Core::IWebAccountMonitor> : produce_base<D, Windows::Security::Authentication::Web::Core::IWebAccountMonitor>
{
    HRESULT __stdcall add_Updated(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Security::Authentication::Web::Core::WebAccountMonitor, Windows::Security::Authentication::Web::Core::WebAccountEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Updated(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Security::Authentication::Web::Core::WebAccountMonitor, Windows::Security::Authentication::Web::Core::WebAccountEventArgs> *>(&handler)));
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

    HRESULT __stdcall add_Removed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Security::Authentication::Web::Core::WebAccountMonitor, Windows::Security::Authentication::Web::Core::WebAccountEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Removed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Security::Authentication::Web::Core::WebAccountMonitor, Windows::Security::Authentication::Web::Core::WebAccountEventArgs> *>(&handler)));
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

    HRESULT __stdcall add_DefaultSignInAccountChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Security::Authentication::Web::Core::WebAccountMonitor, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().DefaultSignInAccountChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Security::Authentication::Web::Core::WebAccountMonitor, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DefaultSignInAccountChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DefaultSignInAccountChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics> : produce_base<D, Windows::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics>
{
    HRESULT __stdcall abi_GetTokenSilentlyAsync(impl::abi_arg_in<Windows::Security::Authentication::Web::Core::IWebTokenRequest> request, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::Core::WebTokenRequestResult>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().GetTokenSilentlyAsync(*reinterpret_cast<const Windows::Security::Authentication::Web::Core::WebTokenRequest *>(&request)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetTokenSilentlyWithWebAccountAsync(impl::abi_arg_in<Windows::Security::Authentication::Web::Core::IWebTokenRequest> request, impl::abi_arg_in<Windows::Security::Credentials::IWebAccount> webAccount, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::Core::WebTokenRequestResult>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().GetTokenSilentlyAsync(*reinterpret_cast<const Windows::Security::Authentication::Web::Core::WebTokenRequest *>(&request), *reinterpret_cast<const Windows::Security::Credentials::WebAccount *>(&webAccount)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestTokenAsync(impl::abi_arg_in<Windows::Security::Authentication::Web::Core::IWebTokenRequest> request, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::Core::WebTokenRequestResult>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().RequestTokenAsync(*reinterpret_cast<const Windows::Security::Authentication::Web::Core::WebTokenRequest *>(&request)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestTokenWithWebAccountAsync(impl::abi_arg_in<Windows::Security::Authentication::Web::Core::IWebTokenRequest> request, impl::abi_arg_in<Windows::Security::Credentials::IWebAccount> webAccount, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::Core::WebTokenRequestResult>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().RequestTokenAsync(*reinterpret_cast<const Windows::Security::Authentication::Web::Core::WebTokenRequest *>(&request), *reinterpret_cast<const Windows::Security::Credentials::WebAccount *>(&webAccount)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAccountAsync(impl::abi_arg_in<Windows::Security::Credentials::IWebAccountProvider> provider, impl::abi_arg_in<hstring> webAccountId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccount>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().FindAccountAsync(*reinterpret_cast<const Windows::Security::Credentials::WebAccountProvider *>(&provider), *reinterpret_cast<const hstring *>(&webAccountId)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAccountProviderAsync(impl::abi_arg_in<hstring> webAccountProviderId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccountProvider>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().FindAccountProviderAsync(*reinterpret_cast<const hstring *>(&webAccountProviderId)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAccountProviderWithAuthorityAsync(impl::abi_arg_in<hstring> webAccountProviderId, impl::abi_arg_in<hstring> authority, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccountProvider>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().FindAccountProviderAsync(*reinterpret_cast<const hstring *>(&webAccountProviderId), *reinterpret_cast<const hstring *>(&authority)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics2> : produce_base<D, Windows::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics2>
{
    HRESULT __stdcall abi_FindAccountProviderWithAuthorityForUserAsync(impl::abi_arg_in<hstring> webAccountProviderId, impl::abi_arg_in<hstring> authority, impl::abi_arg_in<Windows::System::IUser> user, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccountProvider>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().FindAccountProviderAsync(*reinterpret_cast<const hstring *>(&webAccountProviderId), *reinterpret_cast<const hstring *>(&authority), *reinterpret_cast<const Windows::System::User *>(&user)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics3> : produce_base<D, Windows::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics3>
{
    HRESULT __stdcall abi_CreateWebAccountMonitor(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Security::Credentials::WebAccount>> webAccounts, impl::abi_arg_out<Windows::Security::Authentication::Web::Core::IWebAccountMonitor> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateWebAccountMonitor(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Security::Credentials::WebAccount> *>(&webAccounts)));
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
struct produce<D, Windows::Security::Authentication::Web::Core::IWebProviderError> : produce_base<D, Windows::Security::Authentication::Web::Core::IWebProviderError>
{
    HRESULT __stdcall get_ErrorCode(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ErrorCode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ErrorMessage(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ErrorMessage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Properties(impl::abi_arg_out<Windows::Foundation::Collections::IMap<hstring, hstring>> value) noexcept override
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
struct produce<D, Windows::Security::Authentication::Web::Core::IWebProviderErrorFactory> : produce_base<D, Windows::Security::Authentication::Web::Core::IWebProviderErrorFactory>
{
    HRESULT __stdcall abi_Create(uint32_t errorCode, impl::abi_arg_in<hstring> errorMessage, impl::abi_arg_out<Windows::Security::Authentication::Web::Core::IWebProviderError> webProviderError) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *webProviderError = detach_abi(this->shim().Create(errorCode, *reinterpret_cast<const hstring *>(&errorMessage)));
            return S_OK;
        }
        catch (...)
        {
            *webProviderError = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Authentication::Web::Core::IWebTokenRequest> : produce_base<D, Windows::Security::Authentication::Web::Core::IWebTokenRequest>
{
    HRESULT __stdcall get_WebAccountProvider(impl::abi_arg_out<Windows::Security::Credentials::IWebAccountProvider> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WebAccountProvider());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Scope(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Scope());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ClientId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ClientId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PromptType(Windows::Security::Authentication::Web::Core::WebTokenRequestPromptType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PromptType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Properties(impl::abi_arg_out<Windows::Foundation::Collections::IMap<hstring, hstring>> requestProperties) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *requestProperties = detach_abi(this->shim().Properties());
            return S_OK;
        }
        catch (...)
        {
            *requestProperties = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Authentication::Web::Core::IWebTokenRequest2> : produce_base<D, Windows::Security::Authentication::Web::Core::IWebTokenRequest2>
{
    HRESULT __stdcall get_AppProperties(impl::abi_arg_out<Windows::Foundation::Collections::IMap<hstring, hstring>> requestProperties) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *requestProperties = detach_abi(this->shim().AppProperties());
            return S_OK;
        }
        catch (...)
        {
            *requestProperties = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Authentication::Web::Core::IWebTokenRequestFactory> : produce_base<D, Windows::Security::Authentication::Web::Core::IWebTokenRequestFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Security::Credentials::IWebAccountProvider> provider, impl::abi_arg_in<hstring> scope, impl::abi_arg_in<hstring> clientId, impl::abi_arg_out<Windows::Security::Authentication::Web::Core::IWebTokenRequest> webTokenRequest) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *webTokenRequest = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Security::Credentials::WebAccountProvider *>(&provider), *reinterpret_cast<const hstring *>(&scope), *reinterpret_cast<const hstring *>(&clientId)));
            return S_OK;
        }
        catch (...)
        {
            *webTokenRequest = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithPromptType(impl::abi_arg_in<Windows::Security::Credentials::IWebAccountProvider> provider, impl::abi_arg_in<hstring> scope, impl::abi_arg_in<hstring> clientId, Windows::Security::Authentication::Web::Core::WebTokenRequestPromptType promptType, impl::abi_arg_out<Windows::Security::Authentication::Web::Core::IWebTokenRequest> webTokenRequest) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *webTokenRequest = detach_abi(this->shim().CreateWithPromptType(*reinterpret_cast<const Windows::Security::Credentials::WebAccountProvider *>(&provider), *reinterpret_cast<const hstring *>(&scope), *reinterpret_cast<const hstring *>(&clientId), promptType));
            return S_OK;
        }
        catch (...)
        {
            *webTokenRequest = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithProvider(impl::abi_arg_in<Windows::Security::Credentials::IWebAccountProvider> provider, impl::abi_arg_out<Windows::Security::Authentication::Web::Core::IWebTokenRequest> webTokenRequest) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *webTokenRequest = detach_abi(this->shim().CreateWithProvider(*reinterpret_cast<const Windows::Security::Credentials::WebAccountProvider *>(&provider)));
            return S_OK;
        }
        catch (...)
        {
            *webTokenRequest = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithScope(impl::abi_arg_in<Windows::Security::Credentials::IWebAccountProvider> provider, impl::abi_arg_in<hstring> scope, impl::abi_arg_out<Windows::Security::Authentication::Web::Core::IWebTokenRequest> webTokenRequest) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *webTokenRequest = detach_abi(this->shim().CreateWithScope(*reinterpret_cast<const Windows::Security::Credentials::WebAccountProvider *>(&provider), *reinterpret_cast<const hstring *>(&scope)));
            return S_OK;
        }
        catch (...)
        {
            *webTokenRequest = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Authentication::Web::Core::IWebTokenRequestResult> : produce_base<D, Windows::Security::Authentication::Web::Core::IWebTokenRequestResult>
{
    HRESULT __stdcall get_ResponseData(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Security::Authentication::Web::Core::WebTokenResponse>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ResponseData());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ResponseStatus(Windows::Security::Authentication::Web::Core::WebTokenRequestStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ResponseStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ResponseError(impl::abi_arg_out<Windows::Security::Authentication::Web::Core::IWebProviderError> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ResponseError());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_InvalidateCacheAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().InvalidateCacheAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Authentication::Web::Core::IWebTokenResponse> : produce_base<D, Windows::Security::Authentication::Web::Core::IWebTokenResponse>
{
    HRESULT __stdcall get_Token(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Token());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProviderError(impl::abi_arg_out<Windows::Security::Authentication::Web::Core::IWebProviderError> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProviderError());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WebAccount(impl::abi_arg_out<Windows::Security::Credentials::IWebAccount> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WebAccount());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Properties(impl::abi_arg_out<Windows::Foundation::Collections::IMap<hstring, hstring>> value) noexcept override
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
struct produce<D, Windows::Security::Authentication::Web::Core::IWebTokenResponseFactory> : produce_base<D, Windows::Security::Authentication::Web::Core::IWebTokenResponseFactory>
{
    HRESULT __stdcall abi_CreateWithToken(impl::abi_arg_in<hstring> token, impl::abi_arg_out<Windows::Security::Authentication::Web::Core::IWebTokenResponse> webTokenResponse) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *webTokenResponse = detach_abi(this->shim().CreateWithToken(*reinterpret_cast<const hstring *>(&token)));
            return S_OK;
        }
        catch (...)
        {
            *webTokenResponse = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithTokenAndAccount(impl::abi_arg_in<hstring> token, impl::abi_arg_in<Windows::Security::Credentials::IWebAccount> webAccount, impl::abi_arg_out<Windows::Security::Authentication::Web::Core::IWebTokenResponse> webTokenResponse) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *webTokenResponse = detach_abi(this->shim().CreateWithTokenAndAccount(*reinterpret_cast<const hstring *>(&token), *reinterpret_cast<const Windows::Security::Credentials::WebAccount *>(&webAccount)));
            return S_OK;
        }
        catch (...)
        {
            *webTokenResponse = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithTokenAccountAndError(impl::abi_arg_in<hstring> token, impl::abi_arg_in<Windows::Security::Credentials::IWebAccount> webAccount, impl::abi_arg_in<Windows::Security::Authentication::Web::Core::IWebProviderError> error, impl::abi_arg_out<Windows::Security::Authentication::Web::Core::IWebTokenResponse> webTokenResponse) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *webTokenResponse = detach_abi(this->shim().CreateWithTokenAccountAndError(*reinterpret_cast<const hstring *>(&token), *reinterpret_cast<const Windows::Security::Credentials::WebAccount *>(&webAccount), *reinterpret_cast<const Windows::Security::Authentication::Web::Core::WebProviderError *>(&error)));
            return S_OK;
        }
        catch (...)
        {
            *webTokenResponse = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Security::Authentication::Web::Core {

template <typename D> Windows::Security::Credentials::WebAccountProvider impl_IWebTokenRequest<D>::WebAccountProvider() const
{
    Windows::Security::Credentials::WebAccountProvider value { nullptr };
    check_hresult(WINRT_SHIM(IWebTokenRequest)->get_WebAccountProvider(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IWebTokenRequest<D>::Scope() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWebTokenRequest)->get_Scope(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IWebTokenRequest<D>::ClientId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWebTokenRequest)->get_ClientId(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Authentication::Web::Core::WebTokenRequestPromptType impl_IWebTokenRequest<D>::PromptType() const
{
    Windows::Security::Authentication::Web::Core::WebTokenRequestPromptType value {};
    check_hresult(WINRT_SHIM(IWebTokenRequest)->get_PromptType(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMap<hstring, hstring> impl_IWebTokenRequest<D>::Properties() const
{
    Windows::Foundation::Collections::IMap<hstring, hstring> requestProperties;
    check_hresult(WINRT_SHIM(IWebTokenRequest)->get_Properties(put_abi(requestProperties)));
    return requestProperties;
}

template <typename D> Windows::Foundation::Collections::IMap<hstring, hstring> impl_IWebTokenRequest2<D>::AppProperties() const
{
    Windows::Foundation::Collections::IMap<hstring, hstring> requestProperties;
    check_hresult(WINRT_SHIM(IWebTokenRequest2)->get_AppProperties(put_abi(requestProperties)));
    return requestProperties;
}

template <typename D> Windows::Security::Credentials::WebAccount impl_IWebAccountEventArgs<D>::Account() const
{
    Windows::Security::Credentials::WebAccount value { nullptr };
    check_hresult(WINRT_SHIM(IWebAccountEventArgs)->get_Account(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Authentication::Web::Core::WebTokenRequest impl_IWebTokenRequestFactory<D>::Create(const Windows::Security::Credentials::WebAccountProvider & provider, hstring_view scope, hstring_view clientId) const
{
    Windows::Security::Authentication::Web::Core::WebTokenRequest webTokenRequest { nullptr };
    check_hresult(WINRT_SHIM(IWebTokenRequestFactory)->abi_Create(get_abi(provider), get_abi(scope), get_abi(clientId), put_abi(webTokenRequest)));
    return webTokenRequest;
}

template <typename D> Windows::Security::Authentication::Web::Core::WebTokenRequest impl_IWebTokenRequestFactory<D>::CreateWithPromptType(const Windows::Security::Credentials::WebAccountProvider & provider, hstring_view scope, hstring_view clientId, Windows::Security::Authentication::Web::Core::WebTokenRequestPromptType promptType) const
{
    Windows::Security::Authentication::Web::Core::WebTokenRequest webTokenRequest { nullptr };
    check_hresult(WINRT_SHIM(IWebTokenRequestFactory)->abi_CreateWithPromptType(get_abi(provider), get_abi(scope), get_abi(clientId), promptType, put_abi(webTokenRequest)));
    return webTokenRequest;
}

template <typename D> Windows::Security::Authentication::Web::Core::WebTokenRequest impl_IWebTokenRequestFactory<D>::CreateWithProvider(const Windows::Security::Credentials::WebAccountProvider & provider) const
{
    Windows::Security::Authentication::Web::Core::WebTokenRequest webTokenRequest { nullptr };
    check_hresult(WINRT_SHIM(IWebTokenRequestFactory)->abi_CreateWithProvider(get_abi(provider), put_abi(webTokenRequest)));
    return webTokenRequest;
}

template <typename D> Windows::Security::Authentication::Web::Core::WebTokenRequest impl_IWebTokenRequestFactory<D>::CreateWithScope(const Windows::Security::Credentials::WebAccountProvider & provider, hstring_view scope) const
{
    Windows::Security::Authentication::Web::Core::WebTokenRequest webTokenRequest { nullptr };
    check_hresult(WINRT_SHIM(IWebTokenRequestFactory)->abi_CreateWithScope(get_abi(provider), get_abi(scope), put_abi(webTokenRequest)));
    return webTokenRequest;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::Core::WebTokenRequestResult> impl_IWebAuthenticationCoreManagerStatics<D>::GetTokenSilentlyAsync(const Windows::Security::Authentication::Web::Core::WebTokenRequest & request) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::Core::WebTokenRequestResult> asyncInfo;
    check_hresult(WINRT_SHIM(IWebAuthenticationCoreManagerStatics)->abi_GetTokenSilentlyAsync(get_abi(request), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::Core::WebTokenRequestResult> impl_IWebAuthenticationCoreManagerStatics<D>::GetTokenSilentlyAsync(const Windows::Security::Authentication::Web::Core::WebTokenRequest & request, const Windows::Security::Credentials::WebAccount & webAccount) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::Core::WebTokenRequestResult> asyncInfo;
    check_hresult(WINRT_SHIM(IWebAuthenticationCoreManagerStatics)->abi_GetTokenSilentlyWithWebAccountAsync(get_abi(request), get_abi(webAccount), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::Core::WebTokenRequestResult> impl_IWebAuthenticationCoreManagerStatics<D>::RequestTokenAsync(const Windows::Security::Authentication::Web::Core::WebTokenRequest & request) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::Core::WebTokenRequestResult> asyncInfo;
    check_hresult(WINRT_SHIM(IWebAuthenticationCoreManagerStatics)->abi_RequestTokenAsync(get_abi(request), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::Core::WebTokenRequestResult> impl_IWebAuthenticationCoreManagerStatics<D>::RequestTokenAsync(const Windows::Security::Authentication::Web::Core::WebTokenRequest & request, const Windows::Security::Credentials::WebAccount & webAccount) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::Core::WebTokenRequestResult> asyncInfo;
    check_hresult(WINRT_SHIM(IWebAuthenticationCoreManagerStatics)->abi_RequestTokenWithWebAccountAsync(get_abi(request), get_abi(webAccount), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccount> impl_IWebAuthenticationCoreManagerStatics<D>::FindAccountAsync(const Windows::Security::Credentials::WebAccountProvider & provider, hstring_view webAccountId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccount> asyncInfo;
    check_hresult(WINRT_SHIM(IWebAuthenticationCoreManagerStatics)->abi_FindAccountAsync(get_abi(provider), get_abi(webAccountId), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccountProvider> impl_IWebAuthenticationCoreManagerStatics<D>::FindAccountProviderAsync(hstring_view webAccountProviderId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccountProvider> asyncInfo;
    check_hresult(WINRT_SHIM(IWebAuthenticationCoreManagerStatics)->abi_FindAccountProviderAsync(get_abi(webAccountProviderId), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccountProvider> impl_IWebAuthenticationCoreManagerStatics<D>::FindAccountProviderAsync(hstring_view webAccountProviderId, hstring_view authority) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccountProvider> asyncInfo;
    check_hresult(WINRT_SHIM(IWebAuthenticationCoreManagerStatics)->abi_FindAccountProviderWithAuthorityAsync(get_abi(webAccountProviderId), get_abi(authority), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccountProvider> impl_IWebAuthenticationCoreManagerStatics2<D>::FindAccountProviderAsync(hstring_view webAccountProviderId, hstring_view authority, const Windows::System::User & user) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccountProvider> asyncInfo;
    check_hresult(WINRT_SHIM(IWebAuthenticationCoreManagerStatics2)->abi_FindAccountProviderWithAuthorityForUserAsync(get_abi(webAccountProviderId), get_abi(authority), get_abi(user), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Security::Authentication::Web::Core::WebAccountMonitor impl_IWebAuthenticationCoreManagerStatics3<D>::CreateWebAccountMonitor(iterable<Windows::Security::Credentials::WebAccount> webAccounts) const
{
    Windows::Security::Authentication::Web::Core::WebAccountMonitor result { nullptr };
    check_hresult(WINRT_SHIM(IWebAuthenticationCoreManagerStatics3)->abi_CreateWebAccountMonitor(get_abi(webAccounts), put_abi(result)));
    return result;
}

template <typename D> event_token impl_IWebAccountMonitor<D>::Updated(const Windows::Foundation::TypedEventHandler<Windows::Security::Authentication::Web::Core::WebAccountMonitor, Windows::Security::Authentication::Web::Core::WebAccountEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IWebAccountMonitor)->add_Updated(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IWebAccountMonitor> impl_IWebAccountMonitor<D>::Updated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Security::Authentication::Web::Core::WebAccountMonitor, Windows::Security::Authentication::Web::Core::WebAccountEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IWebAccountMonitor>(this, &ABI::Windows::Security::Authentication::Web::Core::IWebAccountMonitor::remove_Updated, Updated(handler));
}

template <typename D> void impl_IWebAccountMonitor<D>::Updated(event_token token) const
{
    check_hresult(WINRT_SHIM(IWebAccountMonitor)->remove_Updated(token));
}

template <typename D> event_token impl_IWebAccountMonitor<D>::Removed(const Windows::Foundation::TypedEventHandler<Windows::Security::Authentication::Web::Core::WebAccountMonitor, Windows::Security::Authentication::Web::Core::WebAccountEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IWebAccountMonitor)->add_Removed(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IWebAccountMonitor> impl_IWebAccountMonitor<D>::Removed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Security::Authentication::Web::Core::WebAccountMonitor, Windows::Security::Authentication::Web::Core::WebAccountEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IWebAccountMonitor>(this, &ABI::Windows::Security::Authentication::Web::Core::IWebAccountMonitor::remove_Removed, Removed(handler));
}

template <typename D> void impl_IWebAccountMonitor<D>::Removed(event_token token) const
{
    check_hresult(WINRT_SHIM(IWebAccountMonitor)->remove_Removed(token));
}

template <typename D> event_token impl_IWebAccountMonitor<D>::DefaultSignInAccountChanged(const Windows::Foundation::TypedEventHandler<Windows::Security::Authentication::Web::Core::WebAccountMonitor, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IWebAccountMonitor)->add_DefaultSignInAccountChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IWebAccountMonitor> impl_IWebAccountMonitor<D>::DefaultSignInAccountChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Security::Authentication::Web::Core::WebAccountMonitor, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IWebAccountMonitor>(this, &ABI::Windows::Security::Authentication::Web::Core::IWebAccountMonitor::remove_DefaultSignInAccountChanged, DefaultSignInAccountChanged(handler));
}

template <typename D> void impl_IWebAccountMonitor<D>::DefaultSignInAccountChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IWebAccountMonitor)->remove_DefaultSignInAccountChanged(token));
}

template <typename D> uint32_t impl_IWebProviderError<D>::ErrorCode() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IWebProviderError)->get_ErrorCode(&value));
    return value;
}

template <typename D> hstring impl_IWebProviderError<D>::ErrorMessage() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWebProviderError)->get_ErrorMessage(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMap<hstring, hstring> impl_IWebProviderError<D>::Properties() const
{
    Windows::Foundation::Collections::IMap<hstring, hstring> value;
    check_hresult(WINRT_SHIM(IWebProviderError)->get_Properties(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Authentication::Web::Core::WebProviderError impl_IWebProviderErrorFactory<D>::Create(uint32_t errorCode, hstring_view errorMessage) const
{
    Windows::Security::Authentication::Web::Core::WebProviderError webProviderError { nullptr };
    check_hresult(WINRT_SHIM(IWebProviderErrorFactory)->abi_Create(errorCode, get_abi(errorMessage), put_abi(webProviderError)));
    return webProviderError;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Security::Authentication::Web::Core::WebTokenResponse> impl_IWebTokenRequestResult<D>::ResponseData() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Security::Authentication::Web::Core::WebTokenResponse> value;
    check_hresult(WINRT_SHIM(IWebTokenRequestResult)->get_ResponseData(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Authentication::Web::Core::WebTokenRequestStatus impl_IWebTokenRequestResult<D>::ResponseStatus() const
{
    Windows::Security::Authentication::Web::Core::WebTokenRequestStatus value {};
    check_hresult(WINRT_SHIM(IWebTokenRequestResult)->get_ResponseStatus(&value));
    return value;
}

template <typename D> Windows::Security::Authentication::Web::Core::WebProviderError impl_IWebTokenRequestResult<D>::ResponseError() const
{
    Windows::Security::Authentication::Web::Core::WebProviderError value { nullptr };
    check_hresult(WINRT_SHIM(IWebTokenRequestResult)->get_ResponseError(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IWebTokenRequestResult<D>::InvalidateCacheAsync() const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IWebTokenRequestResult)->abi_InvalidateCacheAsync(put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> hstring impl_IWebTokenResponse<D>::Token() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWebTokenResponse)->get_Token(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Authentication::Web::Core::WebProviderError impl_IWebTokenResponse<D>::ProviderError() const
{
    Windows::Security::Authentication::Web::Core::WebProviderError value { nullptr };
    check_hresult(WINRT_SHIM(IWebTokenResponse)->get_ProviderError(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Credentials::WebAccount impl_IWebTokenResponse<D>::WebAccount() const
{
    Windows::Security::Credentials::WebAccount value { nullptr };
    check_hresult(WINRT_SHIM(IWebTokenResponse)->get_WebAccount(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMap<hstring, hstring> impl_IWebTokenResponse<D>::Properties() const
{
    Windows::Foundation::Collections::IMap<hstring, hstring> value;
    check_hresult(WINRT_SHIM(IWebTokenResponse)->get_Properties(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Authentication::Web::Core::WebTokenResponse impl_IWebTokenResponseFactory<D>::CreateWithToken(hstring_view token) const
{
    Windows::Security::Authentication::Web::Core::WebTokenResponse webTokenResponse { nullptr };
    check_hresult(WINRT_SHIM(IWebTokenResponseFactory)->abi_CreateWithToken(get_abi(token), put_abi(webTokenResponse)));
    return webTokenResponse;
}

template <typename D> Windows::Security::Authentication::Web::Core::WebTokenResponse impl_IWebTokenResponseFactory<D>::CreateWithTokenAndAccount(hstring_view token, const Windows::Security::Credentials::WebAccount & webAccount) const
{
    Windows::Security::Authentication::Web::Core::WebTokenResponse webTokenResponse { nullptr };
    check_hresult(WINRT_SHIM(IWebTokenResponseFactory)->abi_CreateWithTokenAndAccount(get_abi(token), get_abi(webAccount), put_abi(webTokenResponse)));
    return webTokenResponse;
}

template <typename D> Windows::Security::Authentication::Web::Core::WebTokenResponse impl_IWebTokenResponseFactory<D>::CreateWithTokenAccountAndError(hstring_view token, const Windows::Security::Credentials::WebAccount & webAccount, const Windows::Security::Authentication::Web::Core::WebProviderError & error) const
{
    Windows::Security::Authentication::Web::Core::WebTokenResponse webTokenResponse { nullptr };
    check_hresult(WINRT_SHIM(IWebTokenResponseFactory)->abi_CreateWithTokenAccountAndError(get_abi(token), get_abi(webAccount), get_abi(error), put_abi(webTokenResponse)));
    return webTokenResponse;
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::Core::WebTokenRequestResult> WebAuthenticationCoreManager::GetTokenSilentlyAsync(const Windows::Security::Authentication::Web::Core::WebTokenRequest & request)
{
    return get_activation_factory<WebAuthenticationCoreManager, IWebAuthenticationCoreManagerStatics>().GetTokenSilentlyAsync(request);
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::Core::WebTokenRequestResult> WebAuthenticationCoreManager::GetTokenSilentlyAsync(const Windows::Security::Authentication::Web::Core::WebTokenRequest & request, const Windows::Security::Credentials::WebAccount & webAccount)
{
    return get_activation_factory<WebAuthenticationCoreManager, IWebAuthenticationCoreManagerStatics>().GetTokenSilentlyAsync(request, webAccount);
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::Core::WebTokenRequestResult> WebAuthenticationCoreManager::RequestTokenAsync(const Windows::Security::Authentication::Web::Core::WebTokenRequest & request)
{
    return get_activation_factory<WebAuthenticationCoreManager, IWebAuthenticationCoreManagerStatics>().RequestTokenAsync(request);
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Web::Core::WebTokenRequestResult> WebAuthenticationCoreManager::RequestTokenAsync(const Windows::Security::Authentication::Web::Core::WebTokenRequest & request, const Windows::Security::Credentials::WebAccount & webAccount)
{
    return get_activation_factory<WebAuthenticationCoreManager, IWebAuthenticationCoreManagerStatics>().RequestTokenAsync(request, webAccount);
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccount> WebAuthenticationCoreManager::FindAccountAsync(const Windows::Security::Credentials::WebAccountProvider & provider, hstring_view webAccountId)
{
    return get_activation_factory<WebAuthenticationCoreManager, IWebAuthenticationCoreManagerStatics>().FindAccountAsync(provider, webAccountId);
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccountProvider> WebAuthenticationCoreManager::FindAccountProviderAsync(hstring_view webAccountProviderId)
{
    return get_activation_factory<WebAuthenticationCoreManager, IWebAuthenticationCoreManagerStatics>().FindAccountProviderAsync(webAccountProviderId);
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccountProvider> WebAuthenticationCoreManager::FindAccountProviderAsync(hstring_view webAccountProviderId, hstring_view authority)
{
    return get_activation_factory<WebAuthenticationCoreManager, IWebAuthenticationCoreManagerStatics>().FindAccountProviderAsync(webAccountProviderId, authority);
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccountProvider> WebAuthenticationCoreManager::FindAccountProviderAsync(hstring_view webAccountProviderId, hstring_view authority, const Windows::System::User & user)
{
    return get_activation_factory<WebAuthenticationCoreManager, IWebAuthenticationCoreManagerStatics2>().FindAccountProviderAsync(webAccountProviderId, authority, user);
}

inline Windows::Security::Authentication::Web::Core::WebAccountMonitor WebAuthenticationCoreManager::CreateWebAccountMonitor(iterable<Windows::Security::Credentials::WebAccount> webAccounts)
{
    return get_activation_factory<WebAuthenticationCoreManager, IWebAuthenticationCoreManagerStatics3>().CreateWebAccountMonitor(webAccounts);
}

inline WebProviderError::WebProviderError(uint32_t errorCode, hstring_view errorMessage) :
    WebProviderError(get_activation_factory<WebProviderError, IWebProviderErrorFactory>().Create(errorCode, errorMessage))
{}

inline WebTokenRequest::WebTokenRequest(const Windows::Security::Credentials::WebAccountProvider & provider, hstring_view scope, hstring_view clientId) :
    WebTokenRequest(get_activation_factory<WebTokenRequest, IWebTokenRequestFactory>().Create(provider, scope, clientId))
{}

inline WebTokenRequest::WebTokenRequest(const Windows::Security::Credentials::WebAccountProvider & provider, hstring_view scope, hstring_view clientId, Windows::Security::Authentication::Web::Core::WebTokenRequestPromptType promptType) :
    WebTokenRequest(get_activation_factory<WebTokenRequest, IWebTokenRequestFactory>().CreateWithPromptType(provider, scope, clientId, promptType))
{}

inline WebTokenRequest::WebTokenRequest(const Windows::Security::Credentials::WebAccountProvider & provider) :
    WebTokenRequest(get_activation_factory<WebTokenRequest, IWebTokenRequestFactory>().CreateWithProvider(provider))
{}

inline WebTokenRequest::WebTokenRequest(const Windows::Security::Credentials::WebAccountProvider & provider, hstring_view scope) :
    WebTokenRequest(get_activation_factory<WebTokenRequest, IWebTokenRequestFactory>().CreateWithScope(provider, scope))
{}

inline WebTokenResponse::WebTokenResponse() :
    WebTokenResponse(activate_instance<WebTokenResponse>())
{}

inline WebTokenResponse::WebTokenResponse(hstring_view token) :
    WebTokenResponse(get_activation_factory<WebTokenResponse, IWebTokenResponseFactory>().CreateWithToken(token))
{}

inline WebTokenResponse::WebTokenResponse(hstring_view token, const Windows::Security::Credentials::WebAccount & webAccount) :
    WebTokenResponse(get_activation_factory<WebTokenResponse, IWebTokenResponseFactory>().CreateWithTokenAndAccount(token, webAccount))
{}

inline WebTokenResponse::WebTokenResponse(hstring_view token, const Windows::Security::Credentials::WebAccount & webAccount, const Windows::Security::Authentication::Web::Core::WebProviderError & error) :
    WebTokenResponse(get_activation_factory<WebTokenResponse, IWebTokenResponseFactory>().CreateWithTokenAccountAndError(token, webAccount, error))
{}

}

}
#pragma warning(pop)
