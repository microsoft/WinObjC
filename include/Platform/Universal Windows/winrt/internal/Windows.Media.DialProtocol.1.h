// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Media.DialProtocol.0.h"
#include "Windows.Devices.Enumeration.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.UI.Popups.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::DialProtocol {

struct __declspec(uuid("555ffbd3-45b7-49f3-bbd7-302db6084646")) __declspec(novtable) IDialApp : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AppName(hstring * value) = 0;
    virtual HRESULT __stdcall abi_RequestLaunchAsync(hstring appArgument, Windows::Foundation::IAsyncOperation<winrt::Windows::Media::DialProtocol::DialAppLaunchResult> ** value) = 0;
    virtual HRESULT __stdcall abi_StopAsync(Windows::Foundation::IAsyncOperation<winrt::Windows::Media::DialProtocol::DialAppStopResult> ** value) = 0;
    virtual HRESULT __stdcall abi_GetAppStateAsync(Windows::Foundation::IAsyncOperation<Windows::Media::DialProtocol::DialAppStateDetails> ** value) = 0;
};

struct __declspec(uuid("ddc4a4a1-f5de-400d-bea4-8c8466bb2961")) __declspec(novtable) IDialAppStateDetails : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_State(winrt::Windows::Media::DialProtocol::DialAppState * value) = 0;
    virtual HRESULT __stdcall get_FullXml(hstring * value) = 0;
};

struct __declspec(uuid("fff0edaf-759f-41d2-a20a-7f29ce0b3784")) __declspec(novtable) IDialDevice : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall abi_GetDialApp(hstring appName, Windows::Media::DialProtocol::IDialApp ** value) = 0;
};

struct __declspec(uuid("bab7f3d5-5bfb-4eba-8b32-b57c5c5ee5c9")) __declspec(novtable) IDialDevice2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FriendlyName(hstring * value) = 0;
    virtual HRESULT __stdcall get_Thumbnail(Windows::Storage::Streams::IRandomAccessStreamReference ** value) = 0;
};

struct __declspec(uuid("ba7e520a-ff59-4f4b-bdac-d89f495ad6e1")) __declspec(novtable) IDialDevicePicker : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Filter(Windows::Media::DialProtocol::IDialDevicePickerFilter ** value) = 0;
    virtual HRESULT __stdcall get_Appearance(Windows::Devices::Enumeration::IDevicePickerAppearance ** value) = 0;
    virtual HRESULT __stdcall add_DialDeviceSelected(Windows::Foundation::TypedEventHandler<Windows::Media::DialProtocol::DialDevicePicker, Windows::Media::DialProtocol::DialDeviceSelectedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DialDeviceSelected(event_token token) = 0;
    virtual HRESULT __stdcall add_DisconnectButtonClicked(Windows::Foundation::TypedEventHandler<Windows::Media::DialProtocol::DialDevicePicker, Windows::Media::DialProtocol::DialDisconnectButtonClickedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DisconnectButtonClicked(event_token token) = 0;
    virtual HRESULT __stdcall add_DialDevicePickerDismissed(Windows::Foundation::TypedEventHandler<Windows::Media::DialProtocol::DialDevicePicker, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DialDevicePickerDismissed(event_token token) = 0;
    virtual HRESULT __stdcall abi_Show(Windows::Foundation::Rect selection) = 0;
    virtual HRESULT __stdcall abi_ShowWithPlacement(Windows::Foundation::Rect selection, winrt::Windows::UI::Popups::Placement preferredPlacement) = 0;
    virtual HRESULT __stdcall abi_PickSingleDialDeviceAsync(Windows::Foundation::Rect selection, Windows::Foundation::IAsyncOperation<Windows::Media::DialProtocol::DialDevice> ** operation) = 0;
    virtual HRESULT __stdcall abi_PickSingleDialDeviceAsyncWithPlacement(Windows::Foundation::Rect selection, winrt::Windows::UI::Popups::Placement preferredPlacement, Windows::Foundation::IAsyncOperation<Windows::Media::DialProtocol::DialDevice> ** operation) = 0;
    virtual HRESULT __stdcall abi_Hide() = 0;
    virtual HRESULT __stdcall abi_SetDisplayStatus(Windows::Media::DialProtocol::IDialDevice * device, winrt::Windows::Media::DialProtocol::DialDeviceDisplayStatus status) = 0;
};

struct __declspec(uuid("c17c93ba-86c0-485d-b8d6-0f9a8f641590")) __declspec(novtable) IDialDevicePickerFilter : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SupportedAppNames(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
};

struct __declspec(uuid("480b92ad-ac76-47eb-9c06-a19304da0247")) __declspec(novtable) IDialDeviceSelectedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SelectedDialDevice(Windows::Media::DialProtocol::IDialDevice ** value) = 0;
};

struct __declspec(uuid("aa69cc95-01f8-4758-8461-2bbd1cdc3cf3")) __declspec(novtable) IDialDeviceStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDeviceSelector(hstring appName, hstring * selector) = 0;
    virtual HRESULT __stdcall abi_FromIdAsync(hstring value, Windows::Foundation::IAsyncOperation<Windows::Media::DialProtocol::DialDevice> ** operation) = 0;
    virtual HRESULT __stdcall abi_DeviceInfoSupportsDialAsync(Windows::Devices::Enumeration::IDeviceInformation * device, Windows::Foundation::IAsyncOperation<bool> ** operation) = 0;
};

