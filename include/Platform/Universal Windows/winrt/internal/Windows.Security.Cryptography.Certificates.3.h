// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Security.Cryptography.Certificates.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Security::Cryptography::Certificates {

struct WINRT_EBO Certificate :
    Windows::Security::Cryptography::Certificates::ICertificate,
    impl::require<Certificate, Windows::Security::Cryptography::Certificates::ICertificate2, Windows::Security::Cryptography::Certificates::ICertificate3>
{
    Certificate(std::nullptr_t) noexcept {}
    Certificate(const Windows::Storage::Streams::IBuffer & certBlob);
};

struct WINRT_EBO CertificateChain :
    Windows::Security::Cryptography::Certificates::ICertificateChain
{
    CertificateChain(std::nullptr_t) noexcept {}
};

struct CertificateEnrollmentManager
{
    CertificateEnrollmentManager() = delete;
    static Windows::Foundation::IAsyncOperation<hstring> CreateRequestAsync(const Windows::Security::Cryptography::Certificates::CertificateRequestProperties & request);
    static Windows::Foundation::IAsyncAction InstallCertificateAsync(hstring_view certificate, Windows::Security::Cryptography::Certificates::InstallOptions installOption);
    static Windows::Foundation::IAsyncAction ImportPfxDataAsync(hstring_view pfxData, hstring_view password, Windows::Security::Cryptography::Certificates::ExportOption exportable, Windows::Security::Cryptography::Certificates::KeyProtectionLevel keyProtectionLevel, Windows::Security::Cryptography::Certificates::InstallOptions installOption, hstring_view friendlyName);
    static Windows::Security::Cryptography::Certificates::UserCertificateEnrollmentManager UserCertificateEnrollmentManager();
    static Windows::Foundation::IAsyncAction ImportPfxDataAsync(hstring_view pfxData, hstring_view password, Windows::Security::Cryptography::Certificates::ExportOption exportable, Windows::Security::Cryptography::Certificates::KeyProtectionLevel keyProtectionLevel, Windows::Security::Cryptography::Certificates::InstallOptions installOption, hstring_view friendlyName, hstring_view keyStorageProvider);
    static Windows::Foundation::IAsyncAction ImportPfxDataAsync(hstring_view pfxData, hstring_view password, const Windows::Security::Cryptography::Certificates::PfxImportParameters & pfxImportParameters);
};

struct WINRT_EBO CertificateKeyUsages :
    Windows::Security::Cryptography::Certificates::ICertificateKeyUsages
{
    CertificateKeyUsages(std::nullptr_t) noexcept {}
    CertificateKeyUsages();
};

struct WINRT_EBO CertificateQuery :
    Windows::Security::Cryptography::Certificates::ICertificateQuery,
    impl::require<CertificateQuery, Windows::Security::Cryptography::Certificates::ICertificateQuery2>
{
    CertificateQuery(std::nullptr_t) noexcept {}
    CertificateQuery();
};

struct WINRT_EBO CertificateRequestProperties :
    Windows::Security::Cryptography::Certificates::ICertificateRequestProperties,
    impl::require<CertificateRequestProperties, Windows::Security::Cryptography::Certificates::ICertificateRequestProperties2, Windows::Security::Cryptography::Certificates::ICertificateRequestProperties3>
{
    CertificateRequestProperties(std::nullptr_t) noexcept {}
    CertificateRequestProperties();
};

struct WINRT_EBO CertificateStore :
    Windows::Security::Cryptography::Certificates::ICertificateStore,
    impl::require<CertificateStore, Windows::Security::Cryptography::Certificates::ICertificateStore2>
{
    CertificateStore(std::nullptr_t) noexcept {}
};

struct CertificateStores
{
    CertificateStores() = delete;
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate>> FindAllAsync();
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate>> FindAllAsync(const Windows::Security::Cryptography::Certificates::CertificateQuery & query);
    static Windows::Security::Cryptography::Certificates::CertificateStore TrustedRootCertificationAuthorities();
    static Windows::Security::Cryptography::Certificates::CertificateStore IntermediateCertificationAuthorities();
    static Windows::Security::Cryptography::Certificates::CertificateStore GetStoreByName(hstring_view storeName);
    static Windows::Security::Cryptography::Certificates::UserCertificateStore GetUserStoreByName(hstring_view storeName);
};

