// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Devices.Adc.Provider.3.h"
#include "internal/Windows.Devices.Pwm.Provider.3.h"
#include "internal/Windows.Devices.Gpio.Provider.3.h"
#include "internal/Windows.Devices.I2c.Provider.3.h"
#include "internal/Windows.Devices.Spi.Provider.3.h"
#include "internal/Windows.Devices.3.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::ILowLevelDevicesAggregateProvider> : produce_base<D, Windows::Devices::ILowLevelDevicesAggregateProvider>
{
    HRESULT __stdcall get_AdcControllerProvider(impl::abi_arg_out<Windows::Devices::Adc::Provider::IAdcControllerProvider> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AdcControllerProvider());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PwmControllerProvider(impl::abi_arg_out<Windows::Devices::Pwm::Provider::IPwmControllerProvider> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PwmControllerProvider());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_GpioControllerProvider(impl::abi_arg_out<Windows::Devices::Gpio::Provider::IGpioControllerProvider> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GpioControllerProvider());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_I2cControllerProvider(impl::abi_arg_out<Windows::Devices::I2c::Provider::II2cControllerProvider> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().I2cControllerProvider());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SpiControllerProvider(impl::abi_arg_out<Windows::Devices::Spi::Provider::ISpiControllerProvider> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SpiControllerProvider());
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
struct produce<D, Windows::Devices::ILowLevelDevicesAggregateProviderFactory> : produce_base<D, Windows::Devices::ILowLevelDevicesAggregateProviderFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Devices::Adc::Provider::IAdcControllerProvider> adc, impl::abi_arg_in<Windows::Devices::Pwm::Provider::IPwmControllerProvider> pwm, impl::abi_arg_in<Windows::Devices::Gpio::Provider::IGpioControllerProvider> gpio, impl::abi_arg_in<Windows::Devices::I2c::Provider::II2cControllerProvider> i2c, impl::abi_arg_in<Windows::Devices::Spi::Provider::ISpiControllerProvider> spi, impl::abi_arg_out<Windows::Devices::ILowLevelDevicesAggregateProvider> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Devices::Adc::Provider::IAdcControllerProvider *>(&adc), *reinterpret_cast<const Windows::Devices::Pwm::Provider::IPwmControllerProvider *>(&pwm), *reinterpret_cast<const Windows::Devices::Gpio::Provider::IGpioControllerProvider *>(&gpio), *reinterpret_cast<const Windows::Devices::I2c::Provider::II2cControllerProvider *>(&i2c), *reinterpret_cast<const Windows::Devices::Spi::Provider::ISpiControllerProvider *>(&spi)));
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
struct produce<D, Windows::Devices::ILowLevelDevicesController> : produce_base<D, Windows::Devices::ILowLevelDevicesController>
{};

