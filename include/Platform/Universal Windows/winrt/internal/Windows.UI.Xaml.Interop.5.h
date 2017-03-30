// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Interop {

template <typename D, typename ... Interfaces> struct NotifyCollectionChangedEventArgsT :
    overrides<D, Windows::Foundation::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Interop::INotifyCollectionChangedEventArgs>
{
    using composable = NotifyCollectionChangedEventArgs;

protected:

    NotifyCollectionChangedEventArgsT(Windows::UI::Xaml::Interop::NotifyCollectionChangedAction action, const Windows::UI::Xaml::Interop::IBindableVector & newItems, const Windows::UI::Xaml::Interop::IBindableVector & oldItems, int32_t newIndex, int32_t oldIndex)
    {
        get_activation_factory<NotifyCollectionChangedEventArgs, INotifyCollectionChangedEventArgsFactory>().CreateInstanceWithAllParameters(action, newItems, oldItems, newIndex, oldIndex, *this, this->m_inner);
    }
};

}

}
