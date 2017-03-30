// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Automation.Peers.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Automation::Peers {

struct WINRT_EBO AppBarAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IAppBarAutomationPeer,
    impl::bases<AppBarAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<AppBarAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IExpandCollapseProvider, Windows::UI::Xaml::Automation::Provider::IToggleProvider, Windows::UI::Xaml::Automation::Provider::IWindowProvider>
{
    AppBarAutomationPeer(std::nullptr_t) noexcept {}
    AppBarAutomationPeer(const Windows::UI::Xaml::Controls::AppBar & owner);
};

struct WINRT_EBO AppBarButtonAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IAppBarButtonAutomationPeer,
    impl::bases<AppBarButtonAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::ButtonAutomationPeer>,
    impl::require<AppBarButtonAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IInvokeProvider>
{
    AppBarButtonAutomationPeer(std::nullptr_t) noexcept {}
    AppBarButtonAutomationPeer(const Windows::UI::Xaml::Controls::AppBarButton & owner);
};

struct WINRT_EBO AppBarToggleButtonAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IAppBarToggleButtonAutomationPeer,
    impl::bases<AppBarToggleButtonAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::ToggleButtonAutomationPeer>,
    impl::require<AppBarToggleButtonAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IToggleProvider>
{
    AppBarToggleButtonAutomationPeer(std::nullptr_t) noexcept {}
    AppBarToggleButtonAutomationPeer(const Windows::UI::Xaml::Controls::AppBarToggleButton & owner);
};

struct WINRT_EBO AutoSuggestBoxAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IAutoSuggestBoxAutomationPeer,
    impl::bases<AutoSuggestBoxAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<AutoSuggestBoxAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    AutoSuggestBoxAutomationPeer(std::nullptr_t) noexcept {}
    AutoSuggestBoxAutomationPeer(const Windows::UI::Xaml::Controls::AutoSuggestBox & owner);
};

struct WINRT_EBO AutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IAutomationPeer,
    impl::bases<AutomationPeer, Windows::UI::Xaml::DependencyObject>,
    impl::require<AutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5>
{
    AutomationPeer(std::nullptr_t) noexcept {}
    static bool ListenerExists(Windows::UI::Xaml::Automation::Peers::AutomationEvents eventId);
    static Windows::UI::Xaml::Automation::Peers::RawElementProviderRuntimeId GenerateRawElementProviderRuntimeId();
};

struct WINRT_EBO AutomationPeerAnnotation :
    Windows::UI::Xaml::Automation::Peers::IAutomationPeerAnnotation,
    impl::bases<AutomationPeerAnnotation, Windows::UI::Xaml::DependencyObject>,
    impl::require<AutomationPeerAnnotation, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    AutomationPeerAnnotation(std::nullptr_t) noexcept {}
    AutomationPeerAnnotation();
    AutomationPeerAnnotation(Windows::UI::Xaml::Automation::AnnotationType type);
    AutomationPeerAnnotation(Windows::UI::Xaml::Automation::AnnotationType type, const Windows::UI::Xaml::Automation::Peers::AutomationPeer & peer);
    static Windows::UI::Xaml::DependencyProperty TypeProperty();
    static Windows::UI::Xaml::DependencyProperty PeerProperty();
};

struct WINRT_EBO ButtonAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IButtonAutomationPeer,
    impl::bases<ButtonAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ButtonBaseAutomationPeer>,
    impl::require<ButtonAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IInvokeProvider>
{
    ButtonAutomationPeer(std::nullptr_t) noexcept {}
    ButtonAutomationPeer(const Windows::UI::Xaml::Controls::Button & owner);
};

struct WINRT_EBO ButtonBaseAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer,
    impl::bases<ButtonBaseAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<ButtonBaseAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    ButtonBaseAutomationPeer(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CaptureElementAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::ICaptureElementAutomationPeer,
    impl::bases<CaptureElementAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<CaptureElementAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    CaptureElementAutomationPeer(std::nullptr_t) noexcept {}
    CaptureElementAutomationPeer(const Windows::UI::Xaml::Controls::CaptureElement & owner);
};

