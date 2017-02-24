// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.UI.Xaml.Controls.Primitives.3.h"
#include "internal/Windows.UI.Xaml.Controls.3.h"
#include "internal/Windows.UI.Xaml.Automation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.UI.Xaml.Automation.Provider.3.h"
#include "internal/Windows.UI.Xaml.3.h"
#include "internal/Windows.UI.Xaml.Automation.Peers.3.h"
#include "Windows.UI.Xaml.Automation.h"
#include "Windows.UI.Xaml.Automation.Provider.h"
#include "internal/Windows.UI.Xaml.Automation.Peers.4.h"
#include "internal/Windows.UI.Xaml.Automation.Peers.5.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IAppBarAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IAppBarAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IAppBarAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IAppBarAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IAppBar> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IAppBarAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::AppBar *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IAppBarButtonAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IAppBarButtonAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IAppBarButtonAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IAppBarButtonAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IAppBarButton> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IAppBarButtonAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::AppBarButton *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IAppBarToggleButtonAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IAppBarToggleButtonAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IAppBarToggleButtonAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IAppBarToggleButtonAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IAppBarToggleButton> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IAppBarToggleButtonAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::AppBarToggleButton *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IAutoSuggestBoxAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IAutoSuggestBoxAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IAutoSuggestBoxAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IAutoSuggestBoxAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IAutoSuggestBox> owner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IAutoSuggestBoxAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::AutoSuggestBox *>(&owner)));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeer>
{
    HRESULT __stdcall get_EventsSource(impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IAutomationPeer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EventsSource());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EventsSource(impl::abi_arg_in<Windows::UI::Xaml::Automation::Peers::IAutomationPeer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EventsSource(*reinterpret_cast<const Windows::UI::Xaml::Automation::Peers::AutomationPeer *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPattern(Windows::UI::Xaml::Automation::Peers::PatternInterface patternInterface, impl::abi_arg_out<Windows::Foundation::IInspectable> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetPattern(patternInterface));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RaiseAutomationEvent(Windows::UI::Xaml::Automation::Peers::AutomationEvents eventId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RaiseAutomationEvent(eventId);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RaisePropertyChangedEvent(impl::abi_arg_in<Windows::UI::Xaml::Automation::IAutomationProperty> automationProperty, impl::abi_arg_in<Windows::Foundation::IInspectable> oldValue, impl::abi_arg_in<Windows::Foundation::IInspectable> newValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RaisePropertyChangedEvent(*reinterpret_cast<const Windows::UI::Xaml::Automation::AutomationProperty *>(&automationProperty), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&oldValue), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&newValue));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAcceleratorKey(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetAcceleratorKey());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAccessKey(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetAccessKey());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAutomationControlType(Windows::UI::Xaml::Automation::Peers::AutomationControlType * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetAutomationControlType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAutomationId(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetAutomationId());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetBoundingRectangle(impl::abi_arg_out<Windows::Foundation::Rect> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetBoundingRectangle());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetChildren(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeer>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetChildren());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetClassName(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetClassName());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetClickablePoint(impl::abi_arg_out<Windows::Foundation::Point> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetClickablePoint());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetHelpText(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetHelpText());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetItemStatus(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetItemStatus());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetItemType(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetItemType());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetLabeledBy(impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IAutomationPeer> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetLabeledBy());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetLocalizedControlType(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetLocalizedControlType());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetName(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetName());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetOrientation(Windows::UI::Xaml::Automation::Peers::AutomationOrientation * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetOrientation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_HasKeyboardFocus(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().HasKeyboardFocus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsContentElement(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().IsContentElement());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsControlElement(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().IsControlElement());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsEnabled(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().IsEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsKeyboardFocusable(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().IsKeyboardFocusable());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsOffscreen(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().IsOffscreen());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsPassword(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().IsPassword());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsRequiredForForm(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().IsRequiredForForm());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetFocus() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetFocus();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetParent(impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IAutomationPeer> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetParent());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_InvalidatePeer() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InvalidatePeer();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPeerFromPoint(impl::abi_arg_in<Windows::Foundation::Point> point, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IAutomationPeer> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetPeerFromPoint(*reinterpret_cast<const Windows::Foundation::Point *>(&point)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetLiveSetting(Windows::UI::Xaml::Automation::Peers::AutomationLiveSetting * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetLiveSetting());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3>
{
    HRESULT __stdcall abi_Navigate(Windows::UI::Xaml::Automation::Peers::AutomationNavigationDirection direction, impl::abi_arg_out<Windows::Foundation::IInspectable> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().Navigate(direction));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetElementFromPoint(impl::abi_arg_in<Windows::Foundation::Point> pointInWindowCoordinates, impl::abi_arg_out<Windows::Foundation::IInspectable> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetElementFromPoint(*reinterpret_cast<const Windows::Foundation::Point *>(&pointInWindowCoordinates)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFocusedElement(impl::abi_arg_out<Windows::Foundation::IInspectable> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetFocusedElement());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall abi_GetControlledPeers(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Automation::Peers::AutomationPeer>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetControlledPeers());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAnnotations(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetAnnotations());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetParent(impl::abi_arg_in<Windows::UI::Xaml::Automation::Peers::IAutomationPeer> peer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetParent(*reinterpret_cast<const Windows::UI::Xaml::Automation::Peers::AutomationPeer *>(&peer));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RaiseTextEditTextChangedEvent(Windows::UI::Xaml::Automation::AutomationTextEditChangeType automationTextEditChangeType, impl::abi_arg_in<Windows::Foundation::Collections::IVectorView<hstring>> changedData) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RaiseTextEditTextChangedEvent(automationTextEditChangeType, *reinterpret_cast<const Windows::Foundation::Collections::IVectorView<hstring> *>(&changedData));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPositionInSet(int32_t * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetPositionInSet());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSizeOfSet(int32_t * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetSizeOfSet());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetLevel(int32_t * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetLevel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RaiseStructureChangedEvent(Windows::UI::Xaml::Automation::Peers::AutomationStructureChangeType structureChangeType, impl::abi_arg_in<Windows::UI::Xaml::Automation::Peers::IAutomationPeer> child) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RaiseStructureChangedEvent(structureChangeType, *reinterpret_cast<const Windows::UI::Xaml::Automation::Peers::AutomationPeer *>(&child));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4>
{
    HRESULT __stdcall abi_GetLandmarkType(Windows::UI::Xaml::Automation::Peers::AutomationLandmarkType * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetLandmarkType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetLocalizedLandmarkType(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetLocalizedLandmarkType());
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5>
{
    HRESULT __stdcall abi_IsPeripheral(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().IsPeripheral());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsDataValidForForm(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().IsDataValidForForm());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFullDescription(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetFullDescription());
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerAnnotation> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerAnnotation>
{
    HRESULT __stdcall get_Type(Windows::UI::Xaml::Automation::AnnotationType * value) noexcept override
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

    HRESULT __stdcall put_Type(Windows::UI::Xaml::Automation::AnnotationType value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Type(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Peer(impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IAutomationPeer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Peer());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Peer(impl::abi_arg_in<Windows::UI::Xaml::Automation::Peers::IAutomationPeer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Peer(*reinterpret_cast<const Windows::UI::Xaml::Automation::Peers::AutomationPeer *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerAnnotationFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerAnnotationFactory>
{
    HRESULT __stdcall abi_CreateInstance(Windows::UI::Xaml::Automation::AnnotationType type, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IAutomationPeerAnnotation> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstance(type));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithPeerParameter(Windows::UI::Xaml::Automation::AnnotationType type, impl::abi_arg_in<Windows::UI::Xaml::Automation::Peers::IAutomationPeer> peer, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IAutomationPeerAnnotation> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateWithPeerParameter(type, *reinterpret_cast<const Windows::UI::Xaml::Automation::Peers::AutomationPeer *>(&peer)));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerAnnotationStatics> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerAnnotationStatics>
{
    HRESULT __stdcall get_TypeProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TypeProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PeerProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PeerProperty());
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IAutomationPeer> instance) noexcept override
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>
{
    HRESULT __stdcall abi_GetPatternCore(Windows::UI::Xaml::Automation::Peers::PatternInterface patternInterface, impl::abi_arg_out<Windows::Foundation::IInspectable> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetPatternCore(patternInterface));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAcceleratorKeyCore(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetAcceleratorKeyCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAccessKeyCore(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetAccessKeyCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAutomationControlTypeCore(Windows::UI::Xaml::Automation::Peers::AutomationControlType * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetAutomationControlTypeCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAutomationIdCore(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetAutomationIdCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetBoundingRectangleCore(impl::abi_arg_out<Windows::Foundation::Rect> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetBoundingRectangleCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetChildrenCore(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeer>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetChildrenCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetClassNameCore(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetClassNameCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetClickablePointCore(impl::abi_arg_out<Windows::Foundation::Point> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetClickablePointCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetHelpTextCore(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetHelpTextCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetItemStatusCore(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetItemStatusCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetItemTypeCore(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetItemTypeCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetLabeledByCore(impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IAutomationPeer> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetLabeledByCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetLocalizedControlTypeCore(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetLocalizedControlTypeCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetNameCore(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetNameCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetOrientationCore(Windows::UI::Xaml::Automation::Peers::AutomationOrientation * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetOrientationCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_HasKeyboardFocusCore(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().HasKeyboardFocusCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsContentElementCore(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().IsContentElementCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsControlElementCore(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().IsControlElementCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsEnabledCore(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().IsEnabledCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsKeyboardFocusableCore(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().IsKeyboardFocusableCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsOffscreenCore(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().IsOffscreenCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsPasswordCore(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().IsPasswordCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsRequiredForFormCore(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().IsRequiredForFormCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetFocusCore() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetFocusCore();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPeerFromPointCore(impl::abi_arg_in<Windows::Foundation::Point> point, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IAutomationPeer> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetPeerFromPointCore(*reinterpret_cast<const Windows::Foundation::Point *>(&point)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetLiveSettingCore(Windows::UI::Xaml::Automation::Peers::AutomationLiveSetting * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetLiveSettingCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2>
{
    HRESULT __stdcall abi_ShowContextMenuCore() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowContextMenuCore();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetControlledPeersCore(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Automation::Peers::AutomationPeer>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetControlledPeersCore());
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3>
{
    HRESULT __stdcall abi_NavigateCore(Windows::UI::Xaml::Automation::Peers::AutomationNavigationDirection direction, impl::abi_arg_out<Windows::Foundation::IInspectable> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().NavigateCore(direction));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetElementFromPointCore(impl::abi_arg_in<Windows::Foundation::Point> pointInWindowCoordinates, impl::abi_arg_out<Windows::Foundation::IInspectable> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetElementFromPointCore(*reinterpret_cast<const Windows::Foundation::Point *>(&pointInWindowCoordinates)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFocusedElementCore(impl::abi_arg_out<Windows::Foundation::IInspectable> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetFocusedElementCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAnnotationsCore(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetAnnotationsCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPositionInSetCore(int32_t * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetPositionInSetCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSizeOfSetCore(int32_t * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetSizeOfSetCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetLevelCore(int32_t * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetLevelCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4>
{
    HRESULT __stdcall abi_GetLandmarkTypeCore(Windows::UI::Xaml::Automation::Peers::AutomationLandmarkType * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetLandmarkTypeCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetLocalizedLandmarkTypeCore(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetLocalizedLandmarkTypeCore());
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5>
{
    HRESULT __stdcall abi_IsPeripheralCore(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().IsPeripheralCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsDataValidForFormCore(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().IsDataValidForFormCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFullDescriptionCore(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetFullDescriptionCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDescribedByCore(impl::abi_arg_out<Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::Automation::Peers::AutomationPeer>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetDescribedByCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFlowsToCore(impl::abi_arg_out<Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::Automation::Peers::AutomationPeer>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetFlowsToCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFlowsFromCore(impl::abi_arg_out<Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::Automation::Peers::AutomationPeer>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetFlowsFromCore());
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected>
{
    HRESULT __stdcall abi_PeerFromProvider(impl::abi_arg_in<Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> provider, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IAutomationPeer> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().PeerFromProvider(*reinterpret_cast<const Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple *>(&provider)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ProviderFromPeer(impl::abi_arg_in<Windows::UI::Xaml::Automation::Peers::IAutomationPeer> peer, impl::abi_arg_out<Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().ProviderFromPeer(*reinterpret_cast<const Windows::UI::Xaml::Automation::Peers::AutomationPeer *>(&peer)));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerStatics> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerStatics>
{
    HRESULT __stdcall abi_ListenerExists(Windows::UI::Xaml::Automation::Peers::AutomationEvents eventId, bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().ListenerExists(eventId));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerStatics3> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerStatics3>
{
    HRESULT __stdcall abi_GenerateRawElementProviderRuntimeId(impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::RawElementProviderRuntimeId> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GenerateRawElementProviderRuntimeId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IButtonAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IButtonAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IButtonAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IButtonAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IButton> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IButtonAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::Button *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::Primitives::IButtonBase> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::Primitives::ButtonBase *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::ICaptureElementAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::ICaptureElementAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::ICaptureElementAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::ICaptureElementAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::ICaptureElement> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::ICaptureElementAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::CaptureElement *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::ICheckBoxAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::ICheckBoxAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::ICheckBoxAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::ICheckBoxAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::ICheckBox> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::ICheckBoxAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::CheckBox *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IComboBoxAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IComboBoxAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IComboBoxAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IComboBoxAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IComboBox> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IComboBoxAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::ComboBox *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IComboBoxItemAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IComboBoxItemAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IComboBoxItemAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IComboBoxItemAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IComboBoxItem> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IComboBoxItemAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::ComboBoxItem *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IComboBoxItemDataAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IComboBoxItemDataAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IComboBoxItemDataAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IComboBoxItemDataAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithParentAndItem(impl::abi_arg_in<Windows::Foundation::IInspectable> item, impl::abi_arg_in<Windows::UI::Xaml::Automation::Peers::IComboBoxAutomationPeer> parent, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IComboBoxItemDataAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithParentAndItem(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&item), *reinterpret_cast<const Windows::UI::Xaml::Automation::Peers::ComboBoxAutomationPeer *>(&parent), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IDatePickerAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IDatePickerAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IDatePickerAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IDatePickerAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IDatePicker> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IDatePickerAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::DatePicker *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IDatePickerFlyoutPresenterAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IDatePickerFlyoutPresenterAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IFlipViewAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IFlipViewAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IFlipViewAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IFlipViewAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IFlipView> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IFlipViewAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::FlipView *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IFlipViewItemAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IFlipViewItemAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IFlipViewItemAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IFlipViewItemAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IFlipViewItem> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IFlipViewItemAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::FlipViewItem *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IFlipViewItemDataAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IFlipViewItemDataAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IFlipViewItemDataAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IFlipViewItemDataAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithParentAndItem(impl::abi_arg_in<Windows::Foundation::IInspectable> item, impl::abi_arg_in<Windows::UI::Xaml::Automation::Peers::IFlipViewAutomationPeer> parent, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IFlipViewItemDataAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithParentAndItem(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&item), *reinterpret_cast<const Windows::UI::Xaml::Automation::Peers::FlipViewAutomationPeer *>(&parent), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IFlyoutPresenterAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IFlyoutPresenterAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IFlyoutPresenterAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IFlyoutPresenterAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IFlyoutPresenter> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IFlyoutPresenterAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::FlyoutPresenter *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    HRESULT __stdcall get_Owner(impl::abi_arg_out<Windows::UI::Xaml::IUIElement> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Owner());
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::IFrameworkElement> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::FrameworkElement *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeerStatics> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeerStatics>
{
    HRESULT __stdcall abi_FromElement(impl::abi_arg_in<Windows::UI::Xaml::IUIElement> element, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IAutomationPeer> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().FromElement(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreatePeerForElement(impl::abi_arg_in<Windows::UI::Xaml::IUIElement> element, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IAutomationPeer> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().CreatePeerForElement(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&element)));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IGridViewAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IGridViewAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IGridViewAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IGridViewAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IGridView> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IGridViewAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::GridView *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IGridViewHeaderItemAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IGridViewHeaderItemAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IGridViewHeaderItemAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IGridViewHeaderItemAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IGridViewHeaderItem> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IGridViewHeaderItemAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::GridViewHeaderItem *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IGridViewItemAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IGridViewItemAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IGridViewItemAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IGridViewItemAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IGridViewItem> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IGridViewItemAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::GridViewItem *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IGridViewItemDataAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IGridViewItemDataAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IGridViewItemDataAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IGridViewItemDataAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithParentAndItem(impl::abi_arg_in<Windows::Foundation::IInspectable> item, impl::abi_arg_in<Windows::UI::Xaml::Automation::Peers::IGridViewAutomationPeer> parent, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IGridViewItemDataAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithParentAndItem(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&item), *reinterpret_cast<const Windows::UI::Xaml::Automation::Peers::GridViewAutomationPeer *>(&parent), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IGroupItemAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IGroupItemAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IGroupItemAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IGroupItemAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IGroupItem> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IGroupItemAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::GroupItem *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IHubAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IHubAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IHubAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IHubAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IHub> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IHubAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::Hub *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IHubSectionAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IHubSectionAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IHubSectionAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IHubSectionAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IHubSection> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IHubSectionAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::HubSection *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IHyperlinkButtonAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IHyperlinkButtonAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IHyperlinkButtonAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IHyperlinkButtonAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IHyperlinkButton> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IHyperlinkButtonAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::HyperlinkButton *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IImageAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IImageAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IImageAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IImageAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IImage> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IImageAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::Image *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IInkToolbarAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IInkToolbarAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer>
{
    HRESULT __stdcall get_Item(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Item());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ItemsControlAutomationPeer(impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ItemsControlAutomationPeer());
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithParentAndItem(impl::abi_arg_in<Windows::Foundation::IInspectable> item, impl::abi_arg_in<Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer> parent, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithParentAndItem(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&item), *reinterpret_cast<const Windows::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer *>(&parent), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2>
{
    HRESULT __stdcall abi_CreateItemAutomationPeer(impl::abi_arg_in<Windows::Foundation::IInspectable> item, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().CreateItemAutomationPeer(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&item)));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IItemsControl> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::ItemsControl *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2>
{
    HRESULT __stdcall abi_OnCreateItemAutomationPeer(impl::abi_arg_in<Windows::Foundation::IInspectable> item, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().OnCreateItemAutomationPeer(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&item)));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IListBoxAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IListBoxAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IListBoxAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IListBoxAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IListBox> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IListBoxAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::ListBox *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IListBoxItemAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IListBoxItemAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IListBoxItemAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IListBoxItemAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IListBoxItem> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IListBoxItemAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::ListBoxItem *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IListBoxItemDataAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IListBoxItemDataAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IListBoxItemDataAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IListBoxItemDataAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithParentAndItem(impl::abi_arg_in<Windows::Foundation::IInspectable> item, impl::abi_arg_in<Windows::UI::Xaml::Automation::Peers::IListBoxAutomationPeer> parent, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IListBoxItemDataAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithParentAndItem(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&item), *reinterpret_cast<const Windows::UI::Xaml::Automation::Peers::ListBoxAutomationPeer *>(&parent), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IListPickerFlyoutPresenterAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IListPickerFlyoutPresenterAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IListViewAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IListViewAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IListViewAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IListViewAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IListView> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IListViewAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::ListView *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IListViewBase> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::ListViewBase *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IListViewBaseHeaderItem> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::ListViewBaseHeaderItem *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IListViewHeaderItemAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IListViewHeaderItemAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IListViewHeaderItemAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IListViewHeaderItemAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IListViewHeaderItem> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IListViewHeaderItemAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::ListViewHeaderItem *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IListViewItemAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IListViewItemAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IListViewItemAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IListViewItemAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IListViewItem> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IListViewItemAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::ListViewItem *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IListViewItemDataAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IListViewItemDataAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IListViewItemDataAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IListViewItemDataAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithParentAndItem(impl::abi_arg_in<Windows::Foundation::IInspectable> item, impl::abi_arg_in<Windows::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeer> parent, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IListViewItemDataAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithParentAndItem(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&item), *reinterpret_cast<const Windows::UI::Xaml::Automation::Peers::ListViewBaseAutomationPeer *>(&parent), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::ILoopingSelectorAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::ILoopingSelectorAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::ILoopingSelectorItemAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::ILoopingSelectorItemAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::ILoopingSelectorItemDataAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::ILoopingSelectorItemDataAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IMapControlAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IMapControlAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IMediaElementAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IMediaElementAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IMediaElementAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IMediaElementAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IMediaElement> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IMediaElementAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::MediaElement *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IMediaPlayerElementAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IMediaPlayerElementAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IMediaPlayerElementAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IMediaPlayerElementAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IMediaPlayerElement> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IMediaPlayerElementAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::MediaPlayerElement *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IMediaTransportControlsAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IMediaTransportControlsAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IMediaTransportControlsAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IMediaTransportControlsAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IMediaTransportControls> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IMediaTransportControlsAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::MediaTransportControls *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IMenuFlyoutItemAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IMenuFlyoutItemAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IMenuFlyoutItemAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IMenuFlyoutItemAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IMenuFlyoutItem> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IMenuFlyoutItemAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::MenuFlyoutItem *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IMenuFlyoutPresenterAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IMenuFlyoutPresenterAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IMenuFlyoutPresenterAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IMenuFlyoutPresenterAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IMenuFlyoutPresenter> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IMenuFlyoutPresenterAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::MenuFlyoutPresenter *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IPasswordBoxAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IPasswordBoxAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IPasswordBoxAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IPasswordBoxAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IPasswordBox> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IPasswordBoxAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::PasswordBox *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IPickerFlyoutPresenterAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IPickerFlyoutPresenterAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IPivotAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IPivotAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IPivotAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IPivotAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IPivot> owner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IPivotAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::Pivot *>(&owner)));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IPivotItemAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IPivotItemAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IPivotItemAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IPivotItemAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IPivotItem> owner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IPivotItemAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::PivotItem *>(&owner)));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IPivotItemDataAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IPivotItemDataAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IPivotItemDataAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IPivotItemDataAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithParentAndItem(impl::abi_arg_in<Windows::Foundation::IInspectable> item, impl::abi_arg_in<Windows::UI::Xaml::Automation::Peers::IPivotAutomationPeer> parent, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IPivotItemDataAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithParentAndItem(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&item), *reinterpret_cast<const Windows::UI::Xaml::Automation::Peers::PivotAutomationPeer *>(&parent)));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IProgressBarAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IProgressBarAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IProgressBarAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IProgressBarAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IProgressBar> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IProgressBarAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::ProgressBar *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IProgressRingAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IProgressRingAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IProgressRingAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IProgressRingAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IProgressRing> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IProgressRingAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::ProgressRing *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IRadioButtonAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IRadioButtonAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IRadioButtonAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IRadioButtonAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IRadioButton> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IRadioButtonAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::RadioButton *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::Primitives::IRangeBase> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::Primitives::RangeBase *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IRepeatButtonAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IRepeatButtonAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IRepeatButtonAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IRepeatButtonAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::Primitives::IRepeatButton> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IRepeatButtonAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::Primitives::RepeatButton *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IRichEditBoxAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IRichEditBoxAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IRichEditBoxAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IRichEditBoxAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IRichEditBox> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IRichEditBoxAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::RichEditBox *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IRichTextBlockAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IRichTextBlockAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IRichTextBlockAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IRichTextBlockAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IRichTextBlock> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IRichTextBlockAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::RichTextBlock *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IRichTextBlockOverflowAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IRichTextBlockOverflowAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IRichTextBlockOverflowAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IRichTextBlockOverflowAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IRichTextBlockOverflow> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IRichTextBlockOverflowAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::RichTextBlockOverflow *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IScrollBarAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IScrollBarAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IScrollBarAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IScrollBarAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::Primitives::IScrollBar> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IScrollBarAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::Primitives::ScrollBar *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IScrollViewerAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IScrollViewerAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IScrollViewerAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IScrollViewerAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IScrollViewer> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IScrollViewerAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::ScrollViewer *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::ISearchBoxAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::ISearchBoxAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::ISearchBoxAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::ISearchBoxAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::ISearchBox> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::ISearchBoxAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::SearchBox *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::Primitives::ISelector> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::Primitives::Selector *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithParentAndItem(impl::abi_arg_in<Windows::Foundation::IInspectable> item, impl::abi_arg_in<Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer> parent, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithParentAndItem(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&item), *reinterpret_cast<const Windows::UI::Xaml::Automation::Peers::SelectorAutomationPeer *>(&parent), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::ISemanticZoomAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::ISemanticZoomAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::ISemanticZoomAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::ISemanticZoomAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::ISemanticZoom> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::ISemanticZoomAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::SemanticZoom *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::ISettingsFlyoutAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::ISettingsFlyoutAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::ISettingsFlyoutAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::ISettingsFlyoutAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::ISettingsFlyout> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::ISettingsFlyoutAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::SettingsFlyout *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::ISliderAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::ISliderAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::ISliderAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::ISliderAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::ISlider> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::ISliderAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::Slider *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::ITextBlockAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::ITextBlockAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::ITextBlockAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::ITextBlockAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::ITextBlock> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::ITextBlockAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::TextBlock *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::ITextBoxAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::ITextBoxAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::ITextBoxAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::ITextBoxAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::ITextBox> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::ITextBoxAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::TextBox *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IThumbAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IThumbAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IThumbAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IThumbAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::Primitives::IThumb> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IThumbAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::Primitives::Thumb *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::ITimePickerAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::ITimePickerAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::ITimePickerAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::ITimePickerAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::ITimePicker> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::ITimePickerAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::TimePicker *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::ITimePickerFlyoutPresenterAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::ITimePickerFlyoutPresenterAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::Primitives::IToggleButton> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::Primitives::ToggleButton *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IToggleMenuFlyoutItemAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IToggleMenuFlyoutItemAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IToggleMenuFlyoutItemAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IToggleMenuFlyoutItemAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IToggleMenuFlyoutItem> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IToggleMenuFlyoutItemAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::ToggleMenuFlyoutItem *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::Automation::Peers::IToggleSwitchAutomationPeer> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IToggleSwitchAutomationPeer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Automation::Peers::IToggleSwitchAutomationPeerFactory> : produce_base<D, Windows::UI::Xaml::Automation::Peers::IToggleSwitchAutomationPeerFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithOwner(impl::abi_arg_in<Windows::UI::Xaml::Controls::IToggleSwitch> owner, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IToggleSwitchAutomationPeer> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithOwner(*reinterpret_cast<const Windows::UI::Xaml::Controls::ToggleSwitch *>(&owner), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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

namespace Windows::UI::Xaml::Automation::Peers {

template <typename D> Windows::Foundation::IInspectable impl_IItemAutomationPeer<D>::Item() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IItemAutomationPeer)->get_Item(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer impl_IItemAutomationPeer<D>::ItemsControlAutomationPeer() const
{
    Windows::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer value { nullptr };
    check_hresult(WINRT_SHIM(IItemAutomationPeer)->get_ItemsControlAutomationPeer(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::ItemAutomationPeer impl_IItemAutomationPeerFactory<D>::CreateInstanceWithParentAndItem(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer & parent, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::ItemAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IItemAutomationPeerFactory)->abi_CreateInstanceWithParentAndItem(get_abi(item), get_abi(parent), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::ButtonBaseAutomationPeer impl_IButtonBaseAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::Primitives::ButtonBase & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::ButtonBaseAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IButtonBaseAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::CaptureElementAutomationPeer impl_ICaptureElementAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::CaptureElement & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::CaptureElementAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(ICaptureElementAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::ComboBoxItemAutomationPeer impl_IComboBoxItemAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::ComboBoxItem & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::ComboBoxItemAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IComboBoxItemAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::FlipViewItemAutomationPeer impl_IFlipViewItemAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::FlipViewItem & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::FlipViewItemAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IFlipViewItemAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::GroupItemAutomationPeer impl_IGroupItemAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::GroupItem & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::GroupItemAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IGroupItemAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::ImageAutomationPeer impl_IImageAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::Image & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::ImageAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IImageAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer impl_IItemsControlAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::ItemsControl & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IItemsControlAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::ItemAutomationPeer impl_IItemsControlAutomationPeer2<D>::CreateItemAutomationPeer(const Windows::Foundation::IInspectable & item) const
{
    Windows::UI::Xaml::Automation::Peers::ItemAutomationPeer returnValue { nullptr };
    check_hresult(WINRT_SHIM(IItemsControlAutomationPeer2)->abi_CreateItemAutomationPeer(get_abi(item), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::ItemAutomationPeer impl_IItemsControlAutomationPeerOverrides2<D>::OnCreateItemAutomationPeer(const Windows::Foundation::IInspectable & item) const
{
    Windows::UI::Xaml::Automation::Peers::ItemAutomationPeer returnValue { nullptr };
    check_hresult(WINRT_SHIM(IItemsControlAutomationPeerOverrides2)->abi_OnCreateItemAutomationPeer(get_abi(item), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::ListBoxItemAutomationPeer impl_IListBoxItemAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::ListBoxItem & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::ListBoxItemAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IListBoxItemAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::MediaTransportControlsAutomationPeer impl_IMediaTransportControlsAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::MediaTransportControls & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::MediaTransportControlsAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IMediaTransportControlsAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::PasswordBoxAutomationPeer impl_IPasswordBoxAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::PasswordBox & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::PasswordBoxAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IPasswordBoxAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::ProgressRingAutomationPeer impl_IProgressRingAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::ProgressRing & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::ProgressRingAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IProgressRingAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::RangeBaseAutomationPeer impl_IRangeBaseAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::Primitives::RangeBase & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::RangeBaseAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IRangeBaseAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::RichEditBoxAutomationPeer impl_IRichEditBoxAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::RichEditBox & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::RichEditBoxAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IRichEditBoxAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::RichTextBlockAutomationPeer impl_IRichTextBlockAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::RichTextBlock & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::RichTextBlockAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IRichTextBlockAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::RichTextBlockOverflowAutomationPeer impl_IRichTextBlockOverflowAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::RichTextBlockOverflow & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::RichTextBlockOverflowAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IRichTextBlockOverflowAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::SelectorItemAutomationPeer impl_ISelectorItemAutomationPeerFactory<D>::CreateInstanceWithParentAndItem(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::SelectorAutomationPeer & parent, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::SelectorItemAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(ISelectorItemAutomationPeerFactory)->abi_CreateInstanceWithParentAndItem(get_abi(item), get_abi(parent), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::SemanticZoomAutomationPeer impl_ISemanticZoomAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::SemanticZoom & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::SemanticZoomAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(ISemanticZoomAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::SettingsFlyoutAutomationPeer impl_ISettingsFlyoutAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::SettingsFlyout & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::SettingsFlyoutAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(ISettingsFlyoutAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::TextBlockAutomationPeer impl_ITextBlockAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::TextBlock & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::TextBlockAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(ITextBlockAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::TextBoxAutomationPeer impl_ITextBoxAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::TextBox & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::TextBoxAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(ITextBoxAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::ThumbAutomationPeer impl_IThumbAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::Primitives::Thumb & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::ThumbAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IThumbAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::ToggleSwitchAutomationPeer impl_IToggleSwitchAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::ToggleSwitch & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::ToggleSwitchAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IToggleSwitchAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::ButtonAutomationPeer impl_IButtonAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::Button & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::ButtonAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IButtonAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::ComboBoxItemDataAutomationPeer impl_IComboBoxItemDataAutomationPeerFactory<D>::CreateInstanceWithParentAndItem(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::ComboBoxAutomationPeer & parent, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::ComboBoxItemDataAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IComboBoxItemDataAutomationPeerFactory)->abi_CreateInstanceWithParentAndItem(get_abi(item), get_abi(parent), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::FlipViewItemDataAutomationPeer impl_IFlipViewItemDataAutomationPeerFactory<D>::CreateInstanceWithParentAndItem(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::FlipViewAutomationPeer & parent, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::FlipViewItemDataAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IFlipViewItemDataAutomationPeerFactory)->abi_CreateInstanceWithParentAndItem(get_abi(item), get_abi(parent), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::HyperlinkButtonAutomationPeer impl_IHyperlinkButtonAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::HyperlinkButton & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::HyperlinkButtonAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IHyperlinkButtonAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::ListBoxItemDataAutomationPeer impl_IListBoxItemDataAutomationPeerFactory<D>::CreateInstanceWithParentAndItem(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::ListBoxAutomationPeer & parent, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::ListBoxItemDataAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IListBoxItemDataAutomationPeerFactory)->abi_CreateInstanceWithParentAndItem(get_abi(item), get_abi(parent), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::ProgressBarAutomationPeer impl_IProgressBarAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::ProgressBar & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::ProgressBarAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IProgressBarAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::RepeatButtonAutomationPeer impl_IRepeatButtonAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::Primitives::RepeatButton & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::RepeatButtonAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IRepeatButtonAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::ScrollBarAutomationPeer impl_IScrollBarAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::Primitives::ScrollBar & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::ScrollBarAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IScrollBarAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::SelectorAutomationPeer impl_ISelectorAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::Primitives::Selector & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::SelectorAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(ISelectorAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::SliderAutomationPeer impl_ISliderAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::Slider & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::SliderAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(ISliderAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::ToggleButtonAutomationPeer impl_IToggleButtonAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::Primitives::ToggleButton & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::ToggleButtonAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IToggleButtonAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::CheckBoxAutomationPeer impl_ICheckBoxAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::CheckBox & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::CheckBoxAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(ICheckBoxAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::ComboBoxAutomationPeer impl_IComboBoxAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::ComboBox & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::ComboBoxAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IComboBoxAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::FlipViewAutomationPeer impl_IFlipViewAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::FlipView & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::FlipViewAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IFlipViewAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::ListBoxAutomationPeer impl_IListBoxAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::ListBox & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::ListBoxAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IListBoxAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::RadioButtonAutomationPeer impl_IRadioButtonAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::RadioButton & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::RadioButtonAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IRadioButtonAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::AppBarAutomationPeer impl_IAppBarAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::AppBar & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::AppBarAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IAppBarAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::AutoSuggestBoxAutomationPeer impl_IAutoSuggestBoxAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::AutoSuggestBox & owner) const
{
    Windows::UI::Xaml::Automation::Peers::AutoSuggestBoxAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IAutoSuggestBoxAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::DatePickerAutomationPeer impl_IDatePickerAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::DatePicker & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::DatePickerAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IDatePickerAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::FlyoutPresenterAutomationPeer impl_IFlyoutPresenterAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::FlyoutPresenter & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::FlyoutPresenterAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IFlyoutPresenterAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::GridViewItemAutomationPeer impl_IGridViewItemAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::GridViewItem & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::GridViewItemAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IGridViewItemAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::HubAutomationPeer impl_IHubAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::Hub & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::HubAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IHubAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::HubSectionAutomationPeer impl_IHubSectionAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::HubSection & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::HubSectionAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IHubSectionAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::ListViewBaseHeaderItemAutomationPeer impl_IListViewBaseHeaderItemAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::ListViewBaseHeaderItem & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::ListViewBaseHeaderItemAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IListViewBaseHeaderItemAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::ListViewItemAutomationPeer impl_IListViewItemAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::ListViewItem & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::ListViewItemAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IListViewItemAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::MediaElementAutomationPeer impl_IMediaElementAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::MediaElement & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::MediaElementAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IMediaElementAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::MediaPlayerElementAutomationPeer impl_IMediaPlayerElementAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::MediaPlayerElement & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::MediaPlayerElementAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IMediaPlayerElementAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::MenuFlyoutItemAutomationPeer impl_IMenuFlyoutItemAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::MenuFlyoutItem & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::MenuFlyoutItemAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IMenuFlyoutItemAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::ScrollViewerAutomationPeer impl_IScrollViewerAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::ScrollViewer & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::ScrollViewerAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IScrollViewerAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::SearchBoxAutomationPeer impl_ISearchBoxAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::SearchBox & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::SearchBoxAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(ISearchBoxAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::TimePickerAutomationPeer impl_ITimePickerAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::TimePicker & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::TimePickerAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(ITimePickerAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::ToggleMenuFlyoutItemAutomationPeer impl_IToggleMenuFlyoutItemAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::ToggleMenuFlyoutItem & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::ToggleMenuFlyoutItemAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IToggleMenuFlyoutItemAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::GridViewHeaderItemAutomationPeer impl_IGridViewHeaderItemAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::GridViewHeaderItem & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::GridViewHeaderItemAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IGridViewHeaderItemAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::GridViewItemDataAutomationPeer impl_IGridViewItemDataAutomationPeerFactory<D>::CreateInstanceWithParentAndItem(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::GridViewAutomationPeer & parent, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::GridViewItemDataAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IGridViewItemDataAutomationPeerFactory)->abi_CreateInstanceWithParentAndItem(get_abi(item), get_abi(parent), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::ListViewHeaderItemAutomationPeer impl_IListViewHeaderItemAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::ListViewHeaderItem & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::ListViewHeaderItemAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IListViewHeaderItemAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::ListViewItemDataAutomationPeer impl_IListViewItemDataAutomationPeerFactory<D>::CreateInstanceWithParentAndItem(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::ListViewBaseAutomationPeer & parent, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::ListViewItemDataAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IListViewItemDataAutomationPeerFactory)->abi_CreateInstanceWithParentAndItem(get_abi(item), get_abi(parent), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::MenuFlyoutPresenterAutomationPeer impl_IMenuFlyoutPresenterAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::MenuFlyoutPresenter & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::MenuFlyoutPresenterAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IMenuFlyoutPresenterAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::AppBarButtonAutomationPeer impl_IAppBarButtonAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::AppBarButton & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::AppBarButtonAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IAppBarButtonAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::AppBarToggleButtonAutomationPeer impl_IAppBarToggleButtonAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::AppBarToggleButton & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::AppBarToggleButtonAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IAppBarToggleButtonAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::ListViewBaseAutomationPeer impl_IListViewBaseAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::ListViewBase & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::ListViewBaseAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IListViewBaseAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::GridViewAutomationPeer impl_IGridViewAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::GridView & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::GridViewAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IGridViewAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::ListViewAutomationPeer impl_IListViewAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::ListView & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::ListViewAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IListViewAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::AutomationPeer impl_IAutomationPeer<D>::EventsSource() const
{
    Windows::UI::Xaml::Automation::Peers::AutomationPeer value { nullptr };
    check_hresult(WINRT_SHIM(IAutomationPeer)->get_EventsSource(put_abi(value)));
    return value;
}

template <typename D> void impl_IAutomationPeer<D>::EventsSource(const Windows::UI::Xaml::Automation::Peers::AutomationPeer & value) const
{
    check_hresult(WINRT_SHIM(IAutomationPeer)->put_EventsSource(get_abi(value)));
}

template <typename D> Windows::Foundation::IInspectable impl_IAutomationPeer<D>::GetPattern(Windows::UI::Xaml::Automation::Peers::PatternInterface patternInterface) const
{
    Windows::Foundation::IInspectable returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeer)->abi_GetPattern(patternInterface, put_abi(returnValue)));
    return returnValue;
}

template <typename D> void impl_IAutomationPeer<D>::RaiseAutomationEvent(Windows::UI::Xaml::Automation::Peers::AutomationEvents eventId) const
{
    check_hresult(WINRT_SHIM(IAutomationPeer)->abi_RaiseAutomationEvent(eventId));
}

template <typename D> void impl_IAutomationPeer<D>::RaisePropertyChangedEvent(const Windows::UI::Xaml::Automation::AutomationProperty & automationProperty, const Windows::Foundation::IInspectable & oldValue, const Windows::Foundation::IInspectable & newValue) const
{
    check_hresult(WINRT_SHIM(IAutomationPeer)->abi_RaisePropertyChangedEvent(get_abi(automationProperty), get_abi(oldValue), get_abi(newValue)));
}

template <typename D> hstring impl_IAutomationPeer<D>::GetAcceleratorKey() const
{
    hstring returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeer)->abi_GetAcceleratorKey(put_abi(returnValue)));
    return returnValue;
}

template <typename D> hstring impl_IAutomationPeer<D>::GetAccessKey() const
{
    hstring returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeer)->abi_GetAccessKey(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::AutomationControlType impl_IAutomationPeer<D>::GetAutomationControlType() const
{
    Windows::UI::Xaml::Automation::Peers::AutomationControlType returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeer)->abi_GetAutomationControlType(&returnValue));
    return returnValue;
}

template <typename D> hstring impl_IAutomationPeer<D>::GetAutomationId() const
{
    hstring returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeer)->abi_GetAutomationId(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::Rect impl_IAutomationPeer<D>::GetBoundingRectangle() const
{
    Windows::Foundation::Rect returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeer)->abi_GetBoundingRectangle(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeer> impl_IAutomationPeer<D>::GetChildren() const
{
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeer> returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeer)->abi_GetChildren(put_abi(returnValue)));
    return returnValue;
}

template <typename D> hstring impl_IAutomationPeer<D>::GetClassName() const
{
    hstring returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeer)->abi_GetClassName(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::Point impl_IAutomationPeer<D>::GetClickablePoint() const
{
    Windows::Foundation::Point returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeer)->abi_GetClickablePoint(put_abi(returnValue)));
    return returnValue;
}

template <typename D> hstring impl_IAutomationPeer<D>::GetHelpText() const
{
    hstring returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeer)->abi_GetHelpText(put_abi(returnValue)));
    return returnValue;
}

template <typename D> hstring impl_IAutomationPeer<D>::GetItemStatus() const
{
    hstring returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeer)->abi_GetItemStatus(put_abi(returnValue)));
    return returnValue;
}

template <typename D> hstring impl_IAutomationPeer<D>::GetItemType() const
{
    hstring returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeer)->abi_GetItemType(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::AutomationPeer impl_IAutomationPeer<D>::GetLabeledBy() const
{
    Windows::UI::Xaml::Automation::Peers::AutomationPeer returnValue { nullptr };
    check_hresult(WINRT_SHIM(IAutomationPeer)->abi_GetLabeledBy(put_abi(returnValue)));
    return returnValue;
}

template <typename D> hstring impl_IAutomationPeer<D>::GetLocalizedControlType() const
{
    hstring returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeer)->abi_GetLocalizedControlType(put_abi(returnValue)));
    return returnValue;
}

template <typename D> hstring impl_IAutomationPeer<D>::GetName() const
{
    hstring returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeer)->abi_GetName(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::AutomationOrientation impl_IAutomationPeer<D>::GetOrientation() const
{
    Windows::UI::Xaml::Automation::Peers::AutomationOrientation returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeer)->abi_GetOrientation(&returnValue));
    return returnValue;
}

template <typename D> bool impl_IAutomationPeer<D>::HasKeyboardFocus() const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeer)->abi_HasKeyboardFocus(&returnValue));
    return returnValue;
}

template <typename D> bool impl_IAutomationPeer<D>::IsContentElement() const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeer)->abi_IsContentElement(&returnValue));
    return returnValue;
}

template <typename D> bool impl_IAutomationPeer<D>::IsControlElement() const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeer)->abi_IsControlElement(&returnValue));
    return returnValue;
}

template <typename D> bool impl_IAutomationPeer<D>::IsEnabled() const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeer)->abi_IsEnabled(&returnValue));
    return returnValue;
}

template <typename D> bool impl_IAutomationPeer<D>::IsKeyboardFocusable() const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeer)->abi_IsKeyboardFocusable(&returnValue));
    return returnValue;
}

template <typename D> bool impl_IAutomationPeer<D>::IsOffscreen() const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeer)->abi_IsOffscreen(&returnValue));
    return returnValue;
}

template <typename D> bool impl_IAutomationPeer<D>::IsPassword() const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeer)->abi_IsPassword(&returnValue));
    return returnValue;
}

template <typename D> bool impl_IAutomationPeer<D>::IsRequiredForForm() const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeer)->abi_IsRequiredForForm(&returnValue));
    return returnValue;
}

template <typename D> void impl_IAutomationPeer<D>::SetFocus() const
{
    check_hresult(WINRT_SHIM(IAutomationPeer)->abi_SetFocus());
}

template <typename D> Windows::UI::Xaml::Automation::Peers::AutomationPeer impl_IAutomationPeer<D>::GetParent() const
{
    Windows::UI::Xaml::Automation::Peers::AutomationPeer returnValue { nullptr };
    check_hresult(WINRT_SHIM(IAutomationPeer)->abi_GetParent(put_abi(returnValue)));
    return returnValue;
}

template <typename D> void impl_IAutomationPeer<D>::InvalidatePeer() const
{
    check_hresult(WINRT_SHIM(IAutomationPeer)->abi_InvalidatePeer());
}

template <typename D> Windows::UI::Xaml::Automation::Peers::AutomationPeer impl_IAutomationPeer<D>::GetPeerFromPoint(const Windows::Foundation::Point & point) const
{
    Windows::UI::Xaml::Automation::Peers::AutomationPeer returnValue { nullptr };
    check_hresult(WINRT_SHIM(IAutomationPeer)->abi_GetPeerFromPoint(get_abi(point), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::AutomationLiveSetting impl_IAutomationPeer<D>::GetLiveSetting() const
{
    Windows::UI::Xaml::Automation::Peers::AutomationLiveSetting returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeer)->abi_GetLiveSetting(&returnValue));
    return returnValue;
}

template <typename D> Windows::Foundation::IInspectable impl_IAutomationPeerOverrides<D>::GetPatternCore(Windows::UI::Xaml::Automation::Peers::PatternInterface patternInterface) const
{
    Windows::Foundation::IInspectable returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides)->abi_GetPatternCore(patternInterface, put_abi(returnValue)));
    return returnValue;
}

template <typename D> hstring impl_IAutomationPeerOverrides<D>::GetAcceleratorKeyCore() const
{
    hstring returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides)->abi_GetAcceleratorKeyCore(put_abi(returnValue)));
    return returnValue;
}

template <typename D> hstring impl_IAutomationPeerOverrides<D>::GetAccessKeyCore() const
{
    hstring returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides)->abi_GetAccessKeyCore(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::AutomationControlType impl_IAutomationPeerOverrides<D>::GetAutomationControlTypeCore() const
{
    Windows::UI::Xaml::Automation::Peers::AutomationControlType returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides)->abi_GetAutomationControlTypeCore(&returnValue));
    return returnValue;
}

template <typename D> hstring impl_IAutomationPeerOverrides<D>::GetAutomationIdCore() const
{
    hstring returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides)->abi_GetAutomationIdCore(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::Rect impl_IAutomationPeerOverrides<D>::GetBoundingRectangleCore() const
{
    Windows::Foundation::Rect returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides)->abi_GetBoundingRectangleCore(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeer> impl_IAutomationPeerOverrides<D>::GetChildrenCore() const
{
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeer> returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides)->abi_GetChildrenCore(put_abi(returnValue)));
    return returnValue;
}

template <typename D> hstring impl_IAutomationPeerOverrides<D>::GetClassNameCore() const
{
    hstring returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides)->abi_GetClassNameCore(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::Point impl_IAutomationPeerOverrides<D>::GetClickablePointCore() const
{
    Windows::Foundation::Point returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides)->abi_GetClickablePointCore(put_abi(returnValue)));
    return returnValue;
}

template <typename D> hstring impl_IAutomationPeerOverrides<D>::GetHelpTextCore() const
{
    hstring returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides)->abi_GetHelpTextCore(put_abi(returnValue)));
    return returnValue;
}

template <typename D> hstring impl_IAutomationPeerOverrides<D>::GetItemStatusCore() const
{
    hstring returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides)->abi_GetItemStatusCore(put_abi(returnValue)));
    return returnValue;
}

template <typename D> hstring impl_IAutomationPeerOverrides<D>::GetItemTypeCore() const
{
    hstring returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides)->abi_GetItemTypeCore(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::AutomationPeer impl_IAutomationPeerOverrides<D>::GetLabeledByCore() const
{
    Windows::UI::Xaml::Automation::Peers::AutomationPeer returnValue { nullptr };
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides)->abi_GetLabeledByCore(put_abi(returnValue)));
    return returnValue;
}

template <typename D> hstring impl_IAutomationPeerOverrides<D>::GetLocalizedControlTypeCore() const
{
    hstring returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides)->abi_GetLocalizedControlTypeCore(put_abi(returnValue)));
    return returnValue;
}

template <typename D> hstring impl_IAutomationPeerOverrides<D>::GetNameCore() const
{
    hstring returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides)->abi_GetNameCore(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::AutomationOrientation impl_IAutomationPeerOverrides<D>::GetOrientationCore() const
{
    Windows::UI::Xaml::Automation::Peers::AutomationOrientation returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides)->abi_GetOrientationCore(&returnValue));
    return returnValue;
}

template <typename D> bool impl_IAutomationPeerOverrides<D>::HasKeyboardFocusCore() const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides)->abi_HasKeyboardFocusCore(&returnValue));
    return returnValue;
}

template <typename D> bool impl_IAutomationPeerOverrides<D>::IsContentElementCore() const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides)->abi_IsContentElementCore(&returnValue));
    return returnValue;
}

template <typename D> bool impl_IAutomationPeerOverrides<D>::IsControlElementCore() const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides)->abi_IsControlElementCore(&returnValue));
    return returnValue;
}

template <typename D> bool impl_IAutomationPeerOverrides<D>::IsEnabledCore() const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides)->abi_IsEnabledCore(&returnValue));
    return returnValue;
}

template <typename D> bool impl_IAutomationPeerOverrides<D>::IsKeyboardFocusableCore() const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides)->abi_IsKeyboardFocusableCore(&returnValue));
    return returnValue;
}

template <typename D> bool impl_IAutomationPeerOverrides<D>::IsOffscreenCore() const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides)->abi_IsOffscreenCore(&returnValue));
    return returnValue;
}

template <typename D> bool impl_IAutomationPeerOverrides<D>::IsPasswordCore() const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides)->abi_IsPasswordCore(&returnValue));
    return returnValue;
}

template <typename D> bool impl_IAutomationPeerOverrides<D>::IsRequiredForFormCore() const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides)->abi_IsRequiredForFormCore(&returnValue));
    return returnValue;
}

template <typename D> void impl_IAutomationPeerOverrides<D>::SetFocusCore() const
{
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides)->abi_SetFocusCore());
}

template <typename D> Windows::UI::Xaml::Automation::Peers::AutomationPeer impl_IAutomationPeerOverrides<D>::GetPeerFromPointCore(const Windows::Foundation::Point & point) const
{
    Windows::UI::Xaml::Automation::Peers::AutomationPeer returnValue { nullptr };
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides)->abi_GetPeerFromPointCore(get_abi(point), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::AutomationLiveSetting impl_IAutomationPeerOverrides<D>::GetLiveSettingCore() const
{
    Windows::UI::Xaml::Automation::Peers::AutomationLiveSetting returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides)->abi_GetLiveSettingCore(&returnValue));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::AutomationPeer impl_IAutomationPeerProtected<D>::PeerFromProvider(const Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple & provider) const
{
    Windows::UI::Xaml::Automation::Peers::AutomationPeer returnValue { nullptr };
    check_hresult(WINRT_SHIM(IAutomationPeerProtected)->abi_PeerFromProvider(get_abi(provider), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple impl_IAutomationPeerProtected<D>::ProviderFromPeer(const Windows::UI::Xaml::Automation::Peers::AutomationPeer & peer) const
{
    Windows::UI::Xaml::Automation::Provider::IRawElementProviderSimple returnValue { nullptr };
    check_hresult(WINRT_SHIM(IAutomationPeerProtected)->abi_ProviderFromPeer(get_abi(peer), put_abi(returnValue)));
    return returnValue;
}

template <typename D> bool impl_IAutomationPeerStatics<D>::ListenerExists(Windows::UI::Xaml::Automation::Peers::AutomationEvents eventId) const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeerStatics)->abi_ListenerExists(eventId, &returnValue));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::AutomationPeer impl_IAutomationPeerFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::AutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IAutomationPeerFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> void impl_IAutomationPeerOverrides2<D>::ShowContextMenuCore() const
{
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides2)->abi_ShowContextMenuCore());
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Automation::Peers::AutomationPeer> impl_IAutomationPeerOverrides2<D>::GetControlledPeersCore() const
{
    Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Automation::Peers::AutomationPeer> returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides2)->abi_GetControlledPeersCore(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IInspectable impl_IAutomationPeer3<D>::Navigate(Windows::UI::Xaml::Automation::Peers::AutomationNavigationDirection direction) const
{
    Windows::Foundation::IInspectable returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeer3)->abi_Navigate(direction, put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IInspectable impl_IAutomationPeer3<D>::GetElementFromPoint(const Windows::Foundation::Point & pointInWindowCoordinates) const
{
    Windows::Foundation::IInspectable returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeer3)->abi_GetElementFromPoint(get_abi(pointInWindowCoordinates), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IInspectable impl_IAutomationPeer3<D>::GetFocusedElement() const
{
    Windows::Foundation::IInspectable returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeer3)->abi_GetFocusedElement(put_abi(returnValue)));
    return returnValue;
}

template <typename D> void impl_IAutomationPeer3<D>::ShowContextMenu() const
{
    check_hresult(WINRT_SHIM(IAutomationPeer3)->abi_ShowContextMenu());
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Automation::Peers::AutomationPeer> impl_IAutomationPeer3<D>::GetControlledPeers() const
{
    Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Automation::Peers::AutomationPeer> returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeer3)->abi_GetControlledPeers(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation> impl_IAutomationPeer3<D>::GetAnnotations() const
{
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation> returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeer3)->abi_GetAnnotations(put_abi(returnValue)));
    return returnValue;
}

template <typename D> void impl_IAutomationPeer3<D>::SetParent(const Windows::UI::Xaml::Automation::Peers::AutomationPeer & peer) const
{
    check_hresult(WINRT_SHIM(IAutomationPeer3)->abi_SetParent(get_abi(peer)));
}

template <typename D> void impl_IAutomationPeer3<D>::RaiseTextEditTextChangedEvent(Windows::UI::Xaml::Automation::AutomationTextEditChangeType automationTextEditChangeType, vector_view<hstring> changedData) const
{
    check_hresult(WINRT_SHIM(IAutomationPeer3)->abi_RaiseTextEditTextChangedEvent(automationTextEditChangeType, get_abi(changedData)));
}

template <typename D> int32_t impl_IAutomationPeer3<D>::GetPositionInSet() const
{
    int32_t returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeer3)->abi_GetPositionInSet(&returnValue));
    return returnValue;
}

template <typename D> int32_t impl_IAutomationPeer3<D>::GetSizeOfSet() const
{
    int32_t returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeer3)->abi_GetSizeOfSet(&returnValue));
    return returnValue;
}

template <typename D> int32_t impl_IAutomationPeer3<D>::GetLevel() const
{
    int32_t returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeer3)->abi_GetLevel(&returnValue));
    return returnValue;
}

template <typename D> void impl_IAutomationPeer3<D>::RaiseStructureChangedEvent(Windows::UI::Xaml::Automation::Peers::AutomationStructureChangeType structureChangeType, const Windows::UI::Xaml::Automation::Peers::AutomationPeer & child) const
{
    check_hresult(WINRT_SHIM(IAutomationPeer3)->abi_RaiseStructureChangedEvent(structureChangeType, get_abi(child)));
}

template <typename D> Windows::Foundation::IInspectable impl_IAutomationPeerOverrides3<D>::NavigateCore(Windows::UI::Xaml::Automation::Peers::AutomationNavigationDirection direction) const
{
    Windows::Foundation::IInspectable returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides3)->abi_NavigateCore(direction, put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IInspectable impl_IAutomationPeerOverrides3<D>::GetElementFromPointCore(const Windows::Foundation::Point & pointInWindowCoordinates) const
{
    Windows::Foundation::IInspectable returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides3)->abi_GetElementFromPointCore(get_abi(pointInWindowCoordinates), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IInspectable impl_IAutomationPeerOverrides3<D>::GetFocusedElementCore() const
{
    Windows::Foundation::IInspectable returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides3)->abi_GetFocusedElementCore(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation> impl_IAutomationPeerOverrides3<D>::GetAnnotationsCore() const
{
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation> returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides3)->abi_GetAnnotationsCore(put_abi(returnValue)));
    return returnValue;
}

template <typename D> int32_t impl_IAutomationPeerOverrides3<D>::GetPositionInSetCore() const
{
    int32_t returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides3)->abi_GetPositionInSetCore(&returnValue));
    return returnValue;
}

template <typename D> int32_t impl_IAutomationPeerOverrides3<D>::GetSizeOfSetCore() const
{
    int32_t returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides3)->abi_GetSizeOfSetCore(&returnValue));
    return returnValue;
}

template <typename D> int32_t impl_IAutomationPeerOverrides3<D>::GetLevelCore() const
{
    int32_t returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides3)->abi_GetLevelCore(&returnValue));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::RawElementProviderRuntimeId impl_IAutomationPeerStatics3<D>::GenerateRawElementProviderRuntimeId() const
{
    Windows::UI::Xaml::Automation::Peers::RawElementProviderRuntimeId returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeerStatics3)->abi_GenerateRawElementProviderRuntimeId(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::AutomationLandmarkType impl_IAutomationPeer4<D>::GetLandmarkType() const
{
    Windows::UI::Xaml::Automation::Peers::AutomationLandmarkType returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeer4)->abi_GetLandmarkType(&returnValue));
    return returnValue;
}

template <typename D> hstring impl_IAutomationPeer4<D>::GetLocalizedLandmarkType() const
{
    hstring returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeer4)->abi_GetLocalizedLandmarkType(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::AutomationLandmarkType impl_IAutomationPeerOverrides4<D>::GetLandmarkTypeCore() const
{
    Windows::UI::Xaml::Automation::Peers::AutomationLandmarkType returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides4)->abi_GetLandmarkTypeCore(&returnValue));
    return returnValue;
}

template <typename D> hstring impl_IAutomationPeerOverrides4<D>::GetLocalizedLandmarkTypeCore() const
{
    hstring returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides4)->abi_GetLocalizedLandmarkTypeCore(put_abi(returnValue)));
    return returnValue;
}

template <typename D> bool impl_IAutomationPeer5<D>::IsPeripheral() const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeer5)->abi_IsPeripheral(&returnValue));
    return returnValue;
}

template <typename D> bool impl_IAutomationPeer5<D>::IsDataValidForForm() const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeer5)->abi_IsDataValidForForm(&returnValue));
    return returnValue;
}

template <typename D> hstring impl_IAutomationPeer5<D>::GetFullDescription() const
{
    hstring returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeer5)->abi_GetFullDescription(put_abi(returnValue)));
    return returnValue;
}

template <typename D> bool impl_IAutomationPeerOverrides5<D>::IsPeripheralCore() const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides5)->abi_IsPeripheralCore(&returnValue));
    return returnValue;
}

template <typename D> bool impl_IAutomationPeerOverrides5<D>::IsDataValidForFormCore() const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides5)->abi_IsDataValidForFormCore(&returnValue));
    return returnValue;
}

template <typename D> hstring impl_IAutomationPeerOverrides5<D>::GetFullDescriptionCore() const
{
    hstring returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides5)->abi_GetFullDescriptionCore(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::Automation::Peers::AutomationPeer> impl_IAutomationPeerOverrides5<D>::GetDescribedByCore() const
{
    Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::Automation::Peers::AutomationPeer> returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides5)->abi_GetDescribedByCore(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::Automation::Peers::AutomationPeer> impl_IAutomationPeerOverrides5<D>::GetFlowsToCore() const
{
    Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::Automation::Peers::AutomationPeer> returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides5)->abi_GetFlowsToCore(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::Automation::Peers::AutomationPeer> impl_IAutomationPeerOverrides5<D>::GetFlowsFromCore() const
{
    Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::Automation::Peers::AutomationPeer> returnValue;
    check_hresult(WINRT_SHIM(IAutomationPeerOverrides5)->abi_GetFlowsFromCore(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Automation::AnnotationType impl_IAutomationPeerAnnotation<D>::Type() const
{
    Windows::UI::Xaml::Automation::AnnotationType value {};
    check_hresult(WINRT_SHIM(IAutomationPeerAnnotation)->get_Type(&value));
    return value;
}

template <typename D> void impl_IAutomationPeerAnnotation<D>::Type(Windows::UI::Xaml::Automation::AnnotationType value) const
{
    check_hresult(WINRT_SHIM(IAutomationPeerAnnotation)->put_Type(value));
}

template <typename D> Windows::UI::Xaml::Automation::Peers::AutomationPeer impl_IAutomationPeerAnnotation<D>::Peer() const
{
    Windows::UI::Xaml::Automation::Peers::AutomationPeer value { nullptr };
    check_hresult(WINRT_SHIM(IAutomationPeerAnnotation)->get_Peer(put_abi(value)));
    return value;
}

template <typename D> void impl_IAutomationPeerAnnotation<D>::Peer(const Windows::UI::Xaml::Automation::Peers::AutomationPeer & value) const
{
    check_hresult(WINRT_SHIM(IAutomationPeerAnnotation)->put_Peer(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IAutomationPeerAnnotationStatics<D>::TypeProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IAutomationPeerAnnotationStatics)->get_TypeProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IAutomationPeerAnnotationStatics<D>::PeerProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IAutomationPeerAnnotationStatics)->get_PeerProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation impl_IAutomationPeerAnnotationFactory<D>::CreateInstance(Windows::UI::Xaml::Automation::AnnotationType type) const
{
    Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation instance { nullptr };
    check_hresult(WINRT_SHIM(IAutomationPeerAnnotationFactory)->abi_CreateInstance(type, put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation impl_IAutomationPeerAnnotationFactory<D>::CreateWithPeerParameter(Windows::UI::Xaml::Automation::AnnotationType type, const Windows::UI::Xaml::Automation::Peers::AutomationPeer & peer) const
{
    Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation instance { nullptr };
    check_hresult(WINRT_SHIM(IAutomationPeerAnnotationFactory)->abi_CreateWithPeerParameter(type, get_abi(peer), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::UIElement impl_IFrameworkElementAutomationPeer<D>::Owner() const
{
    Windows::UI::Xaml::UIElement value { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElementAutomationPeer)->get_Owner(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::AutomationPeer impl_IFrameworkElementAutomationPeerStatics<D>::FromElement(const Windows::UI::Xaml::UIElement & element) const
{
    Windows::UI::Xaml::Automation::Peers::AutomationPeer returnValue { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElementAutomationPeerStatics)->abi_FromElement(get_abi(element), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::AutomationPeer impl_IFrameworkElementAutomationPeerStatics<D>::CreatePeerForElement(const Windows::UI::Xaml::UIElement & element) const
{
    Windows::UI::Xaml::Automation::Peers::AutomationPeer returnValue { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElementAutomationPeerStatics)->abi_CreatePeerForElement(get_abi(element), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer impl_IFrameworkElementAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::FrameworkElement & owner, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElementAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::PivotItemAutomationPeer impl_IPivotItemAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::PivotItem & owner) const
{
    Windows::UI::Xaml::Automation::Peers::PivotItemAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IPivotItemAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::PivotItemDataAutomationPeer impl_IPivotItemDataAutomationPeerFactory<D>::CreateInstanceWithParentAndItem(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::PivotAutomationPeer & parent) const
{
    Windows::UI::Xaml::Automation::Peers::PivotItemDataAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IPivotItemDataAutomationPeerFactory)->abi_CreateInstanceWithParentAndItem(get_abi(item), get_abi(parent), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Automation::Peers::PivotAutomationPeer impl_IPivotAutomationPeerFactory<D>::CreateInstanceWithOwner(const Windows::UI::Xaml::Controls::Pivot & owner) const
{
    Windows::UI::Xaml::Automation::Peers::PivotAutomationPeer instance { nullptr };
    check_hresult(WINRT_SHIM(IPivotAutomationPeerFactory)->abi_CreateInstanceWithOwner(get_abi(owner), put_abi(instance)));
    return instance;
}

inline AppBarAutomationPeer::AppBarAutomationPeer(const Windows::UI::Xaml::Controls::AppBar & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<AppBarAutomationPeer, IAppBarAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline AppBarButtonAutomationPeer::AppBarButtonAutomationPeer(const Windows::UI::Xaml::Controls::AppBarButton & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<AppBarButtonAutomationPeer, IAppBarButtonAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline AppBarToggleButtonAutomationPeer::AppBarToggleButtonAutomationPeer(const Windows::UI::Xaml::Controls::AppBarToggleButton & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<AppBarToggleButtonAutomationPeer, IAppBarToggleButtonAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline AutoSuggestBoxAutomationPeer::AutoSuggestBoxAutomationPeer(const Windows::UI::Xaml::Controls::AutoSuggestBox & owner) :
    AutoSuggestBoxAutomationPeer(get_activation_factory<AutoSuggestBoxAutomationPeer, IAutoSuggestBoxAutomationPeerFactory>().CreateInstanceWithOwner(owner))
{}

inline bool AutomationPeer::ListenerExists(Windows::UI::Xaml::Automation::Peers::AutomationEvents eventId)
{
    return get_activation_factory<AutomationPeer, IAutomationPeerStatics>().ListenerExists(eventId);
}

inline Windows::UI::Xaml::Automation::Peers::RawElementProviderRuntimeId AutomationPeer::GenerateRawElementProviderRuntimeId()
{
    return get_activation_factory<AutomationPeer, IAutomationPeerStatics3>().GenerateRawElementProviderRuntimeId();
}

inline AutomationPeerAnnotation::AutomationPeerAnnotation() :
    AutomationPeerAnnotation(activate_instance<AutomationPeerAnnotation>())
{}

inline AutomationPeerAnnotation::AutomationPeerAnnotation(Windows::UI::Xaml::Automation::AnnotationType type) :
    AutomationPeerAnnotation(get_activation_factory<AutomationPeerAnnotation, IAutomationPeerAnnotationFactory>().CreateInstance(type))
{}

inline AutomationPeerAnnotation::AutomationPeerAnnotation(Windows::UI::Xaml::Automation::AnnotationType type, const Windows::UI::Xaml::Automation::Peers::AutomationPeer & peer) :
    AutomationPeerAnnotation(get_activation_factory<AutomationPeerAnnotation, IAutomationPeerAnnotationFactory>().CreateWithPeerParameter(type, peer))
{}

inline Windows::UI::Xaml::DependencyProperty AutomationPeerAnnotation::TypeProperty()
{
    return get_activation_factory<AutomationPeerAnnotation, IAutomationPeerAnnotationStatics>().TypeProperty();
}

inline Windows::UI::Xaml::DependencyProperty AutomationPeerAnnotation::PeerProperty()
{
    return get_activation_factory<AutomationPeerAnnotation, IAutomationPeerAnnotationStatics>().PeerProperty();
}

inline ButtonAutomationPeer::ButtonAutomationPeer(const Windows::UI::Xaml::Controls::Button & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<ButtonAutomationPeer, IButtonAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline CaptureElementAutomationPeer::CaptureElementAutomationPeer(const Windows::UI::Xaml::Controls::CaptureElement & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<CaptureElementAutomationPeer, ICaptureElementAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline CheckBoxAutomationPeer::CheckBoxAutomationPeer(const Windows::UI::Xaml::Controls::CheckBox & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<CheckBoxAutomationPeer, ICheckBoxAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline ComboBoxAutomationPeer::ComboBoxAutomationPeer(const Windows::UI::Xaml::Controls::ComboBox & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<ComboBoxAutomationPeer, IComboBoxAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline ComboBoxItemAutomationPeer::ComboBoxItemAutomationPeer(const Windows::UI::Xaml::Controls::ComboBoxItem & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<ComboBoxItemAutomationPeer, IComboBoxItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline ComboBoxItemDataAutomationPeer::ComboBoxItemDataAutomationPeer(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::ComboBoxAutomationPeer & parent)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<ComboBoxItemDataAutomationPeer, IComboBoxItemDataAutomationPeerFactory>().CreateInstanceWithParentAndItem(item, parent, outer, inner));
}

inline DatePickerAutomationPeer::DatePickerAutomationPeer(const Windows::UI::Xaml::Controls::DatePicker & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<DatePickerAutomationPeer, IDatePickerAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline FlipViewAutomationPeer::FlipViewAutomationPeer(const Windows::UI::Xaml::Controls::FlipView & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<FlipViewAutomationPeer, IFlipViewAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline FlipViewItemAutomationPeer::FlipViewItemAutomationPeer(const Windows::UI::Xaml::Controls::FlipViewItem & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<FlipViewItemAutomationPeer, IFlipViewItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline FlipViewItemDataAutomationPeer::FlipViewItemDataAutomationPeer(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::FlipViewAutomationPeer & parent)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<FlipViewItemDataAutomationPeer, IFlipViewItemDataAutomationPeerFactory>().CreateInstanceWithParentAndItem(item, parent, outer, inner));
}

inline FlyoutPresenterAutomationPeer::FlyoutPresenterAutomationPeer(const Windows::UI::Xaml::Controls::FlyoutPresenter & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<FlyoutPresenterAutomationPeer, IFlyoutPresenterAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline FrameworkElementAutomationPeer::FrameworkElementAutomationPeer(const Windows::UI::Xaml::FrameworkElement & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<FrameworkElementAutomationPeer, IFrameworkElementAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline Windows::UI::Xaml::Automation::Peers::AutomationPeer FrameworkElementAutomationPeer::FromElement(const Windows::UI::Xaml::UIElement & element)
{
    return get_activation_factory<FrameworkElementAutomationPeer, IFrameworkElementAutomationPeerStatics>().FromElement(element);
}

inline Windows::UI::Xaml::Automation::Peers::AutomationPeer FrameworkElementAutomationPeer::CreatePeerForElement(const Windows::UI::Xaml::UIElement & element)
{
    return get_activation_factory<FrameworkElementAutomationPeer, IFrameworkElementAutomationPeerStatics>().CreatePeerForElement(element);
}

inline GridViewAutomationPeer::GridViewAutomationPeer(const Windows::UI::Xaml::Controls::GridView & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<GridViewAutomationPeer, IGridViewAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline GridViewHeaderItemAutomationPeer::GridViewHeaderItemAutomationPeer(const Windows::UI::Xaml::Controls::GridViewHeaderItem & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<GridViewHeaderItemAutomationPeer, IGridViewHeaderItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline GridViewItemAutomationPeer::GridViewItemAutomationPeer(const Windows::UI::Xaml::Controls::GridViewItem & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<GridViewItemAutomationPeer, IGridViewItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline GridViewItemDataAutomationPeer::GridViewItemDataAutomationPeer(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::GridViewAutomationPeer & parent)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<GridViewItemDataAutomationPeer, IGridViewItemDataAutomationPeerFactory>().CreateInstanceWithParentAndItem(item, parent, outer, inner));
}

inline GroupItemAutomationPeer::GroupItemAutomationPeer(const Windows::UI::Xaml::Controls::GroupItem & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<GroupItemAutomationPeer, IGroupItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline HubAutomationPeer::HubAutomationPeer(const Windows::UI::Xaml::Controls::Hub & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<HubAutomationPeer, IHubAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline HubSectionAutomationPeer::HubSectionAutomationPeer(const Windows::UI::Xaml::Controls::HubSection & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<HubSectionAutomationPeer, IHubSectionAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline HyperlinkButtonAutomationPeer::HyperlinkButtonAutomationPeer(const Windows::UI::Xaml::Controls::HyperlinkButton & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<HyperlinkButtonAutomationPeer, IHyperlinkButtonAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline ImageAutomationPeer::ImageAutomationPeer(const Windows::UI::Xaml::Controls::Image & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<ImageAutomationPeer, IImageAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline ItemAutomationPeer::ItemAutomationPeer(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer & parent)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<ItemAutomationPeer, IItemAutomationPeerFactory>().CreateInstanceWithParentAndItem(item, parent, outer, inner));
}

inline ItemsControlAutomationPeer::ItemsControlAutomationPeer(const Windows::UI::Xaml::Controls::ItemsControl & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<ItemsControlAutomationPeer, IItemsControlAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline ListBoxAutomationPeer::ListBoxAutomationPeer(const Windows::UI::Xaml::Controls::ListBox & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<ListBoxAutomationPeer, IListBoxAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline ListBoxItemAutomationPeer::ListBoxItemAutomationPeer(const Windows::UI::Xaml::Controls::ListBoxItem & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<ListBoxItemAutomationPeer, IListBoxItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline ListBoxItemDataAutomationPeer::ListBoxItemDataAutomationPeer(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::ListBoxAutomationPeer & parent)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<ListBoxItemDataAutomationPeer, IListBoxItemDataAutomationPeerFactory>().CreateInstanceWithParentAndItem(item, parent, outer, inner));
}

inline ListViewAutomationPeer::ListViewAutomationPeer(const Windows::UI::Xaml::Controls::ListView & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<ListViewAutomationPeer, IListViewAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline ListViewBaseAutomationPeer::ListViewBaseAutomationPeer(const Windows::UI::Xaml::Controls::ListViewBase & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<ListViewBaseAutomationPeer, IListViewBaseAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline ListViewHeaderItemAutomationPeer::ListViewHeaderItemAutomationPeer(const Windows::UI::Xaml::Controls::ListViewHeaderItem & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<ListViewHeaderItemAutomationPeer, IListViewHeaderItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline ListViewItemAutomationPeer::ListViewItemAutomationPeer(const Windows::UI::Xaml::Controls::ListViewItem & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<ListViewItemAutomationPeer, IListViewItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline ListViewItemDataAutomationPeer::ListViewItemDataAutomationPeer(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::ListViewBaseAutomationPeer & parent)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<ListViewItemDataAutomationPeer, IListViewItemDataAutomationPeerFactory>().CreateInstanceWithParentAndItem(item, parent, outer, inner));
}

inline MediaElementAutomationPeer::MediaElementAutomationPeer(const Windows::UI::Xaml::Controls::MediaElement & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<MediaElementAutomationPeer, IMediaElementAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline MediaPlayerElementAutomationPeer::MediaPlayerElementAutomationPeer(const Windows::UI::Xaml::Controls::MediaPlayerElement & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<MediaPlayerElementAutomationPeer, IMediaPlayerElementAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline MediaTransportControlsAutomationPeer::MediaTransportControlsAutomationPeer(const Windows::UI::Xaml::Controls::MediaTransportControls & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<MediaTransportControlsAutomationPeer, IMediaTransportControlsAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline MenuFlyoutItemAutomationPeer::MenuFlyoutItemAutomationPeer(const Windows::UI::Xaml::Controls::MenuFlyoutItem & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<MenuFlyoutItemAutomationPeer, IMenuFlyoutItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline MenuFlyoutPresenterAutomationPeer::MenuFlyoutPresenterAutomationPeer(const Windows::UI::Xaml::Controls::MenuFlyoutPresenter & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<MenuFlyoutPresenterAutomationPeer, IMenuFlyoutPresenterAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline PasswordBoxAutomationPeer::PasswordBoxAutomationPeer(const Windows::UI::Xaml::Controls::PasswordBox & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<PasswordBoxAutomationPeer, IPasswordBoxAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline PivotAutomationPeer::PivotAutomationPeer(const Windows::UI::Xaml::Controls::Pivot & owner) :
    PivotAutomationPeer(get_activation_factory<PivotAutomationPeer, IPivotAutomationPeerFactory>().CreateInstanceWithOwner(owner))
{}

inline PivotItemAutomationPeer::PivotItemAutomationPeer(const Windows::UI::Xaml::Controls::PivotItem & owner) :
    PivotItemAutomationPeer(get_activation_factory<PivotItemAutomationPeer, IPivotItemAutomationPeerFactory>().CreateInstanceWithOwner(owner))
{}

inline PivotItemDataAutomationPeer::PivotItemDataAutomationPeer(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::PivotAutomationPeer & parent) :
    PivotItemDataAutomationPeer(get_activation_factory<PivotItemDataAutomationPeer, IPivotItemDataAutomationPeerFactory>().CreateInstanceWithParentAndItem(item, parent))
{}

inline ProgressBarAutomationPeer::ProgressBarAutomationPeer(const Windows::UI::Xaml::Controls::ProgressBar & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<ProgressBarAutomationPeer, IProgressBarAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline ProgressRingAutomationPeer::ProgressRingAutomationPeer(const Windows::UI::Xaml::Controls::ProgressRing & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<ProgressRingAutomationPeer, IProgressRingAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline RadioButtonAutomationPeer::RadioButtonAutomationPeer(const Windows::UI::Xaml::Controls::RadioButton & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<RadioButtonAutomationPeer, IRadioButtonAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline RangeBaseAutomationPeer::RangeBaseAutomationPeer(const Windows::UI::Xaml::Controls::Primitives::RangeBase & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<RangeBaseAutomationPeer, IRangeBaseAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline RepeatButtonAutomationPeer::RepeatButtonAutomationPeer(const Windows::UI::Xaml::Controls::Primitives::RepeatButton & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<RepeatButtonAutomationPeer, IRepeatButtonAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline RichEditBoxAutomationPeer::RichEditBoxAutomationPeer(const Windows::UI::Xaml::Controls::RichEditBox & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<RichEditBoxAutomationPeer, IRichEditBoxAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline RichTextBlockAutomationPeer::RichTextBlockAutomationPeer(const Windows::UI::Xaml::Controls::RichTextBlock & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<RichTextBlockAutomationPeer, IRichTextBlockAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline RichTextBlockOverflowAutomationPeer::RichTextBlockOverflowAutomationPeer(const Windows::UI::Xaml::Controls::RichTextBlockOverflow & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<RichTextBlockOverflowAutomationPeer, IRichTextBlockOverflowAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline ScrollBarAutomationPeer::ScrollBarAutomationPeer(const Windows::UI::Xaml::Controls::Primitives::ScrollBar & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<ScrollBarAutomationPeer, IScrollBarAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline ScrollViewerAutomationPeer::ScrollViewerAutomationPeer(const Windows::UI::Xaml::Controls::ScrollViewer & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<ScrollViewerAutomationPeer, IScrollViewerAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline SearchBoxAutomationPeer::SearchBoxAutomationPeer(const Windows::UI::Xaml::Controls::SearchBox & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<SearchBoxAutomationPeer, ISearchBoxAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline SelectorAutomationPeer::SelectorAutomationPeer(const Windows::UI::Xaml::Controls::Primitives::Selector & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<SelectorAutomationPeer, ISelectorAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline SelectorItemAutomationPeer::SelectorItemAutomationPeer(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::SelectorAutomationPeer & parent)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<SelectorItemAutomationPeer, ISelectorItemAutomationPeerFactory>().CreateInstanceWithParentAndItem(item, parent, outer, inner));
}

inline SemanticZoomAutomationPeer::SemanticZoomAutomationPeer(const Windows::UI::Xaml::Controls::SemanticZoom & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<SemanticZoomAutomationPeer, ISemanticZoomAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline SettingsFlyoutAutomationPeer::SettingsFlyoutAutomationPeer(const Windows::UI::Xaml::Controls::SettingsFlyout & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<SettingsFlyoutAutomationPeer, ISettingsFlyoutAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline SliderAutomationPeer::SliderAutomationPeer(const Windows::UI::Xaml::Controls::Slider & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<SliderAutomationPeer, ISliderAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline TextBlockAutomationPeer::TextBlockAutomationPeer(const Windows::UI::Xaml::Controls::TextBlock & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<TextBlockAutomationPeer, ITextBlockAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline TextBoxAutomationPeer::TextBoxAutomationPeer(const Windows::UI::Xaml::Controls::TextBox & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<TextBoxAutomationPeer, ITextBoxAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline ThumbAutomationPeer::ThumbAutomationPeer(const Windows::UI::Xaml::Controls::Primitives::Thumb & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<ThumbAutomationPeer, IThumbAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline TimePickerAutomationPeer::TimePickerAutomationPeer(const Windows::UI::Xaml::Controls::TimePicker & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<TimePickerAutomationPeer, ITimePickerAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline ToggleButtonAutomationPeer::ToggleButtonAutomationPeer(const Windows::UI::Xaml::Controls::Primitives::ToggleButton & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<ToggleButtonAutomationPeer, IToggleButtonAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline ToggleMenuFlyoutItemAutomationPeer::ToggleMenuFlyoutItemAutomationPeer(const Windows::UI::Xaml::Controls::ToggleMenuFlyoutItem & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<ToggleMenuFlyoutItemAutomationPeer, IToggleMenuFlyoutItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

inline ToggleSwitchAutomationPeer::ToggleSwitchAutomationPeer(const Windows::UI::Xaml::Controls::ToggleSwitch & owner)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<ToggleSwitchAutomationPeer, IToggleSwitchAutomationPeerFactory>().CreateInstanceWithOwner(owner, outer, inner));
}

}

}
#pragma warning(pop)
