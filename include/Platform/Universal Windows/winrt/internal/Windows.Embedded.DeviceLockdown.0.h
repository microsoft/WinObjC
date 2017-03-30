// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Embedded::DeviceLockdown {

struct IDeviceLockdownProfileInformation;
struct IDeviceLockdownProfileStatics;
struct DeviceLockdownProfileInformation;

}

namespace Windows::Embedded::DeviceLockdown {

struct IDeviceLockdownProfileInformation;
struct IDeviceLockdownProfileStatics;
struct DeviceLockdownProfile;
struct DeviceLockdownProfileInformation;

}

namespace Windows::Embedded::DeviceLockdown {

template <typename T> struct impl_IDeviceLockdownProfileInformation;
template <typename T> struct impl_IDeviceLockdownProfileStatics;

}

}
