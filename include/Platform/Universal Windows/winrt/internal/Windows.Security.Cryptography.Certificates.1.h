// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Security.Cryptography.Certificates.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Networking.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Storage.Streams.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Security::Cryptography::Certificates {

struct __declspec(uuid("333f740c-04d8-43b3-b278-8c5fcc9be5a0")) __declspec(novtable) ICertificate : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_BuildChainAsync(Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate> * certificates, Windows::Foundation::IAsyncOperation<Windows::Security::Cryptography::Certificates::CertificateChain> ** value) = 0;
    virtual HRESULT __stdcall abi_BuildChainWithParametersAsync(Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate> * certificates, Windows::Security::Cryptography::Certificates::IChainBuildingParameters * parameters, Windows::Foundation::IAsyncOperation<Windows::Security::Cryptography::Certificates::CertificateChain> ** value) = 0;
    virtual HRESULT __stdcall get_SerialNumber(uint32_t * __valueSize, uint8_t ** value) = 0;
    virtual HRESULT __stdcall abi_GetHashValue(uint32_t * __valueSize, uint8_t ** value) = 0;
    virtual HRESULT __stdcall abi_GetHashValueWithAlgorithm(hstring hashAlgorithmName, uint32_t * __valueSize, uint8_t ** value) = 0;
    virtual HRESULT __stdcall abi_GetCertificateBlob(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall get_Subject(hstring * value) = 0;
    virtual HRESULT __stdcall get_Issuer(hstring * value) = 0;
    virtual HRESULT __stdcall get_HasPrivateKey(bool * value) = 0;
    virtual HRESULT __stdcall get_IsStronglyProtected(bool * value) = 0;
    virtual HRESULT __stdcall get_ValidFrom(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_ValidTo(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_EnhancedKeyUsages(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
    virtual HRESULT __stdcall put_FriendlyName(hstring value) = 0;
    virtual HRESULT __stdcall get_FriendlyName(hstring * value) = 0;
};

struct __declspec(uuid("17b8374c-8a25-4d96-a492-8fc29ac4fda6")) __declspec(novtable) ICertificate2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsSecurityDeviceBound(bool * value) = 0;
    virtual HRESULT __stdcall get_KeyUsages(Windows::Security::Cryptography::Certificates::ICertificateKeyUsages ** value) = 0;
    virtual HRESULT __stdcall get_KeyAlgorithmName(hstring * value) = 0;
    virtual HRESULT __stdcall get_SignatureAlgorithmName(hstring * value) = 0;
    virtual HRESULT __stdcall get_SignatureHashAlgorithmName(hstring * value) = 0;
    virtual HRESULT __stdcall get_SubjectAlternativeName(Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo ** value) = 0;
};

struct __declspec(uuid("be51a966-ae5f-4652-ace7-c6d7e7724cf3")) __declspec(novtable) ICertificate3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsPerUser(bool * value) = 0;
    virtual HRESULT __stdcall get_StoreName(hstring * value) = 0;
    virtual HRESULT __stdcall get_KeyStorageProviderName(hstring * value) = 0;
};

struct __declspec(uuid("20bf5385-3691-4501-a62c-fd97278b31ee")) __declspec(novtable) ICertificateChain : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Validate(winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult * status) = 0;
    virtual HRESULT __stdcall abi_ValidateWithParameters(Windows::Security::Cryptography::Certificates::IChainValidationParameters * parameter, winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult * status) = 0;
    virtual HRESULT __stdcall abi_GetCertificates(bool includeRoot, Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> ** certificates) = 0;
};

struct __declspec(uuid("8846ef3f-a986-48fb-9fd7-9aec06935bf1")) __declspec(novtable) ICertificateEnrollmentManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateRequestAsync(Windows::Security::Cryptography::Certificates::ICertificateRequestProperties * request, Windows::Foundation::IAsyncOperation<hstring> ** value) = 0;
    virtual HRESULT __stdcall abi_InstallCertificateAsync(hstring certificate, winrt::Windows::Security::Cryptography::Certificates::InstallOptions installOption, Windows::Foundation::IAsyncAction ** value) = 0;
    virtual HRESULT __stdcall abi_ImportPfxDataAsync(hstring pfxData, hstring password, winrt::Windows::Security::Cryptography::Certificates::ExportOption exportable, winrt::Windows::Security::Cryptography::Certificates::KeyProtectionLevel keyProtectionLevel, winrt::Windows::Security::Cryptography::Certificates::InstallOptions installOption, hstring friendlyName, Windows::Foundation::IAsyncAction ** value) = 0;
};

struct __declspec(uuid("dc5b1c33-6429-4014-999c-5d9735802d1d")) __declspec(novtable) ICertificateEnrollmentManagerStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_UserCertificateEnrollmentManager(Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager ** value) = 0;
    virtual HRESULT __stdcall abi_ImportPfxDataToKspAsync(hstring pfxData, hstring password, winrt::Windows::Security::Cryptography::Certificates::ExportOption exportable, winrt::Windows::Security::Cryptography::Certificates::KeyProtectionLevel keyProtectionLevel, winrt::Windows::Security::Cryptography::Certificates::InstallOptions installOption, hstring friendlyName, hstring keyStorageProvider, Windows::Foundation::IAsyncAction ** value) = 0;
};

struct __declspec(uuid("fdec82be-617c-425a-b72d-398b26ac7264")) __declspec(novtable) ICertificateEnrollmentManagerStatics3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ImportPfxDataToKspWithParametersAsync(hstring pfxData, hstring password, Windows::Security::Cryptography::Certificates::IPfxImportParameters * pfxImportParameters, Windows::Foundation::IAsyncAction ** value) = 0;
};

struct __declspec(uuid("17b4221c-4baf-44a2-9608-04fb62b16942")) __declspec(novtable) ICertificateFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateCertificate(Windows::Storage::Streams::IBuffer * certBlob, Windows::Security::Cryptography::Certificates::ICertificate ** certificate) = 0;
};

struct __declspec(uuid("6ac6206f-e1cf-486a-b485-a69c83e46fd1")) __declspec(novtable) ICertificateKeyUsages : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EncipherOnly(bool * value) = 0;
    virtual HRESULT __stdcall put_EncipherOnly(bool value) = 0;
    virtual HRESULT __stdcall get_CrlSign(bool * value) = 0;
    virtual HRESULT __stdcall put_CrlSign(bool value) = 0;
    virtual HRESULT __stdcall get_KeyCertificateSign(bool * value) = 0;
    virtual HRESULT __stdcall put_KeyCertificateSign(bool value) = 0;
    virtual HRESULT __stdcall get_KeyAgreement(bool * value) = 0;
    virtual HRESULT __stdcall put_KeyAgreement(bool value) = 0;
    virtual HRESULT __stdcall get_DataEncipherment(bool * value) = 0;
    virtual HRESULT __stdcall put_DataEncipherment(bool value) = 0;
    virtual HRESULT __stdcall get_KeyEncipherment(bool * value) = 0;
    virtual HRESULT __stdcall put_KeyEncipherment(bool value) = 0;
    virtual HRESULT __stdcall get_NonRepudiation(bool * value) = 0;
    virtual HRESULT __stdcall put_NonRepudiation(bool value) = 0;
    virtual HRESULT __stdcall get_DigitalSignature(bool * value) = 0;
    virtual HRESULT __stdcall put_DigitalSignature(bool value) = 0;
};