struct __declspec(uuid("52765152-9c81-4e55-adc2-0ebe99cde3b6")) __declspec(novtable) IDialDisconnectButtonClickedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Device(Windows::Media::DialProtocol::IDialDevice ** value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Media::DialProtocol::DialApp> { using default_interface = Windows::Media::DialProtocol::IDialApp; };
template <> struct traits<Windows::Media::DialProtocol::DialAppStateDetails> { using default_interface = Windows::Media::DialProtocol::IDialAppStateDetails; };
template <> struct traits<Windows::Media::DialProtocol::DialDevice> { using default_interface = Windows::Media::DialProtocol::IDialDevice; };
template <> struct traits<Windows::Media::DialProtocol::DialDevicePicker> { using default_interface = Windows::Media::DialProtocol::IDialDevicePicker; };
template <> struct traits<Windows::Media::DialProtocol::DialDevicePickerFilter> { using default_interface = Windows::Media::DialProtocol::IDialDevicePickerFilter; };
template <> struct traits<Windows::Media::DialProtocol::DialDeviceSelectedEventArgs> { using default_interface = Windows::Media::DialProtocol::IDialDeviceSelectedEventArgs; };
template <> struct traits<Windows::Media::DialProtocol::DialDisconnectButtonClickedEventArgs> { using default_interface = Windows::Media::DialProtocol::IDialDisconnectButtonClickedEventArgs; };

}

