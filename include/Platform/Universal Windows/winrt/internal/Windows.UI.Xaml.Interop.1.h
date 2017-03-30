// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.UI.Xaml.Interop.0.h"
#include "Windows.Foundation.0.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Xaml::Interop {

struct TypeName
{
    hstring Name;
    winrt::Windows::UI::Xaml::Interop::TypeKind Kind;
};

}

namespace Windows::UI::Xaml::Interop {

struct TypeName
{
    hstring Name;
    Windows::UI::Xaml::Interop::TypeKind Kind;
};

}

namespace impl {

template <> struct traits<Windows::UI::Xaml::Interop::TypeName>
{
    using abi = ABI::Windows::UI::Xaml::Interop::TypeName;
};

}

namespace ABI::Windows::UI::Xaml::Interop {

struct __declspec(uuid("624cd4e1-d007-43b1-9c03-af4d3e6258c4")) __declspec(novtable) BindableVectorChangedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::UI::Xaml::Interop::IBindableObservableVector * vector, Windows::Foundation::IInspectable * e) = 0;
};

struct __declspec(uuid("036d2c08-df29-41af-8aa2-d774be62ba6f")) __declspec(novtable) IBindableIterable : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_First(Windows::UI::Xaml::Interop::IBindableIterator ** returnValue) = 0;
};

struct __declspec(uuid("6a1d6c07-076d-49f2-8314-f52c9c9a8331")) __declspec(novtable) IBindableIterator : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Current(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall get_HasCurrent(bool * value) = 0;
    virtual HRESULT __stdcall abi_MoveNext(bool * returnValue) = 0;
};

struct __declspec(uuid("fe1eb536-7e7f-4f90-ac9a-474984aae512")) __declspec(novtable) IBindableObservableVector : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_VectorChanged(Windows::UI::Xaml::Interop::BindableVectorChangedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_VectorChanged(event_token token) = 0;
};

struct __declspec(uuid("393de7de-6fd0-4c0d-bb71-47244a113e93")) __declspec(novtable) IBindableVector : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetAt(uint32_t index, Windows::Foundation::IInspectable ** returnValue) = 0;
    virtual HRESULT __stdcall get_Size(uint32_t * value) = 0;
    virtual HRESULT __stdcall abi_GetView(Windows::UI::Xaml::Interop::IBindableVectorView ** returnValue) = 0;
    virtual HRESULT __stdcall abi_IndexOf(Windows::Foundation::IInspectable * value, uint32_t * index, bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_SetAt(uint32_t index, Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall abi_InsertAt(uint32_t index, Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall abi_RemoveAt(uint32_t index) = 0;
    virtual HRESULT __stdcall abi_Append(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall abi_RemoveAtEnd() = 0;
    virtual HRESULT __stdcall abi_Clear() = 0;
};

struct __declspec(uuid("346dd6e7-976e-4bc3-815d-ece243bc0f33")) __declspec(novtable) IBindableVectorView : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetAt(uint32_t index, Windows::Foundation::IInspectable ** returnValue) = 0;
    virtual HRESULT __stdcall get_Size(uint32_t * value) = 0;
    virtual HRESULT __stdcall abi_IndexOf(Windows::Foundation::IInspectable * value, uint32_t * index, bool * returnValue) = 0;
};

struct __declspec(uuid("28b167d5-1a31-465b-9b25-d5c3ae686c40")) __declspec(novtable) INotifyCollectionChanged : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_CollectionChanged(Windows::UI::Xaml::Interop::NotifyCollectionChangedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_CollectionChanged(event_token token) = 0;
};

struct __declspec(uuid("4cf68d33-e3f2-4964-b85e-945b4f7e2f21")) __declspec(novtable) INotifyCollectionChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Action(winrt::Windows::UI::Xaml::Interop::NotifyCollectionChangedAction * value) = 0;
    virtual HRESULT __stdcall get_NewItems(Windows::UI::Xaml::Interop::IBindableVector ** value) = 0;
    virtual HRESULT __stdcall get_OldItems(Windows::UI::Xaml::Interop::IBindableVector ** value) = 0;
    virtual HRESULT __stdcall get_NewStartingIndex(int32_t * value) = 0;
    virtual HRESULT __stdcall get_OldStartingIndex(int32_t * value) = 0;
};

struct __declspec(uuid("b30c3e3a-df8d-44a5-9a38-7ac0d08ce63d")) __declspec(novtable) INotifyCollectionChangedEventArgsFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithAllParameters(winrt::Windows::UI::Xaml::Interop::NotifyCollectionChangedAction action, Windows::UI::Xaml::Interop::IBindableVector * newItems, Windows::UI::Xaml::Interop::IBindableVector * oldItems, int32_t newIndex, int32_t oldIndex, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Interop::INotifyCollectionChangedEventArgs ** instance) = 0;
};

struct __declspec(uuid("ca10b37c-f382-4591-8557-5e24965279b0")) __declspec(novtable) NotifyCollectionChangedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::Interop::INotifyCollectionChangedEventArgs * e) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::UI::Xaml::Interop::NotifyCollectionChangedEventArgs> { using default_interface = Windows::UI::Xaml::Interop::INotifyCollectionChangedEventArgs; };

}

