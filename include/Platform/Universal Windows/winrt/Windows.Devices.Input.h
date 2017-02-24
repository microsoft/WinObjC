// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Devices.Input.3.h"
#include "Windows.Devices.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::Input::IKeyboardCapabilities> : produce_base<D, Windows::Devices::Input::IKeyboardCapabilities>
{
    HRESULT __stdcall get_KeyboardPresent(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().KeyboardPresent());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Input::IMouseCapabilities> : produce_base<D, Windows::Devices::Input::IMouseCapabilities>
{
    HRESULT __stdcall get_MousePresent(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MousePresent());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VerticalWheelPresent(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VerticalWheelPresent());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HorizontalWheelPresent(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HorizontalWheelPresent());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SwapButtons(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SwapButtons());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NumberOfButtons(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NumberOfButtons());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Input::IMouseDevice> : produce_base<D, Windows::Devices::Input::IMouseDevice>
{
    HRESULT __stdcall add_MouseMoved(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Input::MouseDevice, Windows::Devices::Input::MouseEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().MouseMoved(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Input::MouseDevice, Windows::Devices::Input::MouseEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_MouseMoved(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MouseMoved(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Input::IMouseDeviceStatics> : produce_base<D, Windows::Devices::Input::IMouseDeviceStatics>
{
    HRESULT __stdcall abi_GetForCurrentView(impl::abi_arg_out<Windows::Devices::Input::IMouseDevice> mouseDevice) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *mouseDevice = detach_abi(this->shim().GetForCurrentView());
            return S_OK;
        }
        catch (...)
        {
            *mouseDevice = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Input::IMouseEventArgs> : produce_base<D, Windows::Devices::Input::IMouseEventArgs>
{
    HRESULT __stdcall get_MouseDelta(impl::abi_arg_out<Windows::Devices::Input::MouseDelta> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MouseDelta());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Input::IPointerDevice> : produce_base<D, Windows::Devices::Input::IPointerDevice>
{
    HRESULT __stdcall get_PointerDeviceType(Windows::Devices::Input::PointerDeviceType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PointerDeviceType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsIntegrated(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsIntegrated());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxContacts(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxContacts());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PhysicalDeviceRect(impl::abi_arg_out<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PhysicalDeviceRect());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ScreenRect(impl::abi_arg_out<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ScreenRect());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedUsages(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Input::PointerDeviceUsage>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportedUsages());
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
struct produce<D, Windows::Devices::Input::IPointerDevice2> : produce_base<D, Windows::Devices::Input::IPointerDevice2>
{
    HRESULT __stdcall get_MaxPointersWithZDistance(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxPointersWithZDistance());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Input::IPointerDeviceStatics> : produce_base<D, Windows::Devices::Input::IPointerDeviceStatics>
{
    HRESULT __stdcall abi_GetPointerDevice(uint32_t pointerId, impl::abi_arg_out<Windows::Devices::Input::IPointerDevice> pointerDevice) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *pointerDevice = detach_abi(this->shim().GetPointerDevice(pointerId));
            return S_OK;
        }
        catch (...)
        {
            *pointerDevice = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPointerDevices(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Input::PointerDevice>> pointerDevices) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *pointerDevices = detach_abi(this->shim().GetPointerDevices());
            return S_OK;
        }
        catch (...)
        {
            *pointerDevices = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Input::ITouchCapabilities> : produce_base<D, Windows::Devices::Input::ITouchCapabilities>
{
    HRESULT __stdcall get_TouchPresent(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TouchPresent());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Contacts(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Contacts());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Devices::Input {

template <typename D> int32_t impl_IMouseCapabilities<D>::MousePresent() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IMouseCapabilities)->get_MousePresent(&value));
    return value;
}

template <typename D> int32_t impl_IMouseCapabilities<D>::VerticalWheelPresent() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IMouseCapabilities)->get_VerticalWheelPresent(&value));
    return value;
}

template <typename D> int32_t impl_IMouseCapabilities<D>::HorizontalWheelPresent() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IMouseCapabilities)->get_HorizontalWheelPresent(&value));
    return value;
}

template <typename D> int32_t impl_IMouseCapabilities<D>::SwapButtons() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IMouseCapabilities)->get_SwapButtons(&value));
    return value;
}

template <typename D> uint32_t impl_IMouseCapabilities<D>::NumberOfButtons() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMouseCapabilities)->get_NumberOfButtons(&value));
    return value;
}

template <typename D> int32_t impl_IKeyboardCapabilities<D>::KeyboardPresent() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IKeyboardCapabilities)->get_KeyboardPresent(&value));
    return value;
}

template <typename D> int32_t impl_ITouchCapabilities<D>::TouchPresent() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ITouchCapabilities)->get_TouchPresent(&value));
    return value;
}

