// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Security.Credentials.UI.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_83fd09a4_21fd_5c01_9cf6_8293b2929a9f
#define WINRT_GENERIC_83fd09a4_21fd_5c01_9cf6_8293b2929a9f
template <> struct __declspec(uuid("83fd09a4-21fd-5c01-9cf6-8293b2929a9f")) __declspec(novtable) IAsyncOperation<Windows::Security::Credentials::UI::CredentialPickerResults> : impl_IAsyncOperation<Windows::Security::Credentials::UI::CredentialPickerResults> {};
#endif

#ifndef WINRT_GENERIC_ddd384f3_d818_5d83_ab4b_32119c28587c
#define WINRT_GENERIC_ddd384f3_d818_5d83_ab4b_32119c28587c
template <> struct __declspec(uuid("ddd384f3-d818-5d83-ab4b-32119c28587c")) __declspec(novtable) IAsyncOperation<winrt::Windows::Security::Credentials::UI::UserConsentVerifierAvailability> : impl_IAsyncOperation<winrt::Windows::Security::Credentials::UI::UserConsentVerifierAvailability> {};
#endif

#ifndef WINRT_GENERIC_fd596ffd_2318_558f_9dbe_d21df43764a5
#define WINRT_GENERIC_fd596ffd_2318_558f_9dbe_d21df43764a5
template <> struct __declspec(uuid("fd596ffd-2318-558f-9dbe-d21df43764a5")) __declspec(novtable) IAsyncOperation<winrt::Windows::Security::Credentials::UI::UserConsentVerificationResult> : impl_IAsyncOperation<winrt::Windows::Security::Credentials::UI::UserConsentVerificationResult> {};
#endif

#ifndef WINRT_GENERIC_091a96b8_52a6_523a_8c94_7f9c11c6dae5
#define WINRT_GENERIC_091a96b8_52a6_523a_8c94_7f9c11c6dae5
template <> struct __declspec(uuid("091a96b8-52a6-523a-8c94-7f9c11c6dae5")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Security::Credentials::UI::CredentialPickerResults> : impl_AsyncOperationCompletedHandler<Windows::Security::Credentials::UI::CredentialPickerResults> {};
#endif

#ifndef WINRT_GENERIC_28988174_ace2_5c15_a0df_580a26d94294
#define WINRT_GENERIC_28988174_ace2_5c15_a0df_580a26d94294
template <> struct __declspec(uuid("28988174-ace2-5c15-a0df-580a26d94294")) __declspec(novtable) AsyncOperationCompletedHandler<winrt::Windows::Security::Credentials::UI::UserConsentVerifierAvailability> : impl_AsyncOperationCompletedHandler<winrt::Windows::Security::Credentials::UI::UserConsentVerifierAvailability> {};
#endif

#ifndef WINRT_GENERIC_0cffc6c9_4c2b_5cd4_b38c_7b8df3ff5afb
#define WINRT_GENERIC_0cffc6c9_4c2b_5cd4_b38c_7b8df3ff5afb
template <> struct __declspec(uuid("0cffc6c9-4c2b-5cd4-b38c-7b8df3ff5afb")) __declspec(novtable) AsyncOperationCompletedHandler<winrt::Windows::Security::Credentials::UI::UserConsentVerificationResult> : impl_AsyncOperationCompletedHandler<winrt::Windows::Security::Credentials::UI::UserConsentVerificationResult> {};
#endif


}

namespace Windows::Security::Credentials::UI {

struct ICredentialPickerOptions :
    Windows::Foundation::IInspectable,
    impl::consume<ICredentialPickerOptions>
{
    ICredentialPickerOptions(std::nullptr_t = nullptr) noexcept {}
};

struct ICredentialPickerResults :
    Windows::Foundation::IInspectable,
    impl::consume<ICredentialPickerResults>
{
    ICredentialPickerResults(std::nullptr_t = nullptr) noexcept {}
};

struct ICredentialPickerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ICredentialPickerStatics>
{
    ICredentialPickerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IUserConsentVerifierStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IUserConsentVerifierStatics>
{
    IUserConsentVerifierStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
