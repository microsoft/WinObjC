// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.UI.Xaml.Controls.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.ApplicationModel.3.h"
#include "internal/Windows.UI.Core.3.h"
#include "internal/Windows.UI.Xaml.Interop.3.h"
#include "internal/Windows.UI.Xaml.Media.Imaging.3.h"
#include "internal/Windows.Graphics.Imaging.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.ApplicationModel.DataTransfer.3.h"
#include "internal/Windows.ApplicationModel.DataTransfer.DragDrop.3.h"
#include "internal/Windows.UI.Xaml.Media.3.h"
#include "internal/Windows.UI.Xaml.Input.3.h"
#include "internal/Windows.UI.Xaml.Automation.Peers.3.h"
#include "internal/Windows.UI.Xaml.Media.Media3D.3.h"
#include "internal/Windows.UI.Input.3.h"
#include "internal/Windows.UI.Xaml.Controls.Primitives.3.h"
#include "internal/Windows.UI.Xaml.Media.Animation.3.h"
#include "internal/Windows.UI.Xaml.Data.3.h"
#include "internal/Windows.ApplicationModel.Activation.3.h"
#include "internal/Windows.UI.Xaml.3.h"
#include "Windows.UI.h"
#include "Windows.ApplicationModel.Core.h"
#include "Windows.Foundation.Collections.h"
#include "internal/Windows.UI.Xaml.4.h"
#include "internal/Windows.UI.Xaml.5.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml {

template <typename L> ApplicationInitializationCallback::ApplicationInitializationCallback(L lambda) :
    ApplicationInitializationCallback(impl::make_delegate<impl_ApplicationInitializationCallback<L>, ApplicationInitializationCallback>(std::forward<L>(lambda)))
{}

