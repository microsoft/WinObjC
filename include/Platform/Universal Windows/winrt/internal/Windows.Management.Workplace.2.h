// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Management.Workplace.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Management::Workplace {

struct IMdmAllowPolicyStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IMdmAllowPolicyStatics>
{
    IMdmAllowPolicyStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IMdmPolicyStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IMdmPolicyStatics2>
{
    IMdmPolicyStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct IWorkplaceSettingsStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IWorkplaceSettingsStatics>
{
    IWorkplaceSettingsStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
