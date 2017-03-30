// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Devices.Bluetooth.Rfcomm.0.h"
#include "Windows.Devices.Bluetooth.0.h"
#include "Windows.Devices.Enumeration.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Networking.0.h"
#include "Windows.Networking.Sockets.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"
#include "Windows.Storage.Streams.1.h"
#include "Windows.Devices.Enumeration.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Bluetooth::Rfcomm {

struct __declspec(uuid("ae81ff1f-c5a1-4c40-8c28-f3efd69062f3")) __declspec(novtable) IRfcommDeviceService : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ConnectionHostName(Windows::Networking::IHostName ** value) = 0;
    virtual HRESULT __stdcall get_ConnectionServiceName(hstring * value) = 0;
    virtual HRESULT __stdcall get_ServiceId(Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId ** value) = 0;
    virtual HRESULT __stdcall get_ProtectionLevel(winrt::Windows::Networking::Sockets::SocketProtectionLevel * value) = 0;
    virtual HRESULT __stdcall get_MaxProtectionLevel(winrt::Windows::Networking::Sockets::SocketProtectionLevel * value) = 0;
    virtual HRESULT __stdcall abi_GetSdpRawAttributesAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMapView<uint32_t, Windows::Storage::Streams::IBuffer>> ** asyncOp) = 0;
    virtual HRESULT __stdcall abi_GetSdpRawAttributesWithCacheModeAsync(winrt::Windows::Devices::Bluetooth::BluetoothCacheMode cacheMode, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMapView<uint32_t, Windows::Storage::Streams::IBuffer>> ** asyncOp) = 0;
};

struct __declspec(uuid("536ced14-ebcd-49fe-bf9f-40efc689b20d")) __declspec(novtable) IRfcommDeviceService2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Device(Windows::Devices::Bluetooth::IBluetoothDevice ** value) = 0;
};

struct __declspec(uuid("1c22ace6-dd44-4d23-866d-8f3486ee6490")) __declspec(novtable) IRfcommDeviceService3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceAccessInformation(Windows::Devices::Enumeration::IDeviceAccessInformation ** value) = 0;
    virtual HRESULT __stdcall abi_RequestAccessAsync(Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Enumeration::DeviceAccessStatus> ** value) = 0;
};

struct __declspec(uuid("a4a149ef-626d-41ac-b253-87ac5c27e28a")) __declspec(novtable) IRfcommDeviceServiceStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FromIdAsync(hstring deviceId, Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceService> ** asyncOp) = 0;
    virtual HRESULT __stdcall abi_GetDeviceSelector(Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId * serviceId, hstring * selector) = 0;
};

struct __declspec(uuid("aa8cb1c9-e78d-4be4-8076-0a3d87a0a05f")) __declspec(novtable) IRfcommDeviceServiceStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDeviceSelectorForBluetoothDevice(Windows::Devices::Bluetooth::IBluetoothDevice * bluetoothDevice, hstring * selector) = 0;
    virtual HRESULT __stdcall abi_GetDeviceSelectorForBluetoothDeviceWithCacheMode(Windows::Devices::Bluetooth::IBluetoothDevice * bluetoothDevice, winrt::Windows::Devices::Bluetooth::BluetoothCacheMode cacheMode, hstring * selector) = 0;
    virtual HRESULT __stdcall abi_GetDeviceSelectorForBluetoothDeviceAndServiceId(Windows::Devices::Bluetooth::IBluetoothDevice * bluetoothDevice, Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId * serviceId, hstring * selector) = 0;
    virtual HRESULT __stdcall abi_GetDeviceSelectorForBluetoothDeviceAndServiceIdWithCacheMode(Windows::Devices::Bluetooth::IBluetoothDevice * bluetoothDevice, Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId * serviceId, winrt::Windows::Devices::Bluetooth::BluetoothCacheMode cacheMode, hstring * selector) = 0;
};

struct __declspec(uuid("3b48388c-7ccf-488e-9625-d259a5732d55")) __declspec(novtable) IRfcommDeviceServicesResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Error(winrt::Windows::Devices::Bluetooth::BluetoothError * value) = 0;
    virtual HRESULT __stdcall get_Services(Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceService> ** services) = 0;
};

struct __declspec(uuid("22629204-7e02-4017-8136-da1b6a1b9bbf")) __declspec(novtable) IRfcommServiceId : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Uuid(GUID * value) = 0;
    virtual HRESULT __stdcall abi_AsShortId(uint32_t * shortId) = 0;
    virtual HRESULT __stdcall abi_AsString(hstring * id) = 0;
};

