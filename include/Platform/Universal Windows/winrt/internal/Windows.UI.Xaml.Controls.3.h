// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Controls.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Controls {

template <typename H> struct impl_BackClickEventHandler : implements<impl_BackClickEventHandler<H>, abi<BackClickEventHandler>>, H
{
    impl_BackClickEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Controls::IBackClickEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Controls::BackClickEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_CalendarViewDayItemChangingEventHandler : implements<impl_CalendarViewDayItemChangingEventHandler<H>, abi<CalendarViewDayItemChangingEventHandler>>, H
{
    impl_CalendarViewDayItemChangingEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::UI::Xaml::Controls::ICalendarView> sender, impl::abi_arg_in<Windows::UI::Xaml::Controls::ICalendarViewDayItemChangingEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::UI::Xaml::Controls::CalendarView *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Controls::CalendarViewDayItemChangingEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_CleanUpVirtualizedItemEventHandler : implements<impl_CleanUpVirtualizedItemEventHandler<H>, abi<CleanUpVirtualizedItemEventHandler>>, H
{
    impl_CleanUpVirtualizedItemEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Controls::ICleanUpVirtualizedItemEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Controls::CleanUpVirtualizedItemEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_ContextMenuOpeningEventHandler : implements<impl_ContextMenuOpeningEventHandler<H>, abi<ContextMenuOpeningEventHandler>>, H
{
    impl_ContextMenuOpeningEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Controls::IContextMenuEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Controls::ContextMenuEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_DragItemsStartingEventHandler : implements<impl_DragItemsStartingEventHandler<H>, abi<DragItemsStartingEventHandler>>, H
{
    impl_DragItemsStartingEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Controls::IDragItemsStartingEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Controls::DragItemsStartingEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_HubSectionHeaderClickEventHandler : implements<impl_HubSectionHeaderClickEventHandler<H>, abi<HubSectionHeaderClickEventHandler>>, H
{
    impl_HubSectionHeaderClickEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Controls::IHubSectionHeaderClickEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Controls::HubSectionHeaderClickEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_ItemClickEventHandler : implements<impl_ItemClickEventHandler<H>, abi<ItemClickEventHandler>>, H
{
    impl_ItemClickEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Controls::IItemClickEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Controls::ItemClickEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_ListViewItemToKeyHandler : implements<impl_ListViewItemToKeyHandler<H>, abi<ListViewItemToKeyHandler>>, H
{
    impl_ListViewItemToKeyHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> item, impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach_abi((*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&item)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_ListViewKeyToItemHandler : implements<impl_ListViewKeyToItemHandler<H>, abi<ListViewKeyToItemHandler>>, H
{
    impl_ListViewKeyToItemHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<hstring> key, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::IInspectable>> returnValue) noexcept override
    {
        try
        {
            *returnValue = detach_abi((*this)(*reinterpret_cast<const hstring *>(&key)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_NotifyEventHandler : implements<impl_NotifyEventHandler<H>, abi<NotifyEventHandler>>, H
{
    impl_NotifyEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Controls::INotifyEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Controls::NotifyEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_SectionsInViewChangedEventHandler : implements<impl_SectionsInViewChangedEventHandler<H>, abi<SectionsInViewChangedEventHandler>>, H
{
    impl_SectionsInViewChangedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Controls::ISectionsInViewChangedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Controls::SectionsInViewChangedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_SelectionChangedEventHandler : implements<impl_SelectionChangedEventHandler<H>, abi<SelectionChangedEventHandler>>, H
{
    impl_SelectionChangedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Controls::ISelectionChangedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Controls::SelectionChangedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_SemanticZoomViewChangedEventHandler : implements<impl_SemanticZoomViewChangedEventHandler<H>, abi<SemanticZoomViewChangedEventHandler>>, H
{
    impl_SemanticZoomViewChangedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Controls::ISemanticZoomViewChangedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Controls::SemanticZoomViewChangedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_TextChangedEventHandler : implements<impl_TextChangedEventHandler<H>, abi<TextChangedEventHandler>>, H
{
    impl_TextChangedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Controls::ITextChangedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Controls::TextChangedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_TextControlPasteEventHandler : implements<impl_TextControlPasteEventHandler<H>, abi<TextControlPasteEventHandler>>, H
{
    impl_TextControlPasteEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Controls::ITextControlPasteEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Controls::TextControlPasteEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_WebViewNavigationFailedEventHandler : implements<impl_WebViewNavigationFailedEventHandler<H>, abi<WebViewNavigationFailedEventHandler>>, H
{
    impl_WebViewNavigationFailedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Controls::IWebViewNavigationFailedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Controls::WebViewNavigationFailedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::UI::Xaml::Controls {

struct WINRT_EBO AppBar :
    Windows::UI::Xaml::Controls::IAppBar,
    impl::bases<AppBar, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl>,
    impl::require<AppBar, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IAppBarOverrides, Windows::UI::Xaml::Controls::IAppBar2, Windows::UI::Xaml::Controls::IAppBar3, Windows::UI::Xaml::Controls::IAppBarOverrides3, Windows::UI::Xaml::Controls::IAppBar4, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    AppBar(std::nullptr_t) noexcept {}
    AppBar();
    static Windows::UI::Xaml::DependencyProperty IsOpenProperty();
    static Windows::UI::Xaml::DependencyProperty IsStickyProperty();
    static Windows::UI::Xaml::DependencyProperty ClosedDisplayModeProperty();
    static Windows::UI::Xaml::DependencyProperty LightDismissOverlayModeProperty();
};

struct WINRT_EBO AppBarButton :
    Windows::UI::Xaml::Controls::IAppBarButton,
    impl::bases<AppBarButton, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl, Windows::UI::Xaml::Controls::Primitives::ButtonBase, Windows::UI::Xaml::Controls::Button>,
    impl::require<AppBarButton, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IButton, Windows::UI::Xaml::Controls::IButtonWithFlyout, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::ICommandBarElement, Windows::UI::Xaml::Controls::ICommandBarElement2, Windows::UI::Xaml::Controls::IAppBarButton3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    AppBarButton(std::nullptr_t) noexcept {}
    AppBarButton();
    static Windows::UI::Xaml::DependencyProperty LabelProperty();
    static Windows::UI::Xaml::DependencyProperty IconProperty();
    static Windows::UI::Xaml::DependencyProperty IsCompactProperty();
    static Windows::UI::Xaml::DependencyProperty LabelPositionProperty();
    static Windows::UI::Xaml::DependencyProperty IsInOverflowProperty();
    static Windows::UI::Xaml::DependencyProperty DynamicOverflowOrderProperty();
};

struct WINRT_EBO AppBarSeparator :
    Windows::UI::Xaml::Controls::IAppBarSeparator,
    impl::bases<AppBarSeparator, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control>,
    impl::require<AppBarSeparator, Windows::UI::Xaml::Controls::ICommandBarElement, Windows::UI::Xaml::Controls::ICommandBarElement2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    AppBarSeparator(std::nullptr_t) noexcept {}
    AppBarSeparator();
    static Windows::UI::Xaml::DependencyProperty IsCompactProperty();
    static Windows::UI::Xaml::DependencyProperty IsInOverflowProperty();
    static Windows::UI::Xaml::DependencyProperty DynamicOverflowOrderProperty();
};

struct WINRT_EBO AppBarToggleButton :
    Windows::UI::Xaml::Controls::IAppBarToggleButton,
    impl::bases<AppBarToggleButton, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl, Windows::UI::Xaml::Controls::Primitives::ButtonBase, Windows::UI::Xaml::Controls::Primitives::ToggleButton>,
    impl::require<AppBarToggleButton, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverrides, Windows::UI::Xaml::Controls::ICommandBarElement, Windows::UI::Xaml::Controls::ICommandBarElement2, Windows::UI::Xaml::Controls::IAppBarToggleButton3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    AppBarToggleButton(std::nullptr_t) noexcept {}
    AppBarToggleButton();
    static Windows::UI::Xaml::DependencyProperty LabelProperty();
    static Windows::UI::Xaml::DependencyProperty IconProperty();
    static Windows::UI::Xaml::DependencyProperty IsCompactProperty();
    static Windows::UI::Xaml::DependencyProperty LabelPositionProperty();
    static Windows::UI::Xaml::DependencyProperty IsInOverflowProperty();
    static Windows::UI::Xaml::DependencyProperty DynamicOverflowOrderProperty();
};

struct WINRT_EBO AutoSuggestBox :
    Windows::UI::Xaml::Controls::IAutoSuggestBox,
    impl::bases<AutoSuggestBox, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ItemsControl>,
    impl::require<AutoSuggestBox, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControlOverrides, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::IAutoSuggestBox2, Windows::UI::Xaml::Controls::IAutoSuggestBox3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    AutoSuggestBox(std::nullptr_t) noexcept {}
    AutoSuggestBox();
    static Windows::UI::Xaml::DependencyProperty MaxSuggestionListHeightProperty();
    static Windows::UI::Xaml::DependencyProperty IsSuggestionListOpenProperty();
    static Windows::UI::Xaml::DependencyProperty TextMemberPathProperty();
    static Windows::UI::Xaml::DependencyProperty TextProperty();
    static Windows::UI::Xaml::DependencyProperty UpdateTextOnSelectProperty();
    static Windows::UI::Xaml::DependencyProperty PlaceholderTextProperty();
    static Windows::UI::Xaml::DependencyProperty HeaderProperty();
    static Windows::UI::Xaml::DependencyProperty AutoMaximizeSuggestionAreaProperty();
    static Windows::UI::Xaml::DependencyProperty TextBoxStyleProperty();
    static Windows::UI::Xaml::DependencyProperty QueryIconProperty();
    static Windows::UI::Xaml::DependencyProperty LightDismissOverlayModeProperty();
};

struct WINRT_EBO AutoSuggestBoxQuerySubmittedEventArgs :
    Windows::UI::Xaml::Controls::IAutoSuggestBoxQuerySubmittedEventArgs,
    impl::bases<AutoSuggestBoxQuerySubmittedEventArgs, Windows::UI::Xaml::DependencyObject>,
    impl::require<AutoSuggestBoxQuerySubmittedEventArgs, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    AutoSuggestBoxQuerySubmittedEventArgs(std::nullptr_t) noexcept {}
    AutoSuggestBoxQuerySubmittedEventArgs();
};

struct WINRT_EBO AutoSuggestBoxSuggestionChosenEventArgs :
    Windows::UI::Xaml::Controls::IAutoSuggestBoxSuggestionChosenEventArgs,
    impl::bases<AutoSuggestBoxSuggestionChosenEventArgs, Windows::UI::Xaml::DependencyObject>,
    impl::require<AutoSuggestBoxSuggestionChosenEventArgs, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    AutoSuggestBoxSuggestionChosenEventArgs(std::nullptr_t) noexcept {}
    AutoSuggestBoxSuggestionChosenEventArgs();
};

struct WINRT_EBO AutoSuggestBoxTextChangedEventArgs :
    Windows::UI::Xaml::Controls::IAutoSuggestBoxTextChangedEventArgs,
    impl::bases<AutoSuggestBoxTextChangedEventArgs, Windows::UI::Xaml::DependencyObject>,
    impl::require<AutoSuggestBoxTextChangedEventArgs, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    AutoSuggestBoxTextChangedEventArgs(std::nullptr_t) noexcept {}
    AutoSuggestBoxTextChangedEventArgs();
    static Windows::UI::Xaml::DependencyProperty ReasonProperty();
};

struct WINRT_EBO BackClickEventArgs :
    Windows::UI::Xaml::Controls::IBackClickEventArgs
{
    BackClickEventArgs(std::nullptr_t) noexcept {}
    BackClickEventArgs();
};

struct WINRT_EBO BitmapIcon :
    Windows::UI::Xaml::Controls::IBitmapIcon,
    impl::bases<BitmapIcon, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::IconElement>,
    impl::require<BitmapIcon, Windows::UI::Xaml::Controls::IIconElement, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    BitmapIcon(std::nullptr_t) noexcept {}
    BitmapIcon();
    static Windows::UI::Xaml::DependencyProperty UriSourceProperty();
};

struct WINRT_EBO Border :
    Windows::UI::Xaml::Controls::IBorder,
    impl::bases<Border, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement>,
    impl::require<Border, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    Border(std::nullptr_t) noexcept {}
    Border();
    static Windows::UI::Xaml::DependencyProperty BorderBrushProperty();
    static Windows::UI::Xaml::DependencyProperty BorderThicknessProperty();
    static Windows::UI::Xaml::DependencyProperty BackgroundProperty();
    static Windows::UI::Xaml::DependencyProperty CornerRadiusProperty();
    static Windows::UI::Xaml::DependencyProperty PaddingProperty();
    static Windows::UI::Xaml::DependencyProperty ChildTransitionsProperty();
};

struct WINRT_EBO Button :
    Windows::UI::Xaml::Controls::IButton,
    impl::bases<Button, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl, Windows::UI::Xaml::Controls::Primitives::ButtonBase>,
    impl::require<Button, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IButtonWithFlyout, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    Button(std::nullptr_t) noexcept {}
    Button();
    static Windows::UI::Xaml::DependencyProperty FlyoutProperty();
};

struct WINRT_EBO CalendarDatePicker :
    Windows::UI::Xaml::Controls::ICalendarDatePicker,
    impl::bases<CalendarDatePicker, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control>,
    impl::require<CalendarDatePicker, Windows::UI::Xaml::Controls::ICalendarDatePicker2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    CalendarDatePicker(std::nullptr_t) noexcept {}
    CalendarDatePicker();
    static Windows::UI::Xaml::DependencyProperty DateProperty();
    static Windows::UI::Xaml::DependencyProperty IsCalendarOpenProperty();
    static Windows::UI::Xaml::DependencyProperty DateFormatProperty();
    static Windows::UI::Xaml::DependencyProperty PlaceholderTextProperty();
    static Windows::UI::Xaml::DependencyProperty HeaderProperty();
    static Windows::UI::Xaml::DependencyProperty HeaderTemplateProperty();
    static Windows::UI::Xaml::DependencyProperty CalendarViewStyleProperty();
    static Windows::UI::Xaml::DependencyProperty MinDateProperty();
    static Windows::UI::Xaml::DependencyProperty MaxDateProperty();
    static Windows::UI::Xaml::DependencyProperty IsTodayHighlightedProperty();
    static Windows::UI::Xaml::DependencyProperty DisplayModeProperty();
    static Windows::UI::Xaml::DependencyProperty FirstDayOfWeekProperty();
    static Windows::UI::Xaml::DependencyProperty DayOfWeekFormatProperty();
    static Windows::UI::Xaml::DependencyProperty CalendarIdentifierProperty();
    static Windows::UI::Xaml::DependencyProperty IsOutOfScopeEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty IsGroupLabelVisibleProperty();
    static Windows::UI::Xaml::DependencyProperty LightDismissOverlayModeProperty();
};

struct WINRT_EBO CalendarDatePickerDateChangedEventArgs :
    Windows::UI::Xaml::Controls::ICalendarDatePickerDateChangedEventArgs
{
    CalendarDatePickerDateChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CalendarView :
    Windows::UI::Xaml::Controls::ICalendarView,
    impl::bases<CalendarView, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control>,
    impl::require<CalendarView, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    CalendarView(std::nullptr_t) noexcept {}
    CalendarView();
    static Windows::UI::Xaml::DependencyProperty CalendarIdentifierProperty();
    static Windows::UI::Xaml::DependencyProperty DayOfWeekFormatProperty();
    static Windows::UI::Xaml::DependencyProperty IsGroupLabelVisibleProperty();
    static Windows::UI::Xaml::DependencyProperty DisplayModeProperty();
    static Windows::UI::Xaml::DependencyProperty FirstDayOfWeekProperty();
    static Windows::UI::Xaml::DependencyProperty IsOutOfScopeEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty IsTodayHighlightedProperty();
    static Windows::UI::Xaml::DependencyProperty MaxDateProperty();
    static Windows::UI::Xaml::DependencyProperty MinDateProperty();
    static Windows::UI::Xaml::DependencyProperty NumberOfWeeksInViewProperty();
    static Windows::UI::Xaml::DependencyProperty SelectedDatesProperty();
    static Windows::UI::Xaml::DependencyProperty SelectionModeProperty();
    static Windows::UI::Xaml::DependencyProperty TemplateSettingsProperty();
    static Windows::UI::Xaml::DependencyProperty FocusBorderBrushProperty();
    static Windows::UI::Xaml::DependencyProperty SelectedHoverBorderBrushProperty();
    static Windows::UI::Xaml::DependencyProperty SelectedPressedBorderBrushProperty();
    static Windows::UI::Xaml::DependencyProperty SelectedBorderBrushProperty();
    static Windows::UI::Xaml::DependencyProperty HoverBorderBrushProperty();
    static Windows::UI::Xaml::DependencyProperty PressedBorderBrushProperty();
    static Windows::UI::Xaml::DependencyProperty CalendarItemBorderBrushProperty();
    static Windows::UI::Xaml::DependencyProperty OutOfScopeBackgroundProperty();
    static Windows::UI::Xaml::DependencyProperty CalendarItemBackgroundProperty();
    static Windows::UI::Xaml::DependencyProperty PressedForegroundProperty();
    static Windows::UI::Xaml::DependencyProperty TodayForegroundProperty();
    static Windows::UI::Xaml::DependencyProperty BlackoutForegroundProperty();
    static Windows::UI::Xaml::DependencyProperty SelectedForegroundProperty();
    static Windows::UI::Xaml::DependencyProperty OutOfScopeForegroundProperty();
    static Windows::UI::Xaml::DependencyProperty CalendarItemForegroundProperty();
    static Windows::UI::Xaml::DependencyProperty DayItemFontFamilyProperty();
    static Windows::UI::Xaml::DependencyProperty DayItemFontSizeProperty();
    static Windows::UI::Xaml::DependencyProperty DayItemFontStyleProperty();
    static Windows::UI::Xaml::DependencyProperty DayItemFontWeightProperty();
    static Windows::UI::Xaml::DependencyProperty TodayFontWeightProperty();
    static Windows::UI::Xaml::DependencyProperty FirstOfMonthLabelFontFamilyProperty();
    static Windows::UI::Xaml::DependencyProperty FirstOfMonthLabelFontSizeProperty();
    static Windows::UI::Xaml::DependencyProperty FirstOfMonthLabelFontStyleProperty();
    static Windows::UI::Xaml::DependencyProperty FirstOfMonthLabelFontWeightProperty();
    static Windows::UI::Xaml::DependencyProperty MonthYearItemFontFamilyProperty();
    static Windows::UI::Xaml::DependencyProperty MonthYearItemFontSizeProperty();
    static Windows::UI::Xaml::DependencyProperty MonthYearItemFontStyleProperty();
    static Windows::UI::Xaml::DependencyProperty MonthYearItemFontWeightProperty();
    static Windows::UI::Xaml::DependencyProperty FirstOfYearDecadeLabelFontFamilyProperty();
    static Windows::UI::Xaml::DependencyProperty FirstOfYearDecadeLabelFontSizeProperty();
    static Windows::UI::Xaml::DependencyProperty FirstOfYearDecadeLabelFontStyleProperty();
    static Windows::UI::Xaml::DependencyProperty FirstOfYearDecadeLabelFontWeightProperty();
    static Windows::UI::Xaml::DependencyProperty HorizontalDayItemAlignmentProperty();
    static Windows::UI::Xaml::DependencyProperty VerticalDayItemAlignmentProperty();
    static Windows::UI::Xaml::DependencyProperty HorizontalFirstOfMonthLabelAlignmentProperty();
    static Windows::UI::Xaml::DependencyProperty VerticalFirstOfMonthLabelAlignmentProperty();
    static Windows::UI::Xaml::DependencyProperty CalendarItemBorderThicknessProperty();
    static Windows::UI::Xaml::DependencyProperty CalendarViewDayItemStyleProperty();
};

struct WINRT_EBO CalendarViewDayItem :
    Windows::UI::Xaml::Controls::ICalendarViewDayItem,
    impl::bases<CalendarViewDayItem, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control>,
    impl::require<CalendarViewDayItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    CalendarViewDayItem(std::nullptr_t) noexcept {}
    CalendarViewDayItem();
    static Windows::UI::Xaml::DependencyProperty IsBlackoutProperty();
    static Windows::UI::Xaml::DependencyProperty DateProperty();
};

struct WINRT_EBO CalendarViewDayItemChangingEventArgs :
    Windows::UI::Xaml::Controls::ICalendarViewDayItemChangingEventArgs
{
    CalendarViewDayItemChangingEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CalendarViewSelectedDatesChangedEventArgs :
    Windows::UI::Xaml::Controls::ICalendarViewSelectedDatesChangedEventArgs
{
    CalendarViewSelectedDatesChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CandidateWindowBoundsChangedEventArgs :
    Windows::UI::Xaml::Controls::ICandidateWindowBoundsChangedEventArgs
{
    CandidateWindowBoundsChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO Canvas :
    Windows::UI::Xaml::Controls::ICanvas,
    impl::bases<Canvas, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Panel>,
    impl::require<Canvas, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    Canvas(std::nullptr_t) noexcept {}
    Canvas();
    static Windows::UI::Xaml::DependencyProperty LeftProperty();
    static double GetLeft(const Windows::UI::Xaml::UIElement & element);
    static void SetLeft(const Windows::UI::Xaml::UIElement & element, double length);
    static Windows::UI::Xaml::DependencyProperty TopProperty();
    static double GetTop(const Windows::UI::Xaml::UIElement & element);
    static void SetTop(const Windows::UI::Xaml::UIElement & element, double length);
    static Windows::UI::Xaml::DependencyProperty ZIndexProperty();
    static int32_t GetZIndex(const Windows::UI::Xaml::UIElement & element);
    static void SetZIndex(const Windows::UI::Xaml::UIElement & element, int32_t value);
};

struct WINRT_EBO CaptureElement :
    Windows::UI::Xaml::Controls::ICaptureElement,
    impl::bases<CaptureElement, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement>,
    impl::require<CaptureElement, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    CaptureElement(std::nullptr_t) noexcept {}
    CaptureElement();
    static Windows::UI::Xaml::DependencyProperty SourceProperty();
    static Windows::UI::Xaml::DependencyProperty StretchProperty();
};

struct WINRT_EBO CheckBox :
    Windows::UI::Xaml::Controls::ICheckBox,
    impl::bases<CheckBox, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl, Windows::UI::Xaml::Controls::Primitives::ButtonBase, Windows::UI::Xaml::Controls::Primitives::ToggleButton>,
    impl::require<CheckBox, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverrides, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    CheckBox(std::nullptr_t) noexcept {}
    CheckBox();
};

struct WINRT_EBO ChoosingGroupHeaderContainerEventArgs :
    Windows::UI::Xaml::Controls::IChoosingGroupHeaderContainerEventArgs
{
    ChoosingGroupHeaderContainerEventArgs(std::nullptr_t) noexcept {}
    ChoosingGroupHeaderContainerEventArgs();
};

struct WINRT_EBO ChoosingItemContainerEventArgs :
    Windows::UI::Xaml::Controls::IChoosingItemContainerEventArgs
{
    ChoosingItemContainerEventArgs(std::nullptr_t) noexcept {}
    ChoosingItemContainerEventArgs();
};

struct WINRT_EBO CleanUpVirtualizedItemEventArgs :
    Windows::UI::Xaml::Controls::ICleanUpVirtualizedItemEventArgs,
    impl::bases<CleanUpVirtualizedItemEventArgs, Windows::UI::Xaml::RoutedEventArgs>,
    impl::require<CleanUpVirtualizedItemEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
    CleanUpVirtualizedItemEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ColumnDefinition :
    Windows::UI::Xaml::Controls::IColumnDefinition,
    impl::bases<ColumnDefinition, Windows::UI::Xaml::DependencyObject>,
    impl::require<ColumnDefinition, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    ColumnDefinition(std::nullptr_t) noexcept {}
    ColumnDefinition();
    static Windows::UI::Xaml::DependencyProperty WidthProperty();
    static Windows::UI::Xaml::DependencyProperty MaxWidthProperty();
    static Windows::UI::Xaml::DependencyProperty MinWidthProperty();
};

struct WINRT_EBO ColumnDefinitionCollection :
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::ColumnDefinition>
{
    ColumnDefinitionCollection(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ComboBox :
    Windows::UI::Xaml::Controls::IComboBox,
    impl::bases<ComboBox, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ItemsControl, Windows::UI::Xaml::Controls::Primitives::Selector>,
    impl::require<ComboBox, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControlOverrides, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::IComboBoxOverrides, Windows::UI::Xaml::Controls::IComboBox2, Windows::UI::Xaml::Controls::IComboBox3, Windows::UI::Xaml::Controls::Primitives::ISelector, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    ComboBox(std::nullptr_t) noexcept {}
    ComboBox();
    static Windows::UI::Xaml::DependencyProperty IsDropDownOpenProperty();
    static Windows::UI::Xaml::DependencyProperty MaxDropDownHeightProperty();
    static Windows::UI::Xaml::DependencyProperty HeaderProperty();
    static Windows::UI::Xaml::DependencyProperty HeaderTemplateProperty();
    static Windows::UI::Xaml::DependencyProperty PlaceholderTextProperty();
    static Windows::UI::Xaml::DependencyProperty LightDismissOverlayModeProperty();
    static Windows::UI::Xaml::DependencyProperty IsTextSearchEnabledProperty();
};

struct WINRT_EBO ComboBoxItem :
    Windows::UI::Xaml::Controls::IComboBoxItem,
    impl::bases<ComboBoxItem, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl, Windows::UI::Xaml::Controls::Primitives::SelectorItem>,
    impl::require<ComboBoxItem, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::ISelectorItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    ComboBoxItem(std::nullptr_t) noexcept {}
    ComboBoxItem();
};

struct WINRT_EBO CommandBar :
    Windows::UI::Xaml::Controls::ICommandBar,
    impl::bases<CommandBar, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl, Windows::UI::Xaml::Controls::AppBar>,
    impl::require<CommandBar, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IAppBar, Windows::UI::Xaml::Controls::IAppBarOverrides, Windows::UI::Xaml::Controls::IAppBar2, Windows::UI::Xaml::Controls::IAppBar3, Windows::UI::Xaml::Controls::IAppBarOverrides3, Windows::UI::Xaml::Controls::IAppBar4, Windows::UI::Xaml::Controls::ICommandBar2, Windows::UI::Xaml::Controls::ICommandBar3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    CommandBar(std::nullptr_t) noexcept {}
    CommandBar();
    static Windows::UI::Xaml::DependencyProperty PrimaryCommandsProperty();
    static Windows::UI::Xaml::DependencyProperty SecondaryCommandsProperty();
    static Windows::UI::Xaml::DependencyProperty CommandBarOverflowPresenterStyleProperty();
    static Windows::UI::Xaml::DependencyProperty DefaultLabelPositionProperty();
    static Windows::UI::Xaml::DependencyProperty OverflowButtonVisibilityProperty();
    static Windows::UI::Xaml::DependencyProperty IsDynamicOverflowEnabledProperty();
};

struct WINRT_EBO CommandBarOverflowPresenter :
    Windows::UI::Xaml::Controls::ICommandBarOverflowPresenter,
    impl::bases<CommandBarOverflowPresenter, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ItemsControl>,
    impl::require<CommandBarOverflowPresenter, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControlOverrides, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    CommandBarOverflowPresenter(std::nullptr_t) noexcept {}
    CommandBarOverflowPresenter();
};

struct WINRT_EBO ContainerContentChangingEventArgs :
    Windows::UI::Xaml::Controls::IContainerContentChangingEventArgs
{
    ContainerContentChangingEventArgs(std::nullptr_t) noexcept {}
    ContainerContentChangingEventArgs();
};

struct WINRT_EBO ContentControl :
    Windows::UI::Xaml::Controls::IContentControl,
    impl::bases<ContentControl, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control>,
    impl::require<ContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    ContentControl(std::nullptr_t) noexcept {}
    ContentControl();
    static Windows::UI::Xaml::DependencyProperty ContentProperty();
    static Windows::UI::Xaml::DependencyProperty ContentTemplateProperty();
    static Windows::UI::Xaml::DependencyProperty ContentTemplateSelectorProperty();
    static Windows::UI::Xaml::DependencyProperty ContentTransitionsProperty();
};

struct WINRT_EBO ContentDialog :
    Windows::UI::Xaml::Controls::IContentDialog,
    impl::bases<ContentDialog, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl>,
    impl::require<ContentDialog, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    ContentDialog(std::nullptr_t) noexcept {}
    ContentDialog();
    static Windows::UI::Xaml::DependencyProperty TitleProperty();
    static Windows::UI::Xaml::DependencyProperty TitleTemplateProperty();
    static Windows::UI::Xaml::DependencyProperty FullSizeDesiredProperty();
    static Windows::UI::Xaml::DependencyProperty PrimaryButtonTextProperty();
    static Windows::UI::Xaml::DependencyProperty SecondaryButtonTextProperty();
    static Windows::UI::Xaml::DependencyProperty PrimaryButtonCommandProperty();
    static Windows::UI::Xaml::DependencyProperty SecondaryButtonCommandProperty();
    static Windows::UI::Xaml::DependencyProperty PrimaryButtonCommandParameterProperty();
    static Windows::UI::Xaml::DependencyProperty SecondaryButtonCommandParameterProperty();
    static Windows::UI::Xaml::DependencyProperty IsPrimaryButtonEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty IsSecondaryButtonEnabledProperty();
};

struct WINRT_EBO ContentDialogButtonClickDeferral :
    Windows::UI::Xaml::Controls::IContentDialogButtonClickDeferral
{
    ContentDialogButtonClickDeferral(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ContentDialogButtonClickEventArgs :
    Windows::UI::Xaml::Controls::IContentDialogButtonClickEventArgs
{
    ContentDialogButtonClickEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ContentDialogClosedEventArgs :
    Windows::UI::Xaml::Controls::IContentDialogClosedEventArgs
{
    ContentDialogClosedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ContentDialogClosingDeferral :
    Windows::UI::Xaml::Controls::IContentDialogClosingDeferral
{
    ContentDialogClosingDeferral(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ContentDialogClosingEventArgs :
    Windows::UI::Xaml::Controls::IContentDialogClosingEventArgs
{
    ContentDialogClosingEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ContentDialogOpenedEventArgs :
    Windows::UI::Xaml::Controls::IContentDialogOpenedEventArgs
{
    ContentDialogOpenedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ContentPresenter :
    Windows::UI::Xaml::Controls::IContentPresenter,
    impl::bases<ContentPresenter, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement>,
    impl::require<ContentPresenter, Windows::UI::Xaml::Controls::IContentPresenterOverrides, Windows::UI::Xaml::Controls::IContentPresenter2, Windows::UI::Xaml::Controls::IContentPresenter3, Windows::UI::Xaml::Controls::IContentPresenter4, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    ContentPresenter(std::nullptr_t) noexcept {}
    ContentPresenter();
    static Windows::UI::Xaml::DependencyProperty ContentProperty();
    static Windows::UI::Xaml::DependencyProperty ContentTemplateProperty();
    static Windows::UI::Xaml::DependencyProperty ContentTemplateSelectorProperty();
    static Windows::UI::Xaml::DependencyProperty ContentTransitionsProperty();
    static Windows::UI::Xaml::DependencyProperty FontSizeProperty();
    static Windows::UI::Xaml::DependencyProperty FontFamilyProperty();
    static Windows::UI::Xaml::DependencyProperty FontWeightProperty();
    static Windows::UI::Xaml::DependencyProperty FontStyleProperty();
    static Windows::UI::Xaml::DependencyProperty FontStretchProperty();
    static Windows::UI::Xaml::DependencyProperty CharacterSpacingProperty();
    static Windows::UI::Xaml::DependencyProperty ForegroundProperty();
    static Windows::UI::Xaml::DependencyProperty OpticalMarginAlignmentProperty();
    static Windows::UI::Xaml::DependencyProperty TextLineBoundsProperty();
    static Windows::UI::Xaml::DependencyProperty IsTextScaleFactorEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty TextWrappingProperty();
    static Windows::UI::Xaml::DependencyProperty MaxLinesProperty();
    static Windows::UI::Xaml::DependencyProperty LineStackingStrategyProperty();
    static Windows::UI::Xaml::DependencyProperty LineHeightProperty();
    static Windows::UI::Xaml::DependencyProperty BorderBrushProperty();
    static Windows::UI::Xaml::DependencyProperty BorderThicknessProperty();
    static Windows::UI::Xaml::DependencyProperty CornerRadiusProperty();
    static Windows::UI::Xaml::DependencyProperty PaddingProperty();
    static Windows::UI::Xaml::DependencyProperty BackgroundProperty();
    static Windows::UI::Xaml::DependencyProperty HorizontalContentAlignmentProperty();
    static Windows::UI::Xaml::DependencyProperty VerticalContentAlignmentProperty();
};

struct WINRT_EBO ContextMenuEventArgs :
    Windows::UI::Xaml::Controls::IContextMenuEventArgs,
    impl::bases<ContextMenuEventArgs, Windows::UI::Xaml::RoutedEventArgs>,
    impl::require<ContextMenuEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
    ContextMenuEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO Control :
    Windows::UI::Xaml::Controls::IControl,
    impl::bases<Control, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement>,
    impl::require<Control, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    Control(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::DependencyProperty FontSizeProperty();
    static Windows::UI::Xaml::DependencyProperty FontFamilyProperty();
    static Windows::UI::Xaml::DependencyProperty FontWeightProperty();
    static Windows::UI::Xaml::DependencyProperty FontStyleProperty();
    static Windows::UI::Xaml::DependencyProperty FontStretchProperty();
    static Windows::UI::Xaml::DependencyProperty CharacterSpacingProperty();
    static Windows::UI::Xaml::DependencyProperty ForegroundProperty();
    static Windows::UI::Xaml::DependencyProperty IsTabStopProperty();
    static Windows::UI::Xaml::DependencyProperty IsEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty TabIndexProperty();
    static Windows::UI::Xaml::DependencyProperty TabNavigationProperty();
    static Windows::UI::Xaml::DependencyProperty TemplateProperty();
    static Windows::UI::Xaml::DependencyProperty PaddingProperty();
    static Windows::UI::Xaml::DependencyProperty HorizontalContentAlignmentProperty();
    static Windows::UI::Xaml::DependencyProperty VerticalContentAlignmentProperty();
    static Windows::UI::Xaml::DependencyProperty BackgroundProperty();
    static Windows::UI::Xaml::DependencyProperty BorderThicknessProperty();
    static Windows::UI::Xaml::DependencyProperty BorderBrushProperty();
    static Windows::UI::Xaml::DependencyProperty DefaultStyleKeyProperty();
    static Windows::UI::Xaml::DependencyProperty FocusStateProperty();
    static Windows::UI::Xaml::DependencyProperty IsTextScaleFactorEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty UseSystemFocusVisualsProperty();
    static Windows::UI::Xaml::DependencyProperty IsTemplateFocusTargetProperty();
    static bool GetIsTemplateFocusTarget(const Windows::UI::Xaml::FrameworkElement & element);
    static void SetIsTemplateFocusTarget(const Windows::UI::Xaml::FrameworkElement & element, bool value);
    static Windows::UI::Xaml::DependencyProperty IsFocusEngagementEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty IsFocusEngagedProperty();
    static Windows::UI::Xaml::DependencyProperty RequiresPointerProperty();
    static Windows::UI::Xaml::DependencyProperty XYFocusLeftProperty();
    static Windows::UI::Xaml::DependencyProperty XYFocusRightProperty();
    static Windows::UI::Xaml::DependencyProperty XYFocusUpProperty();
    static Windows::UI::Xaml::DependencyProperty XYFocusDownProperty();
    static Windows::UI::Xaml::DependencyProperty ElementSoundModeProperty();
};

struct WINRT_EBO ControlTemplate :
    Windows::UI::Xaml::Controls::IControlTemplate,
    impl::bases<ControlTemplate, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::FrameworkTemplate>,
    impl::require<ControlTemplate, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IFrameworkTemplate>
{
    ControlTemplate(std::nullptr_t) noexcept {}
    ControlTemplate();
};

struct WINRT_EBO DataTemplateSelector :
    Windows::UI::Xaml::Controls::IDataTemplateSelector,
    impl::require<DataTemplateSelector, Windows::UI::Xaml::Controls::IDataTemplateSelectorOverrides, Windows::UI::Xaml::Controls::IDataTemplateSelector2, Windows::UI::Xaml::Controls::IDataTemplateSelectorOverrides2>
{
    DataTemplateSelector(std::nullptr_t) noexcept {}
    DataTemplateSelector();
    using impl_IDataTemplateSelector::SelectTemplate;
    using impl_IDataTemplateSelector2::SelectTemplate;
    using impl_IDataTemplateSelectorOverrides::SelectTemplateCore;
    using impl_IDataTemplateSelectorOverrides2::SelectTemplateCore;
};

struct WINRT_EBO DatePickedEventArgs :
    Windows::UI::Xaml::Controls::IDatePickedEventArgs,
    impl::bases<DatePickedEventArgs, Windows::UI::Xaml::DependencyObject>,
    impl::require<DatePickedEventArgs, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    DatePickedEventArgs(std::nullptr_t) noexcept {}
    DatePickedEventArgs();
};

struct WINRT_EBO DatePicker :
    Windows::UI::Xaml::Controls::IDatePicker,
    impl::bases<DatePicker, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control>,
    impl::require<DatePicker, Windows::UI::Xaml::Controls::IDatePicker2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    DatePicker(std::nullptr_t) noexcept {}
    DatePicker();
    static Windows::UI::Xaml::DependencyProperty HeaderProperty();
    static Windows::UI::Xaml::DependencyProperty HeaderTemplateProperty();
    static Windows::UI::Xaml::DependencyProperty CalendarIdentifierProperty();
    static Windows::UI::Xaml::DependencyProperty DateProperty();
    static Windows::UI::Xaml::DependencyProperty DayVisibleProperty();
    static Windows::UI::Xaml::DependencyProperty MonthVisibleProperty();
    static Windows::UI::Xaml::DependencyProperty YearVisibleProperty();
    static Windows::UI::Xaml::DependencyProperty DayFormatProperty();
    static Windows::UI::Xaml::DependencyProperty MonthFormatProperty();
    static Windows::UI::Xaml::DependencyProperty YearFormatProperty();
    static Windows::UI::Xaml::DependencyProperty MinYearProperty();
    static Windows::UI::Xaml::DependencyProperty MaxYearProperty();
    static Windows::UI::Xaml::DependencyProperty OrientationProperty();
    static Windows::UI::Xaml::DependencyProperty LightDismissOverlayModeProperty();
};

struct WINRT_EBO DatePickerFlyout :
    Windows::UI::Xaml::Controls::IDatePickerFlyout,
    impl::bases<DatePickerFlyout, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Controls::Primitives::FlyoutBase, Windows::UI::Xaml::Controls::Primitives::PickerFlyoutBase>,
    impl::require<DatePickerFlyout, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase, Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseOverrides, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase2, Windows::UI::Xaml::Controls::IDatePickerFlyout2, Windows::UI::Xaml::Controls::Primitives::IPickerFlyoutBase, Windows::UI::Xaml::Controls::Primitives::IPickerFlyoutBaseOverrides>
{
    DatePickerFlyout(std::nullptr_t) noexcept {}
    DatePickerFlyout();
    static Windows::UI::Xaml::DependencyProperty CalendarIdentifierProperty();
    static Windows::UI::Xaml::DependencyProperty DateProperty();
    static Windows::UI::Xaml::DependencyProperty DayVisibleProperty();
    static Windows::UI::Xaml::DependencyProperty MonthVisibleProperty();
    static Windows::UI::Xaml::DependencyProperty YearVisibleProperty();
    static Windows::UI::Xaml::DependencyProperty MinYearProperty();
    static Windows::UI::Xaml::DependencyProperty MaxYearProperty();
    static Windows::UI::Xaml::DependencyProperty DayFormatProperty();
    static Windows::UI::Xaml::DependencyProperty MonthFormatProperty();
    static Windows::UI::Xaml::DependencyProperty YearFormatProperty();
};

struct WINRT_EBO DatePickerFlyoutItem :
    Windows::UI::Xaml::Controls::IDatePickerFlyoutItem,
    impl::bases<DatePickerFlyoutItem, Windows::UI::Xaml::DependencyObject>,
    impl::require<DatePickerFlyoutItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Data::ICustomPropertyProvider>
{
    DatePickerFlyoutItem(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::DependencyProperty PrimaryTextProperty();
    static Windows::UI::Xaml::DependencyProperty SecondaryTextProperty();
};

struct WINRT_EBO DatePickerFlyoutPresenter :
    Windows::UI::Xaml::Controls::IDatePickerFlyoutPresenter,
    impl::bases<DatePickerFlyoutPresenter, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control>,
    impl::require<DatePickerFlyoutPresenter, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    DatePickerFlyoutPresenter(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DatePickerValueChangedEventArgs :
    Windows::UI::Xaml::Controls::IDatePickerValueChangedEventArgs
{
    DatePickerValueChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DragItemsCompletedEventArgs :
    Windows::UI::Xaml::Controls::IDragItemsCompletedEventArgs
{
    DragItemsCompletedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DragItemsStartingEventArgs :
    Windows::UI::Xaml::Controls::IDragItemsStartingEventArgs
{
    DragItemsStartingEventArgs(std::nullptr_t) noexcept {}
    DragItemsStartingEventArgs();
};

struct WINRT_EBO DynamicOverflowItemsChangingEventArgs :
    Windows::UI::Xaml::Controls::IDynamicOverflowItemsChangingEventArgs
{
    DynamicOverflowItemsChangingEventArgs(std::nullptr_t) noexcept {}
    DynamicOverflowItemsChangingEventArgs();
};

struct WINRT_EBO FlipView :
    Windows::UI::Xaml::Controls::IFlipView,
    impl::bases<FlipView, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ItemsControl, Windows::UI::Xaml::Controls::Primitives::Selector>,
    impl::require<FlipView, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControlOverrides, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::IFlipView2, Windows::UI::Xaml::Controls::Primitives::ISelector, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    FlipView(std::nullptr_t) noexcept {}
    FlipView();
    static Windows::UI::Xaml::DependencyProperty UseTouchAnimationsForAllNavigationProperty();
};

struct WINRT_EBO FlipViewItem :
    Windows::UI::Xaml::Controls::IFlipViewItem,
    impl::bases<FlipViewItem, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl, Windows::UI::Xaml::Controls::Primitives::SelectorItem>,
    impl::require<FlipViewItem, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::ISelectorItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    FlipViewItem(std::nullptr_t) noexcept {}
    FlipViewItem();
};

struct WINRT_EBO Flyout :
    Windows::UI::Xaml::Controls::IFlyout,
    impl::bases<Flyout, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Controls::Primitives::FlyoutBase>,
    impl::require<Flyout, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase, Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseOverrides, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase2>
{
    Flyout(std::nullptr_t) noexcept {}
    Flyout();
    static Windows::UI::Xaml::DependencyProperty ContentProperty();
    static Windows::UI::Xaml::DependencyProperty FlyoutPresenterStyleProperty();
};

struct WINRT_EBO FlyoutPresenter :
    Windows::UI::Xaml::Controls::IFlyoutPresenter,
    impl::bases<FlyoutPresenter, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl>,
    impl::require<FlyoutPresenter, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    FlyoutPresenter(std::nullptr_t) noexcept {}
    FlyoutPresenter();
};

struct WINRT_EBO FocusDisengagedEventArgs :
    Windows::UI::Xaml::Controls::IFocusDisengagedEventArgs,
    impl::bases<FocusDisengagedEventArgs, Windows::UI::Xaml::RoutedEventArgs>,
    impl::require<FocusDisengagedEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
    FocusDisengagedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO FocusEngagedEventArgs :
    Windows::UI::Xaml::Controls::IFocusEngagedEventArgs,
    impl::bases<FocusEngagedEventArgs, Windows::UI::Xaml::RoutedEventArgs>,
    impl::require<FocusEngagedEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
    FocusEngagedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO FontIcon :
    Windows::UI::Xaml::Controls::IFontIcon,
    impl::bases<FontIcon, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::IconElement>,
    impl::require<FontIcon, Windows::UI::Xaml::Controls::IIconElement, Windows::UI::Xaml::Controls::IFontIcon2, Windows::UI::Xaml::Controls::IFontIcon3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    FontIcon(std::nullptr_t) noexcept {}
    FontIcon();
    static Windows::UI::Xaml::DependencyProperty GlyphProperty();
    static Windows::UI::Xaml::DependencyProperty FontSizeProperty();
    static Windows::UI::Xaml::DependencyProperty FontFamilyProperty();
    static Windows::UI::Xaml::DependencyProperty FontWeightProperty();
    static Windows::UI::Xaml::DependencyProperty FontStyleProperty();
    static Windows::UI::Xaml::DependencyProperty IsTextScaleFactorEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty MirroredWhenRightToLeftProperty();
};

struct WINRT_EBO Frame :
    Windows::UI::Xaml::Controls::IFrame,
    impl::bases<Frame, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl>,
    impl::require<Frame, Windows::UI::Xaml::Controls::INavigate, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IFrame2, Windows::UI::Xaml::Controls::IFrame3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    Frame(std::nullptr_t) noexcept {}
    Frame();
    using impl_IFrame::GoBack;
    using impl_IFrame::Navigate;
    using impl_IFrame2::Navigate;
    using impl_IFrame3::GoBack;
    using impl_INavigate::Navigate;
    static Windows::UI::Xaml::DependencyProperty CacheSizeProperty();
    static Windows::UI::Xaml::DependencyProperty CanGoBackProperty();
    static Windows::UI::Xaml::DependencyProperty CanGoForwardProperty();
    static Windows::UI::Xaml::DependencyProperty CurrentSourcePageTypeProperty();
    static Windows::UI::Xaml::DependencyProperty SourcePageTypeProperty();
    static Windows::UI::Xaml::DependencyProperty BackStackDepthProperty();
    static Windows::UI::Xaml::DependencyProperty BackStackProperty();
    static Windows::UI::Xaml::DependencyProperty ForwardStackProperty();
};

struct WINRT_EBO Grid :
    Windows::UI::Xaml::Controls::IGrid,
    impl::bases<Grid, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Panel>,
    impl::require<Grid, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IGrid2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    Grid(std::nullptr_t) noexcept {}
    Grid();
    static Windows::UI::Xaml::DependencyProperty RowProperty();
    static int32_t GetRow(const Windows::UI::Xaml::FrameworkElement & element);
    static void SetRow(const Windows::UI::Xaml::FrameworkElement & element, int32_t value);
    static Windows::UI::Xaml::DependencyProperty ColumnProperty();
    static int32_t GetColumn(const Windows::UI::Xaml::FrameworkElement & element);
    static void SetColumn(const Windows::UI::Xaml::FrameworkElement & element, int32_t value);
    static Windows::UI::Xaml::DependencyProperty RowSpanProperty();
    static int32_t GetRowSpan(const Windows::UI::Xaml::FrameworkElement & element);
    static void SetRowSpan(const Windows::UI::Xaml::FrameworkElement & element, int32_t value);
    static Windows::UI::Xaml::DependencyProperty ColumnSpanProperty();
    static int32_t GetColumnSpan(const Windows::UI::Xaml::FrameworkElement & element);
    static void SetColumnSpan(const Windows::UI::Xaml::FrameworkElement & element, int32_t value);
    static Windows::UI::Xaml::DependencyProperty BorderBrushProperty();
    static Windows::UI::Xaml::DependencyProperty BorderThicknessProperty();
    static Windows::UI::Xaml::DependencyProperty CornerRadiusProperty();
    static Windows::UI::Xaml::DependencyProperty PaddingProperty();
};

struct WINRT_EBO GridView :
    Windows::UI::Xaml::Controls::IGridView,
    impl::bases<GridView, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ItemsControl, Windows::UI::Xaml::Controls::Primitives::Selector, Windows::UI::Xaml::Controls::ListViewBase>,
    impl::require<GridView, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::ISemanticZoomInformation, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControlOverrides, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::IListViewBase, Windows::UI::Xaml::Controls::IListViewBase2, Windows::UI::Xaml::Controls::IListViewBase3, Windows::UI::Xaml::Controls::IListViewBase4, Windows::UI::Xaml::Controls::IListViewBase5, Windows::UI::Xaml::Controls::Primitives::ISelector, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    GridView(std::nullptr_t) noexcept {}
    GridView();
};

struct WINRT_EBO GridViewHeaderItem :
    Windows::UI::Xaml::Controls::IGridViewHeaderItem,
    impl::bases<GridViewHeaderItem, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl, Windows::UI::Xaml::Controls::ListViewBaseHeaderItem>,
    impl::require<GridViewHeaderItem, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IListViewBaseHeaderItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    GridViewHeaderItem(std::nullptr_t) noexcept {}
    GridViewHeaderItem();
};

struct WINRT_EBO GridViewItem :
    Windows::UI::Xaml::Controls::IGridViewItem,
    impl::bases<GridViewItem, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl, Windows::UI::Xaml::Controls::Primitives::SelectorItem>,
    impl::require<GridViewItem, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::ISelectorItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    GridViewItem(std::nullptr_t) noexcept {}
    GridViewItem();
};

struct WINRT_EBO GroupItem :
    Windows::UI::Xaml::Controls::IGroupItem,
    impl::bases<GroupItem, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl>,
    impl::require<GroupItem, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    GroupItem(std::nullptr_t) noexcept {}
    GroupItem();
};

struct WINRT_EBO GroupStyle :
    Windows::UI::Xaml::Controls::IGroupStyle,
    impl::require<GroupStyle, Windows::UI::Xaml::Controls::IGroupStyle2, Windows::UI::Xaml::Data::INotifyPropertyChanged>
{
    GroupStyle(std::nullptr_t) noexcept {}
    GroupStyle();
};

struct WINRT_EBO GroupStyleSelector :
    Windows::UI::Xaml::Controls::IGroupStyleSelector,
    impl::require<GroupStyleSelector, Windows::UI::Xaml::Controls::IGroupStyleSelectorOverrides>
{
    GroupStyleSelector(std::nullptr_t) noexcept {}
    GroupStyleSelector();
};

struct WINRT_EBO Hub :
    Windows::UI::Xaml::Controls::IHub,
    impl::bases<Hub, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control>,
    impl::require<Hub, Windows::UI::Xaml::Controls::ISemanticZoomInformation, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    Hub(std::nullptr_t) noexcept {}
    Hub();
    static Windows::UI::Xaml::DependencyProperty HeaderProperty();
    static Windows::UI::Xaml::DependencyProperty HeaderTemplateProperty();
    static Windows::UI::Xaml::DependencyProperty OrientationProperty();
    static Windows::UI::Xaml::DependencyProperty DefaultSectionIndexProperty();
    static Windows::UI::Xaml::DependencyProperty SemanticZoomOwnerProperty();
    static Windows::UI::Xaml::DependencyProperty IsActiveViewProperty();
    static Windows::UI::Xaml::DependencyProperty IsZoomedInViewProperty();
};

struct WINRT_EBO HubSection :
    Windows::UI::Xaml::Controls::IHubSection,
    impl::bases<HubSection, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control>,
    impl::require<HubSection, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    HubSection(std::nullptr_t) noexcept {}
    HubSection();
    static Windows::UI::Xaml::DependencyProperty HeaderProperty();
    static Windows::UI::Xaml::DependencyProperty HeaderTemplateProperty();
    static Windows::UI::Xaml::DependencyProperty ContentTemplateProperty();
    static Windows::UI::Xaml::DependencyProperty IsHeaderInteractiveProperty();
};

