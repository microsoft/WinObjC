// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.ViewManagement.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::ViewManagement {

struct WINRT_EBO AccessibilitySettings :
    Windows::UI::ViewManagement::IAccessibilitySettings
{
    AccessibilitySettings(std::nullptr_t) noexcept {}
    AccessibilitySettings();
};

struct WINRT_EBO ActivationViewSwitcher :
    Windows::UI::ViewManagement::IActivationViewSwitcher
{
    ActivationViewSwitcher(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ApplicationView :
    Windows::UI::ViewManagement::IApplicationView,
    impl::require<ApplicationView, Windows::UI::ViewManagement::IApplicationView2, Windows::UI::ViewManagement::IApplicationView3>
{
    ApplicationView(std::nullptr_t) noexcept {}
    [[deprecated("IApplicationViewFullscreenStatics is deprecated after Windows 8. Please use other resize APIs.")]] static bool TryUnsnapToFullscreen();
    static int32_t GetApplicationViewIdForWindow(const Windows::UI::Core::ICoreWindow & window);
    [[deprecated("Value may be altered or unavailable for releases after Windows 8.1. Instead, query for window layout sizes directly.")]] static Windows::UI::ViewManagement::ApplicationViewState Value();
    [[deprecated("TryUnsnap may be altered or unavailable for releases after Windows 8.1. Apps can be continuously resized, but cannot be snapped, starting in Windows 8.1.")]] static bool TryUnsnap();
    static Windows::UI::ViewManagement::ApplicationView GetForCurrentView();
    static bool TerminateAppOnFinalViewClose();
    static void TerminateAppOnFinalViewClose(bool value);
    static Windows::UI::ViewManagement::ApplicationViewWindowingMode PreferredLaunchWindowingMode();
    static void PreferredLaunchWindowingMode(Windows::UI::ViewManagement::ApplicationViewWindowingMode value);
    static Windows::Foundation::Size PreferredLaunchViewSize();
    static void PreferredLaunchViewSize(const Windows::Foundation::Size & value);
};

struct WINRT_EBO ApplicationViewConsolidatedEventArgs :
    Windows::UI::ViewManagement::IApplicationViewConsolidatedEventArgs
{
    ApplicationViewConsolidatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ApplicationViewScaling :
    Windows::UI::ViewManagement::IApplicationViewScaling
{
    ApplicationViewScaling(std::nullptr_t) noexcept {}
    static bool DisableLayoutScaling();
    static bool TrySetDisableLayoutScaling(bool disableLayoutScaling);
};

struct ApplicationViewSwitcher
{
    ApplicationViewSwitcher() = delete;
    static void DisableShowingMainViewOnActivation();
    static Windows::Foundation::IAsyncOperation<bool> TryShowAsStandaloneAsync(int32_t viewId);
    static Windows::Foundation::IAsyncOperation<bool> TryShowAsStandaloneAsync(int32_t viewId, Windows::UI::ViewManagement::ViewSizePreference sizePreference);
    static Windows::Foundation::IAsyncOperation<bool> TryShowAsStandaloneAsync(int32_t viewId, Windows::UI::ViewManagement::ViewSizePreference sizePreference, int32_t anchorViewId, Windows::UI::ViewManagement::ViewSizePreference anchorSizePreference);
    static Windows::Foundation::IAsyncAction SwitchAsync(int32_t viewId);
    static Windows::Foundation::IAsyncAction SwitchAsync(int32_t toViewId, int32_t fromViewId);
    static Windows::Foundation::IAsyncAction SwitchAsync(int32_t toViewId, int32_t fromViewId, Windows::UI::ViewManagement::ApplicationViewSwitchingOptions options);
    static Windows::Foundation::IAsyncOperation<bool> PrepareForCustomAnimatedSwitchAsync(int32_t toViewId, int32_t fromViewId, Windows::UI::ViewManagement::ApplicationViewSwitchingOptions options);
    static void DisableSystemViewActivationPolicy();
};

struct WINRT_EBO ApplicationViewTitleBar :
    Windows::UI::ViewManagement::IApplicationViewTitleBar
{
    ApplicationViewTitleBar(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ApplicationViewTransferContext :
    Windows::UI::ViewManagement::IApplicationViewTransferContext
{
    ApplicationViewTransferContext(std::nullptr_t) noexcept {}
    ApplicationViewTransferContext();
    static hstring DataPackageFormatId();
};

struct WINRT_EBO InputPane :
    Windows::UI::ViewManagement::IInputPane,
    impl::require<InputPane, Windows::UI::ViewManagement::IInputPane2, Windows::UI::ViewManagement::IInputPaneControl>
{
    InputPane(std::nullptr_t) noexcept {}
    static Windows::UI::ViewManagement::InputPane GetForCurrentView();
};

struct WINRT_EBO InputPaneVisibilityEventArgs :
    Windows::UI::ViewManagement::IInputPaneVisibilityEventArgs
{
    InputPaneVisibilityEventArgs(std::nullptr_t) noexcept {}
};

struct ProjectionManager
{
    ProjectionManager() = delete;
    static Windows::Foundation::IAsyncAction StartProjectingAsync(int32_t projectionViewId, int32_t anchorViewId);
    static Windows::Foundation::IAsyncAction SwapDisplaysForViewsAsync(int32_t projectionViewId, int32_t anchorViewId);
    static Windows::Foundation::IAsyncAction StopProjectingAsync(int32_t projectionViewId, int32_t anchorViewId);
    static bool ProjectionDisplayAvailable();
    static event_token ProjectionDisplayAvailableChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    using ProjectionDisplayAvailableChanged_revoker = factory_event_revoker<IProjectionManagerStatics>;
    static ProjectionDisplayAvailableChanged_revoker ProjectionDisplayAvailableChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    static void ProjectionDisplayAvailableChanged(event_token token);
    static Windows::Foundation::IAsyncAction StartProjectingAsync(int32_t projectionViewId, int32_t anchorViewId, const Windows::Devices::Enumeration::DeviceInformation & displayDeviceInfo);
    static Windows::Foundation::IAsyncOperation<bool> RequestStartProjectingAsync(int32_t projectionViewId, int32_t anchorViewId, const Windows::Foundation::Rect & selection);
    static Windows::Foundation::IAsyncOperation<bool> RequestStartProjectingAsync(int32_t projectionViewId, int32_t anchorViewId, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement prefferedPlacement);
    static hstring GetDeviceSelector();
};

struct WINRT_EBO StatusBar :
    Windows::UI::ViewManagement::IStatusBar
{
    StatusBar(std::nullptr_t) noexcept {}
    static Windows::UI::ViewManagement::StatusBar GetForCurrentView();
};

struct WINRT_EBO StatusBarProgressIndicator :
    Windows::UI::ViewManagement::IStatusBarProgressIndicator
{
    StatusBarProgressIndicator(std::nullptr_t) noexcept {}
};

struct WINRT_EBO UISettings :
    Windows::UI::ViewManagement::IUISettings,
    impl::require<UISettings, Windows::UI::ViewManagement::IUISettings2, Windows::UI::ViewManagement::IUISettings3>
{
    UISettings(std::nullptr_t) noexcept {}
    UISettings();
};

struct WINRT_EBO UIViewSettings :
    Windows::UI::ViewManagement::IUIViewSettings
{
    UIViewSettings(std::nullptr_t) noexcept {}
    static Windows::UI::ViewManagement::UIViewSettings GetForCurrentView();
};

}

}
