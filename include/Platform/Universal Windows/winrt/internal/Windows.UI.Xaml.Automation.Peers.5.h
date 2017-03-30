// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Automation::Peers {

template <typename D, typename ... Interfaces> struct AppBarAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IAppBarAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IExpandCollapseProvider, Windows::UI::Xaml::Automation::Provider::IToggleProvider, Windows::UI::Xaml::Automation::Provider::IWindowProvider>
{
    using composable = AppBarAutomationPeer;

protected:

    AppBarAutomationPeerT(const Windows::UI::Xaml::Controls::AppBar & owner)
    {
        get_activation_factory<AppBarAutomationPeer, IAppBarAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct AppBarButtonAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAppBarButtonAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IInvokeProvider>
{
    using composable = AppBarButtonAutomationPeer;

protected:

    AppBarButtonAutomationPeerT(const Windows::UI::Xaml::Controls::AppBarButton & owner)
    {
        get_activation_factory<AppBarButtonAutomationPeer, IAppBarButtonAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct AppBarToggleButtonAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAppBarToggleButtonAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IToggleProvider>
{
    using composable = AppBarToggleButtonAutomationPeer;

protected:

    AppBarToggleButtonAutomationPeerT(const Windows::UI::Xaml::Controls::AppBarToggleButton & owner)
    {
        get_activation_factory<AppBarToggleButtonAutomationPeer, IAppBarToggleButtonAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct AutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5>
{
    using composable = AutomationPeer;

protected:

    AutomationPeerT()
    {
        get_activation_factory<AutomationPeer, IAutomationPeerFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ButtonAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IButtonAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IInvokeProvider>
{
    using composable = ButtonAutomationPeer;

protected:

    ButtonAutomationPeerT(const Windows::UI::Xaml::Controls::Button & owner)
    {
        get_activation_factory<ButtonAutomationPeer, IButtonAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ButtonBaseAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    using composable = ButtonBaseAutomationPeer;

protected:

    ButtonBaseAutomationPeerT(const Windows::UI::Xaml::Controls::Primitives::ButtonBase & owner)
    {
        get_activation_factory<ButtonBaseAutomationPeer, IButtonBaseAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct CaptureElementAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::ICaptureElementAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    using composable = CaptureElementAutomationPeer;

protected:

    CaptureElementAutomationPeerT(const Windows::UI::Xaml::Controls::CaptureElement & owner)
    {
        get_activation_factory<CaptureElementAutomationPeer, ICaptureElementAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct CheckBoxAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeer, Windows::UI::Xaml::Automation::Peers::ICheckBoxAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IToggleProvider>
{
    using composable = CheckBoxAutomationPeer;

protected:

    CheckBoxAutomationPeerT(const Windows::UI::Xaml::Controls::CheckBox & owner)
    {
        get_activation_factory<CheckBoxAutomationPeer, ICheckBoxAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ComboBoxAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, Windows::UI::Xaml::Automation::Peers::IComboBoxAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IExpandCollapseProvider, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Provider::ISelectionProvider, Windows::UI::Xaml::Automation::Provider::IValueProvider, Windows::UI::Xaml::Automation::Provider::IWindowProvider>
{
    using composable = ComboBoxAutomationPeer;

protected:

    ComboBoxAutomationPeerT(const Windows::UI::Xaml::Controls::ComboBox & owner)
    {
        get_activation_factory<ComboBoxAutomationPeer, IComboBoxAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ComboBoxItemAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IComboBoxItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    using composable = ComboBoxItemAutomationPeer;

protected:

    ComboBoxItemAutomationPeerT(const Windows::UI::Xaml::Controls::ComboBoxItem & owner)
    {
        get_activation_factory<ComboBoxItemAutomationPeer, IComboBoxItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ComboBoxItemDataAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer, Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer, Windows::UI::Xaml::Automation::Peers::IComboBoxItemDataAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Provider::IScrollItemProvider, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider>
{
    using composable = ComboBoxItemDataAutomationPeer;

protected:

    ComboBoxItemDataAutomationPeerT(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::ComboBoxAutomationPeer & parent)
    {
        get_activation_factory<ComboBoxItemDataAutomationPeer, IComboBoxItemDataAutomationPeerFactory>().CreateInstanceWithParentAndItem(item, parent, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct DatePickerAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IDatePickerAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    using composable = DatePickerAutomationPeer;

protected:

    DatePickerAutomationPeerT(const Windows::UI::Xaml::Controls::DatePicker & owner)
    {
        get_activation_factory<DatePickerAutomationPeer, IDatePickerAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct FlipViewAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, Windows::UI::Xaml::Automation::Peers::IFlipViewAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Provider::ISelectionProvider>
{
    using composable = FlipViewAutomationPeer;

protected:

    FlipViewAutomationPeerT(const Windows::UI::Xaml::Controls::FlipView & owner)
    {
        get_activation_factory<FlipViewAutomationPeer, IFlipViewAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct FlipViewItemAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IFlipViewItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    using composable = FlipViewItemAutomationPeer;

protected:

    FlipViewItemAutomationPeerT(const Windows::UI::Xaml::Controls::FlipViewItem & owner)
    {
        get_activation_factory<FlipViewItemAutomationPeer, IFlipViewItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct FlipViewItemDataAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer, Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer, Windows::UI::Xaml::Automation::Peers::IFlipViewItemDataAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Provider::IScrollItemProvider, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider>
{
    using composable = FlipViewItemDataAutomationPeer;

protected:

    FlipViewItemDataAutomationPeerT(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::FlipViewAutomationPeer & parent)
    {
        get_activation_factory<FlipViewItemDataAutomationPeer, IFlipViewItemDataAutomationPeerFactory>().CreateInstanceWithParentAndItem(item, parent, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct FlyoutPresenterAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IFlyoutPresenterAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    using composable = FlyoutPresenterAutomationPeer;

protected:

    FlyoutPresenterAutomationPeerT(const Windows::UI::Xaml::Controls::FlyoutPresenter & owner)
    {
        get_activation_factory<FlyoutPresenterAutomationPeer, IFlyoutPresenterAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct FrameworkElementAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    using composable = FrameworkElementAutomationPeer;

protected:

    FrameworkElementAutomationPeerT(const Windows::UI::Xaml::FrameworkElement & owner)
    {
        get_activation_factory<FrameworkElementAutomationPeer, IFrameworkElementAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct GridViewAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, Windows::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IGridViewAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IDropTargetProvider, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Provider::ISelectionProvider>
{
    using composable = GridViewAutomationPeer;

protected:

    GridViewAutomationPeerT(const Windows::UI::Xaml::Controls::GridView & owner)
    {
        get_activation_factory<GridViewAutomationPeer, IGridViewAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct GridViewHeaderItemAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeer, Windows::UI::Xaml::Automation::Peers::IGridViewHeaderItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    using composable = GridViewHeaderItemAutomationPeer;

protected:

    GridViewHeaderItemAutomationPeerT(const Windows::UI::Xaml::Controls::GridViewHeaderItem & owner)
    {
        get_activation_factory<GridViewHeaderItemAutomationPeer, IGridViewHeaderItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct GridViewItemAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IGridViewItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    using composable = GridViewItemAutomationPeer;

protected:

    GridViewItemAutomationPeerT(const Windows::UI::Xaml::Controls::GridViewItem & owner)
    {
        get_activation_factory<GridViewItemAutomationPeer, IGridViewItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct GridViewItemDataAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer, Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer, Windows::UI::Xaml::Automation::Peers::IGridViewItemDataAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Provider::IScrollItemProvider, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider>
{
    using composable = GridViewItemDataAutomationPeer;

protected:

    GridViewItemDataAutomationPeerT(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::GridViewAutomationPeer & parent)
    {
        get_activation_factory<GridViewItemDataAutomationPeer, IGridViewItemDataAutomationPeerFactory>().CreateInstanceWithParentAndItem(item, parent, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct GroupItemAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IGroupItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    using composable = GroupItemAutomationPeer;

protected:

    GroupItemAutomationPeerT(const Windows::UI::Xaml::Controls::GroupItem & owner)
    {
        get_activation_factory<GroupItemAutomationPeer, IGroupItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct HubAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IHubAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    using composable = HubAutomationPeer;

protected:

    HubAutomationPeerT(const Windows::UI::Xaml::Controls::Hub & owner)
    {
        get_activation_factory<HubAutomationPeer, IHubAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct HubSectionAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IHubSectionAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IScrollItemProvider>
{
    using composable = HubSectionAutomationPeer;

protected:

    HubSectionAutomationPeerT(const Windows::UI::Xaml::Controls::HubSection & owner)
    {
        get_activation_factory<HubSectionAutomationPeer, IHubSectionAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct HyperlinkButtonAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IHyperlinkButtonAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IInvokeProvider>
{
    using composable = HyperlinkButtonAutomationPeer;

protected:

    HyperlinkButtonAutomationPeerT(const Windows::UI::Xaml::Controls::HyperlinkButton & owner)
    {
        get_activation_factory<HyperlinkButtonAutomationPeer, IHyperlinkButtonAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ImageAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IImageAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    using composable = ImageAutomationPeer;

protected:

    ImageAutomationPeerT(const Windows::UI::Xaml::Controls::Image & owner)
    {
        get_activation_factory<ImageAutomationPeer, IImageAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ItemAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider>
{
    using composable = ItemAutomationPeer;

protected:

    ItemAutomationPeerT(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer & parent)
    {
        get_activation_factory<ItemAutomationPeer, IItemAutomationPeerFactory>().CreateInstanceWithParentAndItem(item, parent, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ItemsControlAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider>
{
    using composable = ItemsControlAutomationPeer;

protected:

    ItemsControlAutomationPeerT(const Windows::UI::Xaml::Controls::ItemsControl & owner)
    {
        get_activation_factory<ItemsControlAutomationPeer, IItemsControlAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListBoxAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, Windows::UI::Xaml::Automation::Peers::IListBoxAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Provider::ISelectionProvider>
{
    using composable = ListBoxAutomationPeer;

protected:

    ListBoxAutomationPeerT(const Windows::UI::Xaml::Controls::ListBox & owner)
    {
        get_activation_factory<ListBoxAutomationPeer, IListBoxAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListBoxItemAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IListBoxItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    using composable = ListBoxItemAutomationPeer;

protected:

    ListBoxItemAutomationPeerT(const Windows::UI::Xaml::Controls::ListBoxItem & owner)
    {
        get_activation_factory<ListBoxItemAutomationPeer, IListBoxItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListBoxItemDataAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer, Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer, Windows::UI::Xaml::Automation::Peers::IListBoxItemDataAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Provider::IScrollItemProvider, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider>
{
    using composable = ListBoxItemDataAutomationPeer;

protected:

    ListBoxItemDataAutomationPeerT(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::ListBoxAutomationPeer & parent)
    {
        get_activation_factory<ListBoxItemDataAutomationPeer, IListBoxItemDataAutomationPeerFactory>().CreateInstanceWithParentAndItem(item, parent, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListViewAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, Windows::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IListViewAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IDropTargetProvider, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Provider::ISelectionProvider>
{
    using composable = ListViewAutomationPeer;

protected:

    ListViewAutomationPeerT(const Windows::UI::Xaml::Controls::ListView & owner)
    {
        get_activation_factory<ListViewAutomationPeer, IListViewAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListViewBaseAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, Windows::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IDropTargetProvider, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Provider::ISelectionProvider>
{
    using composable = ListViewBaseAutomationPeer;

protected:

    ListViewBaseAutomationPeerT(const Windows::UI::Xaml::Controls::ListViewBase & owner)
    {
        get_activation_factory<ListViewBaseAutomationPeer, IListViewBaseAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListViewBaseHeaderItemAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    using composable = ListViewBaseHeaderItemAutomationPeer;

protected:

    ListViewBaseHeaderItemAutomationPeerT(const Windows::UI::Xaml::Controls::ListViewBaseHeaderItem & owner)
    {
        get_activation_factory<ListViewBaseHeaderItemAutomationPeer, IListViewBaseHeaderItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListViewHeaderItemAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeer, Windows::UI::Xaml::Automation::Peers::IListViewHeaderItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    using composable = ListViewHeaderItemAutomationPeer;

protected:

    ListViewHeaderItemAutomationPeerT(const Windows::UI::Xaml::Controls::ListViewHeaderItem & owner)
    {
        get_activation_factory<ListViewHeaderItemAutomationPeer, IListViewHeaderItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListViewItemAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IListViewItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    using composable = ListViewItemAutomationPeer;

protected:

    ListViewItemAutomationPeerT(const Windows::UI::Xaml::Controls::ListViewItem & owner)
    {
        get_activation_factory<ListViewItemAutomationPeer, IListViewItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListViewItemDataAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer, Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer, Windows::UI::Xaml::Automation::Peers::IListViewItemDataAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Provider::IScrollItemProvider, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider>
{
    using composable = ListViewItemDataAutomationPeer;

protected:

    ListViewItemDataAutomationPeerT(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::ListViewBaseAutomationPeer & parent)
    {
        get_activation_factory<ListViewItemDataAutomationPeer, IListViewItemDataAutomationPeerFactory>().CreateInstanceWithParentAndItem(item, parent, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct MediaElementAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IMediaElementAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    using composable = MediaElementAutomationPeer;

protected:

    MediaElementAutomationPeerT(const Windows::UI::Xaml::Controls::MediaElement & owner)
    {
        get_activation_factory<MediaElementAutomationPeer, IMediaElementAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct MediaPlayerElementAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IMediaPlayerElementAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    using composable = MediaPlayerElementAutomationPeer;

protected:

    MediaPlayerElementAutomationPeerT(const Windows::UI::Xaml::Controls::MediaPlayerElement & owner)
    {
        get_activation_factory<MediaPlayerElementAutomationPeer, IMediaPlayerElementAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct MediaTransportControlsAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IMediaTransportControlsAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    using composable = MediaTransportControlsAutomationPeer;

protected:

    MediaTransportControlsAutomationPeerT(const Windows::UI::Xaml::Controls::MediaTransportControls & owner)
    {
        get_activation_factory<MediaTransportControlsAutomationPeer, IMediaTransportControlsAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct MenuFlyoutItemAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IMenuFlyoutItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IInvokeProvider>
{
    using composable = MenuFlyoutItemAutomationPeer;

protected:

    MenuFlyoutItemAutomationPeerT(const Windows::UI::Xaml::Controls::MenuFlyoutItem & owner)
    {
        get_activation_factory<MenuFlyoutItemAutomationPeer, IMenuFlyoutItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct MenuFlyoutPresenterAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IMenuFlyoutPresenterAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider>
{
    using composable = MenuFlyoutPresenterAutomationPeer;

protected:

    MenuFlyoutPresenterAutomationPeerT(const Windows::UI::Xaml::Controls::MenuFlyoutPresenter & owner)
    {
        get_activation_factory<MenuFlyoutPresenterAutomationPeer, IMenuFlyoutPresenterAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct PasswordBoxAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IPasswordBoxAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    using composable = PasswordBoxAutomationPeer;

protected:

    PasswordBoxAutomationPeerT(const Windows::UI::Xaml::Controls::PasswordBox & owner)
    {
        get_activation_factory<PasswordBoxAutomationPeer, IPasswordBoxAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ProgressBarAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IProgressBarAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IRangeValueProvider>
{
    using composable = ProgressBarAutomationPeer;

protected:

    ProgressBarAutomationPeerT(const Windows::UI::Xaml::Controls::ProgressBar & owner)
    {
        get_activation_factory<ProgressBarAutomationPeer, IProgressBarAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ProgressRingAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IProgressRingAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    using composable = ProgressRingAutomationPeer;

protected:

    ProgressRingAutomationPeerT(const Windows::UI::Xaml::Controls::ProgressRing & owner)
    {
        get_activation_factory<ProgressRingAutomationPeer, IProgressRingAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct RadioButtonAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeer, Windows::UI::Xaml::Automation::Peers::IRadioButtonAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider, Windows::UI::Xaml::Automation::Provider::IToggleProvider>
{
    using composable = RadioButtonAutomationPeer;

protected:

    RadioButtonAutomationPeerT(const Windows::UI::Xaml::Controls::RadioButton & owner)
    {
        get_activation_factory<RadioButtonAutomationPeer, IRadioButtonAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct RangeBaseAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IRangeValueProvider>
{
    using composable = RangeBaseAutomationPeer;

protected:

    RangeBaseAutomationPeerT(const Windows::UI::Xaml::Controls::Primitives::RangeBase & owner)
    {
        get_activation_factory<RangeBaseAutomationPeer, IRangeBaseAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct RepeatButtonAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IRepeatButtonAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IInvokeProvider>
{
    using composable = RepeatButtonAutomationPeer;

protected:

    RepeatButtonAutomationPeerT(const Windows::UI::Xaml::Controls::Primitives::RepeatButton & owner)
    {
        get_activation_factory<RepeatButtonAutomationPeer, IRepeatButtonAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct RichEditBoxAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IRichEditBoxAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    using composable = RichEditBoxAutomationPeer;

protected:

    RichEditBoxAutomationPeerT(const Windows::UI::Xaml::Controls::RichEditBox & owner)
    {
        get_activation_factory<RichEditBoxAutomationPeer, IRichEditBoxAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct RichTextBlockAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IRichTextBlockAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    using composable = RichTextBlockAutomationPeer;

protected:

    RichTextBlockAutomationPeerT(const Windows::UI::Xaml::Controls::RichTextBlock & owner)
    {
        get_activation_factory<RichTextBlockAutomationPeer, IRichTextBlockAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct RichTextBlockOverflowAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IRichTextBlockOverflowAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    using composable = RichTextBlockOverflowAutomationPeer;

protected:

    RichTextBlockOverflowAutomationPeerT(const Windows::UI::Xaml::Controls::RichTextBlockOverflow & owner)
    {
        get_activation_factory<RichTextBlockOverflowAutomationPeer, IRichTextBlockOverflowAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ScrollBarAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IScrollBarAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IRangeValueProvider>
{
    using composable = ScrollBarAutomationPeer;

protected:

    ScrollBarAutomationPeerT(const Windows::UI::Xaml::Controls::Primitives::ScrollBar & owner)
    {
        get_activation_factory<ScrollBarAutomationPeer, IScrollBarAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ScrollViewerAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IScrollViewerAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IScrollProvider>
{
    using composable = ScrollViewerAutomationPeer;

protected:

    ScrollViewerAutomationPeerT(const Windows::UI::Xaml::Controls::ScrollViewer & owner)
    {
        get_activation_factory<ScrollViewerAutomationPeer, IScrollViewerAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct SearchBoxAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::ISearchBoxAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    using composable = SearchBoxAutomationPeer;

protected:

    SearchBoxAutomationPeerT(const Windows::UI::Xaml::Controls::SearchBox & owner)
    {
        get_activation_factory<SearchBoxAutomationPeer, ISearchBoxAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct SelectorAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, Windows::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IItemContainerProvider, Windows::UI::Xaml::Automation::Provider::ISelectionProvider>
{
    using composable = SelectorAutomationPeer;

protected:

    SelectorAutomationPeerT(const Windows::UI::Xaml::Controls::Primitives::Selector & owner)
    {
        get_activation_factory<SelectorAutomationPeer, ISelectorAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct SelectorItemAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer, Windows::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider, Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider>
{
    using composable = SelectorItemAutomationPeer;

protected:

    SelectorItemAutomationPeerT(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::Automation::Peers::SelectorAutomationPeer & parent)
    {
        get_activation_factory<SelectorItemAutomationPeer, ISelectorItemAutomationPeerFactory>().CreateInstanceWithParentAndItem(item, parent, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct SemanticZoomAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::ISemanticZoomAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IToggleProvider>
{
    using composable = SemanticZoomAutomationPeer;

protected:

    SemanticZoomAutomationPeerT(const Windows::UI::Xaml::Controls::SemanticZoom & owner)
    {
        get_activation_factory<SemanticZoomAutomationPeer, ISemanticZoomAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct SettingsFlyoutAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::ISettingsFlyoutAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    using composable = SettingsFlyoutAutomationPeer;

protected:

    SettingsFlyoutAutomationPeerT(const Windows::UI::Xaml::Controls::SettingsFlyout & owner)
    {
        get_activation_factory<SettingsFlyoutAutomationPeer, ISettingsFlyoutAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct SliderAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::ISliderAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IRangeValueProvider>
{
    using composable = SliderAutomationPeer;

protected:

    SliderAutomationPeerT(const Windows::UI::Xaml::Controls::Slider & owner)
    {
        get_activation_factory<SliderAutomationPeer, ISliderAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct TextBlockAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::ITextBlockAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    using composable = TextBlockAutomationPeer;

protected:

    TextBlockAutomationPeerT(const Windows::UI::Xaml::Controls::TextBlock & owner)
    {
        get_activation_factory<TextBlockAutomationPeer, ITextBlockAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct TextBoxAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::ITextBoxAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    using composable = TextBoxAutomationPeer;

protected:

    TextBoxAutomationPeerT(const Windows::UI::Xaml::Controls::TextBox & owner)
    {
        get_activation_factory<TextBoxAutomationPeer, ITextBoxAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ThumbAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IThumbAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    using composable = ThumbAutomationPeer;

protected:

    ThumbAutomationPeerT(const Windows::UI::Xaml::Controls::Primitives::Thumb & owner)
    {
        get_activation_factory<ThumbAutomationPeer, IThumbAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct TimePickerAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::ITimePickerAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
{
    using composable = TimePickerAutomationPeer;

protected:

    TimePickerAutomationPeerT(const Windows::UI::Xaml::Controls::TimePicker & owner)
    {
        get_activation_factory<TimePickerAutomationPeer, ITimePickerAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ToggleButtonAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, Windows::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IToggleProvider>
{
    using composable = ToggleButtonAutomationPeer;

protected:

    ToggleButtonAutomationPeerT(const Windows::UI::Xaml::Controls::Primitives::ToggleButton & owner)
    {
        get_activation_factory<ToggleButtonAutomationPeer, IToggleButtonAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ToggleMenuFlyoutItemAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IToggleMenuFlyoutItemAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IToggleProvider>
{
    using composable = ToggleMenuFlyoutItemAutomationPeer;

protected:

    ToggleMenuFlyoutItemAutomationPeerT(const Windows::UI::Xaml::Controls::ToggleMenuFlyoutItem & owner)
    {
        get_activation_factory<ToggleMenuFlyoutItemAutomationPeer, IToggleMenuFlyoutItemAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ToggleSwitchAutomationPeerT :
    overrides<D, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Automation::Peers::IToggleSwitchAutomationPeer, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer, Windows::UI::Xaml::Automation::Peers::IAutomationPeerProtected, Windows::UI::Xaml::Automation::Peers::IAutomationPeer2, Windows::UI::Xaml::Automation::Peers::IAutomationPeer3, Windows::UI::Xaml::Automation::Peers::IAutomationPeer4, Windows::UI::Xaml::Automation::Peers::IAutomationPeer5, Windows::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, Windows::UI::Xaml::Automation::Provider::IToggleProvider>
{
    using composable = ToggleSwitchAutomationPeer;

protected:

    ToggleSwitchAutomationPeerT(const Windows::UI::Xaml::Controls::ToggleSwitch & owner)
    {
        get_activation_factory<ToggleSwitchAutomationPeer, IToggleSwitchAutomationPeerFactory>().CreateInstanceWithOwner(owner, *this, this->m_inner);
    }
};

}

}
