// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.UI.3.h"
#include "internal/Windows.Devices.Lights.3.h"
#include "Windows.Devices.h"
#include "Windows.Foundation.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::Lights::ILamp> : produce_base<D, Windows::Devices::Lights::ILamp>
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

    HRESULT __stdcall get_IsEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BrightnessLevel(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BrightnessLevel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BrightnessLevel(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BrightnessLevel(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsColorSettable(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsColorSettable());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Color(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Color());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Color(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Color(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_AvailabilityChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Lights::Lamp, Windows::Devices::Lights::LampAvailabilityChangedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().AvailabilityChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Lights::Lamp, Windows::Devices::Lights::LampAvailabilityChangedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AvailabilityChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AvailabilityChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Lights::ILampAvailabilityChangedEventArgs> : produce_base<D, Windows::Devices::Lights::ILampAvailabilityChangedEventArgs>
{
    HRESULT __stdcall get_IsAvailable(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsAvailable());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Lights::ILampStatics> : produce_base<D, Windows::Devices::Lights::ILampStatics>
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

    HRESULT __stdcall abi_FromIdAsync(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Lights::Lamp>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FromIdAsync(*reinterpret_cast<const hstring *>(&deviceId)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDefaultAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::Lights::Lamp>> operation) noexcept override
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

namespace Windows::Devices::Lights {

template <typename D> hstring impl_ILampStatics<D>::GetDeviceSelector() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ILampStatics)->abi_GetDeviceSelector(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Lights::Lamp> impl_ILampStatics<D>::FromIdAsync(hstring_view deviceId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Lights::Lamp> operation;
    check_hresult(WINRT_SHIM(ILampStatics)->abi_FromIdAsync(get_abi(deviceId), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::Lights::Lamp> impl_ILampStatics<D>::GetDefaultAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::Lights::Lamp> operation;
    check_hresult(WINRT_SHIM(ILampStatics)->abi_GetDefaultAsync(put_abi(operation)));
    return operation;
}

template <typename D> bool impl_ILampAvailabilityChangedEventArgs<D>::IsAvailable() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ILampAvailabilityChangedEventArgs)->get_IsAvailable(&value));
    return value;
}

template <typename D> hstring impl_ILamp<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ILamp)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> bool impl_ILamp<D>::IsEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ILamp)->get_IsEnabled(&value));
    return value;
}

template <typename D> void impl_ILamp<D>::IsEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(ILamp)->put_IsEnabled(value));
}

template <typename D> float impl_ILamp<D>::BrightnessLevel() const
{
    float value {};
    check_hresult(WINRT_SHIM(ILamp)->get_BrightnessLevel(&value));
    return value;
}

template <typename D> void impl_ILamp<D>::BrightnessLevel(float value) const
{
    check_hresult(WINRT_SHIM(ILamp)->put_BrightnessLevel(value));
}

template <typename D> bool impl_ILamp<D>::IsColorSettable() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ILamp)->get_IsColorSettable(&value));
    return value;
}

template <typename D> Windows::UI::Color impl_ILamp<D>::Color() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(ILamp)->get_Color(put_abi(value)));
    return value;
}

template <typename D> void impl_ILamp<D>::Color(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(ILamp)->put_Color(get_abi(value)));
}

template <typename D> event_token impl_ILamp<D>::AvailabilityChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Lights::Lamp, Windows::Devices::Lights::LampAvailabilityChangedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ILamp)->add_AvailabilityChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ILamp> impl_ILamp<D>::AvailabilityChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Lights::Lamp, Windows::Devices::Lights::LampAvailabilityChangedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ILamp>(this, &ABI::Windows::Devices::Lights::ILamp::remove_AvailabilityChanged, AvailabilityChanged(handler));
}

template <typename D> void impl_ILamp<D>::AvailabilityChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(ILamp)->remove_AvailabilityChanged(token));
}

inline hstring Lamp::GetDeviceSelector()
{
    return get_activation_factory<Lamp, ILampStatics>().GetDeviceSelector();
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Lights::Lamp> Lamp::FromIdAsync(hstring_view deviceId)
{
    return get_activation_factory<Lamp, ILampStatics>().FromIdAsync(deviceId);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::Lights::Lamp> Lamp::GetDefaultAsync()
{
    return get_activation_factory<Lamp, ILampStatics>().GetDefaultAsync();
}

}

}
#pragma warning(pop)
