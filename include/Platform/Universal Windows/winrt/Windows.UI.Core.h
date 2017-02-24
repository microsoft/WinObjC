// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.System.3.h"
#include "internal/Windows.UI.Input.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.UI.Popups.3.h"
#include "internal/Windows.UI.Core.3.h"
#include "Windows.UI.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Core {

template <typename L> DispatchedHandler::DispatchedHandler(L lambda) :
    DispatchedHandler(impl::make_delegate<impl_DispatchedHandler<L>, DispatchedHandler>(std::forward<L>(lambda)))
{}

template <typename F> DispatchedHandler::DispatchedHandler(F * function) :
    DispatchedHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> DispatchedHandler::DispatchedHandler(O * object, M method) :
    DispatchedHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void DispatchedHandler::operator()() const
{
    check_hresult((*(abi<DispatchedHandler> **)this)->abi_Invoke());
}

template <typename L> IdleDispatchedHandler::IdleDispatchedHandler(L lambda) :
    IdleDispatchedHandler(impl::make_delegate<impl_IdleDispatchedHandler<L>, IdleDispatchedHandler>(std::forward<L>(lambda)))
{}

template <typename F> IdleDispatchedHandler::IdleDispatchedHandler(F * function) :
    IdleDispatchedHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> IdleDispatchedHandler::IdleDispatchedHandler(O * object, M method) :
    IdleDispatchedHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void IdleDispatchedHandler::operator()(const Windows::UI::Core::IdleDispatchedHandlerArgs & e) const
{
    check_hresult((*(abi<IdleDispatchedHandler> **)this)->abi_Invoke(get_abi(e)));
}

}

