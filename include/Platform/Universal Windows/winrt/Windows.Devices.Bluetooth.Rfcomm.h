// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Devices.Bluetooth.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Networking.3.h"
#include "internal/Windows.Networking.Sockets.3.h"
#include "internal/Windows.Devices.Enumeration.3.h"
#include "internal/Windows.Devices.Bluetooth.Rfcomm.3.h"
#include "Windows.Devices.Bluetooth.h"
#include "Windows.Foundation.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceService> : produce_base<D, Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceService>
{
    HRESULT __stdcall get_ConnectionHostName(impl::abi_arg_out<Windows::Networking::IHostName> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ConnectionHostName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ConnectionServiceName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ConnectionServiceName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServiceId(impl::abi_arg_out<Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServiceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProtectionLevel(Windows::Networking::Sockets::SocketProtectionLevel * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProtectionLevel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxProtectionLevel(Windows::Networking::Sockets::SocketProtectionLevel * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxProtectionLevel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSdpRawAttributesAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMapView<uint32_t, Windows::Storage::Streams::IBuffer>>> asyncOp) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_abi(this->shim().GetSdpRawAttributesAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncOp = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSdpRawAttributesWithCacheModeAsync(Windows::Devices::Bluetooth::BluetoothCacheMode cacheMode, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMapView<uint32_t, Windows::Storage::Streams::IBuffer>>> asyncOp) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_abi(this->shim().GetSdpRawAttributesAsync(cacheMode));
            return S_OK;
        }
        catch (...)
        {
            *asyncOp = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceService2> : produce_base<D, Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceService2>
{
    HRESULT __stdcall get_Device(impl::abi_arg_out<Windows::Devices::Bluetooth::IBluetoothDevice> value) noexcept override
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

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceService3> : produce_base<D, Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceService3>
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
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceServiceStatics> : produce_base<D, Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceServiceStatics>
{
    HRESULT __stdcall abi_FromIdAsync(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceService>> asyncOp) noexcept override
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

    HRESULT __stdcall abi_GetDeviceSelector(impl::abi_arg_in<Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId> serviceId, impl::abi_arg_out<hstring> selector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *selector = detach_abi(this->shim().GetDeviceSelector(*reinterpret_cast<const Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId *>(&serviceId)));
            return S_OK;
        }
        catch (...)
        {
            *selector = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceServiceStatics2> : produce_base<D, Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceServiceStatics2>
{
    HRESULT __stdcall abi_GetDeviceSelectorForBluetoothDevice(impl::abi_arg_in<Windows::Devices::Bluetooth::IBluetoothDevice> bluetoothDevice, impl::abi_arg_out<hstring> selector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *selector = detach_abi(this->shim().GetDeviceSelectorForBluetoothDevice(*reinterpret_cast<const Windows::Devices::Bluetooth::BluetoothDevice *>(&bluetoothDevice)));
            return S_OK;
        }
        catch (...)
        {
            *selector = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelectorForBluetoothDeviceWithCacheMode(impl::abi_arg_in<Windows::Devices::Bluetooth::IBluetoothDevice> bluetoothDevice, Windows::Devices::Bluetooth::BluetoothCacheMode cacheMode, impl::abi_arg_out<hstring> selector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *selector = detach_abi(this->shim().GetDeviceSelectorForBluetoothDevice(*reinterpret_cast<const Windows::Devices::Bluetooth::BluetoothDevice *>(&bluetoothDevice), cacheMode));
            return S_OK;
        }
        catch (...)
        {
            *selector = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelectorForBluetoothDeviceAndServiceId(impl::abi_arg_in<Windows::Devices::Bluetooth::IBluetoothDevice> bluetoothDevice, impl::abi_arg_in<Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId> serviceId, impl::abi_arg_out<hstring> selector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *selector = detach_abi(this->shim().GetDeviceSelectorForBluetoothDeviceAndServiceId(*reinterpret_cast<const Windows::Devices::Bluetooth::BluetoothDevice *>(&bluetoothDevice), *reinterpret_cast<const Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId *>(&serviceId)));
            return S_OK;
        }
        catch (...)
        {
            *selector = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelectorForBluetoothDeviceAndServiceIdWithCacheMode(impl::abi_arg_in<Windows::Devices::Bluetooth::IBluetoothDevice> bluetoothDevice, impl::abi_arg_in<Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId> serviceId, Windows::Devices::Bluetooth::BluetoothCacheMode cacheMode, impl::abi_arg_out<hstring> selector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *selector = detach_abi(this->shim().GetDeviceSelectorForBluetoothDeviceAndServiceId(*reinterpret_cast<const Windows::Devices::Bluetooth::BluetoothDevice *>(&bluetoothDevice), *reinterpret_cast<const Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId *>(&serviceId), cacheMode));
            return S_OK;
        }
        catch (...)
        {
            *selector = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceServicesResult> : produce_base<D, Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceServicesResult>
{
    HRESULT __stdcall get_Error(Windows::Devices::Bluetooth::BluetoothError * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Error());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Services(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceService>> services) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *services = detach_abi(this->shim().Services());
            return S_OK;
        }
        catch (...)
        {
            *services = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId> : produce_base<D, Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId>
{
    HRESULT __stdcall get_Uuid(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Uuid());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AsShortId(uint32_t * shortId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *shortId = detach_abi(this->shim().AsShortId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AsString(impl::abi_arg_out<hstring> id) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *id = detach_abi(this->shim().AsString());
            return S_OK;
        }
        catch (...)
        {
            *id = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceIdStatics> : produce_base<D, Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceIdStatics>
{
    HRESULT __stdcall abi_FromUuid(GUID uuid, impl::abi_arg_out<Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId> serviceId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *serviceId = detach_abi(this->shim().FromUuid(uuid));
            return S_OK;
        }
        catch (...)
        {
            *serviceId = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromShortId(uint32_t shortId, impl::abi_arg_out<Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId> serviceId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *serviceId = detach_abi(this->shim().FromShortId(shortId));
            return S_OK;
        }
        catch (...)
        {
            *serviceId = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SerialPort(impl::abi_arg_out<Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId> serviceId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *serviceId = detach_abi(this->shim().SerialPort());
            return S_OK;
        }
        catch (...)
        {
            *serviceId = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ObexObjectPush(impl::abi_arg_out<Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId> serviceId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *serviceId = detach_abi(this->shim().ObexObjectPush());
            return S_OK;
        }
        catch (...)
        {
            *serviceId = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ObexFileTransfer(impl::abi_arg_out<Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId> serviceId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *serviceId = detach_abi(this->shim().ObexFileTransfer());
            return S_OK;
        }
        catch (...)
        {
            *serviceId = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PhoneBookAccessPce(impl::abi_arg_out<Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId> serviceId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *serviceId = detach_abi(this->shim().PhoneBookAccessPce());
            return S_OK;
        }
        catch (...)
        {
            *serviceId = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PhoneBookAccessPse(impl::abi_arg_out<Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId> serviceId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *serviceId = detach_abi(this->shim().PhoneBookAccessPse());
            return S_OK;
        }
        catch (...)
        {
            *serviceId = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GenericFileTransfer(impl::abi_arg_out<Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId> serviceId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *serviceId = detach_abi(this->shim().GenericFileTransfer());
            return S_OK;
        }
        catch (...)
        {
            *serviceId = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceProvider> : produce_base<D, Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceProvider>
{
    HRESULT __stdcall get_ServiceId(impl::abi_arg_out<Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServiceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SdpRawAttributes(impl::abi_arg_out<Windows::Foundation::Collections::IMap<uint32_t, Windows::Storage::Streams::IBuffer>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SdpRawAttributes());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartAdvertising(impl::abi_arg_in<Windows::Networking::Sockets::IStreamSocketListener> listener) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartAdvertising(*reinterpret_cast<const Windows::Networking::Sockets::StreamSocketListener *>(&listener));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StopAdvertising() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StopAdvertising();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceProvider2> : produce_base<D, Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceProvider2>
{
    HRESULT __stdcall abi_StartAdvertisingWithRadioDiscoverability(impl::abi_arg_in<Windows::Networking::Sockets::IStreamSocketListener> listener, bool radioDiscoverable) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartAdvertising(*reinterpret_cast<const Windows::Networking::Sockets::StreamSocketListener *>(&listener), radioDiscoverable);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceProviderStatics> : produce_base<D, Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceProviderStatics>
{
    HRESULT __stdcall abi_CreateAsync(impl::abi_arg_in<Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceId> serviceId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommServiceProvider>> asyncOp) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_abi(this->shim().CreateAsync(*reinterpret_cast<const Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId *>(&serviceId)));
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

namespace Windows::Devices::Bluetooth::Rfcomm {

template <typename D> Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId impl_IRfcommServiceIdStatics<D>::FromUuid(GUID uuid) const
{
    Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId serviceId { nullptr };
    check_hresult(WINRT_SHIM(IRfcommServiceIdStatics)->abi_FromUuid(uuid, put_abi(serviceId)));
    return serviceId;
}

template <typename D> Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId impl_IRfcommServiceIdStatics<D>::FromShortId(uint32_t shortId) const
{
    Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId serviceId { nullptr };
    check_hresult(WINRT_SHIM(IRfcommServiceIdStatics)->abi_FromShortId(shortId, put_abi(serviceId)));
    return serviceId;
}

template <typename D> Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId impl_IRfcommServiceIdStatics<D>::SerialPort() const
{
    Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId serviceId { nullptr };
    check_hresult(WINRT_SHIM(IRfcommServiceIdStatics)->get_SerialPort(put_abi(serviceId)));
    return serviceId;
}

template <typename D> Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId impl_IRfcommServiceIdStatics<D>::ObexObjectPush() const
{
    Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId serviceId { nullptr };
    check_hresult(WINRT_SHIM(IRfcommServiceIdStatics)->get_ObexObjectPush(put_abi(serviceId)));
    return serviceId;
}

template <typename D> Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId impl_IRfcommServiceIdStatics<D>::ObexFileTransfer() const
{
    Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId serviceId { nullptr };
    check_hresult(WINRT_SHIM(IRfcommServiceIdStatics)->get_ObexFileTransfer(put_abi(serviceId)));
    return serviceId;
}

template <typename D> Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId impl_IRfcommServiceIdStatics<D>::PhoneBookAccessPce() const
{
    Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId serviceId { nullptr };
    check_hresult(WINRT_SHIM(IRfcommServiceIdStatics)->get_PhoneBookAccessPce(put_abi(serviceId)));
    return serviceId;
}

template <typename D> Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId impl_IRfcommServiceIdStatics<D>::PhoneBookAccessPse() const
{
    Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId serviceId { nullptr };
    check_hresult(WINRT_SHIM(IRfcommServiceIdStatics)->get_PhoneBookAccessPse(put_abi(serviceId)));
    return serviceId;
}

template <typename D> Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId impl_IRfcommServiceIdStatics<D>::GenericFileTransfer() const
{
    Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId serviceId { nullptr };
    check_hresult(WINRT_SHIM(IRfcommServiceIdStatics)->get_GenericFileTransfer(put_abi(serviceId)));
    return serviceId;
}

template <typename D> GUID impl_IRfcommServiceId<D>::Uuid() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(IRfcommServiceId)->get_Uuid(&value));
    return value;
}

template <typename D> uint32_t impl_IRfcommServiceId<D>::AsShortId() const
{
    uint32_t shortId {};
    check_hresult(WINRT_SHIM(IRfcommServiceId)->abi_AsShortId(&shortId));
    return shortId;
}

template <typename D> hstring impl_IRfcommServiceId<D>::AsString() const
{
    hstring id;
    check_hresult(WINRT_SHIM(IRfcommServiceId)->abi_AsString(put_abi(id)));
    return id;
}

template <typename D> Windows::Devices::Bluetooth::BluetoothError impl_IRfcommDeviceServicesResult<D>::Error() const
{
    Windows::Devices::Bluetooth::BluetoothError value {};
    check_hresult(WINRT_SHIM(IRfcommDeviceServicesResult)->get_Error(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceService> impl_IRfcommDeviceServicesResult<D>::Services() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceService> services;
    check_hresult(WINRT_SHIM(IRfcommDeviceServicesResult)->get_Services(put_abi(services)));
    return services;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceService> impl_IRfcommDeviceServiceStatics<D>::FromIdAsync(hstring_view deviceId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceService> asyncOp;
    check_hresult(WINRT_SHIM(IRfcommDeviceServiceStatics)->abi_FromIdAsync(get_abi(deviceId), put_abi(asyncOp)));
    return asyncOp;
}

template <typename D> hstring impl_IRfcommDeviceServiceStatics<D>::GetDeviceSelector(const Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId & serviceId) const
{
    hstring selector;
    check_hresult(WINRT_SHIM(IRfcommDeviceServiceStatics)->abi_GetDeviceSelector(get_abi(serviceId), put_abi(selector)));
    return selector;
}

template <typename D> hstring impl_IRfcommDeviceServiceStatics2<D>::GetDeviceSelectorForBluetoothDevice(const Windows::Devices::Bluetooth::BluetoothDevice & bluetoothDevice) const
{
    hstring selector;
    check_hresult(WINRT_SHIM(IRfcommDeviceServiceStatics2)->abi_GetDeviceSelectorForBluetoothDevice(get_abi(bluetoothDevice), put_abi(selector)));
    return selector;
}

template <typename D> hstring impl_IRfcommDeviceServiceStatics2<D>::GetDeviceSelectorForBluetoothDevice(const Windows::Devices::Bluetooth::BluetoothDevice & bluetoothDevice, Windows::Devices::Bluetooth::BluetoothCacheMode cacheMode) const
{
    hstring selector;
    check_hresult(WINRT_SHIM(IRfcommDeviceServiceStatics2)->abi_GetDeviceSelectorForBluetoothDeviceWithCacheMode(get_abi(bluetoothDevice), cacheMode, put_abi(selector)));
    return selector;
}

template <typename D> hstring impl_IRfcommDeviceServiceStatics2<D>::GetDeviceSelectorForBluetoothDeviceAndServiceId(const Windows::Devices::Bluetooth::BluetoothDevice & bluetoothDevice, const Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId & serviceId) const
{
    hstring selector;
    check_hresult(WINRT_SHIM(IRfcommDeviceServiceStatics2)->abi_GetDeviceSelectorForBluetoothDeviceAndServiceId(get_abi(bluetoothDevice), get_abi(serviceId), put_abi(selector)));
    return selector;
}

template <typename D> hstring impl_IRfcommDeviceServiceStatics2<D>::GetDeviceSelectorForBluetoothDeviceAndServiceId(const Windows::Devices::Bluetooth::BluetoothDevice & bluetoothDevice, const Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId & serviceId, Windows::Devices::Bluetooth::BluetoothCacheMode cacheMode) const
{
    hstring selector;
    check_hresult(WINRT_SHIM(IRfcommDeviceServiceStatics2)->abi_GetDeviceSelectorForBluetoothDeviceAndServiceIdWithCacheMode(get_abi(bluetoothDevice), get_abi(serviceId), cacheMode, put_abi(selector)));
    return selector;
}

template <typename D> Windows::Networking::HostName impl_IRfcommDeviceService<D>::ConnectionHostName() const
{
    Windows::Networking::HostName value { nullptr };
    check_hresult(WINRT_SHIM(IRfcommDeviceService)->get_ConnectionHostName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IRfcommDeviceService<D>::ConnectionServiceName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IRfcommDeviceService)->get_ConnectionServiceName(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId impl_IRfcommDeviceService<D>::ServiceId() const
{
    Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId value { nullptr };
    check_hresult(WINRT_SHIM(IRfcommDeviceService)->get_ServiceId(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::Sockets::SocketProtectionLevel impl_IRfcommDeviceService<D>::ProtectionLevel() const
{
    Windows::Networking::Sockets::SocketProtectionLevel value {};
    check_hresult(WINRT_SHIM(IRfcommDeviceService)->get_ProtectionLevel(&value));
    return value;
}

template <typename D> Windows::Networking::Sockets::SocketProtectionLevel impl_IRfcommDeviceService<D>::MaxProtectionLevel() const
{
    Windows::Networking::Sockets::SocketProtectionLevel value {};
    check_hresult(WINRT_SHIM(IRfcommDeviceService)->get_MaxProtectionLevel(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMapView<uint32_t, Windows::Storage::Streams::IBuffer>> impl_IRfcommDeviceService<D>::GetSdpRawAttributesAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMapView<uint32_t, Windows::Storage::Streams::IBuffer>> asyncOp;
    check_hresult(WINRT_SHIM(IRfcommDeviceService)->abi_GetSdpRawAttributesAsync(put_abi(asyncOp)));
    return asyncOp;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMapView<uint32_t, Windows::Storage::Streams::IBuffer>> impl_IRfcommDeviceService<D>::GetSdpRawAttributesAsync(Windows::Devices::Bluetooth::BluetoothCacheMode cacheMode) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMapView<uint32_t, Windows::Storage::Streams::IBuffer>> asyncOp;
    check_hresult(WINRT_SHIM(IRfcommDeviceService)->abi_GetSdpRawAttributesWithCacheModeAsync(cacheMode, put_abi(asyncOp)));
    return asyncOp;
}

template <typename D> Windows::Devices::Bluetooth::BluetoothDevice impl_IRfcommDeviceService2<D>::Device() const
{
    Windows::Devices::Bluetooth::BluetoothDevice value { nullptr };
    check_hresult(WINRT_SHIM(IRfcommDeviceService2)->get_Device(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Enumeration::DeviceAccessInformation impl_IRfcommDeviceService3<D>::DeviceAccessInformation() const
{
    Windows::Devices::Enumeration::DeviceAccessInformation value { nullptr };
    check_hresult(WINRT_SHIM(IRfcommDeviceService3)->get_DeviceAccessInformation(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Enumeration::DeviceAccessStatus> impl_IRfcommDeviceService3<D>::RequestAccessAsync() const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::Enumeration::DeviceAccessStatus> value;
    check_hresult(WINRT_SHIM(IRfcommDeviceService3)->abi_RequestAccessAsync(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommServiceProvider> impl_IRfcommServiceProviderStatics<D>::CreateAsync(const Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId & serviceId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommServiceProvider> asyncOp;
    check_hresult(WINRT_SHIM(IRfcommServiceProviderStatics)->abi_CreateAsync(get_abi(serviceId), put_abi(asyncOp)));
    return asyncOp;
}

template <typename D> Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId impl_IRfcommServiceProvider<D>::ServiceId() const
{
    Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId value { nullptr };
    check_hresult(WINRT_SHIM(IRfcommServiceProvider)->get_ServiceId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMap<uint32_t, Windows::Storage::Streams::IBuffer> impl_IRfcommServiceProvider<D>::SdpRawAttributes() const
{
    Windows::Foundation::Collections::IMap<uint32_t, Windows::Storage::Streams::IBuffer> value;
    check_hresult(WINRT_SHIM(IRfcommServiceProvider)->get_SdpRawAttributes(put_abi(value)));
    return value;
}

template <typename D> void impl_IRfcommServiceProvider<D>::StartAdvertising(const Windows::Networking::Sockets::StreamSocketListener & listener) const
{
    check_hresult(WINRT_SHIM(IRfcommServiceProvider)->abi_StartAdvertising(get_abi(listener)));
}

template <typename D> void impl_IRfcommServiceProvider<D>::StopAdvertising() const
{
    check_hresult(WINRT_SHIM(IRfcommServiceProvider)->abi_StopAdvertising());
}

template <typename D> void impl_IRfcommServiceProvider2<D>::StartAdvertising(const Windows::Networking::Sockets::StreamSocketListener & listener, bool radioDiscoverable) const
{
    check_hresult(WINRT_SHIM(IRfcommServiceProvider2)->abi_StartAdvertisingWithRadioDiscoverability(get_abi(listener), radioDiscoverable));
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommDeviceService> RfcommDeviceService::FromIdAsync(hstring_view deviceId)
{
    return get_activation_factory<RfcommDeviceService, IRfcommDeviceServiceStatics>().FromIdAsync(deviceId);
}

inline hstring RfcommDeviceService::GetDeviceSelector(const Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId & serviceId)
{
    return get_activation_factory<RfcommDeviceService, IRfcommDeviceServiceStatics>().GetDeviceSelector(serviceId);
}

inline hstring RfcommDeviceService::GetDeviceSelectorForBluetoothDevice(const Windows::Devices::Bluetooth::BluetoothDevice & bluetoothDevice)
{
    return get_activation_factory<RfcommDeviceService, IRfcommDeviceServiceStatics2>().GetDeviceSelectorForBluetoothDevice(bluetoothDevice);
}

inline hstring RfcommDeviceService::GetDeviceSelectorForBluetoothDevice(const Windows::Devices::Bluetooth::BluetoothDevice & bluetoothDevice, Windows::Devices::Bluetooth::BluetoothCacheMode cacheMode)
{
    return get_activation_factory<RfcommDeviceService, IRfcommDeviceServiceStatics2>().GetDeviceSelectorForBluetoothDevice(bluetoothDevice, cacheMode);
}

inline hstring RfcommDeviceService::GetDeviceSelectorForBluetoothDeviceAndServiceId(const Windows::Devices::Bluetooth::BluetoothDevice & bluetoothDevice, const Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId & serviceId)
{
    return get_activation_factory<RfcommDeviceService, IRfcommDeviceServiceStatics2>().GetDeviceSelectorForBluetoothDeviceAndServiceId(bluetoothDevice, serviceId);
}

inline hstring RfcommDeviceService::GetDeviceSelectorForBluetoothDeviceAndServiceId(const Windows::Devices::Bluetooth::BluetoothDevice & bluetoothDevice, const Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId & serviceId, Windows::Devices::Bluetooth::BluetoothCacheMode cacheMode)
{
    return get_activation_factory<RfcommDeviceService, IRfcommDeviceServiceStatics2>().GetDeviceSelectorForBluetoothDeviceAndServiceId(bluetoothDevice, serviceId, cacheMode);
}

inline Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId RfcommServiceId::FromUuid(GUID uuid)
{
    return get_activation_factory<RfcommServiceId, IRfcommServiceIdStatics>().FromUuid(uuid);
}

inline Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId RfcommServiceId::FromShortId(uint32_t shortId)
{
    return get_activation_factory<RfcommServiceId, IRfcommServiceIdStatics>().FromShortId(shortId);
}

inline Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId RfcommServiceId::SerialPort()
{
    return get_activation_factory<RfcommServiceId, IRfcommServiceIdStatics>().SerialPort();
}

inline Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId RfcommServiceId::ObexObjectPush()
{
    return get_activation_factory<RfcommServiceId, IRfcommServiceIdStatics>().ObexObjectPush();
}

inline Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId RfcommServiceId::ObexFileTransfer()
{
    return get_activation_factory<RfcommServiceId, IRfcommServiceIdStatics>().ObexFileTransfer();
}

inline Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId RfcommServiceId::PhoneBookAccessPce()
{
    return get_activation_factory<RfcommServiceId, IRfcommServiceIdStatics>().PhoneBookAccessPce();
}

inline Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId RfcommServiceId::PhoneBookAccessPse()
{
    return get_activation_factory<RfcommServiceId, IRfcommServiceIdStatics>().PhoneBookAccessPse();
}

inline Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId RfcommServiceId::GenericFileTransfer()
{
    return get_activation_factory<RfcommServiceId, IRfcommServiceIdStatics>().GenericFileTransfer();
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Bluetooth::Rfcomm::RfcommServiceProvider> RfcommServiceProvider::CreateAsync(const Windows::Devices::Bluetooth::Rfcomm::RfcommServiceId & serviceId)
{
    return get_activation_factory<RfcommServiceProvider, IRfcommServiceProviderStatics>().CreateAsync(serviceId);
}

}

}
#pragma warning(pop)
