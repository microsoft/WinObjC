// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.UI.Xaml.3.h"
#include "internal/Windows.Devices.Input.3.h"
#include "internal/Windows.UI.Input.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.System.3.h"
#include "internal/Windows.UI.Core.3.h"
#include "internal/Windows.UI.Xaml.Input.3.h"
#include "Windows.UI.Xaml.h"
#include "internal/Windows.UI.Xaml.Input.5.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Input {

template <typename L> DoubleTappedEventHandler::DoubleTappedEventHandler(L lambda) :
    DoubleTappedEventHandler(impl::make_delegate<impl_DoubleTappedEventHandler<L>, DoubleTappedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> DoubleTappedEventHandler::DoubleTappedEventHandler(F * function) :
    DoubleTappedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> DoubleTappedEventHandler::DoubleTappedEventHandler(O * object, M method) :
    DoubleTappedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void DoubleTappedEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Input::DoubleTappedRoutedEventArgs & e) const
{
    check_hresult((*(abi<DoubleTappedEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

template <typename L> HoldingEventHandler::HoldingEventHandler(L lambda) :
    HoldingEventHandler(impl::make_delegate<impl_HoldingEventHandler<L>, HoldingEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> HoldingEventHandler::HoldingEventHandler(F * function) :
    HoldingEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> HoldingEventHandler::HoldingEventHandler(O * object, M method) :
    HoldingEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void HoldingEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Input::HoldingRoutedEventArgs & e) const
{
    check_hresult((*(abi<HoldingEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

template <typename L> KeyEventHandler::KeyEventHandler(L lambda) :
    KeyEventHandler(impl::make_delegate<impl_KeyEventHandler<L>, KeyEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> KeyEventHandler::KeyEventHandler(F * function) :
    KeyEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> KeyEventHandler::KeyEventHandler(O * object, M method) :
    KeyEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void KeyEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Input::KeyRoutedEventArgs & e) const
{
    check_hresult((*(abi<KeyEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

template <typename L> ManipulationCompletedEventHandler::ManipulationCompletedEventHandler(L lambda) :
    ManipulationCompletedEventHandler(impl::make_delegate<impl_ManipulationCompletedEventHandler<L>, ManipulationCompletedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> ManipulationCompletedEventHandler::ManipulationCompletedEventHandler(F * function) :
    ManipulationCompletedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> ManipulationCompletedEventHandler::ManipulationCompletedEventHandler(O * object, M method) :
    ManipulationCompletedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void ManipulationCompletedEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Input::ManipulationCompletedRoutedEventArgs & e) const
{
    check_hresult((*(abi<ManipulationCompletedEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

template <typename L> ManipulationDeltaEventHandler::ManipulationDeltaEventHandler(L lambda) :
    ManipulationDeltaEventHandler(impl::make_delegate<impl_ManipulationDeltaEventHandler<L>, ManipulationDeltaEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> ManipulationDeltaEventHandler::ManipulationDeltaEventHandler(F * function) :
    ManipulationDeltaEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> ManipulationDeltaEventHandler::ManipulationDeltaEventHandler(O * object, M method) :
    ManipulationDeltaEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void ManipulationDeltaEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Input::ManipulationDeltaRoutedEventArgs & e) const
{
    check_hresult((*(abi<ManipulationDeltaEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

template <typename L> ManipulationInertiaStartingEventHandler::ManipulationInertiaStartingEventHandler(L lambda) :
    ManipulationInertiaStartingEventHandler(impl::make_delegate<impl_ManipulationInertiaStartingEventHandler<L>, ManipulationInertiaStartingEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> ManipulationInertiaStartingEventHandler::ManipulationInertiaStartingEventHandler(F * function) :
    ManipulationInertiaStartingEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> ManipulationInertiaStartingEventHandler::ManipulationInertiaStartingEventHandler(O * object, M method) :
    ManipulationInertiaStartingEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void ManipulationInertiaStartingEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Input::ManipulationInertiaStartingRoutedEventArgs & e) const
{
    check_hresult((*(abi<ManipulationInertiaStartingEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

template <typename L> ManipulationStartedEventHandler::ManipulationStartedEventHandler(L lambda) :
    ManipulationStartedEventHandler(impl::make_delegate<impl_ManipulationStartedEventHandler<L>, ManipulationStartedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> ManipulationStartedEventHandler::ManipulationStartedEventHandler(F * function) :
    ManipulationStartedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> ManipulationStartedEventHandler::ManipulationStartedEventHandler(O * object, M method) :
    ManipulationStartedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void ManipulationStartedEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Input::ManipulationStartedRoutedEventArgs & e) const
{
    check_hresult((*(abi<ManipulationStartedEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

template <typename L> ManipulationStartingEventHandler::ManipulationStartingEventHandler(L lambda) :
    ManipulationStartingEventHandler(impl::make_delegate<impl_ManipulationStartingEventHandler<L>, ManipulationStartingEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> ManipulationStartingEventHandler::ManipulationStartingEventHandler(F * function) :
    ManipulationStartingEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> ManipulationStartingEventHandler::ManipulationStartingEventHandler(O * object, M method) :
    ManipulationStartingEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void ManipulationStartingEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Input::ManipulationStartingRoutedEventArgs & e) const
{
    check_hresult((*(abi<ManipulationStartingEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

template <typename L> PointerEventHandler::PointerEventHandler(L lambda) :
    PointerEventHandler(impl::make_delegate<impl_PointerEventHandler<L>, PointerEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> PointerEventHandler::PointerEventHandler(F * function) :
    PointerEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> PointerEventHandler::PointerEventHandler(O * object, M method) :
    PointerEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void PointerEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Input::PointerRoutedEventArgs & e) const
{
    check_hresult((*(abi<PointerEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

template <typename L> RightTappedEventHandler::RightTappedEventHandler(L lambda) :
    RightTappedEventHandler(impl::make_delegate<impl_RightTappedEventHandler<L>, RightTappedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> RightTappedEventHandler::RightTappedEventHandler(F * function) :
    RightTappedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> RightTappedEventHandler::RightTappedEventHandler(O * object, M method) :
    RightTappedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void RightTappedEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Input::RightTappedRoutedEventArgs & e) const
{
    check_hresult((*(abi<RightTappedEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

template <typename L> TappedEventHandler::TappedEventHandler(L lambda) :
    TappedEventHandler(impl::make_delegate<impl_TappedEventHandler<L>, TappedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> TappedEventHandler::TappedEventHandler(F * function) :
    TappedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> TappedEventHandler::TappedEventHandler(O * object, M method) :
    TappedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void TappedEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Input::TappedRoutedEventArgs & e) const
{
    check_hresult((*(abi<TappedEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

}

namespace impl {

template <typename D>
struct produce<D, Windows::UI::Xaml::Input::IAccessKeyDisplayDismissedEventArgs> : produce_base<D, Windows::UI::Xaml::Input::IAccessKeyDisplayDismissedEventArgs>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Input::IAccessKeyDisplayRequestedEventArgs> : produce_base<D, Windows::UI::Xaml::Input::IAccessKeyDisplayRequestedEventArgs>
{
    HRESULT __stdcall get_PressedKeys(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PressedKeys());
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
struct produce<D, Windows::UI::Xaml::Input::IAccessKeyInvokedEventArgs> : produce_base<D, Windows::UI::Xaml::Input::IAccessKeyInvokedEventArgs>
{
    HRESULT __stdcall get_Handled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Handled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Handled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Input::IAccessKeyManager> : produce_base<D, Windows::UI::Xaml::Input::IAccessKeyManager>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Input::IAccessKeyManagerStatics> : produce_base<D, Windows::UI::Xaml::Input::IAccessKeyManagerStatics>
{
    HRESULT __stdcall get_IsDisplayModeEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDisplayModeEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_IsDisplayModeEnabledChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::Foundation::IInspectable>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().IsDisplayModeEnabledChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::Foundation::IInspectable> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_IsDisplayModeEnabledChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsDisplayModeEnabledChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ExitDisplayMode() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ExitDisplayMode();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Input::ICommand> : produce_base<D, Windows::UI::Xaml::Input::ICommand>
{
    HRESULT __stdcall add_CanExecuteChanged(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Foundation::IInspectable>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().CanExecuteChanged(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CanExecuteChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanExecuteChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CanExecute(impl::abi_arg_in<Windows::Foundation::IInspectable> parameter, bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().CanExecute(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&parameter)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Execute(impl::abi_arg_in<Windows::Foundation::IInspectable> parameter) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Execute(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&parameter));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Input::IContextRequestedEventArgs> : produce_base<D, Windows::UI::Xaml::Input::IContextRequestedEventArgs>
{
    HRESULT __stdcall get_Handled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Handled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Handled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryGetPosition(impl::abi_arg_in<Windows::UI::Xaml::IUIElement> relativeTo, impl::abi_arg_out<Windows::Foundation::Point> point, bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().TryGetPosition(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&relativeTo), *point));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Input::IDoubleTappedRoutedEventArgs> : produce_base<D, Windows::UI::Xaml::Input::IDoubleTappedRoutedEventArgs>
{
    HRESULT __stdcall get_PointerDeviceType(Windows::Devices::Input::PointerDeviceType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PointerDeviceType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Handled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Handled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Handled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPosition(impl::abi_arg_in<Windows::UI::Xaml::IUIElement> relativeTo, impl::abi_arg_out<Windows::Foundation::Point> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetPosition(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&relativeTo)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Input::IFocusManager> : produce_base<D, Windows::UI::Xaml::Input::IFocusManager>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Input::IFocusManagerStatics> : produce_base<D, Windows::UI::Xaml::Input::IFocusManagerStatics>
{
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
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Input::IFocusManagerStatics2> : produce_base<D, Windows::UI::Xaml::Input::IFocusManagerStatics2>
{
    HRESULT __stdcall abi_TryMoveFocus(Windows::UI::Xaml::Input::FocusNavigationDirection focusNavigationDirection, bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().TryMoveFocus(focusNavigationDirection));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Input::IFocusManagerStatics3> : produce_base<D, Windows::UI::Xaml::Input::IFocusManagerStatics3>
{
    HRESULT __stdcall abi_FindNextFocusableElement(Windows::UI::Xaml::Input::FocusNavigationDirection focusNavigationDirection, impl::abi_arg_out<Windows::UI::Xaml::IUIElement> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FindNextFocusableElement(focusNavigationDirection));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindNextFocusableElementWithHint(Windows::UI::Xaml::Input::FocusNavigationDirection focusNavigationDirection, impl::abi_arg_in<Windows::Foundation::Rect> hintRect, impl::abi_arg_out<Windows::UI::Xaml::IUIElement> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FindNextFocusableElement(focusNavigationDirection, *reinterpret_cast<const Windows::Foundation::Rect *>(&hintRect)));
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
struct produce<D, Windows::UI::Xaml::Input::IHoldingRoutedEventArgs> : produce_base<D, Windows::UI::Xaml::Input::IHoldingRoutedEventArgs>
{
    HRESULT __stdcall get_PointerDeviceType(Windows::Devices::Input::PointerDeviceType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PointerDeviceType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HoldingState(Windows::UI::Input::HoldingState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HoldingState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Handled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Handled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Handled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPosition(impl::abi_arg_in<Windows::UI::Xaml::IUIElement> relativeTo, impl::abi_arg_out<Windows::Foundation::Point> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetPosition(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&relativeTo)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Input::IInertiaExpansionBehavior> : produce_base<D, Windows::UI::Xaml::Input::IInertiaExpansionBehavior>
{
    HRESULT __stdcall get_DesiredDeceleration(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DesiredDeceleration());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DesiredDeceleration(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DesiredDeceleration(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DesiredExpansion(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DesiredExpansion());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DesiredExpansion(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DesiredExpansion(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Input::IInertiaRotationBehavior> : produce_base<D, Windows::UI::Xaml::Input::IInertiaRotationBehavior>
{
    HRESULT __stdcall get_DesiredDeceleration(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DesiredDeceleration());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DesiredDeceleration(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DesiredDeceleration(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DesiredRotation(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DesiredRotation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DesiredRotation(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DesiredRotation(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Input::IInertiaTranslationBehavior> : produce_base<D, Windows::UI::Xaml::Input::IInertiaTranslationBehavior>
{
    HRESULT __stdcall get_DesiredDeceleration(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DesiredDeceleration());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DesiredDeceleration(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DesiredDeceleration(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DesiredDisplacement(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DesiredDisplacement());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DesiredDisplacement(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DesiredDisplacement(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Input::IInputScope> : produce_base<D, Windows::UI::Xaml::Input::IInputScope>
{
    HRESULT __stdcall get_Names(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Input::InputScopeName>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Names());
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
struct produce<D, Windows::UI::Xaml::Input::IInputScopeName> : produce_base<D, Windows::UI::Xaml::Input::IInputScopeName>
{
    HRESULT __stdcall get_NameValue(Windows::UI::Xaml::Input::InputScopeNameValue * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NameValue());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_NameValue(Windows::UI::Xaml::Input::InputScopeNameValue value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NameValue(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Input::IInputScopeNameFactory> : produce_base<D, Windows::UI::Xaml::Input::IInputScopeNameFactory>
{
    HRESULT __stdcall abi_CreateInstance(Windows::UI::Xaml::Input::InputScopeNameValue nameValue, impl::abi_arg_out<Windows::UI::Xaml::Input::IInputScopeName> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstance(nameValue));
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
struct produce<D, Windows::UI::Xaml::Input::IKeyRoutedEventArgs> : produce_base<D, Windows::UI::Xaml::Input::IKeyRoutedEventArgs>
{
    HRESULT __stdcall get_Key(Windows::System::VirtualKey * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Key());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KeyStatus(impl::abi_arg_out<Windows::UI::Core::CorePhysicalKeyStatus> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeyStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Handled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Handled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Handled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Input::IKeyRoutedEventArgs2> : produce_base<D, Windows::UI::Xaml::Input::IKeyRoutedEventArgs2>
{
    HRESULT __stdcall get_OriginalKey(Windows::System::VirtualKey * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OriginalKey());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Input::IKeyRoutedEventArgs3> : produce_base<D, Windows::UI::Xaml::Input::IKeyRoutedEventArgs3>
{
    HRESULT __stdcall get_DeviceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceId());
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
struct produce<D, Windows::UI::Xaml::Input::IManipulationCompletedRoutedEventArgs> : produce_base<D, Windows::UI::Xaml::Input::IManipulationCompletedRoutedEventArgs>
{
    HRESULT __stdcall get_Container(impl::abi_arg_out<Windows::UI::Xaml::IUIElement> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Container());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Position(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Position());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsInertial(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsInertial());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Cumulative(impl::abi_arg_out<Windows::UI::Input::ManipulationDelta> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Cumulative());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Velocities(impl::abi_arg_out<Windows::UI::Input::ManipulationVelocities> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Velocities());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Handled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Handled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Handled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PointerDeviceType(Windows::Devices::Input::PointerDeviceType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PointerDeviceType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Input::IManipulationDeltaRoutedEventArgs> : produce_base<D, Windows::UI::Xaml::Input::IManipulationDeltaRoutedEventArgs>
{
    HRESULT __stdcall get_Container(impl::abi_arg_out<Windows::UI::Xaml::IUIElement> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Container());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Position(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Position());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsInertial(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsInertial());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Delta(impl::abi_arg_out<Windows::UI::Input::ManipulationDelta> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Delta());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Cumulative(impl::abi_arg_out<Windows::UI::Input::ManipulationDelta> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Cumulative());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Velocities(impl::abi_arg_out<Windows::UI::Input::ManipulationVelocities> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Velocities());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Handled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Handled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Handled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PointerDeviceType(Windows::Devices::Input::PointerDeviceType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PointerDeviceType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Complete() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Complete();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Input::IManipulationInertiaStartingRoutedEventArgs> : produce_base<D, Windows::UI::Xaml::Input::IManipulationInertiaStartingRoutedEventArgs>
{
    HRESULT __stdcall get_Container(impl::abi_arg_out<Windows::UI::Xaml::IUIElement> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Container());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExpansionBehavior(impl::abi_arg_out<Windows::UI::Xaml::Input::IInertiaExpansionBehavior> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExpansionBehavior());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ExpansionBehavior(impl::abi_arg_in<Windows::UI::Xaml::Input::IInertiaExpansionBehavior> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ExpansionBehavior(*reinterpret_cast<const Windows::UI::Xaml::Input::InertiaExpansionBehavior *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RotationBehavior(impl::abi_arg_out<Windows::UI::Xaml::Input::IInertiaRotationBehavior> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RotationBehavior());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RotationBehavior(impl::abi_arg_in<Windows::UI::Xaml::Input::IInertiaRotationBehavior> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RotationBehavior(*reinterpret_cast<const Windows::UI::Xaml::Input::InertiaRotationBehavior *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TranslationBehavior(impl::abi_arg_out<Windows::UI::Xaml::Input::IInertiaTranslationBehavior> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TranslationBehavior());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TranslationBehavior(impl::abi_arg_in<Windows::UI::Xaml::Input::IInertiaTranslationBehavior> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TranslationBehavior(*reinterpret_cast<const Windows::UI::Xaml::Input::InertiaTranslationBehavior *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Handled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Handled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Handled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PointerDeviceType(Windows::Devices::Input::PointerDeviceType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PointerDeviceType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Delta(impl::abi_arg_out<Windows::UI::Input::ManipulationDelta> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Delta());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Cumulative(impl::abi_arg_out<Windows::UI::Input::ManipulationDelta> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Cumulative());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Velocities(impl::abi_arg_out<Windows::UI::Input::ManipulationVelocities> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Velocities());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Input::IManipulationPivot> : produce_base<D, Windows::UI::Xaml::Input::IManipulationPivot>
{
    HRESULT __stdcall get_Center(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Center());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Center(impl::abi_arg_in<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Center(*reinterpret_cast<const Windows::Foundation::Point *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Radius(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Radius());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Radius(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Radius(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Input::IManipulationPivotFactory> : produce_base<D, Windows::UI::Xaml::Input::IManipulationPivotFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithCenterAndRadius(impl::abi_arg_in<Windows::Foundation::Point> center, double radius, impl::abi_arg_out<Windows::UI::Xaml::Input::IManipulationPivot> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithCenterAndRadius(*reinterpret_cast<const Windows::Foundation::Point *>(&center), radius));
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
struct produce<D, Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgs> : produce_base<D, Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgs>
{
    HRESULT __stdcall get_Container(impl::abi_arg_out<Windows::UI::Xaml::IUIElement> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Container());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Position(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Position());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Handled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Handled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Handled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PointerDeviceType(Windows::Devices::Input::PointerDeviceType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PointerDeviceType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Cumulative(impl::abi_arg_out<Windows::UI::Input::ManipulationDelta> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Cumulative());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Complete() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Complete();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgsFactory> : produce_base<D, Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgsFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgs> instance) noexcept override
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
struct produce<D, Windows::UI::Xaml::Input::IManipulationStartingRoutedEventArgs> : produce_base<D, Windows::UI::Xaml::Input::IManipulationStartingRoutedEventArgs>
{
    HRESULT __stdcall get_Mode(Windows::UI::Xaml::Input::ManipulationModes * value) noexcept override
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

    HRESULT __stdcall put_Mode(Windows::UI::Xaml::Input::ManipulationModes value) noexcept override
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

    HRESULT __stdcall get_Container(impl::abi_arg_out<Windows::UI::Xaml::IUIElement> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Container());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Container(impl::abi_arg_in<Windows::UI::Xaml::IUIElement> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Container(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Pivot(impl::abi_arg_out<Windows::UI::Xaml::Input::IManipulationPivot> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Pivot());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Pivot(impl::abi_arg_in<Windows::UI::Xaml::Input::IManipulationPivot> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Pivot(*reinterpret_cast<const Windows::UI::Xaml::Input::ManipulationPivot *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Handled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Handled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Handled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Input::IPointer> : produce_base<D, Windows::UI::Xaml::Input::IPointer>
{
    HRESULT __stdcall get_PointerId(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PointerId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PointerDeviceType(Windows::Devices::Input::PointerDeviceType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PointerDeviceType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsInContact(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsInContact());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsInRange(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsInRange());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Input::IPointerRoutedEventArgs> : produce_base<D, Windows::UI::Xaml::Input::IPointerRoutedEventArgs>
{
    HRESULT __stdcall get_Pointer(impl::abi_arg_out<Windows::UI::Xaml::Input::IPointer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Pointer());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KeyModifiers(Windows::System::VirtualKeyModifiers * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeyModifiers());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Handled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Handled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Handled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCurrentPoint(impl::abi_arg_in<Windows::UI::Xaml::IUIElement> relativeTo, impl::abi_arg_out<Windows::UI::Input::IPointerPoint> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetCurrentPoint(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&relativeTo)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetIntermediatePoints(impl::abi_arg_in<Windows::UI::Xaml::IUIElement> relativeTo, impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Input::PointerPoint>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetIntermediatePoints(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&relativeTo)));
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
struct produce<D, Windows::UI::Xaml::Input::IRightTappedRoutedEventArgs> : produce_base<D, Windows::UI::Xaml::Input::IRightTappedRoutedEventArgs>
{
    HRESULT __stdcall get_PointerDeviceType(Windows::Devices::Input::PointerDeviceType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PointerDeviceType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Handled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Handled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Handled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPosition(impl::abi_arg_in<Windows::UI::Xaml::IUIElement> relativeTo, impl::abi_arg_out<Windows::Foundation::Point> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetPosition(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&relativeTo)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Input::ITappedRoutedEventArgs> : produce_base<D, Windows::UI::Xaml::Input::ITappedRoutedEventArgs>
{
    HRESULT __stdcall get_PointerDeviceType(Windows::Devices::Input::PointerDeviceType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PointerDeviceType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Handled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Handled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Handled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPosition(impl::abi_arg_in<Windows::UI::Xaml::IUIElement> relativeTo, impl::abi_arg_out<Windows::Foundation::Point> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetPosition(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&relativeTo)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::UI::Xaml::Input {

template <typename D> event_token impl_ICommand<D>::CanExecuteChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ICommand)->add_CanExecuteChanged(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<ICommand> impl_ICommand<D>::CanExecuteChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const
{
    return impl::make_event_revoker<D, ICommand>(this, &ABI::Windows::UI::Xaml::Input::ICommand::remove_CanExecuteChanged, CanExecuteChanged(value));
}

template <typename D> void impl_ICommand<D>::CanExecuteChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(ICommand)->remove_CanExecuteChanged(token));
}

template <typename D> bool impl_ICommand<D>::CanExecute(const Windows::Foundation::IInspectable & parameter) const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(ICommand)->abi_CanExecute(get_abi(parameter), &returnValue));
    return returnValue;
}

template <typename D> void impl_ICommand<D>::Execute(const Windows::Foundation::IInspectable & parameter) const
{
    check_hresult(WINRT_SHIM(ICommand)->abi_Execute(get_abi(parameter)));
}

template <typename D> hstring impl_IAccessKeyDisplayRequestedEventArgs<D>::PressedKeys() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAccessKeyDisplayRequestedEventArgs)->get_PressedKeys(put_abi(value)));
    return value;
}

template <typename D> bool impl_IAccessKeyInvokedEventArgs<D>::Handled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IAccessKeyInvokedEventArgs)->get_Handled(&value));
    return value;
}

template <typename D> void impl_IAccessKeyInvokedEventArgs<D>::Handled(bool value) const
{
    check_hresult(WINRT_SHIM(IAccessKeyInvokedEventArgs)->put_Handled(value));
}

template <typename D> bool impl_IAccessKeyManagerStatics<D>::IsDisplayModeEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IAccessKeyManagerStatics)->get_IsDisplayModeEnabled(&value));
    return value;
}

template <typename D> event_token impl_IAccessKeyManagerStatics<D>::IsDisplayModeEnabledChanged(const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::Foundation::IInspectable> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IAccessKeyManagerStatics)->add_IsDisplayModeEnabledChanged(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IAccessKeyManagerStatics> impl_IAccessKeyManagerStatics<D>::IsDisplayModeEnabledChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::Foundation::IInspectable> & value) const
{
    return impl::make_event_revoker<D, IAccessKeyManagerStatics>(this, &ABI::Windows::UI::Xaml::Input::IAccessKeyManagerStatics::remove_IsDisplayModeEnabledChanged, IsDisplayModeEnabledChanged(value));
}

template <typename D> void impl_IAccessKeyManagerStatics<D>::IsDisplayModeEnabledChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IAccessKeyManagerStatics)->remove_IsDisplayModeEnabledChanged(token));
}

template <typename D> void impl_IAccessKeyManagerStatics<D>::ExitDisplayMode() const
{
    check_hresult(WINRT_SHIM(IAccessKeyManagerStatics)->abi_ExitDisplayMode());
}

template <typename D> Windows::Foundation::IInspectable impl_IFocusManagerStatics<D>::GetFocusedElement() const
{
    Windows::Foundation::IInspectable returnValue;
    check_hresult(WINRT_SHIM(IFocusManagerStatics)->abi_GetFocusedElement(put_abi(returnValue)));
    return returnValue;
}

template <typename D> bool impl_IFocusManagerStatics2<D>::TryMoveFocus(Windows::UI::Xaml::Input::FocusNavigationDirection focusNavigationDirection) const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IFocusManagerStatics2)->abi_TryMoveFocus(focusNavigationDirection, &returnValue));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::UIElement impl_IFocusManagerStatics3<D>::FindNextFocusableElement(Windows::UI::Xaml::Input::FocusNavigationDirection focusNavigationDirection) const
{
    Windows::UI::Xaml::UIElement result { nullptr };
    check_hresult(WINRT_SHIM(IFocusManagerStatics3)->abi_FindNextFocusableElement(focusNavigationDirection, put_abi(result)));
    return result;
}

template <typename D> Windows::UI::Xaml::UIElement impl_IFocusManagerStatics3<D>::FindNextFocusableElement(Windows::UI::Xaml::Input::FocusNavigationDirection focusNavigationDirection, const Windows::Foundation::Rect & hintRect) const
{
    Windows::UI::Xaml::UIElement result { nullptr };
    check_hresult(WINRT_SHIM(IFocusManagerStatics3)->abi_FindNextFocusableElementWithHint(focusNavigationDirection, get_abi(hintRect), put_abi(result)));
    return result;
}

template <typename D> double impl_IInertiaExpansionBehavior<D>::DesiredDeceleration() const
{
    double value {};
    check_hresult(WINRT_SHIM(IInertiaExpansionBehavior)->get_DesiredDeceleration(&value));
    return value;
}

template <typename D> void impl_IInertiaExpansionBehavior<D>::DesiredDeceleration(double value) const
{
    check_hresult(WINRT_SHIM(IInertiaExpansionBehavior)->put_DesiredDeceleration(value));
}

template <typename D> double impl_IInertiaExpansionBehavior<D>::DesiredExpansion() const
{
    double value {};
    check_hresult(WINRT_SHIM(IInertiaExpansionBehavior)->get_DesiredExpansion(&value));
    return value;
}

template <typename D> void impl_IInertiaExpansionBehavior<D>::DesiredExpansion(double value) const
{
    check_hresult(WINRT_SHIM(IInertiaExpansionBehavior)->put_DesiredExpansion(value));
}

template <typename D> double impl_IInertiaRotationBehavior<D>::DesiredDeceleration() const
{
    double value {};
    check_hresult(WINRT_SHIM(IInertiaRotationBehavior)->get_DesiredDeceleration(&value));
    return value;
}

template <typename D> void impl_IInertiaRotationBehavior<D>::DesiredDeceleration(double value) const
{
    check_hresult(WINRT_SHIM(IInertiaRotationBehavior)->put_DesiredDeceleration(value));
}

template <typename D> double impl_IInertiaRotationBehavior<D>::DesiredRotation() const
{
    double value {};
    check_hresult(WINRT_SHIM(IInertiaRotationBehavior)->get_DesiredRotation(&value));
    return value;
}

template <typename D> void impl_IInertiaRotationBehavior<D>::DesiredRotation(double value) const
{
    check_hresult(WINRT_SHIM(IInertiaRotationBehavior)->put_DesiredRotation(value));
}

template <typename D> double impl_IInertiaTranslationBehavior<D>::DesiredDeceleration() const
{
    double value {};
    check_hresult(WINRT_SHIM(IInertiaTranslationBehavior)->get_DesiredDeceleration(&value));
    return value;
}

template <typename D> void impl_IInertiaTranslationBehavior<D>::DesiredDeceleration(double value) const
{
    check_hresult(WINRT_SHIM(IInertiaTranslationBehavior)->put_DesiredDeceleration(value));
}

template <typename D> double impl_IInertiaTranslationBehavior<D>::DesiredDisplacement() const
{
    double value {};
    check_hresult(WINRT_SHIM(IInertiaTranslationBehavior)->get_DesiredDisplacement(&value));
    return value;
}

template <typename D> void impl_IInertiaTranslationBehavior<D>::DesiredDisplacement(double value) const
{
    check_hresult(WINRT_SHIM(IInertiaTranslationBehavior)->put_DesiredDisplacement(value));
}

template <typename D> Windows::Foundation::Point impl_IManipulationPivot<D>::Center() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(IManipulationPivot)->get_Center(put_abi(value)));
    return value;
}

template <typename D> void impl_IManipulationPivot<D>::Center(const Windows::Foundation::Point & value) const
{
    check_hresult(WINRT_SHIM(IManipulationPivot)->put_Center(get_abi(value)));
}

template <typename D> double impl_IManipulationPivot<D>::Radius() const
{
    double value {};
    check_hresult(WINRT_SHIM(IManipulationPivot)->get_Radius(&value));
    return value;
}

template <typename D> void impl_IManipulationPivot<D>::Radius(double value) const
{
    check_hresult(WINRT_SHIM(IManipulationPivot)->put_Radius(value));
}

template <typename D> Windows::UI::Xaml::Input::ManipulationPivot impl_IManipulationPivotFactory<D>::CreateInstanceWithCenterAndRadius(const Windows::Foundation::Point & center, double radius) const
{
    Windows::UI::Xaml::Input::ManipulationPivot instance { nullptr };
    check_hresult(WINRT_SHIM(IManipulationPivotFactory)->abi_CreateInstanceWithCenterAndRadius(get_abi(center), radius, put_abi(instance)));
    return instance;
}

template <typename D> uint32_t impl_IPointer<D>::PointerId() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IPointer)->get_PointerId(&value));
    return value;
}

template <typename D> Windows::Devices::Input::PointerDeviceType impl_IPointer<D>::PointerDeviceType() const
{
    Windows::Devices::Input::PointerDeviceType value {};
    check_hresult(WINRT_SHIM(IPointer)->get_PointerDeviceType(&value));
    return value;
}

template <typename D> bool impl_IPointer<D>::IsInContact() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPointer)->get_IsInContact(&value));
    return value;
}

template <typename D> bool impl_IPointer<D>::IsInRange() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPointer)->get_IsInRange(&value));
    return value;
}

template <typename D> bool impl_IContextRequestedEventArgs<D>::Handled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IContextRequestedEventArgs)->get_Handled(&value));
    return value;
}

template <typename D> void impl_IContextRequestedEventArgs<D>::Handled(bool value) const
{
    check_hresult(WINRT_SHIM(IContextRequestedEventArgs)->put_Handled(value));
}

template <typename D> bool impl_IContextRequestedEventArgs<D>::TryGetPosition(const Windows::UI::Xaml::UIElement & relativeTo, Windows::Foundation::Point & point) const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IContextRequestedEventArgs)->abi_TryGetPosition(get_abi(relativeTo), put_abi(point), &returnValue));
    return returnValue;
}

template <typename D> Windows::Devices::Input::PointerDeviceType impl_IDoubleTappedRoutedEventArgs<D>::PointerDeviceType() const
{
    Windows::Devices::Input::PointerDeviceType value {};
    check_hresult(WINRT_SHIM(IDoubleTappedRoutedEventArgs)->get_PointerDeviceType(&value));
    return value;
}

template <typename D> bool impl_IDoubleTappedRoutedEventArgs<D>::Handled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDoubleTappedRoutedEventArgs)->get_Handled(&value));
    return value;
}

template <typename D> void impl_IDoubleTappedRoutedEventArgs<D>::Handled(bool value) const
{
    check_hresult(WINRT_SHIM(IDoubleTappedRoutedEventArgs)->put_Handled(value));
}

template <typename D> Windows::Foundation::Point impl_IDoubleTappedRoutedEventArgs<D>::GetPosition(const Windows::UI::Xaml::UIElement & relativeTo) const
{
    Windows::Foundation::Point returnValue {};
    check_hresult(WINRT_SHIM(IDoubleTappedRoutedEventArgs)->abi_GetPosition(get_abi(relativeTo), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Devices::Input::PointerDeviceType impl_IHoldingRoutedEventArgs<D>::PointerDeviceType() const
{
    Windows::Devices::Input::PointerDeviceType value {};
    check_hresult(WINRT_SHIM(IHoldingRoutedEventArgs)->get_PointerDeviceType(&value));
    return value;
}

template <typename D> Windows::UI::Input::HoldingState impl_IHoldingRoutedEventArgs<D>::HoldingState() const
{
    Windows::UI::Input::HoldingState value {};
    check_hresult(WINRT_SHIM(IHoldingRoutedEventArgs)->get_HoldingState(&value));
    return value;
}

template <typename D> bool impl_IHoldingRoutedEventArgs<D>::Handled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IHoldingRoutedEventArgs)->get_Handled(&value));
    return value;
}

template <typename D> void impl_IHoldingRoutedEventArgs<D>::Handled(bool value) const
{
    check_hresult(WINRT_SHIM(IHoldingRoutedEventArgs)->put_Handled(value));
}

template <typename D> Windows::Foundation::Point impl_IHoldingRoutedEventArgs<D>::GetPosition(const Windows::UI::Xaml::UIElement & relativeTo) const
{
    Windows::Foundation::Point returnValue {};
    check_hresult(WINRT_SHIM(IHoldingRoutedEventArgs)->abi_GetPosition(get_abi(relativeTo), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Input::InputScopeName> impl_IInputScope<D>::Names() const
{
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Input::InputScopeName> value;
    check_hresult(WINRT_SHIM(IInputScope)->get_Names(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Input::InputScopeNameValue impl_IInputScopeName<D>::NameValue() const
{
    Windows::UI::Xaml::Input::InputScopeNameValue value {};
    check_hresult(WINRT_SHIM(IInputScopeName)->get_NameValue(&value));
    return value;
}

template <typename D> void impl_IInputScopeName<D>::NameValue(Windows::UI::Xaml::Input::InputScopeNameValue value) const
{
    check_hresult(WINRT_SHIM(IInputScopeName)->put_NameValue(value));
}

template <typename D> Windows::UI::Xaml::Input::InputScopeName impl_IInputScopeNameFactory<D>::CreateInstance(Windows::UI::Xaml::Input::InputScopeNameValue nameValue) const
{
    Windows::UI::Xaml::Input::InputScopeName instance { nullptr };
    check_hresult(WINRT_SHIM(IInputScopeNameFactory)->abi_CreateInstance(nameValue, put_abi(instance)));
    return instance;
}

template <typename D> Windows::System::VirtualKey impl_IKeyRoutedEventArgs<D>::Key() const
{
    Windows::System::VirtualKey value {};
    check_hresult(WINRT_SHIM(IKeyRoutedEventArgs)->get_Key(&value));
    return value;
}

template <typename D> Windows::UI::Core::CorePhysicalKeyStatus impl_IKeyRoutedEventArgs<D>::KeyStatus() const
{
    Windows::UI::Core::CorePhysicalKeyStatus value {};
    check_hresult(WINRT_SHIM(IKeyRoutedEventArgs)->get_KeyStatus(put_abi(value)));
    return value;
}

template <typename D> bool impl_IKeyRoutedEventArgs<D>::Handled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IKeyRoutedEventArgs)->get_Handled(&value));
    return value;
}

template <typename D> void impl_IKeyRoutedEventArgs<D>::Handled(bool value) const
{
    check_hresult(WINRT_SHIM(IKeyRoutedEventArgs)->put_Handled(value));
}

template <typename D> Windows::System::VirtualKey impl_IKeyRoutedEventArgs2<D>::OriginalKey() const
{
    Windows::System::VirtualKey value {};
    check_hresult(WINRT_SHIM(IKeyRoutedEventArgs2)->get_OriginalKey(&value));
    return value;
}

template <typename D> hstring impl_IKeyRoutedEventArgs3<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKeyRoutedEventArgs3)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::UIElement impl_IManipulationCompletedRoutedEventArgs<D>::Container() const
{
    Windows::UI::Xaml::UIElement value { nullptr };
    check_hresult(WINRT_SHIM(IManipulationCompletedRoutedEventArgs)->get_Container(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Point impl_IManipulationCompletedRoutedEventArgs<D>::Position() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(IManipulationCompletedRoutedEventArgs)->get_Position(put_abi(value)));
    return value;
}

template <typename D> bool impl_IManipulationCompletedRoutedEventArgs<D>::IsInertial() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IManipulationCompletedRoutedEventArgs)->get_IsInertial(&value));
    return value;
}

template <typename D> Windows::UI::Input::ManipulationDelta impl_IManipulationCompletedRoutedEventArgs<D>::Cumulative() const
{
    Windows::UI::Input::ManipulationDelta value {};
    check_hresult(WINRT_SHIM(IManipulationCompletedRoutedEventArgs)->get_Cumulative(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Input::ManipulationVelocities impl_IManipulationCompletedRoutedEventArgs<D>::Velocities() const
{
    Windows::UI::Input::ManipulationVelocities value {};
    check_hresult(WINRT_SHIM(IManipulationCompletedRoutedEventArgs)->get_Velocities(put_abi(value)));
    return value;
}

template <typename D> bool impl_IManipulationCompletedRoutedEventArgs<D>::Handled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IManipulationCompletedRoutedEventArgs)->get_Handled(&value));
    return value;
}

template <typename D> void impl_IManipulationCompletedRoutedEventArgs<D>::Handled(bool value) const
{
    check_hresult(WINRT_SHIM(IManipulationCompletedRoutedEventArgs)->put_Handled(value));
}

template <typename D> Windows::Devices::Input::PointerDeviceType impl_IManipulationCompletedRoutedEventArgs<D>::PointerDeviceType() const
{
    Windows::Devices::Input::PointerDeviceType value {};
    check_hresult(WINRT_SHIM(IManipulationCompletedRoutedEventArgs)->get_PointerDeviceType(&value));
    return value;
}

template <typename D> Windows::UI::Xaml::UIElement impl_IManipulationDeltaRoutedEventArgs<D>::Container() const
{
    Windows::UI::Xaml::UIElement value { nullptr };
    check_hresult(WINRT_SHIM(IManipulationDeltaRoutedEventArgs)->get_Container(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Point impl_IManipulationDeltaRoutedEventArgs<D>::Position() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(IManipulationDeltaRoutedEventArgs)->get_Position(put_abi(value)));
    return value;
}

template <typename D> bool impl_IManipulationDeltaRoutedEventArgs<D>::IsInertial() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IManipulationDeltaRoutedEventArgs)->get_IsInertial(&value));
    return value;
}

template <typename D> Windows::UI::Input::ManipulationDelta impl_IManipulationDeltaRoutedEventArgs<D>::Delta() const
{
    Windows::UI::Input::ManipulationDelta value {};
    check_hresult(WINRT_SHIM(IManipulationDeltaRoutedEventArgs)->get_Delta(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Input::ManipulationDelta impl_IManipulationDeltaRoutedEventArgs<D>::Cumulative() const
{
    Windows::UI::Input::ManipulationDelta value {};
    check_hresult(WINRT_SHIM(IManipulationDeltaRoutedEventArgs)->get_Cumulative(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Input::ManipulationVelocities impl_IManipulationDeltaRoutedEventArgs<D>::Velocities() const
{
    Windows::UI::Input::ManipulationVelocities value {};
    check_hresult(WINRT_SHIM(IManipulationDeltaRoutedEventArgs)->get_Velocities(put_abi(value)));
    return value;
}

template <typename D> bool impl_IManipulationDeltaRoutedEventArgs<D>::Handled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IManipulationDeltaRoutedEventArgs)->get_Handled(&value));
    return value;
}

template <typename D> void impl_IManipulationDeltaRoutedEventArgs<D>::Handled(bool value) const
{
    check_hresult(WINRT_SHIM(IManipulationDeltaRoutedEventArgs)->put_Handled(value));
}

template <typename D> Windows::Devices::Input::PointerDeviceType impl_IManipulationDeltaRoutedEventArgs<D>::PointerDeviceType() const
{
    Windows::Devices::Input::PointerDeviceType value {};
    check_hresult(WINRT_SHIM(IManipulationDeltaRoutedEventArgs)->get_PointerDeviceType(&value));
    return value;
}

template <typename D> void impl_IManipulationDeltaRoutedEventArgs<D>::Complete() const
{
    check_hresult(WINRT_SHIM(IManipulationDeltaRoutedEventArgs)->abi_Complete());
}

template <typename D> Windows::UI::Xaml::UIElement impl_IManipulationInertiaStartingRoutedEventArgs<D>::Container() const
{
    Windows::UI::Xaml::UIElement value { nullptr };
    check_hresult(WINRT_SHIM(IManipulationInertiaStartingRoutedEventArgs)->get_Container(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Input::InertiaExpansionBehavior impl_IManipulationInertiaStartingRoutedEventArgs<D>::ExpansionBehavior() const
{
    Windows::UI::Xaml::Input::InertiaExpansionBehavior value { nullptr };
    check_hresult(WINRT_SHIM(IManipulationInertiaStartingRoutedEventArgs)->get_ExpansionBehavior(put_abi(value)));
    return value;
}

template <typename D> void impl_IManipulationInertiaStartingRoutedEventArgs<D>::ExpansionBehavior(const Windows::UI::Xaml::Input::InertiaExpansionBehavior & value) const
{
    check_hresult(WINRT_SHIM(IManipulationInertiaStartingRoutedEventArgs)->put_ExpansionBehavior(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Input::InertiaRotationBehavior impl_IManipulationInertiaStartingRoutedEventArgs<D>::RotationBehavior() const
{
    Windows::UI::Xaml::Input::InertiaRotationBehavior value { nullptr };
    check_hresult(WINRT_SHIM(IManipulationInertiaStartingRoutedEventArgs)->get_RotationBehavior(put_abi(value)));
    return value;
}

template <typename D> void impl_IManipulationInertiaStartingRoutedEventArgs<D>::RotationBehavior(const Windows::UI::Xaml::Input::InertiaRotationBehavior & value) const
{
    check_hresult(WINRT_SHIM(IManipulationInertiaStartingRoutedEventArgs)->put_RotationBehavior(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Input::InertiaTranslationBehavior impl_IManipulationInertiaStartingRoutedEventArgs<D>::TranslationBehavior() const
{
    Windows::UI::Xaml::Input::InertiaTranslationBehavior value { nullptr };
    check_hresult(WINRT_SHIM(IManipulationInertiaStartingRoutedEventArgs)->get_TranslationBehavior(put_abi(value)));
    return value;
}

template <typename D> void impl_IManipulationInertiaStartingRoutedEventArgs<D>::TranslationBehavior(const Windows::UI::Xaml::Input::InertiaTranslationBehavior & value) const
{
    check_hresult(WINRT_SHIM(IManipulationInertiaStartingRoutedEventArgs)->put_TranslationBehavior(get_abi(value)));
}

template <typename D> bool impl_IManipulationInertiaStartingRoutedEventArgs<D>::Handled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IManipulationInertiaStartingRoutedEventArgs)->get_Handled(&value));
    return value;
}

template <typename D> void impl_IManipulationInertiaStartingRoutedEventArgs<D>::Handled(bool value) const
{
    check_hresult(WINRT_SHIM(IManipulationInertiaStartingRoutedEventArgs)->put_Handled(value));
}

template <typename D> Windows::Devices::Input::PointerDeviceType impl_IManipulationInertiaStartingRoutedEventArgs<D>::PointerDeviceType() const
{
    Windows::Devices::Input::PointerDeviceType value {};
    check_hresult(WINRT_SHIM(IManipulationInertiaStartingRoutedEventArgs)->get_PointerDeviceType(&value));
    return value;
}

template <typename D> Windows::UI::Input::ManipulationDelta impl_IManipulationInertiaStartingRoutedEventArgs<D>::Delta() const
{
    Windows::UI::Input::ManipulationDelta value {};
    check_hresult(WINRT_SHIM(IManipulationInertiaStartingRoutedEventArgs)->get_Delta(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Input::ManipulationDelta impl_IManipulationInertiaStartingRoutedEventArgs<D>::Cumulative() const
{
    Windows::UI::Input::ManipulationDelta value {};
    check_hresult(WINRT_SHIM(IManipulationInertiaStartingRoutedEventArgs)->get_Cumulative(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Input::ManipulationVelocities impl_IManipulationInertiaStartingRoutedEventArgs<D>::Velocities() const
{
    Windows::UI::Input::ManipulationVelocities value {};
    check_hresult(WINRT_SHIM(IManipulationInertiaStartingRoutedEventArgs)->get_Velocities(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::UIElement impl_IManipulationStartedRoutedEventArgs<D>::Container() const
{
    Windows::UI::Xaml::UIElement value { nullptr };
    check_hresult(WINRT_SHIM(IManipulationStartedRoutedEventArgs)->get_Container(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Point impl_IManipulationStartedRoutedEventArgs<D>::Position() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(IManipulationStartedRoutedEventArgs)->get_Position(put_abi(value)));
    return value;
}

template <typename D> bool impl_IManipulationStartedRoutedEventArgs<D>::Handled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IManipulationStartedRoutedEventArgs)->get_Handled(&value));
    return value;
}

template <typename D> void impl_IManipulationStartedRoutedEventArgs<D>::Handled(bool value) const
{
    check_hresult(WINRT_SHIM(IManipulationStartedRoutedEventArgs)->put_Handled(value));
}

template <typename D> Windows::Devices::Input::PointerDeviceType impl_IManipulationStartedRoutedEventArgs<D>::PointerDeviceType() const
{
    Windows::Devices::Input::PointerDeviceType value {};
    check_hresult(WINRT_SHIM(IManipulationStartedRoutedEventArgs)->get_PointerDeviceType(&value));
    return value;
}

template <typename D> Windows::UI::Input::ManipulationDelta impl_IManipulationStartedRoutedEventArgs<D>::Cumulative() const
{
    Windows::UI::Input::ManipulationDelta value {};
    check_hresult(WINRT_SHIM(IManipulationStartedRoutedEventArgs)->get_Cumulative(put_abi(value)));
    return value;
}

template <typename D> void impl_IManipulationStartedRoutedEventArgs<D>::Complete() const
{
    check_hresult(WINRT_SHIM(IManipulationStartedRoutedEventArgs)->abi_Complete());
}

template <typename D> Windows::UI::Xaml::Input::ManipulationStartedRoutedEventArgs impl_IManipulationStartedRoutedEventArgsFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Input::ManipulationStartedRoutedEventArgs instance { nullptr };
    check_hresult(WINRT_SHIM(IManipulationStartedRoutedEventArgsFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Input::ManipulationModes impl_IManipulationStartingRoutedEventArgs<D>::Mode() const
{
    Windows::UI::Xaml::Input::ManipulationModes value {};
    check_hresult(WINRT_SHIM(IManipulationStartingRoutedEventArgs)->get_Mode(&value));
    return value;
}

template <typename D> void impl_IManipulationStartingRoutedEventArgs<D>::Mode(Windows::UI::Xaml::Input::ManipulationModes value) const
{
    check_hresult(WINRT_SHIM(IManipulationStartingRoutedEventArgs)->put_Mode(value));
}

template <typename D> Windows::UI::Xaml::UIElement impl_IManipulationStartingRoutedEventArgs<D>::Container() const
{
    Windows::UI::Xaml::UIElement value { nullptr };
    check_hresult(WINRT_SHIM(IManipulationStartingRoutedEventArgs)->get_Container(put_abi(value)));
    return value;
}

template <typename D> void impl_IManipulationStartingRoutedEventArgs<D>::Container(const Windows::UI::Xaml::UIElement & value) const
{
    check_hresult(WINRT_SHIM(IManipulationStartingRoutedEventArgs)->put_Container(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Input::ManipulationPivot impl_IManipulationStartingRoutedEventArgs<D>::Pivot() const
{
    Windows::UI::Xaml::Input::ManipulationPivot value { nullptr };
    check_hresult(WINRT_SHIM(IManipulationStartingRoutedEventArgs)->get_Pivot(put_abi(value)));
    return value;
}

template <typename D> void impl_IManipulationStartingRoutedEventArgs<D>::Pivot(const Windows::UI::Xaml::Input::ManipulationPivot & value) const
{
    check_hresult(WINRT_SHIM(IManipulationStartingRoutedEventArgs)->put_Pivot(get_abi(value)));
}

template <typename D> bool impl_IManipulationStartingRoutedEventArgs<D>::Handled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IManipulationStartingRoutedEventArgs)->get_Handled(&value));
    return value;
}

template <typename D> void impl_IManipulationStartingRoutedEventArgs<D>::Handled(bool value) const
{
    check_hresult(WINRT_SHIM(IManipulationStartingRoutedEventArgs)->put_Handled(value));
}

template <typename D> Windows::UI::Xaml::Input::Pointer impl_IPointerRoutedEventArgs<D>::Pointer() const
{
    Windows::UI::Xaml::Input::Pointer value { nullptr };
    check_hresult(WINRT_SHIM(IPointerRoutedEventArgs)->get_Pointer(put_abi(value)));
    return value;
}

template <typename D> Windows::System::VirtualKeyModifiers impl_IPointerRoutedEventArgs<D>::KeyModifiers() const
{
    Windows::System::VirtualKeyModifiers value {};
    check_hresult(WINRT_SHIM(IPointerRoutedEventArgs)->get_KeyModifiers(&value));
    return value;
}

template <typename D> bool impl_IPointerRoutedEventArgs<D>::Handled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPointerRoutedEventArgs)->get_Handled(&value));
    return value;
}

template <typename D> void impl_IPointerRoutedEventArgs<D>::Handled(bool value) const
{
    check_hresult(WINRT_SHIM(IPointerRoutedEventArgs)->put_Handled(value));
}

template <typename D> Windows::UI::Input::PointerPoint impl_IPointerRoutedEventArgs<D>::GetCurrentPoint(const Windows::UI::Xaml::UIElement & relativeTo) const
{
    Windows::UI::Input::PointerPoint returnValue { nullptr };
    check_hresult(WINRT_SHIM(IPointerRoutedEventArgs)->abi_GetCurrentPoint(get_abi(relativeTo), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::UI::Input::PointerPoint> impl_IPointerRoutedEventArgs<D>::GetIntermediatePoints(const Windows::UI::Xaml::UIElement & relativeTo) const
{
    Windows::Foundation::Collections::IVector<Windows::UI::Input::PointerPoint> returnValue;
    check_hresult(WINRT_SHIM(IPointerRoutedEventArgs)->abi_GetIntermediatePoints(get_abi(relativeTo), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Devices::Input::PointerDeviceType impl_IRightTappedRoutedEventArgs<D>::PointerDeviceType() const
{
    Windows::Devices::Input::PointerDeviceType value {};
    check_hresult(WINRT_SHIM(IRightTappedRoutedEventArgs)->get_PointerDeviceType(&value));
    return value;
}

template <typename D> bool impl_IRightTappedRoutedEventArgs<D>::Handled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IRightTappedRoutedEventArgs)->get_Handled(&value));
    return value;
}

template <typename D> void impl_IRightTappedRoutedEventArgs<D>::Handled(bool value) const
{
    check_hresult(WINRT_SHIM(IRightTappedRoutedEventArgs)->put_Handled(value));
}

template <typename D> Windows::Foundation::Point impl_IRightTappedRoutedEventArgs<D>::GetPosition(const Windows::UI::Xaml::UIElement & relativeTo) const
{
    Windows::Foundation::Point returnValue {};
    check_hresult(WINRT_SHIM(IRightTappedRoutedEventArgs)->abi_GetPosition(get_abi(relativeTo), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Devices::Input::PointerDeviceType impl_ITappedRoutedEventArgs<D>::PointerDeviceType() const
{
    Windows::Devices::Input::PointerDeviceType value {};
    check_hresult(WINRT_SHIM(ITappedRoutedEventArgs)->get_PointerDeviceType(&value));
    return value;
}

template <typename D> bool impl_ITappedRoutedEventArgs<D>::Handled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ITappedRoutedEventArgs)->get_Handled(&value));
    return value;
}

template <typename D> void impl_ITappedRoutedEventArgs<D>::Handled(bool value) const
{
    check_hresult(WINRT_SHIM(ITappedRoutedEventArgs)->put_Handled(value));
}

template <typename D> Windows::Foundation::Point impl_ITappedRoutedEventArgs<D>::GetPosition(const Windows::UI::Xaml::UIElement & relativeTo) const
{
    Windows::Foundation::Point returnValue {};
    check_hresult(WINRT_SHIM(ITappedRoutedEventArgs)->abi_GetPosition(get_abi(relativeTo), put_abi(returnValue)));
    return returnValue;
}

inline AccessKeyDisplayDismissedEventArgs::AccessKeyDisplayDismissedEventArgs() :
    AccessKeyDisplayDismissedEventArgs(activate_instance<AccessKeyDisplayDismissedEventArgs>())
{}

inline AccessKeyDisplayRequestedEventArgs::AccessKeyDisplayRequestedEventArgs() :
    AccessKeyDisplayRequestedEventArgs(activate_instance<AccessKeyDisplayRequestedEventArgs>())
{}

inline AccessKeyInvokedEventArgs::AccessKeyInvokedEventArgs() :
    AccessKeyInvokedEventArgs(activate_instance<AccessKeyInvokedEventArgs>())
{}

inline bool AccessKeyManager::IsDisplayModeEnabled()
{
    return get_activation_factory<AccessKeyManager, IAccessKeyManagerStatics>().IsDisplayModeEnabled();
}

inline event_token AccessKeyManager::IsDisplayModeEnabledChanged(const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::Foundation::IInspectable> & value)
{
    return get_activation_factory<AccessKeyManager, IAccessKeyManagerStatics>().IsDisplayModeEnabledChanged(value);
}

inline factory_event_revoker<IAccessKeyManagerStatics> AccessKeyManager::IsDisplayModeEnabledChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::Foundation::IInspectable> & value)
{
    auto factory = get_activation_factory<AccessKeyManager, IAccessKeyManagerStatics>();
    return { factory, &ABI::Windows::UI::Xaml::Input::IAccessKeyManagerStatics::remove_IsDisplayModeEnabledChanged, factory.IsDisplayModeEnabledChanged(value) };
}

inline void AccessKeyManager::IsDisplayModeEnabledChanged(event_token token)
{
    get_activation_factory<AccessKeyManager, IAccessKeyManagerStatics>().IsDisplayModeEnabledChanged(token);
}

inline void AccessKeyManager::ExitDisplayMode()
{
    get_activation_factory<AccessKeyManager, IAccessKeyManagerStatics>().ExitDisplayMode();
}

inline ContextRequestedEventArgs::ContextRequestedEventArgs() :
    ContextRequestedEventArgs(activate_instance<ContextRequestedEventArgs>())
{}

inline DoubleTappedRoutedEventArgs::DoubleTappedRoutedEventArgs() :
    DoubleTappedRoutedEventArgs(activate_instance<DoubleTappedRoutedEventArgs>())
{}

inline Windows::Foundation::IInspectable FocusManager::GetFocusedElement()
{
    return get_activation_factory<FocusManager, IFocusManagerStatics>().GetFocusedElement();
}

inline bool FocusManager::TryMoveFocus(Windows::UI::Xaml::Input::FocusNavigationDirection focusNavigationDirection)
{
    return get_activation_factory<FocusManager, IFocusManagerStatics2>().TryMoveFocus(focusNavigationDirection);
}

inline Windows::UI::Xaml::UIElement FocusManager::FindNextFocusableElement(Windows::UI::Xaml::Input::FocusNavigationDirection focusNavigationDirection)
{
    return get_activation_factory<FocusManager, IFocusManagerStatics3>().FindNextFocusableElement(focusNavigationDirection);
}

inline Windows::UI::Xaml::UIElement FocusManager::FindNextFocusableElement(Windows::UI::Xaml::Input::FocusNavigationDirection focusNavigationDirection, const Windows::Foundation::Rect & hintRect)
{
    return get_activation_factory<FocusManager, IFocusManagerStatics3>().FindNextFocusableElement(focusNavigationDirection, hintRect);
}

inline HoldingRoutedEventArgs::HoldingRoutedEventArgs() :
    HoldingRoutedEventArgs(activate_instance<HoldingRoutedEventArgs>())
{}

inline InputScope::InputScope() :
    InputScope(activate_instance<InputScope>())
{}

inline InputScopeName::InputScopeName() :
    InputScopeName(activate_instance<InputScopeName>())
{}

inline InputScopeName::InputScopeName(Windows::UI::Xaml::Input::InputScopeNameValue nameValue) :
    InputScopeName(get_activation_factory<InputScopeName, IInputScopeNameFactory>().CreateInstance(nameValue))
{}

inline ManipulationCompletedRoutedEventArgs::ManipulationCompletedRoutedEventArgs() :
    ManipulationCompletedRoutedEventArgs(activate_instance<ManipulationCompletedRoutedEventArgs>())
{}

inline ManipulationDeltaRoutedEventArgs::ManipulationDeltaRoutedEventArgs() :
    ManipulationDeltaRoutedEventArgs(activate_instance<ManipulationDeltaRoutedEventArgs>())
{}

inline ManipulationInertiaStartingRoutedEventArgs::ManipulationInertiaStartingRoutedEventArgs() :
    ManipulationInertiaStartingRoutedEventArgs(activate_instance<ManipulationInertiaStartingRoutedEventArgs>())
{}

inline ManipulationPivot::ManipulationPivot() :
    ManipulationPivot(activate_instance<ManipulationPivot>())
{}

inline ManipulationPivot::ManipulationPivot(const Windows::Foundation::Point & center, double radius) :
    ManipulationPivot(get_activation_factory<ManipulationPivot, IManipulationPivotFactory>().CreateInstanceWithCenterAndRadius(center, radius))
{}

inline ManipulationStartedRoutedEventArgs::ManipulationStartedRoutedEventArgs()
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<ManipulationStartedRoutedEventArgs, IManipulationStartedRoutedEventArgsFactory>().CreateInstance(outer, inner));
}

inline ManipulationStartingRoutedEventArgs::ManipulationStartingRoutedEventArgs() :
    ManipulationStartingRoutedEventArgs(activate_instance<ManipulationStartingRoutedEventArgs>())
{}

inline RightTappedRoutedEventArgs::RightTappedRoutedEventArgs() :
    RightTappedRoutedEventArgs(activate_instance<RightTappedRoutedEventArgs>())
{}

inline TappedRoutedEventArgs::TappedRoutedEventArgs() :
    TappedRoutedEventArgs(activate_instance<TappedRoutedEventArgs>())
{}

}

}
#pragma warning(pop)
