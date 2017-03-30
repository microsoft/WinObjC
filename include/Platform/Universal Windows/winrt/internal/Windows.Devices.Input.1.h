// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Devices.Input.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Input {

struct PointerDeviceUsage
{
    uint32_t UsagePage;
    uint32_t Usage;
    int32_t MinLogical;
    int32_t MaxLogical;
    int32_t MinPhysical;
    int32_t MaxPhysical;
    uint32_t Unit;
    float PhysicalMultiplier;
};

struct MouseDelta
{
    int32_t X;
    int32_t Y;
};

}

namespace Windows::Devices::Input {

using PointerDeviceUsage = ABI::Windows::Devices::Input::PointerDeviceUsage;
using MouseDelta = ABI::Windows::Devices::Input::MouseDelta;

}

namespace ABI::Windows::Devices::Input {

struct __declspec(uuid("3a3f9b56-6798-4bbc-833e-0f34b17c65ff")) __declspec(novtable) IKeyboardCapabilities : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_KeyboardPresent(int32_t * value) = 0;
};

struct __declspec(uuid("bca5e023-7dd9-4b6b-9a92-55d43cb38f73")) __declspec(novtable) IMouseCapabilities : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MousePresent(int32_t * value) = 0;
    virtual HRESULT __stdcall get_VerticalWheelPresent(int32_t * value) = 0;
    virtual HRESULT __stdcall get_HorizontalWheelPresent(int32_t * value) = 0;
    virtual HRESULT __stdcall get_SwapButtons(int32_t * value) = 0;
    virtual HRESULT __stdcall get_NumberOfButtons(uint32_t * value) = 0;
};

struct __declspec(uuid("88edf458-f2c8-49f4-be1f-c256b388bc11")) __declspec(novtable) IMouseDevice : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_MouseMoved(Windows::Foundation::TypedEventHandler<Windows::Devices::Input::MouseDevice, Windows::Devices::Input::MouseEventArgs> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_MouseMoved(event_token cookie) = 0;
};

struct __declspec(uuid("484a9045-6d70-49db-8e68-46ffbd17d38d")) __declspec(novtable) IMouseDeviceStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetForCurrentView(Windows::Devices::Input::IMouseDevice ** mouseDevice) = 0;
};

struct __declspec(uuid("f625aa5d-2354-4cc7-9230-96941c969fde")) __declspec(novtable) IMouseEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MouseDelta(Windows::Devices::Input::MouseDelta * value) = 0;
};

struct __declspec(uuid("93c9bafc-ebcb-467e-82c6-276feae36b5a")) __declspec(novtable) IPointerDevice : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PointerDeviceType(winrt::Windows::Devices::Input::PointerDeviceType * value) = 0;
    virtual HRESULT __stdcall get_IsIntegrated(bool * value) = 0;
    virtual HRESULT __stdcall get_MaxContacts(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_PhysicalDeviceRect(Windows::Foundation::Rect * value) = 0;
    virtual HRESULT __stdcall get_ScreenRect(Windows::Foundation::Rect * value) = 0;
    virtual HRESULT __stdcall get_SupportedUsages(Windows::Foundation::Collections::IVectorView<Windows::Devices::Input::PointerDeviceUsage> ** value) = 0;
};

struct __declspec(uuid("f8a6d2a0-c484-489f-ae3e-30d2ee1ffd3e")) __declspec(novtable) IPointerDevice2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MaxPointersWithZDistance(uint32_t * value) = 0;
};

struct __declspec(uuid("d8b89aa1-d1c6-416e-bd8d-5790914dc563")) __declspec(novtable) IPointerDeviceStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetPointerDevice(uint32_t pointerId, Windows::Devices::Input::IPointerDevice ** pointerDevice) = 0;
    virtual HRESULT __stdcall abi_GetPointerDevices(Windows::Foundation::Collections::IVectorView<Windows::Devices::Input::PointerDevice> ** pointerDevices) = 0;
};

struct __declspec(uuid("20dd55f9-13f1-46c8-9285-2c05fa3eda6f")) __declspec(novtable) ITouchCapabilities : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TouchPresent(int32_t * value) = 0;
    virtual HRESULT __stdcall get_Contacts(uint32_t * value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Devices::Input::KeyboardCapabilities> { using default_interface = Windows::Devices::Input::IKeyboardCapabilities; };
template <> struct traits<Windows::Devices::Input::MouseCapabilities> { using default_interface = Windows::Devices::Input::IMouseCapabilities; };
template <> struct traits<Windows::Devices::Input::MouseDevice> { using default_interface = Windows::Devices::Input::IMouseDevice; };
template <> struct traits<Windows::Devices::Input::MouseEventArgs> { using default_interface = Windows::Devices::Input::IMouseEventArgs; };
template <> struct traits<Windows::Devices::Input::PointerDevice> { using default_interface = Windows::Devices::Input::IPointerDevice; };
template <> struct traits<Windows::Devices::Input::TouchCapabilities> { using default_interface = Windows::Devices::Input::ITouchCapabilities; };

}

