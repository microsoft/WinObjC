// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Devices.I2c.Provider.3.h"
#include "internal/Windows.Devices.I2c.3.h"
#include "Windows.Devices.h"
#include "Windows.Foundation.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::I2c::II2cConnectionSettings> : produce_base<D, Windows::Devices::I2c::II2cConnectionSettings>
{
    HRESULT __stdcall get_SlaveAddress(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SlaveAddress());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SlaveAddress(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SlaveAddress(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BusSpeed(Windows::Devices::I2c::I2cBusSpeed * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BusSpeed());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BusSpeed(Windows::Devices::I2c::I2cBusSpeed value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BusSpeed(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SharingMode(Windows::Devices::I2c::I2cSharingMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SharingMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SharingMode(Windows::Devices::I2c::I2cSharingMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SharingMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::I2c::II2cConnectionSettingsFactory> : produce_base<D, Windows::Devices::I2c::II2cConnectionSettingsFactory>
{
    HRESULT __stdcall abi_Create(int32_t slaveAddress, impl::abi_arg_out<Windows::Devices::I2c::II2cConnectionSettings> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Create(slaveAddress));
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
struct produce<D, Windows::Devices::I2c::II2cController> : produce_base<D, Windows::Devices::I2c::II2cController>
{
    HRESULT __stdcall abi_GetDevice(impl::abi_arg_in<Windows::Devices::I2c::II2cConnectionSettings> settings, impl::abi_arg_out<Windows::Devices::I2c::II2cDevice> device) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *device = detach_abi(this->shim().GetDevice(*reinterpret_cast<const Windows::Devices::I2c::I2cConnectionSettings *>(&settings)));
            return S_OK;
        }
        catch (...)
        {
            *device = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::I2c::II2cControllerStatics> : produce_base<D, Windows::Devices::I2c::II2cControllerStatics>
{
    HRESULT __stdcall abi_GetControllersAsync(impl::abi_arg_in<Windows::Devices::I2c::Provider::II2cProvider> provider, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::I2c::I2cController>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetControllersAsync(*reinterpret_cast<const Windows::Devices::I2c::Provider::II2cProvider *>(&provider)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDefaultAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::I2c::I2cController>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetDefaultAsync());
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
struct produce<D, Windows::Devices::I2c::II2cDevice> : produce_base<D, Windows::Devices::I2c::II2cDevice>
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

    HRESULT __stdcall get_ConnectionSettings(impl::abi_arg_out<Windows::Devices::I2c::II2cConnectionSettings> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ConnectionSettings());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Write(uint32_t __bufferSize, impl::abi_arg_in<uint8_t> * buffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Write(array_view<const uint8_t>(buffer, buffer + __bufferSize));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_WritePartial(uint32_t __bufferSize, impl::abi_arg_in<uint8_t> * buffer, impl::abi_arg_out<Windows::Devices::I2c::I2cTransferResult> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().WritePartial(array_view<const uint8_t>(buffer, buffer + __bufferSize)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Read(uint32_t __bufferSize, impl::abi_arg_out<uint8_t> buffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Read(*buffer);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReadPartial(uint32_t __bufferSize, impl::abi_arg_out<uint8_t> buffer, impl::abi_arg_out<Windows::Devices::I2c::I2cTransferResult> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReadPartial(*buffer));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_WriteRead(uint32_t __writeBufferSize, impl::abi_arg_in<uint8_t> * writeBuffer, uint32_t __readBufferSize, impl::abi_arg_out<uint8_t> readBuffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WriteRead(array_view<const uint8_t>(writeBuffer, writeBuffer + __writeBufferSize), *readBuffer);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_WriteReadPartial(uint32_t __writeBufferSize, impl::abi_arg_in<uint8_t> * writeBuffer, uint32_t __readBufferSize, impl::abi_arg_out<uint8_t> readBuffer, impl::abi_arg_out<Windows::Devices::I2c::I2cTransferResult> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().WriteReadPartial(array_view<const uint8_t>(writeBuffer, writeBuffer + __writeBufferSize), *readBuffer));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::I2c::II2cDeviceStatics> : produce_base<D, Windows::Devices::I2c::II2cDeviceStatics>
{
    HRESULT __stdcall abi_GetDeviceSelector(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDeviceSelector());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelectorFromFriendlyName(impl::abi_arg_in<hstring> friendlyName, impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDeviceSelector(*reinterpret_cast<const hstring *>(&friendlyName)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromIdAsync(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_in<Windows::Devices::I2c::II2cConnectionSettings> settings, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::I2c::I2cDevice>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FromIdAsync(*reinterpret_cast<const hstring *>(&deviceId), *reinterpret_cast<const Windows::Devices::I2c::I2cConnectionSettings *>(&settings)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Devices::I2c {

template <typename D> Windows::Devices::I2c::I2cConnectionSettings impl_II2cConnectionSettingsFactory<D>::Create(int32_t slaveAddress) const
{
    Windows::Devices::I2c::I2cConnectionSettings value { nullptr };
    check_hresult(WINRT_SHIM(II2cConnectionSettingsFactory)->abi_Create(slaveAddress, put_abi(value)));
    return value;
}

template <typename D> int32_t impl_II2cConnectionSettings<D>::SlaveAddress() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(II2cConnectionSettings)->get_SlaveAddress(&value));
    return value;
}

template <typename D> void impl_II2cConnectionSettings<D>::SlaveAddress(int32_t value) const
{
    check_hresult(WINRT_SHIM(II2cConnectionSettings)->put_SlaveAddress(value));
}

template <typename D> Windows::Devices::I2c::I2cBusSpeed impl_II2cConnectionSettings<D>::BusSpeed() const
{
    Windows::Devices::I2c::I2cBusSpeed value {};
    check_hresult(WINRT_SHIM(II2cConnectionSettings)->get_BusSpeed(&value));
    return value;
}

template <typename D> void impl_II2cConnectionSettings<D>::BusSpeed(Windows::Devices::I2c::I2cBusSpeed value) const
{
    check_hresult(WINRT_SHIM(II2cConnectionSettings)->put_BusSpeed(value));
}

template <typename D> Windows::Devices::I2c::I2cSharingMode impl_II2cConnectionSettings<D>::SharingMode() const
{
    Windows::Devices::I2c::I2cSharingMode value {};
    check_hresult(WINRT_SHIM(II2cConnectionSettings)->get_SharingMode(&value));
    return value;
}

template <typename D> void impl_II2cConnectionSettings<D>::SharingMode(Windows::Devices::I2c::I2cSharingMode value) const
{
    check_hresult(WINRT_SHIM(II2cConnectionSettings)->put_SharingMode(value));
}

template <typename D> hstring impl_II2cDeviceStatics<D>::GetDeviceSelector() const
{
    hstring value;
    check_hresult(WINRT_SHIM(II2cDeviceStatics)->abi_GetDeviceSelector(put_abi(value)));
    return value;
}

template <typename D> hstring impl_II2cDeviceStatics<D>::GetDeviceSelector(hstring_view friendlyName) const
{
    hstring value;
    check_hresult(WINRT_SHIM(II2cDeviceStatics)->abi_GetDeviceSelectorFromFriendlyName(get_abi(friendlyName), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::I2c::I2cDevice> impl_II2cDeviceStatics<D>::FromIdAsync(hstring_view deviceId, const Windows::Devices::I2c::I2cConnectionSettings & settings) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::I2c::I2cDevice> operation;
    check_hresult(WINRT_SHIM(II2cDeviceStatics)->abi_FromIdAsync(get_abi(deviceId), get_abi(settings), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Devices::I2c::I2cDevice impl_II2cController<D>::GetDevice(const Windows::Devices::I2c::I2cConnectionSettings & settings) const
{
    Windows::Devices::I2c::I2cDevice device { nullptr };
    check_hresult(WINRT_SHIM(II2cController)->abi_GetDevice(get_abi(settings), put_abi(device)));
    return device;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::I2c::I2cController>> impl_II2cControllerStatics<D>::GetControllersAsync(const Windows::Devices::I2c::Provider::II2cProvider & provider) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::I2c::I2cController>> operation;
    check_hresult(WINRT_SHIM(II2cControllerStatics)->abi_GetControllersAsync(get_abi(provider), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::I2c::I2cController> impl_II2cControllerStatics<D>::GetDefaultAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::I2c::I2cController> operation;
    check_hresult(WINRT_SHIM(II2cControllerStatics)->abi_GetDefaultAsync(put_abi(operation)));
    return operation;
}

template <typename D> hstring impl_II2cDevice<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(II2cDevice)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::I2c::I2cConnectionSettings impl_II2cDevice<D>::ConnectionSettings() const
{
    Windows::Devices::I2c::I2cConnectionSettings value { nullptr };
    check_hresult(WINRT_SHIM(II2cDevice)->get_ConnectionSettings(put_abi(value)));
    return value;
}

template <typename D> void impl_II2cDevice<D>::Write(array_view<const uint8_t> buffer) const
{
    check_hresult(WINRT_SHIM(II2cDevice)->abi_Write(buffer.size(), get_abi(buffer)));
}

template <typename D> Windows::Devices::I2c::I2cTransferResult impl_II2cDevice<D>::WritePartial(array_view<const uint8_t> buffer) const
{
    Windows::Devices::I2c::I2cTransferResult result {};
    check_hresult(WINRT_SHIM(II2cDevice)->abi_WritePartial(buffer.size(), get_abi(buffer), put_abi(result)));
    return result;
}

template <typename D> void impl_II2cDevice<D>::Read(array_view<uint8_t> buffer) const
{
    check_hresult(WINRT_SHIM(II2cDevice)->abi_Read(buffer.size(), get_abi(buffer)));
}

template <typename D> Windows::Devices::I2c::I2cTransferResult impl_II2cDevice<D>::ReadPartial(array_view<uint8_t> buffer) const
{
    Windows::Devices::I2c::I2cTransferResult result {};
    check_hresult(WINRT_SHIM(II2cDevice)->abi_ReadPartial(buffer.size(), get_abi(buffer), put_abi(result)));
    return result;
}

template <typename D> void impl_II2cDevice<D>::WriteRead(array_view<const uint8_t> writeBuffer, array_view<uint8_t> readBuffer) const
{
    check_hresult(WINRT_SHIM(II2cDevice)->abi_WriteRead(writeBuffer.size(), get_abi(writeBuffer), readBuffer.size(), get_abi(readBuffer)));
}

template <typename D> Windows::Devices::I2c::I2cTransferResult impl_II2cDevice<D>::WriteReadPartial(array_view<const uint8_t> writeBuffer, array_view<uint8_t> readBuffer) const
{
    Windows::Devices::I2c::I2cTransferResult result {};
    check_hresult(WINRT_SHIM(II2cDevice)->abi_WriteReadPartial(writeBuffer.size(), get_abi(writeBuffer), readBuffer.size(), get_abi(readBuffer), put_abi(result)));
    return result;
}

inline I2cConnectionSettings::I2cConnectionSettings(int32_t slaveAddress) :
    I2cConnectionSettings(get_activation_factory<I2cConnectionSettings, II2cConnectionSettingsFactory>().Create(slaveAddress))
{}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::I2c::I2cController>> I2cController::GetControllersAsync(const Windows::Devices::I2c::Provider::II2cProvider & provider)
{
    return get_activation_factory<I2cController, II2cControllerStatics>().GetControllersAsync(provider);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::I2c::I2cController> I2cController::GetDefaultAsync()
{
    return get_activation_factory<I2cController, II2cControllerStatics>().GetDefaultAsync();
}

inline hstring I2cDevice::GetDeviceSelector()
{
    return get_activation_factory<I2cDevice, II2cDeviceStatics>().GetDeviceSelector();
}

inline hstring I2cDevice::GetDeviceSelector(hstring_view friendlyName)
{
    return get_activation_factory<I2cDevice, II2cDeviceStatics>().GetDeviceSelector(friendlyName);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::I2c::I2cDevice> I2cDevice::FromIdAsync(hstring_view deviceId, const Windows::Devices::I2c::I2cConnectionSettings & settings)
{
    return get_activation_factory<I2cDevice, II2cDeviceStatics>().FromIdAsync(deviceId, settings);
}

}

}
#pragma warning(pop)
