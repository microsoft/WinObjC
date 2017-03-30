// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.UI.Input.Preview.Injection.0.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Input::Preview::Injection {

struct InjectedInputRectangle
{
    int32_t Left;
    int32_t Top;
    int32_t Bottom;
    int32_t Right;
};

struct InjectedInputPoint
{
    int32_t PositionX;
    int32_t PositionY;
};

struct InjectedInputPointerInfo
{
    uint32_t PointerId;
    winrt::Windows::UI::Input::Preview::Injection::InjectedInputPointerOptions PointerOptions;
    Windows::UI::Input::Preview::Injection::InjectedInputPoint PixelLocation;
    uint32_t TimeOffsetInMilliseconds;
    uint64_t PerformanceCount;
};

}

namespace Windows::UI::Input::Preview::Injection {

using InjectedInputRectangle = ABI::Windows::UI::Input::Preview::Injection::InjectedInputRectangle;
using InjectedInputPoint = ABI::Windows::UI::Input::Preview::Injection::InjectedInputPoint;
using InjectedInputPointerInfo = ABI::Windows::UI::Input::Preview::Injection::InjectedInputPointerInfo;

}

namespace ABI::Windows::UI::Input::Preview::Injection {

struct __declspec(uuid("4b46d140-2b6a-5ffa-7eae-bd077b052acd")) __declspec(novtable) IInjectedInputKeyboardInfo : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_KeyOptions(winrt::Windows::UI::Input::Preview::Injection::InjectedInputKeyOptions * value) = 0;
    virtual HRESULT __stdcall put_KeyOptions(winrt::Windows::UI::Input::Preview::Injection::InjectedInputKeyOptions value) = 0;
    virtual HRESULT __stdcall get_ScanCode(uint16_t * value) = 0;
    virtual HRESULT __stdcall put_ScanCode(uint16_t value) = 0;
    virtual HRESULT __stdcall get_VirtualKey(uint16_t * value) = 0;
    virtual HRESULT __stdcall put_VirtualKey(uint16_t value) = 0;
};

struct __declspec(uuid("96f56e6b-e47a-5cf4-418d-8a5fb9670c7d")) __declspec(novtable) IInjectedInputMouseInfo : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MouseOptions(winrt::Windows::UI::Input::Preview::Injection::InjectedInputMouseOptions * value) = 0;
    virtual HRESULT __stdcall put_MouseOptions(winrt::Windows::UI::Input::Preview::Injection::InjectedInputMouseOptions value) = 0;
    virtual HRESULT __stdcall get_MouseData(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_MouseData(uint32_t value) = 0;
    virtual HRESULT __stdcall get_DeltaY(int32_t * value) = 0;
    virtual HRESULT __stdcall put_DeltaY(int32_t value) = 0;
    virtual HRESULT __stdcall get_DeltaX(int32_t * value) = 0;
    virtual HRESULT __stdcall put_DeltaX(int32_t value) = 0;
    virtual HRESULT __stdcall get_TimeOffsetInMilliseconds(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_TimeOffsetInMilliseconds(uint32_t value) = 0;
};

struct __declspec(uuid("6b40ad03-ca1e-5527-7e02-2828540bb1d4")) __declspec(novtable) IInjectedInputPenInfo : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PointerInfo(Windows::UI::Input::Preview::Injection::InjectedInputPointerInfo * value) = 0;
    virtual HRESULT __stdcall put_PointerInfo(Windows::UI::Input::Preview::Injection::InjectedInputPointerInfo value) = 0;
    virtual HRESULT __stdcall get_PenButtons(winrt::Windows::UI::Input::Preview::Injection::InjectedInputPenButtons * value) = 0;
    virtual HRESULT __stdcall put_PenButtons(winrt::Windows::UI::Input::Preview::Injection::InjectedInputPenButtons value) = 0;
    virtual HRESULT __stdcall get_PenParameters(winrt::Windows::UI::Input::Preview::Injection::InjectedInputPenParameters * value) = 0;
    virtual HRESULT __stdcall put_PenParameters(winrt::Windows::UI::Input::Preview::Injection::InjectedInputPenParameters value) = 0;
    virtual HRESULT __stdcall get_Pressure(double * value) = 0;
    virtual HRESULT __stdcall put_Pressure(double value) = 0;
    virtual HRESULT __stdcall get_Rotation(double * value) = 0;
    virtual HRESULT __stdcall put_Rotation(double value) = 0;
    virtual HRESULT __stdcall get_TiltX(int32_t * value) = 0;
    virtual HRESULT __stdcall put_TiltX(int32_t value) = 0;
    virtual HRESULT __stdcall get_TiltY(int32_t * value) = 0;
    virtual HRESULT __stdcall put_TiltY(int32_t value) = 0;
};