struct WINRT_EBO HubSectionCollection :
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::HubSection>
{
    HubSectionCollection(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HubSectionHeaderClickEventArgs :
    Windows::UI::Xaml::Controls::IHubSectionHeaderClickEventArgs
{
    HubSectionHeaderClickEventArgs(std::nullptr_t) noexcept {}
    HubSectionHeaderClickEventArgs();
};

struct WINRT_EBO HyperlinkButton :
    Windows::UI::Xaml::Controls::IHyperlinkButton,
    impl::bases<HyperlinkButton, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl, Windows::UI::Xaml::Controls::Primitives::ButtonBase>,
    impl::require<HyperlinkButton, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    HyperlinkButton(std::nullptr_t) noexcept {}
    HyperlinkButton();
    static Windows::UI::Xaml::DependencyProperty NavigateUriProperty();
};

struct WINRT_EBO IconElement :
    Windows::UI::Xaml::Controls::IIconElement,
    impl::bases<IconElement, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement>,
    impl::require<IconElement, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    IconElement(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::DependencyProperty ForegroundProperty();
};

struct WINRT_EBO Image :
    Windows::UI::Xaml::Controls::IImage,
    impl::bases<Image, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement>,
    impl::require<Image, Windows::UI::Xaml::Controls::IImage2, Windows::UI::Xaml::Controls::IImage3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    Image(std::nullptr_t) noexcept {}
    Image();
    static Windows::UI::Xaml::DependencyProperty SourceProperty();
    static Windows::UI::Xaml::DependencyProperty StretchProperty();
    static Windows::UI::Xaml::DependencyProperty NineGridProperty();
    [[deprecated("PlayToSource may be altered or unavailable for releases after Windows 10.0. Instead, use GetAsCastingSource.")]] static Windows::UI::Xaml::DependencyProperty PlayToSourceProperty();
};

