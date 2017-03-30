// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.UI.ViewManagement.0.h"
#include "Windows.Devices.Enumeration.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.UI.0.h"
#include "Windows.UI.Core.0.h"
#include "Windows.UI.Popups.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.UI.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::ViewManagement {

struct __declspec(uuid("fe0e8147-c4c0-4562-b962-1327b52ad5b9")) __declspec(novtable) IAccessibilitySettings : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_HighContrast(bool * value) = 0;
    virtual HRESULT __stdcall get_HighContrastScheme(hstring * value) = 0;
    virtual HRESULT __stdcall add_HighContrastChanged(Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::AccessibilitySettings, Windows::Foundation::IInspectable> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_HighContrastChanged(event_token cookie) = 0;
};

struct __declspec(uuid("dca71bb6-7350-492b-aac7-c8a13d7224ad")) __declspec(novtable) IActivationViewSwitcher : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ShowAsStandaloneAsync(int32_t viewId, Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_ShowAsStandaloneWithSizePreferenceAsync(int32_t viewId, winrt::Windows::UI::ViewManagement::ViewSizePreference sizePreference, Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_IsViewPresentedOnActivationVirtualDesktop(int32_t viewId, bool * value) = 0;
};

struct __declspec(uuid("d222d519-4361-451e-96c4-60f4f9742db0")) __declspec(novtable) IApplicationView : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Orientation(winrt::Windows::UI::ViewManagement::ApplicationViewOrientation * value) = 0;
    virtual HRESULT __stdcall get_AdjacentToLeftDisplayEdge(bool * value) = 0;
    virtual HRESULT __stdcall get_AdjacentToRightDisplayEdge(bool * value) = 0;
    virtual HRESULT __stdcall get_IsFullScreen(bool * value) = 0;
    virtual HRESULT __stdcall get_IsOnLockScreen(bool * value) = 0;
    virtual HRESULT __stdcall get_IsScreenCaptureEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsScreenCaptureEnabled(bool value) = 0;
    virtual HRESULT __stdcall put_Title(hstring value) = 0;
    virtual HRESULT __stdcall get_Title(hstring * value) = 0;
    virtual HRESULT __stdcall get_Id(int32_t * value) = 0;
    virtual HRESULT __stdcall add_Consolidated(Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::ApplicationView, Windows::UI::ViewManagement::ApplicationViewConsolidatedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Consolidated(event_token token) = 0;
};

struct __declspec(uuid("e876b196-a545-40dc-b594-450cba68cc00")) __declspec(novtable) IApplicationView2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SuppressSystemOverlays(bool * value) = 0;
    virtual HRESULT __stdcall put_SuppressSystemOverlays(bool value) = 0;
    virtual HRESULT __stdcall get_VisibleBounds(Windows::Foundation::Rect * value) = 0;
    virtual HRESULT __stdcall add_VisibleBoundsChanged(Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::ApplicationView, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_VisibleBoundsChanged(event_token token) = 0;
    virtual HRESULT __stdcall abi_SetDesiredBoundsMode(winrt::Windows::UI::ViewManagement::ApplicationViewBoundsMode boundsMode, bool * success) = 0;
    virtual HRESULT __stdcall get_DesiredBoundsMode(winrt::Windows::UI::ViewManagement::ApplicationViewBoundsMode * value) = 0;
};

struct __declspec(uuid("903c9ce5-793a-4fdf-a2b2-af1ac21e3108")) __declspec(novtable) IApplicationView3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TitleBar(Windows::UI::ViewManagement::IApplicationViewTitleBar ** value) = 0;
    virtual HRESULT __stdcall get_FullScreenSystemOverlayMode(winrt::Windows::UI::ViewManagement::FullScreenSystemOverlayMode * value) = 0;
    virtual HRESULT __stdcall put_FullScreenSystemOverlayMode(winrt::Windows::UI::ViewManagement::FullScreenSystemOverlayMode value) = 0;
    virtual HRESULT __stdcall get_IsFullScreenMode(bool * value) = 0;
    virtual HRESULT __stdcall abi_TryEnterFullScreenMode(bool * success) = 0;
    virtual HRESULT __stdcall abi_ExitFullScreenMode() = 0;
    virtual HRESULT __stdcall abi_ShowStandardSystemOverlays() = 0;
    virtual HRESULT __stdcall abi_TryResizeView(Windows::Foundation::Size value, bool * success) = 0;
    virtual HRESULT __stdcall abi_SetPreferredMinSize(Windows::Foundation::Size minSize) = 0;
};

struct __declspec(uuid("514449ec-7ea2-4de7-a6a6-7dfbaaebb6fb")) __declspec(novtable) IApplicationViewConsolidatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsUserInitiated(bool * value) = 0;
};

struct __declspec(uuid("bc792ebd-64fe-4b65-a0c0-901ce2b68636")) __declspec(novtable) IApplicationViewFullscreenStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_TryUnsnapToFullscreen(bool * success) = 0;
};

struct __declspec(uuid("c446fb5d-4793-4896-a8e2-be57a8bb0f50")) __declspec(novtable) IApplicationViewInteropStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetApplicationViewIdForWindow(Windows::UI::Core::ICoreWindow * window, int32_t * id) = 0;
};

struct __declspec(uuid("1d0ddc23-23f3-4b2d-84fe-74bf37b48b66")) __declspec(novtable) IApplicationViewScaling : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("b08fecf0-b946-45c8-a5e3-71f5aa78f861")) __declspec(novtable) IApplicationViewScalingStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DisableLayoutScaling(bool * value) = 0;
    virtual HRESULT __stdcall abi_TrySetDisableLayoutScaling(bool disableLayoutScaling, bool * success) = 0;
};

struct __declspec(uuid("010a6306-c433-44e5-a9f2-bd84d4030a95")) __declspec(novtable) IApplicationViewStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Value(winrt::Windows::UI::ViewManagement::ApplicationViewState * value) = 0;
    virtual HRESULT __stdcall abi_TryUnsnap(bool * success) = 0;
};

struct __declspec(uuid("af338ae5-cf64-423c-85e5-f3e72448fb23")) __declspec(novtable) IApplicationViewStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetForCurrentView(Windows::UI::ViewManagement::IApplicationView ** current) = 0;
    virtual HRESULT __stdcall get_TerminateAppOnFinalViewClose(bool * value) = 0;
    virtual HRESULT __stdcall put_TerminateAppOnFinalViewClose(bool value) = 0;
};

struct __declspec(uuid("a28d7594-8c41-4e13-9719-5164796fe4c7")) __declspec(novtable) IApplicationViewStatics3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PreferredLaunchWindowingMode(winrt::Windows::UI::ViewManagement::ApplicationViewWindowingMode * value) = 0;
    virtual HRESULT __stdcall put_PreferredLaunchWindowingMode(winrt::Windows::UI::ViewManagement::ApplicationViewWindowingMode value) = 0;
    virtual HRESULT __stdcall get_PreferredLaunchViewSize(Windows::Foundation::Size * value) = 0;
    virtual HRESULT __stdcall put_PreferredLaunchViewSize(Windows::Foundation::Size value) = 0;
};

