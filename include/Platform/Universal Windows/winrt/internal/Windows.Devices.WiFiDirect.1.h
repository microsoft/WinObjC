// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Devices.WiFiDirect.0.h"
#include "Windows.Devices.Enumeration.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Security.Credentials.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Networking.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::WiFiDirect {

struct __declspec(uuid("ab511a2d-2a06-49a1-a584-61435c7905a6")) __declspec(novtable) IWiFiDirectAdvertisement : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_InformationElements(Windows::Foundation::Collections::IVector<Windows::Devices::WiFiDirect::WiFiDirectInformationElement> ** value) = 0;
    virtual HRESULT __stdcall put_InformationElements(Windows::Foundation::Collections::IVector<Windows::Devices::WiFiDirect::WiFiDirectInformationElement> * value) = 0;
    virtual HRESULT __stdcall get_ListenStateDiscoverability(winrt::Windows::Devices::WiFiDirect::WiFiDirectAdvertisementListenStateDiscoverability * value) = 0;
    virtual HRESULT __stdcall put_ListenStateDiscoverability(winrt::Windows::Devices::WiFiDirect::WiFiDirectAdvertisementListenStateDiscoverability value) = 0;
    virtual HRESULT __stdcall get_IsAutonomousGroupOwnerEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsAutonomousGroupOwnerEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_LegacySettings(Windows::Devices::WiFiDirect::IWiFiDirectLegacySettings ** value) = 0;
};

struct __declspec(uuid("b759aa46-d816-491b-917a-b40d7dc403a2")) __declspec(novtable) IWiFiDirectAdvertisement2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SupportedConfigurationMethods(Windows::Foundation::Collections::IVector<winrt::Windows::Devices::WiFiDirect::WiFiDirectConfigurationMethod> ** value) = 0;
};

struct __declspec(uuid("b35a2d1a-9b1f-45d9-925a-694d66df68ef")) __declspec(novtable) IWiFiDirectAdvertisementPublisher : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Advertisement(Windows::Devices::WiFiDirect::IWiFiDirectAdvertisement ** value) = 0;
    virtual HRESULT __stdcall get_Status(winrt::Windows::Devices::WiFiDirect::WiFiDirectAdvertisementPublisherStatus * value) = 0;
    virtual HRESULT __stdcall add_StatusChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::WiFiDirectAdvertisementPublisher, Windows::Devices::WiFiDirect::WiFiDirectAdvertisementPublisherStatusChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_StatusChanged(event_token token) = 0;
    virtual HRESULT __stdcall abi_Start() = 0;
    virtual HRESULT __stdcall abi_Stop() = 0;
};

struct __declspec(uuid("aafde53c-5481-46e6-90dd-32116518f192")) __declspec(novtable) IWiFiDirectAdvertisementPublisherStatusChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Status(winrt::Windows::Devices::WiFiDirect::WiFiDirectAdvertisementPublisherStatus * value) = 0;
    virtual HRESULT __stdcall get_Error(winrt::Windows::Devices::WiFiDirect::WiFiDirectError * value) = 0;
};

struct __declspec(uuid("699c1b0d-8d13-4ee9-b9ec-9c72f8251f7d")) __declspec(novtable) IWiFiDirectConnectionListener : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_ConnectionRequested(Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::WiFiDirectConnectionListener, Windows::Devices::WiFiDirect::WiFiDirectConnectionRequestedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ConnectionRequested(event_token token) = 0;
};

struct __declspec(uuid("b2e55405-5702-4b16-a02c-bbcd21ef6098")) __declspec(novtable) IWiFiDirectConnectionParameters : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_GroupOwnerIntent(int16_t * value) = 0;
    virtual HRESULT __stdcall put_GroupOwnerIntent(int16_t value) = 0;
};

struct __declspec(uuid("ab3b0fbe-aa82-44b4-88c8-e3056b89801d")) __declspec(novtable) IWiFiDirectConnectionParameters2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PreferenceOrderedConfigurationMethods(Windows::Foundation::Collections::IVector<winrt::Windows::Devices::WiFiDirect::WiFiDirectConfigurationMethod> ** value) = 0;
    virtual HRESULT __stdcall get_PreferredPairingProcedure(winrt::Windows::Devices::WiFiDirect::WiFiDirectPairingProcedure * value) = 0;
    virtual HRESULT __stdcall put_PreferredPairingProcedure(winrt::Windows::Devices::WiFiDirect::WiFiDirectPairingProcedure value) = 0;
};