struct WINRT_EBO InkCanvas :
    Windows::UI::Xaml::Controls::IInkCanvas,
    impl::bases<InkCanvas, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement>,
    impl::require<InkCanvas, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    InkCanvas(std::nullptr_t) noexcept {}
    InkCanvas();
};

struct WINRT_EBO InkToolbar :
    Windows::UI::Xaml::Controls::IInkToolbar,
    impl::bases<InkToolbar, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control>,
    impl::require<InkToolbar, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    InkToolbar(std::nullptr_t) noexcept {}
    InkToolbar();
    static Windows::UI::Xaml::DependencyProperty InitialControlsProperty();
    static Windows::UI::Xaml::DependencyProperty ChildrenProperty();
    static Windows::UI::Xaml::DependencyProperty ActiveToolProperty();
    static Windows::UI::Xaml::DependencyProperty InkDrawingAttributesProperty();
    static Windows::UI::Xaml::DependencyProperty IsRulerButtonCheckedProperty();
    static Windows::UI::Xaml::DependencyProperty TargetInkCanvasProperty();
};

struct WINRT_EBO InkToolbarBallpointPenButton :
    Windows::UI::Xaml::Controls::IInkToolbarBallpointPenButton,
    impl::bases<InkToolbarBallpointPenButton, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl, Windows::UI::Xaml::Controls::Primitives::ButtonBase, Windows::UI::Xaml::Controls::Primitives::ToggleButton, Windows::UI::Xaml::Controls::RadioButton, Windows::UI::Xaml::Controls::InkToolbarToolButton, Windows::UI::Xaml::Controls::InkToolbarPenButton>,
    impl::require<InkToolbarBallpointPenButton, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IRadioButton, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverrides, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IInkToolbarToolButton, Windows::UI::Xaml::Controls::IInkToolbarPenButton>
{
    InkToolbarBallpointPenButton(std::nullptr_t) noexcept {}
    InkToolbarBallpointPenButton();
};