template <typename F> ApplicationInitializationCallback::ApplicationInitializationCallback(F * function) :
    ApplicationInitializationCallback([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> ApplicationInitializationCallback::ApplicationInitializationCallback(O * object, M method) :
    ApplicationInitializationCallback([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void ApplicationInitializationCallback::operator()(const Windows::UI::Xaml::ApplicationInitializationCallbackParams & p) const
{
    check_hresult((*(abi<ApplicationInitializationCallback> **)this)->abi_Invoke(get_abi(p)));
}

template <typename L> BindingFailedEventHandler::BindingFailedEventHandler(L lambda) :
    BindingFailedEventHandler(impl::make_delegate<impl_BindingFailedEventHandler<L>, BindingFailedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> BindingFailedEventHandler::BindingFailedEventHandler(F * function) :
    BindingFailedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> BindingFailedEventHandler::BindingFailedEventHandler(O * object, M method) :
    BindingFailedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void BindingFailedEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::BindingFailedEventArgs & e) const
{
    check_hresult((*(abi<BindingFailedEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

template <typename L> CreateDefaultValueCallback::CreateDefaultValueCallback(L lambda) :
    CreateDefaultValueCallback(impl::make_delegate<impl_CreateDefaultValueCallback<L>, CreateDefaultValueCallback>(std::forward<L>(lambda)))
{}

template <typename F> CreateDefaultValueCallback::CreateDefaultValueCallback(F * function) :
    CreateDefaultValueCallback([=](auto && ... args) { return function(args ...); })
{}

template <typename O, typename M> CreateDefaultValueCallback::CreateDefaultValueCallback(O * object, M method) :
    CreateDefaultValueCallback([=](auto && ... args) { return ((*object).*(method))(args ...); })
{}

inline Windows::Foundation::IInspectable CreateDefaultValueCallback::operator()() const
{
    Windows::Foundation::IInspectable value;
    check_hresult((*(abi<CreateDefaultValueCallback> **)this)->abi_Invoke(put_abi(value)));
    return value;
}

template <typename L> DependencyPropertyChangedCallback::DependencyPropertyChangedCallback(L lambda) :
    DependencyPropertyChangedCallback(impl::make_delegate<impl_DependencyPropertyChangedCallback<L>, DependencyPropertyChangedCallback>(std::forward<L>(lambda)))
{}

template <typename F> DependencyPropertyChangedCallback::DependencyPropertyChangedCallback(F * function) :
    DependencyPropertyChangedCallback([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> DependencyPropertyChangedCallback::DependencyPropertyChangedCallback(O * object, M method) :
    DependencyPropertyChangedCallback([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void DependencyPropertyChangedCallback::operator()(const Windows::UI::Xaml::DependencyObject & sender, const Windows::UI::Xaml::DependencyProperty & dp) const
{
    check_hresult((*(abi<DependencyPropertyChangedCallback> **)this)->abi_Invoke(get_abi(sender), get_abi(dp)));
}

template <typename L> DependencyPropertyChangedEventHandler::DependencyPropertyChangedEventHandler(L lambda) :
    DependencyPropertyChangedEventHandler(impl::make_delegate<impl_DependencyPropertyChangedEventHandler<L>, DependencyPropertyChangedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> DependencyPropertyChangedEventHandler::DependencyPropertyChangedEventHandler(F * function) :
    DependencyPropertyChangedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> DependencyPropertyChangedEventHandler::DependencyPropertyChangedEventHandler(O * object, M method) :
    DependencyPropertyChangedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void DependencyPropertyChangedEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::DependencyPropertyChangedEventArgs & e) const
{
    check_hresult((*(abi<DependencyPropertyChangedEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

template <typename L> DragEventHandler::DragEventHandler(L lambda) :
    DragEventHandler(impl::make_delegate<impl_DragEventHandler<L>, DragEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> DragEventHandler::DragEventHandler(F * function) :
    DragEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> DragEventHandler::DragEventHandler(O * object, M method) :
    DragEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void DragEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::DragEventArgs & e) const
{
    check_hresult((*(abi<DragEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

template <typename L> EnteredBackgroundEventHandler::EnteredBackgroundEventHandler(L lambda) :
    EnteredBackgroundEventHandler(impl::make_delegate<impl_EnteredBackgroundEventHandler<L>, EnteredBackgroundEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> EnteredBackgroundEventHandler::EnteredBackgroundEventHandler(F * function) :
    EnteredBackgroundEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> EnteredBackgroundEventHandler::EnteredBackgroundEventHandler(O * object, M method) :
    EnteredBackgroundEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void EnteredBackgroundEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::ApplicationModel::EnteredBackgroundEventArgs & e) const
{
    check_hresult((*(abi<EnteredBackgroundEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

template <typename L> ExceptionRoutedEventHandler::ExceptionRoutedEventHandler(L lambda) :
    ExceptionRoutedEventHandler(impl::make_delegate<impl_ExceptionRoutedEventHandler<L>, ExceptionRoutedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> ExceptionRoutedEventHandler::ExceptionRoutedEventHandler(F * function) :
    ExceptionRoutedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> ExceptionRoutedEventHandler::ExceptionRoutedEventHandler(O * object, M method) :
    ExceptionRoutedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void ExceptionRoutedEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::ExceptionRoutedEventArgs & e) const
{
    check_hresult((*(abi<ExceptionRoutedEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

template <typename L> LeavingBackgroundEventHandler::LeavingBackgroundEventHandler(L lambda) :
    LeavingBackgroundEventHandler(impl::make_delegate<impl_LeavingBackgroundEventHandler<L>, LeavingBackgroundEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> LeavingBackgroundEventHandler::LeavingBackgroundEventHandler(F * function) :
    LeavingBackgroundEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> LeavingBackgroundEventHandler::LeavingBackgroundEventHandler(O * object, M method) :
    LeavingBackgroundEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void LeavingBackgroundEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::ApplicationModel::LeavingBackgroundEventArgs & e) const
{
    check_hresult((*(abi<LeavingBackgroundEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

template <typename L> PropertyChangedCallback::PropertyChangedCallback(L lambda) :
    PropertyChangedCallback(impl::make_delegate<impl_PropertyChangedCallback<L>, PropertyChangedCallback>(std::forward<L>(lambda)))
{}

template <typename F> PropertyChangedCallback::PropertyChangedCallback(F * function) :
    PropertyChangedCallback([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> PropertyChangedCallback::PropertyChangedCallback(O * object, M method) :
    PropertyChangedCallback([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void PropertyChangedCallback::operator()(const Windows::UI::Xaml::DependencyObject & d, const Windows::UI::Xaml::DependencyPropertyChangedEventArgs & e) const
{
    check_hresult((*(abi<PropertyChangedCallback> **)this)->abi_Invoke(get_abi(d), get_abi(e)));
}

template <typename L> RoutedEventHandler::RoutedEventHandler(L lambda) :
    RoutedEventHandler(impl::make_delegate<impl_RoutedEventHandler<L>, RoutedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> RoutedEventHandler::RoutedEventHandler(F * function) :
    RoutedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> RoutedEventHandler::RoutedEventHandler(O * object, M method) :
    RoutedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void RoutedEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::RoutedEventArgs & e) const
{
    check_hresult((*(abi<RoutedEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

template <typename L> SizeChangedEventHandler::SizeChangedEventHandler(L lambda) :
    SizeChangedEventHandler(impl::make_delegate<impl_SizeChangedEventHandler<L>, SizeChangedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> SizeChangedEventHandler::SizeChangedEventHandler(F * function) :
    SizeChangedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> SizeChangedEventHandler::SizeChangedEventHandler(O * object, M method) :
    SizeChangedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void SizeChangedEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::SizeChangedEventArgs & e) const
{
    check_hresult((*(abi<SizeChangedEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

template <typename L> SuspendingEventHandler::SuspendingEventHandler(L lambda) :
    SuspendingEventHandler(impl::make_delegate<impl_SuspendingEventHandler<L>, SuspendingEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> SuspendingEventHandler::SuspendingEventHandler(F * function) :
    SuspendingEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> SuspendingEventHandler::SuspendingEventHandler(O * object, M method) :
    SuspendingEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void SuspendingEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::ApplicationModel::SuspendingEventArgs & e) const
{
    check_hresult((*(abi<SuspendingEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

template <typename L> UnhandledExceptionEventHandler::UnhandledExceptionEventHandler(L lambda) :
    UnhandledExceptionEventHandler(impl::make_delegate<impl_UnhandledExceptionEventHandler<L>, UnhandledExceptionEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> UnhandledExceptionEventHandler::UnhandledExceptionEventHandler(F * function) :
    UnhandledExceptionEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> UnhandledExceptionEventHandler::UnhandledExceptionEventHandler(O * object, M method) :
    UnhandledExceptionEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void UnhandledExceptionEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::UnhandledExceptionEventArgs & e) const
{
    check_hresult((*(abi<UnhandledExceptionEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

template <typename L> VisualStateChangedEventHandler::VisualStateChangedEventHandler(L lambda) :
    VisualStateChangedEventHandler(impl::make_delegate<impl_VisualStateChangedEventHandler<L>, VisualStateChangedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> VisualStateChangedEventHandler::VisualStateChangedEventHandler(F * function) :
    VisualStateChangedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> VisualStateChangedEventHandler::VisualStateChangedEventHandler(O * object, M method) :
    VisualStateChangedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void VisualStateChangedEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::VisualStateChangedEventArgs & e) const
{
    check_hresult((*(abi<VisualStateChangedEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

template <typename L> WindowActivatedEventHandler::WindowActivatedEventHandler(L lambda) :
    WindowActivatedEventHandler(impl::make_delegate<impl_WindowActivatedEventHandler<L>, WindowActivatedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> WindowActivatedEventHandler::WindowActivatedEventHandler(F * function) :
    WindowActivatedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> WindowActivatedEventHandler::WindowActivatedEventHandler(O * object, M method) :
    WindowActivatedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void WindowActivatedEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Core::WindowActivatedEventArgs & e) const
{
    check_hresult((*(abi<WindowActivatedEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

template <typename L> WindowClosedEventHandler::WindowClosedEventHandler(L lambda) :
    WindowClosedEventHandler(impl::make_delegate<impl_WindowClosedEventHandler<L>, WindowClosedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> WindowClosedEventHandler::WindowClosedEventHandler(F * function) :
    WindowClosedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> WindowClosedEventHandler::WindowClosedEventHandler(O * object, M method) :
    WindowClosedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void WindowClosedEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Core::CoreWindowEventArgs & e) const
{
    check_hresult((*(abi<WindowClosedEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

template <typename L> WindowSizeChangedEventHandler::WindowSizeChangedEventHandler(L lambda) :
    WindowSizeChangedEventHandler(impl::make_delegate<impl_WindowSizeChangedEventHandler<L>, WindowSizeChangedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> WindowSizeChangedEventHandler::WindowSizeChangedEventHandler(F * function) :
    WindowSizeChangedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> WindowSizeChangedEventHandler::WindowSizeChangedEventHandler(O * object, M method) :
    WindowSizeChangedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void WindowSizeChangedEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Core::WindowSizeChangedEventArgs & e) const
{
    check_hresult((*(abi<WindowSizeChangedEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

template <typename L> WindowVisibilityChangedEventHandler::WindowVisibilityChangedEventHandler(L lambda) :
    WindowVisibilityChangedEventHandler(impl::make_delegate<impl_WindowVisibilityChangedEventHandler<L>, WindowVisibilityChangedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> WindowVisibilityChangedEventHandler::WindowVisibilityChangedEventHandler(F * function) :
    WindowVisibilityChangedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> WindowVisibilityChangedEventHandler::WindowVisibilityChangedEventHandler(O * object, M method) :
    WindowVisibilityChangedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void WindowVisibilityChangedEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Core::VisibilityChangedEventArgs & e) const
{
    check_hresult((*(abi<WindowVisibilityChangedEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

}

namespace impl {

template <typename D>
struct produce<D, Windows::UI::Xaml::IAdaptiveTrigger> : produce_base<D, Windows::UI::Xaml::IAdaptiveTrigger>
{
    HRESULT __stdcall get_MinWindowWidth(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinWindowWidth());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MinWindowWidth(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MinWindowWidth(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinWindowHeight(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinWindowHeight());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MinWindowHeight(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MinWindowHeight(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IAdaptiveTriggerFactory> : produce_base<D, Windows::UI::Xaml::IAdaptiveTriggerFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::IAdaptiveTrigger> instance) noexcept override
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
struct produce<D, Windows::UI::Xaml::IAdaptiveTriggerStatics> : produce_base<D, Windows::UI::Xaml::IAdaptiveTriggerStatics>
{
    HRESULT __stdcall get_MinWindowWidthProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinWindowWidthProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinWindowHeightProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinWindowHeightProperty());
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
struct produce<D, Windows::UI::Xaml::IApplication> : produce_base<D, Windows::UI::Xaml::IApplication>
{
    HRESULT __stdcall get_Resources(impl::abi_arg_out<Windows::UI::Xaml::IResourceDictionary> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Resources());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Resources(impl::abi_arg_in<Windows::UI::Xaml::IResourceDictionary> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Resources(*reinterpret_cast<const Windows::UI::Xaml::ResourceDictionary *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DebugSettings(impl::abi_arg_out<Windows::UI::Xaml::IDebugSettings> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DebugSettings());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RequestedTheme(Windows::UI::Xaml::ApplicationTheme * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequestedTheme());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RequestedTheme(Windows::UI::Xaml::ApplicationTheme value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequestedTheme(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_UnhandledException(impl::abi_arg_in<Windows::UI::Xaml::UnhandledExceptionEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().UnhandledException(*reinterpret_cast<const Windows::UI::Xaml::UnhandledExceptionEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_UnhandledException(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UnhandledException(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Suspending(impl::abi_arg_in<Windows::UI::Xaml::SuspendingEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Suspending(*reinterpret_cast<const Windows::UI::Xaml::SuspendingEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Suspending(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Suspending(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Resuming(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Foundation::IInspectable>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Resuming(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Resuming(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Resuming(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Exit() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Exit();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IApplication2> : produce_base<D, Windows::UI::Xaml::IApplication2>
{
    HRESULT __stdcall get_FocusVisualKind(Windows::UI::Xaml::FocusVisualKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FocusVisualKind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FocusVisualKind(Windows::UI::Xaml::FocusVisualKind value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FocusVisualKind(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RequiresPointerMode(Windows::UI::Xaml::ApplicationRequiresPointerMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequiresPointerMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RequiresPointerMode(Windows::UI::Xaml::ApplicationRequiresPointerMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequiresPointerMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_LeavingBackground(impl::abi_arg_in<Windows::UI::Xaml::LeavingBackgroundEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().LeavingBackground(*reinterpret_cast<const Windows::UI::Xaml::LeavingBackgroundEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_LeavingBackground(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LeavingBackground(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_EnteredBackground(impl::abi_arg_in<Windows::UI::Xaml::EnteredBackgroundEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().EnteredBackground(*reinterpret_cast<const Windows::UI::Xaml::EnteredBackgroundEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_EnteredBackground(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnteredBackground(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IApplicationFactory> : produce_base<D, Windows::UI::Xaml::IApplicationFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::IApplication> instance) noexcept override
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
struct produce<D, Windows::UI::Xaml::IApplicationInitializationCallbackParams> : produce_base<D, Windows::UI::Xaml::IApplicationInitializationCallbackParams>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::IApplicationOverrides> : produce_base<D, Windows::UI::Xaml::IApplicationOverrides>
{
    HRESULT __stdcall abi_OnActivated(impl::abi_arg_in<Windows::ApplicationModel::Activation::IActivatedEventArgs> args) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnActivated(*reinterpret_cast<const Windows::ApplicationModel::Activation::IActivatedEventArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnLaunched(impl::abi_arg_in<Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs> args) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnLaunched(*reinterpret_cast<const Windows::ApplicationModel::Activation::LaunchActivatedEventArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnFileActivated(impl::abi_arg_in<Windows::ApplicationModel::Activation::IFileActivatedEventArgs> args) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnFileActivated(*reinterpret_cast<const Windows::ApplicationModel::Activation::FileActivatedEventArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnSearchActivated(impl::abi_arg_in<Windows::ApplicationModel::Activation::ISearchActivatedEventArgs> args) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnSearchActivated(*reinterpret_cast<const Windows::ApplicationModel::Activation::SearchActivatedEventArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnShareTargetActivated(impl::abi_arg_in<Windows::ApplicationModel::Activation::IShareTargetActivatedEventArgs> args) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnShareTargetActivated(*reinterpret_cast<const Windows::ApplicationModel::Activation::ShareTargetActivatedEventArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnFileOpenPickerActivated(impl::abi_arg_in<Windows::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs> args) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnFileOpenPickerActivated(*reinterpret_cast<const Windows::ApplicationModel::Activation::FileOpenPickerActivatedEventArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnFileSavePickerActivated(impl::abi_arg_in<Windows::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs> args) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnFileSavePickerActivated(*reinterpret_cast<const Windows::ApplicationModel::Activation::FileSavePickerActivatedEventArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnCachedFileUpdaterActivated(impl::abi_arg_in<Windows::ApplicationModel::Activation::ICachedFileUpdaterActivatedEventArgs> args) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnCachedFileUpdaterActivated(*reinterpret_cast<const Windows::ApplicationModel::Activation::CachedFileUpdaterActivatedEventArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnWindowCreated(impl::abi_arg_in<Windows::UI::Xaml::IWindowCreatedEventArgs> args) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnWindowCreated(*reinterpret_cast<const Windows::UI::Xaml::WindowCreatedEventArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IApplicationOverrides2> : produce_base<D, Windows::UI::Xaml::IApplicationOverrides2>
{
    HRESULT __stdcall abi_OnBackgroundActivated(impl::abi_arg_in<Windows::ApplicationModel::Activation::IBackgroundActivatedEventArgs> args) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnBackgroundActivated(*reinterpret_cast<const Windows::ApplicationModel::Activation::BackgroundActivatedEventArgs *>(&args));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IApplicationStatics> : produce_base<D, Windows::UI::Xaml::IApplicationStatics>
{
    HRESULT __stdcall get_Current(impl::abi_arg_out<Windows::UI::Xaml::IApplication> value) noexcept override
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

    HRESULT __stdcall abi_Start(impl::abi_arg_in<Windows::UI::Xaml::ApplicationInitializationCallback> callback) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start(*reinterpret_cast<const Windows::UI::Xaml::ApplicationInitializationCallback *>(&callback));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LoadComponent(impl::abi_arg_in<Windows::Foundation::IInspectable> component, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> resourceLocator) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LoadComponent(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&component), *reinterpret_cast<const Windows::Foundation::Uri *>(&resourceLocator));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LoadComponentWithResourceLocation(impl::abi_arg_in<Windows::Foundation::IInspectable> component, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> resourceLocator, Windows::UI::Xaml::Controls::Primitives::ComponentResourceLocation componentResourceLocation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LoadComponent(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&component), *reinterpret_cast<const Windows::Foundation::Uri *>(&resourceLocator), componentResourceLocation);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IBindingFailedEventArgs> : produce_base<D, Windows::UI::Xaml::IBindingFailedEventArgs>
{
    HRESULT __stdcall get_Message(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Message());
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
struct produce<D, Windows::UI::Xaml::ICornerRadiusHelper> : produce_base<D, Windows::UI::Xaml::ICornerRadiusHelper>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::ICornerRadiusHelperStatics> : produce_base<D, Windows::UI::Xaml::ICornerRadiusHelperStatics>
{
    HRESULT __stdcall abi_FromRadii(double topLeft, double topRight, double bottomRight, double bottomLeft, impl::abi_arg_out<Windows::UI::Xaml::CornerRadius> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().FromRadii(topLeft, topRight, bottomRight, bottomLeft));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromUniformRadius(double uniformRadius, impl::abi_arg_out<Windows::UI::Xaml::CornerRadius> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().FromUniformRadius(uniformRadius));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IDataContextChangedEventArgs> : produce_base<D, Windows::UI::Xaml::IDataContextChangedEventArgs>
{
    HRESULT __stdcall get_NewValue(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NewValue());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
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
struct produce<D, Windows::UI::Xaml::IDataTemplate> : produce_base<D, Windows::UI::Xaml::IDataTemplate>
{
    HRESULT __stdcall abi_LoadContent(impl::abi_arg_out<Windows::UI::Xaml::IDependencyObject> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().LoadContent());
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
struct produce<D, Windows::UI::Xaml::IDataTemplateExtension> : produce_base<D, Windows::UI::Xaml::IDataTemplateExtension>
{
    HRESULT __stdcall abi_ResetTemplate() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ResetTemplate();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ProcessBinding(uint32_t phase, bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().ProcessBinding(phase));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ProcessBindings(impl::abi_arg_in<Windows::UI::Xaml::Controls::IContainerContentChangingEventArgs> arg, int32_t * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().ProcessBindings(*reinterpret_cast<const Windows::UI::Xaml::Controls::ContainerContentChangingEventArgs *>(&arg)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IDataTemplateFactory> : produce_base<D, Windows::UI::Xaml::IDataTemplateFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::IDataTemplate> instance) noexcept override
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
struct produce<D, Windows::UI::Xaml::IDataTemplateKey> : produce_base<D, Windows::UI::Xaml::IDataTemplateKey>
{
    HRESULT __stdcall get_DataType(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DataType());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DataType(impl::abi_arg_in<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DataType(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IDataTemplateKeyFactory> : produce_base<D, Windows::UI::Xaml::IDataTemplateKeyFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::IDataTemplateKey> instance) noexcept override
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

    HRESULT __stdcall abi_CreateInstanceWithType(impl::abi_arg_in<Windows::Foundation::IInspectable> dataType, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::IDataTemplateKey> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithType(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&dataType), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::IDataTemplateStatics2> : produce_base<D, Windows::UI::Xaml::IDataTemplateStatics2>
{
    HRESULT __stdcall get_ExtensionInstanceProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtensionInstanceProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetExtensionInstance(impl::abi_arg_in<Windows::UI::Xaml::IFrameworkElement> element, impl::abi_arg_out<Windows::UI::Xaml::IDataTemplateExtension> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetExtensionInstance(*reinterpret_cast<const Windows::UI::Xaml::FrameworkElement *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetExtensionInstance(impl::abi_arg_in<Windows::UI::Xaml::IFrameworkElement> element, impl::abi_arg_in<Windows::UI::Xaml::IDataTemplateExtension> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetExtensionInstance(*reinterpret_cast<const Windows::UI::Xaml::FrameworkElement *>(&element), *reinterpret_cast<const Windows::UI::Xaml::IDataTemplateExtension *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IDebugSettings> : produce_base<D, Windows::UI::Xaml::IDebugSettings>
{
    HRESULT __stdcall get_EnableFrameRateCounter(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EnableFrameRateCounter());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EnableFrameRateCounter(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnableFrameRateCounter(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsBindingTracingEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsBindingTracingEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsBindingTracingEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsBindingTracingEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsOverdrawHeatMapEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsOverdrawHeatMapEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsOverdrawHeatMapEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsOverdrawHeatMapEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_BindingFailed(impl::abi_arg_in<Windows::UI::Xaml::BindingFailedEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().BindingFailed(*reinterpret_cast<const Windows::UI::Xaml::BindingFailedEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_BindingFailed(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BindingFailed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IDebugSettings2> : produce_base<D, Windows::UI::Xaml::IDebugSettings2>
{
    HRESULT __stdcall get_EnableRedrawRegions(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EnableRedrawRegions());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EnableRedrawRegions(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnableRedrawRegions(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IDebugSettings3> : produce_base<D, Windows::UI::Xaml::IDebugSettings3>
{
    HRESULT __stdcall get_IsTextPerformanceVisualizationEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsTextPerformanceVisualizationEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsTextPerformanceVisualizationEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsTextPerformanceVisualizationEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IDependencyObject> : produce_base<D, Windows::UI::Xaml::IDependencyObject>
{
    HRESULT __stdcall abi_GetValue(impl::abi_arg_in<Windows::UI::Xaml::IDependencyProperty> dp, impl::abi_arg_out<Windows::Foundation::IInspectable> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetValue(*reinterpret_cast<const Windows::UI::Xaml::DependencyProperty *>(&dp)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetValue(impl::abi_arg_in<Windows::UI::Xaml::IDependencyProperty> dp, impl::abi_arg_in<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetValue(*reinterpret_cast<const Windows::UI::Xaml::DependencyProperty *>(&dp), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ClearValue(impl::abi_arg_in<Windows::UI::Xaml::IDependencyProperty> dp) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClearValue(*reinterpret_cast<const Windows::UI::Xaml::DependencyProperty *>(&dp));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReadLocalValue(impl::abi_arg_in<Windows::UI::Xaml::IDependencyProperty> dp, impl::abi_arg_out<Windows::Foundation::IInspectable> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().ReadLocalValue(*reinterpret_cast<const Windows::UI::Xaml::DependencyProperty *>(&dp)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAnimationBaseValue(impl::abi_arg_in<Windows::UI::Xaml::IDependencyProperty> dp, impl::abi_arg_out<Windows::Foundation::IInspectable> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetAnimationBaseValue(*reinterpret_cast<const Windows::UI::Xaml::DependencyProperty *>(&dp)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
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
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IDependencyObject2> : produce_base<D, Windows::UI::Xaml::IDependencyObject2>
{
    HRESULT __stdcall abi_RegisterPropertyChangedCallback(impl::abi_arg_in<Windows::UI::Xaml::IDependencyProperty> dp, impl::abi_arg_in<Windows::UI::Xaml::DependencyPropertyChangedCallback> callback, int64_t * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().RegisterPropertyChangedCallback(*reinterpret_cast<const Windows::UI::Xaml::DependencyProperty *>(&dp), *reinterpret_cast<const Windows::UI::Xaml::DependencyPropertyChangedCallback *>(&callback)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UnregisterPropertyChangedCallback(impl::abi_arg_in<Windows::UI::Xaml::IDependencyProperty> dp, int64_t token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UnregisterPropertyChangedCallback(*reinterpret_cast<const Windows::UI::Xaml::DependencyProperty *>(&dp), token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IDependencyObjectCollectionFactory> : produce_base<D, Windows::UI::Xaml::IDependencyObjectCollectionFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::Foundation::Collections::IObservableVector<Windows::UI::Xaml::DependencyObject>> instance) noexcept override
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
struct produce<D, Windows::UI::Xaml::IDependencyObjectFactory> : produce_base<D, Windows::UI::Xaml::IDependencyObjectFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::IDependencyObject> instance) noexcept override
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
struct produce<D, Windows::UI::Xaml::IDependencyProperty> : produce_base<D, Windows::UI::Xaml::IDependencyProperty>
{
    HRESULT __stdcall abi_GetMetadata(impl::abi_arg_in<Windows::UI::Xaml::Interop::TypeName> forType, impl::abi_arg_out<Windows::UI::Xaml::IPropertyMetadata> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetMetadata(*reinterpret_cast<const Windows::UI::Xaml::Interop::TypeName *>(&forType)));
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
struct produce<D, Windows::UI::Xaml::IDependencyPropertyChangedEventArgs> : produce_base<D, Windows::UI::Xaml::IDependencyPropertyChangedEventArgs>
{
    HRESULT __stdcall get_Property(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Property());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OldValue(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OldValue());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NewValue(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NewValue());
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
struct produce<D, Windows::UI::Xaml::IDependencyPropertyStatics> : produce_base<D, Windows::UI::Xaml::IDependencyPropertyStatics>
{
    HRESULT __stdcall get_UnsetValue(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UnsetValue());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Register(impl::abi_arg_in<hstring> name, impl::abi_arg_in<Windows::UI::Xaml::Interop::TypeName> propertyType, impl::abi_arg_in<Windows::UI::Xaml::Interop::TypeName> ownerType, impl::abi_arg_in<Windows::UI::Xaml::IPropertyMetadata> typeMetadata, impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().Register(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::UI::Xaml::Interop::TypeName *>(&propertyType), *reinterpret_cast<const Windows::UI::Xaml::Interop::TypeName *>(&ownerType), *reinterpret_cast<const Windows::UI::Xaml::PropertyMetadata *>(&typeMetadata)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RegisterAttached(impl::abi_arg_in<hstring> name, impl::abi_arg_in<Windows::UI::Xaml::Interop::TypeName> propertyType, impl::abi_arg_in<Windows::UI::Xaml::Interop::TypeName> ownerType, impl::abi_arg_in<Windows::UI::Xaml::IPropertyMetadata> defaultMetadata, impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().RegisterAttached(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::UI::Xaml::Interop::TypeName *>(&propertyType), *reinterpret_cast<const Windows::UI::Xaml::Interop::TypeName *>(&ownerType), *reinterpret_cast<const Windows::UI::Xaml::PropertyMetadata *>(&defaultMetadata)));
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
struct produce<D, Windows::UI::Xaml::IDispatcherTimer> : produce_base<D, Windows::UI::Xaml::IDispatcherTimer>
{
    HRESULT __stdcall get_Interval(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Interval());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Interval(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Interval(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Tick(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Foundation::IInspectable>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Tick(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Tick(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Tick(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Start() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Stop() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stop();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IDispatcherTimerFactory> : produce_base<D, Windows::UI::Xaml::IDispatcherTimerFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::IDispatcherTimer> instance) noexcept override
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
struct produce<D, Windows::UI::Xaml::IDragEventArgs> : produce_base<D, Windows::UI::Xaml::IDragEventArgs>
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

    HRESULT __stdcall get_Data(impl::abi_arg_out<Windows::ApplicationModel::DataTransfer::IDataPackage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Data());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Data(impl::abi_arg_in<Windows::ApplicationModel::DataTransfer::IDataPackage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Data(*reinterpret_cast<const Windows::ApplicationModel::DataTransfer::DataPackage *>(&value));
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
struct produce<D, Windows::UI::Xaml::IDragEventArgs2> : produce_base<D, Windows::UI::Xaml::IDragEventArgs2>
{
    HRESULT __stdcall get_DataView(impl::abi_arg_out<Windows::ApplicationModel::DataTransfer::IDataPackageView> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DataView());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DragUIOverride(impl::abi_arg_out<Windows::UI::Xaml::IDragUIOverride> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DragUIOverride());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Modifiers(Windows::ApplicationModel::DataTransfer::DragDrop::DragDropModifiers * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Modifiers());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AcceptedOperation(Windows::ApplicationModel::DataTransfer::DataPackageOperation * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AcceptedOperation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AcceptedOperation(Windows::ApplicationModel::DataTransfer::DataPackageOperation value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AcceptedOperation(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::UI::Xaml::IDragOperationDeferral> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetDeferral());
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
struct produce<D, Windows::UI::Xaml::IDragEventArgs3> : produce_base<D, Windows::UI::Xaml::IDragEventArgs3>
{
    HRESULT __stdcall get_AllowedOperations(Windows::ApplicationModel::DataTransfer::DataPackageOperation * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllowedOperations());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IDragOperationDeferral> : produce_base<D, Windows::UI::Xaml::IDragOperationDeferral>
{
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
struct produce<D, Windows::UI::Xaml::IDragStartingEventArgs> : produce_base<D, Windows::UI::Xaml::IDragStartingEventArgs>
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

    HRESULT __stdcall get_Data(impl::abi_arg_out<Windows::ApplicationModel::DataTransfer::IDataPackage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Data());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DragUI(impl::abi_arg_out<Windows::UI::Xaml::IDragUI> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DragUI());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::UI::Xaml::IDragOperationDeferral> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetDeferral());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
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
struct produce<D, Windows::UI::Xaml::IDragStartingEventArgs2> : produce_base<D, Windows::UI::Xaml::IDragStartingEventArgs2>
{
    HRESULT __stdcall get_AllowedOperations(Windows::ApplicationModel::DataTransfer::DataPackageOperation * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllowedOperations());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AllowedOperations(Windows::ApplicationModel::DataTransfer::DataPackageOperation value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowedOperations(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IDragUI> : produce_base<D, Windows::UI::Xaml::IDragUI>
{
    HRESULT __stdcall abi_SetContentFromBitmapImage(impl::abi_arg_in<Windows::UI::Xaml::Media::Imaging::IBitmapImage> bitmapImage) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetContentFromBitmapImage(*reinterpret_cast<const Windows::UI::Xaml::Media::Imaging::BitmapImage *>(&bitmapImage));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetContentFromBitmapImageWithAnchorPoint(impl::abi_arg_in<Windows::UI::Xaml::Media::Imaging::IBitmapImage> bitmapImage, impl::abi_arg_in<Windows::Foundation::Point> anchorPoint) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetContentFromBitmapImage(*reinterpret_cast<const Windows::UI::Xaml::Media::Imaging::BitmapImage *>(&bitmapImage), *reinterpret_cast<const Windows::Foundation::Point *>(&anchorPoint));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetContentFromSoftwareBitmap(impl::abi_arg_in<Windows::Graphics::Imaging::ISoftwareBitmap> softwareBitmap) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetContentFromSoftwareBitmap(*reinterpret_cast<const Windows::Graphics::Imaging::SoftwareBitmap *>(&softwareBitmap));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetContentFromSoftwareBitmapWithAnchorPoint(impl::abi_arg_in<Windows::Graphics::Imaging::ISoftwareBitmap> softwareBitmap, impl::abi_arg_in<Windows::Foundation::Point> anchorPoint) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetContentFromSoftwareBitmap(*reinterpret_cast<const Windows::Graphics::Imaging::SoftwareBitmap *>(&softwareBitmap), *reinterpret_cast<const Windows::Foundation::Point *>(&anchorPoint));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetContentFromDataPackage() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetContentFromDataPackage();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IDragUIOverride> : produce_base<D, Windows::UI::Xaml::IDragUIOverride>
{
    HRESULT __stdcall get_Caption(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Caption());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Caption(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Caption(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsContentVisible(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsContentVisible());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsContentVisible(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsContentVisible(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsCaptionVisible(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsCaptionVisible());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsCaptionVisible(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsCaptionVisible(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsGlyphVisible(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsGlyphVisible());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsGlyphVisible(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsGlyphVisible(value);
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

    HRESULT __stdcall abi_SetContentFromBitmapImage(impl::abi_arg_in<Windows::UI::Xaml::Media::Imaging::IBitmapImage> bitmapImage) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetContentFromBitmapImage(*reinterpret_cast<const Windows::UI::Xaml::Media::Imaging::BitmapImage *>(&bitmapImage));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetContentFromBitmapImageWithAnchorPoint(impl::abi_arg_in<Windows::UI::Xaml::Media::Imaging::IBitmapImage> bitmapImage, impl::abi_arg_in<Windows::Foundation::Point> anchorPoint) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetContentFromBitmapImage(*reinterpret_cast<const Windows::UI::Xaml::Media::Imaging::BitmapImage *>(&bitmapImage), *reinterpret_cast<const Windows::Foundation::Point *>(&anchorPoint));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetContentFromSoftwareBitmap(impl::abi_arg_in<Windows::Graphics::Imaging::ISoftwareBitmap> softwareBitmap) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetContentFromSoftwareBitmap(*reinterpret_cast<const Windows::Graphics::Imaging::SoftwareBitmap *>(&softwareBitmap));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetContentFromSoftwareBitmapWithAnchorPoint(impl::abi_arg_in<Windows::Graphics::Imaging::ISoftwareBitmap> softwareBitmap, impl::abi_arg_in<Windows::Foundation::Point> anchorPoint) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetContentFromSoftwareBitmap(*reinterpret_cast<const Windows::Graphics::Imaging::SoftwareBitmap *>(&softwareBitmap), *reinterpret_cast<const Windows::Foundation::Point *>(&anchorPoint));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IDropCompletedEventArgs> : produce_base<D, Windows::UI::Xaml::IDropCompletedEventArgs>
{
    HRESULT __stdcall get_DropResult(Windows::ApplicationModel::DataTransfer::DataPackageOperation * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DropResult());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IDurationHelper> : produce_base<D, Windows::UI::Xaml::IDurationHelper>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::IDurationHelperStatics> : produce_base<D, Windows::UI::Xaml::IDurationHelperStatics>
{
    HRESULT __stdcall get_Automatic(impl::abi_arg_out<Windows::UI::Xaml::Duration> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Automatic());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Forever(impl::abi_arg_out<Windows::UI::Xaml::Duration> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Forever());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Compare(impl::abi_arg_in<Windows::UI::Xaml::Duration> duration1, impl::abi_arg_in<Windows::UI::Xaml::Duration> duration2, int32_t * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().Compare(*reinterpret_cast<const Windows::UI::Xaml::Duration *>(&duration1), *reinterpret_cast<const Windows::UI::Xaml::Duration *>(&duration2)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromTimeSpan(impl::abi_arg_in<Windows::Foundation::TimeSpan> timeSpan, impl::abi_arg_out<Windows::UI::Xaml::Duration> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().FromTimeSpan(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&timeSpan)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetHasTimeSpan(impl::abi_arg_in<Windows::UI::Xaml::Duration> target, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetHasTimeSpan(*reinterpret_cast<const Windows::UI::Xaml::Duration *>(&target)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Add(impl::abi_arg_in<Windows::UI::Xaml::Duration> target, impl::abi_arg_in<Windows::UI::Xaml::Duration> duration, impl::abi_arg_out<Windows::UI::Xaml::Duration> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().Add(*reinterpret_cast<const Windows::UI::Xaml::Duration *>(&target), *reinterpret_cast<const Windows::UI::Xaml::Duration *>(&duration)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Equals(impl::abi_arg_in<Windows::UI::Xaml::Duration> target, impl::abi_arg_in<Windows::UI::Xaml::Duration> value, bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().Equals(*reinterpret_cast<const Windows::UI::Xaml::Duration *>(&target), *reinterpret_cast<const Windows::UI::Xaml::Duration *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Subtract(impl::abi_arg_in<Windows::UI::Xaml::Duration> target, impl::abi_arg_in<Windows::UI::Xaml::Duration> duration, impl::abi_arg_out<Windows::UI::Xaml::Duration> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().Subtract(*reinterpret_cast<const Windows::UI::Xaml::Duration *>(&target), *reinterpret_cast<const Windows::UI::Xaml::Duration *>(&duration)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IElementSoundPlayer> : produce_base<D, Windows::UI::Xaml::IElementSoundPlayer>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::IElementSoundPlayerStatics> : produce_base<D, Windows::UI::Xaml::IElementSoundPlayerStatics>
{
    HRESULT __stdcall get_Volume(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Volume());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Volume(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Volume(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_State(Windows::UI::Xaml::ElementSoundPlayerState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().State());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_State(Windows::UI::Xaml::ElementSoundPlayerState value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().State(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Play(Windows::UI::Xaml::ElementSoundKind sound) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Play(sound);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IEventTrigger> : produce_base<D, Windows::UI::Xaml::IEventTrigger>
{
    HRESULT __stdcall get_RoutedEvent(impl::abi_arg_out<Windows::UI::Xaml::IRoutedEvent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RoutedEvent());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RoutedEvent(impl::abi_arg_in<Windows::UI::Xaml::IRoutedEvent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RoutedEvent(*reinterpret_cast<const Windows::UI::Xaml::RoutedEvent *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Actions(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::TriggerAction>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Actions());
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
struct produce<D, Windows::UI::Xaml::IExceptionRoutedEventArgs> : produce_base<D, Windows::UI::Xaml::IExceptionRoutedEventArgs>
{
    HRESULT __stdcall get_ErrorMessage(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ErrorMessage());
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
struct produce<D, Windows::UI::Xaml::IExceptionRoutedEventArgsFactory> : produce_base<D, Windows::UI::Xaml::IExceptionRoutedEventArgsFactory>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::IFrameworkElement> : produce_base<D, Windows::UI::Xaml::IFrameworkElement>
{
    HRESULT __stdcall get_Triggers(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::TriggerBase>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Triggers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Resources(impl::abi_arg_out<Windows::UI::Xaml::IResourceDictionary> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Resources());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Resources(impl::abi_arg_in<Windows::UI::Xaml::IResourceDictionary> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Resources(*reinterpret_cast<const Windows::UI::Xaml::ResourceDictionary *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Tag(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Tag());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Tag(impl::abi_arg_in<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Tag(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Language(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Language());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Language(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Language(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ActualWidth(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ActualWidth());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ActualHeight(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ActualHeight());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Width(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Width());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Width(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Width(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Height(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Height());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Height(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Height(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinWidth(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinWidth());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MinWidth(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MinWidth(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxWidth(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxWidth());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxWidth(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxWidth(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinHeight(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinHeight());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MinHeight(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MinHeight(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxHeight(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxHeight());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxHeight(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxHeight(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HorizontalAlignment(Windows::UI::Xaml::HorizontalAlignment * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HorizontalAlignment());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_HorizontalAlignment(Windows::UI::Xaml::HorizontalAlignment value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HorizontalAlignment(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VerticalAlignment(Windows::UI::Xaml::VerticalAlignment * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VerticalAlignment());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_VerticalAlignment(Windows::UI::Xaml::VerticalAlignment value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VerticalAlignment(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Margin(impl::abi_arg_out<Windows::UI::Xaml::Thickness> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Margin());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Margin(impl::abi_arg_in<Windows::UI::Xaml::Thickness> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Margin(*reinterpret_cast<const Windows::UI::Xaml::Thickness *>(&value));
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

    HRESULT __stdcall put_Name(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Name(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BaseUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BaseUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DataContext(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DataContext());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DataContext(impl::abi_arg_in<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DataContext(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Style(impl::abi_arg_out<Windows::UI::Xaml::IStyle> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Style());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Style(impl::abi_arg_in<Windows::UI::Xaml::IStyle> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Style(*reinterpret_cast<const Windows::UI::Xaml::Style *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Parent(impl::abi_arg_out<Windows::UI::Xaml::IDependencyObject> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Parent());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FlowDirection(Windows::UI::Xaml::FlowDirection * value) noexcept override
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

    HRESULT __stdcall put_FlowDirection(Windows::UI::Xaml::FlowDirection value) noexcept override
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

    HRESULT __stdcall add_Loaded(impl::abi_arg_in<Windows::UI::Xaml::RoutedEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Loaded(*reinterpret_cast<const Windows::UI::Xaml::RoutedEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Loaded(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Loaded(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Unloaded(impl::abi_arg_in<Windows::UI::Xaml::RoutedEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Unloaded(*reinterpret_cast<const Windows::UI::Xaml::RoutedEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Unloaded(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Unloaded(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_SizeChanged(impl::abi_arg_in<Windows::UI::Xaml::SizeChangedEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().SizeChanged(*reinterpret_cast<const Windows::UI::Xaml::SizeChangedEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SizeChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SizeChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_LayoutUpdated(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Foundation::IInspectable>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().LayoutUpdated(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_LayoutUpdated(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LayoutUpdated(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindName(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::Foundation::IInspectable> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().FindName(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetBinding(impl::abi_arg_in<Windows::UI::Xaml::IDependencyProperty> dp, impl::abi_arg_in<Windows::UI::Xaml::Data::IBindingBase> binding) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetBinding(*reinterpret_cast<const Windows::UI::Xaml::DependencyProperty *>(&dp), *reinterpret_cast<const Windows::UI::Xaml::Data::BindingBase *>(&binding));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IFrameworkElement2> : produce_base<D, Windows::UI::Xaml::IFrameworkElement2>
{
    HRESULT __stdcall get_RequestedTheme(Windows::UI::Xaml::ElementTheme * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequestedTheme());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RequestedTheme(Windows::UI::Xaml::ElementTheme value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequestedTheme(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_DataContextChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::DataContextChangedEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().DataContextChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::DataContextChangedEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DataContextChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DataContextChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetBindingExpression(impl::abi_arg_in<Windows::UI::Xaml::IDependencyProperty> dp, impl::abi_arg_out<Windows::UI::Xaml::Data::IBindingExpression> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetBindingExpression(*reinterpret_cast<const Windows::UI::Xaml::DependencyProperty *>(&dp)));
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
struct produce<D, Windows::UI::Xaml::IFrameworkElement3> : produce_base<D, Windows::UI::Xaml::IFrameworkElement3>
{
    HRESULT __stdcall add_Loading(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::FrameworkElement, Windows::Foundation::IInspectable>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Loading(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::FrameworkElement, Windows::Foundation::IInspectable> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Loading(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Loading(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IFrameworkElement4> : produce_base<D, Windows::UI::Xaml::IFrameworkElement4>
{
    HRESULT __stdcall get_AllowFocusOnInteraction(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllowFocusOnInteraction());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AllowFocusOnInteraction(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowFocusOnInteraction(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FocusVisualMargin(impl::abi_arg_out<Windows::UI::Xaml::Thickness> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FocusVisualMargin());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FocusVisualMargin(impl::abi_arg_in<Windows::UI::Xaml::Thickness> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FocusVisualMargin(*reinterpret_cast<const Windows::UI::Xaml::Thickness *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FocusVisualSecondaryThickness(impl::abi_arg_out<Windows::UI::Xaml::Thickness> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FocusVisualSecondaryThickness());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FocusVisualSecondaryThickness(impl::abi_arg_in<Windows::UI::Xaml::Thickness> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FocusVisualSecondaryThickness(*reinterpret_cast<const Windows::UI::Xaml::Thickness *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FocusVisualPrimaryThickness(impl::abi_arg_out<Windows::UI::Xaml::Thickness> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FocusVisualPrimaryThickness());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FocusVisualPrimaryThickness(impl::abi_arg_in<Windows::UI::Xaml::Thickness> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FocusVisualPrimaryThickness(*reinterpret_cast<const Windows::UI::Xaml::Thickness *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FocusVisualSecondaryBrush(impl::abi_arg_out<Windows::UI::Xaml::Media::IBrush> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FocusVisualSecondaryBrush());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FocusVisualSecondaryBrush(impl::abi_arg_in<Windows::UI::Xaml::Media::IBrush> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FocusVisualSecondaryBrush(*reinterpret_cast<const Windows::UI::Xaml::Media::Brush *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FocusVisualPrimaryBrush(impl::abi_arg_out<Windows::UI::Xaml::Media::IBrush> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FocusVisualPrimaryBrush());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FocusVisualPrimaryBrush(impl::abi_arg_in<Windows::UI::Xaml::Media::IBrush> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FocusVisualPrimaryBrush(*reinterpret_cast<const Windows::UI::Xaml::Media::Brush *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AllowFocusWhenDisabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllowFocusWhenDisabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AllowFocusWhenDisabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowFocusWhenDisabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IFrameworkElementFactory> : produce_base<D, Windows::UI::Xaml::IFrameworkElementFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::IFrameworkElement> instance) noexcept override
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
struct produce<D, Windows::UI::Xaml::IFrameworkElementOverrides> : produce_base<D, Windows::UI::Xaml::IFrameworkElementOverrides>
{
    HRESULT __stdcall abi_MeasureOverride(impl::abi_arg_in<Windows::Foundation::Size> availableSize, impl::abi_arg_out<Windows::Foundation::Size> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().MeasureOverride(*reinterpret_cast<const Windows::Foundation::Size *>(&availableSize)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ArrangeOverride(impl::abi_arg_in<Windows::Foundation::Size> finalSize, impl::abi_arg_out<Windows::Foundation::Size> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().ArrangeOverride(*reinterpret_cast<const Windows::Foundation::Size *>(&finalSize)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnApplyTemplate() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnApplyTemplate();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IFrameworkElementOverrides2> : produce_base<D, Windows::UI::Xaml::IFrameworkElementOverrides2>
{
    HRESULT __stdcall abi_GoToElementStateCore(impl::abi_arg_in<hstring> stateName, bool useTransitions, bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GoToElementStateCore(*reinterpret_cast<const hstring *>(&stateName), useTransitions));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IFrameworkElementStatics> : produce_base<D, Windows::UI::Xaml::IFrameworkElementStatics>
{
    HRESULT __stdcall get_TagProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TagProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LanguageProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LanguageProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ActualWidthProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ActualWidthProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ActualHeightProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ActualHeightProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WidthProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WidthProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HeightProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HeightProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinWidthProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinWidthProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxWidthProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxWidthProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinHeightProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinHeightProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxHeightProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxHeightProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HorizontalAlignmentProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HorizontalAlignmentProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VerticalAlignmentProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VerticalAlignmentProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MarginProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MarginProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NameProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NameProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DataContextProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DataContextProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StyleProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StyleProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FlowDirectionProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FlowDirectionProperty());
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
struct produce<D, Windows::UI::Xaml::IFrameworkElementStatics2> : produce_base<D, Windows::UI::Xaml::IFrameworkElementStatics2>
{
    HRESULT __stdcall get_RequestedThemeProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequestedThemeProperty());
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
struct produce<D, Windows::UI::Xaml::IFrameworkElementStatics4> : produce_base<D, Windows::UI::Xaml::IFrameworkElementStatics4>
{
    HRESULT __stdcall get_AllowFocusOnInteractionProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllowFocusOnInteractionProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FocusVisualMarginProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FocusVisualMarginProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FocusVisualSecondaryThicknessProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FocusVisualSecondaryThicknessProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FocusVisualPrimaryThicknessProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FocusVisualPrimaryThicknessProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FocusVisualSecondaryBrushProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FocusVisualSecondaryBrushProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FocusVisualPrimaryBrushProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FocusVisualPrimaryBrushProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AllowFocusWhenDisabledProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllowFocusWhenDisabledProperty());
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
struct produce<D, Windows::UI::Xaml::IFrameworkTemplate> : produce_base<D, Windows::UI::Xaml::IFrameworkTemplate>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::IFrameworkTemplateFactory> : produce_base<D, Windows::UI::Xaml::IFrameworkTemplateFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::IFrameworkTemplate> instance) noexcept override
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
struct produce<D, Windows::UI::Xaml::IFrameworkView> : produce_base<D, Windows::UI::Xaml::IFrameworkView>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::IFrameworkViewSource> : produce_base<D, Windows::UI::Xaml::IFrameworkViewSource>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::IGridLengthHelper> : produce_base<D, Windows::UI::Xaml::IGridLengthHelper>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::IGridLengthHelperStatics> : produce_base<D, Windows::UI::Xaml::IGridLengthHelperStatics>
{
    HRESULT __stdcall get_Auto(impl::abi_arg_out<Windows::UI::Xaml::GridLength> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Auto());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromPixels(double pixels, impl::abi_arg_out<Windows::UI::Xaml::GridLength> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().FromPixels(pixels));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromValueAndType(double value, Windows::UI::Xaml::GridUnitType type, impl::abi_arg_out<Windows::UI::Xaml::GridLength> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().FromValueAndType(value, type));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetIsAbsolute(impl::abi_arg_in<Windows::UI::Xaml::GridLength> target, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetIsAbsolute(*reinterpret_cast<const Windows::UI::Xaml::GridLength *>(&target)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetIsAuto(impl::abi_arg_in<Windows::UI::Xaml::GridLength> target, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetIsAuto(*reinterpret_cast<const Windows::UI::Xaml::GridLength *>(&target)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetIsStar(impl::abi_arg_in<Windows::UI::Xaml::GridLength> target, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetIsStar(*reinterpret_cast<const Windows::UI::Xaml::GridLength *>(&target)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Equals(impl::abi_arg_in<Windows::UI::Xaml::GridLength> target, impl::abi_arg_in<Windows::UI::Xaml::GridLength> value, bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().Equals(*reinterpret_cast<const Windows::UI::Xaml::GridLength *>(&target), *reinterpret_cast<const Windows::UI::Xaml::GridLength *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IMediaFailedRoutedEventArgs> : produce_base<D, Windows::UI::Xaml::IMediaFailedRoutedEventArgs>
{
    HRESULT __stdcall get_ErrorTrace(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ErrorTrace());
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
struct produce<D, Windows::UI::Xaml::IPointHelper> : produce_base<D, Windows::UI::Xaml::IPointHelper>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::IPointHelperStatics> : produce_base<D, Windows::UI::Xaml::IPointHelperStatics>
{
    HRESULT __stdcall abi_FromCoordinates(float x, float y, impl::abi_arg_out<Windows::Foundation::Point> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().FromCoordinates(x, y));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IPropertyMetadata> : produce_base<D, Windows::UI::Xaml::IPropertyMetadata>
{
    HRESULT __stdcall get_DefaultValue(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DefaultValue());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CreateDefaultValueCallback(impl::abi_arg_out<Windows::UI::Xaml::CreateDefaultValueCallback> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateDefaultValueCallback());
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
struct produce<D, Windows::UI::Xaml::IPropertyMetadataFactory> : produce_base<D, Windows::UI::Xaml::IPropertyMetadataFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithDefaultValue(impl::abi_arg_in<Windows::Foundation::IInspectable> defaultValue, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::IPropertyMetadata> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithDefaultValue(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&defaultValue), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
            return S_OK;
        }
        catch (...)
        {
            *inner = nullptr;
            *instance = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateInstanceWithDefaultValueAndCallback(impl::abi_arg_in<Windows::Foundation::IInspectable> defaultValue, impl::abi_arg_in<Windows::UI::Xaml::PropertyChangedCallback> propertyChangedCallback, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::IPropertyMetadata> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithDefaultValueAndCallback(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&defaultValue), *reinterpret_cast<const Windows::UI::Xaml::PropertyChangedCallback *>(&propertyChangedCallback), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
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
struct produce<D, Windows::UI::Xaml::IPropertyMetadataStatics> : produce_base<D, Windows::UI::Xaml::IPropertyMetadataStatics>
{
    HRESULT __stdcall abi_CreateWithDefaultValue(impl::abi_arg_in<Windows::Foundation::IInspectable> defaultValue, impl::abi_arg_out<Windows::UI::Xaml::IPropertyMetadata> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&defaultValue)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithDefaultValueAndCallback(impl::abi_arg_in<Windows::Foundation::IInspectable> defaultValue, impl::abi_arg_in<Windows::UI::Xaml::PropertyChangedCallback> propertyChangedCallback, impl::abi_arg_out<Windows::UI::Xaml::IPropertyMetadata> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&defaultValue), *reinterpret_cast<const Windows::UI::Xaml::PropertyChangedCallback *>(&propertyChangedCallback)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithFactory(impl::abi_arg_in<Windows::UI::Xaml::CreateDefaultValueCallback> createDefaultValueCallback, impl::abi_arg_out<Windows::UI::Xaml::IPropertyMetadata> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::UI::Xaml::CreateDefaultValueCallback *>(&createDefaultValueCallback)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithFactoryAndCallback(impl::abi_arg_in<Windows::UI::Xaml::CreateDefaultValueCallback> createDefaultValueCallback, impl::abi_arg_in<Windows::UI::Xaml::PropertyChangedCallback> propertyChangedCallback, impl::abi_arg_out<Windows::UI::Xaml::IPropertyMetadata> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::UI::Xaml::CreateDefaultValueCallback *>(&createDefaultValueCallback), *reinterpret_cast<const Windows::UI::Xaml::PropertyChangedCallback *>(&propertyChangedCallback)));
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
struct produce<D, Windows::UI::Xaml::IPropertyPath> : produce_base<D, Windows::UI::Xaml::IPropertyPath>
{
    HRESULT __stdcall get_Path(impl::abi_arg_out<hstring> value) noexcept override
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
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IPropertyPathFactory> : produce_base<D, Windows::UI::Xaml::IPropertyPathFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<hstring> path, impl::abi_arg_out<Windows::UI::Xaml::IPropertyPath> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstance(*reinterpret_cast<const hstring *>(&path)));
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
struct produce<D, Windows::UI::Xaml::IRectHelper> : produce_base<D, Windows::UI::Xaml::IRectHelper>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::IRectHelperStatics> : produce_base<D, Windows::UI::Xaml::IRectHelperStatics>
{
    HRESULT __stdcall get_Empty(impl::abi_arg_out<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Empty());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromCoordinatesAndDimensions(float x, float y, float width, float height, impl::abi_arg_out<Windows::Foundation::Rect> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().FromCoordinatesAndDimensions(x, y, width, height));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromPoints(impl::abi_arg_in<Windows::Foundation::Point> point1, impl::abi_arg_in<Windows::Foundation::Point> point2, impl::abi_arg_out<Windows::Foundation::Rect> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().FromPoints(*reinterpret_cast<const Windows::Foundation::Point *>(&point1), *reinterpret_cast<const Windows::Foundation::Point *>(&point2)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromLocationAndSize(impl::abi_arg_in<Windows::Foundation::Point> location, impl::abi_arg_in<Windows::Foundation::Size> size, impl::abi_arg_out<Windows::Foundation::Rect> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().FromLocationAndSize(*reinterpret_cast<const Windows::Foundation::Point *>(&location), *reinterpret_cast<const Windows::Foundation::Size *>(&size)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetIsEmpty(impl::abi_arg_in<Windows::Foundation::Rect> target, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetIsEmpty(*reinterpret_cast<const Windows::Foundation::Rect *>(&target)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetBottom(impl::abi_arg_in<Windows::Foundation::Rect> target, float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetBottom(*reinterpret_cast<const Windows::Foundation::Rect *>(&target)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetLeft(impl::abi_arg_in<Windows::Foundation::Rect> target, float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetLeft(*reinterpret_cast<const Windows::Foundation::Rect *>(&target)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetRight(impl::abi_arg_in<Windows::Foundation::Rect> target, float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetRight(*reinterpret_cast<const Windows::Foundation::Rect *>(&target)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetTop(impl::abi_arg_in<Windows::Foundation::Rect> target, float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetTop(*reinterpret_cast<const Windows::Foundation::Rect *>(&target)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Contains(impl::abi_arg_in<Windows::Foundation::Rect> target, impl::abi_arg_in<Windows::Foundation::Point> point, bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().Contains(*reinterpret_cast<const Windows::Foundation::Rect *>(&target), *reinterpret_cast<const Windows::Foundation::Point *>(&point)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Equals(impl::abi_arg_in<Windows::Foundation::Rect> target, impl::abi_arg_in<Windows::Foundation::Rect> value, bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().Equals(*reinterpret_cast<const Windows::Foundation::Rect *>(&target), *reinterpret_cast<const Windows::Foundation::Rect *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Intersect(impl::abi_arg_in<Windows::Foundation::Rect> target, impl::abi_arg_in<Windows::Foundation::Rect> rect, impl::abi_arg_out<Windows::Foundation::Rect> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().Intersect(*reinterpret_cast<const Windows::Foundation::Rect *>(&target), *reinterpret_cast<const Windows::Foundation::Rect *>(&rect)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UnionWithPoint(impl::abi_arg_in<Windows::Foundation::Rect> target, impl::abi_arg_in<Windows::Foundation::Point> point, impl::abi_arg_out<Windows::Foundation::Rect> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().Union(*reinterpret_cast<const Windows::Foundation::Rect *>(&target), *reinterpret_cast<const Windows::Foundation::Point *>(&point)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UnionWithRect(impl::abi_arg_in<Windows::Foundation::Rect> target, impl::abi_arg_in<Windows::Foundation::Rect> rect, impl::abi_arg_out<Windows::Foundation::Rect> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().Union(*reinterpret_cast<const Windows::Foundation::Rect *>(&target), *reinterpret_cast<const Windows::Foundation::Rect *>(&rect)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IResourceDictionary> : produce_base<D, Windows::UI::Xaml::IResourceDictionary>
{
    HRESULT __stdcall get_Source(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
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

    HRESULT __stdcall put_Source(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Source(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MergedDictionaries(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::ResourceDictionary>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MergedDictionaries());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ThemeDictionaries(impl::abi_arg_out<Windows::Foundation::Collections::IMap<Windows::Foundation::IInspectable, Windows::Foundation::IInspectable>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ThemeDictionaries());
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
struct produce<D, Windows::UI::Xaml::IResourceDictionaryFactory> : produce_base<D, Windows::UI::Xaml::IResourceDictionaryFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::IResourceDictionary> instance) noexcept override
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
struct produce<D, Windows::UI::Xaml::IRoutedEvent> : produce_base<D, Windows::UI::Xaml::IRoutedEvent>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::IRoutedEventArgs> : produce_base<D, Windows::UI::Xaml::IRoutedEventArgs>
{
    HRESULT __stdcall get_OriginalSource(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OriginalSource());
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
struct produce<D, Windows::UI::Xaml::IRoutedEventArgsFactory> : produce_base<D, Windows::UI::Xaml::IRoutedEventArgsFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::IRoutedEventArgs> instance) noexcept override
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
struct produce<D, Windows::UI::Xaml::ISetter> : produce_base<D, Windows::UI::Xaml::ISetter>
{
    HRESULT __stdcall get_Property(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Property());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Property(impl::abi_arg_in<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Property(*reinterpret_cast<const Windows::UI::Xaml::DependencyProperty *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Value(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
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

    HRESULT __stdcall put_Value(impl::abi_arg_in<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Value(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::ISetter2> : produce_base<D, Windows::UI::Xaml::ISetter2>
{
    HRESULT __stdcall get_Target(impl::abi_arg_out<Windows::UI::Xaml::ITargetPropertyPath> value) noexcept override
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

    HRESULT __stdcall put_Target(impl::abi_arg_in<Windows::UI::Xaml::ITargetPropertyPath> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Target(*reinterpret_cast<const Windows::UI::Xaml::TargetPropertyPath *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::ISetterBase> : produce_base<D, Windows::UI::Xaml::ISetterBase>
{
    HRESULT __stdcall get_IsSealed(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsSealed());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::ISetterBaseCollection> : produce_base<D, Windows::UI::Xaml::ISetterBaseCollection>
{
    HRESULT __stdcall get_IsSealed(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsSealed());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::ISetterBaseFactory> : produce_base<D, Windows::UI::Xaml::ISetterBaseFactory>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::ISetterFactory> : produce_base<D, Windows::UI::Xaml::ISetterFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::UI::Xaml::IDependencyProperty> targetProperty, impl::abi_arg_in<Windows::Foundation::IInspectable> value, impl::abi_arg_out<Windows::UI::Xaml::ISetter> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstance(*reinterpret_cast<const Windows::UI::Xaml::DependencyProperty *>(&targetProperty), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&value)));
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
struct produce<D, Windows::UI::Xaml::ISizeChangedEventArgs> : produce_base<D, Windows::UI::Xaml::ISizeChangedEventArgs>
{
    HRESULT __stdcall get_PreviousSize(impl::abi_arg_out<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PreviousSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NewSize(impl::abi_arg_out<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NewSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::ISizeHelper> : produce_base<D, Windows::UI::Xaml::ISizeHelper>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::ISizeHelperStatics> : produce_base<D, Windows::UI::Xaml::ISizeHelperStatics>
{
    HRESULT __stdcall get_Empty(impl::abi_arg_out<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Empty());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromDimensions(float width, float height, impl::abi_arg_out<Windows::Foundation::Size> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().FromDimensions(width, height));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetIsEmpty(impl::abi_arg_in<Windows::Foundation::Size> target, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetIsEmpty(*reinterpret_cast<const Windows::Foundation::Size *>(&target)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Equals(impl::abi_arg_in<Windows::Foundation::Size> target, impl::abi_arg_in<Windows::Foundation::Size> value, bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().Equals(*reinterpret_cast<const Windows::Foundation::Size *>(&target), *reinterpret_cast<const Windows::Foundation::Size *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IStateTrigger> : produce_base<D, Windows::UI::Xaml::IStateTrigger>
{
    HRESULT __stdcall get_IsActive(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsActive());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsActive(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsActive(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IStateTriggerBase> : produce_base<D, Windows::UI::Xaml::IStateTriggerBase>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::IStateTriggerBaseFactory> : produce_base<D, Windows::UI::Xaml::IStateTriggerBaseFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::IStateTriggerBase> instance) noexcept override
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
struct produce<D, Windows::UI::Xaml::IStateTriggerBaseProtected> : produce_base<D, Windows::UI::Xaml::IStateTriggerBaseProtected>
{
    HRESULT __stdcall abi_SetActive(bool IsActive) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetActive(IsActive);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IStateTriggerStatics> : produce_base<D, Windows::UI::Xaml::IStateTriggerStatics>
{
    HRESULT __stdcall get_IsActiveProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsActiveProperty());
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
struct produce<D, Windows::UI::Xaml::IStyle> : produce_base<D, Windows::UI::Xaml::IStyle>
{
    HRESULT __stdcall get_IsSealed(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsSealed());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Setters(impl::abi_arg_out<Windows::UI::Xaml::ISetterBaseCollection> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Setters());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TargetType(impl::abi_arg_out<Windows::UI::Xaml::Interop::TypeName> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TargetType(impl::abi_arg_in<Windows::UI::Xaml::Interop::TypeName> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TargetType(*reinterpret_cast<const Windows::UI::Xaml::Interop::TypeName *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BasedOn(impl::abi_arg_out<Windows::UI::Xaml::IStyle> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BasedOn());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BasedOn(impl::abi_arg_in<Windows::UI::Xaml::IStyle> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BasedOn(*reinterpret_cast<const Windows::UI::Xaml::Style *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Seal() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Seal();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IStyleFactory> : produce_base<D, Windows::UI::Xaml::IStyleFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::UI::Xaml::Interop::TypeName> targetType, impl::abi_arg_out<Windows::UI::Xaml::IStyle> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstance(*reinterpret_cast<const Windows::UI::Xaml::Interop::TypeName *>(&targetType)));
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
struct produce<D, Windows::UI::Xaml::ITargetPropertyPath> : produce_base<D, Windows::UI::Xaml::ITargetPropertyPath>
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

    HRESULT __stdcall get_Target(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
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

    HRESULT __stdcall put_Target(impl::abi_arg_in<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Target(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::ITargetPropertyPathFactory> : produce_base<D, Windows::UI::Xaml::ITargetPropertyPathFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::UI::Xaml::IDependencyProperty> targetProperty, impl::abi_arg_out<Windows::UI::Xaml::ITargetPropertyPath> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstance(*reinterpret_cast<const Windows::UI::Xaml::DependencyProperty *>(&targetProperty)));
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
struct produce<D, Windows::UI::Xaml::IThicknessHelper> : produce_base<D, Windows::UI::Xaml::IThicknessHelper>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::IThicknessHelperStatics> : produce_base<D, Windows::UI::Xaml::IThicknessHelperStatics>
{
    HRESULT __stdcall abi_FromLengths(double left, double top, double right, double bottom, impl::abi_arg_out<Windows::UI::Xaml::Thickness> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().FromLengths(left, top, right, bottom));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromUniformLength(double uniformLength, impl::abi_arg_out<Windows::UI::Xaml::Thickness> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().FromUniformLength(uniformLength));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::ITriggerAction> : produce_base<D, Windows::UI::Xaml::ITriggerAction>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::ITriggerActionFactory> : produce_base<D, Windows::UI::Xaml::ITriggerActionFactory>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::ITriggerBase> : produce_base<D, Windows::UI::Xaml::ITriggerBase>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::ITriggerBaseFactory> : produce_base<D, Windows::UI::Xaml::ITriggerBaseFactory>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::IUIElement> : produce_base<D, Windows::UI::Xaml::IUIElement>
{
    HRESULT __stdcall get_DesiredSize(impl::abi_arg_out<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DesiredSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AllowDrop(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllowDrop());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AllowDrop(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowDrop(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Opacity(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Opacity());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Opacity(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Opacity(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Clip(impl::abi_arg_out<Windows::UI::Xaml::Media::IRectangleGeometry> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Clip());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Clip(impl::abi_arg_in<Windows::UI::Xaml::Media::IRectangleGeometry> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Clip(*reinterpret_cast<const Windows::UI::Xaml::Media::RectangleGeometry *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RenderTransform(impl::abi_arg_out<Windows::UI::Xaml::Media::ITransform> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RenderTransform());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RenderTransform(impl::abi_arg_in<Windows::UI::Xaml::Media::ITransform> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RenderTransform(*reinterpret_cast<const Windows::UI::Xaml::Media::Transform *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Projection(impl::abi_arg_out<Windows::UI::Xaml::Media::IProjection> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Projection());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Projection(impl::abi_arg_in<Windows::UI::Xaml::Media::IProjection> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Projection(*reinterpret_cast<const Windows::UI::Xaml::Media::Projection *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RenderTransformOrigin(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RenderTransformOrigin());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RenderTransformOrigin(impl::abi_arg_in<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RenderTransformOrigin(*reinterpret_cast<const Windows::Foundation::Point *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsHitTestVisible(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsHitTestVisible());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsHitTestVisible(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsHitTestVisible(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Visibility(Windows::UI::Xaml::Visibility * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Visibility());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Visibility(Windows::UI::Xaml::Visibility value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Visibility(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RenderSize(impl::abi_arg_out<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RenderSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UseLayoutRounding(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UseLayoutRounding());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_UseLayoutRounding(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UseLayoutRounding(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Transitions(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Animation::Transition>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Transitions());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Transitions(impl::abi_arg_in<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Animation::Transition>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Transitions(*reinterpret_cast<const Windows::UI::Xaml::Media::Animation::TransitionCollection *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CacheMode(impl::abi_arg_out<Windows::UI::Xaml::Media::ICacheMode> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CacheMode());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CacheMode(impl::abi_arg_in<Windows::UI::Xaml::Media::ICacheMode> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CacheMode(*reinterpret_cast<const Windows::UI::Xaml::Media::CacheMode *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsTapEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsTapEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsTapEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsTapEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsDoubleTapEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDoubleTapEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsDoubleTapEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsDoubleTapEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsRightTapEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsRightTapEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsRightTapEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsRightTapEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsHoldingEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsHoldingEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsHoldingEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsHoldingEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ManipulationMode(Windows::UI::Xaml::Input::ManipulationModes * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ManipulationMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ManipulationMode(Windows::UI::Xaml::Input::ManipulationModes value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ManipulationMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PointerCaptures(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Input::Pointer>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PointerCaptures());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_KeyUp(impl::abi_arg_in<Windows::UI::Xaml::Input::KeyEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().KeyUp(*reinterpret_cast<const Windows::UI::Xaml::Input::KeyEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_KeyUp(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().KeyUp(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_KeyDown(impl::abi_arg_in<Windows::UI::Xaml::Input::KeyEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().KeyDown(*reinterpret_cast<const Windows::UI::Xaml::Input::KeyEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_KeyDown(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().KeyDown(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_GotFocus(impl::abi_arg_in<Windows::UI::Xaml::RoutedEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().GotFocus(*reinterpret_cast<const Windows::UI::Xaml::RoutedEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_GotFocus(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GotFocus(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_LostFocus(impl::abi_arg_in<Windows::UI::Xaml::RoutedEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().LostFocus(*reinterpret_cast<const Windows::UI::Xaml::RoutedEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_LostFocus(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LostFocus(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_DragEnter(impl::abi_arg_in<Windows::UI::Xaml::DragEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().DragEnter(*reinterpret_cast<const Windows::UI::Xaml::DragEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DragEnter(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DragEnter(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_DragLeave(impl::abi_arg_in<Windows::UI::Xaml::DragEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().DragLeave(*reinterpret_cast<const Windows::UI::Xaml::DragEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DragLeave(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DragLeave(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_DragOver(impl::abi_arg_in<Windows::UI::Xaml::DragEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().DragOver(*reinterpret_cast<const Windows::UI::Xaml::DragEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DragOver(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DragOver(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Drop(impl::abi_arg_in<Windows::UI::Xaml::DragEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Drop(*reinterpret_cast<const Windows::UI::Xaml::DragEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Drop(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Drop(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PointerPressed(impl::abi_arg_in<Windows::UI::Xaml::Input::PointerEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().PointerPressed(*reinterpret_cast<const Windows::UI::Xaml::Input::PointerEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerPressed(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerPressed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PointerMoved(impl::abi_arg_in<Windows::UI::Xaml::Input::PointerEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().PointerMoved(*reinterpret_cast<const Windows::UI::Xaml::Input::PointerEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerMoved(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerMoved(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PointerReleased(impl::abi_arg_in<Windows::UI::Xaml::Input::PointerEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().PointerReleased(*reinterpret_cast<const Windows::UI::Xaml::Input::PointerEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerReleased(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerReleased(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PointerEntered(impl::abi_arg_in<Windows::UI::Xaml::Input::PointerEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().PointerEntered(*reinterpret_cast<const Windows::UI::Xaml::Input::PointerEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerEntered(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerEntered(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PointerExited(impl::abi_arg_in<Windows::UI::Xaml::Input::PointerEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().PointerExited(*reinterpret_cast<const Windows::UI::Xaml::Input::PointerEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerExited(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerExited(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PointerCaptureLost(impl::abi_arg_in<Windows::UI::Xaml::Input::PointerEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().PointerCaptureLost(*reinterpret_cast<const Windows::UI::Xaml::Input::PointerEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerCaptureLost(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerCaptureLost(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PointerCanceled(impl::abi_arg_in<Windows::UI::Xaml::Input::PointerEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().PointerCanceled(*reinterpret_cast<const Windows::UI::Xaml::Input::PointerEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerCanceled(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerCanceled(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PointerWheelChanged(impl::abi_arg_in<Windows::UI::Xaml::Input::PointerEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().PointerWheelChanged(*reinterpret_cast<const Windows::UI::Xaml::Input::PointerEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PointerWheelChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerWheelChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Tapped(impl::abi_arg_in<Windows::UI::Xaml::Input::TappedEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Tapped(*reinterpret_cast<const Windows::UI::Xaml::Input::TappedEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Tapped(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Tapped(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_DoubleTapped(impl::abi_arg_in<Windows::UI::Xaml::Input::DoubleTappedEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().DoubleTapped(*reinterpret_cast<const Windows::UI::Xaml::Input::DoubleTappedEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DoubleTapped(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DoubleTapped(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Holding(impl::abi_arg_in<Windows::UI::Xaml::Input::HoldingEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Holding(*reinterpret_cast<const Windows::UI::Xaml::Input::HoldingEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Holding(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Holding(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_RightTapped(impl::abi_arg_in<Windows::UI::Xaml::Input::RightTappedEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().RightTapped(*reinterpret_cast<const Windows::UI::Xaml::Input::RightTappedEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_RightTapped(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RightTapped(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ManipulationStarting(impl::abi_arg_in<Windows::UI::Xaml::Input::ManipulationStartingEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ManipulationStarting(*reinterpret_cast<const Windows::UI::Xaml::Input::ManipulationStartingEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ManipulationStarting(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ManipulationStarting(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ManipulationInertiaStarting(impl::abi_arg_in<Windows::UI::Xaml::Input::ManipulationInertiaStartingEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ManipulationInertiaStarting(*reinterpret_cast<const Windows::UI::Xaml::Input::ManipulationInertiaStartingEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ManipulationInertiaStarting(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ManipulationInertiaStarting(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ManipulationStarted(impl::abi_arg_in<Windows::UI::Xaml::Input::ManipulationStartedEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ManipulationStarted(*reinterpret_cast<const Windows::UI::Xaml::Input::ManipulationStartedEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ManipulationStarted(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ManipulationStarted(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ManipulationDelta(impl::abi_arg_in<Windows::UI::Xaml::Input::ManipulationDeltaEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ManipulationDelta(*reinterpret_cast<const Windows::UI::Xaml::Input::ManipulationDeltaEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ManipulationDelta(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ManipulationDelta(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ManipulationCompleted(impl::abi_arg_in<Windows::UI::Xaml::Input::ManipulationCompletedEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ManipulationCompleted(*reinterpret_cast<const Windows::UI::Xaml::Input::ManipulationCompletedEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ManipulationCompleted(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ManipulationCompleted(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Measure(impl::abi_arg_in<Windows::Foundation::Size> availableSize) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Measure(*reinterpret_cast<const Windows::Foundation::Size *>(&availableSize));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Arrange(impl::abi_arg_in<Windows::Foundation::Rect> finalRect) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Arrange(*reinterpret_cast<const Windows::Foundation::Rect *>(&finalRect));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CapturePointer(impl::abi_arg_in<Windows::UI::Xaml::Input::IPointer> value, bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().CapturePointer(*reinterpret_cast<const Windows::UI::Xaml::Input::Pointer *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReleasePointerCapture(impl::abi_arg_in<Windows::UI::Xaml::Input::IPointer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReleasePointerCapture(*reinterpret_cast<const Windows::UI::Xaml::Input::Pointer *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReleasePointerCaptures() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReleasePointerCaptures();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddHandler(impl::abi_arg_in<Windows::UI::Xaml::IRoutedEvent> routedEvent, impl::abi_arg_in<Windows::Foundation::IInspectable> handler, bool handledEventsToo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddHandler(*reinterpret_cast<const Windows::UI::Xaml::RoutedEvent *>(&routedEvent), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&handler), handledEventsToo);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveHandler(impl::abi_arg_in<Windows::UI::Xaml::IRoutedEvent> routedEvent, impl::abi_arg_in<Windows::Foundation::IInspectable> handler) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveHandler(*reinterpret_cast<const Windows::UI::Xaml::RoutedEvent *>(&routedEvent), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&handler));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TransformToVisual(impl::abi_arg_in<Windows::UI::Xaml::IUIElement> visual, impl::abi_arg_out<Windows::UI::Xaml::Media::IGeneralTransform> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().TransformToVisual(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&visual)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_InvalidateMeasure() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InvalidateMeasure();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_InvalidateArrange() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InvalidateArrange();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UpdateLayout() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UpdateLayout();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IUIElement2> : produce_base<D, Windows::UI::Xaml::IUIElement2>
{
    HRESULT __stdcall get_CompositeMode(Windows::UI::Xaml::Media::ElementCompositeMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CompositeMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CompositeMode(Windows::UI::Xaml::Media::ElementCompositeMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CompositeMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CancelDirectManipulations(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().CancelDirectManipulations());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IUIElement3> : produce_base<D, Windows::UI::Xaml::IUIElement3>
{
    HRESULT __stdcall get_Transform3D(impl::abi_arg_out<Windows::UI::Xaml::Media::Media3D::ITransform3D> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Transform3D());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Transform3D(impl::abi_arg_in<Windows::UI::Xaml::Media::Media3D::ITransform3D> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Transform3D(*reinterpret_cast<const Windows::UI::Xaml::Media::Media3D::Transform3D *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanDrag(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanDrag());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CanDrag(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanDrag(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_DragStarting(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::DragStartingEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().DragStarting(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::DragStartingEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DragStarting(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DragStarting(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_DropCompleted(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::DropCompletedEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().DropCompleted(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::DropCompletedEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DropCompleted(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DropCompleted(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartDragAsync(impl::abi_arg_in<Windows::UI::Input::IPointerPoint> pointerPoint, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::DataTransfer::DataPackageOperation>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().StartDragAsync(*reinterpret_cast<const Windows::UI::Input::PointerPoint *>(&pointerPoint)));
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
struct produce<D, Windows::UI::Xaml::IUIElement4> : produce_base<D, Windows::UI::Xaml::IUIElement4>
{
    HRESULT __stdcall get_ContextFlyout(impl::abi_arg_out<Windows::UI::Xaml::Controls::Primitives::IFlyoutBase> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContextFlyout());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ContextFlyout(impl::abi_arg_in<Windows::UI::Xaml::Controls::Primitives::IFlyoutBase> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContextFlyout(*reinterpret_cast<const Windows::UI::Xaml::Controls::Primitives::FlyoutBase *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExitDisplayModeOnAccessKeyInvoked(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExitDisplayModeOnAccessKeyInvoked());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ExitDisplayModeOnAccessKeyInvoked(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ExitDisplayModeOnAccessKeyInvoked(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsAccessKeyScope(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsAccessKeyScope());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsAccessKeyScope(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsAccessKeyScope(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AccessKeyScopeOwner(impl::abi_arg_out<Windows::UI::Xaml::IDependencyObject> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AccessKeyScopeOwner());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AccessKeyScopeOwner(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AccessKeyScopeOwner(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AccessKey(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AccessKey());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AccessKey(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AccessKey(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ContextRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::Input::ContextRequestedEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ContextRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::Input::ContextRequestedEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ContextRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContextRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ContextCanceled(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::RoutedEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ContextCanceled(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::RoutedEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ContextCanceled(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContextCanceled(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_AccessKeyDisplayRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::Input::AccessKeyDisplayRequestedEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().AccessKeyDisplayRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::Input::AccessKeyDisplayRequestedEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AccessKeyDisplayRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AccessKeyDisplayRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_AccessKeyDisplayDismissed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::Input::AccessKeyDisplayDismissedEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().AccessKeyDisplayDismissed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::Input::AccessKeyDisplayDismissedEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AccessKeyDisplayDismissed(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AccessKeyDisplayDismissed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_AccessKeyInvoked(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::Input::AccessKeyInvokedEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().AccessKeyInvoked(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::Input::AccessKeyInvokedEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AccessKeyInvoked(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AccessKeyInvoked(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IUIElementFactory> : produce_base<D, Windows::UI::Xaml::IUIElementFactory>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::IUIElementOverrides> : produce_base<D, Windows::UI::Xaml::IUIElementOverrides>
{
    HRESULT __stdcall abi_OnCreateAutomationPeer(impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IAutomationPeer> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().OnCreateAutomationPeer());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OnDisconnectVisualChildren() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnDisconnectVisualChildren();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindSubElementsForTouchTargeting(impl::abi_arg_in<Windows::Foundation::Point> point, impl::abi_arg_in<Windows::Foundation::Rect> boundingRect, impl::abi_arg_out<Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IIterable<Windows::Foundation::Point>>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().FindSubElementsForTouchTargeting(*reinterpret_cast<const Windows::Foundation::Point *>(&point), *reinterpret_cast<const Windows::Foundation::Rect *>(&boundingRect)));
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
struct produce<D, Windows::UI::Xaml::IUIElementStatics> : produce_base<D, Windows::UI::Xaml::IUIElementStatics>
{
    HRESULT __stdcall get_KeyDownEvent(impl::abi_arg_out<Windows::UI::Xaml::IRoutedEvent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeyDownEvent());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_KeyUpEvent(impl::abi_arg_out<Windows::UI::Xaml::IRoutedEvent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeyUpEvent());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PointerEnteredEvent(impl::abi_arg_out<Windows::UI::Xaml::IRoutedEvent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PointerEnteredEvent());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PointerPressedEvent(impl::abi_arg_out<Windows::UI::Xaml::IRoutedEvent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PointerPressedEvent());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PointerMovedEvent(impl::abi_arg_out<Windows::UI::Xaml::IRoutedEvent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PointerMovedEvent());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PointerReleasedEvent(impl::abi_arg_out<Windows::UI::Xaml::IRoutedEvent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PointerReleasedEvent());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PointerExitedEvent(impl::abi_arg_out<Windows::UI::Xaml::IRoutedEvent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PointerExitedEvent());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PointerCaptureLostEvent(impl::abi_arg_out<Windows::UI::Xaml::IRoutedEvent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PointerCaptureLostEvent());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PointerCanceledEvent(impl::abi_arg_out<Windows::UI::Xaml::IRoutedEvent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PointerCanceledEvent());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PointerWheelChangedEvent(impl::abi_arg_out<Windows::UI::Xaml::IRoutedEvent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PointerWheelChangedEvent());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TappedEvent(impl::abi_arg_out<Windows::UI::Xaml::IRoutedEvent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TappedEvent());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DoubleTappedEvent(impl::abi_arg_out<Windows::UI::Xaml::IRoutedEvent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DoubleTappedEvent());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HoldingEvent(impl::abi_arg_out<Windows::UI::Xaml::IRoutedEvent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HoldingEvent());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RightTappedEvent(impl::abi_arg_out<Windows::UI::Xaml::IRoutedEvent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RightTappedEvent());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ManipulationStartingEvent(impl::abi_arg_out<Windows::UI::Xaml::IRoutedEvent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ManipulationStartingEvent());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ManipulationInertiaStartingEvent(impl::abi_arg_out<Windows::UI::Xaml::IRoutedEvent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ManipulationInertiaStartingEvent());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ManipulationStartedEvent(impl::abi_arg_out<Windows::UI::Xaml::IRoutedEvent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ManipulationStartedEvent());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ManipulationDeltaEvent(impl::abi_arg_out<Windows::UI::Xaml::IRoutedEvent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ManipulationDeltaEvent());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ManipulationCompletedEvent(impl::abi_arg_out<Windows::UI::Xaml::IRoutedEvent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ManipulationCompletedEvent());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DragEnterEvent(impl::abi_arg_out<Windows::UI::Xaml::IRoutedEvent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DragEnterEvent());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DragLeaveEvent(impl::abi_arg_out<Windows::UI::Xaml::IRoutedEvent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DragLeaveEvent());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DragOverEvent(impl::abi_arg_out<Windows::UI::Xaml::IRoutedEvent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DragOverEvent());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DropEvent(impl::abi_arg_out<Windows::UI::Xaml::IRoutedEvent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DropEvent());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AllowDropProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllowDropProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OpacityProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OpacityProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ClipProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ClipProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RenderTransformProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RenderTransformProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProjectionProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProjectionProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RenderTransformOriginProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RenderTransformOriginProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsHitTestVisibleProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsHitTestVisibleProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VisibilityProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VisibilityProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UseLayoutRoundingProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UseLayoutRoundingProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TransitionsProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TransitionsProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CacheModeProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CacheModeProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsTapEnabledProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsTapEnabledProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsDoubleTapEnabledProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDoubleTapEnabledProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsRightTapEnabledProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsRightTapEnabledProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsHoldingEnabledProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsHoldingEnabledProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ManipulationModeProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ManipulationModeProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PointerCapturesProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PointerCapturesProperty());
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
struct produce<D, Windows::UI::Xaml::IUIElementStatics2> : produce_base<D, Windows::UI::Xaml::IUIElementStatics2>
{
    HRESULT __stdcall get_CompositeModeProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CompositeModeProperty());
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
struct produce<D, Windows::UI::Xaml::IUIElementStatics3> : produce_base<D, Windows::UI::Xaml::IUIElementStatics3>
{
    HRESULT __stdcall get_Transform3DProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Transform3DProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanDragProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanDragProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryStartDirectManipulation(impl::abi_arg_in<Windows::UI::Xaml::Input::IPointer> value, bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().TryStartDirectManipulation(*reinterpret_cast<const Windows::UI::Xaml::Input::Pointer *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IUIElementStatics4> : produce_base<D, Windows::UI::Xaml::IUIElementStatics4>
{
    HRESULT __stdcall get_ContextFlyoutProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContextFlyoutProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExitDisplayModeOnAccessKeyInvokedProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExitDisplayModeOnAccessKeyInvokedProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsAccessKeyScopeProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsAccessKeyScopeProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AccessKeyScopeOwnerProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AccessKeyScopeOwnerProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AccessKeyProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AccessKeyProperty());
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
struct produce<D, Windows::UI::Xaml::IUnhandledExceptionEventArgs> : produce_base<D, Windows::UI::Xaml::IUnhandledExceptionEventArgs>
{
    HRESULT __stdcall get_Exception(HRESULT * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Exception());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Message(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Message());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
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
struct produce<D, Windows::UI::Xaml::IVisualState> : produce_base<D, Windows::UI::Xaml::IVisualState>
{
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

    HRESULT __stdcall get_Storyboard(impl::abi_arg_out<Windows::UI::Xaml::Media::Animation::IStoryboard> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Storyboard());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Storyboard(impl::abi_arg_in<Windows::UI::Xaml::Media::Animation::IStoryboard> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Storyboard(*reinterpret_cast<const Windows::UI::Xaml::Media::Animation::Storyboard *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IVisualState2> : produce_base<D, Windows::UI::Xaml::IVisualState2>
{
    HRESULT __stdcall get_Setters(impl::abi_arg_out<Windows::UI::Xaml::ISetterBaseCollection> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Setters());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StateTriggers(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::StateTriggerBase>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StateTriggers());
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
struct produce<D, Windows::UI::Xaml::IVisualStateChangedEventArgs> : produce_base<D, Windows::UI::Xaml::IVisualStateChangedEventArgs>
{
    HRESULT __stdcall get_OldState(impl::abi_arg_out<Windows::UI::Xaml::IVisualState> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OldState());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OldState(impl::abi_arg_in<Windows::UI::Xaml::IVisualState> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OldState(*reinterpret_cast<const Windows::UI::Xaml::VisualState *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NewState(impl::abi_arg_out<Windows::UI::Xaml::IVisualState> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NewState());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_NewState(impl::abi_arg_in<Windows::UI::Xaml::IVisualState> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NewState(*reinterpret_cast<const Windows::UI::Xaml::VisualState *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Control(impl::abi_arg_out<Windows::UI::Xaml::Controls::IControl> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Control());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Control(impl::abi_arg_in<Windows::UI::Xaml::Controls::IControl> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Control(*reinterpret_cast<const Windows::UI::Xaml::Controls::Control *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IVisualStateGroup> : produce_base<D, Windows::UI::Xaml::IVisualStateGroup>
{
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

    HRESULT __stdcall get_Transitions(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::VisualTransition>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Transitions());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_States(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::VisualState>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().States());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CurrentState(impl::abi_arg_out<Windows::UI::Xaml::IVisualState> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CurrentState());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_CurrentStateChanged(impl::abi_arg_in<Windows::UI::Xaml::VisualStateChangedEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().CurrentStateChanged(*reinterpret_cast<const Windows::UI::Xaml::VisualStateChangedEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CurrentStateChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CurrentStateChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_CurrentStateChanging(impl::abi_arg_in<Windows::UI::Xaml::VisualStateChangedEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().CurrentStateChanging(*reinterpret_cast<const Windows::UI::Xaml::VisualStateChangedEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CurrentStateChanging(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CurrentStateChanging(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IVisualStateManager> : produce_base<D, Windows::UI::Xaml::IVisualStateManager>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::IVisualStateManagerFactory> : produce_base<D, Windows::UI::Xaml::IVisualStateManagerFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::IVisualStateManager> instance) noexcept override
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
struct produce<D, Windows::UI::Xaml::IVisualStateManagerOverrides> : produce_base<D, Windows::UI::Xaml::IVisualStateManagerOverrides>
{
    HRESULT __stdcall abi_GoToStateCore(impl::abi_arg_in<Windows::UI::Xaml::Controls::IControl> control, impl::abi_arg_in<Windows::UI::Xaml::IFrameworkElement> templateRoot, impl::abi_arg_in<hstring> stateName, impl::abi_arg_in<Windows::UI::Xaml::IVisualStateGroup> group, impl::abi_arg_in<Windows::UI::Xaml::IVisualState> state, bool useTransitions, bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GoToStateCore(*reinterpret_cast<const Windows::UI::Xaml::Controls::Control *>(&control), *reinterpret_cast<const Windows::UI::Xaml::FrameworkElement *>(&templateRoot), *reinterpret_cast<const hstring *>(&stateName), *reinterpret_cast<const Windows::UI::Xaml::VisualStateGroup *>(&group), *reinterpret_cast<const Windows::UI::Xaml::VisualState *>(&state), useTransitions));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IVisualStateManagerProtected> : produce_base<D, Windows::UI::Xaml::IVisualStateManagerProtected>
{
    HRESULT __stdcall abi_RaiseCurrentStateChanging(impl::abi_arg_in<Windows::UI::Xaml::IVisualStateGroup> stateGroup, impl::abi_arg_in<Windows::UI::Xaml::IVisualState> oldState, impl::abi_arg_in<Windows::UI::Xaml::IVisualState> newState, impl::abi_arg_in<Windows::UI::Xaml::Controls::IControl> control) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RaiseCurrentStateChanging(*reinterpret_cast<const Windows::UI::Xaml::VisualStateGroup *>(&stateGroup), *reinterpret_cast<const Windows::UI::Xaml::VisualState *>(&oldState), *reinterpret_cast<const Windows::UI::Xaml::VisualState *>(&newState), *reinterpret_cast<const Windows::UI::Xaml::Controls::Control *>(&control));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RaiseCurrentStateChanged(impl::abi_arg_in<Windows::UI::Xaml::IVisualStateGroup> stateGroup, impl::abi_arg_in<Windows::UI::Xaml::IVisualState> oldState, impl::abi_arg_in<Windows::UI::Xaml::IVisualState> newState, impl::abi_arg_in<Windows::UI::Xaml::Controls::IControl> control) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RaiseCurrentStateChanged(*reinterpret_cast<const Windows::UI::Xaml::VisualStateGroup *>(&stateGroup), *reinterpret_cast<const Windows::UI::Xaml::VisualState *>(&oldState), *reinterpret_cast<const Windows::UI::Xaml::VisualState *>(&newState), *reinterpret_cast<const Windows::UI::Xaml::Controls::Control *>(&control));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IVisualStateManagerStatics> : produce_base<D, Windows::UI::Xaml::IVisualStateManagerStatics>
{
    HRESULT __stdcall abi_GetVisualStateGroups(impl::abi_arg_in<Windows::UI::Xaml::IFrameworkElement> obj, impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::VisualStateGroup>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetVisualStateGroups(*reinterpret_cast<const Windows::UI::Xaml::FrameworkElement *>(&obj)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CustomVisualStateManagerProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CustomVisualStateManagerProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCustomVisualStateManager(impl::abi_arg_in<Windows::UI::Xaml::IFrameworkElement> obj, impl::abi_arg_out<Windows::UI::Xaml::IVisualStateManager> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetCustomVisualStateManager(*reinterpret_cast<const Windows::UI::Xaml::FrameworkElement *>(&obj)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetCustomVisualStateManager(impl::abi_arg_in<Windows::UI::Xaml::IFrameworkElement> obj, impl::abi_arg_in<Windows::UI::Xaml::IVisualStateManager> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetCustomVisualStateManager(*reinterpret_cast<const Windows::UI::Xaml::FrameworkElement *>(&obj), *reinterpret_cast<const Windows::UI::Xaml::VisualStateManager *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GoToState(impl::abi_arg_in<Windows::UI::Xaml::Controls::IControl> control, impl::abi_arg_in<hstring> stateName, bool useTransitions, bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GoToState(*reinterpret_cast<const Windows::UI::Xaml::Controls::Control *>(&control), *reinterpret_cast<const hstring *>(&stateName), useTransitions));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IVisualTransition> : produce_base<D, Windows::UI::Xaml::IVisualTransition>
{
    HRESULT __stdcall get_GeneratedDuration(impl::abi_arg_out<Windows::UI::Xaml::Duration> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GeneratedDuration());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_GeneratedDuration(impl::abi_arg_in<Windows::UI::Xaml::Duration> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GeneratedDuration(*reinterpret_cast<const Windows::UI::Xaml::Duration *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GeneratedEasingFunction(impl::abi_arg_out<Windows::UI::Xaml::Media::Animation::IEasingFunctionBase> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GeneratedEasingFunction());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_GeneratedEasingFunction(impl::abi_arg_in<Windows::UI::Xaml::Media::Animation::IEasingFunctionBase> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GeneratedEasingFunction(*reinterpret_cast<const Windows::UI::Xaml::Media::Animation::EasingFunctionBase *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_To(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().To());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_To(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().To(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_From(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().From());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_From(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().From(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Storyboard(impl::abi_arg_out<Windows::UI::Xaml::Media::Animation::IStoryboard> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Storyboard());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Storyboard(impl::abi_arg_in<Windows::UI::Xaml::Media::Animation::IStoryboard> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Storyboard(*reinterpret_cast<const Windows::UI::Xaml::Media::Animation::Storyboard *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IVisualTransitionFactory> : produce_base<D, Windows::UI::Xaml::IVisualTransitionFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::IVisualTransition> instance) noexcept override
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
struct produce<D, Windows::UI::Xaml::IWindow> : produce_base<D, Windows::UI::Xaml::IWindow>
{
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

    HRESULT __stdcall get_Content(impl::abi_arg_out<Windows::UI::Xaml::IUIElement> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Content());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Content(impl::abi_arg_in<Windows::UI::Xaml::IUIElement> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Content(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CoreWindow(impl::abi_arg_out<Windows::UI::Core::ICoreWindow> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CoreWindow());
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

    HRESULT __stdcall add_Activated(impl::abi_arg_in<Windows::UI::Xaml::WindowActivatedEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Activated(*reinterpret_cast<const Windows::UI::Xaml::WindowActivatedEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Activated(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Activated(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Closed(impl::abi_arg_in<Windows::UI::Xaml::WindowClosedEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Closed(*reinterpret_cast<const Windows::UI::Xaml::WindowClosedEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Closed(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Closed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_SizeChanged(impl::abi_arg_in<Windows::UI::Xaml::WindowSizeChangedEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().SizeChanged(*reinterpret_cast<const Windows::UI::Xaml::WindowSizeChangedEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SizeChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SizeChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_VisibilityChanged(impl::abi_arg_in<Windows::UI::Xaml::WindowVisibilityChangedEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().VisibilityChanged(*reinterpret_cast<const Windows::UI::Xaml::WindowVisibilityChangedEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_VisibilityChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VisibilityChanged(token);
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
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IWindow2> : produce_base<D, Windows::UI::Xaml::IWindow2>
{
    HRESULT __stdcall abi_SetTitleBar(impl::abi_arg_in<Windows::UI::Xaml::IUIElement> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetTitleBar(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::IWindowCreatedEventArgs> : produce_base<D, Windows::UI::Xaml::IWindowCreatedEventArgs>
{
    HRESULT __stdcall get_Window(impl::abi_arg_out<Windows::UI::Xaml::IWindow> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Window());
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
struct produce<D, Windows::UI::Xaml::IWindowStatics> : produce_base<D, Windows::UI::Xaml::IWindowStatics>
{
    HRESULT __stdcall get_Current(impl::abi_arg_out<Windows::UI::Xaml::IWindow> value) noexcept override
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
};

}

namespace Windows::UI::Xaml {

template <typename D> void impl_IDataTemplateExtension<D>::ResetTemplate() const
{
    check_hresult(WINRT_SHIM(IDataTemplateExtension)->abi_ResetTemplate());
}

template <typename D> bool impl_IDataTemplateExtension<D>::ProcessBinding(uint32_t phase) const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IDataTemplateExtension)->abi_ProcessBinding(phase, &returnValue));
    return returnValue;
}

template <typename D> int32_t impl_IDataTemplateExtension<D>::ProcessBindings(const Windows::UI::Xaml::Controls::ContainerContentChangingEventArgs & arg) const
{
    int32_t returnValue {};
    check_hresult(WINRT_SHIM(IDataTemplateExtension)->abi_ProcessBindings(get_abi(arg), &returnValue));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::DependencyObject impl_IDataTemplate<D>::LoadContent() const
{
    Windows::UI::Xaml::DependencyObject returnValue { nullptr };
    check_hresult(WINRT_SHIM(IDataTemplate)->abi_LoadContent(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::DataTemplate impl_IDataTemplateFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::DataTemplate instance { nullptr };
    check_hresult(WINRT_SHIM(IDataTemplateFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IDataTemplateStatics2<D>::ExtensionInstanceProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IDataTemplateStatics2)->get_ExtensionInstanceProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::IDataTemplateExtension impl_IDataTemplateStatics2<D>::GetExtensionInstance(const Windows::UI::Xaml::FrameworkElement & element) const
{
    Windows::UI::Xaml::IDataTemplateExtension value;
    check_hresult(WINRT_SHIM(IDataTemplateStatics2)->abi_GetExtensionInstance(get_abi(element), put_abi(value)));
    return value;
}

template <typename D> void impl_IDataTemplateStatics2<D>::SetExtensionInstance(const Windows::UI::Xaml::FrameworkElement & element, const Windows::UI::Xaml::IDataTemplateExtension & value) const
{
    check_hresult(WINRT_SHIM(IDataTemplateStatics2)->abi_SetExtensionInstance(get_abi(element), get_abi(value)));
}

template <typename D> Windows::Foundation::TimeSpan impl_IDispatcherTimer<D>::Interval() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IDispatcherTimer)->get_Interval(put_abi(value)));
    return value;
}

template <typename D> void impl_IDispatcherTimer<D>::Interval(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(IDispatcherTimer)->put_Interval(get_abi(value)));
}

template <typename D> bool impl_IDispatcherTimer<D>::IsEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDispatcherTimer)->get_IsEnabled(&value));
    return value;
}

template <typename D> event_token impl_IDispatcherTimer<D>::Tick(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IDispatcherTimer)->add_Tick(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IDispatcherTimer> impl_IDispatcherTimer<D>::Tick(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const
{
    return impl::make_event_revoker<D, IDispatcherTimer>(this, &ABI::Windows::UI::Xaml::IDispatcherTimer::remove_Tick, Tick(value));
}

template <typename D> void impl_IDispatcherTimer<D>::Tick(event_token token) const
{
    check_hresult(WINRT_SHIM(IDispatcherTimer)->remove_Tick(token));
}

template <typename D> void impl_IDispatcherTimer<D>::Start() const
{
    check_hresult(WINRT_SHIM(IDispatcherTimer)->abi_Start());
}

template <typename D> void impl_IDispatcherTimer<D>::Stop() const
{
    check_hresult(WINRT_SHIM(IDispatcherTimer)->abi_Stop());
}

template <typename D> Windows::UI::Xaml::DispatcherTimer impl_IDispatcherTimerFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::DispatcherTimer instance { nullptr };
    check_hresult(WINRT_SHIM(IDispatcherTimerFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::CornerRadius impl_ICornerRadiusHelperStatics<D>::FromRadii(double topLeft, double topRight, double bottomRight, double bottomLeft) const
{
    Windows::UI::Xaml::CornerRadius returnValue {};
    check_hresult(WINRT_SHIM(ICornerRadiusHelperStatics)->abi_FromRadii(topLeft, topRight, bottomRight, bottomLeft, put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::CornerRadius impl_ICornerRadiusHelperStatics<D>::FromUniformRadius(double uniformRadius) const
{
    Windows::UI::Xaml::CornerRadius returnValue {};
    check_hresult(WINRT_SHIM(ICornerRadiusHelperStatics)->abi_FromUniformRadius(uniformRadius, put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Duration impl_IDurationHelperStatics<D>::Automatic() const
{
    Windows::UI::Xaml::Duration value {};
    check_hresult(WINRT_SHIM(IDurationHelperStatics)->get_Automatic(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Duration impl_IDurationHelperStatics<D>::Forever() const
{
    Windows::UI::Xaml::Duration value {};
    check_hresult(WINRT_SHIM(IDurationHelperStatics)->get_Forever(put_abi(value)));
    return value;
}

template <typename D> int32_t impl_IDurationHelperStatics<D>::Compare(const Windows::UI::Xaml::Duration & duration1, const Windows::UI::Xaml::Duration & duration2) const
{
    int32_t returnValue {};
    check_hresult(WINRT_SHIM(IDurationHelperStatics)->abi_Compare(get_abi(duration1), get_abi(duration2), &returnValue));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Duration impl_IDurationHelperStatics<D>::FromTimeSpan(const Windows::Foundation::TimeSpan & timeSpan) const
{
    Windows::UI::Xaml::Duration returnValue {};
    check_hresult(WINRT_SHIM(IDurationHelperStatics)->abi_FromTimeSpan(get_abi(timeSpan), put_abi(returnValue)));
    return returnValue;
}

template <typename D> bool impl_IDurationHelperStatics<D>::GetHasTimeSpan(const Windows::UI::Xaml::Duration & target) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDurationHelperStatics)->abi_GetHasTimeSpan(get_abi(target), &value));
    return value;
}

template <typename D> Windows::UI::Xaml::Duration impl_IDurationHelperStatics<D>::Add(const Windows::UI::Xaml::Duration & target, const Windows::UI::Xaml::Duration & duration) const
{
    Windows::UI::Xaml::Duration returnValue {};
    check_hresult(WINRT_SHIM(IDurationHelperStatics)->abi_Add(get_abi(target), get_abi(duration), put_abi(returnValue)));
    return returnValue;
}

template <typename D> bool impl_IDurationHelperStatics<D>::Equals(const Windows::UI::Xaml::Duration & target, const Windows::UI::Xaml::Duration & value) const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IDurationHelperStatics)->abi_Equals(get_abi(target), get_abi(value), &returnValue));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Duration impl_IDurationHelperStatics<D>::Subtract(const Windows::UI::Xaml::Duration & target, const Windows::UI::Xaml::Duration & duration) const
{
    Windows::UI::Xaml::Duration returnValue {};
    check_hresult(WINRT_SHIM(IDurationHelperStatics)->abi_Subtract(get_abi(target), get_abi(duration), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Thickness impl_IThicknessHelperStatics<D>::FromLengths(double left, double top, double right, double bottom) const
{
    Windows::UI::Xaml::Thickness returnValue {};
    check_hresult(WINRT_SHIM(IThicknessHelperStatics)->abi_FromLengths(left, top, right, bottom, put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Thickness impl_IThicknessHelperStatics<D>::FromUniformLength(double uniformLength) const
{
    Windows::UI::Xaml::Thickness returnValue {};
    check_hresult(WINRT_SHIM(IThicknessHelperStatics)->abi_FromUniformLength(uniformLength, put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IInspectable impl_IDataContextChangedEventArgs<D>::NewValue() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IDataContextChangedEventArgs)->get_NewValue(put_abi(value)));
    return value;
}

template <typename D> bool impl_IDataContextChangedEventArgs<D>::Handled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDataContextChangedEventArgs)->get_Handled(&value));
    return value;
}

template <typename D> void impl_IDataContextChangedEventArgs<D>::Handled(bool value) const
{
    check_hresult(WINRT_SHIM(IDataContextChangedEventArgs)->put_Handled(value));
}

template <typename D> Windows::Foundation::IInspectable impl_IDataTemplateKey<D>::DataType() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IDataTemplateKey)->get_DataType(put_abi(value)));
    return value;
}

template <typename D> void impl_IDataTemplateKey<D>::DataType(const Windows::Foundation::IInspectable & value) const
{
    check_hresult(WINRT_SHIM(IDataTemplateKey)->put_DataType(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DataTemplateKey impl_IDataTemplateKeyFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::DataTemplateKey instance { nullptr };
    check_hresult(WINRT_SHIM(IDataTemplateKeyFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::DataTemplateKey impl_IDataTemplateKeyFactory<D>::CreateInstanceWithType(const Windows::Foundation::IInspectable & dataType, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::DataTemplateKey instance { nullptr };
    check_hresult(WINRT_SHIM(IDataTemplateKeyFactory)->abi_CreateInstanceWithType(get_abi(dataType), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::Foundation::IInspectable impl_IDependencyObject<D>::GetValue(const Windows::UI::Xaml::DependencyProperty & dp) const
{
    Windows::Foundation::IInspectable returnValue;
    check_hresult(WINRT_SHIM(IDependencyObject)->abi_GetValue(get_abi(dp), put_abi(returnValue)));
    return returnValue;
}

template <typename D> void impl_IDependencyObject<D>::SetValue(const Windows::UI::Xaml::DependencyProperty & dp, const Windows::Foundation::IInspectable & value) const
{
    check_hresult(WINRT_SHIM(IDependencyObject)->abi_SetValue(get_abi(dp), get_abi(value)));
}

template <typename D> void impl_IDependencyObject<D>::ClearValue(const Windows::UI::Xaml::DependencyProperty & dp) const
{
    check_hresult(WINRT_SHIM(IDependencyObject)->abi_ClearValue(get_abi(dp)));
}

template <typename D> Windows::Foundation::IInspectable impl_IDependencyObject<D>::ReadLocalValue(const Windows::UI::Xaml::DependencyProperty & dp) const
{
    Windows::Foundation::IInspectable returnValue;
    check_hresult(WINRT_SHIM(IDependencyObject)->abi_ReadLocalValue(get_abi(dp), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IInspectable impl_IDependencyObject<D>::GetAnimationBaseValue(const Windows::UI::Xaml::DependencyProperty & dp) const
{
    Windows::Foundation::IInspectable returnValue;
    check_hresult(WINRT_SHIM(IDependencyObject)->abi_GetAnimationBaseValue(get_abi(dp), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Core::CoreDispatcher impl_IDependencyObject<D>::Dispatcher() const
{
    Windows::UI::Core::CoreDispatcher value { nullptr };
    check_hresult(WINRT_SHIM(IDependencyObject)->get_Dispatcher(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyObject impl_IDependencyObjectFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::DependencyObject instance { nullptr };
    check_hresult(WINRT_SHIM(IDependencyObjectFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> int64_t impl_IDependencyObject2<D>::RegisterPropertyChangedCallback(const Windows::UI::Xaml::DependencyProperty & dp, const Windows::UI::Xaml::DependencyPropertyChangedCallback & callback) const
{
    int64_t returnValue {};
    check_hresult(WINRT_SHIM(IDependencyObject2)->abi_RegisterPropertyChangedCallback(get_abi(dp), get_abi(callback), &returnValue));
    return returnValue;
}

template <typename D> void impl_IDependencyObject2<D>::UnregisterPropertyChangedCallback(const Windows::UI::Xaml::DependencyProperty & dp, int64_t token) const
{
    check_hresult(WINRT_SHIM(IDependencyObject2)->abi_UnregisterPropertyChangedCallback(get_abi(dp), token));
}

template <typename D> Windows::UI::Xaml::PropertyMetadata impl_IDependencyProperty<D>::GetMetadata(const Windows::UI::Xaml::Interop::TypeName & forType) const
{
    Windows::UI::Xaml::PropertyMetadata returnValue { nullptr };
    check_hresult(WINRT_SHIM(IDependencyProperty)->abi_GetMetadata(get_abi(forType), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IInspectable impl_IDependencyPropertyStatics<D>::UnsetValue() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IDependencyPropertyStatics)->get_UnsetValue(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IDependencyPropertyStatics<D>::Register(hstring_view name, const Windows::UI::Xaml::Interop::TypeName & propertyType, const Windows::UI::Xaml::Interop::TypeName & ownerType, const Windows::UI::Xaml::PropertyMetadata & typeMetadata) const
{
    Windows::UI::Xaml::DependencyProperty returnValue { nullptr };
    check_hresult(WINRT_SHIM(IDependencyPropertyStatics)->abi_Register(get_abi(name), get_abi(propertyType), get_abi(ownerType), get_abi(typeMetadata), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IDependencyPropertyStatics<D>::RegisterAttached(hstring_view name, const Windows::UI::Xaml::Interop::TypeName & propertyType, const Windows::UI::Xaml::Interop::TypeName & ownerType, const Windows::UI::Xaml::PropertyMetadata & defaultMetadata) const
{
    Windows::UI::Xaml::DependencyProperty returnValue { nullptr };
    check_hresult(WINRT_SHIM(IDependencyPropertyStatics)->abi_RegisterAttached(get_abi(name), get_abi(propertyType), get_abi(ownerType), get_abi(defaultMetadata), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IDependencyPropertyChangedEventArgs<D>::Property() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IDependencyPropertyChangedEventArgs)->get_Property(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IInspectable impl_IDependencyPropertyChangedEventArgs<D>::OldValue() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IDependencyPropertyChangedEventArgs)->get_OldValue(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IInspectable impl_IDependencyPropertyChangedEventArgs<D>::NewValue() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IDependencyPropertyChangedEventArgs)->get_NewValue(put_abi(value)));
    return value;
}

template <typename D> void impl_IDragOperationDeferral<D>::Complete() const
{
    check_hresult(WINRT_SHIM(IDragOperationDeferral)->abi_Complete());
}

template <typename D> void impl_IDragUI<D>::SetContentFromBitmapImage(const Windows::UI::Xaml::Media::Imaging::BitmapImage & bitmapImage) const
{
    check_hresult(WINRT_SHIM(IDragUI)->abi_SetContentFromBitmapImage(get_abi(bitmapImage)));
}

template <typename D> void impl_IDragUI<D>::SetContentFromBitmapImage(const Windows::UI::Xaml::Media::Imaging::BitmapImage & bitmapImage, const Windows::Foundation::Point & anchorPoint) const
{
    check_hresult(WINRT_SHIM(IDragUI)->abi_SetContentFromBitmapImageWithAnchorPoint(get_abi(bitmapImage), get_abi(anchorPoint)));
}

template <typename D> void impl_IDragUI<D>::SetContentFromSoftwareBitmap(const Windows::Graphics::Imaging::SoftwareBitmap & softwareBitmap) const
{
    check_hresult(WINRT_SHIM(IDragUI)->abi_SetContentFromSoftwareBitmap(get_abi(softwareBitmap)));
}

template <typename D> void impl_IDragUI<D>::SetContentFromSoftwareBitmap(const Windows::Graphics::Imaging::SoftwareBitmap & softwareBitmap, const Windows::Foundation::Point & anchorPoint) const
{
    check_hresult(WINRT_SHIM(IDragUI)->abi_SetContentFromSoftwareBitmapWithAnchorPoint(get_abi(softwareBitmap), get_abi(anchorPoint)));
}

template <typename D> void impl_IDragUI<D>::SetContentFromDataPackage() const
{
    check_hresult(WINRT_SHIM(IDragUI)->abi_SetContentFromDataPackage());
}

template <typename D> hstring impl_IDragUIOverride<D>::Caption() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDragUIOverride)->get_Caption(put_abi(value)));
    return value;
}

template <typename D> void impl_IDragUIOverride<D>::Caption(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IDragUIOverride)->put_Caption(get_abi(value)));
}

template <typename D> bool impl_IDragUIOverride<D>::IsContentVisible() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDragUIOverride)->get_IsContentVisible(&value));
    return value;
}

template <typename D> void impl_IDragUIOverride<D>::IsContentVisible(bool value) const
{
    check_hresult(WINRT_SHIM(IDragUIOverride)->put_IsContentVisible(value));
}

template <typename D> bool impl_IDragUIOverride<D>::IsCaptionVisible() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDragUIOverride)->get_IsCaptionVisible(&value));
    return value;
}

template <typename D> void impl_IDragUIOverride<D>::IsCaptionVisible(bool value) const
{
    check_hresult(WINRT_SHIM(IDragUIOverride)->put_IsCaptionVisible(value));
}

template <typename D> bool impl_IDragUIOverride<D>::IsGlyphVisible() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDragUIOverride)->get_IsGlyphVisible(&value));
    return value;
}

template <typename D> void impl_IDragUIOverride<D>::IsGlyphVisible(bool value) const
{
    check_hresult(WINRT_SHIM(IDragUIOverride)->put_IsGlyphVisible(value));
}

template <typename D> void impl_IDragUIOverride<D>::Clear() const
{
    check_hresult(WINRT_SHIM(IDragUIOverride)->abi_Clear());
}

template <typename D> void impl_IDragUIOverride<D>::SetContentFromBitmapImage(const Windows::UI::Xaml::Media::Imaging::BitmapImage & bitmapImage) const
{
    check_hresult(WINRT_SHIM(IDragUIOverride)->abi_SetContentFromBitmapImage(get_abi(bitmapImage)));
}

template <typename D> void impl_IDragUIOverride<D>::SetContentFromBitmapImage(const Windows::UI::Xaml::Media::Imaging::BitmapImage & bitmapImage, const Windows::Foundation::Point & anchorPoint) const
{
    check_hresult(WINRT_SHIM(IDragUIOverride)->abi_SetContentFromBitmapImageWithAnchorPoint(get_abi(bitmapImage), get_abi(anchorPoint)));
}

template <typename D> void impl_IDragUIOverride<D>::SetContentFromSoftwareBitmap(const Windows::Graphics::Imaging::SoftwareBitmap & softwareBitmap) const
{
    check_hresult(WINRT_SHIM(IDragUIOverride)->abi_SetContentFromSoftwareBitmap(get_abi(softwareBitmap)));
}

template <typename D> void impl_IDragUIOverride<D>::SetContentFromSoftwareBitmap(const Windows::Graphics::Imaging::SoftwareBitmap & softwareBitmap, const Windows::Foundation::Point & anchorPoint) const
{
    check_hresult(WINRT_SHIM(IDragUIOverride)->abi_SetContentFromSoftwareBitmapWithAnchorPoint(get_abi(softwareBitmap), get_abi(anchorPoint)));
}

template <typename D> double impl_IElementSoundPlayerStatics<D>::Volume() const
{
    double value {};
    check_hresult(WINRT_SHIM(IElementSoundPlayerStatics)->get_Volume(&value));
    return value;
}

template <typename D> void impl_IElementSoundPlayerStatics<D>::Volume(double value) const
{
    check_hresult(WINRT_SHIM(IElementSoundPlayerStatics)->put_Volume(value));
}

template <typename D> Windows::UI::Xaml::ElementSoundPlayerState impl_IElementSoundPlayerStatics<D>::State() const
{
    Windows::UI::Xaml::ElementSoundPlayerState value {};
    check_hresult(WINRT_SHIM(IElementSoundPlayerStatics)->get_State(&value));
    return value;
}

template <typename D> void impl_IElementSoundPlayerStatics<D>::State(Windows::UI::Xaml::ElementSoundPlayerState value) const
{
    check_hresult(WINRT_SHIM(IElementSoundPlayerStatics)->put_State(value));
}

template <typename D> void impl_IElementSoundPlayerStatics<D>::Play(Windows::UI::Xaml::ElementSoundKind sound) const
{
    check_hresult(WINRT_SHIM(IElementSoundPlayerStatics)->abi_Play(sound));
}

template <typename D> Windows::Foundation::IInspectable impl_IPropertyMetadata<D>::DefaultValue() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IPropertyMetadata)->get_DefaultValue(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::CreateDefaultValueCallback impl_IPropertyMetadata<D>::CreateDefaultValueCallback() const
{
    Windows::UI::Xaml::CreateDefaultValueCallback value {};
    check_hresult(WINRT_SHIM(IPropertyMetadata)->get_CreateDefaultValueCallback(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::PropertyMetadata impl_IPropertyMetadataStatics<D>::Create(const Windows::Foundation::IInspectable & defaultValue) const
{
    Windows::UI::Xaml::PropertyMetadata returnValue { nullptr };
    check_hresult(WINRT_SHIM(IPropertyMetadataStatics)->abi_CreateWithDefaultValue(get_abi(defaultValue), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::PropertyMetadata impl_IPropertyMetadataStatics<D>::Create(const Windows::Foundation::IInspectable & defaultValue, const Windows::UI::Xaml::PropertyChangedCallback & propertyChangedCallback) const
{
    Windows::UI::Xaml::PropertyMetadata returnValue { nullptr };
    check_hresult(WINRT_SHIM(IPropertyMetadataStatics)->abi_CreateWithDefaultValueAndCallback(get_abi(defaultValue), get_abi(propertyChangedCallback), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::PropertyMetadata impl_IPropertyMetadataStatics<D>::Create(const Windows::UI::Xaml::CreateDefaultValueCallback & createDefaultValueCallback) const
{
    Windows::UI::Xaml::PropertyMetadata returnValue { nullptr };
    check_hresult(WINRT_SHIM(IPropertyMetadataStatics)->abi_CreateWithFactory(get_abi(createDefaultValueCallback), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::PropertyMetadata impl_IPropertyMetadataStatics<D>::Create(const Windows::UI::Xaml::CreateDefaultValueCallback & createDefaultValueCallback, const Windows::UI::Xaml::PropertyChangedCallback & propertyChangedCallback) const
{
    Windows::UI::Xaml::PropertyMetadata returnValue { nullptr };
    check_hresult(WINRT_SHIM(IPropertyMetadataStatics)->abi_CreateWithFactoryAndCallback(get_abi(createDefaultValueCallback), get_abi(propertyChangedCallback), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::PropertyMetadata impl_IPropertyMetadataFactory<D>::CreateInstanceWithDefaultValue(const Windows::Foundation::IInspectable & defaultValue, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::PropertyMetadata instance { nullptr };
    check_hresult(WINRT_SHIM(IPropertyMetadataFactory)->abi_CreateInstanceWithDefaultValue(get_abi(defaultValue), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::PropertyMetadata impl_IPropertyMetadataFactory<D>::CreateInstanceWithDefaultValueAndCallback(const Windows::Foundation::IInspectable & defaultValue, const Windows::UI::Xaml::PropertyChangedCallback & propertyChangedCallback, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::PropertyMetadata instance { nullptr };
    check_hresult(WINRT_SHIM(IPropertyMetadataFactory)->abi_CreateInstanceWithDefaultValueAndCallback(get_abi(defaultValue), get_abi(propertyChangedCallback), get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::Foundation::IInspectable impl_IRoutedEventArgs<D>::OriginalSource() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IRoutedEventArgs)->get_OriginalSource(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::RoutedEventArgs impl_IRoutedEventArgsFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::RoutedEventArgs instance { nullptr };
    check_hresult(WINRT_SHIM(IRoutedEventArgsFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> bool impl_ISetterBaseCollection<D>::IsSealed() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISetterBaseCollection)->get_IsSealed(&value));
    return value;
}

template <typename D> Windows::UI::Xaml::PropertyPath impl_ITargetPropertyPath<D>::Path() const
{
    Windows::UI::Xaml::PropertyPath value { nullptr };
    check_hresult(WINRT_SHIM(ITargetPropertyPath)->get_Path(put_abi(value)));
    return value;
}

template <typename D> void impl_ITargetPropertyPath<D>::Path(const Windows::UI::Xaml::PropertyPath & value) const
{
    check_hresult(WINRT_SHIM(ITargetPropertyPath)->put_Path(get_abi(value)));
}

template <typename D> Windows::Foundation::IInspectable impl_ITargetPropertyPath<D>::Target() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(ITargetPropertyPath)->get_Target(put_abi(value)));
    return value;
}

template <typename D> void impl_ITargetPropertyPath<D>::Target(const Windows::Foundation::IInspectable & value) const
{
    check_hresult(WINRT_SHIM(ITargetPropertyPath)->put_Target(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::TargetPropertyPath impl_ITargetPropertyPathFactory<D>::CreateInstance(const Windows::UI::Xaml::DependencyProperty & targetProperty) const
{
    Windows::UI::Xaml::TargetPropertyPath instance { nullptr };
    check_hresult(WINRT_SHIM(ITargetPropertyPathFactory)->abi_CreateInstance(get_abi(targetProperty), put_abi(instance)));
    return instance;
}

template <typename D> HRESULT impl_IUnhandledExceptionEventArgs<D>::Exception() const
{
    HRESULT value {};
    check_hresult(WINRT_SHIM(IUnhandledExceptionEventArgs)->get_Exception(&value));
    return value;
}

template <typename D> hstring impl_IUnhandledExceptionEventArgs<D>::Message() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUnhandledExceptionEventArgs)->get_Message(put_abi(value)));
    return value;
}

template <typename D> bool impl_IUnhandledExceptionEventArgs<D>::Handled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IUnhandledExceptionEventArgs)->get_Handled(&value));
    return value;
}

template <typename D> void impl_IUnhandledExceptionEventArgs<D>::Handled(bool value) const
{
    check_hresult(WINRT_SHIM(IUnhandledExceptionEventArgs)->put_Handled(value));
}

template <typename D> Windows::UI::Xaml::VisualState impl_IVisualStateChangedEventArgs<D>::OldState() const
{
    Windows::UI::Xaml::VisualState value { nullptr };
    check_hresult(WINRT_SHIM(IVisualStateChangedEventArgs)->get_OldState(put_abi(value)));
    return value;
}

template <typename D> void impl_IVisualStateChangedEventArgs<D>::OldState(const Windows::UI::Xaml::VisualState & value) const
{
    check_hresult(WINRT_SHIM(IVisualStateChangedEventArgs)->put_OldState(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::VisualState impl_IVisualStateChangedEventArgs<D>::NewState() const
{
    Windows::UI::Xaml::VisualState value { nullptr };
    check_hresult(WINRT_SHIM(IVisualStateChangedEventArgs)->get_NewState(put_abi(value)));
    return value;
}

template <typename D> void impl_IVisualStateChangedEventArgs<D>::NewState(const Windows::UI::Xaml::VisualState & value) const
{
    check_hresult(WINRT_SHIM(IVisualStateChangedEventArgs)->put_NewState(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Controls::Control impl_IVisualStateChangedEventArgs<D>::Control() const
{
    Windows::UI::Xaml::Controls::Control value { nullptr };
    check_hresult(WINRT_SHIM(IVisualStateChangedEventArgs)->get_Control(put_abi(value)));
    return value;
}

template <typename D> void impl_IVisualStateChangedEventArgs<D>::Control(const Windows::UI::Xaml::Controls::Control & value) const
{
    check_hresult(WINRT_SHIM(IVisualStateChangedEventArgs)->put_Control(get_abi(value)));
}

template <typename D> Windows::Foundation::Rect impl_IWindow<D>::Bounds() const
{
    Windows::Foundation::Rect value {};
    check_hresult(WINRT_SHIM(IWindow)->get_Bounds(put_abi(value)));
    return value;
}

template <typename D> bool impl_IWindow<D>::Visible() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IWindow)->get_Visible(&value));
    return value;
}

template <typename D> Windows::UI::Xaml::UIElement impl_IWindow<D>::Content() const
{
    Windows::UI::Xaml::UIElement value { nullptr };
    check_hresult(WINRT_SHIM(IWindow)->get_Content(put_abi(value)));
    return value;
}

template <typename D> void impl_IWindow<D>::Content(const Windows::UI::Xaml::UIElement & value) const
{
    check_hresult(WINRT_SHIM(IWindow)->put_Content(get_abi(value)));
}

template <typename D> Windows::UI::Core::CoreWindow impl_IWindow<D>::CoreWindow() const
{
    Windows::UI::Core::CoreWindow value { nullptr };
    check_hresult(WINRT_SHIM(IWindow)->get_CoreWindow(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Core::CoreDispatcher impl_IWindow<D>::Dispatcher() const
{
    Windows::UI::Core::CoreDispatcher value { nullptr };
    check_hresult(WINRT_SHIM(IWindow)->get_Dispatcher(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IWindow<D>::Activated(const Windows::UI::Xaml::WindowActivatedEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IWindow)->add_Activated(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IWindow> impl_IWindow<D>::Activated(auto_revoke_t, const Windows::UI::Xaml::WindowActivatedEventHandler & value) const
{
    return impl::make_event_revoker<D, IWindow>(this, &ABI::Windows::UI::Xaml::IWindow::remove_Activated, Activated(value));
}

template <typename D> void impl_IWindow<D>::Activated(event_token token) const
{
    check_hresult(WINRT_SHIM(IWindow)->remove_Activated(token));
}

template <typename D> event_token impl_IWindow<D>::Closed(const Windows::UI::Xaml::WindowClosedEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IWindow)->add_Closed(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IWindow> impl_IWindow<D>::Closed(auto_revoke_t, const Windows::UI::Xaml::WindowClosedEventHandler & value) const
{
    return impl::make_event_revoker<D, IWindow>(this, &ABI::Windows::UI::Xaml::IWindow::remove_Closed, Closed(value));
}

template <typename D> void impl_IWindow<D>::Closed(event_token token) const
{
    check_hresult(WINRT_SHIM(IWindow)->remove_Closed(token));
}

template <typename D> event_token impl_IWindow<D>::SizeChanged(const Windows::UI::Xaml::WindowSizeChangedEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IWindow)->add_SizeChanged(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IWindow> impl_IWindow<D>::SizeChanged(auto_revoke_t, const Windows::UI::Xaml::WindowSizeChangedEventHandler & value) const
{
    return impl::make_event_revoker<D, IWindow>(this, &ABI::Windows::UI::Xaml::IWindow::remove_SizeChanged, SizeChanged(value));
}

template <typename D> void impl_IWindow<D>::SizeChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IWindow)->remove_SizeChanged(token));
}

template <typename D> event_token impl_IWindow<D>::VisibilityChanged(const Windows::UI::Xaml::WindowVisibilityChangedEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IWindow)->add_VisibilityChanged(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IWindow> impl_IWindow<D>::VisibilityChanged(auto_revoke_t, const Windows::UI::Xaml::WindowVisibilityChangedEventHandler & value) const
{
    return impl::make_event_revoker<D, IWindow>(this, &ABI::Windows::UI::Xaml::IWindow::remove_VisibilityChanged, VisibilityChanged(value));
}

template <typename D> void impl_IWindow<D>::VisibilityChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IWindow)->remove_VisibilityChanged(token));
}

template <typename D> void impl_IWindow<D>::Activate() const
{
    check_hresult(WINRT_SHIM(IWindow)->abi_Activate());
}

template <typename D> void impl_IWindow<D>::Close() const
{
    check_hresult(WINRT_SHIM(IWindow)->abi_Close());
}

template <typename D> Windows::UI::Xaml::Window impl_IWindowStatics<D>::Current() const
{
    Windows::UI::Xaml::Window value { nullptr };
    check_hresult(WINRT_SHIM(IWindowStatics)->get_Current(put_abi(value)));
    return value;
}

template <typename D> void impl_IWindow2<D>::SetTitleBar(const Windows::UI::Xaml::UIElement & value) const
{
    check_hresult(WINRT_SHIM(IWindow2)->abi_SetTitleBar(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Window impl_IWindowCreatedEventArgs<D>::Window() const
{
    Windows::UI::Xaml::Window value { nullptr };
    check_hresult(WINRT_SHIM(IWindowCreatedEventArgs)->get_Window(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyObjectCollection impl_IDependencyObjectCollectionFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::DependencyObjectCollection instance { nullptr };
    check_hresult(WINRT_SHIM(IDependencyObjectCollectionFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> bool impl_IDragEventArgs<D>::Handled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDragEventArgs)->get_Handled(&value));
    return value;
}

template <typename D> void impl_IDragEventArgs<D>::Handled(bool value) const
{
    check_hresult(WINRT_SHIM(IDragEventArgs)->put_Handled(value));
}

template <typename D> Windows::ApplicationModel::DataTransfer::DataPackage impl_IDragEventArgs<D>::Data() const
{
    Windows::ApplicationModel::DataTransfer::DataPackage value { nullptr };
    check_hresult(WINRT_SHIM(IDragEventArgs)->get_Data(put_abi(value)));
    return value;
}

template <typename D> void impl_IDragEventArgs<D>::Data(const Windows::ApplicationModel::DataTransfer::DataPackage & value) const
{
    check_hresult(WINRT_SHIM(IDragEventArgs)->put_Data(get_abi(value)));
}

template <typename D> Windows::Foundation::Point impl_IDragEventArgs<D>::GetPosition(const Windows::UI::Xaml::UIElement & relativeTo) const
{
    Windows::Foundation::Point returnValue {};
    check_hresult(WINRT_SHIM(IDragEventArgs)->abi_GetPosition(get_abi(relativeTo), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::ApplicationModel::DataTransfer::DataPackageView impl_IDragEventArgs2<D>::DataView() const
{
    Windows::ApplicationModel::DataTransfer::DataPackageView value { nullptr };
    check_hresult(WINRT_SHIM(IDragEventArgs2)->get_DataView(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DragUIOverride impl_IDragEventArgs2<D>::DragUIOverride() const
{
    Windows::UI::Xaml::DragUIOverride value { nullptr };
    check_hresult(WINRT_SHIM(IDragEventArgs2)->get_DragUIOverride(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::DataTransfer::DragDrop::DragDropModifiers impl_IDragEventArgs2<D>::Modifiers() const
{
    Windows::ApplicationModel::DataTransfer::DragDrop::DragDropModifiers value {};
    check_hresult(WINRT_SHIM(IDragEventArgs2)->get_Modifiers(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::DataTransfer::DataPackageOperation impl_IDragEventArgs2<D>::AcceptedOperation() const
{
    Windows::ApplicationModel::DataTransfer::DataPackageOperation value {};
    check_hresult(WINRT_SHIM(IDragEventArgs2)->get_AcceptedOperation(&value));
    return value;
}

template <typename D> void impl_IDragEventArgs2<D>::AcceptedOperation(Windows::ApplicationModel::DataTransfer::DataPackageOperation value) const
{
    check_hresult(WINRT_SHIM(IDragEventArgs2)->put_AcceptedOperation(value));
}

template <typename D> Windows::UI::Xaml::DragOperationDeferral impl_IDragEventArgs2<D>::GetDeferral() const
{
    Windows::UI::Xaml::DragOperationDeferral returnValue { nullptr };
    check_hresult(WINRT_SHIM(IDragEventArgs2)->abi_GetDeferral(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::ApplicationModel::DataTransfer::DataPackageOperation impl_IDragEventArgs3<D>::AllowedOperations() const
{
    Windows::ApplicationModel::DataTransfer::DataPackageOperation value {};
    check_hresult(WINRT_SHIM(IDragEventArgs3)->get_AllowedOperations(&value));
    return value;
}

template <typename D> bool impl_IDragStartingEventArgs<D>::Cancel() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDragStartingEventArgs)->get_Cancel(&value));
    return value;
}

template <typename D> void impl_IDragStartingEventArgs<D>::Cancel(bool value) const
{
    check_hresult(WINRT_SHIM(IDragStartingEventArgs)->put_Cancel(value));
}

template <typename D> Windows::ApplicationModel::DataTransfer::DataPackage impl_IDragStartingEventArgs<D>::Data() const
{
    Windows::ApplicationModel::DataTransfer::DataPackage value { nullptr };
    check_hresult(WINRT_SHIM(IDragStartingEventArgs)->get_Data(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DragUI impl_IDragStartingEventArgs<D>::DragUI() const
{
    Windows::UI::Xaml::DragUI value { nullptr };
    check_hresult(WINRT_SHIM(IDragStartingEventArgs)->get_DragUI(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DragOperationDeferral impl_IDragStartingEventArgs<D>::GetDeferral() const
{
    Windows::UI::Xaml::DragOperationDeferral returnValue { nullptr };
    check_hresult(WINRT_SHIM(IDragStartingEventArgs)->abi_GetDeferral(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::Point impl_IDragStartingEventArgs<D>::GetPosition(const Windows::UI::Xaml::UIElement & relativeTo) const
{
    Windows::Foundation::Point returnValue {};
    check_hresult(WINRT_SHIM(IDragStartingEventArgs)->abi_GetPosition(get_abi(relativeTo), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::ApplicationModel::DataTransfer::DataPackageOperation impl_IDragStartingEventArgs2<D>::AllowedOperations() const
{
    Windows::ApplicationModel::DataTransfer::DataPackageOperation value {};
    check_hresult(WINRT_SHIM(IDragStartingEventArgs2)->get_AllowedOperations(&value));
    return value;
}

template <typename D> void impl_IDragStartingEventArgs2<D>::AllowedOperations(Windows::ApplicationModel::DataTransfer::DataPackageOperation value) const
{
    check_hresult(WINRT_SHIM(IDragStartingEventArgs2)->put_AllowedOperations(value));
}

template <typename D> Windows::ApplicationModel::DataTransfer::DataPackageOperation impl_IDropCompletedEventArgs<D>::DropResult() const
{
    Windows::ApplicationModel::DataTransfer::DataPackageOperation value {};
    check_hresult(WINRT_SHIM(IDropCompletedEventArgs)->get_DropResult(&value));
    return value;
}

template <typename D> hstring impl_IExceptionRoutedEventArgs<D>::ErrorMessage() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IExceptionRoutedEventArgs)->get_ErrorMessage(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::FrameworkTemplate impl_IFrameworkTemplateFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::FrameworkTemplate instance { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkTemplateFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> hstring impl_IPropertyPath<D>::Path() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPropertyPath)->get_Path(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::PropertyPath impl_IPropertyPathFactory<D>::CreateInstance(hstring_view path) const
{
    Windows::UI::Xaml::PropertyPath instance { nullptr };
    check_hresult(WINRT_SHIM(IPropertyPathFactory)->abi_CreateInstance(get_abi(path), put_abi(instance)));
    return instance;
}

template <typename D> Windows::Foundation::Uri impl_IResourceDictionary<D>::Source() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IResourceDictionary)->get_Source(put_abi(value)));
    return value;
}

template <typename D> void impl_IResourceDictionary<D>::Source(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(IResourceDictionary)->put_Source(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::UI::Xaml::ResourceDictionary> impl_IResourceDictionary<D>::MergedDictionaries() const
{
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::ResourceDictionary> value;
    check_hresult(WINRT_SHIM(IResourceDictionary)->get_MergedDictionaries(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMap<Windows::Foundation::IInspectable, Windows::Foundation::IInspectable> impl_IResourceDictionary<D>::ThemeDictionaries() const
{
    Windows::Foundation::Collections::IMap<Windows::Foundation::IInspectable, Windows::Foundation::IInspectable> value;
    check_hresult(WINRT_SHIM(IResourceDictionary)->get_ThemeDictionaries(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::ResourceDictionary impl_IResourceDictionaryFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::ResourceDictionary instance { nullptr };
    check_hresult(WINRT_SHIM(IResourceDictionaryFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> bool impl_ISetterBase<D>::IsSealed() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISetterBase)->get_IsSealed(&value));
    return value;
}

template <typename D> Windows::Foundation::Size impl_ISizeChangedEventArgs<D>::PreviousSize() const
{
    Windows::Foundation::Size value {};
    check_hresult(WINRT_SHIM(ISizeChangedEventArgs)->get_PreviousSize(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Size impl_ISizeChangedEventArgs<D>::NewSize() const
{
    Windows::Foundation::Size value {};
    check_hresult(WINRT_SHIM(ISizeChangedEventArgs)->get_NewSize(put_abi(value)));
    return value;
}

template <typename D> void impl_IStateTriggerBaseProtected<D>::SetActive(bool IsActive) const
{
    check_hresult(WINRT_SHIM(IStateTriggerBaseProtected)->abi_SetActive(IsActive));
}

template <typename D> Windows::UI::Xaml::StateTriggerBase impl_IStateTriggerBaseFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::StateTriggerBase instance { nullptr };
    check_hresult(WINRT_SHIM(IStateTriggerBaseFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> bool impl_IStyle<D>::IsSealed() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStyle)->get_IsSealed(&value));
    return value;
}

template <typename D> Windows::UI::Xaml::SetterBaseCollection impl_IStyle<D>::Setters() const
{
    Windows::UI::Xaml::SetterBaseCollection value { nullptr };
    check_hresult(WINRT_SHIM(IStyle)->get_Setters(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Interop::TypeName impl_IStyle<D>::TargetType() const
{
    Windows::UI::Xaml::Interop::TypeName value {};
    check_hresult(WINRT_SHIM(IStyle)->get_TargetType(put_abi(value)));
    return value;
}

template <typename D> void impl_IStyle<D>::TargetType(const Windows::UI::Xaml::Interop::TypeName & value) const
{
    check_hresult(WINRT_SHIM(IStyle)->put_TargetType(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Style impl_IStyle<D>::BasedOn() const
{
    Windows::UI::Xaml::Style value { nullptr };
    check_hresult(WINRT_SHIM(IStyle)->get_BasedOn(put_abi(value)));
    return value;
}

template <typename D> void impl_IStyle<D>::BasedOn(const Windows::UI::Xaml::Style & value) const
{
    check_hresult(WINRT_SHIM(IStyle)->put_BasedOn(get_abi(value)));
}

template <typename D> void impl_IStyle<D>::Seal() const
{
    check_hresult(WINRT_SHIM(IStyle)->abi_Seal());
}

template <typename D> Windows::UI::Xaml::Style impl_IStyleFactory<D>::CreateInstance(const Windows::UI::Xaml::Interop::TypeName & targetType) const
{
    Windows::UI::Xaml::Style instance { nullptr };
    check_hresult(WINRT_SHIM(IStyleFactory)->abi_CreateInstance(get_abi(targetType), put_abi(instance)));
    return instance;
}

template <typename D> Windows::Foundation::Size impl_IUIElement<D>::DesiredSize() const
{
    Windows::Foundation::Size value {};
    check_hresult(WINRT_SHIM(IUIElement)->get_DesiredSize(put_abi(value)));
    return value;
}

template <typename D> bool impl_IUIElement<D>::AllowDrop() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IUIElement)->get_AllowDrop(&value));
    return value;
}

template <typename D> void impl_IUIElement<D>::AllowDrop(bool value) const
{
    check_hresult(WINRT_SHIM(IUIElement)->put_AllowDrop(value));
}

template <typename D> double impl_IUIElement<D>::Opacity() const
{
    double value {};
    check_hresult(WINRT_SHIM(IUIElement)->get_Opacity(&value));
    return value;
}

template <typename D> void impl_IUIElement<D>::Opacity(double value) const
{
    check_hresult(WINRT_SHIM(IUIElement)->put_Opacity(value));
}

template <typename D> Windows::UI::Xaml::Media::RectangleGeometry impl_IUIElement<D>::Clip() const
{
    Windows::UI::Xaml::Media::RectangleGeometry value { nullptr };
    check_hresult(WINRT_SHIM(IUIElement)->get_Clip(put_abi(value)));
    return value;
}

template <typename D> void impl_IUIElement<D>::Clip(const Windows::UI::Xaml::Media::RectangleGeometry & value) const
{
    check_hresult(WINRT_SHIM(IUIElement)->put_Clip(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Media::Transform impl_IUIElement<D>::RenderTransform() const
{
    Windows::UI::Xaml::Media::Transform value { nullptr };
    check_hresult(WINRT_SHIM(IUIElement)->get_RenderTransform(put_abi(value)));
    return value;
}

template <typename D> void impl_IUIElement<D>::RenderTransform(const Windows::UI::Xaml::Media::Transform & value) const
{
    check_hresult(WINRT_SHIM(IUIElement)->put_RenderTransform(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Media::Projection impl_IUIElement<D>::Projection() const
{
    Windows::UI::Xaml::Media::Projection value { nullptr };
    check_hresult(WINRT_SHIM(IUIElement)->get_Projection(put_abi(value)));
    return value;
}

template <typename D> void impl_IUIElement<D>::Projection(const Windows::UI::Xaml::Media::Projection & value) const
{
    check_hresult(WINRT_SHIM(IUIElement)->put_Projection(get_abi(value)));
}

template <typename D> Windows::Foundation::Point impl_IUIElement<D>::RenderTransformOrigin() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(IUIElement)->get_RenderTransformOrigin(put_abi(value)));
    return value;
}

template <typename D> void impl_IUIElement<D>::RenderTransformOrigin(const Windows::Foundation::Point & value) const
{
    check_hresult(WINRT_SHIM(IUIElement)->put_RenderTransformOrigin(get_abi(value)));
}

template <typename D> bool impl_IUIElement<D>::IsHitTestVisible() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IUIElement)->get_IsHitTestVisible(&value));
    return value;
}

template <typename D> void impl_IUIElement<D>::IsHitTestVisible(bool value) const
{
    check_hresult(WINRT_SHIM(IUIElement)->put_IsHitTestVisible(value));
}

template <typename D> Windows::UI::Xaml::Visibility impl_IUIElement<D>::Visibility() const
{
    Windows::UI::Xaml::Visibility value {};
    check_hresult(WINRT_SHIM(IUIElement)->get_Visibility(&value));
    return value;
}

template <typename D> void impl_IUIElement<D>::Visibility(Windows::UI::Xaml::Visibility value) const
{
    check_hresult(WINRT_SHIM(IUIElement)->put_Visibility(value));
}

template <typename D> Windows::Foundation::Size impl_IUIElement<D>::RenderSize() const
{
    Windows::Foundation::Size value {};
    check_hresult(WINRT_SHIM(IUIElement)->get_RenderSize(put_abi(value)));
    return value;
}

template <typename D> bool impl_IUIElement<D>::UseLayoutRounding() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IUIElement)->get_UseLayoutRounding(&value));
    return value;
}

template <typename D> void impl_IUIElement<D>::UseLayoutRounding(bool value) const
{
    check_hresult(WINRT_SHIM(IUIElement)->put_UseLayoutRounding(value));
}

template <typename D> Windows::UI::Xaml::Media::Animation::TransitionCollection impl_IUIElement<D>::Transitions() const
{
    Windows::UI::Xaml::Media::Animation::TransitionCollection value { nullptr };
    check_hresult(WINRT_SHIM(IUIElement)->get_Transitions(put_abi(value)));
    return value;
}

template <typename D> void impl_IUIElement<D>::Transitions(const Windows::UI::Xaml::Media::Animation::TransitionCollection & value) const
{
    check_hresult(WINRT_SHIM(IUIElement)->put_Transitions(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Media::CacheMode impl_IUIElement<D>::CacheMode() const
{
    Windows::UI::Xaml::Media::CacheMode value { nullptr };
    check_hresult(WINRT_SHIM(IUIElement)->get_CacheMode(put_abi(value)));
    return value;
}

template <typename D> void impl_IUIElement<D>::CacheMode(const Windows::UI::Xaml::Media::CacheMode & value) const
{
    check_hresult(WINRT_SHIM(IUIElement)->put_CacheMode(get_abi(value)));
}

template <typename D> bool impl_IUIElement<D>::IsTapEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IUIElement)->get_IsTapEnabled(&value));
    return value;
}

template <typename D> void impl_IUIElement<D>::IsTapEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IUIElement)->put_IsTapEnabled(value));
}

template <typename D> bool impl_IUIElement<D>::IsDoubleTapEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IUIElement)->get_IsDoubleTapEnabled(&value));
    return value;
}

template <typename D> void impl_IUIElement<D>::IsDoubleTapEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IUIElement)->put_IsDoubleTapEnabled(value));
}

template <typename D> bool impl_IUIElement<D>::IsRightTapEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IUIElement)->get_IsRightTapEnabled(&value));
    return value;
}

template <typename D> void impl_IUIElement<D>::IsRightTapEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IUIElement)->put_IsRightTapEnabled(value));
}

template <typename D> bool impl_IUIElement<D>::IsHoldingEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IUIElement)->get_IsHoldingEnabled(&value));
    return value;
}

template <typename D> void impl_IUIElement<D>::IsHoldingEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IUIElement)->put_IsHoldingEnabled(value));
}

template <typename D> Windows::UI::Xaml::Input::ManipulationModes impl_IUIElement<D>::ManipulationMode() const
{
    Windows::UI::Xaml::Input::ManipulationModes value {};
    check_hresult(WINRT_SHIM(IUIElement)->get_ManipulationMode(&value));
    return value;
}

template <typename D> void impl_IUIElement<D>::ManipulationMode(Windows::UI::Xaml::Input::ManipulationModes value) const
{
    check_hresult(WINRT_SHIM(IUIElement)->put_ManipulationMode(value));
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Input::Pointer> impl_IUIElement<D>::PointerCaptures() const
{
    Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Input::Pointer> value;
    check_hresult(WINRT_SHIM(IUIElement)->get_PointerCaptures(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IUIElement<D>::KeyUp(const Windows::UI::Xaml::Input::KeyEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUIElement)->add_KeyUp(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IUIElement> impl_IUIElement<D>::KeyUp(auto_revoke_t, const Windows::UI::Xaml::Input::KeyEventHandler & value) const
{
    return impl::make_event_revoker<D, IUIElement>(this, &ABI::Windows::UI::Xaml::IUIElement::remove_KeyUp, KeyUp(value));
}

template <typename D> void impl_IUIElement<D>::KeyUp(event_token token) const
{
    check_hresult(WINRT_SHIM(IUIElement)->remove_KeyUp(token));
}

template <typename D> event_token impl_IUIElement<D>::KeyDown(const Windows::UI::Xaml::Input::KeyEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUIElement)->add_KeyDown(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IUIElement> impl_IUIElement<D>::KeyDown(auto_revoke_t, const Windows::UI::Xaml::Input::KeyEventHandler & value) const
{
    return impl::make_event_revoker<D, IUIElement>(this, &ABI::Windows::UI::Xaml::IUIElement::remove_KeyDown, KeyDown(value));
}

template <typename D> void impl_IUIElement<D>::KeyDown(event_token token) const
{
    check_hresult(WINRT_SHIM(IUIElement)->remove_KeyDown(token));
}

template <typename D> event_token impl_IUIElement<D>::GotFocus(const Windows::UI::Xaml::RoutedEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUIElement)->add_GotFocus(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IUIElement> impl_IUIElement<D>::GotFocus(auto_revoke_t, const Windows::UI::Xaml::RoutedEventHandler & value) const
{
    return impl::make_event_revoker<D, IUIElement>(this, &ABI::Windows::UI::Xaml::IUIElement::remove_GotFocus, GotFocus(value));
}

template <typename D> void impl_IUIElement<D>::GotFocus(event_token token) const
{
    check_hresult(WINRT_SHIM(IUIElement)->remove_GotFocus(token));
}

template <typename D> event_token impl_IUIElement<D>::LostFocus(const Windows::UI::Xaml::RoutedEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUIElement)->add_LostFocus(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IUIElement> impl_IUIElement<D>::LostFocus(auto_revoke_t, const Windows::UI::Xaml::RoutedEventHandler & value) const
{
    return impl::make_event_revoker<D, IUIElement>(this, &ABI::Windows::UI::Xaml::IUIElement::remove_LostFocus, LostFocus(value));
}

template <typename D> void impl_IUIElement<D>::LostFocus(event_token token) const
{
    check_hresult(WINRT_SHIM(IUIElement)->remove_LostFocus(token));
}

template <typename D> event_token impl_IUIElement<D>::DragEnter(const Windows::UI::Xaml::DragEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUIElement)->add_DragEnter(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IUIElement> impl_IUIElement<D>::DragEnter(auto_revoke_t, const Windows::UI::Xaml::DragEventHandler & value) const
{
    return impl::make_event_revoker<D, IUIElement>(this, &ABI::Windows::UI::Xaml::IUIElement::remove_DragEnter, DragEnter(value));
}

template <typename D> void impl_IUIElement<D>::DragEnter(event_token token) const
{
    check_hresult(WINRT_SHIM(IUIElement)->remove_DragEnter(token));
}

template <typename D> event_token impl_IUIElement<D>::DragLeave(const Windows::UI::Xaml::DragEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUIElement)->add_DragLeave(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IUIElement> impl_IUIElement<D>::DragLeave(auto_revoke_t, const Windows::UI::Xaml::DragEventHandler & value) const
{
    return impl::make_event_revoker<D, IUIElement>(this, &ABI::Windows::UI::Xaml::IUIElement::remove_DragLeave, DragLeave(value));
}

template <typename D> void impl_IUIElement<D>::DragLeave(event_token token) const
{
    check_hresult(WINRT_SHIM(IUIElement)->remove_DragLeave(token));
}

template <typename D> event_token impl_IUIElement<D>::DragOver(const Windows::UI::Xaml::DragEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUIElement)->add_DragOver(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IUIElement> impl_IUIElement<D>::DragOver(auto_revoke_t, const Windows::UI::Xaml::DragEventHandler & value) const
{
    return impl::make_event_revoker<D, IUIElement>(this, &ABI::Windows::UI::Xaml::IUIElement::remove_DragOver, DragOver(value));
}

template <typename D> void impl_IUIElement<D>::DragOver(event_token token) const
{
    check_hresult(WINRT_SHIM(IUIElement)->remove_DragOver(token));
}

template <typename D> event_token impl_IUIElement<D>::Drop(const Windows::UI::Xaml::DragEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUIElement)->add_Drop(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IUIElement> impl_IUIElement<D>::Drop(auto_revoke_t, const Windows::UI::Xaml::DragEventHandler & value) const
{
    return impl::make_event_revoker<D, IUIElement>(this, &ABI::Windows::UI::Xaml::IUIElement::remove_Drop, Drop(value));
}

template <typename D> void impl_IUIElement<D>::Drop(event_token token) const
{
    check_hresult(WINRT_SHIM(IUIElement)->remove_Drop(token));
}

template <typename D> event_token impl_IUIElement<D>::PointerPressed(const Windows::UI::Xaml::Input::PointerEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUIElement)->add_PointerPressed(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IUIElement> impl_IUIElement<D>::PointerPressed(auto_revoke_t, const Windows::UI::Xaml::Input::PointerEventHandler & value) const
{
    return impl::make_event_revoker<D, IUIElement>(this, &ABI::Windows::UI::Xaml::IUIElement::remove_PointerPressed, PointerPressed(value));
}

template <typename D> void impl_IUIElement<D>::PointerPressed(event_token token) const
{
    check_hresult(WINRT_SHIM(IUIElement)->remove_PointerPressed(token));
}

template <typename D> event_token impl_IUIElement<D>::PointerMoved(const Windows::UI::Xaml::Input::PointerEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUIElement)->add_PointerMoved(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IUIElement> impl_IUIElement<D>::PointerMoved(auto_revoke_t, const Windows::UI::Xaml::Input::PointerEventHandler & value) const
{
    return impl::make_event_revoker<D, IUIElement>(this, &ABI::Windows::UI::Xaml::IUIElement::remove_PointerMoved, PointerMoved(value));
}

template <typename D> void impl_IUIElement<D>::PointerMoved(event_token token) const
{
    check_hresult(WINRT_SHIM(IUIElement)->remove_PointerMoved(token));
}

template <typename D> event_token impl_IUIElement<D>::PointerReleased(const Windows::UI::Xaml::Input::PointerEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUIElement)->add_PointerReleased(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IUIElement> impl_IUIElement<D>::PointerReleased(auto_revoke_t, const Windows::UI::Xaml::Input::PointerEventHandler & value) const
{
    return impl::make_event_revoker<D, IUIElement>(this, &ABI::Windows::UI::Xaml::IUIElement::remove_PointerReleased, PointerReleased(value));
}

template <typename D> void impl_IUIElement<D>::PointerReleased(event_token token) const
{
    check_hresult(WINRT_SHIM(IUIElement)->remove_PointerReleased(token));
}

template <typename D> event_token impl_IUIElement<D>::PointerEntered(const Windows::UI::Xaml::Input::PointerEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUIElement)->add_PointerEntered(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IUIElement> impl_IUIElement<D>::PointerEntered(auto_revoke_t, const Windows::UI::Xaml::Input::PointerEventHandler & value) const
{
    return impl::make_event_revoker<D, IUIElement>(this, &ABI::Windows::UI::Xaml::IUIElement::remove_PointerEntered, PointerEntered(value));
}

template <typename D> void impl_IUIElement<D>::PointerEntered(event_token token) const
{
    check_hresult(WINRT_SHIM(IUIElement)->remove_PointerEntered(token));
}

template <typename D> event_token impl_IUIElement<D>::PointerExited(const Windows::UI::Xaml::Input::PointerEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUIElement)->add_PointerExited(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IUIElement> impl_IUIElement<D>::PointerExited(auto_revoke_t, const Windows::UI::Xaml::Input::PointerEventHandler & value) const
{
    return impl::make_event_revoker<D, IUIElement>(this, &ABI::Windows::UI::Xaml::IUIElement::remove_PointerExited, PointerExited(value));
}

template <typename D> void impl_IUIElement<D>::PointerExited(event_token token) const
{
    check_hresult(WINRT_SHIM(IUIElement)->remove_PointerExited(token));
}

template <typename D> event_token impl_IUIElement<D>::PointerCaptureLost(const Windows::UI::Xaml::Input::PointerEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUIElement)->add_PointerCaptureLost(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IUIElement> impl_IUIElement<D>::PointerCaptureLost(auto_revoke_t, const Windows::UI::Xaml::Input::PointerEventHandler & value) const
{
    return impl::make_event_revoker<D, IUIElement>(this, &ABI::Windows::UI::Xaml::IUIElement::remove_PointerCaptureLost, PointerCaptureLost(value));
}

template <typename D> void impl_IUIElement<D>::PointerCaptureLost(event_token token) const
{
    check_hresult(WINRT_SHIM(IUIElement)->remove_PointerCaptureLost(token));
}

template <typename D> event_token impl_IUIElement<D>::PointerCanceled(const Windows::UI::Xaml::Input::PointerEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUIElement)->add_PointerCanceled(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IUIElement> impl_IUIElement<D>::PointerCanceled(auto_revoke_t, const Windows::UI::Xaml::Input::PointerEventHandler & value) const
{
    return impl::make_event_revoker<D, IUIElement>(this, &ABI::Windows::UI::Xaml::IUIElement::remove_PointerCanceled, PointerCanceled(value));
}

template <typename D> void impl_IUIElement<D>::PointerCanceled(event_token token) const
{
    check_hresult(WINRT_SHIM(IUIElement)->remove_PointerCanceled(token));
}

template <typename D> event_token impl_IUIElement<D>::PointerWheelChanged(const Windows::UI::Xaml::Input::PointerEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUIElement)->add_PointerWheelChanged(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IUIElement> impl_IUIElement<D>::PointerWheelChanged(auto_revoke_t, const Windows::UI::Xaml::Input::PointerEventHandler & value) const
{
    return impl::make_event_revoker<D, IUIElement>(this, &ABI::Windows::UI::Xaml::IUIElement::remove_PointerWheelChanged, PointerWheelChanged(value));
}

template <typename D> void impl_IUIElement<D>::PointerWheelChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IUIElement)->remove_PointerWheelChanged(token));
}

template <typename D> event_token impl_IUIElement<D>::Tapped(const Windows::UI::Xaml::Input::TappedEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUIElement)->add_Tapped(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IUIElement> impl_IUIElement<D>::Tapped(auto_revoke_t, const Windows::UI::Xaml::Input::TappedEventHandler & value) const
{
    return impl::make_event_revoker<D, IUIElement>(this, &ABI::Windows::UI::Xaml::IUIElement::remove_Tapped, Tapped(value));
}

template <typename D> void impl_IUIElement<D>::Tapped(event_token token) const
{
    check_hresult(WINRT_SHIM(IUIElement)->remove_Tapped(token));
}

template <typename D> event_token impl_IUIElement<D>::DoubleTapped(const Windows::UI::Xaml::Input::DoubleTappedEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUIElement)->add_DoubleTapped(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IUIElement> impl_IUIElement<D>::DoubleTapped(auto_revoke_t, const Windows::UI::Xaml::Input::DoubleTappedEventHandler & value) const
{
    return impl::make_event_revoker<D, IUIElement>(this, &ABI::Windows::UI::Xaml::IUIElement::remove_DoubleTapped, DoubleTapped(value));
}

template <typename D> void impl_IUIElement<D>::DoubleTapped(event_token token) const
{
    check_hresult(WINRT_SHIM(IUIElement)->remove_DoubleTapped(token));
}

template <typename D> event_token impl_IUIElement<D>::Holding(const Windows::UI::Xaml::Input::HoldingEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUIElement)->add_Holding(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IUIElement> impl_IUIElement<D>::Holding(auto_revoke_t, const Windows::UI::Xaml::Input::HoldingEventHandler & value) const
{
    return impl::make_event_revoker<D, IUIElement>(this, &ABI::Windows::UI::Xaml::IUIElement::remove_Holding, Holding(value));
}

template <typename D> void impl_IUIElement<D>::Holding(event_token token) const
{
    check_hresult(WINRT_SHIM(IUIElement)->remove_Holding(token));
}

template <typename D> event_token impl_IUIElement<D>::RightTapped(const Windows::UI::Xaml::Input::RightTappedEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUIElement)->add_RightTapped(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IUIElement> impl_IUIElement<D>::RightTapped(auto_revoke_t, const Windows::UI::Xaml::Input::RightTappedEventHandler & value) const
{
    return impl::make_event_revoker<D, IUIElement>(this, &ABI::Windows::UI::Xaml::IUIElement::remove_RightTapped, RightTapped(value));
}

template <typename D> void impl_IUIElement<D>::RightTapped(event_token token) const
{
    check_hresult(WINRT_SHIM(IUIElement)->remove_RightTapped(token));
}

template <typename D> event_token impl_IUIElement<D>::ManipulationStarting(const Windows::UI::Xaml::Input::ManipulationStartingEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUIElement)->add_ManipulationStarting(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IUIElement> impl_IUIElement<D>::ManipulationStarting(auto_revoke_t, const Windows::UI::Xaml::Input::ManipulationStartingEventHandler & value) const
{
    return impl::make_event_revoker<D, IUIElement>(this, &ABI::Windows::UI::Xaml::IUIElement::remove_ManipulationStarting, ManipulationStarting(value));
}

template <typename D> void impl_IUIElement<D>::ManipulationStarting(event_token token) const
{
    check_hresult(WINRT_SHIM(IUIElement)->remove_ManipulationStarting(token));
}

template <typename D> event_token impl_IUIElement<D>::ManipulationInertiaStarting(const Windows::UI::Xaml::Input::ManipulationInertiaStartingEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUIElement)->add_ManipulationInertiaStarting(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IUIElement> impl_IUIElement<D>::ManipulationInertiaStarting(auto_revoke_t, const Windows::UI::Xaml::Input::ManipulationInertiaStartingEventHandler & value) const
{
    return impl::make_event_revoker<D, IUIElement>(this, &ABI::Windows::UI::Xaml::IUIElement::remove_ManipulationInertiaStarting, ManipulationInertiaStarting(value));
}

template <typename D> void impl_IUIElement<D>::ManipulationInertiaStarting(event_token token) const
{
    check_hresult(WINRT_SHIM(IUIElement)->remove_ManipulationInertiaStarting(token));
}

template <typename D> event_token impl_IUIElement<D>::ManipulationStarted(const Windows::UI::Xaml::Input::ManipulationStartedEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUIElement)->add_ManipulationStarted(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IUIElement> impl_IUIElement<D>::ManipulationStarted(auto_revoke_t, const Windows::UI::Xaml::Input::ManipulationStartedEventHandler & value) const
{
    return impl::make_event_revoker<D, IUIElement>(this, &ABI::Windows::UI::Xaml::IUIElement::remove_ManipulationStarted, ManipulationStarted(value));
}

template <typename D> void impl_IUIElement<D>::ManipulationStarted(event_token token) const
{
    check_hresult(WINRT_SHIM(IUIElement)->remove_ManipulationStarted(token));
}

template <typename D> event_token impl_IUIElement<D>::ManipulationDelta(const Windows::UI::Xaml::Input::ManipulationDeltaEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUIElement)->add_ManipulationDelta(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IUIElement> impl_IUIElement<D>::ManipulationDelta(auto_revoke_t, const Windows::UI::Xaml::Input::ManipulationDeltaEventHandler & value) const
{
    return impl::make_event_revoker<D, IUIElement>(this, &ABI::Windows::UI::Xaml::IUIElement::remove_ManipulationDelta, ManipulationDelta(value));
}

template <typename D> void impl_IUIElement<D>::ManipulationDelta(event_token token) const
{
    check_hresult(WINRT_SHIM(IUIElement)->remove_ManipulationDelta(token));
}

template <typename D> event_token impl_IUIElement<D>::ManipulationCompleted(const Windows::UI::Xaml::Input::ManipulationCompletedEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUIElement)->add_ManipulationCompleted(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IUIElement> impl_IUIElement<D>::ManipulationCompleted(auto_revoke_t, const Windows::UI::Xaml::Input::ManipulationCompletedEventHandler & value) const
{
    return impl::make_event_revoker<D, IUIElement>(this, &ABI::Windows::UI::Xaml::IUIElement::remove_ManipulationCompleted, ManipulationCompleted(value));
}

template <typename D> void impl_IUIElement<D>::ManipulationCompleted(event_token token) const
{
    check_hresult(WINRT_SHIM(IUIElement)->remove_ManipulationCompleted(token));
}

template <typename D> void impl_IUIElement<D>::Measure(const Windows::Foundation::Size & availableSize) const
{
    check_hresult(WINRT_SHIM(IUIElement)->abi_Measure(get_abi(availableSize)));
}

template <typename D> void impl_IUIElement<D>::Arrange(const Windows::Foundation::Rect & finalRect) const
{
    check_hresult(WINRT_SHIM(IUIElement)->abi_Arrange(get_abi(finalRect)));
}

template <typename D> bool impl_IUIElement<D>::CapturePointer(const Windows::UI::Xaml::Input::Pointer & value) const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IUIElement)->abi_CapturePointer(get_abi(value), &returnValue));
    return returnValue;
}

template <typename D> void impl_IUIElement<D>::ReleasePointerCapture(const Windows::UI::Xaml::Input::Pointer & value) const
{
    check_hresult(WINRT_SHIM(IUIElement)->abi_ReleasePointerCapture(get_abi(value)));
}

template <typename D> void impl_IUIElement<D>::ReleasePointerCaptures() const
{
    check_hresult(WINRT_SHIM(IUIElement)->abi_ReleasePointerCaptures());
}

template <typename D> void impl_IUIElement<D>::AddHandler(const Windows::UI::Xaml::RoutedEvent & routedEvent, const Windows::Foundation::IInspectable & handler, bool handledEventsToo) const
{
    check_hresult(WINRT_SHIM(IUIElement)->abi_AddHandler(get_abi(routedEvent), get_abi(handler), handledEventsToo));
}

template <typename D> void impl_IUIElement<D>::RemoveHandler(const Windows::UI::Xaml::RoutedEvent & routedEvent, const Windows::Foundation::IInspectable & handler) const
{
    check_hresult(WINRT_SHIM(IUIElement)->abi_RemoveHandler(get_abi(routedEvent), get_abi(handler)));
}

template <typename D> Windows::UI::Xaml::Media::GeneralTransform impl_IUIElement<D>::TransformToVisual(const Windows::UI::Xaml::UIElement & visual) const
{
    Windows::UI::Xaml::Media::GeneralTransform returnValue { nullptr };
    check_hresult(WINRT_SHIM(IUIElement)->abi_TransformToVisual(get_abi(visual), put_abi(returnValue)));
    return returnValue;
}

template <typename D> void impl_IUIElement<D>::InvalidateMeasure() const
{
    check_hresult(WINRT_SHIM(IUIElement)->abi_InvalidateMeasure());
}

template <typename D> void impl_IUIElement<D>::InvalidateArrange() const
{
    check_hresult(WINRT_SHIM(IUIElement)->abi_InvalidateArrange());
}

template <typename D> void impl_IUIElement<D>::UpdateLayout() const
{
    check_hresult(WINRT_SHIM(IUIElement)->abi_UpdateLayout());
}

template <typename D> Windows::UI::Xaml::Automation::Peers::AutomationPeer impl_IUIElementOverrides<D>::OnCreateAutomationPeer() const
{
    Windows::UI::Xaml::Automation::Peers::AutomationPeer returnValue { nullptr };
    check_hresult(WINRT_SHIM(IUIElementOverrides)->abi_OnCreateAutomationPeer(put_abi(returnValue)));
    return returnValue;
}

template <typename D> void impl_IUIElementOverrides<D>::OnDisconnectVisualChildren() const
{
    check_hresult(WINRT_SHIM(IUIElementOverrides)->abi_OnDisconnectVisualChildren());
}

template <typename D> Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IIterable<Windows::Foundation::Point>> impl_IUIElementOverrides<D>::FindSubElementsForTouchTargeting(const Windows::Foundation::Point & point, const Windows::Foundation::Rect & boundingRect) const
{
    Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IIterable<Windows::Foundation::Point>> returnValue;
    check_hresult(WINRT_SHIM(IUIElementOverrides)->abi_FindSubElementsForTouchTargeting(get_abi(point), get_abi(boundingRect), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::RoutedEvent impl_IUIElementStatics<D>::KeyDownEvent() const
{
    Windows::UI::Xaml::RoutedEvent value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_KeyDownEvent(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::RoutedEvent impl_IUIElementStatics<D>::KeyUpEvent() const
{
    Windows::UI::Xaml::RoutedEvent value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_KeyUpEvent(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::RoutedEvent impl_IUIElementStatics<D>::PointerEnteredEvent() const
{
    Windows::UI::Xaml::RoutedEvent value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_PointerEnteredEvent(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::RoutedEvent impl_IUIElementStatics<D>::PointerPressedEvent() const
{
    Windows::UI::Xaml::RoutedEvent value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_PointerPressedEvent(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::RoutedEvent impl_IUIElementStatics<D>::PointerMovedEvent() const
{
    Windows::UI::Xaml::RoutedEvent value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_PointerMovedEvent(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::RoutedEvent impl_IUIElementStatics<D>::PointerReleasedEvent() const
{
    Windows::UI::Xaml::RoutedEvent value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_PointerReleasedEvent(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::RoutedEvent impl_IUIElementStatics<D>::PointerExitedEvent() const
{
    Windows::UI::Xaml::RoutedEvent value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_PointerExitedEvent(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::RoutedEvent impl_IUIElementStatics<D>::PointerCaptureLostEvent() const
{
    Windows::UI::Xaml::RoutedEvent value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_PointerCaptureLostEvent(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::RoutedEvent impl_IUIElementStatics<D>::PointerCanceledEvent() const
{
    Windows::UI::Xaml::RoutedEvent value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_PointerCanceledEvent(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::RoutedEvent impl_IUIElementStatics<D>::PointerWheelChangedEvent() const
{
    Windows::UI::Xaml::RoutedEvent value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_PointerWheelChangedEvent(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::RoutedEvent impl_IUIElementStatics<D>::TappedEvent() const
{
    Windows::UI::Xaml::RoutedEvent value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_TappedEvent(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::RoutedEvent impl_IUIElementStatics<D>::DoubleTappedEvent() const
{
    Windows::UI::Xaml::RoutedEvent value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_DoubleTappedEvent(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::RoutedEvent impl_IUIElementStatics<D>::HoldingEvent() const
{
    Windows::UI::Xaml::RoutedEvent value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_HoldingEvent(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::RoutedEvent impl_IUIElementStatics<D>::RightTappedEvent() const
{
    Windows::UI::Xaml::RoutedEvent value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_RightTappedEvent(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::RoutedEvent impl_IUIElementStatics<D>::ManipulationStartingEvent() const
{
    Windows::UI::Xaml::RoutedEvent value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_ManipulationStartingEvent(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::RoutedEvent impl_IUIElementStatics<D>::ManipulationInertiaStartingEvent() const
{
    Windows::UI::Xaml::RoutedEvent value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_ManipulationInertiaStartingEvent(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::RoutedEvent impl_IUIElementStatics<D>::ManipulationStartedEvent() const
{
    Windows::UI::Xaml::RoutedEvent value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_ManipulationStartedEvent(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::RoutedEvent impl_IUIElementStatics<D>::ManipulationDeltaEvent() const
{
    Windows::UI::Xaml::RoutedEvent value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_ManipulationDeltaEvent(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::RoutedEvent impl_IUIElementStatics<D>::ManipulationCompletedEvent() const
{
    Windows::UI::Xaml::RoutedEvent value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_ManipulationCompletedEvent(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::RoutedEvent impl_IUIElementStatics<D>::DragEnterEvent() const
{
    Windows::UI::Xaml::RoutedEvent value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_DragEnterEvent(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::RoutedEvent impl_IUIElementStatics<D>::DragLeaveEvent() const
{
    Windows::UI::Xaml::RoutedEvent value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_DragLeaveEvent(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::RoutedEvent impl_IUIElementStatics<D>::DragOverEvent() const
{
    Windows::UI::Xaml::RoutedEvent value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_DragOverEvent(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::RoutedEvent impl_IUIElementStatics<D>::DropEvent() const
{
    Windows::UI::Xaml::RoutedEvent value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_DropEvent(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IUIElementStatics<D>::AllowDropProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_AllowDropProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IUIElementStatics<D>::OpacityProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_OpacityProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IUIElementStatics<D>::ClipProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_ClipProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IUIElementStatics<D>::RenderTransformProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_RenderTransformProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IUIElementStatics<D>::ProjectionProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_ProjectionProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IUIElementStatics<D>::RenderTransformOriginProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_RenderTransformOriginProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IUIElementStatics<D>::IsHitTestVisibleProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_IsHitTestVisibleProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IUIElementStatics<D>::VisibilityProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_VisibilityProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IUIElementStatics<D>::UseLayoutRoundingProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_UseLayoutRoundingProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IUIElementStatics<D>::TransitionsProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_TransitionsProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IUIElementStatics<D>::CacheModeProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_CacheModeProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IUIElementStatics<D>::IsTapEnabledProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_IsTapEnabledProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IUIElementStatics<D>::IsDoubleTapEnabledProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_IsDoubleTapEnabledProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IUIElementStatics<D>::IsRightTapEnabledProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_IsRightTapEnabledProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IUIElementStatics<D>::IsHoldingEnabledProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_IsHoldingEnabledProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IUIElementStatics<D>::ManipulationModeProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_ManipulationModeProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IUIElementStatics<D>::PointerCapturesProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics)->get_PointerCapturesProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::ElementCompositeMode impl_IUIElement2<D>::CompositeMode() const
{
    Windows::UI::Xaml::Media::ElementCompositeMode value {};
    check_hresult(WINRT_SHIM(IUIElement2)->get_CompositeMode(&value));
    return value;
}

template <typename D> void impl_IUIElement2<D>::CompositeMode(Windows::UI::Xaml::Media::ElementCompositeMode value) const
{
    check_hresult(WINRT_SHIM(IUIElement2)->put_CompositeMode(value));
}

template <typename D> bool impl_IUIElement2<D>::CancelDirectManipulations() const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IUIElement2)->abi_CancelDirectManipulations(&returnValue));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IUIElementStatics2<D>::CompositeModeProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics2)->get_CompositeModeProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::Media3D::Transform3D impl_IUIElement3<D>::Transform3D() const
{
    Windows::UI::Xaml::Media::Media3D::Transform3D value { nullptr };
    check_hresult(WINRT_SHIM(IUIElement3)->get_Transform3D(put_abi(value)));
    return value;
}

template <typename D> void impl_IUIElement3<D>::Transform3D(const Windows::UI::Xaml::Media::Media3D::Transform3D & value) const
{
    check_hresult(WINRT_SHIM(IUIElement3)->put_Transform3D(get_abi(value)));
}

template <typename D> bool impl_IUIElement3<D>::CanDrag() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IUIElement3)->get_CanDrag(&value));
    return value;
}

template <typename D> void impl_IUIElement3<D>::CanDrag(bool value) const
{
    check_hresult(WINRT_SHIM(IUIElement3)->put_CanDrag(value));
}

template <typename D> event_token impl_IUIElement3<D>::DragStarting(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::DragStartingEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUIElement3)->add_DragStarting(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IUIElement3> impl_IUIElement3<D>::DragStarting(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::DragStartingEventArgs> & value) const
{
    return impl::make_event_revoker<D, IUIElement3>(this, &ABI::Windows::UI::Xaml::IUIElement3::remove_DragStarting, DragStarting(value));
}

template <typename D> void impl_IUIElement3<D>::DragStarting(event_token token) const
{
    check_hresult(WINRT_SHIM(IUIElement3)->remove_DragStarting(token));
}

template <typename D> event_token impl_IUIElement3<D>::DropCompleted(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::DropCompletedEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUIElement3)->add_DropCompleted(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IUIElement3> impl_IUIElement3<D>::DropCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::DropCompletedEventArgs> & value) const
{
    return impl::make_event_revoker<D, IUIElement3>(this, &ABI::Windows::UI::Xaml::IUIElement3::remove_DropCompleted, DropCompleted(value));
}

template <typename D> void impl_IUIElement3<D>::DropCompleted(event_token token) const
{
    check_hresult(WINRT_SHIM(IUIElement3)->remove_DropCompleted(token));
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::DataTransfer::DataPackageOperation> impl_IUIElement3<D>::StartDragAsync(const Windows::UI::Input::PointerPoint & pointerPoint) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::DataTransfer::DataPackageOperation> returnValue;
    check_hresult(WINRT_SHIM(IUIElement3)->abi_StartDragAsync(get_abi(pointerPoint), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IUIElementStatics3<D>::Transform3DProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics3)->get_Transform3DProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IUIElementStatics3<D>::CanDragProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics3)->get_CanDragProperty(put_abi(value)));
    return value;
}

template <typename D> bool impl_IUIElementStatics3<D>::TryStartDirectManipulation(const Windows::UI::Xaml::Input::Pointer & value) const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IUIElementStatics3)->abi_TryStartDirectManipulation(get_abi(value), &returnValue));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::Controls::Primitives::FlyoutBase impl_IUIElement4<D>::ContextFlyout() const
{
    Windows::UI::Xaml::Controls::Primitives::FlyoutBase value { nullptr };
    check_hresult(WINRT_SHIM(IUIElement4)->get_ContextFlyout(put_abi(value)));
    return value;
}

template <typename D> void impl_IUIElement4<D>::ContextFlyout(const Windows::UI::Xaml::Controls::Primitives::FlyoutBase & value) const
{
    check_hresult(WINRT_SHIM(IUIElement4)->put_ContextFlyout(get_abi(value)));
}

template <typename D> bool impl_IUIElement4<D>::ExitDisplayModeOnAccessKeyInvoked() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IUIElement4)->get_ExitDisplayModeOnAccessKeyInvoked(&value));
    return value;
}

template <typename D> void impl_IUIElement4<D>::ExitDisplayModeOnAccessKeyInvoked(bool value) const
{
    check_hresult(WINRT_SHIM(IUIElement4)->put_ExitDisplayModeOnAccessKeyInvoked(value));
}

template <typename D> bool impl_IUIElement4<D>::IsAccessKeyScope() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IUIElement4)->get_IsAccessKeyScope(&value));
    return value;
}

template <typename D> void impl_IUIElement4<D>::IsAccessKeyScope(bool value) const
{
    check_hresult(WINRT_SHIM(IUIElement4)->put_IsAccessKeyScope(value));
}

template <typename D> Windows::UI::Xaml::DependencyObject impl_IUIElement4<D>::AccessKeyScopeOwner() const
{
    Windows::UI::Xaml::DependencyObject value { nullptr };
    check_hresult(WINRT_SHIM(IUIElement4)->get_AccessKeyScopeOwner(put_abi(value)));
    return value;
}

template <typename D> void impl_IUIElement4<D>::AccessKeyScopeOwner(const Windows::UI::Xaml::DependencyObject & value) const
{
    check_hresult(WINRT_SHIM(IUIElement4)->put_AccessKeyScopeOwner(get_abi(value)));
}

template <typename D> hstring impl_IUIElement4<D>::AccessKey() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUIElement4)->get_AccessKey(put_abi(value)));
    return value;
}

template <typename D> void impl_IUIElement4<D>::AccessKey(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IUIElement4)->put_AccessKey(get_abi(value)));
}

template <typename D> event_token impl_IUIElement4<D>::ContextRequested(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::Input::ContextRequestedEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUIElement4)->add_ContextRequested(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IUIElement4> impl_IUIElement4<D>::ContextRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::Input::ContextRequestedEventArgs> & value) const
{
    return impl::make_event_revoker<D, IUIElement4>(this, &ABI::Windows::UI::Xaml::IUIElement4::remove_ContextRequested, ContextRequested(value));
}

template <typename D> void impl_IUIElement4<D>::ContextRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IUIElement4)->remove_ContextRequested(token));
}

template <typename D> event_token impl_IUIElement4<D>::ContextCanceled(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::RoutedEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUIElement4)->add_ContextCanceled(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IUIElement4> impl_IUIElement4<D>::ContextCanceled(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::RoutedEventArgs> & value) const
{
    return impl::make_event_revoker<D, IUIElement4>(this, &ABI::Windows::UI::Xaml::IUIElement4::remove_ContextCanceled, ContextCanceled(value));
}

template <typename D> void impl_IUIElement4<D>::ContextCanceled(event_token token) const
{
    check_hresult(WINRT_SHIM(IUIElement4)->remove_ContextCanceled(token));
}

template <typename D> event_token impl_IUIElement4<D>::AccessKeyDisplayRequested(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::Input::AccessKeyDisplayRequestedEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUIElement4)->add_AccessKeyDisplayRequested(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IUIElement4> impl_IUIElement4<D>::AccessKeyDisplayRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::Input::AccessKeyDisplayRequestedEventArgs> & value) const
{
    return impl::make_event_revoker<D, IUIElement4>(this, &ABI::Windows::UI::Xaml::IUIElement4::remove_AccessKeyDisplayRequested, AccessKeyDisplayRequested(value));
}

template <typename D> void impl_IUIElement4<D>::AccessKeyDisplayRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IUIElement4)->remove_AccessKeyDisplayRequested(token));
}

template <typename D> event_token impl_IUIElement4<D>::AccessKeyDisplayDismissed(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::Input::AccessKeyDisplayDismissedEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUIElement4)->add_AccessKeyDisplayDismissed(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IUIElement4> impl_IUIElement4<D>::AccessKeyDisplayDismissed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::Input::AccessKeyDisplayDismissedEventArgs> & value) const
{
    return impl::make_event_revoker<D, IUIElement4>(this, &ABI::Windows::UI::Xaml::IUIElement4::remove_AccessKeyDisplayDismissed, AccessKeyDisplayDismissed(value));
}

template <typename D> void impl_IUIElement4<D>::AccessKeyDisplayDismissed(event_token token) const
{
    check_hresult(WINRT_SHIM(IUIElement4)->remove_AccessKeyDisplayDismissed(token));
}

template <typename D> event_token impl_IUIElement4<D>::AccessKeyInvoked(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::Input::AccessKeyInvokedEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IUIElement4)->add_AccessKeyInvoked(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IUIElement4> impl_IUIElement4<D>::AccessKeyInvoked(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::Input::AccessKeyInvokedEventArgs> & value) const
{
    return impl::make_event_revoker<D, IUIElement4>(this, &ABI::Windows::UI::Xaml::IUIElement4::remove_AccessKeyInvoked, AccessKeyInvoked(value));
}

template <typename D> void impl_IUIElement4<D>::AccessKeyInvoked(event_token token) const
{
    check_hresult(WINRT_SHIM(IUIElement4)->remove_AccessKeyInvoked(token));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IUIElementStatics4<D>::ContextFlyoutProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics4)->get_ContextFlyoutProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IUIElementStatics4<D>::ExitDisplayModeOnAccessKeyInvokedProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics4)->get_ExitDisplayModeOnAccessKeyInvokedProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IUIElementStatics4<D>::IsAccessKeyScopeProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics4)->get_IsAccessKeyScopeProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IUIElementStatics4<D>::AccessKeyScopeOwnerProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics4)->get_AccessKeyScopeOwnerProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IUIElementStatics4<D>::AccessKeyProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IUIElementStatics4)->get_AccessKeyProperty(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IVisualState<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVisualState)->get_Name(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::Animation::Storyboard impl_IVisualState<D>::Storyboard() const
{
    Windows::UI::Xaml::Media::Animation::Storyboard value { nullptr };
    check_hresult(WINRT_SHIM(IVisualState)->get_Storyboard(put_abi(value)));
    return value;
}

template <typename D> void impl_IVisualState<D>::Storyboard(const Windows::UI::Xaml::Media::Animation::Storyboard & value) const
{
    check_hresult(WINRT_SHIM(IVisualState)->put_Storyboard(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::SetterBaseCollection impl_IVisualState2<D>::Setters() const
{
    Windows::UI::Xaml::SetterBaseCollection value { nullptr };
    check_hresult(WINRT_SHIM(IVisualState2)->get_Setters(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::UI::Xaml::StateTriggerBase> impl_IVisualState2<D>::StateTriggers() const
{
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::StateTriggerBase> value;
    check_hresult(WINRT_SHIM(IVisualState2)->get_StateTriggers(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IVisualStateGroup<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVisualStateGroup)->get_Name(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::UI::Xaml::VisualTransition> impl_IVisualStateGroup<D>::Transitions() const
{
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::VisualTransition> value;
    check_hresult(WINRT_SHIM(IVisualStateGroup)->get_Transitions(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::UI::Xaml::VisualState> impl_IVisualStateGroup<D>::States() const
{
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::VisualState> value;
    check_hresult(WINRT_SHIM(IVisualStateGroup)->get_States(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::VisualState impl_IVisualStateGroup<D>::CurrentState() const
{
    Windows::UI::Xaml::VisualState value { nullptr };
    check_hresult(WINRT_SHIM(IVisualStateGroup)->get_CurrentState(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IVisualStateGroup<D>::CurrentStateChanged(const Windows::UI::Xaml::VisualStateChangedEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IVisualStateGroup)->add_CurrentStateChanged(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IVisualStateGroup> impl_IVisualStateGroup<D>::CurrentStateChanged(auto_revoke_t, const Windows::UI::Xaml::VisualStateChangedEventHandler & value) const
{
    return impl::make_event_revoker<D, IVisualStateGroup>(this, &ABI::Windows::UI::Xaml::IVisualStateGroup::remove_CurrentStateChanged, CurrentStateChanged(value));
}

template <typename D> void impl_IVisualStateGroup<D>::CurrentStateChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IVisualStateGroup)->remove_CurrentStateChanged(token));
}

template <typename D> event_token impl_IVisualStateGroup<D>::CurrentStateChanging(const Windows::UI::Xaml::VisualStateChangedEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IVisualStateGroup)->add_CurrentStateChanging(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IVisualStateGroup> impl_IVisualStateGroup<D>::CurrentStateChanging(auto_revoke_t, const Windows::UI::Xaml::VisualStateChangedEventHandler & value) const
{
    return impl::make_event_revoker<D, IVisualStateGroup>(this, &ABI::Windows::UI::Xaml::IVisualStateGroup::remove_CurrentStateChanging, CurrentStateChanging(value));
}

template <typename D> void impl_IVisualStateGroup<D>::CurrentStateChanging(event_token token) const
{
    check_hresult(WINRT_SHIM(IVisualStateGroup)->remove_CurrentStateChanging(token));
}

template <typename D> bool impl_IVisualStateManagerOverrides<D>::GoToStateCore(const Windows::UI::Xaml::Controls::Control & control, const Windows::UI::Xaml::FrameworkElement & templateRoot, hstring_view stateName, const Windows::UI::Xaml::VisualStateGroup & group, const Windows::UI::Xaml::VisualState & state, bool useTransitions) const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IVisualStateManagerOverrides)->abi_GoToStateCore(get_abi(control), get_abi(templateRoot), get_abi(stateName), get_abi(group), get_abi(state), useTransitions, &returnValue));
    return returnValue;
}

template <typename D> void impl_IVisualStateManagerProtected<D>::RaiseCurrentStateChanging(const Windows::UI::Xaml::VisualStateGroup & stateGroup, const Windows::UI::Xaml::VisualState & oldState, const Windows::UI::Xaml::VisualState & newState, const Windows::UI::Xaml::Controls::Control & control) const
{
    check_hresult(WINRT_SHIM(IVisualStateManagerProtected)->abi_RaiseCurrentStateChanging(get_abi(stateGroup), get_abi(oldState), get_abi(newState), get_abi(control)));
}

template <typename D> void impl_IVisualStateManagerProtected<D>::RaiseCurrentStateChanged(const Windows::UI::Xaml::VisualStateGroup & stateGroup, const Windows::UI::Xaml::VisualState & oldState, const Windows::UI::Xaml::VisualState & newState, const Windows::UI::Xaml::Controls::Control & control) const
{
    check_hresult(WINRT_SHIM(IVisualStateManagerProtected)->abi_RaiseCurrentStateChanged(get_abi(stateGroup), get_abi(oldState), get_abi(newState), get_abi(control)));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::UI::Xaml::VisualStateGroup> impl_IVisualStateManagerStatics<D>::GetVisualStateGroups(const Windows::UI::Xaml::FrameworkElement & obj) const
{
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::VisualStateGroup> value;
    check_hresult(WINRT_SHIM(IVisualStateManagerStatics)->abi_GetVisualStateGroups(get_abi(obj), put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IVisualStateManagerStatics<D>::CustomVisualStateManagerProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IVisualStateManagerStatics)->get_CustomVisualStateManagerProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::VisualStateManager impl_IVisualStateManagerStatics<D>::GetCustomVisualStateManager(const Windows::UI::Xaml::FrameworkElement & obj) const
{
    Windows::UI::Xaml::VisualStateManager value { nullptr };
    check_hresult(WINRT_SHIM(IVisualStateManagerStatics)->abi_GetCustomVisualStateManager(get_abi(obj), put_abi(value)));
    return value;
}

template <typename D> void impl_IVisualStateManagerStatics<D>::SetCustomVisualStateManager(const Windows::UI::Xaml::FrameworkElement & obj, const Windows::UI::Xaml::VisualStateManager & value) const
{
    check_hresult(WINRT_SHIM(IVisualStateManagerStatics)->abi_SetCustomVisualStateManager(get_abi(obj), get_abi(value)));
}

template <typename D> bool impl_IVisualStateManagerStatics<D>::GoToState(const Windows::UI::Xaml::Controls::Control & control, hstring_view stateName, bool useTransitions) const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IVisualStateManagerStatics)->abi_GoToState(get_abi(control), get_abi(stateName), useTransitions, &returnValue));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::VisualStateManager impl_IVisualStateManagerFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::VisualStateManager instance { nullptr };
    check_hresult(WINRT_SHIM(IVisualStateManagerFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Duration impl_IVisualTransition<D>::GeneratedDuration() const
{
    Windows::UI::Xaml::Duration value {};
    check_hresult(WINRT_SHIM(IVisualTransition)->get_GeneratedDuration(put_abi(value)));
    return value;
}

template <typename D> void impl_IVisualTransition<D>::GeneratedDuration(const Windows::UI::Xaml::Duration & value) const
{
    check_hresult(WINRT_SHIM(IVisualTransition)->put_GeneratedDuration(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Media::Animation::EasingFunctionBase impl_IVisualTransition<D>::GeneratedEasingFunction() const
{
    Windows::UI::Xaml::Media::Animation::EasingFunctionBase value { nullptr };
    check_hresult(WINRT_SHIM(IVisualTransition)->get_GeneratedEasingFunction(put_abi(value)));
    return value;
}

template <typename D> void impl_IVisualTransition<D>::GeneratedEasingFunction(const Windows::UI::Xaml::Media::Animation::EasingFunctionBase & value) const
{
    check_hresult(WINRT_SHIM(IVisualTransition)->put_GeneratedEasingFunction(get_abi(value)));
}

template <typename D> hstring impl_IVisualTransition<D>::To() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVisualTransition)->get_To(put_abi(value)));
    return value;
}

template <typename D> void impl_IVisualTransition<D>::To(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IVisualTransition)->put_To(get_abi(value)));
}

template <typename D> hstring impl_IVisualTransition<D>::From() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVisualTransition)->get_From(put_abi(value)));
    return value;
}

template <typename D> void impl_IVisualTransition<D>::From(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IVisualTransition)->put_From(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Media::Animation::Storyboard impl_IVisualTransition<D>::Storyboard() const
{
    Windows::UI::Xaml::Media::Animation::Storyboard value { nullptr };
    check_hresult(WINRT_SHIM(IVisualTransition)->get_Storyboard(put_abi(value)));
    return value;
}

template <typename D> void impl_IVisualTransition<D>::Storyboard(const Windows::UI::Xaml::Media::Animation::Storyboard & value) const
{
    check_hresult(WINRT_SHIM(IVisualTransition)->put_Storyboard(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::VisualTransition impl_IVisualTransitionFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::VisualTransition instance { nullptr };
    check_hresult(WINRT_SHIM(IVisualTransitionFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> double impl_IAdaptiveTrigger<D>::MinWindowWidth() const
{
    double value {};
    check_hresult(WINRT_SHIM(IAdaptiveTrigger)->get_MinWindowWidth(&value));
    return value;
}

template <typename D> void impl_IAdaptiveTrigger<D>::MinWindowWidth(double value) const
{
    check_hresult(WINRT_SHIM(IAdaptiveTrigger)->put_MinWindowWidth(value));
}

template <typename D> double impl_IAdaptiveTrigger<D>::MinWindowHeight() const
{
    double value {};
    check_hresult(WINRT_SHIM(IAdaptiveTrigger)->get_MinWindowHeight(&value));
    return value;
}

template <typename D> void impl_IAdaptiveTrigger<D>::MinWindowHeight(double value) const
{
    check_hresult(WINRT_SHIM(IAdaptiveTrigger)->put_MinWindowHeight(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IAdaptiveTriggerStatics<D>::MinWindowWidthProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IAdaptiveTriggerStatics)->get_MinWindowWidthProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IAdaptiveTriggerStatics<D>::MinWindowHeightProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IAdaptiveTriggerStatics)->get_MinWindowHeightProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::AdaptiveTrigger impl_IAdaptiveTriggerFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::AdaptiveTrigger instance { nullptr };
    check_hresult(WINRT_SHIM(IAdaptiveTriggerFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::RoutedEvent impl_IEventTrigger<D>::RoutedEvent() const
{
    Windows::UI::Xaml::RoutedEvent value { nullptr };
    check_hresult(WINRT_SHIM(IEventTrigger)->get_RoutedEvent(put_abi(value)));
    return value;
}

template <typename D> void impl_IEventTrigger<D>::RoutedEvent(const Windows::UI::Xaml::RoutedEvent & value) const
{
    check_hresult(WINRT_SHIM(IEventTrigger)->put_RoutedEvent(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::TriggerActionCollection impl_IEventTrigger<D>::Actions() const
{
    Windows::UI::Xaml::TriggerActionCollection value { nullptr };
    check_hresult(WINRT_SHIM(IEventTrigger)->get_Actions(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::TriggerCollection impl_IFrameworkElement<D>::Triggers() const
{
    Windows::UI::Xaml::TriggerCollection value { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElement)->get_Triggers(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::ResourceDictionary impl_IFrameworkElement<D>::Resources() const
{
    Windows::UI::Xaml::ResourceDictionary value { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElement)->get_Resources(put_abi(value)));
    return value;
}

template <typename D> void impl_IFrameworkElement<D>::Resources(const Windows::UI::Xaml::ResourceDictionary & value) const
{
    check_hresult(WINRT_SHIM(IFrameworkElement)->put_Resources(get_abi(value)));
}

template <typename D> Windows::Foundation::IInspectable impl_IFrameworkElement<D>::Tag() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IFrameworkElement)->get_Tag(put_abi(value)));
    return value;
}

template <typename D> void impl_IFrameworkElement<D>::Tag(const Windows::Foundation::IInspectable & value) const
{
    check_hresult(WINRT_SHIM(IFrameworkElement)->put_Tag(get_abi(value)));
}

template <typename D> hstring impl_IFrameworkElement<D>::Language() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IFrameworkElement)->get_Language(put_abi(value)));
    return value;
}

template <typename D> void impl_IFrameworkElement<D>::Language(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IFrameworkElement)->put_Language(get_abi(value)));
}

template <typename D> double impl_IFrameworkElement<D>::ActualWidth() const
{
    double value {};
    check_hresult(WINRT_SHIM(IFrameworkElement)->get_ActualWidth(&value));
    return value;
}

template <typename D> double impl_IFrameworkElement<D>::ActualHeight() const
{
    double value {};
    check_hresult(WINRT_SHIM(IFrameworkElement)->get_ActualHeight(&value));
    return value;
}

template <typename D> double impl_IFrameworkElement<D>::Width() const
{
    double value {};
    check_hresult(WINRT_SHIM(IFrameworkElement)->get_Width(&value));
    return value;
}

template <typename D> void impl_IFrameworkElement<D>::Width(double value) const
{
    check_hresult(WINRT_SHIM(IFrameworkElement)->put_Width(value));
}

template <typename D> double impl_IFrameworkElement<D>::Height() const
{
    double value {};
    check_hresult(WINRT_SHIM(IFrameworkElement)->get_Height(&value));
    return value;
}

template <typename D> void impl_IFrameworkElement<D>::Height(double value) const
{
    check_hresult(WINRT_SHIM(IFrameworkElement)->put_Height(value));
}

template <typename D> double impl_IFrameworkElement<D>::MinWidth() const
{
    double value {};
    check_hresult(WINRT_SHIM(IFrameworkElement)->get_MinWidth(&value));
    return value;
}

template <typename D> void impl_IFrameworkElement<D>::MinWidth(double value) const
{
    check_hresult(WINRT_SHIM(IFrameworkElement)->put_MinWidth(value));
}

template <typename D> double impl_IFrameworkElement<D>::MaxWidth() const
{
    double value {};
    check_hresult(WINRT_SHIM(IFrameworkElement)->get_MaxWidth(&value));
    return value;
}

template <typename D> void impl_IFrameworkElement<D>::MaxWidth(double value) const
{
    check_hresult(WINRT_SHIM(IFrameworkElement)->put_MaxWidth(value));
}

template <typename D> double impl_IFrameworkElement<D>::MinHeight() const
{
    double value {};
    check_hresult(WINRT_SHIM(IFrameworkElement)->get_MinHeight(&value));
    return value;
}

template <typename D> void impl_IFrameworkElement<D>::MinHeight(double value) const
{
    check_hresult(WINRT_SHIM(IFrameworkElement)->put_MinHeight(value));
}

template <typename D> double impl_IFrameworkElement<D>::MaxHeight() const
{
    double value {};
    check_hresult(WINRT_SHIM(IFrameworkElement)->get_MaxHeight(&value));
    return value;
}

template <typename D> void impl_IFrameworkElement<D>::MaxHeight(double value) const
{
    check_hresult(WINRT_SHIM(IFrameworkElement)->put_MaxHeight(value));
}

template <typename D> Windows::UI::Xaml::HorizontalAlignment impl_IFrameworkElement<D>::HorizontalAlignment() const
{
    Windows::UI::Xaml::HorizontalAlignment value {};
    check_hresult(WINRT_SHIM(IFrameworkElement)->get_HorizontalAlignment(&value));
    return value;
}

template <typename D> void impl_IFrameworkElement<D>::HorizontalAlignment(Windows::UI::Xaml::HorizontalAlignment value) const
{
    check_hresult(WINRT_SHIM(IFrameworkElement)->put_HorizontalAlignment(value));
}

template <typename D> Windows::UI::Xaml::VerticalAlignment impl_IFrameworkElement<D>::VerticalAlignment() const
{
    Windows::UI::Xaml::VerticalAlignment value {};
    check_hresult(WINRT_SHIM(IFrameworkElement)->get_VerticalAlignment(&value));
    return value;
}

template <typename D> void impl_IFrameworkElement<D>::VerticalAlignment(Windows::UI::Xaml::VerticalAlignment value) const
{
    check_hresult(WINRT_SHIM(IFrameworkElement)->put_VerticalAlignment(value));
}

template <typename D> Windows::UI::Xaml::Thickness impl_IFrameworkElement<D>::Margin() const
{
    Windows::UI::Xaml::Thickness value {};
    check_hresult(WINRT_SHIM(IFrameworkElement)->get_Margin(put_abi(value)));
    return value;
}

template <typename D> void impl_IFrameworkElement<D>::Margin(const Windows::UI::Xaml::Thickness & value) const
{
    check_hresult(WINRT_SHIM(IFrameworkElement)->put_Margin(get_abi(value)));
}

template <typename D> hstring impl_IFrameworkElement<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IFrameworkElement)->get_Name(put_abi(value)));
    return value;
}

template <typename D> void impl_IFrameworkElement<D>::Name(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IFrameworkElement)->put_Name(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_IFrameworkElement<D>::BaseUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElement)->get_BaseUri(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IInspectable impl_IFrameworkElement<D>::DataContext() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IFrameworkElement)->get_DataContext(put_abi(value)));
    return value;
}

template <typename D> void impl_IFrameworkElement<D>::DataContext(const Windows::Foundation::IInspectable & value) const
{
    check_hresult(WINRT_SHIM(IFrameworkElement)->put_DataContext(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Style impl_IFrameworkElement<D>::Style() const
{
    Windows::UI::Xaml::Style value { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElement)->get_Style(put_abi(value)));
    return value;
}

template <typename D> void impl_IFrameworkElement<D>::Style(const Windows::UI::Xaml::Style & value) const
{
    check_hresult(WINRT_SHIM(IFrameworkElement)->put_Style(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DependencyObject impl_IFrameworkElement<D>::Parent() const
{
    Windows::UI::Xaml::DependencyObject value { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElement)->get_Parent(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::FlowDirection impl_IFrameworkElement<D>::FlowDirection() const
{
    Windows::UI::Xaml::FlowDirection value {};
    check_hresult(WINRT_SHIM(IFrameworkElement)->get_FlowDirection(&value));
    return value;
}

template <typename D> void impl_IFrameworkElement<D>::FlowDirection(Windows::UI::Xaml::FlowDirection value) const
{
    check_hresult(WINRT_SHIM(IFrameworkElement)->put_FlowDirection(value));
}

template <typename D> event_token impl_IFrameworkElement<D>::Loaded(const Windows::UI::Xaml::RoutedEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IFrameworkElement)->add_Loaded(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IFrameworkElement> impl_IFrameworkElement<D>::Loaded(auto_revoke_t, const Windows::UI::Xaml::RoutedEventHandler & value) const
{
    return impl::make_event_revoker<D, IFrameworkElement>(this, &ABI::Windows::UI::Xaml::IFrameworkElement::remove_Loaded, Loaded(value));
}

template <typename D> void impl_IFrameworkElement<D>::Loaded(event_token token) const
{
    check_hresult(WINRT_SHIM(IFrameworkElement)->remove_Loaded(token));
}

template <typename D> event_token impl_IFrameworkElement<D>::Unloaded(const Windows::UI::Xaml::RoutedEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IFrameworkElement)->add_Unloaded(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IFrameworkElement> impl_IFrameworkElement<D>::Unloaded(auto_revoke_t, const Windows::UI::Xaml::RoutedEventHandler & value) const
{
    return impl::make_event_revoker<D, IFrameworkElement>(this, &ABI::Windows::UI::Xaml::IFrameworkElement::remove_Unloaded, Unloaded(value));
}

template <typename D> void impl_IFrameworkElement<D>::Unloaded(event_token token) const
{
    check_hresult(WINRT_SHIM(IFrameworkElement)->remove_Unloaded(token));
}

template <typename D> event_token impl_IFrameworkElement<D>::SizeChanged(const Windows::UI::Xaml::SizeChangedEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IFrameworkElement)->add_SizeChanged(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IFrameworkElement> impl_IFrameworkElement<D>::SizeChanged(auto_revoke_t, const Windows::UI::Xaml::SizeChangedEventHandler & value) const
{
    return impl::make_event_revoker<D, IFrameworkElement>(this, &ABI::Windows::UI::Xaml::IFrameworkElement::remove_SizeChanged, SizeChanged(value));
}

template <typename D> void impl_IFrameworkElement<D>::SizeChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IFrameworkElement)->remove_SizeChanged(token));
}

template <typename D> event_token impl_IFrameworkElement<D>::LayoutUpdated(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IFrameworkElement)->add_LayoutUpdated(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IFrameworkElement> impl_IFrameworkElement<D>::LayoutUpdated(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const
{
    return impl::make_event_revoker<D, IFrameworkElement>(this, &ABI::Windows::UI::Xaml::IFrameworkElement::remove_LayoutUpdated, LayoutUpdated(value));
}

template <typename D> void impl_IFrameworkElement<D>::LayoutUpdated(event_token token) const
{
    check_hresult(WINRT_SHIM(IFrameworkElement)->remove_LayoutUpdated(token));
}

template <typename D> Windows::Foundation::IInspectable impl_IFrameworkElement<D>::FindName(hstring_view name) const
{
    Windows::Foundation::IInspectable returnValue;
    check_hresult(WINRT_SHIM(IFrameworkElement)->abi_FindName(get_abi(name), put_abi(returnValue)));
    return returnValue;
}

template <typename D> void impl_IFrameworkElement<D>::SetBinding(const Windows::UI::Xaml::DependencyProperty & dp, const Windows::UI::Xaml::Data::BindingBase & binding) const
{
    check_hresult(WINRT_SHIM(IFrameworkElement)->abi_SetBinding(get_abi(dp), get_abi(binding)));
}

template <typename D> Windows::Foundation::Size impl_IFrameworkElementOverrides<D>::MeasureOverride(const Windows::Foundation::Size & availableSize) const
{
    Windows::Foundation::Size returnValue {};
    check_hresult(WINRT_SHIM(IFrameworkElementOverrides)->abi_MeasureOverride(get_abi(availableSize), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::Size impl_IFrameworkElementOverrides<D>::ArrangeOverride(const Windows::Foundation::Size & finalSize) const
{
    Windows::Foundation::Size returnValue {};
    check_hresult(WINRT_SHIM(IFrameworkElementOverrides)->abi_ArrangeOverride(get_abi(finalSize), put_abi(returnValue)));
    return returnValue;
}

template <typename D> void impl_IFrameworkElementOverrides<D>::OnApplyTemplate() const
{
    check_hresult(WINRT_SHIM(IFrameworkElementOverrides)->abi_OnApplyTemplate());
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IFrameworkElementStatics<D>::TagProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElementStatics)->get_TagProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IFrameworkElementStatics<D>::LanguageProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElementStatics)->get_LanguageProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IFrameworkElementStatics<D>::ActualWidthProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElementStatics)->get_ActualWidthProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IFrameworkElementStatics<D>::ActualHeightProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElementStatics)->get_ActualHeightProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IFrameworkElementStatics<D>::WidthProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElementStatics)->get_WidthProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IFrameworkElementStatics<D>::HeightProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElementStatics)->get_HeightProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IFrameworkElementStatics<D>::MinWidthProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElementStatics)->get_MinWidthProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IFrameworkElementStatics<D>::MaxWidthProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElementStatics)->get_MaxWidthProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IFrameworkElementStatics<D>::MinHeightProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElementStatics)->get_MinHeightProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IFrameworkElementStatics<D>::MaxHeightProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElementStatics)->get_MaxHeightProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IFrameworkElementStatics<D>::HorizontalAlignmentProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElementStatics)->get_HorizontalAlignmentProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IFrameworkElementStatics<D>::VerticalAlignmentProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElementStatics)->get_VerticalAlignmentProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IFrameworkElementStatics<D>::MarginProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElementStatics)->get_MarginProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IFrameworkElementStatics<D>::NameProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElementStatics)->get_NameProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IFrameworkElementStatics<D>::DataContextProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElementStatics)->get_DataContextProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IFrameworkElementStatics<D>::StyleProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElementStatics)->get_StyleProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IFrameworkElementStatics<D>::FlowDirectionProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElementStatics)->get_FlowDirectionProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::FrameworkElement impl_IFrameworkElementFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::FrameworkElement instance { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElementFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::ElementTheme impl_IFrameworkElement2<D>::RequestedTheme() const
{
    Windows::UI::Xaml::ElementTheme value {};
    check_hresult(WINRT_SHIM(IFrameworkElement2)->get_RequestedTheme(&value));
    return value;
}

template <typename D> void impl_IFrameworkElement2<D>::RequestedTheme(Windows::UI::Xaml::ElementTheme value) const
{
    check_hresult(WINRT_SHIM(IFrameworkElement2)->put_RequestedTheme(value));
}

template <typename D> event_token impl_IFrameworkElement2<D>::DataContextChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::DataContextChangedEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IFrameworkElement2)->add_DataContextChanged(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IFrameworkElement2> impl_IFrameworkElement2<D>::DataContextChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::DataContextChangedEventArgs> & value) const
{
    return impl::make_event_revoker<D, IFrameworkElement2>(this, &ABI::Windows::UI::Xaml::IFrameworkElement2::remove_DataContextChanged, DataContextChanged(value));
}

template <typename D> void impl_IFrameworkElement2<D>::DataContextChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IFrameworkElement2)->remove_DataContextChanged(token));
}

template <typename D> Windows::UI::Xaml::Data::BindingExpression impl_IFrameworkElement2<D>::GetBindingExpression(const Windows::UI::Xaml::DependencyProperty & dp) const
{
    Windows::UI::Xaml::Data::BindingExpression returnValue { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElement2)->abi_GetBindingExpression(get_abi(dp), put_abi(returnValue)));
    return returnValue;
}

template <typename D> bool impl_IFrameworkElementOverrides2<D>::GoToElementStateCore(hstring_view stateName, bool useTransitions) const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IFrameworkElementOverrides2)->abi_GoToElementStateCore(get_abi(stateName), useTransitions, &returnValue));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IFrameworkElementStatics2<D>::RequestedThemeProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElementStatics2)->get_RequestedThemeProperty(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IFrameworkElement3<D>::Loading(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::FrameworkElement, Windows::Foundation::IInspectable> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IFrameworkElement3)->add_Loading(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IFrameworkElement3> impl_IFrameworkElement3<D>::Loading(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::FrameworkElement, Windows::Foundation::IInspectable> & value) const
{
    return impl::make_event_revoker<D, IFrameworkElement3>(this, &ABI::Windows::UI::Xaml::IFrameworkElement3::remove_Loading, Loading(value));
}

template <typename D> void impl_IFrameworkElement3<D>::Loading(event_token token) const
{
    check_hresult(WINRT_SHIM(IFrameworkElement3)->remove_Loading(token));
}

template <typename D> bool impl_IFrameworkElement4<D>::AllowFocusOnInteraction() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IFrameworkElement4)->get_AllowFocusOnInteraction(&value));
    return value;
}

template <typename D> void impl_IFrameworkElement4<D>::AllowFocusOnInteraction(bool value) const
{
    check_hresult(WINRT_SHIM(IFrameworkElement4)->put_AllowFocusOnInteraction(value));
}

template <typename D> Windows::UI::Xaml::Thickness impl_IFrameworkElement4<D>::FocusVisualMargin() const
{
    Windows::UI::Xaml::Thickness value {};
    check_hresult(WINRT_SHIM(IFrameworkElement4)->get_FocusVisualMargin(put_abi(value)));
    return value;
}

template <typename D> void impl_IFrameworkElement4<D>::FocusVisualMargin(const Windows::UI::Xaml::Thickness & value) const
{
    check_hresult(WINRT_SHIM(IFrameworkElement4)->put_FocusVisualMargin(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Thickness impl_IFrameworkElement4<D>::FocusVisualSecondaryThickness() const
{
    Windows::UI::Xaml::Thickness value {};
    check_hresult(WINRT_SHIM(IFrameworkElement4)->get_FocusVisualSecondaryThickness(put_abi(value)));
    return value;
}

template <typename D> void impl_IFrameworkElement4<D>::FocusVisualSecondaryThickness(const Windows::UI::Xaml::Thickness & value) const
{
    check_hresult(WINRT_SHIM(IFrameworkElement4)->put_FocusVisualSecondaryThickness(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Thickness impl_IFrameworkElement4<D>::FocusVisualPrimaryThickness() const
{
    Windows::UI::Xaml::Thickness value {};
    check_hresult(WINRT_SHIM(IFrameworkElement4)->get_FocusVisualPrimaryThickness(put_abi(value)));
    return value;
}

template <typename D> void impl_IFrameworkElement4<D>::FocusVisualPrimaryThickness(const Windows::UI::Xaml::Thickness & value) const
{
    check_hresult(WINRT_SHIM(IFrameworkElement4)->put_FocusVisualPrimaryThickness(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Media::Brush impl_IFrameworkElement4<D>::FocusVisualSecondaryBrush() const
{
    Windows::UI::Xaml::Media::Brush value { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElement4)->get_FocusVisualSecondaryBrush(put_abi(value)));
    return value;
}

template <typename D> void impl_IFrameworkElement4<D>::FocusVisualSecondaryBrush(const Windows::UI::Xaml::Media::Brush & value) const
{
    check_hresult(WINRT_SHIM(IFrameworkElement4)->put_FocusVisualSecondaryBrush(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Media::Brush impl_IFrameworkElement4<D>::FocusVisualPrimaryBrush() const
{
    Windows::UI::Xaml::Media::Brush value { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElement4)->get_FocusVisualPrimaryBrush(put_abi(value)));
    return value;
}

template <typename D> void impl_IFrameworkElement4<D>::FocusVisualPrimaryBrush(const Windows::UI::Xaml::Media::Brush & value) const
{
    check_hresult(WINRT_SHIM(IFrameworkElement4)->put_FocusVisualPrimaryBrush(get_abi(value)));
}

template <typename D> bool impl_IFrameworkElement4<D>::AllowFocusWhenDisabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IFrameworkElement4)->get_AllowFocusWhenDisabled(&value));
    return value;
}

template <typename D> void impl_IFrameworkElement4<D>::AllowFocusWhenDisabled(bool value) const
{
    check_hresult(WINRT_SHIM(IFrameworkElement4)->put_AllowFocusWhenDisabled(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IFrameworkElementStatics4<D>::AllowFocusOnInteractionProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElementStatics4)->get_AllowFocusOnInteractionProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IFrameworkElementStatics4<D>::FocusVisualMarginProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElementStatics4)->get_FocusVisualMarginProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IFrameworkElementStatics4<D>::FocusVisualSecondaryThicknessProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElementStatics4)->get_FocusVisualSecondaryThicknessProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IFrameworkElementStatics4<D>::FocusVisualPrimaryThicknessProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElementStatics4)->get_FocusVisualPrimaryThicknessProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IFrameworkElementStatics4<D>::FocusVisualSecondaryBrushProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElementStatics4)->get_FocusVisualSecondaryBrushProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IFrameworkElementStatics4<D>::FocusVisualPrimaryBrushProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElementStatics4)->get_FocusVisualPrimaryBrushProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IFrameworkElementStatics4<D>::AllowFocusWhenDisabledProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IFrameworkElementStatics4)->get_AllowFocusWhenDisabledProperty(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMediaFailedRoutedEventArgs<D>::ErrorTrace() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMediaFailedRoutedEventArgs)->get_ErrorTrace(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_ISetter<D>::Property() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(ISetter)->get_Property(put_abi(value)));
    return value;
}

template <typename D> void impl_ISetter<D>::Property(const Windows::UI::Xaml::DependencyProperty & value) const
{
    check_hresult(WINRT_SHIM(ISetter)->put_Property(get_abi(value)));
}

template <typename D> Windows::Foundation::IInspectable impl_ISetter<D>::Value() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(ISetter)->get_Value(put_abi(value)));
    return value;
}

template <typename D> void impl_ISetter<D>::Value(const Windows::Foundation::IInspectable & value) const
{
    check_hresult(WINRT_SHIM(ISetter)->put_Value(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Setter impl_ISetterFactory<D>::CreateInstance(const Windows::UI::Xaml::DependencyProperty & targetProperty, const Windows::Foundation::IInspectable & value) const
{
    Windows::UI::Xaml::Setter instance { nullptr };
    check_hresult(WINRT_SHIM(ISetterFactory)->abi_CreateInstance(get_abi(targetProperty), get_abi(value), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::TargetPropertyPath impl_ISetter2<D>::Target() const
{
    Windows::UI::Xaml::TargetPropertyPath value { nullptr };
    check_hresult(WINRT_SHIM(ISetter2)->get_Target(put_abi(value)));
    return value;
}

template <typename D> void impl_ISetter2<D>::Target(const Windows::UI::Xaml::TargetPropertyPath & value) const
{
    check_hresult(WINRT_SHIM(ISetter2)->put_Target(get_abi(value)));
}

template <typename D> bool impl_IStateTrigger<D>::IsActive() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IStateTrigger)->get_IsActive(&value));
    return value;
}

template <typename D> void impl_IStateTrigger<D>::IsActive(bool value) const
{
    check_hresult(WINRT_SHIM(IStateTrigger)->put_IsActive(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IStateTriggerStatics<D>::IsActiveProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IStateTriggerStatics)->get_IsActiveProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::GridLength impl_IGridLengthHelperStatics<D>::Auto() const
{
    Windows::UI::Xaml::GridLength value {};
    check_hresult(WINRT_SHIM(IGridLengthHelperStatics)->get_Auto(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::GridLength impl_IGridLengthHelperStatics<D>::FromPixels(double pixels) const
{
    Windows::UI::Xaml::GridLength returnValue {};
    check_hresult(WINRT_SHIM(IGridLengthHelperStatics)->abi_FromPixels(pixels, put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::GridLength impl_IGridLengthHelperStatics<D>::FromValueAndType(double value, Windows::UI::Xaml::GridUnitType type) const
{
    Windows::UI::Xaml::GridLength returnValue {};
    check_hresult(WINRT_SHIM(IGridLengthHelperStatics)->abi_FromValueAndType(value, type, put_abi(returnValue)));
    return returnValue;
}

template <typename D> bool impl_IGridLengthHelperStatics<D>::GetIsAbsolute(const Windows::UI::Xaml::GridLength & target) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IGridLengthHelperStatics)->abi_GetIsAbsolute(get_abi(target), &value));
    return value;
}

template <typename D> bool impl_IGridLengthHelperStatics<D>::GetIsAuto(const Windows::UI::Xaml::GridLength & target) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IGridLengthHelperStatics)->abi_GetIsAuto(get_abi(target), &value));
    return value;
}

template <typename D> bool impl_IGridLengthHelperStatics<D>::GetIsStar(const Windows::UI::Xaml::GridLength & target) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IGridLengthHelperStatics)->abi_GetIsStar(get_abi(target), &value));
    return value;
}

template <typename D> bool impl_IGridLengthHelperStatics<D>::Equals(const Windows::UI::Xaml::GridLength & target, const Windows::UI::Xaml::GridLength & value) const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IGridLengthHelperStatics)->abi_Equals(get_abi(target), get_abi(value), &returnValue));
    return returnValue;
}

template <typename D> hstring impl_IBindingFailedEventArgs<D>::Message() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IBindingFailedEventArgs)->get_Message(put_abi(value)));
    return value;
}

template <typename D> bool impl_IDebugSettings<D>::EnableFrameRateCounter() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDebugSettings)->get_EnableFrameRateCounter(&value));
    return value;
}

template <typename D> void impl_IDebugSettings<D>::EnableFrameRateCounter(bool value) const
{
    check_hresult(WINRT_SHIM(IDebugSettings)->put_EnableFrameRateCounter(value));
}

template <typename D> bool impl_IDebugSettings<D>::IsBindingTracingEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDebugSettings)->get_IsBindingTracingEnabled(&value));
    return value;
}

template <typename D> void impl_IDebugSettings<D>::IsBindingTracingEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IDebugSettings)->put_IsBindingTracingEnabled(value));
}

template <typename D> bool impl_IDebugSettings<D>::IsOverdrawHeatMapEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDebugSettings)->get_IsOverdrawHeatMapEnabled(&value));
    return value;
}

template <typename D> void impl_IDebugSettings<D>::IsOverdrawHeatMapEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IDebugSettings)->put_IsOverdrawHeatMapEnabled(value));
}

template <typename D> event_token impl_IDebugSettings<D>::BindingFailed(const Windows::UI::Xaml::BindingFailedEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IDebugSettings)->add_BindingFailed(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IDebugSettings> impl_IDebugSettings<D>::BindingFailed(auto_revoke_t, const Windows::UI::Xaml::BindingFailedEventHandler & value) const
{
    return impl::make_event_revoker<D, IDebugSettings>(this, &ABI::Windows::UI::Xaml::IDebugSettings::remove_BindingFailed, BindingFailed(value));
}

template <typename D> void impl_IDebugSettings<D>::BindingFailed(event_token token) const
{
    check_hresult(WINRT_SHIM(IDebugSettings)->remove_BindingFailed(token));
}

template <typename D> bool impl_IDebugSettings2<D>::EnableRedrawRegions() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDebugSettings2)->get_EnableRedrawRegions(&value));
    return value;
}

template <typename D> void impl_IDebugSettings2<D>::EnableRedrawRegions(bool value) const
{
    check_hresult(WINRT_SHIM(IDebugSettings2)->put_EnableRedrawRegions(value));
}

template <typename D> bool impl_IDebugSettings3<D>::IsTextPerformanceVisualizationEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDebugSettings3)->get_IsTextPerformanceVisualizationEnabled(&value));
    return value;
}

template <typename D> void impl_IDebugSettings3<D>::IsTextPerformanceVisualizationEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IDebugSettings3)->put_IsTextPerformanceVisualizationEnabled(value));
}

template <typename D> Windows::UI::Xaml::ResourceDictionary impl_IApplication<D>::Resources() const
{
    Windows::UI::Xaml::ResourceDictionary value { nullptr };
    check_hresult(WINRT_SHIM(IApplication)->get_Resources(put_abi(value)));
    return value;
}

template <typename D> void impl_IApplication<D>::Resources(const Windows::UI::Xaml::ResourceDictionary & value) const
{
    check_hresult(WINRT_SHIM(IApplication)->put_Resources(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::DebugSettings impl_IApplication<D>::DebugSettings() const
{
    Windows::UI::Xaml::DebugSettings value { nullptr };
    check_hresult(WINRT_SHIM(IApplication)->get_DebugSettings(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::ApplicationTheme impl_IApplication<D>::RequestedTheme() const
{
    Windows::UI::Xaml::ApplicationTheme value {};
    check_hresult(WINRT_SHIM(IApplication)->get_RequestedTheme(&value));
    return value;
}

template <typename D> void impl_IApplication<D>::RequestedTheme(Windows::UI::Xaml::ApplicationTheme value) const
{
    check_hresult(WINRT_SHIM(IApplication)->put_RequestedTheme(value));
}

template <typename D> event_token impl_IApplication<D>::UnhandledException(const Windows::UI::Xaml::UnhandledExceptionEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IApplication)->add_UnhandledException(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IApplication> impl_IApplication<D>::UnhandledException(auto_revoke_t, const Windows::UI::Xaml::UnhandledExceptionEventHandler & value) const
{
    return impl::make_event_revoker<D, IApplication>(this, &ABI::Windows::UI::Xaml::IApplication::remove_UnhandledException, UnhandledException(value));
}

template <typename D> void impl_IApplication<D>::UnhandledException(event_token token) const
{
    check_hresult(WINRT_SHIM(IApplication)->remove_UnhandledException(token));
}

template <typename D> event_token impl_IApplication<D>::Suspending(const Windows::UI::Xaml::SuspendingEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IApplication)->add_Suspending(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IApplication> impl_IApplication<D>::Suspending(auto_revoke_t, const Windows::UI::Xaml::SuspendingEventHandler & value) const
{
    return impl::make_event_revoker<D, IApplication>(this, &ABI::Windows::UI::Xaml::IApplication::remove_Suspending, Suspending(value));
}

template <typename D> void impl_IApplication<D>::Suspending(event_token token) const
{
    check_hresult(WINRT_SHIM(IApplication)->remove_Suspending(token));
}

template <typename D> event_token impl_IApplication<D>::Resuming(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IApplication)->add_Resuming(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IApplication> impl_IApplication<D>::Resuming(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const
{
    return impl::make_event_revoker<D, IApplication>(this, &ABI::Windows::UI::Xaml::IApplication::remove_Resuming, Resuming(value));
}

template <typename D> void impl_IApplication<D>::Resuming(event_token token) const
{
    check_hresult(WINRT_SHIM(IApplication)->remove_Resuming(token));
}

template <typename D> void impl_IApplication<D>::Exit() const
{
    check_hresult(WINRT_SHIM(IApplication)->abi_Exit());
}

template <typename D> void impl_IApplicationOverrides<D>::OnActivated(const Windows::ApplicationModel::Activation::IActivatedEventArgs & args) const
{
    check_hresult(WINRT_SHIM(IApplicationOverrides)->abi_OnActivated(get_abi(args)));
}

template <typename D> void impl_IApplicationOverrides<D>::OnLaunched(const Windows::ApplicationModel::Activation::LaunchActivatedEventArgs & args) const
{
    check_hresult(WINRT_SHIM(IApplicationOverrides)->abi_OnLaunched(get_abi(args)));
}

template <typename D> void impl_IApplicationOverrides<D>::OnFileActivated(const Windows::ApplicationModel::Activation::FileActivatedEventArgs & args) const
{
    check_hresult(WINRT_SHIM(IApplicationOverrides)->abi_OnFileActivated(get_abi(args)));
}

template <typename D> void impl_IApplicationOverrides<D>::OnSearchActivated(const Windows::ApplicationModel::Activation::SearchActivatedEventArgs & args) const
{
    check_hresult(WINRT_SHIM(IApplicationOverrides)->abi_OnSearchActivated(get_abi(args)));
}

template <typename D> void impl_IApplicationOverrides<D>::OnShareTargetActivated(const Windows::ApplicationModel::Activation::ShareTargetActivatedEventArgs & args) const
{
    check_hresult(WINRT_SHIM(IApplicationOverrides)->abi_OnShareTargetActivated(get_abi(args)));
}

template <typename D> void impl_IApplicationOverrides<D>::OnFileOpenPickerActivated(const Windows::ApplicationModel::Activation::FileOpenPickerActivatedEventArgs & args) const
{
    check_hresult(WINRT_SHIM(IApplicationOverrides)->abi_OnFileOpenPickerActivated(get_abi(args)));
}

template <typename D> void impl_IApplicationOverrides<D>::OnFileSavePickerActivated(const Windows::ApplicationModel::Activation::FileSavePickerActivatedEventArgs & args) const
{
    check_hresult(WINRT_SHIM(IApplicationOverrides)->abi_OnFileSavePickerActivated(get_abi(args)));
}

template <typename D> void impl_IApplicationOverrides<D>::OnCachedFileUpdaterActivated(const Windows::ApplicationModel::Activation::CachedFileUpdaterActivatedEventArgs & args) const
{
    check_hresult(WINRT_SHIM(IApplicationOverrides)->abi_OnCachedFileUpdaterActivated(get_abi(args)));
}

template <typename D> void impl_IApplicationOverrides<D>::OnWindowCreated(const Windows::UI::Xaml::WindowCreatedEventArgs & args) const
{
    check_hresult(WINRT_SHIM(IApplicationOverrides)->abi_OnWindowCreated(get_abi(args)));
}

template <typename D> Windows::UI::Xaml::Application impl_IApplicationStatics<D>::Current() const
{
    Windows::UI::Xaml::Application value { nullptr };
    check_hresult(WINRT_SHIM(IApplicationStatics)->get_Current(put_abi(value)));
    return value;
}

template <typename D> void impl_IApplicationStatics<D>::Start(const Windows::UI::Xaml::ApplicationInitializationCallback & callback) const
{
    check_hresult(WINRT_SHIM(IApplicationStatics)->abi_Start(get_abi(callback)));
}

template <typename D> void impl_IApplicationStatics<D>::LoadComponent(const Windows::Foundation::IInspectable & component, const Windows::Foundation::Uri & resourceLocator) const
{
    check_hresult(WINRT_SHIM(IApplicationStatics)->abi_LoadComponent(get_abi(component), get_abi(resourceLocator)));
}

template <typename D> void impl_IApplicationStatics<D>::LoadComponent(const Windows::Foundation::IInspectable & component, const Windows::Foundation::Uri & resourceLocator, Windows::UI::Xaml::Controls::Primitives::ComponentResourceLocation componentResourceLocation) const
{
    check_hresult(WINRT_SHIM(IApplicationStatics)->abi_LoadComponentWithResourceLocation(get_abi(component), get_abi(resourceLocator), componentResourceLocation));
}

template <typename D> Windows::UI::Xaml::Application impl_IApplicationFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Application instance { nullptr };
    check_hresult(WINRT_SHIM(IApplicationFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::FocusVisualKind impl_IApplication2<D>::FocusVisualKind() const
{
    Windows::UI::Xaml::FocusVisualKind value {};
    check_hresult(WINRT_SHIM(IApplication2)->get_FocusVisualKind(&value));
    return value;
}

template <typename D> void impl_IApplication2<D>::FocusVisualKind(Windows::UI::Xaml::FocusVisualKind value) const
{
    check_hresult(WINRT_SHIM(IApplication2)->put_FocusVisualKind(value));
}

template <typename D> Windows::UI::Xaml::ApplicationRequiresPointerMode impl_IApplication2<D>::RequiresPointerMode() const
{
    Windows::UI::Xaml::ApplicationRequiresPointerMode value {};
    check_hresult(WINRT_SHIM(IApplication2)->get_RequiresPointerMode(&value));
    return value;
}

template <typename D> void impl_IApplication2<D>::RequiresPointerMode(Windows::UI::Xaml::ApplicationRequiresPointerMode value) const
{
    check_hresult(WINRT_SHIM(IApplication2)->put_RequiresPointerMode(value));
}

template <typename D> event_token impl_IApplication2<D>::LeavingBackground(const Windows::UI::Xaml::LeavingBackgroundEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IApplication2)->add_LeavingBackground(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IApplication2> impl_IApplication2<D>::LeavingBackground(auto_revoke_t, const Windows::UI::Xaml::LeavingBackgroundEventHandler & value) const
{
    return impl::make_event_revoker<D, IApplication2>(this, &ABI::Windows::UI::Xaml::IApplication2::remove_LeavingBackground, LeavingBackground(value));
}

template <typename D> void impl_IApplication2<D>::LeavingBackground(event_token token) const
{
    check_hresult(WINRT_SHIM(IApplication2)->remove_LeavingBackground(token));
}

template <typename D> event_token impl_IApplication2<D>::EnteredBackground(const Windows::UI::Xaml::EnteredBackgroundEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IApplication2)->add_EnteredBackground(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IApplication2> impl_IApplication2<D>::EnteredBackground(auto_revoke_t, const Windows::UI::Xaml::EnteredBackgroundEventHandler & value) const
{
    return impl::make_event_revoker<D, IApplication2>(this, &ABI::Windows::UI::Xaml::IApplication2::remove_EnteredBackground, EnteredBackground(value));
}

template <typename D> void impl_IApplication2<D>::EnteredBackground(event_token token) const
{
    check_hresult(WINRT_SHIM(IApplication2)->remove_EnteredBackground(token));
}

template <typename D> void impl_IApplicationOverrides2<D>::OnBackgroundActivated(const Windows::ApplicationModel::Activation::BackgroundActivatedEventArgs & args) const
{
    check_hresult(WINRT_SHIM(IApplicationOverrides2)->abi_OnBackgroundActivated(get_abi(args)));
}

template <typename D> Windows::Foundation::Point impl_IPointHelperStatics<D>::FromCoordinates(float x, float y) const
{
    Windows::Foundation::Point returnValue {};
    check_hresult(WINRT_SHIM(IPointHelperStatics)->abi_FromCoordinates(x, y, put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::Rect impl_IRectHelperStatics<D>::Empty() const
{
    Windows::Foundation::Rect value {};
    check_hresult(WINRT_SHIM(IRectHelperStatics)->get_Empty(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Rect impl_IRectHelperStatics<D>::FromCoordinatesAndDimensions(float x, float y, float width, float height) const
{
    Windows::Foundation::Rect returnValue {};
    check_hresult(WINRT_SHIM(IRectHelperStatics)->abi_FromCoordinatesAndDimensions(x, y, width, height, put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::Rect impl_IRectHelperStatics<D>::FromPoints(const Windows::Foundation::Point & point1, const Windows::Foundation::Point & point2) const
{
    Windows::Foundation::Rect returnValue {};
    check_hresult(WINRT_SHIM(IRectHelperStatics)->abi_FromPoints(get_abi(point1), get_abi(point2), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::Rect impl_IRectHelperStatics<D>::FromLocationAndSize(const Windows::Foundation::Point & location, const Windows::Foundation::Size & size) const
{
    Windows::Foundation::Rect returnValue {};
    check_hresult(WINRT_SHIM(IRectHelperStatics)->abi_FromLocationAndSize(get_abi(location), get_abi(size), put_abi(returnValue)));
    return returnValue;
}

template <typename D> bool impl_IRectHelperStatics<D>::GetIsEmpty(const Windows::Foundation::Rect & target) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IRectHelperStatics)->abi_GetIsEmpty(get_abi(target), &value));
    return value;
}

template <typename D> float impl_IRectHelperStatics<D>::GetBottom(const Windows::Foundation::Rect & target) const
{
    float value {};
    check_hresult(WINRT_SHIM(IRectHelperStatics)->abi_GetBottom(get_abi(target), &value));
    return value;
}

template <typename D> float impl_IRectHelperStatics<D>::GetLeft(const Windows::Foundation::Rect & target) const
{
    float value {};
    check_hresult(WINRT_SHIM(IRectHelperStatics)->abi_GetLeft(get_abi(target), &value));
    return value;
}

template <typename D> float impl_IRectHelperStatics<D>::GetRight(const Windows::Foundation::Rect & target) const
{
    float value {};
    check_hresult(WINRT_SHIM(IRectHelperStatics)->abi_GetRight(get_abi(target), &value));
    return value;
}

template <typename D> float impl_IRectHelperStatics<D>::GetTop(const Windows::Foundation::Rect & target) const
{
    float value {};
    check_hresult(WINRT_SHIM(IRectHelperStatics)->abi_GetTop(get_abi(target), &value));
    return value;
}

template <typename D> bool impl_IRectHelperStatics<D>::Contains(const Windows::Foundation::Rect & target, const Windows::Foundation::Point & point) const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IRectHelperStatics)->abi_Contains(get_abi(target), get_abi(point), &returnValue));
    return returnValue;
}

template <typename D> bool impl_IRectHelperStatics<D>::Equals(const Windows::Foundation::Rect & target, const Windows::Foundation::Rect & value) const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(IRectHelperStatics)->abi_Equals(get_abi(target), get_abi(value), &returnValue));
    return returnValue;
}

template <typename D> Windows::Foundation::Rect impl_IRectHelperStatics<D>::Intersect(const Windows::Foundation::Rect & target, const Windows::Foundation::Rect & rect) const
{
    Windows::Foundation::Rect returnValue {};
    check_hresult(WINRT_SHIM(IRectHelperStatics)->abi_Intersect(get_abi(target), get_abi(rect), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::Rect impl_IRectHelperStatics<D>::Union(const Windows::Foundation::Rect & target, const Windows::Foundation::Point & point) const
{
    Windows::Foundation::Rect returnValue {};
    check_hresult(WINRT_SHIM(IRectHelperStatics)->abi_UnionWithPoint(get_abi(target), get_abi(point), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::Rect impl_IRectHelperStatics<D>::Union(const Windows::Foundation::Rect & target, const Windows::Foundation::Rect & rect) const
{
    Windows::Foundation::Rect returnValue {};
    check_hresult(WINRT_SHIM(IRectHelperStatics)->abi_UnionWithRect(get_abi(target), get_abi(rect), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::Size impl_ISizeHelperStatics<D>::Empty() const
{
    Windows::Foundation::Size value {};
    check_hresult(WINRT_SHIM(ISizeHelperStatics)->get_Empty(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Size impl_ISizeHelperStatics<D>::FromDimensions(float width, float height) const
{
    Windows::Foundation::Size returnValue {};
    check_hresult(WINRT_SHIM(ISizeHelperStatics)->abi_FromDimensions(width, height, put_abi(returnValue)));
    return returnValue;
}

template <typename D> bool impl_ISizeHelperStatics<D>::GetIsEmpty(const Windows::Foundation::Size & target) const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISizeHelperStatics)->abi_GetIsEmpty(get_abi(target), &value));
    return value;
}

template <typename D> bool impl_ISizeHelperStatics<D>::Equals(const Windows::Foundation::Size & target, const Windows::Foundation::Size & value) const
{
    bool returnValue {};
    check_hresult(WINRT_SHIM(ISizeHelperStatics)->abi_Equals(get_abi(target), get_abi(value), &returnValue));
    return returnValue;
}

inline AdaptiveTrigger::AdaptiveTrigger()
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<AdaptiveTrigger, IAdaptiveTriggerFactory>().CreateInstance(outer, inner));
}

inline Windows::UI::Xaml::DependencyProperty AdaptiveTrigger::MinWindowWidthProperty()
{
    return get_activation_factory<AdaptiveTrigger, IAdaptiveTriggerStatics>().MinWindowWidthProperty();
}

inline Windows::UI::Xaml::DependencyProperty AdaptiveTrigger::MinWindowHeightProperty()
{
    return get_activation_factory<AdaptiveTrigger, IAdaptiveTriggerStatics>().MinWindowHeightProperty();
}

inline Application::Application()
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<Application, IApplicationFactory>().CreateInstance(outer, inner));
}

inline Windows::UI::Xaml::Application Application::Current()
{
    return get_activation_factory<Application, IApplicationStatics>().Current();
}

inline void Application::Start(const Windows::UI::Xaml::ApplicationInitializationCallback & callback)
{
    get_activation_factory<Application, IApplicationStatics>().Start(callback);
}

inline void Application::LoadComponent(const Windows::Foundation::IInspectable & component, const Windows::Foundation::Uri & resourceLocator)
{
    get_activation_factory<Application, IApplicationStatics>().LoadComponent(component, resourceLocator);
}

inline void Application::LoadComponent(const Windows::Foundation::IInspectable & component, const Windows::Foundation::Uri & resourceLocator, Windows::UI::Xaml::Controls::Primitives::ComponentResourceLocation componentResourceLocation)
{
    get_activation_factory<Application, IApplicationStatics>().LoadComponent(component, resourceLocator, componentResourceLocation);
}

inline Windows::UI::Xaml::CornerRadius CornerRadiusHelper::FromRadii(double topLeft, double topRight, double bottomRight, double bottomLeft)
{
    return get_activation_factory<CornerRadiusHelper, ICornerRadiusHelperStatics>().FromRadii(topLeft, topRight, bottomRight, bottomLeft);
}

inline Windows::UI::Xaml::CornerRadius CornerRadiusHelper::FromUniformRadius(double uniformRadius)
{
    return get_activation_factory<CornerRadiusHelper, ICornerRadiusHelperStatics>().FromUniformRadius(uniformRadius);
}

inline DataTemplate::DataTemplate()
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<DataTemplate, IDataTemplateFactory>().CreateInstance(outer, inner));
}

inline Windows::UI::Xaml::DependencyProperty DataTemplate::ExtensionInstanceProperty()
{
    return get_activation_factory<DataTemplate, IDataTemplateStatics2>().ExtensionInstanceProperty();
}

inline Windows::UI::Xaml::IDataTemplateExtension DataTemplate::GetExtensionInstance(const Windows::UI::Xaml::FrameworkElement & element)
{
    return get_activation_factory<DataTemplate, IDataTemplateStatics2>().GetExtensionInstance(element);
}

inline void DataTemplate::SetExtensionInstance(const Windows::UI::Xaml::FrameworkElement & element, const Windows::UI::Xaml::IDataTemplateExtension & value)
{
    get_activation_factory<DataTemplate, IDataTemplateStatics2>().SetExtensionInstance(element, value);
}

inline DataTemplateKey::DataTemplateKey()
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<DataTemplateKey, IDataTemplateKeyFactory>().CreateInstance(outer, inner));
}

inline DataTemplateKey::DataTemplateKey(const Windows::Foundation::IInspectable & dataType)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<DataTemplateKey, IDataTemplateKeyFactory>().CreateInstanceWithType(dataType, outer, inner));
}

inline DependencyObjectCollection::DependencyObjectCollection()
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<DependencyObjectCollection, IDependencyObjectCollectionFactory>().CreateInstance(outer, inner));
}

inline Windows::Foundation::IInspectable DependencyProperty::UnsetValue()
{
    return get_activation_factory<DependencyProperty, IDependencyPropertyStatics>().UnsetValue();
}

inline Windows::UI::Xaml::DependencyProperty DependencyProperty::Register(hstring_view name, const Windows::UI::Xaml::Interop::TypeName & propertyType, const Windows::UI::Xaml::Interop::TypeName & ownerType, const Windows::UI::Xaml::PropertyMetadata & typeMetadata)
{
    return get_activation_factory<DependencyProperty, IDependencyPropertyStatics>().Register(name, propertyType, ownerType, typeMetadata);
}

inline Windows::UI::Xaml::DependencyProperty DependencyProperty::RegisterAttached(hstring_view name, const Windows::UI::Xaml::Interop::TypeName & propertyType, const Windows::UI::Xaml::Interop::TypeName & ownerType, const Windows::UI::Xaml::PropertyMetadata & defaultMetadata)
{
    return get_activation_factory<DependencyProperty, IDependencyPropertyStatics>().RegisterAttached(name, propertyType, ownerType, defaultMetadata);
}

inline DispatcherTimer::DispatcherTimer()
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<DispatcherTimer, IDispatcherTimerFactory>().CreateInstance(outer, inner));
}

inline Windows::UI::Xaml::Duration DurationHelper::Automatic()
{
    return get_activation_factory<DurationHelper, IDurationHelperStatics>().Automatic();
}

inline Windows::UI::Xaml::Duration DurationHelper::Forever()
{
    return get_activation_factory<DurationHelper, IDurationHelperStatics>().Forever();
}

inline int32_t DurationHelper::Compare(const Windows::UI::Xaml::Duration & duration1, const Windows::UI::Xaml::Duration & duration2)
{
    return get_activation_factory<DurationHelper, IDurationHelperStatics>().Compare(duration1, duration2);
}

inline Windows::UI::Xaml::Duration DurationHelper::FromTimeSpan(const Windows::Foundation::TimeSpan & timeSpan)
{
    return get_activation_factory<DurationHelper, IDurationHelperStatics>().FromTimeSpan(timeSpan);
}

inline bool DurationHelper::GetHasTimeSpan(const Windows::UI::Xaml::Duration & target)
{
    return get_activation_factory<DurationHelper, IDurationHelperStatics>().GetHasTimeSpan(target);
}

inline Windows::UI::Xaml::Duration DurationHelper::Add(const Windows::UI::Xaml::Duration & target, const Windows::UI::Xaml::Duration & duration)
{
    return get_activation_factory<DurationHelper, IDurationHelperStatics>().Add(target, duration);
}

inline bool DurationHelper::Equals(const Windows::UI::Xaml::Duration & target, const Windows::UI::Xaml::Duration & value)
{
    return get_activation_factory<DurationHelper, IDurationHelperStatics>().Equals(target, value);
}

inline Windows::UI::Xaml::Duration DurationHelper::Subtract(const Windows::UI::Xaml::Duration & target, const Windows::UI::Xaml::Duration & duration)
{
    return get_activation_factory<DurationHelper, IDurationHelperStatics>().Subtract(target, duration);
}

inline double ElementSoundPlayer::Volume()
{
    return get_activation_factory<ElementSoundPlayer, IElementSoundPlayerStatics>().Volume();
}

inline void ElementSoundPlayer::Volume(double value)
{
    get_activation_factory<ElementSoundPlayer, IElementSoundPlayerStatics>().Volume(value);
}

inline Windows::UI::Xaml::ElementSoundPlayerState ElementSoundPlayer::State()
{
    return get_activation_factory<ElementSoundPlayer, IElementSoundPlayerStatics>().State();
}

inline void ElementSoundPlayer::State(Windows::UI::Xaml::ElementSoundPlayerState value)
{
    get_activation_factory<ElementSoundPlayer, IElementSoundPlayerStatics>().State(value);
}

inline void ElementSoundPlayer::Play(Windows::UI::Xaml::ElementSoundKind sound)
{
    get_activation_factory<ElementSoundPlayer, IElementSoundPlayerStatics>().Play(sound);
}

inline EventTrigger::EventTrigger() :
    EventTrigger(activate_instance<EventTrigger>())
{}

inline Windows::UI::Xaml::DependencyProperty FrameworkElement::TagProperty()
{
    return get_activation_factory<FrameworkElement, IFrameworkElementStatics>().TagProperty();
}

inline Windows::UI::Xaml::DependencyProperty FrameworkElement::LanguageProperty()
{
    return get_activation_factory<FrameworkElement, IFrameworkElementStatics>().LanguageProperty();
}

inline Windows::UI::Xaml::DependencyProperty FrameworkElement::ActualWidthProperty()
{
    return get_activation_factory<FrameworkElement, IFrameworkElementStatics>().ActualWidthProperty();
}

inline Windows::UI::Xaml::DependencyProperty FrameworkElement::ActualHeightProperty()
{
    return get_activation_factory<FrameworkElement, IFrameworkElementStatics>().ActualHeightProperty();
}

inline Windows::UI::Xaml::DependencyProperty FrameworkElement::WidthProperty()
{
    return get_activation_factory<FrameworkElement, IFrameworkElementStatics>().WidthProperty();
}

inline Windows::UI::Xaml::DependencyProperty FrameworkElement::HeightProperty()
{
    return get_activation_factory<FrameworkElement, IFrameworkElementStatics>().HeightProperty();
}

inline Windows::UI::Xaml::DependencyProperty FrameworkElement::MinWidthProperty()
{
    return get_activation_factory<FrameworkElement, IFrameworkElementStatics>().MinWidthProperty();
}

inline Windows::UI::Xaml::DependencyProperty FrameworkElement::MaxWidthProperty()
{
    return get_activation_factory<FrameworkElement, IFrameworkElementStatics>().MaxWidthProperty();
}

inline Windows::UI::Xaml::DependencyProperty FrameworkElement::MinHeightProperty()
{
    return get_activation_factory<FrameworkElement, IFrameworkElementStatics>().MinHeightProperty();
}

inline Windows::UI::Xaml::DependencyProperty FrameworkElement::MaxHeightProperty()
{
    return get_activation_factory<FrameworkElement, IFrameworkElementStatics>().MaxHeightProperty();
}

inline Windows::UI::Xaml::DependencyProperty FrameworkElement::HorizontalAlignmentProperty()
{
    return get_activation_factory<FrameworkElement, IFrameworkElementStatics>().HorizontalAlignmentProperty();
}

inline Windows::UI::Xaml::DependencyProperty FrameworkElement::VerticalAlignmentProperty()
{
    return get_activation_factory<FrameworkElement, IFrameworkElementStatics>().VerticalAlignmentProperty();
}

inline Windows::UI::Xaml::DependencyProperty FrameworkElement::MarginProperty()
{
    return get_activation_factory<FrameworkElement, IFrameworkElementStatics>().MarginProperty();
}

inline Windows::UI::Xaml::DependencyProperty FrameworkElement::NameProperty()
{
    return get_activation_factory<FrameworkElement, IFrameworkElementStatics>().NameProperty();
}

inline Windows::UI::Xaml::DependencyProperty FrameworkElement::DataContextProperty()
{
    return get_activation_factory<FrameworkElement, IFrameworkElementStatics>().DataContextProperty();
}

inline Windows::UI::Xaml::DependencyProperty FrameworkElement::StyleProperty()
{
    return get_activation_factory<FrameworkElement, IFrameworkElementStatics>().StyleProperty();
}

inline Windows::UI::Xaml::DependencyProperty FrameworkElement::FlowDirectionProperty()
{
    return get_activation_factory<FrameworkElement, IFrameworkElementStatics>().FlowDirectionProperty();
}

inline Windows::UI::Xaml::DependencyProperty FrameworkElement::RequestedThemeProperty()
{
    return get_activation_factory<FrameworkElement, IFrameworkElementStatics2>().RequestedThemeProperty();
}

inline Windows::UI::Xaml::DependencyProperty FrameworkElement::AllowFocusOnInteractionProperty()
{
    return get_activation_factory<FrameworkElement, IFrameworkElementStatics4>().AllowFocusOnInteractionProperty();
}

inline Windows::UI::Xaml::DependencyProperty FrameworkElement::FocusVisualMarginProperty()
{
    return get_activation_factory<FrameworkElement, IFrameworkElementStatics4>().FocusVisualMarginProperty();
}

inline Windows::UI::Xaml::DependencyProperty FrameworkElement::FocusVisualSecondaryThicknessProperty()
{
    return get_activation_factory<FrameworkElement, IFrameworkElementStatics4>().FocusVisualSecondaryThicknessProperty();
}

inline Windows::UI::Xaml::DependencyProperty FrameworkElement::FocusVisualPrimaryThicknessProperty()
{
    return get_activation_factory<FrameworkElement, IFrameworkElementStatics4>().FocusVisualPrimaryThicknessProperty();
}

inline Windows::UI::Xaml::DependencyProperty FrameworkElement::FocusVisualSecondaryBrushProperty()
{
    return get_activation_factory<FrameworkElement, IFrameworkElementStatics4>().FocusVisualSecondaryBrushProperty();
}

inline Windows::UI::Xaml::DependencyProperty FrameworkElement::FocusVisualPrimaryBrushProperty()
{
    return get_activation_factory<FrameworkElement, IFrameworkElementStatics4>().FocusVisualPrimaryBrushProperty();
}

inline Windows::UI::Xaml::DependencyProperty FrameworkElement::AllowFocusWhenDisabledProperty()
{
    return get_activation_factory<FrameworkElement, IFrameworkElementStatics4>().AllowFocusWhenDisabledProperty();
}

inline FrameworkView::FrameworkView() :
    FrameworkView(activate_instance<FrameworkView>())
{}

inline FrameworkViewSource::FrameworkViewSource() :
    FrameworkViewSource(activate_instance<FrameworkViewSource>())
{}

inline Windows::UI::Xaml::GridLength GridLengthHelper::Auto()
{
    return get_activation_factory<GridLengthHelper, IGridLengthHelperStatics>().Auto();
}

inline Windows::UI::Xaml::GridLength GridLengthHelper::FromPixels(double pixels)
{
    return get_activation_factory<GridLengthHelper, IGridLengthHelperStatics>().FromPixels(pixels);
}

inline Windows::UI::Xaml::GridLength GridLengthHelper::FromValueAndType(double value, Windows::UI::Xaml::GridUnitType type)
{
    return get_activation_factory<GridLengthHelper, IGridLengthHelperStatics>().FromValueAndType(value, type);
}

inline bool GridLengthHelper::GetIsAbsolute(const Windows::UI::Xaml::GridLength & target)
{
    return get_activation_factory<GridLengthHelper, IGridLengthHelperStatics>().GetIsAbsolute(target);
}

inline bool GridLengthHelper::GetIsAuto(const Windows::UI::Xaml::GridLength & target)
{
    return get_activation_factory<GridLengthHelper, IGridLengthHelperStatics>().GetIsAuto(target);
}

inline bool GridLengthHelper::GetIsStar(const Windows::UI::Xaml::GridLength & target)
{
    return get_activation_factory<GridLengthHelper, IGridLengthHelperStatics>().GetIsStar(target);
}

inline bool GridLengthHelper::Equals(const Windows::UI::Xaml::GridLength & target, const Windows::UI::Xaml::GridLength & value)
{
    return get_activation_factory<GridLengthHelper, IGridLengthHelperStatics>().Equals(target, value);
}

inline Windows::Foundation::Point PointHelper::FromCoordinates(float x, float y)
{
    return get_activation_factory<PointHelper, IPointHelperStatics>().FromCoordinates(x, y);
}

inline PropertyMetadata::PropertyMetadata(const Windows::Foundation::IInspectable & defaultValue)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<PropertyMetadata, IPropertyMetadataFactory>().CreateInstanceWithDefaultValue(defaultValue, outer, inner));
}

inline PropertyMetadata::PropertyMetadata(const Windows::Foundation::IInspectable & defaultValue, const Windows::UI::Xaml::PropertyChangedCallback & propertyChangedCallback)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<PropertyMetadata, IPropertyMetadataFactory>().CreateInstanceWithDefaultValueAndCallback(defaultValue, propertyChangedCallback, outer, inner));
}

inline Windows::UI::Xaml::PropertyMetadata PropertyMetadata::Create(const Windows::Foundation::IInspectable & defaultValue)
{
    return get_activation_factory<PropertyMetadata, IPropertyMetadataStatics>().Create(defaultValue);
}

inline Windows::UI::Xaml::PropertyMetadata PropertyMetadata::Create(const Windows::Foundation::IInspectable & defaultValue, const Windows::UI::Xaml::PropertyChangedCallback & propertyChangedCallback)
{
    return get_activation_factory<PropertyMetadata, IPropertyMetadataStatics>().Create(defaultValue, propertyChangedCallback);
}

inline Windows::UI::Xaml::PropertyMetadata PropertyMetadata::Create(const Windows::UI::Xaml::CreateDefaultValueCallback & createDefaultValueCallback)
{
    return get_activation_factory<PropertyMetadata, IPropertyMetadataStatics>().Create(createDefaultValueCallback);
}

inline Windows::UI::Xaml::PropertyMetadata PropertyMetadata::Create(const Windows::UI::Xaml::CreateDefaultValueCallback & createDefaultValueCallback, const Windows::UI::Xaml::PropertyChangedCallback & propertyChangedCallback)
{
    return get_activation_factory<PropertyMetadata, IPropertyMetadataStatics>().Create(createDefaultValueCallback, propertyChangedCallback);
}

inline PropertyPath::PropertyPath(hstring_view path) :
    PropertyPath(get_activation_factory<PropertyPath, IPropertyPathFactory>().CreateInstance(path))
{}

inline Windows::Foundation::Rect RectHelper::Empty()
{
    return get_activation_factory<RectHelper, IRectHelperStatics>().Empty();
}

inline Windows::Foundation::Rect RectHelper::FromCoordinatesAndDimensions(float x, float y, float width, float height)
{
    return get_activation_factory<RectHelper, IRectHelperStatics>().FromCoordinatesAndDimensions(x, y, width, height);
}

inline Windows::Foundation::Rect RectHelper::FromPoints(const Windows::Foundation::Point & point1, const Windows::Foundation::Point & point2)
{
    return get_activation_factory<RectHelper, IRectHelperStatics>().FromPoints(point1, point2);
}

inline Windows::Foundation::Rect RectHelper::FromLocationAndSize(const Windows::Foundation::Point & location, const Windows::Foundation::Size & size)
{
    return get_activation_factory<RectHelper, IRectHelperStatics>().FromLocationAndSize(location, size);
}

inline bool RectHelper::GetIsEmpty(const Windows::Foundation::Rect & target)
{
    return get_activation_factory<RectHelper, IRectHelperStatics>().GetIsEmpty(target);
}

inline float RectHelper::GetBottom(const Windows::Foundation::Rect & target)
{
    return get_activation_factory<RectHelper, IRectHelperStatics>().GetBottom(target);
}

inline float RectHelper::GetLeft(const Windows::Foundation::Rect & target)
{
    return get_activation_factory<RectHelper, IRectHelperStatics>().GetLeft(target);
}

inline float RectHelper::GetRight(const Windows::Foundation::Rect & target)
{
    return get_activation_factory<RectHelper, IRectHelperStatics>().GetRight(target);
}

inline float RectHelper::GetTop(const Windows::Foundation::Rect & target)
{
    return get_activation_factory<RectHelper, IRectHelperStatics>().GetTop(target);
}

inline bool RectHelper::Contains(const Windows::Foundation::Rect & target, const Windows::Foundation::Point & point)
{
    return get_activation_factory<RectHelper, IRectHelperStatics>().Contains(target, point);
}

inline bool RectHelper::Equals(const Windows::Foundation::Rect & target, const Windows::Foundation::Rect & value)
{
    return get_activation_factory<RectHelper, IRectHelperStatics>().Equals(target, value);
}

inline Windows::Foundation::Rect RectHelper::Intersect(const Windows::Foundation::Rect & target, const Windows::Foundation::Rect & rect)
{
    return get_activation_factory<RectHelper, IRectHelperStatics>().Intersect(target, rect);
}

inline Windows::Foundation::Rect RectHelper::Union(const Windows::Foundation::Rect & target, const Windows::Foundation::Point & point)
{
    return get_activation_factory<RectHelper, IRectHelperStatics>().Union(target, point);
}

inline Windows::Foundation::Rect RectHelper::Union(const Windows::Foundation::Rect & target, const Windows::Foundation::Rect & rect)
{
    return get_activation_factory<RectHelper, IRectHelperStatics>().Union(target, rect);
}

inline ResourceDictionary::ResourceDictionary()
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<ResourceDictionary, IResourceDictionaryFactory>().CreateInstance(outer, inner));
}

inline RoutedEventArgs::RoutedEventArgs()
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<RoutedEventArgs, IRoutedEventArgsFactory>().CreateInstance(outer, inner));
}

inline Setter::Setter() :
    Setter(activate_instance<Setter>())
{}

inline Setter::Setter(const Windows::UI::Xaml::DependencyProperty & targetProperty, const Windows::Foundation::IInspectable & value) :
    Setter(get_activation_factory<Setter, ISetterFactory>().CreateInstance(targetProperty, value))
{}

inline SetterBaseCollection::SetterBaseCollection() :
    SetterBaseCollection(activate_instance<SetterBaseCollection>())
{}

inline Windows::Foundation::Size SizeHelper::Empty()
{
    return get_activation_factory<SizeHelper, ISizeHelperStatics>().Empty();
}

inline Windows::Foundation::Size SizeHelper::FromDimensions(float width, float height)
{
    return get_activation_factory<SizeHelper, ISizeHelperStatics>().FromDimensions(width, height);
}

inline bool SizeHelper::GetIsEmpty(const Windows::Foundation::Size & target)
{
    return get_activation_factory<SizeHelper, ISizeHelperStatics>().GetIsEmpty(target);
}

inline bool SizeHelper::Equals(const Windows::Foundation::Size & target, const Windows::Foundation::Size & value)
{
    return get_activation_factory<SizeHelper, ISizeHelperStatics>().Equals(target, value);
}

inline StateTrigger::StateTrigger() :
    StateTrigger(activate_instance<StateTrigger>())
{}

inline Windows::UI::Xaml::DependencyProperty StateTrigger::IsActiveProperty()
{
    return get_activation_factory<StateTrigger, IStateTriggerStatics>().IsActiveProperty();
}

inline Style::Style() :
    Style(activate_instance<Style>())
{}

inline Style::Style(const Windows::UI::Xaml::Interop::TypeName & targetType) :
    Style(get_activation_factory<Style, IStyleFactory>().CreateInstance(targetType))
{}

inline TargetPropertyPath::TargetPropertyPath() :
    TargetPropertyPath(activate_instance<TargetPropertyPath>())
{}

inline TargetPropertyPath::TargetPropertyPath(const Windows::UI::Xaml::DependencyProperty & targetProperty) :
    TargetPropertyPath(get_activation_factory<TargetPropertyPath, ITargetPropertyPathFactory>().CreateInstance(targetProperty))
{}

inline Windows::UI::Xaml::Thickness ThicknessHelper::FromLengths(double left, double top, double right, double bottom)
{
    return get_activation_factory<ThicknessHelper, IThicknessHelperStatics>().FromLengths(left, top, right, bottom);
}

inline Windows::UI::Xaml::Thickness ThicknessHelper::FromUniformLength(double uniformLength)
{
    return get_activation_factory<ThicknessHelper, IThicknessHelperStatics>().FromUniformLength(uniformLength);
}

inline TriggerActionCollection::TriggerActionCollection() :
    TriggerActionCollection(activate_instance<TriggerActionCollection>())
{}

inline Windows::UI::Xaml::RoutedEvent UIElement::KeyDownEvent()
{
    return get_activation_factory<UIElement, IUIElementStatics>().KeyDownEvent();
}

inline Windows::UI::Xaml::RoutedEvent UIElement::KeyUpEvent()
{
    return get_activation_factory<UIElement, IUIElementStatics>().KeyUpEvent();
}

inline Windows::UI::Xaml::RoutedEvent UIElement::PointerEnteredEvent()
{
    return get_activation_factory<UIElement, IUIElementStatics>().PointerEnteredEvent();
}

inline Windows::UI::Xaml::RoutedEvent UIElement::PointerPressedEvent()
{
    return get_activation_factory<UIElement, IUIElementStatics>().PointerPressedEvent();
}

inline Windows::UI::Xaml::RoutedEvent UIElement::PointerMovedEvent()
{
    return get_activation_factory<UIElement, IUIElementStatics>().PointerMovedEvent();
}

inline Windows::UI::Xaml::RoutedEvent UIElement::PointerReleasedEvent()
{
    return get_activation_factory<UIElement, IUIElementStatics>().PointerReleasedEvent();
}

inline Windows::UI::Xaml::RoutedEvent UIElement::PointerExitedEvent()
{
    return get_activation_factory<UIElement, IUIElementStatics>().PointerExitedEvent();
}

inline Windows::UI::Xaml::RoutedEvent UIElement::PointerCaptureLostEvent()
{
    return get_activation_factory<UIElement, IUIElementStatics>().PointerCaptureLostEvent();
}

inline Windows::UI::Xaml::RoutedEvent UIElement::PointerCanceledEvent()
{
    return get_activation_factory<UIElement, IUIElementStatics>().PointerCanceledEvent();
}

inline Windows::UI::Xaml::RoutedEvent UIElement::PointerWheelChangedEvent()
{
    return get_activation_factory<UIElement, IUIElementStatics>().PointerWheelChangedEvent();
}

inline Windows::UI::Xaml::RoutedEvent UIElement::TappedEvent()
{
    return get_activation_factory<UIElement, IUIElementStatics>().TappedEvent();
}

inline Windows::UI::Xaml::RoutedEvent UIElement::DoubleTappedEvent()
{
    return get_activation_factory<UIElement, IUIElementStatics>().DoubleTappedEvent();
}

inline Windows::UI::Xaml::RoutedEvent UIElement::HoldingEvent()
{
    return get_activation_factory<UIElement, IUIElementStatics>().HoldingEvent();
}

inline Windows::UI::Xaml::RoutedEvent UIElement::RightTappedEvent()
{
    return get_activation_factory<UIElement, IUIElementStatics>().RightTappedEvent();
}

inline Windows::UI::Xaml::RoutedEvent UIElement::ManipulationStartingEvent()
{
    return get_activation_factory<UIElement, IUIElementStatics>().ManipulationStartingEvent();
}

inline Windows::UI::Xaml::RoutedEvent UIElement::ManipulationInertiaStartingEvent()
{
    return get_activation_factory<UIElement, IUIElementStatics>().ManipulationInertiaStartingEvent();
}

inline Windows::UI::Xaml::RoutedEvent UIElement::ManipulationStartedEvent()
{
    return get_activation_factory<UIElement, IUIElementStatics>().ManipulationStartedEvent();
}

inline Windows::UI::Xaml::RoutedEvent UIElement::ManipulationDeltaEvent()
{
    return get_activation_factory<UIElement, IUIElementStatics>().ManipulationDeltaEvent();
}

inline Windows::UI::Xaml::RoutedEvent UIElement::ManipulationCompletedEvent()
{
    return get_activation_factory<UIElement, IUIElementStatics>().ManipulationCompletedEvent();
}

inline Windows::UI::Xaml::RoutedEvent UIElement::DragEnterEvent()
{
    return get_activation_factory<UIElement, IUIElementStatics>().DragEnterEvent();
}

inline Windows::UI::Xaml::RoutedEvent UIElement::DragLeaveEvent()
{
    return get_activation_factory<UIElement, IUIElementStatics>().DragLeaveEvent();
}

inline Windows::UI::Xaml::RoutedEvent UIElement::DragOverEvent()
{
    return get_activation_factory<UIElement, IUIElementStatics>().DragOverEvent();
}

inline Windows::UI::Xaml::RoutedEvent UIElement::DropEvent()
{
    return get_activation_factory<UIElement, IUIElementStatics>().DropEvent();
}

inline Windows::UI::Xaml::DependencyProperty UIElement::AllowDropProperty()
{
    return get_activation_factory<UIElement, IUIElementStatics>().AllowDropProperty();
}

inline Windows::UI::Xaml::DependencyProperty UIElement::OpacityProperty()
{
    return get_activation_factory<UIElement, IUIElementStatics>().OpacityProperty();
}

inline Windows::UI::Xaml::DependencyProperty UIElement::ClipProperty()
{
    return get_activation_factory<UIElement, IUIElementStatics>().ClipProperty();
}

inline Windows::UI::Xaml::DependencyProperty UIElement::RenderTransformProperty()
{
    return get_activation_factory<UIElement, IUIElementStatics>().RenderTransformProperty();
}

inline Windows::UI::Xaml::DependencyProperty UIElement::ProjectionProperty()
{
    return get_activation_factory<UIElement, IUIElementStatics>().ProjectionProperty();
}

inline Windows::UI::Xaml::DependencyProperty UIElement::RenderTransformOriginProperty()
{
    return get_activation_factory<UIElement, IUIElementStatics>().RenderTransformOriginProperty();
}

inline Windows::UI::Xaml::DependencyProperty UIElement::IsHitTestVisibleProperty()
{
    return get_activation_factory<UIElement, IUIElementStatics>().IsHitTestVisibleProperty();
}

inline Windows::UI::Xaml::DependencyProperty UIElement::VisibilityProperty()
{
    return get_activation_factory<UIElement, IUIElementStatics>().VisibilityProperty();
}

inline Windows::UI::Xaml::DependencyProperty UIElement::UseLayoutRoundingProperty()
{
    return get_activation_factory<UIElement, IUIElementStatics>().UseLayoutRoundingProperty();
}

inline Windows::UI::Xaml::DependencyProperty UIElement::TransitionsProperty()
{
    return get_activation_factory<UIElement, IUIElementStatics>().TransitionsProperty();
}

inline Windows::UI::Xaml::DependencyProperty UIElement::CacheModeProperty()
{
    return get_activation_factory<UIElement, IUIElementStatics>().CacheModeProperty();
}

inline Windows::UI::Xaml::DependencyProperty UIElement::IsTapEnabledProperty()
{
    return get_activation_factory<UIElement, IUIElementStatics>().IsTapEnabledProperty();
}

inline Windows::UI::Xaml::DependencyProperty UIElement::IsDoubleTapEnabledProperty()
{
    return get_activation_factory<UIElement, IUIElementStatics>().IsDoubleTapEnabledProperty();
}

inline Windows::UI::Xaml::DependencyProperty UIElement::IsRightTapEnabledProperty()
{
    return get_activation_factory<UIElement, IUIElementStatics>().IsRightTapEnabledProperty();
}

inline Windows::UI::Xaml::DependencyProperty UIElement::IsHoldingEnabledProperty()
{
    return get_activation_factory<UIElement, IUIElementStatics>().IsHoldingEnabledProperty();
}

inline Windows::UI::Xaml::DependencyProperty UIElement::ManipulationModeProperty()
{
    return get_activation_factory<UIElement, IUIElementStatics>().ManipulationModeProperty();
}

inline Windows::UI::Xaml::DependencyProperty UIElement::PointerCapturesProperty()
{
    return get_activation_factory<UIElement, IUIElementStatics>().PointerCapturesProperty();
}

inline Windows::UI::Xaml::DependencyProperty UIElement::CompositeModeProperty()
{
    return get_activation_factory<UIElement, IUIElementStatics2>().CompositeModeProperty();
}

inline Windows::UI::Xaml::DependencyProperty UIElement::Transform3DProperty()
{
    return get_activation_factory<UIElement, IUIElementStatics3>().Transform3DProperty();
}

inline Windows::UI::Xaml::DependencyProperty UIElement::CanDragProperty()
{
    return get_activation_factory<UIElement, IUIElementStatics3>().CanDragProperty();
}

inline bool UIElement::TryStartDirectManipulation(const Windows::UI::Xaml::Input::Pointer & value)
{
    return get_activation_factory<UIElement, IUIElementStatics3>().TryStartDirectManipulation(value);
}

inline Windows::UI::Xaml::DependencyProperty UIElement::ContextFlyoutProperty()
{
    return get_activation_factory<UIElement, IUIElementStatics4>().ContextFlyoutProperty();
}

inline Windows::UI::Xaml::DependencyProperty UIElement::ExitDisplayModeOnAccessKeyInvokedProperty()
{
    return get_activation_factory<UIElement, IUIElementStatics4>().ExitDisplayModeOnAccessKeyInvokedProperty();
}

inline Windows::UI::Xaml::DependencyProperty UIElement::IsAccessKeyScopeProperty()
{
    return get_activation_factory<UIElement, IUIElementStatics4>().IsAccessKeyScopeProperty();
}

inline Windows::UI::Xaml::DependencyProperty UIElement::AccessKeyScopeOwnerProperty()
{
    return get_activation_factory<UIElement, IUIElementStatics4>().AccessKeyScopeOwnerProperty();
}

inline Windows::UI::Xaml::DependencyProperty UIElement::AccessKeyProperty()
{
    return get_activation_factory<UIElement, IUIElementStatics4>().AccessKeyProperty();
}

inline VisualState::VisualState() :
    VisualState(activate_instance<VisualState>())
{}

inline VisualStateChangedEventArgs::VisualStateChangedEventArgs() :
    VisualStateChangedEventArgs(activate_instance<VisualStateChangedEventArgs>())
{}

inline VisualStateGroup::VisualStateGroup() :
    VisualStateGroup(activate_instance<VisualStateGroup>())
{}

inline VisualStateManager::VisualStateManager()
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<VisualStateManager, IVisualStateManagerFactory>().CreateInstance(outer, inner));
}

inline Windows::Foundation::Collections::IVector<Windows::UI::Xaml::VisualStateGroup> VisualStateManager::GetVisualStateGroups(const Windows::UI::Xaml::FrameworkElement & obj)
{
    return get_activation_factory<VisualStateManager, IVisualStateManagerStatics>().GetVisualStateGroups(obj);
}

inline Windows::UI::Xaml::DependencyProperty VisualStateManager::CustomVisualStateManagerProperty()
{
    return get_activation_factory<VisualStateManager, IVisualStateManagerStatics>().CustomVisualStateManagerProperty();
}

inline Windows::UI::Xaml::VisualStateManager VisualStateManager::GetCustomVisualStateManager(const Windows::UI::Xaml::FrameworkElement & obj)
{
    return get_activation_factory<VisualStateManager, IVisualStateManagerStatics>().GetCustomVisualStateManager(obj);
}

inline void VisualStateManager::SetCustomVisualStateManager(const Windows::UI::Xaml::FrameworkElement & obj, const Windows::UI::Xaml::VisualStateManager & value)
{
    get_activation_factory<VisualStateManager, IVisualStateManagerStatics>().SetCustomVisualStateManager(obj, value);
}

inline bool VisualStateManager::GoToState(const Windows::UI::Xaml::Controls::Control & control, hstring_view stateName, bool useTransitions)
{
    return get_activation_factory<VisualStateManager, IVisualStateManagerStatics>().GoToState(control, stateName, useTransitions);
}

inline VisualTransition::VisualTransition()
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<VisualTransition, IVisualTransitionFactory>().CreateInstance(outer, inner));
}

inline Windows::UI::Xaml::Window Window::Current()
{
    return get_activation_factory<Window, IWindowStatics>().Current();
}

}

}
#pragma warning(pop)
