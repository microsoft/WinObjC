// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Devices.Pwm.Provider.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Devices.Pwm.3.h"
#include "Windows.Devices.h"
#include "Windows.Foundation.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::Pwm::IPwmController> : produce_base<D, Windows::Devices::Pwm::IPwmController>
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

    HRESULT __stdcall get_ActualFrequency(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ActualFrequency());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetDesiredFrequency(double desiredFrequency, double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SetDesiredFrequency(desiredFrequency));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinFrequency(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinFrequency());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxFrequency(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxFrequency());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OpenPin(int32_t pinNumber, impl::abi_arg_out<Windows::Devices::Pwm::IPwmPin> pin) noexcept override
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
};

template <typename D>
struct produce<D, Windows::Devices::Pwm::IPwmControllerStatics> : produce_base<D, Windows::Devices::Pwm::IPwmControllerStatics>
{
    HRESULT __stdcall abi_GetControllersAsync(impl::abi_arg_in<Windows::Devices::Pwm::Provider::IPwmProvider> provider, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Pwm::PwmController>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetControllersAsync(*reinterpret_cast<const Windows::Devices::Pwm::Provider::IPwmProvider *>(&provider)));
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
struct produce<D, Windows::Devices::Pwm::IPwmControllerStatics2> : produce_base<D, Windows::Devices::Pwm::IPwmControllerStatics2>
{
    HRESULT __stdcall abi_GetDefaultAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Pwm::PwmController>> operation) noexcept override
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
struct produce<D, Windows::Devices::Pwm::IPwmPin> : produce_base<D, Windows::Devices::Pwm::IPwmPin>
{
    HRESULT __stdcall get_Controller(impl::abi_arg_out<Windows::Devices::Pwm::IPwmController> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Controller());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetActiveDutyCyclePercentage(double * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetActiveDutyCyclePercentage());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetActiveDutyCyclePercentage(double dutyCyclePercentage) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetActiveDutyCyclePercentage(dutyCyclePercentage);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Polarity(Windows::Devices::Pwm::PwmPulsePolarity * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Polarity());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Polarity(Windows::Devices::Pwm::PwmPulsePolarity value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Polarity(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Start() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Stop() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stop();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsStarted(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsStarted());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Devices::Pwm {

template <typename D> int32_t impl_IPwmController<D>::PinCount() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IPwmController)->get_PinCount(&value));
    return value;
}

template <typename D> double impl_IPwmController<D>::ActualFrequency() const
{
    double value {};
    check_hresult(WINRT_SHIM(IPwmController)->get_ActualFrequency(&value));
    return value;
}

template <typename D> double impl_IPwmController<D>::SetDesiredFrequency(double desiredFrequency) const
{
    double value {};
    check_hresult(WINRT_SHIM(IPwmController)->abi_SetDesiredFrequency(desiredFrequency, &value));
    return value;
}

template <typename D> double impl_IPwmController<D>::MinFrequency() const
{
    double value {};
    check_hresult(WINRT_SHIM(IPwmController)->get_MinFrequency(&value));
    return value;
}

template <typename D> double impl_IPwmController<D>::MaxFrequency() const
{
    double value {};
    check_hresult(WINRT_SHIM(IPwmController)->get_MaxFrequency(&value));
    return value;
}

template <typename D> Windows::Devices::Pwm::PwmPin impl_IPwmController<D>::OpenPin(int32_t pinNumber) const
{
    Windows::Devices::Pwm::PwmPin pin { nullptr };
    check_hresult(WINRT_SHIM(IPwmController)->abi_OpenPin(pinNumber, put_abi(pin)));
    return pin;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Pwm::PwmController>> impl_IPwmControllerStatics<D>::GetControllersAsync(const Windows::Devices::Pwm::Provider::IPwmProvider & provider) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Pwm::PwmController>> operation;
    check_hresult(WINRT_SHIM(IPwmControllerStatics)->abi_GetControllersAsync(get_abi(provider), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Pwm::PwmController> impl_IPwmControllerStatics2<D>::GetDefaultAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Pwm::PwmController> operation;
    check_hresult(WINRT_SHIM(IPwmControllerStatics2)->abi_GetDefaultAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Devices::Pwm::PwmController impl_IPwmPin<D>::Controller() const
{
    Windows::Devices::Pwm::PwmController value { nullptr };
    check_hresult(WINRT_SHIM(IPwmPin)->get_Controller(put_abi(value)));
    return value;
}

template <typename D> double impl_IPwmPin<D>::GetActiveDutyCyclePercentage() const
{
    double result {};
    check_hresult(WINRT_SHIM(IPwmPin)->abi_GetActiveDutyCyclePercentage(&result));
    return result;
}

template <typename D> void impl_IPwmPin<D>::SetActiveDutyCyclePercentage(double dutyCyclePercentage) const
{
    check_hresult(WINRT_SHIM(IPwmPin)->abi_SetActiveDutyCyclePercentage(dutyCyclePercentage));
}

template <typename D> Windows::Devices::Pwm::PwmPulsePolarity impl_IPwmPin<D>::Polarity() const
{
    Windows::Devices::Pwm::PwmPulsePolarity value {};
    check_hresult(WINRT_SHIM(IPwmPin)->get_Polarity(&value));
    return value;
}

template <typename D> void impl_IPwmPin<D>::Polarity(Windows::Devices::Pwm::PwmPulsePolarity value) const
{
    check_hresult(WINRT_SHIM(IPwmPin)->put_Polarity(value));
}

template <typename D> void impl_IPwmPin<D>::Start() const
{
    check_hresult(WINRT_SHIM(IPwmPin)->abi_Start());
}

template <typename D> void impl_IPwmPin<D>::Stop() const
{
    check_hresult(WINRT_SHIM(IPwmPin)->abi_Stop());
}

template <typename D> bool impl_IPwmPin<D>::IsStarted() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPwmPin)->get_IsStarted(&value));
    return value;
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Pwm::PwmController>> PwmController::GetControllersAsync(const Windows::Devices::Pwm::Provider::IPwmProvider & provider)
{
    return get_activation_factory<PwmController, IPwmControllerStatics>().GetControllersAsync(provider);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Pwm::PwmController> PwmController::GetDefaultAsync()
{
    return get_activation_factory<PwmController, IPwmControllerStatics2>().GetDefaultAsync();
}

}

}
#pragma warning(pop)
