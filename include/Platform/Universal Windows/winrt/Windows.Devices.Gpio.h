// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Devices.Gpio.Provider.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Devices.Gpio.3.h"
#include "Windows.Devices.h"
#include "Windows.Foundation.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::Gpio::IGpioController> : produce_base<D, Windows::Devices::Gpio::IGpioController>
{
    HRESULT __stdcall get_PinCount(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PinCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OpenPin(int32_t pinNumber, impl::abi_arg_out<Windows::Devices::Gpio::IGpioPin> pin) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *pin = detach_abi(this->shim().OpenPin(pinNumber));
            return S_OK;
        }
        catch (...)
        {
            *pin = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OpenPinWithSharingMode(int32_t pinNumber, Windows::Devices::Gpio::GpioSharingMode sharingMode, impl::abi_arg_out<Windows::Devices::Gpio::IGpioPin> pin) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *pin = detach_abi(this->shim().OpenPin(pinNumber, sharingMode));
            return S_OK;
        }
        catch (...)
        {
            *pin = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryOpenPin(int32_t pinNumber, Windows::Devices::Gpio::GpioSharingMode sharingMode, impl::abi_arg_out<Windows::Devices::Gpio::IGpioPin> pin, Windows::Devices::Gpio::GpioOpenStatus * openStatus, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TryOpenPin(pinNumber, sharingMode, *pin, *openStatus));
            return S_OK;
        }
        catch (...)
        {
            *pin = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Gpio::IGpioControllerStatics> : produce_base<D, Windows::Devices::Gpio::IGpioControllerStatics>
{
    HRESULT __stdcall abi_GetDefault(impl::abi_arg_out<Windows::Devices::Gpio::IGpioController> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDefault());
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
struct produce<D, Windows::Devices::Gpio::IGpioControllerStatics2> : produce_base<D, Windows::Devices::Gpio::IGpioControllerStatics2>
{
    HRESULT __stdcall abi_GetControllersAsync(impl::abi_arg_in<Windows::Devices::Gpio::Provider::IGpioProvider> provider, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Gpio::GpioController>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetControllersAsync(*reinterpret_cast<const Windows::Devices::Gpio::Provider::IGpioProvider *>(&provider)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDefaultAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Gpio::GpioController>> operation) noexcept override
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
struct produce<D, Windows::Devices::Gpio::IGpioPin> : produce_base<D, Windows::Devices::Gpio::IGpioPin>
{
    HRESULT __stdcall add_ValueChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Gpio::GpioPin, Windows::Devices::Gpio::GpioPinValueChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ValueChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Gpio::GpioPin, Windows::Devices::Gpio::GpioPinValueChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ValueChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ValueChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DebounceTimeout(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DebounceTimeout());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DebounceTimeout(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DebounceTimeout(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PinNumber(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PinNumber());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SharingMode(Windows::Devices::Gpio::GpioSharingMode * value) noexcept override
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

    HRESULT __stdcall abi_IsDriveModeSupported(Windows::Devices::Gpio::GpioPinDriveMode driveMode, bool * supported) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *supported = detach_abi(this->shim().IsDriveModeSupported(driveMode));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDriveMode(Windows::Devices::Gpio::GpioPinDriveMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDriveMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetDriveMode(Windows::Devices::Gpio::GpioPinDriveMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetDriveMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Write(Windows::Devices::Gpio::GpioPinValue value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Write(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Read(Windows::Devices::Gpio::GpioPinValue * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Read());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Gpio::IGpioPinValueChangedEventArgs> : produce_base<D, Windows::Devices::Gpio::IGpioPinValueChangedEventArgs>
{
    HRESULT __stdcall get_Edge(Windows::Devices::Gpio::GpioPinEdge * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Edge());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Devices::Gpio {

template <typename D> Windows::Devices::Gpio::GpioPinEdge impl_IGpioPinValueChangedEventArgs<D>::Edge() const
{
    Windows::Devices::Gpio::GpioPinEdge value {};
    check_hresult(WINRT_SHIM(IGpioPinValueChangedEventArgs)->get_Edge(&value));
    return value;
}

template <typename D> int32_t impl_IGpioController<D>::PinCount() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IGpioController)->get_PinCount(&value));
    return value;
}

template <typename D> Windows::Devices::Gpio::GpioPin impl_IGpioController<D>::OpenPin(int32_t pinNumber) const
{
    Windows::Devices::Gpio::GpioPin pin { nullptr };
    check_hresult(WINRT_SHIM(IGpioController)->abi_OpenPin(pinNumber, put_abi(pin)));
    return pin;
}

template <typename D> Windows::Devices::Gpio::GpioPin impl_IGpioController<D>::OpenPin(int32_t pinNumber, Windows::Devices::Gpio::GpioSharingMode sharingMode) const
{
    Windows::Devices::Gpio::GpioPin pin { nullptr };
    check_hresult(WINRT_SHIM(IGpioController)->abi_OpenPinWithSharingMode(pinNumber, sharingMode, put_abi(pin)));
    return pin;
}

template <typename D> bool impl_IGpioController<D>::TryOpenPin(int32_t pinNumber, Windows::Devices::Gpio::GpioSharingMode sharingMode, Windows::Devices::Gpio::GpioPin & pin, Windows::Devices::Gpio::GpioOpenStatus & openStatus) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(IGpioController)->abi_TryOpenPin(pinNumber, sharingMode, put_abi(pin), &openStatus, &succeeded));
    return succeeded;
}

template <typename D> Windows::Devices::Gpio::GpioController impl_IGpioControllerStatics<D>::GetDefault() const
{
    Windows::Devices::Gpio::GpioController value { nullptr };
    check_hresult(WINRT_SHIM(IGpioControllerStatics)->abi_GetDefault(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Gpio::GpioController>> impl_IGpioControllerStatics2<D>::GetControllersAsync(const Windows::Devices::Gpio::Provider::IGpioProvider & provider) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Gpio::GpioController>> operation;
    check_hresult(WINRT_SHIM(IGpioControllerStatics2)->abi_GetControllersAsync(get_abi(provider), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Gpio::GpioController> impl_IGpioControllerStatics2<D>::GetDefaultAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Gpio::GpioController> operation;
    check_hresult(WINRT_SHIM(IGpioControllerStatics2)->abi_GetDefaultAsync(put_abi(operation)));
    return operation;
}

template <typename D> event_token impl_IGpioPin<D>::ValueChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Gpio::GpioPin, Windows::Devices::Gpio::GpioPinValueChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IGpioPin)->add_ValueChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IGpioPin> impl_IGpioPin<D>::ValueChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Gpio::GpioPin, Windows::Devices::Gpio::GpioPinValueChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IGpioPin>(this, &ABI::Windows::Devices::Gpio::IGpioPin::remove_ValueChanged, ValueChanged(handler));
}

template <typename D> void impl_IGpioPin<D>::ValueChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IGpioPin)->remove_ValueChanged(token));
}

template <typename D> Windows::Foundation::TimeSpan impl_IGpioPin<D>::DebounceTimeout() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IGpioPin)->get_DebounceTimeout(put_abi(value)));
    return value;
}

template <typename D> void impl_IGpioPin<D>::DebounceTimeout(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(IGpioPin)->put_DebounceTimeout(get_abi(value)));
}

template <typename D> int32_t impl_IGpioPin<D>::PinNumber() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IGpioPin)->get_PinNumber(&value));
    return value;
}

template <typename D> Windows::Devices::Gpio::GpioSharingMode impl_IGpioPin<D>::SharingMode() const
{
    Windows::Devices::Gpio::GpioSharingMode value {};
    check_hresult(WINRT_SHIM(IGpioPin)->get_SharingMode(&value));
    return value;
}

template <typename D> bool impl_IGpioPin<D>::IsDriveModeSupported(Windows::Devices::Gpio::GpioPinDriveMode driveMode) const
{
    bool supported {};
    check_hresult(WINRT_SHIM(IGpioPin)->abi_IsDriveModeSupported(driveMode, &supported));
    return supported;
}

template <typename D> Windows::Devices::Gpio::GpioPinDriveMode impl_IGpioPin<D>::GetDriveMode() const
{
    Windows::Devices::Gpio::GpioPinDriveMode value {};
    check_hresult(WINRT_SHIM(IGpioPin)->abi_GetDriveMode(&value));
    return value;
}

template <typename D> void impl_IGpioPin<D>::SetDriveMode(Windows::Devices::Gpio::GpioPinDriveMode value) const
{
    check_hresult(WINRT_SHIM(IGpioPin)->abi_SetDriveMode(value));
}

template <typename D> void impl_IGpioPin<D>::Write(Windows::Devices::Gpio::GpioPinValue value) const
{
    check_hresult(WINRT_SHIM(IGpioPin)->abi_Write(value));
}

template <typename D> Windows::Devices::Gpio::GpioPinValue impl_IGpioPin<D>::Read() const
{
    Windows::Devices::Gpio::GpioPinValue value {};
    check_hresult(WINRT_SHIM(IGpioPin)->abi_Read(&value));
    return value;
}

inline Windows::Devices::Gpio::GpioController GpioController::GetDefault()
{
    return get_activation_factory<GpioController, IGpioControllerStatics>().GetDefault();
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Gpio::GpioController>> GpioController::GetControllersAsync(const Windows::Devices::Gpio::Provider::IGpioProvider & provider)
{
    return get_activation_factory<GpioController, IGpioControllerStatics2>().GetControllersAsync(provider);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Gpio::GpioController> GpioController::GetDefaultAsync()
{
    return get_activation_factory<GpioController, IGpioControllerStatics2>().GetDefaultAsync();
}

}

}
#pragma warning(pop)
