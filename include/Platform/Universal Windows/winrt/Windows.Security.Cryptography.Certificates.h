// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Networking.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Security.Cryptography.Certificates.3.h"
#include "Windows.Security.Cryptography.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Security::Cryptography::Certificates::ICertificate> : produce_base<D, Windows::Security::Cryptography::Certificates::ICertificate>
{
    HRESULT __stdcall abi_BuildChainAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate>> certificates, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::Cryptography::Certificates::CertificateChain>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BuildChainAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate> *>(&certificates)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_BuildChainWithParametersAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate>> certificates, impl::abi_arg_in<Windows::Security::Cryptography::Certificates::IChainBuildingParameters> parameters, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::Cryptography::Certificates::CertificateChain>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BuildChainAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate> *>(&certificates), *reinterpret_cast<const Windows::Security::Cryptography::Certificates::ChainBuildingParameters *>(&parameters)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SerialNumber(uint32_t * __valueSize, impl::abi_arg_out<uint8_t> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            std::tie(*__valueSize, *value) = detach_abi(this->shim().SerialNumber());
            return S_OK;
        }
        catch (...)
        {
            *__valueSize = 0;
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetHashValue(uint32_t * __valueSize, impl::abi_arg_out<uint8_t> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            std::tie(*__valueSize, *value) = detach_abi(this->shim().GetHashValue());
            return S_OK;
        }
        catch (...)
        {
            *__valueSize = 0;
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetHashValueWithAlgorithm(impl::abi_arg_in<hstring> hashAlgorithmName, uint32_t * __valueSize, impl::abi_arg_out<uint8_t> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            std::tie(*__valueSize, *value) = detach_abi(this->shim().GetHashValue(*reinterpret_cast<const hstring *>(&hashAlgorithmName)));
            return S_OK;
        }
        catch (...)
        {
            *__valueSize = 0;
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCertificateBlob(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetCertificateBlob());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Subject(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Subject());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Issuer(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Issuer());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HasPrivateKey(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HasPrivateKey());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsStronglyProtected(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsStronglyProtected());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ValidFrom(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ValidFrom());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ValidTo(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ValidTo());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EnhancedKeyUsages(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EnhancedKeyUsages());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FriendlyName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FriendlyName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FriendlyName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FriendlyName());
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
struct produce<D, Windows::Security::Cryptography::Certificates::ICertificate2> : produce_base<D, Windows::Security::Cryptography::Certificates::ICertificate2>
{
    HRESULT __stdcall get_IsSecurityDeviceBound(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsSecurityDeviceBound());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KeyUsages(impl::abi_arg_out<Windows::Security::Cryptography::Certificates::ICertificateKeyUsages> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeyUsages());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KeyAlgorithmName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeyAlgorithmName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SignatureAlgorithmName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SignatureAlgorithmName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SignatureHashAlgorithmName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SignatureHashAlgorithmName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SubjectAlternativeName(impl::abi_arg_out<Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SubjectAlternativeName());
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
struct produce<D, Windows::Security::Cryptography::Certificates::ICertificate3> : produce_base<D, Windows::Security::Cryptography::Certificates::ICertificate3>
{
    HRESULT __stdcall get_IsPerUser(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsPerUser());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StoreName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StoreName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KeyStorageProviderName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeyStorageProviderName());
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
struct produce<D, Windows::Security::Cryptography::Certificates::ICertificateChain> : produce_base<D, Windows::Security::Cryptography::Certificates::ICertificateChain>
{
    HRESULT __stdcall abi_Validate(Windows::Security::Cryptography::Certificates::ChainValidationResult * status) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *status = detach_abi(this->shim().Validate());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ValidateWithParameters(impl::abi_arg_in<Windows::Security::Cryptography::Certificates::IChainValidationParameters> parameter, Windows::Security::Cryptography::Certificates::ChainValidationResult * status) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *status = detach_abi(this->shim().Validate(*reinterpret_cast<const Windows::Security::Cryptography::Certificates::ChainValidationParameters *>(&parameter)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCertificates(bool includeRoot, impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate>> certificates) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *certificates = detach_abi(this->shim().GetCertificates(includeRoot));
            return S_OK;
        }
        catch (...)
        {
            *certificates = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics> : produce_base<D, Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics>
{
    HRESULT __stdcall abi_CreateRequestAsync(impl::abi_arg_in<Windows::Security::Cryptography::Certificates::ICertificateRequestProperties> request, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateRequestAsync(*reinterpret_cast<const Windows::Security::Cryptography::Certificates::CertificateRequestProperties *>(&request)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_InstallCertificateAsync(impl::abi_arg_in<hstring> certificate, Windows::Security::Cryptography::Certificates::InstallOptions installOption, impl::abi_arg_out<Windows::Foundation::IAsyncAction> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InstallCertificateAsync(*reinterpret_cast<const hstring *>(&certificate), installOption));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ImportPfxDataAsync(impl::abi_arg_in<hstring> pfxData, impl::abi_arg_in<hstring> password, Windows::Security::Cryptography::Certificates::ExportOption exportable, Windows::Security::Cryptography::Certificates::KeyProtectionLevel keyProtectionLevel, Windows::Security::Cryptography::Certificates::InstallOptions installOption, impl::abi_arg_in<hstring> friendlyName, impl::abi_arg_out<Windows::Foundation::IAsyncAction> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ImportPfxDataAsync(*reinterpret_cast<const hstring *>(&pfxData), *reinterpret_cast<const hstring *>(&password), exportable, keyProtectionLevel, installOption, *reinterpret_cast<const hstring *>(&friendlyName)));
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
struct produce<D, Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics2> : produce_base<D, Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics2>
{
    HRESULT __stdcall get_UserCertificateEnrollmentManager(impl::abi_arg_out<Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UserCertificateEnrollmentManager());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ImportPfxDataToKspAsync(impl::abi_arg_in<hstring> pfxData, impl::abi_arg_in<hstring> password, Windows::Security::Cryptography::Certificates::ExportOption exportable, Windows::Security::Cryptography::Certificates::KeyProtectionLevel keyProtectionLevel, Windows::Security::Cryptography::Certificates::InstallOptions installOption, impl::abi_arg_in<hstring> friendlyName, impl::abi_arg_in<hstring> keyStorageProvider, impl::abi_arg_out<Windows::Foundation::IAsyncAction> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ImportPfxDataAsync(*reinterpret_cast<const hstring *>(&pfxData), *reinterpret_cast<const hstring *>(&password), exportable, keyProtectionLevel, installOption, *reinterpret_cast<const hstring *>(&friendlyName), *reinterpret_cast<const hstring *>(&keyStorageProvider)));
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
struct produce<D, Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics3> : produce_base<D, Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics3>
{
    HRESULT __stdcall abi_ImportPfxDataToKspWithParametersAsync(impl::abi_arg_in<hstring> pfxData, impl::abi_arg_in<hstring> password, impl::abi_arg_in<Windows::Security::Cryptography::Certificates::IPfxImportParameters> pfxImportParameters, impl::abi_arg_out<Windows::Foundation::IAsyncAction> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ImportPfxDataAsync(*reinterpret_cast<const hstring *>(&pfxData), *reinterpret_cast<const hstring *>(&password), *reinterpret_cast<const Windows::Security::Cryptography::Certificates::PfxImportParameters *>(&pfxImportParameters)));
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
struct produce<D, Windows::Security::Cryptography::Certificates::ICertificateFactory> : produce_base<D, Windows::Security::Cryptography::Certificates::ICertificateFactory>
{
    HRESULT __stdcall abi_CreateCertificate(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> certBlob, impl::abi_arg_out<Windows::Security::Cryptography::Certificates::ICertificate> certificate) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *certificate = detach_abi(this->shim().CreateCertificate(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&certBlob)));
            return S_OK;
        }
        catch (...)
        {
            *certificate = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Cryptography::Certificates::ICertificateKeyUsages> : produce_base<D, Windows::Security::Cryptography::Certificates::ICertificateKeyUsages>
{
    HRESULT __stdcall get_EncipherOnly(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EncipherOnly());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EncipherOnly(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EncipherOnly(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CrlSign(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CrlSign());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CrlSign(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CrlSign(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KeyCertificateSign(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeyCertificateSign());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_KeyCertificateSign(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().KeyCertificateSign(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KeyAgreement(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeyAgreement());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_KeyAgreement(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().KeyAgreement(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DataEncipherment(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DataEncipherment());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DataEncipherment(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DataEncipherment(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KeyEncipherment(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeyEncipherment());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_KeyEncipherment(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().KeyEncipherment(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NonRepudiation(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NonRepudiation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_NonRepudiation(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NonRepudiation(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DigitalSignature(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DigitalSignature());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DigitalSignature(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DigitalSignature(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Cryptography::Certificates::ICertificateQuery> : produce_base<D, Windows::Security::Cryptography::Certificates::ICertificateQuery>
{
    HRESULT __stdcall get_EnhancedKeyUsages(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EnhancedKeyUsages());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IssuerName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IssuerName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IssuerName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IssuerName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FriendlyName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FriendlyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FriendlyName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FriendlyName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Thumbprint(uint32_t * __valueSize, impl::abi_arg_out<uint8_t> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            std::tie(*__valueSize, *value) = detach_abi(this->shim().Thumbprint());
            return S_OK;
        }
        catch (...)
        {
            *__valueSize = 0;
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Thumbprint(uint32_t __valueSize, impl::abi_arg_in<uint8_t> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Thumbprint(array_view<const uint8_t>(value, value + __valueSize));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HardwareOnly(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HardwareOnly());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_HardwareOnly(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HardwareOnly(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Cryptography::Certificates::ICertificateQuery2> : produce_base<D, Windows::Security::Cryptography::Certificates::ICertificateQuery2>
{
    HRESULT __stdcall get_IncludeDuplicates(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IncludeDuplicates());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IncludeDuplicates(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IncludeDuplicates(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IncludeExpiredCertificates(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IncludeExpiredCertificates());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IncludeExpiredCertificates(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IncludeExpiredCertificates(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StoreName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StoreName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StoreName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StoreName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Cryptography::Certificates::ICertificateRequestProperties> : produce_base<D, Windows::Security::Cryptography::Certificates::ICertificateRequestProperties>
{
    HRESULT __stdcall get_Subject(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Subject());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Subject(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Subject(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KeyAlgorithmName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeyAlgorithmName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_KeyAlgorithmName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().KeyAlgorithmName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KeySize(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeySize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_KeySize(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().KeySize(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FriendlyName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FriendlyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FriendlyName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FriendlyName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HashAlgorithmName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HashAlgorithmName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_HashAlgorithmName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HashAlgorithmName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Exportable(Windows::Security::Cryptography::Certificates::ExportOption * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Exportable());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Exportable(Windows::Security::Cryptography::Certificates::ExportOption value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Exportable(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KeyUsages(Windows::Security::Cryptography::Certificates::EnrollKeyUsages * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeyUsages());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_KeyUsages(Windows::Security::Cryptography::Certificates::EnrollKeyUsages value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().KeyUsages(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KeyProtectionLevel(Windows::Security::Cryptography::Certificates::KeyProtectionLevel * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeyProtectionLevel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_KeyProtectionLevel(Windows::Security::Cryptography::Certificates::KeyProtectionLevel value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().KeyProtectionLevel(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KeyStorageProviderName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeyStorageProviderName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_KeyStorageProviderName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().KeyStorageProviderName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Cryptography::Certificates::ICertificateRequestProperties2> : produce_base<D, Windows::Security::Cryptography::Certificates::ICertificateRequestProperties2>
{
    HRESULT __stdcall get_SmartcardReaderName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SmartcardReaderName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SmartcardReaderName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SmartcardReaderName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SigningCertificate(impl::abi_arg_out<Windows::Security::Cryptography::Certificates::ICertificate> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SigningCertificate());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SigningCertificate(impl::abi_arg_in<Windows::Security::Cryptography::Certificates::ICertificate> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SigningCertificate(*reinterpret_cast<const Windows::Security::Cryptography::Certificates::Certificate *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AttestationCredentialCertificate(impl::abi_arg_out<Windows::Security::Cryptography::Certificates::ICertificate> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AttestationCredentialCertificate());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AttestationCredentialCertificate(impl::abi_arg_in<Windows::Security::Cryptography::Certificates::ICertificate> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AttestationCredentialCertificate(*reinterpret_cast<const Windows::Security::Cryptography::Certificates::Certificate *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Cryptography::Certificates::ICertificateRequestProperties3> : produce_base<D, Windows::Security::Cryptography::Certificates::ICertificateRequestProperties3>
{
    HRESULT __stdcall get_CurveName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CurveName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CurveName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CurveName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CurveParameters(uint32_t * __valueSize, impl::abi_arg_out<uint8_t> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            std::tie(*__valueSize, *value) = detach_abi(this->shim().CurveParameters());
            return S_OK;
        }
        catch (...)
        {
            *__valueSize = 0;
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CurveParameters(uint32_t __valueSize, impl::abi_arg_in<uint8_t> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CurveParameters(array_view<const uint8_t>(value, value + __valueSize));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContainerNamePrefix(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContainerNamePrefix());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ContainerNamePrefix(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContainerNamePrefix(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContainerName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContainerName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ContainerName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContainerName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UseExistingKey(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UseExistingKey());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_UseExistingKey(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UseExistingKey(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Cryptography::Certificates::ICertificateStore> : produce_base<D, Windows::Security::Cryptography::Certificates::ICertificateStore>
{
    HRESULT __stdcall abi_Add(impl::abi_arg_in<Windows::Security::Cryptography::Certificates::ICertificate> certificate) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Add(*reinterpret_cast<const Windows::Security::Cryptography::Certificates::Certificate *>(&certificate));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Delete(impl::abi_arg_in<Windows::Security::Cryptography::Certificates::ICertificate> certificate) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Delete(*reinterpret_cast<const Windows::Security::Cryptography::Certificates::Certificate *>(&certificate));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Cryptography::Certificates::ICertificateStore2> : produce_base<D, Windows::Security::Cryptography::Certificates::ICertificateStore2>
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
};

template <typename D>
struct produce<D, Windows::Security::Cryptography::Certificates::ICertificateStoresStatics> : produce_base<D, Windows::Security::Cryptography::Certificates::ICertificateStoresStatics>
{
    HRESULT __stdcall abi_FindAllAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate>>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FindAllAsync());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAllWithQueryAsync(impl::abi_arg_in<Windows::Security::Cryptography::Certificates::ICertificateQuery> query, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate>>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FindAllAsync(*reinterpret_cast<const Windows::Security::Cryptography::Certificates::CertificateQuery *>(&query)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TrustedRootCertificationAuthorities(impl::abi_arg_out<Windows::Security::Cryptography::Certificates::ICertificateStore> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TrustedRootCertificationAuthorities());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IntermediateCertificationAuthorities(impl::abi_arg_out<Windows::Security::Cryptography::Certificates::ICertificateStore> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IntermediateCertificationAuthorities());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStoreByName(impl::abi_arg_in<hstring> storeName, impl::abi_arg_out<Windows::Security::Cryptography::Certificates::ICertificateStore> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetStoreByName(*reinterpret_cast<const hstring *>(&storeName)));
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
struct produce<D, Windows::Security::Cryptography::Certificates::ICertificateStoresStatics2> : produce_base<D, Windows::Security::Cryptography::Certificates::ICertificateStoresStatics2>
{
    HRESULT __stdcall abi_GetUserStoreByName(impl::abi_arg_in<hstring> storeName, impl::abi_arg_out<Windows::Security::Cryptography::Certificates::IUserCertificateStore> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetUserStoreByName(*reinterpret_cast<const hstring *>(&storeName)));
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
struct produce<D, Windows::Security::Cryptography::Certificates::IChainBuildingParameters> : produce_base<D, Windows::Security::Cryptography::Certificates::IChainBuildingParameters>
{
    HRESULT __stdcall get_EnhancedKeyUsages(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EnhancedKeyUsages());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ValidationTimestamp(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ValidationTimestamp());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ValidationTimestamp(impl::abi_arg_in<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ValidationTimestamp(*reinterpret_cast<const Windows::Foundation::DateTime *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RevocationCheckEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RevocationCheckEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RevocationCheckEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RevocationCheckEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NetworkRetrievalEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NetworkRetrievalEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_NetworkRetrievalEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NetworkRetrievalEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AuthorityInformationAccessEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AuthorityInformationAccessEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AuthorityInformationAccessEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AuthorityInformationAccessEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CurrentTimeValidationEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CurrentTimeValidationEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CurrentTimeValidationEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CurrentTimeValidationEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExclusiveTrustRoots(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::Certificate>> certificates) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *certificates = detach_abi(this->shim().ExclusiveTrustRoots());
            return S_OK;
        }
        catch (...)
        {
            *certificates = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Cryptography::Certificates::IChainValidationParameters> : produce_base<D, Windows::Security::Cryptography::Certificates::IChainValidationParameters>
{
    HRESULT __stdcall get_CertificateChainPolicy(Windows::Security::Cryptography::Certificates::CertificateChainPolicy * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CertificateChainPolicy());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CertificateChainPolicy(Windows::Security::Cryptography::Certificates::CertificateChainPolicy value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CertificateChainPolicy(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServerDnsName(impl::abi_arg_out<Windows::Networking::IHostName> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServerDnsName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ServerDnsName(impl::abi_arg_in<Windows::Networking::IHostName> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ServerDnsName(*reinterpret_cast<const Windows::Networking::HostName *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Cryptography::Certificates::ICmsAttachedSignature> : produce_base<D, Windows::Security::Cryptography::Certificates::ICmsAttachedSignature>
{
    HRESULT __stdcall get_Certificates(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Certificates());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Content(uint32_t * __valueSize, impl::abi_arg_out<uint8_t> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            std::tie(*__valueSize, *value) = detach_abi(this->shim().Content());
            return S_OK;
        }
        catch (...)
        {
            *__valueSize = 0;
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Signers(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::CmsSignerInfo>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Signers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_VerifySignature(Windows::Security::Cryptography::Certificates::SignatureValidationResult * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VerifySignature());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureFactory> : produce_base<D, Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureFactory>
{
    HRESULT __stdcall abi_CreateCmsAttachedSignature(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> inputBlob, impl::abi_arg_out<Windows::Security::Cryptography::Certificates::ICmsAttachedSignature> cmsSignedData) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cmsSignedData = detach_abi(this->shim().CreateCmsAttachedSignature(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&inputBlob)));
            return S_OK;
        }
        catch (...)
        {
            *cmsSignedData = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureStatics> : produce_base<D, Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureStatics>
{
    HRESULT __stdcall abi_GenerateSignatureAsync(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> data, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo>> signers, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate>> certificates, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer>> outputBlob) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *outputBlob = detach_abi(this->shim().GenerateSignatureAsync(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&data), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo> *>(&signers), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate> *>(&certificates)));
            return S_OK;
        }
        catch (...)
        {
            *outputBlob = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Cryptography::Certificates::ICmsDetachedSignature> : produce_base<D, Windows::Security::Cryptography::Certificates::ICmsDetachedSignature>
{
    HRESULT __stdcall get_Certificates(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Certificates());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Signers(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::CmsSignerInfo>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Signers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_VerifySignatureAsync(impl::abi_arg_in<Windows::Storage::Streams::IInputStream> data, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Cryptography::Certificates::SignatureValidationResult>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VerifySignatureAsync(*reinterpret_cast<const Windows::Storage::Streams::IInputStream *>(&data)));
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
struct produce<D, Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureFactory> : produce_base<D, Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureFactory>
{
    HRESULT __stdcall abi_CreateCmsDetachedSignature(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> inputBlob, impl::abi_arg_out<Windows::Security::Cryptography::Certificates::ICmsDetachedSignature> cmsSignedData) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cmsSignedData = detach_abi(this->shim().CreateCmsDetachedSignature(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&inputBlob)));
            return S_OK;
        }
        catch (...)
        {
            *cmsSignedData = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureStatics> : produce_base<D, Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureStatics>
{
    HRESULT __stdcall abi_GenerateSignatureAsync(impl::abi_arg_in<Windows::Storage::Streams::IInputStream> data, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo>> signers, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate>> certificates, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer>> outputBlob) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *outputBlob = detach_abi(this->shim().GenerateSignatureAsync(*reinterpret_cast<const Windows::Storage::Streams::IInputStream *>(&data), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo> *>(&signers), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate> *>(&certificates)));
            return S_OK;
        }
        catch (...)
        {
            *outputBlob = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Cryptography::Certificates::ICmsSignerInfo> : produce_base<D, Windows::Security::Cryptography::Certificates::ICmsSignerInfo>
{
    HRESULT __stdcall get_Certificate(impl::abi_arg_out<Windows::Security::Cryptography::Certificates::ICertificate> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Certificate());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Certificate(impl::abi_arg_in<Windows::Security::Cryptography::Certificates::ICertificate> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Certificate(*reinterpret_cast<const Windows::Security::Cryptography::Certificates::Certificate *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HashAlgorithmName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HashAlgorithmName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_HashAlgorithmName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HashAlgorithmName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TimestampInfo(impl::abi_arg_out<Windows::Security::Cryptography::Certificates::ICmsTimestampInfo> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TimestampInfo());
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
struct produce<D, Windows::Security::Cryptography::Certificates::ICmsTimestampInfo> : produce_base<D, Windows::Security::Cryptography::Certificates::ICmsTimestampInfo>
{
    HRESULT __stdcall get_SigningCertificate(impl::abi_arg_out<Windows::Security::Cryptography::Certificates::ICertificate> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SigningCertificate());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Certificates(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Certificates());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Timestamp(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Timestamp());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics> : produce_base<D, Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics>
{
    HRESULT __stdcall get_Rsa(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Rsa());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Dsa(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Dsa());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Ecdh256(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Ecdh256());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Ecdh384(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Ecdh384());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Ecdh521(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Ecdh521());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Ecdsa256(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Ecdsa256());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Ecdsa384(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Ecdsa384());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Ecdsa521(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Ecdsa521());
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
struct produce<D, Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics2> : produce_base<D, Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics2>
{
    HRESULT __stdcall get_Ecdsa(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Ecdsa());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Ecdh(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Ecdh());
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
struct produce<D, Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics> : produce_base<D, Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics>
{
    HRESULT __stdcall abi_DecryptTpmAttestationCredentialAsync(impl::abi_arg_in<hstring> credential, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DecryptTpmAttestationCredentialAsync(*reinterpret_cast<const hstring *>(&credential)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetTpmAttestationCredentialId(impl::abi_arg_in<hstring> credential, impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetTpmAttestationCredentialId(*reinterpret_cast<const hstring *>(&credential)));
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
struct produce<D, Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics2> : produce_base<D, Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics2>
{
    HRESULT __stdcall abi_DecryptTpmAttestationCredentialWithContainerNameAsync(impl::abi_arg_in<hstring> credential, impl::abi_arg_in<hstring> containerName, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DecryptTpmAttestationCredentialAsync(*reinterpret_cast<const hstring *>(&credential), *reinterpret_cast<const hstring *>(&containerName)));
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
struct produce<D, Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics> : produce_base<D, Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics>
{
    HRESULT __stdcall get_SoftwareKeyStorageProvider(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SoftwareKeyStorageProvider());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SmartcardKeyStorageProvider(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SmartcardKeyStorageProvider());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PlatformKeyStorageProvider(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PlatformKeyStorageProvider());
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
struct produce<D, Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics2> : produce_base<D, Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics2>
{
    HRESULT __stdcall get_PassportKeyStorageProvider(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PassportKeyStorageProvider());
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
struct produce<D, Windows::Security::Cryptography::Certificates::IPfxImportParameters> : produce_base<D, Windows::Security::Cryptography::Certificates::IPfxImportParameters>
{
    HRESULT __stdcall get_Exportable(Windows::Security::Cryptography::Certificates::ExportOption * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Exportable());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Exportable(Windows::Security::Cryptography::Certificates::ExportOption value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Exportable(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KeyProtectionLevel(Windows::Security::Cryptography::Certificates::KeyProtectionLevel * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeyProtectionLevel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_KeyProtectionLevel(Windows::Security::Cryptography::Certificates::KeyProtectionLevel value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().KeyProtectionLevel(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InstallOptions(Windows::Security::Cryptography::Certificates::InstallOptions * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InstallOptions());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_InstallOptions(Windows::Security::Cryptography::Certificates::InstallOptions value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InstallOptions(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FriendlyName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FriendlyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FriendlyName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FriendlyName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KeyStorageProviderName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeyStorageProviderName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_KeyStorageProviderName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().KeyStorageProviderName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContainerNamePrefix(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContainerNamePrefix());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ContainerNamePrefix(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContainerNamePrefix(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ReaderName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReaderName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ReaderName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReaderName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::Cryptography::Certificates::IStandardCertificateStoreNamesStatics> : produce_base<D, Windows::Security::Cryptography::Certificates::IStandardCertificateStoreNamesStatics>
{
    HRESULT __stdcall get_Personal(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Personal());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TrustedRootCertificationAuthorities(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TrustedRootCertificationAuthorities());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IntermediateCertificationAuthorities(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IntermediateCertificationAuthorities());
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
struct produce<D, Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo> : produce_base<D, Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo>
{
    HRESULT __stdcall get_EmailName(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EmailName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IPAddress(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IPAddress());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Url(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Url());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DnsName(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DnsName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DistinguishedName(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DistinguishedName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PrincipalName(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PrincipalName());
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
struct produce<D, Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager> : produce_base<D, Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager>
{
    HRESULT __stdcall abi_CreateRequestAsync(impl::abi_arg_in<Windows::Security::Cryptography::Certificates::ICertificateRequestProperties> request, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateRequestAsync(*reinterpret_cast<const Windows::Security::Cryptography::Certificates::CertificateRequestProperties *>(&request)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_InstallCertificateAsync(impl::abi_arg_in<hstring> certificate, Windows::Security::Cryptography::Certificates::InstallOptions installOption, impl::abi_arg_out<Windows::Foundation::IAsyncAction> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InstallCertificateAsync(*reinterpret_cast<const hstring *>(&certificate), installOption));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ImportPfxDataAsync(impl::abi_arg_in<hstring> pfxData, impl::abi_arg_in<hstring> password, Windows::Security::Cryptography::Certificates::ExportOption exportable, Windows::Security::Cryptography::Certificates::KeyProtectionLevel keyProtectionLevel, Windows::Security::Cryptography::Certificates::InstallOptions installOption, impl::abi_arg_in<hstring> friendlyName, impl::abi_arg_out<Windows::Foundation::IAsyncAction> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ImportPfxDataAsync(*reinterpret_cast<const hstring *>(&pfxData), *reinterpret_cast<const hstring *>(&password), exportable, keyProtectionLevel, installOption, *reinterpret_cast<const hstring *>(&friendlyName)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ImportPfxDataToKspAsync(impl::abi_arg_in<hstring> pfxData, impl::abi_arg_in<hstring> password, Windows::Security::Cryptography::Certificates::ExportOption exportable, Windows::Security::Cryptography::Certificates::KeyProtectionLevel keyProtectionLevel, Windows::Security::Cryptography::Certificates::InstallOptions installOption, impl::abi_arg_in<hstring> friendlyName, impl::abi_arg_in<hstring> keyStorageProvider, impl::abi_arg_out<Windows::Foundation::IAsyncAction> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ImportPfxDataAsync(*reinterpret_cast<const hstring *>(&pfxData), *reinterpret_cast<const hstring *>(&password), exportable, keyProtectionLevel, installOption, *reinterpret_cast<const hstring *>(&friendlyName), *reinterpret_cast<const hstring *>(&keyStorageProvider)));
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
struct produce<D, Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager2> : produce_base<D, Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager2>
{
    HRESULT __stdcall abi_ImportPfxDataToKspWithParametersAsync(impl::abi_arg_in<hstring> pfxData, impl::abi_arg_in<hstring> password, impl::abi_arg_in<Windows::Security::Cryptography::Certificates::IPfxImportParameters> pfxImportParameters, impl::abi_arg_out<Windows::Foundation::IAsyncAction> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ImportPfxDataAsync(*reinterpret_cast<const hstring *>(&pfxData), *reinterpret_cast<const hstring *>(&password), *reinterpret_cast<const Windows::Security::Cryptography::Certificates::PfxImportParameters *>(&pfxImportParameters)));
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
struct produce<D, Windows::Security::Cryptography::Certificates::IUserCertificateStore> : produce_base<D, Windows::Security::Cryptography::Certificates::IUserCertificateStore>
{
    HRESULT __stdcall abi_RequestAddAsync(impl::abi_arg_in<Windows::Security::Cryptography::Certificates::ICertificate> certificate, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestAddAsync(*reinterpret_cast<const Windows::Security::Cryptography::Certificates::Certificate *>(&certificate)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestDeleteAsync(impl::abi_arg_in<Windows::Security::Cryptography::Certificates::ICertificate> certificate, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestDeleteAsync(*reinterpret_cast<const Windows::Security::Cryptography::Certificates::Certificate *>(&certificate)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
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
};

}

namespace Windows::Security::Cryptography::Certificates {

template <typename D> hstring impl_ICertificateRequestProperties<D>::Subject() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICertificateRequestProperties)->get_Subject(put_abi(value)));
    return value;
}

template <typename D> void impl_ICertificateRequestProperties<D>::Subject(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ICertificateRequestProperties)->put_Subject(get_abi(value)));
}

template <typename D> hstring impl_ICertificateRequestProperties<D>::KeyAlgorithmName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICertificateRequestProperties)->get_KeyAlgorithmName(put_abi(value)));
    return value;
}

template <typename D> void impl_ICertificateRequestProperties<D>::KeyAlgorithmName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ICertificateRequestProperties)->put_KeyAlgorithmName(get_abi(value)));
}

template <typename D> uint32_t impl_ICertificateRequestProperties<D>::KeySize() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ICertificateRequestProperties)->get_KeySize(&value));
    return value;
}

template <typename D> void impl_ICertificateRequestProperties<D>::KeySize(uint32_t value) const
{
    check_hresult(WINRT_SHIM(ICertificateRequestProperties)->put_KeySize(value));
}

template <typename D> hstring impl_ICertificateRequestProperties<D>::FriendlyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICertificateRequestProperties)->get_FriendlyName(put_abi(value)));
    return value;
}

template <typename D> void impl_ICertificateRequestProperties<D>::FriendlyName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ICertificateRequestProperties)->put_FriendlyName(get_abi(value)));
}

template <typename D> hstring impl_ICertificateRequestProperties<D>::HashAlgorithmName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICertificateRequestProperties)->get_HashAlgorithmName(put_abi(value)));
    return value;
}

template <typename D> void impl_ICertificateRequestProperties<D>::HashAlgorithmName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ICertificateRequestProperties)->put_HashAlgorithmName(get_abi(value)));
}

template <typename D> Windows::Security::Cryptography::Certificates::ExportOption impl_ICertificateRequestProperties<D>::Exportable() const
{
    Windows::Security::Cryptography::Certificates::ExportOption value {};
    check_hresult(WINRT_SHIM(ICertificateRequestProperties)->get_Exportable(&value));
    return value;
}

template <typename D> void impl_ICertificateRequestProperties<D>::Exportable(Windows::Security::Cryptography::Certificates::ExportOption value) const
{
    check_hresult(WINRT_SHIM(ICertificateRequestProperties)->put_Exportable(value));
}

template <typename D> Windows::Security::Cryptography::Certificates::EnrollKeyUsages impl_ICertificateRequestProperties<D>::KeyUsages() const
{
    Windows::Security::Cryptography::Certificates::EnrollKeyUsages value {};
    check_hresult(WINRT_SHIM(ICertificateRequestProperties)->get_KeyUsages(&value));
    return value;
}

template <typename D> void impl_ICertificateRequestProperties<D>::KeyUsages(Windows::Security::Cryptography::Certificates::EnrollKeyUsages value) const
{
    check_hresult(WINRT_SHIM(ICertificateRequestProperties)->put_KeyUsages(value));
}

template <typename D> Windows::Security::Cryptography::Certificates::KeyProtectionLevel impl_ICertificateRequestProperties<D>::KeyProtectionLevel() const
{
    Windows::Security::Cryptography::Certificates::KeyProtectionLevel value {};
    check_hresult(WINRT_SHIM(ICertificateRequestProperties)->get_KeyProtectionLevel(&value));
    return value;
}

template <typename D> void impl_ICertificateRequestProperties<D>::KeyProtectionLevel(Windows::Security::Cryptography::Certificates::KeyProtectionLevel value) const
{
    check_hresult(WINRT_SHIM(ICertificateRequestProperties)->put_KeyProtectionLevel(value));
}

template <typename D> hstring impl_ICertificateRequestProperties<D>::KeyStorageProviderName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICertificateRequestProperties)->get_KeyStorageProviderName(put_abi(value)));
    return value;
}

template <typename D> void impl_ICertificateRequestProperties<D>::KeyStorageProviderName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ICertificateRequestProperties)->put_KeyStorageProviderName(get_abi(value)));
}

template <typename D> hstring impl_ICertificateRequestProperties2<D>::SmartcardReaderName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICertificateRequestProperties2)->get_SmartcardReaderName(put_abi(value)));
    return value;
}

template <typename D> void impl_ICertificateRequestProperties2<D>::SmartcardReaderName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ICertificateRequestProperties2)->put_SmartcardReaderName(get_abi(value)));
}

template <typename D> Windows::Security::Cryptography::Certificates::Certificate impl_ICertificateRequestProperties2<D>::SigningCertificate() const
{
    Windows::Security::Cryptography::Certificates::Certificate value { nullptr };
    check_hresult(WINRT_SHIM(ICertificateRequestProperties2)->get_SigningCertificate(put_abi(value)));
    return value;
}

template <typename D> void impl_ICertificateRequestProperties2<D>::SigningCertificate(const Windows::Security::Cryptography::Certificates::Certificate & value) const
{
    check_hresult(WINRT_SHIM(ICertificateRequestProperties2)->put_SigningCertificate(get_abi(value)));
}

template <typename D> Windows::Security::Cryptography::Certificates::Certificate impl_ICertificateRequestProperties2<D>::AttestationCredentialCertificate() const
{
    Windows::Security::Cryptography::Certificates::Certificate value { nullptr };
    check_hresult(WINRT_SHIM(ICertificateRequestProperties2)->get_AttestationCredentialCertificate(put_abi(value)));
    return value;
}

template <typename D> void impl_ICertificateRequestProperties2<D>::AttestationCredentialCertificate(const Windows::Security::Cryptography::Certificates::Certificate & value) const
{
    check_hresult(WINRT_SHIM(ICertificateRequestProperties2)->put_AttestationCredentialCertificate(get_abi(value)));
}

template <typename D> hstring impl_ICertificateRequestProperties3<D>::CurveName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICertificateRequestProperties3)->get_CurveName(put_abi(value)));
    return value;
}

template <typename D> void impl_ICertificateRequestProperties3<D>::CurveName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ICertificateRequestProperties3)->put_CurveName(get_abi(value)));
}

template <typename D> com_array<uint8_t> impl_ICertificateRequestProperties3<D>::CurveParameters() const
{
    com_array<uint8_t> value {};
    check_hresult(WINRT_SHIM(ICertificateRequestProperties3)->get_CurveParameters(impl::put_size_abi(value), put_abi(value)));
    return value;
}

template <typename D> void impl_ICertificateRequestProperties3<D>::CurveParameters(array_view<const uint8_t> value) const
{
    check_hresult(WINRT_SHIM(ICertificateRequestProperties3)->put_CurveParameters(value.size(), get_abi(value)));
}

template <typename D> hstring impl_ICertificateRequestProperties3<D>::ContainerNamePrefix() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICertificateRequestProperties3)->get_ContainerNamePrefix(put_abi(value)));
    return value;
}

template <typename D> void impl_ICertificateRequestProperties3<D>::ContainerNamePrefix(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ICertificateRequestProperties3)->put_ContainerNamePrefix(get_abi(value)));
}

template <typename D> hstring impl_ICertificateRequestProperties3<D>::ContainerName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICertificateRequestProperties3)->get_ContainerName(put_abi(value)));
    return value;
}

template <typename D> void impl_ICertificateRequestProperties3<D>::ContainerName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ICertificateRequestProperties3)->put_ContainerName(get_abi(value)));
}

template <typename D> bool impl_ICertificateRequestProperties3<D>::UseExistingKey() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICertificateRequestProperties3)->get_UseExistingKey(&value));
    return value;
}

template <typename D> void impl_ICertificateRequestProperties3<D>::UseExistingKey(bool value) const
{
    check_hresult(WINRT_SHIM(ICertificateRequestProperties3)->put_UseExistingKey(value));
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_ICertificateEnrollmentManagerStatics<D>::CreateRequestAsync(const Windows::Security::Cryptography::Certificates::CertificateRequestProperties & request) const
{
    Windows::Foundation::IAsyncOperation<hstring> value;
    check_hresult(WINRT_SHIM(ICertificateEnrollmentManagerStatics)->abi_CreateRequestAsync(get_abi(request), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ICertificateEnrollmentManagerStatics<D>::InstallCertificateAsync(hstring_view certificate, Windows::Security::Cryptography::Certificates::InstallOptions installOption) const
{
    Windows::Foundation::IAsyncAction value;
    check_hresult(WINRT_SHIM(ICertificateEnrollmentManagerStatics)->abi_InstallCertificateAsync(get_abi(certificate), installOption, put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ICertificateEnrollmentManagerStatics<D>::ImportPfxDataAsync(hstring_view pfxData, hstring_view password, Windows::Security::Cryptography::Certificates::ExportOption exportable, Windows::Security::Cryptography::Certificates::KeyProtectionLevel keyProtectionLevel, Windows::Security::Cryptography::Certificates::InstallOptions installOption, hstring_view friendlyName) const
{
    Windows::Foundation::IAsyncAction value;
    check_hresult(WINRT_SHIM(ICertificateEnrollmentManagerStatics)->abi_ImportPfxDataAsync(get_abi(pfxData), get_abi(password), exportable, keyProtectionLevel, installOption, get_abi(friendlyName), put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Cryptography::Certificates::UserCertificateEnrollmentManager impl_ICertificateEnrollmentManagerStatics2<D>::UserCertificateEnrollmentManager() const
{
    Windows::Security::Cryptography::Certificates::UserCertificateEnrollmentManager value { nullptr };
    check_hresult(WINRT_SHIM(ICertificateEnrollmentManagerStatics2)->get_UserCertificateEnrollmentManager(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ICertificateEnrollmentManagerStatics2<D>::ImportPfxDataAsync(hstring_view pfxData, hstring_view password, Windows::Security::Cryptography::Certificates::ExportOption exportable, Windows::Security::Cryptography::Certificates::KeyProtectionLevel keyProtectionLevel, Windows::Security::Cryptography::Certificates::InstallOptions installOption, hstring_view friendlyName, hstring_view keyStorageProvider) const
{
    Windows::Foundation::IAsyncAction value;
    check_hresult(WINRT_SHIM(ICertificateEnrollmentManagerStatics2)->abi_ImportPfxDataToKspAsync(get_abi(pfxData), get_abi(password), exportable, keyProtectionLevel, installOption, get_abi(friendlyName), get_abi(keyStorageProvider), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ICertificateEnrollmentManagerStatics3<D>::ImportPfxDataAsync(hstring_view pfxData, hstring_view password, const Windows::Security::Cryptography::Certificates::PfxImportParameters & pfxImportParameters) const
{
    Windows::Foundation::IAsyncAction value;
    check_hresult(WINRT_SHIM(ICertificateEnrollmentManagerStatics3)->abi_ImportPfxDataToKspWithParametersAsync(get_abi(pfxData), get_abi(password), get_abi(pfxImportParameters), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IKeyAttestationHelperStatics<D>::DecryptTpmAttestationCredentialAsync(hstring_view credential) const
{
    Windows::Foundation::IAsyncOperation<hstring> value;
    check_hresult(WINRT_SHIM(IKeyAttestationHelperStatics)->abi_DecryptTpmAttestationCredentialAsync(get_abi(credential), put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKeyAttestationHelperStatics<D>::GetTpmAttestationCredentialId(hstring_view credential) const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKeyAttestationHelperStatics)->abi_GetTpmAttestationCredentialId(get_abi(credential), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IKeyAttestationHelperStatics2<D>::DecryptTpmAttestationCredentialAsync(hstring_view credential, hstring_view containerName) const
{
    Windows::Foundation::IAsyncOperation<hstring> value;
    check_hresult(WINRT_SHIM(IKeyAttestationHelperStatics2)->abi_DecryptTpmAttestationCredentialWithContainerNameAsync(get_abi(credential), get_abi(containerName), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate>> impl_ICertificateStoresStatics<D>::FindAllAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate>> value;
    check_hresult(WINRT_SHIM(ICertificateStoresStatics)->abi_FindAllAsync(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate>> impl_ICertificateStoresStatics<D>::FindAllAsync(const Windows::Security::Cryptography::Certificates::CertificateQuery & query) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate>> value;
    check_hresult(WINRT_SHIM(ICertificateStoresStatics)->abi_FindAllWithQueryAsync(get_abi(query), put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Cryptography::Certificates::CertificateStore impl_ICertificateStoresStatics<D>::TrustedRootCertificationAuthorities() const
{
    Windows::Security::Cryptography::Certificates::CertificateStore value { nullptr };
    check_hresult(WINRT_SHIM(ICertificateStoresStatics)->get_TrustedRootCertificationAuthorities(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Cryptography::Certificates::CertificateStore impl_ICertificateStoresStatics<D>::IntermediateCertificationAuthorities() const
{
    Windows::Security::Cryptography::Certificates::CertificateStore value { nullptr };
    check_hresult(WINRT_SHIM(ICertificateStoresStatics)->get_IntermediateCertificationAuthorities(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Cryptography::Certificates::CertificateStore impl_ICertificateStoresStatics<D>::GetStoreByName(hstring_view storeName) const
{
    Windows::Security::Cryptography::Certificates::CertificateStore value { nullptr };
    check_hresult(WINRT_SHIM(ICertificateStoresStatics)->abi_GetStoreByName(get_abi(storeName), put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Cryptography::Certificates::UserCertificateStore impl_ICertificateStoresStatics2<D>::GetUserStoreByName(hstring_view storeName) const
{
    Windows::Security::Cryptography::Certificates::UserCertificateStore result { nullptr };
    check_hresult(WINRT_SHIM(ICertificateStoresStatics2)->abi_GetUserStoreByName(get_abi(storeName), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IUserCertificateEnrollmentManager<D>::CreateRequestAsync(const Windows::Security::Cryptography::Certificates::CertificateRequestProperties & request) const
{
    Windows::Foundation::IAsyncOperation<hstring> value;
    check_hresult(WINRT_SHIM(IUserCertificateEnrollmentManager)->abi_CreateRequestAsync(get_abi(request), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IUserCertificateEnrollmentManager<D>::InstallCertificateAsync(hstring_view certificate, Windows::Security::Cryptography::Certificates::InstallOptions installOption) const
{
    Windows::Foundation::IAsyncAction value;
    check_hresult(WINRT_SHIM(IUserCertificateEnrollmentManager)->abi_InstallCertificateAsync(get_abi(certificate), installOption, put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IUserCertificateEnrollmentManager<D>::ImportPfxDataAsync(hstring_view pfxData, hstring_view password, Windows::Security::Cryptography::Certificates::ExportOption exportable, Windows::Security::Cryptography::Certificates::KeyProtectionLevel keyProtectionLevel, Windows::Security::Cryptography::Certificates::InstallOptions installOption, hstring_view friendlyName) const
{
    Windows::Foundation::IAsyncAction value;
    check_hresult(WINRT_SHIM(IUserCertificateEnrollmentManager)->abi_ImportPfxDataAsync(get_abi(pfxData), get_abi(password), exportable, keyProtectionLevel, installOption, get_abi(friendlyName), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IUserCertificateEnrollmentManager<D>::ImportPfxDataAsync(hstring_view pfxData, hstring_view password, Windows::Security::Cryptography::Certificates::ExportOption exportable, Windows::Security::Cryptography::Certificates::KeyProtectionLevel keyProtectionLevel, Windows::Security::Cryptography::Certificates::InstallOptions installOption, hstring_view friendlyName, hstring_view keyStorageProvider) const
{
    Windows::Foundation::IAsyncAction value;
    check_hresult(WINRT_SHIM(IUserCertificateEnrollmentManager)->abi_ImportPfxDataToKspAsync(get_abi(pfxData), get_abi(password), exportable, keyProtectionLevel, installOption, get_abi(friendlyName), get_abi(keyStorageProvider), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IUserCertificateEnrollmentManager2<D>::ImportPfxDataAsync(hstring_view pfxData, hstring_view password, const Windows::Security::Cryptography::Certificates::PfxImportParameters & pfxImportParameters) const
{
    Windows::Foundation::IAsyncAction value;
    check_hresult(WINRT_SHIM(IUserCertificateEnrollmentManager2)->abi_ImportPfxDataToKspWithParametersAsync(get_abi(pfxData), get_abi(password), get_abi(pfxImportParameters), put_abi(value)));
    return value;
}

template <typename D> void impl_ICertificateStore<D>::Add(const Windows::Security::Cryptography::Certificates::Certificate & certificate) const
{
    check_hresult(WINRT_SHIM(ICertificateStore)->abi_Add(get_abi(certificate)));
}

template <typename D> void impl_ICertificateStore<D>::Delete(const Windows::Security::Cryptography::Certificates::Certificate & certificate) const
{
    check_hresult(WINRT_SHIM(ICertificateStore)->abi_Delete(get_abi(certificate)));
}

template <typename D> hstring impl_ICertificateStore2<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICertificateStore2)->get_Name(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IUserCertificateStore<D>::RequestAddAsync(const Windows::Security::Cryptography::Certificates::Certificate & certificate) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IUserCertificateStore)->abi_RequestAddAsync(get_abi(certificate), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IUserCertificateStore<D>::RequestDeleteAsync(const Windows::Security::Cryptography::Certificates::Certificate & certificate) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IUserCertificateStore)->abi_RequestDeleteAsync(get_abi(certificate), put_abi(result)));
    return result;
}

template <typename D> hstring impl_IUserCertificateStore<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUserCertificateStore)->get_Name(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStandardCertificateStoreNamesStatics<D>::Personal() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStandardCertificateStoreNamesStatics)->get_Personal(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStandardCertificateStoreNamesStatics<D>::TrustedRootCertificationAuthorities() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStandardCertificateStoreNamesStatics)->get_TrustedRootCertificationAuthorities(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStandardCertificateStoreNamesStatics<D>::IntermediateCertificationAuthorities() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStandardCertificateStoreNamesStatics)->get_IntermediateCertificationAuthorities(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKeyAlgorithmNamesStatics<D>::Rsa() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKeyAlgorithmNamesStatics)->get_Rsa(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKeyAlgorithmNamesStatics<D>::Dsa() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKeyAlgorithmNamesStatics)->get_Dsa(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKeyAlgorithmNamesStatics<D>::Ecdh256() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKeyAlgorithmNamesStatics)->get_Ecdh256(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKeyAlgorithmNamesStatics<D>::Ecdh384() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKeyAlgorithmNamesStatics)->get_Ecdh384(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKeyAlgorithmNamesStatics<D>::Ecdh521() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKeyAlgorithmNamesStatics)->get_Ecdh521(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKeyAlgorithmNamesStatics<D>::Ecdsa256() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKeyAlgorithmNamesStatics)->get_Ecdsa256(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKeyAlgorithmNamesStatics<D>::Ecdsa384() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKeyAlgorithmNamesStatics)->get_Ecdsa384(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKeyAlgorithmNamesStatics<D>::Ecdsa521() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKeyAlgorithmNamesStatics)->get_Ecdsa521(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKeyAlgorithmNamesStatics2<D>::Ecdsa() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKeyAlgorithmNamesStatics2)->get_Ecdsa(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKeyAlgorithmNamesStatics2<D>::Ecdh() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKeyAlgorithmNamesStatics2)->get_Ecdh(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKeyStorageProviderNamesStatics<D>::SoftwareKeyStorageProvider() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKeyStorageProviderNamesStatics)->get_SoftwareKeyStorageProvider(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKeyStorageProviderNamesStatics<D>::SmartcardKeyStorageProvider() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKeyStorageProviderNamesStatics)->get_SmartcardKeyStorageProvider(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKeyStorageProviderNamesStatics<D>::PlatformKeyStorageProvider() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKeyStorageProviderNamesStatics)->get_PlatformKeyStorageProvider(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKeyStorageProviderNamesStatics2<D>::PassportKeyStorageProvider() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKeyStorageProviderNamesStatics2)->get_PassportKeyStorageProvider(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IChainBuildingParameters<D>::EnhancedKeyUsages() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IChainBuildingParameters)->get_EnhancedKeyUsages(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IChainBuildingParameters<D>::ValidationTimestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IChainBuildingParameters)->get_ValidationTimestamp(put_abi(value)));
    return value;
}

template <typename D> void impl_IChainBuildingParameters<D>::ValidationTimestamp(const Windows::Foundation::DateTime & value) const
{
    check_hresult(WINRT_SHIM(IChainBuildingParameters)->put_ValidationTimestamp(get_abi(value)));
}

template <typename D> bool impl_IChainBuildingParameters<D>::RevocationCheckEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IChainBuildingParameters)->get_RevocationCheckEnabled(&value));
    return value;
}

template <typename D> void impl_IChainBuildingParameters<D>::RevocationCheckEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IChainBuildingParameters)->put_RevocationCheckEnabled(value));
}

template <typename D> bool impl_IChainBuildingParameters<D>::NetworkRetrievalEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IChainBuildingParameters)->get_NetworkRetrievalEnabled(&value));
    return value;
}

template <typename D> void impl_IChainBuildingParameters<D>::NetworkRetrievalEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IChainBuildingParameters)->put_NetworkRetrievalEnabled(value));
}

template <typename D> bool impl_IChainBuildingParameters<D>::AuthorityInformationAccessEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IChainBuildingParameters)->get_AuthorityInformationAccessEnabled(&value));
    return value;
}

template <typename D> void impl_IChainBuildingParameters<D>::AuthorityInformationAccessEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IChainBuildingParameters)->put_AuthorityInformationAccessEnabled(value));
}

template <typename D> bool impl_IChainBuildingParameters<D>::CurrentTimeValidationEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IChainBuildingParameters)->get_CurrentTimeValidationEnabled(&value));
    return value;
}

template <typename D> void impl_IChainBuildingParameters<D>::CurrentTimeValidationEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IChainBuildingParameters)->put_CurrentTimeValidationEnabled(value));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::Certificate> impl_IChainBuildingParameters<D>::ExclusiveTrustRoots() const
{
    Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::Certificate> certificates;
    check_hresult(WINRT_SHIM(IChainBuildingParameters)->get_ExclusiveTrustRoots(put_abi(certificates)));
    return certificates;
}

template <typename D> Windows::Security::Cryptography::Certificates::CertificateChainPolicy impl_IChainValidationParameters<D>::CertificateChainPolicy() const
{
    Windows::Security::Cryptography::Certificates::CertificateChainPolicy value {};
    check_hresult(WINRT_SHIM(IChainValidationParameters)->get_CertificateChainPolicy(&value));
    return value;
}

template <typename D> void impl_IChainValidationParameters<D>::CertificateChainPolicy(Windows::Security::Cryptography::Certificates::CertificateChainPolicy value) const
{
    check_hresult(WINRT_SHIM(IChainValidationParameters)->put_CertificateChainPolicy(value));
}

template <typename D> Windows::Networking::HostName impl_IChainValidationParameters<D>::ServerDnsName() const
{
    Windows::Networking::HostName value { nullptr };
    check_hresult(WINRT_SHIM(IChainValidationParameters)->get_ServerDnsName(put_abi(value)));
    return value;
}

template <typename D> void impl_IChainValidationParameters<D>::ServerDnsName(const Windows::Networking::HostName & value) const
{
    check_hresult(WINRT_SHIM(IChainValidationParameters)->put_ServerDnsName(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_ICertificateQuery<D>::EnhancedKeyUsages() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(ICertificateQuery)->get_EnhancedKeyUsages(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICertificateQuery<D>::IssuerName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICertificateQuery)->get_IssuerName(put_abi(value)));
    return value;
}

template <typename D> void impl_ICertificateQuery<D>::IssuerName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ICertificateQuery)->put_IssuerName(get_abi(value)));
}

template <typename D> hstring impl_ICertificateQuery<D>::FriendlyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICertificateQuery)->get_FriendlyName(put_abi(value)));
    return value;
}

template <typename D> void impl_ICertificateQuery<D>::FriendlyName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ICertificateQuery)->put_FriendlyName(get_abi(value)));
}

template <typename D> com_array<uint8_t> impl_ICertificateQuery<D>::Thumbprint() const
{
    com_array<uint8_t> value {};
    check_hresult(WINRT_SHIM(ICertificateQuery)->get_Thumbprint(impl::put_size_abi(value), put_abi(value)));
    return value;
}

template <typename D> void impl_ICertificateQuery<D>::Thumbprint(array_view<const uint8_t> value) const
{
    check_hresult(WINRT_SHIM(ICertificateQuery)->put_Thumbprint(value.size(), get_abi(value)));
}

template <typename D> bool impl_ICertificateQuery<D>::HardwareOnly() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICertificateQuery)->get_HardwareOnly(&value));
    return value;
}

template <typename D> void impl_ICertificateQuery<D>::HardwareOnly(bool value) const
{
    check_hresult(WINRT_SHIM(ICertificateQuery)->put_HardwareOnly(value));
}

template <typename D> bool impl_ICertificateQuery2<D>::IncludeDuplicates() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICertificateQuery2)->get_IncludeDuplicates(&value));
    return value;
}

template <typename D> void impl_ICertificateQuery2<D>::IncludeDuplicates(bool value) const
{
    check_hresult(WINRT_SHIM(ICertificateQuery2)->put_IncludeDuplicates(value));
}

template <typename D> bool impl_ICertificateQuery2<D>::IncludeExpiredCertificates() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICertificateQuery2)->get_IncludeExpiredCertificates(&value));
    return value;
}

template <typename D> void impl_ICertificateQuery2<D>::IncludeExpiredCertificates(bool value) const
{
    check_hresult(WINRT_SHIM(ICertificateQuery2)->put_IncludeExpiredCertificates(value));
}

template <typename D> hstring impl_ICertificateQuery2<D>::StoreName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICertificateQuery2)->get_StoreName(put_abi(value)));
    return value;
}

template <typename D> void impl_ICertificateQuery2<D>::StoreName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ICertificateQuery2)->put_StoreName(get_abi(value)));
}

template <typename D> Windows::Security::Cryptography::Certificates::ChainValidationResult impl_ICertificateChain<D>::Validate() const
{
    Windows::Security::Cryptography::Certificates::ChainValidationResult status {};
    check_hresult(WINRT_SHIM(ICertificateChain)->abi_Validate(&status));
    return status;
}

template <typename D> Windows::Security::Cryptography::Certificates::ChainValidationResult impl_ICertificateChain<D>::Validate(const Windows::Security::Cryptography::Certificates::ChainValidationParameters & parameter) const
{
    Windows::Security::Cryptography::Certificates::ChainValidationResult status {};
    check_hresult(WINRT_SHIM(ICertificateChain)->abi_ValidateWithParameters(get_abi(parameter), &status));
    return status;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> impl_ICertificateChain<D>::GetCertificates(bool includeRoot) const
{
    Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> certificates;
    check_hresult(WINRT_SHIM(ICertificateChain)->abi_GetCertificates(includeRoot, put_abi(certificates)));
    return certificates;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::Cryptography::Certificates::CertificateChain> impl_ICertificate<D>::BuildChainAsync(iterable<Windows::Security::Cryptography::Certificates::Certificate> certificates) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Cryptography::Certificates::CertificateChain> value;
    check_hresult(WINRT_SHIM(ICertificate)->abi_BuildChainAsync(get_abi(certificates), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::Cryptography::Certificates::CertificateChain> impl_ICertificate<D>::BuildChainAsync(iterable<Windows::Security::Cryptography::Certificates::Certificate> certificates, const Windows::Security::Cryptography::Certificates::ChainBuildingParameters & parameters) const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Cryptography::Certificates::CertificateChain> value;
    check_hresult(WINRT_SHIM(ICertificate)->abi_BuildChainWithParametersAsync(get_abi(certificates), get_abi(parameters), put_abi(value)));
    return value;
}

template <typename D> com_array<uint8_t> impl_ICertificate<D>::SerialNumber() const
{
    com_array<uint8_t> value {};
    check_hresult(WINRT_SHIM(ICertificate)->get_SerialNumber(impl::put_size_abi(value), put_abi(value)));
    return value;
}

template <typename D> com_array<uint8_t> impl_ICertificate<D>::GetHashValue() const
{
    com_array<uint8_t> value {};
    check_hresult(WINRT_SHIM(ICertificate)->abi_GetHashValue(impl::put_size_abi(value), put_abi(value)));
    return value;
}

template <typename D> com_array<uint8_t> impl_ICertificate<D>::GetHashValue(hstring_view hashAlgorithmName) const
{
    com_array<uint8_t> value {};
    check_hresult(WINRT_SHIM(ICertificate)->abi_GetHashValueWithAlgorithm(get_abi(hashAlgorithmName), impl::put_size_abi(value), put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_ICertificate<D>::GetCertificateBlob() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(ICertificate)->abi_GetCertificateBlob(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICertificate<D>::Subject() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICertificate)->get_Subject(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICertificate<D>::Issuer() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICertificate)->get_Issuer(put_abi(value)));
    return value;
}

template <typename D> bool impl_ICertificate<D>::HasPrivateKey() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICertificate)->get_HasPrivateKey(&value));
    return value;
}

template <typename D> bool impl_ICertificate<D>::IsStronglyProtected() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICertificate)->get_IsStronglyProtected(&value));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_ICertificate<D>::ValidFrom() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(ICertificate)->get_ValidFrom(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_ICertificate<D>::ValidTo() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(ICertificate)->get_ValidTo(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_ICertificate<D>::EnhancedKeyUsages() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(ICertificate)->get_EnhancedKeyUsages(put_abi(value)));
    return value;
}

template <typename D> void impl_ICertificate<D>::FriendlyName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ICertificate)->put_FriendlyName(get_abi(value)));
}

template <typename D> hstring impl_ICertificate<D>::FriendlyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICertificate)->get_FriendlyName(put_abi(value)));
    return value;
}

template <typename D> bool impl_ICertificate2<D>::IsSecurityDeviceBound() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICertificate2)->get_IsSecurityDeviceBound(&value));
    return value;
}

template <typename D> Windows::Security::Cryptography::Certificates::CertificateKeyUsages impl_ICertificate2<D>::KeyUsages() const
{
    Windows::Security::Cryptography::Certificates::CertificateKeyUsages value { nullptr };
    check_hresult(WINRT_SHIM(ICertificate2)->get_KeyUsages(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICertificate2<D>::KeyAlgorithmName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICertificate2)->get_KeyAlgorithmName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICertificate2<D>::SignatureAlgorithmName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICertificate2)->get_SignatureAlgorithmName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICertificate2<D>::SignatureHashAlgorithmName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICertificate2)->get_SignatureHashAlgorithmName(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Cryptography::Certificates::SubjectAlternativeNameInfo impl_ICertificate2<D>::SubjectAlternativeName() const
{
    Windows::Security::Cryptography::Certificates::SubjectAlternativeNameInfo value { nullptr };
    check_hresult(WINRT_SHIM(ICertificate2)->get_SubjectAlternativeName(put_abi(value)));
    return value;
}

template <typename D> bool impl_ICertificate3<D>::IsPerUser() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICertificate3)->get_IsPerUser(&value));
    return value;
}

template <typename D> hstring impl_ICertificate3<D>::StoreName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICertificate3)->get_StoreName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICertificate3<D>::KeyStorageProviderName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICertificate3)->get_KeyStorageProviderName(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Cryptography::Certificates::Certificate impl_ICertificateFactory<D>::CreateCertificate(const Windows::Storage::Streams::IBuffer & certBlob) const
{
    Windows::Security::Cryptography::Certificates::Certificate certificate { nullptr };
    check_hresult(WINRT_SHIM(ICertificateFactory)->abi_CreateCertificate(get_abi(certBlob), put_abi(certificate)));
    return certificate;
}

template <typename D> Windows::Security::Cryptography::Certificates::Certificate impl_ICmsTimestampInfo<D>::SigningCertificate() const
{
    Windows::Security::Cryptography::Certificates::Certificate value { nullptr };
    check_hresult(WINRT_SHIM(ICmsTimestampInfo)->get_SigningCertificate(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> impl_ICmsTimestampInfo<D>::Certificates() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> value;
    check_hresult(WINRT_SHIM(ICmsTimestampInfo)->get_Certificates(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_ICmsTimestampInfo<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(ICmsTimestampInfo)->get_Timestamp(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Cryptography::Certificates::Certificate impl_ICmsSignerInfo<D>::Certificate() const
{
    Windows::Security::Cryptography::Certificates::Certificate value { nullptr };
    check_hresult(WINRT_SHIM(ICmsSignerInfo)->get_Certificate(put_abi(value)));
    return value;
}

template <typename D> void impl_ICmsSignerInfo<D>::Certificate(const Windows::Security::Cryptography::Certificates::Certificate & value) const
{
    check_hresult(WINRT_SHIM(ICmsSignerInfo)->put_Certificate(get_abi(value)));
}

template <typename D> hstring impl_ICmsSignerInfo<D>::HashAlgorithmName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICmsSignerInfo)->get_HashAlgorithmName(put_abi(value)));
    return value;
}

template <typename D> void impl_ICmsSignerInfo<D>::HashAlgorithmName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ICmsSignerInfo)->put_HashAlgorithmName(get_abi(value)));
}

template <typename D> Windows::Security::Cryptography::Certificates::CmsTimestampInfo impl_ICmsSignerInfo<D>::TimestampInfo() const
{
    Windows::Security::Cryptography::Certificates::CmsTimestampInfo value { nullptr };
    check_hresult(WINRT_SHIM(ICmsSignerInfo)->get_TimestampInfo(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_ISubjectAlternativeNameInfo<D>::EmailName() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(ISubjectAlternativeNameInfo)->get_EmailName(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_ISubjectAlternativeNameInfo<D>::IPAddress() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(ISubjectAlternativeNameInfo)->get_IPAddress(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_ISubjectAlternativeNameInfo<D>::Url() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(ISubjectAlternativeNameInfo)->get_Url(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_ISubjectAlternativeNameInfo<D>::DnsName() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(ISubjectAlternativeNameInfo)->get_DnsName(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_ISubjectAlternativeNameInfo<D>::DistinguishedName() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(ISubjectAlternativeNameInfo)->get_DistinguishedName(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_ISubjectAlternativeNameInfo<D>::PrincipalName() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(ISubjectAlternativeNameInfo)->get_PrincipalName(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Cryptography::Certificates::ExportOption impl_IPfxImportParameters<D>::Exportable() const
{
    Windows::Security::Cryptography::Certificates::ExportOption value {};
    check_hresult(WINRT_SHIM(IPfxImportParameters)->get_Exportable(&value));
    return value;
}

template <typename D> void impl_IPfxImportParameters<D>::Exportable(Windows::Security::Cryptography::Certificates::ExportOption value) const
{
    check_hresult(WINRT_SHIM(IPfxImportParameters)->put_Exportable(value));
}

template <typename D> Windows::Security::Cryptography::Certificates::KeyProtectionLevel impl_IPfxImportParameters<D>::KeyProtectionLevel() const
{
    Windows::Security::Cryptography::Certificates::KeyProtectionLevel value {};
    check_hresult(WINRT_SHIM(IPfxImportParameters)->get_KeyProtectionLevel(&value));
    return value;
}

template <typename D> void impl_IPfxImportParameters<D>::KeyProtectionLevel(Windows::Security::Cryptography::Certificates::KeyProtectionLevel value) const
{
    check_hresult(WINRT_SHIM(IPfxImportParameters)->put_KeyProtectionLevel(value));
}

template <typename D> Windows::Security::Cryptography::Certificates::InstallOptions impl_IPfxImportParameters<D>::InstallOptions() const
{
    Windows::Security::Cryptography::Certificates::InstallOptions value {};
    check_hresult(WINRT_SHIM(IPfxImportParameters)->get_InstallOptions(&value));
    return value;
}

template <typename D> void impl_IPfxImportParameters<D>::InstallOptions(Windows::Security::Cryptography::Certificates::InstallOptions value) const
{
    check_hresult(WINRT_SHIM(IPfxImportParameters)->put_InstallOptions(value));
}

template <typename D> hstring impl_IPfxImportParameters<D>::FriendlyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPfxImportParameters)->get_FriendlyName(put_abi(value)));
    return value;
}

template <typename D> void impl_IPfxImportParameters<D>::FriendlyName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPfxImportParameters)->put_FriendlyName(get_abi(value)));
}

template <typename D> hstring impl_IPfxImportParameters<D>::KeyStorageProviderName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPfxImportParameters)->get_KeyStorageProviderName(put_abi(value)));
    return value;
}

template <typename D> void impl_IPfxImportParameters<D>::KeyStorageProviderName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPfxImportParameters)->put_KeyStorageProviderName(get_abi(value)));
}

template <typename D> hstring impl_IPfxImportParameters<D>::ContainerNamePrefix() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPfxImportParameters)->get_ContainerNamePrefix(put_abi(value)));
    return value;
}

template <typename D> void impl_IPfxImportParameters<D>::ContainerNamePrefix(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPfxImportParameters)->put_ContainerNamePrefix(get_abi(value)));
}

template <typename D> hstring impl_IPfxImportParameters<D>::ReaderName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPfxImportParameters)->get_ReaderName(put_abi(value)));
    return value;
}

template <typename D> void impl_IPfxImportParameters<D>::ReaderName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPfxImportParameters)->put_ReaderName(get_abi(value)));
}

template <typename D> bool impl_ICertificateKeyUsages<D>::EncipherOnly() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICertificateKeyUsages)->get_EncipherOnly(&value));
    return value;
}

template <typename D> void impl_ICertificateKeyUsages<D>::EncipherOnly(bool value) const
{
    check_hresult(WINRT_SHIM(ICertificateKeyUsages)->put_EncipherOnly(value));
}

template <typename D> bool impl_ICertificateKeyUsages<D>::CrlSign() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICertificateKeyUsages)->get_CrlSign(&value));
    return value;
}

template <typename D> void impl_ICertificateKeyUsages<D>::CrlSign(bool value) const
{
    check_hresult(WINRT_SHIM(ICertificateKeyUsages)->put_CrlSign(value));
}

template <typename D> bool impl_ICertificateKeyUsages<D>::KeyCertificateSign() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICertificateKeyUsages)->get_KeyCertificateSign(&value));
    return value;
}

template <typename D> void impl_ICertificateKeyUsages<D>::KeyCertificateSign(bool value) const
{
    check_hresult(WINRT_SHIM(ICertificateKeyUsages)->put_KeyCertificateSign(value));
}

template <typename D> bool impl_ICertificateKeyUsages<D>::KeyAgreement() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICertificateKeyUsages)->get_KeyAgreement(&value));
    return value;
}

template <typename D> void impl_ICertificateKeyUsages<D>::KeyAgreement(bool value) const
{
    check_hresult(WINRT_SHIM(ICertificateKeyUsages)->put_KeyAgreement(value));
}

template <typename D> bool impl_ICertificateKeyUsages<D>::DataEncipherment() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICertificateKeyUsages)->get_DataEncipherment(&value));
    return value;
}

template <typename D> void impl_ICertificateKeyUsages<D>::DataEncipherment(bool value) const
{
    check_hresult(WINRT_SHIM(ICertificateKeyUsages)->put_DataEncipherment(value));
}

template <typename D> bool impl_ICertificateKeyUsages<D>::KeyEncipherment() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICertificateKeyUsages)->get_KeyEncipherment(&value));
    return value;
}

template <typename D> void impl_ICertificateKeyUsages<D>::KeyEncipherment(bool value) const
{
    check_hresult(WINRT_SHIM(ICertificateKeyUsages)->put_KeyEncipherment(value));
}

template <typename D> bool impl_ICertificateKeyUsages<D>::NonRepudiation() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICertificateKeyUsages)->get_NonRepudiation(&value));
    return value;
}

template <typename D> void impl_ICertificateKeyUsages<D>::NonRepudiation(bool value) const
{
    check_hresult(WINRT_SHIM(ICertificateKeyUsages)->put_NonRepudiation(value));
}

template <typename D> bool impl_ICertificateKeyUsages<D>::DigitalSignature() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICertificateKeyUsages)->get_DigitalSignature(&value));
    return value;
}

template <typename D> void impl_ICertificateKeyUsages<D>::DigitalSignature(bool value) const
{
    check_hresult(WINRT_SHIM(ICertificateKeyUsages)->put_DigitalSignature(value));
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> impl_ICmsAttachedSignature<D>::Certificates() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> value;
    check_hresult(WINRT_SHIM(ICmsAttachedSignature)->get_Certificates(put_abi(value)));
    return value;
}

template <typename D> com_array<uint8_t> impl_ICmsAttachedSignature<D>::Content() const
{
    com_array<uint8_t> value {};
    check_hresult(WINRT_SHIM(ICmsAttachedSignature)->get_Content(impl::put_size_abi(value), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::CmsSignerInfo> impl_ICmsAttachedSignature<D>::Signers() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::CmsSignerInfo> value;
    check_hresult(WINRT_SHIM(ICmsAttachedSignature)->get_Signers(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Cryptography::Certificates::SignatureValidationResult impl_ICmsAttachedSignature<D>::VerifySignature() const
{
    Windows::Security::Cryptography::Certificates::SignatureValidationResult value {};
    check_hresult(WINRT_SHIM(ICmsAttachedSignature)->abi_VerifySignature(&value));
    return value;
}

template <typename D> Windows::Security::Cryptography::Certificates::CmsAttachedSignature impl_ICmsAttachedSignatureFactory<D>::CreateCmsAttachedSignature(const Windows::Storage::Streams::IBuffer & inputBlob) const
{
    Windows::Security::Cryptography::Certificates::CmsAttachedSignature cmsSignedData { nullptr };
    check_hresult(WINRT_SHIM(ICmsAttachedSignatureFactory)->abi_CreateCmsAttachedSignature(get_abi(inputBlob), put_abi(cmsSignedData)));
    return cmsSignedData;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> impl_ICmsAttachedSignatureStatics<D>::GenerateSignatureAsync(const Windows::Storage::Streams::IBuffer & data, iterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo> signers, iterable<Windows::Security::Cryptography::Certificates::Certificate> certificates) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> outputBlob;
    check_hresult(WINRT_SHIM(ICmsAttachedSignatureStatics)->abi_GenerateSignatureAsync(get_abi(data), get_abi(signers), get_abi(certificates), put_abi(outputBlob)));
    return outputBlob;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> impl_ICmsDetachedSignature<D>::Certificates() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> value;
    check_hresult(WINRT_SHIM(ICmsDetachedSignature)->get_Certificates(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::CmsSignerInfo> impl_ICmsDetachedSignature<D>::Signers() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::CmsSignerInfo> value;
    check_hresult(WINRT_SHIM(ICmsDetachedSignature)->get_Signers(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Cryptography::Certificates::SignatureValidationResult> impl_ICmsDetachedSignature<D>::VerifySignatureAsync(const Windows::Storage::Streams::IInputStream & data) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Cryptography::Certificates::SignatureValidationResult> value;
    check_hresult(WINRT_SHIM(ICmsDetachedSignature)->abi_VerifySignatureAsync(get_abi(data), put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Cryptography::Certificates::CmsDetachedSignature impl_ICmsDetachedSignatureFactory<D>::CreateCmsDetachedSignature(const Windows::Storage::Streams::IBuffer & inputBlob) const
{
    Windows::Security::Cryptography::Certificates::CmsDetachedSignature cmsSignedData { nullptr };
    check_hresult(WINRT_SHIM(ICmsDetachedSignatureFactory)->abi_CreateCmsDetachedSignature(get_abi(inputBlob), put_abi(cmsSignedData)));
    return cmsSignedData;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> impl_ICmsDetachedSignatureStatics<D>::GenerateSignatureAsync(const Windows::Storage::Streams::IInputStream & data, iterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo> signers, iterable<Windows::Security::Cryptography::Certificates::Certificate> certificates) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> outputBlob;
    check_hresult(WINRT_SHIM(ICmsDetachedSignatureStatics)->abi_GenerateSignatureAsync(get_abi(data), get_abi(signers), get_abi(certificates), put_abi(outputBlob)));
    return outputBlob;
}

inline Certificate::Certificate(const Windows::Storage::Streams::IBuffer & certBlob) :
    Certificate(get_activation_factory<Certificate, ICertificateFactory>().CreateCertificate(certBlob))
{}

inline Windows::Foundation::IAsyncOperation<hstring> CertificateEnrollmentManager::CreateRequestAsync(const Windows::Security::Cryptography::Certificates::CertificateRequestProperties & request)
{
    return get_activation_factory<CertificateEnrollmentManager, ICertificateEnrollmentManagerStatics>().CreateRequestAsync(request);
}

inline Windows::Foundation::IAsyncAction CertificateEnrollmentManager::InstallCertificateAsync(hstring_view certificate, Windows::Security::Cryptography::Certificates::InstallOptions installOption)
{
    return get_activation_factory<CertificateEnrollmentManager, ICertificateEnrollmentManagerStatics>().InstallCertificateAsync(certificate, installOption);
}

inline Windows::Foundation::IAsyncAction CertificateEnrollmentManager::ImportPfxDataAsync(hstring_view pfxData, hstring_view password, Windows::Security::Cryptography::Certificates::ExportOption exportable, Windows::Security::Cryptography::Certificates::KeyProtectionLevel keyProtectionLevel, Windows::Security::Cryptography::Certificates::InstallOptions installOption, hstring_view friendlyName)
{
    return get_activation_factory<CertificateEnrollmentManager, ICertificateEnrollmentManagerStatics>().ImportPfxDataAsync(pfxData, password, exportable, keyProtectionLevel, installOption, friendlyName);
}

inline Windows::Security::Cryptography::Certificates::UserCertificateEnrollmentManager CertificateEnrollmentManager::UserCertificateEnrollmentManager()
{
    return get_activation_factory<CertificateEnrollmentManager, ICertificateEnrollmentManagerStatics2>().UserCertificateEnrollmentManager();
}

inline Windows::Foundation::IAsyncAction CertificateEnrollmentManager::ImportPfxDataAsync(hstring_view pfxData, hstring_view password, Windows::Security::Cryptography::Certificates::ExportOption exportable, Windows::Security::Cryptography::Certificates::KeyProtectionLevel keyProtectionLevel, Windows::Security::Cryptography::Certificates::InstallOptions installOption, hstring_view friendlyName, hstring_view keyStorageProvider)
{
    return get_activation_factory<CertificateEnrollmentManager, ICertificateEnrollmentManagerStatics2>().ImportPfxDataAsync(pfxData, password, exportable, keyProtectionLevel, installOption, friendlyName, keyStorageProvider);
}

inline Windows::Foundation::IAsyncAction CertificateEnrollmentManager::ImportPfxDataAsync(hstring_view pfxData, hstring_view password, const Windows::Security::Cryptography::Certificates::PfxImportParameters & pfxImportParameters)
{
    return get_activation_factory<CertificateEnrollmentManager, ICertificateEnrollmentManagerStatics3>().ImportPfxDataAsync(pfxData, password, pfxImportParameters);
}

inline CertificateKeyUsages::CertificateKeyUsages() :
    CertificateKeyUsages(activate_instance<CertificateKeyUsages>())
{}

inline CertificateQuery::CertificateQuery() :
    CertificateQuery(activate_instance<CertificateQuery>())
{}

inline CertificateRequestProperties::CertificateRequestProperties() :
    CertificateRequestProperties(activate_instance<CertificateRequestProperties>())
{}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate>> CertificateStores::FindAllAsync()
{
    return get_activation_factory<CertificateStores, ICertificateStoresStatics>().FindAllAsync();
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate>> CertificateStores::FindAllAsync(const Windows::Security::Cryptography::Certificates::CertificateQuery & query)
{
    return get_activation_factory<CertificateStores, ICertificateStoresStatics>().FindAllAsync(query);
}

inline Windows::Security::Cryptography::Certificates::CertificateStore CertificateStores::TrustedRootCertificationAuthorities()
{
    return get_activation_factory<CertificateStores, ICertificateStoresStatics>().TrustedRootCertificationAuthorities();
}

inline Windows::Security::Cryptography::Certificates::CertificateStore CertificateStores::IntermediateCertificationAuthorities()
{
    return get_activation_factory<CertificateStores, ICertificateStoresStatics>().IntermediateCertificationAuthorities();
}

inline Windows::Security::Cryptography::Certificates::CertificateStore CertificateStores::GetStoreByName(hstring_view storeName)
{
    return get_activation_factory<CertificateStores, ICertificateStoresStatics>().GetStoreByName(storeName);
}

inline Windows::Security::Cryptography::Certificates::UserCertificateStore CertificateStores::GetUserStoreByName(hstring_view storeName)
{
    return get_activation_factory<CertificateStores, ICertificateStoresStatics2>().GetUserStoreByName(storeName);
}

inline ChainBuildingParameters::ChainBuildingParameters() :
    ChainBuildingParameters(activate_instance<ChainBuildingParameters>())
{}

inline ChainValidationParameters::ChainValidationParameters() :
    ChainValidationParameters(activate_instance<ChainValidationParameters>())
{}

inline CmsAttachedSignature::CmsAttachedSignature(const Windows::Storage::Streams::IBuffer & inputBlob) :
    CmsAttachedSignature(get_activation_factory<CmsAttachedSignature, ICmsAttachedSignatureFactory>().CreateCmsAttachedSignature(inputBlob))
{}

inline Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> CmsAttachedSignature::GenerateSignatureAsync(const Windows::Storage::Streams::IBuffer & data, iterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo> signers, iterable<Windows::Security::Cryptography::Certificates::Certificate> certificates)
{
    return get_activation_factory<CmsAttachedSignature, ICmsAttachedSignatureStatics>().GenerateSignatureAsync(data, signers, certificates);
}

inline CmsDetachedSignature::CmsDetachedSignature(const Windows::Storage::Streams::IBuffer & inputBlob) :
    CmsDetachedSignature(get_activation_factory<CmsDetachedSignature, ICmsDetachedSignatureFactory>().CreateCmsDetachedSignature(inputBlob))
{}

inline Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> CmsDetachedSignature::GenerateSignatureAsync(const Windows::Storage::Streams::IInputStream & data, iterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo> signers, iterable<Windows::Security::Cryptography::Certificates::Certificate> certificates)
{
    return get_activation_factory<CmsDetachedSignature, ICmsDetachedSignatureStatics>().GenerateSignatureAsync(data, signers, certificates);
}

inline CmsSignerInfo::CmsSignerInfo() :
    CmsSignerInfo(activate_instance<CmsSignerInfo>())
{}

inline hstring KeyAlgorithmNames::Rsa()
{
    return get_activation_factory<KeyAlgorithmNames, IKeyAlgorithmNamesStatics>().Rsa();
}

inline hstring KeyAlgorithmNames::Dsa()
{
    return get_activation_factory<KeyAlgorithmNames, IKeyAlgorithmNamesStatics>().Dsa();
}

inline hstring KeyAlgorithmNames::Ecdh256()
{
    return get_activation_factory<KeyAlgorithmNames, IKeyAlgorithmNamesStatics>().Ecdh256();
}

inline hstring KeyAlgorithmNames::Ecdh384()
{
    return get_activation_factory<KeyAlgorithmNames, IKeyAlgorithmNamesStatics>().Ecdh384();
}

inline hstring KeyAlgorithmNames::Ecdh521()
{
    return get_activation_factory<KeyAlgorithmNames, IKeyAlgorithmNamesStatics>().Ecdh521();
}

inline hstring KeyAlgorithmNames::Ecdsa256()
{
    return get_activation_factory<KeyAlgorithmNames, IKeyAlgorithmNamesStatics>().Ecdsa256();
}

inline hstring KeyAlgorithmNames::Ecdsa384()
{
    return get_activation_factory<KeyAlgorithmNames, IKeyAlgorithmNamesStatics>().Ecdsa384();
}

inline hstring KeyAlgorithmNames::Ecdsa521()
{
    return get_activation_factory<KeyAlgorithmNames, IKeyAlgorithmNamesStatics>().Ecdsa521();
}

inline hstring KeyAlgorithmNames::Ecdsa()
{
    return get_activation_factory<KeyAlgorithmNames, IKeyAlgorithmNamesStatics2>().Ecdsa();
}

inline hstring KeyAlgorithmNames::Ecdh()
{
    return get_activation_factory<KeyAlgorithmNames, IKeyAlgorithmNamesStatics2>().Ecdh();
}

inline Windows::Foundation::IAsyncOperation<hstring> KeyAttestationHelper::DecryptTpmAttestationCredentialAsync(hstring_view credential)
{
    return get_activation_factory<KeyAttestationHelper, IKeyAttestationHelperStatics>().DecryptTpmAttestationCredentialAsync(credential);
}

inline hstring KeyAttestationHelper::GetTpmAttestationCredentialId(hstring_view credential)
{
    return get_activation_factory<KeyAttestationHelper, IKeyAttestationHelperStatics>().GetTpmAttestationCredentialId(credential);
}

inline Windows::Foundation::IAsyncOperation<hstring> KeyAttestationHelper::DecryptTpmAttestationCredentialAsync(hstring_view credential, hstring_view containerName)
{
    return get_activation_factory<KeyAttestationHelper, IKeyAttestationHelperStatics2>().DecryptTpmAttestationCredentialAsync(credential, containerName);
}

inline hstring KeyStorageProviderNames::SoftwareKeyStorageProvider()
{
    return get_activation_factory<KeyStorageProviderNames, IKeyStorageProviderNamesStatics>().SoftwareKeyStorageProvider();
}

inline hstring KeyStorageProviderNames::SmartcardKeyStorageProvider()
{
    return get_activation_factory<KeyStorageProviderNames, IKeyStorageProviderNamesStatics>().SmartcardKeyStorageProvider();
}

inline hstring KeyStorageProviderNames::PlatformKeyStorageProvider()
{
    return get_activation_factory<KeyStorageProviderNames, IKeyStorageProviderNamesStatics>().PlatformKeyStorageProvider();
}

inline hstring KeyStorageProviderNames::PassportKeyStorageProvider()
{
    return get_activation_factory<KeyStorageProviderNames, IKeyStorageProviderNamesStatics2>().PassportKeyStorageProvider();
}

inline PfxImportParameters::PfxImportParameters() :
    PfxImportParameters(activate_instance<PfxImportParameters>())
{}

inline hstring StandardCertificateStoreNames::Personal()
{
    return get_activation_factory<StandardCertificateStoreNames, IStandardCertificateStoreNamesStatics>().Personal();
}

inline hstring StandardCertificateStoreNames::TrustedRootCertificationAuthorities()
{
    return get_activation_factory<StandardCertificateStoreNames, IStandardCertificateStoreNamesStatics>().TrustedRootCertificationAuthorities();
}

inline hstring StandardCertificateStoreNames::IntermediateCertificationAuthorities()
{
    return get_activation_factory<StandardCertificateStoreNames, IStandardCertificateStoreNamesStatics>().IntermediateCertificationAuthorities();
}

inline SubjectAlternativeNameInfo::SubjectAlternativeNameInfo() :
    SubjectAlternativeNameInfo(activate_instance<SubjectAlternativeNameInfo>())
{}

}

}
#pragma warning(pop)
