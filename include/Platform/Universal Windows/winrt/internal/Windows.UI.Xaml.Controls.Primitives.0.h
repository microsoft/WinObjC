// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Xaml::Controls::Primitives {

struct GeneratorPosition;

}

namespace Windows::UI::Xaml::Controls::Primitives {

using GeneratorPosition = ABI::Windows::UI::Xaml::Controls::Primitives::GeneratorPosition;

}

namespace ABI::Windows::UI::Xaml::Controls::Primitives {

struct DragCompletedEventHandler;
struct DragDeltaEventHandler;
struct DragStartedEventHandler;
struct IAppBarTemplateSettings;
struct IButtonBase;
struct IButtonBaseFactory;
struct IButtonBaseStatics;
struct ICalendarPanel;
struct ICalendarViewTemplateSettings;
struct ICarouselPanel;
struct ICarouselPanelFactory;
struct IComboBoxTemplateSettings;
struct IComboBoxTemplateSettings2;
struct ICommandBarTemplateSettings;
struct ICommandBarTemplateSettings2;
struct ICommandBarTemplateSettings3;
struct IDragCompletedEventArgs;
struct IDragCompletedEventArgsFactory;
struct IDragDeltaEventArgs;
struct IDragDeltaEventArgsFactory;
struct IDragStartedEventArgs;
struct IDragStartedEventArgsFactory;
struct IFlyoutBase;
struct IFlyoutBase2;
struct IFlyoutBaseClosingEventArgs;
struct IFlyoutBaseFactory;
struct IFlyoutBaseOverrides;
struct IFlyoutBaseStatics;
struct IFlyoutBaseStatics2;
struct IGeneratorPositionHelper;
struct IGeneratorPositionHelperStatics;
struct IGridViewItemPresenter;
struct IGridViewItemPresenterFactory;
struct IGridViewItemPresenterStatics;
struct IGridViewItemTemplateSettings;
struct IItemsChangedEventArgs;
struct IJumpListItemBackgroundConverter;
struct IJumpListItemBackgroundConverterStatics;
struct IJumpListItemForegroundConverter;
struct IJumpListItemForegroundConverterStatics;
struct ILayoutInformation;
struct ILayoutInformationStatics;
struct IListViewItemPresenter;
struct IListViewItemPresenter2;
struct IListViewItemPresenterFactory;
struct IListViewItemPresenterStatics;
struct IListViewItemPresenterStatics2;
struct IListViewItemTemplateSettings;
struct ILoopingSelector;
struct ILoopingSelectorItem;
struct ILoopingSelectorPanel;
struct ILoopingSelectorStatics;
struct IMenuFlyoutPresenterTemplateSettings;
struct IOrientedVirtualizingPanel;
struct IOrientedVirtualizingPanelFactory;
struct IPickerFlyoutBase;
struct IPickerFlyoutBaseFactory;
struct IPickerFlyoutBaseOverrides;
struct IPickerFlyoutBaseStatics;
struct IPivotHeaderItem;
struct IPivotHeaderItemFactory;
struct IPivotHeaderPanel;
struct IPivotPanel;
struct IPopup;
struct IPopup2;
struct IPopupStatics;
struct IPopupStatics2;
struct IProgressBarTemplateSettings;
struct IProgressRingTemplateSettings;
struct IRangeBase;
struct IRangeBaseFactory;
struct IRangeBaseOverrides;
struct IRangeBaseStatics;
struct IRangeBaseValueChangedEventArgs;
struct IRepeatButton;
struct IRepeatButtonStatics;
struct IScrollBar;
struct IScrollBarStatics;
struct IScrollEventArgs;
struct IScrollSnapPointsInfo;
struct ISelector;
struct ISelectorFactory;
struct ISelectorItem;
struct ISelectorItemFactory;
struct ISelectorItemStatics;
struct ISelectorStatics;
struct ISettingsFlyoutTemplateSettings;
struct ISplitViewTemplateSettings;
struct IThumb;
struct IThumbStatics;
struct ITickBar;
struct ITickBarStatics;
struct IToggleButton;
struct IToggleButtonFactory;
struct IToggleButtonOverrides;
struct IToggleButtonStatics;
struct IToggleSwitchTemplateSettings;
struct IToolTipTemplateSettings;
struct ItemsChangedEventHandler;
struct RangeBaseValueChangedEventHandler;
struct ScrollEventHandler;
struct AppBarTemplateSettings;
struct ButtonBase;
struct CalendarPanel;
struct CalendarViewTemplateSettings;
struct CarouselPanel;
struct ComboBoxTemplateSettings;
struct CommandBarTemplateSettings;
struct DragCompletedEventArgs;
struct DragDeltaEventArgs;
struct DragStartedEventArgs;
struct FlyoutBase;
struct FlyoutBaseClosingEventArgs;
struct GeneratorPositionHelper;
struct GridViewItemPresenter;
struct GridViewItemTemplateSettings;
struct ItemsChangedEventArgs;
struct JumpListItemBackgroundConverter;
struct JumpListItemForegroundConverter;
struct LayoutInformation;
struct ListViewItemPresenter;
struct ListViewItemTemplateSettings;
struct LoopingSelector;
struct LoopingSelectorItem;
struct LoopingSelectorPanel;
struct MenuFlyoutPresenterTemplateSettings;
struct OrientedVirtualizingPanel;
struct PickerFlyoutBase;
struct PivotHeaderItem;
struct PivotHeaderPanel;
struct PivotPanel;
struct Popup;
struct ProgressBarTemplateSettings;
struct ProgressRingTemplateSettings;
struct RangeBase;
struct RangeBaseValueChangedEventArgs;
struct RepeatButton;
struct ScrollBar;
struct ScrollEventArgs;
struct Selector;
struct SelectorItem;
struct SettingsFlyoutTemplateSettings;
struct SplitViewTemplateSettings;
struct Thumb;
struct TickBar;
struct ToggleButton;
struct ToggleSwitchTemplateSettings;
struct ToolTipTemplateSettings;

}

