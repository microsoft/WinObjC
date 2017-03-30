// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Data::Pdf {

struct IPdfDocument;
struct IPdfDocumentStatics;
struct IPdfPage;
struct IPdfPageDimensions;
struct IPdfPageRenderOptions;
struct PdfDocument;
struct PdfPage;
struct PdfPageDimensions;
struct PdfPageRenderOptions;

}

namespace Windows::Data::Pdf {

struct IPdfDocument;
struct IPdfDocumentStatics;
struct IPdfPage;
struct IPdfPageDimensions;
struct IPdfPageRenderOptions;
struct PdfDocument;
struct PdfPage;
struct PdfPageDimensions;
struct PdfPageRenderOptions;

}

namespace Windows::Data::Pdf {

template <typename T> struct impl_IPdfDocument;
template <typename T> struct impl_IPdfDocumentStatics;
template <typename T> struct impl_IPdfPage;
template <typename T> struct impl_IPdfPageDimensions;
template <typename T> struct impl_IPdfPageRenderOptions;

}

namespace Windows::Data::Pdf {

enum class PdfPageRotation
{
    Normal = 0,
    Rotate90 = 1,
    Rotate180 = 2,
    Rotate270 = 3,
};

}

}
