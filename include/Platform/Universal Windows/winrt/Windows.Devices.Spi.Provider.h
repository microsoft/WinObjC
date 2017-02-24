// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Devices.Spi.Provider.3.h"
#include "Windows.Devices.Spi.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::Spi::Provider::IProviderSpiConnectionSettings> : produce_base<D, Windows::Devices::Spi::Provider::IProviderSpiConnectionSettings>
{
    HRESULT __stdcall get_ChipSelectLine(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ChipSelectLine());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ChipSelectLine(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ChipSelectLine(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Mode(Windows::Devices::Spi::Provider::ProviderSpiMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Mode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Mode(Windows::Devices::Spi::Provider::ProviderSpiMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Mode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DataBitLength(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DataBitLength());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DataBitLength(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DataBitLength(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ClockFrequency(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ClockFrequency());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ClockFrequency(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClockFrequency(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SharingMode(Windows::Devices::Spi::Provider::ProviderSpiSharingMode * value) noexcept override
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

    HRESULT __stdcall put_SharingMode(Windows::Devices::Spi::Provider::ProviderSpiSharingMode value) noexcept override
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
struct produce<D, Windows::Devices::Spi::Provider::IProviderSpiConnectionSettingsFactory> : produce_base<D, Windows::Devices::Spi::Provider::IProviderSpiConnectionSettingsFactory>
{
    HRESULT __stdcall abi_Create(int32_t chipSelectLine, impl::abi_arg_out<Windows::Devices::Spi::Provider::IProviderSpiConnectionSettings> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Create(chipSelectLine));
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
struct produce<D, Windows::Devices::Spi::Provider::ISpiControllerProvider> : produce_base<D, Windows::Devices::Spi::Provider::ISpiControllerProvider>
{
    HRESULT __stdcall abi_GetDeviceProvider(impl::abi_arg_in<Windows::Devices::Spi::Provider::IProviderSpiConnectionSettings> settings, impl::abi_arg_out<Windows::Devices::Spi::Provider::ISpiDeviceProvider> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDeviceProvider(*reinterpret_cast<const Windows::Devices::Spi::Provider::ProviderSpiConnectionSettings *>(&settings)));
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
struct produce<D, Windows::Devices::Spi::Provider::ISpiDeviceProvider> : produce_base<D, Windows::Devices::Spi::Provider::ISpiDeviceProvider>
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

    HRESULT __stdcall get_ConnectionSettings(impl::abi_arg_out<Windows::Devices::Spi::Provider::IProviderSpiConnectionSettings> value) noexcept override
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

    HRESULT __stdcall abi_TransferSequential(uint32_t __writeBufferSize, impl::abi_arg_in<uint8_t> * writeBuffer, uint32_t __readBufferSize, impl::abi_arg_out<uint8_t> readBuffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TransferSequential(array_view<const uint8_t>(writeBuffer, writeBuffer + __writeBufferSize), *readBuffer);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TransferFullDuplex(uint32_t __writeBufferSize, impl::abi_arg_in<uint8_t> * writeBuffer, uint32_t __readBufferSize, impl::abi_arg_out<uint8_t> readBuffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TransferFullDuplex(array_view<const uint8_t>(writeBuffer, writeBuffer + __writeBufferSize), *readBuffer);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Spi::Provider::ISpiProvider> : produce_base<D, Windows::Devices::Spi::Provider::ISpiProvider>
{
    HRESULT __stdcall abi_GetControllersAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Spi::Provider::ISpiControllerProvider>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetControllersAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Devices::Spi::Provider {

template <typename D> Windows::Devices::Spi::Provider::ProviderSpiConnectionSettings impl_IProviderSpiConnectionSettingsFactory<D>::Create(int32_t chipSelectLine) const
{
    Windows::Devices::Spi::Provider::ProviderSpiConnectionSettings value { nullptr };
    check_hresult(WINRT_SHIM(IProviderSpiConnectionSettingsFactory)->abi_Create(chipSelectLine, put_abi(value)));
    return value;
}

template <typename D> int32_t impl_IProviderSpiConnectionSettings<D>::ChipSelectLine() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IProviderSpiConnectionSettings)->get_ChipSelectLine(&value));
    return value;
}

template <typename D> void impl_IProviderSpiConnectionSettings<D>::ChipSelectLine(int32_t value) const
{
    check_hresult(WINRT_SHIM(IProviderSpiConnectionSettings)->put_ChipSelectLine(value));
}

template <typename D> Windows::Devices::Spi::Provider::ProviderSpiMode impl_IProviderSpiConnectionSettings<D>::Mode() const
{
    Windows::Devices::Spi::Provider::ProviderSpiMode value {};
    check_hresult(WINRT_SHIM(IProviderSpiConnectionSettings)->get_Mode(&value));
    return value;
}

template <typename D> void impl_IProviderSpiConnectionSettings<D>::Mode(Windows::Devices::Spi::Provider::ProviderSpiMode value) const
{
    check_hresult(WINRT_SHIM(IProviderSpiConnectionSettings)->put_Mode(value));
}

template <typename D> int32_t impl_IProviderSpiConnectionSettings<D>::DataBitLength() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IProviderSpiConnectionSettings)->get_DataBitLength(&value));
    return value;
}

template <typename D> void impl_IProviderSpiConnectionSettings<D>::DataBitLength(int32_t value) const
{
    check_hresult(WINRT_SHIM(IProviderSpiConnectionSettings)->put_DataBitLength(value));
}

template <typename D> int32_t impl_IProviderSpiConnectionSettings<D>::ClockFrequency() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IProviderSpiConnectionSettings)->get_ClockFrequency(&value));
    return value;
}

template <typename D> void impl_IProviderSpiConnectionSettings<D>::ClockFrequency(int32_t value) const
{
    check_hresult(WINRT_SHIM(IProviderSpiConnectionSettings)->put_ClockFrequency(value));
}

template <typename D> Windows::Devices::Spi::Provider::ProviderSpiSharingMode impl_IProviderSpiConnectionSettings<D>::SharingMode() const
{
    Windows::Devices::Spi::Provider::ProviderSpiSharingMode value {};
    check_hresult(WINRT_SHIM(IProviderSpiConnectionSettings)->get_SharingMode(&value));
    return value;
}

template <typename D> void impl_IProviderSpiConnectionSettings<D>::SharingMode(Windows::Devices::Spi::Provider::ProviderSpiSharingMode value) const
{
    check_hresult(WINRT_SHIM(IProviderSpiConnectionSettings)->put_SharingMode(value));
}

template <typename D> Windows::Devices::Spi::Provider::ISpiDeviceProvider impl_ISpiControllerProvider<D>::GetDeviceProvider(const Windows::Devices::Spi::Provider::ProviderSpiConnectionSettings & settings) const
{
    Windows::Devices::Spi::Provider::ISpiDeviceProvider result;
    check_hresult(WINRT_SHIM(ISpiControllerProvider)->abi_GetDeviceProvider(get_abi(settings), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Spi::Provider::ISpiControllerProvider>> impl_ISpiProvider<D>::GetControllersAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Spi::Provider::ISpiControllerProvider>> result;
    check_hresult(WINRT_SHIM(ISpiProvider)->abi_GetControllersAsync(put_abi(result)));
    return result;
}

template <typename D> hstring impl_ISpiDeviceProvider<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISpiDeviceProvider)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Spi::Provider::ProviderSpiConnectionSettings impl_ISpiDeviceProvider<D>::ConnectionSettings() const
{
    Windows::Devices::Spi::Provider::ProviderSpiConnectionSettings value { nullptr };
    check_hresult(WINRT_SHIM(ISpiDeviceProvider)->get_ConnectionSettings(put_abi(value)));
    return value;
}

template <typename D> void impl_ISpiDeviceProvider<D>::Write(array_view<const uint8_t> buffer) const
{
    check_hresult(WINRT_SHIM(ISpiDeviceProvider)->abi_Write(buffer.size(), get_abi(buffer)));
}

template <typename D> void impl_ISpiDeviceProvider<D>::Read(array_view<uint8_t> buffer) const
{
    check_hresult(WINRT_SHIM(ISpiDeviceProvider)->abi_Read(buffer.size(), get_abi(buffer)));
}

template <typename D> void impl_ISpiDeviceProvider<D>::TransferSequential(array_view<const uint8_t> writeBuffer, array_view<uint8_t> readBuffer) const
{
    check_hresult(WINRT_SHIM(ISpiDeviceProvider)->abi_TransferSequential(writeBuffer.size(), get_abi(writeBuffer), readBuffer.size(), get_abi(readBuffer)));
}

template <typename D> void impl_ISpiDeviceProvider<D>::TransferFullDuplex(array_view<const uint8_t> writeBuffer, array_view<uint8_t> readBuffer) const
{
    check_hresult(WINRT_SHIM(ISpiDeviceProvider)->abi_TransferFullDuplex(writeBuffer.size(), get_abi(writeBuffer), readBuffer.size(), get_abi(readBuffer)));
}

inline ProviderSpiConnectionSettings::ProviderSpiConnectionSettings(int32_t chipSelectLine) :
    ProviderSpiConnectionSettings(get_activation_factory<ProviderSpiConnectionSettings, IProviderSpiConnectionSettingsFactory>().Create(chipSelectLine))
{}

}

}
#pragma warning(pop)
