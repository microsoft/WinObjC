// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Gaming.UI.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_c50898f6_c536_5f47_8583_8b2c2438a13b
#define WINRT_GENERIC_c50898f6_c536_5f47_8583_8b2c2438a13b
template <> struct __declspec(uuid("c50898f6-c536-5f47-8583-8b2c2438a13b")) __declspec(novtable) EventHandler<Windows::Foundation::IInspectable> : impl_EventHandler<Windows::Foundation::IInspectable> {};
#endif


}

namespace Windows::Gaming::UI {

struct IGameBarStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IGameBarStatics>
{
    IGameBarStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
