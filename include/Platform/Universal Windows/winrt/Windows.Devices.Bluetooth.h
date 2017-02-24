// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Networking.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Devices.Enumeration.3.h"
#include "internal/Windows.Devices.Bluetooth.Rfcomm.3.h"
#include "internal/Windows.Devices.Bluetooth.GenericAttributeProfile.3.h"
#include "internal/Windows.Devices.Bluetooth.3.h"
#include "Windows.Devices.h"
#include "Windows.Foundation.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::IBluetoothClassOfDevice> : produce_base<D, Windows::Devices::Bluetooth::IBluetoothClassOfDevice>
{
    HRESULT __stdcall get_RawValue(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RawValue());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MajorClass(Windows::Devices::Bluetooth::BluetoothMajorClass * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MajorClass());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinorClass(Windows::Devices::Bluetooth::BluetoothMinorClass * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinorClass());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServiceCapabilities(Windows::Devices::Bluetooth::BluetoothServiceCapabilities * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServiceCapabilities());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::IBluetoothClassOfDeviceStatics> : produce_base<D, Windows::Devices::Bluetooth::IBluetoothClassOfDeviceStatics>
{
    HRESULT __stdcall abi_FromRawValue(uint32_t rawValue, impl::abi_arg_out<Windows::Devices::Bluetooth::IBluetoothClassOfDevice> classOfDevice) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *classOfDevice = detach_abi(this->shim().FromRawValue(rawValue));
            return S_OK;
        }
        catch (...)
        {
            *classOfDevice = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromParts(Windows::Devices::Bluetooth::BluetoothMajorClass majorClass, Windows::Devices::Bluetooth::BluetoothMinorClass minorClass, Windows::Devices::Bluetooth::BluetoothServiceCapabilities serviceCapabilities, impl::abi_arg_out<Windows::Devices::Bluetooth::IBluetoothClassOfDevice> classOfDevice) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *classOfDevice = detach_abi(this->shim().FromParts(majorClass, minorClass, serviceCapabilities));
            return S_OK;
        }
        catch (...)
        {
            *classOfDevice = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::IBluetoothDevice> : produce_base<D, Windows::Devices::Bluetooth::IBluetoothDevice>
{
    HRESULT __stdcall get_DeviceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HostName(impl::abi_arg_out<Windows::Networking::IHostName> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HostName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Name(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ClassOfDevice(impl::abi_arg_out<Windows::Devices::Bluetooth::IBluetoothClassOfDevice> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ClassOfDevice());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SdpRecords(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Storage::Streams::IBuffer>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SdpRecords());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RfcommServices(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceService>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RfcommServices());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ConnectionStatus(Windows::Devices::Bluetooth::BluetoothConnectionStatus * value) noexcept override
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

    HRESULT __stdcall get_BluetoothAddress(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BluetoothAddress());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_NameChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothDevice, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().NameChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothDevice, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_NameChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NameChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_SdpRecordsChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothDevice, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().SdpRecordsChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothDevice, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SdpRecordsChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SdpRecordsChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ConnectionStatusChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothDevice, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ConnectionStatusChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothDevice, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ConnectionStatusChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ConnectionStatusChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::IBluetoothDevice2> : produce_base<D, Windows::Devices::Bluetooth::IBluetoothDevice2>
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
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::IBluetoothDevice3> : produce_base<D, Windows::Devices::Bluetooth::IBluetoothDevice3>
{
    HRESULT __stdcall get_DeviceAccessInformation(impl::abi_arg_out<Windows::Devices::Enumeration::IDeviceAccessInformation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceAccessInformation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestAccessAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Enumeration::DeviceAccessStatus>> value) noexcept override
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

    HRESULT __stdcall abi_GetRfcommServicesAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetRfcommServicesAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetRfcommServicesWithCacheModeAsync(Windows::Devices::Bluetooth::BluetoothCacheMode cacheMode, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetRfcommServicesAsync(cacheMode));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetRfcommServicesForIdAsync(impl::abi_arg_in<Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId> serviceId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetRfcommServicesForIdAsync(*reinterpret_cast<const Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId *>(&serviceId)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetRfcommServicesForIdWithCacheModeAsync(impl::abi_arg_in<Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId> serviceId, Windows::Devices::Bluetooth::BluetoothCacheMode cacheMode, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetRfcommServicesForIdAsync(*reinterpret_cast<const Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId *>(&serviceId), cacheMode));
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
struct produce<D, Windows::Devices::Bluetooth::IBluetoothDeviceStatics> : produce_base<D, Windows::Devices::Bluetooth::IBluetoothDeviceStatics>
{
    HRESULT __stdcall abi_FromIdAsync(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothDevice>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FromIdAsync(*reinterpret_cast<const hstring *>(&deviceId)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromHostNameAsync(impl::abi_arg_in<Windows::Networking::IHostName> hostName, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothDevice>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FromHostNameAsync(*reinterpret_cast<const Windows::Networking::HostName *>(&hostName)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromBluetoothAddressAsync(uint64_t address, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothDevice>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FromBluetoothAddressAsync(address));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
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
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::IBluetoothDeviceStatics2> : produce_base<D, Windows::Devices::Bluetooth::IBluetoothDeviceStatics2>
{
    HRESULT __stdcall abi_GetDeviceSelectorFromPairingState(bool pairingState, impl::abi_arg_out<hstring> deviceSelector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deviceSelector = detach_abi(this->shim().GetDeviceSelectorFromPairingState(pairingState));
            return S_OK;
        }
        catch (...)
        {
            *deviceSelector = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelectorFromConnectionStatus(Windows::Devices::Bluetooth::BluetoothConnectionStatus connectionStatus, impl::abi_arg_out<hstring> deviceSelector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deviceSelector = detach_abi(this->shim().GetDeviceSelectorFromConnectionStatus(connectionStatus));
            return S_OK;
        }
        catch (...)
        {
            *deviceSelector = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelectorFromDeviceName(impl::abi_arg_in<hstring> deviceName, impl::abi_arg_out<hstring> deviceSelector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deviceSelector = detach_abi(this->shim().GetDeviceSelectorFromDeviceName(*reinterpret_cast<const hstring *>(&deviceName)));
            return S_OK;
        }
        catch (...)
        {
            *deviceSelector = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelectorFromBluetoothAddress(uint64_t bluetoothAddress, impl::abi_arg_out<hstring> deviceSelector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deviceSelector = detach_abi(this->shim().GetDeviceSelectorFromBluetoothAddress(bluetoothAddress));
            return S_OK;
        }
        catch (...)
        {
            *deviceSelector = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelectorFromClassOfDevice(impl::abi_arg_in<Windows::Devices::Bluetooth::IBluetoothClassOfDevice> classOfDevice, impl::abi_arg_out<hstring> deviceSelector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deviceSelector = detach_abi(this->shim().GetDeviceSelectorFromClassOfDevice(*reinterpret_cast<const Windows::Devices::Bluetooth::BluetoothClassOfDevice *>(&classOfDevice)));
            return S_OK;
        }
        catch (...)
        {
            *deviceSelector = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::IBluetoothLEAppearance> : produce_base<D, Windows::Devices::Bluetooth::IBluetoothLEAppearance>
{
    HRESULT __stdcall get_RawValue(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RawValue());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Category(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Category());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SubCategory(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SubCategory());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::IBluetoothLEAppearanceCategoriesStatics> : produce_base<D, Windows::Devices::Bluetooth::IBluetoothLEAppearanceCategoriesStatics>
{
    HRESULT __stdcall get_Uncategorized(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Uncategorized());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Phone(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Phone());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Computer(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Computer());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Watch(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Watch());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Clock(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Clock());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Display(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Display());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RemoteControl(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemoteControl());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EyeGlasses(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EyeGlasses());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Tag(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Tag());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Keyring(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Keyring());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MediaPlayer(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MediaPlayer());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BarcodeScanner(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BarcodeScanner());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Thermometer(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Thermometer());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HeartRate(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HeartRate());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BloodPressure(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BloodPressure());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HumanInterfaceDevice(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HumanInterfaceDevice());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GlucoseMeter(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GlucoseMeter());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RunningWalking(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RunningWalking());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Cycling(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Cycling());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PulseOximeter(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PulseOximeter());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WeightScale(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WeightScale());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OutdoorSportActivity(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OutdoorSportActivity());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::IBluetoothLEAppearanceStatics> : produce_base<D, Windows::Devices::Bluetooth::IBluetoothLEAppearanceStatics>
{
    HRESULT __stdcall abi_FromRawValue(uint16_t rawValue, impl::abi_arg_out<Windows::Devices::Bluetooth::IBluetoothLEAppearance> appearance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *appearance = detach_abi(this->shim().FromRawValue(rawValue));
            return S_OK;
        }
        catch (...)
        {
            *appearance = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromParts(uint16_t appearanceCategory, uint16_t appearanceSubCategory, impl::abi_arg_out<Windows::Devices::Bluetooth::IBluetoothLEAppearance> appearance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *appearance = detach_abi(this->shim().FromParts(appearanceCategory, appearanceSubCategory));
            return S_OK;
        }
        catch (...)
        {
            *appearance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::IBluetoothLEAppearanceSubcategoriesStatics> : produce_base<D, Windows::Devices::Bluetooth::IBluetoothLEAppearanceSubcategoriesStatics>
{
    HRESULT __stdcall get_Generic(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Generic());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SportsWatch(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SportsWatch());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ThermometerEar(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ThermometerEar());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HeartRateBelt(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HeartRateBelt());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BloodPressureArm(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BloodPressureArm());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BloodPressureWrist(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BloodPressureWrist());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Keyboard(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Keyboard());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Mouse(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Mouse());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Joystick(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Joystick());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Gamepad(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Gamepad());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DigitizerTablet(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DigitizerTablet());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CardReader(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CardReader());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DigitalPen(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DigitalPen());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BarcodeScanner(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BarcodeScanner());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RunningWalkingInShoe(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RunningWalkingInShoe());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RunningWalkingOnShoe(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RunningWalkingOnShoe());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RunningWalkingOnHip(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RunningWalkingOnHip());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CyclingComputer(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CyclingComputer());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CyclingSpeedSensor(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CyclingSpeedSensor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CyclingCadenceSensor(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CyclingCadenceSensor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CyclingPowerSensor(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CyclingPowerSensor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CyclingSpeedCadenceSensor(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CyclingSpeedCadenceSensor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OximeterFingertip(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OximeterFingertip());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OximeterWristWorn(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OximeterWristWorn());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LocationDisplay(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LocationDisplay());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LocationNavigationDisplay(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LocationNavigationDisplay());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LocationPod(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LocationPod());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LocationNavigationPod(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LocationNavigationPod());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::IBluetoothLEDevice> : produce_base<D, Windows::Devices::Bluetooth::IBluetoothLEDevice>
{
    HRESULT __stdcall get_DeviceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Name(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GattServices(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceService>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GattServices());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ConnectionStatus(Windows::Devices::Bluetooth::BluetoothConnectionStatus * value) noexcept override
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

    HRESULT __stdcall get_BluetoothAddress(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BluetoothAddress());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetGattService(GUID serviceUuid, impl::abi_arg_out<Windows::Devices::Bluetooth::GenericAttributeProfile::IGattDeviceService> service) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *service = detach_abi(this->shim().GetGattService(serviceUuid));
            return S_OK;
        }
        catch (...)
        {
            *service = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_NameChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothLEDevice, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().NameChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothLEDevice, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_NameChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NameChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_GattServicesChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothLEDevice, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().GattServicesChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothLEDevice, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_GattServicesChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GattServicesChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ConnectionStatusChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothLEDevice, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ConnectionStatusChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothLEDevice, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ConnectionStatusChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ConnectionStatusChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::IBluetoothLEDevice2> : produce_base<D, Windows::Devices::Bluetooth::IBluetoothLEDevice2>
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

    HRESULT __stdcall get_Appearance(impl::abi_arg_out<Windows::Devices::Bluetooth::IBluetoothLEAppearance> value) noexcept override
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

    HRESULT __stdcall get_BluetoothAddressType(Windows::Devices::Bluetooth::BluetoothAddressType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BluetoothAddressType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::IBluetoothLEDeviceStatics> : produce_base<D, Windows::Devices::Bluetooth::IBluetoothLEDeviceStatics>
{
    HRESULT __stdcall abi_FromIdAsync(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothLEDevice>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FromIdAsync(*reinterpret_cast<const hstring *>(&deviceId)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromBluetoothAddressAsync(uint64_t bluetoothAddress, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothLEDevice>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FromBluetoothAddressAsync(bluetoothAddress));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
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
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::IBluetoothLEDeviceStatics2> : produce_base<D, Windows::Devices::Bluetooth::IBluetoothLEDeviceStatics2>
{
    HRESULT __stdcall abi_GetDeviceSelectorFromPairingState(bool pairingState, impl::abi_arg_out<hstring> deviceSelector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deviceSelector = detach_abi(this->shim().GetDeviceSelectorFromPairingState(pairingState));
            return S_OK;
        }
        catch (...)
        {
            *deviceSelector = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelectorFromConnectionStatus(Windows::Devices::Bluetooth::BluetoothConnectionStatus connectionStatus, impl::abi_arg_out<hstring> deviceSelector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deviceSelector = detach_abi(this->shim().GetDeviceSelectorFromConnectionStatus(connectionStatus));
            return S_OK;
        }
        catch (...)
        {
            *deviceSelector = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelectorFromDeviceName(impl::abi_arg_in<hstring> deviceName, impl::abi_arg_out<hstring> deviceSelector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deviceSelector = detach_abi(this->shim().GetDeviceSelectorFromDeviceName(*reinterpret_cast<const hstring *>(&deviceName)));
            return S_OK;
        }
        catch (...)
        {
            *deviceSelector = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelectorFromBluetoothAddress(uint64_t bluetoothAddress, impl::abi_arg_out<hstring> deviceSelector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deviceSelector = detach_abi(this->shim().GetDeviceSelectorFromBluetoothAddress(bluetoothAddress));
            return S_OK;
        }
        catch (...)
        {
            *deviceSelector = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelectorFromBluetoothAddressWithBluetoothAddressType(uint64_t bluetoothAddress, Windows::Devices::Bluetooth::BluetoothAddressType bluetoothAddressType, impl::abi_arg_out<hstring> deviceSelector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deviceSelector = detach_abi(this->shim().GetDeviceSelectorFromBluetoothAddress(bluetoothAddress, bluetoothAddressType));
            return S_OK;
        }
        catch (...)
        {
            *deviceSelector = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelectorFromAppearance(impl::abi_arg_in<Windows::Devices::Bluetooth::IBluetoothLEAppearance> appearance, impl::abi_arg_out<hstring> deviceSelector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deviceSelector = detach_abi(this->shim().GetDeviceSelectorFromAppearance(*reinterpret_cast<const Windows::Devices::Bluetooth::BluetoothLEAppearance *>(&appearance)));
            return S_OK;
        }
        catch (...)
        {
            *deviceSelector = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromBluetoothAddressWithBluetoothAddressTypeAsync(uint64_t bluetoothAddress, Windows::Devices::Bluetooth::BluetoothAddressType bluetoothAddressType, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothLEDevice>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FromBluetoothAddressAsync(bluetoothAddress, bluetoothAddressType));
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
struct produce<D, Windows::Devices::Bluetooth::IBluetoothSignalStrengthFilter> : produce_base<D, Windows::Devices::Bluetooth::IBluetoothSignalStrengthFilter>
{
    HRESULT __stdcall get_InRangeThresholdInDBm(impl::abi_arg_out<Windows::Foundation::IReference<int16_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InRangeThresholdInDBm());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_InRangeThresholdInDBm(impl::abi_arg_in<Windows::Foundation::IReference<int16_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InRangeThresholdInDBm(*reinterpret_cast<const Windows::Foundation::IReference<int16_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OutOfRangeThresholdInDBm(impl::abi_arg_out<Windows::Foundation::IReference<int16_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OutOfRangeThresholdInDBm());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OutOfRangeThresholdInDBm(impl::abi_arg_in<Windows::Foundation::IReference<int16_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OutOfRangeThresholdInDBm(*reinterpret_cast<const Windows::Foundation::IReference<int16_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OutOfRangeTimeout(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OutOfRangeTimeout());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OutOfRangeTimeout(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OutOfRangeTimeout(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::TimeSpan> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SamplingInterval(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SamplingInterval());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SamplingInterval(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SamplingInterval(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::TimeSpan> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Devices::Bluetooth {

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothDevice> impl_IBluetoothDeviceStatics<D>::FromIdAsync(hstring_view deviceId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothDevice> operation;
    check_hresult(WINRT_SHIM(IBluetoothDeviceStatics)->abi_FromIdAsync(get_abi(deviceId), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothDevice> impl_IBluetoothDeviceStatics<D>::FromHostNameAsync(const Windows::Networking::HostName & hostName) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothDevice> operation;
    check_hresult(WINRT_SHIM(IBluetoothDeviceStatics)->abi_FromHostNameAsync(get_abi(hostName), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothDevice> impl_IBluetoothDeviceStatics<D>::FromBluetoothAddressAsync(uint64_t address) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothDevice> operation;
    check_hresult(WINRT_SHIM(IBluetoothDeviceStatics)->abi_FromBluetoothAddressAsync(address, put_abi(operation)));
    return operation;
}

template <typename D> hstring impl_IBluetoothDeviceStatics<D>::GetDeviceSelector() const
{
    hstring deviceSelector;
    check_hresult(WINRT_SHIM(IBluetoothDeviceStatics)->abi_GetDeviceSelector(put_abi(deviceSelector)));
    return deviceSelector;
}

template <typename D> hstring impl_IBluetoothDeviceStatics2<D>::GetDeviceSelectorFromPairingState(bool pairingState) const
{
    hstring deviceSelector;
    check_hresult(WINRT_SHIM(IBluetoothDeviceStatics2)->abi_GetDeviceSelectorFromPairingState(pairingState, put_abi(deviceSelector)));
    return deviceSelector;
}

template <typename D> hstring impl_IBluetoothDeviceStatics2<D>::GetDeviceSelectorFromConnectionStatus(Windows::Devices::Bluetooth::BluetoothConnectionStatus connectionStatus) const
{
    hstring deviceSelector;
    check_hresult(WINRT_SHIM(IBluetoothDeviceStatics2)->abi_GetDeviceSelectorFromConnectionStatus(connectionStatus, put_abi(deviceSelector)));
    return deviceSelector;
}

template <typename D> hstring impl_IBluetoothDeviceStatics2<D>::GetDeviceSelectorFromDeviceName(hstring_view deviceName) const
{
    hstring deviceSelector;
    check_hresult(WINRT_SHIM(IBluetoothDeviceStatics2)->abi_GetDeviceSelectorFromDeviceName(get_abi(deviceName), put_abi(deviceSelector)));
    return deviceSelector;
}

template <typename D> hstring impl_IBluetoothDeviceStatics2<D>::GetDeviceSelectorFromBluetoothAddress(uint64_t bluetoothAddress) const
{
    hstring deviceSelector;
    check_hresult(WINRT_SHIM(IBluetoothDeviceStatics2)->abi_GetDeviceSelectorFromBluetoothAddress(bluetoothAddress, put_abi(deviceSelector)));
    return deviceSelector;
}

template <typename D> hstring impl_IBluetoothDeviceStatics2<D>::GetDeviceSelectorFromClassOfDevice(const Windows::Devices::Bluetooth::BluetoothClassOfDevice & classOfDevice) const
{
    hstring deviceSelector;
    check_hresult(WINRT_SHIM(IBluetoothDeviceStatics2)->abi_GetDeviceSelectorFromClassOfDevice(get_abi(classOfDevice), put_abi(deviceSelector)));
    return deviceSelector;
}

template <typename D> hstring impl_IBluetoothDevice<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IBluetoothDevice)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::HostName impl_IBluetoothDevice<D>::HostName() const
{
    Windows::Networking::HostName value { nullptr };
    check_hresult(WINRT_SHIM(IBluetoothDevice)->get_HostName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IBluetoothDevice<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IBluetoothDevice)->get_Name(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Bluetooth::BluetoothClassOfDevice impl_IBluetoothDevice<D>::ClassOfDevice() const
{
    Windows::Devices::Bluetooth::BluetoothClassOfDevice value { nullptr };
    check_hresult(WINRT_SHIM(IBluetoothDevice)->get_ClassOfDevice(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Storage::Streams::IBuffer> impl_IBluetoothDevice<D>::SdpRecords() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Storage::Streams::IBuffer> value;
    check_hresult(WINRT_SHIM(IBluetoothDevice)->get_SdpRecords(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceService> impl_IBluetoothDevice<D>::RfcommServices() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceService> value;
    check_hresult(WINRT_SHIM(IBluetoothDevice)->get_RfcommServices(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Bluetooth::BluetoothConnectionStatus impl_IBluetoothDevice<D>::ConnectionStatus() const
{
    Windows::Devices::Bluetooth::BluetoothConnectionStatus value {};
    check_hresult(WINRT_SHIM(IBluetoothDevice)->get_ConnectionStatus(&value));
    return value;
}

template <typename D> uint64_t impl_IBluetoothDevice<D>::BluetoothAddress() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IBluetoothDevice)->get_BluetoothAddress(&value));
    return value;
}

template <typename D> event_token impl_IBluetoothDevice<D>::NameChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothDevice, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IBluetoothDevice)->add_NameChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IBluetoothDevice> impl_IBluetoothDevice<D>::NameChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothDevice, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IBluetoothDevice>(this, &ABI::Windows::Devices::Bluetooth::IBluetoothDevice::remove_NameChanged, NameChanged(handler));
}

template <typename D> void impl_IBluetoothDevice<D>::NameChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IBluetoothDevice)->remove_NameChanged(token));
}

template <typename D> event_token impl_IBluetoothDevice<D>::SdpRecordsChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothDevice, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IBluetoothDevice)->add_SdpRecordsChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IBluetoothDevice> impl_IBluetoothDevice<D>::SdpRecordsChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothDevice, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IBluetoothDevice>(this, &ABI::Windows::Devices::Bluetooth::IBluetoothDevice::remove_SdpRecordsChanged, SdpRecordsChanged(handler));
}

template <typename D> void impl_IBluetoothDevice<D>::SdpRecordsChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IBluetoothDevice)->remove_SdpRecordsChanged(token));
}

template <typename D> event_token impl_IBluetoothDevice<D>::ConnectionStatusChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothDevice, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IBluetoothDevice)->add_ConnectionStatusChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IBluetoothDevice> impl_IBluetoothDevice<D>::ConnectionStatusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothDevice, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IBluetoothDevice>(this, &ABI::Windows::Devices::Bluetooth::IBluetoothDevice::remove_ConnectionStatusChanged, ConnectionStatusChanged(handler));
}

template <typename D> void impl_IBluetoothDevice<D>::ConnectionStatusChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IBluetoothDevice)->remove_ConnectionStatusChanged(token));
}

template <typename D> Windows::Devices::Enumeration::DeviceInformation impl_IBluetoothDevice2<D>::DeviceInformation() const
{
    Windows::Devices::Enumeration::DeviceInformation value { nullptr };
    check_hresult(WINRT_SHIM(IBluetoothDevice2)->get_DeviceInformation(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Enumeration::DeviceAccessInformation impl_IBluetoothDevice3<D>::DeviceAccessInformation() const
{
    Windows::Devices::Enumeration::DeviceAccessInformation value { nullptr };
    check_hresult(WINRT_SHIM(IBluetoothDevice3)->get_DeviceAccessInformation(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Enumeration::DeviceAccessStatus> impl_IBluetoothDevice3<D>::RequestAccessAsync() const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Enumeration::DeviceAccessStatus> value;
    check_hresult(WINRT_SHIM(IBluetoothDevice3)->abi_RequestAccessAsync(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult> impl_IBluetoothDevice3<D>::GetRfcommServicesAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult> operation;
    check_hresult(WINRT_SHIM(IBluetoothDevice3)->abi_GetRfcommServicesAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult> impl_IBluetoothDevice3<D>::GetRfcommServicesAsync(Windows::Devices::Bluetooth::BluetoothCacheMode cacheMode) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult> operation;
    check_hresult(WINRT_SHIM(IBluetoothDevice3)->abi_GetRfcommServicesWithCacheModeAsync(cacheMode, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult> impl_IBluetoothDevice3<D>::GetRfcommServicesForIdAsync(const Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId & serviceId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult> operation;
    check_hresult(WINRT_SHIM(IBluetoothDevice3)->abi_GetRfcommServicesForIdAsync(get_abi(serviceId), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult> impl_IBluetoothDevice3<D>::GetRfcommServicesForIdAsync(const Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId & serviceId, Windows::Devices::Bluetooth::BluetoothCacheMode cacheMode) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceServicesResult> operation;
    check_hresult(WINRT_SHIM(IBluetoothDevice3)->abi_GetRfcommServicesForIdWithCacheModeAsync(get_abi(serviceId), cacheMode, put_abi(operation)));
    return operation;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::Uncategorized() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceCategoriesStatics)->get_Uncategorized(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::Phone() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceCategoriesStatics)->get_Phone(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::Computer() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceCategoriesStatics)->get_Computer(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::Watch() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceCategoriesStatics)->get_Watch(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::Clock() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceCategoriesStatics)->get_Clock(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::Display() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceCategoriesStatics)->get_Display(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::RemoteControl() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceCategoriesStatics)->get_RemoteControl(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::EyeGlasses() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceCategoriesStatics)->get_EyeGlasses(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::Tag() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceCategoriesStatics)->get_Tag(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::Keyring() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceCategoriesStatics)->get_Keyring(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::MediaPlayer() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceCategoriesStatics)->get_MediaPlayer(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::BarcodeScanner() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceCategoriesStatics)->get_BarcodeScanner(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::Thermometer() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceCategoriesStatics)->get_Thermometer(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::HeartRate() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceCategoriesStatics)->get_HeartRate(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::BloodPressure() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceCategoriesStatics)->get_BloodPressure(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::HumanInterfaceDevice() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceCategoriesStatics)->get_HumanInterfaceDevice(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::GlucoseMeter() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceCategoriesStatics)->get_GlucoseMeter(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::RunningWalking() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceCategoriesStatics)->get_RunningWalking(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::Cycling() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceCategoriesStatics)->get_Cycling(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::PulseOximeter() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceCategoriesStatics)->get_PulseOximeter(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::WeightScale() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceCategoriesStatics)->get_WeightScale(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceCategoriesStatics<D>::OutdoorSportActivity() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceCategoriesStatics)->get_OutdoorSportActivity(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::Generic() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceSubcategoriesStatics)->get_Generic(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::SportsWatch() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceSubcategoriesStatics)->get_SportsWatch(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::ThermometerEar() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceSubcategoriesStatics)->get_ThermometerEar(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::HeartRateBelt() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceSubcategoriesStatics)->get_HeartRateBelt(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::BloodPressureArm() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceSubcategoriesStatics)->get_BloodPressureArm(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::BloodPressureWrist() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceSubcategoriesStatics)->get_BloodPressureWrist(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::Keyboard() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceSubcategoriesStatics)->get_Keyboard(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::Mouse() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceSubcategoriesStatics)->get_Mouse(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::Joystick() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceSubcategoriesStatics)->get_Joystick(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::Gamepad() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceSubcategoriesStatics)->get_Gamepad(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::DigitizerTablet() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceSubcategoriesStatics)->get_DigitizerTablet(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::CardReader() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceSubcategoriesStatics)->get_CardReader(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::DigitalPen() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceSubcategoriesStatics)->get_DigitalPen(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::BarcodeScanner() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceSubcategoriesStatics)->get_BarcodeScanner(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::RunningWalkingInShoe() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceSubcategoriesStatics)->get_RunningWalkingInShoe(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::RunningWalkingOnShoe() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceSubcategoriesStatics)->get_RunningWalkingOnShoe(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::RunningWalkingOnHip() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceSubcategoriesStatics)->get_RunningWalkingOnHip(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::CyclingComputer() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceSubcategoriesStatics)->get_CyclingComputer(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::CyclingSpeedSensor() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceSubcategoriesStatics)->get_CyclingSpeedSensor(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::CyclingCadenceSensor() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceSubcategoriesStatics)->get_CyclingCadenceSensor(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::CyclingPowerSensor() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceSubcategoriesStatics)->get_CyclingPowerSensor(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::CyclingSpeedCadenceSensor() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceSubcategoriesStatics)->get_CyclingSpeedCadenceSensor(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::OximeterFingertip() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceSubcategoriesStatics)->get_OximeterFingertip(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::OximeterWristWorn() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceSubcategoriesStatics)->get_OximeterWristWorn(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::LocationDisplay() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceSubcategoriesStatics)->get_LocationDisplay(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::LocationNavigationDisplay() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceSubcategoriesStatics)->get_LocationNavigationDisplay(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::LocationPod() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceSubcategoriesStatics)->get_LocationPod(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearanceSubcategoriesStatics<D>::LocationNavigationPod() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceSubcategoriesStatics)->get_LocationNavigationPod(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearance<D>::RawValue() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearance)->get_RawValue(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearance<D>::Category() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearance)->get_Category(&value));
    return value;
}

template <typename D> uint16_t impl_IBluetoothLEAppearance<D>::SubCategory() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEAppearance)->get_SubCategory(&value));
    return value;
}

template <typename D> Windows::Devices::Bluetooth::BluetoothLEAppearance impl_IBluetoothLEAppearanceStatics<D>::FromRawValue(uint16_t rawValue) const
{
    Windows::Devices::Bluetooth::BluetoothLEAppearance appearance { nullptr };
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceStatics)->abi_FromRawValue(rawValue, put_abi(appearance)));
    return appearance;
}

template <typename D> Windows::Devices::Bluetooth::BluetoothLEAppearance impl_IBluetoothLEAppearanceStatics<D>::FromParts(uint16_t appearanceCategory, uint16_t appearanceSubCategory) const
{
    Windows::Devices::Bluetooth::BluetoothLEAppearance appearance { nullptr };
    check_hresult(WINRT_SHIM(IBluetoothLEAppearanceStatics)->abi_FromParts(appearanceCategory, appearanceSubCategory, put_abi(appearance)));
    return appearance;
}

template <typename D> hstring impl_IBluetoothLEDevice<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IBluetoothLEDevice)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IBluetoothLEDevice<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IBluetoothLEDevice)->get_Name(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceService> impl_IBluetoothLEDevice<D>::GattServices() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceService> value;
    check_hresult(WINRT_SHIM(IBluetoothLEDevice)->get_GattServices(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Bluetooth::BluetoothConnectionStatus impl_IBluetoothLEDevice<D>::ConnectionStatus() const
{
    Windows::Devices::Bluetooth::BluetoothConnectionStatus value {};
    check_hresult(WINRT_SHIM(IBluetoothLEDevice)->get_ConnectionStatus(&value));
    return value;
}

template <typename D> uint64_t impl_IBluetoothLEDevice<D>::BluetoothAddress() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IBluetoothLEDevice)->get_BluetoothAddress(&value));
    return value;
}

template <typename D> Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceService impl_IBluetoothLEDevice<D>::GetGattService(GUID serviceUuid) const
{
    Windows::Devices::Bluetooth::GenericAttributeProfile::GattDeviceService service { nullptr };
    check_hresult(WINRT_SHIM(IBluetoothLEDevice)->abi_GetGattService(serviceUuid, put_abi(service)));
    return service;
}

template <typename D> event_token impl_IBluetoothLEDevice<D>::NameChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothLEDevice, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IBluetoothLEDevice)->add_NameChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IBluetoothLEDevice> impl_IBluetoothLEDevice<D>::NameChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothLEDevice, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IBluetoothLEDevice>(this, &ABI::Windows::Devices::Bluetooth::IBluetoothLEDevice::remove_NameChanged, NameChanged(handler));
}

template <typename D> void impl_IBluetoothLEDevice<D>::NameChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IBluetoothLEDevice)->remove_NameChanged(token));
}

template <typename D> event_token impl_IBluetoothLEDevice<D>::GattServicesChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothLEDevice, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IBluetoothLEDevice)->add_GattServicesChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IBluetoothLEDevice> impl_IBluetoothLEDevice<D>::GattServicesChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothLEDevice, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IBluetoothLEDevice>(this, &ABI::Windows::Devices::Bluetooth::IBluetoothLEDevice::remove_GattServicesChanged, GattServicesChanged(handler));
}

template <typename D> void impl_IBluetoothLEDevice<D>::GattServicesChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IBluetoothLEDevice)->remove_GattServicesChanged(token));
}

template <typename D> event_token impl_IBluetoothLEDevice<D>::ConnectionStatusChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothLEDevice, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IBluetoothLEDevice)->add_ConnectionStatusChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IBluetoothLEDevice> impl_IBluetoothLEDevice<D>::ConnectionStatusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Bluetooth::BluetoothLEDevice, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IBluetoothLEDevice>(this, &ABI::Windows::Devices::Bluetooth::IBluetoothLEDevice::remove_ConnectionStatusChanged, ConnectionStatusChanged(handler));
}

template <typename D> void impl_IBluetoothLEDevice<D>::ConnectionStatusChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IBluetoothLEDevice)->remove_ConnectionStatusChanged(token));
}

template <typename D> Windows::Devices::Enumeration::DeviceInformation impl_IBluetoothLEDevice2<D>::DeviceInformation() const
{
    Windows::Devices::Enumeration::DeviceInformation value { nullptr };
    check_hresult(WINRT_SHIM(IBluetoothLEDevice2)->get_DeviceInformation(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Bluetooth::BluetoothLEAppearance impl_IBluetoothLEDevice2<D>::Appearance() const
{
    Windows::Devices::Bluetooth::BluetoothLEAppearance value { nullptr };
    check_hresult(WINRT_SHIM(IBluetoothLEDevice2)->get_Appearance(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Bluetooth::BluetoothAddressType impl_IBluetoothLEDevice2<D>::BluetoothAddressType() const
{
    Windows::Devices::Bluetooth::BluetoothAddressType value {};
    check_hresult(WINRT_SHIM(IBluetoothLEDevice2)->get_BluetoothAddressType(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothLEDevice> impl_IBluetoothLEDeviceStatics<D>::FromIdAsync(hstring_view deviceId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothLEDevice> operation;
    check_hresult(WINRT_SHIM(IBluetoothLEDeviceStatics)->abi_FromIdAsync(get_abi(deviceId), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothLEDevice> impl_IBluetoothLEDeviceStatics<D>::FromBluetoothAddressAsync(uint64_t bluetoothAddress) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothLEDevice> operation;
    check_hresult(WINRT_SHIM(IBluetoothLEDeviceStatics)->abi_FromBluetoothAddressAsync(bluetoothAddress, put_abi(operation)));
    return operation;
}

template <typename D> hstring impl_IBluetoothLEDeviceStatics<D>::GetDeviceSelector() const
{
    hstring deviceSelector;
    check_hresult(WINRT_SHIM(IBluetoothLEDeviceStatics)->abi_GetDeviceSelector(put_abi(deviceSelector)));
    return deviceSelector;
}

template <typename D> hstring impl_IBluetoothLEDeviceStatics2<D>::GetDeviceSelectorFromPairingState(bool pairingState) const
{
    hstring deviceSelector;
    check_hresult(WINRT_SHIM(IBluetoothLEDeviceStatics2)->abi_GetDeviceSelectorFromPairingState(pairingState, put_abi(deviceSelector)));
    return deviceSelector;
}

template <typename D> hstring impl_IBluetoothLEDeviceStatics2<D>::GetDeviceSelectorFromConnectionStatus(Windows::Devices::Bluetooth::BluetoothConnectionStatus connectionStatus) const
{
    hstring deviceSelector;
    check_hresult(WINRT_SHIM(IBluetoothLEDeviceStatics2)->abi_GetDeviceSelectorFromConnectionStatus(connectionStatus, put_abi(deviceSelector)));
    return deviceSelector;
}

template <typename D> hstring impl_IBluetoothLEDeviceStatics2<D>::GetDeviceSelectorFromDeviceName(hstring_view deviceName) const
{
    hstring deviceSelector;
    check_hresult(WINRT_SHIM(IBluetoothLEDeviceStatics2)->abi_GetDeviceSelectorFromDeviceName(get_abi(deviceName), put_abi(deviceSelector)));
    return deviceSelector;
}

template <typename D> hstring impl_IBluetoothLEDeviceStatics2<D>::GetDeviceSelectorFromBluetoothAddress(uint64_t bluetoothAddress) const
{
    hstring deviceSelector;
    check_hresult(WINRT_SHIM(IBluetoothLEDeviceStatics2)->abi_GetDeviceSelectorFromBluetoothAddress(bluetoothAddress, put_abi(deviceSelector)));
    return deviceSelector;
}

template <typename D> hstring impl_IBluetoothLEDeviceStatics2<D>::GetDeviceSelectorFromBluetoothAddress(uint64_t bluetoothAddress, Windows::Devices::Bluetooth::BluetoothAddressType bluetoothAddressType) const
{
    hstring deviceSelector;
    check_hresult(WINRT_SHIM(IBluetoothLEDeviceStatics2)->abi_GetDeviceSelectorFromBluetoothAddressWithBluetoothAddressType(bluetoothAddress, bluetoothAddressType, put_abi(deviceSelector)));
    return deviceSelector;
}

template <typename D> hstring impl_IBluetoothLEDeviceStatics2<D>::GetDeviceSelectorFromAppearance(const Windows::Devices::Bluetooth::BluetoothLEAppearance & appearance) const
{
    hstring deviceSelector;
    check_hresult(WINRT_SHIM(IBluetoothLEDeviceStatics2)->abi_GetDeviceSelectorFromAppearance(get_abi(appearance), put_abi(deviceSelector)));
    return deviceSelector;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothLEDevice> impl_IBluetoothLEDeviceStatics2<D>::FromBluetoothAddressAsync(uint64_t bluetoothAddress, Windows::Devices::Bluetooth::BluetoothAddressType bluetoothAddressType) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothLEDevice> operation;
    check_hresult(WINRT_SHIM(IBluetoothLEDeviceStatics2)->abi_FromBluetoothAddressWithBluetoothAddressTypeAsync(bluetoothAddress, bluetoothAddressType, put_abi(operation)));
    return operation;
}

template <typename D> uint32_t impl_IBluetoothClassOfDevice<D>::RawValue() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBluetoothClassOfDevice)->get_RawValue(&value));
    return value;
}

template <typename D> Windows::Devices::Bluetooth::BluetoothMajorClass impl_IBluetoothClassOfDevice<D>::MajorClass() const
{
    Windows::Devices::Bluetooth::BluetoothMajorClass value {};
    check_hresult(WINRT_SHIM(IBluetoothClassOfDevice)->get_MajorClass(&value));
    return value;
}

template <typename D> Windows::Devices::Bluetooth::BluetoothMinorClass impl_IBluetoothClassOfDevice<D>::MinorClass() const
{
    Windows::Devices::Bluetooth::BluetoothMinorClass value {};
    check_hresult(WINRT_SHIM(IBluetoothClassOfDevice)->get_MinorClass(&value));
    return value;
}

template <typename D> Windows::Devices::Bluetooth::BluetoothServiceCapabilities impl_IBluetoothClassOfDevice<D>::ServiceCapabilities() const
{
    Windows::Devices::Bluetooth::BluetoothServiceCapabilities value {};
    check_hresult(WINRT_SHIM(IBluetoothClassOfDevice)->get_ServiceCapabilities(&value));
    return value;
}

template <typename D> Windows::Devices::Bluetooth::BluetoothClassOfDevice impl_IBluetoothClassOfDeviceStatics<D>::FromRawValue(uint32_t rawValue) const
{
    Windows::Devices::Bluetooth::BluetoothClassOfDevice classOfDevice { nullptr };
    check_hresult(WINRT_SHIM(IBluetoothClassOfDeviceStatics)->abi_FromRawValue(rawValue, put_abi(classOfDevice)));
    return classOfDevice;
}

template <typename D> Windows::Devices::Bluetooth::BluetoothClassOfDevice impl_IBluetoothClassOfDeviceStatics<D>::FromParts(Windows::Devices::Bluetooth::BluetoothMajorClass majorClass, Windows::Devices::Bluetooth::BluetoothMinorClass minorClass, Windows::Devices::Bluetooth::BluetoothServiceCapabilities serviceCapabilities) const
{
    Windows::Devices::Bluetooth::BluetoothClassOfDevice classOfDevice { nullptr };
    check_hresult(WINRT_SHIM(IBluetoothClassOfDeviceStatics)->abi_FromParts(majorClass, minorClass, serviceCapabilities, put_abi(classOfDevice)));
    return classOfDevice;
}

template <typename D> Windows::Foundation::IReference<int16_t> impl_IBluetoothSignalStrengthFilter<D>::InRangeThresholdInDBm() const
{
    Windows::Foundation::IReference<int16_t> value;
    check_hresult(WINRT_SHIM(IBluetoothSignalStrengthFilter)->get_InRangeThresholdInDBm(put_abi(value)));
    return value;
}

template <typename D> void impl_IBluetoothSignalStrengthFilter<D>::InRangeThresholdInDBm(const optional<int16_t> & value) const
{
    check_hresult(WINRT_SHIM(IBluetoothSignalStrengthFilter)->put_InRangeThresholdInDBm(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<int16_t> impl_IBluetoothSignalStrengthFilter<D>::OutOfRangeThresholdInDBm() const
{
    Windows::Foundation::IReference<int16_t> value;
    check_hresult(WINRT_SHIM(IBluetoothSignalStrengthFilter)->get_OutOfRangeThresholdInDBm(put_abi(value)));
    return value;
}

template <typename D> void impl_IBluetoothSignalStrengthFilter<D>::OutOfRangeThresholdInDBm(const optional<int16_t> & value) const
{
    check_hresult(WINRT_SHIM(IBluetoothSignalStrengthFilter)->put_OutOfRangeThresholdInDBm(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::TimeSpan> impl_IBluetoothSignalStrengthFilter<D>::OutOfRangeTimeout() const
{
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> value;
    check_hresult(WINRT_SHIM(IBluetoothSignalStrengthFilter)->get_OutOfRangeTimeout(put_abi(value)));
    return value;
}

template <typename D> void impl_IBluetoothSignalStrengthFilter<D>::OutOfRangeTimeout(const optional<Windows::Foundation::TimeSpan> & value) const
{
    check_hresult(WINRT_SHIM(IBluetoothSignalStrengthFilter)->put_OutOfRangeTimeout(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::TimeSpan> impl_IBluetoothSignalStrengthFilter<D>::SamplingInterval() const
{
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> value;
    check_hresult(WINRT_SHIM(IBluetoothSignalStrengthFilter)->get_SamplingInterval(put_abi(value)));
    return value;
}

template <typename D> void impl_IBluetoothSignalStrengthFilter<D>::SamplingInterval(const optional<Windows::Foundation::TimeSpan> & value) const
{
    check_hresult(WINRT_SHIM(IBluetoothSignalStrengthFilter)->put_SamplingInterval(get_abi(value)));
}

inline Windows::Devices::Bluetooth::BluetoothClassOfDevice BluetoothClassOfDevice::FromRawValue(uint32_t rawValue)
{
    return get_activation_factory<BluetoothClassOfDevice, IBluetoothClassOfDeviceStatics>().FromRawValue(rawValue);
}

inline Windows::Devices::Bluetooth::BluetoothClassOfDevice BluetoothClassOfDevice::FromParts(Windows::Devices::Bluetooth::BluetoothMajorClass majorClass, Windows::Devices::Bluetooth::BluetoothMinorClass minorClass, Windows::Devices::Bluetooth::BluetoothServiceCapabilities serviceCapabilities)
{
    return get_activation_factory<BluetoothClassOfDevice, IBluetoothClassOfDeviceStatics>().FromParts(majorClass, minorClass, serviceCapabilities);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothDevice> BluetoothDevice::FromIdAsync(hstring_view deviceId)
{
    return get_activation_factory<BluetoothDevice, IBluetoothDeviceStatics>().FromIdAsync(deviceId);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothDevice> BluetoothDevice::FromHostNameAsync(const Windows::Networking::HostName & hostName)
{
    return get_activation_factory<BluetoothDevice, IBluetoothDeviceStatics>().FromHostNameAsync(hostName);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothDevice> BluetoothDevice::FromBluetoothAddressAsync(uint64_t address)
{
    return get_activation_factory<BluetoothDevice, IBluetoothDeviceStatics>().FromBluetoothAddressAsync(address);
}

inline hstring BluetoothDevice::GetDeviceSelector()
{
    return get_activation_factory<BluetoothDevice, IBluetoothDeviceStatics>().GetDeviceSelector();
}

inline hstring BluetoothDevice::GetDeviceSelectorFromPairingState(bool pairingState)
{
    return get_activation_factory<BluetoothDevice, IBluetoothDeviceStatics2>().GetDeviceSelectorFromPairingState(pairingState);
}

inline hstring BluetoothDevice::GetDeviceSelectorFromConnectionStatus(Windows::Devices::Bluetooth::BluetoothConnectionStatus connectionStatus)
{
    return get_activation_factory<BluetoothDevice, IBluetoothDeviceStatics2>().GetDeviceSelectorFromConnectionStatus(connectionStatus);
}

inline hstring BluetoothDevice::GetDeviceSelectorFromDeviceName(hstring_view deviceName)
{
    return get_activation_factory<BluetoothDevice, IBluetoothDeviceStatics2>().GetDeviceSelectorFromDeviceName(deviceName);
}

inline hstring BluetoothDevice::GetDeviceSelectorFromBluetoothAddress(uint64_t bluetoothAddress)
{
    return get_activation_factory<BluetoothDevice, IBluetoothDeviceStatics2>().GetDeviceSelectorFromBluetoothAddress(bluetoothAddress);
}

inline hstring BluetoothDevice::GetDeviceSelectorFromClassOfDevice(const Windows::Devices::Bluetooth::BluetoothClassOfDevice & classOfDevice)
{
    return get_activation_factory<BluetoothDevice, IBluetoothDeviceStatics2>().GetDeviceSelectorFromClassOfDevice(classOfDevice);
}

inline Windows::Devices::Bluetooth::BluetoothLEAppearance BluetoothLEAppearance::FromRawValue(uint16_t rawValue)
{
    return get_activation_factory<BluetoothLEAppearance, IBluetoothLEAppearanceStatics>().FromRawValue(rawValue);
}

inline Windows::Devices::Bluetooth::BluetoothLEAppearance BluetoothLEAppearance::FromParts(uint16_t appearanceCategory, uint16_t appearanceSubCategory)
{
    return get_activation_factory<BluetoothLEAppearance, IBluetoothLEAppearanceStatics>().FromParts(appearanceCategory, appearanceSubCategory);
}

inline uint16_t BluetoothLEAppearanceCategories::Uncategorized()
{
    return get_activation_factory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().Uncategorized();
}

inline uint16_t BluetoothLEAppearanceCategories::Phone()
{
    return get_activation_factory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().Phone();
}

inline uint16_t BluetoothLEAppearanceCategories::Computer()
{
    return get_activation_factory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().Computer();
}

inline uint16_t BluetoothLEAppearanceCategories::Watch()
{
    return get_activation_factory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().Watch();
}

inline uint16_t BluetoothLEAppearanceCategories::Clock()
{
    return get_activation_factory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().Clock();
}

inline uint16_t BluetoothLEAppearanceCategories::Display()
{
    return get_activation_factory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().Display();
}

inline uint16_t BluetoothLEAppearanceCategories::RemoteControl()
{
    return get_activation_factory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().RemoteControl();
}

inline uint16_t BluetoothLEAppearanceCategories::EyeGlasses()
{
    return get_activation_factory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().EyeGlasses();
}

inline uint16_t BluetoothLEAppearanceCategories::Tag()
{
    return get_activation_factory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().Tag();
}

inline uint16_t BluetoothLEAppearanceCategories::Keyring()
{
    return get_activation_factory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().Keyring();
}

inline uint16_t BluetoothLEAppearanceCategories::MediaPlayer()
{
    return get_activation_factory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().MediaPlayer();
}

inline uint16_t BluetoothLEAppearanceCategories::BarcodeScanner()
{
    return get_activation_factory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().BarcodeScanner();
}

inline uint16_t BluetoothLEAppearanceCategories::Thermometer()
{
    return get_activation_factory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().Thermometer();
}

inline uint16_t BluetoothLEAppearanceCategories::HeartRate()
{
    return get_activation_factory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().HeartRate();
}

inline uint16_t BluetoothLEAppearanceCategories::BloodPressure()
{
    return get_activation_factory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().BloodPressure();
}

inline uint16_t BluetoothLEAppearanceCategories::HumanInterfaceDevice()
{
    return get_activation_factory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().HumanInterfaceDevice();
}

inline uint16_t BluetoothLEAppearanceCategories::GlucoseMeter()
{
    return get_activation_factory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().GlucoseMeter();
}

inline uint16_t BluetoothLEAppearanceCategories::RunningWalking()
{
    return get_activation_factory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().RunningWalking();
}

inline uint16_t BluetoothLEAppearanceCategories::Cycling()
{
    return get_activation_factory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().Cycling();
}

inline uint16_t BluetoothLEAppearanceCategories::PulseOximeter()
{
    return get_activation_factory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().PulseOximeter();
}

inline uint16_t BluetoothLEAppearanceCategories::WeightScale()
{
    return get_activation_factory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().WeightScale();
}

inline uint16_t BluetoothLEAppearanceCategories::OutdoorSportActivity()
{
    return get_activation_factory<BluetoothLEAppearanceCategories, IBluetoothLEAppearanceCategoriesStatics>().OutdoorSportActivity();
}

inline uint16_t BluetoothLEAppearanceSubcategories::Generic()
{
    return get_activation_factory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().Generic();
}

inline uint16_t BluetoothLEAppearanceSubcategories::SportsWatch()
{
    return get_activation_factory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().SportsWatch();
}

inline uint16_t BluetoothLEAppearanceSubcategories::ThermometerEar()
{
    return get_activation_factory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().ThermometerEar();
}

inline uint16_t BluetoothLEAppearanceSubcategories::HeartRateBelt()
{
    return get_activation_factory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().HeartRateBelt();
}

inline uint16_t BluetoothLEAppearanceSubcategories::BloodPressureArm()
{
    return get_activation_factory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().BloodPressureArm();
}

inline uint16_t BluetoothLEAppearanceSubcategories::BloodPressureWrist()
{
    return get_activation_factory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().BloodPressureWrist();
}

inline uint16_t BluetoothLEAppearanceSubcategories::Keyboard()
{
    return get_activation_factory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().Keyboard();
}

inline uint16_t BluetoothLEAppearanceSubcategories::Mouse()
{
    return get_activation_factory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().Mouse();
}

inline uint16_t BluetoothLEAppearanceSubcategories::Joystick()
{
    return get_activation_factory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().Joystick();
}

inline uint16_t BluetoothLEAppearanceSubcategories::Gamepad()
{
    return get_activation_factory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().Gamepad();
}

inline uint16_t BluetoothLEAppearanceSubcategories::DigitizerTablet()
{
    return get_activation_factory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().DigitizerTablet();
}

inline uint16_t BluetoothLEAppearanceSubcategories::CardReader()
{
    return get_activation_factory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().CardReader();
}

inline uint16_t BluetoothLEAppearanceSubcategories::DigitalPen()
{
    return get_activation_factory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().DigitalPen();
}

inline uint16_t BluetoothLEAppearanceSubcategories::BarcodeScanner()
{
    return get_activation_factory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().BarcodeScanner();
}

inline uint16_t BluetoothLEAppearanceSubcategories::RunningWalkingInShoe()
{
    return get_activation_factory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().RunningWalkingInShoe();
}

inline uint16_t BluetoothLEAppearanceSubcategories::RunningWalkingOnShoe()
{
    return get_activation_factory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().RunningWalkingOnShoe();
}

inline uint16_t BluetoothLEAppearanceSubcategories::RunningWalkingOnHip()
{
    return get_activation_factory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().RunningWalkingOnHip();
}

inline uint16_t BluetoothLEAppearanceSubcategories::CyclingComputer()
{
    return get_activation_factory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().CyclingComputer();
}

inline uint16_t BluetoothLEAppearanceSubcategories::CyclingSpeedSensor()
{
    return get_activation_factory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().CyclingSpeedSensor();
}

inline uint16_t BluetoothLEAppearanceSubcategories::CyclingCadenceSensor()
{
    return get_activation_factory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().CyclingCadenceSensor();
}

inline uint16_t BluetoothLEAppearanceSubcategories::CyclingPowerSensor()
{
    return get_activation_factory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().CyclingPowerSensor();
}

inline uint16_t BluetoothLEAppearanceSubcategories::CyclingSpeedCadenceSensor()
{
    return get_activation_factory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().CyclingSpeedCadenceSensor();
}

inline uint16_t BluetoothLEAppearanceSubcategories::OximeterFingertip()
{
    return get_activation_factory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().OximeterFingertip();
}

inline uint16_t BluetoothLEAppearanceSubcategories::OximeterWristWorn()
{
    return get_activation_factory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().OximeterWristWorn();
}

inline uint16_t BluetoothLEAppearanceSubcategories::LocationDisplay()
{
    return get_activation_factory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().LocationDisplay();
}

inline uint16_t BluetoothLEAppearanceSubcategories::LocationNavigationDisplay()
{
    return get_activation_factory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().LocationNavigationDisplay();
}

inline uint16_t BluetoothLEAppearanceSubcategories::LocationPod()
{
    return get_activation_factory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().LocationPod();
}

inline uint16_t BluetoothLEAppearanceSubcategories::LocationNavigationPod()
{
    return get_activation_factory<BluetoothLEAppearanceSubcategories, IBluetoothLEAppearanceSubcategoriesStatics>().LocationNavigationPod();
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothLEDevice> BluetoothLEDevice::FromIdAsync(hstring_view deviceId)
{
    return get_activation_factory<BluetoothLEDevice, IBluetoothLEDeviceStatics>().FromIdAsync(deviceId);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothLEDevice> BluetoothLEDevice::FromBluetoothAddressAsync(uint64_t bluetoothAddress)
{
    return get_activation_factory<BluetoothLEDevice, IBluetoothLEDeviceStatics>().FromBluetoothAddressAsync(bluetoothAddress);
}

inline hstring BluetoothLEDevice::GetDeviceSelector()
{
    return get_activation_factory<BluetoothLEDevice, IBluetoothLEDeviceStatics>().GetDeviceSelector();
}

inline hstring BluetoothLEDevice::GetDeviceSelectorFromPairingState(bool pairingState)
{
    return get_activation_factory<BluetoothLEDevice, IBluetoothLEDeviceStatics2>().GetDeviceSelectorFromPairingState(pairingState);
}

inline hstring BluetoothLEDevice::GetDeviceSelectorFromConnectionStatus(Windows::Devices::Bluetooth::BluetoothConnectionStatus connectionStatus)
{
    return get_activation_factory<BluetoothLEDevice, IBluetoothLEDeviceStatics2>().GetDeviceSelectorFromConnectionStatus(connectionStatus);
}

inline hstring BluetoothLEDevice::GetDeviceSelectorFromDeviceName(hstring_view deviceName)
{
    return get_activation_factory<BluetoothLEDevice, IBluetoothLEDeviceStatics2>().GetDeviceSelectorFromDeviceName(deviceName);
}

inline hstring BluetoothLEDevice::GetDeviceSelectorFromBluetoothAddress(uint64_t bluetoothAddress)
{
    return get_activation_factory<BluetoothLEDevice, IBluetoothLEDeviceStatics2>().GetDeviceSelectorFromBluetoothAddress(bluetoothAddress);
}

inline hstring BluetoothLEDevice::GetDeviceSelectorFromBluetoothAddress(uint64_t bluetoothAddress, Windows::Devices::Bluetooth::BluetoothAddressType bluetoothAddressType)
{
    return get_activation_factory<BluetoothLEDevice, IBluetoothLEDeviceStatics2>().GetDeviceSelectorFromBluetoothAddress(bluetoothAddress, bluetoothAddressType);
}

inline hstring BluetoothLEDevice::GetDeviceSelectorFromAppearance(const Windows::Devices::Bluetooth::BluetoothLEAppearance & appearance)
{
    return get_activation_factory<BluetoothLEDevice, IBluetoothLEDeviceStatics2>().GetDeviceSelectorFromAppearance(appearance);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::BluetoothLEDevice> BluetoothLEDevice::FromBluetoothAddressAsync(uint64_t bluetoothAddress, Windows::Devices::Bluetooth::BluetoothAddressType bluetoothAddressType)
{
    return get_activation_factory<BluetoothLEDevice, IBluetoothLEDeviceStatics2>().FromBluetoothAddressAsync(bluetoothAddress, bluetoothAddressType);
}

inline BluetoothSignalStrengthFilter::BluetoothSignalStrengthFilter() :
    BluetoothSignalStrengthFilter(activate_instance<BluetoothSignalStrengthFilter>())
{}

}

}
#pragma warning(pop)
