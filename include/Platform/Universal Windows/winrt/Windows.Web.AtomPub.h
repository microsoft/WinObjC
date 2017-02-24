// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Web.Syndication.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Security.Credentials.3.h"
#include "internal/Windows.Web.AtomPub.3.h"
#include "Windows.Web.h"
#include "Windows.Web.Syndication.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Web::AtomPub::IAtomPubClient> : produce_base<D, Windows::Web::AtomPub::IAtomPubClient>
{
    HRESULT __stdcall abi_RetrieveServiceDocumentAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::AtomPub::ServiceDocument, Windows::Web::Syndication::RetrievalProgress>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RetrieveServiceDocumentAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RetrieveMediaResourceAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Storage::Streams::IInputStream, Windows::Web::Syndication::RetrievalProgress>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RetrieveMediaResourceAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RetrieveResourceAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Syndication::SyndicationItem, Windows::Web::Syndication::RetrievalProgress>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RetrieveResourceAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateResourceAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_in<hstring> description, impl::abi_arg_in<Windows::Web::Syndication::ISyndicationItem> item, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Syndication::SyndicationItem, Windows::Web::Syndication::TransferProgress>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreateResourceAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const hstring *>(&description), *reinterpret_cast<const Windows::Web::Syndication::SyndicationItem *>(&item)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateMediaResourceAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_in<hstring> mediaType, impl::abi_arg_in<hstring> description, impl::abi_arg_in<Windows::Storage::Streams::IInputStream> mediaStream, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Syndication::SyndicationItem, Windows::Web::Syndication::TransferProgress>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreateMediaResourceAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const hstring *>(&mediaType), *reinterpret_cast<const hstring *>(&description), *reinterpret_cast<const Windows::Storage::Streams::IInputStream *>(&mediaStream)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UpdateMediaResourceAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_in<hstring> mediaType, impl::abi_arg_in<Windows::Storage::Streams::IInputStream> mediaStream, impl::abi_arg_out<Windows::Foundation::IAsyncActionWithProgress<Windows::Web::Syndication::TransferProgress>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().UpdateMediaResourceAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const hstring *>(&mediaType), *reinterpret_cast<const Windows::Storage::Streams::IInputStream *>(&mediaStream)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UpdateResourceAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_in<Windows::Web::Syndication::ISyndicationItem> item, impl::abi_arg_out<Windows::Foundation::IAsyncActionWithProgress<Windows::Web::Syndication::TransferProgress>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().UpdateResourceAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const Windows::Web::Syndication::SyndicationItem *>(&item)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UpdateResourceItemAsync(impl::abi_arg_in<Windows::Web::Syndication::ISyndicationItem> item, impl::abi_arg_out<Windows::Foundation::IAsyncActionWithProgress<Windows::Web::Syndication::TransferProgress>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().UpdateResourceItemAsync(*reinterpret_cast<const Windows::Web::Syndication::SyndicationItem *>(&item)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteResourceAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_out<Windows::Foundation::IAsyncActionWithProgress<Windows::Web::Syndication::TransferProgress>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().DeleteResourceAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteResourceItemAsync(impl::abi_arg_in<Windows::Web::Syndication::ISyndicationItem> item, impl::abi_arg_out<Windows::Foundation::IAsyncActionWithProgress<Windows::Web::Syndication::TransferProgress>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().DeleteResourceItemAsync(*reinterpret_cast<const Windows::Web::Syndication::SyndicationItem *>(&item)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CancelAsyncOperations() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CancelAsyncOperations();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::AtomPub::IAtomPubClientFactory> : produce_base<D, Windows::Web::AtomPub::IAtomPubClientFactory>
{
    HRESULT __stdcall abi_CreateAtomPubClientWithCredentials(impl::abi_arg_in<Windows::Security::Credentials::IPasswordCredential> serverCredential, impl::abi_arg_out<Windows::Web::AtomPub::IAtomPubClient> atomPubClient) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *atomPubClient = detach_abi(this->shim().CreateAtomPubClientWithCredentials(*reinterpret_cast<const Windows::Security::Credentials::PasswordCredential *>(&serverCredential)));
            return S_OK;
        }
        catch (...)
        {
            *atomPubClient = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Web::AtomPub::IResourceCollection> : produce_base<D, Windows::Web::AtomPub::IResourceCollection>
{
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

    HRESULT __stdcall get_Categories(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Web::Syndication::SyndicationCategory>> value) noexcept override
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

    HRESULT __stdcall get_Accepts(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Accepts());
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
struct produce<D, Windows::Web::AtomPub::IServiceDocument> : produce_base<D, Windows::Web::AtomPub::IServiceDocument>
{
    HRESULT __stdcall get_Workspaces(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Web::AtomPub::Workspace>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Workspaces());
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
struct produce<D, Windows::Web::AtomPub::IWorkspace> : produce_base<D, Windows::Web::AtomPub::IWorkspace>
{
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

    HRESULT __stdcall get_Collections(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Web::AtomPub::ResourceCollection>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Collections());
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

namespace Windows::Web::AtomPub {

template <typename D> Windows::Web::Syndication::ISyndicationText impl_IResourceCollection<D>::Title() const
{
    Windows::Web::Syndication::ISyndicationText value;
    check_hresult(WINRT_SHIM(IResourceCollection)->get_Title(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_IResourceCollection<D>::Uri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IResourceCollection)->get_Uri(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Web::Syndication::SyndicationCategory> impl_IResourceCollection<D>::Categories() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Web::Syndication::SyndicationCategory> value;
    check_hresult(WINRT_SHIM(IResourceCollection)->get_Categories(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IResourceCollection<D>::Accepts() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(IResourceCollection)->get_Accepts(put_abi(value)));
    return value;
}

template <typename D> Windows::Web::Syndication::ISyndicationText impl_IWorkspace<D>::Title() const
{
    Windows::Web::Syndication::ISyndicationText value;
    check_hresult(WINRT_SHIM(IWorkspace)->get_Title(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Web::AtomPub::ResourceCollection> impl_IWorkspace<D>::Collections() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Web::AtomPub::ResourceCollection> value;
    check_hresult(WINRT_SHIM(IWorkspace)->get_Collections(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Web::AtomPub::Workspace> impl_IServiceDocument<D>::Workspaces() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Web::AtomPub::Workspace> value;
    check_hresult(WINRT_SHIM(IServiceDocument)->get_Workspaces(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::AtomPub::ServiceDocument, Windows::Web::Syndication::RetrievalProgress> impl_IAtomPubClient<D>::RetrieveServiceDocumentAsync(const Windows::Foundation::Uri & uri) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::AtomPub::ServiceDocument, Windows::Web::Syndication::RetrievalProgress> operation;
    check_hresult(WINRT_SHIM(IAtomPubClient)->abi_RetrieveServiceDocumentAsync(get_abi(uri), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Storage::Streams::IInputStream, Windows::Web::Syndication::RetrievalProgress> impl_IAtomPubClient<D>::RetrieveMediaResourceAsync(const Windows::Foundation::Uri & uri) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Storage::Streams::IInputStream, Windows::Web::Syndication::RetrievalProgress> operation;
    check_hresult(WINRT_SHIM(IAtomPubClient)->abi_RetrieveMediaResourceAsync(get_abi(uri), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Syndication::SyndicationItem, Windows::Web::Syndication::RetrievalProgress> impl_IAtomPubClient<D>::RetrieveResourceAsync(const Windows::Foundation::Uri & uri) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Syndication::SyndicationItem, Windows::Web::Syndication::RetrievalProgress> operation;
    check_hresult(WINRT_SHIM(IAtomPubClient)->abi_RetrieveResourceAsync(get_abi(uri), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Syndication::SyndicationItem, Windows::Web::Syndication::TransferProgress> impl_IAtomPubClient<D>::CreateResourceAsync(const Windows::Foundation::Uri & uri, hstring_view description, const Windows::Web::Syndication::SyndicationItem & item) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Syndication::SyndicationItem, Windows::Web::Syndication::TransferProgress> operation;
    check_hresult(WINRT_SHIM(IAtomPubClient)->abi_CreateResourceAsync(get_abi(uri), get_abi(description), get_abi(item), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Syndication::SyndicationItem, Windows::Web::Syndication::TransferProgress> impl_IAtomPubClient<D>::CreateMediaResourceAsync(const Windows::Foundation::Uri & uri, hstring_view mediaType, hstring_view description, const Windows::Storage::Streams::IInputStream & mediaStream) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Syndication::SyndicationItem, Windows::Web::Syndication::TransferProgress> operation;
    check_hresult(WINRT_SHIM(IAtomPubClient)->abi_CreateMediaResourceAsync(get_abi(uri), get_abi(mediaType), get_abi(description), get_abi(mediaStream), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncActionWithProgress<Windows::Web::Syndication::TransferProgress> impl_IAtomPubClient<D>::UpdateMediaResourceAsync(const Windows::Foundation::Uri & uri, hstring_view mediaType, const Windows::Storage::Streams::IInputStream & mediaStream) const
{
    Windows::Foundation::IAsyncActionWithProgress<Windows::Web::Syndication::TransferProgress> operation;
    check_hresult(WINRT_SHIM(IAtomPubClient)->abi_UpdateMediaResourceAsync(get_abi(uri), get_abi(mediaType), get_abi(mediaStream), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncActionWithProgress<Windows::Web::Syndication::TransferProgress> impl_IAtomPubClient<D>::UpdateResourceAsync(const Windows::Foundation::Uri & uri, const Windows::Web::Syndication::SyndicationItem & item) const
{
    Windows::Foundation::IAsyncActionWithProgress<Windows::Web::Syndication::TransferProgress> operation;
    check_hresult(WINRT_SHIM(IAtomPubClient)->abi_UpdateResourceAsync(get_abi(uri), get_abi(item), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncActionWithProgress<Windows::Web::Syndication::TransferProgress> impl_IAtomPubClient<D>::UpdateResourceItemAsync(const Windows::Web::Syndication::SyndicationItem & item) const
{
    Windows::Foundation::IAsyncActionWithProgress<Windows::Web::Syndication::TransferProgress> operation;
    check_hresult(WINRT_SHIM(IAtomPubClient)->abi_UpdateResourceItemAsync(get_abi(item), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncActionWithProgress<Windows::Web::Syndication::TransferProgress> impl_IAtomPubClient<D>::DeleteResourceAsync(const Windows::Foundation::Uri & uri) const
{
    Windows::Foundation::IAsyncActionWithProgress<Windows::Web::Syndication::TransferProgress> operation;
    check_hresult(WINRT_SHIM(IAtomPubClient)->abi_DeleteResourceAsync(get_abi(uri), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncActionWithProgress<Windows::Web::Syndication::TransferProgress> impl_IAtomPubClient<D>::DeleteResourceItemAsync(const Windows::Web::Syndication::SyndicationItem & item) const
{
    Windows::Foundation::IAsyncActionWithProgress<Windows::Web::Syndication::TransferProgress> operation;
    check_hresult(WINRT_SHIM(IAtomPubClient)->abi_DeleteResourceItemAsync(get_abi(item), put_abi(operation)));
    return operation;
}

template <typename D> void impl_IAtomPubClient<D>::CancelAsyncOperations() const
{
    check_hresult(WINRT_SHIM(IAtomPubClient)->abi_CancelAsyncOperations());
}

template <typename D> Windows::Web::AtomPub::AtomPubClient impl_IAtomPubClientFactory<D>::CreateAtomPubClientWithCredentials(const Windows::Security::Credentials::PasswordCredential & serverCredential) const
{
    Windows::Web::AtomPub::AtomPubClient atomPubClient { nullptr };
    check_hresult(WINRT_SHIM(IAtomPubClientFactory)->abi_CreateAtomPubClientWithCredentials(get_abi(serverCredential), put_abi(atomPubClient)));
    return atomPubClient;
}

inline AtomPubClient::AtomPubClient() :
    AtomPubClient(activate_instance<AtomPubClient>())
{}

inline AtomPubClient::AtomPubClient(const Windows::Security::Credentials::PasswordCredential & serverCredential) :
    AtomPubClient(get_activation_factory<AtomPubClient, IAtomPubClientFactory>().CreateAtomPubClientWithCredentials(serverCredential))
{}

}

}
#pragma warning(pop)