namespace impl {

template <typename D>
struct produce<D, Windows::UI::Core::IAcceleratorKeyEventArgs> : produce_base<D, Windows::UI::Core::IAcceleratorKeyEventArgs>
{
    HRESULT __stdcall get_EventType(Windows::UI::Core::CoreAcceleratorKeyEventType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EventType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VirtualKey(Windows::System::VirtualKey * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VirtualKey());
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
};

template <typename D>
struct produce<D, Windows::UI::Core::IAcceleratorKeyEventArgs2> : produce_base<D, Windows::UI::Core::IAcceleratorKeyEventArgs2>
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
struct produce<D, Windows::UI::Core::IAutomationProviderRequestedEventArgs> : produce_base<D, Windows::UI::Core::IAutomationProviderRequestedEventArgs>
{
    HRESULT __stdcall get_AutomationProvider(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AutomationProvider());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AutomationProvider(impl::abi_arg_in<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AutomationProvider(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Core::IBackRequestedEventArgs> : produce_base<D, Windows::UI::Core::IBackRequestedEventArgs>
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
struct produce<D, Windows::UI::Core::ICharacterReceivedEventArgs> : produce_base<D, Windows::UI::Core::ICharacterReceivedEventArgs>
{
    HRESULT __stdcall get_KeyCode(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeyCode());
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
};

template <typename D>
struct produce<D, Windows::UI::Core::IClosestInteractiveBoundsRequestedEventArgs> : produce_base<D, Windows::UI::Core::IClosestInteractiveBoundsRequestedEventArgs>
{
    HRESULT __stdcall get_PointerPosition(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PointerPosition());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SearchBounds(impl::abi_arg_out<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SearchBounds());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ClosestInteractiveBounds(impl::abi_arg_out<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ClosestInteractiveBounds());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ClosestInteractiveBounds(impl::abi_arg_in<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClosestInteractiveBounds(*reinterpret_cast<const Windows::Foundation::Rect *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Core::ICoreAcceleratorKeys> : produce_base<D, Windows::UI::Core::ICoreAcceleratorKeys>
{
    HRESULT __stdcall add_AcceleratorKeyActivated(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreDispatcher, Windows::UI::Core::AcceleratorKeyEventArgs>> handler, event_token * pCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_abi(this->shim().AcceleratorKeyActivated(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreDispatcher, Windows::UI::Core::AcceleratorKeyEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AcceleratorKeyActivated(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AcceleratorKeyActivated(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Core::ICoreClosestInteractiveBoundsRequested> : produce_base<D, Windows::UI::Core::ICoreClosestInteractiveBoundsRequested>
{
    HRESULT __stdcall add_ClosestInteractiveBoundsRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreComponentInputSource, Windows::UI::Core::ClosestInteractiveBoundsRequestedEventArgs>> handler, event_token * pCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_abi(this->shim().ClosestInteractiveBoundsRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreComponentInputSource, Windows::UI::Core::ClosestInteractiveBoundsRequestedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ClosestInteractiveBoundsRequested(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClosestInteractiveBoundsRequested(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Core::ICoreComponentFocusable> : produce_base<D, Windows::UI::Core::ICoreComponentFocusable>
{
    HRESULT __stdcall get_HasFocus(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HasFocus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_GotFocus(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::CoreWindowEventArgs>> handler, event_token * pCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_abi(this->shim().GotFocus(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::CoreWindowEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_GotFocus(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GotFocus(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_LostFocus(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::CoreWindowEventArgs>> handler, event_token * pCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_abi(this->shim().LostFocus(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::CoreWindowEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_LostFocus(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LostFocus(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Core::ICoreCursor> : produce_base<D, Windows::UI::Core::ICoreCursor>
{
    HRESULT __stdcall get_Id(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Type(Windows::UI::Core::CoreCursorType * value) noexcept override
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
struct produce<D, Windows::UI::Core::ICoreCursorFactory> : produce_base<D, Windows::UI::Core::ICoreCursorFactory>
{
    HRESULT __stdcall abi_CreateCursor(Windows::UI::Core::CoreCursorType type, uint32_t id, impl::abi_arg_out<Windows::UI::Core::ICoreCursor> cursor) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cursor = detach_abi(this->shim().CreateCursor(type, id));
            return S_OK;
        }
        catch (...)
        {
            *cursor = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Core::ICoreDispatcher> : produce_base<D, Windows::UI::Core::ICoreDispatcher>
{
    HRESULT __stdcall get_HasThreadAccess(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HasThreadAccess());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ProcessEvents(Windows::UI::Core::CoreProcessEventsOption options) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProcessEvents(options);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RunAsync(Windows::UI::Core::CoreDispatcherPriority priority, impl::abi_arg_in<Windows::UI::Core::DispatchedHandler> agileCallback, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncAction) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncAction = detach_abi(this->shim().RunAsync(priority, *reinterpret_cast<const Windows::UI::Core::DispatchedHandler *>(&agileCallback)));
            return S_OK;
        }
        catch (...)
        {
            *asyncAction = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RunIdleAsync(impl::abi_arg_in<Windows::UI::Core::IdleDispatchedHandler> agileCallback, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncAction) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncAction = detach_abi(this->shim().RunIdleAsync(*reinterpret_cast<const Windows::UI::Core::IdleDispatchedHandler *>(&agileCallback)));
            return S_OK;
        }
        catch (...)
        {
            *asyncAction = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Core::ICoreDispatcher2> : produce_base<D, Windows::UI::Core::ICoreDispatcher2>
{
    HRESULT __stdcall abi_TryRunAsync(Windows::UI::Core::CoreDispatcherPriority priority, impl::abi_arg_in<Windows::UI::Core::DispatchedHandler> agileCallback, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> asyncOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOperation = detach_abi(this->shim().TryRunAsync(priority, *reinterpret_cast<const Windows::UI::Core::DispatchedHandler *>(&agileCallback)));
            return S_OK;
        }
        catch (...)
        {
            *asyncOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryRunIdleAsync(impl::abi_arg_in<Windows::UI::Core::IdleDispatchedHandler> agileCallback, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> asyncOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOperation = detach_abi(this->shim().TryRunIdleAsync(*reinterpret_cast<const Windows::UI::Core::IdleDispatchedHandler *>(&agileCallback)));
            return S_OK;
        }
        catch (...)
        {
            *asyncOperation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Core::ICoreDispatcherWithTaskPriority> : produce_base<D, Windows::UI::Core::ICoreDispatcherWithTaskPriority>
{
    HRESULT __stdcall get_CurrentPriority(Windows::UI::Core::CoreDispatcherPriority * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CurrentPriority());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CurrentPriority(Windows::UI::Core::CoreDispatcherPriority value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CurrentPriority(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShouldYield(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ShouldYield());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShouldYieldToPriority(Windows::UI::Core::CoreDispatcherPriority priority, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ShouldYield(priority));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StopProcessEvents() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StopProcessEvents();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Core::ICoreInputSourceBase> : produce_base<D, Windows::UI::Core::ICoreInputSourceBase>
{
    HRESULT __stdcall get_Dispatcher(impl::abi_arg_out<Windows::UI::Core::ICoreDispatcher> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Dispatcher());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsInputEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsInputEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsInputEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsInputEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_InputEnabled(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::InputEnabledEventArgs>> handler, event_token * pCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_abi(this->shim().InputEnabled(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::InputEnabledEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_InputEnabled(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InputEnabled(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Core::ICoreKeyboardInputSource> : produce_base<D, Windows::UI::Core::ICoreKeyboardInputSource>
{
    HRESULT __stdcall abi_GetCurrentKeyState(Windows::System::VirtualKey virtualKey, Windows::UI::Core::CoreVirtualKeyStates * KeyState) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *KeyState = detach_abi(this->shim().GetCurrentKeyState(virtualKey));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_CharacterReceived(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::CharacterReceivedEventArgs>> handler, event_token * pCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_abi(this->shim().CharacterReceived(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::CharacterReceivedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CharacterReceived(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CharacterReceived(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_KeyDown(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::KeyEventArgs>> handler, event_token * pCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_abi(this->shim().KeyDown(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::KeyEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_KeyDown(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().KeyDown(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_KeyUp(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::KeyEventArgs>> handler, event_token * pCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_abi(this->shim().KeyUp(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::KeyEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_KeyUp(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().KeyUp(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Core::ICoreKeyboardInputSource2> : produce_base<D, Windows::UI::Core::ICoreKeyboardInputSource2>
{
    HRESULT __stdcall abi_GetCurrentKeyEventDeviceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetCurrentKeyEventDeviceId());
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
struct produce<D, Windows::UI::Core::ICorePointerInputSource> : produce_base<D, Windows::UI::Core::ICorePointerInputSource>
{
    HRESULT __stdcall abi_ReleasePointerCapture() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReleasePointerCapture();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPointerCapture() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPointerCapture();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HasCapture(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HasCapture());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PointerPosition(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PointerPosition());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PointerCursor(impl::abi_arg_out<Windows::UI::Core::ICoreCursor> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PointerCursor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PointerCursor(impl::abi_arg_in<Windows::UI::Core::ICoreCursor> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerCursor(*reinterpret_cast<const Windows::UI::Core::CoreCursor *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PointerCaptureLost(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::PointerEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().PointerCaptureLost(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::PointerEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerCaptureLost(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerCaptureLost(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PointerEntered(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::PointerEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().PointerEntered(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::PointerEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerEntered(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerEntered(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PointerExited(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::PointerEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().PointerExited(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::PointerEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerExited(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerExited(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PointerMoved(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::PointerEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().PointerMoved(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::PointerEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerMoved(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerMoved(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PointerPressed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::PointerEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().PointerPressed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::PointerEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerPressed(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerPressed(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PointerReleased(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::PointerEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().PointerReleased(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::PointerEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerReleased(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerReleased(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PointerWheelChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::PointerEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().PointerWheelChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::PointerEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerWheelChanged(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerWheelChanged(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Core::ICorePointerRedirector> : produce_base<D, Windows::UI::Core::ICorePointerRedirector>
{
    HRESULT __stdcall add_PointerRoutedAway(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Core::ICorePointerRedirector, Windows::UI::Core::PointerEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().PointerRoutedAway(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Core::ICorePointerRedirector, Windows::UI::Core::PointerEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerRoutedAway(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerRoutedAway(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PointerRoutedTo(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Core::ICorePointerRedirector, Windows::UI::Core::PointerEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().PointerRoutedTo(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Core::ICorePointerRedirector, Windows::UI::Core::PointerEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerRoutedTo(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerRoutedTo(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PointerRoutedReleased(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Core::ICorePointerRedirector, Windows::UI::Core::PointerEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().PointerRoutedReleased(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Core::ICorePointerRedirector, Windows::UI::Core::PointerEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerRoutedReleased(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerRoutedReleased(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Core::ICoreTouchHitTesting> : produce_base<D, Windows::UI::Core::ICoreTouchHitTesting>
{
    HRESULT __stdcall add_TouchHitTesting(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::TouchHitTestingEventArgs>> handler, event_token * pCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_abi(this->shim().TouchHitTesting(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::TouchHitTestingEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_TouchHitTesting(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TouchHitTesting(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Core::ICoreWindow> : produce_base<D, Windows::UI::Core::ICoreWindow>
{
    HRESULT __stdcall get_AutomationHostProvider(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AutomationHostProvider());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Bounds(impl::abi_arg_out<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Bounds());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CustomProperties(impl::abi_arg_out<Windows::Foundation::Collections::IPropertySet> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CustomProperties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Dispatcher(impl::abi_arg_out<Windows::UI::Core::ICoreDispatcher> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Dispatcher());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FlowDirection(Windows::UI::Core::CoreWindowFlowDirection * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FlowDirection());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FlowDirection(Windows::UI::Core::CoreWindowFlowDirection value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FlowDirection(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsInputEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsInputEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsInputEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsInputEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PointerCursor(impl::abi_arg_out<Windows::UI::Core::ICoreCursor> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PointerCursor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PointerCursor(impl::abi_arg_in<Windows::UI::Core::ICoreCursor> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerCursor(*reinterpret_cast<const Windows::UI::Core::CoreCursor *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PointerPosition(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PointerPosition());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Visible(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Visible());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Activate() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Activate();
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

    HRESULT __stdcall abi_GetAsyncKeyState(Windows::System::VirtualKey virtualKey, Windows::UI::Core::CoreVirtualKeyStates * KeyState) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *KeyState = detach_abi(this->shim().GetAsyncKeyState(virtualKey));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetKeyState(Windows::System::VirtualKey virtualKey, Windows::UI::Core::CoreVirtualKeyStates * KeyState) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *KeyState = detach_abi(this->shim().GetKeyState(virtualKey));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReleasePointerCapture() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReleasePointerCapture();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPointerCapture() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPointerCapture();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Activated(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::WindowActivatedEventArgs>> handler, event_token * pCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_abi(this->shim().Activated(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::WindowActivatedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Activated(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Activated(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_AutomationProviderRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::AutomationProviderRequestedEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().AutomationProviderRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::AutomationProviderRequestedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AutomationProviderRequested(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AutomationProviderRequested(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_CharacterReceived(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::CharacterReceivedEventArgs>> handler, event_token * pCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_abi(this->shim().CharacterReceived(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::CharacterReceivedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CharacterReceived(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CharacterReceived(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Closed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::CoreWindowEventArgs>> handler, event_token * pCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_abi(this->shim().Closed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::CoreWindowEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Closed(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Closed(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_InputEnabled(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::InputEnabledEventArgs>> handler, event_token * pCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_abi(this->shim().InputEnabled(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::InputEnabledEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_InputEnabled(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InputEnabled(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_KeyDown(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::KeyEventArgs>> handler, event_token * pCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_abi(this->shim().KeyDown(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::KeyEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_KeyDown(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().KeyDown(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_KeyUp(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::KeyEventArgs>> handler, event_token * pCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_abi(this->shim().KeyUp(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::KeyEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_KeyUp(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().KeyUp(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PointerCaptureLost(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::PointerEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().PointerCaptureLost(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::PointerEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerCaptureLost(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerCaptureLost(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PointerEntered(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::PointerEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().PointerEntered(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::PointerEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerEntered(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerEntered(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PointerExited(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::PointerEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().PointerExited(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::PointerEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerExited(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerExited(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PointerMoved(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::PointerEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().PointerMoved(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::PointerEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerMoved(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerMoved(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PointerPressed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::PointerEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().PointerPressed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::PointerEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerPressed(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerPressed(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PointerReleased(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::PointerEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().PointerReleased(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::PointerEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerReleased(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerReleased(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_TouchHitTesting(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::TouchHitTestingEventArgs>> handler, event_token * pCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_abi(this->shim().TouchHitTesting(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::TouchHitTestingEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_TouchHitTesting(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TouchHitTesting(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PointerWheelChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::PointerEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().PointerWheelChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::PointerEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerWheelChanged(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerWheelChanged(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_SizeChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::WindowSizeChangedEventArgs>> handler, event_token * pCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_abi(this->shim().SizeChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::WindowSizeChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SizeChanged(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SizeChanged(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_VisibilityChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::VisibilityChangedEventArgs>> handler, event_token * pCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_abi(this->shim().VisibilityChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::VisibilityChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_VisibilityChanged(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VisibilityChanged(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Core::ICoreWindow2> : produce_base<D, Windows::UI::Core::ICoreWindow2>
{
    HRESULT __stdcall put_PointerPosition(impl::abi_arg_in<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerPosition(*reinterpret_cast<const Windows::Foundation::Point *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Core::ICoreWindow3> : produce_base<D, Windows::UI::Core::ICoreWindow3>
{
    HRESULT __stdcall add_ClosestInteractiveBoundsRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::ClosestInteractiveBoundsRequestedEventArgs>> handler, event_token * pCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_abi(this->shim().ClosestInteractiveBoundsRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::ClosestInteractiveBoundsRequestedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ClosestInteractiveBoundsRequested(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClosestInteractiveBoundsRequested(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCurrentKeyEventDeviceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetCurrentKeyEventDeviceId());
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
struct produce<D, Windows::UI::Core::ICoreWindowDialog> : produce_base<D, Windows::UI::Core::ICoreWindowDialog>
{
    HRESULT __stdcall add_Showing(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::CoreWindowPopupShowingEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().Showing(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::CoreWindowPopupShowingEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Showing(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Showing(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxSize(impl::abi_arg_out<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinSize(impl::abi_arg_out<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Title(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Title());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Title(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Title(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsInteractionDelayed(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsInteractionDelayed());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsInteractionDelayed(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsInteractionDelayed(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Commands(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Popups::IUICommand>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Commands());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DefaultCommandIndex(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DefaultCommandIndex());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DefaultCommandIndex(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DefaultCommandIndex(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CancelCommandIndex(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CancelCommandIndex());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CancelCommandIndex(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CancelCommandIndex(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BackButtonCommand(impl::abi_arg_out<Windows::UI::Popups::UICommandInvokedHandler> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BackButtonCommand());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BackButtonCommand(impl::abi_arg_in<Windows::UI::Popups::UICommandInvokedHandler> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BackButtonCommand(*reinterpret_cast<const Windows::UI::Popups::UICommandInvokedHandler *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::UI::Popups::IUICommand>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().ShowAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Core::ICoreWindowDialogFactory> : produce_base<D, Windows::UI::Core::ICoreWindowDialogFactory>
{
    HRESULT __stdcall abi_CreateWithTitle(impl::abi_arg_in<hstring> title, impl::abi_arg_out<Windows::UI::Core::ICoreWindowDialog> coreWindowDialog) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *coreWindowDialog = detach_abi(this->shim().CreateWithTitle(*reinterpret_cast<const hstring *>(&title)));
            return S_OK;
        }
        catch (...)
        {
            *coreWindowDialog = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Core::ICoreWindowEventArgs> : produce_base<D, Windows::UI::Core::ICoreWindowEventArgs>
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
struct produce<D, Windows::UI::Core::ICoreWindowFlyout> : produce_base<D, Windows::UI::Core::ICoreWindowFlyout>
{
    HRESULT __stdcall add_Showing(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::CoreWindowPopupShowingEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().Showing(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::CoreWindowPopupShowingEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Showing(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Showing(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxSize(impl::abi_arg_out<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinSize(impl::abi_arg_out<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Title(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Title());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Title(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Title(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsInteractionDelayed(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsInteractionDelayed());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsInteractionDelayed(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsInteractionDelayed(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Commands(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Popups::IUICommand>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Commands());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DefaultCommandIndex(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DefaultCommandIndex());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DefaultCommandIndex(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DefaultCommandIndex(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BackButtonCommand(impl::abi_arg_out<Windows::UI::Popups::UICommandInvokedHandler> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BackButtonCommand());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BackButtonCommand(impl::abi_arg_in<Windows::UI::Popups::UICommandInvokedHandler> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BackButtonCommand(*reinterpret_cast<const Windows::UI::Popups::UICommandInvokedHandler *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::UI::Popups::IUICommand>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().ShowAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Core::ICoreWindowFlyoutFactory> : produce_base<D, Windows::UI::Core::ICoreWindowFlyoutFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Foundation::Point> position, impl::abi_arg_out<Windows::UI::Core::ICoreWindowFlyout> coreWindowFlyout) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *coreWindowFlyout = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Foundation::Point *>(&position)));
            return S_OK;
        }
        catch (...)
        {
            *coreWindowFlyout = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithTitle(impl::abi_arg_in<Windows::Foundation::Point> position, impl::abi_arg_in<hstring> title, impl::abi_arg_out<Windows::UI::Core::ICoreWindowFlyout> coreWindowFlyout) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *coreWindowFlyout = detach_abi(this->shim().CreateWithTitle(*reinterpret_cast<const Windows::Foundation::Point *>(&position), *reinterpret_cast<const hstring *>(&title)));
            return S_OK;
        }
        catch (...)
        {
            *coreWindowFlyout = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Core::ICoreWindowPopupShowingEventArgs> : produce_base<D, Windows::UI::Core::ICoreWindowPopupShowingEventArgs>
{
    HRESULT __stdcall abi_SetDesiredSize(impl::abi_arg_in<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetDesiredSize(*reinterpret_cast<const Windows::Foundation::Size *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Core::ICoreWindowResizeManager> : produce_base<D, Windows::UI::Core::ICoreWindowResizeManager>
{
    HRESULT __stdcall abi_NotifyLayoutCompleted() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyLayoutCompleted();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Core::ICoreWindowResizeManagerLayoutCapability> : produce_base<D, Windows::UI::Core::ICoreWindowResizeManagerLayoutCapability>
{
    HRESULT __stdcall put_ShouldWaitForLayoutCompletion(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShouldWaitForLayoutCompletion(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ShouldWaitForLayoutCompletion(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ShouldWaitForLayoutCompletion());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Core::ICoreWindowResizeManagerStatics> : produce_base<D, Windows::UI::Core::ICoreWindowResizeManagerStatics>
{
    HRESULT __stdcall abi_GetForCurrentView(impl::abi_arg_out<Windows::UI::Core::ICoreWindowResizeManager> CoreWindowResizeManager) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *CoreWindowResizeManager = detach_abi(this->shim().GetForCurrentView());
            return S_OK;
        }
        catch (...)
        {
            *CoreWindowResizeManager = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Core::ICoreWindowStatic> : produce_base<D, Windows::UI::Core::ICoreWindowStatic>
{
    HRESULT __stdcall abi_GetForCurrentThread(impl::abi_arg_out<Windows::UI::Core::ICoreWindow> ppWindow) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *ppWindow = detach_abi(this->shim().GetForCurrentThread());
            return S_OK;
        }
        catch (...)
        {
            *ppWindow = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Core::IIdleDispatchedHandlerArgs> : produce_base<D, Windows::UI::Core::IIdleDispatchedHandlerArgs>
{
    HRESULT __stdcall get_IsDispatcherIdle(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDispatcherIdle());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Core::IInitializeWithCoreWindow> : produce_base<D, Windows::UI::Core::IInitializeWithCoreWindow>
{
    HRESULT __stdcall abi_Initialize(impl::abi_arg_in<Windows::UI::Core::ICoreWindow> window) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Initialize(*reinterpret_cast<const Windows::UI::Core::CoreWindow *>(&window));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Core::IInputEnabledEventArgs> : produce_base<D, Windows::UI::Core::IInputEnabledEventArgs>
{
    HRESULT __stdcall get_InputEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InputEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Core::IKeyEventArgs> : produce_base<D, Windows::UI::Core::IKeyEventArgs>
{
    HRESULT __stdcall get_VirtualKey(Windows::System::VirtualKey * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VirtualKey());
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
};

template <typename D>
struct produce<D, Windows::UI::Core::IKeyEventArgs2> : produce_base<D, Windows::UI::Core::IKeyEventArgs2>
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
struct produce<D, Windows::UI::Core::IPointerEventArgs> : produce_base<D, Windows::UI::Core::IPointerEventArgs>
{
    HRESULT __stdcall get_CurrentPoint(impl::abi_arg_out<Windows::UI::Input::IPointerPoint> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CurrentPoint());
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

    HRESULT __stdcall abi_GetIntermediatePoints(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Input::PointerPoint>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetIntermediatePoints());
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
struct produce<D, Windows::UI::Core::ISystemNavigationManager> : produce_base<D, Windows::UI::Core::ISystemNavigationManager>
{
    HRESULT __stdcall add_BackRequested(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::UI::Core::BackRequestedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().BackRequested(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::UI::Core::BackRequestedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_BackRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BackRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Core::ISystemNavigationManager2> : produce_base<D, Windows::UI::Core::ISystemNavigationManager2>
{
    HRESULT __stdcall get_AppViewBackButtonVisibility(Windows::UI::Core::AppViewBackButtonVisibility * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AppViewBackButtonVisibility());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AppViewBackButtonVisibility(Windows::UI::Core::AppViewBackButtonVisibility value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AppViewBackButtonVisibility(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Core::ISystemNavigationManagerStatics> : produce_base<D, Windows::UI::Core::ISystemNavigationManagerStatics>
{
    HRESULT __stdcall abi_GetForCurrentView(impl::abi_arg_out<Windows::UI::Core::ISystemNavigationManager> loader) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *loader = detach_abi(this->shim().GetForCurrentView());
            return S_OK;
        }
        catch (...)
        {
            *loader = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Core::ITouchHitTestingEventArgs> : produce_base<D, Windows::UI::Core::ITouchHitTestingEventArgs>
{
    HRESULT __stdcall get_ProximityEvaluation(impl::abi_arg_out<Windows::UI::Core::CoreProximityEvaluation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProximityEvaluation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ProximityEvaluation(impl::abi_arg_in<Windows::UI::Core::CoreProximityEvaluation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProximityEvaluation(*reinterpret_cast<const Windows::UI::Core::CoreProximityEvaluation *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Point(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Point());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BoundingBox(impl::abi_arg_out<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BoundingBox());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_EvaluateProximityToRect(impl::abi_arg_in<Windows::Foundation::Rect> controlBoundingBox, impl::abi_arg_out<Windows::UI::Core::CoreProximityEvaluation> proximityEvaluation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *proximityEvaluation = detach_abi(this->shim().EvaluateProximity(*reinterpret_cast<const Windows::Foundation::Rect *>(&controlBoundingBox)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_EvaluateProximityToPolygon(uint32_t __controlVerticesSize, impl::abi_arg_in<Windows::Foundation::Point> * controlVertices, impl::abi_arg_out<Windows::UI::Core::CoreProximityEvaluation> proximityEvaluation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *proximityEvaluation = detach_abi(this->shim().EvaluateProximity(*reinterpret_cast<const Windows::Foundation::Point *>(&controlVertices)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Core::IVisibilityChangedEventArgs> : produce_base<D, Windows::UI::Core::IVisibilityChangedEventArgs>
{
    HRESULT __stdcall get_Visible(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Visible());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Core::IWindowActivatedEventArgs> : produce_base<D, Windows::UI::Core::IWindowActivatedEventArgs>
{
    HRESULT __stdcall get_WindowActivationState(Windows::UI::Core::CoreWindowActivationState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WindowActivationState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Core::IWindowSizeChangedEventArgs> : produce_base<D, Windows::UI::Core::IWindowSizeChangedEventArgs>
{
    HRESULT __stdcall get_Size(impl::abi_arg_out<Windows::Foundation::Size> value) noexcept override
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
};

}

namespace Windows::UI::Core {

template <typename D> bool impl_ICoreWindowEventArgs<D>::Handled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICoreWindowEventArgs)->get_Handled(&value));
    return value;
}

template <typename D> void impl_ICoreWindowEventArgs<D>::Handled(bool value) const
{
    check_hresult(WINRT_SHIM(ICoreWindowEventArgs)->put_Handled(value));
}

template <typename D> Windows::Foundation::IInspectable impl_IAutomationProviderRequestedEventArgs<D>::AutomationProvider() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IAutomationProviderRequestedEventArgs)->get_AutomationProvider(put_abi(value)));
    return value;
}

template <typename D> void impl_IAutomationProviderRequestedEventArgs<D>::AutomationProvider(const Windows::Foundation::IInspectable & value) const
{
    check_hresult(WINRT_SHIM(IAutomationProviderRequestedEventArgs)->put_AutomationProvider(get_abi(value)));
}

template <typename D> uint32_t impl_ICharacterReceivedEventArgs<D>::KeyCode() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ICharacterReceivedEventArgs)->get_KeyCode(&value));
    return value;
}

template <typename D> Windows::UI::Core::CorePhysicalKeyStatus impl_ICharacterReceivedEventArgs<D>::KeyStatus() const
{
    Windows::UI::Core::CorePhysicalKeyStatus value {};
    check_hresult(WINRT_SHIM(ICharacterReceivedEventArgs)->get_KeyStatus(put_abi(value)));
    return value;
}

template <typename D> bool impl_IInputEnabledEventArgs<D>::InputEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IInputEnabledEventArgs)->get_InputEnabled(&value));
    return value;
}

template <typename D> Windows::System::VirtualKey impl_IKeyEventArgs<D>::VirtualKey() const
{
    Windows::System::VirtualKey value {};
    check_hresult(WINRT_SHIM(IKeyEventArgs)->get_VirtualKey(&value));
    return value;
}

template <typename D> Windows::UI::Core::CorePhysicalKeyStatus impl_IKeyEventArgs<D>::KeyStatus() const
{
    Windows::UI::Core::CorePhysicalKeyStatus value {};
    check_hresult(WINRT_SHIM(IKeyEventArgs)->get_KeyStatus(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IKeyEventArgs2<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IKeyEventArgs2)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Input::PointerPoint impl_IPointerEventArgs<D>::CurrentPoint() const
{
    Windows::UI::Input::PointerPoint value { nullptr };
    check_hresult(WINRT_SHIM(IPointerEventArgs)->get_CurrentPoint(put_abi(value)));
    return value;
}

template <typename D> Windows::System::VirtualKeyModifiers impl_IPointerEventArgs<D>::KeyModifiers() const
{
    Windows::System::VirtualKeyModifiers value {};
    check_hresult(WINRT_SHIM(IPointerEventArgs)->get_KeyModifiers(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::UI::Input::PointerPoint> impl_IPointerEventArgs<D>::GetIntermediatePoints() const
{
    Windows::Foundation::Collections::IVector<Windows::UI::Input::PointerPoint> value;
    check_hresult(WINRT_SHIM(IPointerEventArgs)->abi_GetIntermediatePoints(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Core::CoreProximityEvaluation impl_ITouchHitTestingEventArgs<D>::ProximityEvaluation() const
{
    Windows::UI::Core::CoreProximityEvaluation value {};
    check_hresult(WINRT_SHIM(ITouchHitTestingEventArgs)->get_ProximityEvaluation(put_abi(value)));
    return value;
}

template <typename D> void impl_ITouchHitTestingEventArgs<D>::ProximityEvaluation(const Windows::UI::Core::CoreProximityEvaluation & value) const
{
    check_hresult(WINRT_SHIM(ITouchHitTestingEventArgs)->put_ProximityEvaluation(get_abi(value)));
}

template <typename D> Windows::Foundation::Point impl_ITouchHitTestingEventArgs<D>::Point() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(ITouchHitTestingEventArgs)->get_Point(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Rect impl_ITouchHitTestingEventArgs<D>::BoundingBox() const
{
    Windows::Foundation::Rect value {};
    check_hresult(WINRT_SHIM(ITouchHitTestingEventArgs)->get_BoundingBox(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Core::CoreProximityEvaluation impl_ITouchHitTestingEventArgs<D>::EvaluateProximity(const Windows::Foundation::Rect & controlBoundingBox) const
{
    Windows::UI::Core::CoreProximityEvaluation proximityEvaluation {};
    check_hresult(WINRT_SHIM(ITouchHitTestingEventArgs)->abi_EvaluateProximityToRect(get_abi(controlBoundingBox), put_abi(proximityEvaluation)));
    return proximityEvaluation;
}

template <typename D> Windows::UI::Core::CoreProximityEvaluation impl_ITouchHitTestingEventArgs<D>::EvaluateProximity(array_view<const Windows::Foundation::Point> controlVertices) const
{
    Windows::UI::Core::CoreProximityEvaluation proximityEvaluation {};
    check_hresult(WINRT_SHIM(ITouchHitTestingEventArgs)->abi_EvaluateProximityToPolygon(controlVertices.size(), get_abi(controlVertices), put_abi(proximityEvaluation)));
    return proximityEvaluation;
}

template <typename D> Windows::Foundation::Point impl_IClosestInteractiveBoundsRequestedEventArgs<D>::PointerPosition() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(IClosestInteractiveBoundsRequestedEventArgs)->get_PointerPosition(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Rect impl_IClosestInteractiveBoundsRequestedEventArgs<D>::SearchBounds() const
{
    Windows::Foundation::Rect value {};
    check_hresult(WINRT_SHIM(IClosestInteractiveBoundsRequestedEventArgs)->get_SearchBounds(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Rect impl_IClosestInteractiveBoundsRequestedEventArgs<D>::ClosestInteractiveBounds() const
{
    Windows::Foundation::Rect value {};
    check_hresult(WINRT_SHIM(IClosestInteractiveBoundsRequestedEventArgs)->get_ClosestInteractiveBounds(put_abi(value)));
    return value;
}

template <typename D> void impl_IClosestInteractiveBoundsRequestedEventArgs<D>::ClosestInteractiveBounds(const Windows::Foundation::Rect & value) const
{
    check_hresult(WINRT_SHIM(IClosestInteractiveBoundsRequestedEventArgs)->put_ClosestInteractiveBounds(get_abi(value)));
}

template <typename D> Windows::UI::Core::CoreWindowActivationState impl_IWindowActivatedEventArgs<D>::WindowActivationState() const
{
    Windows::UI::Core::CoreWindowActivationState value {};
    check_hresult(WINRT_SHIM(IWindowActivatedEventArgs)->get_WindowActivationState(&value));
    return value;
}

template <typename D> Windows::Foundation::Size impl_IWindowSizeChangedEventArgs<D>::Size() const
{
    Windows::Foundation::Size value {};
    check_hresult(WINRT_SHIM(IWindowSizeChangedEventArgs)->get_Size(put_abi(value)));
    return value;
}

template <typename D> bool impl_IVisibilityChangedEventArgs<D>::Visible() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IVisibilityChangedEventArgs)->get_Visible(&value));
    return value;
}

template <typename D> Windows::Foundation::IInspectable impl_ICoreWindow<D>::AutomationHostProvider() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(ICoreWindow)->get_AutomationHostProvider(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Rect impl_ICoreWindow<D>::Bounds() const
{
    Windows::Foundation::Rect value {};
    check_hresult(WINRT_SHIM(ICoreWindow)->get_Bounds(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IPropertySet impl_ICoreWindow<D>::CustomProperties() const
{
    Windows::Foundation::Collections::IPropertySet value;
    check_hresult(WINRT_SHIM(ICoreWindow)->get_CustomProperties(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Core::CoreDispatcher impl_ICoreWindow<D>::Dispatcher() const
{
    Windows::UI::Core::CoreDispatcher value { nullptr };
    check_hresult(WINRT_SHIM(ICoreWindow)->get_Dispatcher(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Core::CoreWindowFlowDirection impl_ICoreWindow<D>::FlowDirection() const
{
    Windows::UI::Core::CoreWindowFlowDirection value {};
    check_hresult(WINRT_SHIM(ICoreWindow)->get_FlowDirection(&value));
    return value;
}

template <typename D> void impl_ICoreWindow<D>::FlowDirection(Windows::UI::Core::CoreWindowFlowDirection value) const
{
    check_hresult(WINRT_SHIM(ICoreWindow)->put_FlowDirection(value));
}

template <typename D> bool impl_ICoreWindow<D>::IsInputEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICoreWindow)->get_IsInputEnabled(&value));
    return value;
}

template <typename D> void impl_ICoreWindow<D>::IsInputEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(ICoreWindow)->put_IsInputEnabled(value));
}

template <typename D> Windows::UI::Core::CoreCursor impl_ICoreWindow<D>::PointerCursor() const
{
    Windows::UI::Core::CoreCursor value { nullptr };
    check_hresult(WINRT_SHIM(ICoreWindow)->get_PointerCursor(put_abi(value)));
    return value;
}

template <typename D> void impl_ICoreWindow<D>::PointerCursor(const Windows::UI::Core::CoreCursor & value) const
{
    check_hresult(WINRT_SHIM(ICoreWindow)->put_PointerCursor(get_abi(value)));
}

template <typename D> Windows::Foundation::Point impl_ICoreWindow<D>::PointerPosition() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(ICoreWindow)->get_PointerPosition(put_abi(value)));
    return value;
}

template <typename D> bool impl_ICoreWindow<D>::Visible() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICoreWindow)->get_Visible(&value));
    return value;
}

template <typename D> void impl_ICoreWindow<D>::Activate() const
{
    check_hresult(WINRT_SHIM(ICoreWindow)->abi_Activate());
}

template <typename D> void impl_ICoreWindow<D>::Close() const
{
    check_hresult(WINRT_SHIM(ICoreWindow)->abi_Close());
}

template <typename D> Windows::UI::Core::CoreVirtualKeyStates impl_ICoreWindow<D>::GetAsyncKeyState(Windows::System::VirtualKey virtualKey) const
{
    Windows::UI::Core::CoreVirtualKeyStates KeyState {};
    check_hresult(WINRT_SHIM(ICoreWindow)->abi_GetAsyncKeyState(virtualKey, &KeyState));
    return KeyState;
}

template <typename D> Windows::UI::Core::CoreVirtualKeyStates impl_ICoreWindow<D>::GetKeyState(Windows::System::VirtualKey virtualKey) const
{
    Windows::UI::Core::CoreVirtualKeyStates KeyState {};
    check_hresult(WINRT_SHIM(ICoreWindow)->abi_GetKeyState(virtualKey, &KeyState));
    return KeyState;
}

template <typename D> void impl_ICoreWindow<D>::ReleasePointerCapture() const
{
    check_hresult(WINRT_SHIM(ICoreWindow)->abi_ReleasePointerCapture());
}

template <typename D> void impl_ICoreWindow<D>::SetPointerCapture() const
{
    check_hresult(WINRT_SHIM(ICoreWindow)->abi_SetPointerCapture());
}

template <typename D> event_token impl_ICoreWindow<D>::Activated(const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::WindowActivatedEventArgs> & handler) const
{
    event_token pCookie {};
    check_hresult(WINRT_SHIM(ICoreWindow)->add_Activated(get_abi(handler), &pCookie));
    return pCookie;
}

template <typename D> event_revoker<ICoreWindow> impl_ICoreWindow<D>::Activated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::WindowActivatedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreWindow>(this, &ABI::Windows::UI::Core::ICoreWindow::remove_Activated, Activated(handler));
}

template <typename D> void impl_ICoreWindow<D>::Activated(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreWindow)->remove_Activated(cookie));
}

template <typename D> event_token impl_ICoreWindow<D>::AutomationProviderRequested(const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::AutomationProviderRequestedEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICoreWindow)->add_AutomationProviderRequested(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICoreWindow> impl_ICoreWindow<D>::AutomationProviderRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::AutomationProviderRequestedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreWindow>(this, &ABI::Windows::UI::Core::ICoreWindow::remove_AutomationProviderRequested, AutomationProviderRequested(handler));
}

template <typename D> void impl_ICoreWindow<D>::AutomationProviderRequested(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreWindow)->remove_AutomationProviderRequested(cookie));
}

template <typename D> event_token impl_ICoreWindow<D>::CharacterReceived(const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::CharacterReceivedEventArgs> & handler) const
{
    event_token pCookie {};
    check_hresult(WINRT_SHIM(ICoreWindow)->add_CharacterReceived(get_abi(handler), &pCookie));
    return pCookie;
}

template <typename D> event_revoker<ICoreWindow> impl_ICoreWindow<D>::CharacterReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::CharacterReceivedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreWindow>(this, &ABI::Windows::UI::Core::ICoreWindow::remove_CharacterReceived, CharacterReceived(handler));
}

template <typename D> void impl_ICoreWindow<D>::CharacterReceived(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreWindow)->remove_CharacterReceived(cookie));
}

template <typename D> event_token impl_ICoreWindow<D>::Closed(const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::CoreWindowEventArgs> & handler) const
{
    event_token pCookie {};
    check_hresult(WINRT_SHIM(ICoreWindow)->add_Closed(get_abi(handler), &pCookie));
    return pCookie;
}

template <typename D> event_revoker<ICoreWindow> impl_ICoreWindow<D>::Closed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::CoreWindowEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreWindow>(this, &ABI::Windows::UI::Core::ICoreWindow::remove_Closed, Closed(handler));
}

template <typename D> void impl_ICoreWindow<D>::Closed(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreWindow)->remove_Closed(cookie));
}

template <typename D> event_token impl_ICoreWindow<D>::InputEnabled(const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::InputEnabledEventArgs> & handler) const
{
    event_token pCookie {};
    check_hresult(WINRT_SHIM(ICoreWindow)->add_InputEnabled(get_abi(handler), &pCookie));
    return pCookie;
}

template <typename D> event_revoker<ICoreWindow> impl_ICoreWindow<D>::InputEnabled(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::InputEnabledEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreWindow>(this, &ABI::Windows::UI::Core::ICoreWindow::remove_InputEnabled, InputEnabled(handler));
}

template <typename D> void impl_ICoreWindow<D>::InputEnabled(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreWindow)->remove_InputEnabled(cookie));
}

template <typename D> event_token impl_ICoreWindow<D>::KeyDown(const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::KeyEventArgs> & handler) const
{
    event_token pCookie {};
    check_hresult(WINRT_SHIM(ICoreWindow)->add_KeyDown(get_abi(handler), &pCookie));
    return pCookie;
}

template <typename D> event_revoker<ICoreWindow> impl_ICoreWindow<D>::KeyDown(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::KeyEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreWindow>(this, &ABI::Windows::UI::Core::ICoreWindow::remove_KeyDown, KeyDown(handler));
}

template <typename D> void impl_ICoreWindow<D>::KeyDown(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreWindow)->remove_KeyDown(cookie));
}

template <typename D> event_token impl_ICoreWindow<D>::KeyUp(const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::KeyEventArgs> & handler) const
{
    event_token pCookie {};
    check_hresult(WINRT_SHIM(ICoreWindow)->add_KeyUp(get_abi(handler), &pCookie));
    return pCookie;
}

template <typename D> event_revoker<ICoreWindow> impl_ICoreWindow<D>::KeyUp(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::KeyEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreWindow>(this, &ABI::Windows::UI::Core::ICoreWindow::remove_KeyUp, KeyUp(handler));
}

template <typename D> void impl_ICoreWindow<D>::KeyUp(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreWindow)->remove_KeyUp(cookie));
}

template <typename D> event_token impl_ICoreWindow<D>::PointerCaptureLost(const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::PointerEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICoreWindow)->add_PointerCaptureLost(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICoreWindow> impl_ICoreWindow<D>::PointerCaptureLost(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::PointerEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreWindow>(this, &ABI::Windows::UI::Core::ICoreWindow::remove_PointerCaptureLost, PointerCaptureLost(handler));
}

template <typename D> void impl_ICoreWindow<D>::PointerCaptureLost(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreWindow)->remove_PointerCaptureLost(cookie));
}

template <typename D> event_token impl_ICoreWindow<D>::PointerEntered(const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::PointerEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICoreWindow)->add_PointerEntered(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICoreWindow> impl_ICoreWindow<D>::PointerEntered(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::PointerEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreWindow>(this, &ABI::Windows::UI::Core::ICoreWindow::remove_PointerEntered, PointerEntered(handler));
}

template <typename D> void impl_ICoreWindow<D>::PointerEntered(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreWindow)->remove_PointerEntered(cookie));
}

template <typename D> event_token impl_ICoreWindow<D>::PointerExited(const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::PointerEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICoreWindow)->add_PointerExited(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICoreWindow> impl_ICoreWindow<D>::PointerExited(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::PointerEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreWindow>(this, &ABI::Windows::UI::Core::ICoreWindow::remove_PointerExited, PointerExited(handler));
}

template <typename D> void impl_ICoreWindow<D>::PointerExited(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreWindow)->remove_PointerExited(cookie));
}

template <typename D> event_token impl_ICoreWindow<D>::PointerMoved(const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::PointerEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICoreWindow)->add_PointerMoved(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICoreWindow> impl_ICoreWindow<D>::PointerMoved(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::PointerEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreWindow>(this, &ABI::Windows::UI::Core::ICoreWindow::remove_PointerMoved, PointerMoved(handler));
}

template <typename D> void impl_ICoreWindow<D>::PointerMoved(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreWindow)->remove_PointerMoved(cookie));
}

template <typename D> event_token impl_ICoreWindow<D>::PointerPressed(const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::PointerEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICoreWindow)->add_PointerPressed(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICoreWindow> impl_ICoreWindow<D>::PointerPressed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::PointerEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreWindow>(this, &ABI::Windows::UI::Core::ICoreWindow::remove_PointerPressed, PointerPressed(handler));
}

template <typename D> void impl_ICoreWindow<D>::PointerPressed(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreWindow)->remove_PointerPressed(cookie));
}

template <typename D> event_token impl_ICoreWindow<D>::PointerReleased(const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::PointerEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICoreWindow)->add_PointerReleased(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICoreWindow> impl_ICoreWindow<D>::PointerReleased(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::PointerEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreWindow>(this, &ABI::Windows::UI::Core::ICoreWindow::remove_PointerReleased, PointerReleased(handler));
}

template <typename D> void impl_ICoreWindow<D>::PointerReleased(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreWindow)->remove_PointerReleased(cookie));
}

template <typename D> event_token impl_ICoreWindow<D>::TouchHitTesting(const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::TouchHitTestingEventArgs> & handler) const
{
    event_token pCookie {};
    check_hresult(WINRT_SHIM(ICoreWindow)->add_TouchHitTesting(get_abi(handler), &pCookie));
    return pCookie;
}

template <typename D> event_revoker<ICoreWindow> impl_ICoreWindow<D>::TouchHitTesting(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::TouchHitTestingEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreWindow>(this, &ABI::Windows::UI::Core::ICoreWindow::remove_TouchHitTesting, TouchHitTesting(handler));
}

template <typename D> void impl_ICoreWindow<D>::TouchHitTesting(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreWindow)->remove_TouchHitTesting(cookie));
}

template <typename D> event_token impl_ICoreWindow<D>::PointerWheelChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::PointerEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICoreWindow)->add_PointerWheelChanged(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICoreWindow> impl_ICoreWindow<D>::PointerWheelChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::PointerEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreWindow>(this, &ABI::Windows::UI::Core::ICoreWindow::remove_PointerWheelChanged, PointerWheelChanged(handler));
}

template <typename D> void impl_ICoreWindow<D>::PointerWheelChanged(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreWindow)->remove_PointerWheelChanged(cookie));
}

template <typename D> event_token impl_ICoreWindow<D>::SizeChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::WindowSizeChangedEventArgs> & handler) const
{
    event_token pCookie {};
    check_hresult(WINRT_SHIM(ICoreWindow)->add_SizeChanged(get_abi(handler), &pCookie));
    return pCookie;
}

template <typename D> event_revoker<ICoreWindow> impl_ICoreWindow<D>::SizeChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::WindowSizeChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreWindow>(this, &ABI::Windows::UI::Core::ICoreWindow::remove_SizeChanged, SizeChanged(handler));
}

template <typename D> void impl_ICoreWindow<D>::SizeChanged(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreWindow)->remove_SizeChanged(cookie));
}

template <typename D> event_token impl_ICoreWindow<D>::VisibilityChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::VisibilityChangedEventArgs> & handler) const
{
    event_token pCookie {};
    check_hresult(WINRT_SHIM(ICoreWindow)->add_VisibilityChanged(get_abi(handler), &pCookie));
    return pCookie;
}

template <typename D> event_revoker<ICoreWindow> impl_ICoreWindow<D>::VisibilityChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::VisibilityChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreWindow>(this, &ABI::Windows::UI::Core::ICoreWindow::remove_VisibilityChanged, VisibilityChanged(handler));
}

template <typename D> void impl_ICoreWindow<D>::VisibilityChanged(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreWindow)->remove_VisibilityChanged(cookie));
}

template <typename D> void impl_ICoreWindow2<D>::PointerPosition(const Windows::Foundation::Point & value) const
{
    check_hresult(WINRT_SHIM(ICoreWindow2)->put_PointerPosition(get_abi(value)));
}

template <typename D> event_token impl_ICoreWindow3<D>::ClosestInteractiveBoundsRequested(const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::ClosestInteractiveBoundsRequestedEventArgs> & handler) const
{
    event_token pCookie {};
    check_hresult(WINRT_SHIM(ICoreWindow3)->add_ClosestInteractiveBoundsRequested(get_abi(handler), &pCookie));
    return pCookie;
}

template <typename D> event_revoker<ICoreWindow3> impl_ICoreWindow3<D>::ClosestInteractiveBoundsRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::ClosestInteractiveBoundsRequestedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreWindow3>(this, &ABI::Windows::UI::Core::ICoreWindow3::remove_ClosestInteractiveBoundsRequested, ClosestInteractiveBoundsRequested(handler));
}

template <typename D> void impl_ICoreWindow3<D>::ClosestInteractiveBoundsRequested(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreWindow3)->remove_ClosestInteractiveBoundsRequested(cookie));
}

template <typename D> hstring impl_ICoreWindow3<D>::GetCurrentKeyEventDeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICoreWindow3)->abi_GetCurrentKeyEventDeviceId(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Core::CoreWindow impl_ICoreWindowStatic<D>::GetForCurrentThread() const
{
    Windows::UI::Core::CoreWindow ppWindow { nullptr };
    check_hresult(WINRT_SHIM(ICoreWindowStatic)->abi_GetForCurrentThread(put_abi(ppWindow)));
    return ppWindow;
}

template <typename D> Windows::UI::Core::CoreAcceleratorKeyEventType impl_IAcceleratorKeyEventArgs<D>::EventType() const
{
    Windows::UI::Core::CoreAcceleratorKeyEventType value {};
    check_hresult(WINRT_SHIM(IAcceleratorKeyEventArgs)->get_EventType(&value));
    return value;
}

template <typename D> Windows::System::VirtualKey impl_IAcceleratorKeyEventArgs<D>::VirtualKey() const
{
    Windows::System::VirtualKey value {};
    check_hresult(WINRT_SHIM(IAcceleratorKeyEventArgs)->get_VirtualKey(&value));
    return value;
}

template <typename D> Windows::UI::Core::CorePhysicalKeyStatus impl_IAcceleratorKeyEventArgs<D>::KeyStatus() const
{
    Windows::UI::Core::CorePhysicalKeyStatus value {};
    check_hresult(WINRT_SHIM(IAcceleratorKeyEventArgs)->get_KeyStatus(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAcceleratorKeyEventArgs2<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAcceleratorKeyEventArgs2)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> event_token impl_ICoreAcceleratorKeys<D>::AcceleratorKeyActivated(const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreDispatcher, Windows::UI::Core::AcceleratorKeyEventArgs> & handler) const
{
    event_token pCookie {};
    check_hresult(WINRT_SHIM(ICoreAcceleratorKeys)->add_AcceleratorKeyActivated(get_abi(handler), &pCookie));
    return pCookie;
}

template <typename D> event_revoker<ICoreAcceleratorKeys> impl_ICoreAcceleratorKeys<D>::AcceleratorKeyActivated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreDispatcher, Windows::UI::Core::AcceleratorKeyEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreAcceleratorKeys>(this, &ABI::Windows::UI::Core::ICoreAcceleratorKeys::remove_AcceleratorKeyActivated, AcceleratorKeyActivated(handler));
}

template <typename D> void impl_ICoreAcceleratorKeys<D>::AcceleratorKeyActivated(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreAcceleratorKeys)->remove_AcceleratorKeyActivated(cookie));
}

template <typename D> bool impl_ICoreDispatcher<D>::HasThreadAccess() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICoreDispatcher)->get_HasThreadAccess(&value));
    return value;
}

template <typename D> void impl_ICoreDispatcher<D>::ProcessEvents(Windows::UI::Core::CoreProcessEventsOption options) const
{
    check_hresult(WINRT_SHIM(ICoreDispatcher)->abi_ProcessEvents(options));
}

template <typename D> Windows::Foundation::IAsyncAction impl_ICoreDispatcher<D>::RunAsync(Windows::UI::Core::CoreDispatcherPriority priority, const Windows::UI::Core::DispatchedHandler & agileCallback) const
{
    Windows::Foundation::IAsyncAction asyncAction;
    check_hresult(WINRT_SHIM(ICoreDispatcher)->abi_RunAsync(priority, get_abi(agileCallback), put_abi(asyncAction)));
    return asyncAction;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ICoreDispatcher<D>::RunIdleAsync(const Windows::UI::Core::IdleDispatchedHandler & agileCallback) const
{
    Windows::Foundation::IAsyncAction asyncAction;
    check_hresult(WINRT_SHIM(ICoreDispatcher)->abi_RunIdleAsync(get_abi(agileCallback), put_abi(asyncAction)));
    return asyncAction;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ICoreDispatcher2<D>::TryRunAsync(Windows::UI::Core::CoreDispatcherPriority priority, const Windows::UI::Core::DispatchedHandler & agileCallback) const
{
    Windows::Foundation::IAsyncOperation<bool> asyncOperation;
    check_hresult(WINRT_SHIM(ICoreDispatcher2)->abi_TryRunAsync(priority, get_abi(agileCallback), put_abi(asyncOperation)));
    return asyncOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ICoreDispatcher2<D>::TryRunIdleAsync(const Windows::UI::Core::IdleDispatchedHandler & agileCallback) const
{
    Windows::Foundation::IAsyncOperation<bool> asyncOperation;
    check_hresult(WINRT_SHIM(ICoreDispatcher2)->abi_TryRunIdleAsync(get_abi(agileCallback), put_abi(asyncOperation)));
    return asyncOperation;
}

template <typename D> Windows::UI::Core::CoreDispatcherPriority impl_ICoreDispatcherWithTaskPriority<D>::CurrentPriority() const
{
    Windows::UI::Core::CoreDispatcherPriority value {};
    check_hresult(WINRT_SHIM(ICoreDispatcherWithTaskPriority)->get_CurrentPriority(&value));
    return value;
}

template <typename D> void impl_ICoreDispatcherWithTaskPriority<D>::CurrentPriority(Windows::UI::Core::CoreDispatcherPriority value) const
{
    check_hresult(WINRT_SHIM(ICoreDispatcherWithTaskPriority)->put_CurrentPriority(value));
}

template <typename D> bool impl_ICoreDispatcherWithTaskPriority<D>::ShouldYield() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICoreDispatcherWithTaskPriority)->abi_ShouldYield(&value));
    return value;
}

template <typename D> bool impl_ICoreDispatcherWithTaskPriority<D>::ShouldYield(Windows::UI::Core::CoreDispatcherPriority priority) const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICoreDispatcherWithTaskPriority)->abi_ShouldYieldToPriority(priority, &value));
    return value;
}

template <typename D> void impl_ICoreDispatcherWithTaskPriority<D>::StopProcessEvents() const
{
    check_hresult(WINRT_SHIM(ICoreDispatcherWithTaskPriority)->abi_StopProcessEvents());
}

template <typename D> bool impl_IIdleDispatchedHandlerArgs<D>::IsDispatcherIdle() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IIdleDispatchedHandlerArgs)->get_IsDispatcherIdle(&value));
    return value;
}

template <typename D> uint32_t impl_ICoreCursor<D>::Id() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ICoreCursor)->get_Id(&value));
    return value;
}

template <typename D> Windows::UI::Core::CoreCursorType impl_ICoreCursor<D>::Type() const
{
    Windows::UI::Core::CoreCursorType value {};
    check_hresult(WINRT_SHIM(ICoreCursor)->get_Type(&value));
    return value;
}

template <typename D> Windows::UI::Core::CoreCursor impl_ICoreCursorFactory<D>::CreateCursor(Windows::UI::Core::CoreCursorType type, uint32_t id) const
{
    Windows::UI::Core::CoreCursor cursor { nullptr };
    check_hresult(WINRT_SHIM(ICoreCursorFactory)->abi_CreateCursor(type, id, put_abi(cursor)));
    return cursor;
}

template <typename D> void impl_IInitializeWithCoreWindow<D>::Initialize(const Windows::UI::Core::CoreWindow & window) const
{
    check_hresult(WINRT_SHIM(IInitializeWithCoreWindow)->abi_Initialize(get_abi(window)));
}

template <typename D> void impl_ICoreWindowResizeManager<D>::NotifyLayoutCompleted() const
{
    check_hresult(WINRT_SHIM(ICoreWindowResizeManager)->abi_NotifyLayoutCompleted());
}

template <typename D> void impl_ICoreWindowResizeManagerLayoutCapability<D>::ShouldWaitForLayoutCompletion(bool value) const
{
    check_hresult(WINRT_SHIM(ICoreWindowResizeManagerLayoutCapability)->put_ShouldWaitForLayoutCompletion(value));
}

template <typename D> bool impl_ICoreWindowResizeManagerLayoutCapability<D>::ShouldWaitForLayoutCompletion() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICoreWindowResizeManagerLayoutCapability)->get_ShouldWaitForLayoutCompletion(&value));
    return value;
}

template <typename D> Windows::UI::Core::CoreWindowResizeManager impl_ICoreWindowResizeManagerStatics<D>::GetForCurrentView() const
{
    Windows::UI::Core::CoreWindowResizeManager CoreWindowResizeManager { nullptr };
    check_hresult(WINRT_SHIM(ICoreWindowResizeManagerStatics)->abi_GetForCurrentView(put_abi(CoreWindowResizeManager)));
    return CoreWindowResizeManager;
}

template <typename D> Windows::UI::Core::CoreDispatcher impl_ICoreInputSourceBase<D>::Dispatcher() const
{
    Windows::UI::Core::CoreDispatcher value { nullptr };
    check_hresult(WINRT_SHIM(ICoreInputSourceBase)->get_Dispatcher(put_abi(value)));
    return value;
}

template <typename D> bool impl_ICoreInputSourceBase<D>::IsInputEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICoreInputSourceBase)->get_IsInputEnabled(&value));
    return value;
}

template <typename D> void impl_ICoreInputSourceBase<D>::IsInputEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(ICoreInputSourceBase)->put_IsInputEnabled(value));
}

template <typename D> event_token impl_ICoreInputSourceBase<D>::InputEnabled(const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::InputEnabledEventArgs> & handler) const
{
    event_token pCookie {};
    check_hresult(WINRT_SHIM(ICoreInputSourceBase)->add_InputEnabled(get_abi(handler), &pCookie));
    return pCookie;
}

template <typename D> event_revoker<ICoreInputSourceBase> impl_ICoreInputSourceBase<D>::InputEnabled(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::InputEnabledEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreInputSourceBase>(this, &ABI::Windows::UI::Core::ICoreInputSourceBase::remove_InputEnabled, InputEnabled(handler));
}

template <typename D> void impl_ICoreInputSourceBase<D>::InputEnabled(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreInputSourceBase)->remove_InputEnabled(cookie));
}

template <typename D> void impl_ICorePointerInputSource<D>::ReleasePointerCapture() const
{
    check_hresult(WINRT_SHIM(ICorePointerInputSource)->abi_ReleasePointerCapture());
}

template <typename D> void impl_ICorePointerInputSource<D>::SetPointerCapture() const
{
    check_hresult(WINRT_SHIM(ICorePointerInputSource)->abi_SetPointerCapture());
}

template <typename D> bool impl_ICorePointerInputSource<D>::HasCapture() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICorePointerInputSource)->get_HasCapture(&value));
    return value;
}

template <typename D> Windows::Foundation::Point impl_ICorePointerInputSource<D>::PointerPosition() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(ICorePointerInputSource)->get_PointerPosition(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Core::CoreCursor impl_ICorePointerInputSource<D>::PointerCursor() const
{
    Windows::UI::Core::CoreCursor value { nullptr };
    check_hresult(WINRT_SHIM(ICorePointerInputSource)->get_PointerCursor(put_abi(value)));
    return value;
}

template <typename D> void impl_ICorePointerInputSource<D>::PointerCursor(const Windows::UI::Core::CoreCursor & value) const
{
    check_hresult(WINRT_SHIM(ICorePointerInputSource)->put_PointerCursor(get_abi(value)));
}

template <typename D> event_token impl_ICorePointerInputSource<D>::PointerCaptureLost(const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::PointerEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICorePointerInputSource)->add_PointerCaptureLost(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICorePointerInputSource> impl_ICorePointerInputSource<D>::PointerCaptureLost(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::PointerEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICorePointerInputSource>(this, &ABI::Windows::UI::Core::ICorePointerInputSource::remove_PointerCaptureLost, PointerCaptureLost(handler));
}

template <typename D> void impl_ICorePointerInputSource<D>::PointerCaptureLost(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICorePointerInputSource)->remove_PointerCaptureLost(cookie));
}

template <typename D> event_token impl_ICorePointerInputSource<D>::PointerEntered(const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::PointerEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICorePointerInputSource)->add_PointerEntered(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICorePointerInputSource> impl_ICorePointerInputSource<D>::PointerEntered(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::PointerEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICorePointerInputSource>(this, &ABI::Windows::UI::Core::ICorePointerInputSource::remove_PointerEntered, PointerEntered(handler));
}

template <typename D> void impl_ICorePointerInputSource<D>::PointerEntered(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICorePointerInputSource)->remove_PointerEntered(cookie));
}

template <typename D> event_token impl_ICorePointerInputSource<D>::PointerExited(const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::PointerEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICorePointerInputSource)->add_PointerExited(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICorePointerInputSource> impl_ICorePointerInputSource<D>::PointerExited(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::PointerEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICorePointerInputSource>(this, &ABI::Windows::UI::Core::ICorePointerInputSource::remove_PointerExited, PointerExited(handler));
}

template <typename D> void impl_ICorePointerInputSource<D>::PointerExited(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICorePointerInputSource)->remove_PointerExited(cookie));
}

template <typename D> event_token impl_ICorePointerInputSource<D>::PointerMoved(const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::PointerEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICorePointerInputSource)->add_PointerMoved(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICorePointerInputSource> impl_ICorePointerInputSource<D>::PointerMoved(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::PointerEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICorePointerInputSource>(this, &ABI::Windows::UI::Core::ICorePointerInputSource::remove_PointerMoved, PointerMoved(handler));
}

template <typename D> void impl_ICorePointerInputSource<D>::PointerMoved(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICorePointerInputSource)->remove_PointerMoved(cookie));
}

template <typename D> event_token impl_ICorePointerInputSource<D>::PointerPressed(const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::PointerEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICorePointerInputSource)->add_PointerPressed(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICorePointerInputSource> impl_ICorePointerInputSource<D>::PointerPressed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::PointerEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICorePointerInputSource>(this, &ABI::Windows::UI::Core::ICorePointerInputSource::remove_PointerPressed, PointerPressed(handler));
}

template <typename D> void impl_ICorePointerInputSource<D>::PointerPressed(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICorePointerInputSource)->remove_PointerPressed(cookie));
}

template <typename D> event_token impl_ICorePointerInputSource<D>::PointerReleased(const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::PointerEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICorePointerInputSource)->add_PointerReleased(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICorePointerInputSource> impl_ICorePointerInputSource<D>::PointerReleased(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::PointerEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICorePointerInputSource>(this, &ABI::Windows::UI::Core::ICorePointerInputSource::remove_PointerReleased, PointerReleased(handler));
}

template <typename D> void impl_ICorePointerInputSource<D>::PointerReleased(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICorePointerInputSource)->remove_PointerReleased(cookie));
}

template <typename D> event_token impl_ICorePointerInputSource<D>::PointerWheelChanged(const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::PointerEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICorePointerInputSource)->add_PointerWheelChanged(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICorePointerInputSource> impl_ICorePointerInputSource<D>::PointerWheelChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::PointerEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICorePointerInputSource>(this, &ABI::Windows::UI::Core::ICorePointerInputSource::remove_PointerWheelChanged, PointerWheelChanged(handler));
}

template <typename D> void impl_ICorePointerInputSource<D>::PointerWheelChanged(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICorePointerInputSource)->remove_PointerWheelChanged(cookie));
}

template <typename D> Windows::UI::Core::CoreVirtualKeyStates impl_ICoreKeyboardInputSource<D>::GetCurrentKeyState(Windows::System::VirtualKey virtualKey) const
{
    Windows::UI::Core::CoreVirtualKeyStates KeyState {};
    check_hresult(WINRT_SHIM(ICoreKeyboardInputSource)->abi_GetCurrentKeyState(virtualKey, &KeyState));
    return KeyState;
}

template <typename D> event_token impl_ICoreKeyboardInputSource<D>::CharacterReceived(const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::CharacterReceivedEventArgs> & handler) const
{
    event_token pCookie {};
    check_hresult(WINRT_SHIM(ICoreKeyboardInputSource)->add_CharacterReceived(get_abi(handler), &pCookie));
    return pCookie;
}

template <typename D> event_revoker<ICoreKeyboardInputSource> impl_ICoreKeyboardInputSource<D>::CharacterReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::CharacterReceivedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreKeyboardInputSource>(this, &ABI::Windows::UI::Core::ICoreKeyboardInputSource::remove_CharacterReceived, CharacterReceived(handler));
}

template <typename D> void impl_ICoreKeyboardInputSource<D>::CharacterReceived(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreKeyboardInputSource)->remove_CharacterReceived(cookie));
}

template <typename D> event_token impl_ICoreKeyboardInputSource<D>::KeyDown(const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::KeyEventArgs> & handler) const
{
    event_token pCookie {};
    check_hresult(WINRT_SHIM(ICoreKeyboardInputSource)->add_KeyDown(get_abi(handler), &pCookie));
    return pCookie;
}

template <typename D> event_revoker<ICoreKeyboardInputSource> impl_ICoreKeyboardInputSource<D>::KeyDown(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::KeyEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreKeyboardInputSource>(this, &ABI::Windows::UI::Core::ICoreKeyboardInputSource::remove_KeyDown, KeyDown(handler));
}

template <typename D> void impl_ICoreKeyboardInputSource<D>::KeyDown(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreKeyboardInputSource)->remove_KeyDown(cookie));
}

template <typename D> event_token impl_ICoreKeyboardInputSource<D>::KeyUp(const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::KeyEventArgs> & handler) const
{
    event_token pCookie {};
    check_hresult(WINRT_SHIM(ICoreKeyboardInputSource)->add_KeyUp(get_abi(handler), &pCookie));
    return pCookie;
}

template <typename D> event_revoker<ICoreKeyboardInputSource> impl_ICoreKeyboardInputSource<D>::KeyUp(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::KeyEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreKeyboardInputSource>(this, &ABI::Windows::UI::Core::ICoreKeyboardInputSource::remove_KeyUp, KeyUp(handler));
}

template <typename D> void impl_ICoreKeyboardInputSource<D>::KeyUp(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreKeyboardInputSource)->remove_KeyUp(cookie));
}

template <typename D> hstring impl_ICoreKeyboardInputSource2<D>::GetCurrentKeyEventDeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICoreKeyboardInputSource2)->abi_GetCurrentKeyEventDeviceId(put_abi(value)));
    return value;
}

template <typename D> bool impl_ICoreComponentFocusable<D>::HasFocus() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICoreComponentFocusable)->get_HasFocus(&value));
    return value;
}

template <typename D> event_token impl_ICoreComponentFocusable<D>::GotFocus(const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::CoreWindowEventArgs> & handler) const
{
    event_token pCookie {};
    check_hresult(WINRT_SHIM(ICoreComponentFocusable)->add_GotFocus(get_abi(handler), &pCookie));
    return pCookie;
}

template <typename D> event_revoker<ICoreComponentFocusable> impl_ICoreComponentFocusable<D>::GotFocus(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::CoreWindowEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreComponentFocusable>(this, &ABI::Windows::UI::Core::ICoreComponentFocusable::remove_GotFocus, GotFocus(handler));
}

template <typename D> void impl_ICoreComponentFocusable<D>::GotFocus(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreComponentFocusable)->remove_GotFocus(cookie));
}

template <typename D> event_token impl_ICoreComponentFocusable<D>::LostFocus(const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::CoreWindowEventArgs> & handler) const
{
    event_token pCookie {};
    check_hresult(WINRT_SHIM(ICoreComponentFocusable)->add_LostFocus(get_abi(handler), &pCookie));
    return pCookie;
}

template <typename D> event_revoker<ICoreComponentFocusable> impl_ICoreComponentFocusable<D>::LostFocus(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::CoreWindowEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreComponentFocusable>(this, &ABI::Windows::UI::Core::ICoreComponentFocusable::remove_LostFocus, LostFocus(handler));
}

template <typename D> void impl_ICoreComponentFocusable<D>::LostFocus(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreComponentFocusable)->remove_LostFocus(cookie));
}

template <typename D> event_token impl_ICoreTouchHitTesting<D>::TouchHitTesting(const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::TouchHitTestingEventArgs> & handler) const
{
    event_token pCookie {};
    check_hresult(WINRT_SHIM(ICoreTouchHitTesting)->add_TouchHitTesting(get_abi(handler), &pCookie));
    return pCookie;
}

template <typename D> event_revoker<ICoreTouchHitTesting> impl_ICoreTouchHitTesting<D>::TouchHitTesting(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::UI::Core::TouchHitTestingEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreTouchHitTesting>(this, &ABI::Windows::UI::Core::ICoreTouchHitTesting::remove_TouchHitTesting, TouchHitTesting(handler));
}

template <typename D> void impl_ICoreTouchHitTesting<D>::TouchHitTesting(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreTouchHitTesting)->remove_TouchHitTesting(cookie));
}

template <typename D> event_token impl_ICoreClosestInteractiveBoundsRequested<D>::ClosestInteractiveBoundsRequested(const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreComponentInputSource, Windows::UI::Core::ClosestInteractiveBoundsRequestedEventArgs> & handler) const
{
    event_token pCookie {};
    check_hresult(WINRT_SHIM(ICoreClosestInteractiveBoundsRequested)->add_ClosestInteractiveBoundsRequested(get_abi(handler), &pCookie));
    return pCookie;
}

template <typename D> event_revoker<ICoreClosestInteractiveBoundsRequested> impl_ICoreClosestInteractiveBoundsRequested<D>::ClosestInteractiveBoundsRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreComponentInputSource, Windows::UI::Core::ClosestInteractiveBoundsRequestedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreClosestInteractiveBoundsRequested>(this, &ABI::Windows::UI::Core::ICoreClosestInteractiveBoundsRequested::remove_ClosestInteractiveBoundsRequested, ClosestInteractiveBoundsRequested(handler));
}

template <typename D> void impl_ICoreClosestInteractiveBoundsRequested<D>::ClosestInteractiveBoundsRequested(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreClosestInteractiveBoundsRequested)->remove_ClosestInteractiveBoundsRequested(cookie));
}

template <typename D> event_token impl_ICorePointerRedirector<D>::PointerRoutedAway(const Windows::Foundation::TypedEventHandler<Windows::UI::Core::ICorePointerRedirector, Windows::UI::Core::PointerEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICorePointerRedirector)->add_PointerRoutedAway(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICorePointerRedirector> impl_ICorePointerRedirector<D>::PointerRoutedAway(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Core::ICorePointerRedirector, Windows::UI::Core::PointerEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICorePointerRedirector>(this, &ABI::Windows::UI::Core::ICorePointerRedirector::remove_PointerRoutedAway, PointerRoutedAway(handler));
}

template <typename D> void impl_ICorePointerRedirector<D>::PointerRoutedAway(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICorePointerRedirector)->remove_PointerRoutedAway(cookie));
}

template <typename D> event_token impl_ICorePointerRedirector<D>::PointerRoutedTo(const Windows::Foundation::TypedEventHandler<Windows::UI::Core::ICorePointerRedirector, Windows::UI::Core::PointerEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICorePointerRedirector)->add_PointerRoutedTo(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICorePointerRedirector> impl_ICorePointerRedirector<D>::PointerRoutedTo(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Core::ICorePointerRedirector, Windows::UI::Core::PointerEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICorePointerRedirector>(this, &ABI::Windows::UI::Core::ICorePointerRedirector::remove_PointerRoutedTo, PointerRoutedTo(handler));
}

template <typename D> void impl_ICorePointerRedirector<D>::PointerRoutedTo(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICorePointerRedirector)->remove_PointerRoutedTo(cookie));
}

template <typename D> event_token impl_ICorePointerRedirector<D>::PointerRoutedReleased(const Windows::Foundation::TypedEventHandler<Windows::UI::Core::ICorePointerRedirector, Windows::UI::Core::PointerEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICorePointerRedirector)->add_PointerRoutedReleased(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICorePointerRedirector> impl_ICorePointerRedirector<D>::PointerRoutedReleased(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Core::ICorePointerRedirector, Windows::UI::Core::PointerEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICorePointerRedirector>(this, &ABI::Windows::UI::Core::ICorePointerRedirector::remove_PointerRoutedReleased, PointerRoutedReleased(handler));
}

template <typename D> void impl_ICorePointerRedirector<D>::PointerRoutedReleased(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICorePointerRedirector)->remove_PointerRoutedReleased(cookie));
}

template <typename D> event_token impl_ISystemNavigationManager<D>::BackRequested(const Windows::Foundation::EventHandler<Windows::UI::Core::BackRequestedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ISystemNavigationManager)->add_BackRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ISystemNavigationManager> impl_ISystemNavigationManager<D>::BackRequested(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::UI::Core::BackRequestedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ISystemNavigationManager>(this, &ABI::Windows::UI::Core::ISystemNavigationManager::remove_BackRequested, BackRequested(handler));
}

template <typename D> void impl_ISystemNavigationManager<D>::BackRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(ISystemNavigationManager)->remove_BackRequested(token));
}

template <typename D> Windows::UI::Core::AppViewBackButtonVisibility impl_ISystemNavigationManager2<D>::AppViewBackButtonVisibility() const
{
    Windows::UI::Core::AppViewBackButtonVisibility value {};
    check_hresult(WINRT_SHIM(ISystemNavigationManager2)->get_AppViewBackButtonVisibility(&value));
    return value;
}

template <typename D> void impl_ISystemNavigationManager2<D>::AppViewBackButtonVisibility(Windows::UI::Core::AppViewBackButtonVisibility value) const
{
    check_hresult(WINRT_SHIM(ISystemNavigationManager2)->put_AppViewBackButtonVisibility(value));
}

template <typename D> Windows::UI::Core::SystemNavigationManager impl_ISystemNavigationManagerStatics<D>::GetForCurrentView() const
{
    Windows::UI::Core::SystemNavigationManager loader { nullptr };
    check_hresult(WINRT_SHIM(ISystemNavigationManagerStatics)->abi_GetForCurrentView(put_abi(loader)));
    return loader;
}

template <typename D> bool impl_IBackRequestedEventArgs<D>::Handled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IBackRequestedEventArgs)->get_Handled(&value));
    return value;
}

template <typename D> void impl_IBackRequestedEventArgs<D>::Handled(bool value) const
{
    check_hresult(WINRT_SHIM(IBackRequestedEventArgs)->put_Handled(value));
}

template <typename D> void impl_ICoreWindowPopupShowingEventArgs<D>::SetDesiredSize(const Windows::Foundation::Size & value) const
{
    check_hresult(WINRT_SHIM(ICoreWindowPopupShowingEventArgs)->abi_SetDesiredSize(get_abi(value)));
}

template <typename D> event_token impl_ICoreWindowDialog<D>::Showing(const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::CoreWindowPopupShowingEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICoreWindowDialog)->add_Showing(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICoreWindowDialog> impl_ICoreWindowDialog<D>::Showing(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::CoreWindowPopupShowingEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreWindowDialog>(this, &ABI::Windows::UI::Core::ICoreWindowDialog::remove_Showing, Showing(handler));
}

template <typename D> void impl_ICoreWindowDialog<D>::Showing(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreWindowDialog)->remove_Showing(cookie));
}

template <typename D> Windows::Foundation::Size impl_ICoreWindowDialog<D>::MaxSize() const
{
    Windows::Foundation::Size value {};
    check_hresult(WINRT_SHIM(ICoreWindowDialog)->get_MaxSize(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Size impl_ICoreWindowDialog<D>::MinSize() const
{
    Windows::Foundation::Size value {};
    check_hresult(WINRT_SHIM(ICoreWindowDialog)->get_MinSize(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICoreWindowDialog<D>::Title() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICoreWindowDialog)->get_Title(put_abi(value)));
    return value;
}

template <typename D> void impl_ICoreWindowDialog<D>::Title(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ICoreWindowDialog)->put_Title(get_abi(value)));
}

template <typename D> int32_t impl_ICoreWindowDialog<D>::IsInteractionDelayed() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICoreWindowDialog)->get_IsInteractionDelayed(&value));
    return value;
}

template <typename D> void impl_ICoreWindowDialog<D>::IsInteractionDelayed(int32_t value) const
{
    check_hresult(WINRT_SHIM(ICoreWindowDialog)->put_IsInteractionDelayed(value));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::UI::Popups::IUICommand> impl_ICoreWindowDialog<D>::Commands() const
{
    Windows::Foundation::Collections::IVector<Windows::UI::Popups::IUICommand> value;
    check_hresult(WINRT_SHIM(ICoreWindowDialog)->get_Commands(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_ICoreWindowDialog<D>::DefaultCommandIndex() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ICoreWindowDialog)->get_DefaultCommandIndex(&value));
    return value;
}

template <typename D> void impl_ICoreWindowDialog<D>::DefaultCommandIndex(uint32_t value) const
{
    check_hresult(WINRT_SHIM(ICoreWindowDialog)->put_DefaultCommandIndex(value));
}

template <typename D> uint32_t impl_ICoreWindowDialog<D>::CancelCommandIndex() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ICoreWindowDialog)->get_CancelCommandIndex(&value));
    return value;
}

template <typename D> void impl_ICoreWindowDialog<D>::CancelCommandIndex(uint32_t value) const
{
    check_hresult(WINRT_SHIM(ICoreWindowDialog)->put_CancelCommandIndex(value));
}

template <typename D> Windows::UI::Popups::UICommandInvokedHandler impl_ICoreWindowDialog<D>::BackButtonCommand() const
{
    Windows::UI::Popups::UICommandInvokedHandler value {};
    check_hresult(WINRT_SHIM(ICoreWindowDialog)->get_BackButtonCommand(put_abi(value)));
    return value;
}

template <typename D> void impl_ICoreWindowDialog<D>::BackButtonCommand(const Windows::UI::Popups::UICommandInvokedHandler & value) const
{
    check_hresult(WINRT_SHIM(ICoreWindowDialog)->put_BackButtonCommand(get_abi(value)));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::UI::Popups::IUICommand> impl_ICoreWindowDialog<D>::ShowAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::UI::Popups::IUICommand> asyncInfo;
    check_hresult(WINRT_SHIM(ICoreWindowDialog)->abi_ShowAsync(put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::UI::Core::CoreWindowDialog impl_ICoreWindowDialogFactory<D>::CreateWithTitle(hstring_view title) const
{
    Windows::UI::Core::CoreWindowDialog coreWindowDialog { nullptr };
    check_hresult(WINRT_SHIM(ICoreWindowDialogFactory)->abi_CreateWithTitle(get_abi(title), put_abi(coreWindowDialog)));
    return coreWindowDialog;
}

template <typename D> event_token impl_ICoreWindowFlyout<D>::Showing(const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::CoreWindowPopupShowingEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ICoreWindowFlyout)->add_Showing(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ICoreWindowFlyout> impl_ICoreWindowFlyout<D>::Showing(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Core::CoreWindow, Windows::UI::Core::CoreWindowPopupShowingEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreWindowFlyout>(this, &ABI::Windows::UI::Core::ICoreWindowFlyout::remove_Showing, Showing(handler));
}

template <typename D> void impl_ICoreWindowFlyout<D>::Showing(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ICoreWindowFlyout)->remove_Showing(cookie));
}

template <typename D> Windows::Foundation::Size impl_ICoreWindowFlyout<D>::MaxSize() const
{
    Windows::Foundation::Size value {};
    check_hresult(WINRT_SHIM(ICoreWindowFlyout)->get_MaxSize(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Size impl_ICoreWindowFlyout<D>::MinSize() const
{
    Windows::Foundation::Size value {};
    check_hresult(WINRT_SHIM(ICoreWindowFlyout)->get_MinSize(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ICoreWindowFlyout<D>::Title() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICoreWindowFlyout)->get_Title(put_abi(value)));
    return value;
}

template <typename D> void impl_ICoreWindowFlyout<D>::Title(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ICoreWindowFlyout)->put_Title(get_abi(value)));
}

template <typename D> int32_t impl_ICoreWindowFlyout<D>::IsInteractionDelayed() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ICoreWindowFlyout)->get_IsInteractionDelayed(&value));
    return value;
}

template <typename D> void impl_ICoreWindowFlyout<D>::IsInteractionDelayed(int32_t value) const
{
    check_hresult(WINRT_SHIM(ICoreWindowFlyout)->put_IsInteractionDelayed(value));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::UI::Popups::IUICommand> impl_ICoreWindowFlyout<D>::Commands() const
{
    Windows::Foundation::Collections::IVector<Windows::UI::Popups::IUICommand> value;
    check_hresult(WINRT_SHIM(ICoreWindowFlyout)->get_Commands(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_ICoreWindowFlyout<D>::DefaultCommandIndex() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ICoreWindowFlyout)->get_DefaultCommandIndex(&value));
    return value;
}

template <typename D> void impl_ICoreWindowFlyout<D>::DefaultCommandIndex(uint32_t value) const
{
    check_hresult(WINRT_SHIM(ICoreWindowFlyout)->put_DefaultCommandIndex(value));
}

template <typename D> Windows::UI::Popups::UICommandInvokedHandler impl_ICoreWindowFlyout<D>::BackButtonCommand() const
{
    Windows::UI::Popups::UICommandInvokedHandler value {};
    check_hresult(WINRT_SHIM(ICoreWindowFlyout)->get_BackButtonCommand(put_abi(value)));
    return value;
}

template <typename D> void impl_ICoreWindowFlyout<D>::BackButtonCommand(const Windows::UI::Popups::UICommandInvokedHandler & value) const
{
    check_hresult(WINRT_SHIM(ICoreWindowFlyout)->put_BackButtonCommand(get_abi(value)));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::UI::Popups::IUICommand> impl_ICoreWindowFlyout<D>::ShowAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::UI::Popups::IUICommand> asyncInfo;
    check_hresult(WINRT_SHIM(ICoreWindowFlyout)->abi_ShowAsync(put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::UI::Core::CoreWindowFlyout impl_ICoreWindowFlyoutFactory<D>::Create(const Windows::Foundation::Point & position) const
{
    Windows::UI::Core::CoreWindowFlyout coreWindowFlyout { nullptr };
    check_hresult(WINRT_SHIM(ICoreWindowFlyoutFactory)->abi_Create(get_abi(position), put_abi(coreWindowFlyout)));
    return coreWindowFlyout;
}

template <typename D> Windows::UI::Core::CoreWindowFlyout impl_ICoreWindowFlyoutFactory<D>::CreateWithTitle(const Windows::Foundation::Point & position, hstring_view title) const
{
    Windows::UI::Core::CoreWindowFlyout coreWindowFlyout { nullptr };
    check_hresult(WINRT_SHIM(ICoreWindowFlyoutFactory)->abi_CreateWithTitle(get_abi(position), get_abi(title), put_abi(coreWindowFlyout)));
    return coreWindowFlyout;
}

inline CoreCursor::CoreCursor(Windows::UI::Core::CoreCursorType type, uint32_t id) :
    CoreCursor(get_activation_factory<CoreCursor, ICoreCursorFactory>().CreateCursor(type, id))
{}

inline Windows::UI::Core::CoreWindow CoreWindow::GetForCurrentThread()
{
    return get_activation_factory<CoreWindow, ICoreWindowStatic>().GetForCurrentThread();
}

inline CoreWindowDialog::CoreWindowDialog() :
    CoreWindowDialog(activate_instance<CoreWindowDialog>())
{}

inline CoreWindowDialog::CoreWindowDialog(hstring_view title) :
    CoreWindowDialog(get_activation_factory<CoreWindowDialog, ICoreWindowDialogFactory>().CreateWithTitle(title))
{}

inline CoreWindowFlyout::CoreWindowFlyout(const Windows::Foundation::Point & position) :
    CoreWindowFlyout(get_activation_factory<CoreWindowFlyout, ICoreWindowFlyoutFactory>().Create(position))
{}

inline CoreWindowFlyout::CoreWindowFlyout(const Windows::Foundation::Point & position, hstring_view title) :
    CoreWindowFlyout(get_activation_factory<CoreWindowFlyout, ICoreWindowFlyoutFactory>().CreateWithTitle(position, title))
{}

inline Windows::UI::Core::CoreWindowResizeManager CoreWindowResizeManager::GetForCurrentView()
{
    return get_activation_factory<CoreWindowResizeManager, ICoreWindowResizeManagerStatics>().GetForCurrentView();
}

inline Windows::UI::Core::SystemNavigationManager SystemNavigationManager::GetForCurrentView()
{
    return get_activation_factory<SystemNavigationManager, ISystemNavigationManagerStatics>().GetForCurrentView();
}

}

}
#pragma warning(pop)
