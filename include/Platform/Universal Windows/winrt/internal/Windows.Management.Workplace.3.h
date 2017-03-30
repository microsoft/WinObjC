// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Management.Workplace.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Management::Workplace {

struct MdmPolicy
{
    MdmPolicy() = delete;
    static bool IsBrowserAllowed();
    static bool IsCameraAllowed();
    static bool IsMicrosoftAccountAllowed();
    static bool IsStoreAllowed();
    static Windows::Management::Workplace::MessagingSyncPolicy GetMessagingSyncPolicy();
};

struct WorkplaceSettings
{
    WorkplaceSettings() = delete;
    static bool IsMicrosoftAccountOptional();
};

}

}
