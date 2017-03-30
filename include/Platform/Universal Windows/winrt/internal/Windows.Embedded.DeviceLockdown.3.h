// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Embedded.DeviceLockdown.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Embedded::DeviceLockdown {

struct DeviceLockdownProfile
{
    DeviceLockdownProfile() = delete;
    static Windows::Foundation::Collections::IVectorView<GUID> GetSupportedLockdownProfiles();
    static GUID GetCurrentLockdownProfile();
    static Windows::Foundation::IAsyncAction ApplyLockdownProfileAsync(GUID profileID);
    static Windows::Embedded::DeviceLockdown::DeviceLockdownProfileInformation GetLockdownProfileInformation(GUID profileID);
};

struct WINRT_EBO DeviceLockdownProfileInformation :
    Windows::Embedded::DeviceLockdown::IDeviceLockdownProfileInformation
{
    DeviceLockdownProfileInformation(std::nullptr_t) noexcept {}
};

}

}