namespace Windows::Devices::Input {

template <typename D>
struct WINRT_EBO impl_IKeyboardCapabilities
{
    int32_t KeyboardPresent() const;
};

template <typename D>
struct WINRT_EBO impl_IMouseCapabilities
{
    int32_t MousePresent() const;
    int32_t VerticalWheelPresent() const;
    int32_t HorizontalWheelPresent() const;
    int32_t SwapButtons() const;
    uint32_t NumberOfButtons() const;
};

template <typename D>
struct WINRT_EBO impl_IMouseDevice
{
    event_token MouseMoved(const Windows::Foundation::TypedEventHandler<Windows::Devices::Input::MouseDevice, Windows::Devices::Input::MouseEventArgs> & handler) const;
    using MouseMoved_revoker = event_revoker<IMouseDevice>;
    MouseMoved_revoker MouseMoved(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Input::MouseDevice, Windows::Devices::Input::MouseEventArgs> & handler) const;
    void MouseMoved(event_token cookie) const;
};

template <typename D>
struct WINRT_EBO impl_IMouseDeviceStatics
{
    Windows::Devices::Input::MouseDevice GetForCurrentView() const;
};

template <typename D>
struct WINRT_EBO impl_IMouseEventArgs
{
    Windows::Devices::Input::MouseDelta MouseDelta() const;
};

template <typename D>
struct WINRT_EBO impl_IPointerDevice
{
    Windows::Devices::Input::PointerDeviceType PointerDeviceType() const;
    bool IsIntegrated() const;
    uint32_t MaxContacts() const;
    Windows::Foundation::Rect PhysicalDeviceRect() const;
    Windows::Foundation::Rect ScreenRect() const;
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Input::PointerDeviceUsage> SupportedUsages() const;
};

template <typename D>
struct WINRT_EBO impl_IPointerDevice2
{
    uint32_t MaxPointersWithZDistance() const;
};

template <typename D>
struct WINRT_EBO impl_IPointerDeviceStatics
{
    Windows::Devices::Input::PointerDevice GetPointerDevice(uint32_t pointerId) const;
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Input::PointerDevice> GetPointerDevices() const;
};

template <typename D>
struct WINRT_EBO impl_ITouchCapabilities
{
    int32_t TouchPresent() const;
    uint32_t Contacts() const;
};

}

namespace impl {

template <> struct traits<Windows::Devices::Input::IKeyboardCapabilities>
{
    using abi = ABI::Windows::Devices::Input::IKeyboardCapabilities;
    template <typename D> using consume = Windows::Devices::Input::impl_IKeyboardCapabilities<D>;
};

template <> struct traits<Windows::Devices::Input::IMouseCapabilities>
{
    using abi = ABI::Windows::Devices::Input::IMouseCapabilities;
    template <typename D> using consume = Windows::Devices::Input::impl_IMouseCapabilities<D>;
};

template <> struct traits<Windows::Devices::Input::IMouseDevice>
{
    using abi = ABI::Windows::Devices::Input::IMouseDevice;
    template <typename D> using consume = Windows::Devices::Input::impl_IMouseDevice<D>;
};

template <> struct traits<Windows::Devices::Input::IMouseDeviceStatics>
{
    using abi = ABI::Windows::Devices::Input::IMouseDeviceStatics;
    template <typename D> using consume = Windows::Devices::Input::impl_IMouseDeviceStatics<D>;
};

template <> struct traits<Windows::Devices::Input::IMouseEventArgs>
{
    using abi = ABI::Windows::Devices::Input::IMouseEventArgs;
    template <typename D> using consume = Windows::Devices::Input::impl_IMouseEventArgs<D>;
};

template <> struct traits<Windows::Devices::Input::IPointerDevice>
{
    using abi = ABI::Windows::Devices::Input::IPointerDevice;
    template <typename D> using consume = Windows::Devices::Input::impl_IPointerDevice<D>;
};

template <> struct traits<Windows::Devices::Input::IPointerDevice2>
{
    using abi = ABI::Windows::Devices::Input::IPointerDevice2;
    template <typename D> using consume = Windows::Devices::Input::impl_IPointerDevice2<D>;
};

template <> struct traits<Windows::Devices::Input::IPointerDeviceStatics>
{
    using abi = ABI::Windows::Devices::Input::IPointerDeviceStatics;
    template <typename D> using consume = Windows::Devices::Input::impl_IPointerDeviceStatics<D>;
};

template <> struct traits<Windows::Devices::Input::ITouchCapabilities>
{
    using abi = ABI::Windows::Devices::Input::ITouchCapabilities;
    template <typename D> using consume = Windows::Devices::Input::impl_ITouchCapabilities<D>;
};

template <> struct traits<Windows::Devices::Input::KeyboardCapabilities>
{
    using abi = ABI::Windows::Devices::Input::KeyboardCapabilities;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Input.KeyboardCapabilities"; }
};

template <> struct traits<Windows::Devices::Input::MouseCapabilities>
{
    using abi = ABI::Windows::Devices::Input::MouseCapabilities;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Input.MouseCapabilities"; }
};

template <> struct traits<Windows::Devices::Input::MouseDevice>
{
    using abi = ABI::Windows::Devices::Input::MouseDevice;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Input.MouseDevice"; }
};

template <> struct traits<Windows::Devices::Input::MouseEventArgs>
{
    using abi = ABI::Windows::Devices::Input::MouseEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Input.MouseEventArgs"; }
};

template <> struct traits<Windows::Devices::Input::PointerDevice>
{
    using abi = ABI::Windows::Devices::Input::PointerDevice;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Input.PointerDevice"; }
};

template <> struct traits<Windows::Devices::Input::TouchCapabilities>
{
    using abi = ABI::Windows::Devices::Input::TouchCapabilities;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Input.TouchCapabilities"; }
};

}

}
