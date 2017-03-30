// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Devices.WiFiDirect.Services.0.h"
#include "Windows.Devices.Enumeration.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Networking.Sockets.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Networking.1.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::WiFiDirect::Services {

struct __declspec(uuid("50aabbb8-5f71-45ec-84f1-a1e4fc7879a3")) __declspec(novtable) IWiFiDirectService : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RemoteServiceInfo(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall get_SupportedConfigurationMethods(Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceConfigurationMethod> ** value) = 0;
    virtual HRESULT __stdcall get_PreferGroupOwnerMode(bool * value) = 0;
    virtual HRESULT __stdcall put_PreferGroupOwnerMode(bool value) = 0;
    virtual HRESULT __stdcall get_SessionInfo(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall put_SessionInfo(Windows::Storage::Streams::IBuffer * value) = 0;
    virtual HRESULT __stdcall get_ServiceError(winrt::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceError * value) = 0;
    virtual HRESULT __stdcall add_SessionDeferred(Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectService, Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionDeferredEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SessionDeferred(event_token token) = 0;
    virtual HRESULT __stdcall abi_GetProvisioningInfoAsync(winrt::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceConfigurationMethod selectedConfigurationMethod, Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceProvisioningInfo> ** result) = 0;
    virtual HRESULT __stdcall abi_ConnectAsync(Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession> ** result) = 0;
    virtual HRESULT __stdcall abi_ConnectAsyncWithPin(hstring pin, Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession> ** result) = 0;
};

struct __declspec(uuid("a4aa1ee1-9d8f-4f4f-93ee-7ddea2e37f46")) __declspec(novtable) IWiFiDirectServiceAdvertiser : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ServiceName(hstring * value) = 0;
    virtual HRESULT __stdcall get_ServiceNamePrefixes(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_ServiceInfo(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall put_ServiceInfo(Windows::Storage::Streams::IBuffer * value) = 0;
    virtual HRESULT __stdcall get_AutoAcceptSession(bool * value) = 0;
    virtual HRESULT __stdcall put_AutoAcceptSession(bool value) = 0;
    virtual HRESULT __stdcall get_PreferGroupOwnerMode(bool * value) = 0;
    virtual HRESULT __stdcall put_PreferGroupOwnerMode(bool value) = 0;
    virtual HRESULT __stdcall get_PreferredConfigurationMethods(Windows::Foundation::Collections::IVector<winrt::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceConfigurationMethod> ** value) = 0;
    virtual HRESULT __stdcall get_ServiceStatus(winrt::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceStatus * value) = 0;
    virtual HRESULT __stdcall put_ServiceStatus(winrt::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceStatus value) = 0;
    virtual HRESULT __stdcall get_CustomServiceStatusCode(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_CustomServiceStatusCode(uint32_t value) = 0;
    virtual HRESULT __stdcall get_DeferredSessionInfo(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall put_DeferredSessionInfo(Windows::Storage::Streams::IBuffer * value) = 0;
    virtual HRESULT __stdcall get_AdvertisementStatus(winrt::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAdvertisementStatus * value) = 0;
    virtual HRESULT __stdcall get_ServiceError(winrt::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceError * value) = 0;
    virtual HRESULT __stdcall add_SessionRequested(Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAdvertiser, Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionRequestedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SessionRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_AutoAcceptSessionConnected(Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAdvertiser, Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAutoAcceptSessionConnectedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_AutoAcceptSessionConnected(event_token token) = 0;
    virtual HRESULT __stdcall add_AdvertisementStatusChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAdvertiser, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_AdvertisementStatusChanged(event_token token) = 0;
    virtual HRESULT __stdcall abi_ConnectAsync(Windows::Devices::Enumeration::IDeviceInformation * deviceInfo, Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession> ** result) = 0;
    virtual HRESULT __stdcall abi_ConnectAsyncWithPin(Windows::Devices::Enumeration::IDeviceInformation * deviceInfo, hstring pin, Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession> ** result) = 0;
    virtual HRESULT __stdcall abi_Start() = 0;
    virtual HRESULT __stdcall abi_Stop() = 0;
};

struct __declspec(uuid("3106ac0d-b446-4f13-9f9a-8ae925feba2b")) __declspec(novtable) IWiFiDirectServiceAdvertiserFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateWiFiDirectServiceAdvertiser(hstring serviceName, Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser ** result) = 0;
};

struct __declspec(uuid("dcd9e01e-83df-43e5-8f43-cbe8479e84eb")) __declspec(novtable) IWiFiDirectServiceAutoAcceptSessionConnectedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Session(Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSession ** value) = 0;
    virtual HRESULT __stdcall get_SessionInfo(Windows::Storage::Streams::IBuffer ** value) = 0;
};

struct __declspec(uuid("8bdb7cfe-97d9-45a2-8e99-db50910fb6a6")) __declspec(novtable) IWiFiDirectServiceProvisioningInfo : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SelectedConfigurationMethod(winrt::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceConfigurationMethod * value) = 0;
    virtual HRESULT __stdcall get_IsGroupFormationNeeded(bool * value) = 0;
};

struct __declspec(uuid("d4cebac1-3fd3-4f0e-b7bd-782906f44411")) __declspec(novtable) IWiFiDirectServiceRemotePortAddedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EndpointPairs(Windows::Foundation::Collections::IVectorView<Windows::Networking::EndpointPair> ** value) = 0;
    virtual HRESULT __stdcall get_Protocol(winrt::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceIPProtocol * value) = 0;
};

struct __declspec(uuid("81142163-e426-47cb-8640-e1b3588bf26f")) __declspec(novtable) IWiFiDirectServiceSession : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ServiceName(hstring * value) = 0;
    virtual HRESULT __stdcall get_Status(winrt::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionStatus * value) = 0;
    virtual HRESULT __stdcall get_ErrorStatus(winrt::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionErrorStatus * value) = 0;
    virtual HRESULT __stdcall get_SessionId(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_AdvertisementId(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_ServiceAddress(hstring * value) = 0;
    virtual HRESULT __stdcall get_SessionAddress(hstring * value) = 0;
    virtual HRESULT __stdcall abi_GetConnectionEndpointPairs(Windows::Foundation::Collections::IVectorView<Windows::Networking::EndpointPair> ** value) = 0;
    virtual HRESULT __stdcall add_SessionStatusChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SessionStatusChanged(event_token token) = 0;
    virtual HRESULT __stdcall abi_AddStreamSocketListenerAsync(Windows::Networking::Sockets::IStreamSocketListener * value, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_AddDatagramSocketAsync(Windows::Networking::Sockets::IDatagramSocket * value, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall add_RemotePortAdded(Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession, Windows::Devices::WiFiDirect::Services::WiFiDirectServiceRemotePortAddedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_RemotePortAdded(event_token token) = 0;
};

struct __declspec(uuid("8dfc197f-1201-4f1f-b6f4-5df1b7b9fb2e")) __declspec(novtable) IWiFiDirectServiceSessionDeferredEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeferredSessionInfo(Windows::Storage::Streams::IBuffer ** value) = 0;
};

struct __declspec(uuid("a0e27c8b-50cb-4a58-9bcf-e472b99fba04")) __declspec(novtable) IWiFiDirectServiceSessionRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceInformation(Windows::Devices::Enumeration::IDeviceInformation ** value) = 0;
    virtual HRESULT __stdcall get_ProvisioningInfo(Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceProvisioningInfo ** value) = 0;
    virtual HRESULT __stdcall get_SessionInfo(Windows::Storage::Streams::IBuffer ** value) = 0;
};

struct __declspec(uuid("74bdcc11-53d6-4999-b4f8-6c8ecc1771e7")) __declspec(novtable) IWiFiDirectServiceSessionRequestedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetSessionRequest(Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionRequest ** value) = 0;
};

struct __declspec(uuid("7db40045-fd74-4688-b725-5dce86acf233")) __declspec(novtable) IWiFiDirectServiceStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetSelector(hstring serviceName, hstring * serviceSelector) = 0;
    virtual HRESULT __stdcall abi_GetSelectorWithFilter(hstring serviceName, Windows::Storage::Streams::IBuffer * serviceInfoFilter, hstring * serviceSelector) = 0;
    virtual HRESULT __stdcall abi_FromIdAsync(hstring deviceId, Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::Services::WiFiDirectService> ** asyncOp) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Devices::WiFiDirect::Services::WiFiDirectService> { using default_interface = Windows::Devices::WiFiDirect::Services::IWiFiDirectService; };
template <> struct traits<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAdvertiser> { using default_interface = Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser; };
template <> struct traits<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAutoAcceptSessionConnectedEventArgs> { using default_interface = Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAutoAcceptSessionConnectedEventArgs; };
template <> struct traits<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceProvisioningInfo> { using default_interface = Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceProvisioningInfo; };
template <> struct traits<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceRemotePortAddedEventArgs> { using default_interface = Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceRemotePortAddedEventArgs; };
template <> struct traits<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession> { using default_interface = Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSession; };
template <> struct traits<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionDeferredEventArgs> { using default_interface = Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionDeferredEventArgs; };
template <> struct traits<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionRequest> { using default_interface = Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionRequest; };
template <> struct traits<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionRequestedEventArgs> { using default_interface = Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionRequestedEventArgs; };

}

namespace Windows::Devices::WiFiDirect::Services {

template <typename D>
struct WINRT_EBO impl_IWiFiDirectService
{
    Windows::Storage::Streams::IBuffer RemoteServiceInfo() const;
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceConfigurationMethod> SupportedConfigurationMethods() const;
    bool PreferGroupOwnerMode() const;
    void PreferGroupOwnerMode(bool value) const;
    Windows::Storage::Streams::IBuffer SessionInfo() const;
    void SessionInfo(const Windows::Storage::Streams::IBuffer & value) const;
    Windows::Devices::WiFiDirect::Services::WiFiDirectServiceError ServiceError() const;
    event_token SessionDeferred(const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectService, Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionDeferredEventArgs> & handler) const;
    using SessionDeferred_revoker = event_revoker<IWiFiDirectService>;
    SessionDeferred_revoker SessionDeferred(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectService, Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionDeferredEventArgs> & handler) const;
    void SessionDeferred(event_token token) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceProvisioningInfo> GetProvisioningInfoAsync(Windows::Devices::WiFiDirect::Services::WiFiDirectServiceConfigurationMethod selectedConfigurationMethod) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession> ConnectAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession> ConnectAsync(hstring_view pin) const;
};

template <typename D>
struct WINRT_EBO impl_IWiFiDirectServiceAdvertiser
{
    hstring ServiceName() const;
    Windows::Foundation::Collections::IVector<hstring> ServiceNamePrefixes() const;
    Windows::Storage::Streams::IBuffer ServiceInfo() const;
    void ServiceInfo(const Windows::Storage::Streams::IBuffer & value) const;
    bool AutoAcceptSession() const;
    void AutoAcceptSession(bool value) const;
    bool PreferGroupOwnerMode() const;
    void PreferGroupOwnerMode(bool value) const;
    Windows::Foundation::Collections::IVector<winrt::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceConfigurationMethod> PreferredConfigurationMethods() const;
    Windows::Devices::WiFiDirect::Services::WiFiDirectServiceStatus ServiceStatus() const;
    void ServiceStatus(Windows::Devices::WiFiDirect::Services::WiFiDirectServiceStatus value) const;
    uint32_t CustomServiceStatusCode() const;
    void CustomServiceStatusCode(uint32_t value) const;
    Windows::Storage::Streams::IBuffer DeferredSessionInfo() const;
    void DeferredSessionInfo(const Windows::Storage::Streams::IBuffer & value) const;
    Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAdvertisementStatus AdvertisementStatus() const;
    Windows::Devices::WiFiDirect::Services::WiFiDirectServiceError ServiceError() const;
    event_token SessionRequested(const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAdvertiser, Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionRequestedEventArgs> & handler) const;
    using SessionRequested_revoker = event_revoker<IWiFiDirectServiceAdvertiser>;
    SessionRequested_revoker SessionRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAdvertiser, Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionRequestedEventArgs> & handler) const;
    void SessionRequested(event_token token) const;
    event_token AutoAcceptSessionConnected(const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAdvertiser, Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAutoAcceptSessionConnectedEventArgs> & handler) const;
    using AutoAcceptSessionConnected_revoker = event_revoker<IWiFiDirectServiceAdvertiser>;
    AutoAcceptSessionConnected_revoker AutoAcceptSessionConnected(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAdvertiser, Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAutoAcceptSessionConnectedEventArgs> & handler) const;
    void AutoAcceptSessionConnected(event_token token) const;
    event_token AdvertisementStatusChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAdvertiser, Windows::Foundation::IInspectable> & handler) const;
    using AdvertisementStatusChanged_revoker = event_revoker<IWiFiDirectServiceAdvertiser>;
    AdvertisementStatusChanged_revoker AdvertisementStatusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAdvertiser, Windows::Foundation::IInspectable> & handler) const;
    void AdvertisementStatusChanged(event_token token) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession> ConnectAsync(const Windows::Devices::Enumeration::DeviceInformation & deviceInfo) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession> ConnectAsync(const Windows::Devices::Enumeration::DeviceInformation & deviceInfo, hstring_view pin) const;
    void Start() const;
    void Stop() const;
};

template <typename D>
struct WINRT_EBO impl_IWiFiDirectServiceAdvertiserFactory
{
    Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAdvertiser CreateWiFiDirectServiceAdvertiser(hstring_view serviceName) const;
};

template <typename D>
struct WINRT_EBO impl_IWiFiDirectServiceAutoAcceptSessionConnectedEventArgs
{
    Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession Session() const;
    Windows::Storage::Streams::IBuffer SessionInfo() const;
};

template <typename D>
struct WINRT_EBO impl_IWiFiDirectServiceProvisioningInfo
{
    Windows::Devices::WiFiDirect::Services::WiFiDirectServiceConfigurationMethod SelectedConfigurationMethod() const;
    bool IsGroupFormationNeeded() const;
};

template <typename D>
struct WINRT_EBO impl_IWiFiDirectServiceRemotePortAddedEventArgs
{
    Windows::Foundation::Collections::IVectorView<Windows::Networking::EndpointPair> EndpointPairs() const;
    Windows::Devices::WiFiDirect::Services::WiFiDirectServiceIPProtocol Protocol() const;
};

template <typename D>
struct WINRT_EBO impl_IWiFiDirectServiceSession
{
    hstring ServiceName() const;
    Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionStatus Status() const;
    Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionErrorStatus ErrorStatus() const;
    uint32_t SessionId() const;
    uint32_t AdvertisementId() const;
    hstring ServiceAddress() const;
    hstring SessionAddress() const;
    Windows::Foundation::Collections::IVectorView<Windows::Networking::EndpointPair> GetConnectionEndpointPairs() const;
    event_token SessionStatusChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession, Windows::Foundation::IInspectable> & handler) const;
    using SessionStatusChanged_revoker = event_revoker<IWiFiDirectServiceSession>;
    SessionStatusChanged_revoker SessionStatusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession, Windows::Foundation::IInspectable> & handler) const;
    void SessionStatusChanged(event_token token) const;
    Windows::Foundation::IAsyncAction AddStreamSocketListenerAsync(const Windows::Networking::Sockets::StreamSocketListener & value) const;
    Windows::Foundation::IAsyncAction AddDatagramSocketAsync(const Windows::Networking::Sockets::DatagramSocket & value) const;
    event_token RemotePortAdded(const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession, Windows::Devices::WiFiDirect::Services::WiFiDirectServiceRemotePortAddedEventArgs> & handler) const;
    using RemotePortAdded_revoker = event_revoker<IWiFiDirectServiceSession>;
    RemotePortAdded_revoker RemotePortAdded(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession, Windows::Devices::WiFiDirect::Services::WiFiDirectServiceRemotePortAddedEventArgs> & handler) const;
    void RemotePortAdded(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IWiFiDirectServiceSessionDeferredEventArgs
{
    Windows::Storage::Streams::IBuffer DeferredSessionInfo() const;
};

template <typename D>
struct WINRT_EBO impl_IWiFiDirectServiceSessionRequest
{
    Windows::Devices::Enumeration::DeviceInformation DeviceInformation() const;
    Windows::Devices::WiFiDirect::Services::WiFiDirectServiceProvisioningInfo ProvisioningInfo() const;
    Windows::Storage::Streams::IBuffer SessionInfo() const;
};

template <typename D>
struct WINRT_EBO impl_IWiFiDirectServiceSessionRequestedEventArgs
{
    Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionRequest GetSessionRequest() const;
};

template <typename D>
struct WINRT_EBO impl_IWiFiDirectServiceStatics
{
    hstring GetSelector(hstring_view serviceName) const;
    hstring GetSelector(hstring_view serviceName, const Windows::Storage::Streams::IBuffer & serviceInfoFilter) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::Services::WiFiDirectService> FromIdAsync(hstring_view deviceId) const;
};

}