struct WINRT_EBO CheckBoxAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::ICheckBoxAutomationPeer,
    impl::bases<CheckBoxAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::ToggleButtonAutomationPeer>,
    impl::require<CheckBoxAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IToggleProvider>
{
    CheckBoxAutomationPeer(std::nullptr_t) noexcept {}
    CheckBoxAutomationPeer(const Windows::UI::Xaml::Controls::CheckBox & owner);
};

struct WINRT_EBO ComboBoxAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IComboBoxAutomationPeer,
    impl::bases<ComboBoxAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Peers::SelectorAutomationPeer>,
    impl::require<ComboBoxAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IExpandCollapseProvider, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Provider::ISelectionProvider, Windows::UI::Xaml::Automation::Provider::IValueProvider, Windows::UI::Xaml::Automation::Provider::IWindowProvider>
{
    ComboBoxAutomationPeer(std::nullptr_t) noexcept {}
    ComboBoxAutomationPeer(const Windows::UI::Xaml::Controls::ComboBox & owner);
    using impl_IDependencyObject::SetValue;
    using impl_IValueProvider::SetValue;
};

struct WINRT_EBO ComboBoxItemAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IComboBoxItemAutomationPeer,
    impl::bases<ComboBoxItemAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<ComboBoxItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    ComboBoxItemAutomationPeer(std::nullptr_t) noexcept {}
    ComboBoxItemAutomationPeer(const Windows::UI::Xaml::Controls::ComboBoxItem & owner);
};

struct WINRT_EBO ComboBoxItemDataAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IComboBoxItemDataAutomationPeer,
    impl::bases<ComboBoxItemDataAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::ItemAutomationPeer, Windows::UI::Xaml::Automation::Peers::SelectorItemAutomationPeer>,
    impl::require<ComboBoxItemDataAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer, Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Provider::IScrollItemProvider, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider>
{
    ComboBoxItemDataAutomationPeer(std::nullptr_t) noexcept {}
    ComboBoxItemDataAutomationPeer(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::ComboBoxAutomationPeer & parent);
};

struct WINRT_EBO DatePickerAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IDatePickerAutomationPeer,
    impl::bases<DatePickerAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<DatePickerAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    DatePickerAutomationPeer(std::nullptr_t) noexcept {}
    DatePickerAutomationPeer(const Windows::UI::Xaml::Controls::DatePicker & owner);
};

struct WINRT_EBO DatePickerFlyoutPresenterAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IDatePickerFlyoutPresenterAutomationPeer,
    impl::bases<DatePickerFlyoutPresenterAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<DatePickerFlyoutPresenterAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    DatePickerFlyoutPresenterAutomationPeer(std::nullptr_t) noexcept {}
};

struct WINRT_EBO FlipViewAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IFlipViewAutomationPeer,
    impl::bases<FlipViewAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Peers::SelectorAutomationPeer>,
    impl::require<FlipViewAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Provider::ISelectionProvider>
{
    FlipViewAutomationPeer(std::nullptr_t) noexcept {}
    FlipViewAutomationPeer(const Windows::UI::Xaml::Controls::FlipView & owner);
};

struct WINRT_EBO FlipViewItemAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IFlipViewItemAutomationPeer,
    impl::bases<FlipViewItemAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<FlipViewItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    FlipViewItemAutomationPeer(std::nullptr_t) noexcept {}
    FlipViewItemAutomationPeer(const Windows::UI::Xaml::Controls::FlipViewItem & owner);
};

struct WINRT_EBO FlipViewItemDataAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IFlipViewItemDataAutomationPeer,
    impl::bases<FlipViewItemDataAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::ItemAutomationPeer, Windows::UI::Xaml::Automation::Peers::SelectorItemAutomationPeer>,
    impl::require<FlipViewItemDataAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer, Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Provider::IScrollItemProvider, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider>
{
    FlipViewItemDataAutomationPeer(std::nullptr_t) noexcept {}
    FlipViewItemDataAutomationPeer(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::FlipViewAutomationPeer & parent);
};