struct __declspec(uuid("224fd1df-43e8-5ef5-510a-69ca8c9b4c28")) __declspec(novtable) IInjectedInputTouchInfo : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Contact(Windows::UI::Input::Preview::Injection::InjectedInputRectangle * value) = 0;
    virtual HRESULT __stdcall put_Contact(Windows::UI::Input::Preview::Injection::InjectedInputRectangle value) = 0;
    virtual HRESULT __stdcall get_Orientation(int32_t * value) = 0;
    virtual HRESULT __stdcall put_Orientation(int32_t value) = 0;
    virtual HRESULT __stdcall get_PointerInfo(Windows::UI::Input::Preview::Injection::InjectedInputPointerInfo * value) = 0;
    virtual HRESULT __stdcall put_PointerInfo(Windows::UI::Input::Preview::Injection::InjectedInputPointerInfo value) = 0;
    virtual HRESULT __stdcall get_Pressure(double * value) = 0;
    virtual HRESULT __stdcall put_Pressure(double value) = 0;
    virtual HRESULT __stdcall get_TouchParameters(winrt::Windows::UI::Input::Preview::Injection::InjectedInputTouchParameters * value) = 0;
    virtual HRESULT __stdcall put_TouchParameters(winrt::Windows::UI::Input::Preview::Injection::InjectedInputTouchParameters value) = 0;
};

struct __declspec(uuid("8ec26f84-0b02-4bd2-ad7a-3d4658be3e18")) __declspec(novtable) IInputInjector : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_InjectKeyboardInput(Windows::Foundation::Collections::IIterable<Windows::UI::Input::Preview::Injection::InjectedInputKeyboardInfo> * input) = 0;
    virtual HRESULT __stdcall abi_InjectMouseInput(Windows::Foundation::Collections::IIterable<Windows::UI::Input::Preview::Injection::InjectedInputMouseInfo> * input) = 0;
    virtual HRESULT __stdcall abi_InitializeTouchInjection(winrt::Windows::UI::Input::Preview::Injection::InjectedInputVisualizationMode visualMode) = 0;
    virtual HRESULT __stdcall abi_InjectTouchInput(Windows::Foundation::Collections::IIterable<Windows::UI::Input::Preview::Injection::InjectedInputTouchInfo> * input) = 0;
    virtual HRESULT __stdcall abi_UninitializeTouchInjection() = 0;
    virtual HRESULT __stdcall abi_InitializePenInjection(winrt::Windows::UI::Input::Preview::Injection::InjectedInputVisualizationMode visualMode) = 0;
    virtual HRESULT __stdcall abi_InjectPenInput(Windows::UI::Input::Preview::Injection::IInjectedInputPenInfo * input) = 0;
    virtual HRESULT __stdcall abi_UninitializePenInjection() = 0;
    virtual HRESULT __stdcall abi_InjectShortcut(winrt::Windows::UI::Input::Preview::Injection::InjectedInputShortcut shortcut) = 0;
};

