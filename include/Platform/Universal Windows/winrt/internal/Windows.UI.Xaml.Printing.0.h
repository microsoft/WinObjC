// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Xaml::Printing {

struct AddPagesEventHandler;
struct GetPreviewPageEventHandler;
struct IAddPagesEventArgs;
struct IGetPreviewPageEventArgs;
struct IPaginateEventArgs;
struct IPrintDocument;
struct IPrintDocumentFactory;
struct IPrintDocumentStatics;
struct PaginateEventHandler;
struct AddPagesEventArgs;
struct GetPreviewPageEventArgs;
struct PaginateEventArgs;
struct PrintDocument;

}

namespace Windows::UI::Xaml::Printing {

struct AddPagesEventHandler;
struct GetPreviewPageEventHandler;
struct PaginateEventHandler;
struct IAddPagesEventArgs;
struct IGetPreviewPageEventArgs;
struct IPaginateEventArgs;
struct IPrintDocument;
struct IPrintDocumentFactory;
struct IPrintDocumentStatics;
struct AddPagesEventArgs;
struct GetPreviewPageEventArgs;
struct PaginateEventArgs;
struct PrintDocument;

}

namespace Windows::UI::Xaml::Printing {

template <typename T> struct impl_IAddPagesEventArgs;
template <typename T> struct impl_IGetPreviewPageEventArgs;
template <typename T> struct impl_IPaginateEventArgs;
template <typename T> struct impl_IPrintDocument;
template <typename T> struct impl_IPrintDocumentFactory;
template <typename T> struct impl_IPrintDocumentStatics;
template <typename T> struct impl_AddPagesEventHandler;
template <typename T> struct impl_GetPreviewPageEventHandler;
template <typename T> struct impl_PaginateEventHandler;

}

namespace Windows::UI::Xaml::Printing {

enum class PreviewPageCountType
{
    Final = 0,
    Intermediate = 1,
};

}

}
