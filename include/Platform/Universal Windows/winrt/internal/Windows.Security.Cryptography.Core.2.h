// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Security.Cryptography.Core.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
#define WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
template <> struct __declspec(uuid("2f13c006-a03a-5f69-b090-75a43e33423e")) __declspec(novtable) IVectorView<hstring> : impl_IVectorView<hstring> {};
#endif

#ifndef WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
#define WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
template <> struct __declspec(uuid("e2fcc7c1-3bfc-5a0b-b2b0-72e769d1cb7e")) __declspec(novtable) IIterable<hstring> : impl_IIterable<hstring> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_3bee8834_b9a7_5a80_a746_5ef097227878
#define WINRT_GENERIC_3bee8834_b9a7_5a80_a746_5ef097227878
template <> struct __declspec(uuid("3bee8834-b9a7-5a80-a746-5ef097227878")) __declspec(novtable) IAsyncOperation<Windows::Storage::Streams::IBuffer> : impl_IAsyncOperation<Windows::Storage::Streams::IBuffer> {};
#endif

#ifndef WINRT_GENERIC_81ca789b_98df_5c6a_9531_966238e3e7ae
#define WINRT_GENERIC_81ca789b_98df_5c6a_9531_966238e3e7ae
template <> struct __declspec(uuid("81ca789b-98df-5c6a-9531-966238e3e7ae")) __declspec(novtable) IAsyncOperation<Windows::Security::Cryptography::Core::CryptographicKey> : impl_IAsyncOperation<Windows::Security::Cryptography::Core::CryptographicKey> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
#define WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
template <> struct __declspec(uuid("8c304ebb-6615-50a4-8829-879ecd443236")) __declspec(novtable) IIterator<hstring> : impl_IIterator<hstring> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_51c3d2fd_b8a1_5620_b746_7ee6d533aca3
#define WINRT_GENERIC_51c3d2fd_b8a1_5620_b746_7ee6d533aca3
template <> struct __declspec(uuid("51c3d2fd-b8a1-5620-b746-7ee6d533aca3")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Storage::Streams::IBuffer> : impl_AsyncOperationCompletedHandler<Windows::Storage::Streams::IBuffer> {};
#endif

#ifndef WINRT_GENERIC_04ca4378_f594_5de6_a555_304f62cb4faf
#define WINRT_GENERIC_04ca4378_f594_5de6_a555_304f62cb4faf
template <> struct __declspec(uuid("04ca4378-f594-5de6-a555-304f62cb4faf")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Security::Cryptography::Core::CryptographicKey> : impl_AsyncOperationCompletedHandler<Windows::Security::Cryptography::Core::CryptographicKey> {};
#endif


}

namespace Windows::Security::Cryptography::Core {

struct IAsymmetricAlgorithmNamesStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IAsymmetricAlgorithmNamesStatics>
{
    IAsymmetricAlgorithmNamesStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IAsymmetricAlgorithmNamesStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IAsymmetricAlgorithmNamesStatics2>
{
    IAsymmetricAlgorithmNamesStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct IAsymmetricKeyAlgorithmProvider :
    Windows::Foundation::IInspectable,
    impl::consume<IAsymmetricKeyAlgorithmProvider>
{
    IAsymmetricKeyAlgorithmProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IAsymmetricKeyAlgorithmProvider2 :
    Windows::Foundation::IInspectable,
    impl::consume<IAsymmetricKeyAlgorithmProvider2>
{
    IAsymmetricKeyAlgorithmProvider2(std::nullptr_t = nullptr) noexcept {}
};

struct IAsymmetricKeyAlgorithmProviderStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IAsymmetricKeyAlgorithmProviderStatics>
{
    IAsymmetricKeyAlgorithmProviderStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ICryptographicEngineStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ICryptographicEngineStatics>
{
    ICryptographicEngineStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ICryptographicEngineStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<ICryptographicEngineStatics2>
{
    ICryptographicEngineStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct ICryptographicKey :
    Windows::Foundation::IInspectable,
    impl::consume<ICryptographicKey>
{
    ICryptographicKey(std::nullptr_t = nullptr) noexcept {}
};

struct IEccCurveNamesStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IEccCurveNamesStatics>
{
    IEccCurveNamesStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IEncryptedAndAuthenticatedData :
    Windows::Foundation::IInspectable,
    impl::consume<IEncryptedAndAuthenticatedData>
{
    IEncryptedAndAuthenticatedData(std::nullptr_t = nullptr) noexcept {}
};

struct IHashAlgorithmNamesStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IHashAlgorithmNamesStatics>
{
    IHashAlgorithmNamesStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IHashAlgorithmProvider :
    Windows::Foundation::IInspectable,
    impl::consume<IHashAlgorithmProvider>
{
    IHashAlgorithmProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IHashAlgorithmProviderStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IHashAlgorithmProviderStatics>
{
    IHashAlgorithmProviderStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IHashComputation :
    Windows::Foundation::IInspectable,
    impl::consume<IHashComputation>
{
    IHashComputation(std::nullptr_t = nullptr) noexcept {}
};

struct IKeyDerivationAlgorithmNamesStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IKeyDerivationAlgorithmNamesStatics>
{
    IKeyDerivationAlgorithmNamesStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IKeyDerivationAlgorithmNamesStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IKeyDerivationAlgorithmNamesStatics2>
{
    IKeyDerivationAlgorithmNamesStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct IKeyDerivationAlgorithmProvider :
    Windows::Foundation::IInspectable,
    impl::consume<IKeyDerivationAlgorithmProvider>
{
    IKeyDerivationAlgorithmProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IKeyDerivationAlgorithmProviderStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IKeyDerivationAlgorithmProviderStatics>
{
    IKeyDerivationAlgorithmProviderStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IKeyDerivationParameters :
    Windows::Foundation::IInspectable,
    impl::consume<IKeyDerivationParameters>
{
    IKeyDerivationParameters(std::nullptr_t = nullptr) noexcept {}
};

struct IKeyDerivationParameters2 :
    Windows::Foundation::IInspectable,
    impl::consume<IKeyDerivationParameters2>
{
    IKeyDerivationParameters2(std::nullptr_t = nullptr) noexcept {}
};

struct IKeyDerivationParametersStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IKeyDerivationParametersStatics>
{
    IKeyDerivationParametersStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IKeyDerivationParametersStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IKeyDerivationParametersStatics2>
{
    IKeyDerivationParametersStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct IMacAlgorithmNamesStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IMacAlgorithmNamesStatics>
{
    IMacAlgorithmNamesStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IMacAlgorithmProvider :
    Windows::Foundation::IInspectable,
    impl::consume<IMacAlgorithmProvider>
{
    IMacAlgorithmProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IMacAlgorithmProvider2 :
    Windows::Foundation::IInspectable,
    impl::consume<IMacAlgorithmProvider2>
{
    IMacAlgorithmProvider2(std::nullptr_t = nullptr) noexcept {}
};

struct IMacAlgorithmProviderStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IMacAlgorithmProviderStatics>
{
    IMacAlgorithmProviderStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IPersistedKeyProviderStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IPersistedKeyProviderStatics>
{
    IPersistedKeyProviderStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ISymmetricAlgorithmNamesStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ISymmetricAlgorithmNamesStatics>
{
    ISymmetricAlgorithmNamesStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ISymmetricKeyAlgorithmProvider :
    Windows::Foundation::IInspectable,
    impl::consume<ISymmetricKeyAlgorithmProvider>
{
    ISymmetricKeyAlgorithmProvider(std::nullptr_t = nullptr) noexcept {}
};

struct ISymmetricKeyAlgorithmProviderStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ISymmetricKeyAlgorithmProviderStatics>
{
    ISymmetricKeyAlgorithmProviderStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