struct __declspec(uuid("deae6943-7402-4141-a5c6-0c01aa57b16a")) __declspec(novtable) IInputInjectorStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_TryCreate(Windows::UI::Input::Preview::Injection::IInputInjector ** instance) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::UI::Input::Preview::Injection::InjectedInputKeyboardInfo> { using default_interface = Windows::UI::Input::Preview::Injection::IInjectedInputKeyboardInfo; };
template <> struct traits<Windows::UI::Input::Preview::Injection::InjectedInputMouseInfo> { using default_interface = Windows::UI::Input::Preview::Injection::IInjectedInputMouseInfo; };
template <> struct traits<Windows::UI::Input::Preview::Injection::InjectedInputPenInfo> { using default_interface = Windows::UI::Input::Preview::Injection::IInjectedInputPenInfo; };
template <> struct traits<Windows::UI::Input::Preview::Injection::InjectedInputTouchInfo> { using default_interface = Windows::UI::Input::Preview::Injection::IInjectedInputTouchInfo; };
template <> struct traits<Windows::UI::Input::Preview::Injection::InputInjector> { using default_interface = Windows::UI::Input::Preview::Injection::IInputInjector; };

}

namespace Windows::UI::Input::Preview::Injection {

template <typename D>
struct WINRT_EBO impl_IInjectedInputKeyboardInfo
{
    Windows::UI::Input::Preview::Injection::InjectedInputKeyOptions KeyOptions() const;
    void KeyOptions(Windows::UI::Input::Preview::Injection::InjectedInputKeyOptions value) const;
    uint16_t ScanCode() const;
    void ScanCode(uint16_t value) const;
    uint16_t VirtualKey() const;
    void VirtualKey(uint16_t value) const;
};

template <typename D>
struct WINRT_EBO impl_IInjectedInputMouseInfo
{
    Windows::UI::Input::Preview::Injection::InjectedInputMouseOptions MouseOptions() const;
    void MouseOptions(Windows::UI::Input::Preview::Injection::InjectedInputMouseOptions value) const;
    uint32_t MouseData() const;
    void MouseData(uint32_t value) const;
    int32_t DeltaY() const;
    void DeltaY(int32_t value) const;
    int32_t DeltaX() const;
    void DeltaX(int32_t value) const;
    uint32_t TimeOffsetInMilliseconds() const;
    void TimeOffsetInMilliseconds(uint32_t value) const;
};

template <typename D>
struct WINRT_EBO impl_IInjectedInputPenInfo
{
    Windows::UI::Input::Preview::Injection::InjectedInputPointerInfo PointerInfo() const;
    void PointerInfo(const Windows::UI::Input::Preview::Injection::InjectedInputPointerInfo & value) const;
    Windows::UI::Input::Preview::Injection::InjectedInputPenButtons PenButtons() const;
    void PenButtons(Windows::UI::Input::Preview::Injection::InjectedInputPenButtons value) const;
    Windows::UI::Input::Preview::Injection::InjectedInputPenParameters PenParameters() const;
    void PenParameters(Windows::UI::Input::Preview::Injection::InjectedInputPenParameters value) const;
    double Pressure() const;
    void Pressure(double value) const;
    double Rotation() const;
    void Rotation(double value) const;
    int32_t TiltX() const;
    void TiltX(int32_t value) const;
    int32_t TiltY() const;
    void TiltY(int32_t value) const;
};

template <typename D>
struct WINRT_EBO impl_IInjectedInputTouchInfo
{
    Windows::UI::Input::Preview::Injection::InjectedInputRectangle Contact() const;
    void Contact(const Windows::UI::Input::Preview::Injection::InjectedInputRectangle & value) const;
    int32_t Orientation() const;
    void Orientation(int32_t value) const;
    Windows::UI::Input::Preview::Injection::InjectedInputPointerInfo PointerInfo() const;
    void PointerInfo(const Windows::UI::Input::Preview::Injection::InjectedInputPointerInfo & value) const;
    double Pressure() const;
    void Pressure(double value) const;
    Windows::UI::Input::Preview::Injection::InjectedInputTouchParameters TouchParameters() const;
    void TouchParameters(Windows::UI::Input::Preview::Injection::InjectedInputTouchParameters value) const;
};

template <typename D>
struct WINRT_EBO impl_IInputInjector
{
    void InjectKeyboardInput(iterable<Windows::UI::Input::Preview::Injection::InjectedInputKeyboardInfo> input) const;
    void InjectMouseInput(iterable<Windows::UI::Input::Preview::Injection::InjectedInputMouseInfo> input) const;
    void InitializeTouchInjection(Windows::UI::Input::Preview::Injection::InjectedInputVisualizationMode visualMode) const;
    void InjectTouchInput(iterable<Windows::UI::Input::Preview::Injection::InjectedInputTouchInfo> input) const;
    void UninitializeTouchInjection() const;
    void InitializePenInjection(Windows::UI::Input::Preview::Injection::InjectedInputVisualizationMode visualMode) const;
    void InjectPenInput(const Windows::UI::Input::Preview::Injection::InjectedInputPenInfo & input) const;
    void UninitializePenInjection() const;
    void InjectShortcut(Windows::UI::Input::Preview::Injection::InjectedInputShortcut shortcut) const;
};

template <typename D>
struct WINRT_EBO impl_IInputInjectorStatics
{
    Windows::UI::Input::Preview::Injection::InputInjector TryCreate() const;
};

}