struct WINRT_EBO FlyoutPresenterAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IFlyoutPresenterAutomationPeer,
    impl::bases<FlyoutPresenterAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<FlyoutPresenterAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    FlyoutPresenterAutomationPeer(std::nullptr_t) noexcept {}
    FlyoutPresenterAutomationPeer(const Windows::UI::Xaml::Controls::FlyoutPresenter & owner);
};

struct WINRT_EBO FrameworkElementAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer,
    impl::bases<FrameworkElementAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer>,
    impl::require<FrameworkElementAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5>
{
    FrameworkElementAutomationPeer(std::nullptr_t) noexcept {}
    FrameworkElementAutomationPeer(const Windows::UI::Xaml::FrameworkElement & owner);
    static Windows::UI::Xaml::Automation::Peers::AutomationPeer FromElement(const Windows::UI::Xaml::UIElement & element);
    static Windows::UI::Xaml::Automation::Peers::AutomationPeer CreatePeerForElement(const Windows::UI::Xaml::UIElement & element);
};

struct WINRT_EBO GridViewAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IGridViewAutomationPeer,
    impl::bases<GridViewAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Peers::SelectorAutomationPeer, Windows::UI::Xaml::Automation::Peers::ListViewBaseAutomationPeer>,
    impl::require<GridViewAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, Windows::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IDropTargetProvider, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Provider::ISelectionProvider>
{
    GridViewAutomationPeer(std::nullptr_t) noexcept {}
    GridViewAutomationPeer(const Windows::UI::Xaml::Controls::GridView & owner);
};

struct WINRT_EBO GridViewHeaderItemAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IGridViewHeaderItemAutomationPeer,
    impl::bases<GridViewHeaderItemAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ListViewBaseHeaderItemAutomationPeer>,
    impl::require<GridViewHeaderItemAutomationPeer, Windows::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    GridViewHeaderItemAutomationPeer(std::nullptr_t) noexcept {}
    GridViewHeaderItemAutomationPeer(const Windows::UI::Xaml::Controls::GridViewHeaderItem & owner);
};

struct WINRT_EBO GridViewItemAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IGridViewItemAutomationPeer,
    impl::bases<GridViewItemAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<GridViewItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    GridViewItemAutomationPeer(std::nullptr_t) noexcept {}
    GridViewItemAutomationPeer(const Windows::UI::Xaml::Controls::GridViewItem & owner);
};

struct WINRT_EBO GridViewItemDataAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IGridViewItemDataAutomationPeer,
    impl::bases<GridViewItemDataAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::ItemAutomationPeer, Windows::UI::Xaml::Automation::Peers::SelectorItemAutomationPeer>,
    impl::require<GridViewItemDataAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer, Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Provider::IScrollItemProvider, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider>
{
    GridViewItemDataAutomationPeer(std::nullptr_t) noexcept {}
    GridViewItemDataAutomationPeer(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::GridViewAutomationPeer & parent);
};

struct WINRT_EBO GroupItemAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IGroupItemAutomationPeer,
    impl::bases<GroupItemAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<GroupItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    GroupItemAutomationPeer(std::nullptr_t) noexcept {}
    GroupItemAutomationPeer(const Windows::UI::Xaml::Controls::GroupItem & owner);
};

struct WINRT_EBO HubAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IHubAutomationPeer,
    impl::bases<HubAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<HubAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    HubAutomationPeer(std::nullptr_t) noexcept {}
    HubAutomationPeer(const Windows::UI::Xaml::Controls::Hub & owner);
};

struct WINRT_EBO HubSectionAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IHubSectionAutomationPeer,
    impl::bases<HubSectionAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<HubSectionAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IScrollItemProvider>
{
    HubSectionAutomationPeer(std::nullptr_t) noexcept {}
    HubSectionAutomationPeer(const Windows::UI::Xaml::Controls::HubSection & owner);
};