struct WINRT_EBO InkToolbarCustomPen :
    Windows::UI::Xaml::Controls::IInkToolbarCustomPen,
    impl::bases<InkToolbarCustomPen, Windows::UI::Xaml::DependencyObject>,
    impl::require<InkToolbarCustomPen, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::IInkToolbarCustomPenOverrides>
{
    InkToolbarCustomPen(std::nullptr_t) noexcept {}
};

struct WINRT_EBO InkToolbarCustomPenButton :
    Windows::UI::Xaml::Controls::IInkToolbarCustomPenButton,
    impl::bases<InkToolbarCustomPenButton, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl, Windows::UI::Xaml::Controls::Primitives::ButtonBase, Windows::UI::Xaml::Controls::Primitives::ToggleButton, Windows::UI::Xaml::Controls::RadioButton, Windows::UI::Xaml::Controls::InkToolbarToolButton, Windows::UI::Xaml::Controls::InkToolbarPenButton>,
    impl::require<InkToolbarCustomPenButton, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IRadioButton, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverrides, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IInkToolbarToolButton, Windows::UI::Xaml::Controls::IInkToolbarPenButton>
{
    InkToolbarCustomPenButton(std::nullptr_t) noexcept {}
    InkToolbarCustomPenButton();
    static Windows::UI::Xaml::DependencyProperty CustomPenProperty();
    static Windows::UI::Xaml::DependencyProperty ConfigurationContentProperty();
};

struct WINRT_EBO InkToolbarCustomToggleButton :
    Windows::UI::Xaml::Controls::IInkToolbarCustomToggleButton,
    impl::bases<InkToolbarCustomToggleButton, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl, Windows::UI::Xaml::Controls::Primitives::ButtonBase, Windows::UI::Xaml::Controls::Primitives::ToggleButton, Windows::UI::Xaml::Controls::CheckBox, Windows::UI::Xaml::Controls::InkToolbarToggleButton>,
    impl::require<InkToolbarCustomToggleButton, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::ICheckBox, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverrides, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IInkToolbarToggleButton>
{
    InkToolbarCustomToggleButton(std::nullptr_t) noexcept {}
    InkToolbarCustomToggleButton();
};

struct WINRT_EBO InkToolbarCustomToolButton :
    Windows::UI::Xaml::Controls::IInkToolbarCustomToolButton,
    impl::bases<InkToolbarCustomToolButton, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl, Windows::UI::Xaml::Controls::Primitives::ButtonBase, Windows::UI::Xaml::Controls::Primitives::ToggleButton, Windows::UI::Xaml::Controls::RadioButton, Windows::UI::Xaml::Controls::InkToolbarToolButton>,
    impl::require<InkToolbarCustomToolButton, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IRadioButton, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverrides, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IInkToolbarToolButton>
{
    InkToolbarCustomToolButton(std::nullptr_t) noexcept {}
    InkToolbarCustomToolButton();
    static Windows::UI::Xaml::DependencyProperty ConfigurationContentProperty();
};

struct WINRT_EBO InkToolbarEraserButton :
    Windows::UI::Xaml::Controls::IInkToolbarEraserButton,
    impl::bases<InkToolbarEraserButton, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl, Windows::UI::Xaml::Controls::Primitives::ButtonBase, Windows::UI::Xaml::Controls::Primitives::ToggleButton, Windows::UI::Xaml::Controls::RadioButton, Windows::UI::Xaml::Controls::InkToolbarToolButton>,
    impl::require<InkToolbarEraserButton, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IRadioButton, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverrides, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IInkToolbarToolButton>
{
    InkToolbarEraserButton(std::nullptr_t) noexcept {}
    InkToolbarEraserButton();
};

struct WINRT_EBO InkToolbarHighlighterButton :
    Windows::UI::Xaml::Controls::IInkToolbarHighlighterButton,
    impl::bases<InkToolbarHighlighterButton, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl, Windows::UI::Xaml::Controls::Primitives::ButtonBase, Windows::UI::Xaml::Controls::Primitives::ToggleButton, Windows::UI::Xaml::Controls::RadioButton, Windows::UI::Xaml::Controls::InkToolbarToolButton, Windows::UI::Xaml::Controls::InkToolbarPenButton>,
    impl::require<InkToolbarHighlighterButton, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IRadioButton, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverrides, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IInkToolbarToolButton, Windows::UI::Xaml::Controls::IInkToolbarPenButton>
{
    InkToolbarHighlighterButton(std::nullptr_t) noexcept {}
    InkToolbarHighlighterButton();
};

struct WINRT_EBO InkToolbarPenButton :
    Windows::UI::Xaml::Controls::IInkToolbarPenButton,
    impl::bases<InkToolbarPenButton, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl, Windows::UI::Xaml::Controls::Primitives::ButtonBase, Windows::UI::Xaml::Controls::Primitives::ToggleButton, Windows::UI::Xaml::Controls::RadioButton, Windows::UI::Xaml::Controls::InkToolbarToolButton>,
    impl::require<InkToolbarPenButton, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IRadioButton, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverrides, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IInkToolbarToolButton>
{
    InkToolbarPenButton(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::DependencyProperty PaletteProperty();
    static Windows::UI::Xaml::DependencyProperty MinStrokeWidthProperty();
    static Windows::UI::Xaml::DependencyProperty MaxStrokeWidthProperty();
    static Windows::UI::Xaml::DependencyProperty SelectedBrushProperty();
    static Windows::UI::Xaml::DependencyProperty SelectedBrushIndexProperty();
    static Windows::UI::Xaml::DependencyProperty SelectedStrokeWidthProperty();
};

struct WINRT_EBO InkToolbarPenConfigurationControl :
    Windows::UI::Xaml::Controls::IInkToolbarPenConfigurationControl,
    impl::bases<InkToolbarPenConfigurationControl, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control>,
    impl::require<InkToolbarPenConfigurationControl, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    InkToolbarPenConfigurationControl(std::nullptr_t) noexcept {}
    InkToolbarPenConfigurationControl();
    static Windows::UI::Xaml::DependencyProperty PenButtonProperty();
};

struct WINRT_EBO InkToolbarPencilButton :
    Windows::UI::Xaml::Controls::IInkToolbarPencilButton,
    impl::bases<InkToolbarPencilButton, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl, Windows::UI::Xaml::Controls::Primitives::ButtonBase, Windows::UI::Xaml::Controls::Primitives::ToggleButton, Windows::UI::Xaml::Controls::RadioButton, Windows::UI::Xaml::Controls::InkToolbarToolButton, Windows::UI::Xaml::Controls::InkToolbarPenButton>,
    impl::require<InkToolbarPencilButton, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IRadioButton, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverrides, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IInkToolbarToolButton, Windows::UI::Xaml::Controls::IInkToolbarPenButton>
{
    InkToolbarPencilButton(std::nullptr_t) noexcept {}
    InkToolbarPencilButton();
};

struct WINRT_EBO InkToolbarRulerButton :
    Windows::UI::Xaml::Controls::IInkToolbarRulerButton,
    impl::bases<InkToolbarRulerButton, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl, Windows::UI::Xaml::Controls::Primitives::ButtonBase, Windows::UI::Xaml::Controls::Primitives::ToggleButton, Windows::UI::Xaml::Controls::CheckBox, Windows::UI::Xaml::Controls::InkToolbarToggleButton>,
    impl::require<InkToolbarRulerButton, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::ICheckBox, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverrides, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IInkToolbarToggleButton>
{
    InkToolbarRulerButton(std::nullptr_t) noexcept {}
    InkToolbarRulerButton();
    static Windows::UI::Xaml::DependencyProperty RulerProperty();
};

struct WINRT_EBO InkToolbarToggleButton :
    Windows::UI::Xaml::Controls::IInkToolbarToggleButton,
    impl::bases<InkToolbarToggleButton, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl, Windows::UI::Xaml::Controls::Primitives::ButtonBase, Windows::UI::Xaml::Controls::Primitives::ToggleButton, Windows::UI::Xaml::Controls::CheckBox>,
    impl::require<InkToolbarToggleButton, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::ICheckBox, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverrides, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    InkToolbarToggleButton(std::nullptr_t) noexcept {}
};

struct WINRT_EBO InkToolbarToolButton :
    Windows::UI::Xaml::Controls::IInkToolbarToolButton,
    impl::bases<InkToolbarToolButton, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl, Windows::UI::Xaml::Controls::Primitives::ButtonBase, Windows::UI::Xaml::Controls::Primitives::ToggleButton, Windows::UI::Xaml::Controls::RadioButton>,
    impl::require<InkToolbarToolButton, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IRadioButton, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverrides, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    InkToolbarToolButton(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::DependencyProperty IsExtensionGlyphShownProperty();
};

struct WINRT_EBO ItemClickEventArgs :
    Windows::UI::Xaml::Controls::IItemClickEventArgs,
    impl::bases<ItemClickEventArgs, Windows::UI::Xaml::RoutedEventArgs>,
    impl::require<ItemClickEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
    ItemClickEventArgs(std::nullptr_t) noexcept {}
    ItemClickEventArgs();
};

struct WINRT_EBO ItemCollection :
    Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable>
{
    ItemCollection(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ItemContainerGenerator :
    Windows::UI::Xaml::Controls::IItemContainerGenerator
{
    ItemContainerGenerator(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ItemsControl :
    Windows::UI::Xaml::Controls::IItemsControl,
    impl::bases<ItemsControl, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control>,
    impl::require<ItemsControl, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControlOverrides, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    ItemsControl(std::nullptr_t) noexcept {}
    ItemsControl();
    static Windows::UI::Xaml::DependencyProperty ItemsSourceProperty();
    static Windows::UI::Xaml::DependencyProperty ItemTemplateProperty();
    static Windows::UI::Xaml::DependencyProperty ItemTemplateSelectorProperty();
    static Windows::UI::Xaml::DependencyProperty ItemsPanelProperty();
    static Windows::UI::Xaml::DependencyProperty DisplayMemberPathProperty();
    static Windows::UI::Xaml::DependencyProperty ItemContainerStyleProperty();
    static Windows::UI::Xaml::DependencyProperty ItemContainerStyleSelectorProperty();
    static Windows::UI::Xaml::DependencyProperty ItemContainerTransitionsProperty();
    static Windows::UI::Xaml::DependencyProperty GroupStyleSelectorProperty();
    static Windows::UI::Xaml::DependencyProperty IsGroupingProperty();
    static Windows::UI::Xaml::Controls::ItemsControl GetItemsOwner(const Windows::UI::Xaml::DependencyObject & element);
    static Windows::UI::Xaml::Controls::ItemsControl ItemsControlFromItemContainer(const Windows::UI::Xaml::DependencyObject & container);
};

struct WINRT_EBO ItemsPanelTemplate :
    Windows::UI::Xaml::Controls::IItemsPanelTemplate,
    impl::bases<ItemsPanelTemplate, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::FrameworkTemplate>,
    impl::require<ItemsPanelTemplate, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IFrameworkTemplate>
{
    ItemsPanelTemplate(std::nullptr_t) noexcept {}
    ItemsPanelTemplate();
};

struct WINRT_EBO ItemsPickedEventArgs :
    Windows::UI::Xaml::Controls::IItemsPickedEventArgs,
    impl::bases<ItemsPickedEventArgs, Windows::UI::Xaml::DependencyObject>,
    impl::require<ItemsPickedEventArgs, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    ItemsPickedEventArgs(std::nullptr_t) noexcept {}
    ItemsPickedEventArgs();
};

struct WINRT_EBO ItemsPresenter :
    Windows::UI::Xaml::Controls::IItemsPresenter,
    impl::bases<ItemsPresenter, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement>,
    impl::require<ItemsPresenter, Windows::UI::Xaml::Controls::IItemsPresenter2, Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    ItemsPresenter(std::nullptr_t) noexcept {}
    ItemsPresenter();
    static Windows::UI::Xaml::DependencyProperty HeaderProperty();
    static Windows::UI::Xaml::DependencyProperty HeaderTemplateProperty();
    static Windows::UI::Xaml::DependencyProperty HeaderTransitionsProperty();
    static Windows::UI::Xaml::DependencyProperty PaddingProperty();
    static Windows::UI::Xaml::DependencyProperty FooterProperty();
    static Windows::UI::Xaml::DependencyProperty FooterTemplateProperty();
    static Windows::UI::Xaml::DependencyProperty FooterTransitionsProperty();
};

struct WINRT_EBO ItemsStackPanel :
    Windows::UI::Xaml::Controls::IItemsStackPanel,
    impl::bases<ItemsStackPanel, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Panel>,
    impl::require<ItemsStackPanel, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IItemsStackPanel2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    ItemsStackPanel(std::nullptr_t) noexcept {}
    ItemsStackPanel();
    static Windows::UI::Xaml::DependencyProperty GroupPaddingProperty();
    static Windows::UI::Xaml::DependencyProperty OrientationProperty();
    static Windows::UI::Xaml::DependencyProperty GroupHeaderPlacementProperty();
    static Windows::UI::Xaml::DependencyProperty CacheLengthProperty();
    static Windows::UI::Xaml::DependencyProperty AreStickyGroupHeadersEnabledProperty();
};

struct WINRT_EBO ItemsWrapGrid :
    Windows::UI::Xaml::Controls::IItemsWrapGrid,
    impl::bases<ItemsWrapGrid, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Panel>,
    impl::require<ItemsWrapGrid, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IItemsWrapGrid2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    ItemsWrapGrid(std::nullptr_t) noexcept {}
    ItemsWrapGrid();
    static Windows::UI::Xaml::DependencyProperty GroupPaddingProperty();
    static Windows::UI::Xaml::DependencyProperty OrientationProperty();
    static Windows::UI::Xaml::DependencyProperty MaximumRowsOrColumnsProperty();
    static Windows::UI::Xaml::DependencyProperty ItemWidthProperty();
    static Windows::UI::Xaml::DependencyProperty ItemHeightProperty();
    static Windows::UI::Xaml::DependencyProperty GroupHeaderPlacementProperty();
    static Windows::UI::Xaml::DependencyProperty CacheLengthProperty();
    static Windows::UI::Xaml::DependencyProperty AreStickyGroupHeadersEnabledProperty();
};

struct WINRT_EBO ListBox :
    Windows::UI::Xaml::Controls::IListBox,
    impl::bases<ListBox, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ItemsControl, Windows::UI::Xaml::Controls::Primitives::Selector>,
    impl::require<ListBox, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControlOverrides, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::IListBox2, Windows::UI::Xaml::Controls::Primitives::ISelector, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    ListBox(std::nullptr_t) noexcept {}
    ListBox();
    static Windows::UI::Xaml::DependencyProperty SelectionModeProperty();
    static Windows::UI::Xaml::DependencyProperty SingleSelectionFollowsFocusProperty();
};

struct WINRT_EBO ListBoxItem :
    Windows::UI::Xaml::Controls::IListBoxItem,
    impl::bases<ListBoxItem, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl, Windows::UI::Xaml::Controls::Primitives::SelectorItem>,
    impl::require<ListBoxItem, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::ISelectorItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    ListBoxItem(std::nullptr_t) noexcept {}
    ListBoxItem();
};

struct WINRT_EBO ListPickerFlyout :
    Windows::UI::Xaml::Controls::IListPickerFlyout,
    impl::bases<ListPickerFlyout, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Controls::Primitives::FlyoutBase, Windows::UI::Xaml::Controls::Primitives::PickerFlyoutBase>,
    impl::require<ListPickerFlyout, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase, Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseOverrides, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase2, Windows::UI::Xaml::Controls::Primitives::IPickerFlyoutBase, Windows::UI::Xaml::Controls::Primitives::IPickerFlyoutBaseOverrides>
{
    ListPickerFlyout(std::nullptr_t) noexcept {}
    ListPickerFlyout();
    static Windows::UI::Xaml::DependencyProperty ItemsSourceProperty();
    static Windows::UI::Xaml::DependencyProperty ItemTemplateProperty();
    static Windows::UI::Xaml::DependencyProperty DisplayMemberPathProperty();
    static Windows::UI::Xaml::DependencyProperty SelectionModeProperty();
    static Windows::UI::Xaml::DependencyProperty SelectedIndexProperty();
    static Windows::UI::Xaml::DependencyProperty SelectedItemProperty();
    static Windows::UI::Xaml::DependencyProperty SelectedValueProperty();
    static Windows::UI::Xaml::DependencyProperty SelectedValuePathProperty();
};

struct WINRT_EBO ListPickerFlyoutPresenter :
    Windows::UI::Xaml::Controls::IListPickerFlyoutPresenter,
    impl::bases<ListPickerFlyoutPresenter, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control>,
    impl::require<ListPickerFlyoutPresenter, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    ListPickerFlyoutPresenter(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ListView :
    Windows::UI::Xaml::Controls::IListView,
    impl::bases<ListView, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ItemsControl, Windows::UI::Xaml::Controls::Primitives::Selector, Windows::UI::Xaml::Controls::ListViewBase>,
    impl::require<ListView, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::ISemanticZoomInformation, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControlOverrides, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::IListViewBase, Windows::UI::Xaml::Controls::IListViewBase2, Windows::UI::Xaml::Controls::IListViewBase3, Windows::UI::Xaml::Controls::IListViewBase4, Windows::UI::Xaml::Controls::IListViewBase5, Windows::UI::Xaml::Controls::Primitives::ISelector, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    ListView(std::nullptr_t) noexcept {}
    ListView();
};