namespace Windows::UI::Xaml::Controls::Primitives {

struct DragCompletedEventHandler;
struct DragDeltaEventHandler;
struct DragStartedEventHandler;
struct ItemsChangedEventHandler;
struct RangeBaseValueChangedEventHandler;
struct ScrollEventHandler;
struct IAppBarTemplateSettings;
struct IButtonBase;
struct IButtonBaseFactory;
struct IButtonBaseStatics;
struct ICalendarPanel;
struct ICalendarViewTemplateSettings;
struct ICarouselPanel;
struct ICarouselPanelFactory;
struct IComboBoxTemplateSettings;
struct IComboBoxTemplateSettings2;
struct ICommandBarTemplateSettings;
struct ICommandBarTemplateSettings2;
struct ICommandBarTemplateSettings3;
struct IDragCompletedEventArgs;
struct IDragCompletedEventArgsFactory;
struct IDragDeltaEventArgs;
struct IDragDeltaEventArgsFactory;
struct IDragStartedEventArgs;
struct IDragStartedEventArgsFactory;
struct IFlyoutBase;
struct IFlyoutBase2;
struct IFlyoutBaseClosingEventArgs;
struct IFlyoutBaseFactory;
struct IFlyoutBaseOverrides;
struct IFlyoutBaseStatics;
struct IFlyoutBaseStatics2;
struct IGeneratorPositionHelper;
struct IGeneratorPositionHelperStatics;
struct IGridViewItemPresenter;
struct IGridViewItemPresenterFactory;
struct IGridViewItemPresenterStatics;
struct IGridViewItemTemplateSettings;
struct IItemsChangedEventArgs;
struct IJumpListItemBackgroundConverter;
struct IJumpListItemBackgroundConverterStatics;
struct IJumpListItemForegroundConverter;
struct IJumpListItemForegroundConverterStatics;
struct ILayoutInformation;
struct ILayoutInformationStatics;
struct IListViewItemPresenter;
struct IListViewItemPresenter2;
struct IListViewItemPresenterFactory;
struct IListViewItemPresenterStatics;
struct IListViewItemPresenterStatics2;
struct IListViewItemTemplateSettings;
struct ILoopingSelector;
struct ILoopingSelectorItem;
struct ILoopingSelectorPanel;
struct ILoopingSelectorStatics;
struct IMenuFlyoutPresenterTemplateSettings;
struct IOrientedVirtualizingPanel;
struct IOrientedVirtualizingPanelFactory;
struct IPickerFlyoutBase;
struct IPickerFlyoutBaseFactory;
struct IPickerFlyoutBaseOverrides;
struct IPickerFlyoutBaseStatics;
struct IPivotHeaderItem;
struct IPivotHeaderItemFactory;
struct IPivotHeaderPanel;
struct IPivotPanel;
struct IPopup;
struct IPopup2;
struct IPopupStatics;
struct IPopupStatics2;
struct IProgressBarTemplateSettings;
struct IProgressRingTemplateSettings;
struct IRangeBase;
struct IRangeBaseFactory;
struct IRangeBaseOverrides;
struct IRangeBaseStatics;
struct IRangeBaseValueChangedEventArgs;
struct IRepeatButton;
struct IRepeatButtonStatics;
struct IScrollBar;
struct IScrollBarStatics;
struct IScrollEventArgs;
struct IScrollSnapPointsInfo;
struct ISelector;
struct ISelectorFactory;
struct ISelectorItem;
struct ISelectorItemFactory;
struct ISelectorItemStatics;
struct ISelectorStatics;
struct ISettingsFlyoutTemplateSettings;
struct ISplitViewTemplateSettings;
struct IThumb;
struct IThumbStatics;
struct ITickBar;
struct ITickBarStatics;
struct IToggleButton;
struct IToggleButtonFactory;
struct IToggleButtonOverrides;
struct IToggleButtonStatics;
struct IToggleSwitchTemplateSettings;
struct IToolTipTemplateSettings;
struct AppBarTemplateSettings;
struct ButtonBase;
struct CalendarPanel;
struct CalendarViewTemplateSettings;
struct CarouselPanel;
struct ComboBoxTemplateSettings;
struct CommandBarTemplateSettings;
struct DragCompletedEventArgs;
struct DragDeltaEventArgs;
struct DragStartedEventArgs;
struct FlyoutBase;
struct FlyoutBaseClosingEventArgs;
struct GeneratorPositionHelper;
struct GridViewItemPresenter;
struct GridViewItemTemplateSettings;
struct ItemsChangedEventArgs;
struct JumpListItemBackgroundConverter;
struct JumpListItemForegroundConverter;
struct LayoutInformation;
struct ListViewItemPresenter;
struct ListViewItemTemplateSettings;
struct LoopingSelector;
struct LoopingSelectorItem;
struct LoopingSelectorPanel;
struct MenuFlyoutPresenterTemplateSettings;
struct OrientedVirtualizingPanel;
struct PickerFlyoutBase;
struct PivotHeaderItem;
struct PivotHeaderPanel;
struct PivotPanel;
struct Popup;
struct ProgressBarTemplateSettings;
struct ProgressRingTemplateSettings;
struct RangeBase;
struct RangeBaseValueChangedEventArgs;
struct RepeatButton;
struct ScrollBar;
struct ScrollEventArgs;
struct Selector;
struct SelectorItem;
struct SettingsFlyoutTemplateSettings;
struct SplitViewTemplateSettings;
struct Thumb;
struct TickBar;
struct ToggleButton;
struct ToggleSwitchTemplateSettings;
struct ToolTipTemplateSettings;

}

