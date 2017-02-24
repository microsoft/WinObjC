// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Devices.Spi.Provider.3.h"
#include "internal/Windows.Devices.Spi.3.h"
#include "Windows.Devices.h"
#include "Windows.Foundation.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::Spi::ISpiBusInfo> : produce_base<D, Windows::Devices::Spi::ISpiBusInfo>
{
    HRESULT __stdcall get_ChipSelectLineCount(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ChipSelectLineCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinClockFrequency(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinClockFrequency());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxClockFrequency(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxClockFrequency());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedDataBitLengths(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportedDataBitLengths());
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
struct produce<D, Windows::Devices::Spi::ISpiConnectionSettings> : produce_base<D, Windows::Devices::Spi::ISpiConnectionSettings>
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

    HRESULT __stdcall get_Mode(Windows::Devices::Spi::SpiMode * value) noexcept override
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

    HRESULT __stdcall put_Mode(Windows::Devices::Spi::SpiMode value) noexcept override
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

    HRESULT __stdcall get_SharingMode(Windows::Devices::Spi::SpiSharingMode * value) noexcept override
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

    HRESULT __stdcall put_SharingMode(Windows::Devices::Spi::SpiSharingMode value) noexcept override
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
struct produce<D, Windows::Devices::Spi::ISpiConnectionSettingsFactory> : produce_base<D, Windows::Devices::Spi::ISpiConnectionSettingsFactory>
{
    HRESULT __stdcall abi_Create(int32_t chipSelectLine, impl::abi_arg_out<Windows::Devices::Spi::ISpiConnectionSettings> value) noexcept override
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
struct produce<D, Windows::Devices::Spi::ISpiController> : produce_base<D, Windows::Devices::Spi::ISpiController>
{
    HRESULT __stdcall abi_GetDevice(impl::abi_arg_in<Windows::Devices::Spi::ISpiConnectionSettings> settings, impl::abi_arg_out<Windows::Devices::Spi::ISpiDevice> device) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *device = detach_abi(this->shim().GetDevice(*reinterpret_cast<const Windows::Devices::Spi::SpiConnectionSettings *>(&settings)));
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
struct produce<D, Windows::Devices::Spi::ISpiControllerStatics> : produce_base<D, Windows::Devices::Spi::ISpiControllerStatics>
{
    HRESULT __stdcall abi_GetDefaultAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Spi::SpiController>> operation) noexcept override
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

    HRESULT __stdcall abi_GetControllersAsync(impl::abi_arg_in<Windows::Devices::Spi::Provider::ISpiProvider> provider, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Spi::SpiController>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetControllersAsync(*reinterpret_cast<const Windows::Devices::Spi::Provider::ISpiProvider *>(&provider)));
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
struct produce<D, Windows::Devices::Spi::ISpiDevice> : produce_base<D, Windows::Devices::Spi::ISpiDevice>
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

    HRESULT __stdcall get_ConnectionSettings(impl::abi_arg_out<Windows::Devices::Spi::ISpiConnectionSettings> value) noexcept override
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
struct produce<D, Windows::Devices::Spi::ISpiDeviceStatics> : produce_base<D, Windows::Devices::Spi::ISpiDeviceStatics>
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

    HRESULT __stdcall abi_GetBusInfo(impl::abi_arg_in<hstring> busId, impl::abi_arg_out<Windows::Devices::Spi::ISpiBusInfo> busInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *busInfo = detach_abi(this->shim().GetBusInfo(*reinterpret_cast<const hstring *>(&busId)));
            return S_OK;
        }
        catch (...)
        {
            *busInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromIdAsync(impl::abi_arg_in<hstring> busId, impl::abi_arg_in<Windows::Devices::Spi::ISpiConnectionSettings> settings, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Spi::SpiDevice>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FromIdAsync(*reinterpret_cast<const hstring *>(&busId), *reinterpret_cast<const Windows::Devices::Spi::SpiConnectionSettings *>(&settings)));
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

namespace Windows::Devices::Spi {

template <typename D> Windows::Devices::Spi::SpiConnectionSettings impl_ISpiConnectionSettingsFactory<D>::Create(int32_t chipSelectLine) const
{
    Windows::Devices::Spi::SpiConnectionSettings value { nullptr };
    check_hresult(WINRT_SHIM(ISpiConnectionSettingsFactory)->abi_Create(chipSelectLine, put_abi(value)));
    return value;
}

template <typename D> int32_t impl_ISpiConnectionSettings<D>::ChipSelectLine() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ISpiConnectionSettings)->get_ChipSelectLine(&value));
    return value;
}

template <typename D> void impl_ISpiConnectionSettings<D>::ChipSelectLine(int32_t value) const
{
    check_hresult(WINRT_SHIM(ISpiConnectionSettings)->put_ChipSelectLine(value));
}

template <typename D> Windows::Devices::Spi::SpiMode impl_ISpiConnectionSettings<D>::Mode() const
{
    Windows::Devices::Spi::SpiMode value {};
    check_hresult(WINRT_SHIM(ISpiConnectionSettings)->get_Mode(&value));
    return value;
}

template <typename D> void impl_ISpiConnectionSettings<D>::Mode(Windows::Devices::Spi::SpiMode value) const
{
    check_hresult(WINRT_SHIM(ISpiConnectionSettings)->put_Mode(value));
}

template <typename D> int32_t impl_ISpiConnectionSettings<D>::DataBitLength() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ISpiConnectionSettings)->get_DataBitLength(&value));
    return value;
}