struct WINRT_EBO ListViewBase :
    Windows::UI::Xaml::Controls::IListViewBase,
    impl::bases<ListViewBase, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ItemsControl, Windows::UI::Xaml::Controls::Primitives::Selector>,
    impl::require<ListViewBase, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::ISemanticZoomInformation, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControlOverrides, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::IListViewBase2, Windows::UI::Xaml::Controls::IListViewBase3, Windows::UI::Xaml::Controls::IListViewBase4, Windows::UI::Xaml::Controls::IListViewBase5, Windows::UI::Xaml::Controls::Primitives::ISelector, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    ListViewBase(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::DependencyProperty SelectionModeProperty();
    static Windows::UI::Xaml::DependencyProperty IsSwipeEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty CanDragItemsProperty();
    static Windows::UI::Xaml::DependencyProperty CanReorderItemsProperty();
    static Windows::UI::Xaml::DependencyProperty IsItemClickEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty DataFetchSizeProperty();
    static Windows::UI::Xaml::DependencyProperty IncrementalLoadingThresholdProperty();
    static Windows::UI::Xaml::DependencyProperty IncrementalLoadingTriggerProperty();
    static Windows::UI::Xaml::DependencyProperty SemanticZoomOwnerProperty();
    static Windows::UI::Xaml::DependencyProperty IsActiveViewProperty();
    static Windows::UI::Xaml::DependencyProperty IsZoomedInViewProperty();
    static Windows::UI::Xaml::DependencyProperty HeaderProperty();
    static Windows::UI::Xaml::DependencyProperty HeaderTemplateProperty();
    static Windows::UI::Xaml::DependencyProperty HeaderTransitionsProperty();
    static Windows::UI::Xaml::DependencyProperty ShowsScrollingPlaceholdersProperty();
    static Windows::UI::Xaml::DependencyProperty FooterProperty();
    static Windows::UI::Xaml::DependencyProperty FooterTemplateProperty();
    static Windows::UI::Xaml::DependencyProperty FooterTransitionsProperty();
    static Windows::UI::Xaml::DependencyProperty ReorderModeProperty();
    static Windows::UI::Xaml::DependencyProperty IsMultiSelectCheckBoxEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty SingleSelectionFollowsFocusProperty();
};

struct WINRT_EBO ListViewBaseHeaderItem :
    Windows::UI::Xaml::Controls::IListViewBaseHeaderItem,
    impl::bases<ListViewBaseHeaderItem, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl>,
    impl::require<ListViewBaseHeaderItem, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    ListViewBaseHeaderItem(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ListViewHeaderItem :
    Windows::UI::Xaml::Controls::IListViewHeaderItem,
    impl::bases<ListViewHeaderItem, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl, Windows::UI::Xaml::Controls::ListViewBaseHeaderItem>,
    impl::require<ListViewHeaderItem, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IListViewBaseHeaderItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    ListViewHeaderItem(std::nullptr_t) noexcept {}
    ListViewHeaderItem();
};

struct WINRT_EBO ListViewItem :
    Windows::UI::Xaml::Controls::IListViewItem,
    impl::bases<ListViewItem, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl, Windows::UI::Xaml::Controls::Primitives::SelectorItem>,
    impl::require<ListViewItem, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::ISelectorItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    ListViewItem(std::nullptr_t) noexcept {}
    ListViewItem();
};

struct WINRT_EBO ListViewPersistenceHelper :
    Windows::UI::Xaml::Controls::IListViewPersistenceHelper
{
    ListViewPersistenceHelper(std::nullptr_t) noexcept {}
    static hstring GetRelativeScrollPosition(const Windows::UI::Xaml::Controls::ListViewBase & listViewBase, const Windows::UI::Xaml::Controls::ListViewItemToKeyHandler & itemToKeyHandler);
    static Windows::Foundation::IAsyncAction SetRelativeScrollPositionAsync(const Windows::UI::Xaml::Controls::ListViewBase & listViewBase, hstring_view relativeScrollPosition, const Windows::UI::Xaml::Controls::ListViewKeyToItemHandler & keyToItemHandler);
};

struct WINRT_EBO MediaElement :
    Windows::UI::Xaml::Controls::IMediaElement,
    impl::bases<MediaElement, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement>,
    impl::require<MediaElement, Windows::UI::Xaml::Controls::IMediaElement2, Windows::UI::Xaml::Controls::IMediaElement3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    MediaElement(std::nullptr_t) noexcept {}
    MediaElement();
    static Windows::UI::Xaml::DependencyProperty PosterSourceProperty();
    static Windows::UI::Xaml::DependencyProperty SourceProperty();
    static Windows::UI::Xaml::DependencyProperty IsMutedProperty();
    static Windows::UI::Xaml::DependencyProperty IsAudioOnlyProperty();
    static Windows::UI::Xaml::DependencyProperty AutoPlayProperty();
    static Windows::UI::Xaml::DependencyProperty VolumeProperty();
    static Windows::UI::Xaml::DependencyProperty BalanceProperty();
    static Windows::UI::Xaml::DependencyProperty NaturalVideoHeightProperty();
    static Windows::UI::Xaml::DependencyProperty NaturalVideoWidthProperty();
    static Windows::UI::Xaml::DependencyProperty NaturalDurationProperty();
    static Windows::UI::Xaml::DependencyProperty PositionProperty();
    static Windows::UI::Xaml::DependencyProperty DownloadProgressProperty();
    static Windows::UI::Xaml::DependencyProperty BufferingProgressProperty();
    static Windows::UI::Xaml::DependencyProperty DownloadProgressOffsetProperty();
    static Windows::UI::Xaml::DependencyProperty CurrentStateProperty();
    static Windows::UI::Xaml::DependencyProperty CanSeekProperty();
    static Windows::UI::Xaml::DependencyProperty CanPauseProperty();
    static Windows::UI::Xaml::DependencyProperty AudioStreamCountProperty();
    static Windows::UI::Xaml::DependencyProperty AudioStreamIndexProperty();
    static Windows::UI::Xaml::DependencyProperty PlaybackRateProperty();
    static Windows::UI::Xaml::DependencyProperty IsLoopingProperty();
    [[deprecated("PlayToSource may be altered or unavailable for releases after Windows 10.0. Instead, use GetAsCastingSource.")]] static Windows::UI::Xaml::DependencyProperty PlayToSourceProperty();
    static Windows::UI::Xaml::DependencyProperty DefaultPlaybackRateProperty();
    static Windows::UI::Xaml::DependencyProperty AspectRatioWidthProperty();
    static Windows::UI::Xaml::DependencyProperty AspectRatioHeightProperty();
    static Windows::UI::Xaml::DependencyProperty RealTimePlaybackProperty();
    static Windows::UI::Xaml::DependencyProperty AudioCategoryProperty();
    static Windows::UI::Xaml::DependencyProperty AudioDeviceTypeProperty();
    static Windows::UI::Xaml::DependencyProperty ProtectionManagerProperty();
    static Windows::UI::Xaml::DependencyProperty Stereo3DVideoPackingModeProperty();
    static Windows::UI::Xaml::DependencyProperty Stereo3DVideoRenderModeProperty();
    static Windows::UI::Xaml::DependencyProperty IsStereo3DVideoProperty();
    static Windows::UI::Xaml::DependencyProperty ActualStereo3DVideoPackingModeProperty();
    static Windows::UI::Xaml::DependencyProperty AreTransportControlsEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty StretchProperty();
    static Windows::UI::Xaml::DependencyProperty IsFullWindowProperty();
    [[deprecated("PlayToPreferredSourceUri may be altered or unavailable for releases after Windows 10.0. Instead, use GetAsCastingSource().PreferredSourceUri.")]] static Windows::UI::Xaml::DependencyProperty PlayToPreferredSourceUriProperty();
};

struct WINRT_EBO MediaPlayerElement :
    Windows::UI::Xaml::Controls::IMediaPlayerElement,
    impl::bases<MediaPlayerElement, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control>,
    impl::require<MediaPlayerElement, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    MediaPlayerElement(std::nullptr_t) noexcept {}
    MediaPlayerElement();
    static Windows::UI::Xaml::DependencyProperty SourceProperty();
    static Windows::UI::Xaml::DependencyProperty AreTransportControlsEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty PosterSourceProperty();
    static Windows::UI::Xaml::DependencyProperty StretchProperty();
    static Windows::UI::Xaml::DependencyProperty AutoPlayProperty();
    static Windows::UI::Xaml::DependencyProperty IsFullWindowProperty();
    static Windows::UI::Xaml::DependencyProperty MediaPlayerProperty();
};

struct WINRT_EBO MediaPlayerPresenter :
    Windows::UI::Xaml::Controls::IMediaPlayerPresenter,
    impl::bases<MediaPlayerPresenter, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement>,
    impl::require<MediaPlayerPresenter, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    MediaPlayerPresenter(std::nullptr_t) noexcept {}
    MediaPlayerPresenter();
    static Windows::UI::Xaml::DependencyProperty MediaPlayerProperty();
    static Windows::UI::Xaml::DependencyProperty StretchProperty();
    static Windows::UI::Xaml::DependencyProperty IsFullWindowProperty();
};

struct WINRT_EBO MediaTransportControls :
    Windows::UI::Xaml::Controls::IMediaTransportControls,
    impl::bases<MediaTransportControls, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control>,
    impl::require<MediaTransportControls, Windows::UI::Xaml::Controls::IMediaTransportControls2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    MediaTransportControls(std::nullptr_t) noexcept {}
    MediaTransportControls();
    static Windows::UI::Xaml::DependencyProperty IsFullWindowButtonVisibleProperty();
    static Windows::UI::Xaml::DependencyProperty IsFullWindowEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty IsZoomButtonVisibleProperty();
    static Windows::UI::Xaml::DependencyProperty IsZoomEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty IsFastForwardButtonVisibleProperty();
    static Windows::UI::Xaml::DependencyProperty IsFastForwardEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty IsFastRewindButtonVisibleProperty();
    static Windows::UI::Xaml::DependencyProperty IsFastRewindEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty IsStopButtonVisibleProperty();
    static Windows::UI::Xaml::DependencyProperty IsStopEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty IsVolumeButtonVisibleProperty();
    static Windows::UI::Xaml::DependencyProperty IsVolumeEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty IsPlaybackRateButtonVisibleProperty();
    static Windows::UI::Xaml::DependencyProperty IsPlaybackRateEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty IsSeekBarVisibleProperty();
    static Windows::UI::Xaml::DependencyProperty IsSeekEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty IsCompactProperty();
    static Windows::UI::Xaml::DependencyProperty IsSkipForwardButtonVisibleProperty();
    static Windows::UI::Xaml::DependencyProperty IsSkipForwardEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty IsSkipBackwardButtonVisibleProperty();
    static Windows::UI::Xaml::DependencyProperty IsSkipBackwardEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty IsNextTrackButtonVisibleProperty();
    static Windows::UI::Xaml::DependencyProperty IsPreviousTrackButtonVisibleProperty();
    static Windows::UI::Xaml::DependencyProperty FastPlayFallbackBehaviourProperty();
};

struct WINRT_EBO MediaTransportControlsHelper :
    Windows::UI::Xaml::Controls::IMediaTransportControlsHelper
{
    MediaTransportControlsHelper(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::DependencyProperty DropoutOrderProperty();
    static Windows::Foundation::IReference<int32_t> GetDropoutOrder(const Windows::UI::Xaml::UIElement & element);
    static void SetDropoutOrder(const Windows::UI::Xaml::UIElement & element, const optional<int32_t> & value);
};

struct WINRT_EBO MenuFlyout :
    Windows::UI::Xaml::Controls::IMenuFlyout,
    impl::bases<MenuFlyout, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Controls::Primitives::FlyoutBase>,
    impl::require<MenuFlyout, Windows::UI::Xaml::Controls::IMenuFlyout2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase, Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseOverrides, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase2>
{
    MenuFlyout(std::nullptr_t) noexcept {}
    MenuFlyout();
    using impl_IFlyoutBase::ShowAt;
    using impl_IMenuFlyout2::ShowAt;
    static Windows::UI::Xaml::DependencyProperty MenuFlyoutPresenterStyleProperty();
};

struct WINRT_EBO MenuFlyoutItem :
    Windows::UI::Xaml::Controls::IMenuFlyoutItem,
    impl::bases<MenuFlyoutItem, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::MenuFlyoutItemBase>,
    impl::require<MenuFlyoutItem, Windows::UI::Xaml::Controls::IMenuFlyoutItemBase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    MenuFlyoutItem(std::nullptr_t) noexcept {}
    MenuFlyoutItem();
    static Windows::UI::Xaml::DependencyProperty TextProperty();
    static Windows::UI::Xaml::DependencyProperty CommandProperty();
    static Windows::UI::Xaml::DependencyProperty CommandParameterProperty();
};

struct WINRT_EBO MenuFlyoutItemBase :
    Windows::UI::Xaml::Controls::IMenuFlyoutItemBase,
    impl::bases<MenuFlyoutItemBase, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control>,
    impl::require<MenuFlyoutItemBase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    MenuFlyoutItemBase(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MenuFlyoutPresenter :
    Windows::UI::Xaml::Controls::IMenuFlyoutPresenter,
    impl::bases<MenuFlyoutPresenter, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ItemsControl>,
    impl::require<MenuFlyoutPresenter, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControlOverrides, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::Controls::IMenuFlyoutPresenter2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    MenuFlyoutPresenter(std::nullptr_t) noexcept {}
    MenuFlyoutPresenter();
};

struct WINRT_EBO MenuFlyoutSeparator :
    Windows::UI::Xaml::Controls::IMenuFlyoutSeparator,
    impl::bases<MenuFlyoutSeparator, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::MenuFlyoutItemBase>,
    impl::require<MenuFlyoutSeparator, Windows::UI::Xaml::Controls::IMenuFlyoutItemBase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    MenuFlyoutSeparator(std::nullptr_t) noexcept {}
    MenuFlyoutSeparator();
};

struct WINRT_EBO MenuFlyoutSubItem :
    Windows::UI::Xaml::Controls::IMenuFlyoutSubItem,
    impl::bases<MenuFlyoutSubItem, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::MenuFlyoutItemBase>,
    impl::require<MenuFlyoutSubItem, Windows::UI::Xaml::Controls::IMenuFlyoutItemBase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    MenuFlyoutSubItem(std::nullptr_t) noexcept {}
    MenuFlyoutSubItem();
    static Windows::UI::Xaml::DependencyProperty TextProperty();
};

struct WINRT_EBO NotifyEventArgs :
    Windows::UI::Xaml::Controls::INotifyEventArgs,
    impl::require<NotifyEventArgs, Windows::UI::Xaml::Controls::INotifyEventArgs2>
{
    NotifyEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO Page :
    Windows::UI::Xaml::Controls::IPage,
    impl::bases<Page, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::UserControl>,
    impl::require<Page, Windows::UI::Xaml::Controls::IUserControl, Windows::UI::Xaml::Controls::IPageOverrides, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    Page(std::nullptr_t) noexcept {}
    Page();
    static Windows::UI::Xaml::DependencyProperty FrameProperty();
    static Windows::UI::Xaml::DependencyProperty TopAppBarProperty();
    static Windows::UI::Xaml::DependencyProperty BottomAppBarProperty();
};

struct WINRT_EBO Panel :
    Windows::UI::Xaml::Controls::IPanel,
    impl::bases<Panel, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement>,
    impl::require<Panel, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    Panel(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::DependencyProperty BackgroundProperty();
    static Windows::UI::Xaml::DependencyProperty IsItemsHostProperty();
    static Windows::UI::Xaml::DependencyProperty ChildrenTransitionsProperty();
};

struct WINRT_EBO PasswordBox :
    Windows::UI::Xaml::Controls::IPasswordBox,
    impl::bases<PasswordBox, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control>,
    impl::require<PasswordBox, Windows::UI::Xaml::Controls::IPasswordBox2, Windows::UI::Xaml::Controls::IPasswordBox3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    PasswordBox(std::nullptr_t) noexcept {}
    PasswordBox();
    static Windows::UI::Xaml::DependencyProperty PasswordProperty();
    static Windows::UI::Xaml::DependencyProperty PasswordCharProperty();
    [[deprecated("IsPasswordRevealButtonEnabledProperty may be altered or unavailable for releases after Windows 10.0. Instead, use PasswordRevealModeProperty.")]] static Windows::UI::Xaml::DependencyProperty IsPasswordRevealButtonEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty MaxLengthProperty();
    static Windows::UI::Xaml::DependencyProperty HeaderProperty();
    static Windows::UI::Xaml::DependencyProperty HeaderTemplateProperty();
    static Windows::UI::Xaml::DependencyProperty PlaceholderTextProperty();
    static Windows::UI::Xaml::DependencyProperty SelectionHighlightColorProperty();
    static Windows::UI::Xaml::DependencyProperty PreventKeyboardDisplayOnProgrammaticFocusProperty();
    static Windows::UI::Xaml::DependencyProperty PasswordRevealModeProperty();
    static Windows::UI::Xaml::DependencyProperty TextReadingOrderProperty();
    static Windows::UI::Xaml::DependencyProperty InputScopeProperty();
};

struct WINRT_EBO PathIcon :
    Windows::UI::Xaml::Controls::IPathIcon,
    impl::bases<PathIcon, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::IconElement>,
    impl::require<PathIcon, Windows::UI::Xaml::Controls::IIconElement, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    PathIcon(std::nullptr_t) noexcept {}
    PathIcon();
    static Windows::UI::Xaml::DependencyProperty DataProperty();
};

struct WINRT_EBO PickerConfirmedEventArgs :
    Windows::UI::Xaml::Controls::IPickerConfirmedEventArgs,
    impl::bases<PickerConfirmedEventArgs, Windows::UI::Xaml::DependencyObject>,
    impl::require<PickerConfirmedEventArgs, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    PickerConfirmedEventArgs(std::nullptr_t) noexcept {}
    PickerConfirmedEventArgs();
};

struct WINRT_EBO PickerFlyout :
    Windows::UI::Xaml::Controls::IPickerFlyout,
    impl::bases<PickerFlyout, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Controls::Primitives::FlyoutBase, Windows::UI::Xaml::Controls::Primitives::PickerFlyoutBase>,
    impl::require<PickerFlyout, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase, Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseOverrides, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase2, Windows::UI::Xaml::Controls::Primitives::IPickerFlyoutBase, Windows::UI::Xaml::Controls::Primitives::IPickerFlyoutBaseOverrides>
{
    PickerFlyout(std::nullptr_t) noexcept {}
    PickerFlyout();
    static Windows::UI::Xaml::DependencyProperty ContentProperty();
    static Windows::UI::Xaml::DependencyProperty ConfirmationButtonsVisibleProperty();
};

struct WINRT_EBO PickerFlyoutPresenter :
    Windows::UI::Xaml::Controls::IPickerFlyoutPresenter,
    impl::bases<PickerFlyoutPresenter, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl>,
    impl::require<PickerFlyoutPresenter, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    PickerFlyoutPresenter(std::nullptr_t) noexcept {}
};

