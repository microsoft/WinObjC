// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Controls.Primitives.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Controls::Primitives {

template <typename H> struct impl_DragCompletedEventHandler : implements<impl_DragCompletedEventHandler<H>, abi<DragCompletedEventHandler>>, H
{
    impl_DragCompletedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Controls::Primitives::IDragCompletedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Controls::Primitives::DragCompletedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_DragDeltaEventHandler : implements<impl_DragDeltaEventHandler<H>, abi<DragDeltaEventHandler>>, H
{
    impl_DragDeltaEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Controls::Primitives::IDragDeltaEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Controls::Primitives::DragDeltaEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_DragStartedEventHandler : implements<impl_DragStartedEventHandler<H>, abi<DragStartedEventHandler>>, H
{
    impl_DragStartedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Controls::Primitives::IDragStartedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Controls::Primitives::DragStartedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_ItemsChangedEventHandler : implements<impl_ItemsChangedEventHandler<H>, abi<ItemsChangedEventHandler>>, H
{
    impl_ItemsChangedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Controls::Primitives::IItemsChangedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Controls::Primitives::ItemsChangedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_RangeBaseValueChangedEventHandler : implements<impl_RangeBaseValueChangedEventHandler<H>, abi<RangeBaseValueChangedEventHandler>>, H
{
    impl_RangeBaseValueChangedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Controls::Primitives::IRangeBaseValueChangedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Controls::Primitives::RangeBaseValueChangedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_ScrollEventHandler : implements<impl_ScrollEventHandler<H>, abi<ScrollEventHandler>>, H
{
    impl_ScrollEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Controls::Primitives::IScrollEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Controls::Primitives::ScrollEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::UI::Xaml::Controls::Primitives {

struct WINRT_EBO AppBarTemplateSettings :
    Windows::UI::Xaml::Controls::Primitives::IAppBarTemplateSettings,
    impl::bases<AppBarTemplateSettings, Windows::UI::Xaml::DependencyObject>,
    impl::require<AppBarTemplateSettings, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    AppBarTemplateSettings(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ButtonBase :
    Windows::UI::Xaml::Controls::Primitives::IButtonBase,
    impl::bases<ButtonBase, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl>,
    impl::require<ButtonBase, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    ButtonBase(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::DependencyProperty ClickModeProperty();
    static Windows::UI::Xaml::DependencyProperty IsPointerOverProperty();
    static Windows::UI::Xaml::DependencyProperty IsPressedProperty();
    static Windows::UI::Xaml::DependencyProperty CommandProperty();
    static Windows::UI::Xaml::DependencyProperty CommandParameterProperty();
};

struct WINRT_EBO CalendarPanel :
    Windows::UI::Xaml::Controls::Primitives::ICalendarPanel,
    impl::bases<CalendarPanel, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Panel>,
    impl::require<CalendarPanel, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    CalendarPanel(std::nullptr_t) noexcept {}
    CalendarPanel();
};

struct WINRT_EBO CalendarViewTemplateSettings :
    Windows::UI::Xaml::Controls::Primitives::ICalendarViewTemplateSettings,
    impl::bases<CalendarViewTemplateSettings, Windows::UI::Xaml::DependencyObject>,
    impl::require<CalendarViewTemplateSettings, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    CalendarViewTemplateSettings(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CarouselPanel :
    Windows::UI::Xaml::Controls::Primitives::ICarouselPanel,
    impl::bases<CarouselPanel, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Panel, Windows::UI::Xaml::Controls::VirtualizingPanel>,
    impl::require<CarouselPanel, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IVirtualizingPanel, Windows::UI::Xaml::Controls::IVirtualizingPanelOverrides, Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    CarouselPanel(std::nullptr_t) noexcept {}
    CarouselPanel();
};

struct WINRT_EBO ComboBoxTemplateSettings :
    Windows::UI::Xaml::Controls::Primitives::IComboBoxTemplateSettings,
    impl::bases<ComboBoxTemplateSettings, Windows::UI::Xaml::DependencyObject>,
    impl::require<ComboBoxTemplateSettings, Windows::UI::Xaml::Controls::Primitives::IComboBoxTemplateSettings2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    ComboBoxTemplateSettings(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CommandBarTemplateSettings :
    Windows::UI::Xaml::Controls::Primitives::ICommandBarTemplateSettings,
    impl::bases<CommandBarTemplateSettings, Windows::UI::Xaml::DependencyObject>,
    impl::require<CommandBarTemplateSettings, Windows::UI::Xaml::Controls::Primitives::ICommandBarTemplateSettings2, Windows::UI::Xaml::Controls::Primitives::ICommandBarTemplateSettings3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    CommandBarTemplateSettings(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DragCompletedEventArgs :
    Windows::UI::Xaml::Controls::Primitives::IDragCompletedEventArgs,
    impl::bases<DragCompletedEventArgs, Windows::UI::Xaml::RoutedEventArgs>,
    impl::require<DragCompletedEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
    DragCompletedEventArgs(std::nullptr_t) noexcept {}
    DragCompletedEventArgs(double horizontalChange, double verticalChange, bool canceled);
};

struct WINRT_EBO DragDeltaEventArgs :
    Windows::UI::Xaml::Controls::Primitives::IDragDeltaEventArgs,
    impl::bases<DragDeltaEventArgs, Windows::UI::Xaml::RoutedEventArgs>,
    impl::require<DragDeltaEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
    DragDeltaEventArgs(std::nullptr_t) noexcept {}
    DragDeltaEventArgs(double horizontalChange, double verticalChange);
};

struct WINRT_EBO DragStartedEventArgs :
    Windows::UI::Xaml::Controls::Primitives::IDragStartedEventArgs,
    impl::bases<DragStartedEventArgs, Windows::UI::Xaml::RoutedEventArgs>,
    impl::require<DragStartedEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
    DragStartedEventArgs(std::nullptr_t) noexcept {}
    DragStartedEventArgs(double horizontalOffset, double verticalOffset);
};

struct WINRT_EBO FlyoutBase :
    Windows::UI::Xaml::Controls::Primitives::IFlyoutBase,
    impl::bases<FlyoutBase, Windows::UI::Xaml::DependencyObject>,
    impl::require<FlyoutBase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseOverrides, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase2>
{
    FlyoutBase(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::DependencyProperty PlacementProperty();
    static Windows::UI::Xaml::DependencyProperty AttachedFlyoutProperty();
    static Windows::UI::Xaml::Controls::Primitives::FlyoutBase GetAttachedFlyout(const Windows::UI::Xaml::FrameworkElement & element);
    static void SetAttachedFlyout(const Windows::UI::Xaml::FrameworkElement & element, const Windows::UI::Xaml::Controls::Primitives::FlyoutBase & value);
    static void ShowAttachedFlyout(const Windows::UI::Xaml::FrameworkElement & flyoutOwner);
    static Windows::UI::Xaml::DependencyProperty AllowFocusOnInteractionProperty();
    static Windows::UI::Xaml::DependencyProperty LightDismissOverlayModeProperty();
    static Windows::UI::Xaml::DependencyProperty AllowFocusWhenDisabledProperty();
    static Windows::UI::Xaml::DependencyProperty ElementSoundModeProperty();
};

struct WINRT_EBO FlyoutBaseClosingEventArgs :
    Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseClosingEventArgs
{
    FlyoutBaseClosingEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO GeneratorPositionHelper :
    Windows::UI::Xaml::Controls::Primitives::IGeneratorPositionHelper
{
    GeneratorPositionHelper(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::Controls::Primitives::GeneratorPosition FromIndexAndOffset(int32_t index, int32_t offset);
};

struct WINRT_EBO GridViewItemPresenter :
    Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter,
    impl::bases<GridViewItemPresenter, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::ContentPresenter>,
    impl::require<GridViewItemPresenter, Windows::UI::Xaml::Controls::IContentPresenter, Windows::UI::Xaml::Controls::IContentPresenterOverrides, Windows::UI::Xaml::Controls::IContentPresenter2, Windows::UI::Xaml::Controls::IContentPresenter3, Windows::UI::Xaml::Controls::IContentPresenter4, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    GridViewItemPresenter(std::nullptr_t) noexcept {}
    GridViewItemPresenter();
    static Windows::UI::Xaml::DependencyProperty SelectionCheckMarkVisualEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty CheckHintBrushProperty();
    static Windows::UI::Xaml::DependencyProperty CheckSelectingBrushProperty();
    static Windows::UI::Xaml::DependencyProperty CheckBrushProperty();
    static Windows::UI::Xaml::DependencyProperty DragBackgroundProperty();
    static Windows::UI::Xaml::DependencyProperty DragForegroundProperty();
    static Windows::UI::Xaml::DependencyProperty FocusBorderBrushProperty();
    static Windows::UI::Xaml::DependencyProperty PlaceholderBackgroundProperty();
    static Windows::UI::Xaml::DependencyProperty PointerOverBackgroundProperty();
    static Windows::UI::Xaml::DependencyProperty SelectedBackgroundProperty();
    static Windows::UI::Xaml::DependencyProperty SelectedForegroundProperty();
    static Windows::UI::Xaml::DependencyProperty SelectedPointerOverBackgroundProperty();
    static Windows::UI::Xaml::DependencyProperty SelectedPointerOverBorderBrushProperty();
    static Windows::UI::Xaml::DependencyProperty SelectedBorderThicknessProperty();
    static Windows::UI::Xaml::DependencyProperty DisabledOpacityProperty();
    static Windows::UI::Xaml::DependencyProperty DragOpacityProperty();
    static Windows::UI::Xaml::DependencyProperty ReorderHintOffsetProperty();
    [[deprecated("Use ContentPresenter.HorizontalContentAlignment instead of GridViewItemPresenterHorizontalContentAlignment. For more info, see MSDN.")]] static Windows::UI::Xaml::DependencyProperty GridViewItemPresenterHorizontalContentAlignmentProperty();
    [[deprecated("Use ContentPresenter.VerticalContentAlignment instead of GridViewItemPresenterVerticalContentAlignment. For more info, see MSDN.")]] static Windows::UI::Xaml::DependencyProperty GridViewItemPresenterVerticalContentAlignmentProperty();
    [[deprecated("Use ContentPresenter.Padding instead of GridViewItemPresenterPadding. For more info, see MSDN.")]] static Windows::UI::Xaml::DependencyProperty GridViewItemPresenterPaddingProperty();
    static Windows::UI::Xaml::DependencyProperty PointerOverBackgroundMarginProperty();
    static Windows::UI::Xaml::DependencyProperty ContentMarginProperty();
};

struct WINRT_EBO GridViewItemTemplateSettings :
    Windows::UI::Xaml::Controls::Primitives::IGridViewItemTemplateSettings,
    impl::bases<GridViewItemTemplateSettings, Windows::UI::Xaml::DependencyObject>,
    impl::require<GridViewItemTemplateSettings, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    GridViewItemTemplateSettings(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ItemsChangedEventArgs :
    Windows::UI::Xaml::Controls::Primitives::IItemsChangedEventArgs
{
    ItemsChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO JumpListItemBackgroundConverter :
    Windows::UI::Xaml::Controls::Primitives::IJumpListItemBackgroundConverter,
    impl::bases<JumpListItemBackgroundConverter, Windows::UI::Xaml::DependencyObject>,
    impl::require<JumpListItemBackgroundConverter, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Data::IValueConverter>
{
    JumpListItemBackgroundConverter(std::nullptr_t) noexcept {}
    JumpListItemBackgroundConverter();
    static Windows::UI::Xaml::DependencyProperty EnabledProperty();
    static Windows::UI::Xaml::DependencyProperty DisabledProperty();
};

struct WINRT_EBO JumpListItemForegroundConverter :
    Windows::UI::Xaml::Controls::Primitives::IJumpListItemForegroundConverter,
    impl::bases<JumpListItemForegroundConverter, Windows::UI::Xaml::DependencyObject>,
    impl::require<JumpListItemForegroundConverter, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Data::IValueConverter>
{
    JumpListItemForegroundConverter(std::nullptr_t) noexcept {}
    JumpListItemForegroundConverter();
    static Windows::UI::Xaml::DependencyProperty EnabledProperty();
    static Windows::UI::Xaml::DependencyProperty DisabledProperty();
};

struct WINRT_EBO LayoutInformation :
    Windows::UI::Xaml::Controls::Primitives::ILayoutInformation
{
    LayoutInformation(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::UIElement GetLayoutExceptionElement(const Windows::Foundation::IInspectable & dispatcher);
    static Windows::Foundation::Rect GetLayoutSlot(const Windows::UI::Xaml::FrameworkElement & element);
};

struct WINRT_EBO ListViewItemPresenter :
    Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter,
    impl::bases<ListViewItemPresenter, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::ContentPresenter>,
    impl::require<ListViewItemPresenter, Windows::UI::Xaml::Controls::IContentPresenter, Windows::UI::Xaml::Controls::IContentPresenterOverrides, Windows::UI::Xaml::Controls::IContentPresenter2, Windows::UI::Xaml::Controls::IContentPresenter3, Windows::UI::Xaml::Controls::IContentPresenter4, Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    ListViewItemPresenter(std::nullptr_t) noexcept {}
    ListViewItemPresenter();
    static Windows::UI::Xaml::DependencyProperty SelectionCheckMarkVisualEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty CheckHintBrushProperty();
    static Windows::UI::Xaml::DependencyProperty CheckSelectingBrushProperty();
    static Windows::UI::Xaml::DependencyProperty CheckBrushProperty();
    static Windows::UI::Xaml::DependencyProperty DragBackgroundProperty();
    static Windows::UI::Xaml::DependencyProperty DragForegroundProperty();
    static Windows::UI::Xaml::DependencyProperty FocusBorderBrushProperty();
    static Windows::UI::Xaml::DependencyProperty PlaceholderBackgroundProperty();
    static Windows::UI::Xaml::DependencyProperty PointerOverBackgroundProperty();
    static Windows::UI::Xaml::DependencyProperty SelectedBackgroundProperty();
    static Windows::UI::Xaml::DependencyProperty SelectedForegroundProperty();
    static Windows::UI::Xaml::DependencyProperty SelectedPointerOverBackgroundProperty();
    static Windows::UI::Xaml::DependencyProperty SelectedPointerOverBorderBrushProperty();
    static Windows::UI::Xaml::DependencyProperty SelectedBorderThicknessProperty();
    static Windows::UI::Xaml::DependencyProperty DisabledOpacityProperty();
    static Windows::UI::Xaml::DependencyProperty DragOpacityProperty();
    static Windows::UI::Xaml::DependencyProperty ReorderHintOffsetProperty();
    [[deprecated("Use ContentPresenter.HorizontalContentAlignment instead of ListViewItemPresenterHorizontalContentAlignment. For more info, see MSDN.")]] static Windows::UI::Xaml::DependencyProperty ListViewItemPresenterHorizontalContentAlignmentProperty();
    [[deprecated("Use ContentPresenter.VerticalContentAlignment instead of ListViewItemPresenterVerticalContentAlignment. For more info, see MSDN.")]] static Windows::UI::Xaml::DependencyProperty ListViewItemPresenterVerticalContentAlignmentProperty();
    [[deprecated("Use ContentPresenter.Padding instead of GridViewItemPresenterPadding. For more info, see MSDN.")]] static Windows::UI::Xaml::DependencyProperty ListViewItemPresenterPaddingProperty();
    static Windows::UI::Xaml::DependencyProperty PointerOverBackgroundMarginProperty();
    static Windows::UI::Xaml::DependencyProperty ContentMarginProperty();
    static Windows::UI::Xaml::DependencyProperty SelectedPressedBackgroundProperty();
    static Windows::UI::Xaml::DependencyProperty PressedBackgroundProperty();
    static Windows::UI::Xaml::DependencyProperty CheckBoxBrushProperty();
    static Windows::UI::Xaml::DependencyProperty FocusSecondaryBorderBrushProperty();
    static Windows::UI::Xaml::DependencyProperty CheckModeProperty();
    static Windows::UI::Xaml::DependencyProperty PointerOverForegroundProperty();
};

struct WINRT_EBO ListViewItemTemplateSettings :
    Windows::UI::Xaml::Controls::Primitives::IListViewItemTemplateSettings,
    impl::bases<ListViewItemTemplateSettings, Windows::UI::Xaml::DependencyObject>,
    impl::require<ListViewItemTemplateSettings, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    ListViewItemTemplateSettings(std::nullptr_t) noexcept {}
};

struct WINRT_EBO LoopingSelector :
    Windows::UI::Xaml::Controls::Primitives::ILoopingSelector,
    impl::bases<LoopingSelector, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control>,
    impl::require<LoopingSelector, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    LoopingSelector(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::DependencyProperty ShouldLoopProperty();
    static Windows::UI::Xaml::DependencyProperty ItemsProperty();
    static Windows::UI::Xaml::DependencyProperty SelectedIndexProperty();
    static Windows::UI::Xaml::DependencyProperty SelectedItemProperty();
    static Windows::UI::Xaml::DependencyProperty ItemWidthProperty();
    static Windows::UI::Xaml::DependencyProperty ItemHeightProperty();
    static Windows::UI::Xaml::DependencyProperty ItemTemplateProperty();
};

struct WINRT_EBO LoopingSelectorItem :
    Windows::UI::Xaml::Controls::Primitives::ILoopingSelectorItem,
    impl::bases<LoopingSelectorItem, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl>,
    impl::require<LoopingSelectorItem, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    LoopingSelectorItem(std::nullptr_t) noexcept {}
};

struct WINRT_EBO LoopingSelectorPanel :
    Windows::UI::Xaml::Controls::Primitives::ILoopingSelectorPanel,
    impl::bases<LoopingSelectorPanel, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Panel, Windows::UI::Xaml::Controls::Canvas>,
    impl::require<LoopingSelectorPanel, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::ICanvas, Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    LoopingSelectorPanel(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MenuFlyoutPresenterTemplateSettings :
    Windows::UI::Xaml::Controls::Primitives::IMenuFlyoutPresenterTemplateSettings,
    impl::bases<MenuFlyoutPresenterTemplateSettings, Windows::UI::Xaml::DependencyObject>,
    impl::require<MenuFlyoutPresenterTemplateSettings, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    MenuFlyoutPresenterTemplateSettings(std::nullptr_t) noexcept {}
};

struct WINRT_EBO OrientedVirtualizingPanel :
    Windows::UI::Xaml::Controls::Primitives::IOrientedVirtualizingPanel,
    impl::bases<OrientedVirtualizingPanel, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Panel, Windows::UI::Xaml::Controls::VirtualizingPanel>,
    impl::require<OrientedVirtualizingPanel, Windows::UI::Xaml::Controls::IInsertionPanel, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IVirtualizingPanel, Windows::UI::Xaml::Controls::IVirtualizingPanelOverrides, Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    OrientedVirtualizingPanel(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PickerFlyoutBase :
    Windows::UI::Xaml::Controls::Primitives::IPickerFlyoutBase,
    impl::bases<PickerFlyoutBase, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Controls::Primitives::FlyoutBase>,
    impl::require<PickerFlyoutBase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase, Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseOverrides, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase2, Windows::UI::Xaml::Controls::Primitives::IPickerFlyoutBaseOverrides>
{
    PickerFlyoutBase(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::DependencyProperty TitleProperty();
    static hstring GetTitle(const Windows::UI::Xaml::DependencyObject & element);
    static void SetTitle(const Windows::UI::Xaml::DependencyObject & element, hstring_view value);
};

struct WINRT_EBO PivotHeaderItem :
    Windows::UI::Xaml::Controls::Primitives::IPivotHeaderItem,
    impl::bases<PivotHeaderItem, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl>,
    impl::require<PivotHeaderItem, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    PivotHeaderItem(std::nullptr_t) noexcept {}
    PivotHeaderItem();
};

struct WINRT_EBO PivotHeaderPanel :
    Windows::UI::Xaml::Controls::Primitives::IPivotHeaderPanel,
    impl::bases<PivotHeaderPanel, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Panel, Windows::UI::Xaml::Controls::Canvas>,
    impl::require<PivotHeaderPanel, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::ICanvas, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    PivotHeaderPanel(std::nullptr_t) noexcept {}
    PivotHeaderPanel();
};

struct WINRT_EBO PivotPanel :
    Windows::UI::Xaml::Controls::Primitives::IPivotPanel,
    impl::bases<PivotPanel, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Panel>,
    impl::require<PivotPanel, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    PivotPanel(std::nullptr_t) noexcept {}
    PivotPanel();
};

struct WINRT_EBO Popup :
    Windows::UI::Xaml::Controls::Primitives::IPopup,
    impl::bases<Popup, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement>,
    impl::require<Popup, Windows::UI::Xaml::Controls::Primitives::IPopup2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    Popup(std::nullptr_t) noexcept {}
    Popup();
    static Windows::UI::Xaml::DependencyProperty ChildProperty();
    static Windows::UI::Xaml::DependencyProperty IsOpenProperty();
    static Windows::UI::Xaml::DependencyProperty HorizontalOffsetProperty();
    static Windows::UI::Xaml::DependencyProperty VerticalOffsetProperty();
    static Windows::UI::Xaml::DependencyProperty ChildTransitionsProperty();
    static Windows::UI::Xaml::DependencyProperty IsLightDismissEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty LightDismissOverlayModeProperty();
};

struct WINRT_EBO ProgressBarTemplateSettings :
    Windows::UI::Xaml::Controls::Primitives::IProgressBarTemplateSettings,
    impl::bases<ProgressBarTemplateSettings, Windows::UI::Xaml::DependencyObject>,
    impl::require<ProgressBarTemplateSettings, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    ProgressBarTemplateSettings(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ProgressRingTemplateSettings :
    Windows::UI::Xaml::Controls::Primitives::IProgressRingTemplateSettings,
    impl::bases<ProgressRingTemplateSettings, Windows::UI::Xaml::DependencyObject>,
    impl::require<ProgressRingTemplateSettings, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    ProgressRingTemplateSettings(std::nullptr_t) noexcept {}
};

struct WINRT_EBO RangeBase :
    Windows::UI::Xaml::Controls::Primitives::IRangeBase,
    impl::bases<RangeBase, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control>,
    impl::require<RangeBase, Windows::UI::Xaml::Controls::Primitives::IRangeBaseOverrides, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    RangeBase(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::DependencyProperty MinimumProperty();
    static Windows::UI::Xaml::DependencyProperty MaximumProperty();
    static Windows::UI::Xaml::DependencyProperty SmallChangeProperty();
    static Windows::UI::Xaml::DependencyProperty LargeChangeProperty();
    static Windows::UI::Xaml::DependencyProperty ValueProperty();
};

struct WINRT_EBO RangeBaseValueChangedEventArgs :
    Windows::UI::Xaml::Controls::Primitives::IRangeBaseValueChangedEventArgs,
    impl::bases<RangeBaseValueChangedEventArgs, Windows::UI::Xaml::RoutedEventArgs>,
    impl::require<RangeBaseValueChangedEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
    RangeBaseValueChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO RepeatButton :
    Windows::UI::Xaml::Controls::Primitives::IRepeatButton,
    impl::bases<RepeatButton, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl, Windows::UI::Xaml::Controls::Primitives::ButtonBase>,
    impl::require<RepeatButton, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    RepeatButton(std::nullptr_t) noexcept {}
    RepeatButton();
    static Windows::UI::Xaml::DependencyProperty DelayProperty();
    static Windows::UI::Xaml::DependencyProperty IntervalProperty();
};

struct WINRT_EBO ScrollBar :
    Windows::UI::Xaml::Controls::Primitives::IScrollBar,
    impl::bases<ScrollBar, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::Primitives::RangeBase>,
    impl::require<ScrollBar, Windows::UI::Xaml::Controls::Primitives::IRangeBase, Windows::UI::Xaml::Controls::Primitives::IRangeBaseOverrides, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    ScrollBar(std::nullptr_t) noexcept {}
    ScrollBar();
    static Windows::UI::Xaml::DependencyProperty OrientationProperty();
    static Windows::UI::Xaml::DependencyProperty ViewportSizeProperty();
    static Windows::UI::Xaml::DependencyProperty IndicatorModeProperty();
};

struct WINRT_EBO ScrollEventArgs :
    Windows::UI::Xaml::Controls::Primitives::IScrollEventArgs,
    impl::bases<ScrollEventArgs, Windows::UI::Xaml::RoutedEventArgs>,
    impl::require<ScrollEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
    ScrollEventArgs(std::nullptr_t) noexcept {}
    ScrollEventArgs();
};

struct WINRT_EBO Selector :
    Windows::UI::Xaml::Controls::Primitives::ISelector,
    impl::bases<Selector, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ItemsControl>,
    impl::require<Selector, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControlOverrides, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    Selector(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::DependencyProperty SelectedIndexProperty();
    static Windows::UI::Xaml::DependencyProperty SelectedItemProperty();
    static Windows::UI::Xaml::DependencyProperty SelectedValueProperty();
    static Windows::UI::Xaml::DependencyProperty SelectedValuePathProperty();
    static Windows::UI::Xaml::DependencyProperty IsSynchronizedWithCurrentItemProperty();
    static bool GetIsSelectionActive(const Windows::UI::Xaml::DependencyObject & element);
};

struct WINRT_EBO SelectorItem :
    Windows::UI::Xaml::Controls::Primitives::ISelectorItem,
    impl::bases<SelectorItem, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl>,
    impl::require<SelectorItem, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    SelectorItem(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::DependencyProperty IsSelectedProperty();
};

struct WINRT_EBO SettingsFlyoutTemplateSettings :
    Windows::UI::Xaml::Controls::Primitives::ISettingsFlyoutTemplateSettings,
    impl::bases<SettingsFlyoutTemplateSettings, Windows::UI::Xaml::DependencyObject>,
    impl::require<SettingsFlyoutTemplateSettings, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    SettingsFlyoutTemplateSettings(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SplitViewTemplateSettings :
    Windows::UI::Xaml::Controls::Primitives::ISplitViewTemplateSettings,
    impl::bases<SplitViewTemplateSettings, Windows::UI::Xaml::DependencyObject>,
    impl::require<SplitViewTemplateSettings, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    SplitViewTemplateSettings(std::nullptr_t) noexcept {}
};

struct WINRT_EBO Thumb :
    Windows::UI::Xaml::Controls::Primitives::IThumb,
    impl::bases<Thumb, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control>,
    impl::require<Thumb, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    Thumb(std::nullptr_t) noexcept {}
    Thumb();
    static Windows::UI::Xaml::DependencyProperty IsDraggingProperty();
};

struct WINRT_EBO TickBar :
    Windows::UI::Xaml::Controls::Primitives::ITickBar,
    impl::bases<TickBar, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement>,
    impl::require<TickBar, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    TickBar(std::nullptr_t) noexcept {}
    TickBar();
    static Windows::UI::Xaml::DependencyProperty FillProperty();
};

struct WINRT_EBO ToggleButton :
    Windows::UI::Xaml::Controls::Primitives::IToggleButton,
    impl::bases<ToggleButton, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl, Windows::UI::Xaml::Controls::Primitives::ButtonBase>,
    impl::require<ToggleButton, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverrides, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    ToggleButton(std::nullptr_t) noexcept {}
    ToggleButton();
    static Windows::UI::Xaml::DependencyProperty IsCheckedProperty();
    static Windows::UI::Xaml::DependencyProperty IsThreeStateProperty();
};

struct WINRT_EBO ToggleSwitchTemplateSettings :
    Windows::UI::Xaml::Controls::Primitives::IToggleSwitchTemplateSettings,
    impl::bases<ToggleSwitchTemplateSettings, Windows::UI::Xaml::DependencyObject>,
    impl::require<ToggleSwitchTemplateSettings, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    ToggleSwitchTemplateSettings(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ToolTipTemplateSettings :
    Windows::UI::Xaml::Controls::Primitives::IToolTipTemplateSettings,
    impl::bases<ToolTipTemplateSettings, Windows::UI::Xaml::DependencyObject>,
    impl::require<ToolTipTemplateSettings, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    ToolTipTemplateSettings(std::nullptr_t) noexcept {}
};

}

}
