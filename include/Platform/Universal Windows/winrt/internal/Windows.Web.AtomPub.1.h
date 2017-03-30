// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Web.AtomPub.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Security.Credentials.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Web.Syndication.0.h"
#include "Windows.Web.Syndication.1.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"
#include "Windows.Storage.Streams.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Web::AtomPub {

struct __declspec(uuid("35392c38-cded-4d4c-9637-05f15c1c9406")) __declspec(novtable) IAtomPubClient : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RetrieveServiceDocumentAsync(Windows::Foundation::IUriRuntimeClass * uri, Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::AtomPub::ServiceDocument, Windows::Web::Syndication::RetrievalProgress> ** operation) = 0;
    virtual HRESULT __stdcall abi_RetrieveMediaResourceAsync(Windows::Foundation::IUriRuntimeClass * uri, Windows::Foundation::IAsyncOperationWithProgress<Windows::Storage::Streams::IInputStream, Windows::Web::Syndication::RetrievalProgress> ** operation) = 0;
    virtual HRESULT __stdcall abi_RetrieveResourceAsync(Windows::Foundation::IUriRuntimeClass * uri, Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Syndication::SyndicationItem, Windows::Web::Syndication::RetrievalProgress> ** operation) = 0;
    virtual HRESULT __stdcall abi_CreateResourceAsync(Windows::Foundation::IUriRuntimeClass * uri, hstring description, Windows::Web::Syndication::ISyndicationItem * item, Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Syndication::SyndicationItem, Windows::Web::Syndication::TransferProgress> ** operation) = 0;
    virtual HRESULT __stdcall abi_CreateMediaResourceAsync(Windows::Foundation::IUriRuntimeClass * uri, hstring mediaType, hstring description, Windows::Storage::Streams::IInputStream * mediaStream, Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Syndication::SyndicationItem, Windows::Web::Syndication::TransferProgress> ** operation) = 0;
    virtual HRESULT __stdcall abi_UpdateMediaResourceAsync(Windows::Foundation::IUriRuntimeClass * uri, hstring mediaType, Windows::Storage::Streams::IInputStream * mediaStream, Windows::Foundation::IAsyncActionWithProgress<Windows::Web::Syndication::TransferProgress> ** operation) = 0;
    virtual HRESULT __stdcall abi_UpdateResourceAsync(Windows::Foundation::IUriRuntimeClass * uri, Windows::Web::Syndication::ISyndicationItem * item, Windows::Foundation::IAsyncActionWithProgress<Windows::Web::Syndication::TransferProgress> ** operation) = 0;
    virtual HRESULT __stdcall abi_UpdateResourceItemAsync(Windows::Web::Syndication::ISyndicationItem * item, Windows::Foundation::IAsyncActionWithProgress<Windows::Web::Syndication::TransferProgress> ** operation) = 0;
    virtual HRESULT __stdcall abi_DeleteResourceAsync(Windows::Foundation::IUriRuntimeClass * uri, Windows::Foundation::IAsyncActionWithProgress<Windows::Web::Syndication::TransferProgress> ** operation) = 0;
    virtual HRESULT __stdcall abi_DeleteResourceItemAsync(Windows::Web::Syndication::ISyndicationItem * item, Windows::Foundation::IAsyncActionWithProgress<Windows::Web::Syndication::TransferProgress> ** operation) = 0;
    virtual HRESULT __stdcall abi_CancelAsyncOperations() = 0;
};

struct __declspec(uuid("49d55012-57cb-4bde-ab9f-2610b172777b")) __declspec(novtable) IAtomPubClientFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateAtomPubClientWithCredentials(Windows::Security::Credentials::IPasswordCredential * serverCredential, Windows::Web::AtomPub::IAtomPubClient ** atomPubClient) = 0;
};

struct __declspec(uuid("7f5fd609-bc88-41d4-88fa-3de6704d428e")) __declspec(novtable) IResourceCollection : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Title(Windows::Web::Syndication::ISyndicationText ** value) = 0;
    virtual HRESULT __stdcall get_Uri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall get_Categories(Windows::Foundation::Collections::IVectorView<Windows::Web::Syndication::SyndicationCategory> ** value) = 0;
    virtual HRESULT __stdcall get_Accepts(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
};

struct __declspec(uuid("8b7ec771-2ab3-4dbe-8bcc-778f92b75e51")) __declspec(novtable) IServiceDocument : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Workspaces(Windows::Foundation::Collections::IVectorView<Windows::Web::AtomPub::Workspace> ** value) = 0;
};

struct __declspec(uuid("b41da63b-a4b8-4036-89c5-83c31266ba49")) __declspec(novtable) IWorkspace : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Title(Windows::Web::Syndication::ISyndicationText ** value) = 0;
    virtual HRESULT __stdcall get_Collections(Windows::Foundation::Collections::IVectorView<Windows::Web::AtomPub::ResourceCollection> ** value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Web::AtomPub::AtomPubClient> { using default_interface = Windows::Web::AtomPub::IAtomPubClient; };
template <> struct traits<Windows::Web::AtomPub::ResourceCollection> { using default_interface = Windows::Web::AtomPub::IResourceCollection; };
template <> struct traits<Windows::Web::AtomPub::ServiceDocument> { using default_interface = Windows::Web::AtomPub::IServiceDocument; };
template <> struct traits<Windows::Web::AtomPub::Workspace> { using default_interface = Windows::Web::AtomPub::IWorkspace; };

}

