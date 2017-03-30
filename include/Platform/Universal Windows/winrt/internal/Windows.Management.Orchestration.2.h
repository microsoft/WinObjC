// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Management.Orchestration.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Management::Orchestration {

struct ICurrentAppOrchestration :
    Windows::Foundation::IInspectable,
    impl::consume<ICurrentAppOrchestration>
{
    ICurrentAppOrchestration(std::nullptr_t = nullptr) noexcept {}
};

struct ICurrentAppOrchestrationStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ICurrentAppOrchestrationStatics>
{
    ICurrentAppOrchestrationStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ISingleAppModeContext :
    Windows::Foundation::IInspectable,
    impl::consume<ISingleAppModeContext>,
    impl::require<ISingleAppModeContext, Windows::Foundation::IClosable>
{
    ISingleAppModeContext(std::nullptr_t = nullptr) noexcept {}
};

}

}
