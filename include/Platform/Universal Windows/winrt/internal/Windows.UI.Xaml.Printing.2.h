// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Printing.1.h"
#include "Windows.UI.Xaml.1.h"
#include "Windows.UI.Xaml.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Printing {

struct AddPagesEventHandler : Windows::Foundation::IUnknown
{
    AddPagesEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> AddPagesEventHandler(L lambda);
    template <typename F> AddPagesEventHandler (F * function);
    template <typename O, typename M> AddPagesEventHandler(O * object, M method);
    void operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Printing::AddPagesEventArgs & e) const;
};

struct GetPreviewPageEventHandler : Windows::Foundation::IUnknown
{
    GetPreviewPageEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> GetPreviewPageEventHandler(L lambda);
    template <typename F> GetPreviewPageEventHandler (F * function);
    template <typename O, typename M> GetPreviewPageEventHandler(O * object, M method);
    void operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Printing::GetPreviewPageEventArgs & e) const;
};

struct PaginateEventHandler : Windows::Foundation::IUnknown
{
    PaginateEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> PaginateEventHandler(L lambda);
    template <typename F> PaginateEventHandler (F * function);
    template <typename O, typename M> PaginateEventHandler(O * object, M method);
    void operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Printing::PaginateEventArgs & e) const;
};

struct IAddPagesEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IAddPagesEventArgs>
{
    IAddPagesEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IGetPreviewPageEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IGetPreviewPageEventArgs>
{
    IGetPreviewPageEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IPaginateEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IPaginateEventArgs>
{
    IPaginateEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintDocument :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintDocument>
{
    IPrintDocument(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintDocumentFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintDocumentFactory>
{
    IPrintDocumentFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintDocumentStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintDocumentStatics>
{
    IPrintDocumentStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
