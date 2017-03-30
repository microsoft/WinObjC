// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.ViewManagement.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_cdb5efb3_5788_509d_9be1_71ccb8a3362a
#define WINRT_GENERIC_cdb5efb3_5788_509d_9be1_71ccb8a3362a
template <> struct __declspec(uuid("cdb5efb3-5788-509d-9be1-71ccb8a3362a")) __declspec(novtable) IAsyncOperation<bool> : impl_IAsyncOperation<bool> {};
#endif

#ifndef WINRT_GENERIC_463c606a_8c82_5a29_a2bd_040781f25348
#define WINRT_GENERIC_463c606a_8c82_5a29_a2bd_040781f25348
template <> struct __declspec(uuid("463c606a-8c82-5a29-a2bd-040781f25348")) __declspec(novtable) TypedEventHandler<Windows::UI::ViewManagement::ApplicationView, Windows::UI::ViewManagement::ApplicationViewConsolidatedEventArgs> : impl_TypedEventHandler<Windows::UI::ViewManagement::ApplicationView, Windows::UI::ViewManagement::ApplicationViewConsolidatedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_00c1f983_c836_565c_8bbf_7053055bdb4c
#define WINRT_GENERIC_00c1f983_c836_565c_8bbf_7053055bdb4c
template <> struct __declspec(uuid("00c1f983-c836-565c-8bbf-7053055bdb4c")) __declspec(novtable) TypedEventHandler<Windows::UI::ViewManagement::ApplicationView, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::UI::ViewManagement::ApplicationView, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_ab8e5d11_b0c1_5a21_95ae_f16bf3a37624
#define WINRT_GENERIC_ab8e5d11_b0c1_5a21_95ae_f16bf3a37624
template <> struct __declspec(uuid("ab8e5d11-b0c1-5a21-95ae-f16bf3a37624")) __declspec(novtable) IReference<Windows::UI::Color> : impl_IReference<Windows::UI::Color> {};
#endif

#ifndef WINRT_GENERIC_c50898f6_c536_5f47_8583_8b2c2438a13b
#define WINRT_GENERIC_c50898f6_c536_5f47_8583_8b2c2438a13b
template <> struct __declspec(uuid("c50898f6-c536-5f47-8583-8b2c2438a13b")) __declspec(novtable) EventHandler<Windows::Foundation::IInspectable> : impl_EventHandler<Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_2f2d6c29_5473_5f3e_92e7_96572bb990e2
#define WINRT_GENERIC_2f2d6c29_5473_5f3e_92e7_96572bb990e2
template <> struct __declspec(uuid("2f2d6c29-5473-5f3e-92e7-96572bb990e2")) __declspec(novtable) IReference<double> : impl_IReference<double> {};
#endif

#ifndef WINRT_GENERIC_b813d684_d953_5a8a_9b30_78b79fb9147b
#define WINRT_GENERIC_b813d684_d953_5a8a_9b30_78b79fb9147b
template <> struct __declspec(uuid("b813d684-d953-5a8a-9b30-78b79fb9147b")) __declspec(novtable) TypedEventHandler<Windows::UI::ViewManagement::InputPane, Windows::UI::ViewManagement::InputPaneVisibilityEventArgs> : impl_TypedEventHandler<Windows::UI::ViewManagement::InputPane, Windows::UI::ViewManagement::InputPaneVisibilityEventArgs> {};
#endif

#ifndef WINRT_GENERIC_f5917e6f_5abf_5e65_b5b4_1b9c8d94e788
#define WINRT_GENERIC_f5917e6f_5abf_5e65_b5b4_1b9c8d94e788
template <> struct __declspec(uuid("f5917e6f-5abf-5e65-b5b4-1b9c8d94e788")) __declspec(novtable) TypedEventHandler<Windows::UI::ViewManagement::AccessibilitySettings, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::UI::ViewManagement::AccessibilitySettings, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_2dbdba9d_20da_519d_9078_09f835bc5bc7
#define WINRT_GENERIC_2dbdba9d_20da_519d_9078_09f835bc5bc7
template <> struct __declspec(uuid("2dbdba9d-20da-519d-9078-09f835bc5bc7")) __declspec(novtable) TypedEventHandler<Windows::UI::ViewManagement::UISettings, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::UI::ViewManagement::UISettings, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_38254d6e_8596_5218_bb61_5d9db935aa02
#define WINRT_GENERIC_38254d6e_8596_5218_bb61_5d9db935aa02
template <> struct __declspec(uuid("38254d6e-8596-5218-bb61-5d9db935aa02")) __declspec(novtable) TypedEventHandler<Windows::UI::ViewManagement::StatusBar, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::UI::ViewManagement::StatusBar, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_c1d3d1a2_ae17_5a5f_b5a2_bdcc8844889a
#define WINRT_GENERIC_c1d3d1a2_ae17_5a5f_b5a2_bdcc8844889a
template <> struct __declspec(uuid("c1d3d1a2-ae17-5a5f-b5a2-bdcc8844889a")) __declspec(novtable) AsyncOperationCompletedHandler<bool> : impl_AsyncOperationCompletedHandler<bool> {};
#endif


}

