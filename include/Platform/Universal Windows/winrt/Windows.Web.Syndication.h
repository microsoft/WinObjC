// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Data.Xml.Dom.3.h"
#include "internal/Windows.Security.Credentials.3.h"
#include "internal/Windows.Web.Syndication.3.h"
#include "Windows.Web.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Web::Syndication::ISyndicationAttribute> : produce_base<D, Windows::Web::Syndication::ISyndicationAttribute>
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

    HRESULT __stdcall put_Name(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Name(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Namespace(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Namespace());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Namespace(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Namespace(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Value(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Value());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Value(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Value(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Syndication::ISyndicationAttributeFactory> : produce_base<D, Windows::Web::Syndication::ISyndicationAttributeFactory>
{
    HRESULT __stdcall abi_CreateSyndicationAttribute(impl::abi_arg_in<hstring> attributeName, impl::abi_arg_in<hstring> attributeNamespace, impl::abi_arg_in<hstring> attributeValue, impl::abi_arg_out<Windows::Web::Syndication::ISyndicationAttribute> syndicationAttribute) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *syndicationAttribute = detach_abi(this->shim().CreateSyndicationAttribute(*reinterpret_cast<const hstring *>(&attributeName), *reinterpret_cast<const hstring *>(&attributeNamespace), *reinterpret_cast<const hstring *>(&attributeValue)));
            return S_OK;
        }
        catch (...)
        {
            *syndicationAttribute = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Syndication::ISyndicationCategory> : produce_base<D, Windows::Web::Syndication::ISyndicationCategory>
{
    HRESULT __stdcall get_Label(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Label());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Label(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Label(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Scheme(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Scheme());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Scheme(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Scheme(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Term(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Term());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Term(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Term(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Syndication::ISyndicationCategoryFactory> : produce_base<D, Windows::Web::Syndication::ISyndicationCategoryFactory>
{
    HRESULT __stdcall abi_CreateSyndicationCategory(impl::abi_arg_in<hstring> term, impl::abi_arg_out<Windows::Web::Syndication::ISyndicationCategory> category) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *category = detach_abi(this->shim().CreateSyndicationCategory(*reinterpret_cast<const hstring *>(&term)));
            return S_OK;
        }
        catch (...)
        {
            *category = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateSyndicationCategoryEx(impl::abi_arg_in<hstring> term, impl::abi_arg_in<hstring> scheme, impl::abi_arg_in<hstring> label, impl::abi_arg_out<Windows::Web::Syndication::ISyndicationCategory> category) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *category = detach_abi(this->shim().CreateSyndicationCategoryEx(*reinterpret_cast<const hstring *>(&term), *reinterpret_cast<const hstring *>(&scheme), *reinterpret_cast<const hstring *>(&label)));
            return S_OK;
        }
        catch (...)
        {
            *category = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Syndication::ISyndicationClient> : produce_base<D, Windows::Web::Syndication::ISyndicationClient>
{
    HRESULT __stdcall get_ServerCredential(impl::abi_arg_out<Windows::Security::Credentials::IPasswordCredential> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServerCredential());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ServerCredential(impl::abi_arg_in<Windows::Security::Credentials::IPasswordCredential> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ServerCredential(*reinterpret_cast<const Windows::Security::Credentials::PasswordCredential *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProxyCredential(impl::abi_arg_out<Windows::Security::Credentials::IPasswordCredential> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProxyCredential());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ProxyCredential(impl::abi_arg_in<Windows::Security::Credentials::IPasswordCredential> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProxyCredential(*reinterpret_cast<const Windows::Security::Credentials::PasswordCredential *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxResponseBufferSize(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxResponseBufferSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxResponseBufferSize(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxResponseBufferSize(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Timeout(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Timeout());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Timeout(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Timeout(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BypassCacheOnRetrieve(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BypassCacheOnRetrieve());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BypassCacheOnRetrieve(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BypassCacheOnRetrieve(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetRequestHeader(impl::abi_arg_in<hstring> name, impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetRequestHeader(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RetrieveFeedAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Syndication::SyndicationFeed, Windows::Web::Syndication::RetrievalProgress>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RetrieveFeedAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri)));
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
struct produce<D, Windows::Web::Syndication::ISyndicationClientFactory> : produce_base<D, Windows::Web::Syndication::ISyndicationClientFactory>
{
    HRESULT __stdcall abi_CreateSyndicationClient(impl::abi_arg_in<Windows::Security::Credentials::IPasswordCredential> serverCredential, impl::abi_arg_out<Windows::Web::Syndication::ISyndicationClient> syndicationClient) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *syndicationClient = detach_abi(this->shim().CreateSyndicationClient(*reinterpret_cast<const Windows::Security::Credentials::PasswordCredential *>(&serverCredential)));
            return S_OK;
        }
        catch (...)
        {
            *syndicationClient = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Syndication::ISyndicationContent> : produce_base<D, Windows::Web::Syndication::ISyndicationContent>
{
    HRESULT __stdcall get_SourceUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourceUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SourceUri(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceUri(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Syndication::ISyndicationContentFactory> : produce_base<D, Windows::Web::Syndication::ISyndicationContentFactory>
{
    HRESULT __stdcall abi_CreateSyndicationContent(impl::abi_arg_in<hstring> text, Windows::Web::Syndication::SyndicationTextType type, impl::abi_arg_out<Windows::Web::Syndication::ISyndicationContent> content) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *content = detach_abi(this->shim().CreateSyndicationContent(*reinterpret_cast<const hstring *>(&text), type));
            return S_OK;
        }
        catch (...)
        {
            *content = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateSyndicationContentWithSourceUri(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> sourceUri, impl::abi_arg_out<Windows::Web::Syndication::ISyndicationContent> content) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *content = detach_abi(this->shim().CreateSyndicationContentWithSourceUri(*reinterpret_cast<const Windows::Foundation::Uri *>(&sourceUri)));
            return S_OK;
        }
        catch (...)
        {
            *content = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Syndication::ISyndicationErrorStatics> : produce_base<D, Windows::Web::Syndication::ISyndicationErrorStatics>
{
    HRESULT __stdcall abi_GetStatus(int32_t hresult, Windows::Web::Syndication::SyndicationErrorStatus * status) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *status = detach_abi(this->shim().GetStatus(hresult));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Syndication::ISyndicationFeed> : produce_base<D, Windows::Web::Syndication::ISyndicationFeed>
{
    HRESULT __stdcall get_Authors(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationPerson>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Authors());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Categories(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationCategory>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Categories());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Contributors(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationPerson>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Contributors());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Generator(impl::abi_arg_out<Windows::Web::Syndication::ISyndicationGenerator> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Generator());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Generator(impl::abi_arg_in<Windows::Web::Syndication::ISyndicationGenerator> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Generator(*reinterpret_cast<const Windows::Web::Syndication::SyndicationGenerator *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IconUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IconUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IconUri(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IconUri(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
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

    HRESULT __stdcall put_Id(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Id(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Items(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationItem>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Items());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LastUpdatedTime(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LastUpdatedTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LastUpdatedTime(impl::abi_arg_in<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LastUpdatedTime(*reinterpret_cast<const Windows::Foundation::DateTime *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Links(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationLink>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Links());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ImageUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ImageUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ImageUri(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ImageUri(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Rights(impl::abi_arg_out<Windows::Web::Syndication::ISyndicationText> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Rights());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Rights(impl::abi_arg_in<Windows::Web::Syndication::ISyndicationText> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Rights(*reinterpret_cast<const Windows::Web::Syndication::ISyndicationText *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Subtitle(impl::abi_arg_out<Windows::Web::Syndication::ISyndicationText> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Subtitle());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Subtitle(impl::abi_arg_in<Windows::Web::Syndication::ISyndicationText> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Subtitle(*reinterpret_cast<const Windows::Web::Syndication::ISyndicationText *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Title(impl::abi_arg_out<Windows::Web::Syndication::ISyndicationText> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Title());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Title(impl::abi_arg_in<Windows::Web::Syndication::ISyndicationText> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Title(*reinterpret_cast<const Windows::Web::Syndication::ISyndicationText *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FirstUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FirstUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LastUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LastUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NextUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NextUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PreviousUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PreviousUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SourceFormat(Windows::Web::Syndication::SyndicationFormat * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourceFormat());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Load(impl::abi_arg_in<hstring> feed) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Load(*reinterpret_cast<const hstring *>(&feed));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LoadFromXml(impl::abi_arg_in<Windows::Data::Xml::Dom::IXmlDocument> feedDocument) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LoadFromXml(*reinterpret_cast<const Windows::Data::Xml::Dom::XmlDocument *>(&feedDocument));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Syndication::ISyndicationFeedFactory> : produce_base<D, Windows::Web::Syndication::ISyndicationFeedFactory>
{
    HRESULT __stdcall abi_CreateSyndicationFeed(impl::abi_arg_in<hstring> title, impl::abi_arg_in<hstring> subtitle, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_out<Windows::Web::Syndication::ISyndicationFeed> feed) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *feed = detach_abi(this->shim().CreateSyndicationFeed(*reinterpret_cast<const hstring *>(&title), *reinterpret_cast<const hstring *>(&subtitle), *reinterpret_cast<const Windows::Foundation::Uri *>(&uri)));
            return S_OK;
        }
        catch (...)
        {
            *feed = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Syndication::ISyndicationGenerator> : produce_base<D, Windows::Web::Syndication::ISyndicationGenerator>
{
    HRESULT __stdcall get_Text(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Text());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Text(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Text(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Uri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Uri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Uri(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Uri(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Version(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Version());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Version(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Version(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Syndication::ISyndicationGeneratorFactory> : produce_base<D, Windows::Web::Syndication::ISyndicationGeneratorFactory>
{
    HRESULT __stdcall abi_CreateSyndicationGenerator(impl::abi_arg_in<hstring> text, impl::abi_arg_out<Windows::Web::Syndication::ISyndicationGenerator> generator) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *generator = detach_abi(this->shim().CreateSyndicationGenerator(*reinterpret_cast<const hstring *>(&text)));
            return S_OK;
        }
        catch (...)
        {
            *generator = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Syndication::ISyndicationItem> : produce_base<D, Windows::Web::Syndication::ISyndicationItem>
{
    HRESULT __stdcall get_Authors(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationPerson>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Authors());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Categories(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationCategory>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Categories());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Contributors(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationPerson>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Contributors());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Content(impl::abi_arg_out<Windows::Web::Syndication::ISyndicationContent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Content());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Content(impl::abi_arg_in<Windows::Web::Syndication::ISyndicationContent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Content(*reinterpret_cast<const Windows::Web::Syndication::SyndicationContent *>(&value));
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

    HRESULT __stdcall put_Id(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Id(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LastUpdatedTime(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LastUpdatedTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LastUpdatedTime(impl::abi_arg_in<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LastUpdatedTime(*reinterpret_cast<const Windows::Foundation::DateTime *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Links(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationLink>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Links());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PublishedDate(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PublishedDate());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PublishedDate(impl::abi_arg_in<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PublishedDate(*reinterpret_cast<const Windows::Foundation::DateTime *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Rights(impl::abi_arg_out<Windows::Web::Syndication::ISyndicationText> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Rights());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Rights(impl::abi_arg_in<Windows::Web::Syndication::ISyndicationText> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Rights(*reinterpret_cast<const Windows::Web::Syndication::ISyndicationText *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Source(impl::abi_arg_out<Windows::Web::Syndication::ISyndicationFeed> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Source());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Source(impl::abi_arg_in<Windows::Web::Syndication::ISyndicationFeed> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Source(*reinterpret_cast<const Windows::Web::Syndication::SyndicationFeed *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Summary(impl::abi_arg_out<Windows::Web::Syndication::ISyndicationText> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Summary());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Summary(impl::abi_arg_in<Windows::Web::Syndication::ISyndicationText> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Summary(*reinterpret_cast<const Windows::Web::Syndication::ISyndicationText *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Title(impl::abi_arg_out<Windows::Web::Syndication::ISyndicationText> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Title());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Title(impl::abi_arg_in<Windows::Web::Syndication::ISyndicationText> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Title(*reinterpret_cast<const Windows::Web::Syndication::ISyndicationText *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CommentsUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CommentsUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CommentsUri(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CommentsUri(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EditUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EditUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EditMediaUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EditMediaUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ETag(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ETag());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ItemUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ItemUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Load(impl::abi_arg_in<hstring> item) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Load(*reinterpret_cast<const hstring *>(&item));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LoadFromXml(impl::abi_arg_in<Windows::Data::Xml::Dom::IXmlDocument> itemDocument) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LoadFromXml(*reinterpret_cast<const Windows::Data::Xml::Dom::XmlDocument *>(&itemDocument));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Syndication::ISyndicationItemFactory> : produce_base<D, Windows::Web::Syndication::ISyndicationItemFactory>
{
    HRESULT __stdcall abi_CreateSyndicationItem(impl::abi_arg_in<hstring> title, impl::abi_arg_in<Windows::Web::Syndication::ISyndicationContent> content, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_out<Windows::Web::Syndication::ISyndicationItem> item) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *item = detach_abi(this->shim().CreateSyndicationItem(*reinterpret_cast<const hstring *>(&title), *reinterpret_cast<const Windows::Web::Syndication::SyndicationContent *>(&content), *reinterpret_cast<const Windows::Foundation::Uri *>(&uri)));
            return S_OK;
        }
        catch (...)
        {
            *item = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Syndication::ISyndicationLink> : produce_base<D, Windows::Web::Syndication::ISyndicationLink>
{
    HRESULT __stdcall get_Length(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Length());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Length(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Length(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MediaType(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MediaType());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MediaType(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MediaType(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Relationship(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Relationship());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Relationship(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Relationship(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Title(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Title());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Title(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Title(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Uri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Uri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Uri(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Uri(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ResourceLanguage(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ResourceLanguage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ResourceLanguage(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ResourceLanguage(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Syndication::ISyndicationLinkFactory> : produce_base<D, Windows::Web::Syndication::ISyndicationLinkFactory>
{
    HRESULT __stdcall abi_CreateSyndicationLink(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_out<Windows::Web::Syndication::ISyndicationLink> link) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *link = detach_abi(this->shim().CreateSyndicationLink(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri)));
            return S_OK;
        }
        catch (...)
        {
            *link = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateSyndicationLinkEx(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_in<hstring> relationship, impl::abi_arg_in<hstring> title, impl::abi_arg_in<hstring> mediaType, uint32_t length, impl::abi_arg_out<Windows::Web::Syndication::ISyndicationLink> link) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *link = detach_abi(this->shim().CreateSyndicationLinkEx(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const hstring *>(&relationship), *reinterpret_cast<const hstring *>(&title), *reinterpret_cast<const hstring *>(&mediaType), length));
            return S_OK;
        }
        catch (...)
        {
            *link = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Syndication::ISyndicationNode> : produce_base<D, Windows::Web::Syndication::ISyndicationNode>
{
    HRESULT __stdcall get_NodeName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NodeName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_NodeName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NodeName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NodeNamespace(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NodeNamespace());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_NodeNamespace(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NodeNamespace(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NodeValue(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NodeValue());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_NodeValue(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NodeValue(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Language(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Language());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Language(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Language(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BaseUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BaseUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BaseUri(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BaseUri(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AttributeExtensions(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationAttribute>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AttributeExtensions());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ElementExtensions(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Web::Syndication::ISyndicationNode>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ElementExtensions());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetXmlDocument(Windows::Web::Syndication::SyndicationFormat format, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlDocument> xmlDocument) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *xmlDocument = detach_abi(this->shim().GetXmlDocument(format));
            return S_OK;
        }
        catch (...)
        {
            *xmlDocument = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Syndication::ISyndicationNodeFactory> : produce_base<D, Windows::Web::Syndication::ISyndicationNodeFactory>
{
    HRESULT __stdcall abi_CreateSyndicationNode(impl::abi_arg_in<hstring> nodeName, impl::abi_arg_in<hstring> nodeNamespace, impl::abi_arg_in<hstring> nodeValue, impl::abi_arg_out<Windows::Web::Syndication::ISyndicationNode> node) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *node = detach_abi(this->shim().CreateSyndicationNode(*reinterpret_cast<const hstring *>(&nodeName), *reinterpret_cast<const hstring *>(&nodeNamespace), *reinterpret_cast<const hstring *>(&nodeValue)));
            return S_OK;
        }
        catch (...)
        {
            *node = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Syndication::ISyndicationPerson> : produce_base<D, Windows::Web::Syndication::ISyndicationPerson>
{
    HRESULT __stdcall get_Email(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Email());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Email(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Email(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall put_Name(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Name(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Uri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Uri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Uri(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Uri(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Syndication::ISyndicationPersonFactory> : produce_base<D, Windows::Web::Syndication::ISyndicationPersonFactory>
{
    HRESULT __stdcall abi_CreateSyndicationPerson(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::Web::Syndication::ISyndicationPerson> person) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *person = detach_abi(this->shim().CreateSyndicationPerson(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *person = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateSyndicationPersonEx(impl::abi_arg_in<hstring> name, impl::abi_arg_in<hstring> email, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_out<Windows::Web::Syndication::ISyndicationPerson> person) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *person = detach_abi(this->shim().CreateSyndicationPersonEx(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const hstring *>(&email), *reinterpret_cast<const Windows::Foundation::Uri *>(&uri)));
            return S_OK;
        }
        catch (...)
        {
            *person = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Syndication::ISyndicationText> : produce_base<D, Windows::Web::Syndication::ISyndicationText>
{
    HRESULT __stdcall get_Text(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Text());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Text(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Text(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Type(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Type());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Type(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Type(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Xml(impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlDocument> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Xml());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Xml(impl::abi_arg_in<Windows::Data::Xml::Dom::IXmlDocument> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Xml(*reinterpret_cast<const Windows::Data::Xml::Dom::XmlDocument *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::Syndication::ISyndicationTextFactory> : produce_base<D, Windows::Web::Syndication::ISyndicationTextFactory>
{
    HRESULT __stdcall abi_CreateSyndicationText(impl::abi_arg_in<hstring> text, impl::abi_arg_out<Windows::Web::Syndication::ISyndicationText> syndicationText) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *syndicationText = detach_abi(this->shim().CreateSyndicationText(*reinterpret_cast<const hstring *>(&text)));
            return S_OK;
        }
        catch (...)
        {
            *syndicationText = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateSyndicationTextEx(impl::abi_arg_in<hstring> text, Windows::Web::Syndication::SyndicationTextType type, impl::abi_arg_out<Windows::Web::Syndication::ISyndicationText> syndicationText) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *syndicationText = detach_abi(this->shim().CreateSyndicationTextEx(*reinterpret_cast<const hstring *>(&text), type));
            return S_OK;
        }
        catch (...)
        {
            *syndicationText = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Web::Syndication {

template <typename D> hstring impl_ISyndicationAttribute<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISyndicationAttribute)->get_Name(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationAttribute<D>::Name(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISyndicationAttribute)->put_Name(get_abi(value)));
}

template <typename D> hstring impl_ISyndicationAttribute<D>::Namespace() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISyndicationAttribute)->get_Namespace(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationAttribute<D>::Namespace(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISyndicationAttribute)->put_Namespace(get_abi(value)));
}

template <typename D> hstring impl_ISyndicationAttribute<D>::Value() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISyndicationAttribute)->get_Value(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationAttribute<D>::Value(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISyndicationAttribute)->put_Value(get_abi(value)));
}

template <typename D> Windows::Web::Syndication::SyndicationAttribute impl_ISyndicationAttributeFactory<D>::CreateSyndicationAttribute(hstring_view attributeName, hstring_view attributeNamespace, hstring_view attributeValue) const
{
    Windows::Web::Syndication::SyndicationAttribute syndicationAttribute { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationAttributeFactory)->abi_CreateSyndicationAttribute(get_abi(attributeName), get_abi(attributeNamespace), get_abi(attributeValue), put_abi(syndicationAttribute)));
    return syndicationAttribute;
}

template <typename D> hstring impl_ISyndicationNode<D>::NodeName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISyndicationNode)->get_NodeName(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationNode<D>::NodeName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISyndicationNode)->put_NodeName(get_abi(value)));
}

template <typename D> hstring impl_ISyndicationNode<D>::NodeNamespace() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISyndicationNode)->get_NodeNamespace(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationNode<D>::NodeNamespace(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISyndicationNode)->put_NodeNamespace(get_abi(value)));
}

template <typename D> hstring impl_ISyndicationNode<D>::NodeValue() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISyndicationNode)->get_NodeValue(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationNode<D>::NodeValue(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISyndicationNode)->put_NodeValue(get_abi(value)));
}

template <typename D> hstring impl_ISyndicationNode<D>::Language() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISyndicationNode)->get_Language(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationNode<D>::Language(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISyndicationNode)->put_Language(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_ISyndicationNode<D>::BaseUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationNode)->get_BaseUri(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationNode<D>::BaseUri(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(ISyndicationNode)->put_BaseUri(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationAttribute> impl_ISyndicationNode<D>::AttributeExtensions() const
{
    Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationAttribute> value;
    check_hresult(WINRT_SHIM(ISyndicationNode)->get_AttributeExtensions(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Web::Syndication::ISyndicationNode> impl_ISyndicationNode<D>::ElementExtensions() const
{
    Windows::Foundation::Collections::IVector<Windows::Web::Syndication::ISyndicationNode> value;
    check_hresult(WINRT_SHIM(ISyndicationNode)->get_ElementExtensions(put_abi(value)));
    return value;
}

template <typename D> Windows::Data::Xml::Dom::XmlDocument impl_ISyndicationNode<D>::GetXmlDocument(Windows::Web::Syndication::SyndicationFormat format) const
{
    Windows::Data::Xml::Dom::XmlDocument xmlDocument { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationNode)->abi_GetXmlDocument(format, put_abi(xmlDocument)));
    return xmlDocument;
}

template <typename D> Windows::Web::Syndication::SyndicationNode impl_ISyndicationNodeFactory<D>::CreateSyndicationNode(hstring_view nodeName, hstring_view nodeNamespace, hstring_view nodeValue) const
{
    Windows::Web::Syndication::SyndicationNode node { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationNodeFactory)->abi_CreateSyndicationNode(get_abi(nodeName), get_abi(nodeNamespace), get_abi(nodeValue), put_abi(node)));
    return node;
}

template <typename D> hstring impl_ISyndicationGenerator<D>::Text() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISyndicationGenerator)->get_Text(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationGenerator<D>::Text(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISyndicationGenerator)->put_Text(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_ISyndicationGenerator<D>::Uri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationGenerator)->get_Uri(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationGenerator<D>::Uri(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(ISyndicationGenerator)->put_Uri(get_abi(value)));
}

template <typename D> hstring impl_ISyndicationGenerator<D>::Version() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISyndicationGenerator)->get_Version(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationGenerator<D>::Version(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISyndicationGenerator)->put_Version(get_abi(value)));
}

template <typename D> Windows::Web::Syndication::SyndicationGenerator impl_ISyndicationGeneratorFactory<D>::CreateSyndicationGenerator(hstring_view text) const
{
    Windows::Web::Syndication::SyndicationGenerator generator { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationGeneratorFactory)->abi_CreateSyndicationGenerator(get_abi(text), put_abi(generator)));
    return generator;
}

template <typename D> hstring impl_ISyndicationText<D>::Text() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISyndicationText)->get_Text(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationText<D>::Text(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISyndicationText)->put_Text(get_abi(value)));
}

template <typename D> hstring impl_ISyndicationText<D>::Type() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISyndicationText)->get_Type(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationText<D>::Type(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISyndicationText)->put_Type(get_abi(value)));
}

template <typename D> Windows::Data::Xml::Dom::XmlDocument impl_ISyndicationText<D>::Xml() const
{
    Windows::Data::Xml::Dom::XmlDocument value { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationText)->get_Xml(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationText<D>::Xml(const Windows::Data::Xml::Dom::XmlDocument & value) const
{
    check_hresult(WINRT_SHIM(ISyndicationText)->put_Xml(get_abi(value)));
}

template <typename D> Windows::Web::Syndication::SyndicationText impl_ISyndicationTextFactory<D>::CreateSyndicationText(hstring_view text) const
{
    Windows::Web::Syndication::SyndicationText syndicationText { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationTextFactory)->abi_CreateSyndicationText(get_abi(text), put_abi(syndicationText)));
    return syndicationText;
}

template <typename D> Windows::Web::Syndication::SyndicationText impl_ISyndicationTextFactory<D>::CreateSyndicationTextEx(hstring_view text, Windows::Web::Syndication::SyndicationTextType type) const
{
    Windows::Web::Syndication::SyndicationText syndicationText { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationTextFactory)->abi_CreateSyndicationTextEx(get_abi(text), type, put_abi(syndicationText)));
    return syndicationText;
}

template <typename D> Windows::Foundation::Uri impl_ISyndicationContent<D>::SourceUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationContent)->get_SourceUri(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationContent<D>::SourceUri(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(ISyndicationContent)->put_SourceUri(get_abi(value)));
}

template <typename D> Windows::Web::Syndication::SyndicationContent impl_ISyndicationContentFactory<D>::CreateSyndicationContent(hstring_view text, Windows::Web::Syndication::SyndicationTextType type) const
{
    Windows::Web::Syndication::SyndicationContent content { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationContentFactory)->abi_CreateSyndicationContent(get_abi(text), type, put_abi(content)));
    return content;
}

template <typename D> Windows::Web::Syndication::SyndicationContent impl_ISyndicationContentFactory<D>::CreateSyndicationContentWithSourceUri(const Windows::Foundation::Uri & sourceUri) const
{
    Windows::Web::Syndication::SyndicationContent content { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationContentFactory)->abi_CreateSyndicationContentWithSourceUri(get_abi(sourceUri), put_abi(content)));
    return content;
}

template <typename D> uint32_t impl_ISyndicationLink<D>::Length() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ISyndicationLink)->get_Length(&value));
    return value;
}

template <typename D> void impl_ISyndicationLink<D>::Length(uint32_t value) const
{
    check_hresult(WINRT_SHIM(ISyndicationLink)->put_Length(value));
}

template <typename D> hstring impl_ISyndicationLink<D>::MediaType() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISyndicationLink)->get_MediaType(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationLink<D>::MediaType(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISyndicationLink)->put_MediaType(get_abi(value)));
}

template <typename D> hstring impl_ISyndicationLink<D>::Relationship() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISyndicationLink)->get_Relationship(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationLink<D>::Relationship(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISyndicationLink)->put_Relationship(get_abi(value)));
}

template <typename D> hstring impl_ISyndicationLink<D>::Title() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISyndicationLink)->get_Title(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationLink<D>::Title(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISyndicationLink)->put_Title(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_ISyndicationLink<D>::Uri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationLink)->get_Uri(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationLink<D>::Uri(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(ISyndicationLink)->put_Uri(get_abi(value)));
}

template <typename D> hstring impl_ISyndicationLink<D>::ResourceLanguage() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISyndicationLink)->get_ResourceLanguage(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationLink<D>::ResourceLanguage(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISyndicationLink)->put_ResourceLanguage(get_abi(value)));
}

template <typename D> Windows::Web::Syndication::SyndicationLink impl_ISyndicationLinkFactory<D>::CreateSyndicationLink(const Windows::Foundation::Uri & uri) const
{
    Windows::Web::Syndication::SyndicationLink link { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationLinkFactory)->abi_CreateSyndicationLink(get_abi(uri), put_abi(link)));
    return link;
}

template <typename D> Windows::Web::Syndication::SyndicationLink impl_ISyndicationLinkFactory<D>::CreateSyndicationLinkEx(const Windows::Foundation::Uri & uri, hstring_view relationship, hstring_view title, hstring_view mediaType, uint32_t length) const
{
    Windows::Web::Syndication::SyndicationLink link { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationLinkFactory)->abi_CreateSyndicationLinkEx(get_abi(uri), get_abi(relationship), get_abi(title), get_abi(mediaType), length, put_abi(link)));
    return link;
}

template <typename D> hstring impl_ISyndicationPerson<D>::Email() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISyndicationPerson)->get_Email(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationPerson<D>::Email(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISyndicationPerson)->put_Email(get_abi(value)));
}

template <typename D> hstring impl_ISyndicationPerson<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISyndicationPerson)->get_Name(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationPerson<D>::Name(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISyndicationPerson)->put_Name(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_ISyndicationPerson<D>::Uri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationPerson)->get_Uri(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationPerson<D>::Uri(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(ISyndicationPerson)->put_Uri(get_abi(value)));
}

template <typename D> Windows::Web::Syndication::SyndicationPerson impl_ISyndicationPersonFactory<D>::CreateSyndicationPerson(hstring_view name) const
{
    Windows::Web::Syndication::SyndicationPerson person { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationPersonFactory)->abi_CreateSyndicationPerson(get_abi(name), put_abi(person)));
    return person;
}

template <typename D> Windows::Web::Syndication::SyndicationPerson impl_ISyndicationPersonFactory<D>::CreateSyndicationPersonEx(hstring_view name, hstring_view email, const Windows::Foundation::Uri & uri) const
{
    Windows::Web::Syndication::SyndicationPerson person { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationPersonFactory)->abi_CreateSyndicationPersonEx(get_abi(name), get_abi(email), get_abi(uri), put_abi(person)));
    return person;
}

template <typename D> hstring impl_ISyndicationCategory<D>::Label() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISyndicationCategory)->get_Label(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationCategory<D>::Label(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISyndicationCategory)->put_Label(get_abi(value)));
}

template <typename D> hstring impl_ISyndicationCategory<D>::Scheme() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISyndicationCategory)->get_Scheme(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationCategory<D>::Scheme(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISyndicationCategory)->put_Scheme(get_abi(value)));
}

template <typename D> hstring impl_ISyndicationCategory<D>::Term() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISyndicationCategory)->get_Term(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationCategory<D>::Term(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISyndicationCategory)->put_Term(get_abi(value)));
}

template <typename D> Windows::Web::Syndication::SyndicationCategory impl_ISyndicationCategoryFactory<D>::CreateSyndicationCategory(hstring_view term) const
{
    Windows::Web::Syndication::SyndicationCategory category { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationCategoryFactory)->abi_CreateSyndicationCategory(get_abi(term), put_abi(category)));
    return category;
}

template <typename D> Windows::Web::Syndication::SyndicationCategory impl_ISyndicationCategoryFactory<D>::CreateSyndicationCategoryEx(hstring_view term, hstring_view scheme, hstring_view label) const
{
    Windows::Web::Syndication::SyndicationCategory category { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationCategoryFactory)->abi_CreateSyndicationCategoryEx(get_abi(term), get_abi(scheme), get_abi(label), put_abi(category)));
    return category;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationPerson> impl_ISyndicationItem<D>::Authors() const
{
    Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationPerson> value;
    check_hresult(WINRT_SHIM(ISyndicationItem)->get_Authors(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationCategory> impl_ISyndicationItem<D>::Categories() const
{
    Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationCategory> value;
    check_hresult(WINRT_SHIM(ISyndicationItem)->get_Categories(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationPerson> impl_ISyndicationItem<D>::Contributors() const
{
    Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationPerson> value;
    check_hresult(WINRT_SHIM(ISyndicationItem)->get_Contributors(put_abi(value)));
    return value;
}

template <typename D> Windows::Web::Syndication::SyndicationContent impl_ISyndicationItem<D>::Content() const
{
    Windows::Web::Syndication::SyndicationContent value { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationItem)->get_Content(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationItem<D>::Content(const Windows::Web::Syndication::SyndicationContent & value) const
{
    check_hresult(WINRT_SHIM(ISyndicationItem)->put_Content(get_abi(value)));
}

template <typename D> hstring impl_ISyndicationItem<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISyndicationItem)->get_Id(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationItem<D>::Id(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISyndicationItem)->put_Id(get_abi(value)));
}

template <typename D> Windows::Foundation::DateTime impl_ISyndicationItem<D>::LastUpdatedTime() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(ISyndicationItem)->get_LastUpdatedTime(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationItem<D>::LastUpdatedTime(const Windows::Foundation::DateTime & value) const
{
    check_hresult(WINRT_SHIM(ISyndicationItem)->put_LastUpdatedTime(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationLink> impl_ISyndicationItem<D>::Links() const
{
    Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationLink> value;
    check_hresult(WINRT_SHIM(ISyndicationItem)->get_Links(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_ISyndicationItem<D>::PublishedDate() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(ISyndicationItem)->get_PublishedDate(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationItem<D>::PublishedDate(const Windows::Foundation::DateTime & value) const
{
    check_hresult(WINRT_SHIM(ISyndicationItem)->put_PublishedDate(get_abi(value)));
}

template <typename D> Windows::Web::Syndication::ISyndicationText impl_ISyndicationItem<D>::Rights() const
{
    Windows::Web::Syndication::ISyndicationText value;
    check_hresult(WINRT_SHIM(ISyndicationItem)->get_Rights(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationItem<D>::Rights(const Windows::Web::Syndication::ISyndicationText & value) const
{
    check_hresult(WINRT_SHIM(ISyndicationItem)->put_Rights(get_abi(value)));
}

template <typename D> Windows::Web::Syndication::SyndicationFeed impl_ISyndicationItem<D>::Source() const
{
    Windows::Web::Syndication::SyndicationFeed value { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationItem)->get_Source(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationItem<D>::Source(const Windows::Web::Syndication::SyndicationFeed & value) const
{
    check_hresult(WINRT_SHIM(ISyndicationItem)->put_Source(get_abi(value)));
}

template <typename D> Windows::Web::Syndication::ISyndicationText impl_ISyndicationItem<D>::Summary() const
{
    Windows::Web::Syndication::ISyndicationText value;
    check_hresult(WINRT_SHIM(ISyndicationItem)->get_Summary(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationItem<D>::Summary(const Windows::Web::Syndication::ISyndicationText & value) const
{
    check_hresult(WINRT_SHIM(ISyndicationItem)->put_Summary(get_abi(value)));
}

template <typename D> Windows::Web::Syndication::ISyndicationText impl_ISyndicationItem<D>::Title() const
{
    Windows::Web::Syndication::ISyndicationText value;
    check_hresult(WINRT_SHIM(ISyndicationItem)->get_Title(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationItem<D>::Title(const Windows::Web::Syndication::ISyndicationText & value) const
{
    check_hresult(WINRT_SHIM(ISyndicationItem)->put_Title(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_ISyndicationItem<D>::CommentsUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationItem)->get_CommentsUri(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationItem<D>::CommentsUri(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(ISyndicationItem)->put_CommentsUri(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_ISyndicationItem<D>::EditUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationItem)->get_EditUri(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_ISyndicationItem<D>::EditMediaUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationItem)->get_EditMediaUri(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISyndicationItem<D>::ETag() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISyndicationItem)->get_ETag(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_ISyndicationItem<D>::ItemUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationItem)->get_ItemUri(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationItem<D>::Load(hstring_view item) const
{
    check_hresult(WINRT_SHIM(ISyndicationItem)->abi_Load(get_abi(item)));
}

template <typename D> void impl_ISyndicationItem<D>::LoadFromXml(const Windows::Data::Xml::Dom::XmlDocument & itemDocument) const
{
    check_hresult(WINRT_SHIM(ISyndicationItem)->abi_LoadFromXml(get_abi(itemDocument)));
}

template <typename D> Windows::Web::Syndication::SyndicationItem impl_ISyndicationItemFactory<D>::CreateSyndicationItem(hstring_view title, const Windows::Web::Syndication::SyndicationContent & content, const Windows::Foundation::Uri & uri) const
{
    Windows::Web::Syndication::SyndicationItem item { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationItemFactory)->abi_CreateSyndicationItem(get_abi(title), get_abi(content), get_abi(uri), put_abi(item)));
    return item;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationPerson> impl_ISyndicationFeed<D>::Authors() const
{
    Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationPerson> value;
    check_hresult(WINRT_SHIM(ISyndicationFeed)->get_Authors(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationCategory> impl_ISyndicationFeed<D>::Categories() const
{
    Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationCategory> value;
    check_hresult(WINRT_SHIM(ISyndicationFeed)->get_Categories(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationPerson> impl_ISyndicationFeed<D>::Contributors() const
{
    Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationPerson> value;
    check_hresult(WINRT_SHIM(ISyndicationFeed)->get_Contributors(put_abi(value)));
    return value;
}

template <typename D> Windows::Web::Syndication::SyndicationGenerator impl_ISyndicationFeed<D>::Generator() const
{
    Windows::Web::Syndication::SyndicationGenerator value { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationFeed)->get_Generator(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationFeed<D>::Generator(const Windows::Web::Syndication::SyndicationGenerator & value) const
{
    check_hresult(WINRT_SHIM(ISyndicationFeed)->put_Generator(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_ISyndicationFeed<D>::IconUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationFeed)->get_IconUri(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationFeed<D>::IconUri(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(ISyndicationFeed)->put_IconUri(get_abi(value)));
}

template <typename D> hstring impl_ISyndicationFeed<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISyndicationFeed)->get_Id(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationFeed<D>::Id(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISyndicationFeed)->put_Id(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationItem> impl_ISyndicationFeed<D>::Items() const
{
    Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationItem> value;
    check_hresult(WINRT_SHIM(ISyndicationFeed)->get_Items(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_ISyndicationFeed<D>::LastUpdatedTime() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(ISyndicationFeed)->get_LastUpdatedTime(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationFeed<D>::LastUpdatedTime(const Windows::Foundation::DateTime & value) const
{
    check_hresult(WINRT_SHIM(ISyndicationFeed)->put_LastUpdatedTime(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationLink> impl_ISyndicationFeed<D>::Links() const
{
    Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationLink> value;
    check_hresult(WINRT_SHIM(ISyndicationFeed)->get_Links(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_ISyndicationFeed<D>::ImageUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationFeed)->get_ImageUri(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationFeed<D>::ImageUri(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(ISyndicationFeed)->put_ImageUri(get_abi(value)));
}

template <typename D> Windows::Web::Syndication::ISyndicationText impl_ISyndicationFeed<D>::Rights() const
{
    Windows::Web::Syndication::ISyndicationText value;
    check_hresult(WINRT_SHIM(ISyndicationFeed)->get_Rights(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationFeed<D>::Rights(const Windows::Web::Syndication::ISyndicationText & value) const
{
    check_hresult(WINRT_SHIM(ISyndicationFeed)->put_Rights(get_abi(value)));
}

template <typename D> Windows::Web::Syndication::ISyndicationText impl_ISyndicationFeed<D>::Subtitle() const
{
    Windows::Web::Syndication::ISyndicationText value;
    check_hresult(WINRT_SHIM(ISyndicationFeed)->get_Subtitle(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationFeed<D>::Subtitle(const Windows::Web::Syndication::ISyndicationText & value) const
{
    check_hresult(WINRT_SHIM(ISyndicationFeed)->put_Subtitle(get_abi(value)));
}

template <typename D> Windows::Web::Syndication::ISyndicationText impl_ISyndicationFeed<D>::Title() const
{
    Windows::Web::Syndication::ISyndicationText value;
    check_hresult(WINRT_SHIM(ISyndicationFeed)->get_Title(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationFeed<D>::Title(const Windows::Web::Syndication::ISyndicationText & value) const
{
    check_hresult(WINRT_SHIM(ISyndicationFeed)->put_Title(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_ISyndicationFeed<D>::FirstUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationFeed)->get_FirstUri(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_ISyndicationFeed<D>::LastUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationFeed)->get_LastUri(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_ISyndicationFeed<D>::NextUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationFeed)->get_NextUri(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_ISyndicationFeed<D>::PreviousUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationFeed)->get_PreviousUri(put_abi(value)));
    return value;
}

template <typename D> Windows::Web::Syndication::SyndicationFormat impl_ISyndicationFeed<D>::SourceFormat() const
{
    Windows::Web::Syndication::SyndicationFormat value {};
    check_hresult(WINRT_SHIM(ISyndicationFeed)->get_SourceFormat(&value));
    return value;
}

template <typename D> void impl_ISyndicationFeed<D>::Load(hstring_view feed) const
{
    check_hresult(WINRT_SHIM(ISyndicationFeed)->abi_Load(get_abi(feed)));
}

template <typename D> void impl_ISyndicationFeed<D>::LoadFromXml(const Windows::Data::Xml::Dom::XmlDocument & feedDocument) const
{
    check_hresult(WINRT_SHIM(ISyndicationFeed)->abi_LoadFromXml(get_abi(feedDocument)));
}

template <typename D> Windows::Web::Syndication::SyndicationFeed impl_ISyndicationFeedFactory<D>::CreateSyndicationFeed(hstring_view title, hstring_view subtitle, const Windows::Foundation::Uri & uri) const
{
    Windows::Web::Syndication::SyndicationFeed feed { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationFeedFactory)->abi_CreateSyndicationFeed(get_abi(title), get_abi(subtitle), get_abi(uri), put_abi(feed)));
    return feed;
}

template <typename D> Windows::Security::Credentials::PasswordCredential impl_ISyndicationClient<D>::ServerCredential() const
{
    Windows::Security::Credentials::PasswordCredential value { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationClient)->get_ServerCredential(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationClient<D>::ServerCredential(const Windows::Security::Credentials::PasswordCredential & value) const
{
    check_hresult(WINRT_SHIM(ISyndicationClient)->put_ServerCredential(get_abi(value)));
}

template <typename D> Windows::Security::Credentials::PasswordCredential impl_ISyndicationClient<D>::ProxyCredential() const
{
    Windows::Security::Credentials::PasswordCredential value { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationClient)->get_ProxyCredential(put_abi(value)));
    return value;
}

template <typename D> void impl_ISyndicationClient<D>::ProxyCredential(const Windows::Security::Credentials::PasswordCredential & value) const
{
    check_hresult(WINRT_SHIM(ISyndicationClient)->put_ProxyCredential(get_abi(value)));
}

template <typename D> uint32_t impl_ISyndicationClient<D>::MaxResponseBufferSize() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ISyndicationClient)->get_MaxResponseBufferSize(&value));
    return value;
}

template <typename D> void impl_ISyndicationClient<D>::MaxResponseBufferSize(uint32_t value) const
{
    check_hresult(WINRT_SHIM(ISyndicationClient)->put_MaxResponseBufferSize(value));
}

template <typename D> uint32_t impl_ISyndicationClient<D>::Timeout() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ISyndicationClient)->get_Timeout(&value));
    return value;
}

template <typename D> void impl_ISyndicationClient<D>::Timeout(uint32_t value) const
{
    check_hresult(WINRT_SHIM(ISyndicationClient)->put_Timeout(value));
}

template <typename D> bool impl_ISyndicationClient<D>::BypassCacheOnRetrieve() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISyndicationClient)->get_BypassCacheOnRetrieve(&value));
    return value;
}

template <typename D> void impl_ISyndicationClient<D>::BypassCacheOnRetrieve(bool value) const
{
    check_hresult(WINRT_SHIM(ISyndicationClient)->put_BypassCacheOnRetrieve(value));
}

template <typename D> void impl_ISyndicationClient<D>::SetRequestHeader(hstring_view name, hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISyndicationClient)->abi_SetRequestHeader(get_abi(name), get_abi(value)));
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Syndication::SyndicationFeed, Windows::Web::Syndication::RetrievalProgress> impl_ISyndicationClient<D>::RetrieveFeedAsync(const Windows::Foundation::Uri & uri) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Syndication::SyndicationFeed, Windows::Web::Syndication::RetrievalProgress> operation;
    check_hresult(WINRT_SHIM(ISyndicationClient)->abi_RetrieveFeedAsync(get_abi(uri), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Web::Syndication::SyndicationClient impl_ISyndicationClientFactory<D>::CreateSyndicationClient(const Windows::Security::Credentials::PasswordCredential & serverCredential) const
{
    Windows::Web::Syndication::SyndicationClient syndicationClient { nullptr };
    check_hresult(WINRT_SHIM(ISyndicationClientFactory)->abi_CreateSyndicationClient(get_abi(serverCredential), put_abi(syndicationClient)));
    return syndicationClient;
}

template <typename D> Windows::Web::Syndication::SyndicationErrorStatus impl_ISyndicationErrorStatics<D>::GetStatus(int32_t hresult) const
{
    Windows::Web::Syndication::SyndicationErrorStatus status {};
    check_hresult(WINRT_SHIM(ISyndicationErrorStatics)->abi_GetStatus(hresult, &status));
    return status;
}

inline SyndicationAttribute::SyndicationAttribute() :
    SyndicationAttribute(activate_instance<SyndicationAttribute>())
{}

inline SyndicationAttribute::SyndicationAttribute(hstring_view attributeName, hstring_view attributeNamespace, hstring_view attributeValue) :
    SyndicationAttribute(get_activation_factory<SyndicationAttribute, ISyndicationAttributeFactory>().CreateSyndicationAttribute(attributeName, attributeNamespace, attributeValue))
{}

inline SyndicationCategory::SyndicationCategory() :
    SyndicationCategory(activate_instance<SyndicationCategory>())
{}

inline SyndicationCategory::SyndicationCategory(hstring_view term) :
    SyndicationCategory(get_activation_factory<SyndicationCategory, ISyndicationCategoryFactory>().CreateSyndicationCategory(term))
{}

inline SyndicationCategory::SyndicationCategory(hstring_view term, hstring_view scheme, hstring_view label) :
    SyndicationCategory(get_activation_factory<SyndicationCategory, ISyndicationCategoryFactory>().CreateSyndicationCategoryEx(term, scheme, label))
{}

inline SyndicationClient::SyndicationClient() :
    SyndicationClient(activate_instance<SyndicationClient>())
{}

inline SyndicationClient::SyndicationClient(const Windows::Security::Credentials::PasswordCredential & serverCredential) :
    SyndicationClient(get_activation_factory<SyndicationClient, ISyndicationClientFactory>().CreateSyndicationClient(serverCredential))
{}

inline SyndicationContent::SyndicationContent() :
    SyndicationContent(activate_instance<SyndicationContent>())
{}

inline SyndicationContent::SyndicationContent(hstring_view text, Windows::Web::Syndication::SyndicationTextType type) :
    SyndicationContent(get_activation_factory<SyndicationContent, ISyndicationContentFactory>().CreateSyndicationContent(text, type))
{}

inline SyndicationContent::SyndicationContent(const Windows::Foundation::Uri & sourceUri) :
    SyndicationContent(get_activation_factory<SyndicationContent, ISyndicationContentFactory>().CreateSyndicationContentWithSourceUri(sourceUri))
{}

inline Windows::Web::Syndication::SyndicationErrorStatus SyndicationError::GetStatus(int32_t hresult)
{
    return get_activation_factory<SyndicationError, ISyndicationErrorStatics>().GetStatus(hresult);
}

inline SyndicationFeed::SyndicationFeed() :
    SyndicationFeed(activate_instance<SyndicationFeed>())
{}

inline SyndicationFeed::SyndicationFeed(hstring_view title, hstring_view subtitle, const Windows::Foundation::Uri & uri) :
    SyndicationFeed(get_activation_factory<SyndicationFeed, ISyndicationFeedFactory>().CreateSyndicationFeed(title, subtitle, uri))
{}

inline SyndicationGenerator::SyndicationGenerator() :
    SyndicationGenerator(activate_instance<SyndicationGenerator>())
{}

inline SyndicationGenerator::SyndicationGenerator(hstring_view text) :
    SyndicationGenerator(get_activation_factory<SyndicationGenerator, ISyndicationGeneratorFactory>().CreateSyndicationGenerator(text))
{}

inline SyndicationItem::SyndicationItem() :
    SyndicationItem(activate_instance<SyndicationItem>())
{}

inline SyndicationItem::SyndicationItem(hstring_view title, const Windows::Web::Syndication::SyndicationContent & content, const Windows::Foundation::Uri & uri) :
    SyndicationItem(get_activation_factory<SyndicationItem, ISyndicationItemFactory>().CreateSyndicationItem(title, content, uri))
{}

inline SyndicationLink::SyndicationLink() :
    SyndicationLink(activate_instance<SyndicationLink>())
{}

inline SyndicationLink::SyndicationLink(const Windows::Foundation::Uri & uri) :
    SyndicationLink(get_activation_factory<SyndicationLink, ISyndicationLinkFactory>().CreateSyndicationLink(uri))
{}

inline SyndicationLink::SyndicationLink(const Windows::Foundation::Uri & uri, hstring_view relationship, hstring_view title, hstring_view mediaType, uint32_t length) :
    SyndicationLink(get_activation_factory<SyndicationLink, ISyndicationLinkFactory>().CreateSyndicationLinkEx(uri, relationship, title, mediaType, length))
{}

inline SyndicationNode::SyndicationNode() :
    SyndicationNode(activate_instance<SyndicationNode>())
{}

inline SyndicationNode::SyndicationNode(hstring_view nodeName, hstring_view nodeNamespace, hstring_view nodeValue) :
    SyndicationNode(get_activation_factory<SyndicationNode, ISyndicationNodeFactory>().CreateSyndicationNode(nodeName, nodeNamespace, nodeValue))
{}

inline SyndicationPerson::SyndicationPerson() :
    SyndicationPerson(activate_instance<SyndicationPerson>())
{}

inline SyndicationPerson::SyndicationPerson(hstring_view name) :
    SyndicationPerson(get_activation_factory<SyndicationPerson, ISyndicationPersonFactory>().CreateSyndicationPerson(name))
{}

inline SyndicationPerson::SyndicationPerson(hstring_view name, hstring_view email, const Windows::Foundation::Uri & uri) :
    SyndicationPerson(get_activation_factory<SyndicationPerson, ISyndicationPersonFactory>().CreateSyndicationPersonEx(name, email, uri))
{}

inline SyndicationText::SyndicationText() :
    SyndicationText(activate_instance<SyndicationText>())
{}

inline SyndicationText::SyndicationText(hstring_view text) :
    SyndicationText(get_activation_factory<SyndicationText, ISyndicationTextFactory>().CreateSyndicationText(text))
{}

inline SyndicationText::SyndicationText(hstring_view text, Windows::Web::Syndication::SyndicationTextType type) :
    SyndicationText(get_activation_factory<SyndicationText, ISyndicationTextFactory>().CreateSyndicationTextEx(text, type))
{}

}

}
#pragma warning(pop)
