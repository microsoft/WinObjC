// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Controls.4.h"
#include "Windows.UI.Xaml.4.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Controls::Primitives {

template <typename D, typename ... Interfaces> struct ButtonBaseT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = ButtonBase;

protected:

    ButtonBaseT()
    {
        get_activation_factory<ButtonBase, IButtonBaseFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct CarouselPanelT :
    overrides<D, Windows::UI::Xaml::Controls::IVirtualizingPanelOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IVirtualizingPanel, Windows::UI::Xaml::Controls::IVirtualizingPanelProtected, Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo, Windows::UI::Xaml::Controls::Primitives::ICarouselPanel, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    using composable = CarouselPanel;

protected:

    CarouselPanelT()
    {
        get_activation_factory<CarouselPanel, ICarouselPanelFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct DragCompletedEventArgsT :
    overrides<D, Windows::Foundation::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::Primitives::IDragCompletedEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
    using composable = DragCompletedEventArgs;

protected:

    DragCompletedEventArgsT(double horizontalChange, double verticalChange, bool canceled)
    {
        get_activation_factory<DragCompletedEventArgs, IDragCompletedEventArgsFactory>().CreateInstanceWithHorizontalChangeVerticalChangeAndCanceled(horizontalChange, verticalChange, canceled, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct DragDeltaEventArgsT :
    overrides<D, Windows::Foundation::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::Primitives::IDragDeltaEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
    using composable = DragDeltaEventArgs;

protected:

    DragDeltaEventArgsT(double horizontalChange, double verticalChange)
    {
        get_activation_factory<DragDeltaEventArgs, IDragDeltaEventArgsFactory>().CreateInstanceWithHorizontalChangeAndVerticalChange(horizontalChange, verticalChange, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct DragStartedEventArgsT :
    overrides<D, Windows::Foundation::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::Primitives::IDragStartedEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
    using composable = DragStartedEventArgs;

protected:

    DragStartedEventArgsT(double horizontalOffset, double verticalOffset)
    {
        get_activation_factory<DragStartedEventArgs, IDragStartedEventArgsFactory>().CreateInstanceWithHorizontalOffsetAndVerticalOffset(horizontalOffset, verticalOffset, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct FlyoutBaseT :
    overrides<D, Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase2>
{
    using composable = FlyoutBase;

protected:

    FlyoutBaseT()
    {
        get_activation_factory<FlyoutBase, IFlyoutBaseFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct GridViewItemPresenterT :
    overrides<D, Windows::UI::Xaml::Controls::IContentPresenterOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentPresenter, Windows::UI::Xaml::Controls::IContentPresenter2, Windows::UI::Xaml::Controls::IContentPresenter3, Windows::UI::Xaml::Controls::IContentPresenter4, Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    using composable = GridViewItemPresenter;

protected:

    GridViewItemPresenterT()
    {
        get_activation_factory<GridViewItemPresenter, IGridViewItemPresenterFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ListViewItemPresenterT :
    overrides<D, Windows::UI::Xaml::Controls::IContentPresenterOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentPresenter, Windows::UI::Xaml::Controls::IContentPresenter2, Windows::UI::Xaml::Controls::IContentPresenter3, Windows::UI::Xaml::Controls::IContentPresenter4, Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter, Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    using composable = ListViewItemPresenter;

protected:

    ListViewItemPresenterT()
    {
        get_activation_factory<ListViewItemPresenter, IListViewItemPresenterFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct PickerFlyoutBaseT :
    overrides<D, Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IPickerFlyoutBaseOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase2, Windows::UI::Xaml::Controls::Primitives::IPickerFlyoutBase>
{
    using composable = PickerFlyoutBase;

protected:

    PickerFlyoutBaseT()
    {
        get_activation_factory<PickerFlyoutBase, IPickerFlyoutBaseFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct PivotHeaderItemT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::Primitives::IPivotHeaderItem>
{
    using composable = PivotHeaderItem;

protected:

    PivotHeaderItemT()
    {
        get_activation_factory<PivotHeaderItem, IPivotHeaderItemFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct RangeBaseT :
    overrides<D, Windows::UI::Xaml::Controls::Primitives::IRangeBaseOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::Primitives::IRangeBase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = RangeBase;

protected:

    RangeBaseT()
    {
        get_activation_factory<RangeBase, IRangeBaseFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct SelectorItemT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::ISelectorItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = SelectorItem;

protected:

    SelectorItemT()
    {
        get_activation_factory<SelectorItem, ISelectorItemFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ToggleButtonT :
    overrides<D, Windows::UI::Xaml::Controls::IContentControlOverridesT<D>, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverridesT<D>, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Windows::UI::Xaml::Controls::IControlOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlProtected, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    using composable = ToggleButton;

protected:

    ToggleButtonT()
    {
        get_activation_factory<ToggleButton, IToggleButtonFactory>().CreateInstance(*this, this->m_inner);
    }
};

}

}
