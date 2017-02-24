// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Devices.Enumeration.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.UI.Popups.3.h"
#include "internal/Windows.Media.DialProtocol.3.h"
#include "Windows.Media.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Media::DialProtocol::IDialApp> : produce_base<D, Windows::Media::DialProtocol::IDialApp>
{
    HRESULT __stdcall get_AppName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AppName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestLaunchAsync(impl::abi_arg_in<hstring> appArgument, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Media::DialProtocol::DialAppLaunchResult>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequestLaunchAsync(*reinterpret_cast<const hstring *>(&appArgument)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StopAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Media::DialProtocol::DialAppStopResult>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StopAsync());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAppStateAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::DialProtocol::DialAppStateDetails>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetAppStateAsync());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::DialProtocol::IDialAppStateDetails> : produce_base<D, Windows::Media::DialProtocol::IDialAppStateDetails>
{
    HRESULT __stdcall get_State(Windows::Media::DialProtocol::DialAppState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().State());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FullXml(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FullXml());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::DialProtocol::IDialDevice> : produce_base<D, Windows::Media::DialProtocol::IDialDevice>
{
    HRESULT __stdcall get_Id(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDialApp(impl::abi_arg_in<hstring> appName, impl::abi_arg_out<Windows::Media::DialProtocol::IDialApp> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDialApp(*reinterpret_cast<const hstring *>(&appName)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::DialProtocol::IDialDevice2> : produce_base<D, Windows::Media::DialProtocol::IDialDevice2>
{
    HRESULT __stdcall get_FriendlyName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FriendlyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Thumbnail(impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Thumbnail());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::DialProtocol::IDialDevicePicker> : produce_base<D, Windows::Media::DialProtocol::IDialDevicePicker>
{
    HRESULT __stdcall get_Filter(impl::abi_arg_out<Windows::Media::DialProtocol::IDialDevicePickerFilter> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Filter());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Appearance(impl::abi_arg_out<Windows::Devices::Enumeration::IDevicePickerAppearance> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Appearance());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_DialDeviceSelected(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::DialProtocol::DialDevicePicker, Windows::Media::DialProtocol::DialDeviceSelectedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().DialDeviceSelected(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::DialProtocol::DialDevicePicker, Windows::Media::DialProtocol::DialDeviceSelectedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DialDeviceSelected(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DialDeviceSelected(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_DisconnectButtonClicked(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::DialProtocol::DialDevicePicker, Windows::Media::DialProtocol::DialDisconnectButtonClickedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().DisconnectButtonClicked(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::DialProtocol::DialDevicePicker, Windows::Media::DialProtocol::DialDisconnectButtonClickedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DisconnectButtonClicked(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisconnectButtonClicked(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_DialDevicePickerDismissed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::DialProtocol::DialDevicePicker, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().DialDevicePickerDismissed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::DialProtocol::DialDevicePicker, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DialDevicePickerDismissed(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DialDevicePickerDismissed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Show(impl::abi_arg_in<Windows::Foundation::Rect> selection) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Show(*reinterpret_cast<const Windows::Foundation::Rect *>(&selection));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowWithPlacement(impl::abi_arg_in<Windows::Foundation::Rect> selection, Windows::UI::Popups::Placement preferredPlacement) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Show(*reinterpret_cast<const Windows::Foundation::Rect *>(&selection), preferredPlacement);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PickSingleDialDeviceAsync(impl::abi_arg_in<Windows::Foundation::Rect> selection, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::DialProtocol::DialDevice>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().PickSingleDialDeviceAsync(*reinterpret_cast<const Windows::Foundation::Rect *>(&selection)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PickSingleDialDeviceAsyncWithPlacement(impl::abi_arg_in<Windows::Foundation::Rect> selection, Windows::UI::Popups::Placement preferredPlacement, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::DialProtocol::DialDevice>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().PickSingleDialDeviceAsync(*reinterpret_cast<const Windows::Foundation::Rect *>(&selection), preferredPlacement));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Hide() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Hide();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetDisplayStatus(impl::abi_arg_in<Windows::Media::DialProtocol::IDialDevice> device, Windows::Media::DialProtocol::DialDeviceDisplayStatus status) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetDisplayStatus(*reinterpret_cast<const Windows::Media::DialProtocol::DialDevice *>(&device), status);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::DialProtocol::IDialDevicePickerFilter> : produce_base<D, Windows::Media::DialProtocol::IDialDevicePickerFilter>
{
    HRESULT __stdcall get_SupportedAppNames(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportedAppNames());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::DialProtocol::IDialDeviceSelectedEventArgs> : produce_base<D, Windows::Media::DialProtocol::IDialDeviceSelectedEventArgs>
{
    HRESULT __stdcall get_SelectedDialDevice(impl::abi_arg_out<Windows::Media::DialProtocol::IDialDevice> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SelectedDialDevice());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::DialProtocol::IDialDeviceStatics> : produce_base<D, Windows::Media::DialProtocol::IDialDeviceStatics>
{
    HRESULT __stdcall abi_GetDeviceSelector(impl::abi_arg_in<hstring> appName, impl::abi_arg_out<hstring> selector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *selector = detach_abi(this->shim().GetDeviceSelector(*reinterpret_cast<const hstring *>(&appName)));
            return S_OK;
        }
        catch (...)
        {
            *selector = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromIdAsync(impl::abi_arg_in<hstring> value, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::DialProtocol::DialDevice>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FromIdAsync(*reinterpret_cast<const hstring *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeviceInfoSupportsDialAsync(impl::abi_arg_in<Windows::Devices::Enumeration::IDeviceInformation> device, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().DeviceInfoSupportsDialAsync(*reinterpret_cast<const Windows::Devices::Enumeration::DeviceInformation *>(&device)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::DialProtocol::IDialDisconnectButtonClickedEventArgs> : produce_base<D, Windows::Media::DialProtocol::IDialDisconnectButtonClickedEventArgs>
{
    HRESULT __stdcall get_Device(impl::abi_arg_out<Windows::Media::DialProtocol::IDialDevice> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Device());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Media::DialProtocol {

template <typename D> Windows::Media::DialProtocol::DialAppState impl_IDialAppStateDetails<D>::State() const
{
    Windows::Media::DialProtocol::DialAppState value {};
    check_hresult(WINRT_SHIM(IDialAppStateDetails)->get_State(&value));
    return value;
}

template <typename D> hstring impl_IDialAppStateDetails<D>::FullXml() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDialAppStateDetails)->get_FullXml(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IDialApp<D>::AppName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDialApp)->get_AppName(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Media::DialProtocol::DialAppLaunchResult> impl_IDialApp<D>::RequestLaunchAsync(hstring_view appArgument) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Media::DialProtocol::DialAppLaunchResult> value;
    check_hresult(WINRT_SHIM(IDialApp)->abi_RequestLaunchAsync(get_abi(appArgument), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Media::DialProtocol::DialAppStopResult> impl_IDialApp<D>::StopAsync() const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Media::DialProtocol::DialAppStopResult> value;
    check_hresult(WINRT_SHIM(IDialApp)->abi_StopAsync(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::DialProtocol::DialAppStateDetails> impl_IDialApp<D>::GetAppStateAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::DialProtocol::DialAppStateDetails> value;
    check_hresult(WINRT_SHIM(IDialApp)->abi_GetAppStateAsync(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IDialDevice<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDialDevice)->get_Id(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::DialProtocol::DialApp impl_IDialDevice<D>::GetDialApp(hstring_view appName) const
{
    Windows::Media::DialProtocol::DialApp value { nullptr };
    check_hresult(WINRT_SHIM(IDialDevice)->abi_GetDialApp(get_abi(appName), put_abi(value)));
    return value;
}

template <typename D> hstring impl_IDialDevice2<D>::FriendlyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDialDevice2)->get_FriendlyName(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IRandomAccessStreamReference impl_IDialDevice2<D>::Thumbnail() const
{
    Windows::Storage::Streams::IRandomAccessStreamReference value;
    check_hresult(WINRT_SHIM(IDialDevice2)->get_Thumbnail(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IDialDeviceStatics<D>::GetDeviceSelector(hstring_view appName) const
{
    hstring selector;
    check_hresult(WINRT_SHIM(IDialDeviceStatics)->abi_GetDeviceSelector(get_abi(appName), put_abi(selector)));
    return selector;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::DialProtocol::DialDevice> impl_IDialDeviceStatics<D>::FromIdAsync(hstring_view value) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::DialProtocol::DialDevice> operation;
    check_hresult(WINRT_SHIM(IDialDeviceStatics)->abi_FromIdAsync(get_abi(value), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IDialDeviceStatics<D>::DeviceInfoSupportsDialAsync(const Windows::Devices::Enumeration::DeviceInformation & device) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(IDialDeviceStatics)->abi_DeviceInfoSupportsDialAsync(get_abi(device), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Media::DialProtocol::DialDevice impl_IDialDeviceSelectedEventArgs<D>::SelectedDialDevice() const
{
    Windows::Media::DialProtocol::DialDevice value { nullptr };
    check_hresult(WINRT_SHIM(IDialDeviceSelectedEventArgs)->get_SelectedDialDevice(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::DialProtocol::DialDevice impl_IDialDisconnectButtonClickedEventArgs<D>::Device() const
{
    Windows::Media::DialProtocol::DialDevice value { nullptr };
    check_hresult(WINRT_SHIM(IDialDisconnectButtonClickedEventArgs)->get_Device(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IDialDevicePickerFilter<D>::SupportedAppNames() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IDialDevicePickerFilter)->get_SupportedAppNames(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::DialProtocol::DialDevicePickerFilter impl_IDialDevicePicker<D>::Filter() const
{
    Windows::Media::DialProtocol::DialDevicePickerFilter value { nullptr };
    check_hresult(WINRT_SHIM(IDialDevicePicker)->get_Filter(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Enumeration::DevicePickerAppearance impl_IDialDevicePicker<D>::Appearance() const
{
    Windows::Devices::Enumeration::DevicePickerAppearance value { nullptr };
    check_hresult(WINRT_SHIM(IDialDevicePicker)->get_Appearance(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IDialDevicePicker<D>::DialDeviceSelected(const Windows::Foundation::TypedEventHandler<Windows::Media::DialProtocol::DialDevicePicker, Windows::Media::DialProtocol::DialDeviceSelectedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IDialDevicePicker)->add_DialDeviceSelected(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IDialDevicePicker> impl_IDialDevicePicker<D>::DialDeviceSelected(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::DialProtocol::DialDevicePicker, Windows::Media::DialProtocol::DialDeviceSelectedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IDialDevicePicker>(this, &ABI::Windows::Media::DialProtocol::IDialDevicePicker::remove_DialDeviceSelected, DialDeviceSelected(handler));
}

template <typename D> void impl_IDialDevicePicker<D>::DialDeviceSelected(event_token token) const
{
    check_hresult(WINRT_SHIM(IDialDevicePicker)->remove_DialDeviceSelected(token));
}

template <typename D> event_token impl_IDialDevicePicker<D>::DisconnectButtonClicked(const Windows::Foundation::TypedEventHandler<Windows::Media::DialProtocol::DialDevicePicker, Windows::Media::DialProtocol::DialDisconnectButtonClickedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IDialDevicePicker)->add_DisconnectButtonClicked(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IDialDevicePicker> impl_IDialDevicePicker<D>::DisconnectButtonClicked(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::DialProtocol::DialDevicePicker, Windows::Media::DialProtocol::DialDisconnectButtonClickedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IDialDevicePicker>(this, &ABI::Windows::Media::DialProtocol::IDialDevicePicker::remove_DisconnectButtonClicked, DisconnectButtonClicked(handler));
}

template <typename D> void impl_IDialDevicePicker<D>::DisconnectButtonClicked(event_token token) const
{
    check_hresult(WINRT_SHIM(IDialDevicePicker)->remove_DisconnectButtonClicked(token));
}

template <typename D> event_token impl_IDialDevicePicker<D>::DialDevicePickerDismissed(const Windows::Foundation::TypedEventHandler<Windows::Media::DialProtocol::DialDevicePicker, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IDialDevicePicker)->add_DialDevicePickerDismissed(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IDialDevicePicker> impl_IDialDevicePicker<D>::DialDevicePickerDismissed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::DialProtocol::DialDevicePicker, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IDialDevicePicker>(this, &ABI::Windows::Media::DialProtocol::IDialDevicePicker::remove_DialDevicePickerDismissed, DialDevicePickerDismissed(handler));
}

template <typename D> void impl_IDialDevicePicker<D>::DialDevicePickerDismissed(event_token token) const
{
    check_hresult(WINRT_SHIM(IDialDevicePicker)->remove_DialDevicePickerDismissed(token));
}

template <typename D> void impl_IDialDevicePicker<D>::Show(const Windows::Foundation::Rect & selection) const
{
    check_hresult(WINRT_SHIM(IDialDevicePicker)->abi_Show(get_abi(selection)));
}

template <typename D> void impl_IDialDevicePicker<D>::Show(const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement) const
{
    check_hresult(WINRT_SHIM(IDialDevicePicker)->abi_ShowWithPlacement(get_abi(selection), preferredPlacement));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::DialProtocol::DialDevice> impl_IDialDevicePicker<D>::PickSingleDialDeviceAsync(const Windows::Foundation::Rect & selection) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::DialProtocol::DialDevice> operation;
    check_hresult(WINRT_SHIM(IDialDevicePicker)->abi_PickSingleDialDeviceAsync(get_abi(selection), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::DialProtocol::DialDevice> impl_IDialDevicePicker<D>::PickSingleDialDeviceAsync(const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::DialProtocol::DialDevice> operation;
    check_hresult(WINRT_SHIM(IDialDevicePicker)->abi_PickSingleDialDeviceAsyncWithPlacement(get_abi(selection), preferredPlacement, put_abi(operation)));
    return operation;
}

template <typename D> void impl_IDialDevicePicker<D>::Hide() const
{
    check_hresult(WINRT_SHIM(IDialDevicePicker)->abi_Hide());
}

template <typename D> void impl_IDialDevicePicker<D>::SetDisplayStatus(const Windows::Media::DialProtocol::DialDevice & device, Windows::Media::DialProtocol::DialDeviceDisplayStatus status) const
{
    check_hresult(WINRT_SHIM(IDialDevicePicker)->abi_SetDisplayStatus(get_abi(device), status));
}

inline hstring DialDevice::GetDeviceSelector(hstring_view appName)
{
    return get_activation_factory<DialDevice, IDialDeviceStatics>().GetDeviceSelector(appName);
}

inline Windows::Foundation::IAsyncOperation<Windows::Media::DialProtocol::DialDevice> DialDevice::FromIdAsync(hstring_view value)
{
    return get_activation_factory<DialDevice, IDialDeviceStatics>().FromIdAsync(value);
}

inline Windows::Foundation::IAsyncOperation<bool> DialDevice::DeviceInfoSupportsDialAsync(const Windows::Devices::Enumeration::DeviceInformation & device)
{
    return get_activation_factory<DialDevice, IDialDeviceStatics>().DeviceInfoSupportsDialAsync(device);
}

inline DialDevicePicker::DialDevicePicker() :
    DialDevicePicker(activate_instance<DialDevicePicker>())
{}

}

}
#pragma warning(pop)