template <typename D> void impl_ISpiConnectionSettings<D>::DataBitLength(int32_t value) const
{
    check_hresult(WINRT_SHIM(ISpiConnectionSettings)->put_DataBitLength(value));
}

template <typename D> int32_t impl_ISpiConnectionSettings<D>::ClockFrequency() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ISpiConnectionSettings)->get_ClockFrequency(&value));
    return value;
}

template <typename D> void impl_ISpiConnectionSettings<D>::ClockFrequency(int32_t value) const
{
    check_hresult(WINRT_SHIM(ISpiConnectionSettings)->put_ClockFrequency(value));
}

template <typename D> Windows::Devices::Spi::SpiSharingMode impl_ISpiConnectionSettings<D>::SharingMode() const
{
    Windows::Devices::Spi::SpiSharingMode value {};
    check_hresult(WINRT_SHIM(ISpiConnectionSettings)->get_SharingMode(&value));
    return value;
}

template <typename D> void impl_ISpiConnectionSettings<D>::SharingMode(Windows::Devices::Spi::SpiSharingMode value) const
{
    check_hresult(WINRT_SHIM(ISpiConnectionSettings)->put_SharingMode(value));
}

template <typename D> int32_t impl_ISpiBusInfo<D>::ChipSelectLineCount() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ISpiBusInfo)->get_ChipSelectLineCount(&value));
    return value;
}

template <typename D> int32_t impl_ISpiBusInfo<D>::MinClockFrequency() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ISpiBusInfo)->get_MinClockFrequency(&value));
    return value;
}