struct __declspec(uuid("975f2f1e-e656-4c5e-a0a1-717c6ffa7d64")) __declspec(novtable) IApplicationViewSwitcherStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_DisableShowingMainViewOnActivation() = 0;
    virtual HRESULT __stdcall abi_TryShowAsStandaloneAsync(int32_t viewId, Windows::Foundation::IAsyncOperation<bool> ** operation) = 0;
    virtual HRESULT __stdcall abi_TryShowAsStandaloneWithSizePreferenceAsync(int32_t viewId, winrt::Windows::UI::ViewManagement::ViewSizePreference sizePreference, Windows::Foundation::IAsyncOperation<bool> ** operation) = 0;
    virtual HRESULT __stdcall abi_TryShowAsStandaloneWithAnchorViewAndSizePreferenceAsync(int32_t viewId, winrt::Windows::UI::ViewManagement::ViewSizePreference sizePreference, int32_t anchorViewId, winrt::Windows::UI::ViewManagement::ViewSizePreference anchorSizePreference, Windows::Foundation::IAsyncOperation<bool> ** operation) = 0;
    virtual HRESULT __stdcall abi_SwitchAsync(int32_t viewId, Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_SwitchFromViewAsync(int32_t toViewId, int32_t fromViewId, Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_SwitchFromViewWithOptionsAsync(int32_t toViewId, int32_t fromViewId, winrt::Windows::UI::ViewManagement::ApplicationViewSwitchingOptions options, Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_PrepareForCustomAnimatedSwitchAsync(int32_t toViewId, int32_t fromViewId, winrt::Windows::UI::ViewManagement::ApplicationViewSwitchingOptions options, Windows::Foundation::IAsyncOperation<bool> ** operation) = 0;
};

struct __declspec(uuid("60e995cd-4fc2-48c4-b8e3-395f2b9f0fc1")) __declspec(novtable) IApplicationViewSwitcherStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_DisableSystemViewActivationPolicy() = 0;
};

struct __declspec(uuid("00924ac0-932b-4a6b-9c4b-dc38c82478ce")) __declspec(novtable) IApplicationViewTitleBar : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_ForegroundColor(Windows::Foundation::IReference<Windows::UI::Color> * value) = 0;
    virtual HRESULT __stdcall get_ForegroundColor(Windows::Foundation::IReference<Windows::UI::Color> ** value) = 0;
    virtual HRESULT __stdcall put_BackgroundColor(Windows::Foundation::IReference<Windows::UI::Color> * value) = 0;
    virtual HRESULT __stdcall get_BackgroundColor(Windows::Foundation::IReference<Windows::UI::Color> ** value) = 0;
    virtual HRESULT __stdcall put_ButtonForegroundColor(Windows::Foundation::IReference<Windows::UI::Color> * value) = 0;
    virtual HRESULT __stdcall get_ButtonForegroundColor(Windows::Foundation::IReference<Windows::UI::Color> ** value) = 0;
    virtual HRESULT __stdcall put_ButtonBackgroundColor(Windows::Foundation::IReference<Windows::UI::Color> * value) = 0;
    virtual HRESULT __stdcall get_ButtonBackgroundColor(Windows::Foundation::IReference<Windows::UI::Color> ** value) = 0;
    virtual HRESULT __stdcall put_ButtonHoverForegroundColor(Windows::Foundation::IReference<Windows::UI::Color> * value) = 0;
    virtual HRESULT __stdcall get_ButtonHoverForegroundColor(Windows::Foundation::IReference<Windows::UI::Color> ** value) = 0;
    virtual HRESULT __stdcall put_ButtonHoverBackgroundColor(Windows::Foundation::IReference<Windows::UI::Color> * value) = 0;
    virtual HRESULT __stdcall get_ButtonHoverBackgroundColor(Windows::Foundation::IReference<Windows::UI::Color> ** value) = 0;
    virtual HRESULT __stdcall put_ButtonPressedForegroundColor(Windows::Foundation::IReference<Windows::UI::Color> * value) = 0;
    virtual HRESULT __stdcall get_ButtonPressedForegroundColor(Windows::Foundation::IReference<Windows::UI::Color> ** value) = 0;
    virtual HRESULT __stdcall put_ButtonPressedBackgroundColor(Windows::Foundation::IReference<Windows::UI::Color> * value) = 0;
    virtual HRESULT __stdcall get_ButtonPressedBackgroundColor(Windows::Foundation::IReference<Windows::UI::Color> ** value) = 0;
    virtual HRESULT __stdcall put_InactiveForegroundColor(Windows::Foundation::IReference<Windows::UI::Color> * value) = 0;
    virtual HRESULT __stdcall get_InactiveForegroundColor(Windows::Foundation::IReference<Windows::UI::Color> ** value) = 0;
    virtual HRESULT __stdcall put_InactiveBackgroundColor(Windows::Foundation::IReference<Windows::UI::Color> * value) = 0;
    virtual HRESULT __stdcall get_InactiveBackgroundColor(Windows::Foundation::IReference<Windows::UI::Color> ** value) = 0;
    virtual HRESULT __stdcall put_ButtonInactiveForegroundColor(Windows::Foundation::IReference<Windows::UI::Color> * value) = 0;
    virtual HRESULT __stdcall get_ButtonInactiveForegroundColor(Windows::Foundation::IReference<Windows::UI::Color> ** value) = 0;
    virtual HRESULT __stdcall put_ButtonInactiveBackgroundColor(Windows::Foundation::IReference<Windows::UI::Color> * value) = 0;
    virtual HRESULT __stdcall get_ButtonInactiveBackgroundColor(Windows::Foundation::IReference<Windows::UI::Color> ** value) = 0;
};

struct __declspec(uuid("8574bc63-3c17-408e-9408-8a1a9ea81bfa")) __declspec(novtable) IApplicationViewTransferContext : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ViewId(int32_t * value) = 0;
    virtual HRESULT __stdcall put_ViewId(int32_t value) = 0;
};

struct __declspec(uuid("15a89d92-dd79-4b0b-bc47-d5f195f14661")) __declspec(novtable) IApplicationViewTransferContextStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DataPackageFormatId(hstring * value) = 0;
};