struct __declspec(uuid("5b082a31-a728-4916-b5ee-ffcb8acf2417")) __declspec(novtable) ICertificateQuery : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EnhancedKeyUsages(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_IssuerName(hstring * value) = 0;
    virtual HRESULT __stdcall put_IssuerName(hstring value) = 0;
    virtual HRESULT __stdcall get_FriendlyName(hstring * value) = 0;
    virtual HRESULT __stdcall put_FriendlyName(hstring value) = 0;
    virtual HRESULT __stdcall get_Thumbprint(uint32_t * __valueSize, uint8_t ** value) = 0;
    virtual HRESULT __stdcall put_Thumbprint(uint32_t __valueSize, uint8_t * value) = 0;
    virtual HRESULT __stdcall get_HardwareOnly(bool * value) = 0;
    virtual HRESULT __stdcall put_HardwareOnly(bool value) = 0;
};

struct __declspec(uuid("935a0af7-0bd9-4f75-b8c2-e27a7f74eecd")) __declspec(novtable) ICertificateQuery2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IncludeDuplicates(bool * value) = 0;
    virtual HRESULT __stdcall put_IncludeDuplicates(bool value) = 0;
    virtual HRESULT __stdcall get_IncludeExpiredCertificates(bool * value) = 0;
    virtual HRESULT __stdcall put_IncludeExpiredCertificates(bool value) = 0;
    virtual HRESULT __stdcall get_StoreName(hstring * value) = 0;
    virtual HRESULT __stdcall put_StoreName(hstring value) = 0;
};

struct __declspec(uuid("487e84f6-94e2-4dce-8833-1a700a37a29a")) __declspec(novtable) ICertificateRequestProperties : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Subject(hstring * value) = 0;
    virtual HRESULT __stdcall put_Subject(hstring value) = 0;
    virtual HRESULT __stdcall get_KeyAlgorithmName(hstring * value) = 0;
    virtual HRESULT __stdcall put_KeyAlgorithmName(hstring value) = 0;
    virtual HRESULT __stdcall get_KeySize(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_KeySize(uint32_t value) = 0;
    virtual HRESULT __stdcall get_FriendlyName(hstring * value) = 0;
    virtual HRESULT __stdcall put_FriendlyName(hstring value) = 0;
    virtual HRESULT __stdcall get_HashAlgorithmName(hstring * value) = 0;
    virtual HRESULT __stdcall put_HashAlgorithmName(hstring value) = 0;
    virtual HRESULT __stdcall get_Exportable(winrt::Windows::Security::Cryptography::Certificates::ExportOption * value) = 0;
    virtual HRESULT __stdcall put_Exportable(winrt::Windows::Security::Cryptography::Certificates::ExportOption value) = 0;
    virtual HRESULT __stdcall get_KeyUsages(winrt::Windows::Security::Cryptography::Certificates::EnrollKeyUsages * value) = 0;
    virtual HRESULT __stdcall put_KeyUsages(winrt::Windows::Security::Cryptography::Certificates::EnrollKeyUsages value) = 0;
    virtual HRESULT __stdcall get_KeyProtectionLevel(winrt::Windows::Security::Cryptography::Certificates::KeyProtectionLevel * value) = 0;
    virtual HRESULT __stdcall put_KeyProtectionLevel(winrt::Windows::Security::Cryptography::Certificates::KeyProtectionLevel value) = 0;
    virtual HRESULT __stdcall get_KeyStorageProviderName(hstring * value) = 0;
    virtual HRESULT __stdcall put_KeyStorageProviderName(hstring value) = 0;
};

struct __declspec(uuid("3da0c954-d73f-4ff3-a0a6-0677c0ada05b")) __declspec(novtable) ICertificateRequestProperties2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SmartcardReaderName(hstring * value) = 0;
    virtual HRESULT __stdcall put_SmartcardReaderName(hstring value) = 0;
    virtual HRESULT __stdcall get_SigningCertificate(Windows::Security::Cryptography::Certificates::ICertificate ** value) = 0;
    virtual HRESULT __stdcall put_SigningCertificate(Windows::Security::Cryptography::Certificates::ICertificate * value) = 0;
    virtual HRESULT __stdcall get_AttestationCredentialCertificate(Windows::Security::Cryptography::Certificates::ICertificate ** value) = 0;
    virtual HRESULT __stdcall put_AttestationCredentialCertificate(Windows::Security::Cryptography::Certificates::ICertificate * value) = 0;
};

struct __declspec(uuid("e687f616-734d-46b1-9d4c-6edfdbfc845b")) __declspec(novtable) ICertificateRequestProperties3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CurveName(hstring * value) = 0;
    virtual HRESULT __stdcall put_CurveName(hstring value) = 0;
    virtual HRESULT __stdcall get_CurveParameters(uint32_t * __valueSize, uint8_t ** value) = 0;
    virtual HRESULT __stdcall put_CurveParameters(uint32_t __valueSize, uint8_t * value) = 0;
    virtual HRESULT __stdcall get_ContainerNamePrefix(hstring * value) = 0;
    virtual HRESULT __stdcall put_ContainerNamePrefix(hstring value) = 0;
    virtual HRESULT __stdcall get_ContainerName(hstring * value) = 0;
    virtual HRESULT __stdcall put_ContainerName(hstring value) = 0;
    virtual HRESULT __stdcall get_UseExistingKey(bool * value) = 0;
    virtual HRESULT __stdcall put_UseExistingKey(bool value) = 0;
};

struct __declspec(uuid("b0bff720-344e-4331-af14-a7f7a7ebc93a")) __declspec(novtable) ICertificateStore : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Add(Windows::Security::Cryptography::Certificates::ICertificate * certificate) = 0;
    virtual HRESULT __stdcall abi_Delete(Windows::Security::Cryptography::Certificates::ICertificate * certificate) = 0;
};

struct __declspec(uuid("c7e68e4a-417d-4d1a-babd-15687e549974")) __declspec(novtable) ICertificateStore2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
};

struct __declspec(uuid("fbecc739-c6fe-4de7-99cf-74c3e596e032")) __declspec(novtable) ICertificateStoresStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FindAllAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate>> ** value) = 0;
    virtual HRESULT __stdcall abi_FindAllWithQueryAsync(Windows::Security::Cryptography::Certificates::ICertificateQuery * query, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate>> ** value) = 0;
    virtual HRESULT __stdcall get_TrustedRootCertificationAuthorities(Windows::Security::Cryptography::Certificates::ICertificateStore ** value) = 0;
    virtual HRESULT __stdcall get_IntermediateCertificationAuthorities(Windows::Security::Cryptography::Certificates::ICertificateStore ** value) = 0;
    virtual HRESULT __stdcall abi_GetStoreByName(hstring storeName, Windows::Security::Cryptography::Certificates::ICertificateStore ** value) = 0;
};

