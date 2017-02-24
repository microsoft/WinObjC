// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Networking.Connectivity.3.h"
#include "internal/Windows.Security.Credentials.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Devices.WiFi.3.h"
#include "Windows.Devices.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::WiFi::IWiFiAdapter> : produce_base<D, Windows::Devices::WiFi::IWiFiAdapter>
{
    HRESULT __stdcall get_NetworkAdapter(impl::abi_arg_out<Windows::Networking::Connectivity::INetworkAdapter> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NetworkAdapter());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ScanAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ScanAsync());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NetworkReport(impl::abi_arg_out<Windows::Devices::WiFi::IWiFiNetworkReport> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NetworkReport());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_AvailableNetworksChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::WiFi::WiFiAdapter, Windows::Foundation::IInspectable>> args, event_token * eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_abi(this->shim().AvailableNetworksChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFi::WiFiAdapter, Windows::Foundation::IInspectable> *>(&args)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AvailableNetworksChanged(event_token eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AvailableNetworksChanged(eventCookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ConnectAsync(impl::abi_arg_in<Windows::Devices::WiFi::IWiFiAvailableNetwork> availableNetwork, Windows::Devices::WiFi::WiFiReconnectionKind reconnectionKind, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiConnectionResult>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ConnectAsync(*reinterpret_cast<const Windows::Devices::WiFi::WiFiAvailableNetwork *>(&availableNetwork), reconnectionKind));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ConnectWithPasswordCredentialAsync(impl::abi_arg_in<Windows::Devices::WiFi::IWiFiAvailableNetwork> availableNetwork, Windows::Devices::WiFi::WiFiReconnectionKind reconnectionKind, impl::abi_arg_in<Windows::Security::Credentials::IPasswordCredential> passwordCredential, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiConnectionResult>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ConnectAsync(*reinterpret_cast<const Windows::Devices::WiFi::WiFiAvailableNetwork *>(&availableNetwork), reconnectionKind, *reinterpret_cast<const Windows::Security::Credentials::PasswordCredential *>(&passwordCredential)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ConnectWithPasswordCredentialAndSsidAsync(impl::abi_arg_in<Windows::Devices::WiFi::IWiFiAvailableNetwork> availableNetwork, Windows::Devices::WiFi::WiFiReconnectionKind reconnectionKind, impl::abi_arg_in<Windows::Security::Credentials::IPasswordCredential> passwordCredential, impl::abi_arg_in<hstring> ssid, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiConnectionResult>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ConnectAsync(*reinterpret_cast<const Windows::Devices::WiFi::WiFiAvailableNetwork *>(&availableNetwork), reconnectionKind, *reinterpret_cast<const Windows::Security::Credentials::PasswordCredential *>(&passwordCredential), *reinterpret_cast<const hstring *>(&ssid)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Disconnect() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Disconnect();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::WiFi::IWiFiAdapterStatics> : produce_base<D, Windows::Devices::WiFi::IWiFiAdapterStatics>
{
    HRESULT __stdcall abi_FindAllAdaptersAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::WiFi::WiFiAdapter>>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FindAllAdaptersAsync());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelector(impl::abi_arg_out<hstring> deviceSelector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deviceSelector = detach_abi(this->shim().GetDeviceSelector());
            return S_OK;
        }
        catch (...)
        {
            *deviceSelector = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromIdAsync(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiAdapter>> asyncOp) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_abi(this->shim().FromIdAsync(*reinterpret_cast<const hstring *>(&deviceId)));
            return S_OK;
        }
        catch (...)
        {
            *asyncOp = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestAccessAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::WiFi::WiFiAccessStatus>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequestAccessAsync());
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
struct produce<D, Windows::Devices::WiFi::IWiFiAvailableNetwork> : produce_base<D, Windows::Devices::WiFi::IWiFiAvailableNetwork>
{
    HRESULT __stdcall get_Uptime(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Uptime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Ssid(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Ssid());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Bssid(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Bssid());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ChannelCenterFrequencyInKilohertz(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ChannelCenterFrequencyInKilohertz());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NetworkRssiInDecibelMilliwatts(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NetworkRssiInDecibelMilliwatts());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SignalBars(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SignalBars());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NetworkKind(Windows::Devices::WiFi::WiFiNetworkKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NetworkKind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PhyKind(Windows::Devices::WiFi::WiFiPhyKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PhyKind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SecuritySettings(impl::abi_arg_out<Windows::Networking::Connectivity::INetworkSecuritySettings> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SecuritySettings());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BeaconInterval(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BeaconInterval());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsWiFiDirect(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsWiFiDirect());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::WiFi::IWiFiConnectionResult> : produce_base<D, Windows::Devices::WiFi::IWiFiConnectionResult>
{
    HRESULT __stdcall get_ConnectionStatus(Windows::Devices::WiFi::WiFiConnectionStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ConnectionStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::WiFi::IWiFiNetworkReport> : produce_base<D, Windows::Devices::WiFi::IWiFiNetworkReport>
{
    HRESULT __stdcall get_Timestamp(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Timestamp());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AvailableNetworks(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::WiFi::WiFiAvailableNetwork>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AvailableNetworks());
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

namespace Windows::Devices::WiFi {

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::WiFi::WiFiAdapter>> impl_IWiFiAdapterStatics<D>::FindAllAdaptersAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::WiFi::WiFiAdapter>> value;
    check_hresult(WINRT_SHIM(IWiFiAdapterStatics)->abi_FindAllAdaptersAsync(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IWiFiAdapterStatics<D>::GetDeviceSelector() const
{
    hstring deviceSelector;
    check_hresult(WINRT_SHIM(IWiFiAdapterStatics)->abi_GetDeviceSelector(put_abi(deviceSelector)));
    return deviceSelector;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiAdapter> impl_IWiFiAdapterStatics<D>::FromIdAsync(hstring_view deviceId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiAdapter> asyncOp;
    check_hresult(WINRT_SHIM(IWiFiAdapterStatics)->abi_FromIdAsync(get_abi(deviceId), put_abi(asyncOp)));
    return asyncOp;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::WiFi::WiFiAccessStatus> impl_IWiFiAdapterStatics<D>::RequestAccessAsync() const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::WiFi::WiFiAccessStatus> value;
    check_hresult(WINRT_SHIM(IWiFiAdapterStatics)->abi_RequestAccessAsync(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::Connectivity::NetworkAdapter impl_IWiFiAdapter<D>::NetworkAdapter() const
{
    Windows::Networking::Connectivity::NetworkAdapter value { nullptr };
    check_hresult(WINRT_SHIM(IWiFiAdapter)->get_NetworkAdapter(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IWiFiAdapter<D>::ScanAsync() const
{
    Windows::Foundation::IAsyncAction value;
    check_hresult(WINRT_SHIM(IWiFiAdapter)->abi_ScanAsync(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::WiFi::WiFiNetworkReport impl_IWiFiAdapter<D>::NetworkReport() const
{
    Windows::Devices::WiFi::WiFiNetworkReport value { nullptr };
    check_hresult(WINRT_SHIM(IWiFiAdapter)->get_NetworkReport(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IWiFiAdapter<D>::AvailableNetworksChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFi::WiFiAdapter, Windows::Foundation::IInspectable> & args) const
{
    event_token eventCookie {};
    check_hresult(WINRT_SHIM(IWiFiAdapter)->add_AvailableNetworksChanged(get_abi(args), &eventCookie));
    return eventCookie;
}

template <typename D> event_revoker<IWiFiAdapter> impl_IWiFiAdapter<D>::AvailableNetworksChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFi::WiFiAdapter, Windows::Foundation::IInspectable> & args) const
{
    return impl::make_event_revoker<D, IWiFiAdapter>(this, &ABI::Windows::Devices::WiFi::IWiFiAdapter::remove_AvailableNetworksChanged, AvailableNetworksChanged(args));
}

template <typename D> void impl_IWiFiAdapter<D>::AvailableNetworksChanged(event_token eventCookie) const
{
    check_hresult(WINRT_SHIM(IWiFiAdapter)->remove_AvailableNetworksChanged(eventCookie));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiConnectionResult> impl_IWiFiAdapter<D>::ConnectAsync(const Windows::Devices::WiFi::WiFiAvailableNetwork & availableNetwork, Windows::Devices::WiFi::WiFiReconnectionKind reconnectionKind) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiConnectionResult> value;
    check_hresult(WINRT_SHIM(IWiFiAdapter)->abi_ConnectAsync(get_abi(availableNetwork), reconnectionKind, put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiConnectionResult> impl_IWiFiAdapter<D>::ConnectAsync(const Windows::Devices::WiFi::WiFiAvailableNetwork & availableNetwork, Windows::Devices::WiFi::WiFiReconnectionKind reconnectionKind, const Windows::Security::Credentials::PasswordCredential & passwordCredential) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiConnectionResult> value;
    check_hresult(WINRT_SHIM(IWiFiAdapter)->abi_ConnectWithPasswordCredentialAsync(get_abi(availableNetwork), reconnectionKind, get_abi(passwordCredential), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiConnectionResult> impl_IWiFiAdapter<D>::ConnectAsync(const Windows::Devices::WiFi::WiFiAvailableNetwork & availableNetwork, Windows::Devices::WiFi::WiFiReconnectionKind reconnectionKind, const Windows::Security::Credentials::PasswordCredential & passwordCredential, hstring_view ssid) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiConnectionResult> value;
    check_hresult(WINRT_SHIM(IWiFiAdapter)->abi_ConnectWithPasswordCredentialAndSsidAsync(get_abi(availableNetwork), reconnectionKind, get_abi(passwordCredential), get_abi(ssid), put_abi(value)));
    return value;
}

template <typename D> void impl_IWiFiAdapter<D>::Disconnect() const
{
    check_hresult(WINRT_SHIM(IWiFiAdapter)->abi_Disconnect());
}

template <typename D> Windows::Foundation::DateTime impl_IWiFiNetworkReport<D>::Timestamp() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IWiFiNetworkReport)->get_Timestamp(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::WiFi::WiFiAvailableNetwork> impl_IWiFiNetworkReport<D>::AvailableNetworks() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::WiFi::WiFiAvailableNetwork> value;
    check_hresult(WINRT_SHIM(IWiFiNetworkReport)->get_AvailableNetworks(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IWiFiAvailableNetwork<D>::Uptime() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IWiFiAvailableNetwork)->get_Uptime(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IWiFiAvailableNetwork<D>::Ssid() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWiFiAvailableNetwork)->get_Ssid(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IWiFiAvailableNetwork<D>::Bssid() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWiFiAvailableNetwork)->get_Bssid(put_abi(value)));
    return value;
}

template <typename D> int32_t impl_IWiFiAvailableNetwork<D>::ChannelCenterFrequencyInKilohertz() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IWiFiAvailableNetwork)->get_ChannelCenterFrequencyInKilohertz(&value));
    return value;
}

template <typename D> double impl_IWiFiAvailableNetwork<D>::NetworkRssiInDecibelMilliwatts() const
{
    double value {};
    check_hresult(WINRT_SHIM(IWiFiAvailableNetwork)->get_NetworkRssiInDecibelMilliwatts(&value));
    return value;
}

template <typename D> uint8_t impl_IWiFiAvailableNetwork<D>::SignalBars() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IWiFiAvailableNetwork)->get_SignalBars(&value));
    return value;
}

template <typename D> Windows::Devices::WiFi::WiFiNetworkKind impl_IWiFiAvailableNetwork<D>::NetworkKind() const
{
    Windows::Devices::WiFi::WiFiNetworkKind value {};
    check_hresult(WINRT_SHIM(IWiFiAvailableNetwork)->get_NetworkKind(&value));
    return value;
}

template <typename D> Windows::Devices::WiFi::WiFiPhyKind impl_IWiFiAvailableNetwork<D>::PhyKind() const
{
    Windows::Devices::WiFi::WiFiPhyKind value {};
    check_hresult(WINRT_SHIM(IWiFiAvailableNetwork)->get_PhyKind(&value));
    return value;
}

template <typename D> Windows::Networking::Connectivity::NetworkSecuritySettings impl_IWiFiAvailableNetwork<D>::SecuritySettings() const
{
    Windows::Networking::Connectivity::NetworkSecuritySettings value { nullptr };
    check_hresult(WINRT_SHIM(IWiFiAvailableNetwork)->get_SecuritySettings(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IWiFiAvailableNetwork<D>::BeaconInterval() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IWiFiAvailableNetwork)->get_BeaconInterval(put_abi(value)));
    return value;
}

template <typename D> bool impl_IWiFiAvailableNetwork<D>::IsWiFiDirect() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IWiFiAvailableNetwork)->get_IsWiFiDirect(&value));
    return value;
}

template <typename D> Windows::Devices::WiFi::WiFiConnectionStatus impl_IWiFiConnectionResult<D>::ConnectionStatus() const
{
    Windows::Devices::WiFi::WiFiConnectionStatus value {};
    check_hresult(WINRT_SHIM(IWiFiConnectionResult)->get_ConnectionStatus(&value));
    return value;
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::WiFi::WiFiAdapter>> WiFiAdapter::FindAllAdaptersAsync()
{
    return get_activation_factory<WiFiAdapter, IWiFiAdapterStatics>().FindAllAdaptersAsync();
}

inline hstring WiFiAdapter::GetDeviceSelector()
{
    return get_activation_factory<WiFiAdapter, IWiFiAdapterStatics>().GetDeviceSelector();
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::WiFi::WiFiAdapter> WiFiAdapter::FromIdAsync(hstring_view deviceId)
{
    return get_activation_factory<WiFiAdapter, IWiFiAdapterStatics>().FromIdAsync(deviceId);
}

inline Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::WiFi::WiFiAccessStatus> WiFiAdapter::RequestAccessAsync()
{
    return get_activation_factory<WiFiAdapter, IWiFiAdapterStatics>().RequestAccessAsync();
}

}

}
#pragma warning(pop)
