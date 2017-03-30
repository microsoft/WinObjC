// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Input.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Input {

template <typename H> struct impl_DoubleTappedEventHandler : implements<impl_DoubleTappedEventHandler<H>, abi<DoubleTappedEventHandler>>, H
{
    impl_DoubleTappedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Input::IDoubleTappedRoutedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Input::DoubleTappedRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_HoldingEventHandler : implements<impl_HoldingEventHandler<H>, abi<HoldingEventHandler>>, H
{
    impl_HoldingEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Input::IHoldingRoutedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Input::HoldingRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_KeyEventHandler : implements<impl_KeyEventHandler<H>, abi<KeyEventHandler>>, H
{
    impl_KeyEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Input::IKeyRoutedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Input::KeyRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_ManipulationCompletedEventHandler : implements<impl_ManipulationCompletedEventHandler<H>, abi<ManipulationCompletedEventHandler>>, H
{
    impl_ManipulationCompletedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Input::IManipulationCompletedRoutedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Input::ManipulationCompletedRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_ManipulationDeltaEventHandler : implements<impl_ManipulationDeltaEventHandler<H>, abi<ManipulationDeltaEventHandler>>, H
{
    impl_ManipulationDeltaEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Input::IManipulationDeltaRoutedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Input::ManipulationDeltaRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_ManipulationInertiaStartingEventHandler : implements<impl_ManipulationInertiaStartingEventHandler<H>, abi<ManipulationInertiaStartingEventHandler>>, H
{
    impl_ManipulationInertiaStartingEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Input::IManipulationInertiaStartingRoutedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Input::ManipulationInertiaStartingRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_ManipulationStartedEventHandler : implements<impl_ManipulationStartedEventHandler<H>, abi<ManipulationStartedEventHandler>>, H
{
    impl_ManipulationStartedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Input::ManipulationStartedRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_ManipulationStartingEventHandler : implements<impl_ManipulationStartingEventHandler<H>, abi<ManipulationStartingEventHandler>>, H
{
    impl_ManipulationStartingEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Input::IManipulationStartingRoutedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Input::ManipulationStartingRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_PointerEventHandler : implements<impl_PointerEventHandler<H>, abi<PointerEventHandler>>, H
{
    impl_PointerEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Input::IPointerRoutedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Input::PointerRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_RightTappedEventHandler : implements<impl_RightTappedEventHandler<H>, abi<RightTappedEventHandler>>, H
{
    impl_RightTappedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Input::IRightTappedRoutedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Input::RightTappedRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_TappedEventHandler : implements<impl_TappedEventHandler<H>, abi<TappedEventHandler>>, H
{
    impl_TappedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Input::ITappedRoutedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Input::TappedRoutedEventArgs *>(&e));
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

struct WINRT_EBO AccessKeyDisplayDismissedEventArgs :
    Windows::UI::Xaml::Input::IAccessKeyDisplayDismissedEventArgs
{
    AccessKeyDisplayDismissedEventArgs(std::nullptr_t) noexcept {}
    AccessKeyDisplayDismissedEventArgs();
};

struct WINRT_EBO AccessKeyDisplayRequestedEventArgs :
    Windows::UI::Xaml::Input::IAccessKeyDisplayRequestedEventArgs
{
    AccessKeyDisplayRequestedEventArgs(std::nullptr_t) noexcept {}
    AccessKeyDisplayRequestedEventArgs();
};

struct WINRT_EBO AccessKeyInvokedEventArgs :
    Windows::UI::Xaml::Input::IAccessKeyInvokedEventArgs
{
    AccessKeyInvokedEventArgs(std::nullptr_t) noexcept {}
    AccessKeyInvokedEventArgs();
};

struct WINRT_EBO AccessKeyManager :
    Windows::UI::Xaml::Input::IAccessKeyManager
{
    AccessKeyManager(std::nullptr_t) noexcept {}
    static bool IsDisplayModeEnabled();
    static event_token IsDisplayModeEnabledChanged(const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::Foundation::IInspectable> & value);
    using IsDisplayModeEnabledChanged_revoker = factory_event_revoker<IAccessKeyManagerStatics>;
    static IsDisplayModeEnabledChanged_revoker IsDisplayModeEnabledChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::Foundation::IInspectable> & value);
    static void IsDisplayModeEnabledChanged(event_token token);
    static void ExitDisplayMode();
};

struct WINRT_EBO ContextRequestedEventArgs :
    Windows::UI::Xaml::Input::IContextRequestedEventArgs,
    impl::bases<ContextRequestedEventArgs, Windows::UI::Xaml::RoutedEventArgs>,
    impl::require<ContextRequestedEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
    ContextRequestedEventArgs(std::nullptr_t) noexcept {}
    ContextRequestedEventArgs();
};

struct WINRT_EBO DoubleTappedRoutedEventArgs :
    Windows::UI::Xaml::Input::IDoubleTappedRoutedEventArgs,
    impl::bases<DoubleTappedRoutedEventArgs, Windows::UI::Xaml::RoutedEventArgs>,
    impl::require<DoubleTappedRoutedEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
    DoubleTappedRoutedEventArgs(std::nullptr_t) noexcept {}
    DoubleTappedRoutedEventArgs();
};

struct WINRT_EBO FocusManager :
    Windows::UI::Xaml::Input::IFocusManager
{
    FocusManager(std::nullptr_t) noexcept {}
    static Windows::Foundation::IInspectable GetFocusedElement();
    static bool TryMoveFocus(Windows::UI::Xaml::Input::FocusNavigationDirection focusNavigationDirection);
    static Windows::UI::Xaml::UIElement FindNextFocusableElement(Windows::UI::Xaml::Input::FocusNavigationDirection focusNavigationDirection);
    static Windows::UI::Xaml::UIElement FindNextFocusableElement(Windows::UI::Xaml::Input::FocusNavigationDirection focusNavigationDirection, const Windows::Foundation::Rect & hintRect);
};

struct WINRT_EBO HoldingRoutedEventArgs :
    Windows::UI::Xaml::Input::IHoldingRoutedEventArgs,
    impl::bases<HoldingRoutedEventArgs, Windows::UI::Xaml::RoutedEventArgs>,
    impl::require<HoldingRoutedEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
    HoldingRoutedEventArgs(std::nullptr_t) noexcept {}
    HoldingRoutedEventArgs();
};

struct WINRT_EBO InertiaExpansionBehavior :
    Windows::UI::Xaml::Input::IInertiaExpansionBehavior
{
    InertiaExpansionBehavior(std::nullptr_t) noexcept {}
};

struct WINRT_EBO InertiaRotationBehavior :
    Windows::UI::Xaml::Input::IInertiaRotationBehavior
{
    InertiaRotationBehavior(std::nullptr_t) noexcept {}
};

struct WINRT_EBO InertiaTranslationBehavior :
    Windows::UI::Xaml::Input::IInertiaTranslationBehavior
{
    InertiaTranslationBehavior(std::nullptr_t) noexcept {}
};

struct WINRT_EBO InputScope :
    Windows::UI::Xaml::Input::IInputScope,
    impl::bases<InputScope, Windows::UI::Xaml::DependencyObject>,
    impl::require<InputScope, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    InputScope(std::nullptr_t) noexcept {}
    InputScope();
};

struct WINRT_EBO InputScopeName :
    Windows::UI::Xaml::Input::IInputScopeName,
    impl::bases<InputScopeName, Windows::UI::Xaml::DependencyObject>,
    impl::require<InputScopeName, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    InputScopeName(std::nullptr_t) noexcept {}
    InputScopeName();
    InputScopeName(Windows::UI::Xaml::Input::InputScopeNameValue nameValue);
};

struct WINRT_EBO KeyRoutedEventArgs :
    Windows::UI::Xaml::Input::IKeyRoutedEventArgs,
    impl::bases<KeyRoutedEventArgs, Windows::UI::Xaml::RoutedEventArgs>,
    impl::require<KeyRoutedEventArgs, Windows::UI::Xaml::IRoutedEventArgs, Windows::UI::Xaml::Input::IKeyRoutedEventArgs2, Windows::UI::Xaml::Input::IKeyRoutedEventArgs3>
{
    KeyRoutedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ManipulationCompletedRoutedEventArgs :
    Windows::UI::Xaml::Input::IManipulationCompletedRoutedEventArgs,
    impl::bases<ManipulationCompletedRoutedEventArgs, Windows::UI::Xaml::RoutedEventArgs>,
    impl::require<ManipulationCompletedRoutedEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
    ManipulationCompletedRoutedEventArgs(std::nullptr_t) noexcept {}
    ManipulationCompletedRoutedEventArgs();
};

struct WINRT_EBO ManipulationDeltaRoutedEventArgs :
    Windows::UI::Xaml::Input::IManipulationDeltaRoutedEventArgs,
    impl::bases<ManipulationDeltaRoutedEventArgs, Windows::UI::Xaml::RoutedEventArgs>,
    impl::require<ManipulationDeltaRoutedEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
    ManipulationDeltaRoutedEventArgs(std::nullptr_t) noexcept {}
    ManipulationDeltaRoutedEventArgs();
};

struct WINRT_EBO ManipulationInertiaStartingRoutedEventArgs :
    Windows::UI::Xaml::Input::IManipulationInertiaStartingRoutedEventArgs,
    impl::bases<ManipulationInertiaStartingRoutedEventArgs, Windows::UI::Xaml::RoutedEventArgs>,
    impl::require<ManipulationInertiaStartingRoutedEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
    ManipulationInertiaStartingRoutedEventArgs(std::nullptr_t) noexcept {}
    ManipulationInertiaStartingRoutedEventArgs();
};

struct WINRT_EBO ManipulationPivot :
    Windows::UI::Xaml::Input::IManipulationPivot
{
    ManipulationPivot(std::nullptr_t) noexcept {}
    ManipulationPivot();
    ManipulationPivot(const Windows::Foundation::Point & center, double radius);
};

struct WINRT_EBO ManipulationStartedRoutedEventArgs :
    Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgs,
    impl::bases<ManipulationStartedRoutedEventArgs, Windows::UI::Xaml::RoutedEventArgs>,
    impl::require<ManipulationStartedRoutedEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
    ManipulationStartedRoutedEventArgs(std::nullptr_t) noexcept {}
    ManipulationStartedRoutedEventArgs();
};

struct WINRT_EBO ManipulationStartingRoutedEventArgs :
    Windows::UI::Xaml::Input::IManipulationStartingRoutedEventArgs,
    impl::bases<ManipulationStartingRoutedEventArgs, Windows::UI::Xaml::RoutedEventArgs>,
    impl::require<ManipulationStartingRoutedEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
    ManipulationStartingRoutedEventArgs(std::nullptr_t) noexcept {}
    ManipulationStartingRoutedEventArgs();
};

struct WINRT_EBO Pointer :
    Windows::UI::Xaml::Input::IPointer
{
    Pointer(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PointerRoutedEventArgs :
    Windows::UI::Xaml::Input::IPointerRoutedEventArgs,
    impl::bases<PointerRoutedEventArgs, Windows::UI::Xaml::RoutedEventArgs>,
    impl::require<PointerRoutedEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
    PointerRoutedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO RightTappedRoutedEventArgs :
    Windows::UI::Xaml::Input::IRightTappedRoutedEventArgs,
    impl::bases<RightTappedRoutedEventArgs, Windows::UI::Xaml::RoutedEventArgs>,
    impl::require<RightTappedRoutedEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
    RightTappedRoutedEventArgs(std::nullptr_t) noexcept {}
    RightTappedRoutedEventArgs();
};

struct WINRT_EBO TappedRoutedEventArgs :
    Windows::UI::Xaml::Input::ITappedRoutedEventArgs,
    impl::bases<TappedRoutedEventArgs, Windows::UI::Xaml::RoutedEventArgs>,
    impl::require<TappedRoutedEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
    TappedRoutedEventArgs(std::nullptr_t) noexcept {}
    TappedRoutedEventArgs();
};

}

}