namespace Windows::Web::AtomPub {

template <typename D>
struct WINRT_EBO impl_IAtomPubClient
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::AtomPub::ServiceDocument, Windows::Web::Syndication::RetrievalProgress> RetrieveServiceDocumentAsync(const Windows::Foundation::Uri & uri) const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Storage::Streams::IInputStream, Windows::Web::Syndication::RetrievalProgress> RetrieveMediaResourceAsync(const Windows::Foundation::Uri & uri) const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Syndication::SyndicationItem, Windows::Web::Syndication::RetrievalProgress> RetrieveResourceAsync(const Windows::Foundation::Uri & uri) const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Syndication::SyndicationItem, Windows::Web::Syndication::TransferProgress> CreateResourceAsync(const Windows::Foundation::Uri & uri, hstring_view description, const Windows::Web::Syndication::SyndicationItem & item) const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Syndication::SyndicationItem, Windows::Web::Syndication::TransferProgress> CreateMediaResourceAsync(const Windows::Foundation::Uri & uri, hstring_view mediaType, hstring_view description, const Windows::Storage::Streams::IInputStream & mediaStream) const;
    Windows::Foundation::IAsyncActionWithProgress<Windows::Web::Syndication::TransferProgress> UpdateMediaResourceAsync(const Windows::Foundation::Uri & uri, hstring_view mediaType, const Windows::Storage::Streams::IInputStream & mediaStream) const;
    Windows::Foundation::IAsyncActionWithProgress<Windows::Web::Syndication::TransferProgress> UpdateResourceAsync(const Windows::Foundation::Uri & uri, const Windows::Web::Syndication::SyndicationItem & item) const;
    Windows::Foundation::IAsyncActionWithProgress<Windows::Web::Syndication::TransferProgress> UpdateResourceItemAsync(const Windows::Web::Syndication::SyndicationItem & item) const;
    Windows::Foundation::IAsyncActionWithProgress<Windows::Web::Syndication::TransferProgress> DeleteResourceAsync(const Windows::Foundation::Uri & uri) const;
    Windows::Foundation::IAsyncActionWithProgress<Windows::Web::Syndication::TransferProgress> DeleteResourceItemAsync(const Windows::Web::Syndication::SyndicationItem & item) const;
    void CancelAsyncOperations() const;
};

template <typename D>
struct WINRT_EBO impl_IAtomPubClientFactory
{
    Windows::Web::AtomPub::AtomPubClient CreateAtomPubClientWithCredentials(const Windows::Security::Credentials::PasswordCredential & serverCredential) const;
};

template <typename D>
struct WINRT_EBO impl_IResourceCollection
{
    Windows::Web::Syndication::ISyndicationText Title() const;
    Windows::Foundation::Uri Uri() const;
    Windows::Foundation::Collections::IVectorView<Windows::Web::Syndication::SyndicationCategory> Categories() const;
    Windows::Foundation::Collections::IVectorView<hstring> Accepts() const;
};

template <typename D>
struct WINRT_EBO impl_IServiceDocument
{
    Windows::Foundation::Collections::IVectorView<Windows::Web::AtomPub::Workspace> Workspaces() const;
};

template <typename D>
struct WINRT_EBO impl_IWorkspace
{
    Windows::Web::Syndication::ISyndicationText Title() const;
    Windows::Foundation::Collections::IVectorView<Windows::Web::AtomPub::ResourceCollection> Collections() const;
};

}

namespace impl {

template <> struct traits<Windows::Web::AtomPub::IAtomPubClient>
{
    using abi = ABI::Windows::Web::AtomPub::IAtomPubClient;
    template <typename D> using consume = Windows::Web::AtomPub::impl_IAtomPubClient<D>;
};

template <> struct traits<Windows::Web::AtomPub::IAtomPubClientFactory>
{
    using abi = ABI::Windows::Web::AtomPub::IAtomPubClientFactory;
    template <typename D> using consume = Windows::Web::AtomPub::impl_IAtomPubClientFactory<D>;
};

template <> struct traits<Windows::Web::AtomPub::IResourceCollection>
{
    using abi = ABI::Windows::Web::AtomPub::IResourceCollection;
    template <typename D> using consume = Windows::Web::AtomPub::impl_IResourceCollection<D>;
};

template <> struct traits<Windows::Web::AtomPub::IServiceDocument>
{
    using abi = ABI::Windows::Web::AtomPub::IServiceDocument;
    template <typename D> using consume = Windows::Web::AtomPub::impl_IServiceDocument<D>;
};

template <> struct traits<Windows::Web::AtomPub::IWorkspace>
{
    using abi = ABI::Windows::Web::AtomPub::IWorkspace;
    template <typename D> using consume = Windows::Web::AtomPub::impl_IWorkspace<D>;
};

template <> struct traits<Windows::Web::AtomPub::AtomPubClient>
{
    using abi = ABI::Windows::Web::AtomPub::AtomPubClient;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.AtomPub.AtomPubClient"; }
};

template <> struct traits<Windows::Web::AtomPub::ResourceCollection>
{
    using abi = ABI::Windows::Web::AtomPub::ResourceCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.AtomPub.ResourceCollection"; }
};

template <> struct traits<Windows::Web::AtomPub::ServiceDocument>
{
    using abi = ABI::Windows::Web::AtomPub::ServiceDocument;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.AtomPub.ServiceDocument"; }
};

template <> struct traits<Windows::Web::AtomPub::Workspace>
{
    using abi = ABI::Windows::Web::AtomPub::Workspace;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.AtomPub.Workspace"; }
};

}

}
