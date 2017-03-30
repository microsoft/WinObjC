// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Media.Ocr.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_2f2d6c29_5473_5f3e_92e7_96572bb990e2
#define WINRT_GENERIC_2f2d6c29_5473_5f3e_92e7_96572bb990e2
template <> struct __declspec(uuid("2f2d6c29-5473-5f3e-92e7-96572bb990e2")) __declspec(novtable) IReference<double> : impl_IReference<double> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_144b0f3d_2d59_5dd2_b012_908ec3e06435
#define WINRT_GENERIC_144b0f3d_2d59_5dd2_b012_908ec3e06435
template <> struct __declspec(uuid("144b0f3d-2d59-5dd2-b012-908ec3e06435")) __declspec(novtable) IVectorView<Windows::Globalization::Language> : impl_IVectorView<Windows::Globalization::Language> {};
#endif

#ifndef WINRT_GENERIC_805a60c7_df4f_527c_86b2_e29e439a83d2
#define WINRT_GENERIC_805a60c7_df4f_527c_86b2_e29e439a83d2
template <> struct __declspec(uuid("805a60c7-df4f-527c-86b2-e29e439a83d2")) __declspec(novtable) IVectorView<Windows::Media::Ocr::OcrWord> : impl_IVectorView<Windows::Media::Ocr::OcrWord> {};
#endif

#ifndef WINRT_GENERIC_60c76eac_8875_5ddb_a19b_65a3936279ea
#define WINRT_GENERIC_60c76eac_8875_5ddb_a19b_65a3936279ea
template <> struct __declspec(uuid("60c76eac-8875-5ddb-a19b-65a3936279ea")) __declspec(novtable) IVectorView<Windows::Media::Ocr::OcrLine> : impl_IVectorView<Windows::Media::Ocr::OcrLine> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_c7d7118e_ae36_59c0_ac76_7badee711c8b
#define WINRT_GENERIC_c7d7118e_ae36_59c0_ac76_7badee711c8b
template <> struct __declspec(uuid("c7d7118e-ae36-59c0-ac76-7badee711c8b")) __declspec(novtable) IAsyncOperation<Windows::Media::Ocr::OcrResult> : impl_IAsyncOperation<Windows::Media::Ocr::OcrResult> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_48409a10_61b6_5db1_a69d_8abc46ac608a
#define WINRT_GENERIC_48409a10_61b6_5db1_a69d_8abc46ac608a
template <> struct __declspec(uuid("48409a10-61b6-5db1-a69d-8abc46ac608a")) __declspec(novtable) IIterable<Windows::Globalization::Language> : impl_IIterable<Windows::Globalization::Language> {};
#endif

#ifndef WINRT_GENERIC_30e99ae6_f414_5243_8db2_aab38ea3f1f1
#define WINRT_GENERIC_30e99ae6_f414_5243_8db2_aab38ea3f1f1
template <> struct __declspec(uuid("30e99ae6-f414-5243-8db2-aab38ea3f1f1")) __declspec(novtable) IIterator<Windows::Globalization::Language> : impl_IIterator<Windows::Globalization::Language> {};
#endif

#ifndef WINRT_GENERIC_0ed4317a_9964_51c6_acbe_02512a069082
#define WINRT_GENERIC_0ed4317a_9964_51c6_acbe_02512a069082
template <> struct __declspec(uuid("0ed4317a-9964-51c6-acbe-02512a069082")) __declspec(novtable) IIterator<Windows::Media::Ocr::OcrWord> : impl_IIterator<Windows::Media::Ocr::OcrWord> {};
#endif

#ifndef WINRT_GENERIC_a0ce663a_46d0_55e5_928e_251eb67a1e99
#define WINRT_GENERIC_a0ce663a_46d0_55e5_928e_251eb67a1e99
template <> struct __declspec(uuid("a0ce663a-46d0-55e5-928e-251eb67a1e99")) __declspec(novtable) IIterable<Windows::Media::Ocr::OcrWord> : impl_IIterable<Windows::Media::Ocr::OcrWord> {};
#endif

#ifndef WINRT_GENERIC_52ca0f8a_5788_5695_b905_46b8d8171d88
#define WINRT_GENERIC_52ca0f8a_5788_5695_b905_46b8d8171d88
template <> struct __declspec(uuid("52ca0f8a-5788-5695-b905-46b8d8171d88")) __declspec(novtable) IIterator<Windows::Media::Ocr::OcrLine> : impl_IIterator<Windows::Media::Ocr::OcrLine> {};
#endif

#ifndef WINRT_GENERIC_6afa94a2_60d7_5dbe_942d_81aa3929c85e
#define WINRT_GENERIC_6afa94a2_60d7_5dbe_942d_81aa3929c85e
template <> struct __declspec(uuid("6afa94a2-60d7-5dbe-942d-81aa3929c85e")) __declspec(novtable) IIterable<Windows::Media::Ocr::OcrLine> : impl_IIterable<Windows::Media::Ocr::OcrLine> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_989c1371_444a_5e7e_b197_9eaaf9d2829a
#define WINRT_GENERIC_989c1371_444a_5e7e_b197_9eaaf9d2829a
template <> struct __declspec(uuid("989c1371-444a-5e7e-b197-9eaaf9d2829a")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Media::Ocr::OcrResult> : impl_AsyncOperationCompletedHandler<Windows::Media::Ocr::OcrResult> {};
#endif


}

namespace Windows::Media::Ocr {

struct IOcrEngine :
    Windows::Foundation::IInspectable,
    impl::consume<IOcrEngine>
{
    IOcrEngine(std::nullptr_t = nullptr) noexcept {}
};

struct IOcrEngineStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IOcrEngineStatics>
{
    IOcrEngineStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IOcrLine :
    Windows::Foundation::IInspectable,
    impl::consume<IOcrLine>
{
    IOcrLine(std::nullptr_t = nullptr) noexcept {}
};

struct IOcrResult :
    Windows::Foundation::IInspectable,
    impl::consume<IOcrResult>
{
    IOcrResult(std::nullptr_t = nullptr) noexcept {}
};

struct IOcrWord :
    Windows::Foundation::IInspectable,
    impl::consume<IOcrWord>
{
    IOcrWord(std::nullptr_t = nullptr) noexcept {}
};

}

}