struct WINRT_EBO HyperlinkButtonAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IHyperlinkButtonAutomationPeer,
    impl::bases<HyperlinkButtonAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ButtonBaseAutomationPeer>,
    impl::require<HyperlinkButtonAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IInvokeProvider>
{
    HyperlinkButtonAutomationPeer(std::nullptr_t) noexcept {}
    HyperlinkButtonAutomationPeer(const Windows::UI::Xaml::Controls::HyperlinkButton & owner);
};

struct WINRT_EBO ImageAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IImageAutomationPeer,
    impl::bases<ImageAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<ImageAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    ImageAutomationPeer(std::nullptr_t) noexcept {}
    ImageAutomationPeer(const Windows::UI::Xaml::Controls::Image & owner);
};

struct WINRT_EBO InkToolbarAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IInkToolbarAutomationPeer,
    impl::bases<InkToolbarAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<InkToolbarAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    InkToolbarAutomationPeer(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ItemAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer,
    impl::bases<ItemAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer>,
    impl::require<ItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider>
{
    ItemAutomationPeer(std::nullptr_t) noexcept {}
    ItemAutomationPeer(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer & parent);
};

struct WINRT_EBO ItemsControlAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer,
    impl::bases<ItemsControlAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<ItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider>
{
    ItemsControlAutomationPeer(std::nullptr_t) noexcept {}
    ItemsControlAutomationPeer(const Windows::UI::Xaml::Controls::ItemsControl & owner);
};

struct WINRT_EBO ListBoxAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IListBoxAutomationPeer,
    impl::bases<ListBoxAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Peers::SelectorAutomationPeer>,
    impl::require<ListBoxAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Provider::ISelectionProvider>
{
    ListBoxAutomationPeer(std::nullptr_t) noexcept {}
    ListBoxAutomationPeer(const Windows::UI::Xaml::Controls::ListBox & owner);
};

struct WINRT_EBO ListBoxItemAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IListBoxItemAutomationPeer,
    impl::bases<ListBoxItemAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<ListBoxItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    ListBoxItemAutomationPeer(std::nullptr_t) noexcept {}
    ListBoxItemAutomationPeer(const Windows::UI::Xaml::Controls::ListBoxItem & owner);
};

struct WINRT_EBO ListBoxItemDataAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IListBoxItemDataAutomationPeer,
    impl::bases<ListBoxItemDataAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::ItemAutomationPeer, Windows::UI::Xaml::Automation::Peers::SelectorItemAutomationPeer>,
    impl::require<ListBoxItemDataAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer, Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Provider::IScrollItemProvider, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider>
{
    ListBoxItemDataAutomationPeer(std::nullptr_t) noexcept {}
    ListBoxItemDataAutomationPeer(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::ListBoxAutomationPeer & parent);
};

struct WINRT_EBO ListPickerFlyoutPresenterAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IListPickerFlyoutPresenterAutomationPeer,
    impl::bases<ListPickerFlyoutPresenterAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<ListPickerFlyoutPresenterAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    ListPickerFlyoutPresenterAutomationPeer(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ListViewAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IListViewAutomationPeer,
    impl::bases<ListViewAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Peers::SelectorAutomationPeer, Windows::UI::Xaml::Automation::Peers::ListViewBaseAutomationPeer>,
    impl::require<ListViewAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, Windows::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IDropTargetProvider, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Provider::ISelectionProvider>
{
    ListViewAutomationPeer(std::nullptr_t) noexcept {}
    ListViewAutomationPeer(const Windows::UI::Xaml::Controls::ListView & owner);
};

struct WINRT_EBO ListViewBaseAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeer,
    impl::bases<ListViewBaseAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Peers::SelectorAutomationPeer>,
    impl::require<ListViewBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IDropTargetProvider, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Provider::ISelectionProvider>
{
    ListViewBaseAutomationPeer(std::nullptr_t) noexcept {}
    ListViewBaseAutomationPeer(const Windows::UI::Xaml::Controls::ListViewBase & owner);
};

struct WINRT_EBO ListViewBaseHeaderItemAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeer,
    impl::bases<ListViewBaseHeaderItemAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<ListViewBaseHeaderItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    ListViewBaseHeaderItemAutomationPeer(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ListViewHeaderItemAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IListViewHeaderItemAutomationPeer,
    impl::bases<ListViewHeaderItemAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ListViewBaseHeaderItemAutomationPeer>,
    impl::require<ListViewHeaderItemAutomationPeer, Windows::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    ListViewHeaderItemAutomationPeer(std::nullptr_t) noexcept {}
    ListViewHeaderItemAutomationPeer(const Windows::UI::Xaml::Controls::ListViewHeaderItem & owner);
};

struct WINRT_EBO ListViewItemAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IListViewItemAutomationPeer,
    impl::bases<ListViewItemAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<ListViewItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    ListViewItemAutomationPeer(std::nullptr_t) noexcept {}
    ListViewItemAutomationPeer(const Windows::UI::Xaml::Controls::ListViewItem & owner);
};

