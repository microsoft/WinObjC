// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Hosting.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Hosting {

struct IElementCompositionPreview :
    Windows::Foundation::IInspectable,
    impl::consume<IElementCompositionPreview>
{
    IElementCompositionPreview(std::nullptr_t = nullptr) noexcept {}
};

struct IElementCompositionPreviewStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IElementCompositionPreviewStatics>
{
    IElementCompositionPreviewStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IXamlUIPresenter :
    Windows::Foundation::IInspectable,
    impl::consume<IXamlUIPresenter>
{
    IXamlUIPresenter(std::nullptr_t = nullptr) noexcept {}
};

struct IXamlUIPresenterHost :
    Windows::Foundation::IInspectable,
    impl::consume<IXamlUIPresenterHost>
{
    IXamlUIPresenterHost(std::nullptr_t = nullptr) noexcept {}
};

struct IXamlUIPresenterHost2 :
    Windows::Foundation::IInspectable,
    impl::consume<IXamlUIPresenterHost2>
{
    IXamlUIPresenterHost2(std::nullptr_t = nullptr) noexcept {}
};

struct IXamlUIPresenterHost3 :
    Windows::Foundation::IInspectable,
    impl::consume<IXamlUIPresenterHost3>
{
    IXamlUIPresenterHost3(std::nullptr_t = nullptr) noexcept {}
};

struct IXamlUIPresenterStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IXamlUIPresenterStatics>
{
    IXamlUIPresenterStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IXamlUIPresenterStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IXamlUIPresenterStatics2>
{
    IXamlUIPresenterStatics2(std::nullptr_t = nullptr) noexcept {}
};

}

}