namespace impl {

template <> struct traits<Windows::UI::Input::Preview::Injection::IInjectedInputKeyboardInfo>
{
    using abi = ABI::Windows::UI::Input::Preview::Injection::IInjectedInputKeyboardInfo;
    template <typename D> using consume = Windows::UI::Input::Preview::Injection::impl_IInjectedInputKeyboardInfo<D>;
};

template <> struct traits<Windows::UI::Input::Preview::Injection::IInjectedInputMouseInfo>
{
    using abi = ABI::Windows::UI::Input::Preview::Injection::IInjectedInputMouseInfo;
    template <typename D> using consume = Windows::UI::Input::Preview::Injection::impl_IInjectedInputMouseInfo<D>;
};

template <> struct traits<Windows::UI::Input::Preview::Injection::IInjectedInputPenInfo>
{
    using abi = ABI::Windows::UI::Input::Preview::Injection::IInjectedInputPenInfo;
    template <typename D> using consume = Windows::UI::Input::Preview::Injection::impl_IInjectedInputPenInfo<D>;
};

template <> struct traits<Windows::UI::Input::Preview::Injection::IInjectedInputTouchInfo>
{
    using abi = ABI::Windows::UI::Input::Preview::Injection::IInjectedInputTouchInfo;
    template <typename D> using consume = Windows::UI::Input::Preview::Injection::impl_IInjectedInputTouchInfo<D>;
};

template <> struct traits<Windows::UI::Input::Preview::Injection::IInputInjector>
{
    using abi = ABI::Windows::UI::Input::Preview::Injection::IInputInjector;
    template <typename D> using consume = Windows::UI::Input::Preview::Injection::impl_IInputInjector<D>;
};

template <> struct traits<Windows::UI::Input::Preview::Injection::IInputInjectorStatics>
{
    using abi = ABI::Windows::UI::Input::Preview::Injection::IInputInjectorStatics;
    template <typename D> using consume = Windows::UI::Input::Preview::Injection::impl_IInputInjectorStatics<D>;
};

template <> struct traits<Windows::UI::Input::Preview::Injection::InjectedInputKeyboardInfo>
{
    using abi = ABI::Windows::UI::Input::Preview::Injection::InjectedInputKeyboardInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Input.Preview.Injection.InjectedInputKeyboardInfo"; }
};

template <> struct traits<Windows::UI::Input::Preview::Injection::InjectedInputMouseInfo>
{
    using abi = ABI::Windows::UI::Input::Preview::Injection::InjectedInputMouseInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Input.Preview.Injection.InjectedInputMouseInfo"; }
};

template <> struct traits<Windows::UI::Input::Preview::Injection::InjectedInputPenInfo>
{
    using abi = ABI::Windows::UI::Input::Preview::Injection::InjectedInputPenInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Input.Preview.Injection.InjectedInputPenInfo"; }
};

template <> struct traits<Windows::UI::Input::Preview::Injection::InjectedInputTouchInfo>
{
    using abi = ABI::Windows::UI::Input::Preview::Injection::InjectedInputTouchInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Input.Preview.Injection.InjectedInputTouchInfo"; }
};

template <> struct traits<Windows::UI::Input::Preview::Injection::InputInjector>
{
    using abi = ABI::Windows::UI::Input::Preview::Injection::InputInjector;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Input.Preview.Injection.InputInjector"; }
};

}

}
