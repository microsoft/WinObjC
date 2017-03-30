// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Data {

template <typename D, typename ... Interfaces> struct BindingT :
    overrides<D, Windows::Foundation::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Data::IBindingBase, Windows::UI::Xaml::Data::IBinding, Windows::UI::Xaml::Data::IBinding2>
{
    using composable = Binding;

protected:

    BindingT()
    {
        get_activation_factory<Binding, IBindingFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct BindingBaseT :
    overrides<D, Windows::Foundation::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Data::IBindingBase>
{
    using composable = BindingBase;

protected:

    BindingBaseT()
    {
        get_activation_factory<BindingBase, IBindingBaseFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct CurrentChangingEventArgsT :
    overrides<D, Windows::Foundation::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Data::ICurrentChangingEventArgs>
{
    using composable = CurrentChangingEventArgs;

protected:

    CurrentChangingEventArgsT()
    {
        get_activation_factory<CurrentChangingEventArgs, ICurrentChangingEventArgsFactory>().CreateInstance(*this, this->m_inner);
    }

    CurrentChangingEventArgsT(bool isCancelable)
    {
        get_activation_factory<CurrentChangingEventArgs, ICurrentChangingEventArgsFactory>().CreateWithCancelableParameter(isCancelable, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ItemIndexRangeT :
    overrides<D, Windows::Foundation::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Data::IItemIndexRange>
{
    using composable = ItemIndexRange;

protected:

    ItemIndexRangeT(int32_t firstIndex, uint32_t length)
    {
        get_activation_factory<ItemIndexRange, IItemIndexRangeFactory>().CreateInstance(firstIndex, length, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct PropertyChangedEventArgsT :
    overrides<D, Windows::Foundation::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Data::IPropertyChangedEventArgs>
{
    using composable = PropertyChangedEventArgs;

protected:

    PropertyChangedEventArgsT(hstring_view name)
    {
        get_activation_factory<PropertyChangedEventArgs, IPropertyChangedEventArgsFactory>().CreateInstance(name, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct RelativeSourceT :
    overrides<D, Windows::Foundation::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Data::IRelativeSource>
{
    using composable = RelativeSource;

protected:

    RelativeSourceT()
    {
        get_activation_factory<RelativeSource, IRelativeSourceFactory>().CreateInstance(*this, this->m_inner);
    }
};

}

}