struct __declspec(uuid("2a179eba-a975-46e3-b56b-08ffd783a5fe")) __declspec(novtable) IRfcommServiceIdStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FromUuid(GUID uuid, Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId ** serviceId) = 0;
    virtual HRESULT __stdcall abi_FromShortId(uint32_t shortId, Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId ** serviceId) = 0;
    virtual HRESULT __stdcall get_SerialPort(Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId ** serviceId) = 0;
    virtual HRESULT __stdcall get_ObexObjectPush(Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId ** serviceId) = 0;
    virtual HRESULT __stdcall get_ObexFileTransfer(Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId ** serviceId) = 0;
    virtual HRESULT __stdcall get_PhoneBookAccessPce(Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId ** serviceId) = 0;
    virtual HRESULT __stdcall get_PhoneBookAccessPse(Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId ** serviceId) = 0;
    virtual HRESULT __stdcall get_GenericFileTransfer(Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId ** serviceId) = 0;
};

struct __declspec(uuid("eadbfdc4-b1f6-44ff-9f7c-e7a82ab86821")) __declspec(novtable) IRfcommServiceProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ServiceId(Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId ** value) = 0;
    virtual HRESULT __stdcall get_SdpRawAttributes(Windows::Foundation::Collections::IMap<uint32_t, Windows::Storage::Streams::IBuffer> ** value) = 0;
    virtual HRESULT __stdcall abi_StartAdvertising(Windows::Networking::Sockets::IStreamSocketListener * listener) = 0;
    virtual HRESULT __stdcall abi_StopAdvertising() = 0;
};

struct __declspec(uuid("736bdfc6-3c81-4d1e-baf2-ddbb81284512")) __declspec(novtable) IRfcommServiceProvider2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_StartAdvertisingWithRadioDiscoverability(Windows::Networking::Sockets::IStreamSocketListener * listener, bool radioDiscoverable) = 0;
};

struct __declspec(uuid("98888303-69ca-413a-84f7-4344c7292997")) __declspec(novtable) IRfcommServiceProviderStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateAsync(Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId * serviceId, Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommServiceProvider> ** asyncOp) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceService> { using default_interface = Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceService; };
template <> struct traits<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult> { using default_interface = Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceServicesResult; };
template <> struct traits<Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId> { using default_interface = Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId; };
template <> struct traits<Windows::Devices::Bluetooth::Rfcomm::RfcommServiceProvider> { using default_interface = Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceProvider; };

}

namespace Windows::Devices::Bluetooth::Rfcomm {

template <typename D>
struct WINRT_EBO impl_IRfcommDeviceService
{
    Windows::Networking::HostName ConnectionHostName() const;
    hstring ConnectionServiceName() const;
    Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId ServiceId() const;
    Windows::Networking::Sockets::SocketProtectionLevel ProtectionLevel() const;
    Windows::Networking::Sockets::SocketProtectionLevel MaxProtectionLevel() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMapView<uint32_t, Windows::Storage::Streams::IBuffer>> GetSdpRawAttributesAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMapView<uint32_t, Windows::Storage::Streams::IBuffer>> GetSdpRawAttributesAsync(Windows::Devices::Bluetooth::BluetoothCacheMode cacheMode) const;
};

template <typename D>
struct WINRT_EBO impl_IRfcommDeviceService2
{
    Windows::Devices::Bluetooth::BluetoothDevice Device() const;
};

template <typename D>
struct WINRT_EBO impl_IRfcommDeviceService3
{
    Windows::Devices::Enumeration::DeviceAccessInformation DeviceAccessInformation() const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Enumeration::DeviceAccessStatus> RequestAccessAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IRfcommDeviceServiceStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceService> FromIdAsync(hstring_view deviceId) const;
    hstring GetDeviceSelector(const Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId & serviceId) const;
};

template <typename D>
struct WINRT_EBO impl_IRfcommDeviceServiceStatics2
{
    hstring GetDeviceSelectorForBluetoothDevice(const Windows::Devices::Bluetooth::BluetoothDevice & bluetoothDevice) const;
    hstring GetDeviceSelectorForBluetoothDevice(const Windows::Devices::Bluetooth::BluetoothDevice & bluetoothDevice, Windows::Devices::Bluetooth::BluetoothCacheMode cacheMode) const;
    hstring GetDeviceSelectorForBluetoothDeviceAndServiceId(const Windows::Devices::Bluetooth::BluetoothDevice & bluetoothDevice, const Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId & serviceId) const;
    hstring GetDeviceSelectorForBluetoothDeviceAndServiceId(const Windows::Devices::Bluetooth::BluetoothDevice & bluetoothDevice, const Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId & serviceId, Windows::Devices::Bluetooth::BluetoothCacheMode cacheMode) const;
};

template <typename D>
struct WINRT_EBO impl_IRfcommDeviceServicesResult
{
    Windows::Devices::Bluetooth::BluetoothError Error() const;
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceService> Services() const;
};

template <typename D>
struct WINRT_EBO impl_IRfcommServiceId
{
    GUID Uuid() const;
    uint32_t AsShortId() const;
    hstring AsString() const;
};

template <typename D>
struct WINRT_EBO impl_IRfcommServiceIdStatics
{
    Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId FromUuid(GUID uuid) const;
    Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId FromShortId(uint32_t shortId) const;
    Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId SerialPort() const;
    Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId ObexObjectPush() const;
    Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId ObexFileTransfer() const;
    Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId PhoneBookAccessPce() const;
    Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId PhoneBookAccessPse() const;
    Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId GenericFileTransfer() const;
};

template <typename D>
struct WINRT_EBO impl_IRfcommServiceProvider
{
    Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId ServiceId() const;
    Windows::Foundation::Collections::IMap<uint32_t, Windows::Storage::Streams::IBuffer> SdpRawAttributes() const;
    void StartAdvertising(const Windows::Networking::Sockets::StreamSocketListener & listener) const;
    void StopAdvertising() const;
};

template <typename D>
struct WINRT_EBO impl_IRfcommServiceProvider2
{
    void StartAdvertising(const Windows::Networking::Sockets::StreamSocketListener & listener, bool radioDiscoverable) const;
};

template <typename D>
struct WINRT_EBO impl_IRfcommServiceProviderStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommServiceProvider> CreateAsync(const Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId & serviceId) const;
};

}

