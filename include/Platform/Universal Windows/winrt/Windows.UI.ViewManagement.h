// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.UI.Core.3.h"
#include "internal/Windows.Devices.Enumeration.3.h"
#include "internal/Windows.UI.Popups.3.h"
#include "internal/Windows.UI.3.h"
#include "internal/Windows.UI.ViewManagement.3.h"
#include "Windows.UI.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::UI::ViewManagement::IAccessibilitySettings> : produce_base<D, Windows::UI::ViewManagement::IAccessibilitySettings>
{
    HRESULT __stdcall get_HighContrast(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HighContrast());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HighContrastScheme(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HighContrastScheme());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_HighContrastChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::AccessibilitySettings, Windows::Foundation::IInspectable>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().HighContrastChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::AccessibilitySettings, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_HighContrastChanged(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HighContrastChanged(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ViewManagement::IActivationViewSwitcher> : produce_base<D, Windows::UI::ViewManagement::IActivationViewSwitcher>
{
    HRESULT __stdcall abi_ShowAsStandaloneAsync(int32_t viewId, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ShowAsStandaloneAsync(viewId));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowAsStandaloneWithSizePreferenceAsync(int32_t viewId, Windows::UI::ViewManagement::ViewSizePreference sizePreference, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ShowAsStandaloneAsync(viewId, sizePreference));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsViewPresentedOnActivationVirtualDesktop(int32_t viewId, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsViewPresentedOnActivationVirtualDesktop(viewId));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ViewManagement::IApplicationView> : produce_base<D, Windows::UI::ViewManagement::IApplicationView>
{
    HRESULT __stdcall get_Orientation(Windows::UI::ViewManagement::ApplicationViewOrientation * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Orientation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AdjacentToLeftDisplayEdge(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AdjacentToLeftDisplayEdge());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AdjacentToRightDisplayEdge(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AdjacentToRightDisplayEdge());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsFullScreen(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsFullScreen());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsOnLockScreen(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsOnLockScreen());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsScreenCaptureEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsScreenCaptureEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsScreenCaptureEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsScreenCaptureEnabled(value);
            return S_OK;
        }
        catch (...)
        {
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

    HRESULT __stdcall get_Id(int32_t * value) noexcept override
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

    HRESULT __stdcall add_Consolidated(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::ApplicationView, Windows::UI::ViewManagement::ApplicationViewConsolidatedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Consolidated(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::ApplicationView, Windows::UI::ViewManagement::ApplicationViewConsolidatedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Consolidated(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Consolidated(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ViewManagement::IApplicationView2> : produce_base<D, Windows::UI::ViewManagement::IApplicationView2>
{
    HRESULT __stdcall get_SuppressSystemOverlays(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SuppressSystemOverlays());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SuppressSystemOverlays(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SuppressSystemOverlays(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VisibleBounds(impl::abi_arg_out<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VisibleBounds());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_VisibleBoundsChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::ApplicationView, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().VisibleBoundsChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::ApplicationView, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_VisibleBoundsChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VisibleBoundsChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetDesiredBoundsMode(Windows::UI::ViewManagement::ApplicationViewBoundsMode boundsMode, bool * success) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *success = detach_abi(this->shim().SetDesiredBoundsMode(boundsMode));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DesiredBoundsMode(Windows::UI::ViewManagement::ApplicationViewBoundsMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DesiredBoundsMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ViewManagement::IApplicationView3> : produce_base<D, Windows::UI::ViewManagement::IApplicationView3>
{
    HRESULT __stdcall get_TitleBar(impl::abi_arg_out<Windows::UI::ViewManagement::IApplicationViewTitleBar> value) noexcept override
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

    HRESULT __stdcall get_FullScreenSystemOverlayMode(Windows::UI::ViewManagement::FullScreenSystemOverlayMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FullScreenSystemOverlayMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_FullScreenSystemOverlayMode(Windows::UI::ViewManagement::FullScreenSystemOverlayMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FullScreenSystemOverlayMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsFullScreenMode(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsFullScreenMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryEnterFullScreenMode(bool * success) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *success = detach_abi(this->shim().TryEnterFullScreenMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ExitFullScreenMode() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ExitFullScreenMode();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowStandardSystemOverlays() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowStandardSystemOverlays();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryResizeView(impl::abi_arg_in<Windows::Foundation::Size> value, bool * success) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *success = detach_abi(this->shim().TryResizeView(*reinterpret_cast<const Windows::Foundation::Size *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPreferredMinSize(impl::abi_arg_in<Windows::Foundation::Size> minSize) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPreferredMinSize(*reinterpret_cast<const Windows::Foundation::Size *>(&minSize));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ViewManagement::IApplicationViewConsolidatedEventArgs> : produce_base<D, Windows::UI::ViewManagement::IApplicationViewConsolidatedEventArgs>
{
    HRESULT __stdcall get_IsUserInitiated(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsUserInitiated());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ViewManagement::IApplicationViewFullscreenStatics> : produce_base<D, Windows::UI::ViewManagement::IApplicationViewFullscreenStatics>
{
    HRESULT __stdcall abi_TryUnsnapToFullscreen(bool * success) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *success = detach_abi(this->shim().TryUnsnapToFullscreen());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ViewManagement::IApplicationViewInteropStatics> : produce_base<D, Windows::UI::ViewManagement::IApplicationViewInteropStatics>
{
    HRESULT __stdcall abi_GetApplicationViewIdForWindow(impl::abi_arg_in<Windows::UI::Core::ICoreWindow> window, int32_t * id) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *id = detach_abi(this->shim().GetApplicationViewIdForWindow(*reinterpret_cast<const Windows::UI::Core::ICoreWindow *>(&window)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ViewManagement::IApplicationViewScaling> : produce_base<D, Windows::UI::ViewManagement::IApplicationViewScaling>
{};

template <typename D>
struct produce<D, Windows::UI::ViewManagement::IApplicationViewScalingStatics> : produce_base<D, Windows::UI::ViewManagement::IApplicationViewScalingStatics>
{
    HRESULT __stdcall get_DisableLayoutScaling(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisableLayoutScaling());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TrySetDisableLayoutScaling(bool disableLayoutScaling, bool * success) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *success = detach_abi(this->shim().TrySetDisableLayoutScaling(disableLayoutScaling));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ViewManagement::IApplicationViewStatics> : produce_base<D, Windows::UI::ViewManagement::IApplicationViewStatics>
{
    HRESULT __stdcall get_Value(Windows::UI::ViewManagement::ApplicationViewState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Value());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryUnsnap(bool * success) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *success = detach_abi(this->shim().TryUnsnap());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ViewManagement::IApplicationViewStatics2> : produce_base<D, Windows::UI::ViewManagement::IApplicationViewStatics2>
{
    HRESULT __stdcall abi_GetForCurrentView(impl::abi_arg_out<Windows::UI::ViewManagement::IApplicationView> current) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *current = detach_abi(this->shim().GetForCurrentView());
            return S_OK;
        }
        catch (...)
        {
            *current = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TerminateAppOnFinalViewClose(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TerminateAppOnFinalViewClose());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TerminateAppOnFinalViewClose(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TerminateAppOnFinalViewClose(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ViewManagement::IApplicationViewStatics3> : produce_base<D, Windows::UI::ViewManagement::IApplicationViewStatics3>
{
    HRESULT __stdcall get_PreferredLaunchWindowingMode(Windows::UI::ViewManagement::ApplicationViewWindowingMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PreferredLaunchWindowingMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PreferredLaunchWindowingMode(Windows::UI::ViewManagement::ApplicationViewWindowingMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PreferredLaunchWindowingMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PreferredLaunchViewSize(impl::abi_arg_out<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PreferredLaunchViewSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PreferredLaunchViewSize(impl::abi_arg_in<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PreferredLaunchViewSize(*reinterpret_cast<const Windows::Foundation::Size *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ViewManagement::IApplicationViewSwitcherStatics> : produce_base<D, Windows::UI::ViewManagement::IApplicationViewSwitcherStatics>
{
    HRESULT __stdcall abi_DisableShowingMainViewOnActivation() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisableShowingMainViewOnActivation();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryShowAsStandaloneAsync(int32_t viewId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().TryShowAsStandaloneAsync(viewId));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryShowAsStandaloneWithSizePreferenceAsync(int32_t viewId, Windows::UI::ViewManagement::ViewSizePreference sizePreference, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().TryShowAsStandaloneAsync(viewId, sizePreference));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryShowAsStandaloneWithAnchorViewAndSizePreferenceAsync(int32_t viewId, Windows::UI::ViewManagement::ViewSizePreference sizePreference, int32_t anchorViewId, Windows::UI::ViewManagement::ViewSizePreference anchorSizePreference, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().TryShowAsStandaloneAsync(viewId, sizePreference, anchorViewId, anchorSizePreference));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SwitchAsync(int32_t viewId, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().SwitchAsync(viewId));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SwitchFromViewAsync(int32_t toViewId, int32_t fromViewId, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().SwitchAsync(toViewId, fromViewId));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SwitchFromViewWithOptionsAsync(int32_t toViewId, int32_t fromViewId, Windows::UI::ViewManagement::ApplicationViewSwitchingOptions options, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().SwitchAsync(toViewId, fromViewId, options));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PrepareForCustomAnimatedSwitchAsync(int32_t toViewId, int32_t fromViewId, Windows::UI::ViewManagement::ApplicationViewSwitchingOptions options, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().PrepareForCustomAnimatedSwitchAsync(toViewId, fromViewId, options));
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
struct produce<D, Windows::UI::ViewManagement::IApplicationViewSwitcherStatics2> : produce_base<D, Windows::UI::ViewManagement::IApplicationViewSwitcherStatics2>
{
    HRESULT __stdcall abi_DisableSystemViewActivationPolicy() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisableSystemViewActivationPolicy();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ViewManagement::IApplicationViewTitleBar> : produce_base<D, Windows::UI::ViewManagement::IApplicationViewTitleBar>
{
    HRESULT __stdcall put_ForegroundColor(impl::abi_arg_in<Windows::Foundation::IReference<Windows::UI::Color>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ForegroundColor(*reinterpret_cast<const Windows::Foundation::IReference<Windows::UI::Color> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ForegroundColor(impl::abi_arg_out<Windows::Foundation::IReference<Windows::UI::Color>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ForegroundColor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BackgroundColor(impl::abi_arg_in<Windows::Foundation::IReference<Windows::UI::Color>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BackgroundColor(*reinterpret_cast<const Windows::Foundation::IReference<Windows::UI::Color> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BackgroundColor(impl::abi_arg_out<Windows::Foundation::IReference<Windows::UI::Color>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BackgroundColor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ButtonForegroundColor(impl::abi_arg_in<Windows::Foundation::IReference<Windows::UI::Color>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ButtonForegroundColor(*reinterpret_cast<const Windows::Foundation::IReference<Windows::UI::Color> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ButtonForegroundColor(impl::abi_arg_out<Windows::Foundation::IReference<Windows::UI::Color>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ButtonForegroundColor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ButtonBackgroundColor(impl::abi_arg_in<Windows::Foundation::IReference<Windows::UI::Color>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ButtonBackgroundColor(*reinterpret_cast<const Windows::Foundation::IReference<Windows::UI::Color> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ButtonBackgroundColor(impl::abi_arg_out<Windows::Foundation::IReference<Windows::UI::Color>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ButtonBackgroundColor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ButtonHoverForegroundColor(impl::abi_arg_in<Windows::Foundation::IReference<Windows::UI::Color>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ButtonHoverForegroundColor(*reinterpret_cast<const Windows::Foundation::IReference<Windows::UI::Color> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ButtonHoverForegroundColor(impl::abi_arg_out<Windows::Foundation::IReference<Windows::UI::Color>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ButtonHoverForegroundColor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ButtonHoverBackgroundColor(impl::abi_arg_in<Windows::Foundation::IReference<Windows::UI::Color>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ButtonHoverBackgroundColor(*reinterpret_cast<const Windows::Foundation::IReference<Windows::UI::Color> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ButtonHoverBackgroundColor(impl::abi_arg_out<Windows::Foundation::IReference<Windows::UI::Color>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ButtonHoverBackgroundColor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ButtonPressedForegroundColor(impl::abi_arg_in<Windows::Foundation::IReference<Windows::UI::Color>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ButtonPressedForegroundColor(*reinterpret_cast<const Windows::Foundation::IReference<Windows::UI::Color> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ButtonPressedForegroundColor(impl::abi_arg_out<Windows::Foundation::IReference<Windows::UI::Color>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ButtonPressedForegroundColor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ButtonPressedBackgroundColor(impl::abi_arg_in<Windows::Foundation::IReference<Windows::UI::Color>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ButtonPressedBackgroundColor(*reinterpret_cast<const Windows::Foundation::IReference<Windows::UI::Color> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ButtonPressedBackgroundColor(impl::abi_arg_out<Windows::Foundation::IReference<Windows::UI::Color>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ButtonPressedBackgroundColor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_InactiveForegroundColor(impl::abi_arg_in<Windows::Foundation::IReference<Windows::UI::Color>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InactiveForegroundColor(*reinterpret_cast<const Windows::Foundation::IReference<Windows::UI::Color> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InactiveForegroundColor(impl::abi_arg_out<Windows::Foundation::IReference<Windows::UI::Color>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InactiveForegroundColor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_InactiveBackgroundColor(impl::abi_arg_in<Windows::Foundation::IReference<Windows::UI::Color>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InactiveBackgroundColor(*reinterpret_cast<const Windows::Foundation::IReference<Windows::UI::Color> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InactiveBackgroundColor(impl::abi_arg_out<Windows::Foundation::IReference<Windows::UI::Color>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InactiveBackgroundColor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ButtonInactiveForegroundColor(impl::abi_arg_in<Windows::Foundation::IReference<Windows::UI::Color>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ButtonInactiveForegroundColor(*reinterpret_cast<const Windows::Foundation::IReference<Windows::UI::Color> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ButtonInactiveForegroundColor(impl::abi_arg_out<Windows::Foundation::IReference<Windows::UI::Color>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ButtonInactiveForegroundColor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ButtonInactiveBackgroundColor(impl::abi_arg_in<Windows::Foundation::IReference<Windows::UI::Color>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ButtonInactiveBackgroundColor(*reinterpret_cast<const Windows::Foundation::IReference<Windows::UI::Color> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ButtonInactiveBackgroundColor(impl::abi_arg_out<Windows::Foundation::IReference<Windows::UI::Color>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ButtonInactiveBackgroundColor());
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
struct produce<D, Windows::UI::ViewManagement::IApplicationViewTransferContext> : produce_base<D, Windows::UI::ViewManagement::IApplicationViewTransferContext>
{
    HRESULT __stdcall get_ViewId(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ViewId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ViewId(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ViewId(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ViewManagement::IApplicationViewTransferContextStatics> : produce_base<D, Windows::UI::ViewManagement::IApplicationViewTransferContextStatics>
{
    HRESULT __stdcall get_DataPackageFormatId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DataPackageFormatId());
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
struct produce<D, Windows::UI::ViewManagement::IInputPane> : produce_base<D, Windows::UI::ViewManagement::IInputPane>
{
    HRESULT __stdcall add_Showing(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::InputPane, Windows::UI::ViewManagement::InputPaneVisibilityEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Showing(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::InputPane, Windows::UI::ViewManagement::InputPaneVisibilityEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Showing(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Showing(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Hiding(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::InputPane, Windows::UI::ViewManagement::InputPaneVisibilityEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Hiding(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::InputPane, Windows::UI::ViewManagement::InputPaneVisibilityEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Hiding(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Hiding(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OccludedRect(impl::abi_arg_out<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OccludedRect());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ViewManagement::IInputPane2> : produce_base<D, Windows::UI::ViewManagement::IInputPane2>
{
    HRESULT __stdcall abi_TryShow(bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryShow());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryHide(bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryHide());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ViewManagement::IInputPaneControl> : produce_base<D, Windows::UI::ViewManagement::IInputPaneControl>
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

    HRESULT __stdcall put_Visible(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Visible(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ViewManagement::IInputPaneStatics> : produce_base<D, Windows::UI::ViewManagement::IInputPaneStatics>
{
    HRESULT __stdcall abi_GetForCurrentView(impl::abi_arg_out<Windows::UI::ViewManagement::IInputPane> inputPane) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *inputPane = detach_abi(this->shim().GetForCurrentView());
            return S_OK;
        }
        catch (...)
        {
            *inputPane = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ViewManagement::IInputPaneVisibilityEventArgs> : produce_base<D, Windows::UI::ViewManagement::IInputPaneVisibilityEventArgs>
{
    HRESULT __stdcall get_OccludedRect(impl::abi_arg_out<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OccludedRect());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EnsuredFocusedElementInView(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnsuredFocusedElementInView(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EnsuredFocusedElementInView(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EnsuredFocusedElementInView());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ViewManagement::IProjectionManagerStatics> : produce_base<D, Windows::UI::ViewManagement::IProjectionManagerStatics>
{
    HRESULT __stdcall abi_StartProjectingAsync(int32_t projectionViewId, int32_t anchorViewId, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().StartProjectingAsync(projectionViewId, anchorViewId));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SwapDisplaysForViewsAsync(int32_t projectionViewId, int32_t anchorViewId, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().SwapDisplaysForViewsAsync(projectionViewId, anchorViewId));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StopProjectingAsync(int32_t projectionViewId, int32_t anchorViewId, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().StopProjectingAsync(projectionViewId, anchorViewId));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProjectionDisplayAvailable(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProjectionDisplayAvailable());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ProjectionDisplayAvailableChanged(impl::abi_arg_in<Windows::Foundation::EventHandler<Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ProjectionDisplayAvailableChanged(*reinterpret_cast<const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ProjectionDisplayAvailableChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProjectionDisplayAvailableChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ViewManagement::IProjectionManagerStatics2> : produce_base<D, Windows::UI::ViewManagement::IProjectionManagerStatics2>
{
    HRESULT __stdcall abi_StartProjectingWithDeviceInfoAsync(int32_t projectionViewId, int32_t anchorViewId, impl::abi_arg_in<Windows::Devices::Enumeration::IDeviceInformation> displayDeviceInfo, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().StartProjectingAsync(projectionViewId, anchorViewId, *reinterpret_cast<const Windows::Devices::Enumeration::DeviceInformation *>(&displayDeviceInfo)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestStartProjectingAsync(int32_t projectionViewId, int32_t anchorViewId, impl::abi_arg_in<Windows::Foundation::Rect> selection, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestStartProjectingAsync(projectionViewId, anchorViewId, *reinterpret_cast<const Windows::Foundation::Rect *>(&selection)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestStartProjectingWithPlacementAsync(int32_t projectionViewId, int32_t anchorViewId, impl::abi_arg_in<Windows::Foundation::Rect> selection, Windows::UI::Popups::Placement prefferedPlacement, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestStartProjectingAsync(projectionViewId, anchorViewId, *reinterpret_cast<const Windows::Foundation::Rect *>(&selection), prefferedPlacement));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelector(impl::abi_arg_out<hstring> selector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *selector = detach_abi(this->shim().GetDeviceSelector());
            return S_OK;
        }
        catch (...)
        {
            *selector = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ViewManagement::IStatusBar> : produce_base<D, Windows::UI::ViewManagement::IStatusBar>
{
    HRESULT __stdcall abi_ShowAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().ShowAsync());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_HideAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().HideAsync());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BackgroundOpacity(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BackgroundOpacity());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BackgroundOpacity(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BackgroundOpacity(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ForegroundColor(impl::abi_arg_out<Windows::Foundation::IReference<Windows::UI::Color>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ForegroundColor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ForegroundColor(impl::abi_arg_in<Windows::Foundation::IReference<Windows::UI::Color>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ForegroundColor(*reinterpret_cast<const Windows::Foundation::IReference<Windows::UI::Color> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BackgroundColor(impl::abi_arg_out<Windows::Foundation::IReference<Windows::UI::Color>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BackgroundColor());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BackgroundColor(impl::abi_arg_in<Windows::Foundation::IReference<Windows::UI::Color>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BackgroundColor(*reinterpret_cast<const Windows::Foundation::IReference<Windows::UI::Color> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProgressIndicator(impl::abi_arg_out<Windows::UI::ViewManagement::IStatusBarProgressIndicator> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProgressIndicator());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OccludedRect(impl::abi_arg_out<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OccludedRect());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Showing(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::StatusBar, Windows::Foundation::IInspectable>> eventHandler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Showing(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::StatusBar, Windows::Foundation::IInspectable> *>(&eventHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Showing(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Showing(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Hiding(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::StatusBar, Windows::Foundation::IInspectable>> eventHandler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().Hiding(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::StatusBar, Windows::Foundation::IInspectable> *>(&eventHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Hiding(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Hiding(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ViewManagement::IStatusBarProgressIndicator> : produce_base<D, Windows::UI::ViewManagement::IStatusBarProgressIndicator>
{
    HRESULT __stdcall abi_ShowAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().ShowAsync());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_HideAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().HideAsync());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Text(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Text());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Text(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Text(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProgressValue(impl::abi_arg_out<Windows::Foundation::IReference<double>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProgressValue());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ProgressValue(impl::abi_arg_in<Windows::Foundation::IReference<double>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProgressValue(*reinterpret_cast<const Windows::Foundation::IReference<double> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ViewManagement::IStatusBarStatics> : produce_base<D, Windows::UI::ViewManagement::IStatusBarStatics>
{
    HRESULT __stdcall abi_GetForCurrentView(impl::abi_arg_out<Windows::UI::ViewManagement::IStatusBar> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetForCurrentView());
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
struct produce<D, Windows::UI::ViewManagement::IUISettings> : produce_base<D, Windows::UI::ViewManagement::IUISettings>
{
    HRESULT __stdcall get_HandPreference(Windows::UI::ViewManagement::HandPreference * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HandPreference());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CursorSize(impl::abi_arg_out<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CursorSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ScrollBarSize(impl::abi_arg_out<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ScrollBarSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ScrollBarArrowSize(impl::abi_arg_out<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ScrollBarArrowSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ScrollBarThumbBoxSize(impl::abi_arg_out<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ScrollBarThumbBoxSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MessageDuration(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MessageDuration());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AnimationsEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AnimationsEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CaretBrowsingEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CaretBrowsingEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CaretBlinkRate(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CaretBlinkRate());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CaretWidth(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CaretWidth());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DoubleClickTime(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DoubleClickTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MouseHoverTime(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MouseHoverTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UIElementColor(Windows::UI::ViewManagement::UIElementType desiredElement, impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UIElementColor(desiredElement));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ViewManagement::IUISettings2> : produce_base<D, Windows::UI::ViewManagement::IUISettings2>
{
    HRESULT __stdcall get_TextScaleFactor(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TextScaleFactor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_TextScaleFactorChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::UISettings, Windows::Foundation::IInspectable>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().TextScaleFactorChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::UISettings, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_TextScaleFactorChanged(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TextScaleFactorChanged(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ViewManagement::IUISettings3> : produce_base<D, Windows::UI::ViewManagement::IUISettings3>
{
    HRESULT __stdcall abi_GetColorValue(Windows::UI::ViewManagement::UIColorType desiredColor, impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetColorValue(desiredColor));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ColorValuesChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::UISettings, Windows::Foundation::IInspectable>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().ColorValuesChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::UISettings, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ColorValuesChanged(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ColorValuesChanged(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ViewManagement::IUIViewSettings> : produce_base<D, Windows::UI::ViewManagement::IUIViewSettings>
{
    HRESULT __stdcall get_UserInteractionMode(Windows::UI::ViewManagement::UserInteractionMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UserInteractionMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::ViewManagement::IUIViewSettingsStatics> : produce_base<D, Windows::UI::ViewManagement::IUIViewSettingsStatics>
{
    HRESULT __stdcall abi_GetForCurrentView(impl::abi_arg_out<Windows::UI::ViewManagement::IUIViewSettings> current) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *current = detach_abi(this->shim().GetForCurrentView());
            return S_OK;
        }
        catch (...)
        {
            *current = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::UI::ViewManagement {

template <typename D> void impl_IApplicationViewSwitcherStatics<D>::DisableShowingMainViewOnActivation() const
{
    check_hresult(WINRT_SHIM(IApplicationViewSwitcherStatics)->abi_DisableShowingMainViewOnActivation());
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IApplicationViewSwitcherStatics<D>::TryShowAsStandaloneAsync(int32_t viewId) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(IApplicationViewSwitcherStatics)->abi_TryShowAsStandaloneAsync(viewId, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IApplicationViewSwitcherStatics<D>::TryShowAsStandaloneAsync(int32_t viewId, Windows::UI::ViewManagement::ViewSizePreference sizePreference) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(IApplicationViewSwitcherStatics)->abi_TryShowAsStandaloneWithSizePreferenceAsync(viewId, sizePreference, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IApplicationViewSwitcherStatics<D>::TryShowAsStandaloneAsync(int32_t viewId, Windows::UI::ViewManagement::ViewSizePreference sizePreference, int32_t anchorViewId, Windows::UI::ViewManagement::ViewSizePreference anchorSizePreference) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(IApplicationViewSwitcherStatics)->abi_TryShowAsStandaloneWithAnchorViewAndSizePreferenceAsync(viewId, sizePreference, anchorViewId, anchorSizePreference, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IApplicationViewSwitcherStatics<D>::SwitchAsync(int32_t viewId) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IApplicationViewSwitcherStatics)->abi_SwitchAsync(viewId, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IApplicationViewSwitcherStatics<D>::SwitchAsync(int32_t toViewId, int32_t fromViewId) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IApplicationViewSwitcherStatics)->abi_SwitchFromViewAsync(toViewId, fromViewId, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IApplicationViewSwitcherStatics<D>::SwitchAsync(int32_t toViewId, int32_t fromViewId, Windows::UI::ViewManagement::ApplicationViewSwitchingOptions options) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IApplicationViewSwitcherStatics)->abi_SwitchFromViewWithOptionsAsync(toViewId, fromViewId, options, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IApplicationViewSwitcherStatics<D>::PrepareForCustomAnimatedSwitchAsync(int32_t toViewId, int32_t fromViewId, Windows::UI::ViewManagement::ApplicationViewSwitchingOptions options) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(IApplicationViewSwitcherStatics)->abi_PrepareForCustomAnimatedSwitchAsync(toViewId, fromViewId, options, put_abi(operation)));
    return operation;
}

template <typename D> void impl_IApplicationViewSwitcherStatics2<D>::DisableSystemViewActivationPolicy() const
{
    check_hresult(WINRT_SHIM(IApplicationViewSwitcherStatics2)->abi_DisableSystemViewActivationPolicy());
}

template <typename D> int32_t impl_IApplicationViewInteropStatics<D>::GetApplicationViewIdForWindow(const Windows::UI::Core::ICoreWindow & window) const
{
    int32_t id {};
    check_hresult(WINRT_SHIM(IApplicationViewInteropStatics)->abi_GetApplicationViewIdForWindow(get_abi(window), &id));
    return id;
}

template <typename D> Windows::UI::ViewManagement::ApplicationViewState impl_IApplicationViewStatics<D>::Value() const
{
    Windows::UI::ViewManagement::ApplicationViewState value {};
    check_hresult(WINRT_SHIM(IApplicationViewStatics)->get_Value(&value));
    return value;
}

template <typename D> bool impl_IApplicationViewStatics<D>::TryUnsnap() const
{
    bool success {};
    check_hresult(WINRT_SHIM(IApplicationViewStatics)->abi_TryUnsnap(&success));
    return success;
}

template <typename D> Windows::UI::ViewManagement::ApplicationView impl_IApplicationViewStatics2<D>::GetForCurrentView() const
{
    Windows::UI::ViewManagement::ApplicationView current { nullptr };
    check_hresult(WINRT_SHIM(IApplicationViewStatics2)->abi_GetForCurrentView(put_abi(current)));
    return current;
}

template <typename D> bool impl_IApplicationViewStatics2<D>::TerminateAppOnFinalViewClose() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IApplicationViewStatics2)->get_TerminateAppOnFinalViewClose(&value));
    return value;
}

template <typename D> void impl_IApplicationViewStatics2<D>::TerminateAppOnFinalViewClose(bool value) const
{
    check_hresult(WINRT_SHIM(IApplicationViewStatics2)->put_TerminateAppOnFinalViewClose(value));
}

template <typename D> Windows::UI::ViewManagement::ApplicationViewWindowingMode impl_IApplicationViewStatics3<D>::PreferredLaunchWindowingMode() const
{
    Windows::UI::ViewManagement::ApplicationViewWindowingMode value {};
    check_hresult(WINRT_SHIM(IApplicationViewStatics3)->get_PreferredLaunchWindowingMode(&value));
    return value;
}

template <typename D> void impl_IApplicationViewStatics3<D>::PreferredLaunchWindowingMode(Windows::UI::ViewManagement::ApplicationViewWindowingMode value) const
{
    check_hresult(WINRT_SHIM(IApplicationViewStatics3)->put_PreferredLaunchWindowingMode(value));
}

template <typename D> Windows::Foundation::Size impl_IApplicationViewStatics3<D>::PreferredLaunchViewSize() const
{
    Windows::Foundation::Size value {};
    check_hresult(WINRT_SHIM(IApplicationViewStatics3)->get_PreferredLaunchViewSize(put_abi(value)));
    return value;
}

template <typename D> void impl_IApplicationViewStatics3<D>::PreferredLaunchViewSize(const Windows::Foundation::Size & value) const
{
    check_hresult(WINRT_SHIM(IApplicationViewStatics3)->put_PreferredLaunchViewSize(get_abi(value)));
}

template <typename D> Windows::UI::ViewManagement::ApplicationViewOrientation impl_IApplicationView<D>::Orientation() const
{
    Windows::UI::ViewManagement::ApplicationViewOrientation value {};
    check_hresult(WINRT_SHIM(IApplicationView)->get_Orientation(&value));
    return value;
}

template <typename D> bool impl_IApplicationView<D>::AdjacentToLeftDisplayEdge() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IApplicationView)->get_AdjacentToLeftDisplayEdge(&value));
    return value;
}

template <typename D> bool impl_IApplicationView<D>::AdjacentToRightDisplayEdge() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IApplicationView)->get_AdjacentToRightDisplayEdge(&value));
    return value;
}

template <typename D> bool impl_IApplicationView<D>::IsFullScreen() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IApplicationView)->get_IsFullScreen(&value));
    return value;
}

template <typename D> bool impl_IApplicationView<D>::IsOnLockScreen() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IApplicationView)->get_IsOnLockScreen(&value));
    return value;
}

template <typename D> bool impl_IApplicationView<D>::IsScreenCaptureEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IApplicationView)->get_IsScreenCaptureEnabled(&value));
    return value;
}

template <typename D> void impl_IApplicationView<D>::IsScreenCaptureEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IApplicationView)->put_IsScreenCaptureEnabled(value));
}

template <typename D> void impl_IApplicationView<D>::Title(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IApplicationView)->put_Title(get_abi(value)));
}

template <typename D> hstring impl_IApplicationView<D>::Title() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IApplicationView)->get_Title(put_abi(value)));
    return value;
}

template <typename D> int32_t impl_IApplicationView<D>::Id() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IApplicationView)->get_Id(&value));
    return value;
}

template <typename D> event_token impl_IApplicationView<D>::Consolidated(const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::ApplicationView, Windows::UI::ViewManagement::ApplicationViewConsolidatedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IApplicationView)->add_Consolidated(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IApplicationView> impl_IApplicationView<D>::Consolidated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::ApplicationView, Windows::UI::ViewManagement::ApplicationViewConsolidatedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IApplicationView>(this, &ABI::Windows::UI::ViewManagement::IApplicationView::remove_Consolidated, Consolidated(handler));
}

template <typename D> void impl_IApplicationView<D>::Consolidated(event_token token) const
{
    check_hresult(WINRT_SHIM(IApplicationView)->remove_Consolidated(token));
}

template <typename D> bool impl_IApplicationView2<D>::SuppressSystemOverlays() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IApplicationView2)->get_SuppressSystemOverlays(&value));
    return value;
}

template <typename D> void impl_IApplicationView2<D>::SuppressSystemOverlays(bool value) const
{
    check_hresult(WINRT_SHIM(IApplicationView2)->put_SuppressSystemOverlays(value));
}

template <typename D> Windows::Foundation::Rect impl_IApplicationView2<D>::VisibleBounds() const
{
    Windows::Foundation::Rect value {};
    check_hresult(WINRT_SHIM(IApplicationView2)->get_VisibleBounds(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IApplicationView2<D>::VisibleBoundsChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::ApplicationView, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IApplicationView2)->add_VisibleBoundsChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IApplicationView2> impl_IApplicationView2<D>::VisibleBoundsChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::ApplicationView, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IApplicationView2>(this, &ABI::Windows::UI::ViewManagement::IApplicationView2::remove_VisibleBoundsChanged, VisibleBoundsChanged(handler));
}

template <typename D> void impl_IApplicationView2<D>::VisibleBoundsChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IApplicationView2)->remove_VisibleBoundsChanged(token));
}

template <typename D> bool impl_IApplicationView2<D>::SetDesiredBoundsMode(Windows::UI::ViewManagement::ApplicationViewBoundsMode boundsMode) const
{
    bool success {};
    check_hresult(WINRT_SHIM(IApplicationView2)->abi_SetDesiredBoundsMode(boundsMode, &success));
    return success;
}

template <typename D> Windows::UI::ViewManagement::ApplicationViewBoundsMode impl_IApplicationView2<D>::DesiredBoundsMode() const
{
    Windows::UI::ViewManagement::ApplicationViewBoundsMode value {};
    check_hresult(WINRT_SHIM(IApplicationView2)->get_DesiredBoundsMode(&value));
    return value;
}

template <typename D> void impl_IApplicationViewTitleBar<D>::ForegroundColor(const optional<Windows::UI::Color> & value) const
{
    check_hresult(WINRT_SHIM(IApplicationViewTitleBar)->put_ForegroundColor(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::UI::Color> impl_IApplicationViewTitleBar<D>::ForegroundColor() const
{
    Windows::Foundation::IReference<Windows::UI::Color> value;
    check_hresult(WINRT_SHIM(IApplicationViewTitleBar)->get_ForegroundColor(put_abi(value)));
    return value;
}

template <typename D> void impl_IApplicationViewTitleBar<D>::BackgroundColor(const optional<Windows::UI::Color> & value) const
{
    check_hresult(WINRT_SHIM(IApplicationViewTitleBar)->put_BackgroundColor(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::UI::Color> impl_IApplicationViewTitleBar<D>::BackgroundColor() const
{
    Windows::Foundation::IReference<Windows::UI::Color> value;
    check_hresult(WINRT_SHIM(IApplicationViewTitleBar)->get_BackgroundColor(put_abi(value)));
    return value;
}

template <typename D> void impl_IApplicationViewTitleBar<D>::ButtonForegroundColor(const optional<Windows::UI::Color> & value) const
{
    check_hresult(WINRT_SHIM(IApplicationViewTitleBar)->put_ButtonForegroundColor(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::UI::Color> impl_IApplicationViewTitleBar<D>::ButtonForegroundColor() const
{
    Windows::Foundation::IReference<Windows::UI::Color> value;
    check_hresult(WINRT_SHIM(IApplicationViewTitleBar)->get_ButtonForegroundColor(put_abi(value)));
    return value;
}

template <typename D> void impl_IApplicationViewTitleBar<D>::ButtonBackgroundColor(const optional<Windows::UI::Color> & value) const
{
    check_hresult(WINRT_SHIM(IApplicationViewTitleBar)->put_ButtonBackgroundColor(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::UI::Color> impl_IApplicationViewTitleBar<D>::ButtonBackgroundColor() const
{
    Windows::Foundation::IReference<Windows::UI::Color> value;
    check_hresult(WINRT_SHIM(IApplicationViewTitleBar)->get_ButtonBackgroundColor(put_abi(value)));
    return value;
}

template <typename D> void impl_IApplicationViewTitleBar<D>::ButtonHoverForegroundColor(const optional<Windows::UI::Color> & value) const
{
    check_hresult(WINRT_SHIM(IApplicationViewTitleBar)->put_ButtonHoverForegroundColor(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::UI::Color> impl_IApplicationViewTitleBar<D>::ButtonHoverForegroundColor() const
{
    Windows::Foundation::IReference<Windows::UI::Color> value;
    check_hresult(WINRT_SHIM(IApplicationViewTitleBar)->get_ButtonHoverForegroundColor(put_abi(value)));
    return value;
}

template <typename D> void impl_IApplicationViewTitleBar<D>::ButtonHoverBackgroundColor(const optional<Windows::UI::Color> & value) const
{
    check_hresult(WINRT_SHIM(IApplicationViewTitleBar)->put_ButtonHoverBackgroundColor(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::UI::Color> impl_IApplicationViewTitleBar<D>::ButtonHoverBackgroundColor() const
{
    Windows::Foundation::IReference<Windows::UI::Color> value;
    check_hresult(WINRT_SHIM(IApplicationViewTitleBar)->get_ButtonHoverBackgroundColor(put_abi(value)));
    return value;
}

template <typename D> void impl_IApplicationViewTitleBar<D>::ButtonPressedForegroundColor(const optional<Windows::UI::Color> & value) const
{
    check_hresult(WINRT_SHIM(IApplicationViewTitleBar)->put_ButtonPressedForegroundColor(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::UI::Color> impl_IApplicationViewTitleBar<D>::ButtonPressedForegroundColor() const
{
    Windows::Foundation::IReference<Windows::UI::Color> value;
    check_hresult(WINRT_SHIM(IApplicationViewTitleBar)->get_ButtonPressedForegroundColor(put_abi(value)));
    return value;
}

template <typename D> void impl_IApplicationViewTitleBar<D>::ButtonPressedBackgroundColor(const optional<Windows::UI::Color> & value) const
{
    check_hresult(WINRT_SHIM(IApplicationViewTitleBar)->put_ButtonPressedBackgroundColor(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::UI::Color> impl_IApplicationViewTitleBar<D>::ButtonPressedBackgroundColor() const
{
    Windows::Foundation::IReference<Windows::UI::Color> value;
    check_hresult(WINRT_SHIM(IApplicationViewTitleBar)->get_ButtonPressedBackgroundColor(put_abi(value)));
    return value;
}

template <typename D> void impl_IApplicationViewTitleBar<D>::InactiveForegroundColor(const optional<Windows::UI::Color> & value) const
{
    check_hresult(WINRT_SHIM(IApplicationViewTitleBar)->put_InactiveForegroundColor(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::UI::Color> impl_IApplicationViewTitleBar<D>::InactiveForegroundColor() const
{
    Windows::Foundation::IReference<Windows::UI::Color> value;
    check_hresult(WINRT_SHIM(IApplicationViewTitleBar)->get_InactiveForegroundColor(put_abi(value)));
    return value;
}

template <typename D> void impl_IApplicationViewTitleBar<D>::InactiveBackgroundColor(const optional<Windows::UI::Color> & value) const
{
    check_hresult(WINRT_SHIM(IApplicationViewTitleBar)->put_InactiveBackgroundColor(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::UI::Color> impl_IApplicationViewTitleBar<D>::InactiveBackgroundColor() const
{
    Windows::Foundation::IReference<Windows::UI::Color> value;
    check_hresult(WINRT_SHIM(IApplicationViewTitleBar)->get_InactiveBackgroundColor(put_abi(value)));
    return value;
}

template <typename D> void impl_IApplicationViewTitleBar<D>::ButtonInactiveForegroundColor(const optional<Windows::UI::Color> & value) const
{
    check_hresult(WINRT_SHIM(IApplicationViewTitleBar)->put_ButtonInactiveForegroundColor(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::UI::Color> impl_IApplicationViewTitleBar<D>::ButtonInactiveForegroundColor() const
{
    Windows::Foundation::IReference<Windows::UI::Color> value;
    check_hresult(WINRT_SHIM(IApplicationViewTitleBar)->get_ButtonInactiveForegroundColor(put_abi(value)));
    return value;
}

template <typename D> void impl_IApplicationViewTitleBar<D>::ButtonInactiveBackgroundColor(const optional<Windows::UI::Color> & value) const
{
    check_hresult(WINRT_SHIM(IApplicationViewTitleBar)->put_ButtonInactiveBackgroundColor(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::UI::Color> impl_IApplicationViewTitleBar<D>::ButtonInactiveBackgroundColor() const
{
    Windows::Foundation::IReference<Windows::UI::Color> value;
    check_hresult(WINRT_SHIM(IApplicationViewTitleBar)->get_ButtonInactiveBackgroundColor(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::ViewManagement::ApplicationViewTitleBar impl_IApplicationView3<D>::TitleBar() const
{
    Windows::UI::ViewManagement::ApplicationViewTitleBar value { nullptr };
    check_hresult(WINRT_SHIM(IApplicationView3)->get_TitleBar(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::ViewManagement::FullScreenSystemOverlayMode impl_IApplicationView3<D>::FullScreenSystemOverlayMode() const
{
    Windows::UI::ViewManagement::FullScreenSystemOverlayMode value {};
    check_hresult(WINRT_SHIM(IApplicationView3)->get_FullScreenSystemOverlayMode(&value));
    return value;
}

template <typename D> void impl_IApplicationView3<D>::FullScreenSystemOverlayMode(Windows::UI::ViewManagement::FullScreenSystemOverlayMode value) const
{
    check_hresult(WINRT_SHIM(IApplicationView3)->put_FullScreenSystemOverlayMode(value));
}

template <typename D> bool impl_IApplicationView3<D>::IsFullScreenMode() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IApplicationView3)->get_IsFullScreenMode(&value));
    return value;
}

template <typename D> bool impl_IApplicationView3<D>::TryEnterFullScreenMode() const
{
    bool success {};
    check_hresult(WINRT_SHIM(IApplicationView3)->abi_TryEnterFullScreenMode(&success));
    return success;
}

template <typename D> void impl_IApplicationView3<D>::ExitFullScreenMode() const
{
    check_hresult(WINRT_SHIM(IApplicationView3)->abi_ExitFullScreenMode());
}

template <typename D> void impl_IApplicationView3<D>::ShowStandardSystemOverlays() const
{
    check_hresult(WINRT_SHIM(IApplicationView3)->abi_ShowStandardSystemOverlays());
}

template <typename D> bool impl_IApplicationView3<D>::TryResizeView(const Windows::Foundation::Size & value) const
{
    bool success {};
    check_hresult(WINRT_SHIM(IApplicationView3)->abi_TryResizeView(get_abi(value), &success));
    return success;
}

template <typename D> void impl_IApplicationView3<D>::SetPreferredMinSize(const Windows::Foundation::Size & minSize) const
{
    check_hresult(WINRT_SHIM(IApplicationView3)->abi_SetPreferredMinSize(get_abi(minSize)));
}

template <typename D> bool impl_IApplicationViewFullscreenStatics<D>::TryUnsnapToFullscreen() const
{
    bool success {};
    check_hresult(WINRT_SHIM(IApplicationViewFullscreenStatics)->abi_TryUnsnapToFullscreen(&success));
    return success;
}

template <typename D> bool impl_IApplicationViewConsolidatedEventArgs<D>::IsUserInitiated() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IApplicationViewConsolidatedEventArgs)->get_IsUserInitiated(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IActivationViewSwitcher<D>::ShowAsStandaloneAsync(int32_t viewId) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IActivationViewSwitcher)->abi_ShowAsStandaloneAsync(viewId, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IActivationViewSwitcher<D>::ShowAsStandaloneAsync(int32_t viewId, Windows::UI::ViewManagement::ViewSizePreference sizePreference) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IActivationViewSwitcher)->abi_ShowAsStandaloneWithSizePreferenceAsync(viewId, sizePreference, put_abi(operation)));
    return operation;
}

template <typename D> bool impl_IActivationViewSwitcher<D>::IsViewPresentedOnActivationVirtualDesktop(int32_t viewId) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IActivationViewSwitcher)->abi_IsViewPresentedOnActivationVirtualDesktop(viewId, &value));
    return value;
}

template <typename D> int32_t impl_IApplicationViewTransferContext<D>::ViewId() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IApplicationViewTransferContext)->get_ViewId(&value));
    return value;
}

template <typename D> void impl_IApplicationViewTransferContext<D>::ViewId(int32_t value) const
{
    check_hresult(WINRT_SHIM(IApplicationViewTransferContext)->put_ViewId(value));
}

template <typename D> hstring impl_IApplicationViewTransferContextStatics<D>::DataPackageFormatId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IApplicationViewTransferContextStatics)->get_DataPackageFormatId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Rect impl_IInputPaneVisibilityEventArgs<D>::OccludedRect() const
{
    Windows::Foundation::Rect value {};
    check_hresult(WINRT_SHIM(IInputPaneVisibilityEventArgs)->get_OccludedRect(put_abi(value)));
    return value;
}

template <typename D> void impl_IInputPaneVisibilityEventArgs<D>::EnsuredFocusedElementInView(bool value) const
{
    check_hresult(WINRT_SHIM(IInputPaneVisibilityEventArgs)->put_EnsuredFocusedElementInView(value));
}

template <typename D> bool impl_IInputPaneVisibilityEventArgs<D>::EnsuredFocusedElementInView() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IInputPaneVisibilityEventArgs)->get_EnsuredFocusedElementInView(&value));
    return value;
}

template <typename D> event_token impl_IInputPane<D>::Showing(const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::InputPane, Windows::UI::ViewManagement::InputPaneVisibilityEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IInputPane)->add_Showing(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IInputPane> impl_IInputPane<D>::Showing(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::InputPane, Windows::UI::ViewManagement::InputPaneVisibilityEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IInputPane>(this, &ABI::Windows::UI::ViewManagement::IInputPane::remove_Showing, Showing(handler));
}

template <typename D> void impl_IInputPane<D>::Showing(event_token token) const
{
    check_hresult(WINRT_SHIM(IInputPane)->remove_Showing(token));
}

template <typename D> event_token impl_IInputPane<D>::Hiding(const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::InputPane, Windows::UI::ViewManagement::InputPaneVisibilityEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IInputPane)->add_Hiding(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IInputPane> impl_IInputPane<D>::Hiding(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::InputPane, Windows::UI::ViewManagement::InputPaneVisibilityEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IInputPane>(this, &ABI::Windows::UI::ViewManagement::IInputPane::remove_Hiding, Hiding(handler));
}

template <typename D> void impl_IInputPane<D>::Hiding(event_token token) const
{
    check_hresult(WINRT_SHIM(IInputPane)->remove_Hiding(token));
}

template <typename D> Windows::Foundation::Rect impl_IInputPane<D>::OccludedRect() const
{
    Windows::Foundation::Rect value {};
    check_hresult(WINRT_SHIM(IInputPane)->get_OccludedRect(put_abi(value)));
    return value;
}

template <typename D> bool impl_IInputPane2<D>::TryShow() const
{
    bool result {};
    check_hresult(WINRT_SHIM(IInputPane2)->abi_TryShow(&result));
    return result;
}

template <typename D> bool impl_IInputPane2<D>::TryHide() const
{
    bool result {};
    check_hresult(WINRT_SHIM(IInputPane2)->abi_TryHide(&result));
    return result;
}

template <typename D> bool impl_IInputPaneControl<D>::Visible() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IInputPaneControl)->get_Visible(&value));
    return value;
}

template <typename D> void impl_IInputPaneControl<D>::Visible(bool value) const
{
    check_hresult(WINRT_SHIM(IInputPaneControl)->put_Visible(value));
}

template <typename D> Windows::UI::ViewManagement::InputPane impl_IInputPaneStatics<D>::GetForCurrentView() const
{
    Windows::UI::ViewManagement::InputPane inputPane { nullptr };
    check_hresult(WINRT_SHIM(IInputPaneStatics)->abi_GetForCurrentView(put_abi(inputPane)));
    return inputPane;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IProjectionManagerStatics<D>::StartProjectingAsync(int32_t projectionViewId, int32_t anchorViewId) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IProjectionManagerStatics)->abi_StartProjectingAsync(projectionViewId, anchorViewId, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IProjectionManagerStatics<D>::SwapDisplaysForViewsAsync(int32_t projectionViewId, int32_t anchorViewId) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IProjectionManagerStatics)->abi_SwapDisplaysForViewsAsync(projectionViewId, anchorViewId, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IProjectionManagerStatics<D>::StopProjectingAsync(int32_t projectionViewId, int32_t anchorViewId) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IProjectionManagerStatics)->abi_StopProjectingAsync(projectionViewId, anchorViewId, put_abi(operation)));
    return operation;
}

template <typename D> bool impl_IProjectionManagerStatics<D>::ProjectionDisplayAvailable() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IProjectionManagerStatics)->get_ProjectionDisplayAvailable(&value));
    return value;
}

template <typename D> event_token impl_IProjectionManagerStatics<D>::ProjectionDisplayAvailableChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IProjectionManagerStatics)->add_ProjectionDisplayAvailableChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IProjectionManagerStatics> impl_IProjectionManagerStatics<D>::ProjectionDisplayAvailableChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IProjectionManagerStatics>(this, &ABI::Windows::UI::ViewManagement::IProjectionManagerStatics::remove_ProjectionDisplayAvailableChanged, ProjectionDisplayAvailableChanged(handler));
}

template <typename D> void impl_IProjectionManagerStatics<D>::ProjectionDisplayAvailableChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IProjectionManagerStatics)->remove_ProjectionDisplayAvailableChanged(token));
}

template <typename D> Windows::Foundation::IAsyncAction impl_IProjectionManagerStatics2<D>::StartProjectingAsync(int32_t projectionViewId, int32_t anchorViewId, const Windows::Devices::Enumeration::DeviceInformation & displayDeviceInfo) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IProjectionManagerStatics2)->abi_StartProjectingWithDeviceInfoAsync(projectionViewId, anchorViewId, get_abi(displayDeviceInfo), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IProjectionManagerStatics2<D>::RequestStartProjectingAsync(int32_t projectionViewId, int32_t anchorViewId, const Windows::Foundation::Rect & selection) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(IProjectionManagerStatics2)->abi_RequestStartProjectingAsync(projectionViewId, anchorViewId, get_abi(selection), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IProjectionManagerStatics2<D>::RequestStartProjectingAsync(int32_t projectionViewId, int32_t anchorViewId, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement prefferedPlacement) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(IProjectionManagerStatics2)->abi_RequestStartProjectingWithPlacementAsync(projectionViewId, anchorViewId, get_abi(selection), prefferedPlacement, put_abi(operation)));
    return operation;
}

template <typename D> hstring impl_IProjectionManagerStatics2<D>::GetDeviceSelector() const
{
    hstring selector;
    check_hresult(WINRT_SHIM(IProjectionManagerStatics2)->abi_GetDeviceSelector(put_abi(selector)));
    return selector;
}

template <typename D> Windows::UI::ViewManagement::UserInteractionMode impl_IUIViewSettings<D>::UserInteractionMode() const
{
    Windows::UI::ViewManagement::UserInteractionMode value {};
    check_hresult(WINRT_SHIM(IUIViewSettings)->get_UserInteractionMode(&value));
    return value;
}

template <typename D> Windows::UI::ViewManagement::UIViewSettings impl_IUIViewSettingsStatics<D>::GetForCurrentView() const
{
    Windows::UI::ViewManagement::UIViewSettings current { nullptr };
    check_hresult(WINRT_SHIM(IUIViewSettingsStatics)->abi_GetForCurrentView(put_abi(current)));
    return current;
}

template <typename D> bool impl_IAccessibilitySettings<D>::HighContrast() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IAccessibilitySettings)->get_HighContrast(&value));
    return value;
}

template <typename D> hstring impl_IAccessibilitySettings<D>::HighContrastScheme() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAccessibilitySettings)->get_HighContrastScheme(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IAccessibilitySettings<D>::HighContrastChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::AccessibilitySettings, Windows::Foundation::IInspectable> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IAccessibilitySettings)->add_HighContrastChanged(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IAccessibilitySettings> impl_IAccessibilitySettings<D>::HighContrastChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::AccessibilitySettings, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IAccessibilitySettings>(this, &ABI::Windows::UI::ViewManagement::IAccessibilitySettings::remove_HighContrastChanged, HighContrastChanged(handler));
}

template <typename D> void impl_IAccessibilitySettings<D>::HighContrastChanged(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IAccessibilitySettings)->remove_HighContrastChanged(cookie));
}

template <typename D> Windows::UI::ViewManagement::HandPreference impl_IUISettings<D>::HandPreference() const
{
    Windows::UI::ViewManagement::HandPreference value {};
    check_hresult(WINRT_SHIM(IUISettings)->get_HandPreference(&value));
    return value;
}

template <typename D> Windows::Foundation::Size impl_IUISettings<D>::CursorSize() const
{
    Windows::Foundation::Size value {};
    check_hresult(WINRT_SHIM(IUISettings)->get_CursorSize(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Size impl_IUISettings<D>::ScrollBarSize() const
{
    Windows::Foundation::Size value {};
    check_hresult(WINRT_SHIM(IUISettings)->get_ScrollBarSize(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Size impl_IUISettings<D>::ScrollBarArrowSize() const
{
    Windows::Foundation::Size value {};
    check_hresult(WINRT_SHIM(IUISettings)->get_ScrollBarArrowSize(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Size impl_IUISettings<D>::ScrollBarThumbBoxSize() const
{
    Windows::Foundation::Size value {};
    check_hresult(WINRT_SHIM(IUISettings)->get_ScrollBarThumbBoxSize(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IUISettings<D>::MessageDuration() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IUISettings)->get_MessageDuration(&value));
    return value;
}

template <typename D> bool impl_IUISettings<D>::AnimationsEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IUISettings)->get_AnimationsEnabled(&value));
    return value;
}

template <typename D> bool impl_IUISettings<D>::CaretBrowsingEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IUISettings)->get_CaretBrowsingEnabled(&value));
    return value;
}

template <typename D> uint32_t impl_IUISettings<D>::CaretBlinkRate() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IUISettings)->get_CaretBlinkRate(&value));
    return value;
}

template <typename D> uint32_t impl_IUISettings<D>::CaretWidth() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IUISettings)->get_CaretWidth(&value));
    return value;
}

template <typename D> uint32_t impl_IUISettings<D>::DoubleClickTime() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IUISettings)->get_DoubleClickTime(&value));
    return value;
}

template <typename D> uint32_t impl_IUISettings<D>::MouseHoverTime() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IUISettings)->get_MouseHoverTime(&value));
    return value;
}

template <typename D> Windows::UI::Color impl_IUISettings<D>::UIElementColor(Windows::UI::ViewManagement::UIElementType desiredElement) const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IUISettings)->abi_UIElementColor(desiredElement, put_abi(value)));
    return value;
}

template <typename D> double impl_IUISettings2<D>::TextScaleFactor() const
{
    double value {};
    check_hresult(WINRT_SHIM(IUISettings2)->get_TextScaleFactor(&value));
    return value;
}

template <typename D> event_token impl_IUISettings2<D>::TextScaleFactorChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::UISettings, Windows::Foundation::IInspectable> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IUISettings2)->add_TextScaleFactorChanged(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IUISettings2> impl_IUISettings2<D>::TextScaleFactorChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::UISettings, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IUISettings2>(this, &ABI::Windows::UI::ViewManagement::IUISettings2::remove_TextScaleFactorChanged, TextScaleFactorChanged(handler));
}

template <typename D> void impl_IUISettings2<D>::TextScaleFactorChanged(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IUISettings2)->remove_TextScaleFactorChanged(cookie));
}

template <typename D> Windows::UI::Color impl_IUISettings3<D>::GetColorValue(Windows::UI::ViewManagement::UIColorType desiredColor) const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IUISettings3)->abi_GetColorValue(desiredColor, put_abi(value)));
    return value;
}

template <typename D> event_token impl_IUISettings3<D>::ColorValuesChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::UISettings, Windows::Foundation::IInspectable> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IUISettings3)->add_ColorValuesChanged(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IUISettings3> impl_IUISettings3<D>::ColorValuesChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::UISettings, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IUISettings3>(this, &ABI::Windows::UI::ViewManagement::IUISettings3::remove_ColorValuesChanged, ColorValuesChanged(handler));
}

template <typename D> void impl_IUISettings3<D>::ColorValuesChanged(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IUISettings3)->remove_ColorValuesChanged(cookie));
}

template <typename D> bool impl_IApplicationViewScalingStatics<D>::DisableLayoutScaling() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IApplicationViewScalingStatics)->get_DisableLayoutScaling(&value));
    return value;
}

template <typename D> bool impl_IApplicationViewScalingStatics<D>::TrySetDisableLayoutScaling(bool disableLayoutScaling) const
{
    bool success {};
    check_hresult(WINRT_SHIM(IApplicationViewScalingStatics)->abi_TrySetDisableLayoutScaling(disableLayoutScaling, &success));
    return success;
}

template <typename D> Windows::UI::ViewManagement::StatusBar impl_IStatusBarStatics<D>::GetForCurrentView() const
{
    Windows::UI::ViewManagement::StatusBar value { nullptr };
    check_hresult(WINRT_SHIM(IStatusBarStatics)->abi_GetForCurrentView(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IStatusBar<D>::ShowAsync() const
{
    Windows::Foundation::IAsyncAction returnValue;
    check_hresult(WINRT_SHIM(IStatusBar)->abi_ShowAsync(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IStatusBar<D>::HideAsync() const
{
    Windows::Foundation::IAsyncAction returnValue;
    check_hresult(WINRT_SHIM(IStatusBar)->abi_HideAsync(put_abi(returnValue)));
    return returnValue;
}

template <typename D> double impl_IStatusBar<D>::BackgroundOpacity() const
{
    double value {};
    check_hresult(WINRT_SHIM(IStatusBar)->get_BackgroundOpacity(&value));
    return value;
}

template <typename D> void impl_IStatusBar<D>::BackgroundOpacity(double value) const
{
    check_hresult(WINRT_SHIM(IStatusBar)->put_BackgroundOpacity(value));
}

template <typename D> Windows::Foundation::IReference<Windows::UI::Color> impl_IStatusBar<D>::ForegroundColor() const
{
    Windows::Foundation::IReference<Windows::UI::Color> value;
    check_hresult(WINRT_SHIM(IStatusBar)->get_ForegroundColor(put_abi(value)));
    return value;
}

template <typename D> void impl_IStatusBar<D>::ForegroundColor(const optional<Windows::UI::Color> & value) const
{
    check_hresult(WINRT_SHIM(IStatusBar)->put_ForegroundColor(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::UI::Color> impl_IStatusBar<D>::BackgroundColor() const
{
    Windows::Foundation::IReference<Windows::UI::Color> value;
    check_hresult(WINRT_SHIM(IStatusBar)->get_BackgroundColor(put_abi(value)));
    return value;
}

template <typename D> void impl_IStatusBar<D>::BackgroundColor(const optional<Windows::UI::Color> & value) const
{
    check_hresult(WINRT_SHIM(IStatusBar)->put_BackgroundColor(get_abi(value)));
}

template <typename D> Windows::UI::ViewManagement::StatusBarProgressIndicator impl_IStatusBar<D>::ProgressIndicator() const
{
    Windows::UI::ViewManagement::StatusBarProgressIndicator value { nullptr };
    check_hresult(WINRT_SHIM(IStatusBar)->get_ProgressIndicator(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Rect impl_IStatusBar<D>::OccludedRect() const
{
    Windows::Foundation::Rect value {};
    check_hresult(WINRT_SHIM(IStatusBar)->get_OccludedRect(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IStatusBar<D>::Showing(const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::StatusBar, Windows::Foundation::IInspectable> & eventHandler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IStatusBar)->add_Showing(get_abi(eventHandler), &token));
    return token;
}

template <typename D> event_revoker<IStatusBar> impl_IStatusBar<D>::Showing(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::StatusBar, Windows::Foundation::IInspectable> & eventHandler) const
{
    return impl::make_event_revoker<D, IStatusBar>(this, &ABI::Windows::UI::ViewManagement::IStatusBar::remove_Showing, Showing(eventHandler));
}

template <typename D> void impl_IStatusBar<D>::Showing(event_token token) const
{
    check_hresult(WINRT_SHIM(IStatusBar)->remove_Showing(token));
}

template <typename D> event_token impl_IStatusBar<D>::Hiding(const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::StatusBar, Windows::Foundation::IInspectable> & eventHandler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IStatusBar)->add_Hiding(get_abi(eventHandler), &token));
    return token;
}

template <typename D> event_revoker<IStatusBar> impl_IStatusBar<D>::Hiding(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::StatusBar, Windows::Foundation::IInspectable> & eventHandler) const
{
    return impl::make_event_revoker<D, IStatusBar>(this, &ABI::Windows::UI::ViewManagement::IStatusBar::remove_Hiding, Hiding(eventHandler));
}

template <typename D> void impl_IStatusBar<D>::Hiding(event_token token) const
{
    check_hresult(WINRT_SHIM(IStatusBar)->remove_Hiding(token));
}

template <typename D> Windows::Foundation::IAsyncAction impl_IStatusBarProgressIndicator<D>::ShowAsync() const
{
    Windows::Foundation::IAsyncAction returnValue;
    check_hresult(WINRT_SHIM(IStatusBarProgressIndicator)->abi_ShowAsync(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IStatusBarProgressIndicator<D>::HideAsync() const
{
    Windows::Foundation::IAsyncAction returnValue;
    check_hresult(WINRT_SHIM(IStatusBarProgressIndicator)->abi_HideAsync(put_abi(returnValue)));
    return returnValue;
}

template <typename D> hstring impl_IStatusBarProgressIndicator<D>::Text() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IStatusBarProgressIndicator)->get_Text(put_abi(value)));
    return value;
}

template <typename D> void impl_IStatusBarProgressIndicator<D>::Text(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IStatusBarProgressIndicator)->put_Text(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<double> impl_IStatusBarProgressIndicator<D>::ProgressValue() const
{
    Windows::Foundation::IReference<double> value;
    check_hresult(WINRT_SHIM(IStatusBarProgressIndicator)->get_ProgressValue(put_abi(value)));
    return value;
}

template <typename D> void impl_IStatusBarProgressIndicator<D>::ProgressValue(const optional<double> & value) const
{
    check_hresult(WINRT_SHIM(IStatusBarProgressIndicator)->put_ProgressValue(get_abi(value)));
}

inline AccessibilitySettings::AccessibilitySettings() :
    AccessibilitySettings(activate_instance<AccessibilitySettings>())
{}

inline bool ApplicationView::TryUnsnapToFullscreen()
{
    return get_activation_factory<ApplicationView, IApplicationViewFullscreenStatics>().TryUnsnapToFullscreen();
}

inline int32_t ApplicationView::GetApplicationViewIdForWindow(const Windows::UI::Core::ICoreWindow & window)
{
    return get_activation_factory<ApplicationView, IApplicationViewInteropStatics>().GetApplicationViewIdForWindow(window);
}

inline Windows::UI::ViewManagement::ApplicationViewState ApplicationView::Value()
{
    return get_activation_factory<ApplicationView, IApplicationViewStatics>().Value();
}

inline bool ApplicationView::TryUnsnap()
{
    return get_activation_factory<ApplicationView, IApplicationViewStatics>().TryUnsnap();
}

inline Windows::UI::ViewManagement::ApplicationView ApplicationView::GetForCurrentView()
{
    return get_activation_factory<ApplicationView, IApplicationViewStatics2>().GetForCurrentView();
}

inline bool ApplicationView::TerminateAppOnFinalViewClose()
{
    return get_activation_factory<ApplicationView, IApplicationViewStatics2>().TerminateAppOnFinalViewClose();
}

inline void ApplicationView::TerminateAppOnFinalViewClose(bool value)
{
    get_activation_factory<ApplicationView, IApplicationViewStatics2>().TerminateAppOnFinalViewClose(value);
}

inline Windows::UI::ViewManagement::ApplicationViewWindowingMode ApplicationView::PreferredLaunchWindowingMode()
{
    return get_activation_factory<ApplicationView, IApplicationViewStatics3>().PreferredLaunchWindowingMode();
}

inline void ApplicationView::PreferredLaunchWindowingMode(Windows::UI::ViewManagement::ApplicationViewWindowingMode value)
{
    get_activation_factory<ApplicationView, IApplicationViewStatics3>().PreferredLaunchWindowingMode(value);
}

inline Windows::Foundation::Size ApplicationView::PreferredLaunchViewSize()
{
    return get_activation_factory<ApplicationView, IApplicationViewStatics3>().PreferredLaunchViewSize();
}

inline void ApplicationView::PreferredLaunchViewSize(const Windows::Foundation::Size & value)
{
    get_activation_factory<ApplicationView, IApplicationViewStatics3>().PreferredLaunchViewSize(value);
}

inline bool ApplicationViewScaling::DisableLayoutScaling()
{
    return get_activation_factory<ApplicationViewScaling, IApplicationViewScalingStatics>().DisableLayoutScaling();
}

inline bool ApplicationViewScaling::TrySetDisableLayoutScaling(bool disableLayoutScaling)
{
    return get_activation_factory<ApplicationViewScaling, IApplicationViewScalingStatics>().TrySetDisableLayoutScaling(disableLayoutScaling);
}

inline void ApplicationViewSwitcher::DisableShowingMainViewOnActivation()
{
    get_activation_factory<ApplicationViewSwitcher, IApplicationViewSwitcherStatics>().DisableShowingMainViewOnActivation();
}

inline Windows::Foundation::IAsyncOperation<bool> ApplicationViewSwitcher::TryShowAsStandaloneAsync(int32_t viewId)
{
    return get_activation_factory<ApplicationViewSwitcher, IApplicationViewSwitcherStatics>().TryShowAsStandaloneAsync(viewId);
}

inline Windows::Foundation::IAsyncOperation<bool> ApplicationViewSwitcher::TryShowAsStandaloneAsync(int32_t viewId, Windows::UI::ViewManagement::ViewSizePreference sizePreference)
{
    return get_activation_factory<ApplicationViewSwitcher, IApplicationViewSwitcherStatics>().TryShowAsStandaloneAsync(viewId, sizePreference);
}

inline Windows::Foundation::IAsyncOperation<bool> ApplicationViewSwitcher::TryShowAsStandaloneAsync(int32_t viewId, Windows::UI::ViewManagement::ViewSizePreference sizePreference, int32_t anchorViewId, Windows::UI::ViewManagement::ViewSizePreference anchorSizePreference)
{
    return get_activation_factory<ApplicationViewSwitcher, IApplicationViewSwitcherStatics>().TryShowAsStandaloneAsync(viewId, sizePreference, anchorViewId, anchorSizePreference);
}

inline Windows::Foundation::IAsyncAction ApplicationViewSwitcher::SwitchAsync(int32_t viewId)
{
    return get_activation_factory<ApplicationViewSwitcher, IApplicationViewSwitcherStatics>().SwitchAsync(viewId);
}

inline Windows::Foundation::IAsyncAction ApplicationViewSwitcher::SwitchAsync(int32_t toViewId, int32_t fromViewId)
{
    return get_activation_factory<ApplicationViewSwitcher, IApplicationViewSwitcherStatics>().SwitchAsync(toViewId, fromViewId);
}

inline Windows::Foundation::IAsyncAction ApplicationViewSwitcher::SwitchAsync(int32_t toViewId, int32_t fromViewId, Windows::UI::ViewManagement::ApplicationViewSwitchingOptions options)
{
    return get_activation_factory<ApplicationViewSwitcher, IApplicationViewSwitcherStatics>().SwitchAsync(toViewId, fromViewId, options);
}

inline Windows::Foundation::IAsyncOperation<bool> ApplicationViewSwitcher::PrepareForCustomAnimatedSwitchAsync(int32_t toViewId, int32_t fromViewId, Windows::UI::ViewManagement::ApplicationViewSwitchingOptions options)
{
    return get_activation_factory<ApplicationViewSwitcher, IApplicationViewSwitcherStatics>().PrepareForCustomAnimatedSwitchAsync(toViewId, fromViewId, options);
}

inline void ApplicationViewSwitcher::DisableSystemViewActivationPolicy()
{
    get_activation_factory<ApplicationViewSwitcher, IApplicationViewSwitcherStatics2>().DisableSystemViewActivationPolicy();
}

inline ApplicationViewTransferContext::ApplicationViewTransferContext() :
    ApplicationViewTransferContext(activate_instance<ApplicationViewTransferContext>())
{}

inline hstring ApplicationViewTransferContext::DataPackageFormatId()
{
    return get_activation_factory<ApplicationViewTransferContext, IApplicationViewTransferContextStatics>().DataPackageFormatId();
}

inline Windows::UI::ViewManagement::InputPane InputPane::GetForCurrentView()
{
    return get_activation_factory<InputPane, IInputPaneStatics>().GetForCurrentView();
}

inline Windows::Foundation::IAsyncAction ProjectionManager::StartProjectingAsync(int32_t projectionViewId, int32_t anchorViewId)
{
    return get_activation_factory<ProjectionManager, IProjectionManagerStatics>().StartProjectingAsync(projectionViewId, anchorViewId);
}

inline Windows::Foundation::IAsyncAction ProjectionManager::SwapDisplaysForViewsAsync(int32_t projectionViewId, int32_t anchorViewId)
{
    return get_activation_factory<ProjectionManager, IProjectionManagerStatics>().SwapDisplaysForViewsAsync(projectionViewId, anchorViewId);
}

inline Windows::Foundation::IAsyncAction ProjectionManager::StopProjectingAsync(int32_t projectionViewId, int32_t anchorViewId)
{
    return get_activation_factory<ProjectionManager, IProjectionManagerStatics>().StopProjectingAsync(projectionViewId, anchorViewId);
}

inline bool ProjectionManager::ProjectionDisplayAvailable()
{
    return get_activation_factory<ProjectionManager, IProjectionManagerStatics>().ProjectionDisplayAvailable();
}

inline event_token ProjectionManager::ProjectionDisplayAvailableChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    return get_activation_factory<ProjectionManager, IProjectionManagerStatics>().ProjectionDisplayAvailableChanged(handler);
}

inline factory_event_revoker<IProjectionManagerStatics> ProjectionManager::ProjectionDisplayAvailableChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler)
{
    auto factory = get_activation_factory<ProjectionManager, IProjectionManagerStatics>();
    return { factory, &ABI::Windows::UI::ViewManagement::IProjectionManagerStatics::remove_ProjectionDisplayAvailableChanged, factory.ProjectionDisplayAvailableChanged(handler) };
}

inline void ProjectionManager::ProjectionDisplayAvailableChanged(event_token token)
{
    get_activation_factory<ProjectionManager, IProjectionManagerStatics>().ProjectionDisplayAvailableChanged(token);
}

inline Windows::Foundation::IAsyncAction ProjectionManager::StartProjectingAsync(int32_t projectionViewId, int32_t anchorViewId, const Windows::Devices::Enumeration::DeviceInformation & displayDeviceInfo)
{
    return get_activation_factory<ProjectionManager, IProjectionManagerStatics2>().StartProjectingAsync(projectionViewId, anchorViewId, displayDeviceInfo);
}

inline Windows::Foundation::IAsyncOperation<bool> ProjectionManager::RequestStartProjectingAsync(int32_t projectionViewId, int32_t anchorViewId, const Windows::Foundation::Rect & selection)
{
    return get_activation_factory<ProjectionManager, IProjectionManagerStatics2>().RequestStartProjectingAsync(projectionViewId, anchorViewId, selection);
}

inline Windows::Foundation::IAsyncOperation<bool> ProjectionManager::RequestStartProjectingAsync(int32_t projectionViewId, int32_t anchorViewId, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement prefferedPlacement)
{
    return get_activation_factory<ProjectionManager, IProjectionManagerStatics2>().RequestStartProjectingAsync(projectionViewId, anchorViewId, selection, prefferedPlacement);
}

inline hstring ProjectionManager::GetDeviceSelector()
{
    return get_activation_factory<ProjectionManager, IProjectionManagerStatics2>().GetDeviceSelector();
}

inline Windows::UI::ViewManagement::StatusBar StatusBar::GetForCurrentView()
{
    return get_activation_factory<StatusBar, IStatusBarStatics>().GetForCurrentView();
}

inline UISettings::UISettings() :
    UISettings(activate_instance<UISettings>())
{}

inline Windows::UI::ViewManagement::UIViewSettings UIViewSettings::GetForCurrentView()
{
    return get_activation_factory<UIViewSettings, IUIViewSettingsStatics>().GetForCurrentView();
}

}

}
#pragma warning(pop)