struct __declspec(uuid("598af493-7642-456f-b9d8-e8a9eb1f401a")) __declspec(novtable) IWiFiDirectConnectionParametersStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDevicePairingKinds(winrt::Windows::Devices::WiFiDirect::WiFiDirectConfigurationMethod configurationMethod, winrt::Windows::Devices::Enumeration::DevicePairingKinds * result) = 0;
};

struct __declspec(uuid("8eb99605-914f-49c3-a614-d18dc5b19b43")) __declspec(novtable) IWiFiDirectConnectionRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceInformation(Windows::Devices::Enumeration::IDeviceInformation ** value) = 0;
};

struct __declspec(uuid("f99d20be-d38d-484f-8215-e7b65abf244c")) __declspec(novtable) IWiFiDirectConnectionRequestedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetConnectionRequest(Windows::Devices::WiFiDirect::IWiFiDirectConnectionRequest ** result) = 0;
};

struct __declspec(uuid("72deaaa8-72eb-4dae-8a28-8513355d2777")) __declspec(novtable) IWiFiDirectDevice : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ConnectionStatus(winrt::Windows::Devices::WiFiDirect::WiFiDirectConnectionStatus * value) = 0;
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
    virtual HRESULT __stdcall add_ConnectionStatusChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::WiFiDirectDevice, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ConnectionStatusChanged(event_token token) = 0;
    virtual HRESULT __stdcall abi_GetConnectionEndpointPairs(Windows::Foundation::Collections::IVectorView<Windows::Networking::EndpointPair> ** value) = 0;
};

struct __declspec(uuid("e86cb57c-3aac-4851-a792-482aaf931b04")) __declspec(novtable) IWiFiDirectDeviceStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDeviceSelector(hstring * deviceSelector) = 0;
    virtual HRESULT __stdcall abi_FromIdAsync(hstring deviceId, Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::WiFiDirectDevice> ** asyncOp) = 0;
};

struct __declspec(uuid("1a953e49-b103-437e-9226-ab67971342f9")) __declspec(novtable) IWiFiDirectDeviceStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDeviceSelector(winrt::Windows::Devices::WiFiDirect::WiFiDirectDeviceSelectorType type, hstring * result) = 0;
    virtual HRESULT __stdcall abi_FromIdAsync(hstring deviceId, Windows::Devices::WiFiDirect::IWiFiDirectConnectionParameters * connectionParameters, Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::WiFiDirectDevice> ** result) = 0;
};

struct __declspec(uuid("affb72d6-76bb-497e-ac8b-dc72838bc309")) __declspec(novtable) IWiFiDirectInformationElement : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Oui(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall put_Oui(Windows::Storage::Streams::IBuffer * value) = 0;
    virtual HRESULT __stdcall get_OuiType(uint8_t * value) = 0;
    virtual HRESULT __stdcall put_OuiType(uint8_t value) = 0;
    virtual HRESULT __stdcall get_Value(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall put_Value(Windows::Storage::Streams::IBuffer * value) = 0;
};

struct __declspec(uuid("dbd02f16-11a5-4e60-8caa-34772148378a")) __declspec(novtable) IWiFiDirectInformationElementStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateFromBuffer(Windows::Storage::Streams::IBuffer * buffer, Windows::Foundation::Collections::IVector<Windows::Devices::WiFiDirect::WiFiDirectInformationElement> ** result) = 0;
    virtual HRESULT __stdcall abi_CreateFromDeviceInformation(Windows::Devices::Enumeration::IDeviceInformation * deviceInformation, Windows::Foundation::Collections::IVector<Windows::Devices::WiFiDirect::WiFiDirectInformationElement> ** result) = 0;
};

