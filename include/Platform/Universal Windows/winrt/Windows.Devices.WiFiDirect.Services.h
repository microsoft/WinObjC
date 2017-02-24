// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Devices.Enumeration.3.h"
#include "internal/Windows.Networking.Sockets.3.h"
#include "internal/Windows.Devices.WiFiDirect.Services.3.h"
#include "Windows.Devices.WiFiDirect.h"
#include "Windows.Foundation.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::WiFiDirect::Services::IWiFiDirectService> : produce_base<D, Windows::Devices::WiFiDirect::Services::IWiFiDirectService>
{
    HRESULT __stdcall get_RemoteServiceInfo(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemoteServiceInfo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedConfigurationMethods(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceConfigurationMethod>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportedConfigurationMethods());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PreferGroupOwnerMode(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PreferGroupOwnerMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PreferGroupOwnerMode(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PreferGroupOwnerMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SessionInfo(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SessionInfo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SessionInfo(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SessionInfo(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServiceError(Windows::Devices::WiFiDirect::Services::WiFiDirectServiceError * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServiceError());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_SessionDeferred(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectService, Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionDeferredEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().SessionDeferred(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectService, Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionDeferredEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SessionDeferred(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SessionDeferred(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetProvisioningInfoAsync(Windows::Devices::WiFiDirect::Services::WiFiDirectServiceConfigurationMethod selectedConfigurationMethod, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceProvisioningInfo>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetProvisioningInfoAsync(selectedConfigurationMethod));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ConnectAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ConnectAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ConnectAsyncWithPin(impl::abi_arg_in<hstring> pin, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ConnectAsync(*reinterpret_cast<const hstring *>(&pin)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser> : produce_base<D, Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser>
{
    HRESULT __stdcall get_ServiceName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServiceName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServiceNamePrefixes(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServiceNamePrefixes());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServiceInfo(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServiceInfo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ServiceInfo(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ServiceInfo(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AutoAcceptSession(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AutoAcceptSession());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AutoAcceptSession(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AutoAcceptSession(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PreferGroupOwnerMode(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PreferGroupOwnerMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PreferGroupOwnerMode(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PreferGroupOwnerMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PreferredConfigurationMethods(impl::abi_arg_out<Windows::Foundation::Collections::IVector<winrt::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceConfigurationMethod>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PreferredConfigurationMethods());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServiceStatus(Windows::Devices::WiFiDirect::Services::WiFiDirectServiceStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServiceStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ServiceStatus(Windows::Devices::WiFiDirect::Services::WiFiDirectServiceStatus value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ServiceStatus(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CustomServiceStatusCode(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CustomServiceStatusCode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CustomServiceStatusCode(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CustomServiceStatusCode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeferredSessionInfo(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeferredSessionInfo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DeferredSessionInfo(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DeferredSessionInfo(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AdvertisementStatus(Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAdvertisementStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AdvertisementStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServiceError(Windows::Devices::WiFiDirect::Services::WiFiDirectServiceError * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServiceError());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_SessionRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAdvertiser, Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionRequestedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().SessionRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAdvertiser, Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionRequestedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SessionRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SessionRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_AutoAcceptSessionConnected(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAdvertiser, Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAutoAcceptSessionConnectedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().AutoAcceptSessionConnected(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAdvertiser, Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAutoAcceptSessionConnectedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AutoAcceptSessionConnected(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AutoAcceptSessionConnected(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_AdvertisementStatusChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAdvertiser, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().AdvertisementStatusChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAdvertiser, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AdvertisementStatusChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AdvertisementStatusChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ConnectAsync(impl::abi_arg_in<Windows::Devices::Enumeration::IDeviceInformation> deviceInfo, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ConnectAsync(*reinterpret_cast<const Windows::Devices::Enumeration::DeviceInformation *>(&deviceInfo)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ConnectAsyncWithPin(impl::abi_arg_in<Windows::Devices::Enumeration::IDeviceInformation> deviceInfo, impl::abi_arg_in<hstring> pin, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ConnectAsync(*reinterpret_cast<const Windows::Devices::Enumeration::DeviceInformation *>(&deviceInfo), *reinterpret_cast<const hstring *>(&pin)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Start() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Stop() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stop();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiserFactory> : produce_base<D, Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiserFactory>
{
    HRESULT __stdcall abi_CreateWiFiDirectServiceAdvertiser(impl::abi_arg_in<hstring> serviceName, impl::abi_arg_out<Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateWiFiDirectServiceAdvertiser(*reinterpret_cast<const hstring *>(&serviceName)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAutoAcceptSessionConnectedEventArgs> : produce_base<D, Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAutoAcceptSessionConnectedEventArgs>
{
    HRESULT __stdcall get_Session(impl::abi_arg_out<Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSession> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Session());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SessionInfo(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SessionInfo());
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
struct produce<D, Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceProvisioningInfo> : produce_base<D, Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceProvisioningInfo>
{
    HRESULT __stdcall get_SelectedConfigurationMethod(Windows::Devices::WiFiDirect::Services::WiFiDirectServiceConfigurationMethod * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SelectedConfigurationMethod());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsGroupFormationNeeded(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsGroupFormationNeeded());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceRemotePortAddedEventArgs> : produce_base<D, Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceRemotePortAddedEventArgs>
{
    HRESULT __stdcall get_EndpointPairs(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Networking::EndpointPair>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EndpointPairs());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Protocol(Windows::Devices::WiFiDirect::Services::WiFiDirectServiceIPProtocol * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Protocol());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSession> : produce_base<D, Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSession>
{
    HRESULT __stdcall get_ServiceName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServiceName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Status(Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ErrorStatus(Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionErrorStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ErrorStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SessionId(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SessionId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AdvertisementId(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AdvertisementId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServiceAddress(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServiceAddress());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SessionAddress(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SessionAddress());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetConnectionEndpointPairs(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Networking::EndpointPair>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetConnectionEndpointPairs());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_SessionStatusChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().SessionStatusChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SessionStatusChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SessionStatusChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddStreamSocketListenerAsync(impl::abi_arg_in<Windows::Networking::Sockets::IStreamSocketListener> value, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().AddStreamSocketListenerAsync(*reinterpret_cast<const Windows::Networking::Sockets::StreamSocketListener *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddDatagramSocketAsync(impl::abi_arg_in<Windows::Networking::Sockets::IDatagramSocket> value, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().AddDatagramSocketAsync(*reinterpret_cast<const Windows::Networking::Sockets::DatagramSocket *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_RemotePortAdded(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession, Windows::Devices::WiFiDirect::Services::WiFiDirectServiceRemotePortAddedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().RemotePortAdded(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession, Windows::Devices::WiFiDirect::Services::WiFiDirectServiceRemotePortAddedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_RemotePortAdded(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemotePortAdded(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionDeferredEventArgs> : produce_base<D, Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionDeferredEventArgs>
{
    HRESULT __stdcall get_DeferredSessionInfo(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeferredSessionInfo());
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
struct produce<D, Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionRequest> : produce_base<D, Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionRequest>
{
    HRESULT __stdcall get_DeviceInformation(impl::abi_arg_out<Windows::Devices::Enumeration::IDeviceInformation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceInformation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProvisioningInfo(impl::abi_arg_out<Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceProvisioningInfo> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProvisioningInfo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SessionInfo(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SessionInfo());
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
struct produce<D, Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionRequestedEventArgs> : produce_base<D, Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionRequestedEventArgs>
{
    HRESULT __stdcall abi_GetSessionRequest(impl::abi_arg_out<Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionRequest> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetSessionRequest());
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
struct produce<D, Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceStatics> : produce_base<D, Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceStatics>
{
    HRESULT __stdcall abi_GetSelector(impl::abi_arg_in<hstring> serviceName, impl::abi_arg_out<hstring> serviceSelector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *serviceSelector = detach_abi(this->shim().GetSelector(*reinterpret_cast<const hstring *>(&serviceName)));
            return S_OK;
        }
        catch (...)
        {
            *serviceSelector = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSelectorWithFilter(impl::abi_arg_in<hstring> serviceName, impl::abi_arg_in<Windows::Storage::Streams::IBuffer> serviceInfoFilter, impl::abi_arg_out<hstring> serviceSelector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *serviceSelector = detach_abi(this->shim().GetSelector(*reinterpret_cast<const hstring *>(&serviceName), *reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&serviceInfoFilter)));
            return S_OK;
        }
        catch (...)
        {
            *serviceSelector = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromIdAsync(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::Services::WiFiDirectService>> asyncOp) noexcept override
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
};

}

namespace Windows::Devices::WiFiDirect::Services {

template <typename D> Windows::Devices::WiFiDirect::Services::WiFiDirectServiceConfigurationMethod impl_IWiFiDirectServiceProvisioningInfo<D>::SelectedConfigurationMethod() const
{
    Windows::Devices::WiFiDirect::Services::WiFiDirectServiceConfigurationMethod value {};
    check_hresult(WINRT_SHIM(IWiFiDirectServiceProvisioningInfo)->get_SelectedConfigurationMethod(&value));
    return value;
}

template <typename D> bool impl_IWiFiDirectServiceProvisioningInfo<D>::IsGroupFormationNeeded() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IWiFiDirectServiceProvisioningInfo)->get_IsGroupFormationNeeded(&value));
    return value;
}

template <typename D> Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession impl_IWiFiDirectServiceAutoAcceptSessionConnectedEventArgs<D>::Session() const
{
    Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession value { nullptr };
    check_hresult(WINRT_SHIM(IWiFiDirectServiceAutoAcceptSessionConnectedEventArgs)->get_Session(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IWiFiDirectServiceAutoAcceptSessionConnectedEventArgs<D>::SessionInfo() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IWiFiDirectServiceAutoAcceptSessionConnectedEventArgs)->get_SessionInfo(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Networking::EndpointPair> impl_IWiFiDirectServiceRemotePortAddedEventArgs<D>::EndpointPairs() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Networking::EndpointPair> value;
    check_hresult(WINRT_SHIM(IWiFiDirectServiceRemotePortAddedEventArgs)->get_EndpointPairs(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::WiFiDirect::Services::WiFiDirectServiceIPProtocol impl_IWiFiDirectServiceRemotePortAddedEventArgs<D>::Protocol() const
{
    Windows::Devices::WiFiDirect::Services::WiFiDirectServiceIPProtocol value {};
    check_hresult(WINRT_SHIM(IWiFiDirectServiceRemotePortAddedEventArgs)->get_Protocol(&value));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IWiFiDirectServiceSessionDeferredEventArgs<D>::DeferredSessionInfo() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IWiFiDirectServiceSessionDeferredEventArgs)->get_DeferredSessionInfo(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionRequest impl_IWiFiDirectServiceSessionRequestedEventArgs<D>::GetSessionRequest() const
{
    Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionRequest value { nullptr };
    check_hresult(WINRT_SHIM(IWiFiDirectServiceSessionRequestedEventArgs)->abi_GetSessionRequest(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAdvertiser impl_IWiFiDirectServiceAdvertiserFactory<D>::CreateWiFiDirectServiceAdvertiser(hstring_view serviceName) const
{
    Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAdvertiser result { nullptr };
    check_hresult(WINRT_SHIM(IWiFiDirectServiceAdvertiserFactory)->abi_CreateWiFiDirectServiceAdvertiser(get_abi(serviceName), put_abi(result)));
    return result;
}

template <typename D> hstring impl_IWiFiDirectServiceAdvertiser<D>::ServiceName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWiFiDirectServiceAdvertiser)->get_ServiceName(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IWiFiDirectServiceAdvertiser<D>::ServiceNamePrefixes() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IWiFiDirectServiceAdvertiser)->get_ServiceNamePrefixes(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IWiFiDirectServiceAdvertiser<D>::ServiceInfo() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IWiFiDirectServiceAdvertiser)->get_ServiceInfo(put_abi(value)));
    return value;
}

template <typename D> void impl_IWiFiDirectServiceAdvertiser<D>::ServiceInfo(const Windows::Storage::Streams::IBuffer & value) const
{
    check_hresult(WINRT_SHIM(IWiFiDirectServiceAdvertiser)->put_ServiceInfo(get_abi(value)));
}

template <typename D> bool impl_IWiFiDirectServiceAdvertiser<D>::AutoAcceptSession() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IWiFiDirectServiceAdvertiser)->get_AutoAcceptSession(&value));
    return value;
}

template <typename D> void impl_IWiFiDirectServiceAdvertiser<D>::AutoAcceptSession(bool value) const
{
    check_hresult(WINRT_SHIM(IWiFiDirectServiceAdvertiser)->put_AutoAcceptSession(value));
}

template <typename D> bool impl_IWiFiDirectServiceAdvertiser<D>::PreferGroupOwnerMode() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IWiFiDirectServiceAdvertiser)->get_PreferGroupOwnerMode(&value));
    return value;
}

template <typename D> void impl_IWiFiDirectServiceAdvertiser<D>::PreferGroupOwnerMode(bool value) const
{
    check_hresult(WINRT_SHIM(IWiFiDirectServiceAdvertiser)->put_PreferGroupOwnerMode(value));
}

template <typename D> Windows::Foundation::Collections::IVector<winrt::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceConfigurationMethod> impl_IWiFiDirectServiceAdvertiser<D>::PreferredConfigurationMethods() const
{
    Windows::Foundation::Collections::IVector<winrt::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceConfigurationMethod> value;
    check_hresult(WINRT_SHIM(IWiFiDirectServiceAdvertiser)->get_PreferredConfigurationMethods(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::WiFiDirect::Services::WiFiDirectServiceStatus impl_IWiFiDirectServiceAdvertiser<D>::ServiceStatus() const
{
    Windows::Devices::WiFiDirect::Services::WiFiDirectServiceStatus value {};
    check_hresult(WINRT_SHIM(IWiFiDirectServiceAdvertiser)->get_ServiceStatus(&value));
    return value;
}

template <typename D> void impl_IWiFiDirectServiceAdvertiser<D>::ServiceStatus(Windows::Devices::WiFiDirect::Services::WiFiDirectServiceStatus value) const
{
    check_hresult(WINRT_SHIM(IWiFiDirectServiceAdvertiser)->put_ServiceStatus(value));
}

template <typename D> uint32_t impl_IWiFiDirectServiceAdvertiser<D>::CustomServiceStatusCode() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IWiFiDirectServiceAdvertiser)->get_CustomServiceStatusCode(&value));
    return value;
}

template <typename D> void impl_IWiFiDirectServiceAdvertiser<D>::CustomServiceStatusCode(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IWiFiDirectServiceAdvertiser)->put_CustomServiceStatusCode(value));
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IWiFiDirectServiceAdvertiser<D>::DeferredSessionInfo() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IWiFiDirectServiceAdvertiser)->get_DeferredSessionInfo(put_abi(value)));
    return value;
}

template <typename D> void impl_IWiFiDirectServiceAdvertiser<D>::DeferredSessionInfo(const Windows::Storage::Streams::IBuffer & value) const
{
    check_hresult(WINRT_SHIM(IWiFiDirectServiceAdvertiser)->put_DeferredSessionInfo(get_abi(value)));
}

template <typename D> Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAdvertisementStatus impl_IWiFiDirectServiceAdvertiser<D>::AdvertisementStatus() const
{
    Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAdvertisementStatus value {};
    check_hresult(WINRT_SHIM(IWiFiDirectServiceAdvertiser)->get_AdvertisementStatus(&value));
    return value;
}

template <typename D> Windows::Devices::WiFiDirect::Services::WiFiDirectServiceError impl_IWiFiDirectServiceAdvertiser<D>::ServiceError() const
{
    Windows::Devices::WiFiDirect::Services::WiFiDirectServiceError value {};
    check_hresult(WINRT_SHIM(IWiFiDirectServiceAdvertiser)->get_ServiceError(&value));
    return value;
}

template <typename D> event_token impl_IWiFiDirectServiceAdvertiser<D>::SessionRequested(const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAdvertiser, Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionRequestedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IWiFiDirectServiceAdvertiser)->add_SessionRequested(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IWiFiDirectServiceAdvertiser> impl_IWiFiDirectServiceAdvertiser<D>::SessionRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAdvertiser, Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionRequestedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IWiFiDirectServiceAdvertiser>(this, &ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser::remove_SessionRequested, SessionRequested(handler));
}

template <typename D> void impl_IWiFiDirectServiceAdvertiser<D>::SessionRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IWiFiDirectServiceAdvertiser)->remove_SessionRequested(token));
}

template <typename D> event_token impl_IWiFiDirectServiceAdvertiser<D>::AutoAcceptSessionConnected(const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAdvertiser, Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAutoAcceptSessionConnectedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IWiFiDirectServiceAdvertiser)->add_AutoAcceptSessionConnected(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IWiFiDirectServiceAdvertiser> impl_IWiFiDirectServiceAdvertiser<D>::AutoAcceptSessionConnected(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAdvertiser, Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAutoAcceptSessionConnectedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IWiFiDirectServiceAdvertiser>(this, &ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser::remove_AutoAcceptSessionConnected, AutoAcceptSessionConnected(handler));
}

template <typename D> void impl_IWiFiDirectServiceAdvertiser<D>::AutoAcceptSessionConnected(event_token token) const
{
    check_hresult(WINRT_SHIM(IWiFiDirectServiceAdvertiser)->remove_AutoAcceptSessionConnected(token));
}

template <typename D> event_token impl_IWiFiDirectServiceAdvertiser<D>::AdvertisementStatusChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAdvertiser, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IWiFiDirectServiceAdvertiser)->add_AdvertisementStatusChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IWiFiDirectServiceAdvertiser> impl_IWiFiDirectServiceAdvertiser<D>::AdvertisementStatusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAdvertiser, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IWiFiDirectServiceAdvertiser>(this, &ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser::remove_AdvertisementStatusChanged, AdvertisementStatusChanged(handler));
}

template <typename D> void impl_IWiFiDirectServiceAdvertiser<D>::AdvertisementStatusChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IWiFiDirectServiceAdvertiser)->remove_AdvertisementStatusChanged(token));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession> impl_IWiFiDirectServiceAdvertiser<D>::ConnectAsync(const Windows::Devices::Enumeration::DeviceInformation & deviceInfo) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession> result;
    check_hresult(WINRT_SHIM(IWiFiDirectServiceAdvertiser)->abi_ConnectAsync(get_abi(deviceInfo), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession> impl_IWiFiDirectServiceAdvertiser<D>::ConnectAsync(const Windows::Devices::Enumeration::DeviceInformation & deviceInfo, hstring_view pin) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession> result;
    check_hresult(WINRT_SHIM(IWiFiDirectServiceAdvertiser)->abi_ConnectAsyncWithPin(get_abi(deviceInfo), get_abi(pin), put_abi(result)));
    return result;
}

template <typename D> void impl_IWiFiDirectServiceAdvertiser<D>::Start() const
{
    check_hresult(WINRT_SHIM(IWiFiDirectServiceAdvertiser)->abi_Start());
}

template <typename D> void impl_IWiFiDirectServiceAdvertiser<D>::Stop() const
{
    check_hresult(WINRT_SHIM(IWiFiDirectServiceAdvertiser)->abi_Stop());
}

template <typename D> hstring impl_IWiFiDirectServiceStatics<D>::GetSelector(hstring_view serviceName) const
{
    hstring serviceSelector;
    check_hresult(WINRT_SHIM(IWiFiDirectServiceStatics)->abi_GetSelector(get_abi(serviceName), put_abi(serviceSelector)));
    return serviceSelector;
}

template <typename D> hstring impl_IWiFiDirectServiceStatics<D>::GetSelector(hstring_view serviceName, const Windows::Storage::Streams::IBuffer & serviceInfoFilter) const
{
    hstring serviceSelector;
    check_hresult(WINRT_SHIM(IWiFiDirectServiceStatics)->abi_GetSelectorWithFilter(get_abi(serviceName), get_abi(serviceInfoFilter), put_abi(serviceSelector)));
    return serviceSelector;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::Services::WiFiDirectService> impl_IWiFiDirectServiceStatics<D>::FromIdAsync(hstring_view deviceId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::Services::WiFiDirectService> asyncOp;
    check_hresult(WINRT_SHIM(IWiFiDirectServiceStatics)->abi_FromIdAsync(get_abi(deviceId), put_abi(asyncOp)));
    return asyncOp;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IWiFiDirectService<D>::RemoteServiceInfo() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IWiFiDirectService)->get_RemoteServiceInfo(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceConfigurationMethod> impl_IWiFiDirectService<D>::SupportedConfigurationMethods() const
{
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceConfigurationMethod> value;
    check_hresult(WINRT_SHIM(IWiFiDirectService)->get_SupportedConfigurationMethods(put_abi(value)));
    return value;
}

template <typename D> bool impl_IWiFiDirectService<D>::PreferGroupOwnerMode() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IWiFiDirectService)->get_PreferGroupOwnerMode(&value));
    return value;
}

template <typename D> void impl_IWiFiDirectService<D>::PreferGroupOwnerMode(bool value) const
{
    check_hresult(WINRT_SHIM(IWiFiDirectService)->put_PreferGroupOwnerMode(value));
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IWiFiDirectService<D>::SessionInfo() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IWiFiDirectService)->get_SessionInfo(put_abi(value)));
    return value;
}

template <typename D> void impl_IWiFiDirectService<D>::SessionInfo(const Windows::Storage::Streams::IBuffer & value) const
{
    check_hresult(WINRT_SHIM(IWiFiDirectService)->put_SessionInfo(get_abi(value)));
}

template <typename D> Windows::Devices::WiFiDirect::Services::WiFiDirectServiceError impl_IWiFiDirectService<D>::ServiceError() const
{
    Windows::Devices::WiFiDirect::Services::WiFiDirectServiceError value {};
    check_hresult(WINRT_SHIM(IWiFiDirectService)->get_ServiceError(&value));
    return value;
}

template <typename D> event_token impl_IWiFiDirectService<D>::SessionDeferred(const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectService, Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionDeferredEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IWiFiDirectService)->add_SessionDeferred(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IWiFiDirectService> impl_IWiFiDirectService<D>::SessionDeferred(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectService, Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionDeferredEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IWiFiDirectService>(this, &ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectService::remove_SessionDeferred, SessionDeferred(handler));
}

template <typename D> void impl_IWiFiDirectService<D>::SessionDeferred(event_token token) const
{
    check_hresult(WINRT_SHIM(IWiFiDirectService)->remove_SessionDeferred(token));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceProvisioningInfo> impl_IWiFiDirectService<D>::GetProvisioningInfoAsync(Windows::Devices::WiFiDirect::Services::WiFiDirectServiceConfigurationMethod selectedConfigurationMethod) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceProvisioningInfo> result;
    check_hresult(WINRT_SHIM(IWiFiDirectService)->abi_GetProvisioningInfoAsync(selectedConfigurationMethod, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession> impl_IWiFiDirectService<D>::ConnectAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession> result;
    check_hresult(WINRT_SHIM(IWiFiDirectService)->abi_ConnectAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession> impl_IWiFiDirectService<D>::ConnectAsync(hstring_view pin) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession> result;
    check_hresult(WINRT_SHIM(IWiFiDirectService)->abi_ConnectAsyncWithPin(get_abi(pin), put_abi(result)));
    return result;
}

template <typename D> Windows::Devices::Enumeration::DeviceInformation impl_IWiFiDirectServiceSessionRequest<D>::DeviceInformation() const
{
    Windows::Devices::Enumeration::DeviceInformation value { nullptr };
    check_hresult(WINRT_SHIM(IWiFiDirectServiceSessionRequest)->get_DeviceInformation(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::WiFiDirect::Services::WiFiDirectServiceProvisioningInfo impl_IWiFiDirectServiceSessionRequest<D>::ProvisioningInfo() const
{
    Windows::Devices::WiFiDirect::Services::WiFiDirectServiceProvisioningInfo value { nullptr };
    check_hresult(WINRT_SHIM(IWiFiDirectServiceSessionRequest)->get_ProvisioningInfo(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IWiFiDirectServiceSessionRequest<D>::SessionInfo() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IWiFiDirectServiceSessionRequest)->get_SessionInfo(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IWiFiDirectServiceSession<D>::ServiceName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWiFiDirectServiceSession)->get_ServiceName(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionStatus impl_IWiFiDirectServiceSession<D>::Status() const
{
    Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionStatus value {};
    check_hresult(WINRT_SHIM(IWiFiDirectServiceSession)->get_Status(&value));
    return value;
}

template <typename D> Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionErrorStatus impl_IWiFiDirectServiceSession<D>::ErrorStatus() const
{
    Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionErrorStatus value {};
    check_hresult(WINRT_SHIM(IWiFiDirectServiceSession)->get_ErrorStatus(&value));
    return value;
}

template <typename D> uint32_t impl_IWiFiDirectServiceSession<D>::SessionId() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IWiFiDirectServiceSession)->get_SessionId(&value));
    return value;
}

template <typename D> uint32_t impl_IWiFiDirectServiceSession<D>::AdvertisementId() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IWiFiDirectServiceSession)->get_AdvertisementId(&value));
    return value;
}

template <typename D> hstring impl_IWiFiDirectServiceSession<D>::ServiceAddress() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWiFiDirectServiceSession)->get_ServiceAddress(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IWiFiDirectServiceSession<D>::SessionAddress() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWiFiDirectServiceSession)->get_SessionAddress(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Networking::EndpointPair> impl_IWiFiDirectServiceSession<D>::GetConnectionEndpointPairs() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Networking::EndpointPair> value;
    check_hresult(WINRT_SHIM(IWiFiDirectServiceSession)->abi_GetConnectionEndpointPairs(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IWiFiDirectServiceSession<D>::SessionStatusChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IWiFiDirectServiceSession)->add_SessionStatusChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IWiFiDirectServiceSession> impl_IWiFiDirectServiceSession<D>::SessionStatusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IWiFiDirectServiceSession>(this, &ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSession::remove_SessionStatusChanged, SessionStatusChanged(handler));
}

template <typename D> void impl_IWiFiDirectServiceSession<D>::SessionStatusChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IWiFiDirectServiceSession)->remove_SessionStatusChanged(token));
}

template <typename D> Windows::Foundation::IAsyncAction impl_IWiFiDirectServiceSession<D>::AddStreamSocketListenerAsync(const Windows::Networking::Sockets::StreamSocketListener & value) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IWiFiDirectServiceSession)->abi_AddStreamSocketListenerAsync(get_abi(value), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IWiFiDirectServiceSession<D>::AddDatagramSocketAsync(const Windows::Networking::Sockets::DatagramSocket & value) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IWiFiDirectServiceSession)->abi_AddDatagramSocketAsync(get_abi(value), put_abi(result)));
    return result;
}

template <typename D> event_token impl_IWiFiDirectServiceSession<D>::RemotePortAdded(const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession, Windows::Devices::WiFiDirect::Services::WiFiDirectServiceRemotePortAddedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IWiFiDirectServiceSession)->add_RemotePortAdded(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IWiFiDirectServiceSession> impl_IWiFiDirectServiceSession<D>::RemotePortAdded(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession, Windows::Devices::WiFiDirect::Services::WiFiDirectServiceRemotePortAddedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IWiFiDirectServiceSession>(this, &ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSession::remove_RemotePortAdded, RemotePortAdded(handler));
}

template <typename D> void impl_IWiFiDirectServiceSession<D>::RemotePortAdded(event_token token) const
{
    check_hresult(WINRT_SHIM(IWiFiDirectServiceSession)->remove_RemotePortAdded(token));
}

inline hstring WiFiDirectService::GetSelector(hstring_view serviceName)
{
    return get_activation_factory<WiFiDirectService, IWiFiDirectServiceStatics>().GetSelector(serviceName);
}

inline hstring WiFiDirectService::GetSelector(hstring_view serviceName, const Windows::Storage::Streams::IBuffer & serviceInfoFilter)
{
    return get_activation_factory<WiFiDirectService, IWiFiDirectServiceStatics>().GetSelector(serviceName, serviceInfoFilter);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::Services::WiFiDirectService> WiFiDirectService::FromIdAsync(hstring_view deviceId)
{
    return get_activation_factory<WiFiDirectService, IWiFiDirectServiceStatics>().FromIdAsync(deviceId);
}

inline WiFiDirectServiceAdvertiser::WiFiDirectServiceAdvertiser(hstring_view serviceName) :
    WiFiDirectServiceAdvertiser(get_activation_factory<WiFiDirectServiceAdvertiser, IWiFiDirectServiceAdvertiserFactory>().CreateWiFiDirectServiceAdvertiser(serviceName))
{}

}

}
#pragma warning(pop)
