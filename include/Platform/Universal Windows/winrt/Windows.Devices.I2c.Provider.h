// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Devices.I2c.Provider.3.h"
#include "Windows.Devices.I2c.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::I2c::Provider::II2cControllerProvider> : produce_base<D, Windows::Devices::I2c::Provider::II2cControllerProvider>
{
    HRESULT __stdcall abi_GetDeviceProvider(impl::abi_arg_in<Windows::Devices::I2c::Provider::IProviderI2cConnectionSettings> settings, impl::abi_arg_out<Windows::Devices::I2c::Provider::II2cDeviceProvider> device) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *device = detach_abi(this->shim().GetDeviceProvider(*reinterpret_cast<const Windows::Devices::I2c::Provider::ProviderI2cConnectionSettings *>(&settings)));
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
struct produce<D, Windows::Devices::I2c::Provider::II2cDeviceProvider> : produce_base<D, Windows::Devices::I2c::Provider::II2cDeviceProvider>
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

    HRESULT __stdcall abi_WritePartial(uint32_t __bufferSize, impl::abi_arg_in<uint8_t> * buffer, impl::abi_arg_out<Windows::Devices::I2c::Provider::ProviderI2cTransferResult> result) noexcept override
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

    HRESULT __stdcall abi_ReadPartial(uint32_t __bufferSize, impl::abi_arg_out<uint8_t> buffer, impl::abi_arg_out<Windows::Devices::I2c::Provider::ProviderI2cTransferResult> result) noexcept override
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

    HRESULT __stdcall abi_WriteReadPartial(uint32_t __writeBufferSize, impl::abi_arg_in<uint8_t> * writeBuffer, uint32_t __readBufferSize, impl::abi_arg_out<uint8_t> readBuffer, impl::abi_arg_out<Windows::Devices::I2c::Provider::ProviderI2cTransferResult> result) noexcept override
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
struct produce<D, Windows::Devices::I2c::Provider::II2cProvider> : produce_base<D, Windows::Devices::I2c::Provider::II2cProvider>
{
    HRESULT __stdcall abi_GetControllersAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::I2c::Provider::II2cControllerProvider>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetControllersAsync());
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
struct produce<D, Windows::Devices::I2c::Provider::IProviderI2cConnectionSettings> : produce_base<D, Windows::Devices::I2c::Provider::IProviderI2cConnectionSettings>
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

    HRESULT __stdcall get_BusSpeed(Windows::Devices::I2c::Provider::ProviderI2cBusSpeed * value) noexcept override
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

    HRESULT __stdcall put_BusSpeed(Windows::Devices::I2c::Provider::ProviderI2cBusSpeed value) noexcept override
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

    HRESULT __stdcall get_SharingMode(Windows::Devices::I2c::Provider::ProviderI2cSharingMode * value) noexcept override
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

    HRESULT __stdcall put_SharingMode(Windows::Devices::I2c::Provider::ProviderI2cSharingMode value) noexcept override
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

}

namespace Windows::Devices::I2c::Provider {

template <typename D> int32_t impl_IProviderI2cConnectionSettings<D>::SlaveAddress() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IProviderI2cConnectionSettings)->get_SlaveAddress(&value));
    return value;
}

template <typename D> void impl_IProviderI2cConnectionSettings<D>::SlaveAddress(int32_t value) const
{
    check_hresult(WINRT_SHIM(IProviderI2cConnectionSettings)->put_SlaveAddress(value));
}

template <typename D> Windows::Devices::I2c::Provider::ProviderI2cBusSpeed impl_IProviderI2cConnectionSettings<D>::BusSpeed() const
{
    Windows::Devices::I2c::Provider::ProviderI2cBusSpeed value {};
    check_hresult(WINRT_SHIM(IProviderI2cConnectionSettings)->get_BusSpeed(&value));
    return value;
}

template <typename D> void impl_IProviderI2cConnectionSettings<D>::BusSpeed(Windows::Devices::I2c::Provider::ProviderI2cBusSpeed value) const
{
    check_hresult(WINRT_SHIM(IProviderI2cConnectionSettings)->put_BusSpeed(value));
}

