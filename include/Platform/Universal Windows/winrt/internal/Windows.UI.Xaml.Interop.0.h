// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Xaml::Interop {

struct TypeName;

}

namespace Windows::UI::Xaml::Interop {

struct TypeName;

}

namespace ABI::Windows::UI::Xaml::Interop {

struct BindableVectorChangedEventHandler;
struct IBindableIterable;
struct IBindableIterator;
struct IBindableObservableVector;
struct IBindableVector;
struct IBindableVectorView;
struct INotifyCollectionChanged;
struct INotifyCollectionChangedEventArgs;
struct INotifyCollectionChangedEventArgsFactory;
struct NotifyCollectionChangedEventHandler;
struct NotifyCollectionChangedEventArgs;

}

namespace Windows::UI::Xaml::Interop {

struct BindableVectorChangedEventHandler;
struct NotifyCollectionChangedEventHandler;
struct IBindableIterable;
struct IBindableIterator;
struct IBindableObservableVector;
struct IBindableVector;
struct IBindableVectorView;
struct INotifyCollectionChanged;
struct INotifyCollectionChangedEventArgs;
struct INotifyCollectionChangedEventArgsFactory;
struct NotifyCollectionChangedEventArgs;

}

namespace Windows::UI::Xaml::Interop {

template <typename T> struct impl_IBindableIterable;
template <typename T> struct impl_IBindableIterator;
template <typename T> struct impl_IBindableObservableVector;
template <typename T> struct impl_IBindableVector;
template <typename T> struct impl_IBindableVectorView;
template <typename T> struct impl_INotifyCollectionChanged;
template <typename T> struct impl_INotifyCollectionChangedEventArgs;
template <typename T> struct impl_INotifyCollectionChangedEventArgsFactory;
template <typename T> struct impl_BindableVectorChangedEventHandler;
template <typename T> struct impl_NotifyCollectionChangedEventHandler;

}

namespace Windows::UI::Xaml::Interop {

enum class NotifyCollectionChangedAction
{
    Add = 0,
    Remove = 1,
    Replace = 2,
    Move = 3,
    Reset = 4,
};

enum class TypeKind
{
    Primitive = 0,
    Metadata = 1,
    Custom = 2,
};

}

}
