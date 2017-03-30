// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Devices.I2c.0.h"
#include "Windows.Devices.I2c.Provider.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::I2c {

struct I2cTransferResult
{
    winrt::Windows::Devices::I2c::I2cTransferStatus Status;
    uint32_t BytesTransferred;
};

}

namespace Windows::Devices::I2c {

using I2cTransferResult = ABI::Windows::Devices::I2c::I2cTransferResult;

}

namespace ABI::Windows::Devices::I2c {

struct __declspec(uuid("f2db1307-ab6f-4639-a767-54536dc3460f")) __declspec(novtable) II2cConnectionSettings : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SlaveAddress(int32_t * value) = 0;
    virtual HRESULT __stdcall put_SlaveAddress(int32_t value) = 0;
    virtual HRESULT __stdcall get_BusSpeed(winrt::Windows::Devices::I2c::I2cBusSpeed * value) = 0;
    virtual HRESULT __stdcall put_BusSpeed(winrt::Windows::Devices::I2c::I2cBusSpeed value) = 0;
    virtual HRESULT __stdcall get_SharingMode(winrt::Windows::Devices::I2c::I2cSharingMode * value) = 0;
    virtual HRESULT __stdcall put_SharingMode(winrt::Windows::Devices::I2c::I2cSharingMode value) = 0;
};

struct __declspec(uuid("81b586b3-9693-41b1-a243-ded4f6e66926")) __declspec(novtable) II2cConnectionSettingsFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(int32_t slaveAddress, Windows::Devices::I2c::II2cConnectionSettings ** value) = 0;
};

struct __declspec(uuid("c48ab1b2-87a0-4166-8e3e-b4b8f97cd729")) __declspec(novtable) II2cController : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDevice(Windows::Devices::I2c::II2cConnectionSettings * settings, Windows::Devices::I2c::II2cDevice ** device) = 0;
};

struct __declspec(uuid("40fc0365-5f05-4e7e-84bd-100db8e0aec5")) __declspec(novtable) II2cControllerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetControllersAsync(Windows::Devices::I2c::Provider::II2cProvider * provider, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::I2c::I2cController>> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetDefaultAsync(Windows::Foundation::IAsyncOperation<Windows::Devices::I2c::I2cController> ** operation) = 0;
};

struct __declspec(uuid("8636c136-b9c5-4f70-9449-cc46dc6f57eb")) __declspec(novtable) II2cDevice : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
    virtual HRESULT __stdcall get_ConnectionSettings(Windows::Devices::I2c::II2cConnectionSettings ** value) = 0;
    virtual HRESULT __stdcall abi_Write(uint32_t __bufferSize, uint8_t * buffer) = 0;
    virtual HRESULT __stdcall abi_WritePartial(uint32_t __bufferSize, uint8_t * buffer, Windows::Devices::I2c::I2cTransferResult * result) = 0;
    virtual HRESULT __stdcall abi_Read(uint32_t __bufferSize, uint8_t * buffer) = 0;
    virtual HRESULT __stdcall abi_ReadPartial(uint32_t __bufferSize, uint8_t * buffer, Windows::Devices::I2c::I2cTransferResult * result) = 0;
    virtual HRESULT __stdcall abi_WriteRead(uint32_t __writeBufferSize, uint8_t * writeBuffer, uint32_t __readBufferSize, uint8_t * readBuffer) = 0;
    virtual HRESULT __stdcall abi_WriteReadPartial(uint32_t __writeBufferSize, uint8_t * writeBuffer, uint32_t __readBufferSize, uint8_t * readBuffer, Windows::Devices::I2c::I2cTransferResult * result) = 0;
};

struct __declspec(uuid("91a33be3-7334-4512-96bc-fbae9459f5f6")) __declspec(novtable) II2cDeviceStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDeviceSelector(hstring * value) = 0;
    virtual HRESULT __stdcall abi_GetDeviceSelectorFromFriendlyName(hstring friendlyName, hstring * value) = 0;
    virtual HRESULT __stdcall abi_FromIdAsync(hstring deviceId, Windows::Devices::I2c::II2cConnectionSettings * settings, Windows::Foundation::IAsyncOperation<Windows::Devices::I2c::I2cDevice> ** operation) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Devices::I2c::I2cConnectionSettings> { using default_interface = Windows::Devices::I2c::II2cConnectionSettings; };
template <> struct traits<Windows::Devices::I2c::I2cController> { using default_interface = Windows::Devices::I2c::II2cController; };
template <> struct traits<Windows::Devices::I2c::I2cDevice> { using default_interface = Windows::Devices::I2c::II2cDevice; };

}