struct WINRT_EBO ListViewItemDataAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IListViewItemDataAutomationPeer,
    impl::bases<ListViewItemDataAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::ItemAutomationPeer, Windows::UI::Xaml::Automation::Peers::SelectorItemAutomationPeer>,
    impl::require<ListViewItemDataAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer, Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Provider::IScrollItemProvider, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider>
{
    ListViewItemDataAutomationPeer(std::nullptr_t) noexcept {}
    ListViewItemDataAutomationPeer(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::ListViewBaseAutomationPeer & parent);
};

struct WINRT_EBO LoopingSelectorAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::ILoopingSelectorAutomationPeer,
    impl::bases<LoopingSelectorAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<LoopingSelectorAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IExpandCollapseProvider, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Provider::IScrollProvider, Windows::UI::Xaml::Automation::Provider::ISelectionProvider>
{
    LoopingSelectorAutomationPeer(std::nullptr_t) noexcept {}
};

struct WINRT_EBO LoopingSelectorItemAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::ILoopingSelectorItemAutomationPeer,
    impl::bases<LoopingSelectorItemAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<LoopingSelectorItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IScrollItemProvider, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider>
{
    LoopingSelectorItemAutomationPeer(std::nullptr_t) noexcept {}
};

struct WINRT_EBO LoopingSelectorItemDataAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::ILoopingSelectorItemDataAutomationPeer,
    impl::bases<LoopingSelectorItemDataAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer>,
    impl::require<LoopingSelectorItemDataAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider>
{
    LoopingSelectorItemDataAutomationPeer(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MapControlAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IMapControlAutomationPeer,
    impl::bases<MapControlAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<MapControlAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IScrollProvider>
{
    MapControlAutomationPeer(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaElementAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IMediaElementAutomationPeer,
    impl::bases<MediaElementAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<MediaElementAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    MediaElementAutomationPeer(std::nullptr_t) noexcept {}
    MediaElementAutomationPeer(const Windows::UI::Xaml::Controls::MediaElement & owner);
};

struct WINRT_EBO MediaPlayerElementAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IMediaPlayerElementAutomationPeer,
    impl::bases<MediaPlayerElementAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<MediaPlayerElementAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    MediaPlayerElementAutomationPeer(std::nullptr_t) noexcept {}
    MediaPlayerElementAutomationPeer(const Windows::UI::Xaml::Controls::MediaPlayerElement & owner);
};

struct WINRT_EBO MediaTransportControlsAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IMediaTransportControlsAutomationPeer,
    impl::bases<MediaTransportControlsAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<MediaTransportControlsAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    MediaTransportControlsAutomationPeer(std::nullptr_t) noexcept {}
    MediaTransportControlsAutomationPeer(const Windows::UI::Xaml::Controls::MediaTransportControls & owner);
};

struct WINRT_EBO MenuFlyoutItemAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IMenuFlyoutItemAutomationPeer,
    impl::bases<MenuFlyoutItemAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<MenuFlyoutItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IInvokeProvider>
{
    MenuFlyoutItemAutomationPeer(std::nullptr_t) noexcept {}
    MenuFlyoutItemAutomationPeer(const Windows::UI::Xaml::Controls::MenuFlyoutItem & owner);
};

struct WINRT_EBO MenuFlyoutPresenterAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IMenuFlyoutPresenterAutomationPeer,
    impl::bases<MenuFlyoutPresenterAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer>,
    impl::require<MenuFlyoutPresenterAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider>
{
    MenuFlyoutPresenterAutomationPeer(std::nullptr_t) noexcept {}
    MenuFlyoutPresenterAutomationPeer(const Windows::UI::Xaml::Controls::MenuFlyoutPresenter & owner);
};

struct WINRT_EBO PasswordBoxAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IPasswordBoxAutomationPeer,
    impl::bases<PasswordBoxAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<PasswordBoxAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    PasswordBoxAutomationPeer(std::nullptr_t) noexcept {}
    PasswordBoxAutomationPeer(const Windows::UI::Xaml::Controls::PasswordBox & owner);
};

