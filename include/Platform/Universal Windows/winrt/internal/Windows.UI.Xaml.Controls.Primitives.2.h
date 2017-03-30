// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Controls.Primitives.1.h"
#include "Windows.UI.Xaml.1.h"
#include "Windows.UI.Xaml.Controls.1.h"
#include "Windows.UI.Xaml.Data.1.h"
#include "Windows.UI.Xaml.2.h"
#include "Windows.UI.Xaml.Controls.2.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_c50898f6_c536_5f47_8583_8b2c2438a13b
#define WINRT_GENERIC_c50898f6_c536_5f47_8583_8b2c2438a13b
template <> struct __declspec(uuid("c50898f6-c536-5f47-8583-8b2c2438a13b")) __declspec(novtable) EventHandler<Windows::Foundation::IInspectable> : impl_EventHandler<Windows::Foundation::IInspectable> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_a6487363_b074_5c60_ab16_866dce4ee54d
#define WINRT_GENERIC_a6487363_b074_5c60_ab16_866dce4ee54d
template <> struct __declspec(uuid("a6487363-b074-5c60-ab16-866dce4ee54d")) __declspec(novtable) IVectorView<Windows::Foundation::IInspectable> : impl_IVectorView<Windows::Foundation::IInspectable> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_3c00fd60_2950_5939_a21a_2d12c5a01b8a
#define WINRT_GENERIC_3c00fd60_2950_5939_a21a_2d12c5a01b8a
template <> struct __declspec(uuid("3c00fd60-2950-5939-a21a-2d12c5a01b8a")) __declspec(novtable) IReference<bool> : impl_IReference<bool> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_b32bdca4_5e52_5b27_bc5d_d66a1a268c2a
#define WINRT_GENERIC_b32bdca4_5e52_5b27_bc5d_d66a1a268c2a
template <> struct __declspec(uuid("b32bdca4-5e52-5b27-bc5d-d66a1a268c2a")) __declspec(novtable) IVector<Windows::Foundation::IInspectable> : impl_IVector<Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_092b849b_60b1_52be_a44a_6fe8e933cbe4
#define WINRT_GENERIC_092b849b_60b1_52be_a44a_6fe8e933cbe4
template <> struct __declspec(uuid("092b849b-60b1-52be-a44a-6fe8e933cbe4")) __declspec(novtable) IIterable<Windows::Foundation::IInspectable> : impl_IIterable<Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_7bca64fd_150c_5d50_b56b_9f4f474c5930
#define WINRT_GENERIC_7bca64fd_150c_5d50_b56b_9f4f474c5930
template <> struct __declspec(uuid("7bca64fd-150c-5d50-b56b-9f4f474c5930")) __declspec(novtable) IVectorView<float> : impl_IVectorView<float> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_96e17fbc_78c7_5560_ac3a_587f46db70d6
#define WINRT_GENERIC_96e17fbc_78c7_5560_ac3a_587f46db70d6
template <> struct __declspec(uuid("96e17fbc-78c7-5560-ac3a-587f46db70d6")) __declspec(novtable) TypedEventHandler<Windows::UI::Xaml::Controls::Primitives::FlyoutBase, Windows::UI::Xaml::Controls::Primitives::FlyoutBaseClosingEventArgs> : impl_TypedEventHandler<Windows::UI::Xaml::Controls::Primitives::FlyoutBase, Windows::UI::Xaml::Controls::Primitives::FlyoutBaseClosingEventArgs> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_44a94f2d_04f8_5091_b336_be7892dd10be
#define WINRT_GENERIC_44a94f2d_04f8_5091_b336_be7892dd10be
template <> struct __declspec(uuid("44a94f2d-04f8-5091-b336-be7892dd10be")) __declspec(novtable) IIterator<Windows::Foundation::IInspectable> : impl_IIterator<Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_42614e61_b0aa_5e72_9354_2771db20b7a8
#define WINRT_GENERIC_42614e61_b0aa_5e72_9354_2771db20b7a8
template <> struct __declspec(uuid("42614e61-b0aa-5e72-9354-2771db20b7a8")) __declspec(novtable) IIterator<float> : impl_IIterator<float> {};
#endif

#ifndef WINRT_GENERIC_b01bee51_063a_5fda_bd72_d76637bb8cb8
#define WINRT_GENERIC_b01bee51_063a_5fda_bd72_d76637bb8cb8
template <> struct __declspec(uuid("b01bee51-063a-5fda-bd72-d76637bb8cb8")) __declspec(novtable) IIterable<float> : impl_IIterable<float> {};
#endif


}