struct WINRT_EBO ChainBuildingParameters :
    Windows::Security::Cryptography::Certificates::IChainBuildingParameters
{
    ChainBuildingParameters(std::nullptr_t) noexcept {}
    ChainBuildingParameters();
};

struct WINRT_EBO ChainValidationParameters :
    Windows::Security::Cryptography::Certificates::IChainValidationParameters
{
    ChainValidationParameters(std::nullptr_t) noexcept {}
    ChainValidationParameters();
};

struct WINRT_EBO CmsAttachedSignature :
    Windows::Security::Cryptography::Certificates::ICmsAttachedSignature
{
    CmsAttachedSignature(std::nullptr_t) noexcept {}
    CmsAttachedSignature(const Windows::Storage::Streams::IBuffer & inputBlob);
    static Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> GenerateSignatureAsync(const Windows::Storage::Streams::IBuffer & data, iterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo> signers, iterable<Windows::Security::Cryptography::Certificates::Certificate> certificates);
};

struct WINRT_EBO CmsDetachedSignature :
    Windows::Security::Cryptography::Certificates::ICmsDetachedSignature
{
    CmsDetachedSignature(std::nullptr_t) noexcept {}
    CmsDetachedSignature(const Windows::Storage::Streams::IBuffer & inputBlob);
    static Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> GenerateSignatureAsync(const Windows::Storage::Streams::IInputStream & data, iterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo> signers, iterable<Windows::Security::Cryptography::Certificates::Certificate> certificates);
};

struct WINRT_EBO CmsSignerInfo :
    Windows::Security::Cryptography::Certificates::ICmsSignerInfo
{
    CmsSignerInfo(std::nullptr_t) noexcept {}
    CmsSignerInfo();
};

struct WINRT_EBO CmsTimestampInfo :
    Windows::Security::Cryptography::Certificates::ICmsTimestampInfo
{
    CmsTimestampInfo(std::nullptr_t) noexcept {}
};

struct KeyAlgorithmNames
{
    KeyAlgorithmNames() = delete;
    static hstring Rsa();
    static hstring Dsa();
    static hstring Ecdh256();
    static hstring Ecdh384();
    static hstring Ecdh521();
    static hstring Ecdsa256();
    static hstring Ecdsa384();
    static hstring Ecdsa521();
    static hstring Ecdsa();
    static hstring Ecdh();
};

struct KeyAttestationHelper
{
    KeyAttestationHelper() = delete;
    static Windows::Foundation::IAsyncOperation<hstring> DecryptTpmAttestationCredentialAsync(hstring_view credential);
    static hstring GetTpmAttestationCredentialId(hstring_view credential);
    static Windows::Foundation::IAsyncOperation<hstring> DecryptTpmAttestationCredentialAsync(hstring_view credential, hstring_view containerName);
};

struct KeyStorageProviderNames
{
    KeyStorageProviderNames() = delete;
    static hstring SoftwareKeyStorageProvider();
    static hstring SmartcardKeyStorageProvider();
    static hstring PlatformKeyStorageProvider();
    static hstring PassportKeyStorageProvider();
};

struct WINRT_EBO PfxImportParameters :
    Windows::Security::Cryptography::Certificates::IPfxImportParameters
{
    PfxImportParameters(std::nullptr_t) noexcept {}
    PfxImportParameters();
};

struct StandardCertificateStoreNames
{
    StandardCertificateStoreNames() = delete;
    static hstring Personal();
    static hstring TrustedRootCertificationAuthorities();
    static hstring IntermediateCertificationAuthorities();
};

struct WINRT_EBO SubjectAlternativeNameInfo :
    Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo
{
    SubjectAlternativeNameInfo(std::nullptr_t) noexcept {}
    SubjectAlternativeNameInfo();
};

struct WINRT_EBO UserCertificateEnrollmentManager :
    Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager,
    impl::require<UserCertificateEnrollmentManager, Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager2>
{
    UserCertificateEnrollmentManager(std::nullptr_t) noexcept {}
    using impl_IUserCertificateEnrollmentManager::ImportPfxDataAsync;
    using impl_IUserCertificateEnrollmentManager2::ImportPfxDataAsync;
};

struct WINRT_EBO UserCertificateStore :
    Windows::Security::Cryptography::Certificates::IUserCertificateStore
{
    UserCertificateStore(std::nullptr_t) noexcept {}
};

}

}
