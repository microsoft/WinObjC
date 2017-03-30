// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Security.Cryptography.Core.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Security::Cryptography::Core {

struct AsymmetricAlgorithmNames
{
    AsymmetricAlgorithmNames() = delete;
    static hstring RsaPkcs1();
    static hstring RsaOaepSha1();
    static hstring RsaOaepSha256();
    static hstring RsaOaepSha384();
    static hstring RsaOaepSha512();
    static hstring EcdsaP256Sha256();
    static hstring EcdsaP384Sha384();
    static hstring EcdsaP521Sha512();
    static hstring DsaSha1();
    static hstring DsaSha256();
    static hstring RsaSignPkcs1Sha1();
    static hstring RsaSignPkcs1Sha256();
    static hstring RsaSignPkcs1Sha384();
    static hstring RsaSignPkcs1Sha512();
    static hstring RsaSignPssSha1();
    static hstring RsaSignPssSha256();
    static hstring RsaSignPssSha384();
    static hstring RsaSignPssSha512();
    static hstring EcdsaSha256();
    static hstring EcdsaSha384();
    static hstring EcdsaSha512();
};

struct WINRT_EBO AsymmetricKeyAlgorithmProvider :
    Windows::Security::Cryptography::Core::IAsymmetricKeyAlgorithmProvider,
    impl::require<AsymmetricKeyAlgorithmProvider, Windows::Security::Cryptography::Core::IAsymmetricKeyAlgorithmProvider2>
{
    AsymmetricKeyAlgorithmProvider(std::nullptr_t) noexcept {}
    static Windows::Security::Cryptography::Core::AsymmetricKeyAlgorithmProvider OpenAlgorithm(hstring_view algorithm);
};

struct CryptographicEngine
{
    CryptographicEngine() = delete;
    static Windows::Storage::Streams::IBuffer Encrypt(const Windows::Security::Cryptography::Core::CryptographicKey & key, const Windows::Storage::Streams::IBuffer & data, const Windows::Storage::Streams::IBuffer & iv);
    static Windows::Storage::Streams::IBuffer Decrypt(const Windows::Security::Cryptography::Core::CryptographicKey & key, const Windows::Storage::Streams::IBuffer & data, const Windows::Storage::Streams::IBuffer & iv);
    static Windows::Security::Cryptography::Core::EncryptedAndAuthenticatedData EncryptAndAuthenticate(const Windows::Security::Cryptography::Core::CryptographicKey & key, const Windows::Storage::Streams::IBuffer & data, const Windows::Storage::Streams::IBuffer & nonce, const Windows::Storage::Streams::IBuffer & authenticatedData);
    static Windows::Storage::Streams::IBuffer DecryptAndAuthenticate(const Windows::Security::Cryptography::Core::CryptographicKey & key, const Windows::Storage::Streams::IBuffer & data, const Windows::Storage::Streams::IBuffer & nonce, const Windows::Storage::Streams::IBuffer & authenticationTag, const Windows::Storage::Streams::IBuffer & authenticatedData);
    static Windows::Storage::Streams::IBuffer Sign(const Windows::Security::Cryptography::Core::CryptographicKey & key, const Windows::Storage::Streams::IBuffer & data);
    static bool VerifySignature(const Windows::Security::Cryptography::Core::CryptographicKey & key, const Windows::Storage::Streams::IBuffer & data, const Windows::Storage::Streams::IBuffer & signature);
    static Windows::Storage::Streams::IBuffer DeriveKeyMaterial(const Windows::Security::Cryptography::Core::CryptographicKey & key, const Windows::Security::Cryptography::Core::KeyDerivationParameters & parameters, uint32_t desiredKeySize);
    static Windows::Storage::Streams::IBuffer SignHashedData(const Windows::Security::Cryptography::Core::CryptographicKey & key, const Windows::Storage::Streams::IBuffer & data);
    static bool VerifySignatureWithHashInput(const Windows::Security::Cryptography::Core::CryptographicKey & key, const Windows::Storage::Streams::IBuffer & data, const Windows::Storage::Streams::IBuffer & signature);
    static Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> DecryptAsync(const Windows::Security::Cryptography::Core::CryptographicKey & key, const Windows::Storage::Streams::IBuffer & data, const Windows::Storage::Streams::IBuffer & iv);
    static Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> SignAsync(const Windows::Security::Cryptography::Core::CryptographicKey & key, const Windows::Storage::Streams::IBuffer & data);
    static Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> SignHashedDataAsync(const Windows::Security::Cryptography::Core::CryptographicKey & key, const Windows::Storage::Streams::IBuffer & data);
};

