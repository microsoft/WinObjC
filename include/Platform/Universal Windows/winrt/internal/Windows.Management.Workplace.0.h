// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Management::Workplace {

struct IMdmAllowPolicyStatics;
struct IMdmPolicyStatics2;
struct IWorkplaceSettingsStatics;

}

namespace Windows::Management::Workplace {

struct IMdmAllowPolicyStatics;
struct IMdmPolicyStatics2;
struct IWorkplaceSettingsStatics;
struct MdmPolicy;
struct WorkplaceSettings;

}

namespace Windows::Management::Workplace {

template <typename T> struct impl_IMdmAllowPolicyStatics;
template <typename T> struct impl_IMdmPolicyStatics2;
template <typename T> struct impl_IWorkplaceSettingsStatics;

}

namespace Windows::Management::Workplace {

enum class MessagingSyncPolicy
{
    Disallowed = 0,
    Allowed = 1,
    Required = 2,
};

}

}
