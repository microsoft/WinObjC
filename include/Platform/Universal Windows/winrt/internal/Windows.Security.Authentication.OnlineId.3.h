// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Security.Authentication.OnlineId.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Security::Authentication::OnlineId {

struct WINRT_EBO OnlineIdAuthenticator :
    Windows::Security::Authentication::OnlineId::IOnlineIdAuthenticator
{
    OnlineIdAuthenticator(std::nullptr_t) noexcept {}
    OnlineIdAuthenticator();
};

struct WINRT_EBO OnlineIdServiceTicket :
    Windows::Security::Authentication::OnlineId::IOnlineIdServiceTicket
{
    OnlineIdServiceTicket(std::nullptr_t) noexcept {}
};

struct WINRT_EBO OnlineIdServiceTicketRequest :
    Windows::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequest
{
    OnlineIdServiceTicketRequest(std::nullptr_t) noexcept {}
    OnlineIdServiceTicketRequest(hstring_view service, hstring_view policy);
    OnlineIdServiceTicketRequest(hstring_view service);
};

struct WINRT_EBO SignOutUserOperation :
    Windows::Foundation::IAsyncAction
{
    SignOutUserOperation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO UserAuthenticationOperation :
    Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::OnlineId::UserIdentity>
{
    UserAuthenticationOperation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO UserIdentity :
    Windows::Security::Authentication::OnlineId::IUserIdentity
{
    UserIdentity(std::nullptr_t) noexcept {}
};

}

}