struct __declspec(uuid("640ada70-06f3-4c87-a678-9829c9127c28")) __declspec(novtable) IInputPane : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_Showing(Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::InputPane, Windows::UI::ViewManagement::InputPaneVisibilityEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Showing(event_token token) = 0;
    virtual HRESULT __stdcall add_Hiding(Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::InputPane, Windows::UI::ViewManagement::InputPaneVisibilityEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Hiding(event_token token) = 0;
    virtual HRESULT __stdcall get_OccludedRect(Windows::Foundation::Rect * value) = 0;
};

struct __declspec(uuid("8a6b3f26-7090-4793-944c-c3f2cde26276")) __declspec(novtable) IInputPane2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_TryShow(bool * result) = 0;
    virtual HRESULT __stdcall abi_TryHide(bool * result) = 0;
};

struct __declspec(uuid("088bb24f-962f-489d-aa6e-c6be1a0a6e52")) __declspec(novtable) IInputPaneControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Visible(bool * value) = 0;
    virtual HRESULT __stdcall put_Visible(bool value) = 0;
};

struct __declspec(uuid("95f4af3a-ef47-424a-9741-fd2815eba2bd")) __declspec(novtable) IInputPaneStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetForCurrentView(Windows::UI::ViewManagement::IInputPane ** inputPane) = 0;
};

struct __declspec(uuid("d243e016-d907-4fcc-bb8d-f77baa5028f1")) __declspec(novtable) IInputPaneVisibilityEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_OccludedRect(Windows::Foundation::Rect * value) = 0;
    virtual HRESULT __stdcall put_EnsuredFocusedElementInView(bool value) = 0;
    virtual HRESULT __stdcall get_EnsuredFocusedElementInView(bool * value) = 0;
};