struct WINRT_EBO PickerFlyoutPresenterAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IPickerFlyoutPresenterAutomationPeer,
    impl::bases<PickerFlyoutPresenterAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<PickerFlyoutPresenterAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    PickerFlyoutPresenterAutomationPeer(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PivotAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IPivotAutomationPeer,
    impl::bases<PivotAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer>,
    impl::require<PivotAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Provider::IScrollProvider, Windows::UI::Xaml::Automation::Provider::ISelectionProvider>
{
    PivotAutomationPeer(std::nullptr_t) noexcept {}
    PivotAutomationPeer(const Windows::UI::Xaml::Controls::Pivot & owner);
};

struct WINRT_EBO PivotItemAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IPivotItemAutomationPeer,
    impl::bases<PivotItemAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<PivotItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    PivotItemAutomationPeer(std::nullptr_t) noexcept {}
    PivotItemAutomationPeer(const Windows::UI::Xaml::Controls::PivotItem & owner);
};

struct WINRT_EBO PivotItemDataAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IPivotItemDataAutomationPeer,
    impl::bases<PivotItemDataAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::ItemAutomationPeer>,
    impl::require<PivotItemDataAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Provider::IScrollItemProvider, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider>
{
    PivotItemDataAutomationPeer(std::nullptr_t) noexcept {}
    PivotItemDataAutomationPeer(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::PivotAutomationPeer & parent);
};

struct WINRT_EBO ProgressBarAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IProgressBarAutomationPeer,
    impl::bases<ProgressBarAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::RangeBaseAutomationPeer>,
    impl::require<ProgressBarAutomationPeer, Windows::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IRangeValueProvider>
{
    ProgressBarAutomationPeer(std::nullptr_t) noexcept {}
    ProgressBarAutomationPeer(const Windows::UI::Xaml::Controls::ProgressBar & owner);
    using impl_IDependencyObject::SetValue;
    using impl_IRangeValueProvider::SetValue;
};

struct WINRT_EBO ProgressRingAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IProgressRingAutomationPeer,
    impl::bases<ProgressRingAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<ProgressRingAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    ProgressRingAutomationPeer(std::nullptr_t) noexcept {}
    ProgressRingAutomationPeer(const Windows::UI::Xaml::Controls::ProgressRing & owner);
};

struct WINRT_EBO RadioButtonAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IRadioButtonAutomationPeer,
    impl::bases<RadioButtonAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::ToggleButtonAutomationPeer>,
    impl::require<RadioButtonAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider, Windows::UI::Xaml::Automation::Provider::IToggleProvider>
{
    RadioButtonAutomationPeer(std::nullptr_t) noexcept {}
    RadioButtonAutomationPeer(const Windows::UI::Xaml::Controls::RadioButton & owner);
};

struct WINRT_EBO RangeBaseAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer,
    impl::bases<RangeBaseAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<RangeBaseAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IRangeValueProvider>
{
    RangeBaseAutomationPeer(std::nullptr_t) noexcept {}
    RangeBaseAutomationPeer(const Windows::UI::Xaml::Controls::Primitives::RangeBase & owner);
    using impl_IDependencyObject::SetValue;
    using impl_IRangeValueProvider::SetValue;
};