namespace impl {

template <> struct traits<Windows::Devices::WiFiDirect::Services::IWiFiDirectService>
{
    using abi = ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectService;
    template <typename D> using consume = Windows::Devices::WiFiDirect::Services::impl_IWiFiDirectService<D>;
};

template <> struct traits<Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser>
{
    using abi = ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser;
    template <typename D> using consume = Windows::Devices::WiFiDirect::Services::impl_IWiFiDirectServiceAdvertiser<D>;
};

template <> struct traits<Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiserFactory>
{
    using abi = ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiserFactory;
    template <typename D> using consume = Windows::Devices::WiFiDirect::Services::impl_IWiFiDirectServiceAdvertiserFactory<D>;
};

template <> struct traits<Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAutoAcceptSessionConnectedEventArgs>
{
    using abi = ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAutoAcceptSessionConnectedEventArgs;
    template <typename D> using consume = Windows::Devices::WiFiDirect::Services::impl_IWiFiDirectServiceAutoAcceptSessionConnectedEventArgs<D>;
};

template <> struct traits<Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceProvisioningInfo>
{
    using abi = ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceProvisioningInfo;
    template <typename D> using consume = Windows::Devices::WiFiDirect::Services::impl_IWiFiDirectServiceProvisioningInfo<D>;
};

template <> struct traits<Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceRemotePortAddedEventArgs>
{
    using abi = ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceRemotePortAddedEventArgs;
    template <typename D> using consume = Windows::Devices::WiFiDirect::Services::impl_IWiFiDirectServiceRemotePortAddedEventArgs<D>;
};

template <> struct traits<Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSession>
{
    using abi = ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSession;
    template <typename D> using consume = Windows::Devices::WiFiDirect::Services::impl_IWiFiDirectServiceSession<D>;
};

template <> struct traits<Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionDeferredEventArgs>
{
    using abi = ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionDeferredEventArgs;
    template <typename D> using consume = Windows::Devices::WiFiDirect::Services::impl_IWiFiDirectServiceSessionDeferredEventArgs<D>;
};

template <> struct traits<Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionRequest>
{
    using abi = ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionRequest;
    template <typename D> using consume = Windows::Devices::WiFiDirect::Services::impl_IWiFiDirectServiceSessionRequest<D>;
};

template <> struct traits<Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionRequestedEventArgs>
{
    using abi = ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionRequestedEventArgs;
    template <typename D> using consume = Windows::Devices::WiFiDirect::Services::impl_IWiFiDirectServiceSessionRequestedEventArgs<D>;
};

template <> struct traits<Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceStatics>
{
    using abi = ABI::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceStatics;
    template <typename D> using consume = Windows::Devices::WiFiDirect::Services::impl_IWiFiDirectServiceStatics<D>;
};

template <> struct traits<Windows::Devices::WiFiDirect::Services::WiFiDirectService>
{
    using abi = ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectService;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.WiFiDirect.Services.WiFiDirectService"; }
};

template <> struct traits<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAdvertiser>
{
    using abi = ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAdvertiser;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.WiFiDirect.Services.WiFiDirectServiceAdvertiser"; }
};

template <> struct traits<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAutoAcceptSessionConnectedEventArgs>
{
    using abi = ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceAutoAcceptSessionConnectedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.WiFiDirect.Services.WiFiDirectServiceAutoAcceptSessionConnectedEventArgs"; }
};

template <> struct traits<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceProvisioningInfo>
{
    using abi = ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceProvisioningInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.WiFiDirect.Services.WiFiDirectServiceProvisioningInfo"; }
};

template <> struct traits<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceRemotePortAddedEventArgs>
{
    using abi = ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceRemotePortAddedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.WiFiDirect.Services.WiFiDirectServiceRemotePortAddedEventArgs"; }
};

template <> struct traits<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession>
{
    using abi = ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSession;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.WiFiDirect.Services.WiFiDirectServiceSession"; }
};

template <> struct traits<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionDeferredEventArgs>
{
    using abi = ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionDeferredEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.WiFiDirect.Services.WiFiDirectServiceSessionDeferredEventArgs"; }
};

template <> struct traits<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionRequest>
{
    using abi = ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.WiFiDirect.Services.WiFiDirectServiceSessionRequest"; }
};

template <> struct traits<Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionRequestedEventArgs>
{
    using abi = ABI::Windows::Devices::WiFiDirect::Services::WiFiDirectServiceSessionRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.WiFiDirect.Services.WiFiDirectServiceSessionRequestedEventArgs"; }
};

}

}