namespace Windows::Media::DialProtocol {

template <typename D>
struct WINRT_EBO impl_IDialApp
{
    hstring AppName() const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Media::DialProtocol::DialAppLaunchResult> RequestLaunchAsync(hstring_view appArgument) const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Media::DialProtocol::DialAppStopResult> StopAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Media::DialProtocol::DialAppStateDetails> GetAppStateAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IDialAppStateDetails
{
    Windows::Media::DialProtocol::DialAppState State() const;
    hstring FullXml() const;
};

template <typename D>
struct WINRT_EBO impl_IDialDevice
{
    hstring Id() const;
    Windows::Media::DialProtocol::DialApp GetDialApp(hstring_view appName) const;
};

template <typename D>
struct WINRT_EBO impl_IDialDevice2
{
    hstring FriendlyName() const;
    Windows::Storage::Streams::IRandomAccessStreamReference Thumbnail() const;
};

template <typename D>
struct WINRT_EBO impl_IDialDevicePicker
{
    Windows::Media::DialProtocol::DialDevicePickerFilter Filter() const;
    Windows::Devices::Enumeration::DevicePickerAppearance Appearance() const;
    event_token DialDeviceSelected(const Windows::Foundation::TypedEventHandler<Windows::Media::DialProtocol::DialDevicePicker, Windows::Media::DialProtocol::DialDeviceSelectedEventArgs> & handler) const;
    using DialDeviceSelected_revoker = event_revoker<IDialDevicePicker>;
    DialDeviceSelected_revoker DialDeviceSelected(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::DialProtocol::DialDevicePicker, Windows::Media::DialProtocol::DialDeviceSelectedEventArgs> & handler) const;
    void DialDeviceSelected(event_token token) const;
    event_token DisconnectButtonClicked(const Windows::Foundation::TypedEventHandler<Windows::Media::DialProtocol::DialDevicePicker, Windows::Media::DialProtocol::DialDisconnectButtonClickedEventArgs> & handler) const;
    using DisconnectButtonClicked_revoker = event_revoker<IDialDevicePicker>;
    DisconnectButtonClicked_revoker DisconnectButtonClicked(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::DialProtocol::DialDevicePicker, Windows::Media::DialProtocol::DialDisconnectButtonClickedEventArgs> & handler) const;
    void DisconnectButtonClicked(event_token token) const;
    event_token DialDevicePickerDismissed(const Windows::Foundation::TypedEventHandler<Windows::Media::DialProtocol::DialDevicePicker, Windows::Foundation::IInspectable> & handler) const;
    using DialDevicePickerDismissed_revoker = event_revoker<IDialDevicePicker>;
    DialDevicePickerDismissed_revoker DialDevicePickerDismissed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::DialProtocol::DialDevicePicker, Windows::Foundation::IInspectable> & handler) const;
    void DialDevicePickerDismissed(event_token token) const;
    void Show(const Windows::Foundation::Rect & selection) const;
    void Show(const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement) const;
    Windows::Foundation::IAsyncOperation<Windows::Media::DialProtocol::DialDevice> PickSingleDialDeviceAsync(const Windows::Foundation::Rect & selection) const;
    Windows::Foundation::IAsyncOperation<Windows::Media::DialProtocol::DialDevice> PickSingleDialDeviceAsync(const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement) const;
    void Hide() const;
    void SetDisplayStatus(const Windows::Media::DialProtocol::DialDevice & device, Windows::Media::DialProtocol::DialDeviceDisplayStatus status) const;
};

template <typename D>
struct WINRT_EBO impl_IDialDevicePickerFilter
{
    Windows::Foundation::Collections::IVector<hstring> SupportedAppNames() const;
};

template <typename D>
struct WINRT_EBO impl_IDialDeviceSelectedEventArgs
{
    Windows::Media::DialProtocol::DialDevice SelectedDialDevice() const;
};

template <typename D>
struct WINRT_EBO impl_IDialDeviceStatics
{
    hstring GetDeviceSelector(hstring_view appName) const;
    Windows::Foundation::IAsyncOperation<Windows::Media::DialProtocol::DialDevice> FromIdAsync(hstring_view value) const;
    Windows::Foundation::IAsyncOperation<bool> DeviceInfoSupportsDialAsync(const Windows::Devices::Enumeration::DeviceInformation & device) const;
};

template <typename D>
struct WINRT_EBO impl_IDialDisconnectButtonClickedEventArgs
{
    Windows::Media::DialProtocol::DialDevice Device() const;
};

}

