// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.UI.Xaml.Navigation.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.UI.Xaml.0.h"
#include "Windows.UI.Xaml.Interop.0.h"
#include "Windows.UI.Xaml.Media.Animation.0.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Xaml::Navigation {

struct __declspec(uuid("fd1d67ae-eafb-4079-be80-6dc92a03aedf")) __declspec(novtable) INavigatingCancelEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Cancel(bool * value) = 0;
    virtual HRESULT __stdcall put_Cancel(bool value) = 0;
    virtual HRESULT __stdcall get_NavigationMode(winrt::Windows::UI::Xaml::Navigation::NavigationMode * value) = 0;
    virtual HRESULT __stdcall get_SourcePageType(Windows::UI::Xaml::Interop::TypeName * value) = 0;
};

struct __declspec(uuid("5407b704-8147-4343-838f-dd1ee908c137")) __declspec(novtable) INavigatingCancelEventArgs2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Parameter(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall get_NavigationTransitionInfo(Windows::UI::Xaml::Media::Animation::INavigationTransitionInfo ** value) = 0;
};

struct __declspec(uuid("b6aa9834-6691-44d1-bdf7-58820c27b0d0")) __declspec(novtable) INavigationEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Content(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall get_Parameter(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall get_SourcePageType(Windows::UI::Xaml::Interop::TypeName * value) = 0;
    virtual HRESULT __stdcall get_NavigationMode(winrt::Windows::UI::Xaml::Navigation::NavigationMode * value) = 0;
    virtual HRESULT __stdcall get_Uri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall put_Uri(Windows::Foundation::IUriRuntimeClass * value) = 0;
};

struct __declspec(uuid("dbff71d9-979a-4b2e-a49b-3bb17fdef574")) __declspec(novtable) INavigationEventArgs2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_NavigationTransitionInfo(Windows::UI::Xaml::Media::Animation::INavigationTransitionInfo ** value) = 0;
};

struct __declspec(uuid("11c1dff7-36c2-4102-b2ef-0217a97289b3")) __declspec(novtable) INavigationFailedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Exception(HRESULT * value) = 0;
    virtual HRESULT __stdcall get_Handled(bool * value) = 0;
    virtual HRESULT __stdcall put_Handled(bool value) = 0;
    virtual HRESULT __stdcall get_SourcePageType(Windows::UI::Xaml::Interop::TypeName * value) = 0;
};

struct __declspec(uuid("ef8814a6-9388-4aca-8572-405194069080")) __declspec(novtable) IPageStackEntry : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SourcePageType(Windows::UI::Xaml::Interop::TypeName * value) = 0;
    virtual HRESULT __stdcall get_Parameter(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall get_NavigationTransitionInfo(Windows::UI::Xaml::Media::Animation::INavigationTransitionInfo ** value) = 0;
};

struct __declspec(uuid("4454048a-a8b9-4f78-9b84-1f51f58851ff")) __declspec(novtable) IPageStackEntryFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::UI::Xaml::Interop::TypeName sourcePageType, Windows::Foundation::IInspectable * parameter, Windows::UI::Xaml::Media::Animation::INavigationTransitionInfo * navigationTransitionInfo, Windows::UI::Xaml::Navigation::IPageStackEntry ** instance) = 0;
};

struct __declspec(uuid("aceff8e3-246c-4033-9f01-01cb0da5254e")) __declspec(novtable) IPageStackEntryStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SourcePageTypeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("aebaf785-43fc-4e2c-95c3-97ae84eabc8e")) __declspec(novtable) LoadCompletedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::Navigation::INavigationEventArgs * e) = 0;
};

struct __declspec(uuid("7bd1cf54-23cf-4cce-b2f5-4ce78d96896e")) __declspec(novtable) NavigatedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::Navigation::INavigationEventArgs * e) = 0;
};

struct __declspec(uuid("75d6a78f-a302-4489-9898-24ea49182910")) __declspec(novtable) NavigatingCancelEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::Navigation::INavigatingCancelEventArgs * e) = 0;
};

struct __declspec(uuid("4dab4671-12b2-43c7-b892-9be2dcd3e88d")) __declspec(novtable) NavigationFailedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::Navigation::INavigationFailedEventArgs * e) = 0;
};

struct __declspec(uuid("f0117ddb-12fa-4d8d-8b26-b383d09c2b3c")) __declspec(novtable) NavigationStoppedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::Navigation::INavigationEventArgs * e) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::UI::Xaml::Navigation::NavigatingCancelEventArgs> { using default_interface = Windows::UI::Xaml::Navigation::INavigatingCancelEventArgs; };
template <> struct traits<Windows::UI::Xaml::Navigation::NavigationEventArgs> { using default_interface = Windows::UI::Xaml::Navigation::INavigationEventArgs; };
template <> struct traits<Windows::UI::Xaml::Navigation::NavigationFailedEventArgs> { using default_interface = Windows::UI::Xaml::Navigation::INavigationFailedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Navigation::PageStackEntry> { using default_interface = Windows::UI::Xaml::Navigation::IPageStackEntry; };

}

