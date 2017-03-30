// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Printing.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Printing {

template <typename H> struct impl_AddPagesEventHandler : implements<impl_AddPagesEventHandler<H>, abi<AddPagesEventHandler>>, H
{
    impl_AddPagesEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Printing::IAddPagesEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Printing::AddPagesEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_GetPreviewPageEventHandler : implements<impl_GetPreviewPageEventHandler<H>, abi<GetPreviewPageEventHandler>>, H
{
    impl_GetPreviewPageEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Printing::IGetPreviewPageEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Printing::GetPreviewPageEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_PaginateEventHandler : implements<impl_PaginateEventHandler<H>, abi<PaginateEventHandler>>, H
{
    impl_PaginateEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Printing::IPaginateEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Printing::PaginateEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::UI::Xaml::Printing {

struct WINRT_EBO AddPagesEventArgs :
    Windows::UI::Xaml::Printing::IAddPagesEventArgs
{
    AddPagesEventArgs(std::nullptr_t) noexcept {}
    AddPagesEventArgs();
};

struct WINRT_EBO GetPreviewPageEventArgs :
    Windows::UI::Xaml::Printing::IGetPreviewPageEventArgs
{
    GetPreviewPageEventArgs(std::nullptr_t) noexcept {}
    GetPreviewPageEventArgs();
};

struct WINRT_EBO PaginateEventArgs :
    Windows::UI::Xaml::Printing::IPaginateEventArgs
{
    PaginateEventArgs(std::nullptr_t) noexcept {}
    PaginateEventArgs();
};

struct WINRT_EBO PrintDocument :
    Windows::UI::Xaml::Printing::IPrintDocument,
    impl::bases<PrintDocument, Windows::UI::Xaml::DependencyObject>,
    impl::require<PrintDocument, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    PrintDocument(std::nullptr_t) noexcept {}
    PrintDocument();
    static Windows::UI::Xaml::DependencyProperty DocumentSourceProperty();
};

}

}