namespace impl {

template <> struct traits<Windows::Media::DialProtocol::IDialApp>
{
    using abi = ABI::Windows::Media::DialProtocol::IDialApp;
    template <typename D> using consume = Windows::Media::DialProtocol::impl_IDialApp<D>;
};

template <> struct traits<Windows::Media::DialProtocol::IDialAppStateDetails>
{
    using abi = ABI::Windows::Media::DialProtocol::IDialAppStateDetails;
    template <typename D> using consume = Windows::Media::DialProtocol::impl_IDialAppStateDetails<D>;
};

template <> struct traits<Windows::Media::DialProtocol::IDialDevice>
{
    using abi = ABI::Windows::Media::DialProtocol::IDialDevice;
    template <typename D> using consume = Windows::Media::DialProtocol::impl_IDialDevice<D>;
};

template <> struct traits<Windows::Media::DialProtocol::IDialDevice2>
{
    using abi = ABI::Windows::Media::DialProtocol::IDialDevice2;
    template <typename D> using consume = Windows::Media::DialProtocol::impl_IDialDevice2<D>;
};

template <> struct traits<Windows::Media::DialProtocol::IDialDevicePicker>
{
    using abi = ABI::Windows::Media::DialProtocol::IDialDevicePicker;
    template <typename D> using consume = Windows::Media::DialProtocol::impl_IDialDevicePicker<D>;
};

template <> struct traits<Windows::Media::DialProtocol::IDialDevicePickerFilter>
{
    using abi = ABI::Windows::Media::DialProtocol::IDialDevicePickerFilter;
    template <typename D> using consume = Windows::Media::DialProtocol::impl_IDialDevicePickerFilter<D>;
};

template <> struct traits<Windows::Media::DialProtocol::IDialDeviceSelectedEventArgs>
{
    using abi = ABI::Windows::Media::DialProtocol::IDialDeviceSelectedEventArgs;
    template <typename D> using consume = Windows::Media::DialProtocol::impl_IDialDeviceSelectedEventArgs<D>;
};

template <> struct traits<Windows::Media::DialProtocol::IDialDeviceStatics>
{
    using abi = ABI::Windows::Media::DialProtocol::IDialDeviceStatics;
    template <typename D> using consume = Windows::Media::DialProtocol::impl_IDialDeviceStatics<D>;
};

template <> struct traits<Windows::Media::DialProtocol::IDialDisconnectButtonClickedEventArgs>
{
    using abi = ABI::Windows::Media::DialProtocol::IDialDisconnectButtonClickedEventArgs;
    template <typename D> using consume = Windows::Media::DialProtocol::impl_IDialDisconnectButtonClickedEventArgs<D>;
};

template <> struct traits<Windows::Media::DialProtocol::DialApp>
{
    using abi = ABI::Windows::Media::DialProtocol::DialApp;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.DialProtocol.DialApp"; }
};

template <> struct traits<Windows::Media::DialProtocol::DialAppStateDetails>
{
    using abi = ABI::Windows::Media::DialProtocol::DialAppStateDetails;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.DialProtocol.DialAppStateDetails"; }
};

template <> struct traits<Windows::Media::DialProtocol::DialDevice>
{
    using abi = ABI::Windows::Media::DialProtocol::DialDevice;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.DialProtocol.DialDevice"; }
};

template <> struct traits<Windows::Media::DialProtocol::DialDevicePicker>
{
    using abi = ABI::Windows::Media::DialProtocol::DialDevicePicker;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.DialProtocol.DialDevicePicker"; }
};

template <> struct traits<Windows::Media::DialProtocol::DialDevicePickerFilter>
{
    using abi = ABI::Windows::Media::DialProtocol::DialDevicePickerFilter;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.DialProtocol.DialDevicePickerFilter"; }
};

template <> struct traits<Windows::Media::DialProtocol::DialDeviceSelectedEventArgs>
{
    using abi = ABI::Windows::Media::DialProtocol::DialDeviceSelectedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.DialProtocol.DialDeviceSelectedEventArgs"; }
};

template <> struct traits<Windows::Media::DialProtocol::DialDisconnectButtonClickedEventArgs>
{
    using abi = ABI::Windows::Media::DialProtocol::DialDisconnectButtonClickedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.DialProtocol.DialDisconnectButtonClickedEventArgs"; }
};

}

}