struct __declspec(uuid("fa900b79-a0d4-4b8c-bc55-c0a37eb141ed")) __declspec(novtable) ICertificateStoresStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetUserStoreByName(hstring storeName, Windows::Security::Cryptography::Certificates::IUserCertificateStore ** result) = 0;
};

struct __declspec(uuid("422ba922-7c8d-47b7-b59b-b12703733ac3")) __declspec(novtable) IChainBuildingParameters : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EnhancedKeyUsages(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_ValidationTimestamp(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall put_ValidationTimestamp(Windows::Foundation::DateTime value) = 0;
    virtual HRESULT __stdcall get_RevocationCheckEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_RevocationCheckEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_NetworkRetrievalEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_NetworkRetrievalEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_AuthorityInformationAccessEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_AuthorityInformationAccessEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_CurrentTimeValidationEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_CurrentTimeValidationEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_ExclusiveTrustRoots(Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::Certificate> ** certificates) = 0;
};

struct __declspec(uuid("c4743b4a-7eb0-4b56-a040-b9c8e655ddf3")) __declspec(novtable) IChainValidationParameters : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CertificateChainPolicy(winrt::Windows::Security::Cryptography::Certificates::CertificateChainPolicy * value) = 0;
    virtual HRESULT __stdcall put_CertificateChainPolicy(winrt::Windows::Security::Cryptography::Certificates::CertificateChainPolicy value) = 0;
    virtual HRESULT __stdcall get_ServerDnsName(Windows::Networking::IHostName ** value) = 0;
    virtual HRESULT __stdcall put_ServerDnsName(Windows::Networking::IHostName * value) = 0;
};

struct __declspec(uuid("61899d9d-3757-4ecb-bddc-0ca357d7a936")) __declspec(novtable) ICmsAttachedSignature : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Certificates(Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> ** value) = 0;
    virtual HRESULT __stdcall get_Content(uint32_t * __valueSize, uint8_t ** value) = 0;
    virtual HRESULT __stdcall get_Signers(Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::CmsSignerInfo> ** value) = 0;
    virtual HRESULT __stdcall abi_VerifySignature(winrt::Windows::Security::Cryptography::Certificates::SignatureValidationResult * value) = 0;
};

struct __declspec(uuid("d0c8fc15-f757-4c64-a362-52cc1c77cffb")) __declspec(novtable) ICmsAttachedSignatureFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateCmsAttachedSignature(Windows::Storage::Streams::IBuffer * inputBlob, Windows::Security::Cryptography::Certificates::ICmsAttachedSignature ** cmsSignedData) = 0;
};

struct __declspec(uuid("87989c8e-b0ad-498d-a7f5-78b59bce4b36")) __declspec(novtable) ICmsAttachedSignatureStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GenerateSignatureAsync(Windows::Storage::Streams::IBuffer * data, Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo> * signers, Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate> * certificates, Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> ** outputBlob) = 0;
};

struct __declspec(uuid("0f1ef154-f65e-4536-8339-5944081db2ca")) __declspec(novtable) ICmsDetachedSignature : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Certificates(Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> ** value) = 0;
    virtual HRESULT __stdcall get_Signers(Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::CmsSignerInfo> ** value) = 0;
    virtual HRESULT __stdcall abi_VerifySignatureAsync(Windows::Storage::Streams::IInputStream * data, Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Cryptography::Certificates::SignatureValidationResult> ** value) = 0;
};

struct __declspec(uuid("c4ab3503-ae7f-4387-ad19-00f150e48ebb")) __declspec(novtable) ICmsDetachedSignatureFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateCmsDetachedSignature(Windows::Storage::Streams::IBuffer * inputBlob, Windows::Security::Cryptography::Certificates::ICmsDetachedSignature ** cmsSignedData) = 0;
};

struct __declspec(uuid("3d114cfd-bf9b-4682-9be6-91f57c053808")) __declspec(novtable) ICmsDetachedSignatureStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GenerateSignatureAsync(Windows::Storage::Streams::IInputStream * data, Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo> * signers, Windows::Foundation::Collections::IIterable<Windows::Security::Cryptography::Certificates::Certificate> * certificates, Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> ** outputBlob) = 0;
};

struct __declspec(uuid("50d020db-1d2f-4c1a-b5c5-d0188ff91f47")) __declspec(novtable) ICmsSignerInfo : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Certificate(Windows::Security::Cryptography::Certificates::ICertificate ** value) = 0;
    virtual HRESULT __stdcall put_Certificate(Windows::Security::Cryptography::Certificates::ICertificate * value) = 0;
    virtual HRESULT __stdcall get_HashAlgorithmName(hstring * value) = 0;
    virtual HRESULT __stdcall put_HashAlgorithmName(hstring value) = 0;
    virtual HRESULT __stdcall get_TimestampInfo(Windows::Security::Cryptography::Certificates::ICmsTimestampInfo ** value) = 0;
};

struct __declspec(uuid("2f5f00f2-2c18-4f88-8435-c534086076f5")) __declspec(novtable) ICmsTimestampInfo : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SigningCertificate(Windows::Security::Cryptography::Certificates::ICertificate ** value) = 0;
    virtual HRESULT __stdcall get_Certificates(Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> ** value) = 0;
    virtual HRESULT __stdcall get_Timestamp(Windows::Foundation::DateTime * value) = 0;
};

struct __declspec(uuid("479065d7-7ac7-4581-8c3b-d07027140448")) __declspec(novtable) IKeyAlgorithmNamesStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Rsa(hstring * value) = 0;
    virtual HRESULT __stdcall get_Dsa(hstring * value) = 0;
    virtual HRESULT __stdcall get_Ecdh256(hstring * value) = 0;
    virtual HRESULT __stdcall get_Ecdh384(hstring * value) = 0;
    virtual HRESULT __stdcall get_Ecdh521(hstring * value) = 0;
    virtual HRESULT __stdcall get_Ecdsa256(hstring * value) = 0;
    virtual HRESULT __stdcall get_Ecdsa384(hstring * value) = 0;
    virtual HRESULT __stdcall get_Ecdsa521(hstring * value) = 0;
};

struct __declspec(uuid("c99b5686-e1fd-4a4a-893d-a26f33dd8bb4")) __declspec(novtable) IKeyAlgorithmNamesStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Ecdsa(hstring * value) = 0;
    virtual HRESULT __stdcall get_Ecdh(hstring * value) = 0;
};

struct __declspec(uuid("1648e246-f644-4326-88be-3af102d30e0c")) __declspec(novtable) IKeyAttestationHelperStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_DecryptTpmAttestationCredentialAsync(hstring credential, Windows::Foundation::IAsyncOperation<hstring> ** value) = 0;
    virtual HRESULT __stdcall abi_GetTpmAttestationCredentialId(hstring credential, hstring * value) = 0;
};