struct WINRT_EBO CryptographicHash :
    Windows::Security::Cryptography::Core::IHashComputation
{
    CryptographicHash(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CryptographicKey :
    Windows::Security::Cryptography::Core::ICryptographicKey
{
    CryptographicKey(std::nullptr_t) noexcept {}
};

struct EccCurveNames
{
    EccCurveNames() = delete;
    static hstring BrainpoolP160r1();
    static hstring BrainpoolP160t1();
    static hstring BrainpoolP192r1();
    static hstring BrainpoolP192t1();
    static hstring BrainpoolP224r1();
    static hstring BrainpoolP224t1();
    static hstring BrainpoolP256r1();
    static hstring BrainpoolP256t1();
    static hstring BrainpoolP320r1();
    static hstring BrainpoolP320t1();
    static hstring BrainpoolP384r1();
    static hstring BrainpoolP384t1();
    static hstring BrainpoolP512r1();
    static hstring BrainpoolP512t1();
    static hstring Curve25519();
    static hstring Ec192wapi();
    static hstring NistP192();
    static hstring NistP224();
    static hstring NistP256();
    static hstring NistP384();
    static hstring NistP521();
    static hstring NumsP256t1();
    static hstring NumsP384t1();
    static hstring NumsP512t1();
    static hstring SecP160k1();
    static hstring SecP160r1();
    static hstring SecP160r2();
    static hstring SecP192k1();
    static hstring SecP192r1();
    static hstring SecP224k1();
    static hstring SecP224r1();
    static hstring SecP256k1();
    static hstring SecP256r1();
    static hstring SecP384r1();
    static hstring SecP521r1();
    static hstring Wtls7();
    static hstring Wtls9();
    static hstring Wtls12();
    static hstring X962P192v1();
    static hstring X962P192v2();
    static hstring X962P192v3();
    static hstring X962P239v1();
    static hstring X962P239v2();
    static hstring X962P239v3();
    static hstring X962P256v1();
    static Windows::Foundation::Collections::IVectorView<hstring> AllEccCurveNames();
};

struct WINRT_EBO EncryptedAndAuthenticatedData :
    Windows::Security::Cryptography::Core::IEncryptedAndAuthenticatedData
{
    EncryptedAndAuthenticatedData(std::nullptr_t) noexcept {}
};

struct HashAlgorithmNames
{
    HashAlgorithmNames() = delete;
    static hstring Md5();
    static hstring Sha1();
    static hstring Sha256();
    static hstring Sha384();
    static hstring Sha512();
};

struct WINRT_EBO HashAlgorithmProvider :
    Windows::Security::Cryptography::Core::IHashAlgorithmProvider
{
    HashAlgorithmProvider(std::nullptr_t) noexcept {}
    static Windows::Security::Cryptography::Core::HashAlgorithmProvider OpenAlgorithm(hstring_view algorithm);
};

struct KeyDerivationAlgorithmNames
{
    KeyDerivationAlgorithmNames() = delete;
    static hstring Pbkdf2Md5();
    static hstring Pbkdf2Sha1();
    static hstring Pbkdf2Sha256();
    static hstring Pbkdf2Sha384();
    static hstring Pbkdf2Sha512();
    static hstring Sp800108CtrHmacMd5();
    static hstring Sp800108CtrHmacSha1();
    static hstring Sp800108CtrHmacSha256();
    static hstring Sp800108CtrHmacSha384();
    static hstring Sp800108CtrHmacSha512();
    static hstring Sp80056aConcatMd5();
    static hstring Sp80056aConcatSha1();
    static hstring Sp80056aConcatSha256();
    static hstring Sp80056aConcatSha384();
    static hstring Sp80056aConcatSha512();
    static hstring CapiKdfMd5();
    static hstring CapiKdfSha1();
    static hstring CapiKdfSha256();
    static hstring CapiKdfSha384();
    static hstring CapiKdfSha512();
};

struct WINRT_EBO KeyDerivationAlgorithmProvider :
    Windows::Security::Cryptography::Core::IKeyDerivationAlgorithmProvider
{
    KeyDerivationAlgorithmProvider(std::nullptr_t) noexcept {}
    static Windows::Security::Cryptography::Core::KeyDerivationAlgorithmProvider OpenAlgorithm(hstring_view algorithm);
};

struct WINRT_EBO KeyDerivationParameters :
    Windows::Security::Cryptography::Core::IKeyDerivationParameters,
    impl::require<KeyDerivationParameters, Windows::Security::Cryptography::Core::IKeyDerivationParameters2>
{
    KeyDerivationParameters(std::nullptr_t) noexcept {}
    static Windows::Security::Cryptography::Core::KeyDerivationParameters BuildForPbkdf2(const Windows::Storage::Streams::IBuffer & pbkdf2Salt, uint32_t iterationCount);
    static Windows::Security::Cryptography::Core::KeyDerivationParameters BuildForSP800108(const Windows::Storage::Streams::IBuffer & label, const Windows::Storage::Streams::IBuffer & context);
    static Windows::Security::Cryptography::Core::KeyDerivationParameters BuildForSP80056a(const Windows::Storage::Streams::IBuffer & algorithmId, const Windows::Storage::Streams::IBuffer & partyUInfo, const Windows::Storage::Streams::IBuffer & partyVInfo, const Windows::Storage::Streams::IBuffer & suppPubInfo, const Windows::Storage::Streams::IBuffer & suppPrivInfo);
    static Windows::Security::Cryptography::Core::KeyDerivationParameters BuildForCapi1Kdf(Windows::Security::Cryptography::Core::Capi1KdfTargetAlgorithm capi1KdfTargetAlgorithm);
};

struct MacAlgorithmNames
{
    MacAlgorithmNames() = delete;
    static hstring HmacMd5();
    static hstring HmacSha1();
    static hstring HmacSha256();
    static hstring HmacSha384();
    static hstring HmacSha512();
    static hstring AesCmac();
};

struct WINRT_EBO MacAlgorithmProvider :
    Windows::Security::Cryptography::Core::IMacAlgorithmProvider,
    impl::require<MacAlgorithmProvider, Windows::Security::Cryptography::Core::IMacAlgorithmProvider2>
{
    MacAlgorithmProvider(std::nullptr_t) noexcept {}
    static Windows::Security::Cryptography::Core::MacAlgorithmProvider OpenAlgorithm(hstring_view algorithm);
};

struct PersistedKeyProvider
{
    PersistedKeyProvider() = delete;
    static Windows::Foundation::IAsyncOperation<Windows::Security::Cryptography::Core::CryptographicKey> OpenKeyPairFromCertificateAsync(const Windows::Security::Cryptography::Certificates::Certificate & certificate, hstring_view hashAlgorithmName, Windows::Security::Cryptography::Core::CryptographicPadding padding);
    static Windows::Security::Cryptography::Core::CryptographicKey OpenPublicKeyFromCertificate(const Windows::Security::Cryptography::Certificates::Certificate & certificate, hstring_view hashAlgorithmName, Windows::Security::Cryptography::Core::CryptographicPadding padding);
};

struct SymmetricAlgorithmNames
{
    SymmetricAlgorithmNames() = delete;
    static hstring DesCbc();
    static hstring DesEcb();
    static hstring TripleDesCbc();
    static hstring TripleDesEcb();
    static hstring Rc2Cbc();
    static hstring Rc2Ecb();
    static hstring AesCbc();
    static hstring AesEcb();
    static hstring AesGcm();
    static hstring AesCcm();
    static hstring AesCbcPkcs7();
    static hstring AesEcbPkcs7();
    static hstring DesCbcPkcs7();
    static hstring DesEcbPkcs7();
    static hstring TripleDesCbcPkcs7();
    static hstring TripleDesEcbPkcs7();
    static hstring Rc2CbcPkcs7();
    static hstring Rc2EcbPkcs7();
    static hstring Rc4();
};

struct WINRT_EBO SymmetricKeyAlgorithmProvider :
    Windows::Security::Cryptography::Core::ISymmetricKeyAlgorithmProvider
{
    SymmetricKeyAlgorithmProvider(std::nullptr_t) noexcept {}
    static Windows::Security::Cryptography::Core::SymmetricKeyAlgorithmProvider OpenAlgorithm(hstring_view algorithm);
};

}

}