namespace Windows::UI::Xaml::Interop {

template <typename D>
struct WINRT_EBO impl_IBindableIterable
{
    Windows::UI::Xaml::Interop::IBindableIterator First() const;
};

template <typename D>
struct WINRT_EBO impl_IBindableIterator
{
    Windows::Foundation::IInspectable Current() const;
    bool HasCurrent() const;
    bool MoveNext() const;
};

template <typename D>
struct WINRT_EBO impl_IBindableObservableVector
{
    event_token VectorChanged(const Windows::UI::Xaml::Interop::BindableVectorChangedEventHandler & value) const;
    using VectorChanged_revoker = event_revoker<IBindableObservableVector>;
    VectorChanged_revoker VectorChanged(auto_revoke_t, const Windows::UI::Xaml::Interop::BindableVectorChangedEventHandler & value) const;
    void VectorChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IBindableVector
{
    Windows::Foundation::IInspectable GetAt(uint32_t index) const;
    uint32_t Size() const;
    Windows::UI::Xaml::Interop::IBindableVectorView GetView() const;
    bool IndexOf(const Windows::Foundation::IInspectable & value, uint32_t & index) const;
    void SetAt(uint32_t index, const Windows::Foundation::IInspectable & value) const;
    void InsertAt(uint32_t index, const Windows::Foundation::IInspectable & value) const;
    void RemoveAt(uint32_t index) const;
    void Append(const Windows::Foundation::IInspectable & value) const;
    void RemoveAtEnd() const;
    void Clear() const;
};

template <typename D>
struct WINRT_EBO impl_IBindableVectorView
{
    Windows::Foundation::IInspectable GetAt(uint32_t index) const;
    uint32_t Size() const;
    bool IndexOf(const Windows::Foundation::IInspectable & value, uint32_t & index) const;
};

template <typename D>
struct WINRT_EBO impl_INotifyCollectionChanged
{
    event_token CollectionChanged(const Windows::UI::Xaml::Interop::NotifyCollectionChangedEventHandler & value) const;
    using CollectionChanged_revoker = event_revoker<INotifyCollectionChanged>;
    CollectionChanged_revoker CollectionChanged(auto_revoke_t, const Windows::UI::Xaml::Interop::NotifyCollectionChangedEventHandler & value) const;
    void CollectionChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_INotifyCollectionChangedEventArgs
{
    Windows::UI::Xaml::Interop::NotifyCollectionChangedAction Action() const;
    Windows::UI::Xaml::Interop::IBindableVector NewItems() const;
    Windows::UI::Xaml::Interop::IBindableVector OldItems() const;
    int32_t NewStartingIndex() const;
    int32_t OldStartingIndex() const;
};

template <typename D>
struct WINRT_EBO impl_INotifyCollectionChangedEventArgsFactory
{
    Windows::UI::Xaml::Interop::NotifyCollectionChangedEventArgs CreateInstanceWithAllParameters(Windows::UI::Xaml::Interop::NotifyCollectionChangedAction action, const Windows::UI::Xaml::Interop::IBindableVector & newItems, const Windows::UI::Xaml::Interop::IBindableVector & oldItems, int32_t newIndex, int32_t oldIndex, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

}

namespace impl {

template <> struct traits<Windows::UI::Xaml::Interop::BindableVectorChangedEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::Interop::BindableVectorChangedEventHandler;
};

template <> struct traits<Windows::UI::Xaml::Interop::IBindableIterable>
{
    using abi = ABI::Windows::UI::Xaml::Interop::IBindableIterable;
    template <typename D> using consume = Windows::UI::Xaml::Interop::impl_IBindableIterable<D>;
};

template <> struct traits<Windows::UI::Xaml::Interop::IBindableIterator>
{
    using abi = ABI::Windows::UI::Xaml::Interop::IBindableIterator;
    template <typename D> using consume = Windows::UI::Xaml::Interop::impl_IBindableIterator<D>;
};

template <> struct traits<Windows::UI::Xaml::Interop::IBindableObservableVector>
{
    using abi = ABI::Windows::UI::Xaml::Interop::IBindableObservableVector;
    template <typename D> using consume = Windows::UI::Xaml::Interop::impl_IBindableObservableVector<D>;
};

template <> struct traits<Windows::UI::Xaml::Interop::IBindableVector>
{
    using abi = ABI::Windows::UI::Xaml::Interop::IBindableVector;
    template <typename D> using consume = Windows::UI::Xaml::Interop::impl_IBindableVector<D>;
};

template <> struct traits<Windows::UI::Xaml::Interop::IBindableVectorView>
{
    using abi = ABI::Windows::UI::Xaml::Interop::IBindableVectorView;
    template <typename D> using consume = Windows::UI::Xaml::Interop::impl_IBindableVectorView<D>;
};

template <> struct traits<Windows::UI::Xaml::Interop::INotifyCollectionChanged>
{
    using abi = ABI::Windows::UI::Xaml::Interop::INotifyCollectionChanged;
    template <typename D> using consume = Windows::UI::Xaml::Interop::impl_INotifyCollectionChanged<D>;
};

template <> struct traits<Windows::UI::Xaml::Interop::INotifyCollectionChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Interop::INotifyCollectionChangedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Interop::impl_INotifyCollectionChangedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Interop::INotifyCollectionChangedEventArgsFactory>
{
    using abi = ABI::Windows::UI::Xaml::Interop::INotifyCollectionChangedEventArgsFactory;
    template <typename D> using consume = Windows::UI::Xaml::Interop::impl_INotifyCollectionChangedEventArgsFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Interop::NotifyCollectionChangedEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::Interop::NotifyCollectionChangedEventHandler;
};

template <> struct traits<Windows::UI::Xaml::Interop::NotifyCollectionChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Interop::NotifyCollectionChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Interop.NotifyCollectionChangedEventArgs"; }
};

}

}
