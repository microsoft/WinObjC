// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.UI.Xaml.Automation.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.UI.3.h"
#include "internal/Windows.UI.Xaml.Automation.Text.3.h"
#include "internal/Windows.UI.Xaml.Automation.Peers.3.h"
#include "internal/Windows.UI.Xaml.Automation.Provider.3.h"
#include "Windows.UI.Xaml.Automation.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Provider::IAnnotationProvider> : produce_base<D, Windows::UI::Xaml::Automation::Provider::IAnnotationProvider>
{
    HRESULT __stdcall get_AnnotationTypeId(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AnnotationTypeId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AnnotationTypeName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AnnotationTypeName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Author(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Author());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DateTime(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DateTime());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Target(impl::abi_arg_out<Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Target());
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
struct produce<D, Windows::UI::Xaml::Automation::Provider::ICustomNavigationProvider> : produce_base<D, Windows::UI::Xaml::Automation::Provider::ICustomNavigationProvider>
{
    HRESULT __stdcall abi_NavigateCustom(Windows::UI::Xaml::Automation::Peers::AutomationNavigationDirection direction, impl::abi_arg_out<Windows::Foundation::IInspectable> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().NavigateCustom(direction));
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
struct produce<D, Windows::UI::Xaml::Automation::Provider::IDockProvider> : produce_base<D, Windows::UI::Xaml::Automation::Provider::IDockProvider>
{
    HRESULT __stdcall get_DockPosition(Windows::UI::Xaml::Automation::DockPosition * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DockPosition());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetDockPosition(Windows::UI::Xaml::Automation::DockPosition dockPosition) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetDockPosition(dockPosition);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Provider::IDragProvider> : produce_base<D, Windows::UI::Xaml::Automation::Provider::IDragProvider>
{
    HRESULT __stdcall get_IsGrabbed(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsGrabbed());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DropEffect(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DropEffect());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DropEffects(uint32_t * __valueSize, impl::abi_arg_out<hstring> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            std::tie(*__valueSize, *value) = detach_abi(this->shim().DropEffects());
            return S_OK;
        }
        catch (...)
        {
            *__valueSize = 0;
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetGrabbedItems(uint32_t * __returnValueSize, impl::abi_arg_out<Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            std::tie(*__returnValueSize, *returnValue) = detach_abi(this->shim().GetGrabbedItems());
            return S_OK;
        }
        catch (...)
        {
            *__returnValueSize = 0;
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Provider::IDropTargetProvider> : produce_base<D, Windows::UI::Xaml::Automation::Provider::IDropTargetProvider>
{
    HRESULT __stdcall get_DropEffect(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DropEffect());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DropEffects(uint32_t * __valueSize, impl::abi_arg_out<hstring> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            std::tie(*__valueSize, *value) = detach_abi(this->shim().DropEffects());
            return S_OK;
        }
        catch (...)
        {
            *__valueSize = 0;
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Provider::IExpandCollapseProvider> : produce_base<D, Windows::UI::Xaml::Automation::Provider::IExpandCollapseProvider>
{
    HRESULT __stdcall get_ExpandCollapseState(Windows::UI::Xaml::Automation::ExpandCollapseState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExpandCollapseState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Collapse() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Collapse();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Expand() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Expand();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Provider::IGridItemProvider> : produce_base<D, Windows::UI::Xaml::Automation::Provider::IGridItemProvider>
{
    HRESULT __stdcall get_Column(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Column());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ColumnSpan(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ColumnSpan());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContainingGrid(impl::abi_arg_out<Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContainingGrid());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Row(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Row());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RowSpan(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RowSpan());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Provider::IGridProvider> : produce_base<D, Windows::UI::Xaml::Automation::Provider::IGridProvider>
{
    HRESULT __stdcall get_ColumnCount(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ColumnCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RowCount(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RowCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetItem(int32_t row, int32_t column, impl::abi_arg_out<Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetItem(row, column));
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
struct produce<D, Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> : produce_base<D, Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Provider::IInvokeProvider> : produce_base<D, Windows::UI::Xaml::Automation::Provider::IInvokeProvider>
{
    HRESULT __stdcall abi_Invoke() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Invoke();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider> : produce_base<D, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider>
{
    HRESULT __stdcall abi_FindItemByProperty(impl::abi_arg_in<Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> startAfter, impl::abi_arg_in<Windows::UI::Xaml::Automation::IAutomationProperty> automationProperty, impl::abi_arg_in<Windows::Foundation::IInspectable> value, impl::abi_arg_out<Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().FindItemByProperty(*reinterpret_cast<const Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple *>(&startAfter), *reinterpret_cast<const Windows::UI::Xaml::Automation::AutomationProperty *>(&automationProperty), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&value)));
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
struct produce<D, Windows::UI::Xaml::Automation::Provider::IMultipleViewProvider> : produce_base<D, Windows::UI::Xaml::Automation::Provider::IMultipleViewProvider>
{
    HRESULT __stdcall get_CurrentView(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CurrentView());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSupportedViews(uint32_t * __returnValueSize, impl::abi_arg_out<int32_t> * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            std::tie(*__returnValueSize, *returnValue) = detach_abi(this->shim().GetSupportedViews());
            return S_OK;
        }
        catch (...)
        {
            *__returnValueSize = 0;
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetViewName(int32_t viewId, impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetViewName(viewId));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetCurrentView(int32_t viewId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetCurrentView(viewId);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Provider::IObjectModelProvider> : produce_base<D, Windows::UI::Xaml::Automation::Provider::IObjectModelProvider>
{
    HRESULT __stdcall abi_GetUnderlyingObjectModel(impl::abi_arg_out<Windows::Foundation::IInspectable> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetUnderlyingObjectModel());
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
struct produce<D, Windows::UI::Xaml::Automation::Provider::IRangeValueProvider> : produce_base<D, Windows::UI::Xaml::Automation::Provider::IRangeValueProvider>
{
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

    HRESULT __stdcall get_LargeChange(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LargeChange());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Maximum(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Maximum());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Minimum(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Minimum());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SmallChange(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SmallChange());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Value(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Value());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetValue(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetValue(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Provider::IScrollItemProvider> : produce_base<D, Windows::UI::Xaml::Automation::Provider::IScrollItemProvider>
{
    HRESULT __stdcall abi_ScrollIntoView() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ScrollIntoView();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Provider::IScrollProvider> : produce_base<D, Windows::UI::Xaml::Automation::Provider::IScrollProvider>
{
    HRESULT __stdcall get_HorizontallyScrollable(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HorizontallyScrollable());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HorizontalScrollPercent(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HorizontalScrollPercent());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HorizontalViewSize(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HorizontalViewSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VerticallyScrollable(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VerticallyScrollable());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VerticalScrollPercent(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VerticalScrollPercent());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VerticalViewSize(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VerticalViewSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Scroll(Windows::UI::Xaml::Automation::ScrollAmount horizontalAmount, Windows::UI::Xaml::Automation::ScrollAmount verticalAmount) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Scroll(horizontalAmount, verticalAmount);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetScrollPercent(double horizontalPercent, double verticalPercent) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetScrollPercent(horizontalPercent, verticalPercent);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider> : produce_base<D, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider>
{
    HRESULT __stdcall get_IsSelected(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsSelected());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SelectionContainer(impl::abi_arg_out<Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SelectionContainer());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddToSelection() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddToSelection();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveFromSelection() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveFromSelection();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Select() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Select();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Provider::ISelectionProvider> : produce_base<D, Windows::UI::Xaml::Automation::Provider::ISelectionProvider>
{
    HRESULT __stdcall get_CanSelectMultiple(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanSelectMultiple());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsSelectionRequired(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsSelectionRequired());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSelection(uint32_t * __returnValueSize, impl::abi_arg_out<Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            std::tie(*__returnValueSize, *returnValue) = detach_abi(this->shim().GetSelection());
            return S_OK;
        }
        catch (...)
        {
            *__returnValueSize = 0;
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Provider::ISpreadsheetItemProvider> : produce_base<D, Windows::UI::Xaml::Automation::Provider::ISpreadsheetItemProvider>
{
    HRESULT __stdcall get_Formula(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Formula());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAnnotationObjects(uint32_t * __returnValueSize, impl::abi_arg_out<Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            std::tie(*__returnValueSize, *returnValue) = detach_abi(this->shim().GetAnnotationObjects());
            return S_OK;
        }
        catch (...)
        {
            *__returnValueSize = 0;
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAnnotationTypes(uint32_t * __returnValueSize, impl::abi_arg_out<Windows::UI::Xaml::Automation::AnnotationType> * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            std::tie(*__returnValueSize, *returnValue) = detach_abi(this->shim().GetAnnotationTypes());
            return S_OK;
        }
        catch (...)
        {
            *__returnValueSize = 0;
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Provider::ISpreadsheetProvider> : produce_base<D, Windows::UI::Xaml::Automation::Provider::ISpreadsheetProvider>
{
    HRESULT __stdcall abi_GetItemByName(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetItemByName(*reinterpret_cast<const hstring *>(&name)));
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
struct produce<D, Windows::UI::Xaml::Automation::Provider::IStylesProvider> : produce_base<D, Windows::UI::Xaml::Automation::Provider::IStylesProvider>
{
    HRESULT __stdcall get_ExtendedProperties(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendedProperties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FillColor(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FillColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FillPatternColor(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FillPatternColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FillPatternStyle(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FillPatternStyle());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Shape(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Shape());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StyleId(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StyleId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StyleName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StyleName());
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
struct produce<D, Windows::UI::Xaml::Automation::Provider::ISynchronizedInputProvider> : produce_base<D, Windows::UI::Xaml::Automation::Provider::ISynchronizedInputProvider>
{
    HRESULT __stdcall abi_Cancel() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Cancel();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartListening(Windows::UI::Xaml::Automation::SynchronizedInputType inputType) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartListening(inputType);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Provider::ITableItemProvider> : produce_base<D, Windows::UI::Xaml::Automation::Provider::ITableItemProvider>
{
    HRESULT __stdcall abi_GetColumnHeaderItems(uint32_t * __returnValueSize, impl::abi_arg_out<Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            std::tie(*__returnValueSize, *returnValue) = detach_abi(this->shim().GetColumnHeaderItems());
            return S_OK;
        }
        catch (...)
        {
            *__returnValueSize = 0;
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetRowHeaderItems(uint32_t * __returnValueSize, impl::abi_arg_out<Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            std::tie(*__returnValueSize, *returnValue) = detach_abi(this->shim().GetRowHeaderItems());
            return S_OK;
        }
        catch (...)
        {
            *__returnValueSize = 0;
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Provider::ITableProvider> : produce_base<D, Windows::UI::Xaml::Automation::Provider::ITableProvider>
{
    HRESULT __stdcall get_RowOrColumnMajor(Windows::UI::Xaml::Automation::RowOrColumnMajor * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RowOrColumnMajor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetColumnHeaders(uint32_t * __returnValueSize, impl::abi_arg_out<Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            std::tie(*__returnValueSize, *returnValue) = detach_abi(this->shim().GetColumnHeaders());
            return S_OK;
        }
        catch (...)
        {
            *__returnValueSize = 0;
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetRowHeaders(uint32_t * __returnValueSize, impl::abi_arg_out<Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            std::tie(*__returnValueSize, *returnValue) = detach_abi(this->shim().GetRowHeaders());
            return S_OK;
        }
        catch (...)
        {
            *__returnValueSize = 0;
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Provider::ITextChildProvider> : produce_base<D, Windows::UI::Xaml::Automation::Provider::ITextChildProvider>
{
    HRESULT __stdcall get_TextContainer(impl::abi_arg_out<Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TextContainer());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TextRange(impl::abi_arg_out<Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TextRange());
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
struct produce<D, Windows::UI::Xaml::Automation::Provider::ITextEditProvider> : produce_base<D, Windows::UI::Xaml::Automation::Provider::ITextEditProvider>
{
    HRESULT __stdcall abi_GetActiveComposition(impl::abi_arg_out<Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetActiveComposition());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetConversionTarget(impl::abi_arg_out<Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetConversionTarget());
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
struct produce<D, Windows::UI::Xaml::Automation::Provider::ITextProvider> : produce_base<D, Windows::UI::Xaml::Automation::Provider::ITextProvider>
{
    HRESULT __stdcall get_DocumentRange(impl::abi_arg_out<Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DocumentRange());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedTextSelection(Windows::UI::Xaml::Automation::SupportedTextSelection * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportedTextSelection());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSelection(uint32_t * __returnValueSize, impl::abi_arg_out<Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            std::tie(*__returnValueSize, *returnValue) = detach_abi(this->shim().GetSelection());
            return S_OK;
        }
        catch (...)
        {
            *__returnValueSize = 0;
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetVisibleRanges(uint32_t * __returnValueSize, impl::abi_arg_out<Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            std::tie(*__returnValueSize, *returnValue) = detach_abi(this->shim().GetVisibleRanges());
            return S_OK;
        }
        catch (...)
        {
            *__returnValueSize = 0;
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RangeFromChild(impl::abi_arg_in<Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> childElement, impl::abi_arg_out<Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().RangeFromChild(*reinterpret_cast<const Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple *>(&childElement)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RangeFromPoint(impl::abi_arg_in<Windows::Foundation::Point> screenLocation, impl::abi_arg_out<Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().RangeFromPoint(*reinterpret_cast<const Windows::Foundation::Point *>(&screenLocation)));
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
struct produce<D, Windows::UI::Xaml::Automation::Provider::ITextProvider2> : produce_base<D, Windows::UI::Xaml::Automation::Provider::ITextProvider2>
{
    HRESULT __stdcall abi_RangeFromAnnotation(impl::abi_arg_in<Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> annotationElement, impl::abi_arg_out<Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().RangeFromAnnotation(*reinterpret_cast<const Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple *>(&annotationElement)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCaretRange(bool * isActive, impl::abi_arg_out<Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetCaretRange(*isActive));
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
struct produce<D, Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> : produce_base<D, Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>
{
    HRESULT __stdcall abi_Clone(impl::abi_arg_out<Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().Clone());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Compare(impl::abi_arg_in<Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> textRangeProvider, bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().Compare(*reinterpret_cast<const Windows::UI::Xaml::Automation::Provider::ITextRangeProvider *>(&textRangeProvider)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CompareEndpoints(Windows::UI::Xaml::Automation::Text::TextPatternRangeEndpoint endpoint, impl::abi_arg_in<Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> textRangeProvider, Windows::UI::Xaml::Automation::Text::TextPatternRangeEndpoint targetEndpoint, int32_t * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().CompareEndpoints(endpoint, *reinterpret_cast<const Windows::UI::Xaml::Automation::Provider::ITextRangeProvider *>(&textRangeProvider), targetEndpoint));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ExpandToEnclosingUnit(Windows::UI::Xaml::Automation::Text::TextUnit unit) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ExpandToEnclosingUnit(unit);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAttribute(int32_t attributeId, impl::abi_arg_in<Windows::Foundation::IInspectable> value, bool backward, impl::abi_arg_out<Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().FindAttribute(attributeId, *reinterpret_cast<const Windows::Foundation::IInspectable *>(&value), backward));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindText(impl::abi_arg_in<hstring> text, bool backward, bool ignoreCase, impl::abi_arg_out<Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().FindText(*reinterpret_cast<const hstring *>(&text), backward, ignoreCase));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAttributeValue(int32_t attributeId, impl::abi_arg_out<Windows::Foundation::IInspectable> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetAttributeValue(attributeId));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetBoundingRectangles(uint32_t * __returnValueSize, impl::abi_arg_out<double> * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GetBoundingRectangles(detach_abi<double>(__returnValueSize, returnValue));
            return S_OK;
        }
        catch (...)
        {
            *__returnValueSize = 0;
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetEnclosingElement(impl::abi_arg_out<Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetEnclosingElement());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetText(int32_t maxLength, impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetText(maxLength));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Move(Windows::UI::Xaml::Automation::Text::TextUnit unit, int32_t count, int32_t * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().Move(unit, count));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MoveEndpointByUnit(Windows::UI::Xaml::Automation::Text::TextPatternRangeEndpoint endpoint, Windows::UI::Xaml::Automation::Text::TextUnit unit, int32_t count, int32_t * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().MoveEndpointByUnit(endpoint, unit, count));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MoveEndpointByRange(Windows::UI::Xaml::Automation::Text::TextPatternRangeEndpoint endpoint, impl::abi_arg_in<Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> textRangeProvider, Windows::UI::Xaml::Automation::Text::TextPatternRangeEndpoint targetEndpoint) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MoveEndpointByRange(endpoint, *reinterpret_cast<const Windows::UI::Xaml::Automation::Provider::ITextRangeProvider *>(&textRangeProvider), targetEndpoint);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Select() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Select();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddToSelection() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddToSelection();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveFromSelection() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveFromSelection();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ScrollIntoView(bool alignToTop) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ScrollIntoView(alignToTop);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetChildren(uint32_t * __returnValueSize, impl::abi_arg_out<Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            std::tie(*__returnValueSize, *returnValue) = detach_abi(this->shim().GetChildren());
            return S_OK;
        }
        catch (...)
        {
            *__returnValueSize = 0;
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Provider::ITextRangeProvider2> : produce_base<D, Windows::UI::Xaml::Automation::Provider::ITextRangeProvider2>
{
    HRESULT __stdcall abi_ShowContextMenu() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowContextMenu();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Provider::IToggleProvider> : produce_base<D, Windows::UI::Xaml::Automation::Provider::IToggleProvider>
{
    HRESULT __stdcall get_ToggleState(Windows::UI::Xaml::Automation::ToggleState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ToggleState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Toggle() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Toggle();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Provider::ITransformProvider> : produce_base<D, Windows::UI::Xaml::Automation::Provider::ITransformProvider>
{
    HRESULT __stdcall get_CanMove(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanMove());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanResize(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanResize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanRotate(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanRotate());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Move(double x, double y) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Move(x, y);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Resize(double width, double height) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Resize(width, height);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Rotate(double degrees) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Rotate(degrees);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Provider::ITransformProvider2> : produce_base<D, Windows::UI::Xaml::Automation::Provider::ITransformProvider2>
{
    HRESULT __stdcall get_CanZoom(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanZoom());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ZoomLevel(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ZoomLevel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxZoom(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxZoom());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinZoom(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinZoom());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Zoom(double zoom) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Zoom(zoom);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ZoomByUnit(Windows::UI::Xaml::Automation::ZoomUnit zoomUnit) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ZoomByUnit(zoomUnit);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Provider::IValueProvider> : produce_base<D, Windows::UI::Xaml::Automation::Provider::IValueProvider>
{
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

    HRESULT __stdcall get_Value(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Value());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetValue(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetValue(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider> : produce_base<D, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider>
{
    HRESULT __stdcall abi_Realize() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Realize();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Provider::IWindowProvider> : produce_base<D, Windows::UI::Xaml::Automation::Provider::IWindowProvider>
{
    HRESULT __stdcall get_IsModal(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsModal());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsTopmost(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsTopmost());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Maximizable(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Maximizable());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Minimizable(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Minimizable());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InteractionState(Windows::UI::Xaml::Automation::WindowInteractionState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InteractionState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VisualState(Windows::UI::Xaml::Automation::WindowVisualState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VisualState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Close() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Close();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetVisualState(Windows::UI::Xaml::Automation::WindowVisualState state) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetVisualState(state);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_WaitForInputIdle(int32_t milliseconds, bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().WaitForInputIdle(milliseconds));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::UI::Xaml::Automation::Provider {

template <typename D> int32_t impl_IAnnotationProvider<D>::AnnotationTypeId() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IAnnotationProvider)->get_AnnotationTypeId(&value));
    return value;
}

template <typename D> hstring impl_IAnnotationProvider<D>::AnnotationTypeName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAnnotationProvider)->get_AnnotationTypeName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAnnotationProvider<D>::Author() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAnnotationProvider)->get_Author(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAnnotationProvider<D>::DateTime() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAnnotationProvider)->get_DateTime(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple impl_IAnnotationProvider<D>::Target() const
{
    Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple value { nullptr };
    check_hresult(WINRT_SHIM(IAnnotationProvider)->get_Target(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Automation::DockPosition impl_IDockProvider<D>::DockPosition() const
{
    Windows::UI::Xaml::Automation::DockPosition value {};
    check_hresult(WINRT_SHIM(IDockProvider)->get_DockPosition(&value));
    return value;
}

template <typename D> void impl_IDockProvider<D>::SetDockPosition(Windows::UI::Xaml::Automation::DockPosition dockPosition) const
{
    check_hresult(WINRT_SHIM(IDockProvider)->abi_SetDockPosition(dockPosition));
}

template <typename D> bool impl_IDragProvider<D>::IsGrabbed() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDragProvider)->get_IsGrabbed(&value));
    return value;
}

template <typename D> hstring impl_IDragProvider<D>::DropEffect() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDragProvider)->get_DropEffect(put_abi(value)));
    return value;
}

template <typename D> com_array<hstring> impl_IDragProvider<D>::DropEffects() const
{
    com_array<hstring> value;
    check_hresult(WINRT_SHIM(IDragProvider)->get_DropEffects(impl::put_size_abi(value), put_abi(value)));
    return value;
}

template <typename D> com_array<Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple> impl_IDragProvider<D>::GetGrabbedItems() const
{
    com_array<Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple> returnValue { nullptr };
    check_hresult(WINRT_SHIM(IDragProvider)->abi_GetGrabbedItems(impl::put_size_abi(returnValue), put_abi(returnValue)));
    return returnValue;
}

template <typename D> hstring impl_IDropTargetProvider<D>::DropEffect() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDropTargetProvider)->get_DropEffect(put_abi(value)));
    return value;
}

template <typename D> com_array<hstring> impl_IDropTargetProvider<D>::DropEffects() const
{
    com_array<hstring> value;
    check_hresult(WINRT_SHIM(IDropTargetProvider)->get_DropEffects(impl::put_size_abi(value), put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Automation::ExpandCollapseState impl_IExpandCollapseProvider<D>::ExpandCollapseState() const
{
    Windows::UI::Xaml::Automation::ExpandCollapseState value {};
    check_hresult(WINRT_SHIM(IExpandCollapseProvider)->get_ExpandCollapseState(&value));
    return value;
}

template <typename D> void impl_IExpandCollapseProvider<D>::Collapse() const
{
    check_hresult(WINRT_SHIM(IExpandCollapseProvider)->abi_Collapse());
}

template <typename D> void impl_IExpandCollapseProvider<D>::Expand() const
{
    check_hresult(WINRT_SHIM(IExpandCollapseProvider)->abi_Expand());
}

template <typename D> int32_t impl_IGridItemProvider<D>::Column() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IGridItemProvider)->get_Column(&value));
    return value;
}

template <typename D> int32_t impl_IGridItemProvider<D>::ColumnSpan() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IGridItemProvider)->get_ColumnSpan(&value));
    return value;
}

template <typename D> Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple impl_IGridItemProvider<D>::ContainingGrid() const
{
    Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple value { nullptr };
    check_hresult(WINRT_SHIM(IGridItemProvider)->get_ContainingGrid(put_abi(value)));
    return value;
}

template <typename D> int32_t impl_IGridItemProvider<D>::Row() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IGridItemProvider)->get_Row(&value));
    return value;
}

template <typename D> int32_t impl_IGridItemProvider<D>::RowSpan() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IGridItemProvider)->get_RowSpan(&value));
    return value;
}

template <typename D> int32_t impl_IGridProvider<D>::ColumnCount() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IGridProvider)->get_ColumnCount(&value));
    return value;
}

template <typename D> int32_t impl_IGridProvider<D>::RowCount() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IGridProvider)->get_RowCount(&value));
    return value;
}

template <typename D> Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple impl_IGridProvider<D>::GetItem(int32_t row, int32_t column) const
{
    Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple returnValue { nullptr };
    check_hresult(WINRT_SHIM(IGridProvider)->abi_GetItem(row, column, put_abi(returnValue)));
    return returnValue;
}

template <typename D> void impl_IInvokeProvider<D>::Invoke() const
{
    check_hresult(WINRT_SHIM(IInvokeProvider)->abi_Invoke());
}

template <typename D> Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple impl_IItemContainerProvider<D>::FindItemByProperty(const Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple & startAfter, const Windows::UI::Xaml::Automation::AutomationProperty & automationProperty, const Windows::Foundation::IInspectable & value) const
{
    Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple returnValue { nullptr };
    check_hresult(WINRT_SHIM(IItemContainerProvider)->abi_FindItemByProperty(get_abi(startAfter), get_abi(automationProperty), get_abi(value), put_abi(returnValue)));
    return returnValue;
}

template <typename D> int32_t impl_IMultipleViewProvider<D>::CurrentView() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IMultipleViewProvider)->get_CurrentView(&value));
    return value;
}

template <typename D> com_array<int32_t> impl_IMultipleViewProvider<D>::GetSupportedViews() const
{
    com_array<int32_t> returnValue {};
    check_hresult(WINRT_SHIM(IMultipleViewProvider)->abi_GetSupportedViews(impl::put_size_abi(returnValue), put_abi(returnValue)));
    return returnValue;
}

template <typename D> hstring impl_IMultipleViewProvider<D>::GetViewName(int32_t viewId) const
{
    hstring returnValue;
    check_hresult(WINRT_SHIM(IMultipleViewProvider)->abi_GetViewName(viewId, put_abi(returnValue)));
    return returnValue;
}

template <typename D> void impl_IMultipleViewProvider<D>::SetCurrentView(int32_t viewId) const
{
    check_hresult(WINRT_SHIM(IMultipleViewProvider)->abi_SetCurrentView(viewId));
}

template <typename D> Windows::Foundation::IInspectable impl_IObjectModelProvider<D>::GetUnderlyingObjectModel() const
{
    Windows::Foundation::IInspectable returnValue;
    check_hresult(WINRT_SHIM(IObjectModelProvider)->abi_GetUnderlyingObjectModel(put_abi(returnValue)));
    return returnValue;
}

template <typename D> bool impl_IRangeValueProvider<D>::IsReadOnly() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IRangeValueProvider)->get_IsReadOnly(&value));
    return value;
}

template <typename D> double impl_IRangeValueProvider<D>::LargeChange() const
{
    double value {};
    check_hresult(WINRT_SHIM(IRangeValueProvider)->get_LargeChange(&value));
    return value;
}

template <typename D> double impl_IRangeValueProvider<D>::Maximum() const
{
    double value {};
    check_hresult(WINRT_SHIM(IRangeValueProvider)->get_Maximum(&value));
    return value;
}

template <typename D> double impl_IRangeValueProvider<D>::Minimum() const
{
    double value {};
    check_hresult(WINRT_SHIM(IRangeValueProvider)->get_Minimum(&value));
    return value;
}

template <typename D> double impl_IRangeValueProvider<D>::SmallChange() const
{
    double value {};
    check_hresult(WINRT_SHIM(IRangeValueProvider)->get_SmallChange(&value));
    return value;
}

template <typename D> double impl_IRangeValueProvider<D>::Value() const
{
    double value {};
    check_hresult(WINRT_SHIM(IRangeValueProvider)->get_Value(&value));
    return value;
}

template <typename D> void impl_IRangeValueProvider<D>::SetValue(double value) const
{
    check_hresult(WINRT_SHIM(IRangeValueProvider)->abi_SetValue(value));
}

template <typename D> void impl_IScrollItemProvider<D>::ScrollIntoView() const
{
    check_hresult(WINRT_SHIM(IScrollItemProvider)->abi_ScrollIntoView());
}

template <typename D> bool impl_IScrollProvider<D>::HorizontallyScrollable() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IScrollProvider)->get_HorizontallyScrollable(&value));
    return value;
}

template <typename D> double impl_IScrollProvider<D>::HorizontalScrollPercent() const
{
    double value {};
    check_hresult(WINRT_SHIM(IScrollProvider)->get_HorizontalScrollPercent(&value));
    return value;
}

template <typename D> double impl_IScrollProvider<D>::HorizontalViewSize() const
{
    double value {};
    check_hresult(WINRT_SHIM(IScrollProvider)->get_HorizontalViewSize(&value));
    return value;
}

template <typename D> bool impl_IScrollProvider<D>::VerticallyScrollable() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IScrollProvider)->get_VerticallyScrollable(&value));
    return value;
}

template <typename D> double impl_IScrollProvider<D>::VerticalScrollPercent() const
{
    double value {};
    check_hresult(WINRT_SHIM(IScrollProvider)->get_VerticalScrollPercent(&value));
    return value;
}

template <typename D> double impl_IScrollProvider<D>::VerticalViewSize() const
{
    double value {};
    check_hresult(WINRT_SHIM(IScrollProvider)->get_VerticalViewSize(&value));
    return value;
}

template <typename D> void impl_IScrollProvider<D>::Scroll(Windows::UI::Xaml::Automation::ScrollAmount horizontalAmount, Windows::UI::Xaml::Automation::ScrollAmount verticalAmount) const
{
    check_hresult(WINRT_SHIM(IScrollProvider)->abi_Scroll(horizontalAmount, verticalAmount));
}

template <typename D> void impl_IScrollProvider<D>::SetScrollPercent(double horizontalPercent, double verticalPercent) const
{
    check_hresult(WINRT_SHIM(IScrollProvider)->abi_SetScrollPercent(horizontalPercent, verticalPercent));
}

template <typename D> bool impl_ISelectionItemProvider<D>::IsSelected() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISelectionItemProvider)->get_IsSelected(&value));
    return value;
}

template <typename D> Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple impl_ISelectionItemProvider<D>::SelectionContainer() const
{
    Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple value { nullptr };
    check_hresult(WINRT_SHIM(ISelectionItemProvider)->get_SelectionContainer(put_abi(value)));
    return value;
}

template <typename D> void impl_ISelectionItemProvider<D>::AddToSelection() const
{
    check_hresult(WINRT_SHIM(ISelectionItemProvider)->abi_AddToSelection());
}

template <typename D> void impl_ISelectionItemProvider<D>::RemoveFromSelection() const
{
    check_hresult(WINRT_SHIM(ISelectionItemProvider)->abi_RemoveFromSelection());
}

template <typename D> void impl_ISelectionItemProvider<D>::Select() const
{
    check_hresult(WINRT_SHIM(ISelectionItemProvider)->abi_Select());
}

template <typename D> bool impl_ISelectionProvider<D>::CanSelectMultiple() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISelectionProvider)->get_CanSelectMultiple(&value));
    return value;
}

template <typename D> bool impl_ISelectionProvider<D>::IsSelectionRequired() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISelectionProvider)->get_IsSelectionRequired(&value));
    return value;
}

template <typename D> com_array<Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple> impl_ISelectionProvider<D>::GetSelection() const
{
    com_array<Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple> returnValue { nullptr };
    check_hresult(WINRT_SHIM(ISelectionProvider)->abi_GetSelection(impl::put_size_abi(returnValue), put_abi(returnValue)));
    return returnValue;
}

template <typename D> hstring impl_ISpreadsheetItemProvider<D>::Formula() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISpreadsheetItemProvider)->get_Formula(put_abi(value)));
    return value;
}

template <typename D> com_array<Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple> impl_ISpreadsheetItemProvider<D>::GetAnnotationObjects() const
{
    com_array<Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple> returnValue { nullptr };
    check_hresult(WINRT_SHIM(ISpreadsheetItemProvider)->abi_GetAnnotationObjects(impl::put_size_abi(returnValue), put_abi(returnValue)));
    return returnValue;
}

template <typename D> com_array<Windows::UI::Xaml::Automation::AnnotationType> impl_ISpreadsheetItemProvider<D>::GetAnnotationTypes() const
{
    com_array<Windows::UI::Xaml::Automation::AnnotationType> returnValue {};
    check_hresult(WINRT_SHIM(ISpreadsheetItemProvider)->abi_GetAnnotationTypes(impl::put_size_abi(returnValue), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple impl_ISpreadsheetProvider<D>::GetItemByName(hstring_view name) const
{
    Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple returnValue { nullptr };
    check_hresult(WINRT_SHIM(ISpreadsheetProvider)->abi_GetItemByName(get_abi(name), put_abi(returnValue)));
    return returnValue;
}

template <typename D> hstring impl_IStylesProvider<D>::ExtendedProperties() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStylesProvider)->get_ExtendedProperties(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Color impl_IStylesProvider<D>::FillColor() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IStylesProvider)->get_FillColor(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Color impl_IStylesProvider<D>::FillPatternColor() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IStylesProvider)->get_FillPatternColor(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStylesProvider<D>::FillPatternStyle() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStylesProvider)->get_FillPatternStyle(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IStylesProvider<D>::Shape() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStylesProvider)->get_Shape(put_abi(value)));
    return value;
}

template <typename D> int32_t impl_IStylesProvider<D>::StyleId() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IStylesProvider)->get_StyleId(&value));
    return value;
}

template <typename D> hstring impl_IStylesProvider<D>::StyleName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStylesProvider)->get_StyleName(put_abi(value)));
    return value;
}

template <typename D> void impl_ISynchronizedInputProvider<D>::Cancel() const
{
    check_hresult(WINRT_SHIM(ISynchronizedInputProvider)->abi_Cancel());
}

template <typename D> void impl_ISynchronizedInputProvider<D>::StartListening(Windows::UI::Xaml::Automation::SynchronizedInputType inputType) const
{
    check_hresult(WINRT_SHIM(ISynchronizedInputProvider)->abi_StartListening(inputType));
}

template <typename D> com_array<Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple> impl_ITableItemProvider<D>::GetColumnHeaderItems() const
{
    com_array<Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple> returnValue { nullptr };
    check_hresult(WINRT_SHIM(ITableItemProvider)->abi_GetColumnHeaderItems(impl::put_size_abi(returnValue), put_abi(returnValue)));
    return returnValue;
}

template <typename D> com_array<Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple> impl_ITableItemProvider<D>::GetRowHeaderItems() const
{
    com_array<Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple> returnValue { nullptr };
    check_hresult(WINRT_SHIM(ITableItemProvider)->abi_GetRowHeaderItems(impl::put_size_abi(returnValue), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Automation::RowOrColumnMajor impl_ITableProvider<D>::RowOrColumnMajor() const
{
    Windows::UI::Xaml::Automation::RowOrColumnMajor value {};
    check_hresult(WINRT_SHIM(ITableProvider)->get_RowOrColumnMajor(&value));
    return value;
}

template <typename D> com_array<Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple> impl_ITableProvider<D>::GetColumnHeaders() const
{
    com_array<Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple> returnValue { nullptr };
    check_hresult(WINRT_SHIM(ITableProvider)->abi_GetColumnHeaders(impl::put_size_abi(returnValue), put_abi(returnValue)));
    return returnValue;
}

template <typename D> com_array<Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple> impl_ITableProvider<D>::GetRowHeaders() const
{
    com_array<Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple> returnValue { nullptr };
    check_hresult(WINRT_SHIM(ITableProvider)->abi_GetRowHeaders(impl::put_size_abi(returnValue), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple impl_ITextChildProvider<D>::TextContainer() const
{
    Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple value { nullptr };
    check_hresult(WINRT_SHIM(ITextChildProvider)->get_TextContainer(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Automation::Provider::ITextRangeProvider impl_ITextChildProvider<D>::TextRange() const
{
    Windows::UI::Xaml::Automation::Provider::ITextRangeProvider value;
    check_hresult(WINRT_SHIM(ITextChildProvider)->get_TextRange(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Automation::Provider::ITextRangeProvider impl_ITextRangeProvider<D>::Clone() const
{
    Windows::UI::Xaml::Automation::Provider::ITextRangeProvider returnValue;
    check_hresult(WINRT_SHIM(ITextRangeProvider)->abi_Clone(put_abi(returnValue)));
    return returnValue;
}

template <typename D> bool impl_ITextRangeProvider<D>::Compare(const Windows::UI::Xaml::Automation::Provider::ITextRangeProvider & textRangeProvider) const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(ITextRangeProvider)->abi_Compare(get_abi(textRangeProvider), &returnValue));
    return returnValue;
}

template <typename D> int32_t impl_ITextRangeProvider<D>::CompareEndpoints(Windows::UI::Xaml::Automation::Text::TextPatternRangeEndpoint endpoint, const Windows::UI::Xaml::Automation::Provider::ITextRangeProvider & textRangeProvider, Windows::UI::Xaml::Automation::Text::TextPatternRangeEndpoint targetEndpoint) const
{
    int32_t returnValue {};
    check_hresult(WINRT_SHIM(ITextRangeProvider)->abi_CompareEndpoints(endpoint, get_abi(textRangeProvider), targetEndpoint, &returnValue));
    return returnValue;
}

template <typename D> void impl_ITextRangeProvider<D>::ExpandToEnclosingUnit(Windows::UI::Xaml::Automation::Text::TextUnit unit) const
{
    check_hresult(WINRT_SHIM(ITextRangeProvider)->abi_ExpandToEnclosingUnit(unit));
}

template <typename D> Windows::UI::Xaml::Automation::Provider::ITextRangeProvider impl_ITextRangeProvider<D>::FindAttribute(int32_t attributeId, const Windows::Foundation::IInspectable & value, bool backward) const
{
    Windows::UI::Xaml::Automation::Provider::ITextRangeProvider returnValue;
    check_hresult(WINRT_SHIM(ITextRangeProvider)->abi_FindAttribute(attributeId, get_abi(value), backward, put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Automation::Provider::ITextRangeProvider impl_ITextRangeProvider<D>::FindText(hstring_view text, bool backward, bool ignoreCase) const
{
    Windows::UI::Xaml::Automation::Provider::ITextRangeProvider returnValue;
    check_hresult(WINRT_SHIM(ITextRangeProvider)->abi_FindText(get_abi(text), backward, ignoreCase, put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IInspectable impl_ITextRangeProvider<D>::GetAttributeValue(int32_t attributeId) const
{
    Windows::Foundation::IInspectable returnValue;
    check_hresult(WINRT_SHIM(ITextRangeProvider)->abi_GetAttributeValue(attributeId, put_abi(returnValue)));
    return returnValue;
}

template <typename D> void impl_ITextRangeProvider<D>::GetBoundingRectangles(com_array<double> & returnValue) const
{
    check_hresult(WINRT_SHIM(ITextRangeProvider)->abi_GetBoundingRectangles(impl::put_size_abi(returnValue), put_abi(returnValue)));
}

template <typename D> Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple impl_ITextRangeProvider<D>::GetEnclosingElement() const
{
    Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple returnValue { nullptr };
    check_hresult(WINRT_SHIM(ITextRangeProvider)->abi_GetEnclosingElement(put_abi(returnValue)));
    return returnValue;
}

template <typename D> hstring impl_ITextRangeProvider<D>::GetText(int32_t maxLength) const
{
    hstring returnValue;
    check_hresult(WINRT_SHIM(ITextRangeProvider)->abi_GetText(maxLength, put_abi(returnValue)));
    return returnValue;
}

template <typename D> int32_t impl_ITextRangeProvider<D>::Move(Windows::UI::Xaml::Automation::Text::TextUnit unit, int32_t count) const
{
    int32_t returnValue {};
    check_hresult(WINRT_SHIM(ITextRangeProvider)->abi_Move(unit, count, &returnValue));
    return returnValue;
}

template <typename D> int32_t impl_ITextRangeProvider<D>::MoveEndpointByUnit(Windows::UI::Xaml::Automation::Text::TextPatternRangeEndpoint endpoint, Windows::UI::Xaml::Automation::Text::TextUnit unit, int32_t count) const
{
    int32_t returnValue {};
    check_hresult(WINRT_SHIM(ITextRangeProvider)->abi_MoveEndpointByUnit(endpoint, unit, count, &returnValue));
    return returnValue;
}

template <typename D> void impl_ITextRangeProvider<D>::MoveEndpointByRange(Windows::UI::Xaml::Automation::Text::TextPatternRangeEndpoint endpoint, const Windows::UI::Xaml::Automation::Provider::ITextRangeProvider & textRangeProvider, Windows::UI::Xaml::Automation::Text::TextPatternRangeEndpoint targetEndpoint) const
{
    check_hresult(WINRT_SHIM(ITextRangeProvider)->abi_MoveEndpointByRange(endpoint, get_abi(textRangeProvider), targetEndpoint));
}

template <typename D> void impl_ITextRangeProvider<D>::Select() const
{
    check_hresult(WINRT_SHIM(ITextRangeProvider)->abi_Select());
}

template <typename D> void impl_ITextRangeProvider<D>::AddToSelection() const
{
    check_hresult(WINRT_SHIM(ITextRangeProvider)->abi_AddToSelection());
}

template <typename D> void impl_ITextRangeProvider<D>::RemoveFromSelection() const
{
    check_hresult(WINRT_SHIM(ITextRangeProvider)->abi_RemoveFromSelection());
}

template <typename D> void impl_ITextRangeProvider<D>::ScrollIntoView(bool alignToTop) const
{
    check_hresult(WINRT_SHIM(ITextRangeProvider)->abi_ScrollIntoView(alignToTop));
}

template <typename D> com_array<Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple> impl_ITextRangeProvider<D>::GetChildren() const
{
    com_array<Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple> returnValue { nullptr };
    check_hresult(WINRT_SHIM(ITextRangeProvider)->abi_GetChildren(impl::put_size_abi(returnValue), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Automation::Provider::ITextRangeProvider impl_ITextProvider<D>::DocumentRange() const
{
    Windows::UI::Xaml::Automation::Provider::ITextRangeProvider value;
    check_hresult(WINRT_SHIM(ITextProvider)->get_DocumentRange(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Automation::SupportedTextSelection impl_ITextProvider<D>::SupportedTextSelection() const
{
    Windows::UI::Xaml::Automation::SupportedTextSelection value {};
    check_hresult(WINRT_SHIM(ITextProvider)->get_SupportedTextSelection(&value));
    return value;
}

template <typename D> com_array<Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> impl_ITextProvider<D>::GetSelection() const
{
    com_array<Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> returnValue;
    check_hresult(WINRT_SHIM(ITextProvider)->abi_GetSelection(impl::put_size_abi(returnValue), put_abi(returnValue)));
    return returnValue;
}

template <typename D> com_array<Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> impl_ITextProvider<D>::GetVisibleRanges() const
{
    com_array<Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> returnValue;
    check_hresult(WINRT_SHIM(ITextProvider)->abi_GetVisibleRanges(impl::put_size_abi(returnValue), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Automation::Provider::ITextRangeProvider impl_ITextProvider<D>::RangeFromChild(const Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple & childElement) const
{
    Windows::UI::Xaml::Automation::Provider::ITextRangeProvider returnValue;
    check_hresult(WINRT_SHIM(ITextProvider)->abi_RangeFromChild(get_abi(childElement), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Automation::Provider::ITextRangeProvider impl_ITextProvider<D>::RangeFromPoint(const Windows::Foundation::Point & screenLocation) const
{
    Windows::UI::Xaml::Automation::Provider::ITextRangeProvider returnValue;
    check_hresult(WINRT_SHIM(ITextProvider)->abi_RangeFromPoint(get_abi(screenLocation), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Automation::Provider::ITextRangeProvider impl_ITextProvider2<D>::RangeFromAnnotation(const Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple & annotationElement) const
{
    Windows::UI::Xaml::Automation::Provider::ITextRangeProvider returnValue;
    check_hresult(WINRT_SHIM(ITextProvider2)->abi_RangeFromAnnotation(get_abi(annotationElement), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Automation::Provider::ITextRangeProvider impl_ITextProvider2<D>::GetCaretRange(bool & isActive) const
{
    Windows::UI::Xaml::Automation::Provider::ITextRangeProvider returnValue;
    check_hresult(WINRT_SHIM(ITextProvider2)->abi_GetCaretRange(&isActive, put_abi(returnValue)));
    return returnValue;
}

template <typename D> void impl_ITextRangeProvider2<D>::ShowContextMenu() const
{
    check_hresult(WINRT_SHIM(ITextRangeProvider2)->abi_ShowContextMenu());
}

template <typename D> Windows::UI::Xaml::Automation::ToggleState impl_IToggleProvider<D>::ToggleState() const
{
    Windows::UI::Xaml::Automation::ToggleState value {};
    check_hresult(WINRT_SHIM(IToggleProvider)->get_ToggleState(&value));
    return value;
}

template <typename D> void impl_IToggleProvider<D>::Toggle() const
{
    check_hresult(WINRT_SHIM(IToggleProvider)->abi_Toggle());
}

template <typename D> bool impl_ITransformProvider<D>::CanMove() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITransformProvider)->get_CanMove(&value));
    return value;
}

template <typename D> bool impl_ITransformProvider<D>::CanResize() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITransformProvider)->get_CanResize(&value));
    return value;
}

template <typename D> bool impl_ITransformProvider<D>::CanRotate() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITransformProvider)->get_CanRotate(&value));
    return value;
}

template <typename D> void impl_ITransformProvider<D>::Move(double x, double y) const
{
    check_hresult(WINRT_SHIM(ITransformProvider)->abi_Move(x, y));
}

template <typename D> void impl_ITransformProvider<D>::Resize(double width, double height) const
{
    check_hresult(WINRT_SHIM(ITransformProvider)->abi_Resize(width, height));
}

template <typename D> void impl_ITransformProvider<D>::Rotate(double degrees) const
{
    check_hresult(WINRT_SHIM(ITransformProvider)->abi_Rotate(degrees));
}

template <typename D> bool impl_ITransformProvider2<D>::CanZoom() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITransformProvider2)->get_CanZoom(&value));
    return value;
}

template <typename D> double impl_ITransformProvider2<D>::ZoomLevel() const
{
    double value {};
    check_hresult(WINRT_SHIM(ITransformProvider2)->get_ZoomLevel(&value));
    return value;
}

template <typename D> double impl_ITransformProvider2<D>::MaxZoom() const
{
    double value {};
    check_hresult(WINRT_SHIM(ITransformProvider2)->get_MaxZoom(&value));
    return value;
}

template <typename D> double impl_ITransformProvider2<D>::MinZoom() const
{
    double value {};
    check_hresult(WINRT_SHIM(ITransformProvider2)->get_MinZoom(&value));
    return value;
}

template <typename D> void impl_ITransformProvider2<D>::Zoom(double zoom) const
{
    check_hresult(WINRT_SHIM(ITransformProvider2)->abi_Zoom(zoom));
}

template <typename D> void impl_ITransformProvider2<D>::ZoomByUnit(Windows::UI::Xaml::Automation::ZoomUnit zoomUnit) const
{
    check_hresult(WINRT_SHIM(ITransformProvider2)->abi_ZoomByUnit(zoomUnit));
}

template <typename D> bool impl_IValueProvider<D>::IsReadOnly() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IValueProvider)->get_IsReadOnly(&value));
    return value;
}

template <typename D> hstring impl_IValueProvider<D>::Value() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IValueProvider)->get_Value(put_abi(value)));
    return value;
}

template <typename D> void impl_IValueProvider<D>::SetValue(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IValueProvider)->abi_SetValue(get_abi(value)));
}

template <typename D> void impl_IVirtualizedItemProvider<D>::Realize() const
{
    check_hresult(WINRT_SHIM(IVirtualizedItemProvider)->abi_Realize());
}

template <typename D> bool impl_IWindowProvider<D>::IsModal() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IWindowProvider)->get_IsModal(&value));
    return value;
}

template <typename D> bool impl_IWindowProvider<D>::IsTopmost() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IWindowProvider)->get_IsTopmost(&value));
    return value;
}

template <typename D> bool impl_IWindowProvider<D>::Maximizable() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IWindowProvider)->get_Maximizable(&value));
    return value;
}

template <typename D> bool impl_IWindowProvider<D>::Minimizable() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IWindowProvider)->get_Minimizable(&value));
    return value;
}

template <typename D> Windows::UI::Xaml::Automation::WindowInteractionState impl_IWindowProvider<D>::InteractionState() const
{
    Windows::UI::Xaml::Automation::WindowInteractionState value {};
    check_hresult(WINRT_SHIM(IWindowProvider)->get_InteractionState(&value));
    return value;
}

template <typename D> Windows::UI::Xaml::Automation::WindowVisualState impl_IWindowProvider<D>::VisualState() const
{
    Windows::UI::Xaml::Automation::WindowVisualState value {};
    check_hresult(WINRT_SHIM(IWindowProvider)->get_VisualState(&value));
    return value;
}

template <typename D> void impl_IWindowProvider<D>::Close() const
{
    check_hresult(WINRT_SHIM(IWindowProvider)->abi_Close());
}

template <typename D> void impl_IWindowProvider<D>::SetVisualState(Windows::UI::Xaml::Automation::WindowVisualState state) const
{
    check_hresult(WINRT_SHIM(IWindowProvider)->abi_SetVisualState(state));
}

template <typename D> bool impl_IWindowProvider<D>::WaitForInputIdle(int32_t milliseconds) const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IWindowProvider)->abi_WaitForInputIdle(milliseconds, &returnValue));
    return returnValue;
}

template <typename D> Windows::Foundation::IInspectable impl_ICustomNavigationProvider<D>::NavigateCustom(Windows::UI::Xaml::Automation::Peers::AutomationNavigationDirection direction) const
{
    Windows::Foundation::IInspectable returnValue;
    check_hresult(WINRT_SHIM(ICustomNavigationProvider)->abi_NavigateCustom(direction, put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Automation::Provider::ITextRangeProvider impl_ITextEditProvider<D>::GetActiveComposition() const
{
    Windows::UI::Xaml::Automation::Provider::ITextRangeProvider returnValue;
    check_hresult(WINRT_SHIM(ITextEditProvider)->abi_GetActiveComposition(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Automation::Provider::ITextRangeProvider impl_ITextEditProvider<D>::GetConversionTarget() const
{
    Windows::UI::Xaml::Automation::Provider::ITextRangeProvider returnValue;
    check_hresult(WINRT_SHIM(ITextEditProvider)->abi_GetConversionTarget(put_abi(returnValue)));
    return returnValue;
}

}

}
#pragma warning(pop)
