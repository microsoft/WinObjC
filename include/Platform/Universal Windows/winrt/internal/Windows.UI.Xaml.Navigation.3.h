// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Navigation.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Navigation {

template <typename H> struct impl_LoadCompletedEventHandler : implements<impl_LoadCompletedEventHandler<H>, abi<LoadCompletedEventHandler>>, H
{
    impl_LoadCompletedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Navigation::INavigationEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Navigation::NavigationEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_NavigatedEventHandler : implements<impl_NavigatedEventHandler<H>, abi<NavigatedEventHandler>>, H
{
    impl_NavigatedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Navigation::INavigationEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Navigation::NavigationEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_NavigatingCancelEventHandler : implements<impl_NavigatingCancelEventHandler<H>, abi<NavigatingCancelEventHandler>>, H
{
    impl_NavigatingCancelEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Navigation::INavigatingCancelEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Navigation::NavigatingCancelEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_NavigationFailedEventHandler : implements<impl_NavigationFailedEventHandler<H>, abi<NavigationFailedEventHandler>>, H
{
    impl_NavigationFailedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Navigation::INavigationFailedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Navigation::NavigationFailedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_NavigationStoppedEventHandler : implements<impl_NavigationStoppedEventHandler<H>, abi<NavigationStoppedEventHandler>>, H
{
    impl_NavigationStoppedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Navigation::INavigationEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Navigation::NavigationEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::UI::Xaml::Navigation {

struct WINRT_EBO NavigatingCancelEventArgs :
    Windows::UI::Xaml::Navigation::INavigatingCancelEventArgs,
    impl::require<NavigatingCancelEventArgs, Windows::UI::Xaml::Navigation::INavigatingCancelEventArgs2>
{
    NavigatingCancelEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO NavigationEventArgs :
    Windows::UI::Xaml::Navigation::INavigationEventArgs,
    impl::require<NavigationEventArgs, Windows::UI::Xaml::Navigation::INavigationEventArgs2>
{
    NavigationEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO NavigationFailedEventArgs :
    Windows::UI::Xaml::Navigation::INavigationFailedEventArgs
{
    NavigationFailedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PageStackEntry :
    Windows::UI::Xaml::Navigation::IPageStackEntry,
    impl::bases<PageStackEntry, Windows::UI::Xaml::DependencyObject>,
    impl::require<PageStackEntry, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    PageStackEntry(std::nullptr_t) noexcept {}
    PageStackEntry(const Windows::UI::Xaml::Interop::TypeName & sourcePageType, const Windows::Foundation::IInspectable & parameter, const Windows::UI::Xaml::Media::Animation::NavigationTransitionInfo & navigationTransitionInfo);
    static Windows::UI::Xaml::DependencyProperty SourcePageTypeProperty();
};

}

}