struct __declspec(uuid("9c590b2c-a6c6-4a5e-9e64-e85d5279df97")) __declspec(novtable) IKeyAttestationHelperStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_DecryptTpmAttestationCredentialWithContainerNameAsync(hstring credential, hstring containerName, Windows::Foundation::IAsyncOperation<hstring> ** value) = 0;
};

struct __declspec(uuid("af186ae0-5529-4602-bd94-0aab91957b5c")) __declspec(novtable) IKeyStorageProviderNamesStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SoftwareKeyStorageProvider(hstring * value) = 0;
    virtual HRESULT __stdcall get_SmartcardKeyStorageProvider(hstring * value) = 0;
    virtual HRESULT __stdcall get_PlatformKeyStorageProvider(hstring * value) = 0;
};

struct __declspec(uuid("262d743d-9c2e-41cc-8812-c4d971dd7c60")) __declspec(novtable) IKeyStorageProviderNamesStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PassportKeyStorageProvider(hstring * value) = 0;
};

struct __declspec(uuid("680d3511-9a08-47c8-864a-2edd4d8eb46c")) __declspec(novtable) IPfxImportParameters : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Exportable(winrt::Windows::Security::Cryptography::Certificates::ExportOption * value) = 0;
    virtual HRESULT __stdcall put_Exportable(winrt::Windows::Security::Cryptography::Certificates::ExportOption value) = 0;
    virtual HRESULT __stdcall get_KeyProtectionLevel(winrt::Windows::Security::Cryptography::Certificates::KeyProtectionLevel * value) = 0;
    virtual HRESULT __stdcall put_KeyProtectionLevel(winrt::Windows::Security::Cryptography::Certificates::KeyProtectionLevel value) = 0;
    virtual HRESULT __stdcall get_InstallOptions(winrt::Windows::Security::Cryptography::Certificates::InstallOptions * value) = 0;
    virtual HRESULT __stdcall put_InstallOptions(winrt::Windows::Security::Cryptography::Certificates::InstallOptions value) = 0;
    virtual HRESULT __stdcall get_FriendlyName(hstring * value) = 0;
    virtual HRESULT __stdcall put_FriendlyName(hstring value) = 0;
    virtual HRESULT __stdcall get_KeyStorageProviderName(hstring * value) = 0;
    virtual HRESULT __stdcall put_KeyStorageProviderName(hstring value) = 0;
    virtual HRESULT __stdcall get_ContainerNamePrefix(hstring * value) = 0;
    virtual HRESULT __stdcall put_ContainerNamePrefix(hstring value) = 0;
    virtual HRESULT __stdcall get_ReaderName(hstring * value) = 0;
    virtual HRESULT __stdcall put_ReaderName(hstring value) = 0;
};

struct __declspec(uuid("0c154adb-a496-41f8-8fe5-9e96f36efbf8")) __declspec(novtable) IStandardCertificateStoreNamesStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Personal(hstring * value) = 0;
    virtual HRESULT __stdcall get_TrustedRootCertificationAuthorities(hstring * value) = 0;
    virtual HRESULT __stdcall get_IntermediateCertificationAuthorities(hstring * value) = 0;
};