namespace Windows::UI::Xaml::Controls::Primitives {

struct DragCompletedEventHandler : Windows::Foundation::IUnknown
{
    DragCompletedEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> DragCompletedEventHandler(L lambda);
    template <typename F> DragCompletedEventHandler (F * function);
    template <typename O, typename M> DragCompletedEventHandler(O * object, M method);
    void operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Controls::Primitives::DragCompletedEventArgs & e) const;
};

struct DragDeltaEventHandler : Windows::Foundation::IUnknown
{
    DragDeltaEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> DragDeltaEventHandler(L lambda);
    template <typename F> DragDeltaEventHandler (F * function);
    template <typename O, typename M> DragDeltaEventHandler(O * object, M method);
    void operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Controls::Primitives::DragDeltaEventArgs & e) const;
};

struct DragStartedEventHandler : Windows::Foundation::IUnknown
{
    DragStartedEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> DragStartedEventHandler(L lambda);
    template <typename F> DragStartedEventHandler (F * function);
    template <typename O, typename M> DragStartedEventHandler(O * object, M method);
    void operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Controls::Primitives::DragStartedEventArgs & e) const;
};

struct ItemsChangedEventHandler : Windows::Foundation::IUnknown
{
    ItemsChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> ItemsChangedEventHandler(L lambda);
    template <typename F> ItemsChangedEventHandler (F * function);
    template <typename O, typename M> ItemsChangedEventHandler(O * object, M method);
    void operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Controls::Primitives::ItemsChangedEventArgs & e) const;
};

struct RangeBaseValueChangedEventHandler : Windows::Foundation::IUnknown
{
    RangeBaseValueChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> RangeBaseValueChangedEventHandler(L lambda);
    template <typename F> RangeBaseValueChangedEventHandler (F * function);
    template <typename O, typename M> RangeBaseValueChangedEventHandler(O * object, M method);
    void operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Controls::Primitives::RangeBaseValueChangedEventArgs & e) const;
};

struct ScrollEventHandler : Windows::Foundation::IUnknown
{
    ScrollEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> ScrollEventHandler(L lambda);
    template <typename F> ScrollEventHandler (F * function);
    template <typename O, typename M> ScrollEventHandler(O * object, M method);
    void operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Controls::Primitives::ScrollEventArgs & e) const;
};

struct IAppBarTemplateSettings :
    Windows::Foundation::IInspectable,
    impl::consume<IAppBarTemplateSettings>
{
    IAppBarTemplateSettings(std::nullptr_t = nullptr) noexcept {}
};

struct IButtonBase :
    Windows::Foundation::IInspectable,
    impl::consume<IButtonBase>
{
    IButtonBase(std::nullptr_t = nullptr) noexcept {}
};

