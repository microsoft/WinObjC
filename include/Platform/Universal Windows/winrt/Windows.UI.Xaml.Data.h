// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.UI.Xaml.Interop.3.h"
#include "internal/Windows.UI.Xaml.3.h"
#include "internal/Windows.UI.Xaml.Data.3.h"
#include "Windows.UI.Xaml.h"
#include "internal/Windows.UI.Xaml.Data.5.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Data {

template <typename L> CurrentChangingEventHandler::CurrentChangingEventHandler(L lambda) :
    CurrentChangingEventHandler(impl::make_delegate<impl_CurrentChangingEventHandler<L>, CurrentChangingEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> CurrentChangingEventHandler::CurrentChangingEventHandler(F * function) :
    CurrentChangingEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> CurrentChangingEventHandler::CurrentChangingEventHandler(O * object, M method) :
    CurrentChangingEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void CurrentChangingEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Data::CurrentChangingEventArgs & e) const
{
    check_hresult((*(abi<CurrentChangingEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

template <typename L> PropertyChangedEventHandler::PropertyChangedEventHandler(L lambda) :
    PropertyChangedEventHandler(impl::make_delegate<impl_PropertyChangedEventHandler<L>, PropertyChangedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> PropertyChangedEventHandler::PropertyChangedEventHandler(F * function) :
    PropertyChangedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> PropertyChangedEventHandler::PropertyChangedEventHandler(O * object, M method) :
    PropertyChangedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void PropertyChangedEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Data::PropertyChangedEventArgs & e) const
{
    check_hresult((*(abi<PropertyChangedEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

}

namespace impl {

template <typename D>
struct produce<D, Windows::UI::Xaml::Data::IBinding> : produce_base<D, Windows::UI::Xaml::Data::IBinding>
{
    HRESULT __stdcall get_Path(impl::abi_arg_out<Windows::UI::Xaml::IPropertyPath> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Path());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Path(impl::abi_arg_in<Windows::UI::Xaml::IPropertyPath> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Path(*reinterpret_cast<const Windows::UI::Xaml::PropertyPath *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Mode(Windows::UI::Xaml::Data::BindingMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Mode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Mode(Windows::UI::Xaml::Data::BindingMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Mode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Source(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Source());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Source(impl::abi_arg_in<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Source(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RelativeSource(impl::abi_arg_out<Windows::UI::Xaml::Data::IRelativeSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RelativeSource());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RelativeSource(impl::abi_arg_in<Windows::UI::Xaml::Data::IRelativeSource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RelativeSource(*reinterpret_cast<const Windows::UI::Xaml::Data::RelativeSource *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ElementName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ElementName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ElementName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ElementName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Converter(impl::abi_arg_out<Windows::UI::Xaml::Data::IValueConverter> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Converter());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Converter(impl::abi_arg_in<Windows::UI::Xaml::Data::IValueConverter> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Converter(*reinterpret_cast<const Windows::UI::Xaml::Data::IValueConverter *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ConverterParameter(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ConverterParameter());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ConverterParameter(impl::abi_arg_in<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ConverterParameter(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ConverterLanguage(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ConverterLanguage());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ConverterLanguage(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ConverterLanguage(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Data::IBinding2> : produce_base<D, Windows::UI::Xaml::Data::IBinding2>
{
    HRESULT __stdcall get_FallbackValue(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FallbackValue());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FallbackValue(impl::abi_arg_in<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FallbackValue(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TargetNullValue(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetNullValue());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TargetNullValue(impl::abi_arg_in<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TargetNullValue(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UpdateSourceTrigger(Windows::UI::Xaml::Data::UpdateSourceTrigger * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UpdateSourceTrigger());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_UpdateSourceTrigger(Windows::UI::Xaml::Data::UpdateSourceTrigger value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UpdateSourceTrigger(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Data::IBindingBase> : produce_base<D, Windows::UI::Xaml::Data::IBindingBase>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Data::IBindingBaseFactory> : produce_base<D, Windows::UI::Xaml::Data::IBindingBaseFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Data::IBindingBase> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstance(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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

template <typename D>
struct produce<D, Windows::UI::Xaml::Data::IBindingExpression> : produce_base<D, Windows::UI::Xaml::Data::IBindingExpression>
{
    HRESULT __stdcall get_DataItem(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DataItem());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ParentBinding(impl::abi_arg_out<Windows::UI::Xaml::Data::IBinding> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ParentBinding());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UpdateSource() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UpdateSource();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Data::IBindingExpressionBase> : produce_base<D, Windows::UI::Xaml::Data::IBindingExpressionBase>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Data::IBindingExpressionBaseFactory> : produce_base<D, Windows::UI::Xaml::Data::IBindingExpressionBaseFactory>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Data::IBindingExpressionFactory> : produce_base<D, Windows::UI::Xaml::Data::IBindingExpressionFactory>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Data::IBindingFactory> : produce_base<D, Windows::UI::Xaml::Data::IBindingFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Data::IBinding> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstance(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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

template <typename D>
struct produce<D, Windows::UI::Xaml::Data::IBindingOperations> : produce_base<D, Windows::UI::Xaml::Data::IBindingOperations>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Data::IBindingOperationsStatics> : produce_base<D, Windows::UI::Xaml::Data::IBindingOperationsStatics>
{
    HRESULT __stdcall abi_SetBinding(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> target, impl::abi_arg_in<Windows::UI::Xaml::IDependencyProperty> dp, impl::abi_arg_in<Windows::UI::Xaml::Data::IBindingBase> binding) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetBinding(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&target), *reinterpret_cast<const Windows::UI::Xaml::DependencyProperty *>(&dp), *reinterpret_cast<const Windows::UI::Xaml::Data::BindingBase *>(&binding));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Data::ICollectionView> : produce_base<D, Windows::UI::Xaml::Data::ICollectionView>
{
    HRESULT __stdcall get_CurrentItem(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CurrentItem());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CurrentPosition(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CurrentPosition());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsCurrentAfterLast(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsCurrentAfterLast());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsCurrentBeforeFirst(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsCurrentBeforeFirst());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CollectionGroups(impl::abi_arg_out<Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CollectionGroups());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HasMoreItems(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HasMoreItems());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_CurrentChanged(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Foundation::IInspectable>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().CurrentChanged(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CurrentChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CurrentChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_CurrentChanging(impl::abi_arg_in<Windows::UI::Xaml::Data::CurrentChangingEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().CurrentChanging(*reinterpret_cast<const Windows::UI::Xaml::Data::CurrentChangingEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CurrentChanging(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CurrentChanging(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MoveCurrentTo(impl::abi_arg_in<Windows::Foundation::IInspectable> item, bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().MoveCurrentTo(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&item)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MoveCurrentToPosition(int32_t index, bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().MoveCurrentToPosition(index));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MoveCurrentToFirst(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().MoveCurrentToFirst());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MoveCurrentToLast(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().MoveCurrentToLast());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MoveCurrentToNext(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().MoveCurrentToNext());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MoveCurrentToPrevious(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().MoveCurrentToPrevious());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LoadMoreItemsAsync(uint32_t count, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::UI::Xaml::Data::LoadMoreItemsResult>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().LoadMoreItemsAsync(count));
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
struct produce<D, Windows::UI::Xaml::Data::ICollectionViewFactory> : produce_base<D, Windows::UI::Xaml::Data::ICollectionViewFactory>
{
    HRESULT __stdcall abi_CreateView(impl::abi_arg_out<Windows::UI::Xaml::Data::ICollectionView> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateView());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Data::ICollectionViewGroup> : produce_base<D, Windows::UI::Xaml::Data::ICollectionViewGroup>
{
    HRESULT __stdcall get_Group(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Group());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GroupItems(impl::abi_arg_out<Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GroupItems());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Data::ICollectionViewSource> : produce_base<D, Windows::UI::Xaml::Data::ICollectionViewSource>
{
    HRESULT __stdcall get_Source(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Source());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Source(impl::abi_arg_in<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Source(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_View(impl::abi_arg_out<Windows::UI::Xaml::Data::ICollectionView> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().View());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsSourceGrouped(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsSourceGrouped());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsSourceGrouped(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsSourceGrouped(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ItemsPath(impl::abi_arg_out<Windows::UI::Xaml::IPropertyPath> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ItemsPath());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ItemsPath(impl::abi_arg_in<Windows::UI::Xaml::IPropertyPath> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ItemsPath(*reinterpret_cast<const Windows::UI::Xaml::PropertyPath *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Data::ICollectionViewSourceStatics> : produce_base<D, Windows::UI::Xaml::Data::ICollectionViewSourceStatics>
{
    HRESULT __stdcall get_SourceProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourceProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ViewProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ViewProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsSourceGroupedProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsSourceGroupedProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ItemsPathProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ItemsPathProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Data::ICurrentChangingEventArgs> : produce_base<D, Windows::UI::Xaml::Data::ICurrentChangingEventArgs>
{
    HRESULT __stdcall get_Cancel(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Cancel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Cancel(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Cancel(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsCancelable(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsCancelable());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Data::ICurrentChangingEventArgsFactory> : produce_base<D, Windows::UI::Xaml::Data::ICurrentChangingEventArgsFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Data::ICurrentChangingEventArgs> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstance(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
            return S_OK;
        }
        catch (...)
        {
            *inner = nullptr;
            *instance = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithCancelableParameter(bool isCancelable, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Data::ICurrentChangingEventArgs> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateWithCancelableParameter(isCancelable, *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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

template <typename D>
struct produce<D, Windows::UI::Xaml::Data::ICustomProperty> : produce_base<D, Windows::UI::Xaml::Data::ICustomProperty>
{
    HRESULT __stdcall get_Type(impl::abi_arg_out<Windows::UI::Xaml::Interop::TypeName> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Type());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Name(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetValue(impl::abi_arg_in<Windows::Foundation::IInspectable> target, impl::abi_arg_out<Windows::Foundation::IInspectable> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetValue(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&target)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetValue(impl::abi_arg_in<Windows::Foundation::IInspectable> target, impl::abi_arg_in<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetValue(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&target), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetIndexedValue(impl::abi_arg_in<Windows::Foundation::IInspectable> target, impl::abi_arg_in<Windows::Foundation::IInspectable> index, impl::abi_arg_out<Windows::Foundation::IInspectable> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetIndexedValue(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&target), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&index)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetIndexedValue(impl::abi_arg_in<Windows::Foundation::IInspectable> target, impl::abi_arg_in<Windows::Foundation::IInspectable> value, impl::abi_arg_in<Windows::Foundation::IInspectable> index) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetIndexedValue(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&target), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&value), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&index));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanWrite(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanWrite());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanRead(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanRead());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Data::ICustomPropertyProvider> : produce_base<D, Windows::UI::Xaml::Data::ICustomPropertyProvider>
{
    HRESULT __stdcall abi_GetCustomProperty(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::UI::Xaml::Data::ICustomProperty> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetCustomProperty(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetIndexedProperty(impl::abi_arg_in<hstring> name, impl::abi_arg_in<Windows::UI::Xaml::Interop::TypeName> type, impl::abi_arg_out<Windows::UI::Xaml::Data::ICustomProperty> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetIndexedProperty(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::UI::Xaml::Interop::TypeName *>(&type)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStringRepresentation(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetStringRepresentation());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Type(impl::abi_arg_out<Windows::UI::Xaml::Interop::TypeName> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Type());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Data::IItemIndexRange> : produce_base<D, Windows::UI::Xaml::Data::IItemIndexRange>
{
    HRESULT __stdcall get_FirstIndex(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FirstIndex());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Length(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Length());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LastIndex(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LastIndex());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Data::IItemIndexRangeFactory> : produce_base<D, Windows::UI::Xaml::Data::IItemIndexRangeFactory>
{
    HRESULT __stdcall abi_CreateInstance(int32_t firstIndex, uint32_t length, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Data::IItemIndexRange> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstance(firstIndex, length, *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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

template <typename D>
struct produce<D, Windows::UI::Xaml::Data::IItemsRangeInfo> : produce_base<D, Windows::UI::Xaml::Data::IItemsRangeInfo>
{
    HRESULT __stdcall abi_RangesChanged(impl::abi_arg_in<Windows::UI::Xaml::Data::IItemIndexRange> visibleRange, impl::abi_arg_in<Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Data::ItemIndexRange>> trackedItems) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RangesChanged(*reinterpret_cast<const Windows::UI::Xaml::Data::ItemIndexRange *>(&visibleRange), *reinterpret_cast<const Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Data::ItemIndexRange> *>(&trackedItems));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Data::INotifyPropertyChanged> : produce_base<D, Windows::UI::Xaml::Data::INotifyPropertyChanged>
{
    HRESULT __stdcall add_PropertyChanged(impl::abi_arg_in<Windows::UI::Xaml::Data::PropertyChangedEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().PropertyChanged(*reinterpret_cast<const Windows::UI::Xaml::Data::PropertyChangedEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PropertyChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PropertyChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Data::IPropertyChangedEventArgs> : produce_base<D, Windows::UI::Xaml::Data::IPropertyChangedEventArgs>
{
    HRESULT __stdcall get_PropertyName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PropertyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Data::IPropertyChangedEventArgsFactory> : produce_base<D, Windows::UI::Xaml::Data::IPropertyChangedEventArgsFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<hstring> name, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Data::IPropertyChangedEventArgs> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstance(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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

template <typename D>
struct produce<D, Windows::UI::Xaml::Data::IRelativeSource> : produce_base<D, Windows::UI::Xaml::Data::IRelativeSource>
{
    HRESULT __stdcall get_Mode(Windows::UI::Xaml::Data::RelativeSourceMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Mode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Mode(Windows::UI::Xaml::Data::RelativeSourceMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Mode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Data::IRelativeSourceFactory> : produce_base<D, Windows::UI::Xaml::Data::IRelativeSourceFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Data::IRelativeSource> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstance(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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

template <typename D>
struct produce<D, Windows::UI::Xaml::Data::ISelectionInfo> : produce_base<D, Windows::UI::Xaml::Data::ISelectionInfo>
{
    HRESULT __stdcall abi_SelectRange(impl::abi_arg_in<Windows::UI::Xaml::Data::IItemIndexRange> itemIndexRange) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SelectRange(*reinterpret_cast<const Windows::UI::Xaml::Data::ItemIndexRange *>(&itemIndexRange));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeselectRange(impl::abi_arg_in<Windows::UI::Xaml::Data::IItemIndexRange> itemIndexRange) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DeselectRange(*reinterpret_cast<const Windows::UI::Xaml::Data::ItemIndexRange *>(&itemIndexRange));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsSelected(int32_t index, bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().IsSelected(index));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSelectedRanges(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Data::ItemIndexRange>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetSelectedRanges());
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
struct produce<D, Windows::UI::Xaml::Data::ISupportIncrementalLoading> : produce_base<D, Windows::UI::Xaml::Data::ISupportIncrementalLoading>
{
    HRESULT __stdcall abi_LoadMoreItemsAsync(uint32_t count, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::UI::Xaml::Data::LoadMoreItemsResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().LoadMoreItemsAsync(count));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HasMoreItems(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HasMoreItems());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Data::IValueConverter> : produce_base<D, Windows::UI::Xaml::Data::IValueConverter>
{
    HRESULT __stdcall abi_Convert(impl::abi_arg_in<Windows::Foundation::IInspectable> value, impl::abi_arg_in<Windows::UI::Xaml::Interop::TypeName> targetType, impl::abi_arg_in<Windows::Foundation::IInspectable> parameter, impl::abi_arg_in<hstring> language, impl::abi_arg_out<Windows::Foundation::IInspectable> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().Convert(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&value), *reinterpret_cast<const Windows::UI::Xaml::Interop::TypeName *>(&targetType), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&parameter), *reinterpret_cast<const hstring *>(&language)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ConvertBack(impl::abi_arg_in<Windows::Foundation::IInspectable> value, impl::abi_arg_in<Windows::UI::Xaml::Interop::TypeName> targetType, impl::abi_arg_in<Windows::Foundation::IInspectable> parameter, impl::abi_arg_in<hstring> language, impl::abi_arg_out<Windows::Foundation::IInspectable> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().ConvertBack(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&value), *reinterpret_cast<const Windows::UI::Xaml::Interop::TypeName *>(&targetType), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&parameter), *reinterpret_cast<const hstring *>(&language)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::UI::Xaml::Data {

template <typename D> void impl_IItemsRangeInfo<D>::RangesChanged(const Windows::UI::Xaml::Data::ItemIndexRange & visibleRange, vector_view<Windows::UI::Xaml::Data::ItemIndexRange> trackedItems) const
{
    check_hresult(WINRT_SHIM(IItemsRangeInfo)->abi_RangesChanged(get_abi(visibleRange), get_abi(trackedItems)));
}

template <typename D> void impl_ISelectionInfo<D>::SelectRange(const Windows::UI::Xaml::Data::ItemIndexRange & itemIndexRange) const
{
    check_hresult(WINRT_SHIM(ISelectionInfo)->abi_SelectRange(get_abi(itemIndexRange)));
}

template <typename D> void impl_ISelectionInfo<D>::DeselectRange(const Windows::UI::Xaml::Data::ItemIndexRange & itemIndexRange) const
{
    check_hresult(WINRT_SHIM(ISelectionInfo)->abi_DeselectRange(get_abi(itemIndexRange)));
}

template <typename D> bool impl_ISelectionInfo<D>::IsSelected(int32_t index) const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(ISelectionInfo)->abi_IsSelected(index, &returnValue));
    return returnValue;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Data::ItemIndexRange> impl_ISelectionInfo<D>::GetSelectedRanges() const
{
    Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Data::ItemIndexRange> returnValue;
    check_hresult(WINRT_SHIM(ISelectionInfo)->abi_GetSelectedRanges(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Interop::TypeName impl_ICustomProperty<D>::Type() const
{
    Windows::UI::Xaml::Interop::TypeName value {};
    check_hresult(WINRT_SHIM(ICustomProperty)->get_Type(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICustomProperty<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICustomProperty)->get_Name(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IInspectable impl_ICustomProperty<D>::GetValue(const Windows::Foundation::IInspectable & target) const
{
    Windows::Foundation::IInspectable returnValue;
    check_hresult(WINRT_SHIM(ICustomProperty)->abi_GetValue(get_abi(target), put_abi(returnValue)));
    return returnValue;
}

template <typename D> void impl_ICustomProperty<D>::SetValue(const Windows::Foundation::IInspectable & target, const Windows::Foundation::IInspectable & value) const
{
    check_hresult(WINRT_SHIM(ICustomProperty)->abi_SetValue(get_abi(target), get_abi(value)));
}

template <typename D> Windows::Foundation::IInspectable impl_ICustomProperty<D>::GetIndexedValue(const Windows::Foundation::IInspectable & target, const Windows::Foundation::IInspectable & index) const
{
    Windows::Foundation::IInspectable returnValue;
    check_hresult(WINRT_SHIM(ICustomProperty)->abi_GetIndexedValue(get_abi(target), get_abi(index), put_abi(returnValue)));
    return returnValue;
}

template <typename D> void impl_ICustomProperty<D>::SetIndexedValue(const Windows::Foundation::IInspectable & target, const Windows::Foundation::IInspectable & value, const Windows::Foundation::IInspectable & index) const
{
    check_hresult(WINRT_SHIM(ICustomProperty)->abi_SetIndexedValue(get_abi(target), get_abi(value), get_abi(index)));
}

template <typename D> bool impl_ICustomProperty<D>::CanWrite() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICustomProperty)->get_CanWrite(&value));
    return value;
}

template <typename D> bool impl_ICustomProperty<D>::CanRead() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICustomProperty)->get_CanRead(&value));
    return value;
}

template <typename D> Windows::UI::Xaml::Data::ICustomProperty impl_ICustomPropertyProvider<D>::GetCustomProperty(hstring_view name) const
{
    Windows::UI::Xaml::Data::ICustomProperty returnValue;
    check_hresult(WINRT_SHIM(ICustomPropertyProvider)->abi_GetCustomProperty(get_abi(name), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Data::ICustomProperty impl_ICustomPropertyProvider<D>::GetIndexedProperty(hstring_view name, const Windows::UI::Xaml::Interop::TypeName & type) const
{
    Windows::UI::Xaml::Data::ICustomProperty returnValue;
    check_hresult(WINRT_SHIM(ICustomPropertyProvider)->abi_GetIndexedProperty(get_abi(name), get_abi(type), put_abi(returnValue)));
    return returnValue;
}

template <typename D> hstring impl_ICustomPropertyProvider<D>::GetStringRepresentation() const
{
    hstring returnValue;
    check_hresult(WINRT_SHIM(ICustomPropertyProvider)->abi_GetStringRepresentation(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Interop::TypeName impl_ICustomPropertyProvider<D>::Type() const
{
    Windows::UI::Xaml::Interop::TypeName value {};
    check_hresult(WINRT_SHIM(ICustomPropertyProvider)->get_Type(put_abi(value)));
    return value;
}

template <typename D> event_token impl_INotifyPropertyChanged<D>::PropertyChanged(const Windows::UI::Xaml::Data::PropertyChangedEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(INotifyPropertyChanged)->add_PropertyChanged(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<INotifyPropertyChanged> impl_INotifyPropertyChanged<D>::PropertyChanged(auto_revoke_t, const Windows::UI::Xaml::Data::PropertyChangedEventHandler & value) const
{
    return impl::make_event_revoker<D, INotifyPropertyChanged>(this, &ABI::Windows::UI::Xaml::Data::INotifyPropertyChanged::remove_PropertyChanged, PropertyChanged(value));
}

template <typename D> void impl_INotifyPropertyChanged<D>::PropertyChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(INotifyPropertyChanged)->remove_PropertyChanged(token));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::UI::Xaml::Data::LoadMoreItemsResult> impl_ISupportIncrementalLoading<D>::LoadMoreItemsAsync(uint32_t count) const
{
    Windows::Foundation::IAsyncOperation<Windows::UI::Xaml::Data::LoadMoreItemsResult> operation;
    check_hresult(WINRT_SHIM(ISupportIncrementalLoading)->abi_LoadMoreItemsAsync(count, put_abi(operation)));
    return operation;
}

template <typename D> bool impl_ISupportIncrementalLoading<D>::HasMoreItems() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISupportIncrementalLoading)->get_HasMoreItems(&value));
    return value;
}

template <typename D> Windows::Foundation::IInspectable impl_IValueConverter<D>::Convert(const Windows::Foundation::IInspectable & value, const Windows::UI::Xaml::Interop::TypeName & targetType, const Windows::Foundation::IInspectable & parameter, hstring_view language) const
{
    Windows::Foundation::IInspectable returnValue;
    check_hresult(WINRT_SHIM(IValueConverter)->abi_Convert(get_abi(value), get_abi(targetType), get_abi(parameter), get_abi(language), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IInspectable impl_IValueConverter<D>::ConvertBack(const Windows::Foundation::IInspectable & value, const Windows::UI::Xaml::Interop::TypeName & targetType, const Windows::Foundation::IInspectable & parameter, hstring_view language) const
{
    Windows::Foundation::IInspectable returnValue;
    check_hresult(WINRT_SHIM(IValueConverter)->abi_ConvertBack(get_abi(value), get_abi(targetType), get_abi(parameter), get_abi(language), put_abi(returnValue)));
    return returnValue;
}

template <typename D> void impl_IBindingOperationsStatics<D>::SetBinding(const Windows::UI::Xaml::DependencyObject & target, const Windows::UI::Xaml::DependencyProperty & dp, const Windows::UI::Xaml::Data::BindingBase & binding) const
{
    check_hresult(WINRT_SHIM(IBindingOperationsStatics)->abi_SetBinding(get_abi(target), get_abi(dp), get_abi(binding)));
}

template <typename D> bool impl_ICurrentChangingEventArgs<D>::Cancel() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICurrentChangingEventArgs)->get_Cancel(&value));
    return value;
}

template <typename D> void impl_ICurrentChangingEventArgs<D>::Cancel(bool value) const
{
    check_hresult(WINRT_SHIM(ICurrentChangingEventArgs)->put_Cancel(value));
}

template <typename D> bool impl_ICurrentChangingEventArgs<D>::IsCancelable() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICurrentChangingEventArgs)->get_IsCancelable(&value));
    return value;
}

template <typename D> Windows::UI::Xaml::Data::CurrentChangingEventArgs impl_ICurrentChangingEventArgsFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Data::CurrentChangingEventArgs instance { nullptr };
    check_hresult(WINRT_SHIM(ICurrentChangingEventArgsFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Data::CurrentChangingEventArgs impl_ICurrentChangingEventArgsFactory<D>::CreateWithCancelableParameter(bool isCancelable, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Data::CurrentChangingEventArgs instance { nullptr };
    check_hresult(WINRT_SHIM(ICurrentChangingEventArgsFactory)->abi_CreateWithCancelableParameter(isCancelable, get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> hstring impl_IPropertyChangedEventArgs<D>::PropertyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPropertyChangedEventArgs)->get_PropertyName(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Data::PropertyChangedEventArgs impl_IPropertyChangedEventArgsFactory<D>::CreateInstance(hstring_view name, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Data::PropertyChangedEventArgs instance { nullptr };
    check_hresult(WINRT_SHIM(IPropertyChangedEventArgsFactory)->abi_CreateInstance(get_abi(name), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Data::BindingBase impl_IBindingBaseFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Data::BindingBase instance { nullptr };
    check_hresult(WINRT_SHIM(IBindingBaseFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::Foundation::IInspectable impl_IBindingExpression<D>::DataItem() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IBindingExpression)->get_DataItem(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Data::Binding impl_IBindingExpression<D>::ParentBinding() const
{
    Windows::UI::Xaml::Data::Binding value { nullptr };
    check_hresult(WINRT_SHIM(IBindingExpression)->get_ParentBinding(put_abi(value)));
    return value;
}

template <typename D> void impl_IBindingExpression<D>::UpdateSource() const
{
    check_hresult(WINRT_SHIM(IBindingExpression)->abi_UpdateSource());
}

template <typename D> Windows::UI::Xaml::Data::RelativeSourceMode impl_IRelativeSource<D>::Mode() const
{
    Windows::UI::Xaml::Data::RelativeSourceMode value {};
    check_hresult(WINRT_SHIM(IRelativeSource)->get_Mode(&value));
    return value;
}

template <typename D> void impl_IRelativeSource<D>::Mode(Windows::UI::Xaml::Data::RelativeSourceMode value) const
{
    check_hresult(WINRT_SHIM(IRelativeSource)->put_Mode(value));
}

template <typename D> Windows::UI::Xaml::Data::RelativeSource impl_IRelativeSourceFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Data::RelativeSource instance { nullptr };
    check_hresult(WINRT_SHIM(IRelativeSourceFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::PropertyPath impl_IBinding<D>::Path() const
{
    Windows::UI::Xaml::PropertyPath value { nullptr };
    check_hresult(WINRT_SHIM(IBinding)->get_Path(put_abi(value)));
    return value;
}

template <typename D> void impl_IBinding<D>::Path(const Windows::UI::Xaml::PropertyPath & value) const
{
    check_hresult(WINRT_SHIM(IBinding)->put_Path(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Data::BindingMode impl_IBinding<D>::Mode() const
{
    Windows::UI::Xaml::Data::BindingMode value {};
    check_hresult(WINRT_SHIM(IBinding)->get_Mode(&value));
    return value;
}

template <typename D> void impl_IBinding<D>::Mode(Windows::UI::Xaml::Data::BindingMode value) const
{
    check_hresult(WINRT_SHIM(IBinding)->put_Mode(value));
}

template <typename D> Windows::Foundation::IInspectable impl_IBinding<D>::Source() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IBinding)->get_Source(put_abi(value)));
    return value;
}

template <typename D> void impl_IBinding<D>::Source(const Windows::Foundation::IInspectable & value) const
{
    check_hresult(WINRT_SHIM(IBinding)->put_Source(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Data::RelativeSource impl_IBinding<D>::RelativeSource() const
{
    Windows::UI::Xaml::Data::RelativeSource value { nullptr };
    check_hresult(WINRT_SHIM(IBinding)->get_RelativeSource(put_abi(value)));
    return value;
}

template <typename D> void impl_IBinding<D>::RelativeSource(const Windows::UI::Xaml::Data::RelativeSource & value) const
{
    check_hresult(WINRT_SHIM(IBinding)->put_RelativeSource(get_abi(value)));
}

template <typename D> hstring impl_IBinding<D>::ElementName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IBinding)->get_ElementName(put_abi(value)));
    return value;
}

template <typename D> void impl_IBinding<D>::ElementName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IBinding)->put_ElementName(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Data::IValueConverter impl_IBinding<D>::Converter() const
{
    Windows::UI::Xaml::Data::IValueConverter value;
    check_hresult(WINRT_SHIM(IBinding)->get_Converter(put_abi(value)));
    return value;
}

template <typename D> void impl_IBinding<D>::Converter(const Windows::UI::Xaml::Data::IValueConverter & value) const
{
    check_hresult(WINRT_SHIM(IBinding)->put_Converter(get_abi(value)));
}

template <typename D> Windows::Foundation::IInspectable impl_IBinding<D>::ConverterParameter() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IBinding)->get_ConverterParameter(put_abi(value)));
    return value;
}

template <typename D> void impl_IBinding<D>::ConverterParameter(const Windows::Foundation::IInspectable & value) const
{
    check_hresult(WINRT_SHIM(IBinding)->put_ConverterParameter(get_abi(value)));
}

template <typename D> hstring impl_IBinding<D>::ConverterLanguage() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IBinding)->get_ConverterLanguage(put_abi(value)));
    return value;
}

template <typename D> void impl_IBinding<D>::ConverterLanguage(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IBinding)->put_ConverterLanguage(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Data::Binding impl_IBindingFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Data::Binding instance { nullptr };
    check_hresult(WINRT_SHIM(IBindingFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::Foundation::IInspectable impl_IBinding2<D>::FallbackValue() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IBinding2)->get_FallbackValue(put_abi(value)));
    return value;
}

template <typename D> void impl_IBinding2<D>::FallbackValue(const Windows::Foundation::IInspectable & value) const
{
    check_hresult(WINRT_SHIM(IBinding2)->put_FallbackValue(get_abi(value)));
}

template <typename D> Windows::Foundation::IInspectable impl_IBinding2<D>::TargetNullValue() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IBinding2)->get_TargetNullValue(put_abi(value)));
    return value;
}

template <typename D> void impl_IBinding2<D>::TargetNullValue(const Windows::Foundation::IInspectable & value) const
{
    check_hresult(WINRT_SHIM(IBinding2)->put_TargetNullValue(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Data::UpdateSourceTrigger impl_IBinding2<D>::UpdateSourceTrigger() const
{
    Windows::UI::Xaml::Data::UpdateSourceTrigger value {};
    check_hresult(WINRT_SHIM(IBinding2)->get_UpdateSourceTrigger(&value));
    return value;
}

template <typename D> void impl_IBinding2<D>::UpdateSourceTrigger(Windows::UI::Xaml::Data::UpdateSourceTrigger value) const
{
    check_hresult(WINRT_SHIM(IBinding2)->put_UpdateSourceTrigger(value));
}

template <typename D> Windows::Foundation::IInspectable impl_ICollectionView<D>::CurrentItem() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(ICollectionView)->get_CurrentItem(put_abi(value)));
    return value;
}

template <typename D> int32_t impl_ICollectionView<D>::CurrentPosition() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICollectionView)->get_CurrentPosition(&value));
    return value;
}

template <typename D> bool impl_ICollectionView<D>::IsCurrentAfterLast() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICollectionView)->get_IsCurrentAfterLast(&value));
    return value;
}

template <typename D> bool impl_ICollectionView<D>::IsCurrentBeforeFirst() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICollectionView)->get_IsCurrentBeforeFirst(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> impl_ICollectionView<D>::CollectionGroups() const
{
    Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> value;
    check_hresult(WINRT_SHIM(ICollectionView)->get_CollectionGroups(put_abi(value)));
    return value;
}

template <typename D> bool impl_ICollectionView<D>::HasMoreItems() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICollectionView)->get_HasMoreItems(&value));
    return value;
}

template <typename D> event_token impl_ICollectionView<D>::CurrentChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ICollectionView)->add_CurrentChanged(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<ICollectionView> impl_ICollectionView<D>::CurrentChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const
{
    return impl::make_event_revoker<D, ICollectionView>(this, &ABI::Windows::UI::Xaml::Data::ICollectionView::remove_CurrentChanged, CurrentChanged(value));
}

template <typename D> void impl_ICollectionView<D>::CurrentChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(ICollectionView)->remove_CurrentChanged(token));
}

template <typename D> event_token impl_ICollectionView<D>::CurrentChanging(const Windows::UI::Xaml::Data::CurrentChangingEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ICollectionView)->add_CurrentChanging(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<ICollectionView> impl_ICollectionView<D>::CurrentChanging(auto_revoke_t, const Windows::UI::Xaml::Data::CurrentChangingEventHandler & value) const
{
    return impl::make_event_revoker<D, ICollectionView>(this, &ABI::Windows::UI::Xaml::Data::ICollectionView::remove_CurrentChanging, CurrentChanging(value));
}

template <typename D> void impl_ICollectionView<D>::CurrentChanging(event_token token) const
{
    check_hresult(WINRT_SHIM(ICollectionView)->remove_CurrentChanging(token));
}

template <typename D> bool impl_ICollectionView<D>::MoveCurrentTo(const Windows::Foundation::IInspectable & item) const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(ICollectionView)->abi_MoveCurrentTo(get_abi(item), &returnValue));
    return returnValue;
}

template <typename D> bool impl_ICollectionView<D>::MoveCurrentToPosition(int32_t index) const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(ICollectionView)->abi_MoveCurrentToPosition(index, &returnValue));
    return returnValue;
}

template <typename D> bool impl_ICollectionView<D>::MoveCurrentToFirst() const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(ICollectionView)->abi_MoveCurrentToFirst(&returnValue));
    return returnValue;
}

template <typename D> bool impl_ICollectionView<D>::MoveCurrentToLast() const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(ICollectionView)->abi_MoveCurrentToLast(&returnValue));
    return returnValue;
}

template <typename D> bool impl_ICollectionView<D>::MoveCurrentToNext() const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(ICollectionView)->abi_MoveCurrentToNext(&returnValue));
    return returnValue;
}

template <typename D> bool impl_ICollectionView<D>::MoveCurrentToPrevious() const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(ICollectionView)->abi_MoveCurrentToPrevious(&returnValue));
    return returnValue;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::UI::Xaml::Data::LoadMoreItemsResult> impl_ICollectionView<D>::LoadMoreItemsAsync(uint32_t count) const
{
    Windows::Foundation::IAsyncOperation<Windows::UI::Xaml::Data::LoadMoreItemsResult> returnValue;
    check_hresult(WINRT_SHIM(ICollectionView)->abi_LoadMoreItemsAsync(count, put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Data::ICollectionView impl_ICollectionViewFactory<D>::CreateView() const
{
    Windows::UI::Xaml::Data::ICollectionView result;
    check_hresult(WINRT_SHIM(ICollectionViewFactory)->abi_CreateView(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IInspectable impl_ICollectionViewGroup<D>::Group() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(ICollectionViewGroup)->get_Group(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> impl_ICollectionViewGroup<D>::GroupItems() const
{
    Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> value;
    check_hresult(WINRT_SHIM(ICollectionViewGroup)->get_GroupItems(put_abi(value)));
    return value;
}

template <typename D> int32_t impl_IItemIndexRange<D>::FirstIndex() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IItemIndexRange)->get_FirstIndex(&value));
    return value;
}

template <typename D> uint32_t impl_IItemIndexRange<D>::Length() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IItemIndexRange)->get_Length(&value));
    return value;
}

template <typename D> int32_t impl_IItemIndexRange<D>::LastIndex() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IItemIndexRange)->get_LastIndex(&value));
    return value;
}

template <typename D> Windows::UI::Xaml::Data::ItemIndexRange impl_IItemIndexRangeFactory<D>::CreateInstance(int32_t firstIndex, uint32_t length, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Data::ItemIndexRange instance { nullptr };
    check_hresult(WINRT_SHIM(IItemIndexRangeFactory)->abi_CreateInstance(firstIndex, length, get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::Foundation::IInspectable impl_ICollectionViewSource<D>::Source() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(ICollectionViewSource)->get_Source(put_abi(value)));
    return value;
}

template <typename D> void impl_ICollectionViewSource<D>::Source(const Windows::Foundation::IInspectable & value) const
{
    check_hresult(WINRT_SHIM(ICollectionViewSource)->put_Source(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Data::ICollectionView impl_ICollectionViewSource<D>::View() const
{
    Windows::UI::Xaml::Data::ICollectionView value;
    check_hresult(WINRT_SHIM(ICollectionViewSource)->get_View(put_abi(value)));
    return value;
}

template <typename D> bool impl_ICollectionViewSource<D>::IsSourceGrouped() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICollectionViewSource)->get_IsSourceGrouped(&value));
    return value;
}

template <typename D> void impl_ICollectionViewSource<D>::IsSourceGrouped(bool value) const
{
    check_hresult(WINRT_SHIM(ICollectionViewSource)->put_IsSourceGrouped(value));
}

template <typename D> Windows::UI::Xaml::PropertyPath impl_ICollectionViewSource<D>::ItemsPath() const
{
    Windows::UI::Xaml::PropertyPath value { nullptr };
    check_hresult(WINRT_SHIM(ICollectionViewSource)->get_ItemsPath(put_abi(value)));
    return value;
}

template <typename D> void impl_ICollectionViewSource<D>::ItemsPath(const Windows::UI::Xaml::PropertyPath & value) const
{
    check_hresult(WINRT_SHIM(ICollectionViewSource)->put_ItemsPath(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ICollectionViewSourceStatics<D>::SourceProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ICollectionViewSourceStatics)->get_SourceProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ICollectionViewSourceStatics<D>::ViewProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ICollectionViewSourceStatics)->get_ViewProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ICollectionViewSourceStatics<D>::IsSourceGroupedProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ICollectionViewSourceStatics)->get_IsSourceGroupedProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ICollectionViewSourceStatics<D>::ItemsPathProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ICollectionViewSourceStatics)->get_ItemsPathProperty(put_abi(value)));
    return value;
}

inline Binding::Binding()
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<Binding, IBindingFactory>().CreateInstance(outer, inner));
}

inline BindingBase::BindingBase()
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<BindingBase, IBindingBaseFactory>().CreateInstance(outer, inner));
}

inline void BindingOperations::SetBinding(const Windows::UI::Xaml::DependencyObject & target, const Windows::UI::Xaml::DependencyProperty & dp, const Windows::UI::Xaml::Data::BindingBase & binding)
{
    get_activation_factory<BindingOperations, IBindingOperationsStatics>().SetBinding(target, dp, binding);
}

inline CollectionViewSource::CollectionViewSource() :
    CollectionViewSource(activate_instance<CollectionViewSource>())
{}

inline Windows::UI::Xaml::DependencyProperty CollectionViewSource::SourceProperty()
{
    return get_activation_factory<CollectionViewSource, ICollectionViewSourceStatics>().SourceProperty();
}

inline Windows::UI::Xaml::DependencyProperty CollectionViewSource::ViewProperty()
{
    return get_activation_factory<CollectionViewSource, ICollectionViewSourceStatics>().ViewProperty();
}

inline Windows::UI::Xaml::DependencyProperty CollectionViewSource::IsSourceGroupedProperty()
{
    return get_activation_factory<CollectionViewSource, ICollectionViewSourceStatics>().IsSourceGroupedProperty();
}

inline Windows::UI::Xaml::DependencyProperty CollectionViewSource::ItemsPathProperty()
{
    return get_activation_factory<CollectionViewSource, ICollectionViewSourceStatics>().ItemsPathProperty();
}

inline CurrentChangingEventArgs::CurrentChangingEventArgs()
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<CurrentChangingEventArgs, ICurrentChangingEventArgsFactory>().CreateInstance(outer, inner));
}

inline CurrentChangingEventArgs::CurrentChangingEventArgs(bool isCancelable)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<CurrentChangingEventArgs, ICurrentChangingEventArgsFactory>().CreateWithCancelableParameter(isCancelable, outer, inner));
}

inline ItemIndexRange::ItemIndexRange(int32_t firstIndex, uint32_t length)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<ItemIndexRange, IItemIndexRangeFactory>().CreateInstance(firstIndex, length, outer, inner));
}

inline PropertyChangedEventArgs::PropertyChangedEventArgs(hstring_view name)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<PropertyChangedEventArgs, IPropertyChangedEventArgsFactory>().CreateInstance(name, outer, inner));
}

inline RelativeSource::RelativeSource()
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<RelativeSource, IRelativeSourceFactory>().CreateInstance(outer, inner));
}

}

}
#pragma warning(pop)
