// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::ViewManagement {

struct IAccessibilitySettings;
struct IActivationViewSwitcher;
struct IApplicationView;
struct IApplicationView2;
struct IApplicationView3;
struct IApplicationViewConsolidatedEventArgs;
struct IApplicationViewFullscreenStatics;
struct IApplicationViewInteropStatics;
struct IApplicationViewScaling;
struct IApplicationViewScalingStatics;
struct IApplicationViewStatics;
struct IApplicationViewStatics2;
struct IApplicationViewStatics3;
struct IApplicationViewSwitcherStatics;
struct IApplicationViewSwitcherStatics2;
struct IApplicationViewTitleBar;
struct IApplicationViewTransferContext;
struct IApplicationViewTransferContextStatics;
struct IInputPane;
struct IInputPane2;
struct IInputPaneControl;
struct IInputPaneStatics;
struct IInputPaneVisibilityEventArgs;
struct IProjectionManagerStatics;
struct IProjectionManagerStatics2;
struct IStatusBar;
struct IStatusBarProgressIndicator;
struct IStatusBarStatics;
struct IUISettings;
struct IUISettings2;
struct IUISettings3;
struct IUIViewSettings;
struct IUIViewSettingsStatics;
struct AccessibilitySettings;
struct ActivationViewSwitcher;
struct ApplicationView;
struct ApplicationViewConsolidatedEventArgs;
struct ApplicationViewScaling;
struct ApplicationViewTitleBar;
struct ApplicationViewTransferContext;
struct InputPane;
struct InputPaneVisibilityEventArgs;
struct StatusBar;
struct StatusBarProgressIndicator;
struct UISettings;
struct UIViewSettings;

}

namespace Windows::UI::ViewManagement {

struct IAccessibilitySettings;
struct IActivationViewSwitcher;
struct IApplicationView;
struct IApplicationView2;
struct IApplicationView3;
struct IApplicationViewConsolidatedEventArgs;
struct IApplicationViewFullscreenStatics;
struct IApplicationViewInteropStatics;
struct IApplicationViewScaling;
struct IApplicationViewScalingStatics;
struct IApplicationViewStatics;
struct IApplicationViewStatics2;
struct IApplicationViewStatics3;
struct IApplicationViewSwitcherStatics;
struct IApplicationViewSwitcherStatics2;
struct IApplicationViewTitleBar;
struct IApplicationViewTransferContext;
struct IApplicationViewTransferContextStatics;
struct IInputPane;
struct IInputPane2;
struct IInputPaneControl;
struct IInputPaneStatics;
struct IInputPaneVisibilityEventArgs;
struct IProjectionManagerStatics;
struct IProjectionManagerStatics2;
struct IStatusBar;
struct IStatusBarProgressIndicator;
struct IStatusBarStatics;
struct IUISettings;
struct IUISettings2;
struct IUISettings3;
struct IUIViewSettings;
struct IUIViewSettingsStatics;
struct AccessibilitySettings;
struct ActivationViewSwitcher;
struct ApplicationView;
struct ApplicationViewConsolidatedEventArgs;
struct ApplicationViewScaling;
struct ApplicationViewSwitcher;
struct ApplicationViewTitleBar;
struct ApplicationViewTransferContext;
struct InputPane;
struct InputPaneVisibilityEventArgs;
struct ProjectionManager;
struct StatusBar;
struct StatusBarProgressIndicator;
struct UISettings;
struct UIViewSettings;

}

namespace Windows::UI::ViewManagement {

template <typename T> struct impl_IAccessibilitySettings;
template <typename T> struct impl_IActivationViewSwitcher;
template <typename T> struct impl_IApplicationView;
template <typename T> struct impl_IApplicationView2;
template <typename T> struct impl_IApplicationView3;
template <typename T> struct impl_IApplicationViewConsolidatedEventArgs;
template <typename T> struct impl_IApplicationViewFullscreenStatics;
template <typename T> struct impl_IApplicationViewInteropStatics;
template <typename T> struct impl_IApplicationViewScaling;
template <typename T> struct impl_IApplicationViewScalingStatics;
template <typename T> struct impl_IApplicationViewStatics;
template <typename T> struct impl_IApplicationViewStatics2;
template <typename T> struct impl_IApplicationViewStatics3;
template <typename T> struct impl_IApplicationViewSwitcherStatics;
template <typename T> struct impl_IApplicationViewSwitcherStatics2;
template <typename T> struct impl_IApplicationViewTitleBar;
template <typename T> struct impl_IApplicationViewTransferContext;
template <typename T> struct impl_IApplicationViewTransferContextStatics;
template <typename T> struct impl_IInputPane;
template <typename T> struct impl_IInputPane2;
template <typename T> struct impl_IInputPaneControl;
template <typename T> struct impl_IInputPaneStatics;
template <typename T> struct impl_IInputPaneVisibilityEventArgs;
template <typename T> struct impl_IProjectionManagerStatics;
template <typename T> struct impl_IProjectionManagerStatics2;
template <typename T> struct impl_IStatusBar;
template <typename T> struct impl_IStatusBarProgressIndicator;
template <typename T> struct impl_IStatusBarStatics;
template <typename T> struct impl_IUISettings;
template <typename T> struct impl_IUISettings2;
template <typename T> struct impl_IUISettings3;
template <typename T> struct impl_IUIViewSettings;
template <typename T> struct impl_IUIViewSettingsStatics;

}

namespace Windows::UI::ViewManagement {

enum class ApplicationViewBoundsMode
{
    UseVisible = 0,
    UseCoreWindow = 1,
};

enum class ApplicationViewOrientation
{
    Landscape = 0,
    Portrait = 1,
};

enum class [[deprecated("ApplicationViewState may be altered or unavailable for releases after Windows 8.1. Instead, query for window layout sizes directly.")]] ApplicationViewState
{
    FullScreenLandscape = 0,
    Filled = 1,
    Snapped = 2,
    FullScreenPortrait = 3,
};

enum class ApplicationViewSwitchingOptions : unsigned
{
    Default = 0x0,
    SkipAnimation = 0x1,
    ConsolidateViews = 0x2,
};

DEFINE_ENUM_FLAG_OPERATORS(ApplicationViewSwitchingOptions)

enum class ApplicationViewWindowingMode
{
    Auto = 0,
    PreferredLaunchViewSize = 1,
    FullScreen = 2,
};

enum class FullScreenSystemOverlayMode
{
    Standard = 0,
    Minimal = 1,
};

enum class HandPreference
{
    LeftHanded = 0,
    RightHanded = 1,
};

enum class UIColorType
{
    Background = 0,
    Foreground = 1,
    AccentDark3 = 2,
    AccentDark2 = 3,
    AccentDark1 = 4,
    Accent = 5,
    AccentLight1 = 6,
    AccentLight2 = 7,
    AccentLight3 = 8,
    Complement = 9,
};

enum class UIElementType
{
    ActiveCaption = 0,
    Background = 1,
    ButtonFace = 2,
    ButtonText = 3,
    CaptionText = 4,
    GrayText = 5,
    Highlight = 6,
    HighlightText = 7,
    Hotlight = 8,
    InactiveCaption = 9,
    InactiveCaptionText = 10,
    Window = 11,
    WindowText = 12,
};

enum class UserInteractionMode
{
    Mouse = 0,
    Touch = 1,
};

enum class ViewSizePreference
{
    Default = 0,
    UseLess = 1,
    UseHalf = 2,
    UseMore = 3,
    UseMinimum = 4,
    UseNone = 5,
};

}

}