struct __declspec(uuid("a64fdbba-f2fd-4567-a91b-f5c2f5321057")) __declspec(novtable) IWiFiDirectLegacySettings : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_Ssid(hstring * value) = 0;
    virtual HRESULT __stdcall put_Ssid(hstring value) = 0;
    virtual HRESULT __stdcall get_Passphrase(Windows::Security::Credentials::IPasswordCredential ** value) = 0;
    virtual HRESULT __stdcall put_Passphrase(Windows::Security::Credentials::IPasswordCredential * value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Devices::WiFiDirect::WiFiDirectAdvertisement> { using default_interface = Windows::Devices::WiFiDirect::IWiFiDirectAdvertisement; };
template <> struct traits<Windows::Devices::WiFiDirect::WiFiDirectAdvertisementPublisher> { using default_interface = Windows::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisher; };
template <> struct traits<Windows::Devices::WiFiDirect::WiFiDirectAdvertisementPublisherStatusChangedEventArgs> { using default_interface = Windows::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisherStatusChangedEventArgs; };
template <> struct traits<Windows::Devices::WiFiDirect::WiFiDirectConnectionListener> { using default_interface = Windows::Devices::WiFiDirect::IWiFiDirectConnectionListener; };
template <> struct traits<Windows::Devices::WiFiDirect::WiFiDirectConnectionParameters> { using default_interface = Windows::Devices::WiFiDirect::IWiFiDirectConnectionParameters; };
template <> struct traits<Windows::Devices::WiFiDirect::WiFiDirectConnectionRequest> { using default_interface = Windows::Devices::WiFiDirect::IWiFiDirectConnectionRequest; };
template <> struct traits<Windows::Devices::WiFiDirect::WiFiDirectConnectionRequestedEventArgs> { using default_interface = Windows::Devices::WiFiDirect::IWiFiDirectConnectionRequestedEventArgs; };
template <> struct traits<Windows::Devices::WiFiDirect::WiFiDirectDevice> { using default_interface = Windows::Devices::WiFiDirect::IWiFiDirectDevice; };
template <> struct traits<Windows::Devices::WiFiDirect::WiFiDirectInformationElement> { using default_interface = Windows::Devices::WiFiDirect::IWiFiDirectInformationElement; };
template <> struct traits<Windows::Devices::WiFiDirect::WiFiDirectLegacySettings> { using default_interface = Windows::Devices::WiFiDirect::IWiFiDirectLegacySettings; };

}

namespace Windows::Devices::WiFiDirect {

template <typename D>
struct WINRT_EBO impl_IWiFiDirectAdvertisement
{
    Windows::Foundation::Collections::IVector<Windows::Devices::WiFiDirect::WiFiDirectInformationElement> InformationElements() const;
    void InformationElements(const Windows::Foundation::Collections::IVector<Windows::Devices::WiFiDirect::WiFiDirectInformationElement> & value) const;
    Windows::Devices::WiFiDirect::WiFiDirectAdvertisementListenStateDiscoverability ListenStateDiscoverability() const;
    void ListenStateDiscoverability(Windows::Devices::WiFiDirect::WiFiDirectAdvertisementListenStateDiscoverability value) const;
    bool IsAutonomousGroupOwnerEnabled() const;
    void IsAutonomousGroupOwnerEnabled(bool value) const;
    Windows::Devices::WiFiDirect::WiFiDirectLegacySettings LegacySettings() const;
};

template <typename D>
struct WINRT_EBO impl_IWiFiDirectAdvertisement2
{
    Windows::Foundation::Collections::IVector<winrt::Windows::Devices::WiFiDirect::WiFiDirectConfigurationMethod> SupportedConfigurationMethods() const;
};

template <typename D>
struct WINRT_EBO impl_IWiFiDirectAdvertisementPublisher
{
    Windows::Devices::WiFiDirect::WiFiDirectAdvertisement Advertisement() const;
    Windows::Devices::WiFiDirect::WiFiDirectAdvertisementPublisherStatus Status() const;
    event_token StatusChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::WiFiDirectAdvertisementPublisher, Windows::Devices::WiFiDirect::WiFiDirectAdvertisementPublisherStatusChangedEventArgs> & handler) const;
    using StatusChanged_revoker = event_revoker<IWiFiDirectAdvertisementPublisher>;
    StatusChanged_revoker StatusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::WiFiDirectAdvertisementPublisher, Windows::Devices::WiFiDirect::WiFiDirectAdvertisementPublisherStatusChangedEventArgs> & handler) const;
    void StatusChanged(event_token token) const;
    void Start() const;
    void Stop() const;
};

template <typename D>
struct WINRT_EBO impl_IWiFiDirectAdvertisementPublisherStatusChangedEventArgs
{
    Windows::Devices::WiFiDirect::WiFiDirectAdvertisementPublisherStatus Status() const;
    Windows::Devices::WiFiDirect::WiFiDirectError Error() const;
};

