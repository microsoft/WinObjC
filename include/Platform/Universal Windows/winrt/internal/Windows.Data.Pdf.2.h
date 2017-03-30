// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Data.Pdf.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_d6b166ec_099a_5ee2_ad2e_f4c88614aabb
#define WINRT_GENERIC_d6b166ec_099a_5ee2_ad2e_f4c88614aabb
template <> struct __declspec(uuid("d6b166ec-099a-5ee2-ad2e-f4c88614aabb")) __declspec(novtable) IAsyncOperation<Windows::Data::Pdf::PdfDocument> : impl_IAsyncOperation<Windows::Data::Pdf::PdfDocument> {};
#endif

#ifndef WINRT_GENERIC_8d4950b3_629d_5d7d_84cc_04c0dcf7942b
#define WINRT_GENERIC_8d4950b3_629d_5d7d_84cc_04c0dcf7942b
template <> struct __declspec(uuid("8d4950b3-629d-5d7d-84cc-04c0dcf7942b")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Data::Pdf::PdfDocument> : impl_AsyncOperationCompletedHandler<Windows::Data::Pdf::PdfDocument> {};
#endif


}

namespace Windows::Data::Pdf {

struct IPdfDocument :
    Windows::Foundation::IInspectable,
    impl::consume<IPdfDocument>
{
    IPdfDocument(std::nullptr_t = nullptr) noexcept {}
};

struct IPdfDocumentStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IPdfDocumentStatics>
{
    IPdfDocumentStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IPdfPage :
    Windows::Foundation::IInspectable,
    impl::consume<IPdfPage>
{
    IPdfPage(std::nullptr_t = nullptr) noexcept {}
};

struct IPdfPageDimensions :
    Windows::Foundation::IInspectable,
    impl::consume<IPdfPageDimensions>
{
    IPdfPageDimensions(std::nullptr_t = nullptr) noexcept {}
};

struct IPdfPageRenderOptions :
    Windows::Foundation::IInspectable,
    impl::consume<IPdfPageRenderOptions>
{
    IPdfPageRenderOptions(std::nullptr_t = nullptr) noexcept {}
};

}

}
