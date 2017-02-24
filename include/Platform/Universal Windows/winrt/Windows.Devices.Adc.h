// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Devices.Adc.Provider.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Devices.Adc.3.h"
#include "Windows.Devices.h"
#include "Windows.Foundation.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::Adc::IAdcChannel> : produce_base<D, Windows::Devices::Adc::IAdcChannel>
{
    HRESULT __stdcall get_Controller(impl::abi_arg_out<Windows::Devices::Adc::IAdcController> value) noexcept override
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

    HRESULT __stdcall abi_ReadValue(int32_t * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReadValue());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReadRatio(double * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReadRatio());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Adc::IAdcController> : produce_base<D, Windows::Devices::Adc::IAdcController>
{
    HRESULT __stdcall get_ChannelCount(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ChannelCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ResolutionInBits(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ResolutionInBits());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinValue(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinValue());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxValue(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxValue());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ChannelMode(Windows::Devices::Adc::AdcChannelMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ChannelMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ChannelMode(Windows::Devices::Adc::AdcChannelMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ChannelMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsChannelModeSupported(Windows::Devices::Adc::AdcChannelMode channelMode, bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsChannelModeSupported(channelMode));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OpenChannel(int32_t channelNumber, impl::abi_arg_out<Windows::Devices::Adc::IAdcChannel> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().OpenChannel(channelNumber));
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
struct produce<D, Windows::Devices::Adc::IAdcControllerStatics> : produce_base<D, Windows::Devices::Adc::IAdcControllerStatics>
{
    HRESULT __stdcall abi_GetControllersAsync(impl::abi_arg_in<Windows::Devices::Adc::Provider::IAdcProvider> provider, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Adc::AdcController>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetControllersAsync(*reinterpret_cast<const Windows::Devices::Adc::Provider::IAdcProvider *>(&provider)));
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
struct produce<D, Windows::Devices::Adc::IAdcControllerStatics2> : produce_base<D, Windows::Devices::Adc::IAdcControllerStatics2>
{
    HRESULT __stdcall abi_GetDefaultAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Adc::AdcController>> operation) noexcept override
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

}

namespace Windows::Devices::Adc {

template <typename D> int32_t impl_IAdcController<D>::ChannelCount() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IAdcController)->get_ChannelCount(&value));
    return value;
}

template <typename D> int32_t impl_IAdcController<D>::ResolutionInBits() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IAdcController)->get_ResolutionInBits(&value));
    return value;
}

template <typename D> int32_t impl_IAdcController<D>::MinValue() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IAdcController)->get_MinValue(&value));
    return value;
}

template <typename D> int32_t impl_IAdcController<D>::MaxValue() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IAdcController)->get_MaxValue(&value));
    return value;
}

template <typename D> Windows::Devices::Adc::AdcChannelMode impl_IAdcController<D>::ChannelMode() const
{
    Windows::Devices::Adc::AdcChannelMode value {};
    check_hresult(WINRT_SHIM(IAdcController)->get_ChannelMode(&value));
    return value;
}

template <typename D> void impl_IAdcController<D>::ChannelMode(Windows::Devices::Adc::AdcChannelMode value) const
{
    check_hresult(WINRT_SHIM(IAdcController)->put_ChannelMode(value));
}

template <typename D> bool impl_IAdcController<D>::IsChannelModeSupported(Windows::Devices::Adc::AdcChannelMode channelMode) const
{
    bool result {};
    check_hresult(WINRT_SHIM(IAdcController)->abi_IsChannelModeSupported(channelMode, &result));
    return result;
}

template <typename D> Windows::Devices::Adc::AdcChannel impl_IAdcController<D>::OpenChannel(int32_t channelNumber) const
{
    Windows::Devices::Adc::AdcChannel result { nullptr };
    check_hresult(WINRT_SHIM(IAdcController)->abi_OpenChannel(channelNumber, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Adc::AdcController>> impl_IAdcControllerStatics<D>::GetControllersAsync(const Windows::Devices::Adc::Provider::IAdcProvider & provider) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Adc::AdcController>> operation;
    check_hresult(WINRT_SHIM(IAdcControllerStatics)->abi_GetControllersAsync(get_abi(provider), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Adc::AdcController> impl_IAdcControllerStatics2<D>::GetDefaultAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Adc::AdcController> operation;
    check_hresult(WINRT_SHIM(IAdcControllerStatics2)->abi_GetDefaultAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Devices::Adc::AdcController impl_IAdcChannel<D>::Controller() const
{
    Windows::Devices::Adc::AdcController value { nullptr };
    check_hresult(WINRT_SHIM(IAdcChannel)->get_Controller(put_abi(value)));
    return value;
}

template <typename D> int32_t impl_IAdcChannel<D>::ReadValue() const
{
    int32_t result {};
    check_hresult(WINRT_SHIM(IAdcChannel)->abi_ReadValue(&result));
    return result;
}

template <typename D> double impl_IAdcChannel<D>::ReadRatio() const
{
    double result {};
    check_hresult(WINRT_SHIM(IAdcChannel)->abi_ReadRatio(&result));
    return result;
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Adc::AdcController>> AdcController::GetControllersAsync(const Windows::Devices::Adc::Provider::IAdcProvider & provider)
{
    return get_activation_factory<AdcController, IAdcControllerStatics>().GetControllersAsync(provider);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Adc::AdcController> AdcController::GetDefaultAsync()
{
    return get_activation_factory<AdcController, IAdcControllerStatics2>().GetDefaultAsync();
}

}

}
#pragma warning(pop)
