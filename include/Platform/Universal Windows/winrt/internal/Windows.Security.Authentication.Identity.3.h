// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Security.Authentication.Identity.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Security::Authentication::Identity {

struct WINRT_EBO EnterpriseKeyCredentialRegistrationInfo :
    Windows::Security::Authentication::Identity::IEnterpriseKeyCredentialRegistrationInfo
{
    EnterpriseKeyCredentialRegistrationInfo(std::nullptr_t) noexcept {}
};

struct WINRT_EBO EnterpriseKeyCredentialRegistrationManager :
    Windows::Security::Authentication::Identity::IEnterpriseKeyCredentialRegistrationManager
{
    EnterpriseKeyCredentialRegistrationManager(std::nullptr_t) noexcept {}
    static Windows::Security::Authentication::Identity::EnterpriseKeyCredentialRegistrationManager Current();
};

}

}