struct WINRT_EBO Pivot :
    Windows::UI::Xaml::Controls::IPivot,
    impl::bases<Pivot, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ItemsControl>,
    impl::require<Pivot, Windows::UI::Xaml::Controls::IItemContainerMapping, Windows::UI::Xaml::Controls::IItemsControl, Windows::UI::Xaml::Controls::IItemsControlOverrides, Windows::UI::Xaml::Controls::IItemsControl2, Windows::UI::Xaml::Controls::IItemsControl3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4, Windows::UI::Xaml::Controls::IPivot2, Windows::UI::Xaml::Controls::IPivot3>
{
    Pivot(std::nullptr_t) noexcept {}
    Pivot();
    static Windows::UI::Xaml::DependencyProperty TitleProperty();
    static Windows::UI::Xaml::DependencyProperty TitleTemplateProperty();
    static Windows::UI::Xaml::DependencyProperty HeaderTemplateProperty();
    static Windows::UI::Xaml::DependencyProperty SelectedIndexProperty();
    static Windows::UI::Xaml::DependencyProperty SelectedItemProperty();
    static Windows::UI::Xaml::DependencyProperty IsLockedProperty();
    static Windows::UI::Xaml::DependencyProperty SlideInAnimationGroupProperty();
    static Windows::UI::Xaml::Controls::PivotSlideInAnimationGroup GetSlideInAnimationGroup(const Windows::UI::Xaml::FrameworkElement & element);
    static void SetSlideInAnimationGroup(const Windows::UI::Xaml::FrameworkElement & element, Windows::UI::Xaml::Controls::PivotSlideInAnimationGroup value);
    static Windows::UI::Xaml::DependencyProperty LeftHeaderProperty();
    static Windows::UI::Xaml::DependencyProperty LeftHeaderTemplateProperty();
    static Windows::UI::Xaml::DependencyProperty RightHeaderProperty();
    static Windows::UI::Xaml::DependencyProperty RightHeaderTemplateProperty();
    static Windows::UI::Xaml::DependencyProperty HeaderFocusVisualPlacementProperty();
    static Windows::UI::Xaml::DependencyProperty IsHeaderItemsCarouselEnabledProperty();
};

struct WINRT_EBO PivotItem :
    Windows::UI::Xaml::Controls::IPivotItem,
    impl::bases<PivotItem, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl>,
    impl::require<PivotItem, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    PivotItem(std::nullptr_t) noexcept {}
    PivotItem();
    static Windows::UI::Xaml::DependencyProperty HeaderProperty();
};

struct WINRT_EBO PivotItemEventArgs :
    Windows::UI::Xaml::Controls::IPivotItemEventArgs
{
    PivotItemEventArgs(std::nullptr_t) noexcept {}
    PivotItemEventArgs();
};

struct WINRT_EBO ProgressBar :
    Windows::UI::Xaml::Controls::IProgressBar,
    impl::bases<ProgressBar, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::Primitives::RangeBase>,
    impl::require<ProgressBar, Windows::UI::Xaml::Controls::Primitives::IRangeBase, Windows::UI::Xaml::Controls::Primitives::IRangeBaseOverrides, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    ProgressBar(std::nullptr_t) noexcept {}
    ProgressBar();
    static Windows::UI::Xaml::DependencyProperty IsIndeterminateProperty();
    static Windows::UI::Xaml::DependencyProperty ShowErrorProperty();
    static Windows::UI::Xaml::DependencyProperty ShowPausedProperty();
};

struct WINRT_EBO ProgressRing :
    Windows::UI::Xaml::Controls::IProgressRing,
    impl::bases<ProgressRing, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control>,
    impl::require<ProgressRing, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    ProgressRing(std::nullptr_t) noexcept {}
    ProgressRing();
    static Windows::UI::Xaml::DependencyProperty IsActiveProperty();
};

struct WINRT_EBO RadioButton :
    Windows::UI::Xaml::Controls::IRadioButton,
    impl::bases<RadioButton, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl, Windows::UI::Xaml::Controls::Primitives::ButtonBase, Windows::UI::Xaml::Controls::Primitives::ToggleButton>,
    impl::require<RadioButton, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::Primitives::IButtonBase, Windows::UI::Xaml::Controls::Primitives::IToggleButton, Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverrides, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    RadioButton(std::nullptr_t) noexcept {}
    RadioButton();
    static Windows::UI::Xaml::DependencyProperty GroupNameProperty();
};

struct WINRT_EBO RelativePanel :
    Windows::UI::Xaml::Controls::IRelativePanel,
    impl::bases<RelativePanel, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Panel>,
    impl::require<RelativePanel, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    RelativePanel(std::nullptr_t) noexcept {}
    RelativePanel();
    static Windows::UI::Xaml::DependencyProperty LeftOfProperty();
    static Windows::Foundation::IInspectable GetLeftOf(const Windows::UI::Xaml::UIElement & element);
    static void SetLeftOf(const Windows::UI::Xaml::UIElement & element, const Windows::Foundation::IInspectable & value);
    static Windows::UI::Xaml::DependencyProperty AboveProperty();
    static Windows::Foundation::IInspectable GetAbove(const Windows::UI::Xaml::UIElement & element);
    static void SetAbove(const Windows::UI::Xaml::UIElement & element, const Windows::Foundation::IInspectable & value);
    static Windows::UI::Xaml::DependencyProperty RightOfProperty();
    static Windows::Foundation::IInspectable GetRightOf(const Windows::UI::Xaml::UIElement & element);
    static void SetRightOf(const Windows::UI::Xaml::UIElement & element, const Windows::Foundation::IInspectable & value);
    static Windows::UI::Xaml::DependencyProperty BelowProperty();
    static Windows::Foundation::IInspectable GetBelow(const Windows::UI::Xaml::UIElement & element);
    static void SetBelow(const Windows::UI::Xaml::UIElement & element, const Windows::Foundation::IInspectable & value);
    static Windows::UI::Xaml::DependencyProperty AlignHorizontalCenterWithProperty();
    static Windows::Foundation::IInspectable GetAlignHorizontalCenterWith(const Windows::UI::Xaml::UIElement & element);
    static void SetAlignHorizontalCenterWith(const Windows::UI::Xaml::UIElement & element, const Windows::Foundation::IInspectable & value);
    static Windows::UI::Xaml::DependencyProperty AlignVerticalCenterWithProperty();
    static Windows::Foundation::IInspectable GetAlignVerticalCenterWith(const Windows::UI::Xaml::UIElement & element);
    static void SetAlignVerticalCenterWith(const Windows::UI::Xaml::UIElement & element, const Windows::Foundation::IInspectable & value);
    static Windows::UI::Xaml::DependencyProperty AlignLeftWithProperty();
    static Windows::Foundation::IInspectable GetAlignLeftWith(const Windows::UI::Xaml::UIElement & element);
    static void SetAlignLeftWith(const Windows::UI::Xaml::UIElement & element, const Windows::Foundation::IInspectable & value);
    static Windows::UI::Xaml::DependencyProperty AlignTopWithProperty();
    static Windows::Foundation::IInspectable GetAlignTopWith(const Windows::UI::Xaml::UIElement & element);
    static void SetAlignTopWith(const Windows::UI::Xaml::UIElement & element, const Windows::Foundation::IInspectable & value);
    static Windows::UI::Xaml::DependencyProperty AlignRightWithProperty();
    static Windows::Foundation::IInspectable GetAlignRightWith(const Windows::UI::Xaml::UIElement & element);
    static void SetAlignRightWith(const Windows::UI::Xaml::UIElement & element, const Windows::Foundation::IInspectable & value);
    static Windows::UI::Xaml::DependencyProperty AlignBottomWithProperty();
    static Windows::Foundation::IInspectable GetAlignBottomWith(const Windows::UI::Xaml::UIElement & element);
    static void SetAlignBottomWith(const Windows::UI::Xaml::UIElement & element, const Windows::Foundation::IInspectable & value);
    static Windows::UI::Xaml::DependencyProperty AlignLeftWithPanelProperty();
    static bool GetAlignLeftWithPanel(const Windows::UI::Xaml::UIElement & element);
    static void SetAlignLeftWithPanel(const Windows::UI::Xaml::UIElement & element, bool value);
    static Windows::UI::Xaml::DependencyProperty AlignTopWithPanelProperty();
    static bool GetAlignTopWithPanel(const Windows::UI::Xaml::UIElement & element);
    static void SetAlignTopWithPanel(const Windows::UI::Xaml::UIElement & element, bool value);
    static Windows::UI::Xaml::DependencyProperty AlignRightWithPanelProperty();
    static bool GetAlignRightWithPanel(const Windows::UI::Xaml::UIElement & element);
    static void SetAlignRightWithPanel(const Windows::UI::Xaml::UIElement & element, bool value);
    static Windows::UI::Xaml::DependencyProperty AlignBottomWithPanelProperty();
    static bool GetAlignBottomWithPanel(const Windows::UI::Xaml::UIElement & element);
    static void SetAlignBottomWithPanel(const Windows::UI::Xaml::UIElement & element, bool value);
    static Windows::UI::Xaml::DependencyProperty AlignHorizontalCenterWithPanelProperty();
    static bool GetAlignHorizontalCenterWithPanel(const Windows::UI::Xaml::UIElement & element);
    static void SetAlignHorizontalCenterWithPanel(const Windows::UI::Xaml::UIElement & element, bool value);
    static Windows::UI::Xaml::DependencyProperty AlignVerticalCenterWithPanelProperty();
    static bool GetAlignVerticalCenterWithPanel(const Windows::UI::Xaml::UIElement & element);
    static void SetAlignVerticalCenterWithPanel(const Windows::UI::Xaml::UIElement & element, bool value);
    static Windows::UI::Xaml::DependencyProperty BorderBrushProperty();
    static Windows::UI::Xaml::DependencyProperty BorderThicknessProperty();
    static Windows::UI::Xaml::DependencyProperty CornerRadiusProperty();
    static Windows::UI::Xaml::DependencyProperty PaddingProperty();
};

struct WINRT_EBO RichEditBox :
    Windows::UI::Xaml::Controls::IRichEditBox,
    impl::bases<RichEditBox, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control>,
    impl::require<RichEditBox, Windows::UI::Xaml::Controls::IRichEditBox2, Windows::UI::Xaml::Controls::IRichEditBox3, Windows::UI::Xaml::Controls::IRichEditBox4, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    RichEditBox(std::nullptr_t) noexcept {}
    RichEditBox();
    static Windows::UI::Xaml::DependencyProperty IsReadOnlyProperty();
    static Windows::UI::Xaml::DependencyProperty AcceptsReturnProperty();
    static Windows::UI::Xaml::DependencyProperty TextAlignmentProperty();
    static Windows::UI::Xaml::DependencyProperty TextWrappingProperty();
    static Windows::UI::Xaml::DependencyProperty IsSpellCheckEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty IsTextPredictionEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty InputScopeProperty();
    static Windows::UI::Xaml::DependencyProperty HeaderProperty();
    static Windows::UI::Xaml::DependencyProperty HeaderTemplateProperty();
    static Windows::UI::Xaml::DependencyProperty PlaceholderTextProperty();
    static Windows::UI::Xaml::DependencyProperty SelectionHighlightColorProperty();
    static Windows::UI::Xaml::DependencyProperty PreventKeyboardDisplayOnProgrammaticFocusProperty();
    static Windows::UI::Xaml::DependencyProperty IsColorFontEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty DesiredCandidateWindowAlignmentProperty();
    static Windows::UI::Xaml::DependencyProperty TextReadingOrderProperty();
    static Windows::UI::Xaml::DependencyProperty ClipboardCopyFormatProperty();
};

struct WINRT_EBO RichEditBoxTextChangingEventArgs :
    Windows::UI::Xaml::Controls::IRichEditBoxTextChangingEventArgs
{
    RichEditBoxTextChangingEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO RichTextBlock :
    Windows::UI::Xaml::Controls::IRichTextBlock,
    impl::bases<RichTextBlock, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement>,
    impl::require<RichTextBlock, Windows::UI::Xaml::Controls::IRichTextBlock2, Windows::UI::Xaml::Controls::IRichTextBlock3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    RichTextBlock(std::nullptr_t) noexcept {}
    RichTextBlock();
    static Windows::UI::Xaml::DependencyProperty FontSizeProperty();
    static Windows::UI::Xaml::DependencyProperty FontFamilyProperty();
    static Windows::UI::Xaml::DependencyProperty FontWeightProperty();
    static Windows::UI::Xaml::DependencyProperty FontStyleProperty();
    static Windows::UI::Xaml::DependencyProperty FontStretchProperty();
    static Windows::UI::Xaml::DependencyProperty ForegroundProperty();
    static Windows::UI::Xaml::DependencyProperty TextWrappingProperty();
    static Windows::UI::Xaml::DependencyProperty TextTrimmingProperty();
    static Windows::UI::Xaml::DependencyProperty TextAlignmentProperty();
    static Windows::UI::Xaml::DependencyProperty PaddingProperty();
    static Windows::UI::Xaml::DependencyProperty LineHeightProperty();
    static Windows::UI::Xaml::DependencyProperty LineStackingStrategyProperty();
    static Windows::UI::Xaml::DependencyProperty CharacterSpacingProperty();
    static Windows::UI::Xaml::DependencyProperty OverflowContentTargetProperty();
    static Windows::UI::Xaml::DependencyProperty IsTextSelectionEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty HasOverflowContentProperty();
    static Windows::UI::Xaml::DependencyProperty SelectedTextProperty();
    static Windows::UI::Xaml::DependencyProperty TextIndentProperty();
    static Windows::UI::Xaml::DependencyProperty MaxLinesProperty();
    static Windows::UI::Xaml::DependencyProperty TextLineBoundsProperty();
    static Windows::UI::Xaml::DependencyProperty SelectionHighlightColorProperty();
    static Windows::UI::Xaml::DependencyProperty OpticalMarginAlignmentProperty();
    static Windows::UI::Xaml::DependencyProperty IsColorFontEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty TextReadingOrderProperty();
    static Windows::UI::Xaml::DependencyProperty IsTextScaleFactorEnabledProperty();
};

struct WINRT_EBO RichTextBlockOverflow :
    Windows::UI::Xaml::Controls::IRichTextBlockOverflow,
    impl::bases<RichTextBlockOverflow, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement>,
    impl::require<RichTextBlockOverflow, Windows::UI::Xaml::Controls::IRichTextBlockOverflow2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    RichTextBlockOverflow(std::nullptr_t) noexcept {}
    RichTextBlockOverflow();
    static Windows::UI::Xaml::DependencyProperty OverflowContentTargetProperty();
    static Windows::UI::Xaml::DependencyProperty PaddingProperty();
    static Windows::UI::Xaml::DependencyProperty HasOverflowContentProperty();
    static Windows::UI::Xaml::DependencyProperty MaxLinesProperty();
};

struct WINRT_EBO RowDefinition :
    Windows::UI::Xaml::Controls::IRowDefinition,
    impl::bases<RowDefinition, Windows::UI::Xaml::DependencyObject>,
    impl::require<RowDefinition, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    RowDefinition(std::nullptr_t) noexcept {}
    RowDefinition();
    static Windows::UI::Xaml::DependencyProperty HeightProperty();
    static Windows::UI::Xaml::DependencyProperty MaxHeightProperty();
    static Windows::UI::Xaml::DependencyProperty MinHeightProperty();
};

