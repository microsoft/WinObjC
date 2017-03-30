// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Data.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Data {

template <typename H> struct impl_CurrentChangingEventHandler : implements<impl_CurrentChangingEventHandler<H>, abi<CurrentChangingEventHandler>>, H
{
    impl_CurrentChangingEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Data::ICurrentChangingEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Data::CurrentChangingEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_PropertyChangedEventHandler : implements<impl_PropertyChangedEventHandler<H>, abi<PropertyChangedEventHandler>>, H
{
    impl_PropertyChangedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Data::IPropertyChangedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Data::PropertyChangedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::UI::Xaml::Data {

struct WINRT_EBO Binding :
    Windows::UI::Xaml::Data::IBinding,
    impl::bases<Binding, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Data::BindingBase>,
    impl::require<Binding, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Data::IBindingBase, Windows::UI::Xaml::Data::IBinding2>
{
    Binding(std::nullptr_t) noexcept {}
    Binding();
};

struct WINRT_EBO BindingBase :
    Windows::UI::Xaml::Data::IBindingBase,
    impl::bases<BindingBase, Windows::UI::Xaml::DependencyObject>,
    impl::require<BindingBase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    BindingBase(std::nullptr_t) noexcept {}
    BindingBase();
};

struct WINRT_EBO BindingExpression :
    Windows::UI::Xaml::Data::IBindingExpression,
    impl::bases<BindingExpression, Windows::UI::Xaml::Data::BindingExpressionBase>,
    impl::require<BindingExpression, Windows::UI::Xaml::Data::IBindingExpressionBase>
{
    BindingExpression(std::nullptr_t) noexcept {}
};

struct WINRT_EBO BindingExpressionBase :
    Windows::UI::Xaml::Data::IBindingExpressionBase
{
    BindingExpressionBase(std::nullptr_t) noexcept {}
};

struct WINRT_EBO BindingOperations :
    Windows::UI::Xaml::Data::IBindingOperations
{
    BindingOperations(std::nullptr_t) noexcept {}
    static void SetBinding(const Windows::UI::Xaml::DependencyObject & target, const Windows::UI::Xaml::DependencyProperty & dp, const Windows::UI::Xaml::Data::BindingBase & binding);
};

struct WINRT_EBO CollectionViewSource :
    Windows::UI::Xaml::Data::ICollectionViewSource,
    impl::bases<CollectionViewSource, Windows::UI::Xaml::DependencyObject>,
    impl::require<CollectionViewSource, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    CollectionViewSource(std::nullptr_t) noexcept {}
    CollectionViewSource();
    static Windows::UI::Xaml::DependencyProperty SourceProperty();
    static Windows::UI::Xaml::DependencyProperty ViewProperty();
    static Windows::UI::Xaml::DependencyProperty IsSourceGroupedProperty();
    static Windows::UI::Xaml::DependencyProperty ItemsPathProperty();
};

struct WINRT_EBO CurrentChangingEventArgs :
    Windows::UI::Xaml::Data::ICurrentChangingEventArgs
{
    CurrentChangingEventArgs(std::nullptr_t) noexcept {}
    CurrentChangingEventArgs();
    CurrentChangingEventArgs(bool isCancelable);
};

struct WINRT_EBO ItemIndexRange :
    Windows::UI::Xaml::Data::IItemIndexRange
{
    ItemIndexRange(std::nullptr_t) noexcept {}
    ItemIndexRange(int32_t firstIndex, uint32_t length);
};

struct WINRT_EBO PropertyChangedEventArgs :
    Windows::UI::Xaml::Data::IPropertyChangedEventArgs
{
    PropertyChangedEventArgs(std::nullptr_t) noexcept {}
    PropertyChangedEventArgs(hstring_view name);
};

struct WINRT_EBO RelativeSource :
    Windows::UI::Xaml::Data::IRelativeSource,
    impl::bases<RelativeSource, Windows::UI::Xaml::DependencyObject>,
    impl::require<RelativeSource, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    RelativeSource(std::nullptr_t) noexcept {}
    RelativeSource();
};

}

}
