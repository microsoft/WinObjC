// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Core.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Core {

template <typename H> struct impl_DispatchedHandler : implements<impl_DispatchedHandler<H>, abi<DispatchedHandler>>, H
{
    impl_DispatchedHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke() noexcept override
    {
        try
        {
            (*this)();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_IdleDispatchedHandler : implements<impl_IdleDispatchedHandler<H>, abi<IdleDispatchedHandler>>, H
{
    impl_IdleDispatchedHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::UI::Core::IIdleDispatchedHandlerArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::UI::Core::IdleDispatchedHandlerArgs *>(&e));
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

struct WINRT_EBO AcceleratorKeyEventArgs :
    Windows::UI::Core::IAcceleratorKeyEventArgs,
    impl::require<AcceleratorKeyEventArgs, Windows::UI::Core::IAcceleratorKeyEventArgs2>
{
    AcceleratorKeyEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AutomationProviderRequestedEventArgs :
    Windows::UI::Core::IAutomationProviderRequestedEventArgs
{
    AutomationProviderRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO BackRequestedEventArgs :
    Windows::UI::Core::IBackRequestedEventArgs
{
    BackRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CharacterReceivedEventArgs :
    Windows::UI::Core::ICharacterReceivedEventArgs
{
    CharacterReceivedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ClosestInteractiveBoundsRequestedEventArgs :
    Windows::UI::Core::IClosestInteractiveBoundsRequestedEventArgs
{
    ClosestInteractiveBoundsRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CoreAcceleratorKeys :
    Windows::UI::Core::ICoreAcceleratorKeys
{
    CoreAcceleratorKeys(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CoreComponentInputSource :
    Windows::UI::Core::ICoreInputSourceBase,
    impl::require<CoreComponentInputSource, Windows::UI::Core::ICorePointerInputSource, Windows::UI::Core::ICoreKeyboardInputSource, Windows::UI::Core::ICoreKeyboardInputSource2, Windows::UI::Core::ICoreComponentFocusable, Windows::UI::Core::ICoreTouchHitTesting, Windows::UI::Core::ICoreClosestInteractiveBoundsRequested>
{
    CoreComponentInputSource(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CoreCursor :
    Windows::UI::Core::ICoreCursor
{
    CoreCursor(std::nullptr_t) noexcept {}
    CoreCursor(Windows::UI::Core::CoreCursorType type, uint32_t id);
};

struct WINRT_EBO CoreDispatcher :
    Windows::UI::Core::ICoreDispatcher,
    impl::require<CoreDispatcher, Windows::UI::Core::ICoreDispatcher2, Windows::UI::Core::ICoreDispatcherWithTaskPriority>
{
    CoreDispatcher(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CoreIndependentInputSource :
    Windows::UI::Core::ICoreInputSourceBase,
    impl::require<CoreIndependentInputSource, Windows::UI::Core::ICorePointerInputSource>
{
    CoreIndependentInputSource(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CoreWindow :
    Windows::UI::Core::ICoreWindow,
    impl::require<CoreWindow, Windows::UI::Core::ICoreWindow2, Windows::UI::Core::ICoreWindow3, Windows::UI::Core::ICorePointerRedirector>
{
    CoreWindow(std::nullptr_t) noexcept {}
    using impl_ICoreWindow::PointerPosition;
    using impl_ICoreWindow2::PointerPosition;
    static Windows::UI::Core::CoreWindow GetForCurrentThread();
};

struct WINRT_EBO CoreWindowDialog :
    Windows::UI::Core::ICoreWindowDialog
{
    CoreWindowDialog(std::nullptr_t) noexcept {}
    CoreWindowDialog();
    CoreWindowDialog(hstring_view title);
};

struct WINRT_EBO CoreWindowEventArgs :
    Windows::UI::Core::ICoreWindowEventArgs
{
    CoreWindowEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CoreWindowFlyout :
    Windows::UI::Core::ICoreWindowFlyout
{
    CoreWindowFlyout(std::nullptr_t) noexcept {}
    CoreWindowFlyout(const Windows::Foundation::Point & position);
    CoreWindowFlyout(const Windows::Foundation::Point & position, hstring_view title);
};

struct WINRT_EBO CoreWindowPopupShowingEventArgs :
    Windows::UI::Core::ICoreWindowPopupShowingEventArgs
{
    CoreWindowPopupShowingEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CoreWindowResizeManager :
    Windows::UI::Core::ICoreWindowResizeManager,
    impl::require<CoreWindowResizeManager, Windows::UI::Core::ICoreWindowResizeManagerLayoutCapability>
{
    CoreWindowResizeManager(std::nullptr_t) noexcept {}
    static Windows::UI::Core::CoreWindowResizeManager GetForCurrentView();
};

struct WINRT_EBO IdleDispatchedHandlerArgs :
    Windows::UI::Core::IIdleDispatchedHandlerArgs
{
    IdleDispatchedHandlerArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO InputEnabledEventArgs :
    Windows::UI::Core::IInputEnabledEventArgs
{
    InputEnabledEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO KeyEventArgs :
    Windows::UI::Core::IKeyEventArgs,
    impl::require<KeyEventArgs, Windows::UI::Core::IKeyEventArgs2>
{
    KeyEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PointerEventArgs :
    Windows::UI::Core::IPointerEventArgs
{
    PointerEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SystemNavigationManager :
    Windows::UI::Core::ISystemNavigationManager,
    impl::require<SystemNavigationManager, Windows::UI::Core::ISystemNavigationManager2>
{
    SystemNavigationManager(std::nullptr_t) noexcept {}
    static Windows::UI::Core::SystemNavigationManager GetForCurrentView();
};

struct WINRT_EBO TouchHitTestingEventArgs :
    Windows::UI::Core::ITouchHitTestingEventArgs
{
    TouchHitTestingEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO VisibilityChangedEventArgs :
    Windows::UI::Core::IVisibilityChangedEventArgs
{
    VisibilityChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WindowActivatedEventArgs :
    Windows::UI::Core::IWindowActivatedEventArgs
{
    WindowActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WindowSizeChangedEventArgs :
    Windows::UI::Core::IWindowSizeChangedEventArgs
{
    WindowSizeChangedEventArgs(std::nullptr_t) noexcept {}
};

}

}
