// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Foundation.Metadata.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Foundation::Metadata {

struct IApiInformationStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IApiInformationStatics>
{
    IApiInformationStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
