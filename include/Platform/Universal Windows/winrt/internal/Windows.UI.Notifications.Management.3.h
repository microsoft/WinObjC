// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Notifications.Management.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Notifications::Management {

struct WINRT_EBO UserNotificationListener :
    Windows::UI::Notifications::Management::IUserNotificationListener
{
    UserNotificationListener(std::nullptr_t) noexcept {}
    static Windows::UI::Notifications::Management::UserNotificationListener Current();
};

}

}