namespace Windows::UI::ViewManagement {

struct IAccessibilitySettings :
    Windows::Foundation::IInspectable,
    impl::consume<IAccessibilitySettings>
{
    IAccessibilitySettings(std::nullptr_t = nullptr) noexcept {}
};

struct IActivationViewSwitcher :
    Windows::Foundation::IInspectable,
    impl::consume<IActivationViewSwitcher>
{
    IActivationViewSwitcher(std::nullptr_t = nullptr) noexcept {}
};

struct IApplicationView :
    Windows::Foundation::IInspectable,
    impl::consume<IApplicationView>
{
    IApplicationView(std::nullptr_t = nullptr) noexcept {}
};

struct IApplicationView2 :
    Windows::Foundation::IInspectable,
    impl::consume<IApplicationView2>
{
    IApplicationView2(std::nullptr_t = nullptr) noexcept {}
};

struct IApplicationView3 :
    Windows::Foundation::IInspectable,
    impl::consume<IApplicationView3>
{
    IApplicationView3(std::nullptr_t = nullptr) noexcept {}
};

struct IApplicationViewConsolidatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IApplicationViewConsolidatedEventArgs>
{
    IApplicationViewConsolidatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct [[deprecated("IApplicationViewFullscreenStatics is deprecated after Windows 8. Please use other resize APIs.")]] IApplicationViewFullscreenStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IApplicationViewFullscreenStatics>
{
    IApplicationViewFullscreenStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IApplicationViewInteropStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IApplicationViewInteropStatics>
{
    IApplicationViewInteropStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IApplicationViewScaling :
    Windows::Foundation::IInspectable,
    impl::consume<IApplicationViewScaling>
{
    IApplicationViewScaling(std::nullptr_t = nullptr) noexcept {}
};

struct IApplicationViewScalingStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IApplicationViewScalingStatics>
{
    IApplicationViewScalingStatics(std::nullptr_t = nullptr) noexcept {}
};

struct [[deprecated("ApplicationView static methods may be altered or unavailable for releases after Windows 8.1. Instead, use ApplicationView.GetForCurrentView to get an instance of ApplicationView.")]] IApplicationViewStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IApplicationViewStatics>
{
    IApplicationViewStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IApplicationViewStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IApplicationViewStatics2>
{
    IApplicationViewStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct IApplicationViewStatics3 :
    Windows::Foundation::IInspectable,
    impl::consume<IApplicationViewStatics3>
{
    IApplicationViewStatics3(std::nullptr_t = nullptr) noexcept {}
};

struct IApplicationViewSwitcherStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IApplicationViewSwitcherStatics>
{
    IApplicationViewSwitcherStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IApplicationViewSwitcherStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IApplicationViewSwitcherStatics2>
{
    IApplicationViewSwitcherStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct IApplicationViewTitleBar :
    Windows::Foundation::IInspectable,
    impl::consume<IApplicationViewTitleBar>
{
    IApplicationViewTitleBar(std::nullptr_t = nullptr) noexcept {}
};

struct IApplicationViewTransferContext :
    Windows::Foundation::IInspectable,
    impl::consume<IApplicationViewTransferContext>
{
    IApplicationViewTransferContext(std::nullptr_t = nullptr) noexcept {}
};

struct IApplicationViewTransferContextStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IApplicationViewTransferContextStatics>
{
    IApplicationViewTransferContextStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IInputPane :
    Windows::Foundation::IInspectable,
    impl::consume<IInputPane>
{
    IInputPane(std::nullptr_t = nullptr) noexcept {}
};

struct IInputPane2 :
    Windows::Foundation::IInspectable,
    impl::consume<IInputPane2>
{
    IInputPane2(std::nullptr_t = nullptr) noexcept {}
};

struct IInputPaneControl :
    Windows::Foundation::IInspectable,
    impl::consume<IInputPaneControl>
{
    IInputPaneControl(std::nullptr_t = nullptr) noexcept {}
};

struct IInputPaneStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IInputPaneStatics>
{
    IInputPaneStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IInputPaneVisibilityEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IInputPaneVisibilityEventArgs>
{
    IInputPaneVisibilityEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IProjectionManagerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IProjectionManagerStatics>
{
    IProjectionManagerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IProjectionManagerStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IProjectionManagerStatics2>
{
    IProjectionManagerStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct IStatusBar :
    Windows::Foundation::IInspectable,
    impl::consume<IStatusBar>
{
    IStatusBar(std::nullptr_t = nullptr) noexcept {}
};

struct IStatusBarProgressIndicator :
    Windows::Foundation::IInspectable,
    impl::consume<IStatusBarProgressIndicator>
{
    IStatusBarProgressIndicator(std::nullptr_t = nullptr) noexcept {}
};

struct IStatusBarStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IStatusBarStatics>
{
    IStatusBarStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IUISettings :
    Windows::Foundation::IInspectable,
    impl::consume<IUISettings>
{
    IUISettings(std::nullptr_t = nullptr) noexcept {}
};

struct IUISettings2 :
    Windows::Foundation::IInspectable,
    impl::consume<IUISettings2>
{
    IUISettings2(std::nullptr_t = nullptr) noexcept {}
};

struct IUISettings3 :
    Windows::Foundation::IInspectable,
    impl::consume<IUISettings3>
{
    IUISettings3(std::nullptr_t = nullptr) noexcept {}
};

struct IUIViewSettings :
    Windows::Foundation::IInspectable,
    impl::consume<IUIViewSettings>
{
    IUIViewSettings(std::nullptr_t = nullptr) noexcept {}
};

struct IUIViewSettingsStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IUIViewSettingsStatics>
{
    IUIViewSettingsStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