namespace Windows::UI::Xaml::Controls::Primitives {

template <typename T> struct impl_IAppBarTemplateSettings;
template <typename T> struct impl_IButtonBase;
template <typename T> struct impl_IButtonBaseFactory;
template <typename T> struct impl_IButtonBaseStatics;
template <typename T> struct impl_ICalendarPanel;
template <typename T> struct impl_ICalendarViewTemplateSettings;
template <typename T> struct impl_ICarouselPanel;
template <typename T> struct impl_ICarouselPanelFactory;
template <typename T> struct impl_IComboBoxTemplateSettings;
template <typename T> struct impl_IComboBoxTemplateSettings2;
template <typename T> struct impl_ICommandBarTemplateSettings;
template <typename T> struct impl_ICommandBarTemplateSettings2;
template <typename T> struct impl_ICommandBarTemplateSettings3;
template <typename T> struct impl_IDragCompletedEventArgs;
template <typename T> struct impl_IDragCompletedEventArgsFactory;
template <typename T> struct impl_IDragDeltaEventArgs;
template <typename T> struct impl_IDragDeltaEventArgsFactory;
template <typename T> struct impl_IDragStartedEventArgs;
template <typename T> struct impl_IDragStartedEventArgsFactory;
template <typename T> struct impl_IFlyoutBase;
template <typename T> struct impl_IFlyoutBase2;
template <typename T> struct impl_IFlyoutBaseClosingEventArgs;
template <typename T> struct impl_IFlyoutBaseFactory;
template <typename T> struct impl_IFlyoutBaseOverrides;
template <typename T> struct impl_IFlyoutBaseStatics;
template <typename T> struct impl_IFlyoutBaseStatics2;
template <typename T> struct impl_IGeneratorPositionHelper;
template <typename T> struct impl_IGeneratorPositionHelperStatics;
template <typename T> struct impl_IGridViewItemPresenter;
template <typename T> struct impl_IGridViewItemPresenterFactory;
template <typename T> struct impl_IGridViewItemPresenterStatics;
template <typename T> struct impl_IGridViewItemTemplateSettings;
template <typename T> struct impl_IItemsChangedEventArgs;
template <typename T> struct impl_IJumpListItemBackgroundConverter;
template <typename T> struct impl_IJumpListItemBackgroundConverterStatics;
template <typename T> struct impl_IJumpListItemForegroundConverter;
template <typename T> struct impl_IJumpListItemForegroundConverterStatics;
template <typename T> struct impl_ILayoutInformation;
template <typename T> struct impl_ILayoutInformationStatics;
template <typename T> struct impl_IListViewItemPresenter;
template <typename T> struct impl_IListViewItemPresenter2;
template <typename T> struct impl_IListViewItemPresenterFactory;
template <typename T> struct impl_IListViewItemPresenterStatics;
template <typename T> struct impl_IListViewItemPresenterStatics2;
template <typename T> struct impl_IListViewItemTemplateSettings;
template <typename T> struct impl_ILoopingSelector;
template <typename T> struct impl_ILoopingSelectorItem;
template <typename T> struct impl_ILoopingSelectorPanel;
template <typename T> struct impl_ILoopingSelectorStatics;
template <typename T> struct impl_IMenuFlyoutPresenterTemplateSettings;
template <typename T> struct impl_IOrientedVirtualizingPanel;
template <typename T> struct impl_IOrientedVirtualizingPanelFactory;
template <typename T> struct impl_IPickerFlyoutBase;
template <typename T> struct impl_IPickerFlyoutBaseFactory;
template <typename T> struct impl_IPickerFlyoutBaseOverrides;
template <typename T> struct impl_IPickerFlyoutBaseStatics;
template <typename T> struct impl_IPivotHeaderItem;
template <typename T> struct impl_IPivotHeaderItemFactory;
template <typename T> struct impl_IPivotHeaderPanel;
template <typename T> struct impl_IPivotPanel;
template <typename T> struct impl_IPopup;
template <typename T> struct impl_IPopup2;
template <typename T> struct impl_IPopupStatics;
template <typename T> struct impl_IPopupStatics2;
template <typename T> struct impl_IProgressBarTemplateSettings;
template <typename T> struct impl_IProgressRingTemplateSettings;
template <typename T> struct impl_IRangeBase;
template <typename T> struct impl_IRangeBaseFactory;
template <typename T> struct impl_IRangeBaseOverrides;
template <typename T> struct impl_IRangeBaseStatics;
template <typename T> struct impl_IRangeBaseValueChangedEventArgs;
template <typename T> struct impl_IRepeatButton;
template <typename T> struct impl_IRepeatButtonStatics;
template <typename T> struct impl_IScrollBar;
template <typename T> struct impl_IScrollBarStatics;
template <typename T> struct impl_IScrollEventArgs;
template <typename T> struct impl_IScrollSnapPointsInfo;
template <typename T> struct impl_ISelector;
template <typename T> struct impl_ISelectorFactory;
template <typename T> struct impl_ISelectorItem;
template <typename T> struct impl_ISelectorItemFactory;
template <typename T> struct impl_ISelectorItemStatics;
template <typename T> struct impl_ISelectorStatics;
template <typename T> struct impl_ISettingsFlyoutTemplateSettings;
template <typename T> struct impl_ISplitViewTemplateSettings;
template <typename T> struct impl_IThumb;
template <typename T> struct impl_IThumbStatics;
template <typename T> struct impl_ITickBar;
template <typename T> struct impl_ITickBarStatics;
template <typename T> struct impl_IToggleButton;
template <typename T> struct impl_IToggleButtonFactory;
template <typename T> struct impl_IToggleButtonOverrides;
template <typename T> struct impl_IToggleButtonStatics;
template <typename T> struct impl_IToggleSwitchTemplateSettings;
template <typename T> struct impl_IToolTipTemplateSettings;
template <typename T> struct impl_DragCompletedEventHandler;
template <typename T> struct impl_DragDeltaEventHandler;
template <typename T> struct impl_DragStartedEventHandler;
template <typename T> struct impl_ItemsChangedEventHandler;
template <typename T> struct impl_RangeBaseValueChangedEventHandler;
template <typename T> struct impl_ScrollEventHandler;

}

