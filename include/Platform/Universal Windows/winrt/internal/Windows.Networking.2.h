// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Networking.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Networking {

struct IEndpointPair :
    Windows::Foundation::IInspectable,
    impl::consume<IEndpointPair>
{
    IEndpointPair(std::nullptr_t = nullptr) noexcept {}
};

struct IEndpointPairFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IEndpointPairFactory>
{
    IEndpointPairFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IHostName :
    Windows::Foundation::IInspectable,
    impl::consume<IHostName>
{
    IHostName(std::nullptr_t = nullptr) noexcept {}
};

struct IHostNameFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IHostNameFactory>
{
    IHostNameFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IHostNameStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IHostNameStatics>
{
    IHostNameStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
