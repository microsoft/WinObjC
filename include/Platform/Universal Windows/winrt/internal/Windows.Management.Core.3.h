// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Management.Core.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Management::Core {

struct WINRT_EBO ApplicationDataManager :
    Windows::Management::Core::IApplicationDataManager
{
    ApplicationDataManager(std::nullptr_t) noexcept {}
    static Windows::Storage::ApplicationData CreateForPackageFamily(hstring_view packageFamilyName);
};

}

}
