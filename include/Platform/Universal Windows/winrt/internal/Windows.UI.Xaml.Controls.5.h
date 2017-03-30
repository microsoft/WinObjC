// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Controls.Primitives.4.h"
#include "Windows.UI.Xaml.4.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Controls {

template <typename D, typename ... Interfaces> struct AppBarT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::IAppBarOverridesT<D>, Windows::UI::Xaml::Controls::IAppBarOverrides3T<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IAppBar, Windows::UI::Xaml::Controls::IAppBar2, Windows::UI::Xaml::Controls::IAppBar3, Windows::UI::Xaml::Controls::IAppBar4, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = AppBar;

protected:

    AppBarT()
    {
        get_activation_factory<AppBar, IAppBarFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct AppBarButtonT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IButton, Windows::UI::Xaml::Controls::IButtonWithFlyout, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::ICommandBarElement, Windows::UI::Xaml::Controls::ICommandBarElement2, Windows::UI::Xaml::Controls::IAppBarButton, Windows::UI::Xaml::Controls::IAppBarButton3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = AppBarButton;

protected:

    AppBarButtonT()
    {
        get_activation_factory<AppBarButton, IAppBarButtonFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct AppBarSeparatorT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::ICommandBarElement, Windows::UI::Xaml::Controls::ICommandBarElement2, Windows::UI::Xaml::Controls::IAppBarSeparator, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = AppBarSeparator;

protected:

    AppBarSeparatorT()
    {
        get_activation_factory<AppBarSeparator, IAppBarSeparatorFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct AppBarToggleButtonT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::Controls::ICommandBarElement, Windows::UI::Xaml::Controls::ICommandBarElement2, Windows::UI::Xaml::Controls::IAppBarToggleButton, Windows::UI::Xaml::Controls::IAppBarToggleButton3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = AppBarToggleButton;

protected:

    AppBarToggleButtonT()
    {
        get_activation_factory<AppBarToggleButton, IAppBarToggleButtonFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct BitmapIconT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IIconElement, Windows::UI::Xaml::Controls::IBitmapIcon, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    using composable = BitmapIcon;

protected:

    BitmapIconT()
    {
        get_activation_factory<BitmapIcon, IBitmapIconFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ButtonT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IButton, Windows::UI::Xaml::Controls::IButtonWithFlyout, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = Button;

protected:

    ButtonT()
    {
        get_activation_factory<Button, IButtonFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct CalendarDatePickerT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::ICalendarDatePicker, Windows::UI::Xaml::Controls::ICalendarDatePicker2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = CalendarDatePicker;

protected:

    CalendarDatePickerT()
    {
        get_activation_factory<CalendarDatePicker, ICalendarDatePickerFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct CalendarViewT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::ICalendarView, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = CalendarView;

protected:

    CalendarViewT()
    {
        get_activation_factory<CalendarView, ICalendarViewFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct CalendarViewDayItemT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::ICalendarViewDayItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = CalendarViewDayItem;

protected:

    CalendarViewDayItemT()
    {
        get_activation_factory<CalendarViewDayItem, ICalendarViewDayItemFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct CanvasT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::ICanvas, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    using composable = Canvas;

protected:

    CanvasT()
    {
        get_activation_factory<Canvas, ICanvasFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct CheckBoxT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::ICheckBox, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = CheckBox;

protected:

    CheckBoxT()
    {
        get_activation_factory<CheckBox, ICheckBoxFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ComboBoxT :
    overrides<D, Windows::UI::Xaml::Controls::IItemsControlOverridesT<D>, Windows::UI::Xaml::Controls::IComboBoxOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::IComboBox, Windows::UI::Xaml::Controls::IComboBox2, Windows::UI::Xaml::Controls::IComboBox3, Windows::UI::Xaml::Controls::Primitives::ISelector, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = ComboBox;

protected:

    ComboBoxT()
    {
        get_activation_factory<ComboBox, IComboBoxFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ComboBoxItemT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IComboBoxItem, Windows::UI::Xaml::Controls::Primitives::ISelectorItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = ComboBoxItem;

protected:

    ComboBoxItemT()
    {
        get_activation_factory<ComboBoxItem, IComboBoxItemFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct CommandBarT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::IAppBarOverridesT<D>, Windows::UI::Xaml::Controls::IAppBarOverrides3T<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IAppBar, Windows::UI::Xaml::Controls::IAppBar2, Windows::UI::Xaml::Controls::IAppBar3, Windows::UI::Xaml::Controls::IAppBar4, Windows::UI::Xaml::Controls::ICommandBar, Windows::UI::Xaml::Controls::ICommandBar2, Windows::UI::Xaml::Controls::ICommandBar3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = CommandBar;

protected:

    CommandBarT()
    {
        get_activation_factory<CommandBar, ICommandBarFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct CommandBarOverflowPresenterT :
    overrides<D, Windows::UI::Xaml::Controls::IItemsControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::ICommandBarOverflowPresenter, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = CommandBarOverflowPresenter;

protected:

    CommandBarOverflowPresenterT()
    {
        get_activation_factory<CommandBarOverflowPresenter, ICommandBarOverflowPresenterFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ContentControlT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = ContentControl;

protected:

    ContentControlT()
    {
        get_activation_factory<ContentControl, IContentControlFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ContentDialogT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IContentDialog, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = ContentDialog;

protected:

    ContentDialogT()
    {
        get_activation_factory<ContentDialog, IContentDialogFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ContentPresenterT :
    overrides<D, Windows::UI::Xaml::Controls::IContentPresenterOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentPresenter, Windows::UI::Xaml::Controls::IContentPresenter2, Windows::UI::Xaml::Controls::IContentPresenter3, Windows::UI::Xaml::Controls::IContentPresenter4, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    using composable = ContentPresenter;

protected:

    ContentPresenterT()
    {
        get_activation_factory<ContentPresenter, IContentPresenterFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ControlT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = Control;

protected:

    ControlT()
    {
        get_activation_factory<Control, IControlFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct DataTemplateSelectorT :
    overrides<D, Windows::UI::Xaml::Controls::IDataTemplateSelectorOverridesT<D>, Windows::UI::Xaml::Controls::IDataTemplateSelectorOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IDataTemplateSelector, Windows::UI::Xaml::Controls::IDataTemplateSelector2>
{
    using composable = DataTemplateSelector;

protected:

    DataTemplateSelectorT()
    {
        get_activation_factory<DataTemplateSelector, IDataTemplateSelectorFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct DatePickerT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IDatePicker, Windows::UI::Xaml::Controls::IDatePicker2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = DatePicker;

protected:

    DatePickerT()
    {
        get_activation_factory<DatePicker, IDatePickerFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct FlipViewT :
    overrides<D, Windows::UI::Xaml::Controls::IItemsControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::IFlipView, Windows::UI::Xaml::Controls::IFlipView2, Windows::UI::Xaml::Controls::Primitives::ISelector, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = FlipView;

protected:

    FlipViewT()
    {
        get_activation_factory<FlipView, IFlipViewFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct FlipViewItemT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IFlipViewItem, Windows::UI::Xaml::Controls::Primitives::ISelectorItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = FlipViewItem;

protected:

    FlipViewItemT()
    {
        get_activation_factory<FlipViewItem, IFlipViewItemFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct FlyoutT :
    overrides<D, Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IFlyout, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase2>
{
    using composable = Flyout;

protected:

    FlyoutT()
    {
        get_activation_factory<Flyout, IFlyoutFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct FlyoutPresenterT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IFlyoutPresenter, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = FlyoutPresenter;

protected:

    FlyoutPresenterT()
    {
        get_activation_factory<FlyoutPresenter, IFlyoutPresenterFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct FontIconT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IIconElement, Windows::UI::Xaml::Controls::IFontIcon, Windows::UI::Xaml::Controls::IFontIcon2, Windows::UI::Xaml::Controls::IFontIcon3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    using composable = FontIcon;

protected:

    FontIconT()
    {
        get_activation_factory<FontIcon, IFontIconFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct FrameT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::INavigate, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IFrame, Windows::UI::Xaml::Controls::IFrame2, Windows::UI::Xaml::Controls::IFrame3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = Frame;

protected:

    FrameT()
    {
        get_activation_factory<Frame, IFrameFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct GridT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IGrid, Windows::UI::Xaml::Controls::IGrid2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    using composable = Grid;

protected:

    GridT()
    {
        get_activation_factory<Grid, IGridFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct GridViewT :
    overrides<D, Windows::UI::Xaml::Controls::IItemsControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::ISemanticZoomInformation, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::IListViewBase, Windows::UI::Xaml::Controls::IListViewBase2, Windows::UI::Xaml::Controls::IListViewBase3, Windows::UI::Xaml::Controls::IListViewBase4, Windows::UI::Xaml::Controls::IListViewBase5, Windows::UI::Xaml::Controls::Primitives::ISelector, Windows::UI::Xaml::Controls::IGridView, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = GridView;

protected:

    GridViewT()
    {
        get_activation_factory<GridView, IGridViewFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct GridViewHeaderItemT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IListViewBaseHeaderItem, Windows::UI::Xaml::Controls::IGridViewHeaderItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = GridViewHeaderItem;

protected:

    GridViewHeaderItemT()
    {
        get_activation_factory<GridViewHeaderItem, IGridViewHeaderItemFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct GridViewItemT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::ISelectorItem, Windows::UI::Xaml::Controls::IGridViewItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = GridViewItem;

protected:

    GridViewItemT()
    {
        get_activation_factory<GridViewItem, IGridViewItemFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct GroupItemT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IGroupItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = GroupItem;

protected:

    GroupItemT()
    {
        get_activation_factory<GroupItem, IGroupItemFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct GroupStyleT :
    overrides<D, Windows::Foundation::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IGroupStyle, Windows::UI::Xaml::Controls::IGroupStyle2, Windows::UI::Xaml::Data::INotifyPropertyChanged>
{
    using composable = GroupStyle;

protected:

    GroupStyleT()
    {
        get_activation_factory<GroupStyle, IGroupStyleFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct GroupStyleSelectorT :
    overrides<D, Windows::UI::Xaml::Controls::IGroupStyleSelectorOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IGroupStyleSelector>
{
    using composable = GroupStyleSelector;

protected:

    GroupStyleSelectorT()
    {
        get_activation_factory<GroupStyleSelector, IGroupStyleSelectorFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct HubT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::ISemanticZoomInformation, Windows::UI::Xaml::Controls::IHub, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = Hub;

protected:

    HubT()
    {
        get_activation_factory<Hub, IHubFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct HubSectionT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IHubSection, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = HubSection;

protected:

    HubSectionT()
    {
        get_activation_factory<HubSection, IHubSectionFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct HyperlinkButtonT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IHyperlinkButton, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = HyperlinkButton;

protected:

    HyperlinkButtonT()
    {
        get_activation_factory<HyperlinkButton, IHyperlinkButtonFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct InkCanvasT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IInkCanvas, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    using composable = InkCanvas;

protected:

    InkCanvasT()
    {
        get_activation_factory<InkCanvas, IInkCanvasFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct InkToolbarT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IInkToolbar>
{
    using composable = InkToolbar;

protected:

    InkToolbarT()
    {
        get_activation_factory<InkToolbar, IInkToolbarFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct InkToolbarBallpointPenButtonT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IRadioButton, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IInkToolbarToolButton, Windows::UI::Xaml::Controls::IInkToolbarPenButton, Windows::UI::Xaml::Controls::IInkToolbarBallpointPenButton>
{
    using composable = InkToolbarBallpointPenButton;

protected:

    InkToolbarBallpointPenButtonT()
    {
        get_activation_factory<InkToolbarBallpointPenButton, IInkToolbarBallpointPenButtonFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct InkToolbarCustomPenT :
    overrides<D, Windows::UI::Xaml::Controls::IInkToolbarCustomPenOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::IInkToolbarCustomPen>
{
    using composable = InkToolbarCustomPen;

protected:

    InkToolbarCustomPenT()
    {
        get_activation_factory<InkToolbarCustomPen, IInkToolbarCustomPenFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct InkToolbarCustomPenButtonT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IRadioButton, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IInkToolbarToolButton, Windows::UI::Xaml::Controls::IInkToolbarPenButton, Windows::UI::Xaml::Controls::IInkToolbarCustomPenButton>
{
    using composable = InkToolbarCustomPenButton;

protected:

    InkToolbarCustomPenButtonT()
    {
        get_activation_factory<InkToolbarCustomPenButton, IInkToolbarCustomPenButtonFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct InkToolbarCustomToggleButtonT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::ICheckBox, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IInkToolbarToggleButton, Windows::UI::Xaml::Controls::IInkToolbarCustomToggleButton>
{
    using composable = InkToolbarCustomToggleButton;

protected:

    InkToolbarCustomToggleButtonT()
    {
        get_activation_factory<InkToolbarCustomToggleButton, IInkToolbarCustomToggleButtonFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct InkToolbarCustomToolButtonT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IRadioButton, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IInkToolbarToolButton, Windows::UI::Xaml::Controls::IInkToolbarCustomToolButton>
{
    using composable = InkToolbarCustomToolButton;

protected:

    InkToolbarCustomToolButtonT()
    {
        get_activation_factory<InkToolbarCustomToolButton, IInkToolbarCustomToolButtonFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct InkToolbarEraserButtonT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IRadioButton, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IInkToolbarToolButton, Windows::UI::Xaml::Controls::IInkToolbarEraserButton>
{
    using composable = InkToolbarEraserButton;

protected:

    InkToolbarEraserButtonT()
    {
        get_activation_factory<InkToolbarEraserButton, IInkToolbarEraserButtonFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct InkToolbarHighlighterButtonT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IRadioButton, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IInkToolbarToolButton, Windows::UI::Xaml::Controls::IInkToolbarPenButton, Windows::UI::Xaml::Controls::IInkToolbarHighlighterButton>
{
    using composable = InkToolbarHighlighterButton;

protected:

    InkToolbarHighlighterButtonT()
    {
        get_activation_factory<InkToolbarHighlighterButton, IInkToolbarHighlighterButtonFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct InkToolbarPenConfigurationControlT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IInkToolbarPenConfigurationControl>
{
    using composable = InkToolbarPenConfigurationControl;

protected:

    InkToolbarPenConfigurationControlT()
    {
        get_activation_factory<InkToolbarPenConfigurationControl, IInkToolbarPenConfigurationControlFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct InkToolbarPencilButtonT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IRadioButton, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IInkToolbarToolButton, Windows::UI::Xaml::Controls::IInkToolbarPenButton, Windows::UI::Xaml::Controls::IInkToolbarPencilButton>
{
    using composable = InkToolbarPencilButton;

protected:

    InkToolbarPencilButtonT()
    {
        get_activation_factory<InkToolbarPencilButton, IInkToolbarPencilButtonFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct InkToolbarRulerButtonT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::ICheckBox, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IInkToolbarToggleButton, Windows::UI::Xaml::Controls::IInkToolbarRulerButton>
{
    using composable = InkToolbarRulerButton;

protected:

    InkToolbarRulerButtonT()
    {
        get_activation_factory<InkToolbarRulerButton, IInkToolbarRulerButtonFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ItemsControlT :
    overrides<D, Windows::UI::Xaml::Controls::IItemsControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = ItemsControl;

protected:

    ItemsControlT()
    {
        get_activation_factory<ItemsControl, IItemsControlFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListBoxT :
    overrides<D, Windows::UI::Xaml::Controls::IItemsControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::IListBox, Windows::UI::Xaml::Controls::IListBox2, Windows::UI::Xaml::Controls::Primitives::ISelector, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = ListBox;

protected:

    ListBoxT()
    {
        get_activation_factory<ListBox, IListBoxFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListBoxItemT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IListBoxItem, Windows::UI::Xaml::Controls::Primitives::ISelectorItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = ListBoxItem;

protected:

    ListBoxItemT()
    {
        get_activation_factory<ListBoxItem, IListBoxItemFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListViewT :
    overrides<D, Windows::UI::Xaml::Controls::IItemsControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::ISemanticZoomInformation, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::IListViewBase, Windows::UI::Xaml::Controls::IListViewBase2, Windows::UI::Xaml::Controls::IListViewBase3, Windows::UI::Xaml::Controls::IListViewBase4, Windows::UI::Xaml::Controls::IListViewBase5, Windows::UI::Xaml::Controls::Primitives::ISelector, Windows::UI::Xaml::Controls::IListView, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = ListView;

protected:

    ListViewT()
    {
        get_activation_factory<ListView, IListViewFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListViewBaseT :
    overrides<D, Windows::UI::Xaml::Controls::IItemsControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::ISemanticZoomInformation, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::IListViewBase, Windows::UI::Xaml::Controls::IListViewBase2, Windows::UI::Xaml::Controls::IListViewBase3, Windows::UI::Xaml::Controls::IListViewBase4, Windows::UI::Xaml::Controls::IListViewBase5, Windows::UI::Xaml::Controls::Primitives::ISelector, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = ListViewBase;

protected:

    ListViewBaseT()
    {
        get_activation_factory<ListViewBase, IListViewBaseFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListViewHeaderItemT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IListViewBaseHeaderItem, Windows::UI::Xaml::Controls::IListViewHeaderItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = ListViewHeaderItem;

protected:

    ListViewHeaderItemT()
    {
        get_activation_factory<ListViewHeaderItem, IListViewHeaderItemFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListViewItemT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::ISelectorItem, Windows::UI::Xaml::Controls::IListViewItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = ListViewItem;

protected:

    ListViewItemT()
    {
        get_activation_factory<ListViewItem, IListViewItemFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct MediaPlayerElementT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IMediaPlayerElement, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = MediaPlayerElement;

protected:

    MediaPlayerElementT()
    {
        get_activation_factory<MediaPlayerElement, IMediaPlayerElementFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct MediaPlayerPresenterT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IMediaPlayerPresenter, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    using composable = MediaPlayerPresenter;

protected:

    MediaPlayerPresenterT()
    {
        get_activation_factory<MediaPlayerPresenter, IMediaPlayerPresenterFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct MediaTransportControlsT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IMediaTransportControls, Windows::UI::Xaml::Controls::IMediaTransportControls2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = MediaTransportControls;

protected:

    MediaTransportControlsT()
    {
        get_activation_factory<MediaTransportControls, IMediaTransportControlsFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct MenuFlyoutT :
    overrides<D, Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IMenuFlyout, Windows::UI::Xaml::Controls::IMenuFlyout2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase2>
{
    using composable = MenuFlyout;

protected:

    MenuFlyoutT()
    {
        get_activation_factory<MenuFlyout, IMenuFlyoutFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct MenuFlyoutItemT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IMenuFlyoutItemBase, Windows::UI::Xaml::Controls::IMenuFlyoutItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = MenuFlyoutItem;

protected:

    MenuFlyoutItemT()
    {
        get_activation_factory<MenuFlyoutItem, IMenuFlyoutItemFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct MenuFlyoutPresenterT :
    overrides<D, Windows::UI::Xaml::Controls::IItemsControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::IMenuFlyoutPresenter, Windows::UI::Xaml::Controls::IMenuFlyoutPresenter2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = MenuFlyoutPresenter;

protected:

    MenuFlyoutPresenterT()
    {
        get_activation_factory<MenuFlyoutPresenter, IMenuFlyoutPresenterFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct MenuFlyoutSeparatorT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IMenuFlyoutItemBase, Windows::UI::Xaml::Controls::IMenuFlyoutSeparator, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = MenuFlyoutSeparator;

protected:

    MenuFlyoutSeparatorT()
    {
        get_activation_factory<MenuFlyoutSeparator, IMenuFlyoutSeparatorFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct PageT :
    overrides<D, Windows::UI::Xaml::Controls::IPageOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IUserControl, Windows::UI::Xaml::Controls::IPage, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = Page;

protected:

    PageT()
    {
        get_activation_factory<Page, IPageFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct PanelT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    using composable = Panel;

protected:

    PanelT()
    {
        get_activation_factory<Panel, IPanelFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct PathIconT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IIconElement, Windows::UI::Xaml::Controls::IPathIcon, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    using composable = PathIcon;

protected:

    PathIconT()
    {
        get_activation_factory<PathIcon, IPathIconFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct PivotT :
    overrides<D, Windows::UI::Xaml::Controls::IItemsControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IPivot, Windows::UI::Xaml::Controls::IPivot2, Windows::UI::Xaml::Controls::IPivot3>
{
    using composable = Pivot;

protected:

    PivotT()
    {
        get_activation_factory<Pivot, IPivotFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct PivotItemT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IPivotItem>
{
    using composable = PivotItem;

protected:

    PivotItemT()
    {
        get_activation_factory<PivotItem, IPivotItemFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ProgressBarT :
    overrides<D, Windows::UI::Xaml::Controls::Primitives::IRangeBaseOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IProgressBar, Windows::UI::Xaml::Controls::Primitives::IRangeBase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = ProgressBar;

protected:

    ProgressBarT()
    {
        get_activation_factory<ProgressBar, IProgressBarFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct RadioButtonT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IRadioButton, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = RadioButton;

protected:

    RadioButtonT()
    {
        get_activation_factory<RadioButton, IRadioButtonFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct RelativePanelT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IRelativePanel, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    using composable = RelativePanel;

protected:

    RelativePanelT()
    {
        get_activation_factory<RelativePanel, IRelativePanelFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct RichEditBoxT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IRichEditBox, Windows::UI::Xaml::Controls::IRichEditBox2, Windows::UI::Xaml::Controls::IRichEditBox3, Windows::UI::Xaml::Controls::IRichEditBox4, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = RichEditBox;

protected:

    RichEditBoxT()
    {
        get_activation_factory<RichEditBox, IRichEditBoxFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct SearchBoxT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::ISearchBox, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = SearchBox;

protected:

    SearchBoxT()
    {
        get_activation_factory<SearchBox, ISearchBoxFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct SelectionChangedEventArgsT :
    overrides<D, Windows::Foundation::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::ISelectionChangedEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
    using composable = SelectionChangedEventArgs;

protected:

    SelectionChangedEventArgsT(const Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> & removedItems, const Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> & addedItems)
    {
        get_activation_factory<SelectionChangedEventArgs, ISelectionChangedEventArgsFactory>().CreateInstanceWithRemovedItemsAndAddedItems(removedItems, addedItems, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct SettingsFlyoutT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::ISettingsFlyout, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = SettingsFlyout;

protected:

    SettingsFlyoutT()
    {
        get_activation_factory<SettingsFlyout, ISettingsFlyoutFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct SliderT :
    overrides<D, Windows::UI::Xaml::Controls::Primitives::IRangeBaseOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::ISlider, Windows::UI::Xaml::Controls::ISlider2, Windows::UI::Xaml::Controls::Primitives::IRangeBase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = Slider;

protected:

    SliderT()
    {
        get_activation_factory<Slider, ISliderFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct SplitViewT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::ISplitView, Windows::UI::Xaml::Controls::ISplitView2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = SplitView;

protected:

    SplitViewT()
    {
        get_activation_factory<SplitView, ISplitViewFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct StackPanelT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IInsertionPanel, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IStackPanel, Windows::UI::Xaml::Controls::IStackPanel2, Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    using composable = StackPanel;

protected:

    StackPanelT()
    {
        get_activation_factory<StackPanel, IStackPanelFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct StyleSelectorT :
    overrides<D, Windows::UI::Xaml::Controls::IStyleSelectorOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IStyleSelector>
{
    using composable = StyleSelector;

protected:

    StyleSelectorT()
    {
        get_activation_factory<StyleSelector, IStyleSelectorFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct SwapChainBackgroundPanelT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IGrid, Windows::UI::Xaml::Controls::IGrid2, Windows::UI::Xaml::Controls::ISwapChainBackgroundPanel, Windows::UI::Xaml::Controls::ISwapChainBackgroundPanel2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    using composable = SwapChainBackgroundPanel;

protected:

    SwapChainBackgroundPanelT()
    {
        get_activation_factory<SwapChainBackgroundPanel, ISwapChainBackgroundPanelFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct SwapChainPanelT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IGrid, Windows::UI::Xaml::Controls::IGrid2, Windows::UI::Xaml::Controls::ISwapChainPanel, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    using composable = SwapChainPanel;

protected:

    SwapChainPanelT()
    {
        get_activation_factory<SwapChainPanel, ISwapChainPanelFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct TextBoxT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::ITextBox, Windows::UI::Xaml::Controls::ITextBox2, Windows::UI::Xaml::Controls::ITextBox3, Windows::UI::Xaml::Controls::ITextBox4, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = TextBox;

protected:

    TextBoxT()
    {
        get_activation_factory<TextBox, ITextBoxFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct TimePickerT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::ITimePicker, Windows::UI::Xaml::Controls::ITimePicker2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = TimePicker;

protected:

    TimePickerT()
    {
        get_activation_factory<TimePicker, ITimePickerFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ToggleMenuFlyoutItemT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IMenuFlyoutItemBase, Windows::UI::Xaml::Controls::IMenuFlyoutItem, Windows::UI::Xaml::Controls::IToggleMenuFlyoutItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = ToggleMenuFlyoutItem;

protected:

    ToggleMenuFlyoutItemT()
    {
        get_activation_factory<ToggleMenuFlyoutItem, IToggleMenuFlyoutItemFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ToolTipT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IToolTip, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = ToolTip;

protected:

    ToolTipT()
    {
        get_activation_factory<ToolTip, IToolTipFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct UserControlT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IUserControl, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = UserControl;

protected:

    UserControlT()
    {
        get_activation_factory<UserControl, IUserControlFactory>().CreateInstance(*this, this->m_inner);
    }
};

}

}