namespace Windows::Devices::I2c {

template <typename D>
struct WINRT_EBO impl_II2cConnectionSettings
{
    int32_t SlaveAddress() const;
    void SlaveAddress(int32_t value) const;
    Windows::Devices::I2c::I2cBusSpeed BusSpeed() const;
    void BusSpeed(Windows::Devices::I2c::I2cBusSpeed value) const;
    Windows::Devices::I2c::I2cSharingMode SharingMode() const;
    void SharingMode(Windows::Devices::I2c::I2cSharingMode value) const;
};

template <typename D>
struct WINRT_EBO impl_II2cConnectionSettingsFactory
{
    Windows::Devices::I2c::I2cConnectionSettings Create(int32_t slaveAddress) const;
};

template <typename D>
struct WINRT_EBO impl_II2cController
{
    Windows::Devices::I2c::I2cDevice GetDevice(const Windows::Devices::I2c::I2cConnectionSettings & settings) const;
};

template <typename D>
struct WINRT_EBO impl_II2cControllerStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::I2c::I2cController>> GetControllersAsync(const Windows::Devices::I2c::Provider::II2cProvider & provider) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::I2c::I2cController> GetDefaultAsync() const;
};

template <typename D>
struct WINRT_EBO impl_II2cDevice
{
    hstring DeviceId() const;
    Windows::Devices::I2c::I2cConnectionSettings ConnectionSettings() const;
    void Write(array_view<const uint8_t> buffer) const;
    Windows::Devices::I2c::I2cTransferResult WritePartial(array_view<const uint8_t> buffer) const;
    void Read(array_view<uint8_t> buffer) const;
    Windows::Devices::I2c::I2cTransferResult ReadPartial(array_view<uint8_t> buffer) const;
    void WriteRead(array_view<const uint8_t> writeBuffer, array_view<uint8_t> readBuffer) const;
    Windows::Devices::I2c::I2cTransferResult WriteReadPartial(array_view<const uint8_t> writeBuffer, array_view<uint8_t> readBuffer) const;
};

template <typename D>
struct WINRT_EBO impl_II2cDeviceStatics
{
    hstring GetDeviceSelector() const;
    hstring GetDeviceSelector(hstring_view friendlyName) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::I2c::I2cDevice> FromIdAsync(hstring_view deviceId, const Windows::Devices::I2c::I2cConnectionSettings & settings) const;
};

}

namespace impl {

template <> struct traits<Windows::Devices::I2c::II2cConnectionSettings>
{
    using abi = ABI::Windows::Devices::I2c::II2cConnectionSettings;
    template <typename D> using consume = Windows::Devices::I2c::impl_II2cConnectionSettings<D>;
};

template <> struct traits<Windows::Devices::I2c::II2cConnectionSettingsFactory>
{
    using abi = ABI::Windows::Devices::I2c::II2cConnectionSettingsFactory;
    template <typename D> using consume = Windows::Devices::I2c::impl_II2cConnectionSettingsFactory<D>;
};

template <> struct traits<Windows::Devices::I2c::II2cController>
{
    using abi = ABI::Windows::Devices::I2c::II2cController;
    template <typename D> using consume = Windows::Devices::I2c::impl_II2cController<D>;
};

template <> struct traits<Windows::Devices::I2c::II2cControllerStatics>
{
    using abi = ABI::Windows::Devices::I2c::II2cControllerStatics;
    template <typename D> using consume = Windows::Devices::I2c::impl_II2cControllerStatics<D>;
};

template <> struct traits<Windows::Devices::I2c::II2cDevice>
{
    using abi = ABI::Windows::Devices::I2c::II2cDevice;
    template <typename D> using consume = Windows::Devices::I2c::impl_II2cDevice<D>;
};

template <> struct traits<Windows::Devices::I2c::II2cDeviceStatics>
{
    using abi = ABI::Windows::Devices::I2c::II2cDeviceStatics;
    template <typename D> using consume = Windows::Devices::I2c::impl_II2cDeviceStatics<D>;
};

template <> struct traits<Windows::Devices::I2c::I2cConnectionSettings>
{
    using abi = ABI::Windows::Devices::I2c::I2cConnectionSettings;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.I2c.I2cConnectionSettings"; }
};

template <> struct traits<Windows::Devices::I2c::I2cController>
{
    using abi = ABI::Windows::Devices::I2c::I2cController;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.I2c.I2cController"; }
};

template <> struct traits<Windows::Devices::I2c::I2cDevice>
{
    using abi = ABI::Windows::Devices::I2c::I2cDevice;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.I2c.I2cDevice"; }
};

}

}
