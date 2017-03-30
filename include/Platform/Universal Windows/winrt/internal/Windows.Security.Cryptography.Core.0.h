// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Security::Cryptography::Core {

struct IAsymmetricAlgorithmNamesStatics;
struct IAsymmetricAlgorithmNamesStatics2;
struct IAsymmetricKeyAlgorithmProvider;
struct IAsymmetricKeyAlgorithmProvider2;
struct IAsymmetricKeyAlgorithmProviderStatics;
struct ICryptographicEngineStatics;
struct ICryptographicEngineStatics2;
struct ICryptographicKey;
struct IEccCurveNamesStatics;
struct IEncryptedAndAuthenticatedData;
struct IHashAlgorithmNamesStatics;
struct IHashAlgorithmProvider;
struct IHashAlgorithmProviderStatics;
struct IHashComputation;
struct IKeyDerivationAlgorithmNamesStatics;
struct IKeyDerivationAlgorithmNamesStatics2;
struct IKeyDerivationAlgorithmProvider;
struct IKeyDerivationAlgorithmProviderStatics;
struct IKeyDerivationParameters;
struct IKeyDerivationParameters2;
struct IKeyDerivationParametersStatics;
struct IKeyDerivationParametersStatics2;
struct IMacAlgorithmNamesStatics;
struct IMacAlgorithmProvider;
struct IMacAlgorithmProvider2;
struct IMacAlgorithmProviderStatics;
struct IPersistedKeyProviderStatics;
struct ISymmetricAlgorithmNamesStatics;
struct ISymmetricKeyAlgorithmProvider;
struct ISymmetricKeyAlgorithmProviderStatics;
struct AsymmetricKeyAlgorithmProvider;
struct CryptographicHash;
struct CryptographicKey;
struct EncryptedAndAuthenticatedData;
struct HashAlgorithmProvider;
struct KeyDerivationAlgorithmProvider;
struct KeyDerivationParameters;
struct MacAlgorithmProvider;
struct SymmetricKeyAlgorithmProvider;

}

namespace Windows::Security::Cryptography::Core {

struct IAsymmetricAlgorithmNamesStatics;
struct IAsymmetricAlgorithmNamesStatics2;
struct IAsymmetricKeyAlgorithmProvider;
struct IAsymmetricKeyAlgorithmProvider2;
struct IAsymmetricKeyAlgorithmProviderStatics;
struct ICryptographicEngineStatics;
struct ICryptographicEngineStatics2;
struct ICryptographicKey;
struct IEccCurveNamesStatics;
struct IEncryptedAndAuthenticatedData;
struct IHashAlgorithmNamesStatics;
struct IHashAlgorithmProvider;
struct IHashAlgorithmProviderStatics;
struct IHashComputation;
struct IKeyDerivationAlgorithmNamesStatics;
struct IKeyDerivationAlgorithmNamesStatics2;
struct IKeyDerivationAlgorithmProvider;
struct IKeyDerivationAlgorithmProviderStatics;
struct IKeyDerivationParameters;
struct IKeyDerivationParameters2;
struct IKeyDerivationParametersStatics;
struct IKeyDerivationParametersStatics2;
struct IMacAlgorithmNamesStatics;
struct IMacAlgorithmProvider;
struct IMacAlgorithmProvider2;
struct IMacAlgorithmProviderStatics;
struct IPersistedKeyProviderStatics;
struct ISymmetricAlgorithmNamesStatics;
struct ISymmetricKeyAlgorithmProvider;
struct ISymmetricKeyAlgorithmProviderStatics;
struct AsymmetricAlgorithmNames;
struct AsymmetricKeyAlgorithmProvider;
struct CryptographicEngine;
struct CryptographicHash;
struct CryptographicKey;
struct EccCurveNames;
struct EncryptedAndAuthenticatedData;
struct HashAlgorithmNames;
struct HashAlgorithmProvider;
struct KeyDerivationAlgorithmNames;
struct KeyDerivationAlgorithmProvider;
struct KeyDerivationParameters;
struct MacAlgorithmNames;
struct MacAlgorithmProvider;
struct PersistedKeyProvider;
struct SymmetricAlgorithmNames;
struct SymmetricKeyAlgorithmProvider;

}

namespace Windows::Security::Cryptography::Core {

template <typename T> struct impl_IAsymmetricAlgorithmNamesStatics;
template <typename T> struct impl_IAsymmetricAlgorithmNamesStatics2;
template <typename T> struct impl_IAsymmetricKeyAlgorithmProvider;
template <typename T> struct impl_IAsymmetricKeyAlgorithmProvider2;
template <typename T> struct impl_IAsymmetricKeyAlgorithmProviderStatics;
template <typename T> struct impl_ICryptographicEngineStatics;
template <typename T> struct impl_ICryptographicEngineStatics2;
template <typename T> struct impl_ICryptographicKey;
template <typename T> struct impl_IEccCurveNamesStatics;
template <typename T> struct impl_IEncryptedAndAuthenticatedData;
template <typename T> struct impl_IHashAlgorithmNamesStatics;
template <typename T> struct impl_IHashAlgorithmProvider;
template <typename T> struct impl_IHashAlgorithmProviderStatics;
template <typename T> struct impl_IHashComputation;
template <typename T> struct impl_IKeyDerivationAlgorithmNamesStatics;
template <typename T> struct impl_IKeyDerivationAlgorithmNamesStatics2;
template <typename T> struct impl_IKeyDerivationAlgorithmProvider;
template <typename T> struct impl_IKeyDerivationAlgorithmProviderStatics;
template <typename T> struct impl_IKeyDerivationParameters;
template <typename T> struct impl_IKeyDerivationParameters2;
template <typename T> struct impl_IKeyDerivationParametersStatics;
template <typename T> struct impl_IKeyDerivationParametersStatics2;
template <typename T> struct impl_IMacAlgorithmNamesStatics;
template <typename T> struct impl_IMacAlgorithmProvider;
template <typename T> struct impl_IMacAlgorithmProvider2;
template <typename T> struct impl_IMacAlgorithmProviderStatics;
template <typename T> struct impl_IPersistedKeyProviderStatics;
template <typename T> struct impl_ISymmetricAlgorithmNamesStatics;
template <typename T> struct impl_ISymmetricKeyAlgorithmProvider;
template <typename T> struct impl_ISymmetricKeyAlgorithmProviderStatics;

}

namespace Windows::Security::Cryptography::Core {

enum class Capi1KdfTargetAlgorithm
{
    NotAes = 0,
    Aes = 1,
};

enum class CryptographicPadding
{
    None = 0,
    RsaOaep = 1,
    RsaPkcs1V15 = 2,
    RsaPss = 3,
};

enum class CryptographicPrivateKeyBlobType
{
    Pkcs8RawPrivateKeyInfo = 0,
    Pkcs1RsaPrivateKey = 1,
    BCryptPrivateKey = 2,
    Capi1PrivateKey = 3,
    BCryptEccFullPrivateKey = 4,
};

enum class CryptographicPublicKeyBlobType
{
    X509SubjectPublicKeyInfo = 0,
    Pkcs1RsaPublicKey = 1,
    BCryptPublicKey = 2,
    Capi1PublicKey = 3,
    BCryptEccFullPublicKey = 4,
};

}

}
