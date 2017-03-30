// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Security::Authentication::OnlineId {

struct IOnlineIdAuthenticator;
struct IOnlineIdServiceTicket;
struct IOnlineIdServiceTicketRequest;
struct IOnlineIdServiceTicketRequestFactory;
struct IUserIdentity;
struct OnlineIdAuthenticator;
struct OnlineIdServiceTicket;
struct OnlineIdServiceTicketRequest;
struct SignOutUserOperation;
struct UserAuthenticationOperation;
struct UserIdentity;

}

namespace Windows::Security::Authentication::OnlineId {

struct IOnlineIdAuthenticator;
struct IOnlineIdServiceTicket;
struct IOnlineIdServiceTicketRequest;
struct IOnlineIdServiceTicketRequestFactory;
struct IUserIdentity;
struct OnlineIdAuthenticator;
struct OnlineIdServiceTicket;
struct OnlineIdServiceTicketRequest;
struct SignOutUserOperation;
struct UserAuthenticationOperation;
struct UserIdentity;

}

namespace Windows::Security::Authentication::OnlineId {

template <typename T> struct impl_IOnlineIdAuthenticator;
template <typename T> struct impl_IOnlineIdServiceTicket;
template <typename T> struct impl_IOnlineIdServiceTicketRequest;
template <typename T> struct impl_IOnlineIdServiceTicketRequestFactory;
template <typename T> struct impl_IUserIdentity;

}

namespace Windows::Security::Authentication::OnlineId {

enum class CredentialPromptType
{
    PromptIfNeeded = 0,
    RetypeCredentials = 1,
    DoNotPrompt = 2,
};

}

}
