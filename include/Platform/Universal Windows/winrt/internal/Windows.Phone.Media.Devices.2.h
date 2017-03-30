// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Phone.Media.Devices.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_61c26d35_9fae_59f1_83e0_9d57b45bc2ee
#define WINRT_GENERIC_61c26d35_9fae_59f1_83e0_9d57b45bc2ee
template <> struct __declspec(uuid("61c26d35-9fae-59f1-83e0-9d57b45bc2ee")) __declspec(novtable) TypedEventHandler<Windows::Phone::Media::Devices::AudioRoutingManager, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::Phone::Media::Devices::AudioRoutingManager, Windows::Foundation::IInspectable> {};
#endif


}

namespace Windows::Phone::Media::Devices {

struct IAudioRoutingManager :
    Windows::Foundation::IInspectable,
    impl::consume<IAudioRoutingManager>
{
    IAudioRoutingManager(std::nullptr_t = nullptr) noexcept {}
};

struct IAudioRoutingManagerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IAudioRoutingManagerStatics>
{
    IAudioRoutingManagerStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
