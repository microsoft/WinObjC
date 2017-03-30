// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Devices.I2c.Provider.0.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::I2c::Provider {

struct ProviderI2cTransferResult
{
    winrt::Windows::Devices::I2c::Provider::ProviderI2cTransferStatus Status;
    uint32_t BytesTransferred;
};

}

namespace Windows::Devices::I2c::Provider {

using ProviderI2cTransferResult = ABI::Windows::Devices::I2c::Provider::ProviderI2cTransferResult;

}

namespace ABI::Windows::Devices::I2c::Provider {

struct __declspec(uuid("61c2bb82-4510-4163-a87c-4e15a9558980")) __declspec(novtable) II2cControllerProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDeviceProvider(Windows::Devices::I2c::Provider::IProviderI2cConnectionSettings * settings, Windows::Devices::I2c::Provider::II2cDeviceProvider ** device) = 0;
};

struct __declspec(uuid("ad342654-57e8-453e-8329-d1e447d103a9")) __declspec(novtable) II2cDeviceProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
    virtual HRESULT __stdcall abi_Write(uint32_t __bufferSize, uint8_t * buffer) = 0;
    virtual HRESULT __stdcall abi_WritePartial(uint32_t __bufferSize, uint8_t * buffer, Windows::Devices::I2c::Provider::ProviderI2cTransferResult * result) = 0;
    virtual HRESULT __stdcall abi_Read(uint32_t __bufferSize, uint8_t * buffer) = 0;
    virtual HRESULT __stdcall abi_ReadPartial(uint32_t __bufferSize, uint8_t * buffer, Windows::Devices::I2c::Provider::ProviderI2cTransferResult * result) = 0;
    virtual HRESULT __stdcall abi_WriteRead(uint32_t __writeBufferSize, uint8_t * writeBuffer, uint32_t __readBufferSize, uint8_t * readBuffer) = 0;
    virtual HRESULT __stdcall abi_WriteReadPartial(uint32_t __writeBufferSize, uint8_t * writeBuffer, uint32_t __readBufferSize, uint8_t * readBuffer, Windows::Devices::I2c::Provider::ProviderI2cTransferResult * result) = 0;
};

struct __declspec(uuid("6f13083e-bf62-4fe2-a95a-f08999669818")) __declspec(novtable) II2cProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetControllersAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::I2c::Provider::II2cControllerProvider>> ** operation) = 0;
};

struct __declspec(uuid("e9db4e34-e510-44b7-809d-f2f85b555339")) __declspec(novtable) IProviderI2cConnectionSettings : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SlaveAddress(int32_t * value) = 0;
    virtual HRESULT __stdcall put_SlaveAddress(int32_t value) = 0;
    virtual HRESULT __stdcall get_BusSpeed(winrt::Windows::Devices::I2c::Provider::ProviderI2cBusSpeed * value) = 0;
    virtual HRESULT __stdcall put_BusSpeed(winrt::Windows::Devices::I2c::Provider::ProviderI2cBusSpeed value) = 0;
    virtual HRESULT __stdcall get_SharingMode(winrt::Windows::Devices::I2c::Provider::ProviderI2cSharingMode * value) = 0;
    virtual HRESULT __stdcall put_SharingMode(winrt::Windows::Devices::I2c::Provider::ProviderI2cSharingMode value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Devices::I2c::Provider::ProviderI2cConnectionSettings> { using default_interface = Windows::Devices::I2c::Provider::IProviderI2cConnectionSettings; };

}

namespace Windows::Devices::I2c::Provider {

template <typename D>
struct WINRT_EBO impl_II2cControllerProvider
{
    Windows::Devices::I2c::Provider::II2cDeviceProvider GetDeviceProvider(const Windows::Devices::I2c::Provider::ProviderI2cConnectionSettings & settings) const;
};

template <typename D>
struct WINRT_EBO impl_II2cDeviceProvider
{
    hstring DeviceId() const;
    void Write(array_view<const uint8_t> buffer) const;
    Windows::Devices::I2c::Provider::ProviderI2cTransferResult WritePartial(array_view<const uint8_t> buffer) const;
    void Read(array_view<uint8_t> buffer) const;
    Windows::Devices::I2c::Provider::ProviderI2cTransferResult ReadPartial(array_view<uint8_t> buffer) const;
    void WriteRead(array_view<const uint8_t> writeBuffer, array_view<uint8_t> readBuffer) const;
    Windows::Devices::I2c::Provider::ProviderI2cTransferResult WriteReadPartial(array_view<const uint8_t> writeBuffer, array_view<uint8_t> readBuffer) const;
};

template <typename D>
struct WINRT_EBO impl_II2cProvider
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::I2c::Provider::II2cControllerProvider>> GetControllersAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IProviderI2cConnectionSettings
{
    int32_t SlaveAddress() const;
    void SlaveAddress(int32_t value) const;
    Windows::Devices::I2c::Provider::ProviderI2cBusSpeed BusSpeed() const;
    void BusSpeed(Windows::Devices::I2c::Provider::ProviderI2cBusSpeed value) const;
    Windows::Devices::I2c::Provider::ProviderI2cSharingMode SharingMode() const;
    void SharingMode(Windows::Devices::I2c::Provider::ProviderI2cSharingMode value) const;
};

}

namespace impl {

template <> struct traits<Windows::Devices::I2c::Provider::II2cControllerProvider>
{
    using abi = ABI::Windows::Devices::I2c::Provider::II2cControllerProvider;
    template <typename D> using consume = Windows::Devices::I2c::Provider::impl_II2cControllerProvider<D>;
};

template <> struct traits<Windows::Devices::I2c::Provider::II2cDeviceProvider>
{
    using abi = ABI::Windows::Devices::I2c::Provider::II2cDeviceProvider;
    template <typename D> using consume = Windows::Devices::I2c::Provider::impl_II2cDeviceProvider<D>;
};

template <> struct traits<Windows::Devices::I2c::Provider::II2cProvider>
{
    using abi = ABI::Windows::Devices::I2c::Provider::II2cProvider;
    template <typename D> using consume = Windows::Devices::I2c::Provider::impl_II2cProvider<D>;
};

template <> struct traits<Windows::Devices::I2c::Provider::IProviderI2cConnectionSettings>
{
    using abi = ABI::Windows::Devices::I2c::Provider::IProviderI2cConnectionSettings;
    template <typename D> using consume = Windows::Devices::I2c::Provider::impl_IProviderI2cConnectionSettings<D>;
};

template <> struct traits<Windows::Devices::I2c::Provider::ProviderI2cConnectionSettings>
{
    using abi = ABI::Windows::Devices::I2c::Provider::ProviderI2cConnectionSettings;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.I2c.Provider.ProviderI2cConnectionSettings"; }
};

}

}