template <typename D>
struct WINRT_EBO impl_IWiFiDirectConnectionListener
{
    event_token ConnectionRequested(const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::WiFiDirectConnectionListener, Windows::Devices::WiFiDirect::WiFiDirectConnectionRequestedEventArgs> & handler) const;
    using ConnectionRequested_revoker = event_revoker<IWiFiDirectConnectionListener>;
    ConnectionRequested_revoker ConnectionRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::WiFiDirectConnectionListener, Windows::Devices::WiFiDirect::WiFiDirectConnectionRequestedEventArgs> & handler) const;
    void ConnectionRequested(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IWiFiDirectConnectionParameters
{
    int16_t GroupOwnerIntent() const;
    void GroupOwnerIntent(int16_t value) const;
};

template <typename D>
struct WINRT_EBO impl_IWiFiDirectConnectionParameters2
{
    Windows::Foundation::Collections::IVector<winrt::Windows::Devices::WiFiDirect::WiFiDirectConfigurationMethod> PreferenceOrderedConfigurationMethods() const;
    Windows::Devices::WiFiDirect::WiFiDirectPairingProcedure PreferredPairingProcedure() const;
    void PreferredPairingProcedure(Windows::Devices::WiFiDirect::WiFiDirectPairingProcedure value) const;
};

template <typename D>
struct WINRT_EBO impl_IWiFiDirectConnectionParametersStatics
{
    Windows::Devices::Enumeration::DevicePairingKinds GetDevicePairingKinds(Windows::Devices::WiFiDirect::WiFiDirectConfigurationMethod configurationMethod) const;
};

template <typename D>
struct WINRT_EBO impl_IWiFiDirectConnectionRequest
{
    Windows::Devices::Enumeration::DeviceInformation DeviceInformation() const;
};

template <typename D>
struct WINRT_EBO impl_IWiFiDirectConnectionRequestedEventArgs
{
    Windows::Devices::WiFiDirect::WiFiDirectConnectionRequest GetConnectionRequest() const;
};

template <typename D>
struct WINRT_EBO impl_IWiFiDirectDevice
{
    Windows::Devices::WiFiDirect::WiFiDirectConnectionStatus ConnectionStatus() const;
    hstring DeviceId() const;
    event_token ConnectionStatusChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::WiFiDirectDevice, Windows::Foundation::IInspectable> & handler) const;
    using ConnectionStatusChanged_revoker = event_revoker<IWiFiDirectDevice>;
    ConnectionStatusChanged_revoker ConnectionStatusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::WiFiDirect::WiFiDirectDevice, Windows::Foundation::IInspectable> & handler) const;
    void ConnectionStatusChanged(event_token token) const;
    Windows::Foundation::Collections::IVectorView<Windows::Networking::EndpointPair> GetConnectionEndpointPairs() const;
};

template <typename D>
struct WINRT_EBO impl_IWiFiDirectDeviceStatics
{
    hstring GetDeviceSelector() const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::WiFiDirectDevice> FromIdAsync(hstring_view deviceId) const;
};

template <typename D>
struct WINRT_EBO impl_IWiFiDirectDeviceStatics2
{
    hstring GetDeviceSelector(Windows::Devices::WiFiDirect::WiFiDirectDeviceSelectorType type) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::WiFiDirect::WiFiDirectDevice> FromIdAsync(hstring_view deviceId, const Windows::Devices::WiFiDirect::WiFiDirectConnectionParameters & connectionParameters) const;
};

template <typename D>
struct WINRT_EBO impl_IWiFiDirectInformationElement
{
    Windows::Storage::Streams::IBuffer Oui() const;
    void Oui(const Windows::Storage::Streams::IBuffer & value) const;
    uint8_t OuiType() const;
    void OuiType(uint8_t value) const;
    Windows::Storage::Streams::IBuffer Value() const;
    void Value(const Windows::Storage::Streams::IBuffer & value) const;
};

template <typename D>
struct WINRT_EBO impl_IWiFiDirectInformationElementStatics
{
    Windows::Foundation::Collections::IVector<Windows::Devices::WiFiDirect::WiFiDirectInformationElement> CreateFromBuffer(const Windows::Storage::Streams::IBuffer & buffer) const;
    Windows::Foundation::Collections::IVector<Windows::Devices::WiFiDirect::WiFiDirectInformationElement> CreateFromDeviceInformation(const Windows::Devices::Enumeration::DeviceInformation & deviceInformation) const;
};