struct __declspec(uuid("582859f1-569d-4c20-be7b-4e1c9a0bc52b")) __declspec(novtable) ISubjectAlternativeNameInfo : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EmailName(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_IPAddress(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_Url(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_DnsName(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_DistinguishedName(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_PrincipalName(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
};

struct __declspec(uuid("96313718-22e1-4819-b20b-ab46a6eca06e")) __declspec(novtable) IUserCertificateEnrollmentManager : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateRequestAsync(Windows::Security::Cryptography::Certificates::ICertificateRequestProperties * request, Windows::Foundation::IAsyncOperation<hstring> ** value) = 0;
    virtual HRESULT __stdcall abi_InstallCertificateAsync(hstring certificate, winrt::Windows::Security::Cryptography::Certificates::InstallOptions installOption, Windows::Foundation::IAsyncAction ** value) = 0;
    virtual HRESULT __stdcall abi_ImportPfxDataAsync(hstring pfxData, hstring password, winrt::Windows::Security::Cryptography::Certificates::ExportOption exportable, winrt::Windows::Security::Cryptography::Certificates::KeyProtectionLevel keyProtectionLevel, winrt::Windows::Security::Cryptography::Certificates::InstallOptions installOption, hstring friendlyName, Windows::Foundation::IAsyncAction ** value) = 0;
    virtual HRESULT __stdcall abi_ImportPfxDataToKspAsync(hstring pfxData, hstring password, winrt::Windows::Security::Cryptography::Certificates::ExportOption exportable, winrt::Windows::Security::Cryptography::Certificates::KeyProtectionLevel keyProtectionLevel, winrt::Windows::Security::Cryptography::Certificates::InstallOptions installOption, hstring friendlyName, hstring keyStorageProvider, Windows::Foundation::IAsyncAction ** value) = 0;
};

struct __declspec(uuid("0dad9cb1-65de-492a-b86d-fc5c482c3747")) __declspec(novtable) IUserCertificateEnrollmentManager2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ImportPfxDataToKspWithParametersAsync(hstring pfxData, hstring password, Windows::Security::Cryptography::Certificates::IPfxImportParameters * pfxImportParameters, Windows::Foundation::IAsyncAction ** value) = 0;
};

struct __declspec(uuid("c9fb1d83-789f-4b4e-9180-045a757aac6d")) __declspec(novtable) IUserCertificateStore : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RequestAddAsync(Windows::Security::Cryptography::Certificates::ICertificate * certificate, Windows::Foundation::IAsyncOperation<bool> ** result) = 0;
    virtual HRESULT __stdcall abi_RequestDeleteAsync(Windows::Security::Cryptography::Certificates::ICertificate * certificate, Windows::Foundation::IAsyncOperation<bool> ** result) = 0;
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Security::Cryptography::Certificates::Certificate> { using default_interface = Windows::Security::Cryptography::Certificates::ICertificate; };
template <> struct traits<Windows::Security::Cryptography::Certificates::CertificateChain> { using default_interface = Windows::Security::Cryptography::Certificates::ICertificateChain; };
template <> struct traits<Windows::Security::Cryptography::Certificates::CertificateKeyUsages> { using default_interface = Windows::Security::Cryptography::Certificates::ICertificateKeyUsages; };
template <> struct traits<Windows::Security::Cryptography::Certificates::CertificateQuery> { using default_interface = Windows::Security::Cryptography::Certificates::ICertificateQuery; };
template <> struct traits<Windows::Security::Cryptography::Certificates::CertificateRequestProperties> { using default_interface = Windows::Security::Cryptography::Certificates::ICertificateRequestProperties; };
template <> struct traits<Windows::Security::Cryptography::Certificates::CertificateStore> { using default_interface = Windows::Security::Cryptography::Certificates::ICertificateStore; };
template <> struct traits<Windows::Security::Cryptography::Certificates::ChainBuildingParameters> { using default_interface = Windows::Security::Cryptography::Certificates::IChainBuildingParameters; };
template <> struct traits<Windows::Security::Cryptography::Certificates::ChainValidationParameters> { using default_interface = Windows::Security::Cryptography::Certificates::IChainValidationParameters; };
template <> struct traits<Windows::Security::Cryptography::Certificates::CmsAttachedSignature> { using default_interface = Windows::Security::Cryptography::Certificates::ICmsAttachedSignature; };
template <> struct traits<Windows::Security::Cryptography::Certificates::CmsDetachedSignature> { using default_interface = Windows::Security::Cryptography::Certificates::ICmsDetachedSignature; };
template <> struct traits<Windows::Security::Cryptography::Certificates::CmsSignerInfo> { using default_interface = Windows::Security::Cryptography::Certificates::ICmsSignerInfo; };
template <> struct traits<Windows::Security::Cryptography::Certificates::CmsTimestampInfo> { using default_interface = Windows::Security::Cryptography::Certificates::ICmsTimestampInfo; };
template <> struct traits<Windows::Security::Cryptography::Certificates::PfxImportParameters> { using default_interface = Windows::Security::Cryptography::Certificates::IPfxImportParameters; };
template <> struct traits<Windows::Security::Cryptography::Certificates::SubjectAlternativeNameInfo> { using default_interface = Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo; };
template <> struct traits<Windows::Security::Cryptography::Certificates::UserCertificateEnrollmentManager> { using default_interface = Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager; };
template <> struct traits<Windows::Security::Cryptography::Certificates::UserCertificateStore> { using default_interface = Windows::Security::Cryptography::Certificates::IUserCertificateStore; };

}

namespace Windows::Security::Cryptography::Certificates {

template <typename D>
struct WINRT_EBO impl_ICertificate
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Cryptography::Certificates::CertificateChain> BuildChainAsync(iterable<Windows::Security::Cryptography::Certificates::Certificate> certificates) const;
    Windows::Foundation::IAsyncOperation<Windows::Security::Cryptography::Certificates::CertificateChain> BuildChainAsync(iterable<Windows::Security::Cryptography::Certificates::Certificate> certificates, const Windows::Security::Cryptography::Certificates::ChainBuildingParameters & parameters) const;
    com_array<uint8_t> SerialNumber() const;
    com_array<uint8_t> GetHashValue() const;
    com_array<uint8_t> GetHashValue(hstring_view hashAlgorithmName) const;
    Windows::Storage::Streams::IBuffer GetCertificateBlob() const;
    hstring Subject() const;
    hstring Issuer() const;
    bool HasPrivateKey() const;
    bool IsStronglyProtected() const;
    Windows::Foundation::DateTime ValidFrom() const;
    Windows::Foundation::DateTime ValidTo() const;
    Windows::Foundation::Collections::IVectorView<hstring> EnhancedKeyUsages() const;
    void FriendlyName(hstring_view value) const;
    hstring FriendlyName() const;
};

template <typename D>
struct WINRT_EBO impl_ICertificate2
{
    bool IsSecurityDeviceBound() const;
    Windows::Security::Cryptography::Certificates::CertificateKeyUsages KeyUsages() const;
    hstring KeyAlgorithmName() const;
    hstring SignatureAlgorithmName() const;
    hstring SignatureHashAlgorithmName() const;
    Windows::Security::Cryptography::Certificates::SubjectAlternativeNameInfo SubjectAlternativeName() const;
};

template <typename D>
struct WINRT_EBO impl_ICertificate3
{
    bool IsPerUser() const;
    hstring StoreName() const;
    hstring KeyStorageProviderName() const;
};

template <typename D>
struct WINRT_EBO impl_ICertificateChain
{
    Windows::Security::Cryptography::Certificates::ChainValidationResult Validate() const;
    Windows::Security::Cryptography::Certificates::ChainValidationResult Validate(const Windows::Security::Cryptography::Certificates::ChainValidationParameters & parameter) const;
    Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> GetCertificates(bool includeRoot) const;
};

template <typename D>
struct WINRT_EBO impl_ICertificateEnrollmentManagerStatics
{
    Windows::Foundation::IAsyncOperation<hstring> CreateRequestAsync(const Windows::Security::Cryptography::Certificates::CertificateRequestProperties & request) const;
    Windows::Foundation::IAsyncAction InstallCertificateAsync(hstring_view certificate, Windows::Security::Cryptography::Certificates::InstallOptions installOption) const;
    Windows::Foundation::IAsyncAction ImportPfxDataAsync(hstring_view pfxData, hstring_view password, Windows::Security::Cryptography::Certificates::ExportOption exportable, Windows::Security::Cryptography::Certificates::KeyProtectionLevel keyProtectionLevel, Windows::Security::Cryptography::Certificates::InstallOptions installOption, hstring_view friendlyName) const;
};

template <typename D>
struct WINRT_EBO impl_ICertificateEnrollmentManagerStatics2
{
    Windows::Security::Cryptography::Certificates::UserCertificateEnrollmentManager UserCertificateEnrollmentManager() const;
    Windows::Foundation::IAsyncAction ImportPfxDataAsync(hstring_view pfxData, hstring_view password, Windows::Security::Cryptography::Certificates::ExportOption exportable, Windows::Security::Cryptography::Certificates::KeyProtectionLevel keyProtectionLevel, Windows::Security::Cryptography::Certificates::InstallOptions installOption, hstring_view friendlyName, hstring_view keyStorageProvider) const;
};

template <typename D>
struct WINRT_EBO impl_ICertificateEnrollmentManagerStatics3
{
    Windows::Foundation::IAsyncAction ImportPfxDataAsync(hstring_view pfxData, hstring_view password, const Windows::Security::Cryptography::Certificates::PfxImportParameters & pfxImportParameters) const;
};

template <typename D>
struct WINRT_EBO impl_ICertificateFactory
{
    Windows::Security::Cryptography::Certificates::Certificate CreateCertificate(const Windows::Storage::Streams::IBuffer & certBlob) const;
};

template <typename D>
struct WINRT_EBO impl_ICertificateKeyUsages
{
    bool EncipherOnly() const;
    void EncipherOnly(bool value) const;
    bool CrlSign() const;
    void CrlSign(bool value) const;
    bool KeyCertificateSign() const;
    void KeyCertificateSign(bool value) const;
    bool KeyAgreement() const;
    void KeyAgreement(bool value) const;
    bool DataEncipherment() const;
    void DataEncipherment(bool value) const;
    bool KeyEncipherment() const;
    void KeyEncipherment(bool value) const;
    bool NonRepudiation() const;
    void NonRepudiation(bool value) const;
    bool DigitalSignature() const;
    void DigitalSignature(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_ICertificateQuery
{
    Windows::Foundation::Collections::IVector<hstring> EnhancedKeyUsages() const;
    hstring IssuerName() const;
    void IssuerName(hstring_view value) const;
    hstring FriendlyName() const;
    void FriendlyName(hstring_view value) const;
    com_array<uint8_t> Thumbprint() const;
    void Thumbprint(array_view<const uint8_t> value) const;
    bool HardwareOnly() const;
    void HardwareOnly(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_ICertificateQuery2
{
    bool IncludeDuplicates() const;
    void IncludeDuplicates(bool value) const;
    bool IncludeExpiredCertificates() const;
    void IncludeExpiredCertificates(bool value) const;
    hstring StoreName() const;
    void StoreName(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_ICertificateRequestProperties
{
    hstring Subject() const;
    void Subject(hstring_view value) const;
    hstring KeyAlgorithmName() const;
    void KeyAlgorithmName(hstring_view value) const;
    uint32_t KeySize() const;
    void KeySize(uint32_t value) const;
    hstring FriendlyName() const;
    void FriendlyName(hstring_view value) const;
    hstring HashAlgorithmName() const;
    void HashAlgorithmName(hstring_view value) const;
    Windows::Security::Cryptography::Certificates::ExportOption Exportable() const;
    void Exportable(Windows::Security::Cryptography::Certificates::ExportOption value) const;
    Windows::Security::Cryptography::Certificates::EnrollKeyUsages KeyUsages() const;
    void KeyUsages(Windows::Security::Cryptography::Certificates::EnrollKeyUsages value) const;
    Windows::Security::Cryptography::Certificates::KeyProtectionLevel KeyProtectionLevel() const;
    void KeyProtectionLevel(Windows::Security::Cryptography::Certificates::KeyProtectionLevel value) const;
    hstring KeyStorageProviderName() const;
    void KeyStorageProviderName(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_ICertificateRequestProperties2
{
    hstring SmartcardReaderName() const;
    void SmartcardReaderName(hstring_view value) const;
    Windows::Security::Cryptography::Certificates::Certificate SigningCertificate() const;
    void SigningCertificate(const Windows::Security::Cryptography::Certificates::Certificate & value) const;
    Windows::Security::Cryptography::Certificates::Certificate AttestationCredentialCertificate() const;
    void AttestationCredentialCertificate(const Windows::Security::Cryptography::Certificates::Certificate & value) const;
};

template <typename D>
struct WINRT_EBO impl_ICertificateRequestProperties3
{
    hstring CurveName() const;
    void CurveName(hstring_view value) const;
    com_array<uint8_t> CurveParameters() const;
    void CurveParameters(array_view<const uint8_t> value) const;
    hstring ContainerNamePrefix() const;
    void ContainerNamePrefix(hstring_view value) const;
    hstring ContainerName() const;
    void ContainerName(hstring_view value) const;
    bool UseExistingKey() const;
    void UseExistingKey(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_ICertificateStore
{
    void Add(const Windows::Security::Cryptography::Certificates::Certificate & certificate) const;
    void Delete(const Windows::Security::Cryptography::Certificates::Certificate & certificate) const;
};

template <typename D>
struct WINRT_EBO impl_ICertificateStore2
{
    hstring Name() const;
};

template <typename D>
struct WINRT_EBO impl_ICertificateStoresStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate>> FindAllAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate>> FindAllAsync(const Windows::Security::Cryptography::Certificates::CertificateQuery & query) const;
    Windows::Security::Cryptography::Certificates::CertificateStore TrustedRootCertificationAuthorities() const;
    Windows::Security::Cryptography::Certificates::CertificateStore IntermediateCertificationAuthorities() const;
    Windows::Security::Cryptography::Certificates::CertificateStore GetStoreByName(hstring_view storeName) const;
};

template <typename D>
struct WINRT_EBO impl_ICertificateStoresStatics2
{
    Windows::Security::Cryptography::Certificates::UserCertificateStore GetUserStoreByName(hstring_view storeName) const;
};

template <typename D>
struct WINRT_EBO impl_IChainBuildingParameters
{
    Windows::Foundation::Collections::IVector<hstring> EnhancedKeyUsages() const;
    Windows::Foundation::DateTime ValidationTimestamp() const;
    void ValidationTimestamp(const Windows::Foundation::DateTime & value) const;
    bool RevocationCheckEnabled() const;
    void RevocationCheckEnabled(bool value) const;
    bool NetworkRetrievalEnabled() const;
    void NetworkRetrievalEnabled(bool value) const;
    bool AuthorityInformationAccessEnabled() const;
    void AuthorityInformationAccessEnabled(bool value) const;
    bool CurrentTimeValidationEnabled() const;
    void CurrentTimeValidationEnabled(bool value) const;
    Windows::Foundation::Collections::IVector<Windows::Security::Cryptography::Certificates::Certificate> ExclusiveTrustRoots() const;
};

template <typename D>
struct WINRT_EBO impl_IChainValidationParameters
{
    Windows::Security::Cryptography::Certificates::CertificateChainPolicy CertificateChainPolicy() const;
    void CertificateChainPolicy(Windows::Security::Cryptography::Certificates::CertificateChainPolicy value) const;
    Windows::Networking::HostName ServerDnsName() const;
    void ServerDnsName(const Windows::Networking::HostName & value) const;
};

template <typename D>
struct WINRT_EBO impl_ICmsAttachedSignature
{
    Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> Certificates() const;
    com_array<uint8_t> Content() const;
    Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::CmsSignerInfo> Signers() const;
    Windows::Security::Cryptography::Certificates::SignatureValidationResult VerifySignature() const;
};

template <typename D>
struct WINRT_EBO impl_ICmsAttachedSignatureFactory
{
    Windows::Security::Cryptography::Certificates::CmsAttachedSignature CreateCmsAttachedSignature(const Windows::Storage::Streams::IBuffer & inputBlob) const;
};

template <typename D>
struct WINRT_EBO impl_ICmsAttachedSignatureStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> GenerateSignatureAsync(const Windows::Storage::Streams::IBuffer & data, iterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo> signers, iterable<Windows::Security::Cryptography::Certificates::Certificate> certificates) const;
};

template <typename D>
struct WINRT_EBO impl_ICmsDetachedSignature
{
    Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> Certificates() const;
    Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::CmsSignerInfo> Signers() const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Cryptography::Certificates::SignatureValidationResult> VerifySignatureAsync(const Windows::Storage::Streams::IInputStream & data) const;
};

template <typename D>
struct WINRT_EBO impl_ICmsDetachedSignatureFactory
{
    Windows::Security::Cryptography::Certificates::CmsDetachedSignature CreateCmsDetachedSignature(const Windows::Storage::Streams::IBuffer & inputBlob) const;
};

template <typename D>
struct WINRT_EBO impl_ICmsDetachedSignatureStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> GenerateSignatureAsync(const Windows::Storage::Streams::IInputStream & data, iterable<Windows::Security::Cryptography::Certificates::CmsSignerInfo> signers, iterable<Windows::Security::Cryptography::Certificates::Certificate> certificates) const;
};

template <typename D>
struct WINRT_EBO impl_ICmsSignerInfo
{
    Windows::Security::Cryptography::Certificates::Certificate Certificate() const;
    void Certificate(const Windows::Security::Cryptography::Certificates::Certificate & value) const;
    hstring HashAlgorithmName() const;
    void HashAlgorithmName(hstring_view value) const;
    Windows::Security::Cryptography::Certificates::CmsTimestampInfo TimestampInfo() const;
};

template <typename D>
struct WINRT_EBO impl_ICmsTimestampInfo
{
    Windows::Security::Cryptography::Certificates::Certificate SigningCertificate() const;
    Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> Certificates() const;
    Windows::Foundation::DateTime Timestamp() const;
};

template <typename D>
struct WINRT_EBO impl_IKeyAlgorithmNamesStatics
{
    hstring Rsa() const;
    hstring Dsa() const;
    hstring Ecdh256() const;
    hstring Ecdh384() const;
    hstring Ecdh521() const;
    hstring Ecdsa256() const;
    hstring Ecdsa384() const;
    hstring Ecdsa521() const;
};

template <typename D>
struct WINRT_EBO impl_IKeyAlgorithmNamesStatics2
{
    hstring Ecdsa() const;
    hstring Ecdh() const;
};

template <typename D>
struct WINRT_EBO impl_IKeyAttestationHelperStatics
{
    Windows::Foundation::IAsyncOperation<hstring> DecryptTpmAttestationCredentialAsync(hstring_view credential) const;
    hstring GetTpmAttestationCredentialId(hstring_view credential) const;
};

template <typename D>
struct WINRT_EBO impl_IKeyAttestationHelperStatics2
{
    Windows::Foundation::IAsyncOperation<hstring> DecryptTpmAttestationCredentialAsync(hstring_view credential, hstring_view containerName) const;
};

template <typename D>
struct WINRT_EBO impl_IKeyStorageProviderNamesStatics
{
    hstring SoftwareKeyStorageProvider() const;
    hstring SmartcardKeyStorageProvider() const;
    hstring PlatformKeyStorageProvider() const;
};

template <typename D>
struct WINRT_EBO impl_IKeyStorageProviderNamesStatics2
{
    hstring PassportKeyStorageProvider() const;
};

template <typename D>
struct WINRT_EBO impl_IPfxImportParameters
{
    Windows::Security::Cryptography::Certificates::ExportOption Exportable() const;
    void Exportable(Windows::Security::Cryptography::Certificates::ExportOption value) const;
    Windows::Security::Cryptography::Certificates::KeyProtectionLevel KeyProtectionLevel() const;
    void KeyProtectionLevel(Windows::Security::Cryptography::Certificates::KeyProtectionLevel value) const;
    Windows::Security::Cryptography::Certificates::InstallOptions InstallOptions() const;
    void InstallOptions(Windows::Security::Cryptography::Certificates::InstallOptions value) const;
    hstring FriendlyName() const;
    void FriendlyName(hstring_view value) const;
    hstring KeyStorageProviderName() const;
    void KeyStorageProviderName(hstring_view value) const;
    hstring ContainerNamePrefix() const;
    void ContainerNamePrefix(hstring_view value) const;
    hstring ReaderName() const;
    void ReaderName(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IStandardCertificateStoreNamesStatics
{
    hstring Personal() const;
    hstring TrustedRootCertificationAuthorities() const;
    hstring IntermediateCertificationAuthorities() const;
};

template <typename D>
struct WINRT_EBO impl_ISubjectAlternativeNameInfo
{
    Windows::Foundation::Collections::IVectorView<hstring> EmailName() const;
    Windows::Foundation::Collections::IVectorView<hstring> IPAddress() const;
    Windows::Foundation::Collections::IVectorView<hstring> Url() const;
    Windows::Foundation::Collections::IVectorView<hstring> DnsName() const;
    Windows::Foundation::Collections::IVectorView<hstring> DistinguishedName() const;
    Windows::Foundation::Collections::IVectorView<hstring> PrincipalName() const;
};

template <typename D>
struct WINRT_EBO impl_IUserCertificateEnrollmentManager
{
    Windows::Foundation::IAsyncOperation<hstring> CreateRequestAsync(const Windows::Security::Cryptography::Certificates::CertificateRequestProperties & request) const;
    Windows::Foundation::IAsyncAction InstallCertificateAsync(hstring_view certificate, Windows::Security::Cryptography::Certificates::InstallOptions installOption) const;
    Windows::Foundation::IAsyncAction ImportPfxDataAsync(hstring_view pfxData, hstring_view password, Windows::Security::Cryptography::Certificates::ExportOption exportable, Windows::Security::Cryptography::Certificates::KeyProtectionLevel keyProtectionLevel, Windows::Security::Cryptography::Certificates::InstallOptions installOption, hstring_view friendlyName) const;
    Windows::Foundation::IAsyncAction ImportPfxDataAsync(hstring_view pfxData, hstring_view password, Windows::Security::Cryptography::Certificates::ExportOption exportable, Windows::Security::Cryptography::Certificates::KeyProtectionLevel keyProtectionLevel, Windows::Security::Cryptography::Certificates::InstallOptions installOption, hstring_view friendlyName, hstring_view keyStorageProvider) const;
};

template <typename D>
struct WINRT_EBO impl_IUserCertificateEnrollmentManager2
{
    Windows::Foundation::IAsyncAction ImportPfxDataAsync(hstring_view pfxData, hstring_view password, const Windows::Security::Cryptography::Certificates::PfxImportParameters & pfxImportParameters) const;
};

template <typename D>
struct WINRT_EBO impl_IUserCertificateStore
{
    Windows::Foundation::IAsyncOperation<bool> RequestAddAsync(const Windows::Security::Cryptography::Certificates::Certificate & certificate) const;
    Windows::Foundation::IAsyncOperation<bool> RequestDeleteAsync(const Windows::Security::Cryptography::Certificates::Certificate & certificate) const;
    hstring Name() const;
};

}

namespace impl {

template <> struct traits<Windows::Security::Cryptography::Certificates::ICertificate>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::ICertificate;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_ICertificate<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::ICertificate2>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::ICertificate2;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_ICertificate2<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::ICertificate3>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::ICertificate3;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_ICertificate3<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::ICertificateChain>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::ICertificateChain;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_ICertificateChain<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_ICertificateEnrollmentManagerStatics<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics2>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics2;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_ICertificateEnrollmentManagerStatics2<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics3>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::ICertificateEnrollmentManagerStatics3;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_ICertificateEnrollmentManagerStatics3<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::ICertificateFactory>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::ICertificateFactory;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_ICertificateFactory<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::ICertificateKeyUsages>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::ICertificateKeyUsages;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_ICertificateKeyUsages<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::ICertificateQuery>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::ICertificateQuery;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_ICertificateQuery<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::ICertificateQuery2>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::ICertificateQuery2;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_ICertificateQuery2<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::ICertificateRequestProperties>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_ICertificateRequestProperties<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::ICertificateRequestProperties2>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties2;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_ICertificateRequestProperties2<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::ICertificateRequestProperties3>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::ICertificateRequestProperties3;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_ICertificateRequestProperties3<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::ICertificateStore>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::ICertificateStore;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_ICertificateStore<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::ICertificateStore2>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::ICertificateStore2;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_ICertificateStore2<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::ICertificateStoresStatics>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::ICertificateStoresStatics;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_ICertificateStoresStatics<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::ICertificateStoresStatics2>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::ICertificateStoresStatics2;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_ICertificateStoresStatics2<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::IChainBuildingParameters>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::IChainBuildingParameters;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_IChainBuildingParameters<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::IChainValidationParameters>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::IChainValidationParameters;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_IChainValidationParameters<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::ICmsAttachedSignature>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::ICmsAttachedSignature;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_ICmsAttachedSignature<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureFactory>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureFactory;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_ICmsAttachedSignatureFactory<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureStatics>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::ICmsAttachedSignatureStatics;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_ICmsAttachedSignatureStatics<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::ICmsDetachedSignature>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::ICmsDetachedSignature;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_ICmsDetachedSignature<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureFactory>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureFactory;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_ICmsDetachedSignatureFactory<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureStatics>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::ICmsDetachedSignatureStatics;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_ICmsDetachedSignatureStatics<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::ICmsSignerInfo>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::ICmsSignerInfo;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_ICmsSignerInfo<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::ICmsTimestampInfo>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::ICmsTimestampInfo;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_ICmsTimestampInfo<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_IKeyAlgorithmNamesStatics<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics2>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::IKeyAlgorithmNamesStatics2;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_IKeyAlgorithmNamesStatics2<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_IKeyAttestationHelperStatics<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics2>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::IKeyAttestationHelperStatics2;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_IKeyAttestationHelperStatics2<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_IKeyStorageProviderNamesStatics<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics2>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::IKeyStorageProviderNamesStatics2;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_IKeyStorageProviderNamesStatics2<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::IPfxImportParameters>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::IPfxImportParameters;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_IPfxImportParameters<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::IStandardCertificateStoreNamesStatics>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::IStandardCertificateStoreNamesStatics;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_IStandardCertificateStoreNamesStatics<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::ISubjectAlternativeNameInfo;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_ISubjectAlternativeNameInfo<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_IUserCertificateEnrollmentManager<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager2>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::IUserCertificateEnrollmentManager2;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_IUserCertificateEnrollmentManager2<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::IUserCertificateStore>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::IUserCertificateStore;
    template <typename D> using consume = Windows::Security::Cryptography::Certificates::impl_IUserCertificateStore<D>;
};

template <> struct traits<Windows::Security::Cryptography::Certificates::Certificate>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::Certificate;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Cryptography.Certificates.Certificate"; }
};

template <> struct traits<Windows::Security::Cryptography::Certificates::CertificateChain>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::CertificateChain;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Cryptography.Certificates.CertificateChain"; }
};

template <> struct traits<Windows::Security::Cryptography::Certificates::CertificateEnrollmentManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Cryptography.Certificates.CertificateEnrollmentManager"; }
};

template <> struct traits<Windows::Security::Cryptography::Certificates::CertificateKeyUsages>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::CertificateKeyUsages;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Cryptography.Certificates.CertificateKeyUsages"; }
};

template <> struct traits<Windows::Security::Cryptography::Certificates::CertificateQuery>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::CertificateQuery;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Cryptography.Certificates.CertificateQuery"; }
};

template <> struct traits<Windows::Security::Cryptography::Certificates::CertificateRequestProperties>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::CertificateRequestProperties;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Cryptography.Certificates.CertificateRequestProperties"; }
};

template <> struct traits<Windows::Security::Cryptography::Certificates::CertificateStore>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::CertificateStore;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Cryptography.Certificates.CertificateStore"; }
};

template <> struct traits<Windows::Security::Cryptography::Certificates::CertificateStores>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Cryptography.Certificates.CertificateStores"; }
};

template <> struct traits<Windows::Security::Cryptography::Certificates::ChainBuildingParameters>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::ChainBuildingParameters;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Cryptography.Certificates.ChainBuildingParameters"; }
};

template <> struct traits<Windows::Security::Cryptography::Certificates::ChainValidationParameters>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::ChainValidationParameters;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Cryptography.Certificates.ChainValidationParameters"; }
};

