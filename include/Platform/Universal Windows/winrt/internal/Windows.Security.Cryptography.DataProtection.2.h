// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Security.Cryptography.DataProtection.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_3bee8834_b9a7_5a80_a746_5ef097227878
#define WINRT_GENERIC_3bee8834_b9a7_5a80_a746_5ef097227878
template <> struct __declspec(uuid("3bee8834-b9a7-5a80-a746-5ef097227878")) __declspec(novtable) IAsyncOperation<Windows::Storage::Streams::IBuffer> : impl_IAsyncOperation<Windows::Storage::Streams::IBuffer> {};
#endif

#ifndef WINRT_GENERIC_51c3d2fd_b8a1_5620_b746_7ee6d533aca3
#define WINRT_GENERIC_51c3d2fd_b8a1_5620_b746_7ee6d533aca3
template <> struct __declspec(uuid("51c3d2fd-b8a1-5620-b746-7ee6d533aca3")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Storage::Streams::IBuffer> : impl_AsyncOperationCompletedHandler<Windows::Storage::Streams::IBuffer> {};
#endif


}

namespace Windows::Security::Cryptography::DataProtection {

struct IDataProtectionProvider :
    Windows::Foundation::IInspectable,
    impl::consume<IDataProtectionProvider>
{
    IDataProtectionProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IDataProtectionProviderFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IDataProtectionProviderFactory>
{
    IDataProtectionProviderFactory(std::nullptr_t = nullptr) noexcept {}
};

}

}
