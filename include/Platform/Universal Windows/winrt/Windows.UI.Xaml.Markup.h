// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.UI.Xaml.Interop.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.UI.Xaml.3.h"
#include "internal/Windows.UI.Xaml.Markup.3.h"
#include "Windows.UI.Xaml.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::UI::Xaml::Markup::IComponentConnector> : produce_base<D, Windows::UI::Xaml::Markup::IComponentConnector>
{
    HRESULT __stdcall abi_Connect(int32_t connectionId, impl::abi_arg_in<Windows::Foundation::IInspectable> target) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Connect(connectionId, *reinterpret_cast<const Windows::Foundation::IInspectable *>(&target));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Markup::IComponentConnector2> : produce_base<D, Windows::UI::Xaml::Markup::IComponentConnector2>
{
    HRESULT __stdcall abi_GetBindingConnector(int32_t connectionId, impl::abi_arg_in<Windows::Foundation::IInspectable> target, impl::abi_arg_out<Windows::UI::Xaml::Markup::IComponentConnector> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetBindingConnector(connectionId, *reinterpret_cast<const Windows::Foundation::IInspectable *>(&target)));
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
struct produce<D, Windows::UI::Xaml::Markup::IDataTemplateComponent> : produce_base<D, Windows::UI::Xaml::Markup::IDataTemplateComponent>
{
    HRESULT __stdcall abi_Recycle() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Recycle();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ProcessBindings(impl::abi_arg_in<Windows::Foundation::IInspectable> item, int32_t itemIndex, int32_t phase, int32_t * nextPhase) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProcessBindings(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&item), itemIndex, phase, *nextPhase);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Markup::IXamlBinaryWriter> : produce_base<D, Windows::UI::Xaml::Markup::IXamlBinaryWriter>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Markup::IXamlBinaryWriterStatics> : produce_base<D, Windows::UI::Xaml::Markup::IXamlBinaryWriterStatics>
{
    HRESULT __stdcall abi_Write(impl::abi_arg_in<Windows::Foundation::Collections::IVector<Windows::Storage::Streams::IRandomAccessStream>> inputStreams, impl::abi_arg_in<Windows::Foundation::Collections::IVector<Windows::Storage::Streams::IRandomAccessStream>> outputStreams, impl::abi_arg_in<Windows::UI::Xaml::Markup::IXamlMetadataProvider> xamlMetadataProvider, impl::abi_arg_out<Windows::UI::Xaml::Markup::XamlBinaryWriterErrorInformation> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().Write(*reinterpret_cast<const Windows::Foundation::Collections::IVector<Windows::Storage::Streams::IRandomAccessStream> *>(&inputStreams), *reinterpret_cast<const Windows::Foundation::Collections::IVector<Windows::Storage::Streams::IRandomAccessStream> *>(&outputStreams), *reinterpret_cast<const Windows::UI::Xaml::Markup::IXamlMetadataProvider *>(&xamlMetadataProvider)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Markup::IXamlBindingHelper> : produce_base<D, Windows::UI::Xaml::Markup::IXamlBindingHelper>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Markup::IXamlBindingHelperStatics> : produce_base<D, Windows::UI::Xaml::Markup::IXamlBindingHelperStatics>
{
    HRESULT __stdcall get_DataTemplateComponentProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DataTemplateComponentProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDataTemplateComponent(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, impl::abi_arg_out<Windows::UI::Xaml::Markup::IDataTemplateComponent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDataTemplateComponent(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetDataTemplateComponent(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> element, impl::abi_arg_in<Windows::UI::Xaml::Markup::IDataTemplateComponent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetDataTemplateComponent(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&element), *reinterpret_cast<const Windows::UI::Xaml::Markup::IDataTemplateComponent *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SuspendRendering(impl::abi_arg_in<Windows::UI::Xaml::IUIElement> target) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SuspendRendering(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&target));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ResumeRendering(impl::abi_arg_in<Windows::UI::Xaml::IUIElement> target) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ResumeRendering(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&target));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ConvertValue(impl::abi_arg_in<Windows::UI::Xaml::Interop::TypeName> type, impl::abi_arg_in<Windows::Foundation::IInspectable> value, impl::abi_arg_out<Windows::Foundation::IInspectable> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().ConvertValue(*reinterpret_cast<const Windows::UI::Xaml::Interop::TypeName *>(&type), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPropertyFromString(impl::abi_arg_in<Windows::Foundation::IInspectable> dependencyObject, impl::abi_arg_in<Windows::UI::Xaml::IDependencyProperty> propertyToSet, impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPropertyFromString(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&dependencyObject), *reinterpret_cast<const Windows::UI::Xaml::DependencyProperty *>(&propertyToSet), *reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPropertyFromBoolean(impl::abi_arg_in<Windows::Foundation::IInspectable> dependencyObject, impl::abi_arg_in<Windows::UI::Xaml::IDependencyProperty> propertyToSet, bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPropertyFromBoolean(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&dependencyObject), *reinterpret_cast<const Windows::UI::Xaml::DependencyProperty *>(&propertyToSet), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPropertyFromChar16(impl::abi_arg_in<Windows::Foundation::IInspectable> dependencyObject, impl::abi_arg_in<Windows::UI::Xaml::IDependencyProperty> propertyToSet, wchar_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPropertyFromChar16(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&dependencyObject), *reinterpret_cast<const Windows::UI::Xaml::DependencyProperty *>(&propertyToSet), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPropertyFromDateTime(impl::abi_arg_in<Windows::Foundation::IInspectable> dependencyObject, impl::abi_arg_in<Windows::UI::Xaml::IDependencyProperty> propertyToSet, impl::abi_arg_in<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPropertyFromDateTime(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&dependencyObject), *reinterpret_cast<const Windows::UI::Xaml::DependencyProperty *>(&propertyToSet), *reinterpret_cast<const Windows::Foundation::DateTime *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPropertyFromDouble(impl::abi_arg_in<Windows::Foundation::IInspectable> dependencyObject, impl::abi_arg_in<Windows::UI::Xaml::IDependencyProperty> propertyToSet, double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPropertyFromDouble(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&dependencyObject), *reinterpret_cast<const Windows::UI::Xaml::DependencyProperty *>(&propertyToSet), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPropertyFromInt32(impl::abi_arg_in<Windows::Foundation::IInspectable> dependencyObject, impl::abi_arg_in<Windows::UI::Xaml::IDependencyProperty> propertyToSet, int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPropertyFromInt32(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&dependencyObject), *reinterpret_cast<const Windows::UI::Xaml::DependencyProperty *>(&propertyToSet), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPropertyFromUInt32(impl::abi_arg_in<Windows::Foundation::IInspectable> dependencyObject, impl::abi_arg_in<Windows::UI::Xaml::IDependencyProperty> propertyToSet, uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPropertyFromUInt32(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&dependencyObject), *reinterpret_cast<const Windows::UI::Xaml::DependencyProperty *>(&propertyToSet), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPropertyFromInt64(impl::abi_arg_in<Windows::Foundation::IInspectable> dependencyObject, impl::abi_arg_in<Windows::UI::Xaml::IDependencyProperty> propertyToSet, int64_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPropertyFromInt64(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&dependencyObject), *reinterpret_cast<const Windows::UI::Xaml::DependencyProperty *>(&propertyToSet), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPropertyFromUInt64(impl::abi_arg_in<Windows::Foundation::IInspectable> dependencyObject, impl::abi_arg_in<Windows::UI::Xaml::IDependencyProperty> propertyToSet, uint64_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPropertyFromUInt64(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&dependencyObject), *reinterpret_cast<const Windows::UI::Xaml::DependencyProperty *>(&propertyToSet), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPropertyFromSingle(impl::abi_arg_in<Windows::Foundation::IInspectable> dependencyObject, impl::abi_arg_in<Windows::UI::Xaml::IDependencyProperty> propertyToSet, float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPropertyFromSingle(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&dependencyObject), *reinterpret_cast<const Windows::UI::Xaml::DependencyProperty *>(&propertyToSet), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPropertyFromPoint(impl::abi_arg_in<Windows::Foundation::IInspectable> dependencyObject, impl::abi_arg_in<Windows::UI::Xaml::IDependencyProperty> propertyToSet, impl::abi_arg_in<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPropertyFromPoint(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&dependencyObject), *reinterpret_cast<const Windows::UI::Xaml::DependencyProperty *>(&propertyToSet), *reinterpret_cast<const Windows::Foundation::Point *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPropertyFromRect(impl::abi_arg_in<Windows::Foundation::IInspectable> dependencyObject, impl::abi_arg_in<Windows::UI::Xaml::IDependencyProperty> propertyToSet, impl::abi_arg_in<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPropertyFromRect(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&dependencyObject), *reinterpret_cast<const Windows::UI::Xaml::DependencyProperty *>(&propertyToSet), *reinterpret_cast<const Windows::Foundation::Rect *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPropertyFromSize(impl::abi_arg_in<Windows::Foundation::IInspectable> dependencyObject, impl::abi_arg_in<Windows::UI::Xaml::IDependencyProperty> propertyToSet, impl::abi_arg_in<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPropertyFromSize(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&dependencyObject), *reinterpret_cast<const Windows::UI::Xaml::DependencyProperty *>(&propertyToSet), *reinterpret_cast<const Windows::Foundation::Size *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPropertyFromTimeSpan(impl::abi_arg_in<Windows::Foundation::IInspectable> dependencyObject, impl::abi_arg_in<Windows::UI::Xaml::IDependencyProperty> propertyToSet, impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPropertyFromTimeSpan(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&dependencyObject), *reinterpret_cast<const Windows::UI::Xaml::DependencyProperty *>(&propertyToSet), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPropertyFromByte(impl::abi_arg_in<Windows::Foundation::IInspectable> dependencyObject, impl::abi_arg_in<Windows::UI::Xaml::IDependencyProperty> propertyToSet, uint8_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPropertyFromByte(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&dependencyObject), *reinterpret_cast<const Windows::UI::Xaml::DependencyProperty *>(&propertyToSet), value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPropertyFromUri(impl::abi_arg_in<Windows::Foundation::IInspectable> dependencyObject, impl::abi_arg_in<Windows::UI::Xaml::IDependencyProperty> propertyToSet, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPropertyFromUri(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&dependencyObject), *reinterpret_cast<const Windows::UI::Xaml::DependencyProperty *>(&propertyToSet), *reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPropertyFromObject(impl::abi_arg_in<Windows::Foundation::IInspectable> dependencyObject, impl::abi_arg_in<Windows::UI::Xaml::IDependencyProperty> propertyToSet, impl::abi_arg_in<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPropertyFromObject(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&dependencyObject), *reinterpret_cast<const Windows::UI::Xaml::DependencyProperty *>(&propertyToSet), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Markup::IXamlMember> : produce_base<D, Windows::UI::Xaml::Markup::IXamlMember>
{
    HRESULT __stdcall get_IsAttachable(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsAttachable());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsDependencyProperty(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDependencyProperty());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsReadOnly(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsReadOnly());
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

    HRESULT __stdcall get_TargetType(impl::abi_arg_out<Windows::UI::Xaml::Markup::IXamlType> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetType());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Type(impl::abi_arg_out<Windows::UI::Xaml::Markup::IXamlType> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Type());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetValue(impl::abi_arg_in<Windows::Foundation::IInspectable> instance, impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetValue(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&instance)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetValue(impl::abi_arg_in<Windows::Foundation::IInspectable> instance, impl::abi_arg_in<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetValue(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&instance), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Markup::IXamlMetadataProvider> : produce_base<D, Windows::UI::Xaml::Markup::IXamlMetadataProvider>
{
    HRESULT __stdcall abi_GetXamlType(impl::abi_arg_in<Windows::UI::Xaml::Interop::TypeName> type, impl::abi_arg_out<Windows::UI::Xaml::Markup::IXamlType> xamlType) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *xamlType = detach_abi(this->shim().GetXamlType(*reinterpret_cast<const Windows::UI::Xaml::Interop::TypeName *>(&type)));
            return S_OK;
        }
        catch (...)
        {
            *xamlType = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetXamlTypeByFullName(impl::abi_arg_in<hstring> fullName, impl::abi_arg_out<Windows::UI::Xaml::Markup::IXamlType> xamlType) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *xamlType = detach_abi(this->shim().GetXamlType(*reinterpret_cast<const hstring *>(&fullName)));
            return S_OK;
        }
        catch (...)
        {
            *xamlType = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetXmlnsDefinitions(uint32_t * __definitionsSize, impl::abi_arg_out<Windows::UI::Xaml::Markup::XmlnsDefinition> * definitions) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            std::tie(*__definitionsSize, *definitions) = detach_abi(this->shim().GetXmlnsDefinitions());
            return S_OK;
        }
        catch (...)
        {
            *__definitionsSize = 0;
            *definitions = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Markup::IXamlReader> : produce_base<D, Windows::UI::Xaml::Markup::IXamlReader>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Markup::IXamlReaderStatics> : produce_base<D, Windows::UI::Xaml::Markup::IXamlReaderStatics>
{
    HRESULT __stdcall abi_Load(impl::abi_arg_in<hstring> xaml, impl::abi_arg_out<Windows::Foundation::IInspectable> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().Load(*reinterpret_cast<const hstring *>(&xaml)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LoadWithInitialTemplateValidation(impl::abi_arg_in<hstring> xaml, impl::abi_arg_out<Windows::Foundation::IInspectable> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().LoadWithInitialTemplateValidation(*reinterpret_cast<const hstring *>(&xaml)));
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
struct produce<D, Windows::UI::Xaml::Markup::IXamlType> : produce_base<D, Windows::UI::Xaml::Markup::IXamlType>
{
    HRESULT __stdcall get_BaseType(impl::abi_arg_out<Windows::UI::Xaml::Markup::IXamlType> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BaseType());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContentProperty(impl::abi_arg_out<Windows::UI::Xaml::Markup::IXamlMember> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FullName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FullName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsArray(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsArray());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsCollection(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsCollection());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsConstructible(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsConstructible());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsDictionary(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDictionary());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsMarkupExtension(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsMarkupExtension());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsBindable(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsBindable());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ItemType(impl::abi_arg_out<Windows::UI::Xaml::Markup::IXamlType> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ItemType());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KeyType(impl::abi_arg_out<Windows::UI::Xaml::Markup::IXamlType> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeyType());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UnderlyingType(impl::abi_arg_out<Windows::UI::Xaml::Interop::TypeName> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UnderlyingType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ActivateInstance(impl::abi_arg_out<Windows::Foundation::IInspectable> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().ActivateInstance());
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromString(impl::abi_arg_in<hstring> value, impl::abi_arg_out<Windows::Foundation::IInspectable> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateFromString(*reinterpret_cast<const hstring *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetMember(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::UI::Xaml::Markup::IXamlMember> xamlMember) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *xamlMember = detach_abi(this->shim().GetMember(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *xamlMember = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddToVector(impl::abi_arg_in<Windows::Foundation::IInspectable> instance, impl::abi_arg_in<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddToVector(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&instance), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddToMap(impl::abi_arg_in<Windows::Foundation::IInspectable> instance, impl::abi_arg_in<Windows::Foundation::IInspectable> key, impl::abi_arg_in<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddToMap(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&instance), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&key), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RunInitializer() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RunInitializer();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::UI::Xaml::Markup {

template <typename D> void impl_IComponentConnector<D>::Connect(int32_t connectionId, const Windows::Foundation::IInspectable & target) const
{
    check_hresult(WINRT_SHIM(IComponentConnector)->abi_Connect(connectionId, get_abi(target)));
}

template <typename D> Windows::UI::Xaml::Markup::IComponentConnector impl_IComponentConnector2<D>::GetBindingConnector(int32_t connectionId, const Windows::Foundation::IInspectable & target) const
{
    Windows::UI::Xaml::Markup::IComponentConnector returnValue;
    check_hresult(WINRT_SHIM(IComponentConnector2)->abi_GetBindingConnector(connectionId, get_abi(target), put_abi(returnValue)));
    return returnValue;
}

template <typename D> bool impl_IXamlMember<D>::IsAttachable() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IXamlMember)->get_IsAttachable(&value));
    return value;
}

template <typename D> bool impl_IXamlMember<D>::IsDependencyProperty() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IXamlMember)->get_IsDependencyProperty(&value));
    return value;
}

template <typename D> bool impl_IXamlMember<D>::IsReadOnly() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IXamlMember)->get_IsReadOnly(&value));
    return value;
}

template <typename D> hstring impl_IXamlMember<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IXamlMember)->get_Name(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Markup::IXamlType impl_IXamlMember<D>::TargetType() const
{
    Windows::UI::Xaml::Markup::IXamlType value;
    check_hresult(WINRT_SHIM(IXamlMember)->get_TargetType(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Markup::IXamlType impl_IXamlMember<D>::Type() const
{
    Windows::UI::Xaml::Markup::IXamlType value;
    check_hresult(WINRT_SHIM(IXamlMember)->get_Type(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IInspectable impl_IXamlMember<D>::GetValue(const Windows::Foundation::IInspectable & instance) const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IXamlMember)->abi_GetValue(get_abi(instance), put_abi(value)));
    return value;
}

template <typename D> void impl_IXamlMember<D>::SetValue(const Windows::Foundation::IInspectable & instance, const Windows::Foundation::IInspectable & value) const
{
    check_hresult(WINRT_SHIM(IXamlMember)->abi_SetValue(get_abi(instance), get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Markup::IXamlType impl_IXamlType<D>::BaseType() const
{
    Windows::UI::Xaml::Markup::IXamlType value;
    check_hresult(WINRT_SHIM(IXamlType)->get_BaseType(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Markup::IXamlMember impl_IXamlType<D>::ContentProperty() const
{
    Windows::UI::Xaml::Markup::IXamlMember value;
    check_hresult(WINRT_SHIM(IXamlType)->get_ContentProperty(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IXamlType<D>::FullName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IXamlType)->get_FullName(put_abi(value)));
    return value;
}

template <typename D> bool impl_IXamlType<D>::IsArray() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IXamlType)->get_IsArray(&value));
    return value;
}

template <typename D> bool impl_IXamlType<D>::IsCollection() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IXamlType)->get_IsCollection(&value));
    return value;
}

template <typename D> bool impl_IXamlType<D>::IsConstructible() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IXamlType)->get_IsConstructible(&value));
    return value;
}

template <typename D> bool impl_IXamlType<D>::IsDictionary() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IXamlType)->get_IsDictionary(&value));
    return value;
}

template <typename D> bool impl_IXamlType<D>::IsMarkupExtension() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IXamlType)->get_IsMarkupExtension(&value));
    return value;
}

template <typename D> bool impl_IXamlType<D>::IsBindable() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IXamlType)->get_IsBindable(&value));
    return value;
}

template <typename D> Windows::UI::Xaml::Markup::IXamlType impl_IXamlType<D>::ItemType() const
{
    Windows::UI::Xaml::Markup::IXamlType value;
    check_hresult(WINRT_SHIM(IXamlType)->get_ItemType(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Markup::IXamlType impl_IXamlType<D>::KeyType() const
{
    Windows::UI::Xaml::Markup::IXamlType value;
    check_hresult(WINRT_SHIM(IXamlType)->get_KeyType(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Interop::TypeName impl_IXamlType<D>::UnderlyingType() const
{
    Windows::UI::Xaml::Interop::TypeName value {};
    check_hresult(WINRT_SHIM(IXamlType)->get_UnderlyingType(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IInspectable impl_IXamlType<D>::ActivateInstance() const
{
    Windows::Foundation::IInspectable instance;
    check_hresult(WINRT_SHIM(IXamlType)->abi_ActivateInstance(put_abi(instance)));
    return instance;
}

template <typename D> Windows::Foundation::IInspectable impl_IXamlType<D>::CreateFromString(hstring_view value) const
{
    Windows::Foundation::IInspectable instance;
    check_hresult(WINRT_SHIM(IXamlType)->abi_CreateFromString(get_abi(value), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Markup::IXamlMember impl_IXamlType<D>::GetMember(hstring_view name) const
{
    Windows::UI::Xaml::Markup::IXamlMember xamlMember;
    check_hresult(WINRT_SHIM(IXamlType)->abi_GetMember(get_abi(name), put_abi(xamlMember)));
    return xamlMember;
}

template <typename D> void impl_IXamlType<D>::AddToVector(const Windows::Foundation::IInspectable & instance, const Windows::Foundation::IInspectable & value) const
{
    check_hresult(WINRT_SHIM(IXamlType)->abi_AddToVector(get_abi(instance), get_abi(value)));
}

template <typename D> void impl_IXamlType<D>::AddToMap(const Windows::Foundation::IInspectable & instance, const Windows::Foundation::IInspectable & key, const Windows::Foundation::IInspectable & value) const
{
    check_hresult(WINRT_SHIM(IXamlType)->abi_AddToMap(get_abi(instance), get_abi(key), get_abi(value)));
}

template <typename D> void impl_IXamlType<D>::RunInitializer() const
{
    check_hresult(WINRT_SHIM(IXamlType)->abi_RunInitializer());
}

template <typename D> Windows::UI::Xaml::Markup::IXamlType impl_IXamlMetadataProvider<D>::GetXamlType(const Windows::UI::Xaml::Interop::TypeName & type) const
{
    Windows::UI::Xaml::Markup::IXamlType xamlType;
    check_hresult(WINRT_SHIM(IXamlMetadataProvider)->abi_GetXamlType(get_abi(type), put_abi(xamlType)));
    return xamlType;
}

template <typename D> Windows::UI::Xaml::Markup::IXamlType impl_IXamlMetadataProvider<D>::GetXamlType(hstring_view fullName) const
{
    Windows::UI::Xaml::Markup::IXamlType xamlType;
    check_hresult(WINRT_SHIM(IXamlMetadataProvider)->abi_GetXamlTypeByFullName(get_abi(fullName), put_abi(xamlType)));
    return xamlType;
}

template <typename D> com_array<Windows::UI::Xaml::Markup::XmlnsDefinition> impl_IXamlMetadataProvider<D>::GetXmlnsDefinitions() const
{
    com_array<Windows::UI::Xaml::Markup::XmlnsDefinition> definitions {};
    check_hresult(WINRT_SHIM(IXamlMetadataProvider)->abi_GetXmlnsDefinitions(impl::put_size_abi(definitions), put_abi(definitions)));
    return definitions;
}

template <typename D> Windows::UI::Xaml::Markup::XamlBinaryWriterErrorInformation impl_IXamlBinaryWriterStatics<D>::Write(const Windows::Foundation::Collections::IVector<Windows::Storage::Streams::IRandomAccessStream> & inputStreams, const Windows::Foundation::Collections::IVector<Windows::Storage::Streams::IRandomAccessStream> & outputStreams, const Windows::UI::Xaml::Markup::IXamlMetadataProvider & xamlMetadataProvider) const
{
    Windows::UI::Xaml::Markup::XamlBinaryWriterErrorInformation returnValue {};
    check_hresult(WINRT_SHIM(IXamlBinaryWriterStatics)->abi_Write(get_abi(inputStreams), get_abi(outputStreams), get_abi(xamlMetadataProvider), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IInspectable impl_IXamlReaderStatics<D>::Load(hstring_view xaml) const
{
    Windows::Foundation::IInspectable returnValue;
    check_hresult(WINRT_SHIM(IXamlReaderStatics)->abi_Load(get_abi(xaml), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IInspectable impl_IXamlReaderStatics<D>::LoadWithInitialTemplateValidation(hstring_view xaml) const
{
    Windows::Foundation::IInspectable returnValue;
    check_hresult(WINRT_SHIM(IXamlReaderStatics)->abi_LoadWithInitialTemplateValidation(get_abi(xaml), put_abi(returnValue)));
    return returnValue;
}

template <typename D> void impl_IDataTemplateComponent<D>::Recycle() const
{
    check_hresult(WINRT_SHIM(IDataTemplateComponent)->abi_Recycle());
}

template <typename D> void impl_IDataTemplateComponent<D>::ProcessBindings(const Windows::Foundation::IInspectable & item, int32_t itemIndex, int32_t phase, int32_t & nextPhase) const
{
    check_hresult(WINRT_SHIM(IDataTemplateComponent)->abi_ProcessBindings(get_abi(item), itemIndex, phase, &nextPhase));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IXamlBindingHelperStatics<D>::DataTemplateComponentProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IXamlBindingHelperStatics)->get_DataTemplateComponentProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Markup::IDataTemplateComponent impl_IXamlBindingHelperStatics<D>::GetDataTemplateComponent(const Windows::UI::Xaml::DependencyObject & element) const
{
    Windows::UI::Xaml::Markup::IDataTemplateComponent value;
    check_hresult(WINRT_SHIM(IXamlBindingHelperStatics)->abi_GetDataTemplateComponent(get_abi(element), put_abi(value)));
    return value;
}

template <typename D> void impl_IXamlBindingHelperStatics<D>::SetDataTemplateComponent(const Windows::UI::Xaml::DependencyObject & element, const Windows::UI::Xaml::Markup::IDataTemplateComponent & value) const
{
    check_hresult(WINRT_SHIM(IXamlBindingHelperStatics)->abi_SetDataTemplateComponent(get_abi(element), get_abi(value)));
}

template <typename D> void impl_IXamlBindingHelperStatics<D>::SuspendRendering(const Windows::UI::Xaml::UIElement & target) const
{
    check_hresult(WINRT_SHIM(IXamlBindingHelperStatics)->abi_SuspendRendering(get_abi(target)));
}

template <typename D> void impl_IXamlBindingHelperStatics<D>::ResumeRendering(const Windows::UI::Xaml::UIElement & target) const
{
    check_hresult(WINRT_SHIM(IXamlBindingHelperStatics)->abi_ResumeRendering(get_abi(target)));
}

template <typename D> Windows::Foundation::IInspectable impl_IXamlBindingHelperStatics<D>::ConvertValue(const Windows::UI::Xaml::Interop::TypeName & type, const Windows::Foundation::IInspectable & value) const
{
    Windows::Foundation::IInspectable returnValue;
    check_hresult(WINRT_SHIM(IXamlBindingHelperStatics)->abi_ConvertValue(get_abi(type), get_abi(value), put_abi(returnValue)));
    return returnValue;
}

template <typename D> void impl_IXamlBindingHelperStatics<D>::SetPropertyFromString(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, hstring_view value) const
{
    check_hresult(WINRT_SHIM(IXamlBindingHelperStatics)->abi_SetPropertyFromString(get_abi(dependencyObject), get_abi(propertyToSet), get_abi(value)));
}

template <typename D> void impl_IXamlBindingHelperStatics<D>::SetPropertyFromBoolean(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, bool value) const
{
    check_hresult(WINRT_SHIM(IXamlBindingHelperStatics)->abi_SetPropertyFromBoolean(get_abi(dependencyObject), get_abi(propertyToSet), value));
}

template <typename D> void impl_IXamlBindingHelperStatics<D>::SetPropertyFromChar16(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, wchar_t value) const
{
    check_hresult(WINRT_SHIM(IXamlBindingHelperStatics)->abi_SetPropertyFromChar16(get_abi(dependencyObject), get_abi(propertyToSet), value));
}

template <typename D> void impl_IXamlBindingHelperStatics<D>::SetPropertyFromDateTime(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, const Windows::Foundation::DateTime & value) const
{
    check_hresult(WINRT_SHIM(IXamlBindingHelperStatics)->abi_SetPropertyFromDateTime(get_abi(dependencyObject), get_abi(propertyToSet), get_abi(value)));
}

template <typename D> void impl_IXamlBindingHelperStatics<D>::SetPropertyFromDouble(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, double value) const
{
    check_hresult(WINRT_SHIM(IXamlBindingHelperStatics)->abi_SetPropertyFromDouble(get_abi(dependencyObject), get_abi(propertyToSet), value));
}

template <typename D> void impl_IXamlBindingHelperStatics<D>::SetPropertyFromInt32(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, int32_t value) const
{
    check_hresult(WINRT_SHIM(IXamlBindingHelperStatics)->abi_SetPropertyFromInt32(get_abi(dependencyObject), get_abi(propertyToSet), value));
}

template <typename D> void impl_IXamlBindingHelperStatics<D>::SetPropertyFromUInt32(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, uint32_t value) const
{
    check_hresult(WINRT_SHIM(IXamlBindingHelperStatics)->abi_SetPropertyFromUInt32(get_abi(dependencyObject), get_abi(propertyToSet), value));
}

template <typename D> void impl_IXamlBindingHelperStatics<D>::SetPropertyFromInt64(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, int64_t value) const
{
    check_hresult(WINRT_SHIM(IXamlBindingHelperStatics)->abi_SetPropertyFromInt64(get_abi(dependencyObject), get_abi(propertyToSet), value));
}

template <typename D> void impl_IXamlBindingHelperStatics<D>::SetPropertyFromUInt64(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, uint64_t value) const
{
    check_hresult(WINRT_SHIM(IXamlBindingHelperStatics)->abi_SetPropertyFromUInt64(get_abi(dependencyObject), get_abi(propertyToSet), value));
}

template <typename D> void impl_IXamlBindingHelperStatics<D>::SetPropertyFromSingle(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, float value) const
{
    check_hresult(WINRT_SHIM(IXamlBindingHelperStatics)->abi_SetPropertyFromSingle(get_abi(dependencyObject), get_abi(propertyToSet), value));
}

template <typename D> void impl_IXamlBindingHelperStatics<D>::SetPropertyFromPoint(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, const Windows::Foundation::Point & value) const
{
    check_hresult(WINRT_SHIM(IXamlBindingHelperStatics)->abi_SetPropertyFromPoint(get_abi(dependencyObject), get_abi(propertyToSet), get_abi(value)));
}

template <typename D> void impl_IXamlBindingHelperStatics<D>::SetPropertyFromRect(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, const Windows::Foundation::Rect & value) const
{
    check_hresult(WINRT_SHIM(IXamlBindingHelperStatics)->abi_SetPropertyFromRect(get_abi(dependencyObject), get_abi(propertyToSet), get_abi(value)));
}

template <typename D> void impl_IXamlBindingHelperStatics<D>::SetPropertyFromSize(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, const Windows::Foundation::Size & value) const
{
    check_hresult(WINRT_SHIM(IXamlBindingHelperStatics)->abi_SetPropertyFromSize(get_abi(dependencyObject), get_abi(propertyToSet), get_abi(value)));
}

template <typename D> void impl_IXamlBindingHelperStatics<D>::SetPropertyFromTimeSpan(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(IXamlBindingHelperStatics)->abi_SetPropertyFromTimeSpan(get_abi(dependencyObject), get_abi(propertyToSet), get_abi(value)));
}

template <typename D> void impl_IXamlBindingHelperStatics<D>::SetPropertyFromByte(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, uint8_t value) const
{
    check_hresult(WINRT_SHIM(IXamlBindingHelperStatics)->abi_SetPropertyFromByte(get_abi(dependencyObject), get_abi(propertyToSet), value));
}

template <typename D> void impl_IXamlBindingHelperStatics<D>::SetPropertyFromUri(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(IXamlBindingHelperStatics)->abi_SetPropertyFromUri(get_abi(dependencyObject), get_abi(propertyToSet), get_abi(value)));
}

template <typename D> void impl_IXamlBindingHelperStatics<D>::SetPropertyFromObject(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, const Windows::Foundation::IInspectable & value) const
{
    check_hresult(WINRT_SHIM(IXamlBindingHelperStatics)->abi_SetPropertyFromObject(get_abi(dependencyObject), get_abi(propertyToSet), get_abi(value)));
}

inline Windows::UI::Xaml::Markup::XamlBinaryWriterErrorInformation XamlBinaryWriter::Write(const Windows::Foundation::Collections::IVector<Windows::Storage::Streams::IRandomAccessStream> & inputStreams, const Windows::Foundation::Collections::IVector<Windows::Storage::Streams::IRandomAccessStream> & outputStreams, const Windows::UI::Xaml::Markup::IXamlMetadataProvider & xamlMetadataProvider)
{
    return get_activation_factory<XamlBinaryWriter, IXamlBinaryWriterStatics>().Write(inputStreams, outputStreams, xamlMetadataProvider);
}

inline Windows::UI::Xaml::DependencyProperty XamlBindingHelper::DataTemplateComponentProperty()
{
    return get_activation_factory<XamlBindingHelper, IXamlBindingHelperStatics>().DataTemplateComponentProperty();
}

inline Windows::UI::Xaml::Markup::IDataTemplateComponent XamlBindingHelper::GetDataTemplateComponent(const Windows::UI::Xaml::DependencyObject & element)
{
    return get_activation_factory<XamlBindingHelper, IXamlBindingHelperStatics>().GetDataTemplateComponent(element);
}

inline void XamlBindingHelper::SetDataTemplateComponent(const Windows::UI::Xaml::DependencyObject & element, const Windows::UI::Xaml::Markup::IDataTemplateComponent & value)
{
    get_activation_factory<XamlBindingHelper, IXamlBindingHelperStatics>().SetDataTemplateComponent(element, value);
}

inline void XamlBindingHelper::SuspendRendering(const Windows::UI::Xaml::UIElement & target)
{
    get_activation_factory<XamlBindingHelper, IXamlBindingHelperStatics>().SuspendRendering(target);
}

inline void XamlBindingHelper::ResumeRendering(const Windows::UI::Xaml::UIElement & target)
{
    get_activation_factory<XamlBindingHelper, IXamlBindingHelperStatics>().ResumeRendering(target);
}

inline Windows::Foundation::IInspectable XamlBindingHelper::ConvertValue(const Windows::UI::Xaml::Interop::TypeName & type, const Windows::Foundation::IInspectable & value)
{
    return get_activation_factory<XamlBindingHelper, IXamlBindingHelperStatics>().ConvertValue(type, value);
}

inline void XamlBindingHelper::SetPropertyFromString(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, hstring_view value)
{
    get_activation_factory<XamlBindingHelper, IXamlBindingHelperStatics>().SetPropertyFromString(dependencyObject, propertyToSet, value);
}

inline void XamlBindingHelper::SetPropertyFromBoolean(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, bool value)
{
    get_activation_factory<XamlBindingHelper, IXamlBindingHelperStatics>().SetPropertyFromBoolean(dependencyObject, propertyToSet, value);
}

inline void XamlBindingHelper::SetPropertyFromChar16(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, wchar_t value)
{
    get_activation_factory<XamlBindingHelper, IXamlBindingHelperStatics>().SetPropertyFromChar16(dependencyObject, propertyToSet, value);
}

inline void XamlBindingHelper::SetPropertyFromDateTime(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, const Windows::Foundation::DateTime & value)
{
    get_activation_factory<XamlBindingHelper, IXamlBindingHelperStatics>().SetPropertyFromDateTime(dependencyObject, propertyToSet, value);
}

inline void XamlBindingHelper::SetPropertyFromDouble(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, double value)
{
    get_activation_factory<XamlBindingHelper, IXamlBindingHelperStatics>().SetPropertyFromDouble(dependencyObject, propertyToSet, value);
}

inline void XamlBindingHelper::SetPropertyFromInt32(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, int32_t value)
{
    get_activation_factory<XamlBindingHelper, IXamlBindingHelperStatics>().SetPropertyFromInt32(dependencyObject, propertyToSet, value);
}

inline void XamlBindingHelper::SetPropertyFromUInt32(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, uint32_t value)
{
    get_activation_factory<XamlBindingHelper, IXamlBindingHelperStatics>().SetPropertyFromUInt32(dependencyObject, propertyToSet, value);
}

inline void XamlBindingHelper::SetPropertyFromInt64(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, int64_t value)
{
    get_activation_factory<XamlBindingHelper, IXamlBindingHelperStatics>().SetPropertyFromInt64(dependencyObject, propertyToSet, value);
}

inline void XamlBindingHelper::SetPropertyFromUInt64(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, uint64_t value)
{
    get_activation_factory<XamlBindingHelper, IXamlBindingHelperStatics>().SetPropertyFromUInt64(dependencyObject, propertyToSet, value);
}

inline void XamlBindingHelper::SetPropertyFromSingle(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, float value)
{
    get_activation_factory<XamlBindingHelper, IXamlBindingHelperStatics>().SetPropertyFromSingle(dependencyObject, propertyToSet, value);
}

inline void XamlBindingHelper::SetPropertyFromPoint(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, const Windows::Foundation::Point & value)
{
    get_activation_factory<XamlBindingHelper, IXamlBindingHelperStatics>().SetPropertyFromPoint(dependencyObject, propertyToSet, value);
}

inline void XamlBindingHelper::SetPropertyFromRect(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, const Windows::Foundation::Rect & value)
{
    get_activation_factory<XamlBindingHelper, IXamlBindingHelperStatics>().SetPropertyFromRect(dependencyObject, propertyToSet, value);
}

inline void XamlBindingHelper::SetPropertyFromSize(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, const Windows::Foundation::Size & value)
{
    get_activation_factory<XamlBindingHelper, IXamlBindingHelperStatics>().SetPropertyFromSize(dependencyObject, propertyToSet, value);
}

inline void XamlBindingHelper::SetPropertyFromTimeSpan(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, const Windows::Foundation::TimeSpan & value)
{
    get_activation_factory<XamlBindingHelper, IXamlBindingHelperStatics>().SetPropertyFromTimeSpan(dependencyObject, propertyToSet, value);
}

inline void XamlBindingHelper::SetPropertyFromByte(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, uint8_t value)
{
    get_activation_factory<XamlBindingHelper, IXamlBindingHelperStatics>().SetPropertyFromByte(dependencyObject, propertyToSet, value);
}

inline void XamlBindingHelper::SetPropertyFromUri(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, const Windows::Foundation::Uri & value)
{
    get_activation_factory<XamlBindingHelper, IXamlBindingHelperStatics>().SetPropertyFromUri(dependencyObject, propertyToSet, value);
}

inline void XamlBindingHelper::SetPropertyFromObject(const Windows::Foundation::IInspectable & dependencyObject, const Windows::UI::Xaml::DependencyProperty & propertyToSet, const Windows::Foundation::IInspectable & value)
{
    get_activation_factory<XamlBindingHelper, IXamlBindingHelperStatics>().SetPropertyFromObject(dependencyObject, propertyToSet, value);
}

inline Windows::Foundation::IInspectable XamlReader::Load(hstring_view xaml)
{
    return get_activation_factory<XamlReader, IXamlReaderStatics>().Load(xaml);
}

inline Windows::Foundation::IInspectable XamlReader::LoadWithInitialTemplateValidation(hstring_view xaml)
{
    return get_activation_factory<XamlReader, IXamlReaderStatics>().LoadWithInitialTemplateValidation(xaml);
}

}

}
#pragma warning(pop)