template <typename D> Windows::Devices::I2c::Provider::ProviderI2cSharingMode impl_IProviderI2cConnectionSettings<D>::SharingMode() const
{
    Windows::Devices::I2c::Provider::ProviderI2cSharingMode value {};
    check_hresult(WINRT_SHIM(IProviderI2cConnectionSettings)->get_SharingMode(&value));
    return value;
}

template <typename D> void impl_IProviderI2cConnectionSettings<D>::SharingMode(Windows::Devices::I2c::Provider::ProviderI2cSharingMode value) const
{
    check_hresult(WINRT_SHIM(IProviderI2cConnectionSettings)->put_SharingMode(value));
}

template <typename D> Windows::Devices::I2c::Provider::II2cDeviceProvider impl_II2cControllerProvider<D>::GetDeviceProvider(const Windows::Devices::I2c::Provider::ProviderI2cConnectionSettings & settings) const
{
    Windows::Devices::I2c::Provider::II2cDeviceProvider device;
    check_hresult(WINRT_SHIM(II2cControllerProvider)->abi_GetDeviceProvider(get_abi(settings), put_abi(device)));
    return device;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::I2c::Provider::II2cControllerProvider>> impl_II2cProvider<D>::GetControllersAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::I2c::Provider::II2cControllerProvider>> operation;
    check_hresult(WINRT_SHIM(II2cProvider)->abi_GetControllersAsync(put_abi(operation)));
    return operation;
}

template <typename D> hstring impl_II2cDeviceProvider<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(II2cDeviceProvider)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> void impl_II2cDeviceProvider<D>::Write(array_view<const uint8_t> buffer) const
{
    check_hresult(WINRT_SHIM(II2cDeviceProvider)->abi_Write(buffer.size(), get_abi(buffer)));
}

template <typename D> Windows::Devices::I2c::Provider::ProviderI2cTransferResult impl_II2cDeviceProvider<D>::WritePartial(array_view<const uint8_t> buffer) const
{
    Windows::Devices::I2c::Provider::ProviderI2cTransferResult result {};
    check_hresult(WINRT_SHIM(II2cDeviceProvider)->abi_WritePartial(buffer.size(), get_abi(buffer), put_abi(result)));
    return result;
}

template <typename D> void impl_II2cDeviceProvider<D>::Read(array_view<uint8_t> buffer) const
{
    check_hresult(WINRT_SHIM(II2cDeviceProvider)->abi_Read(buffer.size(), get_abi(buffer)));
}

template <typename D> Windows::Devices::I2c::Provider::ProviderI2cTransferResult impl_II2cDeviceProvider<D>::ReadPartial(array_view<uint8_t> buffer) const
{
    Windows::Devices::I2c::Provider::ProviderI2cTransferResult result {};
    check_hresult(WINRT_SHIM(II2cDeviceProvider)->abi_ReadPartial(buffer.size(), get_abi(buffer), put_abi(result)));
    return result;
}

template <typename D> void impl_II2cDeviceProvider<D>::WriteRead(array_view<const uint8_t> writeBuffer, array_view<uint8_t> readBuffer) const
{
    check_hresult(WINRT_SHIM(II2cDeviceProvider)->abi_WriteRead(writeBuffer.size(), get_abi(writeBuffer), readBuffer.size(), get_abi(readBuffer)));
}

template <typename D> Windows::Devices::I2c::Provider::ProviderI2cTransferResult impl_II2cDeviceProvider<D>::WriteReadPartial(array_view<const uint8_t> writeBuffer, array_view<uint8_t> readBuffer) const
{
    Windows::Devices::I2c::Provider::ProviderI2cTransferResult result {};
    check_hresult(WINRT_SHIM(II2cDeviceProvider)->abi_WriteReadPartial(writeBuffer.size(), get_abi(writeBuffer), readBuffer.size(), get_abi(readBuffer), put_abi(result)));
    return result;
}

}

}
#pragma warning(pop)