template <typename D>
struct WINRT_EBO impl_IWiFiDirectLegacySettings
{
    bool IsEnabled() const;
    void IsEnabled(bool value) const;
    hstring Ssid() const;
    void Ssid(hstring_view value) const;
    Windows::Security::Credentials::PasswordCredential Passphrase() const;
    void Passphrase(const Windows::Security::Credentials::PasswordCredential & value) const;
};

}

namespace impl {

template <> struct traits<Windows::Devices::WiFiDirect::IWiFiDirectAdvertisement>
{
    using abi = ABI::Windows::Devices::WiFiDirect::IWiFiDirectAdvertisement;
    template <typename D> using consume = Windows::Devices::WiFiDirect::impl_IWiFiDirectAdvertisement<D>;
};

template <> struct traits<Windows::Devices::WiFiDirect::IWiFiDirectAdvertisement2>
{
    using abi = ABI::Windows::Devices::WiFiDirect::IWiFiDirectAdvertisement2;
    template <typename D> using consume = Windows::Devices::WiFiDirect::impl_IWiFiDirectAdvertisement2<D>;
};

template <> struct traits<Windows::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisher>
{
    using abi = ABI::Windows::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisher;
    template <typename D> using consume = Windows::Devices::WiFiDirect::impl_IWiFiDirectAdvertisementPublisher<D>;
};

template <> struct traits<Windows::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisherStatusChangedEventArgs>
{
    using abi = ABI::Windows::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisherStatusChangedEventArgs;
    template <typename D> using consume = Windows::Devices::WiFiDirect::impl_IWiFiDirectAdvertisementPublisherStatusChangedEventArgs<D>;
};

template <> struct traits<Windows::Devices::WiFiDirect::IWiFiDirectConnectionListener>
{
    using abi = ABI::Windows::Devices::WiFiDirect::IWiFiDirectConnectionListener;
    template <typename D> using consume = Windows::Devices::WiFiDirect::impl_IWiFiDirectConnectionListener<D>;
};

template <> struct traits<Windows::Devices::WiFiDirect::IWiFiDirectConnectionParameters>
{
    using abi = ABI::Windows::Devices::WiFiDirect::IWiFiDirectConnectionParameters;
    template <typename D> using consume = Windows::Devices::WiFiDirect::impl_IWiFiDirectConnectionParameters<D>;
};

template <> struct traits<Windows::Devices::WiFiDirect::IWiFiDirectConnectionParameters2>
{
    using abi = ABI::Windows::Devices::WiFiDirect::IWiFiDirectConnectionParameters2;
    template <typename D> using consume = Windows::Devices::WiFiDirect::impl_IWiFiDirectConnectionParameters2<D>;
};

template <> struct traits<Windows::Devices::WiFiDirect::IWiFiDirectConnectionParametersStatics>
{
    using abi = ABI::Windows::Devices::WiFiDirect::IWiFiDirectConnectionParametersStatics;
    template <typename D> using consume = Windows::Devices::WiFiDirect::impl_IWiFiDirectConnectionParametersStatics<D>;
};

template <> struct traits<Windows::Devices::WiFiDirect::IWiFiDirectConnectionRequest>
{
    using abi = ABI::Windows::Devices::WiFiDirect::IWiFiDirectConnectionRequest;
    template <typename D> using consume = Windows::Devices::WiFiDirect::impl_IWiFiDirectConnectionRequest<D>;
};

template <> struct traits<Windows::Devices::WiFiDirect::IWiFiDirectConnectionRequestedEventArgs>
{
    using abi = ABI::Windows::Devices::WiFiDirect::IWiFiDirectConnectionRequestedEventArgs;
    template <typename D> using consume = Windows::Devices::WiFiDirect::impl_IWiFiDirectConnectionRequestedEventArgs<D>;
};

template <> struct traits<Windows::Devices::WiFiDirect::IWiFiDirectDevice>
{
    using abi = ABI::Windows::Devices::WiFiDirect::IWiFiDirectDevice;
    template <typename D> using consume = Windows::Devices::WiFiDirect::impl_IWiFiDirectDevice<D>;
};

template <> struct traits<Windows::Devices::WiFiDirect::IWiFiDirectDeviceStatics>
{
    using abi = ABI::Windows::Devices::WiFiDirect::IWiFiDirectDeviceStatics;
    template <typename D> using consume = Windows::Devices::WiFiDirect::impl_IWiFiDirectDeviceStatics<D>;
};

template <> struct traits<Windows::Devices::WiFiDirect::IWiFiDirectDeviceStatics2>
{
    using abi = ABI::Windows::Devices::WiFiDirect::IWiFiDirectDeviceStatics2;
    template <typename D> using consume = Windows::Devices::WiFiDirect::impl_IWiFiDirectDeviceStatics2<D>;
};

template <> struct traits<Windows::Devices::WiFiDirect::IWiFiDirectInformationElement>
{
    using abi = ABI::Windows::Devices::WiFiDirect::IWiFiDirectInformationElement;
    template <typename D> using consume = Windows::Devices::WiFiDirect::impl_IWiFiDirectInformationElement<D>;
};

template <> struct traits<Windows::Devices::WiFiDirect::IWiFiDirectInformationElementStatics>
{
    using abi = ABI::Windows::Devices::WiFiDirect::IWiFiDirectInformationElementStatics;
    template <typename D> using consume = Windows::Devices::WiFiDirect::impl_IWiFiDirectInformationElementStatics<D>;
};

template <> struct traits<Windows::Devices::WiFiDirect::IWiFiDirectLegacySettings>
{
    using abi = ABI::Windows::Devices::WiFiDirect::IWiFiDirectLegacySettings;
    template <typename D> using consume = Windows::Devices::WiFiDirect::impl_IWiFiDirectLegacySettings<D>;
};

template <> struct traits<Windows::Devices::WiFiDirect::WiFiDirectAdvertisement>
{
    using abi = ABI::Windows::Devices::WiFiDirect::WiFiDirectAdvertisement;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.WiFiDirect.WiFiDirectAdvertisement"; }
};

template <> struct traits<Windows::Devices::WiFiDirect::WiFiDirectAdvertisementPublisher>
{
    using abi = ABI::Windows::Devices::WiFiDirect::WiFiDirectAdvertisementPublisher;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.WiFiDirect.WiFiDirectAdvertisementPublisher"; }
};

template <> struct traits<Windows::Devices::WiFiDirect::WiFiDirectAdvertisementPublisherStatusChangedEventArgs>
{
    using abi = ABI::Windows::Devices::WiFiDirect::WiFiDirectAdvertisementPublisherStatusChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.WiFiDirect.WiFiDirectAdvertisementPublisherStatusChangedEventArgs"; }
};

template <> struct traits<Windows::Devices::WiFiDirect::WiFiDirectConnectionListener>
{
    using abi = ABI::Windows::Devices::WiFiDirect::WiFiDirectConnectionListener;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.WiFiDirect.WiFiDirectConnectionListener"; }
};

template <> struct traits<Windows::Devices::WiFiDirect::WiFiDirectConnectionParameters>
{
    using abi = ABI::Windows::Devices::WiFiDirect::WiFiDirectConnectionParameters;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.WiFiDirect.WiFiDirectConnectionParameters"; }
};

template <> struct traits<Windows::Devices::WiFiDirect::WiFiDirectConnectionRequest>
{
    using abi = ABI::Windows::Devices::WiFiDirect::WiFiDirectConnectionRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.WiFiDirect.WiFiDirectConnectionRequest"; }
};

template <> struct traits<Windows::Devices::WiFiDirect::WiFiDirectConnectionRequestedEventArgs>
{
    using abi = ABI::Windows::Devices::WiFiDirect::WiFiDirectConnectionRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.WiFiDirect.WiFiDirectConnectionRequestedEventArgs"; }
};

template <> struct traits<Windows::Devices::WiFiDirect::WiFiDirectDevice>
{
    using abi = ABI::Windows::Devices::WiFiDirect::WiFiDirectDevice;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.WiFiDirect.WiFiDirectDevice"; }
};

template <> struct traits<Windows::Devices::WiFiDirect::WiFiDirectInformationElement>
{
    using abi = ABI::Windows::Devices::WiFiDirect::WiFiDirectInformationElement;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.WiFiDirect.WiFiDirectInformationElement"; }
};

template <> struct traits<Windows::Devices::WiFiDirect::WiFiDirectLegacySettings>
{
    using abi = ABI::Windows::Devices::WiFiDirect::WiFiDirectLegacySettings;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.WiFiDirect.WiFiDirectLegacySettings"; }
};

}

}
