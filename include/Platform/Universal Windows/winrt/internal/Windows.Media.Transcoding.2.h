// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Media.Transcoding.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_f5f07c13_3047_5bab_8eb7_6e5d7d14afae
#define WINRT_GENERIC_f5f07c13_3047_5bab_8eb7_6e5d7d14afae
template <> struct __declspec(uuid("f5f07c13-3047-5bab-8eb7-6e5d7d14afae")) __declspec(novtable) IAsyncOperation<Windows::Media::Transcoding::PrepareTranscodeResult> : impl_IAsyncOperation<Windows::Media::Transcoding::PrepareTranscodeResult> {};
#endif

#ifndef WINRT_GENERIC_4f1430a6_a825_56ca_b047_1a9bad52ba67
#define WINRT_GENERIC_4f1430a6_a825_56ca_b047_1a9bad52ba67
template <> struct __declspec(uuid("4f1430a6-a825-56ca-b047-1a9bad52ba67")) __declspec(novtable) IAsyncActionWithProgress<double> : impl_IAsyncActionWithProgress<double> {};
#endif

#ifndef WINRT_GENERIC_a44d7d07_8f74_52ee_9f02_c2b244b4ff2a
#define WINRT_GENERIC_a44d7d07_8f74_52ee_9f02_c2b244b4ff2a
template <> struct __declspec(uuid("a44d7d07-8f74-52ee-9f02-c2b244b4ff2a")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Media::Transcoding::PrepareTranscodeResult> : impl_AsyncOperationCompletedHandler<Windows::Media::Transcoding::PrepareTranscodeResult> {};
#endif

#ifndef WINRT_GENERIC_44825c7c_0da9_5691_b2b4_914f231eeced
#define WINRT_GENERIC_44825c7c_0da9_5691_b2b4_914f231eeced
template <> struct __declspec(uuid("44825c7c-0da9-5691-b2b4-914f231eeced")) __declspec(novtable) AsyncActionProgressHandler<double> : impl_AsyncActionProgressHandler<double> {};
#endif

#ifndef WINRT_GENERIC_94d64ac6_4491_53ef_8be8_36481f3ff1e8
#define WINRT_GENERIC_94d64ac6_4491_53ef_8be8_36481f3ff1e8
template <> struct __declspec(uuid("94d64ac6-4491-53ef-8be8-36481f3ff1e8")) __declspec(novtable) AsyncActionWithProgressCompletedHandler<double> : impl_AsyncActionWithProgressCompletedHandler<double> {};
#endif


}

namespace Windows::Media::Transcoding {

struct IMediaTranscoder :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaTranscoder>
{
    IMediaTranscoder(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaTranscoder2 :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaTranscoder2>
{
    IMediaTranscoder2(std::nullptr_t = nullptr) noexcept {}
};

struct IPrepareTranscodeResult :
    Windows::Foundation::IInspectable,
    impl::consume<IPrepareTranscodeResult>
{
    IPrepareTranscodeResult(std::nullptr_t = nullptr) noexcept {}
};

}

}