template <typename D> int32_t impl_ISpiBusInfo<D>::MaxClockFrequency() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ISpiBusInfo)->get_MaxClockFrequency(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<int32_t> impl_ISpiBusInfo<D>::SupportedDataBitLengths() const
{
    Windows::Foundation::Collections::IVectorView<int32_t> value;
    check_hresult(WINRT_SHIM(ISpiBusInfo)->get_SupportedDataBitLengths(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISpiDeviceStatics<D>::GetDeviceSelector() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISpiDeviceStatics)->abi_GetDeviceSelector(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISpiDeviceStatics<D>::GetDeviceSelector(hstring_view friendlyName) const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISpiDeviceStatics)->abi_GetDeviceSelectorFromFriendlyName(get_abi(friendlyName), put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Spi::SpiBusInfo impl_ISpiDeviceStatics<D>::GetBusInfo(hstring_view busId) const
{
    Windows::Devices::Spi::SpiBusInfo busInfo { nullptr };
    check_hresult(WINRT_SHIM(ISpiDeviceStatics)->abi_GetBusInfo(get_abi(busId), put_abi(busInfo)));
    return busInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Spi::SpiDevice> impl_ISpiDeviceStatics<D>::FromIdAsync(hstring_view busId, const Windows::Devices::Spi::SpiConnectionSettings & settings) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Spi::SpiDevice> operation;
    check_hresult(WINRT_SHIM(ISpiDeviceStatics)->abi_FromIdAsync(get_abi(busId), get_abi(settings), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Devices::Spi::SpiDevice impl_ISpiController<D>::GetDevice(const Windows::Devices::Spi::SpiConnectionSettings & settings) const
{
    Windows::Devices::Spi::SpiDevice device { nullptr };
    check_hresult(WINRT_SHIM(ISpiController)->abi_GetDevice(get_abi(settings), put_abi(device)));
    return device;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Spi::SpiController> impl_ISpiControllerStatics<D>::GetDefaultAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Spi::SpiController> operation;
    check_hresult(WINRT_SHIM(ISpiControllerStatics)->abi_GetDefaultAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Spi::SpiController>> impl_ISpiControllerStatics<D>::GetControllersAsync(const Windows::Devices::Spi::Provider::ISpiProvider & provider) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Spi::SpiController>> operation;
    check_hresult(WINRT_SHIM(ISpiControllerStatics)->abi_GetControllersAsync(get_abi(provider), put_abi(operation)));
    return operation;
}

template <typename D> hstring impl_ISpiDevice<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISpiDevice)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Spi::SpiConnectionSettings impl_ISpiDevice<D>::ConnectionSettings() const
{
    Windows::Devices::Spi::SpiConnectionSettings value { nullptr };
    check_hresult(WINRT_SHIM(ISpiDevice)->get_ConnectionSettings(put_abi(value)));
    return value;
}

template <typename D> void impl_ISpiDevice<D>::Write(array_view<const uint8_t> buffer) const
{
    check_hresult(WINRT_SHIM(ISpiDevice)->abi_Write(buffer.size(), get_abi(buffer)));
}

template <typename D> void impl_ISpiDevice<D>::Read(array_view<uint8_t> buffer) const
{
    check_hresult(WINRT_SHIM(ISpiDevice)->abi_Read(buffer.size(), get_abi(buffer)));
}

template <typename D> void impl_ISpiDevice<D>::TransferSequential(array_view<const uint8_t> writeBuffer, array_view<uint8_t> readBuffer) const
{
    check_hresult(WINRT_SHIM(ISpiDevice)->abi_TransferSequential(writeBuffer.size(), get_abi(writeBuffer), readBuffer.size(), get_abi(readBuffer)));
}

template <typename D> void impl_ISpiDevice<D>::TransferFullDuplex(array_view<const uint8_t> writeBuffer, array_view<uint8_t> readBuffer) const
{
    check_hresult(WINRT_SHIM(ISpiDevice)->abi_TransferFullDuplex(writeBuffer.size(), get_abi(writeBuffer), readBuffer.size(), get_abi(readBuffer)));
}

inline SpiConnectionSettings::SpiConnectionSettings(int32_t chipSelectLine) :
    SpiConnectionSettings(get_activation_factory<SpiConnectionSettings, ISpiConnectionSettingsFactory>().Create(chipSelectLine))
{}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Spi::SpiController> SpiController::GetDefaultAsync()
{
    return get_activation_factory<SpiController, ISpiControllerStatics>().GetDefaultAsync();
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Spi::SpiController>> SpiController::GetControllersAsync(const Windows::Devices::Spi::Provider::ISpiProvider & provider)
{
    return get_activation_factory<SpiController, ISpiControllerStatics>().GetControllersAsync(provider);
}

inline hstring SpiDevice::GetDeviceSelector()
{
    return get_activation_factory<SpiDevice, ISpiDeviceStatics>().GetDeviceSelector();
}

inline hstring SpiDevice::GetDeviceSelector(hstring_view friendlyName)
{
    return get_activation_factory<SpiDevice, ISpiDeviceStatics>().GetDeviceSelector(friendlyName);
}

inline Windows::Devices::Spi::SpiBusInfo SpiDevice::GetBusInfo(hstring_view busId)
{
    return get_activation_factory<SpiDevice, ISpiDeviceStatics>().GetBusInfo(busId);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Spi::SpiDevice> SpiDevice::FromIdAsync(hstring_view busId, const Windows::Devices::Spi::SpiConnectionSettings & settings)
{
    return get_activation_factory<SpiDevice, ISpiDeviceStatics>().FromIdAsync(busId, settings);
}

}

}
#pragma warning(pop)