struct IButtonBaseFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IButtonBaseFactory>
{
    IButtonBaseFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IButtonBaseStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IButtonBaseStatics>
{
    IButtonBaseStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ICalendarPanel :
    Windows::Foundation::IInspectable,
    impl::consume<ICalendarPanel>
{
    ICalendarPanel(std::nullptr_t = nullptr) noexcept {}
};

struct ICalendarViewTemplateSettings :
    Windows::Foundation::IInspectable,
    impl::consume<ICalendarViewTemplateSettings>
{
    ICalendarViewTemplateSettings(std::nullptr_t = nullptr) noexcept {}
};

struct ICarouselPanel :
    Windows::Foundation::IInspectable,
    impl::consume<ICarouselPanel>
{
    ICarouselPanel(std::nullptr_t = nullptr) noexcept {}
};

struct ICarouselPanelFactory :
    Windows::Foundation::IInspectable,
    impl::consume<ICarouselPanelFactory>
{
    ICarouselPanelFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IComboBoxTemplateSettings :
    Windows::Foundation::IInspectable,
    impl::consume<IComboBoxTemplateSettings>
{
    IComboBoxTemplateSettings(std::nullptr_t = nullptr) noexcept {}
};

struct IComboBoxTemplateSettings2 :
    Windows::Foundation::IInspectable,
    impl::consume<IComboBoxTemplateSettings2>
{
    IComboBoxTemplateSettings2(std::nullptr_t = nullptr) noexcept {}
};

struct ICommandBarTemplateSettings :
    Windows::Foundation::IInspectable,
    impl::consume<ICommandBarTemplateSettings>
{
    ICommandBarTemplateSettings(std::nullptr_t = nullptr) noexcept {}
};

struct ICommandBarTemplateSettings2 :
    Windows::Foundation::IInspectable,
    impl::consume<ICommandBarTemplateSettings2>
{
    ICommandBarTemplateSettings2(std::nullptr_t = nullptr) noexcept {}
};

struct ICommandBarTemplateSettings3 :
    Windows::Foundation::IInspectable,
    impl::consume<ICommandBarTemplateSettings3>
{
    ICommandBarTemplateSettings3(std::nullptr_t = nullptr) noexcept {}
};

struct IDragCompletedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IDragCompletedEventArgs>
{
    IDragCompletedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IDragCompletedEventArgsFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IDragCompletedEventArgsFactory>
{
    IDragCompletedEventArgsFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IDragDeltaEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IDragDeltaEventArgs>
{
    IDragDeltaEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IDragDeltaEventArgsFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IDragDeltaEventArgsFactory>
{
    IDragDeltaEventArgsFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IDragStartedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IDragStartedEventArgs>
{
    IDragStartedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IDragStartedEventArgsFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IDragStartedEventArgsFactory>
{
    IDragStartedEventArgsFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IFlyoutBase :
    Windows::Foundation::IInspectable,
    impl::consume<IFlyoutBase>
{
    IFlyoutBase(std::nullptr_t = nullptr) noexcept {}
};

struct IFlyoutBase2 :
    Windows::Foundation::IInspectable,
    impl::consume<IFlyoutBase2>
{
    IFlyoutBase2(std::nullptr_t = nullptr) noexcept {}
};

struct IFlyoutBaseClosingEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IFlyoutBaseClosingEventArgs>
{
    IFlyoutBaseClosingEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IFlyoutBaseFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IFlyoutBaseFactory>
{
    IFlyoutBaseFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IFlyoutBaseOverrides :
    Windows::Foundation::IInspectable,
    impl::consume<IFlyoutBaseOverrides>
{
    IFlyoutBaseOverrides(std::nullptr_t = nullptr) noexcept {}
};

struct IFlyoutBaseStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IFlyoutBaseStatics>
{
    IFlyoutBaseStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IFlyoutBaseStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IFlyoutBaseStatics2>
{
    IFlyoutBaseStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct IGeneratorPositionHelper :
    Windows::Foundation::IInspectable,
    impl::consume<IGeneratorPositionHelper>
{
    IGeneratorPositionHelper(std::nullptr_t = nullptr) noexcept {}
};

struct IGeneratorPositionHelperStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IGeneratorPositionHelperStatics>
{
    IGeneratorPositionHelperStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IGridViewItemPresenter :
    Windows::Foundation::IInspectable,
    impl::consume<IGridViewItemPresenter>
{
    IGridViewItemPresenter(std::nullptr_t = nullptr) noexcept {}
};

struct IGridViewItemPresenterFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IGridViewItemPresenterFactory>
{
    IGridViewItemPresenterFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IGridViewItemPresenterStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IGridViewItemPresenterStatics>
{
    IGridViewItemPresenterStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IGridViewItemTemplateSettings :
    Windows::Foundation::IInspectable,
    impl::consume<IGridViewItemTemplateSettings>
{
    IGridViewItemTemplateSettings(std::nullptr_t = nullptr) noexcept {}
};

struct IItemsChangedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IItemsChangedEventArgs>
{
    IItemsChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IJumpListItemBackgroundConverter :
    Windows::Foundation::IInspectable,
    impl::consume<IJumpListItemBackgroundConverter>
{
    IJumpListItemBackgroundConverter(std::nullptr_t = nullptr) noexcept {}
};

struct IJumpListItemBackgroundConverterStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IJumpListItemBackgroundConverterStatics>
{
    IJumpListItemBackgroundConverterStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IJumpListItemForegroundConverter :
    Windows::Foundation::IInspectable,
    impl::consume<IJumpListItemForegroundConverter>
{
    IJumpListItemForegroundConverter(std::nullptr_t = nullptr) noexcept {}
};

struct IJumpListItemForegroundConverterStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IJumpListItemForegroundConverterStatics>
{
    IJumpListItemForegroundConverterStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ILayoutInformation :
    Windows::Foundation::IInspectable,
    impl::consume<ILayoutInformation>
{
    ILayoutInformation(std::nullptr_t = nullptr) noexcept {}
};

struct ILayoutInformationStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ILayoutInformationStatics>
{
    ILayoutInformationStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IListViewItemPresenter :
    Windows::Foundation::IInspectable,
    impl::consume<IListViewItemPresenter>
{
    IListViewItemPresenter(std::nullptr_t = nullptr) noexcept {}
};

struct IListViewItemPresenter2 :
    Windows::Foundation::IInspectable,
    impl::consume<IListViewItemPresenter2>
{
    IListViewItemPresenter2(std::nullptr_t = nullptr) noexcept {}
};

struct IListViewItemPresenterFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IListViewItemPresenterFactory>
{
    IListViewItemPresenterFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IListViewItemPresenterStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IListViewItemPresenterStatics>
{
    IListViewItemPresenterStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IListViewItemPresenterStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IListViewItemPresenterStatics2>
{
    IListViewItemPresenterStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct IListViewItemTemplateSettings :
    Windows::Foundation::IInspectable,
    impl::consume<IListViewItemTemplateSettings>
{
    IListViewItemTemplateSettings(std::nullptr_t = nullptr) noexcept {}
};

struct ILoopingSelector :
    Windows::Foundation::IInspectable,
    impl::consume<ILoopingSelector>
{
    ILoopingSelector(std::nullptr_t = nullptr) noexcept {}
};

struct ILoopingSelectorItem :
    Windows::Foundation::IInspectable,
    impl::consume<ILoopingSelectorItem>
{
    ILoopingSelectorItem(std::nullptr_t = nullptr) noexcept {}
};

struct ILoopingSelectorPanel :
    Windows::Foundation::IInspectable,
    impl::consume<ILoopingSelectorPanel>
{
    ILoopingSelectorPanel(std::nullptr_t = nullptr) noexcept {}
};

struct ILoopingSelectorStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ILoopingSelectorStatics>
{
    ILoopingSelectorStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IMenuFlyoutPresenterTemplateSettings :
    Windows::Foundation::IInspectable,
    impl::consume<IMenuFlyoutPresenterTemplateSettings>
{
    IMenuFlyoutPresenterTemplateSettings(std::nullptr_t = nullptr) noexcept {}
};

struct IOrientedVirtualizingPanel :
    Windows::Foundation::IInspectable,
    impl::consume<IOrientedVirtualizingPanel>
{
    IOrientedVirtualizingPanel(std::nullptr_t = nullptr) noexcept {}
};

struct IOrientedVirtualizingPanelFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IOrientedVirtualizingPanelFactory>
{
    IOrientedVirtualizingPanelFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IPickerFlyoutBase :
    Windows::Foundation::IInspectable,
    impl::consume<IPickerFlyoutBase>
{
    IPickerFlyoutBase(std::nullptr_t = nullptr) noexcept {}
};

struct IPickerFlyoutBaseFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IPickerFlyoutBaseFactory>
{
    IPickerFlyoutBaseFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IPickerFlyoutBaseOverrides :
    Windows::Foundation::IInspectable,
    impl::consume<IPickerFlyoutBaseOverrides>
{
    IPickerFlyoutBaseOverrides(std::nullptr_t = nullptr) noexcept {}
};

struct IPickerFlyoutBaseStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IPickerFlyoutBaseStatics>
{
    IPickerFlyoutBaseStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IPivotHeaderItem :
    Windows::Foundation::IInspectable,
    impl::consume<IPivotHeaderItem>
{
    IPivotHeaderItem(std::nullptr_t = nullptr) noexcept {}
};

struct IPivotHeaderItemFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IPivotHeaderItemFactory>
{
    IPivotHeaderItemFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IPivotHeaderPanel :
    Windows::Foundation::IInspectable,
    impl::consume<IPivotHeaderPanel>
{
    IPivotHeaderPanel(std::nullptr_t = nullptr) noexcept {}
};

struct IPivotPanel :
    Windows::Foundation::IInspectable,
    impl::consume<IPivotPanel>
{
    IPivotPanel(std::nullptr_t = nullptr) noexcept {}
};

struct IPopup :
    Windows::Foundation::IInspectable,
    impl::consume<IPopup>
{
    IPopup(std::nullptr_t = nullptr) noexcept {}
};

struct IPopup2 :
    Windows::Foundation::IInspectable,
    impl::consume<IPopup2>
{
    IPopup2(std::nullptr_t = nullptr) noexcept {}
};

struct IPopupStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IPopupStatics>
{
    IPopupStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IPopupStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IPopupStatics2>
{
    IPopupStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct IProgressBarTemplateSettings :
    Windows::Foundation::IInspectable,
    impl::consume<IProgressBarTemplateSettings>
{
    IProgressBarTemplateSettings(std::nullptr_t = nullptr) noexcept {}
};

struct IProgressRingTemplateSettings :
    Windows::Foundation::IInspectable,
    impl::consume<IProgressRingTemplateSettings>
{
    IProgressRingTemplateSettings(std::nullptr_t = nullptr) noexcept {}
};

struct IRangeBase :
    Windows::Foundation::IInspectable,
    impl::consume<IRangeBase>
{
    IRangeBase(std::nullptr_t = nullptr) noexcept {}
};

struct IRangeBaseFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IRangeBaseFactory>
{
    IRangeBaseFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IRangeBaseOverrides :
    Windows::Foundation::IInspectable,
    impl::consume<IRangeBaseOverrides>
{
    IRangeBaseOverrides(std::nullptr_t = nullptr) noexcept {}
};

struct IRangeBaseStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IRangeBaseStatics>
{
    IRangeBaseStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IRangeBaseValueChangedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IRangeBaseValueChangedEventArgs>
{
    IRangeBaseValueChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IRepeatButton :
    Windows::Foundation::IInspectable,
    impl::consume<IRepeatButton>
{
    IRepeatButton(std::nullptr_t = nullptr) noexcept {}
};

struct IRepeatButtonStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IRepeatButtonStatics>
{
    IRepeatButtonStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IScrollBar :
    Windows::Foundation::IInspectable,
    impl::consume<IScrollBar>
{
    IScrollBar(std::nullptr_t = nullptr) noexcept {}
};

struct IScrollBarStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IScrollBarStatics>
{
    IScrollBarStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IScrollEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IScrollEventArgs>
{
    IScrollEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IScrollSnapPointsInfo :
    Windows::Foundation::IInspectable,
    impl::consume<IScrollSnapPointsInfo>
{
    IScrollSnapPointsInfo(std::nullptr_t = nullptr) noexcept {}
};

struct ISelector :
    Windows::Foundation::IInspectable,
    impl::consume<ISelector>
{
    ISelector(std::nullptr_t = nullptr) noexcept {}
};

struct ISelectorFactory :
    Windows::Foundation::IInspectable,
    impl::consume<ISelectorFactory>
{
    ISelectorFactory(std::nullptr_t = nullptr) noexcept {}
};

struct ISelectorItem :
    Windows::Foundation::IInspectable,
    impl::consume<ISelectorItem>
{
    ISelectorItem(std::nullptr_t = nullptr) noexcept {}
};

struct ISelectorItemFactory :
    Windows::Foundation::IInspectable,
    impl::consume<ISelectorItemFactory>
{
    ISelectorItemFactory(std::nullptr_t = nullptr) noexcept {}
};

struct ISelectorItemStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ISelectorItemStatics>
{
    ISelectorItemStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ISelectorStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ISelectorStatics>
{
    ISelectorStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ISettingsFlyoutTemplateSettings :
    Windows::Foundation::IInspectable,
    impl::consume<ISettingsFlyoutTemplateSettings>
{
    ISettingsFlyoutTemplateSettings(std::nullptr_t = nullptr) noexcept {}
};

struct ISplitViewTemplateSettings :
    Windows::Foundation::IInspectable,
    impl::consume<ISplitViewTemplateSettings>
{
    ISplitViewTemplateSettings(std::nullptr_t = nullptr) noexcept {}
};

struct IThumb :
    Windows::Foundation::IInspectable,
    impl::consume<IThumb>
{
    IThumb(std::nullptr_t = nullptr) noexcept {}
};

struct IThumbStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IThumbStatics>
{
    IThumbStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ITickBar :
    Windows::Foundation::IInspectable,
    impl::consume<ITickBar>
{
    ITickBar(std::nullptr_t = nullptr) noexcept {}
};

struct ITickBarStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ITickBarStatics>
{
    ITickBarStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IToggleButton :
    Windows::Foundation::IInspectable,
    impl::consume<IToggleButton>
{
    IToggleButton(std::nullptr_t = nullptr) noexcept {}
};

struct IToggleButtonFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IToggleButtonFactory>
{
    IToggleButtonFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IToggleButtonOverrides :
    Windows::Foundation::IInspectable,
    impl::consume<IToggleButtonOverrides>
{
    IToggleButtonOverrides(std::nullptr_t = nullptr) noexcept {}
};

struct IToggleButtonStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IToggleButtonStatics>
{
    IToggleButtonStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IToggleSwitchTemplateSettings :
    Windows::Foundation::IInspectable,
    impl::consume<IToggleSwitchTemplateSettings>
{
    IToggleSwitchTemplateSettings(std::nullptr_t = nullptr) noexcept {}
};

struct IToolTipTemplateSettings :
    Windows::Foundation::IInspectable,
    impl::consume<IToolTipTemplateSettings>
{
    IToolTipTemplateSettings(std::nullptr_t = nullptr) noexcept {}
};

}

}
