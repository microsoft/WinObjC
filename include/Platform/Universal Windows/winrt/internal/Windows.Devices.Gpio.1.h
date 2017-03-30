// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Devices.Gpio.0.h"
#include "Windows.Devices.Gpio.Provider.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Gpio {

struct __declspec(uuid("284012e3-7461-469c-a8bc-61d69d08a53c")) __declspec(novtable) IGpioController : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PinCount(int32_t * value) = 0;
    virtual HRESULT __stdcall abi_OpenPin(int32_t pinNumber, Windows::Devices::Gpio::IGpioPin ** pin) = 0;
    virtual HRESULT __stdcall abi_OpenPinWithSharingMode(int32_t pinNumber, winrt::Windows::Devices::Gpio::GpioSharingMode sharingMode, Windows::Devices::Gpio::IGpioPin ** pin) = 0;
    virtual HRESULT __stdcall abi_TryOpenPin(int32_t pinNumber, winrt::Windows::Devices::Gpio::GpioSharingMode sharingMode, Windows::Devices::Gpio::IGpioPin ** pin, winrt::Windows::Devices::Gpio::GpioOpenStatus * openStatus, bool * succeeded) = 0;
};

struct __declspec(uuid("2ed6f42e-7af7-4116-9533-c43d99a1fb64")) __declspec(novtable) IGpioControllerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDefault(Windows::Devices::Gpio::IGpioController ** value) = 0;
};

struct __declspec(uuid("912b7d20-6ca4-4106-a373-fffd346b0e5b")) __declspec(novtable) IGpioControllerStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetControllersAsync(Windows::Devices::Gpio::Provider::IGpioProvider * provider, Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Gpio::GpioController>> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetDefaultAsync(Windows::Foundation::IAsyncOperation<Windows::Devices::Gpio::GpioController> ** operation) = 0;
};

struct __declspec(uuid("11d9b087-afae-4790-9ee9-e0eac942d201")) __declspec(novtable) IGpioPin : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_ValueChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::Gpio::GpioPin, Windows::Devices::Gpio::GpioPinValueChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ValueChanged(event_token token) = 0;
    virtual HRESULT __stdcall get_DebounceTimeout(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall put_DebounceTimeout(Windows::Foundation::TimeSpan value) = 0;
    virtual HRESULT __stdcall get_PinNumber(int32_t * value) = 0;
    virtual HRESULT __stdcall get_SharingMode(winrt::Windows::Devices::Gpio::GpioSharingMode * value) = 0;
    virtual HRESULT __stdcall abi_IsDriveModeSupported(winrt::Windows::Devices::Gpio::GpioPinDriveMode driveMode, bool * supported) = 0;
    virtual HRESULT __stdcall abi_GetDriveMode(winrt::Windows::Devices::Gpio::GpioPinDriveMode * value) = 0;
    virtual HRESULT __stdcall abi_SetDriveMode(winrt::Windows::Devices::Gpio::GpioPinDriveMode value) = 0;
    virtual HRESULT __stdcall abi_Write(winrt::Windows::Devices::Gpio::GpioPinValue value) = 0;
    virtual HRESULT __stdcall abi_Read(winrt::Windows::Devices::Gpio::GpioPinValue * value) = 0;
};

struct __declspec(uuid("3137aae1-703d-4059-bd24-b5b25dffb84e")) __declspec(novtable) IGpioPinValueChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Edge(winrt::Windows::Devices::Gpio::GpioPinEdge * value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Devices::Gpio::GpioController> { using default_interface = Windows::Devices::Gpio::IGpioController; };
template <> struct traits<Windows::Devices::Gpio::GpioPin> { using default_interface = Windows::Devices::Gpio::IGpioPin; };
template <> struct traits<Windows::Devices::Gpio::GpioPinValueChangedEventArgs> { using default_interface = Windows::Devices::Gpio::IGpioPinValueChangedEventArgs; };

}