struct WINRT_EBO RowDefinitionCollection :
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::RowDefinition>
{
    RowDefinitionCollection(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ScrollContentPresenter :
    Windows::UI::Xaml::Controls::IScrollContentPresenter,
    impl::bases<ScrollContentPresenter, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::ContentPresenter>,
    impl::require<ScrollContentPresenter, Windows::UI::Xaml::Controls::IContentPresenter, Windows::UI::Xaml::Controls::IContentPresenterOverrides, Windows::UI::Xaml::Controls::IContentPresenter2, Windows::UI::Xaml::Controls::IContentPresenter3, Windows::UI::Xaml::Controls::IContentPresenter4, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    ScrollContentPresenter(std::nullptr_t) noexcept {}
    ScrollContentPresenter();
};

struct WINRT_EBO ScrollViewer :
    Windows::UI::Xaml::Controls::IScrollViewer,
    impl::bases<ScrollViewer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl>,
    impl::require<ScrollViewer, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::Controls::IScrollViewer2, Windows::UI::Xaml::Controls::IScrollViewer3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    ScrollViewer(std::nullptr_t) noexcept {}
    ScrollViewer();
    static Windows::UI::Xaml::DependencyProperty HorizontalSnapPointsAlignmentProperty();
    static Windows::UI::Xaml::DependencyProperty VerticalSnapPointsAlignmentProperty();
    static Windows::UI::Xaml::DependencyProperty HorizontalSnapPointsTypeProperty();
    static Windows::UI::Xaml::DependencyProperty VerticalSnapPointsTypeProperty();
    static Windows::UI::Xaml::DependencyProperty ZoomSnapPointsTypeProperty();
    static Windows::UI::Xaml::DependencyProperty HorizontalOffsetProperty();
    static Windows::UI::Xaml::DependencyProperty ViewportWidthProperty();
    static Windows::UI::Xaml::DependencyProperty ScrollableWidthProperty();
    static Windows::UI::Xaml::DependencyProperty ComputedHorizontalScrollBarVisibilityProperty();
    static Windows::UI::Xaml::DependencyProperty ExtentWidthProperty();
    static Windows::UI::Xaml::DependencyProperty VerticalOffsetProperty();
    static Windows::UI::Xaml::DependencyProperty ViewportHeightProperty();
    static Windows::UI::Xaml::DependencyProperty ScrollableHeightProperty();
    static Windows::UI::Xaml::DependencyProperty ComputedVerticalScrollBarVisibilityProperty();
    static Windows::UI::Xaml::DependencyProperty ExtentHeightProperty();
    static Windows::UI::Xaml::DependencyProperty MinZoomFactorProperty();
    static Windows::UI::Xaml::DependencyProperty MaxZoomFactorProperty();
    static Windows::UI::Xaml::DependencyProperty ZoomFactorProperty();
    static Windows::UI::Xaml::DependencyProperty ZoomSnapPointsProperty();
    static Windows::UI::Xaml::DependencyProperty HorizontalScrollBarVisibilityProperty();
    static Windows::UI::Xaml::Controls::ScrollBarVisibility GetHorizontalScrollBarVisibility(const Windows::UI::Xaml::DependencyObject & element);
    static void SetHorizontalScrollBarVisibility(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::Controls::ScrollBarVisibility horizontalScrollBarVisibility);
    static Windows::UI::Xaml::DependencyProperty VerticalScrollBarVisibilityProperty();
    static Windows::UI::Xaml::Controls::ScrollBarVisibility GetVerticalScrollBarVisibility(const Windows::UI::Xaml::DependencyObject & element);
    static void SetVerticalScrollBarVisibility(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::Controls::ScrollBarVisibility verticalScrollBarVisibility);
    static Windows::UI::Xaml::DependencyProperty IsHorizontalRailEnabledProperty();
    static bool GetIsHorizontalRailEnabled(const Windows::UI::Xaml::DependencyObject & element);
    static void SetIsHorizontalRailEnabled(const Windows::UI::Xaml::DependencyObject & element, bool isHorizontalRailEnabled);
    static Windows::UI::Xaml::DependencyProperty IsVerticalRailEnabledProperty();
    static bool GetIsVerticalRailEnabled(const Windows::UI::Xaml::DependencyObject & element);
    static void SetIsVerticalRailEnabled(const Windows::UI::Xaml::DependencyObject & element, bool isVerticalRailEnabled);
    static Windows::UI::Xaml::DependencyProperty IsHorizontalScrollChainingEnabledProperty();
    static bool GetIsHorizontalScrollChainingEnabled(const Windows::UI::Xaml::DependencyObject & element);
    static void SetIsHorizontalScrollChainingEnabled(const Windows::UI::Xaml::DependencyObject & element, bool isHorizontalScrollChainingEnabled);
    static Windows::UI::Xaml::DependencyProperty IsVerticalScrollChainingEnabledProperty();
    static bool GetIsVerticalScrollChainingEnabled(const Windows::UI::Xaml::DependencyObject & element);
    static void SetIsVerticalScrollChainingEnabled(const Windows::UI::Xaml::DependencyObject & element, bool isVerticalScrollChainingEnabled);
    static Windows::UI::Xaml::DependencyProperty IsZoomChainingEnabledProperty();
    static bool GetIsZoomChainingEnabled(const Windows::UI::Xaml::DependencyObject & element);
    static void SetIsZoomChainingEnabled(const Windows::UI::Xaml::DependencyObject & element, bool isZoomChainingEnabled);
    static Windows::UI::Xaml::DependencyProperty IsScrollInertiaEnabledProperty();
    static bool GetIsScrollInertiaEnabled(const Windows::UI::Xaml::DependencyObject & element);
    static void SetIsScrollInertiaEnabled(const Windows::UI::Xaml::DependencyObject & element, bool isScrollInertiaEnabled);
    static Windows::UI::Xaml::DependencyProperty IsZoomInertiaEnabledProperty();
    static bool GetIsZoomInertiaEnabled(const Windows::UI::Xaml::DependencyObject & element);
    static void SetIsZoomInertiaEnabled(const Windows::UI::Xaml::DependencyObject & element, bool isZoomInertiaEnabled);
    static Windows::UI::Xaml::DependencyProperty HorizontalScrollModeProperty();
    static Windows::UI::Xaml::Controls::ScrollMode GetHorizontalScrollMode(const Windows::UI::Xaml::DependencyObject & element);
    static void SetHorizontalScrollMode(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::Controls::ScrollMode horizontalScrollMode);
    static Windows::UI::Xaml::DependencyProperty VerticalScrollModeProperty();
    static Windows::UI::Xaml::Controls::ScrollMode GetVerticalScrollMode(const Windows::UI::Xaml::DependencyObject & element);
    static void SetVerticalScrollMode(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::Controls::ScrollMode verticalScrollMode);
    static Windows::UI::Xaml::DependencyProperty ZoomModeProperty();
    static Windows::UI::Xaml::Controls::ZoomMode GetZoomMode(const Windows::UI::Xaml::DependencyObject & element);
    static void SetZoomMode(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::Controls::ZoomMode zoomMode);
    static Windows::UI::Xaml::DependencyProperty IsDeferredScrollingEnabledProperty();
    static bool GetIsDeferredScrollingEnabled(const Windows::UI::Xaml::DependencyObject & element);
    static void SetIsDeferredScrollingEnabled(const Windows::UI::Xaml::DependencyObject & element, bool isDeferredScrollingEnabled);
    static Windows::UI::Xaml::DependencyProperty BringIntoViewOnFocusChangeProperty();
    static bool GetBringIntoViewOnFocusChange(const Windows::UI::Xaml::DependencyObject & element);
    static void SetBringIntoViewOnFocusChange(const Windows::UI::Xaml::DependencyObject & element, bool bringIntoViewOnFocusChange);
    static Windows::UI::Xaml::DependencyProperty TopLeftHeaderProperty();
    static Windows::UI::Xaml::DependencyProperty LeftHeaderProperty();
    static Windows::UI::Xaml::DependencyProperty TopHeaderProperty();
};

struct WINRT_EBO ScrollViewerView :
    Windows::UI::Xaml::Controls::IScrollViewerView
{
    ScrollViewerView(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ScrollViewerViewChangedEventArgs :
    Windows::UI::Xaml::Controls::IScrollViewerViewChangedEventArgs
{
    ScrollViewerViewChangedEventArgs(std::nullptr_t) noexcept {}
    ScrollViewerViewChangedEventArgs();
};

struct WINRT_EBO ScrollViewerViewChangingEventArgs :
    Windows::UI::Xaml::Controls::IScrollViewerViewChangingEventArgs
{
    ScrollViewerViewChangingEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SearchBox :
    Windows::UI::Xaml::Controls::ISearchBox,
    impl::bases<SearchBox, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control>,
    impl::require<SearchBox, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    SearchBox(std::nullptr_t) noexcept {}
    SearchBox();
    static Windows::UI::Xaml::DependencyProperty SearchHistoryEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty SearchHistoryContextProperty();
    static Windows::UI::Xaml::DependencyProperty PlaceholderTextProperty();
    static Windows::UI::Xaml::DependencyProperty QueryTextProperty();
    static Windows::UI::Xaml::DependencyProperty FocusOnKeyboardInputProperty();
    static Windows::UI::Xaml::DependencyProperty ChooseSuggestionOnEnterProperty();
};

struct WINRT_EBO SearchBoxQueryChangedEventArgs :
    Windows::UI::Xaml::Controls::ISearchBoxQueryChangedEventArgs
{
    SearchBoxQueryChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SearchBoxQuerySubmittedEventArgs :
    Windows::UI::Xaml::Controls::ISearchBoxQuerySubmittedEventArgs
{
    SearchBoxQuerySubmittedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SearchBoxResultSuggestionChosenEventArgs :
    Windows::UI::Xaml::Controls::ISearchBoxResultSuggestionChosenEventArgs
{
    SearchBoxResultSuggestionChosenEventArgs(std::nullptr_t) noexcept {}
    SearchBoxResultSuggestionChosenEventArgs();
};

struct WINRT_EBO SearchBoxSuggestionsRequestedEventArgs :
    Windows::UI::Xaml::Controls::ISearchBoxSuggestionsRequestedEventArgs
{
    SearchBoxSuggestionsRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SectionsInViewChangedEventArgs :
    Windows::UI::Xaml::Controls::ISectionsInViewChangedEventArgs
{
    SectionsInViewChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SelectionChangedEventArgs :
    Windows::UI::Xaml::Controls::ISelectionChangedEventArgs,
    impl::bases<SelectionChangedEventArgs, Windows::UI::Xaml::RoutedEventArgs>,
    impl::require<SelectionChangedEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
    SelectionChangedEventArgs(std::nullptr_t) noexcept {}
    SelectionChangedEventArgs(const Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> & removedItems, const Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> & addedItems);
};

struct WINRT_EBO SemanticZoom :
    Windows::UI::Xaml::Controls::ISemanticZoom,
    impl::bases<SemanticZoom, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control>,
    impl::require<SemanticZoom, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    SemanticZoom(std::nullptr_t) noexcept {}
    SemanticZoom();
    static Windows::UI::Xaml::DependencyProperty ZoomedInViewProperty();
    static Windows::UI::Xaml::DependencyProperty ZoomedOutViewProperty();
    static Windows::UI::Xaml::DependencyProperty IsZoomedInViewActiveProperty();
    static Windows::UI::Xaml::DependencyProperty CanChangeViewsProperty();
    static Windows::UI::Xaml::DependencyProperty IsZoomOutButtonEnabledProperty();
};

struct WINRT_EBO SemanticZoomLocation :
    Windows::UI::Xaml::Controls::ISemanticZoomLocation
{
    SemanticZoomLocation(std::nullptr_t) noexcept {}
    SemanticZoomLocation();
};

struct WINRT_EBO SemanticZoomViewChangedEventArgs :
    Windows::UI::Xaml::Controls::ISemanticZoomViewChangedEventArgs
{
    SemanticZoomViewChangedEventArgs(std::nullptr_t) noexcept {}
    SemanticZoomViewChangedEventArgs();
};

struct WINRT_EBO SettingsFlyout :
    Windows::UI::Xaml::Controls::ISettingsFlyout,
    impl::bases<SettingsFlyout, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl>,
    impl::require<SettingsFlyout, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    SettingsFlyout(std::nullptr_t) noexcept {}
    SettingsFlyout();
    static Windows::UI::Xaml::DependencyProperty TitleProperty();
    static Windows::UI::Xaml::DependencyProperty HeaderBackgroundProperty();
    static Windows::UI::Xaml::DependencyProperty HeaderForegroundProperty();
    static Windows::UI::Xaml::DependencyProperty IconSourceProperty();
};

struct WINRT_EBO Slider :
    Windows::UI::Xaml::Controls::ISlider,
    impl::bases<Slider, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::Primitives::RangeBase>,
    impl::require<Slider, Windows::UI::Xaml::Controls::ISlider2, Windows::UI::Xaml::Controls::Primitives::IRangeBase, Windows::UI::Xaml::Controls::Primitives::IRangeBaseOverrides, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    Slider(std::nullptr_t) noexcept {}
    Slider();
    static Windows::UI::Xaml::DependencyProperty IntermediateValueProperty();
    static Windows::UI::Xaml::DependencyProperty StepFrequencyProperty();
    static Windows::UI::Xaml::DependencyProperty SnapsToProperty();
    static Windows::UI::Xaml::DependencyProperty TickFrequencyProperty();
    static Windows::UI::Xaml::DependencyProperty TickPlacementProperty();
    static Windows::UI::Xaml::DependencyProperty OrientationProperty();
    static Windows::UI::Xaml::DependencyProperty IsDirectionReversedProperty();
    static Windows::UI::Xaml::DependencyProperty IsThumbToolTipEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty ThumbToolTipValueConverterProperty();
    static Windows::UI::Xaml::DependencyProperty HeaderProperty();
    static Windows::UI::Xaml::DependencyProperty HeaderTemplateProperty();
};

struct WINRT_EBO SplitView :
    Windows::UI::Xaml::Controls::ISplitView,
    impl::bases<SplitView, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control>,
    impl::require<SplitView, Windows::UI::Xaml::Controls::ISplitView2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    SplitView(std::nullptr_t) noexcept {}
    SplitView();
    static Windows::UI::Xaml::DependencyProperty ContentProperty();
    static Windows::UI::Xaml::DependencyProperty PaneProperty();
    static Windows::UI::Xaml::DependencyProperty IsPaneOpenProperty();
    static Windows::UI::Xaml::DependencyProperty OpenPaneLengthProperty();
    static Windows::UI::Xaml::DependencyProperty CompactPaneLengthProperty();
    static Windows::UI::Xaml::DependencyProperty PanePlacementProperty();
    static Windows::UI::Xaml::DependencyProperty DisplayModeProperty();
    static Windows::UI::Xaml::DependencyProperty TemplateSettingsProperty();
    static Windows::UI::Xaml::DependencyProperty PaneBackgroundProperty();
    static Windows::UI::Xaml::DependencyProperty LightDismissOverlayModeProperty();
};

struct WINRT_EBO SplitViewPaneClosingEventArgs :
    Windows::UI::Xaml::Controls::ISplitViewPaneClosingEventArgs
{
    SplitViewPaneClosingEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO StackPanel :
    Windows::UI::Xaml::Controls::IStackPanel,
    impl::bases<StackPanel, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Panel>,
    impl::require<StackPanel, Windows::UI::Xaml::Controls::IInsertionPanel, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IStackPanel2, Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    StackPanel(std::nullptr_t) noexcept {}
    StackPanel();
    static Windows::UI::Xaml::DependencyProperty AreScrollSnapPointsRegularProperty();
    static Windows::UI::Xaml::DependencyProperty OrientationProperty();
    static Windows::UI::Xaml::DependencyProperty BorderBrushProperty();
    static Windows::UI::Xaml::DependencyProperty BorderThicknessProperty();
    static Windows::UI::Xaml::DependencyProperty CornerRadiusProperty();
    static Windows::UI::Xaml::DependencyProperty PaddingProperty();
};

struct WINRT_EBO StyleSelector :
    Windows::UI::Xaml::Controls::IStyleSelector,
    impl::require<StyleSelector, Windows::UI::Xaml::Controls::IStyleSelectorOverrides>
{
    StyleSelector(std::nullptr_t) noexcept {}
    StyleSelector();
};

struct WINRT_EBO SwapChainBackgroundPanel :
    Windows::UI::Xaml::Controls::ISwapChainBackgroundPanel,
    impl::bases<SwapChainBackgroundPanel, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Panel, Windows::UI::Xaml::Controls::Grid>,
    impl::require<SwapChainBackgroundPanel, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IGrid, Windows::UI::Xaml::Controls::IGrid2, Windows::UI::Xaml::Controls::ISwapChainBackgroundPanel2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    SwapChainBackgroundPanel(std::nullptr_t) noexcept {}
    SwapChainBackgroundPanel();
};

struct WINRT_EBO SwapChainPanel :
    Windows::UI::Xaml::Controls::ISwapChainPanel,
    impl::bases<SwapChainPanel, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Panel, Windows::UI::Xaml::Controls::Grid>,
    impl::require<SwapChainPanel, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IGrid, Windows::UI::Xaml::Controls::IGrid2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    SwapChainPanel(std::nullptr_t) noexcept {}
    SwapChainPanel();
    static Windows::UI::Xaml::DependencyProperty CompositionScaleXProperty();
    static Windows::UI::Xaml::DependencyProperty CompositionScaleYProperty();
};

struct WINRT_EBO SymbolIcon :
    Windows::UI::Xaml::Controls::ISymbolIcon,
    impl::bases<SymbolIcon, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::IconElement>,
    impl::require<SymbolIcon, Windows::UI::Xaml::Controls::IIconElement, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    SymbolIcon(std::nullptr_t) noexcept {}
    SymbolIcon();
    SymbolIcon(Windows::UI::Xaml::Controls::Symbol symbol);
    static Windows::UI::Xaml::DependencyProperty SymbolProperty();
};

struct WINRT_EBO TextBlock :
    Windows::UI::Xaml::Controls::ITextBlock,
    impl::bases<TextBlock, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement>,
    impl::require<TextBlock, Windows::UI::Xaml::Controls::ITextBlock2, Windows::UI::Xaml::Controls::ITextBlock3, Windows::UI::Xaml::Controls::ITextBlock4, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    TextBlock(std::nullptr_t) noexcept {}
    TextBlock();
    static Windows::UI::Xaml::DependencyProperty FontSizeProperty();
    static Windows::UI::Xaml::DependencyProperty FontFamilyProperty();
    static Windows::UI::Xaml::DependencyProperty FontWeightProperty();
    static Windows::UI::Xaml::DependencyProperty FontStyleProperty();
    static Windows::UI::Xaml::DependencyProperty FontStretchProperty();
    static Windows::UI::Xaml::DependencyProperty CharacterSpacingProperty();
    static Windows::UI::Xaml::DependencyProperty ForegroundProperty();
    static Windows::UI::Xaml::DependencyProperty TextWrappingProperty();
    static Windows::UI::Xaml::DependencyProperty TextTrimmingProperty();
    static Windows::UI::Xaml::DependencyProperty TextAlignmentProperty();
    static Windows::UI::Xaml::DependencyProperty TextProperty();
    static Windows::UI::Xaml::DependencyProperty PaddingProperty();
    static Windows::UI::Xaml::DependencyProperty LineHeightProperty();
    static Windows::UI::Xaml::DependencyProperty LineStackingStrategyProperty();
    static Windows::UI::Xaml::DependencyProperty IsTextSelectionEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty SelectedTextProperty();
    static Windows::UI::Xaml::DependencyProperty SelectionHighlightColorProperty();
    static Windows::UI::Xaml::DependencyProperty MaxLinesProperty();
    static Windows::UI::Xaml::DependencyProperty TextLineBoundsProperty();
    static Windows::UI::Xaml::DependencyProperty OpticalMarginAlignmentProperty();
    static Windows::UI::Xaml::DependencyProperty IsColorFontEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty TextReadingOrderProperty();
    static Windows::UI::Xaml::DependencyProperty IsTextScaleFactorEnabledProperty();
};

struct WINRT_EBO TextBox :
    Windows::UI::Xaml::Controls::ITextBox,
    impl::bases<TextBox, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control>,
    impl::require<TextBox, Windows::UI::Xaml::Controls::ITextBox2, Windows::UI::Xaml::Controls::ITextBox3, Windows::UI::Xaml::Controls::ITextBox4, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    TextBox(std::nullptr_t) noexcept {}
    TextBox();
    static Windows::UI::Xaml::DependencyProperty TextProperty();
    static Windows::UI::Xaml::DependencyProperty MaxLengthProperty();
    static Windows::UI::Xaml::DependencyProperty IsReadOnlyProperty();
    static Windows::UI::Xaml::DependencyProperty AcceptsReturnProperty();
    static Windows::UI::Xaml::DependencyProperty TextAlignmentProperty();
    static Windows::UI::Xaml::DependencyProperty TextWrappingProperty();
    static Windows::UI::Xaml::DependencyProperty IsSpellCheckEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty IsTextPredictionEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty InputScopeProperty();
    static Windows::UI::Xaml::DependencyProperty HeaderProperty();
    static Windows::UI::Xaml::DependencyProperty HeaderTemplateProperty();
    static Windows::UI::Xaml::DependencyProperty PlaceholderTextProperty();
    static Windows::UI::Xaml::DependencyProperty SelectionHighlightColorProperty();
    static Windows::UI::Xaml::DependencyProperty PreventKeyboardDisplayOnProgrammaticFocusProperty();
    static Windows::UI::Xaml::DependencyProperty IsColorFontEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty DesiredCandidateWindowAlignmentProperty();
    static Windows::UI::Xaml::DependencyProperty TextReadingOrderProperty();
};

