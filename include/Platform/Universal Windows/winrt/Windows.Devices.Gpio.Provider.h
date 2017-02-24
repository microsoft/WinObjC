// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Devices.Gpio.Provider.3.h"
#include "Windows.Devices.Gpio.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::Gpio::Provider::IGpioControllerProvider> : produce_base<D, Windows::Devices::Gpio::Provider::IGpioControllerProvider>
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

    HRESULT __stdcall abi_OpenPinProvider(int32_t pin, Windows::Devices::Gpio::Provider::ProviderGpioSharingMode sharingMode, impl::abi_arg_out<Windows::Devices::Gpio::Provider::IGpioPinProvider> gpioPinProvider) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *gpioPinProvider = detach_abi(this->shim().OpenPinProvider(pin, sharingMode));
            return S_OK;
        }
        catch (...)
        {
            *gpioPinProvider = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Gpio::Provider::IGpioPinProvider> : produce_base<D, Windows::Devices::Gpio::Provider::IGpioPinProvider>
{
    HRESULT __stdcall add_ValueChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Gpio::Provider::IGpioPinProvider, Windows::Devices::Gpio::Provider::GpioPinProviderValueChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ValueChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Gpio::Provider::IGpioPinProvider, Windows::Devices::Gpio::Provider::GpioPinProviderValueChangedEventArgs> *>(&handler)));
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

    HRESULT __stdcall get_SharingMode(Windows::Devices::Gpio::Provider::ProviderGpioSharingMode * value) noexcept override
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

    HRESULT __stdcall abi_IsDriveModeSupported(Windows::Devices::Gpio::Provider::ProviderGpioPinDriveMode driveMode, bool * supported) noexcept override
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

    HRESULT __stdcall abi_GetDriveMode(Windows::Devices::Gpio::Provider::ProviderGpioPinDriveMode * value) noexcept override
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

    HRESULT __stdcall abi_SetDriveMode(Windows::Devices::Gpio::Provider::ProviderGpioPinDriveMode value) noexcept override
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

    HRESULT __stdcall abi_Write(Windows::Devices::Gpio::Provider::ProviderGpioPinValue value) noexcept override
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

    HRESULT __stdcall abi_Read(Windows::Devices::Gpio::Provider::ProviderGpioPinValue * value) noexcept override
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
struct produce<D, Windows::Devices::Gpio::Provider::IGpioPinProviderValueChangedEventArgs> : produce_base<D, Windows::Devices::Gpio::Provider::IGpioPinProviderValueChangedEventArgs>
{
    HRESULT __stdcall get_Edge(Windows::Devices::Gpio::Provider::ProviderGpioPinEdge * value) noexcept override
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

template <typename D>
struct produce<D, Windows::Devices::Gpio::Provider::IGpioPinProviderValueChangedEventArgsFactory> : produce_base<D, Windows::Devices::Gpio::Provider::IGpioPinProviderValueChangedEventArgsFactory>
{
    HRESULT __stdcall abi_Create(Windows::Devices::Gpio::Provider::ProviderGpioPinEdge edge, impl::abi_arg_out<Windows::Devices::Gpio::Provider::IGpioPinProviderValueChangedEventArgs> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Create(edge));
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
struct produce<D, Windows::Devices::Gpio::Provider::IGpioProvider> : produce_base<D, Windows::Devices::Gpio::Provider::IGpioProvider>
{
    HRESULT __stdcall abi_GetControllers(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Gpio::Provider::IGpioControllerProvider>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetControllers());
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

namespace Windows::Devices::Gpio::Provider {

template <typename D> Windows::Devices::Gpio::Provider::GpioPinProviderValueChangedEventArgs impl_IGpioPinProviderValueChangedEventArgsFactory<D>::Create(Windows::Devices::Gpio::Provider::ProviderGpioPinEdge edge) const
{
    Windows::Devices::Gpio::Provider::GpioPinProviderValueChangedEventArgs value { nullptr };
    check_hresult(WINRT_SHIM(IGpioPinProviderValueChangedEventArgsFactory)->abi_Create(edge, put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Gpio::Provider::ProviderGpioPinEdge impl_IGpioPinProviderValueChangedEventArgs<D>::Edge() const
{
    Windows::Devices::Gpio::Provider::ProviderGpioPinEdge value {};
    check_hresult(WINRT_SHIM(IGpioPinProviderValueChangedEventArgs)->get_Edge(&value));
    return value;
}

template <typename D> event_token impl_IGpioPinProvider<D>::ValueChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Gpio::Provider::IGpioPinProvider, Windows::Devices::Gpio::Provider::GpioPinProviderValueChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IGpioPinProvider)->add_ValueChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IGpioPinProvider> impl_IGpioPinProvider<D>::ValueChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Gpio::Provider::IGpioPinProvider, Windows::Devices::Gpio::Provider::GpioPinProviderValueChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IGpioPinProvider>(this, &ABI::Windows::Devices::Gpio::Provider::IGpioPinProvider::remove_ValueChanged, ValueChanged(handler));
}

template <typename D> void impl_IGpioPinProvider<D>::ValueChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IGpioPinProvider)->remove_ValueChanged(token));
}

template <typename D> Windows::Foundation::TimeSpan impl_IGpioPinProvider<D>::DebounceTimeout() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IGpioPinProvider)->get_DebounceTimeout(put_abi(value)));
    return value;
}