namespace Windows::Devices::Gpio {

template <typename D>
struct WINRT_EBO impl_IGpioController
{
    int32_t PinCount() const;
    Windows::Devices::Gpio::GpioPin OpenPin(int32_t pinNumber) const;
    Windows::Devices::Gpio::GpioPin OpenPin(int32_t pinNumber, Windows::Devices::Gpio::GpioSharingMode sharingMode) const;
    bool TryOpenPin(int32_t pinNumber, Windows::Devices::Gpio::GpioSharingMode sharingMode, Windows::Devices::Gpio::GpioPin & pin, Windows::Devices::Gpio::GpioOpenStatus & openStatus) const;
};

template <typename D>
struct WINRT_EBO impl_IGpioControllerStatics
{
    Windows::Devices::Gpio::GpioController GetDefault() const;
};

template <typename D>
struct WINRT_EBO impl_IGpioControllerStatics2
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Gpio::GpioController>> GetControllersAsync(const Windows::Devices::Gpio::Provider::IGpioProvider & provider) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::Gpio::GpioController> GetDefaultAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IGpioPin
{
    event_token ValueChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Gpio::GpioPin, Windows::Devices::Gpio::GpioPinValueChangedEventArgs> & handler) const;
    using ValueChanged_revoker = event_revoker<IGpioPin>;
    ValueChanged_revoker ValueChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Gpio::GpioPin, Windows::Devices::Gpio::GpioPinValueChangedEventArgs> & handler) const;
    void ValueChanged(event_token token) const;
    Windows::Foundation::TimeSpan DebounceTimeout() const;
    void DebounceTimeout(const Windows::Foundation::TimeSpan & value) const;
    int32_t PinNumber() const;
    Windows::Devices::Gpio::GpioSharingMode SharingMode() const;
    bool IsDriveModeSupported(Windows::Devices::Gpio::GpioPinDriveMode driveMode) const;
    Windows::Devices::Gpio::GpioPinDriveMode GetDriveMode() const;
    void SetDriveMode(Windows::Devices::Gpio::GpioPinDriveMode value) const;
    void Write(Windows::Devices::Gpio::GpioPinValue value) const;
    Windows::Devices::Gpio::GpioPinValue Read() const;
};

template <typename D>
struct WINRT_EBO impl_IGpioPinValueChangedEventArgs
{
    Windows::Devices::Gpio::GpioPinEdge Edge() const;
};

}

namespace impl {

template <> struct traits<Windows::Devices::Gpio::IGpioController>
{
    using abi = ABI::Windows::Devices::Gpio::IGpioController;
    template <typename D> using consume = Windows::Devices::Gpio::impl_IGpioController<D>;
};

template <> struct traits<Windows::Devices::Gpio::IGpioControllerStatics>
{
    using abi = ABI::Windows::Devices::Gpio::IGpioControllerStatics;
    template <typename D> using consume = Windows::Devices::Gpio::impl_IGpioControllerStatics<D>;
};

template <> struct traits<Windows::Devices::Gpio::IGpioControllerStatics2>
{
    using abi = ABI::Windows::Devices::Gpio::IGpioControllerStatics2;
    template <typename D> using consume = Windows::Devices::Gpio::impl_IGpioControllerStatics2<D>;
};

template <> struct traits<Windows::Devices::Gpio::IGpioPin>
{
    using abi = ABI::Windows::Devices::Gpio::IGpioPin;
    template <typename D> using consume = Windows::Devices::Gpio::impl_IGpioPin<D>;
};

template <> struct traits<Windows::Devices::Gpio::IGpioPinValueChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Gpio::IGpioPinValueChangedEventArgs;
    template <typename D> using consume = Windows::Devices::Gpio::impl_IGpioPinValueChangedEventArgs<D>;
};

template <> struct traits<Windows::Devices::Gpio::GpioController>
{
    using abi = ABI::Windows::Devices::Gpio::GpioController;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Gpio.GpioController"; }
};

template <> struct traits<Windows::Devices::Gpio::GpioPin>
{
    using abi = ABI::Windows::Devices::Gpio::GpioPin;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Gpio.GpioPin"; }
};

template <> struct traits<Windows::Devices::Gpio::GpioPinValueChangedEventArgs>
{
    using abi = ABI::Windows::Devices::Gpio::GpioPinValueChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Gpio.GpioPinValueChangedEventArgs"; }
};

}

}