template <typename D>
struct produce<D, Windows::Devices::ILowLevelDevicesControllerStatics> : produce_base<D, Windows::Devices::ILowLevelDevicesControllerStatics>
{
    HRESULT __stdcall get_DefaultProvider(impl::abi_arg_out<Windows::Devices::ILowLevelDevicesAggregateProvider> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DefaultProvider());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DefaultProvider(impl::abi_arg_in<Windows::Devices::ILowLevelDevicesAggregateProvider> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DefaultProvider(*reinterpret_cast<const Windows::Devices::ILowLevelDevicesAggregateProvider *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Devices {

template <typename D> Windows::Devices::Adc::Provider::IAdcControllerProvider impl_ILowLevelDevicesAggregateProvider<D>::AdcControllerProvider() const
{
    Windows::Devices::Adc::Provider::IAdcControllerProvider value;
    check_hresult(WINRT_SHIM(ILowLevelDevicesAggregateProvider)->get_AdcControllerProvider(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Pwm::Provider::IPwmControllerProvider impl_ILowLevelDevicesAggregateProvider<D>::PwmControllerProvider() const
{
    Windows::Devices::Pwm::Provider::IPwmControllerProvider value;
    check_hresult(WINRT_SHIM(ILowLevelDevicesAggregateProvider)->get_PwmControllerProvider(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Gpio::Provider::IGpioControllerProvider impl_ILowLevelDevicesAggregateProvider<D>::GpioControllerProvider() const
{
    Windows::Devices::Gpio::Provider::IGpioControllerProvider value;
    check_hresult(WINRT_SHIM(ILowLevelDevicesAggregateProvider)->get_GpioControllerProvider(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::I2c::Provider::II2cControllerProvider impl_ILowLevelDevicesAggregateProvider<D>::I2cControllerProvider() const
{
    Windows::Devices::I2c::Provider::II2cControllerProvider value;
    check_hresult(WINRT_SHIM(ILowLevelDevicesAggregateProvider)->get_I2cControllerProvider(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Spi::Provider::ISpiControllerProvider impl_ILowLevelDevicesAggregateProvider<D>::SpiControllerProvider() const
{
    Windows::Devices::Spi::Provider::ISpiControllerProvider value;
    check_hresult(WINRT_SHIM(ILowLevelDevicesAggregateProvider)->get_SpiControllerProvider(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::LowLevelDevicesAggregateProvider impl_ILowLevelDevicesAggregateProviderFactory<D>::Create(const Windows::Devices::Adc::Provider::IAdcControllerProvider & adc, const Windows::Devices::Pwm::Provider::IPwmControllerProvider & pwm, const Windows::Devices::Gpio::Provider::IGpioControllerProvider & gpio, const Windows::Devices::I2c::Provider::II2cControllerProvider & i2c, const Windows::Devices::Spi::Provider::ISpiControllerProvider & spi) const
{
    Windows::Devices::LowLevelDevicesAggregateProvider value { nullptr };
    check_hresult(WINRT_SHIM(ILowLevelDevicesAggregateProviderFactory)->abi_Create(get_abi(adc), get_abi(pwm), get_abi(gpio), get_abi(i2c), get_abi(spi), put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::ILowLevelDevicesAggregateProvider impl_ILowLevelDevicesControllerStatics<D>::DefaultProvider() const
{
    Windows::Devices::ILowLevelDevicesAggregateProvider value;
    check_hresult(WINRT_SHIM(ILowLevelDevicesControllerStatics)->get_DefaultProvider(put_abi(value)));
    return value;
}

template <typename D> void impl_ILowLevelDevicesControllerStatics<D>::DefaultProvider(const Windows::Devices::ILowLevelDevicesAggregateProvider & value) const
{
    check_hresult(WINRT_SHIM(ILowLevelDevicesControllerStatics)->put_DefaultProvider(get_abi(value)));
}

inline LowLevelDevicesAggregateProvider::LowLevelDevicesAggregateProvider(const Windows::Devices::Adc::Provider::IAdcControllerProvider & adc, const Windows::Devices::Pwm::Provider::IPwmControllerProvider & pwm, const Windows::Devices::Gpio::Provider::IGpioControllerProvider & gpio, const Windows::Devices::I2c::Provider::II2cControllerProvider & i2c, const Windows::Devices::Spi::Provider::ISpiControllerProvider & spi) :
    LowLevelDevicesAggregateProvider(get_activation_factory<LowLevelDevicesAggregateProvider, ILowLevelDevicesAggregateProviderFactory>().Create(adc, pwm, gpio, i2c, spi))
{}

inline Windows::Devices::ILowLevelDevicesAggregateProvider LowLevelDevicesController::DefaultProvider()
{
    return get_activation_factory<LowLevelDevicesController, ILowLevelDevicesControllerStatics>().DefaultProvider();
}

inline void LowLevelDevicesController::DefaultProvider(const Windows::Devices::ILowLevelDevicesAggregateProvider & value)
{
    get_activation_factory<LowLevelDevicesController, ILowLevelDevicesControllerStatics>().DefaultProvider(value);
}

}

}
#pragma warning(pop)
