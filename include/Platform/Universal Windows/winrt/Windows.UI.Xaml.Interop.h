// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.UI.Xaml.Interop.3.h"
#include "Windows.UI.Xaml.h"
#include "internal/Windows.UI.Xaml.Interop.5.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Interop {

template <typename L> BindableVectorChangedEventHandler::BindableVectorChangedEventHandler(L lambda) :
    BindableVectorChangedEventHandler(impl::make_delegate<impl_BindableVectorChangedEventHandler<L>, BindableVectorChangedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> BindableVectorChangedEventHandler::BindableVectorChangedEventHandler(F * function) :
    BindableVectorChangedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> BindableVectorChangedEventHandler::BindableVectorChangedEventHandler(O * object, M method) :
    BindableVectorChangedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void BindableVectorChangedEventHandler::operator()(const Windows::UI::Xaml::Interop::IBindableObservableVector & vector, const Windows::Foundation::IInspectable & e) const
{
    check_hresult((*(abi<BindableVectorChangedEventHandler> **)this)->abi_Invoke(get_abi(vector), get_abi(e)));
}

template <typename L> NotifyCollectionChangedEventHandler::NotifyCollectionChangedEventHandler(L lambda) :
    NotifyCollectionChangedEventHandler(impl::make_delegate<impl_NotifyCollectionChangedEventHandler<L>, NotifyCollectionChangedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> NotifyCollectionChangedEventHandler::NotifyCollectionChangedEventHandler(F * function) :
    NotifyCollectionChangedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> NotifyCollectionChangedEventHandler::NotifyCollectionChangedEventHandler(O * object, M method) :
    NotifyCollectionChangedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void NotifyCollectionChangedEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Interop::NotifyCollectionChangedEventArgs & e) const
{
    check_hresult((*(abi<NotifyCollectionChangedEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

}

namespace impl {

template <typename D>
struct produce<D, Windows::UI::Xaml::Interop::IBindableIterable> : produce_base<D, Windows::UI::Xaml::Interop::IBindableIterable>
{
    HRESULT __stdcall abi_First(impl::abi_arg_out<Windows::UI::Xaml::Interop::IBindableIterator> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().First());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Interop::IBindableIterator> : produce_base<D, Windows::UI::Xaml::Interop::IBindableIterator>
{
    HRESULT __stdcall get_Current(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Current());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HasCurrent(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HasCurrent());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MoveNext(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().MoveNext());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Interop::IBindableObservableVector> : produce_base<D, Windows::UI::Xaml::Interop::IBindableObservableVector>
{
    HRESULT __stdcall add_VectorChanged(impl::abi_arg_in<Windows::UI::Xaml::Interop::BindableVectorChangedEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().VectorChanged(*reinterpret_cast<const Windows::UI::Xaml::Interop::BindableVectorChangedEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_VectorChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VectorChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Interop::IBindableVector> : produce_base<D, Windows::UI::Xaml::Interop::IBindableVector>
{
    HRESULT __stdcall abi_GetAt(uint32_t index, impl::abi_arg_out<Windows::Foundation::IInspectable> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetAt(index));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Size(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Size());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetView(impl::abi_arg_out<Windows::UI::Xaml::Interop::IBindableVectorView> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetView());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IndexOf(impl::abi_arg_in<Windows::Foundation::IInspectable> value, uint32_t * index, bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().IndexOf(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&value), *index));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetAt(uint32_t index, impl::abi_arg_in<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetAt(index, *reinterpret_cast<const Windows::Foundation::IInspectable *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_InsertAt(uint32_t index, impl::abi_arg_in<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertAt(index, *reinterpret_cast<const Windows::Foundation::IInspectable *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveAt(uint32_t index) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveAt(index);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Append(impl::abi_arg_in<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Append(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveAtEnd() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveAtEnd();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Clear() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Clear();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Interop::IBindableVectorView> : produce_base<D, Windows::UI::Xaml::Interop::IBindableVectorView>
{
    HRESULT __stdcall abi_GetAt(uint32_t index, impl::abi_arg_out<Windows::Foundation::IInspectable> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetAt(index));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Size(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Size());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IndexOf(impl::abi_arg_in<Windows::Foundation::IInspectable> value, uint32_t * index, bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().IndexOf(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&value), *index));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Interop::INotifyCollectionChanged> : produce_base<D, Windows::UI::Xaml::Interop::INotifyCollectionChanged>
{
    HRESULT __stdcall add_CollectionChanged(impl::abi_arg_in<Windows::UI::Xaml::Interop::NotifyCollectionChangedEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().CollectionChanged(*reinterpret_cast<const Windows::UI::Xaml::Interop::NotifyCollectionChangedEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CollectionChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CollectionChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Interop::INotifyCollectionChangedEventArgs> : produce_base<D, Windows::UI::Xaml::Interop::INotifyCollectionChangedEventArgs>
{
    HRESULT __stdcall get_Action(Windows::UI::Xaml::Interop::NotifyCollectionChangedAction * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Action());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NewItems(impl::abi_arg_out<Windows::UI::Xaml::Interop::IBindableVector> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NewItems());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OldItems(impl::abi_arg_out<Windows::UI::Xaml::Interop::IBindableVector> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OldItems());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NewStartingIndex(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NewStartingIndex());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OldStartingIndex(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OldStartingIndex());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Interop::INotifyCollectionChangedEventArgsFactory> : produce_base<D, Windows::UI::Xaml::Interop::INotifyCollectionChangedEventArgsFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithAllParameters(Windows::UI::Xaml::Interop::NotifyCollectionChangedAction action, impl::abi_arg_in<Windows::UI::Xaml::Interop::IBindableVector> newItems, impl::abi_arg_in<Windows::UI::Xaml::Interop::IBindableVector> oldItems, int32_t newIndex, int32_t oldIndex, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Interop::INotifyCollectionChangedEventArgs> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithAllParameters(action, *reinterpret_cast<const Windows::UI::Xaml::Interop::IBindableVector *>(&newItems), *reinterpret_cast<const Windows::UI::Xaml::Interop::IBindableVector *>(&oldItems), newIndex, oldIndex, *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
            return S_OK;
        }
        catch (...)
        {
            *inner = nullptr;
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::UI::Xaml::Interop {

template <typename D> Windows::UI::Xaml::Interop::IBindableIterator impl_IBindableIterable<D>::First() const
{
    Windows::UI::Xaml::Interop::IBindableIterator returnValue;
    check_hresult(WINRT_SHIM(IBindableIterable)->abi_First(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IInspectable impl_IBindableVector<D>::GetAt(uint32_t index) const
{
    Windows::Foundation::IInspectable returnValue;
    check_hresult(WINRT_SHIM(IBindableVector)->abi_GetAt(index, put_abi(returnValue)));
    return returnValue;
}

template <typename D> uint32_t impl_IBindableVector<D>::Size() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBindableVector)->get_Size(&value));
    return value;
}

template <typename D> Windows::UI::Xaml::Interop::IBindableVectorView impl_IBindableVector<D>::GetView() const
{
    Windows::UI::Xaml::Interop::IBindableVectorView returnValue;
    check_hresult(WINRT_SHIM(IBindableVector)->abi_GetView(put_abi(returnValue)));
    return returnValue;
}

template <typename D> bool impl_IBindableVector<D>::IndexOf(const Windows::Foundation::IInspectable & value, uint32_t & index) const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IBindableVector)->abi_IndexOf(get_abi(value), &index, &returnValue));
    return returnValue;
}

template <typename D> void impl_IBindableVector<D>::SetAt(uint32_t index, const Windows::Foundation::IInspectable & value) const
{
    check_hresult(WINRT_SHIM(IBindableVector)->abi_SetAt(index, get_abi(value)));
}

template <typename D> void impl_IBindableVector<D>::InsertAt(uint32_t index, const Windows::Foundation::IInspectable & value) const
{
    check_hresult(WINRT_SHIM(IBindableVector)->abi_InsertAt(index, get_abi(value)));
}

template <typename D> void impl_IBindableVector<D>::RemoveAt(uint32_t index) const
{
    check_hresult(WINRT_SHIM(IBindableVector)->abi_RemoveAt(index));
}

template <typename D> void impl_IBindableVector<D>::Append(const Windows::Foundation::IInspectable & value) const
{
    check_hresult(WINRT_SHIM(IBindableVector)->abi_Append(get_abi(value)));
}

template <typename D> void impl_IBindableVector<D>::RemoveAtEnd() const
{
    check_hresult(WINRT_SHIM(IBindableVector)->abi_RemoveAtEnd());
}

template <typename D> void impl_IBindableVector<D>::Clear() const
{
    check_hresult(WINRT_SHIM(IBindableVector)->abi_Clear());
}

template <typename D> event_token impl_IBindableObservableVector<D>::VectorChanged(const Windows::UI::Xaml::Interop::BindableVectorChangedEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IBindableObservableVector)->add_VectorChanged(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IBindableObservableVector> impl_IBindableObservableVector<D>::VectorChanged(auto_revoke_t, const Windows::UI::Xaml::Interop::BindableVectorChangedEventHandler & value) const
{
    return impl::make_event_revoker<D, IBindableObservableVector>(this, &ABI::Windows::UI::Xaml::Interop::IBindableObservableVector::remove_VectorChanged, VectorChanged(value));
}

template <typename D> void impl_IBindableObservableVector<D>::VectorChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IBindableObservableVector)->remove_VectorChanged(token));
}

template <typename D> Windows::Foundation::IInspectable impl_IBindableVectorView<D>::GetAt(uint32_t index) const
{
    Windows::Foundation::IInspectable returnValue;
    check_hresult(WINRT_SHIM(IBindableVectorView)->abi_GetAt(index, put_abi(returnValue)));
    return returnValue;
}

template <typename D> uint32_t impl_IBindableVectorView<D>::Size() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBindableVectorView)->get_Size(&value));
    return value;
}

template <typename D> bool impl_IBindableVectorView<D>::IndexOf(const Windows::Foundation::IInspectable & value, uint32_t & index) const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IBindableVectorView)->abi_IndexOf(get_abi(value), &index, &returnValue));
    return returnValue;
}

template <typename D> Windows::Foundation::IInspectable impl_IBindableIterator<D>::Current() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IBindableIterator)->get_Current(put_abi(value)));
    return value;
}

template <typename D> bool impl_IBindableIterator<D>::HasCurrent() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IBindableIterator)->get_HasCurrent(&value));
    return value;
}

template <typename D> bool impl_IBindableIterator<D>::MoveNext() const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IBindableIterator)->abi_MoveNext(&returnValue));
    return returnValue;
}

template <typename D> event_token impl_INotifyCollectionChanged<D>::CollectionChanged(const Windows::UI::Xaml::Interop::NotifyCollectionChangedEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(INotifyCollectionChanged)->add_CollectionChanged(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<INotifyCollectionChanged> impl_INotifyCollectionChanged<D>::CollectionChanged(auto_revoke_t, const Windows::UI::Xaml::Interop::NotifyCollectionChangedEventHandler & value) const
{
    return impl::make_event_revoker<D, INotifyCollectionChanged>(this, &ABI::Windows::UI::Xaml::Interop::INotifyCollectionChanged::remove_CollectionChanged, CollectionChanged(value));
}

template <typename D> void impl_INotifyCollectionChanged<D>::CollectionChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(INotifyCollectionChanged)->remove_CollectionChanged(token));
}

template <typename D> Windows::UI::Xaml::Interop::NotifyCollectionChangedAction impl_INotifyCollectionChangedEventArgs<D>::Action() const
{
    Windows::UI::Xaml::Interop::NotifyCollectionChangedAction value {};
    check_hresult(WINRT_SHIM(INotifyCollectionChangedEventArgs)->get_Action(&value));
    return value;
}

template <typename D> Windows::UI::Xaml::Interop::IBindableVector impl_INotifyCollectionChangedEventArgs<D>::NewItems() const
{
    Windows::UI::Xaml::Interop::IBindableVector value;
    check_hresult(WINRT_SHIM(INotifyCollectionChangedEventArgs)->get_NewItems(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Interop::IBindableVector impl_INotifyCollectionChangedEventArgs<D>::OldItems() const
{
    Windows::UI::Xaml::Interop::IBindableVector value;
    check_hresult(WINRT_SHIM(INotifyCollectionChangedEventArgs)->get_OldItems(put_abi(value)));
    return value;
}

template <typename D> int32_t impl_INotifyCollectionChangedEventArgs<D>::NewStartingIndex() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(INotifyCollectionChangedEventArgs)->get_NewStartingIndex(&value));
    return value;
}

template <typename D> int32_t impl_INotifyCollectionChangedEventArgs<D>::OldStartingIndex() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(INotifyCollectionChangedEventArgs)->get_OldStartingIndex(&value));
    return value;
}

template <typename D> Windows::UI::Xaml::Interop::NotifyCollectionChangedEventArgs impl_INotifyCollectionChangedEventArgsFactory<D>::CreateInstanceWithAllParameters(Windows::UI::Xaml::Interop::NotifyCollectionChangedAction action, const Windows::UI::Xaml::Interop::IBindableVector & newItems, const Windows::UI::Xaml::Interop::IBindableVector & oldItems, int32_t newIndex, int32_t oldIndex, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Interop::NotifyCollectionChangedEventArgs instance { nullptr };
    check_hresult(WINRT_SHIM(INotifyCollectionChangedEventArgsFactory)->abi_CreateInstanceWithAllParameters(action, get_abi(newItems), get_abi(oldItems), newIndex, oldIndex, get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

inline NotifyCollectionChangedEventArgs::NotifyCollectionChangedEventArgs(Windows::UI::Xaml::Interop::NotifyCollectionChangedAction action, const Windows::UI::Xaml::Interop::IBindableVector & newItems, const Windows::UI::Xaml::Interop::IBindableVector & oldItems, int32_t newIndex, int32_t oldIndex)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<NotifyCollectionChangedEventArgs, INotifyCollectionChangedEventArgsFactory>().CreateInstanceWithAllParameters(action, newItems, oldItems, newIndex, oldIndex, outer, inner));
}

}

}
#pragma warning(pop)