struct __declspec(uuid("b65f913d-e2f0-4ffd-ba95-34241647e45c")) __declspec(novtable) IProjectionManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_StartProjectingAsync(int32_t projectionViewId, int32_t anchorViewId, Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_SwapDisplaysForViewsAsync(int32_t projectionViewId, int32_t anchorViewId, Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_StopProjectingAsync(int32_t projectionViewId, int32_t anchorViewId, Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall get_ProjectionDisplayAvailable(bool * value) = 0;
    virtual HRESULT __stdcall add_ProjectionDisplayAvailableChanged(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ProjectionDisplayAvailableChanged(event_token token) = 0;
};

struct __declspec(uuid("f33d2f43-2749-4cde-b977-c0c41e7415d1")) __declspec(novtable) IProjectionManagerStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_StartProjectingWithDeviceInfoAsync(int32_t projectionViewId, int32_t anchorViewId, Windows::Devices::Enumeration::IDeviceInformation * displayDeviceInfo, Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_RequestStartProjectingAsync(int32_t projectionViewId, int32_t anchorViewId, Windows::Foundation::Rect selection, Windows::Foundation::IAsyncOperation<bool> ** operation) = 0;
    virtual HRESULT __stdcall abi_RequestStartProjectingWithPlacementAsync(int32_t projectionViewId, int32_t anchorViewId, Windows::Foundation::Rect selection, winrt::Windows::UI::Popups::Placement prefferedPlacement, Windows::Foundation::IAsyncOperation<bool> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetDeviceSelector(hstring * selector) = 0;
};

struct __declspec(uuid("0ffcc5bf-98d0-4864-b1e8-b3f4020be8b4")) __declspec(novtable) IStatusBar : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ShowAsync(Windows::Foundation::IAsyncAction ** returnValue) = 0;
    virtual HRESULT __stdcall abi_HideAsync(Windows::Foundation::IAsyncAction ** returnValue) = 0;
    virtual HRESULT __stdcall get_BackgroundOpacity(double * value) = 0;
    virtual HRESULT __stdcall put_BackgroundOpacity(double value) = 0;
    virtual HRESULT __stdcall get_ForegroundColor(Windows::Foundation::IReference<Windows::UI::Color> ** value) = 0;
    virtual HRESULT __stdcall put_ForegroundColor(Windows::Foundation::IReference<Windows::UI::Color> * value) = 0;
    virtual HRESULT __stdcall get_BackgroundColor(Windows::Foundation::IReference<Windows::UI::Color> ** value) = 0;
    virtual HRESULT __stdcall put_BackgroundColor(Windows::Foundation::IReference<Windows::UI::Color> * value) = 0;
    virtual HRESULT __stdcall get_ProgressIndicator(Windows::UI::ViewManagement::IStatusBarProgressIndicator ** value) = 0;
    virtual HRESULT __stdcall get_OccludedRect(Windows::Foundation::Rect * value) = 0;
    virtual HRESULT __stdcall add_Showing(Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::StatusBar, Windows::Foundation::IInspectable> * eventHandler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Showing(event_token token) = 0;
    virtual HRESULT __stdcall add_Hiding(Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::StatusBar, Windows::Foundation::IInspectable> * eventHandler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Hiding(event_token token) = 0;
};

struct __declspec(uuid("76cb2670-a3d7-49cf-8200-4f3eedca27bb")) __declspec(novtable) IStatusBarProgressIndicator : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ShowAsync(Windows::Foundation::IAsyncAction ** returnValue) = 0;
    virtual HRESULT __stdcall abi_HideAsync(Windows::Foundation::IAsyncAction ** returnValue) = 0;
    virtual HRESULT __stdcall get_Text(hstring * value) = 0;
    virtual HRESULT __stdcall put_Text(hstring value) = 0;
    virtual HRESULT __stdcall get_ProgressValue(Windows::Foundation::IReference<double> ** value) = 0;
    virtual HRESULT __stdcall put_ProgressValue(Windows::Foundation::IReference<double> * value) = 0;
};

struct __declspec(uuid("8b463fdf-422f-4561-8806-fb1289cadfb7")) __declspec(novtable) IStatusBarStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetForCurrentView(Windows::UI::ViewManagement::IStatusBar ** value) = 0;
};

struct __declspec(uuid("85361600-1c63-4627-bcb1-3a89e0bc9c55")) __declspec(novtable) IUISettings : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_HandPreference(winrt::Windows::UI::ViewManagement::HandPreference * value) = 0;
    virtual HRESULT __stdcall get_CursorSize(Windows::Foundation::Size * value) = 0;
    virtual HRESULT __stdcall get_ScrollBarSize(Windows::Foundation::Size * value) = 0;
    virtual HRESULT __stdcall get_ScrollBarArrowSize(Windows::Foundation::Size * value) = 0;
    virtual HRESULT __stdcall get_ScrollBarThumbBoxSize(Windows::Foundation::Size * value) = 0;
    virtual HRESULT __stdcall get_MessageDuration(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_AnimationsEnabled(bool * value) = 0;
    virtual HRESULT __stdcall get_CaretBrowsingEnabled(bool * value) = 0;
    virtual HRESULT __stdcall get_CaretBlinkRate(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_CaretWidth(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_DoubleClickTime(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_MouseHoverTime(uint32_t * value) = 0;
    virtual HRESULT __stdcall abi_UIElementColor(winrt::Windows::UI::ViewManagement::UIElementType desiredElement, Windows::UI::Color * value) = 0;
};

struct __declspec(uuid("bad82401-2721-44f9-bb91-2bb228be442f")) __declspec(novtable) IUISettings2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TextScaleFactor(double * value) = 0;
    virtual HRESULT __stdcall add_TextScaleFactorChanged(Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::UISettings, Windows::Foundation::IInspectable> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_TextScaleFactorChanged(event_token cookie) = 0;
};

struct __declspec(uuid("03021be4-5254-4781-8194-5168f7d06d7b")) __declspec(novtable) IUISettings3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetColorValue(winrt::Windows::UI::ViewManagement::UIColorType desiredColor, Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall add_ColorValuesChanged(Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::UISettings, Windows::Foundation::IInspectable> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_ColorValuesChanged(event_token cookie) = 0;
};

struct __declspec(uuid("c63657f6-8850-470d-88f8-455e16ea2c26")) __declspec(novtable) IUIViewSettings : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_UserInteractionMode(winrt::Windows::UI::ViewManagement::UserInteractionMode * value) = 0;
};

struct __declspec(uuid("595c97a5-f8f6-41cf-b0fb-aacdb81fd5f6")) __declspec(novtable) IUIViewSettingsStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetForCurrentView(Windows::UI::ViewManagement::IUIViewSettings ** current) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::UI::ViewManagement::AccessibilitySettings> { using default_interface = Windows::UI::ViewManagement::IAccessibilitySettings; };
template <> struct traits<Windows::UI::ViewManagement::ActivationViewSwitcher> { using default_interface = Windows::UI::ViewManagement::IActivationViewSwitcher; };
template <> struct traits<Windows::UI::ViewManagement::ApplicationView> { using default_interface = Windows::UI::ViewManagement::IApplicationView; };
template <> struct traits<Windows::UI::ViewManagement::ApplicationViewConsolidatedEventArgs> { using default_interface = Windows::UI::ViewManagement::IApplicationViewConsolidatedEventArgs; };
template <> struct traits<Windows::UI::ViewManagement::ApplicationViewScaling> { using default_interface = Windows::UI::ViewManagement::IApplicationViewScaling; };
template <> struct traits<Windows::UI::ViewManagement::ApplicationViewTitleBar> { using default_interface = Windows::UI::ViewManagement::IApplicationViewTitleBar; };
template <> struct traits<Windows::UI::ViewManagement::ApplicationViewTransferContext> { using default_interface = Windows::UI::ViewManagement::IApplicationViewTransferContext; };
template <> struct traits<Windows::UI::ViewManagement::InputPane> { using default_interface = Windows::UI::ViewManagement::IInputPane; };
template <> struct traits<Windows::UI::ViewManagement::InputPaneVisibilityEventArgs> { using default_interface = Windows::UI::ViewManagement::IInputPaneVisibilityEventArgs; };
template <> struct traits<Windows::UI::ViewManagement::StatusBar> { using default_interface = Windows::UI::ViewManagement::IStatusBar; };
template <> struct traits<Windows::UI::ViewManagement::StatusBarProgressIndicator> { using default_interface = Windows::UI::ViewManagement::IStatusBarProgressIndicator; };
template <> struct traits<Windows::UI::ViewManagement::UISettings> { using default_interface = Windows::UI::ViewManagement::IUISettings; };
template <> struct traits<Windows::UI::ViewManagement::UIViewSettings> { using default_interface = Windows::UI::ViewManagement::IUIViewSettings; };

}

namespace Windows::UI::ViewManagement {

template <typename D>
struct WINRT_EBO impl_IAccessibilitySettings
{
    bool HighContrast() const;
    hstring HighContrastScheme() const;
    event_token HighContrastChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::AccessibilitySettings, Windows::Foundation::IInspectable> & handler) const;
    using HighContrastChanged_revoker = event_revoker<IAccessibilitySettings>;
    HighContrastChanged_revoker HighContrastChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::AccessibilitySettings, Windows::Foundation::IInspectable> & handler) const;
    void HighContrastChanged(event_token cookie) const;
};

template <typename D>
struct WINRT_EBO impl_IActivationViewSwitcher
{
    Windows::Foundation::IAsyncAction ShowAsStandaloneAsync(int32_t viewId) const;
    Windows::Foundation::IAsyncAction ShowAsStandaloneAsync(int32_t viewId, Windows::UI::ViewManagement::ViewSizePreference sizePreference) const;
    bool IsViewPresentedOnActivationVirtualDesktop(int32_t viewId) const;
};

template <typename D>
struct WINRT_EBO impl_IApplicationView
{
    Windows::UI::ViewManagement::ApplicationViewOrientation Orientation() const;
    bool AdjacentToLeftDisplayEdge() const;
    bool AdjacentToRightDisplayEdge() const;
    [[deprecated("To check full screen mode, use IsFullScreenMode. To check if the view is adjacent to both edges, use AdjacentToLeftDisplayEdge and AdjacentToRightDisplayEdge. For more info, see MSDN.")]] bool IsFullScreen() const;
    bool IsOnLockScreen() const;
    bool IsScreenCaptureEnabled() const;
    void IsScreenCaptureEnabled(bool value) const;
    void Title(hstring_view value) const;
    hstring Title() const;
    int32_t Id() const;
    event_token Consolidated(const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::ApplicationView, Windows::UI::ViewManagement::ApplicationViewConsolidatedEventArgs> & handler) const;
    using Consolidated_revoker = event_revoker<IApplicationView>;
    Consolidated_revoker Consolidated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::ApplicationView, Windows::UI::ViewManagement::ApplicationViewConsolidatedEventArgs> & handler) const;
    void Consolidated(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IApplicationView2
{
    [[deprecated("Use the TryEnterFullScreen method and IsFullScreenMode property instead of SuppressSystemOverlays. For more info, see MSDN.")]] bool SuppressSystemOverlays() const;
    [[deprecated("Use the TryEnterFullScreen method and IsFullScreenMode property instead of SuppressSystemOverlays. For more info, see MSDN.")]] void SuppressSystemOverlays(bool value) const;
    Windows::Foundation::Rect VisibleBounds() const;
    event_token VisibleBoundsChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::ApplicationView, Windows::Foundation::IInspectable> & handler) const;
    using VisibleBoundsChanged_revoker = event_revoker<IApplicationView2>;
    VisibleBoundsChanged_revoker VisibleBoundsChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::ApplicationView, Windows::Foundation::IInspectable> & handler) const;
    void VisibleBoundsChanged(event_token token) const;
    bool SetDesiredBoundsMode(Windows::UI::ViewManagement::ApplicationViewBoundsMode boundsMode) const;
    Windows::UI::ViewManagement::ApplicationViewBoundsMode DesiredBoundsMode() const;
};

template <typename D>
struct WINRT_EBO impl_IApplicationView3
{
    Windows::UI::ViewManagement::ApplicationViewTitleBar TitleBar() const;
    Windows::UI::ViewManagement::FullScreenSystemOverlayMode FullScreenSystemOverlayMode() const;
    void FullScreenSystemOverlayMode(Windows::UI::ViewManagement::FullScreenSystemOverlayMode value) const;
    bool IsFullScreenMode() const;
    bool TryEnterFullScreenMode() const;
    void ExitFullScreenMode() const;
    void ShowStandardSystemOverlays() const;
    bool TryResizeView(const Windows::Foundation::Size & value) const;
    void SetPreferredMinSize(const Windows::Foundation::Size & minSize) const;
};

template <typename D>
struct WINRT_EBO impl_IApplicationViewConsolidatedEventArgs
{
    bool IsUserInitiated() const;
};

template <typename D>
struct WINRT_EBO impl_IApplicationViewFullscreenStatics
{
    [[deprecated("IApplicationViewFullscreenStatics is deprecated after Windows 8. Please use other resize APIs.")]] bool TryUnsnapToFullscreen() const;
};

template <typename D>
struct WINRT_EBO impl_IApplicationViewInteropStatics
{
    int32_t GetApplicationViewIdForWindow(const Windows::UI::Core::ICoreWindow & window) const;
};

template <typename D>
struct WINRT_EBO impl_IApplicationViewScaling
{
};

template <typename D>
struct WINRT_EBO impl_IApplicationViewScalingStatics
{
    bool DisableLayoutScaling() const;
    bool TrySetDisableLayoutScaling(bool disableLayoutScaling) const;
};

template <typename D>
struct WINRT_EBO impl_IApplicationViewStatics
{
    [[deprecated("Value may be altered or unavailable for releases after Windows 8.1. Instead, query for window layout sizes directly.")]] Windows::UI::ViewManagement::ApplicationViewState Value() const;
    [[deprecated("TryUnsnap may be altered or unavailable for releases after Windows 8.1. Apps can be continuously resized, but cannot be snapped, starting in Windows 8.1.")]] bool TryUnsnap() const;
};

template <typename D>
struct WINRT_EBO impl_IApplicationViewStatics2
{
    Windows::UI::ViewManagement::ApplicationView GetForCurrentView() const;
    bool TerminateAppOnFinalViewClose() const;
    void TerminateAppOnFinalViewClose(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IApplicationViewStatics3
{
    Windows::UI::ViewManagement::ApplicationViewWindowingMode PreferredLaunchWindowingMode() const;
    void PreferredLaunchWindowingMode(Windows::UI::ViewManagement::ApplicationViewWindowingMode value) const;
    Windows::Foundation::Size PreferredLaunchViewSize() const;
    void PreferredLaunchViewSize(const Windows::Foundation::Size & value) const;
};

template <typename D>
struct WINRT_EBO impl_IApplicationViewSwitcherStatics
{
    void DisableShowingMainViewOnActivation() const;
    Windows::Foundation::IAsyncOperation<bool> TryShowAsStandaloneAsync(int32_t viewId) const;
    Windows::Foundation::IAsyncOperation<bool> TryShowAsStandaloneAsync(int32_t viewId, Windows::UI::ViewManagement::ViewSizePreference sizePreference) const;
    Windows::Foundation::IAsyncOperation<bool> TryShowAsStandaloneAsync(int32_t viewId, Windows::UI::ViewManagement::ViewSizePreference sizePreference, int32_t anchorViewId, Windows::UI::ViewManagement::ViewSizePreference anchorSizePreference) const;
    Windows::Foundation::IAsyncAction SwitchAsync(int32_t viewId) const;
    Windows::Foundation::IAsyncAction SwitchAsync(int32_t toViewId, int32_t fromViewId) const;
    Windows::Foundation::IAsyncAction SwitchAsync(int32_t toViewId, int32_t fromViewId, Windows::UI::ViewManagement::ApplicationViewSwitchingOptions options) const;
    Windows::Foundation::IAsyncOperation<bool> PrepareForCustomAnimatedSwitchAsync(int32_t toViewId, int32_t fromViewId, Windows::UI::ViewManagement::ApplicationViewSwitchingOptions options) const;
};

template <typename D>
struct WINRT_EBO impl_IApplicationViewSwitcherStatics2
{
    void DisableSystemViewActivationPolicy() const;
};

template <typename D>
struct WINRT_EBO impl_IApplicationViewTitleBar
{
    void ForegroundColor(const optional<Windows::UI::Color> & value) const;
    Windows::Foundation::IReference<Windows::UI::Color> ForegroundColor() const;
    void BackgroundColor(const optional<Windows::UI::Color> & value) const;
    Windows::Foundation::IReference<Windows::UI::Color> BackgroundColor() const;
    void ButtonForegroundColor(const optional<Windows::UI::Color> & value) const;
    Windows::Foundation::IReference<Windows::UI::Color> ButtonForegroundColor() const;
    void ButtonBackgroundColor(const optional<Windows::UI::Color> & value) const;
    Windows::Foundation::IReference<Windows::UI::Color> ButtonBackgroundColor() const;
    void ButtonHoverForegroundColor(const optional<Windows::UI::Color> & value) const;
    Windows::Foundation::IReference<Windows::UI::Color> ButtonHoverForegroundColor() const;
    void ButtonHoverBackgroundColor(const optional<Windows::UI::Color> & value) const;
    Windows::Foundation::IReference<Windows::UI::Color> ButtonHoverBackgroundColor() const;
    void ButtonPressedForegroundColor(const optional<Windows::UI::Color> & value) const;
    Windows::Foundation::IReference<Windows::UI::Color> ButtonPressedForegroundColor() const;
    void ButtonPressedBackgroundColor(const optional<Windows::UI::Color> & value) const;
    Windows::Foundation::IReference<Windows::UI::Color> ButtonPressedBackgroundColor() const;
    void InactiveForegroundColor(const optional<Windows::UI::Color> & value) const;
    Windows::Foundation::IReference<Windows::UI::Color> InactiveForegroundColor() const;
    void InactiveBackgroundColor(const optional<Windows::UI::Color> & value) const;
    Windows::Foundation::IReference<Windows::UI::Color> InactiveBackgroundColor() const;
    void ButtonInactiveForegroundColor(const optional<Windows::UI::Color> & value) const;
    Windows::Foundation::IReference<Windows::UI::Color> ButtonInactiveForegroundColor() const;
    void ButtonInactiveBackgroundColor(const optional<Windows::UI::Color> & value) const;
    Windows::Foundation::IReference<Windows::UI::Color> ButtonInactiveBackgroundColor() const;
};

template <typename D>
struct WINRT_EBO impl_IApplicationViewTransferContext
{
    int32_t ViewId() const;
    void ViewId(int32_t value) const;
};

template <typename D>
struct WINRT_EBO impl_IApplicationViewTransferContextStatics
{
    hstring DataPackageFormatId() const;
};

template <typename D>
struct WINRT_EBO impl_IInputPane
{
    event_token Showing(const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::InputPane, Windows::UI::ViewManagement::InputPaneVisibilityEventArgs> & handler) const;
    using Showing_revoker = event_revoker<IInputPane>;
    Showing_revoker Showing(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::InputPane, Windows::UI::ViewManagement::InputPaneVisibilityEventArgs> & handler) const;
    void Showing(event_token token) const;
    event_token Hiding(const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::InputPane, Windows::UI::ViewManagement::InputPaneVisibilityEventArgs> & handler) const;
    using Hiding_revoker = event_revoker<IInputPane>;
    Hiding_revoker Hiding(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::InputPane, Windows::UI::ViewManagement::InputPaneVisibilityEventArgs> & handler) const;
    void Hiding(event_token token) const;
    Windows::Foundation::Rect OccludedRect() const;
};

template <typename D>
struct WINRT_EBO impl_IInputPane2
{
    bool TryShow() const;
    bool TryHide() const;
};

template <typename D>
struct WINRT_EBO impl_IInputPaneControl
{
    bool Visible() const;
    void Visible(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IInputPaneStatics
{
    Windows::UI::ViewManagement::InputPane GetForCurrentView() const;
};

template <typename D>
struct WINRT_EBO impl_IInputPaneVisibilityEventArgs
{
    Windows::Foundation::Rect OccludedRect() const;
    void EnsuredFocusedElementInView(bool value) const;
    bool EnsuredFocusedElementInView() const;
};

template <typename D>
struct WINRT_EBO impl_IProjectionManagerStatics
{
    Windows::Foundation::IAsyncAction StartProjectingAsync(int32_t projectionViewId, int32_t anchorViewId) const;
    Windows::Foundation::IAsyncAction SwapDisplaysForViewsAsync(int32_t projectionViewId, int32_t anchorViewId) const;
    Windows::Foundation::IAsyncAction StopProjectingAsync(int32_t projectionViewId, int32_t anchorViewId) const;
    bool ProjectionDisplayAvailable() const;
    event_token ProjectionDisplayAvailableChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const;
    using ProjectionDisplayAvailableChanged_revoker = event_revoker<IProjectionManagerStatics>;
    ProjectionDisplayAvailableChanged_revoker ProjectionDisplayAvailableChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler) const;
    void ProjectionDisplayAvailableChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IProjectionManagerStatics2
{
    Windows::Foundation::IAsyncAction StartProjectingAsync(int32_t projectionViewId, int32_t anchorViewId, const Windows::Devices::Enumeration::DeviceInformation & displayDeviceInfo) const;
    Windows::Foundation::IAsyncOperation<bool> RequestStartProjectingAsync(int32_t projectionViewId, int32_t anchorViewId, const Windows::Foundation::Rect & selection) const;
    Windows::Foundation::IAsyncOperation<bool> RequestStartProjectingAsync(int32_t projectionViewId, int32_t anchorViewId, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement prefferedPlacement) const;
    hstring GetDeviceSelector() const;
};

template <typename D>
struct WINRT_EBO impl_IStatusBar
{
    Windows::Foundation::IAsyncAction ShowAsync() const;
    Windows::Foundation::IAsyncAction HideAsync() const;
    double BackgroundOpacity() const;
    void BackgroundOpacity(double value) const;
    Windows::Foundation::IReference<Windows::UI::Color> ForegroundColor() const;
    void ForegroundColor(const optional<Windows::UI::Color> & value) const;
    Windows::Foundation::IReference<Windows::UI::Color> BackgroundColor() const;
    void BackgroundColor(const optional<Windows::UI::Color> & value) const;
    Windows::UI::ViewManagement::StatusBarProgressIndicator ProgressIndicator() const;
    Windows::Foundation::Rect OccludedRect() const;
    event_token Showing(const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::StatusBar, Windows::Foundation::IInspectable> & eventHandler) const;
    using Showing_revoker = event_revoker<IStatusBar>;
    Showing_revoker Showing(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::StatusBar, Windows::Foundation::IInspectable> & eventHandler) const;
    void Showing(event_token token) const;
    event_token Hiding(const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::StatusBar, Windows::Foundation::IInspectable> & eventHandler) const;
    using Hiding_revoker = event_revoker<IStatusBar>;
    Hiding_revoker Hiding(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::StatusBar, Windows::Foundation::IInspectable> & eventHandler) const;
    void Hiding(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IStatusBarProgressIndicator
{
    Windows::Foundation::IAsyncAction ShowAsync() const;
    Windows::Foundation::IAsyncAction HideAsync() const;
    hstring Text() const;
    void Text(hstring_view value) const;
    Windows::Foundation::IReference<double> ProgressValue() const;
    void ProgressValue(const optional<double> & value) const;
};

template <typename D>
struct WINRT_EBO impl_IStatusBarStatics
{
    Windows::UI::ViewManagement::StatusBar GetForCurrentView() const;
};

template <typename D>
struct WINRT_EBO impl_IUISettings
{
    Windows::UI::ViewManagement::HandPreference HandPreference() const;
    Windows::Foundation::Size CursorSize() const;
    Windows::Foundation::Size ScrollBarSize() const;
    Windows::Foundation::Size ScrollBarArrowSize() const;
    Windows::Foundation::Size ScrollBarThumbBoxSize() const;
    uint32_t MessageDuration() const;
    bool AnimationsEnabled() const;
    bool CaretBrowsingEnabled() const;
    uint32_t CaretBlinkRate() const;
    uint32_t CaretWidth() const;
    uint32_t DoubleClickTime() const;
    uint32_t MouseHoverTime() const;
    Windows::UI::Color UIElementColor(Windows::UI::ViewManagement::UIElementType desiredElement) const;
};

template <typename D>
struct WINRT_EBO impl_IUISettings2
{
    double TextScaleFactor() const;
    event_token TextScaleFactorChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::UISettings, Windows::Foundation::IInspectable> & handler) const;
    using TextScaleFactorChanged_revoker = event_revoker<IUISettings2>;
    TextScaleFactorChanged_revoker TextScaleFactorChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::UISettings, Windows::Foundation::IInspectable> & handler) const;
    void TextScaleFactorChanged(event_token cookie) const;
};

template <typename D>
struct WINRT_EBO impl_IUISettings3
{
    Windows::UI::Color GetColorValue(Windows::UI::ViewManagement::UIColorType desiredColor) const;
    event_token ColorValuesChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::UISettings, Windows::Foundation::IInspectable> & handler) const;
    using ColorValuesChanged_revoker = event_revoker<IUISettings3>;
    ColorValuesChanged_revoker ColorValuesChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::ViewManagement::UISettings, Windows::Foundation::IInspectable> & handler) const;
    void ColorValuesChanged(event_token cookie) const;
};

template <typename D>
struct WINRT_EBO impl_IUIViewSettings
{
    Windows::UI::ViewManagement::UserInteractionMode UserInteractionMode() const;
};

template <typename D>
struct WINRT_EBO impl_IUIViewSettingsStatics
{
    Windows::UI::ViewManagement::UIViewSettings GetForCurrentView() const;
};

}

namespace impl {

template <> struct traits<Windows::UI::ViewManagement::IAccessibilitySettings>
{
    using abi = ABI::Windows::UI::ViewManagement::IAccessibilitySettings;
    template <typename D> using consume = Windows::UI::ViewManagement::impl_IAccessibilitySettings<D>;
};

template <> struct traits<Windows::UI::ViewManagement::IActivationViewSwitcher>
{
    using abi = ABI::Windows::UI::ViewManagement::IActivationViewSwitcher;
    template <typename D> using consume = Windows::UI::ViewManagement::impl_IActivationViewSwitcher<D>;
};

template <> struct traits<Windows::UI::ViewManagement::IApplicationView>
{
    using abi = ABI::Windows::UI::ViewManagement::IApplicationView;
    template <typename D> using consume = Windows::UI::ViewManagement::impl_IApplicationView<D>;
};

template <> struct traits<Windows::UI::ViewManagement::IApplicationView2>
{
    using abi = ABI::Windows::UI::ViewManagement::IApplicationView2;
    template <typename D> using consume = Windows::UI::ViewManagement::impl_IApplicationView2<D>;
};

template <> struct traits<Windows::UI::ViewManagement::IApplicationView3>
{
    using abi = ABI::Windows::UI::ViewManagement::IApplicationView3;
    template <typename D> using consume = Windows::UI::ViewManagement::impl_IApplicationView3<D>;
};

template <> struct traits<Windows::UI::ViewManagement::IApplicationViewConsolidatedEventArgs>
{
    using abi = ABI::Windows::UI::ViewManagement::IApplicationViewConsolidatedEventArgs;
    template <typename D> using consume = Windows::UI::ViewManagement::impl_IApplicationViewConsolidatedEventArgs<D>;
};

template <> struct traits<Windows::UI::ViewManagement::IApplicationViewFullscreenStatics>
{
    using abi = ABI::Windows::UI::ViewManagement::IApplicationViewFullscreenStatics;
    template <typename D> using consume = Windows::UI::ViewManagement::impl_IApplicationViewFullscreenStatics<D>;
};

template <> struct traits<Windows::UI::ViewManagement::IApplicationViewInteropStatics>
{
    using abi = ABI::Windows::UI::ViewManagement::IApplicationViewInteropStatics;
    template <typename D> using consume = Windows::UI::ViewManagement::impl_IApplicationViewInteropStatics<D>;
};

template <> struct traits<Windows::UI::ViewManagement::IApplicationViewScaling>
{
    using abi = ABI::Windows::UI::ViewManagement::IApplicationViewScaling;
    template <typename D> using consume = Windows::UI::ViewManagement::impl_IApplicationViewScaling<D>;
};

template <> struct traits<Windows::UI::ViewManagement::IApplicationViewScalingStatics>
{
    using abi = ABI::Windows::UI::ViewManagement::IApplicationViewScalingStatics;
    template <typename D> using consume = Windows::UI::ViewManagement::impl_IApplicationViewScalingStatics<D>;
};

template <> struct traits<Windows::UI::ViewManagement::IApplicationViewStatics>
{
    using abi = ABI::Windows::UI::ViewManagement::IApplicationViewStatics;
    template <typename D> using consume = Windows::UI::ViewManagement::impl_IApplicationViewStatics<D>;
};

template <> struct traits<Windows::UI::ViewManagement::IApplicationViewStatics2>
{
    using abi = ABI::Windows::UI::ViewManagement::IApplicationViewStatics2;
    template <typename D> using consume = Windows::UI::ViewManagement::impl_IApplicationViewStatics2<D>;
};

template <> struct traits<Windows::UI::ViewManagement::IApplicationViewStatics3>
{
    using abi = ABI::Windows::UI::ViewManagement::IApplicationViewStatics3;
    template <typename D> using consume = Windows::UI::ViewManagement::impl_IApplicationViewStatics3<D>;
};

template <> struct traits<Windows::UI::ViewManagement::IApplicationViewSwitcherStatics>
{
    using abi = ABI::Windows::UI::ViewManagement::IApplicationViewSwitcherStatics;
    template <typename D> using consume = Windows::UI::ViewManagement::impl_IApplicationViewSwitcherStatics<D>;
};

template <> struct traits<Windows::UI::ViewManagement::IApplicationViewSwitcherStatics2>
{
    using abi = ABI::Windows::UI::ViewManagement::IApplicationViewSwitcherStatics2;
    template <typename D> using consume = Windows::UI::ViewManagement::impl_IApplicationViewSwitcherStatics2<D>;
};

template <> struct traits<Windows::UI::ViewManagement::IApplicationViewTitleBar>
{
    using abi = ABI::Windows::UI::ViewManagement::IApplicationViewTitleBar;
    template <typename D> using consume = Windows::UI::ViewManagement::impl_IApplicationViewTitleBar<D>;
};

template <> struct traits<Windows::UI::ViewManagement::IApplicationViewTransferContext>
{
    using abi = ABI::Windows::UI::ViewManagement::IApplicationViewTransferContext;
    template <typename D> using consume = Windows::UI::ViewManagement::impl_IApplicationViewTransferContext<D>;
};

template <> struct traits<Windows::UI::ViewManagement::IApplicationViewTransferContextStatics>
{
    using abi = ABI::Windows::UI::ViewManagement::IApplicationViewTransferContextStatics;
    template <typename D> using consume = Windows::UI::ViewManagement::impl_IApplicationViewTransferContextStatics<D>;
};

template <> struct traits<Windows::UI::ViewManagement::IInputPane>
{
    using abi = ABI::Windows::UI::ViewManagement::IInputPane;
    template <typename D> using consume = Windows::UI::ViewManagement::impl_IInputPane<D>;
};

template <> struct traits<Windows::UI::ViewManagement::IInputPane2>
{
    using abi = ABI::Windows::UI::ViewManagement::IInputPane2;
    template <typename D> using consume = Windows::UI::ViewManagement::impl_IInputPane2<D>;
};

template <> struct traits<Windows::UI::ViewManagement::IInputPaneControl>
{
    using abi = ABI::Windows::UI::ViewManagement::IInputPaneControl;
    template <typename D> using consume = Windows::UI::ViewManagement::impl_IInputPaneControl<D>;
};

template <> struct traits<Windows::UI::ViewManagement::IInputPaneStatics>
{
    using abi = ABI::Windows::UI::ViewManagement::IInputPaneStatics;
    template <typename D> using consume = Windows::UI::ViewManagement::impl_IInputPaneStatics<D>;
};

template <> struct traits<Windows::UI::ViewManagement::IInputPaneVisibilityEventArgs>
{
    using abi = ABI::Windows::UI::ViewManagement::IInputPaneVisibilityEventArgs;
    template <typename D> using consume = Windows::UI::ViewManagement::impl_IInputPaneVisibilityEventArgs<D>;
};

template <> struct traits<Windows::UI::ViewManagement::IProjectionManagerStatics>
{
    using abi = ABI::Windows::UI::ViewManagement::IProjectionManagerStatics;
    template <typename D> using consume = Windows::UI::ViewManagement::impl_IProjectionManagerStatics<D>;
};

template <> struct traits<Windows::UI::ViewManagement::IProjectionManagerStatics2>
{
    using abi = ABI::Windows::UI::ViewManagement::IProjectionManagerStatics2;
    template <typename D> using consume = Windows::UI::ViewManagement::impl_IProjectionManagerStatics2<D>;
};

template <> struct traits<Windows::UI::ViewManagement::IStatusBar>
{
    using abi = ABI::Windows::UI::ViewManagement::IStatusBar;
    template <typename D> using consume = Windows::UI::ViewManagement::impl_IStatusBar<D>;
};

template <> struct traits<Windows::UI::ViewManagement::IStatusBarProgressIndicator>
{
    using abi = ABI::Windows::UI::ViewManagement::IStatusBarProgressIndicator;
    template <typename D> using consume = Windows::UI::ViewManagement::impl_IStatusBarProgressIndicator<D>;
};

template <> struct traits<Windows::UI::ViewManagement::IStatusBarStatics>
{
    using abi = ABI::Windows::UI::ViewManagement::IStatusBarStatics;
    template <typename D> using consume = Windows::UI::ViewManagement::impl_IStatusBarStatics<D>;
};

template <> struct traits<Windows::UI::ViewManagement::IUISettings>
{
    using abi = ABI::Windows::UI::ViewManagement::IUISettings;
    template <typename D> using consume = Windows::UI::ViewManagement::impl_IUISettings<D>;
};

template <> struct traits<Windows::UI::ViewManagement::IUISettings2>
{
    using abi = ABI::Windows::UI::ViewManagement::IUISettings2;
    template <typename D> using consume = Windows::UI::ViewManagement::impl_IUISettings2<D>;
};

template <> struct traits<Windows::UI::ViewManagement::IUISettings3>
{
    using abi = ABI::Windows::UI::ViewManagement::IUISettings3;
    template <typename D> using consume = Windows::UI::ViewManagement::impl_IUISettings3<D>;
};

template <> struct traits<Windows::UI::ViewManagement::IUIViewSettings>
{
    using abi = ABI::Windows::UI::ViewManagement::IUIViewSettings;
    template <typename D> using consume = Windows::UI::ViewManagement::impl_IUIViewSettings<D>;
};

template <> struct traits<Windows::UI::ViewManagement::IUIViewSettingsStatics>
{
    using abi = ABI::Windows::UI::ViewManagement::IUIViewSettingsStatics;
    template <typename D> using consume = Windows::UI::ViewManagement::impl_IUIViewSettingsStatics<D>;
};

template <> struct traits<Windows::UI::ViewManagement::AccessibilitySettings>
{
    using abi = ABI::Windows::UI::ViewManagement::AccessibilitySettings;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.ViewManagement.AccessibilitySettings"; }
};

template <> struct traits<Windows::UI::ViewManagement::ActivationViewSwitcher>
{
    using abi = ABI::Windows::UI::ViewManagement::ActivationViewSwitcher;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.ViewManagement.ActivationViewSwitcher"; }
};

template <> struct traits<Windows::UI::ViewManagement::ApplicationView>
{
    using abi = ABI::Windows::UI::ViewManagement::ApplicationView;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.ViewManagement.ApplicationView"; }
};

template <> struct traits<Windows::UI::ViewManagement::ApplicationViewConsolidatedEventArgs>
{
    using abi = ABI::Windows::UI::ViewManagement::ApplicationViewConsolidatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.ViewManagement.ApplicationViewConsolidatedEventArgs"; }
};

template <> struct traits<Windows::UI::ViewManagement::ApplicationViewScaling>
{
    using abi = ABI::Windows::UI::ViewManagement::ApplicationViewScaling;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.ViewManagement.ApplicationViewScaling"; }
};

template <> struct traits<Windows::UI::ViewManagement::ApplicationViewSwitcher>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.ViewManagement.ApplicationViewSwitcher"; }
};

template <> struct traits<Windows::UI::ViewManagement::ApplicationViewTitleBar>
{
    using abi = ABI::Windows::UI::ViewManagement::ApplicationViewTitleBar;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.ViewManagement.ApplicationViewTitleBar"; }
};

template <> struct traits<Windows::UI::ViewManagement::ApplicationViewTransferContext>
{
    using abi = ABI::Windows::UI::ViewManagement::ApplicationViewTransferContext;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.ViewManagement.ApplicationViewTransferContext"; }
};

template <> struct traits<Windows::UI::ViewManagement::InputPane>
{
    using abi = ABI::Windows::UI::ViewManagement::InputPane;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.ViewManagement.InputPane"; }
};

template <> struct traits<Windows::UI::ViewManagement::InputPaneVisibilityEventArgs>
{
    using abi = ABI::Windows::UI::ViewManagement::InputPaneVisibilityEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.ViewManagement.InputPaneVisibilityEventArgs"; }
};

template <> struct traits<Windows::UI::ViewManagement::ProjectionManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.ViewManagement.ProjectionManager"; }
};

template <> struct traits<Windows::UI::ViewManagement::StatusBar>
{
    using abi = ABI::Windows::UI::ViewManagement::StatusBar;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.ViewManagement.StatusBar"; }
};

template <> struct traits<Windows::UI::ViewManagement::StatusBarProgressIndicator>
{
    using abi = ABI::Windows::UI::ViewManagement::StatusBarProgressIndicator;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.ViewManagement.StatusBarProgressIndicator"; }
};

template <> struct traits<Windows::UI::ViewManagement::UISettings>
{
    using abi = ABI::Windows::UI::ViewManagement::UISettings;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.ViewManagement.UISettings"; }
};

template <> struct traits<Windows::UI::ViewManagement::UIViewSettings>
{
    using abi = ABI::Windows::UI::ViewManagement::UIViewSettings;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.ViewManagement.UIViewSettings"; }
};

}

}