namespace impl {

template <> struct traits<Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceService>
{
    using abi = ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceService;
    template <typename D> using consume = Windows::Devices::Bluetooth::Rfcomm::impl_IRfcommDeviceService<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceService2>
{
    using abi = ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceService2;
    template <typename D> using consume = Windows::Devices::Bluetooth::Rfcomm::impl_IRfcommDeviceService2<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceService3>
{
    using abi = ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceService3;
    template <typename D> using consume = Windows::Devices::Bluetooth::Rfcomm::impl_IRfcommDeviceService3<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceServiceStatics>
{
    using abi = ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceServiceStatics;
    template <typename D> using consume = Windows::Devices::Bluetooth::Rfcomm::impl_IRfcommDeviceServiceStatics<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceServiceStatics2>
{
    using abi = ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceServiceStatics2;
    template <typename D> using consume = Windows::Devices::Bluetooth::Rfcomm::impl_IRfcommDeviceServiceStatics2<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceServicesResult>
{
    using abi = ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceServicesResult;
    template <typename D> using consume = Windows::Devices::Bluetooth::Rfcomm::impl_IRfcommDeviceServicesResult<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId>
{
    using abi = ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId;
    template <typename D> using consume = Windows::Devices::Bluetooth::Rfcomm::impl_IRfcommServiceId<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceIdStatics>
{
    using abi = ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceIdStatics;
    template <typename D> using consume = Windows::Devices::Bluetooth::Rfcomm::impl_IRfcommServiceIdStatics<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceProvider>
{
    using abi = ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceProvider;
    template <typename D> using consume = Windows::Devices::Bluetooth::Rfcomm::impl_IRfcommServiceProvider<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceProvider2>
{
    using abi = ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceProvider2;
    template <typename D> using consume = Windows::Devices::Bluetooth::Rfcomm::impl_IRfcommServiceProvider2<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceProviderStatics>
{
    using abi = ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceProviderStatics;
    template <typename D> using consume = Windows::Devices::Bluetooth::Rfcomm::impl_IRfcommServiceProviderStatics<D>;
};

template <> struct traits<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceService>
{
    using abi = ABI::Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceService;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.Rfcomm.RfcommDeviceService"; }
};

template <> struct traits<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult>
{
    using abi = ABI::Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.Rfcomm.RfcommDeviceServicesResult"; }
};

template <> struct traits<Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId>
{
    using abi = ABI::Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.Rfcomm.RfcommServiceId"; }
};

template <> struct traits<Windows::Devices::Bluetooth::Rfcomm::RfcommServiceProvider>
{
    using abi = ABI::Windows::Devices::Bluetooth::Rfcomm::RfcommServiceProvider;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Bluetooth.Rfcomm.RfcommServiceProvider"; }
};

}

}
