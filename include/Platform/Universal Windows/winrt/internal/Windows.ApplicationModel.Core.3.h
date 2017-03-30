// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.Core.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::Core {

struct WINRT_EBO AppListEntry :
    Windows::ApplicationModel::Core::IAppListEntry
{
    AppListEntry(std::nullptr_t) noexcept {}
};

struct CoreApplication
{
    CoreApplication() = delete;
    static hstring Id();
    static event_token Suspending(const Windows::Foundation::EventHandler<Windows::ApplicationModel::SuspendingEventArgs> & handler);
    using Suspending_revoker = factory_event_revoker<ICoreApplication>;
    static Suspending_revoker Suspending(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::ApplicationModel::SuspendingEventArgs> & handler);
    static void Suspending(event_token token);
    static event_token Resuming(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    using Resuming_revoker = factory_event_revoker<ICoreApplication>;
    static Resuming_revoker Resuming(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    static void Resuming(event_token token);
    static Windows::Foundation::Collections::IPropertySet Properties();
    static Windows::ApplicationModel::Core::CoreApplicationView GetCurrentView();
    static void Run(const Windows::ApplicationModel::Core::IFrameworkViewSource & viewSource);
    static void RunWithActivationFactories(const Windows::Foundation::IGetActivationFactory & activationFactoryCallback);
    static event_token BackgroundActivated(const Windows::Foundation::EventHandler<Windows::ApplicationModel::Activation::BackgroundActivatedEventArgs> & handler);
    using BackgroundActivated_revoker = factory_event_revoker<ICoreApplication2>;
    static BackgroundActivated_revoker BackgroundActivated(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::ApplicationModel::Activation::BackgroundActivatedEventArgs> & handler);
    static void BackgroundActivated(event_token token);
    static event_token LeavingBackground(const Windows::Foundation::EventHandler<Windows::ApplicationModel::LeavingBackgroundEventArgs> & handler);
    using LeavingBackground_revoker = factory_event_revoker<ICoreApplication2>;
    static LeavingBackground_revoker LeavingBackground(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::ApplicationModel::LeavingBackgroundEventArgs> & handler);
    static void LeavingBackground(event_token token);
    static event_token EnteredBackground(const Windows::Foundation::EventHandler<Windows::ApplicationModel::EnteredBackgroundEventArgs> & handler);
    using EnteredBackground_revoker = factory_event_revoker<ICoreApplication2>;
    static EnteredBackground_revoker EnteredBackground(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::ApplicationModel::EnteredBackgroundEventArgs> & handler);
    static void EnteredBackground(event_token token);
    static void EnablePrelaunch(bool value);
    static void Exit();
    static event_token Exiting(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    using Exiting_revoker = factory_event_revoker<ICoreApplicationExit>;
    static Exiting_revoker Exiting(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    static void Exiting(event_token token);
    static event_token UnhandledErrorDetected(const Windows::Foundation::EventHandler<Windows::ApplicationModel::Core::UnhandledErrorDetectedEventArgs> & handler);
    using UnhandledErrorDetected_revoker = factory_event_revoker<ICoreApplicationUnhandledError>;
    static UnhandledErrorDetected_revoker UnhandledErrorDetected(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::ApplicationModel::Core::UnhandledErrorDetectedEventArgs> & handler);
    static void UnhandledErrorDetected(event_token token);
    static void IncrementApplicationUseCount();
    static void DecrementApplicationUseCount();
    static Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Core::CoreApplicationView> Views();
    static Windows::ApplicationModel::Core::CoreApplicationView CreateNewView(hstring_view runtimeType, hstring_view entryPoint);
    static Windows::ApplicationModel::Core::CoreApplicationView MainView();
    static Windows::ApplicationModel::Core::CoreApplicationView CreateNewView();
    static Windows::ApplicationModel::Core::CoreApplicationView CreateNewView(const Windows::ApplicationModel::Core::IFrameworkViewSource & viewSource);
};

struct WINRT_EBO CoreApplicationView :
    Windows::ApplicationModel::Core::ICoreApplicationView,
    impl::require<CoreApplicationView, Windows::ApplicationModel::Core::ICoreApplicationView2, Windows::ApplicationModel::Core::ICoreApplicationView3>
{
    CoreApplicationView(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CoreApplicationViewTitleBar :
    Windows::ApplicationModel::Core::ICoreApplicationViewTitleBar
{
    CoreApplicationViewTitleBar(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HostedViewClosingEventArgs :
    Windows::ApplicationModel::Core::IHostedViewClosingEventArgs
{
    HostedViewClosingEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO UnhandledError :
    Windows::ApplicationModel::Core::IUnhandledError
{
    UnhandledError(std::nullptr_t) noexcept {}
};

struct WINRT_EBO UnhandledErrorDetectedEventArgs :
    Windows::ApplicationModel::Core::IUnhandledErrorDetectedEventArgs
{
    UnhandledErrorDetectedEventArgs(std::nullptr_t) noexcept {}
};

}

}