struct WINRT_EBO RepeatButtonAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IRepeatButtonAutomationPeer,
    impl::bases<RepeatButtonAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ButtonBaseAutomationPeer>,
    impl::require<RepeatButtonAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IInvokeProvider>
{
    RepeatButtonAutomationPeer(std::nullptr_t) noexcept {}
    RepeatButtonAutomationPeer(const Windows::UI::Xaml::Controls::Primitives::RepeatButton & owner);
};

struct WINRT_EBO RichEditBoxAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IRichEditBoxAutomationPeer,
    impl::bases<RichEditBoxAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<RichEditBoxAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    RichEditBoxAutomationPeer(std::nullptr_t) noexcept {}
    RichEditBoxAutomationPeer(const Windows::UI::Xaml::Controls::RichEditBox & owner);
};

struct WINRT_EBO RichTextBlockAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IRichTextBlockAutomationPeer,
    impl::bases<RichTextBlockAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<RichTextBlockAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    RichTextBlockAutomationPeer(std::nullptr_t) noexcept {}
    RichTextBlockAutomationPeer(const Windows::UI::Xaml::Controls::RichTextBlock & owner);
};

struct WINRT_EBO RichTextBlockOverflowAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IRichTextBlockOverflowAutomationPeer,
    impl::bases<RichTextBlockOverflowAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<RichTextBlockOverflowAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    RichTextBlockOverflowAutomationPeer(std::nullptr_t) noexcept {}
    RichTextBlockOverflowAutomationPeer(const Windows::UI::Xaml::Controls::RichTextBlockOverflow & owner);
};

struct WINRT_EBO ScrollBarAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IScrollBarAutomationPeer,
    impl::bases<ScrollBarAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::RangeBaseAutomationPeer>,
    impl::require<ScrollBarAutomationPeer, Windows::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IRangeValueProvider>
{
    ScrollBarAutomationPeer(std::nullptr_t) noexcept {}
    ScrollBarAutomationPeer(const Windows::UI::Xaml::Controls::Primitives::ScrollBar & owner);
    using impl_IDependencyObject::SetValue;
    using impl_IRangeValueProvider::SetValue;
};

struct WINRT_EBO ScrollViewerAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IScrollViewerAutomationPeer,
    impl::bases<ScrollViewerAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<ScrollViewerAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IScrollProvider>
{
    ScrollViewerAutomationPeer(std::nullptr_t) noexcept {}
    ScrollViewerAutomationPeer(const Windows::UI::Xaml::Controls::ScrollViewer & owner);
};

struct WINRT_EBO SearchBoxAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::ISearchBoxAutomationPeer,
    impl::bases<SearchBoxAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<SearchBoxAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    SearchBoxAutomationPeer(std::nullptr_t) noexcept {}
    SearchBoxAutomationPeer(const Windows::UI::Xaml::Controls::SearchBox & owner);
};

struct WINRT_EBO SelectorAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer,
    impl::bases<SelectorAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer>,
    impl::require<SelectorAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Provider::ISelectionProvider>
{
    SelectorAutomationPeer(std::nullptr_t) noexcept {}
    SelectorAutomationPeer(const Windows::UI::Xaml::Controls::Primitives::Selector & owner);
};

struct WINRT_EBO SelectorItemAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer,
    impl::bases<SelectorItemAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::ItemAutomationPeer>,
    impl::require<SelectorItemAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider>
{
    SelectorItemAutomationPeer(std::nullptr_t) noexcept {}
    SelectorItemAutomationPeer(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::SelectorAutomationPeer & parent);
};

struct WINRT_EBO SemanticZoomAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::ISemanticZoomAutomationPeer,
    impl::bases<SemanticZoomAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<SemanticZoomAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IToggleProvider>
{
    SemanticZoomAutomationPeer(std::nullptr_t) noexcept {}
    SemanticZoomAutomationPeer(const Windows::UI::Xaml::Controls::SemanticZoom & owner);
};