template <typename D> uint32_t impl_ITouchCapabilities<D>::Contacts() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ITouchCapabilities)->get_Contacts(&value));
    return value;
}

template <typename D> Windows::Devices::Input::PointerDevice impl_IPointerDeviceStatics<D>::GetPointerDevice(uint32_t pointerId) const
{
    Windows::Devices::Input::PointerDevice pointerDevice { nullptr };
    check_hresult(WINRT_SHIM(IPointerDeviceStatics)->abi_GetPointerDevice(pointerId, put_abi(pointerDevice)));
    return pointerDevice;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Input::PointerDevice> impl_IPointerDeviceStatics<D>::GetPointerDevices() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Input::PointerDevice> pointerDevices;
    check_hresult(WINRT_SHIM(IPointerDeviceStatics)->abi_GetPointerDevices(put_abi(pointerDevices)));
    return pointerDevices;
}

template <typename D> Windows::Devices::Input::PointerDeviceType impl_IPointerDevice<D>::PointerDeviceType() const
{
    Windows::Devices::Input::PointerDeviceType value {};
    check_hresult(WINRT_SHIM(IPointerDevice)->get_PointerDeviceType(&value));
    return value;
}

template <typename D> bool impl_IPointerDevice<D>::IsIntegrated() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPointerDevice)->get_IsIntegrated(&value));
    return value;
}

template <typename D> uint32_t impl_IPointerDevice<D>::MaxContacts() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IPointerDevice)->get_MaxContacts(&value));
    return value;
}

template <typename D> Windows::Foundation::Rect impl_IPointerDevice<D>::PhysicalDeviceRect() const
{
    Windows::Foundation::Rect value {};
    check_hresult(WINRT_SHIM(IPointerDevice)->get_PhysicalDeviceRect(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Rect impl_IPointerDevice<D>::ScreenRect() const
{
    Windows::Foundation::Rect value {};
    check_hresult(WINRT_SHIM(IPointerDevice)->get_ScreenRect(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Input::PointerDeviceUsage> impl_IPointerDevice<D>::SupportedUsages() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Input::PointerDeviceUsage> value;
    check_hresult(WINRT_SHIM(IPointerDevice)->get_SupportedUsages(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IPointerDevice2<D>::MaxPointersWithZDistance() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IPointerDevice2)->get_MaxPointersWithZDistance(&value));
    return value;
}

template <typename D> Windows::Devices::Input::MouseDelta impl_IMouseEventArgs<D>::MouseDelta() const
{
    Windows::Devices::Input::MouseDelta value {};
    check_hresult(WINRT_SHIM(IMouseEventArgs)->get_MouseDelta(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IMouseDevice<D>::MouseMoved(const Windows::Foundation::TypedEventHandler<Windows::Devices::Input::MouseDevice, Windows::Devices::Input::MouseEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IMouseDevice)->add_MouseMoved(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IMouseDevice> impl_IMouseDevice<D>::MouseMoved(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Input::MouseDevice, Windows::Devices::Input::MouseEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMouseDevice>(this, &ABI::Windows::Devices::Input::IMouseDevice::remove_MouseMoved, MouseMoved(handler));
}

template <typename D> void impl_IMouseDevice<D>::MouseMoved(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IMouseDevice)->remove_MouseMoved(cookie));
}

template <typename D> Windows::Devices::Input::MouseDevice impl_IMouseDeviceStatics<D>::GetForCurrentView() const
{
    Windows::Devices::Input::MouseDevice mouseDevice { nullptr };
    check_hresult(WINRT_SHIM(IMouseDeviceStatics)->abi_GetForCurrentView(put_abi(mouseDevice)));
    return mouseDevice;
}

inline KeyboardCapabilities::KeyboardCapabilities() :
    KeyboardCapabilities(activate_instance<KeyboardCapabilities>())
{}

inline MouseCapabilities::MouseCapabilities() :
    MouseCapabilities(activate_instance<MouseCapabilities>())
{}

inline Windows::Devices::Input::MouseDevice MouseDevice::GetForCurrentView()
{
    return get_activation_factory<MouseDevice, IMouseDeviceStatics>().GetForCurrentView();
}

inline Windows::Devices::Input::PointerDevice PointerDevice::GetPointerDevice(uint32_t pointerId)
{
    return get_activation_factory<PointerDevice, IPointerDeviceStatics>().GetPointerDevice(pointerId);
}

inline Windows::Foundation::Collections::IVectorView<Windows::Devices::Input::PointerDevice> PointerDevice::GetPointerDevices()
{
    return get_activation_factory<PointerDevice, IPointerDeviceStatics>().GetPointerDevices();
}

inline TouchCapabilities::TouchCapabilities() :
    TouchCapabilities(activate_instance<TouchCapabilities>())
{}

}

}
#pragma warning(pop)
