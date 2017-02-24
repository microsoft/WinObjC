// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.ApplicationModel.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.UI.Core.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.ApplicationModel.Core.3.h"
#include "Windows.ApplicationModel.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::Core::IAppListEntry> : produce_base<D, Windows::ApplicationModel::Core::IAppListEntry>
{
    HRESULT __stdcall get_DisplayInfo(impl::abi_arg_out<Windows::ApplicationModel::IAppDisplayInfo> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayInfo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LaunchAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().LaunchAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Core::ICoreApplication> : produce_base<D, Windows::ApplicationModel::Core::ICoreApplication>
{
    HRESULT __stdcall get_Id(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Suspending(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::ApplicationModel::SuspendingEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Suspending(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::ApplicationModel::SuspendingEventArgs> *>(&handler)));
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

    HRESULT __stdcall add_Resuming(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Resuming(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> *>(&handler)));
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

    HRESULT __stdcall get_Properties(impl::abi_arg_out<Windows::Foundation::Collections::IPropertySet> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Properties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCurrentView(impl::abi_arg_out<Windows::ApplicationModel::Core::ICoreApplicationView> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetCurrentView());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Run(impl::abi_arg_in<Windows::ApplicationModel::Core::IFrameworkViewSource> viewSource) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Run(*reinterpret_cast<const Windows::ApplicationModel::Core::IFrameworkViewSource *>(&viewSource));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RunWithActivationFactories(impl::abi_arg_in<Windows::Foundation::IGetActivationFactory> activationFactoryCallback) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RunWithActivationFactories(*reinterpret_cast<const Windows::Foundation::IGetActivationFactory *>(&activationFactoryCallback));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Core::ICoreApplication2> : produce_base<D, Windows::ApplicationModel::Core::ICoreApplication2>
{
    HRESULT __stdcall add_BackgroundActivated(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::ApplicationModel::Activation::BackgroundActivatedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().BackgroundActivated(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::ApplicationModel::Activation::BackgroundActivatedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_BackgroundActivated(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BackgroundActivated(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_LeavingBackground(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::ApplicationModel::LeavingBackgroundEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().LeavingBackground(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::ApplicationModel::LeavingBackgroundEventArgs> *>(&handler)));
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

    HRESULT __stdcall add_EnteredBackground(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::ApplicationModel::EnteredBackgroundEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().EnteredBackground(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::ApplicationModel::EnteredBackgroundEventArgs> *>(&handler)));
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

    HRESULT __stdcall abi_EnablePrelaunch(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnablePrelaunch(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Core::ICoreApplicationExit> : produce_base<D, Windows::ApplicationModel::Core::ICoreApplicationExit>
{
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

    HRESULT __stdcall add_Exiting(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Exiting(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Exiting(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Exiting(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Core::ICoreApplicationUnhandledError> : produce_base<D, Windows::ApplicationModel::Core::ICoreApplicationUnhandledError>
{
    HRESULT __stdcall add_UnhandledErrorDetected(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::ApplicationModel::Core::UnhandledErrorDetectedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().UnhandledErrorDetected(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::ApplicationModel::Core::UnhandledErrorDetectedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_UnhandledErrorDetected(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UnhandledErrorDetected(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Core::ICoreApplicationUseCount> : produce_base<D, Windows::ApplicationModel::Core::ICoreApplicationUseCount>
{
    HRESULT __stdcall abi_IncrementApplicationUseCount() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IncrementApplicationUseCount();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DecrementApplicationUseCount() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DecrementApplicationUseCount();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Core::ICoreApplicationView> : produce_base<D, Windows::ApplicationModel::Core::ICoreApplicationView>
{
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

    HRESULT __stdcall add_Activated(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Core::CoreApplicationView, Windows::ApplicationModel::Activation::IActivatedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Activated(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Core::CoreApplicationView, Windows::ApplicationModel::Activation::IActivatedEventArgs> *>(&handler)));
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

    HRESULT __stdcall get_IsMain(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsMain());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsHosted(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsHosted());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Core::ICoreApplicationView2> : produce_base<D, Windows::ApplicationModel::Core::ICoreApplicationView2>
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
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Core::ICoreApplicationView3> : produce_base<D, Windows::ApplicationModel::Core::ICoreApplicationView3>
{
    HRESULT __stdcall get_IsComponent(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsComponent());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TitleBar(impl::abi_arg_out<Windows::ApplicationModel::Core::ICoreApplicationViewTitleBar> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TitleBar());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_HostedViewClosing(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Core::CoreApplicationView, Windows::ApplicationModel::Core::HostedViewClosingEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().HostedViewClosing(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Core::CoreApplicationView, Windows::ApplicationModel::Core::HostedViewClosingEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_HostedViewClosing(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HostedViewClosing(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Core::ICoreApplicationViewTitleBar> : produce_base<D, Windows::ApplicationModel::Core::ICoreApplicationViewTitleBar>
{
    HRESULT __stdcall put_ExtendViewIntoTitleBar(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ExtendViewIntoTitleBar(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExtendViewIntoTitleBar(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendViewIntoTitleBar());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SystemOverlayLeftInset(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SystemOverlayLeftInset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SystemOverlayRightInset(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SystemOverlayRightInset());
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

    HRESULT __stdcall add_LayoutMetricsChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Core::CoreApplicationViewTitleBar, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().LayoutMetricsChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Core::CoreApplicationViewTitleBar, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_LayoutMetricsChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LayoutMetricsChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsVisible(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsVisible());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_IsVisibleChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Core::CoreApplicationViewTitleBar, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().IsVisibleChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Core::CoreApplicationViewTitleBar, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_IsVisibleChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsVisibleChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Core::ICoreImmersiveApplication> : produce_base<D, Windows::ApplicationModel::Core::ICoreImmersiveApplication>
{
    HRESULT __stdcall get_Views(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Core::CoreApplicationView>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Views());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateNewView(impl::abi_arg_in<hstring> runtimeType, impl::abi_arg_in<hstring> entryPoint, impl::abi_arg_out<Windows::ApplicationModel::Core::ICoreApplicationView> view) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *view = detach_abi(this->shim().CreateNewView(*reinterpret_cast<const hstring *>(&runtimeType), *reinterpret_cast<const hstring *>(&entryPoint)));
            return S_OK;
        }
        catch (...)
        {
            *view = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MainView(impl::abi_arg_out<Windows::ApplicationModel::Core::ICoreApplicationView> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MainView());
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
struct produce<D, Windows::ApplicationModel::Core::ICoreImmersiveApplication2> : produce_base<D, Windows::ApplicationModel::Core::ICoreImmersiveApplication2>
{
    HRESULT __stdcall abi_CreateNewViewFromMainView(impl::abi_arg_out<Windows::ApplicationModel::Core::ICoreApplicationView> view) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *view = detach_abi(this->shim().CreateNewView());
            return S_OK;
        }
        catch (...)
        {
            *view = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Core::ICoreImmersiveApplication3> : produce_base<D, Windows::ApplicationModel::Core::ICoreImmersiveApplication3>
{
    HRESULT __stdcall abi_CreateNewViewWithViewSource(impl::abi_arg_in<Windows::ApplicationModel::Core::IFrameworkViewSource> viewSource, impl::abi_arg_out<Windows::ApplicationModel::Core::ICoreApplicationView> view) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *view = detach_abi(this->shim().CreateNewView(*reinterpret_cast<const Windows::ApplicationModel::Core::IFrameworkViewSource *>(&viewSource)));
            return S_OK;
        }
        catch (...)
        {
            *view = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Core::IFrameworkView> : produce_base<D, Windows::ApplicationModel::Core::IFrameworkView>
{
    HRESULT __stdcall abi_Initialize(impl::abi_arg_in<Windows::ApplicationModel::Core::ICoreApplicationView> applicationView) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Initialize(*reinterpret_cast<const Windows::ApplicationModel::Core::CoreApplicationView *>(&applicationView));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetWindow(impl::abi_arg_in<Windows::UI::Core::ICoreWindow> window) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetWindow(*reinterpret_cast<const Windows::UI::Core::CoreWindow *>(&window));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Load(impl::abi_arg_in<hstring> entryPoint) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Load(*reinterpret_cast<const hstring *>(&entryPoint));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Run() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Run();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Uninitialize() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Uninitialize();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Core::IFrameworkViewSource> : produce_base<D, Windows::ApplicationModel::Core::IFrameworkViewSource>
{
    HRESULT __stdcall abi_CreateView(impl::abi_arg_out<Windows::ApplicationModel::Core::IFrameworkView> viewProvider) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *viewProvider = detach_abi(this->shim().CreateView());
            return S_OK;
        }
        catch (...)
        {
            *viewProvider = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Core::IHostedViewClosingEventArgs> : produce_base<D, Windows::ApplicationModel::Core::IHostedViewClosingEventArgs>
{
    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Foundation::IDeferral> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDeferral());
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
struct produce<D, Windows::ApplicationModel::Core::IUnhandledError> : produce_base<D, Windows::ApplicationModel::Core::IUnhandledError>
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

    HRESULT __stdcall abi_Propagate() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Propagate();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Core::IUnhandledErrorDetectedEventArgs> : produce_base<D, Windows::ApplicationModel::Core::IUnhandledErrorDetectedEventArgs>
{
    HRESULT __stdcall get_UnhandledError(impl::abi_arg_out<Windows::ApplicationModel::Core::IUnhandledError> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UnhandledError());
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

namespace Windows::ApplicationModel::Core {

template <typename D> Windows::ApplicationModel::AppDisplayInfo impl_IAppListEntry<D>::DisplayInfo() const
{
    Windows::ApplicationModel::AppDisplayInfo value { nullptr };
    check_hresult(WINRT_SHIM(IAppListEntry)->get_DisplayInfo(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IAppListEntry<D>::LaunchAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(IAppListEntry)->abi_LaunchAsync(put_abi(operation)));
    return operation;
}

template <typename D> void impl_IFrameworkView<D>::Initialize(const Windows::ApplicationModel::Core::CoreApplicationView & applicationView) const
{
    check_hresult(WINRT_SHIM(IFrameworkView)->abi_Initialize(get_abi(applicationView)));
}

template <typename D> void impl_IFrameworkView<D>::SetWindow(const Windows::UI::Core::CoreWindow & window) const
{
    check_hresult(WINRT_SHIM(IFrameworkView)->abi_SetWindow(get_abi(window)));
}

template <typename D> void impl_IFrameworkView<D>::Load(hstring_view entryPoint) const
{
    check_hresult(WINRT_SHIM(IFrameworkView)->abi_Load(get_abi(entryPoint)));
}

template <typename D> void impl_IFrameworkView<D>::Run() const
{
    check_hresult(WINRT_SHIM(IFrameworkView)->abi_Run());
}

template <typename D> void impl_IFrameworkView<D>::Uninitialize() const
{
    check_hresult(WINRT_SHIM(IFrameworkView)->abi_Uninitialize());
}

template <typename D> Windows::ApplicationModel::Core::IFrameworkView impl_IFrameworkViewSource<D>::CreateView() const
{
    Windows::ApplicationModel::Core::IFrameworkView viewProvider;
    check_hresult(WINRT_SHIM(IFrameworkViewSource)->abi_CreateView(put_abi(viewProvider)));
    return viewProvider;
}

template <typename D> hstring impl_ICoreApplication<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICoreApplication)->get_Id(put_abi(value)));
    return value;
}

template <typename D> event_token impl_ICoreApplication<D>::Suspending(const Windows::Foundation::EventHandler<Windows::ApplicationModel::SuspendingEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ICoreApplication)->add_Suspending(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ICoreApplication> impl_ICoreApplication<D>::Suspending(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::ApplicationModel::SuspendingEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreApplication>(this, &ABI::Windows::ApplicationModel::Core::ICoreApplication::remove_Suspending, Suspending(handler));
}

template <typename D> void impl_ICoreApplication<D>::Suspending(event_token token) const
{
    check_hresult(WINRT_SHIM(ICoreApplication)->remove_Suspending(token));
}

template <typename D> event_token impl_ICoreApplication<D>::Resuming(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ICoreApplication)->add_Resuming(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ICoreApplication> impl_ICoreApplication<D>::Resuming(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, ICoreApplication>(this, &ABI::Windows::ApplicationModel::Core::ICoreApplication::remove_Resuming, Resuming(handler));
}

template <typename D> void impl_ICoreApplication<D>::Resuming(event_token token) const
{
    check_hresult(WINRT_SHIM(ICoreApplication)->remove_Resuming(token));
}

template <typename D> Windows::Foundation::Collections::IPropertySet impl_ICoreApplication<D>::Properties() const
{
    Windows::Foundation::Collections::IPropertySet value;
    check_hresult(WINRT_SHIM(ICoreApplication)->get_Properties(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Core::CoreApplicationView impl_ICoreApplication<D>::GetCurrentView() const
{
    Windows::ApplicationModel::Core::CoreApplicationView value { nullptr };
    check_hresult(WINRT_SHIM(ICoreApplication)->abi_GetCurrentView(put_abi(value)));
    return value;
}

template <typename D> void impl_ICoreApplication<D>::Run(const Windows::ApplicationModel::Core::IFrameworkViewSource & viewSource) const
{
    check_hresult(WINRT_SHIM(ICoreApplication)->abi_Run(get_abi(viewSource)));
}

template <typename D> void impl_ICoreApplication<D>::RunWithActivationFactories(const Windows::Foundation::IGetActivationFactory & activationFactoryCallback) const
{
    check_hresult(WINRT_SHIM(ICoreApplication)->abi_RunWithActivationFactories(get_abi(activationFactoryCallback)));
}

template <typename D> void impl_ICoreApplicationUseCount<D>::IncrementApplicationUseCount() const
{
    check_hresult(WINRT_SHIM(ICoreApplicationUseCount)->abi_IncrementApplicationUseCount());
}

template <typename D> void impl_ICoreApplicationUseCount<D>::DecrementApplicationUseCount() const
{
    check_hresult(WINRT_SHIM(ICoreApplicationUseCount)->abi_DecrementApplicationUseCount());
}

template <typename D> void impl_ICoreApplicationExit<D>::Exit() const
{
    check_hresult(WINRT_SHIM(ICoreApplicationExit)->abi_Exit());
}

template <typename D> event_token impl_ICoreApplicationExit<D>::Exiting(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ICoreApplicationExit)->add_Exiting(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ICoreApplicationExit> impl_ICoreApplicationExit<D>::Exiting(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, ICoreApplicationExit>(this, &ABI::Windows::ApplicationModel::Core::ICoreApplicationExit::remove_Exiting, Exiting(handler));
}

template <typename D> void impl_ICoreApplicationExit<D>::Exiting(event_token token) const
{
    check_hresult(WINRT_SHIM(ICoreApplicationExit)->remove_Exiting(token));
}

template <typename D> event_token impl_ICoreApplication2<D>::BackgroundActivated(const Windows::Foundation::EventHandler<Windows::ApplicationModel::Activation::BackgroundActivatedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ICoreApplication2)->add_BackgroundActivated(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ICoreApplication2> impl_ICoreApplication2<D>::BackgroundActivated(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::ApplicationModel::Activation::BackgroundActivatedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreApplication2>(this, &ABI::Windows::ApplicationModel::Core::ICoreApplication2::remove_BackgroundActivated, BackgroundActivated(handler));
}

template <typename D> void impl_ICoreApplication2<D>::BackgroundActivated(event_token token) const
{
    check_hresult(WINRT_SHIM(ICoreApplication2)->remove_BackgroundActivated(token));
}

template <typename D> event_token impl_ICoreApplication2<D>::LeavingBackground(const Windows::Foundation::EventHandler<Windows::ApplicationModel::LeavingBackgroundEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ICoreApplication2)->add_LeavingBackground(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ICoreApplication2> impl_ICoreApplication2<D>::LeavingBackground(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::ApplicationModel::LeavingBackgroundEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreApplication2>(this, &ABI::Windows::ApplicationModel::Core::ICoreApplication2::remove_LeavingBackground, LeavingBackground(handler));
}

template <typename D> void impl_ICoreApplication2<D>::LeavingBackground(event_token token) const
{
    check_hresult(WINRT_SHIM(ICoreApplication2)->remove_LeavingBackground(token));
}

template <typename D> event_token impl_ICoreApplication2<D>::EnteredBackground(const Windows::Foundation::EventHandler<Windows::ApplicationModel::EnteredBackgroundEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ICoreApplication2)->add_EnteredBackground(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ICoreApplication2> impl_ICoreApplication2<D>::EnteredBackground(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::ApplicationModel::EnteredBackgroundEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreApplication2>(this, &ABI::Windows::ApplicationModel::Core::ICoreApplication2::remove_EnteredBackground, EnteredBackground(handler));
}

template <typename D> void impl_ICoreApplication2<D>::EnteredBackground(event_token token) const
{
    check_hresult(WINRT_SHIM(ICoreApplication2)->remove_EnteredBackground(token));
}

template <typename D> void impl_ICoreApplication2<D>::EnablePrelaunch(bool value) const
{
    check_hresult(WINRT_SHIM(ICoreApplication2)->abi_EnablePrelaunch(value));
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Core::CoreApplicationView> impl_ICoreImmersiveApplication<D>::Views() const
{
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Core::CoreApplicationView> value;
    check_hresult(WINRT_SHIM(ICoreImmersiveApplication)->get_Views(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Core::CoreApplicationView impl_ICoreImmersiveApplication<D>::CreateNewView(hstring_view runtimeType, hstring_view entryPoint) const
{
    Windows::ApplicationModel::Core::CoreApplicationView view { nullptr };
    check_hresult(WINRT_SHIM(ICoreImmersiveApplication)->abi_CreateNewView(get_abi(runtimeType), get_abi(entryPoint), put_abi(view)));
    return view;
}

template <typename D> Windows::ApplicationModel::Core::CoreApplicationView impl_ICoreImmersiveApplication<D>::MainView() const
{
    Windows::ApplicationModel::Core::CoreApplicationView value { nullptr };
    check_hresult(WINRT_SHIM(ICoreImmersiveApplication)->get_MainView(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Core::CoreApplicationView impl_ICoreImmersiveApplication2<D>::CreateNewView() const
{
    Windows::ApplicationModel::Core::CoreApplicationView view { nullptr };
    check_hresult(WINRT_SHIM(ICoreImmersiveApplication2)->abi_CreateNewViewFromMainView(put_abi(view)));
    return view;
}

template <typename D> Windows::ApplicationModel::Core::CoreApplicationView impl_ICoreImmersiveApplication3<D>::CreateNewView(const Windows::ApplicationModel::Core::IFrameworkViewSource & viewSource) const
{
    Windows::ApplicationModel::Core::CoreApplicationView view { nullptr };
    check_hresult(WINRT_SHIM(ICoreImmersiveApplication3)->abi_CreateNewViewWithViewSource(get_abi(viewSource), put_abi(view)));
    return view;
}

template <typename D> event_token impl_ICoreApplicationUnhandledError<D>::UnhandledErrorDetected(const Windows::Foundation::EventHandler<Windows::ApplicationModel::Core::UnhandledErrorDetectedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ICoreApplicationUnhandledError)->add_UnhandledErrorDetected(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ICoreApplicationUnhandledError> impl_ICoreApplicationUnhandledError<D>::UnhandledErrorDetected(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::ApplicationModel::Core::UnhandledErrorDetectedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreApplicationUnhandledError>(this, &ABI::Windows::ApplicationModel::Core::ICoreApplicationUnhandledError::remove_UnhandledErrorDetected, UnhandledErrorDetected(handler));
}

template <typename D> void impl_ICoreApplicationUnhandledError<D>::UnhandledErrorDetected(event_token token) const
{
    check_hresult(WINRT_SHIM(ICoreApplicationUnhandledError)->remove_UnhandledErrorDetected(token));
}

template <typename D> Windows::UI::Core::CoreWindow impl_ICoreApplicationView<D>::CoreWindow() const
{
    Windows::UI::Core::CoreWindow value { nullptr };
    check_hresult(WINRT_SHIM(ICoreApplicationView)->get_CoreWindow(put_abi(value)));
    return value;
}

template <typename D> event_token impl_ICoreApplicationView<D>::Activated(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Core::CoreApplicationView, Windows::ApplicationModel::Activation::IActivatedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ICoreApplicationView)->add_Activated(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ICoreApplicationView> impl_ICoreApplicationView<D>::Activated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Core::CoreApplicationView, Windows::ApplicationModel::Activation::IActivatedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreApplicationView>(this, &ABI::Windows::ApplicationModel::Core::ICoreApplicationView::remove_Activated, Activated(handler));
}

template <typename D> void impl_ICoreApplicationView<D>::Activated(event_token token) const
{
    check_hresult(WINRT_SHIM(ICoreApplicationView)->remove_Activated(token));
}

template <typename D> bool impl_ICoreApplicationView<D>::IsMain() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICoreApplicationView)->get_IsMain(&value));
    return value;
}

template <typename D> bool impl_ICoreApplicationView<D>::IsHosted() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICoreApplicationView)->get_IsHosted(&value));
    return value;
}

template <typename D> Windows::UI::Core::CoreDispatcher impl_ICoreApplicationView2<D>::Dispatcher() const
{
    Windows::UI::Core::CoreDispatcher value { nullptr };
    check_hresult(WINRT_SHIM(ICoreApplicationView2)->get_Dispatcher(put_abi(value)));
    return value;
}

template <typename D> bool impl_ICoreApplicationView3<D>::IsComponent() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICoreApplicationView3)->get_IsComponent(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Core::CoreApplicationViewTitleBar impl_ICoreApplicationView3<D>::TitleBar() const
{
    Windows::ApplicationModel::Core::CoreApplicationViewTitleBar value { nullptr };
    check_hresult(WINRT_SHIM(ICoreApplicationView3)->get_TitleBar(put_abi(value)));
    return value;
}

template <typename D> event_token impl_ICoreApplicationView3<D>::HostedViewClosing(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Core::CoreApplicationView, Windows::ApplicationModel::Core::HostedViewClosingEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ICoreApplicationView3)->add_HostedViewClosing(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ICoreApplicationView3> impl_ICoreApplicationView3<D>::HostedViewClosing(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Core::CoreApplicationView, Windows::ApplicationModel::Core::HostedViewClosingEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ICoreApplicationView3>(this, &ABI::Windows::ApplicationModel::Core::ICoreApplicationView3::remove_HostedViewClosing, HostedViewClosing(handler));
}

template <typename D> void impl_ICoreApplicationView3<D>::HostedViewClosing(event_token token) const
{
    check_hresult(WINRT_SHIM(ICoreApplicationView3)->remove_HostedViewClosing(token));
}

template <typename D> Windows::Foundation::Deferral impl_IHostedViewClosingEventArgs<D>::GetDeferral() const
{
    Windows::Foundation::Deferral result { nullptr };
    check_hresult(WINRT_SHIM(IHostedViewClosingEventArgs)->abi_GetDeferral(put_abi(result)));
    return result;
}

template <typename D> void impl_ICoreApplicationViewTitleBar<D>::ExtendViewIntoTitleBar(bool value) const
{
    check_hresult(WINRT_SHIM(ICoreApplicationViewTitleBar)->put_ExtendViewIntoTitleBar(value));
}

template <typename D> bool impl_ICoreApplicationViewTitleBar<D>::ExtendViewIntoTitleBar() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICoreApplicationViewTitleBar)->get_ExtendViewIntoTitleBar(&value));
    return value;
}

template <typename D> double impl_ICoreApplicationViewTitleBar<D>::SystemOverlayLeftInset() const
{
    double value {};
    check_hresult(WINRT_SHIM(ICoreApplicationViewTitleBar)->get_SystemOverlayLeftInset(&value));
    return value;
}

template <typename D> double impl_ICoreApplicationViewTitleBar<D>::SystemOverlayRightInset() const
{
    double value {};
    check_hresult(WINRT_SHIM(ICoreApplicationViewTitleBar)->get_SystemOverlayRightInset(&value));
    return value;
}

template <typename D> double impl_ICoreApplicationViewTitleBar<D>::Height() const
{
    double value {};
    check_hresult(WINRT_SHIM(ICoreApplicationViewTitleBar)->get_Height(&value));
    return value;
}

template <typename D> event_token impl_ICoreApplicationViewTitleBar<D>::LayoutMetricsChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Core::CoreApplicationViewTitleBar, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ICoreApplicationViewTitleBar)->add_LayoutMetricsChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ICoreApplicationViewTitleBar> impl_ICoreApplicationViewTitleBar<D>::LayoutMetricsChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Core::CoreApplicationViewTitleBar, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, ICoreApplicationViewTitleBar>(this, &ABI::Windows::ApplicationModel::Core::ICoreApplicationViewTitleBar::remove_LayoutMetricsChanged, LayoutMetricsChanged(handler));
}

template <typename D> void impl_ICoreApplicationViewTitleBar<D>::LayoutMetricsChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(ICoreApplicationViewTitleBar)->remove_LayoutMetricsChanged(token));
}

template <typename D> bool impl_ICoreApplicationViewTitleBar<D>::IsVisible() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICoreApplicationViewTitleBar)->get_IsVisible(&value));
    return value;
}

template <typename D> event_token impl_ICoreApplicationViewTitleBar<D>::IsVisibleChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Core::CoreApplicationViewTitleBar, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ICoreApplicationViewTitleBar)->add_IsVisibleChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ICoreApplicationViewTitleBar> impl_ICoreApplicationViewTitleBar<D>::IsVisibleChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Core::CoreApplicationViewTitleBar, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, ICoreApplicationViewTitleBar>(this, &ABI::Windows::ApplicationModel::Core::ICoreApplicationViewTitleBar::remove_IsVisibleChanged, IsVisibleChanged(handler));
}

template <typename D> void impl_ICoreApplicationViewTitleBar<D>::IsVisibleChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(ICoreApplicationViewTitleBar)->remove_IsVisibleChanged(token));
}

template <typename D> Windows::ApplicationModel::Core::UnhandledError impl_IUnhandledErrorDetectedEventArgs<D>::UnhandledError() const
{
    Windows::ApplicationModel::Core::UnhandledError value { nullptr };
    check_hresult(WINRT_SHIM(IUnhandledErrorDetectedEventArgs)->get_UnhandledError(put_abi(value)));
    return value;
}

template <typename D> bool impl_IUnhandledError<D>::Handled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IUnhandledError)->get_Handled(&value));
    return value;
}

template <typename D> void impl_IUnhandledError<D>::Propagate() const
{
    check_hresult(WINRT_SHIM(IUnhandledError)->abi_Propagate());
}

inline hstring CoreApplication::Id()
{
    return get_activation_factory<CoreApplication, ICoreApplication>().Id();
}

inline event_token CoreApplication::Suspending(const Windows::Foundation::EventHandler<Windows::ApplicationModel::SuspendingEventArgs> & handler)
{
    return get_activation_factory<CoreApplication, ICoreApplication>().Suspending(handler);
}

inline factory_event_revoker<ICoreApplication> CoreApplication::Suspending(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::ApplicationModel::SuspendingEventArgs> & handler)
{
    auto factory = get_activation_factory<CoreApplication, ICoreApplication>();
    return { factory, &ABI::Windows::ApplicationModel::Core::ICoreApplication::remove_Suspending, factory.Suspending(handler) };
}

inline void CoreApplication::Suspending(event_token token)
{
    get_activation_factory<CoreApplication, ICoreApplication>().Suspending(token);
}

inline event_token CoreApplication::Resuming(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    return get_activation_factory<CoreApplication, ICoreApplication>().Resuming(handler);
}

inline factory_event_revoker<ICoreApplication> CoreApplication::Resuming(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    auto factory = get_activation_factory<CoreApplication, ICoreApplication>();
    return { factory, &ABI::Windows::ApplicationModel::Core::ICoreApplication::remove_Resuming, factory.Resuming(handler) };
}

inline void CoreApplication::Resuming(event_token token)
{
    get_activation_factory<CoreApplication, ICoreApplication>().Resuming(token);
}

inline Windows::Foundation::Collections::IPropertySet CoreApplication::Properties()
{
    return get_activation_factory<CoreApplication, ICoreApplication>().Properties();
}

inline Windows::ApplicationModel::Core::CoreApplicationView CoreApplication::GetCurrentView()
{
    return get_activation_factory<CoreApplication, ICoreApplication>().GetCurrentView();
}

inline void CoreApplication::Run(const Windows::ApplicationModel::Core::IFrameworkViewSource & viewSource)
{
    get_activation_factory<CoreApplication, ICoreApplication>().Run(viewSource);
}

inline void CoreApplication::RunWithActivationFactories(const Windows::Foundation::IGetActivationFactory & activationFactoryCallback)
{
    get_activation_factory<CoreApplication, ICoreApplication>().RunWithActivationFactories(activationFactoryCallback);
}

inline event_token CoreApplication::BackgroundActivated(const Windows::Foundation::EventHandler<Windows::ApplicationModel::Activation::BackgroundActivatedEventArgs> & handler)
{
    return get_activation_factory<CoreApplication, ICoreApplication2>().BackgroundActivated(handler);
}

inline factory_event_revoker<ICoreApplication2> CoreApplication::BackgroundActivated(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::ApplicationModel::Activation::BackgroundActivatedEventArgs> & handler)
{
    auto factory = get_activation_factory<CoreApplication, ICoreApplication2>();
    return { factory, &ABI::Windows::ApplicationModel::Core::ICoreApplication2::remove_BackgroundActivated, factory.BackgroundActivated(handler) };
}

inline void CoreApplication::BackgroundActivated(event_token token)
{
    get_activation_factory<CoreApplication, ICoreApplication2>().BackgroundActivated(token);
}

inline event_token CoreApplication::LeavingBackground(const Windows::Foundation::EventHandler<Windows::ApplicationModel::LeavingBackgroundEventArgs> & handler)
{
    return get_activation_factory<CoreApplication, ICoreApplication2>().LeavingBackground(handler);
}

inline factory_event_revoker<ICoreApplication2> CoreApplication::LeavingBackground(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::ApplicationModel::LeavingBackgroundEventArgs> & handler)
{
    auto factory = get_activation_factory<CoreApplication, ICoreApplication2>();
    return { factory, &ABI::Windows::ApplicationModel::Core::ICoreApplication2::remove_LeavingBackground, factory.LeavingBackground(handler) };
}

inline void CoreApplication::LeavingBackground(event_token token)
{
    get_activation_factory<CoreApplication, ICoreApplication2>().LeavingBackground(token);
}

inline event_token CoreApplication::EnteredBackground(const Windows::Foundation::EventHandler<Windows::ApplicationModel::EnteredBackgroundEventArgs> & handler)
{
    return get_activation_factory<CoreApplication, ICoreApplication2>().EnteredBackground(handler);
}

inline factory_event_revoker<ICoreApplication2> CoreApplication::EnteredBackground(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::ApplicationModel::EnteredBackgroundEventArgs> & handler)
{
    auto factory = get_activation_factory<CoreApplication, ICoreApplication2>();
    return { factory, &ABI::Windows::ApplicationModel::Core::ICoreApplication2::remove_EnteredBackground, factory.EnteredBackground(handler) };
}

inline void CoreApplication::EnteredBackground(event_token token)
{
    get_activation_factory<CoreApplication, ICoreApplication2>().EnteredBackground(token);
}

inline void CoreApplication::EnablePrelaunch(bool value)
{
    get_activation_factory<CoreApplication, ICoreApplication2>().EnablePrelaunch(value);
}

inline void CoreApplication::Exit()
{
    get_activation_factory<CoreApplication, ICoreApplicationExit>().Exit();
}

inline event_token CoreApplication::Exiting(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    return get_activation_factory<CoreApplication, ICoreApplicationExit>().Exiting(handler);
}

inline factory_event_revoker<ICoreApplicationExit> CoreApplication::Exiting(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    auto factory = get_activation_factory<CoreApplication, ICoreApplicationExit>();
    return { factory, &ABI::Windows::ApplicationModel::Core::ICoreApplicationExit::remove_Exiting, factory.Exiting(handler) };
}

inline void CoreApplication::Exiting(event_token token)
{
    get_activation_factory<CoreApplication, ICoreApplicationExit>().Exiting(token);
}

inline event_token CoreApplication::UnhandledErrorDetected(const Windows::Foundation::EventHandler<Windows::ApplicationModel::Core::UnhandledErrorDetectedEventArgs> & handler)
{
    return get_activation_factory<CoreApplication, ICoreApplicationUnhandledError>().UnhandledErrorDetected(handler);
}

inline factory_event_revoker<ICoreApplicationUnhandledError> CoreApplication::UnhandledErrorDetected(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::ApplicationModel::Core::UnhandledErrorDetectedEventArgs> & handler)
{
    auto factory = get_activation_factory<CoreApplication, ICoreApplicationUnhandledError>();
    return { factory, &ABI::Windows::ApplicationModel::Core::ICoreApplicationUnhandledError::remove_UnhandledErrorDetected, factory.UnhandledErrorDetected(handler) };
}

inline void CoreApplication::UnhandledErrorDetected(event_token token)
{
    get_activation_factory<CoreApplication, ICoreApplicationUnhandledError>().UnhandledErrorDetected(token);
}

inline void CoreApplication::IncrementApplicationUseCount()
{
    get_activation_factory<CoreApplication, ICoreApplicationUseCount>().IncrementApplicationUseCount();
}

inline void CoreApplication::DecrementApplicationUseCount()
{
    get_activation_factory<CoreApplication, ICoreApplicationUseCount>().DecrementApplicationUseCount();
}

inline Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Core::CoreApplicationView> CoreApplication::Views()
{
    return get_activation_factory<CoreApplication, ICoreImmersiveApplication>().Views();
}

inline Windows::ApplicationModel::Core::CoreApplicationView CoreApplication::CreateNewView(hstring_view runtimeType, hstring_view entryPoint)
{
    return get_activation_factory<CoreApplication, ICoreImmersiveApplication>().CreateNewView(runtimeType, entryPoint);
}

inline Windows::ApplicationModel::Core::CoreApplicationView CoreApplication::MainView()
{
    return get_activation_factory<CoreApplication, ICoreImmersiveApplication>().MainView();
}

inline Windows::ApplicationModel::Core::CoreApplicationView CoreApplication::CreateNewView()
{
    return get_activation_factory<CoreApplication, ICoreImmersiveApplication2>().CreateNewView();
}

inline Windows::ApplicationModel::Core::CoreApplicationView CoreApplication::CreateNewView(const Windows::ApplicationModel::Core::IFrameworkViewSource & viewSource)
{
    return get_activation_factory<CoreApplication, ICoreImmersiveApplication3>().CreateNewView(viewSource);
}

}

}
#pragma warning(pop)