struct WINRT_EBO SettingsFlyoutAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::ISettingsFlyoutAutomationPeer,
    impl::bases<SettingsFlyoutAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<SettingsFlyoutAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    SettingsFlyoutAutomationPeer(std::nullptr_t) noexcept {}
    SettingsFlyoutAutomationPeer(const Windows::UI::Xaml::Controls::SettingsFlyout & owner);
};

struct WINRT_EBO SliderAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::ISliderAutomationPeer,
    impl::bases<SliderAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::RangeBaseAutomationPeer>,
    impl::require<SliderAutomationPeer, Windows::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IRangeValueProvider>
{
    SliderAutomationPeer(std::nullptr_t) noexcept {}
    SliderAutomationPeer(const Windows::UI::Xaml::Controls::Slider & owner);
    using impl_IDependencyObject::SetValue;
    using impl_IRangeValueProvider::SetValue;
};

struct WINRT_EBO TextBlockAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::ITextBlockAutomationPeer,
    impl::bases<TextBlockAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<TextBlockAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    TextBlockAutomationPeer(std::nullptr_t) noexcept {}
    TextBlockAutomationPeer(const Windows::UI::Xaml::Controls::TextBlock & owner);
};

struct WINRT_EBO TextBoxAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::ITextBoxAutomationPeer,
    impl::bases<TextBoxAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<TextBoxAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    TextBoxAutomationPeer(std::nullptr_t) noexcept {}
    TextBoxAutomationPeer(const Windows::UI::Xaml::Controls::TextBox & owner);
};

struct WINRT_EBO ThumbAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IThumbAutomationPeer,
    impl::bases<ThumbAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<ThumbAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    ThumbAutomationPeer(std::nullptr_t) noexcept {}
    ThumbAutomationPeer(const Windows::UI::Xaml::Controls::Primitives::Thumb & owner);
};

struct WINRT_EBO TimePickerAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::ITimePickerAutomationPeer,
    impl::bases<TimePickerAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<TimePickerAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    TimePickerAutomationPeer(std::nullptr_t) noexcept {}
    TimePickerAutomationPeer(const Windows::UI::Xaml::Controls::TimePicker & owner);
};

struct WINRT_EBO TimePickerFlyoutPresenterAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::ITimePickerFlyoutPresenterAutomationPeer,
    impl::bases<TimePickerFlyoutPresenterAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<TimePickerFlyoutPresenterAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    TimePickerFlyoutPresenterAutomationPeer(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ToggleButtonAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeer,
    impl::bases<ToggleButtonAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Peers::ButtonBaseAutomationPeer>,
    impl::require<ToggleButtonAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IToggleProvider>
{
    ToggleButtonAutomationPeer(std::nullptr_t) noexcept {}
    ToggleButtonAutomationPeer(const Windows::UI::Xaml::Controls::Primitives::ToggleButton & owner);
};

struct WINRT_EBO ToggleMenuFlyoutItemAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IToggleMenuFlyoutItemAutomationPeer,
    impl::bases<ToggleMenuFlyoutItemAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<ToggleMenuFlyoutItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IToggleProvider>
{
    ToggleMenuFlyoutItemAutomationPeer(std::nullptr_t) noexcept {}
    ToggleMenuFlyoutItemAutomationPeer(const Windows::UI::Xaml::Controls::ToggleMenuFlyoutItem & owner);
};

struct WINRT_EBO ToggleSwitchAutomationPeer :
    Windows::UI::Xaml::Automation::Peers::IToggleSwitchAutomationPeer,
    impl::bases<ToggleSwitchAutomationPeer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Automation::Peers::AutomationPeer, Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>,
    impl::require<ToggleSwitchAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IToggleProvider>
{
    ToggleSwitchAutomationPeer(std::nullptr_t) noexcept {}
    ToggleSwitchAutomationPeer(const Windows::UI::Xaml::Controls::ToggleSwitch & owner);
};

}

}
