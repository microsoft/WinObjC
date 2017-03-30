// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Navigation.1.h"
#include "Windows.UI.Xaml.1.h"
#include "Windows.UI.Xaml.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Navigation {

struct LoadCompletedEventHandler : Windows::Foundation::IUnknown
{
    LoadCompletedEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> LoadCompletedEventHandler(L lambda);
    template <typename F> LoadCompletedEventHandler (F * function);
    template <typename O, typename M> LoadCompletedEventHandler(O * object, M method);
    void operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Navigation::NavigationEventArgs & e) const;
};

struct NavigatedEventHandler : Windows::Foundation::IUnknown
{
    NavigatedEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> NavigatedEventHandler(L lambda);
    template <typename F> NavigatedEventHandler (F * function);
    template <typename O, typename M> NavigatedEventHandler(O * object, M method);
    void operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Navigation::NavigationEventArgs & e) const;
};

struct NavigatingCancelEventHandler : Windows::Foundation::IUnknown
{
    NavigatingCancelEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> NavigatingCancelEventHandler(L lambda);
    template <typename F> NavigatingCancelEventHandler (F * function);
    template <typename O, typename M> NavigatingCancelEventHandler(O * object, M method);
    void operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Navigation::NavigatingCancelEventArgs & e) const;
};

struct NavigationFailedEventHandler : Windows::Foundation::IUnknown
{
    NavigationFailedEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> NavigationFailedEventHandler(L lambda);
    template <typename F> NavigationFailedEventHandler (F * function);
    template <typename O, typename M> NavigationFailedEventHandler(O * object, M method);
    void operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Navigation::NavigationFailedEventArgs & e) const;
};

struct NavigationStoppedEventHandler : Windows::Foundation::IUnknown
{
    NavigationStoppedEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> NavigationStoppedEventHandler(L lambda);
    template <typename F> NavigationStoppedEventHandler (F * function);
    template <typename O, typename M> NavigationStoppedEventHandler(O * object, M method);
    void operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Navigation::NavigationEventArgs & e) const;
};

struct INavigatingCancelEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<INavigatingCancelEventArgs>
{
    INavigatingCancelEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct INavigatingCancelEventArgs2 :
    Windows::Foundation::IInspectable,
    impl::consume<INavigatingCancelEventArgs2>
{
    INavigatingCancelEventArgs2(std::nullptr_t = nullptr) noexcept {}
};

struct INavigationEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<INavigationEventArgs>
{
    INavigationEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct INavigationEventArgs2 :
    Windows::Foundation::IInspectable,
    impl::consume<INavigationEventArgs2>
{
    INavigationEventArgs2(std::nullptr_t = nullptr) noexcept {}
};

struct INavigationFailedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<INavigationFailedEventArgs>
{
    INavigationFailedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IPageStackEntry :
    Windows::Foundation::IInspectable,
    impl::consume<IPageStackEntry>
{
    IPageStackEntry(std::nullptr_t = nullptr) noexcept {}
};

struct IPageStackEntryFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IPageStackEntryFactory>
{
    IPageStackEntryFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IPageStackEntryStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IPageStackEntryStatics>
{
    IPageStackEntryStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