template <> struct traits<Windows::Security::Cryptography::Certificates::CmsAttachedSignature>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::CmsAttachedSignature;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Cryptography.Certificates.CmsAttachedSignature"; }
};

template <> struct traits<Windows::Security::Cryptography::Certificates::CmsDetachedSignature>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::CmsDetachedSignature;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Cryptography.Certificates.CmsDetachedSignature"; }
};

template <> struct traits<Windows::Security::Cryptography::Certificates::CmsSignerInfo>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::CmsSignerInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Cryptography.Certificates.CmsSignerInfo"; }
};

template <> struct traits<Windows::Security::Cryptography::Certificates::CmsTimestampInfo>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::CmsTimestampInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Cryptography.Certificates.CmsTimestampInfo"; }
};

template <> struct traits<Windows::Security::Cryptography::Certificates::KeyAlgorithmNames>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Cryptography.Certificates.KeyAlgorithmNames"; }
};

template <> struct traits<Windows::Security::Cryptography::Certificates::KeyAttestationHelper>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Cryptography.Certificates.KeyAttestationHelper"; }
};

template <> struct traits<Windows::Security::Cryptography::Certificates::KeyStorageProviderNames>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Cryptography.Certificates.KeyStorageProviderNames"; }
};

template <> struct traits<Windows::Security::Cryptography::Certificates::PfxImportParameters>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::PfxImportParameters;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Cryptography.Certificates.PfxImportParameters"; }
};

template <> struct traits<Windows::Security::Cryptography::Certificates::StandardCertificateStoreNames>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Cryptography.Certificates.StandardCertificateStoreNames"; }
};

template <> struct traits<Windows::Security::Cryptography::Certificates::SubjectAlternativeNameInfo>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::SubjectAlternativeNameInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Cryptography.Certificates.SubjectAlternativeNameInfo"; }
};

template <> struct traits<Windows::Security::Cryptography::Certificates::UserCertificateEnrollmentManager>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::UserCertificateEnrollmentManager;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Cryptography.Certificates.UserCertificateEnrollmentManager"; }
};

template <> struct traits<Windows::Security::Cryptography::Certificates::UserCertificateStore>
{
    using abi = ABI::Windows::Security::Cryptography::Certificates::UserCertificateStore;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Cryptography.Certificates.UserCertificateStore"; }
};

}

}
