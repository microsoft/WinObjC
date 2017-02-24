// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.System.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Security.Cryptography.Core.3.h"
#include "internal/Windows.Security.Credentials.3.h"
#include "Windows.Foundation.Collections.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Security::Credentials::ICredentialFactory> : produce_base<D, Windows::Security::Credentials::ICredentialFactory>
{
    HRESULT __stdcall abi_CreatePasswordCredential(impl::abi_arg_in<hstring> resource, impl::abi_arg_in<hstring> userName, impl::abi_arg_in<hstring> password, impl::abi_arg_out<Windows::Security::Credentials::IPasswordCredential> credential) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *credential = detach_abi(this->shim().CreatePasswordCredential(*reinterpret_cast<const hstring *>(&resource), *reinterpret_cast<const hstring *>(&userName), *reinterpret_cast<const hstring *>(&password)));
            return S_OK;
        }
        catch (...)
        {
            *credential = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Credentials::IKeyCredential> : produce_base<D, Windows::Security::Credentials::IKeyCredential>
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

    HRESULT __stdcall abi_RetrievePublicKeyWithDefaultBlobType(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RetrievePublicKey());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RetrievePublicKeyWithBlobType(Windows::Security::Cryptography::Core::CryptographicPublicKeyBlobType blobType, impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RetrievePublicKey(blobType));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestSignAsync(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> data, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::KeyCredentialOperationResult>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequestSignAsync(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&data)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAttestationAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::KeyCredentialAttestationResult>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetAttestationAsync());
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
struct produce<D, Windows::Security::Credentials::IKeyCredentialAttestationResult> : produce_base<D, Windows::Security::Credentials::IKeyCredentialAttestationResult>
{
    HRESULT __stdcall get_CertificateChainBuffer(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CertificateChainBuffer());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AttestationBuffer(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AttestationBuffer());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Status(Windows::Security::Credentials::KeyCredentialAttestationStatus * value) noexcept override
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
struct produce<D, Windows::Security::Credentials::IKeyCredentialManagerStatics> : produce_base<D, Windows::Security::Credentials::IKeyCredentialManagerStatics>
{
    HRESULT __stdcall abi_IsSupportedAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsSupportedAsync());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RenewAttestationAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RenewAttestationAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestCreateAsync(impl::abi_arg_in<hstring> name, Windows::Security::Credentials::KeyCredentialCreationOption option, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::KeyCredentialRetrievalResult>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequestCreateAsync(*reinterpret_cast<const hstring *>(&name), option));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OpenAsync(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::KeyCredentialRetrievalResult>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OpenAsync(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteAsync(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().DeleteAsync(*reinterpret_cast<const hstring *>(&name)));
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
struct produce<D, Windows::Security::Credentials::IKeyCredentialOperationResult> : produce_base<D, Windows::Security::Credentials::IKeyCredentialOperationResult>
{
    HRESULT __stdcall get_Result(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Result());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Status(Windows::Security::Credentials::KeyCredentialStatus * value) noexcept override
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
struct produce<D, Windows::Security::Credentials::IKeyCredentialRetrievalResult> : produce_base<D, Windows::Security::Credentials::IKeyCredentialRetrievalResult>
{
    HRESULT __stdcall get_Credential(impl::abi_arg_out<Windows::Security::Credentials::IKeyCredential> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Credential());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Status(Windows::Security::Credentials::KeyCredentialStatus * value) noexcept override
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
struct produce<D, Windows::Security::Credentials::IPasswordCredential> : produce_base<D, Windows::Security::Credentials::IPasswordCredential>
{
    HRESULT __stdcall get_Resource(impl::abi_arg_out<hstring> resource) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *resource = detach_abi(this->shim().Resource());
            return S_OK;
        }
        catch (...)
        {
            *resource = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Resource(impl::abi_arg_in<hstring> resource) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Resource(*reinterpret_cast<const hstring *>(&resource));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UserName(impl::abi_arg_out<hstring> userName) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *userName = detach_abi(this->shim().UserName());
            return S_OK;
        }
        catch (...)
        {
            *userName = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_UserName(impl::abi_arg_in<hstring> userName) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UserName(*reinterpret_cast<const hstring *>(&userName));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Password(impl::abi_arg_out<hstring> password) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *password = detach_abi(this->shim().Password());
            return S_OK;
        }
        catch (...)
        {
            *password = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Password(impl::abi_arg_in<hstring> password) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Password(*reinterpret_cast<const hstring *>(&password));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RetrievePassword() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RetrievePassword();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Properties(impl::abi_arg_out<Windows::Foundation::Collections::IPropertySet> props) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *props = detach_abi(this->shim().Properties());
            return S_OK;
        }
        catch (...)
        {
            *props = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Credentials::IPasswordVault> : produce_base<D, Windows::Security::Credentials::IPasswordVault>
{
    HRESULT __stdcall abi_Add(impl::abi_arg_in<Windows::Security::Credentials::IPasswordCredential> credential) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Add(*reinterpret_cast<const Windows::Security::Credentials::PasswordCredential *>(&credential));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Remove(impl::abi_arg_in<Windows::Security::Credentials::IPasswordCredential> credential) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Remove(*reinterpret_cast<const Windows::Security::Credentials::PasswordCredential *>(&credential));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Retrieve(impl::abi_arg_in<hstring> resource, impl::abi_arg_in<hstring> userName, impl::abi_arg_out<Windows::Security::Credentials::IPasswordCredential> credential) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *credential = detach_abi(this->shim().Retrieve(*reinterpret_cast<const hstring *>(&resource), *reinterpret_cast<const hstring *>(&userName)));
            return S_OK;
        }
        catch (...)
        {
            *credential = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAllByResource(impl::abi_arg_in<hstring> resource, impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Security::Credentials::PasswordCredential>> credentials) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *credentials = detach_abi(this->shim().FindAllByResource(*reinterpret_cast<const hstring *>(&resource)));
            return S_OK;
        }
        catch (...)
        {
            *credentials = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAllByUserName(impl::abi_arg_in<hstring> userName, impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Security::Credentials::PasswordCredential>> credentials) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *credentials = detach_abi(this->shim().FindAllByUserName(*reinterpret_cast<const hstring *>(&userName)));
            return S_OK;
        }
        catch (...)
        {
            *credentials = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RetrieveAll(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Security::Credentials::PasswordCredential>> credentials) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *credentials = detach_abi(this->shim().RetrieveAll());
            return S_OK;
        }
        catch (...)
        {
            *credentials = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Credentials::IWebAccount> : produce_base<D, Windows::Security::Credentials::IWebAccount>
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

    HRESULT __stdcall get_UserName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UserName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_State(Windows::Security::Credentials::WebAccountState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().State());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Credentials::IWebAccount2> : produce_base<D, Windows::Security::Credentials::IWebAccount2>
{
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

    HRESULT __stdcall get_Properties(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, hstring>> value) noexcept override
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

    HRESULT __stdcall abi_GetPictureAsync(Windows::Security::Credentials::WebAccountPictureSize desizedSize, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().GetPictureAsync(desizedSize));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SignOutAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().SignOutAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SignOutWithClientIdAsync(impl::abi_arg_in<hstring> clientId, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().SignOutAsync(*reinterpret_cast<const hstring *>(&clientId)));
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
struct produce<D, Windows::Security::Credentials::IWebAccountFactory> : produce_base<D, Windows::Security::Credentials::IWebAccountFactory>
{
    HRESULT __stdcall abi_CreateWebAccount(impl::abi_arg_in<Windows::Security::Credentials::IWebAccountProvider> webAccountProvider, impl::abi_arg_in<hstring> userName, Windows::Security::Credentials::WebAccountState state, impl::abi_arg_out<Windows::Security::Credentials::IWebAccount> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateWebAccount(*reinterpret_cast<const Windows::Security::Credentials::WebAccountProvider *>(&webAccountProvider), *reinterpret_cast<const hstring *>(&userName), state));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Credentials::IWebAccountProvider> : produce_base<D, Windows::Security::Credentials::IWebAccountProvider>
{
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

    HRESULT __stdcall get_DisplayName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
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
};

template <typename D>
struct produce<D, Windows::Security::Credentials::IWebAccountProvider2> : produce_base<D, Windows::Security::Credentials::IWebAccountProvider2>
{
    HRESULT __stdcall get_DisplayPurpose(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayPurpose());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Authority(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Authority());
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
struct produce<D, Windows::Security::Credentials::IWebAccountProvider3> : produce_base<D, Windows::Security::Credentials::IWebAccountProvider3>
{
    HRESULT __stdcall get_User(impl::abi_arg_out<Windows::System::IUser> user) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *user = detach_abi(this->shim().User());
            return S_OK;
        }
        catch (...)
        {
            *user = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Credentials::IWebAccountProviderFactory> : produce_base<D, Windows::Security::Credentials::IWebAccountProviderFactory>
{
    HRESULT __stdcall abi_CreateWebAccountProvider(impl::abi_arg_in<hstring> id, impl::abi_arg_in<hstring> displayName, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> iconUri, impl::abi_arg_out<Windows::Security::Credentials::IWebAccountProvider> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateWebAccountProvider(*reinterpret_cast<const hstring *>(&id), *reinterpret_cast<const hstring *>(&displayName), *reinterpret_cast<const Windows::Foundation::Uri *>(&iconUri)));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Security::Credentials {

template <typename D> Windows::Security::Credentials::WebAccount impl_IWebAccountFactory<D>::CreateWebAccount(const Windows::Security::Credentials::WebAccountProvider & webAccountProvider, hstring_view userName, Windows::Security::Credentials::WebAccountState state) const
{
    Windows::Security::Credentials::WebAccount instance { nullptr };
    check_hresult(WINRT_SHIM(IWebAccountFactory)->abi_CreateWebAccount(get_abi(webAccountProvider), get_abi(userName), state, put_abi(instance)));
    return instance;
}

template <typename D> Windows::Security::Credentials::WebAccountProvider impl_IWebAccount<D>::WebAccountProvider() const
{
    Windows::Security::Credentials::WebAccountProvider value { nullptr };
    check_hresult(WINRT_SHIM(IWebAccount)->get_WebAccountProvider(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IWebAccount<D>::UserName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWebAccount)->get_UserName(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Credentials::WebAccountState impl_IWebAccount<D>::State() const
{
    Windows::Security::Credentials::WebAccountState value {};
    check_hresult(WINRT_SHIM(IWebAccount)->get_State(&value));
    return value;
}

template <typename D> hstring impl_IWebAccount2<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWebAccount2)->get_Id(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, hstring> impl_IWebAccount2<D>::Properties() const
{
    Windows::Foundation::Collections::IMapView<hstring, hstring> value;
    check_hresult(WINRT_SHIM(IWebAccount2)->get_Properties(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> impl_IWebAccount2<D>::GetPictureAsync(Windows::Security::Credentials::WebAccountPictureSize desizedSize) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> asyncInfo;
    check_hresult(WINRT_SHIM(IWebAccount2)->abi_GetPictureAsync(desizedSize, put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IWebAccount2<D>::SignOutAsync() const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IWebAccount2)->abi_SignOutAsync(put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IWebAccount2<D>::SignOutAsync(hstring_view clientId) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IWebAccount2)->abi_SignOutWithClientIdAsync(get_abi(clientId), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Security::Credentials::WebAccountProvider impl_IWebAccountProviderFactory<D>::CreateWebAccountProvider(hstring_view id, hstring_view displayName, const Windows::Foundation::Uri & iconUri) const
{
    Windows::Security::Credentials::WebAccountProvider instance { nullptr };
    check_hresult(WINRT_SHIM(IWebAccountProviderFactory)->abi_CreateWebAccountProvider(get_abi(id), get_abi(displayName), get_abi(iconUri), put_abi(instance)));
    return instance;
}

template <typename D> hstring impl_IWebAccountProvider<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWebAccountProvider)->get_Id(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IWebAccountProvider<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWebAccountProvider)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_IWebAccountProvider<D>::IconUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IWebAccountProvider)->get_IconUri(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IWebAccountProvider2<D>::DisplayPurpose() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWebAccountProvider2)->get_DisplayPurpose(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IWebAccountProvider2<D>::Authority() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWebAccountProvider2)->get_Authority(put_abi(value)));
    return value;
}

template <typename D> Windows::System::User impl_IWebAccountProvider3<D>::User() const
{
    Windows::System::User user { nullptr };
    check_hresult(WINRT_SHIM(IWebAccountProvider3)->get_User(put_abi(user)));
    return user;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IKeyCredentialManagerStatics<D>::IsSupportedAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> value;
    check_hresult(WINRT_SHIM(IKeyCredentialManagerStatics)->abi_IsSupportedAsync(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IKeyCredentialManagerStatics<D>::RenewAttestationAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IKeyCredentialManagerStatics)->abi_RenewAttestationAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::KeyCredentialRetrievalResult> impl_IKeyCredentialManagerStatics<D>::RequestCreateAsync(hstring_view name, Windows::Security::Credentials::KeyCredentialCreationOption option) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::KeyCredentialRetrievalResult> value;
    check_hresult(WINRT_SHIM(IKeyCredentialManagerStatics)->abi_RequestCreateAsync(get_abi(name), option, put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::KeyCredentialRetrievalResult> impl_IKeyCredentialManagerStatics<D>::OpenAsync(hstring_view name) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::KeyCredentialRetrievalResult> value;
    check_hresult(WINRT_SHIM(IKeyCredentialManagerStatics)->abi_OpenAsync(get_abi(name), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IKeyCredentialManagerStatics<D>::DeleteAsync(hstring_view name) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IKeyCredentialManagerStatics)->abi_DeleteAsync(get_abi(name), put_abi(operation)));
    return operation;
}

template <typename D> hstring impl_IKeyCredential<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKeyCredential)->get_Name(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IKeyCredential<D>::RetrievePublicKey() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IKeyCredential)->abi_RetrievePublicKeyWithDefaultBlobType(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IKeyCredential<D>::RetrievePublicKey(Windows::Security::Cryptography::Core::CryptographicPublicKeyBlobType blobType) const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IKeyCredential)->abi_RetrievePublicKeyWithBlobType(blobType, put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::KeyCredentialOperationResult> impl_IKeyCredential<D>::RequestSignAsync(const Windows::Storage::Streams::IBuffer & data) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::KeyCredentialOperationResult> value;
    check_hresult(WINRT_SHIM(IKeyCredential)->abi_RequestSignAsync(get_abi(data), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::KeyCredentialAttestationResult> impl_IKeyCredential<D>::GetAttestationAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::KeyCredentialAttestationResult> value;
    check_hresult(WINRT_SHIM(IKeyCredential)->abi_GetAttestationAsync(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Credentials::KeyCredential impl_IKeyCredentialRetrievalResult<D>::Credential() const
{
    Windows::Security::Credentials::KeyCredential value { nullptr };
    check_hresult(WINRT_SHIM(IKeyCredentialRetrievalResult)->get_Credential(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Credentials::KeyCredentialStatus impl_IKeyCredentialRetrievalResult<D>::Status() const
{
    Windows::Security::Credentials::KeyCredentialStatus value {};
    check_hresult(WINRT_SHIM(IKeyCredentialRetrievalResult)->get_Status(&value));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IKeyCredentialOperationResult<D>::Result() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IKeyCredentialOperationResult)->get_Result(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Credentials::KeyCredentialStatus impl_IKeyCredentialOperationResult<D>::Status() const
{
    Windows::Security::Credentials::KeyCredentialStatus value {};
    check_hresult(WINRT_SHIM(IKeyCredentialOperationResult)->get_Status(&value));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IKeyCredentialAttestationResult<D>::CertificateChainBuffer() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IKeyCredentialAttestationResult)->get_CertificateChainBuffer(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IKeyCredentialAttestationResult<D>::AttestationBuffer() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IKeyCredentialAttestationResult)->get_AttestationBuffer(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Credentials::KeyCredentialAttestationStatus impl_IKeyCredentialAttestationResult<D>::Status() const
{
    Windows::Security::Credentials::KeyCredentialAttestationStatus value {};
    check_hresult(WINRT_SHIM(IKeyCredentialAttestationResult)->get_Status(&value));
    return value;
}

template <typename D> hstring impl_IPasswordCredential<D>::Resource() const
{
    hstring resource;
    check_hresult(WINRT_SHIM(IPasswordCredential)->get_Resource(put_abi(resource)));
    return resource;
}

template <typename D> void impl_IPasswordCredential<D>::Resource(hstring_view resource) const
{
    check_hresult(WINRT_SHIM(IPasswordCredential)->put_Resource(get_abi(resource)));
}

template <typename D> hstring impl_IPasswordCredential<D>::UserName() const
{
    hstring userName;
    check_hresult(WINRT_SHIM(IPasswordCredential)->get_UserName(put_abi(userName)));
    return userName;
}

template <typename D> void impl_IPasswordCredential<D>::UserName(hstring_view userName) const
{
    check_hresult(WINRT_SHIM(IPasswordCredential)->put_UserName(get_abi(userName)));
}

template <typename D> hstring impl_IPasswordCredential<D>::Password() const
{
    hstring password;
    check_hresult(WINRT_SHIM(IPasswordCredential)->get_Password(put_abi(password)));
    return password;
}

template <typename D> void impl_IPasswordCredential<D>::Password(hstring_view password) const
{
    check_hresult(WINRT_SHIM(IPasswordCredential)->put_Password(get_abi(password)));
}

template <typename D> void impl_IPasswordCredential<D>::RetrievePassword() const
{
    check_hresult(WINRT_SHIM(IPasswordCredential)->abi_RetrievePassword());
}

template <typename D> Windows::Foundation::Collections::IPropertySet impl_IPasswordCredential<D>::Properties() const
{
    Windows::Foundation::Collections::IPropertySet props;
    check_hresult(WINRT_SHIM(IPasswordCredential)->get_Properties(put_abi(props)));
    return props;
}

template <typename D> Windows::Security::Credentials::PasswordCredential impl_ICredentialFactory<D>::CreatePasswordCredential(hstring_view resource, hstring_view userName, hstring_view password) const
{
    Windows::Security::Credentials::PasswordCredential credential { nullptr };
    check_hresult(WINRT_SHIM(ICredentialFactory)->abi_CreatePasswordCredential(get_abi(resource), get_abi(userName), get_abi(password), put_abi(credential)));
    return credential;
}

template <typename D> void impl_IPasswordVault<D>::Add(const Windows::Security::Credentials::PasswordCredential & credential) const
{
    check_hresult(WINRT_SHIM(IPasswordVault)->abi_Add(get_abi(credential)));
}

template <typename D> void impl_IPasswordVault<D>::Remove(const Windows::Security::Credentials::PasswordCredential & credential) const
{
    check_hresult(WINRT_SHIM(IPasswordVault)->abi_Remove(get_abi(credential)));
}

template <typename D> Windows::Security::Credentials::PasswordCredential impl_IPasswordVault<D>::Retrieve(hstring_view resource, hstring_view userName) const
{
    Windows::Security::Credentials::PasswordCredential credential { nullptr };
    check_hresult(WINRT_SHIM(IPasswordVault)->abi_Retrieve(get_abi(resource), get_abi(userName), put_abi(credential)));
    return credential;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Security::Credentials::PasswordCredential> impl_IPasswordVault<D>::FindAllByResource(hstring_view resource) const
{
    Windows::Foundation::Collections::IVectorView<Windows::Security::Credentials::PasswordCredential> credentials;
    check_hresult(WINRT_SHIM(IPasswordVault)->abi_FindAllByResource(get_abi(resource), put_abi(credentials)));
    return credentials;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Security::Credentials::PasswordCredential> impl_IPasswordVault<D>::FindAllByUserName(hstring_view userName) const
{
    Windows::Foundation::Collections::IVectorView<Windows::Security::Credentials::PasswordCredential> credentials;
    check_hresult(WINRT_SHIM(IPasswordVault)->abi_FindAllByUserName(get_abi(userName), put_abi(credentials)));
    return credentials;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Security::Credentials::PasswordCredential> impl_IPasswordVault<D>::RetrieveAll() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Security::Credentials::PasswordCredential> credentials;
    check_hresult(WINRT_SHIM(IPasswordVault)->abi_RetrieveAll(put_abi(credentials)));
    return credentials;
}

inline Windows::Foundation::IAsyncOperation<bool> KeyCredentialManager::IsSupportedAsync()
{
    return get_activation_factory<KeyCredentialManager, IKeyCredentialManagerStatics>().IsSupportedAsync();
}

inline Windows::Foundation::IAsyncAction KeyCredentialManager::RenewAttestationAsync()
{
    return get_activation_factory<KeyCredentialManager, IKeyCredentialManagerStatics>().RenewAttestationAsync();
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::KeyCredentialRetrievalResult> KeyCredentialManager::RequestCreateAsync(hstring_view name, Windows::Security::Credentials::KeyCredentialCreationOption option)
{
    return get_activation_factory<KeyCredentialManager, IKeyCredentialManagerStatics>().RequestCreateAsync(name, option);
}

inline Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::KeyCredentialRetrievalResult> KeyCredentialManager::OpenAsync(hstring_view name)
{
    return get_activation_factory<KeyCredentialManager, IKeyCredentialManagerStatics>().OpenAsync(name);
}

inline Windows::Foundation::IAsyncAction KeyCredentialManager::DeleteAsync(hstring_view name)
{
    return get_activation_factory<KeyCredentialManager, IKeyCredentialManagerStatics>().DeleteAsync(name);
}

inline PasswordCredential::PasswordCredential() :
    PasswordCredential(activate_instance<PasswordCredential>())
{}

inline PasswordCredential::PasswordCredential(hstring_view resource, hstring_view userName, hstring_view password) :
    PasswordCredential(get_activation_factory<PasswordCredential, ICredentialFactory>().CreatePasswordCredential(resource, userName, password))
{}

inline PasswordCredentialPropertyStore::PasswordCredentialPropertyStore() :
    PasswordCredentialPropertyStore(activate_instance<PasswordCredentialPropertyStore>())
{}

inline PasswordVault::PasswordVault() :
    PasswordVault(activate_instance<PasswordVault>())
{}

inline WebAccount::WebAccount(const Windows::Security::Credentials::WebAccountProvider & webAccountProvider, hstring_view userName, Windows::Security::Credentials::WebAccountState state) :
    WebAccount(get_activation_factory<WebAccount, IWebAccountFactory>().CreateWebAccount(webAccountProvider, userName, state))
{}

inline WebAccountProvider::WebAccountProvider(hstring_view id, hstring_view displayName, const Windows::Foundation::Uri & iconUri) :
    WebAccountProvider(get_activation_factory<WebAccountProvider, IWebAccountProviderFactory>().CreateWebAccountProvider(id, displayName, iconUri))
{}

}

}
#pragma warning(pop)