namespace Windows::UI::Xaml::Controls::Primitives {

enum class AnimationDirection
{
    Left = 0,
    Top = 1,
    Right = 2,
    Bottom = 3,
};

enum class ComponentResourceLocation
{
    Application = 0,
    Nested = 1,
};

enum class EdgeTransitionLocation
{
    Left = 0,
    Top = 1,
    Right = 2,
    Bottom = 3,
};

enum class FlyoutPlacementMode
{
    Top = 0,
    Bottom = 1,
    Left = 2,
    Right = 3,
    Full = 4,
};

enum class GeneratorDirection
{
    Forward = 0,
    Backward = 1,
};

enum class GroupHeaderPlacement
{
    Top = 0,
    Left = 1,
};

enum class ListViewItemPresenterCheckMode
{
    Inline = 0,
    Overlay = 1,
};

enum class PlacementMode
{
    Bottom = 2,
    Left = 9,
    Mouse = 7,
    Right = 4,
    Top = 10,
};

enum class ScrollEventType
{
    SmallDecrement = 0,
    SmallIncrement = 1,
    LargeDecrement = 2,
    LargeIncrement = 3,
    ThumbPosition = 4,
    ThumbTrack = 5,
    First = 6,
    Last = 7,
    EndScroll = 8,
};

enum class ScrollingIndicatorMode
{
    None = 0,
    TouchIndicator = 1,
    MouseIndicator = 2,
};

enum class SliderSnapsTo
{
    StepValues = 0,
    Ticks = 1,
};

enum class SnapPointsAlignment
{
    Near = 0,
    Center = 1,
    Far = 2,
};

enum class TickPlacement
{
    None = 0,
    TopLeft = 1,
    BottomRight = 2,
    Outside = 3,
    Inline = 4,
};

}

}