namespace Windows::UI::Xaml::Navigation {

template <typename D>
struct WINRT_EBO impl_INavigatingCancelEventArgs
{
    bool Cancel() const;
    void Cancel(bool value) const;
    Windows::UI::Xaml::Navigation::NavigationMode NavigationMode() const;
    Windows::UI::Xaml::Interop::TypeName SourcePageType() const;
};

template <typename D>
struct WINRT_EBO impl_INavigatingCancelEventArgs2
{
    Windows::Foundation::IInspectable Parameter() const;
    Windows::UI::Xaml::Media::Animation::NavigationTransitionInfo NavigationTransitionInfo() const;
};

template <typename D>
struct WINRT_EBO impl_INavigationEventArgs
{
    Windows::Foundation::IInspectable Content() const;
    Windows::Foundation::IInspectable Parameter() const;
    Windows::UI::Xaml::Interop::TypeName SourcePageType() const;
    Windows::UI::Xaml::Navigation::NavigationMode NavigationMode() const;
    Windows::Foundation::Uri Uri() const;
    void Uri(const Windows::Foundation::Uri & value) const;
};

template <typename D>
struct WINRT_EBO impl_INavigationEventArgs2
{
    Windows::UI::Xaml::Media::Animation::NavigationTransitionInfo NavigationTransitionInfo() const;
};

template <typename D>
struct WINRT_EBO impl_INavigationFailedEventArgs
{
    HRESULT Exception() const;
    bool Handled() const;
    void Handled(bool value) const;
    Windows::UI::Xaml::Interop::TypeName SourcePageType() const;
};

template <typename D>
struct WINRT_EBO impl_IPageStackEntry
{
    Windows::UI::Xaml::Interop::TypeName SourcePageType() const;
    Windows::Foundation::IInspectable Parameter() const;
    Windows::UI::Xaml::Media::Animation::NavigationTransitionInfo NavigationTransitionInfo() const;
};

template <typename D>
struct WINRT_EBO impl_IPageStackEntryFactory
{
    Windows::UI::Xaml::Navigation::PageStackEntry CreateInstance(const Windows::UI::Xaml::Interop::TypeName & sourcePageType, const Windows::Foundation::IInspectable & parameter, const Windows::UI::Xaml::Media::Animation::NavigationTransitionInfo & navigationTransitionInfo) const;
};

template <typename D>
struct WINRT_EBO impl_IPageStackEntryStatics
{
    Windows::UI::Xaml::DependencyProperty SourcePageTypeProperty() const;
};

}

namespace impl {

template <> struct traits<Windows::UI::Xaml::Navigation::INavigatingCancelEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Navigation::INavigatingCancelEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Navigation::impl_INavigatingCancelEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Navigation::INavigatingCancelEventArgs2>
{
    using abi = ABI::Windows::UI::Xaml::Navigation::INavigatingCancelEventArgs2;
    template <typename D> using consume = Windows::UI::Xaml::Navigation::impl_INavigatingCancelEventArgs2<D>;
};

template <> struct traits<Windows::UI::Xaml::Navigation::INavigationEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Navigation::INavigationEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Navigation::impl_INavigationEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Navigation::INavigationEventArgs2>
{
    using abi = ABI::Windows::UI::Xaml::Navigation::INavigationEventArgs2;
    template <typename D> using consume = Windows::UI::Xaml::Navigation::impl_INavigationEventArgs2<D>;
};

template <> struct traits<Windows::UI::Xaml::Navigation::INavigationFailedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Navigation::INavigationFailedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Navigation::impl_INavigationFailedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Navigation::IPageStackEntry>
{
    using abi = ABI::Windows::UI::Xaml::Navigation::IPageStackEntry;
    template <typename D> using consume = Windows::UI::Xaml::Navigation::impl_IPageStackEntry<D>;
};

template <> struct traits<Windows::UI::Xaml::Navigation::IPageStackEntryFactory>
{
    using abi = ABI::Windows::UI::Xaml::Navigation::IPageStackEntryFactory;
    template <typename D> using consume = Windows::UI::Xaml::Navigation::impl_IPageStackEntryFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Navigation::IPageStackEntryStatics>
{
    using abi = ABI::Windows::UI::Xaml::Navigation::IPageStackEntryStatics;
    template <typename D> using consume = Windows::UI::Xaml::Navigation::impl_IPageStackEntryStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Navigation::LoadCompletedEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::Navigation::LoadCompletedEventHandler;
};

template <> struct traits<Windows::UI::Xaml::Navigation::NavigatedEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::Navigation::NavigatedEventHandler;
};

template <> struct traits<Windows::UI::Xaml::Navigation::NavigatingCancelEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::Navigation::NavigatingCancelEventHandler;
};

template <> struct traits<Windows::UI::Xaml::Navigation::NavigationFailedEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::Navigation::NavigationFailedEventHandler;
};

template <> struct traits<Windows::UI::Xaml::Navigation::NavigationStoppedEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::Navigation::NavigationStoppedEventHandler;
};

template <> struct traits<Windows::UI::Xaml::Navigation::NavigatingCancelEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Navigation::NavigatingCancelEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Navigation.NavigatingCancelEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Navigation::NavigationEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Navigation::NavigationEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Navigation.NavigationEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Navigation::NavigationFailedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Navigation::NavigationFailedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Navigation.NavigationFailedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Navigation::PageStackEntry>
{
    using abi = ABI::Windows::UI::Xaml::Navigation::PageStackEntry;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Navigation.PageStackEntry"; }
};

}

}
