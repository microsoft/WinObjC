// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Devices.Pwm.Provider.0.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Pwm::Provider {

struct __declspec(uuid("1300593b-e2e3-40a4-b7d9-48dff0377a52")) __declspec(novtable) IPwmControllerProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PinCount(int32_t * value) = 0;
    virtual HRESULT __stdcall get_ActualFrequency(double * value) = 0;
    virtual HRESULT __stdcall abi_SetDesiredFrequency(double frequency, double * value) = 0;
    virtual HRESULT __stdcall get_MaxFrequency(double * value) = 0;
    virtual HRESULT __stdcall get_MinFrequency(double * value) = 0;
    virtual HRESULT __stdcall abi_AcquirePin(int32_t pin) = 0;
    virtual HRESULT __stdcall abi_ReleasePin(int32_t pin) = 0;
    virtual HRESULT __stdcall abi_EnablePin(int32_t pin) = 0;
    virtual HRESULT __stdcall abi_DisablePin(int32_t pin) = 0;
    virtual HRESULT __stdcall abi_SetPulseParameters(int32_t pin, double dutyCycle, bool invertPolarity) = 0;
};

struct __declspec(uuid("a3301228-52f1-47b0-9349-66ba43d25902")) __declspec(novtable) IPwmProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetControllers(Windows::Foundation::Collections::IVectorView<Windows::Devices::Pwm::Provider::IPwmControllerProvider> ** result) = 0;
};

}

namespace ABI {


}

namespace Windows::Devices::Pwm::Provider {

template <typename D>
struct WINRT_EBO impl_IPwmControllerProvider
{
    int32_t PinCount() const;
    double ActualFrequency() const;
    double SetDesiredFrequency(double frequency) const;
    double MaxFrequency() const;
    double MinFrequency() const;
    void AcquirePin(int32_t pin) const;
    void ReleasePin(int32_t pin) const;
    void EnablePin(int32_t pin) const;
    void DisablePin(int32_t pin) const;
    void SetPulseParameters(int32_t pin, double dutyCycle, bool invertPolarity) const;
};

template <typename D>
struct WINRT_EBO impl_IPwmProvider
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Pwm::Provider::IPwmControllerProvider> GetControllers() const;
};

}

namespace impl {

template <> struct traits<Windows::Devices::Pwm::Provider::IPwmControllerProvider>
{
    using abi = ABI::Windows::Devices::Pwm::Provider::IPwmControllerProvider;
    template <typename D> using consume = Windows::Devices::Pwm::Provider::impl_IPwmControllerProvider<D>;
};

template <> struct traits<Windows::Devices::Pwm::Provider::IPwmProvider>
{
    using abi = ABI::Windows::Devices::Pwm::Provider::IPwmProvider;
    template <typename D> using consume = Windows::Devices::Pwm::Provider::impl_IPwmProvider<D>;
};

}

}
