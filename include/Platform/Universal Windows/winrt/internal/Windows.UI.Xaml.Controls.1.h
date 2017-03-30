// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.UI.Xaml.Controls.0.h"
#include "Windows.ApplicationModel.DataTransfer.0.h"
#include "Windows.ApplicationModel.Search.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Foundation.Collections.0.h"
#include "Windows.Globalization.0.h"
#include "Windows.Media.Capture.0.h"
#include "Windows.Media.Casting.0.h"
#include "Windows.Media.Core.0.h"
#include "Windows.Media.PlayTo.0.h"
#include "Windows.Media.Playback.0.h"
#include "Windows.Media.Protection.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.System.0.h"
#include "Windows.UI.0.h"
#include "Windows.UI.Composition.0.h"
#include "Windows.UI.Core.0.h"
#include "Windows.UI.Input.Inking.0.h"
#include "Windows.UI.Text.0.h"
#include "Windows.UI.Xaml.0.h"
#include "Windows.UI.Xaml.Controls.Primitives.0.h"
#include "Windows.UI.Xaml.Data.0.h"
#include "Windows.UI.Xaml.Documents.0.h"
#include "Windows.UI.Xaml.Input.0.h"
#include "Windows.UI.Xaml.Interop.0.h"
#include "Windows.UI.Xaml.Media.0.h"
#include "Windows.UI.Xaml.Media.Animation.0.h"
#include "Windows.UI.Xaml.Navigation.0.h"
#include "Windows.Web.0.h"
#include "Windows.Web.Http.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"
#include "Windows.UI.Xaml.1.h"
#include "Windows.UI.Xaml.Media.1.h"
#include "Windows.UI.Xaml.Data.1.h"
#include "Windows.ApplicationModel.DataTransfer.1.h"
#include "Windows.UI.1.h"
#include "Windows.UI.Xaml.Navigation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Xaml::Controls {

struct __declspec(uuid("fa9bc21f-9892-482e-abf6-eb2d607d32de")) __declspec(novtable) BackClickEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::Controls::IBackClickEventArgs * e) = 0;
};

struct __declspec(uuid("8d745891-4de3-49cb-974b-083871a3afe6")) __declspec(novtable) CalendarViewDayItemChangingEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::UI::Xaml::Controls::ICalendarView * sender, Windows::UI::Xaml::Controls::ICalendarViewDayItemChangingEventArgs * e) = 0;
};

struct __declspec(uuid("cacad0d6-0f0d-4870-884d-f2dedf674288")) __declspec(novtable) CleanUpVirtualizedItemEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::Controls::ICleanUpVirtualizedItemEventArgs * e) = 0;
};

struct __declspec(uuid("df945151-745c-4446-b2fc-216d765847a0")) __declspec(novtable) ContextMenuOpeningEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::Controls::IContextMenuEventArgs * e) = 0;
};

struct __declspec(uuid("3aaeab4c-14cb-4434-becc-88a8585c2f89")) __declspec(novtable) DragItemsStartingEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::Controls::IDragItemsStartingEventArgs * e) = 0;
};

struct __declspec(uuid("afe17b9b-9c63-4583-88e4-c59019b7f49d")) __declspec(novtable) HubSectionHeaderClickEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::Controls::IHubSectionHeaderClickEventArgs * e) = 0;
};

struct __declspec(uuid("7b0fc253-86a5-4b43-9872-0b8a6234b74b")) __declspec(novtable) IAppBar : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsOpen(bool * value) = 0;
    virtual HRESULT __stdcall put_IsOpen(bool value) = 0;
    virtual HRESULT __stdcall get_IsSticky(bool * value) = 0;
    virtual HRESULT __stdcall put_IsSticky(bool value) = 0;
    virtual HRESULT __stdcall add_Opened(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Opened(event_token token) = 0;
    virtual HRESULT __stdcall add_Closed(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Closed(event_token token) = 0;
};

struct __declspec(uuid("c3ab17b3-7ad7-4676-9910-7fe3f0e8e993")) __declspec(novtable) IAppBar2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ClosedDisplayMode(winrt::Windows::UI::Xaml::Controls::AppBarClosedDisplayMode * value) = 0;
    virtual HRESULT __stdcall put_ClosedDisplayMode(winrt::Windows::UI::Xaml::Controls::AppBarClosedDisplayMode value) = 0;
};

struct __declspec(uuid("982b001f-752e-4e7a-b055-54802c9ea749")) __declspec(novtable) IAppBar3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TemplateSettings(Windows::UI::Xaml::Controls::Primitives::IAppBarTemplateSettings ** value) = 0;
    virtual HRESULT __stdcall add_Opening(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Opening(event_token token) = 0;
    virtual HRESULT __stdcall add_Closing(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Closing(event_token token) = 0;
};

struct __declspec(uuid("94ebc8cd-0a64-4da3-bf43-f13100a46605")) __declspec(novtable) IAppBar4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LightDismissOverlayMode(winrt::Windows::UI::Xaml::Controls::LightDismissOverlayMode * value) = 0;
    virtual HRESULT __stdcall put_LightDismissOverlayMode(winrt::Windows::UI::Xaml::Controls::LightDismissOverlayMode value) = 0;
};

struct __declspec(uuid("4459a451-69e8-440c-9896-4bb4f5f642d1")) __declspec(novtable) IAppBarButton : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Label(hstring * value) = 0;
    virtual HRESULT __stdcall put_Label(hstring value) = 0;
    virtual HRESULT __stdcall get_Icon(Windows::UI::Xaml::Controls::IIconElement ** value) = 0;
    virtual HRESULT __stdcall put_Icon(Windows::UI::Xaml::Controls::IIconElement * value) = 0;
};

struct __declspec(uuid("0b282150-198b-4e84-8f1c-9f6a8ba267a7")) __declspec(novtable) IAppBarButton3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LabelPosition(winrt::Windows::UI::Xaml::Controls::CommandBarLabelPosition * value) = 0;
    virtual HRESULT __stdcall put_LabelPosition(winrt::Windows::UI::Xaml::Controls::CommandBarLabelPosition value) = 0;
};

struct __declspec(uuid("bdbb1bb6-cb2e-4276-abd6-7935130510e0")) __declspec(novtable) IAppBarButtonFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IAppBarButton ** instance) = 0;
};

struct __declspec(uuid("7ccd13e6-5301-407f-874e-dc9160aa07af")) __declspec(novtable) IAppBarButtonStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LabelProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IconProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsCompactProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("4d7bf314-2ede-4328-8906-752a1f27cdfa")) __declspec(novtable) IAppBarButtonStatics3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LabelPositionProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsInOverflowProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_DynamicOverflowOrderProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("614708d1-8e65-43cb-92d7-8eee17515f8d")) __declspec(novtable) IAppBarFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IAppBar ** instance) = 0;
};

struct __declspec(uuid("f003e4e2-7b0f-4f4a-970d-ae8a0eaa9b70")) __declspec(novtable) IAppBarOverrides : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_OnClosed(Windows::Foundation::IInspectable * e) = 0;
    virtual HRESULT __stdcall abi_OnOpened(Windows::Foundation::IInspectable * e) = 0;
};

struct __declspec(uuid("412bbbc8-51d0-4b49-ab62-a3dd6bdcb298")) __declspec(novtable) IAppBarOverrides3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_OnClosing(Windows::Foundation::IInspectable * e) = 0;
    virtual HRESULT __stdcall abi_OnOpening(Windows::Foundation::IInspectable * e) = 0;
};

struct __declspec(uuid("1b0795a1-1bc1-4d53-95ea-fb0a2cccc905")) __declspec(novtable) IAppBarSeparator : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("05da25cd-f407-48de-8b50-ff87d1e2818f")) __declspec(novtable) IAppBarSeparatorFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IAppBarSeparator ** instance) = 0;
};

struct __declspec(uuid("37f23484-5b35-4663-a75d-f2d50cb9c619")) __declspec(novtable) IAppBarSeparatorStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsCompactProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("36c753f9-7373-4e5e-9ba4-c3622a003c4e")) __declspec(novtable) IAppBarSeparatorStatics3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsInOverflowProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_DynamicOverflowOrderProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("79bb7e8d-dca9-4b5f-a448-37b13238ed76")) __declspec(novtable) IAppBarStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsOpenProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsStickyProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("222355e9-0384-49de-8738-dfc9d409ac5d")) __declspec(novtable) IAppBarStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ClosedDisplayModeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("ba02082e-1165-4451-94b3-eb3ac73e4196")) __declspec(novtable) IAppBarStatics4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LightDismissOverlayModeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("2e914438-fd53-4b8d-858b-3644269f8e4d")) __declspec(novtable) IAppBarToggleButton : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Label(hstring * value) = 0;
    virtual HRESULT __stdcall put_Label(hstring value) = 0;
    virtual HRESULT __stdcall get_Icon(Windows::UI::Xaml::Controls::IIconElement ** value) = 0;
    virtual HRESULT __stdcall put_Icon(Windows::UI::Xaml::Controls::IIconElement * value) = 0;
};

struct __declspec(uuid("ef9a85e5-16ff-4d72-b9e8-9b861eaf84a8")) __declspec(novtable) IAppBarToggleButton3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LabelPosition(winrt::Windows::UI::Xaml::Controls::CommandBarLabelPosition * value) = 0;
    virtual HRESULT __stdcall put_LabelPosition(winrt::Windows::UI::Xaml::Controls::CommandBarLabelPosition value) = 0;
};

struct __declspec(uuid("028aa7d4-8f54-45a6-9f90-13605656d793")) __declspec(novtable) IAppBarToggleButtonFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IAppBarToggleButton ** instance) = 0;
};

struct __declspec(uuid("fe5aaf96-7929-4da1-aa67-cddf73a3e4b5")) __declspec(novtable) IAppBarToggleButtonStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LabelProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IconProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsCompactProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("bd4c65bf-2edd-44d1-acd5-35c00e2f21bc")) __declspec(novtable) IAppBarToggleButtonStatics3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LabelPositionProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsInOverflowProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_DynamicOverflowOrderProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("103e9b13-3400-4a16-90b9-6912bf06974f")) __declspec(novtable) IAutoSuggestBox : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MaxSuggestionListHeight(double * value) = 0;
    virtual HRESULT __stdcall put_MaxSuggestionListHeight(double value) = 0;
    virtual HRESULT __stdcall get_IsSuggestionListOpen(bool * value) = 0;
    virtual HRESULT __stdcall put_IsSuggestionListOpen(bool value) = 0;
    virtual HRESULT __stdcall get_TextMemberPath(hstring * value) = 0;
    virtual HRESULT __stdcall put_TextMemberPath(hstring value) = 0;
    virtual HRESULT __stdcall get_Text(hstring * value) = 0;
    virtual HRESULT __stdcall put_Text(hstring value) = 0;
    virtual HRESULT __stdcall get_UpdateTextOnSelect(bool * value) = 0;
    virtual HRESULT __stdcall put_UpdateTextOnSelect(bool value) = 0;
    virtual HRESULT __stdcall get_PlaceholderText(hstring * value) = 0;
    virtual HRESULT __stdcall put_PlaceholderText(hstring value) = 0;
    virtual HRESULT __stdcall get_Header(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_Header(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_AutoMaximizeSuggestionArea(bool * value) = 0;
    virtual HRESULT __stdcall put_AutoMaximizeSuggestionArea(bool value) = 0;
    virtual HRESULT __stdcall get_TextBoxStyle(Windows::UI::Xaml::IStyle ** value) = 0;
    virtual HRESULT __stdcall put_TextBoxStyle(Windows::UI::Xaml::IStyle * value) = 0;
    virtual HRESULT __stdcall add_SuggestionChosen(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::AutoSuggestBox, Windows::UI::Xaml::Controls::AutoSuggestBoxSuggestionChosenEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SuggestionChosen(event_token token) = 0;
    virtual HRESULT __stdcall add_TextChanged(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::AutoSuggestBox, Windows::UI::Xaml::Controls::AutoSuggestBoxTextChangedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_TextChanged(event_token token) = 0;
};

struct __declspec(uuid("aa87ddde-e679-45b2-a7c9-9aedc39db886")) __declspec(novtable) IAutoSuggestBox2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_QueryIcon(Windows::UI::Xaml::Controls::IIconElement ** value) = 0;
    virtual HRESULT __stdcall put_QueryIcon(Windows::UI::Xaml::Controls::IIconElement * value) = 0;
    virtual HRESULT __stdcall add_QuerySubmitted(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::AutoSuggestBox, Windows::UI::Xaml::Controls::AutoSuggestBoxQuerySubmittedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_QuerySubmitted(event_token token) = 0;
};

struct __declspec(uuid("9bbbfcef-f32d-402e-9009-05bdbaf6336e")) __declspec(novtable) IAutoSuggestBox3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LightDismissOverlayMode(winrt::Windows::UI::Xaml::Controls::LightDismissOverlayMode * value) = 0;
    virtual HRESULT __stdcall put_LightDismissOverlayMode(winrt::Windows::UI::Xaml::Controls::LightDismissOverlayMode value) = 0;
};

struct __declspec(uuid("78dcb116-818a-4cb5-bca7-382ce6ddc90d")) __declspec(novtable) IAutoSuggestBoxQuerySubmittedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_QueryText(hstring * value) = 0;
    virtual HRESULT __stdcall get_ChosenSuggestion(Windows::Foundation::IInspectable ** value) = 0;
};

struct __declspec(uuid("ee22c7f4-c15d-4ff3-8a94-f50dfdfbe89a")) __declspec(novtable) IAutoSuggestBoxStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MaxSuggestionListHeightProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsSuggestionListOpenProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TextMemberPathProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TextProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_UpdateTextOnSelectProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PlaceholderTextProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_HeaderProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_AutoMaximizeSuggestionAreaProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TextBoxStyleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("1cd297a8-8e6a-41ef-a95d-7157dc0c7106")) __declspec(novtable) IAutoSuggestBoxStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_QueryIconProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("2cead2dd-c4d5-4ab2-8a13-afddcf067c86")) __declspec(novtable) IAutoSuggestBoxStatics3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LightDismissOverlayModeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("396f7254-1ed5-4bc5-a060-655530bca6ba")) __declspec(novtable) IAutoSuggestBoxSuggestionChosenEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SelectedItem(Windows::Foundation::IInspectable ** value) = 0;
};

struct __declspec(uuid("3a6f7254-1ed5-4bc5-a060-655530bca6ba")) __declspec(novtable) IAutoSuggestBoxTextChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Reason(winrt::Windows::UI::Xaml::Controls::AutoSuggestionBoxTextChangeReason * value) = 0;
    virtual HRESULT __stdcall put_Reason(winrt::Windows::UI::Xaml::Controls::AutoSuggestionBoxTextChangeReason value) = 0;
    virtual HRESULT __stdcall abi_CheckCurrent(bool * returnValue) = 0;
};

struct __declspec(uuid("fef7772b-9f45-44db-8c27-bda3f933e7b5")) __declspec(novtable) IAutoSuggestBoxTextChangedEventArgsStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ReasonProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("2ae6146c-477e-48c9-8830-2c464b7c7104")) __declspec(novtable) IBackClickEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Handled(bool * value) = 0;
    virtual HRESULT __stdcall put_Handled(bool value) = 0;
};

struct __declspec(uuid("e8fe17cb-35f7-40f3-a185-48b397b73e68")) __declspec(novtable) IBitmapIcon : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_UriSource(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall put_UriSource(Windows::Foundation::IUriRuntimeClass * value) = 0;
};

struct __declspec(uuid("46d64b1d-7a49-4f66-9729-2848c788e402")) __declspec(novtable) IBitmapIconFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IBitmapIcon ** instance) = 0;
};

struct __declspec(uuid("e072d117-e4e7-4e0c-9470-53ff1ce84f67")) __declspec(novtable) IBitmapIconStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_UriSourceProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("797c4539-45bd-4633-a044-bfb02ef5170f")) __declspec(novtable) IBorder : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_BorderBrush(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall put_BorderBrush(Windows::UI::Xaml::Media::IBrush * value) = 0;
    virtual HRESULT __stdcall get_BorderThickness(Windows::UI::Xaml::Thickness * value) = 0;
    virtual HRESULT __stdcall put_BorderThickness(Windows::UI::Xaml::Thickness value) = 0;
    virtual HRESULT __stdcall get_Background(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall put_Background(Windows::UI::Xaml::Media::IBrush * value) = 0;
    virtual HRESULT __stdcall get_CornerRadius(Windows::UI::Xaml::CornerRadius * value) = 0;
    virtual HRESULT __stdcall put_CornerRadius(Windows::UI::Xaml::CornerRadius value) = 0;
    virtual HRESULT __stdcall get_Padding(Windows::UI::Xaml::Thickness * value) = 0;
    virtual HRESULT __stdcall put_Padding(Windows::UI::Xaml::Thickness value) = 0;
    virtual HRESULT __stdcall get_Child(Windows::UI::Xaml::IUIElement ** value) = 0;
    virtual HRESULT __stdcall put_Child(Windows::UI::Xaml::IUIElement * value) = 0;
    virtual HRESULT __stdcall get_ChildTransitions(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Animation::Transition> ** value) = 0;
    virtual HRESULT __stdcall put_ChildTransitions(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Animation::Transition> * value) = 0;
};

struct __declspec(uuid("b81d1639-e911-4fd7-a4c4-b9c7f008b7fc")) __declspec(novtable) IBorderStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_BorderBrushProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_BorderThicknessProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_BackgroundProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CornerRadiusProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PaddingProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ChildTransitionsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("280335ae-5570-46c7-8e0b-602be71229a2")) __declspec(novtable) IButton : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("80a13c19-843a-451c-8cf5-44c701b0e216")) __declspec(novtable) IButtonFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IButton ** instance) = 0;
};

struct __declspec(uuid("90143898-a16c-4759-b2f0-a5f7e625169e")) __declspec(novtable) IButtonStaticsWithFlyout : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FlyoutProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("09108f87-df6c-4180-9b3a-e60845825811")) __declspec(novtable) IButtonWithFlyout : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Flyout(Windows::UI::Xaml::Controls::Primitives::IFlyoutBase ** value) = 0;
    virtual HRESULT __stdcall put_Flyout(Windows::UI::Xaml::Controls::Primitives::IFlyoutBase * value) = 0;
};

struct __declspec(uuid("63c9c16f-668c-4491-9444-d45d8bf4fa29")) __declspec(novtable) ICalendarDatePicker : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Date(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall put_Date(Windows::Foundation::IReference<Windows::Foundation::DateTime> * value) = 0;
    virtual HRESULT __stdcall get_IsCalendarOpen(bool * value) = 0;
    virtual HRESULT __stdcall put_IsCalendarOpen(bool value) = 0;
    virtual HRESULT __stdcall get_DateFormat(hstring * value) = 0;
    virtual HRESULT __stdcall put_DateFormat(hstring value) = 0;
    virtual HRESULT __stdcall get_PlaceholderText(hstring * value) = 0;
    virtual HRESULT __stdcall put_PlaceholderText(hstring value) = 0;
    virtual HRESULT __stdcall get_Header(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_Header(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_HeaderTemplate(Windows::UI::Xaml::IDataTemplate ** value) = 0;
    virtual HRESULT __stdcall put_HeaderTemplate(Windows::UI::Xaml::IDataTemplate * value) = 0;
    virtual HRESULT __stdcall get_CalendarViewStyle(Windows::UI::Xaml::IStyle ** value) = 0;
    virtual HRESULT __stdcall put_CalendarViewStyle(Windows::UI::Xaml::IStyle * value) = 0;
    virtual HRESULT __stdcall get_MinDate(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall put_MinDate(Windows::Foundation::DateTime value) = 0;
    virtual HRESULT __stdcall get_MaxDate(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall put_MaxDate(Windows::Foundation::DateTime value) = 0;
    virtual HRESULT __stdcall get_IsTodayHighlighted(bool * value) = 0;
    virtual HRESULT __stdcall put_IsTodayHighlighted(bool value) = 0;
    virtual HRESULT __stdcall get_DisplayMode(winrt::Windows::UI::Xaml::Controls::CalendarViewDisplayMode * value) = 0;
    virtual HRESULT __stdcall put_DisplayMode(winrt::Windows::UI::Xaml::Controls::CalendarViewDisplayMode value) = 0;
    virtual HRESULT __stdcall get_FirstDayOfWeek(winrt::Windows::Globalization::DayOfWeek * value) = 0;
    virtual HRESULT __stdcall put_FirstDayOfWeek(winrt::Windows::Globalization::DayOfWeek value) = 0;
    virtual HRESULT __stdcall get_DayOfWeekFormat(hstring * value) = 0;
    virtual HRESULT __stdcall put_DayOfWeekFormat(hstring value) = 0;
    virtual HRESULT __stdcall get_CalendarIdentifier(hstring * value) = 0;
    virtual HRESULT __stdcall put_CalendarIdentifier(hstring value) = 0;
    virtual HRESULT __stdcall get_IsOutOfScopeEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsOutOfScopeEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsGroupLabelVisible(bool * value) = 0;
    virtual HRESULT __stdcall put_IsGroupLabelVisible(bool value) = 0;
    virtual HRESULT __stdcall add_CalendarViewDayItemChanging(Windows::UI::Xaml::Controls::CalendarViewDayItemChangingEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_CalendarViewDayItemChanging(event_token token) = 0;
    virtual HRESULT __stdcall add_DateChanged(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::CalendarDatePicker, Windows::UI::Xaml::Controls::CalendarDatePickerDateChangedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DateChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_Opened(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Opened(event_token token) = 0;
    virtual HRESULT __stdcall add_Closed(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Closed(event_token token) = 0;
    virtual HRESULT __stdcall abi_SetDisplayDate(Windows::Foundation::DateTime date) = 0;
    virtual HRESULT __stdcall abi_SetYearDecadeDisplayDimensions(int32_t columns, int32_t rows) = 0;
};

struct __declspec(uuid("b216c159-2411-4a60-a7aa-27416b49481e")) __declspec(novtable) ICalendarDatePicker2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LightDismissOverlayMode(winrt::Windows::UI::Xaml::Controls::LightDismissOverlayMode * value) = 0;
    virtual HRESULT __stdcall put_LightDismissOverlayMode(winrt::Windows::UI::Xaml::Controls::LightDismissOverlayMode value) = 0;
};

struct __declspec(uuid("60d90db2-5010-46ba-842d-a4152c6504e7")) __declspec(novtable) ICalendarDatePickerDateChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_NewDate(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall get_OldDate(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
};

struct __declspec(uuid("107aad5d-38be-42af-a957-fc86a5cf1e9a")) __declspec(novtable) ICalendarDatePickerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::ICalendarDatePicker ** instance) = 0;
};

struct __declspec(uuid("39a3d291-afab-4b94-8395-ba7b874e3c8c")) __declspec(novtable) ICalendarDatePickerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsCalendarOpenProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_DateFormatProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PlaceholderTextProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_HeaderProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_HeaderTemplateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CalendarViewStyleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MinDateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MaxDateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsTodayHighlightedProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_DisplayModeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FirstDayOfWeekProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_DayOfWeekFormatProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CalendarIdentifierProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsOutOfScopeEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsGroupLabelVisibleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("30206b58-a2f6-4a00-8d13-33c46b6b8e0d")) __declspec(novtable) ICalendarDatePickerStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LightDismissOverlayModeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("cd639203-dfb5-4312-ac07-c0391824607b")) __declspec(novtable) ICalendarView : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CalendarIdentifier(hstring * value) = 0;
    virtual HRESULT __stdcall put_CalendarIdentifier(hstring value) = 0;
    virtual HRESULT __stdcall get_DayOfWeekFormat(hstring * value) = 0;
    virtual HRESULT __stdcall put_DayOfWeekFormat(hstring value) = 0;
    virtual HRESULT __stdcall get_IsGroupLabelVisible(bool * value) = 0;
    virtual HRESULT __stdcall put_IsGroupLabelVisible(bool value) = 0;
    virtual HRESULT __stdcall get_DisplayMode(winrt::Windows::UI::Xaml::Controls::CalendarViewDisplayMode * value) = 0;
    virtual HRESULT __stdcall put_DisplayMode(winrt::Windows::UI::Xaml::Controls::CalendarViewDisplayMode value) = 0;
    virtual HRESULT __stdcall get_FirstDayOfWeek(winrt::Windows::Globalization::DayOfWeek * value) = 0;
    virtual HRESULT __stdcall put_FirstDayOfWeek(winrt::Windows::Globalization::DayOfWeek value) = 0;
    virtual HRESULT __stdcall get_IsOutOfScopeEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsOutOfScopeEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsTodayHighlighted(bool * value) = 0;
    virtual HRESULT __stdcall put_IsTodayHighlighted(bool value) = 0;
    virtual HRESULT __stdcall get_MaxDate(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall put_MaxDate(Windows::Foundation::DateTime value) = 0;
    virtual HRESULT __stdcall get_MinDate(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall put_MinDate(Windows::Foundation::DateTime value) = 0;
    virtual HRESULT __stdcall get_NumberOfWeeksInView(int32_t * value) = 0;
    virtual HRESULT __stdcall put_NumberOfWeeksInView(int32_t value) = 0;
    virtual HRESULT __stdcall get_SelectedDates(Windows::Foundation::Collections::IVector<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall get_SelectionMode(winrt::Windows::UI::Xaml::Controls::CalendarViewSelectionMode * value) = 0;
    virtual HRESULT __stdcall put_SelectionMode(winrt::Windows::UI::Xaml::Controls::CalendarViewSelectionMode value) = 0;
    virtual HRESULT __stdcall get_TemplateSettings(Windows::UI::Xaml::Controls::Primitives::ICalendarViewTemplateSettings ** value) = 0;
    virtual HRESULT __stdcall get_FocusBorderBrush(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall put_FocusBorderBrush(Windows::UI::Xaml::Media::IBrush * value) = 0;
    virtual HRESULT __stdcall get_SelectedHoverBorderBrush(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall put_SelectedHoverBorderBrush(Windows::UI::Xaml::Media::IBrush * value) = 0;
    virtual HRESULT __stdcall get_SelectedPressedBorderBrush(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall put_SelectedPressedBorderBrush(Windows::UI::Xaml::Media::IBrush * value) = 0;
    virtual HRESULT __stdcall get_SelectedBorderBrush(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall put_SelectedBorderBrush(Windows::UI::Xaml::Media::IBrush * value) = 0;
    virtual HRESULT __stdcall get_HoverBorderBrush(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall put_HoverBorderBrush(Windows::UI::Xaml::Media::IBrush * value) = 0;
    virtual HRESULT __stdcall get_PressedBorderBrush(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall put_PressedBorderBrush(Windows::UI::Xaml::Media::IBrush * value) = 0;
    virtual HRESULT __stdcall get_CalendarItemBorderBrush(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall put_CalendarItemBorderBrush(Windows::UI::Xaml::Media::IBrush * value) = 0;
    virtual HRESULT __stdcall get_OutOfScopeBackground(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall put_OutOfScopeBackground(Windows::UI::Xaml::Media::IBrush * value) = 0;
    virtual HRESULT __stdcall get_CalendarItemBackground(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall put_CalendarItemBackground(Windows::UI::Xaml::Media::IBrush * value) = 0;
    virtual HRESULT __stdcall get_PressedForeground(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall put_PressedForeground(Windows::UI::Xaml::Media::IBrush * value) = 0;
    virtual HRESULT __stdcall get_TodayForeground(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall put_TodayForeground(Windows::UI::Xaml::Media::IBrush * value) = 0;
    virtual HRESULT __stdcall get_BlackoutForeground(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall put_BlackoutForeground(Windows::UI::Xaml::Media::IBrush * value) = 0;
    virtual HRESULT __stdcall get_SelectedForeground(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall put_SelectedForeground(Windows::UI::Xaml::Media::IBrush * value) = 0;
    virtual HRESULT __stdcall get_OutOfScopeForeground(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall put_OutOfScopeForeground(Windows::UI::Xaml::Media::IBrush * value) = 0;
    virtual HRESULT __stdcall get_CalendarItemForeground(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall put_CalendarItemForeground(Windows::UI::Xaml::Media::IBrush * value) = 0;
    virtual HRESULT __stdcall get_DayItemFontFamily(Windows::UI::Xaml::Media::IFontFamily ** value) = 0;
    virtual HRESULT __stdcall put_DayItemFontFamily(Windows::UI::Xaml::Media::IFontFamily * value) = 0;
    virtual HRESULT __stdcall get_DayItemFontSize(double * value) = 0;
    virtual HRESULT __stdcall put_DayItemFontSize(double value) = 0;
    virtual HRESULT __stdcall get_DayItemFontStyle(winrt::Windows::UI::Text::FontStyle * value) = 0;
    virtual HRESULT __stdcall put_DayItemFontStyle(winrt::Windows::UI::Text::FontStyle value) = 0;
    virtual HRESULT __stdcall get_DayItemFontWeight(Windows::UI::Text::FontWeight * value) = 0;
    virtual HRESULT __stdcall put_DayItemFontWeight(Windows::UI::Text::FontWeight value) = 0;
    virtual HRESULT __stdcall get_TodayFontWeight(Windows::UI::Text::FontWeight * value) = 0;
    virtual HRESULT __stdcall put_TodayFontWeight(Windows::UI::Text::FontWeight value) = 0;
    virtual HRESULT __stdcall get_FirstOfMonthLabelFontFamily(Windows::UI::Xaml::Media::IFontFamily ** value) = 0;
    virtual HRESULT __stdcall put_FirstOfMonthLabelFontFamily(Windows::UI::Xaml::Media::IFontFamily * value) = 0;
    virtual HRESULT __stdcall get_FirstOfMonthLabelFontSize(double * value) = 0;
    virtual HRESULT __stdcall put_FirstOfMonthLabelFontSize(double value) = 0;
    virtual HRESULT __stdcall get_FirstOfMonthLabelFontStyle(winrt::Windows::UI::Text::FontStyle * value) = 0;
    virtual HRESULT __stdcall put_FirstOfMonthLabelFontStyle(winrt::Windows::UI::Text::FontStyle value) = 0;
    virtual HRESULT __stdcall get_FirstOfMonthLabelFontWeight(Windows::UI::Text::FontWeight * value) = 0;
    virtual HRESULT __stdcall put_FirstOfMonthLabelFontWeight(Windows::UI::Text::FontWeight value) = 0;
    virtual HRESULT __stdcall get_MonthYearItemFontFamily(Windows::UI::Xaml::Media::IFontFamily ** value) = 0;
    virtual HRESULT __stdcall put_MonthYearItemFontFamily(Windows::UI::Xaml::Media::IFontFamily * value) = 0;
    virtual HRESULT __stdcall get_MonthYearItemFontSize(double * value) = 0;
    virtual HRESULT __stdcall put_MonthYearItemFontSize(double value) = 0;
    virtual HRESULT __stdcall get_MonthYearItemFontStyle(winrt::Windows::UI::Text::FontStyle * value) = 0;
    virtual HRESULT __stdcall put_MonthYearItemFontStyle(winrt::Windows::UI::Text::FontStyle value) = 0;
    virtual HRESULT __stdcall get_MonthYearItemFontWeight(Windows::UI::Text::FontWeight * value) = 0;
    virtual HRESULT __stdcall put_MonthYearItemFontWeight(Windows::UI::Text::FontWeight value) = 0;
    virtual HRESULT __stdcall get_FirstOfYearDecadeLabelFontFamily(Windows::UI::Xaml::Media::IFontFamily ** value) = 0;
    virtual HRESULT __stdcall put_FirstOfYearDecadeLabelFontFamily(Windows::UI::Xaml::Media::IFontFamily * value) = 0;
    virtual HRESULT __stdcall get_FirstOfYearDecadeLabelFontSize(double * value) = 0;
    virtual HRESULT __stdcall put_FirstOfYearDecadeLabelFontSize(double value) = 0;
    virtual HRESULT __stdcall get_FirstOfYearDecadeLabelFontStyle(winrt::Windows::UI::Text::FontStyle * value) = 0;
    virtual HRESULT __stdcall put_FirstOfYearDecadeLabelFontStyle(winrt::Windows::UI::Text::FontStyle value) = 0;
    virtual HRESULT __stdcall get_FirstOfYearDecadeLabelFontWeight(Windows::UI::Text::FontWeight * value) = 0;
    virtual HRESULT __stdcall put_FirstOfYearDecadeLabelFontWeight(Windows::UI::Text::FontWeight value) = 0;
    virtual HRESULT __stdcall get_HorizontalDayItemAlignment(winrt::Windows::UI::Xaml::HorizontalAlignment * value) = 0;
    virtual HRESULT __stdcall put_HorizontalDayItemAlignment(winrt::Windows::UI::Xaml::HorizontalAlignment value) = 0;
    virtual HRESULT __stdcall get_VerticalDayItemAlignment(winrt::Windows::UI::Xaml::VerticalAlignment * value) = 0;
    virtual HRESULT __stdcall put_VerticalDayItemAlignment(winrt::Windows::UI::Xaml::VerticalAlignment value) = 0;
    virtual HRESULT __stdcall get_HorizontalFirstOfMonthLabelAlignment(winrt::Windows::UI::Xaml::HorizontalAlignment * value) = 0;
    virtual HRESULT __stdcall put_HorizontalFirstOfMonthLabelAlignment(winrt::Windows::UI::Xaml::HorizontalAlignment value) = 0;
    virtual HRESULT __stdcall get_VerticalFirstOfMonthLabelAlignment(winrt::Windows::UI::Xaml::VerticalAlignment * value) = 0;
    virtual HRESULT __stdcall put_VerticalFirstOfMonthLabelAlignment(winrt::Windows::UI::Xaml::VerticalAlignment value) = 0;
    virtual HRESULT __stdcall get_CalendarItemBorderThickness(Windows::UI::Xaml::Thickness * value) = 0;
    virtual HRESULT __stdcall put_CalendarItemBorderThickness(Windows::UI::Xaml::Thickness value) = 0;
    virtual HRESULT __stdcall get_CalendarViewDayItemStyle(Windows::UI::Xaml::IStyle ** value) = 0;
    virtual HRESULT __stdcall put_CalendarViewDayItemStyle(Windows::UI::Xaml::IStyle * value) = 0;
    virtual HRESULT __stdcall add_CalendarViewDayItemChanging(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::CalendarView, Windows::UI::Xaml::Controls::CalendarViewDayItemChangingEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_CalendarViewDayItemChanging(event_token token) = 0;
    virtual HRESULT __stdcall add_SelectedDatesChanged(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::CalendarView, Windows::UI::Xaml::Controls::CalendarViewSelectedDatesChangedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SelectedDatesChanged(event_token token) = 0;
    virtual HRESULT __stdcall abi_SetDisplayDate(Windows::Foundation::DateTime date) = 0;
    virtual HRESULT __stdcall abi_SetYearDecadeDisplayDimensions(int32_t columns, int32_t rows) = 0;
};

struct __declspec(uuid("0fdb2dc5-32c1-4b8f-befc-017b555b32d2")) __declspec(novtable) ICalendarViewDayItem : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsBlackout(bool * value) = 0;
    virtual HRESULT __stdcall put_IsBlackout(bool value) = 0;
    virtual HRESULT __stdcall get_Date(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall abi_SetDensityColors(Windows::Foundation::Collections::IIterable<Windows::UI::Color> * colors) = 0;
};

struct __declspec(uuid("73146666-1fb1-44f9-b7ad-4de859ecc565")) __declspec(novtable) ICalendarViewDayItemChangingEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_InRecycleQueue(bool * value) = 0;
    virtual HRESULT __stdcall get_Item(Windows::UI::Xaml::Controls::ICalendarViewDayItem ** value) = 0;
    virtual HRESULT __stdcall get_Phase(uint32_t * value) = 0;
    virtual HRESULT __stdcall abi_RegisterUpdateCallback(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::CalendarView, Windows::UI::Xaml::Controls::CalendarViewDayItemChangingEventArgs> * callback) = 0;
    virtual HRESULT __stdcall abi_RegisterUpdateCallbackWithPhase(uint32_t callbackPhase, Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::CalendarView, Windows::UI::Xaml::Controls::CalendarViewDayItemChangingEventArgs> * callback) = 0;
};

struct __declspec(uuid("62112bdc-1d2f-4e44-9baf-1665749521f2")) __declspec(novtable) ICalendarViewDayItemFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::ICalendarViewDayItem ** instance) = 0;
};

struct __declspec(uuid("c3a1dbbf-bd88-488b-b916-d00d69b1735a")) __declspec(novtable) ICalendarViewDayItemStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsBlackoutProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_DateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("3d8f82e3-6cc6-423e-8d7c-7014d954ddef")) __declspec(novtable) ICalendarViewFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::ICalendarView ** instance) = 0;
};

struct __declspec(uuid("ee6069f6-13ef-4896-8ffc-5302b1b17539")) __declspec(novtable) ICalendarViewSelectedDatesChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AddedDates(Windows::Foundation::Collections::IVectorView<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall get_RemovedDates(Windows::Foundation::Collections::IVectorView<Windows::Foundation::DateTime> ** value) = 0;
};

struct __declspec(uuid("7260f1c4-2f5d-41bd-99bb-4571b20b79a8")) __declspec(novtable) ICalendarViewStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CalendarIdentifierProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_DayOfWeekFormatProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsGroupLabelVisibleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_DisplayModeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FirstDayOfWeekProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsOutOfScopeEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsTodayHighlightedProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MaxDateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MinDateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_NumberOfWeeksInViewProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SelectedDatesProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SelectionModeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TemplateSettingsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FocusBorderBrushProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SelectedHoverBorderBrushProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SelectedPressedBorderBrushProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SelectedBorderBrushProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_HoverBorderBrushProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PressedBorderBrushProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CalendarItemBorderBrushProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_OutOfScopeBackgroundProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CalendarItemBackgroundProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PressedForegroundProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TodayForegroundProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_BlackoutForegroundProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SelectedForegroundProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_OutOfScopeForegroundProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CalendarItemForegroundProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_DayItemFontFamilyProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_DayItemFontSizeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_DayItemFontStyleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_DayItemFontWeightProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TodayFontWeightProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FirstOfMonthLabelFontFamilyProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FirstOfMonthLabelFontSizeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FirstOfMonthLabelFontStyleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FirstOfMonthLabelFontWeightProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MonthYearItemFontFamilyProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MonthYearItemFontSizeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MonthYearItemFontStyleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MonthYearItemFontWeightProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FirstOfYearDecadeLabelFontFamilyProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FirstOfYearDecadeLabelFontSizeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FirstOfYearDecadeLabelFontStyleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FirstOfYearDecadeLabelFontWeightProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_HorizontalDayItemAlignmentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_VerticalDayItemAlignmentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_HorizontalFirstOfMonthLabelAlignmentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_VerticalFirstOfMonthLabelAlignmentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CalendarItemBorderThicknessProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CalendarViewDayItemStyleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("8a946458-83b0-4c32-9450-5169a5838b55")) __declspec(novtable) ICandidateWindowBoundsChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Bounds(Windows::Foundation::Rect * value) = 0;
};

struct __declspec(uuid("79190e19-cd38-4823-aeae-64a77132f519")) __declspec(novtable) ICanvas : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("1b328bd1-b400-4a8e-943b-5ad2c45be0df")) __declspec(novtable) ICanvasFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::ICanvas ** instance) = 0;
};

struct __declspec(uuid("40ce5c46-2962-446f-aafb-4cdc486939c9")) __declspec(novtable) ICanvasStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LeftProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetLeft(Windows::UI::Xaml::IUIElement * element, double * length) = 0;
    virtual HRESULT __stdcall abi_SetLeft(Windows::UI::Xaml::IUIElement * element, double length) = 0;
    virtual HRESULT __stdcall get_TopProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetTop(Windows::UI::Xaml::IUIElement * element, double * length) = 0;
    virtual HRESULT __stdcall abi_SetTop(Windows::UI::Xaml::IUIElement * element, double length) = 0;
    virtual HRESULT __stdcall get_ZIndexProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetZIndex(Windows::UI::Xaml::IUIElement * element, int32_t * value) = 0;
    virtual HRESULT __stdcall abi_SetZIndex(Windows::UI::Xaml::IUIElement * element, int32_t value) = 0;
};

struct __declspec(uuid("31a5c0e7-f307-4d4a-b626-e978863f5b74")) __declspec(novtable) ICaptureElement : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Source(Windows::Media::Capture::IMediaCapture ** value) = 0;
    virtual HRESULT __stdcall put_Source(Windows::Media::Capture::IMediaCapture * value) = 0;
    virtual HRESULT __stdcall get_Stretch(winrt::Windows::UI::Xaml::Media::Stretch * value) = 0;
    virtual HRESULT __stdcall put_Stretch(winrt::Windows::UI::Xaml::Media::Stretch value) = 0;
};

struct __declspec(uuid("1e438ded-7da6-409e-806e-305ae4ad9b3f")) __declspec(novtable) ICaptureElementStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SourceProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_StretchProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("2294c894-7e2a-4b70-b088-8f5d814875ba")) __declspec(novtable) ICheckBox : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("4fa6aabb-3f4b-4301-be07-1172ea61eefb")) __declspec(novtable) ICheckBoxFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::ICheckBox ** instance) = 0;
};

struct __declspec(uuid("67db44d6-d201-4d72-beac-5e8e58afd8c7")) __declspec(novtable) IChoosingGroupHeaderContainerEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_GroupHeaderContainer(Windows::UI::Xaml::Controls::IListViewBaseHeaderItem ** value) = 0;
    virtual HRESULT __stdcall put_GroupHeaderContainer(Windows::UI::Xaml::Controls::IListViewBaseHeaderItem * value) = 0;
    virtual HRESULT __stdcall get_GroupIndex(int32_t * value) = 0;
    virtual HRESULT __stdcall get_Group(Windows::Foundation::IInspectable ** value) = 0;
};

struct __declspec(uuid("9bb43bce-ae67-4a80-8363-e3fe1b244f2c")) __declspec(novtable) IChoosingItemContainerEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ItemIndex(int32_t * value) = 0;
    virtual HRESULT __stdcall get_Item(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall get_ItemContainer(Windows::UI::Xaml::Controls::Primitives::ISelectorItem ** value) = 0;
    virtual HRESULT __stdcall put_ItemContainer(Windows::UI::Xaml::Controls::Primitives::ISelectorItem * value) = 0;
    virtual HRESULT __stdcall get_IsContainerPrepared(bool * value) = 0;
    virtual HRESULT __stdcall put_IsContainerPrepared(bool value) = 0;
};

struct __declspec(uuid("ea05cce9-937c-4120-8406-792185784338")) __declspec(novtable) ICleanUpVirtualizedItemEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Value(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall get_UIElement(Windows::UI::Xaml::IUIElement ** value) = 0;
    virtual HRESULT __stdcall get_Cancel(bool * value) = 0;
    virtual HRESULT __stdcall put_Cancel(bool value) = 0;
};

struct __declspec(uuid("f7f1b229-f024-467f-970a-7e705615db7b")) __declspec(novtable) IColumnDefinition : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Width(Windows::UI::Xaml::GridLength * value) = 0;
    virtual HRESULT __stdcall put_Width(Windows::UI::Xaml::GridLength value) = 0;
    virtual HRESULT __stdcall get_MaxWidth(double * value) = 0;
    virtual HRESULT __stdcall put_MaxWidth(double value) = 0;
    virtual HRESULT __stdcall get_MinWidth(double * value) = 0;
    virtual HRESULT __stdcall put_MinWidth(double value) = 0;
    virtual HRESULT __stdcall get_ActualWidth(double * value) = 0;
};

struct __declspec(uuid("06b0d728-d044-40c6-942e-ae60eac74851")) __declspec(novtable) IColumnDefinitionStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_WidthProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MaxWidthProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MinWidthProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("b9a8d05c-ac97-47f1-a5f4-3f9f4d4b116c")) __declspec(novtable) IComboBox : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsDropDownOpen(bool * value) = 0;
    virtual HRESULT __stdcall put_IsDropDownOpen(bool value) = 0;
    virtual HRESULT __stdcall get_IsEditable(bool * value) = 0;
    virtual HRESULT __stdcall get_IsSelectionBoxHighlighted(bool * value) = 0;
    virtual HRESULT __stdcall get_MaxDropDownHeight(double * value) = 0;
    virtual HRESULT __stdcall put_MaxDropDownHeight(double value) = 0;
    virtual HRESULT __stdcall get_SelectionBoxItem(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall get_SelectionBoxItemTemplate(Windows::UI::Xaml::IDataTemplate ** value) = 0;
    virtual HRESULT __stdcall get_TemplateSettings(Windows::UI::Xaml::Controls::Primitives::IComboBoxTemplateSettings ** value) = 0;
    virtual HRESULT __stdcall add_DropDownClosed(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DropDownClosed(event_token token) = 0;
    virtual HRESULT __stdcall add_DropDownOpened(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DropDownOpened(event_token token) = 0;
};

struct __declspec(uuid("ea0cbf91-ca36-4fad-972a-2e53a6718b9f")) __declspec(novtable) IComboBox2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Header(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_Header(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_HeaderTemplate(Windows::UI::Xaml::IDataTemplate ** value) = 0;
    virtual HRESULT __stdcall put_HeaderTemplate(Windows::UI::Xaml::IDataTemplate * value) = 0;
    virtual HRESULT __stdcall get_PlaceholderText(hstring * value) = 0;
    virtual HRESULT __stdcall put_PlaceholderText(hstring value) = 0;
};

struct __declspec(uuid("52400a63-476c-4bb6-b781-019324d3fed9")) __declspec(novtable) IComboBox3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LightDismissOverlayMode(winrt::Windows::UI::Xaml::Controls::LightDismissOverlayMode * value) = 0;
    virtual HRESULT __stdcall put_LightDismissOverlayMode(winrt::Windows::UI::Xaml::Controls::LightDismissOverlayMode value) = 0;
    virtual HRESULT __stdcall get_IsTextSearchEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsTextSearchEnabled(bool value) = 0;
};

struct __declspec(uuid("ac0d0444-a65b-4abd-86df-3016049efedc")) __declspec(novtable) IComboBoxFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IComboBox ** instance) = 0;
};

struct __declspec(uuid("993fd6d2-2aae-4f3b-b44d-5648f4d06114")) __declspec(novtable) IComboBoxItem : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("8fffe867-d94c-4e87-8fc4-6ebcd63c5ac2")) __declspec(novtable) IComboBoxItemFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IComboBoxItem ** instance) = 0;
};

struct __declspec(uuid("4f016541-bcfe-4a22-8932-c914981c2240")) __declspec(novtable) IComboBoxOverrides : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_OnDropDownClosed(Windows::Foundation::IInspectable * e) = 0;
    virtual HRESULT __stdcall abi_OnDropDownOpened(Windows::Foundation::IInspectable * e) = 0;
};

struct __declspec(uuid("3e14c9b1-d15b-4dc9-8110-cf3a117b96e7")) __declspec(novtable) IComboBoxStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsDropDownOpenProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MaxDropDownHeightProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("93988a11-402c-4b13-96d1-7220266b9220")) __declspec(novtable) IComboBoxStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_HeaderProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_HeaderTemplateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PlaceholderTextProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("949e140f-ce7f-4e41-bdc5-d1d3388ad0a6")) __declspec(novtable) IComboBoxStatics3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LightDismissOverlayModeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsTextSearchEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("98bc4280-4a3d-4cee-bd07-22ce94c5af76")) __declspec(novtable) ICommandBar : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PrimaryCommands(Windows::Foundation::Collections::IObservableVector<Windows::UI::Xaml::Controls::ICommandBarElement> ** value) = 0;
    virtual HRESULT __stdcall get_SecondaryCommands(Windows::Foundation::Collections::IObservableVector<Windows::UI::Xaml::Controls::ICommandBarElement> ** value) = 0;
};

struct __declspec(uuid("57662f58-5b32-475d-be64-4ca36e7b97d4")) __declspec(novtable) ICommandBar2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CommandBarOverflowPresenterStyle(Windows::UI::Xaml::IStyle ** value) = 0;
    virtual HRESULT __stdcall put_CommandBarOverflowPresenterStyle(Windows::UI::Xaml::IStyle * value) = 0;
    virtual HRESULT __stdcall get_CommandBarTemplateSettings(Windows::UI::Xaml::Controls::Primitives::ICommandBarTemplateSettings ** value) = 0;
};

struct __declspec(uuid("40ebbc23-2a79-48b3-9a67-649b852d8589")) __declspec(novtable) ICommandBar3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DefaultLabelPosition(winrt::Windows::UI::Xaml::Controls::CommandBarDefaultLabelPosition * value) = 0;
    virtual HRESULT __stdcall put_DefaultLabelPosition(winrt::Windows::UI::Xaml::Controls::CommandBarDefaultLabelPosition value) = 0;
    virtual HRESULT __stdcall get_OverflowButtonVisibility(winrt::Windows::UI::Xaml::Controls::CommandBarOverflowButtonVisibility * value) = 0;
    virtual HRESULT __stdcall put_OverflowButtonVisibility(winrt::Windows::UI::Xaml::Controls::CommandBarOverflowButtonVisibility value) = 0;
    virtual HRESULT __stdcall get_IsDynamicOverflowEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsDynamicOverflowEnabled(bool value) = 0;
    virtual HRESULT __stdcall add_DynamicOverflowItemsChanging(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::CommandBar, Windows::UI::Xaml::Controls::DynamicOverflowItemsChangingEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DynamicOverflowItemsChanging(event_token token) = 0;
};

struct __declspec(uuid("67918e1b-f2d5-44d1-8b84-92b87f80a350")) __declspec(novtable) ICommandBarElement : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsCompact(bool * value) = 0;
    virtual HRESULT __stdcall put_IsCompact(bool value) = 0;
};

struct __declspec(uuid("a9bf1236-4402-4688-b987-9d2b9b7bf2bd")) __declspec(novtable) ICommandBarElement2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsInOverflow(bool * value) = 0;
    virtual HRESULT __stdcall get_DynamicOverflowOrder(int32_t * value) = 0;
    virtual HRESULT __stdcall put_DynamicOverflowOrder(int32_t value) = 0;
};

struct __declspec(uuid("67bdeb44-20e1-4177-ad44-f617b374e8e8")) __declspec(novtable) ICommandBarFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::ICommandBar ** instance) = 0;
};

struct __declspec(uuid("6e7a9427-58ef-4366-a017-18c193d56b14")) __declspec(novtable) ICommandBarOverflowPresenter : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("8323f774-5aaa-4049-b78f-218c6a19c37e")) __declspec(novtable) ICommandBarOverflowPresenterFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::ICommandBarOverflowPresenter ** instance) = 0;
};

struct __declspec(uuid("5bd981ea-e278-409c-b522-f946ca253b44")) __declspec(novtable) ICommandBarStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PrimaryCommandsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SecondaryCommandsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("3d9ec8e3-51a9-4e34-956c-7081d06f26f8")) __declspec(novtable) ICommandBarStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CommandBarOverflowPresenterStyleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("b45a24a4-8af1-4843-b319-e03fc45ab726")) __declspec(novtable) ICommandBarStatics3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DefaultLabelPositionProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_OverflowButtonVisibilityProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsDynamicOverflowEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("07deeaa7-018f-4dda-b399-fd4e13a31bea")) __declspec(novtable) IContainerContentChangingEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ItemContainer(Windows::UI::Xaml::Controls::Primitives::ISelectorItem ** value) = 0;
    virtual HRESULT __stdcall get_InRecycleQueue(bool * value) = 0;
    virtual HRESULT __stdcall get_ItemIndex(int32_t * value) = 0;
    virtual HRESULT __stdcall get_Item(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall get_Phase(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_Handled(bool * value) = 0;
    virtual HRESULT __stdcall put_Handled(bool value) = 0;
    virtual HRESULT __stdcall abi_RegisterUpdateCallback(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::ListViewBase, Windows::UI::Xaml::Controls::ContainerContentChangingEventArgs> * callback) = 0;
    virtual HRESULT __stdcall abi_RegisterUpdateCallbackWithPhase(uint32_t callbackPhase, Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::ListViewBase, Windows::UI::Xaml::Controls::ContainerContentChangingEventArgs> * callback) = 0;
};

struct __declspec(uuid("a26dd1dc-cd44-435c-be94-01d6241c231c")) __declspec(novtable) IContentControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Content(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_Content(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_ContentTemplate(Windows::UI::Xaml::IDataTemplate ** value) = 0;
    virtual HRESULT __stdcall put_ContentTemplate(Windows::UI::Xaml::IDataTemplate * value) = 0;
    virtual HRESULT __stdcall get_ContentTemplateSelector(Windows::UI::Xaml::Controls::IDataTemplateSelector ** value) = 0;
    virtual HRESULT __stdcall put_ContentTemplateSelector(Windows::UI::Xaml::Controls::IDataTemplateSelector * value) = 0;
    virtual HRESULT __stdcall get_ContentTransitions(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Animation::Transition> ** value) = 0;
    virtual HRESULT __stdcall put_ContentTransitions(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Animation::Transition> * value) = 0;
};

struct __declspec(uuid("652c208c-8ccf-4399-bd3e-5a015aa1bc03")) __declspec(novtable) IContentControl2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ContentTemplateRoot(Windows::UI::Xaml::IUIElement ** value) = 0;
};

struct __declspec(uuid("ab017b19-196e-4ed5-a27f-55c58fb1673f")) __declspec(novtable) IContentControlFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IContentControl ** instance) = 0;
};

struct __declspec(uuid("5f4c0b10-e38e-4b5d-be1a-5ed04246a635")) __declspec(novtable) IContentControlOverrides : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_OnContentChanged(Windows::Foundation::IInspectable * oldContent, Windows::Foundation::IInspectable * newContent) = 0;
    virtual HRESULT __stdcall abi_OnContentTemplateChanged(Windows::UI::Xaml::IDataTemplate * oldContentTemplate, Windows::UI::Xaml::IDataTemplate * newContentTemplate) = 0;
    virtual HRESULT __stdcall abi_OnContentTemplateSelectorChanged(Windows::UI::Xaml::Controls::IDataTemplateSelector * oldContentTemplateSelector, Windows::UI::Xaml::Controls::IDataTemplateSelector * newContentTemplateSelector) = 0;
};

struct __declspec(uuid("116982a4-5cf5-4c05-a53f-15e4876c85ec")) __declspec(novtable) IContentControlStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ContentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ContentTemplateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ContentTemplateSelectorProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ContentTransitionsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("38dc4404-d24e-40d8-9415-349464c1afdc")) __declspec(novtable) IContentDialog : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Title(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_Title(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_TitleTemplate(Windows::UI::Xaml::IDataTemplate ** value) = 0;
    virtual HRESULT __stdcall put_TitleTemplate(Windows::UI::Xaml::IDataTemplate * value) = 0;
    virtual HRESULT __stdcall get_FullSizeDesired(bool * value) = 0;
    virtual HRESULT __stdcall put_FullSizeDesired(bool value) = 0;
    virtual HRESULT __stdcall get_PrimaryButtonText(hstring * value) = 0;
    virtual HRESULT __stdcall put_PrimaryButtonText(hstring value) = 0;
    virtual HRESULT __stdcall get_SecondaryButtonText(hstring * value) = 0;
    virtual HRESULT __stdcall put_SecondaryButtonText(hstring value) = 0;
    virtual HRESULT __stdcall get_PrimaryButtonCommand(Windows::UI::Xaml::Input::ICommand ** value) = 0;
    virtual HRESULT __stdcall put_PrimaryButtonCommand(Windows::UI::Xaml::Input::ICommand * value) = 0;
    virtual HRESULT __stdcall get_SecondaryButtonCommand(Windows::UI::Xaml::Input::ICommand ** value) = 0;
    virtual HRESULT __stdcall put_SecondaryButtonCommand(Windows::UI::Xaml::Input::ICommand * value) = 0;
    virtual HRESULT __stdcall get_PrimaryButtonCommandParameter(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_PrimaryButtonCommandParameter(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_SecondaryButtonCommandParameter(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_SecondaryButtonCommandParameter(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_IsPrimaryButtonEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsPrimaryButtonEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsSecondaryButtonEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsSecondaryButtonEnabled(bool value) = 0;
    virtual HRESULT __stdcall add_Closing(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::ContentDialog, Windows::UI::Xaml::Controls::ContentDialogClosingEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Closing(event_token token) = 0;
    virtual HRESULT __stdcall add_Closed(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::ContentDialog, Windows::UI::Xaml::Controls::ContentDialogClosedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Closed(event_token token) = 0;
    virtual HRESULT __stdcall add_Opened(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::ContentDialog, Windows::UI::Xaml::Controls::ContentDialogOpenedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Opened(event_token token) = 0;
    virtual HRESULT __stdcall add_PrimaryButtonClick(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::ContentDialog, Windows::UI::Xaml::Controls::ContentDialogButtonClickEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PrimaryButtonClick(event_token token) = 0;
    virtual HRESULT __stdcall add_SecondaryButtonClick(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::ContentDialog, Windows::UI::Xaml::Controls::ContentDialogButtonClickEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SecondaryButtonClick(event_token token) = 0;
    virtual HRESULT __stdcall abi_Hide() = 0;
    virtual HRESULT __stdcall abi_ShowAsync(Windows::Foundation::IAsyncOperation<winrt::Windows::UI::Xaml::Controls::ContentDialogResult> ** returnValue) = 0;
};

struct __declspec(uuid("bd0d3637-19ce-4946-8e77-bd03fe8ebe03")) __declspec(novtable) IContentDialogButtonClickDeferral : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Complete() = 0;
};

struct __declspec(uuid("5f34c205-8afa-4cf2-8ca0-264d73bed63d")) __declspec(novtable) IContentDialogButtonClickEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Cancel(bool * value) = 0;
    virtual HRESULT __stdcall put_Cancel(bool value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::UI::Xaml::Controls::IContentDialogButtonClickDeferral ** returnValue) = 0;
};

struct __declspec(uuid("905522ef-2cba-4af8-b666-cc36c22732fb")) __declspec(novtable) IContentDialogClosedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Result(winrt::Windows::UI::Xaml::Controls::ContentDialogResult * value) = 0;
};

struct __declspec(uuid("215d4d11-7e30-4cb9-a710-5a4f9cca8b42")) __declspec(novtable) IContentDialogClosingDeferral : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Complete() = 0;
};

struct __declspec(uuid("db3c1c34-3bbf-47d4-be4f-c9ec115918b9")) __declspec(novtable) IContentDialogClosingEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Result(winrt::Windows::UI::Xaml::Controls::ContentDialogResult * value) = 0;
    virtual HRESULT __stdcall get_Cancel(bool * value) = 0;
    virtual HRESULT __stdcall put_Cancel(bool value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::UI::Xaml::Controls::IContentDialogClosingDeferral ** returnValue) = 0;
};

struct __declspec(uuid("05557178-9d8e-4315-b37d-680c14012c35")) __declspec(novtable) IContentDialogFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IContentDialog ** instance) = 0;
};

struct __declspec(uuid("0966b315-5f59-4999-9e3e-374c0f174b04")) __declspec(novtable) IContentDialogOpenedEventArgs : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("23ab47a6-508a-4f33-b786-f2fa96d869af")) __declspec(novtable) IContentDialogStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TitleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TitleTemplateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FullSizeDesiredProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PrimaryButtonTextProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SecondaryButtonTextProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PrimaryButtonCommandProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SecondaryButtonCommandProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PrimaryButtonCommandParameterProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SecondaryButtonCommandParameterProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsPrimaryButtonEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsSecondaryButtonEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("79fde5b4-cd37-491c-8845-daf472defff6")) __declspec(novtable) IContentPresenter : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Content(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_Content(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_ContentTemplate(Windows::UI::Xaml::IDataTemplate ** value) = 0;
    virtual HRESULT __stdcall put_ContentTemplate(Windows::UI::Xaml::IDataTemplate * value) = 0;
    virtual HRESULT __stdcall get_ContentTemplateSelector(Windows::UI::Xaml::Controls::IDataTemplateSelector ** value) = 0;
    virtual HRESULT __stdcall put_ContentTemplateSelector(Windows::UI::Xaml::Controls::IDataTemplateSelector * value) = 0;
    virtual HRESULT __stdcall get_ContentTransitions(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Animation::Transition> ** value) = 0;
    virtual HRESULT __stdcall put_ContentTransitions(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Animation::Transition> * value) = 0;
    virtual HRESULT __stdcall get_FontSize(double * value) = 0;
    virtual HRESULT __stdcall put_FontSize(double value) = 0;
    virtual HRESULT __stdcall get_FontFamily(Windows::UI::Xaml::Media::IFontFamily ** value) = 0;
    virtual HRESULT __stdcall put_FontFamily(Windows::UI::Xaml::Media::IFontFamily * value) = 0;
    virtual HRESULT __stdcall get_FontWeight(Windows::UI::Text::FontWeight * value) = 0;
    virtual HRESULT __stdcall put_FontWeight(Windows::UI::Text::FontWeight value) = 0;
    virtual HRESULT __stdcall get_FontStyle(winrt::Windows::UI::Text::FontStyle * value) = 0;
    virtual HRESULT __stdcall put_FontStyle(winrt::Windows::UI::Text::FontStyle value) = 0;
    virtual HRESULT __stdcall get_FontStretch(winrt::Windows::UI::Text::FontStretch * value) = 0;
    virtual HRESULT __stdcall put_FontStretch(winrt::Windows::UI::Text::FontStretch value) = 0;
    virtual HRESULT __stdcall get_CharacterSpacing(int32_t * value) = 0;
    virtual HRESULT __stdcall put_CharacterSpacing(int32_t value) = 0;
    virtual HRESULT __stdcall get_Foreground(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall put_Foreground(Windows::UI::Xaml::Media::IBrush * value) = 0;
};

struct __declspec(uuid("5138e958-335d-4210-8bbb-0aa2b4b5c29e")) __declspec(novtable) IContentPresenter2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_OpticalMarginAlignment(winrt::Windows::UI::Xaml::OpticalMarginAlignment * value) = 0;
    virtual HRESULT __stdcall put_OpticalMarginAlignment(winrt::Windows::UI::Xaml::OpticalMarginAlignment value) = 0;
    virtual HRESULT __stdcall get_TextLineBounds(winrt::Windows::UI::Xaml::TextLineBounds * value) = 0;
    virtual HRESULT __stdcall put_TextLineBounds(winrt::Windows::UI::Xaml::TextLineBounds value) = 0;
};

struct __declspec(uuid("b038876a-9c4d-4402-ac56-a223487dc6c8")) __declspec(novtable) IContentPresenter3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsTextScaleFactorEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsTextScaleFactorEnabled(bool value) = 0;
};

struct __declspec(uuid("997b1b17-3bf8-432b-8fd9-68c7bab21f9d")) __declspec(novtable) IContentPresenter4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TextWrapping(winrt::Windows::UI::Xaml::TextWrapping * value) = 0;
    virtual HRESULT __stdcall put_TextWrapping(winrt::Windows::UI::Xaml::TextWrapping value) = 0;
    virtual HRESULT __stdcall get_MaxLines(int32_t * value) = 0;
    virtual HRESULT __stdcall put_MaxLines(int32_t value) = 0;
    virtual HRESULT __stdcall get_LineStackingStrategy(winrt::Windows::UI::Xaml::LineStackingStrategy * value) = 0;
    virtual HRESULT __stdcall put_LineStackingStrategy(winrt::Windows::UI::Xaml::LineStackingStrategy value) = 0;
    virtual HRESULT __stdcall get_LineHeight(double * value) = 0;
    virtual HRESULT __stdcall put_LineHeight(double value) = 0;
    virtual HRESULT __stdcall get_BorderBrush(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall put_BorderBrush(Windows::UI::Xaml::Media::IBrush * value) = 0;
    virtual HRESULT __stdcall get_BorderThickness(Windows::UI::Xaml::Thickness * value) = 0;
    virtual HRESULT __stdcall put_BorderThickness(Windows::UI::Xaml::Thickness value) = 0;
    virtual HRESULT __stdcall get_CornerRadius(Windows::UI::Xaml::CornerRadius * value) = 0;
    virtual HRESULT __stdcall put_CornerRadius(Windows::UI::Xaml::CornerRadius value) = 0;
    virtual HRESULT __stdcall get_Padding(Windows::UI::Xaml::Thickness * value) = 0;
    virtual HRESULT __stdcall put_Padding(Windows::UI::Xaml::Thickness value) = 0;
    virtual HRESULT __stdcall get_Background(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall put_Background(Windows::UI::Xaml::Media::IBrush * value) = 0;
    virtual HRESULT __stdcall get_HorizontalContentAlignment(winrt::Windows::UI::Xaml::HorizontalAlignment * value) = 0;
    virtual HRESULT __stdcall put_HorizontalContentAlignment(winrt::Windows::UI::Xaml::HorizontalAlignment value) = 0;
    virtual HRESULT __stdcall get_VerticalContentAlignment(winrt::Windows::UI::Xaml::VerticalAlignment * value) = 0;
    virtual HRESULT __stdcall put_VerticalContentAlignment(winrt::Windows::UI::Xaml::VerticalAlignment value) = 0;
};

struct __declspec(uuid("3339d4f7-4815-44c4-9f76-68c83880ef10")) __declspec(novtable) IContentPresenterFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IContentPresenter ** instance) = 0;
};

struct __declspec(uuid("a76339ed-32ff-438b-aad5-1d68fae93426")) __declspec(novtable) IContentPresenterOverrides : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_OnContentTemplateChanged(Windows::UI::Xaml::IDataTemplate * oldContentTemplate, Windows::UI::Xaml::IDataTemplate * newContentTemplate) = 0;
    virtual HRESULT __stdcall abi_OnContentTemplateSelectorChanged(Windows::UI::Xaml::Controls::IDataTemplateSelector * oldContentTemplateSelector, Windows::UI::Xaml::Controls::IDataTemplateSelector * newContentTemplateSelector) = 0;
};

struct __declspec(uuid("18c2893b-da2e-4426-b85a-2c7e2171bedf")) __declspec(novtable) IContentPresenterStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ContentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ContentTemplateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ContentTemplateSelectorProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ContentTransitionsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FontSizeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FontFamilyProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FontWeightProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FontStyleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FontStretchProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CharacterSpacingProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ForegroundProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("c7d89dd9-06e6-46be-a8a0-9c117d3024a3")) __declspec(novtable) IContentPresenterStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_OpticalMarginAlignmentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TextLineBoundsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("cbe6cf5b-38b1-4d5d-b098-bc94b35c8ddf")) __declspec(novtable) IContentPresenterStatics3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsTextScaleFactorEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("ff8be292-af28-47eb-a5c3-dc44ced40fd2")) __declspec(novtable) IContentPresenterStatics4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TextWrappingProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MaxLinesProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_LineStackingStrategyProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_LineHeightProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_BorderBrushProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_BorderThicknessProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CornerRadiusProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PaddingProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_BackgroundProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_HorizontalContentAlignmentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_VerticalContentAlignmentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("1f7df263-c14b-4528-b6f0-637999d83cc6")) __declspec(novtable) IContextMenuEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Handled(bool * value) = 0;
    virtual HRESULT __stdcall put_Handled(bool value) = 0;
    virtual HRESULT __stdcall get_CursorLeft(double * value) = 0;
    virtual HRESULT __stdcall get_CursorTop(double * value) = 0;
};

struct __declspec(uuid("a8912263-2951-4f58-a9c5-5a134eaa7f07")) __declspec(novtable) IControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FontSize(double * value) = 0;
    virtual HRESULT __stdcall put_FontSize(double value) = 0;
    virtual HRESULT __stdcall get_FontFamily(Windows::UI::Xaml::Media::IFontFamily ** value) = 0;
    virtual HRESULT __stdcall put_FontFamily(Windows::UI::Xaml::Media::IFontFamily * value) = 0;
    virtual HRESULT __stdcall get_FontWeight(Windows::UI::Text::FontWeight * value) = 0;
    virtual HRESULT __stdcall put_FontWeight(Windows::UI::Text::FontWeight value) = 0;
    virtual HRESULT __stdcall get_FontStyle(winrt::Windows::UI::Text::FontStyle * value) = 0;
    virtual HRESULT __stdcall put_FontStyle(winrt::Windows::UI::Text::FontStyle value) = 0;
    virtual HRESULT __stdcall get_FontStretch(winrt::Windows::UI::Text::FontStretch * value) = 0;
    virtual HRESULT __stdcall put_FontStretch(winrt::Windows::UI::Text::FontStretch value) = 0;
    virtual HRESULT __stdcall get_CharacterSpacing(int32_t * value) = 0;
    virtual HRESULT __stdcall put_CharacterSpacing(int32_t value) = 0;
    virtual HRESULT __stdcall get_Foreground(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall put_Foreground(Windows::UI::Xaml::Media::IBrush * value) = 0;
    virtual HRESULT __stdcall get_IsTabStop(bool * value) = 0;
    virtual HRESULT __stdcall put_IsTabStop(bool value) = 0;
    virtual HRESULT __stdcall get_IsEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_TabIndex(int32_t * value) = 0;
    virtual HRESULT __stdcall put_TabIndex(int32_t value) = 0;
    virtual HRESULT __stdcall get_TabNavigation(winrt::Windows::UI::Xaml::Input::KeyboardNavigationMode * value) = 0;
    virtual HRESULT __stdcall put_TabNavigation(winrt::Windows::UI::Xaml::Input::KeyboardNavigationMode value) = 0;
    virtual HRESULT __stdcall get_Template(Windows::UI::Xaml::Controls::IControlTemplate ** value) = 0;
    virtual HRESULT __stdcall put_Template(Windows::UI::Xaml::Controls::IControlTemplate * value) = 0;
    virtual HRESULT __stdcall get_Padding(Windows::UI::Xaml::Thickness * value) = 0;
    virtual HRESULT __stdcall put_Padding(Windows::UI::Xaml::Thickness value) = 0;
    virtual HRESULT __stdcall get_HorizontalContentAlignment(winrt::Windows::UI::Xaml::HorizontalAlignment * value) = 0;
    virtual HRESULT __stdcall put_HorizontalContentAlignment(winrt::Windows::UI::Xaml::HorizontalAlignment value) = 0;
    virtual HRESULT __stdcall get_VerticalContentAlignment(winrt::Windows::UI::Xaml::VerticalAlignment * value) = 0;
    virtual HRESULT __stdcall put_VerticalContentAlignment(winrt::Windows::UI::Xaml::VerticalAlignment value) = 0;
    virtual HRESULT __stdcall get_Background(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall put_Background(Windows::UI::Xaml::Media::IBrush * value) = 0;
    virtual HRESULT __stdcall get_BorderThickness(Windows::UI::Xaml::Thickness * value) = 0;
    virtual HRESULT __stdcall put_BorderThickness(Windows::UI::Xaml::Thickness value) = 0;
    virtual HRESULT __stdcall get_BorderBrush(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall put_BorderBrush(Windows::UI::Xaml::Media::IBrush * value) = 0;
    virtual HRESULT __stdcall get_FocusState(winrt::Windows::UI::Xaml::FocusState * value) = 0;
    virtual HRESULT __stdcall add_IsEnabledChanged(Windows::UI::Xaml::DependencyPropertyChangedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_IsEnabledChanged(event_token token) = 0;
    virtual HRESULT __stdcall abi_ApplyTemplate(bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_Focus(winrt::Windows::UI::Xaml::FocusState value, bool * returnValue) = 0;
};

struct __declspec(uuid("43e0fe10-14ec-427e-8c57-dee60df60aa8")) __declspec(novtable) IControl2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsTextScaleFactorEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsTextScaleFactorEnabled(bool value) = 0;
};

struct __declspec(uuid("077b29e4-dade-4f55-9b96-09e21b28eb1c")) __declspec(novtable) IControl3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_UseSystemFocusVisuals(bool * value) = 0;
    virtual HRESULT __stdcall put_UseSystemFocusVisuals(bool value) = 0;
};

struct __declspec(uuid("0e18aeee-5f2e-44ea-8513-d3875c0a7513")) __declspec(novtable) IControl4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsFocusEngagementEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsFocusEngagementEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsFocusEngaged(bool * value) = 0;
    virtual HRESULT __stdcall put_IsFocusEngaged(bool value) = 0;
    virtual HRESULT __stdcall get_RequiresPointer(winrt::Windows::UI::Xaml::Controls::RequiresPointer * value) = 0;
    virtual HRESULT __stdcall put_RequiresPointer(winrt::Windows::UI::Xaml::Controls::RequiresPointer value) = 0;
    virtual HRESULT __stdcall get_XYFocusLeft(Windows::UI::Xaml::IDependencyObject ** value) = 0;
    virtual HRESULT __stdcall put_XYFocusLeft(Windows::UI::Xaml::IDependencyObject * value) = 0;
    virtual HRESULT __stdcall get_XYFocusRight(Windows::UI::Xaml::IDependencyObject ** value) = 0;
    virtual HRESULT __stdcall put_XYFocusRight(Windows::UI::Xaml::IDependencyObject * value) = 0;
    virtual HRESULT __stdcall get_XYFocusUp(Windows::UI::Xaml::IDependencyObject ** value) = 0;
    virtual HRESULT __stdcall put_XYFocusUp(Windows::UI::Xaml::IDependencyObject * value) = 0;
    virtual HRESULT __stdcall get_XYFocusDown(Windows::UI::Xaml::IDependencyObject ** value) = 0;
    virtual HRESULT __stdcall put_XYFocusDown(Windows::UI::Xaml::IDependencyObject * value) = 0;
    virtual HRESULT __stdcall get_ElementSoundMode(winrt::Windows::UI::Xaml::ElementSoundMode * value) = 0;
    virtual HRESULT __stdcall put_ElementSoundMode(winrt::Windows::UI::Xaml::ElementSoundMode value) = 0;
    virtual HRESULT __stdcall add_FocusEngaged(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::FocusEngagedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_FocusEngaged(event_token token) = 0;
    virtual HRESULT __stdcall add_FocusDisengaged(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::FocusDisengagedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_FocusDisengaged(event_token token) = 0;
    virtual HRESULT __stdcall abi_RemoveFocusEngagement() = 0;
};

struct __declspec(uuid("b12b1d5a-6419-4e16-b212-a45336b75778")) __declspec(novtable) IControlFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IControl ** instance) = 0;
};

struct __declspec(uuid("a09691df-9824-41fe-b530-b0d8990e64c1")) __declspec(novtable) IControlOverrides : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_OnPointerEntered(Windows::UI::Xaml::Input::IPointerRoutedEventArgs * e) = 0;
    virtual HRESULT __stdcall abi_OnPointerPressed(Windows::UI::Xaml::Input::IPointerRoutedEventArgs * e) = 0;
    virtual HRESULT __stdcall abi_OnPointerMoved(Windows::UI::Xaml::Input::IPointerRoutedEventArgs * e) = 0;
    virtual HRESULT __stdcall abi_OnPointerReleased(Windows::UI::Xaml::Input::IPointerRoutedEventArgs * e) = 0;
    virtual HRESULT __stdcall abi_OnPointerExited(Windows::UI::Xaml::Input::IPointerRoutedEventArgs * e) = 0;
    virtual HRESULT __stdcall abi_OnPointerCaptureLost(Windows::UI::Xaml::Input::IPointerRoutedEventArgs * e) = 0;
    virtual HRESULT __stdcall abi_OnPointerCanceled(Windows::UI::Xaml::Input::IPointerRoutedEventArgs * e) = 0;
    virtual HRESULT __stdcall abi_OnPointerWheelChanged(Windows::UI::Xaml::Input::IPointerRoutedEventArgs * e) = 0;
    virtual HRESULT __stdcall abi_OnTapped(Windows::UI::Xaml::Input::ITappedRoutedEventArgs * e) = 0;
    virtual HRESULT __stdcall abi_OnDoubleTapped(Windows::UI::Xaml::Input::IDoubleTappedRoutedEventArgs * e) = 0;
    virtual HRESULT __stdcall abi_OnHolding(Windows::UI::Xaml::Input::IHoldingRoutedEventArgs * e) = 0;
    virtual HRESULT __stdcall abi_OnRightTapped(Windows::UI::Xaml::Input::IRightTappedRoutedEventArgs * e) = 0;
    virtual HRESULT __stdcall abi_OnManipulationStarting(Windows::UI::Xaml::Input::IManipulationStartingRoutedEventArgs * e) = 0;
    virtual HRESULT __stdcall abi_OnManipulationInertiaStarting(Windows::UI::Xaml::Input::IManipulationInertiaStartingRoutedEventArgs * e) = 0;
    virtual HRESULT __stdcall abi_OnManipulationStarted(Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgs * e) = 0;
    virtual HRESULT __stdcall abi_OnManipulationDelta(Windows::UI::Xaml::Input::IManipulationDeltaRoutedEventArgs * e) = 0;
    virtual HRESULT __stdcall abi_OnManipulationCompleted(Windows::UI::Xaml::Input::IManipulationCompletedRoutedEventArgs * e) = 0;
    virtual HRESULT __stdcall abi_OnKeyUp(Windows::UI::Xaml::Input::IKeyRoutedEventArgs * e) = 0;
    virtual HRESULT __stdcall abi_OnKeyDown(Windows::UI::Xaml::Input::IKeyRoutedEventArgs * e) = 0;
    virtual HRESULT __stdcall abi_OnGotFocus(Windows::UI::Xaml::IRoutedEventArgs * e) = 0;
    virtual HRESULT __stdcall abi_OnLostFocus(Windows::UI::Xaml::IRoutedEventArgs * e) = 0;
    virtual HRESULT __stdcall abi_OnDragEnter(Windows::UI::Xaml::IDragEventArgs * e) = 0;
    virtual HRESULT __stdcall abi_OnDragLeave(Windows::UI::Xaml::IDragEventArgs * e) = 0;
    virtual HRESULT __stdcall abi_OnDragOver(Windows::UI::Xaml::IDragEventArgs * e) = 0;
    virtual HRESULT __stdcall abi_OnDrop(Windows::UI::Xaml::IDragEventArgs * e) = 0;
};

struct __declspec(uuid("1791587a-2a7c-4981-a2d8-ab99fffc65b9")) __declspec(novtable) IControlProtected : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DefaultStyleKey(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_DefaultStyleKey(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall abi_GetTemplateChild(hstring childName, Windows::UI::Xaml::IDependencyObject ** returnValue) = 0;
};

struct __declspec(uuid("473b305b-877d-4c35-8fca-46a05f96607a")) __declspec(novtable) IControlStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FontSizeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FontFamilyProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FontWeightProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FontStyleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FontStretchProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CharacterSpacingProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ForegroundProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsTabStopProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TabIndexProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TabNavigationProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TemplateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PaddingProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_HorizontalContentAlignmentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_VerticalContentAlignmentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_BackgroundProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_BorderThicknessProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_BorderBrushProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_DefaultStyleKeyProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FocusStateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("32233e36-ab74-4a25-a556-45293135b2c5")) __declspec(novtable) IControlStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsTextScaleFactorEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("aad15e61-e4b9-4d72-b653-934149aa5003")) __declspec(novtable) IControlStatics3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_UseSystemFocusVisualsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsTemplateFocusTargetProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetIsTemplateFocusTarget(Windows::UI::Xaml::IFrameworkElement * element, bool * value) = 0;
    virtual HRESULT __stdcall abi_SetIsTemplateFocusTarget(Windows::UI::Xaml::IFrameworkElement * element, bool value) = 0;
};

struct __declspec(uuid("59fda728-c05a-4ec2-8a4b-06ad69b66e15")) __declspec(novtable) IControlStatics4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsFocusEngagementEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsFocusEngagedProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_RequiresPointerProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_XYFocusLeftProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_XYFocusRightProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_XYFocusUpProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_XYFocusDownProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ElementSoundModeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("efd2418e-41e0-48bb-8b82-91eda1ba3fe2")) __declspec(novtable) IControlTemplate : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TargetType(Windows::UI::Xaml::Interop::TypeName * value) = 0;
    virtual HRESULT __stdcall put_TargetType(Windows::UI::Xaml::Interop::TypeName value) = 0;
};

struct __declspec(uuid("a907d496-46a0-4cd7-8dbe-f9a581df60b1")) __declspec(novtable) IDataTemplateSelector : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SelectTemplate(Windows::Foundation::IInspectable * item, Windows::UI::Xaml::IDependencyObject * container, Windows::UI::Xaml::IDataTemplate ** returnValue) = 0;
};

struct __declspec(uuid("3792bc47-8c4b-4257-a5ae-cc3f8ed786eb")) __declspec(novtable) IDataTemplateSelector2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SelectTemplateForItem(Windows::Foundation::IInspectable * item, Windows::UI::Xaml::IDataTemplate ** returnValue) = 0;
};

struct __declspec(uuid("511baad0-210a-457d-9521-433d2b11b7d2")) __declspec(novtable) IDataTemplateSelectorFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IDataTemplateSelector ** instance) = 0;
};

struct __declspec(uuid("2d162925-5966-4bfa-8638-4d345689f6cf")) __declspec(novtable) IDataTemplateSelectorOverrides : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SelectTemplateCore(Windows::Foundation::IInspectable * item, Windows::UI::Xaml::IDependencyObject * container, Windows::UI::Xaml::IDataTemplate ** returnValue) = 0;
};

struct __declspec(uuid("6c3fb5fc-8e84-4c91-ac15-04a1d885500f")) __declspec(novtable) IDataTemplateSelectorOverrides2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SelectTemplateForItemCore(Windows::Foundation::IInspectable * item, Windows::UI::Xaml::IDataTemplate ** returnValue) = 0;
};

struct __declspec(uuid("a1527b12-59c1-4521-b28c-b176675e7c5a")) __declspec(novtable) IDatePickedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_OldDate(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_NewDate(Windows::Foundation::DateTime * value) = 0;
};

struct __declspec(uuid("06da3946-08b8-4103-8b8a-093efd6a7657")) __declspec(novtable) IDatePicker : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Header(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_Header(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_HeaderTemplate(Windows::UI::Xaml::IDataTemplate ** value) = 0;
    virtual HRESULT __stdcall put_HeaderTemplate(Windows::UI::Xaml::IDataTemplate * value) = 0;
    virtual HRESULT __stdcall get_CalendarIdentifier(hstring * value) = 0;
    virtual HRESULT __stdcall put_CalendarIdentifier(hstring value) = 0;
    virtual HRESULT __stdcall get_Date(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall put_Date(Windows::Foundation::DateTime value) = 0;
    virtual HRESULT __stdcall get_DayVisible(bool * value) = 0;
    virtual HRESULT __stdcall put_DayVisible(bool value) = 0;
    virtual HRESULT __stdcall get_MonthVisible(bool * value) = 0;
    virtual HRESULT __stdcall put_MonthVisible(bool value) = 0;
    virtual HRESULT __stdcall get_YearVisible(bool * value) = 0;
    virtual HRESULT __stdcall put_YearVisible(bool value) = 0;
    virtual HRESULT __stdcall get_DayFormat(hstring * value) = 0;
    virtual HRESULT __stdcall put_DayFormat(hstring value) = 0;
    virtual HRESULT __stdcall get_MonthFormat(hstring * value) = 0;
    virtual HRESULT __stdcall put_MonthFormat(hstring value) = 0;
    virtual HRESULT __stdcall get_YearFormat(hstring * value) = 0;
    virtual HRESULT __stdcall put_YearFormat(hstring value) = 0;
    virtual HRESULT __stdcall get_MinYear(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall put_MinYear(Windows::Foundation::DateTime value) = 0;
    virtual HRESULT __stdcall get_MaxYear(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall put_MaxYear(Windows::Foundation::DateTime value) = 0;
    virtual HRESULT __stdcall get_Orientation(winrt::Windows::UI::Xaml::Controls::Orientation * value) = 0;
    virtual HRESULT __stdcall put_Orientation(winrt::Windows::UI::Xaml::Controls::Orientation value) = 0;
    virtual HRESULT __stdcall add_DateChanged(Windows::Foundation::EventHandler<Windows::UI::Xaml::Controls::DatePickerValueChangedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DateChanged(event_token token) = 0;
};

struct __declspec(uuid("bb28b475-2c1f-4340-9e30-948f99c9e57a")) __declspec(novtable) IDatePicker2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LightDismissOverlayMode(winrt::Windows::UI::Xaml::Controls::LightDismissOverlayMode * value) = 0;
    virtual HRESULT __stdcall put_LightDismissOverlayMode(winrt::Windows::UI::Xaml::Controls::LightDismissOverlayMode value) = 0;
};

struct __declspec(uuid("eec3ca84-9896-4a7d-bb35-6fb21eaeca11")) __declspec(novtable) IDatePickerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IDatePicker ** instance) = 0;
};

struct __declspec(uuid("fbf33b1a-a3a4-4df8-9228-23a5ac27df4e")) __declspec(novtable) IDatePickerFlyout : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CalendarIdentifier(hstring * value) = 0;
    virtual HRESULT __stdcall put_CalendarIdentifier(hstring value) = 0;
    virtual HRESULT __stdcall get_Date(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall put_Date(Windows::Foundation::DateTime value) = 0;
    virtual HRESULT __stdcall get_DayVisible(bool * value) = 0;
    virtual HRESULT __stdcall put_DayVisible(bool value) = 0;
    virtual HRESULT __stdcall get_MonthVisible(bool * value) = 0;
    virtual HRESULT __stdcall put_MonthVisible(bool value) = 0;
    virtual HRESULT __stdcall get_YearVisible(bool * value) = 0;
    virtual HRESULT __stdcall put_YearVisible(bool value) = 0;
    virtual HRESULT __stdcall get_MinYear(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall put_MinYear(Windows::Foundation::DateTime value) = 0;
    virtual HRESULT __stdcall get_MaxYear(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall put_MaxYear(Windows::Foundation::DateTime value) = 0;
    virtual HRESULT __stdcall add_DatePicked(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::DatePickerFlyout, Windows::UI::Xaml::Controls::DatePickedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DatePicked(event_token token) = 0;
    virtual HRESULT __stdcall abi_ShowAtAsync(Windows::UI::Xaml::IFrameworkElement * target, Windows::Foundation::IAsyncOperation<Windows::Foundation::IReference<Windows::Foundation::DateTime>> ** returnValue) = 0;
};

struct __declspec(uuid("cfb18dbb-9931-4119-8bda-54a86fdfac84")) __declspec(novtable) IDatePickerFlyout2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DayFormat(hstring * value) = 0;
    virtual HRESULT __stdcall put_DayFormat(hstring value) = 0;
    virtual HRESULT __stdcall get_MonthFormat(hstring * value) = 0;
    virtual HRESULT __stdcall put_MonthFormat(hstring value) = 0;
    virtual HRESULT __stdcall get_YearFormat(hstring * value) = 0;
    virtual HRESULT __stdcall put_YearFormat(hstring value) = 0;
};

struct __declspec(uuid("9d9bc289-00d2-4aac-9c85-d74f06367887")) __declspec(novtable) IDatePickerFlyoutItem : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PrimaryText(hstring * value) = 0;
    virtual HRESULT __stdcall put_PrimaryText(hstring value) = 0;
    virtual HRESULT __stdcall get_SecondaryText(hstring * value) = 0;
    virtual HRESULT __stdcall put_SecondaryText(hstring value) = 0;
};

struct __declspec(uuid("aa9c91da-07f6-4cdf-89b4-dda3bdb0ea6b")) __declspec(novtable) IDatePickerFlyoutItemStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PrimaryTextProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SecondaryTextProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("7c62f70e-2ddc-4381-832f-54cbdfaa849a")) __declspec(novtable) IDatePickerFlyoutPresenter : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("cd570377-5845-4c12-8c10-592d9fcc7cd9")) __declspec(novtable) IDatePickerFlyoutStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CalendarIdentifierProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_DateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_DayVisibleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MonthVisibleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_YearVisibleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MinYearProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MaxYearProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("afd3e569-81e6-4b54-84a9-68079b73e34e")) __declspec(novtable) IDatePickerFlyoutStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DayFormatProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MonthFormatProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_YearFormatProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("182e7c69-2116-4c67-b513-713364831d79")) __declspec(novtable) IDatePickerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_HeaderProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_HeaderTemplateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CalendarIdentifierProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_DateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_DayVisibleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MonthVisibleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_YearVisibleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_DayFormatProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MonthFormatProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_YearFormatProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MinYearProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MaxYearProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_OrientationProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("f1076df6-fba6-4550-8b88-a6420847f60d")) __declspec(novtable) IDatePickerStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LightDismissOverlayModeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("1ae661b2-b1b4-4273-96e0-19daff187446")) __declspec(novtable) IDatePickerValueChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_OldDate(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_NewDate(Windows::Foundation::DateTime * value) = 0;
};

struct __declspec(uuid("af05f22f-9e78-4b21-9a8e-41c2d1367a2a")) __declspec(novtable) IDragItemsCompletedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Items(Windows::Foundation::Collections::IVectorView<Windows::Foundation::IInspectable> ** value) = 0;
    virtual HRESULT __stdcall get_DropResult(winrt::Windows::ApplicationModel::DataTransfer::DataPackageOperation * value) = 0;
};

struct __declspec(uuid("71cf215c-daed-4783-aa11-dc574d2713e9")) __declspec(novtable) IDragItemsStartingEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Cancel(bool * value) = 0;
    virtual HRESULT __stdcall put_Cancel(bool value) = 0;
    virtual HRESULT __stdcall get_Items(Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> ** value) = 0;
    virtual HRESULT __stdcall get_Data(Windows::ApplicationModel::DataTransfer::IDataPackage ** value) = 0;
};

struct __declspec(uuid("c93c736f-6f6e-4e43-90d9-9b46a0d88b9f")) __declspec(novtable) IDynamicOverflowItemsChangingEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Action(winrt::Windows::UI::Xaml::Controls::CommandBarDynamicOverflowAction * value) = 0;
};

struct __declspec(uuid("a1582f68-3d7d-4d3b-b71d-488eed1e3493")) __declspec(novtable) IFlipView : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("c4fea4fd-7af3-4952-9fd9-9e0987fc4f29")) __declspec(novtable) IFlipView2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_UseTouchAnimationsForAllNavigation(bool * value) = 0;
    virtual HRESULT __stdcall put_UseTouchAnimationsForAllNavigation(bool value) = 0;
};

struct __declspec(uuid("f1dea9be-9ae8-4d4b-ab43-16d31e05f4f3")) __declspec(novtable) IFlipViewFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IFlipView ** instance) = 0;
};

struct __declspec(uuid("56196565-ce2b-4bda-a36b-82a2b8b0d4c0")) __declspec(novtable) IFlipViewItem : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("f21d91fe-22a0-4412-a853-9d6a6e8f2aaf")) __declspec(novtable) IFlipViewItemFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IFlipViewItem ** instance) = 0;
};

struct __declspec(uuid("70e3d93f-4308-4ba2-bbce-e2cb0ed34476")) __declspec(novtable) IFlipViewStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_UseTouchAnimationsForAllNavigationProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("6584ebdf-cbc7-4e19-843a-a14f24a793ea")) __declspec(novtable) IFlyout : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Content(Windows::UI::Xaml::IUIElement ** value) = 0;
    virtual HRESULT __stdcall put_Content(Windows::UI::Xaml::IUIElement * value) = 0;
    virtual HRESULT __stdcall get_FlyoutPresenterStyle(Windows::UI::Xaml::IStyle ** value) = 0;
    virtual HRESULT __stdcall put_FlyoutPresenterStyle(Windows::UI::Xaml::IStyle * value) = 0;
};

struct __declspec(uuid("4bed4933-008e-4b03-a385-79fe5266ddba")) __declspec(novtable) IFlyoutFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IFlyout ** instance) = 0;
};

struct __declspec(uuid("827d5b79-e37b-46a5-8d44-63a11a580e83")) __declspec(novtable) IFlyoutPresenter : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("ee4d668f-da76-469a-acd7-3060e613ade7")) __declspec(novtable) IFlyoutPresenterFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IFlyoutPresenter ** instance) = 0;
};

struct __declspec(uuid("61364e0b-db75-47e1-b2c3-5b901c3d74b6")) __declspec(novtable) IFlyoutStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ContentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FlyoutPresenterStyleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("5e14280f-953e-4cf8-b9ea-c530a1ce02ad")) __declspec(novtable) IFocusDisengagedEventArgs : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("a69fc352-da66-404c-823f-5358594e70bb")) __declspec(novtable) IFocusEngagedEventArgs : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("d4d61391-39ac-4950-9166-3606c264418b")) __declspec(novtable) IFontIcon : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Glyph(hstring * value) = 0;
    virtual HRESULT __stdcall put_Glyph(hstring value) = 0;
    virtual HRESULT __stdcall get_FontSize(double * value) = 0;
    virtual HRESULT __stdcall put_FontSize(double value) = 0;
    virtual HRESULT __stdcall get_FontFamily(Windows::UI::Xaml::Media::IFontFamily ** value) = 0;
    virtual HRESULT __stdcall put_FontFamily(Windows::UI::Xaml::Media::IFontFamily * value) = 0;
    virtual HRESULT __stdcall get_FontWeight(Windows::UI::Text::FontWeight * value) = 0;
    virtual HRESULT __stdcall put_FontWeight(Windows::UI::Text::FontWeight value) = 0;
    virtual HRESULT __stdcall get_FontStyle(winrt::Windows::UI::Text::FontStyle * value) = 0;
    virtual HRESULT __stdcall put_FontStyle(winrt::Windows::UI::Text::FontStyle value) = 0;
};

struct __declspec(uuid("f6ebd84d-37e8-46ee-a574-41ad550482e0")) __declspec(novtable) IFontIcon2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsTextScaleFactorEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsTextScaleFactorEnabled(bool value) = 0;
};

struct __declspec(uuid("6155d919-1c6c-4950-8794-231ef0914d94")) __declspec(novtable) IFontIcon3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MirroredWhenRightToLeft(bool * value) = 0;
    virtual HRESULT __stdcall put_MirroredWhenRightToLeft(bool value) = 0;
};

struct __declspec(uuid("1c781b6b-37bf-4ddc-a1a8-1b77db3cf0ea")) __declspec(novtable) IFontIconFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IFontIcon ** instance) = 0;
};

struct __declspec(uuid("b3be7bf6-1467-4086-bbcb-4e21d97a7b4d")) __declspec(novtable) IFontIconStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_GlyphProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FontSizeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FontFamilyProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FontWeightProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FontStyleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("e6080672-08f8-43d3-8790-4604290cbebd")) __declspec(novtable) IFontIconStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsTextScaleFactorEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("a4528b17-b084-4bd5-aab4-feae9d3b5d26")) __declspec(novtable) IFontIconStatics3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MirroredWhenRightToLeftProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("68ea500b-3fe9-4735-b6a0-e7601933b089")) __declspec(novtable) IFrame : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CacheSize(int32_t * value) = 0;
    virtual HRESULT __stdcall put_CacheSize(int32_t value) = 0;
    virtual HRESULT __stdcall get_CanGoBack(bool * value) = 0;
    virtual HRESULT __stdcall get_CanGoForward(bool * value) = 0;
    virtual HRESULT __stdcall get_CurrentSourcePageType(Windows::UI::Xaml::Interop::TypeName * value) = 0;
    virtual HRESULT __stdcall get_SourcePageType(Windows::UI::Xaml::Interop::TypeName * value) = 0;
    virtual HRESULT __stdcall put_SourcePageType(Windows::UI::Xaml::Interop::TypeName value) = 0;
    virtual HRESULT __stdcall get_BackStackDepth(int32_t * value) = 0;
    virtual HRESULT __stdcall add_Navigated(Windows::UI::Xaml::Navigation::NavigatedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Navigated(event_token token) = 0;
    virtual HRESULT __stdcall add_Navigating(Windows::UI::Xaml::Navigation::NavigatingCancelEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Navigating(event_token token) = 0;
    virtual HRESULT __stdcall add_NavigationFailed(Windows::UI::Xaml::Navigation::NavigationFailedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_NavigationFailed(event_token token) = 0;
    virtual HRESULT __stdcall add_NavigationStopped(Windows::UI::Xaml::Navigation::NavigationStoppedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_NavigationStopped(event_token token) = 0;
    virtual HRESULT __stdcall abi_GoBack() = 0;
    virtual HRESULT __stdcall abi_GoForward() = 0;
    virtual HRESULT __stdcall abi_Navigate(Windows::UI::Xaml::Interop::TypeName sourcePageType, Windows::Foundation::IInspectable * parameter, bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetNavigationState(hstring * returnValue) = 0;
    virtual HRESULT __stdcall abi_SetNavigationState(hstring navigationState) = 0;
};

struct __declspec(uuid("3f367f87-9f5a-4b04-b818-b554c069597a")) __declspec(novtable) IFrame2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_BackStack(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Navigation::PageStackEntry> ** value) = 0;
    virtual HRESULT __stdcall get_ForwardStack(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Navigation::PageStackEntry> ** value) = 0;
    virtual HRESULT __stdcall abi_Navigate(Windows::UI::Xaml::Interop::TypeName sourcePageType, Windows::Foundation::IInspectable * parameter, Windows::UI::Xaml::Media::Animation::INavigationTransitionInfo * infoOverride, bool * returnValue) = 0;
};

struct __declspec(uuid("648a2b4d-53ca-4b5a-aa8e-3cc7440f4a67")) __declspec(novtable) IFrame3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GoBack(Windows::UI::Xaml::Media::Animation::INavigationTransitionInfo * transitionInfoOverride) = 0;
};

struct __declspec(uuid("02ee93d4-448e-469e-9799-0a8a1f70f171")) __declspec(novtable) IFrameFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IFrame ** instance) = 0;
};

struct __declspec(uuid("d5acf0e9-d967-471b-8459-c8af4341511b")) __declspec(novtable) IFrameStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CacheSizeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CanGoBackProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CanGoForwardProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CurrentSourcePageTypeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SourcePageTypeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_BackStackDepthProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("e4b5cdfe-42f0-4462-a1c1-5d259dd82a03")) __declspec(novtable) IFrameStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_BackStackProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ForwardStackProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("fd104460-2e15-4ba3-8b8f-fa693a4161e9")) __declspec(novtable) IGrid : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RowDefinitions(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::RowDefinition> ** value) = 0;
    virtual HRESULT __stdcall get_ColumnDefinitions(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::ColumnDefinition> ** value) = 0;
};

struct __declspec(uuid("f76efa41-380e-45db-be87-9e1326ba4b57")) __declspec(novtable) IGrid2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_BorderBrush(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall put_BorderBrush(Windows::UI::Xaml::Media::IBrush * value) = 0;
    virtual HRESULT __stdcall get_BorderThickness(Windows::UI::Xaml::Thickness * value) = 0;
    virtual HRESULT __stdcall put_BorderThickness(Windows::UI::Xaml::Thickness value) = 0;
    virtual HRESULT __stdcall get_CornerRadius(Windows::UI::Xaml::CornerRadius * value) = 0;
    virtual HRESULT __stdcall put_CornerRadius(Windows::UI::Xaml::CornerRadius value) = 0;
    virtual HRESULT __stdcall get_Padding(Windows::UI::Xaml::Thickness * value) = 0;
    virtual HRESULT __stdcall put_Padding(Windows::UI::Xaml::Thickness value) = 0;
};

struct __declspec(uuid("ae814041-c531-43b4-bf99-12f506f7b01c")) __declspec(novtable) IGridFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IGrid ** instance) = 0;
};

struct __declspec(uuid("64fe2e9f-f951-42b6-a9ce-bb179af11595")) __declspec(novtable) IGridStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RowProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetRow(Windows::UI::Xaml::IFrameworkElement * element, int32_t * value) = 0;
    virtual HRESULT __stdcall abi_SetRow(Windows::UI::Xaml::IFrameworkElement * element, int32_t value) = 0;
    virtual HRESULT __stdcall get_ColumnProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetColumn(Windows::UI::Xaml::IFrameworkElement * element, int32_t * value) = 0;
    virtual HRESULT __stdcall abi_SetColumn(Windows::UI::Xaml::IFrameworkElement * element, int32_t value) = 0;
    virtual HRESULT __stdcall get_RowSpanProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetRowSpan(Windows::UI::Xaml::IFrameworkElement * element, int32_t * value) = 0;
    virtual HRESULT __stdcall abi_SetRowSpan(Windows::UI::Xaml::IFrameworkElement * element, int32_t value) = 0;
    virtual HRESULT __stdcall get_ColumnSpanProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetColumnSpan(Windows::UI::Xaml::IFrameworkElement * element, int32_t * value) = 0;
    virtual HRESULT __stdcall abi_SetColumnSpan(Windows::UI::Xaml::IFrameworkElement * element, int32_t value) = 0;
};

struct __declspec(uuid("2d666658-58b6-4a1b-841b-875ba93b5d6a")) __declspec(novtable) IGridStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_BorderBrushProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_BorderThicknessProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CornerRadiusProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PaddingProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("026ae934-b67e-4d80-8f72-8aa64b4d827b")) __declspec(novtable) IGridView : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("d9bcca89-09f9-4c6e-a83e-f199146f0e7d")) __declspec(novtable) IGridViewFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IGridView ** instance) = 0;
};

struct __declspec(uuid("72d75d7e-5dc3-4ffc-9b1c-939b5c37161c")) __declspec(novtable) IGridViewHeaderItem : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("36e0c96e-b56a-4b3b-8bac-7aef5e6f9945")) __declspec(novtable) IGridViewHeaderItemFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IGridViewHeaderItem ** instance) = 0;
};

struct __declspec(uuid("7d9901f1-e7c1-4e83-b470-c9d6d7bda9f5")) __declspec(novtable) IGridViewItem : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TemplateSettings(Windows::UI::Xaml::Controls::Primitives::IGridViewItemTemplateSettings ** value) = 0;
};

struct __declspec(uuid("229b00af-3fa6-43e9-979d-07ea0d6280dc")) __declspec(novtable) IGridViewItemFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IGridViewItem ** instance) = 0;
};

struct __declspec(uuid("4ae8d5d1-7228-4a16-a61f-88c0e8f45c76")) __declspec(novtable) IGroupItem : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("d9a1d53e-b1e0-4319-9808-7a9e887e13b0")) __declspec(novtable) IGroupItemFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IGroupItem ** instance) = 0;
};

struct __declspec(uuid("71ca300b-b89e-4184-b0df-a9e95447de8d")) __declspec(novtable) IGroupStyle : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Panel(Windows::UI::Xaml::Controls::IItemsPanelTemplate ** value) = 0;
    virtual HRESULT __stdcall put_Panel(Windows::UI::Xaml::Controls::IItemsPanelTemplate * value) = 0;
    virtual HRESULT __stdcall get_ContainerStyle(Windows::UI::Xaml::IStyle ** value) = 0;
    virtual HRESULT __stdcall put_ContainerStyle(Windows::UI::Xaml::IStyle * value) = 0;
    virtual HRESULT __stdcall get_ContainerStyleSelector(Windows::UI::Xaml::Controls::IStyleSelector ** value) = 0;
    virtual HRESULT __stdcall put_ContainerStyleSelector(Windows::UI::Xaml::Controls::IStyleSelector * value) = 0;
    virtual HRESULT __stdcall get_HeaderTemplate(Windows::UI::Xaml::IDataTemplate ** value) = 0;
    virtual HRESULT __stdcall put_HeaderTemplate(Windows::UI::Xaml::IDataTemplate * value) = 0;
    virtual HRESULT __stdcall get_HeaderTemplateSelector(Windows::UI::Xaml::Controls::IDataTemplateSelector ** value) = 0;
    virtual HRESULT __stdcall put_HeaderTemplateSelector(Windows::UI::Xaml::Controls::IDataTemplateSelector * value) = 0;
    virtual HRESULT __stdcall get_HidesIfEmpty(bool * value) = 0;
    virtual HRESULT __stdcall put_HidesIfEmpty(bool value) = 0;
};

struct __declspec(uuid("69f90679-3a11-4fe7-b4df-2a0139d4018b")) __declspec(novtable) IGroupStyle2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_HeaderContainerStyle(Windows::UI::Xaml::IStyle ** value) = 0;
    virtual HRESULT __stdcall put_HeaderContainerStyle(Windows::UI::Xaml::IStyle * value) = 0;
};

struct __declspec(uuid("56ff664f-e2d7-4f49-803d-c727cdf9372d")) __declspec(novtable) IGroupStyleFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IGroupStyle ** instance) = 0;
};

struct __declspec(uuid("6dda119e-9a74-478f-a339-5bb52de6c51e")) __declspec(novtable) IGroupStyleSelector : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SelectGroupStyle(Windows::Foundation::IInspectable * group, uint32_t level, Windows::UI::Xaml::Controls::IGroupStyle ** returnValue) = 0;
};

struct __declspec(uuid("bf570d33-b2f6-481f-a450-c80c291fb22d")) __declspec(novtable) IGroupStyleSelectorFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IGroupStyleSelector ** instance) = 0;
};

struct __declspec(uuid("f691cab2-77ad-4d3d-a51c-8ef9c3836456")) __declspec(novtable) IGroupStyleSelectorOverrides : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SelectGroupStyleCore(Windows::Foundation::IInspectable * group, uint32_t level, Windows::UI::Xaml::Controls::IGroupStyle ** returnValue) = 0;
};

struct __declspec(uuid("ae692e82-7314-4f51-ab11-2af1ed4a19f8")) __declspec(novtable) IHub : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Header(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_Header(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_HeaderTemplate(Windows::UI::Xaml::IDataTemplate ** value) = 0;
    virtual HRESULT __stdcall put_HeaderTemplate(Windows::UI::Xaml::IDataTemplate * value) = 0;
    virtual HRESULT __stdcall get_Orientation(winrt::Windows::UI::Xaml::Controls::Orientation * value) = 0;
    virtual HRESULT __stdcall put_Orientation(winrt::Windows::UI::Xaml::Controls::Orientation value) = 0;
    virtual HRESULT __stdcall get_DefaultSectionIndex(int32_t * value) = 0;
    virtual HRESULT __stdcall put_DefaultSectionIndex(int32_t value) = 0;
    virtual HRESULT __stdcall get_Sections(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::HubSection> ** value) = 0;
    virtual HRESULT __stdcall get_SectionsInView(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::HubSection> ** value) = 0;
    virtual HRESULT __stdcall get_SectionHeaders(Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> ** value) = 0;
    virtual HRESULT __stdcall add_SectionHeaderClick(Windows::UI::Xaml::Controls::HubSectionHeaderClickEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SectionHeaderClick(event_token token) = 0;
    virtual HRESULT __stdcall add_SectionsInViewChanged(Windows::UI::Xaml::Controls::SectionsInViewChangedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SectionsInViewChanged(event_token token) = 0;
    virtual HRESULT __stdcall abi_ScrollToSection(Windows::UI::Xaml::Controls::IHubSection * section) = 0;
};

struct __declspec(uuid("dca6b2ba-c6f5-4961-9953-c51873db5424")) __declspec(novtable) IHubFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IHub ** instance) = 0;
};

struct __declspec(uuid("a4e66cb7-7fdd-4fe0-ab49-c246639dccf9")) __declspec(novtable) IHubSection : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Header(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_Header(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_HeaderTemplate(Windows::UI::Xaml::IDataTemplate ** value) = 0;
    virtual HRESULT __stdcall put_HeaderTemplate(Windows::UI::Xaml::IDataTemplate * value) = 0;
    virtual HRESULT __stdcall get_ContentTemplate(Windows::UI::Xaml::IDataTemplate ** value) = 0;
    virtual HRESULT __stdcall put_ContentTemplate(Windows::UI::Xaml::IDataTemplate * value) = 0;
    virtual HRESULT __stdcall get_IsHeaderInteractive(bool * value) = 0;
    virtual HRESULT __stdcall put_IsHeaderInteractive(bool value) = 0;
};

struct __declspec(uuid("fff55fa2-ece4-4bba-aa3b-9804aef47883")) __declspec(novtable) IHubSectionFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IHubSection ** instance) = 0;
};

struct __declspec(uuid("e1c5ef04-1edd-4112-aeeb-996c96400698")) __declspec(novtable) IHubSectionHeaderClickEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Section(Windows::UI::Xaml::Controls::IHubSection ** value) = 0;
};

struct __declspec(uuid("12d2d85a-ea27-42d1-998b-61e52aed842b")) __declspec(novtable) IHubSectionStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_HeaderProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_HeaderTemplateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ContentTemplateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsHeaderInteractiveProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("0e6fa034-ad3c-4f32-b701-e24fab562028")) __declspec(novtable) IHubStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_HeaderProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_HeaderTemplateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_OrientationProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_DefaultSectionIndexProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SemanticZoomOwnerProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsActiveViewProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsZoomedInViewProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("ccebaca3-3b5c-4f4c-9bfd-86887bc79772")) __declspec(novtable) IHyperlinkButton : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_NavigateUri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall put_NavigateUri(Windows::Foundation::IUriRuntimeClass * value) = 0;
};

struct __declspec(uuid("43521bad-4e97-4da9-a64d-935dfd8cedf2")) __declspec(novtable) IHyperlinkButtonFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IHyperlinkButton ** instance) = 0;
};

struct __declspec(uuid("fbaeb5c7-cdb7-4263-b7d6-3c0d2904ed98")) __declspec(novtable) IHyperlinkButtonStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_NavigateUriProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("9af0803b-d04c-467a-bbd5-9b81f02d9a56")) __declspec(novtable) IIconElement : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Foreground(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall put_Foreground(Windows::UI::Xaml::Media::IBrush * value) = 0;
};

struct __declspec(uuid("cf37a562-0424-43c7-8bea-720fba973ef1")) __declspec(novtable) IIconElementFactory : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("be19a623-77cf-472f-82ea-047801d12012")) __declspec(novtable) IIconElementStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ForegroundProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("495b7402-9af3-4e50-aa90-03388f3086d2")) __declspec(novtable) IImage : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Source(Windows::UI::Xaml::Media::IImageSource ** value) = 0;
    virtual HRESULT __stdcall put_Source(Windows::UI::Xaml::Media::IImageSource * value) = 0;
    virtual HRESULT __stdcall get_Stretch(winrt::Windows::UI::Xaml::Media::Stretch * value) = 0;
    virtual HRESULT __stdcall put_Stretch(winrt::Windows::UI::Xaml::Media::Stretch value) = 0;
    virtual HRESULT __stdcall get_NineGrid(Windows::UI::Xaml::Thickness * value) = 0;
    virtual HRESULT __stdcall put_NineGrid(Windows::UI::Xaml::Thickness value) = 0;
    virtual HRESULT __stdcall get_PlayToSource(Windows::Media::PlayTo::IPlayToSource ** value) = 0;
    virtual HRESULT __stdcall add_ImageFailed(Windows::UI::Xaml::ExceptionRoutedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ImageFailed(event_token token) = 0;
    virtual HRESULT __stdcall add_ImageOpened(Windows::UI::Xaml::RoutedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ImageOpened(event_token token) = 0;
};

struct __declspec(uuid("f445119e-881f-48bb-873a-64417ca4f002")) __declspec(novtable) IImage2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetAsCastingSource(Windows::Media::Casting::ICastingSource ** returnValue) = 0;
};

struct __declspec(uuid("06ebe792-47c2-4d92-a488-8cd685d06aca")) __declspec(novtable) IImage3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetAlphaMask(Windows::UI::Composition::ICompositionBrush ** returnValue) = 0;
};

struct __declspec(uuid("89903772-c336-43d1-9d51-c3bbd5d5d691")) __declspec(novtable) IImageStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SourceProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_StretchProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_NineGridProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PlayToSourceProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("29443c28-8e48-4fc8-a473-35b0ba12acea")) __declspec(novtable) IInkCanvas : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_InkPresenter(Windows::UI::Input::Inking::IInkPresenter ** value) = 0;
};

struct __declspec(uuid("924ac2de-ab04-48f0-9653-e0f2da4dbf1a")) __declspec(novtable) IInkCanvasFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IInkCanvas ** instance) = 0;
};

struct __declspec(uuid("3ddd0cca-51f0-486f-a03e-4ee13dc12bcb")) __declspec(novtable) IInkToolbar : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_InitialControls(winrt::Windows::UI::Xaml::Controls::InkToolbarInitialControls * value) = 0;
    virtual HRESULT __stdcall put_InitialControls(winrt::Windows::UI::Xaml::Controls::InkToolbarInitialControls value) = 0;
    virtual HRESULT __stdcall get_Children(Windows::Foundation::Collections::IObservableVector<Windows::UI::Xaml::DependencyObject> ** value) = 0;
    virtual HRESULT __stdcall get_ActiveTool(Windows::UI::Xaml::Controls::IInkToolbarToolButton ** value) = 0;
    virtual HRESULT __stdcall put_ActiveTool(Windows::UI::Xaml::Controls::IInkToolbarToolButton * value) = 0;
    virtual HRESULT __stdcall get_InkDrawingAttributes(Windows::UI::Input::Inking::IInkDrawingAttributes ** value) = 0;
    virtual HRESULT __stdcall get_IsRulerButtonChecked(bool * value) = 0;
    virtual HRESULT __stdcall put_IsRulerButtonChecked(bool value) = 0;
    virtual HRESULT __stdcall get_TargetInkCanvas(Windows::UI::Xaml::Controls::IInkCanvas ** value) = 0;
    virtual HRESULT __stdcall put_TargetInkCanvas(Windows::UI::Xaml::Controls::IInkCanvas * value) = 0;
    virtual HRESULT __stdcall add_ActiveToolChanged(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::InkToolbar, Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ActiveToolChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_InkDrawingAttributesChanged(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::InkToolbar, Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_InkDrawingAttributesChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_EraseAllClicked(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::InkToolbar, Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_EraseAllClicked(event_token token) = 0;
    virtual HRESULT __stdcall add_IsRulerButtonCheckedChanged(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::InkToolbar, Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_IsRulerButtonCheckedChanged(event_token token) = 0;
    virtual HRESULT __stdcall abi_GetToolButton(winrt::Windows::UI::Xaml::Controls::InkToolbarTool tool, Windows::UI::Xaml::Controls::IInkToolbarToolButton ** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetToggleButton(winrt::Windows::UI::Xaml::Controls::InkToolbarToggle tool, Windows::UI::Xaml::Controls::IInkToolbarToggleButton ** returnValue) = 0;
};

struct __declspec(uuid("158329f8-1e99-3acc-910f-9da2d872ae12")) __declspec(novtable) IInkToolbarBallpointPenButton : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("2f0bd3e4-d754-4255-8ec4-00cd101296ab")) __declspec(novtable) IInkToolbarBallpointPenButtonFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IInkToolbarBallpointPenButton ** instance) = 0;
};

struct __declspec(uuid("4082207b-2f3d-4e6a-8c27-fe61ef7e70eb")) __declspec(novtable) IInkToolbarCustomPen : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInkDrawingAttributes(Windows::UI::Xaml::Media::IBrush * brush, double strokeWidth, Windows::UI::Input::Inking::IInkDrawingAttributes ** returnValue) = 0;
};

struct __declspec(uuid("46024401-2b2a-4f3c-a53c-1a045a408efa")) __declspec(novtable) IInkToolbarCustomPenButton : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CustomPen(Windows::UI::Xaml::Controls::IInkToolbarCustomPen ** value) = 0;
    virtual HRESULT __stdcall put_CustomPen(Windows::UI::Xaml::Controls::IInkToolbarCustomPen * value) = 0;
    virtual HRESULT __stdcall get_ConfigurationContent(Windows::UI::Xaml::IUIElement ** value) = 0;
    virtual HRESULT __stdcall put_ConfigurationContent(Windows::UI::Xaml::IUIElement * value) = 0;
};

struct __declspec(uuid("0f2ef0ba-c8b9-4c36-8987-94d3dafede18")) __declspec(novtable) IInkToolbarCustomPenButtonFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IInkToolbarCustomPenButton ** instance) = 0;
};

struct __declspec(uuid("373c25f4-e555-4e85-a80d-da6b8433dbde")) __declspec(novtable) IInkToolbarCustomPenButtonStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CustomPenProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ConfigurationContentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("d214d636-f1aa-4f48-bf2c-a926caae4c60")) __declspec(novtable) IInkToolbarCustomPenFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IInkToolbarCustomPen ** instance) = 0;
};

struct __declspec(uuid("9d22eb6c-1255-4256-b6bd-82c2fd273488")) __declspec(novtable) IInkToolbarCustomPenOverrides : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInkDrawingAttributesCore(Windows::UI::Xaml::Media::IBrush * brush, double strokeWidth, Windows::UI::Input::Inking::IInkDrawingAttributes ** returnValue) = 0;
};

struct __declspec(uuid("550c4d84-4f54-4fbe-b12b-e0a50aab0d05")) __declspec(novtable) IInkToolbarCustomToggleButton : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("4a00374d-4cd2-4ed9-863e-83b8cf3fd2af")) __declspec(novtable) IInkToolbarCustomToggleButtonFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IInkToolbarCustomToggleButton ** instance) = 0;
};

struct __declspec(uuid("9f98acd7-c605-4105-be10-3943a7c0da3c")) __declspec(novtable) IInkToolbarCustomToolButton : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ConfigurationContent(Windows::UI::Xaml::IUIElement ** value) = 0;
    virtual HRESULT __stdcall put_ConfigurationContent(Windows::UI::Xaml::IUIElement * value) = 0;
};

struct __declspec(uuid("c295fe4e-30eb-4130-a6b6-8c85d8e26e89")) __declspec(novtable) IInkToolbarCustomToolButtonFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IInkToolbarCustomToolButton ** instance) = 0;
};

struct __declspec(uuid("11fe4cb9-bbac-4314-9344-92c6693ddeaf")) __declspec(novtable) IInkToolbarCustomToolButtonStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ConfigurationContentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("4cbdb92e-5f5e-4b35-a41c-16ffb0283bc0")) __declspec(novtable) IInkToolbarEraserButton : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("fd40611d-d1ba-4d67-af00-148036ad492c")) __declspec(novtable) IInkToolbarEraserButtonFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IInkToolbarEraserButton ** instance) = 0;
};

struct __declspec(uuid("3947aa99-36b1-4374-ab5c-98bf07a4320b")) __declspec(novtable) IInkToolbarFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IInkToolbar ** instance) = 0;
};

struct __declspec(uuid("0b3cc15b-7abf-487e-acc1-5b5048fee6d2")) __declspec(novtable) IInkToolbarHighlighterButton : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("7c334add-42ca-4943-94a4-23b5a6e55cf1")) __declspec(novtable) IInkToolbarHighlighterButtonFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IInkToolbarHighlighterButton ** instance) = 0;
};

struct __declspec(uuid("e0b80c21-b032-40ee-a2b9-507f6ccb827b")) __declspec(novtable) IInkToolbarPenButton : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Palette(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Brush> ** value) = 0;
    virtual HRESULT __stdcall put_Palette(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Brush> * value) = 0;
    virtual HRESULT __stdcall get_MinStrokeWidth(double * value) = 0;
    virtual HRESULT __stdcall put_MinStrokeWidth(double value) = 0;
    virtual HRESULT __stdcall get_MaxStrokeWidth(double * value) = 0;
    virtual HRESULT __stdcall put_MaxStrokeWidth(double value) = 0;
    virtual HRESULT __stdcall get_SelectedBrush(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall get_SelectedBrushIndex(int32_t * value) = 0;
    virtual HRESULT __stdcall put_SelectedBrushIndex(int32_t value) = 0;
    virtual HRESULT __stdcall get_SelectedStrokeWidth(double * value) = 0;
    virtual HRESULT __stdcall put_SelectedStrokeWidth(double value) = 0;
};

struct __declspec(uuid("b1463d21-59cb-4a83-92e1-692842797b2e")) __declspec(novtable) IInkToolbarPenButtonFactory : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("b922ce42-09f0-453d-8026-44daf2753f65")) __declspec(novtable) IInkToolbarPenButtonStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PaletteProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MinStrokeWidthProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MaxStrokeWidthProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SelectedBrushProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SelectedBrushIndexProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SelectedStrokeWidthProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("601ae5f6-28a5-44cc-89a6-380e91a572dd")) __declspec(novtable) IInkToolbarPenConfigurationControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PenButton(Windows::UI::Xaml::Controls::IInkToolbarPenButton ** value) = 0;
};

struct __declspec(uuid("67f065ee-f5e7-46eb-9187-8d3ca3af891b")) __declspec(novtable) IInkToolbarPenConfigurationControlFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IInkToolbarPenConfigurationControl ** instance) = 0;
};

struct __declspec(uuid("48a61bef-19ce-41bb-abe0-7c8726fae75e")) __declspec(novtable) IInkToolbarPenConfigurationControlStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PenButtonProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("5b112832-1984-4148-9f25-382b35db087f")) __declspec(novtable) IInkToolbarPencilButton : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("db66d85f-cfd6-495f-93ab-b8566af9f8af")) __declspec(novtable) IInkToolbarPencilButtonFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IInkToolbarPencilButton ** instance) = 0;
};

struct __declspec(uuid("4a992832-1984-4148-9f25-382b35db087f")) __declspec(novtable) IInkToolbarRulerButton : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Ruler(Windows::UI::Input::Inking::IInkPresenterRuler ** value) = 0;
};

struct __declspec(uuid("bb26d85f-cfd6-495f-93ab-b8566af9f8af")) __declspec(novtable) IInkToolbarRulerButtonFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IInkToolbarRulerButton ** instance) = 0;
};

struct __declspec(uuid("bae75f65-be30-4bee-964b-ff9e498fee37")) __declspec(novtable) IInkToolbarRulerButtonStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RulerProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("a3b493bb-cb4f-4e6b-a33d-f11e7a295efa")) __declspec(novtable) IInkToolbarStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_InitialControlsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ChildrenProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ActiveToolProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_InkDrawingAttributesProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsRulerButtonCheckedProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TargetInkCanvasProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("b4a278fa-f5f0-4b1f-beb0-0b8a29905a4a")) __declspec(novtable) IInkToolbarToggleButton : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ToggleKind(winrt::Windows::UI::Xaml::Controls::InkToolbarToggle * value) = 0;
};

struct __declspec(uuid("b2f90710-e5a1-4365-9d1a-e5b7ad8b9668")) __declspec(novtable) IInkToolbarToggleButtonFactory : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("5c5af41e-ccb7-4458-8064-a9849d31561b")) __declspec(novtable) IInkToolbarToolButton : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ToolKind(winrt::Windows::UI::Xaml::Controls::InkToolbarTool * value) = 0;
    virtual HRESULT __stdcall get_IsExtensionGlyphShown(bool * value) = 0;
    virtual HRESULT __stdcall put_IsExtensionGlyphShown(bool value) = 0;
};

struct __declspec(uuid("6293bf4b-89fe-4ed0-a1a6-88d3eba917b2")) __declspec(novtable) IInkToolbarToolButtonFactory : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("9e097d18-d136-4ef6-b0fd-1a78c2884a01")) __declspec(novtable) IInkToolbarToolButtonStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsExtensionGlyphShownProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("6b8de08f-6527-4d39-bcbf-58b01da923d7")) __declspec(novtable) IInsertionPanel : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetInsertionIndexes(Windows::Foundation::Point position, int32_t * first, int32_t * second) = 0;
};

struct __declspec(uuid("9c314242-f29a-494d-a3a5-d4c7b2a46852")) __declspec(novtable) IItemClickEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ClickedItem(Windows::Foundation::IInspectable ** value) = 0;
};

struct __declspec(uuid("40765f00-83f0-4d7f-b1b8-f19de4f1d5da")) __declspec(novtable) IItemContainerGenerator : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_ItemsChanged(Windows::UI::Xaml::Controls::Primitives::ItemsChangedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ItemsChanged(event_token token) = 0;
    virtual HRESULT __stdcall abi_ItemFromContainer(Windows::UI::Xaml::IDependencyObject * container, Windows::Foundation::IInspectable ** returnValue) = 0;
    virtual HRESULT __stdcall abi_ContainerFromItem(Windows::Foundation::IInspectable * item, Windows::UI::Xaml::IDependencyObject ** returnValue) = 0;
    virtual HRESULT __stdcall abi_IndexFromContainer(Windows::UI::Xaml::IDependencyObject * container, int32_t * returnValue) = 0;
    virtual HRESULT __stdcall abi_ContainerFromIndex(int32_t index, Windows::UI::Xaml::IDependencyObject ** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetItemContainerGeneratorForPanel(Windows::UI::Xaml::Controls::IPanel * panel, Windows::UI::Xaml::Controls::IItemContainerGenerator ** returnValue) = 0;
    virtual HRESULT __stdcall abi_StartAt(Windows::UI::Xaml::Controls::Primitives::GeneratorPosition position, winrt::Windows::UI::Xaml::Controls::Primitives::GeneratorDirection direction, bool allowStartAtRealizedItem) = 0;
    virtual HRESULT __stdcall abi_Stop() = 0;
    virtual HRESULT __stdcall abi_GenerateNext(bool * isNewlyRealized, Windows::UI::Xaml::IDependencyObject ** returnValue) = 0;
    virtual HRESULT __stdcall abi_PrepareItemContainer(Windows::UI::Xaml::IDependencyObject * container) = 0;
    virtual HRESULT __stdcall abi_RemoveAll() = 0;
    virtual HRESULT __stdcall abi_Remove(Windows::UI::Xaml::Controls::Primitives::GeneratorPosition position, int32_t count) = 0;
    virtual HRESULT __stdcall abi_GeneratorPositionFromIndex(int32_t itemIndex, Windows::UI::Xaml::Controls::Primitives::GeneratorPosition * returnValue) = 0;
    virtual HRESULT __stdcall abi_IndexFromGeneratorPosition(Windows::UI::Xaml::Controls::Primitives::GeneratorPosition position, int32_t * returnValue) = 0;
    virtual HRESULT __stdcall abi_Recycle(Windows::UI::Xaml::Controls::Primitives::GeneratorPosition position, int32_t count) = 0;
};

struct __declspec(uuid("53c9f23a-f25d-446a-99b8-c7aeb839050f")) __declspec(novtable) IItemContainerMapping : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ItemFromContainer(Windows::UI::Xaml::IDependencyObject * container, Windows::Foundation::IInspectable ** returnValue) = 0;
    virtual HRESULT __stdcall abi_ContainerFromItem(Windows::Foundation::IInspectable * item, Windows::UI::Xaml::IDependencyObject ** returnValue) = 0;
    virtual HRESULT __stdcall abi_IndexFromContainer(Windows::UI::Xaml::IDependencyObject * container, int32_t * returnValue) = 0;
    virtual HRESULT __stdcall abi_ContainerFromIndex(int32_t index, Windows::UI::Xaml::IDependencyObject ** returnValue) = 0;
};

struct __declspec(uuid("f4a91dd8-d979-4381-8652-bda0342a765e")) __declspec(novtable) IItemsControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ItemsSource(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_ItemsSource(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_Items(Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> ** value) = 0;
    virtual HRESULT __stdcall get_ItemTemplate(Windows::UI::Xaml::IDataTemplate ** value) = 0;
    virtual HRESULT __stdcall put_ItemTemplate(Windows::UI::Xaml::IDataTemplate * value) = 0;
    virtual HRESULT __stdcall get_ItemTemplateSelector(Windows::UI::Xaml::Controls::IDataTemplateSelector ** value) = 0;
    virtual HRESULT __stdcall put_ItemTemplateSelector(Windows::UI::Xaml::Controls::IDataTemplateSelector * value) = 0;
    virtual HRESULT __stdcall get_ItemsPanel(Windows::UI::Xaml::Controls::IItemsPanelTemplate ** value) = 0;
    virtual HRESULT __stdcall put_ItemsPanel(Windows::UI::Xaml::Controls::IItemsPanelTemplate * value) = 0;
    virtual HRESULT __stdcall get_DisplayMemberPath(hstring * value) = 0;
    virtual HRESULT __stdcall put_DisplayMemberPath(hstring value) = 0;
    virtual HRESULT __stdcall get_ItemContainerStyle(Windows::UI::Xaml::IStyle ** value) = 0;
    virtual HRESULT __stdcall put_ItemContainerStyle(Windows::UI::Xaml::IStyle * value) = 0;
    virtual HRESULT __stdcall get_ItemContainerStyleSelector(Windows::UI::Xaml::Controls::IStyleSelector ** value) = 0;
    virtual HRESULT __stdcall put_ItemContainerStyleSelector(Windows::UI::Xaml::Controls::IStyleSelector * value) = 0;
    virtual HRESULT __stdcall get_ItemContainerGenerator(Windows::UI::Xaml::Controls::IItemContainerGenerator ** value) = 0;
    virtual HRESULT __stdcall get_ItemContainerTransitions(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Animation::Transition> ** value) = 0;
    virtual HRESULT __stdcall put_ItemContainerTransitions(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Animation::Transition> * value) = 0;
    virtual HRESULT __stdcall get_GroupStyle(Windows::Foundation::Collections::IObservableVector<Windows::UI::Xaml::Controls::GroupStyle> ** value) = 0;
    virtual HRESULT __stdcall get_GroupStyleSelector(Windows::UI::Xaml::Controls::IGroupStyleSelector ** value) = 0;
    virtual HRESULT __stdcall put_GroupStyleSelector(Windows::UI::Xaml::Controls::IGroupStyleSelector * value) = 0;
    virtual HRESULT __stdcall get_IsGrouping(bool * value) = 0;
};

struct __declspec(uuid("754c3266-0529-45e3-8748-bf747d158357")) __declspec(novtable) IItemsControl2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ItemsPanelRoot(Windows::UI::Xaml::Controls::IPanel ** value) = 0;
};

struct __declspec(uuid("502b7489-aee4-4de3-a2ab-195ac20c4212")) __declspec(novtable) IItemsControl3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GroupHeaderContainerFromItemContainer(Windows::UI::Xaml::IDependencyObject * itemContainer, Windows::UI::Xaml::IDependencyObject ** returnValue) = 0;
};

struct __declspec(uuid("f7bbc359-f8fd-471c-bcb2-2c74be8ebf8c")) __declspec(novtable) IItemsControlFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IItemsControl ** instance) = 0;
};

struct __declspec(uuid("c79bb41b-a084-4301-a496-72971f364ed1")) __declspec(novtable) IItemsControlOverrides : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_IsItemItsOwnContainerOverride(Windows::Foundation::IInspectable * item, bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetContainerForItemOverride(Windows::UI::Xaml::IDependencyObject ** returnValue) = 0;
    virtual HRESULT __stdcall abi_ClearContainerForItemOverride(Windows::UI::Xaml::IDependencyObject * element, Windows::Foundation::IInspectable * item) = 0;
    virtual HRESULT __stdcall abi_PrepareContainerForItemOverride(Windows::UI::Xaml::IDependencyObject * element, Windows::Foundation::IInspectable * item) = 0;
    virtual HRESULT __stdcall abi_OnItemsChanged(Windows::Foundation::IInspectable * e) = 0;
    virtual HRESULT __stdcall abi_OnItemContainerStyleChanged(Windows::UI::Xaml::IStyle * oldItemContainerStyle, Windows::UI::Xaml::IStyle * newItemContainerStyle) = 0;
    virtual HRESULT __stdcall abi_OnItemContainerStyleSelectorChanged(Windows::UI::Xaml::Controls::IStyleSelector * oldItemContainerStyleSelector, Windows::UI::Xaml::Controls::IStyleSelector * newItemContainerStyleSelector) = 0;
    virtual HRESULT __stdcall abi_OnItemTemplateChanged(Windows::UI::Xaml::IDataTemplate * oldItemTemplate, Windows::UI::Xaml::IDataTemplate * newItemTemplate) = 0;
    virtual HRESULT __stdcall abi_OnItemTemplateSelectorChanged(Windows::UI::Xaml::Controls::IDataTemplateSelector * oldItemTemplateSelector, Windows::UI::Xaml::Controls::IDataTemplateSelector * newItemTemplateSelector) = 0;
    virtual HRESULT __stdcall abi_OnGroupStyleSelectorChanged(Windows::UI::Xaml::Controls::IGroupStyleSelector * oldGroupStyleSelector, Windows::UI::Xaml::Controls::IGroupStyleSelector * newGroupStyleSelector) = 0;
};

struct __declspec(uuid("37dabd89-dcfb-45b8-9afe-874df097905e")) __declspec(novtable) IItemsControlStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ItemsSourceProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ItemTemplateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ItemTemplateSelectorProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ItemsPanelProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_DisplayMemberPathProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ItemContainerStyleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ItemContainerStyleSelectorProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ItemContainerTransitionsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_GroupStyleSelectorProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsGroupingProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetItemsOwner(Windows::UI::Xaml::IDependencyObject * element, Windows::UI::Xaml::Controls::IItemsControl ** returnValue) = 0;
    virtual HRESULT __stdcall abi_ItemsControlFromItemContainer(Windows::UI::Xaml::IDependencyObject * container, Windows::UI::Xaml::Controls::IItemsControl ** returnValue) = 0;
};

struct __declspec(uuid("14ead768-34b2-4b97-bf3c-e8d73230a2aa")) __declspec(novtable) IItemsPanelTemplate : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("f95b9aac-a621-488e-9156-8ee31165be04")) __declspec(novtable) IItemsPickedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AddedItems(Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> ** value) = 0;
    virtual HRESULT __stdcall get_RemovedItems(Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> ** value) = 0;
};

struct __declspec(uuid("c271569b-6dca-4e2b-8e14-c55136b02a71")) __declspec(novtable) IItemsPresenter : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Header(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_Header(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_HeaderTemplate(Windows::UI::Xaml::IDataTemplate ** value) = 0;
    virtual HRESULT __stdcall put_HeaderTemplate(Windows::UI::Xaml::IDataTemplate * value) = 0;
    virtual HRESULT __stdcall get_HeaderTransitions(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Animation::Transition> ** value) = 0;
    virtual HRESULT __stdcall put_HeaderTransitions(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Animation::Transition> * value) = 0;
    virtual HRESULT __stdcall get_Padding(Windows::UI::Xaml::Thickness * value) = 0;
    virtual HRESULT __stdcall put_Padding(Windows::UI::Xaml::Thickness value) = 0;
};

struct __declspec(uuid("5c04aa33-1df3-4731-a4c9-da818378d63d")) __declspec(novtable) IItemsPresenter2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Footer(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_Footer(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_FooterTemplate(Windows::UI::Xaml::IDataTemplate ** value) = 0;
    virtual HRESULT __stdcall put_FooterTemplate(Windows::UI::Xaml::IDataTemplate * value) = 0;
    virtual HRESULT __stdcall get_FooterTransitions(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Animation::Transition> ** value) = 0;
    virtual HRESULT __stdcall put_FooterTransitions(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Animation::Transition> * value) = 0;
};

struct __declspec(uuid("18de66cd-4a6c-4b2e-aa86-cb126c9a2920")) __declspec(novtable) IItemsPresenterStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_HeaderProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_HeaderTemplateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_HeaderTransitionsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PaddingProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("8971632e-7867-4d66-9630-29f1c5f7403f")) __declspec(novtable) IItemsPresenterStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FooterProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FooterTemplateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FooterTransitionsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("df7ab79d-7ad5-4b58-9363-919af90226e6")) __declspec(novtable) IItemsStackPanel : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_GroupPadding(Windows::UI::Xaml::Thickness * value) = 0;
    virtual HRESULT __stdcall put_GroupPadding(Windows::UI::Xaml::Thickness value) = 0;
    virtual HRESULT __stdcall get_Orientation(winrt::Windows::UI::Xaml::Controls::Orientation * value) = 0;
    virtual HRESULT __stdcall put_Orientation(winrt::Windows::UI::Xaml::Controls::Orientation value) = 0;
    virtual HRESULT __stdcall get_FirstCacheIndex(int32_t * value) = 0;
    virtual HRESULT __stdcall get_FirstVisibleIndex(int32_t * value) = 0;
    virtual HRESULT __stdcall get_LastVisibleIndex(int32_t * value) = 0;
    virtual HRESULT __stdcall get_LastCacheIndex(int32_t * value) = 0;
    virtual HRESULT __stdcall get_ScrollingDirection(winrt::Windows::UI::Xaml::Controls::PanelScrollingDirection * value) = 0;
    virtual HRESULT __stdcall get_GroupHeaderPlacement(winrt::Windows::UI::Xaml::Controls::Primitives::GroupHeaderPlacement * value) = 0;
    virtual HRESULT __stdcall put_GroupHeaderPlacement(winrt::Windows::UI::Xaml::Controls::Primitives::GroupHeaderPlacement value) = 0;
    virtual HRESULT __stdcall get_ItemsUpdatingScrollMode(winrt::Windows::UI::Xaml::Controls::ItemsUpdatingScrollMode * value) = 0;
    virtual HRESULT __stdcall put_ItemsUpdatingScrollMode(winrt::Windows::UI::Xaml::Controls::ItemsUpdatingScrollMode value) = 0;
    virtual HRESULT __stdcall get_CacheLength(double * value) = 0;
    virtual HRESULT __stdcall put_CacheLength(double value) = 0;
};

struct __declspec(uuid("eeeecdb0-00b4-4534-937b-56318b293e92")) __declspec(novtable) IItemsStackPanel2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AreStickyGroupHeadersEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_AreStickyGroupHeadersEnabled(bool value) = 0;
};

struct __declspec(uuid("ca25d63f-044f-4b6b-b315-0b60e0b4f87d")) __declspec(novtable) IItemsStackPanelStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_GroupPaddingProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_OrientationProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_GroupHeaderPlacementProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CacheLengthProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("3972eb2c-384a-48bf-adfd-772e2572c504")) __declspec(novtable) IItemsStackPanelStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AreStickyGroupHeadersEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("ddfe6b5f-ba88-4a7d-8a5b-e58caf0f4e2d")) __declspec(novtable) IItemsWrapGrid : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_GroupPadding(Windows::UI::Xaml::Thickness * value) = 0;
    virtual HRESULT __stdcall put_GroupPadding(Windows::UI::Xaml::Thickness value) = 0;
    virtual HRESULT __stdcall get_Orientation(winrt::Windows::UI::Xaml::Controls::Orientation * value) = 0;
    virtual HRESULT __stdcall put_Orientation(winrt::Windows::UI::Xaml::Controls::Orientation value) = 0;
    virtual HRESULT __stdcall get_MaximumRowsOrColumns(int32_t * value) = 0;
    virtual HRESULT __stdcall put_MaximumRowsOrColumns(int32_t value) = 0;
    virtual HRESULT __stdcall get_ItemWidth(double * value) = 0;
    virtual HRESULT __stdcall put_ItemWidth(double value) = 0;
    virtual HRESULT __stdcall get_ItemHeight(double * value) = 0;
    virtual HRESULT __stdcall put_ItemHeight(double value) = 0;
    virtual HRESULT __stdcall get_FirstCacheIndex(int32_t * value) = 0;
    virtual HRESULT __stdcall get_FirstVisibleIndex(int32_t * value) = 0;
    virtual HRESULT __stdcall get_LastVisibleIndex(int32_t * value) = 0;
    virtual HRESULT __stdcall get_LastCacheIndex(int32_t * value) = 0;
    virtual HRESULT __stdcall get_ScrollingDirection(winrt::Windows::UI::Xaml::Controls::PanelScrollingDirection * value) = 0;
    virtual HRESULT __stdcall get_GroupHeaderPlacement(winrt::Windows::UI::Xaml::Controls::Primitives::GroupHeaderPlacement * value) = 0;
    virtual HRESULT __stdcall put_GroupHeaderPlacement(winrt::Windows::UI::Xaml::Controls::Primitives::GroupHeaderPlacement value) = 0;
    virtual HRESULT __stdcall get_CacheLength(double * value) = 0;
    virtual HRESULT __stdcall put_CacheLength(double value) = 0;
};

struct __declspec(uuid("80c21c0f-63ec-4258-bd61-d4a6956c864a")) __declspec(novtable) IItemsWrapGrid2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AreStickyGroupHeadersEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_AreStickyGroupHeadersEnabled(bool value) = 0;
};

struct __declspec(uuid("4ec5427d-24a0-449a-b763-3077ba0f2dd5")) __declspec(novtable) IItemsWrapGridStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_GroupPaddingProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_OrientationProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MaximumRowsOrColumnsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ItemWidthProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ItemHeightProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_GroupHeaderPlacementProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CacheLengthProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("2e27d3f7-feaa-478d-bfd1-29338adc5a03")) __declspec(novtable) IItemsWrapGridStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AreStickyGroupHeadersEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("e9f3b9ff-8e91-4ecf-a707-c927f694f881")) __declspec(novtable) IListBox : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SelectedItems(Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> ** value) = 0;
    virtual HRESULT __stdcall get_SelectionMode(winrt::Windows::UI::Xaml::Controls::SelectionMode * value) = 0;
    virtual HRESULT __stdcall put_SelectionMode(winrt::Windows::UI::Xaml::Controls::SelectionMode value) = 0;
    virtual HRESULT __stdcall abi_ScrollIntoView(Windows::Foundation::IInspectable * item) = 0;
    virtual HRESULT __stdcall abi_SelectAll() = 0;
};

struct __declspec(uuid("70572aba-8ad1-4085-9350-deee359294e3")) __declspec(novtable) IListBox2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SingleSelectionFollowsFocus(bool * value) = 0;
    virtual HRESULT __stdcall put_SingleSelectionFollowsFocus(bool value) = 0;
};

struct __declspec(uuid("60cdfda2-2f44-444b-9c94-b8c9fda46f59")) __declspec(novtable) IListBoxFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IListBox ** instance) = 0;
};

struct __declspec(uuid("43c13323-6edf-4e4b-b6b2-3a93eec41d95")) __declspec(novtable) IListBoxItem : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("4398b8d4-a3de-402c-b23d-190384b27ca8")) __declspec(novtable) IListBoxItemFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IListBoxItem ** instance) = 0;
};

struct __declspec(uuid("6d3f7f73-706a-4e53-a9aa-c9a53c9cdd70")) __declspec(novtable) IListBoxStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SelectionModeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("0089adeb-b709-4c8d-b1ed-4a7d97ee7716")) __declspec(novtable) IListBoxStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SingleSelectionFollowsFocusProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("0f0cb9d7-e5f3-45e6-9063-ff7bbb193c47")) __declspec(novtable) IListPickerFlyout : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ItemsSource(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_ItemsSource(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_ItemTemplate(Windows::UI::Xaml::IDataTemplate ** value) = 0;
    virtual HRESULT __stdcall put_ItemTemplate(Windows::UI::Xaml::IDataTemplate * value) = 0;
    virtual HRESULT __stdcall get_DisplayMemberPath(hstring * value) = 0;
    virtual HRESULT __stdcall put_DisplayMemberPath(hstring value) = 0;
    virtual HRESULT __stdcall get_SelectionMode(winrt::Windows::UI::Xaml::Controls::ListPickerFlyoutSelectionMode * value) = 0;
    virtual HRESULT __stdcall put_SelectionMode(winrt::Windows::UI::Xaml::Controls::ListPickerFlyoutSelectionMode value) = 0;
    virtual HRESULT __stdcall get_SelectedIndex(int32_t * value) = 0;
    virtual HRESULT __stdcall put_SelectedIndex(int32_t value) = 0;
    virtual HRESULT __stdcall get_SelectedItem(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_SelectedItem(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_SelectedValue(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_SelectedValue(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_SelectedValuePath(hstring * value) = 0;
    virtual HRESULT __stdcall put_SelectedValuePath(hstring value) = 0;
    virtual HRESULT __stdcall get_SelectedItems(Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> ** value) = 0;
    virtual HRESULT __stdcall add_ItemsPicked(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::ListPickerFlyout, Windows::UI::Xaml::Controls::ItemsPickedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ItemsPicked(event_token token) = 0;
    virtual HRESULT __stdcall abi_ShowAtAsync(Windows::UI::Xaml::IFrameworkElement * target, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Foundation::IInspectable>> ** returnValue) = 0;
};

struct __declspec(uuid("68155fb3-883e-417a-80d0-e2fd88410084")) __declspec(novtable) IListPickerFlyoutPresenter : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("fee25b97-8b96-4602-81d2-82fd8e0f7ea8")) __declspec(novtable) IListPickerFlyoutStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ItemsSourceProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ItemTemplateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_DisplayMemberPathProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SelectionModeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SelectedIndexProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SelectedItemProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SelectedValueProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SelectedValuePathProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("f6ce8c6d-fe96-41ad-a64a-c2b81c4af7f8")) __declspec(novtable) IListView : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("3d0813ba-6890-4537-bfe5-796d9458edd6")) __declspec(novtable) IListViewBase : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SelectedItems(Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> ** value) = 0;
    virtual HRESULT __stdcall get_SelectionMode(winrt::Windows::UI::Xaml::Controls::ListViewSelectionMode * value) = 0;
    virtual HRESULT __stdcall put_SelectionMode(winrt::Windows::UI::Xaml::Controls::ListViewSelectionMode value) = 0;
    virtual HRESULT __stdcall get_IsSwipeEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsSwipeEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_CanDragItems(bool * value) = 0;
    virtual HRESULT __stdcall put_CanDragItems(bool value) = 0;
    virtual HRESULT __stdcall get_CanReorderItems(bool * value) = 0;
    virtual HRESULT __stdcall put_CanReorderItems(bool value) = 0;
    virtual HRESULT __stdcall get_IsItemClickEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsItemClickEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_DataFetchSize(double * value) = 0;
    virtual HRESULT __stdcall put_DataFetchSize(double value) = 0;
    virtual HRESULT __stdcall get_IncrementalLoadingThreshold(double * value) = 0;
    virtual HRESULT __stdcall put_IncrementalLoadingThreshold(double value) = 0;
    virtual HRESULT __stdcall get_IncrementalLoadingTrigger(winrt::Windows::UI::Xaml::Controls::IncrementalLoadingTrigger * value) = 0;
    virtual HRESULT __stdcall put_IncrementalLoadingTrigger(winrt::Windows::UI::Xaml::Controls::IncrementalLoadingTrigger value) = 0;
    virtual HRESULT __stdcall add_ItemClick(Windows::UI::Xaml::Controls::ItemClickEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ItemClick(event_token token) = 0;
    virtual HRESULT __stdcall add_DragItemsStarting(Windows::UI::Xaml::Controls::DragItemsStartingEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DragItemsStarting(event_token token) = 0;
    virtual HRESULT __stdcall abi_ScrollIntoView(Windows::Foundation::IInspectable * item) = 0;
    virtual HRESULT __stdcall abi_SelectAll() = 0;
    virtual HRESULT __stdcall abi_LoadMoreItemsAsync(Windows::Foundation::IAsyncOperation<Windows::UI::Xaml::Data::LoadMoreItemsResult> ** returnValue) = 0;
    virtual HRESULT __stdcall abi_ScrollIntoViewWithAlignment(Windows::Foundation::IInspectable * item, winrt::Windows::UI::Xaml::Controls::ScrollIntoViewAlignment alignment) = 0;
    virtual HRESULT __stdcall get_Header(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_Header(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_HeaderTemplate(Windows::UI::Xaml::IDataTemplate ** value) = 0;
    virtual HRESULT __stdcall put_HeaderTemplate(Windows::UI::Xaml::IDataTemplate * value) = 0;
    virtual HRESULT __stdcall get_HeaderTransitions(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Animation::Transition> ** value) = 0;
    virtual HRESULT __stdcall put_HeaderTransitions(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Animation::Transition> * value) = 0;
};

struct __declspec(uuid("d1c2a4f7-78a3-4491-86e0-2ddebc007ac5")) __declspec(novtable) IListViewBase2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ShowsScrollingPlaceholders(bool * value) = 0;
    virtual HRESULT __stdcall put_ShowsScrollingPlaceholders(bool value) = 0;
    virtual HRESULT __stdcall add_ContainerContentChanging(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::ListViewBase, Windows::UI::Xaml::Controls::ContainerContentChangingEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ContainerContentChanging(event_token token) = 0;
    virtual HRESULT __stdcall abi_SetDesiredContainerUpdateDuration(Windows::Foundation::TimeSpan duration) = 0;
    virtual HRESULT __stdcall get_Footer(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_Footer(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_FooterTemplate(Windows::UI::Xaml::IDataTemplate ** value) = 0;
    virtual HRESULT __stdcall put_FooterTemplate(Windows::UI::Xaml::IDataTemplate * value) = 0;
    virtual HRESULT __stdcall get_FooterTransitions(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Animation::Transition> ** value) = 0;
    virtual HRESULT __stdcall put_FooterTransitions(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Animation::Transition> * value) = 0;
};

struct __declspec(uuid("b364c035-0a13-406f-a3fb-f30e7ddca94c")) __declspec(novtable) IListViewBase3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ReorderMode(winrt::Windows::UI::Xaml::Controls::ListViewReorderMode * value) = 0;
    virtual HRESULT __stdcall put_ReorderMode(winrt::Windows::UI::Xaml::Controls::ListViewReorderMode value) = 0;
};

struct __declspec(uuid("18b7792b-11dc-4eb6-a7bc-741adb3eeb79")) __declspec(novtable) IListViewBase4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SelectedRanges(Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Data::ItemIndexRange> ** value) = 0;
    virtual HRESULT __stdcall get_IsMultiSelectCheckBoxEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsMultiSelectCheckBoxEnabled(bool value) = 0;
    virtual HRESULT __stdcall add_DragItemsCompleted(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::ListViewBase, Windows::UI::Xaml::Controls::DragItemsCompletedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DragItemsCompleted(event_token token) = 0;
    virtual HRESULT __stdcall add_ChoosingItemContainer(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::ListViewBase, Windows::UI::Xaml::Controls::ChoosingItemContainerEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ChoosingItemContainer(event_token token) = 0;
    virtual HRESULT __stdcall add_ChoosingGroupHeaderContainer(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::ListViewBase, Windows::UI::Xaml::Controls::ChoosingGroupHeaderContainerEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ChoosingGroupHeaderContainer(event_token token) = 0;
    virtual HRESULT __stdcall abi_SelectRange(Windows::UI::Xaml::Data::IItemIndexRange * itemIndexRange) = 0;
    virtual HRESULT __stdcall abi_DeselectRange(Windows::UI::Xaml::Data::IItemIndexRange * itemIndexRange) = 0;
};

struct __declspec(uuid("1a9c6e99-1719-4b80-b335-628331a07019")) __declspec(novtable) IListViewBase5 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SingleSelectionFollowsFocus(bool * value) = 0;
    virtual HRESULT __stdcall put_SingleSelectionFollowsFocus(bool value) = 0;
    virtual HRESULT __stdcall abi_IsDragSource(bool * returnValue) = 0;
};

struct __declspec(uuid("e67e6c7f-150f-46d0-a6ac-c5002bd9ca53")) __declspec(novtable) IListViewBaseFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IListViewBase ** instance) = 0;
};

struct __declspec(uuid("6d0ded27-0d19-4091-8917-ce7c85c1e630")) __declspec(novtable) IListViewBaseHeaderItem : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("3872a6a1-ea19-455f-9df7-147cc41d329c")) __declspec(novtable) IListViewBaseHeaderItemFactory : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("8532b8f7-3e16-455b-89a8-c1346223f6d3")) __declspec(novtable) IListViewBaseStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SelectionModeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsSwipeEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CanDragItemsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CanReorderItemsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsItemClickEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_DataFetchSizeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IncrementalLoadingThresholdProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IncrementalLoadingTriggerProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SemanticZoomOwnerProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsActiveViewProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsZoomedInViewProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_HeaderProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_HeaderTemplateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_HeaderTransitionsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("821c00c8-78cc-411f-9f2e-a55758227f3e")) __declspec(novtable) IListViewBaseStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ShowsScrollingPlaceholdersProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FooterProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FooterTemplateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FooterTransitionsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("3b539091-31c6-4d0c-90af-5dc1d6ae9c05")) __declspec(novtable) IListViewBaseStatics3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ReorderModeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("ad13258b-fbd0-4f18-8bf8-9b8613951c22")) __declspec(novtable) IListViewBaseStatics4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsMultiSelectCheckBoxEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("40346fcf-0476-4259-895f-a6569738620f")) __declspec(novtable) IListViewBaseStatics5 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SingleSelectionFollowsFocusProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("bdff696d-3f22-41f9-97a6-883134a76113")) __declspec(novtable) IListViewFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IListView ** instance) = 0;
};

struct __declspec(uuid("1b61baeb-e196-4b3b-a5f9-1ed636f3f79b")) __declspec(novtable) IListViewHeaderItem : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("68d2c96a-96b0-4f08-a7a5-f1086720a0fa")) __declspec(novtable) IListViewHeaderItemFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IListViewHeaderItem ** instance) = 0;
};

struct __declspec(uuid("b7bb4305-3dd9-43de-a8c0-c472f085bc11")) __declspec(novtable) IListViewItem : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TemplateSettings(Windows::UI::Xaml::Controls::Primitives::IListViewItemTemplateSettings ** value) = 0;
};

struct __declspec(uuid("f431073d-9cac-42a2-82df-0f4490bc4e2e")) __declspec(novtable) IListViewItemFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IListViewItem ** instance) = 0;
};

struct __declspec(uuid("05bde8a6-2191-4b4b-8c22-9b25676e806e")) __declspec(novtable) IListViewPersistenceHelper : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("6d0c2b08-bb9b-44f9-8063-5c3f9c21884b")) __declspec(novtable) IListViewPersistenceHelperStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetRelativeScrollPosition(Windows::UI::Xaml::Controls::IListViewBase * listViewBase, Windows::UI::Xaml::Controls::ListViewItemToKeyHandler * itemToKeyHandler, hstring * returnValue) = 0;
    virtual HRESULT __stdcall abi_SetRelativeScrollPositionAsync(Windows::UI::Xaml::Controls::IListViewBase * listViewBase, hstring relativeScrollPosition, Windows::UI::Xaml::Controls::ListViewKeyToItemHandler * keyToItemHandler, Windows::Foundation::IAsyncAction ** returnValue) = 0;
};

struct __declspec(uuid("a38ed2cf-13de-4299-ade2-ae18f74ed353")) __declspec(novtable) IMediaElement : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PosterSource(Windows::UI::Xaml::Media::IImageSource ** value) = 0;
    virtual HRESULT __stdcall put_PosterSource(Windows::UI::Xaml::Media::IImageSource * value) = 0;
    virtual HRESULT __stdcall get_Source(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall put_Source(Windows::Foundation::IUriRuntimeClass * value) = 0;
    virtual HRESULT __stdcall get_IsMuted(bool * value) = 0;
    virtual HRESULT __stdcall put_IsMuted(bool value) = 0;
    virtual HRESULT __stdcall get_IsAudioOnly(bool * value) = 0;
    virtual HRESULT __stdcall get_AutoPlay(bool * value) = 0;
    virtual HRESULT __stdcall put_AutoPlay(bool value) = 0;
    virtual HRESULT __stdcall get_Volume(double * value) = 0;
    virtual HRESULT __stdcall put_Volume(double value) = 0;
    virtual HRESULT __stdcall get_Balance(double * value) = 0;
    virtual HRESULT __stdcall put_Balance(double value) = 0;
    virtual HRESULT __stdcall get_NaturalVideoHeight(int32_t * value) = 0;
    virtual HRESULT __stdcall get_NaturalVideoWidth(int32_t * value) = 0;
    virtual HRESULT __stdcall get_NaturalDuration(Windows::UI::Xaml::Duration * value) = 0;
    virtual HRESULT __stdcall get_Position(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall put_Position(Windows::Foundation::TimeSpan value) = 0;
    virtual HRESULT __stdcall get_DownloadProgress(double * value) = 0;
    virtual HRESULT __stdcall get_BufferingProgress(double * value) = 0;
    virtual HRESULT __stdcall get_DownloadProgressOffset(double * value) = 0;
    virtual HRESULT __stdcall get_CurrentState(winrt::Windows::UI::Xaml::Media::MediaElementState * value) = 0;
    virtual HRESULT __stdcall get_Markers(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::TimelineMarker> ** value) = 0;
    virtual HRESULT __stdcall get_CanSeek(bool * value) = 0;
    virtual HRESULT __stdcall get_CanPause(bool * value) = 0;
    virtual HRESULT __stdcall get_AudioStreamCount(int32_t * value) = 0;
    virtual HRESULT __stdcall get_AudioStreamIndex(Windows::Foundation::IReference<int32_t> ** value) = 0;
    virtual HRESULT __stdcall put_AudioStreamIndex(Windows::Foundation::IReference<int32_t> * value) = 0;
    virtual HRESULT __stdcall get_PlaybackRate(double * value) = 0;
    virtual HRESULT __stdcall put_PlaybackRate(double value) = 0;
    virtual HRESULT __stdcall get_IsLooping(bool * value) = 0;
    virtual HRESULT __stdcall put_IsLooping(bool value) = 0;
    virtual HRESULT __stdcall get_PlayToSource(Windows::Media::PlayTo::IPlayToSource ** value) = 0;
    virtual HRESULT __stdcall get_DefaultPlaybackRate(double * value) = 0;
    virtual HRESULT __stdcall put_DefaultPlaybackRate(double value) = 0;
    virtual HRESULT __stdcall get_AspectRatioWidth(int32_t * value) = 0;
    virtual HRESULT __stdcall get_AspectRatioHeight(int32_t * value) = 0;
    virtual HRESULT __stdcall get_RealTimePlayback(bool * value) = 0;
    virtual HRESULT __stdcall put_RealTimePlayback(bool value) = 0;
    virtual HRESULT __stdcall get_AudioCategory(winrt::Windows::UI::Xaml::Media::AudioCategory * value) = 0;
    virtual HRESULT __stdcall put_AudioCategory(winrt::Windows::UI::Xaml::Media::AudioCategory value) = 0;
    virtual HRESULT __stdcall get_AudioDeviceType(winrt::Windows::UI::Xaml::Media::AudioDeviceType * value) = 0;
    virtual HRESULT __stdcall put_AudioDeviceType(winrt::Windows::UI::Xaml::Media::AudioDeviceType value) = 0;
    virtual HRESULT __stdcall get_ProtectionManager(Windows::Media::Protection::IMediaProtectionManager ** value) = 0;
    virtual HRESULT __stdcall put_ProtectionManager(Windows::Media::Protection::IMediaProtectionManager * value) = 0;
    virtual HRESULT __stdcall get_Stereo3DVideoPackingMode(winrt::Windows::UI::Xaml::Media::Stereo3DVideoPackingMode * value) = 0;
    virtual HRESULT __stdcall put_Stereo3DVideoPackingMode(winrt::Windows::UI::Xaml::Media::Stereo3DVideoPackingMode value) = 0;
    virtual HRESULT __stdcall get_Stereo3DVideoRenderMode(winrt::Windows::UI::Xaml::Media::Stereo3DVideoRenderMode * value) = 0;
    virtual HRESULT __stdcall put_Stereo3DVideoRenderMode(winrt::Windows::UI::Xaml::Media::Stereo3DVideoRenderMode value) = 0;
    virtual HRESULT __stdcall get_IsStereo3DVideo(bool * value) = 0;
    virtual HRESULT __stdcall add_MediaOpened(Windows::UI::Xaml::RoutedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_MediaOpened(event_token token) = 0;
    virtual HRESULT __stdcall add_MediaEnded(Windows::UI::Xaml::RoutedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_MediaEnded(event_token token) = 0;
    virtual HRESULT __stdcall add_MediaFailed(Windows::UI::Xaml::ExceptionRoutedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_MediaFailed(event_token token) = 0;
    virtual HRESULT __stdcall add_DownloadProgressChanged(Windows::UI::Xaml::RoutedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DownloadProgressChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_BufferingProgressChanged(Windows::UI::Xaml::RoutedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_BufferingProgressChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_CurrentStateChanged(Windows::UI::Xaml::RoutedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_CurrentStateChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_MarkerReached(Windows::UI::Xaml::Media::TimelineMarkerRoutedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_MarkerReached(event_token token) = 0;
    virtual HRESULT __stdcall add_RateChanged(Windows::UI::Xaml::Media::RateChangedRoutedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_RateChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_VolumeChanged(Windows::UI::Xaml::RoutedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_VolumeChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_SeekCompleted(Windows::UI::Xaml::RoutedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SeekCompleted(event_token token) = 0;
    virtual HRESULT __stdcall abi_Stop() = 0;
    virtual HRESULT __stdcall abi_Play() = 0;
    virtual HRESULT __stdcall abi_Pause() = 0;
    virtual HRESULT __stdcall abi_CanPlayType(hstring type, winrt::Windows::UI::Xaml::Media::MediaCanPlayResponse * returnValue) = 0;
    virtual HRESULT __stdcall abi_SetSource(Windows::Storage::Streams::IRandomAccessStream * stream, hstring mimeType) = 0;
    virtual HRESULT __stdcall abi_GetAudioStreamLanguage(Windows::Foundation::IReference<int32_t> * index, hstring * returnValue) = 0;
    virtual HRESULT __stdcall abi_AddAudioEffect(hstring effectID, bool effectOptional, Windows::Foundation::Collections::IPropertySet * effectConfiguration) = 0;
    virtual HRESULT __stdcall abi_AddVideoEffect(hstring effectID, bool effectOptional, Windows::Foundation::Collections::IPropertySet * effectConfiguration) = 0;
    virtual HRESULT __stdcall abi_RemoveAllEffects() = 0;
    virtual HRESULT __stdcall get_ActualStereo3DVideoPackingMode(winrt::Windows::UI::Xaml::Media::Stereo3DVideoPackingMode * value) = 0;
};

struct __declspec(uuid("fd53da65-b186-4654-bfdb-180ed26cad07")) __declspec(novtable) IMediaElement2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AreTransportControlsEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_AreTransportControlsEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_Stretch(winrt::Windows::UI::Xaml::Media::Stretch * value) = 0;
    virtual HRESULT __stdcall put_Stretch(winrt::Windows::UI::Xaml::Media::Stretch value) = 0;
    virtual HRESULT __stdcall get_IsFullWindow(bool * value) = 0;
    virtual HRESULT __stdcall put_IsFullWindow(bool value) = 0;
    virtual HRESULT __stdcall abi_SetMediaStreamSource(Windows::Media::Core::IMediaSource * source) = 0;
    virtual HRESULT __stdcall get_PlayToPreferredSourceUri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall put_PlayToPreferredSourceUri(Windows::Foundation::IUriRuntimeClass * value) = 0;
};

struct __declspec(uuid("479f6f13-0fdb-4ed8-928a-4d39169c3cd2")) __declspec(novtable) IMediaElement3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TransportControls(Windows::UI::Xaml::Controls::IMediaTransportControls ** value) = 0;
    virtual HRESULT __stdcall put_TransportControls(Windows::UI::Xaml::Controls::IMediaTransportControls * value) = 0;
    virtual HRESULT __stdcall add_PartialMediaFailureDetected(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::MediaElement, Windows::UI::Xaml::Media::PartialMediaFailureDetectedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PartialMediaFailureDetected(event_token token) = 0;
    virtual HRESULT __stdcall abi_SetPlaybackSource(Windows::Media::Playback::IMediaPlaybackSource * source) = 0;
    virtual HRESULT __stdcall abi_GetAsCastingSource(Windows::Media::Casting::ICastingSource ** returnValue) = 0;
};

struct __declspec(uuid("dccd2cb9-7568-4682-a72a-8ddf2a2665ca")) __declspec(novtable) IMediaElementStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PosterSourceProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SourceProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsMutedProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsAudioOnlyProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_AutoPlayProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_VolumeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_BalanceProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_NaturalVideoHeightProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_NaturalVideoWidthProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_NaturalDurationProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PositionProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_DownloadProgressProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_BufferingProgressProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_DownloadProgressOffsetProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CurrentStateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CanSeekProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CanPauseProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_AudioStreamCountProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_AudioStreamIndexProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PlaybackRateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsLoopingProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PlayToSourceProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_DefaultPlaybackRateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_AspectRatioWidthProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_AspectRatioHeightProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_RealTimePlaybackProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_AudioCategoryProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_AudioDeviceTypeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ProtectionManagerProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_Stereo3DVideoPackingModeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_Stereo3DVideoRenderModeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsStereo3DVideoProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ActualStereo3DVideoPackingModeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("9ee7f826-f154-4dc6-8014-a6eba987f847")) __declspec(novtable) IMediaElementStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AreTransportControlsEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_StretchProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsFullWindowProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PlayToPreferredSourceUriProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("3b4ca526-2e25-4598-bc71-d491f8e8de39")) __declspec(novtable) IMediaPlayerElement : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Source(Windows::Media::Playback::IMediaPlaybackSource ** value) = 0;
    virtual HRESULT __stdcall put_Source(Windows::Media::Playback::IMediaPlaybackSource * value) = 0;
    virtual HRESULT __stdcall get_TransportControls(Windows::UI::Xaml::Controls::IMediaTransportControls ** value) = 0;
    virtual HRESULT __stdcall put_TransportControls(Windows::UI::Xaml::Controls::IMediaTransportControls * value) = 0;
    virtual HRESULT __stdcall get_AreTransportControlsEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_AreTransportControlsEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_PosterSource(Windows::UI::Xaml::Media::IImageSource ** value) = 0;
    virtual HRESULT __stdcall put_PosterSource(Windows::UI::Xaml::Media::IImageSource * value) = 0;
    virtual HRESULT __stdcall get_Stretch(winrt::Windows::UI::Xaml::Media::Stretch * value) = 0;
    virtual HRESULT __stdcall put_Stretch(winrt::Windows::UI::Xaml::Media::Stretch value) = 0;
    virtual HRESULT __stdcall get_AutoPlay(bool * value) = 0;
    virtual HRESULT __stdcall put_AutoPlay(bool value) = 0;
    virtual HRESULT __stdcall get_IsFullWindow(bool * value) = 0;
    virtual HRESULT __stdcall put_IsFullWindow(bool value) = 0;
    virtual HRESULT __stdcall get_MediaPlayer(Windows::Media::Playback::IMediaPlayer ** value) = 0;
    virtual HRESULT __stdcall abi_SetMediaPlayer(Windows::Media::Playback::IMediaPlayer * mediaPlayer) = 0;
};

struct __declspec(uuid("77e525c3-eb17-4b8d-889d-1ea8abdbd4ef")) __declspec(novtable) IMediaPlayerElementFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IMediaPlayerElement ** instance) = 0;
};

struct __declspec(uuid("1e7c4020-ac57-42dd-ad1c-3ebc2d7f08ba")) __declspec(novtable) IMediaPlayerElementStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SourceProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_AreTransportControlsEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PosterSourceProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_StretchProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_AutoPlayProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsFullWindowProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MediaPlayerProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("77a92326-0c5b-41fc-bf49-15f6c3524b6b")) __declspec(novtable) IMediaPlayerPresenter : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MediaPlayer(Windows::Media::Playback::IMediaPlayer ** value) = 0;
    virtual HRESULT __stdcall put_MediaPlayer(Windows::Media::Playback::IMediaPlayer * value) = 0;
    virtual HRESULT __stdcall get_Stretch(winrt::Windows::UI::Xaml::Media::Stretch * value) = 0;
    virtual HRESULT __stdcall put_Stretch(winrt::Windows::UI::Xaml::Media::Stretch value) = 0;
    virtual HRESULT __stdcall get_IsFullWindow(bool * value) = 0;
    virtual HRESULT __stdcall put_IsFullWindow(bool value) = 0;
};

struct __declspec(uuid("e6766fb7-d96f-4b95-b33c-59e81cb1e9ba")) __declspec(novtable) IMediaPlayerPresenterFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IMediaPlayerPresenter ** instance) = 0;
};

struct __declspec(uuid("84d774fe-ead4-4957-b42b-223158ca0de7")) __declspec(novtable) IMediaPlayerPresenterStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MediaPlayerProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_StretchProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsFullWindowProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("d6f69e7d-0825-49a9-9fce-5586d8694f0c")) __declspec(novtable) IMediaTransportControls : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsFullWindowButtonVisible(bool * value) = 0;
    virtual HRESULT __stdcall put_IsFullWindowButtonVisible(bool value) = 0;
    virtual HRESULT __stdcall get_IsFullWindowEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsFullWindowEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsZoomButtonVisible(bool * value) = 0;
    virtual HRESULT __stdcall put_IsZoomButtonVisible(bool value) = 0;
    virtual HRESULT __stdcall get_IsZoomEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsZoomEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsFastForwardButtonVisible(bool * value) = 0;
    virtual HRESULT __stdcall put_IsFastForwardButtonVisible(bool value) = 0;
    virtual HRESULT __stdcall get_IsFastForwardEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsFastForwardEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsFastRewindButtonVisible(bool * value) = 0;
    virtual HRESULT __stdcall put_IsFastRewindButtonVisible(bool value) = 0;
    virtual HRESULT __stdcall get_IsFastRewindEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsFastRewindEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsStopButtonVisible(bool * value) = 0;
    virtual HRESULT __stdcall put_IsStopButtonVisible(bool value) = 0;
    virtual HRESULT __stdcall get_IsStopEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsStopEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsVolumeButtonVisible(bool * value) = 0;
    virtual HRESULT __stdcall put_IsVolumeButtonVisible(bool value) = 0;
    virtual HRESULT __stdcall get_IsVolumeEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsVolumeEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsPlaybackRateButtonVisible(bool * value) = 0;
    virtual HRESULT __stdcall put_IsPlaybackRateButtonVisible(bool value) = 0;
    virtual HRESULT __stdcall get_IsPlaybackRateEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsPlaybackRateEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsSeekBarVisible(bool * value) = 0;
    virtual HRESULT __stdcall put_IsSeekBarVisible(bool value) = 0;
    virtual HRESULT __stdcall get_IsSeekEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsSeekEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsCompact(bool * value) = 0;
    virtual HRESULT __stdcall put_IsCompact(bool value) = 0;
};

struct __declspec(uuid("2b89efec-1bea-451e-8bcd-cfe2d9423262")) __declspec(novtable) IMediaTransportControls2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsSkipForwardButtonVisible(bool * value) = 0;
    virtual HRESULT __stdcall put_IsSkipForwardButtonVisible(bool value) = 0;
    virtual HRESULT __stdcall get_IsSkipForwardEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsSkipForwardEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsSkipBackwardButtonVisible(bool * value) = 0;
    virtual HRESULT __stdcall put_IsSkipBackwardButtonVisible(bool value) = 0;
    virtual HRESULT __stdcall get_IsSkipBackwardEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsSkipBackwardEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsNextTrackButtonVisible(bool * value) = 0;
    virtual HRESULT __stdcall put_IsNextTrackButtonVisible(bool value) = 0;
    virtual HRESULT __stdcall get_IsPreviousTrackButtonVisible(bool * value) = 0;
    virtual HRESULT __stdcall put_IsPreviousTrackButtonVisible(bool value) = 0;
    virtual HRESULT __stdcall get_FastPlayFallbackBehaviour(winrt::Windows::UI::Xaml::Media::FastPlayFallbackBehaviour * value) = 0;
    virtual HRESULT __stdcall put_FastPlayFallbackBehaviour(winrt::Windows::UI::Xaml::Media::FastPlayFallbackBehaviour value) = 0;
    virtual HRESULT __stdcall add_ThumbnailRequested(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::MediaTransportControls, Windows::UI::Xaml::Media::MediaTransportControlsThumbnailRequestedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ThumbnailRequested(event_token token) = 0;
};

struct __declspec(uuid("1da2015a-a8e4-4c1b-88c9-0b183ecc62e3")) __declspec(novtable) IMediaTransportControlsFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IMediaTransportControls ** instance) = 0;
};

struct __declspec(uuid("3d41d509-ff44-4420-807e-8f7a2e2c4251")) __declspec(novtable) IMediaTransportControlsHelper : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("5a772047-a9a1-4625-9270-7f49875d4394")) __declspec(novtable) IMediaTransportControlsHelperStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DropoutOrderProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetDropoutOrder(Windows::UI::Xaml::IUIElement * element, Windows::Foundation::IReference<int32_t> ** value) = 0;
    virtual HRESULT __stdcall abi_SetDropoutOrder(Windows::UI::Xaml::IUIElement * element, Windows::Foundation::IReference<int32_t> * value) = 0;
};

struct __declspec(uuid("590ea907-d2ef-4c1a-9429-b4b15d64fd56")) __declspec(novtable) IMediaTransportControlsStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsFullWindowButtonVisibleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsFullWindowEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsZoomButtonVisibleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsZoomEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsFastForwardButtonVisibleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsFastForwardEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsFastRewindButtonVisibleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsFastRewindEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsStopButtonVisibleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsStopEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsVolumeButtonVisibleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsVolumeEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsPlaybackRateButtonVisibleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsPlaybackRateEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsSeekBarVisibleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsSeekEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsCompactProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("1728cfdc-561f-4386-a7f8-090d95f68d96")) __declspec(novtable) IMediaTransportControlsStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsSkipForwardButtonVisibleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsSkipForwardEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsSkipBackwardButtonVisibleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsSkipBackwardEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsNextTrackButtonVisibleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsPreviousTrackButtonVisibleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FastPlayFallbackBehaviourProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("ad3210f1-985b-4171-bbba-67bcc729649b")) __declspec(novtable) IMenuFlyout : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Items(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::MenuFlyoutItemBase> ** value) = 0;
    virtual HRESULT __stdcall get_MenuFlyoutPresenterStyle(Windows::UI::Xaml::IStyle ** value) = 0;
    virtual HRESULT __stdcall put_MenuFlyoutPresenterStyle(Windows::UI::Xaml::IStyle * value) = 0;
};

struct __declspec(uuid("507c7bad-d9d1-4c05-9d4b-cda8de9ab242")) __declspec(novtable) IMenuFlyout2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ShowAt(Windows::UI::Xaml::IUIElement * targetElement, Windows::Foundation::Point point) = 0;
};

struct __declspec(uuid("644533ab-bbb9-499b-9ff3-30d40e2c56d8")) __declspec(novtable) IMenuFlyoutFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IMenuFlyout ** instance) = 0;
};

struct __declspec(uuid("160775cf-b598-44af-a488-c3ce2af6d3f0")) __declspec(novtable) IMenuFlyoutItem : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Text(hstring * value) = 0;
    virtual HRESULT __stdcall put_Text(hstring value) = 0;
    virtual HRESULT __stdcall get_Command(Windows::UI::Xaml::Input::ICommand ** value) = 0;
    virtual HRESULT __stdcall put_Command(Windows::UI::Xaml::Input::ICommand * value) = 0;
    virtual HRESULT __stdcall get_CommandParameter(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_CommandParameter(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall add_Click(Windows::UI::Xaml::RoutedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Click(event_token token) = 0;
};

struct __declspec(uuid("f9b56047-8da6-4730-9208-144125c6b396")) __declspec(novtable) IMenuFlyoutItemBase : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("83e6dbad-fc67-41d5-8797-60acd1ceb1d9")) __declspec(novtable) IMenuFlyoutItemBaseFactory : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("c5aa39e2-44f3-455e-9c5b-62bb6afce3ad")) __declspec(novtable) IMenuFlyoutItemFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IMenuFlyoutItem ** instance) = 0;
};

struct __declspec(uuid("4950b424-a43a-41f7-aa3a-9ce9619747d5")) __declspec(novtable) IMenuFlyoutItemStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TextProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CommandProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CommandParameterProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("906e0304-254e-413f-b219-c7b97f003752")) __declspec(novtable) IMenuFlyoutPresenter : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("895894df-5a9f-4a1f-85ec-6f3c1b6dcb89")) __declspec(novtable) IMenuFlyoutPresenter2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TemplateSettings(Windows::UI::Xaml::Controls::Primitives::IMenuFlyoutPresenterTemplateSettings ** value) = 0;
};

struct __declspec(uuid("b88b5091-101c-41f8-aac1-1b105c14fb99")) __declspec(novtable) IMenuFlyoutPresenterFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IMenuFlyoutPresenter ** instance) = 0;
};

struct __declspec(uuid("71fa2b7d-0b51-4950-a1a4-bbc42eac4c12")) __declspec(novtable) IMenuFlyoutSeparator : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("c159dcc8-b437-44e0-b24b-5720aea1dbac")) __declspec(novtable) IMenuFlyoutSeparatorFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IMenuFlyoutSeparator ** instance) = 0;
};

struct __declspec(uuid("3dbefba1-9522-4045-9e58-c99b13aab9b9")) __declspec(novtable) IMenuFlyoutStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MenuFlyoutPresenterStyleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("e5386550-fe2c-43e2-a73f-62168f619973")) __declspec(novtable) IMenuFlyoutSubItem : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Items(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::MenuFlyoutItemBase> ** value) = 0;
    virtual HRESULT __stdcall get_Text(hstring * value) = 0;
    virtual HRESULT __stdcall put_Text(hstring value) = 0;
};

struct __declspec(uuid("ddb27a36-1874-4aef-837d-6fec9da4e681")) __declspec(novtable) IMenuFlyoutSubItemStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TextProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("bf2195a9-f4ea-4336-977c-f8fcf78b0d9e")) __declspec(novtable) INavigate : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Navigate(Windows::UI::Xaml::Interop::TypeName sourcePageType, bool * returnValue) = 0;
};

struct __declspec(uuid("af0e05f7-c4b7-44c5-b09d-5cb7052b3a97")) __declspec(novtable) INotifyEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Value(hstring * value) = 0;
};

struct __declspec(uuid("0d140f56-1dce-4fcd-85bc-5a5572273b9c")) __declspec(novtable) INotifyEventArgs2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CallingUri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
};

struct __declspec(uuid("c4b27075-e641-453e-824d-012fc7cf95cf")) __declspec(novtable) IPage : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Frame(Windows::UI::Xaml::Controls::IFrame ** value) = 0;
    virtual HRESULT __stdcall get_NavigationCacheMode(winrt::Windows::UI::Xaml::Navigation::NavigationCacheMode * value) = 0;
    virtual HRESULT __stdcall put_NavigationCacheMode(winrt::Windows::UI::Xaml::Navigation::NavigationCacheMode value) = 0;
    virtual HRESULT __stdcall get_TopAppBar(Windows::UI::Xaml::Controls::IAppBar ** value) = 0;
    virtual HRESULT __stdcall put_TopAppBar(Windows::UI::Xaml::Controls::IAppBar * value) = 0;
    virtual HRESULT __stdcall get_BottomAppBar(Windows::UI::Xaml::Controls::IAppBar ** value) = 0;
    virtual HRESULT __stdcall put_BottomAppBar(Windows::UI::Xaml::Controls::IAppBar * value) = 0;
};

struct __declspec(uuid("dfa149ac-1849-445e-937c-40a9590cc076")) __declspec(novtable) IPageFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IPage ** instance) = 0;
};

struct __declspec(uuid("230b9cb8-3419-4306-aabe-4a8e680d3627")) __declspec(novtable) IPageOverrides : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_OnNavigatedFrom(Windows::UI::Xaml::Navigation::INavigationEventArgs * e) = 0;
    virtual HRESULT __stdcall abi_OnNavigatedTo(Windows::UI::Xaml::Navigation::INavigationEventArgs * e) = 0;
    virtual HRESULT __stdcall abi_OnNavigatingFrom(Windows::UI::Xaml::Navigation::INavigatingCancelEventArgs * e) = 0;
};

struct __declspec(uuid("376dde71-f725-46dd-8d80-eeeaf7da74e5")) __declspec(novtable) IPageStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FrameProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TopAppBarProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_BottomAppBarProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("a50a4bbd-8361-469c-90da-e9a40c7474df")) __declspec(novtable) IPanel : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Children(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::UIElement> ** value) = 0;
    virtual HRESULT __stdcall get_Background(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall put_Background(Windows::UI::Xaml::Media::IBrush * value) = 0;
    virtual HRESULT __stdcall get_IsItemsHost(bool * value) = 0;
    virtual HRESULT __stdcall get_ChildrenTransitions(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Animation::Transition> ** value) = 0;
    virtual HRESULT __stdcall put_ChildrenTransitions(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Animation::Transition> * value) = 0;
};

struct __declspec(uuid("eee68111-c7cc-433f-95cd-d630c34302dd")) __declspec(novtable) IPanelFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IPanel ** instance) = 0;
};

struct __declspec(uuid("f23d6b5d-8330-47a6-a046-25f509b25232")) __declspec(novtable) IPanelStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_BackgroundProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsItemsHostProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ChildrenTransitionsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("02b9aa11-0b47-4e7d-ad91-3a4168ed230d")) __declspec(novtable) IPasswordBox : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Password(hstring * value) = 0;
    virtual HRESULT __stdcall put_Password(hstring value) = 0;
    virtual HRESULT __stdcall get_PasswordChar(hstring * value) = 0;
    virtual HRESULT __stdcall put_PasswordChar(hstring value) = 0;
    virtual HRESULT __stdcall get_IsPasswordRevealButtonEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsPasswordRevealButtonEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_MaxLength(int32_t * value) = 0;
    virtual HRESULT __stdcall put_MaxLength(int32_t value) = 0;
    virtual HRESULT __stdcall add_PasswordChanged(Windows::UI::Xaml::RoutedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PasswordChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_ContextMenuOpening(Windows::UI::Xaml::Controls::ContextMenuOpeningEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ContextMenuOpening(event_token token) = 0;
    virtual HRESULT __stdcall abi_SelectAll() = 0;
};

struct __declspec(uuid("5ed738df-212f-4aeb-b5b8-2c219aec3c0c")) __declspec(novtable) IPasswordBox2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Header(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_Header(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_HeaderTemplate(Windows::UI::Xaml::IDataTemplate ** value) = 0;
    virtual HRESULT __stdcall put_HeaderTemplate(Windows::UI::Xaml::IDataTemplate * value) = 0;
    virtual HRESULT __stdcall get_PlaceholderText(hstring * value) = 0;
    virtual HRESULT __stdcall put_PlaceholderText(hstring value) = 0;
    virtual HRESULT __stdcall get_SelectionHighlightColor(Windows::UI::Xaml::Media::ISolidColorBrush ** value) = 0;
    virtual HRESULT __stdcall put_SelectionHighlightColor(Windows::UI::Xaml::Media::ISolidColorBrush * value) = 0;
    virtual HRESULT __stdcall get_PreventKeyboardDisplayOnProgrammaticFocus(bool * value) = 0;
    virtual HRESULT __stdcall put_PreventKeyboardDisplayOnProgrammaticFocus(bool value) = 0;
    virtual HRESULT __stdcall add_Paste(Windows::UI::Xaml::Controls::TextControlPasteEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Paste(event_token token) = 0;
};

struct __declspec(uuid("6024d9d1-56b7-41f0-9558-3934c14244d6")) __declspec(novtable) IPasswordBox3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PasswordRevealMode(winrt::Windows::UI::Xaml::Controls::PasswordRevealMode * value) = 0;
    virtual HRESULT __stdcall put_PasswordRevealMode(winrt::Windows::UI::Xaml::Controls::PasswordRevealMode value) = 0;
    virtual HRESULT __stdcall get_TextReadingOrder(winrt::Windows::UI::Xaml::TextReadingOrder * value) = 0;
    virtual HRESULT __stdcall put_TextReadingOrder(winrt::Windows::UI::Xaml::TextReadingOrder value) = 0;
    virtual HRESULT __stdcall get_InputScope(Windows::UI::Xaml::Input::IInputScope ** value) = 0;
    virtual HRESULT __stdcall put_InputScope(Windows::UI::Xaml::Input::IInputScope * value) = 0;
};

struct __declspec(uuid("5ee67563-2d74-4ace-bd79-fcab61a7d77b")) __declspec(novtable) IPasswordBoxStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PasswordProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PasswordCharProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsPasswordRevealButtonEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MaxLengthProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("fc57935f-98fa-4066-b785-fa725ecde232")) __declspec(novtable) IPasswordBoxStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_HeaderProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_HeaderTemplateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PlaceholderTextProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SelectionHighlightColorProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PreventKeyboardDisplayOnProgrammaticFocusProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("a2cdd319-ad6a-4352-b590-f696ffcb8e3f")) __declspec(novtable) IPasswordBoxStatics3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PasswordRevealModeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TextReadingOrderProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_InputScopeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("214c62db-c366-4a0e-b9ad-dcf168d7ec0c")) __declspec(novtable) IPathIcon : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Data(Windows::UI::Xaml::Media::IGeometry ** value) = 0;
    virtual HRESULT __stdcall put_Data(Windows::UI::Xaml::Media::IGeometry * value) = 0;
};

struct __declspec(uuid("af9d9652-9c5d-4a37-9e1a-044abeef792b")) __declspec(novtable) IPathIconFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IPathIcon ** instance) = 0;
};

struct __declspec(uuid("77b75db8-fb15-491a-b6e3-7dbba911bafe")) __declspec(novtable) IPathIconStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DataProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("447a9b51-1e23-4779-992b-986849713941")) __declspec(novtable) IPickerConfirmedEventArgs : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("a336ffdb-08d9-43e6-944e-f2e5c7cee630")) __declspec(novtable) IPickerFlyout : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Content(Windows::UI::Xaml::IUIElement ** value) = 0;
    virtual HRESULT __stdcall put_Content(Windows::UI::Xaml::IUIElement * value) = 0;
    virtual HRESULT __stdcall get_ConfirmationButtonsVisible(bool * value) = 0;
    virtual HRESULT __stdcall put_ConfirmationButtonsVisible(bool value) = 0;
    virtual HRESULT __stdcall add_Confirmed(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::PickerFlyout, Windows::UI::Xaml::Controls::PickerConfirmedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Confirmed(event_token token) = 0;
    virtual HRESULT __stdcall abi_ShowAtAsync(Windows::UI::Xaml::IFrameworkElement * target, Windows::Foundation::IAsyncOperation<bool> ** returnValue) = 0;
};

struct __declspec(uuid("5884c978-6b27-4b38-a9ae-677c2994652e")) __declspec(novtable) IPickerFlyoutPresenter : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("af18a436-f38a-4abd-b933-6286c115b07f")) __declspec(novtable) IPickerFlyoutStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ContentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ConfirmationButtonsVisibleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("103e9b13-3400-4a16-90b9-6912bf06974e")) __declspec(novtable) IPivot : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Title(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_Title(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_TitleTemplate(Windows::UI::Xaml::IDataTemplate ** value) = 0;
    virtual HRESULT __stdcall put_TitleTemplate(Windows::UI::Xaml::IDataTemplate * value) = 0;
    virtual HRESULT __stdcall get_HeaderTemplate(Windows::UI::Xaml::IDataTemplate ** value) = 0;
    virtual HRESULT __stdcall put_HeaderTemplate(Windows::UI::Xaml::IDataTemplate * value) = 0;
    virtual HRESULT __stdcall get_SelectedIndex(int32_t * value) = 0;
    virtual HRESULT __stdcall put_SelectedIndex(int32_t value) = 0;
    virtual HRESULT __stdcall get_SelectedItem(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_SelectedItem(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_IsLocked(bool * value) = 0;
    virtual HRESULT __stdcall put_IsLocked(bool value) = 0;
    virtual HRESULT __stdcall add_SelectionChanged(Windows::UI::Xaml::Controls::SelectionChangedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SelectionChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_PivotItemLoading(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Pivot, Windows::UI::Xaml::Controls::PivotItemEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PivotItemLoading(event_token token) = 0;
    virtual HRESULT __stdcall add_PivotItemLoaded(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Pivot, Windows::UI::Xaml::Controls::PivotItemEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PivotItemLoaded(event_token token) = 0;
    virtual HRESULT __stdcall add_PivotItemUnloading(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Pivot, Windows::UI::Xaml::Controls::PivotItemEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PivotItemUnloading(event_token token) = 0;
    virtual HRESULT __stdcall add_PivotItemUnloaded(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Pivot, Windows::UI::Xaml::Controls::PivotItemEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PivotItemUnloaded(event_token token) = 0;
};

struct __declspec(uuid("8b8a8660-1a55-411c-a82d-18991c3f0d6f")) __declspec(novtable) IPivot2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LeftHeader(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_LeftHeader(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_LeftHeaderTemplate(Windows::UI::Xaml::IDataTemplate ** value) = 0;
    virtual HRESULT __stdcall put_LeftHeaderTemplate(Windows::UI::Xaml::IDataTemplate * value) = 0;
    virtual HRESULT __stdcall get_RightHeader(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_RightHeader(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_RightHeaderTemplate(Windows::UI::Xaml::IDataTemplate ** value) = 0;
    virtual HRESULT __stdcall put_RightHeaderTemplate(Windows::UI::Xaml::IDataTemplate * value) = 0;
};

struct __declspec(uuid("95bcbf96-f0da-4089-8c65-e8b81354c766")) __declspec(novtable) IPivot3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_HeaderFocusVisualPlacement(winrt::Windows::UI::Xaml::Controls::PivotHeaderFocusVisualPlacement * value) = 0;
    virtual HRESULT __stdcall put_HeaderFocusVisualPlacement(winrt::Windows::UI::Xaml::Controls::PivotHeaderFocusVisualPlacement value) = 0;
    virtual HRESULT __stdcall get_IsHeaderItemsCarouselEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsHeaderItemsCarouselEnabled(bool value) = 0;
};

struct __declspec(uuid("1b0a818e-2529-4762-ba44-9abc68c3ceca")) __declspec(novtable) IPivotFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IPivot ** instance) = 0;
};

struct __declspec(uuid("a4764371-a502-47a3-915e-4aa096daf87f")) __declspec(novtable) IPivotItem : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Header(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_Header(Windows::Foundation::IInspectable * value) = 0;
};

struct __declspec(uuid("1a6f7254-1ed5-4bc5-a060-655530bca6ba")) __declspec(novtable) IPivotItemEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Item(Windows::UI::Xaml::Controls::IPivotItem ** value) = 0;
    virtual HRESULT __stdcall put_Item(Windows::UI::Xaml::Controls::IPivotItem * value) = 0;
};

struct __declspec(uuid("0dced981-636e-4a34-8a3f-8ee018639285")) __declspec(novtable) IPivotItemFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IPivotItem ** instance) = 0;
};

struct __declspec(uuid("e147ad0c-488b-4a6e-becd-a5dbd9941754")) __declspec(novtable) IPivotItemStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_HeaderProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("ee22c7f4-c15d-4ff3-8a94-f50dfdfbe899")) __declspec(novtable) IPivotStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TitleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TitleTemplateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_HeaderTemplateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SelectedIndexProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SelectedItemProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsLockedProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SlideInAnimationGroupProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetSlideInAnimationGroup(Windows::UI::Xaml::IFrameworkElement * element, winrt::Windows::UI::Xaml::Controls::PivotSlideInAnimationGroup * value) = 0;
    virtual HRESULT __stdcall abi_SetSlideInAnimationGroup(Windows::UI::Xaml::IFrameworkElement * element, winrt::Windows::UI::Xaml::Controls::PivotSlideInAnimationGroup value) = 0;
};

struct __declspec(uuid("d7518add-be75-4023-8deb-c6513c3192a3")) __declspec(novtable) IPivotStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LeftHeaderProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_LeftHeaderTemplateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_RightHeaderProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_RightHeaderTemplateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("78b6274e-6616-4600-a039-922a5d09330b")) __declspec(novtable) IPivotStatics3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_HeaderFocusVisualPlacementProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsHeaderItemsCarouselEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("ae752c89-0067-4963-bf4c-29db0c4a507e")) __declspec(novtable) IProgressBar : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsIndeterminate(bool * value) = 0;
    virtual HRESULT __stdcall put_IsIndeterminate(bool value) = 0;
    virtual HRESULT __stdcall get_ShowError(bool * value) = 0;
    virtual HRESULT __stdcall put_ShowError(bool value) = 0;
    virtual HRESULT __stdcall get_ShowPaused(bool * value) = 0;
    virtual HRESULT __stdcall put_ShowPaused(bool value) = 0;
    virtual HRESULT __stdcall get_TemplateSettings(Windows::UI::Xaml::Controls::Primitives::IProgressBarTemplateSettings ** value) = 0;
};

struct __declspec(uuid("da9a8c11-1591-400b-a993-0f1c5cc12f3b")) __declspec(novtable) IProgressBarFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IProgressBar ** instance) = 0;
};

struct __declspec(uuid("7a129fda-5837-4e26-b3b4-e1c092cebbec")) __declspec(novtable) IProgressBarStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsIndeterminateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ShowErrorProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ShowPausedProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("6da5e49e-6e9d-425c-bd7c-02173e39763f")) __declspec(novtable) IProgressRing : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsActive(bool * value) = 0;
    virtual HRESULT __stdcall put_IsActive(bool value) = 0;
    virtual HRESULT __stdcall get_TemplateSettings(Windows::UI::Xaml::Controls::Primitives::IProgressRingTemplateSettings ** value) = 0;
};

struct __declspec(uuid("e8b62507-4e2c-47d5-a54a-c6c48a5e6989")) __declspec(novtable) IProgressRingStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsActiveProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("325c44e0-9a03-4bf3-abd6-6fbb46c9a486")) __declspec(novtable) IRadioButton : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_GroupName(hstring * value) = 0;
    virtual HRESULT __stdcall put_GroupName(hstring value) = 0;
};

struct __declspec(uuid("f1d04933-34e1-4a5c-b2ae-ca3b1c0b20de")) __declspec(novtable) IRadioButtonFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IRadioButton ** instance) = 0;
};

struct __declspec(uuid("6b149293-f50f-4bd8-b0ac-5c162f33a208")) __declspec(novtable) IRadioButtonStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_GroupNameProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("2eabfaeb-b35a-4035-acea-3c4a3730683f")) __declspec(novtable) IRelativePanel : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_BorderBrush(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall put_BorderBrush(Windows::UI::Xaml::Media::IBrush * value) = 0;
    virtual HRESULT __stdcall get_BorderThickness(Windows::UI::Xaml::Thickness * value) = 0;
    virtual HRESULT __stdcall put_BorderThickness(Windows::UI::Xaml::Thickness value) = 0;
    virtual HRESULT __stdcall get_CornerRadius(Windows::UI::Xaml::CornerRadius * value) = 0;
    virtual HRESULT __stdcall put_CornerRadius(Windows::UI::Xaml::CornerRadius value) = 0;
    virtual HRESULT __stdcall get_Padding(Windows::UI::Xaml::Thickness * value) = 0;
    virtual HRESULT __stdcall put_Padding(Windows::UI::Xaml::Thickness value) = 0;
};

struct __declspec(uuid("8460193c-361b-44ba-a17e-b84c9dcdc772")) __declspec(novtable) IRelativePanelFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IRelativePanel ** instance) = 0;
};

struct __declspec(uuid("15903c27-f18c-4c35-8e19-6a7459d907b6")) __declspec(novtable) IRelativePanelStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LeftOfProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetLeftOf(Windows::UI::Xaml::IUIElement * element, Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall abi_SetLeftOf(Windows::UI::Xaml::IUIElement * element, Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_AboveProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetAbove(Windows::UI::Xaml::IUIElement * element, Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall abi_SetAbove(Windows::UI::Xaml::IUIElement * element, Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_RightOfProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetRightOf(Windows::UI::Xaml::IUIElement * element, Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall abi_SetRightOf(Windows::UI::Xaml::IUIElement * element, Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_BelowProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetBelow(Windows::UI::Xaml::IUIElement * element, Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall abi_SetBelow(Windows::UI::Xaml::IUIElement * element, Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_AlignHorizontalCenterWithProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetAlignHorizontalCenterWith(Windows::UI::Xaml::IUIElement * element, Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall abi_SetAlignHorizontalCenterWith(Windows::UI::Xaml::IUIElement * element, Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_AlignVerticalCenterWithProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetAlignVerticalCenterWith(Windows::UI::Xaml::IUIElement * element, Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall abi_SetAlignVerticalCenterWith(Windows::UI::Xaml::IUIElement * element, Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_AlignLeftWithProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetAlignLeftWith(Windows::UI::Xaml::IUIElement * element, Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall abi_SetAlignLeftWith(Windows::UI::Xaml::IUIElement * element, Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_AlignTopWithProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetAlignTopWith(Windows::UI::Xaml::IUIElement * element, Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall abi_SetAlignTopWith(Windows::UI::Xaml::IUIElement * element, Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_AlignRightWithProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetAlignRightWith(Windows::UI::Xaml::IUIElement * element, Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall abi_SetAlignRightWith(Windows::UI::Xaml::IUIElement * element, Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_AlignBottomWithProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetAlignBottomWith(Windows::UI::Xaml::IUIElement * element, Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall abi_SetAlignBottomWith(Windows::UI::Xaml::IUIElement * element, Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_AlignLeftWithPanelProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetAlignLeftWithPanel(Windows::UI::Xaml::IUIElement * element, bool * value) = 0;
    virtual HRESULT __stdcall abi_SetAlignLeftWithPanel(Windows::UI::Xaml::IUIElement * element, bool value) = 0;
    virtual HRESULT __stdcall get_AlignTopWithPanelProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetAlignTopWithPanel(Windows::UI::Xaml::IUIElement * element, bool * value) = 0;
    virtual HRESULT __stdcall abi_SetAlignTopWithPanel(Windows::UI::Xaml::IUIElement * element, bool value) = 0;
    virtual HRESULT __stdcall get_AlignRightWithPanelProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetAlignRightWithPanel(Windows::UI::Xaml::IUIElement * element, bool * value) = 0;
    virtual HRESULT __stdcall abi_SetAlignRightWithPanel(Windows::UI::Xaml::IUIElement * element, bool value) = 0;
    virtual HRESULT __stdcall get_AlignBottomWithPanelProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetAlignBottomWithPanel(Windows::UI::Xaml::IUIElement * element, bool * value) = 0;
    virtual HRESULT __stdcall abi_SetAlignBottomWithPanel(Windows::UI::Xaml::IUIElement * element, bool value) = 0;
    virtual HRESULT __stdcall get_AlignHorizontalCenterWithPanelProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetAlignHorizontalCenterWithPanel(Windows::UI::Xaml::IUIElement * element, bool * value) = 0;
    virtual HRESULT __stdcall abi_SetAlignHorizontalCenterWithPanel(Windows::UI::Xaml::IUIElement * element, bool value) = 0;
    virtual HRESULT __stdcall get_AlignVerticalCenterWithPanelProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetAlignVerticalCenterWithPanel(Windows::UI::Xaml::IUIElement * element, bool * value) = 0;
    virtual HRESULT __stdcall abi_SetAlignVerticalCenterWithPanel(Windows::UI::Xaml::IUIElement * element, bool value) = 0;
    virtual HRESULT __stdcall get_BorderBrushProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_BorderThicknessProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CornerRadiusProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PaddingProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("90a57a40-80b6-4fce-b1ec-e3c616284b6a")) __declspec(novtable) IRichEditBox : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsReadOnly(bool * value) = 0;
    virtual HRESULT __stdcall put_IsReadOnly(bool value) = 0;
    virtual HRESULT __stdcall get_AcceptsReturn(bool * value) = 0;
    virtual HRESULT __stdcall put_AcceptsReturn(bool value) = 0;
    virtual HRESULT __stdcall get_TextAlignment(winrt::Windows::UI::Xaml::TextAlignment * value) = 0;
    virtual HRESULT __stdcall put_TextAlignment(winrt::Windows::UI::Xaml::TextAlignment value) = 0;
    virtual HRESULT __stdcall get_TextWrapping(winrt::Windows::UI::Xaml::TextWrapping * value) = 0;
    virtual HRESULT __stdcall put_TextWrapping(winrt::Windows::UI::Xaml::TextWrapping value) = 0;
    virtual HRESULT __stdcall get_IsSpellCheckEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsSpellCheckEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsTextPredictionEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsTextPredictionEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_Document(Windows::UI::Text::ITextDocument ** value) = 0;
    virtual HRESULT __stdcall get_InputScope(Windows::UI::Xaml::Input::IInputScope ** value) = 0;
    virtual HRESULT __stdcall put_InputScope(Windows::UI::Xaml::Input::IInputScope * value) = 0;
    virtual HRESULT __stdcall add_TextChanged(Windows::UI::Xaml::RoutedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_TextChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_SelectionChanged(Windows::UI::Xaml::RoutedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SelectionChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_ContextMenuOpening(Windows::UI::Xaml::Controls::ContextMenuOpeningEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ContextMenuOpening(event_token token) = 0;
};

struct __declspec(uuid("bbea6ead-e805-47a4-bbe7-47e59b8f74a7")) __declspec(novtable) IRichEditBox2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Header(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_Header(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_HeaderTemplate(Windows::UI::Xaml::IDataTemplate ** value) = 0;
    virtual HRESULT __stdcall put_HeaderTemplate(Windows::UI::Xaml::IDataTemplate * value) = 0;
    virtual HRESULT __stdcall get_PlaceholderText(hstring * value) = 0;
    virtual HRESULT __stdcall put_PlaceholderText(hstring value) = 0;
    virtual HRESULT __stdcall get_SelectionHighlightColor(Windows::UI::Xaml::Media::ISolidColorBrush ** value) = 0;
    virtual HRESULT __stdcall put_SelectionHighlightColor(Windows::UI::Xaml::Media::ISolidColorBrush * value) = 0;
    virtual HRESULT __stdcall get_PreventKeyboardDisplayOnProgrammaticFocus(bool * value) = 0;
    virtual HRESULT __stdcall put_PreventKeyboardDisplayOnProgrammaticFocus(bool value) = 0;
    virtual HRESULT __stdcall get_IsColorFontEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsColorFontEnabled(bool value) = 0;
    virtual HRESULT __stdcall add_Paste(Windows::UI::Xaml::Controls::TextControlPasteEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Paste(event_token token) = 0;
};

struct __declspec(uuid("6b17a462-fbb6-4fff-9991-9399cb9c0b90")) __declspec(novtable) IRichEditBox3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_TextCompositionStarted(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::RichEditBox, Windows::UI::Xaml::Controls::TextCompositionStartedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_TextCompositionStarted(event_token token) = 0;
    virtual HRESULT __stdcall add_TextCompositionChanged(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::RichEditBox, Windows::UI::Xaml::Controls::TextCompositionChangedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_TextCompositionChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_TextCompositionEnded(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::RichEditBox, Windows::UI::Xaml::Controls::TextCompositionEndedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_TextCompositionEnded(event_token token) = 0;
    virtual HRESULT __stdcall get_TextReadingOrder(winrt::Windows::UI::Xaml::TextReadingOrder * value) = 0;
    virtual HRESULT __stdcall put_TextReadingOrder(winrt::Windows::UI::Xaml::TextReadingOrder value) = 0;
    virtual HRESULT __stdcall get_DesiredCandidateWindowAlignment(winrt::Windows::UI::Xaml::Controls::CandidateWindowAlignment * value) = 0;
    virtual HRESULT __stdcall put_DesiredCandidateWindowAlignment(winrt::Windows::UI::Xaml::Controls::CandidateWindowAlignment value) = 0;
    virtual HRESULT __stdcall add_CandidateWindowBoundsChanged(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::RichEditBox, Windows::UI::Xaml::Controls::CandidateWindowBoundsChangedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_CandidateWindowBoundsChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_TextChanging(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::RichEditBox, Windows::UI::Xaml::Controls::RichEditBoxTextChangingEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_TextChanging(event_token token) = 0;
};

struct __declspec(uuid("5caa8d35-c838-4bad-a07c-204183bb751f")) __declspec(novtable) IRichEditBox4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetLinguisticAlternativesAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<hstring>> ** returnValue) = 0;
    virtual HRESULT __stdcall get_ClipboardCopyFormat(winrt::Windows::UI::Xaml::Controls::RichEditClipboardFormat * value) = 0;
    virtual HRESULT __stdcall put_ClipboardCopyFormat(winrt::Windows::UI::Xaml::Controls::RichEditClipboardFormat value) = 0;
};

struct __declspec(uuid("61a1df62-2806-41ed-88ed-ae21f47ab422")) __declspec(novtable) IRichEditBoxFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IRichEditBox ** instance) = 0;
};

struct __declspec(uuid("f5e03a74-88ea-479b-9a05-37089ff30ede")) __declspec(novtable) IRichEditBoxStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsReadOnlyProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_AcceptsReturnProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TextAlignmentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TextWrappingProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsSpellCheckEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsTextPredictionEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_InputScopeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("e3eb26de-2748-420b-b1fc-ce95b6e85eec")) __declspec(novtable) IRichEditBoxStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_HeaderProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_HeaderTemplateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PlaceholderTextProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SelectionHighlightColorProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PreventKeyboardDisplayOnProgrammaticFocusProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsColorFontEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("6d17eec5-1fb3-4c8b-aa23-f5e15d6ab64e")) __declspec(novtable) IRichEditBoxStatics3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DesiredCandidateWindowAlignmentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TextReadingOrderProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("f5d54fd7-7796-42a5-a5e5-2cd211ee8176")) __declspec(novtable) IRichEditBoxStatics4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ClipboardCopyFormatProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("54065018-2813-4922-9f8e-b6bbafd995d8")) __declspec(novtable) IRichEditBoxTextChangingEventArgs : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("e5fff9e2-b968-49e7-97d4-8cca2ac3ae7c")) __declspec(novtable) IRichTextBlock : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FontSize(double * value) = 0;
    virtual HRESULT __stdcall put_FontSize(double value) = 0;
    virtual HRESULT __stdcall get_FontFamily(Windows::UI::Xaml::Media::IFontFamily ** value) = 0;
    virtual HRESULT __stdcall put_FontFamily(Windows::UI::Xaml::Media::IFontFamily * value) = 0;
    virtual HRESULT __stdcall get_FontWeight(Windows::UI::Text::FontWeight * value) = 0;
    virtual HRESULT __stdcall put_FontWeight(Windows::UI::Text::FontWeight value) = 0;
    virtual HRESULT __stdcall get_FontStyle(winrt::Windows::UI::Text::FontStyle * value) = 0;
    virtual HRESULT __stdcall put_FontStyle(winrt::Windows::UI::Text::FontStyle value) = 0;
    virtual HRESULT __stdcall get_FontStretch(winrt::Windows::UI::Text::FontStretch * value) = 0;
    virtual HRESULT __stdcall put_FontStretch(winrt::Windows::UI::Text::FontStretch value) = 0;
    virtual HRESULT __stdcall get_Foreground(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall put_Foreground(Windows::UI::Xaml::Media::IBrush * value) = 0;
    virtual HRESULT __stdcall get_TextWrapping(winrt::Windows::UI::Xaml::TextWrapping * value) = 0;
    virtual HRESULT __stdcall put_TextWrapping(winrt::Windows::UI::Xaml::TextWrapping value) = 0;
    virtual HRESULT __stdcall get_TextTrimming(winrt::Windows::UI::Xaml::TextTrimming * value) = 0;
    virtual HRESULT __stdcall put_TextTrimming(winrt::Windows::UI::Xaml::TextTrimming value) = 0;
    virtual HRESULT __stdcall get_TextAlignment(winrt::Windows::UI::Xaml::TextAlignment * value) = 0;
    virtual HRESULT __stdcall put_TextAlignment(winrt::Windows::UI::Xaml::TextAlignment value) = 0;
    virtual HRESULT __stdcall get_Blocks(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Documents::Block> ** value) = 0;
    virtual HRESULT __stdcall get_Padding(Windows::UI::Xaml::Thickness * value) = 0;
    virtual HRESULT __stdcall put_Padding(Windows::UI::Xaml::Thickness value) = 0;
    virtual HRESULT __stdcall get_LineHeight(double * value) = 0;
    virtual HRESULT __stdcall put_LineHeight(double value) = 0;
    virtual HRESULT __stdcall get_LineStackingStrategy(winrt::Windows::UI::Xaml::LineStackingStrategy * value) = 0;
    virtual HRESULT __stdcall put_LineStackingStrategy(winrt::Windows::UI::Xaml::LineStackingStrategy value) = 0;
    virtual HRESULT __stdcall get_CharacterSpacing(int32_t * value) = 0;
    virtual HRESULT __stdcall put_CharacterSpacing(int32_t value) = 0;
    virtual HRESULT __stdcall get_OverflowContentTarget(Windows::UI::Xaml::Controls::IRichTextBlockOverflow ** value) = 0;
    virtual HRESULT __stdcall put_OverflowContentTarget(Windows::UI::Xaml::Controls::IRichTextBlockOverflow * value) = 0;
    virtual HRESULT __stdcall get_IsTextSelectionEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsTextSelectionEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_HasOverflowContent(bool * value) = 0;
    virtual HRESULT __stdcall get_SelectedText(hstring * value) = 0;
    virtual HRESULT __stdcall get_ContentStart(Windows::UI::Xaml::Documents::ITextPointer ** value) = 0;
    virtual HRESULT __stdcall get_ContentEnd(Windows::UI::Xaml::Documents::ITextPointer ** value) = 0;
    virtual HRESULT __stdcall get_SelectionStart(Windows::UI::Xaml::Documents::ITextPointer ** value) = 0;
    virtual HRESULT __stdcall get_SelectionEnd(Windows::UI::Xaml::Documents::ITextPointer ** value) = 0;
    virtual HRESULT __stdcall get_BaselineOffset(double * value) = 0;
    virtual HRESULT __stdcall add_SelectionChanged(Windows::UI::Xaml::RoutedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SelectionChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_ContextMenuOpening(Windows::UI::Xaml::Controls::ContextMenuOpeningEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ContextMenuOpening(event_token token) = 0;
    virtual HRESULT __stdcall abi_SelectAll() = 0;
    virtual HRESULT __stdcall abi_Select(Windows::UI::Xaml::Documents::ITextPointer * start, Windows::UI::Xaml::Documents::ITextPointer * end) = 0;
    virtual HRESULT __stdcall abi_GetPositionFromPoint(Windows::Foundation::Point point, Windows::UI::Xaml::Documents::ITextPointer ** returnValue) = 0;
    virtual HRESULT __stdcall abi_Focus(winrt::Windows::UI::Xaml::FocusState value, bool * returnValue) = 0;
    virtual HRESULT __stdcall get_TextIndent(double * value) = 0;
    virtual HRESULT __stdcall put_TextIndent(double value) = 0;
};

struct __declspec(uuid("3f209013-03e7-4508-964a-91aedab3d11e")) __declspec(novtable) IRichTextBlock2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MaxLines(int32_t * value) = 0;
    virtual HRESULT __stdcall put_MaxLines(int32_t value) = 0;
    virtual HRESULT __stdcall get_TextLineBounds(winrt::Windows::UI::Xaml::TextLineBounds * value) = 0;
    virtual HRESULT __stdcall put_TextLineBounds(winrt::Windows::UI::Xaml::TextLineBounds value) = 0;
    virtual HRESULT __stdcall get_SelectionHighlightColor(Windows::UI::Xaml::Media::ISolidColorBrush ** value) = 0;
    virtual HRESULT __stdcall put_SelectionHighlightColor(Windows::UI::Xaml::Media::ISolidColorBrush * value) = 0;
    virtual HRESULT __stdcall get_OpticalMarginAlignment(winrt::Windows::UI::Xaml::OpticalMarginAlignment * value) = 0;
    virtual HRESULT __stdcall put_OpticalMarginAlignment(winrt::Windows::UI::Xaml::OpticalMarginAlignment value) = 0;
    virtual HRESULT __stdcall get_IsColorFontEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsColorFontEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_TextReadingOrder(winrt::Windows::UI::Xaml::TextReadingOrder * value) = 0;
    virtual HRESULT __stdcall put_TextReadingOrder(winrt::Windows::UI::Xaml::TextReadingOrder value) = 0;
};

struct __declspec(uuid("7d39ae83-8918-4613-b007-7c898ba2950e")) __declspec(novtable) IRichTextBlock3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsTextScaleFactorEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsTextScaleFactorEnabled(bool value) = 0;
};

struct __declspec(uuid("4f93749b-dac3-4a42-9cbb-99f0de37c071")) __declspec(novtable) IRichTextBlockOverflow : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_OverflowContentTarget(Windows::UI::Xaml::Controls::IRichTextBlockOverflow ** value) = 0;
    virtual HRESULT __stdcall put_OverflowContentTarget(Windows::UI::Xaml::Controls::IRichTextBlockOverflow * value) = 0;
    virtual HRESULT __stdcall get_Padding(Windows::UI::Xaml::Thickness * value) = 0;
    virtual HRESULT __stdcall put_Padding(Windows::UI::Xaml::Thickness value) = 0;
    virtual HRESULT __stdcall get_ContentSource(Windows::UI::Xaml::Controls::IRichTextBlock ** value) = 0;
    virtual HRESULT __stdcall get_HasOverflowContent(bool * value) = 0;
    virtual HRESULT __stdcall get_ContentStart(Windows::UI::Xaml::Documents::ITextPointer ** value) = 0;
    virtual HRESULT __stdcall get_ContentEnd(Windows::UI::Xaml::Documents::ITextPointer ** value) = 0;
    virtual HRESULT __stdcall get_BaselineOffset(double * value) = 0;
    virtual HRESULT __stdcall abi_GetPositionFromPoint(Windows::Foundation::Point point, Windows::UI::Xaml::Documents::ITextPointer ** returnValue) = 0;
    virtual HRESULT __stdcall abi_Focus(winrt::Windows::UI::Xaml::FocusState value, bool * returnValue) = 0;
};

struct __declspec(uuid("8742624e-a882-4826-b929-4d5c3905b9a1")) __declspec(novtable) IRichTextBlockOverflow2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MaxLines(int32_t * value) = 0;
    virtual HRESULT __stdcall put_MaxLines(int32_t value) = 0;
};

struct __declspec(uuid("041ac2f7-4f2b-43c3-a122-3fea9ca9dc87")) __declspec(novtable) IRichTextBlockOverflowStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_OverflowContentTargetProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PaddingProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_HasOverflowContentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("b5ebed4c-f8c4-4a3a-907f-e53e78279fa3")) __declspec(novtable) IRichTextBlockOverflowStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MaxLinesProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("492d883c-adea-433c-be1c-208a164262be")) __declspec(novtable) IRichTextBlockStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FontSizeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FontFamilyProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FontWeightProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FontStyleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FontStretchProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ForegroundProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TextWrappingProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TextTrimmingProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TextAlignmentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PaddingProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_LineHeightProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_LineStackingStrategyProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CharacterSpacingProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_OverflowContentTargetProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsTextSelectionEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_HasOverflowContentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SelectedTextProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TextIndentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("0d6131e1-af29-48ce-8aaf-74ecc28bfbb0")) __declspec(novtable) IRichTextBlockStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MaxLinesProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TextLineBoundsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SelectionHighlightColorProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_OpticalMarginAlignmentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsColorFontEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TextReadingOrderProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("073f7ef4-ca2b-4b49-a59a-31d8fa743332")) __declspec(novtable) IRichTextBlockStatics3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsTextScaleFactorEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("4abae829-d80c-4a5e-a48c-f8b3d3b6533d")) __declspec(novtable) IRowDefinition : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Height(Windows::UI::Xaml::GridLength * value) = 0;
    virtual HRESULT __stdcall put_Height(Windows::UI::Xaml::GridLength value) = 0;
    virtual HRESULT __stdcall get_MaxHeight(double * value) = 0;
    virtual HRESULT __stdcall put_MaxHeight(double value) = 0;
    virtual HRESULT __stdcall get_MinHeight(double * value) = 0;
    virtual HRESULT __stdcall put_MinHeight(double value) = 0;
    virtual HRESULT __stdcall get_ActualHeight(double * value) = 0;
};

struct __declspec(uuid("5adf3fe5-2056-4724-94d6-e4812b022ec8")) __declspec(novtable) IRowDefinitionStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_HeightProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MaxHeightProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MinHeightProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("5712ee2b-0eeb-46d3-aa31-5f6801b8de20")) __declspec(novtable) IScrollContentPresenter : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CanVerticallyScroll(bool * value) = 0;
    virtual HRESULT __stdcall put_CanVerticallyScroll(bool value) = 0;
    virtual HRESULT __stdcall get_CanHorizontallyScroll(bool * value) = 0;
    virtual HRESULT __stdcall put_CanHorizontallyScroll(bool value) = 0;
    virtual HRESULT __stdcall get_ExtentWidth(double * value) = 0;
    virtual HRESULT __stdcall get_ExtentHeight(double * value) = 0;
    virtual HRESULT __stdcall get_ViewportWidth(double * value) = 0;
    virtual HRESULT __stdcall get_ViewportHeight(double * value) = 0;
    virtual HRESULT __stdcall get_HorizontalOffset(double * value) = 0;
    virtual HRESULT __stdcall get_VerticalOffset(double * value) = 0;
    virtual HRESULT __stdcall get_ScrollOwner(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_ScrollOwner(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall abi_LineUp() = 0;
    virtual HRESULT __stdcall abi_LineDown() = 0;
    virtual HRESULT __stdcall abi_LineLeft() = 0;
    virtual HRESULT __stdcall abi_LineRight() = 0;
    virtual HRESULT __stdcall abi_PageUp() = 0;
    virtual HRESULT __stdcall abi_PageDown() = 0;
    virtual HRESULT __stdcall abi_PageLeft() = 0;
    virtual HRESULT __stdcall abi_PageRight() = 0;
    virtual HRESULT __stdcall abi_MouseWheelUp() = 0;
    virtual HRESULT __stdcall abi_MouseWheelDown() = 0;
    virtual HRESULT __stdcall abi_MouseWheelLeft() = 0;
    virtual HRESULT __stdcall abi_MouseWheelRight() = 0;
    virtual HRESULT __stdcall abi_SetHorizontalOffset(double offset) = 0;
    virtual HRESULT __stdcall abi_SetVerticalOffset(double offset) = 0;
    virtual HRESULT __stdcall abi_MakeVisible(Windows::UI::Xaml::IUIElement * visual, Windows::Foundation::Rect rectangle, Windows::Foundation::Rect * returnValue) = 0;
};

struct __declspec(uuid("64e9be00-4dc1-493d-abe7-cbd3c577490d")) __declspec(novtable) IScrollViewer : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_HorizontalScrollBarVisibility(winrt::Windows::UI::Xaml::Controls::ScrollBarVisibility * value) = 0;
    virtual HRESULT __stdcall put_HorizontalScrollBarVisibility(winrt::Windows::UI::Xaml::Controls::ScrollBarVisibility value) = 0;
    virtual HRESULT __stdcall get_VerticalScrollBarVisibility(winrt::Windows::UI::Xaml::Controls::ScrollBarVisibility * value) = 0;
    virtual HRESULT __stdcall put_VerticalScrollBarVisibility(winrt::Windows::UI::Xaml::Controls::ScrollBarVisibility value) = 0;
    virtual HRESULT __stdcall get_IsHorizontalRailEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsHorizontalRailEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsVerticalRailEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsVerticalRailEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsHorizontalScrollChainingEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsHorizontalScrollChainingEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsVerticalScrollChainingEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsVerticalScrollChainingEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsZoomChainingEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsZoomChainingEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsScrollInertiaEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsScrollInertiaEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsZoomInertiaEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsZoomInertiaEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_HorizontalScrollMode(winrt::Windows::UI::Xaml::Controls::ScrollMode * value) = 0;
    virtual HRESULT __stdcall put_HorizontalScrollMode(winrt::Windows::UI::Xaml::Controls::ScrollMode value) = 0;
    virtual HRESULT __stdcall get_VerticalScrollMode(winrt::Windows::UI::Xaml::Controls::ScrollMode * value) = 0;
    virtual HRESULT __stdcall put_VerticalScrollMode(winrt::Windows::UI::Xaml::Controls::ScrollMode value) = 0;
    virtual HRESULT __stdcall get_ZoomMode(winrt::Windows::UI::Xaml::Controls::ZoomMode * value) = 0;
    virtual HRESULT __stdcall put_ZoomMode(winrt::Windows::UI::Xaml::Controls::ZoomMode value) = 0;
    virtual HRESULT __stdcall get_HorizontalSnapPointsAlignment(winrt::Windows::UI::Xaml::Controls::Primitives::SnapPointsAlignment * value) = 0;
    virtual HRESULT __stdcall put_HorizontalSnapPointsAlignment(winrt::Windows::UI::Xaml::Controls::Primitives::SnapPointsAlignment value) = 0;
    virtual HRESULT __stdcall get_VerticalSnapPointsAlignment(winrt::Windows::UI::Xaml::Controls::Primitives::SnapPointsAlignment * value) = 0;
    virtual HRESULT __stdcall put_VerticalSnapPointsAlignment(winrt::Windows::UI::Xaml::Controls::Primitives::SnapPointsAlignment value) = 0;
    virtual HRESULT __stdcall get_HorizontalSnapPointsType(winrt::Windows::UI::Xaml::Controls::SnapPointsType * value) = 0;
    virtual HRESULT __stdcall put_HorizontalSnapPointsType(winrt::Windows::UI::Xaml::Controls::SnapPointsType value) = 0;
    virtual HRESULT __stdcall get_VerticalSnapPointsType(winrt::Windows::UI::Xaml::Controls::SnapPointsType * value) = 0;
    virtual HRESULT __stdcall put_VerticalSnapPointsType(winrt::Windows::UI::Xaml::Controls::SnapPointsType value) = 0;
    virtual HRESULT __stdcall get_ZoomSnapPointsType(winrt::Windows::UI::Xaml::Controls::SnapPointsType * value) = 0;
    virtual HRESULT __stdcall put_ZoomSnapPointsType(winrt::Windows::UI::Xaml::Controls::SnapPointsType value) = 0;
    virtual HRESULT __stdcall get_HorizontalOffset(double * value) = 0;
    virtual HRESULT __stdcall get_ViewportWidth(double * value) = 0;
    virtual HRESULT __stdcall get_ScrollableWidth(double * value) = 0;
    virtual HRESULT __stdcall get_ComputedHorizontalScrollBarVisibility(winrt::Windows::UI::Xaml::Visibility * value) = 0;
    virtual HRESULT __stdcall get_ExtentWidth(double * value) = 0;
    virtual HRESULT __stdcall get_VerticalOffset(double * value) = 0;
    virtual HRESULT __stdcall get_ViewportHeight(double * value) = 0;
    virtual HRESULT __stdcall get_ScrollableHeight(double * value) = 0;
    virtual HRESULT __stdcall get_ComputedVerticalScrollBarVisibility(winrt::Windows::UI::Xaml::Visibility * value) = 0;
    virtual HRESULT __stdcall get_ExtentHeight(double * value) = 0;
    virtual HRESULT __stdcall get_MinZoomFactor(float * value) = 0;
    virtual HRESULT __stdcall put_MinZoomFactor(float value) = 0;
    virtual HRESULT __stdcall get_MaxZoomFactor(float * value) = 0;
    virtual HRESULT __stdcall put_MaxZoomFactor(float value) = 0;
    virtual HRESULT __stdcall get_ZoomFactor(float * value) = 0;
    virtual HRESULT __stdcall get_ZoomSnapPoints(Windows::Foundation::Collections::IVector<float> ** value) = 0;
    virtual HRESULT __stdcall add_ViewChanged(Windows::Foundation::EventHandler<Windows::UI::Xaml::Controls::ScrollViewerViewChangedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ViewChanged(event_token token) = 0;
    virtual HRESULT __stdcall abi_ScrollToHorizontalOffset(double offset) = 0;
    virtual HRESULT __stdcall abi_ScrollToVerticalOffset(double offset) = 0;
    virtual HRESULT __stdcall abi_ZoomToFactor(float factor) = 0;
    virtual HRESULT __stdcall abi_InvalidateScrollInfo() = 0;
    virtual HRESULT __stdcall get_IsDeferredScrollingEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsDeferredScrollingEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_BringIntoViewOnFocusChange(bool * value) = 0;
    virtual HRESULT __stdcall put_BringIntoViewOnFocusChange(bool value) = 0;
};

struct __declspec(uuid("64e9be10-4dd1-494d-abf7-cbd3c577491d")) __declspec(novtable) IScrollViewer2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TopLeftHeader(Windows::UI::Xaml::IUIElement ** value) = 0;
    virtual HRESULT __stdcall put_TopLeftHeader(Windows::UI::Xaml::IUIElement * value) = 0;
    virtual HRESULT __stdcall get_LeftHeader(Windows::UI::Xaml::IUIElement ** value) = 0;
    virtual HRESULT __stdcall put_LeftHeader(Windows::UI::Xaml::IUIElement * value) = 0;
    virtual HRESULT __stdcall get_TopHeader(Windows::UI::Xaml::IUIElement ** value) = 0;
    virtual HRESULT __stdcall put_TopHeader(Windows::UI::Xaml::IUIElement * value) = 0;
    virtual HRESULT __stdcall add_ViewChanging(Windows::Foundation::EventHandler<Windows::UI::Xaml::Controls::ScrollViewerViewChangingEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ViewChanging(event_token token) = 0;
    virtual HRESULT __stdcall abi_ChangeView(Windows::Foundation::IReference<double> * horizontalOffset, Windows::Foundation::IReference<double> * verticalOffset, Windows::Foundation::IReference<float> * zoomFactor, bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_ChangeViewWithOptionalAnimation(Windows::Foundation::IReference<double> * horizontalOffset, Windows::Foundation::IReference<double> * verticalOffset, Windows::Foundation::IReference<float> * zoomFactor, bool disableAnimation, bool * returnValue) = 0;
};

struct __declspec(uuid("74e9be21-5de2-595e-bc08-dbd3c577492c")) __declspec(novtable) IScrollViewer3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_DirectManipulationStarted(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DirectManipulationStarted(event_token token) = 0;
    virtual HRESULT __stdcall add_DirectManipulationCompleted(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DirectManipulationCompleted(event_token token) = 0;
};

struct __declspec(uuid("33d1299d-8d6e-4290-bf22-905cccd04d31")) __declspec(novtable) IScrollViewerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_HorizontalSnapPointsAlignmentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_VerticalSnapPointsAlignmentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_HorizontalSnapPointsTypeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_VerticalSnapPointsTypeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ZoomSnapPointsTypeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_HorizontalOffsetProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ViewportWidthProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ScrollableWidthProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ComputedHorizontalScrollBarVisibilityProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ExtentWidthProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_VerticalOffsetProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ViewportHeightProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ScrollableHeightProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ComputedVerticalScrollBarVisibilityProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ExtentHeightProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MinZoomFactorProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MaxZoomFactorProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ZoomFactorProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ZoomSnapPointsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_HorizontalScrollBarVisibilityProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetHorizontalScrollBarVisibility(Windows::UI::Xaml::IDependencyObject * element, winrt::Windows::UI::Xaml::Controls::ScrollBarVisibility * horizontalScrollBarVisibility) = 0;
    virtual HRESULT __stdcall abi_SetHorizontalScrollBarVisibility(Windows::UI::Xaml::IDependencyObject * element, winrt::Windows::UI::Xaml::Controls::ScrollBarVisibility horizontalScrollBarVisibility) = 0;
    virtual HRESULT __stdcall get_VerticalScrollBarVisibilityProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetVerticalScrollBarVisibility(Windows::UI::Xaml::IDependencyObject * element, winrt::Windows::UI::Xaml::Controls::ScrollBarVisibility * verticalScrollBarVisibility) = 0;
    virtual HRESULT __stdcall abi_SetVerticalScrollBarVisibility(Windows::UI::Xaml::IDependencyObject * element, winrt::Windows::UI::Xaml::Controls::ScrollBarVisibility verticalScrollBarVisibility) = 0;
    virtual HRESULT __stdcall get_IsHorizontalRailEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetIsHorizontalRailEnabled(Windows::UI::Xaml::IDependencyObject * element, bool * isHorizontalRailEnabled) = 0;
    virtual HRESULT __stdcall abi_SetIsHorizontalRailEnabled(Windows::UI::Xaml::IDependencyObject * element, bool isHorizontalRailEnabled) = 0;
    virtual HRESULT __stdcall get_IsVerticalRailEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetIsVerticalRailEnabled(Windows::UI::Xaml::IDependencyObject * element, bool * isVerticalRailEnabled) = 0;
    virtual HRESULT __stdcall abi_SetIsVerticalRailEnabled(Windows::UI::Xaml::IDependencyObject * element, bool isVerticalRailEnabled) = 0;
    virtual HRESULT __stdcall get_IsHorizontalScrollChainingEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetIsHorizontalScrollChainingEnabled(Windows::UI::Xaml::IDependencyObject * element, bool * isHorizontalScrollChainingEnabled) = 0;
    virtual HRESULT __stdcall abi_SetIsHorizontalScrollChainingEnabled(Windows::UI::Xaml::IDependencyObject * element, bool isHorizontalScrollChainingEnabled) = 0;
    virtual HRESULT __stdcall get_IsVerticalScrollChainingEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetIsVerticalScrollChainingEnabled(Windows::UI::Xaml::IDependencyObject * element, bool * isVerticalScrollChainingEnabled) = 0;
    virtual HRESULT __stdcall abi_SetIsVerticalScrollChainingEnabled(Windows::UI::Xaml::IDependencyObject * element, bool isVerticalScrollChainingEnabled) = 0;
    virtual HRESULT __stdcall get_IsZoomChainingEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetIsZoomChainingEnabled(Windows::UI::Xaml::IDependencyObject * element, bool * isZoomChainingEnabled) = 0;
    virtual HRESULT __stdcall abi_SetIsZoomChainingEnabled(Windows::UI::Xaml::IDependencyObject * element, bool isZoomChainingEnabled) = 0;
    virtual HRESULT __stdcall get_IsScrollInertiaEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetIsScrollInertiaEnabled(Windows::UI::Xaml::IDependencyObject * element, bool * isScrollInertiaEnabled) = 0;
    virtual HRESULT __stdcall abi_SetIsScrollInertiaEnabled(Windows::UI::Xaml::IDependencyObject * element, bool isScrollInertiaEnabled) = 0;
    virtual HRESULT __stdcall get_IsZoomInertiaEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetIsZoomInertiaEnabled(Windows::UI::Xaml::IDependencyObject * element, bool * isZoomInertiaEnabled) = 0;
    virtual HRESULT __stdcall abi_SetIsZoomInertiaEnabled(Windows::UI::Xaml::IDependencyObject * element, bool isZoomInertiaEnabled) = 0;
    virtual HRESULT __stdcall get_HorizontalScrollModeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetHorizontalScrollMode(Windows::UI::Xaml::IDependencyObject * element, winrt::Windows::UI::Xaml::Controls::ScrollMode * horizontalScrollMode) = 0;
    virtual HRESULT __stdcall abi_SetHorizontalScrollMode(Windows::UI::Xaml::IDependencyObject * element, winrt::Windows::UI::Xaml::Controls::ScrollMode horizontalScrollMode) = 0;
    virtual HRESULT __stdcall get_VerticalScrollModeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetVerticalScrollMode(Windows::UI::Xaml::IDependencyObject * element, winrt::Windows::UI::Xaml::Controls::ScrollMode * verticalScrollMode) = 0;
    virtual HRESULT __stdcall abi_SetVerticalScrollMode(Windows::UI::Xaml::IDependencyObject * element, winrt::Windows::UI::Xaml::Controls::ScrollMode verticalScrollMode) = 0;
    virtual HRESULT __stdcall get_ZoomModeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetZoomMode(Windows::UI::Xaml::IDependencyObject * element, winrt::Windows::UI::Xaml::Controls::ZoomMode * zoomMode) = 0;
    virtual HRESULT __stdcall abi_SetZoomMode(Windows::UI::Xaml::IDependencyObject * element, winrt::Windows::UI::Xaml::Controls::ZoomMode zoomMode) = 0;
    virtual HRESULT __stdcall get_IsDeferredScrollingEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetIsDeferredScrollingEnabled(Windows::UI::Xaml::IDependencyObject * element, bool * isDeferredScrollingEnabled) = 0;
    virtual HRESULT __stdcall abi_SetIsDeferredScrollingEnabled(Windows::UI::Xaml::IDependencyObject * element, bool isDeferredScrollingEnabled) = 0;
    virtual HRESULT __stdcall get_BringIntoViewOnFocusChangeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetBringIntoViewOnFocusChange(Windows::UI::Xaml::IDependencyObject * element, bool * bringIntoViewOnFocusChange) = 0;
    virtual HRESULT __stdcall abi_SetBringIntoViewOnFocusChange(Windows::UI::Xaml::IDependencyObject * element, bool bringIntoViewOnFocusChange) = 0;
};

struct __declspec(uuid("33d129ad-8d7e-42a0-bf32-905cccd04d41")) __declspec(novtable) IScrollViewerStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TopLeftHeaderProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_LeftHeaderProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TopHeaderProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("64e9be01-4dc2-493e-abe8-cbd3c577490e")) __declspec(novtable) IScrollViewerView : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_HorizontalOffset(double * value) = 0;
    virtual HRESULT __stdcall get_VerticalOffset(double * value) = 0;
    virtual HRESULT __stdcall get_ZoomFactor(float * value) = 0;
};

struct __declspec(uuid("4dd04f7e-7a11-4b2e-9933-577df39252b6")) __declspec(novtable) IScrollViewerViewChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsIntermediate(bool * value) = 0;
};

struct __declspec(uuid("4dd04f7f-7a11-4b2e-9933-577df39252b6")) __declspec(novtable) IScrollViewerViewChangingEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_NextView(Windows::UI::Xaml::Controls::IScrollViewerView ** value) = 0;
    virtual HRESULT __stdcall get_FinalView(Windows::UI::Xaml::Controls::IScrollViewerView ** value) = 0;
    virtual HRESULT __stdcall get_IsInertial(bool * value) = 0;
};

struct __declspec(uuid("f89ecc5a-99ba-4bd4-966c-f11fa443d13c")) __declspec(novtable) ISearchBox : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SearchHistoryEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_SearchHistoryEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_SearchHistoryContext(hstring * value) = 0;
    virtual HRESULT __stdcall put_SearchHistoryContext(hstring value) = 0;
    virtual HRESULT __stdcall get_PlaceholderText(hstring * value) = 0;
    virtual HRESULT __stdcall put_PlaceholderText(hstring value) = 0;
    virtual HRESULT __stdcall get_QueryText(hstring * value) = 0;
    virtual HRESULT __stdcall put_QueryText(hstring value) = 0;
    virtual HRESULT __stdcall get_FocusOnKeyboardInput(bool * value) = 0;
    virtual HRESULT __stdcall put_FocusOnKeyboardInput(bool value) = 0;
    virtual HRESULT __stdcall get_ChooseSuggestionOnEnter(bool * value) = 0;
    virtual HRESULT __stdcall put_ChooseSuggestionOnEnter(bool value) = 0;
    virtual HRESULT __stdcall add_QueryChanged(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::SearchBox, Windows::UI::Xaml::Controls::SearchBoxQueryChangedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_QueryChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_SuggestionsRequested(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::SearchBox, Windows::UI::Xaml::Controls::SearchBoxSuggestionsRequestedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SuggestionsRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_QuerySubmitted(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::SearchBox, Windows::UI::Xaml::Controls::SearchBoxQuerySubmittedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_QuerySubmitted(event_token token) = 0;
    virtual HRESULT __stdcall add_ResultSuggestionChosen(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::SearchBox, Windows::UI::Xaml::Controls::SearchBoxResultSuggestionChosenEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ResultSuggestionChosen(event_token token) = 0;
    virtual HRESULT __stdcall add_PrepareForFocusOnKeyboardInput(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::SearchBox, Windows::UI::Xaml::RoutedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PrepareForFocusOnKeyboardInput(event_token token) = 0;
    virtual HRESULT __stdcall abi_SetLocalContentSuggestionSettings(Windows::ApplicationModel::Search::ILocalContentSuggestionSettings * settings) = 0;
};

struct __declspec(uuid("cd743f6d-8685-46b4-9ddd-202f6941b701")) __declspec(novtable) ISearchBoxFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::ISearchBox ** instance) = 0;
};

struct __declspec(uuid("a9a70f8f-0cb0-4bd2-9998-2fb57ad5e731")) __declspec(novtable) ISearchBoxQueryChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_QueryText(hstring * value) = 0;
    virtual HRESULT __stdcall get_Language(hstring * value) = 0;
    virtual HRESULT __stdcall get_LinguisticDetails(Windows::ApplicationModel::Search::ISearchQueryLinguisticDetails ** value) = 0;
};

struct __declspec(uuid("126e90fd-3c4e-4ccb-9aef-4705d19fe548")) __declspec(novtable) ISearchBoxQuerySubmittedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_QueryText(hstring * value) = 0;
    virtual HRESULT __stdcall get_Language(hstring * value) = 0;
    virtual HRESULT __stdcall get_LinguisticDetails(Windows::ApplicationModel::Search::ISearchQueryLinguisticDetails ** value) = 0;
    virtual HRESULT __stdcall get_KeyModifiers(winrt::Windows::System::VirtualKeyModifiers * value) = 0;
};

struct __declspec(uuid("18918c23-e4c3-4662-a03b-d054ffd0f905")) __declspec(novtable) ISearchBoxResultSuggestionChosenEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Tag(hstring * value) = 0;
    virtual HRESULT __stdcall get_KeyModifiers(winrt::Windows::System::VirtualKeyModifiers * value) = 0;
};

struct __declspec(uuid("b123634f-6871-48cd-92df-4cff22459082")) __declspec(novtable) ISearchBoxStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SearchHistoryEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SearchHistoryContextProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PlaceholderTextProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_QueryTextProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FocusOnKeyboardInputProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ChooseSuggestionOnEnterProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("da15170e-e566-48cb-bd11-fe4b0f30a44d")) __declspec(novtable) ISearchBoxSuggestionsRequestedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_QueryText(hstring * value) = 0;
    virtual HRESULT __stdcall get_Language(hstring * value) = 0;
    virtual HRESULT __stdcall get_LinguisticDetails(Windows::ApplicationModel::Search::ISearchQueryLinguisticDetails ** value) = 0;
    virtual HRESULT __stdcall get_Request(Windows::ApplicationModel::Search::ISearchSuggestionsRequest ** value) = 0;
};

struct __declspec(uuid("dd49ee6b-d165-430f-a37d-b807064f85e1")) __declspec(novtable) ISectionsInViewChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AddedSections(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::HubSection> ** value) = 0;
    virtual HRESULT __stdcall get_RemovedSections(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::HubSection> ** value) = 0;
};

struct __declspec(uuid("557f5244-92f8-4150-b730-e6346e8f50d1")) __declspec(novtable) ISectionsInViewChangedEventArgsFactory : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("c972d2dc-b609-4758-851e-a799c21de97d")) __declspec(novtable) ISelectionChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AddedItems(Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> ** value) = 0;
    virtual HRESULT __stdcall get_RemovedItems(Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> ** value) = 0;
};

struct __declspec(uuid("11a8b6b5-2830-4517-84cd-5524c8b88b45")) __declspec(novtable) ISelectionChangedEventArgsFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithRemovedItemsAndAddedItems(Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> * removedItems, Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> * addedItems, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::ISelectionChangedEventArgs ** instance) = 0;
};

struct __declspec(uuid("019fff21-ece6-4fbc-bf40-8938d4813e27")) __declspec(novtable) ISemanticZoom : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ZoomedInView(Windows::UI::Xaml::Controls::ISemanticZoomInformation ** value) = 0;
    virtual HRESULT __stdcall put_ZoomedInView(Windows::UI::Xaml::Controls::ISemanticZoomInformation * value) = 0;
    virtual HRESULT __stdcall get_ZoomedOutView(Windows::UI::Xaml::Controls::ISemanticZoomInformation ** value) = 0;
    virtual HRESULT __stdcall put_ZoomedOutView(Windows::UI::Xaml::Controls::ISemanticZoomInformation * value) = 0;
    virtual HRESULT __stdcall get_IsZoomedInViewActive(bool * value) = 0;
    virtual HRESULT __stdcall put_IsZoomedInViewActive(bool value) = 0;
    virtual HRESULT __stdcall get_CanChangeViews(bool * value) = 0;
    virtual HRESULT __stdcall put_CanChangeViews(bool value) = 0;
    virtual HRESULT __stdcall add_ViewChangeStarted(Windows::UI::Xaml::Controls::SemanticZoomViewChangedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ViewChangeStarted(event_token token) = 0;
    virtual HRESULT __stdcall add_ViewChangeCompleted(Windows::UI::Xaml::Controls::SemanticZoomViewChangedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ViewChangeCompleted(event_token token) = 0;
    virtual HRESULT __stdcall abi_ToggleActiveView() = 0;
    virtual HRESULT __stdcall get_IsZoomOutButtonEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsZoomOutButtonEnabled(bool value) = 0;
};

struct __declspec(uuid("a76a3b63-229b-4dc5-aa11-9d922fbf8a98")) __declspec(novtable) ISemanticZoomInformation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SemanticZoomOwner(Windows::UI::Xaml::Controls::ISemanticZoom ** value) = 0;
    virtual HRESULT __stdcall put_SemanticZoomOwner(Windows::UI::Xaml::Controls::ISemanticZoom * value) = 0;
    virtual HRESULT __stdcall get_IsActiveView(bool * value) = 0;
    virtual HRESULT __stdcall put_IsActiveView(bool value) = 0;
    virtual HRESULT __stdcall get_IsZoomedInView(bool * value) = 0;
    virtual HRESULT __stdcall put_IsZoomedInView(bool value) = 0;
    virtual HRESULT __stdcall abi_InitializeViewChange() = 0;
    virtual HRESULT __stdcall abi_CompleteViewChange() = 0;
    virtual HRESULT __stdcall abi_MakeVisible(Windows::UI::Xaml::Controls::ISemanticZoomLocation * item) = 0;
    virtual HRESULT __stdcall abi_StartViewChangeFrom(Windows::UI::Xaml::Controls::ISemanticZoomLocation * source, Windows::UI::Xaml::Controls::ISemanticZoomLocation * destination) = 0;
    virtual HRESULT __stdcall abi_StartViewChangeTo(Windows::UI::Xaml::Controls::ISemanticZoomLocation * source, Windows::UI::Xaml::Controls::ISemanticZoomLocation * destination) = 0;
    virtual HRESULT __stdcall abi_CompleteViewChangeFrom(Windows::UI::Xaml::Controls::ISemanticZoomLocation * source, Windows::UI::Xaml::Controls::ISemanticZoomLocation * destination) = 0;
    virtual HRESULT __stdcall abi_CompleteViewChangeTo(Windows::UI::Xaml::Controls::ISemanticZoomLocation * source, Windows::UI::Xaml::Controls::ISemanticZoomLocation * destination) = 0;
};

struct __declspec(uuid("42011736-e3c2-496b-bc4e-d750d4375b9a")) __declspec(novtable) ISemanticZoomLocation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Item(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_Item(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_Bounds(Windows::Foundation::Rect * value) = 0;
    virtual HRESULT __stdcall put_Bounds(Windows::Foundation::Rect value) = 0;
};

struct __declspec(uuid("8ef17ef2-9898-4666-b285-3ed38a07910e")) __declspec(novtable) ISemanticZoomStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ZoomedInViewProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ZoomedOutViewProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsZoomedInViewActiveProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CanChangeViewsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsZoomOutButtonEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("47dfc068-b569-4b19-842d-8e6cf90989af")) __declspec(novtable) ISemanticZoomViewChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsSourceZoomedInView(bool * value) = 0;
    virtual HRESULT __stdcall put_IsSourceZoomedInView(bool value) = 0;
    virtual HRESULT __stdcall get_SourceItem(Windows::UI::Xaml::Controls::ISemanticZoomLocation ** value) = 0;
    virtual HRESULT __stdcall put_SourceItem(Windows::UI::Xaml::Controls::ISemanticZoomLocation * value) = 0;
    virtual HRESULT __stdcall get_DestinationItem(Windows::UI::Xaml::Controls::ISemanticZoomLocation ** value) = 0;
    virtual HRESULT __stdcall put_DestinationItem(Windows::UI::Xaml::Controls::ISemanticZoomLocation * value) = 0;
};

struct __declspec(uuid("830ba82b-c55b-4e32-a51c-5791e024c8af")) __declspec(novtable) ISettingsFlyout : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Title(hstring * value) = 0;
    virtual HRESULT __stdcall put_Title(hstring value) = 0;
    virtual HRESULT __stdcall get_HeaderBackground(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall put_HeaderBackground(Windows::UI::Xaml::Media::IBrush * value) = 0;
    virtual HRESULT __stdcall get_HeaderForeground(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall put_HeaderForeground(Windows::UI::Xaml::Media::IBrush * value) = 0;
    virtual HRESULT __stdcall get_IconSource(Windows::UI::Xaml::Media::IImageSource ** value) = 0;
    virtual HRESULT __stdcall put_IconSource(Windows::UI::Xaml::Media::IImageSource * value) = 0;
    virtual HRESULT __stdcall get_TemplateSettings(Windows::UI::Xaml::Controls::Primitives::ISettingsFlyoutTemplateSettings ** value) = 0;
    virtual HRESULT __stdcall add_BackClick(Windows::UI::Xaml::Controls::BackClickEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_BackClick(event_token token) = 0;
    virtual HRESULT __stdcall abi_Show() = 0;
    virtual HRESULT __stdcall abi_ShowIndependent() = 0;
    virtual HRESULT __stdcall abi_Hide() = 0;
};

struct __declspec(uuid("480c7011-57aa-4db6-b6fd-ec676f6d414e")) __declspec(novtable) ISettingsFlyoutFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::ISettingsFlyout ** instance) = 0;
};

struct __declspec(uuid("d0e3b535-9157-4be4-a42a-f591698846ac")) __declspec(novtable) ISettingsFlyoutStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TitleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_HeaderBackgroundProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_HeaderForegroundProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IconSourceProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("89572027-4c48-4700-8076-497ba73d9c18")) __declspec(novtable) ISlider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IntermediateValue(double * value) = 0;
    virtual HRESULT __stdcall put_IntermediateValue(double value) = 0;
    virtual HRESULT __stdcall get_StepFrequency(double * value) = 0;
    virtual HRESULT __stdcall put_StepFrequency(double value) = 0;
    virtual HRESULT __stdcall get_SnapsTo(winrt::Windows::UI::Xaml::Controls::Primitives::SliderSnapsTo * value) = 0;
    virtual HRESULT __stdcall put_SnapsTo(winrt::Windows::UI::Xaml::Controls::Primitives::SliderSnapsTo value) = 0;
    virtual HRESULT __stdcall get_TickFrequency(double * value) = 0;
    virtual HRESULT __stdcall put_TickFrequency(double value) = 0;
    virtual HRESULT __stdcall get_TickPlacement(winrt::Windows::UI::Xaml::Controls::Primitives::TickPlacement * value) = 0;
    virtual HRESULT __stdcall put_TickPlacement(winrt::Windows::UI::Xaml::Controls::Primitives::TickPlacement value) = 0;
    virtual HRESULT __stdcall get_Orientation(winrt::Windows::UI::Xaml::Controls::Orientation * value) = 0;
    virtual HRESULT __stdcall put_Orientation(winrt::Windows::UI::Xaml::Controls::Orientation value) = 0;
    virtual HRESULT __stdcall get_IsDirectionReversed(bool * value) = 0;
    virtual HRESULT __stdcall put_IsDirectionReversed(bool value) = 0;
    virtual HRESULT __stdcall get_IsThumbToolTipEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsThumbToolTipEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_ThumbToolTipValueConverter(Windows::UI::Xaml::Data::IValueConverter ** value) = 0;
    virtual HRESULT __stdcall put_ThumbToolTipValueConverter(Windows::UI::Xaml::Data::IValueConverter * value) = 0;
};

struct __declspec(uuid("40a3c50e-87d6-4d2f-b1cf-b279cc996f26")) __declspec(novtable) ISlider2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Header(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_Header(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_HeaderTemplate(Windows::UI::Xaml::IDataTemplate ** value) = 0;
    virtual HRESULT __stdcall put_HeaderTemplate(Windows::UI::Xaml::IDataTemplate * value) = 0;
};

struct __declspec(uuid("03a67b37-c7bf-437c-848f-8cb5b753eab4")) __declspec(novtable) ISliderFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::ISlider ** instance) = 0;
};

struct __declspec(uuid("8a4363d7-7fdf-4d30-98fe-ce78c05b31cf")) __declspec(novtable) ISliderStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IntermediateValueProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_StepFrequencyProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SnapsToProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TickFrequencyProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TickPlacementProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_OrientationProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsDirectionReversedProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsThumbToolTipEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ThumbToolTipValueConverterProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("00e7935d-79a5-4759-96a6-29e0a94add33")) __declspec(novtable) ISliderStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_HeaderProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_HeaderTemplateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("97222f31-3844-429e-939c-1673155322a1")) __declspec(novtable) ISplitView : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Content(Windows::UI::Xaml::IUIElement ** value) = 0;
    virtual HRESULT __stdcall put_Content(Windows::UI::Xaml::IUIElement * value) = 0;
    virtual HRESULT __stdcall get_Pane(Windows::UI::Xaml::IUIElement ** value) = 0;
    virtual HRESULT __stdcall put_Pane(Windows::UI::Xaml::IUIElement * value) = 0;
    virtual HRESULT __stdcall get_IsPaneOpen(bool * value) = 0;
    virtual HRESULT __stdcall put_IsPaneOpen(bool value) = 0;
    virtual HRESULT __stdcall get_OpenPaneLength(double * value) = 0;
    virtual HRESULT __stdcall put_OpenPaneLength(double value) = 0;
    virtual HRESULT __stdcall get_CompactPaneLength(double * value) = 0;
    virtual HRESULT __stdcall put_CompactPaneLength(double value) = 0;
    virtual HRESULT __stdcall get_PanePlacement(winrt::Windows::UI::Xaml::Controls::SplitViewPanePlacement * value) = 0;
    virtual HRESULT __stdcall put_PanePlacement(winrt::Windows::UI::Xaml::Controls::SplitViewPanePlacement value) = 0;
    virtual HRESULT __stdcall get_DisplayMode(winrt::Windows::UI::Xaml::Controls::SplitViewDisplayMode * value) = 0;
    virtual HRESULT __stdcall put_DisplayMode(winrt::Windows::UI::Xaml::Controls::SplitViewDisplayMode value) = 0;
    virtual HRESULT __stdcall get_TemplateSettings(Windows::UI::Xaml::Controls::Primitives::ISplitViewTemplateSettings ** value) = 0;
    virtual HRESULT __stdcall get_PaneBackground(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall put_PaneBackground(Windows::UI::Xaml::Media::IBrush * value) = 0;
    virtual HRESULT __stdcall add_PaneClosing(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::SplitView, Windows::UI::Xaml::Controls::SplitViewPaneClosingEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PaneClosing(event_token token) = 0;
    virtual HRESULT __stdcall add_PaneClosed(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::SplitView, Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PaneClosed(event_token token) = 0;
};

struct __declspec(uuid("5ea7dc10-cc83-409a-82f9-3e91d6d7084f")) __declspec(novtable) ISplitView2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LightDismissOverlayMode(winrt::Windows::UI::Xaml::Controls::LightDismissOverlayMode * value) = 0;
    virtual HRESULT __stdcall put_LightDismissOverlayMode(winrt::Windows::UI::Xaml::Controls::LightDismissOverlayMode value) = 0;
};

struct __declspec(uuid("f101773a-084e-4fb9-8442-63221b44533f")) __declspec(novtable) ISplitViewFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::ISplitView ** instance) = 0;
};

struct __declspec(uuid("93cf494e-7a95-44d8-9562-1b348248da9f")) __declspec(novtable) ISplitViewPaneClosingEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Cancel(bool * value) = 0;
    virtual HRESULT __stdcall put_Cancel(bool value) = 0;
};

struct __declspec(uuid("859b4f6f-44ab-4e4b-91c1-17b7056d9b5f")) __declspec(novtable) ISplitViewStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ContentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PaneProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsPaneOpenProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_OpenPaneLengthProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CompactPaneLengthProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PanePlacementProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_DisplayModeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TemplateSettingsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PaneBackgroundProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("14b7cd7a-dfbc-422c-80a9-585871297113")) __declspec(novtable) ISplitViewStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LightDismissOverlayModeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("b8ae8fe2-d641-4fd7-80b4-7439207d2798")) __declspec(novtable) IStackPanel : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AreScrollSnapPointsRegular(bool * value) = 0;
    virtual HRESULT __stdcall put_AreScrollSnapPointsRegular(bool value) = 0;
    virtual HRESULT __stdcall get_Orientation(winrt::Windows::UI::Xaml::Controls::Orientation * value) = 0;
    virtual HRESULT __stdcall put_Orientation(winrt::Windows::UI::Xaml::Controls::Orientation value) = 0;
};

struct __declspec(uuid("36f23359-040e-48f7-9a98-f2664591959c")) __declspec(novtable) IStackPanel2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_BorderBrush(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall put_BorderBrush(Windows::UI::Xaml::Media::IBrush * value) = 0;
    virtual HRESULT __stdcall get_BorderThickness(Windows::UI::Xaml::Thickness * value) = 0;
    virtual HRESULT __stdcall put_BorderThickness(Windows::UI::Xaml::Thickness value) = 0;
    virtual HRESULT __stdcall get_CornerRadius(Windows::UI::Xaml::CornerRadius * value) = 0;
    virtual HRESULT __stdcall put_CornerRadius(Windows::UI::Xaml::CornerRadius value) = 0;
    virtual HRESULT __stdcall get_Padding(Windows::UI::Xaml::Thickness * value) = 0;
    virtual HRESULT __stdcall put_Padding(Windows::UI::Xaml::Thickness value) = 0;
};

struct __declspec(uuid("63d8248a-8b34-445a-808f-b6ecd62a27d9")) __declspec(novtable) IStackPanelFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IStackPanel ** instance) = 0;
};

struct __declspec(uuid("f0d0cd93-4dbc-48a7-9914-954924657771")) __declspec(novtable) IStackPanelStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AreScrollSnapPointsRegularProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_OrientationProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("d97e6257-080d-412e-a91a-ce6e5d02aad3")) __declspec(novtable) IStackPanelStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_BorderBrushProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_BorderThicknessProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CornerRadiusProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PaddingProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("d1113f67-d8c1-4ae4-98f0-d8504502f08b")) __declspec(novtable) IStyleSelector : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SelectStyle(Windows::Foundation::IInspectable * item, Windows::UI::Xaml::IDependencyObject * container, Windows::UI::Xaml::IStyle ** returnValue) = 0;
};

struct __declspec(uuid("9e942ae7-3761-447f-8f97-29e39d5eb310")) __declspec(novtable) IStyleSelectorFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IStyleSelector ** instance) = 0;
};

struct __declspec(uuid("08add66d-0e2e-43a0-aeca-8faa94b9d017")) __declspec(novtable) IStyleSelectorOverrides : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SelectStyleCore(Windows::Foundation::IInspectable * item, Windows::UI::Xaml::IDependencyObject * container, Windows::UI::Xaml::IStyle ** returnValue) = 0;
};

struct __declspec(uuid("1c59db48-8233-4c0c-bcf5-02a5fb35ae00")) __declspec(novtable) ISwapChainBackgroundPanel : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("21e672f2-2592-4c38-870f-28fbcf52c095")) __declspec(novtable) ISwapChainBackgroundPanel2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateCoreIndependentInputSource(winrt::Windows::UI::Core::CoreInputDeviceTypes deviceTypes, Windows::UI::Core::ICoreInputSourceBase ** returnValue) = 0;
};

struct __declspec(uuid("198289d4-c89b-49b2-896c-5917bf8adcae")) __declspec(novtable) ISwapChainBackgroundPanelFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::ISwapChainBackgroundPanel ** instance) = 0;
};

struct __declspec(uuid("c589644f-eba8-427a-b75a-9f1f93a11ae9")) __declspec(novtable) ISwapChainPanel : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CompositionScaleX(float * value) = 0;
    virtual HRESULT __stdcall get_CompositionScaleY(float * value) = 0;
    virtual HRESULT __stdcall add_CompositionScaleChanged(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::SwapChainPanel, Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_CompositionScaleChanged(event_token token) = 0;
    virtual HRESULT __stdcall abi_CreateCoreIndependentInputSource(winrt::Windows::UI::Core::CoreInputDeviceTypes deviceTypes, Windows::UI::Core::ICoreInputSourceBase ** returnValue) = 0;
};

struct __declspec(uuid("f38f8d7f-1a48-49cb-86d2-10eaaaf6fd70")) __declspec(novtable) ISwapChainPanelFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::ISwapChainPanel ** instance) = 0;
};

struct __declspec(uuid("f89c0297-eea8-498c-99c4-257e3660df7e")) __declspec(novtable) ISwapChainPanelStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CompositionScaleXProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CompositionScaleYProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("7a4774c9-a6a3-4b30-8ff1-9081d70e9a5c")) __declspec(novtable) ISymbolIcon : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Symbol(winrt::Windows::UI::Xaml::Controls::Symbol * value) = 0;
    virtual HRESULT __stdcall put_Symbol(winrt::Windows::UI::Xaml::Controls::Symbol value) = 0;
};

struct __declspec(uuid("c7252b88-e76c-4b44-8a05-046b9dc772b8")) __declspec(novtable) ISymbolIconFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithSymbol(winrt::Windows::UI::Xaml::Controls::Symbol symbol, Windows::UI::Xaml::Controls::ISymbolIcon ** instance) = 0;
};

struct __declspec(uuid("8624fbdf-952c-4f76-b03f-30833be99572")) __declspec(novtable) ISymbolIconStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SymbolProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("ae2d9271-3b4a-45fc-8468-f7949548f4d5")) __declspec(novtable) ITextBlock : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FontSize(double * value) = 0;
    virtual HRESULT __stdcall put_FontSize(double value) = 0;
    virtual HRESULT __stdcall get_FontFamily(Windows::UI::Xaml::Media::IFontFamily ** value) = 0;
    virtual HRESULT __stdcall put_FontFamily(Windows::UI::Xaml::Media::IFontFamily * value) = 0;
    virtual HRESULT __stdcall get_FontWeight(Windows::UI::Text::FontWeight * value) = 0;
    virtual HRESULT __stdcall put_FontWeight(Windows::UI::Text::FontWeight value) = 0;
    virtual HRESULT __stdcall get_FontStyle(winrt::Windows::UI::Text::FontStyle * value) = 0;
    virtual HRESULT __stdcall put_FontStyle(winrt::Windows::UI::Text::FontStyle value) = 0;
    virtual HRESULT __stdcall get_FontStretch(winrt::Windows::UI::Text::FontStretch * value) = 0;
    virtual HRESULT __stdcall put_FontStretch(winrt::Windows::UI::Text::FontStretch value) = 0;
    virtual HRESULT __stdcall get_CharacterSpacing(int32_t * value) = 0;
    virtual HRESULT __stdcall put_CharacterSpacing(int32_t value) = 0;
    virtual HRESULT __stdcall get_Foreground(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall put_Foreground(Windows::UI::Xaml::Media::IBrush * value) = 0;
    virtual HRESULT __stdcall get_TextWrapping(winrt::Windows::UI::Xaml::TextWrapping * value) = 0;
    virtual HRESULT __stdcall put_TextWrapping(winrt::Windows::UI::Xaml::TextWrapping value) = 0;
    virtual HRESULT __stdcall get_TextTrimming(winrt::Windows::UI::Xaml::TextTrimming * value) = 0;
    virtual HRESULT __stdcall put_TextTrimming(winrt::Windows::UI::Xaml::TextTrimming value) = 0;
    virtual HRESULT __stdcall get_TextAlignment(winrt::Windows::UI::Xaml::TextAlignment * value) = 0;
    virtual HRESULT __stdcall put_TextAlignment(winrt::Windows::UI::Xaml::TextAlignment value) = 0;
    virtual HRESULT __stdcall get_Text(hstring * value) = 0;
    virtual HRESULT __stdcall put_Text(hstring value) = 0;
    virtual HRESULT __stdcall get_Inlines(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Documents::Inline> ** value) = 0;
    virtual HRESULT __stdcall get_Padding(Windows::UI::Xaml::Thickness * value) = 0;
    virtual HRESULT __stdcall put_Padding(Windows::UI::Xaml::Thickness value) = 0;
    virtual HRESULT __stdcall get_LineHeight(double * value) = 0;
    virtual HRESULT __stdcall put_LineHeight(double value) = 0;
    virtual HRESULT __stdcall get_LineStackingStrategy(winrt::Windows::UI::Xaml::LineStackingStrategy * value) = 0;
    virtual HRESULT __stdcall put_LineStackingStrategy(winrt::Windows::UI::Xaml::LineStackingStrategy value) = 0;
    virtual HRESULT __stdcall get_IsTextSelectionEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsTextSelectionEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_SelectedText(hstring * value) = 0;
    virtual HRESULT __stdcall get_ContentStart(Windows::UI::Xaml::Documents::ITextPointer ** value) = 0;
    virtual HRESULT __stdcall get_ContentEnd(Windows::UI::Xaml::Documents::ITextPointer ** value) = 0;
    virtual HRESULT __stdcall get_SelectionStart(Windows::UI::Xaml::Documents::ITextPointer ** value) = 0;
    virtual HRESULT __stdcall get_SelectionEnd(Windows::UI::Xaml::Documents::ITextPointer ** value) = 0;
    virtual HRESULT __stdcall get_BaselineOffset(double * value) = 0;
    virtual HRESULT __stdcall add_SelectionChanged(Windows::UI::Xaml::RoutedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SelectionChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_ContextMenuOpening(Windows::UI::Xaml::Controls::ContextMenuOpeningEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ContextMenuOpening(event_token token) = 0;
    virtual HRESULT __stdcall abi_SelectAll() = 0;
    virtual HRESULT __stdcall abi_Select(Windows::UI::Xaml::Documents::ITextPointer * start, Windows::UI::Xaml::Documents::ITextPointer * end) = 0;
    virtual HRESULT __stdcall abi_Focus(winrt::Windows::UI::Xaml::FocusState value, bool * returnValue) = 0;
};

struct __declspec(uuid("45206a4c-0a4e-4fbf-aee9-335d5a205f6e")) __declspec(novtable) ITextBlock2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SelectionHighlightColor(Windows::UI::Xaml::Media::ISolidColorBrush ** value) = 0;
    virtual HRESULT __stdcall put_SelectionHighlightColor(Windows::UI::Xaml::Media::ISolidColorBrush * value) = 0;
    virtual HRESULT __stdcall get_MaxLines(int32_t * value) = 0;
    virtual HRESULT __stdcall put_MaxLines(int32_t value) = 0;
    virtual HRESULT __stdcall get_TextLineBounds(winrt::Windows::UI::Xaml::TextLineBounds * value) = 0;
    virtual HRESULT __stdcall put_TextLineBounds(winrt::Windows::UI::Xaml::TextLineBounds value) = 0;
    virtual HRESULT __stdcall get_OpticalMarginAlignment(winrt::Windows::UI::Xaml::OpticalMarginAlignment * value) = 0;
    virtual HRESULT __stdcall put_OpticalMarginAlignment(winrt::Windows::UI::Xaml::OpticalMarginAlignment value) = 0;
    virtual HRESULT __stdcall get_IsColorFontEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsColorFontEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_TextReadingOrder(winrt::Windows::UI::Xaml::TextReadingOrder * value) = 0;
    virtual HRESULT __stdcall put_TextReadingOrder(winrt::Windows::UI::Xaml::TextReadingOrder value) = 0;
};

struct __declspec(uuid("b651dd5a-424b-48c3-9b67-486f4e139899")) __declspec(novtable) ITextBlock3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsTextScaleFactorEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsTextScaleFactorEnabled(bool value) = 0;
};

struct __declspec(uuid("b014f270-9808-4adc-b452-60cda54100c1")) __declspec(novtable) ITextBlock4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetAlphaMask(Windows::UI::Composition::ICompositionBrush ** returnValue) = 0;
};

struct __declspec(uuid("193ec042-a847-4552-b4e8-db36655b840a")) __declspec(novtable) ITextBlockStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FontSizeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FontFamilyProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FontWeightProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FontStyleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FontStretchProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CharacterSpacingProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ForegroundProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TextWrappingProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TextTrimmingProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TextAlignmentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TextProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PaddingProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_LineHeightProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_LineStackingStrategyProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsTextSelectionEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SelectedTextProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("88100b1b-ff24-4b93-a0e6-f029c94871f1")) __declspec(novtable) ITextBlockStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SelectionHighlightColorProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MaxLinesProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TextLineBoundsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_OpticalMarginAlignmentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsColorFontEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TextReadingOrderProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("8d16b9eb-20a1-4eab-bbf2-1d6bdcbcd705")) __declspec(novtable) ITextBlockStatics3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsTextScaleFactorEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("e48f5a8b-1dff-4352-a1f4-e516514ec882")) __declspec(novtable) ITextBox : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Text(hstring * value) = 0;
    virtual HRESULT __stdcall put_Text(hstring value) = 0;
    virtual HRESULT __stdcall get_SelectedText(hstring * value) = 0;
    virtual HRESULT __stdcall put_SelectedText(hstring value) = 0;
    virtual HRESULT __stdcall get_SelectionLength(int32_t * value) = 0;
    virtual HRESULT __stdcall put_SelectionLength(int32_t value) = 0;
    virtual HRESULT __stdcall get_SelectionStart(int32_t * value) = 0;
    virtual HRESULT __stdcall put_SelectionStart(int32_t value) = 0;
    virtual HRESULT __stdcall get_MaxLength(int32_t * value) = 0;
    virtual HRESULT __stdcall put_MaxLength(int32_t value) = 0;
    virtual HRESULT __stdcall get_IsReadOnly(bool * value) = 0;
    virtual HRESULT __stdcall put_IsReadOnly(bool value) = 0;
    virtual HRESULT __stdcall get_AcceptsReturn(bool * value) = 0;
    virtual HRESULT __stdcall put_AcceptsReturn(bool value) = 0;
    virtual HRESULT __stdcall get_TextAlignment(winrt::Windows::UI::Xaml::TextAlignment * value) = 0;
    virtual HRESULT __stdcall put_TextAlignment(winrt::Windows::UI::Xaml::TextAlignment value) = 0;
    virtual HRESULT __stdcall get_TextWrapping(winrt::Windows::UI::Xaml::TextWrapping * value) = 0;
    virtual HRESULT __stdcall put_TextWrapping(winrt::Windows::UI::Xaml::TextWrapping value) = 0;
    virtual HRESULT __stdcall get_IsSpellCheckEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsSpellCheckEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsTextPredictionEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsTextPredictionEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_InputScope(Windows::UI::Xaml::Input::IInputScope ** value) = 0;
    virtual HRESULT __stdcall put_InputScope(Windows::UI::Xaml::Input::IInputScope * value) = 0;
    virtual HRESULT __stdcall add_TextChanged(Windows::UI::Xaml::Controls::TextChangedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_TextChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_SelectionChanged(Windows::UI::Xaml::RoutedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SelectionChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_ContextMenuOpening(Windows::UI::Xaml::Controls::ContextMenuOpeningEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ContextMenuOpening(event_token token) = 0;
    virtual HRESULT __stdcall abi_Select(int32_t start, int32_t length) = 0;
    virtual HRESULT __stdcall abi_SelectAll() = 0;
    virtual HRESULT __stdcall abi_GetRectFromCharacterIndex(int32_t charIndex, bool trailingEdge, Windows::Foundation::Rect * returnValue) = 0;
};

struct __declspec(uuid("f7168c00-1432-462a-9405-38f385bfc37c")) __declspec(novtable) ITextBox2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Header(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_Header(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_HeaderTemplate(Windows::UI::Xaml::IDataTemplate ** value) = 0;
    virtual HRESULT __stdcall put_HeaderTemplate(Windows::UI::Xaml::IDataTemplate * value) = 0;
    virtual HRESULT __stdcall get_PlaceholderText(hstring * value) = 0;
    virtual HRESULT __stdcall put_PlaceholderText(hstring value) = 0;
    virtual HRESULT __stdcall get_SelectionHighlightColor(Windows::UI::Xaml::Media::ISolidColorBrush ** value) = 0;
    virtual HRESULT __stdcall put_SelectionHighlightColor(Windows::UI::Xaml::Media::ISolidColorBrush * value) = 0;
    virtual HRESULT __stdcall get_PreventKeyboardDisplayOnProgrammaticFocus(bool * value) = 0;
    virtual HRESULT __stdcall put_PreventKeyboardDisplayOnProgrammaticFocus(bool value) = 0;
    virtual HRESULT __stdcall get_IsColorFontEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsColorFontEnabled(bool value) = 0;
    virtual HRESULT __stdcall add_Paste(Windows::UI::Xaml::Controls::TextControlPasteEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Paste(event_token token) = 0;
};

struct __declspec(uuid("7df18c3c-2826-425e-9a94-00b7f73f3756")) __declspec(novtable) ITextBox3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_TextCompositionStarted(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::TextBox, Windows::UI::Xaml::Controls::TextCompositionStartedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_TextCompositionStarted(event_token token) = 0;
    virtual HRESULT __stdcall add_TextCompositionChanged(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::TextBox, Windows::UI::Xaml::Controls::TextCompositionChangedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_TextCompositionChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_TextCompositionEnded(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::TextBox, Windows::UI::Xaml::Controls::TextCompositionEndedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_TextCompositionEnded(event_token token) = 0;
    virtual HRESULT __stdcall get_TextReadingOrder(winrt::Windows::UI::Xaml::TextReadingOrder * value) = 0;
    virtual HRESULT __stdcall put_TextReadingOrder(winrt::Windows::UI::Xaml::TextReadingOrder value) = 0;
    virtual HRESULT __stdcall get_DesiredCandidateWindowAlignment(winrt::Windows::UI::Xaml::Controls::CandidateWindowAlignment * value) = 0;
    virtual HRESULT __stdcall put_DesiredCandidateWindowAlignment(winrt::Windows::UI::Xaml::Controls::CandidateWindowAlignment value) = 0;
    virtual HRESULT __stdcall add_CandidateWindowBoundsChanged(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::TextBox, Windows::UI::Xaml::Controls::CandidateWindowBoundsChangedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_CandidateWindowBoundsChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_TextChanging(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::TextBox, Windows::UI::Xaml::Controls::TextBoxTextChangingEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_TextChanging(event_token token) = 0;
};

struct __declspec(uuid("b5f1a675-cce1-45af-aef9-c4787bbb5e30")) __declspec(novtable) ITextBox4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetLinguisticAlternativesAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<hstring>> ** returnValue) = 0;
};

struct __declspec(uuid("710e4278-8529-47d3-8d8e-307e34cff081")) __declspec(novtable) ITextBoxFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::ITextBox ** instance) = 0;
};

struct __declspec(uuid("7e37f4fb-a4bc-4625-8838-8eb2a9091283")) __declspec(novtable) ITextBoxStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TextProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MaxLengthProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsReadOnlyProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_AcceptsReturnProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TextAlignmentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TextWrappingProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsSpellCheckEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsTextPredictionEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_InputScopeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("7592f37d-4e76-4ee4-8e0f-7d6e1a23326b")) __declspec(novtable) ITextBoxStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_HeaderProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_HeaderTemplateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PlaceholderTextProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_SelectionHighlightColorProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PreventKeyboardDisplayOnProgrammaticFocusProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsColorFontEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("0e1005c0-10b5-40f6-92c2-ce134b0d3457")) __declspec(novtable) ITextBoxStatics3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DesiredCandidateWindowAlignmentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TextReadingOrderProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("4e6a4b75-43dd-4e33-acbe-2d8796a17927")) __declspec(novtable) ITextBoxTextChangingEventArgs : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("4dd04f7d-7a11-4b2e-9933-577df39252b6")) __declspec(novtable) ITextChangedEventArgs : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("b9c7e0f2-50b7-441d-990c-68553e2e056b")) __declspec(novtable) ITextCompositionChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_StartIndex(int32_t * value) = 0;
    virtual HRESULT __stdcall get_Length(int32_t * value) = 0;
};

struct __declspec(uuid("46e34db2-77c0-4015-8eb4-92eefdfc5914")) __declspec(novtable) ITextCompositionEndedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_StartIndex(int32_t * value) = 0;
    virtual HRESULT __stdcall get_Length(int32_t * value) = 0;
};

struct __declspec(uuid("df22abb2-10cf-491e-91e8-d3cd72d8a0d3")) __declspec(novtable) ITextCompositionStartedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_StartIndex(int32_t * value) = 0;
    virtual HRESULT __stdcall get_Length(int32_t * value) = 0;
};

struct __declspec(uuid("4bd1d625-221a-477e-bb2c-ad0c1ed125e7")) __declspec(novtable) ITextControlPasteEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Handled(bool * value) = 0;
    virtual HRESULT __stdcall put_Handled(bool value) = 0;
};

struct __declspec(uuid("8ad3ff21-5f66-4785-b999-24fef39fb6db")) __declspec(novtable) ITimePickedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_OldTime(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_NewTime(Windows::Foundation::TimeSpan * value) = 0;
};

struct __declspec(uuid("e39099f2-3aff-4792-909e-2d9941ec0357")) __declspec(novtable) ITimePicker : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Header(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_Header(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_HeaderTemplate(Windows::UI::Xaml::IDataTemplate ** value) = 0;
    virtual HRESULT __stdcall put_HeaderTemplate(Windows::UI::Xaml::IDataTemplate * value) = 0;
    virtual HRESULT __stdcall get_ClockIdentifier(hstring * value) = 0;
    virtual HRESULT __stdcall put_ClockIdentifier(hstring value) = 0;
    virtual HRESULT __stdcall get_MinuteIncrement(int32_t * value) = 0;
    virtual HRESULT __stdcall put_MinuteIncrement(int32_t value) = 0;
    virtual HRESULT __stdcall get_Time(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall put_Time(Windows::Foundation::TimeSpan value) = 0;
    virtual HRESULT __stdcall add_TimeChanged(Windows::Foundation::EventHandler<Windows::UI::Xaml::Controls::TimePickerValueChangedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_TimeChanged(event_token token) = 0;
};

struct __declspec(uuid("0ff0798c-f922-419f-8b3d-23ee7586d48e")) __declspec(novtable) ITimePicker2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LightDismissOverlayMode(winrt::Windows::UI::Xaml::Controls::LightDismissOverlayMode * value) = 0;
    virtual HRESULT __stdcall put_LightDismissOverlayMode(winrt::Windows::UI::Xaml::Controls::LightDismissOverlayMode value) = 0;
};

struct __declspec(uuid("553fe413-6cd7-46a9-a97b-a18bdc4b4ca3")) __declspec(novtable) ITimePickerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::ITimePicker ** instance) = 0;
};

struct __declspec(uuid("bb739d75-e836-439e-86d5-506d2d18e404")) __declspec(novtable) ITimePickerFlyout : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ClockIdentifier(hstring * value) = 0;
    virtual HRESULT __stdcall put_ClockIdentifier(hstring value) = 0;
    virtual HRESULT __stdcall get_Time(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall put_Time(Windows::Foundation::TimeSpan value) = 0;
    virtual HRESULT __stdcall get_MinuteIncrement(int32_t * value) = 0;
    virtual HRESULT __stdcall put_MinuteIncrement(int32_t value) = 0;
    virtual HRESULT __stdcall add_TimePicked(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::TimePickerFlyout, Windows::UI::Xaml::Controls::TimePickedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_TimePicked(event_token token) = 0;
    virtual HRESULT __stdcall abi_ShowAtAsync(Windows::UI::Xaml::IFrameworkElement * target, Windows::Foundation::IAsyncOperation<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> ** returnValue) = 0;
};

struct __declspec(uuid("c5320638-7a18-40ed-9fd0-4c852c09b24e")) __declspec(novtable) ITimePickerFlyoutPresenter : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("3f6728ce-2169-4003-b4a8-8de7035a0ad6")) __declspec(novtable) ITimePickerFlyoutStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ClockIdentifierProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TimeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MinuteIncrementProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("fa71dfb1-233e-4f31-b8be-a6ea670c25cd")) __declspec(novtable) ITimePickerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_HeaderProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_HeaderTemplateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ClockIdentifierProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MinuteIncrementProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TimeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("36d8abcd-4e10-451a-b93b-1a731ea7ee3f")) __declspec(novtable) ITimePickerStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LightDismissOverlayModeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("2f4edb8d-b995-4e31-8ba9-c4dcdeb21ca3")) __declspec(novtable) ITimePickerValueChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_OldTime(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_NewTime(Windows::Foundation::TimeSpan * value) = 0;
};

struct __declspec(uuid("49841edd-88e9-4663-a701-cd4fd25e398f")) __declspec(novtable) IToggleMenuFlyoutItem : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsChecked(bool * value) = 0;
    virtual HRESULT __stdcall put_IsChecked(bool value) = 0;
};

struct __declspec(uuid("a151966f-3bf7-46b6-b61c-9b2c1ba68843")) __declspec(novtable) IToggleMenuFlyoutItemFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IToggleMenuFlyoutItem ** instance) = 0;
};

struct __declspec(uuid("16c724fb-6c1a-4852-9258-08c038367907")) __declspec(novtable) IToggleMenuFlyoutItemStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsCheckedProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("331d8f00-c5f9-46a5-b6c8-ede539304567")) __declspec(novtable) IToggleSwitch : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsOn(bool * value) = 0;
    virtual HRESULT __stdcall put_IsOn(bool value) = 0;
    virtual HRESULT __stdcall get_Header(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_Header(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_HeaderTemplate(Windows::UI::Xaml::IDataTemplate ** value) = 0;
    virtual HRESULT __stdcall put_HeaderTemplate(Windows::UI::Xaml::IDataTemplate * value) = 0;
    virtual HRESULT __stdcall get_OnContent(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_OnContent(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_OnContentTemplate(Windows::UI::Xaml::IDataTemplate ** value) = 0;
    virtual HRESULT __stdcall put_OnContentTemplate(Windows::UI::Xaml::IDataTemplate * value) = 0;
    virtual HRESULT __stdcall get_OffContent(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_OffContent(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_OffContentTemplate(Windows::UI::Xaml::IDataTemplate ** value) = 0;
    virtual HRESULT __stdcall put_OffContentTemplate(Windows::UI::Xaml::IDataTemplate * value) = 0;
    virtual HRESULT __stdcall get_TemplateSettings(Windows::UI::Xaml::Controls::Primitives::IToggleSwitchTemplateSettings ** value) = 0;
    virtual HRESULT __stdcall add_Toggled(Windows::UI::Xaml::RoutedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Toggled(event_token token) = 0;
};

struct __declspec(uuid("bfd07f53-f8ca-4e47-949e-9e80429b3d16")) __declspec(novtable) IToggleSwitchOverrides : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_OnToggled() = 0;
    virtual HRESULT __stdcall abi_OnOnContentChanged(Windows::Foundation::IInspectable * oldContent, Windows::Foundation::IInspectable * newContent) = 0;
    virtual HRESULT __stdcall abi_OnOffContentChanged(Windows::Foundation::IInspectable * oldContent, Windows::Foundation::IInspectable * newContent) = 0;
    virtual HRESULT __stdcall abi_OnHeaderChanged(Windows::Foundation::IInspectable * oldContent, Windows::Foundation::IInspectable * newContent) = 0;
};

struct __declspec(uuid("1d37147f-97df-4226-92ca-ddf453d7fd5a")) __declspec(novtable) IToggleSwitchStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsOnProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_HeaderProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_HeaderTemplateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_OnContentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_OnContentTemplateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_OffContentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_OffContentTemplateProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("7de5d75f-4415-429f-b523-699bdb8c30db")) __declspec(novtable) IToolTip : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_HorizontalOffset(double * value) = 0;
    virtual HRESULT __stdcall put_HorizontalOffset(double value) = 0;
    virtual HRESULT __stdcall get_IsOpen(bool * value) = 0;
    virtual HRESULT __stdcall put_IsOpen(bool value) = 0;
    virtual HRESULT __stdcall get_Placement(winrt::Windows::UI::Xaml::Controls::Primitives::PlacementMode * value) = 0;
    virtual HRESULT __stdcall put_Placement(winrt::Windows::UI::Xaml::Controls::Primitives::PlacementMode value) = 0;
    virtual HRESULT __stdcall get_PlacementTarget(Windows::UI::Xaml::IUIElement ** value) = 0;
    virtual HRESULT __stdcall put_PlacementTarget(Windows::UI::Xaml::IUIElement * value) = 0;
    virtual HRESULT __stdcall get_VerticalOffset(double * value) = 0;
    virtual HRESULT __stdcall put_VerticalOffset(double value) = 0;
    virtual HRESULT __stdcall get_TemplateSettings(Windows::UI::Xaml::Controls::Primitives::IToolTipTemplateSettings ** value) = 0;
    virtual HRESULT __stdcall add_Closed(Windows::UI::Xaml::RoutedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Closed(event_token token) = 0;
    virtual HRESULT __stdcall add_Opened(Windows::UI::Xaml::RoutedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Opened(event_token token) = 0;
};

struct __declspec(uuid("89839403-b538-49e3-a430-3ac037dc6fe0")) __declspec(novtable) IToolTipFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IToolTip ** instance) = 0;
};

struct __declspec(uuid("03a55f87-bfcc-4a1e-8fea-98f610832cea")) __declspec(novtable) IToolTipService : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("86e649f8-e245-48aa-a8c8-d1073ed76319")) __declspec(novtable) IToolTipServiceStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PlacementProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetPlacement(Windows::UI::Xaml::IDependencyObject * element, winrt::Windows::UI::Xaml::Controls::Primitives::PlacementMode * value) = 0;
    virtual HRESULT __stdcall abi_SetPlacement(Windows::UI::Xaml::IDependencyObject * element, winrt::Windows::UI::Xaml::Controls::Primitives::PlacementMode value) = 0;
    virtual HRESULT __stdcall get_PlacementTargetProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetPlacementTarget(Windows::UI::Xaml::IDependencyObject * element, Windows::UI::Xaml::IUIElement ** value) = 0;
    virtual HRESULT __stdcall abi_SetPlacementTarget(Windows::UI::Xaml::IDependencyObject * element, Windows::UI::Xaml::IUIElement * value) = 0;
    virtual HRESULT __stdcall get_ToolTipProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetToolTip(Windows::UI::Xaml::IDependencyObject * element, Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall abi_SetToolTip(Windows::UI::Xaml::IDependencyObject * element, Windows::Foundation::IInspectable * value) = 0;
};

struct __declspec(uuid("f00285b8-4ba9-4f4f-86a7-86003813ceb3")) __declspec(novtable) IToolTipStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_HorizontalOffsetProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsOpenProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PlacementProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PlacementTargetProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_VerticalOffsetProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("d6602d54-88f6-43f6-85d8-a9d914a6dd3b")) __declspec(novtable) IUIElementCollection : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Move(uint32_t oldIndex, uint32_t newIndex) = 0;
};

struct __declspec(uuid("a7a69ec9-ea35-4679-bf29-f4f09286d314")) __declspec(novtable) IUserControl : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Content(Windows::UI::Xaml::IUIElement ** value) = 0;
    virtual HRESULT __stdcall put_Content(Windows::UI::Xaml::IUIElement * value) = 0;
};

struct __declspec(uuid("38b1ed92-a28a-4972-93df-f4f759b8afd2")) __declspec(novtable) IUserControlFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Controls::IUserControl ** instance) = 0;
};

struct __declspec(uuid("e8887976-2c5c-41cf-be6a-9e44befdf655")) __declspec(novtable) IUserControlStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ContentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("9ca507c7-23c9-4f01-b80f-be5c21eef474")) __declspec(novtable) IVariableSizedWrapGrid : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ItemHeight(double * value) = 0;
    virtual HRESULT __stdcall put_ItemHeight(double value) = 0;
    virtual HRESULT __stdcall get_ItemWidth(double * value) = 0;
    virtual HRESULT __stdcall put_ItemWidth(double value) = 0;
    virtual HRESULT __stdcall get_Orientation(winrt::Windows::UI::Xaml::Controls::Orientation * value) = 0;
    virtual HRESULT __stdcall put_Orientation(winrt::Windows::UI::Xaml::Controls::Orientation value) = 0;
    virtual HRESULT __stdcall get_HorizontalChildrenAlignment(winrt::Windows::UI::Xaml::HorizontalAlignment * value) = 0;
    virtual HRESULT __stdcall put_HorizontalChildrenAlignment(winrt::Windows::UI::Xaml::HorizontalAlignment value) = 0;
    virtual HRESULT __stdcall get_VerticalChildrenAlignment(winrt::Windows::UI::Xaml::VerticalAlignment * value) = 0;
    virtual HRESULT __stdcall put_VerticalChildrenAlignment(winrt::Windows::UI::Xaml::VerticalAlignment value) = 0;
    virtual HRESULT __stdcall get_MaximumRowsOrColumns(int32_t * value) = 0;
    virtual HRESULT __stdcall put_MaximumRowsOrColumns(int32_t value) = 0;
};

struct __declspec(uuid("fe9db859-8127-4aef-b7a2-949847486e96")) __declspec(novtable) IVariableSizedWrapGridStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ItemHeightProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ItemWidthProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_OrientationProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_HorizontalChildrenAlignmentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_VerticalChildrenAlignmentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MaximumRowsOrColumnsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_RowSpanProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetRowSpan(Windows::UI::Xaml::IUIElement * element, int32_t * value) = 0;
    virtual HRESULT __stdcall abi_SetRowSpan(Windows::UI::Xaml::IUIElement * element, int32_t value) = 0;
    virtual HRESULT __stdcall get_ColumnSpanProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetColumnSpan(Windows::UI::Xaml::IUIElement * element, int32_t * value) = 0;
    virtual HRESULT __stdcall abi_SetColumnSpan(Windows::UI::Xaml::IUIElement * element, int32_t value) = 0;
};

struct __declspec(uuid("05252c58-ba9d-4809-9ec3-fa0d16710ba1")) __declspec(novtable) IViewbox : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Child(Windows::UI::Xaml::IUIElement ** value) = 0;
    virtual HRESULT __stdcall put_Child(Windows::UI::Xaml::IUIElement * value) = 0;
    virtual HRESULT __stdcall get_Stretch(winrt::Windows::UI::Xaml::Media::Stretch * value) = 0;
    virtual HRESULT __stdcall put_Stretch(winrt::Windows::UI::Xaml::Media::Stretch value) = 0;
    virtual HRESULT __stdcall get_StretchDirection(winrt::Windows::UI::Xaml::Controls::StretchDirection * value) = 0;
    virtual HRESULT __stdcall put_StretchDirection(winrt::Windows::UI::Xaml::Controls::StretchDirection value) = 0;
};

struct __declspec(uuid("5cd1e72d-e8d3-4865-8f08-b6b2d689adf1")) __declspec(novtable) IViewboxStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_StretchProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_StretchDirectionProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("38aad50c-12cf-4d1e-a884-c9df85f07cd9")) __declspec(novtable) IVirtualizingPanel : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ItemContainerGenerator(Windows::UI::Xaml::Controls::IItemContainerGenerator ** value) = 0;
};

struct __declspec(uuid("be19f839-cbd0-43e9-a5d0-0bdba0ffbd38")) __declspec(novtable) IVirtualizingPanelFactory : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("5ef6bd7d-677f-408d-a96c-b19507750466")) __declspec(novtable) IVirtualizingPanelOverrides : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_OnItemsChanged(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::Controls::Primitives::IItemsChangedEventArgs * args) = 0;
    virtual HRESULT __stdcall abi_OnClearChildren() = 0;
    virtual HRESULT __stdcall abi_BringIndexIntoView(int32_t index) = 0;
};

struct __declspec(uuid("c9c9ab42-c232-479d-a7c9-5e7611196a45")) __declspec(novtable) IVirtualizingPanelProtected : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_AddInternalChild(Windows::UI::Xaml::IUIElement * child) = 0;
    virtual HRESULT __stdcall abi_InsertInternalChild(int32_t index, Windows::UI::Xaml::IUIElement * child) = 0;
    virtual HRESULT __stdcall abi_RemoveInternalChildRange(int32_t index, int32_t range) = 0;
};

struct __declspec(uuid("7567cd9a-a3b4-4dea-bb11-549e2c2f919d")) __declspec(novtable) IVirtualizingStackPanel : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AreScrollSnapPointsRegular(bool * value) = 0;
    virtual HRESULT __stdcall put_AreScrollSnapPointsRegular(bool value) = 0;
    virtual HRESULT __stdcall get_Orientation(winrt::Windows::UI::Xaml::Controls::Orientation * value) = 0;
    virtual HRESULT __stdcall put_Orientation(winrt::Windows::UI::Xaml::Controls::Orientation value) = 0;
    virtual HRESULT __stdcall add_CleanUpVirtualizedItemEvent(Windows::UI::Xaml::Controls::CleanUpVirtualizedItemEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_CleanUpVirtualizedItemEvent(event_token token) = 0;
};

struct __declspec(uuid("cbe6f72c-2892-46d1-987f-58ca1081f040")) __declspec(novtable) IVirtualizingStackPanelOverrides : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_OnCleanUpVirtualizedItem(Windows::UI::Xaml::Controls::ICleanUpVirtualizedItemEventArgs * e) = 0;
};

struct __declspec(uuid("8314e778-91d3-4d56-ac09-223adcd2bd3f")) __declspec(novtable) IVirtualizingStackPanelStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AreScrollSnapPointsRegularProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_OrientationProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_VirtualizationModeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetVirtualizationMode(Windows::UI::Xaml::IDependencyObject * element, winrt::Windows::UI::Xaml::Controls::VirtualizationMode * value) = 0;
    virtual HRESULT __stdcall abi_SetVirtualizationMode(Windows::UI::Xaml::IDependencyObject * element, winrt::Windows::UI::Xaml::Controls::VirtualizationMode value) = 0;
    virtual HRESULT __stdcall get_IsVirtualizingProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetIsVirtualizing(Windows::UI::Xaml::IDependencyObject * o, bool * value) = 0;
};

struct __declspec(uuid("5862cc46-1f7d-479b-92a6-de7858fe8d54")) __declspec(novtable) IWebView : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Source(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall put_Source(Windows::Foundation::IUriRuntimeClass * value) = 0;
    virtual HRESULT __stdcall get_AllowedScriptNotifyUris(Windows::Foundation::Collections::IVector<Windows::Foundation::Uri> ** value) = 0;
    virtual HRESULT __stdcall put_AllowedScriptNotifyUris(Windows::Foundation::Collections::IVector<Windows::Foundation::Uri> * value) = 0;
    virtual HRESULT __stdcall get_DataTransferPackage(Windows::ApplicationModel::DataTransfer::IDataPackage ** value) = 0;
    virtual HRESULT __stdcall add_LoadCompleted(Windows::UI::Xaml::Navigation::LoadCompletedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_LoadCompleted(event_token token) = 0;
    virtual HRESULT __stdcall add_ScriptNotify(Windows::UI::Xaml::Controls::NotifyEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ScriptNotify(event_token token) = 0;
    virtual HRESULT __stdcall add_NavigationFailed(Windows::UI::Xaml::Controls::WebViewNavigationFailedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_NavigationFailed(event_token token) = 0;
    virtual HRESULT __stdcall abi_InvokeScript(hstring scriptName, uint32_t __argumentsSize, hstring * arguments, hstring * returnValue) = 0;
    virtual HRESULT __stdcall abi_Navigate(Windows::Foundation::IUriRuntimeClass * source) = 0;
    virtual HRESULT __stdcall abi_NavigateToString(hstring text) = 0;
};

struct __declspec(uuid("d481759e-3eff-4462-823d-fd52f9ba4cc8")) __declspec(novtable) IWebView2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CanGoBack(bool * value) = 0;
    virtual HRESULT __stdcall get_CanGoForward(bool * value) = 0;
    virtual HRESULT __stdcall get_DocumentTitle(hstring * value) = 0;
    virtual HRESULT __stdcall add_NavigationStarting(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewNavigationStartingEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_NavigationStarting(event_token token) = 0;
    virtual HRESULT __stdcall add_ContentLoading(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewContentLoadingEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ContentLoading(event_token token) = 0;
    virtual HRESULT __stdcall add_DOMContentLoaded(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewDOMContentLoadedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DOMContentLoaded(event_token token) = 0;
    virtual HRESULT __stdcall abi_GoForward() = 0;
    virtual HRESULT __stdcall abi_GoBack() = 0;
    virtual HRESULT __stdcall abi_Refresh() = 0;
    virtual HRESULT __stdcall abi_Stop() = 0;
    virtual HRESULT __stdcall abi_CapturePreviewToStreamAsync(Windows::Storage::Streams::IRandomAccessStream * stream, Windows::Foundation::IAsyncAction ** returnValue) = 0;
    virtual HRESULT __stdcall abi_InvokeScriptAsync(hstring scriptName, Windows::Foundation::Collections::IIterable<hstring> * arguments, Windows::Foundation::IAsyncOperation<hstring> ** returnValue) = 0;
    virtual HRESULT __stdcall abi_CaptureSelectedContentToDataPackageAsync(Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::DataTransfer::DataPackage> ** returnValue) = 0;
    virtual HRESULT __stdcall abi_NavigateToLocalStreamUri(Windows::Foundation::IUriRuntimeClass * source, Windows::Web::IUriToStreamResolver * streamResolver) = 0;
    virtual HRESULT __stdcall abi_BuildLocalStreamUri(hstring contentIdentifier, hstring relativePath, Windows::Foundation::IUriRuntimeClass ** returnValue) = 0;
    virtual HRESULT __stdcall get_DefaultBackgroundColor(Windows::UI::Color * value) = 0;
    virtual HRESULT __stdcall put_DefaultBackgroundColor(Windows::UI::Color value) = 0;
    virtual HRESULT __stdcall add_NavigationCompleted(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewNavigationCompletedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_NavigationCompleted(event_token token) = 0;
    virtual HRESULT __stdcall add_FrameNavigationStarting(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewNavigationStartingEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_FrameNavigationStarting(event_token token) = 0;
    virtual HRESULT __stdcall add_FrameContentLoading(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewContentLoadingEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_FrameContentLoading(event_token token) = 0;
    virtual HRESULT __stdcall add_FrameDOMContentLoaded(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewDOMContentLoadedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_FrameDOMContentLoaded(event_token token) = 0;
    virtual HRESULT __stdcall add_FrameNavigationCompleted(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewNavigationCompletedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_FrameNavigationCompleted(event_token token) = 0;
    virtual HRESULT __stdcall add_LongRunningScriptDetected(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewLongRunningScriptDetectedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_LongRunningScriptDetected(event_token token) = 0;
    virtual HRESULT __stdcall add_UnsafeContentWarningDisplaying(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_UnsafeContentWarningDisplaying(event_token token) = 0;
    virtual HRESULT __stdcall add_UnviewableContentIdentified(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewUnviewableContentIdentifiedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_UnviewableContentIdentified(event_token token) = 0;
    virtual HRESULT __stdcall abi_NavigateWithHttpRequestMessage(Windows::Web::Http::IHttpRequestMessage * requestMessage) = 0;
    virtual HRESULT __stdcall abi_Focus(winrt::Windows::UI::Xaml::FocusState value, bool * returnValue) = 0;
};

struct __declspec(uuid("c497789b-b499-4d69-b5c2-ae9d5d6d594e")) __declspec(novtable) IWebView3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ContainsFullScreenElement(bool * value) = 0;
    virtual HRESULT __stdcall add_ContainsFullScreenElementChanged(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ContainsFullScreenElementChanged(event_token token) = 0;
};

struct __declspec(uuid("e28243bc-67f3-462a-b4e0-3bbf6c3dab0b")) __declspec(novtable) IWebView4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ExecutionMode(winrt::Windows::UI::Xaml::Controls::WebViewExecutionMode * value) = 0;
    virtual HRESULT __stdcall get_DeferredPermissionRequests(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::WebViewDeferredPermissionRequest> ** value) = 0;
    virtual HRESULT __stdcall get_Settings(Windows::UI::Xaml::Controls::IWebViewSettings ** value) = 0;
    virtual HRESULT __stdcall add_UnsupportedUriSchemeIdentified(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewUnsupportedUriSchemeIdentifiedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_UnsupportedUriSchemeIdentified(event_token token) = 0;
    virtual HRESULT __stdcall add_NewWindowRequested(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewNewWindowRequestedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_NewWindowRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_PermissionRequested(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewPermissionRequestedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PermissionRequested(event_token token) = 0;
    virtual HRESULT __stdcall abi_AddWebAllowedObject(hstring name, Windows::Foundation::IInspectable * pObject) = 0;
    virtual HRESULT __stdcall abi_DeferredPermissionRequestById(uint32_t id, Windows::UI::Xaml::Controls::IWebViewDeferredPermissionRequest ** returnValue) = 0;
};

struct __declspec(uuid("8c9884a6-2f3b-4a55-a463-8444c2095d00")) __declspec(novtable) IWebView5 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_XYFocusLeft(Windows::UI::Xaml::IDependencyObject ** value) = 0;
    virtual HRESULT __stdcall put_XYFocusLeft(Windows::UI::Xaml::IDependencyObject * value) = 0;
    virtual HRESULT __stdcall get_XYFocusRight(Windows::UI::Xaml::IDependencyObject ** value) = 0;
    virtual HRESULT __stdcall put_XYFocusRight(Windows::UI::Xaml::IDependencyObject * value) = 0;
    virtual HRESULT __stdcall get_XYFocusUp(Windows::UI::Xaml::IDependencyObject ** value) = 0;
    virtual HRESULT __stdcall put_XYFocusUp(Windows::UI::Xaml::IDependencyObject * value) = 0;
    virtual HRESULT __stdcall get_XYFocusDown(Windows::UI::Xaml::IDependencyObject ** value) = 0;
    virtual HRESULT __stdcall put_XYFocusDown(Windows::UI::Xaml::IDependencyObject * value) = 0;
};

struct __declspec(uuid("40e86f75-0cf4-4b72-a4d6-cf5d15780116")) __declspec(novtable) IWebViewBrush : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SourceName(hstring * value) = 0;
    virtual HRESULT __stdcall put_SourceName(hstring value) = 0;
    virtual HRESULT __stdcall abi_Redraw() = 0;
    virtual HRESULT __stdcall abi_SetSource(Windows::UI::Xaml::Controls::IWebView * source) = 0;
};

struct __declspec(uuid("d74daa24-1d05-463e-b028-6baa4420e762")) __declspec(novtable) IWebViewBrushStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SourceNameProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("6e2980bb-98b8-413e-8129-971c6f7e4c8a")) __declspec(novtable) IWebViewContentLoadingEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Uri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
};

struct __declspec(uuid("c47eba15-dc6b-4b36-9d80-82fb8817b988")) __declspec(novtable) IWebViewDOMContentLoadedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Uri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
};

struct __declspec(uuid("a3dcc461-7350-4d3a-8fb9-40eeec2746c2")) __declspec(novtable) IWebViewDeferredPermissionRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Uri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall get_PermissionType(winrt::Windows::UI::Xaml::Controls::WebViewPermissionType * value) = 0;
    virtual HRESULT __stdcall get_Id(uint32_t * value) = 0;
    virtual HRESULT __stdcall abi_Allow() = 0;
    virtual HRESULT __stdcall abi_Deny() = 0;
};

struct __declspec(uuid("82edac58-ee6a-4c9b-a3a0-9347a7d0ef4c")) __declspec(novtable) IWebViewFactory4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithExecutionMode(winrt::Windows::UI::Xaml::Controls::WebViewExecutionMode executionMode, Windows::UI::Xaml::Controls::IWebView ** instance) = 0;
};

struct __declspec(uuid("f3f020ab-a46c-42b0-9efe-69764d5cffa6")) __declspec(novtable) IWebViewLongRunningScriptDetectedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ExecutionTime(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_StopPageScriptExecution(bool * value) = 0;
    virtual HRESULT __stdcall put_StopPageScriptExecution(bool value) = 0;
};

struct __declspec(uuid("11e6f20b-eba7-44c0-889b-edeb6a064ddd")) __declspec(novtable) IWebViewNavigationCompletedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Uri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall get_IsSuccess(bool * value) = 0;
    virtual HRESULT __stdcall get_WebErrorStatus(winrt::Windows::Web::WebErrorStatus * value) = 0;
};

struct __declspec(uuid("af09609a-129c-4170-9e9c-e2cdf025dca4")) __declspec(novtable) IWebViewNavigationFailedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Uri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall get_WebErrorStatus(winrt::Windows::Web::WebErrorStatus * value) = 0;
};

struct __declspec(uuid("94cb8668-8367-43d5-91bb-96eba37ec784")) __declspec(novtable) IWebViewNavigationStartingEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Uri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall get_Cancel(bool * value) = 0;
    virtual HRESULT __stdcall put_Cancel(bool value) = 0;
};

struct __declspec(uuid("470fa818-6862-44d9-b3d1-c0696373de35")) __declspec(novtable) IWebViewNewWindowRequestedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Uri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall get_Referrer(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall get_Handled(bool * value) = 0;
    virtual HRESULT __stdcall put_Handled(bool value) = 0;
};

struct __declspec(uuid("17b76332-66c4-4131-999e-df7de20a8c9c")) __declspec(novtable) IWebViewPermissionRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Uri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall get_PermissionType(winrt::Windows::UI::Xaml::Controls::WebViewPermissionType * value) = 0;
    virtual HRESULT __stdcall get_Id(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_State(winrt::Windows::UI::Xaml::Controls::WebViewPermissionState * value) = 0;
    virtual HRESULT __stdcall abi_Defer() = 0;
    virtual HRESULT __stdcall abi_Allow() = 0;
    virtual HRESULT __stdcall abi_Deny() = 0;
};

struct __declspec(uuid("dadecfd0-6e1e-473f-b0be-b02404d6a86d")) __declspec(novtable) IWebViewPermissionRequestedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PermissionRequest(Windows::UI::Xaml::Controls::IWebViewPermissionRequest ** value) = 0;
};

struct __declspec(uuid("1d50ad4d-abf6-4785-8df3-fdebc1270301")) __declspec(novtable) IWebViewSettings : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsJavaScriptEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsJavaScriptEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsIndexedDBEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsIndexedDBEnabled(bool value) = 0;
};

struct __declspec(uuid("a0b561de-5fdb-443b-b9f0-5c30f6b7a1f4")) __declspec(novtable) IWebViewStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AnyScriptNotifyUri(Windows::Foundation::Collections::IVector<Windows::Foundation::Uri> ** value) = 0;
    virtual HRESULT __stdcall get_SourceProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_AllowedScriptNotifyUrisProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_DataTransferPackageProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("322f8780-e812-466b-9e50-8e9fec24018a")) __declspec(novtable) IWebViewStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CanGoBackProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CanGoForwardProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_DocumentTitleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_DefaultBackgroundColorProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("129bef8a-4509-4374-b0d1-a7104d0c3a2f")) __declspec(novtable) IWebViewStatics3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ContainsFullScreenElementProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("44b197b0-b746-40f3-9936-4ebbff6b47b8")) __declspec(novtable) IWebViewStatics4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DefaultExecutionMode(winrt::Windows::UI::Xaml::Controls::WebViewExecutionMode * value) = 0;
    virtual HRESULT __stdcall abi_ClearTemporaryWebDataAsync(Windows::Foundation::IAsyncAction ** returnValue) = 0;
};

struct __declspec(uuid("08a0b8d1-508a-4db8-97ef-0fa505e19ec2")) __declspec(novtable) IWebViewStatics5 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_XYFocusLeftProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_XYFocusRightProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_XYFocusUpProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_XYFocusDownProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("b9c9e1a7-620f-4895-935d-10fbac6fd29e")) __declspec(novtable) IWebViewUnsupportedUriSchemeIdentifiedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Uri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall get_Handled(bool * value) = 0;
    virtual HRESULT __stdcall put_Handled(bool value) = 0;
};

struct __declspec(uuid("37bc16e1-6062-4678-b20b-6c36ac9c59ac")) __declspec(novtable) IWebViewUnviewableContentIdentifiedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Uri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall get_Referrer(Windows::Foundation::IUriRuntimeClass ** value) = 0;
};

struct __declspec(uuid("9abe1154-36f0-4268-8d88-121eedf45e6a")) __declspec(novtable) IWebViewUnviewableContentIdentifiedEventArgs2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MediaType(hstring * value) = 0;
};

struct __declspec(uuid("0552178b-7567-47c2-bd5c-ad8394c828ba")) __declspec(novtable) IWrapGrid : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ItemWidth(double * value) = 0;
    virtual HRESULT __stdcall put_ItemWidth(double value) = 0;
    virtual HRESULT __stdcall get_ItemHeight(double * value) = 0;
    virtual HRESULT __stdcall put_ItemHeight(double value) = 0;
    virtual HRESULT __stdcall get_Orientation(winrt::Windows::UI::Xaml::Controls::Orientation * value) = 0;
    virtual HRESULT __stdcall put_Orientation(winrt::Windows::UI::Xaml::Controls::Orientation value) = 0;
    virtual HRESULT __stdcall get_HorizontalChildrenAlignment(winrt::Windows::UI::Xaml::HorizontalAlignment * value) = 0;
    virtual HRESULT __stdcall put_HorizontalChildrenAlignment(winrt::Windows::UI::Xaml::HorizontalAlignment value) = 0;
    virtual HRESULT __stdcall get_VerticalChildrenAlignment(winrt::Windows::UI::Xaml::VerticalAlignment * value) = 0;
    virtual HRESULT __stdcall put_VerticalChildrenAlignment(winrt::Windows::UI::Xaml::VerticalAlignment value) = 0;
    virtual HRESULT __stdcall get_MaximumRowsOrColumns(int32_t * value) = 0;
    virtual HRESULT __stdcall put_MaximumRowsOrColumns(int32_t value) = 0;
};

struct __declspec(uuid("d04a6b97-13cb-479c-a285-e4e56846c4cb")) __declspec(novtable) IWrapGridStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ItemWidthProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ItemHeightProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_OrientationProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_HorizontalChildrenAlignmentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_VerticalChildrenAlignmentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MaximumRowsOrColumnsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("3df6d14e-e18a-4a75-9395-627c5f3cd489")) __declspec(novtable) ItemClickEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::Controls::IItemClickEventArgs * e) = 0;
};

struct __declspec(uuid("6af5da76-7e8b-4a91-9a56-460cb47d523f")) __declspec(novtable) ListViewItemToKeyHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * item, hstring * returnValue) = 0;
};

struct __declspec(uuid("26fd5855-b530-4688-b9f0-428249178ef8")) __declspec(novtable) ListViewKeyToItemHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(hstring key, Windows::Foundation::IAsyncOperation<Windows::Foundation::IInspectable> ** returnValue) = 0;
};

struct __declspec(uuid("c2fdd1f8-7105-4a74-a109-de29dff56b98")) __declspec(novtable) NotifyEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::Controls::INotifyEventArgs * e) = 0;
};

struct __declspec(uuid("6becaa6a-63f8-47ff-b6ac-76e7da247d67")) __declspec(novtable) SectionsInViewChangedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::Controls::ISectionsInViewChangedEventArgs * e) = 0;
};

struct __declspec(uuid("e1a05352-5aa0-42ca-9cd9-068a14db6e68")) __declspec(novtable) SelectionChangedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::Controls::ISelectionChangedEventArgs * e) = 0;
};

struct __declspec(uuid("1fa9161d-5d73-44fb-81ac-d1c9384919d4")) __declspec(novtable) SemanticZoomViewChangedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::Controls::ISemanticZoomViewChangedEventArgs * e) = 0;
};

struct __declspec(uuid("8eb35b97-ad87-40e8-818b-77db24759566")) __declspec(novtable) TextChangedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::Controls::ITextChangedEventArgs * e) = 0;
};

struct __declspec(uuid("d56db359-6f77-4296-ab9c-794939444365")) __declspec(novtable) TextControlPasteEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::Controls::ITextControlPasteEventArgs * e) = 0;
};

struct __declspec(uuid("a31eafe1-41dc-47f8-ae22-9706c8f143d4")) __declspec(novtable) WebViewNavigationFailedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::Controls::IWebViewNavigationFailedEventArgs * e) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::UI::Xaml::Controls::AppBar> { using default_interface = Windows::UI::Xaml::Controls::IAppBar; };
template <> struct traits<Windows::UI::Xaml::Controls::AppBarButton> { using default_interface = Windows::UI::Xaml::Controls::IAppBarButton; };
template <> struct traits<Windows::UI::Xaml::Controls::AppBarSeparator> { using default_interface = Windows::UI::Xaml::Controls::IAppBarSeparator; };
template <> struct traits<Windows::UI::Xaml::Controls::AppBarToggleButton> { using default_interface = Windows::UI::Xaml::Controls::IAppBarToggleButton; };
template <> struct traits<Windows::UI::Xaml::Controls::AutoSuggestBox> { using default_interface = Windows::UI::Xaml::Controls::IAutoSuggestBox; };
template <> struct traits<Windows::UI::Xaml::Controls::AutoSuggestBoxQuerySubmittedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::IAutoSuggestBoxQuerySubmittedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::AutoSuggestBoxSuggestionChosenEventArgs> { using default_interface = Windows::UI::Xaml::Controls::IAutoSuggestBoxSuggestionChosenEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::AutoSuggestBoxTextChangedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::IAutoSuggestBoxTextChangedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::BackClickEventArgs> { using default_interface = Windows::UI::Xaml::Controls::IBackClickEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::BitmapIcon> { using default_interface = Windows::UI::Xaml::Controls::IBitmapIcon; };
template <> struct traits<Windows::UI::Xaml::Controls::Border> { using default_interface = Windows::UI::Xaml::Controls::IBorder; };
template <> struct traits<Windows::UI::Xaml::Controls::Button> { using default_interface = Windows::UI::Xaml::Controls::IButton; };
template <> struct traits<Windows::UI::Xaml::Controls::CalendarDatePicker> { using default_interface = Windows::UI::Xaml::Controls::ICalendarDatePicker; };
template <> struct traits<Windows::UI::Xaml::Controls::CalendarDatePickerDateChangedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::ICalendarDatePickerDateChangedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::CalendarView> { using default_interface = Windows::UI::Xaml::Controls::ICalendarView; };
template <> struct traits<Windows::UI::Xaml::Controls::CalendarViewDayItem> { using default_interface = Windows::UI::Xaml::Controls::ICalendarViewDayItem; };
template <> struct traits<Windows::UI::Xaml::Controls::CalendarViewDayItemChangingEventArgs> { using default_interface = Windows::UI::Xaml::Controls::ICalendarViewDayItemChangingEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::CalendarViewSelectedDatesChangedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::ICalendarViewSelectedDatesChangedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::CandidateWindowBoundsChangedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::ICandidateWindowBoundsChangedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::Canvas> { using default_interface = Windows::UI::Xaml::Controls::ICanvas; };
template <> struct traits<Windows::UI::Xaml::Controls::CaptureElement> { using default_interface = Windows::UI::Xaml::Controls::ICaptureElement; };
template <> struct traits<Windows::UI::Xaml::Controls::CheckBox> { using default_interface = Windows::UI::Xaml::Controls::ICheckBox; };
template <> struct traits<Windows::UI::Xaml::Controls::ChoosingGroupHeaderContainerEventArgs> { using default_interface = Windows::UI::Xaml::Controls::IChoosingGroupHeaderContainerEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::ChoosingItemContainerEventArgs> { using default_interface = Windows::UI::Xaml::Controls::IChoosingItemContainerEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::CleanUpVirtualizedItemEventArgs> { using default_interface = Windows::UI::Xaml::Controls::ICleanUpVirtualizedItemEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::ColumnDefinition> { using default_interface = Windows::UI::Xaml::Controls::IColumnDefinition; };
template <> struct traits<Windows::UI::Xaml::Controls::ColumnDefinitionCollection> { using default_interface = Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::ColumnDefinition>; };
template <> struct traits<Windows::UI::Xaml::Controls::ComboBox> { using default_interface = Windows::UI::Xaml::Controls::IComboBox; };
template <> struct traits<Windows::UI::Xaml::Controls::ComboBoxItem> { using default_interface = Windows::UI::Xaml::Controls::IComboBoxItem; };
template <> struct traits<Windows::UI::Xaml::Controls::CommandBar> { using default_interface = Windows::UI::Xaml::Controls::ICommandBar; };
template <> struct traits<Windows::UI::Xaml::Controls::CommandBarOverflowPresenter> { using default_interface = Windows::UI::Xaml::Controls::ICommandBarOverflowPresenter; };
template <> struct traits<Windows::UI::Xaml::Controls::ContainerContentChangingEventArgs> { using default_interface = Windows::UI::Xaml::Controls::IContainerContentChangingEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::ContentControl> { using default_interface = Windows::UI::Xaml::Controls::IContentControl; };
template <> struct traits<Windows::UI::Xaml::Controls::ContentDialog> { using default_interface = Windows::UI::Xaml::Controls::IContentDialog; };
template <> struct traits<Windows::UI::Xaml::Controls::ContentDialogButtonClickDeferral> { using default_interface = Windows::UI::Xaml::Controls::IContentDialogButtonClickDeferral; };
template <> struct traits<Windows::UI::Xaml::Controls::ContentDialogButtonClickEventArgs> { using default_interface = Windows::UI::Xaml::Controls::IContentDialogButtonClickEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::ContentDialogClosedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::IContentDialogClosedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::ContentDialogClosingDeferral> { using default_interface = Windows::UI::Xaml::Controls::IContentDialogClosingDeferral; };
template <> struct traits<Windows::UI::Xaml::Controls::ContentDialogClosingEventArgs> { using default_interface = Windows::UI::Xaml::Controls::IContentDialogClosingEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::ContentDialogOpenedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::IContentDialogOpenedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::ContentPresenter> { using default_interface = Windows::UI::Xaml::Controls::IContentPresenter; };
template <> struct traits<Windows::UI::Xaml::Controls::ContextMenuEventArgs> { using default_interface = Windows::UI::Xaml::Controls::IContextMenuEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::Control> { using default_interface = Windows::UI::Xaml::Controls::IControl; };
template <> struct traits<Windows::UI::Xaml::Controls::ControlTemplate> { using default_interface = Windows::UI::Xaml::Controls::IControlTemplate; };
template <> struct traits<Windows::UI::Xaml::Controls::DataTemplateSelector> { using default_interface = Windows::UI::Xaml::Controls::IDataTemplateSelector; };
template <> struct traits<Windows::UI::Xaml::Controls::DatePickedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::IDatePickedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::DatePicker> { using default_interface = Windows::UI::Xaml::Controls::IDatePicker; };
template <> struct traits<Windows::UI::Xaml::Controls::DatePickerFlyout> { using default_interface = Windows::UI::Xaml::Controls::IDatePickerFlyout; };
template <> struct traits<Windows::UI::Xaml::Controls::DatePickerFlyoutItem> { using default_interface = Windows::UI::Xaml::Controls::IDatePickerFlyoutItem; };
template <> struct traits<Windows::UI::Xaml::Controls::DatePickerFlyoutPresenter> { using default_interface = Windows::UI::Xaml::Controls::IDatePickerFlyoutPresenter; };
template <> struct traits<Windows::UI::Xaml::Controls::DatePickerValueChangedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::IDatePickerValueChangedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::DragItemsCompletedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::IDragItemsCompletedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::DragItemsStartingEventArgs> { using default_interface = Windows::UI::Xaml::Controls::IDragItemsStartingEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::DynamicOverflowItemsChangingEventArgs> { using default_interface = Windows::UI::Xaml::Controls::IDynamicOverflowItemsChangingEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::FlipView> { using default_interface = Windows::UI::Xaml::Controls::IFlipView; };
template <> struct traits<Windows::UI::Xaml::Controls::FlipViewItem> { using default_interface = Windows::UI::Xaml::Controls::IFlipViewItem; };
template <> struct traits<Windows::UI::Xaml::Controls::Flyout> { using default_interface = Windows::UI::Xaml::Controls::IFlyout; };
template <> struct traits<Windows::UI::Xaml::Controls::FlyoutPresenter> { using default_interface = Windows::UI::Xaml::Controls::IFlyoutPresenter; };
template <> struct traits<Windows::UI::Xaml::Controls::FocusDisengagedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::IFocusDisengagedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::FocusEngagedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::IFocusEngagedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::FontIcon> { using default_interface = Windows::UI::Xaml::Controls::IFontIcon; };
template <> struct traits<Windows::UI::Xaml::Controls::Frame> { using default_interface = Windows::UI::Xaml::Controls::IFrame; };
template <> struct traits<Windows::UI::Xaml::Controls::Grid> { using default_interface = Windows::UI::Xaml::Controls::IGrid; };
template <> struct traits<Windows::UI::Xaml::Controls::GridView> { using default_interface = Windows::UI::Xaml::Controls::IGridView; };
template <> struct traits<Windows::UI::Xaml::Controls::GridViewHeaderItem> { using default_interface = Windows::UI::Xaml::Controls::IGridViewHeaderItem; };
template <> struct traits<Windows::UI::Xaml::Controls::GridViewItem> { using default_interface = Windows::UI::Xaml::Controls::IGridViewItem; };
template <> struct traits<Windows::UI::Xaml::Controls::GroupItem> { using default_interface = Windows::UI::Xaml::Controls::IGroupItem; };
template <> struct traits<Windows::UI::Xaml::Controls::GroupStyle> { using default_interface = Windows::UI::Xaml::Controls::IGroupStyle; };
template <> struct traits<Windows::UI::Xaml::Controls::GroupStyleSelector> { using default_interface = Windows::UI::Xaml::Controls::IGroupStyleSelector; };
template <> struct traits<Windows::UI::Xaml::Controls::Hub> { using default_interface = Windows::UI::Xaml::Controls::IHub; };
template <> struct traits<Windows::UI::Xaml::Controls::HubSection> { using default_interface = Windows::UI::Xaml::Controls::IHubSection; };
template <> struct traits<Windows::UI::Xaml::Controls::HubSectionCollection> { using default_interface = Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::HubSection>; };
template <> struct traits<Windows::UI::Xaml::Controls::HubSectionHeaderClickEventArgs> { using default_interface = Windows::UI::Xaml::Controls::IHubSectionHeaderClickEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::HyperlinkButton> { using default_interface = Windows::UI::Xaml::Controls::IHyperlinkButton; };
template <> struct traits<Windows::UI::Xaml::Controls::IconElement> { using default_interface = Windows::UI::Xaml::Controls::IIconElement; };
template <> struct traits<Windows::UI::Xaml::Controls::Image> { using default_interface = Windows::UI::Xaml::Controls::IImage; };
template <> struct traits<Windows::UI::Xaml::Controls::InkCanvas> { using default_interface = Windows::UI::Xaml::Controls::IInkCanvas; };
template <> struct traits<Windows::UI::Xaml::Controls::InkToolbar> { using default_interface = Windows::UI::Xaml::Controls::IInkToolbar; };
template <> struct traits<Windows::UI::Xaml::Controls::InkToolbarBallpointPenButton> { using default_interface = Windows::UI::Xaml::Controls::IInkToolbarBallpointPenButton; };
template <> struct traits<Windows::UI::Xaml::Controls::InkToolbarCustomPen> { using default_interface = Windows::UI::Xaml::Controls::IInkToolbarCustomPen; };
template <> struct traits<Windows::UI::Xaml::Controls::InkToolbarCustomPenButton> { using default_interface = Windows::UI::Xaml::Controls::IInkToolbarCustomPenButton; };
template <> struct traits<Windows::UI::Xaml::Controls::InkToolbarCustomToggleButton> { using default_interface = Windows::UI::Xaml::Controls::IInkToolbarCustomToggleButton; };
template <> struct traits<Windows::UI::Xaml::Controls::InkToolbarCustomToolButton> { using default_interface = Windows::UI::Xaml::Controls::IInkToolbarCustomToolButton; };
template <> struct traits<Windows::UI::Xaml::Controls::InkToolbarEraserButton> { using default_interface = Windows::UI::Xaml::Controls::IInkToolbarEraserButton; };
template <> struct traits<Windows::UI::Xaml::Controls::InkToolbarHighlighterButton> { using default_interface = Windows::UI::Xaml::Controls::IInkToolbarHighlighterButton; };
template <> struct traits<Windows::UI::Xaml::Controls::InkToolbarPenButton> { using default_interface = Windows::UI::Xaml::Controls::IInkToolbarPenButton; };
template <> struct traits<Windows::UI::Xaml::Controls::InkToolbarPenConfigurationControl> { using default_interface = Windows::UI::Xaml::Controls::IInkToolbarPenConfigurationControl; };
template <> struct traits<Windows::UI::Xaml::Controls::InkToolbarPencilButton> { using default_interface = Windows::UI::Xaml::Controls::IInkToolbarPencilButton; };
template <> struct traits<Windows::UI::Xaml::Controls::InkToolbarRulerButton> { using default_interface = Windows::UI::Xaml::Controls::IInkToolbarRulerButton; };
template <> struct traits<Windows::UI::Xaml::Controls::InkToolbarToggleButton> { using default_interface = Windows::UI::Xaml::Controls::IInkToolbarToggleButton; };
template <> struct traits<Windows::UI::Xaml::Controls::InkToolbarToolButton> { using default_interface = Windows::UI::Xaml::Controls::IInkToolbarToolButton; };
template <> struct traits<Windows::UI::Xaml::Controls::ItemClickEventArgs> { using default_interface = Windows::UI::Xaml::Controls::IItemClickEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::ItemCollection> { using default_interface = Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable>; };
template <> struct traits<Windows::UI::Xaml::Controls::ItemContainerGenerator> { using default_interface = Windows::UI::Xaml::Controls::IItemContainerGenerator; };
template <> struct traits<Windows::UI::Xaml::Controls::ItemsControl> { using default_interface = Windows::UI::Xaml::Controls::IItemsControl; };
template <> struct traits<Windows::UI::Xaml::Controls::ItemsPanelTemplate> { using default_interface = Windows::UI::Xaml::Controls::IItemsPanelTemplate; };
template <> struct traits<Windows::UI::Xaml::Controls::ItemsPickedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::IItemsPickedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::ItemsPresenter> { using default_interface = Windows::UI::Xaml::Controls::IItemsPresenter; };
template <> struct traits<Windows::UI::Xaml::Controls::ItemsStackPanel> { using default_interface = Windows::UI::Xaml::Controls::IItemsStackPanel; };
template <> struct traits<Windows::UI::Xaml::Controls::ItemsWrapGrid> { using default_interface = Windows::UI::Xaml::Controls::IItemsWrapGrid; };
template <> struct traits<Windows::UI::Xaml::Controls::ListBox> { using default_interface = Windows::UI::Xaml::Controls::IListBox; };
template <> struct traits<Windows::UI::Xaml::Controls::ListBoxItem> { using default_interface = Windows::UI::Xaml::Controls::IListBoxItem; };
template <> struct traits<Windows::UI::Xaml::Controls::ListPickerFlyout> { using default_interface = Windows::UI::Xaml::Controls::IListPickerFlyout; };
template <> struct traits<Windows::UI::Xaml::Controls::ListPickerFlyoutPresenter> { using default_interface = Windows::UI::Xaml::Controls::IListPickerFlyoutPresenter; };
template <> struct traits<Windows::UI::Xaml::Controls::ListView> { using default_interface = Windows::UI::Xaml::Controls::IListView; };
template <> struct traits<Windows::UI::Xaml::Controls::ListViewBase> { using default_interface = Windows::UI::Xaml::Controls::IListViewBase; };
template <> struct traits<Windows::UI::Xaml::Controls::ListViewBaseHeaderItem> { using default_interface = Windows::UI::Xaml::Controls::IListViewBaseHeaderItem; };
template <> struct traits<Windows::UI::Xaml::Controls::ListViewHeaderItem> { using default_interface = Windows::UI::Xaml::Controls::IListViewHeaderItem; };
template <> struct traits<Windows::UI::Xaml::Controls::ListViewItem> { using default_interface = Windows::UI::Xaml::Controls::IListViewItem; };
template <> struct traits<Windows::UI::Xaml::Controls::ListViewPersistenceHelper> { using default_interface = Windows::UI::Xaml::Controls::IListViewPersistenceHelper; };
template <> struct traits<Windows::UI::Xaml::Controls::MediaElement> { using default_interface = Windows::UI::Xaml::Controls::IMediaElement; };
template <> struct traits<Windows::UI::Xaml::Controls::MediaPlayerElement> { using default_interface = Windows::UI::Xaml::Controls::IMediaPlayerElement; };
template <> struct traits<Windows::UI::Xaml::Controls::MediaPlayerPresenter> { using default_interface = Windows::UI::Xaml::Controls::IMediaPlayerPresenter; };
template <> struct traits<Windows::UI::Xaml::Controls::MediaTransportControls> { using default_interface = Windows::UI::Xaml::Controls::IMediaTransportControls; };
template <> struct traits<Windows::UI::Xaml::Controls::MediaTransportControlsHelper> { using default_interface = Windows::UI::Xaml::Controls::IMediaTransportControlsHelper; };
template <> struct traits<Windows::UI::Xaml::Controls::MenuFlyout> { using default_interface = Windows::UI::Xaml::Controls::IMenuFlyout; };
template <> struct traits<Windows::UI::Xaml::Controls::MenuFlyoutItem> { using default_interface = Windows::UI::Xaml::Controls::IMenuFlyoutItem; };
template <> struct traits<Windows::UI::Xaml::Controls::MenuFlyoutItemBase> { using default_interface = Windows::UI::Xaml::Controls::IMenuFlyoutItemBase; };
template <> struct traits<Windows::UI::Xaml::Controls::MenuFlyoutPresenter> { using default_interface = Windows::UI::Xaml::Controls::IMenuFlyoutPresenter; };
template <> struct traits<Windows::UI::Xaml::Controls::MenuFlyoutSeparator> { using default_interface = Windows::UI::Xaml::Controls::IMenuFlyoutSeparator; };
template <> struct traits<Windows::UI::Xaml::Controls::MenuFlyoutSubItem> { using default_interface = Windows::UI::Xaml::Controls::IMenuFlyoutSubItem; };
template <> struct traits<Windows::UI::Xaml::Controls::NotifyEventArgs> { using default_interface = Windows::UI::Xaml::Controls::INotifyEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::Page> { using default_interface = Windows::UI::Xaml::Controls::IPage; };
template <> struct traits<Windows::UI::Xaml::Controls::Panel> { using default_interface = Windows::UI::Xaml::Controls::IPanel; };
template <> struct traits<Windows::UI::Xaml::Controls::PasswordBox> { using default_interface = Windows::UI::Xaml::Controls::IPasswordBox; };
template <> struct traits<Windows::UI::Xaml::Controls::PathIcon> { using default_interface = Windows::UI::Xaml::Controls::IPathIcon; };
template <> struct traits<Windows::UI::Xaml::Controls::PickerConfirmedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::IPickerConfirmedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::PickerFlyout> { using default_interface = Windows::UI::Xaml::Controls::IPickerFlyout; };
template <> struct traits<Windows::UI::Xaml::Controls::PickerFlyoutPresenter> { using default_interface = Windows::UI::Xaml::Controls::IPickerFlyoutPresenter; };
template <> struct traits<Windows::UI::Xaml::Controls::Pivot> { using default_interface = Windows::UI::Xaml::Controls::IPivot; };
template <> struct traits<Windows::UI::Xaml::Controls::PivotItem> { using default_interface = Windows::UI::Xaml::Controls::IPivotItem; };
template <> struct traits<Windows::UI::Xaml::Controls::PivotItemEventArgs> { using default_interface = Windows::UI::Xaml::Controls::IPivotItemEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::ProgressBar> { using default_interface = Windows::UI::Xaml::Controls::IProgressBar; };
template <> struct traits<Windows::UI::Xaml::Controls::ProgressRing> { using default_interface = Windows::UI::Xaml::Controls::IProgressRing; };
template <> struct traits<Windows::UI::Xaml::Controls::RadioButton> { using default_interface = Windows::UI::Xaml::Controls::IRadioButton; };
template <> struct traits<Windows::UI::Xaml::Controls::RelativePanel> { using default_interface = Windows::UI::Xaml::Controls::IRelativePanel; };
template <> struct traits<Windows::UI::Xaml::Controls::RichEditBox> { using default_interface = Windows::UI::Xaml::Controls::IRichEditBox; };
template <> struct traits<Windows::UI::Xaml::Controls::RichEditBoxTextChangingEventArgs> { using default_interface = Windows::UI::Xaml::Controls::IRichEditBoxTextChangingEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::RichTextBlock> { using default_interface = Windows::UI::Xaml::Controls::IRichTextBlock; };
template <> struct traits<Windows::UI::Xaml::Controls::RichTextBlockOverflow> { using default_interface = Windows::UI::Xaml::Controls::IRichTextBlockOverflow; };
template <> struct traits<Windows::UI::Xaml::Controls::RowDefinition> { using default_interface = Windows::UI::Xaml::Controls::IRowDefinition; };
template <> struct traits<Windows::UI::Xaml::Controls::RowDefinitionCollection> { using default_interface = Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::RowDefinition>; };
template <> struct traits<Windows::UI::Xaml::Controls::ScrollContentPresenter> { using default_interface = Windows::UI::Xaml::Controls::IScrollContentPresenter; };
template <> struct traits<Windows::UI::Xaml::Controls::ScrollViewer> { using default_interface = Windows::UI::Xaml::Controls::IScrollViewer; };
template <> struct traits<Windows::UI::Xaml::Controls::ScrollViewerView> { using default_interface = Windows::UI::Xaml::Controls::IScrollViewerView; };
template <> struct traits<Windows::UI::Xaml::Controls::ScrollViewerViewChangedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::IScrollViewerViewChangedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::ScrollViewerViewChangingEventArgs> { using default_interface = Windows::UI::Xaml::Controls::IScrollViewerViewChangingEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::SearchBox> { using default_interface = Windows::UI::Xaml::Controls::ISearchBox; };
template <> struct traits<Windows::UI::Xaml::Controls::SearchBoxQueryChangedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::ISearchBoxQueryChangedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::SearchBoxQuerySubmittedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::ISearchBoxQuerySubmittedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::SearchBoxResultSuggestionChosenEventArgs> { using default_interface = Windows::UI::Xaml::Controls::ISearchBoxResultSuggestionChosenEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::SearchBoxSuggestionsRequestedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::ISearchBoxSuggestionsRequestedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::SectionsInViewChangedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::ISectionsInViewChangedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::SelectionChangedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::ISelectionChangedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::SemanticZoom> { using default_interface = Windows::UI::Xaml::Controls::ISemanticZoom; };
template <> struct traits<Windows::UI::Xaml::Controls::SemanticZoomLocation> { using default_interface = Windows::UI::Xaml::Controls::ISemanticZoomLocation; };
template <> struct traits<Windows::UI::Xaml::Controls::SemanticZoomViewChangedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::ISemanticZoomViewChangedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::SettingsFlyout> { using default_interface = Windows::UI::Xaml::Controls::ISettingsFlyout; };
template <> struct traits<Windows::UI::Xaml::Controls::Slider> { using default_interface = Windows::UI::Xaml::Controls::ISlider; };
template <> struct traits<Windows::UI::Xaml::Controls::SplitView> { using default_interface = Windows::UI::Xaml::Controls::ISplitView; };
template <> struct traits<Windows::UI::Xaml::Controls::SplitViewPaneClosingEventArgs> { using default_interface = Windows::UI::Xaml::Controls::ISplitViewPaneClosingEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::StackPanel> { using default_interface = Windows::UI::Xaml::Controls::IStackPanel; };
template <> struct traits<Windows::UI::Xaml::Controls::StyleSelector> { using default_interface = Windows::UI::Xaml::Controls::IStyleSelector; };
template <> struct traits<Windows::UI::Xaml::Controls::SwapChainBackgroundPanel> { using default_interface = Windows::UI::Xaml::Controls::ISwapChainBackgroundPanel; };
template <> struct traits<Windows::UI::Xaml::Controls::SwapChainPanel> { using default_interface = Windows::UI::Xaml::Controls::ISwapChainPanel; };
template <> struct traits<Windows::UI::Xaml::Controls::SymbolIcon> { using default_interface = Windows::UI::Xaml::Controls::ISymbolIcon; };
template <> struct traits<Windows::UI::Xaml::Controls::TextBlock> { using default_interface = Windows::UI::Xaml::Controls::ITextBlock; };
template <> struct traits<Windows::UI::Xaml::Controls::TextBox> { using default_interface = Windows::UI::Xaml::Controls::ITextBox; };
template <> struct traits<Windows::UI::Xaml::Controls::TextBoxTextChangingEventArgs> { using default_interface = Windows::UI::Xaml::Controls::ITextBoxTextChangingEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::TextChangedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::ITextChangedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::TextCompositionChangedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::ITextCompositionChangedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::TextCompositionEndedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::ITextCompositionEndedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::TextCompositionStartedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::ITextCompositionStartedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::TextControlPasteEventArgs> { using default_interface = Windows::UI::Xaml::Controls::ITextControlPasteEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::TimePickedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::ITimePickedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::TimePicker> { using default_interface = Windows::UI::Xaml::Controls::ITimePicker; };
template <> struct traits<Windows::UI::Xaml::Controls::TimePickerFlyout> { using default_interface = Windows::UI::Xaml::Controls::ITimePickerFlyout; };
template <> struct traits<Windows::UI::Xaml::Controls::TimePickerFlyoutPresenter> { using default_interface = Windows::UI::Xaml::Controls::ITimePickerFlyoutPresenter; };
template <> struct traits<Windows::UI::Xaml::Controls::TimePickerValueChangedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::ITimePickerValueChangedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::ToggleMenuFlyoutItem> { using default_interface = Windows::UI::Xaml::Controls::IToggleMenuFlyoutItem; };
template <> struct traits<Windows::UI::Xaml::Controls::ToggleSwitch> { using default_interface = Windows::UI::Xaml::Controls::IToggleSwitch; };
template <> struct traits<Windows::UI::Xaml::Controls::ToolTip> { using default_interface = Windows::UI::Xaml::Controls::IToolTip; };
template <> struct traits<Windows::UI::Xaml::Controls::ToolTipService> { using default_interface = Windows::UI::Xaml::Controls::IToolTipService; };
template <> struct traits<Windows::UI::Xaml::Controls::UIElementCollection> { using default_interface = Windows::Foundation::Collections::IVector<Windows::UI::Xaml::UIElement>; };
template <> struct traits<Windows::UI::Xaml::Controls::UserControl> { using default_interface = Windows::UI::Xaml::Controls::IUserControl; };
template <> struct traits<Windows::UI::Xaml::Controls::VariableSizedWrapGrid> { using default_interface = Windows::UI::Xaml::Controls::IVariableSizedWrapGrid; };
template <> struct traits<Windows::UI::Xaml::Controls::Viewbox> { using default_interface = Windows::UI::Xaml::Controls::IViewbox; };
template <> struct traits<Windows::UI::Xaml::Controls::VirtualizingPanel> { using default_interface = Windows::UI::Xaml::Controls::IVirtualizingPanel; };
template <> struct traits<Windows::UI::Xaml::Controls::VirtualizingStackPanel> { using default_interface = Windows::UI::Xaml::Controls::IVirtualizingStackPanel; };
template <> struct traits<Windows::UI::Xaml::Controls::WebView> { using default_interface = Windows::UI::Xaml::Controls::IWebView; };
template <> struct traits<Windows::UI::Xaml::Controls::WebViewBrush> { using default_interface = Windows::UI::Xaml::Controls::IWebViewBrush; };
template <> struct traits<Windows::UI::Xaml::Controls::WebViewContentLoadingEventArgs> { using default_interface = Windows::UI::Xaml::Controls::IWebViewContentLoadingEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::WebViewDOMContentLoadedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::IWebViewDOMContentLoadedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::WebViewDeferredPermissionRequest> { using default_interface = Windows::UI::Xaml::Controls::IWebViewDeferredPermissionRequest; };
template <> struct traits<Windows::UI::Xaml::Controls::WebViewLongRunningScriptDetectedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::IWebViewLongRunningScriptDetectedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::WebViewNavigationCompletedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::IWebViewNavigationCompletedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::WebViewNavigationFailedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::IWebViewNavigationFailedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::WebViewNavigationStartingEventArgs> { using default_interface = Windows::UI::Xaml::Controls::IWebViewNavigationStartingEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::WebViewNewWindowRequestedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::IWebViewNewWindowRequestedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::WebViewPermissionRequest> { using default_interface = Windows::UI::Xaml::Controls::IWebViewPermissionRequest; };
template <> struct traits<Windows::UI::Xaml::Controls::WebViewPermissionRequestedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::IWebViewPermissionRequestedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::WebViewSettings> { using default_interface = Windows::UI::Xaml::Controls::IWebViewSettings; };
template <> struct traits<Windows::UI::Xaml::Controls::WebViewUnsupportedUriSchemeIdentifiedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::IWebViewUnsupportedUriSchemeIdentifiedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::WebViewUnviewableContentIdentifiedEventArgs> { using default_interface = Windows::UI::Xaml::Controls::IWebViewUnviewableContentIdentifiedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Controls::WrapGrid> { using default_interface = Windows::UI::Xaml::Controls::IWrapGrid; };

}

namespace Windows::UI::Xaml::Controls {

template <typename D>
struct WINRT_EBO impl_IAppBar
{
    bool IsOpen() const;
    void IsOpen(bool value) const;
    bool IsSticky() const;
    void IsSticky(bool value) const;
    event_token Opened(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const;
    using Opened_revoker = event_revoker<IAppBar>;
    Opened_revoker Opened(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const;
    void Opened(event_token token) const;
    event_token Closed(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const;
    using Closed_revoker = event_revoker<IAppBar>;
    Closed_revoker Closed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const;
    void Closed(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IAppBar2
{
    Windows::UI::Xaml::Controls::AppBarClosedDisplayMode ClosedDisplayMode() const;
    void ClosedDisplayMode(Windows::UI::Xaml::Controls::AppBarClosedDisplayMode value) const;
};

template <typename D>
struct WINRT_EBO impl_IAppBar3
{
    Windows::UI::Xaml::Controls::Primitives::AppBarTemplateSettings TemplateSettings() const;
    event_token Opening(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const;
    using Opening_revoker = event_revoker<IAppBar3>;
    Opening_revoker Opening(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const;
    void Opening(event_token token) const;
    event_token Closing(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const;
    using Closing_revoker = event_revoker<IAppBar3>;
    Closing_revoker Closing(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const;
    void Closing(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IAppBar4
{
    Windows::UI::Xaml::Controls::LightDismissOverlayMode LightDismissOverlayMode() const;
    void LightDismissOverlayMode(Windows::UI::Xaml::Controls::LightDismissOverlayMode value) const;
};

template <typename D>
struct WINRT_EBO impl_IAppBarButton
{
    hstring Label() const;
    void Label(hstring_view value) const;
    Windows::UI::Xaml::Controls::IconElement Icon() const;
    void Icon(const Windows::UI::Xaml::Controls::IconElement & value) const;
};

template <typename D>
struct WINRT_EBO impl_IAppBarButton3
{
    Windows::UI::Xaml::Controls::CommandBarLabelPosition LabelPosition() const;
    void LabelPosition(Windows::UI::Xaml::Controls::CommandBarLabelPosition value) const;
};

template <typename D>
struct WINRT_EBO impl_IAppBarButtonFactory
{
    Windows::UI::Xaml::Controls::AppBarButton CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IAppBarButtonStatics
{
    Windows::UI::Xaml::DependencyProperty LabelProperty() const;
    Windows::UI::Xaml::DependencyProperty IconProperty() const;
    Windows::UI::Xaml::DependencyProperty IsCompactProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IAppBarButtonStatics3
{
    Windows::UI::Xaml::DependencyProperty LabelPositionProperty() const;
    Windows::UI::Xaml::DependencyProperty IsInOverflowProperty() const;
    Windows::UI::Xaml::DependencyProperty DynamicOverflowOrderProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IAppBarFactory
{
    Windows::UI::Xaml::Controls::AppBar CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IAppBarOverrides
{
    void OnClosed(const Windows::Foundation::IInspectable & e) const;
    void OnOpened(const Windows::Foundation::IInspectable & e) const;
};

template <typename D>
struct WINRT_EBO impl_IAppBarOverrides3
{
    void OnClosing(const Windows::Foundation::IInspectable & e) const;
    void OnOpening(const Windows::Foundation::IInspectable & e) const;
};

template <typename D>
struct WINRT_EBO impl_IAppBarSeparator
{
};

template <typename D>
struct WINRT_EBO impl_IAppBarSeparatorFactory
{
    Windows::UI::Xaml::Controls::AppBarSeparator CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IAppBarSeparatorStatics
{
    Windows::UI::Xaml::DependencyProperty IsCompactProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IAppBarSeparatorStatics3
{
    Windows::UI::Xaml::DependencyProperty IsInOverflowProperty() const;
    Windows::UI::Xaml::DependencyProperty DynamicOverflowOrderProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IAppBarStatics
{
    Windows::UI::Xaml::DependencyProperty IsOpenProperty() const;
    Windows::UI::Xaml::DependencyProperty IsStickyProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IAppBarStatics2
{
    Windows::UI::Xaml::DependencyProperty ClosedDisplayModeProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IAppBarStatics4
{
    Windows::UI::Xaml::DependencyProperty LightDismissOverlayModeProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IAppBarToggleButton
{
    hstring Label() const;
    void Label(hstring_view value) const;
    Windows::UI::Xaml::Controls::IconElement Icon() const;
    void Icon(const Windows::UI::Xaml::Controls::IconElement & value) const;
};

template <typename D>
struct WINRT_EBO impl_IAppBarToggleButton3
{
    Windows::UI::Xaml::Controls::CommandBarLabelPosition LabelPosition() const;
    void LabelPosition(Windows::UI::Xaml::Controls::CommandBarLabelPosition value) const;
};

template <typename D>
struct WINRT_EBO impl_IAppBarToggleButtonFactory
{
    Windows::UI::Xaml::Controls::AppBarToggleButton CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IAppBarToggleButtonStatics
{
    Windows::UI::Xaml::DependencyProperty LabelProperty() const;
    Windows::UI::Xaml::DependencyProperty IconProperty() const;
    Windows::UI::Xaml::DependencyProperty IsCompactProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IAppBarToggleButtonStatics3
{
    Windows::UI::Xaml::DependencyProperty LabelPositionProperty() const;
    Windows::UI::Xaml::DependencyProperty IsInOverflowProperty() const;
    Windows::UI::Xaml::DependencyProperty DynamicOverflowOrderProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IAutoSuggestBox
{
    double MaxSuggestionListHeight() const;
    void MaxSuggestionListHeight(double value) const;
    bool IsSuggestionListOpen() const;
    void IsSuggestionListOpen(bool value) const;
    hstring TextMemberPath() const;
    void TextMemberPath(hstring_view value) const;
    hstring Text() const;
    void Text(hstring_view value) const;
    bool UpdateTextOnSelect() const;
    void UpdateTextOnSelect(bool value) const;
    hstring PlaceholderText() const;
    void PlaceholderText(hstring_view value) const;
    Windows::Foundation::IInspectable Header() const;
    void Header(const Windows::Foundation::IInspectable & value) const;
    bool AutoMaximizeSuggestionArea() const;
    void AutoMaximizeSuggestionArea(bool value) const;
    Windows::UI::Xaml::Style TextBoxStyle() const;
    void TextBoxStyle(const Windows::UI::Xaml::Style & value) const;
    event_token SuggestionChosen(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::AutoSuggestBox, Windows::UI::Xaml::Controls::AutoSuggestBoxSuggestionChosenEventArgs> & value) const;
    using SuggestionChosen_revoker = event_revoker<IAutoSuggestBox>;
    SuggestionChosen_revoker SuggestionChosen(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::AutoSuggestBox, Windows::UI::Xaml::Controls::AutoSuggestBoxSuggestionChosenEventArgs> & value) const;
    void SuggestionChosen(event_token token) const;
    event_token TextChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::AutoSuggestBox, Windows::UI::Xaml::Controls::AutoSuggestBoxTextChangedEventArgs> & value) const;
    using TextChanged_revoker = event_revoker<IAutoSuggestBox>;
    TextChanged_revoker TextChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::AutoSuggestBox, Windows::UI::Xaml::Controls::AutoSuggestBoxTextChangedEventArgs> & value) const;
    void TextChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IAutoSuggestBox2
{
    Windows::UI::Xaml::Controls::IconElement QueryIcon() const;
    void QueryIcon(const Windows::UI::Xaml::Controls::IconElement & value) const;
    event_token QuerySubmitted(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::AutoSuggestBox, Windows::UI::Xaml::Controls::AutoSuggestBoxQuerySubmittedEventArgs> & value) const;
    using QuerySubmitted_revoker = event_revoker<IAutoSuggestBox2>;
    QuerySubmitted_revoker QuerySubmitted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::AutoSuggestBox, Windows::UI::Xaml::Controls::AutoSuggestBoxQuerySubmittedEventArgs> & value) const;
    void QuerySubmitted(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IAutoSuggestBox3
{
    Windows::UI::Xaml::Controls::LightDismissOverlayMode LightDismissOverlayMode() const;
    void LightDismissOverlayMode(Windows::UI::Xaml::Controls::LightDismissOverlayMode value) const;
};

template <typename D>
struct WINRT_EBO impl_IAutoSuggestBoxQuerySubmittedEventArgs
{
    hstring QueryText() const;
    Windows::Foundation::IInspectable ChosenSuggestion() const;
};

template <typename D>
struct WINRT_EBO impl_IAutoSuggestBoxStatics
{
    Windows::UI::Xaml::DependencyProperty MaxSuggestionListHeightProperty() const;
    Windows::UI::Xaml::DependencyProperty IsSuggestionListOpenProperty() const;
    Windows::UI::Xaml::DependencyProperty TextMemberPathProperty() const;
    Windows::UI::Xaml::DependencyProperty TextProperty() const;
    Windows::UI::Xaml::DependencyProperty UpdateTextOnSelectProperty() const;
    Windows::UI::Xaml::DependencyProperty PlaceholderTextProperty() const;
    Windows::UI::Xaml::DependencyProperty HeaderProperty() const;
    Windows::UI::Xaml::DependencyProperty AutoMaximizeSuggestionAreaProperty() const;
    Windows::UI::Xaml::DependencyProperty TextBoxStyleProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IAutoSuggestBoxStatics2
{
    Windows::UI::Xaml::DependencyProperty QueryIconProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IAutoSuggestBoxStatics3
{
    Windows::UI::Xaml::DependencyProperty LightDismissOverlayModeProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IAutoSuggestBoxSuggestionChosenEventArgs
{
    Windows::Foundation::IInspectable SelectedItem() const;
};

template <typename D>
struct WINRT_EBO impl_IAutoSuggestBoxTextChangedEventArgs
{
    Windows::UI::Xaml::Controls::AutoSuggestionBoxTextChangeReason Reason() const;
    void Reason(Windows::UI::Xaml::Controls::AutoSuggestionBoxTextChangeReason value) const;
    bool CheckCurrent() const;
};

template <typename D>
struct WINRT_EBO impl_IAutoSuggestBoxTextChangedEventArgsStatics
{
    Windows::UI::Xaml::DependencyProperty ReasonProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IBackClickEventArgs
{
    bool Handled() const;
    void Handled(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IBitmapIcon
{
    Windows::Foundation::Uri UriSource() const;
    void UriSource(const Windows::Foundation::Uri & value) const;
};

template <typename D>
struct WINRT_EBO impl_IBitmapIconFactory
{
    Windows::UI::Xaml::Controls::BitmapIcon CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IBitmapIconStatics
{
    Windows::UI::Xaml::DependencyProperty UriSourceProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IBorder
{
    Windows::UI::Xaml::Media::Brush BorderBrush() const;
    void BorderBrush(const Windows::UI::Xaml::Media::Brush & value) const;
    Windows::UI::Xaml::Thickness BorderThickness() const;
    void BorderThickness(const Windows::UI::Xaml::Thickness & value) const;
    Windows::UI::Xaml::Media::Brush Background() const;
    void Background(const Windows::UI::Xaml::Media::Brush & value) const;
    Windows::UI::Xaml::CornerRadius CornerRadius() const;
    void CornerRadius(const Windows::UI::Xaml::CornerRadius & value) const;
    Windows::UI::Xaml::Thickness Padding() const;
    void Padding(const Windows::UI::Xaml::Thickness & value) const;
    Windows::UI::Xaml::UIElement Child() const;
    void Child(const Windows::UI::Xaml::UIElement & value) const;
    Windows::UI::Xaml::Media::Animation::TransitionCollection ChildTransitions() const;
    void ChildTransitions(const Windows::UI::Xaml::Media::Animation::TransitionCollection & value) const;
};

template <typename D>
struct WINRT_EBO impl_IBorderStatics
{
    Windows::UI::Xaml::DependencyProperty BorderBrushProperty() const;
    Windows::UI::Xaml::DependencyProperty BorderThicknessProperty() const;
    Windows::UI::Xaml::DependencyProperty BackgroundProperty() const;
    Windows::UI::Xaml::DependencyProperty CornerRadiusProperty() const;
    Windows::UI::Xaml::DependencyProperty PaddingProperty() const;
    Windows::UI::Xaml::DependencyProperty ChildTransitionsProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IButton
{
};

template <typename D>
struct WINRT_EBO impl_IButtonFactory
{
    Windows::UI::Xaml::Controls::Button CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IButtonStaticsWithFlyout
{
    Windows::UI::Xaml::DependencyProperty FlyoutProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IButtonWithFlyout
{
    Windows::UI::Xaml::Controls::Primitives::FlyoutBase Flyout() const;
    void Flyout(const Windows::UI::Xaml::Controls::Primitives::FlyoutBase & value) const;
};

template <typename D>
struct WINRT_EBO impl_ICalendarDatePicker
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> Date() const;
    void Date(const optional<Windows::Foundation::DateTime> & value) const;
    bool IsCalendarOpen() const;
    void IsCalendarOpen(bool value) const;
    hstring DateFormat() const;
    void DateFormat(hstring_view value) const;
    hstring PlaceholderText() const;
    void PlaceholderText(hstring_view value) const;
    Windows::Foundation::IInspectable Header() const;
    void Header(const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::DataTemplate HeaderTemplate() const;
    void HeaderTemplate(const Windows::UI::Xaml::DataTemplate & value) const;
    Windows::UI::Xaml::Style CalendarViewStyle() const;
    void CalendarViewStyle(const Windows::UI::Xaml::Style & value) const;
    Windows::Foundation::DateTime MinDate() const;
    void MinDate(const Windows::Foundation::DateTime & value) const;
    Windows::Foundation::DateTime MaxDate() const;
    void MaxDate(const Windows::Foundation::DateTime & value) const;
    bool IsTodayHighlighted() const;
    void IsTodayHighlighted(bool value) const;
    Windows::UI::Xaml::Controls::CalendarViewDisplayMode DisplayMode() const;
    void DisplayMode(Windows::UI::Xaml::Controls::CalendarViewDisplayMode value) const;
    Windows::Globalization::DayOfWeek FirstDayOfWeek() const;
    void FirstDayOfWeek(Windows::Globalization::DayOfWeek value) const;
    hstring DayOfWeekFormat() const;
    void DayOfWeekFormat(hstring_view value) const;
    hstring CalendarIdentifier() const;
    void CalendarIdentifier(hstring_view value) const;
    bool IsOutOfScopeEnabled() const;
    void IsOutOfScopeEnabled(bool value) const;
    bool IsGroupLabelVisible() const;
    void IsGroupLabelVisible(bool value) const;
    event_token CalendarViewDayItemChanging(const Windows::UI::Xaml::Controls::CalendarViewDayItemChangingEventHandler & value) const;
    using CalendarViewDayItemChanging_revoker = event_revoker<ICalendarDatePicker>;
    CalendarViewDayItemChanging_revoker CalendarViewDayItemChanging(auto_revoke_t, const Windows::UI::Xaml::Controls::CalendarViewDayItemChangingEventHandler & value) const;
    void CalendarViewDayItemChanging(event_token token) const;
    event_token DateChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::CalendarDatePicker, Windows::UI::Xaml::Controls::CalendarDatePickerDateChangedEventArgs> & value) const;
    using DateChanged_revoker = event_revoker<ICalendarDatePicker>;
    DateChanged_revoker DateChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::CalendarDatePicker, Windows::UI::Xaml::Controls::CalendarDatePickerDateChangedEventArgs> & value) const;
    void DateChanged(event_token token) const;
    event_token Opened(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const;
    using Opened_revoker = event_revoker<ICalendarDatePicker>;
    Opened_revoker Opened(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const;
    void Opened(event_token token) const;
    event_token Closed(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const;
    using Closed_revoker = event_revoker<ICalendarDatePicker>;
    Closed_revoker Closed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const;
    void Closed(event_token token) const;
    void SetDisplayDate(const Windows::Foundation::DateTime & date) const;
    void SetYearDecadeDisplayDimensions(int32_t columns, int32_t rows) const;
};

template <typename D>
struct WINRT_EBO impl_ICalendarDatePicker2
{
    Windows::UI::Xaml::Controls::LightDismissOverlayMode LightDismissOverlayMode() const;
    void LightDismissOverlayMode(Windows::UI::Xaml::Controls::LightDismissOverlayMode value) const;
};

template <typename D>
struct WINRT_EBO impl_ICalendarDatePickerDateChangedEventArgs
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> NewDate() const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> OldDate() const;
};

template <typename D>
struct WINRT_EBO impl_ICalendarDatePickerFactory
{
    Windows::UI::Xaml::Controls::CalendarDatePicker CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_ICalendarDatePickerStatics
{
    Windows::UI::Xaml::DependencyProperty DateProperty() const;
    Windows::UI::Xaml::DependencyProperty IsCalendarOpenProperty() const;
    Windows::UI::Xaml::DependencyProperty DateFormatProperty() const;
    Windows::UI::Xaml::DependencyProperty PlaceholderTextProperty() const;
    Windows::UI::Xaml::DependencyProperty HeaderProperty() const;
    Windows::UI::Xaml::DependencyProperty HeaderTemplateProperty() const;
    Windows::UI::Xaml::DependencyProperty CalendarViewStyleProperty() const;
    Windows::UI::Xaml::DependencyProperty MinDateProperty() const;
    Windows::UI::Xaml::DependencyProperty MaxDateProperty() const;
    Windows::UI::Xaml::DependencyProperty IsTodayHighlightedProperty() const;
    Windows::UI::Xaml::DependencyProperty DisplayModeProperty() const;
    Windows::UI::Xaml::DependencyProperty FirstDayOfWeekProperty() const;
    Windows::UI::Xaml::DependencyProperty DayOfWeekFormatProperty() const;
    Windows::UI::Xaml::DependencyProperty CalendarIdentifierProperty() const;
    Windows::UI::Xaml::DependencyProperty IsOutOfScopeEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty IsGroupLabelVisibleProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ICalendarDatePickerStatics2
{
    Windows::UI::Xaml::DependencyProperty LightDismissOverlayModeProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ICalendarView
{
    hstring CalendarIdentifier() const;
    void CalendarIdentifier(hstring_view value) const;
    hstring DayOfWeekFormat() const;
    void DayOfWeekFormat(hstring_view value) const;
    bool IsGroupLabelVisible() const;
    void IsGroupLabelVisible(bool value) const;
    Windows::UI::Xaml::Controls::CalendarViewDisplayMode DisplayMode() const;
    void DisplayMode(Windows::UI::Xaml::Controls::CalendarViewDisplayMode value) const;
    Windows::Globalization::DayOfWeek FirstDayOfWeek() const;
    void FirstDayOfWeek(Windows::Globalization::DayOfWeek value) const;
    bool IsOutOfScopeEnabled() const;
    void IsOutOfScopeEnabled(bool value) const;
    bool IsTodayHighlighted() const;
    void IsTodayHighlighted(bool value) const;
    Windows::Foundation::DateTime MaxDate() const;
    void MaxDate(const Windows::Foundation::DateTime & value) const;
    Windows::Foundation::DateTime MinDate() const;
    void MinDate(const Windows::Foundation::DateTime & value) const;
    int32_t NumberOfWeeksInView() const;
    void NumberOfWeeksInView(int32_t value) const;
    Windows::Foundation::Collections::IVector<Windows::Foundation::DateTime> SelectedDates() const;
    Windows::UI::Xaml::Controls::CalendarViewSelectionMode SelectionMode() const;
    void SelectionMode(Windows::UI::Xaml::Controls::CalendarViewSelectionMode value) const;
    Windows::UI::Xaml::Controls::Primitives::CalendarViewTemplateSettings TemplateSettings() const;
    Windows::UI::Xaml::Media::Brush FocusBorderBrush() const;
    void FocusBorderBrush(const Windows::UI::Xaml::Media::Brush & value) const;
    Windows::UI::Xaml::Media::Brush SelectedHoverBorderBrush() const;
    void SelectedHoverBorderBrush(const Windows::UI::Xaml::Media::Brush & value) const;
    Windows::UI::Xaml::Media::Brush SelectedPressedBorderBrush() const;
    void SelectedPressedBorderBrush(const Windows::UI::Xaml::Media::Brush & value) const;
    Windows::UI::Xaml::Media::Brush SelectedBorderBrush() const;
    void SelectedBorderBrush(const Windows::UI::Xaml::Media::Brush & value) const;
    Windows::UI::Xaml::Media::Brush HoverBorderBrush() const;
    void HoverBorderBrush(const Windows::UI::Xaml::Media::Brush & value) const;
    Windows::UI::Xaml::Media::Brush PressedBorderBrush() const;
    void PressedBorderBrush(const Windows::UI::Xaml::Media::Brush & value) const;
    Windows::UI::Xaml::Media::Brush CalendarItemBorderBrush() const;
    void CalendarItemBorderBrush(const Windows::UI::Xaml::Media::Brush & value) const;
    Windows::UI::Xaml::Media::Brush OutOfScopeBackground() const;
    void OutOfScopeBackground(const Windows::UI::Xaml::Media::Brush & value) const;
    Windows::UI::Xaml::Media::Brush CalendarItemBackground() const;
    void CalendarItemBackground(const Windows::UI::Xaml::Media::Brush & value) const;
    Windows::UI::Xaml::Media::Brush PressedForeground() const;
    void PressedForeground(const Windows::UI::Xaml::Media::Brush & value) const;
    Windows::UI::Xaml::Media::Brush TodayForeground() const;
    void TodayForeground(const Windows::UI::Xaml::Media::Brush & value) const;
    Windows::UI::Xaml::Media::Brush BlackoutForeground() const;
    void BlackoutForeground(const Windows::UI::Xaml::Media::Brush & value) const;
    Windows::UI::Xaml::Media::Brush SelectedForeground() const;
    void SelectedForeground(const Windows::UI::Xaml::Media::Brush & value) const;
    Windows::UI::Xaml::Media::Brush OutOfScopeForeground() const;
    void OutOfScopeForeground(const Windows::UI::Xaml::Media::Brush & value) const;
    Windows::UI::Xaml::Media::Brush CalendarItemForeground() const;
    void CalendarItemForeground(const Windows::UI::Xaml::Media::Brush & value) const;
    Windows::UI::Xaml::Media::FontFamily DayItemFontFamily() const;
    void DayItemFontFamily(const Windows::UI::Xaml::Media::FontFamily & value) const;
    double DayItemFontSize() const;
    void DayItemFontSize(double value) const;
    Windows::UI::Text::FontStyle DayItemFontStyle() const;
    void DayItemFontStyle(Windows::UI::Text::FontStyle value) const;
    Windows::UI::Text::FontWeight DayItemFontWeight() const;
    void DayItemFontWeight(const Windows::UI::Text::FontWeight & value) const;
    Windows::UI::Text::FontWeight TodayFontWeight() const;
    void TodayFontWeight(const Windows::UI::Text::FontWeight & value) const;
    Windows::UI::Xaml::Media::FontFamily FirstOfMonthLabelFontFamily() const;
    void FirstOfMonthLabelFontFamily(const Windows::UI::Xaml::Media::FontFamily & value) const;
    double FirstOfMonthLabelFontSize() const;
    void FirstOfMonthLabelFontSize(double value) const;
    Windows::UI::Text::FontStyle FirstOfMonthLabelFontStyle() const;
    void FirstOfMonthLabelFontStyle(Windows::UI::Text::FontStyle value) const;
    Windows::UI::Text::FontWeight FirstOfMonthLabelFontWeight() const;
    void FirstOfMonthLabelFontWeight(const Windows::UI::Text::FontWeight & value) const;
    Windows::UI::Xaml::Media::FontFamily MonthYearItemFontFamily() const;
    void MonthYearItemFontFamily(const Windows::UI::Xaml::Media::FontFamily & value) const;
    double MonthYearItemFontSize() const;
    void MonthYearItemFontSize(double value) const;
    Windows::UI::Text::FontStyle MonthYearItemFontStyle() const;
    void MonthYearItemFontStyle(Windows::UI::Text::FontStyle value) const;
    Windows::UI::Text::FontWeight MonthYearItemFontWeight() const;
    void MonthYearItemFontWeight(const Windows::UI::Text::FontWeight & value) const;
    Windows::UI::Xaml::Media::FontFamily FirstOfYearDecadeLabelFontFamily() const;
    void FirstOfYearDecadeLabelFontFamily(const Windows::UI::Xaml::Media::FontFamily & value) const;
    double FirstOfYearDecadeLabelFontSize() const;
    void FirstOfYearDecadeLabelFontSize(double value) const;
    Windows::UI::Text::FontStyle FirstOfYearDecadeLabelFontStyle() const;
    void FirstOfYearDecadeLabelFontStyle(Windows::UI::Text::FontStyle value) const;
    Windows::UI::Text::FontWeight FirstOfYearDecadeLabelFontWeight() const;
    void FirstOfYearDecadeLabelFontWeight(const Windows::UI::Text::FontWeight & value) const;
    Windows::UI::Xaml::HorizontalAlignment HorizontalDayItemAlignment() const;
    void HorizontalDayItemAlignment(Windows::UI::Xaml::HorizontalAlignment value) const;
    Windows::UI::Xaml::VerticalAlignment VerticalDayItemAlignment() const;
    void VerticalDayItemAlignment(Windows::UI::Xaml::VerticalAlignment value) const;
    Windows::UI::Xaml::HorizontalAlignment HorizontalFirstOfMonthLabelAlignment() const;
    void HorizontalFirstOfMonthLabelAlignment(Windows::UI::Xaml::HorizontalAlignment value) const;
    Windows::UI::Xaml::VerticalAlignment VerticalFirstOfMonthLabelAlignment() const;
    void VerticalFirstOfMonthLabelAlignment(Windows::UI::Xaml::VerticalAlignment value) const;
    Windows::UI::Xaml::Thickness CalendarItemBorderThickness() const;
    void CalendarItemBorderThickness(const Windows::UI::Xaml::Thickness & value) const;
    Windows::UI::Xaml::Style CalendarViewDayItemStyle() const;
    void CalendarViewDayItemStyle(const Windows::UI::Xaml::Style & value) const;
    event_token CalendarViewDayItemChanging(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::CalendarView, Windows::UI::Xaml::Controls::CalendarViewDayItemChangingEventArgs> & value) const;
    using CalendarViewDayItemChanging_revoker = event_revoker<ICalendarView>;
    CalendarViewDayItemChanging_revoker CalendarViewDayItemChanging(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::CalendarView, Windows::UI::Xaml::Controls::CalendarViewDayItemChangingEventArgs> & value) const;
    void CalendarViewDayItemChanging(event_token token) const;
    event_token SelectedDatesChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::CalendarView, Windows::UI::Xaml::Controls::CalendarViewSelectedDatesChangedEventArgs> & value) const;
    using SelectedDatesChanged_revoker = event_revoker<ICalendarView>;
    SelectedDatesChanged_revoker SelectedDatesChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::CalendarView, Windows::UI::Xaml::Controls::CalendarViewSelectedDatesChangedEventArgs> & value) const;
    void SelectedDatesChanged(event_token token) const;
    void SetDisplayDate(const Windows::Foundation::DateTime & date) const;
    void SetYearDecadeDisplayDimensions(int32_t columns, int32_t rows) const;
};

template <typename D>
struct WINRT_EBO impl_ICalendarViewDayItem
{
    bool IsBlackout() const;
    void IsBlackout(bool value) const;
    Windows::Foundation::DateTime Date() const;
    void SetDensityColors(iterable<Windows::UI::Color> colors) const;
};

template <typename D>
struct WINRT_EBO impl_ICalendarViewDayItemChangingEventArgs
{
    bool InRecycleQueue() const;
    Windows::UI::Xaml::Controls::CalendarViewDayItem Item() const;
    uint32_t Phase() const;
    void RegisterUpdateCallback(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::CalendarView, Windows::UI::Xaml::Controls::CalendarViewDayItemChangingEventArgs> & callback) const;
    void RegisterUpdateCallback(uint32_t callbackPhase, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::CalendarView, Windows::UI::Xaml::Controls::CalendarViewDayItemChangingEventArgs> & callback) const;
};

template <typename D>
struct WINRT_EBO impl_ICalendarViewDayItemFactory
{
    Windows::UI::Xaml::Controls::CalendarViewDayItem CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_ICalendarViewDayItemStatics
{
    Windows::UI::Xaml::DependencyProperty IsBlackoutProperty() const;
    Windows::UI::Xaml::DependencyProperty DateProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ICalendarViewFactory
{
    Windows::UI::Xaml::Controls::CalendarView CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_ICalendarViewSelectedDatesChangedEventArgs
{
    Windows::Foundation::Collections::IVectorView<Windows::Foundation::DateTime> AddedDates() const;
    Windows::Foundation::Collections::IVectorView<Windows::Foundation::DateTime> RemovedDates() const;
};

template <typename D>
struct WINRT_EBO impl_ICalendarViewStatics
{
    Windows::UI::Xaml::DependencyProperty CalendarIdentifierProperty() const;
    Windows::UI::Xaml::DependencyProperty DayOfWeekFormatProperty() const;
    Windows::UI::Xaml::DependencyProperty IsGroupLabelVisibleProperty() const;
    Windows::UI::Xaml::DependencyProperty DisplayModeProperty() const;
    Windows::UI::Xaml::DependencyProperty FirstDayOfWeekProperty() const;
    Windows::UI::Xaml::DependencyProperty IsOutOfScopeEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty IsTodayHighlightedProperty() const;
    Windows::UI::Xaml::DependencyProperty MaxDateProperty() const;
    Windows::UI::Xaml::DependencyProperty MinDateProperty() const;
    Windows::UI::Xaml::DependencyProperty NumberOfWeeksInViewProperty() const;
    Windows::UI::Xaml::DependencyProperty SelectedDatesProperty() const;
    Windows::UI::Xaml::DependencyProperty SelectionModeProperty() const;
    Windows::UI::Xaml::DependencyProperty TemplateSettingsProperty() const;
    Windows::UI::Xaml::DependencyProperty FocusBorderBrushProperty() const;
    Windows::UI::Xaml::DependencyProperty SelectedHoverBorderBrushProperty() const;
    Windows::UI::Xaml::DependencyProperty SelectedPressedBorderBrushProperty() const;
    Windows::UI::Xaml::DependencyProperty SelectedBorderBrushProperty() const;
    Windows::UI::Xaml::DependencyProperty HoverBorderBrushProperty() const;
    Windows::UI::Xaml::DependencyProperty PressedBorderBrushProperty() const;
    Windows::UI::Xaml::DependencyProperty CalendarItemBorderBrushProperty() const;
    Windows::UI::Xaml::DependencyProperty OutOfScopeBackgroundProperty() const;
    Windows::UI::Xaml::DependencyProperty CalendarItemBackgroundProperty() const;
    Windows::UI::Xaml::DependencyProperty PressedForegroundProperty() const;
    Windows::UI::Xaml::DependencyProperty TodayForegroundProperty() const;
    Windows::UI::Xaml::DependencyProperty BlackoutForegroundProperty() const;
    Windows::UI::Xaml::DependencyProperty SelectedForegroundProperty() const;
    Windows::UI::Xaml::DependencyProperty OutOfScopeForegroundProperty() const;
    Windows::UI::Xaml::DependencyProperty CalendarItemForegroundProperty() const;
    Windows::UI::Xaml::DependencyProperty DayItemFontFamilyProperty() const;
    Windows::UI::Xaml::DependencyProperty DayItemFontSizeProperty() const;
    Windows::UI::Xaml::DependencyProperty DayItemFontStyleProperty() const;
    Windows::UI::Xaml::DependencyProperty DayItemFontWeightProperty() const;
    Windows::UI::Xaml::DependencyProperty TodayFontWeightProperty() const;
    Windows::UI::Xaml::DependencyProperty FirstOfMonthLabelFontFamilyProperty() const;
    Windows::UI::Xaml::DependencyProperty FirstOfMonthLabelFontSizeProperty() const;
    Windows::UI::Xaml::DependencyProperty FirstOfMonthLabelFontStyleProperty() const;
    Windows::UI::Xaml::DependencyProperty FirstOfMonthLabelFontWeightProperty() const;
    Windows::UI::Xaml::DependencyProperty MonthYearItemFontFamilyProperty() const;
    Windows::UI::Xaml::DependencyProperty MonthYearItemFontSizeProperty() const;
    Windows::UI::Xaml::DependencyProperty MonthYearItemFontStyleProperty() const;
    Windows::UI::Xaml::DependencyProperty MonthYearItemFontWeightProperty() const;
    Windows::UI::Xaml::DependencyProperty FirstOfYearDecadeLabelFontFamilyProperty() const;
    Windows::UI::Xaml::DependencyProperty FirstOfYearDecadeLabelFontSizeProperty() const;
    Windows::UI::Xaml::DependencyProperty FirstOfYearDecadeLabelFontStyleProperty() const;
    Windows::UI::Xaml::DependencyProperty FirstOfYearDecadeLabelFontWeightProperty() const;
    Windows::UI::Xaml::DependencyProperty HorizontalDayItemAlignmentProperty() const;
    Windows::UI::Xaml::DependencyProperty VerticalDayItemAlignmentProperty() const;
    Windows::UI::Xaml::DependencyProperty HorizontalFirstOfMonthLabelAlignmentProperty() const;
    Windows::UI::Xaml::DependencyProperty VerticalFirstOfMonthLabelAlignmentProperty() const;
    Windows::UI::Xaml::DependencyProperty CalendarItemBorderThicknessProperty() const;
    Windows::UI::Xaml::DependencyProperty CalendarViewDayItemStyleProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ICandidateWindowBoundsChangedEventArgs
{
    Windows::Foundation::Rect Bounds() const;
};

template <typename D>
struct WINRT_EBO impl_ICanvas
{
};

template <typename D>
struct WINRT_EBO impl_ICanvasFactory
{
    Windows::UI::Xaml::Controls::Canvas CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_ICanvasStatics
{
    Windows::UI::Xaml::DependencyProperty LeftProperty() const;
    double GetLeft(const Windows::UI::Xaml::UIElement & element) const;
    void SetLeft(const Windows::UI::Xaml::UIElement & element, double length) const;
    Windows::UI::Xaml::DependencyProperty TopProperty() const;
    double GetTop(const Windows::UI::Xaml::UIElement & element) const;
    void SetTop(const Windows::UI::Xaml::UIElement & element, double length) const;
    Windows::UI::Xaml::DependencyProperty ZIndexProperty() const;
    int32_t GetZIndex(const Windows::UI::Xaml::UIElement & element) const;
    void SetZIndex(const Windows::UI::Xaml::UIElement & element, int32_t value) const;
};

template <typename D>
struct WINRT_EBO impl_ICaptureElement
{
    Windows::Media::Capture::MediaCapture Source() const;
    void Source(const Windows::Media::Capture::MediaCapture & value) const;
    Windows::UI::Xaml::Media::Stretch Stretch() const;
    void Stretch(Windows::UI::Xaml::Media::Stretch value) const;
};

template <typename D>
struct WINRT_EBO impl_ICaptureElementStatics
{
    Windows::UI::Xaml::DependencyProperty SourceProperty() const;
    Windows::UI::Xaml::DependencyProperty StretchProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ICheckBox
{
};

template <typename D>
struct WINRT_EBO impl_ICheckBoxFactory
{
    Windows::UI::Xaml::Controls::CheckBox CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IChoosingGroupHeaderContainerEventArgs
{
    Windows::UI::Xaml::Controls::ListViewBaseHeaderItem GroupHeaderContainer() const;
    void GroupHeaderContainer(const Windows::UI::Xaml::Controls::ListViewBaseHeaderItem & value) const;
    int32_t GroupIndex() const;
    Windows::Foundation::IInspectable Group() const;
};

template <typename D>
struct WINRT_EBO impl_IChoosingItemContainerEventArgs
{
    int32_t ItemIndex() const;
    Windows::Foundation::IInspectable Item() const;
    Windows::UI::Xaml::Controls::Primitives::SelectorItem ItemContainer() const;
    void ItemContainer(const Windows::UI::Xaml::Controls::Primitives::SelectorItem & value) const;
    bool IsContainerPrepared() const;
    void IsContainerPrepared(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_ICleanUpVirtualizedItemEventArgs
{
    Windows::Foundation::IInspectable Value() const;
    Windows::UI::Xaml::UIElement UIElement() const;
    bool Cancel() const;
    void Cancel(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IColumnDefinition
{
    Windows::UI::Xaml::GridLength Width() const;
    void Width(const Windows::UI::Xaml::GridLength & value) const;
    double MaxWidth() const;
    void MaxWidth(double value) const;
    double MinWidth() const;
    void MinWidth(double value) const;
    double ActualWidth() const;
};

template <typename D>
struct WINRT_EBO impl_IColumnDefinitionStatics
{
    Windows::UI::Xaml::DependencyProperty WidthProperty() const;
    Windows::UI::Xaml::DependencyProperty MaxWidthProperty() const;
    Windows::UI::Xaml::DependencyProperty MinWidthProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IComboBox
{
    bool IsDropDownOpen() const;
    void IsDropDownOpen(bool value) const;
    bool IsEditable() const;
    bool IsSelectionBoxHighlighted() const;
    double MaxDropDownHeight() const;
    void MaxDropDownHeight(double value) const;
    Windows::Foundation::IInspectable SelectionBoxItem() const;
    Windows::UI::Xaml::DataTemplate SelectionBoxItemTemplate() const;
    Windows::UI::Xaml::Controls::Primitives::ComboBoxTemplateSettings TemplateSettings() const;
    event_token DropDownClosed(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const;
    using DropDownClosed_revoker = event_revoker<IComboBox>;
    DropDownClosed_revoker DropDownClosed(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const;
    void DropDownClosed(event_token token) const;
    event_token DropDownOpened(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const;
    using DropDownOpened_revoker = event_revoker<IComboBox>;
    DropDownOpened_revoker DropDownOpened(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const;
    void DropDownOpened(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IComboBox2
{
    Windows::Foundation::IInspectable Header() const;
    void Header(const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::DataTemplate HeaderTemplate() const;
    void HeaderTemplate(const Windows::UI::Xaml::DataTemplate & value) const;
    hstring PlaceholderText() const;
    void PlaceholderText(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IComboBox3
{
    Windows::UI::Xaml::Controls::LightDismissOverlayMode LightDismissOverlayMode() const;
    void LightDismissOverlayMode(Windows::UI::Xaml::Controls::LightDismissOverlayMode value) const;
    bool IsTextSearchEnabled() const;
    void IsTextSearchEnabled(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IComboBoxFactory
{
    Windows::UI::Xaml::Controls::ComboBox CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IComboBoxItem
{
};

template <typename D>
struct WINRT_EBO impl_IComboBoxItemFactory
{
    Windows::UI::Xaml::Controls::ComboBoxItem CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IComboBoxOverrides
{
    void OnDropDownClosed(const Windows::Foundation::IInspectable & e) const;
    void OnDropDownOpened(const Windows::Foundation::IInspectable & e) const;
};

template <typename D>
struct WINRT_EBO impl_IComboBoxStatics
{
    Windows::UI::Xaml::DependencyProperty IsDropDownOpenProperty() const;
    Windows::UI::Xaml::DependencyProperty MaxDropDownHeightProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IComboBoxStatics2
{
    Windows::UI::Xaml::DependencyProperty HeaderProperty() const;
    Windows::UI::Xaml::DependencyProperty HeaderTemplateProperty() const;
    Windows::UI::Xaml::DependencyProperty PlaceholderTextProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IComboBoxStatics3
{
    Windows::UI::Xaml::DependencyProperty LightDismissOverlayModeProperty() const;
    Windows::UI::Xaml::DependencyProperty IsTextSearchEnabledProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ICommandBar
{
    Windows::Foundation::Collections::IObservableVector<Windows::UI::Xaml::Controls::ICommandBarElement> PrimaryCommands() const;
    Windows::Foundation::Collections::IObservableVector<Windows::UI::Xaml::Controls::ICommandBarElement> SecondaryCommands() const;
};

template <typename D>
struct WINRT_EBO impl_ICommandBar2
{
    Windows::UI::Xaml::Style CommandBarOverflowPresenterStyle() const;
    void CommandBarOverflowPresenterStyle(const Windows::UI::Xaml::Style & value) const;
    Windows::UI::Xaml::Controls::Primitives::CommandBarTemplateSettings CommandBarTemplateSettings() const;
};

template <typename D>
struct WINRT_EBO impl_ICommandBar3
{
    Windows::UI::Xaml::Controls::CommandBarDefaultLabelPosition DefaultLabelPosition() const;
    void DefaultLabelPosition(Windows::UI::Xaml::Controls::CommandBarDefaultLabelPosition value) const;
    Windows::UI::Xaml::Controls::CommandBarOverflowButtonVisibility OverflowButtonVisibility() const;
    void OverflowButtonVisibility(Windows::UI::Xaml::Controls::CommandBarOverflowButtonVisibility value) const;
    bool IsDynamicOverflowEnabled() const;
    void IsDynamicOverflowEnabled(bool value) const;
    event_token DynamicOverflowItemsChanging(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::CommandBar, Windows::UI::Xaml::Controls::DynamicOverflowItemsChangingEventArgs> & value) const;
    using DynamicOverflowItemsChanging_revoker = event_revoker<ICommandBar3>;
    DynamicOverflowItemsChanging_revoker DynamicOverflowItemsChanging(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::CommandBar, Windows::UI::Xaml::Controls::DynamicOverflowItemsChangingEventArgs> & value) const;
    void DynamicOverflowItemsChanging(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_ICommandBarElement
{
    bool IsCompact() const;
    void IsCompact(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_ICommandBarElement2
{
    bool IsInOverflow() const;
    int32_t DynamicOverflowOrder() const;
    void DynamicOverflowOrder(int32_t value) const;
};

template <typename D>
struct WINRT_EBO impl_ICommandBarFactory
{
    Windows::UI::Xaml::Controls::CommandBar CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_ICommandBarOverflowPresenter
{
};

template <typename D>
struct WINRT_EBO impl_ICommandBarOverflowPresenterFactory
{
    Windows::UI::Xaml::Controls::CommandBarOverflowPresenter CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_ICommandBarStatics
{
    Windows::UI::Xaml::DependencyProperty PrimaryCommandsProperty() const;
    Windows::UI::Xaml::DependencyProperty SecondaryCommandsProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ICommandBarStatics2
{
    Windows::UI::Xaml::DependencyProperty CommandBarOverflowPresenterStyleProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ICommandBarStatics3
{
    Windows::UI::Xaml::DependencyProperty DefaultLabelPositionProperty() const;
    Windows::UI::Xaml::DependencyProperty OverflowButtonVisibilityProperty() const;
    Windows::UI::Xaml::DependencyProperty IsDynamicOverflowEnabledProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IContainerContentChangingEventArgs
{
    Windows::UI::Xaml::Controls::Primitives::SelectorItem ItemContainer() const;
    bool InRecycleQueue() const;
    int32_t ItemIndex() const;
    Windows::Foundation::IInspectable Item() const;
    uint32_t Phase() const;
    bool Handled() const;
    void Handled(bool value) const;
    void RegisterUpdateCallback(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::ListViewBase, Windows::UI::Xaml::Controls::ContainerContentChangingEventArgs> & callback) const;
    void RegisterUpdateCallback(uint32_t callbackPhase, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::ListViewBase, Windows::UI::Xaml::Controls::ContainerContentChangingEventArgs> & callback) const;
};

template <typename D>
struct WINRT_EBO impl_IContentControl
{
    Windows::Foundation::IInspectable Content() const;
    void Content(const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::DataTemplate ContentTemplate() const;
    void ContentTemplate(const Windows::UI::Xaml::DataTemplate & value) const;
    Windows::UI::Xaml::Controls::DataTemplateSelector ContentTemplateSelector() const;
    void ContentTemplateSelector(const Windows::UI::Xaml::Controls::DataTemplateSelector & value) const;
    Windows::UI::Xaml::Media::Animation::TransitionCollection ContentTransitions() const;
    void ContentTransitions(const Windows::UI::Xaml::Media::Animation::TransitionCollection & value) const;
};

template <typename D>
struct WINRT_EBO impl_IContentControl2
{
    Windows::UI::Xaml::UIElement ContentTemplateRoot() const;
};

template <typename D>
struct WINRT_EBO impl_IContentControlFactory
{
    Windows::UI::Xaml::Controls::ContentControl CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IContentControlOverrides
{
    void OnContentChanged(const Windows::Foundation::IInspectable & oldContent, const Windows::Foundation::IInspectable & newContent) const;
    void OnContentTemplateChanged(const Windows::UI::Xaml::DataTemplate & oldContentTemplate, const Windows::UI::Xaml::DataTemplate & newContentTemplate) const;
    void OnContentTemplateSelectorChanged(const Windows::UI::Xaml::Controls::DataTemplateSelector & oldContentTemplateSelector, const Windows::UI::Xaml::Controls::DataTemplateSelector & newContentTemplateSelector) const;
};

template <typename D>
struct WINRT_EBO impl_IContentControlStatics
{
    Windows::UI::Xaml::DependencyProperty ContentProperty() const;
    Windows::UI::Xaml::DependencyProperty ContentTemplateProperty() const;
    Windows::UI::Xaml::DependencyProperty ContentTemplateSelectorProperty() const;
    Windows::UI::Xaml::DependencyProperty ContentTransitionsProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IContentDialog
{
    Windows::Foundation::IInspectable Title() const;
    void Title(const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::DataTemplate TitleTemplate() const;
    void TitleTemplate(const Windows::UI::Xaml::DataTemplate & value) const;
    bool FullSizeDesired() const;
    void FullSizeDesired(bool value) const;
    hstring PrimaryButtonText() const;
    void PrimaryButtonText(hstring_view value) const;
    hstring SecondaryButtonText() const;
    void SecondaryButtonText(hstring_view value) const;
    Windows::UI::Xaml::Input::ICommand PrimaryButtonCommand() const;
    void PrimaryButtonCommand(const Windows::UI::Xaml::Input::ICommand & value) const;
    Windows::UI::Xaml::Input::ICommand SecondaryButtonCommand() const;
    void SecondaryButtonCommand(const Windows::UI::Xaml::Input::ICommand & value) const;
    Windows::Foundation::IInspectable PrimaryButtonCommandParameter() const;
    void PrimaryButtonCommandParameter(const Windows::Foundation::IInspectable & value) const;
    Windows::Foundation::IInspectable SecondaryButtonCommandParameter() const;
    void SecondaryButtonCommandParameter(const Windows::Foundation::IInspectable & value) const;
    bool IsPrimaryButtonEnabled() const;
    void IsPrimaryButtonEnabled(bool value) const;
    bool IsSecondaryButtonEnabled() const;
    void IsSecondaryButtonEnabled(bool value) const;
    event_token Closing(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::ContentDialog, Windows::UI::Xaml::Controls::ContentDialogClosingEventArgs> & value) const;
    using Closing_revoker = event_revoker<IContentDialog>;
    Closing_revoker Closing(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::ContentDialog, Windows::UI::Xaml::Controls::ContentDialogClosingEventArgs> & value) const;
    void Closing(event_token token) const;
    event_token Closed(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::ContentDialog, Windows::UI::Xaml::Controls::ContentDialogClosedEventArgs> & value) const;
    using Closed_revoker = event_revoker<IContentDialog>;
    Closed_revoker Closed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::ContentDialog, Windows::UI::Xaml::Controls::ContentDialogClosedEventArgs> & value) const;
    void Closed(event_token token) const;
    event_token Opened(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::ContentDialog, Windows::UI::Xaml::Controls::ContentDialogOpenedEventArgs> & value) const;
    using Opened_revoker = event_revoker<IContentDialog>;
    Opened_revoker Opened(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::ContentDialog, Windows::UI::Xaml::Controls::ContentDialogOpenedEventArgs> & value) const;
    void Opened(event_token token) const;
    event_token PrimaryButtonClick(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::ContentDialog, Windows::UI::Xaml::Controls::ContentDialogButtonClickEventArgs> & value) const;
    using PrimaryButtonClick_revoker = event_revoker<IContentDialog>;
    PrimaryButtonClick_revoker PrimaryButtonClick(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::ContentDialog, Windows::UI::Xaml::Controls::ContentDialogButtonClickEventArgs> & value) const;
    void PrimaryButtonClick(event_token token) const;
    event_token SecondaryButtonClick(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::ContentDialog, Windows::UI::Xaml::Controls::ContentDialogButtonClickEventArgs> & value) const;
    using SecondaryButtonClick_revoker = event_revoker<IContentDialog>;
    SecondaryButtonClick_revoker SecondaryButtonClick(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::ContentDialog, Windows::UI::Xaml::Controls::ContentDialogButtonClickEventArgs> & value) const;
    void SecondaryButtonClick(event_token token) const;
    void Hide() const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::UI::Xaml::Controls::ContentDialogResult> ShowAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IContentDialogButtonClickDeferral
{
    void Complete() const;
};

template <typename D>
struct WINRT_EBO impl_IContentDialogButtonClickEventArgs
{
    bool Cancel() const;
    void Cancel(bool value) const;
    Windows::UI::Xaml::Controls::ContentDialogButtonClickDeferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IContentDialogClosedEventArgs
{
    Windows::UI::Xaml::Controls::ContentDialogResult Result() const;
};

template <typename D>
struct WINRT_EBO impl_IContentDialogClosingDeferral
{
    void Complete() const;
};

template <typename D>
struct WINRT_EBO impl_IContentDialogClosingEventArgs
{
    Windows::UI::Xaml::Controls::ContentDialogResult Result() const;
    bool Cancel() const;
    void Cancel(bool value) const;
    Windows::UI::Xaml::Controls::ContentDialogClosingDeferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IContentDialogFactory
{
    Windows::UI::Xaml::Controls::ContentDialog CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IContentDialogOpenedEventArgs
{
};

template <typename D>
struct WINRT_EBO impl_IContentDialogStatics
{
    Windows::UI::Xaml::DependencyProperty TitleProperty() const;
    Windows::UI::Xaml::DependencyProperty TitleTemplateProperty() const;
    Windows::UI::Xaml::DependencyProperty FullSizeDesiredProperty() const;
    Windows::UI::Xaml::DependencyProperty PrimaryButtonTextProperty() const;
    Windows::UI::Xaml::DependencyProperty SecondaryButtonTextProperty() const;
    Windows::UI::Xaml::DependencyProperty PrimaryButtonCommandProperty() const;
    Windows::UI::Xaml::DependencyProperty SecondaryButtonCommandProperty() const;
    Windows::UI::Xaml::DependencyProperty PrimaryButtonCommandParameterProperty() const;
    Windows::UI::Xaml::DependencyProperty SecondaryButtonCommandParameterProperty() const;
    Windows::UI::Xaml::DependencyProperty IsPrimaryButtonEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty IsSecondaryButtonEnabledProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IContentPresenter
{
    Windows::Foundation::IInspectable Content() const;
    void Content(const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::DataTemplate ContentTemplate() const;
    void ContentTemplate(const Windows::UI::Xaml::DataTemplate & value) const;
    Windows::UI::Xaml::Controls::DataTemplateSelector ContentTemplateSelector() const;
    void ContentTemplateSelector(const Windows::UI::Xaml::Controls::DataTemplateSelector & value) const;
    Windows::UI::Xaml::Media::Animation::TransitionCollection ContentTransitions() const;
    void ContentTransitions(const Windows::UI::Xaml::Media::Animation::TransitionCollection & value) const;
    double FontSize() const;
    void FontSize(double value) const;
    Windows::UI::Xaml::Media::FontFamily FontFamily() const;
    void FontFamily(const Windows::UI::Xaml::Media::FontFamily & value) const;
    Windows::UI::Text::FontWeight FontWeight() const;
    void FontWeight(const Windows::UI::Text::FontWeight & value) const;
    Windows::UI::Text::FontStyle FontStyle() const;
    void FontStyle(Windows::UI::Text::FontStyle value) const;
    Windows::UI::Text::FontStretch FontStretch() const;
    void FontStretch(Windows::UI::Text::FontStretch value) const;
    int32_t CharacterSpacing() const;
    void CharacterSpacing(int32_t value) const;
    Windows::UI::Xaml::Media::Brush Foreground() const;
    void Foreground(const Windows::UI::Xaml::Media::Brush & value) const;
};

template <typename D>
struct WINRT_EBO impl_IContentPresenter2
{
    Windows::UI::Xaml::OpticalMarginAlignment OpticalMarginAlignment() const;
    void OpticalMarginAlignment(Windows::UI::Xaml::OpticalMarginAlignment value) const;
    Windows::UI::Xaml::TextLineBounds TextLineBounds() const;
    void TextLineBounds(Windows::UI::Xaml::TextLineBounds value) const;
};

template <typename D>
struct WINRT_EBO impl_IContentPresenter3
{
    bool IsTextScaleFactorEnabled() const;
    void IsTextScaleFactorEnabled(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IContentPresenter4
{
    Windows::UI::Xaml::TextWrapping TextWrapping() const;
    void TextWrapping(Windows::UI::Xaml::TextWrapping value) const;
    int32_t MaxLines() const;
    void MaxLines(int32_t value) const;
    Windows::UI::Xaml::LineStackingStrategy LineStackingStrategy() const;
    void LineStackingStrategy(Windows::UI::Xaml::LineStackingStrategy value) const;
    double LineHeight() const;
    void LineHeight(double value) const;
    Windows::UI::Xaml::Media::Brush BorderBrush() const;
    void BorderBrush(const Windows::UI::Xaml::Media::Brush & value) const;
    Windows::UI::Xaml::Thickness BorderThickness() const;
    void BorderThickness(const Windows::UI::Xaml::Thickness & value) const;
    Windows::UI::Xaml::CornerRadius CornerRadius() const;
    void CornerRadius(const Windows::UI::Xaml::CornerRadius & value) const;
    Windows::UI::Xaml::Thickness Padding() const;
    void Padding(const Windows::UI::Xaml::Thickness & value) const;
    Windows::UI::Xaml::Media::Brush Background() const;
    void Background(const Windows::UI::Xaml::Media::Brush & value) const;
    Windows::UI::Xaml::HorizontalAlignment HorizontalContentAlignment() const;
    void HorizontalContentAlignment(Windows::UI::Xaml::HorizontalAlignment value) const;
    Windows::UI::Xaml::VerticalAlignment VerticalContentAlignment() const;
    void VerticalContentAlignment(Windows::UI::Xaml::VerticalAlignment value) const;
};

template <typename D>
struct WINRT_EBO impl_IContentPresenterFactory
{
    Windows::UI::Xaml::Controls::ContentPresenter CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IContentPresenterOverrides
{
    void OnContentTemplateChanged(const Windows::UI::Xaml::DataTemplate & oldContentTemplate, const Windows::UI::Xaml::DataTemplate & newContentTemplate) const;
    void OnContentTemplateSelectorChanged(const Windows::UI::Xaml::Controls::DataTemplateSelector & oldContentTemplateSelector, const Windows::UI::Xaml::Controls::DataTemplateSelector & newContentTemplateSelector) const;
};

template <typename D>
struct WINRT_EBO impl_IContentPresenterStatics
{
    Windows::UI::Xaml::DependencyProperty ContentProperty() const;
    Windows::UI::Xaml::DependencyProperty ContentTemplateProperty() const;
    Windows::UI::Xaml::DependencyProperty ContentTemplateSelectorProperty() const;
    Windows::UI::Xaml::DependencyProperty ContentTransitionsProperty() const;
    Windows::UI::Xaml::DependencyProperty FontSizeProperty() const;
    Windows::UI::Xaml::DependencyProperty FontFamilyProperty() const;
    Windows::UI::Xaml::DependencyProperty FontWeightProperty() const;
    Windows::UI::Xaml::DependencyProperty FontStyleProperty() const;
    Windows::UI::Xaml::DependencyProperty FontStretchProperty() const;
    Windows::UI::Xaml::DependencyProperty CharacterSpacingProperty() const;
    Windows::UI::Xaml::DependencyProperty ForegroundProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IContentPresenterStatics2
{
    Windows::UI::Xaml::DependencyProperty OpticalMarginAlignmentProperty() const;
    Windows::UI::Xaml::DependencyProperty TextLineBoundsProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IContentPresenterStatics3
{
    Windows::UI::Xaml::DependencyProperty IsTextScaleFactorEnabledProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IContentPresenterStatics4
{
    Windows::UI::Xaml::DependencyProperty TextWrappingProperty() const;
    Windows::UI::Xaml::DependencyProperty MaxLinesProperty() const;
    Windows::UI::Xaml::DependencyProperty LineStackingStrategyProperty() const;
    Windows::UI::Xaml::DependencyProperty LineHeightProperty() const;
    Windows::UI::Xaml::DependencyProperty BorderBrushProperty() const;
    Windows::UI::Xaml::DependencyProperty BorderThicknessProperty() const;
    Windows::UI::Xaml::DependencyProperty CornerRadiusProperty() const;
    Windows::UI::Xaml::DependencyProperty PaddingProperty() const;
    Windows::UI::Xaml::DependencyProperty BackgroundProperty() const;
    Windows::UI::Xaml::DependencyProperty HorizontalContentAlignmentProperty() const;
    Windows::UI::Xaml::DependencyProperty VerticalContentAlignmentProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IContextMenuEventArgs
{
    bool Handled() const;
    void Handled(bool value) const;
    double CursorLeft() const;
    double CursorTop() const;
};

template <typename D>
struct WINRT_EBO impl_IControl
{
    double FontSize() const;
    void FontSize(double value) const;
    Windows::UI::Xaml::Media::FontFamily FontFamily() const;
    void FontFamily(const Windows::UI::Xaml::Media::FontFamily & value) const;
    Windows::UI::Text::FontWeight FontWeight() const;
    void FontWeight(const Windows::UI::Text::FontWeight & value) const;
    Windows::UI::Text::FontStyle FontStyle() const;
    void FontStyle(Windows::UI::Text::FontStyle value) const;
    Windows::UI::Text::FontStretch FontStretch() const;
    void FontStretch(Windows::UI::Text::FontStretch value) const;
    int32_t CharacterSpacing() const;
    void CharacterSpacing(int32_t value) const;
    Windows::UI::Xaml::Media::Brush Foreground() const;
    void Foreground(const Windows::UI::Xaml::Media::Brush & value) const;
    bool IsTabStop() const;
    void IsTabStop(bool value) const;
    bool IsEnabled() const;
    void IsEnabled(bool value) const;
    int32_t TabIndex() const;
    void TabIndex(int32_t value) const;
    Windows::UI::Xaml::Input::KeyboardNavigationMode TabNavigation() const;
    void TabNavigation(Windows::UI::Xaml::Input::KeyboardNavigationMode value) const;
    Windows::UI::Xaml::Controls::ControlTemplate Template() const;
    void Template(const Windows::UI::Xaml::Controls::ControlTemplate & value) const;
    Windows::UI::Xaml::Thickness Padding() const;
    void Padding(const Windows::UI::Xaml::Thickness & value) const;
    Windows::UI::Xaml::HorizontalAlignment HorizontalContentAlignment() const;
    void HorizontalContentAlignment(Windows::UI::Xaml::HorizontalAlignment value) const;
    Windows::UI::Xaml::VerticalAlignment VerticalContentAlignment() const;
    void VerticalContentAlignment(Windows::UI::Xaml::VerticalAlignment value) const;
    Windows::UI::Xaml::Media::Brush Background() const;
    void Background(const Windows::UI::Xaml::Media::Brush & value) const;
    Windows::UI::Xaml::Thickness BorderThickness() const;
    void BorderThickness(const Windows::UI::Xaml::Thickness & value) const;
    Windows::UI::Xaml::Media::Brush BorderBrush() const;
    void BorderBrush(const Windows::UI::Xaml::Media::Brush & value) const;
    Windows::UI::Xaml::FocusState FocusState() const;
    event_token IsEnabledChanged(const Windows::UI::Xaml::DependencyPropertyChangedEventHandler & value) const;
    using IsEnabledChanged_revoker = event_revoker<IControl>;
    IsEnabledChanged_revoker IsEnabledChanged(auto_revoke_t, const Windows::UI::Xaml::DependencyPropertyChangedEventHandler & value) const;
    void IsEnabledChanged(event_token token) const;
    bool ApplyTemplate() const;
    bool Focus(Windows::UI::Xaml::FocusState value) const;
};

template <typename D>
struct WINRT_EBO impl_IControl2
{
    bool IsTextScaleFactorEnabled() const;
    void IsTextScaleFactorEnabled(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IControl3
{
    bool UseSystemFocusVisuals() const;
    void UseSystemFocusVisuals(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IControl4
{
    bool IsFocusEngagementEnabled() const;
    void IsFocusEngagementEnabled(bool value) const;
    bool IsFocusEngaged() const;
    void IsFocusEngaged(bool value) const;
    Windows::UI::Xaml::Controls::RequiresPointer RequiresPointer() const;
    void RequiresPointer(Windows::UI::Xaml::Controls::RequiresPointer value) const;
    Windows::UI::Xaml::DependencyObject XYFocusLeft() const;
    void XYFocusLeft(const Windows::UI::Xaml::DependencyObject & value) const;
    Windows::UI::Xaml::DependencyObject XYFocusRight() const;
    void XYFocusRight(const Windows::UI::Xaml::DependencyObject & value) const;
    Windows::UI::Xaml::DependencyObject XYFocusUp() const;
    void XYFocusUp(const Windows::UI::Xaml::DependencyObject & value) const;
    Windows::UI::Xaml::DependencyObject XYFocusDown() const;
    void XYFocusDown(const Windows::UI::Xaml::DependencyObject & value) const;
    Windows::UI::Xaml::ElementSoundMode ElementSoundMode() const;
    void ElementSoundMode(Windows::UI::Xaml::ElementSoundMode value) const;
    event_token FocusEngaged(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::FocusEngagedEventArgs> & value) const;
    using FocusEngaged_revoker = event_revoker<IControl4>;
    FocusEngaged_revoker FocusEngaged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::FocusEngagedEventArgs> & value) const;
    void FocusEngaged(event_token token) const;
    event_token FocusDisengaged(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::FocusDisengagedEventArgs> & value) const;
    using FocusDisengaged_revoker = event_revoker<IControl4>;
    FocusDisengaged_revoker FocusDisengaged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Control, Windows::UI::Xaml::Controls::FocusDisengagedEventArgs> & value) const;
    void FocusDisengaged(event_token token) const;
    void RemoveFocusEngagement() const;
};

template <typename D>
struct WINRT_EBO impl_IControlFactory
{
    Windows::UI::Xaml::Controls::Control CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IControlOverrides
{
    void OnPointerEntered(const Windows::UI::Xaml::Input::PointerRoutedEventArgs & e) const;
    void OnPointerPressed(const Windows::UI::Xaml::Input::PointerRoutedEventArgs & e) const;
    void OnPointerMoved(const Windows::UI::Xaml::Input::PointerRoutedEventArgs & e) const;
    void OnPointerReleased(const Windows::UI::Xaml::Input::PointerRoutedEventArgs & e) const;
    void OnPointerExited(const Windows::UI::Xaml::Input::PointerRoutedEventArgs & e) const;
    void OnPointerCaptureLost(const Windows::UI::Xaml::Input::PointerRoutedEventArgs & e) const;
    void OnPointerCanceled(const Windows::UI::Xaml::Input::PointerRoutedEventArgs & e) const;
    void OnPointerWheelChanged(const Windows::UI::Xaml::Input::PointerRoutedEventArgs & e) const;
    void OnTapped(const Windows::UI::Xaml::Input::TappedRoutedEventArgs & e) const;
    void OnDoubleTapped(const Windows::UI::Xaml::Input::DoubleTappedRoutedEventArgs & e) const;
    void OnHolding(const Windows::UI::Xaml::Input::HoldingRoutedEventArgs & e) const;
    void OnRightTapped(const Windows::UI::Xaml::Input::RightTappedRoutedEventArgs & e) const;
    void OnManipulationStarting(const Windows::UI::Xaml::Input::ManipulationStartingRoutedEventArgs & e) const;
    void OnManipulationInertiaStarting(const Windows::UI::Xaml::Input::ManipulationInertiaStartingRoutedEventArgs & e) const;
    void OnManipulationStarted(const Windows::UI::Xaml::Input::ManipulationStartedRoutedEventArgs & e) const;
    void OnManipulationDelta(const Windows::UI::Xaml::Input::ManipulationDeltaRoutedEventArgs & e) const;
    void OnManipulationCompleted(const Windows::UI::Xaml::Input::ManipulationCompletedRoutedEventArgs & e) const;
    void OnKeyUp(const Windows::UI::Xaml::Input::KeyRoutedEventArgs & e) const;
    void OnKeyDown(const Windows::UI::Xaml::Input::KeyRoutedEventArgs & e) const;
    void OnGotFocus(const Windows::UI::Xaml::RoutedEventArgs & e) const;
    void OnLostFocus(const Windows::UI::Xaml::RoutedEventArgs & e) const;
    void OnDragEnter(const Windows::UI::Xaml::DragEventArgs & e) const;
    void OnDragLeave(const Windows::UI::Xaml::DragEventArgs & e) const;
    void OnDragOver(const Windows::UI::Xaml::DragEventArgs & e) const;
    void OnDrop(const Windows::UI::Xaml::DragEventArgs & e) const;
};

template <typename D>
struct WINRT_EBO impl_IControlProtected
{
    Windows::Foundation::IInspectable DefaultStyleKey() const;
    void DefaultStyleKey(const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::DependencyObject GetTemplateChild(hstring_view childName) const;
};

template <typename D>
struct WINRT_EBO impl_IControlStatics
{
    Windows::UI::Xaml::DependencyProperty FontSizeProperty() const;
    Windows::UI::Xaml::DependencyProperty FontFamilyProperty() const;
    Windows::UI::Xaml::DependencyProperty FontWeightProperty() const;
    Windows::UI::Xaml::DependencyProperty FontStyleProperty() const;
    Windows::UI::Xaml::DependencyProperty FontStretchProperty() const;
    Windows::UI::Xaml::DependencyProperty CharacterSpacingProperty() const;
    Windows::UI::Xaml::DependencyProperty ForegroundProperty() const;
    Windows::UI::Xaml::DependencyProperty IsTabStopProperty() const;
    Windows::UI::Xaml::DependencyProperty IsEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty TabIndexProperty() const;
    Windows::UI::Xaml::DependencyProperty TabNavigationProperty() const;
    Windows::UI::Xaml::DependencyProperty TemplateProperty() const;
    Windows::UI::Xaml::DependencyProperty PaddingProperty() const;
    Windows::UI::Xaml::DependencyProperty HorizontalContentAlignmentProperty() const;
    Windows::UI::Xaml::DependencyProperty VerticalContentAlignmentProperty() const;
    Windows::UI::Xaml::DependencyProperty BackgroundProperty() const;
    Windows::UI::Xaml::DependencyProperty BorderThicknessProperty() const;
    Windows::UI::Xaml::DependencyProperty BorderBrushProperty() const;
    Windows::UI::Xaml::DependencyProperty DefaultStyleKeyProperty() const;
    Windows::UI::Xaml::DependencyProperty FocusStateProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IControlStatics2
{
    Windows::UI::Xaml::DependencyProperty IsTextScaleFactorEnabledProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IControlStatics3
{
    Windows::UI::Xaml::DependencyProperty UseSystemFocusVisualsProperty() const;
    Windows::UI::Xaml::DependencyProperty IsTemplateFocusTargetProperty() const;
    bool GetIsTemplateFocusTarget(const Windows::UI::Xaml::FrameworkElement & element) const;
    void SetIsTemplateFocusTarget(const Windows::UI::Xaml::FrameworkElement & element, bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IControlStatics4
{
    Windows::UI::Xaml::DependencyProperty IsFocusEngagementEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty IsFocusEngagedProperty() const;
    Windows::UI::Xaml::DependencyProperty RequiresPointerProperty() const;
    Windows::UI::Xaml::DependencyProperty XYFocusLeftProperty() const;
    Windows::UI::Xaml::DependencyProperty XYFocusRightProperty() const;
    Windows::UI::Xaml::DependencyProperty XYFocusUpProperty() const;
    Windows::UI::Xaml::DependencyProperty XYFocusDownProperty() const;
    Windows::UI::Xaml::DependencyProperty ElementSoundModeProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IControlTemplate
{
    Windows::UI::Xaml::Interop::TypeName TargetType() const;
    void TargetType(const Windows::UI::Xaml::Interop::TypeName & value) const;
};

template <typename D>
struct WINRT_EBO impl_IDataTemplateSelector
{
    Windows::UI::Xaml::DataTemplate SelectTemplate(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::DependencyObject & container) const;
};

template <typename D>
struct WINRT_EBO impl_IDataTemplateSelector2
{
    Windows::UI::Xaml::DataTemplate SelectTemplate(const Windows::Foundation::IInspectable & item) const;
};

template <typename D>
struct WINRT_EBO impl_IDataTemplateSelectorFactory
{
    Windows::UI::Xaml::Controls::DataTemplateSelector CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IDataTemplateSelectorOverrides
{
    Windows::UI::Xaml::DataTemplate SelectTemplateCore(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::DependencyObject & container) const;
};

template <typename D>
struct WINRT_EBO impl_IDataTemplateSelectorOverrides2
{
    Windows::UI::Xaml::DataTemplate SelectTemplateCore(const Windows::Foundation::IInspectable & item) const;
};

template <typename D>
struct WINRT_EBO impl_IDatePickedEventArgs
{
    Windows::Foundation::DateTime OldDate() const;
    Windows::Foundation::DateTime NewDate() const;
};

template <typename D>
struct WINRT_EBO impl_IDatePicker
{
    Windows::Foundation::IInspectable Header() const;
    void Header(const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::DataTemplate HeaderTemplate() const;
    void HeaderTemplate(const Windows::UI::Xaml::DataTemplate & value) const;
    hstring CalendarIdentifier() const;
    void CalendarIdentifier(hstring_view value) const;
    Windows::Foundation::DateTime Date() const;
    void Date(const Windows::Foundation::DateTime & value) const;
    bool DayVisible() const;
    void DayVisible(bool value) const;
    bool MonthVisible() const;
    void MonthVisible(bool value) const;
    bool YearVisible() const;
    void YearVisible(bool value) const;
    hstring DayFormat() const;
    void DayFormat(hstring_view value) const;
    hstring MonthFormat() const;
    void MonthFormat(hstring_view value) const;
    hstring YearFormat() const;
    void YearFormat(hstring_view value) const;
    Windows::Foundation::DateTime MinYear() const;
    void MinYear(const Windows::Foundation::DateTime & value) const;
    Windows::Foundation::DateTime MaxYear() const;
    void MaxYear(const Windows::Foundation::DateTime & value) const;
    Windows::UI::Xaml::Controls::Orientation Orientation() const;
    void Orientation(Windows::UI::Xaml::Controls::Orientation value) const;
    event_token DateChanged(const Windows::Foundation::EventHandler<Windows::UI::Xaml::Controls::DatePickerValueChangedEventArgs> & value) const;
    using DateChanged_revoker = event_revoker<IDatePicker>;
    DateChanged_revoker DateChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::UI::Xaml::Controls::DatePickerValueChangedEventArgs> & value) const;
    void DateChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IDatePicker2
{
    Windows::UI::Xaml::Controls::LightDismissOverlayMode LightDismissOverlayMode() const;
    void LightDismissOverlayMode(Windows::UI::Xaml::Controls::LightDismissOverlayMode value) const;
};

template <typename D>
struct WINRT_EBO impl_IDatePickerFactory
{
    Windows::UI::Xaml::Controls::DatePicker CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IDatePickerFlyout
{
    hstring CalendarIdentifier() const;
    void CalendarIdentifier(hstring_view value) const;
    Windows::Foundation::DateTime Date() const;
    void Date(const Windows::Foundation::DateTime & value) const;
    bool DayVisible() const;
    void DayVisible(bool value) const;
    bool MonthVisible() const;
    void MonthVisible(bool value) const;
    bool YearVisible() const;
    void YearVisible(bool value) const;
    Windows::Foundation::DateTime MinYear() const;
    void MinYear(const Windows::Foundation::DateTime & value) const;
    Windows::Foundation::DateTime MaxYear() const;
    void MaxYear(const Windows::Foundation::DateTime & value) const;
    event_token DatePicked(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::DatePickerFlyout, Windows::UI::Xaml::Controls::DatePickedEventArgs> & value) const;
    using DatePicked_revoker = event_revoker<IDatePickerFlyout>;
    DatePicked_revoker DatePicked(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::DatePickerFlyout, Windows::UI::Xaml::Controls::DatePickedEventArgs> & value) const;
    void DatePicked(event_token token) const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::IReference<Windows::Foundation::DateTime>> ShowAtAsync(const Windows::UI::Xaml::FrameworkElement & target) const;
};

template <typename D>
struct WINRT_EBO impl_IDatePickerFlyout2
{
    hstring DayFormat() const;
    void DayFormat(hstring_view value) const;
    hstring MonthFormat() const;
    void MonthFormat(hstring_view value) const;
    hstring YearFormat() const;
    void YearFormat(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IDatePickerFlyoutItem
{
    hstring PrimaryText() const;
    void PrimaryText(hstring_view value) const;
    hstring SecondaryText() const;
    void SecondaryText(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IDatePickerFlyoutItemStatics
{
    Windows::UI::Xaml::DependencyProperty PrimaryTextProperty() const;
    Windows::UI::Xaml::DependencyProperty SecondaryTextProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IDatePickerFlyoutPresenter
{
};

template <typename D>
struct WINRT_EBO impl_IDatePickerFlyoutStatics
{
    Windows::UI::Xaml::DependencyProperty CalendarIdentifierProperty() const;
    Windows::UI::Xaml::DependencyProperty DateProperty() const;
    Windows::UI::Xaml::DependencyProperty DayVisibleProperty() const;
    Windows::UI::Xaml::DependencyProperty MonthVisibleProperty() const;
    Windows::UI::Xaml::DependencyProperty YearVisibleProperty() const;
    Windows::UI::Xaml::DependencyProperty MinYearProperty() const;
    Windows::UI::Xaml::DependencyProperty MaxYearProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IDatePickerFlyoutStatics2
{
    Windows::UI::Xaml::DependencyProperty DayFormatProperty() const;
    Windows::UI::Xaml::DependencyProperty MonthFormatProperty() const;
    Windows::UI::Xaml::DependencyProperty YearFormatProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IDatePickerStatics
{
    Windows::UI::Xaml::DependencyProperty HeaderProperty() const;
    Windows::UI::Xaml::DependencyProperty HeaderTemplateProperty() const;
    Windows::UI::Xaml::DependencyProperty CalendarIdentifierProperty() const;
    Windows::UI::Xaml::DependencyProperty DateProperty() const;
    Windows::UI::Xaml::DependencyProperty DayVisibleProperty() const;
    Windows::UI::Xaml::DependencyProperty MonthVisibleProperty() const;
    Windows::UI::Xaml::DependencyProperty YearVisibleProperty() const;
    Windows::UI::Xaml::DependencyProperty DayFormatProperty() const;
    Windows::UI::Xaml::DependencyProperty MonthFormatProperty() const;
    Windows::UI::Xaml::DependencyProperty YearFormatProperty() const;
    Windows::UI::Xaml::DependencyProperty MinYearProperty() const;
    Windows::UI::Xaml::DependencyProperty MaxYearProperty() const;
    Windows::UI::Xaml::DependencyProperty OrientationProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IDatePickerStatics2
{
    Windows::UI::Xaml::DependencyProperty LightDismissOverlayModeProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IDatePickerValueChangedEventArgs
{
    Windows::Foundation::DateTime OldDate() const;
    Windows::Foundation::DateTime NewDate() const;
};

template <typename D>
struct WINRT_EBO impl_IDragItemsCompletedEventArgs
{
    Windows::Foundation::Collections::IVectorView<Windows::Foundation::IInspectable> Items() const;
    Windows::ApplicationModel::DataTransfer::DataPackageOperation DropResult() const;
};

template <typename D>
struct WINRT_EBO impl_IDragItemsStartingEventArgs
{
    bool Cancel() const;
    void Cancel(bool value) const;
    Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> Items() const;
    Windows::ApplicationModel::DataTransfer::DataPackage Data() const;
};

template <typename D>
struct WINRT_EBO impl_IDynamicOverflowItemsChangingEventArgs
{
    Windows::UI::Xaml::Controls::CommandBarDynamicOverflowAction Action() const;
};

template <typename D>
struct WINRT_EBO impl_IFlipView
{
};

template <typename D>
struct WINRT_EBO impl_IFlipView2
{
    bool UseTouchAnimationsForAllNavigation() const;
    void UseTouchAnimationsForAllNavigation(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IFlipViewFactory
{
    Windows::UI::Xaml::Controls::FlipView CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IFlipViewItem
{
};

template <typename D>
struct WINRT_EBO impl_IFlipViewItemFactory
{
    Windows::UI::Xaml::Controls::FlipViewItem CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IFlipViewStatics2
{
    Windows::UI::Xaml::DependencyProperty UseTouchAnimationsForAllNavigationProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IFlyout
{
    Windows::UI::Xaml::UIElement Content() const;
    void Content(const Windows::UI::Xaml::UIElement & value) const;
    Windows::UI::Xaml::Style FlyoutPresenterStyle() const;
    void FlyoutPresenterStyle(const Windows::UI::Xaml::Style & value) const;
};

template <typename D>
struct WINRT_EBO impl_IFlyoutFactory
{
    Windows::UI::Xaml::Controls::Flyout CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IFlyoutPresenter
{
};

template <typename D>
struct WINRT_EBO impl_IFlyoutPresenterFactory
{
    Windows::UI::Xaml::Controls::FlyoutPresenter CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IFlyoutStatics
{
    Windows::UI::Xaml::DependencyProperty ContentProperty() const;
    Windows::UI::Xaml::DependencyProperty FlyoutPresenterStyleProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IFocusDisengagedEventArgs
{
};

template <typename D>
struct WINRT_EBO impl_IFocusEngagedEventArgs
{
};

template <typename D>
struct WINRT_EBO impl_IFontIcon
{
    hstring Glyph() const;
    void Glyph(hstring_view value) const;
    double FontSize() const;
    void FontSize(double value) const;
    Windows::UI::Xaml::Media::FontFamily FontFamily() const;
    void FontFamily(const Windows::UI::Xaml::Media::FontFamily & value) const;
    Windows::UI::Text::FontWeight FontWeight() const;
    void FontWeight(const Windows::UI::Text::FontWeight & value) const;
    Windows::UI::Text::FontStyle FontStyle() const;
    void FontStyle(Windows::UI::Text::FontStyle value) const;
};

template <typename D>
struct WINRT_EBO impl_IFontIcon2
{
    bool IsTextScaleFactorEnabled() const;
    void IsTextScaleFactorEnabled(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IFontIcon3
{
    bool MirroredWhenRightToLeft() const;
    void MirroredWhenRightToLeft(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IFontIconFactory
{
    Windows::UI::Xaml::Controls::FontIcon CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IFontIconStatics
{
    Windows::UI::Xaml::DependencyProperty GlyphProperty() const;
    Windows::UI::Xaml::DependencyProperty FontSizeProperty() const;
    Windows::UI::Xaml::DependencyProperty FontFamilyProperty() const;
    Windows::UI::Xaml::DependencyProperty FontWeightProperty() const;
    Windows::UI::Xaml::DependencyProperty FontStyleProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IFontIconStatics2
{
    Windows::UI::Xaml::DependencyProperty IsTextScaleFactorEnabledProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IFontIconStatics3
{
    Windows::UI::Xaml::DependencyProperty MirroredWhenRightToLeftProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IFrame
{
    int32_t CacheSize() const;
    void CacheSize(int32_t value) const;
    bool CanGoBack() const;
    bool CanGoForward() const;
    Windows::UI::Xaml::Interop::TypeName CurrentSourcePageType() const;
    Windows::UI::Xaml::Interop::TypeName SourcePageType() const;
    void SourcePageType(const Windows::UI::Xaml::Interop::TypeName & value) const;
    int32_t BackStackDepth() const;
    event_token Navigated(const Windows::UI::Xaml::Navigation::NavigatedEventHandler & value) const;
    using Navigated_revoker = event_revoker<IFrame>;
    Navigated_revoker Navigated(auto_revoke_t, const Windows::UI::Xaml::Navigation::NavigatedEventHandler & value) const;
    void Navigated(event_token token) const;
    event_token Navigating(const Windows::UI::Xaml::Navigation::NavigatingCancelEventHandler & value) const;
    using Navigating_revoker = event_revoker<IFrame>;
    Navigating_revoker Navigating(auto_revoke_t, const Windows::UI::Xaml::Navigation::NavigatingCancelEventHandler & value) const;
    void Navigating(event_token token) const;
    event_token NavigationFailed(const Windows::UI::Xaml::Navigation::NavigationFailedEventHandler & value) const;
    using NavigationFailed_revoker = event_revoker<IFrame>;
    NavigationFailed_revoker NavigationFailed(auto_revoke_t, const Windows::UI::Xaml::Navigation::NavigationFailedEventHandler & value) const;
    void NavigationFailed(event_token token) const;
    event_token NavigationStopped(const Windows::UI::Xaml::Navigation::NavigationStoppedEventHandler & value) const;
    using NavigationStopped_revoker = event_revoker<IFrame>;
    NavigationStopped_revoker NavigationStopped(auto_revoke_t, const Windows::UI::Xaml::Navigation::NavigationStoppedEventHandler & value) const;
    void NavigationStopped(event_token token) const;
    void GoBack() const;
    void GoForward() const;
    bool Navigate(const Windows::UI::Xaml::Interop::TypeName & sourcePageType, const Windows::Foundation::IInspectable & parameter) const;
    hstring GetNavigationState() const;
    void SetNavigationState(hstring_view navigationState) const;
};

template <typename D>
struct WINRT_EBO impl_IFrame2
{
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Navigation::PageStackEntry> BackStack() const;
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Navigation::PageStackEntry> ForwardStack() const;
    bool Navigate(const Windows::UI::Xaml::Interop::TypeName & sourcePageType, const Windows::Foundation::IInspectable & parameter, const Windows::UI::Xaml::Media::Animation::NavigationTransitionInfo & infoOverride) const;
};

template <typename D>
struct WINRT_EBO impl_IFrame3
{
    void GoBack(const Windows::UI::Xaml::Media::Animation::NavigationTransitionInfo & transitionInfoOverride) const;
};

template <typename D>
struct WINRT_EBO impl_IFrameFactory
{
    Windows::UI::Xaml::Controls::Frame CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IFrameStatics
{
    Windows::UI::Xaml::DependencyProperty CacheSizeProperty() const;
    Windows::UI::Xaml::DependencyProperty CanGoBackProperty() const;
    Windows::UI::Xaml::DependencyProperty CanGoForwardProperty() const;
    Windows::UI::Xaml::DependencyProperty CurrentSourcePageTypeProperty() const;
    Windows::UI::Xaml::DependencyProperty SourcePageTypeProperty() const;
    Windows::UI::Xaml::DependencyProperty BackStackDepthProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IFrameStatics2
{
    Windows::UI::Xaml::DependencyProperty BackStackProperty() const;
    Windows::UI::Xaml::DependencyProperty ForwardStackProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IGrid
{
    Windows::UI::Xaml::Controls::RowDefinitionCollection RowDefinitions() const;
    Windows::UI::Xaml::Controls::ColumnDefinitionCollection ColumnDefinitions() const;
};

template <typename D>
struct WINRT_EBO impl_IGrid2
{
    Windows::UI::Xaml::Media::Brush BorderBrush() const;
    void BorderBrush(const Windows::UI::Xaml::Media::Brush & value) const;
    Windows::UI::Xaml::Thickness BorderThickness() const;
    void BorderThickness(const Windows::UI::Xaml::Thickness & value) const;
    Windows::UI::Xaml::CornerRadius CornerRadius() const;
    void CornerRadius(const Windows::UI::Xaml::CornerRadius & value) const;
    Windows::UI::Xaml::Thickness Padding() const;
    void Padding(const Windows::UI::Xaml::Thickness & value) const;
};

template <typename D>
struct WINRT_EBO impl_IGridFactory
{
    Windows::UI::Xaml::Controls::Grid CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IGridStatics
{
    Windows::UI::Xaml::DependencyProperty RowProperty() const;
    int32_t GetRow(const Windows::UI::Xaml::FrameworkElement & element) const;
    void SetRow(const Windows::UI::Xaml::FrameworkElement & element, int32_t value) const;
    Windows::UI::Xaml::DependencyProperty ColumnProperty() const;
    int32_t GetColumn(const Windows::UI::Xaml::FrameworkElement & element) const;
    void SetColumn(const Windows::UI::Xaml::FrameworkElement & element, int32_t value) const;
    Windows::UI::Xaml::DependencyProperty RowSpanProperty() const;
    int32_t GetRowSpan(const Windows::UI::Xaml::FrameworkElement & element) const;
    void SetRowSpan(const Windows::UI::Xaml::FrameworkElement & element, int32_t value) const;
    Windows::UI::Xaml::DependencyProperty ColumnSpanProperty() const;
    int32_t GetColumnSpan(const Windows::UI::Xaml::FrameworkElement & element) const;
    void SetColumnSpan(const Windows::UI::Xaml::FrameworkElement & element, int32_t value) const;
};

template <typename D>
struct WINRT_EBO impl_IGridStatics2
{
    Windows::UI::Xaml::DependencyProperty BorderBrushProperty() const;
    Windows::UI::Xaml::DependencyProperty BorderThicknessProperty() const;
    Windows::UI::Xaml::DependencyProperty CornerRadiusProperty() const;
    Windows::UI::Xaml::DependencyProperty PaddingProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IGridView
{
};

template <typename D>
struct WINRT_EBO impl_IGridViewFactory
{
    Windows::UI::Xaml::Controls::GridView CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IGridViewHeaderItem
{
};

template <typename D>
struct WINRT_EBO impl_IGridViewHeaderItemFactory
{
    Windows::UI::Xaml::Controls::GridViewHeaderItem CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IGridViewItem
{
    Windows::UI::Xaml::Controls::Primitives::GridViewItemTemplateSettings TemplateSettings() const;
};

template <typename D>
struct WINRT_EBO impl_IGridViewItemFactory
{
    Windows::UI::Xaml::Controls::GridViewItem CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IGroupItem
{
};

template <typename D>
struct WINRT_EBO impl_IGroupItemFactory
{
    Windows::UI::Xaml::Controls::GroupItem CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IGroupStyle
{
    Windows::UI::Xaml::Controls::ItemsPanelTemplate Panel() const;
    void Panel(const Windows::UI::Xaml::Controls::ItemsPanelTemplate & value) const;
    [[deprecated("ContainerStyle may be altered or unavailable for releases after Windows 8.1, and is not supported for ItemsControl.GroupStyle.")]] Windows::UI::Xaml::Style ContainerStyle() const;
    [[deprecated("ContainerStyle may be altered or unavailable for releases after Windows 8.1, and is not supported for ItemsControl.GroupStyle.")]] void ContainerStyle(const Windows::UI::Xaml::Style & value) const;
    [[deprecated("ContainerStyleSelector may be altered or unavailable for releases after Windows 8.1, and is not supported for ItemsControl.GroupStyle.")]] Windows::UI::Xaml::Controls::StyleSelector ContainerStyleSelector() const;
    [[deprecated("ContainerStyleSelector may be altered or unavailable for releases after Windows 8.1, and is not supported for ItemsControl.GroupStyle.")]] void ContainerStyleSelector(const Windows::UI::Xaml::Controls::StyleSelector & value) const;
    Windows::UI::Xaml::DataTemplate HeaderTemplate() const;
    void HeaderTemplate(const Windows::UI::Xaml::DataTemplate & value) const;
    Windows::UI::Xaml::Controls::DataTemplateSelector HeaderTemplateSelector() const;
    void HeaderTemplateSelector(const Windows::UI::Xaml::Controls::DataTemplateSelector & value) const;
    bool HidesIfEmpty() const;
    void HidesIfEmpty(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IGroupStyle2
{
    Windows::UI::Xaml::Style HeaderContainerStyle() const;
    void HeaderContainerStyle(const Windows::UI::Xaml::Style & value) const;
};

template <typename D>
struct WINRT_EBO impl_IGroupStyleFactory
{
    Windows::UI::Xaml::Controls::GroupStyle CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IGroupStyleSelector
{
    Windows::UI::Xaml::Controls::GroupStyle SelectGroupStyle(const Windows::Foundation::IInspectable & group, uint32_t level) const;
};

template <typename D>
struct WINRT_EBO impl_IGroupStyleSelectorFactory
{
    Windows::UI::Xaml::Controls::GroupStyleSelector CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IGroupStyleSelectorOverrides
{
    Windows::UI::Xaml::Controls::GroupStyle SelectGroupStyleCore(const Windows::Foundation::IInspectable & group, uint32_t level) const;
};

template <typename D>
struct WINRT_EBO impl_IHub
{
    Windows::Foundation::IInspectable Header() const;
    void Header(const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::DataTemplate HeaderTemplate() const;
    void HeaderTemplate(const Windows::UI::Xaml::DataTemplate & value) const;
    Windows::UI::Xaml::Controls::Orientation Orientation() const;
    void Orientation(Windows::UI::Xaml::Controls::Orientation value) const;
    int32_t DefaultSectionIndex() const;
    void DefaultSectionIndex(int32_t value) const;
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::HubSection> Sections() const;
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::HubSection> SectionsInView() const;
    Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> SectionHeaders() const;
    event_token SectionHeaderClick(const Windows::UI::Xaml::Controls::HubSectionHeaderClickEventHandler & value) const;
    using SectionHeaderClick_revoker = event_revoker<IHub>;
    SectionHeaderClick_revoker SectionHeaderClick(auto_revoke_t, const Windows::UI::Xaml::Controls::HubSectionHeaderClickEventHandler & value) const;
    void SectionHeaderClick(event_token token) const;
    event_token SectionsInViewChanged(const Windows::UI::Xaml::Controls::SectionsInViewChangedEventHandler & value) const;
    using SectionsInViewChanged_revoker = event_revoker<IHub>;
    SectionsInViewChanged_revoker SectionsInViewChanged(auto_revoke_t, const Windows::UI::Xaml::Controls::SectionsInViewChangedEventHandler & value) const;
    void SectionsInViewChanged(event_token token) const;
    void ScrollToSection(const Windows::UI::Xaml::Controls::HubSection & section) const;
};

template <typename D>
struct WINRT_EBO impl_IHubFactory
{
    Windows::UI::Xaml::Controls::Hub CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IHubSection
{
    Windows::Foundation::IInspectable Header() const;
    void Header(const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::DataTemplate HeaderTemplate() const;
    void HeaderTemplate(const Windows::UI::Xaml::DataTemplate & value) const;
    Windows::UI::Xaml::DataTemplate ContentTemplate() const;
    void ContentTemplate(const Windows::UI::Xaml::DataTemplate & value) const;
    bool IsHeaderInteractive() const;
    void IsHeaderInteractive(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IHubSectionFactory
{
    Windows::UI::Xaml::Controls::HubSection CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IHubSectionHeaderClickEventArgs
{
    Windows::UI::Xaml::Controls::HubSection Section() const;
};

template <typename D>
struct WINRT_EBO impl_IHubSectionStatics
{
    Windows::UI::Xaml::DependencyProperty HeaderProperty() const;
    Windows::UI::Xaml::DependencyProperty HeaderTemplateProperty() const;
    Windows::UI::Xaml::DependencyProperty ContentTemplateProperty() const;
    Windows::UI::Xaml::DependencyProperty IsHeaderInteractiveProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IHubStatics
{
    Windows::UI::Xaml::DependencyProperty HeaderProperty() const;
    Windows::UI::Xaml::DependencyProperty HeaderTemplateProperty() const;
    Windows::UI::Xaml::DependencyProperty OrientationProperty() const;
    Windows::UI::Xaml::DependencyProperty DefaultSectionIndexProperty() const;
    Windows::UI::Xaml::DependencyProperty SemanticZoomOwnerProperty() const;
    Windows::UI::Xaml::DependencyProperty IsActiveViewProperty() const;
    Windows::UI::Xaml::DependencyProperty IsZoomedInViewProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IHyperlinkButton
{
    Windows::Foundation::Uri NavigateUri() const;
    void NavigateUri(const Windows::Foundation::Uri & value) const;
};

template <typename D>
struct WINRT_EBO impl_IHyperlinkButtonFactory
{
    Windows::UI::Xaml::Controls::HyperlinkButton CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IHyperlinkButtonStatics
{
    Windows::UI::Xaml::DependencyProperty NavigateUriProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IIconElement
{
    Windows::UI::Xaml::Media::Brush Foreground() const;
    void Foreground(const Windows::UI::Xaml::Media::Brush & value) const;
};

template <typename D>
struct WINRT_EBO impl_IIconElementFactory
{
};

template <typename D>
struct WINRT_EBO impl_IIconElementStatics
{
    Windows::UI::Xaml::DependencyProperty ForegroundProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IImage
{
    Windows::UI::Xaml::Media::ImageSource Source() const;
    void Source(const Windows::UI::Xaml::Media::ImageSource & value) const;
    Windows::UI::Xaml::Media::Stretch Stretch() const;
    void Stretch(Windows::UI::Xaml::Media::Stretch value) const;
    Windows::UI::Xaml::Thickness NineGrid() const;
    void NineGrid(const Windows::UI::Xaml::Thickness & value) const;
    [[deprecated("PlayToSource may be altered or unavailable for releases after Windows 10.0. Instead, use GetAsCastingSource.")]] Windows::Media::PlayTo::PlayToSource PlayToSource() const;
    event_token ImageFailed(const Windows::UI::Xaml::ExceptionRoutedEventHandler & value) const;
    using ImageFailed_revoker = event_revoker<IImage>;
    ImageFailed_revoker ImageFailed(auto_revoke_t, const Windows::UI::Xaml::ExceptionRoutedEventHandler & value) const;
    void ImageFailed(event_token token) const;
    event_token ImageOpened(const Windows::UI::Xaml::RoutedEventHandler & value) const;
    using ImageOpened_revoker = event_revoker<IImage>;
    ImageOpened_revoker ImageOpened(auto_revoke_t, const Windows::UI::Xaml::RoutedEventHandler & value) const;
    void ImageOpened(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IImage2
{
    Windows::Media::Casting::CastingSource GetAsCastingSource() const;
};

template <typename D>
struct WINRT_EBO impl_IImage3
{
    Windows::UI::Composition::CompositionBrush GetAlphaMask() const;
};

template <typename D>
struct WINRT_EBO impl_IImageStatics
{
    Windows::UI::Xaml::DependencyProperty SourceProperty() const;
    Windows::UI::Xaml::DependencyProperty StretchProperty() const;
    Windows::UI::Xaml::DependencyProperty NineGridProperty() const;
    [[deprecated("PlayToSource may be altered or unavailable for releases after Windows 10.0. Instead, use GetAsCastingSource.")]] Windows::UI::Xaml::DependencyProperty PlayToSourceProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IInkCanvas
{
    Windows::UI::Input::Inking::InkPresenter InkPresenter() const;
};

template <typename D>
struct WINRT_EBO impl_IInkCanvasFactory
{
    Windows::UI::Xaml::Controls::InkCanvas CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IInkToolbar
{
    Windows::UI::Xaml::Controls::InkToolbarInitialControls InitialControls() const;
    void InitialControls(Windows::UI::Xaml::Controls::InkToolbarInitialControls value) const;
    Windows::UI::Xaml::DependencyObjectCollection Children() const;
    Windows::UI::Xaml::Controls::InkToolbarToolButton ActiveTool() const;
    void ActiveTool(const Windows::UI::Xaml::Controls::InkToolbarToolButton & value) const;
    Windows::UI::Input::Inking::InkDrawingAttributes InkDrawingAttributes() const;
    bool IsRulerButtonChecked() const;
    void IsRulerButtonChecked(bool value) const;
    Windows::UI::Xaml::Controls::InkCanvas TargetInkCanvas() const;
    void TargetInkCanvas(const Windows::UI::Xaml::Controls::InkCanvas & value) const;
    event_token ActiveToolChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::InkToolbar, Windows::Foundation::IInspectable> & value) const;
    using ActiveToolChanged_revoker = event_revoker<IInkToolbar>;
    ActiveToolChanged_revoker ActiveToolChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::InkToolbar, Windows::Foundation::IInspectable> & value) const;
    void ActiveToolChanged(event_token token) const;
    event_token InkDrawingAttributesChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::InkToolbar, Windows::Foundation::IInspectable> & value) const;
    using InkDrawingAttributesChanged_revoker = event_revoker<IInkToolbar>;
    InkDrawingAttributesChanged_revoker InkDrawingAttributesChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::InkToolbar, Windows::Foundation::IInspectable> & value) const;
    void InkDrawingAttributesChanged(event_token token) const;
    event_token EraseAllClicked(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::InkToolbar, Windows::Foundation::IInspectable> & value) const;
    using EraseAllClicked_revoker = event_revoker<IInkToolbar>;
    EraseAllClicked_revoker EraseAllClicked(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::InkToolbar, Windows::Foundation::IInspectable> & value) const;
    void EraseAllClicked(event_token token) const;
    event_token IsRulerButtonCheckedChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::InkToolbar, Windows::Foundation::IInspectable> & value) const;
    using IsRulerButtonCheckedChanged_revoker = event_revoker<IInkToolbar>;
    IsRulerButtonCheckedChanged_revoker IsRulerButtonCheckedChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::InkToolbar, Windows::Foundation::IInspectable> & value) const;
    void IsRulerButtonCheckedChanged(event_token token) const;
    Windows::UI::Xaml::Controls::InkToolbarToolButton GetToolButton(Windows::UI::Xaml::Controls::InkToolbarTool tool) const;
    Windows::UI::Xaml::Controls::InkToolbarToggleButton GetToggleButton(Windows::UI::Xaml::Controls::InkToolbarToggle tool) const;
};

template <typename D>
struct WINRT_EBO impl_IInkToolbarBallpointPenButton
{
};

template <typename D>
struct WINRT_EBO impl_IInkToolbarBallpointPenButtonFactory
{
    Windows::UI::Xaml::Controls::InkToolbarBallpointPenButton CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IInkToolbarCustomPen
{
    Windows::UI::Input::Inking::InkDrawingAttributes CreateInkDrawingAttributes(const Windows::UI::Xaml::Media::Brush & brush, double strokeWidth) const;
};

template <typename D>
struct WINRT_EBO impl_IInkToolbarCustomPenButton
{
    Windows::UI::Xaml::Controls::InkToolbarCustomPen CustomPen() const;
    void CustomPen(const Windows::UI::Xaml::Controls::InkToolbarCustomPen & value) const;
    Windows::UI::Xaml::UIElement ConfigurationContent() const;
    void ConfigurationContent(const Windows::UI::Xaml::UIElement & value) const;
};

template <typename D>
struct WINRT_EBO impl_IInkToolbarCustomPenButtonFactory
{
    Windows::UI::Xaml::Controls::InkToolbarCustomPenButton CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IInkToolbarCustomPenButtonStatics
{
    Windows::UI::Xaml::DependencyProperty CustomPenProperty() const;
    Windows::UI::Xaml::DependencyProperty ConfigurationContentProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IInkToolbarCustomPenFactory
{
    Windows::UI::Xaml::Controls::InkToolbarCustomPen CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IInkToolbarCustomPenOverrides
{
    Windows::UI::Input::Inking::InkDrawingAttributes CreateInkDrawingAttributesCore(const Windows::UI::Xaml::Media::Brush & brush, double strokeWidth) const;
};

template <typename D>
struct WINRT_EBO impl_IInkToolbarCustomToggleButton
{
};

template <typename D>
struct WINRT_EBO impl_IInkToolbarCustomToggleButtonFactory
{
    Windows::UI::Xaml::Controls::InkToolbarCustomToggleButton CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IInkToolbarCustomToolButton
{
    Windows::UI::Xaml::UIElement ConfigurationContent() const;
    void ConfigurationContent(const Windows::UI::Xaml::UIElement & value) const;
};

template <typename D>
struct WINRT_EBO impl_IInkToolbarCustomToolButtonFactory
{
    Windows::UI::Xaml::Controls::InkToolbarCustomToolButton CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IInkToolbarCustomToolButtonStatics
{
    Windows::UI::Xaml::DependencyProperty ConfigurationContentProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IInkToolbarEraserButton
{
};

template <typename D>
struct WINRT_EBO impl_IInkToolbarEraserButtonFactory
{
    Windows::UI::Xaml::Controls::InkToolbarEraserButton CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IInkToolbarFactory
{
    Windows::UI::Xaml::Controls::InkToolbar CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IInkToolbarHighlighterButton
{
};

template <typename D>
struct WINRT_EBO impl_IInkToolbarHighlighterButtonFactory
{
    Windows::UI::Xaml::Controls::InkToolbarHighlighterButton CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IInkToolbarPenButton
{
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Brush> Palette() const;
    void Palette(const Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Brush> & value) const;
    double MinStrokeWidth() const;
    void MinStrokeWidth(double value) const;
    double MaxStrokeWidth() const;
    void MaxStrokeWidth(double value) const;
    Windows::UI::Xaml::Media::Brush SelectedBrush() const;
    int32_t SelectedBrushIndex() const;
    void SelectedBrushIndex(int32_t value) const;
    double SelectedStrokeWidth() const;
    void SelectedStrokeWidth(double value) const;
};

template <typename D>
struct WINRT_EBO impl_IInkToolbarPenButtonFactory
{
};

template <typename D>
struct WINRT_EBO impl_IInkToolbarPenButtonStatics
{
    Windows::UI::Xaml::DependencyProperty PaletteProperty() const;
    Windows::UI::Xaml::DependencyProperty MinStrokeWidthProperty() const;
    Windows::UI::Xaml::DependencyProperty MaxStrokeWidthProperty() const;
    Windows::UI::Xaml::DependencyProperty SelectedBrushProperty() const;
    Windows::UI::Xaml::DependencyProperty SelectedBrushIndexProperty() const;
    Windows::UI::Xaml::DependencyProperty SelectedStrokeWidthProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IInkToolbarPenConfigurationControl
{
    Windows::UI::Xaml::Controls::InkToolbarPenButton PenButton() const;
};

template <typename D>
struct WINRT_EBO impl_IInkToolbarPenConfigurationControlFactory
{
    Windows::UI::Xaml::Controls::InkToolbarPenConfigurationControl CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IInkToolbarPenConfigurationControlStatics
{
    Windows::UI::Xaml::DependencyProperty PenButtonProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IInkToolbarPencilButton
{
};

template <typename D>
struct WINRT_EBO impl_IInkToolbarPencilButtonFactory
{
    Windows::UI::Xaml::Controls::InkToolbarPencilButton CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IInkToolbarRulerButton
{
    Windows::UI::Input::Inking::InkPresenterRuler Ruler() const;
};

template <typename D>
struct WINRT_EBO impl_IInkToolbarRulerButtonFactory
{
    Windows::UI::Xaml::Controls::InkToolbarRulerButton CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IInkToolbarRulerButtonStatics
{
    Windows::UI::Xaml::DependencyProperty RulerProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IInkToolbarStatics
{
    Windows::UI::Xaml::DependencyProperty InitialControlsProperty() const;
    Windows::UI::Xaml::DependencyProperty ChildrenProperty() const;
    Windows::UI::Xaml::DependencyProperty ActiveToolProperty() const;
    Windows::UI::Xaml::DependencyProperty InkDrawingAttributesProperty() const;
    Windows::UI::Xaml::DependencyProperty IsRulerButtonCheckedProperty() const;
    Windows::UI::Xaml::DependencyProperty TargetInkCanvasProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IInkToolbarToggleButton
{
    Windows::UI::Xaml::Controls::InkToolbarToggle ToggleKind() const;
};

template <typename D>
struct WINRT_EBO impl_IInkToolbarToggleButtonFactory
{
};

template <typename D>
struct WINRT_EBO impl_IInkToolbarToolButton
{
    Windows::UI::Xaml::Controls::InkToolbarTool ToolKind() const;
    bool IsExtensionGlyphShown() const;
    void IsExtensionGlyphShown(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IInkToolbarToolButtonFactory
{
};

template <typename D>
struct WINRT_EBO impl_IInkToolbarToolButtonStatics
{
    Windows::UI::Xaml::DependencyProperty IsExtensionGlyphShownProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IInsertionPanel
{
    void GetInsertionIndexes(const Windows::Foundation::Point & position, int32_t & first, int32_t & second) const;
};

template <typename D>
struct WINRT_EBO impl_IItemClickEventArgs
{
    Windows::Foundation::IInspectable ClickedItem() const;
};

template <typename D>
struct WINRT_EBO impl_IItemContainerGenerator
{
    event_token ItemsChanged(const Windows::UI::Xaml::Controls::Primitives::ItemsChangedEventHandler & value) const;
    using ItemsChanged_revoker = event_revoker<IItemContainerGenerator>;
    ItemsChanged_revoker ItemsChanged(auto_revoke_t, const Windows::UI::Xaml::Controls::Primitives::ItemsChangedEventHandler & value) const;
    void ItemsChanged(event_token token) const;
    [[deprecated("ItemFromContainer may be altered or unavailable for releases after Windows 8.1. Instead, use ItemsControl.ItemFromContainer.")]] Windows::Foundation::IInspectable ItemFromContainer(const Windows::UI::Xaml::DependencyObject & container) const;
    [[deprecated("ContainerFromItem may be altered or unavailable for releases after Windows 8.1. Instead, use ItemsControl.ContainerFromItem.")]] Windows::UI::Xaml::DependencyObject ContainerFromItem(const Windows::Foundation::IInspectable & item) const;
    [[deprecated("IndexFromContainer may be altered or unavailable for releases after Windows 8.1. Instead, use ItemsControl.IndexFromContainer.")]] int32_t IndexFromContainer(const Windows::UI::Xaml::DependencyObject & container) const;
    [[deprecated("ContainerFromIndex may be altered or unavailable for releases after Windows 8.1. Instead, use ItemsControl.ContainerFromIndex.")]] Windows::UI::Xaml::DependencyObject ContainerFromIndex(int32_t index) const;
    Windows::UI::Xaml::Controls::ItemContainerGenerator GetItemContainerGeneratorForPanel(const Windows::UI::Xaml::Controls::Panel & panel) const;
    void StartAt(const Windows::UI::Xaml::Controls::Primitives::GeneratorPosition & position, Windows::UI::Xaml::Controls::Primitives::GeneratorDirection direction, bool allowStartAtRealizedItem) const;
    void Stop() const;
    Windows::UI::Xaml::DependencyObject GenerateNext(bool & isNewlyRealized) const;
    void PrepareItemContainer(const Windows::UI::Xaml::DependencyObject & container) const;
    void RemoveAll() const;
    void Remove(const Windows::UI::Xaml::Controls::Primitives::GeneratorPosition & position, int32_t count) const;
    Windows::UI::Xaml::Controls::Primitives::GeneratorPosition GeneratorPositionFromIndex(int32_t itemIndex) const;
    int32_t IndexFromGeneratorPosition(const Windows::UI::Xaml::Controls::Primitives::GeneratorPosition & position) const;
    void Recycle(const Windows::UI::Xaml::Controls::Primitives::GeneratorPosition & position, int32_t count) const;
};

template <typename D>
struct WINRT_EBO impl_IItemContainerMapping
{
    Windows::Foundation::IInspectable ItemFromContainer(const Windows::UI::Xaml::DependencyObject & container) const;
    Windows::UI::Xaml::DependencyObject ContainerFromItem(const Windows::Foundation::IInspectable & item) const;
    int32_t IndexFromContainer(const Windows::UI::Xaml::DependencyObject & container) const;
    Windows::UI::Xaml::DependencyObject ContainerFromIndex(int32_t index) const;
};

template <typename D>
struct WINRT_EBO impl_IItemsControl
{
    Windows::Foundation::IInspectable ItemsSource() const;
    void ItemsSource(const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::Controls::ItemCollection Items() const;
    Windows::UI::Xaml::DataTemplate ItemTemplate() const;
    void ItemTemplate(const Windows::UI::Xaml::DataTemplate & value) const;
    Windows::UI::Xaml::Controls::DataTemplateSelector ItemTemplateSelector() const;
    void ItemTemplateSelector(const Windows::UI::Xaml::Controls::DataTemplateSelector & value) const;
    Windows::UI::Xaml::Controls::ItemsPanelTemplate ItemsPanel() const;
    void ItemsPanel(const Windows::UI::Xaml::Controls::ItemsPanelTemplate & value) const;
    hstring DisplayMemberPath() const;
    void DisplayMemberPath(hstring_view value) const;
    Windows::UI::Xaml::Style ItemContainerStyle() const;
    void ItemContainerStyle(const Windows::UI::Xaml::Style & value) const;
    Windows::UI::Xaml::Controls::StyleSelector ItemContainerStyleSelector() const;
    void ItemContainerStyleSelector(const Windows::UI::Xaml::Controls::StyleSelector & value) const;
    Windows::UI::Xaml::Controls::ItemContainerGenerator ItemContainerGenerator() const;
    Windows::UI::Xaml::Media::Animation::TransitionCollection ItemContainerTransitions() const;
    void ItemContainerTransitions(const Windows::UI::Xaml::Media::Animation::TransitionCollection & value) const;
    Windows::Foundation::Collections::IObservableVector<Windows::UI::Xaml::Controls::GroupStyle> GroupStyle() const;
    Windows::UI::Xaml::Controls::GroupStyleSelector GroupStyleSelector() const;
    void GroupStyleSelector(const Windows::UI::Xaml::Controls::GroupStyleSelector & value) const;
    bool IsGrouping() const;
};

template <typename D>
struct WINRT_EBO impl_IItemsControl2
{
    Windows::UI::Xaml::Controls::Panel ItemsPanelRoot() const;
};

template <typename D>
struct WINRT_EBO impl_IItemsControl3
{
    Windows::UI::Xaml::DependencyObject GroupHeaderContainerFromItemContainer(const Windows::UI::Xaml::DependencyObject & itemContainer) const;
};

template <typename D>
struct WINRT_EBO impl_IItemsControlFactory
{
    Windows::UI::Xaml::Controls::ItemsControl CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IItemsControlOverrides
{
    bool IsItemItsOwnContainerOverride(const Windows::Foundation::IInspectable & item) const;
    Windows::UI::Xaml::DependencyObject GetContainerForItemOverride() const;
    void ClearContainerForItemOverride(const Windows::UI::Xaml::DependencyObject & element, const Windows::Foundation::IInspectable & item) const;
    void PrepareContainerForItemOverride(const Windows::UI::Xaml::DependencyObject & element, const Windows::Foundation::IInspectable & item) const;
    void OnItemsChanged(const Windows::Foundation::IInspectable & e) const;
    void OnItemContainerStyleChanged(const Windows::UI::Xaml::Style & oldItemContainerStyle, const Windows::UI::Xaml::Style & newItemContainerStyle) const;
    void OnItemContainerStyleSelectorChanged(const Windows::UI::Xaml::Controls::StyleSelector & oldItemContainerStyleSelector, const Windows::UI::Xaml::Controls::StyleSelector & newItemContainerStyleSelector) const;
    void OnItemTemplateChanged(const Windows::UI::Xaml::DataTemplate & oldItemTemplate, const Windows::UI::Xaml::DataTemplate & newItemTemplate) const;
    void OnItemTemplateSelectorChanged(const Windows::UI::Xaml::Controls::DataTemplateSelector & oldItemTemplateSelector, const Windows::UI::Xaml::Controls::DataTemplateSelector & newItemTemplateSelector) const;
    void OnGroupStyleSelectorChanged(const Windows::UI::Xaml::Controls::GroupStyleSelector & oldGroupStyleSelector, const Windows::UI::Xaml::Controls::GroupStyleSelector & newGroupStyleSelector) const;
};

template <typename D>
struct WINRT_EBO impl_IItemsControlStatics
{
    Windows::UI::Xaml::DependencyProperty ItemsSourceProperty() const;
    Windows::UI::Xaml::DependencyProperty ItemTemplateProperty() const;
    Windows::UI::Xaml::DependencyProperty ItemTemplateSelectorProperty() const;
    Windows::UI::Xaml::DependencyProperty ItemsPanelProperty() const;
    Windows::UI::Xaml::DependencyProperty DisplayMemberPathProperty() const;
    Windows::UI::Xaml::DependencyProperty ItemContainerStyleProperty() const;
    Windows::UI::Xaml::DependencyProperty ItemContainerStyleSelectorProperty() const;
    Windows::UI::Xaml::DependencyProperty ItemContainerTransitionsProperty() const;
    Windows::UI::Xaml::DependencyProperty GroupStyleSelectorProperty() const;
    Windows::UI::Xaml::DependencyProperty IsGroupingProperty() const;
    Windows::UI::Xaml::Controls::ItemsControl GetItemsOwner(const Windows::UI::Xaml::DependencyObject & element) const;
    Windows::UI::Xaml::Controls::ItemsControl ItemsControlFromItemContainer(const Windows::UI::Xaml::DependencyObject & container) const;
};

template <typename D>
struct WINRT_EBO impl_IItemsPanelTemplate
{
};

template <typename D>
struct WINRT_EBO impl_IItemsPickedEventArgs
{
    Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> AddedItems() const;
    Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> RemovedItems() const;
};

template <typename D>
struct WINRT_EBO impl_IItemsPresenter
{
    Windows::Foundation::IInspectable Header() const;
    void Header(const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::DataTemplate HeaderTemplate() const;
    void HeaderTemplate(const Windows::UI::Xaml::DataTemplate & value) const;
    Windows::UI::Xaml::Media::Animation::TransitionCollection HeaderTransitions() const;
    void HeaderTransitions(const Windows::UI::Xaml::Media::Animation::TransitionCollection & value) const;
    Windows::UI::Xaml::Thickness Padding() const;
    void Padding(const Windows::UI::Xaml::Thickness & value) const;
};

template <typename D>
struct WINRT_EBO impl_IItemsPresenter2
{
    Windows::Foundation::IInspectable Footer() const;
    void Footer(const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::DataTemplate FooterTemplate() const;
    void FooterTemplate(const Windows::UI::Xaml::DataTemplate & value) const;
    Windows::UI::Xaml::Media::Animation::TransitionCollection FooterTransitions() const;
    void FooterTransitions(const Windows::UI::Xaml::Media::Animation::TransitionCollection & value) const;
};

template <typename D>
struct WINRT_EBO impl_IItemsPresenterStatics
{
    Windows::UI::Xaml::DependencyProperty HeaderProperty() const;
    Windows::UI::Xaml::DependencyProperty HeaderTemplateProperty() const;
    Windows::UI::Xaml::DependencyProperty HeaderTransitionsProperty() const;
    Windows::UI::Xaml::DependencyProperty PaddingProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IItemsPresenterStatics2
{
    Windows::UI::Xaml::DependencyProperty FooterProperty() const;
    Windows::UI::Xaml::DependencyProperty FooterTemplateProperty() const;
    Windows::UI::Xaml::DependencyProperty FooterTransitionsProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IItemsStackPanel
{
    Windows::UI::Xaml::Thickness GroupPadding() const;
    void GroupPadding(const Windows::UI::Xaml::Thickness & value) const;
    Windows::UI::Xaml::Controls::Orientation Orientation() const;
    void Orientation(Windows::UI::Xaml::Controls::Orientation value) const;
    int32_t FirstCacheIndex() const;
    int32_t FirstVisibleIndex() const;
    int32_t LastVisibleIndex() const;
    int32_t LastCacheIndex() const;
    Windows::UI::Xaml::Controls::PanelScrollingDirection ScrollingDirection() const;
    Windows::UI::Xaml::Controls::Primitives::GroupHeaderPlacement GroupHeaderPlacement() const;
    void GroupHeaderPlacement(Windows::UI::Xaml::Controls::Primitives::GroupHeaderPlacement value) const;
    Windows::UI::Xaml::Controls::ItemsUpdatingScrollMode ItemsUpdatingScrollMode() const;
    void ItemsUpdatingScrollMode(Windows::UI::Xaml::Controls::ItemsUpdatingScrollMode value) const;
    double CacheLength() const;
    void CacheLength(double value) const;
};

template <typename D>
struct WINRT_EBO impl_IItemsStackPanel2
{
    bool AreStickyGroupHeadersEnabled() const;
    void AreStickyGroupHeadersEnabled(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IItemsStackPanelStatics
{
    Windows::UI::Xaml::DependencyProperty GroupPaddingProperty() const;
    Windows::UI::Xaml::DependencyProperty OrientationProperty() const;
    Windows::UI::Xaml::DependencyProperty GroupHeaderPlacementProperty() const;
    Windows::UI::Xaml::DependencyProperty CacheLengthProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IItemsStackPanelStatics2
{
    Windows::UI::Xaml::DependencyProperty AreStickyGroupHeadersEnabledProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IItemsWrapGrid
{
    Windows::UI::Xaml::Thickness GroupPadding() const;
    void GroupPadding(const Windows::UI::Xaml::Thickness & value) const;
    Windows::UI::Xaml::Controls::Orientation Orientation() const;
    void Orientation(Windows::UI::Xaml::Controls::Orientation value) const;
    int32_t MaximumRowsOrColumns() const;
    void MaximumRowsOrColumns(int32_t value) const;
    double ItemWidth() const;
    void ItemWidth(double value) const;
    double ItemHeight() const;
    void ItemHeight(double value) const;
    int32_t FirstCacheIndex() const;
    int32_t FirstVisibleIndex() const;
    int32_t LastVisibleIndex() const;
    int32_t LastCacheIndex() const;
    Windows::UI::Xaml::Controls::PanelScrollingDirection ScrollingDirection() const;
    Windows::UI::Xaml::Controls::Primitives::GroupHeaderPlacement GroupHeaderPlacement() const;
    void GroupHeaderPlacement(Windows::UI::Xaml::Controls::Primitives::GroupHeaderPlacement value) const;
    double CacheLength() const;
    void CacheLength(double value) const;
};

template <typename D>
struct WINRT_EBO impl_IItemsWrapGrid2
{
    bool AreStickyGroupHeadersEnabled() const;
    void AreStickyGroupHeadersEnabled(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IItemsWrapGridStatics
{
    Windows::UI::Xaml::DependencyProperty GroupPaddingProperty() const;
    Windows::UI::Xaml::DependencyProperty OrientationProperty() const;
    Windows::UI::Xaml::DependencyProperty MaximumRowsOrColumnsProperty() const;
    Windows::UI::Xaml::DependencyProperty ItemWidthProperty() const;
    Windows::UI::Xaml::DependencyProperty ItemHeightProperty() const;
    Windows::UI::Xaml::DependencyProperty GroupHeaderPlacementProperty() const;
    Windows::UI::Xaml::DependencyProperty CacheLengthProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IItemsWrapGridStatics2
{
    Windows::UI::Xaml::DependencyProperty AreStickyGroupHeadersEnabledProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IListBox
{
    Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> SelectedItems() const;
    Windows::UI::Xaml::Controls::SelectionMode SelectionMode() const;
    void SelectionMode(Windows::UI::Xaml::Controls::SelectionMode value) const;
    void ScrollIntoView(const Windows::Foundation::IInspectable & item) const;
    void SelectAll() const;
};

template <typename D>
struct WINRT_EBO impl_IListBox2
{
    bool SingleSelectionFollowsFocus() const;
    void SingleSelectionFollowsFocus(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IListBoxFactory
{
    Windows::UI::Xaml::Controls::ListBox CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IListBoxItem
{
};

template <typename D>
struct WINRT_EBO impl_IListBoxItemFactory
{
    Windows::UI::Xaml::Controls::ListBoxItem CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IListBoxStatics
{
    Windows::UI::Xaml::DependencyProperty SelectionModeProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IListBoxStatics2
{
    Windows::UI::Xaml::DependencyProperty SingleSelectionFollowsFocusProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IListPickerFlyout
{
    Windows::Foundation::IInspectable ItemsSource() const;
    void ItemsSource(const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::DataTemplate ItemTemplate() const;
    void ItemTemplate(const Windows::UI::Xaml::DataTemplate & value) const;
    hstring DisplayMemberPath() const;
    void DisplayMemberPath(hstring_view value) const;
    Windows::UI::Xaml::Controls::ListPickerFlyoutSelectionMode SelectionMode() const;
    void SelectionMode(Windows::UI::Xaml::Controls::ListPickerFlyoutSelectionMode value) const;
    int32_t SelectedIndex() const;
    void SelectedIndex(int32_t value) const;
    Windows::Foundation::IInspectable SelectedItem() const;
    void SelectedItem(const Windows::Foundation::IInspectable & value) const;
    Windows::Foundation::IInspectable SelectedValue() const;
    void SelectedValue(const Windows::Foundation::IInspectable & value) const;
    hstring SelectedValuePath() const;
    void SelectedValuePath(hstring_view value) const;
    Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> SelectedItems() const;
    event_token ItemsPicked(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::ListPickerFlyout, Windows::UI::Xaml::Controls::ItemsPickedEventArgs> & value) const;
    using ItemsPicked_revoker = event_revoker<IListPickerFlyout>;
    ItemsPicked_revoker ItemsPicked(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::ListPickerFlyout, Windows::UI::Xaml::Controls::ItemsPickedEventArgs> & value) const;
    void ItemsPicked(event_token token) const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Foundation::IInspectable>> ShowAtAsync(const Windows::UI::Xaml::FrameworkElement & target) const;
};

template <typename D>
struct WINRT_EBO impl_IListPickerFlyoutPresenter
{
};

template <typename D>
struct WINRT_EBO impl_IListPickerFlyoutStatics
{
    Windows::UI::Xaml::DependencyProperty ItemsSourceProperty() const;
    Windows::UI::Xaml::DependencyProperty ItemTemplateProperty() const;
    Windows::UI::Xaml::DependencyProperty DisplayMemberPathProperty() const;
    Windows::UI::Xaml::DependencyProperty SelectionModeProperty() const;
    Windows::UI::Xaml::DependencyProperty SelectedIndexProperty() const;
    Windows::UI::Xaml::DependencyProperty SelectedItemProperty() const;
    Windows::UI::Xaml::DependencyProperty SelectedValueProperty() const;
    Windows::UI::Xaml::DependencyProperty SelectedValuePathProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IListView
{
};

template <typename D>
struct WINRT_EBO impl_IListViewBase
{
    Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> SelectedItems() const;
    Windows::UI::Xaml::Controls::ListViewSelectionMode SelectionMode() const;
    void SelectionMode(Windows::UI::Xaml::Controls::ListViewSelectionMode value) const;
    bool IsSwipeEnabled() const;
    void IsSwipeEnabled(bool value) const;
    bool CanDragItems() const;
    void CanDragItems(bool value) const;
    bool CanReorderItems() const;
    void CanReorderItems(bool value) const;
    bool IsItemClickEnabled() const;
    void IsItemClickEnabled(bool value) const;
    double DataFetchSize() const;
    void DataFetchSize(double value) const;
    double IncrementalLoadingThreshold() const;
    void IncrementalLoadingThreshold(double value) const;
    Windows::UI::Xaml::Controls::IncrementalLoadingTrigger IncrementalLoadingTrigger() const;
    void IncrementalLoadingTrigger(Windows::UI::Xaml::Controls::IncrementalLoadingTrigger value) const;
    event_token ItemClick(const Windows::UI::Xaml::Controls::ItemClickEventHandler & value) const;
    using ItemClick_revoker = event_revoker<IListViewBase>;
    ItemClick_revoker ItemClick(auto_revoke_t, const Windows::UI::Xaml::Controls::ItemClickEventHandler & value) const;
    void ItemClick(event_token token) const;
    event_token DragItemsStarting(const Windows::UI::Xaml::Controls::DragItemsStartingEventHandler & value) const;
    using DragItemsStarting_revoker = event_revoker<IListViewBase>;
    DragItemsStarting_revoker DragItemsStarting(auto_revoke_t, const Windows::UI::Xaml::Controls::DragItemsStartingEventHandler & value) const;
    void DragItemsStarting(event_token token) const;
    void ScrollIntoView(const Windows::Foundation::IInspectable & item) const;
    void SelectAll() const;
    Windows::Foundation::IAsyncOperation<Windows::UI::Xaml::Data::LoadMoreItemsResult> LoadMoreItemsAsync() const;
    void ScrollIntoView(const Windows::Foundation::IInspectable & item, Windows::UI::Xaml::Controls::ScrollIntoViewAlignment alignment) const;
    Windows::Foundation::IInspectable Header() const;
    void Header(const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::DataTemplate HeaderTemplate() const;
    void HeaderTemplate(const Windows::UI::Xaml::DataTemplate & value) const;
    Windows::UI::Xaml::Media::Animation::TransitionCollection HeaderTransitions() const;
    void HeaderTransitions(const Windows::UI::Xaml::Media::Animation::TransitionCollection & value) const;
};

template <typename D>
struct WINRT_EBO impl_IListViewBase2
{
    bool ShowsScrollingPlaceholders() const;
    void ShowsScrollingPlaceholders(bool value) const;
    event_token ContainerContentChanging(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::ListViewBase, Windows::UI::Xaml::Controls::ContainerContentChangingEventArgs> & value) const;
    using ContainerContentChanging_revoker = event_revoker<IListViewBase2>;
    ContainerContentChanging_revoker ContainerContentChanging(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::ListViewBase, Windows::UI::Xaml::Controls::ContainerContentChangingEventArgs> & value) const;
    void ContainerContentChanging(event_token token) const;
    void SetDesiredContainerUpdateDuration(const Windows::Foundation::TimeSpan & duration) const;
    Windows::Foundation::IInspectable Footer() const;
    void Footer(const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::DataTemplate FooterTemplate() const;
    void FooterTemplate(const Windows::UI::Xaml::DataTemplate & value) const;
    Windows::UI::Xaml::Media::Animation::TransitionCollection FooterTransitions() const;
    void FooterTransitions(const Windows::UI::Xaml::Media::Animation::TransitionCollection & value) const;
};

template <typename D>
struct WINRT_EBO impl_IListViewBase3
{
    Windows::UI::Xaml::Controls::ListViewReorderMode ReorderMode() const;
    void ReorderMode(Windows::UI::Xaml::Controls::ListViewReorderMode value) const;
};

template <typename D>
struct WINRT_EBO impl_IListViewBase4
{
    Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Data::ItemIndexRange> SelectedRanges() const;
    bool IsMultiSelectCheckBoxEnabled() const;
    void IsMultiSelectCheckBoxEnabled(bool value) const;
    event_token DragItemsCompleted(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::ListViewBase, Windows::UI::Xaml::Controls::DragItemsCompletedEventArgs> & value) const;
    using DragItemsCompleted_revoker = event_revoker<IListViewBase4>;
    DragItemsCompleted_revoker DragItemsCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::ListViewBase, Windows::UI::Xaml::Controls::DragItemsCompletedEventArgs> & value) const;
    void DragItemsCompleted(event_token token) const;
    event_token ChoosingItemContainer(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::ListViewBase, Windows::UI::Xaml::Controls::ChoosingItemContainerEventArgs> & value) const;
    using ChoosingItemContainer_revoker = event_revoker<IListViewBase4>;
    ChoosingItemContainer_revoker ChoosingItemContainer(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::ListViewBase, Windows::UI::Xaml::Controls::ChoosingItemContainerEventArgs> & value) const;
    void ChoosingItemContainer(event_token token) const;
    event_token ChoosingGroupHeaderContainer(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::ListViewBase, Windows::UI::Xaml::Controls::ChoosingGroupHeaderContainerEventArgs> & value) const;
    using ChoosingGroupHeaderContainer_revoker = event_revoker<IListViewBase4>;
    ChoosingGroupHeaderContainer_revoker ChoosingGroupHeaderContainer(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::ListViewBase, Windows::UI::Xaml::Controls::ChoosingGroupHeaderContainerEventArgs> & value) const;
    void ChoosingGroupHeaderContainer(event_token token) const;
    void SelectRange(const Windows::UI::Xaml::Data::ItemIndexRange & itemIndexRange) const;
    void DeselectRange(const Windows::UI::Xaml::Data::ItemIndexRange & itemIndexRange) const;
};

template <typename D>
struct WINRT_EBO impl_IListViewBase5
{
    bool SingleSelectionFollowsFocus() const;
    void SingleSelectionFollowsFocus(bool value) const;
    bool IsDragSource() const;
};

template <typename D>
struct WINRT_EBO impl_IListViewBaseFactory
{
    Windows::UI::Xaml::Controls::ListViewBase CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IListViewBaseHeaderItem
{
};

template <typename D>
struct WINRT_EBO impl_IListViewBaseHeaderItemFactory
{
};

template <typename D>
struct WINRT_EBO impl_IListViewBaseStatics
{
    Windows::UI::Xaml::DependencyProperty SelectionModeProperty() const;
    Windows::UI::Xaml::DependencyProperty IsSwipeEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty CanDragItemsProperty() const;
    Windows::UI::Xaml::DependencyProperty CanReorderItemsProperty() const;
    Windows::UI::Xaml::DependencyProperty IsItemClickEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty DataFetchSizeProperty() const;
    Windows::UI::Xaml::DependencyProperty IncrementalLoadingThresholdProperty() const;
    Windows::UI::Xaml::DependencyProperty IncrementalLoadingTriggerProperty() const;
    Windows::UI::Xaml::DependencyProperty SemanticZoomOwnerProperty() const;
    Windows::UI::Xaml::DependencyProperty IsActiveViewProperty() const;
    Windows::UI::Xaml::DependencyProperty IsZoomedInViewProperty() const;
    Windows::UI::Xaml::DependencyProperty HeaderProperty() const;
    Windows::UI::Xaml::DependencyProperty HeaderTemplateProperty() const;
    Windows::UI::Xaml::DependencyProperty HeaderTransitionsProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IListViewBaseStatics2
{
    Windows::UI::Xaml::DependencyProperty ShowsScrollingPlaceholdersProperty() const;
    Windows::UI::Xaml::DependencyProperty FooterProperty() const;
    Windows::UI::Xaml::DependencyProperty FooterTemplateProperty() const;
    Windows::UI::Xaml::DependencyProperty FooterTransitionsProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IListViewBaseStatics3
{
    Windows::UI::Xaml::DependencyProperty ReorderModeProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IListViewBaseStatics4
{
    Windows::UI::Xaml::DependencyProperty IsMultiSelectCheckBoxEnabledProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IListViewBaseStatics5
{
    Windows::UI::Xaml::DependencyProperty SingleSelectionFollowsFocusProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IListViewFactory
{
    Windows::UI::Xaml::Controls::ListView CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IListViewHeaderItem
{
};

template <typename D>
struct WINRT_EBO impl_IListViewHeaderItemFactory
{
    Windows::UI::Xaml::Controls::ListViewHeaderItem CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IListViewItem
{
    Windows::UI::Xaml::Controls::Primitives::ListViewItemTemplateSettings TemplateSettings() const;
};

template <typename D>
struct WINRT_EBO impl_IListViewItemFactory
{
    Windows::UI::Xaml::Controls::ListViewItem CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IListViewPersistenceHelper
{
};

template <typename D>
struct WINRT_EBO impl_IListViewPersistenceHelperStatics
{
    hstring GetRelativeScrollPosition(const Windows::UI::Xaml::Controls::ListViewBase & listViewBase, const Windows::UI::Xaml::Controls::ListViewItemToKeyHandler & itemToKeyHandler) const;
    Windows::Foundation::IAsyncAction SetRelativeScrollPositionAsync(const Windows::UI::Xaml::Controls::ListViewBase & listViewBase, hstring_view relativeScrollPosition, const Windows::UI::Xaml::Controls::ListViewKeyToItemHandler & keyToItemHandler) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaElement
{
    Windows::UI::Xaml::Media::ImageSource PosterSource() const;
    void PosterSource(const Windows::UI::Xaml::Media::ImageSource & value) const;
    Windows::Foundation::Uri Source() const;
    void Source(const Windows::Foundation::Uri & value) const;
    bool IsMuted() const;
    void IsMuted(bool value) const;
    bool IsAudioOnly() const;
    bool AutoPlay() const;
    void AutoPlay(bool value) const;
    double Volume() const;
    void Volume(double value) const;
    double Balance() const;
    void Balance(double value) const;
    int32_t NaturalVideoHeight() const;
    int32_t NaturalVideoWidth() const;
    Windows::UI::Xaml::Duration NaturalDuration() const;
    Windows::Foundation::TimeSpan Position() const;
    void Position(const Windows::Foundation::TimeSpan & value) const;
    double DownloadProgress() const;
    double BufferingProgress() const;
    double DownloadProgressOffset() const;
    Windows::UI::Xaml::Media::MediaElementState CurrentState() const;
    Windows::UI::Xaml::Media::TimelineMarkerCollection Markers() const;
    bool CanSeek() const;
    bool CanPause() const;
    int32_t AudioStreamCount() const;
    Windows::Foundation::IReference<int32_t> AudioStreamIndex() const;
    void AudioStreamIndex(const optional<int32_t> & value) const;
    double PlaybackRate() const;
    void PlaybackRate(double value) const;
    bool IsLooping() const;
    void IsLooping(bool value) const;
    [[deprecated("PlayToSource may be altered or unavailable for releases after Windows 10.0. Instead, use GetAsCastingSource.")]] Windows::Media::PlayTo::PlayToSource PlayToSource() const;
    double DefaultPlaybackRate() const;
    void DefaultPlaybackRate(double value) const;
    int32_t AspectRatioWidth() const;
    int32_t AspectRatioHeight() const;
    bool RealTimePlayback() const;
    void RealTimePlayback(bool value) const;
    Windows::UI::Xaml::Media::AudioCategory AudioCategory() const;
    void AudioCategory(Windows::UI::Xaml::Media::AudioCategory value) const;
    Windows::UI::Xaml::Media::AudioDeviceType AudioDeviceType() const;
    void AudioDeviceType(Windows::UI::Xaml::Media::AudioDeviceType value) const;
    Windows::Media::Protection::MediaProtectionManager ProtectionManager() const;
    void ProtectionManager(const Windows::Media::Protection::MediaProtectionManager & value) const;
    Windows::UI::Xaml::Media::Stereo3DVideoPackingMode Stereo3DVideoPackingMode() const;
    void Stereo3DVideoPackingMode(Windows::UI::Xaml::Media::Stereo3DVideoPackingMode value) const;
    Windows::UI::Xaml::Media::Stereo3DVideoRenderMode Stereo3DVideoRenderMode() const;
    void Stereo3DVideoRenderMode(Windows::UI::Xaml::Media::Stereo3DVideoRenderMode value) const;
    bool IsStereo3DVideo() const;
    event_token MediaOpened(const Windows::UI::Xaml::RoutedEventHandler & value) const;
    using MediaOpened_revoker = event_revoker<IMediaElement>;
    MediaOpened_revoker MediaOpened(auto_revoke_t, const Windows::UI::Xaml::RoutedEventHandler & value) const;
    void MediaOpened(event_token token) const;
    event_token MediaEnded(const Windows::UI::Xaml::RoutedEventHandler & value) const;
    using MediaEnded_revoker = event_revoker<IMediaElement>;
    MediaEnded_revoker MediaEnded(auto_revoke_t, const Windows::UI::Xaml::RoutedEventHandler & value) const;
    void MediaEnded(event_token token) const;
    event_token MediaFailed(const Windows::UI::Xaml::ExceptionRoutedEventHandler & value) const;
    using MediaFailed_revoker = event_revoker<IMediaElement>;
    MediaFailed_revoker MediaFailed(auto_revoke_t, const Windows::UI::Xaml::ExceptionRoutedEventHandler & value) const;
    void MediaFailed(event_token token) const;
    event_token DownloadProgressChanged(const Windows::UI::Xaml::RoutedEventHandler & value) const;
    using DownloadProgressChanged_revoker = event_revoker<IMediaElement>;
    DownloadProgressChanged_revoker DownloadProgressChanged(auto_revoke_t, const Windows::UI::Xaml::RoutedEventHandler & value) const;
    void DownloadProgressChanged(event_token token) const;
    event_token BufferingProgressChanged(const Windows::UI::Xaml::RoutedEventHandler & value) const;
    using BufferingProgressChanged_revoker = event_revoker<IMediaElement>;
    BufferingProgressChanged_revoker BufferingProgressChanged(auto_revoke_t, const Windows::UI::Xaml::RoutedEventHandler & value) const;
    void BufferingProgressChanged(event_token token) const;
    event_token CurrentStateChanged(const Windows::UI::Xaml::RoutedEventHandler & value) const;
    using CurrentStateChanged_revoker = event_revoker<IMediaElement>;
    CurrentStateChanged_revoker CurrentStateChanged(auto_revoke_t, const Windows::UI::Xaml::RoutedEventHandler & value) const;
    void CurrentStateChanged(event_token token) const;
    event_token MarkerReached(const Windows::UI::Xaml::Media::TimelineMarkerRoutedEventHandler & value) const;
    using MarkerReached_revoker = event_revoker<IMediaElement>;
    MarkerReached_revoker MarkerReached(auto_revoke_t, const Windows::UI::Xaml::Media::TimelineMarkerRoutedEventHandler & value) const;
    void MarkerReached(event_token token) const;
    event_token RateChanged(const Windows::UI::Xaml::Media::RateChangedRoutedEventHandler & value) const;
    using RateChanged_revoker = event_revoker<IMediaElement>;
    RateChanged_revoker RateChanged(auto_revoke_t, const Windows::UI::Xaml::Media::RateChangedRoutedEventHandler & value) const;
    void RateChanged(event_token token) const;
    event_token VolumeChanged(const Windows::UI::Xaml::RoutedEventHandler & value) const;
    using VolumeChanged_revoker = event_revoker<IMediaElement>;
    VolumeChanged_revoker VolumeChanged(auto_revoke_t, const Windows::UI::Xaml::RoutedEventHandler & value) const;
    void VolumeChanged(event_token token) const;
    event_token SeekCompleted(const Windows::UI::Xaml::RoutedEventHandler & value) const;
    using SeekCompleted_revoker = event_revoker<IMediaElement>;
    SeekCompleted_revoker SeekCompleted(auto_revoke_t, const Windows::UI::Xaml::RoutedEventHandler & value) const;
    void SeekCompleted(event_token token) const;
    void Stop() const;
    void Play() const;
    void Pause() const;
    Windows::UI::Xaml::Media::MediaCanPlayResponse CanPlayType(hstring_view type) const;
    void SetSource(const Windows::Storage::Streams::IRandomAccessStream & stream, hstring_view mimeType) const;
    hstring GetAudioStreamLanguage(const optional<int32_t> & index) const;
    void AddAudioEffect(hstring_view effectID, bool effectOptional, const Windows::Foundation::Collections::IPropertySet & effectConfiguration) const;
    void AddVideoEffect(hstring_view effectID, bool effectOptional, const Windows::Foundation::Collections::IPropertySet & effectConfiguration) const;
    void RemoveAllEffects() const;
    Windows::UI::Xaml::Media::Stereo3DVideoPackingMode ActualStereo3DVideoPackingMode() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaElement2
{
    bool AreTransportControlsEnabled() const;
    void AreTransportControlsEnabled(bool value) const;
    Windows::UI::Xaml::Media::Stretch Stretch() const;
    void Stretch(Windows::UI::Xaml::Media::Stretch value) const;
    bool IsFullWindow() const;
    void IsFullWindow(bool value) const;
    void SetMediaStreamSource(const Windows::Media::Core::IMediaSource & source) const;
    [[deprecated("PlayToPreferredSourceUri may be altered or unavailable for releases after Windows 10.0. Instead, use GetAsCastingSource().PreferredSourceUri.")]] Windows::Foundation::Uri PlayToPreferredSourceUri() const;
    [[deprecated("PlayToPreferredSourceUri may be altered or unavailable for releases after Windows 10.0. Instead, use GetAsCastingSource().PreferredSourceUri.")]] void PlayToPreferredSourceUri(const Windows::Foundation::Uri & value) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaElement3
{
    Windows::UI::Xaml::Controls::MediaTransportControls TransportControls() const;
    void TransportControls(const Windows::UI::Xaml::Controls::MediaTransportControls & value) const;
    event_token PartialMediaFailureDetected(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::MediaElement, Windows::UI::Xaml::Media::PartialMediaFailureDetectedEventArgs> & value) const;
    using PartialMediaFailureDetected_revoker = event_revoker<IMediaElement3>;
    PartialMediaFailureDetected_revoker PartialMediaFailureDetected(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::MediaElement, Windows::UI::Xaml::Media::PartialMediaFailureDetectedEventArgs> & value) const;
    void PartialMediaFailureDetected(event_token token) const;
    void SetPlaybackSource(const Windows::Media::Playback::IMediaPlaybackSource & source) const;
    Windows::Media::Casting::CastingSource GetAsCastingSource() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaElementStatics
{
    Windows::UI::Xaml::DependencyProperty PosterSourceProperty() const;
    Windows::UI::Xaml::DependencyProperty SourceProperty() const;
    Windows::UI::Xaml::DependencyProperty IsMutedProperty() const;
    Windows::UI::Xaml::DependencyProperty IsAudioOnlyProperty() const;
    Windows::UI::Xaml::DependencyProperty AutoPlayProperty() const;
    Windows::UI::Xaml::DependencyProperty VolumeProperty() const;
    Windows::UI::Xaml::DependencyProperty BalanceProperty() const;
    Windows::UI::Xaml::DependencyProperty NaturalVideoHeightProperty() const;
    Windows::UI::Xaml::DependencyProperty NaturalVideoWidthProperty() const;
    Windows::UI::Xaml::DependencyProperty NaturalDurationProperty() const;
    Windows::UI::Xaml::DependencyProperty PositionProperty() const;
    Windows::UI::Xaml::DependencyProperty DownloadProgressProperty() const;
    Windows::UI::Xaml::DependencyProperty BufferingProgressProperty() const;
    Windows::UI::Xaml::DependencyProperty DownloadProgressOffsetProperty() const;
    Windows::UI::Xaml::DependencyProperty CurrentStateProperty() const;
    Windows::UI::Xaml::DependencyProperty CanSeekProperty() const;
    Windows::UI::Xaml::DependencyProperty CanPauseProperty() const;
    Windows::UI::Xaml::DependencyProperty AudioStreamCountProperty() const;
    Windows::UI::Xaml::DependencyProperty AudioStreamIndexProperty() const;
    Windows::UI::Xaml::DependencyProperty PlaybackRateProperty() const;
    Windows::UI::Xaml::DependencyProperty IsLoopingProperty() const;
    [[deprecated("PlayToSource may be altered or unavailable for releases after Windows 10.0. Instead, use GetAsCastingSource.")]] Windows::UI::Xaml::DependencyProperty PlayToSourceProperty() const;
    Windows::UI::Xaml::DependencyProperty DefaultPlaybackRateProperty() const;
    Windows::UI::Xaml::DependencyProperty AspectRatioWidthProperty() const;
    Windows::UI::Xaml::DependencyProperty AspectRatioHeightProperty() const;
    Windows::UI::Xaml::DependencyProperty RealTimePlaybackProperty() const;
    Windows::UI::Xaml::DependencyProperty AudioCategoryProperty() const;
    Windows::UI::Xaml::DependencyProperty AudioDeviceTypeProperty() const;
    Windows::UI::Xaml::DependencyProperty ProtectionManagerProperty() const;
    Windows::UI::Xaml::DependencyProperty Stereo3DVideoPackingModeProperty() const;
    Windows::UI::Xaml::DependencyProperty Stereo3DVideoRenderModeProperty() const;
    Windows::UI::Xaml::DependencyProperty IsStereo3DVideoProperty() const;
    Windows::UI::Xaml::DependencyProperty ActualStereo3DVideoPackingModeProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaElementStatics2
{
    Windows::UI::Xaml::DependencyProperty AreTransportControlsEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty StretchProperty() const;
    Windows::UI::Xaml::DependencyProperty IsFullWindowProperty() const;
    [[deprecated("PlayToPreferredSourceUri may be altered or unavailable for releases after Windows 10.0. Instead, use GetAsCastingSource().PreferredSourceUri.")]] Windows::UI::Xaml::DependencyProperty PlayToPreferredSourceUriProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlayerElement
{
    Windows::Media::Playback::IMediaPlaybackSource Source() const;
    void Source(const Windows::Media::Playback::IMediaPlaybackSource & value) const;
    Windows::UI::Xaml::Controls::MediaTransportControls TransportControls() const;
    void TransportControls(const Windows::UI::Xaml::Controls::MediaTransportControls & value) const;
    bool AreTransportControlsEnabled() const;
    void AreTransportControlsEnabled(bool value) const;
    Windows::UI::Xaml::Media::ImageSource PosterSource() const;
    void PosterSource(const Windows::UI::Xaml::Media::ImageSource & value) const;
    Windows::UI::Xaml::Media::Stretch Stretch() const;
    void Stretch(Windows::UI::Xaml::Media::Stretch value) const;
    bool AutoPlay() const;
    void AutoPlay(bool value) const;
    bool IsFullWindow() const;
    void IsFullWindow(bool value) const;
    Windows::Media::Playback::MediaPlayer MediaPlayer() const;
    void SetMediaPlayer(const Windows::Media::Playback::MediaPlayer & mediaPlayer) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlayerElementFactory
{
    Windows::UI::Xaml::Controls::MediaPlayerElement CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlayerElementStatics
{
    Windows::UI::Xaml::DependencyProperty SourceProperty() const;
    Windows::UI::Xaml::DependencyProperty AreTransportControlsEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty PosterSourceProperty() const;
    Windows::UI::Xaml::DependencyProperty StretchProperty() const;
    Windows::UI::Xaml::DependencyProperty AutoPlayProperty() const;
    Windows::UI::Xaml::DependencyProperty IsFullWindowProperty() const;
    Windows::UI::Xaml::DependencyProperty MediaPlayerProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlayerPresenter
{
    Windows::Media::Playback::MediaPlayer MediaPlayer() const;
    void MediaPlayer(const Windows::Media::Playback::MediaPlayer & value) const;
    Windows::UI::Xaml::Media::Stretch Stretch() const;
    void Stretch(Windows::UI::Xaml::Media::Stretch value) const;
    bool IsFullWindow() const;
    void IsFullWindow(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlayerPresenterFactory
{
    Windows::UI::Xaml::Controls::MediaPlayerPresenter CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaPlayerPresenterStatics
{
    Windows::UI::Xaml::DependencyProperty MediaPlayerProperty() const;
    Windows::UI::Xaml::DependencyProperty StretchProperty() const;
    Windows::UI::Xaml::DependencyProperty IsFullWindowProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaTransportControls
{
    bool IsFullWindowButtonVisible() const;
    void IsFullWindowButtonVisible(bool value) const;
    bool IsFullWindowEnabled() const;
    void IsFullWindowEnabled(bool value) const;
    bool IsZoomButtonVisible() const;
    void IsZoomButtonVisible(bool value) const;
    bool IsZoomEnabled() const;
    void IsZoomEnabled(bool value) const;
    bool IsFastForwardButtonVisible() const;
    void IsFastForwardButtonVisible(bool value) const;
    bool IsFastForwardEnabled() const;
    void IsFastForwardEnabled(bool value) const;
    bool IsFastRewindButtonVisible() const;
    void IsFastRewindButtonVisible(bool value) const;
    bool IsFastRewindEnabled() const;
    void IsFastRewindEnabled(bool value) const;
    bool IsStopButtonVisible() const;
    void IsStopButtonVisible(bool value) const;
    bool IsStopEnabled() const;
    void IsStopEnabled(bool value) const;
    bool IsVolumeButtonVisible() const;
    void IsVolumeButtonVisible(bool value) const;
    bool IsVolumeEnabled() const;
    void IsVolumeEnabled(bool value) const;
    bool IsPlaybackRateButtonVisible() const;
    void IsPlaybackRateButtonVisible(bool value) const;
    bool IsPlaybackRateEnabled() const;
    void IsPlaybackRateEnabled(bool value) const;
    bool IsSeekBarVisible() const;
    void IsSeekBarVisible(bool value) const;
    bool IsSeekEnabled() const;
    void IsSeekEnabled(bool value) const;
    bool IsCompact() const;
    void IsCompact(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaTransportControls2
{
    bool IsSkipForwardButtonVisible() const;
    void IsSkipForwardButtonVisible(bool value) const;
    bool IsSkipForwardEnabled() const;
    void IsSkipForwardEnabled(bool value) const;
    bool IsSkipBackwardButtonVisible() const;
    void IsSkipBackwardButtonVisible(bool value) const;
    bool IsSkipBackwardEnabled() const;
    void IsSkipBackwardEnabled(bool value) const;
    bool IsNextTrackButtonVisible() const;
    void IsNextTrackButtonVisible(bool value) const;
    bool IsPreviousTrackButtonVisible() const;
    void IsPreviousTrackButtonVisible(bool value) const;
    Windows::UI::Xaml::Media::FastPlayFallbackBehaviour FastPlayFallbackBehaviour() const;
    void FastPlayFallbackBehaviour(Windows::UI::Xaml::Media::FastPlayFallbackBehaviour value) const;
    event_token ThumbnailRequested(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::MediaTransportControls, Windows::UI::Xaml::Media::MediaTransportControlsThumbnailRequestedEventArgs> & value) const;
    using ThumbnailRequested_revoker = event_revoker<IMediaTransportControls2>;
    ThumbnailRequested_revoker ThumbnailRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::MediaTransportControls, Windows::UI::Xaml::Media::MediaTransportControlsThumbnailRequestedEventArgs> & value) const;
    void ThumbnailRequested(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaTransportControlsFactory
{
    Windows::UI::Xaml::Controls::MediaTransportControls CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaTransportControlsHelper
{
};

template <typename D>
struct WINRT_EBO impl_IMediaTransportControlsHelperStatics
{
    Windows::UI::Xaml::DependencyProperty DropoutOrderProperty() const;
    Windows::Foundation::IReference<int32_t> GetDropoutOrder(const Windows::UI::Xaml::UIElement & element) const;
    void SetDropoutOrder(const Windows::UI::Xaml::UIElement & element, const optional<int32_t> & value) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaTransportControlsStatics
{
    Windows::UI::Xaml::DependencyProperty IsFullWindowButtonVisibleProperty() const;
    Windows::UI::Xaml::DependencyProperty IsFullWindowEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty IsZoomButtonVisibleProperty() const;
    Windows::UI::Xaml::DependencyProperty IsZoomEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty IsFastForwardButtonVisibleProperty() const;
    Windows::UI::Xaml::DependencyProperty IsFastForwardEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty IsFastRewindButtonVisibleProperty() const;
    Windows::UI::Xaml::DependencyProperty IsFastRewindEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty IsStopButtonVisibleProperty() const;
    Windows::UI::Xaml::DependencyProperty IsStopEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty IsVolumeButtonVisibleProperty() const;
    Windows::UI::Xaml::DependencyProperty IsVolumeEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty IsPlaybackRateButtonVisibleProperty() const;
    Windows::UI::Xaml::DependencyProperty IsPlaybackRateEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty IsSeekBarVisibleProperty() const;
    Windows::UI::Xaml::DependencyProperty IsSeekEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty IsCompactProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaTransportControlsStatics2
{
    Windows::UI::Xaml::DependencyProperty IsSkipForwardButtonVisibleProperty() const;
    Windows::UI::Xaml::DependencyProperty IsSkipForwardEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty IsSkipBackwardButtonVisibleProperty() const;
    Windows::UI::Xaml::DependencyProperty IsSkipBackwardEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty IsNextTrackButtonVisibleProperty() const;
    Windows::UI::Xaml::DependencyProperty IsPreviousTrackButtonVisibleProperty() const;
    Windows::UI::Xaml::DependencyProperty FastPlayFallbackBehaviourProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IMenuFlyout
{
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::MenuFlyoutItemBase> Items() const;
    Windows::UI::Xaml::Style MenuFlyoutPresenterStyle() const;
    void MenuFlyoutPresenterStyle(const Windows::UI::Xaml::Style & value) const;
};

template <typename D>
struct WINRT_EBO impl_IMenuFlyout2
{
    void ShowAt(const Windows::UI::Xaml::UIElement & targetElement, const Windows::Foundation::Point & point) const;
};

template <typename D>
struct WINRT_EBO impl_IMenuFlyoutFactory
{
    Windows::UI::Xaml::Controls::MenuFlyout CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IMenuFlyoutItem
{
    hstring Text() const;
    void Text(hstring_view value) const;
    Windows::UI::Xaml::Input::ICommand Command() const;
    void Command(const Windows::UI::Xaml::Input::ICommand & value) const;
    Windows::Foundation::IInspectable CommandParameter() const;
    void CommandParameter(const Windows::Foundation::IInspectable & value) const;
    event_token Click(const Windows::UI::Xaml::RoutedEventHandler & value) const;
    using Click_revoker = event_revoker<IMenuFlyoutItem>;
    Click_revoker Click(auto_revoke_t, const Windows::UI::Xaml::RoutedEventHandler & value) const;
    void Click(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IMenuFlyoutItemBase
{
};

template <typename D>
struct WINRT_EBO impl_IMenuFlyoutItemBaseFactory
{
};

template <typename D>
struct WINRT_EBO impl_IMenuFlyoutItemFactory
{
    Windows::UI::Xaml::Controls::MenuFlyoutItem CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IMenuFlyoutItemStatics
{
    Windows::UI::Xaml::DependencyProperty TextProperty() const;
    Windows::UI::Xaml::DependencyProperty CommandProperty() const;
    Windows::UI::Xaml::DependencyProperty CommandParameterProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IMenuFlyoutPresenter
{
};

template <typename D>
struct WINRT_EBO impl_IMenuFlyoutPresenter2
{
    Windows::UI::Xaml::Controls::Primitives::MenuFlyoutPresenterTemplateSettings TemplateSettings() const;
};

template <typename D>
struct WINRT_EBO impl_IMenuFlyoutPresenterFactory
{
    Windows::UI::Xaml::Controls::MenuFlyoutPresenter CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IMenuFlyoutSeparator
{
};

template <typename D>
struct WINRT_EBO impl_IMenuFlyoutSeparatorFactory
{
    Windows::UI::Xaml::Controls::MenuFlyoutSeparator CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IMenuFlyoutStatics
{
    Windows::UI::Xaml::DependencyProperty MenuFlyoutPresenterStyleProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IMenuFlyoutSubItem
{
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::MenuFlyoutItemBase> Items() const;
    hstring Text() const;
    void Text(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IMenuFlyoutSubItemStatics
{
    Windows::UI::Xaml::DependencyProperty TextProperty() const;
};

template <typename D>
struct WINRT_EBO impl_INavigate
{
    bool Navigate(const Windows::UI::Xaml::Interop::TypeName & sourcePageType) const;
};

template <typename D>
struct WINRT_EBO impl_INotifyEventArgs
{
    hstring Value() const;
};

template <typename D>
struct WINRT_EBO impl_INotifyEventArgs2
{
    Windows::Foundation::Uri CallingUri() const;
};

template <typename D>
struct WINRT_EBO impl_IPage
{
    Windows::UI::Xaml::Controls::Frame Frame() const;
    Windows::UI::Xaml::Navigation::NavigationCacheMode NavigationCacheMode() const;
    void NavigationCacheMode(Windows::UI::Xaml::Navigation::NavigationCacheMode value) const;
    Windows::UI::Xaml::Controls::AppBar TopAppBar() const;
    void TopAppBar(const Windows::UI::Xaml::Controls::AppBar & value) const;
    Windows::UI::Xaml::Controls::AppBar BottomAppBar() const;
    void BottomAppBar(const Windows::UI::Xaml::Controls::AppBar & value) const;
};

template <typename D>
struct WINRT_EBO impl_IPageFactory
{
    Windows::UI::Xaml::Controls::Page CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IPageOverrides
{
    void OnNavigatedFrom(const Windows::UI::Xaml::Navigation::NavigationEventArgs & e) const;
    void OnNavigatedTo(const Windows::UI::Xaml::Navigation::NavigationEventArgs & e) const;
    void OnNavigatingFrom(const Windows::UI::Xaml::Navigation::NavigatingCancelEventArgs & e) const;
};

template <typename D>
struct WINRT_EBO impl_IPageStatics
{
    Windows::UI::Xaml::DependencyProperty FrameProperty() const;
    Windows::UI::Xaml::DependencyProperty TopAppBarProperty() const;
    Windows::UI::Xaml::DependencyProperty BottomAppBarProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IPanel
{
    Windows::UI::Xaml::Controls::UIElementCollection Children() const;
    Windows::UI::Xaml::Media::Brush Background() const;
    void Background(const Windows::UI::Xaml::Media::Brush & value) const;
    bool IsItemsHost() const;
    Windows::UI::Xaml::Media::Animation::TransitionCollection ChildrenTransitions() const;
    void ChildrenTransitions(const Windows::UI::Xaml::Media::Animation::TransitionCollection & value) const;
};

template <typename D>
struct WINRT_EBO impl_IPanelFactory
{
    Windows::UI::Xaml::Controls::Panel CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IPanelStatics
{
    Windows::UI::Xaml::DependencyProperty BackgroundProperty() const;
    Windows::UI::Xaml::DependencyProperty IsItemsHostProperty() const;
    Windows::UI::Xaml::DependencyProperty ChildrenTransitionsProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IPasswordBox
{
    hstring Password() const;
    void Password(hstring_view value) const;
    hstring PasswordChar() const;
    void PasswordChar(hstring_view value) const;
    [[deprecated("IsPasswordRevealButtonEnabledProperty may be altered or unavailable for releases after Windows 10.0. Instead, use PasswordRevealModeProperty.")]] bool IsPasswordRevealButtonEnabled() const;
    [[deprecated("IsPasswordRevealButtonEnabledProperty may be altered or unavailable for releases after Windows 10.0. Instead, use PasswordRevealModeProperty.")]] void IsPasswordRevealButtonEnabled(bool value) const;
    int32_t MaxLength() const;
    void MaxLength(int32_t value) const;
    event_token PasswordChanged(const Windows::UI::Xaml::RoutedEventHandler & value) const;
    using PasswordChanged_revoker = event_revoker<IPasswordBox>;
    PasswordChanged_revoker PasswordChanged(auto_revoke_t, const Windows::UI::Xaml::RoutedEventHandler & value) const;
    void PasswordChanged(event_token token) const;
    event_token ContextMenuOpening(const Windows::UI::Xaml::Controls::ContextMenuOpeningEventHandler & value) const;
    using ContextMenuOpening_revoker = event_revoker<IPasswordBox>;
    ContextMenuOpening_revoker ContextMenuOpening(auto_revoke_t, const Windows::UI::Xaml::Controls::ContextMenuOpeningEventHandler & value) const;
    void ContextMenuOpening(event_token token) const;
    void SelectAll() const;
};

template <typename D>
struct WINRT_EBO impl_IPasswordBox2
{
    Windows::Foundation::IInspectable Header() const;
    void Header(const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::DataTemplate HeaderTemplate() const;
    void HeaderTemplate(const Windows::UI::Xaml::DataTemplate & value) const;
    hstring PlaceholderText() const;
    void PlaceholderText(hstring_view value) const;
    Windows::UI::Xaml::Media::SolidColorBrush SelectionHighlightColor() const;
    void SelectionHighlightColor(const Windows::UI::Xaml::Media::SolidColorBrush & value) const;
    bool PreventKeyboardDisplayOnProgrammaticFocus() const;
    void PreventKeyboardDisplayOnProgrammaticFocus(bool value) const;
    event_token Paste(const Windows::UI::Xaml::Controls::TextControlPasteEventHandler & value) const;
    using Paste_revoker = event_revoker<IPasswordBox2>;
    Paste_revoker Paste(auto_revoke_t, const Windows::UI::Xaml::Controls::TextControlPasteEventHandler & value) const;
    void Paste(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IPasswordBox3
{
    Windows::UI::Xaml::Controls::PasswordRevealMode PasswordRevealMode() const;
    void PasswordRevealMode(Windows::UI::Xaml::Controls::PasswordRevealMode value) const;
    Windows::UI::Xaml::TextReadingOrder TextReadingOrder() const;
    void TextReadingOrder(Windows::UI::Xaml::TextReadingOrder value) const;
    Windows::UI::Xaml::Input::InputScope InputScope() const;
    void InputScope(const Windows::UI::Xaml::Input::InputScope & value) const;
};

template <typename D>
struct WINRT_EBO impl_IPasswordBoxStatics
{
    Windows::UI::Xaml::DependencyProperty PasswordProperty() const;
    Windows::UI::Xaml::DependencyProperty PasswordCharProperty() const;
    [[deprecated("IsPasswordRevealButtonEnabledProperty may be altered or unavailable for releases after Windows 10.0. Instead, use PasswordRevealModeProperty.")]] Windows::UI::Xaml::DependencyProperty IsPasswordRevealButtonEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty MaxLengthProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IPasswordBoxStatics2
{
    Windows::UI::Xaml::DependencyProperty HeaderProperty() const;
    Windows::UI::Xaml::DependencyProperty HeaderTemplateProperty() const;
    Windows::UI::Xaml::DependencyProperty PlaceholderTextProperty() const;
    Windows::UI::Xaml::DependencyProperty SelectionHighlightColorProperty() const;
    Windows::UI::Xaml::DependencyProperty PreventKeyboardDisplayOnProgrammaticFocusProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IPasswordBoxStatics3
{
    Windows::UI::Xaml::DependencyProperty PasswordRevealModeProperty() const;
    Windows::UI::Xaml::DependencyProperty TextReadingOrderProperty() const;
    Windows::UI::Xaml::DependencyProperty InputScopeProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IPathIcon
{
    Windows::UI::Xaml::Media::Geometry Data() const;
    void Data(const Windows::UI::Xaml::Media::Geometry & value) const;
};

template <typename D>
struct WINRT_EBO impl_IPathIconFactory
{
    Windows::UI::Xaml::Controls::PathIcon CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IPathIconStatics
{
    Windows::UI::Xaml::DependencyProperty DataProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IPickerConfirmedEventArgs
{
};

template <typename D>
struct WINRT_EBO impl_IPickerFlyout
{
    Windows::UI::Xaml::UIElement Content() const;
    void Content(const Windows::UI::Xaml::UIElement & value) const;
    bool ConfirmationButtonsVisible() const;
    void ConfirmationButtonsVisible(bool value) const;
    event_token Confirmed(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::PickerFlyout, Windows::UI::Xaml::Controls::PickerConfirmedEventArgs> & value) const;
    using Confirmed_revoker = event_revoker<IPickerFlyout>;
    Confirmed_revoker Confirmed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::PickerFlyout, Windows::UI::Xaml::Controls::PickerConfirmedEventArgs> & value) const;
    void Confirmed(event_token token) const;
    Windows::Foundation::IAsyncOperation<bool> ShowAtAsync(const Windows::UI::Xaml::FrameworkElement & target) const;
};

template <typename D>
struct WINRT_EBO impl_IPickerFlyoutPresenter
{
};

template <typename D>
struct WINRT_EBO impl_IPickerFlyoutStatics
{
    Windows::UI::Xaml::DependencyProperty ContentProperty() const;
    Windows::UI::Xaml::DependencyProperty ConfirmationButtonsVisibleProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IPivot
{
    Windows::Foundation::IInspectable Title() const;
    void Title(const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::DataTemplate TitleTemplate() const;
    void TitleTemplate(const Windows::UI::Xaml::DataTemplate & value) const;
    Windows::UI::Xaml::DataTemplate HeaderTemplate() const;
    void HeaderTemplate(const Windows::UI::Xaml::DataTemplate & value) const;
    int32_t SelectedIndex() const;
    void SelectedIndex(int32_t value) const;
    Windows::Foundation::IInspectable SelectedItem() const;
    void SelectedItem(const Windows::Foundation::IInspectable & value) const;
    bool IsLocked() const;
    void IsLocked(bool value) const;
    event_token SelectionChanged(const Windows::UI::Xaml::Controls::SelectionChangedEventHandler & value) const;
    using SelectionChanged_revoker = event_revoker<IPivot>;
    SelectionChanged_revoker SelectionChanged(auto_revoke_t, const Windows::UI::Xaml::Controls::SelectionChangedEventHandler & value) const;
    void SelectionChanged(event_token token) const;
    event_token PivotItemLoading(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Pivot, Windows::UI::Xaml::Controls::PivotItemEventArgs> & value) const;
    using PivotItemLoading_revoker = event_revoker<IPivot>;
    PivotItemLoading_revoker PivotItemLoading(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Pivot, Windows::UI::Xaml::Controls::PivotItemEventArgs> & value) const;
    void PivotItemLoading(event_token token) const;
    event_token PivotItemLoaded(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Pivot, Windows::UI::Xaml::Controls::PivotItemEventArgs> & value) const;
    using PivotItemLoaded_revoker = event_revoker<IPivot>;
    PivotItemLoaded_revoker PivotItemLoaded(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Pivot, Windows::UI::Xaml::Controls::PivotItemEventArgs> & value) const;
    void PivotItemLoaded(event_token token) const;
    event_token PivotItemUnloading(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Pivot, Windows::UI::Xaml::Controls::PivotItemEventArgs> & value) const;
    using PivotItemUnloading_revoker = event_revoker<IPivot>;
    PivotItemUnloading_revoker PivotItemUnloading(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Pivot, Windows::UI::Xaml::Controls::PivotItemEventArgs> & value) const;
    void PivotItemUnloading(event_token token) const;
    event_token PivotItemUnloaded(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Pivot, Windows::UI::Xaml::Controls::PivotItemEventArgs> & value) const;
    using PivotItemUnloaded_revoker = event_revoker<IPivot>;
    PivotItemUnloaded_revoker PivotItemUnloaded(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::Pivot, Windows::UI::Xaml::Controls::PivotItemEventArgs> & value) const;
    void PivotItemUnloaded(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IPivot2
{
    Windows::Foundation::IInspectable LeftHeader() const;
    void LeftHeader(const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::DataTemplate LeftHeaderTemplate() const;
    void LeftHeaderTemplate(const Windows::UI::Xaml::DataTemplate & value) const;
    Windows::Foundation::IInspectable RightHeader() const;
    void RightHeader(const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::DataTemplate RightHeaderTemplate() const;
    void RightHeaderTemplate(const Windows::UI::Xaml::DataTemplate & value) const;
};

template <typename D>
struct WINRT_EBO impl_IPivot3
{
    Windows::UI::Xaml::Controls::PivotHeaderFocusVisualPlacement HeaderFocusVisualPlacement() const;
    void HeaderFocusVisualPlacement(Windows::UI::Xaml::Controls::PivotHeaderFocusVisualPlacement value) const;
    bool IsHeaderItemsCarouselEnabled() const;
    void IsHeaderItemsCarouselEnabled(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IPivotFactory
{
    Windows::UI::Xaml::Controls::Pivot CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IPivotItem
{
    Windows::Foundation::IInspectable Header() const;
    void Header(const Windows::Foundation::IInspectable & value) const;
};

template <typename D>
struct WINRT_EBO impl_IPivotItemEventArgs
{
    Windows::UI::Xaml::Controls::PivotItem Item() const;
    void Item(const Windows::UI::Xaml::Controls::PivotItem & value) const;
};

template <typename D>
struct WINRT_EBO impl_IPivotItemFactory
{
    Windows::UI::Xaml::Controls::PivotItem CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IPivotItemStatics
{
    Windows::UI::Xaml::DependencyProperty HeaderProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IPivotStatics
{
    Windows::UI::Xaml::DependencyProperty TitleProperty() const;
    Windows::UI::Xaml::DependencyProperty TitleTemplateProperty() const;
    Windows::UI::Xaml::DependencyProperty HeaderTemplateProperty() const;
    Windows::UI::Xaml::DependencyProperty SelectedIndexProperty() const;
    Windows::UI::Xaml::DependencyProperty SelectedItemProperty() const;
    Windows::UI::Xaml::DependencyProperty IsLockedProperty() const;
    Windows::UI::Xaml::DependencyProperty SlideInAnimationGroupProperty() const;
    Windows::UI::Xaml::Controls::PivotSlideInAnimationGroup GetSlideInAnimationGroup(const Windows::UI::Xaml::FrameworkElement & element) const;
    void SetSlideInAnimationGroup(const Windows::UI::Xaml::FrameworkElement & element, Windows::UI::Xaml::Controls::PivotSlideInAnimationGroup value) const;
};

template <typename D>
struct WINRT_EBO impl_IPivotStatics2
{
    Windows::UI::Xaml::DependencyProperty LeftHeaderProperty() const;
    Windows::UI::Xaml::DependencyProperty LeftHeaderTemplateProperty() const;
    Windows::UI::Xaml::DependencyProperty RightHeaderProperty() const;
    Windows::UI::Xaml::DependencyProperty RightHeaderTemplateProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IPivotStatics3
{
    Windows::UI::Xaml::DependencyProperty HeaderFocusVisualPlacementProperty() const;
    Windows::UI::Xaml::DependencyProperty IsHeaderItemsCarouselEnabledProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IProgressBar
{
    bool IsIndeterminate() const;
    void IsIndeterminate(bool value) const;
    bool ShowError() const;
    void ShowError(bool value) const;
    bool ShowPaused() const;
    void ShowPaused(bool value) const;
    Windows::UI::Xaml::Controls::Primitives::ProgressBarTemplateSettings TemplateSettings() const;
};

template <typename D>
struct WINRT_EBO impl_IProgressBarFactory
{
    Windows::UI::Xaml::Controls::ProgressBar CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IProgressBarStatics
{
    Windows::UI::Xaml::DependencyProperty IsIndeterminateProperty() const;
    Windows::UI::Xaml::DependencyProperty ShowErrorProperty() const;
    Windows::UI::Xaml::DependencyProperty ShowPausedProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IProgressRing
{
    bool IsActive() const;
    void IsActive(bool value) const;
    Windows::UI::Xaml::Controls::Primitives::ProgressRingTemplateSettings TemplateSettings() const;
};

template <typename D>
struct WINRT_EBO impl_IProgressRingStatics
{
    Windows::UI::Xaml::DependencyProperty IsActiveProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IRadioButton
{
    hstring GroupName() const;
    void GroupName(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IRadioButtonFactory
{
    Windows::UI::Xaml::Controls::RadioButton CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IRadioButtonStatics
{
    Windows::UI::Xaml::DependencyProperty GroupNameProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IRelativePanel
{
    Windows::UI::Xaml::Media::Brush BorderBrush() const;
    void BorderBrush(const Windows::UI::Xaml::Media::Brush & value) const;
    Windows::UI::Xaml::Thickness BorderThickness() const;
    void BorderThickness(const Windows::UI::Xaml::Thickness & value) const;
    Windows::UI::Xaml::CornerRadius CornerRadius() const;
    void CornerRadius(const Windows::UI::Xaml::CornerRadius & value) const;
    Windows::UI::Xaml::Thickness Padding() const;
    void Padding(const Windows::UI::Xaml::Thickness & value) const;
};

template <typename D>
struct WINRT_EBO impl_IRelativePanelFactory
{
    Windows::UI::Xaml::Controls::RelativePanel CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IRelativePanelStatics
{
    Windows::UI::Xaml::DependencyProperty LeftOfProperty() const;
    Windows::Foundation::IInspectable GetLeftOf(const Windows::UI::Xaml::UIElement & element) const;
    void SetLeftOf(const Windows::UI::Xaml::UIElement & element, const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::DependencyProperty AboveProperty() const;
    Windows::Foundation::IInspectable GetAbove(const Windows::UI::Xaml::UIElement & element) const;
    void SetAbove(const Windows::UI::Xaml::UIElement & element, const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::DependencyProperty RightOfProperty() const;
    Windows::Foundation::IInspectable GetRightOf(const Windows::UI::Xaml::UIElement & element) const;
    void SetRightOf(const Windows::UI::Xaml::UIElement & element, const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::DependencyProperty BelowProperty() const;
    Windows::Foundation::IInspectable GetBelow(const Windows::UI::Xaml::UIElement & element) const;
    void SetBelow(const Windows::UI::Xaml::UIElement & element, const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::DependencyProperty AlignHorizontalCenterWithProperty() const;
    Windows::Foundation::IInspectable GetAlignHorizontalCenterWith(const Windows::UI::Xaml::UIElement & element) const;
    void SetAlignHorizontalCenterWith(const Windows::UI::Xaml::UIElement & element, const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::DependencyProperty AlignVerticalCenterWithProperty() const;
    Windows::Foundation::IInspectable GetAlignVerticalCenterWith(const Windows::UI::Xaml::UIElement & element) const;
    void SetAlignVerticalCenterWith(const Windows::UI::Xaml::UIElement & element, const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::DependencyProperty AlignLeftWithProperty() const;
    Windows::Foundation::IInspectable GetAlignLeftWith(const Windows::UI::Xaml::UIElement & element) const;
    void SetAlignLeftWith(const Windows::UI::Xaml::UIElement & element, const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::DependencyProperty AlignTopWithProperty() const;
    Windows::Foundation::IInspectable GetAlignTopWith(const Windows::UI::Xaml::UIElement & element) const;
    void SetAlignTopWith(const Windows::UI::Xaml::UIElement & element, const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::DependencyProperty AlignRightWithProperty() const;
    Windows::Foundation::IInspectable GetAlignRightWith(const Windows::UI::Xaml::UIElement & element) const;
    void SetAlignRightWith(const Windows::UI::Xaml::UIElement & element, const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::DependencyProperty AlignBottomWithProperty() const;
    Windows::Foundation::IInspectable GetAlignBottomWith(const Windows::UI::Xaml::UIElement & element) const;
    void SetAlignBottomWith(const Windows::UI::Xaml::UIElement & element, const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::DependencyProperty AlignLeftWithPanelProperty() const;
    bool GetAlignLeftWithPanel(const Windows::UI::Xaml::UIElement & element) const;
    void SetAlignLeftWithPanel(const Windows::UI::Xaml::UIElement & element, bool value) const;
    Windows::UI::Xaml::DependencyProperty AlignTopWithPanelProperty() const;
    bool GetAlignTopWithPanel(const Windows::UI::Xaml::UIElement & element) const;
    void SetAlignTopWithPanel(const Windows::UI::Xaml::UIElement & element, bool value) const;
    Windows::UI::Xaml::DependencyProperty AlignRightWithPanelProperty() const;
    bool GetAlignRightWithPanel(const Windows::UI::Xaml::UIElement & element) const;
    void SetAlignRightWithPanel(const Windows::UI::Xaml::UIElement & element, bool value) const;
    Windows::UI::Xaml::DependencyProperty AlignBottomWithPanelProperty() const;
    bool GetAlignBottomWithPanel(const Windows::UI::Xaml::UIElement & element) const;
    void SetAlignBottomWithPanel(const Windows::UI::Xaml::UIElement & element, bool value) const;
    Windows::UI::Xaml::DependencyProperty AlignHorizontalCenterWithPanelProperty() const;
    bool GetAlignHorizontalCenterWithPanel(const Windows::UI::Xaml::UIElement & element) const;
    void SetAlignHorizontalCenterWithPanel(const Windows::UI::Xaml::UIElement & element, bool value) const;
    Windows::UI::Xaml::DependencyProperty AlignVerticalCenterWithPanelProperty() const;
    bool GetAlignVerticalCenterWithPanel(const Windows::UI::Xaml::UIElement & element) const;
    void SetAlignVerticalCenterWithPanel(const Windows::UI::Xaml::UIElement & element, bool value) const;
    Windows::UI::Xaml::DependencyProperty BorderBrushProperty() const;
    Windows::UI::Xaml::DependencyProperty BorderThicknessProperty() const;
    Windows::UI::Xaml::DependencyProperty CornerRadiusProperty() const;
    Windows::UI::Xaml::DependencyProperty PaddingProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IRichEditBox
{
    bool IsReadOnly() const;
    void IsReadOnly(bool value) const;
    bool AcceptsReturn() const;
    void AcceptsReturn(bool value) const;
    Windows::UI::Xaml::TextAlignment TextAlignment() const;
    void TextAlignment(Windows::UI::Xaml::TextAlignment value) const;
    Windows::UI::Xaml::TextWrapping TextWrapping() const;
    void TextWrapping(Windows::UI::Xaml::TextWrapping value) const;
    bool IsSpellCheckEnabled() const;
    void IsSpellCheckEnabled(bool value) const;
    bool IsTextPredictionEnabled() const;
    void IsTextPredictionEnabled(bool value) const;
    Windows::UI::Text::ITextDocument Document() const;
    Windows::UI::Xaml::Input::InputScope InputScope() const;
    void InputScope(const Windows::UI::Xaml::Input::InputScope & value) const;
    event_token TextChanged(const Windows::UI::Xaml::RoutedEventHandler & value) const;
    using TextChanged_revoker = event_revoker<IRichEditBox>;
    TextChanged_revoker TextChanged(auto_revoke_t, const Windows::UI::Xaml::RoutedEventHandler & value) const;
    void TextChanged(event_token token) const;
    event_token SelectionChanged(const Windows::UI::Xaml::RoutedEventHandler & value) const;
    using SelectionChanged_revoker = event_revoker<IRichEditBox>;
    SelectionChanged_revoker SelectionChanged(auto_revoke_t, const Windows::UI::Xaml::RoutedEventHandler & value) const;
    void SelectionChanged(event_token token) const;
    event_token ContextMenuOpening(const Windows::UI::Xaml::Controls::ContextMenuOpeningEventHandler & value) const;
    using ContextMenuOpening_revoker = event_revoker<IRichEditBox>;
    ContextMenuOpening_revoker ContextMenuOpening(auto_revoke_t, const Windows::UI::Xaml::Controls::ContextMenuOpeningEventHandler & value) const;
    void ContextMenuOpening(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IRichEditBox2
{
    Windows::Foundation::IInspectable Header() const;
    void Header(const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::DataTemplate HeaderTemplate() const;
    void HeaderTemplate(const Windows::UI::Xaml::DataTemplate & value) const;
    hstring PlaceholderText() const;
    void PlaceholderText(hstring_view value) const;
    Windows::UI::Xaml::Media::SolidColorBrush SelectionHighlightColor() const;
    void SelectionHighlightColor(const Windows::UI::Xaml::Media::SolidColorBrush & value) const;
    bool PreventKeyboardDisplayOnProgrammaticFocus() const;
    void PreventKeyboardDisplayOnProgrammaticFocus(bool value) const;
    bool IsColorFontEnabled() const;
    void IsColorFontEnabled(bool value) const;
    event_token Paste(const Windows::UI::Xaml::Controls::TextControlPasteEventHandler & value) const;
    using Paste_revoker = event_revoker<IRichEditBox2>;
    Paste_revoker Paste(auto_revoke_t, const Windows::UI::Xaml::Controls::TextControlPasteEventHandler & value) const;
    void Paste(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IRichEditBox3
{
    event_token TextCompositionStarted(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::RichEditBox, Windows::UI::Xaml::Controls::TextCompositionStartedEventArgs> & value) const;
    using TextCompositionStarted_revoker = event_revoker<IRichEditBox3>;
    TextCompositionStarted_revoker TextCompositionStarted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::RichEditBox, Windows::UI::Xaml::Controls::TextCompositionStartedEventArgs> & value) const;
    void TextCompositionStarted(event_token token) const;
    event_token TextCompositionChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::RichEditBox, Windows::UI::Xaml::Controls::TextCompositionChangedEventArgs> & value) const;
    using TextCompositionChanged_revoker = event_revoker<IRichEditBox3>;
    TextCompositionChanged_revoker TextCompositionChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::RichEditBox, Windows::UI::Xaml::Controls::TextCompositionChangedEventArgs> & value) const;
    void TextCompositionChanged(event_token token) const;
    event_token TextCompositionEnded(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::RichEditBox, Windows::UI::Xaml::Controls::TextCompositionEndedEventArgs> & value) const;
    using TextCompositionEnded_revoker = event_revoker<IRichEditBox3>;
    TextCompositionEnded_revoker TextCompositionEnded(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::RichEditBox, Windows::UI::Xaml::Controls::TextCompositionEndedEventArgs> & value) const;
    void TextCompositionEnded(event_token token) const;
    Windows::UI::Xaml::TextReadingOrder TextReadingOrder() const;
    void TextReadingOrder(Windows::UI::Xaml::TextReadingOrder value) const;
    Windows::UI::Xaml::Controls::CandidateWindowAlignment DesiredCandidateWindowAlignment() const;
    void DesiredCandidateWindowAlignment(Windows::UI::Xaml::Controls::CandidateWindowAlignment value) const;
    event_token CandidateWindowBoundsChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::RichEditBox, Windows::UI::Xaml::Controls::CandidateWindowBoundsChangedEventArgs> & value) const;
    using CandidateWindowBoundsChanged_revoker = event_revoker<IRichEditBox3>;
    CandidateWindowBoundsChanged_revoker CandidateWindowBoundsChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::RichEditBox, Windows::UI::Xaml::Controls::CandidateWindowBoundsChangedEventArgs> & value) const;
    void CandidateWindowBoundsChanged(event_token token) const;
    event_token TextChanging(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::RichEditBox, Windows::UI::Xaml::Controls::RichEditBoxTextChangingEventArgs> & value) const;
    using TextChanging_revoker = event_revoker<IRichEditBox3>;
    TextChanging_revoker TextChanging(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::RichEditBox, Windows::UI::Xaml::Controls::RichEditBoxTextChangingEventArgs> & value) const;
    void TextChanging(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IRichEditBox4
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<hstring>> GetLinguisticAlternativesAsync() const;
    Windows::UI::Xaml::Controls::RichEditClipboardFormat ClipboardCopyFormat() const;
    void ClipboardCopyFormat(Windows::UI::Xaml::Controls::RichEditClipboardFormat value) const;
};

template <typename D>
struct WINRT_EBO impl_IRichEditBoxFactory
{
    Windows::UI::Xaml::Controls::RichEditBox CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IRichEditBoxStatics
{
    Windows::UI::Xaml::DependencyProperty IsReadOnlyProperty() const;
    Windows::UI::Xaml::DependencyProperty AcceptsReturnProperty() const;
    Windows::UI::Xaml::DependencyProperty TextAlignmentProperty() const;
    Windows::UI::Xaml::DependencyProperty TextWrappingProperty() const;
    Windows::UI::Xaml::DependencyProperty IsSpellCheckEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty IsTextPredictionEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty InputScopeProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IRichEditBoxStatics2
{
    Windows::UI::Xaml::DependencyProperty HeaderProperty() const;
    Windows::UI::Xaml::DependencyProperty HeaderTemplateProperty() const;
    Windows::UI::Xaml::DependencyProperty PlaceholderTextProperty() const;
    Windows::UI::Xaml::DependencyProperty SelectionHighlightColorProperty() const;
    Windows::UI::Xaml::DependencyProperty PreventKeyboardDisplayOnProgrammaticFocusProperty() const;
    Windows::UI::Xaml::DependencyProperty IsColorFontEnabledProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IRichEditBoxStatics3
{
    Windows::UI::Xaml::DependencyProperty DesiredCandidateWindowAlignmentProperty() const;
    Windows::UI::Xaml::DependencyProperty TextReadingOrderProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IRichEditBoxStatics4
{
    Windows::UI::Xaml::DependencyProperty ClipboardCopyFormatProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IRichEditBoxTextChangingEventArgs
{
};

template <typename D>
struct WINRT_EBO impl_IRichTextBlock
{
    double FontSize() const;
    void FontSize(double value) const;
    Windows::UI::Xaml::Media::FontFamily FontFamily() const;
    void FontFamily(const Windows::UI::Xaml::Media::FontFamily & value) const;
    Windows::UI::Text::FontWeight FontWeight() const;
    void FontWeight(const Windows::UI::Text::FontWeight & value) const;
    Windows::UI::Text::FontStyle FontStyle() const;
    void FontStyle(Windows::UI::Text::FontStyle value) const;
    Windows::UI::Text::FontStretch FontStretch() const;
    void FontStretch(Windows::UI::Text::FontStretch value) const;
    Windows::UI::Xaml::Media::Brush Foreground() const;
    void Foreground(const Windows::UI::Xaml::Media::Brush & value) const;
    Windows::UI::Xaml::TextWrapping TextWrapping() const;
    void TextWrapping(Windows::UI::Xaml::TextWrapping value) const;
    Windows::UI::Xaml::TextTrimming TextTrimming() const;
    void TextTrimming(Windows::UI::Xaml::TextTrimming value) const;
    Windows::UI::Xaml::TextAlignment TextAlignment() const;
    void TextAlignment(Windows::UI::Xaml::TextAlignment value) const;
    Windows::UI::Xaml::Documents::BlockCollection Blocks() const;
    Windows::UI::Xaml::Thickness Padding() const;
    void Padding(const Windows::UI::Xaml::Thickness & value) const;
    double LineHeight() const;
    void LineHeight(double value) const;
    Windows::UI::Xaml::LineStackingStrategy LineStackingStrategy() const;
    void LineStackingStrategy(Windows::UI::Xaml::LineStackingStrategy value) const;
    int32_t CharacterSpacing() const;
    void CharacterSpacing(int32_t value) const;
    Windows::UI::Xaml::Controls::RichTextBlockOverflow OverflowContentTarget() const;
    void OverflowContentTarget(const Windows::UI::Xaml::Controls::RichTextBlockOverflow & value) const;
    bool IsTextSelectionEnabled() const;
    void IsTextSelectionEnabled(bool value) const;
    bool HasOverflowContent() const;
    hstring SelectedText() const;
    Windows::UI::Xaml::Documents::TextPointer ContentStart() const;
    Windows::UI::Xaml::Documents::TextPointer ContentEnd() const;
    Windows::UI::Xaml::Documents::TextPointer SelectionStart() const;
    Windows::UI::Xaml::Documents::TextPointer SelectionEnd() const;
    double BaselineOffset() const;
    event_token SelectionChanged(const Windows::UI::Xaml::RoutedEventHandler & value) const;
    using SelectionChanged_revoker = event_revoker<IRichTextBlock>;
    SelectionChanged_revoker SelectionChanged(auto_revoke_t, const Windows::UI::Xaml::RoutedEventHandler & value) const;
    void SelectionChanged(event_token token) const;
    event_token ContextMenuOpening(const Windows::UI::Xaml::Controls::ContextMenuOpeningEventHandler & value) const;
    using ContextMenuOpening_revoker = event_revoker<IRichTextBlock>;
    ContextMenuOpening_revoker ContextMenuOpening(auto_revoke_t, const Windows::UI::Xaml::Controls::ContextMenuOpeningEventHandler & value) const;
    void ContextMenuOpening(event_token token) const;
    void SelectAll() const;
    void Select(const Windows::UI::Xaml::Documents::TextPointer & start, const Windows::UI::Xaml::Documents::TextPointer & end) const;
    Windows::UI::Xaml::Documents::TextPointer GetPositionFromPoint(const Windows::Foundation::Point & point) const;
    bool Focus(Windows::UI::Xaml::FocusState value) const;
    double TextIndent() const;
    void TextIndent(double value) const;
};

template <typename D>
struct WINRT_EBO impl_IRichTextBlock2
{
    int32_t MaxLines() const;
    void MaxLines(int32_t value) const;
    Windows::UI::Xaml::TextLineBounds TextLineBounds() const;
    void TextLineBounds(Windows::UI::Xaml::TextLineBounds value) const;
    Windows::UI::Xaml::Media::SolidColorBrush SelectionHighlightColor() const;
    void SelectionHighlightColor(const Windows::UI::Xaml::Media::SolidColorBrush & value) const;
    Windows::UI::Xaml::OpticalMarginAlignment OpticalMarginAlignment() const;
    void OpticalMarginAlignment(Windows::UI::Xaml::OpticalMarginAlignment value) const;
    bool IsColorFontEnabled() const;
    void IsColorFontEnabled(bool value) const;
    Windows::UI::Xaml::TextReadingOrder TextReadingOrder() const;
    void TextReadingOrder(Windows::UI::Xaml::TextReadingOrder value) const;
};

template <typename D>
struct WINRT_EBO impl_IRichTextBlock3
{
    bool IsTextScaleFactorEnabled() const;
    void IsTextScaleFactorEnabled(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IRichTextBlockOverflow
{
    Windows::UI::Xaml::Controls::RichTextBlockOverflow OverflowContentTarget() const;
    void OverflowContentTarget(const Windows::UI::Xaml::Controls::RichTextBlockOverflow & value) const;
    Windows::UI::Xaml::Thickness Padding() const;
    void Padding(const Windows::UI::Xaml::Thickness & value) const;
    Windows::UI::Xaml::Controls::RichTextBlock ContentSource() const;
    bool HasOverflowContent() const;
    Windows::UI::Xaml::Documents::TextPointer ContentStart() const;
    Windows::UI::Xaml::Documents::TextPointer ContentEnd() const;
    double BaselineOffset() const;
    Windows::UI::Xaml::Documents::TextPointer GetPositionFromPoint(const Windows::Foundation::Point & point) const;
    bool Focus(Windows::UI::Xaml::FocusState value) const;
};

template <typename D>
struct WINRT_EBO impl_IRichTextBlockOverflow2
{
    int32_t MaxLines() const;
    void MaxLines(int32_t value) const;
};

template <typename D>
struct WINRT_EBO impl_IRichTextBlockOverflowStatics
{
    Windows::UI::Xaml::DependencyProperty OverflowContentTargetProperty() const;
    Windows::UI::Xaml::DependencyProperty PaddingProperty() const;
    Windows::UI::Xaml::DependencyProperty HasOverflowContentProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IRichTextBlockOverflowStatics2
{
    Windows::UI::Xaml::DependencyProperty MaxLinesProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IRichTextBlockStatics
{
    Windows::UI::Xaml::DependencyProperty FontSizeProperty() const;
    Windows::UI::Xaml::DependencyProperty FontFamilyProperty() const;
    Windows::UI::Xaml::DependencyProperty FontWeightProperty() const;
    Windows::UI::Xaml::DependencyProperty FontStyleProperty() const;
    Windows::UI::Xaml::DependencyProperty FontStretchProperty() const;
    Windows::UI::Xaml::DependencyProperty ForegroundProperty() const;
    Windows::UI::Xaml::DependencyProperty TextWrappingProperty() const;
    Windows::UI::Xaml::DependencyProperty TextTrimmingProperty() const;
    Windows::UI::Xaml::DependencyProperty TextAlignmentProperty() const;
    Windows::UI::Xaml::DependencyProperty PaddingProperty() const;
    Windows::UI::Xaml::DependencyProperty LineHeightProperty() const;
    Windows::UI::Xaml::DependencyProperty LineStackingStrategyProperty() const;
    Windows::UI::Xaml::DependencyProperty CharacterSpacingProperty() const;
    Windows::UI::Xaml::DependencyProperty OverflowContentTargetProperty() const;
    Windows::UI::Xaml::DependencyProperty IsTextSelectionEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty HasOverflowContentProperty() const;
    Windows::UI::Xaml::DependencyProperty SelectedTextProperty() const;
    Windows::UI::Xaml::DependencyProperty TextIndentProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IRichTextBlockStatics2
{
    Windows::UI::Xaml::DependencyProperty MaxLinesProperty() const;
    Windows::UI::Xaml::DependencyProperty TextLineBoundsProperty() const;
    Windows::UI::Xaml::DependencyProperty SelectionHighlightColorProperty() const;
    Windows::UI::Xaml::DependencyProperty OpticalMarginAlignmentProperty() const;
    Windows::UI::Xaml::DependencyProperty IsColorFontEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty TextReadingOrderProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IRichTextBlockStatics3
{
    Windows::UI::Xaml::DependencyProperty IsTextScaleFactorEnabledProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IRowDefinition
{
    Windows::UI::Xaml::GridLength Height() const;
    void Height(const Windows::UI::Xaml::GridLength & value) const;
    double MaxHeight() const;
    void MaxHeight(double value) const;
    double MinHeight() const;
    void MinHeight(double value) const;
    double ActualHeight() const;
};

template <typename D>
struct WINRT_EBO impl_IRowDefinitionStatics
{
    Windows::UI::Xaml::DependencyProperty HeightProperty() const;
    Windows::UI::Xaml::DependencyProperty MaxHeightProperty() const;
    Windows::UI::Xaml::DependencyProperty MinHeightProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IScrollContentPresenter
{
    bool CanVerticallyScroll() const;
    void CanVerticallyScroll(bool value) const;
    bool CanHorizontallyScroll() const;
    void CanHorizontallyScroll(bool value) const;
    double ExtentWidth() const;
    double ExtentHeight() const;
    double ViewportWidth() const;
    double ViewportHeight() const;
    double HorizontalOffset() const;
    double VerticalOffset() const;
    Windows::Foundation::IInspectable ScrollOwner() const;
    void ScrollOwner(const Windows::Foundation::IInspectable & value) const;
    void LineUp() const;
    void LineDown() const;
    void LineLeft() const;
    void LineRight() const;
    void PageUp() const;
    void PageDown() const;
    void PageLeft() const;
    void PageRight() const;
    void MouseWheelUp() const;
    void MouseWheelDown() const;
    void MouseWheelLeft() const;
    void MouseWheelRight() const;
    void SetHorizontalOffset(double offset) const;
    void SetVerticalOffset(double offset) const;
    Windows::Foundation::Rect MakeVisible(const Windows::UI::Xaml::UIElement & visual, const Windows::Foundation::Rect & rectangle) const;
};

template <typename D>
struct WINRT_EBO impl_IScrollViewer
{
    Windows::UI::Xaml::Controls::ScrollBarVisibility HorizontalScrollBarVisibility() const;
    void HorizontalScrollBarVisibility(Windows::UI::Xaml::Controls::ScrollBarVisibility value) const;
    Windows::UI::Xaml::Controls::ScrollBarVisibility VerticalScrollBarVisibility() const;
    void VerticalScrollBarVisibility(Windows::UI::Xaml::Controls::ScrollBarVisibility value) const;
    bool IsHorizontalRailEnabled() const;
    void IsHorizontalRailEnabled(bool value) const;
    bool IsVerticalRailEnabled() const;
    void IsVerticalRailEnabled(bool value) const;
    bool IsHorizontalScrollChainingEnabled() const;
    void IsHorizontalScrollChainingEnabled(bool value) const;
    bool IsVerticalScrollChainingEnabled() const;
    void IsVerticalScrollChainingEnabled(bool value) const;
    bool IsZoomChainingEnabled() const;
    void IsZoomChainingEnabled(bool value) const;
    bool IsScrollInertiaEnabled() const;
    void IsScrollInertiaEnabled(bool value) const;
    bool IsZoomInertiaEnabled() const;
    void IsZoomInertiaEnabled(bool value) const;
    Windows::UI::Xaml::Controls::ScrollMode HorizontalScrollMode() const;
    void HorizontalScrollMode(Windows::UI::Xaml::Controls::ScrollMode value) const;
    Windows::UI::Xaml::Controls::ScrollMode VerticalScrollMode() const;
    void VerticalScrollMode(Windows::UI::Xaml::Controls::ScrollMode value) const;
    Windows::UI::Xaml::Controls::ZoomMode ZoomMode() const;
    void ZoomMode(Windows::UI::Xaml::Controls::ZoomMode value) const;
    Windows::UI::Xaml::Controls::Primitives::SnapPointsAlignment HorizontalSnapPointsAlignment() const;
    void HorizontalSnapPointsAlignment(Windows::UI::Xaml::Controls::Primitives::SnapPointsAlignment value) const;
    Windows::UI::Xaml::Controls::Primitives::SnapPointsAlignment VerticalSnapPointsAlignment() const;
    void VerticalSnapPointsAlignment(Windows::UI::Xaml::Controls::Primitives::SnapPointsAlignment value) const;
    Windows::UI::Xaml::Controls::SnapPointsType HorizontalSnapPointsType() const;
    void HorizontalSnapPointsType(Windows::UI::Xaml::Controls::SnapPointsType value) const;
    Windows::UI::Xaml::Controls::SnapPointsType VerticalSnapPointsType() const;
    void VerticalSnapPointsType(Windows::UI::Xaml::Controls::SnapPointsType value) const;
    Windows::UI::Xaml::Controls::SnapPointsType ZoomSnapPointsType() const;
    void ZoomSnapPointsType(Windows::UI::Xaml::Controls::SnapPointsType value) const;
    double HorizontalOffset() const;
    double ViewportWidth() const;
    double ScrollableWidth() const;
    Windows::UI::Xaml::Visibility ComputedHorizontalScrollBarVisibility() const;
    double ExtentWidth() const;
    double VerticalOffset() const;
    double ViewportHeight() const;
    double ScrollableHeight() const;
    Windows::UI::Xaml::Visibility ComputedVerticalScrollBarVisibility() const;
    double ExtentHeight() const;
    float MinZoomFactor() const;
    void MinZoomFactor(float value) const;
    float MaxZoomFactor() const;
    void MaxZoomFactor(float value) const;
    float ZoomFactor() const;
    Windows::Foundation::Collections::IVector<float> ZoomSnapPoints() const;
    event_token ViewChanged(const Windows::Foundation::EventHandler<Windows::UI::Xaml::Controls::ScrollViewerViewChangedEventArgs> & value) const;
    using ViewChanged_revoker = event_revoker<IScrollViewer>;
    ViewChanged_revoker ViewChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::UI::Xaml::Controls::ScrollViewerViewChangedEventArgs> & value) const;
    void ViewChanged(event_token token) const;
    [[deprecated("ScrollToHorizontalOffset may be altered or unavailable for releases after Windows 8.1. Instead, use ChangeView.")]] void ScrollToHorizontalOffset(double offset) const;
    [[deprecated("ScrollToVerticalOffset may be altered or unavailable for releases after Windows 8.1. Instead, use ChangeView.")]] void ScrollToVerticalOffset(double offset) const;
    [[deprecated("ZoomToFactor may be altered or unavailable for releases after Windows 8.1. Instead, use ChangeView.")]] void ZoomToFactor(float factor) const;
    void InvalidateScrollInfo() const;
    bool IsDeferredScrollingEnabled() const;
    void IsDeferredScrollingEnabled(bool value) const;
    bool BringIntoViewOnFocusChange() const;
    void BringIntoViewOnFocusChange(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IScrollViewer2
{
    Windows::UI::Xaml::UIElement TopLeftHeader() const;
    void TopLeftHeader(const Windows::UI::Xaml::UIElement & value) const;
    Windows::UI::Xaml::UIElement LeftHeader() const;
    void LeftHeader(const Windows::UI::Xaml::UIElement & value) const;
    Windows::UI::Xaml::UIElement TopHeader() const;
    void TopHeader(const Windows::UI::Xaml::UIElement & value) const;
    event_token ViewChanging(const Windows::Foundation::EventHandler<Windows::UI::Xaml::Controls::ScrollViewerViewChangingEventArgs> & value) const;
    using ViewChanging_revoker = event_revoker<IScrollViewer2>;
    ViewChanging_revoker ViewChanging(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::UI::Xaml::Controls::ScrollViewerViewChangingEventArgs> & value) const;
    void ViewChanging(event_token token) const;
    bool ChangeView(const optional<double> & horizontalOffset, const optional<double> & verticalOffset, const optional<float> & zoomFactor) const;
    bool ChangeView(const optional<double> & horizontalOffset, const optional<double> & verticalOffset, const optional<float> & zoomFactor, bool disableAnimation) const;
};

template <typename D>
struct WINRT_EBO impl_IScrollViewer3
{
    event_token DirectManipulationStarted(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const;
    using DirectManipulationStarted_revoker = event_revoker<IScrollViewer3>;
    DirectManipulationStarted_revoker DirectManipulationStarted(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const;
    void DirectManipulationStarted(event_token token) const;
    event_token DirectManipulationCompleted(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const;
    using DirectManipulationCompleted_revoker = event_revoker<IScrollViewer3>;
    DirectManipulationCompleted_revoker DirectManipulationCompleted(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const;
    void DirectManipulationCompleted(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IScrollViewerStatics
{
    Windows::UI::Xaml::DependencyProperty HorizontalSnapPointsAlignmentProperty() const;
    Windows::UI::Xaml::DependencyProperty VerticalSnapPointsAlignmentProperty() const;
    Windows::UI::Xaml::DependencyProperty HorizontalSnapPointsTypeProperty() const;
    Windows::UI::Xaml::DependencyProperty VerticalSnapPointsTypeProperty() const;
    Windows::UI::Xaml::DependencyProperty ZoomSnapPointsTypeProperty() const;
    Windows::UI::Xaml::DependencyProperty HorizontalOffsetProperty() const;
    Windows::UI::Xaml::DependencyProperty ViewportWidthProperty() const;
    Windows::UI::Xaml::DependencyProperty ScrollableWidthProperty() const;
    Windows::UI::Xaml::DependencyProperty ComputedHorizontalScrollBarVisibilityProperty() const;
    Windows::UI::Xaml::DependencyProperty ExtentWidthProperty() const;
    Windows::UI::Xaml::DependencyProperty VerticalOffsetProperty() const;
    Windows::UI::Xaml::DependencyProperty ViewportHeightProperty() const;
    Windows::UI::Xaml::DependencyProperty ScrollableHeightProperty() const;
    Windows::UI::Xaml::DependencyProperty ComputedVerticalScrollBarVisibilityProperty() const;
    Windows::UI::Xaml::DependencyProperty ExtentHeightProperty() const;
    Windows::UI::Xaml::DependencyProperty MinZoomFactorProperty() const;
    Windows::UI::Xaml::DependencyProperty MaxZoomFactorProperty() const;
    Windows::UI::Xaml::DependencyProperty ZoomFactorProperty() const;
    Windows::UI::Xaml::DependencyProperty ZoomSnapPointsProperty() const;
    Windows::UI::Xaml::DependencyProperty HorizontalScrollBarVisibilityProperty() const;
    Windows::UI::Xaml::Controls::ScrollBarVisibility GetHorizontalScrollBarVisibility(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetHorizontalScrollBarVisibility(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::Controls::ScrollBarVisibility horizontalScrollBarVisibility) const;
    Windows::UI::Xaml::DependencyProperty VerticalScrollBarVisibilityProperty() const;
    Windows::UI::Xaml::Controls::ScrollBarVisibility GetVerticalScrollBarVisibility(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetVerticalScrollBarVisibility(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::Controls::ScrollBarVisibility verticalScrollBarVisibility) const;
    Windows::UI::Xaml::DependencyProperty IsHorizontalRailEnabledProperty() const;
    bool GetIsHorizontalRailEnabled(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetIsHorizontalRailEnabled(const Windows::UI::Xaml::DependencyObject & element, bool isHorizontalRailEnabled) const;
    Windows::UI::Xaml::DependencyProperty IsVerticalRailEnabledProperty() const;
    bool GetIsVerticalRailEnabled(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetIsVerticalRailEnabled(const Windows::UI::Xaml::DependencyObject & element, bool isVerticalRailEnabled) const;
    Windows::UI::Xaml::DependencyProperty IsHorizontalScrollChainingEnabledProperty() const;
    bool GetIsHorizontalScrollChainingEnabled(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetIsHorizontalScrollChainingEnabled(const Windows::UI::Xaml::DependencyObject & element, bool isHorizontalScrollChainingEnabled) const;
    Windows::UI::Xaml::DependencyProperty IsVerticalScrollChainingEnabledProperty() const;
    bool GetIsVerticalScrollChainingEnabled(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetIsVerticalScrollChainingEnabled(const Windows::UI::Xaml::DependencyObject & element, bool isVerticalScrollChainingEnabled) const;
    Windows::UI::Xaml::DependencyProperty IsZoomChainingEnabledProperty() const;
    bool GetIsZoomChainingEnabled(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetIsZoomChainingEnabled(const Windows::UI::Xaml::DependencyObject & element, bool isZoomChainingEnabled) const;
    Windows::UI::Xaml::DependencyProperty IsScrollInertiaEnabledProperty() const;
    bool GetIsScrollInertiaEnabled(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetIsScrollInertiaEnabled(const Windows::UI::Xaml::DependencyObject & element, bool isScrollInertiaEnabled) const;
    Windows::UI::Xaml::DependencyProperty IsZoomInertiaEnabledProperty() const;
    bool GetIsZoomInertiaEnabled(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetIsZoomInertiaEnabled(const Windows::UI::Xaml::DependencyObject & element, bool isZoomInertiaEnabled) const;
    Windows::UI::Xaml::DependencyProperty HorizontalScrollModeProperty() const;
    Windows::UI::Xaml::Controls::ScrollMode GetHorizontalScrollMode(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetHorizontalScrollMode(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::Controls::ScrollMode horizontalScrollMode) const;
    Windows::UI::Xaml::DependencyProperty VerticalScrollModeProperty() const;
    Windows::UI::Xaml::Controls::ScrollMode GetVerticalScrollMode(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetVerticalScrollMode(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::Controls::ScrollMode verticalScrollMode) const;
    Windows::UI::Xaml::DependencyProperty ZoomModeProperty() const;
    Windows::UI::Xaml::Controls::ZoomMode GetZoomMode(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetZoomMode(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::Controls::ZoomMode zoomMode) const;
    Windows::UI::Xaml::DependencyProperty IsDeferredScrollingEnabledProperty() const;
    bool GetIsDeferredScrollingEnabled(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetIsDeferredScrollingEnabled(const Windows::UI::Xaml::DependencyObject & element, bool isDeferredScrollingEnabled) const;
    Windows::UI::Xaml::DependencyProperty BringIntoViewOnFocusChangeProperty() const;
    bool GetBringIntoViewOnFocusChange(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetBringIntoViewOnFocusChange(const Windows::UI::Xaml::DependencyObject & element, bool bringIntoViewOnFocusChange) const;
};

template <typename D>
struct WINRT_EBO impl_IScrollViewerStatics2
{
    Windows::UI::Xaml::DependencyProperty TopLeftHeaderProperty() const;
    Windows::UI::Xaml::DependencyProperty LeftHeaderProperty() const;
    Windows::UI::Xaml::DependencyProperty TopHeaderProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IScrollViewerView
{
    double HorizontalOffset() const;
    double VerticalOffset() const;
    float ZoomFactor() const;
};

template <typename D>
struct WINRT_EBO impl_IScrollViewerViewChangedEventArgs
{
    bool IsIntermediate() const;
};

template <typename D>
struct WINRT_EBO impl_IScrollViewerViewChangingEventArgs
{
    Windows::UI::Xaml::Controls::ScrollViewerView NextView() const;
    Windows::UI::Xaml::Controls::ScrollViewerView FinalView() const;
    bool IsInertial() const;
};

template <typename D>
struct WINRT_EBO impl_ISearchBox
{
    bool SearchHistoryEnabled() const;
    void SearchHistoryEnabled(bool value) const;
    hstring SearchHistoryContext() const;
    void SearchHistoryContext(hstring_view value) const;
    hstring PlaceholderText() const;
    void PlaceholderText(hstring_view value) const;
    hstring QueryText() const;
    void QueryText(hstring_view value) const;
    bool FocusOnKeyboardInput() const;
    void FocusOnKeyboardInput(bool value) const;
    bool ChooseSuggestionOnEnter() const;
    void ChooseSuggestionOnEnter(bool value) const;
    event_token QueryChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::SearchBox, Windows::UI::Xaml::Controls::SearchBoxQueryChangedEventArgs> & value) const;
    using QueryChanged_revoker = event_revoker<ISearchBox>;
    QueryChanged_revoker QueryChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::SearchBox, Windows::UI::Xaml::Controls::SearchBoxQueryChangedEventArgs> & value) const;
    void QueryChanged(event_token token) const;
    event_token SuggestionsRequested(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::SearchBox, Windows::UI::Xaml::Controls::SearchBoxSuggestionsRequestedEventArgs> & value) const;
    using SuggestionsRequested_revoker = event_revoker<ISearchBox>;
    SuggestionsRequested_revoker SuggestionsRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::SearchBox, Windows::UI::Xaml::Controls::SearchBoxSuggestionsRequestedEventArgs> & value) const;
    void SuggestionsRequested(event_token token) const;
    event_token QuerySubmitted(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::SearchBox, Windows::UI::Xaml::Controls::SearchBoxQuerySubmittedEventArgs> & value) const;
    using QuerySubmitted_revoker = event_revoker<ISearchBox>;
    QuerySubmitted_revoker QuerySubmitted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::SearchBox, Windows::UI::Xaml::Controls::SearchBoxQuerySubmittedEventArgs> & value) const;
    void QuerySubmitted(event_token token) const;
    event_token ResultSuggestionChosen(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::SearchBox, Windows::UI::Xaml::Controls::SearchBoxResultSuggestionChosenEventArgs> & value) const;
    using ResultSuggestionChosen_revoker = event_revoker<ISearchBox>;
    ResultSuggestionChosen_revoker ResultSuggestionChosen(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::SearchBox, Windows::UI::Xaml::Controls::SearchBoxResultSuggestionChosenEventArgs> & value) const;
    void ResultSuggestionChosen(event_token token) const;
    event_token PrepareForFocusOnKeyboardInput(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::SearchBox, Windows::UI::Xaml::RoutedEventArgs> & value) const;
    using PrepareForFocusOnKeyboardInput_revoker = event_revoker<ISearchBox>;
    PrepareForFocusOnKeyboardInput_revoker PrepareForFocusOnKeyboardInput(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::SearchBox, Windows::UI::Xaml::RoutedEventArgs> & value) const;
    void PrepareForFocusOnKeyboardInput(event_token token) const;
    void SetLocalContentSuggestionSettings(const Windows::ApplicationModel::Search::LocalContentSuggestionSettings & settings) const;
};

template <typename D>
struct WINRT_EBO impl_ISearchBoxFactory
{
    Windows::UI::Xaml::Controls::SearchBox CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_ISearchBoxQueryChangedEventArgs
{
    hstring QueryText() const;
    hstring Language() const;
    Windows::ApplicationModel::Search::SearchQueryLinguisticDetails LinguisticDetails() const;
};

template <typename D>
struct WINRT_EBO impl_ISearchBoxQuerySubmittedEventArgs
{
    hstring QueryText() const;
    hstring Language() const;
    Windows::ApplicationModel::Search::SearchQueryLinguisticDetails LinguisticDetails() const;
    Windows::System::VirtualKeyModifiers KeyModifiers() const;
};

template <typename D>
struct WINRT_EBO impl_ISearchBoxResultSuggestionChosenEventArgs
{
    hstring Tag() const;
    Windows::System::VirtualKeyModifiers KeyModifiers() const;
};

template <typename D>
struct WINRT_EBO impl_ISearchBoxStatics
{
    Windows::UI::Xaml::DependencyProperty SearchHistoryEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty SearchHistoryContextProperty() const;
    Windows::UI::Xaml::DependencyProperty PlaceholderTextProperty() const;
    Windows::UI::Xaml::DependencyProperty QueryTextProperty() const;
    Windows::UI::Xaml::DependencyProperty FocusOnKeyboardInputProperty() const;
    Windows::UI::Xaml::DependencyProperty ChooseSuggestionOnEnterProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ISearchBoxSuggestionsRequestedEventArgs
{
    hstring QueryText() const;
    hstring Language() const;
    Windows::ApplicationModel::Search::SearchQueryLinguisticDetails LinguisticDetails() const;
    Windows::ApplicationModel::Search::SearchSuggestionsRequest Request() const;
};

template <typename D>
struct WINRT_EBO impl_ISectionsInViewChangedEventArgs
{
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::HubSection> AddedSections() const;
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::HubSection> RemovedSections() const;
};

template <typename D>
struct WINRT_EBO impl_ISectionsInViewChangedEventArgsFactory
{
};

template <typename D>
struct WINRT_EBO impl_ISelectionChangedEventArgs
{
    Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> AddedItems() const;
    Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> RemovedItems() const;
};

template <typename D>
struct WINRT_EBO impl_ISelectionChangedEventArgsFactory
{
    Windows::UI::Xaml::Controls::SelectionChangedEventArgs CreateInstanceWithRemovedItemsAndAddedItems(const Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> & removedItems, const Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> & addedItems, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_ISemanticZoom
{
    Windows::UI::Xaml::Controls::ISemanticZoomInformation ZoomedInView() const;
    void ZoomedInView(const Windows::UI::Xaml::Controls::ISemanticZoomInformation & value) const;
    Windows::UI::Xaml::Controls::ISemanticZoomInformation ZoomedOutView() const;
    void ZoomedOutView(const Windows::UI::Xaml::Controls::ISemanticZoomInformation & value) const;
    bool IsZoomedInViewActive() const;
    void IsZoomedInViewActive(bool value) const;
    bool CanChangeViews() const;
    void CanChangeViews(bool value) const;
    event_token ViewChangeStarted(const Windows::UI::Xaml::Controls::SemanticZoomViewChangedEventHandler & value) const;
    using ViewChangeStarted_revoker = event_revoker<ISemanticZoom>;
    ViewChangeStarted_revoker ViewChangeStarted(auto_revoke_t, const Windows::UI::Xaml::Controls::SemanticZoomViewChangedEventHandler & value) const;
    void ViewChangeStarted(event_token token) const;
    event_token ViewChangeCompleted(const Windows::UI::Xaml::Controls::SemanticZoomViewChangedEventHandler & value) const;
    using ViewChangeCompleted_revoker = event_revoker<ISemanticZoom>;
    ViewChangeCompleted_revoker ViewChangeCompleted(auto_revoke_t, const Windows::UI::Xaml::Controls::SemanticZoomViewChangedEventHandler & value) const;
    void ViewChangeCompleted(event_token token) const;
    void ToggleActiveView() const;
    bool IsZoomOutButtonEnabled() const;
    void IsZoomOutButtonEnabled(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_ISemanticZoomInformation
{
    Windows::UI::Xaml::Controls::SemanticZoom SemanticZoomOwner() const;
    void SemanticZoomOwner(const Windows::UI::Xaml::Controls::SemanticZoom & value) const;
    bool IsActiveView() const;
    void IsActiveView(bool value) const;
    bool IsZoomedInView() const;
    void IsZoomedInView(bool value) const;
    void InitializeViewChange() const;
    void CompleteViewChange() const;
    void MakeVisible(const Windows::UI::Xaml::Controls::SemanticZoomLocation & item) const;
    void StartViewChangeFrom(const Windows::UI::Xaml::Controls::SemanticZoomLocation & source, const Windows::UI::Xaml::Controls::SemanticZoomLocation & destination) const;
    void StartViewChangeTo(const Windows::UI::Xaml::Controls::SemanticZoomLocation & source, const Windows::UI::Xaml::Controls::SemanticZoomLocation & destination) const;
    void CompleteViewChangeFrom(const Windows::UI::Xaml::Controls::SemanticZoomLocation & source, const Windows::UI::Xaml::Controls::SemanticZoomLocation & destination) const;
    void CompleteViewChangeTo(const Windows::UI::Xaml::Controls::SemanticZoomLocation & source, const Windows::UI::Xaml::Controls::SemanticZoomLocation & destination) const;
};

template <typename D>
struct WINRT_EBO impl_ISemanticZoomLocation
{
    Windows::Foundation::IInspectable Item() const;
    void Item(const Windows::Foundation::IInspectable & value) const;
    Windows::Foundation::Rect Bounds() const;
    void Bounds(const Windows::Foundation::Rect & value) const;
};

template <typename D>
struct WINRT_EBO impl_ISemanticZoomStatics
{
    Windows::UI::Xaml::DependencyProperty ZoomedInViewProperty() const;
    Windows::UI::Xaml::DependencyProperty ZoomedOutViewProperty() const;
    Windows::UI::Xaml::DependencyProperty IsZoomedInViewActiveProperty() const;
    Windows::UI::Xaml::DependencyProperty CanChangeViewsProperty() const;
    Windows::UI::Xaml::DependencyProperty IsZoomOutButtonEnabledProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ISemanticZoomViewChangedEventArgs
{
    bool IsSourceZoomedInView() const;
    void IsSourceZoomedInView(bool value) const;
    Windows::UI::Xaml::Controls::SemanticZoomLocation SourceItem() const;
    void SourceItem(const Windows::UI::Xaml::Controls::SemanticZoomLocation & value) const;
    Windows::UI::Xaml::Controls::SemanticZoomLocation DestinationItem() const;
    void DestinationItem(const Windows::UI::Xaml::Controls::SemanticZoomLocation & value) const;
};

template <typename D>
struct WINRT_EBO impl_ISettingsFlyout
{
    hstring Title() const;
    void Title(hstring_view value) const;
    Windows::UI::Xaml::Media::Brush HeaderBackground() const;
    void HeaderBackground(const Windows::UI::Xaml::Media::Brush & value) const;
    Windows::UI::Xaml::Media::Brush HeaderForeground() const;
    void HeaderForeground(const Windows::UI::Xaml::Media::Brush & value) const;
    Windows::UI::Xaml::Media::ImageSource IconSource() const;
    void IconSource(const Windows::UI::Xaml::Media::ImageSource & value) const;
    Windows::UI::Xaml::Controls::Primitives::SettingsFlyoutTemplateSettings TemplateSettings() const;
    event_token BackClick(const Windows::UI::Xaml::Controls::BackClickEventHandler & value) const;
    using BackClick_revoker = event_revoker<ISettingsFlyout>;
    BackClick_revoker BackClick(auto_revoke_t, const Windows::UI::Xaml::Controls::BackClickEventHandler & value) const;
    void BackClick(event_token token) const;
    void Show() const;
    void ShowIndependent() const;
    void Hide() const;
};

template <typename D>
struct WINRT_EBO impl_ISettingsFlyoutFactory
{
    Windows::UI::Xaml::Controls::SettingsFlyout CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_ISettingsFlyoutStatics
{
    Windows::UI::Xaml::DependencyProperty TitleProperty() const;
    Windows::UI::Xaml::DependencyProperty HeaderBackgroundProperty() const;
    Windows::UI::Xaml::DependencyProperty HeaderForegroundProperty() const;
    Windows::UI::Xaml::DependencyProperty IconSourceProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ISlider
{
    double IntermediateValue() const;
    void IntermediateValue(double value) const;
    double StepFrequency() const;
    void StepFrequency(double value) const;
    Windows::UI::Xaml::Controls::Primitives::SliderSnapsTo SnapsTo() const;
    void SnapsTo(Windows::UI::Xaml::Controls::Primitives::SliderSnapsTo value) const;
    double TickFrequency() const;
    void TickFrequency(double value) const;
    Windows::UI::Xaml::Controls::Primitives::TickPlacement TickPlacement() const;
    void TickPlacement(Windows::UI::Xaml::Controls::Primitives::TickPlacement value) const;
    Windows::UI::Xaml::Controls::Orientation Orientation() const;
    void Orientation(Windows::UI::Xaml::Controls::Orientation value) const;
    bool IsDirectionReversed() const;
    void IsDirectionReversed(bool value) const;
    bool IsThumbToolTipEnabled() const;
    void IsThumbToolTipEnabled(bool value) const;
    Windows::UI::Xaml::Data::IValueConverter ThumbToolTipValueConverter() const;
    void ThumbToolTipValueConverter(const Windows::UI::Xaml::Data::IValueConverter & value) const;
};

template <typename D>
struct WINRT_EBO impl_ISlider2
{
    Windows::Foundation::IInspectable Header() const;
    void Header(const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::DataTemplate HeaderTemplate() const;
    void HeaderTemplate(const Windows::UI::Xaml::DataTemplate & value) const;
};

template <typename D>
struct WINRT_EBO impl_ISliderFactory
{
    Windows::UI::Xaml::Controls::Slider CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_ISliderStatics
{
    Windows::UI::Xaml::DependencyProperty IntermediateValueProperty() const;
    Windows::UI::Xaml::DependencyProperty StepFrequencyProperty() const;
    Windows::UI::Xaml::DependencyProperty SnapsToProperty() const;
    Windows::UI::Xaml::DependencyProperty TickFrequencyProperty() const;
    Windows::UI::Xaml::DependencyProperty TickPlacementProperty() const;
    Windows::UI::Xaml::DependencyProperty OrientationProperty() const;
    Windows::UI::Xaml::DependencyProperty IsDirectionReversedProperty() const;
    Windows::UI::Xaml::DependencyProperty IsThumbToolTipEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty ThumbToolTipValueConverterProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ISliderStatics2
{
    Windows::UI::Xaml::DependencyProperty HeaderProperty() const;
    Windows::UI::Xaml::DependencyProperty HeaderTemplateProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ISplitView
{
    Windows::UI::Xaml::UIElement Content() const;
    void Content(const Windows::UI::Xaml::UIElement & value) const;
    Windows::UI::Xaml::UIElement Pane() const;
    void Pane(const Windows::UI::Xaml::UIElement & value) const;
    bool IsPaneOpen() const;
    void IsPaneOpen(bool value) const;
    double OpenPaneLength() const;
    void OpenPaneLength(double value) const;
    double CompactPaneLength() const;
    void CompactPaneLength(double value) const;
    Windows::UI::Xaml::Controls::SplitViewPanePlacement PanePlacement() const;
    void PanePlacement(Windows::UI::Xaml::Controls::SplitViewPanePlacement value) const;
    Windows::UI::Xaml::Controls::SplitViewDisplayMode DisplayMode() const;
    void DisplayMode(Windows::UI::Xaml::Controls::SplitViewDisplayMode value) const;
    Windows::UI::Xaml::Controls::Primitives::SplitViewTemplateSettings TemplateSettings() const;
    Windows::UI::Xaml::Media::Brush PaneBackground() const;
    void PaneBackground(const Windows::UI::Xaml::Media::Brush & value) const;
    event_token PaneClosing(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::SplitView, Windows::UI::Xaml::Controls::SplitViewPaneClosingEventArgs> & value) const;
    using PaneClosing_revoker = event_revoker<ISplitView>;
    PaneClosing_revoker PaneClosing(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::SplitView, Windows::UI::Xaml::Controls::SplitViewPaneClosingEventArgs> & value) const;
    void PaneClosing(event_token token) const;
    event_token PaneClosed(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::SplitView, Windows::Foundation::IInspectable> & value) const;
    using PaneClosed_revoker = event_revoker<ISplitView>;
    PaneClosed_revoker PaneClosed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::SplitView, Windows::Foundation::IInspectable> & value) const;
    void PaneClosed(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_ISplitView2
{
    Windows::UI::Xaml::Controls::LightDismissOverlayMode LightDismissOverlayMode() const;
    void LightDismissOverlayMode(Windows::UI::Xaml::Controls::LightDismissOverlayMode value) const;
};

template <typename D>
struct WINRT_EBO impl_ISplitViewFactory
{
    Windows::UI::Xaml::Controls::SplitView CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_ISplitViewPaneClosingEventArgs
{
    bool Cancel() const;
    void Cancel(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_ISplitViewStatics
{
    Windows::UI::Xaml::DependencyProperty ContentProperty() const;
    Windows::UI::Xaml::DependencyProperty PaneProperty() const;
    Windows::UI::Xaml::DependencyProperty IsPaneOpenProperty() const;
    Windows::UI::Xaml::DependencyProperty OpenPaneLengthProperty() const;
    Windows::UI::Xaml::DependencyProperty CompactPaneLengthProperty() const;
    Windows::UI::Xaml::DependencyProperty PanePlacementProperty() const;
    Windows::UI::Xaml::DependencyProperty DisplayModeProperty() const;
    Windows::UI::Xaml::DependencyProperty TemplateSettingsProperty() const;
    Windows::UI::Xaml::DependencyProperty PaneBackgroundProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ISplitViewStatics2
{
    Windows::UI::Xaml::DependencyProperty LightDismissOverlayModeProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IStackPanel
{
    bool AreScrollSnapPointsRegular() const;
    void AreScrollSnapPointsRegular(bool value) const;
    Windows::UI::Xaml::Controls::Orientation Orientation() const;
    void Orientation(Windows::UI::Xaml::Controls::Orientation value) const;
};

template <typename D>
struct WINRT_EBO impl_IStackPanel2
{
    Windows::UI::Xaml::Media::Brush BorderBrush() const;
    void BorderBrush(const Windows::UI::Xaml::Media::Brush & value) const;
    Windows::UI::Xaml::Thickness BorderThickness() const;
    void BorderThickness(const Windows::UI::Xaml::Thickness & value) const;
    Windows::UI::Xaml::CornerRadius CornerRadius() const;
    void CornerRadius(const Windows::UI::Xaml::CornerRadius & value) const;
    Windows::UI::Xaml::Thickness Padding() const;
    void Padding(const Windows::UI::Xaml::Thickness & value) const;
};

template <typename D>
struct WINRT_EBO impl_IStackPanelFactory
{
    Windows::UI::Xaml::Controls::StackPanel CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IStackPanelStatics
{
    Windows::UI::Xaml::DependencyProperty AreScrollSnapPointsRegularProperty() const;
    Windows::UI::Xaml::DependencyProperty OrientationProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IStackPanelStatics2
{
    Windows::UI::Xaml::DependencyProperty BorderBrushProperty() const;
    Windows::UI::Xaml::DependencyProperty BorderThicknessProperty() const;
    Windows::UI::Xaml::DependencyProperty CornerRadiusProperty() const;
    Windows::UI::Xaml::DependencyProperty PaddingProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IStyleSelector
{
    Windows::UI::Xaml::Style SelectStyle(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::DependencyObject & container) const;
};

template <typename D>
struct WINRT_EBO impl_IStyleSelectorFactory
{
    Windows::UI::Xaml::Controls::StyleSelector CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IStyleSelectorOverrides
{
    Windows::UI::Xaml::Style SelectStyleCore(const Windows::Foundation::IInspectable & item, const Windows::UI::Xaml::DependencyObject & container) const;
};

template <typename D>
struct WINRT_EBO impl_ISwapChainBackgroundPanel
{
};

template <typename D>
struct WINRT_EBO impl_ISwapChainBackgroundPanel2
{
    Windows::UI::Core::CoreIndependentInputSource CreateCoreIndependentInputSource(Windows::UI::Core::CoreInputDeviceTypes deviceTypes) const;
};

template <typename D>
struct WINRT_EBO impl_ISwapChainBackgroundPanelFactory
{
    Windows::UI::Xaml::Controls::SwapChainBackgroundPanel CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_ISwapChainPanel
{
    float CompositionScaleX() const;
    float CompositionScaleY() const;
    event_token CompositionScaleChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::SwapChainPanel, Windows::Foundation::IInspectable> & value) const;
    using CompositionScaleChanged_revoker = event_revoker<ISwapChainPanel>;
    CompositionScaleChanged_revoker CompositionScaleChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::SwapChainPanel, Windows::Foundation::IInspectable> & value) const;
    void CompositionScaleChanged(event_token token) const;
    Windows::UI::Core::CoreIndependentInputSource CreateCoreIndependentInputSource(Windows::UI::Core::CoreInputDeviceTypes deviceTypes) const;
};

template <typename D>
struct WINRT_EBO impl_ISwapChainPanelFactory
{
    Windows::UI::Xaml::Controls::SwapChainPanel CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_ISwapChainPanelStatics
{
    Windows::UI::Xaml::DependencyProperty CompositionScaleXProperty() const;
    Windows::UI::Xaml::DependencyProperty CompositionScaleYProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ISymbolIcon
{
    Windows::UI::Xaml::Controls::Symbol Symbol() const;
    void Symbol(Windows::UI::Xaml::Controls::Symbol value) const;
};

template <typename D>
struct WINRT_EBO impl_ISymbolIconFactory
{
    Windows::UI::Xaml::Controls::SymbolIcon CreateInstanceWithSymbol(Windows::UI::Xaml::Controls::Symbol symbol) const;
};

template <typename D>
struct WINRT_EBO impl_ISymbolIconStatics
{
    Windows::UI::Xaml::DependencyProperty SymbolProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ITextBlock
{
    double FontSize() const;
    void FontSize(double value) const;
    Windows::UI::Xaml::Media::FontFamily FontFamily() const;
    void FontFamily(const Windows::UI::Xaml::Media::FontFamily & value) const;
    Windows::UI::Text::FontWeight FontWeight() const;
    void FontWeight(const Windows::UI::Text::FontWeight & value) const;
    Windows::UI::Text::FontStyle FontStyle() const;
    void FontStyle(Windows::UI::Text::FontStyle value) const;
    Windows::UI::Text::FontStretch FontStretch() const;
    void FontStretch(Windows::UI::Text::FontStretch value) const;
    int32_t CharacterSpacing() const;
    void CharacterSpacing(int32_t value) const;
    Windows::UI::Xaml::Media::Brush Foreground() const;
    void Foreground(const Windows::UI::Xaml::Media::Brush & value) const;
    Windows::UI::Xaml::TextWrapping TextWrapping() const;
    void TextWrapping(Windows::UI::Xaml::TextWrapping value) const;
    Windows::UI::Xaml::TextTrimming TextTrimming() const;
    void TextTrimming(Windows::UI::Xaml::TextTrimming value) const;
    Windows::UI::Xaml::TextAlignment TextAlignment() const;
    void TextAlignment(Windows::UI::Xaml::TextAlignment value) const;
    hstring Text() const;
    void Text(hstring_view value) const;
    Windows::UI::Xaml::Documents::InlineCollection Inlines() const;
    Windows::UI::Xaml::Thickness Padding() const;
    void Padding(const Windows::UI::Xaml::Thickness & value) const;
    double LineHeight() const;
    void LineHeight(double value) const;
    Windows::UI::Xaml::LineStackingStrategy LineStackingStrategy() const;
    void LineStackingStrategy(Windows::UI::Xaml::LineStackingStrategy value) const;
    bool IsTextSelectionEnabled() const;
    void IsTextSelectionEnabled(bool value) const;
    hstring SelectedText() const;
    Windows::UI::Xaml::Documents::TextPointer ContentStart() const;
    Windows::UI::Xaml::Documents::TextPointer ContentEnd() const;
    Windows::UI::Xaml::Documents::TextPointer SelectionStart() const;
    Windows::UI::Xaml::Documents::TextPointer SelectionEnd() const;
    double BaselineOffset() const;
    event_token SelectionChanged(const Windows::UI::Xaml::RoutedEventHandler & value) const;
    using SelectionChanged_revoker = event_revoker<ITextBlock>;
    SelectionChanged_revoker SelectionChanged(auto_revoke_t, const Windows::UI::Xaml::RoutedEventHandler & value) const;
    void SelectionChanged(event_token token) const;
    event_token ContextMenuOpening(const Windows::UI::Xaml::Controls::ContextMenuOpeningEventHandler & value) const;
    using ContextMenuOpening_revoker = event_revoker<ITextBlock>;
    ContextMenuOpening_revoker ContextMenuOpening(auto_revoke_t, const Windows::UI::Xaml::Controls::ContextMenuOpeningEventHandler & value) const;
    void ContextMenuOpening(event_token token) const;
    void SelectAll() const;
    void Select(const Windows::UI::Xaml::Documents::TextPointer & start, const Windows::UI::Xaml::Documents::TextPointer & end) const;
    bool Focus(Windows::UI::Xaml::FocusState value) const;
};

template <typename D>
struct WINRT_EBO impl_ITextBlock2
{
    Windows::UI::Xaml::Media::SolidColorBrush SelectionHighlightColor() const;
    void SelectionHighlightColor(const Windows::UI::Xaml::Media::SolidColorBrush & value) const;
    int32_t MaxLines() const;
    void MaxLines(int32_t value) const;
    Windows::UI::Xaml::TextLineBounds TextLineBounds() const;
    void TextLineBounds(Windows::UI::Xaml::TextLineBounds value) const;
    Windows::UI::Xaml::OpticalMarginAlignment OpticalMarginAlignment() const;
    void OpticalMarginAlignment(Windows::UI::Xaml::OpticalMarginAlignment value) const;
    bool IsColorFontEnabled() const;
    void IsColorFontEnabled(bool value) const;
    Windows::UI::Xaml::TextReadingOrder TextReadingOrder() const;
    void TextReadingOrder(Windows::UI::Xaml::TextReadingOrder value) const;
};

template <typename D>
struct WINRT_EBO impl_ITextBlock3
{
    bool IsTextScaleFactorEnabled() const;
    void IsTextScaleFactorEnabled(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_ITextBlock4
{
    Windows::UI::Composition::CompositionBrush GetAlphaMask() const;
};

template <typename D>
struct WINRT_EBO impl_ITextBlockStatics
{
    Windows::UI::Xaml::DependencyProperty FontSizeProperty() const;
    Windows::UI::Xaml::DependencyProperty FontFamilyProperty() const;
    Windows::UI::Xaml::DependencyProperty FontWeightProperty() const;
    Windows::UI::Xaml::DependencyProperty FontStyleProperty() const;
    Windows::UI::Xaml::DependencyProperty FontStretchProperty() const;
    Windows::UI::Xaml::DependencyProperty CharacterSpacingProperty() const;
    Windows::UI::Xaml::DependencyProperty ForegroundProperty() const;
    Windows::UI::Xaml::DependencyProperty TextWrappingProperty() const;
    Windows::UI::Xaml::DependencyProperty TextTrimmingProperty() const;
    Windows::UI::Xaml::DependencyProperty TextAlignmentProperty() const;
    Windows::UI::Xaml::DependencyProperty TextProperty() const;
    Windows::UI::Xaml::DependencyProperty PaddingProperty() const;
    Windows::UI::Xaml::DependencyProperty LineHeightProperty() const;
    Windows::UI::Xaml::DependencyProperty LineStackingStrategyProperty() const;
    Windows::UI::Xaml::DependencyProperty IsTextSelectionEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty SelectedTextProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ITextBlockStatics2
{
    Windows::UI::Xaml::DependencyProperty SelectionHighlightColorProperty() const;
    Windows::UI::Xaml::DependencyProperty MaxLinesProperty() const;
    Windows::UI::Xaml::DependencyProperty TextLineBoundsProperty() const;
    Windows::UI::Xaml::DependencyProperty OpticalMarginAlignmentProperty() const;
    Windows::UI::Xaml::DependencyProperty IsColorFontEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty TextReadingOrderProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ITextBlockStatics3
{
    Windows::UI::Xaml::DependencyProperty IsTextScaleFactorEnabledProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ITextBox
{
    hstring Text() const;
    void Text(hstring_view value) const;
    hstring SelectedText() const;
    void SelectedText(hstring_view value) const;
    int32_t SelectionLength() const;
    void SelectionLength(int32_t value) const;
    int32_t SelectionStart() const;
    void SelectionStart(int32_t value) const;
    int32_t MaxLength() const;
    void MaxLength(int32_t value) const;
    bool IsReadOnly() const;
    void IsReadOnly(bool value) const;
    bool AcceptsReturn() const;
    void AcceptsReturn(bool value) const;
    Windows::UI::Xaml::TextAlignment TextAlignment() const;
    void TextAlignment(Windows::UI::Xaml::TextAlignment value) const;
    Windows::UI::Xaml::TextWrapping TextWrapping() const;
    void TextWrapping(Windows::UI::Xaml::TextWrapping value) const;
    bool IsSpellCheckEnabled() const;
    void IsSpellCheckEnabled(bool value) const;
    bool IsTextPredictionEnabled() const;
    void IsTextPredictionEnabled(bool value) const;
    Windows::UI::Xaml::Input::InputScope InputScope() const;
    void InputScope(const Windows::UI::Xaml::Input::InputScope & value) const;
    event_token TextChanged(const Windows::UI::Xaml::Controls::TextChangedEventHandler & value) const;
    using TextChanged_revoker = event_revoker<ITextBox>;
    TextChanged_revoker TextChanged(auto_revoke_t, const Windows::UI::Xaml::Controls::TextChangedEventHandler & value) const;
    void TextChanged(event_token token) const;
    event_token SelectionChanged(const Windows::UI::Xaml::RoutedEventHandler & value) const;
    using SelectionChanged_revoker = event_revoker<ITextBox>;
    SelectionChanged_revoker SelectionChanged(auto_revoke_t, const Windows::UI::Xaml::RoutedEventHandler & value) const;
    void SelectionChanged(event_token token) const;
    event_token ContextMenuOpening(const Windows::UI::Xaml::Controls::ContextMenuOpeningEventHandler & value) const;
    using ContextMenuOpening_revoker = event_revoker<ITextBox>;
    ContextMenuOpening_revoker ContextMenuOpening(auto_revoke_t, const Windows::UI::Xaml::Controls::ContextMenuOpeningEventHandler & value) const;
    void ContextMenuOpening(event_token token) const;
    void Select(int32_t start, int32_t length) const;
    void SelectAll() const;
    Windows::Foundation::Rect GetRectFromCharacterIndex(int32_t charIndex, bool trailingEdge) const;
};

template <typename D>
struct WINRT_EBO impl_ITextBox2
{
    Windows::Foundation::IInspectable Header() const;
    void Header(const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::DataTemplate HeaderTemplate() const;
    void HeaderTemplate(const Windows::UI::Xaml::DataTemplate & value) const;
    hstring PlaceholderText() const;
    void PlaceholderText(hstring_view value) const;
    Windows::UI::Xaml::Media::SolidColorBrush SelectionHighlightColor() const;
    void SelectionHighlightColor(const Windows::UI::Xaml::Media::SolidColorBrush & value) const;
    bool PreventKeyboardDisplayOnProgrammaticFocus() const;
    void PreventKeyboardDisplayOnProgrammaticFocus(bool value) const;
    bool IsColorFontEnabled() const;
    void IsColorFontEnabled(bool value) const;
    event_token Paste(const Windows::UI::Xaml::Controls::TextControlPasteEventHandler & value) const;
    using Paste_revoker = event_revoker<ITextBox2>;
    Paste_revoker Paste(auto_revoke_t, const Windows::UI::Xaml::Controls::TextControlPasteEventHandler & value) const;
    void Paste(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_ITextBox3
{
    event_token TextCompositionStarted(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::TextBox, Windows::UI::Xaml::Controls::TextCompositionStartedEventArgs> & value) const;
    using TextCompositionStarted_revoker = event_revoker<ITextBox3>;
    TextCompositionStarted_revoker TextCompositionStarted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::TextBox, Windows::UI::Xaml::Controls::TextCompositionStartedEventArgs> & value) const;
    void TextCompositionStarted(event_token token) const;
    event_token TextCompositionChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::TextBox, Windows::UI::Xaml::Controls::TextCompositionChangedEventArgs> & value) const;
    using TextCompositionChanged_revoker = event_revoker<ITextBox3>;
    TextCompositionChanged_revoker TextCompositionChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::TextBox, Windows::UI::Xaml::Controls::TextCompositionChangedEventArgs> & value) const;
    void TextCompositionChanged(event_token token) const;
    event_token TextCompositionEnded(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::TextBox, Windows::UI::Xaml::Controls::TextCompositionEndedEventArgs> & value) const;
    using TextCompositionEnded_revoker = event_revoker<ITextBox3>;
    TextCompositionEnded_revoker TextCompositionEnded(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::TextBox, Windows::UI::Xaml::Controls::TextCompositionEndedEventArgs> & value) const;
    void TextCompositionEnded(event_token token) const;
    Windows::UI::Xaml::TextReadingOrder TextReadingOrder() const;
    void TextReadingOrder(Windows::UI::Xaml::TextReadingOrder value) const;
    Windows::UI::Xaml::Controls::CandidateWindowAlignment DesiredCandidateWindowAlignment() const;
    void DesiredCandidateWindowAlignment(Windows::UI::Xaml::Controls::CandidateWindowAlignment value) const;
    event_token CandidateWindowBoundsChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::TextBox, Windows::UI::Xaml::Controls::CandidateWindowBoundsChangedEventArgs> & value) const;
    using CandidateWindowBoundsChanged_revoker = event_revoker<ITextBox3>;
    CandidateWindowBoundsChanged_revoker CandidateWindowBoundsChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::TextBox, Windows::UI::Xaml::Controls::CandidateWindowBoundsChangedEventArgs> & value) const;
    void CandidateWindowBoundsChanged(event_token token) const;
    event_token TextChanging(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::TextBox, Windows::UI::Xaml::Controls::TextBoxTextChangingEventArgs> & value) const;
    using TextChanging_revoker = event_revoker<ITextBox3>;
    TextChanging_revoker TextChanging(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::TextBox, Windows::UI::Xaml::Controls::TextBoxTextChangingEventArgs> & value) const;
    void TextChanging(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_ITextBox4
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<hstring>> GetLinguisticAlternativesAsync() const;
};

template <typename D>
struct WINRT_EBO impl_ITextBoxFactory
{
    Windows::UI::Xaml::Controls::TextBox CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_ITextBoxStatics
{
    Windows::UI::Xaml::DependencyProperty TextProperty() const;
    Windows::UI::Xaml::DependencyProperty MaxLengthProperty() const;
    Windows::UI::Xaml::DependencyProperty IsReadOnlyProperty() const;
    Windows::UI::Xaml::DependencyProperty AcceptsReturnProperty() const;
    Windows::UI::Xaml::DependencyProperty TextAlignmentProperty() const;
    Windows::UI::Xaml::DependencyProperty TextWrappingProperty() const;
    Windows::UI::Xaml::DependencyProperty IsSpellCheckEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty IsTextPredictionEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty InputScopeProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ITextBoxStatics2
{
    Windows::UI::Xaml::DependencyProperty HeaderProperty() const;
    Windows::UI::Xaml::DependencyProperty HeaderTemplateProperty() const;
    Windows::UI::Xaml::DependencyProperty PlaceholderTextProperty() const;
    Windows::UI::Xaml::DependencyProperty SelectionHighlightColorProperty() const;
    Windows::UI::Xaml::DependencyProperty PreventKeyboardDisplayOnProgrammaticFocusProperty() const;
    Windows::UI::Xaml::DependencyProperty IsColorFontEnabledProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ITextBoxStatics3
{
    Windows::UI::Xaml::DependencyProperty DesiredCandidateWindowAlignmentProperty() const;
    Windows::UI::Xaml::DependencyProperty TextReadingOrderProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ITextBoxTextChangingEventArgs
{
};

template <typename D>
struct WINRT_EBO impl_ITextChangedEventArgs
{
};

template <typename D>
struct WINRT_EBO impl_ITextCompositionChangedEventArgs
{
    int32_t StartIndex() const;
    int32_t Length() const;
};

template <typename D>
struct WINRT_EBO impl_ITextCompositionEndedEventArgs
{
    int32_t StartIndex() const;
    int32_t Length() const;
};

template <typename D>
struct WINRT_EBO impl_ITextCompositionStartedEventArgs
{
    int32_t StartIndex() const;
    int32_t Length() const;
};

template <typename D>
struct WINRT_EBO impl_ITextControlPasteEventArgs
{
    bool Handled() const;
    void Handled(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_ITimePickedEventArgs
{
    Windows::Foundation::TimeSpan OldTime() const;
    Windows::Foundation::TimeSpan NewTime() const;
};

template <typename D>
struct WINRT_EBO impl_ITimePicker
{
    Windows::Foundation::IInspectable Header() const;
    void Header(const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::DataTemplate HeaderTemplate() const;
    void HeaderTemplate(const Windows::UI::Xaml::DataTemplate & value) const;
    hstring ClockIdentifier() const;
    void ClockIdentifier(hstring_view value) const;
    int32_t MinuteIncrement() const;
    void MinuteIncrement(int32_t value) const;
    Windows::Foundation::TimeSpan Time() const;
    void Time(const Windows::Foundation::TimeSpan & value) const;
    event_token TimeChanged(const Windows::Foundation::EventHandler<Windows::UI::Xaml::Controls::TimePickerValueChangedEventArgs> & value) const;
    using TimeChanged_revoker = event_revoker<ITimePicker>;
    TimeChanged_revoker TimeChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::UI::Xaml::Controls::TimePickerValueChangedEventArgs> & value) const;
    void TimeChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_ITimePicker2
{
    Windows::UI::Xaml::Controls::LightDismissOverlayMode LightDismissOverlayMode() const;
    void LightDismissOverlayMode(Windows::UI::Xaml::Controls::LightDismissOverlayMode value) const;
};

template <typename D>
struct WINRT_EBO impl_ITimePickerFactory
{
    Windows::UI::Xaml::Controls::TimePicker CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_ITimePickerFlyout
{
    hstring ClockIdentifier() const;
    void ClockIdentifier(hstring_view value) const;
    Windows::Foundation::TimeSpan Time() const;
    void Time(const Windows::Foundation::TimeSpan & value) const;
    int32_t MinuteIncrement() const;
    void MinuteIncrement(int32_t value) const;
    event_token TimePicked(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::TimePickerFlyout, Windows::UI::Xaml::Controls::TimePickedEventArgs> & value) const;
    using TimePicked_revoker = event_revoker<ITimePickerFlyout>;
    TimePicked_revoker TimePicked(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::TimePickerFlyout, Windows::UI::Xaml::Controls::TimePickedEventArgs> & value) const;
    void TimePicked(event_token token) const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> ShowAtAsync(const Windows::UI::Xaml::FrameworkElement & target) const;
};

template <typename D>
struct WINRT_EBO impl_ITimePickerFlyoutPresenter
{
};

template <typename D>
struct WINRT_EBO impl_ITimePickerFlyoutStatics
{
    Windows::UI::Xaml::DependencyProperty ClockIdentifierProperty() const;
    Windows::UI::Xaml::DependencyProperty TimeProperty() const;
    Windows::UI::Xaml::DependencyProperty MinuteIncrementProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ITimePickerStatics
{
    Windows::UI::Xaml::DependencyProperty HeaderProperty() const;
    Windows::UI::Xaml::DependencyProperty HeaderTemplateProperty() const;
    Windows::UI::Xaml::DependencyProperty ClockIdentifierProperty() const;
    Windows::UI::Xaml::DependencyProperty MinuteIncrementProperty() const;
    Windows::UI::Xaml::DependencyProperty TimeProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ITimePickerStatics2
{
    Windows::UI::Xaml::DependencyProperty LightDismissOverlayModeProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ITimePickerValueChangedEventArgs
{
    Windows::Foundation::TimeSpan OldTime() const;
    Windows::Foundation::TimeSpan NewTime() const;
};

template <typename D>
struct WINRT_EBO impl_IToggleMenuFlyoutItem
{
    bool IsChecked() const;
    void IsChecked(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IToggleMenuFlyoutItemFactory
{
    Windows::UI::Xaml::Controls::ToggleMenuFlyoutItem CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IToggleMenuFlyoutItemStatics
{
    Windows::UI::Xaml::DependencyProperty IsCheckedProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IToggleSwitch
{
    bool IsOn() const;
    void IsOn(bool value) const;
    Windows::Foundation::IInspectable Header() const;
    void Header(const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::DataTemplate HeaderTemplate() const;
    void HeaderTemplate(const Windows::UI::Xaml::DataTemplate & value) const;
    Windows::Foundation::IInspectable OnContent() const;
    void OnContent(const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::DataTemplate OnContentTemplate() const;
    void OnContentTemplate(const Windows::UI::Xaml::DataTemplate & value) const;
    Windows::Foundation::IInspectable OffContent() const;
    void OffContent(const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::DataTemplate OffContentTemplate() const;
    void OffContentTemplate(const Windows::UI::Xaml::DataTemplate & value) const;
    Windows::UI::Xaml::Controls::Primitives::ToggleSwitchTemplateSettings TemplateSettings() const;
    event_token Toggled(const Windows::UI::Xaml::RoutedEventHandler & value) const;
    using Toggled_revoker = event_revoker<IToggleSwitch>;
    Toggled_revoker Toggled(auto_revoke_t, const Windows::UI::Xaml::RoutedEventHandler & value) const;
    void Toggled(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IToggleSwitchOverrides
{
    void OnToggled() const;
    void OnOnContentChanged(const Windows::Foundation::IInspectable & oldContent, const Windows::Foundation::IInspectable & newContent) const;
    void OnOffContentChanged(const Windows::Foundation::IInspectable & oldContent, const Windows::Foundation::IInspectable & newContent) const;
    void OnHeaderChanged(const Windows::Foundation::IInspectable & oldContent, const Windows::Foundation::IInspectable & newContent) const;
};

template <typename D>
struct WINRT_EBO impl_IToggleSwitchStatics
{
    Windows::UI::Xaml::DependencyProperty IsOnProperty() const;
    Windows::UI::Xaml::DependencyProperty HeaderProperty() const;
    Windows::UI::Xaml::DependencyProperty HeaderTemplateProperty() const;
    Windows::UI::Xaml::DependencyProperty OnContentProperty() const;
    Windows::UI::Xaml::DependencyProperty OnContentTemplateProperty() const;
    Windows::UI::Xaml::DependencyProperty OffContentProperty() const;
    Windows::UI::Xaml::DependencyProperty OffContentTemplateProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IToolTip
{
    double HorizontalOffset() const;
    void HorizontalOffset(double value) const;
    bool IsOpen() const;
    void IsOpen(bool value) const;
    Windows::UI::Xaml::Controls::Primitives::PlacementMode Placement() const;
    void Placement(Windows::UI::Xaml::Controls::Primitives::PlacementMode value) const;
    Windows::UI::Xaml::UIElement PlacementTarget() const;
    void PlacementTarget(const Windows::UI::Xaml::UIElement & value) const;
    double VerticalOffset() const;
    void VerticalOffset(double value) const;
    Windows::UI::Xaml::Controls::Primitives::ToolTipTemplateSettings TemplateSettings() const;
    event_token Closed(const Windows::UI::Xaml::RoutedEventHandler & value) const;
    using Closed_revoker = event_revoker<IToolTip>;
    Closed_revoker Closed(auto_revoke_t, const Windows::UI::Xaml::RoutedEventHandler & value) const;
    void Closed(event_token token) const;
    event_token Opened(const Windows::UI::Xaml::RoutedEventHandler & value) const;
    using Opened_revoker = event_revoker<IToolTip>;
    Opened_revoker Opened(auto_revoke_t, const Windows::UI::Xaml::RoutedEventHandler & value) const;
    void Opened(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IToolTipFactory
{
    Windows::UI::Xaml::Controls::ToolTip CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IToolTipService
{
};

template <typename D>
struct WINRT_EBO impl_IToolTipServiceStatics
{
    Windows::UI::Xaml::DependencyProperty PlacementProperty() const;
    Windows::UI::Xaml::Controls::Primitives::PlacementMode GetPlacement(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetPlacement(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::Controls::Primitives::PlacementMode value) const;
    Windows::UI::Xaml::DependencyProperty PlacementTargetProperty() const;
    Windows::UI::Xaml::UIElement GetPlacementTarget(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetPlacementTarget(const Windows::UI::Xaml::DependencyObject & element, const Windows::UI::Xaml::UIElement & value) const;
    Windows::UI::Xaml::DependencyProperty ToolTipProperty() const;
    Windows::Foundation::IInspectable GetToolTip(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetToolTip(const Windows::UI::Xaml::DependencyObject & element, const Windows::Foundation::IInspectable & value) const;
};

template <typename D>
struct WINRT_EBO impl_IToolTipStatics
{
    Windows::UI::Xaml::DependencyProperty HorizontalOffsetProperty() const;
    Windows::UI::Xaml::DependencyProperty IsOpenProperty() const;
    Windows::UI::Xaml::DependencyProperty PlacementProperty() const;
    Windows::UI::Xaml::DependencyProperty PlacementTargetProperty() const;
    Windows::UI::Xaml::DependencyProperty VerticalOffsetProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IUIElementCollection
{
    void Move(uint32_t oldIndex, uint32_t newIndex) const;
};

template <typename D>
struct WINRT_EBO impl_IUserControl
{
    Windows::UI::Xaml::UIElement Content() const;
    void Content(const Windows::UI::Xaml::UIElement & value) const;
};

template <typename D>
struct WINRT_EBO impl_IUserControlFactory
{
    Windows::UI::Xaml::Controls::UserControl CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IUserControlStatics
{
    Windows::UI::Xaml::DependencyProperty ContentProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IVariableSizedWrapGrid
{
    double ItemHeight() const;
    void ItemHeight(double value) const;
    double ItemWidth() const;
    void ItemWidth(double value) const;
    Windows::UI::Xaml::Controls::Orientation Orientation() const;
    void Orientation(Windows::UI::Xaml::Controls::Orientation value) const;
    Windows::UI::Xaml::HorizontalAlignment HorizontalChildrenAlignment() const;
    void HorizontalChildrenAlignment(Windows::UI::Xaml::HorizontalAlignment value) const;
    Windows::UI::Xaml::VerticalAlignment VerticalChildrenAlignment() const;
    void VerticalChildrenAlignment(Windows::UI::Xaml::VerticalAlignment value) const;
    int32_t MaximumRowsOrColumns() const;
    void MaximumRowsOrColumns(int32_t value) const;
};

template <typename D>
struct WINRT_EBO impl_IVariableSizedWrapGridStatics
{
    Windows::UI::Xaml::DependencyProperty ItemHeightProperty() const;
    Windows::UI::Xaml::DependencyProperty ItemWidthProperty() const;
    Windows::UI::Xaml::DependencyProperty OrientationProperty() const;
    Windows::UI::Xaml::DependencyProperty HorizontalChildrenAlignmentProperty() const;
    Windows::UI::Xaml::DependencyProperty VerticalChildrenAlignmentProperty() const;
    Windows::UI::Xaml::DependencyProperty MaximumRowsOrColumnsProperty() const;
    Windows::UI::Xaml::DependencyProperty RowSpanProperty() const;
    int32_t GetRowSpan(const Windows::UI::Xaml::UIElement & element) const;
    void SetRowSpan(const Windows::UI::Xaml::UIElement & element, int32_t value) const;
    Windows::UI::Xaml::DependencyProperty ColumnSpanProperty() const;
    int32_t GetColumnSpan(const Windows::UI::Xaml::UIElement & element) const;
    void SetColumnSpan(const Windows::UI::Xaml::UIElement & element, int32_t value) const;
};

template <typename D>
struct WINRT_EBO impl_IViewbox
{
    Windows::UI::Xaml::UIElement Child() const;
    void Child(const Windows::UI::Xaml::UIElement & value) const;
    Windows::UI::Xaml::Media::Stretch Stretch() const;
    void Stretch(Windows::UI::Xaml::Media::Stretch value) const;
    Windows::UI::Xaml::Controls::StretchDirection StretchDirection() const;
    void StretchDirection(Windows::UI::Xaml::Controls::StretchDirection value) const;
};

template <typename D>
struct WINRT_EBO impl_IViewboxStatics
{
    Windows::UI::Xaml::DependencyProperty StretchProperty() const;
    Windows::UI::Xaml::DependencyProperty StretchDirectionProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IVirtualizingPanel
{
    Windows::UI::Xaml::Controls::ItemContainerGenerator ItemContainerGenerator() const;
};

template <typename D>
struct WINRT_EBO impl_IVirtualizingPanelFactory
{
};

template <typename D>
struct WINRT_EBO impl_IVirtualizingPanelOverrides
{
    void OnItemsChanged(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Controls::Primitives::ItemsChangedEventArgs & args) const;
    void OnClearChildren() const;
    void BringIndexIntoView(int32_t index) const;
};

template <typename D>
struct WINRT_EBO impl_IVirtualizingPanelProtected
{
    void AddInternalChild(const Windows::UI::Xaml::UIElement & child) const;
    void InsertInternalChild(int32_t index, const Windows::UI::Xaml::UIElement & child) const;
    void RemoveInternalChildRange(int32_t index, int32_t range) const;
};

template <typename D>
struct WINRT_EBO impl_IVirtualizingStackPanel
{
    bool AreScrollSnapPointsRegular() const;
    void AreScrollSnapPointsRegular(bool value) const;
    Windows::UI::Xaml::Controls::Orientation Orientation() const;
    void Orientation(Windows::UI::Xaml::Controls::Orientation value) const;
    event_token CleanUpVirtualizedItemEvent(const Windows::UI::Xaml::Controls::CleanUpVirtualizedItemEventHandler & value) const;
    using CleanUpVirtualizedItemEvent_revoker = event_revoker<IVirtualizingStackPanel>;
    CleanUpVirtualizedItemEvent_revoker CleanUpVirtualizedItemEvent(auto_revoke_t, const Windows::UI::Xaml::Controls::CleanUpVirtualizedItemEventHandler & value) const;
    void CleanUpVirtualizedItemEvent(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IVirtualizingStackPanelOverrides
{
    void OnCleanUpVirtualizedItem(const Windows::UI::Xaml::Controls::CleanUpVirtualizedItemEventArgs & e) const;
};

template <typename D>
struct WINRT_EBO impl_IVirtualizingStackPanelStatics
{
    Windows::UI::Xaml::DependencyProperty AreScrollSnapPointsRegularProperty() const;
    Windows::UI::Xaml::DependencyProperty OrientationProperty() const;
    Windows::UI::Xaml::DependencyProperty VirtualizationModeProperty() const;
    Windows::UI::Xaml::Controls::VirtualizationMode GetVirtualizationMode(const Windows::UI::Xaml::DependencyObject & element) const;
    void SetVirtualizationMode(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::Controls::VirtualizationMode value) const;
    Windows::UI::Xaml::DependencyProperty IsVirtualizingProperty() const;
    bool GetIsVirtualizing(const Windows::UI::Xaml::DependencyObject & o) const;
};

template <typename D>
struct WINRT_EBO impl_IWebView
{
    Windows::Foundation::Uri Source() const;
    void Source(const Windows::Foundation::Uri & value) const;
    [[deprecated("AllowedScriptNotifyUris is unavailable for releases beginning with Windows 8.1. Instead, list URIs under ApplicationContentUriRules in the package manifest. For more info, see the AllowedScriptNotifyUris documentation.")]] Windows::Foundation::Collections::IVector<Windows::Foundation::Uri> AllowedScriptNotifyUris() const;
    [[deprecated("AllowedScriptNotifyUris is unavailable for releases beginning with Windows 8.1. Instead, list URIs under ApplicationContentUriRules in the package manifest. For more info, see the AllowedScriptNotifyUris documentation.")]] void AllowedScriptNotifyUris(const Windows::Foundation::Collections::IVector<Windows::Foundation::Uri> & value) const;
    [[deprecated("Use CaptureSelectedContentToDataPackageAsync instead of DataTransferPackage. For more info, see MSDN.")]] Windows::ApplicationModel::DataTransfer::DataPackage DataTransferPackage() const;
    [[deprecated("LoadCompleted may be altered or unavailable for releases after Windows 8.1. Instead, use NavigationCompleted.")]] event_token LoadCompleted(const Windows::UI::Xaml::Navigation::LoadCompletedEventHandler & value) const;
    using LoadCompleted_revoker = event_revoker<IWebView>;
    [[deprecated("LoadCompleted may be altered or unavailable for releases after Windows 8.1. Instead, use NavigationCompleted.")]] LoadCompleted_revoker LoadCompleted(auto_revoke_t, const Windows::UI::Xaml::Navigation::LoadCompletedEventHandler & value) const;
    [[deprecated("LoadCompleted may be altered or unavailable for releases after Windows 8.1. Instead, use NavigationCompleted.")]] void LoadCompleted(event_token token) const;
    event_token ScriptNotify(const Windows::UI::Xaml::Controls::NotifyEventHandler & value) const;
    using ScriptNotify_revoker = event_revoker<IWebView>;
    ScriptNotify_revoker ScriptNotify(auto_revoke_t, const Windows::UI::Xaml::Controls::NotifyEventHandler & value) const;
    void ScriptNotify(event_token token) const;
    [[deprecated("NavigationFailed may be altered or unavailable for releases after Windows 8.1. Instead, use NavigationCompleted.")]] event_token NavigationFailed(const Windows::UI::Xaml::Controls::WebViewNavigationFailedEventHandler & value) const;
    using NavigationFailed_revoker = event_revoker<IWebView>;
    [[deprecated("NavigationFailed may be altered or unavailable for releases after Windows 8.1. Instead, use NavigationCompleted.")]] NavigationFailed_revoker NavigationFailed(auto_revoke_t, const Windows::UI::Xaml::Controls::WebViewNavigationFailedEventHandler & value) const;
    [[deprecated("NavigationFailed may be altered or unavailable for releases after Windows 8.1. Instead, use NavigationCompleted.")]] void NavigationFailed(event_token token) const;
    [[deprecated("Use InvokeScriptAsync instead of InvokeScript. For more info, see MSDN.")]] hstring InvokeScript(hstring_view scriptName, array_view<const hstring> arguments) const;
    void Navigate(const Windows::Foundation::Uri & source) const;
    void NavigateToString(hstring_view text) const;
};

template <typename D>
struct WINRT_EBO impl_IWebView2
{
    bool CanGoBack() const;
    bool CanGoForward() const;
    hstring DocumentTitle() const;
    event_token NavigationStarting(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewNavigationStartingEventArgs> & value) const;
    using NavigationStarting_revoker = event_revoker<IWebView2>;
    NavigationStarting_revoker NavigationStarting(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewNavigationStartingEventArgs> & value) const;
    void NavigationStarting(event_token token) const;
    event_token ContentLoading(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewContentLoadingEventArgs> & value) const;
    using ContentLoading_revoker = event_revoker<IWebView2>;
    ContentLoading_revoker ContentLoading(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewContentLoadingEventArgs> & value) const;
    void ContentLoading(event_token token) const;
    event_token DOMContentLoaded(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewDOMContentLoadedEventArgs> & value) const;
    using DOMContentLoaded_revoker = event_revoker<IWebView2>;
    DOMContentLoaded_revoker DOMContentLoaded(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewDOMContentLoadedEventArgs> & value) const;
    void DOMContentLoaded(event_token token) const;
    void GoForward() const;
    void GoBack() const;
    void Refresh() const;
    void Stop() const;
    Windows::Foundation::IAsyncAction CapturePreviewToStreamAsync(const Windows::Storage::Streams::IRandomAccessStream & stream) const;
    Windows::Foundation::IAsyncOperation<hstring> InvokeScriptAsync(hstring_view scriptName, iterable<hstring> arguments) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::DataTransfer::DataPackage> CaptureSelectedContentToDataPackageAsync() const;
    void NavigateToLocalStreamUri(const Windows::Foundation::Uri & source, const Windows::Web::IUriToStreamResolver & streamResolver) const;
    Windows::Foundation::Uri BuildLocalStreamUri(hstring_view contentIdentifier, hstring_view relativePath) const;
    Windows::UI::Color DefaultBackgroundColor() const;
    void DefaultBackgroundColor(const Windows::UI::Color & value) const;
    event_token NavigationCompleted(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewNavigationCompletedEventArgs> & value) const;
    using NavigationCompleted_revoker = event_revoker<IWebView2>;
    NavigationCompleted_revoker NavigationCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewNavigationCompletedEventArgs> & value) const;
    void NavigationCompleted(event_token token) const;
    event_token FrameNavigationStarting(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewNavigationStartingEventArgs> & value) const;
    using FrameNavigationStarting_revoker = event_revoker<IWebView2>;
    FrameNavigationStarting_revoker FrameNavigationStarting(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewNavigationStartingEventArgs> & value) const;
    void FrameNavigationStarting(event_token token) const;
    event_token FrameContentLoading(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewContentLoadingEventArgs> & value) const;
    using FrameContentLoading_revoker = event_revoker<IWebView2>;
    FrameContentLoading_revoker FrameContentLoading(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewContentLoadingEventArgs> & value) const;
    void FrameContentLoading(event_token token) const;
    event_token FrameDOMContentLoaded(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewDOMContentLoadedEventArgs> & value) const;
    using FrameDOMContentLoaded_revoker = event_revoker<IWebView2>;
    FrameDOMContentLoaded_revoker FrameDOMContentLoaded(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewDOMContentLoadedEventArgs> & value) const;
    void FrameDOMContentLoaded(event_token token) const;
    event_token FrameNavigationCompleted(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewNavigationCompletedEventArgs> & value) const;
    using FrameNavigationCompleted_revoker = event_revoker<IWebView2>;
    FrameNavigationCompleted_revoker FrameNavigationCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewNavigationCompletedEventArgs> & value) const;
    void FrameNavigationCompleted(event_token token) const;
    event_token LongRunningScriptDetected(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewLongRunningScriptDetectedEventArgs> & value) const;
    using LongRunningScriptDetected_revoker = event_revoker<IWebView2>;
    LongRunningScriptDetected_revoker LongRunningScriptDetected(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewLongRunningScriptDetectedEventArgs> & value) const;
    void LongRunningScriptDetected(event_token token) const;
    event_token UnsafeContentWarningDisplaying(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::Foundation::IInspectable> & value) const;
    using UnsafeContentWarningDisplaying_revoker = event_revoker<IWebView2>;
    UnsafeContentWarningDisplaying_revoker UnsafeContentWarningDisplaying(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::Foundation::IInspectable> & value) const;
    void UnsafeContentWarningDisplaying(event_token token) const;
    event_token UnviewableContentIdentified(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewUnviewableContentIdentifiedEventArgs> & value) const;
    using UnviewableContentIdentified_revoker = event_revoker<IWebView2>;
    UnviewableContentIdentified_revoker UnviewableContentIdentified(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewUnviewableContentIdentifiedEventArgs> & value) const;
    void UnviewableContentIdentified(event_token token) const;
    void NavigateWithHttpRequestMessage(const Windows::Web::Http::HttpRequestMessage & requestMessage) const;
    bool Focus(Windows::UI::Xaml::FocusState value) const;
};

template <typename D>
struct WINRT_EBO impl_IWebView3
{
    bool ContainsFullScreenElement() const;
    event_token ContainsFullScreenElementChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::Foundation::IInspectable> & value) const;
    using ContainsFullScreenElementChanged_revoker = event_revoker<IWebView3>;
    ContainsFullScreenElementChanged_revoker ContainsFullScreenElementChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::Foundation::IInspectable> & value) const;
    void ContainsFullScreenElementChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IWebView4
{
    Windows::UI::Xaml::Controls::WebViewExecutionMode ExecutionMode() const;
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Controls::WebViewDeferredPermissionRequest> DeferredPermissionRequests() const;
    Windows::UI::Xaml::Controls::WebViewSettings Settings() const;
    event_token UnsupportedUriSchemeIdentified(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewUnsupportedUriSchemeIdentifiedEventArgs> & value) const;
    using UnsupportedUriSchemeIdentified_revoker = event_revoker<IWebView4>;
    UnsupportedUriSchemeIdentified_revoker UnsupportedUriSchemeIdentified(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewUnsupportedUriSchemeIdentifiedEventArgs> & value) const;
    void UnsupportedUriSchemeIdentified(event_token token) const;
    event_token NewWindowRequested(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewNewWindowRequestedEventArgs> & value) const;
    using NewWindowRequested_revoker = event_revoker<IWebView4>;
    NewWindowRequested_revoker NewWindowRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewNewWindowRequestedEventArgs> & value) const;
    void NewWindowRequested(event_token token) const;
    event_token PermissionRequested(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewPermissionRequestedEventArgs> & value) const;
    using PermissionRequested_revoker = event_revoker<IWebView4>;
    PermissionRequested_revoker PermissionRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::Controls::WebView, Windows::UI::Xaml::Controls::WebViewPermissionRequestedEventArgs> & value) const;
    void PermissionRequested(event_token token) const;
    void AddWebAllowedObject(hstring_view name, const Windows::Foundation::IInspectable & pObject) const;
    Windows::UI::Xaml::Controls::WebViewDeferredPermissionRequest DeferredPermissionRequestById(uint32_t id) const;
};

template <typename D>
struct WINRT_EBO impl_IWebView5
{
    Windows::UI::Xaml::DependencyObject XYFocusLeft() const;
    void XYFocusLeft(const Windows::UI::Xaml::DependencyObject & value) const;
    Windows::UI::Xaml::DependencyObject XYFocusRight() const;
    void XYFocusRight(const Windows::UI::Xaml::DependencyObject & value) const;
    Windows::UI::Xaml::DependencyObject XYFocusUp() const;
    void XYFocusUp(const Windows::UI::Xaml::DependencyObject & value) const;
    Windows::UI::Xaml::DependencyObject XYFocusDown() const;
    void XYFocusDown(const Windows::UI::Xaml::DependencyObject & value) const;
};

template <typename D>
struct WINRT_EBO impl_IWebViewBrush
{
    hstring SourceName() const;
    void SourceName(hstring_view value) const;
    void Redraw() const;
    void SetSource(const Windows::UI::Xaml::Controls::WebView & source) const;
};

template <typename D>
struct WINRT_EBO impl_IWebViewBrushStatics
{
    Windows::UI::Xaml::DependencyProperty SourceNameProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IWebViewContentLoadingEventArgs
{
    Windows::Foundation::Uri Uri() const;
};

template <typename D>
struct WINRT_EBO impl_IWebViewDOMContentLoadedEventArgs
{
    Windows::Foundation::Uri Uri() const;
};

template <typename D>
struct WINRT_EBO impl_IWebViewDeferredPermissionRequest
{
    Windows::Foundation::Uri Uri() const;
    Windows::UI::Xaml::Controls::WebViewPermissionType PermissionType() const;
    uint32_t Id() const;
    void Allow() const;
    void Deny() const;
};

template <typename D>
struct WINRT_EBO impl_IWebViewFactory4
{
    Windows::UI::Xaml::Controls::WebView CreateInstanceWithExecutionMode(Windows::UI::Xaml::Controls::WebViewExecutionMode executionMode) const;
};

template <typename D>
struct WINRT_EBO impl_IWebViewLongRunningScriptDetectedEventArgs
{
    Windows::Foundation::TimeSpan ExecutionTime() const;
    bool StopPageScriptExecution() const;
    void StopPageScriptExecution(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IWebViewNavigationCompletedEventArgs
{
    Windows::Foundation::Uri Uri() const;
    bool IsSuccess() const;
    Windows::Web::WebErrorStatus WebErrorStatus() const;
};

template <typename D>
struct WINRT_EBO impl_IWebViewNavigationFailedEventArgs
{
    Windows::Foundation::Uri Uri() const;
    Windows::Web::WebErrorStatus WebErrorStatus() const;
};

template <typename D>
struct WINRT_EBO impl_IWebViewNavigationStartingEventArgs
{
    Windows::Foundation::Uri Uri() const;
    bool Cancel() const;
    void Cancel(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IWebViewNewWindowRequestedEventArgs
{
    Windows::Foundation::Uri Uri() const;
    Windows::Foundation::Uri Referrer() const;
    bool Handled() const;
    void Handled(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IWebViewPermissionRequest
{
    Windows::Foundation::Uri Uri() const;
    Windows::UI::Xaml::Controls::WebViewPermissionType PermissionType() const;
    uint32_t Id() const;
    Windows::UI::Xaml::Controls::WebViewPermissionState State() const;
    void Defer() const;
    void Allow() const;
    void Deny() const;
};

template <typename D>
struct WINRT_EBO impl_IWebViewPermissionRequestedEventArgs
{
    Windows::UI::Xaml::Controls::WebViewPermissionRequest PermissionRequest() const;
};

template <typename D>
struct WINRT_EBO impl_IWebViewSettings
{
    bool IsJavaScriptEnabled() const;
    void IsJavaScriptEnabled(bool value) const;
    bool IsIndexedDBEnabled() const;
    void IsIndexedDBEnabled(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IWebViewStatics
{
    [[deprecated("AnyScriptNotifyUri is unavailable for releases beginning with Windows 8.1. Instead, list URIs under ApplicationContentUriRules in the package manifest. For more info, see the AnyScriptNotifyUri documentation.")]] Windows::Foundation::Collections::IVector<Windows::Foundation::Uri> AnyScriptNotifyUri() const;
    Windows::UI::Xaml::DependencyProperty SourceProperty() const;
    [[deprecated("AllowedScriptNotifyUris is unavailable for releases beginning with Windows 8.1. Instead, list URIs under ApplicationContentUriRules in the package manifest. For more info, see the AllowedScriptNotifyUris documentation.")]] Windows::UI::Xaml::DependencyProperty AllowedScriptNotifyUrisProperty() const;
    [[deprecated("Use CaptureSelectedContentToDataPackageAsync instead of DataTransferPackage. For more info, see MSDN.")]] Windows::UI::Xaml::DependencyProperty DataTransferPackageProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IWebViewStatics2
{
    Windows::UI::Xaml::DependencyProperty CanGoBackProperty() const;
    Windows::UI::Xaml::DependencyProperty CanGoForwardProperty() const;
    Windows::UI::Xaml::DependencyProperty DocumentTitleProperty() const;
    Windows::UI::Xaml::DependencyProperty DefaultBackgroundColorProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IWebViewStatics3
{
    Windows::UI::Xaml::DependencyProperty ContainsFullScreenElementProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IWebViewStatics4
{
    Windows::UI::Xaml::Controls::WebViewExecutionMode DefaultExecutionMode() const;
    Windows::Foundation::IAsyncAction ClearTemporaryWebDataAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IWebViewStatics5
{
    Windows::UI::Xaml::DependencyProperty XYFocusLeftProperty() const;
    Windows::UI::Xaml::DependencyProperty XYFocusRightProperty() const;
    Windows::UI::Xaml::DependencyProperty XYFocusUpProperty() const;
    Windows::UI::Xaml::DependencyProperty XYFocusDownProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IWebViewUnsupportedUriSchemeIdentifiedEventArgs
{
    Windows::Foundation::Uri Uri() const;
    bool Handled() const;
    void Handled(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IWebViewUnviewableContentIdentifiedEventArgs
{
    Windows::Foundation::Uri Uri() const;
    Windows::Foundation::Uri Referrer() const;
};

template <typename D>
struct WINRT_EBO impl_IWebViewUnviewableContentIdentifiedEventArgs2
{
    hstring MediaType() const;
};

template <typename D>
struct WINRT_EBO impl_IWrapGrid
{
    double ItemWidth() const;
    void ItemWidth(double value) const;
    double ItemHeight() const;
    void ItemHeight(double value) const;
    Windows::UI::Xaml::Controls::Orientation Orientation() const;
    void Orientation(Windows::UI::Xaml::Controls::Orientation value) const;
    Windows::UI::Xaml::HorizontalAlignment HorizontalChildrenAlignment() const;
    void HorizontalChildrenAlignment(Windows::UI::Xaml::HorizontalAlignment value) const;
    Windows::UI::Xaml::VerticalAlignment VerticalChildrenAlignment() const;
    void VerticalChildrenAlignment(Windows::UI::Xaml::VerticalAlignment value) const;
    int32_t MaximumRowsOrColumns() const;
    void MaximumRowsOrColumns(int32_t value) const;
};

template <typename D>
struct WINRT_EBO impl_IWrapGridStatics
{
    Windows::UI::Xaml::DependencyProperty ItemWidthProperty() const;
    Windows::UI::Xaml::DependencyProperty ItemHeightProperty() const;
    Windows::UI::Xaml::DependencyProperty OrientationProperty() const;
    Windows::UI::Xaml::DependencyProperty HorizontalChildrenAlignmentProperty() const;
    Windows::UI::Xaml::DependencyProperty VerticalChildrenAlignmentProperty() const;
    Windows::UI::Xaml::DependencyProperty MaximumRowsOrColumnsProperty() const;
};

}

namespace impl {

template <> struct traits<Windows::UI::Xaml::Controls::BackClickEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::Controls::BackClickEventHandler;
};

template <> struct traits<Windows::UI::Xaml::Controls::CalendarViewDayItemChangingEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::Controls::CalendarViewDayItemChangingEventHandler;
};

template <> struct traits<Windows::UI::Xaml::Controls::CleanUpVirtualizedItemEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::Controls::CleanUpVirtualizedItemEventHandler;
};

template <> struct traits<Windows::UI::Xaml::Controls::ContextMenuOpeningEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ContextMenuOpeningEventHandler;
};

template <> struct traits<Windows::UI::Xaml::Controls::DragItemsStartingEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::Controls::DragItemsStartingEventHandler;
};

template <> struct traits<Windows::UI::Xaml::Controls::HubSectionHeaderClickEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::Controls::HubSectionHeaderClickEventHandler;
};

template <> struct traits<Windows::UI::Xaml::Controls::IAppBar>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IAppBar;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IAppBar<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IAppBar2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IAppBar2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IAppBar2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IAppBar3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IAppBar3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IAppBar3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IAppBar4>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IAppBar4;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IAppBar4<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IAppBarButton>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IAppBarButton;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IAppBarButton<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IAppBarButton3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IAppBarButton3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IAppBarButton3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IAppBarButtonFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IAppBarButtonFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IAppBarButtonFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IAppBarButtonStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IAppBarButtonStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IAppBarButtonStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IAppBarButtonStatics3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IAppBarButtonStatics3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IAppBarButtonStatics3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IAppBarFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IAppBarFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IAppBarFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IAppBarOverrides>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IAppBarOverrides;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IAppBarOverrides<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IAppBarOverrides3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IAppBarOverrides3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IAppBarOverrides3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IAppBarSeparator>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IAppBarSeparator;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IAppBarSeparator<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IAppBarSeparatorFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IAppBarSeparatorFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IAppBarSeparatorFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IAppBarSeparatorStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IAppBarSeparatorStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IAppBarSeparatorStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IAppBarSeparatorStatics3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IAppBarSeparatorStatics3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IAppBarSeparatorStatics3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IAppBarStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IAppBarStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IAppBarStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IAppBarStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IAppBarStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IAppBarStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IAppBarStatics4>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IAppBarStatics4;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IAppBarStatics4<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IAppBarToggleButton>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IAppBarToggleButton;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IAppBarToggleButton<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IAppBarToggleButton3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IAppBarToggleButton3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IAppBarToggleButton3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IAppBarToggleButtonFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IAppBarToggleButtonFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IAppBarToggleButtonFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IAppBarToggleButtonStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IAppBarToggleButtonStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IAppBarToggleButtonStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IAppBarToggleButtonStatics3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IAppBarToggleButtonStatics3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IAppBarToggleButtonStatics3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IAutoSuggestBox>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IAutoSuggestBox;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IAutoSuggestBox<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IAutoSuggestBox2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IAutoSuggestBox2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IAutoSuggestBox2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IAutoSuggestBox3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IAutoSuggestBox3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IAutoSuggestBox3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IAutoSuggestBoxQuerySubmittedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IAutoSuggestBoxQuerySubmittedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IAutoSuggestBoxQuerySubmittedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IAutoSuggestBoxStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IAutoSuggestBoxStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IAutoSuggestBoxStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IAutoSuggestBoxStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IAutoSuggestBoxStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IAutoSuggestBoxStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IAutoSuggestBoxStatics3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IAutoSuggestBoxStatics3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IAutoSuggestBoxStatics3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IAutoSuggestBoxSuggestionChosenEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IAutoSuggestBoxSuggestionChosenEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IAutoSuggestBoxSuggestionChosenEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IAutoSuggestBoxTextChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IAutoSuggestBoxTextChangedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IAutoSuggestBoxTextChangedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IAutoSuggestBoxTextChangedEventArgsStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IAutoSuggestBoxTextChangedEventArgsStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IAutoSuggestBoxTextChangedEventArgsStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IBackClickEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IBackClickEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IBackClickEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IBitmapIcon>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IBitmapIcon;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IBitmapIcon<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IBitmapIconFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IBitmapIconFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IBitmapIconFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IBitmapIconStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IBitmapIconStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IBitmapIconStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IBorder>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IBorder;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IBorder<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IBorderStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IBorderStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IBorderStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IButton>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IButton;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IButton<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IButtonFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IButtonFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IButtonFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IButtonStaticsWithFlyout>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IButtonStaticsWithFlyout;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IButtonStaticsWithFlyout<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IButtonWithFlyout>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IButtonWithFlyout;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IButtonWithFlyout<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ICalendarDatePicker>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ICalendarDatePicker;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ICalendarDatePicker<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ICalendarDatePicker2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ICalendarDatePicker2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ICalendarDatePicker2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ICalendarDatePickerDateChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ICalendarDatePickerDateChangedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ICalendarDatePickerDateChangedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ICalendarDatePickerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ICalendarDatePickerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ICalendarDatePickerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ICalendarDatePickerStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ICalendarDatePickerStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ICalendarDatePickerStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ICalendarDatePickerStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ICalendarDatePickerStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ICalendarDatePickerStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ICalendarView>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ICalendarView;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ICalendarView<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ICalendarViewDayItem>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ICalendarViewDayItem;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ICalendarViewDayItem<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ICalendarViewDayItemChangingEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ICalendarViewDayItemChangingEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ICalendarViewDayItemChangingEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ICalendarViewDayItemFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ICalendarViewDayItemFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ICalendarViewDayItemFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ICalendarViewDayItemStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ICalendarViewDayItemStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ICalendarViewDayItemStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ICalendarViewFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ICalendarViewFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ICalendarViewFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ICalendarViewSelectedDatesChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ICalendarViewSelectedDatesChangedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ICalendarViewSelectedDatesChangedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ICalendarViewStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ICalendarViewStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ICalendarViewStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ICandidateWindowBoundsChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ICandidateWindowBoundsChangedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ICandidateWindowBoundsChangedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ICanvas>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ICanvas;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ICanvas<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ICanvasFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ICanvasFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ICanvasFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ICanvasStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ICanvasStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ICanvasStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ICaptureElement>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ICaptureElement;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ICaptureElement<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ICaptureElementStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ICaptureElementStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ICaptureElementStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ICheckBox>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ICheckBox;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ICheckBox<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ICheckBoxFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ICheckBoxFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ICheckBoxFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IChoosingGroupHeaderContainerEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IChoosingGroupHeaderContainerEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IChoosingGroupHeaderContainerEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IChoosingItemContainerEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IChoosingItemContainerEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IChoosingItemContainerEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ICleanUpVirtualizedItemEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ICleanUpVirtualizedItemEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ICleanUpVirtualizedItemEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IColumnDefinition>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IColumnDefinition;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IColumnDefinition<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IColumnDefinitionStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IColumnDefinitionStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IColumnDefinitionStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IComboBox>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IComboBox;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IComboBox<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IComboBox2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IComboBox2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IComboBox2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IComboBox3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IComboBox3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IComboBox3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IComboBoxFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IComboBoxFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IComboBoxFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IComboBoxItem>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IComboBoxItem;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IComboBoxItem<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IComboBoxItemFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IComboBoxItemFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IComboBoxItemFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IComboBoxOverrides>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IComboBoxOverrides;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IComboBoxOverrides<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IComboBoxStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IComboBoxStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IComboBoxStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IComboBoxStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IComboBoxStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IComboBoxStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IComboBoxStatics3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IComboBoxStatics3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IComboBoxStatics3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ICommandBar>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ICommandBar;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ICommandBar<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ICommandBar2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ICommandBar2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ICommandBar2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ICommandBar3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ICommandBar3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ICommandBar3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ICommandBarElement>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ICommandBarElement;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ICommandBarElement<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ICommandBarElement2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ICommandBarElement2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ICommandBarElement2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ICommandBarFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ICommandBarFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ICommandBarFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ICommandBarOverflowPresenter>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ICommandBarOverflowPresenter;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ICommandBarOverflowPresenter<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ICommandBarOverflowPresenterFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ICommandBarOverflowPresenterFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ICommandBarOverflowPresenterFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ICommandBarStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ICommandBarStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ICommandBarStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ICommandBarStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ICommandBarStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ICommandBarStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ICommandBarStatics3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ICommandBarStatics3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ICommandBarStatics3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IContainerContentChangingEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IContainerContentChangingEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IContainerContentChangingEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IContentControl>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IContentControl;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IContentControl<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IContentControl2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IContentControl2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IContentControl2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IContentControlFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IContentControlFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IContentControlFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IContentControlOverrides>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IContentControlOverrides;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IContentControlOverrides<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IContentControlStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IContentControlStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IContentControlStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IContentDialog>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IContentDialog;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IContentDialog<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IContentDialogButtonClickDeferral>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IContentDialogButtonClickDeferral;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IContentDialogButtonClickDeferral<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IContentDialogButtonClickEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IContentDialogButtonClickEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IContentDialogButtonClickEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IContentDialogClosedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IContentDialogClosedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IContentDialogClosedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IContentDialogClosingDeferral>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IContentDialogClosingDeferral;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IContentDialogClosingDeferral<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IContentDialogClosingEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IContentDialogClosingEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IContentDialogClosingEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IContentDialogFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IContentDialogFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IContentDialogFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IContentDialogOpenedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IContentDialogOpenedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IContentDialogOpenedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IContentDialogStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IContentDialogStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IContentDialogStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IContentPresenter>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IContentPresenter;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IContentPresenter<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IContentPresenter2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IContentPresenter2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IContentPresenter2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IContentPresenter3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IContentPresenter3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IContentPresenter3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IContentPresenter4>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IContentPresenter4;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IContentPresenter4<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IContentPresenterFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IContentPresenterFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IContentPresenterFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IContentPresenterOverrides>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IContentPresenterOverrides;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IContentPresenterOverrides<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IContentPresenterStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IContentPresenterStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IContentPresenterStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IContentPresenterStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IContentPresenterStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IContentPresenterStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IContentPresenterStatics3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IContentPresenterStatics3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IContentPresenterStatics3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IContentPresenterStatics4>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IContentPresenterStatics4;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IContentPresenterStatics4<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IContextMenuEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IContextMenuEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IContextMenuEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IControl>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IControl;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IControl<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IControl2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IControl2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IControl2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IControl3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IControl3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IControl3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IControl4>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IControl4;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IControl4<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IControlFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IControlFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IControlFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IControlOverrides>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IControlOverrides;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IControlOverrides<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IControlProtected>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IControlProtected;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IControlProtected<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IControlStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IControlStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IControlStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IControlStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IControlStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IControlStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IControlStatics3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IControlStatics3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IControlStatics3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IControlStatics4>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IControlStatics4;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IControlStatics4<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IControlTemplate>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IControlTemplate;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IControlTemplate<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IDataTemplateSelector>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IDataTemplateSelector;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IDataTemplateSelector<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IDataTemplateSelector2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IDataTemplateSelector2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IDataTemplateSelector2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IDataTemplateSelectorFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IDataTemplateSelectorFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IDataTemplateSelectorFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IDataTemplateSelectorOverrides>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IDataTemplateSelectorOverrides;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IDataTemplateSelectorOverrides<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IDataTemplateSelectorOverrides2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IDataTemplateSelectorOverrides2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IDataTemplateSelectorOverrides2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IDatePickedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IDatePickedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IDatePickedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IDatePicker>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IDatePicker;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IDatePicker<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IDatePicker2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IDatePicker2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IDatePicker2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IDatePickerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IDatePickerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IDatePickerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IDatePickerFlyout>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IDatePickerFlyout;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IDatePickerFlyout<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IDatePickerFlyout2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IDatePickerFlyout2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IDatePickerFlyout2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IDatePickerFlyoutItem>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IDatePickerFlyoutItem;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IDatePickerFlyoutItem<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IDatePickerFlyoutItemStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IDatePickerFlyoutItemStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IDatePickerFlyoutItemStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IDatePickerFlyoutPresenter>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IDatePickerFlyoutPresenter;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IDatePickerFlyoutPresenter<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IDatePickerFlyoutStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IDatePickerFlyoutStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IDatePickerFlyoutStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IDatePickerFlyoutStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IDatePickerFlyoutStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IDatePickerFlyoutStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IDatePickerStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IDatePickerStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IDatePickerStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IDatePickerStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IDatePickerStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IDatePickerStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IDatePickerValueChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IDatePickerValueChangedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IDatePickerValueChangedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IDragItemsCompletedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IDragItemsCompletedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IDragItemsCompletedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IDragItemsStartingEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IDragItemsStartingEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IDragItemsStartingEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IDynamicOverflowItemsChangingEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IDynamicOverflowItemsChangingEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IDynamicOverflowItemsChangingEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IFlipView>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IFlipView;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IFlipView<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IFlipView2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IFlipView2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IFlipView2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IFlipViewFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IFlipViewFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IFlipViewFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IFlipViewItem>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IFlipViewItem;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IFlipViewItem<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IFlipViewItemFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IFlipViewItemFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IFlipViewItemFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IFlipViewStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IFlipViewStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IFlipViewStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IFlyout>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IFlyout;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IFlyout<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IFlyoutFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IFlyoutFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IFlyoutFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IFlyoutPresenter>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IFlyoutPresenter;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IFlyoutPresenter<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IFlyoutPresenterFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IFlyoutPresenterFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IFlyoutPresenterFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IFlyoutStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IFlyoutStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IFlyoutStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IFocusDisengagedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IFocusDisengagedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IFocusDisengagedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IFocusEngagedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IFocusEngagedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IFocusEngagedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IFontIcon>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IFontIcon;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IFontIcon<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IFontIcon2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IFontIcon2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IFontIcon2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IFontIcon3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IFontIcon3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IFontIcon3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IFontIconFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IFontIconFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IFontIconFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IFontIconStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IFontIconStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IFontIconStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IFontIconStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IFontIconStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IFontIconStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IFontIconStatics3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IFontIconStatics3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IFontIconStatics3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IFrame>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IFrame;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IFrame<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IFrame2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IFrame2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IFrame2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IFrame3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IFrame3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IFrame3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IFrameFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IFrameFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IFrameFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IFrameStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IFrameStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IFrameStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IFrameStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IFrameStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IFrameStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IGrid>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IGrid;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IGrid<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IGrid2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IGrid2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IGrid2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IGridFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IGridFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IGridFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IGridStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IGridStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IGridStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IGridStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IGridStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IGridStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IGridView>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IGridView;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IGridView<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IGridViewFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IGridViewFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IGridViewFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IGridViewHeaderItem>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IGridViewHeaderItem;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IGridViewHeaderItem<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IGridViewHeaderItemFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IGridViewHeaderItemFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IGridViewHeaderItemFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IGridViewItem>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IGridViewItem;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IGridViewItem<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IGridViewItemFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IGridViewItemFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IGridViewItemFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IGroupItem>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IGroupItem;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IGroupItem<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IGroupItemFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IGroupItemFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IGroupItemFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IGroupStyle>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IGroupStyle;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IGroupStyle<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IGroupStyle2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IGroupStyle2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IGroupStyle2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IGroupStyleFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IGroupStyleFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IGroupStyleFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IGroupStyleSelector>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IGroupStyleSelector;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IGroupStyleSelector<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IGroupStyleSelectorFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IGroupStyleSelectorFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IGroupStyleSelectorFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IGroupStyleSelectorOverrides>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IGroupStyleSelectorOverrides;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IGroupStyleSelectorOverrides<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IHub>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IHub;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IHub<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IHubFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IHubFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IHubFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IHubSection>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IHubSection;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IHubSection<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IHubSectionFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IHubSectionFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IHubSectionFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IHubSectionHeaderClickEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IHubSectionHeaderClickEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IHubSectionHeaderClickEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IHubSectionStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IHubSectionStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IHubSectionStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IHubStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IHubStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IHubStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IHyperlinkButton>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IHyperlinkButton;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IHyperlinkButton<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IHyperlinkButtonFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IHyperlinkButtonFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IHyperlinkButtonFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IHyperlinkButtonStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IHyperlinkButtonStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IHyperlinkButtonStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IIconElement>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IIconElement;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IIconElement<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IIconElementFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IIconElementFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IIconElementFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IIconElementStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IIconElementStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IIconElementStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IImage>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IImage;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IImage<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IImage2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IImage2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IImage2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IImage3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IImage3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IImage3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IImageStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IImageStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IImageStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkCanvas>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkCanvas;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkCanvas<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkCanvasFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkCanvasFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkCanvasFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkToolbar>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkToolbar;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkToolbar<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkToolbarBallpointPenButton>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkToolbarBallpointPenButton;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkToolbarBallpointPenButton<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkToolbarBallpointPenButtonFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkToolbarBallpointPenButtonFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkToolbarBallpointPenButtonFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkToolbarCustomPen>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkToolbarCustomPen;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkToolbarCustomPen<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkToolbarCustomPenButton>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkToolbarCustomPenButton;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkToolbarCustomPenButton<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkToolbarCustomPenButtonFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkToolbarCustomPenButtonFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkToolbarCustomPenButtonFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkToolbarCustomPenButtonStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkToolbarCustomPenButtonStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkToolbarCustomPenButtonStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkToolbarCustomPenFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkToolbarCustomPenFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkToolbarCustomPenFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkToolbarCustomPenOverrides>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkToolbarCustomPenOverrides;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkToolbarCustomPenOverrides<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkToolbarCustomToggleButton>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkToolbarCustomToggleButton;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkToolbarCustomToggleButton<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkToolbarCustomToggleButtonFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkToolbarCustomToggleButtonFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkToolbarCustomToggleButtonFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkToolbarCustomToolButton>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkToolbarCustomToolButton;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkToolbarCustomToolButton<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkToolbarCustomToolButtonFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkToolbarCustomToolButtonFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkToolbarCustomToolButtonFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkToolbarCustomToolButtonStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkToolbarCustomToolButtonStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkToolbarCustomToolButtonStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkToolbarEraserButton>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkToolbarEraserButton;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkToolbarEraserButton<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkToolbarEraserButtonFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkToolbarEraserButtonFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkToolbarEraserButtonFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkToolbarFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkToolbarFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkToolbarFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkToolbarHighlighterButton>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkToolbarHighlighterButton;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkToolbarHighlighterButton<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkToolbarHighlighterButtonFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkToolbarHighlighterButtonFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkToolbarHighlighterButtonFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkToolbarPenButton>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkToolbarPenButton;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkToolbarPenButton<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkToolbarPenButtonFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkToolbarPenButtonFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkToolbarPenButtonFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkToolbarPenButtonStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkToolbarPenButtonStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkToolbarPenButtonStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkToolbarPenConfigurationControl>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkToolbarPenConfigurationControl;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkToolbarPenConfigurationControl<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkToolbarPenConfigurationControlFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkToolbarPenConfigurationControlFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkToolbarPenConfigurationControlFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkToolbarPenConfigurationControlStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkToolbarPenConfigurationControlStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkToolbarPenConfigurationControlStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkToolbarPencilButton>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkToolbarPencilButton;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkToolbarPencilButton<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkToolbarPencilButtonFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkToolbarPencilButtonFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkToolbarPencilButtonFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkToolbarRulerButton>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkToolbarRulerButton;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkToolbarRulerButton<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkToolbarRulerButtonFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkToolbarRulerButtonFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkToolbarRulerButtonFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkToolbarRulerButtonStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkToolbarRulerButtonStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkToolbarRulerButtonStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkToolbarStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkToolbarStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkToolbarStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkToolbarToggleButton>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkToolbarToggleButton;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkToolbarToggleButton<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkToolbarToggleButtonFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkToolbarToggleButtonFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkToolbarToggleButtonFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkToolbarToolButton>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkToolbarToolButton;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkToolbarToolButton<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkToolbarToolButtonFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkToolbarToolButtonFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkToolbarToolButtonFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInkToolbarToolButtonStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInkToolbarToolButtonStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInkToolbarToolButtonStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IInsertionPanel>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IInsertionPanel;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IInsertionPanel<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IItemClickEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IItemClickEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IItemClickEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IItemContainerGenerator>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IItemContainerGenerator;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IItemContainerGenerator<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IItemContainerMapping>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IItemContainerMapping;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IItemContainerMapping<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IItemsControl>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IItemsControl;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IItemsControl<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IItemsControl2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IItemsControl2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IItemsControl2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IItemsControl3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IItemsControl3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IItemsControl3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IItemsControlFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IItemsControlFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IItemsControlFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IItemsControlOverrides>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IItemsControlOverrides;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IItemsControlOverrides<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IItemsControlStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IItemsControlStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IItemsControlStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IItemsPanelTemplate>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IItemsPanelTemplate;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IItemsPanelTemplate<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IItemsPickedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IItemsPickedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IItemsPickedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IItemsPresenter>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IItemsPresenter;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IItemsPresenter<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IItemsPresenter2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IItemsPresenter2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IItemsPresenter2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IItemsPresenterStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IItemsPresenterStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IItemsPresenterStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IItemsPresenterStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IItemsPresenterStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IItemsPresenterStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IItemsStackPanel>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IItemsStackPanel;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IItemsStackPanel<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IItemsStackPanel2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IItemsStackPanel2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IItemsStackPanel2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IItemsStackPanelStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IItemsStackPanelStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IItemsStackPanelStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IItemsStackPanelStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IItemsStackPanelStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IItemsStackPanelStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IItemsWrapGrid>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IItemsWrapGrid;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IItemsWrapGrid<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IItemsWrapGrid2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IItemsWrapGrid2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IItemsWrapGrid2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IItemsWrapGridStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IItemsWrapGridStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IItemsWrapGridStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IItemsWrapGridStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IItemsWrapGridStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IItemsWrapGridStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IListBox>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IListBox;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IListBox<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IListBox2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IListBox2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IListBox2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IListBoxFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IListBoxFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IListBoxFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IListBoxItem>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IListBoxItem;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IListBoxItem<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IListBoxItemFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IListBoxItemFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IListBoxItemFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IListBoxStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IListBoxStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IListBoxStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IListBoxStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IListBoxStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IListBoxStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IListPickerFlyout>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IListPickerFlyout;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IListPickerFlyout<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IListPickerFlyoutPresenter>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IListPickerFlyoutPresenter;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IListPickerFlyoutPresenter<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IListPickerFlyoutStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IListPickerFlyoutStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IListPickerFlyoutStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IListView>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IListView;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IListView<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IListViewBase>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IListViewBase;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IListViewBase<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IListViewBase2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IListViewBase2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IListViewBase2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IListViewBase3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IListViewBase3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IListViewBase3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IListViewBase4>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IListViewBase4;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IListViewBase4<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IListViewBase5>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IListViewBase5;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IListViewBase5<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IListViewBaseFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IListViewBaseFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IListViewBaseFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IListViewBaseHeaderItem>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IListViewBaseHeaderItem;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IListViewBaseHeaderItem<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IListViewBaseHeaderItemFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IListViewBaseHeaderItemFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IListViewBaseHeaderItemFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IListViewBaseStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IListViewBaseStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IListViewBaseStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IListViewBaseStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IListViewBaseStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IListViewBaseStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IListViewBaseStatics3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IListViewBaseStatics3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IListViewBaseStatics3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IListViewBaseStatics4>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IListViewBaseStatics4;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IListViewBaseStatics4<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IListViewBaseStatics5>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IListViewBaseStatics5;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IListViewBaseStatics5<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IListViewFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IListViewFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IListViewFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IListViewHeaderItem>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IListViewHeaderItem;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IListViewHeaderItem<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IListViewHeaderItemFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IListViewHeaderItemFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IListViewHeaderItemFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IListViewItem>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IListViewItem;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IListViewItem<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IListViewItemFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IListViewItemFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IListViewItemFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IListViewPersistenceHelper>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IListViewPersistenceHelper;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IListViewPersistenceHelper<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IListViewPersistenceHelperStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IListViewPersistenceHelperStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IListViewPersistenceHelperStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IMediaElement>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IMediaElement;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IMediaElement<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IMediaElement2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IMediaElement2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IMediaElement2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IMediaElement3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IMediaElement3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IMediaElement3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IMediaElementStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IMediaElementStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IMediaElementStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IMediaElementStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IMediaElementStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IMediaElementStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IMediaPlayerElement>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IMediaPlayerElement;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IMediaPlayerElement<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IMediaPlayerElementFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IMediaPlayerElementFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IMediaPlayerElementFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IMediaPlayerElementStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IMediaPlayerElementStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IMediaPlayerElementStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IMediaPlayerPresenter>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IMediaPlayerPresenter;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IMediaPlayerPresenter<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IMediaPlayerPresenterFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IMediaPlayerPresenterFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IMediaPlayerPresenterFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IMediaPlayerPresenterStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IMediaPlayerPresenterStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IMediaPlayerPresenterStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IMediaTransportControls>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IMediaTransportControls;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IMediaTransportControls<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IMediaTransportControls2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IMediaTransportControls2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IMediaTransportControls2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IMediaTransportControlsFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IMediaTransportControlsFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IMediaTransportControlsFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IMediaTransportControlsHelper>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IMediaTransportControlsHelper;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IMediaTransportControlsHelper<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IMediaTransportControlsHelperStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IMediaTransportControlsHelperStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IMediaTransportControlsHelperStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IMediaTransportControlsStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IMediaTransportControlsStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IMediaTransportControlsStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IMediaTransportControlsStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IMediaTransportControlsStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IMediaTransportControlsStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IMenuFlyout>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IMenuFlyout;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IMenuFlyout<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IMenuFlyout2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IMenuFlyout2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IMenuFlyout2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IMenuFlyoutFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IMenuFlyoutFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IMenuFlyoutFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IMenuFlyoutItem>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IMenuFlyoutItem;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IMenuFlyoutItem<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IMenuFlyoutItemBase>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IMenuFlyoutItemBase;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IMenuFlyoutItemBase<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IMenuFlyoutItemBaseFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IMenuFlyoutItemBaseFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IMenuFlyoutItemBaseFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IMenuFlyoutItemFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IMenuFlyoutItemFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IMenuFlyoutItemFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IMenuFlyoutItemStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IMenuFlyoutItemStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IMenuFlyoutItemStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IMenuFlyoutPresenter>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IMenuFlyoutPresenter;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IMenuFlyoutPresenter<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IMenuFlyoutPresenter2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IMenuFlyoutPresenter2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IMenuFlyoutPresenter2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IMenuFlyoutPresenterFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IMenuFlyoutPresenterFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IMenuFlyoutPresenterFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IMenuFlyoutSeparator>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IMenuFlyoutSeparator;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IMenuFlyoutSeparator<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IMenuFlyoutSeparatorFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IMenuFlyoutSeparatorFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IMenuFlyoutSeparatorFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IMenuFlyoutStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IMenuFlyoutStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IMenuFlyoutStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IMenuFlyoutSubItem>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IMenuFlyoutSubItem;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IMenuFlyoutSubItem<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IMenuFlyoutSubItemStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IMenuFlyoutSubItemStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IMenuFlyoutSubItemStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::INavigate>
{
    using abi = ABI::Windows::UI::Xaml::Controls::INavigate;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_INavigate<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::INotifyEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::INotifyEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_INotifyEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::INotifyEventArgs2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::INotifyEventArgs2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_INotifyEventArgs2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IPage>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IPage;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IPage<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IPageFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IPageFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IPageFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IPageOverrides>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IPageOverrides;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IPageOverrides<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IPageStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IPageStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IPageStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IPanel>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IPanel;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IPanel<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IPanelFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IPanelFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IPanelFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IPanelStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IPanelStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IPanelStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IPasswordBox>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IPasswordBox;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IPasswordBox<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IPasswordBox2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IPasswordBox2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IPasswordBox2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IPasswordBox3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IPasswordBox3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IPasswordBox3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IPasswordBoxStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IPasswordBoxStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IPasswordBoxStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IPasswordBoxStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IPasswordBoxStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IPasswordBoxStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IPasswordBoxStatics3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IPasswordBoxStatics3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IPasswordBoxStatics3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IPathIcon>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IPathIcon;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IPathIcon<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IPathIconFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IPathIconFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IPathIconFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IPathIconStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IPathIconStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IPathIconStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IPickerConfirmedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IPickerConfirmedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IPickerConfirmedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IPickerFlyout>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IPickerFlyout;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IPickerFlyout<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IPickerFlyoutPresenter>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IPickerFlyoutPresenter;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IPickerFlyoutPresenter<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IPickerFlyoutStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IPickerFlyoutStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IPickerFlyoutStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IPivot>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IPivot;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IPivot<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IPivot2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IPivot2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IPivot2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IPivot3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IPivot3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IPivot3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IPivotFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IPivotFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IPivotFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IPivotItem>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IPivotItem;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IPivotItem<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IPivotItemEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IPivotItemEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IPivotItemEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IPivotItemFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IPivotItemFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IPivotItemFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IPivotItemStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IPivotItemStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IPivotItemStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IPivotStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IPivotStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IPivotStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IPivotStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IPivotStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IPivotStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IPivotStatics3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IPivotStatics3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IPivotStatics3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IProgressBar>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IProgressBar;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IProgressBar<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IProgressBarFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IProgressBarFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IProgressBarFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IProgressBarStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IProgressBarStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IProgressBarStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IProgressRing>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IProgressRing;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IProgressRing<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IProgressRingStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IProgressRingStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IProgressRingStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IRadioButton>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IRadioButton;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IRadioButton<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IRadioButtonFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IRadioButtonFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IRadioButtonFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IRadioButtonStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IRadioButtonStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IRadioButtonStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IRelativePanel>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IRelativePanel;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IRelativePanel<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IRelativePanelFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IRelativePanelFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IRelativePanelFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IRelativePanelStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IRelativePanelStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IRelativePanelStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IRichEditBox>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IRichEditBox;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IRichEditBox<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IRichEditBox2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IRichEditBox2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IRichEditBox2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IRichEditBox3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IRichEditBox3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IRichEditBox3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IRichEditBox4>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IRichEditBox4;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IRichEditBox4<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IRichEditBoxFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IRichEditBoxFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IRichEditBoxFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IRichEditBoxStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IRichEditBoxStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IRichEditBoxStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IRichEditBoxStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IRichEditBoxStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IRichEditBoxStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IRichEditBoxStatics3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IRichEditBoxStatics3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IRichEditBoxStatics3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IRichEditBoxStatics4>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IRichEditBoxStatics4;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IRichEditBoxStatics4<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IRichEditBoxTextChangingEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IRichEditBoxTextChangingEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IRichEditBoxTextChangingEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IRichTextBlock>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IRichTextBlock;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IRichTextBlock<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IRichTextBlock2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IRichTextBlock2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IRichTextBlock2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IRichTextBlock3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IRichTextBlock3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IRichTextBlock3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IRichTextBlockOverflow>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IRichTextBlockOverflow;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IRichTextBlockOverflow<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IRichTextBlockOverflow2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IRichTextBlockOverflow2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IRichTextBlockOverflow2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IRichTextBlockOverflowStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IRichTextBlockOverflowStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IRichTextBlockOverflowStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IRichTextBlockOverflowStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IRichTextBlockOverflowStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IRichTextBlockOverflowStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IRichTextBlockStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IRichTextBlockStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IRichTextBlockStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IRichTextBlockStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IRichTextBlockStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IRichTextBlockStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IRichTextBlockStatics3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IRichTextBlockStatics3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IRichTextBlockStatics3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IRowDefinition>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IRowDefinition;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IRowDefinition<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IRowDefinitionStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IRowDefinitionStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IRowDefinitionStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IScrollContentPresenter>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IScrollContentPresenter;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IScrollContentPresenter<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IScrollViewer>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IScrollViewer;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IScrollViewer<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IScrollViewer2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IScrollViewer2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IScrollViewer2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IScrollViewer3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IScrollViewer3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IScrollViewer3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IScrollViewerStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IScrollViewerStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IScrollViewerStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IScrollViewerStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IScrollViewerStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IScrollViewerStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IScrollViewerView>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IScrollViewerView;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IScrollViewerView<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IScrollViewerViewChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IScrollViewerViewChangedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IScrollViewerViewChangedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IScrollViewerViewChangingEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IScrollViewerViewChangingEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IScrollViewerViewChangingEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISearchBox>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISearchBox;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISearchBox<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISearchBoxFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISearchBoxFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISearchBoxFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISearchBoxQueryChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISearchBoxQueryChangedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISearchBoxQueryChangedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISearchBoxQuerySubmittedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISearchBoxQuerySubmittedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISearchBoxQuerySubmittedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISearchBoxResultSuggestionChosenEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISearchBoxResultSuggestionChosenEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISearchBoxResultSuggestionChosenEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISearchBoxStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISearchBoxStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISearchBoxStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISearchBoxSuggestionsRequestedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISearchBoxSuggestionsRequestedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISearchBoxSuggestionsRequestedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISectionsInViewChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISectionsInViewChangedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISectionsInViewChangedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISectionsInViewChangedEventArgsFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISectionsInViewChangedEventArgsFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISectionsInViewChangedEventArgsFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISelectionChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISelectionChangedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISelectionChangedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISelectionChangedEventArgsFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISelectionChangedEventArgsFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISelectionChangedEventArgsFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISemanticZoom>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISemanticZoom;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISemanticZoom<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISemanticZoomInformation>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISemanticZoomInformation;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISemanticZoomInformation<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISemanticZoomLocation>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISemanticZoomLocation;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISemanticZoomLocation<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISemanticZoomStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISemanticZoomStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISemanticZoomStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISemanticZoomViewChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISemanticZoomViewChangedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISemanticZoomViewChangedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISettingsFlyout>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISettingsFlyout;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISettingsFlyout<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISettingsFlyoutFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISettingsFlyoutFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISettingsFlyoutFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISettingsFlyoutStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISettingsFlyoutStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISettingsFlyoutStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISlider>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISlider;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISlider<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISlider2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISlider2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISlider2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISliderFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISliderFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISliderFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISliderStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISliderStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISliderStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISliderStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISliderStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISliderStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISplitView>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISplitView;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISplitView<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISplitView2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISplitView2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISplitView2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISplitViewFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISplitViewFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISplitViewFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISplitViewPaneClosingEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISplitViewPaneClosingEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISplitViewPaneClosingEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISplitViewStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISplitViewStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISplitViewStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISplitViewStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISplitViewStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISplitViewStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IStackPanel>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IStackPanel;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IStackPanel<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IStackPanel2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IStackPanel2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IStackPanel2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IStackPanelFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IStackPanelFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IStackPanelFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IStackPanelStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IStackPanelStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IStackPanelStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IStackPanelStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IStackPanelStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IStackPanelStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IStyleSelector>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IStyleSelector;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IStyleSelector<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IStyleSelectorFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IStyleSelectorFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IStyleSelectorFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IStyleSelectorOverrides>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IStyleSelectorOverrides;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IStyleSelectorOverrides<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISwapChainBackgroundPanel>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISwapChainBackgroundPanel;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISwapChainBackgroundPanel<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISwapChainBackgroundPanel2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISwapChainBackgroundPanel2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISwapChainBackgroundPanel2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISwapChainBackgroundPanelFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISwapChainBackgroundPanelFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISwapChainBackgroundPanelFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISwapChainPanel>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISwapChainPanel;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISwapChainPanel<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISwapChainPanelFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISwapChainPanelFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISwapChainPanelFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISwapChainPanelStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISwapChainPanelStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISwapChainPanelStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISymbolIcon>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISymbolIcon;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISymbolIcon<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISymbolIconFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISymbolIconFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISymbolIconFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ISymbolIconStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ISymbolIconStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ISymbolIconStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ITextBlock>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ITextBlock;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ITextBlock<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ITextBlock2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ITextBlock2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ITextBlock2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ITextBlock3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ITextBlock3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ITextBlock3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ITextBlock4>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ITextBlock4;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ITextBlock4<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ITextBlockStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ITextBlockStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ITextBlockStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ITextBlockStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ITextBlockStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ITextBlockStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ITextBlockStatics3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ITextBlockStatics3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ITextBlockStatics3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ITextBox>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ITextBox;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ITextBox<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ITextBox2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ITextBox2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ITextBox2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ITextBox3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ITextBox3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ITextBox3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ITextBox4>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ITextBox4;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ITextBox4<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ITextBoxFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ITextBoxFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ITextBoxFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ITextBoxStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ITextBoxStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ITextBoxStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ITextBoxStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ITextBoxStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ITextBoxStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ITextBoxStatics3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ITextBoxStatics3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ITextBoxStatics3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ITextBoxTextChangingEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ITextBoxTextChangingEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ITextBoxTextChangingEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ITextChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ITextChangedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ITextChangedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ITextCompositionChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ITextCompositionChangedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ITextCompositionChangedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ITextCompositionEndedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ITextCompositionEndedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ITextCompositionEndedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ITextCompositionStartedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ITextCompositionStartedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ITextCompositionStartedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ITextControlPasteEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ITextControlPasteEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ITextControlPasteEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ITimePickedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ITimePickedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ITimePickedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ITimePicker>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ITimePicker;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ITimePicker<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ITimePicker2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ITimePicker2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ITimePicker2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ITimePickerFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ITimePickerFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ITimePickerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ITimePickerFlyout>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ITimePickerFlyout;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ITimePickerFlyout<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ITimePickerFlyoutPresenter>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ITimePickerFlyoutPresenter;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ITimePickerFlyoutPresenter<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ITimePickerFlyoutStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ITimePickerFlyoutStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ITimePickerFlyoutStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ITimePickerStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ITimePickerStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ITimePickerStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ITimePickerStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ITimePickerStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ITimePickerStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ITimePickerValueChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ITimePickerValueChangedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_ITimePickerValueChangedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IToggleMenuFlyoutItem>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IToggleMenuFlyoutItem;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IToggleMenuFlyoutItem<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IToggleMenuFlyoutItemFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IToggleMenuFlyoutItemFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IToggleMenuFlyoutItemFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IToggleMenuFlyoutItemStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IToggleMenuFlyoutItemStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IToggleMenuFlyoutItemStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IToggleSwitch>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IToggleSwitch;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IToggleSwitch<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IToggleSwitchOverrides>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IToggleSwitchOverrides;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IToggleSwitchOverrides<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IToggleSwitchStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IToggleSwitchStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IToggleSwitchStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IToolTip>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IToolTip;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IToolTip<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IToolTipFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IToolTipFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IToolTipFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IToolTipService>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IToolTipService;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IToolTipService<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IToolTipServiceStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IToolTipServiceStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IToolTipServiceStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IToolTipStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IToolTipStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IToolTipStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IUIElementCollection>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IUIElementCollection;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IUIElementCollection<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IUserControl>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IUserControl;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IUserControl<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IUserControlFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IUserControlFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IUserControlFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IUserControlStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IUserControlStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IUserControlStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IVariableSizedWrapGrid>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IVariableSizedWrapGrid;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IVariableSizedWrapGrid<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IVariableSizedWrapGridStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IVariableSizedWrapGridStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IVariableSizedWrapGridStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IViewbox>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IViewbox;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IViewbox<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IViewboxStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IViewboxStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IViewboxStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IVirtualizingPanel>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IVirtualizingPanel;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IVirtualizingPanel<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IVirtualizingPanelFactory>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IVirtualizingPanelFactory;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IVirtualizingPanelFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IVirtualizingPanelOverrides>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IVirtualizingPanelOverrides;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IVirtualizingPanelOverrides<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IVirtualizingPanelProtected>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IVirtualizingPanelProtected;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IVirtualizingPanelProtected<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IVirtualizingStackPanel>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IVirtualizingStackPanel;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IVirtualizingStackPanel<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IVirtualizingStackPanelOverrides>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IVirtualizingStackPanelOverrides;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IVirtualizingStackPanelOverrides<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IVirtualizingStackPanelStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IVirtualizingStackPanelStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IVirtualizingStackPanelStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IWebView>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IWebView;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IWebView<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IWebView2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IWebView2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IWebView2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IWebView3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IWebView3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IWebView3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IWebView4>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IWebView4;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IWebView4<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IWebView5>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IWebView5;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IWebView5<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IWebViewBrush>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IWebViewBrush;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IWebViewBrush<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IWebViewBrushStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IWebViewBrushStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IWebViewBrushStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IWebViewContentLoadingEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IWebViewContentLoadingEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IWebViewContentLoadingEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IWebViewDOMContentLoadedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IWebViewDOMContentLoadedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IWebViewDOMContentLoadedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IWebViewDeferredPermissionRequest>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IWebViewDeferredPermissionRequest;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IWebViewDeferredPermissionRequest<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IWebViewFactory4>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IWebViewFactory4;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IWebViewFactory4<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IWebViewLongRunningScriptDetectedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IWebViewLongRunningScriptDetectedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IWebViewLongRunningScriptDetectedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IWebViewNavigationCompletedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IWebViewNavigationCompletedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IWebViewNavigationCompletedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IWebViewNavigationFailedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IWebViewNavigationFailedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IWebViewNavigationFailedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IWebViewNavigationStartingEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IWebViewNavigationStartingEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IWebViewNavigationStartingEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IWebViewNewWindowRequestedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IWebViewNewWindowRequestedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IWebViewNewWindowRequestedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IWebViewPermissionRequest>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IWebViewPermissionRequest;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IWebViewPermissionRequest<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IWebViewPermissionRequestedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IWebViewPermissionRequestedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IWebViewPermissionRequestedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IWebViewSettings>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IWebViewSettings;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IWebViewSettings<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IWebViewStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IWebViewStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IWebViewStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IWebViewStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IWebViewStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IWebViewStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IWebViewStatics3>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IWebViewStatics3;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IWebViewStatics3<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IWebViewStatics4>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IWebViewStatics4;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IWebViewStatics4<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IWebViewStatics5>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IWebViewStatics5;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IWebViewStatics5<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IWebViewUnsupportedUriSchemeIdentifiedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IWebViewUnsupportedUriSchemeIdentifiedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IWebViewUnsupportedUriSchemeIdentifiedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IWebViewUnviewableContentIdentifiedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IWebViewUnviewableContentIdentifiedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IWebViewUnviewableContentIdentifiedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IWebViewUnviewableContentIdentifiedEventArgs2>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IWebViewUnviewableContentIdentifiedEventArgs2;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IWebViewUnviewableContentIdentifiedEventArgs2<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IWrapGrid>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IWrapGrid;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IWrapGrid<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::IWrapGridStatics>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IWrapGridStatics;
    template <typename D> using consume = Windows::UI::Xaml::Controls::impl_IWrapGridStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Controls::ItemClickEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ItemClickEventHandler;
};

template <> struct traits<Windows::UI::Xaml::Controls::ListViewItemToKeyHandler>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ListViewItemToKeyHandler;
};

template <> struct traits<Windows::UI::Xaml::Controls::ListViewKeyToItemHandler>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ListViewKeyToItemHandler;
};

template <> struct traits<Windows::UI::Xaml::Controls::NotifyEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::Controls::NotifyEventHandler;
};

template <> struct traits<Windows::UI::Xaml::Controls::SectionsInViewChangedEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::Controls::SectionsInViewChangedEventHandler;
};

template <> struct traits<Windows::UI::Xaml::Controls::SelectionChangedEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::Controls::SelectionChangedEventHandler;
};

template <> struct traits<Windows::UI::Xaml::Controls::SemanticZoomViewChangedEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::Controls::SemanticZoomViewChangedEventHandler;
};

template <> struct traits<Windows::UI::Xaml::Controls::TextChangedEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::Controls::TextChangedEventHandler;
};

template <> struct traits<Windows::UI::Xaml::Controls::TextControlPasteEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::Controls::TextControlPasteEventHandler;
};

template <> struct traits<Windows::UI::Xaml::Controls::WebViewNavigationFailedEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::Controls::WebViewNavigationFailedEventHandler;
};

template <> struct traits<Windows::UI::Xaml::Controls::AppBar>
{
    using abi = ABI::Windows::UI::Xaml::Controls::AppBar;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.AppBar"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::AppBarButton>
{
    using abi = ABI::Windows::UI::Xaml::Controls::AppBarButton;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.AppBarButton"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::AppBarSeparator>
{
    using abi = ABI::Windows::UI::Xaml::Controls::AppBarSeparator;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.AppBarSeparator"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::AppBarToggleButton>
{
    using abi = ABI::Windows::UI::Xaml::Controls::AppBarToggleButton;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.AppBarToggleButton"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::AutoSuggestBox>
{
    using abi = ABI::Windows::UI::Xaml::Controls::AutoSuggestBox;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.AutoSuggestBox"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::AutoSuggestBoxQuerySubmittedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::AutoSuggestBoxQuerySubmittedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.AutoSuggestBoxQuerySubmittedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::AutoSuggestBoxSuggestionChosenEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::AutoSuggestBoxSuggestionChosenEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.AutoSuggestBoxSuggestionChosenEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::AutoSuggestBoxTextChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::AutoSuggestBoxTextChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.AutoSuggestBoxTextChangedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::BackClickEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::BackClickEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.BackClickEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::BitmapIcon>
{
    using abi = ABI::Windows::UI::Xaml::Controls::BitmapIcon;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.BitmapIcon"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Border>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Border;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Border"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Button>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Button;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Button"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::CalendarDatePicker>
{
    using abi = ABI::Windows::UI::Xaml::Controls::CalendarDatePicker;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.CalendarDatePicker"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::CalendarDatePickerDateChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::CalendarDatePickerDateChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.CalendarDatePickerDateChangedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::CalendarView>
{
    using abi = ABI::Windows::UI::Xaml::Controls::CalendarView;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.CalendarView"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::CalendarViewDayItem>
{
    using abi = ABI::Windows::UI::Xaml::Controls::CalendarViewDayItem;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.CalendarViewDayItem"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::CalendarViewDayItemChangingEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::CalendarViewDayItemChangingEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.CalendarViewDayItemChangingEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::CalendarViewSelectedDatesChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::CalendarViewSelectedDatesChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.CalendarViewSelectedDatesChangedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::CandidateWindowBoundsChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::CandidateWindowBoundsChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.CandidateWindowBoundsChangedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Canvas>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Canvas;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Canvas"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::CaptureElement>
{
    using abi = ABI::Windows::UI::Xaml::Controls::CaptureElement;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.CaptureElement"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::CheckBox>
{
    using abi = ABI::Windows::UI::Xaml::Controls::CheckBox;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.CheckBox"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ChoosingGroupHeaderContainerEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ChoosingGroupHeaderContainerEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ChoosingGroupHeaderContainerEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ChoosingItemContainerEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ChoosingItemContainerEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ChoosingItemContainerEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::CleanUpVirtualizedItemEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::CleanUpVirtualizedItemEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.CleanUpVirtualizedItemEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ColumnDefinition>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ColumnDefinition;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ColumnDefinition"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ColumnDefinitionCollection>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ColumnDefinitionCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ColumnDefinitionCollection"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ComboBox>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ComboBox;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ComboBox"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ComboBoxItem>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ComboBoxItem;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ComboBoxItem"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::CommandBar>
{
    using abi = ABI::Windows::UI::Xaml::Controls::CommandBar;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.CommandBar"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::CommandBarOverflowPresenter>
{
    using abi = ABI::Windows::UI::Xaml::Controls::CommandBarOverflowPresenter;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.CommandBarOverflowPresenter"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ContainerContentChangingEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ContainerContentChangingEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ContainerContentChangingEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ContentControl>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ContentControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ContentControl"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ContentDialog>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ContentDialog;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ContentDialog"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ContentDialogButtonClickDeferral>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ContentDialogButtonClickDeferral;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ContentDialogButtonClickDeferral"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ContentDialogButtonClickEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ContentDialogButtonClickEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ContentDialogButtonClickEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ContentDialogClosedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ContentDialogClosedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ContentDialogClosedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ContentDialogClosingDeferral>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ContentDialogClosingDeferral;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ContentDialogClosingDeferral"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ContentDialogClosingEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ContentDialogClosingEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ContentDialogClosingEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ContentDialogOpenedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ContentDialogOpenedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ContentDialogOpenedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ContentPresenter>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ContentPresenter;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ContentPresenter"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ContextMenuEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ContextMenuEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ContextMenuEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Control>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Control;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Control"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ControlTemplate>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ControlTemplate;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ControlTemplate"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::DataTemplateSelector>
{
    using abi = ABI::Windows::UI::Xaml::Controls::DataTemplateSelector;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.DataTemplateSelector"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::DatePickedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::DatePickedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.DatePickedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::DatePicker>
{
    using abi = ABI::Windows::UI::Xaml::Controls::DatePicker;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.DatePicker"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::DatePickerFlyout>
{
    using abi = ABI::Windows::UI::Xaml::Controls::DatePickerFlyout;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.DatePickerFlyout"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::DatePickerFlyoutItem>
{
    using abi = ABI::Windows::UI::Xaml::Controls::DatePickerFlyoutItem;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.DatePickerFlyoutItem"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::DatePickerFlyoutPresenter>
{
    using abi = ABI::Windows::UI::Xaml::Controls::DatePickerFlyoutPresenter;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.DatePickerFlyoutPresenter"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::DatePickerValueChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::DatePickerValueChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.DatePickerValueChangedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::DragItemsCompletedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::DragItemsCompletedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.DragItemsCompletedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::DragItemsStartingEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::DragItemsStartingEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.DragItemsStartingEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::DynamicOverflowItemsChangingEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::DynamicOverflowItemsChangingEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.DynamicOverflowItemsChangingEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::FlipView>
{
    using abi = ABI::Windows::UI::Xaml::Controls::FlipView;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.FlipView"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::FlipViewItem>
{
    using abi = ABI::Windows::UI::Xaml::Controls::FlipViewItem;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.FlipViewItem"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Flyout>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Flyout;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Flyout"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::FlyoutPresenter>
{
    using abi = ABI::Windows::UI::Xaml::Controls::FlyoutPresenter;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.FlyoutPresenter"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::FocusDisengagedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::FocusDisengagedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.FocusDisengagedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::FocusEngagedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::FocusEngagedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.FocusEngagedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::FontIcon>
{
    using abi = ABI::Windows::UI::Xaml::Controls::FontIcon;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.FontIcon"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Frame>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Frame;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Frame"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Grid>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Grid;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Grid"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::GridView>
{
    using abi = ABI::Windows::UI::Xaml::Controls::GridView;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.GridView"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::GridViewHeaderItem>
{
    using abi = ABI::Windows::UI::Xaml::Controls::GridViewHeaderItem;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.GridViewHeaderItem"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::GridViewItem>
{
    using abi = ABI::Windows::UI::Xaml::Controls::GridViewItem;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.GridViewItem"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::GroupItem>
{
    using abi = ABI::Windows::UI::Xaml::Controls::GroupItem;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.GroupItem"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::GroupStyle>
{
    using abi = ABI::Windows::UI::Xaml::Controls::GroupStyle;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.GroupStyle"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::GroupStyleSelector>
{
    using abi = ABI::Windows::UI::Xaml::Controls::GroupStyleSelector;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.GroupStyleSelector"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Hub>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Hub;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Hub"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::HubSection>
{
    using abi = ABI::Windows::UI::Xaml::Controls::HubSection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.HubSection"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::HubSectionCollection>
{
    using abi = ABI::Windows::UI::Xaml::Controls::HubSectionCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.HubSectionCollection"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::HubSectionHeaderClickEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::HubSectionHeaderClickEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.HubSectionHeaderClickEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::HyperlinkButton>
{
    using abi = ABI::Windows::UI::Xaml::Controls::HyperlinkButton;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.HyperlinkButton"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::IconElement>
{
    using abi = ABI::Windows::UI::Xaml::Controls::IconElement;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.IconElement"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Image>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Image;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Image"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::InkCanvas>
{
    using abi = ABI::Windows::UI::Xaml::Controls::InkCanvas;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.InkCanvas"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::InkToolbar>
{
    using abi = ABI::Windows::UI::Xaml::Controls::InkToolbar;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.InkToolbar"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::InkToolbarBallpointPenButton>
{
    using abi = ABI::Windows::UI::Xaml::Controls::InkToolbarBallpointPenButton;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.InkToolbarBallpointPenButton"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::InkToolbarCustomPen>
{
    using abi = ABI::Windows::UI::Xaml::Controls::InkToolbarCustomPen;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.InkToolbarCustomPen"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::InkToolbarCustomPenButton>
{
    using abi = ABI::Windows::UI::Xaml::Controls::InkToolbarCustomPenButton;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.InkToolbarCustomPenButton"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::InkToolbarCustomToggleButton>
{
    using abi = ABI::Windows::UI::Xaml::Controls::InkToolbarCustomToggleButton;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.InkToolbarCustomToggleButton"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::InkToolbarCustomToolButton>
{
    using abi = ABI::Windows::UI::Xaml::Controls::InkToolbarCustomToolButton;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.InkToolbarCustomToolButton"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::InkToolbarEraserButton>
{
    using abi = ABI::Windows::UI::Xaml::Controls::InkToolbarEraserButton;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.InkToolbarEraserButton"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::InkToolbarHighlighterButton>
{
    using abi = ABI::Windows::UI::Xaml::Controls::InkToolbarHighlighterButton;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.InkToolbarHighlighterButton"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::InkToolbarPenButton>
{
    using abi = ABI::Windows::UI::Xaml::Controls::InkToolbarPenButton;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.InkToolbarPenButton"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::InkToolbarPenConfigurationControl>
{
    using abi = ABI::Windows::UI::Xaml::Controls::InkToolbarPenConfigurationControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.InkToolbarPenConfigurationControl"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::InkToolbarPencilButton>
{
    using abi = ABI::Windows::UI::Xaml::Controls::InkToolbarPencilButton;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.InkToolbarPencilButton"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::InkToolbarRulerButton>
{
    using abi = ABI::Windows::UI::Xaml::Controls::InkToolbarRulerButton;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.InkToolbarRulerButton"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::InkToolbarToggleButton>
{
    using abi = ABI::Windows::UI::Xaml::Controls::InkToolbarToggleButton;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.InkToolbarToggleButton"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::InkToolbarToolButton>
{
    using abi = ABI::Windows::UI::Xaml::Controls::InkToolbarToolButton;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.InkToolbarToolButton"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ItemClickEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ItemClickEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ItemClickEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ItemCollection>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ItemCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ItemCollection"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ItemContainerGenerator>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ItemContainerGenerator;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ItemContainerGenerator"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ItemsControl>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ItemsControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ItemsControl"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ItemsPanelTemplate>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ItemsPanelTemplate;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ItemsPanelTemplate"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ItemsPickedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ItemsPickedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ItemsPickedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ItemsPresenter>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ItemsPresenter;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ItemsPresenter"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ItemsStackPanel>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ItemsStackPanel;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ItemsStackPanel"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ItemsWrapGrid>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ItemsWrapGrid;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ItemsWrapGrid"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ListBox>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ListBox;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ListBox"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ListBoxItem>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ListBoxItem;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ListBoxItem"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ListPickerFlyout>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ListPickerFlyout;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ListPickerFlyout"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ListPickerFlyoutPresenter>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ListPickerFlyoutPresenter;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ListPickerFlyoutPresenter"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ListView>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ListView;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ListView"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ListViewBase>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ListViewBase;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ListViewBase"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ListViewBaseHeaderItem>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ListViewBaseHeaderItem;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ListViewBaseHeaderItem"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ListViewHeaderItem>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ListViewHeaderItem;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ListViewHeaderItem"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ListViewItem>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ListViewItem;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ListViewItem"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ListViewPersistenceHelper>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ListViewPersistenceHelper;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ListViewPersistenceHelper"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::MediaElement>
{
    using abi = ABI::Windows::UI::Xaml::Controls::MediaElement;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.MediaElement"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::MediaPlayerElement>
{
    using abi = ABI::Windows::UI::Xaml::Controls::MediaPlayerElement;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.MediaPlayerElement"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::MediaPlayerPresenter>
{
    using abi = ABI::Windows::UI::Xaml::Controls::MediaPlayerPresenter;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.MediaPlayerPresenter"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::MediaTransportControls>
{
    using abi = ABI::Windows::UI::Xaml::Controls::MediaTransportControls;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.MediaTransportControls"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::MediaTransportControlsHelper>
{
    using abi = ABI::Windows::UI::Xaml::Controls::MediaTransportControlsHelper;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.MediaTransportControlsHelper"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::MenuFlyout>
{
    using abi = ABI::Windows::UI::Xaml::Controls::MenuFlyout;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.MenuFlyout"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::MenuFlyoutItem>
{
    using abi = ABI::Windows::UI::Xaml::Controls::MenuFlyoutItem;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.MenuFlyoutItem"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::MenuFlyoutItemBase>
{
    using abi = ABI::Windows::UI::Xaml::Controls::MenuFlyoutItemBase;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.MenuFlyoutItemBase"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::MenuFlyoutPresenter>
{
    using abi = ABI::Windows::UI::Xaml::Controls::MenuFlyoutPresenter;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.MenuFlyoutPresenter"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::MenuFlyoutSeparator>
{
    using abi = ABI::Windows::UI::Xaml::Controls::MenuFlyoutSeparator;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.MenuFlyoutSeparator"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::MenuFlyoutSubItem>
{
    using abi = ABI::Windows::UI::Xaml::Controls::MenuFlyoutSubItem;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.MenuFlyoutSubItem"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::NotifyEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::NotifyEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.NotifyEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Page>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Page;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Page"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Panel>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Panel;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Panel"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::PasswordBox>
{
    using abi = ABI::Windows::UI::Xaml::Controls::PasswordBox;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.PasswordBox"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::PathIcon>
{
    using abi = ABI::Windows::UI::Xaml::Controls::PathIcon;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.PathIcon"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::PickerConfirmedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::PickerConfirmedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.PickerConfirmedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::PickerFlyout>
{
    using abi = ABI::Windows::UI::Xaml::Controls::PickerFlyout;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.PickerFlyout"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::PickerFlyoutPresenter>
{
    using abi = ABI::Windows::UI::Xaml::Controls::PickerFlyoutPresenter;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.PickerFlyoutPresenter"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Pivot>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Pivot;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Pivot"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::PivotItem>
{
    using abi = ABI::Windows::UI::Xaml::Controls::PivotItem;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.PivotItem"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::PivotItemEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::PivotItemEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.PivotItemEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ProgressBar>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ProgressBar;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ProgressBar"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ProgressRing>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ProgressRing;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ProgressRing"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::RadioButton>
{
    using abi = ABI::Windows::UI::Xaml::Controls::RadioButton;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.RadioButton"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::RelativePanel>
{
    using abi = ABI::Windows::UI::Xaml::Controls::RelativePanel;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.RelativePanel"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::RichEditBox>
{
    using abi = ABI::Windows::UI::Xaml::Controls::RichEditBox;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.RichEditBox"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::RichEditBoxTextChangingEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::RichEditBoxTextChangingEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.RichEditBoxTextChangingEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::RichTextBlock>
{
    using abi = ABI::Windows::UI::Xaml::Controls::RichTextBlock;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.RichTextBlock"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::RichTextBlockOverflow>
{
    using abi = ABI::Windows::UI::Xaml::Controls::RichTextBlockOverflow;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.RichTextBlockOverflow"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::RowDefinition>
{
    using abi = ABI::Windows::UI::Xaml::Controls::RowDefinition;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.RowDefinition"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::RowDefinitionCollection>
{
    using abi = ABI::Windows::UI::Xaml::Controls::RowDefinitionCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.RowDefinitionCollection"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ScrollContentPresenter>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ScrollContentPresenter;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ScrollContentPresenter"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ScrollViewer>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ScrollViewer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ScrollViewer"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ScrollViewerView>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ScrollViewerView;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ScrollViewerView"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ScrollViewerViewChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ScrollViewerViewChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ScrollViewerViewChangedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ScrollViewerViewChangingEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ScrollViewerViewChangingEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ScrollViewerViewChangingEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::SearchBox>
{
    using abi = ABI::Windows::UI::Xaml::Controls::SearchBox;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.SearchBox"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::SearchBoxQueryChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::SearchBoxQueryChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.SearchBoxQueryChangedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::SearchBoxQuerySubmittedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::SearchBoxQuerySubmittedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.SearchBoxQuerySubmittedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::SearchBoxResultSuggestionChosenEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::SearchBoxResultSuggestionChosenEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.SearchBoxResultSuggestionChosenEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::SearchBoxSuggestionsRequestedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::SearchBoxSuggestionsRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.SearchBoxSuggestionsRequestedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::SectionsInViewChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::SectionsInViewChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.SectionsInViewChangedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::SelectionChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::SelectionChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.SelectionChangedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::SemanticZoom>
{
    using abi = ABI::Windows::UI::Xaml::Controls::SemanticZoom;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.SemanticZoom"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::SemanticZoomLocation>
{
    using abi = ABI::Windows::UI::Xaml::Controls::SemanticZoomLocation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.SemanticZoomLocation"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::SemanticZoomViewChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::SemanticZoomViewChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.SemanticZoomViewChangedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::SettingsFlyout>
{
    using abi = ABI::Windows::UI::Xaml::Controls::SettingsFlyout;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.SettingsFlyout"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Slider>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Slider;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Slider"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::SplitView>
{
    using abi = ABI::Windows::UI::Xaml::Controls::SplitView;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.SplitView"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::SplitViewPaneClosingEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::SplitViewPaneClosingEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.SplitViewPaneClosingEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::StackPanel>
{
    using abi = ABI::Windows::UI::Xaml::Controls::StackPanel;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.StackPanel"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::StyleSelector>
{
    using abi = ABI::Windows::UI::Xaml::Controls::StyleSelector;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.StyleSelector"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::SwapChainBackgroundPanel>
{
    using abi = ABI::Windows::UI::Xaml::Controls::SwapChainBackgroundPanel;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.SwapChainBackgroundPanel"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::SwapChainPanel>
{
    using abi = ABI::Windows::UI::Xaml::Controls::SwapChainPanel;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.SwapChainPanel"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::SymbolIcon>
{
    using abi = ABI::Windows::UI::Xaml::Controls::SymbolIcon;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.SymbolIcon"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::TextBlock>
{
    using abi = ABI::Windows::UI::Xaml::Controls::TextBlock;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.TextBlock"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::TextBox>
{
    using abi = ABI::Windows::UI::Xaml::Controls::TextBox;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.TextBox"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::TextBoxTextChangingEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::TextBoxTextChangingEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.TextBoxTextChangingEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::TextChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::TextChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.TextChangedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::TextCompositionChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::TextCompositionChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.TextCompositionChangedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::TextCompositionEndedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::TextCompositionEndedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.TextCompositionEndedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::TextCompositionStartedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::TextCompositionStartedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.TextCompositionStartedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::TextControlPasteEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::TextControlPasteEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.TextControlPasteEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::TimePickedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::TimePickedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.TimePickedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::TimePicker>
{
    using abi = ABI::Windows::UI::Xaml::Controls::TimePicker;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.TimePicker"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::TimePickerFlyout>
{
    using abi = ABI::Windows::UI::Xaml::Controls::TimePickerFlyout;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.TimePickerFlyout"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::TimePickerFlyoutPresenter>
{
    using abi = ABI::Windows::UI::Xaml::Controls::TimePickerFlyoutPresenter;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.TimePickerFlyoutPresenter"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::TimePickerValueChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::TimePickerValueChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.TimePickerValueChangedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ToggleMenuFlyoutItem>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ToggleMenuFlyoutItem;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ToggleMenuFlyoutItem"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ToggleSwitch>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ToggleSwitch;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ToggleSwitch"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ToolTip>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ToolTip;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ToolTip"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::ToolTipService>
{
    using abi = ABI::Windows::UI::Xaml::Controls::ToolTipService;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.ToolTipService"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::UIElementCollection>
{
    using abi = ABI::Windows::UI::Xaml::Controls::UIElementCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.UIElementCollection"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::UserControl>
{
    using abi = ABI::Windows::UI::Xaml::Controls::UserControl;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.UserControl"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::VariableSizedWrapGrid>
{
    using abi = ABI::Windows::UI::Xaml::Controls::VariableSizedWrapGrid;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.VariableSizedWrapGrid"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::Viewbox>
{
    using abi = ABI::Windows::UI::Xaml::Controls::Viewbox;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.Viewbox"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::VirtualizingPanel>
{
    using abi = ABI::Windows::UI::Xaml::Controls::VirtualizingPanel;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.VirtualizingPanel"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::VirtualizingStackPanel>
{
    using abi = ABI::Windows::UI::Xaml::Controls::VirtualizingStackPanel;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.VirtualizingStackPanel"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::WebView>
{
    using abi = ABI::Windows::UI::Xaml::Controls::WebView;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.WebView"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::WebViewBrush>
{
    using abi = ABI::Windows::UI::Xaml::Controls::WebViewBrush;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.WebViewBrush"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::WebViewContentLoadingEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::WebViewContentLoadingEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.WebViewContentLoadingEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::WebViewDOMContentLoadedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::WebViewDOMContentLoadedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.WebViewDOMContentLoadedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::WebViewDeferredPermissionRequest>
{
    using abi = ABI::Windows::UI::Xaml::Controls::WebViewDeferredPermissionRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.WebViewDeferredPermissionRequest"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::WebViewLongRunningScriptDetectedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::WebViewLongRunningScriptDetectedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.WebViewLongRunningScriptDetectedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::WebViewNavigationCompletedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::WebViewNavigationCompletedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.WebViewNavigationCompletedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::WebViewNavigationFailedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::WebViewNavigationFailedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.WebViewNavigationFailedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::WebViewNavigationStartingEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::WebViewNavigationStartingEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.WebViewNavigationStartingEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::WebViewNewWindowRequestedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::WebViewNewWindowRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.WebViewNewWindowRequestedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::WebViewPermissionRequest>
{
    using abi = ABI::Windows::UI::Xaml::Controls::WebViewPermissionRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.WebViewPermissionRequest"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::WebViewPermissionRequestedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::WebViewPermissionRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.WebViewPermissionRequestedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::WebViewSettings>
{
    using abi = ABI::Windows::UI::Xaml::Controls::WebViewSettings;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.WebViewSettings"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::WebViewUnsupportedUriSchemeIdentifiedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::WebViewUnsupportedUriSchemeIdentifiedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.WebViewUnsupportedUriSchemeIdentifiedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::WebViewUnviewableContentIdentifiedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Controls::WebViewUnviewableContentIdentifiedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.WebViewUnviewableContentIdentifiedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Controls::WrapGrid>
{
    using abi = ABI::Windows::UI::Xaml::Controls::WrapGrid;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Controls.WrapGrid"; }
};

}

}
