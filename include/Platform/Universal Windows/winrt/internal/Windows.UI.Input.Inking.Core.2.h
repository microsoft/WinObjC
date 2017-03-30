// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Input.Inking.Core.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_b83fbe98_882a_5b69_bd1c_c66690707fef
#define WINRT_GENERIC_b83fbe98_882a_5b69_bd1c_c66690707fef
template <> struct __declspec(uuid("b83fbe98-882a-5b69-bd1c-c66690707fef")) __declspec(novtable) TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> : impl_TypedEventHandler<Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource, Windows::UI::Core::PointerEventArgs> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_10c47202_47ab_58bc_91de_d5000f1a74c0
#define WINRT_GENERIC_10c47202_47ab_58bc_91de_d5000f1a74c0
template <> struct __declspec(uuid("10c47202-47ab-58bc-91de-d5000f1a74c0")) __declspec(novtable) IVector<Windows::UI::Input::Inking::InkPoint> : impl_IVector<Windows::UI::Input::Inking::InkPoint> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_67ff75e8_02a4_5254_a965_0b254c7d0788
#define WINRT_GENERIC_67ff75e8_02a4_5254_a965_0b254c7d0788
template <> struct __declspec(uuid("67ff75e8-02a4-5254-a965-0b254c7d0788")) __declspec(novtable) TypedEventHandler<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> : impl_TypedEventHandler<Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_d1ac414b_c87d_540f_8ab1_4e0d09d9d283
#define WINRT_GENERIC_d1ac414b_c87d_540f_8ab1_4e0d09d9d283
template <> struct __declspec(uuid("d1ac414b-c87d-540f-8ab1-4e0d09d9d283")) __declspec(novtable) IVectorView<Windows::UI::Input::Inking::InkPoint> : impl_IVectorView<Windows::UI::Input::Inking::InkPoint> {};
#endif

#ifndef WINRT_GENERIC_0630c0ef_a4e2_5af6_b2e9_8e042e294e17
#define WINRT_GENERIC_0630c0ef_a4e2_5af6_b2e9_8e042e294e17
template <> struct __declspec(uuid("0630c0ef-a4e2-5af6-b2e9-8e042e294e17")) __declspec(novtable) IIterable<Windows::UI::Input::Inking::InkPoint> : impl_IIterable<Windows::UI::Input::Inking::InkPoint> {};
#endif

#ifndef WINRT_GENERIC_47415452_db79_567e_84d5_e9912330f944
#define WINRT_GENERIC_47415452_db79_567e_84d5_e9912330f944
template <> struct __declspec(uuid("47415452-db79-567e-84d5-e9912330f944")) __declspec(novtable) IIterator<Windows::UI::Input::Inking::InkPoint> : impl_IIterator<Windows::UI::Input::Inking::InkPoint> {};
#endif


}

namespace Windows::UI::Input::Inking::Core {

struct ICoreInkIndependentInputSource :
    Windows::Foundation::IInspectable,
    impl::consume<ICoreInkIndependentInputSource>
{
    ICoreInkIndependentInputSource(std::nullptr_t = nullptr) noexcept {}
};

struct ICoreInkIndependentInputSourceStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ICoreInkIndependentInputSourceStatics>
{
    ICoreInkIndependentInputSourceStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ICoreWetStrokeUpdateEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<ICoreWetStrokeUpdateEventArgs>
{
    ICoreWetStrokeUpdateEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct ICoreWetStrokeUpdateSource :
    Windows::Foundation::IInspectable,
    impl::consume<ICoreWetStrokeUpdateSource>
{
    ICoreWetStrokeUpdateSource(std::nullptr_t = nullptr) noexcept {}
};

struct ICoreWetStrokeUpdateSourceStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ICoreWetStrokeUpdateSourceStatics>
{
    ICoreWetStrokeUpdateSourceStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
