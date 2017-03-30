// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Input.Preview.Injection.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_15d6330f_9c97_5705_b677_872585664fb5
#define WINRT_GENERIC_15d6330f_9c97_5705_b677_872585664fb5
template <> struct __declspec(uuid("15d6330f-9c97-5705-b677-872585664fb5")) __declspec(novtable) IIterable<Windows::UI::Input::Preview::Injection::InjectedInputKeyboardInfo> : impl_IIterable<Windows::UI::Input::Preview::Injection::InjectedInputKeyboardInfo> {};
#endif

#ifndef WINRT_GENERIC_6c34e5bd_0fa4_5244_89fb_04bfd480ecd8
#define WINRT_GENERIC_6c34e5bd_0fa4_5244_89fb_04bfd480ecd8
template <> struct __declspec(uuid("6c34e5bd-0fa4-5244-89fb-04bfd480ecd8")) __declspec(novtable) IIterable<Windows::UI::Input::Preview::Injection::InjectedInputMouseInfo> : impl_IIterable<Windows::UI::Input::Preview::Injection::InjectedInputMouseInfo> {};
#endif

#ifndef WINRT_GENERIC_ac5fac0b_82a0_5436_9284_e7db0bf4e615
#define WINRT_GENERIC_ac5fac0b_82a0_5436_9284_e7db0bf4e615
template <> struct __declspec(uuid("ac5fac0b-82a0-5436-9284-e7db0bf4e615")) __declspec(novtable) IIterable<Windows::UI::Input::Preview::Injection::InjectedInputTouchInfo> : impl_IIterable<Windows::UI::Input::Preview::Injection::InjectedInputTouchInfo> {};
#endif

#ifndef WINRT_GENERIC_500e5efe_3bc1_5d9b_bcfc_c1f439505f12
#define WINRT_GENERIC_500e5efe_3bc1_5d9b_bcfc_c1f439505f12
template <> struct __declspec(uuid("500e5efe-3bc1-5d9b-bcfc-c1f439505f12")) __declspec(novtable) IIterator<Windows::UI::Input::Preview::Injection::InjectedInputKeyboardInfo> : impl_IIterator<Windows::UI::Input::Preview::Injection::InjectedInputKeyboardInfo> {};
#endif

#ifndef WINRT_GENERIC_9604d1d9_1744_5bd3_b5b9_d47b9434facb
#define WINRT_GENERIC_9604d1d9_1744_5bd3_b5b9_d47b9434facb
template <> struct __declspec(uuid("9604d1d9-1744-5bd3-b5b9-d47b9434facb")) __declspec(novtable) IIterator<Windows::UI::Input::Preview::Injection::InjectedInputMouseInfo> : impl_IIterator<Windows::UI::Input::Preview::Injection::InjectedInputMouseInfo> {};
#endif

#ifndef WINRT_GENERIC_4bc92e92_d32e_597a_ae24_b38861c5fb08
#define WINRT_GENERIC_4bc92e92_d32e_597a_ae24_b38861c5fb08
template <> struct __declspec(uuid("4bc92e92-d32e-597a-ae24-b38861c5fb08")) __declspec(novtable) IIterator<Windows::UI::Input::Preview::Injection::InjectedInputTouchInfo> : impl_IIterator<Windows::UI::Input::Preview::Injection::InjectedInputTouchInfo> {};
#endif


}

namespace Windows::UI::Input::Preview::Injection {

struct IInjectedInputKeyboardInfo :
    Windows::Foundation::IInspectable,
    impl::consume<IInjectedInputKeyboardInfo>
{
    IInjectedInputKeyboardInfo(std::nullptr_t = nullptr) noexcept {}
};

struct IInjectedInputMouseInfo :
    Windows::Foundation::IInspectable,
    impl::consume<IInjectedInputMouseInfo>
{
    IInjectedInputMouseInfo(std::nullptr_t = nullptr) noexcept {}
};

struct IInjectedInputPenInfo :
    Windows::Foundation::IInspectable,
    impl::consume<IInjectedInputPenInfo>
{
    IInjectedInputPenInfo(std::nullptr_t = nullptr) noexcept {}
};

struct IInjectedInputTouchInfo :
    Windows::Foundation::IInspectable,
    impl::consume<IInjectedInputTouchInfo>
{
    IInjectedInputTouchInfo(std::nullptr_t = nullptr) noexcept {}
};

struct IInputInjector :
    Windows::Foundation::IInspectable,
    impl::consume<IInputInjector>
{
    IInputInjector(std::nullptr_t = nullptr) noexcept {}
};

struct IInputInjectorStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IInputInjectorStatics>
{
    IInputInjectorStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