struct WINRT_EBO TextBoxTextChangingEventArgs :
    Windows::UI::Xaml::Controls::ITextBoxTextChangingEventArgs
{
    TextBoxTextChangingEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO TextChangedEventArgs :
    Windows::UI::Xaml::Controls::ITextChangedEventArgs,
    impl::bases<TextChangedEventArgs, Windows::UI::Xaml::RoutedEventArgs>,
    impl::require<TextChangedEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
    TextChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO TextCompositionChangedEventArgs :
    Windows::UI::Xaml::Controls::ITextCompositionChangedEventArgs
{
    TextCompositionChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO TextCompositionEndedEventArgs :
    Windows::UI::Xaml::Controls::ITextCompositionEndedEventArgs
{
    TextCompositionEndedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO TextCompositionStartedEventArgs :
    Windows::UI::Xaml::Controls::ITextCompositionStartedEventArgs
{
    TextCompositionStartedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO TextControlPasteEventArgs :
    Windows::UI::Xaml::Controls::ITextControlPasteEventArgs
{
    TextControlPasteEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO TimePickedEventArgs :
    Windows::UI::Xaml::Controls::ITimePickedEventArgs,
    impl::bases<TimePickedEventArgs, Windows::UI::Xaml::DependencyObject>,
    impl::require<TimePickedEventArgs, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    TimePickedEventArgs(std::nullptr_t) noexcept {}
    TimePickedEventArgs();
};

struct WINRT_EBO TimePicker :
    Windows::UI::Xaml::Controls::ITimePicker,
    impl::bases<TimePicker, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control>,
    impl::require<TimePicker, Windows::UI::Xaml::Controls::ITimePicker2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    TimePicker(std::nullptr_t) noexcept {}
    TimePicker();
    static Windows::UI::Xaml::DependencyProperty HeaderProperty();
    static Windows::UI::Xaml::DependencyProperty HeaderTemplateProperty();
    static Windows::UI::Xaml::DependencyProperty ClockIdentifierProperty();
    static Windows::UI::Xaml::DependencyProperty MinuteIncrementProperty();
    static Windows::UI::Xaml::DependencyProperty TimeProperty();
    static Windows::UI::Xaml::DependencyProperty LightDismissOverlayModeProperty();
};

struct WINRT_EBO TimePickerFlyout :
    Windows::UI::Xaml::Controls::ITimePickerFlyout,
    impl::bases<TimePickerFlyout, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Controls::Primitives::FlyoutBase, Windows::UI::Xaml::Controls::Primitives::PickerFlyoutBase>,
    impl::require<TimePickerFlyout, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase, Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseOverrides, Windows::UI::Xaml::Controls::Primitives::IFlyoutBase2, Windows::UI::Xaml::Controls::Primitives::IPickerFlyoutBase, Windows::UI::Xaml::Controls::Primitives::IPickerFlyoutBaseOverrides>
{
    TimePickerFlyout(std::nullptr_t) noexcept {}
    TimePickerFlyout();
    static Windows::UI::Xaml::DependencyProperty ClockIdentifierProperty();
    static Windows::UI::Xaml::DependencyProperty TimeProperty();
    static Windows::UI::Xaml::DependencyProperty MinuteIncrementProperty();
};

struct WINRT_EBO TimePickerFlyoutPresenter :
    Windows::UI::Xaml::Controls::ITimePickerFlyoutPresenter,
    impl::bases<TimePickerFlyoutPresenter, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control>,
    impl::require<TimePickerFlyoutPresenter, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    TimePickerFlyoutPresenter(std::nullptr_t) noexcept {}
};

struct WINRT_EBO TimePickerValueChangedEventArgs :
    Windows::UI::Xaml::Controls::ITimePickerValueChangedEventArgs
{
    TimePickerValueChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ToggleMenuFlyoutItem :
    Windows::UI::Xaml::Controls::IToggleMenuFlyoutItem,
    impl::bases<ToggleMenuFlyoutItem, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::MenuFlyoutItemBase, Windows::UI::Xaml::Controls::MenuFlyoutItem>,
    impl::require<ToggleMenuFlyoutItem, Windows::UI::Xaml::Controls::IMenuFlyoutItemBase, Windows::UI::Xaml::Controls::IMenuFlyoutItem, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    ToggleMenuFlyoutItem(std::nullptr_t) noexcept {}
    ToggleMenuFlyoutItem();
    static Windows::UI::Xaml::DependencyProperty IsCheckedProperty();
};

struct WINRT_EBO ToggleSwitch :
    Windows::UI::Xaml::Controls::IToggleSwitch,
    impl::bases<ToggleSwitch, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control>,
    impl::require<ToggleSwitch, Windows::UI::Xaml::Controls::IToggleSwitchOverrides, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    ToggleSwitch(std::nullptr_t) noexcept {}
    ToggleSwitch();
    static Windows::UI::Xaml::DependencyProperty IsOnProperty();
    static Windows::UI::Xaml::DependencyProperty HeaderProperty();
    static Windows::UI::Xaml::DependencyProperty HeaderTemplateProperty();
    static Windows::UI::Xaml::DependencyProperty OnContentProperty();
    static Windows::UI::Xaml::DependencyProperty OnContentTemplateProperty();
    static Windows::UI::Xaml::DependencyProperty OffContentProperty();
    static Windows::UI::Xaml::DependencyProperty OffContentTemplateProperty();
};

struct WINRT_EBO ToolTip :
    Windows::UI::Xaml::Controls::IToolTip,
    impl::bases<ToolTip, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::ContentControl>,
    impl::require<ToolTip, Windows::UI::Xaml::Controls::IContentControl, Windows::UI::Xaml::Controls::IContentControlOverrides, Windows::UI::Xaml::Controls::IContentControl2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    ToolTip(std::nullptr_t) noexcept {}
    ToolTip();
    static Windows::UI::Xaml::DependencyProperty HorizontalOffsetProperty();
    static Windows::UI::Xaml::DependencyProperty IsOpenProperty();
    static Windows::UI::Xaml::DependencyProperty PlacementProperty();
    static Windows::UI::Xaml::DependencyProperty PlacementTargetProperty();
    static Windows::UI::Xaml::DependencyProperty VerticalOffsetProperty();
};

struct WINRT_EBO ToolTipService :
    Windows::UI::Xaml::Controls::IToolTipService
{
    ToolTipService(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::DependencyProperty PlacementProperty();
    static Windows::UI::Xaml::Controls::Primitives::PlacementMode GetPlacement(const Windows::UI::Xaml::DependencyObject & element);
    static void SetPlacement(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::Controls::Primitives::PlacementMode value);
    static Windows::UI::Xaml::DependencyProperty PlacementTargetProperty();
    static Windows::UI::Xaml::UIElement GetPlacementTarget(const Windows::UI::Xaml::DependencyObject & element);
    static void SetPlacementTarget(const Windows::UI::Xaml::DependencyObject & element, const Windows::UI::Xaml::UIElement & value);
    static Windows::UI::Xaml::DependencyProperty ToolTipProperty();
    static Windows::Foundation::IInspectable GetToolTip(const Windows::UI::Xaml::DependencyObject & element);
    static void SetToolTip(const Windows::UI::Xaml::DependencyObject & element, const Windows::Foundation::IInspectable & value);
};

struct WINRT_EBO UIElementCollection :
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::UIElement>,
    impl::require<UIElementCollection, Windows::UI::Xaml::Controls::IUIElementCollection>
{
    UIElementCollection(std::nullptr_t) noexcept {}
};

struct WINRT_EBO UserControl :
    Windows::UI::Xaml::Controls::IUserControl,
    impl::bases<UserControl, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Control>,
    impl::require<UserControl, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Controls::IControl, Windows::UI::Xaml::Controls::IControlOverrides, Windows::UI::Xaml::Controls::IControl2, Windows::UI::Xaml::Controls::IControl3, Windows::UI::Xaml::Controls::IControl4>
{
    UserControl(std::nullptr_t) noexcept {}
    UserControl();
    static Windows::UI::Xaml::DependencyProperty ContentProperty();
};

struct WINRT_EBO VariableSizedWrapGrid :
    Windows::UI::Xaml::Controls::IVariableSizedWrapGrid,
    impl::bases<VariableSizedWrapGrid, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Panel>,
    impl::require<VariableSizedWrapGrid, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    VariableSizedWrapGrid(std::nullptr_t) noexcept {}
    VariableSizedWrapGrid();
    static Windows::UI::Xaml::DependencyProperty ItemHeightProperty();
    static Windows::UI::Xaml::DependencyProperty ItemWidthProperty();
    static Windows::UI::Xaml::DependencyProperty OrientationProperty();
    static Windows::UI::Xaml::DependencyProperty HorizontalChildrenAlignmentProperty();
    static Windows::UI::Xaml::DependencyProperty VerticalChildrenAlignmentProperty();
    static Windows::UI::Xaml::DependencyProperty MaximumRowsOrColumnsProperty();
    static Windows::UI::Xaml::DependencyProperty RowSpanProperty();
    static int32_t GetRowSpan(const Windows::UI::Xaml::UIElement & element);
    static void SetRowSpan(const Windows::UI::Xaml::UIElement & element, int32_t value);
    static Windows::UI::Xaml::DependencyProperty ColumnSpanProperty();
    static int32_t GetColumnSpan(const Windows::UI::Xaml::UIElement & element);
    static void SetColumnSpan(const Windows::UI::Xaml::UIElement & element, int32_t value);
};

struct WINRT_EBO Viewbox :
    Windows::UI::Xaml::Controls::IViewbox,
    impl::bases<Viewbox, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement>,
    impl::require<Viewbox, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    Viewbox(std::nullptr_t) noexcept {}
    Viewbox();
    static Windows::UI::Xaml::DependencyProperty StretchProperty();
    static Windows::UI::Xaml::DependencyProperty StretchDirectionProperty();
};

struct WINRT_EBO VirtualizingPanel :
    Windows::UI::Xaml::Controls::IVirtualizingPanel,
    impl::bases<VirtualizingPanel, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Panel>,
    impl::require<VirtualizingPanel, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IVirtualizingPanelOverrides, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    VirtualizingPanel(std::nullptr_t) noexcept {}
};

struct WINRT_EBO VirtualizingStackPanel :
    Windows::UI::Xaml::Controls::IVirtualizingStackPanel,
    impl::bases<VirtualizingStackPanel, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Panel, Windows::UI::Xaml::Controls::VirtualizingPanel, Windows::UI::Xaml::Controls::Primitives::OrientedVirtualizingPanel>,
    impl::require<VirtualizingStackPanel, Windows::UI::Xaml::Controls::IInsertionPanel, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IVirtualizingPanel, Windows::UI::Xaml::Controls::IVirtualizingPanelOverrides, Windows::UI::Xaml::Controls::IVirtualizingStackPanelOverrides, Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo, Windows::UI::Xaml::Controls::Primitives::IOrientedVirtualizingPanel, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    VirtualizingStackPanel(std::nullptr_t) noexcept {}
    VirtualizingStackPanel();
    static Windows::UI::Xaml::DependencyProperty AreScrollSnapPointsRegularProperty();
    static Windows::UI::Xaml::DependencyProperty OrientationProperty();
    static Windows::UI::Xaml::DependencyProperty VirtualizationModeProperty();
    static Windows::UI::Xaml::Controls::VirtualizationMode GetVirtualizationMode(const Windows::UI::Xaml::DependencyObject & element);
    static void SetVirtualizationMode(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::Controls::VirtualizationMode value);
    static Windows::UI::Xaml::DependencyProperty IsVirtualizingProperty();
    static bool GetIsVirtualizing(const Windows::UI::Xaml::DependencyObject & o);
};

struct WINRT_EBO WebView :
    Windows::UI::Xaml::Controls::IWebView,
    impl::bases<WebView, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement>,
    impl::require<WebView, Windows::UI::Xaml::Controls::IWebView2, Windows::UI::Xaml::Controls::IWebView3, Windows::UI::Xaml::Controls::IWebView4, Windows::UI::Xaml::Controls::IWebView5, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    WebView(std::nullptr_t) noexcept {}
    WebView();
    WebView(Windows::UI::Xaml::Controls::WebViewExecutionMode executionMode);
    [[deprecated("AnyScriptNotifyUri is unavailable for releases beginning with Windows 8.1. Instead, list URIs under ApplicationContentUriRules in the package manifest. For more info, see the AnyScriptNotifyUri documentation.")]] static Windows::Foundation::Collections::IVector<Windows::Foundation::Uri> AnyScriptNotifyUri();
    static Windows::UI::Xaml::DependencyProperty SourceProperty();
    [[deprecated("AllowedScriptNotifyUris is unavailable for releases beginning with Windows 8.1. Instead, list URIs under ApplicationContentUriRules in the package manifest. For more info, see the AllowedScriptNotifyUris documentation.")]] static Windows::UI::Xaml::DependencyProperty AllowedScriptNotifyUrisProperty();
    [[deprecated("Use CaptureSelectedContentToDataPackageAsync instead of DataTransferPackage. For more info, see MSDN.")]] static Windows::UI::Xaml::DependencyProperty DataTransferPackageProperty();
    static Windows::UI::Xaml::DependencyProperty CanGoBackProperty();
    static Windows::UI::Xaml::DependencyProperty CanGoForwardProperty();
    static Windows::UI::Xaml::DependencyProperty DocumentTitleProperty();
    static Windows::UI::Xaml::DependencyProperty DefaultBackgroundColorProperty();
    static Windows::UI::Xaml::DependencyProperty ContainsFullScreenElementProperty();
    static Windows::UI::Xaml::Controls::WebViewExecutionMode DefaultExecutionMode();
    static Windows::Foundation::IAsyncAction ClearTemporaryWebDataAsync();
    static Windows::UI::Xaml::DependencyProperty XYFocusLeftProperty();
    static Windows::UI::Xaml::DependencyProperty XYFocusRightProperty();
    static Windows::UI::Xaml::DependencyProperty XYFocusUpProperty();
    static Windows::UI::Xaml::DependencyProperty XYFocusDownProperty();
};

struct WINRT_EBO WebViewBrush :
    Windows::UI::Xaml::Controls::IWebViewBrush,
    impl::bases<WebViewBrush, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Brush, Windows::UI::Xaml::Media::TileBrush>,
    impl::require<WebViewBrush, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IBrush, Windows::UI::Xaml::Media::ITileBrush>
{
    WebViewBrush(std::nullptr_t) noexcept {}
    WebViewBrush();
    static Windows::UI::Xaml::DependencyProperty SourceNameProperty();
};

struct WINRT_EBO WebViewContentLoadingEventArgs :
    Windows::UI::Xaml::Controls::IWebViewContentLoadingEventArgs
{
    WebViewContentLoadingEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WebViewDOMContentLoadedEventArgs :
    Windows::UI::Xaml::Controls::IWebViewDOMContentLoadedEventArgs
{
    WebViewDOMContentLoadedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WebViewDeferredPermissionRequest :
    Windows::UI::Xaml::Controls::IWebViewDeferredPermissionRequest
{
    WebViewDeferredPermissionRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WebViewLongRunningScriptDetectedEventArgs :
    Windows::UI::Xaml::Controls::IWebViewLongRunningScriptDetectedEventArgs
{
    WebViewLongRunningScriptDetectedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WebViewNavigationCompletedEventArgs :
    Windows::UI::Xaml::Controls::IWebViewNavigationCompletedEventArgs
{
    WebViewNavigationCompletedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WebViewNavigationFailedEventArgs :
    Windows::UI::Xaml::Controls::IWebViewNavigationFailedEventArgs
{
    WebViewNavigationFailedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WebViewNavigationStartingEventArgs :
    Windows::UI::Xaml::Controls::IWebViewNavigationStartingEventArgs
{
    WebViewNavigationStartingEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WebViewNewWindowRequestedEventArgs :
    Windows::UI::Xaml::Controls::IWebViewNewWindowRequestedEventArgs
{
    WebViewNewWindowRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WebViewPermissionRequest :
    Windows::UI::Xaml::Controls::IWebViewPermissionRequest
{
    WebViewPermissionRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WebViewPermissionRequestedEventArgs :
    Windows::UI::Xaml::Controls::IWebViewPermissionRequestedEventArgs
{
    WebViewPermissionRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WebViewSettings :
    Windows::UI::Xaml::Controls::IWebViewSettings
{
    WebViewSettings(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WebViewUnsupportedUriSchemeIdentifiedEventArgs :
    Windows::UI::Xaml::Controls::IWebViewUnsupportedUriSchemeIdentifiedEventArgs
{
    WebViewUnsupportedUriSchemeIdentifiedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WebViewUnviewableContentIdentifiedEventArgs :
    Windows::UI::Xaml::Controls::IWebViewUnviewableContentIdentifiedEventArgs,
    impl::require<WebViewUnviewableContentIdentifiedEventArgs, Windows::UI::Xaml::Controls::IWebViewUnviewableContentIdentifiedEventArgs2>
{
    WebViewUnviewableContentIdentifiedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WrapGrid :
    Windows::UI::Xaml::Controls::IWrapGrid,
    impl::bases<WrapGrid, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::Controls::Panel, Windows::UI::Xaml::Controls::VirtualizingPanel, Windows::UI::Xaml::Controls::Primitives::OrientedVirtualizingPanel>,
    impl::require<WrapGrid, Windows::UI::Xaml::Controls::IInsertionPanel, Windows::UI::Xaml::Controls::IPanel, Windows::UI::Xaml::Controls::IVirtualizingPanel, Windows::UI::Xaml::Controls::IVirtualizingPanelOverrides, Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo, Windows::UI::Xaml::Controls::Primitives::IOrientedVirtualizingPanel, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    WrapGrid(std::nullptr_t) noexcept {}
    WrapGrid();
    static Windows::UI::Xaml::DependencyProperty ItemWidthProperty();
    static Windows::UI::Xaml::DependencyProperty ItemHeightProperty();
    static Windows::UI::Xaml::DependencyProperty OrientationProperty();
    static Windows::UI::Xaml::DependencyProperty HorizontalChildrenAlignmentProperty();
    static Windows::UI::Xaml::DependencyProperty VerticalChildrenAlignmentProperty();
    static Windows::UI::Xaml::DependencyProperty MaximumRowsOrColumnsProperty();
};

}

}