template <typename D> void impl_IGpioPinProvider<D>::DebounceTimeout(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(IGpioPinProvider)->put_DebounceTimeout(get_abi(value)));
}

template <typename D> int32_t impl_IGpioPinProvider<D>::PinNumber() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IGpioPinProvider)->get_PinNumber(&value));
    return value;
}

template <typename D> Windows::Devices::Gpio::Provider::ProviderGpioSharingMode impl_IGpioPinProvider<D>::SharingMode() const
{
    Windows::Devices::Gpio::Provider::ProviderGpioSharingMode value {};
    check_hresult(WINRT_SHIM(IGpioPinProvider)->get_SharingMode(&value));
    return value;
}

template <typename D> bool impl_IGpioPinProvider<D>::IsDriveModeSupported(Windows::Devices::Gpio::Provider::ProviderGpioPinDriveMode driveMode) const
{
    bool supported {};
    check_hresult(WINRT_SHIM(IGpioPinProvider)->abi_IsDriveModeSupported(driveMode, &supported));
    return supported;
}

template <typename D> Windows::Devices::Gpio::Provider::ProviderGpioPinDriveMode impl_IGpioPinProvider<D>::GetDriveMode() const
{
    Windows::Devices::Gpio::Provider::ProviderGpioPinDriveMode value {};
    check_hresult(WINRT_SHIM(IGpioPinProvider)->abi_GetDriveMode(&value));
    return value;
}

template <typename D> void impl_IGpioPinProvider<D>::SetDriveMode(Windows::Devices::Gpio::Provider::ProviderGpioPinDriveMode value) const
{
    check_hresult(WINRT_SHIM(IGpioPinProvider)->abi_SetDriveMode(value));
}

template <typename D> void impl_IGpioPinProvider<D>::Write(Windows::Devices::Gpio::Provider::ProviderGpioPinValue value) const
{
    check_hresult(WINRT_SHIM(IGpioPinProvider)->abi_Write(value));
}

template <typename D> Windows::Devices::Gpio::Provider::ProviderGpioPinValue impl_IGpioPinProvider<D>::Read() const
{
    Windows::Devices::Gpio::Provider::ProviderGpioPinValue value {};
    check_hresult(WINRT_SHIM(IGpioPinProvider)->abi_Read(&value));
    return value;
}

template <typename D> int32_t impl_IGpioControllerProvider<D>::PinCount() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IGpioControllerProvider)->get_PinCount(&value));
    return value;
}

template <typename D> Windows::Devices::Gpio::Provider::IGpioPinProvider impl_IGpioControllerProvider<D>::OpenPinProvider(int32_t pin, Windows::Devices::Gpio::Provider::ProviderGpioSharingMode sharingMode) const
{
    Windows::Devices::Gpio::Provider::IGpioPinProvider gpioPinProvider;
    check_hresult(WINRT_SHIM(IGpioControllerProvider)->abi_OpenPinProvider(pin, sharingMode, put_abi(gpioPinProvider)));
    return gpioPinProvider;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Gpio::Provider::IGpioControllerProvider> impl_IGpioProvider<D>::GetControllers() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Gpio::Provider::IGpioControllerProvider> result;
    check_hresult(WINRT_SHIM(IGpioProvider)->abi_GetControllers(put_abi(result)));
    return result;
}

inline GpioPinProviderValueChangedEventArgs::GpioPinProviderValueChangedEventArgs(Windows::Devices::Gpio::Provider::ProviderGpioPinEdge edge) :
    GpioPinProviderValueChangedEventArgs(get_activation_factory<GpioPinProviderValueChangedEventArgs, IGpioPinProviderValueChangedEventArgsFactory>().Create(edge))
{}

}

}
#pragma warning(pop)
