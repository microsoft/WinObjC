// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Interop.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Interop {

struct BindableVectorChangedEventHandler : Windows::Foundation::IUnknown
{
    BindableVectorChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> BindableVectorChangedEventHandler(L lambda);
    template <typename F> BindableVectorChangedEventHandler (F * function);
    template <typename O, typename M> BindableVectorChangedEventHandler(O * object, M method);
    void operator()(const Windows::UI::Xaml::Interop::IBindableObservableVector & vector, const Windows::Foundation::IInspectable & e) const;
};

struct NotifyCollectionChangedEventHandler : Windows::Foundation::IUnknown
{
    NotifyCollectionChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> NotifyCollectionChangedEventHandler(L lambda);
    template <typename F> NotifyCollectionChangedEventHandler (F * function);
    template <typename O, typename M> NotifyCollectionChangedEventHandler(O * object, M method);
    void operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Interop::NotifyCollectionChangedEventArgs & e) const;
};

struct IBindableIterable :
    Windows::Foundation::IInspectable,
    impl::consume<IBindableIterable>
{
    IBindableIterable(std::nullptr_t = nullptr) noexcept {}
};

struct IBindableIterator :
    Windows::Foundation::IInspectable,
    impl::consume<IBindableIterator>
{
    IBindableIterator(std::nullptr_t = nullptr) noexcept {}
};

struct IBindableObservableVector :
    Windows::Foundation::IInspectable,
    impl::consume<IBindableObservableVector>,
    impl::require<IBindableObservableVector, Windows::UI::Xaml::Interop::IBindableIterable, Windows::UI::Xaml::Interop::IBindableVector>
{
    IBindableObservableVector(std::nullptr_t = nullptr) noexcept {}
};

struct IBindableVector :
    Windows::Foundation::IInspectable,
    impl::consume<IBindableVector>,
    impl::require<IBindableVector, Windows::UI::Xaml::Interop::IBindableIterable>
{
    IBindableVector(std::nullptr_t = nullptr) noexcept {}
};

struct IBindableVectorView :
    Windows::Foundation::IInspectable,
    impl::consume<IBindableVectorView>,
    impl::require<IBindableVectorView, Windows::UI::Xaml::Interop::IBindableIterable>
{
    IBindableVectorView(std::nullptr_t = nullptr) noexcept {}
};

struct INotifyCollectionChanged :
    Windows::Foundation::IInspectable,
    impl::consume<INotifyCollectionChanged>
{
    INotifyCollectionChanged(std::nullptr_t = nullptr) noexcept {}
};

struct INotifyCollectionChangedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<INotifyCollectionChangedEventArgs>
{
    INotifyCollectionChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct INotifyCollectionChangedEventArgsFactory :
    Windows::Foundation::IInspectable,
    impl::consume<INotifyCollectionChangedEventArgsFactory>
{
    INotifyCollectionChangedEventArgsFactory(std::nullptr_t = nullptr) noexcept {}
};

}

}
