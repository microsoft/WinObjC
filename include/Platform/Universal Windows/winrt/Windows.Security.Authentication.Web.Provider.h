// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Security.Authentication.Web.Core.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Security.Authentication.Web.3.h"
#include "internal/Windows.Security.Credentials.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Security.Authentication.Web.Provider.3.h"
#include "Windows.Security.Authentication.Web.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Security::Authentication::Web::Provider::IWebAccountClientView> : produce_base<D, Windows::Security::Authentication::Web::Provider::IWebAccountClientView>
{
    HRESULT __stdcall get_ApplicationCallbackUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ApplicationCallbackUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Type(Windows::Security::Authentication::Web::Provider::WebAccountClientViewType * value) noexcept override
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

    HRESULT __stdcall get_AccountPairwiseId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AccountPairwiseId());
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
struct produce<D, Windows::Security::Authentication::Web::Provider::IWebAccountClientViewFactory> : produce_base<D, Windows::Security::Authentication::Web::Provider::IWebAccountClientViewFactory>
{
    HRESULT __stdcall abi_Create(Windows::Security::Authentication::Web::Provider::WebAccountClientViewType viewType, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> applicationCallbackUri, impl::abi_arg_out<Windows::Security::Authentication::Web::Provider::IWebAccountClientView> view) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *view = detach_abi(this->shim().Create(viewType, *reinterpret_cast<const Windows::Foundation::Uri *>(&applicationCallbackUri)));
            return S_OK;
        }
        catch (...)
        {
            *view = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithPairwiseId(Windows::Security::Authentication::Web::Provider::WebAccountClientViewType viewType, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> applicationCallbackUri, impl::abi_arg_in<hstring> accountPairwiseId, impl::abi_arg_out<Windows::Security::Authentication::Web::Provider::IWebAccountClientView> view) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *view = detach_abi(this->shim().CreateWithPairwiseId(viewType, *reinterpret_cast<const Windows::Foundation::Uri *>(&applicationCallbackUri), *reinterpret_cast<const hstring *>(&accountPairwiseId)));
            return S_OK;
        }
        catch (...)
        {
            *view = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Authentication::Web::Provider::IWebAccountManagerStatics> : produce_base<D, Windows::Security::Authentication::Web::Provider::IWebAccountManagerStatics>
{
    HRESULT __stdcall abi_UpdateWebAccountPropertiesAsync(impl::abi_arg_in<Windows::Security::Credentials::IWebAccount> webAccount, impl::abi_arg_in<hstring> webAccountUserName, impl::abi_arg_in<Windows::Foundation::Collections::IMapView<hstring, hstring>> additionalProperties, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().UpdateWebAccountPropertiesAsync(*reinterpret_cast<const Windows::Security::Credentials::WebAccount *>(&webAccount), *reinterpret_cast<const hstring *>(&webAccountUserName), *reinterpret_cast<const Windows::Foundation::Collections::IMapView<hstring, hstring> *>(&additionalProperties)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddWebAccountAsync(impl::abi_arg_in<hstring> webAccountId, impl::abi_arg_in<hstring> webAccountUserName, impl::abi_arg_in<Windows::Foundation::Collections::IMapView<hstring, hstring>> props, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccount>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().AddWebAccountAsync(*reinterpret_cast<const hstring *>(&webAccountId), *reinterpret_cast<const hstring *>(&webAccountUserName), *reinterpret_cast<const Windows::Foundation::Collections::IMapView<hstring, hstring> *>(&props)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteWebAccountAsync(impl::abi_arg_in<Windows::Security::Credentials::IWebAccount> webAccount, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().DeleteWebAccountAsync(*reinterpret_cast<const Windows::Security::Credentials::WebAccount *>(&webAccount)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAllProviderWebAccountsAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Credentials::WebAccount>>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().FindAllProviderWebAccountsAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PushCookiesAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_in<Windows::Foundation::Collections::IVectorView<Windows::Web::Http::HttpCookie>> cookies, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().PushCookiesAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const Windows::Foundation::Collections::IVectorView<Windows::Web::Http::HttpCookie> *>(&cookies)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetViewAsync(impl::abi_arg_in<Windows::Security::Credentials::IWebAccount> webAccount, impl::abi_arg_in<Windows::Security::Authentication::Web::Provider::IWebAccountClientView> view, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().SetViewAsync(*reinterpret_cast<const Windows::Security::Credentials::WebAccount *>(&webAccount), *reinterpret_cast<const Windows::Security::Authentication::Web::Provider::WebAccountClientView *>(&view)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ClearViewAsync(impl::abi_arg_in<Windows::Security::Credentials::IWebAccount> webAccount, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> applicationCallbackUri, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().ClearViewAsync(*reinterpret_cast<const Windows::Security::Credentials::WebAccount *>(&webAccount), *reinterpret_cast<const Windows::Foundation::Uri *>(&applicationCallbackUri)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetViewsAsync(impl::abi_arg_in<Windows::Security::Credentials::IWebAccount> webAccount, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Authentication::Web::Provider::WebAccountClientView>>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().GetViewsAsync(*reinterpret_cast<const Windows::Security::Credentials::WebAccount *>(&webAccount)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetWebAccountPictureAsync(impl::abi_arg_in<Windows::Security::Credentials::IWebAccount> webAccount, impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStream> webAccountPicture, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().SetWebAccountPictureAsync(*reinterpret_cast<const Windows::Security::Credentials::WebAccount *>(&webAccount), *reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStream *>(&webAccountPicture)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ClearWebAccountPictureAsync(impl::abi_arg_in<Windows::Security::Credentials::IWebAccount> webAccount, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().ClearWebAccountPictureAsync(*reinterpret_cast<const Windows::Security::Credentials::WebAccount *>(&webAccount)));
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
struct produce<D, Windows::Security::Authentication::Web::Provider::IWebAccountManagerStatics2> : produce_base<D, Windows::Security::Authentication::Web::Provider::IWebAccountManagerStatics2>
{
    HRESULT __stdcall abi_PullCookiesAsync(impl::abi_arg_in<hstring> uriString, impl::abi_arg_in<hstring> callerPFN, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().PullCookiesAsync(*reinterpret_cast<const hstring *>(&uriString), *reinterpret_cast<const hstring *>(&callerPFN)));
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
struct produce<D, Windows::Security::Authentication::Web::Provider::IWebAccountMapManagerStatics> : produce_base<D, Windows::Security::Authentication::Web::Provider::IWebAccountMapManagerStatics>
{
    HRESULT __stdcall abi_AddWebAccountWithScopeAndMapAsync(impl::abi_arg_in<hstring> webAccountId, impl::abi_arg_in<hstring> webAccountUserName, impl::abi_arg_in<Windows::Foundation::Collections::IMapView<hstring, hstring>> props, Windows::Security::Authentication::Web::Provider::WebAccountScope scope, impl::abi_arg_in<hstring> perUserWebAccountId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccount>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().AddWebAccountAsync(*reinterpret_cast<const hstring *>(&webAccountId), *reinterpret_cast<const hstring *>(&webAccountUserName), *reinterpret_cast<const Windows::Foundation::Collections::IMapView<hstring, hstring> *>(&props), scope, *reinterpret_cast<const hstring *>(&perUserWebAccountId)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPerAppToPerUserAccountAsync(impl::abi_arg_in<Windows::Security::Credentials::IWebAccount> perAppAccount, impl::abi_arg_in<hstring> perUserWebAccountId, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().SetPerAppToPerUserAccountAsync(*reinterpret_cast<const Windows::Security::Credentials::WebAccount *>(&perAppAccount), *reinterpret_cast<const hstring *>(&perUserWebAccountId)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPerUserFromPerAppAccountAsync(impl::abi_arg_in<Windows::Security::Credentials::IWebAccount> perAppAccount, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccount>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().GetPerUserFromPerAppAccountAsync(*reinterpret_cast<const Windows::Security::Credentials::WebAccount *>(&perAppAccount)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ClearPerUserFromPerAppAccountAsync(impl::abi_arg_in<Windows::Security::Credentials::IWebAccount> perAppAccount, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().ClearPerUserFromPerAppAccountAsync(*reinterpret_cast<const Windows::Security::Credentials::WebAccount *>(&perAppAccount)));
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
struct produce<D, Windows::Security::Authentication::Web::Provider::IWebAccountProviderAddAccountOperation> : produce_base<D, Windows::Security::Authentication::Web::Provider::IWebAccountProviderAddAccountOperation>
{
    HRESULT __stdcall abi_ReportCompleted() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportCompleted();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Authentication::Web::Provider::IWebAccountProviderBaseReportOperation> : produce_base<D, Windows::Security::Authentication::Web::Provider::IWebAccountProviderBaseReportOperation>
{
    HRESULT __stdcall abi_ReportCompleted() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportCompleted();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportError(impl::abi_arg_in<Windows::Security::Authentication::Web::Core::IWebProviderError> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportError(*reinterpret_cast<const Windows::Security::Authentication::Web::Core::WebProviderError *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Authentication::Web::Provider::IWebAccountProviderDeleteAccountOperation> : produce_base<D, Windows::Security::Authentication::Web::Provider::IWebAccountProviderDeleteAccountOperation>
{
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
};

template <typename D>
struct produce<D, Windows::Security::Authentication::Web::Provider::IWebAccountProviderManageAccountOperation> : produce_base<D, Windows::Security::Authentication::Web::Provider::IWebAccountProviderManageAccountOperation>
{
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

    HRESULT __stdcall abi_ReportCompleted() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportCompleted();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Authentication::Web::Provider::IWebAccountProviderOperation> : produce_base<D, Windows::Security::Authentication::Web::Provider::IWebAccountProviderOperation>
{
    HRESULT __stdcall get_Kind(Windows::Security::Authentication::Web::Provider::WebAccountProviderOperationKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Kind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Authentication::Web::Provider::IWebAccountProviderRetrieveCookiesOperation> : produce_base<D, Windows::Security::Authentication::Web::Provider::IWebAccountProviderRetrieveCookiesOperation>
{
    HRESULT __stdcall get_Context(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> webCookieRequestContext) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *webCookieRequestContext = detach_abi(this->shim().Context());
            return S_OK;
        }
        catch (...)
        {
            *webCookieRequestContext = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Cookies(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Web::Http::HttpCookie>> cookies) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookies = detach_abi(this->shim().Cookies());
            return S_OK;
        }
        catch (...)
        {
            *cookies = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Uri(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Uri(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Uri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> uri) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *uri = detach_abi(this->shim().Uri());
            return S_OK;
        }
        catch (...)
        {
            *uri = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ApplicationCallbackUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ApplicationCallbackUri());
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
struct produce<D, Windows::Security::Authentication::Web::Provider::IWebAccountProviderSignOutAccountOperation> : produce_base<D, Windows::Security::Authentication::Web::Provider::IWebAccountProviderSignOutAccountOperation>
{
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

    HRESULT __stdcall get_ApplicationCallbackUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ApplicationCallbackUri());
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
};

template <typename D>
struct produce<D, Windows::Security::Authentication::Web::Provider::IWebAccountProviderSilentReportOperation> : produce_base<D, Windows::Security::Authentication::Web::Provider::IWebAccountProviderSilentReportOperation>
{
    HRESULT __stdcall abi_ReportUserInteractionRequired() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportUserInteractionRequired();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportUserInteractionRequiredWithError(impl::abi_arg_in<Windows::Security::Authentication::Web::Core::IWebProviderError> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportUserInteractionRequired(*reinterpret_cast<const Windows::Security::Authentication::Web::Core::WebProviderError *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Authentication::Web::Provider::IWebAccountProviderTokenObjects> : produce_base<D, Windows::Security::Authentication::Web::Provider::IWebAccountProviderTokenObjects>
{
    HRESULT __stdcall get_Operation(impl::abi_arg_out<Windows::Security::Authentication::Web::Provider::IWebAccountProviderOperation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Operation());
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
struct produce<D, Windows::Security::Authentication::Web::Provider::IWebAccountProviderTokenOperation> : produce_base<D, Windows::Security::Authentication::Web::Provider::IWebAccountProviderTokenOperation>
{
    HRESULT __stdcall get_ProviderRequest(impl::abi_arg_out<Windows::Security::Authentication::Web::Provider::IWebProviderTokenRequest> webTokenRequest) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *webTokenRequest = detach_abi(this->shim().ProviderRequest());
            return S_OK;
        }
        catch (...)
        {
            *webTokenRequest = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProviderResponses(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Security::Authentication::Web::Provider::WebProviderTokenResponse>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProviderResponses());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CacheExpirationTime(impl::abi_arg_in<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CacheExpirationTime(*reinterpret_cast<const Windows::Foundation::DateTime *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CacheExpirationTime(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CacheExpirationTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Authentication::Web::Provider::IWebAccountProviderUIReportOperation> : produce_base<D, Windows::Security::Authentication::Web::Provider::IWebAccountProviderUIReportOperation>
{
    HRESULT __stdcall abi_ReportUserCanceled() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportUserCanceled();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Authentication::Web::Provider::IWebAccountScopeManagerStatics> : produce_base<D, Windows::Security::Authentication::Web::Provider::IWebAccountScopeManagerStatics>
{
    HRESULT __stdcall abi_AddWebAccountWithScopeAsync(impl::abi_arg_in<hstring> webAccountId, impl::abi_arg_in<hstring> webAccountUserName, impl::abi_arg_in<Windows::Foundation::Collections::IMapView<hstring, hstring>> props, Windows::Security::Authentication::Web::Provider::WebAccountScope scope, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccount>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().AddWebAccountAsync(*reinterpret_cast<const hstring *>(&webAccountId), *reinterpret_cast<const hstring *>(&webAccountUserName), *reinterpret_cast<const Windows::Foundation::Collections::IMapView<hstring, hstring> *>(&props), scope));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetScopeAsync(impl::abi_arg_in<Windows::Security::Credentials::IWebAccount> webAccount, Windows::Security::Authentication::Web::Provider::WebAccountScope scope, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().SetScopeAsync(*reinterpret_cast<const Windows::Security::Credentials::WebAccount *>(&webAccount), scope));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetScope(impl::abi_arg_in<Windows::Security::Credentials::IWebAccount> webAccount, Windows::Security::Authentication::Web::Provider::WebAccountScope * scope) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *scope = detach_abi(this->shim().GetScope(*reinterpret_cast<const Windows::Security::Credentials::WebAccount *>(&webAccount)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Authentication::Web::Provider::IWebProviderTokenRequest> : produce_base<D, Windows::Security::Authentication::Web::Provider::IWebProviderTokenRequest>
{
    HRESULT __stdcall get_ClientRequest(impl::abi_arg_out<Windows::Security::Authentication::Web::Core::IWebTokenRequest> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ClientRequest());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WebAccounts(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Security::Credentials::WebAccount>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WebAccounts());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WebAccountSelectionOptions(Windows::Security::Authentication::Web::Provider::WebAccountSelectionOptions * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WebAccountSelectionOptions());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ApplicationCallbackUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ApplicationCallbackUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetApplicationTokenBindingKeyAsync(Windows::Security::Authentication::Web::TokenBindingKeyType keyType, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> target, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::Cryptography::Core::CryptographicKey>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().GetApplicationTokenBindingKeyAsync(keyType, *reinterpret_cast<const Windows::Foundation::Uri *>(&target)));
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
struct produce<D, Windows::Security::Authentication::Web::Provider::IWebProviderTokenRequest2> : produce_base<D, Windows::Security::Authentication::Web::Provider::IWebProviderTokenRequest2>
{
    HRESULT __stdcall abi_GetApplicationTokenBindingKeyIdAsync(Windows::Security::Authentication::Web::TokenBindingKeyType keyType, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> target, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().GetApplicationTokenBindingKeyIdAsync(keyType, *reinterpret_cast<const Windows::Foundation::Uri *>(&target)));
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
struct produce<D, Windows::Security::Authentication::Web::Provider::IWebProviderTokenResponse> : produce_base<D, Windows::Security::Authentication::Web::Provider::IWebProviderTokenResponse>
{
    HRESULT __stdcall get_ClientResponse(impl::abi_arg_out<Windows::Security::Authentication::Web::Core::IWebTokenResponse> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ClientResponse());
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
struct produce<D, Windows::Security::Authentication::Web::Provider::IWebProviderTokenResponseFactory> : produce_base<D, Windows::Security::Authentication::Web::Provider::IWebProviderTokenResponseFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Security::Authentication::Web::Core::IWebTokenResponse> webTokenResponse, impl::abi_arg_out<Windows::Security::Authentication::Web::Provider::IWebProviderTokenResponse> webProviderTokenResponse) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *webProviderTokenResponse = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Security::Authentication::Web::Core::WebTokenResponse *>(&webTokenResponse)));
            return S_OK;
        }
        catch (...)
        {
            *webProviderTokenResponse = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Security::Authentication::Web::Provider {

template <typename D> Windows::Security::Authentication::Web::Provider::WebAccountProviderOperationKind impl_IWebAccountProviderOperation<D>::Kind() const
{
    Windows::Security::Authentication::Web::Provider::WebAccountProviderOperationKind value {};
    check_hresult(WINRT_SHIM(IWebAccountProviderOperation)->get_Kind(&value));
    return value;
}

template <typename D> Windows::Security::Authentication::Web::Core::WebTokenRequest impl_IWebProviderTokenRequest<D>::ClientRequest() const
{
    Windows::Security::Authentication::Web::Core::WebTokenRequest value { nullptr };
    check_hresult(WINRT_SHIM(IWebProviderTokenRequest)->get_ClientRequest(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Security::Credentials::WebAccount> impl_IWebProviderTokenRequest<D>::WebAccounts() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Security::Credentials::WebAccount> value;
    check_hresult(WINRT_SHIM(IWebProviderTokenRequest)->get_WebAccounts(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Authentication::Web::Provider::WebAccountSelectionOptions impl_IWebProviderTokenRequest<D>::WebAccountSelectionOptions() const
{
    Windows::Security::Authentication::Web::Provider::WebAccountSelectionOptions value {};
    check_hresult(WINRT_SHIM(IWebProviderTokenRequest)->get_WebAccountSelectionOptions(&value));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_IWebProviderTokenRequest<D>::ApplicationCallbackUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IWebProviderTokenRequest)->get_ApplicationCallbackUri(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::Cryptography::Core::CryptographicKey> impl_IWebProviderTokenRequest<D>::GetApplicationTokenBindingKeyAsync(Windows::Security::Authentication::Web::TokenBindingKeyType keyType, const Windows::Foundation::Uri & target) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Cryptography::Core::CryptographicKey> asyncInfo;
    check_hresult(WINRT_SHIM(IWebProviderTokenRequest)->abi_GetApplicationTokenBindingKeyAsync(keyType, get_abi(target), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> impl_IWebProviderTokenRequest2<D>::GetApplicationTokenBindingKeyIdAsync(Windows::Security::Authentication::Web::TokenBindingKeyType keyType, const Windows::Foundation::Uri & target) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> asyncInfo;
    check_hresult(WINRT_SHIM(IWebProviderTokenRequest2)->abi_GetApplicationTokenBindingKeyIdAsync(keyType, get_abi(target), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Security::Authentication::Web::Core::WebTokenResponse impl_IWebProviderTokenResponse<D>::ClientResponse() const
{
    Windows::Security::Authentication::Web::Core::WebTokenResponse value { nullptr };
    check_hresult(WINRT_SHIM(IWebProviderTokenResponse)->get_ClientResponse(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Authentication::Web::Provider::WebProviderTokenResponse impl_IWebProviderTokenResponseFactory<D>::Create(const Windows::Security::Authentication::Web::Core::WebTokenResponse & webTokenResponse) const
{
    Windows::Security::Authentication::Web::Provider::WebProviderTokenResponse webProviderTokenResponse { nullptr };
    check_hresult(WINRT_SHIM(IWebProviderTokenResponseFactory)->abi_Create(get_abi(webTokenResponse), put_abi(webProviderTokenResponse)));
    return webProviderTokenResponse;
}

template <typename D> Windows::Foundation::Uri impl_IWebAccountClientView<D>::ApplicationCallbackUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IWebAccountClientView)->get_ApplicationCallbackUri(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Authentication::Web::Provider::WebAccountClientViewType impl_IWebAccountClientView<D>::Type() const
{
    Windows::Security::Authentication::Web::Provider::WebAccountClientViewType value {};
    check_hresult(WINRT_SHIM(IWebAccountClientView)->get_Type(&value));
    return value;
}

template <typename D> hstring impl_IWebAccountClientView<D>::AccountPairwiseId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWebAccountClientView)->get_AccountPairwiseId(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Authentication::Web::Provider::WebAccountClientView impl_IWebAccountClientViewFactory<D>::Create(Windows::Security::Authentication::Web::Provider::WebAccountClientViewType viewType, const Windows::Foundation::Uri & applicationCallbackUri) const
{
    Windows::Security::Authentication::Web::Provider::WebAccountClientView view { nullptr };
    check_hresult(WINRT_SHIM(IWebAccountClientViewFactory)->abi_Create(viewType, get_abi(applicationCallbackUri), put_abi(view)));
    return view;
}

template <typename D> Windows::Security::Authentication::Web::Provider::WebAccountClientView impl_IWebAccountClientViewFactory<D>::CreateWithPairwiseId(Windows::Security::Authentication::Web::Provider::WebAccountClientViewType viewType, const Windows::Foundation::Uri & applicationCallbackUri, hstring_view accountPairwiseId) const
{
    Windows::Security::Authentication::Web::Provider::WebAccountClientView view { nullptr };
    check_hresult(WINRT_SHIM(IWebAccountClientViewFactory)->abi_CreateWithPairwiseId(viewType, get_abi(applicationCallbackUri), get_abi(accountPairwiseId), put_abi(view)));
    return view;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IWebAccountManagerStatics<D>::UpdateWebAccountPropertiesAsync(const Windows::Security::Credentials::WebAccount & webAccount, hstring_view webAccountUserName, map_view<hstring, hstring> additionalProperties) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IWebAccountManagerStatics)->abi_UpdateWebAccountPropertiesAsync(get_abi(webAccount), get_abi(webAccountUserName), get_abi(additionalProperties), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccount> impl_IWebAccountManagerStatics<D>::AddWebAccountAsync(hstring_view webAccountId, hstring_view webAccountUserName, map_view<hstring, hstring> props) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccount> asyncInfo;
    check_hresult(WINRT_SHIM(IWebAccountManagerStatics)->abi_AddWebAccountAsync(get_abi(webAccountId), get_abi(webAccountUserName), get_abi(props), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IWebAccountManagerStatics<D>::DeleteWebAccountAsync(const Windows::Security::Credentials::WebAccount & webAccount) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IWebAccountManagerStatics)->abi_DeleteWebAccountAsync(get_abi(webAccount), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Credentials::WebAccount>> impl_IWebAccountManagerStatics<D>::FindAllProviderWebAccountsAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Credentials::WebAccount>> asyncInfo;
    check_hresult(WINRT_SHIM(IWebAccountManagerStatics)->abi_FindAllProviderWebAccountsAsync(put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IWebAccountManagerStatics<D>::PushCookiesAsync(const Windows::Foundation::Uri & uri, vector_view<Windows::Web::Http::HttpCookie> cookies) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IWebAccountManagerStatics)->abi_PushCookiesAsync(get_abi(uri), get_abi(cookies), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IWebAccountManagerStatics<D>::SetViewAsync(const Windows::Security::Credentials::WebAccount & webAccount, const Windows::Security::Authentication::Web::Provider::WebAccountClientView & view) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IWebAccountManagerStatics)->abi_SetViewAsync(get_abi(webAccount), get_abi(view), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IWebAccountManagerStatics<D>::ClearViewAsync(const Windows::Security::Credentials::WebAccount & webAccount, const Windows::Foundation::Uri & applicationCallbackUri) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IWebAccountManagerStatics)->abi_ClearViewAsync(get_abi(webAccount), get_abi(applicationCallbackUri), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Authentication::Web::Provider::WebAccountClientView>> impl_IWebAccountManagerStatics<D>::GetViewsAsync(const Windows::Security::Credentials::WebAccount & webAccount) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Authentication::Web::Provider::WebAccountClientView>> asyncInfo;
    check_hresult(WINRT_SHIM(IWebAccountManagerStatics)->abi_GetViewsAsync(get_abi(webAccount), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IWebAccountManagerStatics<D>::SetWebAccountPictureAsync(const Windows::Security::Credentials::WebAccount & webAccount, const Windows::Storage::Streams::IRandomAccessStream & webAccountPicture) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IWebAccountManagerStatics)->abi_SetWebAccountPictureAsync(get_abi(webAccount), get_abi(webAccountPicture), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IWebAccountManagerStatics<D>::ClearWebAccountPictureAsync(const Windows::Security::Credentials::WebAccount & webAccount) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IWebAccountManagerStatics)->abi_ClearWebAccountPictureAsync(get_abi(webAccount), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IWebAccountManagerStatics2<D>::PullCookiesAsync(hstring_view uriString, hstring_view callerPFN) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IWebAccountManagerStatics2)->abi_PullCookiesAsync(get_abi(uriString), get_abi(callerPFN), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccount> impl_IWebAccountScopeManagerStatics<D>::AddWebAccountAsync(hstring_view webAccountId, hstring_view webAccountUserName, map_view<hstring, hstring> props, Windows::Security::Authentication::Web::Provider::WebAccountScope scope) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccount> asyncInfo;
    check_hresult(WINRT_SHIM(IWebAccountScopeManagerStatics)->abi_AddWebAccountWithScopeAsync(get_abi(webAccountId), get_abi(webAccountUserName), get_abi(props), scope, put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IWebAccountScopeManagerStatics<D>::SetScopeAsync(const Windows::Security::Credentials::WebAccount & webAccount, Windows::Security::Authentication::Web::Provider::WebAccountScope scope) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IWebAccountScopeManagerStatics)->abi_SetScopeAsync(get_abi(webAccount), scope, put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Security::Authentication::Web::Provider::WebAccountScope impl_IWebAccountScopeManagerStatics<D>::GetScope(const Windows::Security::Credentials::WebAccount & webAccount) const
{
    Windows::Security::Authentication::Web::Provider::WebAccountScope scope {};
    check_hresult(WINRT_SHIM(IWebAccountScopeManagerStatics)->abi_GetScope(get_abi(webAccount), &scope));
    return scope;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccount> impl_IWebAccountMapManagerStatics<D>::AddWebAccountAsync(hstring_view webAccountId, hstring_view webAccountUserName, map_view<hstring, hstring> props, Windows::Security::Authentication::Web::Provider::WebAccountScope scope, hstring_view perUserWebAccountId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccount> asyncInfo;
    check_hresult(WINRT_SHIM(IWebAccountMapManagerStatics)->abi_AddWebAccountWithScopeAndMapAsync(get_abi(webAccountId), get_abi(webAccountUserName), get_abi(props), scope, get_abi(perUserWebAccountId), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IWebAccountMapManagerStatics<D>::SetPerAppToPerUserAccountAsync(const Windows::Security::Credentials::WebAccount & perAppAccount, hstring_view perUserWebAccountId) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IWebAccountMapManagerStatics)->abi_SetPerAppToPerUserAccountAsync(get_abi(perAppAccount), get_abi(perUserWebAccountId), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccount> impl_IWebAccountMapManagerStatics<D>::GetPerUserFromPerAppAccountAsync(const Windows::Security::Credentials::WebAccount & perAppAccount) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccount> asyncInfo;
    check_hresult(WINRT_SHIM(IWebAccountMapManagerStatics)->abi_GetPerUserFromPerAppAccountAsync(get_abi(perAppAccount), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IWebAccountMapManagerStatics<D>::ClearPerUserFromPerAppAccountAsync(const Windows::Security::Credentials::WebAccount & perAppAccount) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IWebAccountMapManagerStatics)->abi_ClearPerUserFromPerAppAccountAsync(get_abi(perAppAccount), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> void impl_IWebAccountProviderBaseReportOperation<D>::ReportCompleted() const
{
    check_hresult(WINRT_SHIM(IWebAccountProviderBaseReportOperation)->abi_ReportCompleted());
}

template <typename D> void impl_IWebAccountProviderBaseReportOperation<D>::ReportError(const Windows::Security::Authentication::Web::Core::WebProviderError & value) const
{
    check_hresult(WINRT_SHIM(IWebAccountProviderBaseReportOperation)->abi_ReportError(get_abi(value)));
}

template <typename D> void impl_IWebAccountProviderUIReportOperation<D>::ReportUserCanceled() const
{
    check_hresult(WINRT_SHIM(IWebAccountProviderUIReportOperation)->abi_ReportUserCanceled());
}

template <typename D> void impl_IWebAccountProviderSilentReportOperation<D>::ReportUserInteractionRequired() const
{
    check_hresult(WINRT_SHIM(IWebAccountProviderSilentReportOperation)->abi_ReportUserInteractionRequired());
}

template <typename D> void impl_IWebAccountProviderSilentReportOperation<D>::ReportUserInteractionRequired(const Windows::Security::Authentication::Web::Core::WebProviderError & value) const
{
    check_hresult(WINRT_SHIM(IWebAccountProviderSilentReportOperation)->abi_ReportUserInteractionRequiredWithError(get_abi(value)));
}

template <typename D> Windows::Security::Authentication::Web::Provider::WebProviderTokenRequest impl_IWebAccountProviderTokenOperation<D>::ProviderRequest() const
{
    Windows::Security::Authentication::Web::Provider::WebProviderTokenRequest webTokenRequest { nullptr };
    check_hresult(WINRT_SHIM(IWebAccountProviderTokenOperation)->get_ProviderRequest(put_abi(webTokenRequest)));
    return webTokenRequest;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Security::Authentication::Web::Provider::WebProviderTokenResponse> impl_IWebAccountProviderTokenOperation<D>::ProviderResponses() const
{
    Windows::Foundation::Collections::IVector<Windows::Security::Authentication::Web::Provider::WebProviderTokenResponse> value;
    check_hresult(WINRT_SHIM(IWebAccountProviderTokenOperation)->get_ProviderResponses(put_abi(value)));
    return value;
}

template <typename D> void impl_IWebAccountProviderTokenOperation<D>::CacheExpirationTime(const Windows::Foundation::DateTime & value) const
{
    check_hresult(WINRT_SHIM(IWebAccountProviderTokenOperation)->put_CacheExpirationTime(get_abi(value)));
}

template <typename D> Windows::Foundation::DateTime impl_IWebAccountProviderTokenOperation<D>::CacheExpirationTime() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IWebAccountProviderTokenOperation)->get_CacheExpirationTime(put_abi(value)));
    return value;
}

template <typename D> void impl_IWebAccountProviderAddAccountOperation<D>::ReportCompleted() const
{
    check_hresult(WINRT_SHIM(IWebAccountProviderAddAccountOperation)->abi_ReportCompleted());
}

template <typename D> Windows::Security::Credentials::WebAccount impl_IWebAccountProviderManageAccountOperation<D>::WebAccount() const
{
    Windows::Security::Credentials::WebAccount value { nullptr };
    check_hresult(WINRT_SHIM(IWebAccountProviderManageAccountOperation)->get_WebAccount(put_abi(value)));
    return value;
}

template <typename D> void impl_IWebAccountProviderManageAccountOperation<D>::ReportCompleted() const
{
    check_hresult(WINRT_SHIM(IWebAccountProviderManageAccountOperation)->abi_ReportCompleted());
}

template <typename D> Windows::Security::Credentials::WebAccount impl_IWebAccountProviderDeleteAccountOperation<D>::WebAccount() const
{
    Windows::Security::Credentials::WebAccount value { nullptr };
    check_hresult(WINRT_SHIM(IWebAccountProviderDeleteAccountOperation)->get_WebAccount(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Credentials::WebAccount impl_IWebAccountProviderSignOutAccountOperation<D>::WebAccount() const
{
    Windows::Security::Credentials::WebAccount value { nullptr };
    check_hresult(WINRT_SHIM(IWebAccountProviderSignOutAccountOperation)->get_WebAccount(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_IWebAccountProviderSignOutAccountOperation<D>::ApplicationCallbackUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IWebAccountProviderSignOutAccountOperation)->get_ApplicationCallbackUri(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IWebAccountProviderSignOutAccountOperation<D>::ClientId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWebAccountProviderSignOutAccountOperation)->get_ClientId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_IWebAccountProviderRetrieveCookiesOperation<D>::Context() const
{
    Windows::Foundation::Uri webCookieRequestContext { nullptr };
    check_hresult(WINRT_SHIM(IWebAccountProviderRetrieveCookiesOperation)->get_Context(put_abi(webCookieRequestContext)));
    return webCookieRequestContext;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Web::Http::HttpCookie> impl_IWebAccountProviderRetrieveCookiesOperation<D>::Cookies() const
{
    Windows::Foundation::Collections::IVector<Windows::Web::Http::HttpCookie> cookies;
    check_hresult(WINRT_SHIM(IWebAccountProviderRetrieveCookiesOperation)->get_Cookies(put_abi(cookies)));
    return cookies;
}

template <typename D> void impl_IWebAccountProviderRetrieveCookiesOperation<D>::Uri(const Windows::Foundation::Uri & uri) const
{
    check_hresult(WINRT_SHIM(IWebAccountProviderRetrieveCookiesOperation)->put_Uri(get_abi(uri)));
}

template <typename D> Windows::Foundation::Uri impl_IWebAccountProviderRetrieveCookiesOperation<D>::Uri() const
{
    Windows::Foundation::Uri uri { nullptr };
    check_hresult(WINRT_SHIM(IWebAccountProviderRetrieveCookiesOperation)->get_Uri(put_abi(uri)));
    return uri;
}

template <typename D> Windows::Foundation::Uri impl_IWebAccountProviderRetrieveCookiesOperation<D>::ApplicationCallbackUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IWebAccountProviderRetrieveCookiesOperation)->get_ApplicationCallbackUri(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Authentication::Web::Provider::IWebAccountProviderOperation impl_IWebAccountProviderTokenObjects<D>::Operation() const
{
    Windows::Security::Authentication::Web::Provider::IWebAccountProviderOperation value;
    check_hresult(WINRT_SHIM(IWebAccountProviderTokenObjects)->get_Operation(put_abi(value)));
    return value;
}

inline WebAccountClientView::WebAccountClientView(Windows::Security::Authentication::Web::Provider::WebAccountClientViewType viewType, const Windows::Foundation::Uri & applicationCallbackUri) :
    WebAccountClientView(get_activation_factory<WebAccountClientView, IWebAccountClientViewFactory>().Create(viewType, applicationCallbackUri))
{}

inline WebAccountClientView::WebAccountClientView(Windows::Security::Authentication::Web::Provider::WebAccountClientViewType viewType, const Windows::Foundation::Uri & applicationCallbackUri, hstring_view accountPairwiseId) :
    WebAccountClientView(get_activation_factory<WebAccountClientView, IWebAccountClientViewFactory>().CreateWithPairwiseId(viewType, applicationCallbackUri, accountPairwiseId))
{}

inline Windows::Foundation::IAsyncAction WebAccountManager::UpdateWebAccountPropertiesAsync(const Windows::Security::Credentials::WebAccount & webAccount, hstring_view webAccountUserName, map_view<hstring, hstring> additionalProperties)
{
    return get_activation_factory<WebAccountManager, IWebAccountManagerStatics>().UpdateWebAccountPropertiesAsync(webAccount, webAccountUserName, additionalProperties);
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccount> WebAccountManager::AddWebAccountAsync(hstring_view webAccountId, hstring_view webAccountUserName, map_view<hstring, hstring> props)
{
    return get_activation_factory<WebAccountManager, IWebAccountManagerStatics>().AddWebAccountAsync(webAccountId, webAccountUserName, props);
}

inline Windows::Foundation::IAsyncAction WebAccountManager::DeleteWebAccountAsync(const Windows::Security::Credentials::WebAccount & webAccount)
{
    return get_activation_factory<WebAccountManager, IWebAccountManagerStatics>().DeleteWebAccountAsync(webAccount);
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Credentials::WebAccount>> WebAccountManager::FindAllProviderWebAccountsAsync()
{
    return get_activation_factory<WebAccountManager, IWebAccountManagerStatics>().FindAllProviderWebAccountsAsync();
}

inline Windows::Foundation::IAsyncAction WebAccountManager::PushCookiesAsync(const Windows::Foundation::Uri & uri, vector_view<Windows::Web::Http::HttpCookie> cookies)
{
    return get_activation_factory<WebAccountManager, IWebAccountManagerStatics>().PushCookiesAsync(uri, cookies);
}

inline Windows::Foundation::IAsyncAction WebAccountManager::SetViewAsync(const Windows::Security::Credentials::WebAccount & webAccount, const Windows::Security::Authentication::Web::Provider::WebAccountClientView & view)
{
    return get_activation_factory<WebAccountManager, IWebAccountManagerStatics>().SetViewAsync(webAccount, view);
}

inline Windows::Foundation::IAsyncAction WebAccountManager::ClearViewAsync(const Windows::Security::Credentials::WebAccount & webAccount, const Windows::Foundation::Uri & applicationCallbackUri)
{
    return get_activation_factory<WebAccountManager, IWebAccountManagerStatics>().ClearViewAsync(webAccount, applicationCallbackUri);
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Authentication::Web::Provider::WebAccountClientView>> WebAccountManager::GetViewsAsync(const Windows::Security::Credentials::WebAccount & webAccount)
{
    return get_activation_factory<WebAccountManager, IWebAccountManagerStatics>().GetViewsAsync(webAccount);
}

inline Windows::Foundation::IAsyncAction WebAccountManager::SetWebAccountPictureAsync(const Windows::Security::Credentials::WebAccount & webAccount, const Windows::Storage::Streams::IRandomAccessStream & webAccountPicture)
{
    return get_activation_factory<WebAccountManager, IWebAccountManagerStatics>().SetWebAccountPictureAsync(webAccount, webAccountPicture);
}

inline Windows::Foundation::IAsyncAction WebAccountManager::ClearWebAccountPictureAsync(const Windows::Security::Credentials::WebAccount & webAccount)
{
    return get_activation_factory<WebAccountManager, IWebAccountManagerStatics>().ClearWebAccountPictureAsync(webAccount);
}

inline Windows::Foundation::IAsyncAction WebAccountManager::PullCookiesAsync(hstring_view uriString, hstring_view callerPFN)
{
    return get_activation_factory<WebAccountManager, IWebAccountManagerStatics2>().PullCookiesAsync(uriString, callerPFN);
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccount> WebAccountManager::AddWebAccountAsync(hstring_view webAccountId, hstring_view webAccountUserName, map_view<hstring, hstring> props, Windows::Security::Authentication::Web::Provider::WebAccountScope scope, hstring_view perUserWebAccountId)
{
    return get_activation_factory<WebAccountManager, IWebAccountMapManagerStatics>().AddWebAccountAsync(webAccountId, webAccountUserName, props, scope, perUserWebAccountId);
}

inline Windows::Foundation::IAsyncAction WebAccountManager::SetPerAppToPerUserAccountAsync(const Windows::Security::Credentials::WebAccount & perAppAccount, hstring_view perUserWebAccountId)
{
    return get_activation_factory<WebAccountManager, IWebAccountMapManagerStatics>().SetPerAppToPerUserAccountAsync(perAppAccount, perUserWebAccountId);
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccount> WebAccountManager::GetPerUserFromPerAppAccountAsync(const Windows::Security::Credentials::WebAccount & perAppAccount)
{
    return get_activation_factory<WebAccountManager, IWebAccountMapManagerStatics>().GetPerUserFromPerAppAccountAsync(perAppAccount);
}

inline Windows::Foundation::IAsyncAction WebAccountManager::ClearPerUserFromPerAppAccountAsync(const Windows::Security::Credentials::WebAccount & perAppAccount)
{
    return get_activation_factory<WebAccountManager, IWebAccountMapManagerStatics>().ClearPerUserFromPerAppAccountAsync(perAppAccount);
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::WebAccount> WebAccountManager::AddWebAccountAsync(hstring_view webAccountId, hstring_view webAccountUserName, map_view<hstring, hstring> props, Windows::Security::Authentication::Web::Provider::WebAccountScope scope)
{
    return get_activation_factory<WebAccountManager, IWebAccountScopeManagerStatics>().AddWebAccountAsync(webAccountId, webAccountUserName, props, scope);
}

inline Windows::Foundation::IAsyncAction WebAccountManager::SetScopeAsync(const Windows::Security::Credentials::WebAccount & webAccount, Windows::Security::Authentication::Web::Provider::WebAccountScope scope)
{
    return get_activation_factory<WebAccountManager, IWebAccountScopeManagerStatics>().SetScopeAsync(webAccount, scope);
}

inline Windows::Security::Authentication::Web::Provider::WebAccountScope WebAccountManager::GetScope(const Windows::Security::Credentials::WebAccount & webAccount)
{
    return get_activation_factory<WebAccountManager, IWebAccountScopeManagerStatics>().GetScope(webAccount);
}

inline WebProviderTokenResponse::WebProviderTokenResponse(const Windows::Security::Authentication::Web::Core::WebTokenResponse & webTokenResponse) :
    WebProviderTokenResponse(get_activation_factory<WebProviderTokenResponse, IWebProviderTokenResponseFactory>().Create(webTokenResponse))
{}

}

}
#pragma warning(pop)
